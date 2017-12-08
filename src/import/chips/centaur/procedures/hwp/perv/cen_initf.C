/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_initf.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file cen_initf.C
/// @brief Centaur initf (FAPI2)
///
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_initf.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fixes.H>
#include <centaur_misc_constants.H>
#include <cen_ring_id.h>
#include <cen_common_funcs.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_initf(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");
    fapi2::Target<fapi2::TARGET_TYPE_DMI> l_attached_dmi_target =
        i_target.getParent<fapi2::TARGET_TYPE_DMI>();
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_attached_proc_target =
        l_attached_dmi_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    fapi2::ATTR_CHIP_EC_FEATURE_HW419021_Type l_hw419021;
    fapi2::buffer<uint64_t> l_nest_clk_scansel_data = 0;
    fapi2::buffer<uint64_t> l_nest_clk_scandata0_data = 0;
    uint64_t l_nest_clk_scansel_addr = get_scom_addr(SCAN_CHIPLET_NEST, CEN_GENERIC_CLK_SCANSEL);
    uint64_t l_nest_clk_scandata0_addr = get_scom_addr(SCAN_CHIPLET_NEST, CEN_GENERIC_CLK_SCANDATA0);

    FAPI_TRY(fapi2::putRing(i_target, tcn_mbs_func),
             "Error from putRing (tcn_mbs_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbs_cmsk),
             "Error from putRing (tcn_mbs_cmsk)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbi_cmsk),
             "Error from putRing (tcn_mbi_cmsk)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbi_func),
             "Error from putRing (tcn_mbi_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_mbi_gptr),
             "Error from putRing (tcn_mbi_gptr)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_perv_func),
             "Error from putRing (tcn_perv_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_dmi_func),
             "Error from putRing (tcn_dmi_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_refr_func),
             "Error from putRing (tcn_refr_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcn_refr_abst),
             "Error from putRing (tcn_refr_abst)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_memn_cmsk),
             "Error from putRing (tcm_memn_cmsk)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_mems_cmsk),
             "Error from putRing (tcm_mems_cmsk)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_memn_func),
             "Error from putRing (tcm_memn_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_mems_func),
             "Error from putRing (tcm_mems_func)");
    FAPI_TRY(fapi2::putRing(i_target, tcm_perv_func),
             "Error from putRing (tcm_perv_func)");

    // re-rotate tcn_mbs_func to fixup spy parity, and set:
    //   MBU.MBS.CFG_UNALIGNED_US_DTAG_TRANSFER_DISABLE=ON
    //   MBU.MBS.CFG_UNALIGNED_NONBYP_US_DTAG_TRANSFER_DISABLE=ON
    // if attached to P9C DD1.0
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW419021,
                           l_attached_proc_target,
                           l_hw419021),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW419021)");

    FAPI_DBG("Re-scanning tcn_mbs_func (HW419021=%d)",
             l_hw419021);
    // ring length is 76490 bits
    // MBU.MBS.ARB.DACTL.MODESLAT_PARITYQ.SLC.L2 = bit 50610 (set to 0 for all chips)
    // MBU.MBS.ARB.CHARB.MODE_PARITYQ.ESC.L2 = bit 72419 (set to 0 for HW419021 only)
    // MBU.MBS.CFG_UNALIGNED_US_DTAG_TRANSFER_DISABLE = bit 72837 (set to 1 for HW419021 only)
    // MBU.MBS.CFG_UNALIGNED_NONBYP_US_DTAG_TRANSFER_DISABLE = bit 72843 (set to 1 for HW419021 only)
    // inject header
    l_nest_clk_scansel_data.setBit<8>().setBit<20>();
    FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scansel_addr, l_nest_clk_scansel_data));
    l_nest_clk_scandata0_data = 0xA5A55A5A00000000;
    FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scandata0_addr, l_nest_clk_scandata0_data));

    // scan 0..50610 (460*110 + 10)
    for (auto ii = 0; ii < 460; ii++)
    {
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x6E, l_nest_clk_scandata0_data));
    }

    FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x0A, l_nest_clk_scandata0_data));

    // flip MBU.MBS.ARB.DACTL.MODESLAT_PARITYQ.SLC.L2
    FAPI_DBG("Flip DACTL parity");
    l_nest_clk_scandata0_data.clearBit<0>();
    FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scandata0_addr, l_nest_clk_scandata0_data));

    // scan 50610..72419 (198*110 + 29)
    for (auto ii = 0; ii < 198; ii++)
    {
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x6E, l_nest_clk_scandata0_data));
    }

    FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x1D, l_nest_clk_scandata0_data));

    if (l_hw419021)
    {
        // flip MBU.MBS.ARB.CHARB.MODE_PARITYQ.ESC.L2
        FAPI_DBG("Flip CHARB parity");
        l_nest_clk_scandata0_data.clearBit<0>();
        FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scandata0_addr, l_nest_clk_scandata0_data));
    }

    // scan 72419..72837 (3*110 + 88)
    for (auto ii = 0; ii < 3; ii++)
    {
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x6E, l_nest_clk_scandata0_data));
    }

    FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x58, l_nest_clk_scandata0_data));

    if (l_hw419021)
    {
        // flip chicken switches
        FAPI_DBG("Flip chicken switches");
        l_nest_clk_scandata0_data.setBit<0>().setBit<6>();
        FAPI_TRY(fapi2::putScom(i_target, l_nest_clk_scandata0_addr, l_nest_clk_scandata0_data));
    }

    // scan 72837..76490 (33*110 + 23)
    for (auto ii = 0; ii < 33; ii++)
    {
        FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x6E, l_nest_clk_scandata0_data));
    }

    FAPI_TRY(fapi2::getScom(i_target, l_nest_clk_scandata0_addr + 0x17, l_nest_clk_scandata0_data));

    // check header
    FAPI_ASSERT((l_nest_clk_scandata0_data == 0xA5A55A5A00000000),
                fapi2::CEN_INITF_HEADER_MISMATCH().set_TARGET(i_target),
                "Error rotating tcn_mbs_func ring -- header mismatch!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
