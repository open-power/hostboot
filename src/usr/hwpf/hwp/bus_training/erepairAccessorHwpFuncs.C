/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/erepairAccessorHwpFuncs.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
/**
 *  @file erepairAccessorHwpFuncs.C
 *
 *  @brief FW Team Utility functions that accesses fabric and memory eRepair
 *         data.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     10/24/2012  Created.
 */

#include <erepairAccessorHwpFuncs.H>
#include <string.h>
#include <erepairConsts.H>

using namespace EREPAIR;

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
 *
 * @return ReturnCode
 */
fapi::ReturnCode mnfgCheckFieldVPD(const fapi::Target &i_endp1_target,
                                   const fapi::Target &i_endp2_target);


/**
 * @brief: This Function reads the specified VPD (Mnfg or Field) of the passed
 *         targets and verifies whether there are matching eRepair records.
 *         The matching eRepair lanes are returned in the passed references
 *         for vectors.
 *
 * @param [in]  i_endp1_target       Target of one end the connecting bus
 * @param [out] o_endp1_txFaillanes  Reference to vector which will have fail
 *                                   lane numbers on Tx side of target passed
 *                                   as first param
 * @param [out] o_endp1_rxFaillanes  Reference to vector which will have fail
 *                                   lane numbers on Rx side of target passed
 *                                   as first param
 * @param [in]  i_endp2_target       Target of the other end of the connecting
 *                                   bus
 * @param [out] o_endp2_txFaillanes  Reference to vector which will have fail
 *                                   lane numbers on Tx side of target passed
 *                                   as fourth param
 * @param [out] o_endp2_rxFaillanes  Reference to vector which will have fail
 *                                   lane numbers on Rx side of target passed
 *                                   as fourth param
 * @param [in]  i_charmModeIPL       If TRUE, indicates that the drawer is under
 *                                   CHARM operation, FALSE otherwise
 * @param [in]  i_vpdType            Indicates whether to read Mnfg VPD or
 *                                   Field VPD
 *
 * @return ReturnCode
 */
