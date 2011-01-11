/******************************************************************************
 * IBM Confidential
 *
 * Licensed Internal Code Source Materials
 *
 * IBM Flexible Support Processor Licensed Internal Code
 *
 * (c) Copyright IBM Corp. 2004, 2010
 *
 * The source code is for this program is not published or otherwise divested
 * of its trade secrets, irrespective of what has been deposited with the
 * U.S. Copyright Office.
 *****************************************************************************/

#ifndef TRACINTERFACE_H
#define TRACINTERFACE_H

/*!@file tracinterface.H
 * @brief Contains macros for trace interface
 *
 * This header file provides a common interface for the Trace
 * mechanism.  Trace is a way for developers to debug their code.  They
 * can use the trace Macro's to write to standar out, to wraparound files and
 * to a wraparound buffer which will be stored in shared memory.
 *
 * There are two types of trace, debug and field, that you can use when tracing.
 * Debug traces will be compiled out of the code when the system is released to the field.
 * Field traces will be remain in the code permenantly.
 *
 * TRACxSYSn calls will always go to syslog
 *
 * There are three different environments trace will operate in.
 *
 * Unit Test / Simulation: All component traces (debug and field) are sent to standard out by default.
 * The developer has the option to do define an evironmental variable:
 * 'export FIPS_TRACE_PATH="<path>"' where path is the location to write the files (ex. "./").
 *
 * Lab: All component traces will, by default, follow the same implementation as the
 * Unit Test / Simulation env.  However, drivers flashed onto the system (built by the
 * build team) will use the memory wrapping implementation.  Code built in a local
 * sandbox will continue to use the file wrapping implementation.  This will give
 * the developer the speed of the memory wrapping trace (for code they don't really
 * care about) and ease of debug with the file wrapping code (for their own code).
 *
 * Field: Only component traces of type field will be sent to the shared memory wraparound
 * buffer.  Debug traces will be compiled out of the code.
 *
 * In Unit Test / Simulation, The file will have the name "trac" + 'component name'.
 * For example the error logger component would be <path>/tracERRL
*/
/* Change Log *****************************************************************/
/*                                                                            */
/* ch#  Feat/def# Userid    Date      Description                             */
/* --- ---------- --------  --------  ----------------------------------------*/
/* 00   N/A       andrewg   08/27/01  Created                                            */
/* 01   N/A       andrewg   10/03/01  Removed duplicate copyright and other housekeeping */
/* 02   N/A       andrewg   10/17/01  Added deallocateBuffer flag to TRAC_FREE_BUFFER    */
/* 03   N/A       andrewg   10/19/01  Added 'using namespace std;', vector.h -> vector   */
/*                                     included iostream.h, printf bug.                  */
/* 04   354052    andrewg   11/09/01  Took out file writing portion, only go to printf   */
/* ag05 354388    andrewg   11/14/01  Changed binary macro name and added typedef        */
/* ag06 354696    andrewg   11/19/01  Removed ag05 change flags, causing errors          */
/* n/a  355095    andrewg   11/28/01  Put common.h include first                         */
/* ag07 354971    andrewg   11/28/01  Added file wrapping code                           */
/* ag08 359225    andrewg   02/11/01  Added memory wrapping code, removed USE_PRINTF defined flag */
/* ag09 360869    andrewg   03/04/02  Added persistant writing macro                     */
/* ag10 361649    andrewg   03/08/02  Added the constants                                */
/* n/a  363697    andrewg   03/28/02  Modified to use new file object                    */
/* n/a  376324    andrewg   07/24/02  Fixed bad define of TRACDCOMP9                     */
/* ag11 382759    andrewg   09/09/02  Support compile flag to remove debug trace         */
/* n/a  385314    andrewg   09/27/02  Remove use of STL                                  */
/* n/a  388981    andrewg   11/12/02  Add new static variable constructor                */
/* n/a  HBIBASE   iawilllia 10/05/10  Removed a lot of stuff for HBI trace base.         */
/* End Change Log *************************************************************/

