/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/targetservicestart.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
/* [+] Google Inc.                                                        */
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
 *  @file targeting/targetservicestart.C
 *
 *  @brief Hostboot entry point for target service
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



// Other components
#include <kernel/console.H>
#include <sys/misc.h>
#include <sys/mm.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <arch/ppc.H>
#include <targeting/common/trace.H>
#include <targeting/adapters/assertadapter.H>
#include <targeting/adapters/types.H>
#include <initservice/taskargs.H>
#include <util/utilmbox_scratch.H>
#include <util/align.H>

// This component
#include <targeting/common/targetservice.H>
#include <targeting/attrrp.H>
#include <targeting/targplatutil.H>
#include <targeting/common/mfgFlagAccessors.H>

// Others
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <initservice/initserviceif.H>
#include <util/misc.H>
#include <util/utilrsvdmem.H>
#include <kernel/bltohbdatamgr.H>
#include <map>
#include <arch/pirformat.H>
#include <lpc/lpcif.H>
#include <xscom/xscomif.H>
#include <bootloader/bootloaderif.H>
#include <sbeio/sbeioif.H>
#include <sys/mm.h>
#include "../runtime/hdatstructs.H"
#include <console/consoleif.H>

#include <targeting/common/associationmanager.H>

using namespace INITSERVICE::SPLESS;
using namespace MEMMAP;
//******************************************************************************
// targetService
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"

#define TARG_LOC TARG_NAMESPACE TARG_CLASS TARG_FN ": "

//******************************************************************************
// _start
//******************************************************************************

#define TARG_CLASS ""

/*
 * @brief Initialize any attributes that need to be set early on
 */
static void initializeAttributes(TargetService& i_targetService,
                                 bool i_isMpipl,
                                 bool i_istepMode,
                                 const ATTR_MASTER_MBOX_SCRATCH_typeStdArr& i_masterScratch);

/**
 *  @brief Check that at least one processor of our cpu type is being targeted
 */
static void checkProcessorTargeting(TargetService& i_targetService);

/**
 *  @brief Compute any values that might change based on a remap of memory
 *  @param[in]  Pointer to targeting service
 */
static void adjustMemoryMap(TargetService& i_targetService);

/**
 *  @brief Entry point for initialization service to initialize the targeting
 *      code
 *
 *  @param[in] io_pError
 *      Error log handle; returns NULL on success, !NULL otherwise
 *
 *  @note: Link register is configured to automatically invoke task_end() when
 *      this routine returns
 */
