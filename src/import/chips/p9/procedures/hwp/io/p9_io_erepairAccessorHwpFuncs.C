/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_erepairAccessorHwpFuncs.C $ */
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
///
/// @file p9_io_erepairAccessorHwpFuncs.C
/// @brief FW Team utility functions that access fabric and memory eRepair data.
///
//----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_io_erepairAccessorHwpFuncs.H>
#include <string.h>
#include <p9_io_erepairConsts.H>
#include <p9_io_erepairSetFailedLanesHwp.H>
#include <p9_io_erepairGetFailedLanesHwp.H>

using namespace EREPAIR;
using namespace fapi2;

/** Forward Declarations **/

/**
 * @brief: This function reads the field VPD data to check if there is any
 *         eRepair data. This function will be called during Mnfg mode IPL
 *         during which we need to make sure that the Field VPD is clear.
 *         The Field VPD needs to be clear to enable customers to have
 *         eRepair capability.
 *
 * @param [in]   i_endp1_target  Target of one end the connecting bus
 * @param [in]   i_endp2_target  Target of the other end of the connecting bus
 *                               The VPD of the passed targets are read for
 *                               checking the VPD contents
 * @param[in]    i_clkGroup      Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K, fapi2::TargetType J>
fapi2::ReturnCode mnfgCheckFieldVPD(
    const fapi2::Target < K >&          i_endp1_target,
    const fapi2::Target < J >&          i_endp2_target,
    const uint8_t                     i_clkGroup);


/**
 * @brief: This Function reads the specified VPD (Mnfg or Field) of the passed
 *         targets and verifies whether there are matching eRepair records.
 *         The matching eRepair lanes are returned in the passed references
 *         for vectors.
 *
 * @param [in]  i_endp1_target       Target of one end the connecting bus
 * @param [in]  i_endp2_target       Target of the other end of the connecting
 *                                   bus
 * @param[in]   i_clkGroup           Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param [out] o_endp1_txFaillanes  Reference to vector which will have fail
 *                                   lane numbers on Tx side of target passed
 *                                   as first param
 * @param [out] o_endp1_rxFaillanes  Reference to vector which will have fail
 *                                   lane numbers on Rx side of target passed
 *                                   as first param
 * @param [out] o_endp2_txFaillanes  Reference to vector which will have fail
 *                                   lane numbers on Tx side of target passed
 *                                   as fourth param
 * @param [out] o_endp2_rxFaillanes  Reference to vector which will have fail
 *                                   lane numbers on Rx side of target passed
 *                                   as fourth param
 * @param[in]   i_clkGroup           Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param [in]  i_vpdType            Indicates whether to read Mnfg VPD or
 *                                   Field VPD
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K, fapi2::TargetType J>
fapi2::ReturnCode getVerifiedRepairLanes(
    const fapi2::Target < K >&          i_endp1_target,
    const fapi2::Target < J >&          i_endp2_target,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>& o_endp1_txFaillanes,
    std::vector<uint8_t>& o_endp1_rxFaillanes,
    std::vector<uint8_t>& o_endp2_txFaillanes,
    std::vector<uint8_t>& o_endp2_rxFaillanes,
    const erepairVpdType i_vpdType);

/**
 * @brief This function checks to see if the passed vectors have matching
 *        fail lane numbers. If no matching lane number is found, such lane
 *        value will be invalidated in the vector
 *
 * @param [in]  io_endp1_txFaillanes        Reference to vector which has fail
 *                                          lane numbers of Tx side
 * @param [in]  io_endp2_rxFaillanes        Reference to vector which has fail
 *                                          lane numbers of Rx side
 * @param [out] o_invalidFails_inTx_Ofendp1 If TRUE, indicates that Tx has fail
 *                                          lane numbers for which there is no
 *                                          matching entry on Rx side
 * @param [out] o_invalidFails_inRx_Ofendp2 If TRUE, indicates that Tx has fail
 *                                          lane numbers for which there is no
 *                                          matching entry on Tx side
 *
 * @return void
 */
void invalidateNonMatchingFailLanes(std::vector<uint8_t>& io_endp1_txFaillanes,
                                    std::vector<uint8_t>& io_endp2_rxFaillanes,
                                    bool& o_invalidFails_inTx_Ofendp1,
                                    bool& o_invalidFails_inRx_Ofendp2);

/**
 * @brief This function gets the eRepair threshold value of the passed target
 *        for the particular IPL type.
 *
 * @param [in]   i_endp_target The target for whose type the threshold value
 *                             is needed
 * @param [in]   i_mfgModeIPL  If TRUE, indicates that this is a MnfgMode IPL
 *                             If FALSE, indicates that this is a Normal IPL
 * @param [out]  o_threshold   The threshold return value
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode geteRepairThreshold(
    const fapi2::Target < K >&          i_endp_target,
    const bool         i_mfgModeIPL,
    uint8_t&            o_threshold);

/**
 * @brief This function determines the lane numbers that needs to be spared
 *        to support Corner testing.
 *
 * @param [in]  i_tgtType            The target type(XBus or OBus or DMIBus) for
 *                                   which the lanes that need to be spared are
 *                                   determined
 * @param [out] o_endp1_txFailLanes  The reference to the vector which will
 *                                   have the Tx side of lanes that need to be
 *                                   spared for endp1
 * @param [out] o_endp1_rxFailLanes  The reference to the vector which will
 *                                   have the Rx side of lanes that need to be
 *                                   spared for endp1
 * @param [out] o_endp2_txFailLanes  The reference to the vector which will
 *                                   have the Tx side of lanes that need to be
 *                                   spared for endp2
 * @param [out] o_endp2_rxFailLanes  The reference to the vector which will
 *                                   have the Rx side of lanes that need to be
 *                                   spared for endp2
 *
 * @return void
 */
