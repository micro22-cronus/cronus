/*
 * Copyright (c) 2021 Jianyu Jiang <jianyu@connect.hku.hk>
 */

#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/sched/coredump.h>
#include <linux/sched/numa_balancing.h>
#include <linux/highmem.h>
#include <linux/hugetlb.h>
#include <linux/mmu_notifier.h>
#include <linux/rmap.h>
#include <linux/swap.h>
#include <linux/shrinker.h>
#include <linux/mm_inline.h>
#include <linux/swapops.h>
#include <linux/dax.h>
#include <linux/khugepaged.h>
#include <linux/freezer.h>
#include <linux/pfn_t.h>
#include <linux/mman.h>
#include <linux/memremap.h>
#include <linux/pagemap.h>
#include <linux/debugfs.h>
#include <linux/migrate.h>
#include <linux/hashtable.h>
#include <linux/userfaultfd_k.h>
#include <linux/page_idle.h>
#include <linux/shmem_fs.h>
#include <linux/oom.h>
#include <linux/numa.h>
#include <linux/page_owner.h>

#include "tee-port.h"

uint32_t map_virt_phys(long *virt_addr, long phys_addr, unsigned long size, int prot);

extern const uint8_t *__vheap_start;
extern const uint8_t *__vmap_space;
extern const uint8_t *__vmap_space_end;
extern int vmap_pages_cnt;

extern uint8_t * vmap_cache;
static vm_fault_t vmf_insert(long virt_addr, unsigned long pfn, int prot) {
    long physical_addr = PFN_PHYS(pfn);
    uint32_t ret = map_virt_phys(&virt_addr, physical_addr, 4096, 0);
    if (ret) {
        printk("map page failed\n");
        return VM_FAULT_SIGSEGV;
    }
    return VM_FAULT_NOPAGE;
}

// huge_mm
vm_fault_t vmf_insert_pfn_pmd_prot(struct vm_fault *vmf, pfn_t pfn,
                pgprot_t pgprot, bool write) {
    unsigned long pn = pfn_t_to_pfn(pfn);
    return vmf_insert(vmf->address, pn, 0);
}

// mm
vm_fault_t vmf_insert_pfn_prot(struct vm_area_struct *vma, unsigned long addr,
			unsigned long pfn, pgprot_t pgprot) {
    return vmf_insert(addr, pfn, 0);
}

vm_fault_t vmf_insert_mixed_prot(struct vm_area_struct *vma, unsigned long addr,
			pfn_t pfn, pgprot_t pgprot) {
    unsigned long pn = pfn_t_to_pfn(pfn);
    return vmf_insert(addr, pn, 0);
}
