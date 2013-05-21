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

    SCAN_COMM_REGISTER_CLASS * l_rer = NULL;
    SCAN_COMM_REGISTER_CLASS * l_TPrer = NULL;

    // FIXME 68302 - This needs a better check for FSP environment
    // we could get a xstp during hostboot at a stage when GLOBALUNITXSTPFIR
    // can't be accessed
#ifndef __HOSTBOOT_MODULE
    SCAN_COMM_REGISTER_CLASS * l_unitxstp = NULL;

    l_unitxstp = i_chip->getRegister("GLOBALUNITXSTPFIR");
    o_rc |= l_unitxstp->Read();
#endif
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
    // FIXME 68302 - This needs a better check for FSP environment
    // we could get a xstp during hostboot at a stage when GLOBALUNITXSTPFIR
    // can't be accessed
#ifndef __HOSTBOOT_MODULE
    else if((l_rer->GetBitFieldJustified(16,16) &
             l_unitxstp->GetBitFieldJustified(16,16)) == 0 )
    {
        // core recoverable
        o_sev = 2;
    }
#endif
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
    using namespace PlatServices;

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
#ifdef __HOSTBOOT_MODULE
    // if in hostboot just return false to prevent the default reg capture
    return SUCCESS;
#endif

    TargetHandleList l_coreList =
      PlatServices::getConnected(i_chip->GetChipHandle(), TYPE_EX);

    if (l_coreList.size() > 0)
        o_isCoreConfigured = true;

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


/**
 * @brief Handle XBUS 1 spare deployed
 * @param i_chip P8 chip
 * @param i_sc   The step code data struct
 * @returns Failure or Success
 */
int32_t xbus1SpareDeployed(  ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_XBUS, 1, i_sc, true);
}
PRDF_PLUGIN_DEFINE( Proc, xbus1SpareDeployed );

/**
 * @brief Handle XBUS 1 spares exceeded
 * @param i_chip P8 chip
 * @param i_sc   The step code data struct
 * @returns Failure or Success
 */
int32_t xbus1SparesExceeded(  ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_XBUS, 1, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, xbus1SparesExceeded );

/**
 * @brief Handle XBUS 1 Too Many Bus Errors
 * @param i_chip P8 chip
 * @param i_sc   The step code data struct
 * @returns Failure or Success
 */
int32_t xbus1TooManyErrors(  ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_XBUS, 1, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, xbus1TooManyErrors );

/**
 * @brief Handle ABUS 0-2 spare deployed
 * @param i_chip P8 chip
 * @param i_sc The step code data struct
 * @returns Failure or Success
 */
int32_t abus0SpareDeployed(  ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 0, i_sc, true);
}
PRDF_PLUGIN_DEFINE( Proc, abus0SpareDeployed );

int32_t abus1SpareDeployed(  ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 1, i_sc, true);
}
PRDF_PLUGIN_DEFINE( Proc, abus1SpareDeployed );

int32_t abus2SpareDeployed(  ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 2, i_sc, true);
}
PRDF_PLUGIN_DEFINE( Proc, abus2SpareDeployed );

/**
 * @brief Handle ABUS 0-2 spares exceeded
 * @param i_chip P8 chip
 * @param i_sc The step code data struct
 * @returns Failure or Success
 */
int32_t abus0SparesExceeded(  ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 0, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, abus0SparesExceeded );

int32_t abus1SparesExceeded(  ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 1, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, abus1SparesExceeded );

int32_t abus2SparesExceeded(  ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 2, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, abus2SparesExceeded );

/**
 * @brief Handle ABUS 0-2 too many bus errors
 * @param i_chip P8 chip
 * @param i_sc The step code data struct
 * @returns Failure or Success
 */
int32_t abus0TooManyErrors(  ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 0, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, abus0TooManyErrors );

int32_t abus1TooManyErrors(  ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 1, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, abus1TooManyErrors );

int32_t abus2TooManyErrors(  ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_ABUS, 2, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, abus2TooManyErrors );

/**
 * @brief Handle DMI bus 0-3 spare deployed
 * @param i_chip P8 chip
 * @param i_sc   The step code data struct
 * @returns Failure or Success
 */
int32_t dmiBus0SpareDeployed(  ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_MCS, 4, i_sc, true);
}
PRDF_PLUGIN_DEFINE( Proc, dmiBus0SpareDeployed );

