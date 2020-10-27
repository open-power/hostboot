/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfLaneRepair.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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

#include <prdfLaneRepairExtraSig.H>
#include <hwas/common/hwasCallout.H>

#ifndef __HOSTBOOT_MODULE
#include <hwsvSvrErrl.H>
#endif // not hostboot module


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
    else if (TYPE_DMI == busType)
    {
        // Get connected memory buffer
        o_txTrgt = getConnectedChild( i_rxTrgt, TYPE_MEMBUF, 0 );
    }
    else if (TYPE_MEMBUF == busType)
    {
        // grab connected DMI parent
        o_txTrgt = getConnectedParent( i_rxTrgt, TYPE_DMI );
    }
    else if ( TYPE_OMI == busType )
    {
        // Get connected child OCMB (one OCMB per OMI)
        o_txTrgt = getConnectedChild( i_rxTrgt, TYPE_OCMB_CHIP, 0 );
    }
    else if ( TYPE_OCMB_CHIP == busType )
    {
        // Get connected parent OMI
        o_txTrgt = getConnectedParent( i_rxTrgt, TYPE_OMI );
    }

    PRDF_ASSERT(nullptr != o_txTrgt);
    return o_txTrgt;
}

// Wrapper to check appropriate eRepair MNFG flag
template<TYPE T>
bool isLaneRepairDisabled();

template<>
bool isLaneRepairDisabled<TYPE_OBUS>()
{
    return isFabeRepairDisabled();
}
template<>
bool isLaneRepairDisabled<TYPE_XBUS>()
{
    return isFabeRepairDisabled();
}
template<>
bool isLaneRepairDisabled<TYPE_DMI>()
{
    return isMemeRepairDisabled();
}
template<>
bool isLaneRepairDisabled<TYPE_MEMBUF>()
{
    return isMemeRepairDisabled();
}


