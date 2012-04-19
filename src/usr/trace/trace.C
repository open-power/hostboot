//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/trace/trace.C $
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

/**
 *  @file trace.C
 *
 *  @brief Implementation of class Trace
 */


/* TODO
 *  - Add support in for debug trace enable/disable
 *  - FORMAT_PRINTF support
 *  - %s support
 *  - Multiple buffer support
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <trace/interface.H>
#include <stdarg.h>
#include <stdlib.h>
#include <arch/ppc.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <limits.h>
#include <stdlib.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string_ext.h>
#include <util/align.H>
#include <assert.h>

#include <trace/trace.H>
#include "tracedaemon.H"


/******************************************************************************/
// Namespace
/******************************************************************************/
namespace TRACE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

const uint32_t TRAC_TIME_REAL   = 0;  // upper 32 = secs, lower 32 = microsecs
const uint32_t TRAC_TIME_50MHZ  = 1;
const uint32_t TRAC_TIME_200MHZ = 2;
const uint32_t TRAC_TIME_167MHZ = 3;  // 166666667Hz




// WARNING: Changing the size of the trace buffer name string requires a
// changing OFFSET_BUFFER_ADDRESS in src/build/debug/Hostboot/Trace.pm.
const uint32_t COMP_NAME_SIZE   = 16; // includes NULL terminator, so 15 max


// Settings for the default buffer.  Name must be upper case.
const char * const TRAC_DEFAULT_BUFFER_NAME = "DEFAULT";
const uint64_t     TRAC_DEFAULT_BUFFER_SIZE = 0x0800;  //2KB


// The number of trace buffers.
// NOTE: This constant should only be changed to an even number for now.
// WARNING: Changing the count of buffers requires a co-req change
// in src/build/debug/Hostboot/Trace.pm  which has this count hard coded.
const uint64_t TRAC_MAX_NUM_BUFFERS = 48;

// An array of these structs accounts for all the trace buffers in Hostboot.
// WARNING: Changing the size of trace_desc_array requires a co-req change
// in src/build/debug/Hostboot/Trace.pm  which has hard-coded the size of
// this structure.
typedef struct trace_desc_array
{
    char comp[COMP_NAME_SIZE];        // the buffer name
    trace_desc_t * td_entry;          // pointer to the buffer
}trace_desc_array_t;

// Global: found in syms file and thus the dump.
trace_desc_array_t g_desc_array[TRAC_MAX_NUM_BUFFERS];


// Set up a structure to hold information about the mixed-trace
// or continuous-trace buffer, aka tracBINARY.

// WARNING: Changes to this structure will require co-req changes to
// src/build/debug/simics-debug-framework.py which contains the simics
// hap handler for extracting this buffer.
struct mixed_trace_info
{
    char *     pBuffer;
    uint64_t   cbUsed;
    uint32_t   TriggerActive;
    uint32_t   LostTraceCount;
};
typedef struct mixed_trace_info mixed_trace_info_t;
const uint64_t TRAC_BINARY_SIZE = 4096;
mixed_trace_info_t g_tracBinaryInfo[2];

struct vpo_con_trigger_t
{
    volatile uint64_t trig;  // bit0 = trig signalling bit1:63 = trace buff addr
    uint32_t len;   // length of trace buffer with valid trace data.
    uint32_t seq;
};

struct vpo_cont_support_t
{
    vpo_con_trigger_t triggers[2];
    uint64_t enable;   // VPO script sets it to 2
                       // SIMICS hap handler sets it to 0
                       // Compiler sets it to 1 for Mbox
};

// This structure is monitored by VPO script. The enable variable is set
// at compile time to 1. The VPO script set the enable variable at the
// start to enable the continuous trace support for VPO. It then montiors the
// trigger active bit of each buffer and take action.
vpo_cont_support_t g_cont_trace_trigger_info = { { {0,0,0}, {0,0,0} }, 1 };

const uint64_t TRIGGER_ACTIVE_BIT = 0x8000000000000000;

/******************************************************************************/
// TracInit::TracInit()
/******************************************************************************/
TracInit::TracInit(trace_desc_t **o_td, const char *i_comp,const size_t i_size)
{
    TRAC_INIT_BUFFER(o_td,i_comp,i_size);
}

/******************************************************************************/
// TracInit::~TracInit()
/******************************************************************************/
TracInit::~TracInit()
{
}


/******************************************************************************/
// Trace::getTheInstance
/******************************************************************************/
Trace& Trace::getTheInstance()
{
    return Singleton<Trace>::instance();
}

/******************************************************************************/
// Trace::Trace
/******************************************************************************/
Trace::Trace()
{
    mutex_init(&iv_trac_mutex);

    // compiler inits global vars to zero
    // memset(g_desc_array, 0, sizeof(g_desc_array));

    // fsp-trace convention expects a 2 in the first byte of tracBINARY
    for (size_t i = 0; i < 2; i++)
    {
        g_tracBinaryInfo[i].pBuffer =
                                 static_cast<char*>(malloc(TRAC_BINARY_SIZE));
        g_tracBinaryInfo[i].pBuffer[0]     = 2;
        g_tracBinaryInfo[i].cbUsed         = 1;
        g_tracBinaryInfo[i].TriggerActive  = 0;
        g_tracBinaryInfo[i].LostTraceCount = 0;
        g_cont_trace_trigger_info.triggers[i].trig =
                      reinterpret_cast<uint64_t>(g_tracBinaryInfo[i].pBuffer);
    }

    // if this code is running under simics, call the hap handler to set
    // g_cont_trace_trigger_info.enable to 0. Otherwise, this will be noop
    MAGIC_INSTRUCTION(MAGIC_CONTINUOUS_TRACE);

    // tracBINARY buffer appending is always on.
    // TODO figure a way to control continuous trace on/off, perhaps
    // unregister the hap handler for it.
    iv_ContinuousTrace = 1;

    // select buffer0 initially
    iv_CurBuf = 0;
    // initialize seq number
    iv_seqNum = 0;

    // Create the daemon.
    iv_daemon = new TraceDaemon();
}

