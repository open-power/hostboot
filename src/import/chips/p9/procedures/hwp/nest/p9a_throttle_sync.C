/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9a_throttle_sync.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// ----------------------------------------------------------------------------
/// @file  p9_throttle_sync.C
///
/// @brief Perform p9_throttle_sync HWP
///
/// The purpose of this procedure is to triggers sync command from a 'master'
/// MC to other MCs that have attached memory in a processor.
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP HWP Backup  : Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 3
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9a_throttle_sync.H>
#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/shared/axone_consts.H>

///
/// @brief Program MCMODE0 based on the functional targets
///
/// @param[in]  i_mi_target   The MC target to be programmed
/// @param[in]  i_mi_targets  Other MC targets.
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode prog_MCMODE0(
    const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_mc_target,
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MI> >& i_mc_targets)
{
    FAPI_DBG("Entering prog_MCMODE0 on target %s", mss::c_str(i_mc_target));
    // --------------------------------------------------------------
    // Setup MCMODE0 for disabling MC SYNC to other-side and same-side
    // partner unit.
    // BIT27: set if other-side MC is non-functional, 0<->2, 1<->3
    // BIT28: set if same-side MC is non-functional, 0<->1, 2<->3
    // --------------------------------------------------------------
    fapi2::buffer<uint64_t> l_scomData(0);
    fapi2::buffer<uint64_t> l_scomMask(0);
    bool l_other_side_functional = false;
    bool l_same_side_functional = false;
    uint8_t l_current_pos = 0;
    uint8_t l_other_side_pos = 0;
    uint8_t l_same_side_pos = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_mc_target, l_current_pos),
             "Error getting ATTR_CHIP_UNIT_POS on %s", mss::c_str(i_mc_target));

    // Calculate the peer MC in the other side and in the same side.
    l_other_side_pos = (l_current_pos + MAX_MC_PER_SIDE) % MAX_MC_PER_PROC;
    l_same_side_pos = ((l_current_pos / MAX_MC_SIDES_PER_PROC) * MAX_MC_PER_SIDE)
                      + ((l_current_pos % MAX_MC_PER_SIDE) + 1) % MAX_MC_PER_SIDE;

    FAPI_DBG("Current pos: %i, other side pos: %i, same side pos: %i",
             l_current_pos, l_other_side_pos, l_same_side_pos);

    // Determine side functionality
    for (const auto& l_mc : i_mc_targets)
    {
        uint8_t l_tmp_pos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc, l_tmp_pos),
                 "Error getting ATTR_CHIP_UNIT_POS on %s", mss::c_str(l_mc));

        // The other side
        if (l_tmp_pos == l_other_side_pos)
        {
            l_other_side_functional = true;
        }

        // The same side
        if (l_tmp_pos == l_same_side_pos)
        {
            l_same_side_functional = true;
        }
    }

    l_scomData.flush<0>();
    l_scomMask.flush<0>();

    if (!l_other_side_functional)
    {
        l_scomData.setBit<P9A_MI_MCMODE0_DISABLE_MC_SYNC>();
        l_scomMask.setBit<P9A_MI_MCMODE0_DISABLE_MC_SYNC>();
    }
    else
    {
        l_scomData.clearBit<P9A_MI_MCMODE0_DISABLE_MC_SYNC>();
        l_scomMask.setBit<P9A_MI_MCMODE0_DISABLE_MC_SYNC>();
    }

    if (!l_same_side_functional)
    {
        l_scomData.setBit<P9A_MI_MCMODE0_DISABLE_MC_PAIR_SYNC>();
        l_scomMask.setBit<P9A_MI_MCMODE0_DISABLE_MC_PAIR_SYNC>();
    }
    else
    {
        l_scomData.clearBit<P9A_MI_MCMODE0_DISABLE_MC_PAIR_SYNC>();
        l_scomMask.setBit<P9A_MI_MCMODE0_DISABLE_MC_PAIR_SYNC>();
    }

    FAPI_DBG("Writing MCS_MCMODE0 reg 0x%016llX: Mask 0x%016llX , Data 0x%016llX",
             P9A_MI_MCMODE0, l_scomMask, l_scomData);

    FAPI_TRY(fapi2::putScomUnderMask(i_mc_target, P9A_MI_MCMODE0, l_scomData, l_scomMask),
             "putScomUnderMask() returns an error, P9A_MI_MCMODE0 reg 0x%016llX", P9A_MI_MCMODE0);

