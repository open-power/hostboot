/* TODO
 *  - Add support in for debug trace enable/disable
 *  - FORMAT_PRINTF support
 *  - %s support
 *  - Multiple buffer support
 *  - Prolog
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
#include <kernel/pagemgr.H>
#include <limits.h>
#include <stdlib.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string.h>

#include <trace/trace.H>

/******************************************************************************/
// Namespace
/******************************************************************************/
namespace TRACE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

const uint32_t TRAC_TIME_REAL   = 0;  // upper 32 = seconds, lower 32 = microseconds
const uint32_t TRAC_TIME_50MHZ  = 1;
const uint32_t TRAC_TIME_200MHZ = 2;
const uint32_t TRAC_TIME_167MHZ = 3;  // 166666667Hz
const uint32_t COMP_NAME_SIZE   = 16; // NULL terminated string

// Initial implementation is to allocate a fixed 2KB buffer to each
// component on request.
// NOTE: any change to this value will require change to Trace::initBuffer()
// since currently malloc() does not work for large allocations/fragmentations
// and we are using PageManager::allocatePage() to allocate space for two
// buffers at a time.  Once malloc() works, we can remove this constraint.
const uint64_t TRAC_DEFAULT_BUFFER_SIZE = 0x0800;  //2KB

// NOTE: This constant should only be changed to an even number for now.
// Same reason as above.
const uint64_t TRAC_MAX_NUM_BUFFERS = 24;

const char * const TRAC_DEFAULT_BUFFER_NAME = "DEFAULT";

// Global component trace buffer array.  Initially allow for 24 buffers max.
// Keep global so it can be found in syms file
typedef struct trace_desc_array {
    char comp[COMP_NAME_SIZE];        // the buffer name
    trace_desc_t * td_entry;          // pointer to the buffer
}trace_desc_array_t;

trace_desc_array_t g_desc_array[TRAC_MAX_NUM_BUFFERS];

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

    memset(g_desc_array, 0, sizeof(g_desc_array));
}

/******************************************************************************/
// Trace::~Trace
/******************************************************************************/
Trace::~Trace()
{

}


/******************************************************************************/
// trace_adal_init_buffer
/******************************************************************************/
void Trace::initBuffer(trace_desc_t **o_td, const char* i_comp,
                            const size_t i_size )
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    uint32_t i = 0;
    char * l_td = NULL;
    char l_comp[COMP_NAME_SIZE] = {'\0'};

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/
    if(*o_td == NULL)
    {
        // Limit component name to 15 characters.
        // Too bad we don't have strncpy(), strncmp()
        if (strlen(i_comp) > (COMP_NAME_SIZE -1))
        {
            memcpy(l_comp, i_comp, COMP_NAME_SIZE - 1);
        }
        else
        {
            strcpy(l_comp, i_comp);
        }

        // CRITICAL REGION START
        mutex_lock(&iv_trac_mutex);

        // Search through the descriptor array for the first unallocated buffer.
        // The last buffer is the reserved default buffer for any component
        // which didn't get its own buffer.
        for (i = 0; i < (TRAC_MAX_NUM_BUFFERS - 1); i++)
        {
            if(!strcmp(l_comp, g_desc_array[i].comp))
            {
                //printk("Trace::initBuffer - buffer already allocated %d\n", i);

                // Buffer is already allocated.  Return the buffer.
                *o_td = g_desc_array[i].td_entry;

                break;
            }
            else if (strlen(g_desc_array[i].comp) == 0)
            {
                //printk("Trace::initBuffer - found unallocated buffer %d\n", i);

                // Found the first unallocated buffer; use this one.

                // Set the component name for the buffer
                strcpy(g_desc_array[i].comp, l_comp);

                // Allocate memory if needed
                if (NULL == g_desc_array[i].td_entry)
                {
                    //printk("Trace::initBuffer - allocate memory\n");

                    // Allocate memory for two buffers.
                    // Once malloc() works, we can allocate memory for one
                    // one buffer at a time.
                    l_td = static_cast<char *>(PageManager::allocatePage());

                    g_desc_array[i].td_entry =
                        reinterpret_cast<trace_desc_t *>(l_td);

                    g_desc_array[i+1].td_entry =
                        reinterpret_cast<trace_desc_t *>(
                            l_td + TRAC_DEFAULT_BUFFER_SIZE);
                }

                // Initialize the buffer header
                initValuesBuffer(g_desc_array[i].td_entry,
                                 g_desc_array[i].comp);

                // Return the newly allocated buffer
                *o_td = g_desc_array[i].td_entry;

                break;
            }
        }

        if ((TRAC_MAX_NUM_BUFFERS - 1) == i)
        {
            //printk("Trace::initBuffer - allocate default buffer %d\n", i);

            // We're out of buffers to allocate.
            // Use the default buffer reserved for everyone else.
            // Initialize only once
            if (strlen(g_desc_array[i].comp) == 0)
            {
                // Set the component name for the buffer
                strcpy(g_desc_array[i].comp, TRAC_DEFAULT_BUFFER_NAME);

                // Allocate memory if needed
                // Memory should have already been reserved if
                // TRAC_MAX_NUM_BUFFERS is an even # and we're using
                // PageManager::allocatePage().  Add check just in
                // case TRAC_MAC_NUM_BUFFERS is set to an odd number.
                if (NULL == g_desc_array[i].td_entry)
                {
                    //printk("Trace::initBuffer - allocate memory\n");

                    // Allocate memory for buffer
                    l_td = static_cast<char *>(PageManager::allocatePage());

                    // Throw away the last 2KB for now to keep code simple
                    // until we decide to add support for variable-sized
                    // buffers.  Also, once we change to use malloc(),
                    // we won't have this problem.
                    g_desc_array[i].td_entry =
                        reinterpret_cast<trace_desc_t *>(l_td);
                }

                // Initialize the buffer header
                initValuesBuffer(g_desc_array[i].td_entry,
                                 g_desc_array[i].comp);
            }

            // Return the default buffer
            *o_td = g_desc_array[i].td_entry;
        }

        mutex_unlock(&iv_trac_mutex);
        // CRITICAL REGION END

    }

    return;
}