template<fapi2::TargetType K>
void getCornerTestingLanes(
    const fapi2::Target < K >&          i_tgtType,
    std::vector<uint8_t>& o_endp1_txFailLanes,
    std::vector<uint8_t>& o_endp1_rxFailLanes,
    std::vector<uint8_t>& o_endp2_txFailLanes,
    std::vector<uint8_t>& o_endp2_rxFailLanes);

/**
 * @brief This function combines the eRepair lane numbers read from
 *        Manufacturing VPD and Field VPD
 *
 * @param [in]  i_mnfgFaillanes  The eRepair lane numbers read from the
 *                               Manufacturing VPD
 * @param [in]  i_fieldFaillanes The eRepair lane numbers read from the
 *                               Field VPD
 * @param [out] o_allFaillanes   The eRepair lane numbers which is the union
 *                               of the Field and Manufacturing eRepair lanes
 *                               passed as first iand second params
 *
 * @return void
 */
void combineFieldandMnfgLanes(std::vector<uint8_t>& i_mnfgFaillanes,
                              std::vector<uint8_t>& i_fieldFaillanes,
                              std::vector<uint8_t>& o_allFailLanes);


/***** Function definitions *****/

template<fapi2::TargetType K, fapi2::TargetType J>
fapi2::ReturnCode erepairGetRestoreLanes(
    const fapi2::Target < K >&          i_endp1_target,
    const fapi2::Target < J >&          i_endp2_target,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>&             o_endp1_txFaillanes,
    std::vector<uint8_t>&             o_endp1_rxFaillanes,
    std::vector<uint8_t>&             o_endp2_txFaillanes,
    std::vector<uint8_t>&             o_endp2_rxFaillanes)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    std::vector<uint8_t>    l_endp1_txFieldFaillanes;
    std::vector<uint8_t>    l_endp1_rxFieldFaillanes;
    std::vector<uint8_t>    l_endp1_txMnfgFaillanes;
    std::vector<uint8_t>    l_endp1_rxMnfgFaillanes;

    std::vector<uint8_t>    l_endp2_txFieldFaillanes;
    std::vector<uint8_t>    l_endp2_rxFieldFaillanes;
    std::vector<uint8_t>    l_endp2_txMnfgFaillanes;
    std::vector<uint8_t>    l_endp2_rxMnfgFaillanes;

    bool                    l_mnfgModeIPL          = false;
    bool                    l_enableDmiSpares      = false;
    bool                    l_enableFabricSpares   = false;
    bool                    l_disableFabricERepair = false;
    bool                    l_disableMemoryERepair = false;
    bool                    l_thresholdExceed      = false;
    uint8_t                 l_threshold            = 0;
    uint64_t                l_allMnfgFlags         = 0;
    uint32_t                l_numTxFailLanes       = 0;
    uint32_t                l_numRxFailLanes       = 0;
    fapi2::TargetType       l_endp1_tgtType = fapi2::TARGET_TYPE_NONE;
    fapi2::TargetType       l_endp2_tgtType = fapi2::TARGET_TYPE_NONE;

    FAPI_INF(">>erepairGetRestoreLanes");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MNFG_FLAGS,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_allMnfgFlags));

    // Check if MNFG_DISABLE_FABRIC_EREPAIR is enabled
    l_disableFabricERepair = false;

    if(l_allMnfgFlags &
       fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_FABRIC_eREPAIR)
    {
        l_disableFabricERepair = true;
    }

    // Check if MNFG_DISABLE_MEMORY_EREPAIR is enabled
    l_disableMemoryERepair = false;

    if(l_allMnfgFlags &
       fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_MEMORY_eREPAIR)
    {
        l_disableMemoryERepair = true;
    }

    // Check if this is Manufacturing mode IPL.
    l_mnfgModeIPL = false;

    if(l_allMnfgFlags & fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_THRESHOLDS)
    {
        l_mnfgModeIPL = true;
    }

    // Get the type of passed targets
    l_endp1_tgtType = i_endp1_target.getType();
    l_endp2_tgtType = i_endp2_target.getType();

    // Check if the correct target types are passed
    if(l_endp1_tgtType == fapi2::TARGET_TYPE_XBUS_ENDPOINT ||
       l_endp1_tgtType == fapi2::TARGET_TYPE_OBUS)
    {
        FAPI_ASSERT(l_endp1_tgtType == l_endp2_tgtType,
                    fapi2::P9_EREPAIR_RESTORE_INVALID_TARGET_PAIR()
                    .set_TARGET1(l_endp1_tgtType)
                    .set_TARGET2(l_endp2_tgtType),
                    "ERROR:erepairGetRestoreLanes: Invalid endpoint target pair");

        // Check for enablement of Fabric eRepair
        if(l_mnfgModeIPL && l_disableFabricERepair)
        {
            // Fabric eRepair has been disabled using the
            // Manufacturing policy flags
            FAPI_INF("erepairGetRestoreLanes: Fabric eRepair is disabled");
            goto fapi_try_exit;
        }
    }
    else if(l_endp1_tgtType == fapi2::TARGET_TYPE_MCS_CHIPLET ||
            l_endp1_tgtType == fapi2::TARGET_TYPE_MEMBUF_CHIP)
    {
        FAPI_ASSERT( ((l_endp1_tgtType == fapi2::TARGET_TYPE_MCS_CHIPLET) &&
                      (l_endp2_tgtType == fapi2::TARGET_TYPE_MEMBUF_CHIP)) ||
                     ((l_endp1_tgtType == fapi2::TARGET_TYPE_MEMBUF_CHIP) &&
                      (l_endp2_tgtType == fapi2::TARGET_TYPE_MCS_CHIPLET)),
                     fapi2::P9_EREPAIR_RESTORE_INVALID_TARGET_PAIR()
                     .set_TARGET1(l_endp1_tgtType)
                     .set_TARGET2(l_endp2_tgtType),
                     "ERROR:erepairGetRestoreLanes: Invalid endpoint target pair");

        // Check for enablement of Memory eRepair
        if(l_mnfgModeIPL && l_disableMemoryERepair)
        {
            // Memory eRepair has been disabled using the
            // Manufacturing policy flags
            FAPI_INF("erepairGetRestoreLanes: Memory eRepair is disabled");
            goto fapi_try_exit;
        }
    }

    if(l_mnfgModeIPL)
    {
        /***** Check Field VPD *****/

        // Do not allow eRepair data in Field VPD during Mfg Mode IPL
        l_rc = mnfgCheckFieldVPD(i_endp1_target,
                                 i_endp2_target,
                                 i_clkGroup);

        if(l_rc)
        {
            FAPI_DBG("erepairGetRestoreLanes:Error from mnfgCheckFieldVPD");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        /***** Read Manufacturing VPD *****/
        FAPI_TRY( getVerifiedRepairLanes(
                      i_endp1_target,
                      i_endp2_target,
                      i_clkGroup,
                      o_endp1_txFaillanes,
                      o_endp1_rxFaillanes,
                      o_endp2_txFaillanes,
                      o_endp2_rxFaillanes,
                      EREPAIR_VPD_MNFG),
                  "getVerifiedRepairLanes(Mnfg) mnfg mode ipl failed w/rc=0x%x",
                  (uint64_t)current_err );
    }
    else
    {
        /***** Normal Mode IPL *****/
        // During Normal mode IPL we read both Mnfg and Field VPD
        // for restoring eRepair lanes

        /***** Read Manufacturing VPD *****/
        FAPI_TRY( getVerifiedRepairLanes(
                      i_endp1_target,
                      i_endp2_target,
                      i_clkGroup,
                      l_endp1_txMnfgFaillanes,
                      l_endp1_rxMnfgFaillanes,
                      l_endp2_txMnfgFaillanes,
                      l_endp2_rxMnfgFaillanes,
                      EREPAIR_VPD_MNFG),
                  "getVerifiedRepairLanes(Mnfg) normal mode ipl failed w/rc=0x%x",
                  (uint64_t)current_err );

        /***** Read Field VPD *****/
        FAPI_TRY( getVerifiedRepairLanes(
                      i_endp1_target,
                      i_endp2_target,
                      i_clkGroup,
                      l_endp1_txFieldFaillanes,
                      l_endp1_rxFieldFaillanes,
                      l_endp2_txFieldFaillanes,
                      l_endp2_rxFieldFaillanes,
                      EREPAIR_VPD_FIELD),
                  "getVerifiedRepairLanes(Field) normal mode ipl failed w/rc=0x%x",
                  (uint64_t)current_err );

        /***** Combine the Mnfg and Field eRepair lanes *****/

        // Combine the Tx side fail lanes of endp1
        combineFieldandMnfgLanes(l_endp1_txMnfgFaillanes,
                                 l_endp1_txFieldFaillanes,
                                 o_endp1_txFaillanes);

        // Combine the Rx side fail lanes of endp1
        combineFieldandMnfgLanes(l_endp1_rxMnfgFaillanes,
                                 l_endp1_rxFieldFaillanes,
                                 o_endp1_rxFaillanes);

        // Combine the Tx side fail lanes of endp2
        combineFieldandMnfgLanes(l_endp2_txMnfgFaillanes,
                                 l_endp2_txFieldFaillanes,
                                 o_endp2_txFaillanes);

        // Combine the Rx side fail lanes of endp1
        combineFieldandMnfgLanes(l_endp2_rxMnfgFaillanes,
                                 l_endp2_rxFieldFaillanes,
                                 o_endp2_rxFaillanes);

    } // end of else block of "if(l_mnfgModeIPL)"


    /***** Check for threshold exceed conditions *****/

    // Get the eRepair threshold limit
    l_threshold = 0;
    FAPI_TRY( geteRepairThreshold(
                  i_endp1_target,
                  l_mnfgModeIPL,
                  l_threshold),
              "geteRepairThreshold() failed w/rc=0x%x",
              (uint64_t)current_err );

    // Check if the eRepair threshold has exceeded for Tx side of endp1
    if(o_endp1_txFaillanes.size() > l_threshold)
    {
        l_thresholdExceed = true;
        l_numTxFailLanes = o_endp1_txFaillanes.size();

        FAPI_DBG("erepairGetRestoreLanes: eRepair threshold exceed error"
                 " seen in Tx of endp1 target. No.of lanes: %d", l_numTxFailLanes);
    }

    // Check if the eRepair threshold has exceeded for Rx side of endp1
    if(o_endp1_rxFaillanes.size() > l_threshold)
    {
        l_thresholdExceed = true;
        l_numRxFailLanes = o_endp1_rxFaillanes.size();

        FAPI_DBG("erepairGetRestoreLanes: eRepair threshold exceed error"
                 " seen in Rx of endp1 target. No.of lanes: %d", l_numRxFailLanes);
    }

    // Check if the eRepair threshold has exceeded for Tx side of endp2
    if(o_endp2_txFaillanes.size() > l_threshold)
    {
        l_thresholdExceed = true;
        l_numTxFailLanes = o_endp2_txFaillanes.size();

        FAPI_DBG("erepairGetRestoreLanes: eRepair threshold exceed error"
                 " seen in Tx of endp2 target. No.of lanes: %d",
                 l_numTxFailLanes);
    }

    // Check if the eRepair threshold has exceeded for Rx side of endp2
    if(o_endp2_rxFaillanes.size() > l_threshold)
    {
        l_thresholdExceed = true;
        l_numRxFailLanes = o_endp2_rxFaillanes.size();

        FAPI_DBG("erepairGetRestoreLanes: eRepair threshold exceed error"
                 " seen in Rx of endp2 target. No.of lanes: %d",
                 l_numRxFailLanes);
    }

    FAPI_ASSERT(l_thresholdExceed == false,
                fapi2::P9_EREPAIR_THRESHOLD_EXCEED()
                .set_TX_NUM_LANES(l_numTxFailLanes)
                .set_RX_NUM_LANES(l_numTxFailLanes)
                .set_THRESHOLD(l_threshold),
                "ERROR:The threshold limit for eRepair has been crossed");

    if(l_mnfgModeIPL)
    {
        // Check if MNFG_DMI_DEPLOY_LANE_SPARES is enabled
        l_enableDmiSpares = false;

        if(l_allMnfgFlags &
           fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DMI_DEPLOY_LANE_SPARES)
        {
            l_enableDmiSpares = true;
        }

        // Check if MNFG_FABRIC_DEPLOY_LANE_SPARES is enabled
        l_enableFabricSpares = false;

        if(l_allMnfgFlags &
           fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_FABRIC_DEPLOY_LANE_SPARES)
        {
            l_enableFabricSpares = true;
        }

        if(l_enableDmiSpares || l_enableFabricSpares)
        {
            // This is a Corner testing IPL.
            // eRepair Restore the pre-determined memory lanes
            getCornerTestingLanes(i_endp1_target,
                                  o_endp1_txFaillanes,
                                  o_endp1_rxFaillanes,
                                  o_endp2_txFaillanes,
                                  o_endp2_rxFaillanes);
        }
    } // end of if(l_mnfgModeIPL)

fapi_try_exit:
    return fapi2::current_err;
}

