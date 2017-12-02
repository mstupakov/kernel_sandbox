/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2017 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

SECTIONS
{
  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*) SORT(.ctors.*)))
    KEEP (*(.init_array .ctors))
    PROVIDE_HIDDEN (__init_array_end = .);
  }

  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*) SORT(.dtors.*)))
    KEEP (*(.fini_array .dtors))
    PROVIDE_HIDDEN (__fini_array_end = .);
  }
}
