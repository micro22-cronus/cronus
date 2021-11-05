/*
 * Copyright (c) 2021 Jianyu Jiang <jianyu@connect.hku.hk>
 */

#include <linux/export.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/signal.h>
#include <linux/completion.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/cpu.h>
#include <linux/notifier.h>
#include <linux/kthread.h>
#include <linux/hardirq.h>
#include <linux/mempolicy.h>
#include <linux/freezer.h>
#include <linux/debug_locks.h>
#include <linux/lockdep.h>
#include <linux/idr.h>
#include <linux/jhash.h>
#include <linux/hashtable.h>
#include <linux/rculist.h>
#include <linux/nodemask.h>
#include <linux/moduleparam.h>
#include <linux/uaccess.h>
#include <linux/sched/isolation.h>
#include <linux/nmi.h>

#include "tee-port.h"

struct workqueue_struct {
    uint8_t handle;
    struct list_head k_list;
};

struct workqueue_struct *system_freezable_wq __read_mostly;
EXPORT_SYMBOL_GPL(system_freezable_wq);
struct workqueue_struct *system_wq __read_mostly;
EXPORT_SYMBOL(system_wq);

static void debug_task() {}

#define EXEC_TASK(work) \
    printk("execute task %lx from %s\n", work, __FUNCTION__); \
    debug_task(); \
    (work)->func(work); \
    printk("execute task %lx fin\n", work);

__printf(1, 4)
struct workqueue_struct *alloc_workqueue(const char *fmt,
					 unsigned int flags,
					 int max_active, ...)
{
    struct workqueue_struct* ws = kzalloc(sizeof(struct workqueue_struct), GFP_KERNEL);
    INIT_LIST_HEAD(&ws->k_list);
    return ws;
}
EXPORT_SYMBOL_GPL(alloc_workqueue);

bool cancel_delayed_work_sync(struct delayed_work *dwork)
{
	// return __cancel_work_timer(&dwork->work, true);
    unimplemented();
}
EXPORT_SYMBOL(cancel_delayed_work);

bool cancel_work_sync(struct work_struct *work)
{
	// return __cancel_work_timer(work, false);
    unimplemented();
}
EXPORT_SYMBOL_GPL(cancel_work_sync);

void delayed_work_timer_fn(struct timer_list *t)
{
	struct delayed_work *dwork = from_timer(dwork, t, timer);

	/* should have been called from irqsafe timer with irq already off */
	unimplemented();
}
EXPORT_SYMBOL(delayed_work_timer_fn);

void destroy_workqueue(struct workqueue_struct *wq) {
    free(wq);
}
EXPORT_SYMBOL_GPL(destroy_workqueue);

bool flush_work(struct work_struct *work)
{
    printk("no work for flushing as we execute them immediately\n");
    return false;
}
EXPORT_SYMBOL_GPL(flush_work);

bool queue_delayed_work_on(int cpu, struct workqueue_struct *wq,
			   struct delayed_work *dwork, unsigned long delay) {
    // EXEC_TASK(&dwork->work);
    unimplemented();
    return false;
}
EXPORT_SYMBOL(queue_delayed_work_on);

bool queue_work_on(int cpu, struct workqueue_struct *wq,
		   struct work_struct *work) {
    printk("execute task immediately\n");
    EXEC_TASK(work);
    return false;
}
EXPORT_SYMBOL(queue_work_on);

void flush_workqueue(struct workqueue_struct *wq) {
    unimplemented();
}
EXPORT_SYMBOL(flush_workqueue);

extern u32 init_workqueue() {
    init_cpu_present(cpumask_of(0));
    init_cpu_possible(cpumask_of(0));
    system_wq = alloc_workqueue("events", 0, 0);
    system_freezable_wq = alloc_workqueue("events_freezable",
                        WQ_FREEZABLE, 0);
    return 0;
}