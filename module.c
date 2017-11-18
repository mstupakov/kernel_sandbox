/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2017 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#include "cxx_module.h"

int __init kmodule_init(void)
{
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  cxx_module_init();

  return 0;
}

void __exit kmodule_exit(void)
{
  printk(KERN_INFO "! Enter: %s\n", __FUNCTION__);
  cxx_module_exit();
}

module_init(kmodule_init);
module_exit(kmodule_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maksym Stupakov");
