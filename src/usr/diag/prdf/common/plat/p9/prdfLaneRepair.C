/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfLaneRepair.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/** @file prdfLaneRepair.C */

#include <prdfLaneRepair.H>

// Framework includes
#include <prdfPluginDef.H>
#include <prdfLaneRepair.H>
#include <prdfPlatServices.H>
#include <iipconst.h>
#include <prdfGlobal.H>
#include <iipSystem.h>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <UtilHash.H>

#include <prdfP9ProcMbCommonExtraSig.H>
#include <hwas/common/hwasCallout.H>

using namespace TARGETING;

namespace PRDF
{
using namespace PlatServices;

namespace LaneRepair
{

TargetHandle_t getTxBusEndPt( TargetHandle_t i_rxTrgt)
{
    TargetHandle_t o_txTrgt = nullptr;

    PRDF_ASSERT(nullptr != i_rxTrgt);

    TYPE busType = getTargetType(i_rxTrgt);
    if ( TYPE_XBUS == busType || TYPE_OBUS == busType )
    {
        o_txTrgt = getConnectedPeerTarget( i_rxTrgt );
    }

    PRDF_ASSERT(nullptr != o_txTrgt);
    return o_txTrgt;
}

int32_t handleLaneRepairEvent( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc,
                               bool i_spareDeployed )
{
    #define PRDF_FUNC "[LaneRepair::handleLaneRepairEvent] "

    int32_t l_rc = SUCCESS;
    TargetHandle_t rxBusTgt = i_chip->getTrgt();
    TargetHandle_t txBusTgt = nullptr;
    TYPE busType = getTargetType(rxBusTgt);

    // Make predictive on first occurrence in MFG
    if (isFabeRepairDisabled())
    {
        i_sc.service_data->setServiceCall();
    }

    // RTC 174485
    // Need HWPs for this. Just callout bus interface for now.
    if (busType == TYPE_OBUS)
    {
        if ( obusInSmpMode(rxBusTgt) )
        {
            calloutBusInterface( i_chip, i_sc, MRU_LOW );
            i_sc.service_data->setServiceCall();
        }
        else
        {
            PRDF_ERR( PRDF_FUNC "Lane repair only supported in SMP mode "
                      "obus: 0x%08x", getHuid(rxBusTgt) );
            i_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED, NO_GARD );
            i_sc.service_data->SetCallout( SP_CODE, MRU_MED, NO_GARD );
            i_sc.service_data->setServiceCall(); 
        }
        return SUCCESS;
    }

    bool thrExceeded;
    // Number of clock groups on this interface. (2 for xbus, 1 for all others)
    uint8_t clkGrps = (busType == TYPE_XBUS) ? 2 : 1;
    std::vector<uint8_t> rx_lanes[2];    // Failing lanes on clock group 0/1
    // RX-side, previously failed laned lanes stored in VPD for each clk grp
    std::vector<uint8_t> rx_vpdLanes[2];
    // TX-side, previously failed laned lanes stored in VPD for each clk grp
    std::vector<uint8_t> tx_vpdLanes[2];
    BitStringBuffer l_newLaneMap0to63(64); // FFDC Bitmap of newly failed lanes
    BitStringBuffer l_newLaneMap64to127(64);
    BitStringBuffer l_vpdLaneMap0to63(64); // FFDC Bitmap of VPD failed lanes
    BitStringBuffer l_vpdLaneMap64to127(64);

