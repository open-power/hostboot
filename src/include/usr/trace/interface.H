/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/trace/interface.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
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

#ifndef __TRACE_INTERFACE_H
#define __TRACE_INTERFACE_H

/*!@file interface.H
 * @brief Contains macros for trace interface
 *
 * Note that this file was for the most parted ported in from the fsp-trace
 * implementation.
 *
 * This header file provides a common interface for the Trace
 * mechanism.
 *
 * There are two types of trace, debug and field, that you can use when tracing.
 * Debug traces are not enabled by default, they must be enabled by the user.
 * Field traces will always be enabled.
*/

/******************************************************************************/
// Includes
/******************************************************************************/
#include <utility>
#include <builtins.h>
#include <stdint.h>
#include <trace/trace.H>      // Internal function and struct definitions
#include <type_traits>

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
#define ENTER_MRK ">>"
#define EXIT_MRK  "<<"
#define ERR_MRK   "E>"
#define FAIL_MRK  "F>"
#define WARN_MRK  "W>"
#define INFO_MRK  "I>"
#define ARG_MRK   "A>"

#if defined(COMPILETIME_TRACEHASH) && defined(TRACEHASH_FULL_STRINGS)
// We change this to one character when we are replacing the filename at
// compile-time (for hostboot runtime) because it's simpler to search for a
// character than a full string.
#define TRACE_FILENAME "\xFE"
#else
#define TRACE_FILENAME "TRACEPP_INSERT_FILENAME"
#endif

const uint32_t TRACE_DEBUG   = 1;       //Indicates trace is debug
const uint32_t TRACE_FIELD   = 0;       //Indicates trace is field


// check compatibility of header file/macros and preprocessor tracepp
// if tracepp was used
#define TRAC_MACROVER 1
#ifdef TRAC_TRACEPP
#if !defined(TRAC_PPVER)
#warning fsptrace preprocessor version unknown, might be incompatible with header file
#elif TRAC_PPVER < TRAC_MACROVER
#error fsptrace header file version and preprocessor version dont fit
#endif
#endif


/* for any trace_adal_write_all call we need the printf_string in addition to
 * the hash value. if tracepp is used it will add a (shortened) printf string,
 * otherwise the macros has to add it
 */
#ifdef TRAC_TRACEPP
#define __ALL_HASH(printf_string,num) trace_adal_hash(printf_string,num)
#else
#define __ALL_HASH(printf_string,num) trace_adal_hash(printf_string,num),printf_string
#endif

#ifdef COMPILETIME_TRACEHASH
#include <trace/compiletime_tracehash.H>
#else

#define __TRACE_HASH_STRUCTURES(str) \
    static TRACE::traceCodeInfo __traceData_codeInfo \
        __attribute((used)) = \
            { NULL, 1 }; \
    static TRACE::traceParseInfo __traceData_parseInfo \
        __attribute((used)) = \
            { sizeof(TRACE::traceParseInfo::string), \
              sizeof(TRACE::traceParseInfo::file), 0, \
              str, __FILE__, &__traceData_codeInfo }

#endif

/******************************************************************************/
// Macros
/******************************************************************************/

#ifdef TRAC_DEBUG_OUT /* compile out everyones debug traces */

#define TRACDCOMP(des,printf_string,args...) do {} while(0)
#define TRACDBIN(des,descString,address,length) do {} while(0)

#else
#ifndef HOSTBOOT_DEBUG

