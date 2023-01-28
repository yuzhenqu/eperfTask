#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yuzhen Qu");
MODULE_DESCRIPTION("A kernel module that prints \"Hello World\" when inserted and \"Goodbye!\" when remove it.");

static int init lkm_init(void) {
    printk(KERN_INFO "Hello World\n");
    return 0;
}

static void exit lkm_exit(void) {
    printk(KERN_INFO "Goodbye!\n");
}

module_init(lkm_init);
module_exit(lkm_exit);