template< TYPE T_RX, TYPE T_TX >
int32_t __handleLaneRepairEvent( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & i_sc,
                                 bool i_spareDeployed )
{
    #define PRDF_FUNC "[LaneRepair::handleLaneRepairEvent] "

    int32_t l_rc = SUCCESS;
    TargetHandle_t rxBusTgt = i_chip->getTrgt();
    TargetHandle_t txBusTgt = nullptr;


    // Make predictive on first occurrence in MFG
    if ( isLaneRepairDisabled<T_RX>() )
    {
        i_sc.service_data->setServiceCall();
    }


    bool thrExceeded;
    // Number of clock groups on this interface. (2 for xbus, 1 for all others)
    uint8_t clkGrps = (T_RX == TYPE_XBUS) ? 2 : 1;
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
            l_rc = readErepair<T_RX>(rxBusTgt, rx_lanes[i], i);
            if (SUCCESS != l_rc)
            {
                PRDF_ERR( PRDF_FUNC "readErepair() failed: rxBusTgt=0x%08x",
                          getHuid(rxBusTgt) );
                break;
            }

            // Add newly failed lanes to capture data
            for ( auto lane : rx_lanes[i] )
            {
                lane += i * 16; // Adjust for multiple clock groups (XBUS only).
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
        if ( !isLaneRepairDisabled<T_RX>() )
        {
            // Read Failed Lanes from VPD
            for (uint8_t i=0; i<clkGrps; ++i)
            {
                l_rc = getVpdFailedLanes<T_RX>(rxBusTgt, rx_vpdLanes[i],
                                               tx_vpdLanes[i], i);

                if (SUCCESS != l_rc)
                {
                    PRDF_ERR( PRDF_FUNC "getVpdFailedLanes() failed: "
                              "rxBusTgt=0x%08x", getHuid(rxBusTgt) );
                    break;
                }

                // Add VPD lanes to capture data
                for ( auto lane : rx_vpdLanes[i] )
                {
                    lane += i * 16; // Adjust for multiple clock groups (XBUS
                                    // only).
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
            } // end Read Failed Lanes from VPD

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
                    l_rc = setVpdFailedLanes<T_RX, T_TX>(rxBusTgt, txBusTgt,
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
                        l_rc = getVpdFailedLanes<T_RX>( rxBusTgt,
                                                        rx_vpdLanes[i],
                                                        tx_vpdLanes[i], i );

                        if (SUCCESS != l_rc)
                        {
                            PRDF_ERR( PRDF_FUNC
                                      "getVpdFailedLanes() before power down "
                                      "failed: rxBusTgt=0x%08x",
                                      getHuid(rxBusTgt) );
                            break;
                        }

                        // Power down all lanes that have been saved in VPD
                        l_rc = powerDownLanes<T_RX>( rxBusTgt, rx_vpdLanes[i],
                                                     tx_vpdLanes[i], i );
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
    l_rc |= clearIOFirs<T_RX>(rxBusTgt);

    // This return code gets returned by the plugin code back to the rule code.
    // So, we do not want to give a return code that the rule code does not
    // understand. So far, there is no need return a special code, so always
    // return SUCCESS.
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "i_chip: 0x%08x busType:%d",
                  i_chip->GetId(), T_RX );

        i_sc.service_data->SetErrorSig(PRDFSIG_ERepair_ERROR);
        i_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_MED, NO_GARD);
        i_sc.service_data->SetCallout(SP_CODE, MRU_MED, NO_GARD);
        i_sc.service_data->setServiceCall();
    }

    return SUCCESS;

    #undef PRDF_FUNC
}

int32_t handleLaneRepairEvent( ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc,
                               bool i_spareDeployed )
{
    int32_t rc = SUCCESS;
    TYPE trgtType = getTargetType(i_chip->getTrgt());
    switch (trgtType)
    {
      case TYPE_XBUS:
        rc = __handleLaneRepairEvent<TYPE_XBUS,TYPE_XBUS>( i_chip, i_sc,
                                                           i_spareDeployed );
        break;
      case TYPE_DMI:
        rc = __handleLaneRepairEvent<TYPE_DMI,TYPE_MEMBUF>( i_chip, i_sc,
                                                            i_spareDeployed );
        break;
      case TYPE_MEMBUF:
        rc = __handleLaneRepairEvent<TYPE_MEMBUF,TYPE_DMI>( i_chip, i_sc,
                                                            i_spareDeployed );
        break;

      default:
        PRDF_ASSERT( false );  // Unsupported type for handleLaneRepairEvent
    }
    return rc;
}


void   obus_smpCallout( TargetHandle_t i_smpTgt, TargetHandle_t i_obusTgt,
                        STEP_CODE_DATA_STRUCT & i_sc )
{
    errlHndl_t l_mainElog = NULL;
    l_mainElog = ServiceGeneratorClass::ThisServiceGenerator().getErrl();

    if ( NULL == l_mainElog )
    {
        PRDF_ERR("smpCallout_link Failed to get the global error log" );
    }
    else
    {
        // add callout(s) on any bit firing
        // get the peer SMGROUP target associated with input SMPGROUP
        TargetHandle_t  l_smpPeerTgt =  i_smpTgt->getAttr<ATTR_PEER_TARGET>();
        PRDF_ASSERT(nullptr != l_smpPeerTgt);

    #ifdef __HOSTBOOT_MODULE
        HWAS::CalloutFlag_t calloutFlg = HWAS::FLAG_NONE;

        // Get Link position 0/1 (check if tgt pos is even/odd)
        uint32_t lnk = getTargetPosition(i_smpTgt) % 2;

        // If Link status reg has been zeroed, we know this link has failed
        ExtensibleChip *obusChip =
            (ExtensibleChip *)systemPtr->GetChip( i_obusTgt );
        SCAN_COMM_REGISTER_CLASS *lnkStat = obusChip->getRegister(
            lnk==0 ? "LINK_STATUS_REG0" : "LINK_STATUS_REG1" );

        int32_t rc = lnkStat->Read();

        if (rc != SUCCESS)
        {
            PRDF_ERR("smpCallout_link Failed to read LINK_STATUS_REG");
        }
        else if ( lnkStat->BitStringIsZero() )
        {
            calloutFlg = HWAS::FLAG_LINK_DOWN;

            // Indicate in the multi-signature section that the link has failed.
            // This allows us to know what attention we were handling in the
            // primary signature.
            i_sc.service_data->AddSignatureList(i_obusTgt, PRDFSIG_LinkFailed);

            // Make the error log predictive and mask.
            i_sc.service_data->SetThresholdMaskId(0);

            // Power down all lanes of the failed link.
            powerDownObusLink(i_obusTgt, lnk);
        }

        l_mainElog->addBusCallout( i_smpTgt, l_smpPeerTgt, HWAS::O_BUS_TYPE,
                                   HWAS::SRCI_PRIORITY_MED, calloutFlg );
    #else
        // FSP code
        #ifndef ESW_SIM_COMPILE
        errlHndl_t  l_err = NULL;

        // Call SVPD routine to add callouts
        l_err = HWSV::SvrError::AddBusCallouts( l_mainElog, i_smpTgt,
                                                l_smpPeerTgt, HWAS::O_BUS_TYPE,
                                                SRCI_PRIORITY_MED );

        if (NULL != l_err)
        {
            PRDF_ERR("AddBusCallouts failed");
            l_err->CollectTrace(PRDF_COMP_NAME, 1024);
            l_err->commit( PRDF_COMP_ID, ERRL_ACTION_REPORT );
            delete l_err;
           l_err = NULL;
        }
        #endif // not simulation

    #endif  // else FSP side
    } // main elog is non-null


} // end  obus_smpCallout - two SMP targets


/** Given an OBUS TARGET and SMP link number -- get the SMP target **/
void  obus_getSmpTarget( TargetHandle_t &i_obusTgt,
                         uint32_t i_link,
                         TargetHandle_t &o_smpTgt )
{
    PredicateCTM           l_unitMatch(CLASS_UNIT, TYPE_SMPGROUP );
    TargetHandleList       l_smpTargetList;
    uint32_t               l_smpNum    = 0;
    TYPE                   l_targType = getTargetType(i_obusTgt);


    o_smpTgt = nullptr;

    // Validate we have expected target
    if ( TYPE_OBUS != l_targType )
    {
        PRDF_ERR("obus_callout Invalid Target(%d) on link%d",
                  l_targType, i_link );
        PRDF_ASSERT(false);
    }

    // Get all SMPGROUPS associated with OBUS target
    targetService().getAssociated(
                l_smpTargetList,
                i_obusTgt,
                TARGETING::TargetService::CHILD,
                TARGETING::TargetService::ALL,
                &l_unitMatch);

    // Find the match in SMPGROUP targets
    for ( auto  l_smp : l_smpTargetList )
    {
        l_smpNum = l_smp->getAttr<ATTR_CHIP_UNIT>();

        // ==========================================
        // Link numbering from hardware is just 0:1
        //  in OBUS related FIR.
        // ==========================================
        // SMPGROUP numbering is 0:7  (2 per OBUS chiplet)
        //
        //  OBUS0  link 0:1 ->  SMGROUP 0:1
        //  OBUS1  link 0:1 ->  SMGROUP 2:3
        //  OBUS2  link 0:1 ->  SMGROUP 4:5
        //  OBUS3  link 0:1 ->  SMGROUP 6:7
        // ==========================================
        l_smpNum = l_smpNum % 2;

        if (i_link == l_smpNum)
        {
            // We found the SMPGROUP
            o_smpTgt = l_smp;
            break;
        } // end if right LINK

    } // end for on smp targets

} // end obus_getSmpTarget


/** Given the OBUS TARGET and SMP link number -- do the callout **/
void  obus_smpCallout_link( TargetHandle_t &i_obusTgt, uint32_t i_link,
                            STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[LaneRepair::obus_smpCallout_link] "

    if ( !obusInSmpMode(i_obusTgt) )
    {
        // There is no support in for calling out the other end of an NV or
        // openCAPI bus. By design, any FIR bits associated with those bus types
        // should not be driving attentions. So instead use the default callout.

        PRDF_ERR( PRDF_FUNC "Bus callouts only supported in SMP mode: "
                  "i_obusTgt=0x%08x", getHuid(i_obusTgt) );

        i_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED, NO_GARD );
        i_sc.service_data->SetCallout( SP_CODE, MRU_MED, NO_GARD );
        i_sc.service_data->setServiceCall();
    }
    else
    {
        TargetHandle_t  l_smpTarg     = nullptr;

        // Get the associated SMP target for this OBUS target
        obus_getSmpTarget( i_obusTgt, i_link, l_smpTarg );
        PRDF_ASSERT(nullptr != l_smpTarg);

        // Callout both SMPGROUPS
        obus_smpCallout( l_smpTarg, i_obusTgt, i_sc );
    }

    return;

    #undef PRDF_FUNC

} // end  obus_smpCallout_link -  smp link number


