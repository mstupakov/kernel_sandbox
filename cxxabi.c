/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2017 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <linux/kernel.h>

void __cxa_pure_virtual(void) {
}

void __cxa_guard_abort(void *p) {
}

int __cxa_guard_acquire(void *p) {
  return 0;
}

void __cxa_guard_release(void *p) {
}
