/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_draminit.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

// Error Handling and Tracing Support
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <plat_trace.H>

// Generated files
#include  <config.h>

// Istep 13 framework
#include <istepHelperFuncs.H>
#include "istep13consts.H"
#include "platform_vddr.H"

// Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

// fapi2 HWP invoker
#include  <fapi2/plat_hwp_invoker.H>

//From Import Directory (EKB Repository)
#include  <fapi2.H>
#ifndef CONFIG_AXONE
    #include  <p9_mss_draminit.H>
    #include  <p9c_mss_draminit.H>
#else
#include <chipids.H>
    #include  <exp_draminit.H>
    #include  <gem_draminit.H>
#endif

// NVDIMM support
#ifdef CONFIG_NVDIMM
#include    <isteps/nvdimm/nvdimm.H>
#endif


using namespace ERRORLOG;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace TARGETING;

namespace ISTEP_13
{
// Declare local functions
void nimbus_mss_draminit(IStepError & io_istepError);
void cumulus_mss_draminit(IStepError & io_istepError);
void axone_mss_draminit(IStepError & io_istepError);
void mss_post_draminit( IStepError & io_stepError );

void* call_mss_draminit (void *io_pArgs)
{
    IStepError l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit entry" );
    auto l_procModel = TARGETING::targetService().getProcessorModel();

    switch (l_procModel)
    {
        case TARGETING::MODEL_CUMULUS:
            cumulus_mss_draminit(l_stepError);
            break;
        case TARGETING::MODEL_AXONE:
            axone_mss_draminit(l_stepError);
            break;
        case TARGETING::MODEL_NIMBUS:
            nimbus_mss_draminit(l_stepError);
            break;
        default:
            assert(0, "call_mss_draminit: Unsupported model type 0x%04X",
                l_procModel);
            break;
    }

    // call POST_DRAM_INIT function, if nothing failed above
    if( INITSERVICE::spBaseServicesEnabled() &&
        (l_stepError.getErrorHandle() == nullptr) )
    {
        mss_post_draminit(l_stepError);
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit exit" );

    return l_stepError.getErrorHandle();
}

void mss_post_draminit( IStepError & io_stepError )
{
    errlHndl_t l_err = NULL;
    bool rerun_vddr = false;

    do {

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "mss_post_draminit entry" );

        set_eff_config_attrs_helper(DEFAULT, rerun_vddr);

        if ( rerun_vddr == false )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "mss_post_draminit: nothing to do" );
            break;
        }

        // Call mss_volt_vddr_offset to recalculate VDDR voltage
        TARGETING::Target* pSysTarget = nullptr;
        TARGETING::targetService().getTopLevelTarget(pSysTarget);
        assert((pSysTarget != nullptr),
                "mss_post_draminit: Code bug!  System target was NULL.");

        // only calculate if system supports dynamic voltage
        if (pSysTarget->getAttr< TARGETING::ATTR_SUPPORTS_DYNAMIC_MEM_VOLT >()
            == 1)
        {
            // Update mss_volt_vddr_offset_millivolts attribute
            l_err = computeDynamicMemoryVoltage<
                        TARGETING::ATTR_MSS_VDDR_PROGRAM,
                        TARGETING::ATTR_VDDR_ID>();
            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                    "VDDR domain",
                    l_err->reasonCode());
                io_stepError.addErrorDetails(l_err);
                errlCommit(l_err,HWPF_COMP_ID);
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "mss_post_draminit: mss_volt_vddr_offset_millivolts "
                 "successfully updated");
            }
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "mss_post_draminit: dynamic voltage not "
                "supported on this system");
            break;
        }

        // Call HWSV to call POWR code
        // This fuction has compile-time binding for different platforms
        l_err = platform_adjust_vddr_post_dram_init();

        if( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mss_post_draminit: "
                      "platform_adjust_vddr_post_dram_init() returns error",
                      l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            io_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }

    } while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "mss_post_draminit exit" );
    return;
}