template ReturnCode erepairGetRestoreLanes<TARGET_TYPE_XBUS, TARGET_TYPE_XBUS>(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&          i_endp1_target,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&          i_endp2_target,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>&             o_endp1_txFaillanes,
    std::vector<uint8_t>&             o_endp1_rxFaillanes,
    std::vector<uint8_t>&             o_endp2_txFaillanes,
    std::vector<uint8_t>&             o_endp2_rxFaillanes);


void combineFieldandMnfgLanes(std::vector<uint8_t>& i_mnfgFaillanes,
                              std::vector<uint8_t>& i_fieldFaillanes,
                              std::vector<uint8_t>& o_allFaillanes)
{
    std::vector<uint8_t>::iterator l_it;

    // Merge the Field and Mnfg fail lanes
    l_it = o_allFaillanes.begin();
    o_allFaillanes.insert(l_it,
                          i_mnfgFaillanes.begin(),
                          i_mnfgFaillanes.end());

    l_it = o_allFaillanes.end();
    o_allFaillanes.insert(l_it,
                          i_fieldFaillanes.begin(),
                          i_fieldFaillanes.end());

    // Check if Mfg VPD and Field VPD have same fail lanes.
    // If found, erase them
    std::sort(o_allFaillanes.begin(), o_allFaillanes.end());

    o_allFaillanes.erase(std::unique(o_allFaillanes.begin(),
                                     o_allFaillanes.end()),
                         o_allFaillanes.end());

}

