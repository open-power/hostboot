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

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
#define ENTER_MRK ">>"
#define EXIT_MRK  "<<"
#define ERR_MRK	  "E>"
#define INFO_MRK  "I>"
#define ARG_MRK	  "A>"

#define TRAC_COMP_SIZE      16      // Max component name size
#define TRAC_MAX_ARGS       9       // Max number of arguments in trace


#define TRACE_DEBUG         1       //Indicates trace is debug
#define TRACE_FIELD         0       //Indicates trace is field

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

#else /* direct them to real function calls */

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
        TRACE::trace_adal_write_all((des),__ALL_HASH(printf_string,-1),__LINE__,TRACE_DEBUG, ##args)

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
        TRACE::trace_adal_write_bin(des,__ALL_HASH(printf_string,0),      \
                             __LINE__,                             \
                             address,                              \
                             len,                                  \
                             TRACE_DEBUG)
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
        TRACE::trace_adal_write_all((des),__ALL_HASH(printf_string,-1),__LINE__,TRACE_FIELD, ##args)


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
        TRACE::trace_adal_write_bin(des,__ALL_HASH(printf_string,0),      \
                             __LINE__,                             \
                             address,                              \
                             len,                                  \
                             TRACE_FIELD)
			
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
        TRACE::trace_adal_init_buffer((des), (comp_name), (bufferSize))

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


/******************************************************************************/
// Internals - Not to be called or used directly by host boot code
/******************************************************************************/


typedef uint32_t trace_hash_val;    // Hash values are 32 bytes

/*
 * @brief Structure is put at beginning of all trace buffers
 */
typedef struct trace_buf_head {
    unsigned char ver;          /*!< version of this struct (1)               */
    unsigned char hdr_len;      /*!< size of this struct in bytes             */
    unsigned char time_flg;     /*!< meaning of timestamp entry field         */
    unsigned char endian_flg;   /*!< flag for big ('B') or little ('L') endian*/
    char comp[TRAC_COMP_SIZE];  /*!< the buffer name as specified in init call*/
    uint32_t size;              /*!< size of buffer, including this struct    */
    uint32_t times_wrap;        /*!< how often the buffer wrapped             */
    uint32_t next_free;         /*!< offset of the byte behind the latest entry*/
    uint32_t te_count;          /*!< Updated each time a trace is done        */
    uint32_t extracted;         /*!< Not currently used                       */
}trace_buf_head_t;

/*!
 * @brief Timestamp and thread id for each trace entry.
 */
typedef struct trace_entry_stamp {
    //uint32_t tbh;        /*!< timestamp upper part                            */
    //uint32_t tbl;        /*!< timestamp lower part                            */
    uint32_t tb[2];
    //uint64_t tb;
    uint32_t tid;        /*!< process/thread id                               */
}trace_entry_stamp_t;

/*
 * @brief Structure is used by adal app. layer to fill in trace info.
 */
typedef struct trace_entry_head {
    uint16_t length;    /*!< size of trace entry                              */
    uint16_t tag;       /*!< type of entry: xTRACE xDUMP, (un)packed          */
    uint32_t hash;      /*!< a value for the (format) string                  */
    uint32_t line;      /*!< source file line number of trace call            */
}trace_entry_head_t;

/*
 * @brief Parameter traces can be all contained in one write.
 */
typedef struct trace_entire_entry {
    trace_entry_stamp_t stamp;
    trace_entry_head_t head;
    uint64_t args[TRAC_MAX_ARGS + 1];
} trace_entire_entry_t;


/*
 * @brief Binary first writes header and time stamp.
 */
typedef struct trace_bin_entry {
    trace_entry_stamp_t stamp;
    trace_entry_head_t head;
} trace_bin_entry_t;

/**
 * @brief New version name of this typedef
 */
typedef trace_buf_head_t trace_desc_t;

namespace TRACE
{

/**
 *  @brief  Initialize a trace buffer
 *
 *  @param o_td[out] Trace descriptor to initialize
 *  @param i_comp[in] Component name for trace buffer
 *  @param i_size[in] Size to allocate for trace buffer
 *
 *  @return void
 */
void trace_adal_init_buffer(trace_desc_t **o_td,
                            const char* i_comp,
                            const size_t i_size );

/**
 *  @brief  Write component trace out to input buffer
 *
 *  @param io_td[inout] Trace descriptor of buffer to write to.
 *  @param i_hash[in] Descriptive string hash value
 *  @param i_fmt [in] Formatting string
 *  @param i_line[in] Line number trace was done at
 *  @param i_type[in] Type of trace (TRACE_DEBUG, TRACE_FIELD)
 *
 *  @return void
 */
void trace_adal_write_all(trace_desc_t *io_td,
                          const trace_hash_val i_hash,
                          const char * i_fmt,
                          const uint32_t i_line,
                          const int32_t i_type, ...);

/**
 *  @brief  Write binary data out to trace buffer
 *
 *  @param io_td[inout] Trace descriptor of buffer to write to.
 *  @param i_hash[in] Descriptive string hash value
 *  @param i_line[in] Line number trace was done at
 *  @param i_ptr[in] Pointer to binary data
 *  @param i_size[in] Size of binary data
 *  @param i_type[in] Type of trace (TRACE_DEBUG, TRACE_FIELD)
 *
 *  @return void
 */
void trace_adal_write_bin(trace_desc_t * io_td,
                            const trace_hash_val i_hash,
                            const uint32_t i_line,
                            const void *i_ptr,
                            const uint32_t i_size,
                            const int32_t type);


/******************************************************************************/
// Allow users to init trace buffer outside of a function
/******************************************************************************/
class TracInit
{
  public:

    /*------------------------------------------------------------------------*/
    /* Constructor                                                            */
    /*------------------------------------------------------------------------*/

    TracInit(trace_desc_t **o_td, const char *i_comp,const size_t i_size)
    {
        TRAC_INIT_BUFFER(o_td,i_comp,i_size);
    }

    ~TracInit()
    {
    }

};

}; // Namespace

#endif //! -- !defined __TRACE_INTERFACE_H