static void initTargeting(errlHndl_t& io_pError)
{
    #define TARG_FN "initTargeting(errlHndl_t& io_pError)"

    TARG_ENTER();

    //Need to stash away the master mbox regs as they will
    //be overwritten
    bool l_isMpipl = false;
    bool l_isIstepMode = false;
    const auto l_scratch = Util::readScratchRegs();

    // Check mbox scratch reg 3 for IPL boot options
    // Specifically istep mode (bit 0) and MPIPL (bit 2)
    INITSERVICE::SPLESS::MboxScratch3_t l_scratch3;
    l_scratch3.data32 = l_scratch[INITSERVICE::SPLESS::MboxScratch3_t::REG_IDX];

    if(l_scratch3.fwModeCtlFlags.isMpipl)
    {
        TARG_INF("We are running MPIPL mode");
        printk( "Boot is MPIPL.\n" );
        CONSOLE::displayf(CONSOLE::DEFAULT,  NULL,"Boot is MPIPL." );
        CONSOLE::flush();
        l_isMpipl = true;
    }
    if(l_scratch3.fwModeCtlFlags.istepMode)
    {
        l_isIstepMode = true;
    }
    if(l_scratch3.fwModeCtlFlags.overrideSecurity)
    {
        TARG_INF("WARNING: External tool asked master proc to disable "
            "security.");
    }
    if(l_scratch3.fwModeCtlFlags.allowAttrOverrides)
    {
        TARG_INF("WARNING: External tool asked master proc to allow "
            "attribute overrides even in secure mode.");
    }

    AttrRP::init(io_pError, l_isMpipl);

    if (io_pError == NULL)
    {
        TargetService& l_targetService = targetService();
        (void)l_targetService.init();

        if(l_isMpipl)
        {
            // Open the permissions to be able to reset the links between
            // sys <-> nodeN established during runtime.
            io_pError = l_targetService.modifyReadOnlyPagePermissions(true);
            if(io_pError)
            {
                auto l_eid = io_pError->eid();
                errlCommit(io_pError, TARG_COMP_ID);
                INITSERVICE::doShutdown(l_eid, true);
            }

            io_pError = TARGETING::AssociationManager::
                                                    reconnectSyAndNodeTargets();
            if(io_pError)
            {
                auto l_eid = io_pError->eid();
                errlCommit(io_pError, TARG_COMP_ID);
                INITSERVICE::doShutdown(l_eid,  true);
            }
        }

        initializeAttributes(l_targetService, l_isMpipl, l_isIstepMode,
                             l_scratch);


        uint32_t l_peerTargetsAdjusted = 0;
        uint32_t l_numberMutexAttrsReset = 0;

        if(l_isMpipl)
        {


            for( auto targ_iter = l_targetService.begin();
                 targ_iter != l_targetService.end();
                 targ_iter++)
            {
                const Target* l_pTarget = *targ_iter;

                // Ensure all mutex attributes are setup correctly for MPIPL
                // Check if there any mutex attributes
                // we need to reset on this target
                l_numberMutexAttrsReset +=
                    l_targetService.resetMutexAttributes(l_pTarget);

                // Update any peer target addresses if necessary
                // updatePeerTargets will write to read-only attribute pages.
                // To get around vmm fails we need to allow writes to readonly
                // memory for the duration of this loop (unlocking is done
                // above).
                if(l_targetService.updatePeerTarget(l_pTarget))
                {
                    l_peerTargetsAdjusted++;
                }
            }

            // Now that the loop is complete we can re-apply
            // the read only permissions to the read only attr pages
            l_targetService.modifyReadOnlyPagePermissions(false);
            TARG_INF("Number of peer target addresses adjusted: %d",
                     l_peerTargetsAdjusted);
            TARG_INF("Number of mutex attributes reset: %d",
                     l_numberMutexAttrsReset);
        }
        else
        {

            for( auto targ_iter = l_targetService.begin();
                 targ_iter != l_targetService.end();
                 targ_iter++)
            {
                const Target* l_pTarget = *targ_iter;

                // Ensure all mutex attributes are setup correctly for IPL
                // Recursive Mutexes need to be setup since they are defaulted
                // to all zero.
                // Check if there any mutex attributes
                // we need to reset on this target
                l_targetService.resetMutexAttributes(l_pTarget);
            }
        }


        checkProcessorTargeting(l_targetService);

        // Print out top-level model value from loaded targeting values.
        // @TODO RTC:88056 Make the model printed more meaniful
        Target* l_pTopLevel = NULL;
        l_targetService.getTopLevelTarget(l_pTopLevel);
        ATTR_MODEL_type l_model = MODEL_NA;
        if (l_pTopLevel->tryGetAttr<ATTR_MODEL>(l_model)) {
            TARG_INF("Initialized targeting for model: %s",
                     l_pTopLevel->getAttrAsString<ATTR_MODEL>());
        }

        // Handle possibility of Attribute Overrides allowed in secure mode
        bool l_allow_attr_overrides =
            g_BlToHbDataManager.getAllowAttrOverrides();
        if (l_allow_attr_overrides)
        {
            TARG_INF("Allow Attribute Overrides In Secure Mode: %d",
                l_allow_attr_overrides);
            l_pTopLevel->setAttr<
                TARGETING::ATTR_ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE>(
                    l_allow_attr_overrides);
        }
        else
        {
            // Hardcode to zero to be safe
            l_pTopLevel->setAttr<
                TARGETING::ATTR_ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE>(0x0);
        }

// No error module loaded in VPO to save load time
#ifndef CONFIG_VPO_COMPILE
        // call ErrlManager function - tell him that TARG is ready!
        ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::TARG);
#endif

        // set global that TARG is ready
        Util::setIsTargetingLoaded();
    }

    TARG_EXIT();

#undef TARG_FN
}

/**
 *  @brief Create _start entry point using task entry macro and vector to
 *      initTargeting function
 */
TASK_ENTRY_MACRO(initTargeting);


/**
 *  @brief Check that at least one processor of our cpu type is being targeted
 */
static void checkProcessorTargeting(TargetService& i_targetService)
{
    #define TARG_FN "checkProcessorTargeting()"
    TARG_ENTER();

    PredicateCTM l_procChip(CLASS_CHIP,TYPE_PROC);
    ProcessorCoreType l_coreType = cpu_core_type();
    bool l_haveOneCorrectProcessor = false;
    TargetRangeFilter l_filter(
        i_targetService.begin(),
        i_targetService.end(),
        &l_procChip);

    for(;l_filter && (l_haveOneCorrectProcessor != true);++l_filter)
    {
        switch(l_filter->getAttr<ATTR_MODEL>())
        {
            case MODEL_POWER10:
                if(l_coreType == CORE_POWER10)
                {
                    l_haveOneCorrectProcessor = true;
                }
                break;
            default:
                break;
        };
    }

    TARG_ASSERT((l_haveOneCorrectProcessor == true), TARG_ERR_LOC "FATAL: No "
                "targeted processors are of the correct type");

    TARG_EXIT();

    #undef TARG_FN
}

/* @brief Set the CP_REFCLOCK_SELECT attribute on the given processor using the
 *        value in SBE Mailbox Scratch Register 6 (used by p10_clock_test).
 *
 * @param[in] i_proc  The processor to operate on
 * @param[in] i_regs  The boot processor's SBE mailbox scratch registers
 */
void set_cp_refclock_select_attribute(Target* const i_proc,
                                      const TARGETING::ATTR_MASTER_MBOX_SCRATCH_typeStdArr& i_regs)
{
    INITSERVICE::SPLESS::MboxScratch6_t scratch { };
    scratch.data32 = i_regs[scratch.REG_IDX];
    i_proc->setAttr<ATTR_CP_REFCLOCK_SELECT>(scratch.masterSlaveNodeChipSel.cp_refclock_select);
}

/*
 * @brief Initialize any attributes that need to be set early on
 */
