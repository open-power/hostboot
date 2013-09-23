/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/stdio.C $                                             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
                iv_pos--;
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
    console.putc('\0');
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
    console.putc('\0');
    return count;
}

int vsprintf(char *str, const char * format, va_list args)
{
    using Util::vasprintf;

    SprintfBuffer console(str);
    size_t count = vasprintf(console, format, args);

    console.putc('\0');
    return count;
}

int vsnprintf(char *str, size_t size, const char * format, va_list args)
{
    SprintfBuffer console(str, size);
    size_t count = vasprintf(console, format, args);

    console.putc('\0');
    return count;
}