fapi::ReturnCode getVerifiedRepairLanes(
                                  const fapi::Target   &i_endp1_target,
                                  std::vector<uint8_t> &o_endp1_txFaillanes,
                                  std::vector<uint8_t> &o_endp1_rxFaillanes,
                                  const fapi::Target   &i_endp2_target,
                                  std::vector<uint8_t> &o_endp2_txFaillanes,
                                  std::vector<uint8_t> &o_endp2_rxFaillanes,
                                  const bool           i_charmModeIPL,
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
void invalidateNonMatchingFailLanes(std::vector<uint8_t> &io_endp1_txFaillanes,
                                    std::vector<uint8_t> &io_endp2_rxFaillanes,
                                    bool &o_invalidFails_inTx_Ofendp1,
                                    bool &o_invalidFails_inRx_Ofendp2);

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
fapi::ReturnCode geteRepairThreshold(const fapi::Target &i_endp_target,
                                     const bool         i_mfgModeIPL,
                                     uint8_t            &o_threshold);

/**
 * @brief This function determines the lane numbers that needs to be spared
 *        to support Corner testing.
 *
 * @param [in]  i_tgtType            The target type(XBus or ABus or DMIBus) for
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
void getCornerTestingLanes(const fapi::TargetType i_tgtType,
                           std::vector<uint8_t> &o_endp1_txFailLanes,
                           std::vector<uint8_t> &o_endp1_rxFailLanes,
                           std::vector<uint8_t> &o_endp2_txFailLanes,
                           std::vector<uint8_t> &o_endp2_rxFailLanes);

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
void combineFieldandMnfgLanes(std::vector<uint8_t> &i_mnfgFaillanes,
                              std::vector<uint8_t> &i_fieldFaillanes,
                              std::vector<uint8_t> &o_allFailLanes);

#ifndef __HOSTBOOT_MODULE
/**
 * @brief: This function checks to see if the no.of fail lanes exceed the
 *         threshold on the sub-interfaces(Tx, Rx),in the scenario where
 *         a new drawer is being added through CHARM.
 *         The Tx lanes of endp1 will be combined with the Rx lanes of endp2
 *         and verified whether the combined value exceeds the threshold.
 *         Same verificatiion is done with Tx of endp2 and Rx of endp1
 *
 * @param [in] i_endp1_txFaillanes  Reference to vector which will have fail
 *                                  lane numbers of Tx of endp1
 * @param [in] i_endp1_rxFaillanes  Reference to vector which will have fail
 *                                  lane numbers of Rx of endp1
 * @param [in] i_endp2_txFaillanes  Reference to vector which will have fail
 *                                  lane numbers of Tx of endp2
 * @param [in] i_endp2_rxFaillanes  Reference to vector which will have fail
 *                                  lane numbers of Rx of endp2
 * @param [in] i_threshold          The eRepair threshold limit
 *
 * @return bool If TRUE, indicates that the threshold has been crossed,
 *               FALSE, otherwise.
 */
bool charmModeThresholdExceed(std::vector<uint8_t> &o_endp1_txFaillanes,
                              std::vector<uint8_t> &o_endp1_rxFaillanes,
                              std::vector<uint8_t> &o_endp2_txFaillanes,
                              std::vector<uint8_t> &o_endp2_rxFaillanes,
                              const uint8_t        i_threshold);
#endif


/***** Function definitions *****/

fapi::ReturnCode erepairGetRestoreLanes(const fapi::Target &i_endp1_target,
                                      std::vector<uint8_t> &o_endp1_txFaillanes,
                                      std::vector<uint8_t> &o_endp1_rxFaillanes,
                                      const fapi::Target   &i_endp2_target,
                                      std::vector<uint8_t> &o_endp2_txFaillanes,
                                      std::vector<uint8_t> &o_endp2_rxFaillanes)
{
    fapi::ReturnCode l_rc;

    std::vector<uint8_t>    l_endp1_txFieldFaillanes;
    std::vector<uint8_t>    l_endp1_rxFieldFaillanes;
    std::vector<uint8_t>    l_endp1_txMnfgFaillanes;
    std::vector<uint8_t>    l_endp1_rxMnfgFaillanes;

    std::vector<uint8_t>    l_endp2_txFieldFaillanes;
    std::vector<uint8_t>    l_endp2_rxFieldFaillanes;
    std::vector<uint8_t>    l_endp2_txMnfgFaillanes;
    std::vector<uint8_t>    l_endp2_rxMnfgFaillanes;

    bool                    l_mnfgModeIPL          = false;
    bool                    l_charmModeIPL         = false;
    bool                    l_enableDmiSpares      = false;
    bool                    l_enableFabricSpares   = false;
    bool                    l_disableFabricERepair = false;
    bool                    l_disableMemoryERepair = false;
    bool                    l_thresholdExceed      = false;
    uint8_t                 l_threshold            = 0;
    uint64_t                l_allMnfgFlags         = 0;
    uint32_t                l_numTxFailLanes       = 0;
    uint32_t                l_numRxFailLanes       = 0;
    fapi::TargetType        l_endp1_tgtType = fapi::TARGET_TYPE_NONE;
    fapi::TargetType        l_endp2_tgtType = fapi::TARGET_TYPE_NONE;

    FAPI_INF(">>erepairGetRestoreLanes: endp1 = %s, endp2 = %s",
             i_endp1_target.toEcmdString(), i_endp2_target.toEcmdString());

    do
    {
        l_rc = FAPI_ATTR_GET(ATTR_MNFG_FLAGS, NULL, l_allMnfgFlags);

        if(l_rc)
        {
            FAPI_ERR("erepairGetRestoreLanes: Unable to read attribute"
                     " - ATTR_MNFG_FLAGS");
            break;
        }

        // Check if MNFG_DISABLE_FABRIC_EREPAIR is enabled
        l_disableFabricERepair = false;
        if(l_allMnfgFlags &
           fapi::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_FABRIC_eREPAIR)
        {
            l_disableFabricERepair = true;
        }

        // Check if MNFG_DISABLE_MEMORY_EREPAIR is enabled
        l_disableMemoryERepair = false;
        if(l_allMnfgFlags &
           fapi::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_MEMORY_eREPAIR)
        {
            l_disableMemoryERepair = true;
        }

        // Check if this is Manufacturing mode IPL.
        l_mnfgModeIPL = false;
        if(l_allMnfgFlags & fapi::ENUM_ATTR_MNFG_FLAGS_MNFG_THRESHOLDS)
        {
            l_mnfgModeIPL = true;
        }

        // Get the type of passed targets
        l_endp1_tgtType = i_endp1_target.getType();
        l_endp2_tgtType = i_endp2_target.getType();

        // Check if the correct target types are passed
        if(l_endp1_tgtType == fapi::TARGET_TYPE_XBUS_ENDPOINT ||
           l_endp1_tgtType == fapi::TARGET_TYPE_ABUS_ENDPOINT)
        {
            if(l_endp1_tgtType != l_endp2_tgtType)
            {
                FAPI_ERR("erepairGetRestoreLanes: Invalid endpoint target"
                         " type %d-%d", l_endp1_tgtType, l_endp2_tgtType);

                FAPI_SET_HWP_ERROR(l_rc,RC_EREPAIR_RESTORE_INVALID_TARGET_PAIR);
                break;
            }

            if(l_mnfgModeIPL && l_disableFabricERepair)
            {
                // Fabric eRepair has been disabled using the
                // Manufacturing policy flags
                FAPI_INF("erepairGetRestoreLanes: Fabric eRepair is disabled");
                break;
            }
        }
        else if((l_endp1_tgtType    == fapi::TARGET_TYPE_MCS_CHIPLET
                 && l_endp2_tgtType != fapi::TARGET_TYPE_MEMBUF_CHIP) ||
                (l_endp1_tgtType    == fapi::TARGET_TYPE_MEMBUF_CHIP
                 && l_endp2_tgtType != fapi::TARGET_TYPE_MCS_CHIPLET))
        {
            FAPI_ERR("erepairGetRestoreLanes: Invalid endpoint target"
                     " type %d-%d", l_endp1_tgtType, l_endp2_tgtType);

            FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_RESTORE_INVALID_TARGET_PAIR);
            break;
        }
        else if(l_mnfgModeIPL && l_disableMemoryERepair)
        {
            // Memory eRepair has been disabled using the
            // Manufacturing policy flags
            FAPI_INF("erepairGetRestoreLanes: Memory eRepair is disabled");
            break;
        }

#ifndef __HOSTBOOT_MODULE
        // TODO: Check if this is CHARM mode IPL. RTC: 59493
        // l_charmModeIPL = <read_TBD>

        if(l_mnfgModeIPL && l_charmModeIPL)
        {
            // TODO: Review this policy during CHARM  supportcode review.
            // RTC: 59493
            FAPI_ERR("erepairGetRestoreLanes: Manufactuing flags should not"
                     " be enabled during CHARM operation. Ignoring the"
                     " Manufacturing flags for eRepair");
        }
#endif

        if(l_mnfgModeIPL)
        {
            /***** Check Field VPD *****/

            // Do not allow eRepair data in Field VPD during Mfg Mode IPL
            l_rc = mnfgCheckFieldVPD(i_endp1_target,
                                     i_endp2_target);
            if(l_rc)
            {
                FAPI_ERR("erepairGetRestoreLanes:Error from mnfgCheckFieldVPD");
                break;
            }

            /***** Read Manufacturing VPD *****/
            l_rc = getVerifiedRepairLanes(i_endp1_target,
                                          o_endp1_txFaillanes,
                                          o_endp1_rxFaillanes,
                                          i_endp2_target,
                                          o_endp2_txFaillanes,
                                          o_endp2_rxFaillanes,
                                          l_charmModeIPL,
                                          EREPAIR_VPD_MNFG);
            if(l_rc)
            {
                FAPI_ERR("erepairGetRestoreLanes: Error from"
                         " getVerifiedRepairLanes(Mnfg)");
                break;
            }
        }
        else
        {   /***** Normal Mode IPL *****/

            // During Normal mode IPL we read both Mnfg and Field VPD
            // for restoring eRepair lanes

            /***** Read Manufacturing VPD *****/

            l_rc = getVerifiedRepairLanes(i_endp1_target,
                                          l_endp1_txMnfgFaillanes,
                                          l_endp1_rxMnfgFaillanes,
                                          i_endp2_target,
                                          l_endp2_txMnfgFaillanes,
                                          l_endp2_rxMnfgFaillanes,
                                          l_charmModeIPL,
                                          EREPAIR_VPD_MNFG);
            if(l_rc)
            {
                FAPI_ERR("erepairGetRestoreLanes: Error from"
                         " getVerifiedRepairLanes(Mnfg)");
                break;
            }

            /***** Read Field VPD *****/

            l_rc = getVerifiedRepairLanes(i_endp1_target,
                                          l_endp1_txFieldFaillanes,
                                          l_endp1_rxFieldFaillanes,
                                          i_endp2_target,
                                          l_endp2_txFieldFaillanes,
                                          l_endp2_rxFieldFaillanes,
                                          l_charmModeIPL,
                                          EREPAIR_VPD_FIELD);
            if(l_rc)
            {
                FAPI_ERR("erepairGetRestoreLanes: Error from"
                         " getVerifiedRepairLanes(Field)");
                break;
            }

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


        /***** Remove invalid lane numbers *****/

        // Check if there are invalid lanes in Tx side of endp1.
        // If found, erase them from the vector
        o_endp1_txFaillanes.erase(std::remove(o_endp1_txFaillanes.begin(),
                                              o_endp1_txFaillanes.end(),
                                              INVALID_FAIL_LANE_NUMBER),
                                  o_endp1_txFaillanes.end());

        // Check if there are invalid lanes in Rx side of endp1.
        // If found, erase them from the vector
        o_endp1_rxFaillanes.erase(std::remove(o_endp1_rxFaillanes.begin(),
                                              o_endp1_rxFaillanes.end(),
                                              INVALID_FAIL_LANE_NUMBER),
                                  o_endp1_rxFaillanes.end());

        // Check if there are invalid lanes in Tx side of endp2.
        // If found, erase them from the vector
        o_endp2_txFaillanes.erase(std::remove(o_endp2_txFaillanes.begin(),
                                              o_endp2_txFaillanes.end(),
                                              INVALID_FAIL_LANE_NUMBER),
                                  o_endp2_txFaillanes.end());

        // Check if there are invalid lanes in Rx side of endp2.
        // If found, erase them from the vector
        o_endp2_rxFaillanes.erase(std::remove(o_endp2_rxFaillanes.begin(),
                                              o_endp2_rxFaillanes.end(),
                                              INVALID_FAIL_LANE_NUMBER),
                                  o_endp2_rxFaillanes.end());

        /***** Check for threshold exceed conditions *****/

        // Get the eRepair threshold limit
        l_threshold = 0;
        l_rc = geteRepairThreshold(i_endp1_target, l_mnfgModeIPL, l_threshold);

        if(l_rc)
        {
            FAPI_ERR("erepairGetRestoreLanes: Error from geteRepairThreshold");
            break;
        }

        // Check if the eRepair threshold has exceeded for Tx side of endp1
        if(o_endp1_txFaillanes.size() > l_threshold)
        {
            l_thresholdExceed = true;
            l_numTxFailLanes  = o_endp1_txFaillanes.size();

            FAPI_ERR("erepairGetRestoreLanes: eRepair threshold exceed error"
                     " seen in Tx of endp1 target. No.of lanes: %d",
                     l_numTxFailLanes);
        }

        // Check if the eRepair threshold has exceeded for Rx side of endp1
        if(o_endp1_rxFaillanes.size() > l_threshold)
        {
            l_thresholdExceed = true;
            l_numRxFailLanes  = o_endp1_rxFaillanes.size();

            FAPI_ERR("erepairGetRestoreLanes: eRepair threshold exceed error"
                     " seen in Rx of endp1 target. No.of lanes: %d",
                     l_numRxFailLanes);
        }

        // Check if the eRepair threshold has exceeded for Tx side of endp2
        if(o_endp2_txFaillanes.size() > l_threshold)
        {
            l_thresholdExceed = true;
            l_numTxFailLanes  = o_endp2_txFaillanes.size();

            FAPI_ERR("erepairGetRestoreLanes: eRepair threshold exceed error"
                     " seen in Tx of endp2 target. No.of lanes: %d",
                     l_numTxFailLanes);
        }

        // Check if the eRepair threshold has exceeded for Rx side of endp2
        if(o_endp2_rxFaillanes.size() > l_threshold)
        {
            l_thresholdExceed = true;
            l_numRxFailLanes  = o_endp2_rxFaillanes.size();

            FAPI_ERR("erepairGetRestoreLanes: eRepair threshold exceed error"
                     " seen in Rx of endp2 target. No.of lanes: %d",
                     l_numRxFailLanes);
        }

        if(l_thresholdExceed)
        {
            FAPI_ERR("erepairGetRestoreLanes: Threshold has Exceeded");

            const uint32_t &FFDC_TX_NUM_LANES = l_numTxFailLanes;
            const uint32_t &FFDC_RX_NUM_LANES = l_numRxFailLanes;
            const uint32_t &FFDC_THRESHOLD    = l_threshold;
            FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_THRESHOLD_EXCEED);
            break;
        }

#ifndef __HOSTBOOT_MODULE
        // Check threshold exceed scenario during CHARM mode IPL
        bool l_charmThresholdExceed = false;

        if(l_charmModeIPL)
        {
            l_charmThresholdExceed = false;
            l_charmThresholdExceed = charmModeThresholdExceed(
                                                         o_endp1_txFaillanes,
                                                         o_endp1_rxFaillanes,
                                                         o_endp2_txFaillanes,
                                                         o_endp2_rxFaillanes,
                                                         l_threshold);

            if(l_charmThresholdExceed)
            {
                FAPI_ERR("erepairGetRestoreLanes: CHARM IPL, Threshold Exceed");

                FAPI_SET_HWP_ERROR(l_rc,
                                   RC_EREPAIR_RESTORE_CHARM_THRESHOLD_EXCEED);
                break;
            }
        }
#endif
        if(l_mnfgModeIPL)
        {
            // Check if MNFG_DMI_DEPLOY_LANE_SPARES is enabled
            l_enableDmiSpares = false;
            if(l_allMnfgFlags &
               fapi::ENUM_ATTR_MNFG_FLAGS_MNFG_DMI_DEPLOY_LANE_SPARES)
            {
                l_enableDmiSpares = true;
            }

            // Check if MNFG_FABRIC_DEPLOY_LANE_SPARES is enabled
            l_enableFabricSpares = false;
            if(l_allMnfgFlags &
               fapi::ENUM_ATTR_MNFG_FLAGS_MNFG_FABRIC_DEPLOY_LANE_SPARES)
            {
                l_enableFabricSpares = true;
            }

            if(l_enableDmiSpares || l_enableFabricSpares)
            {
                // This is a Corner testing IPL.
                // eRepair Restore the pre-determined memory lanes
                getCornerTestingLanes(l_endp1_tgtType,
                                      o_endp1_txFaillanes,
                                      o_endp1_rxFaillanes,
                                      o_endp2_txFaillanes,
                                      o_endp2_rxFaillanes);
            }
        } // end of if(l_mnfgModeIPL)
    }while(0);

    return l_rc;
}