/******************************************************************************/
// Trace::~Trace
/******************************************************************************/
Trace::~Trace()
{
    // Delete the daemon.
    delete iv_daemon;
}


/******************************************************************************/
// trace_adal_init_buffer
/******************************************************************************/
void Trace::initBuffer( trace_desc_t **o_td,
                        const char* i_comp,
                        size_t i_size )
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    unsigned int i = 0;
    char l_comp[COMP_NAME_SIZE] = {'\0'};

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/


    // Limit buffer sizes to 2KB
    if( i_size > TRAC_DEFAULT_BUFFER_SIZE )
    {
        i_size = TRAC_DEFAULT_BUFFER_SIZE;
    }

    // Limit component name to 15 characters.
    if (strlen(i_comp) > (COMP_NAME_SIZE -1))
    {
        memcpy(l_comp, i_comp, COMP_NAME_SIZE - 1);
    }
    else
    {
        strcpy(l_comp, i_comp);
    }

    // Store buffer name internally in upper case
    strupr(l_comp);

    // The page containing the trace-descriptor destination might not be
    // loaded yet, so we write to it outside of the mutex to force a page
    // fault to bring the page in.  If we don't do this, we can end up with
    // a dead-lock where this code is blocked due to a page-fault while
    // holding the trace mutex, which in turn blocks the code that handles
    // page faults.
    *o_td = NULL;

    // CRITICAL REGION START
    mutex_lock(&iv_trac_mutex);

    // Search through the descriptor array for the first unallocated buffer.
    // The last buffer is the reserved default buffer for any component
    // which didn't get its own buffer.
    for (i = 0; i < (TRAC_MAX_NUM_BUFFERS - 1); i++)
    {
        if( 0 == strcmp(l_comp, g_desc_array[i].comp))
        {
            // Buffer is already allocated for the given buffer name.
            // Return the pointer to the buffer.
            *o_td = g_desc_array[i].td_entry;
            break;
        }
        else if ( '\0' == g_desc_array[i].comp[0] )
        {
            // Found an unallocated buffer; use this one.
            // Set the component name for the buffer
            strcpy(g_desc_array[i].comp, l_comp);

            // Allocate memory for the trace buffer.
            *o_td = g_desc_array[i].td_entry =
                reinterpret_cast<trace_desc_t *>(malloc(i_size));

            // Initialize the trace buffer.
            initValuesBuffer( g_desc_array[i].td_entry,
                              g_desc_array[i].comp,
                              i_size );

            break;
        }
    }


    if ((TRAC_MAX_NUM_BUFFERS - 1) == i)
    {
        // We're out of buffers to allocate.
        // Use the default buffer reserved for everyone else.
        // Initialize only once
        if ( '\0' == g_desc_array[i].comp[0] )
        {
            // Set the component name for the buffer
            strcpy(g_desc_array[i].comp, TRAC_DEFAULT_BUFFER_NAME);

            // Allocate memory for buffer
            g_desc_array[i].td_entry =
                reinterpret_cast<trace_desc_t *>(malloc(TRAC_DEFAULT_BUFFER_SIZE));

            // Initialize the buffer header
            initValuesBuffer(g_desc_array[i].td_entry,
                             g_desc_array[i].comp,
                             TRAC_DEFAULT_BUFFER_SIZE);
        }

        // Return the default buffer
        *o_td = g_desc_array[i].td_entry;
    }

    mutex_unlock(&iv_trac_mutex);
    // CRITICAL REGION END

    return;
}

/******************************************************************************/
// initValuesBuffer
/******************************************************************************/
void Trace::initValuesBuffer( trace_desc_t *o_buf,
                              const char *i_comp,
                              size_t i_size )
{
    // Initialize it to all 0's
    memset(o_buf,0,i_size);

    o_buf->ver = TRACE_BUF_VERSION;
    o_buf->hdr_len = sizeof(trace_buf_head_t);
    o_buf->time_flg = TRAC_TIME_REAL;
    o_buf->endian_flg = 'B';  // Big Endian
    strcpy(o_buf->comp,i_comp);
    o_buf->size = i_size;
    o_buf->times_wrap = 0;
    o_buf->next_free = sizeof(trace_buf_head_t);

    return;
}

