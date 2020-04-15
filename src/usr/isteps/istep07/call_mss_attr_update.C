/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_attr_update.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *  @file call_mss_attr_update.C
 *  Contains the wrapper for istep 7.5
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>
#include    <arch/pirformat.H>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>

#include    <hbotcompid.H>           // HWPF_COMP_ID
#include    <isteps/hwpisteperror.H>
#include    <istepHelperFuncs.H>     // captureError

#include    <errl/errludtarget.H>
#include    <initservice/isteps_trace.H>
#include    <initservice/initserviceif.H>
#include    <initservice/initsvcreasoncodes.H>

// SBE
#include    <sbeif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/attrrp.H>
#include    <targeting/common/mfgFlagAccessors.H>
#include    <targeting/targplatutil.H> //assertGetToplevelTarget

// HWAS
#include    <hwas/common/hwas.H>

// fapi2 support
#include <fapi2.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>


// HWP
#include <p10_mss_attr_update.H>

//HRMOR
#include <sys/misc.h>

#include <isteps/mem_utils.H>
#include <arch/memorymap.H>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


typedef struct procIds
{
    Target* proc;                                    // Proc
    ATTR_PROC_FABRIC_TOPOLOGY_ID_type topoIdDflt;    // Default Topo ID
    ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID_type topoIdEff; // Effective Topo ID
    ATTR_PROC_FABRIC_TOPOLOGY_ID_type topoId;        // Desired Topo ID
} procIds_t;

const uint8_t INVALID_PROC = 0xFF;


/**
 * @brief   check_proc0_memory_config   Check memory config for proc0
 *
 *  Loops through all processors gathering topology ID information for
 *  each one and determining which is proc0 based on having the smallest
 *  topology ID.
 *
 *  Checks that proc0 has associated functional dimms.  If it does not have any
 *  functional dimms behind it, look for a proc that does have functional dimms
 *  and swap IDs for these processors.
 *
 *  Loops through all processors again making sure that the effective topology
 *  IDs are the desired IDs.  If the IDs are not as desired, update the
 *  effective ID attributes and flag that an SBE Update is needed.
 *
 *  If SBE Update is needed, sync all attributes to the FSP and perform update.
 *
 * @param[in/out] io_istepErr  Error for this istep
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          nullptr if no errors;
 */