void combineFieldandMnfgLanes(std::vector<uint8_t> &i_mnfgFaillanes,
                              std::vector<uint8_t> &i_fieldFaillanes,
                              std::vector<uint8_t> &o_allFaillanes)
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

void getCornerTestingLanes(const fapi::TargetType i_tgtType,
                           std::vector<uint8_t> &o_endp1_txFaillanes,
                           std::vector<uint8_t> &o_endp1_rxFaillanes,
                           std::vector<uint8_t> &o_endp2_txFaillanes,
                           std::vector<uint8_t> &o_endp2_rxFaillanes)
{
    std::vector<uint8_t>::iterator l_it;
    uint8_t l_deployIndx = 0;
    uint8_t l_maxDeploys = 0;
    uint8_t *l_deployPtr = NULL;

    uint8_t l_xDeployLanes[XBUS_MAXSPARES_IN_HW] = {XBUS_SPARE_DEPLOY_LANE_1,
                                                    XBUS_SPARE_DEPLOY_LANE_2};

    uint8_t l_aDeployLanes[ABUS_MAXSPARES_IN_HW] = {ABUS_SPARE_DEPLOY_LANE_1};

    uint8_t l_dmiDeployLanes[DMIBUS_MAXSPARES_IN_HW] = {
                                                 DMIBUS_SPARE_DEPLOY_LANE_1,
                                                 DMIBUS_SPARE_DEPLOY_LANE_2};

    // Idea is to push_back the pre-determined lanes into the Tx and Rx
    // vectors of endpoint1 and endpoint2
    do
    {
        switch(i_tgtType)
        {
            case fapi::TARGET_TYPE_XBUS_ENDPOINT:
                l_maxDeploys = XBUS_MAXSPARES_IN_HW;
                l_deployPtr = l_xDeployLanes;
                break;

            case fapi::TARGET_TYPE_ABUS_ENDPOINT:
                l_maxDeploys = ABUS_MAXSPARES_IN_HW;
                l_deployPtr = l_aDeployLanes;
                break;

            case fapi::TARGET_TYPE_MCS_CHIPLET:
            case fapi::TARGET_TYPE_MEMBUF_CHIP:
                l_maxDeploys = DMIBUS_MAXSPARES_IN_HW;
                l_deployPtr = l_dmiDeployLanes;
                break;

            default:
                FAPI_ERR("getCornerTestingLanes: Invalid target type");
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

    }while(0);
}

fapi::ReturnCode geteRepairThreshold(const fapi::Target &i_endp_target,
                                     const bool         i_mfgModeIPL,
                                     uint8_t            &o_threshold)
{
    fapi::ReturnCode l_rc;
    fapi::TargetType l_tgtType = fapi::TARGET_TYPE_NONE;

    do
    {
        o_threshold = 0;
        l_tgtType = i_endp_target.getType();

        if(i_mfgModeIPL)
        {
            switch(l_tgtType)
            {
                case fapi::TARGET_TYPE_XBUS_ENDPOINT:
                     l_rc = FAPI_ATTR_GET(ATTR_X_EREPAIR_THRESHOLD_MNFG,
                                          NULL,
                                          o_threshold);
                    break;

                case fapi::TARGET_TYPE_ABUS_ENDPOINT:
                     l_rc = FAPI_ATTR_GET(ATTR_A_EREPAIR_THRESHOLD_MNFG,
                                          NULL,
                                          o_threshold);
                    break;

                case fapi::TARGET_TYPE_MCS_CHIPLET:
                case fapi::TARGET_TYPE_MEMBUF_CHIP:
                     l_rc = FAPI_ATTR_GET(ATTR_DMI_EREPAIR_THRESHOLD_MNFG,
                                          NULL,
                                          o_threshold);
                    break;

                default:
                    FAPI_ERR("geteRepairThreshold: Invalid target type %d",
                             l_tgtType);
                    FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_RESTORE_INVALID_TARGET);
                    break;
            };
        }
        else
        {
            switch(l_tgtType)
            {
                case fapi::TARGET_TYPE_XBUS_ENDPOINT:
                     l_rc = FAPI_ATTR_GET(ATTR_X_EREPAIR_THRESHOLD_FIELD,
                                          NULL,
                                          o_threshold);
                    break;

                case fapi::TARGET_TYPE_ABUS_ENDPOINT:
                     l_rc = FAPI_ATTR_GET(ATTR_A_EREPAIR_THRESHOLD_FIELD,
                                          NULL,
                                          o_threshold);
                    break;

                case fapi::TARGET_TYPE_MCS_CHIPLET:
                case fapi::TARGET_TYPE_MEMBUF_CHIP:
                     l_rc = FAPI_ATTR_GET(ATTR_DMI_EREPAIR_THRESHOLD_FIELD,
                                          NULL,
                                          o_threshold);
                    break;

                default:
                    FAPI_ERR("geteRepairThreshold: Invalid target type %d",
                             l_tgtType);
                    FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_RESTORE_INVALID_TARGET);
                    break;
            };
        }
    }while(0);

    FAPI_INF("geteRepairThreshold: o_threshold = %d", o_threshold);
    return l_rc;
}

