/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Core.C $             */
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
// Framework includes
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfErrlUtil.H>
#ifdef __HOSTBOOT_RUNTIME
  #include <hwas/common/hwas.H>
  #include <hwas/common/deconfigGard.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Ec
{
#ifdef __HOSTBOOT_RUNTIME
void maskIfCoreCs( ExtensibleChip * i_chip )
{
    int32_t l_rc = SUCCESS;

    // Get core global mask register.
    SCAN_COMM_REGISTER_CLASS * coreFirMask =
        i_chip->getRegister("EC_CHIPLET_FIR_MASK");

    SCAN_COMM_REGISTER_CLASS * coreUcsMask =
        i_chip->getRegister("EC_CHIPLET_UCS_FIR_MASK");

    // Read values.
    l_rc  = coreFirMask->Read();
    l_rc |= coreUcsMask->Read();

    if (SUCCESS == l_rc)
    {
        // Mask bit 4 for recoverable and checkstop
        coreFirMask->SetBit(4);
        // Mask bit 0 for local checkstop summary
        coreFirMask->SetBit(0);
        // Mask bit 26 (mask for debug trigger)
        coreFirMask->SetBit(26);

        // Mask bit 1 for Unit checkstop
        coreUcsMask->SetBit(0); // setting bit 0 masks the FIR bit 1.

        coreFirMask->Write();
        coreUcsMask->Write();
    }
}

void rtDcnfgCore( ExtensibleChip * i_chip )
{
    /* TODO RTC 256733
    TargetHandle_t coreTgt = i_chip->getTrgt();

    // Get the Global Errorlog
    errlHndl_t globalErrl =
        ServiceGeneratorClass::ThisServiceGenerator().getErrl();

    // Call Deconfig
    errlHndl_t errl = nullptr;
    errl = HWAS::theDeconfigGard().deconfigureTargetAtRuntime( coreTgt,
                       HWAS::DeconfigGard::FULLY_AT_RUNTIME, globalErrl );

    if (errl)
    {
        PRDF_ERR( "[EC::rtDcnfgCore] Deconfig failed on core %x",
                  getHuid(coreTgt));
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
    }
    */
}
#endif

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip    EC chip.
 * @param  io_sc     The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip,
                      STEP_CODE_DATA_STRUCT & io_sc )
{
#ifdef __HOSTBOOT_RUNTIME
    /* TODO RTC 256733
    if ( io_sc.service_data->isProcCoreCS() )
    {
        ExtensibleChip * n_chip = getNeighborCore(i_chip);
        maskIfCoreCs(i_chip);
        rtDcnfgCore(i_chip);
        if (n_chip != nullptr)
        {
            maskIfCoreCs(n_chip);
        }
    }
    else
    {
        int32_t l_rc = restartTraceArray(i_chip->getTrgt());
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[EC PostAnalysis HUID: 0x%08x RestartTraceArray failed",
                      i_chip->GetId());
        }

    }
    */
#endif
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( axone_ec,   Ec, PostAnalysis );

/**
 * @brief Checks if this core has checkstopped as a side effect of its
 * fused-core neighbor checkstopping
 *
 * @param  i_chip    EC chip.
 * @return TRUE      If UCS root cause is on neighbor
 *         FALSE     If UCS root cause is not on neighbor
 */
bool neighborHasRealCoreCS( ExtensibleChip * i_chip )
{
    int32_t l_rc = SUCCESS;
    bool neighborHasRealCs = false;

    // Check if this core is reporting a neighbor Core Checkstop with no
    // other core checkstop bits of its own
    SCAN_COMM_REGISTER_CLASS *fir  = i_chip->getRegister("COREFIR");
    SCAN_COMM_REGISTER_CLASS *msk  = i_chip->getRegister("COREFIR_MASK");
    SCAN_COMM_REGISTER_CLASS *act0 = i_chip->getRegister("COREFIR_ACT0");
    SCAN_COMM_REGISTER_CLASS *act1 = i_chip->getRegister("COREFIR_ACT1");

    l_rc |=  fir->Read();
    l_rc |=  msk->Read();
    l_rc |= act0->Read();
    l_rc |= act1->Read();

    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[EC neighborHasRealCoreCS] scom fail on HUID 0x%08x",
                  i_chip->GetId());
        return false;
    }

    uint64_t firBits  =  fir->GetBitFieldJustified(0, 64);
    uint64_t mskBits  =  msk->GetBitFieldJustified(0, 64);
    uint64_t act0Bits = act0->GetBitFieldJustified(0, 64);
    uint64_t act1Bits = act1->GetBitFieldJustified(0, 64);

    if ( ( firBits & ~mskBits & act0Bits & act1Bits ) == 0x0000000000000040ULL )
    {
        // If the only Unit checkstop bit set on this core is bit 57, then
        // we will skip this core and check the neighbor for the true cause

        // Get neighbor core
        ExtensibleChip * n_chip = getNeighborCore( i_chip );
        if (n_chip == nullptr)
            return false;

        // Get neighbor regs
        SCAN_COMM_REGISTER_CLASS * wof;
        uint64_t wofBits;

        fir  = n_chip->getRegister("COREFIR");
        wof  = n_chip->getRegister("COREFIR_WOF");
        msk  = n_chip->getRegister("COREFIR_MASK");
        act1 = n_chip->getRegister("COREFIR_ACT1");

        l_rc |=  fir->Read();
        l_rc |=  wof->Read();
        l_rc |=  msk->Read();
        l_rc |= act1->Read();

        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[EC neighborHasRealCoreCS] scom fail on HUID 0x%08x",
                      n_chip->GetId());
            return false;
        }

        firBits  =  fir->GetBitFieldJustified(0, 64);
        wofBits  =  wof->GetBitFieldJustified(0, 64);
        mskBits  =  msk->GetBitFieldJustified(0, 64);
        act1Bits = act1->GetBitFieldJustified(0, 64);

        // Ensure that neighbor has something to analyze (RE or UCS)
        if ( (firBits | wofBits) & ~mskBits & act1Bits )
        {
            PRDF_TRAC("[EC neighborHasRealCoreCS] need to analyze neighbor "
                      "0x%08x for UCS root cause.", n_chip->GetId());
            neighborHasRealCs = true;
        }
    }

    return neighborHasRealCs;
}


