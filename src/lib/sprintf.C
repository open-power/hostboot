/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/sprintf.C $                                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#include <util/sprintf.H>
#include <builtins.h>
#include <string.h>
#include <ctype.h>

namespace Util
{

struct format_options
{
    enum
    {
        ALT_FORM = 0x1,
        ZERO_PAD = 0x2,
        LEFT_ALIGN = 0x4,
        EMPTY_SIGN = 0x8,
        PLUS_SIGN = 0x10
    };

    int flags;

    size_t field_width;
    size_t precision;

    enum lengths
    {
        LEN_INT,
        LEN_CHAR,
        LEN_SHORT,
        LEN_LONG,
        LEN_LONGLONG,
        LEN_SIZET,
        LEN_PTRDIFF,
    };

    lengths length;

    bool upper;

    enum types
    {
        TYPE_PERCENT,
        TYPE_SIGNED_DECIMAL,
        TYPE_DECIMAL,
        TYPE_OCTAL,
        TYPE_HEX,
        TYPE_BINARY,
        TYPE_CHAR,
        TYPE_STRING,
        TYPE_PTR,
    };

    types type;
};

void parse_format_options(format_options& opt, const char*& fmt)
{
    opt = format_options();
    ++fmt; // increment past first %.

    if (('\0' == *fmt) || ('%' == *fmt))
    {
        opt.type = opt.TYPE_PERCENT;
        return;
    }

    // Look for 'flag' type options.
    bool should_continue = true;
    while(should_continue)
    {
        switch(*fmt)
        {
            case '#':
                opt.flags |= opt.ALT_FORM;
                ++fmt;
                break;

            case '0':
                opt.flags |= opt.ZERO_PAD;
                ++fmt;
                break;

            case '-':
                opt.flags |= opt.LEFT_ALIGN;
                ++fmt;
                break;

            case ' ':
                opt.flags |= opt.EMPTY_SIGN;
                ++fmt;
                break;

            case '+':
                opt.flags |= opt.PLUS_SIGN;
                ++fmt;
                break;

            default:
                should_continue = false;
                break;
        }
    }

    // Look for field width options.
    should_continue = true;
    while (should_continue)
    {
        if(isdigit(*fmt))
        {
            opt.field_width *= 10;
            opt.field_width += (*fmt) - '0';
            ++fmt;
        }
        else
        {
            should_continue = false;
        }
    }

    // Look for precision options.
    if ('.' == *fmt)
    {
        ++fmt;
        should_continue = true;
        while (should_continue)
        {
            if(isdigit(*fmt))
            {
                opt.precision *= 10;
                opt.precision += (*fmt) - '0';
                ++fmt;
            }
            else
            {
                should_continue = false;
            }
        }
    }

    // Look for length modifiers.
    should_continue = true;
    while (should_continue)
    {
        switch (*fmt)
        {
            case 'h':
                if ((opt.length == opt.LEN_SHORT) ||
                    (opt.length == opt.LEN_CHAR))
                {
                    opt.length = opt.LEN_CHAR;
                }
                else
                {
                    opt.length = opt.LEN_SHORT;
                }
                ++fmt;
                break;

            case 'l':
                if ((opt.length == opt.LEN_LONG) ||
                    (opt.length == opt.LEN_LONGLONG))
                {
                    opt.length = opt.LEN_LONGLONG;
                }
                else
                {
                    opt.length = opt.LEN_LONG;
                }
                ++fmt;
                break;

            case 'z':
                opt.length = opt.LEN_SIZET;
                ++fmt;
                break;

            case 't':
                opt.length = opt.LEN_PTRDIFF;
                ++fmt;
                break;

            default:
                should_continue = false;
                break;
        }
    }

    // Look for the type specifier
    switch (*fmt)
    {
        case 'd':
        case 'i':
            opt.type = opt.TYPE_SIGNED_DECIMAL;
            break;

        case 'o':
            opt.type = opt.TYPE_OCTAL;
            break;

        case 'u':
            opt.type = opt.TYPE_DECIMAL;
            break;

        case 'x':
            opt.type = opt.TYPE_HEX;
            break;

        case 'X':
            opt.type = opt.TYPE_HEX;
            opt.upper = true;
            break;

        case 'b':
            opt.type = opt.TYPE_BINARY;
            break;

        case 'B':
            opt.type = opt.TYPE_BINARY;
            opt.upper = true;
            break;

        case 'c':
            opt.type = opt.TYPE_CHAR;
            break;

        case 's':
            opt.type = opt.TYPE_STRING;
            break;

        case 'p':
            opt.type = opt.TYPE_PTR;
            break;

        default:
            opt.type = opt.TYPE_PERCENT;
    }
    if ('\0' != *fmt)
    {
        ++fmt;
    }

}

size_t display_pre_header(ConsoleBufferInterface& func,
                          const format_options& f, size_t size)
{
    size_t count = 0;
    if (!(f.flags & format_options::LEFT_ALIGN) &&
            f.field_width)
    {
        for (size_t i = size; i < f.field_width; i++)
        {
            func(' ');
            ++count;
        }
    }
    return count;
}

size_t display_post_header(ConsoleBufferInterface& func,
                           const format_options& f, size_t size)
{
    size_t count = 0;
    if ((f.flags & format_options::LEFT_ALIGN) &&
            f.field_width)
    {
        for (size_t i = size; i < f.field_width; i++)
        {
            func(' ');
            ++count;
        }
    }
    return count;
}

size_t display_string(ConsoleBufferInterface& func,
                      const format_options& f, const char* string)
{
    size_t count = 0;
    size_t len = strlen(string);

    count += display_pre_header(func, f, len);
    for(size_t i = 0; i < len; i++)
    {
        func(string[i]);
        ++count;
    }
    count += display_post_header(func, f, len);

    return count;
}

size_t display_number(ConsoleBufferInterface& func,
                      const format_options& f, uint64_t number)
{
    static const char* digits = "0123456789abcdef";
    size_t count = 0;

    char output[64];
    size_t len = 0;

    // Determine sign of number.
    char sign = '\0';
    if (f.type == format_options::TYPE_SIGNED_DECIMAL)
    {
        if (0 > (int64_t) number)
        {
            sign = '-';
            number = -1 * (int64_t) number;
        }
        else if (f.flags & format_options::PLUS_SIGN)
        {
            sign = '+';
        }
        else if (f.flags & format_options::EMPTY_SIGN)
        {
            sign = ' ';
        }
    }

    // Determine base.
    uint64_t base = 0;
    switch (f.type)
    {
        case format_options::TYPE_BINARY:
            base = 2;
            break;

        case format_options::TYPE_OCTAL:
            base = 8;
            break;

        case format_options::TYPE_HEX:
        case format_options::TYPE_PTR:
            base = 16;
            break;

        case format_options::TYPE_SIGNED_DECIMAL:
        case format_options::TYPE_DECIMAL:
        default:
            base = 10;
            break;
    }

    // Determine alt-form header state.
    size_t special_len = 0;
    char special[2];

    if ((f.flags & format_options::ALT_FORM) ||
        (f.type == format_options::TYPE_PTR))
    {
        switch (f.type)
        {
            case format_options::TYPE_BINARY:
                special[0] = '0';
                special[1] = 'b';
                special_len = 2;
                break;

            case format_options::TYPE_HEX:
            case format_options::TYPE_PTR:
                special[0] = '0';
                special[1] = 'x';
                special_len = 2;
                break;

            case format_options::TYPE_OCTAL:
                special[0] = '0';
                special_len = 1;
                break;

            default:
                break;
        }
    }

    // Convert number to ascii.
    while(number)
    {
        output[len++] = digits[number % base];
        number /= base;
    }
    if (len == 0)
    {
        output[len++] = digits[0];
    }

    // Fix up zero pad.
    while(len < f.precision)
    {
        output[len++] = digits[0];
    }

    // Output pre-header.
    size_t total_len = len + (sign == '\0' ? 0 : 1) + special_len;
    if (f.flags & format_options::ZERO_PAD)
    {
        while (total_len < f.field_width)
        {
            output[len++] = digits[0];
            ++total_len;
        }
    }
    else
    {
        count += display_pre_header(func, f, total_len);
    }

    // Output sign, special.
    if (sign != '\0')
    {
        func(sign);
        ++count;
    }
    if (special_len)
    {
        for (size_t i = 0; i < special_len; i++)
        {
            func(f.upper ? toupper(special[i]) : special[i]);
            ++count;
        }
    }

    // Output number.
    for (size_t i = 0; i < len; i++)
    {
        func(f.upper ? toupper(output[len - (i+1)]) : output[len - (i+1)]);
        ++count;
    }

    // Output post-header.
    if (!(f.flags & format_options::ZERO_PAD))
    {
        count += display_post_header(func, f, total_len);
    }

    return count;
}

size_t vasprintf(ConsoleBufferInterface& func, const char* fmt, va_list& args)
{
    int count = 0;

    while(*fmt)
    {
        if ('%' == *fmt)
        {
            format_options f;
            parse_format_options(f, fmt);

            switch(f.type)
            {
                case format_options::TYPE_PERCENT:
                    func('%');
                    ++count;
                    break;

                case format_options::TYPE_PTR:
                    display_number(func, f, (uint64_t) va_arg(args, void*));
                    break;

                case format_options::TYPE_CHAR:
                    count += display_pre_header(func, f, 1);
                    func(va_arg(args,int));
                    ++count;
                    count += display_post_header(func, f, 1);
                    break;

                case format_options::TYPE_STRING:
                    count += display_string(func, f, va_arg(args,const char*));
                    break;

                // All the number cases.
                default:
                {
                    uint64_t number = 0;
                    switch (f.length)
                    {
                        case format_options::LEN_INT:
                        case format_options::LEN_CHAR:
                        case format_options::LEN_SHORT:
                                // All of these types are automatically
                                // promoted to 'unsigned int' when passed
                                // through va_arg lists.
                            number = (uint64_t) va_arg(args, unsigned int);
                            break;

                        case format_options::LEN_LONG:
                        case format_options::LEN_LONGLONG:
                                // Hostboot doesn't use 'long long' but FSP
                                // code tends to use %llx for uint64_t.
                            number = (uint64_t) va_arg(args, unsigned long);
                            break;

                        case format_options::LEN_SIZET:
                            number = (uint64_t) va_arg(args, size_t);
                            break;

                        case format_options::LEN_PTRDIFF:
                            number = (uint64_t) va_arg(args, ptrdiff_t);
                            break;
                    }
                    count += display_number(func, f, number);
                }
            }
        }
        else // Stand-alone character.
        {
            func(*fmt++);
            ++count;
        }
    }
    return count;
}

};