fapi::ReturnCode mnfgCheckFieldVPD(const fapi::Target &i_endp1_target,
                                   const fapi::Target &i_endp2_target)
{
    fapi::ReturnCode l_rc;
    std::vector<uint8_t> l_endp1_txFaillanes;
    std::vector<uint8_t> l_endp1_rxFaillanes;
    std::vector<uint8_t> l_endp2_txFaillanes;
    std::vector<uint8_t> l_endp2_rxFaillanes;
    bool l_fieldVPDClear = true;

    do
    {
        l_fieldVPDClear = true;

        /***** Read Field VPD *****/

        // During Mfg mode IPL, field VPD need to be clear.

        // Get failed lanes for endp1
        l_rc = erepairGetFieldFailedLanes(i_endp1_target,
                                          l_endp1_txFaillanes,
                                          l_endp1_rxFaillanes);

        if(l_rc)
        {
            FAPI_ERR("mnfgCheckFieldVPD: Error from erepairGetFieldFailedLanes"
                    " for %s",i_endp1_target.toEcmdString());
            break;
        }

        // If there are fail lanes in Field VPD on endpoint1, create an
        // error log and return
        if(l_endp1_txFaillanes.size() ||
           l_endp1_rxFaillanes.size())
        {
            l_fieldVPDClear = false;

            FAPI_ERR("mnfgCheckFieldVPD: eRepair records found in"
                     " Field VPD, in Tx of %s during Manufacturing mode IPL",
                     i_endp1_target.toEcmdString());
        }

        // Get failed lanes for endp2
        l_rc = erepairGetFieldFailedLanes(i_endp2_target,
                                          l_endp2_txFaillanes,
                                          l_endp2_rxFaillanes);

        if(l_rc)
        {
            FAPI_ERR("mnfgCheckFieldVPD: Error from erepairGetFieldFailedLanes"
                     " for %s",i_endp2_target.toEcmdString());
            break;
        }

        // If there are fail lanes in Field VPD on endpoint2, create an
        // error log and return
        if(l_endp2_txFaillanes.size() ||
           l_endp2_rxFaillanes.size())
        {
            l_fieldVPDClear = false;

            FAPI_ERR("mnfgCheckFieldVPD: eRepair records found in"
                     " Field VPD, in Rx of %s during Manufacturing mode IPL",
                     i_endp2_target.toEcmdString());
        }

        if(l_fieldVPDClear != true)
        {
            FAPI_ERR("mnfgCheckFieldVPD: Field VPD need to be clear"
                     " during Mnfg mode IPL");

            FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_RESTORE_FIELD_VPD_NOT_CLEAR);
        }
    }while(0);

    return (l_rc);
}

