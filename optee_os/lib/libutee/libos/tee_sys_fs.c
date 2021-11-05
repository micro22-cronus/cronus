/*
 * Copyright (c) 2021 Jianyu Jiang <jianyu@connect.hku.hk>
 */

#include <tee_internal_api_extensions.h>
#include <utee_syscalls.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/uio.h>
#include <pthread.h>
#include <pthread_arch.h>

#include "libos.h"

#define BIT32(nr)		(UINT32_C(1) << (nr))
#define BIT64(nr)		(UINT64_C(1) << (nr))

#define TEE_MAP_FLAG_SHAREABLE	BIT32(0)
#define TEE_MAP_FLAG_WRITEABLE	BIT32(1)
#define TEE_MAP_FLAG_EXECUTABLE	BIT32(2)

#define SMALL_PAGE_SIZE		0x00001000

int file_fd_idx = 3;

struct fd_struct {
    int cur;
    int handle;
} fd_struct_mapping [10];

int tee_fs_openat(int fd, const char* filename, int flag, int mode) {
  int handle;
  TEE_UUID uuid;
  TEE_Result ret = _utee_fs_open(filename, flag, mode, &handle);
  int ret_fd = -1;
  uintptr_t va;
  int flags = TEE_MAP_FLAG_SHAREABLE;
  if (ret) {
    errno = EACCES;
    goto no_error;
  }

  ret_fd = file_fd_idx++;
  fd_struct_mapping[ret_fd].cur = 0;
  fd_struct_mapping[ret_fd].handle = handle;

no_error:
  libos_debug("open file (%s, %lx, %lx) -> %lx\n", filename, flag, mode, ret_fd);
  return ret_fd;
}

int tee_fs_read(int fd, void *buf, size_t count) {
  struct fd_struct *fds = &fd_struct_mapping[fd];
  TEE_Result ret;
  ssize_t rsize;

  if (fd == STDIN_FILENO)
    return -1;

  ret = _utee_fs_read(fds->handle, buf, count, fds->cur, &rsize);
  if (ret) {
    // handle
    return -1;
  }  
  fds->cur += rsize;
  return rsize;
}

int tee_fs_readv(int fd, const struct iovec *iov, int iovcnt) {
  int total_size = 0;
  int rsize = 0;
  int has_error = 0;
  for (int i = 0;i < iovcnt;i++) {
    if (iov[i].iov_len > 0) {
      rsize = tee_fs_read(fd, iov[i].iov_base, iov[i].iov_len);
      if (rsize > 0)
        total_size += rsize;
      else
        has_error = 1;
    }
  }
  if (has_error) total_size = -1;
  
  libos_debug_ret(total_size);
  return total_size;
}

int tee_fs_write(int fd, const void *buf, size_t count) {
    struct fd_struct *fds = &fd_struct_mapping[fd];
    TEE_Result ret;
    ssize_t wsize;

    if (fd == STDOUT_FILENO || fd == STDERR_FILENO) {
      _utee_log(buf, count);
      wsize = count;
    } else {
      ret = _utee_fs_write(fds->handle, buf, count, fds->cur, &wsize);
      if (ret) {
        // handle
        return -1;
      }
      fds->cur += wsize;
    }

    return wsize;
}

int tee_fs_writev(int fd, const struct iovec *iov, int iovcnt) {
    int total_size = 0;
    char buf[100];
    int wsize = 0;
    int has_error = 0;

    for (int i = 0;i < iovcnt; i++) {
        total_size += iov[i].iov_len;
        if (iov[i].iov_len) {
            wsize = tee_fs_write(fd, iov[i].iov_base, iov[i].iov_len);
            if (wsize > 0)
              total_size += wsize;
            else
              has_error = 1;
        }
    }

    if (has_error) total_size = -1;

    return total_size;
}

void tee_fs_close(int fd) {
  struct fd_struct *fds = &fd_struct_mapping[fd];
  TEE_Result ret;
  ret = _utee_fs_close(fds->handle);
  if (ret) {
    // errno = ?;
  }
  libos_debug("close fd %d\n", fd);
}

int tee_dev_ioctl(int fd, unsigned long cmd, void *args) {
    struct fd_struct *fds = &fd_struct_mapping[fd];
    TEE_Result ret = TEE_ERROR_BAD_PARAMETERS;
    int ret_val;

    switch (fd) {
      case STDIN_FILENO:  break;
      case STDOUT_FILENO: break;
        break;
      default: ret = _utee_dev_ioctl(fds->handle, cmd, args, &ret_val); break;
    }

    if (ret) {
        ret_val = -1;
    }
    libos_debug_ret(ret);
    return ret_val;
}