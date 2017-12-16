/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2017 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include "common.h"
#include "cxx_module.h"

template<typename T>
class Base {
  public:
    Base() {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }

    Base(const Base&) {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }

#if __cplusplus >= 201103L
    Base(const Base&&) {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }
#endif

   ~Base() {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }

    void base_method() {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }
};

template<typename T>
class Derived : public Base<T> {
  public:
    Derived() {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }

    Derived(const Derived&) {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }

#if __cplusplus >= 201103L
    Derived(const Derived&&) {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }
#endif

   ~Derived() {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }

    void derived_method() {
      printk("! Enter: %s\n", __PRETTY_FUNCTION__);
    }
};

Derived<char> g_object_1;
Derived<char> g_object_2;
Derived<char> g_object_3;

void cxx_module_init(void) {
  printk("! Enter: %s\n", __PRETTY_FUNCTION__);

  Derived<int> object_1;
  Derived<int> object_2 = object_1;

#if __cplusplus >= 201103L
  Derived<int> object_3 = static_cast<Derived<int>&&>(object_2);
#endif

  object_1.base_method();
  object_1.derived_method();

  static Derived<short> s_object_1;
  static Derived<short> s_object_2;
}

void cxx_module_exit(void) {
  printk("! Enter: %s\n", __PRETTY_FUNCTION__);
}