fapi::ReturnCode getVerifiedRepairLanes(
                                  const fapi::Target   &i_endp1_target,
                                  std::vector<uint8_t> &o_endp1_txFaillanes,
                                  std::vector<uint8_t> &o_endp1_rxFaillanes,
                                  const fapi::Target   &i_endp2_target,
                                  std::vector<uint8_t> &o_endp2_txFaillanes,
                                  std::vector<uint8_t> &o_endp2_rxFaillanes,
                                  const bool           i_charmModeIPL,
                                  const erepairVpdType i_vpdType)
{
    fapi::ReturnCode l_rc;

    getLanes_t l_getLanes = NULL;
    setLanes_t l_setLanes = NULL;

    fapi::Target l_target[2] = {i_endp1_target, i_endp2_target};
    bool         l_invalidFails_inTx_OfTgt[2] = {false, false};
    bool         l_invalidFails_inRx_OfTgt[2] = {false, false};
    uint8_t      l_tgtIndx = 0;

    std::vector<uint8_t> l_emptyVector;
    std::vector<uint8_t> l_txFaillanes;
    std::vector<uint8_t> l_rxFaillanes;

    FAPI_INF(">> getVerifiedRepairLanes: charm: %d, vpdType: %s",
             i_charmModeIPL, i_vpdType == EREPAIR_VPD_FIELD ? "Field":"Mnfg");

    do
    {
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
            l_rc = l_getLanes(l_target[l_tgtIndx],
                              l_txFaillanes,
                              l_rxFaillanes);

            if(l_rc)
            {
                FAPI_ERR("getVerifiedRepairLanes: Error while getting failed"
                         " lanes for %s",
                         l_target[l_tgtIndx].toEcmdString());
                break;
            }

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

        if(l_rc)
        {
            // break out of do-while(0) loop
            break;
        }

        /***** Verify eRepair data *****/

        // Do not check for matching fail lanes on the other end
        // if this is a CHARM mode IPL
        if(i_charmModeIPL == true)
        {
            break;
        }

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
                l_rc = l_setLanes(l_target[l_tgtIndx],
                                  l_txFaillanes,
                                  l_rxFaillanes);
                if(l_rc)
                {
                    FAPI_ERR("getVerifiedRepairLanes: Error while setting"
                             " lanes for Tx and Rx on %s",
                             l_target[l_tgtIndx].toEcmdString());
                    break;
                }
            }
            else if(l_invalidFails_inTx_OfTgt[l_tgtIndx])
            {
                l_rc = l_setLanes(l_target[l_tgtIndx],
                                  l_txFaillanes,
                                  l_emptyVector);
                if(l_rc)
                {
                    FAPI_ERR("getVerifiedRepairLanes: Error while setting"
                             " lanes for Tx on %s",
                             l_target[l_tgtIndx].toEcmdString());
                    break;
                }
            }
            else if(l_invalidFails_inRx_OfTgt[l_tgtIndx])
            {
                l_rc = l_setLanes(l_target[l_tgtIndx],
                                  l_emptyVector,
                                  l_rxFaillanes);
                if(l_rc)
                {
                    FAPI_ERR("getVerifiedRepairLanes: Error while setting"
                              " lanes Rx on %s",
                              l_target[l_tgtIndx].toEcmdString());
                    break;
                }
            }
        } // end of for loop
    }while(0);

    return l_rc;
}

