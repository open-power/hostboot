/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_throttle_sync.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_throttle_sync.H
///
/// @brief Perform p9_throttle_sync HWP
///
/// The purpose of this procedure is to triggers sync command from a 'master'
/// MC to other MCs that have attached memory in a processor.
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 2
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_throttle_sync.H>
#include <fapi2.H>
#include <lib/utils/find.H>

///----------------------------------------------------------------------------
/// Constant definitions
///----------------------------------------------------------------------------
const uint8_t SUPER_SYNC_BIT   = 14;
const uint8_t MAX_MC_SIDES_PER_PROC = 2; // MC01, MC23

// Structure that holds the potential master MCS for a MC side (MC01/MC23)
struct mcSideInfo_t
{
    bool masterMcsFound = false;
    // Master MCS for this MC side
    fapi2::Target<fapi2::TARGET_TYPE_MCS> masterMcs;
};


///
/// @brief Programming master MCS
///        Writes MCS_MCSYNC reg to set the input MCS as the master.
///
/// @param[in]  i_mcsTarget  The MCS target to be programmed as master.
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode progMasterMcs(
    const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_mcsTarget)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    fapi2::buffer<uint64_t> l_scomMask(0);

    // -------------------------------------------------------------------
    // 1. Reset sync command
    // -------------------------------------------------------------------

    // Note:
    // MCS_MCSYNC reg bit 16 is now used to setup SYNC_GO for both channels.
    // Bit 17 is now reserved (it was MCS_MCSYNC_SYNC_GO_CH1 before)
    //   REGISTER MCSYNC(mcsync(0:27), 0x000000000);
    //      MCSYNC.address(SCOM) += 0x00000015;
    //      MCSYNC.comment = "MC Sync Command Register (MCSYNC)";
    //      MCSYNC.attr(part_decl) = "0:7   = MCSYNC_Channel_Select"
    //                               "8:15  = MCSYNC_Sync_Type"
    //                               "16    = MCSYNC_Sync_Go"
    //                               "17:27 = MCSYNC_Reserved";
    //      MCSYNC.attr(access) = "**::SCOM = RW";
    //      MCSYNC.attr(parity) = "mcSYNC_pe";
    //      MCSYNC.attr(wpulse) = "act_sc15";

    l_scomMask.flush<0>().setBit<MCS_MCSYNC_SYNC_GO_CH0>();
    l_scomData.flush<0>();
    FAPI_TRY(fapi2::putScomUnderMask(i_mcsTarget, MCS_MCSYNC,
                                     l_scomData, l_scomMask),
             "putScomUnderMask() returns an error (Sync reset), Addr 0x%.16llX",
             MCS_MCSYNC);

    // --------------------------------------------------------------
    // 2. Setup MC Sync Command Register data for master MCS
    // --------------------------------------------------------------
    // Clear buffers
    l_scomData.flush<0>();
    l_scomMask.flush<0>();

    // Setup MCSYNC_CHANNEL_SELECT
    // Set ALL channels with or without DIMMs (bits 0:7)
    l_scomData.setBit<MCS_MCSYNC_CHANNEL_SELECT,
                      MCS_MCSYNC_CHANNEL_SELECT_LEN>();
    l_scomMask.setBit<MCS_MCSYNC_CHANNEL_SELECT,
                      MCS_MCSYNC_CHANNEL_SELECT_LEN>();

    // Setup MCSYNC_SYNC_TYPE
    // Set all sync types except Super Sync
    l_scomData.setBit<MCS_MCSYNC_SYNC_TYPE,
                      MCS_MCSYNC_SYNC_TYPE_LEN>().clearBit(SUPER_SYNC_BIT);
    l_scomMask.setBit<MCS_MCSYNC_SYNC_TYPE,
                      MCS_MCSYNC_SYNC_TYPE_LEN>();

    // Setup SYNC_GO (bit 16 is now used for both channels)
    l_scomMask.setBit<MCS_MCSYNC_SYNC_GO_CH0>();
    l_scomData.setBit<MCS_MCSYNC_SYNC_GO_CH0>();

    // --------------------------------------------------------------
    // 3. Write to MC Sync Command Register of master MCS
    // --------------------------------------------------------------
    // Write to MCSYNC reg
    FAPI_INF("Writing MCS_MCSYNC reg 0x%.16llX: Mask 0x%.16llX , Data 0x%.16llX",
             MCS_MCSYNC, l_scomMask, l_scomData);

    FAPI_TRY(fapi2::putScomUnderMask(i_mcsTarget, MCS_MCSYNC,
                                     l_scomData, l_scomMask),
             "putScomUnderMask() returns an error (Sync), MCS_MCSYNC reg 0x%.16llX",
             MCS_MCSYNC);

    // Note: No need to read Sync replay count and retry in P9.

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}


