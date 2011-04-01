/******************************************************************************
 * IBM Confidential
 *
 * Licensed Internal Code Source Materials
 *
 * IBM Flexible Support Processor Licensed Internal Code
 *
 * (c) Copyright IBM Corp. 2004, 2009
 *
 * The source code is for this program is not published or otherwise divested
 * of its trade secrets, irrespective of what has been deposited with the
 * U.S. Copyright Office.
 *****************************************************************************
 * \file trace_adal.h
 * \brief Contains header data for trace component..
 *
 *  The trace component allows an application to trace its execution into
 *  circular buffers (like a flight recorder) with low performance and
 *  memory usage impact.  This implementation focuses on the Linux operating
 *  system running on embedded controllers.
 *
 * \note Please see the document trace_doc.lyx for full documentation on this
 * \note component.
 *****************************************************************************/


#ifndef _TRACE_ADAL_H
#define _TRACE_ADAL_H

#include <stdint.h>

/**
 * @brief Maximum size of component name
 * @note Make sure to also change in include/linux/trac.h -
 *   TRACER_FSP_TRACE_NAME_SIZE
*/
#define TRACE_MAX_COMP_NAME_SIZE 16

#define TRACE_DEBUG_ON  1		//Set to this when debug trace on
#define TRACE_DEBUG_OFF  0		//Set to this when debug trace off
#define TRACE_DEBUG  1			//Pass this when trace is debug
#define TRACE_FIELD 0			//Pass this when trace is field

#define TRACE_COMP_TRACE	0x434F		//Identifies trace as a component trace (printf)
#define TRACE_BINARY_TRACE	0x4249		//Identifies trace as a binary trace
#define TRACE_INTERNAL_BLOCKED	0xFF42		//Identifies trace as an dd internal trace

#define TRACE_BUFFER_VERSION		1	//Trace buffer version
#define TRACE_BUFFER_BINARY_VERSION	2	//Trace buffer version when collected by fsp-trace from pipe

#define TRACE_DEFAULT_TD  0		//Default trace descriptor


/*
 * Parsing and output modifier flags
 */

/* 		When multiple buffers are given the traces of all buffers are sorted by timestamp and printed as one list. 
 * 		If this flag is not given the traces are printed separatly for each trace buffers (i.e. grouped by buffer). 
 */
#define TRACE_MIX_BUFFERS		1

/*		Show the name of a trace buffer for each trace. The buffer name will be inserted between timestamp and trace text. 
 *		Only one of TRACE_APPEND_BUFFERNAME and TRACE_PREPEND_BUFFERNAME can be given.
 */
#define TRACE_PREPEND_BUFFERNAME	2

/*		Show the name of a trace buffer for each trace. The buffer name will be appended at the end of the line
 *		(after	trace	text).	Only one of TRACE_APPEND_BUFFERNAME and TRACE_PREPEND_BUFFERNAME can be given.
 */
#define TRACE_APPEND_BUFFERNAME		4

/*		When set timestamps are translated to timeofday values (date/time). This needs "timeref" to be given. 
 *		If timeref is not given the timestamps are treated as if the PPC timebase counter was started at epoch time
 *		(i.e. the printed timestamp will be the time since FSP boot time).
 */
#define TRACE_TIMEOFDAY			8

/*		If a TIMEREF trace is found in a trace buffer and timeref is a valid
 *		pointer the values from the TIMEREF trace are written to timeref. This flag is independent of TRACE_TIMEOFDAY.
 */
#define TRACE_SET_TIMEOFDAY		16

/*		Show the name of the source file that contains the trace statement for each trace.
 *		(at the end of the line, after buffer name if this is printed too).
 */
#define TRACE_FILENAME			32
#define TRACE_VERBOSE			64	//some messages are printed to STDERR.
#define TRACE_IGNORE_VERSION		128
#define TRACE_OVERWRITE			256
#define TRACE_BINARY			512

/*		When this is set trace pipe isn't turned off after pipe read
 */
#define TRACE_DONTSTOP			1024


/* MSB of tid field is used as trace-in-irq flag
 */
#define TRACE_TID_IRQ			(1<<31)
#define TRACE_TID_TID(tid)		((tid) & ~(TRACE_TID_IRQ))

/*!
 * @brief Device driver fills in this structure for each trace entry.
 * It will put this data first in the trace buffer.
 */
typedef struct trace_entry_stamp {
    uint32_t tbh;        /*!< timestamp upper part                            */
    uint32_t tbl;        /*!< timestamp lower part                            */
    uint32_t tid;        /*!< process/thread id                               */
} trace_entry_stamp_t;


/*
 * @brief Structure is used by adal app. layer to fill in trace info.
 */
