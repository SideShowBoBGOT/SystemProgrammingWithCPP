#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_AUTHOR("Serhii Panchenko");
MODULE_DESCRIPTION("Lab4");
MODULE_LICENSE("GPL3");

static int __init hw_init(void) {
    printk(KERN_ERR "Input , Kernel!\n");
    return 0;
}

static void __exit hw_exit(void) {
    printk(KERN_ERR "It out from, Kernel!\n");
}

module_init(hw_init);
module_exit(hw_exit);