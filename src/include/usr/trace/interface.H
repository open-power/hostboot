//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/tracinterface.H $
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
#include <stdint.h>
#include <trace/trace.H>      // Internal function and struct definitions

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

/******************************************************************************/
// Macros
/******************************************************************************/

#ifdef TRAC_DEBUG_OUT /* compile out everyones debug traces */

#define TRACDCOMP(des,printf_string,args...) do {} while(0)
#define TRACDBIN(des,descString,address,length) do {} while(0)

#else
#ifndef HOSTBOOT_DEBUG

#define TRACDCOMP(des,printf_string,args...) do {} while(0)
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
        TRACE::Trace::trace_adal_write_all((des),__ALL_HASH(printf_string,-1),__LINE__,TRACE_DEBUG, ##args)


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
#define TRACDBIN(des,printf_string,address,len)                    \
        TRACE::Trace::trace_adal_write_bin(des,__ALL_HASH(printf_string,0),      \
                             __LINE__,                             \
                             address,                              \
                             len,                                  \
                             TRACE_DEBUG)
#endif /* HOSTBOOT_DEBUG */
#endif /* TRAC_DEBUG_OUT */

/**
 * @fn void TRACFCOMP0(des, printf_string)
 * @brief Defines all Field Component Traces
 *
 * The user can pass 0 to 9 parameters to the macro.  These trace calls will
 * always be written to the trace memory buffer.
 *
 * @param des This is assigned by TRAC_INIT_BUFFER
 * @param printf_string String describing the trace entry and providing the
 *                      formatting flags for any parameters passed.
 * @param p1,p2... Optional parameters
 *
 * @return void
*/

/* a macro w/o the param number suffix. number is calculated from printf string */
#define TRACFCOMP(des,printf_string,args...) \
        TRACE::Trace::trace_adal_write_all((des),__ALL_HASH(printf_string,-1),__LINE__,TRACE_FIELD, ##args)


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
 * @param length lenght of the binary data.
 *
 * @return void
*/
#define TRACFBIN(des,printf_string,address,len) \
        TRACE::Trace::trace_adal_write_bin(des,__ALL_HASH(printf_string,0),      \
                             __LINE__,                             \
                             address,                              \
                             len,                                  \
                             TRACE_FIELD)


/**
@fn void TRACSCOMP(des, printf_string, args...)
@brief Defines all Strace Component Traces

The user can pass 0 to 9 parameters to the macro.  These traces will be treated
as debug traces but will never be compiled out of the code so that they can always be
dynamically turned on/off.

@note If you are passing parameters then make sure 'printf_string' has the
@note necessary parameter formatting i.e. 'p1' = "hello" make sure
@note 'printf_string' has '%s' somewhere in it to corretcly format p1.
@return void The user will not be impacted by the failure of this function
@param des This is assigned by TRAC_INIT_BUFFER
@param printf_string string describing the trace entry and providing the formatting flags for any parameters passed.
@param p1,p2... Optional parameters

tracepp replaces trace_adal_hash() with hash value and reduced format string
*/

/* a macro w/o the param number suffix. number is calculated from printf string */
#define TRACSCOMP(des,printf_string,args...) \
     TRACE::Trace::trace_adal_write_all((des),__ALL_HASH(printf_string,-1),__LINE__,TRACE_DEBUG, ##args)


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
 * @fn void TRAC_INIT_BUFFER(des,comp_name, bufferSize)
 * @brief Initializes trace buffer for component
 *
 * This function must be called before any other trace calls.  It
 * initializes a buffer for the calling component and returns a trace
 * descriptor which is used by the trace calls to find the correct
 * buffer to write to.
 *
 * @param des This is assigned by this function.
 * @param comp_name This is the four character name of the component requesting
 *                  the trace buffer.
 * @param bufferSize Requested length of the buffer, if 0 is entered the user will
 *                   get default buffer size.
 * @return void
*/
#define TRAC_INIT_BUFFER(des,comp_name, bufferSize) \
        TRACE::Trace::getTheInstance().initBuffer((des), (comp_name), (bufferSize))

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

#define TRAC_INIT_UNIQ(des, name, sz, ln) TRACE::TracInit static g_trac_##ln(des, name, sz)
#define TRAC_INIT_LINE(des, name, sz, ln) TRAC_INIT_UNIQ(des, name, sz, ln)
#define TRAC_INIT(des, name, sz)	 TRAC_INIT_LINE(des, name, sz, __LINE__)

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

    TracInit(trace_desc_t **o_td, const char *i_comp,const size_t i_size);

    ~TracInit();

};

}


#endif //! -- !defined __TRACE_INTERFACE_H
