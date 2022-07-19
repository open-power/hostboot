/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_mss_scrub.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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

#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>
#include <util/misc.H>
#include <diag/prdf/prdfMain.H>
#include <plat_hwp_invoker.H>     // for FAPI_INVOKE_HWP
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H> // mss::unmask::after_background_scrub
#include <chipids.H> // for POWER_CHIPID

using namespace ERRORLOG;
using namespace TARGETING;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace TARGETING;

namespace ISTEP_16
{

void* call_mss_scrub(void* const io_pArgs)
{
    #define ISTEP_FUNC "call_mss_scrub: "

    IStepError l_stepError;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC "entry");

    errlHndl_t errl = nullptr;

    do
    {
        if (Util::isSimicsRunning())
        {
            // There are performance issues and some functional deficiencies
            // that make background scrub problematic in SIMICs.
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC
                      "Background scrubbing not supported in SIMICs");
            break;
        }

        TargetHandle_t sysTrgt = nullptr;
        targetService().getTopLevelTarget(sysTrgt);

        // The OCMB_CHIP target type runs the maintenance commands.
        const TARGETING::TYPE maintTrgtType = TYPE_OCMB_CHIP;

        // Start background scrubbing on all targets of this maintenance type.
        TargetHandleList maintList;
        if ( TYPE_OCMB_CHIP == maintTrgtType )
        {
            getAllChips( maintList, maintTrgtType );
        }
        else
        {
            getAllChiplets( maintList, maintTrgtType );
        }
        for ( const auto & maintTrgt : maintList )
        {
            bool start = true; // initially true except for MP-IPL conditions.

            // Continue to the next target if we are unable to start background
            // scrubbing on this target.
            if (!start)
            {
                continue;
            }

            // Start the command on this target.
            errl = PRDF::startScrub(maintTrgt);

            if (nullptr != errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC
                          "PRDF::startScrub(0x%08x) failed",
                          get_huid(maintTrgt));
                break;
            }

            if (TYPE_OCMB_CHIP == maintTrgtType)
            {
                fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> ft (maintTrgt);

                uint32_t l_chipId = maintTrgt->getAttr<ATTR_CHIP_ID>();

                if (l_chipId == POWER_CHIPID::EXPLORER_16)
                {
                    FAPI_INVOKE_HWP(errl, mss::unmask::after_background_scrub<
                        mss::mc_type::EXPLORER>, ft);
                }
                else if (l_chipId == POWER_CHIPID::ODYSSEY_16)
                {
                    FAPI_INVOKE_HWP(errl, mss::unmask::after_background_scrub<
                        mss::mc_type::ODYSSEY>, ft);
                }
                else
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC
                        "Skipping call to mss::unmask::after_background_scrub "
                        "on target HUID 0x%.8X, chipId 0x%.8X is not an "
                        "Explorer or Odyssey OCMB.",
                        TARGETING::get_huid(maintTrgt), l_chipId);
                }

                if (errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC
                              "mss::unmask::after_background_scrub(0x%08x) failed: "
                              TRACE_ERR_FMT,
                              get_huid(maintTrgt),
                              TRACE_ERR_ARGS(errl));
                    break;
                }
            }
        }
        if (nullptr != errl)
        {
            break;
        }
    } while (0);

    if (nullptr != errl)
    {
        l_stepError.addErrorDetails(errl);
        errl->collectTrace("ISTEPS_TRACE");
        errlCommit(errl, HWPF_COMP_ID);
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC "exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

    #undef ISTEP_FUNC
} // end call_mss_scrub

} // end namespace ISTEP_16