/** Given the OBUS unit number and SMP link number -- do the callout **/
void  obus_smpCallout_link( uint32_t  i_obusNum, ExtensibleChip * i_chip,
                            uint32_t i_link, STEP_CODE_DATA_STRUCT & i_sc )
{
    // From NEST so it will be a processor target
    TargetHandle_t rxTrgt = i_chip->getTrgt();

    // We need the right OBUS target from this processor
    TargetHandle_t   l_obus = getConnectedChild(rxTrgt,
                                                TYPE_OBUS, i_obusNum);

    PRDF_ASSERT( NULL != l_obus );

    // We found the right OBUS target
    obus_smpCallout_link( l_obus, i_link, i_sc );

} // end  obus_smpCallout_link - obus & smp link numbers


int32_t obus_callout_L0( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // Need the obus target
    TargetHandle_t rxTrgt = i_chip->getTrgt();
    // Call out LINK0 in SMPGROUP
    obus_smpCallout_link( rxTrgt, 0, i_sc );

    return rc;

} // end  obus_callout_L0
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  LaneRepair, obus_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, LaneRepair, obus_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   LaneRepair, obus_callout_L0 );

int32_t obus_callout_L1( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
   int32_t rc = SUCCESS;

    // Need the obus target
    TargetHandle_t rxTrgt = i_chip->getTrgt();
    // Call out LINK1 in SMPGROUP
    obus_smpCallout_link( rxTrgt, 1, i_sc );

    return rc;

} // end  obus_callout_L1
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  LaneRepair, obus_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, LaneRepair, obus_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   LaneRepair, obus_callout_L1 );

