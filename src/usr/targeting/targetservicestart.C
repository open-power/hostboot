/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/targetservicestart.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
#include <sys/misc.h>
#include <sys/mm.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <targeting/common/trace.H>
#include <targeting/adapters/assertadapter.H>
#include <initservice/taskargs.H>
#include <util/utilmbox_scratch.H>
#include <util/align.H>

// This component
#include <targeting/common/targetservice.H>
#include <targeting/attrrp.H>

// Others
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <config.h>
#include <initservice/initserviceif.H>
#include <util/misc.H>
#include <util/utilrsvdmem.H>
#include <kernel/bltohbdatamgr.H>
#include <map>
#include <arch/memorymap.H>
#include <lpc/lpcif.H>
#include <xscom/xscomif.H>
#include <bootloader/bootloaderif.H>
#include <sbeio/sbeioif.H>
#include <sys/mm.h>
#include "../runtime/hdatstructs.H"

#ifdef CONFIG_DRTM
#include <secureboot/drtm.H>
#endif

using namespace INITSERVICE::SPLESS;
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
                                 ATTR_MASTER_MBOX_SCRATCH_type& i_masterScratch);

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
    ATTR_MASTER_MBOX_SCRATCH_type l_scratch = {0,0,0,0,0,0,0,0};

    for(size_t i=0; i< sizeof(l_scratch)/sizeof(l_scratch[0]); i++)
    {
        l_scratch[i] =
        Util::readScratchReg(MBOX_SCRATCH_REG1+i);
    }

    // Check mbox scratch reg 3 for IPL boot options
    // Specifically istep mode (bit 0) and MPIPL (bit 2)
    INITSERVICE::SPLESS::MboxScratch3_t l_scratch3;
    l_scratch3.data32 = l_scratch[SCRATCH_3];

    if(l_scratch3.isMpipl)
    {
        TARG_INF("We are running MPIPL mode");
        //Since we are in MPIPL we know that memory is up and running
        //in order to avoid burning through all of our memory pages
        //during the attrrp init, which is when we copy attributes from
        //the prev IPL into PNOR, we expand out to full cache right now
        //in activate_threads we will expand out to MM_EXTEND_REAL_MEMORY
        mm_extend(MM_EXTEND_FULL_CACHE);
        l_isMpipl = true;
    }
    if(l_scratch3.istepMode)
    {
        l_isIstepMode = true;
    }
    if(l_scratch3.overrideSecurity)
    {
        TARG_INF("WARNING: External tool asked master proc to disable "
            "security.");
    }
    if(l_scratch3.allowAttrOverrides)
    {
        TARG_INF("WARNING: External tool asked master proc to allow "
            "attribute overrides even in secure mode.");
    }

    AttrRP::init(io_pError, l_isMpipl);

    if (io_pError == NULL)
    {
        TargetService& l_targetService = targetService();
        (void)l_targetService.init();

        initializeAttributes(l_targetService, l_isMpipl, l_isIstepMode, l_scratch);
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

#ifdef CONFIG_DRTM
        const INITSERVICE::SPLESS::MboxScratch7_t scratch7 =
            {.data32 = l_scratch[SCRATCH_7] };
        const INITSERVICE::SPLESS::MboxScratch8_t scratch8 =
            {.data32 = l_scratch[SCRATCH_8] };

        errlHndl_t pError = SECUREBOOT::DRTM::discoverDrtmState(
            scratch7,scratch8);
        if(pError)
        {
            auto plid = pError->plid();
            errlCommit(pError,SECURE_COMP_ID);
            // TODO: RTC 167205: Better GA error handling
            INITSERVICE::doShutdown(plid, true);
        }
#endif

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
            case MODEL_VENICE:
                if(l_coreType == CORE_POWER8_VENICE)
                {
                    l_haveOneCorrectProcessor = true;
                }
                break;

            case MODEL_MURANO:
                if(l_coreType == CORE_POWER8_MURANO)
                {
                    l_haveOneCorrectProcessor = true;
                }
                break;

            case MODEL_NAPLES:
                if(l_coreType == CORE_POWER8_NAPLES)
                {
                    l_haveOneCorrectProcessor = true;
                }
                break;
            case MODEL_NIMBUS:
                if(l_coreType == CORE_POWER9_NIMBUS)
                {
                    l_haveOneCorrectProcessor = true;
                }
                break;
            case MODEL_CUMULUS:
                if(l_coreType == CORE_POWER9_CUMULUS)
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

/*
 * @brief Initialize any attributes that need to be set early on
 */
static void initializeAttributes(TargetService& i_targetService,
                                 bool i_isMpipl,
                                 bool i_istepMode,
                                 ATTR_MASTER_MBOX_SCRATCH_type& i_masterScratch)
{
    #define TARG_FN "initializeAttributes()...)"
    TARG_ENTER();

    Target* l_pTopLevel = NULL;

    TargetHandleList l_chips;

    i_targetService.getTopLevelTarget(l_pTopLevel);
    if(l_pTopLevel)
    {
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


            l_pTopLevel->setAttr<ATTR_MASTER_MBOX_SCRATCH>(i_masterScratch);

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

            //Set the RISK_LEVEL ATTR based off of master Scratch regs
            INITSERVICE::SPLESS::MboxScratch5_t l_scratch5;
            l_scratch5.data32 = i_masterScratch[INITSERVICE::SPLESS::SCRATCH_5];
            l_pTopLevel->setAttr<ATTR_RISK_LEVEL>(l_scratch5.riskLevel);
        }

        if(i_isMpipl)
        {
            l_pTopLevel->setAttr<ATTR_IS_MPIPL_HB>(1);

            //Clear out some attributes that could have stale data
            l_pTopLevel->setAttr<ATTR_HB_RSV_MEM_NEXT_SECTION>(0);
            l_pTopLevel->setAttr<ATTR_ATTN_CHK_ALL_PROCS>(1);

            //It is possible that the hypervisor moved the HRMOR
            //The SBE should have read the HRMOR value from the master
            //core prior to stopping its clocks and passed that
            //value to the bootloader. The bootloader passes this to
            //HB via the BlToHbDataManager
            // Setup physical TOC address
            uint64_t l_hyp_hrmor = 0;

            Bootloader::keyAddrPair_t l_keyAddrPairs =
            g_BlToHbDataManager.getKeyAddrPairs();

            for (uint8_t keyIndex = 0; keyIndex < MAX_ROW_COUNT; keyIndex++)
            {
                if(l_keyAddrPairs.key[keyIndex] == SBEIO::HYPERVISOR_HRMOR)
                {
                    l_hyp_hrmor = l_keyAddrPairs.addr[keyIndex];
                }
            }

            if(l_hyp_hrmor)
            {
                l_pTopLevel->setAttr<ATTR_PAYLOAD_BASE>(l_hyp_hrmor);
            }


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
                auto tpmMutex=tpm->getHbMutexAttr<ATTR_HB_TPM_MUTEX>();
                mutex_init(tpmMutex);
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

            // Setup physical TOC address
            uint64_t l_hbdTocAddr = AttrRP::getHbDataTocAddr();

            // Variables to store information about Hostboot/Hypervisor communcation area
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


            //This will tell us how far from the beginning of the toc_ptr the hypComm area starts
            uint64_t l_hypComm_offset = l_hypComm_virt_addr - reinterpret_cast<uint64_t>(l_toc_ptr);

            //Use the offset found w/ virtual addresses to determine the physical address of the
            //hostboot/hypervisor comm area
            l_hypComm_phys_addr = l_hbdTocAddr + l_hypComm_offset;

            // Clear the mapped memory for the TOC, it is not longer needed as we have phys ptr
            assert (0 == mm_block_unmap(reinterpret_cast<void*>(l_toc_ptr)),
                    "Failed to unmap hbData TOC");

            // The hb/hyp communcation area is at the end of the hostboot
            // data reserved mem section.
            hbHypCommArea_t * l_hbHypComm_ptr =
                reinterpret_cast<hbHypCommArea_t *>(
                    mm_block_map(reinterpret_cast<void*>(l_hypComm_phys_addr),
                                 ALIGN_PAGE(sizeof(l_hypComm_size))));

            // Make sure the magic number and version are valid
            if(l_hbHypComm_ptr->magicNum == HYPECOMM_MAGIC_NUM && l_hbHypComm_ptr->version >= STRUCT_VERSION_FIRST)
            {
              // if the hrmor in the comm area is non-zero then set the payload base attribute
              if( l_hbHypComm_ptr->hrmorAddress)
              {
                const uint64_t THREAD_STATE_RUNNING = 0x8000000000000000ULL;
                TARG_INF("Setting ATTR_PAYLOAD_BASE to new hrmor given by hypervisor: 0x%lx",
                          l_hbHypComm_ptr->hrmorAddress);
                //Mask off THREAD_STATE_RUNNING bit and then divide remaining address by 1 MB
                uint64_t l_payloadBase_MB =  ((~(THREAD_STATE_RUNNING)) & l_hbHypComm_ptr->hrmorAddress) / MEGABYTE;
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
            assert(0 == mm_block_unmap(reinterpret_cast<void*>(l_hbHypComm_ptr)),
                  "Failed to unmap hbHypComm area");
        }
        else
        {
            l_pTopLevel->setAttr<ATTR_IS_MPIPL_HB>(0);

            // Compute any values that might change based on a remap of memory
            adjustMemoryMap(i_targetService);

            if(!INITSERVICE::spBaseServicesEnabled())
            {
                TARGETING::Target* l_sys = NULL;
                TARGETING::targetService().getTopLevelTarget(l_sys);
                getAllChips(l_chips, TYPE_PROC, false);

                ATTR_PROC_EFF_FABRIC_GROUP_ID_type l_eff_id;
                ATTR_FABRIC_PRESENT_GROUPS_type l_fabric_groups = 0;

                for(auto l_chip : l_chips)
                {
                    // Read the fabric group id
                    l_eff_id = l_chip->getAttr<ATTR_PROC_EFF_FABRIC_GROUP_ID>();
                    // Set the corresponding bit in fabric groups
                    l_fabric_groups |= (1 <<
                                       ((sizeof(ATTR_FABRIC_PRESENT_GROUPS_type)
                                        * 8)
                                        - l_eff_id - 1));
                }
                l_sys->setAttr<ATTR_FABRIC_PRESENT_GROUPS>(l_fabric_groups);
            }
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

    // Save off the base (group0-chip0) value for the BARs
    Target* l_pTopLevel = nullptr;
    i_targetService.getTopLevelTarget(l_pTopLevel);
    ATTR_XSCOM_BASE_ADDRESS_type l_xscomBase =
      l_pTopLevel->getAttr<ATTR_XSCOM_BASE_ADDRESS>();
    ATTR_LPC_BUS_ADDR_type l_lpcBase =
      l_pTopLevel->getAttr<ATTR_LPC_BUS_ADDR>();

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
        ATTR_FABRIC_GROUP_ID_type l_groupId =
          l_procChip->getAttr<ATTR_FABRIC_GROUP_ID>();
        l_procChip->setAttr<ATTR_PROC_EFF_FABRIC_GROUP_ID>(l_groupId);

        ATTR_FABRIC_CHIP_ID_type l_chipId =
          l_procChip->getAttr<ATTR_FABRIC_CHIP_ID>();
        l_procChip->setAttr<ATTR_PROC_EFF_FABRIC_CHIP_ID>(l_chipId);

        // Compute default xscom BAR
        ATTR_XSCOM_BASE_ADDRESS_type l_xscomBAR =
          computeMemoryMapOffset( l_xscomBase, l_groupId, l_chipId );
        TARG_INF( " XSCOM=%.16llX", l_xscomBAR );
        l_procChip->setAttr<ATTR_XSCOM_BASE_ADDRESS>(l_xscomBAR);

        // See if this chip's space now belongs to the master
        if( l_xscomBAR == l_curXscomBAR )
        {
            l_swapVictim = l_procChip;
            TARG_INF( "Master Proc %.8X is using XSCOM BAR from %.8X, BAR=%.16llX", get_huid(l_pMasterProcChip), get_huid(l_swapVictim), l_curXscomBAR );
            l_swapAttrs[ATTR_PROC_EFF_FABRIC_GROUP_ID] = l_groupId;
            l_swapAttrs[ATTR_PROC_EFF_FABRIC_CHIP_ID] = l_chipId;
            l_swapAttrs[ATTR_XSCOM_BASE_ADDRESS] = l_xscomBAR;
        }

        // Compute default LPC BAR
        ATTR_LPC_BUS_ADDR_type l_lpcBAR =
          computeMemoryMapOffset( l_lpcBase, l_groupId, l_chipId );
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
                                  l_groupId,
                                  l_chipId);
        TARG_INF( " PSI_BRIDGE_BAR =%.16llX", l_psiBridgeBAR );
        l_procChip->setAttr<ATTR_PSI_BRIDGE_BASE_ADDR>(l_psiBridgeBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_PSI_BRIDGE_BASE_ADDR] = l_psiBridgeBAR;
        }

        ATTR_XIVE_CONTROLLER_BAR_ADDR_type l_xiveCtrlBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_XIVE_CONTROLLER_BASE_ADDR,
                                   l_groupId,
                                   l_chipId);
        TARG_INF( " XIVE_CONTROLLER_BAR =%.16llX", l_xiveCtrlBAR );
        l_procChip->setAttr<ATTR_XIVE_CONTROLLER_BAR_ADDR>(l_xiveCtrlBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_XIVE_CONTROLLER_BAR_ADDR] = l_xiveCtrlBAR;
        }

        ATTR_XIVE_THREAD_MGMT1_BAR_ADDR_type l_xiveThreadMgmtBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_XIVE_THREAD_MGMT1_BASE_ADDR,
                                   l_groupId,
                                   l_chipId);
        TARG_INF( " XIVE_THREAD_MGMT1_BAR =%.16llX", l_xiveThreadMgmtBAR );
        l_procChip->setAttr<ATTR_XIVE_THREAD_MGMT1_BAR_ADDR>(l_xiveThreadMgmtBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_XIVE_THREAD_MGMT1_BAR_ADDR] = l_xiveThreadMgmtBAR;
        }

        ATTR_PSI_HB_ESB_ADDR_type l_psiHbEsbBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_PSI_HB_ESB_BASE_ADDR,
                                   l_groupId,
                                   l_chipId);
        TARG_INF( " PSI_HB_ESB_BAR =%.16llX", l_psiHbEsbBAR );
        l_procChip->setAttr<ATTR_PSI_HB_ESB_ADDR>(l_psiHbEsbBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_PSI_HB_ESB_ADDR] = l_psiHbEsbBAR;
        }

        ATTR_INTP_BASE_ADDR_type l_intpBAR =
            computeMemoryMapOffset(MMIO_GROUP0_CHIP0_INTP_BASE_ADDR,
                                   l_groupId,
                                   l_chipId);
        TARG_INF( " INTP_BAR =%.16llX", l_intpBAR );
        l_procChip->setAttr<ATTR_INTP_BASE_ADDR>(l_intpBAR);
        if( l_swapVictim == l_procChip)
        {
            l_swapAttrs[ATTR_INTP_BASE_ADDR] = l_intpBAR;
        }
        //finished setting up interrupt bars

        // Set the rest of the BARs...
    }

    // We must have found a match somewhere
    TARG_ASSERT( l_swapVictim != nullptr, "No swap match found" );

    // Now swap the BARs between the master and the victim if needed
    if( l_swapVictim != l_pMasterProcChip )
    {
        // Walk through all of the attributes we cached above
        SWAP_ATTRIBUTE( ATTR_PROC_EFF_FABRIC_GROUP_ID, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_PROC_EFF_FABRIC_CHIP_ID, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_XSCOM_BASE_ADDRESS, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_LPC_BUS_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_PSI_BRIDGE_BASE_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_XIVE_CONTROLLER_BAR_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_XIVE_THREAD_MGMT1_BAR_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_PSI_HB_ESB_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        SWAP_ATTRIBUTE( ATTR_INTP_BASE_ADDR, l_pMasterProcChip,
                        l_swapVictim, l_swapAttrs );
        // Handle the rest of the BARs...
    }


    // Cross-check that what we ended up setting in the attributes
    //  matches the non-TARGETING values that the XSCOM and LPC
    //  drivers computed
    if( l_pMasterProcChip->getAttr<ATTR_LPC_BUS_ADDR>()
        != LPC::get_lpc_bar() )
    {
        TARG_ERR( "LPC attribute=%.16llX, live=%.16llX",
           l_pMasterProcChip->getAttr<ATTR_LPC_BUS_ADDR>(),
           LPC::get_lpc_bar() );
        TARG_ASSERT( false, "LPC BARs are inconsistent" );
    }
    if( l_pMasterProcChip->getAttr<ATTR_XSCOM_BASE_ADDRESS>()
        != XSCOM::get_master_bar() )
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

