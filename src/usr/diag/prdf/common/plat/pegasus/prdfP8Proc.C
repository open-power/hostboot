/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Proc.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

/** @file  prdfP8Proc.C
 *  @brief Contains all the plugin code for the PRD P8 Proc
 */
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>
#include <prdfLaneRepair.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Proc
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the P8 Mba data bundle.
 * @param  i_chip P8 chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_chip )
{
    // FIXME: Add proper initialization as per requirement
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, Initialize );

/**
 * @brief Checks the Global Broadcast register.
 * @param i_reg - the global recoverable register
 * @param i_tpReg - the TP chiplet recoverable register
 * @return true if only MC bits are on.
 */
static inline bool OnlyMcRec (SCAN_COMM_REGISTER_CLASS * i_reg,
                              SCAN_COMM_REGISTER_CLASS * i_tpReg)
{
    bool rc = false;

    if ( (0 == i_reg->GetBitFieldJustified(2,23)) &&
         (0 == i_tpReg->GetBitFieldJustified(1,2)) &&
         (0 != i_tpReg->GetBitFieldJustified(3,8)) &&
         (0 == i_tpReg->GetBitFieldJustified(11,8)) )
    {
        rc = true;
    }
    return rc;
}

/**
 * @brief Checks the GLobal CS Brodacast register and
 *        the PBXSTP Chiplet register
 * @param i_glcs - the Global CS Broadcast register
 * @param i_tpcs - the TPXSTP register
 * @param i_pbcs - the PBXSTP register
 * @return true if only mem bits are on in CS, or,
 *         if the only other CS is External CS.
 */
static inline bool OnlyMcOrExtCS (SCAN_COMM_REGISTER_CLASS * i_glcs,
                                  SCAN_COMM_REGISTER_CLASS * i_tpCs,
                                  SCAN_COMM_REGISTER_CLASS * i_pbcs)
{
    bool rc = false;

    if (((0 == i_glcs->GetBitFieldJustified(3,22)) && //No CS besides TP and PB
         (0 == i_tpCs->GetBitFieldJustified(3,2 )) && //No CS in TP besides MCs
         (0 == i_tpCs->GetBitFieldJustified(13,8)))   //No CS in TP besides MCs
        &&                                            //and
        (((!i_glcs->IsBitSet(2)) &&                   // if its not from PB
          (0 != i_tpCs->GetBitFieldJustified(5,8)))   // and it is from a MC
         ||                                           //   or
         ((i_glcs->IsBitSet(2)) &&                    // it is from PB
          (i_pbcs->IsBitSet(2)) &&                    // and its external
          (0 == i_pbcs->GetBitFieldJustified(3,18)))))// and nothing else in PB
    {
        rc = true;
    }

    return rc;
}

/**
 * @brief Used when the chip has a CHECK_STOP attention to check for the
 * presence of recovered errors.
 * @param  i_chip - P8 chip.
 * @param o_hasRecovered - true if chip has a recovered that we want to analyze
 * @return SUCCESS
 */
