LKM             = sgx-step
PWD            := $(shell pwd)

obj-m          += $(LKM).o
$(LKM)-objs     = sgxstep.o

KERN_SOURCE ?= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KERN_SOURCE) M=$(PWD) modules

clean:
	make -C $(KERN_SOURCE) M=$(PWD) clean

unload:
	sudo rmmod $(LKM).ko || true

load: unload all
	sudo modprobe -a isgx msr || true
	sudo insmod $(LKM).ko
	sudo dmesg | tail
