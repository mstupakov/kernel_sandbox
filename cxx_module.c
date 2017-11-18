/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2017 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include "common.h"
#include "cxx_module.h"

void cxx_module_init(void) {
  printk("! Enter: %s\n", __PRETTY_FUNCTION__);
}

void cxx_module_exit(void) {
  printk("! Enter: %s\n", __PRETTY_FUNCTION__);
}
