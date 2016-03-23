/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_sbe_hb_structures.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------------
//
/// @file p9_sbe_hb_structures.H
/// @brief Structures that the SBE and HB will both use
//
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE, HB
//-----------------------------------------------------------------------------------

#ifndef _SBE_HB_STRUCTURES_H_
#define _SBE_HB_STRUCTURES_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

// Structure starts at the bootloader zero address
struct BootloaderConfigData_t
{
    uint32_t version;  // Some kind of version field so we know if there is new data being added
    uint8_t sbeBootSide;  // 0=SBE side 0, 1=SBE side 1   [ATTR_SBE_BOOT_SIDE]
    uint8_t pnorBootSide;  // 0=PNOR side A, 1=PNOR side B  [ATTR_PNOR_BOOT_SIDE]
    uint16_t pnorSizeMB;  // Size of PNOR in MB  [ATTR_PNOR_SIZE]
    uint64_t blLoadSize;  // Size of Load (Exception vectors and Bootloader)
};

#endif
