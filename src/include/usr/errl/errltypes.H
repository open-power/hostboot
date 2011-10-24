//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errltypes.H $
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
 *    @brief Scope is found in user header section.
 
 */
enum errlScope_t
{
    ERRL_SCOPE_PLATFORM            = 0x03, ///< Entire Platform
};



/**
 *   @brief Domain as found in user header section.
 */
enum errlDomain_t
{
    ERRL_DOMAIN_DEFAULT     = 0xFF  // Field based on Subsystem ID
};


/**
 *   @brief Vector as found in user header section.
 */
enum errlVector_t
{
    ERRL_VECTOR_DEFAULT      = 0xFF  // Vector that triggered the base class
                                     // of problem in Problem Domain Field.
                                     // Unique field based on Subsystem ID
};



/**
 *  @brief Platform Event Log actions
 *
 *  Several action flags used to trigger various
 *  handling mechanisms for an event log such as
 *  calling home and sending to the hypervisor.
 */
enum errlActions_t
{
    ERRL_ACTION_NONE             = 0x0000, // No action required
};




/**
 *  @brief Creator types.
 */
enum errlCreator_t
{
    ERRL_CID_HOSTBOOT                       = 'B',
};




/**
 * @brief Enumeration of PEL section eyecatchers. These are
 * usually handled as a uint16_t.  See
 * "eCLipz and P7 Platform Event Log and SRC PLDD" documentation
 * https://mcdoc.boeblingen.de.ibm.com/out/out.ViewDocument.php?documentid=1675
 */
enum errlSectionId_t
{
    ERRL_SID_PRIVATE_HEADER                 = 0x5048, // PH private header
    ERRL_SID_USER_HEADER                    = 0x5548, // UH user header
    ERRL_SID_PRIMARY_SRC                    = 0x5053, // PS
    ERRL_SID_USER_DEFINED                   = 0x5544  // UD user defined
};


/**
 * @brief Enumeration of error log severity.
 * Needs to fit into 1 byte for flattening purposes.
 * 
 * Severity resides in the user header of the PEL log.
 * 
 * Refer to this ErrlEntry setter: 
 * void ErrlEntry::setSev(const errlSeverity_t i_sev)
 */
enum errlSeverity_t
{
    ERRL_SEV_INFORMATIONAL     = 0x00,
    ERRL_SEV_UNRECOVERABLE     = 0x10,
    ERRL_SEV_CRITICAL_SYS_TERM = 0x20,
    ERRL_SEV_UNKNOWN           = 0xFF
};




/**
 * @brief Event (error) type
 * Needs to fit into 1 byte for flattening purposes.
 * 
 * Event type resides in user header of PEL log.
 * 
 * Refer to this ErrlEntry setter:
 * void ErrlEntry::setEventType(const errlEventType_t i_eventType)
 */
enum errlEventType_t
{
    ERRL_ETYPE_NOT_APPLICABLE           = 0x00,
    ERRL_ETYPE_MISCELLANEOUS            = 0x01,
    ERRL_ETYPE_DUMP_NOTIFICATION        = 0x08,
    ERRL_ETYPE_USER_DECONFIG            = 0x20,
    ERRL_ETYPE_SYS_DECONFIG             = 0x21,
    ERRL_ETYPE_CONCURRENT_MAINTENANCE   = 0x40,
    ERRL_ETYPE_CAPACITY_UPGRADE         = 0x60,
};




/**
 * @brief SRC type definitions
 * Needs to fit into 1 byte for flattening purposes.
 * 
 * This represents the byte in an SRC in position
 * XX......  such as B1 in B181F00B.
 * 
 * Refer to errlentry.H and this setter:
 * void ErrlEntry::setSrcType(const srcType_t i_srcType)
 *
 */
enum srcType_t
{
    SRC_INTERVENTION_REQ   = 0xA1,
    SRC_ERR_INFO           = 0xB1,
    SRC_IPL_STATUS         = 0xC1,
    SRC_GENERAL_STATUS     = 0xD1,
};




/**
 * @brief Sub system definitions
 * Needs to fit into 1 byte for flattening purposes.
 * This represents the byte in an SRC in position
 * ..XX....  such as 81 in B181F00B.
 * 
 * Refer to errentry.H and this setter: 
 * void ErrlEntry::setSubSys(const epubSubSystem_t i_subSys);
 */
enum epubSubSystem_t
{
    EPUB_RESERVED_0          = 0x00,
    EPUB_FIRMWARE_SUBSYS     = 0x80,
    EPUB_FIRMWARE_SP         = 0x81,
    EPUB_UNKNOWN             = 0xFF,
};



/**
 * @brief Terminating flag definitions
 * Needs to fit into 1 word (32-bits) for flattening purposes.
 * TODO Termination state and termination action.
 */
enum errlTermState_t
{
    TERM_STATE_NO_FLAGS        = 0x00000000,
    TERM_STATE_UNKNOWN         = 0xFFFFFFFF,
};




/** @enum  errlUserDataType_t
  *
  * These are section type identifiers for the ERRL component for
  * user-defined data sections. For example, if somebody calls
  *           errl->collectTrace("INITSVC")
  * then the resulting UD PEL section header will be tagged with
  *     component id:       ERRL_COMP_ID
  *     section type:       ERRL_UDT_TRACE
  *     version:            ERRL_UDV_DEFAULT_VER_1
  *
  * Other components will have to code a similar enum so that
  * the the errl parser/pretty printer can "dispatch" a user-defined
  * PEL section to them for printing based on the three values in
  * the UD PEL section: component id, section type, and version.
  *
  * The section type field in the PEL header is one byte long.
  */
