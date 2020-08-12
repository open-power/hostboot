/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Proc.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

/** @file  prdfP10Proc.C
 *  @brief Contains all the plugin code for the PRD P10 Proc
 */

// Framework includes
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <xspprdService.h>

#ifdef __HOSTBOOT_MODULE
#include <prdfPlatServices_ipl.H>
#include <prdfErrlUtil.H>
#include <prdfLaneRepair.H>
#include <sbeio/sbeioif.H>
#endif

#ifdef __HOSTBOOT_RUNTIME
#include <prdfP10PmRecovery.H>
#endif

// Platform includes

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
 * @brief  Used when the chip has a CHECK_STOP or UNIT_CS attention to check for
 *         the presence of recoverable attentions.
 * @param  i_chip         A P9 chip.
 * @param  o_hasRecovered True if the chip has a recoverable attention.
 * @return SUCCESS
 */
int32_t CheckForRecovered( ExtensibleChip * i_chip,
                           bool & o_hasRecovered )
{
    o_hasRecovered = false;

    int32_t l_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * l_grer = i_chip->getRegister("GLOBAL_RE_FIR");
    l_rc = l_grer->Read();

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR("[CheckForRecovered] GLOBAL_RE_FIR read failed"
                 "for 0x%08x", i_chip->GetId());
    }
    else if ( 0 != l_grer->GetBitFieldJustified(1,55) )
    {
        o_hasRecovered = true;
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,     Proc, CheckForRecovered );

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
int32_t CheckForRecoveredSev(ExtensibleChip * i_chip, uint32_t & o_sev)
{
    int32_t o_rc = SUCCESS;
    bool l_runtime = atRuntime();

    SCAN_COMM_REGISTER_CLASS * l_rer = NULL;

    SCAN_COMM_REGISTER_CLASS * l_unitxstp = NULL;
    if ( l_runtime )
    {
        l_unitxstp = i_chip->getRegister("GLOBAL_UCS_FIR");
        o_rc |= l_unitxstp->Read();
    }

    l_rer = i_chip->getRegister("GLOBAL_RE_FIR");
    o_rc |= l_rer->Read();

    if (o_rc)
    {
        PRDF_ERR( "[CheckForRecoveredSev] SCOM fail on 0x%08x rc=%x",
                  i_chip->GetId(), o_rc);
        return o_rc;
    }

    if (l_rer->GetBitFieldJustified(7,2))
    {
        // errors from MC chiplets
        o_sev = 5;
    }
    else if(l_rer->GetBitFieldJustified(2, 4) ||
            l_rer->GetBitFieldJustified(9, 4) ||
            l_rer->GetBitFieldJustified(13,3) ||
            l_rer->IsBitSet(6))
    {
        // errors from PB, Xbus, OB, or PCI chiplets
        o_sev = 4;
    }
    else if(l_rer->IsBitSet(1))
    {
        // error from TP
        o_sev = 3;
    }
    else if (l_rer->GetBitFieldJustified(16,6))
    {
        // error from EQ
        o_sev = 2;
    }
    else if(l_runtime &&
            (l_rer->GetBitFieldJustified(32,24) &
             l_unitxstp->GetBitFieldJustified(32,24)) == 0 )
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

}
PRDF_PLUGIN_DEFINE_NS( p10_proc,     Proc, CheckForRecoveredSev );

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
    o_externalChips.clear();
    o_wofValue = 0;

    SCAN_COMM_REGISTER_CLASS * l_globalFir =
      i_chip->getRegister("GLOBAL_CS_FIR");

    SCAN_COMM_REGISTER_CLASS * l_pbXstpFir =
      i_chip->getRegister("N3_CHIPLET_CS_FIR");

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

    uint8_t l_connectedXstps = l_extXstpFir->GetBitFieldJustified(0,7);

    bool pbXstpFromOtherChip = l_pbXstpFir->IsBitSet(2);

    if ((0 != l_globalFir->GetBitFieldJustified(0,56)) &&
        (!l_globalFir->IsBitSet(5) || !pbXstpFromOtherChip))
        o_wasInternal = true;

    // Get connected chips.
    uint32_t l_positions[] =
    {
        0, // bit 0 - XBUS 0
        1, // bit 1 - XBUS 1
        2, // bit 2 - XBUS 2
        0, // bit 3 - OBUS 0
        1, // bit 4 - OBUS 1
        2, // bit 5 - OBUS 2
        3  // bit 6 - OBUS 3
    };

    for (uint8_t i = 0, j = 0x40; i < 7; i++, j >>= 1)
    {
        if (0 != (j & l_connectedXstps))
        {
            TargetHandle_t l_connectedFab =
              getConnectedPeerProc(i_chip->GetChipHandle(),
                                   i<3 ? TYPE_XBUS : TYPE_OBUS,
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

}
PRDF_PLUGIN_DEFINE_NS( axone_proc,   Proc, GetCheckstopInfo );
PRDF_PLUGIN_DEFINE_NS( p10_proc,     Proc, GetCheckstopInfo );

//------------------------------------------------------------------------------

/** Call HW server rtn for Deadman Timer */
int32_t handleDeadmanTimer( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    TARGETING::TargetHandle_t  l_target = i_chip->getTrgt();


    // This routine adds FFDC information to the elog
    // and will also do the callouts as needed.
    deadmanTimerFFDC( l_target, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,     Proc, handleDeadmanTimer );

//------------------------------------------------------------------------------

/** Call hostboot to indicate SBE bad, extract FFDC and handle recovery */
int32_t handleSbeVital( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    // Hostboot code is suppose to handle all Vital attentions
    // and initiate recovery with FSP,etc... if needed
#ifdef __HOSTBOOT_MODULE
    TARGETING::TargetHandle_t  l_target = i_chip->getTrgt();
    SCAN_COMM_REGISTER_CLASS * l_tpmask_or;

   PRDF_ERR("Invoking HB SBE vital routine");
   errlHndl_t  l_elog = SBEIO::handleVitalAttn( l_target );

    // commit any failures
    if (nullptr != l_elog)
    {
        // Need to MASK bit 26 of TPLFIR to avoid getting this again
        // (will use the 'OR' reg for doing the masking)
        l_tpmask_or = i_chip->getRegister("TP_LFIR_MASK_OR");
        l_tpmask_or->clearAllBits();
        l_tpmask_or->SetBit( 26  );

        int32_t l_rc = l_tpmask_or->Write();
        if (l_rc != SUCCESS)
        {   // we are probably stuck in an infinite loop now
            PRDF_ERR("Failed(%d) masking SBE bit for chip: 0x%08x",
                      l_rc,  i_chip->getHuid() );
        }

        PRDF_ERR("handleVitalAttn failure");
        PRDF_COMMIT_ERRL( l_elog, ERRL_ACTION_REPORT );
    }
#endif
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,     Proc, handleSbeVital );

//------------------------------------------------------------------------------

/**
 * @brief  Used when the chip has a CHECK_STOP to see if there
 *         is also a UNIT_CS present
 * @param  i_chip         A P9 chip.
 * @param  o_hasUcs True if the chip has a UNIT CS attention.
 * @return SUCCESS
 */
int32_t CheckForUnitCs( ExtensibleChip * i_chip,
                        bool & o_hasUcs )
{
    o_hasUcs = false;

    int32_t l_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * l_gUcsR = i_chip->getRegister("GLOBAL_UCS_FIR");
    l_rc = l_gUcsR->Read();

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR("[CheckForUnitCs] GLOBAL_UCS_FIR read failed"
                 "for 0x%08x", i_chip->GetId());
    }
    else if ( 0 != l_gUcsR->GetBitFieldJustified(1,55) )
    {
        o_hasUcs = true;
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,     Proc, CheckForUnitCs );

//------------------------------------------------------------------------------

/**
 * @brief Recovery actions for a power management STOP failure. Collects FFDC,
 *        runtime deconfigures lost cores, and makes appropriate callouts as
 *        determined by the p9_pm_callout procedure.
 * @param  i_chip         A P9 chip.
 * @param  io_sc          step code data struct
 * @return SUCCESS
 */
int32_t PmRecovery( ExtensibleChip * i_chip,
                    STEP_CODE_DATA_STRUCT & io_sc )
{

#ifdef __HOSTBOOT_RUNTIME

    if ( pmRecovery(i_chip, io_sc) != SUCCESS )
    {
        PRDF_ERR("[PmRecovery] failed for 0x%08x", i_chip->GetId());
    }

#else

    PRDF_ERR( "[PmRecovery] not expected outside of HB runtime" );
    io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_HIGH);
    io_sc.service_data->SetCallout(i_chip->getTrgt());

#endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,     Proc, PmRecovery );

//------------------------------------------------------------------------------

/**
 * @brief  Special action for INT_CQ_FIR_PC_RECOV_ERROR_0_2
 * @param  i_chip         A P9 chip.
 * @param  io_sc          step code data struct
 * @return PRD_SCAN_COMM_REGISTER_ZERO if we take normal action, SUCCESS for
 *         conditional action, FAIL if an internal function fails
 */
int32_t handleIntCqFirPcRecovError( ExtensibleChip * i_chip,
                                    STEP_CODE_DATA_STRUCT & io_sc)
{
    int32_t l_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * l_intPcVpcErr1Wof =
            i_chip->getRegister("INT_PC_VPC_ERR1_WOF");
        SCAN_COMM_REGISTER_CLASS * l_intPcVpcErr1WofDetail =
            i_chip->getRegister("INT_PC_VPC_ERR1_WOF_DETAIL");

        l_rc |= l_intPcVpcErr1Wof->Read();
        l_rc |= l_intPcVpcErr1WofDetail->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( "[handleIntCqFirPcRecovError] Error reading "
                      "INT_PC_VPC_ERR1_WOF or INT_PC_VPC_ERR1_WOF_DETAIL" );
            break;
        }

        // If INT_PC_VPC_ERR1_WOF[30] or INT_PC_VPC_ERR1_WOF_DETAIL[3] is not
        // set, set rc to FAIL and let rule code take action as normal
        if ( !l_intPcVpcErr1Wof->IsBitSet(30) ||
             !l_intPcVpcErr1WofDetail->IsBitSet(3) )
        {
            l_rc = PRD_SCAN_COMM_REGISTER_ZERO;
            break;
        }
        // Else if INT_PC_VPC_ERR1_WOF[30] and INT_PC_VPC_ERR1_WOF_DETAIL[3] are
        // both set.
        // Don't increment thresholding

        // Don't commit the error log
        io_sc.service_data->setDontCommitErrl();

        // Clear INT_PC_VPC_ERR1_WOF[30]
        l_intPcVpcErr1Wof->ClearBit(30);
        l_rc = l_intPcVpcErr1Wof->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( "[handleIntCqFirPcRecovError] Error clearing "
                      "INT_PC_VPC_ERR1_WOF[30]" );
            break;
        }

        // Clear all of INT_PC_VPC_ERR1_WOF_DETAIL because there are other bits
        // in that register that have detauls about why bit 3 is set.
        l_intPcVpcErr1WofDetail->clearAllBits();
        l_rc = l_intPcVpcErr1WofDetail->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( "[handleIntCqFirPcRecovError] Error clearing "
                      "INT_PC_VPC_ERR1_WOF_DETAIL" );
            break;
        }

        // Clear INTCQFIR[52:54] (Should be done automatically by the rule code)

    }while(0);

    return l_rc;
}
PRDF_PLUGIN_DEFINE_NS( p10_proc,     Proc, handleIntCqFirPcRecovError );

//------------------------------------------------------------------------------

} // end namespace Proc

} // end namespace PRDF
