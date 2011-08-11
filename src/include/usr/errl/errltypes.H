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
 *  This file will be included by error log parsers that run
 *  on pool machines, so the stuff in here needs to be generic.
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
 * @brief Enumeration of error log severity.
 * Needs to fit into 1 byte for flattening purposes.
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
 * Needs to fit into 1 byte for flattening purposes.
 */
enum errlEventType_t
{
    ERRL_ETYPE_NOT_APPLICABLE           = 0x00,
    ERRL_ETYPE_DUMP_NOTIFICATION        = 0x08,
    ERRL_ETYPE_USER_DECONFIG            = 0x20,
    ERRL_ETYPE_SYS_DECONFIG             = 0x21,
    ERRL_ETYPE_CONCURRENT_MAINTENANCE   = 0x40,
    ERRL_ETYPE_CAPACITY_UPGRADE         = 0x60,
};

/**
 * @brief Error log call out priority
 * Needs to fit into 1 byte for flattening purposes.
 */
enum callOutPriority_t
{
    CALLOUT_PRIORITY_LOW    = 1,
    CALLOUT_PRIORITY_MED    = 2,
    CALLOUT_PRIORITY_HIGH   = 3,
};

/**
 * @brief Error log procedure Id
 * Needs to fit into 1 byte for flattening purposes.
 */
enum epubProcedureId_t
{
    EPUB_PRC_NONE   = 0x00,
};

/**
 * @brief Sub system definitions
 * Needs to fit into 1 byte for flattening purposes.
 */
enum epubSubSystem_t
{
    EPUB_RESERVED_0 = 0x00,
    EPUB_UNKNOWN    = 0xFF,
};

/**
 * @brief Terminating flag definitions
 * Needs to fit into 1 word (32-bits) for flattening purposes.
 */
enum errlTermState_t
{
    TERM_STATE_NO_FLAGS        = 0x00000000,
    TERM_STATE_UNKNOWN         = 0xFFFFFFFF,
};


/**
 * @brief SRC type definitions
 * Needs to fit into 1 byte for flattening purposes.
 */
enum srcType_t
{
    SRC_INTERVENTION_REQ   = 0xA1,
    SRC_ERR_INFO           = 0xB1,
    SRC_IPL_STATUS         = 0xC1,
    SRC_GENERAL_STATUS     = 0xD1,
};


/**
 * @brief  This is the size of the storage buffer, presently
 * in L3 RAM.  When this storage is filled, no more error logs
 * will be committed. The L3 RAM storage is g_ErrlStorage[]
 * declared in errlmanager.C in BSS data. This will change
 * when switching to PNOR.
 */
const uint32_t ERRL_STORAGE_SIZE = 65536;



/**
 * @brief Flattened error log header structure contains the basic
 * instance variables of the ErrlEntry class.  Note the
 * alignment of the fields, and that the structure is packed.
 */
typedef struct errl_header
{
    uint32_t cbytes;           // count of bytes in this struct
    uint32_t csections;        // count of sections in this error log
    uint16_t reasonCode;       // reason code
    uint8_t  unused1;          // need this for alignment
    uint8_t  modId;            // module id
    uint8_t  sev;              // severity
    uint8_t  eventType;        // event type
    uint8_t  subSys;           // subsystem
    uint8_t  srcType;          // SRC type
    uint32_t termState;        // Terminate state
    uint32_t logId;            // This log's unique ID
    uint64_t user1;            // Optional user data 1
    uint64_t user2;            // Optional user data 2
    uint64_t CreationTime;     // time error log was created
} __attribute__((packed)) errl_header_t;



/**
 * @brief Error logs may have a number of sections/FFDC sections added.
 * This is a section header that preceeds the user-defined
 * data that follows this header.  Note the alignment of the fields,
 * and that this structure is packed.
 */
typedef struct section_header
{
    uint32_t  cbHeader;    // count of bytes in this struct (flattening)
    uint32_t  cbSection;   // count of bytes in the user-added data
    uint16_t  compId;      // component id
    uint8_t   sctnVer;     // section version
    uint8_t   subSect;     // subsection
} __attribute__((packed)) section_header_t;


/**
 * @brief The RAM storage for committed error logs starts with this
 * header.  This structure is org'ed at &g_ErrlStorage[0].  All
 * offsets are based from &g_achErrlStorage[0], so the first
 * marker will appear at offset sizeof( storage_header_t )
 */
typedef struct storage_header
{
    uint32_t    cbStorage;        // count of bytes in buffer
    uint32_t    cInserted;        // count of logs ever commited
    uint32_t    offsetStart;      // start-of-list marker
    uint32_t    offsetMarker;     // next-insertion marker
} __attribute__((packed)) storage_header_t;




/**
 * @brief The storage buffer is a series of flattened error logs
 * interspersed with markers.
 * A typical marker will give the offset to the next marker and also
 * the length of the flattened error log data.
 */
typedef struct marker
{
    uint32_t    offsetNext;
    uint32_t    length;
} __attribute__((packed)) marker_t;



} // End namespace

#endif // ERRLTYPES_H
