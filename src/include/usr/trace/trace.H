/**
 *  @file trace.H
 *
 *  Internal trace definitions and functions.  External users should
 *  not directly include or use this file.  trace/interface.H is the external
 *  file.
*/

#ifndef __TRACE_TRACE_H
#define __TRACE_TRACE_H

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <util/singleton.H>
#include <sys/sync.h>

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

const uint32_t TRACE_BUF_VERSION = 0x01;    // Trace buffer version
const uint32_t TRACE_COMP_TRACE  = 0x434F;  // Component Field Trace - "CO"
const uint32_t TRACE_FIELDTRACE  = 0x4654;  // Field Trace - "FT"
const uint32_t TRACE_FIELDBIN    = 0x4644;  // Binary Field Trace - "FD"

const uint32_t TRACE_DEBUG_ON    = 1;       //Set to this when debug trace on
const uint32_t TRACE_DEBUG_OFF   = 0;       //Set to this when debug trace off

const uint32_t TRAC_COMP_SIZE    = 16;      // Max component name size
const uint32_t TRAC_MAX_ARGS     = 9;       // Max number of arguments in trace

/******************************************************************************/
// Typedef/Enumerations
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
    uint32_t tbh;        /*!< timestamp upper part                            */
    uint32_t tbl;        /*!< timestamp lower part                            */
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
    uint64_t args[TRAC_MAX_ARGS + 1]; /*!< Add 1 for the required buffer size */
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


/******************************************************************************/
// Trace Class
/******************************************************************************/
namespace TRACE
{

// Singleton definition
class Trace;
typedef Singleton<Trace> theTrace;

/**
 *  @brief  Trace Singleton Class
 *
 *  This class managers the internals of the host boot trace implementation.
*/
class Trace
{

public:
    /**
     * @brief Get singleton instance of this class.
     */
    static Trace& getTheInstance();

    /**
     *  @brief  Initialize a trace buffer
     *
     *  @param [out] o_td Trace descriptor to initialize
     *  @param [in] i_comp Component name for trace buffer
     *  @param [in] i_size Size to allocate for trace buffer
     *
     *  @return void
     */
    void initBuffer(trace_desc_t **o_td,
                    const char* i_comp,
                    const size_t i_size );

    /**
     *  @brief  Write component trace out to input buffer
     *
     *  Note that to continue to support tracepp, we must keep the
     *  name of this function as is.
     *
     *  @param [in,out] io_td Trace descriptor of buffer to write to.
     *  @param [in] i_hash Descriptive string hash value
     *  @param [in] i_fmt Formatting string
     *  @param [in] i_line Line number trace was done at
     *  @param [in] i_type Type of trace (TRACE_DEBUG, TRACE_FIELD)
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
     *  Note that to continue to support tracepp, we must keep the
     *  name of this function as is.
     *
     *  @param [in,out] io_td Trace descriptor of buffer to write to.
     *  @param [in] i_hash Descriptive string hash value
     *  @param [in] i_line Line number trace was done at
     *  @param [in] i_ptr Pointer to binary data
     *  @param [in] i_size Size of binary data
     *  @param [in] i_type Type of trace (TRACE_DEBUG, TRACE_FIELD)
     *
     *  @return void
     */
    void trace_adal_write_bin(trace_desc_t * io_td,
                              const trace_hash_val i_hash,
                              const uint32_t i_line,
                              const void *i_ptr,
                              const uint32_t i_size,
                              const int32_t i_type);

protected:

    /**
     * @brief Constructor for the trace object.
     */
    Trace();

    /**
     * @brief Destructor for the trace object.
     */
    ~Trace();

private:

    /**
     * @brief Initialize a new trace buffer
     *
     * Internal function responsible setting up the defaults in a newly created
     * trace buffer.
     *
     * @param [out] o_buf Trace descriptor of component buffer to initialize.
     * @param [in] i_comp Component name
     *
     * @return void
     *
     */
    void initValuesBuffer(trace_desc_t *o_buf,
                          const char *i_comp);


    /**
     * @brief Write the trace data into the buffer
     *
     * Internal function responsible for copying the trace data into the appropriate
     * buffer.
     *
     * @param [in,out] io_td Trace descriptor of component buffer to write to.
     * @param [in] i_ptr Pointer to data to copy into the trace buffer.
     * @param [in] i_size Size of the i_ptr data to copy into the buffer.
     *
     * @return void
     *
     */
    void writeData(trace_desc_t * io_td,
                   const void *i_ptr,
                   const uint32_t i_size);


    /**
     *  @brief  Retrieve full trace buffer for component i_comp
     *
     *  This function assumes memory has already been allocated for
     *  the full trace buffer in o_data.
     *
     *  @param [in] i_td_ptr Trace descriptor of buffer to retrieve.
     *  @param [out] o_data Pre-allocated pointer to where data will be stored.
     *
     *  TODO - Not Supported Yet
     *
     *  @return Non-zero return code on error
     */
    int32_t getBuffer(const trace_desc_t * i_td_ptr,
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
     *  @param [in] i_td_ptr Trace descriptor of buffer to retrieve.
     *  @param [out] o_data Pre-allocated pointer to where data will be stored.
     *  @param [in,out] io_size Size of trace data to retrieve (input)
     *                 Actual size of trace data stored (output)
     *
     *  @return Non-zero return code on error
     */
    int32_t getBufferPartial(const trace_desc_t * i_td_ptr,
                             void *o_data,
                             uint32_t *io_size);

    /**
     *  @brief  Retrieve trace descriptor for input component name
     *
     *  @param [in] i_comp Component name to retrieve trace descriptor for.
     *
     *  @return Valid trace descriptor on success, NULL on failure.
     */
    trace_desc_t * getTd(const char *i_comp);

    /**
     *  @brief  Reset all trace buffers
     *
     *  TODO - Not Supported Yet
     *
     *  @return Non-zero return code on error
     */
    int32_t resetBuf(void);

    /**
     *  @brief  Convert timestamp
     *
     *  @param [out] o_entry Trace entry stamp to fill in the time info for.
     *
     *  @return Void
     */
    void convertTime(trace_entry_stamp_t *o_entry);

    // Disabled copy constructor and assignment operator
    Trace(const Trace & right);
    Trace & operator=(const Trace & right);

    // Global Mutex
    mutex_t    iv_trac_mutex;

};

} // namespace TRACE

#endif