template<fapi2::TargetType K>
void getCornerTestingLanes(
    const fapi2::Target < K >&          i_tgtType,
    std::vector<uint8_t>& o_endp1_txFaillanes,
    std::vector<uint8_t>& o_endp1_rxFaillanes,
    std::vector<uint8_t>& o_endp2_txFaillanes,
    std::vector<uint8_t>& o_endp2_rxFaillanes)
{
    std::vector<uint8_t>::iterator l_it;
    uint8_t l_deployIndx = 0;
    uint8_t l_maxDeploys = 0;
    uint8_t* l_deployPtr = NULL;

    uint8_t l_xDeployLanes[XBUS_MAXSPARES_IN_HW] = {XBUS_SPARE_DEPLOY_LANE_1};
    uint8_t l_oDeployLanes[OBUS_MAXSPARES_IN_HW] = {OBUS_SPARE_DEPLOY_LANE_1,
                                                    OBUS_SPARE_DEPLOY_LANE_2
                                                   };

    uint8_t l_dmiDeployLanes[DMIBUS_MAXSPARES_IN_HW] =
    {
        DMIBUS_SPARE_DEPLOY_LANE_1,
        DMIBUS_SPARE_DEPLOY_LANE_2
    };

    // Idea is to push_back the pre-determined lanes into the Tx and Rx
    // vectors of endpoint1 and endpoint2
    switch(i_tgtType.getType())
    {
        case fapi2::TARGET_TYPE_XBUS_ENDPOINT:
            l_maxDeploys = XBUS_MAXSPARES_IN_HW;
            l_deployPtr = l_xDeployLanes;
            break;

        case fapi2::TARGET_TYPE_OBUS:
            l_maxDeploys = OBUS_MAXSPARES_IN_HW;
            l_deployPtr = l_oDeployLanes;
            break;

        case fapi2::TARGET_TYPE_MCS_CHIPLET:
        case fapi2::TARGET_TYPE_MEMBUF_CHIP:
            l_maxDeploys = DMIBUS_MAXSPARES_IN_HW;
            l_deployPtr = l_dmiDeployLanes;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::P9_EREPAIR_RESTORE_INVALID_TARGET()
                        .set_TARGET(i_tgtType),
                        "ERROR:getCornerTestingLanes: Invalid target type");
            break;
    };

    std::sort(o_endp1_txFaillanes.begin(), o_endp1_txFaillanes.end());

    std::sort(o_endp1_rxFaillanes.begin(), o_endp1_rxFaillanes.end());

    for(l_deployIndx = 0;
        ((l_deployIndx < l_maxDeploys) &&
         (o_endp1_txFaillanes.size() < l_maxDeploys));
        l_deployIndx++)
    {
        l_it = std::find(o_endp1_txFaillanes.begin(),
                         o_endp1_txFaillanes.end(),
                         l_deployPtr[l_deployIndx]);

        if(l_it == o_endp1_txFaillanes.end())
        {
            o_endp1_txFaillanes.push_back(l_deployPtr[l_deployIndx]);
        }
    }

    for(l_deployIndx = 0;
        ((o_endp1_rxFaillanes.size() < l_maxDeploys) &&
         (l_deployIndx < l_maxDeploys));
        l_deployIndx++)
    {
        l_it = std::find(o_endp1_rxFaillanes.begin(),
                         o_endp1_rxFaillanes.end(),
                         l_deployPtr[l_deployIndx]);

        if(l_it == o_endp1_rxFaillanes.end())
        {
            o_endp1_rxFaillanes.push_back(l_deployPtr[l_deployIndx]);
        }
    }

    // We can cassign the lanes of endpoint1 to endpoint2 because any
    // existing faillanes in endpoint2 have already been matched with
    // endpoint1. This means that there cannot be any faillanes in
    // endpoint2 that do not have equivalent lanes in endpoint1.
    o_endp2_txFaillanes = o_endp1_txFaillanes;
    o_endp2_rxFaillanes = o_endp1_rxFaillanes;

