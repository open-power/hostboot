#include <util/singleton.H>
#include <kernel/console.H>

static char kernel_printk_buffer[Console::BUFFER_SIZE];

Console::Console() : iv_pos(0), iv_buffer(kernel_printk_buffer)
{
    memset(iv_buffer, '\0', Console::BUFFER_SIZE);
}

int Console::putc(int c)
{
    if (BUFFER_SIZE > iv_pos)
    {
	iv_buffer[iv_pos] = c;
	iv_pos++;
    }
}

void printk(const char* str)
{
    Console& console = Singleton<Console>::instance();
    while('\0' != *str)
    {
	console.putc(*str);
	str++;
    }
}
