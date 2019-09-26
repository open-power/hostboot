/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/stdio.C $                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#include <stdint.h>
#include <stdio.h>
#include <util/sprintf.H>

class SprintfBuffer : public Util::ConsoleBufferInterface
{
    public:
        int putc(int c)
        {
            if ('\b' == c)
            {
                if (iv_pos > 0)
                {
                    iv_pos--;
                }
            }
            else if (iv_pos < iv_size)
            {
                iv_buffer[iv_pos++] = c;
            }
            else
            {
                iv_pos++;
            }
            return c;
        }

        void nullTerminate()
        {
            if (iv_size > 0)
            {
                if (iv_pos >= iv_size)
                {
                    iv_pos = iv_size - 1;
                }

                putc('\0');
            }
        }

        explicit SprintfBuffer(char* buf, size_t size = UINT64_MAX) :
            iv_pos(0), iv_size(size), iv_buffer(buf) {};

        size_t operator()(int c) { return putc(c); }

    private:
        size_t iv_pos;
        size_t iv_size;
        char * iv_buffer;
};

int sprintf(char *str, const char * format, ...)
{
    using Util::vasprintf;

    va_list args;
    va_start(args, format);

    SprintfBuffer console(str);
    size_t count = vasprintf(console, format, args);

    va_end(args);
    console.nullTerminate();
    return count;
}

int snprintf(char *str, size_t size, const char * format, ...)
{
    using Util::vasprintf;

    va_list args;
    va_start(args, format);

    SprintfBuffer console(str, size);
    size_t count = vasprintf(console, format, args);

    va_end(args);
    console.nullTerminate();
    return count;
}

int vsprintf(char *str, const char * format, va_list args)
{
    using Util::vasprintf;

    SprintfBuffer console(str);
    size_t count = vasprintf(console, format, args);

    console.nullTerminate();
    return count;
}

int vsnprintf(char *str, size_t size, const char * format, va_list args)
{
    SprintfBuffer console(str, size);
    size_t count = vasprintf(console, format, args);

    console.nullTerminate();
    return count;
}