fapi_try_exit:
    return;
}

template<fapi2::TargetType K>
fapi2::ReturnCode geteRepairThreshold(
    const fapi2::Target < K >&          i_endp_target,
    const bool         i_mfgModeIPL,
    uint8_t&            o_threshold)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::TargetType l_tgtType = fapi2::TARGET_TYPE_NONE;

    o_threshold = 0;
    l_tgtType = i_endp_target.getType();

    if(i_mfgModeIPL)
    {
        switch(l_tgtType)
        {
            case fapi2::TARGET_TYPE_XBUS_ENDPOINT:
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_X_EREPAIR_THRESHOLD_MNFG,
                                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                       o_threshold));
                break;

            case fapi2::TARGET_TYPE_OBUS:
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_O_EREPAIR_THRESHOLD_MNFG,
                                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                       o_threshold));
                break;

            case fapi2::TARGET_TYPE_MCS_CHIPLET:
            case fapi2::TARGET_TYPE_MEMBUF_CHIP:
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DMI_EREPAIR_THRESHOLD_MNFG,
                                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                       o_threshold));
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::P9_EREPAIR_RESTORE_INVALID_TARGET()
                            .set_TARGET(l_tgtType),
                            "ERROR:geteRepairThreshold: Invalid target type");
                break;
        };
    }
    else
    {
        switch(l_tgtType)
        {
            case fapi2::TARGET_TYPE_XBUS_ENDPOINT:
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_X_EREPAIR_THRESHOLD_FIELD,
                                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                       o_threshold));
                break;

            case fapi2::TARGET_TYPE_OBUS:
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_O_EREPAIR_THRESHOLD_FIELD,
                                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                       o_threshold));
                break;

            case fapi2::TARGET_TYPE_MCS_CHIPLET:
            case fapi2::TARGET_TYPE_MEMBUF_CHIP:
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DMI_EREPAIR_THRESHOLD_FIELD,
                                       fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                       o_threshold));
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::P9_EREPAIR_RESTORE_INVALID_TARGET()
                            .set_TARGET(l_tgtType),
                            "ERROR:geteRepairThreshold: Invalid target type");
                break;
        };
    }

fapi_try_exit:
    FAPI_INF("geteRepairThreshold: o_threshold = %d", o_threshold);
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::TargetType J>
fapi2::ReturnCode mnfgCheckFieldVPD(
    const fapi2::Target < K >&          i_endp1_target,
    const fapi2::Target < J >&          i_endp2_target,
    const uint8_t                     i_clkGroup)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    std::vector<uint8_t> l_endp1_txFaillanes;
    std::vector<uint8_t> l_endp1_rxFaillanes;
    std::vector<uint8_t> l_endp2_txFaillanes;
    std::vector<uint8_t> l_endp2_rxFaillanes;
    bool l_fieldVPDClear = true;

    l_fieldVPDClear = true;

    /***** Read Field VPD *****/

    // During Mfg mode IPL, field VPD need to be clear.

    // Get failed lanes for endp1
    FAPI_TRY( erepairGetFieldFailedLanes(
                  i_endp1_target,
                  i_clkGroup,
                  l_endp1_txFaillanes,
                  l_endp1_rxFaillanes),
              "erepairGetFieldFailedLanes endp1 target failed w/rc=0x%x",
              (uint64_t)current_err );

    // If there are fail lanes in Field VPD on endpoint1, create an
    // error log and return
    if(l_endp1_txFaillanes.size() ||
       l_endp1_rxFaillanes.size())
    {
        l_fieldVPDClear = false;
        FAPI_DBG("mnfgCheckFieldVPD: eRepair records found in Field VPD in Tx during Manufacturing mode IPL");
    }

    // Get failed lanes for endp2
    FAPI_TRY( erepairGetFieldFailedLanes(
                  i_endp2_target,
                  i_clkGroup,
                  l_endp2_txFaillanes,
                  l_endp2_rxFaillanes),
              "erepairGetFieldFailedLanes endp2 target failed w/rc=0x%x",
              (uint64_t)current_err );

    // If there are fail lanes in Field VPD on endpoint2, create an
    // error log and return
    if(l_endp2_txFaillanes.size() ||
       l_endp2_rxFaillanes.size())
    {
        l_fieldVPDClear = false;
        FAPI_DBG("mnfgCheckFieldVPD: eRepair records found in Field VPD in Rx during Manufacturing mode IPL");
    }

    FAPI_ASSERT(l_fieldVPDClear == true,
                fapi2::P9_EREPAIR_RESTORE_FIELD_VPD_NOT_CLEAR()
                .set_TARGET1(i_endp1_target)
                .set_TARGET2(i_endp2_target),
                "ERROR: mnfgCheckFieldVPD: Field VPD need to be clear during Mnfg mode IPL");

fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::TargetType J>
fapi2::ReturnCode getVerifiedRepairLanes(
    const fapi2::Target < K >&          i_endp1_target,
    const fapi2::Target < J >&          i_endp2_target,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>& o_endp1_txFaillanes,
    std::vector<uint8_t>& o_endp1_rxFaillanes,
    std::vector<uint8_t>& o_endp2_txFaillanes,
    std::vector<uint8_t>& o_endp2_rxFaillanes,
    const erepairVpdType i_vpdType)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    getLanes_t<K> l_getLanes = NULL;
    setLanes_t<K> l_setLanes = NULL;

    fapi2::Target < K > l_target[2] = {i_endp1_target, i_endp2_target};
    bool         l_invalidFails_inTx_OfTgt[2] = {false, false};
    bool         l_invalidFails_inRx_OfTgt[2] = {false, false};
    uint8_t      l_tgtIndx = 0;

    std::vector<uint8_t> l_emptyVector;
    std::vector<uint8_t> l_txFaillanes;
    std::vector<uint8_t> l_rxFaillanes;

    FAPI_INF(">> getVerifiedRepairLanes: vpdType: %s",
             i_vpdType == EREPAIR_VPD_FIELD ? "Field" : "Mnfg");

    /***** Read VPD *****/

    if(i_vpdType == EREPAIR_VPD_FIELD)
    {
        l_getLanes = &erepairGetFieldFailedLanes;
        l_setLanes = &erepairSetFieldFailedLanes;
    }
    else if(i_vpdType == EREPAIR_VPD_MNFG)
    {
        l_getLanes = &erepairGetMnfgFailedLanes;
        l_setLanes = &erepairSetMnfgFailedLanes;
    }

    for(l_tgtIndx = 0; l_tgtIndx < 2; l_tgtIndx++)
    {
        // Get failed lanes for endp1 and endp2
        FAPI_TRY( l_getLanes(
                      l_target[l_tgtIndx],
                      i_clkGroup,
                      l_txFaillanes,
                      l_rxFaillanes),
                  "getVerifiedRepairLanes() from Accessor HWP failed w/rc=0x%x",
                  (uint64_t)current_err );

        if(l_tgtIndx == 0)
        {
            o_endp1_txFaillanes = l_txFaillanes;
            o_endp1_rxFaillanes = l_rxFaillanes;
        }
        else
        {
            o_endp2_txFaillanes = l_txFaillanes;
            o_endp2_rxFaillanes = l_rxFaillanes;
        }

        l_txFaillanes.clear();
        l_rxFaillanes.clear();
    } // end of for(l_tgtIndx)

    // Check if matching fail lanes exists on the sub-interfaces
    // connecting the two end points
    if(o_endp1_txFaillanes.size() || o_endp2_rxFaillanes.size())
    {
        invalidateNonMatchingFailLanes(o_endp1_txFaillanes,
                                       o_endp2_rxFaillanes,
                                       l_invalidFails_inTx_OfTgt[0],
                                       l_invalidFails_inRx_OfTgt[1]);
    }

    if(o_endp2_txFaillanes.size() || o_endp1_rxFaillanes.size())
    {
        invalidateNonMatchingFailLanes(o_endp2_txFaillanes,
                                       o_endp1_rxFaillanes,
                                       l_invalidFails_inTx_OfTgt[1],
                                       l_invalidFails_inRx_OfTgt[0]);
    }

    /***** Correct eRepair data of endp1 in VPD *****/

    for(l_tgtIndx = 0; l_tgtIndx < 2; l_tgtIndx++)
    {
        if(l_tgtIndx == 0)
        {
            l_txFaillanes = o_endp1_txFaillanes;
            l_rxFaillanes = o_endp1_rxFaillanes;
        }
        else
        {
            l_txFaillanes = o_endp2_txFaillanes;
            l_rxFaillanes = o_endp2_rxFaillanes;
        }

        // Update endp1 and endp2 VPD to invalidate fail lanes that do
        // not have matching fail lanes on the other end
        if(l_invalidFails_inTx_OfTgt[l_tgtIndx] &&
           l_invalidFails_inRx_OfTgt[l_tgtIndx])
        {
            FAPI_TRY( l_setLanes(
                          l_target[l_tgtIndx],
                          i_clkGroup,
                          l_txFaillanes,
                          l_rxFaillanes),
                      "getVerifiedRepairLanes() tx/rx from Accessor HWP failed w/rc=0x%x",
                      (uint64_t)current_err );
        }
        else if(l_invalidFails_inTx_OfTgt[l_tgtIndx])
        {
            FAPI_TRY( l_setLanes(
                          l_target[l_tgtIndx],
                          i_clkGroup,
                          l_txFaillanes,
                          l_emptyVector),
                      "getVerifiedRepairLanes() tx from Accessor HWP failed w/rc=0x%x",
                      (uint64_t)current_err );
        }
        else if(l_invalidFails_inRx_OfTgt[l_tgtIndx])
        {
            FAPI_TRY( l_setLanes(
                          l_target[l_tgtIndx],
                          i_clkGroup,
                          l_emptyVector,
                          l_rxFaillanes),
                      "getVerifiedRepairLanes() rx from Accessor HWP failed w/rc=0x%x",
                      (uint64_t)current_err );
        }
    } // end of for loop

fapi_try_exit:
    return current_err;
}

