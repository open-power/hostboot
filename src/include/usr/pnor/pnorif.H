/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/pnor/pnorif.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
    HB_EXT_CODE,    /**< Hostboot Extended Image */
    HB_DATA,        /**< Hostboot Data */
    DIMM_JEDEC_VPD, /**< DIMM JEDEC VPD */
    MODULE_VPD,     /**< Module VPD */
    HB_BASE_CODE,   /**< Hostboot Base Image */
    NUM_SECTIONS,   /**< Number of defined sections */

    //Not currently used
//    GLOBAL_DATA,    /**< Global Data */
//    SBE_IPL,        /**< Self-Boot Engine IPL image */
//    PAYLOAD,        /**< HAL/OPAL */
//    HB_RUNTIME,     /**< Hostboot Runtime Image */
//    HB_ERRLOGS,     /**< Hostboot Error log Repository */

    FIRST_SECTION = TOC,  /**< First section (for looping) */
    LAST_SECTION = HB_BASE_CODE,  /**< Last section (for looping) */
    INVALID_SECTION = NUM_SECTIONS,  /**< Used for error cases, initialization */
};

/**
 * Select a side of flash to access
 */
enum SideSelect
{
    SIDE_A,        /**< A-side of flash */
    SIDE_B,        /**< B-side of flash */
    CURRENT_SIDE,  /**< Use the currently selected side */
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