int32_t dmiBus1SpareDeployed(  ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_MCS, 5, i_sc, true);
}
PRDF_PLUGIN_DEFINE( Proc, dmiBus1SpareDeployed );

int32_t dmiBus2SpareDeployed(  ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_MCS, 6, i_sc, true);
}
PRDF_PLUGIN_DEFINE( Proc, dmiBus2SpareDeployed );

int32_t dmiBus3SpareDeployed(  ExtensibleChip * i_chip,
                               STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_MCS, 7, i_sc, true);
}
PRDF_PLUGIN_DEFINE( Proc, dmiBus3SpareDeployed );

/**
 * @brief Handle DMI Bus 0-3 spares exceeded
 * @param i_chip P8 chip
 * @param i_sc The step code data struct
 * @returns Failure or Success
 */
int32_t dmiBus0SparesExceeded(  ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_MCS, 4, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, dmiBus0SparesExceeded );

int32_t dmiBus1SparesExceeded(  ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_MCS, 5, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, dmiBus1SparesExceeded );

int32_t dmiBus2SparesExceeded(  ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_MCS, 6, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, dmiBus2SparesExceeded );

int32_t dmiBus3SparesExceeded(  ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & i_sc )
{
    return LaneRepair::handleLaneRepairEvent(i_chip, TYPE_MCS, 7, i_sc, false);
}
PRDF_PLUGIN_DEFINE( Proc, dmiBus3SparesExceeded );

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

/**
 * @brief Calls out chip connected on both ends of the a given bus
 * @param i_chip P8 chip
 * @param i_sc   The step code data struct
 * @param i_type type of bus in question
 * @param i_pos  position asociated with bus target
 * @returns Success
 */

int32_t calloutChip( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & i_sc,
                    TYPE i_type, uint32_t i_pos )
{
    //FIXME RTC 72645 Once connection type is supported in getconnected, we
    //shall no longer need these plugins using this function.Callout connected
    //resolution shall be enough for us to callout connected peer proc.

    TargetHandle_t l_srcProcTgt = i_chip->GetChipHandle( );
    TargetHandle_t l_desPeerProc = PlatServices::getConnectedPeerProc(
                                                    l_srcProcTgt,i_type,i_pos );
    PRDpriority l_priority = MRU_MEDA;
    if( NULL == l_desPeerProc )
    {
        PRDF_ERR("proc::calloutChip failed to get peer proc ");
    }
    else
    {
        //FIXME RTC 23127 If Ras Team agrees,we shall just callout A-Bus here
        //and not entire Proc chips on both ends of A-Bus.
        i_sc.service_data->SetCallout( l_desPeerProc,l_priority );
    }
    i_sc.service_data->SetCallout( l_srcProcTgt,l_priority );
    return SUCCESS;
}

/**
 * @brief Called when there is an error on ABus0 connecting two PB chiplet
 * @param i_chip P8 chip
 * @param i_sc   The step code data struct
 * @returns Success
 */

int32_t calloutProcsConnectedToAbus0(  ExtensibleChip * i_chip,
                                        STEP_CODE_DATA_STRUCT & i_sc )
{
    return calloutChip( i_chip,i_sc,TYPE_ABUS,0 );
}
PRDF_PLUGIN_DEFINE( Proc,calloutProcsConnectedToAbus0 );


/**
 * @brief Called when there is an error on ABus1 connecting two PB chiplet
 * @param i_chip P8 chip
 * @param i_sc   The step code data struct
 * @returns Success
 */

int32_t calloutProcsConnectedToAbus1(  ExtensibleChip * i_chip,
                                        STEP_CODE_DATA_STRUCT & i_sc )
{
    return calloutChip( i_chip,i_sc,TYPE_ABUS,1 );
}
PRDF_PLUGIN_DEFINE( Proc,calloutProcsConnectedToAbus1 );

/**
 * @brief Called when there is an error on ABus2 connecting two PB chiplet
 * @param i_chip P8 chip
 * @param i_sc   The step code data struct
 * @returns Success
 */

int32_t calloutProcsConnectedToAbus2(  ExtensibleChip * i_chip,
                                        STEP_CODE_DATA_STRUCT & i_sc )
{
    return calloutChip( i_chip,i_sc,TYPE_ABUS,2 );
}
PRDF_PLUGIN_DEFINE( Proc,calloutProcsConnectedToAbus2 );

} // end namespace Proc
} // end namespace PRDF
