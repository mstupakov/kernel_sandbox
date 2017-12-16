/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2017 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <linux/kernel.h>
#include <linux/slab.h>

void *__dso_handle = 0;

static struct atexit_t {
  void *arg;
  void *dso;
  void (*cb)(void*);

  struct atexit_t *next;
} *head;

void __cxa_pure_virtual(void) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
}

void __cxa_guard_abort(void *p) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
}

int __cxa_guard_acquire(void *p) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  return 1;
}

void __cxa_guard_release(void *p) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
}

int __cxa_atexit(void (*cb)(void*), void *arg, void *dso_handle) {
  struct atexit_t *p = kmalloc(sizeof(struct atexit_t), GFP_KERNEL);
  if (!p) {
    return -1;
  }

  p->cb = cb;
  p->arg = arg;
  p->dso = dso_handle;

  p->next = head;
  head = p;

  return 0;
}

void __cxa_finalize(void *dso_handle) {
  struct atexit_t *p = head;

  while (p) {
    struct atexit_t *f = p;

    p->cb(p->arg);
    p = p->next;

    kfree(f);
  }

  head = 0;
}

void __cxa_finalize_dso(void) {
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  __cxa_finalize(__dso_handle);
}

void (*p)(void) __attribute__ ((section(".fini_array"))) = __cxa_finalize_dso;