fapi_try_exit:
    FAPI_DBG("Exiting prog_MCMODE0");
    return fapi2::current_err;
}

///
/// @brief Programming master MCS
///        Writes P9A_MI_MCSYNC reg to set the input MCS as the master.
///
/// @param[in]  i_mcsTarget  The MCS target to be programmed as master.
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode prog_master(const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_mc_target)
{
    FAPI_DBG("Entering progMaster with target %s", mss::c_str(i_mc_target));
    fapi2::buffer<uint64_t> l_scomData(0);
    fapi2::buffer<uint64_t> l_scomMask(0);

    // -------------------------------------------------------------------
    // 1. Reset sync command
    // -------------------------------------------------------------------

    // Clear GO bit
    l_scomMask.flush<0>().setBit<P9A_MI_MCSYNC_SYNC_GO>();
    l_scomData.flush<0>();
    FAPI_TRY(fapi2::putScomUnderMask(i_mc_target, P9A_MI_MCSYNC, l_scomData, l_scomMask),
             "putScomUnderMask() returns an error (Reset), P9A_MI_MCSYNC reg 0x%016llX", P9A_MI_MCSYNC);

    // --------------------------------------------------------------
    // 2. Setup MC Sync Command Register data for master MCS or MI
    // --------------------------------------------------------------

    // Clear buffers
    l_scomData.flush<0>();
    l_scomMask.flush<0>();

    // Force bit set in case cleared from last procedure run
    l_scomData.setBit<EXPLR_SRQ_MBA_SYNCCNTLQ_SYNC_REF_EN>();
    l_scomMask.setBit<EXPLR_SRQ_MBA_SYNCCNTLQ_SYNC_REF_EN>();

    // Iterate through OCMBs to make sure refresh SYNC bit is set
    for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_mc_target))
    {
        FAPI_DBG("Writing EXPLR_SRQ_MBA_SYNCCNTLQ reg 0x%016llX: Data 0x%016llX Mask 0x%016llX",
                 EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomData, l_scomMask);

        FAPI_TRY(fapi2::putScomUnderMask(l_ocmb, EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomData, l_scomMask),
                 "Error writing to REG 0x%016llX of %s", EXPLR_SRQ_MBA_SYNCCNTLQ, mss::c_str(l_ocmb));
    }

    // Clear buffers
    l_scomData.flush<0>();
    l_scomMask.flush<0>();

    // Setup MCSYNC_CHANNEL_SELECT
    // Set ALL channels with or without DIMMs (bits 0:7)
    l_scomData.setBit<P9A_MI_MCSYNC_CHANNEL_SELECT,
                      P9A_MI_MCSYNC_CHANNEL_SELECT_LEN>();
    l_scomMask.setBit<P9A_MI_MCSYNC_CHANNEL_SELECT,
                      P9A_MI_MCSYNC_CHANNEL_SELECT_LEN>();

    // Setup MCSYNC_SYNC_TYPE for SYNC ALL
    l_scomData.setBit<P9A_MI_MCSYNC_SYNC_TYPE>();
    l_scomMask.setBit<P9A_MI_MCSYNC_SYNC_TYPE>();

    // Setup SYNC_GO (bit 16 is now used for both channels)
    l_scomMask.setBit<P9A_MI_MCSYNC_SYNC_GO>();
    l_scomData.setBit<P9A_MI_MCSYNC_SYNC_GO>();

    // --------------------------------------------------------------
    // 3. Write to MC Sync Command Register of master MCS or MI
    // --------------------------------------------------------------
    // Write to MCSYNC reg
    FAPI_DBG("Writing P9A_MI_MCSYNC reg 0x%016llX: Mask 0x%016llX , Data 0x%016llX",
             P9A_MI_MCSYNC, l_scomMask, l_scomData);

    FAPI_TRY(fapi2::putScomUnderMask(i_mc_target, P9A_MI_MCSYNC, l_scomData, l_scomMask),
             "putScomUnderMask() returns an error (Sync), P9A_MI_MCSYNC reg 0x%016llX", P9A_MI_MCSYNC);

    // Note: No need to read Sync replay count and retry in P9.

    // --------------------------------------------------------------
    // 4. Clear refresh sync bit
    // --------------------------------------------------------------
    l_scomData.flush<0>();
    l_scomMask.flush<0>().setBit<EXPLR_SRQ_MBA_SYNCCNTLQ_SYNC_REF_EN>();

    // Iterate through OCMBs to clear refresh sync bit
    for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_mc_target))
    {
        FAPI_DBG("Writing EXPLR_SRQ_MBA_SYNCCNTLQ reg 0x%016llX: Mask 0x%016llX , Data 0x%016llX on %s",
                 EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomMask, l_scomData, mss::c_str(l_ocmb));

        FAPI_TRY(fapi2::putScomUnderMask(l_ocmb, EXPLR_SRQ_MBA_SYNCCNTLQ, l_scomData, l_scomMask),
                 "putScomUnderMask() returns an error (Sync), EXPLR_SRQ_MBA_SYNCCNTLQ reg 0x%016llX",
                 EXPLR_SRQ_MBA_SYNCCNTLQ);
    }

