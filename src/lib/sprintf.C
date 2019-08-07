/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/sprintf.C $                                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2019                        */
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
#include <util/sprintf.H>
#include <builtins.h>
#include <string.h>
#include <ctype.h>

namespace Util
{

// Create a map, to map a numeric value to its character equivalence
static const char* digits = "0123456789abcdef";

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
        TYPE_DOUBLE,
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

            // Although this modifier can be added to a double, "%lf", it is
            // ignored.  The double to string is a very simple implementation,
            // not meant to be a full blown implementation, but adding the 'l'
            // will not cause any harm.
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

        // Considering that the current implementation of doubles is not being
        // displayed in hexadecimal, there is no need for 'F' in the output
        // display.  Difference between 'f' and 'F' is that F is uppercase and
        // only useful when displaying hex values.
        case 'f':
            opt.type = opt.TYPE_DOUBLE;
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

/* @brief Converts a number into it's ASCII string representation
 *
 * @param[out] o_stringOutput - The recipient of the converted number to ASCII
 * @param[in/out] io_stringOutputIndex - The index into buffer o_stringOutput
 *     @pre  The io_stringOutputIndex is an index to where the first character
 *           will be placed
 *     @post The io_stringOutputIndex is one index location after the last
 *           placed character
 * @param[in]  i_number - The number to convert to a string.
 * @param[in]  i_base - The base of the number; 10, 8, etc
 *
 * @pre i_base must not be 0.  Catastrophic results if so
 */
void convert_number_to_ascii(char     o_stringOutput[],
                             size_t & io_stringOutputIndex,
                                      uint64_t i_number,
                             const    uint64_t i_base)
{
    if (0 == i_number)
    {
        // If no number then use zero
        o_stringOutput[io_stringOutputIndex++] = digits[0];
    }
    else
    {
        // Convert number to ASCII.
        while(i_number)
        {
            o_stringOutput[io_stringOutputIndex++] = digits[i_number % i_base];
            i_number /= i_base;
        }
    }
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
    convert_number_to_ascii(output, len, number, base);

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

/* @brief This is just a rudimentary double to string routine.
 *
 * @details This routine takes in a value of type double, converts it
 *          two a string, and writes it to the provided ConsoleBufferInterface.
 *
 * @note    This is a very simple double to string implementation that will
 *          display the double in a format of NNNN.NNNN in base 10, positive
 *          number only.  It is advised to only use a double of the simplest
 *          form: NNNN.NNN.  Some complicated forms of a double do not convert
 *          well, example 1.2345e-4 converts to 0.958747220502779 (incorrect),
 *          while 1.2345e+4 converts to 12345.0 (correct).  Also working with
 *          doubles can produce imprecise results, example 12334.1469 produces
 *          12334.146899999999 (technically correct), while 3.14159 produces
 *          3.14158 (also technically correct).
 *          Also some printf modifiers are not honored such as 'F', 'l', 'L',
 *          etc. 'F' is for uppercase which is irrelevant when dealing with only
 *          base 10.  'l' and 'L' deal with long double.  Again this is just a
 *          very simple implementation. Also modifiers 'width.precision' punting
 *          on this as well.  Not getting into the minutia of how to display
 *          1.2345e+4 given print format '%3.2f'.
 *          This algorithm works best with doubles of type NNNN.NNNN and print
 *          format of '%f'.
 *
 *
 * @param[out] o_consoleBufferInterface - The recipient of the double in string
 *                                        form.
 * @param[in]  i_formatOptions - Formatting options of the double. Currently not
 *                               being used. Kept to be consistent with current
 *                               interfaces and if someone decides to actually
 *                               implement all the formatting options.
 * @param[in] i_doubleNumber - The double to convert to a string.
 */
size_t display_double(ConsoleBufferInterface& o_consoleBufferInterface,
                      const format_options& i_formatOptions,
                      double i_doubleNumber)
{
    // Extract the integer part from the double. Example: 3 from 3.1415,
    // 1 from 1.0, 31258 from 31258.00001, 0 from 0.123, etc
    uint64_t l_integerPart = static_cast<uint64_t>(i_doubleNumber);

    // Make a copy of the double for manipulation purposes.
    double l_doubleTemp = i_doubleNumber;

    // Make a copy of the integer part for manipulation purposes.
    uint64_t l_integerPartTemp = l_integerPart;

    // The double multiplier to move all digits found after the decimal point
    // to before the decimal point.
    uint64_t l_doubleMultiplier(1);

    // Determine how many digits are there after the decimal point by taking a
    // double such as 3.1415 multiply it by 10 to get 31.415.  Get a copy of the
    // integer part (31). Subtract the integer part (31.0) from the current
    // double (31.415) to get 0.415.  If 0.415 is greater than 0.0, then repeat
    // the process until there are no more digits after the decimal point.
    // The l_doubleMultiplier will be a factor of 10 that is needed to mutiply
    // the double to move all digits after the decimal point to before the
    // decimal point.
    while ((l_doubleTemp - static_cast<double>(l_integerPartTemp)) > 0.0)
    {
        // Increase the multiplier until the value is exactly large enough to
        // move all digits after the decimal point to before the decimal point.
        l_doubleMultiplier*=10;
        // Move 'X' digits after the decimal point to before the decimal point.
        l_doubleTemp*=10;
        // Extract the integer part out of the double
        l_integerPartTemp = static_cast<uint64_t>(l_doubleTemp);
    }

    // Variable to capture to the digits after the decimal point.
    uint64_t l_integerPartAfterDecimalPoint(0);

    // If there are digits after the decimal point then extract those digits.
    if (l_doubleMultiplier > 1)
    {
        // Extract the integer part, after the decimal point, by removing the
        // integer part from the double then multiplying whats left by the
        // multiplier calculated above.
        l_integerPartAfterDecimalPoint = (i_doubleNumber -
                                          static_cast<double>(l_integerPart)) *
                                   l_doubleMultiplier;
    }

    // Length of the character buffer.
    size_t l_bufferLength(0);

    // Buffer to hold the double in string form.
    char l_stringBuffer[64] = { 0 };

    // Default base to 10.
    const uint64_t l_base(10);

    // Convert integer part, after decimal point, to ASCII.
    convert_number_to_ascii(l_stringBuffer, l_bufferLength,
                            l_integerPartAfterDecimalPoint, l_base);

    // Add the decimal point
    l_stringBuffer[l_bufferLength++] = '.';

    // Convert integer part, before decimal point, to ASCII.
    convert_number_to_ascii(l_stringBuffer, l_bufferLength,
                            l_integerPart, l_base);

    // End the string with a NIL terminator.  The l_bufferLength is one index
    // past the last digit character.
    l_stringBuffer[l_bufferLength] = 0;

    // Reverse the string for printing, by swapping to the two ends until they
    // meet in the middle.
    char* l_beginChar = l_stringBuffer;
    char* l_endChar = &(l_stringBuffer[l_bufferLength -1]);
    char l_tempChar;
    while (l_beginChar < l_endChar)
    {
        l_tempChar   = *l_beginChar;
        *l_beginChar = *l_endChar;
        *l_endChar   = l_tempChar;
        ++l_beginChar;
        --l_endChar;
    }

    // Display the double in string form.
    return display_string(o_consoleBufferInterface,
                          i_formatOptions,
                          l_stringBuffer);
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

                case format_options::TYPE_DOUBLE:
                    count += display_double(func, f, va_arg(args,double));
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
