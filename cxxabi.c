/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2017 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <linux/kernel.h>

void *__dso_handle = 0;

void __cxa_pure_virtual(void) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
}

void __cxa_guard_abort(void *p) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
}

int __cxa_guard_acquire(void *p) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  return 0;
}

void __cxa_guard_release(void *p) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
}

int __cxa_atexit(void (*f) (void*), void *arg, void *dso_handle) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  return 0;
}