void invalidateNonMatchingFailLanes(std::vector<uint8_t> &io_endp1_txFaillanes,
                                    std::vector<uint8_t> &io_endp2_rxFaillanes,
                                    bool &o_invalidFails_inTx_Ofendp1,
                                    bool &o_invalidFails_inRx_Ofendp2)
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
    std::sort(io_endp1_txFaillanes.begin(),io_endp1_txFaillanes.end());

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

fapi::ReturnCode erepairGetFailedLanes(const fapi::Target &i_endp_target,
                                       std::vector<uint8_t> &o_txFailLanes,
                                       std::vector<uint8_t> &o_rxFailLanes)
{
    fapi::ReturnCode               l_rc;
    std::vector<uint8_t>           l_txFailLanes;
    std::vector<uint8_t>           l_rxFailLanes;
    std::vector<uint8_t>::iterator l_it;

    FAPI_INF(">> erepairGetFailedLanes for %s", i_endp_target.toEcmdString());

    do
    {
        // Get the erepair lanes from Field VPD
        l_rc = erepairGetFieldFailedLanes(i_endp_target,
                                          l_txFailLanes,
                                          l_rxFailLanes);
        if(l_rc)
        {
            FAPI_ERR("erepairGetFailedLanes: Error from"
                     " erepairGetFieldFailedLanes");
            break;
        }

        o_txFailLanes = l_txFailLanes;
        o_rxFailLanes = l_rxFailLanes;

        // Get the erepair lanes from Manufacturing VPD
        l_txFailLanes.clear();
        l_rxFailLanes.clear();
        l_rc = erepairGetMnfgFailedLanes(i_endp_target,
                                         l_txFailLanes,
                                         l_rxFailLanes);
        if(l_rc)
        {
            FAPI_ERR("erepairGetFailedLanes: Error from"
                     " erepairGetMnfgFailedLanes");
            break;
        }

        // Merge the Mnfg lanes with the Field lanes
        l_it = o_txFailLanes.end();
        o_txFailLanes.insert(l_it, l_txFailLanes.begin(), l_txFailLanes.end());

        l_it = o_rxFailLanes.end();
        o_rxFailLanes.insert(l_it, l_rxFailLanes.begin(), l_rxFailLanes.end());

    }while(0);

    return l_rc;
}