static void initializeAttributes(TargetService& i_targetService,
                                 bool i_isMpipl,
                                 bool i_istepMode,
                                 const ATTR_MASTER_MBOX_SCRATCH_typeStdArr& i_masterScratch)
{
    #define TARG_FN "initializeAttributes()...)"
    TARG_ENTER();

    Target* l_pTopLevel = NULL;

    TargetHandleList l_chips;

    // Setup new TPM SPI Settings passed in via MboxScratch13_t below if that register
    // is valid based on MboxScratch8_t
    INITSERVICE::SPLESS::MboxScratch8_t l_scratch8;
    l_scratch8.data32 = i_masterScratch[INITSERVICE::SPLESS::MboxScratch8_t::REG_IDX];
    INITSERVICE::SPLESS::MboxScratch13_t l_scratch13;
    l_scratch13.data32 = i_masterScratch[INITSERVICE::SPLESS::MboxScratch13_t::REG_IDX];
    uint16_t l_updated_tpm_spi_attr = 0;
    if (l_scratch8.scratchRegValid.validReg13 != 0)
    {
        // Set TPM SPI Attribute based on MboxScratch13_t
        l_updated_tpm_spi_attr = l_scratch13.TPM_SPI_BUS_DIVIDER_SETTINGS.dividerAndDelay.value;
    }

    i_targetService.getTopLevelTarget(l_pTopLevel);
    if(l_pTopLevel)
    {
        //Set SKIP_WAKEUP to true until all cores  are powered on (16.2)
        //If this is not set to true, PM_RESET , which is called between
        //now and istep 16.2 in various configurations and IPL flows will attempt
        //to enable special wakeup on cores that are not yet powered
        l_pTopLevel->setAttr<ATTR_SKIP_WAKEUP>(1);

        Target* l_pMasterProcChip = NULL;
        i_targetService.masterProcChipTargetHandle(l_pMasterProcChip);

        if(l_pMasterProcChip)
        {
            // Master uses xscom by default, needs to be set before
            // doing any other scom accesses
            ScomSwitches l_switches =
              l_pMasterProcChip->getAttr<ATTR_SCOM_SWITCHES>();
            l_switches.useXscom = 1;
            l_switches.useFsiScom = 0;
            l_switches.useSbeScom = 0;
            l_pMasterProcChip->setAttr<ATTR_SCOM_SWITCHES>(l_switches);


            // Master can only use Host I2C so needs to be set before
            // doing any I2C accesses
            I2cSwitches l_i2c_switches =
              l_pMasterProcChip->getAttr<ATTR_I2C_SWITCHES>();
            l_i2c_switches.useHostI2C = 1;
            l_i2c_switches.useFsiI2C  = 0;
            l_pMasterProcChip->setAttr<ATTR_I2C_SWITCHES>(l_i2c_switches);

            l_pMasterProcChip->setAttr<ATTR_PROC_SBE_MASTER_CHIP>(1);

            // Master has SBE started
            l_pMasterProcChip->setAttr<ATTR_SBE_IS_STARTED>(1);


            l_pTopLevel->setAttrFromStdArr<ATTR_MASTER_MBOX_SCRATCH>(i_masterScratch);

            // Targeting data defaults to non istep, only turn "on" if bit
            // is set so we don't tromp default setting
            if (i_istepMode)
            {
                l_pTopLevel->setAttr<ATTR_ISTEP_MODE>(1);
            }
            else
            {
                l_pTopLevel->setAttr<ATTR_ISTEP_MODE>(0);
            }

            //Set the SBE Console enablement based on our console enablement
            ATTR_LPC_CONSOLE_CNFG_type l_console = LPC_CONSOLE_CNFG_ENABLE;
#ifndef CONFIG_CONSOLE
            l_console = LPC_CONSOLE_CNFG_DISABLE;
#endif
            l_pMasterProcChip->setAttr<ATTR_LPC_CONSOLE_CNFG>(l_console);

            // Set TPM SPI Attribute based on MboxScratch13_t
            if (l_updated_tpm_spi_attr != 0)
            {
                auto orig_attr = l_pMasterProcChip->getAttr<ATTR_TPM_SPI_BUS_DIV>();
                TARG_INF("For boot proc=0x%.8X updating ATTR_TPM_SPI_BUS_DIV based on "
                         "ScratchReg8=0x%.8X and ScratchReg13=0x%.8X from 0x%.4X to 0x%.4X",
                         get_huid(l_pMasterProcChip), l_scratch8.data32, l_scratch13.data32,
                         orig_attr, l_updated_tpm_spi_attr);

                l_pMasterProcChip->setAttr<ATTR_TPM_SPI_BUS_DIV>(l_updated_tpm_spi_attr);
            }

        } // end of l_pMasterProcChip

        // Loop around all processors
        TargetHandleList l_allProcChips;
        getAllChips(l_allProcChips, TYPE_PROC, false);
        for(auto l_chip : l_allProcChips)
        {
            if (!INITSERVICE::spBaseServicesEnabled())
            {
                // The FSP will already have set this attribute on enterprise systems,
                // so we only do this calculation on eBMC-based systems.
                set_cp_refclock_select_attribute(l_chip, i_masterScratch);
            }

            // value for master set above
            if( l_chip == l_pMasterProcChip )
            {
                continue;
            }

            //Turn the SBE Console enablement off for all slave chips
            ATTR_LPC_CONSOLE_CNFG_type l_consoleOff = LPC_CONSOLE_CNFG_DISABLE;
            l_chip->setAttr<ATTR_LPC_CONSOLE_CNFG>(l_consoleOff);

            // Set TPM SPI Attribute based on MboxScratch13_t
            if (l_updated_tpm_spi_attr != 0)
            {
                auto orig_attr = l_chip->getAttr<ATTR_TPM_SPI_BUS_DIV>();
                TARG_INF("For secondary proc=0x%.8X updating ATTR_TPM_SPI_BUS_DIV based on "
                         "ScratchReg8=0x%.8X and ScratchReg13=0x%.8X from 0x%.4X to 0x%.4X",
                         get_huid(l_chip), l_scratch8.data32, l_scratch13.data32,
                         orig_attr, l_updated_tpm_spi_attr);

                l_chip->setAttr<ATTR_TPM_SPI_BUS_DIV>(l_updated_tpm_spi_attr);
            }
        }


        // Do some special memory-preserving work
        if(i_isMpipl)
        {
            l_pTopLevel->setAttr<ATTR_IS_MPIPL_HB>(1);
            l_pTopLevel->setAttr<ATTR_EXTEND_TPM_MEAS_TO_OTHER_NODES>(0);

            printk("Hostboot is performing a memory-preserving IPL (MPIPL).\n");

            //Clear out some attributes that could have stale data
            l_pTopLevel->setAttr<ATTR_HB_RSV_MEM_NEXT_SECTION>(0);
            l_pTopLevel->setAttr<ATTR_ATTN_CHK_ALL_PROCS>(1);
            l_pTopLevel->setAttr<ATTR_HALT_ON_BMC_PLDM_RESET>(0);

            //Clear out PM MALF and FFDC enabled attributes
            l_pTopLevel->setAttr<ATTR_PM_MALF_ALERT_ENABLE> (0x0);
            l_pTopLevel->setAttr<ATTR_PM_RESET_FFDC_ENABLE> (0x0);

            //Set this back to its default of zero (PM_COMPLEX_LOAD_TYPE_LOAD)
            l_pTopLevel->setAttr<ATTR_PM_COMPLEX_LOAD_REQ>(0);

            //Assemble list of functional procs and zero out virtual address values
            //to ensure they get set again this IPL
            TARGETING::PredicateCTM l_chipFilter(CLASS_CHIP, TYPE_PROC);
            TARGETING::PredicateIsFunctional l_functional;
            TARGETING::PredicatePostfixExpr l_functionalChips;
            l_functionalChips.push(&l_chipFilter).push(&l_functional).And();

            i_targetService.getAssociated( l_chips,
                                        l_pTopLevel,
                                        TargetService::CHILD_BY_AFFINITY,
                                        TARGETING::TargetService::ALL,
                                        &l_functionalChips);

            for (auto & l_chip : l_chips)
            {
                l_chip->setAttr<ATTR_XSCOM_VIRTUAL_ADDR>(0);
                l_chip->setAttr<ATTR_HOMER_VIRT_ADDR>(0);
                l_chip->setAttr<ATTR_HB_INITIATED_PM_RESET>
                  (HB_INITIATED_PM_RESET_INACTIVE);
                l_chip->setAttr<ATTR_SBE_COMPROMISED_EID>(0);
                l_chip->setAttr<ATTR_LOGGED_FAIL_GETTING_OVERRIDE_WOF_TABLE>(0);

                // clear the NVDIMM arming status so it gets redone when OCC is active
                ATTR_NVDIMM_ARMED_type l_nvdimms_armed_state =
                                        l_chip->getAttr<ATTR_NVDIMM_ARMED>();
                // Only force rearming (error setting should persist)
                l_nvdimms_armed_state.armed = 0;
                l_chip->setAttr<ATTR_NVDIMM_ARMED>(l_nvdimms_armed_state);

                if (l_chip == l_pMasterProcChip)
                {
                    // Need to set PROC_MASTER_TYPE to reflect the
                    //  current acting master
                    l_chip->setAttr<ATTR_PROC_MASTER_TYPE>(PROC_MASTER_TYPE_ACTING_MASTER);
                }
                else
                {
                    // If an different proc chip was previously the master
                    //  (we assume this because the PROC_MASTER_TYPE
                    //  attribute says so) we should change the attribute
                    //  to indicate it could be the master again in the future
                    if (l_chip->getAttr<ATTR_PROC_MASTER_TYPE>()
                                      == PROC_MASTER_TYPE_ACTING_MASTER)
                    {
                        l_chip->setAttr<ATTR_PROC_MASTER_TYPE>(PROC_MASTER_TYPE_MASTER_CANDIDATE);
                    }

                    //In certain IPL Scenarios this attribute may not get
                    // cleared properly, so clearing it for all proc chip
                    // targets that are not the master proc chip
                    l_chip->setAttr<ATTR_PROC_SBE_MASTER_CHIP>(0);
                }
            }

            //Assemble list of tpms and zero out some values
            //to ensure they get set again this IPL
            TargetHandleList l_tpms;
            TARGETING::PredicateCTM tpmFilter(CLASS_CHIP, TYPE_TPM);
            i_targetService.getAssociated(
                l_tpms,
                l_pTopLevel,
                TargetService::CHILD,
                TARGETING::TargetService::ALL,
                &tpmFilter);
            for (auto & tpm : l_tpms)
            {
                tpm->setAttr<ATTR_HB_TPM_INIT_ATTEMPTED>(0);
                tpm->setAttr<ATTR_HB_TPM_LOG_MGR_PTR>(0);
                tpm->setAttr<ATTR_TPM_POISONED>(0);
            }

            //Assemble list of membuf and zero out some virtual address attributes
            //to ensure they get set again this IPL
            TargetHandleList l_membufs;
            TARGETING::PredicateCTM membufFilter(CLASS_CHIP, TYPE_MEMBUF);
            i_targetService.getAssociated(
                l_membufs,
                l_pTopLevel,
                TargetService::CHILD,
                TARGETING::TargetService::ALL,
                &membufFilter);
            for (auto & membuf : l_membufs)
            {
                membuf->setAttr<ATTR_IBSCOM_VIRTUAL_ADDR>(0);
            }

            TARGETING::PredicateCTM l_eqFilter(CLASS_UNIT, TYPE_EQ);
            TARGETING::PredicateCTM l_exFilter(CLASS_UNIT, TYPE_EX);
            TARGETING::PredicateCTM l_ecFilter(CLASS_UNIT, TYPE_CORE);
            TARGETING::PredicatePostfixExpr l_wakeupTargFilter;
            l_wakeupTargFilter.push(&l_eqFilter).push(&l_exFilter).Or().push(&l_ecFilter).Or();
            TargetHandleList l_wakeupTargs;
            i_targetService.getAssociated( l_wakeupTargs,
                                           l_pTopLevel,
                                           TargetService::CHILD_BY_AFFINITY,
                                           TARGETING::TargetService::ALL,
                                           &l_wakeupTargFilter);
            for (auto & l_targ : l_wakeupTargs)
            {
                l_targ->setAttr<ATTR_SPCWKUP_COUNT>(0);
            }

            // HYPCOMM section is only present for master node
            if ( TARGETING::UTIL::isCurrentMasterNode() )
            {
                // Setup physical TOC address
                uint64_t l_hbdTocAddr = AttrRP::getHbDataTocAddr();

                // Variables to store information about Hostboot/Hypervisor
                // communication area
                uint64_t l_hypComm_virt_addr = 0;
                uint64_t l_hypComm_phys_addr = 0;
                uint64_t l_hypComm_size = 0;

                // Now map the TOC to find the total size of the data section
                Util::hbrtTableOfContents_t * l_toc_ptr =
                    reinterpret_cast<Util::hbrtTableOfContents_t *>(
                        mm_block_map(reinterpret_cast<void*>(l_hbdTocAddr),
                        ALIGN_PAGE(sizeof(Util::hbrtTableOfContents_t))));

                // read the TOC and look for ATTR data section
                l_hypComm_virt_addr = Util::hb_find_rsvd_mem_label(
                                                   Util::HBRT_MEM_LABEL_HYPCOMM,
                                                   l_toc_ptr,
                                                   l_hypComm_size);

                //This will tell us how far from the beginning of
                //the toc_ptr the hypComm area starts
                uint64_t l_hypComm_offset = l_hypComm_virt_addr -
                                          reinterpret_cast<uint64_t>(l_toc_ptr);

                //Use the offset found w/ virtual addresses to determine
                //the physical address of the hostboot/hypervisor comm area
                l_hypComm_phys_addr = l_hbdTocAddr + l_hypComm_offset;

                //Clear the mapped memory for the TOC,
                //it is not longer needed as we have phys ptr
                assert (0 == mm_block_unmap(reinterpret_cast<void*>(l_toc_ptr)),
                        "Failed to unmap hbData TOC");

                // The hb/hyp communcation area is at the end of the hostboot
                // data reserved mem section.
                hbHypCommArea_t * l_hbHypComm_ptr =
                    reinterpret_cast<hbHypCommArea_t *>(
                      mm_block_map(reinterpret_cast<void*>(l_hypComm_phys_addr),
                                   ALIGN_PAGE(sizeof(l_hypComm_size))));

                // Make sure the magic number and version are valid
                if( l_hbHypComm_ptr->magicNum == HYPECOMM_MAGIC_NUM &&
                    l_hbHypComm_ptr->version >= STRUCT_VERSION_FIRST )
                {
                  // if the hrmor in the comm area is non-zero then
                  // set the payload base attribute
                  if( l_hbHypComm_ptr->hrmorAddress)
                  {
                    const uint64_t THREAD_STATE_RUNNING = 0x8000000000000000ULL;
                    TARG_INF("Setting ATTR_PAYLOAD_BASE to new hrmor given by hypervisor: 0x%lx",
                              l_hbHypComm_ptr->hrmorAddress);
                    //Mask off THREAD_STATE_RUNNING bit and
                    //then divide remaining address by 1 MB
                    uint64_t l_payloadBase_MB = ( (~(THREAD_STATE_RUNNING)) &
                                      l_hbHypComm_ptr->hrmorAddress) / MEGABYTE;
                    //ATTR_PAYLOAD_BASE's is MB
                    l_pTopLevel->setAttr<ATTR_PAYLOAD_BASE>(l_payloadBase_MB);
                  }
                  else
                  {
                    TARG_INF("Using default HRMOR as hypervisor did notify us of a change in it's HRMOR on previous boot");
                  }
                }
                else
                {
                    TARG_INF("Warning!! hbHypCommArea_t's version is invalid so we cannot check if hrmor has been changed");
                }

                // Clear the mapped memory for the hbHypComm area
                assert(0 == mm_block_unmap(
                       reinterpret_cast<void*>(l_hbHypComm_ptr)),
                       "Failed to unmap hbHypComm area");
            } // end of master node only HRMOR setup
        }
        else
        {
            l_pTopLevel->setAttr<ATTR_IS_MPIPL_HB>(0);

            // TODO RTC 269891: Remove this block of code when all platforms
            // support HW VPD writes; for now, only FSP based systems have this
            // verified.
            #ifdef CONFIG_FSP_BUILD
            const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
            sys->setAttr<TARGETING::ATTR_ALLOW_EEPROM_WRITES>(true);
            #endif

            // Compute any values that might change based on a remap of memory
            adjustMemoryMap(i_targetService);

            if(!INITSERVICE::spBaseServicesEnabled())
            {
                TARGETING::Target* l_sys = NULL;
                TARGETING::targetService().getTopLevelTarget(l_sys);
                getAllChips(l_chips, TYPE_PROC, false);

                ATTR_PROC_FABRIC_PRESENT_GROUPS_type l_fabric_groups = 0;

                for(auto l_chip : l_chips)
                {
                    // Read the fabric topology id
                    const auto l_topoId =
                        l_chip->getAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>();

                    // Extract the group ID from the topology ID
                    uint8_t l_groupId = 0;
                    uint8_t l_chipId = 0;
                    extractGroupAndChip(l_topoId,
                                        l_groupId,
                                        l_chipId);


                    // Set the corresponding bit in fabric groups
                    l_fabric_groups |=
                                (1 <<
                                ((sizeof(ATTR_PROC_FABRIC_PRESENT_GROUPS_type)
                                * 8)
                                - l_groupId - 1));
                }
                l_sys->setAttr<ATTR_PROC_FABRIC_PRESENT_GROUPS>(l_fabric_groups);

                //Look at the MFG_FLAGS attribute on the system target
                //and decide if we need to update the CDM Policy attribute
                //to ignore all gards.
                if(isNoGardSet())
                {
                    TARG_INF("MNFG_NO_GARD bit is set - setting CDM_POLICIES_MANUFACTURING_DISABLED in ATTR_CDM_POLICIES");
                    TARGETING::UTIL::assertGetToplevelTarget()->setAttr<ATTR_CDM_POLICIES>(
                        l_sys->getAttr<ATTR_CDM_POLICIES>() | CDM_POLICIES_MANUFACTURING_DISABLED);
                }

            }
        }

        // Set Hostboot load address across all (intentional) processors so that
        // FSP can determine the Hostboot load address when cores are
        // winkled (since during winkle, the core scratch register holding the
        // Hostboot load address is cleared).
        TargetHandleList procs;
        const auto loadAddressBytes = cpu_spr_value(CPU_SPR_HRMOR);
        (void)getAllChips(procs, TYPE_PROC,false);
        for(auto pProc : procs)
        {
            pProc->setAttr<TARGETING::ATTR_HB_HRMOR_BYTES>(
                loadAddressBytes);
        }
    }
    else // top level is NULL - never expected
    {
        TARG_INF("Top level target is NULL");
    }

    TARG_EXIT();
    #undef TARG_FN
}

