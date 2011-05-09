/* TODO
 *  - Add support in for debug traces
 *  - Time support
 *  - FORMAT_PRINTF support
 *
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <trace/interface.H>
#include <stdarg.h>
#include <arch/ppc.H>
#include <kernel/console.H>
#include <limits.h>
#include <stdlib.h>
#include <sys/task.h>
#include <sys/mutex.h>

#include "trace.H"

/******************************************************************************/
// Namespace
/******************************************************************************/
namespace TRACE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

#define TRAC_TIME_REAL   0  // upper 32 = seconds, lower 32 = microseconds
#define TRAC_TIME_50MHZ  1
#define TRAC_TIME_200MHZ 2
#define TRAC_TIME_167MHZ 3  // 166666667Hz
#define COMP_NAME_SIZE   16

// Global value used as a "timer" to provide tracing point32_t of reference
uint32_t  g_trac_time_high = 0;
uint32_t  g_trac_time_low = 0;

// Global Mutex
mutex_t    g_trac_mutex;

// Global buffer
trace_desc_t *g_trac_global = NULL;



/******************************************************************************/
// trace_adal_init_buffer
/******************************************************************************/
void trace_adal_init_buffer(trace_desc_t **o_td, const char* i_comp,
                            const size_t i_size )
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/
    if(*o_td == NULL)
    {
        if(g_trac_global == NULL)
        {
            // TODO - How do I make this pre-emption/mutli-threading safe?
            g_trac_mutex = mutex_create();

            printk("Global trace buffer is NULL so create and init it!\n");

            g_trac_global = (trace_desc_t *)(malloc(PAGE_SIZE));
            char l_g_comp[TRAC_COMP_SIZE] = "GLOBAL";
            trace_init_values_buffer(g_trac_global,
                                     l_g_comp);

        }

        // Just assign it to the global buffer since we only have
        // one buffer
        *o_td = g_trac_global;
        printk("Assigned input trace descriptor to global buffer\n");
    }

    printk("*td = %lu\n",(unsigned long int)*o_td);

    return;
}

/******************************************************************************/
// trace_init_values_buffer
/******************************************************************************/
void trace_init_values_buffer(trace_desc_t *o_buf,const char *i_comp)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    // Initialize it to all 0's
    memset(o_buf,0,(size_t)PAGE_SIZE);

    (o_buf)->ver = TRACE_BUF_VERSION;
    (o_buf)->hdr_len = sizeof(trace_buf_head_t);
    (o_buf)->time_flg = TRAC_TIME_167MHZ;
    (o_buf)->endian_flg = 'B';  // Big Endian
    memcpy((o_buf)->comp,i_comp,(size_t)COMP_NAME_SIZE);
    (o_buf)->size = PAGE_SIZE;
    (o_buf)->times_wrap = 0;
    (o_buf)->next_free = sizeof(trace_buf_head_t);

    return;
}

