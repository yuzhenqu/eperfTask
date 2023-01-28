obj-m += lkm.o

PWD := $(CURDIR)

all:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
    sudo dmesg -C
    sudo insmod lkm.ko
    sudo rmmod lkm.ko
    sudo dmesg