/**
 *  @brief Utility macro to swap attributes
 *  @param[in]  _attr    Attribute ID
 *  @param[in]  _master  Master proc target
 *  @param[in]  _victim  Victim proc target
 *  @param[in]  _cache   Cache of victime attributes
 */
#define SWAP_ATTRIBUTE( _attr, _master, _victim, _cache ) \
{ \
    _attr##_type l_masterVal = _master->getAttr<_attr>(); \
    _victim->setAttr<_attr>(l_masterVal); \
    TARG_INF( "%.8X>" #_attr "=%.16llX", get_huid(_victim), l_masterVal ); \
    _master->setAttr<_attr>(_cache[_attr]); \
    TARG_INF( "%.8X>" #_attr "=%.16llX", get_huid(_master), _cache[_attr] ); \
}

// Compute any values that might change based on a remap of memory
static void adjustMemoryMap( TargetService& i_targetService )
{
    // Grab the value of the BARs that SBE booted with
    uint64_t l_curXscomBAR = g_BlToHbDataManager.getXscomBAR();
    uint64_t l_curLpcBAR = g_BlToHbDataManager.getLpcBAR();
    TARG_INF( "adjustMemoryMap> xscom=%llX, lpc=%llX",
              l_curXscomBAR, l_curLpcBAR );

    // Get the master proc
    Target* l_pMasterProcChip = nullptr;
    i_targetService.masterProcChipTargetHandle(l_pMasterProcChip);
    assert(l_pMasterProcChip,"No Master Proc");

    // Save off the base (group0-chip0) value for the XSCOM BARs
    ATTR_XSCOM_BASE_ADDRESS_type l_xscomBase =
      MMIO_GROUP0_CHIP0_XSCOM_BASE_ADDR;

    // Propagate SMF but to system-level base attribute
    if(l_curXscomBAR & IS_SMF_ADDR_BIT)
    {
        l_xscomBase |= IS_SMF_ADDR_BIT;
    }
    else
    {
        l_xscomBase &= ~IS_SMF_ADDR_BIT;
    }
    Target* l_pTopLevel = TARGETING::UTIL::assertGetToplevelTarget();
    l_pTopLevel->setAttr<ATTR_XSCOM_BASE_ADDRESS>(l_xscomBase);


    ATTR_LPC_BUS_ADDR_type l_lpcBase =
      l_pTopLevel->getAttr<ATTR_LPC_BUS_ADDR>();

    // Get topology mode (same for all procs)
    const auto l_topologyMode =
        l_pTopLevel->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_MODE>();

    // Loop through all the procs to recompute all the BARs
    //  also find the victim to swap with
    Target* l_swapVictim = nullptr;
    std::map<ATTRIBUTE_ID,uint64_t> l_swapAttrs;

    TARGETING::TargetHandleList l_funcProcs;
    getAllChips(l_funcProcs, TYPE_PROC, false );

    for( auto & l_procChip : l_funcProcs )
    {
        TARG_INF( "Proc=%.8X", get_huid(l_procChip) );

        // Set effective fabric ids back to default values

        const auto l_topologyId =
            l_procChip->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();

        l_procChip->setAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>(l_topologyId);

        ATTR_XSCOM_BASE_ADDRESS_type l_xscomBAR =
            computeMemoryMapOffset(l_xscomBase, l_topologyMode, l_topologyId);

        TARG_INF( " XSCOM=%.16llX", l_xscomBAR );
        l_procChip->setAttr<ATTR_XSCOM_BASE_ADDRESS>(l_xscomBAR);

        // See if this chip's space now belongs to the master
        if( l_xscomBAR == l_curXscomBAR )
        {
            l_swapVictim = l_procChip;
            TARG_INF( "Master Proc %.8X is using XSCOM BAR from %.8X, BAR=%.16llX", get_huid(l_pMasterProcChip), get_huid(l_swapVictim), l_curXscomBAR );

            l_swapAttrs[ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID] = l_topologyId;
            l_swapAttrs[ATTR_XSCOM_BASE_ADDRESS] = l_xscomBAR;
        }

        // Compute default LPC BAR
        ATTR_LPC_BUS_ADDR_type l_lpcBAR =
          computeMemoryMapOffset( l_lpcBase, l_topologyMode, l_topologyId);
        TARG_INF( " LPC=%.16llX", l_lpcBAR );
        l_procChip->setAttr<ATTR_LPC_BUS_ADDR>(l_lpcBAR);
        if( l_swapVictim == l_procChip )
        {
            l_swapAttrs[ATTR_LPC_BUS_ADDR] = l_lpcBAR;
        }

        // Paranoid double-check that LPC matches XSCOM...
        if( ((l_lpcBAR == l_curLpcBAR) && (l_swapVictim != l_procChip))
            ||
            ((l_lpcBAR != l_curLpcBAR) && (l_swapVictim == l_procChip)) )
        {
            TARG_ERR("BARs do not match : LPC=%.16llX, XSCOM=%.16llX",
                     l_curLpcBAR, l_curXscomBAR );
            TARG_ASSERT(false,"Mismatch between LPC and XSCOM BARs");
        }

        //Setup Interrupt Related Bars
        ATTR_PSI_BRIDGE_BASE_ADDR_type l_psiBridgeBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_PSI_BRIDGE_BASE_ADDR,
                                   l_topologyMode, l_topologyId);
        TARG_INF( " PSI_BRIDGE_BAR =%.16llX", l_psiBridgeBAR );
        l_procChip->setAttr<ATTR_PSI_BRIDGE_BASE_ADDR>(l_psiBridgeBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_PSI_BRIDGE_BASE_ADDR] = l_psiBridgeBAR;
        }

        ATTR_XIVE_CONTROLLER_BAR_ADDR_type l_xiveCtrlBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_XIVE_CONTROLLER_BASE_ADDR,
                                   l_topologyMode, l_topologyId);
        TARG_INF( " XIVE_CONTROLLER_BAR =%.16llX", l_xiveCtrlBAR );
        l_procChip->setAttr<ATTR_XIVE_CONTROLLER_BAR_ADDR>(l_xiveCtrlBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_XIVE_CONTROLLER_BAR_ADDR] = l_xiveCtrlBAR;
        }

        ATTR_INT_CQ_TM_BAR_ADDR_type l_intCqTmBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_INT_CQ_TM_BASE_ADDR,
                                   l_topologyMode, l_topologyId);
        TARG_INF( " INT_CQ_TM_BAR =%.16llX", l_intCqTmBAR );
        l_procChip->setAttr<ATTR_INT_CQ_TM_BAR_ADDR>(l_intCqTmBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_INT_CQ_TM_BAR_ADDR] = l_intCqTmBAR;
        }

        ATTR_PSI_HB_ESB_ADDR_type l_psiHbEsbBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_PSI_HB_ESB_BASE_ADDR,
                                   l_topologyMode, l_topologyId);
        TARG_INF( " PSI_HB_ESB_BAR =%.16llX", l_psiHbEsbBAR );
        l_procChip->setAttr<ATTR_PSI_HB_ESB_ADDR>(l_psiHbEsbBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_PSI_HB_ESB_ADDR] = l_psiHbEsbBAR;
        }

        ATTR_FSP_BASE_ADDR_type l_fspBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_FSP_BASE_ADDR,
                                   l_topologyMode, l_topologyId);
        TARG_INF( " FSP_BAR =%.16llX", l_fspBAR );
        l_procChip->setAttr<ATTR_FSP_BASE_ADDR>(l_fspBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_FSP_BASE_ADDR] = l_fspBAR;
        }

        //finished setting up interrupt bars

    }

    // We should have found a match, but if a processor was swapped
    //  between different systems we could end up with a non-match
    if( l_swapVictim == nullptr )
    {
        TARG_INF( "No swap victim was found, forcing master proc to use calculated proc0 values" );

        // figure out what fabric id we actually booted with
        uint8_t l_bootIndex = getTopoIndexFromAddr( l_curXscomBAR );
        CONSOLE::displayf(CONSOLE::DEFAULT,  NULL, "Module swap detected - handling memory remap from %d\n", l_bootIndex );

        // now adjust the attributes that our early code is going to consume
        //  to match the fabric id we're currently using
        ATTR_XSCOM_BASE_ADDRESS_type l_xscomBAR =
          computeMemoryMapOffset( l_xscomBase, l_bootIndex );
        l_pMasterProcChip->setAttr<ATTR_XSCOM_BASE_ADDRESS>(l_xscomBAR);

        ATTR_LPC_BUS_ADDR_type l_lpcBAR =
          computeMemoryMapOffset( l_lpcBase, l_bootIndex );
        l_pMasterProcChip->setAttr<ATTR_LPC_BUS_ADDR>(l_lpcBAR);

        ATTR_PSI_BRIDGE_BASE_ADDR_type l_psiBridgeBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_PSI_BRIDGE_BASE_ADDR,
                                   l_bootIndex);
        l_pMasterProcChip->setAttr<ATTR_PSI_BRIDGE_BASE_ADDR>(l_psiBridgeBAR);

        ATTR_XIVE_CONTROLLER_BAR_ADDR_type l_xiveCtrlBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_XIVE_CONTROLLER_BASE_ADDR,
                                   l_bootIndex);
        l_pMasterProcChip->setAttr<ATTR_XIVE_CONTROLLER_BAR_ADDR>(l_xiveCtrlBAR);

        ATTR_PSI_HB_ESB_ADDR_type l_psiHbEsbBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_PSI_HB_ESB_BASE_ADDR,
                                   l_bootIndex);
        l_pMasterProcChip->setAttr<ATTR_PSI_HB_ESB_ADDR>(l_psiHbEsbBAR);

        // Set the initialization of attribute to force an SBE update later
        l_pTopLevel->setAttr<TARGETING::ATTR_FORCE_SBE_UPDATE>
          (TARGETING::SBE_UPDATE_TYPE_BAR_MISMATCH);
    }
    // Now swap the BARs between the master and the victim if needed
    else if( l_swapVictim != l_pMasterProcChip )
    {
        // Walk through all of the attributes we cached above

        SWAP_ATTRIBUTE( ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_XSCOM_BASE_ADDRESS, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_LPC_BUS_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_PSI_BRIDGE_BASE_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_XIVE_CONTROLLER_BAR_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_INT_CQ_TM_BAR_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_PSI_HB_ESB_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_FSP_BASE_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );

        // Handle the rest of the BARs...
    }

    // Cross-check that what we ended up setting in the attributes
    //  matches the non-TARGETING values that the XSCOM and LPC
    //  drivers computed (only if we found a swap victim)
    if( l_swapVictim &&
        (l_pMasterProcChip->getAttr<ATTR_LPC_BUS_ADDR>()
         != LPC::get_lpc_bar()) )
    {
        TARG_ERR( "LPC attribute=%.16llX, live=%.16llX",
           l_pMasterProcChip->getAttr<ATTR_LPC_BUS_ADDR>(),
           LPC::get_lpc_bar() );
        TARG_ASSERT( false, "LPC BARs are inconsistent" );
    }

    if( l_swapVictim &&
        (l_pMasterProcChip->getAttr<ATTR_XSCOM_BASE_ADDRESS>()
         != XSCOM::get_master_bar()) )
    {
        TARG_ERR( "XSCOM attribute=%.16llX, live=%.16llX",
           l_pMasterProcChip->getAttr<ATTR_XSCOM_BASE_ADDRESS>(),
           XSCOM::get_master_bar() );
        TARG_ASSERT( false, "XSCOM BARs are inconsistent" );
    }

}


#undef TARG_CLASS

#undef TARG_NAMESPACE

} // End namespace TARGETING