void invalidateNonMatchingFailLanes(std::vector<uint8_t>& io_endp1_txFaillanes,
                                    std::vector<uint8_t>& io_endp2_rxFaillanes,
                                    bool& o_invalidFails_inTx_Ofendp1,
                                    bool& o_invalidFails_inRx_Ofendp2)
{
    std::vector<uint8_t>::iterator l_it;
    std::vector<uint8_t>::iterator l_itTmp;
    std::vector<uint8_t>::iterator l_itDrv;
    std::vector<uint8_t>::iterator l_itRcv;

    o_invalidFails_inTx_Ofendp1 = false;
    o_invalidFails_inRx_Ofendp2 = false;

    std::sort(io_endp1_txFaillanes.begin(), io_endp1_txFaillanes.end());
    std::sort(io_endp2_rxFaillanes.begin(), io_endp2_rxFaillanes.end());

    // Start with drive side fail lanes and check for matching lanes
    // on the recieve side
    l_itTmp = io_endp2_rxFaillanes.begin();

    for(l_itDrv = io_endp1_txFaillanes.begin();
        l_itDrv != io_endp1_txFaillanes.end();
        l_itDrv++)
    {
        l_it = std::lower_bound(io_endp2_rxFaillanes.begin(),
                                io_endp2_rxFaillanes.end(),
                                *l_itDrv);

        // If matching fail lane is not found on the receive side,
        // invalidate the drive side fail lane number
        if((l_it == io_endp2_rxFaillanes.end()) || (*l_it > *l_itDrv))
        {
            *l_itDrv = INVALID_FAIL_LANE_NUMBER;
            o_invalidFails_inTx_Ofendp1 = true;
        }
        else
        {
            // save the iterator for the next search
            l_itTmp = l_it;
        }
    }

    // Sort again as we might have invalidated some lanes
    std::sort(io_endp1_txFaillanes.begin(), io_endp1_txFaillanes.end());

    // Now, traverse through the receive side fail lanes and
    // check for matching lanes on the drive side
    for(l_itRcv = io_endp2_rxFaillanes.begin();
        ((l_itRcv <= l_itTmp) && (l_itRcv != io_endp2_rxFaillanes.end()));
        l_itRcv++)
    {
        l_it = std::lower_bound(io_endp1_txFaillanes.begin(),
                                io_endp1_txFaillanes.end(),
                                *l_itRcv);

        // If matching lane is not found on the driver side,
        // invalidate the receive side fail lane number
        if((l_it == io_endp1_txFaillanes.end()) || (*l_it > *l_itRcv))
        {
            *l_itRcv = INVALID_FAIL_LANE_NUMBER;
            o_invalidFails_inRx_Ofendp2 = true;
        }
    }

    // Need to invalidate all the entries beyond the last
    // lower bound of first search
    if(l_itTmp != io_endp2_rxFaillanes.end())
    {
        for(l_itTmp++; l_itTmp != io_endp2_rxFaillanes.end(); l_itTmp++)
        {
            *l_itTmp = INVALID_FAIL_LANE_NUMBER;
        }
    }
}


template<fapi2::TargetType K>
fapi2::ReturnCode erepairGetFailedLanes(
    const fapi2::Target < K >&          i_endp_target,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>& o_txFailLanes,
    std::vector<uint8_t>& o_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    std::vector<uint8_t>           l_txFailLanes;
    std::vector<uint8_t>           l_rxFailLanes;
    std::vector<uint8_t>::iterator l_it;

    FAPI_INF(">> erepairGetFailedLaness");

    // Get the erepair lanes from Field VPD
    FAPI_TRY( erepairGetFieldFailedLanes(
                  i_endp_target,
                  i_clkGroup,
                  l_txFailLanes,
                  l_rxFailLanes),
              "erepairGetFieldFailedLanes() failed w/rc=0x%x",
              (uint64_t)current_err );

    o_txFailLanes = l_txFailLanes;
    o_rxFailLanes = l_rxFailLanes;

    // Get the erepair lanes from Manufacturing VPD
    l_txFailLanes.clear();
    l_rxFailLanes.clear();
    FAPI_TRY( erepairGetMnfgFailedLanes(
                  i_endp_target,
                  i_clkGroup,
                  l_txFailLanes,
                  l_rxFailLanes),
              "erepairGetMnfgFailedLanes() failed w/rc=0x%x",
              (uint64_t)current_err );

    // Merge the Mnfg lanes with the Field lanes
    l_it = o_txFailLanes.end();
    o_txFailLanes.insert(l_it, l_txFailLanes.begin(), l_txFailLanes.end());

    l_it = o_rxFailLanes.end();
    o_rxFailLanes.insert(l_it, l_rxFailLanes.begin(), l_rxFailLanes.end());

fapi_try_exit:
    return fapi2::current_err;
}

template fapi2::ReturnCode erepairGetFailedLanes<TARGET_TYPE_XBUS>(
    const fapi2::Target < TARGET_TYPE_XBUS >&          i_endp_target,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>& o_txFailLanes,
    std::vector<uint8_t>& o_rxFailLanes);


