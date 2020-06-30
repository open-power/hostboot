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
#include    <initservice/mboxRegs.H>

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
#include <p10_frequency_buckets.H>
#include <p10_sbe_scratch_regs.H>

//HRMOR
#include <sys/misc.h>

#include <isteps/mem_utils.H>
#include <arch/memorymap.H>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
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

    TRACFCOMP(g_trac_isteps_trace,
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

        TRACDCOMP(g_trac_isteps_trace,
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

    TRACFCOMP(g_trac_isteps_trace,
              "check_proc0_memory_config: %d functional dimms behind proc0 "
              "%.8X",
              l_dimms.size(), get_huid(l_procIds[l_proc0].proc) );

    if(l_dimms.empty())
    {
        TRACFCOMP(g_trac_isteps_trace,
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
                TRACDCOMP(g_trac_isteps_trace,
                          "check_proc0_memory_config: Proc %.8X has no  "
                          "functional dimms behind it",
                          get_huid(l_procIds[i].proc) );

                continue;
            }

            // Use this proc for swapping memory with proc0
            l_victim = i;

            // Set the desired proc0 IDs from swapped proc's default IDs
            l_procIds[l_proc0].topoId = l_procIds[l_victim].topoIdDflt;
            TRACFCOMP(g_trac_isteps_trace,
                      "check_proc0_memory_config: proc0 %.8X is set to use "
                      "topoId %d",
                      get_huid(l_procIds[l_proc0].proc),
                      l_procIds[l_proc0].topoId);

            // Set the desired IDs for the swapped proc from proc0 defaults
            l_procIds[l_victim].topoId = l_procIds[l_proc0].topoIdDflt;
            TRACFCOMP(g_trac_isteps_trace,
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
        TRACDCOMP(g_trac_isteps_trace,
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
                l_sys->getAttr<ATTR_FORCE_SBE_UPDATE>();
            TRACFCOMP(g_trac_isteps_trace,
                  "updateProcessorSbeSeeproms needed due to "
                  "topology checks, will set ATTR_FORCE_SBE_UPDATE "
                  "Proc %.8X: topoIdEff = %d, topoId = %d l_sbe_update=0x%X",
                  get_huid(l_procIds[i].proc),
                  l_procIds[i].topoIdEff,
                  l_procIds[i].topoId, l_sbe_update);
            l_sys->setAttr<ATTR_FORCE_SBE_UPDATE>
              (l_sbe_update | SBE_UPDATE_TYPE_TOPOLOGY_CHECKS);
        }

        TRACDCOMP(g_trac_isteps_trace,
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

    TRACFCOMP(g_trac_isteps_trace,
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

        TRACFCOMP(g_trac_isteps_trace,
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
            l_sys->getAttr<ATTR_FORCE_SBE_UPDATE>();
        TRACFCOMP(g_trac_isteps_trace,
            "updateProcessorSbeSeeproms needed check_hrmor_within_range, "
            "will set ATTR_FORCE_SBE_UPDATE l_sbe_update=0x%X",
            l_sbe_update);
        l_sys->setAttr<ATTR_FORCE_SBE_UPDATE>
          (l_sbe_update | SBE_UPDATE_TYPE_HRMOR_OUTSIDE_CONFIGURED_MEM);
    }
    else
    {
        TRACFCOMP(g_trac_isteps_trace,
            "check_hrmor_within_range: SBE update is NOT required");
    }
}


/**
 * @brief Check mbox scratch regs versus MRW/Calculated via ATTR
 *        Sync attributes to SP and trigger reconfig loop if mismatch
 *
 * @param[in/out] io_istepErr  Error for this istep
 *
 */
void check_scratch_regs_vs_attrs( IStepError & io_StepError )
{
    errlHndl_t l_err = nullptr;

    Target* l_sys = UTIL::assertGetToplevelTarget();

    bool l_reconfigLoop = false;
    uint32_t l_reconfigReg = 0x0;
    uint32_t l_scratch = 0;
    uint32_t l_ipl_phase = 0;
    const auto l_scratchRegs =
            l_sys->getAttrAsStdArr<ATTR_MASTER_MBOX_SCRATCH>();
    const uint32_t SCRATCH4_MASK  = 0x08000000;
    const uint32_t SCRATCH5_MASK  = 0x04000000;
    const uint32_t SCRATCH6_MASK  = 0x02000000;
    const uint32_t SCRATCH7_MASK  = 0x01000000;
    const uint32_t SCRATCH9_MASK  = 0x00400000;
    const uint32_t SCRATCH10_MASK = 0x00200000;

    do
    {

    TargetHandle_t l_mProc(nullptr);
    l_err = targetService().queryMasterProcChipTargetHandle(l_mProc);
    if (l_err)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  "ERROR: check_scratch_regs_vs_attrs: error getting master proc");
        io_StepError.addErrorDetails(l_err);
        errlCommit( l_err, HWPF_COMP_ID );
        break;
    }

    // @todo RTC 258427 Follow-up on scratch1 and scratch2 reg checks in istep 7.5
    // --------------------------------------------------------
    // Scratch1 (CFAM 2838, SCOM 0x50038) - FW functional Cores
    // --------------------------------------------------------
    // ---------------------------------------------------------------------
    // Scratch2 (CFAM 2839, SCOM 0x50039) – FW functional Targets (non core)
    // ---------------------------------------------------------------------

    // ----------------------------------------------------------
    // Scratch3 (CFAM 283A, SCOM 0x5003A) – FW Mode/Control flags
    // ----------------------------------------------------------
    INITSERVICE::SPLESS::MboxScratch3_t l_scratch3;
    l_scratch3.data32 =
        l_scratchRegs[INITSERVICE::SPLESS::MboxScratch3_t::REG_IDX];

    // Do not compare, just copy scratch3 into ATTR_BOOT_FLAGS
    // Turn off the istep bit first
    l_scratch3.fwModeCtlFlags.istepMode = 0;
    l_sys->setAttr<ATTR_BOOT_FLAGS>(l_scratch3.data32);

    // Override warning info messages
    TRACFCOMP(g_trac_isteps_trace, "ATTR_BOOT_FLAGS=%.8X", l_scratch3.data32);
    if(l_scratch3.fwModeCtlFlags.overrideSecurity)
    {
        TRACFCOMP(g_trac_isteps_trace, INFO_MRK
            "WARNING: Requesting security disable on non-master processors.");
    }
    if(l_scratch3.fwModeCtlFlags.allowAttrOverrides)
    {
        TRACFCOMP(g_trac_isteps_trace, INFO_MRK
            "WARNING: Requesting allowing Attribute Overrides on "
            "non-master processors even if secure mode.");
    }

    // ---------------------------------------------------
    // Scratch4 (CFAM 283B, SCOM 0x5003B) – Nest/Boot Freq
    // ---------------------------------------------------
    INITSERVICE::SPLESS::MboxScratch4_t l_scratch4;
    l_scratch4.data32 =
        l_scratchRegs[INITSERVICE::SPLESS::MboxScratch4_t::REG_IDX];

    // Compare 0:15 to ATTR_SPI_BUS_DIV_REF
    l_scratch = l_scratch4.nestBootFreq.refSpiBusDivider.value;
    const auto l_attr_spi_bus_div =
                        l_mProc->getAttr<ATTR_SPI_BUS_DIV_REF>();
    if (l_scratch != l_attr_spi_bus_div)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH4_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch4 refSpiBusDivider 0x%.4X ATTR_SPI_BUS_DIV_REF 0x%.4X",
            l_scratch, l_attr_spi_bus_div);
    }

    // Compare 16:31 to ATTR_FREQ_CORE_BOOT_MHZ
    l_scratch = l_scratch4.nestBootFreq.coreBootFreqMhz;
    const auto l_attr_core_boot_freq =
                        l_mProc->getAttr<ATTR_FREQ_CORE_BOOT_MHZ>();
    if (l_scratch != l_attr_core_boot_freq)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH4_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch4 coreBootFreqMhz 0x%.4X ATTR_FREQ_CORE_BOOT_MHZ 0x%.4X",
            l_scratch, l_attr_core_boot_freq);
    }

    // -------------------------------------------------------
    // Scratch5 (CFAM 283C, SCOM 0x5003C) –  HWP Control Flags
    // -------------------------------------------------------
    INITSERVICE::SPLESS::MboxScratch5_t l_scratch5;
    l_scratch5.data32 =
        l_scratchRegs[INITSERVICE::SPLESS::MboxScratch5_t::REG_IDX];

    // Save ipl phase to use later
    l_ipl_phase = l_scratch5.hwpCtlFlags.systemIplPhase;

    // Compare bit 3 to ATTR_DISABLE_HBBL_VECTORS
    l_scratch = l_scratch5.hwpCtlFlags.disableHbblVectors;
    const auto l_attr_disable_hbbl_vectors =
                        l_sys->getAttr<ATTR_DISABLE_HBBL_VECTORS>();
    if (l_scratch != l_attr_disable_hbbl_vectors)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH5_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch5 disableHbblVectors 0x%X ATTR_DISABLE_HBBL_VECTORS 0x%X",
            l_scratch, l_attr_disable_hbbl_vectors);
    }

    // Compare 4:6 to ATTR_SBE_SELECT_EX_POLICY
    l_scratch = l_scratch5.hwpCtlFlags.sbeSelectExPolicy;
    const auto l_attr_sbe_select_ex =
                        l_sys->getAttr<ATTR_SBE_SELECT_EX_POLICY>();
    if (l_scratch != l_attr_sbe_select_ex)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH5_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch5 sbeSelectExPolicy 0x%X ATTR_SBE_SELECT_EX_POLICY 0x%X",
            l_scratch, l_attr_sbe_select_ex);
    }

    // ----------------------------------------------------------------------
    // Scratch6 (CFAM 283D, SCOM 0x5003D) – Master/Slave, node/chip selection
    // ----------------------------------------------------------------------
    INITSERVICE::SPLESS::MboxScratch6_t l_scratch6;
    l_scratch6.data32 =
        l_scratchRegs[INITSERVICE::SPLESS::MboxScratch6_t::REG_IDX];

    // Compare bit 8 to ATTR_CP_PLLTODFLT_BYPASS
    l_scratch = l_scratch6.masterSlaveNodeChipSel.forceTodFilterPllBypass;
    const auto l_attr_cp_plltodflt =
                        l_mProc->getAttr<ATTR_CP_PLLTODFLT_BYPASS>();
    if (l_scratch != l_attr_cp_plltodflt)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 forceTodFilterPllBypass 0x%X ATTR_CP_PLLTODFLT_BYPASS 0x%X",
            l_scratch, l_attr_cp_plltodflt);
    }

    // Compare bit 9 to ATTR_CP_PLLNESTFLT_BYPASS
    l_scratch = l_scratch6.masterSlaveNodeChipSel.forceNestFilterPllBypass;
    const auto l_attr_cp_pllnestflt =
                        l_mProc->getAttr<ATTR_CP_PLLNESTFLT_BYPASS>();
    if (l_scratch != l_attr_cp_pllnestflt)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 forceNestFilterPllBypass 0x%X ATTR_CP_PLLNESTFLT_BYPASS 0x%X",
            l_scratch, l_attr_cp_pllnestflt);
    }

    // Compare bit 10 to ATTR_CP_PLLIOFLT_BYPASS
    l_scratch = l_scratch6.masterSlaveNodeChipSel.forceIoFilterPllBypass;
    const auto l_attr_cp_pllioflt =
                        l_mProc->getAttr<ATTR_CP_PLLIOFLT_BYPASS>();
    if (l_scratch != l_attr_cp_pllioflt)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 forceIoFilterPllBypass 0x%X ATTR_CP_PLLIOFLT_BYPASS 0x%X",
            l_scratch, l_attr_cp_pllioflt);
    }

    // Compare bit 11 to ATTR_CP_PLLIOSSFLT_BYPASS
    l_scratch = l_scratch6.masterSlaveNodeChipSel.forceIoSpreadSpectrumPllBypass;
    const auto l_attr_cp_plliossflt =
                        l_mProc->getAttr<ATTR_CP_PLLIOSSFLT_BYPASS>();
    if (l_scratch != l_attr_cp_plliossflt)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 forceIoSpreadSpectrumPllBypass 0x%X ATTR_CP_PLLIOSSFLT_BYPASS 0x%X",
            l_scratch, l_attr_cp_plliossflt);
    }

    // Compare bit 12 to ATTR_NEST_DPLL_BYPASS
    l_scratch = l_scratch6.masterSlaveNodeChipSel.forceNestDpllBypass;
    const auto l_attr_nest_dpll =
                        l_mProc->getAttr<ATTR_NEST_DPLL_BYPASS>();
    if (l_scratch != l_attr_nest_dpll)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 forceNestDpllBypass 0x%X ATTR_NEST_DPLL_BYPASS 0x%X",
            l_scratch, l_attr_nest_dpll);
    }

    // Compare bit 13 to ATTR_PAU_DPLL_BYPASS
    l_scratch = l_scratch6.masterSlaveNodeChipSel.forcePauDpllBypass;
    const auto l_attr_pau_dpll =
                        l_mProc->getAttr<ATTR_PAU_DPLL_BYPASS>();
    if (l_scratch != l_attr_pau_dpll)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 forcePauDpllBypass 0x%X ATTR_PAU_DPLL_BYPASS 0x%X",
            l_scratch, l_attr_pau_dpll);
    }

    // Compare bit 14 to ATTR_IO_TANK_PLL_BYPASS
    l_scratch = l_scratch6.masterSlaveNodeChipSel.forceAllIohsOmiPcieBypass;
    const auto l_attr_io_tank_pll =
                        l_mProc->getAttr<ATTR_IO_TANK_PLL_BYPASS>();
    if (l_scratch != l_attr_io_tank_pll)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 forceAllIohsOmiPcieBypass 0x%X ATTR_IO_TANK_PLL_BYPASS 0x%X",
            l_scratch, l_attr_io_tank_pll);
    }

    // Compare 16:19 to ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID
    l_scratch = l_scratch6.masterSlaveNodeChipSel.fabricEffTopologyId;
    const auto l_attr_fabric_eff_topo_id =
                        l_mProc->getAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>();
    if (l_scratch != l_attr_fabric_eff_topo_id)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 fabricEffTopologyId 0x%X ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID 0x%X",
            l_scratch, l_attr_fabric_eff_topo_id);
    }

    // Compare bit 20 to ATTR_PROC_FABRIC_TOPOLOGY_MODE
    l_scratch = l_scratch6.masterSlaveNodeChipSel.fabricTopologyMode;
    const auto l_attr_fabric_topo_mode =
                        l_sys->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_MODE>();
    if (l_scratch != l_attr_fabric_topo_mode)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 fabricTopologyMode 0x%X ATTR_PROC_FABRIC_TOPOLOGY_MODE 0x%X",
            l_scratch, l_attr_fabric_topo_mode);
    }

    // Compare 22:23 to ATTR_PROC_FABRIC_BROADCAST_MODE
    l_scratch = l_scratch6.masterSlaveNodeChipSel.fabricBroadcastMode;
    const auto l_attr_fabric_broadcast_mode =
                        l_sys->getAttr<ATTR_PROC_FABRIC_BROADCAST_MODE>();
    if (l_scratch != l_attr_fabric_broadcast_mode)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 fabricBroadcastMode 0x%X ATTR_PROC_FABRIC_BROADCAST_MODE 0x%X",
            l_scratch, l_attr_fabric_broadcast_mode);
    }

    // Compare bit 24 to ATTR_PROC_SBE_MASTER_CHIP
    l_scratch = l_scratch6.masterSlaveNodeChipSel.isMaster;
    const auto l_attr_proc_sbe_master =
                        l_mProc->getAttr<ATTR_PROC_SBE_MASTER_CHIP>();
    if (l_scratch != l_attr_proc_sbe_master)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 isMaster 0x%X ATTR_PROC_SBE_MASTER_CHIP 0x%X",
            l_scratch, l_attr_proc_sbe_master);
    }

    // Compare 28:31 to ATTR_PROC_FABRIC_TOPOLOGY_ID
    l_scratch = l_scratch6.masterSlaveNodeChipSel.fabricTopologyId;
    const auto l_attr_fabric_topo_id =
                        l_mProc->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
    if (l_scratch != l_attr_fabric_topo_id)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH6_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch6 fabricTopologyId 0x%X ATTR_PROC_FABRIC_TOPOLOGY_ID 0x%X",
            l_scratch, l_attr_fabric_topo_id);
    }

    // -------------------------------------------------
    // Scratch7 (CFAM 283E, SCOM 0x5003E) – IOHS DL Mode
    // -------------------------------------------------
    INITSERVICE::SPLESS::MboxScratch7_t l_scratch7;
    l_scratch7.data32 =
        l_scratchRegs[INITSERVICE::SPLESS::MboxScratch7_t::REG_IDX];

    // Compare 0:31 to ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC
    // only if in chip-contained mode (ipl phase = 0b10)
    if (l_ipl_phase == MboxScratch5_t::CHIP_CONTAINED)
    {
        l_scratch = l_scratch7.activeCores.activeCoresMask;
        const auto l_attr_chip_contained_cores =
                        l_sys->getAttr<ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC>();
        if (l_scratch != l_attr_chip_contained_cores)
        {
            l_reconfigLoop = true;
            l_reconfigReg |= SCRATCH7_MASK;
            TRACFCOMP( g_trac_isteps_trace,
                "scratch7 activeCoresMask 0x%X ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC 0x%X",
                l_scratch, l_attr_chip_contained_cores);
        }
    }

    // ----------------------------------
    // Scratch8 (CFAM 283F, SCOM 0x5003F)
    // ----------------------------------
    // Valid bits

    // -------------------------------------------------
    // Scratch9 (CFAM 2980, SCOM 0x50180) – PAU, MC Freq
    // -------------------------------------------------
    INITSERVICE::SPLESS::MboxScratch9_t l_scratch9;
    l_scratch9.data32 =
        l_scratchRegs[INITSERVICE::SPLESS::MboxScratch9_t::REG_IDX];

    // Compare 0:15 to ATTR_FREQ_PAU_MHZ
    l_scratch = l_scratch9.pauMcFreq.pauPllFreqMhz;
    const auto l_attr_pau_freq =
                        l_sys->getAttr<ATTR_FREQ_PAU_MHZ>();
    if (l_scratch != l_attr_pau_freq)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH9_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch9 pauPllFreqMhz 0x%.4X ATTR_FREQ_PAU_MHZ 0x%.4X",
            l_scratch, l_attr_pau_freq);
    }

    // Create scratch bucket array to enable loop
    const uint32_t l_s9_mc_pll_bkt[] =
    {
        l_scratch9.pauMcFreq.mc0PllBucket,
        l_scratch9.pauMcFreq.mc1PllBucket,
        l_scratch9.pauMcFreq.mc2PllBucket,
        l_scratch9.pauMcFreq.mc3PllBucket,
    };

    // Get ATTR_MC_PLL_BUCKET array
    const auto l_attr_mc_pll_bkt =
                        l_mProc->getAttrAsStdArr<ATTR_MC_PLL_BUCKET>();

    for (uint32_t l_bkt = 0; l_bkt < l_attr_mc_pll_bkt.size(); l_bkt++)
    {
        // Compare scratch9 mc pll bucket[] to ATTR_MC_PLL_BUCKET[]
        if (l_s9_mc_pll_bkt[l_bkt] != l_attr_mc_pll_bkt[l_bkt])
        {
            l_reconfigLoop = true;
            l_reconfigReg |= SCRATCH9_MASK;
            TRACFCOMP( g_trac_isteps_trace,
                "scratch9 mcPllBucket[%d] 0x%X != ATTR_MC_PLL_BUCKET[%d] 0x%X",
                l_bkt,l_s9_mc_pll_bkt[l_bkt],
                l_bkt,l_attr_mc_pll_bkt[l_bkt]);
        }
    }

    // Compare 28:31 to ATTR_NDL_MESHCTRL_SETUP
    l_scratch = l_scratch9.pauMcFreq.ndlMeshCtlSetup;
    const auto l_attr_ndl_meshctrl =
                        l_mProc->getAttr<ATTR_NDL_MESHCTRL_SETUP>();
    if (l_scratch != l_attr_ndl_meshctrl)
    {
        l_reconfigLoop = true;
        l_reconfigReg |= SCRATCH9_MASK;
        TRACFCOMP( g_trac_isteps_trace,
            "scratch9 ndlMeshCtlSetup 0x%X ATTR_NDL_MESHCTRL_SETUP 0x%X",
            l_scratch, l_attr_ndl_meshctrl);
    }

    // ----------------------------------------------
    // Scratch10 (CFAM 2981, SCOM 0x50181) – IOHS PLL
    // ----------------------------------------------
    INITSERVICE::SPLESS::MboxScratch10_t l_scratch10;
    l_scratch10.data32 =
        l_scratchRegs[INITSERVICE::SPLESS::MboxScratch10_t::REG_IDX];

    // Compare 0:31 to ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC
    // only if in chip-contained mode (ipl phase = 0b10)
    if (l_ipl_phase == MboxScratch5_t::CHIP_CONTAINED)
    {
        l_scratch = l_scratch10.chipCaches.backingCachesMask;
        const auto l_attr_chip_contained_caches =
                    l_mProc->getAttr<ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC>();
        if (l_scratch != l_attr_chip_contained_caches)
        {
            l_reconfigLoop = true;
            l_reconfigReg |= SCRATCH10_MASK;
            TRACFCOMP( g_trac_isteps_trace,
                "scratch10 backingCachesMask 0x%X ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC 0x%X",
                l_scratch, l_attr_chip_contained_caches);
        }
    }
    // Compare 0:31 to ATTR_IOHS_PLL_BUCKET
    else
    {
        // Create array to enable loop
        const uint32_t l_s10_iohs_pll_bkt[] =
        {
            l_scratch10.iohsPll.iohs0PllBucket,
            l_scratch10.iohsPll.iohs1PllBucket,
            l_scratch10.iohsPll.iohs2PllBucket,
            l_scratch10.iohsPll.iohs3PllBucket,
            l_scratch10.iohsPll.iohs4PllBucket,
            l_scratch10.iohsPll.iohs5PllBucket,
            l_scratch10.iohsPll.iohs6PllBucket,
            l_scratch10.iohsPll.iohs7PllBucket,
        };

        // Get ATTR_IOHS_PLL_BUCKET array
        const auto l_attr_iohs_pll_bkt =
                    l_mProc->getAttrAsStdArr<ATTR_IOHS_PLL_BUCKET>();

        for (uint32_t l_bkt = 0; l_bkt < l_attr_iohs_pll_bkt.size(); l_bkt++)
        {
            // Compare scratch10 iohs pll bucket[] to ATTR_IOHS_PLL_BUCKET[]
            if (l_s10_iohs_pll_bkt[l_bkt] != l_attr_iohs_pll_bkt[l_bkt])
            {
                l_reconfigLoop = true;
                l_reconfigReg |= SCRATCH10_MASK;
                TRACFCOMP( g_trac_isteps_trace,
                    "scratch10 iohsPllBucket[%d] 0x%X != ATTR_IOHS_PLL_BUCKET[%d] 0x%X",
                    l_bkt,l_s10_iohs_pll_bkt[l_bkt],
                    l_bkt,l_attr_iohs_pll_bkt[l_bkt]);
            }
        }
    }

    // If we had a scratch/attribute mismatch do reconfig loop
    // which will also sync attributes to the SP
    if (l_reconfigLoop)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  "check_scratch_regs_vs_attrs scratch/attribute mismatch, "
                  "bitwise failing scratch reg: 0x%.8X "
                  "triggering reconfig loop", l_reconfigReg);

        /*@
         * @errortype
         * @moduleid          MOD_CALL_MSS_ATTR_UPDATE
         * @reasoncode        RC_SCRATCH_REG_ATTR_MISMATCH
         * @userdata1         Bitwise scratch register miscompare
         * @userdata2         0
         * @devdesc           Scratch reg / attribute mismatch
         * @custdesc          Firmware detected a problem during boot
         */
        l_err = new ErrlEntry( ERRL_SEV_INFORMATIONAL,
                               MOD_CALL_MSS_ATTR_UPDATE,
                               RC_SCRATCH_REG_ATTR_MISMATCH,
                               l_reconfigReg,
                               0,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_err->collectTrace("ISTEPS_TRACE");
        errlCommit(l_err, HWPF_COMP_ID);

        INITSERVICE::doShutdown(INITSERVICE::SHUTDOWN_DO_RECONFIG_LOOP);
    }

    } while(0);
}


