/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/io/p9_io_cen_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_io_cen_scominit.C
/// @brief Invoke OBUS initfile
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner        : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team            : IO
/// *HWP Level           : 1
/// *HWP Consumed by     : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
///   Invoke CEN scominit file.
///
/// Procedure Prereq:
///   - System clocks are running.
/// @endverbatim
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_io_cen_scominit.H>
#include <centaur_dmi_scom.H>

#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fixes.H>
#include <cen_gen_scom_addresses_fld.H>


//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi2::ReturnCode p9_io_cen_scominit(const CEN_TGT& i_tgt)
{
    // mark HWP entry
    FAPI_INF("p9_io_cen_scominit: Entering...");

    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    // Get system target
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> sys_tgt;

    // Get attached processor target
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> proc_tgt = i_tgt.
            getParent<fapi2::TARGET_TYPE_DMI>().
            getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_INF("Invoke FAPI procedure core: input_target");
    FAPI_EXEC_HWP(rc, centaur_dmi_scom, i_tgt, sys_tgt, proc_tgt);

    if(rc)
    {
        FAPI_ERR("P9 I/O Cen Scominit Failed");
        fapi2::current_err = rc;
    }



    // Centaur DMI FIR setup
    {
        fapi2::buffer<uint64_t> l_cen_fir_mask;
        fapi2::buffer<uint64_t> l_cen_fir_action0;
        fapi2::buffer<uint64_t> l_cen_fir_action1; // Recoverable
        l_cen_fir_mask.flush<1>();
        l_cen_fir_action0.flush<0>();
        l_cen_fir_action1.flush<0>();

        // 0    Rx Invalid State or Parity Error    mask
        // 1    Tx Invalid State or Parity Error    mask
        // 2    GCR Hange Error                     recoverable
        l_cen_fir_mask.clearBit<2>();
        l_cen_fir_action1.setBit<2>();
        // 3:7  Reserved                            mask
        // 8    Training Error                      mask
        // 9    Spare Lane Deployed                 recoverable
        l_cen_fir_mask.clearBit<9>();
        l_cen_fir_action1.setBit<9>();
        // 10   Max Spares Exceeded                 recoverable
        l_cen_fir_mask.clearBit<10>();
        l_cen_fir_action1.setBit<10>();
        // 11   Recal or Dynamic Repair Error       recoverable
        l_cen_fir_mask.clearBit<11>();
        l_cen_fir_action1.setBit<11>();
        // 12   Too Many Bus Errors                 unit_cs
        l_cen_fir_mask.clearBit<12>();
        // 13:15 Reserved                           mask
        // 16:23 Bus 1 - Unused                     mask
        // 24:31 Bus 2 - Unused                     mask
        // 32:39 Bus 3 - Unused                     mask
        // 40:47 Bus 4 - Unused                     mask
        // 48    Scom Error                         recoverable
        l_cen_fir_mask.clearBit<48>();
        l_cen_fir_action1.setBit<48>();
        // 49    Scom Error                         recoverable
        l_cen_fir_mask.clearBit<49>();
        l_cen_fir_action1.setBit<49>();
        // 50:63 Unused                             mask


        FAPI_TRY(fapi2::putScom(i_tgt, CEN_FIR_ACTION0_REG, l_cen_fir_action0));
        FAPI_TRY(fapi2::putScom(i_tgt, CEN_FIR_ACTION1_REG, l_cen_fir_action1));
        FAPI_TRY(fapi2::putScom(i_tgt, CEN_FIR_MASK_REG, l_cen_fir_mask));
    }


fapi_try_exit:

    // mark HWP exit
    FAPI_INF("p9_io_cen_scominit: ...Exiting");
    return fapi2::current_err;
}

