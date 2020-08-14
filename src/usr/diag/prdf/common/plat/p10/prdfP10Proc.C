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

/**
 * @brief Determines if there are any active checkstop attentions on this
 *        processor that did not originate from a connected processor.
 * @param i_chip         A processor chip.
 * @param o_internalAttn True, if there is an internal checkstop attentions.
 *                       False, otherwise.
 * @return SUCCESS always.
 */
int32_t GetCheckstopInfo(ExtensibleChip * i_chip, bool & o_internalAttn)
{
    #define PRDF_FUNC "[Proc::GetCheckstopInfo] "

    o_internalAttn = false;

    SCAN_COMM_REGISTER_CLASS * fir = nullptr;
    SCAN_COMM_REGISTER_CLASS * msk = nullptr;

    do
    {
        // First, check if there is an active checkstop attention at the global
        // level.
        fir = i_chip->getRegister("GLOBAL_CS_FIR");
        if (SUCCESS != fir->Read()) break;

        // If there is an active attention from any chiplet other than the N1
        // chiplet (i.e. any of GLOBAL_CS_FIR[0:2,4:39] are set), the attention
        // is internal.
        if ((0 != fir->GetBitFieldJustified(0, 3)) ||
            (0 != fir->GetBitFieldJustified(4,36)))
        {
            o_internalAttn = true;
            break;
        }

        // If there is NOT an attention from the N1 chiplet (i.e. the only bit
        // not checked above, GLOBAL_CS_FIR[3]), then there is NOT an active
        // checkstop attention on this chip.
        if (!fir->IsBitSet(3)) break;

        // Now, check if there is an active checkstop attention at the chiplet
        // level.
        fir = i_chip->getRegister("N1_CHIPLET_CS_FIR");
        msk = i_chip->getRegister("N1_CHIPLET_CS_FIR_MASK");
        if (SUCCESS != fir->Read() || SUCCESS != msk->Read()) break;

        // If bits there is an active attention from any FIR other than the
        // PB_EXT_FIR (i.e. any of N1_CHIPLET_CS_FIR[4:32,34:39] are set), the
        // attention is internal.
        if ((0 != ( fir->GetBitFieldJustified( 4,29) &
                   ~msk->GetBitFieldJustified( 4,29))) ||
            (0 != ( fir->GetBitFieldJustified(34, 6) &
                   ~msk->GetBitFieldJustified(34, 6))))
        {
            o_internalAttn = true;
            break;
        }

        // At this point, the attention only originated from the PB_EXT_FIR
        // (i.e. N1_CHIPLET_CS_FIR[33]) and, therefore, only originated from a
        // connected processor.

        // This is just a sanity check just in case there is a bug with the bit
        // ranges used above.
        PRDF_ASSERT(fir->IsBitSet(33) && !msk->IsBitSet(33));

    } while (0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS(p10_proc, Proc, GetCheckstopInfo);

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
