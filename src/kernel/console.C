/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/console.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <util/singleton.H>
#include <kernel/console.H>
#include <util/sprintf.H>
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
    using Util::vasprintf;

    va_list args;
    va_start(args, str);

    Console& console = Singleton<Console>::instance();
    vasprintf(console, str, args);

    va_end(args);
}
