obj-m:=kmod.o

KDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -c $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod
	
