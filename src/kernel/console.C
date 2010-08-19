#include <util/singleton.H>
#include <kernel/console.H>
#include <stdarg.h>

char kernel_printk_buffer[Console::BUFFER_SIZE];

Console::Console() : iv_pos(0), iv_buffer(kernel_printk_buffer)
{
    memset(iv_buffer, '\0', Console::BUFFER_SIZE);
}

int Console::putc(int c)
{
    if ('\b' == c)
    {
	__sync_sub_and_fetch(&iv_pos, 1);
    }
    else if (BUFFER_SIZE > iv_pos)
    {
	iv_buffer[__sync_fetch_and_add(&iv_pos, 1)] = c;
    }
    return c;
}

class ConsoleTraits
{
    public:
	enum trait { NONE, HEX, DEC,  };
};

template <typename _T, ConsoleTraits::trait _S = ConsoleTraits::NONE>
class ConsoleDisplay
{
    public:
	static void display(Console& c, _T value) {};
};

template <ConsoleTraits::trait _S>
class ConsoleDisplay<char*, _S>
{
    public:
	static void display(Console&c, char* value)
	{
	    while(*value != '\0')
	    {
		c.putc(*value);
		value++;
	    }
	}
};

template <>
class ConsoleDisplay<char, ConsoleTraits::NONE>
{
    public:
	static void display(Console&c, char value)
	{
	    c.putc(value);
	}
};

template <typename _T>
class ConsoleDisplay<_T, ConsoleTraits::DEC>
{
    public:
	static void display(Console&c, _T value)
	{
	    if (value == 0)
	    {
		c.putc('0');
	    }
	    else if (value < 0)
	    {
		c.putc('-');
		value *= -1;
	    }
	    else
		subdisplay(c, value);
	}

	static void subdisplay(Console&c, _T value)
	{
	    if (value != 0)
	    {
		subdisplay(c, value / 10);
		c.putc('0' + (value % 10));
	    }
	}
};

template<typename _T>
class ConsoleDisplay<_T, ConsoleTraits::HEX>
{
    public:
	static void display(Console&c, _T value)
	{
	    size_t length = sizeof(_T) * 2;
	    subdisplay(c, value, length);
	}

	static void subdisplay(Console&c, _T value, size_t length)
	{
	    if (length == 0) return;
	    subdisplay(c, value / 16, length-1);
	    char nibble = value % 16;
	    if (nibble >= 0x0a)
		c.putc('A' + (nibble - 0x0a));
	    else
		c.putc('0' + nibble);
	}
};

void printk(const char* str, ...)
{
    va_list args;
    va_start(args, str);

    Console& console = Singleton<Console>::instance();
    
    bool format = false;
    int size = 0;

    while('\0' != *str)
    {
	if (('%' == *str) || (format))
	switch (*str)
	{
	    case '%':
		{
		    if (format)
		    {
			ConsoleDisplay<char>::display(console, '%');
			format = false;
		    }
		    else
		    {
			format = true;
			size = 2;
		    }
		    break;
		}
	    case 'c':
		{
		    format = false;
		    ConsoleDisplay<char>
			::display(console,
				  (char)va_arg(args,int));
		    break;
		}
	    case 'h':
		{
		    size--;
		    break;
		}
	    case 'l':
		{
		    size++;
		    break;
		}
	    case 'z': // size_t or ssize_t
		{
		    size = 4;
		    break;
		}
	    case 'd': // decimal
		{
		    format = false;
		    switch(size)
		    {
			case 0:
			    ConsoleDisplay<char, ConsoleTraits::DEC>
				::display(console,
					  (char)va_arg(args,int));
			    break;

			case 1:
			    ConsoleDisplay<short, ConsoleTraits::DEC>
				::display(console,
					  (short)va_arg(args,int));
			    break;

			case 2:
			case 3:
			    ConsoleDisplay<int, ConsoleTraits::DEC>
				::display(console,
					  va_arg(args,int));
			    break;

			case 4:
			    ConsoleDisplay<long, ConsoleTraits::DEC>
				::display(console,
					  va_arg(args,long));
			    break;
		    }
		    break;
		}
	    case 'u': // unsigned decimal
		{
		    format = false;
		    switch(size)
		    {
			case 0:
			    ConsoleDisplay<unsigned char, ConsoleTraits::DEC>
				::display(console,
					  (unsigned char)
					    va_arg(args,unsigned int));
			    break;

			case 1:
			    ConsoleDisplay<unsigned short, ConsoleTraits::DEC>
				::display(console,
					  (unsigned short)
					    va_arg(args,unsigned int));
			    break;

			case 2:
			case 3:
			    ConsoleDisplay<unsigned int, ConsoleTraits::DEC>
				::display(console,
					  va_arg(args,unsigned int));
			    break;

			case 4:
			    ConsoleDisplay<unsigned long, ConsoleTraits::DEC>
				::display(console,
					  va_arg(args,unsigned long));
			    break;
		    }
		    break;
		}
	    case 'x': // unsigned hex
	    case 'X':
		{
		    format = false;
		    switch(size)
		    {
			case 0:
			    ConsoleDisplay<unsigned char, ConsoleTraits::HEX>
				::display(console,
					  (unsigned char)
					    va_arg(args,unsigned int));
			    break;

			case 1:
			    ConsoleDisplay<unsigned short, ConsoleTraits::HEX>
				::display(console,
					  (unsigned short)
					    va_arg(args,unsigned int));
			    break;

			case 2:
			case 3:
			    ConsoleDisplay<unsigned int, ConsoleTraits::HEX>
				::display(console,
					  va_arg(args,unsigned int));
			    break;

			case 4:
			    ConsoleDisplay<unsigned long, ConsoleTraits::HEX>
				::display(console,
					  va_arg(args,unsigned long));
			    break;
		    }
		    break;
		}
	    case 's': // string
		{
		    format = false;
		    ConsoleDisplay<char*>::display(console,
						   (char*)va_arg(args,void*));
		    break;
		}
	}
	else
	    ConsoleDisplay<char>::display(console, *str);

	str++;
    }

    va_end(args);
}
