#include <stdint.h>
#include <kernel/console.H>

int main()
{
    printk("Booting Chenoo kernel...\n");
    printk("Testing a character %c %c %c\n", 'a', 'b', 'c');
    printk("Testing numbers %hhd %hu %x %lx %lld\n",
		(char)-1, (short)1234, 0xabcdef12, 0xdeadbeef, 
		0x0123456789abcdef);
    while(1);

    return 0;
}
