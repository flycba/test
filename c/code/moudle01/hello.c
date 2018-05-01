
#include <linux/init.h>
#include <linux/module.h>

static char hello = 'A';
static char world = 'B';

module_param(hello, byte, S_IRUGO);
module_param(world, byte, S_IRUGO);

static int hello_init(void)
{
    printk(KERN_ALERT "Hello World linux_driver_module %c\n",hello);

    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbey linux_driver_module %02c\n",world);
}

int helloworld(void)
{
    world = hello + world;
    return 0;
}
EXPORT_SYMBOL(helloworld);

module_init(hello_init);

module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("flycba");


//~ Formatted by Jindent --- http://www.jindent.com