/******************************************************************************/
// ManageContTraceBuffers
// This function manages the usage of the two ping-pong buffers for handling
// the continuous trace support.
//
// 1) Under VPO/VBU (g_cont_trace_trigger_info.enable = 2)
//    The handshake between Hostboot code and VPO/VBU script is shown belows
//                        _______________________
//    Trigger_Avtive ____/                       \__________
//                           _________________________
//    ScomReg_Active _______/                         \______
//
//    Hostboot code (this function) sets Trigger_Active, then ScomReg_Active,
//    VPO/VBU script detects ScomReg_Active active, off-load the trigger buffer,
//    and clears Trigger_Active. Hostboot code detects a trigger-state buffer
//    with Trigger_Active cleared, reset ScomReg_Active. Two-level trigger is
//    desired. The ScomReg trigger allows VPO script to sample at no expense
//    of simclocks, thus avoiding spending extra simclocks associated with the
//    flushing of L2/L3 to read the memory trigger.
//
// 2) Under Simics with hap handler (g_cont_trace_trigger_info.enable = 0)
//    The handshake between Hostboot code and the hap handler is shown belows
//                        _______________________
//    Trigger_Avtive ____/                       \__________
//
//    Hostboot code (this function) sets Trigger_Active, then invokes the hap
//    handler. The hap handler off-loads the trigger buffer, and clears the
//    Trigger_Active.
//
// 3) Under Simics/HW with FSP mbox (g_cont_trace_trigger_info.enable = 1)
//                        _______________________
//    Trigger_Avtive ____/                       \__________
//
//    Hostboot code (this function) sets Trigger_Active, then schedule a thread
//    to use mbox DMA MSG to off-load the trigger buffer to FSP, and clears the
//    Trigger_Active.
//
/******************************************************************************/
void Trace::ManageContTraceBuffers(uint64_t i_cbRequired)
{
    uint8_t l_AltBuf = (iv_CurBuf + 1) % 2;
    bool needScomReset = false;

    // Reset TriggerActive if the buffer has been offloaded by VPO
    // script when running under VBU Awan environment
    for (size_t i = 0; (g_cont_trace_trigger_info.enable > 1) && (i < 2); i++)
    {
        if ((g_tracBinaryInfo[i].TriggerActive != 0) &&
             (!(g_cont_trace_trigger_info.triggers[i].trig &
                                                         TRIGGER_ACTIVE_BIT)))
        {
            g_tracBinaryInfo[i].TriggerActive = 0;
            needScomReset = true;
        }
    }

    if (needScomReset)
    {
        msg_t* l_msg = msg_allocate();
        l_msg->type = TraceDaemon::UPDATE_SCRATCH_REG;
        l_msg->data[0] = 0;
        msg_send(iv_daemon->iv_msgQ, l_msg);
    }

    // we should never have the current buffer in the trigger state
    assert (g_tracBinaryInfo[iv_CurBuf].TriggerActive == 0);

    // current buffer is not in trigger state
    // and adding this trace will exceed the size
    if ((g_tracBinaryInfo[iv_CurBuf].cbUsed + i_cbRequired)
                                                          > TRAC_BINARY_SIZE)
    {
        // current buffer entering trigger state
        g_tracBinaryInfo[iv_CurBuf].TriggerActive = 1;

        if (g_cont_trace_trigger_info.enable > 1)
        {
            if (g_tracBinaryInfo[l_AltBuf].TriggerActive == 1)
            {
                // If the alternate buffer's trigger is active, wait for a
                // chance to get offloaded before it is reused.
                uint64_t l_wait = 0x100000;
                while (g_cont_trace_trigger_info.triggers[l_AltBuf].trig &
                             TRIGGER_ACTIVE_BIT)
                {
                    if (--l_wait == 0)
                    {
                        break;
                    }
                }
                // If alternate buffer has been offloaded, exit trigger state.
                if (l_wait != 0)
                {
                    g_tracBinaryInfo[l_AltBuf].TriggerActive = 0;
                }
            }

            g_cont_trace_trigger_info.triggers[iv_CurBuf].seq = iv_seqNum++;
            // Turn on the current buffer's trigger
            g_cont_trace_trigger_info.triggers[iv_CurBuf].trig |=
                                                           TRIGGER_ACTIVE_BIT;

            msg_t* l_msg = msg_allocate();
            l_msg->type = TraceDaemon::UPDATE_SCRATCH_REG;
            l_msg->data[0] = 0x13579BDF00000000;
            l_msg->data[0] += (iv_seqNum * 0x100000000);
            msg_send(iv_daemon->iv_msgQ, l_msg);
        }

        // If the alternate buffer is in trigger state, move it out of
        // the trigger state and keep track of lost trace count.
        if (g_tracBinaryInfo[l_AltBuf].TriggerActive == 1)
        {
            g_tracBinaryInfo[l_AltBuf].LostTraceCount++;
            g_tracBinaryInfo[l_AltBuf].TriggerActive = 0;
        }
        // Now switching to alternate buffer and reset the usage count
        uint8_t l_cur = iv_CurBuf;
        uint64_t l_len = g_tracBinaryInfo[l_cur].cbUsed;
        iv_CurBuf = l_AltBuf;
        g_tracBinaryInfo[iv_CurBuf].cbUsed = 1;

        // For FSP mbox method.
        if (g_cont_trace_trigger_info.enable == 1)
        {
            msg_t* l_msg = msg_allocate();
            l_msg->type = TraceDaemon::SEND_TRACE_BUFFER;
            l_msg->data[1] = TRAC_BINARY_SIZE;
            l_msg->extra_data = malloc(TRAC_BINARY_SIZE);
            memcpy( l_msg->extra_data, g_tracBinaryInfo[l_cur].pBuffer, l_len );
            msg_send(iv_daemon->iv_msgQ, l_msg);
            g_tracBinaryInfo[l_cur].TriggerActive = 0;
        }

        MAGIC_INSTRUCTION(MAGIC_CONTINUOUS_TRACE);
    }
}


/******************************************************************************/
// trace_adal_write_all
/******************************************************************************/
void Trace::trace_adal_write_all(trace_desc_t *io_td,
                                 const trace_hash_val i_hash,
                                 const char * i_fmt,
                                 const uint32_t i_line,
                                 const int32_t i_type, ...)
{
    va_list args;
    va_start(args, i_type);

    getTheInstance()._trace_adal_write_all(io_td,
                                           i_hash,
                                           i_fmt,
                                           i_line,
                                           i_type, args);

    va_end(args);
}

