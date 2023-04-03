/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/tools/dce/dce-extra-files/trace_defs.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef TRACE_DEFS_H
#define TRACE_DEFS_H

/* @file trace_defs.H
 *
 *  The purpose of this file is to override the TRACFCOMP macro and redirect it to the console output for DCE. That way
 *  users of DCE can get traces for their DCE scripts. Typically, only TRACFCOMP should need to be redirected but there
 *  may be cases where trace macros need to be overridden, such as TRACDCOMP. They can be added here as well as needed.
 */

#include <console/consoleif.H>
#include <string.h>
#include <stdio.h>

#define CONSOLE_TRACE(args...) CONSOLE::displayf(CONSOLE::DEFAULT, NULL, args)

#undef TRACFCOMP
#define TRACFCOMP(X, args...) do { (void)X; CONSOLE_TRACE(args); } while (false)

[[maybe_unused]]
static uint8_t dce_bytetochar(const uint8_t c)
{
    if (c >= ' ' && c <= '~')
    {
        return c;
    }
    return '.';
}

[[maybe_unused]]
static void dce_hexdump(const void* data, size_t size)
{
    const uint8_t* cdata = static_cast<const uint8_t*>(data);
    const uint8_t* const cend = cdata + size;
    size_t i = 0;

    while (cdata + 16 <= cend)
    {
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "  %08x: %02x %02x %02x %02x %02x %02x %02x %02x   %02x %02x %02x %02x %02x %02x %02x %02x    "
                          "%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c",
                          i,
                          cdata[0], cdata[1], cdata[2], cdata[3], cdata[4], cdata[5], cdata[6], cdata[7],
                          cdata[8], cdata[9], cdata[10], cdata[11], cdata[12], cdata[13], cdata[14], cdata[15],
                          dce_bytetochar(cdata[0]), dce_bytetochar(cdata[1]), dce_bytetochar(cdata[2]), dce_bytetochar(cdata[3]),
                          dce_bytetochar(cdata[4]), dce_bytetochar(cdata[5]), dce_bytetochar(cdata[6]), dce_bytetochar(cdata[7]),
                          dce_bytetochar(cdata[8]), dce_bytetochar(cdata[9]), dce_bytetochar(cdata[10]), dce_bytetochar(cdata[11]),
                          dce_bytetochar(cdata[12]), dce_bytetochar(cdata[13]), dce_bytetochar(cdata[14]), dce_bytetochar(cdata[15]));
        i += 16;
        cdata += 16;
    }

    if (size != i)
    {
        char lastchunk[16] = { };
        memcpy(lastchunk, cdata, size - i);

        const char* const numfmt = "  %08x: %02x %02x %02x %02x %02x %02x %02x %02x"
                                  "   %02x %02x %02x %02x %02x %02x %02x %02x";
        const char* const spaces = "    ";
        const char* const charfmt = "%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c";

        char ending_fmt[128] = { };
        memcpy(ending_fmt, numfmt, 7 + 5*(size - i) + (size - i >= 8 ? 2 : 0));

        char buf[128] = { };

        sprintf(buf, ending_fmt,
                i,
                lastchunk[0], lastchunk[1], lastchunk[2], lastchunk[3], lastchunk[4], lastchunk[5], lastchunk[6], lastchunk[7],
                lastchunk[8], lastchunk[9], lastchunk[10], lastchunk[11], lastchunk[12], lastchunk[13], lastchunk[14], lastchunk[15]);
        strcat(buf, spaces);

        for (int i = strlen(buf); i < 65; ++i)
        {
            buf[i] = ' ';
        }

        memset(ending_fmt, 0, sizeof(buf));
        memcpy(ending_fmt, charfmt, 2*(size - i) + (size - i >= 8 ? 1 : 0));
        sprintf(buf + strlen(buf), ending_fmt,
                dce_bytetochar(lastchunk[0]), dce_bytetochar(lastchunk[1]), dce_bytetochar(lastchunk[2]),
                dce_bytetochar(lastchunk[3]), dce_bytetochar(lastchunk[4]), dce_bytetochar(lastchunk[5]),
                dce_bytetochar(lastchunk[6]), dce_bytetochar(lastchunk[7]), dce_bytetochar(lastchunk[8]),
                dce_bytetochar(lastchunk[9]), dce_bytetochar(lastchunk[10]), dce_bytetochar(lastchunk[11]),
                dce_bytetochar(lastchunk[12]), dce_bytetochar(lastchunk[13]), dce_bytetochar(lastchunk[14]),
                dce_bytetochar(lastchunk[15]));


        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "%s", buf);
    }
}
#endif