fapi_try_exit:
    FAPI_DBG("Exiting progMaster");
    return fapi2::current_err;
}

///
/// @brief Perform throttle sync on the Memory Controllers
///
/// @param[in]  i_mc_targets vector of reference of MC targets (MCS or MI)
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode throttle_sync(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MI> >& i_mc_targets)
{
    mc_side_info_t l_mcSide[MAX_MC_SIDES_PER_PROC];
    uint8_t l_sideNum = 0;
    uint8_t l_pos = 0;
    uint8_t l_numMasterProgrammed = 0;

    // Initialization
    for (l_sideNum = 0; l_sideNum < MAX_MC_SIDES_PER_PROC; l_sideNum++)
    {
        l_mcSide[l_sideNum].master_mc_found = false;
    }

    // ---------------------------------------------------------------------
    // 1. Pick the first MCS/MI with DIMMS as potential master
    //    for both MC sides (MC01/MC23)
    // ---------------------------------------------------------------------
    for (const auto& l_mc : i_mc_targets)
    {
        uint8_t l_num_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_mc).size();

        if (l_num_dimms > 0)
        {
            // This MCS or MI has DIMMs attached, find out which MC side it
            // belongs to:
            //    l_sideNum = 0 --> MC01
            //                1 --> MC23
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc, l_pos),
                     "Error getting ATTR_CHIP_UNIT_POS on %s", mss::c_str(l_mc));
            l_sideNum = l_pos / MAX_MC_SIDES_PER_PROC;

            FAPI_INF("MCS %u has DIMMs", l_pos);

            // If there's no master MCS or MI marked for this side yet, mark
            // this MCS as master
            if (l_mcSide[l_sideNum].master_mc_found == false)
            {
                FAPI_INF("Mark MCS %u as master for MC side %u",
                         l_pos, l_sideNum);
                l_mcSide[l_sideNum].master_mc_found = true;
                l_mcSide[l_sideNum].master_mc = l_mc;
            }
        }

        prog_MCMODE0(l_mc, i_mc_targets);
    }

    // --------------------------------------------------------------
    // 2. Program the master MI
    // --------------------------------------------------------------
    for (l_sideNum = 0; l_sideNum < MAX_MC_SIDES_PER_PROC; l_sideNum++)
    {
        // If there is a potential master MI found for this side
        if (l_mcSide[l_sideNum].master_mc_found == true)
        {
            // No master MI programmed for either side yet,
            // go ahead and program this MI as master.
            if (l_numMasterProgrammed == 0)
            {
                FAPI_TRY(prog_master(l_mcSide[l_sideNum].master_mc),
                         "programMaster() returns error on %s", mss::c_str(l_mcSide[l_sideNum].master_mc));
                l_numMasterProgrammed++;
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

extern "C"
{
    ///
    /// @brief p9a_throttle_sync procedure
    ///
    /// @param[in] i_target TARGET_TYPE_PROC_CHIP target
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode p9a_throttle_sync(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Executing p9a_throttle_sync on %s", mss::c_str(i_target));

        const auto l_miChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();

        if (l_miChiplets.size() > 0)
        {
            FAPI_TRY(throttle_sync(l_miChiplets), "Error calling throttle_sync() with vector of MI Chiplets");
        }

    fapi_try_exit:
        FAPI_DBG("Exiting");
        return fapi2::current_err;
    }

} // extern "C"