    do
    {
        // Get the TX target
        txBusTgt = getTxBusEndPt(rxBusTgt);

        // Call io_read_erepair for each group
        for (uint8_t i=0; i<clkGrps; ++i)
        {
            l_rc = readErepairXbus(rxBusTgt, rx_lanes[i], i);
            if (SUCCESS != l_rc)
            {
                PRDF_ERR( PRDF_FUNC "readErepair() failed: rxBusTgt=0x%08x",
                          getHuid(rxBusTgt) );
                break;
            }

            // Add newly failed lanes to capture data
            for ( auto & lane : rx_lanes[i] )
            {
                if (lane < 64)
                    l_newLaneMap0to63.setBit(lane);
                else if (lane < 128)
                    l_newLaneMap64to127.setBit(lane - 64);
                else
                {
                    PRDF_ERR( PRDF_FUNC "Invalid lane number %d: "
                              "rxBusTgt=0x%08x", lane, getHuid(rxBusTgt) );
                }
            }
        }

        if ( SUCCESS != l_rc) break;

        // Add failed lane capture data to errorlog
        i_sc.service_data->GetCaptureData().Add(i_chip->GetChipHandle(),
                                ( Util::hashString("ALL_FAILED_LANES_0TO63") ^
                                  i_chip->getSignatureOffset() ),
                                l_newLaneMap0to63);
        i_sc.service_data->GetCaptureData().Add(i_chip->GetChipHandle(),
                                ( Util::hashString("ALL_FAILED_LANES_64TO127") ^
                                  i_chip->getSignatureOffset() ),
                                l_newLaneMap64to127);

        // Don't read/write VPD in mfg mode if erepair is disabled
        // TODO RTC: 174485 - Add support for OBUS/DMI
        if ( (TYPE_XBUS == busType) && (!isFabeRepairDisabled()) )
        {
            // Read Failed Lanes from VPD
            for (uint8_t i=0; i<clkGrps; ++i)
            {
                l_rc = getVpdFailedLanesXbus(rxBusTgt, rx_vpdLanes[i],
                                             tx_vpdLanes[i], i);
                if (SUCCESS != l_rc)
                {
                    PRDF_ERR( PRDF_FUNC "getVpdFailedLanes() failed: "
                              "rxBusTgt=0x%08x", getHuid(rxBusTgt) );
                    break;
                }

                // Add VPD lanes to capture data
                for ( auto & lane : rx_vpdLanes[i] )
                {
                    if (lane < 64)
                        l_vpdLaneMap0to63.setBit(lane);
                    else if (lane < 128)
                        l_vpdLaneMap64to127.setBit(lane - 64);
                    else
                    {
                        PRDF_ERR( PRDF_FUNC "Invalid VPD lane number %d: "
                                  "rxBusTgt=0x%08x", lane, getHuid(rxBusTgt) );
                    }
                }
            }

            if ( SUCCESS != l_rc) break;

            // Add failed lane capture data to errorlog
            i_sc.service_data->GetCaptureData().Add(i_chip->GetChipHandle(),
                                ( Util::hashString("VPD_FAILED_LANES_0TO63") ^
                                  i_chip->getSignatureOffset() ),
                                l_vpdLaneMap0to63);
            i_sc.service_data->GetCaptureData().Add(i_chip->GetChipHandle(),
                               ( Util::hashString("VPD_FAILED_LANES_64TO127") ^
                                 i_chip->getSignatureOffset() ),
                               l_vpdLaneMap64to127);

            if (i_spareDeployed)
            {
                for (uint8_t i=0; i<clkGrps; ++i)
                {
                    if (rx_lanes[i].size() == 0)
                        continue;

                    // Call Erepair to update VPD
                    l_rc = setVpdFailedLanesXbus(rxBusTgt, txBusTgt,
                                                 rx_lanes[i], thrExceeded, i);
                    if (SUCCESS != l_rc)
                    {
                        PRDF_ERR( PRDF_FUNC "setVpdFailedLanes() failed: "
                                  "rxBusTgt=0x%08x txBusTgt=0x%08x",
                                  getHuid(rxBusTgt), getHuid(txBusTgt) );
                        break;
                    }
                    if( thrExceeded )
                    {
                        i_sc.service_data->SetErrorSig(
                                              PRDFSIG_ERepair_FWThrExceeded );
                        i_sc.service_data->setServiceCall();
                        break;
                    }
                    else
                    {
                        // Update lists of lanes from VPD
                        rx_vpdLanes[i].clear(); tx_vpdLanes[i].clear();
                        l_rc = getVpdFailedLanesXbus(rxBusTgt, rx_vpdLanes[i],
                                                     tx_vpdLanes[i], i);
                        if (SUCCESS != l_rc)
                        {
                            PRDF_ERR( PRDF_FUNC
                                      "getVpdFailedLanes() before power down "
                                      "failed: rxBusTgt=0x%08x",
                                      getHuid(rxBusTgt) );
                            break;
                        }

                        // Power down all lanes that have been saved in VPD
                        l_rc = powerDownLanesXbus(rxBusTgt, rx_vpdLanes[i],
                                                  tx_vpdLanes[i], i);
                        if (SUCCESS != l_rc)
                        {
                            PRDF_ERR( PRDF_FUNC "powerDownLanes() failed: "
                                      "rxBusTgt=0x%08x", getHuid(rxBusTgt) );
                            break;
                        }
                    }
                }

                if ( SUCCESS != l_rc) break;

            }
        }
    } while (0);

    // Clear FIRs
    l_rc |= clearIOFirsXbus(rxBusTgt);

