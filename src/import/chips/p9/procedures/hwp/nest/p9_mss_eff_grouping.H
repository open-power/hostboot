/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_mss_eff_grouping.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// ----------------------------------------------------------------------------
/// @file  p9_mss_eff_grouping.H
///
/// @brief Perform Memory Controller grouping on each processor chip
///
/// The purpose of this procedure is to effectively group the memory on each
/// processor chip based on available memory behind its memory grouping ports.
/// Some placement policy/scheme and other info that are stored in the
/// attributes are used as part of the grouping process.
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 2
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

#ifndef _P9_MSS_EFF_GROUPING_H_
#define _P9_MSS_EFF_GROUPING_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

///----------------------------------------------------------------------------
/// Constant definitions
///----------------------------------------------------------------------------

// Constants used for EffGroupingData struct
const uint8_t DATA_GROUPS   = 16;   // 8 regular groups, 8 mirrored groups
const uint8_t MIRR_OFFSET   = 8;    // Start of mirrored offset in DATA_GROUPS
const uint8_t DATA_ELEMENTS = 18;   // 18 items of data for each group

// Indexes used for EffGroupingData::iv_data DATA ELEMENTS
const uint8_t PORT_SIZE = 0;         // Memory size of each port in group (GB)
const uint8_t PORTS_IN_GROUP = 1;    // Number of ports in group
const uint8_t GROUP_SIZE = 2;        // Memory size of entire group (GB)
const uint8_t BASE_ADDR = 3;         // Base Address
#define MEMBER_IDX(X) ((X) + 4)      // List of MC ports in group
#define ALT_VALID(X) ((X) + 12)      // Alt Memory valid (2 alt memory regions)
#define ALT_SIZE(X) ((X) + 14)       // Alt Memory Size
#define ALT_BASE_ADDR(X) ((X) + 16)  // Alt Base Address

// Number of memory regions
const uint8_t NUM_NON_MIRROR_REGIONS = 8;
const uint8_t NUM_MIRROR_REGIONS = 4;
const uint8_t NUM_OF_HTM_REGIONS = 2; // 2 HTM memory regions
const uint8_t NUM_OF_ALT_MEM_REGIONS = 2; // 2 memory holes

// ------------------------------------------------------
// MC ports
// Define the MC ports to be grouped.
// For Nimbus, MC port is an MCA (8 MCAs)
// For Cumulus, MC port is a DMI (8 DMIs)
// -------------------------------------------------------
const uint8_t NUM_MC_PORTS_PER_PROC = 8;
const uint8_t NUM_DIMMS_PER_DRAM_PORT = 2; // 2 DIMMs per DRAM port

/// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_mss_eff_grouping_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
///
/// @brief p9_mss_eff_grouping procedure
///
/// This HWP is to group the MCs of the input target processor chip based
/// on the amount of memory behind its ports and some policy attribute settings.
///
/// @param[in]    i_target   Reference to TARGET_TYPE_PROC_CHIP target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
extern "C"
{

    fapi2::ReturnCode p9_mss_eff_grouping(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif  // _P9_MSS_EFF_GROUPING_H_
