/**
 *  @file trace.H
 *
 *  @brief Internal trace definitions and functions
*/

#ifndef __TRACE_TRACE_H
#define __TRACE_TRACE_H

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>

namespace TRACE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

#define TRACE_BUF_VERSION   0x01;   // Trace buffer version
#define TRACE_FIELDTRACE    0x4654  // Field Trace - "FT"
#define TRACE_FIELDBIN      0x4644  // Binary Field Trace - "FD"

#define TRACE_DEBUG_ON      1       //Set to this when debug trace on
#define TRACE_DEBUG_OFF     0       //Set to this when debug trace off


/******************************************************************************/
// Typedef/Enumerations
/******************************************************************************/

/******************************************************************************/
// Function Prototypes
/******************************************************************************/

/**
 * @brief Initialize a new trace buffer
 *
 * Internal function responsible setting up the defaults in a newly created
 * trace buffer.
 *
 * @param[out] o_buf Trace descriptor of component buffer to initialize.
 * @param[in] i_comp Component name
 *
 * @return void
 *
 */
void trace_init_values_buffer(trace_desc_t *o_buf,
                              const char *i_comp);


/**
 * @brief Write the trace data into the buffer
 *
 * Internal function responsible for copying the trace data into the appropriate
 * buffer.
 *
 * @param[inout] io_td Trace descriptor of component buffer to write to.
 * @param[in] i_ptr Pointer to data to copy into the trace buffer.
 * @param[in] i_size Size of the i_ptr data to copy into the buffer.
 *
 * @return void
 *
 */
void trace_write_data(trace_desc_t * io_td,
                    const void *i_ptr,
                    const uint32_t i_size);


/**
 *  @brief  Retrieve full trace buffer for component i_comp
 *
 *  This function assumes memory has already been allocated for
 *  the full trace buffer in o_data.
 *
 *  @param i_td_ptr Trace descriptor of buffer to retrieve.
 *  @param o_data Pre-allocated pointer to where data will be stored.
 *
 *  TODO - Not Supported Yet
 *
 *  @return Non-zero return code on error
 */
int32_t trace_get_buffer(const trace_desc_t * i_td_ptr,
                     void *o_data);

/**
 *  @brief  Retrieve partial trace buffer for component i_comp
 *
 *  This function assumes memory has already been allocated for
 *  the trace buffer (size io_size).  This function will copy
 *  in up to io_size in bytes to the buffer and set io_size
 *  to the exact size that is copied in.
 *
 *  TODO - Not Supported Yet
 *
 *  @param i_td_ptr Trace descriptor of buffer to retrieve.
 *  @param o_data Pre-allocated pointer to where data will be stored.
 *  @param io_size Size of trace data to retrieve (input)
 *                 Actual size of trace data stored (output)
 *
 *  @return Non-zero return code on error
 */
int32_t trace_get_buffer_partial(const trace_desc_t * i_td_ptr,
                    void *o_data,
                    uint32_t *io_size);

/**
 *  @brief  Retrieve trace descriptor for input component name
 *
 *  @param i_comp Component name to retrieve trace descriptor for.
 *
 *  TODO - Not Supported Yet
 *
 *  @return Valid trace descriptor on success, NULL on failure.
 */
trace_desc_t * trace_get_td(const char *i_comp);

/**
 *  @brief  Reset all trace buffers
 *
 *  TODO - Not Supported Yet
 *
 *  @return Non-zero return code on error
 */
int32_t trace_reset_buf(void);

} // namespace TRACE

#endif