#ifndef CONFIG_AXONE
void nimbus_mss_draminit(IStepError & io_istepError)
{
    errlHndl_t l_err = NULL;

    // Get all MCBIST targets
    TARGETING::TargetHandleList l_mcbistTargetList;
    getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);

    for (const auto & l_mcbist_target : l_mcbistTargetList)
    {
        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9_mss_draminit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mcbist_target));

        fapi2::Target<fapi2::TARGET_TYPE_MCBIST> l_fapi_mcbist_target
            (l_mcbist_target);

        // Initialize the NVDIMMs before hitting draminit
#ifdef CONFIG_NVDIMM
        TARGETING::TargetHandleList l_dimmTargetList;
        getChildAffinityTargets(l_dimmTargetList, l_mcbist_target, CLASS_NA, TYPE_DIMM);

        for (const auto & l_dimm : l_dimmTargetList)
        {
            if (isNVDIMM(l_dimm))
            {
                NVDIMM::nvdimm_init(l_dimm);
            }
        }
#endif
        FAPI_INVOKE_HWP(l_err, p9_mss_draminit, l_fapi_mcbist_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : p9_mss_draminit HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mcbist_target).addToLog(l_err);

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS running p9_mss_draminit HWP on "
                       "target HUID %.8X", TARGETING::get_huid(l_mcbist_target));
        }

    }   // endfor   mcbist's
}

void cumulus_mss_draminit(IStepError & io_istepError)
{
    errlHndl_t l_err = NULL;

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (const auto & l_membufTarget : l_membufTargetList )
    {
        TARGETING::TargetHandleList l_mbaTargetList;
        getChildChiplets(l_mbaTargetList, l_membufTarget, TYPE_MBA);

        for (const auto & l_mbaTarget : l_mbaTargetList )
        {
            // Dump current run on target
             TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9c_mss_draminit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mbaTarget));

            //  call the HWP with each target
            fapi2::Target <fapi2::TARGET_TYPE_MBA_CHIPLET> l_fapi_mba_target(l_mbaTarget);

            FAPI_INVOKE_HWP(l_err, p9c_mss_draminit, l_fapi_mba_target);

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : p9c_mss_draminit HWP returns error",
                    l_err->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_mbaTarget).addToLog(l_err);

                // Create IStep error log and cross reference to error that occurred
                io_istepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS running p9c_mss_draminit HWP on "
                       "target HUID %.8X", TARGETING::get_huid(l_mbaTarget));
            }
         } // end MBA loop
    } // end MEMBUF loop
}

#else
void nimbus_mss_draminit(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'p9_mss_draminit' but Nimbus code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}

void cumulus_mss_draminit(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'p9c_mss_draminit' but Cumulus code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif

#ifdef CONFIG_AXONE
void axone_mss_draminit(IStepError & io_istepError)
{
    errlHndl_t l_err = NULL;

    // Get all OCMB targets
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    bool isGeminiChip = false;
    for ( const auto & l_ocmb : l_ocmbTargetList )
    {
        fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(l_ocmb);

        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb->getAttr< TARGETING::ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            isGeminiChip = false;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running exp_draminit HWP on target HUID 0x%.8X",
                TARGETING::get_huid(l_ocmb) );
            FAPI_INVOKE_HWP(l_err, exp_draminit, l_fapi_ocmb_target);
        }
        else
        {
            isGeminiChip = true;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running gem_draminit HWP on target HUID 0x%.8X, chipId 0x%.4X",
                TARGETING::get_huid(l_ocmb), chipId );
            FAPI_INVOKE_HWP(l_err, gem_draminit, l_fapi_ocmb_target);
        }

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X : %s_draminit HWP returned error",
                l_err->reasonCode(), isGeminiChip?"gem":"exp");

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_ocmb).addToLog(l_err);

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS running %s_draminit HWP on target HUID 0x%.8X",
                isGeminiChip?"gem":"exp", TARGETING::get_huid(l_ocmb) );
        }
    } // end of OCMB loop
}

#else

void axone_mss_draminit(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'exp_draminit' or 'gem_draminit' but Axone code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif

};
