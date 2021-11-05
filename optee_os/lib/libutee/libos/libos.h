/*
 * Copyright (c) 2021 Jianyu Jiang <jianyu@connect.hku.hk>
 */

#pragma once

#include <utee_syscalls.h>

extern char libos_log_buf[];
extern int libos_log_cnt;
#define libos_debug(...) \
    libos_log_cnt = sprintf(libos_log_buf, "D/LIBOS:%s:%d ", __FUNCTION__, __LINE__); \
    sprintf(libos_log_buf + libos_log_cnt, __VA_ARGS__); \
    _utee_log(libos_log_buf, strlen(libos_log_buf));

#define libos_debug_ret(ret) libos_debug("-> %lx\n", ret);