errlHndl_t check_proc0_memory_config(IStepError & io_istepErr)
{
    errlHndl_t l_err = nullptr;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "check_proc0_memory_config entry");

    // Get all procs
    TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);

    // Loop through all procs getting IDs
    procIds_t l_procIds[l_procsList.size()];
    uint8_t i = 0;
    uint8_t l_proc0 = INVALID_PROC;
    uint8_t l_victim = INVALID_PROC;

    Target* l_sys = UTIL::assertGetToplevelTarget();

    for (const auto & l_procChip : l_procsList)
    {
        l_procIds[i].proc = l_procChip;

        // Get Topology IDs
        l_procIds[i].topoIdDflt =
            l_procChip->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
        l_procIds[i].topoIdEff =
            l_procChip->getAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>();
        l_procIds[i].topoId = l_procIds[i].topoIdDflt;

        // Check if this proc should be tracked as proc0
        if(l_proc0 == INVALID_PROC)
        {
            // No proc0, make initial assignment
            l_proc0 = i;
        }
        else if(l_procIds[i].topoId < l_procIds[l_proc0].topoId)
        {
            // Smaller topo ID, replace assignment
            l_proc0 = i;
        }

        TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "check_proc0_memory_config: Initial settings for "
                  "Proc %.8X: topoIdDflt = %d, topoIdEff = %d, topoId = %d\n",
                  get_huid(l_procIds[i].proc),
                  l_procIds[i].topoIdDflt,
                  l_procIds[i].topoIdEff,
                  l_procIds[i].topoId);

        // Increment index
        i++;
    }

    // Get the functional DIMMs for proc0
    PredicateHwas l_functional;
    l_functional.functional(true);
    TargetHandleList l_dimms;
    PredicateCTM l_dimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
    PredicatePostfixExpr l_checkExprFunctional;
    l_checkExprFunctional.push(&l_dimm).push(&l_functional).And();
    targetService().getAssociated(l_dimms,
                                  l_procIds[l_proc0].proc,
                                  TargetService::CHILD_BY_AFFINITY,
                                  TargetService::ALL,
                                  &l_checkExprFunctional);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "check_proc0_memory_config: %d functional dimms behind proc0 "
              "%.8X",
              l_dimms.size(), get_huid(l_procIds[l_proc0].proc) );

    if(l_dimms.empty())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "check_proc0_memory_config: proc0 %.8X has no functional "
                  "dimms behind it",
                  get_huid(l_procIds[l_proc0].proc) );

        // Loop through all procs to find ones for memory remap
        for (i = 0; i < l_procsList.size(); i++)
        {
            // If proc0, then continue
            if(i == l_proc0)
            {
                continue;
            }

            // Get the functional DIMMs for the proc
            targetService().getAssociated(l_dimms,
                                          l_procIds[i].proc,
                                          TargetService::CHILD_BY_AFFINITY,
                                          TargetService::ALL,
                                          &l_checkExprFunctional);

            // If proc does not have memory, then continue
            if(l_dimms.empty())
            {
                TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "check_proc0_memory_config: Proc %.8X has no  "
                          "functional dimms behind it",
                          get_huid(l_procIds[i].proc) );

                continue;
            }

            // Use this proc for swapping memory with proc0
            l_victim = i;

            // Set the desired proc0 IDs from swapped proc's default IDs
            l_procIds[l_proc0].topoId = l_procIds[l_victim].topoIdDflt;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "check_proc0_memory_config: proc0 %.8X is set to use "
                      "topoId %d",
                      get_huid(l_procIds[l_proc0].proc),
                      l_procIds[l_proc0].topoId);

            // Set the desired IDs for the swapped proc from proc0 defaults
            l_procIds[l_victim].topoId = l_procIds[l_proc0].topoIdDflt;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "check_proc0_memory_config: Proc %.8X is set to use "
                      "topoId %d",
                      get_huid(l_procIds[l_victim].proc),
                      l_procIds[l_victim].topoId);

            // Leave loop after swapping memory
            break;
        }

    }

    // Loop through all procs detecting that IDs are set correctly
    for (i = 0; i < l_procsList.size(); i++)
    {
        TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "check_proc0_memory_config: Compare settings for "
              "Proc %.8X: topoIdEff = %d, topoId = %d",
              get_huid(l_procIds[i].proc),
              l_procIds[i].topoIdEff,
              l_procIds[i].topoId);

        if(l_procIds[i].topoId != l_procIds[i].topoIdEff)
        {
            // Update attributes
            (l_procIds[i].proc)->
              setAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>(l_procIds[i].topoId);
            ATTR_FORCE_SBE_UPDATE_type l_sbe_update =
                l_sys->getAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>();
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "updateProcessorSbeSeeproms needed due to "
                  "topology checks, will set ATTR_FORCE_SBE_UPDATE "
                  "Proc %.8X: topoIdEff = %d, topoId = %d l_sbe_update=0x%X",
                  get_huid(l_procIds[i].proc),
                  l_procIds[i].topoIdEff,
                  l_procIds[i].topoId, l_sbe_update);
            l_sys->setAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>
              (l_sbe_update | TARGETING::SBE_UPDATE_TYPE_TOPOLOGY_CHECKS);
        }

        TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "check_proc0_memory_config: Current attribute "
              "settings for Proc %.8X\n"
              "  ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID = %d\n"
              "  ATTR_PROC_FABRIC_TOPOLOGY_ID = %d\n",
              get_huid(l_procIds[i].proc),
              (l_procIds[i].proc)->
                  getAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>(),
              (l_procIds[i].proc)->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>());
    }

    return l_err;
} // end check_proc0_memory_config()

