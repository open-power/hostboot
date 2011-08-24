//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/console.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
#include <util/singleton.H>
#include <kernel/console.H>
#include <util/sprintf.H>
#include <util/functor.H>
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

void printk(const char* str, ...)
{
    using Util::mem_ptr_fun;
    using Util::vasprintf;

    va_list args;
    va_start(args, str);

    Console& console = Singleton<Console>::instance();
    vasprintf(mem_ptr_fun(console, &Console::putc),
	      str, args);

    va_end(args);
}
