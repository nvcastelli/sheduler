ifneq ($(KERNELRELEASE),)
obj-m := scheduler.o

all:
	$(MAKE) -C /lib/modules/'uname -r'/build/ M='pwd' modules
else
	KERNELDIR ?= /lib/modules/`uname -r`/build/
	PWD := `pwd`
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
endif
