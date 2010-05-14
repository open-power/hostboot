
void _main(void)
{
    unsigned int i = 100;
    while(i != 0)
    {
	asm volatile("eieio");
	i--;
    }

    while(1)
    {
    }
}