/******************************************************************************/
// initValuesBuffer
/******************************************************************************/
void Trace::initValuesBuffer(trace_desc_t *o_buf,const char *i_comp)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    // Initialize it to all 0's
    memset(o_buf,0,(size_t)TRAC_DEFAULT_BUFFER_SIZE);

    o_buf->ver = TRACE_BUF_VERSION;
    o_buf->hdr_len = sizeof(trace_buf_head_t);
    o_buf->time_flg = TRAC_TIME_REAL;
    o_buf->endian_flg = 'B';  // Big Endian
    strcpy(o_buf->comp,i_comp);
    o_buf->size = TRAC_DEFAULT_BUFFER_SIZE;
    o_buf->times_wrap = 0;
    o_buf->next_free = sizeof(trace_buf_head_t);

    return;
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
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
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

    if((num_args <= TRAC_MAX_ARGS) && (io_td != NULL))
    {

        // Calculate total space needed
        l_entry_size = sizeof(trace_entry_stamp_t);
        l_entry_size += sizeof(trace_entry_head_t);

        // We always add the size of the entry at the end of the trace entry
        // so the parsing tool can easily walk the trace buffer stack so we
        // need to add that on to total size
        l_entry_size += sizeof(uint32_t);

        // Now add on size for actual number of arguments we're tracing
        l_entry_size += (num_args * sizeof(uint64_t));

        // Word align the entry
        l_entry_size = (l_entry_size + 3) & ~3;

        // Fill in the entry structure
        l_entry.stamp.tid = static_cast<uint32_t>(task_gettid());

        // Length is equal to size of data
        l_entry.head.length = (num_args * sizeof(uint64_t));
        l_entry.head.tag = TRACE_FIELDTRACE;
        l_entry.head.hash = i_hash;
        l_entry.head.line = i_line;

        // Time stamp
        convertTime(&l_entry.stamp);

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
        uint32_t *l_size = reinterpret_cast<uint32_t *>
                            (&(l_entry.args[num_args]));
        *l_size = l_entry_size;

        // We now have total size and need to reserve a part of the trace
        // buffer for this

        // CRITICAL REGION START
        mutex_lock(&iv_trac_mutex);
        // Update the entry count
        io_td->te_count++;

        writeData(io_td,
                  static_cast<void *>(&l_entry),
                  l_entry_size);

        mutex_unlock(&iv_trac_mutex);
        // CRITICAL REGION END
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

        // Now add on size for acutal size of the binary data
        l_entry_size += i_size;

        // Word align the entry
        l_entry_size = (l_entry_size + 3) & ~3;

        // Fill in the entry structure
        l_entry.stamp.tid = static_cast<uint32_t>(task_gettid());

        // Length is equal to size of data
        l_entry.head.length = i_size;
        l_entry.head.tag = TRACE_FIELDBIN;
        l_entry.head.hash = i_hash;
        l_entry.head.line = i_line;

        // We now have total size and need to reserve a part of the trace
        // buffer for this

        // Time stamp
        convertTime(&l_entry.stamp);

        // CRITICAL REGION START
        mutex_lock(&iv_trac_mutex);

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
            break;
        }


        if((io_td->next_free + l_total_size) > io_td->size)
        {
            // Get the pointer to current location in buffer
            l_buf_ptr = reinterpret_cast<char *>(io_td) + io_td->next_free;
            // Figure out the alignment
            l_align = ( (reinterpret_cast<uint64_t>(l_buf_ptr) + 3) & ~3) -
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
        l_align = ( (reinterpret_cast<uint64_t>(l_buf_ptr) + 3) & ~3) -
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
        l_total_size = (l_total_size + 3) & ~3;
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
// getTd
/******************************************************************************/
trace_desc_t * Trace::getTd(const char *i_comp)
{
    /*------------------------------------------------------------------------*/
    /*  Local Variables                                                       */
    /*------------------------------------------------------------------------*/
    uint32_t            i=0;
    trace_desc_t *      l_td = NULL;
    char                l_comp[COMP_NAME_SIZE] = {'\0'};

    /*------------------------------------------------------------------------*/
    /*  Code                                                                  */
    /*------------------------------------------------------------------------*/

    if (strlen(i_comp) != 0)
    {
        // Limit component name to 15 characters.
        if (strlen(i_comp) > (COMP_NAME_SIZE -1))
        {
            memcpy(l_comp, i_comp, COMP_NAME_SIZE - 1);
        }
        else
        {
            strcpy(l_comp, i_comp);
        }

        // Search all allocated component buffers
        for(i=0;
            (i < (TRAC_MAX_NUM_BUFFERS - 1)) &&
            (strlen(g_desc_array[i].comp) != 0);
            i++)
        {
            if(!strcmp(l_comp, g_desc_array[i].comp))
            {
                // Found the component buffer
                l_td = g_desc_array[i].td_entry;
                break;
            }
        }

        if (((TRAC_MAX_NUM_BUFFERS - 1) == i) &&
            (strlen(g_desc_array[i].comp) != 0))

        {
            // Must be the default buffer
            l_td = g_desc_array[i].td_entry;
        }
    }

    return(l_td);
}

/******************************************************************************/
// getBuffer - TODO
/******************************************************************************/
int32_t Trace::getBuffer(const trace_desc_t *i_td_ptr,
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
        l_rc = UTIL_MUTEX_GET(&iv_trac_mutex,TRAC_INTF_MUTEX_TIMEOUT);
        if(l_rc != 0)
        {
            // Badness
        }
        else
        {
            l_rc = SUCCESS;
        }
#endif
        // Copy it's buffer into temp one
        memcpy(o_data,i_td_ptr,(size_t)TRAC_DEFAULT_BUFFER_SIZE);

        // Always try to release even if error above
        // TODO - mutex
        //UTIL_MUTEX_PUT(&iv_trac_mutex);
    }

    return(l_rc);
}

#if 0
/******************************************************************************/
// getBufferPartial - TODO
/******************************************************************************/
// TODO
int32_t Trace::getBufferPartial(const trace_desc_t *i_td_ptr,
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
#if 0
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

#endif
    // Always try to release even if fail above
    // TODO - mutex
    //UTIL_MUTEX_PUT(&iv_trac_mutex);

    return(l_rc);
}

} // namespace
