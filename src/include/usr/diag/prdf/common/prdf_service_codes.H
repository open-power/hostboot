/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/prdf/common/prdf_service_codes.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef prdf_services_codes_H
#define prdf_services_codes_H

/**
 * @file prdf_service_codes.H
 * @brief File contains file IDs and reason codes
 */

#ifdef __HOSTBOOT_MODULE

#include <hbotcompid.H>

#else

#include <fips_comp_id.H>

#endif

namespace PRDF
{

/**
 *  @brief Enum specifying "Module ids" for PRDF_CODE_FAIL SRCs.
 *         Each module Id corresponds to a particular
 *         method in a class or an individual function.
 */
enum ModuleId
{
    PRDF_MAIN                     = 0x01,
    PRDF_HOM_HOM_TYPE             = 0x02, // FIXME: May be deprecated
    PRDF_HOM_SCOM                 = 0x03,
    PRDF_HOM_SCAN                 = 0x04,
    PRDF_SDBUG_INIT               = 0x05,
    PRDF_LOADCHIP                 = 0x06,
    PRDF_RULECHIP                 = 0x07,
    PRDF_EXTENSIBLEDOMAIN         = 0x08,
    PRDF_ERRLSMARTPTR             = 0x09,
    PRDF_ASSERT                   = 0x0A,
    PRDF_RAS_SERVICES             = 0x0B,
    PRDF_RESTORE_DRAM_REPAIR      = 0x0C,
};

/******************************************************************************/
// NOTE!!! PLEASE READ THIS IF YOU ADD A NEW REASON CODE:
//  Each new Reason code must have Service Tags (for the Serviceablity tools).
//  The tags need to be in a .C file - the tools won't pick up if in a .H file.
//  In theory the tags should be right in with the code that generates the
//  Reason Code. For prdf this is not possible in most instances.
//  prdf_ras_services.C is the default place holder for the Service tags.
//  So the Service tags should be either added to a prdf .C file for a unique
//  instance, or in ras services.
/******************************************************************************/

/**
 *  @brief Enum specifying Reason Codes (Refcodes), range 0xE501 to 0xE5FF
 */
enum ReasonCode
{
    PRDF_FIRST_REASONCODE                   = PRDF_COMP_ID | 0x01,

    // PRD thermal error log FIXME: may be depricated in P8
    PRDF_THERMAL_FAIL                       = PRDF_COMP_ID | 0x03,

    // Note: Ranges from 0x04 through 0x3f are reserved for when callouts are
    //       all hardware only.

    PRDF_DETECTED_FAIL_HARDWARE             = PRDF_COMP_ID | 0x04,

    // Note: Ranges from 0x40 through 0x4f are reserved for when callouts are
    //       hardware, but also include software or second level support.

    PRDF_DETECTED_FAIL_HARDWARE_PROBABLE    = PRDF_COMP_ID | 0x40,

    // Note: Ranges from 0x50 through 0x5f are reserved for when at least one
    //       callout is software High, and also include some hardware callouts.

    PRDF_DETECTED_FAIL_SOFTWARE_PROBABLE    = PRDF_COMP_ID | 0x50,

    // Note: Ranges from 0x60 through 0x6f are reserved for when callouts are
    //       all software and second level support only.

    PRDF_DETECTED_FAIL_SOFTWARE             = PRDF_COMP_ID | 0x60,
    PRDF_UNSUPPORTED_SCAN_WRITE             = PRDF_COMP_ID | 0x61,

    // Note: Ranges from 0x70 through 0x7f are currently reserved (unused).

    // Note: Ranges from 0x80 through 0xff are reserved for PRD software
    //       callouts. When PRD detects a code problem in PRD itself or as a
    //       result of interaction with another FSP component.

    // Generic PRD analysis internal code error. Usually acompanied with a
    // module ID.
    PRDF_CODE_FAIL                          = PRDF_COMP_ID | 0x80,
    // Error from an ecmdDataBuffer
    PRDF_ECMD_DATA_BUFFER_FAIL              = PRDF_COMP_ID | 0x81,

    // general code for user error or unsupported configuration
    PRDF_INVALID_CONFIG                     = PRDF_COMP_ID | 0x82,

    PRDF_LAST_REASONCODE                    = PRDF_COMP_ID | 0xFF,
};

} // end namespace PRDF

#endif // prdf_services_codes_H