enum errlUserDataType_t
{
    ERRL_UDT_TRACE          = 0x0C,   // A trace buffer
};


/** @enum  errlUserDataVersion
  *
  * Identifier for the version of user data in an error log.
  * This value is used in conjuction with the type field to format
  * of the additional data in an error log.  Versions and type should
  * be unique across subcomponents of the errl component.
*/
enum errlUserDataVersion
{
    ERRL_UDV_DEFAULT_VER_1      = 0x0001,   // Version 1, default info
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






/**
 * @brief pelSectionHeader_t
 *
 * A PEL structure used to flatten error logs to PEL format.
 *
 * This structure represents the first 8 bytes of any PEL section.
 * Populated by the flatten code of class ErrlSctnHdr for any PEL
 * section.  Classes ErrlUH, ErrlPrvt, and ErrlSctn each have a
 * ErrlSctnHdr.  User-defined sections derive from ErrlSctn, so
 * their section header works though ErrlSctn parent class.
 *
 * When parsing a PEL data set, start at offset 0 (the
 * first section).  Then add "len" to know the starting offset
 * of the second section, and so on.
 *
 * When pretty-printing a user-defined PEL section, the
 * controlling logic will "dispatch" a PEL section to a
 * user-supplied printing function based on the component ID,
 * section type, and version.
 */
typedef struct pelsectionheader
{
  uint16_t   sid;     // section identifier
  uint16_t   len;     // overall length of this section
  uint8_t    ver;     // section version
  uint8_t    sst;     // section type
  uint16_t   compId;  // component ID
} __attribute__((packed))  pelSectionHeader_t;



/**
 * @brief pelPrivateHeaderSection_t
 *
 * A PEL structure used to flatten error logs to PEL format.
 *
 * This structure represents an entire Private Header (PH)
 * PEL section. This section is a fixed overall
 * length of 48 bytes including the PEL section header.
 * This the first section found in a flat PEL dataset.
 * Populated by the flatten code of class ErrlPrvt.
 *
 * The component named in the section header is the
 * creating component of the error log.
 */
typedef struct pelprivateheadersection
{
  pelSectionHeader_t  sectionheader;
  uint64_t   creationTime;
  uint64_t   commitTime;
  uint8_t    creatorId;   // 'B' for Hostboot
  uint8_t    reserved0;
  uint8_t    reserved1;
  uint8_t    sectionCount;
  uint32_t   reserved2;
  uint64_t   creatorImplementation;
  uint32_t   plid;
  uint32_t   eid;
} __attribute__((packed)) pelPrivateHeaderSection_t;



/**
 * @brief pelUserHeaderSection_t
 *
 * A PEL structure used to flatten error logs to PEL format.
 *
 * This structure represents an entire User Header (UH)
 * PEL section. This section is a fixed overall
 * length of 0x18 bytes including the PEL section header.
 * This the second section found in a flat PEL dataset.
 * Populated by the flatten code of class ErrlUH.
 *
 * The component named in the section header is the
 * committing component of the error log.
 */
typedef struct peluserheadersection
{
  pelSectionHeader_t sectionheader;
  uint8_t    ssid;   // subsystem id
  uint8_t    scope;  // event scope
  uint8_t    sev;    // severity
  uint8_t    etype;  // event type
  uint32_t   reserved0;  // for error log return code
  uint8_t    domain;     // TODO not used in Hostboot
  uint8_t    vector;     // TODO not used in Hostboot
  uint16_t   actions;    // TODO not used in Hostboot
  uint32_t   reserved1;
} __attribute__((packed)) pelUserHeaderSection_t;




/**
 * @brief pelSRCSection_t
 *
 * A PEL structure used to flatten error logs to PEL format.
 *
 * This structure represents an entire Primary SRC (PS)
 * PEL section. This section is a fixed overall
 * length of 80 bytes including the PEL section header.
 * This the usually the third section found in a flat PEL dataset.
 * Populated by the flatten code of class ErrlSRC.
 *
 * Hostboot generates a minimal SRC as described under
 * "Common Usage of the SRC Structure" (p.69) in the PEL
 * reference (mcdoc 1675). The page numbers below refer
 * to version 0.8 of that document.
 */

typedef struct pelsrcsection
{
  pelSectionHeader_t sectionheader;
  uint8_t    ver;        // src version, usually a 2
  uint8_t    flags;      // src flags
  uint8_t    reserved0;
  uint8_t    wordcount;  // usually 9
  uint16_t   reserved1;  // usually 0, but I put reasonCode here
  uint16_t   srcLength;  // usually 72
  // "Hex word 2" is the legacy nomenclature. p. 71.
  // Low byte of this word is SRC format 0xF0.
  uint32_t   word2;
  // "Hex word 3" p. 71
  uint16_t   word3;
  uint8_t    moduleId;
  uint8_t    reserved2;
  // "Hex word 4" p. 71  last progress code
  uint32_t   word4;
  // "Hex word 5" p. 72  error status flags, etc.
  uint32_t   word5;
  // "Hex word 6-7" p. 72  optional, iv_user1
  uint64_t   word6;
  // "Hex word 8-9" p. 72  optional, iv_user2
  uint64_t   word8;
  char       srcString[32];
} __attribute__((packed)) pelSRCSection_t;







} // End namespace

#endif // ERRLTYPES_H
