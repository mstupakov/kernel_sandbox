/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2017 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

extern void (*__init_array_start[]) (unsigned, char**, char**);
extern void (*__init_array_end[]) (unsigned, char**, char**);
extern void (*__fini_array_start[]) (void);
extern void (*__fini_array_end[]) (void);

void __do_global_init(void) {
  unsigned i = 0;

  for (i = 0; i < __init_array_end - __init_array_start; ++i) {
    __init_array_start[i](0, 0, 0);
  }
}

void __do_global_fini(void) {
  unsigned i = __fini_array_end - __fini_array_start;

  while (i--) {
    __fini_array_start[i]();
  }
}
