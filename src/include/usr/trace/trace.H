/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/trace/trace.H $                               */
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
/**
 *  @file trace.H
 *
 *  Internal trace definitions and functions.  External users should
 *  not directly include or use this file.  trace/interface.H is the external
 *  file.
*/

#ifndef __TRACE_TRACE_H
#define __TRACE_TRACE_H

#include <stdint.h>
#include <trace/interface.H>

const uint32_t TRACE_DEBUG_ON    = 1;       //< Set to this when debug trace on
const uint32_t TRACE_DEBUG_OFF   = 0;       //< Set to this when debug trace off

const uint32_t TRAC_COMP_SIZE    = 16;      //< Max component name size
const uint32_t TRAC_MAX_ARGS     = 9;       //< Max number of arguments in trace

typedef uint32_t trace_hash_val;    //< Hash values are 32 bits.


extern  "C" {

/**
 *  @brief  dummy function to satisfy BEAM.
 *  C files are normally pre(pre)processed by the "tracepp" script,
 *  which translates this function call to a call to a unique hash function.
 *  When BEAM is run on the un-preprocessed files, it outputs lots
 *  of parser errors because it cannot find this function.
 *  This must be extern "C", otherwise BEAM cannot find it.
 */
trace_hash_val  trace_adal_hash( ... ) ;
}   //  end extern "C"


namespace TRACE
{
    class ComponentDesc; // Forward declaration.

    struct traceCodeInfo
    {
        const char* format;
        trace_hash_val hash;
    } __attribute__((packed));

    struct traceParseInfo
    {
        uint16_t len_string;
        uint16_t len_file;
        uint32_t __padding;
        const char string[512];
        const char file[256];
        traceCodeInfo* code;
    };

    /** @brief Buffer type that a component is directed to. */
    enum BUFFER_TYPES
    {
        BUFFER_SLOW,    //< Traces are part of an infinite non-blocking buffer.
        BUFFER_FAST,    //< Traces are part of a smaller blocking buffer.
        BUFFER_COUNT    //< Number of trace buffers supported.
    };

    /**
     *  @brief  Initialize a trace buffer.
     *
     *  Size is capped at 2KB. You can request larger, but
     *  the code in src/usr/trace/trace.C imposes
     *  a maximum size of 2KB. Sizes smaller than 2KB
     *  will save space.
     *
     *  @param [out] o_td Trace descriptor to initialize
     *  @param [in] i_comp Component name for trace buffer
     *  @param [in] i_size Size to allocate for trace buffer
     *  @param [in] i_bufferType Type of buffer.
     *
     *  @return void
     */
    void initBuffer(ComponentDesc **o_td,
                    const char* i_comp,
                    size_t i_size,
                    uint8_t i_bufferType = BUFFER_FAST);

    /**
     *  @brief  Write component trace out to input buffer
     *
     *  Note that to continue to support tracepp, we must keep the
     *  name of this function as is.
     *
     *  @param [in,out] io_td Trace descriptor of buffer to write to.
     *  @param [in] i_info Info struct for the hash and format string.
     *  @param [in] i_line Line number trace was done at
     *  @param [in] i_type Type of trace (TRACE_DEBUG, TRACE_FIELD)
     *
     *  @return void
     */
    void trace_adal_write_all(ComponentDesc *io_td,
                              const traceCodeInfo* i_info,
                              const uint32_t i_line,
                              const uint32_t i_type, ...);

    /**
     *  @brief  Write binary data out to trace buffer
     *
     *  Note that to continue to support tracepp, we must keep the
     *  name of this function as is.
     *
     *  @param [in,out] io_td Trace descriptor of buffer to write to.
     *  @param [in] i_info Info struct for the hash and format string.
     *  @param [in] i_line Line number trace was done at
     *  @param [in] i_ptr Pointer to binary data
     *  @param [in] i_size Size of binary data
     *  @param [in] i_type Type of trace (TRACE_DEBUG, TRACE_FIELD)
     *
     *  @return void
     */
    void trace_adal_write_bin(ComponentDesc * io_td,
                              const traceCodeInfo* i_info,
                              const uint32_t i_line,
                              const void *i_ptr,
                              const uint32_t i_size,
                              const uint32_t i_type);

    /**
     *  @brief  Retrieve the trace buffer named by i_pName
     *
     *  Caller must allocate memory for the output buffer.  Caller may
     *  first query the size of the buffer by calling with the desired
     *  buffer name and with o_data null and i_bufferSize
     *  zero. The value returned will be the full buffer size.  Caller
     *  allocates the buffer and calls again.
     *
     *  The buffer provided can be less than the full size of the desired
     *  buffer. In that case, this function will copy as many of the most
     *  recent traces into the output buffer as will fit. The buffer must
     *  be big enough to hold a trace buffer header (40 bytes).
     *
     *  i_bufferSize may be larger that the desired trace buffer.
     *
     *  @param [in]  i_pName      name of trace buffer
     *  @param [out] o_data       pointer to output buffer
     *  @param [in]  i_bufferSize size of output buffer in bytes
     *
     *  @return Count of bytes copied, or if given null parameters,
     *  the size of the buffer. Returns zero for error, perhaps the
     *  component name/trace buffer name is not found, or perhaps
     *  the size of the provided buffer is unreasonable.
     */
    size_t getBuffer( const char * i_pName,
                      void *       o_data,
                      size_t     i_bufferSize );

    /**
     *  @brief  flush Continuous trace buffers
     */
    void flushBuffers();


};

typedef TRACE::ComponentDesc trace_desc_t;

#endif