/******************************************************************************/
// trace_adal_write_all
/******************************************************************************/
void trace_adal_write_all(trace_desc_t *io_td,
                          const trace_hash_val i_hash,
                          const char * i_fmt,
                          const uint32_t i_line,
                          const int32_t i_type, ...)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    int64_t                 l_rc = 0;
    uint32_t                l_entry_size = 0;
    trace_entire_entry_t    l_entry;

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    // This code is incorrect for determining formatting but will work for now.
    uint32_t num_args = 0;
    const char* _fmt = i_fmt;
    while ('\0' != *_fmt)
    {
        if ('%' == *_fmt)
            num_args++;
        _fmt++;
    }

    if(num_args > TRAC_MAX_ARGS)
    {
        printk ("Too many arguments: %u",num_args);
    }
    else if(io_td != NULL)
    {

        // Calculate total space needed
        l_entry_size = sizeof(trace_entry_stamp_t);
        l_entry_size += sizeof(trace_entry_head_t);

        // We always add the size of the entry at the end of the trace entry
        // so the parsing tool can easily walk the trace buffer stack so we
        // need to add that on to total size
        l_entry_size += sizeof(uint32_t);

        // Now add on size for acutal number of arguments we're tracing
        l_entry_size += (num_args * sizeof(uint64_t));

        // Word align the entry
        l_entry_size = (l_entry_size + 3) & ~3;

        // Fill in the entry structure
        l_entry.stamp.tid = (uint32_t)task_gettid();   // What is response to this in AME code?

        // Length is equal to size of data
        l_entry.head.length = (num_args * sizeof(uint64_t));
        l_entry.head.tag = TRACE_FIELDTRACE;
        l_entry.head.hash = i_hash;
        l_entry.head.line = i_line;

        // Time stamp
        *(l_entry.stamp.tb) = getTB();

        uint64_t* data = &l_entry.args[0];

        va_list args;
        va_start(args, i_type);
        for (size_t i = 0; i < num_args; i++)
        {
            *data = va_arg(args, uint64_t);
            data++;
        }
        va_end(args);

        // Now put total size at end of buffer
        // Note that fsp-trace assumes this to be a 32 bit long word
        uint32_t *l_size = (uint32_t *)&(l_entry.args[num_args]);
        *l_size = l_entry_size;

        printk("l_entry_size = %u ttid = %u\n",l_entry_size,l_entry.stamp.tid);

        // We now have total size and need to reserve a part of the trace
        // buffer for this

        // CRITICAL REGION START
        l_rc = mutex_lock(g_trac_mutex);
        if(l_rc != 0)
        {
            printk("trace_adal_write_all: Failed to get mutex");
        }
        else
        {
            // Update the entry count
            io_td->te_count++;

            trace_write_data(io_td,
                            (void *)&l_entry,
                            l_entry_size);

            l_rc = mutex_unlock(g_trac_mutex);
            if(l_rc != 0)
            {
                // Badness
                printk("trace_adal_write_all: Failed to release mutex");
            }
        }
        // CRITICAL REGION END
    }
    else
    {
        printk("trace_adal_write_all: User passed invalid parameter");
    }

    return;
}

/******************************************************************************/
// trace_adal_write_bin
/******************************************************************************/
void trace_adal_write_bin(trace_desc_t *io_td,const trace_hash_val i_hash,
                    const uint32_t i_line,
                    const void *i_ptr,
                    const uint32_t i_size,
                    const int32_t type)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    int64_t                 l_rc = 0;
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

        // Now add on size for acutal size of the binary data
        l_entry_size += i_size;

        // Word align the entry
        l_entry_size = (l_entry_size + 3) & ~3;

        // Fill in the entry structure
        l_entry.stamp.tid = (uint32_t)task_gettid();   // What is response to this in AME code?

        // Length is equal to size of data
        l_entry.head.length = i_size;
        l_entry.head.tag = TRACE_FIELDBIN;
        l_entry.head.hash = i_hash;
        l_entry.head.line = i_line;

        // We now have total size and need to reserve a part of the trace
        // buffer for this

        // Time stamp
        *(l_entry.stamp.tb) = getTB();

        // CRITICAL REGION START
        l_rc = mutex_lock(g_trac_mutex);
        if(l_rc != 0)
        {
            printk("trace_adal_write_bin: Failed to get mutex");
        }
        else
        {

            // Increment trace counter
            io_td->te_count++;;

            // First write the header
            trace_write_data(io_td,
                             (void *)&l_entry,
                             sizeof(l_entry));

            // Now write the actual binary data
            trace_write_data(io_td,
                             i_ptr,
                             i_size);

            // Now write the size at the end
            trace_write_data(io_td,
                             (void *)&l_entry_size,
                             sizeof(l_entry_size));

            // CRITICAL REGION END
            l_rc = mutex_unlock(g_trac_mutex);
            if(l_rc != 0)
            {
                // Badness
                printk("trace_adal_write_bin: Failed to release mutex");
            }
        }

    }while(0);

    return;
}