int32_t CheckForRecovered(ExtensibleChip * i_chip,
                          bool & o_hasRecovered)
{
    o_hasRecovered = false;
    int32_t o_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * l_rer =
      i_chip->getRegister("GLOBAL_RE_FIR");
    o_rc |= l_rer->Read();

    SCAN_COMM_REGISTER_CLASS * l_TPrer =
      i_chip->getRegister("TP_CHIPLET_RE_FIR");
    o_rc |= l_TPrer->Read();

    SCAN_COMM_REGISTER_CLASS * l_TPxstp =
      i_chip->getRegister("TP_CHIPLET_CS_FIR");
    o_rc |= l_TPxstp->Read();

    SCAN_COMM_REGISTER_CLASS * l_xstop =
      i_chip->getRegister("GLOBAL_CS_FIR");
    o_rc |= l_xstop->Read();

    SCAN_COMM_REGISTER_CLASS * l_pbXstpFir =
      i_chip->getRegister("PB_CHIPLET_CS_FIR");
    o_rc |= l_pbXstpFir->Read();

    if (o_rc)
    {
        PRDF_ERR( "[CheckForRecovered] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), o_rc);
        return o_rc;
    }

    if ( 0 != l_rer->GetBitFieldJustified(0,32) )
    {
        if ( 0 == l_TPrer->GetBitFieldJustified(3,8) )
        { //No MC Recov
            o_hasRecovered = true;
        }
        else if ( 0 != l_TPxstp->GetBitFieldJustified(5,8) )
        {
            // There is Mc Recov and Mc xstop
            if ( OnlyMcRec(l_rer, l_TPrer) &&
                 OnlyMcOrExtCS(l_xstop, l_TPxstp, l_pbXstpFir) )
            {
                // Ignore the Mc Recoverable if only the Mc bits are
                // on in Global Recoverable reg, and, either the only
                // Global CS bits are Mc or there is an External CS.
            }
            else
            {
                o_hasRecovered = true;
            }
        }
        else
        {
            // MC Recov does not match MC Xstop
              o_hasRecovered = true;
        }
    }

    return SUCCESS;
} PRDF_PLUGIN_DEFINE( Proc, CheckForRecovered );

//------------------------------------------------------------------------------
/**
 * @brief Used when the chip is queried, by the fabric domain, for RECOVERED
 * attentions to assign a severity to the attention for sorting.
 * @param[in]   i_chip - P8 chip
 * @param[out]  o_sev - Priority order (lowest to highest):
 *  1 - Core chiplet checkstop
 *  2 - Core chiplet error
 *  3 - PCB chiplet error (TOD logic)
 *  4 - Other error
 *  5 - Memory controller chiplet
 *
 * @return SUCCESS
 *
 */
int32_t CheckForRecoveredSev(ExtensibleChip * i_chip,
                             uint32_t & o_sev)
{
    int32_t o_rc = SUCCESS;
    bool l_runtime = atRuntime();

    SCAN_COMM_REGISTER_CLASS * l_rer = NULL;
    SCAN_COMM_REGISTER_CLASS * l_TPrer = NULL;

    SCAN_COMM_REGISTER_CLASS * l_unitxstp = NULL;
    if ( l_runtime )
    {
        l_unitxstp = i_chip->getRegister("GLOBALUNITXSTPFIR");
        o_rc |= l_unitxstp->Read();
    }

    l_rer = i_chip->getRegister("GLOBAL_RE_FIR");
    o_rc |= l_rer->Read();
    l_TPrer = i_chip->getRegister("TP_CHIPLET_RE_FIR");
    o_rc |= l_TPrer->Read();

    if (o_rc)
    {
        PRDF_ERR( "[CheckForRecoveredSev] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), o_rc);
        return o_rc;
    }

    if (l_TPrer->GetBitFieldJustified(3,8) != 0)
    {
        // errors from MCS chiplets
        o_sev = 5;
    }
    else if(l_rer->IsBitSet(2) || l_rer->IsBitSet(4) || l_rer->IsBitSet(8))
    {
        // errors from PB, X, or A bus chiplets
        o_sev = 4;
    }
    else if(l_rer->IsBitSet(1))
    {
        // error from TP (other than MCS chiplets)
        o_sev = 3;
    }
    else if(l_runtime &&
            (l_rer->GetBitFieldJustified(16,16) &
             l_unitxstp->GetBitFieldJustified(16,16)) == 0 )
    {
        // core recoverable
        o_sev = 2;
    }
    else
    {
        // core checkstop
        o_sev = 1;
    }

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( Proc, CheckForRecoveredSev );

/** @func GetCheckstopInfo
 *  To be called from the fabric domain to gather Checkstop information.  This
 *  information is used in a sorting algorithm.
 *
 *  This is a plugin function: GetCheckstopInfo
 *
 *  @param i_chip - The chip.
 *  @param o_wasInternal - True if this chip has an internal checkstop.
 *  @param o_externalChips - List of external fabrics driving checkstop.
 *  @param o_wofValue - Current WOF value (unused for now).
 */
int32_t GetCheckstopInfo( ExtensibleChip * i_chip,
                          bool & o_wasInternal,
                          TargetHandleList & o_externalChips,
                          uint64_t & o_wofValue )
{
    // Clear parameters.
    o_wasInternal = false;
    o_externalChips.erase(o_externalChips.begin(), o_externalChips.end());
    o_wofValue = 0;

    SCAN_COMM_REGISTER_CLASS * l_globalFir =
      i_chip->getRegister("GLOBAL_CS_FIR");

    SCAN_COMM_REGISTER_CLASS * l_pbXstpFir =
      i_chip->getRegister("PB_CHIPLET_CS_FIR");

    SCAN_COMM_REGISTER_CLASS * l_extXstpFir =
      i_chip->getRegister("PBEXTFIR");

    int32_t o_rc = SUCCESS;
    o_rc |= l_globalFir->Read();
    o_rc |= l_pbXstpFir->Read();
    o_rc |= l_extXstpFir->Read();

    if(o_rc)
    {
        PRDF_ERR( "[GetCheckstopInfo] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), o_rc);
        return o_rc;
    }

    if ((0 != l_globalFir->GetBitFieldJustified(0,32)) &&
        (!l_globalFir->IsBitSet(2) ||
         !l_pbXstpFir->IsBitSet(2)))
        o_wasInternal = true;

    // Get connected chips.
    uint32_t l_connectedXstps = l_extXstpFir->GetBitFieldJustified(0,7);
    uint32_t l_positions[] =
    {
        0, // bit 0 - XBUS 0
        1, // bit 1 - XBUS 1
        2, // bit 2 - XBUS 2
        3, // bit 3 - XBUS 3
        0, // bit 4 - ABUS 0
        1, // bit 5 - ABUS 1
        2  // bit 6 - ABUS 2
    };

    for (int i = 0, j = 0x40; i < 7; i++, j >>= 1)
    {
        if (0 != (j & l_connectedXstps))
        {
            TargetHandle_t l_connectedFab =
              getConnectedPeerProc(i_chip->GetChipHandle(),
                                   i<4 ? TYPE_XBUS : TYPE_ABUS,
                                   l_positions[i]);

            if (NULL != l_connectedFab)
            {
                o_externalChips.push_back(l_connectedFab);
            }
        }
    }

    // Read WOF value.
    SCAN_COMM_REGISTER_CLASS * l_wof = i_chip->getRegister("TODWOF");
    o_rc |= l_wof->Read();

    if(o_rc)
    {
        PRDF_ERR( "[GetCheckstopInfo] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), o_rc);
        return o_rc;
    }

    o_wofValue = l_wof->GetBitFieldJustified(0,64);

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( Proc, GetCheckstopInfo );

int32_t CoreConfiguredAndNotHostboot(ExtensibleChip * i_chip,
                                     bool & o_isCoreConfigured)
{
    o_isCoreConfigured = false;

    // if at not at runtime just return o_isCoreConfigured = false to prevent
    // the default reg capture
    if (atRuntime())
    {
        // make sure this chip has config'd cores
        TargetHandleList l_coreList =
          PlatServices::getConnected(i_chip->GetChipHandle(), TYPE_EX);

        if (l_coreList.size() > 0)
            o_isCoreConfigured = true;
    }

    return SUCCESS;
} PRDF_PLUGIN_DEFINE(Proc, CoreConfiguredAndNotHostboot);

/**
  * @brief Call  HWP and set the right dump type
  * @param  i_chip P8 chip
  * @param  i_sc   The step code data struct
  * @returns Failure or Success
  * @note
  */
int32_t analyzeMpIPL( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;

#ifndef __HOSTBOOT_MODULE

    if (CHECK_STOP == i_sc.service_data->GetAttentionType())
    {
        TargetHandle_t l_procTarget = i_chip->GetChipHandle();
        bool l_mpiplMode = false;
        l_rc = PlatServices::checkMpiplEligibility(l_procTarget,
                                                   l_mpiplMode);

        PRDF_TRAC("[analyzeMpIPL] Proc: 0x%08x, l_mpiplMode: %d, "
                  "l_rc: %d", i_chip->GetId(), l_mpiplMode, l_rc);

        if((SUCCESS == l_rc) && (true == l_mpiplMode))
        {
            i_sc.service_data->SetDump(CONTENT_SW,
                                       l_procTarget);
        }
    }

#endif

    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, analyzeMpIPL );

//------------------------------------------------------------------------------
// Lane Repair plugins
//------------------------------------------------------------------------------

#define PLUGIN_LANE_REPAIR( BUS, TYPE, POS ) \
int32_t spareDeployed_##BUS##POS( ExtensibleChip * i_chip, \
                                  STEP_CODE_DATA_STRUCT & i_sc ) \
{ return LaneRepair::handleLaneRepairEvent(i_chip, TYPE, POS, i_sc, true); } \
PRDF_PLUGIN_DEFINE( Proc, spareDeployed_##BUS##POS ); \
 \
int32_t maxSparesExceeded_##BUS##POS( ExtensibleChip * i_chip, \
                                      STEP_CODE_DATA_STRUCT & i_sc ) \
{ return LaneRepair::handleLaneRepairEvent(i_chip, TYPE, POS, i_sc, false); } \
PRDF_PLUGIN_DEFINE( Proc, maxSparesExceeded_##BUS##POS );

PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 1 )

PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 0 )
PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 1 )
PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 2 )

PLUGIN_LANE_REPAIR( dmiBus, TYPE_MCS, 4 )
PLUGIN_LANE_REPAIR( dmiBus, TYPE_MCS, 5 )
PLUGIN_LANE_REPAIR( dmiBus, TYPE_MCS, 6 )
PLUGIN_LANE_REPAIR( dmiBus, TYPE_MCS, 7 )

#undef PLUGIN_LANE_REPAIR

#define PLUGIN_LANE_REPAIR( BUS, TYPE, POS ) \
int32_t tooManyBusErrors_##BUS##POS( ExtensibleChip * i_chip, \
                                     STEP_CODE_DATA_STRUCT & i_sc ) \
{ return LaneRepair::handleLaneRepairEvent(i_chip, TYPE, POS, i_sc, false); } \
PRDF_PLUGIN_DEFINE( Proc, tooManyBusErrors_##BUS##POS );

PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 1 )

PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 0 )
PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 1 )
PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 2 )