fapi::ReturnCode erepairGetFieldFailedLanes(const fapi::Target &i_endp_target,
                                            std::vector<uint8_t> &o_txFailLanes,
                                            std::vector<uint8_t> &o_rxFailLanes)
{
    fapi::ReturnCode l_rc;

    FAPI_DBG(">> erepairGetFieldFailedLanes for %s", i_endp_target.toEcmdString());

    do
    {
        // Execute the Accessor HWP to retrieve the failed lanes from the VPD
        FAPI_EXEC_HWP(l_rc,
                      erepairGetFailedLanesHwp,
                      i_endp_target,
                      EREPAIR_VPD_FIELD,
                      o_txFailLanes,
                      o_rxFailLanes);

        if(l_rc)
        {
            FAPI_ERR("erepairGetFieldFailedLanes: Error from Accessor HWP:"
                     " erepairGetFailedLanesHwp");
            break;
        }

        // Check if the VPD has any invalid fail lanes on Tx side.
        // If found, remove them from the list.
        o_txFailLanes.erase(std::remove(o_txFailLanes.begin(),
                                        o_txFailLanes.end(),
                                        INVALID_FAIL_LANE_NUMBER),
                            o_txFailLanes.end());

        // Check if the VPD has any invalid fail lanes on Rx side.
        // If found, remove them from the list.
        o_rxFailLanes.erase(std::remove(o_rxFailLanes.begin(),
                                        o_rxFailLanes.end(),
                                        INVALID_FAIL_LANE_NUMBER),
                            o_rxFailLanes.end());
    }while(0);

    return l_rc;
}


fapi::ReturnCode erepairGetMnfgFailedLanes(const fapi::Target &i_endp_target,
                                           std::vector<uint8_t> &o_txFailLanes,
                                           std::vector<uint8_t> &o_rxFailLanes)
{
    fapi::ReturnCode l_rc;

    FAPI_DBG(">> erepairGetMnfgFailedLanes for %s",
             i_endp_target.toEcmdString());
    do
    {
        // Execute the Accessor HWP to retrieve the failed lanes from the VPD
        FAPI_EXEC_HWP(l_rc,
                      erepairGetFailedLanesHwp,
                      i_endp_target,
                      EREPAIR_VPD_MNFG,
                      o_txFailLanes,
                      o_rxFailLanes);

        if(l_rc)
        {
            FAPI_ERR("erepairGetMnfgFailedLanes: Error from Accessor HWP:"
                     " erepairGetFailedLanesHwp");
            break;
        }

        // Check if the VPD has any invalid fail lanes on Tx side.
        // If found, remove them from the list.
        o_txFailLanes.erase(std::remove(o_txFailLanes.begin(),
                                        o_txFailLanes.end(),
                                        INVALID_FAIL_LANE_NUMBER),
                           o_txFailLanes.end());

        // Check if the VPD has any invalid fail lanes on Rx side.
        // If found, remove them from the list.
        o_rxFailLanes.erase(std::remove(o_rxFailLanes.begin(),
                                        o_rxFailLanes.end(),
                                        INVALID_FAIL_LANE_NUMBER),
                            o_rxFailLanes.end());
    }while(0);

    return l_rc;
}

fapi::ReturnCode erepairSetFailedLanes(
                                  const fapi::Target         &i_txEndp_target,
                                  const fapi::Target         &i_rxEndp_target,
                                  const std::vector<uint8_t> &i_rxFailLanes,
                                  bool                       &o_thresholdExceed)
{
    fapi::ReturnCode l_rc;
    uint64_t         l_allMnfgFlags    = 0;
    bool             l_mnfgModeIPL     = false;
    uint8_t          l_threshold       = 0;
    setLanes_t       l_setLanes        = NULL;
    getLanes_t       l_getLanes        = NULL;
    std::vector<uint8_t> l_txFaillanes;
    std::vector<uint8_t> l_rxFaillanes;
    std::vector<uint8_t> l_emptyVector;
    std::vector<uint8_t> l_throwAway;

    FAPI_INF(">> erepairSetFailedLanes: %s-%s",
              i_rxEndp_target.toEcmdString(), i_txEndp_target.toEcmdString());

    do
    {
        o_thresholdExceed = false;

        // Get the Manufacturing Policy flags
        l_rc = FAPI_ATTR_GET(ATTR_MNFG_FLAGS, NULL, l_allMnfgFlags);

        if(l_rc)
        {
            FAPI_ERR("erepairSetFailedLanes: Unable to read attribute"
                     "ATTR_MNFG_FLAGS");
            break;
        }

        // Check if this is a Mnfg mode IPL
        if(l_allMnfgFlags & fapi::ENUM_ATTR_MNFG_FLAGS_MNFG_THRESHOLDS)
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
        l_rc = geteRepairThreshold(i_rxEndp_target, l_mnfgModeIPL, l_threshold);

        if(l_rc)
        {
            FAPI_ERR("erepairSetFailedLanes: Error (0x%x) from"
                     " geteRepairThreshold", static_cast<uint32_t> (l_rc));
            break;
        }

        // Check if the new fails have crossed the threshold
        if(i_rxFailLanes.size() > l_threshold)
        {
            o_thresholdExceed = true;
            break;
        }

        // Get existing fail lanes that are in the VPD of rx endpoint
        l_rc = l_getLanes(i_rxEndp_target, l_throwAway, l_rxFaillanes);

        if(l_rc)
        {
            FAPI_ERR("erepairSetFailedLanes: Error (0x%x) from"
                     " l_getLanes for %s", static_cast<uint32_t> (l_rc),
                     i_rxEndp_target.toEcmdString());
            break;
        }

        // Get existing fail lanes that are in the VPD of tx endpoint
        l_rc = l_getLanes(i_txEndp_target, l_txFaillanes, l_throwAway);

        if(l_rc)
        {
            FAPI_ERR("erepairSetFailedLanes: Error (0x%x) from"
                     " l_getLanes for %s", static_cast<uint32_t> (l_rc),
                     i_txEndp_target.toEcmdString());
            break;
        }

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
            break;
        }

        /*** Update the VPD ***/

        // Lets write the VPD of endpoint1 with faillanes on Rx side
        l_rc = l_setLanes(i_rxEndp_target, l_emptyVector, l_rxFaillanes);
        if(l_rc)
        {
            FAPI_ERR("Error from l_setLanes for %s",
                    i_rxEndp_target.toEcmdString());
            break;
        }

        // Lets write the VPD of endpoint2 with faillanes on Tx side
        l_rc = l_setLanes(i_txEndp_target, l_txFaillanes, l_emptyVector);
        if(l_rc)
        {
            FAPI_ERR("Error from l_setLanes for %s",
                      i_txEndp_target.toEcmdString());
            break;
        }
    }while(0);

    FAPI_INF("<< erepairSetFailedLanes");
    return l_rc;
}