int32_t obus0_callout_L0( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // callout obus0 link0
    obus_smpCallout_link( 0, i_chip, 0, i_sc );

    return rc;

} // end obus0_callout_L0
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, obus0_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, obus0_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, obus0_callout_L0 );

int32_t obus0_callout_L1( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // callout obus0 link1
    obus_smpCallout_link( 0, i_chip, 1, i_sc );

    return rc;

} // end obus0_callout_L1
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, obus0_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, obus0_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, obus0_callout_L1 );

int32_t obus1_callout_L0( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // callout obus1 link0
    obus_smpCallout_link( 1, i_chip, 0, i_sc );

    return rc;

} // end obus1_callout_L0
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, obus1_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, obus1_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, obus1_callout_L0 );

int32_t obus1_callout_L1( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // callout obus1 link1
    obus_smpCallout_link( 1, i_chip, 1, i_sc );

    return rc;

} // end obus1_callout_L1
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, obus1_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, obus1_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, obus1_callout_L1 );

int32_t obus2_callout_L0( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // callout obus2 link0
    obus_smpCallout_link( 2, i_chip, 0, i_sc );

    return rc;

} // end obus2_callout_L0
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, obus2_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, obus2_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, obus2_callout_L0 );

int32_t obus2_callout_L1( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // callout obus2 link1
    obus_smpCallout_link( 2, i_chip, 1, i_sc );

    return rc;

} // end obus2_callout_L1
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, obus2_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, obus2_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, obus2_callout_L1 );

int32_t obus3_callout_L0( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // callout obus3 link0
    obus_smpCallout_link( 3, i_chip, 0, i_sc );

    return rc;

} // end obus3_callout_L0
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, obus3_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, obus3_callout_L0 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, obus3_callout_L0 );

int32_t obus3_callout_L1( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    // callout obus3 link0
    obus_smpCallout_link( 3, i_chip, 1, i_sc );

    return rc;

} // end obus3_callout_L1
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, obus3_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, obus3_callout_L1 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, obus3_callout_L1 );

