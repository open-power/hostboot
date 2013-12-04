/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8Proc.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#include <prdfPhbUtils.H>
#include <prdfP8DataBundle.H>

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
    i_chip->getDataBundle() = new P8DataBundle( i_chip );
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

PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 0 )
PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 1 )
PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 2 )
PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 3 )

PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 0 )
PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 1 )
PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 2 )

PLUGIN_LANE_REPAIR( dmiBus, TYPE_MCS, 0 )
PLUGIN_LANE_REPAIR( dmiBus, TYPE_MCS, 1 )
PLUGIN_LANE_REPAIR( dmiBus, TYPE_MCS, 2 )
PLUGIN_LANE_REPAIR( dmiBus, TYPE_MCS, 3 )
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

PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 0 )
PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 1 )
PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 2 )
PLUGIN_LANE_REPAIR( xbus, TYPE_XBUS, 3 )

PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 0 )
PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 1 )
PLUGIN_LANE_REPAIR( abus, TYPE_ABUS, 2 )

// Plugin not used for DMI buses

#undef PLUGIN_LANE_REPAIR

/**
 * @brief  checks if MCS block is configured.
 * @param  i_chip P8 chip.
 * @param  i_mcsBlk MCS block ( 0 : ( 0- 3 MCS) ), ( 1 :( 4-7 MCS ))
 * @param  o_isMcsBlkConfigured TRUE if block is configured false otherwise.
 * @return SUCCESS
 */
int32_t mcsBlockConfigured( ExtensibleChip * i_chip,
                            uint8_t i_mcsBlk,
                            bool & o_isMcsBlkConfigured )
{
    o_isMcsBlkConfigured = false;

    // Starting MCS position for MCS block
    uint8_t firstMcsPos[ 2 ] = { 0, 4 };

    // Get functional MCS list
    TargetHandleList l_mcsList =
        PlatServices::getConnected(i_chip->GetChipHandle(), TYPE_MCS);

    for ( TargetHandleList::iterator i = l_mcsList.begin();
          i != l_mcsList.end(); ++i )
    {
        uint8_t pos = getTargetPosition(*i);
        if( ( pos >= firstMcsPos[ i_mcsBlk ] ) &&
            ( pos <= ( firstMcsPos[ i_mcsBlk ] + 3) ) )
        {
            o_isMcsBlkConfigured = true;
            break;
        }
    }

    return SUCCESS;
}

#define PLUGIN_MCS_BLOCK_CONFIGURED( POS ) \
int32_t mcsBlockConfigured_##POS( ExtensibleChip * i_chip, \
                             bool & o_isMcsBlkConfigured ) \
{ return mcsBlockConfigured( i_chip, POS, o_isMcsBlkConfigured ); } \
PRDF_PLUGIN_DEFINE( Proc, mcsBlockConfigured_##POS );

PLUGIN_MCS_BLOCK_CONFIGURED( 0 )
PLUGIN_MCS_BLOCK_CONFIGURED( 1 )

#undef PLUGIN_MCS_BLOCK_CONFIGURED

//------------------------------------------------------------------------------
// Callout plugins
//------------------------------------------------------------------------------

/**
 * @brief Call to check for configured PHB (before capturing FFDC)
 * @param  i_chip             P8 chip
 * @param  i_phbPos           PHB position
 * @param  o_isPhbConfigured  set to true if the PHB configured
 * @returns Success
 */
int32_t phbConfigured(ExtensibleChip * i_chip,
                      uint32_t i_phbPos,
                      bool & o_isPhbConfigured)
{
    #define PRDF_FUNC "[Proc::phbConfigured] "

    static const uint32_t MAX_PCI_NUM = 3;
    static const char * pciEtuResetReg[MAX_PCI_NUM] =
                                         { "PCI_ETU_RESET_0",
                                           "PCI_ETU_RESET_1",
                                           "PCI_ETU_RESET_2" };
    int32_t o_rc = SUCCESS;
    o_isPhbConfigured = false;

    do
    {
        if( i_phbPos >= MAX_PCI_NUM )
        {
            PRDF_ERR( PRDF_FUNC"invalid PCI number: %d", i_phbPos );
            break;
        }

        SCAN_COMM_REGISTER_CLASS * etuResetReg =
            i_chip->getRegister( pciEtuResetReg[i_phbPos] );

        if(NULL == etuResetReg)
        {
            PRDF_ERR( PRDF_FUNC"getRegister() Failed for register:%s",
                         pciEtuResetReg[i_phbPos] );
            break;
        }

        o_rc = etuResetReg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"%s Read() failed. Target=0x%08x",
                      pciEtuResetReg[i_phbPos], i_chip->GetId() );
            break;
        }

        // If bit 0 is cleared then the PHB is configured
        if ( ! etuResetReg->IsBitSet(0) )
        {
            o_isPhbConfigured = true;
        }

    } while(0);

    return SUCCESS;

    #undef PRDF_FUNC
}

