MODULE := kmodule

K_VERSION := $(shell uname -r)
K_SRC_PATH := /lib/modules/$(K_VERSION)/build

CXX_FLAGS := -x c++ -fno-builtin -fno-exceptions -fno-rtti

CFLAGS_cxx_new.o := $(CXX_FLAGS)
CFLAGS_cxx_module.o := $(CXX_FLAGS) 

ldflags-y += -T $(src)/module.lds

obj-m += $(MODULE).o
$(MODULE)-objs := module.o crt0.o memory.o cxxabi.o cxx_new.o cxx_module.o

module:
	make -C $(K_SRC_PATH) M=$(PWD) modules

clean:
	make -C $(K_SRC_PATH) M=$(PWD) clean