void check_hrmor_within_range (ATTR_PROC_MEM_TO_USE_type i_proc_mem_to_use,
                               IStepError & io_StepError)
{
    // TODO RTC 212966 - Support for topology id
    //extract group and chip id from PROC_MEM_TO_USE attribute
    uint8_t l_grp  {0};
    uint8_t l_chip {0};
    HWAS::parseProcMemToUseIntoGrpChipId(i_proc_mem_to_use, l_grp, l_chip);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "check_hrmor_within_range: PROC_MEM_TO_USE=0x%x,Grp=0x%x,Chip=0x%x",
            i_proc_mem_to_use, l_grp, l_chip);

    //Find a proc that matches current proc_mem_to_use's group/chip id
    TargetHandleList l_procs;
    getAllChips(l_procs, TYPE_PROC);

    TargetHandle_t l_procTgtMemUsed {nullptr};
    for (auto & l_proc : l_procs)
    {
        auto l_proc_topo = l_proc->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
        MEMMAP::groupId_t l_proc_grp = 0;
        MEMMAP::chipId_t l_proc_chip = 0;
        MEMMAP::extractGroupAndChip(l_proc_topo,
                                    l_proc_grp,
                                    l_proc_chip);

        if ((l_proc_grp == l_grp) && (l_proc_chip == l_chip))
        {
            l_procTgtMemUsed = l_proc;
            break;
        }
    }


    //if we find it, then we check that the hrmor is within
    //range of configured mem.
    //
    //Otherwise, we want to go down the sbe update and TI path
    bool l_sbeUpdateTIRequired = true;
    if (l_procTgtMemUsed)
    {
        auto l_lowest_mem_addr  = get_bottom_mem_addr(l_procTgtMemUsed);
        auto l_highest_mem_addr = get_top_mem_addr(l_procTgtMemUsed);
        auto l_hrmor = cpu_spr_value(CPU_SPR_HRMOR);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "check_hrmor_within_range: proc picked: 0x%x, lowest addr=0x%x, "
            "highest addr=0x%x HRMOR=0x%x", get_huid(l_procTgtMemUsed),
            l_lowest_mem_addr, l_highest_mem_addr, l_hrmor);

        if ((l_lowest_mem_addr <= l_hrmor) && (l_hrmor < l_highest_mem_addr))
        {
            //we are good -- no need for TI
            l_sbeUpdateTIRequired = false;
        }
    }

    if (l_sbeUpdateTIRequired)
    {
        Target* l_sys = UTIL::assertGetToplevelTarget();
        ATTR_FORCE_SBE_UPDATE_type l_sbe_update =
            l_sys->getAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>();
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "updateProcessorSbeSeeproms needed check_hrmor_within_range, "
            "will set ATTR_FORCE_SBE_UPDATE l_sbe_update=0x%X",
            l_sbe_update);
        l_sys->setAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>
          (l_sbe_update | TARGETING::SBE_UPDATE_TYPE_HRMOR_OUTSIDE_CONFIGURED_MEM);
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "check_hrmor_within_range: SBE update is NOT required");
    }
}