#define TRACDCOMP(des,printf_string,args...) \
    SUPPRESS_UNUSED_VARIABLE(NULL, ##args)
#define TRACDBIN(des,descString,address,length) do {} while(0)

#else

/* direct them to real function calls */

/**
 * @fn void TRACDCOMP0(des, printf_string)
 * @brief Defines all Debug Component Traces
 *
 * The user can pass 0 to 9 parameters to the macro.  In the field environment,
 * these trace calls will be compiled out of the code.  Use these for early bringup
 * needs. These trace calls are written to a memory buffer.
 *
 * @param des This is assigned by TRAC_INIT_BUFFER
 * @param printf_string String describing the trace entry and providing the
 *                      formatting flags for any parameters passed.
 * @param p1,p2... Optional parameters
 *
 * @return void
*/

/* a macro w/o the param number suffix. number is calculated from printf string */
#define TRACDCOMP(des,printf_string,args...) \
    { \
        TRAC_CHECK_ARGS(printf_string, args);    \
        __TRACE_HASH_STRUCTURES(printf_string); \
        TRACE::trace_adal_write_all((des), \
                                    &__traceData_codeInfo, \
                                    __LINE__, \
                                    TRACE_DEBUG, \
                                    ##args); \
    }


/**
 * @fn void TRACDBIN(des,descString,address,length)
 * @brief Defines debug binary trace
 *
 * The binary trace should be used to write out a section of memory.
 *
 * @param des This is assigned by TRAC_INIT_BUFFER
 * @param descString A string that will be put in front of the binary dump,
 *                   developer assigns anything they want.
 * @param address Address of beginning of data to dump.
 * @param length length of the binary data.
 *
 * @return void

*/
#define TRACDBIN(des,printf_string,address,len) \
    { \
        __TRACE_HASH_STRUCTURES(printf_string); \
        TRACE::trace_adal_write_bin((des), \
                                    &__traceData_codeInfo, \
                                    __LINE__, \
                                    address, \
                                    len, \
                                    TRACE_DEBUG); \
    }

#endif /* HOSTBOOT_DEBUG */
#endif /* TRAC_DEBUG_OUT */

/* These few structs and functions are to implement TRAC_CHECK_ARGS macro, which
 * checks at compile time that too many arguments are not passed to a trace
 * function. */

template<typename... Args>
struct TRAC_ARG_TUPLE
{
    static constexpr size_t num_args = sizeof...(Args);
};

template<typename... Args>
TRAC_ARG_TUPLE<Args...> TRAC_MAKE_ARG_TUPLE(Args... args);

template<typename T>
inline constexpr size_t TRAC_COUNT_ARGS()
{
    return T::num_args;
}

inline constexpr size_t TRAC_COUNT_FMT_SPECIFIERS(const char* const str,
                                                  const size_t len = 0)
{
    if (str[0] == '\0')
    {
        return len;
    }

    if (str[0] == '%')
    {
        if (str[1] == '%')
        {
            return TRAC_COUNT_FMT_SPECIFIERS(str + 2, len);
        }
        else
        {
            // This may not skip the entire format specifier (in the
            // case of e.g. "%lld"), but we don't care because we just
            // want to count percent signs.
            return TRAC_COUNT_FMT_SPECIFIERS(str + 2, len + 1);
        }
    }

    return TRAC_COUNT_FMT_SPECIFIERS(str + 1, len);
}

template<typename T>
struct TRAC_CHECK_ARG_TYPE
{
    /* @TODO: Finer-grained argument type checking
    static bool is_bits_type(...);

    template<typename X>
    static int is_bits_type(const X&, const typename X::bits_type&);

    using decay_T = typename std::decay<T>::type;

    static constexpr bool value
        = (std::is_integral<decay_T>::value
           || std::is_same<decay_T, float>::value
           || std::is_same<decay_T, double>::value
           || std::is_enum<decay_T>::value
           || std::is_pointer<decay_T>::value
           || std::is_same<decltype(is_bits_type(std::declval<T>(), 0)), int>::value
           || (std::is_pod<decay_T>::value && sizeof(T) <= 8));
    */
    static constexpr bool value = sizeof(T) <= 8;
};

template<typename... Args>
struct TRAC_CHECK_ARG_TYPES;

template<typename T, typename... Args>
struct TRAC_CHECK_ARG_TYPES<TRAC_ARG_TUPLE<T, Args...>>
    : TRAC_CHECK_ARG_TYPES<TRAC_ARG_TUPLE<Args...>>
{
    static_assert(TRAC_CHECK_ARG_TYPE<T>::value,
                  "Invalid argument type given to trace macro");
};

template<>
struct TRAC_CHECK_ARG_TYPES<TRAC_ARG_TUPLE<>>
{
    static constexpr bool value = true;
};

#define TRAC_CHECK_ARGS(skip, printf_string, args...)                   \
    static_assert(skip || TRAC_COUNT_ARGS<decltype(TRAC_MAKE_ARG_TUPLE(args))>() <= TRAC_MAX_ARGS, \
                  "Too many arguments to trace function");              \
    static_assert(skip || (TRAC_COUNT_ARGS<decltype(TRAC_MAKE_ARG_TUPLE(args))>() \
                           == TRAC_COUNT_FMT_SPECIFIERS(printf_string)), \
                  "Number of format specifiers does not match number of arguments"); \
    static_assert(TRAC_CHECK_ARG_TYPES<decltype(TRAC_MAKE_ARG_TUPLE(args))>::value);

/**
 * @fn void TRACFCOMP_CHECKED(skip_check, des, printf_string, p1, p2, ...)
 * @brief Defines all Field Component Traces
 *
 * The user can pass 0 to 9 parameters to the macro.  These trace calls will
 * always be written to the trace memory buffer.
 *
 * @param skip_check If true, skip the max arg count check
 * @param des This is assigned by TRAC_INIT_BUFFER
 * @param printf_string String describing the trace entry and providing the
 *                      formatting flags for any parameters passed.
 * @param p1,p2... Optional parameters
 *
 * @return void
 * @note If skip_check is false, this macro will check that the number of
 *       optional parameters does not exceed TRAC_MAX_ARGS. If it is true, the
 *       check is skipped.
 */

/* a macro w/o the param number suffix. number is calculated from printf string */
#define TRACFCOMP_CHECKED(skip_check,des,printf_string,args...)  \
    {                                                            \
        TRAC_CHECK_ARGS(skip_check,printf_string,args);          \
        __TRACE_HASH_STRUCTURES(printf_string);                  \
        TRACE::trace_adal_write_all((des),                       \
                                    &__traceData_codeInfo,       \
                                    __LINE__,                    \
                                    TRACE_FIELD,                 \
                                    ##args);                     \
    }

/**
 * @brief Forward arguments to TRACFCOMP_CHECKED, and enable max arg count check.
 */
#define TRACFCOMP(des,printf_string,args...) \
    TRACFCOMP_CHECKED(false,des,printf_string,##args)

/**
 * @fn void TRACFBIN(des,descString,address,len)
 * @brief Defines field binary trace
 *
 * The binary trace should be used to write out a section of memory.
 *
 * @param des This is assigned by TRAC_INIT_BUFFER
 * @param descString A string that will be put in front of the binary dump,
 *                   developer assigns anything they want.
 * @param address Address of beginning of data to dump.
 * @param length length of the binary data.
 *
 * @return void
*/
#define TRACFBIN(des,printf_string,address,len) \
    { \
        __TRACE_HASH_STRUCTURES(printf_string); \
        TRACE::trace_adal_write_bin((des), \
                                &__traceData_codeInfo, \
                                __LINE__, \
                                address, \
                                len, \
                                TRACE_FIELD); \
    }

/**
 * @fn void TRACSCOMP_CHECKED(skip_check, des, printf_string, p1, p2...)
 * @brief Defines all Strace Component Traces
 *
 * The user can pass 0 to 9 parameters to the macro.  These traces will be treated
 * as debug traces but will never be compiled out of the code so that they can always be
 * dynamically turned on/off.
 *
 * @note If you are passing parameters then make sure 'printf_string' has the
 * @note necessary parameter formatting i.e. 'p1' = "hello" make sure
 * @note 'printf_string' has '%s' somewhere in it to corretcly format p1.
 * @return void The user will not be impacted by the failure of this function
 * @param skip_check If true, skip the max arg count check
 * @param des This is assigned by TRAC_INIT_BUFFER
 * @param printf_string string describing the trace entry and providing the formatting flags for any parameters passed.
 * @param p1,p2... Optional parameters
 * @note If skip_check is false, this macro will check that the number of
 *       optional parameters does not exceed TRAC_MAX_ARGS. If it is true, the
 *       check is skipped.
 *
 * tracepp replaces trace_adal_hash() with hash value and reduced format string
*/

/* a macro w/o the param number suffix. number is calculated from printf string */
#define TRACSCOMP_CHECKED(skip_check,des,printf_string,args...) \
    { \
        TRAC_CHECK_ARGS(skip_check,printf_string,##args);   \
        __TRACE_HASH_STRUCTURES(printf_string); \
        TRACE::trace_adal_write_all((des), \
                                    &__traceData_codeInfo, \
                                    __LINE__, \
                                    TRACE_DEBUG, \
                                    ##args); \
    }

/**
 * @brief Forward arguments to TRACSCOMP_CHECKED, and enable max arg count check.
 */
#define TRACSCOMP(des,printf_string,args...) \
    TRACSCOMP_CHECKED(false,des,printf_string,args)


/**
 * Field and Debug trace macros
 * Users must define COMP_TD for their components prior to using macros.
 * Additionally, users must define COMP_NAMESPACE, COMP_CLASS & COMP_FN
 * prior to using the ENTER_/EXIT_ macros.
 * Example:
 *     #define COMP_TD g_my_trace_desc
 *     #define COMP_NAMESPACE "my_namespace"
 *     #define COMP_CLASS "my_class"
 *     #define COMP_FN "my_function"
 */

#define TRAC_ENTER(args...) \
        TRACFCOMP(__COMP_TD__, ENTER_MRK args)
#define TRAC_EXIT(args...) \
        TRACFCOMP(__COMP_TD__, EXIT_MRK args)
#define TRAC_INF(args...) \
        TRACFCOMP(__COMP_TD__, INFO_MRK args)
#define TRAC_ERR(args...) \
        TRACFCOMP(__COMP_TD__, ERR_MRK args)

#define TRAC_ENTER_(args...) \
        TRACFCOMP(__COMP_TD__, ENTER_MRK __COMP_NAMESPACE__ "::" __COMP_CLASS__ "::" __COMP_FN__ " " args)
#define TRAC_EXIT_(args...) \
        TRACFCOMP(__COMP_TD__, EXIT_MRK __COMP_NAMESPACE__ "::" __COMP_CLASS__ "::" __COMP_FN__ " " args)

#define DTRAC_ENTER(args...) \
        TRACDCOMP(__COMP_TD__, ENTER_MRK args)
#define DTRAC_EXIT(args...) \
        TRACDCOMP(__COMP_TD__, EXIT_MRK args)
#define DTRAC_INF(args...) \
        TRACDCOMP(__COMP_TD__, INFO_MRK args)
#define DTRAC_ERR(args...) \
        TRACDCOMP(__COMP_TD__, ERR_MRK args)

#define DTRAC_ENTER_(args...) \
        TRACDCOMP(__COMP_TD__, ENTER_MRK __COMP_NAMESPACE__ "::" __COMP_CLASS__ "::" __COMP_FN__ " " args)
#define DTRAC_EXIT_(args...) \
        TRACDCOMP(__COMP_TD__, EXIT_MRK __COMP_NAMESPACE__ "::" __COMP_CLASS__ "::" __COMP_FN__ " " args)

#define STRAC_ENTER(args...) \
        TRACSCOMP(__COMP_TD__, ENTER_MRK args)
#define STRAC_EXIT(args...) \
        TRACSCOMP(__COMP_TD__, EXIT_MRK args)
#define STRAC_INF(args...) \
        TRACSCOMP(__COMP_TD__, INFO_MRK args)
#define STRAC_ERR(args...) \
        TRACSCOMP(__COMP_TD__, ERR_MRK args)

#define STRAC_ENTER_(args...) \
        TRACSCOMP(__COMP_TD__, ENTER_MRK __COMP_NAMESPACE__ "::" __COMP_CLASS__ "::" __COMP_FN__ " " args)
#define STRAC_EXIT_(args...) \
        TRACSCOMP(__COMP_TD__, EXIT_MRK __COMP_NAMESPACE__ "::" __COMP_CLASS__ "::" __COMP_FN__ " " args)

/**
 * @fn void TRAC_INIT_BUFFER(des,comp_name, bufferSize, bufferType)
 * @brief Initializes trace buffer for component
 *
 * This function must be called before any other trace calls.  It
 * initializes a buffer for the calling component and returns a trace
 * descriptor which is used by the trace calls to find the correct
 * buffer to write to.
 *
 * @param des       A trac_desc_t * initialized to null by the using code.
 * @param comp_name This is the 15 character name of the component requesting
 *                  the trace buffer. Will be stored internally in upper case.
 * @param bufferSize Requested length of the buffer, if 0 is entered the user
 *                   will get default buffer size. Subject to maximum
 *                   allowable size.
 * @param bufferType Type (speed) of buffer.  Defaults to BUFFER_FAST.
 * @return void
 *
 * @note The Hostboot implementation of trace does not have individual
 *       "buffers" to hold the trace entries, but does keep information to
 *       separately account for trace sizes.  The bufferSize becomes a
 *       lower-bound on how much data the implementation will keep for the
 *       component.
 *
*/
#define TRAC_INIT_BUFFER(des,comp_name, bufferSize, bufferType...) \
        TRACE::initBuffer((des), (comp_name), (bufferSize), ## bufferType)

/**
 * @fn void TRAC_FLUSH_BUFFERS()
 * @brief Flushes the traces to the continuous trace buffers.
 */
#define TRAC_FLUSH_BUFFERS() TRACE::flushBuffers()


#ifdef __HIDDEN_TRACEIF_CLEARBUFFER
/**
 * @fn void TRAC_CLEAR_BUFFERS()
 * @brief For all in-use component trace buffers, clear their contents.
 *
 * @return void
*/
#define TRAC_CLEAR_BUFFERS() TRACE::Trace::getTheInstance().clearAllBuffers()
#endif


/*******************************************************************************
  TRAC_INIT: Class for creating trace descriptor object.

  About the macros.
    TRAC_INIT		-- Called by users, adds __LINE__ for uniqueness.
    TRAC_INIT_LINE	-- Translates __LINE__ into the line number.  Using
			macro expansion in this statement would result in
			tracInit static g_trac_"__LINE__"
    TRAC_INIT_UNIQ	-- With line number translated, use the '##' operator to
    			append number in variable name.
*******************************************************************************/

#define TRAC_INIT_UNIQ(des, name, sz, ln, type...) \
                TRACE::TracInit static g_trac_##ln(des, name, sz, ## type)
#define TRAC_INIT_LINE(des, name, sz, ln, type...) \
                TRAC_INIT_UNIQ(des, name, sz, ln, ## type)
#define TRAC_INIT(des, name, sz, type...) \
                TRAC_INIT_LINE(des, name, sz, __LINE__, ## type)

namespace TRACE
{
/******************************************************************************/
// Allow users to init trace buffer outside of a function
/******************************************************************************/
class TracInit
{
  public:

    /*------------------------------------------------------------------------*/
    /* Constructor                                                            */
    /*------------------------------------------------------------------------*/

    TracInit(trace_desc_t **o_td, const char *i_comp,
             const size_t i_size, uint8_t i_bufferType = TRACE::BUFFER_FAST);

    ~TracInit();

};


}


#endif //! -- !defined __TRACE_INTERFACE_H
