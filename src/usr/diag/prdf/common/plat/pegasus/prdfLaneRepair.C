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
#include <prdfCenMembufDataBundle.H>
#include <prdfP8McsDataBundle.H>

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

    if ( i_spareDeployed )
    {
        l_rc |= cleanupSecondaryFirBits( i_chip, i_busType, i_busPos );
    }
    return l_rc;
}

//-----------------------------------------------------------------------------

bool isSpareBitOnDMIBus( ExtensibleChip * i_mcsChip, ExtensibleChip * i_mbChip )
{
    bool bitOn = false;

    do
    {
        // If any of these object is NULL, spare bit should not be on.
        if ( ( NULL == i_mcsChip ) || ( NULL == i_mbChip ))
            break;

        // check spare deployed bit on Centaur side
        SCAN_COMM_REGISTER_CLASS * dmiFir = i_mbChip->getRegister( "DMIFIR" );
        int32_t rc = dmiFir->Read();
        if ( SUCCESS != rc )
        {
            PRDF_ERR("isSpareBitOnDMIBus() : Failed to read DMIFIR."
                      "MEMBUF: 0x%08X", getHuid( i_mbChip->GetChipHandle()) );
            break;
        }
        if ( dmiFir->IsBitSet( 9 ))
        {
            bitOn = true;
            break;
        }

        // check spare deployed bit on Proc side
        TargetHandle_t mcsTgt = i_mcsChip->GetChipHandle();
        TargetHandle_t procTgt = getConnectedParent( mcsTgt, TYPE_PROC );
        ExtensibleChip * procChip =
                        ( ExtensibleChip * )systemPtr->GetChip( procTgt );

        uint32_t mcsPos = getTargetPosition( mcsTgt );

        const char * regStr = ( 4 > mcsPos) ? "IOMCFIR_0" : "IOMCFIR_1";
        SCAN_COMM_REGISTER_CLASS * iomcFir = procChip->getRegister( regStr );
        rc = iomcFir->Read();
        if ( SUCCESS != rc )
        {
            PRDF_ERR("isSpareBitOnDMIBus() : Failed to read %s."
                      "MCS: 0x%08X", regStr, getHuid(mcsTgt) );
            break;
        }
        // Bit 9, 17, 25 and 33 are for spare deployed.
        // Check bit corrosponding to MCS position
        uint8_t bitPos = 9 + ( mcsPos % 4 ) *8;
        if ( iomcFir->IsBitSet(bitPos))
        {
            bitOn = true;
        }

    }while(0);

    return bitOn;
}

//-----------------------------------------------------------------------------

int32_t cleanupSecondaryFirBits( ExtensibleChip * i_chip,
                       TYPE i_busType,
                       uint32_t i_busPos )
{
    int32_t l_rc = SUCCESS;
    TargetHandle_t mcsTgt = NULL;
    TargetHandle_t mbTgt = NULL;
    ExtensibleChip * mcsChip = NULL;
    ExtensibleChip * mbChip = NULL;

    //In case of spare deployed attention for DMI bus, we need to clear
    // secondary MBIFIR[10] and MCIFIR[10] bits.
    if ( i_busType == TYPE_MCS )
    {
        mcsTgt = getConnectedChild( i_chip->GetChipHandle(),
                                      TYPE_MCS,
                                      i_busPos);
        mcsChip = ( ExtensibleChip * )systemPtr->GetChip( mcsTgt );
        mbChip =  getMcsDataBundle( mcsChip )->getMembChip();
        mbTgt =   mbChip->GetChipHandle();

    }
    else if ( i_busType == TYPE_MEMBUF )
    {
        mbTgt = i_chip->GetChipHandle();
        mcsChip = getMembufDataBundle( i_chip )->getMcsChip();
        mcsTgt  = mcsChip->GetChipHandle();
        mbChip = i_chip;
    }

    if ( ( NULL != mcsChip ) && ( NULL != mbChip ))
    {
        SCAN_COMM_REGISTER_CLASS * mciFir =
                                    mcsChip->getRegister( "MCIFIR" );
        int32_t rc = mciFir->Read();
        if ( SUCCESS != rc )
        {
            PRDF_ERR("cleanupSecondaryFirBits() : Failed to read MCIFIR."
                     "MCS: 0x%08X", getHuid(mcsTgt) );
            l_rc |= rc;
        }
        else if ( mciFir->IsBitSet(10))
        {
            mciFir->ClearBit(10);
            l_rc |= mciFir->Write();
        }

        SCAN_COMM_REGISTER_CLASS * mbiFir =
                                    mbChip->getRegister( "MBIFIR" );
        rc = mbiFir->Read();
        if ( SUCCESS != rc )
        {
            PRDF_ERR("cleanupSecondaryFirBits() : Failed to read MBIFIR."
                     "MEMBUF: 0x%08X", getHuid(mbTgt) );
            l_rc |= rc;
        }
        else if ( mbiFir->IsBitSet(10))
        {
            mbiFir->ClearBit(10);
            l_rc |= mbiFir->Write();
        }
    }
    return l_rc;
}

} // end namespace LaneRepair
} // end namespace PRDF
