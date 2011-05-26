#ifndef ERRLTYPES_H
#define ERRLTYPES_H
/**
 *  @file errltypes.H
 *
 *  @brief  Common ErrlEntry definitions.
 *
 *  This header file contains the definition of ErrlEntry related
 *  parameters.
 *
 */

/**
 * @brief Pointer to an ErrlEntry object
 */
namespace ERRORLOG { class ErrlEntry; };
typedef ERRORLOG::ErrlEntry* errlHndl_t;

/**
 * @brief Macros to store different numbers into uint64_t
 */

// Convert any integer to uint16_t
#define TO_UINT16(x)    static_cast<uint16_t>(x)

// Convert any integer to uint32_t
#define TO_UINT32(x)    static_cast<uint32_t>(x)

// Convert any integer to uint64_t
#define TO_UINT64(x)    static_cast<uint64_t>(x)

// uint16_t val = 8bit:8bit
#define TWO_UINT8_TO_UINT16(left_8, right_8) \
            ( (TO_UINT16(left_8) << 8) | TO_UINT16(right_8) )

// uint32_t val = 16bit:16bit
#define TWO_UINT16_TO_UINT32(left_16, right_16) \
            ( (TO_UINT32(left_16) << 16) | TO_UINT32(right_16) )

// uint64_t val = 32bit:32bit
#define TWO_UINT32_TO_UINT64(left_32, right_32) \
            ( (TO_UINT64(left_32) << 32) | TO_UINT64(right_32) )

// uint64_t val = 16bit:16bit:32bit
#define TWO_UINT16_ONE_UINT32_TO_UINT64(left_16, mid_16, right_32) \
            ( (TO_UINT64(TWO_UINT16_TO_UINT32(left_16, mid_16)) << 32) | \
              TO_UINT64(right_32) )

// uint64_t val = 16bit:16bit:16bit:16bit
#define FOUR_UINT16_TO_UINT64(mostleft_16, left_16, right_16, mostright_16) \
        ( (TO_UINT64(TWO_UINT16_TO_UINT32(mostleft_16, left_16)) << 32) | \
          (TO_UINT64(TWO_UINT16_TO_UINT32(right_16, mostright_16))) )

namespace ERRORLOG
{

/**
 * @brief Enumeration of error log severity
 */
enum errlSeverity_t
{
    ERRL_SEV_INFORMATIONAL = 0x00,
    ERRL_SEV_UNRECOVERABLE = 0x10,
    ERRL_SEV_CRITICAL_SYS_TERM = 0x20,
    ERRL_SEV_UNKNOWN = 0xFF
};

/**
 * @brief Event (error) type
 */
enum errlEventType_t
{
    ERRL_ETYPE_NOT_APPLICABLE           = 0,
    ERRL_ETYPE_DUMP_NOTIFICATION        = 8,
    ERRL_ETYPE_USER_DECONFIG            = 0x20,
    ERRL_ETYPE_SYS_DECONFIG             = 0x21,
    ERRL_ETYPE_CONCURRENT_MAINTENANCE   = 0x40,
    ERRL_ETYPE_CAPACITY_UPGRADE         = 0x60,
};

/**
 * @brief Error log call out priority
 */
enum callOutPriority_t
{
    CALLOUT_PRIORITY_LOW    = 1,
    CALLOUT_PRIORITY_MED    = 2,
    CALLOUT_PRIORITY_HIGH   = 3,
};

/**
 * @brief Error log procedure Id
 */
enum epubProcedureId_t
{
    EPUB_PRC_NONE   = 0x00,
};

/**
 * @brief Sub system definitions
 */
enum epubSubSystem_t
{
    EPUB_RESERVED_0 = 0x00,
    EPUB_UNKNOWN    = 0xFF,
};

/**
 * @brief Terminating flag definitions
 */
enum errlTermState_t
{
    TERM_STATE_NO_FLAGS        = 0x00000000,
    TERM_STATE_UNKNOWN         = 0xFFFFFFFF,
};


/**
 * @brief SRC type definitions
 */
enum srcType_t
{
    SRC_INTERVENTION_REQ   = 0xA1,
    SRC_ERR_INFO           = 0xB1,
    SRC_IPL_STATUS         = 0xC1,
    SRC_GENERAL_STATUS     = 0xD1,
};


} // End namespace

#endif // ERRLTYPES_H
