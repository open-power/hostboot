//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/lib/stdio.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#include <stdint.h>
#include <stdio.h>
#include <util/sprintf.H>
#include <util/functor.H>

class SprintfBuffer
{
    public:
	int putc(int c)
	{
	    if ('\b' == c)
	    {
		iv_pos--;
	    }
	    else
	    {
		iv_buffer[iv_pos++] = c;
	    }
	    return c;
	}

	explicit SprintfBuffer(char* buf) : iv_pos(0), iv_buffer(buf) {};

    private:
	size_t iv_pos;    
	char * iv_buffer;
};

int sprintf(char *str, const char * format, ...)
{
    using Util::mem_ptr_fun;
    using Util::vasprintf;

    va_list args;
    va_start(args, format);

    SprintfBuffer console(str);
    size_t count = vasprintf(mem_ptr_fun(console, &SprintfBuffer::putc),
			     format, args);

    va_end(args);
    console.putc('\0');
    return count;
}