void  obus_clearMaskFail( errlHndl_t &io_errl, TargetHandle_t &i_rxTrgt,
                          TargetHandle_t &i_txTrgt, uint32_t i_link )
{
    // ensure we have valid inputs
    PRDF_ASSERT( NULL != i_rxTrgt );
    PRDF_ASSERT( NULL != i_txTrgt );
    PRDF_ASSERT( NULL != io_errl );

#ifdef __HOSTBOOT_MODULE // register writes not allowed on FSP

    uint32_t         l_rc = SUCCESS;
    ExtensibleChip  *l_rxChip =
                            (ExtensibleChip *)systemPtr->GetChip( i_rxTrgt );
    ExtensibleChip  *l_txChip =
                            (ExtensibleChip *)systemPtr->GetChip( i_txTrgt );


    do
    {
        if (MODEL_NIMBUS == getChipModel(i_rxTrgt))
        {
            PRDF_ERR("[obus_clearMaskFail] called on NIMBUS");
            break;
        } // nimbus not supported


        // These defines are for LINK0
        // (LINK1 will be the next bit for each of these)
        #define OBUS_CRC_ERRORS     6
        #define OBUS_ECC_ERRORS    14
        #define OBUS_NO_SPARE      42
        #define OBUS_SPARE_DONE    44
        #define OBUS_TOO_MANY_CRC  46
        #define OBUS_LNK0_TRAINING_FAILED  56

        // Normal rule file handling should clear bit 56
        // or bit 57 and mask it for the target we got the
        // attention on.
        // We still need to do it for the other end of the cable.

        // Clear the FIR on other end
        SCAN_COMM_REGISTER_CLASS * obusTxFir_and = l_txChip->getRegister("IOOLFIR_AND");
        obusTxFir_and->setAllBits();
        obusTxFir_and->ClearBit(OBUS_LNK0_TRAINING_FAILED + i_link);
        // MASK the attention on the other end
        SCAN_COMM_REGISTER_CLASS * obusTxMask_or = l_txChip->getRegister("IOOLFIR_MASK_OR");
        obusTxMask_or->clearAllBits();
        obusTxMask_or->SetBit(OBUS_LNK0_TRAINING_FAILED + i_link);

        // Clear other related bits for link0 or link1
        // on the current target with the active attention
        SCAN_COMM_REGISTER_CLASS * obusRxFir_and = l_rxChip->getRegister("IOOLFIR_AND");
        obusRxFir_and->setAllBits();
        obusRxFir_and->ClearBit(OBUS_CRC_ERRORS   + i_link);
        obusRxFir_and->ClearBit(OBUS_ECC_ERRORS   + i_link);
        obusRxFir_and->ClearBit(OBUS_NO_SPARE     + i_link);
        obusRxFir_and->ClearBit(OBUS_SPARE_DONE   + i_link);
        obusRxFir_and->ClearBit(OBUS_TOO_MANY_CRC + i_link);

        // put back the MASK and FIRs to hardware
        l_rc  = obusTxMask_or->Write();
        l_rc |= obusTxFir_and->Write();
        l_rc |= obusRxFir_and->Write();

        if ( SUCCESS != l_rc )
        {
            PRDF_ERR("obus_clearMaskFail failed handling link %d", i_link);
        }

    } while (0);

#endif // __HOSTBOOT_MODULE

} // end obus_clearMaskFail



int32_t obus_fail_L0( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t rc = SUCCESS;

    TargetHandle_t  rxTrgt = i_chip->getTrgt();
    TargetHandle_t  txTrgt = getTxBusEndPt(rxTrgt);

    do
    {
        errlHndl_t l_mainElog = NULL;
        l_mainElog = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
        if ( NULL == l_mainElog )
        {
            PRDF_ERR( "obus_fail Failed to get the global error log" );
            rc = FAIL;
            break;
        }

        // invoke routine to clear and mask the failure and
        // other related bits.
        obus_clearMaskFail( l_mainElog, rxTrgt, txTrgt, 0 );

    } while(0);


    return rc;

} // end obus_fail_L0
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  LaneRepair, obus_fail_L0 );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, LaneRepair, obus_fail_L0 );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   LaneRepair, obus_fail_L0 );

int32_t obus_fail_L1( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
   int32_t rc = SUCCESS;

    TargetHandle_t  rxTrgt = i_chip->getTrgt();
    TargetHandle_t  txTrgt = getTxBusEndPt(rxTrgt);

    do
    {
        errlHndl_t l_mainElog = NULL;
        l_mainElog = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
        if ( NULL == l_mainElog )
        {
            PRDF_ERR( "obus_fail_Failed to get the global error log" );
            rc = FAIL;
            break;
        }

        // invoke routine to clear and mask the failure and
        // other related bits.
        obus_clearMaskFail( l_mainElog, rxTrgt, txTrgt, 1 );

    } while(0);

    return rc;

} // end obus_fail_L1
PRDF_PLUGIN_DEFINE_NS( nimbus_obus,  LaneRepair, obus_fail_L1 );
PRDF_PLUGIN_DEFINE_NS( cumulus_obus, LaneRepair, obus_fail_L1 );
PRDF_PLUGIN_DEFINE_NS( axone_obus,   LaneRepair, obus_fail_L1 );

/** Need routine to capture FFDC for PBIOOFIR **/
void    baseCaptureSmpFFDC( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc,
                            uint32_t  i_obusNum )
{
    // get the specific OBUS target we are interested in
    TargetHandle_t   l_obus = getConnectedChild(i_chip->getTrgt(),
                                                TYPE_OBUS, i_obusNum);

    ExtensibleChip * l_obusChip;
    l_obusChip = (ExtensibleChip *)systemPtr->GetChip(l_obus);
    // Add OBUS registers for this instance
    if( NULL != l_obusChip )
    {
        l_obusChip->CaptureErrorData(
                          io_sc.service_data->GetCaptureData(),
                          Util::hashString("smpCableFFDC"));
    }

} // baseCaptureSmpFFDC