/******************************************************************************/
// trace_write_data
/******************************************************************************/
void trace_write_data(trace_desc_t *io_td,
                    const void *i_ptr,
                    const uint32_t i_size)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    uint32_t            l_total_size = i_size;
    void                *l_buf_ptr = NULL;
    uint32_t            l_offset = 0;

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    do
    {

        if(i_size > PAGE_SIZE)
        {
            printk("trace_write_data: Input size to large!");
            break;
        }

        if((io_td->next_free + l_total_size) > PAGE_SIZE)
        {
            // copy what we can to end
            l_buf_ptr = (char *)io_td + io_td->next_free;
            l_buf_ptr = (void *) ( ((uint64_t) l_buf_ptr + 3) & ~3);
            l_offset = PAGE_SIZE-io_td->next_free;
            memcpy(l_buf_ptr,i_ptr,(size_t)l_offset);

            l_total_size -= l_offset;

            // Now adjust the main header of buffer
            io_td->times_wrap++;
            io_td->next_free = io_td->hdr_len;
        }

        l_buf_ptr = (char *)io_td + io_td->next_free;

        // Word align the write - total size includes this allignment
        l_buf_ptr = (void *) ( ((uint64_t) l_buf_ptr + 3) & ~3);

        memcpy(l_buf_ptr,(char *)i_ptr + l_offset,l_total_size);

        // Make sure size is correct for word allignment
        // Note that this works with binary trace because only the binary data
        // has the potential to be un-word aligned.  If two parts of the binary
        // trace had this problem then this code would not work.
        l_total_size = (l_total_size + 3) & ~3;
        io_td->next_free += l_total_size;

    }while(0);

    return;

}

/******************************************************************************/
// TRAC_get_td - TODO
/******************************************************************************/
trace_desc_t * trace_get_td(const char *i_comp)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    //uint32_t            l_num_des = 0;
    //uint32_t            i=0;
    //trace_desc_t *      l_td = NULL;

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

#if 0
    l_num_des = sizeof(g_des_array) / sizeof(trace_descriptor_array_t);

    for(i=0;i<l_num_des;i++)
    {
        if(memcmp(i_comp,(g_des_array[i].entry)->comp,(size_t)COMP_NAME_SIZE) == 0)
        {
            // Found the component
            l_td = g_des_array[i].entry;
            break;
        }
    }
#endif
    // Only one trace buffer currently
    return(g_trac_global);
}

/******************************************************************************/
// trace_get_buffer - TODO
/******************************************************************************/
int32_t trace_get_buffer(const trace_desc_t *i_td_ptr,
                    void *o_data)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    int64_t            l_rc = 0;

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    if((i_td_ptr) && (o_data != NULL))
    {
        // Get the lock
        // TODO Mutex
#if 0
        l_rc = UTIL_MUTEX_GET(&g_trac_mutex,TRAC_INTF_MUTEX_TIMEOUT);
        if(l_rc != 0)
        {
            // Badness
            printk("TRAC_get_buffer: Failed to get mutex");
        }
        else
        {
            l_rc = SUCCESS;
        }
#endif
        // Copy it's buffer into temp one
        memcpy(o_data,i_td_ptr,(size_t)PAGE_SIZE);

        // Always try to release even if error above
        // TODO - mutex
        //UTIL_MUTEX_PUT(&g_trac_mutex);
    }
    else
    {
        printk("TRAC_get_buffer: Invalid parameter passed by caller");
    }

    return(l_rc);
}