//
//  Wrapper function to call mss_attr_update
//
void*    call_mss_attr_update( void *io_pArgs )
{
    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_attr_update entry");
    errlHndl_t l_err = nullptr;

    do
    {
        bool l_isPhyp = is_phyp_load();
        bool l_spEnabled = INITSERVICE::spBaseServicesEnabled();

        Target* l_sys = UTIL::assertGetToplevelTarget();

        // Check the memory on master proc chip
        // Use this mechanism for:
        // non-phyp case or
        // PHYP on OpenPower machine
        if (!l_isPhyp || (l_isPhyp && !l_spEnabled))
        {
            l_err = check_proc0_memory_config(l_StepError);

            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR in check_proc0_memory_config. "
                           TRACE_ERR_FMT,
                           TRACE_ERR_ARGS(l_err));

                l_StepError.addErrorDetails(l_err);
                errlCommit( l_err, HWPF_COMP_ID );
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS:  check_proc0_memory_config");
            }
        }
        // For phyp based systems on FSP, HWSV will call
        // HWAS::update_proc_mem_to_use function to determine the new
        // proc to use for memory and update SBE scratch registers as
        // necessary. HB just needs to tell HWSV to do that. There are
        // only two cases where HB will want HWSV to attempt the above
        // logic.
        // 1) HRMOR that we booted doesn't match the current value
        //    of PROC_MEM_TO_USE attribute. This can only happen if the
        //    SBE is really old. So, force an sbe update and TI.
        // 2) HB deconfigured a bunch of dimms in istep7. In this case,
        //    HB computes new value of PROC_MEM_TO_USE and checks it
        //    against current value of PROC_MEM_TO_USE. If they don't
        //    match, HB will force a reconfig loop TI
        else
        {

            //////////////////////////////////////////////////////////////////
            //Case1 from above, where HRMOR doesn't fall in configured mem range
            //of proc pointed by ATTR_PROC_MEM_TO_USE
            //////////////////////////////////////////////////////////////////

            //Get the master proc to get the current value of PROC_MEM_TO_USE
            TargetHandle_t l_mProc;
            l_err = targetService().queryMasterProcChipTargetHandle(l_mProc);
            if (l_err)
            {
                TRACFCOMP (ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR: getting master proc");
                l_StepError.addErrorDetails(l_err);
                errlCommit( l_err, HWPF_COMP_ID );
                break;
            }

            // TODO RTC 212966 - Support for topology ID
            // NOTE: ATTR_PROC_MEM_TO_USE contains group/chip id instead of
            // topology id.
            auto l_proc_mem_to_use = l_mProc->getAttr<ATTR_PROC_MEM_TO_USE>();
            check_hrmor_within_range(l_proc_mem_to_use, l_StepError);

            //////////////////////////////////////////////////////////////////
            //Case2 from above, where HB deconfigured dimms, so, we need to
            //recompute PROC_MEM_TO_USE and if it is not the same TI
            //////////////////////////////////////////////////////////////////
            bool l_valid {true};
            l_err=HWAS::check_current_proc_mem_to_use_is_still_valid (l_valid);
            if (l_err || !l_valid)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR: check_current_proc_mem_to_use_is_still_valid"
                        " going down for a reconfig loop");
                //We deconfigured a bunch of dimms and the answer
                //changed for which proc's memory to use. Trigger
                //reconfig loop TI
                INITSERVICE::doShutdown(INITSERVICE::SHUTDOWN_DO_RECONFIG_LOOP);

            }

            // Need to handle some code upgrade scenarios where the
            // swap values aren't getting updated on the SP.
            // We will force the EFF attributes to match.
            TargetHandleList l_procTargetList;
            getAllChips(l_procTargetList, TYPE_PROC);
            for (const auto & l_proc: l_procTargetList)
            {
                auto l_topoId =
                  l_proc->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
                auto l_effTopoId =
                  l_proc->getAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>();
                if( l_topoId != l_effTopoId )
                {
                    ATTR_FORCE_SBE_UPDATE_type l_sbe_update =
                        l_sys->getAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>();
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Mismatch on proc %.8X : topoId=%.8X, effTopoId=%.8X "
                        "will set ATTR_FORCE_SBE_UPDATE l_sbe_update=0x%X",
                              get_huid(l_proc), l_topoId, l_effTopoId, l_sbe_update);
                    l_sys->setAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>
                      (l_sbe_update | TARGETING::SBE_UPDATE_TYPE_FABRIC_EFF_TOPOLOGY);
                    l_proc->setAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>
                      (l_topoId);
                }
            }
        }

        // Get all functional MI chiplets and call p10_mss_attr_update
        // on each
        TargetHandleList l_miTargetList;
        getAllChiplets(l_miTargetList, TYPE_MI);

        for (const auto & l_miTarget: l_miTargetList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_MI>
                l_fapi2_mi_target(l_miTarget);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p10_mss_attr_update HWP on "
                "MI target HUID %.8X", get_huid(l_miTarget));
            FAPI_INVOKE_HWP(l_err, p10_mss_attr_update, l_fapi2_mi_target);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR in p10_mss_attr_update HWP "
                    "for HUID %.8x. "
                    TRACE_ERR_FMT,
                    get_huid(l_miTarget),
                    TRACE_ERR_ARGS(l_err));
                l_StepError.addErrorDetails(l_err);
                errlCommit( l_err, HWPF_COMP_ID );
            }
        }
        ATTR_FORCE_SBE_UPDATE_type l_sbe_update =
            l_sys->getAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>();
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Checking FORCE_SBE_UPDATE=0x%X",
            l_sbe_update);
        if (l_sbe_update != 0)
        {
            if (l_sys->getAttr<ATTR_IS_MPIPL_HB>() == true)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SBE update NOT allowed during MPIPL!");

                /*@
                 * @errortype
                 * @moduleid          MOD_CALL_MSS_ATTR_UPDATE
                 * @reasoncode        RC_SBE_UPDATE_IN_MPIPL
                 * @userdata1         ATTR_FORCE_SBE_UPDATE, bit mask of reasons
                 *                    See SBE_UPDATE_TYPE from attribute_types_hb.xml
                 * @userdata2         0
                 * @devdesc           SBE cannot be reset during MPIPL
                 * @custdesc          Not allowed to update SBE during MPIPL boot
                 */
                l_err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                              MOD_CALL_MSS_ATTR_UPDATE,
                              RC_SBE_UPDATE_IN_MPIPL,
                              l_sbe_update,
                              0);
                l_err->collectTrace("ISTEPS_TRACE");
                errlCommit(l_err, HWPF_COMP_ID);
            }
            else
            {
                l_err = SBE::updateProcessorSbeSeeproms();
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "WARNING: Return from updateProcessorSbeSeeproms "
                    "this may OR may -NOT- be an issue, "
                    "if undesired, check any configuration overrides. "
                    "FORCE_SBE_UPDATE=0x%X bit mask indicates reasons",
                    l_sbe_update);
                // See attribute_types_hb.xml for SBE_UPDATE_TYPE ^^
                // SBE_UPDATE_DISABLE and NO_SBE_UPDATES can influence
                // Next clear FORCE_SBE_UPDATE for any future usages
                // Clearing is just to remove the mark on the wall in case
                // in the future we want to set/trigger in other logic
                // and avoids conflicting signals in later isteps
                //
                // In updateProcessorSbeSeeproms sbeDoReboot is called,
                // so we should be IPL'ing at this point causing hostboot
                // to restart, thus returning from the reboot request
                // is an error, either the request for reboot explicitly
                // failed (error) -or- hostboot unexpectedly returned
                // from the call without a reboot happening (also an error).
                //
                // If a developer overrides with SBE_UPDATE_DISABLE or
                // NO_SBE_UPDATES this needs to be managed outside the
                // scope of this logic.
                //
                l_sys->setAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>
                  (TARGETING::SBE_UPDATE_TYPE_CLEAR);
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR: updateProcessorSbeSeeproms");
                    l_err->collectTrace("ISTEPS_TRACE");
                    captureError(l_err, l_StepError, HWPF_COMP_ID);
                }
                else
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR: updateProcessorSbeSeeproms"
                          " unexpectedly returned");
                    /*@
                     * @errortype
                     * @moduleid     MOD_CALL_MSS_ATTR_UPDATE
                     * @reasoncode   RC_SBE_UPDATE_UNEXPECTEDLY_FAILED
                     * @userdata1    ATTR_FORCE_SBE_UPDATE, bit mask of reasons
                     *               See SBE_UPDATE_TYPE from attribute_types_hb.xml
                     * @userdata2    0
                     * @devdesc      An IPL failure occurred
                     * @custdesc     Return from updateProcessorSbeSeeproms unexpectedly
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MOD_CALL_MSS_ATTR_UPDATE,
                                    RC_SBE_UPDATE_UNEXPECTEDLY_FAILED,
                                    l_sys->getAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>(),
                                    0);
                    TargetHandle_t l_pMasterProcChip(nullptr);
                    targetService().masterProcChipTargetHandle(l_pMasterProcChip);
                    l_err->addHwCallout(l_pMasterProcChip,
                                         HWAS::SRCI_PRIORITY_HIGH,
                                         HWAS::NO_DECONFIG,
                                         HWAS::GARD_NULL);
                    l_err->collectTrace(TARG_COMP_NAME);
                    l_err->collectTrace(SBE_COMP_NAME);
                    captureError(l_err, l_StepError, HWPF_COMP_ID);
                }
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ATTR_FORCE_SBE_UPDATE -NOT- "
                      "set to call updateProcessorSbeSeeproms,"
                      " skipped calling updateProcessSbeSeeproms");
        }
    } while (0);
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_attr_update exit" );

    return l_StepError.getErrorHandle();
}

};   // end namespace