#define PLUGIN_PHB_CONFIGURED( POS ) \
int32_t phbConfigured_##POS( ExtensibleChip * i_chip, \
                             bool & o_isPhbConfigured ) \
{ return phbConfigured( i_chip, POS, o_isPhbConfigured ); } \
PRDF_PLUGIN_DEFINE( Proc, phbConfigured_##POS );

PLUGIN_PHB_CONFIGURED( 0 )
PLUGIN_PHB_CONFIGURED( 1 )
PLUGIN_PHB_CONFIGURED( 2 )

#undef PLUGIN_PHB_CONFIGURED

//------------------------------------------------------------------------------

/**
 * @brief   calls out master Ex of the node
 * @param   i_chip   P8 chip
 * @param   i_sc     service data collector
 * @returns Success
 */
int32_t calloutMasterCore( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[calloutMasterCore] "

    TargetHandle_t l_procTgt = i_chip->GetChipHandle();

    TargetHandle_t l_masterCore = PlatServices::getMasterCore( l_procTgt );
    if( NULL == l_masterCore )
    {
        PRDF_ERR( PRDF_FUNC"Failed to get master core: PROC = 0x%08x",
                  i_chip->GetId() );
    }
    else
        io_sc.service_data->SetCallout( l_masterCore );

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Proc, calloutMasterCore );

//------------------------------------------------------------------------------

/**
 * @brief   When not in MNFG mode, clear the service call flag so that
 *          thresholding will still be done, but no visible error log committed.
 * @param   i_chip P8 chip
 * @param   i_sc   Step code data struct
 * @returns SUCCESS always
 */
int32_t ClearServiceCallFlag( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & i_sc )
{
    if ( i_sc.service_data->IsAtThreshold() && !mfgMode() )
    {
        i_sc.service_data->ClearFlag(ServiceDataCollector::SERVICE_CALL);
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, ClearServiceCallFlag );

//------------------------------------------------------------------------------
//                   PHB Plugins for IOPCIFIR_x
//------------------------------------------------------------------------------

/**
 * @brief  Calls out PHB targets associated with given processor.
 * @param  i_procChip    Chip reporting attention.
 * @param  io_sc         The step code data struct.
 * @param  i_iopciIdx    IOPCIFIR instance number (0,1)
 * @param  i_calloutPhbA True if error is from clock A, false otherwise.
 * @param  i_calloutPhbB True if error is from clock B, false otherwise.
 * @return Always SUCCESS.
 */
int32_t calloutPhb( ExtensibleChip * i_procChip, STEP_CODE_DATA_STRUCT & io_sc,
                    uint32_t i_iopciIdx, bool i_calloutPhbA, bool i_calloutPhbB)
{
    #define PRDF_FUNC "[Proc::calloutPhb] "

    uint32_t l_rc = SUCCESS;

    TargetHandle_t procTrgt = i_procChip->GetChipHandle();
    TargetHandle_t phbATrgt = NULL;
    TargetHandle_t phbBTrgt = NULL;

    // Callout clock A
    if ( i_calloutPhbA )
    {
        if ( SUCCESS != getConfiguredPHB(procTrgt, i_iopciIdx, 0, phbATrgt) )
        {
            PRDF_ERR( PRDF_FUNC"getConfiguredPHB(0) failed: i_procChip=0x%08x "
                      "i_iopciIdx=%d", i_procChip->GetId(), i_iopciIdx );
            l_rc = FAIL;
        }
        else if ( NULL != phbATrgt )
        {
            io_sc.service_data->SetCallout( phbATrgt );
        }
    }

    // Callout clock B
    if ( i_calloutPhbB )
    {
        if ( SUCCESS != getConfiguredPHB(procTrgt, i_iopciIdx, 1, phbBTrgt) )
        {
            PRDF_ERR( PRDF_FUNC"getConfiguredPHB(1) failed: i_procChip=0x%08x "
                      "i_iopciIdx=%d", i_procChip->GetId(), i_iopciIdx );
            l_rc = FAIL;
        }
        else if ( (NULL != phbBTrgt) && (phbATrgt != phbBTrgt) )
        {
            io_sc.service_data->SetCallout( phbBTrgt );
        }
    }

    // If no PHBs called out, callout 2nd level support.
    if ( (SUCCESS != l_rc) || (0 == io_sc.service_data->GetMruList().size()) )
        io_sc.service_data->SetCallout( NextLevelSupport_ENUM );

    return SUCCESS; // Intentionally returns SUCCESS so rule code does not get
                    // confused by undefined error code.

    #undef PRDF_FUNC
}

#define PLUGIN_CALLOUT_PHB( CLK,IOPCI,ERRA,ERRB ) \
int32_t calloutPhbClk##CLK##_##IOPCI( ExtensibleChip * i_chip, \
                                      STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    return calloutPhb( i_chip, i_sc, IOPCI, ERRA, ERRB );  \
}\
PRDF_PLUGIN_DEFINE( Proc, calloutPhbClk##CLK##_##IOPCI );

PLUGIN_CALLOUT_PHB( A, 0, true, false )
PLUGIN_CALLOUT_PHB( B, 0, false, true )
PLUGIN_CALLOUT_PHB( A, 1, true, false )
PLUGIN_CALLOUT_PHB( B, 1, false, true )

#undef PLUGIN_CALLOUT_PHB

#define PLUGIN_CALLOUT_PHB( IOPCI ) \
int32_t calloutPhbBothClks_##IOPCI( ExtensibleChip * i_chip, \
                                    STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    return calloutPhb( i_chip, i_sc, IOPCI, true, true );  \
}\
PRDF_PLUGIN_DEFINE( Proc, calloutPhbBothClks_##IOPCI );

PLUGIN_CALLOUT_PHB( 0 )
PLUGIN_CALLOUT_PHB( 1 )

#undef PLUGIN_CALLOUT_PHB

/**
  * @brief  checks if proc is Venice chip.
  * @param  i_chip P8 chip.
  * @param  isVenice TRUE if chip is venice false otherwise.
  * @return SUCCESS
  */
int32_t isVeniceProc( ExtensibleChip * i_chip, bool & o_isVenice )
{
    o_isVenice = false;
    if( MODEL_VENICE == getProcModel( i_chip->GetChipHandle() ) )
        o_isVenice = true;

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Proc, isVeniceProc );

} // end namespace Proc

} // end namespace PRDF
