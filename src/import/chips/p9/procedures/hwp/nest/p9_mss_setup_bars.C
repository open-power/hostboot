/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_mss_setup_bars.C $            */
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
/// @file  p9_mss_setup_bars.H
///
/// @brief  Program memory controller base address registers (BARs)
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_mss_setup_bars.H>
#include <p9_mss_eff_grouping.H>

///----------------------------------------------------------------------------
/// Constant definitions
///----------------------------------------------------------------------------

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------
///
/// @brief Setup the non-mirrored BAR registers for an MC target
///
/// @param[in]    i_target     Reference to an MC target
/// @param[in]    i_groupData  Array of groupData info to be used to setup BARs
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode setupNonMirrorBar( const fapi2::Target<T>& i_target,
                                     uint32_t i_groupData[][DATA_ELEMENTS]);
// Specialization for MCS target
template<>
fapi2::ReturnCode setupNonMirrorBar(
    const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
    uint32_t i_groupData[][DATA_ELEMENTS])
{
    FAPI_INF("Setup non-mirrored BARs for MCS");
    fapi2::ReturnCode l_rc;
    uint8_t l_unitPos = 0;

    // Get MC position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unitPos),
             "setupNonMirrorBar: Error getting ATTR_CHIP_UNIT_POS, "
             "l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    //TODO: Add code to write to BARs

fapi_try_exit:
    return fapi2::current_err;
}

// Specialization for MI target
template<>
fapi2::ReturnCode setupNonMirrorBar(
    const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
    uint32_t i_groupData[][DATA_ELEMENTS])
{
    FAPI_INF("Setup non-mirrored BARs for MI");
    fapi2::ReturnCode l_rc;
    uint8_t l_unitPos = 0;

    // Get MC position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unitPos),
             "setupNonMirrorBar: Error getting ATTR_CHIP_UNIT_POS, "
             "l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    //TODO: Add code to write to BARs

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup the mirrored BAR registers for an MC target
///
/// @param[in]    i_target     Reference to an MC target
/// @param[in]    i_groupData  Array of groupData info to be used to setup BARs
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode setupMirrorBar(const fapi2::Target<T>& i_target,
                                 uint32_t i_groupData[][DATA_ELEMENTS]);

// Specialization for MCS target
template<>
fapi2::ReturnCode setupMirrorBar(
    const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
    uint32_t i_groupData[][DATA_ELEMENTS])
{
    FAPI_INF("Setup mirrored BARs for MCS");
    fapi2::ReturnCode l_rc;
    uint8_t l_unitPos = 0;

    // Get MC position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unitPos),
             "setupMirrorBar: Error getting ATTR_CHIP_UNIT_POS, "
             "l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    //TODO: Add code to write to BARs

fapi_try_exit:
    return fapi2::current_err;
}

// Specialization for MI target
template<>
fapi2::ReturnCode setupMirrorBar(
    const fapi2::Target<fapi2::TARGET_TYPE_MI>& i_target,
    uint32_t i_groupData[][DATA_ELEMENTS])
{
    FAPI_INF("Setup mirrored BARs for MI");
    fapi2::ReturnCode l_rc;
    uint8_t l_unitPos = 0;

    // Get MC position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unitPos),
             "setupMirrorBar: Error getting ATTR_CHIP_UNIT_POS, "
             "l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    //TODO: Add code to write to BARs

fapi_try_exit:
    return fapi2::current_err;
}

extern "C" {

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------

///
/// @brief p9_mss_setup_bars procedure entry point
/// See doxygen in p9_mss_setup_bars.H
///
    fapi2::ReturnCode p9_mss_setup_bars(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Entering p9_mss_setup_bars");
        fapi2::ReturnCode l_rc;
        uint8_t l_enhancedNoMirrorMode = 0;
        uint32_t l_groupData[DATA_GROUPS][DATA_ELEMENTS] = { {0} };
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        // Get the MCS chiplets, should be none for Cumulus
        auto l_mcsChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCS>();
        // Get the MI chiplets, , should be none for Nimbus
        auto l_miChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MI>();

        // Get enhanced grouping option
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING,
                               FAPI_SYSTEM, l_enhancedNoMirrorMode),
                 "p9_mss_setup_bars: Error getting "
                 "ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get group data setup by p9_mss_eff_grouping
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MCS_GROUP_32, i_target,
                               l_groupData),
                 "p9_mss_setup_bars: Error getting ATTR_MSS_MCS_GROUP_32, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        // Setup BARs for MCS
        for (auto mcs_itr = l_mcsChiplets.begin();
             mcs_itr != l_mcsChiplets.end();
             ++mcs_itr)
        {
            // Setup non-mirrored BARs on MC
            FAPI_TRY(setupNonMirrorBar((*mcs_itr), l_groupData),
                     "p9_mss_setup_bars: setupNonMirrorBar() returns error, "
                     "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

            // Setup mirrored BARs on MC
            if (l_enhancedNoMirrorMode == false)
            {
                FAPI_TRY(setupMirrorBar((*mcs_itr), l_groupData),
                         "p9_mss_setup_bars: setupMirrorBar() returns error, "
                         "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
            }
        }

        // Setup BARs for MIs
        for (auto mi_itr = l_miChiplets.begin();
             mi_itr != l_miChiplets.end();
             ++mi_itr)
        {
            // Setup non-mirrored BARs on MC
            FAPI_TRY(setupNonMirrorBar((*mi_itr), l_groupData),
                     "p9_mss_setup_bars: setupNonMirrorBar() returns error, "
                     "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

            // Setup mirrored BARs on MC
            if (l_enhancedNoMirrorMode == false)
            {
                FAPI_TRY(setupMirrorBar((*mi_itr), l_groupData),
                         "p9_mss_setup_bars: setupMirrorBar() returns error, "
                         "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting p9_mss_setup_bars");

        return fapi2::current_err;
    }

} // extern "C"