//
//  Wrapper function to call mss_attr_update
//
void*    call_mss_attr_update( void *io_pArgs )
{
    IStepError l_StepError;

    TRACFCOMP( g_trac_isteps_trace, "call_mss_attr_update entry");
    errlHndl_t l_err = nullptr;

    do
    {
        bool l_isPhyp = is_phyp_load();
        bool l_spEnabled = INITSERVICE::spBaseServicesEnabled();

        Target* l_sys = UTIL::assertGetToplevelTarget();

        //Get the master proc
        TargetHandle_t l_mProc;
        l_err = targetService().queryMasterProcChipTargetHandle(l_mProc);
        if (l_err)
        {
            TRACFCOMP (g_trac_isteps_trace,
                    "ERROR: getting master proc");
            l_StepError.addErrorDetails(l_err);
            errlCommit( l_err, HWPF_COMP_ID );
            break;
        }

        // Check the memory on master proc chip
        // Use this mechanism for:
        // non-phyp case or
        // PHYP on OpenPower machine
        if (!l_isPhyp || (l_isPhyp && !l_spEnabled))
        {
            l_err = check_proc0_memory_config(l_StepError);

            if (l_err)
            {
                TRACFCOMP( g_trac_isteps_trace,
                           "ERROR in check_proc0_memory_config. "
                           TRACE_ERR_FMT,
                           TRACE_ERR_ARGS(l_err));

                l_StepError.addErrorDetails(l_err);
                errlCommit( l_err, HWPF_COMP_ID );
                break;
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace,
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
                TRACFCOMP(g_trac_isteps_trace,
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
                        l_sys->getAttr<ATTR_FORCE_SBE_UPDATE>();
                    TRACFCOMP(g_trac_isteps_trace,
                        "Mismatch on proc %.8X : topoId=%.8X, effTopoId=%.8X "
                        "will set ATTR_FORCE_SBE_UPDATE l_sbe_update=0x%X",
                              get_huid(l_proc), l_topoId, l_effTopoId, l_sbe_update);
                    l_sys->setAttr<ATTR_FORCE_SBE_UPDATE>
                      (l_sbe_update | SBE_UPDATE_TYPE_FABRIC_EFF_TOPOLOGY);
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

            TRACFCOMP(g_trac_isteps_trace,
                "Running p10_mss_attr_update HWP on "
                "MI target HUID %.8X", get_huid(l_miTarget));
            FAPI_INVOKE_HWP(l_err, p10_mss_attr_update, l_fapi2_mi_target);
            if(l_err)
            {
                TRACFCOMP(g_trac_isteps_trace,
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
            l_sys->getAttr<ATTR_FORCE_SBE_UPDATE>();
        TRACFCOMP(g_trac_isteps_trace, "Checking FORCE_SBE_UPDATE=0x%X",
            l_sbe_update);
        if (l_sbe_update != 0)
        {
            if (l_sys->getAttr<ATTR_IS_MPIPL_HB>() == true)
            {
                TRACFCOMP( g_trac_isteps_trace,
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
                TRACFCOMP(g_trac_isteps_trace,
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
                l_sys->setAttr<ATTR_FORCE_SBE_UPDATE>
                  (SBE_UPDATE_TYPE_CLEAR);
                if(l_err)
                {
                    TRACFCOMP(g_trac_isteps_trace,
                              "ERROR: updateProcessorSbeSeeproms");
                    l_err->collectTrace("ISTEPS_TRACE");
                    captureError(l_err, l_StepError, HWPF_COMP_ID);
                }
                else
                {
                    TRACFCOMP(g_trac_isteps_trace,
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
                    l_err = new ErrlEntry(
                                    ERRL_SEV_UNRECOVERABLE,
                                    MOD_CALL_MSS_ATTR_UPDATE,
                                    RC_SBE_UPDATE_UNEXPECTEDLY_FAILED,
                                    l_sys->getAttr<ATTR_FORCE_SBE_UPDATE>(),
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
            TRACFCOMP(g_trac_isteps_trace,
                      "ATTR_FORCE_SBE_UPDATE -NOT- "
                      "set to call updateProcessorSbeSeeproms,"
                      " skipped calling updateProcessSbeSeeproms");
        }

        // Set PLL BUCKET attributes
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
        l_fapi2_proc_target (l_mProc);

        TRACFCOMP(g_trac_isteps_trace,
                  "Running p10_sbe_scratch_regs_set_pll_buckets HWP on processor target %.8X",
                  get_huid(l_mProc));

        FAPI_INVOKE_HWP(l_err,
                        p10_sbe_scratch_regs_set_pll_buckets,
                        l_fapi2_proc_target);
        if(l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                "ERROR in p10_sbe_scratch_regs_set_pll_buckets HWP "
                "for HUID %.8x. "
                TRACE_ERR_FMT,
                get_huid(l_mProc),
                TRACE_ERR_ARGS(l_err));
            l_StepError.addErrorDetails(l_err);
            errlCommit( l_err, HWPF_COMP_ID );
        }

        // Compare the SBE scratch regs to attributes
        check_scratch_regs_vs_attrs(l_StepError);

    } while (0);

    TRACFCOMP( g_trac_isteps_trace, "call_mss_attr_update exit" );

    return l_StepError.getErrorHandle();
}

};   // end namespace