/******************************************************************************/
// trace_adal_write_all
/******************************************************************************/
void Trace::_trace_adal_write_all(trace_desc_t *io_td,
                                 const trace_hash_val i_hash,
                                 const char * i_fmt,
                                 const uint32_t i_line,
                                 const int32_t i_type, va_list i_args)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    uint32_t                l_entry_size = 0;
    uint32_t                l_data_size= 0;
    //trace_entire_entry_t    l_entry;
    trace_bin_entry_t       l_entry;
    uint64_t                l_str_map = 0;
    uint64_t                l_char_map = 0;
    uint64_t                l_double_map = 0;


    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    uint32_t num_args = 0;
    uint32_t num_4byte_args = 0; //fsp-trace counts 8-byte args as 2 4-byte args
    const char* _fmt = i_fmt;

    // Save a copy of input args because calling
    // va_arg() on a va_list is a one-shot.
    va_list l_args;
    va_copy (l_args, i_args);


    // Sum the sizes of the items in i_args in order to know how big to
    // allocate the entry.

    for (size_t i = 0; i <= strlen(_fmt); i++)
    {
        if ('%' == _fmt[i])
        {
            i++;

            if ('%' == _fmt[i])
            {
                continue;
            }
            else if ('s' == _fmt[i])
            {
                // Set flag to indicate argument is a string
                l_str_map = l_str_map | (1 << num_args);

                // String counts as one 4-byte arg
                num_args++;
                num_4byte_args++;

                char * l_str = va_arg(i_args, char *);
                size_t l_strLen = strlen(l_str);

                // Add to total size of number of arguments we're tracing
                // and account for word alignment
                l_data_size += l_strLen + 1;
                l_data_size = ALIGN_4(l_data_size);

                //printk("Trace: STRING %s: strlen %d num_args %d l_data_size %d\n",
                //       l_str, static_cast<uint32_t>(l_strLen),
                //       num_args, l_data_size);
                //printk("Trace: l_str_map 0x%16llX\n",
                //     static_cast<long long>(l_str_map));
            }
            else if ('c' == _fmt[i])
            {
                // Set flag to indicate argument is a char
                l_char_map = l_char_map | (1 << num_args);

                // Increment arg counts
                num_args++;
                num_4byte_args++;

                // Retrieve the argument to increment to next one
                uint32_t l_tmpData = va_arg(i_args, uint32_t);

                // Add to total size; data is word aligned
                l_data_size += sizeof(l_tmpData);
            }
            else if (('e' == _fmt[i]) || ('f' == _fmt[i]) || ('g' == _fmt[i]))
            {
                // Set flag to indicate argument is a double
                l_double_map = l_double_map | (1 << num_args);

                // Numbers count as two 4-byte arg
                num_args++;
                num_4byte_args += 2;

                // Retrieve the argument to increment to next one
                double l_tmpData = va_arg(i_args,double);

                // Add to total size; data is word aligned
                l_data_size += sizeof(l_tmpData);
            }
            else
            {
                // Numbers count as two 4-byte arg
                num_args++;
                num_4byte_args += 2;

                // Retrieve the argument to increment to next one
                uint64_t l_tmpData = va_arg(i_args, uint64_t);

                // Add to total size; data is word aligned
                l_data_size += sizeof(l_tmpData);
            }
        }
    }

    va_end( i_args );


    if((num_4byte_args <= TRAC_MAX_ARGS) && (io_td != NULL))
    {
        // Fill in the entry structure
        l_entry.stamp.tid = static_cast<uint32_t>(task_gettid());

        // Length is equal to size of data
        l_entry.head.length = l_data_size;
        //l_entry.head.tag = TRACE_FIELDTRACE;
        l_entry.head.tag = TRACE_COMP_TRACE;
        l_entry.head.hash = i_hash;
        l_entry.head.line = i_line;


        // Calculate total space needed for the entry, which is a
        // combination of the data size from above, the entry
        // headers, and an overall length field.
        l_entry_size = l_data_size +
                       sizeof(trace_entry_stamp_t) +
                       sizeof(trace_entry_head_t)  +
                       // Allow for a uint32 at the end of the trace entry
                       // so parsers may walk the trace buffer backwards
                       sizeof(uint32_t);

        // Round up the size to the next word boundary
        l_entry_size = ALIGN_4(l_entry_size);

        // Allocate buffer for the arguments we're tracing
        void * l_buffer = malloc(l_data_size);
        memset(l_buffer, 0, l_data_size);
        char * l_ptr = static_cast<char *> (l_buffer);

        // Now copy the arguments to the buffer.


        for (size_t i = 0; i < num_args; i++)
        {
            uint32_t l_strLen = 0;

            if (l_str_map & (1 << i))
            {
                // Save string to buffer
                strcpy(l_ptr, va_arg(l_args, char *));

                //printk("Trace: Saved String %s Arg[%d]\n", l_ptr, static_cast<uint32_t>(i));

                // Length = string length + NULL termination
                l_strLen += (strlen(l_ptr) + 1);

                // Increment pointer to next word alignment
                l_ptr += l_strLen;
                l_ptr = reinterpret_cast<char *>(
                        ALIGN_4(reinterpret_cast<uint64_t>(l_ptr)) );

                //printk("Trace::trace_adal_write_all - l_buffer %p l_ptr %p l_strLen %d\n",
                //       l_buffer, l_ptr, l_strLen);
                //printk("Trace::trace_adal_write_all - num_args %d l_data_size %d l_entry_size %d\n",
                //       num_args, l_data_size, l_entry_size);
            }
            else if (l_char_map & (1 << i))
            {
                // Save char to buffer & increment pointer (no need to align)
                *(reinterpret_cast<uint32_t *>(l_ptr)) = va_arg(l_args, uint32_t);
                l_ptr += sizeof(uint32_t);

            }
            else if (l_double_map & (1 << i))
            {
                // Save number to buffer & increment pointer (no need to align)
                *(reinterpret_cast<double *>(l_ptr)) = va_arg(l_args, double);

                l_ptr += sizeof(double);
            }
            else
            {
                // Save number to buffer & increment pointer (no need to align)
                *(reinterpret_cast<uint64_t *>(l_ptr)) = va_arg(l_args, uint64_t);
                l_ptr += sizeof(uint64_t);
            }
        }

        va_end(l_args);

        // Write entry to the trace buffer.

        // CRITICAL REGION START
        mutex_lock(&iv_trac_mutex);

        // time stamp the entry with time-base register
        convertTime(&l_entry.stamp);

        // Update the entry count
        io_td->te_count++;

        // First write the header
        writeData(io_td,
                  static_cast<void *>(&l_entry),
                  sizeof(l_entry));

        // Now write the actual data
        writeData(io_td,
                  l_buffer,
                  l_data_size);

        // Now write the size at the end
        // Note that fsp-trace assumes this to be a 32 bit long word
        writeData(io_td,
                  static_cast<void *>(&l_entry_size),
                  sizeof(l_entry_size));



        // Write to the combined trace buffer, a stream of traces.
        while (iv_ContinuousTrace)
        {
            // This entry requires this many bytes to fit.
            uint64_t l_cbCompName = 1 + strlen( io_td->comp );
            uint64_t l_cbRequired = l_cbCompName + sizeof(l_entry) +
                                                   l_data_size;

            if (l_cbRequired > TRAC_BINARY_SIZE)
            {
                // caller is logging more binary data than the
                // maximum size of the current tracBinary buffer.
                // TODO need to increase the buffer size, or else
                // document its limits.
                break;
            }

            ManageContTraceBuffers(l_cbRequired);

            // Copy the entry piecemeal to the destination.
            char * l_pchDest = g_tracBinaryInfo[iv_CurBuf].pBuffer +
                               g_tracBinaryInfo[iv_CurBuf].cbUsed;

            // component name and its trailing nil byte
            strcpy( l_pchDest, io_td->comp );
            l_pchDest += l_cbCompName;

            // trace entry
            memcpy( l_pchDest, &l_entry, sizeof(l_entry));
            l_pchDest += sizeof(l_entry);

            // trace entry data
            memcpy( l_pchDest, l_buffer, l_data_size );

            // adjust for next time
            g_tracBinaryInfo[iv_CurBuf].cbUsed += l_cbRequired;

            // maintain the buffer's actually used bytes for VPO script
            if (g_cont_trace_trigger_info.enable > 1)
            {
                g_cont_trace_trigger_info.triggers[iv_CurBuf].len =
                                           g_tracBinaryInfo[iv_CurBuf].cbUsed;
            }

            // break from while() which was used much like an if()
            break;
        }


        mutex_unlock(&iv_trac_mutex);
        // CRITICAL REGION END

        // Free allocated memory
        free(l_buffer);
    }

    return;
}

