/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/trace/compiletime_tracehash.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

/* @file compiletime_tracehash.H
 *
 * @brief Implementation details for compile-time trace hashing.
 */

#ifndef COMPILETIME_TRACEHASH_H
#define COMPILETIME_TRACEHASH_H

#include <util/comptime_util.H>

namespace trace_impl
{

// @brief This struct serves as a buffer for compile-time manipulations of
//        strings.
struct compiletime_string
{
    constexpr compiletime_string() = default;

    constexpr compiletime_string(const char* c)
    {
        while (*c)
        {
            data[length] = *c;
            ++length;
            ++c;
        }
    }

    char data[sizeof(TRACE::traceParseInfo::string)] = { };
    size_t length = 0;
};

/* @brief Copies a format specifier, not including width information or other
 *        modifiers, from one string to another.
 * @note This function was taken from tracehash.
 *
 * @param[in] string      The string to copy from
 * @param[in/out] result  The string to append to (result)
 * @param[in/out] r_pos   The current position in the result string
 * @param[in/out] pos     The current position in the input string
 */
constexpr inline void copy_format_spec(const char* string, compiletime_string& result, size_t& r_pos, size_t& pos)
{
    // Search for remainder of format and copy to result.
    int done = 0;
    do
    {
        switch(string[pos])
        {
            // Length tags.
        case 'h': case 'l': case 'L': case 'q':
        case 'j': case 'z': case 't':
            result.data[r_pos++] = string[pos++];
            break;

            // Type tags.
        case 'd': case 'i': case 'o': case 'u':
        case 'x': case 'X': case 'e': case 'E':
        case 'f': case 'F': case 'g': case 'G':
        case 'a': case 'A': case 'c': case 'C':
        case 's': case 'S': case 'p': case 'n':
            result.data[r_pos++] = string[pos];
            done = 1;
            break;

        case '\0':
            done = 1;
            break;

        default:
            pos++;
        }
    } while(!done);
}

/* @brief Reduces a full format string to a smaller string that only contains
 *        the format specifiers, not incliuding any width or other modifier
 *        characters.
 * @note This function was taken from tracehash.
 *
 * @param[in] string           The string to reduce
 * @return compiletime_string  The reduced string
 */
constexpr inline compiletime_string reduce_format_string(const char* string)
{
    size_t length = Util::comptime_strlen(string) + 1;

    compiletime_string result { };

    size_t r_pos = 0; // Current position in result string.

    // Iterate through source string looking for format tags.
    // length - 2 was used because "length" already includes the 0 terminal byte
    //   and we want to make sure we have at least one char beyond the "%"
    //   that way we have two which should deal with most cases
    for(size_t pos = 0; pos < (length-2); pos++)
    {
        // Skip if not %.
        if (string[pos] != '%') continue;
        // Skip over %%.
        if (string[pos+1] == '%') { pos++; continue; }

        // Found a valid start of a format tag... start in result.
        result.data[r_pos++] = '%';

        copy_format_spec(string, result, r_pos, pos);
    }

    result.length = r_pos;

    return result;
}

/* @brief Hash a string.
 *
 * @note This function is widely known as the DJB hash, and is the same as is
 *       used by libbfd in bfd_elf_gnu_hash, used by tracehash
 *
 * @param[in] c            The string to hash
 * @return trace_hash_val  The hash value
 */
constexpr inline trace_hash_val hash_function(const char* c)
{
    trace_hash_val hash = 5831;

    while (*c)
    {
        hash = (hash << 5) + hash + *c;
        ++c;
    }

    return hash;
}

/* @brief A copyable buffer for a C string whose size is known at compile-time.
 *
 * @note compiletime_strings are copied into instances of this class after
 *       format string reduction, so that we allocate exactly as much memory as
 *       needed in the binary, rather than storing compiletime_strings directly
 *       and using some overallocated large fixed-size buffer as a result.
 */
template<size_t N>
struct string_container
{
    char data[N + 1];
};

/* @brief Initialize a string_container<N> with a C-string
 *
 * @param[in] c                 The string to initialize the return value with
 * @return string_container<N>  The string object
 */
template<size_t N>
constexpr string_container<N> initialize_string(const char* c)
{
    string_container<N> string { };

    for (size_t i = 0; i < N; ++i)
    {
        string.data[i] = *c;
        ++c;
    }

    return string;
}

/* @brief Get the basename of a file path
 *
 * @note Usually this would be done by the extracthash/tracehash
 * program. However, for HBRT, we need to embed the full strings in the binary,
 * and so we need to be able to fix them up ourselves.
 */
constexpr inline compiletime_string compiletime_basename(const char* c)
{
    const char* slash = c + Util::comptime_strlen(c);

    while (slash != c)
    {
        if (*slash == '/')
        {
            break;
        }
        --slash;
    }

    if (*slash == '/')
    {
        ++slash;
    }

    compiletime_string str { };

    while (*slash)
    {
        str.data[str.length] = *slash;
        ++str.length;
        ++slash;
    }

    return str;
}

/* @brief Append a string to a compile-time string and return the result
 *
 * @param[in] str              A compile-time string
 * @param[in] c                A C-string
 * @return compiletime_string  Result of the concatenation
 */
constexpr inline compiletime_string operator+(compiletime_string str, const char* c)
{
    compiletime_string out = str;

    while (*c)
    {
        out.data[out.length] = *c;
        ++out.length;
        ++c;
    }

    return out;
}

#ifdef TRACEHASH_FULL_STRINGS
/* @brief Replace the first occurrence of TRACE_FILENAME in a string with the
 *        basename of the filename.
 *
 * @note We only replace the filename marker ourselves when we want to embed the
 *       full trace string in the binary rather than just in the hbotStringFile,
 *       as is the case for Hostboot Runtime. This is the equivalent of the
 *       --full-strings tracehash parameter.
 *
 * @param[in] str             The trace string, possibly containing the TRACE_FILENAME marker
 * @param[in] filename        The filename of the file that called the trace function
 * return compiletime_string  A copy of the string, but with TRACE_FILENAME replaced
 */
constexpr compiletime_string replace_filename_marker(compiletime_string str, const char* filename)
{
    static_assert(sizeof(TRACE_FILENAME) == 2); // Make sure we're using the 1-character filename marker

    for (size_t i = 0; i < str.length; ++i)
    {
        if (str.data[i] == *TRACE_FILENAME)
        {
            str.data[i] = 0;
            str.length = i;

            return str + filename + ": " + (str.data + i + 1);
        }
    }

    return str;
}
#endif

/* @brief Handy template to force compile-time evaluation of an integer
 *        expression.
 */
template<uint32_t V>
struct force_compile_evaluation
{
    static constexpr uint32_t value = V;
};

}