    // This return code gets returned by the plugin code back to the rule code.
    // So, we do not want to give a return code that the rule code does not
    // understand. So far, there is no need return a special code, so always
    // return SUCCESS.
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "i_chip: 0x%08x busType:%d",
                  i_chip->GetId(), busType );

        i_sc.service_data->SetErrorSig(PRDFSIG_ERepair_ERROR);
        i_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_MED, NO_GARD);
        i_sc.service_data->SetCallout(SP_CODE, MRU_MED, NO_GARD);
        i_sc.service_data->setServiceCall();
    }

    return SUCCESS;

    #undef PRDF_FUNC
}

int32_t calloutBusInterface( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc,
                             PRDpriority i_priority )
{
    #define PRDF_FUNC "[PrdfLaneRepair::calloutBusInterface] "

    int32_t rc = SUCCESS;

    do {
        // Get both endpoints
        TargetHandle_t rxTrgt = i_chip->getTrgt();
        TYPE rxType = getTargetType(rxTrgt);

        if ( rxType == TYPE_OBUS && !obusInSmpMode( rxTrgt ) )
        {
            // There is no support in hostboot for calling out the other end of
            // an NV or openCAPI bus. By design, any FIR bits associated with
            // those bus types should not be taking a CalloutBusInterface
            // action. So if we hit this case, just make a default callout.

            PRDF_ERR( PRDF_FUNC "Lane repair only supported in SMP mode "
                      "obus: 0x%08x", getHuid(rxTrgt) );

            i_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED, NO_GARD );
            i_sc.service_data->SetCallout( SP_CODE, MRU_MED, NO_GARD );
            i_sc.service_data->setServiceCall();
            break;
        }

        TargetHandle_t txTrgt = getTxBusEndPt(rxTrgt);
        TYPE txType = getTargetType(txTrgt);

        // Add the endpoint target callouts
        i_sc.service_data->SetCallout( rxTrgt, MRU_MEDA );
        i_sc.service_data->SetCallout( txTrgt, MRU_MEDA);

        // Get the HWAS bus type.
        HWAS::busTypeEnum hwasType = HWAS::X_BUS_TYPE;

        if ( TYPE_XBUS == rxType && TYPE_XBUS == txType )
        {
            hwasType = HWAS::X_BUS_TYPE;
        }
        else if ( TYPE_OBUS == rxType && TYPE_OBUS == txType )
        {
            hwasType = HWAS::O_BUS_TYPE;
        }
        else
        {
            PRDF_ASSERT( false );
        }

        // Get the global error log.
        errlHndl_t errl = NULL;
        errl = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
        if ( NULL == errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get the global error log" );
            rc = FAIL; break;
        }

        // Callout this bus interface.
        PRDF_ADD_BUS_CALLOUT( errl, rxTrgt, txTrgt, hwasType, i_priority );

    } while(0);

    return rc;

    #undef PRDF_FUNC
}

// Lane Repair Rule Plugins

/**
 * @brief  Handles Spare Lane Deployed Event
 * @param  i_chip XBUS chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t spareDeployed( ExtensibleChip * i_chip,
                       STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
        return handleLaneRepairEvent(i_chip, io_sc, true);
    else
        return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_xbus, LaneRepair, spareDeployed );
PRDF_PLUGIN_DEFINE_NS( p9_obus, LaneRepair, spareDeployed );

/**
 * @brief  Handles Max Spares Exceeded Event
 * @param  i_chip XBUS chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t maxSparesExceeded( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
        return handleLaneRepairEvent(i_chip, io_sc, false);
    else
        return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_xbus, LaneRepair, maxSparesExceeded );
PRDF_PLUGIN_DEFINE_NS( p9_obus, LaneRepair, maxSparesExceeded );

/**
 * @brief  Handles Too Many Bus Errors Event
 * @param  i_chip XBUS chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t tooManyBusErrors( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
        return handleLaneRepairEvent(i_chip, io_sc, false);
    else
        return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_xbus, LaneRepair, tooManyBusErrors );
PRDF_PLUGIN_DEFINE_NS( p9_obus, LaneRepair, tooManyBusErrors );

/**
 * @brief Add callouts for a BUS interface
 * @param  i_chip Bus endpt chip
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t calloutBusInterfacePlugin( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc )
{
    calloutBusInterface(i_chip, io_sc, MRU_LOW);
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p9_xbus, LaneRepair, calloutBusInterfacePlugin );
PRDF_PLUGIN_DEFINE_NS( p9_obus, LaneRepair, calloutBusInterfacePlugin );

} // end namespace LaneRepair

} // end namespace PRDF