int32_t captureSmpObus0( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    baseCaptureSmpFFDC( i_chip, io_sc, 0 );
    return SUCCESS;

} // end captureSmpObus0
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, captureSmpObus0 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, captureSmpObus0 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, captureSmpObus0 );

int32_t captureSmpObus1( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    baseCaptureSmpFFDC( i_chip, io_sc, 1 );
    return SUCCESS;

} // end captureSmpObus1
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, captureSmpObus1 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, captureSmpObus1 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, captureSmpObus1 );

int32_t captureSmpObus2( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    baseCaptureSmpFFDC( i_chip, io_sc, 2 );
    return SUCCESS;

} // end captureSmpObus2
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, captureSmpObus2 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, captureSmpObus2 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, captureSmpObus2 );

int32_t captureSmpObus3( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    baseCaptureSmpFFDC( i_chip, io_sc, 3 );
    return SUCCESS;

} // end captureSmpObus3
PRDF_PLUGIN_DEFINE_NS( cumulus_proc, LaneRepair, captureSmpObus3 );
PRDF_PLUGIN_DEFINE_NS( nimbus_proc,  LaneRepair, captureSmpObus3 );
PRDF_PLUGIN_DEFINE_NS( axone_proc,   LaneRepair, captureSmpObus3 );

int32_t calloutBusInterface( TargetHandle_t i_rxTrgt,
                             STEP_CODE_DATA_STRUCT & i_sc,
                             PRDpriority i_priority )
{
    #define PRDF_FUNC "[PrdfLaneRepair::calloutBusInterface] "

    int32_t rc = SUCCESS;

    do {
        // Get both endpoints
        TYPE rxType = getTargetType(i_rxTrgt);

        if ( rxType == TYPE_OBUS && !obusInSmpMode( i_rxTrgt ) )
        {
            // There is no support in hostboot for calling out the other end of
            // an NV or openCAPI bus. By design, any FIR bits associated with
            // those bus types should not be taking a CalloutBusInterface
            // action. So if we hit this case, just make a default callout.

            PRDF_ERR( PRDF_FUNC "Lane repair only supported in SMP mode "
                      "obus: 0x%08x", getHuid(i_rxTrgt) );

            i_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_MED, NO_GARD );
            i_sc.service_data->SetCallout( SP_CODE, MRU_MED, NO_GARD );
            i_sc.service_data->setServiceCall();
            break;
        }

        TargetHandle_t txTrgt = getTxBusEndPt(i_rxTrgt);
        TYPE txType = getTargetType(txTrgt);

        // Add the endpoint target callouts
        i_sc.service_data->SetCallout( i_rxTrgt, MRU_MEDA );
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
        else if ( (TYPE_DMI == rxType && TYPE_MEMBUF == txType) ||
                  (TYPE_MEMBUF == rxType && TYPE_DMI == txType) )
        {
            hwasType = HWAS::DMI_BUS_TYPE;
        }
        else if ( (TYPE_OMI == rxType && TYPE_OCMB_CHIP == txType) ||
                  (TYPE_OCMB_CHIP == rxType && TYPE_OMI == txType) )
        {
            hwasType = HWAS::OMI_BUS_TYPE;
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
        PRDF_ADD_BUS_CALLOUT( errl, i_rxTrgt, txTrgt, hwasType, i_priority );

    } while(0);

    return rc;

    #undef PRDF_FUNC
}



// Lane Repair Rule Plugins