// Magic value for extracthash to check to make sure that it extracts only the
// correct sections.
constexpr uint32_t TRACE_MAGIC = 0x54524143; // 'TRAC'

// If we want full strings in the binary, we have to replace the filename marker
// in the trace string. If not, we can avoid doing that.
#ifdef TRACEHASH_FULL_STRINGS
#define __TRACE_HASH_STRUCTURES(str)                                    \
    constexpr trace_hash_val string_hash                                \
        = trace_impl::force_compile_evaluation<trace_impl::hash_function(str __FILE__)>::value; \
    constexpr trace_impl::compiletime_string trace_with_filename        \
        = trace_impl::replace_filename_marker(str, trace_impl::compiletime_basename(__FILE__).data); \
    static const trace_impl::string_container<trace_with_filename.length> tracehash_reduced_string \
        = trace_impl::initialize_string<trace_with_filename.length>(trace_with_filename.data); \
    const TRACE::traceCodeInfo __traceData_codeInfo __attribute((unused)) \
        = { tracehash_reduced_string.data, string_hash };               \
    static TRACE::traceParseInfo __traceData_parseInfo__DISCARD __attribute((used)) \
        = { TRACE_MAGIC,                                                \
            string_hash,                                                \
            sizeof(TRACE::traceParseInfo::string),                      \
            sizeof(TRACE::traceParseInfo::file),                        \
            0,                                                          \
            str, __FILE__                                               \
          };
#else
#define __TRACE_HASH_STRUCTURES(str)                                    \
    constexpr trace_impl::compiletime_string specifiers                 \
        = trace_impl::reduce_format_string(str);                        \
    static const trace_impl::string_container<specifiers.length> tracehash_reduced_string \
        = trace_impl::initialize_string<specifiers.length>(specifiers.data); \
    constexpr trace_hash_val string_hash                                \
        = trace_impl::force_compile_evaluation<trace_impl::hash_function(str __FILE__)>::value; \
    const TRACE::traceCodeInfo __traceData_codeInfo __attribute((unused)) \
        = { tracehash_reduced_string.data, string_hash };               \
    static TRACE::traceParseInfo __traceData_parseInfo__DISCARD __attribute((used)) \
        = { TRACE_MAGIC,                                                \
            string_hash,                                                \
            sizeof(TRACE::traceParseInfo::string),                      \
            sizeof(TRACE::traceParseInfo::file),                        \
            0,                                                          \
            str, __FILE__                                               \
          };
#endif

#endif