/******************************************************************************/
// trace_adal_write_bin
/******************************************************************************/
void Trace::trace_adal_write_bin(trace_desc_t *io_td,const trace_hash_val i_hash,
                                 const uint32_t i_line,
                                 const void *i_ptr,
                                 const uint32_t i_size,
                                 const int32_t type)
{
    getTheInstance()._trace_adal_write_bin(io_td, i_hash,
                                           i_line,
                                           i_ptr,
                                           i_size,
                                           type);
}

/******************************************************************************/
// trace_adal_write_bin
/******************************************************************************/
void Trace::_trace_adal_write_bin(trace_desc_t *io_td,const trace_hash_val i_hash,
                                 const uint32_t i_line,
                                 const void *i_ptr,
                                 const uint32_t i_size,
                                 const int32_t type)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    uint32_t                l_entry_size = 0;
    trace_bin_entry_t       l_entry;

    /*----------------------------------------------------------------------    --*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/
    do
    {

        if((io_td == NULL) || (i_ptr == NULL) || (i_size == 0))
        {
            break;
        }

        // Calculate total space needed
        l_entry_size = sizeof(trace_entry_stamp_t);
        l_entry_size += sizeof(trace_entry_head_t);

        // We always add the size of the entry at the end of the trace entry
        // so the parsing tool can easily walk the trace buffer stack so we
        // need to add that on to total size
        l_entry_size += sizeof(uint32_t);

        // Now add on size for actual size of the binary data
        l_entry_size += i_size;

        // Word align the entry
        l_entry_size = ALIGN_4(l_entry_size);

        // Fill in the entry structure
        l_entry.stamp.tid = static_cast<uint32_t>(task_gettid());

        // Length is equal to size of data
        l_entry.head.length = i_size;
        l_entry.head.tag = TRACE_FIELDBIN;
        l_entry.head.hash = i_hash;
        l_entry.head.line = i_line;

        // We now have total size and need to reserve a part of the trace
        // buffer for this

        // CRITICAL REGION START
        mutex_lock(&iv_trac_mutex);


        // time stamp the entry with time-base register
        convertTime(&l_entry.stamp);

        // Increment trace counter
        io_td->te_count++;

        // First write the header
        writeData(io_td,
                  static_cast<void *>(&l_entry),
                  sizeof(l_entry));

        // Now write the actual binary data
        writeData(io_td,
                  i_ptr,
                  i_size);

        // Now write the size at the end
        writeData(io_td,
                  static_cast<void *>(&l_entry_size),
                  sizeof(l_entry_size));

        // Write to the combined trace buffer, a stream of traces.
        // A while() here affords use of break to break out on
        // an error condition.
        while( iv_ContinuousTrace )
        {
            // This entry requires this many bytes to fit.
            uint64_t l_cbCompName = 1 + strlen( io_td->comp );
            uint64_t l_cbRequired = l_cbCompName + sizeof( l_entry ) + i_size;

            if( l_cbRequired > TRAC_BINARY_SIZE )
            {
                // caller is logging more binary data than the
                // maximum size of the current tracBinary buffer.
                // TODO need to increase the buffer size, or else
                // document its limits.
                break;
            }

            ManageContTraceBuffers(l_cbRequired);

            // Copy the entry piecemeal to the destination.
            char * l_pchDest = g_tracBinaryInfo[iv_CurBuf].pBuffer +
                               g_tracBinaryInfo[iv_CurBuf].cbUsed;

            // component name and its trailing nil byte
            strcpy( l_pchDest, io_td->comp );
            l_pchDest += l_cbCompName;

            // trace entry
            memcpy( l_pchDest, &l_entry, sizeof(l_entry));
            l_pchDest += sizeof(l_entry);

            // trace entry data
            memcpy( l_pchDest, i_ptr, i_size );

            // adjust for next time
            g_tracBinaryInfo[iv_CurBuf].cbUsed += l_cbRequired;

            // maintain the buffer's actually used bytes for VPO script
            if (g_cont_trace_trigger_info.enable > 1)
            {
                g_cont_trace_trigger_info.triggers[iv_CurBuf].len =
                                            g_tracBinaryInfo[iv_CurBuf].cbUsed;
            }

            // break from while() which was used much like an if()
            break;
        }


        // CRITICAL REGION END
        mutex_unlock(&iv_trac_mutex);

    }while(0);

    return;
}

/******************************************************************************/
// writeData
/******************************************************************************/
void Trace::writeData(trace_desc_t *io_td,
                    const void *i_ptr,
                    const uint32_t i_size)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    uint32_t            l_total_size = i_size;
    void                *l_buf_ptr = NULL;
    uint32_t            l_offset = 0;
    uint64_t            l_align = 0;

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    do
    {

        if(i_size > (io_td->size-sizeof(trace_buf_head_t)))
        {
            // unreasonable size, caller is asking to write something
            // that is very nearly the size of the entire buffer
            break;
        }


        if((io_td->next_free + l_total_size) > io_td->size)
        {
            // Does not fit entirely, write what fits, and wrap the buffer.

            // Get the pointer to current location in buffer
            l_buf_ptr = reinterpret_cast<char *>(io_td) + io_td->next_free;
            // Figure out the alignment
            l_align = ALIGN_4(reinterpret_cast<uint64_t>(l_buf_ptr)) -
                      reinterpret_cast<uint64_t>(l_buf_ptr);
            // Add on the alignment
            l_buf_ptr = reinterpret_cast<void *>(reinterpret_cast<uint64_t>
                         (l_buf_ptr) + l_align);
            // Ensure offset accounts for the alignment
            l_offset = io_td->size-io_td->next_free - l_align;
            // Copy in what fits
            memcpy(l_buf_ptr,i_ptr,static_cast<size_t>(l_offset));

            l_total_size -= l_offset;

            // Now adjust the main header of buffer
            io_td->times_wrap++;
            io_td->next_free = io_td->hdr_len;
        }

        // Get the pointer to current location in buffer
        l_buf_ptr = reinterpret_cast<char *>(io_td) + io_td->next_free;
        // Figure out the alignment
        l_align = ALIGN_4(reinterpret_cast<uint64_t>(l_buf_ptr)) -
                  reinterpret_cast<uint64_t>(l_buf_ptr);
        // Add on the alignment
        l_buf_ptr = reinterpret_cast<void *>(reinterpret_cast<uint64_t>
                                 (l_buf_ptr) + l_align);

        memcpy(l_buf_ptr,reinterpret_cast<const char *>(i_ptr) + l_offset,
               l_total_size);

        // Make sure size is correct for word alignment
        // Note that this works with binary trace because only the binary data
        // has the potential to be un-word aligned.  If two parts of the binary
        // trace had this problem then this code would not work.
        // Note that fsp-trace will ignore garbage data in the unaligned areas.
        l_total_size = ALIGN_4(l_total_size);
        io_td->next_free += l_total_size;

    }while(0);

    return;

}

