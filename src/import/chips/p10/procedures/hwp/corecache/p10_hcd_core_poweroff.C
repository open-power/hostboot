/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_core_poweroff.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file  p10_hcd_core_poweroff.C
/// @brief Power off Core+L2 VDD+VCS PFET headers
///

// *HWP HWP Owner          : David Du               <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still             <stillgs@us.ibm.com>
// *HWP FW Owner           : Prasad Brahmasamurdra  <prasadbgr@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:QME
// *HWP Level              : 2


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "p10_hcd_core_poweroff.H"
#include "p10_hcd_mma_poweroff.H"
#include "p10_hcd_corecache_power_control.H"
#include "p10_hcd_common.H"

#ifdef __PPE_QME
    #include "p10_scom_eq.H"
    #include "p10_ppe_c.H"
    using namespace scomt::eq;
    using namespace scomt::ppe_c;
#else
    #include "p10_scom_eq.H"
    #include "p10_scom_c.H"
    using namespace scomt::eq;
    using namespace scomt::c;
#endif

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Procedure: p10_hcd_core_poweroff
//------------------------------------------------------------------------------


fapi2::ReturnCode
p10_hcd_core_poweroff(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target)
{
    fapi2::buffer<buffer_t> l_mmioData = 0;

    FAPI_INF(">>p10_hcd_core_poweroff");

    // MMA PFET Power On/Off sequence requires CL2 PFET[ON] + CL2 RegulationFinger[ON]
    // Stop11: Set RF -> MMA PFET[OFF] -> Drop RF -> CL2 PFET[OFF]
    // Exit11:                                       CL2 PFET[ON] -> Set RF -> MMA PFET[ON] (keep RF on)
    FAPI_DBG("Assert VDD_PFET_REGULATION_FINGER_EN via CPMS_CL2_PFETCNTL[8]");
    FAPI_TRY( HCD_PUTMMIO_S( i_target, CPMS_CL2_PFETCNTL_WO_OR, BIT64(8) ) );

    // Only VDD for MMA
    FAPI_TRY( p10_hcd_mma_poweroff( i_target ) );

    // Clear Regulation Finger for CL2 power off below, only MMA/Vmin require it to be on.
    FAPI_DBG("Drop VDD_PFET_REGULATION_FINGER_EN via CPMS_CL2_PFETCNTL[8]");
    FAPI_TRY( HCD_PUTMMIO_S( i_target, CPMS_CL2_PFETCNTL_WO_CLEAR, BIT64(8) ) );

    FAPI_DBG("Drop sram_enable via CPMS_CL2_PFETCNTL[63:SRAM_ENABLE]");
    FAPI_TRY( HCD_PUTMMIO_S( i_target, CPMS_CL2_PFETCNTL_WO_CLEAR, BIT64(63) ) );

    // VCS off first, VDD off after
    FAPI_TRY( p10_hcd_corecache_power_control( i_target, HCD_POWER_CL2_OFF ) );

    // Removing the regular wake-up filter applied to stop11 entry for the following cases:
    //   1) this hwp called manually by mpipl or
    //   2) any stop11 entry called manually for backing cache power down or
    //   3) any stop11 entry with regular stop instruction
    // This will keep the regular wakeup from not being filtered out, specially for msgsnd
    //   so we can wakeup from stop11.
    FAPI_DBG("Assert REG_WKUP_FILTER_DIS via QME_SCSR[14]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_SCSR_WO_OR, MMIO_LOAD32H( BIT32(14) ) ) );

#ifndef __PPE_QME
    {
        // scope limitation to deal with cross-initialzation
        using namespace scomt;
        using namespace scomt::eq;
        using namespace scomt::c;

        fapi2::buffer<uint64_t> l_qme_scrb;
        fapi2::buffer<uint64_t> l_scsr;

        auto l_eq_mc  =
            i_target.getParent < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST > ();

        // Upon power down for MPIPL, all of the CORE_LPAR_MODE bits are established
        // to their static power on values.
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_IS_MPIPL_Type is_mpipl;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL, FAPI_SYSTEM, is_mpipl));

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chip_target;
        l_chip_target = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        fapi2::ATTR_CHIP_EC_FEATURE_DYN_CORE_LPAR_Type l_ec_dyn_core_lpar;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DYN_CORE_LPAR, l_chip_target, l_ec_dyn_core_lpar));

        if(is_mpipl && l_ec_dyn_core_lpar)
        {
            fapi2::ATTR_CORE_LPAR_MODE_Type l_core_lpar_mode;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CORE_LPAR_MODE, FAPI_SYSTEM, l_core_lpar_mode));

            if (l_core_lpar_mode == fapi2::ENUM_ATTR_CORE_LPAR_MODE_LPAR_PER_CORE)
            {
                FAPI_TRY(PREP_QME_SCSR_SCOM2(i_target),
                         "Error from prep (QME_SCSR_SCOM2)");
                SET_P10_20_QME_SCSR_SINGLE_LPAR_MODE(l_scsr);
                FAPI_TRY(PUT_QME_SCSR_SCOM2(i_target, l_scsr),
                         "Error from putScom (QME_SCSR_SCOM2)");

                FAPI_TRY(PREP_QME_SCRB_WO_OR(l_eq_mc),
                         "Error from prep (QME_SCRB_WO_OR)");
                l_qme_scrb.setBit<20, 4>();
                FAPI_TRY(PUT_QME_SCRB_WO_OR(l_eq_mc, l_qme_scrb),
                         "Error from putScom (QME_SCRB_WO_OR)");
            }
            else  // per Thread
            {
                FAPI_TRY(PREP_QME_SCSR_WO_CLEAR(i_target),
                         "Error from prep (QME_SCSR_SCOM2)");
                CLEAR_P10_20_QME_SCSR_SINGLE_LPAR_MODE(l_scsr);
                FAPI_TRY(PUT_QME_SCSR_WO_CLEAR(i_target, l_scsr),
                         "Error from putScom (QME_SCSR_SCOM2)");

                FAPI_TRY(PREP_QME_SCRB_WO_CLEAR(l_eq_mc),
                         "Error from prep (QME_SCRB_WO_OR)");
                l_qme_scrb.setBit<20, 4>();
                FAPI_TRY(PUT_QME_SCRB_WO_CLEAR(l_eq_mc, l_qme_scrb),
                         "Error from putScom (QME_SCRB_WO_OR)");
            }
        }
    }  // scope limitation
#endif


fapi_try_exit:

    FAPI_INF("<<p10_hcd_core_poweroff");
    return fapi2::current_err;
}