#if 0
/******************************************************************************/
// trace_get_buffer_partial - TODO
/******************************************************************************/
// TODO
int32_t trace_get_buffer_partial(const trace_desc_t *i_td_ptr,
                    void *o_data,
                    uint32_t *io_size)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    int32_t            l_rc = 0;
    char            *l_full_buf = NULL;
    trace_desc_t    *l_head = NULL;
    uint32_t            l_part_size = 0;

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    do
    {

        if((i_td_ptr == NULL) || (o_data == NULL) || (io_size == NULL))
        {
            printk("trace_get_buffer_partial: Invalid parameter passed by caller");
            l_rc = TRAC_INVALID_PARM;
            if(io_size != NULL)
            {
                *io_size = 0;
            }
            break;
        }

        if(*io_size < sizeof(trace_buf_head_t))
        {
            // Need to at least have enough space for the header
            printk("trace_get_buffer_partial: *io_size to small");
            l_rc = TRAC_MEM_BUFF_TO_SMALL;
            *io_size = 0;
            break;
        }

        // First get the full buffer
        l_rc = tx_byte_allocate(&tpmd_trac_debug_byte_pool,
                                (void **)&l_full_buf,
                                TPMD_TRACE_BUFFER_SIZE,
                                TX_NO_WAIT);
        if(l_rc != TX_SUCCESS)
        {
            printk("trace_get_buffer_partial: Failure allocating memory for temp buffer");
            *io_size = 0;
            l_rc = TRAC_MEM_ALLOC_FAIL;
            break;
        }

        l_rc = trace_get_buffer(i_td_ptr,
                               l_full_buf);
        if(l_rc != 0)
        {
            printk("trace_get_buffer_partial: Failure in call to TRAC_get_buffer()");
            *io_size = 0;
            break;
        }

        // Now that we have full buffer, adjust it to be requested size
        memset(o_data,0,(size_t)*io_size);

        if(*io_size > TPMD_TRACE_BUFFER_SIZE)
        {
            // It fits
            *io_size = TPMD_TRACE_BUFFER_SIZE;
            memcpy(o_data,l_full_buf,(size_t)*io_size);
            break;
        }

        l_head = (trace_desc_t *)l_full_buf;
        memcpy(o_data,l_full_buf,(size_t)(l_head->hdr_len));
        l_head = (trace_desc_t *)o_data;
        l_head->size = *io_size;

        if((l_head->next_free == l_head->hdr_len) && (l_head->times_wrap == 0))
        {
            // No data in buffer so just return what we have
            break;
        }

        if(l_head->next_free > *io_size)
        {
            // We can't even fit in first part of buffer
            // Make sure data size is larger than header length
            // Otherwise, we will be accessing beyond memory
            if(*io_size < l_head->hdr_len)
            {
                l_rc = TRAC_DATA_SIZE_LESS_THAN_HEADER_SIZE;
                break;
            }
            l_part_size = *io_size - l_head->hdr_len;

            memcpy((UCHAR *)o_data+l_head->hdr_len,
                   l_full_buf+l_head->next_free-l_part_size,
                   (size_t)l_part_size);

            // Set pointer at beginning because this will be a
            // "just wrapped" buffer.
            l_head->next_free = l_head->hdr_len;

            // Buffer is now wrapped because we copied max data into it.
            if(!l_head->times_wrap)
            {
                l_head->times_wrap = 1;
            }
        }
        else
        {
            // First part of buffer fits fine
            memcpy((UCHAR *)o_data+l_head->hdr_len,
                   l_full_buf+l_head->hdr_len,
                   (size_t)(l_head->next_free - l_head->hdr_len));


            // If it's wrapped then pick up some more data
            if(l_head->times_wrap)
            {
                // Figure out how much room we have left
                l_part_size = *io_size - l_head->next_free;

                memcpy((UCHAR *)o_data+l_head->next_free,
                       l_full_buf+TPMD_TRACE_BUFFER_SIZE-l_part_size,
                       (size_t)l_part_size);

            }
            else
            {
                // No more data to get, make buffer look as small
                // as possible
                // add '+4' to avoid the need to mark it as wrapped
                // (if the last byte of the buffer is filled
                // next_free has to pointer to the first byte)

                l_head->size = l_head->next_free + 4;

            }

        }

        *io_size = l_head->size;

    }while(0);

    if(l_full_buf != NULL)
    {
        tx_byte_release(l_full_buf);
    }

    return(l_rc);
}
#endif

/******************************************************************************/
// trace_reset_buf - TODO
/******************************************************************************/
int32_t trace_reset_buf()
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
#if 0
    // TODO
    l_rc = UTIL_MUTEX_GET(&g_trac_mutex,TRAC_INTF_MUTEX_TIMEOUT);
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

#endif
    // Always try to release even if fail above
    // TODO - mutex
    //UTIL_MUTEX_PUT(&g_trac_mutex);

    return(l_rc);
}

} // namespace
