/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfLaneRepair.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

    if ( TYPE_XBUS == getTargetType(i_rxTrgt) )
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
        TargetHandle_t i_rxTrgt = i_chip->getTrgt();
        TargetHandle_t i_txTrgt = getTxBusEndPt(i_rxTrgt);

        // Add the endpoint target callouts
        i_sc.service_data->SetCallout( i_rxTrgt, MRU_MEDA );
        i_sc.service_data->SetCallout( i_txTrgt, MRU_MEDA);

        // Get the HWAS bus type.
        HWAS::busTypeEnum hwasType;

        TYPE rxType = getTargetType(i_rxTrgt);
        TYPE txType = getTargetType(i_txTrgt);

        if ( TYPE_XBUS == rxType && TYPE_XBUS == txType )
        {
            hwasType = HWAS::X_BUS_TYPE;
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
        PRDF_ADD_BUS_CALLOUT( errl, i_rxTrgt, i_txTrgt, hwasType, i_priority );

    } while(0);

    return rc;

    #undef PRDF_FUNC
}

} // end namespace LaneRepair
} // end namespace PRDF