/*
 Core checkstop is only supported on PHYP systems. PHYP only supports
 fused-cores. When a normal core checkstops, its fused-core neighbor will
 checkstop along with it. Both cores will end up reporting core checkstop
 attentions. This plugin checks if this core's fused-core neighbor has the
 original core checkstop that we should be analyzing.
*/
int32_t PreAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                     bool & o_analyzed )
{
    o_analyzed = false;

    if (neighborHasRealCoreCS( i_chip ))
    {
        // Get neighbor core
        ExtensibleChip * n_chip = getNeighborCore( i_chip );
        if (n_chip != nullptr)
        {
            if ( SUCCESS == n_chip->Analyze(io_sc,
                                io_sc.service_data->getSecondaryAttnType()) )
            {
                o_analyzed = true;
            }
        }
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( axone_ec,   Ec, PreAnalysis );

void checkCoreRePresent( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t l_rc = SUCCESS;
    SCAN_COMM_REGISTER_CLASS *coreWOF =
             i_chip->getRegister("COREFIR_WOF");
    SCAN_COMM_REGISTER_CLASS * coreMask =
             i_chip->getRegister("COREFIR_MASK");
    SCAN_COMM_REGISTER_CLASS * coreAct0 =
             i_chip->getRegister("COREFIR_ACT0");
    SCAN_COMM_REGISTER_CLASS * coreAct1 =
             i_chip->getRegister("COREFIR_ACT1");

    l_rc  = coreWOF->Read();
    l_rc |= coreMask->Read();
    l_rc |= coreAct0->Read();
    l_rc |= coreAct1->Read();
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[EC::checkCoreRePresent] HUID: 0x%08x failed to read"
                  "CORE FIR", i_chip->GetId());
        return;
    }

    uint64_t coreWOFbits  =  coreWOF->GetBitFieldJustified(0, 64);
    uint64_t coreMaskbits = coreMask->GetBitFieldJustified(0, 64);
    uint64_t coreAct0bits = coreAct0->GetBitFieldJustified(0, 64);
    uint64_t coreAct1bits = coreAct1->GetBitFieldJustified(0, 64);

    // If do not have a valid recoverable bit in COREFIR_WOF, we need to
    // switch analysis to look at core checkstop bits
    if ( !( coreWOFbits  & ~coreMaskbits & ~coreAct0bits & coreAct1bits) )
    {
        io_sc.service_data->setSecondaryAttnType(UNIT_CS);
    }
}