typedef struct trace_entry_head {
    uint16_t length;     /*!< size of trace entry                             */
    uint16_t tag;        /*!< type of entry: xTRACE xDUMP, (un)packed         */
    uint32_t hash;       /*!< a value for the (format) string                 */
    uint32_t line;       /*!< source file line number of trace call           */
    uint32_t args[0];    /*!< trace args or data of binary trace              */
} trace_entry_head_t;


/*
 * @brief Structure is used to return current components tracing
 */
typedef struct trace_buf_list {
    char name[TRACE_MAX_COMP_NAME_SIZE]; /*!< component name                  */
    size_t size;                         /*!< size of component trace buffer  */
} trace_buf_list_t;


typedef uint64_t trace_desc_t;	//Type definition for users trace descriptor data type
typedef uint64_t tracDesc_t;		//Type definition for older trace descriptor type
typedef unsigned long trace_strings_t;	/* type for trace strings */


/*
 * @brief Will use this to hold hash value.
 *
 */
enum trace_hash_val	{ trace_hash };

/* struct for time */
struct trace_tbtime {
	uint32_t high;
	uint32_t low;
};


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
/* only define if not defined by trace_dd.h (make different versions of
 * these files compatible). check only for one define instead of all */
#ifndef TRACE_FIELDTRACE

/* a component trace of type field (non-debug): x4654 = "FT" */
#define TRACE_FIELDTRACE 0x4654
/* a component trace of type debug: x4454 = "DT" */
#define TRACE_DEBUGTRACE 0x4454
/* a binary trace of type field (non-debug): x4644 = "FD" */
#define TRACE_FIELDBIN 0x4644
/* a binary trace of type debug: x4644 = "DD" */
#define TRACE_DEBUGBIN 0x4444
/* a string trace of type field (non-debug): x4653 = "FS" */
#define TRACE_FIELDSTRING 0x4653
/* a string trace of type debug: x4453 = "DS" */
#define TRACE_DEBUGSTRING 0x4453

#endif

/*----------------------------------------------------------------------------*/
/* Function Prototypes                                                        */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Initialize a trace buffer for a component.
 *
 * @param td Device driver will assign caller a trace descriptor.
 * @param comp Pointer to 16 character null terminated string.
 * @param size Requested buffer size.
 *
 * @return 0 for success, negative value for failure.
 * @retval #TRACE_INIT_BUFF_IOCTL_ERR device driver refused to create buffer
 * @retval #TRACE_INIT_BUFF_NAME_ERR buffer name was too long, a buffer with the
           name "BADN" was created instead
 * @retval #TRACE_INIT_FD_ERR cannot open trace device (module not loaded?), errno set
 */
int32_t trace_adal_init_buffer(trace_desc_t *,const char *,const size_t);

/*!
 * @brief Set trace debug level
 *
 * @param td Assigned trace descriptor.
 * @param level If 0 only field traces will be active. If > 0 debug traces
 *              with level <= 'level' will be active.
 *
 * @return 0 for success, negative value for failure.
 * @retval #TRACE_SETDEBUG_IOCTL_ERR error from device driver, errno set
 * @retval #TRACE_SETDEBUG_INV_PARM_ERR second parm must be TRACE_DEBUG_ON or TRACE_DEBUG_OFF
 * @retval #TRACE_INIT_FD_ERR cannot open trace device (module not loaded?), errno set
 */
int32_t trace_adal_setdebug(const trace_desc_t, const int32_t);

/*!
 * @brief Write some data to trace buffer.
 *
 * @param td Assigned trace descriptor.
 * @param debug Is it a debug trace or field.
 * @param size Size of data.
 * @param data Data to write to buffer.
 * @param size2 Size of second data block.
 * @param data2 Second data block to write to buffer.
 *
 * @return 0 for success, negative value for failure.
 * @retval #TRACE_WRITE_IOCTL_ERR error from device driver, errno set
 * @retval #TRACE_INIT_FD_ERR cannot open trace device (module not loaded?), errno set
 */
int32_t trace_adal_write2(const trace_desc_t, const int32_t,
                         const size_t,const void *,const size_t,const void *);

/*!
 * @brief Write trace data (can handle all data types)
 *
 * @return 0 for success, negative value for failure.
 * @retval #TRACE_WRITE_ALL_IOCTL_ERR error from device driver, errno set
 * @retval #TRACE_WRITE_NOT_INIT trying to trace without device driver
 * @retval #TRACE_THREAD_LOCK_FAIL error locking thread lock
 * @retval #TRACE_THREAD_UNLOCK_FAIL error unlocking thread lock
 * @retval #TRACE_INIT_FD_ERR cannot open trace device (module not loaded?), errno set
 * @retval #TRACE_WRITE_ALL_BAD_TD bad trace descriptor
 */
int32_t trace_adal_write_all(const trace_desc_t i_td,const enum trace_hash_val i_hash,
                             const char *i_fmt,
                             const uint32_t i_line, const int32_t i_type,...)
        __attribute__ ((format (printf, 3, 6)));

#ifdef __cplusplus
}
#endif

#endif