fapi::ReturnCode erepairSetFieldFailedLanes(
                                      const fapi::Target         &i_endp_target,
                                      const std::vector<uint8_t> &i_txFailLanes,
                                      const std::vector<uint8_t> &i_rxFailLanes)
{
    fapi::ReturnCode l_rc;

    do
    {
        // Execute the Accessor HWP to write the fail lanes to Field VPD
        FAPI_EXEC_HWP(l_rc,
                      erepairSetFailedLanesHwp,
                      i_endp_target,
                      EREPAIR_VPD_FIELD,
                      i_txFailLanes,
                      i_rxFailLanes);

        if(l_rc)
        {
            FAPI_ERR("erepairSetFieldFailedLanes: Error from Accessor HWP:"
                     "erepairSetFailedLanesHwp");
            break;
        }
    }while(0);

    return l_rc;
}

fapi::ReturnCode erepairSetMnfgFailedLanes(
                                     const fapi::Target   &i_endp_target,
                                     const std::vector<uint8_t> &i_txFailLanes,
                                     const std::vector<uint8_t> &i_rxFailLanes)
{
    fapi::ReturnCode l_rc;

    do
    {
        // Execute the Accessor HWP to write the fail lanes to Mnfg VPD
        FAPI_EXEC_HWP(l_rc,
                      erepairSetFailedLanesHwp,
                      i_endp_target,
                      EREPAIR_VPD_MNFG,
                      i_txFailLanes,
                      i_rxFailLanes);

        if(l_rc)
        {
            FAPI_ERR("erepairSetMnfgFailedLanes: Error from Accessor HWP:"
                     "erepairSetMnfgFailedLanesHwp");
            break;
        }
    }while(0);

    return l_rc;
}

#ifndef __HOSTBOOT_MODULE
bool charmModeThresholdExceed(std::vector<uint8_t> &i_endp1_txFaillanes,
                              std::vector<uint8_t> &i_endp1_rxFaillanes,
                              std::vector<uint8_t> &i_endp2_txFaillanes,
                              std::vector<uint8_t> &i_endp2_rxFaillanes,
                              const uint8_t        i_threshold)
{
    bool l_thresholdExceed = false;
    std::vector<uint8_t> l_tmpFaillanes;
    std::vector<uint8_t>::iterator l_it;
    std::vector<uint8_t>::iterator l_it2;

    FAPI_INF(">> charmModeThresholdExceed");

    do
    {
        // Check for threshold exceed on Tx lanes of endp1 and Rx lanes of endp2
        l_tmpFaillanes.clear();
        l_tmpFaillanes = i_endp1_txFaillanes;

        for(l_it = i_endp2_rxFaillanes.begin();
            l_it != i_endp2_rxFaillanes.end(); l_it++)
        {
            // Check for duplicates
            l_it2 = std::find(l_tmpFaillanes.begin(), l_tmpFaillanes.end(),
                              *l_it);

            if(l_it2 == l_tmpFaillanes.end())
            {
                l_tmpFaillanes.push_back(*l_it);
            }
        }

        if(l_tmpFaillanes.size() > i_threshold)
        {
            FAPI_ERR("charmModeThresholdExceed: eRepair threshold exceed error"
                     " seen in Tx side. Threshold: %d", i_threshold);

            l_thresholdExceed = true;
            break;
        }

        // Check for threshold exceed on Tx lanes of endp2 and Rx lanes of endp1
        l_tmpFaillanes.clear();
        l_tmpFaillanes = i_endp2_txFaillanes;
        for(l_it = i_endp1_rxFaillanes.begin();
            l_it != i_endp1_rxFaillanes.end(); l_it++)
        {
            // Check for duplicates
            l_it2 = std::find(l_tmpFaillanes.begin(), l_tmpFaillanes.end(),
                              *l_it);

            if(l_it2 == l_tmpFaillanes.end())
            {
                l_tmpFaillanes.push_back(*l_it);
            }
        }

        if(l_tmpFaillanes.size() > i_threshold)
        {
            FAPI_ERR("charmModeThresholdExceed: eRepair threshold exceed error"
                     " seen in Rx side. Threshold: %d", i_threshold);

            l_thresholdExceed = true;
            break;
        }
    }while(0);

    return l_thresholdExceed;
}
#endif