/******************************************************************************/
// convertTime
/******************************************************************************/
void Trace::convertTime(trace_entry_stamp_t *o_entry)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    // TODO - Future Sprint will collect proc frequency and correctly
    //        calculate this.
    uint64_t l_time = getTB();
    //o_entry->tbh = l_time && 0xFFFFFFFF00000000;
    //o_entry->tbl = l_time && 0x00000000FFFFFFFF;

    // This basically supports SIMICS, but will look weird on real hw
    o_entry->tbh = (l_time / 512000000);
    o_entry->tbl = ((l_time - (o_entry->tbh * 512000000)) / 512);

}




/******************************************************************************/
// findTdByName
/******************************************************************************/
trace_desc_t * Trace::findTdByName(const char *i_pName)
{
    trace_desc_t *      l_td = NULL;
    char                l_comp[COMP_NAME_SIZE];


    uint64_t i = strlen(i_pName);
    if ( i  )
    {
        if ( i  > (COMP_NAME_SIZE -1))
        {
            // Limit component name.
            memcpy(l_comp, i_pName, COMP_NAME_SIZE - 1);
            l_comp[ COMP_NAME_SIZE - 1 ] = 0;
        }
        else
        {
            strcpy( l_comp, i_pName );
        }

        // Use upper case.
        strupr( l_comp );

        // Lock critical section to access g_desc_array
        mutex_lock(&iv_trac_mutex);

        // Search the buffers array
        for(i=0;
            (i < (TRAC_MAX_NUM_BUFFERS - 1)) &&
            (strlen(g_desc_array[i].comp) != 0);
            i++)
        {
            if(0 == strcmp(l_comp, g_desc_array[i].comp))
            {
                // Return this one.
                l_td = g_desc_array[i].td_entry;
                break;
            }
        }

        // Unlock critical section
        mutex_unlock(&iv_trac_mutex);

    }

    return l_td;
}




/*****************************************************************************/
// getBuffer() called by ErrlEntry.collectTrace()
// Return how many bytes copied to output buffer.
// If given a null pointer or zero buffer then return the full size
// of the buffer.
//
// Otherwise return zero on error; perhaps the component name/trace buffer
// name is not found, or maybe the size of buffer given is too small to even
// hold a trace buffer header.

