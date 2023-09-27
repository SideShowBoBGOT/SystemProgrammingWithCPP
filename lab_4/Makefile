obj-m := Hello.o
KDIR = /lib/modules/`uname -r`/build

all:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order *.cmd
