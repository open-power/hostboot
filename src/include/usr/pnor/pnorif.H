#ifndef __PNOR_PNORIF_H
#define __PNOR_PNORIF_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>

namespace PNOR
{

/**
 * PNOR Sections
 */
enum SectionId
{
    TOC,            /**< Table of Contents */
    GLOBAL_DATA,    /**< Global Data */
    SBE_IPL,        /**< Self-Boot Engine IPL image */
    HB_BASE_CODE,   /**< Hostboot Base Image */
    HB_DATA,        /**< Hostboot Data */
    HB_ERRLOGS,     /**< Hostboot Error log Repository */
    HB_EXT_CODE,    /**< Hostboot Extended Image */
    HB_RUNTIME,     /**< Hostboot Runtime Image */
    PAYLOAD,        /**< HAL/OPAL */
    PFW_LITE_CODE,  /**< PFW-lite */
    OCC_CODE,       /**< OCC Code Image */
    KVM_PART_INFO,  /**< KVM Partition Information */
    CODE_UPDATE,    /**< Code Update Overhead */
    NUM_SECTIONS,   /**< Number of defined sections */

    FIRST_SECTION = TOC,  /**< First section (for looping) */
    LAST_SECTION = CODE_UPDATE,  /**< Last section (for looping) */
    INVALID_SECTION = NUM_SECTIONS,  /**< Used for error cases, initialization */
};

/**
 * Select a side of flash to access
 */
enum SideSelect
{
    SIDE_A,   /**< A-side of flash */
    SIDE_B,   /**< B-side of flash */
    SIDELESS, /**< Sideless data */
};

/**
 * Information about a section of PNOR
 */
struct SectionInfo_t
{
    SectionId id;  /**< Identifier for this section */
    SideSelect side;  /**< Identifier for the side of flash */
    const char* name;  /**< Name of the section */

    uint64_t vaddr;  /**< Virtual address for the start of the section */
    uint64_t size;  /**< Actual size of content in bytes */
    bool eccProtected;  /**< Section is ECC protected */
};




/**
 * @brief  Return the size and address of a given section of PNOR data
 *
 * @param[in] i_section  PNOR section
 * @param[in] i_side  Side select
 * @param[out] o_info  Location and size information
 *
 * @return errlHndl_t  Error log if request was invalid
 */
errlHndl_t getSectionInfo( SectionId i_section,
                           SideSelect i_side,
                           SectionInfo_t& o_info );


}
#endif
