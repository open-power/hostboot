/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfLaneRepair.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/** @file prdfLaneRepair.C */

#include <prdfLaneRepair.H>
#include <prdfPlatServices.H>
#include <iipconst.h>
#include <prdfGlobal.H>
#include <iipSystem.h>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <UtilHash.H>

using namespace TARGETING;

namespace PRDF
{
using namespace PlatServices;

namespace LaneRepair
{

int32_t handleLaneRepairEvent (ExtensibleChip * i_chip,
                               TYPE i_busType,
                               uint32_t i_busPos,
                               STEP_CODE_DATA_STRUCT & i_sc,
                               bool i_spareDeployed)
{
    int32_t l_rc = SUCCESS;
    TargetHandle_t rxBusTgt = NULL;
    TargetHandle_t txBusTgt = NULL;
    bool thrExceeded = true;
    std::vector<uint8_t> rx_lanes;
    std::vector<uint8_t> rx_vpdLanes;
    std::vector<uint8_t> tx_vpdLanes;
    BitStringBuffer l_vpdLaneMap0to63(64);
    BitStringBuffer l_vpdLaneMap64to127(64);
    BitStringBuffer l_newLaneMap0to63(64);
    BitStringBuffer l_newLaneMap64to127(64);

    do {
        // Get RX bus target
        TYPE iChipType = getTargetType(i_chip->GetChipHandle());

        if (iChipType == TYPE_MEMBUF)
        {
            rxBusTgt = i_chip->GetChipHandle();
        }
        else if (iChipType == TYPE_PROC)
        {
            // i_chip is a Proc, Get connected XBUS, ABUS, or MCS target
            rxBusTgt = getConnectedChild( i_chip->GetChipHandle(),
                                          i_busType, i_busPos );
            if ( NULL == rxBusTgt )
            {
                PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] HUID: 0x%08x "
                          "Couldn't find RX connected bus",
                          getHuid(i_chip->GetChipHandle()) );
                break;
            }
        }
        else
        {
            PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] HUID: 0x%08x "
                      "Not of type MEMBUF or PROC",
                      getHuid(i_chip->GetChipHandle()) );
            break;
        }

        // Add callout for RX target
        i_sc.service_data->SetCallout( rxBusTgt, MRU_MEDA );

        // Get TX bus target
        if (i_busType == TYPE_XBUS || i_busType == TYPE_ABUS)
        {
            txBusTgt = getConnectedPeerTarget(rxBusTgt);
        }
        else if (i_busType == TYPE_MEMBUF)
        {
            txBusTgt = getConnectedParent(rxBusTgt, TYPE_MCS);
        }
        else if (i_busType == TYPE_MCS)
        {
            txBusTgt = getConnectedChild(rxBusTgt, TYPE_MEMBUF, 0);
        }

        if ( NULL == txBusTgt )
        {
            PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] i_chip: 0x%08x "
                      "rxBusTgt: 0x%08x. Couldn't find TX connected bus",
                      getHuid(i_chip->GetChipHandle()),
                      getHuid(rxBusTgt));
            break;
        }

        // Add callout for TX target
        i_sc.service_data->SetCallout( txBusTgt, MRU_MEDA );

        // Call io_read_erepair
        l_rc = readErepair(rxBusTgt, rx_lanes);
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] i_chip: 0x%08x "
                      "rxBusTgt: 0x%08x. readErepair failed",
                      getHuid(i_chip->GetChipHandle()),
                      getHuid(rxBusTgt) );
            break;
        }

        // Add newly failed lanes to capture data
        for (std::vector<uint8_t>::iterator lane = rx_lanes.begin();
             lane != rx_lanes.end(); ++lane)
        {
            if (*lane < 64)
                l_newLaneMap0to63.Set(*lane);
            else if (*lane < 127)
                l_newLaneMap64to127.Set(*lane - 64);
            else
                PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] HUID: 0x%08x "
                          "rxBusTgt: 0x%08x. invalid lane number %d",
                          getHuid(i_chip->GetChipHandle()),
                          getHuid(rxBusTgt),
                          *lane );
        }
        // Add failed lane capture data to errorlog
        i_sc.service_data->GetCaptureData().Add(i_chip->GetChipHandle(),
                                    Util::hashString("NEW_FAILED_LANES_0TO63"),
                                    l_newLaneMap0to63);
        i_sc.service_data->GetCaptureData().Add(i_chip->GetChipHandle(),
                                    Util::hashString("NEW_FAILED_LANES_64TO127"),
                                    l_newLaneMap64to127);

        if (!mfgMode()) // Don't read/write VPD in mfg mode
        {
            // Read Failed Lanes from VPD
            l_rc = getVpdFailedLanes(rxBusTgt, rx_vpdLanes, tx_vpdLanes);
            if (SUCCESS != l_rc)
            {
                PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] HUID: 0x%08x "
                          "rxBusTgt: 0x%08x. getVpdFailedLanes failed",
                          getHuid(i_chip->GetChipHandle()),
                          getHuid(rxBusTgt) );
                break;
            }

            // Add VPD lanes to capture data
            for (std::vector<uint8_t>::iterator lane = rx_vpdLanes.begin();
                 lane != rx_vpdLanes.end(); ++lane)
            {
                if (*lane < 64)
                    l_vpdLaneMap0to63.Set(*lane);
                else if (*lane < 127)
                    l_vpdLaneMap64to127.Set(*lane - 64);
                else
                    PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] "
                              "HUID: 0x%08x rxBusTgt: 0x%08x "
                              "invalid vpd lane number %d",
                              getHuid(i_chip->GetChipHandle()),
                              getHuid(rxBusTgt),
                              *lane );
            }
            // Add failed lane capture data to errorlog
            i_sc.service_data->GetCaptureData().Add(i_chip->GetChipHandle(),
                                                 Util::hashString(
                                                   "VPD_FAILED_LANES_0TO63"),
                                                 l_vpdLaneMap0to63);
            i_sc.service_data->GetCaptureData().Add(i_chip->GetChipHandle(),
                                                 Util::hashString(
                                                   "VPD_FAILED_LANES_64TO127"),
                                                 l_vpdLaneMap64to127);
            if (i_spareDeployed)
            {
                // Call Erepair to update VPD
                l_rc = setVpdFailedLanes(rxBusTgt, txBusTgt,
                                         rx_lanes, thrExceeded);
                if (SUCCESS != l_rc)
                {
                    PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] "
                              "HUID: 0x%08x setVpdFailedLanes failed"
                              "Tx: 0x%08x Rx: 0x%08x",
                              getHuid(i_chip->GetChipHandle()),
                              getHuid(txBusTgt), getHuid(rxBusTgt));
                    break;
                }
            }
        }

        if (i_spareDeployed && !thrExceeded)
        {
            // Update lists of lanes from VPD
            rx_vpdLanes.clear(); tx_vpdLanes.clear();
            l_rc = getVpdFailedLanes(rxBusTgt, rx_vpdLanes, tx_vpdLanes);
            if (SUCCESS != l_rc)
            {
                PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] HUID: 0x%08x "
                          "getVpdFailedLanes before power down failed"
                          "rxBusTgt: 0x%08x",
                          getHuid(i_chip->GetChipHandle()),
                          getHuid(rxBusTgt));
                break;
            }

            // Power down all lanes that have been saved in VPD
            l_rc = powerDownLanes(rxBusTgt, rx_vpdLanes, tx_vpdLanes);
            if (SUCCESS != l_rc)
            {
                PRDF_ERR( "[LaneRepair::handleLaneRepairEvent] HUID: 0x%08x "
                          "powerDownLanes failed rxBusTgt: 0x%08x",
                          getHuid(i_chip->GetChipHandle()),
                          getHuid(rxBusTgt));
                break;
            }
        }
        else
        {
            // Make predictive
            i_sc.service_data->SetServiceCall();
        }

    } while (0);

    // Clear FIRs
    if (rxBusTgt)
    {
        l_rc |= erepairFirIsolation(rxBusTgt);
        l_rc |= clearIOFirs(rxBusTgt);
    }

    return l_rc;
}

} // end namespace MemUtil
} // end namespace PRDF