///
/// @brief Perform throttle sync on the Memory Controllers
///
/// @tparam T template parameter, passed in targets.
/// @param[in]  i_mcTargets     Vector of reference of MC targets (MCS or MI)
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template< fapi2::TargetType T>
fapi2::ReturnCode throttleSync(
    const std::vector< fapi2::Target<T> >& i_mcTargets);

/// TARGET_TYPE_MCS
template<>
fapi2::ReturnCode throttleSync(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_mcTargets)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    mcSideInfo_t l_mcSide[MAX_MC_SIDES_PER_PROC];
    uint8_t l_sideNum = 0;
    uint8_t l_pos = 0;
    uint8_t l_numMasterProgrammed = 0;

    // Initialization
    for (l_sideNum = 0; l_sideNum < MAX_MC_SIDES_PER_PROC; l_sideNum++)
    {
        l_mcSide[l_sideNum].masterMcsFound = false;
    }

    // ---------------------------------------------------------------------
    // 1. Pick the first MCS with DIMMS as potential master
    //    for both MC sides (MC01/MC23)
    // ---------------------------------------------------------------------
    for (auto l_mcs : i_mcTargets)
    {
        std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms =
            mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_mcs);

        if (l_dimms.size() > 0)
        {
            // This MCS has DIMMs attached, find out which MC side it
            // belongs to:
            //    l_sideNum = 0 --> MC01
            //                1 --> MC23
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mcs,
                                   l_pos),
                     "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
            l_sideNum = l_pos / MAX_MC_SIDES_PER_PROC;

            FAPI_INF("MCS %u has DIMMs", l_pos);

            // If there's no master MCS marked for this side yet, mark
            // this MCS as master
            if (l_mcSide[l_sideNum].masterMcsFound == false)
            {
                FAPI_INF("Mark MCS %u as master for MC side %u",
                         l_pos, l_sideNum);
                l_mcSide[l_sideNum].masterMcsFound = true;
                l_mcSide[l_sideNum].masterMcs = l_mcs;
            }
        }
    }

    // --------------------------------------------------------------
    // 2. Program the master MCS
    // --------------------------------------------------------------
    for (l_sideNum = 0; l_sideNum < MAX_MC_SIDES_PER_PROC; l_sideNum++)
    {
        // If there is a potential master MCS found for this side
        if (l_mcSide[l_sideNum].masterMcsFound == true)
        {
            // No master MCS programmed for either side yet,
            // go ahead and program this MCS as master.
            if (l_numMasterProgrammed == 0)
            {
                FAPI_TRY(progMasterMcs(l_mcSide[l_sideNum].masterMcs),
                         "programMasterMcs() returns error"
                         "NumMasterProgrammed %d, l_rc 0x%.8X",
                         l_numMasterProgrammed, (uint64_t)fapi2::current_err);
                l_numMasterProgrammed++;
            }
            else
            {
                // A master MCS is already programmed on MC side 0 (MC01).
                // HW397255 requires to also program a master MCS on MC23 if
                // it has DIMMs.
                fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chip =
                    l_mcSide[l_sideNum].masterMcs.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
                fapi2::ATTR_CHIP_EC_FEATURE_HW397255_Type l_HW397255_enabled;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW397255,
                                       l_chip, l_HW397255_enabled),
                         "Error getting the ATTR_CHIP_EC_FEATURE_HW397255");

                if (l_HW397255_enabled)
                {
                    FAPI_TRY(progMasterMcs(l_mcSide[l_sideNum].masterMcs),
                             "programMasterMcs() returns error"
                             "NumMasterProgrammed %d, l_rc 0x%.8X",
                             l_numMasterProgrammed, (uint64_t)fapi2::current_err);
                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

/// TARGET_TYPE_MI
template<>
fapi2::ReturnCode throttleSync(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MI> >& i_mcTargets)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Note: Add code for Cumulus

    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

extern "C"
{

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------

///
/// @brief p9_throttle_sync procedure entry point
/// See doxygen in p9_throttle_sync.H
///
    fapi2::ReturnCode p9_throttle_sync(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Entering");
        fapi2::ReturnCode l_rc;

        auto l_mcsChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCS>();
        auto l_miChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();

        // Get the functional MCS on this proc
        if (l_mcsChiplets.size() > 0)
        {
            FAPI_TRY(throttleSync(l_mcsChiplets),
                     "throttleSync() returns error l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

        // Cumulus
        if (l_miChiplets.size() > 0)
        {
            FAPI_TRY(throttleSync(l_miChiplets),
                     "throttleSync() returns error l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

    fapi_try_exit:
        FAPI_DBG("Exiting");
        return fapi2::current_err;
    }

} // extern "C"
