
void _main(void)
{
    static unsigned char kernel_stack[16 * 1024] = {0};
    register void * stack = &kernel_stack;
    asm volatile("mr 1,%0" :: "r" (stack) );
   
    while(1)
    {
	//asm volatile("wait");
    }
}