// Plugin not used for DMI buses

#undef PLUGIN_LANE_REPAIR

//------------------------------------------------------------------------------
// Centaur CS plugins
//------------------------------------------------------------------------------

/**
 * @brief Mask attentions from MCIFIR after Centaur Unit checkstop
 * @param  i_chip P8 chip
 * @param  i_sc   The step code data struct
 * @param i_bit   The bit in TP mask to set
 * @returns Failure or Success
 */
int32_t MaskIfCentaurCheckstop( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & i_sc, uint32_t i_bit )
{
    int32_t l_rc = SUCCESS;

    if (i_sc.service_data->GetFlag(ServiceDataCollector::UNIT_CS))
    {
        SCAN_COMM_REGISTER_CLASS * l_tpMask =
          i_chip->getRegister("TP_CHIPLET_FIR_MASK");
        l_rc |= l_tpMask->Read();
        if (!l_rc)
        {
            l_tpMask->SetBit(i_bit);
            l_rc |= l_tpMask->Write();
        }
    }

    if (l_rc)
    {
        PRDF_ERR( "[MaskIfCentaurCheckstop] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), l_rc);
    }
    return l_rc;
}

/**
 * @brief Call MaskIfCentaurCheckstop with the correct bit to mask
 * @param  i_chip P8 chip
 * @param  i_sc   The step code data struct
 * @returns Failure or Success
 */
int32_t MaskMCS00IfCentaurCheckstop( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;
    l_rc = MaskIfCentaurCheckstop(i_chip, i_sc, 5);
    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, MaskMCS00IfCentaurCheckstop );

int32_t MaskMCS01IfCentaurCheckstop( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;
    l_rc = MaskIfCentaurCheckstop(i_chip, i_sc, 6);
    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, MaskMCS01IfCentaurCheckstop );

int32_t MaskMCS10IfCentaurCheckstop( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;
    l_rc = MaskIfCentaurCheckstop(i_chip, i_sc, 7);
    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, MaskMCS10IfCentaurCheckstop );

int32_t MaskMCS11IfCentaurCheckstop( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;
    l_rc = MaskIfCentaurCheckstop(i_chip, i_sc, 8);
    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, MaskMCS11IfCentaurCheckstop );

int32_t MaskMCS20IfCentaurCheckstop( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;
    l_rc = MaskIfCentaurCheckstop(i_chip, i_sc, 9);
    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, MaskMCS20IfCentaurCheckstop );

int32_t MaskMCS21IfCentaurCheckstop( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;
    l_rc = MaskIfCentaurCheckstop(i_chip, i_sc, 10);
    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, MaskMCS21IfCentaurCheckstop );

int32_t MaskMCS30IfCentaurCheckstop( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;
    l_rc = MaskIfCentaurCheckstop(i_chip, i_sc, 11);
    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, MaskMCS30IfCentaurCheckstop );

int32_t MaskMCS31IfCentaurCheckstop( ExtensibleChip * i_chip,
                                     STEP_CODE_DATA_STRUCT & i_sc )
{
    int32_t l_rc = SUCCESS;
    l_rc = MaskIfCentaurCheckstop(i_chip, i_sc, 12);
    return l_rc;
}
PRDF_PLUGIN_DEFINE( Proc, MaskMCS31IfCentaurCheckstop );

//------------------------------------------------------------------------------
// Callout plugins
//------------------------------------------------------------------------------

/**
 * @brief  Callout the peer end point on the given bus (priority MRU_MEDA).
 * @param  i_chip A P8 chip.
 * @param  i_sc   The step code data struct.
 * @param  i_type Bus type (TYPE_XBUS or TYPE_ABUS).
 * @param  i_pos  Bus position.
 * @return SUCCESS
 */
int32_t calloutPeerBus( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & i_sc,
                        TYPE i_type, uint32_t i_pos )
{
    #define PRDF_FUNC "[Proc::calloutPeerBus] "

    // FIXME RTC 72645 Can removed plugins once callout(connected()) is fixed.

    do
    {
        TargetHandle_t srcEndPoint = getConnectedChild( i_chip->GetChipHandle(),
                                                        i_type, i_pos );
        if ( NULL == srcEndPoint )
        {
            PRDF_ERR( PRDF_FUNC"getConnectedChild(0x%08x,%d,%d) failed",
                      i_chip->GetId(), i_type, i_pos );
            break;
        }

        TargetHandle_t destEndPoint = getConnectedPeerTarget( srcEndPoint );
        if ( NULL == destEndPoint )
        {
            PRDF_ERR( PRDF_FUNC"getConnectedPeerTarget(0x%08x) failed",
                      getHuid(srcEndPoint) );
            break;
        }

        i_sc.service_data->SetCallout( destEndPoint, MRU_MEDA );

    } while (0);

    return SUCCESS;
}

#define PLUGIN_CALLOUT_PEER_BUS( BUS, TYPE, POS ) \
int32_t calloutPeerBus_##BUS##POS( ExtensibleChip * i_chip, \
                                   STEP_CODE_DATA_STRUCT & i_sc ) \
{ return calloutPeerBus( i_chip, i_sc, TYPE, POS ); } \
PRDF_PLUGIN_DEFINE( Proc, calloutPeerBus_##BUS##POS );

PLUGIN_CALLOUT_PEER_BUS( xbus, TYPE_XBUS, 1 )

PLUGIN_CALLOUT_PEER_BUS( abus, TYPE_ABUS, 0 )
PLUGIN_CALLOUT_PEER_BUS( abus, TYPE_ABUS, 1 )
PLUGIN_CALLOUT_PEER_BUS( abus, TYPE_ABUS, 2 )

#undef PLUGIN_CALLOUT_PEER_BUS

} // end namespace Proc

} // end namespace PRDF
