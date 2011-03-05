#ifndef __UTIL_SPRINTF_H
#define __UTIL_SPRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <builtins.h>

class Console;

namespace Util
{

    class ConsoleTraits
    {
	public:
	    enum trait { NONE, HEX, DEC,  };
    };

    template <typename _T, ConsoleTraits::trait _S = ConsoleTraits::NONE>
	class ConsoleDisplay
	{
	    public:
		template <typename _F>
		ALWAYS_INLINE		
		static size_t display(_F& c, _T value) { return 0; };
	};

    template <ConsoleTraits::trait _S>
	class ConsoleDisplay<char*, _S>
	{
	    public:
		template <typename _F>
		ALWAYS_INLINE				
		static size_t display(_F& c, char* value)
		{
		    size_t count = 0;
		    while(*value != '\0')
		    {
			c(*value);
			value++;
			count++;
		    }
		    return count;
		}
	};

    template <>
	class ConsoleDisplay<char, ConsoleTraits::NONE>
	{
	    public:
		template <typename _F>
		ALWAYS_INLINE				
		static size_t display(_F& c, char value)
		{
		    c(value);
		    return 1;
		}
	};

    template <typename _T>
	class ConsoleDisplay<_T, ConsoleTraits::DEC>
	{
	    public:
		template <typename _F>
		ALWAYS_INLINE				
		static size_t display(_F& c, _T value)
		{
		    size_t count = 0;
		    if (value == 0)
		    {
			c('0'); count++;
		    }
		    else if (value < 0)
		    {
			c('-'); count++;
			value *= -1;
			count += subdisplay(c, value);
		    }
		    else
			count += subdisplay(c, value);
		    return count;
		}
		
		template <typename _F>
		static size_t subdisplay(_F& c, _T value)
		{
		    size_t count = 0;
		    if (value != 0)
		    {
			count += subdisplay(c, value / 10);
			c('0' + (value % 10));
			count++;
		    }
		    return count;
		}
	};

    template<typename _T>
	class ConsoleDisplay<_T, ConsoleTraits::HEX>
	{
	    public:
		template <typename _F>
		ALWAYS_INLINE				
		static size_t display(_F& c, _T value)
		{
		    size_t length = sizeof(_T) * 2;
		    subdisplay(c, value, length);
		    return length;
		}
		
		template <typename _F>
		static void subdisplay(_F& c, _T value, size_t length)
		{
		    if (length == 0) return;
		    subdisplay(c, value / 16, length-1);
		    char nibble = value % 16;
		    if (nibble >= 0x0a)
			c('A' + (nibble - 0x0a));
		    else
			c('0' + nibble);
		}
	};

    template<typename _F>
    size_t vasprintf(_F output_func, const char* fmt_str, va_list& args)
    {
	size_t count = 0;

	bool format = false;
	int size = 0;

	while('\0' != *fmt_str)
	{
	    if (('%' == *fmt_str) || (format))
		switch (*fmt_str)
		{
		    case '%':
			{
			    if (format)
			    {
				count += 
				    ConsoleDisplay<char>::display(output_func, 
								  '%');
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
			    count += ConsoleDisplay<char>
				::display(output_func, (char)va_arg(args,int));
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
				    count += ConsoleDisplay<char, 
							    ConsoleTraits::DEC>
					::display(output_func,
						  (char)va_arg(args,int));
				    break;

				case 1:
				    count += ConsoleDisplay<short, 
							    ConsoleTraits::DEC>
					::display(output_func,
						  (short)va_arg(args,int));
				    break;

				case 2:
				    count += ConsoleDisplay<int, 
							    ConsoleTraits::DEC>
					::display(output_func,
						  va_arg(args,int));
				    break;

				case 3:
				case 4:
				    count += ConsoleDisplay<long, 
							    ConsoleTraits::DEC>
					::display(output_func,
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
				    count += ConsoleDisplay<unsigned char, 
							    ConsoleTraits::DEC>
					::display(output_func,
						  (unsigned char)
						  va_arg(args,unsigned int));
				    break;

				case 1:
				    count += ConsoleDisplay<unsigned short, 
							    ConsoleTraits::DEC>
					::display(output_func,
						  (unsigned short)
						  va_arg(args,unsigned int));
				    break;

				case 2:
				    count += ConsoleDisplay<unsigned int, 
							    ConsoleTraits::DEC>
					::display(output_func,
						  va_arg(args,unsigned int));
				    break;

				case 3:
				case 4:
				    count += ConsoleDisplay<unsigned long, 
							    ConsoleTraits::DEC>
					::display(output_func,
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
				    count += ConsoleDisplay<unsigned char, 
							    ConsoleTraits::HEX>
					::display(output_func,
						  (unsigned char)
						  va_arg(args,unsigned int));
				    break;

				case 1:
				    count += ConsoleDisplay<unsigned short, 
							    ConsoleTraits::HEX>
					::display(output_func,
						  (unsigned short)
						  va_arg(args,unsigned int));
				    break;

				case 2:
				    count += ConsoleDisplay<unsigned int, 
							    ConsoleTraits::HEX>
					::display(output_func,
						  va_arg(args,unsigned int));
				    break;

				case 3:
				case 4:
				    count += ConsoleDisplay<unsigned long, 
							    ConsoleTraits::HEX>
					::display(output_func,
						  va_arg(args,unsigned long));
				    break;
			    }
			    break;
			}
		    case 's': // string
			{
			    format = false;
			    count += ConsoleDisplay<char*>
					::display(output_func,
				                  (char*) va_arg(args,void*));
			    break;
			}
                    case 'p': // pointer
                        {
                            format = false;
			    count += ConsoleDisplay<char>
					::display(output_func,
				                  '0');
			    count += ConsoleDisplay<char>
					::display(output_func,
				                  'x');
                            count += ConsoleDisplay<unsigned long, 
                                                    ConsoleTraits::HEX>
                                  ::display(output_func,
                                            va_arg(args,unsigned long));
                            break;
                        }
		}
	    else
		count += ConsoleDisplay<char>::display(output_func, *fmt_str);

	    fmt_str++;
	}

	return count;
    }

};

#endif
