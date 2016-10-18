/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_throttle_sync.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
    fapi2::buffer<uint64_t> l_scomData(0);
    fapi2::buffer<uint64_t> l_scomMask(0);
    bool l_mcaWithDimm[MAX_MCA_PER_PROC];
    fapi2::Target<fapi2::TARGET_TYPE_MCS> l_masterMcs;
    fapi2::Target<fapi2::TARGET_TYPE_MCA> l_mca;
    uint8_t l_masterMcsPos = 0;
    uint8_t l_mcaPos = 0;

    // Initialize
    memset(l_mcaWithDimm, false, sizeof(l_mcaWithDimm));

    // --------------------------------------------------------------
    // 1. Determine the 'master' MCS and mark which MCA ports have
    //    dimms attached
    // --------------------------------------------------------------
    bool l_masterMcsFound = false;

    for (auto l_mcs :  i_mcTargets)
    {
        // Find first MCS that has DIMM attached
        std::vector< fapi2::Target<fapi2::TARGET_TYPE_DIMM> > l_dimms =
            mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_mcs);

        if (l_dimms.size() > 0)
        {
            // Set first MCS with DIMM attached to be master
            if (l_masterMcsFound == false)
            {
                l_masterMcs = l_mcs;
                l_masterMcsFound = true;
            }

            // Loop over the DIMM list to mark the MCAs that own them
            for (auto l_thisDimm : l_dimms)
            {
                l_mca = mss::find_target<fapi2::TARGET_TYPE_MCA>(l_thisDimm);
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mca, l_mcaPos),
                         "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
                l_mcaWithDimm[l_mcaPos] = true;
            }
        }
    }

    // No master found
    if (l_masterMcsFound == false)
    {
        // Nothing to do with this proc, exit
        // Note: This is a common scenario on Cronus platform.
        goto fapi_try_exit;
    }

    // Display MCS/MCA with DIMM attached
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_masterMcs,
                           l_masterMcsPos),
             "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_INF("Master MCS pos %u", l_masterMcsPos);
    FAPI_DBG("MCA with DIMM attached:");

    for (uint8_t ii = 0; ii < MAX_MCA_PER_PROC; ii++)
    {
        FAPI_DBG("    MCA[%u] %u", ii, l_mcaWithDimm[ii]);
    }

    // -------------------------------------------------------------------
    // 2. Reset sync command on both channels to make sure they are clean
    // -------------------------------------------------------------------
    // Reset the sync command on both channels to make sure they are clean
    l_scomMask.flush<0>().setBit<MCS_MCSYNC_SYNC_GO_CH0>();
    l_scomData.flush<0>();

    FAPI_TRY(fapi2::putScomUnderMask(l_masterMcs, MCS_MCSYNC,
                                     l_scomData, l_scomMask),
             "putScomUnderMask() returns an error (Sync reset), Addr 0x%.16llX",
             MCS_MCSYNC);

    // --------------------------------------------------------------
    // 3. Setup MC Sync Command Register data for master MCS
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

    // Setup SYNC_GO, pick either MCA port of the master MCS, but the port
    // must have DIMM connected.
    l_mcaPos = l_masterMcsPos * 2; // 1st MCS postion of the master MCS

    if (l_mcaWithDimm[l_mcaPos] == true)
    {
        l_scomMask.setBit<MCS_MCSYNC_SYNC_GO_CH0>();
        l_scomData.setBit<MCS_MCSYNC_SYNC_GO_CH0>();
    }

    // --------------------------------------------------------------
    // 4. Write to MC Sync Command Register of master MCS
    // --------------------------------------------------------------

    // Write to MCSYNC reg
    FAPI_INF("Writing MCS_MCSYNC reg 0x%.16llX: Mask 0x%.16llX , Data 0x%.16llX",
             MCS_MCSYNC, l_scomMask, l_scomData);

    FAPI_TRY(fapi2::putScomUnderMask(l_masterMcs, MCS_MCSYNC,
                                     l_scomData, l_scomMask),
             "putScomUnderMask() returns an error (Sync), MCS_MCSYNC reg 0x%.16llX",
             MCS_MCSYNC);

    // Note: No need to read Sync replay count and retry in P9.

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