template<fapi2::TargetType K>
fapi2::ReturnCode erepairGetFieldFailedLanes(
    const fapi2::Target < K >&          i_endp_target,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>& o_txFailLanes,
    std::vector<uint8_t>& o_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_DBG(">> erepairGetFieldFailedLanes");

    // Execute the Accessor HWP to retrieve the failed lanes from the VPD
    FAPI_TRY( p9_io_erepairGetFailedLanesHwp(
                  i_endp_target,
                  EREPAIR_VPD_FIELD,
                  i_clkGroup,
                  o_txFailLanes,
                  o_rxFailLanes),
              "erepairGetFieldFailedLanes() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

fapi_try_exit:
    return fapi2::current_err;
}


template<fapi2::TargetType K>
fapi2::ReturnCode erepairGetMnfgFailedLanes(
    const fapi2::Target < K >&          i_endp_target,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>& o_txFailLanes,
    std::vector<uint8_t>& o_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_DBG(">> erepairGetMnfgFailedLanes");

    // Execute the Accessor HWP to retrieve the failed lanes from the VPD
    FAPI_TRY( p9_io_erepairGetFailedLanesHwp(
                  i_endp_target,
                  EREPAIR_VPD_MNFG,
                  i_clkGroup,
                  o_txFailLanes,
                  o_rxFailLanes),
              "erepairGetMnfgFailedLanes() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::TargetType J>
fapi2::ReturnCode erepairSetFailedLanes(
    const fapi2::Target < K >&          i_txEndp_target,
    const fapi2::Target < J >&          i_rxEndp_target,
    const uint8_t                     i_clkGroup,
    const std::vector<uint8_t>& i_rxFailLanes,
    bool&                       o_thresholdExceed)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint64_t         l_allMnfgFlags    = 0;
    bool             l_mnfgModeIPL     = false;
    uint8_t          l_threshold       = 0;
    setLanes_t<K>       l_setLanes        = NULL;
    getLanes_t<K>       l_getLanes        = NULL;
    std::vector<uint8_t> l_txFaillanes;
    std::vector<uint8_t> l_rxFaillanes;
    std::vector<uint8_t> l_emptyVector;
    std::vector<uint8_t> l_throwAway;

    FAPI_INF(">> erepairSetFailedLanes");

    o_thresholdExceed = false;

    // Get the Manufacturing Policy flags
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MNFG_FLAGS,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_allMnfgFlags),
             "erepairSetFailedLanes: Unable to read attribute ATTR_MNFG_FLAGS");

    // Check if this is a Mnfg mode IPL
    if(l_allMnfgFlags & fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_THRESHOLDS)
    {
        l_mnfgModeIPL = true;
    }

    if(l_mnfgModeIPL)
    {
        l_setLanes = &erepairSetMnfgFailedLanes;
        l_getLanes = &erepairGetMnfgFailedLanes;
    }
    else
    {
        l_setLanes = &erepairSetFieldFailedLanes;
        l_getLanes = &erepairGetFieldFailedLanes;
    }

    /*** Check if we have crossed the repair threshold ***/
    // Get the eRepair threshold limit
    l_threshold = 0;
    FAPI_TRY( geteRepairThreshold(
                  i_rxEndp_target,
                  l_mnfgModeIPL,
                  l_threshold),
              "geteRepairThreshold() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

    // Check if the new fails have crossed the threshold
    if(i_rxFailLanes.size() > l_threshold)
    {
        o_thresholdExceed = true;
        goto fapi_try_exit;
    }

    // Get existing fail lanes that are in the VPD of rx endpoint
    FAPI_TRY( l_getLanes(
                  i_rxEndp_target,
                  i_clkGroup,
                  l_throwAway,
                  l_rxFaillanes),
              "rx l_getLanes() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

    // Get existing fail lanes that are in the VPD of tx endpoint
    FAPI_TRY( l_getLanes(
                  i_txEndp_target,
                  i_clkGroup,
                  l_txFaillanes,
                  l_throwAway),
              "tx l_getLanes() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

    // Lets combine the new and old fail lanes of Rx side
    l_rxFaillanes.insert(l_rxFaillanes.end(),
                         i_rxFailLanes.begin(),
                         i_rxFailLanes.end());

    // Remove duplicate lanes if any on the Rx side
    std::sort(l_rxFaillanes.begin(), l_rxFaillanes.end());

    l_rxFaillanes.erase(std::unique(l_rxFaillanes.begin(),
                                    l_rxFaillanes.end()),
                        l_rxFaillanes.end());

    // Lets combine the new and old fail lanes of Tx side
    l_txFaillanes.insert(l_txFaillanes.end(),
                         i_rxFailLanes.begin(),
                         i_rxFailLanes.end());

    // Remove duplicate lanes if any on the Tx side
    std::sort(l_txFaillanes.begin(), l_txFaillanes.end());

    l_txFaillanes.erase(std::unique(l_txFaillanes.begin(),
                                    l_txFaillanes.end()),
                        l_txFaillanes.end());

    // Check if the sum of old and new fail lanes have crossed the threshold
    if((l_txFaillanes.size() > l_threshold) ||
       (l_rxFaillanes.size() > l_threshold))
    {
        o_thresholdExceed = true;
        goto fapi_try_exit;
    }

    /*** Update the VPD ***/

    // Lets write the VPD of endpoint1 with faillanes on Rx side
    FAPI_TRY( l_setLanes(
                  i_rxEndp_target,
                  i_clkGroup,
                  l_emptyVector,
                  l_rxFaillanes),
              "rx l_setLanes() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

    // Lets write the VPD of endpoint2 with faillanes on Tx side
    FAPI_TRY( l_setLanes(
                  i_txEndp_target,
                  i_clkGroup,
                  l_txFaillanes,
                  l_emptyVector),
              "tx l_setLanes() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

fapi_try_exit:
    FAPI_INF("<< erepairSetFailedLanes");
    return fapi2::current_err;
}

template ReturnCode erepairSetFailedLanes<TARGET_TYPE_XBUS, TARGET_TYPE_XBUS>(
    const fapi2::Target < TARGET_TYPE_XBUS >&          i_txEndp_target,
    const fapi2::Target < TARGET_TYPE_XBUS >&          i_rxEndp_target,
    const uint8_t                     i_clkGroup,
    const std::vector<uint8_t>& i_rxFailLanes,
    bool&                       o_thresholdExceed);


template<fapi2::TargetType K>
fapi2::ReturnCode erepairSetFieldFailedLanes(
    const fapi2::Target < K >&          i_endp_target,
    const uint8_t                     i_clkGroup,
    const std::vector<uint8_t>& i_txFailLanes,
    const std::vector<uint8_t>& i_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Execute the Accessor HWP to write the fail lanes to Field VPD
    FAPI_TRY( p9_io_erepairSetFailedLanesHwp(
                  i_endp_target,
                  EREPAIR_VPD_FIELD,
                  i_clkGroup,
                  i_txFailLanes,
                  i_rxFailLanes),
              "erepairSetFieldFailedLanes() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K>
fapi2::ReturnCode erepairSetMnfgFailedLanes(
    const fapi2::Target < K >&          i_endp_target,
    const uint8_t                     i_clkGroup,
    const std::vector<uint8_t>& i_txFailLanes,
    const std::vector<uint8_t>& i_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Execute the Accessor HWP to write the fail lanes to Mnfg VPD
    FAPI_TRY( p9_io_erepairSetFailedLanesHwp(
                  i_endp_target,
                  EREPAIR_VPD_MNFG,
                  i_clkGroup,
                  i_txFailLanes,
                  i_rxFailLanes),
              "erepairSetMnfgFailedLanes() from Accessor HWP failed w/rc=0x%x",
              (uint64_t)current_err );

fapi_try_exit:
    return fapi2::current_err;
}

