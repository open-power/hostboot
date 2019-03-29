/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_eff_config.C $                */
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
/**
 *  @file call_mss_eff_config.C
 *  Contains the wrapper for mss_eff_config istep
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <pnor/pnorif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

// HWP
#include    <p9_mss_eff_config.H>
#include    <p9_mss_eff_config_thermal.H>
#include    <p9_mss_eff_grouping.H>
#include    <p9c_mss_eff_config.H>
#include    <p9c_mss_eff_mb_interleave.H>
#include    <p9c_mss_eff_config_thermal.H>

#ifdef CONFIG_AXONE
#include    <p9a_mss_eff_config.H>
#include    <p9a_mss_eff_config_thermal.H>
#endif

#include    <hbotcompid.H>

#include    <nvram/nvram_interface.H>
#include    <secureboot/smf.H>
#include    <stdlib.h>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

errlHndl_t call_mss_eff_grouping(IStepError & io_istepErr)
{
    errlHndl_t l_err = nullptr;

    TARGETING::TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);

    for (const auto & l_cpu_target : l_procsList)
    {
        //  print call to hwp and write HUID of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9_mss_eff_grouping HWP cpu target HUID %.8X",
            TARGETING::get_huid(l_cpu_target));

        // cast OUR type of target to a FAPI type of target.
        const fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_cpu_target
            (l_cpu_target);

        FAPI_INVOKE_HWP(l_err, p9_mss_eff_grouping, l_fapi_cpu_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "ERROR 0x%.8X:  p9_mss_eff_grouping HWP on target %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_cpu_target));

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_cpu_target).addToLog(l_err);
            io_istepErr.addErrorDetails(l_err);
            errlCommit(l_err, ISTEP_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  p9_mss_eff_grouping HWP on target %.8x",
                TARGETING::get_huid(l_cpu_target));
        }
    }   // end processor list processing

    return l_err;
}


errlHndl_t call_mss_eff_mb_interleave()
{
    errlHndl_t l_err = NULL;

    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (const auto & l_membuf_target : l_membufTargetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  Running p9c_mss_eff_mb_interleave HWP on HUID %.8X",
                TARGETING::get_huid(l_membuf_target));

        fapi2::Target <fapi2::TARGET_TYPE_MEMBUF_CHIP> l_membuf_fapi_target
                (l_membuf_target);

        FAPI_INVOKE_HWP(l_err, p9c_mss_eff_mb_interleave, l_membuf_fapi_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: p9c_mss_eff_mb_interleave HWP returns error",
                      l_err->reasonCode());
            ErrlUserDetailsTarget(l_membuf_target).addToLog(l_err);
            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Successfully ran p9c_mss_eff_mb_interleave HWP on HUID %.8X",
                      TARGETING::get_huid(l_membuf_target));
        }
    }
    return l_err;
}


//
//  Wrapper function to call mss_eff_config
//
void*    call_mss_eff_config( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
#ifdef CONFIG_SECUREBOOT
    auto memdLoaded = false;
#endif

    do {

    #ifdef CONFIG_SECUREBOOT
    // MEMD used by p9_mss_eff_config HWP
    l_err = loadSecureSection(PNOR::MEMD);
    if (l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            ERR_MRK "Failed in call to loadSecureSection for section "
            "PNOR:MEMD");

        // Create istep error and link it to PLID of original error
        l_StepError.addErrorDetails(l_err);
        errlCommit(l_err, ISTEP_COMP_ID);
        break;
    }
    memdLoaded = true;
    #endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config entry" );

    TARGETING::ATTR_MODEL_type l_procModel = TARGETING::targetService().getProcessorModel();

    TARGETING::Target* l_sys = nullptr;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != nullptr );

    TARGETING::TargetHandleList l_membufTargetList;
    TARGETING::TargetHandleList l_mcsTargetList;
    TARGETING::TargetHandleList l_memportTargetList;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>> l_fapi_memport_targets;

    if(l_procModel == TARGETING::MODEL_CUMULUS)
    {
        // Get all Centaur targets
        getAllChips(l_membufTargetList, TYPE_MEMBUF);

        for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            TARGETING::Target* l_pCentaur = *l_membuf_iter;
            TARGETING::TargetHandleList l_mbaTargetList;
            getChildChiplets(l_mbaTargetList,
                            l_pCentaur,
                            TYPE_MBA);
            for (TargetHandleList::const_iterator
                l_mba_iter = l_mbaTargetList.begin();
                l_mba_iter != l_mbaTargetList.end();
                ++l_mba_iter)
            {
              //  Make a local copy of the target for ease of use
              TARGETING::Target*  l_mbaTarget = *l_mba_iter;
              TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "p9c_mss_eff_config HWP target HUID %.8x",
                          TARGETING::get_huid(l_mbaTarget));

                //  call the HWP with each target
                fapi2::Target <fapi2::TARGET_TYPE_MBA_CHIPLET> l_fapi_mba_target(l_mbaTarget);

                FAPI_INVOKE_HWP(l_err, p9c_mss_eff_config, l_fapi_mba_target);

                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X:  p9c_mss_eff_config HWP on target HUID %.8x",
                        l_err->reasonCode(), TARGETING::get_huid(l_mbaTarget) );

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_mbaTarget).addToLog( l_err );

                    // Create IStep error log and cross reference to error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  p9c_mss_eff_config HWP");
                }
            } // end mba loop
        }  // end membuf loop
    }
    else if(l_procModel == TARGETING::MODEL_NIMBUS)
    {
        // Get all functional MCS chiplets
        getAllChiplets(l_mcsTargetList, TYPE_MCS);

        // Iterate over all MCS, calling mss_eff_config and mss_eff_config_thermal
        for (const auto & l_mcs_target : l_mcsTargetList)
        {
            // Get the TARGETING::Target pointer and its HUID
            uint32_t l_huid = TARGETING::get_huid(l_mcs_target);

            // Create a FAPI target representing the MCS
            const fapi2::Target <fapi2::TARGET_TYPE_MCS> l_fapi_mcs_target
                (l_mcs_target);

            // Call the mss_eff_config HWP
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "p9_mss_eff_config HWP. MCS HUID %.8X", l_huid);
            FAPI_INVOKE_HWP(l_err, p9_mss_eff_config, l_fapi_mcs_target);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  p9_mss_eff_config HWP ", l_err->reasonCode());

                // Ensure istep error created and has same plid as this error
                ErrlUserDetailsTarget(l_mcs_target).addToLog(l_err);
                l_err->collectTrace(EEPROM_COMP_NAME);
                l_err->collectTrace(I2C_COMP_NAME);
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err, ISTEP_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  p9_mss_eff_config HWP");
            }
        } // end mcs loop
    }
#ifdef CONFIG_AXONE
    else if(l_procModel == TARGETING::MODEL_AXONE)
    {
        // Get all functional MEM_PORT chiplets
        getAllChiplets(l_memportTargetList, TYPE_MEM_PORT);

        for(const auto & l_memport_target: l_memportTargetList)
        {
            // Create a FAPI target representing the MEM_PORT target
            const fapi2::Target <fapi2::TARGET_TYPE_MEM_PORT> l_fapi_memport_target
                (l_memport_target);

            l_fapi_memport_targets.push_back(l_fapi_memport_target);

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call p9a_mss_eff_config HWP on MEM_PORT HUID %.8X",
                      TARGETING::get_huid(l_memport_target));

            FAPI_INVOKE_HWP(l_err, p9a_mss_eff_config, l_fapi_memport_target);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X:  p9a_mss_eff_config HWP on target 0x%.08X",
                          l_err->reasonCode(),
                          TARGETING::get_huid(l_memport_target));

                // Ensure istep error created and has same plid as this error
                ErrlUserDetailsTarget(l_memport_target).addToLog(l_err);
                l_err->collectTrace(EEPROM_COMP_NAME);
                l_err->collectTrace(I2C_COMP_NAME);
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err, ISTEP_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS :  p9a_mss_eff_config HWP on target 0x%.08X",
                          TARGETING::get_huid(l_memport_target));
            }
        } // end mem_port list
    }
#endif

    if(!l_StepError.isNull())
    {
        break;
    }

    l_err = call_mss_eff_mb_interleave();

    if (l_err)
    {
        // Ensure istep error created and has same plid as this error
        l_StepError.addErrorDetails( l_err );
        errlCommit( l_err, ISTEP_COMP_ID);
        break;
    }

    if(l_procModel == TARGETING::MODEL_CUMULUS)
    {
        for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
        {
            //  Make a local copy of the target for ease of use
            TARGETING::Target* l_pCentaur = *l_membuf_iter;

            TARGETING::TargetHandleList l_mbaTargetList;
            getChildChiplets(l_mbaTargetList,
                        l_pCentaur,
                        TYPE_MBA);

            for (TargetHandleList::const_iterator
                l_mba_iter = l_mbaTargetList.begin();
                l_mba_iter != l_mbaTargetList.end();
                ++l_mba_iter)
            {
                //  Make a local copy of the target for ease of use
                TARGETING::Target*  l_mbaTarget = *l_mba_iter;
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "p9c_mss_eff_config_thermal HWP target HUID %.8x",
                TARGETING::get_huid(l_mbaTarget));

                //  call the HWP with each target
                fapi2::Target <fapi2::TARGET_TYPE_MBA_CHIPLET> l_fapi_mba_target(l_mbaTarget);

                FAPI_INVOKE_HWP(l_err, p9c_mss_eff_config_thermal, l_fapi_mba_target);

                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  p9c_mss_eff_config_thermal HWP on target HUID %.8x",
                    l_err->reasonCode(), TARGETING::get_huid(l_mbaTarget) );

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_mbaTarget).addToLog( l_err );

                    // Create IStep error log and cross reference to error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  p9c_mss_eff_config_thermal HWP");
                }
            }
        }
    }
    else if(l_procModel == TARGETING::MODEL_NIMBUS)
    {
        std::map<ATTR_VDDR_ID_type,TARGETING::TargetHandleList> l_domainIdGroups;
        TARGETING::TargetHandleList l_mcbistTargetList;
        getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);

        // Iterate over all MCBIST, calling mss_eff_config_thermal
        for (const auto & l_mcbist_target : l_mcbistTargetList)
        {
            TARGETING::TargetHandleList l_mcsChildren;
            getChildChiplets(l_mcsChildren,l_mcbist_target, TARGETING::TYPE_MCS);

            ATTR_VDDR_ID_type l_vddr_id = l_mcbist_target->getAttr<ATTR_VDDR_ID>();
            if(l_domainIdGroups.find(l_vddr_id) == l_domainIdGroups.end())
            {
                std::pair<ATTR_VDDR_ID_type, TARGETING::TargetHandleList> tuple(l_vddr_id, l_mcsChildren);
                l_domainIdGroups.insert(tuple);
            }
            else
            {
                l_domainIdGroups[l_vddr_id].insert(l_domainIdGroups[l_vddr_id].end(), l_mcsChildren.begin(), l_mcsChildren.end());
            }
        }

        for (auto & l_tuple : l_domainIdGroups)
        {
            std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>> l_fapi_mcs_targs;
            for(const auto & l_mcs_target : l_tuple.second)
            {
                // Create a FAPI target representing the MCS
                const fapi2::Target <fapi2::TARGET_TYPE_MCS> l_fapi_mcs_target
                (l_mcs_target);
                l_fapi_mcs_targs.push_back(l_fapi_mcs_target);
            }
            // Call the mss_eff_config_thermal HWP
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "p9_mss_eff_config_thermal HWP. ");
            FAPI_INVOKE_HWP(l_err, p9_mss_eff_config_thermal,l_fapi_mcs_targs);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X:  p9_mss_eff_config_thermal HWP ",
                        l_err->reasonCode());

                // Ensure istep error created and has same plid as this error
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err, ISTEP_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS : p9_mss_eff_config_thermal HWP");
            }
        }
    }
#ifdef CONFIG_AXONE
    else if(l_procModel == TARGETING::MODEL_AXONE)
    {
        if(l_fapi_memport_targets.size() > 0)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call p9a_mss_eff_config_thermal HWP on %d MEM_PORT targets",
                      l_fapi_memport_targets.size());

            FAPI_INVOKE_HWP(l_err, p9a_mss_eff_config_thermal, l_fapi_memport_targets);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X:  p9a_mss_eff_config_thermal HWP",
                          l_err->reasonCode());

                // Ensure istep error created and has same plid as this error
                l_err->collectTrace(EEPROM_COMP_NAME);
                l_err->collectTrace(I2C_COMP_NAME);
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err, ISTEP_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS :  p9a_mss_eff_config_thermal HWP");
            }
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "No MEM_PORT targets found, skipping p9a_mss_eff_config_thermal HWP");
        }
    }
#endif


    if (!l_StepError.isNull())
    {
        break;
    }

    // Stack the memory on each chip
    l_err = call_mss_eff_grouping(l_StepError);

    if (l_err)
    {
        // Ensure istep error created and has same plid as this error
        l_StepError.addErrorDetails( l_err );
        errlCommit( l_err, ISTEP_COMP_ID);
    }

#ifndef CONFIG_FSP_BUILD
    if(!l_StepError.isNull())
    {
        break;
    }

    const char* l_smfMemAmtStr = nullptr;
    l_err = NVRAM::nvramRead(NVRAM::SMF_MEM_AMT_KEY, l_smfMemAmtStr);
    if(l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK"NVRAM read failed. Will not attempt to distribute any SMF memory.");
        // Do not propagate the error - we don't care if NVRAM read fails
        delete l_err;
        l_err = nullptr;
        break;
    }

    // l_smfMemAmtStr will be nullptr if the SMF_MEM_AMT_KEY doesn't exist
    if(l_smfMemAmtStr)
    {
        uint64_t l_smfMemAmt = strtoul(l_smfMemAmtStr, nullptr, 16);
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK"Distributing 0x%.16llx SMF memory among the procs on the system", l_smfMemAmt);
        l_err = SECUREBOOT::SMF::distributeSmfMem(l_smfMemAmt);
        if(l_err)
        {
            // Do not propagate or break on error - distributeSmfMem will
            // not return unrecoverable errors.
            errlCommit(l_err, ISTEP_COMP_ID);
        }
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK"SMF_MEM_AMT_KEY was not found in NVRAM; no SMF memory was distributed.");
    }

#endif

    } while (0);

    #ifdef CONFIG_SECUREBOOT
    if(memdLoaded)
    {
        l_err = unloadSecureSection(PNOR::MEMD);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK "Failed in call to unloadSecureSection for section "
                "PNOR:MEMD");

            // Create istep error and link it to PLID of original error
            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, ISTEP_COMP_ID);
        }
        else
        {
            memdLoaded = false;
        }
    }
    #endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );
    return l_StepError.getErrorHandle();
}
};   // end namespace