/**
 * @brief  Handles Spare Lane Deployed Event
 * @param  i_chip chip.
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
PRDF_PLUGIN_DEFINE_NS( nimbus_xbus,    LaneRepair, spareDeployed );
PRDF_PLUGIN_DEFINE_NS( cumulus_xbus,   LaneRepair, spareDeployed );
PRDF_PLUGIN_DEFINE_NS( axone_xbus,     LaneRepair, spareDeployed );
PRDF_PLUGIN_DEFINE_NS( centaur_membuf, LaneRepair, spareDeployed );

/**
 * @brief  Handles Max Spares Exceeded Event
 * @param  i_chip chip.
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
PRDF_PLUGIN_DEFINE_NS( nimbus_xbus,    LaneRepair, maxSparesExceeded );
PRDF_PLUGIN_DEFINE_NS( cumulus_xbus,   LaneRepair, maxSparesExceeded );
PRDF_PLUGIN_DEFINE_NS( axone_xbus,     LaneRepair, maxSparesExceeded );
PRDF_PLUGIN_DEFINE_NS( centaur_membuf, LaneRepair, maxSparesExceeded );

/**
 * @brief  Handles Too Many Bus Errors Event
 * @param  i_chip chip
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
PRDF_PLUGIN_DEFINE_NS( nimbus_xbus,    LaneRepair, tooManyBusErrors );
PRDF_PLUGIN_DEFINE_NS( cumulus_xbus,   LaneRepair, tooManyBusErrors );
PRDF_PLUGIN_DEFINE_NS( axone_xbus,     LaneRepair, tooManyBusErrors );
PRDF_PLUGIN_DEFINE_NS( centaur_membuf, LaneRepair, tooManyBusErrors );

/**
 * @brief Add callouts for a BUS interface
 * @param  i_chip Bus endpt chip
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t calloutBusInterfacePlugin( ExtensibleChip * i_chip,
                                   STEP_CODE_DATA_STRUCT & io_sc )
{
    calloutBusInterface(i_chip->getTrgt(), io_sc, MRU_LOW);
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( nimbus_xbus,    LaneRepair, calloutBusInterfacePlugin );
PRDF_PLUGIN_DEFINE_NS( cumulus_xbus,   LaneRepair, calloutBusInterfacePlugin );
PRDF_PLUGIN_DEFINE_NS( axone_xbus,     LaneRepair, calloutBusInterfacePlugin );
PRDF_PLUGIN_DEFINE_NS( explorer_ocmb,  LaneRepair, calloutBusInterfacePlugin );
PRDF_PLUGIN_DEFINE_NS( cumulus_dmi,    LaneRepair, calloutBusInterfacePlugin );
PRDF_PLUGIN_DEFINE_NS( centaur_membuf, LaneRepair, calloutBusInterfacePlugin );

/**
 * @brief Add callouts for a BUS interface inputting an OMIC or MCC target
 * @param  i_chip OMIC/MCC chip
 * @param  io_sc  Step code data struct.
 * @param  i_pos  The position of the OMI relative to the OMIC/MCC.
 * @return SUCCESS always
 */

int32_t omiParentCalloutBusInterfacePlugin( ExtensibleChip * i_chip,
                                            STEP_CODE_DATA_STRUCT & io_sc,
                                            uint8_t i_pos )
{
    TargetHandle_t omi  = getConnectedChild(i_chip->getTrgt(), TYPE_OMI, i_pos);
    PRDF_ASSERT( nullptr != omi );
    TargetHandle_t ocmb = getConnectedChild( omi, TYPE_OCMB_CHIP, 0 );
    PRDF_ASSERT( nullptr != ocmb );

    // Callout both ends of the bus as well (OMI and OCMB)
    io_sc.service_data->SetCallout( omi,  MRU_MEDA );
    io_sc.service_data->SetCallout( ocmb, MRU_MEDA );

    calloutBusInterface(omi, io_sc, MRU_LOW);
    return SUCCESS;
}