uint64_t Trace::getBuffer( const char * i_pComp,
                           void *       o_data,
                           uint64_t     i_size )
{
    const char *        l_pchEntry = NULL;         // use this to walk the entries
    const char *        l_pchEntryEOL = NULL;      // end of list of entries
    const char *        l_pchTraceBuffer = NULL;   // source buffer, including header
    const char *        l_pchTraceData = NULL;     // source data, just past header
    const char *        l_pchTraceEOB = NULL;      // end of source buffer
    trace_buf_head_t  * l_pCallerHeader = NULL;    // output buffer, including header
    trace_desc_t *      l_pDescriptor = NULL;
    uint64_t            l_cbWrap = 0;
    uint64_t            l_rc = 0;

    do
    {
        l_pDescriptor = findTdByName( i_pComp );
        if( NULL == l_pDescriptor )
        {
            // trace buffer name not found
            break;
        }

        if( (o_data == NULL) || (i_size == 0 ))
        {
            // return how big is the buffer.
            l_rc = l_pDescriptor->size;
            break;
        }

        // Round size down to nearest 4-byte boundary.
        i_size = ALIGN_DOWN_4(i_size);


        if( i_size < sizeof(trace_buf_head_t))
        {
            // Need at least enough space for the header.
            // printk("trace_get_buffer_partial: i_size too small");
            break;
        }


        // Caller's destination buffer starts with a trace_buf_head_t.
        l_pCallerHeader = static_cast<trace_buf_head_t*>(o_data);



        if( i_size >= l_pDescriptor->size )
        {
            // Caller's buffer is big enough to hold the whole buffer.
            uint64_t l_copyCount = l_pDescriptor->size;

            // Get the lock
            mutex_lock(&iv_trac_mutex);

            // If the buffer is not full, then the unused
            // portion is just zeroes. Avoid copying the zeroes.
            if( 0 == l_pDescriptor->times_wrap )
            {
                // Buffer has never wrapped, so copy the
                // data up to the next-free offset.
                l_copyCount = l_pDescriptor->next_free;
            }

            // Copy source buffer to caller's destination buffer
            memcpy( o_data, l_pDescriptor, l_copyCount );

            mutex_unlock(&iv_trac_mutex);

            // Update the header in the output buffer.
            l_pCallerHeader->size = l_copyCount;

            l_rc = l_copyCount;
            break;
        }



        // Input buffer size is smaller than source buffer size.

        mutex_lock(&iv_trac_mutex);

        if((i_size >= l_pDescriptor->next_free) && (0 == l_pDescriptor->times_wrap))
        {
            // The source buffer has not wrapped,
            // and what is there fits into caller's buffer.
            l_rc = l_pDescriptor->next_free;
            memcpy( o_data, l_pDescriptor, l_rc );

            mutex_unlock(&iv_trac_mutex);

            // Update the header in the output buffer.
            l_pCallerHeader->size = l_rc;
            break;
        }


        // Otherwise, walk the entries backwards because the word
        // just prior to any entry is the length of the previous entry.
        // Subtract this length from the current entry pointer to
        // point to the previous entry. Wrap around as required.


        // Trace descriptor points to base of source trace buffer.
        l_pchTraceBuffer = reinterpret_cast<const char*>(l_pDescriptor);

        // Source trace data resides just past the header.
        l_pchTraceData = reinterpret_cast<const char *>(l_pDescriptor+1);

        // EOB (end of buffer) of source trace buffer
        l_pchTraceEOB = l_pchTraceBuffer + l_pDescriptor->size;

        // useful when calculating locations of wrapped data
        l_cbWrap = l_pDescriptor->size  -  sizeof(trace_buf_head_t);

        // This is how much trace data caller's buffer can hold.
        int l_cbToFill = i_size - sizeof(trace_buf_head_t);



        // Start at next_free, which is not an actual entry.
        // It is where the next entry write will go when it comes.
        // It also marks the end of the list (EOL).
        l_pchEntryEOL = l_pchTraceBuffer + l_pDescriptor->next_free;


        // Walk backwards through the entries, looking for a point
        // such that when walking the source entries from that
        // point forward, those entries will fit into the
        // destination buffer. Because of the cases handled above,
        // this walking will not loop around back to where we started
        // within the source buffer. Otherwise there would have to be
        // tests made for wrapping and sensing when l_pchEntry passes
        // l_pchEntryEOL.  Note that trace entry structures and payload
        // data may be wrapped anywhere on a 4-byte bound.


        // Start here and work backwards.
        l_pchEntry = l_pchEntryEOL;


        do
        {

            if(( l_pchEntry == l_pchTraceData ) && (0 == l_pDescriptor->times_wrap))
            {
                // Exit from this do loop with l_pchEntry the starting point.
                // Probably not going to happen, because the non-wrap short
                // buffer case was handled above.
                // massert( 0 );
                break;
            }


            // Determine the size of the entry prior to l_pchEntry.  Normally,
            // this length is found in the 4-byte word just before the start of any
            // entry.  However, trace code may wrap any given trace entry
            // anywhere on a 4-byte word.

            // massert( l_pchEntry >= l_pchTraceData );
            // massert( l_pchEntry <  l_pchTraceEOB );
            // massert( 0 ==  (((uint64_t)(l_pchEntry)) & 3)  );

            // Length of previous entry is in prior 32-bit word.
            const char * l_pchPreviousLength = l_pchEntry - sizeof(uint32_t);

            if( l_pchPreviousLength  < l_pchTraceData )
            {
                // I am at the start of the source data. Apply wrap byte count
                // to find length up at the end of the buffer.
                l_pchPreviousLength += l_cbWrap;

                // Source buffer must have wrapped.
                // massert( l_pDescriptor->times_wrap );
            }

            // Dereference and get the length of previous entry.
            const uint32_t * l_p32;
            l_p32 = reinterpret_cast<const uint32_t*>(l_pchPreviousLength);
            int l_cbPrevious = *l_p32;



            if(( l_cbToFill - l_cbPrevious ) < 0 )
            {
              // This one is too much. l_pchEntry is the starting point.
              // This is the regular exit point from this loop.
              break;
            }


            // Given the length of the previous one,
            // assign a new value to l_pchEntry
            l_pchEntry -= l_cbPrevious;

            if( l_pchEntry < l_pchTraceData )
            {
                // Wrap.
                l_pchEntry += l_cbWrap;
            }

            l_cbToFill -= l_cbPrevious;
            // massert( l_cbToFill >= 0 );
        }
        while( 1 );



        // Having walked backwards, l_pchEntry is the starting point,
        // All the entries forward of this point are supposed to fit
        // into caller's data buffer.

        // Count how many copied from source to destination buffer.
        int  l_entriesCopied = 0;
        int  l_bytesCopied = sizeof( trace_buf_head_t );

        // Set up destination header.
        memcpy( l_pCallerHeader, l_pDescriptor, sizeof(trace_buf_head_t));

        // Caller's destination area for trace entry data, just past the
        // buffer header.
        char * l_pchDest = reinterpret_cast<char*>(l_pCallerHeader+1);


        while( l_pchEntry != l_pchEntryEOL )
        {
            const trace_bin_entry_t *  l_pEntry;

            // Calculate how many bytes make up this entry. Value
            // goes into l_cbEntry;
            int l_cbEntry;

            if( (l_pchEntry + sizeof(trace_bin_entry_t))   >  l_pchTraceEOB )
            {
                // This entry wraps.  Copy this split-up
                // trace_bin_entry_t to the callers destination buffer
                // (save a malloc) then reference entry->head.length.

                // Copy this much from the end of the source trace buffer.
                int l_cb = l_pchTraceEOB - l_pchEntry;
                memcpy( l_pchDest, l_pchEntry, l_cb );

                // Copy the rest from the start of data in the trace buffer.
                int l_cbTheRest = sizeof( trace_bin_entry_t ) - l_cb;
                memcpy( l_pchDest+l_cb, l_pchTraceData, l_cbTheRest   );

                // I just copied one of these into callers destination buffer.
                l_pEntry = reinterpret_cast<trace_bin_entry_t*>(l_pchDest);
            }
            else
            {
                // Otherwise, point the entry into the source buffer.
                l_pEntry = reinterpret_cast<const trace_bin_entry_t*>(l_pchEntry);
            }

            // Compute length of this entry. entry->head.length is the actual
            // length of the trace data, and has to rounded up to next 4-byte
            // boundary. The extra uint32 is where the size is stored.
            l_cbEntry =  ALIGN_4(l_pEntry->head.length) +
                         sizeof( trace_bin_entry_t )  +
                         sizeof( uint32_t );


            if( (l_pchEntry + l_cbEntry)  >  l_pchTraceEOB )
            {
                // It wraps.  Copy this split-up entry to the
                // callers buffer.
                int l_cb = l_pchTraceEOB - l_pchEntry;
                memcpy( l_pchDest, l_pchEntry, l_cb );

                // Copy the rest
                int l_cbTheRest = l_cbEntry - l_cb;
                memcpy( l_pchDest + l_cb,  l_pchTraceData,  l_cbTheRest );

                // Assign l_pchEntry to next entry
                l_pchEntry = l_pchTraceData + l_cbTheRest;
            }
            else
            {
                // Copy to destination buffer in one go.
                memcpy( l_pchDest, l_pchEntry, l_cbEntry );

                // Assign l_pchEntry to next entry
                l_pchEntry += l_cbEntry;
            }

            l_bytesCopied += l_cbEntry;
            // massert( 0 == ( l_bytesCopied & 3 ));

            // massert( l_pchEntry >= l_pchTraceData );
            // massert( l_pchEntry < l_pchTraceEOB );
            // massert( 0 ==  (((uint64_t)(l_pchEntry)) & 3)  );


            // Increment new data destination pointer.
            l_pchDest  +=  l_cbEntry;
            // massert( l_pchDest <= ((char*)l_pCallerHeader) + i_size );

            // This will eventually go into destination header.
            l_entriesCopied++;

        }

        // Done looking at source buffer stuff.
        mutex_unlock(&iv_trac_mutex);

        // Finish the caller's trace buffer header.
        l_pCallerHeader->times_wrap = 0;
        l_pCallerHeader->te_count   = l_entriesCopied;
        l_pCallerHeader->next_free  = l_bytesCopied;
        l_pCallerHeader->size       = l_bytesCopied;

        // Return how many bytes written to output buffer.
        l_rc = l_bytesCopied;
    }
    while(0);

    return l_rc;
}