//--------------------------------------------------------------------//
//  Constants                                                         //
//--------------------------------------------------------------------//
#define ENTER_MRK ">>"  // -- ag10
#define EXIT_MRK  "<<"  // -- ag10
#define ERR_MRK	  "E>"  // -- ag10
#define INFO_MRK  "I>"  // -- ag10
#define ARG_MRK	  "A>"  // -- ag10

#ifndef NFP_CLIENT  // dc99
#include <stdint.h>
#include <trace_adal.h>
#else
typedef int tracDesc_t;
typedef int trace_desc_t;
#endif

#if( defined(NFP_LIBRARY) || defined(NFP_CLIENT) )  // dc99

#define TRACSCOMP(des,printf_string,args...) do {} while(0)
#define TRACDCOMP(des,printf_string,args...) do {} while(0)
#define TRACDBIN(des,descString,address,length) do {} while(0)

#define TRACFCOMP(des,printf_string,args...) \
	printf(printf_string "\n", ##args)
#define TRACFBIN(des,descString,address,length) \
        printf("%s pointer:%p size:%d\n",descString,address,length)

#define TRAC_INIT_BUFFER(des,comp_name, bufferSize) \
        *(des) = 1

#define TRAC_INIT(des,comp_name, bufferSize)

#define TRAC_FREE_BUFFER(des,deallocateBuff) do {} while(0)

#else

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

//------------------------------------------------------------------------------
// INCLUDES
//------------------------------------------------------------------------------

#include <trace_adal.h>

/* for any trace_adal_write_all call we need the printf_string in addition to
 * the hash value. if tracepp is used it will add a (shortened) printf string,
 * otherwise the macros has to add it
 */

#ifdef TRAC_TRACEPP
#define __ALL_HASH(printf_string,num) trace_adal_hash(printf_string,num)
#else
#define __ALL_HASH(printf_string,num) trace_adal_hash(printf_string,num),printf_string
#endif

#ifdef TRAC_DEBUG_OUT /* compile out everyones debug traces */

#define TRACDCOMP(des,printf_string,args...) do {} while(0)
#define TRACDBIN(des,descString,address,length) do {} while(0)

#else /* direct them to real function calls */

/**
 @fn void TRACDCOMP0(des, printf_string)
 @brief Defines all Debug Component Traces

 The user can pass 0 to 9 parameters to the macro.  In the field environment,
 these trace calls will be compiled out of the code.  Use these for early bringup
 needs. These trace calls are written to a memory buffer.
 @note If you are passing parameters then make sure 'printf_string' has the
 @note necessary parameter formatting i.e. 'p1' = "hello" make sure
 @note 'printf_string' has "%s" somewhere in it to corretcly format p1.
 @return void The user will not be impacted by the failure of this function
 @param des This is assigned by TRAC_INIT_BUFFER
 @param printf_string string describing the trace entry and providing the formatting flags for any parameters passed.
 @param p1,p2... Optional parameters
*/

/* a macro w/o the param number suffix. number is calculated from printf string */
#define TRACDCOMP(des,printf_string,args...) \
        trace_adal_write_all((des),__ALL_HASH(printf_string,-1),__LINE__,TRACE_DEBUG, ##args)

/**
 @fn void TRACDBIN(des,descString,address,length)
 @brief Defines debug binary trace

 The binary trace should be used to write out a section of memory.  The debug
 binary trace will be compiled out in the field environment so only use for early
 bringup debug. When this is being written to a file, it will be displayed in
 hexidecimal.
 @return void The user will not be impacted by the failure of this function
 @param des This is assigned by TRAC_INIT_BUFFER
 @param descString A string that will be put in front of the binary dump, developer assigns anything they want.
 @param address Address of beginning of data to dump.
 @param length lenght of the binary data.
*/
#define TRACDBIN(des,descString,address,len) \
        do{ trace_entry_head_t __e; \
            __e.tag    = TRACE_DEBUGBIN; \
            __e.line   = __LINE__; \
            __e.length = (len); \
            __e.hash   = trace_adal_hash(descString, 0); \
            trace_adal_write2((des), TRACE_DEBUG, sizeof(trace_entry_head_t), &__e, \
                             (uint32_t) (__e.length), (uint32_t *) (address)); \
        } while(0)

#endif /* TRAC_DEBUG_OUT */

/**
 @fn void TRACFCOMP0(des, printf_string)
 @brief Defines all Field Component Traces

 The user can pass 0 to 9 parameters to the macro.  These trace calls will
 always be written to the trace memory buffer.
 @note If you are passing parameters then make sure 'printf_string' has the
 @note necessary parameter formatting
 @note i.e. 'p1' = "hello" make sure 'printf_string' has "%s" somewhere in
 @note it to corretcly format p1.
 @return void The user will not be impacted by the failure of this function
 @param des This is assigned by TRAC_INIT_BUFFER
 @param printf_string string describing the trace entry and providing the formatting flags for any parameters passed.
 @param p1,p2... Optional parameters
*/

/* a macro w/o the param number suffix. number is calculated from printf string */
#define TRACFCOMP(des,printf_string,args...) \
        trace_adal_write_all((des),__ALL_HASH(printf_string,-1),__LINE__,TRACE_FIELD, ##args)

/**
 @fn void TRACSCOMP0(des, printf_string)
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
        trace_adal_write_all((des),__ALL_HASH(printf_string,-1),__LINE__,TRACE_DEBUG, ##args)

/**
 @fn void TRACFBIN(des,descString,address,length)
 @brief Defines field binary trace

 The binary trace should be used to write out a section of memory.  The field
 binary trace will always be logged so use for important information.
 When this is being written to a file, it will be displayed in hexidecimal.
 @return void The user will not be impacted by the failure of this function
 @param des This is assigned by TRAC_INIT_BUFFER
 @param descString A string that will be put in front of the binary dump, developer assigns anything they want.
 @param address Address of beginning of data to dump.
 @param length lenght of the binary data.
*/
#define TRACFBIN(des,descString,address,len) \
        do{ trace_entry_head_t __e; \
            __e.tag    = TRACE_FIELDBIN; \
            __e.line   = __LINE__; \
            __e.length = (len); \
            __e.hash   = trace_adal_hash(descString, 0); \
            trace_adal_write2((des), TRACE_FIELD, sizeof(trace_entry_head_t), &__e, \
                             (uint32_t) (__e.length), (uint32_t *) (address)); \
        } while(0)

			
/**
 @fn void TRAC_INIT_BUFFER(des,comp_name, bufferSize)
 @brief Initializes trace buffer for component

 This function must be called before any other trace calls.  It
 initializes a file for the calling component and returns a trace
 descriptor which is used by the trace calls to find the correct file to write to.
 @return void The user will not be impacted by the failure of this function. If des is a positive value, success.
 @param des This is assigned by this function.
 @param comp_name This is the four character name of the component requesting the trace buffer.
 @param bufferSize Requested length of the buffer, if 0 is entered the user will get default buffer size.
*/
#define TRAC_INIT_BUFFER(des,comp_name, bufferSize) \
        trace_adal_init_buffer((des), (comp_name), (bufferSize))


class TracInit
{
  public:

    /*------------------------------------------------------------------------*/
    /* Constructor                                                            */
    /*------------------------------------------------------------------------*/

    TracInit(tracDesc_t *o_td, const char *i_comp,const size_t i_size)
    {
        // printf("TracInit constructor called for %s, size %u\n",i_comp,i_size);
        TRAC_INIT_BUFFER(o_td,i_comp,i_size);
    }

    ~TracInit()
    {
        // printf("in the TracInit destructor\n");
    }

};

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

#define TRAC_INIT_UNIQ(des, name, sz, ln) TracInit static g_trac_##ln(des, name, sz)
#define TRAC_INIT_LINE(des, name, sz, ln) TRAC_INIT_UNIQ(des, name, sz, ln)
#define TRAC_INIT(des, name, sz)	 TRAC_INIT_LINE(des, name, sz, __LINE__)

#endif  //! -- NFP Library
#endif //! -- !defined TRACINTERFACE_H