#define OMI_PARENT_CALL_BUS_PLUGIN( POS ) \
int32_t omiParentCalloutBusInterfacePlugin_##POS( ExtensibleChip * i_chip, \
                                               STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return omiParentCalloutBusInterfacePlugin( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE_NS( axone_omic, LaneRepair, \
                       omiParentCalloutBusInterfacePlugin_##POS );\
PRDF_PLUGIN_DEFINE_NS( axone_mcc, LaneRepair, \
                       omiParentCalloutBusInterfacePlugin_##POS );

OMI_PARENT_CALL_BUS_PLUGIN( 0 );
OMI_PARENT_CALL_BUS_PLUGIN( 1 );
OMI_PARENT_CALL_BUS_PLUGIN( 2 );

//------------------------------------------------------------------------------

#define CREATE_CALL_CHILD_LANE_REPAIR_FUNCTION( PLUGIN_FUNCTION) \
int32_t callChildLR_##PLUGIN_FUNCTION( ExtensibleChip * i_chip, \
                                      TARGETING::TYPE i_type, \
                                      uint32_t i_pos, \
                                      STEP_CODE_DATA_STRUCT & io_sc) \
{ \
    ExtensibleChip * endPoint = getConnectedChild( i_chip, i_type, i_pos ); \
\
    if ( nullptr == endPoint ) \
    { \
        PRDF_ERR( "[callLaneRepairRulePluginOnChild_##TYPE] Connection lookup failed:" \
            " 0x%08x 0x%02x %d", i_chip->getHuid(), i_type, i_pos ); \
        io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_HIGH); \
        io_sc.service_data->SetCallout(i_chip->getTrgt()); \
        io_sc.service_data->SetThresholdMaskId(0); \
    } \
    else \
    { \
        /* ignore rc as this is a plugin call */ \
        PLUGIN_FUNCTION( endPoint, io_sc ); \
    } \
\
     /* Always return SUCCESS because other rc types (ie. FAIL) */ \
     /* are not necessarily understood by plugin rule code */ \
    return SUCCESS; \
}


// Create plugin calling wrapper functions
CREATE_CALL_CHILD_LANE_REPAIR_FUNCTION( calloutBusInterfacePlugin)
CREATE_CALL_CHILD_LANE_REPAIR_FUNCTION( maxSparesExceeded)
CREATE_CALL_CHILD_LANE_REPAIR_FUNCTION( spareDeployed)
CREATE_CALL_CHILD_LANE_REPAIR_FUNCTION( tooManyBusErrors)

//------------------------------------------------------------------------------

#define PLUGIN_CALLOUT_INTERFACE( TYPE, POS ) \
int32_t calloutBusInterface_##TYPE##POS( ExtensibleChip * i_chip, \
                                         STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return callChildLR_calloutBusInterfacePlugin( i_chip, TYPE_##TYPE, POS, io_sc ); \
} \
PRDF_PLUGIN_DEFINE_NS(nimbus_proc,  LaneRepair, calloutBusInterface_##TYPE##POS);\
PRDF_PLUGIN_DEFINE_NS(cumulus_proc, LaneRepair, calloutBusInterface_##TYPE##POS); \
PRDF_PLUGIN_DEFINE_NS(axone_proc,   LaneRepair, calloutBusInterface_##TYPE##POS);

PLUGIN_CALLOUT_INTERFACE( XBUS, 0 )
PLUGIN_CALLOUT_INTERFACE( XBUS, 1 )
PLUGIN_CALLOUT_INTERFACE( XBUS, 2 )
PLUGIN_CALLOUT_INTERFACE( OBUS, 0 )
PLUGIN_CALLOUT_INTERFACE( OBUS, 1 )
PLUGIN_CALLOUT_INTERFACE( OBUS, 2 )
PLUGIN_CALLOUT_INTERFACE( OBUS, 3 )



#undef PLUGIN_CALLOUT_INTERFACE

//------------------------------------------------------------------------------

#define PLUGIN_LANE_REPAIR_DMI( TYPE, POS ) \
int32_t calloutBusInterface_##TYPE##POS( ExtensibleChip * i_chip, \
                                         STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return callChildLR_calloutBusInterfacePlugin( i_chip, TYPE_##TYPE, POS, io_sc ); \
} \
PRDF_PLUGIN_DEFINE_NS( cumulus_mc, LaneRepair, calloutBusInterface_##TYPE##POS ); \
\
int32_t maxSparesExceeded_##TYPE##POS( ExtensibleChip * i_chip, \
                                       STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return callChildLR_maxSparesExceeded( i_chip, TYPE_##TYPE, POS, io_sc ); \
} \
PRDF_PLUGIN_DEFINE_NS( cumulus_mc, LaneRepair, maxSparesExceeded_##TYPE##POS ); \
\
int32_t spareDeployed_##TYPE##POS( ExtensibleChip * i_chip, \
                                   STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return callChildLR_spareDeployed( i_chip, TYPE_##TYPE, POS, io_sc ); \
} \
PRDF_PLUGIN_DEFINE_NS( cumulus_mc, LaneRepair, spareDeployed_##TYPE##POS ); \
\
int32_t tooManyBusErrors_##TYPE##POS( ExtensibleChip * i_chip, \
                                      STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return callChildLR_tooManyBusErrors( i_chip, TYPE_##TYPE, POS, io_sc ); \
} \
PRDF_PLUGIN_DEFINE_NS( cumulus_mc, LaneRepair, tooManyBusErrors_##TYPE##POS );

// Handle the MC chip target to DMI conversion
PLUGIN_LANE_REPAIR_DMI( DMI, 0 )
PLUGIN_LANE_REPAIR_DMI( DMI, 1 )
PLUGIN_LANE_REPAIR_DMI( DMI, 2 )
PLUGIN_LANE_REPAIR_DMI( DMI, 3 )

#undef PLUGIN_LANE_REPAIR_DMI

//------------------------------------------------------------------------------


} // end namespace LaneRepair

} // end namespace PRDF