/******************************************************************************/
// clearAllBuffers()
/******************************************************************************/
void Trace::clearAllBuffers()
{

    // obtain the big trace lock
    mutex_lock(&iv_trac_mutex);

    // Walk the buffers array
    for( unsigned int i=0; i < TRAC_MAX_NUM_BUFFERS; i++ )
    {
        if( g_desc_array[i].comp[0] )
        {
            // Named, thus in use.

            // Buffer sizes are variable, save the size of it.
            uint32_t l_saveSize = g_desc_array[i].td_entry->size;

            initValuesBuffer( g_desc_array[i].td_entry,
                              g_desc_array[i].comp,
                              l_saveSize );
        }
    }

    // release the lock
    mutex_unlock(&iv_trac_mutex);
}



#if 0
/******************************************************************************/
// resetBuf - TODO
/******************************************************************************/
int32_t Trace::resetBuf()
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    int64_t            l_rc = 0;
    //uint32_t            l_num_des = 0;
    //uint32_t            i=0;

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    // Get mutex so no one traces

    // TODO
    l_rc = UTIL_MUTEX_GET(&iv_trac_mutex,TRAC_INTF_MUTEX_TIMEOUT);
    if(l_rc != TX_SUCCESS)
    {
        printk("trace_reset_buf: Failure trying to get mutex");
        // Badness
    }
    else
    {
        l_num_des = sizeof(g_des_array) / sizeof(trace_descriptor_array_t);

        for(i=0;i<l_num_des;i++)
        {
            // Initialize the buffer
            l_rc = trace_init_values_buffer(g_des_array[i].entry,
                                           g_des_array[i].comp);
            if(l_rc)
            {
                printk("trace_reset_buf: Failure in call to trace_init_values_buffer()");
                break;
            }
        }
    }


    // Always try to release even if fail above
    // TODO - mutex
    //UTIL_MUTEX_PUT(&iv_trac_mutex);

    return(l_rc);
}
#endif

} // namespace
