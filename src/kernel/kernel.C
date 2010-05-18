#include <stdint.h>
#include <kernel/console.H>

int main()
{
    printk("Welcome to the kernel!\n");
    while(1);

    return 0;
}