/**
 * @brief Determine if there is a core unit checkstop and perform appropriate
 * action.
 *
 * 1) Set error to predictive / at threshold.
 * 2) Wait for PHYP to evacuate core.
 * 3) Terminate if PHYP doesn't evacuate.
 * 4) If we have UCS without RE, switch attn type to analyze UCS
 * @param i_chip Ex chip.
 * @param io_sc Step Code data struct
 * @return PRD return code
 */
int32_t CheckCoreCheckstop( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Ec::CheckCoreCheckstop] "
    int32_t l_rc = SUCCESS;
    static const uint32_t CORECS_SECONDS_TO_SLEEP = 10;

    do
    {
        // Skip if we're already at core checkstop in SDC.
        if (io_sc.service_data->isProcCoreCS())
            break;

        // Read core checkstop bit in chiplet RER.
        SCAN_COMM_REGISTER_CLASS * coreRER
                                = i_chip->getRegister("EC_CHIPLET_RE_FIR");
        l_rc = coreRER->ForceRead();
        if (SUCCESS != l_rc)
            break;

        // Check core checkstop bit.
        if (!coreRER->IsBitSet(0))
            break;

        // We must be at core checkstop.
        io_sc.service_data->setProcCoreCS();
        io_sc.service_data->SetThresholdMaskId(0);

        // Check if we need to switch attn type to analyze Unit checkstop
        checkCoreRePresent(i_chip, io_sc);

        if( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() )
        {
            // if both Unit CS and Platform CS occur together, PHYP will not
            // respond to the core evacuation hand-shaking. Don't wait for them
            // and don't collect SH dump. This specifically targets a case
            //  where COREFIR bit 54 and 55 assert together.

            break;
        }

        SCAN_COMM_REGISTER_CLASS *coreHMEER
            = i_chip->getRegister("HOMER_ENABLE");
        l_rc = coreHMEER->Read();
        if (SUCCESS != l_rc)
            break;

        // Check if PHYP has enabled core checkstop (HMEER[0]).
        if (!coreHMEER->IsBitSet(0))
        {
            // Core checkstop not enabled, terminate.
            io_sc.service_data->setFlag( ServiceDataCollector::TERMINATE );

            // PHYP was unresponsive, be sure to get SW content.
            io_sc.service_data->SetDump(CONTENT_SW, i_chip->getTrgt());
            break;
        }

        // Wait for PHYP evacuation by checking SPATTN register.
        SCAN_COMM_REGISTER_CLASS * coreSPAttn
            = i_chip->getRegister("SPEC_ATTN_REASON");

        bool spAttnCleared = false;
        uint32_t secondsToSleep = CORECS_SECONDS_TO_SLEEP;

        do
        {
            // Don't sleep on first time through.
            if (secondsToSleep != CORECS_SECONDS_TO_SLEEP)
            {
                PlatServices::milliSleep(1,0); // 1 second
            }
            secondsToSleep--;

            l_rc = coreSPAttn->ForceRead();
            if (SUCCESS == l_rc)
            {
                if (!coreSPAttn->IsBitSet(2))
                {
                    spAttnCleared = 1;
                }
            }
        } while ((secondsToSleep != 0) && (!spAttnCleared));

        if (SUCCESS == l_rc && !spAttnCleared)
        {
            // If we waited and never cleared, terminate machine.
            io_sc.service_data->setFlag( ServiceDataCollector::TERMINATE );

            // PHYP was unresponsive, so get SW content.
            io_sc.service_data->SetDump(CONTENT_SW, i_chip->getTrgt());
        }
    } while(0);
    return SUCCESS;
    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( axone_ec,   Ec, CheckCoreCheckstop );

} // end namespace Ec
} // end namespace PRDF
