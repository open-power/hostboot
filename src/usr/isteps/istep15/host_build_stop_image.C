/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep15/host_build_stop_image.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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


////System
#include    <sys/misc.h>
#include    <sys/mmio.h>
#include    <sys/mm.h>
#include    <usr/vmmconst.h>
#include    <arch/pirformat.H>
#include    <isteps/pm/pm_common_ext.H>
#include    <config.h>

//Utilities
#include    <util/utilxipimage.H>

//Error handling and tracing
#include    <errl/errlentry.H>
#include    <errl/errluserdetails.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
#include    <errl/errlreasoncodes.H>
#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>

//PNOR Resource Provider
#include    <pnor/pnorif.H>

//Targeting Support
#include    <targeting/common/utilFilter.H>
#include    <fapi2/target.H>

//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>

//Import directory (from EKB repository)
#include    <p9_hcode_image_build.H>
#include    <p9_stop_api.H>
#include    <p9_xip_image.h>
#include    <p9_infrastruct_help.H>
#include    <p9_hcode_image_defines.H>
#include    <p9_xip_section_append.H>

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;
using   namespace   PNOR;
using   namespace   stopImageSection;
using   namespace   fapi2;

namespace ISTEP_15
{

/**
 *  @brief Load HCODE image and return a pointer to it, or NULL
 *
 *  @param[out] -   address of the HCODE image
 *
 *  @return      NULL if success, errorlog if failure
 *
 */
errlHndl_t  loadHcodeImage(  char                    *& o_rHcodeAddr)
{
    errlHndl_t l_errl = NULL;
    PNOR::SectionInfo_t l_info;

    do
    {

#ifdef CONFIG_SECUREBOOT
        l_errl = loadSecureSection(PNOR::HCODE);
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"loadHcodeImage() - Error from "
                       "loadSecureSection(PNOR::HCODE)");

            //No need to commit error here, it gets handled later
            //just break out to escape this function
            break;
        }
#endif

        // Get HCODE/WINK PNOR section info from PNOR RP
        l_errl = PNOR::getSectionInfo( PNOR::HCODE, l_info );
        if( l_errl )
        {
            //No need to commit error here, it gets handled later
            //just break out to escape this function
            break;
        }

        o_rHcodeAddr = reinterpret_cast<char*>(l_info.vaddr);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "HCODE addr = 0x%p ",
                   o_rHcodeAddr);

    } while ( 0 );

    return  l_errl;
}

/**
 * @brief   apply cpu reg information to the HCODE image using
 *          p9_stop_save_cpureg() .
 *
 * @param i_procChipTarg   -   proc target
 * @param io_image      -   pointer to the HCODE image
 * @param i_sizeImage   -   size of the HCODE image
 *
 * @return errorlog if error, NULL otherwise.
 *
 */
errlHndl_t  applyHcodeGenCpuRegs(  TARGETING::Target *i_procChipTarg,
                                   void      *io_image,
                                   uint32_t  i_sizeImage )
{
    errlHndl_t  l_errl      =   NULL;

    //Use TARGETING code to look up CORE target handles
    TARGETING::TargetHandleList l_coreIds;
    getChildChiplets( l_coreIds,
                      i_procChipTarg,
                      TYPE_CORE,
                      false );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "applyHcodeGenCpuRegs: Process cores=0x%x, threads=0x%x",
               l_coreIds.size(),
               cpu_thread_count() );

    //Thread tracking
    const size_t l_cpu_thread_count = cpu_thread_count();
    TARGETING::ATTR_CHIP_UNIT_type l_coreId    =   0;
    size_t      l_threadId  =   0;
    //Error Handling
    uint32_t    l_rc        =   0;
    uint32_t    l_failAddr  =   0;
    //Register Values
    uint64_t    l_msrVal    =   cpu_spr_value(CPU_SPR_MSR);
    uint64_t    l_lpcrVal   =   cpu_spr_value(CPU_SPR_LPCR);

    // See LPCR def, PECE "reg" in Power ISA AS Version: Power8 June 27, 2012
    //  and 23.7.3.5 - 6 in Murano Book 4
    l_lpcrVal   &=  ~(0x0000000000002000) ;
    l_lpcrVal   |=    0x0000400000000000  ;  //Allow Hyp virt to exit STOP

//@TODO RTC:147565
//Force Core Checkstops by telling ACTION1 Reg after coming out of winkle
// Core FIR Action1 Register value from Nick
//     const uint64_t action1_reg = 0xEA5C139705980000;

    //Get top-lvl system target with TARGETING code to find the enabled threads
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    assert( sys != NULL );
    uint64_t en_threads = sys->getAttr<ATTR_ENABLED_THREADS>();

    //look up the HRMOR value from the HRMOR CPU special purpose register(SPR)
    uint64_t    l_hrmorVal  =   cpu_spr_value(CPU_SPR_HRMOR);

    //iterate through the cores while copying information from SPRs
    for (const auto & l_core: l_coreIds)
    {
        // trace the HUID of the core we are writing to
        TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_core));

        l_threadId = 0;

        //Get core's parent processor target handle
        ConstTargetHandle_t l_processor = getParentChip(l_core);

        //Read core's chip unit id attribute and store it as the core's id
         CHIP_UNIT_ATTR l_coreId =
                (l_core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        //Read the processor's fabric group id
        FABRIC_GROUP_ID_ATTR l_logicalGroupId =
          l_processor->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();

        //Read the processor's fabric chip id
        FABRIC_CHIP_ID_ATTR l_chipId =
          l_processor->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

        TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "chip unit: %d  fabric group: %d    chip id: %d",
                  l_coreId, l_logicalGroupId,l_chipId);

        //store the PIR value by passing the values read in above into the
        //PIR_t constructor and read the .word attribute on the new PIR struct
        uint64_t l_pirVal = PIR_t(l_logicalGroupId, l_chipId, l_coreId).word;

        //The underlying stop API knows about fused/normal cores.  Need to take
        //this into account for fused mode.  If we are in fused mode, then
        //the even core thead 0/1 correspond to physical core 0 and 1
        //respectively, so both need to be set to populate the STOP image
        size_t l_fuseThreadAdjust = 0x1;
        if(is_fused_mode())
        {
            //If even core set threads 0,1
            //If odd core skip by setting loop count to 0
            l_fuseThreadAdjust = (l_coreId%2 == 0x0) ? 2 : 0;
        }

        for(size_t l_fuseAdj = 0; l_fuseAdj < l_fuseThreadAdjust; l_fuseAdj++)
        {

            //Call p9_stop_save_cpureg to store the MSR SPR value
            l_rc = p9_stop_save_cpureg( io_image,
                                        P9_STOP_SPR_MSR,
                                        l_msrVal,
                                        l_pirVal | l_fuseAdj);
            if ( l_rc )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR: MSR: core=0x%x,thread=0x%x,l_rc=0x%x",
                           l_coreId, l_threadId, l_rc );
                l_failAddr = P9_STOP_SPR_MSR;
                break;
            }

            //Call p9_stop_save_cpureg to store the HRMOR SPR value
            l_rc = p9_stop_save_cpureg( io_image,
                                        P9_STOP_SPR_HRMOR,
                                        l_hrmorVal,
                                        l_pirVal | l_fuseAdj);

            if ( l_rc ){
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR: HRMOR: core=0x%x,thread=0x%x,l_rc=0x%x",
                           l_coreId, l_threadId, l_rc );
                l_failAddr = P9_STOP_SPR_HRMOR;
                break;
            }
        }

        //  fill in lpcr for each thread
        for ( l_threadId=0; l_threadId < l_cpu_thread_count; l_threadId++ )
        {
            // Skip threads that we shouldn't be starting
            if( !(en_threads & (0x8000000000000000>>l_threadId)) )
            {
                continue;
            }

            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "applyHcodeGenCpuRegs: core=0x%x,thread=0x%x: ",
                       l_coreId, l_threadId );
            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "applyHcodeGenCpuRegs: msrc=0x%x,lpcr=0x%x,hrmor=0x%x",
                       l_msrVal, l_lpcrVal, l_hrmorVal  );

            //the thread ID is the last 3 bytes of pirVal so you can just OR
            uint64_t l_pirValThread = l_pirVal | l_threadId;

            //Call p9_stop_save_cpureg from p9_stop_api
            //to store the LPCR SPR value
            l_rc = p9_stop_save_cpureg( io_image,
                                        P9_STOP_SPR_LPCR,
                                        l_lpcrVal,
                                        l_pirValThread);
            if ( l_rc )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR: LPCR: core=0x%x,thread=0x%x,l_rc=0x%x",
                           l_coreId, l_threadId, l_rc );
                l_failAddr = P9_STOP_SPR_LPCR;
                break;
            }
        }   // end for l_threadId

        //  if error writing thread break out of l_coreId loop
        if ( l_rc !=0 )
        {
            break;
        }
//@TODO RTC:147565
//Force Core Checkstops by telling ACTION1 Reg after coming out of winkle
//@fixme HACK in place for OPAL
          // Need to force core checkstops to escalate to a system checkstop
          //  by telling the HCODE to update the ACTION1 register when it
          //  comes out of winkle  (see HW286670)
//         l_rc = p8_pore_gen_scom_fixed( io_image,
//                                        P8_SLW_MODEBUILD_IPL,
//                                        EX_CORE_FIR_ACTION1_0x10013107,
//                                        l_coreId,
//                                        action1_reg,
//                                        P8_PORE_SCOM_REPLACE,
//                                        P8_SCOM_SECTION_NC );
//         if( l_rc )
//         {
//             TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
//                        "ERROR: ACTION1: core=0x%x,l_rc=0x%x",
//                        l_coreId, l_rc );
//             l_failAddr = EX_CORE_FIR_ACTION1_0x10013107;
//             break;
//         }

    }   // end for l_coreIds

    if ( l_rc ){
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR: p9 stop api fail core=0x%x, thread=0x%x, l_rc=0x%x",
                   l_coreId, l_threadId, l_rc );
        /*@
        * @errortype
        * @reasoncode  ISTEP::RC_BAD_RC
        * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid    ISTEP::MOD_BUILD_HCODE_IMAGES
        * @userdata1   Hi 32 bits: return code from p8_pore_gen_scom_fixed
        *              Lo 32 bits: Address of EX_CORE_FIR_ACTION1_0x10013107
        * @userdata2   Hi 32 bits: ID of core
        *              Lo 32 bits: Thread id
        * @devdesc     Unable to force core checkstops by updating ACTION1
        *              when it comes out of winkle
        * @custdesc    A problem occurred during the IPL
        *              of the system.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                ISTEP::MOD_BUILD_HCODE_IMAGES,
                                ISTEP::RC_BAD_RC,
                                TWO_UINT32_TO_UINT64(l_rc,l_failAddr),
                                TWO_UINT32_TO_UINT64(l_coreId,l_threadId),
                                true);
        l_errl->collectTrace(FAPI_TRACE_NAME,256);
        l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
        l_errl->collectTrace("ISTEPS_TRACE",256);
    }

    return  l_errl;
}

void* host_build_stop_image (void *io_pArgs)
{
    errlHndl_t  l_errl           = NULL;
    ISTEP_ERROR::IStepError     l_StepError;

    // unload of HCODE PNOR section only necessary if SECUREBOOT compiled in
#ifdef CONFIG_SECUREBOOT
    bool unload_hcode_pnor_section = false;
#endif

    char*       l_pHcodeImage     = NULL;
    void*       l_pRealMemBase   = NULL;
    void*       l_pVirtMemBase   = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_build_stop_image entry" );

    // allocate four temporary work buffers
    void* l_temp_buffer0 = malloc(HW_IMG_RING_SIZE);
    void* l_temp_buffer1 = malloc(MAX_RING_BUF_SIZE);
    void* l_temp_buffer2 = malloc(MAX_RING_BUF_SIZE);
    void* l_temp_buffer3 = malloc(MAX_RING_BUF_SIZE);

    do  {
        //Determine top-level system target
        TARGETING::Target* l_sys = NULL;
        TARGETING::targetService().getTopLevelTarget(l_sys);
        assert( l_sys != NULL );

        if (l_sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
        {
            l_errl = HBPM::resetPMAll();
            if(l_errl)
            {
                //Break out of the do-while loop..
                //we should have been able to do a PM reset
                break;
            }
        }

        // Get the node-offset for our instance by looking at the HRMOR
        uint64_t l_memBase = cpu_spr_value(CPU_SPR_HRMOR);
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "HRMOR=%.16X", l_memBase );
        // Now offset up to our hardcoded region
        l_memBase += VMM_HOMER_REGION_START_OFFSET;

        //  Get a chunk of real memory big enough to store all the possible
        //  HCODE images. (4MB is size of HOMER)
        assert(VMM_HOMER_REGION_SIZE <= (P9_MAX_PROCS * (4 * MEGABYTE)),
               "host_build_stop_image: Unsupported HOMER Region size");

        //If running Sapphire need to place this at the top of memory instead
        if(is_sapphire_load())
        {
            l_memBase = get_top_mem_addr();
            assert (l_memBase != 0,
                    "host_build_stop_image: Top of memory was 0!");
            l_memBase -= VMM_ALL_HOMER_OCC_MEMORY_SIZE;
        }
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "HOMER base = %.16X", l_memBase);
        l_pRealMemBase = reinterpret_cast<void * const>(l_memBase );

        //Convert the real memory pointer to a pointer in virtual memory
        l_pVirtMemBase =
              mm_block_map(l_pRealMemBase, VMM_HOMER_REGION_SIZE);

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Got virtual mem  buffer for %d cpus = 0x%p",
                   P9_MAX_PROCS,
                   l_pVirtMemBase  );

        //Since we have the HOMER location defined, set the
        // OCC common attribute to be used later by pm code
        l_sys->setAttr<TARGETING::ATTR_OCC_COMMON_AREA_PHYS_ADDR>
            (reinterpret_cast<uint64_t>(l_pRealMemBase)
                + VMM_HOMER_REGION_SIZE);

        //  Continue, build hcode images
        //
        //Load the reference image from PNOR
        l_errl  =   loadHcodeImage(  l_pHcodeImage );
        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_build_stop_image ERROR : errorlog PLID=0x%x",
                      l_errl->plid() );
            // drop out of do block with errorlog.
            break;
        }
#ifdef CONFIG_SECUREBOOT
        unload_hcode_pnor_section = true;
#endif

        // Pull build information from XIP header and trace it
        Util::imageBuild_t l_imageBuild;
        Util::pullTraceBuildInfo(l_pHcodeImage,
                                 l_imageBuild,
                                 ISTEPS_TRACE::g_trac_isteps_trace);

        //  Loop through all functional Procs and generate images for them.
        //get a list of all the functional Procs
        TARGETING::TargetHandleList l_procChips;
        getAllChips( l_procChips,
                     TARGETING::TYPE_PROC   );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Found %d functional procs in system",
                   l_procChips.size()   );

        for (const auto & l_procChip: l_procChips)
        {
            do  {
                // write the HUID of the core we are writing to
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Build STOP image for proc "
                        "target HUID %.8X", TARGETING::get_huid(l_procChip));

                //  calculate size and location of the HCODE output buffer
                uint32_t    l_procNum =
                  l_procChip->getAttr<TARGETING::ATTR_POSITION>();
                uint64_t    l_procOffsetAddr =
                  ( l_procNum *VMM_HOMER_INSTANCE_SIZE );

                uint64_t    l_procRealMemAddr  =
                  reinterpret_cast<uint64_t>(l_pRealMemBase)
                  + l_procOffsetAddr;

                void *l_pImageOut =
                  reinterpret_cast<void * const>
                  (reinterpret_cast<uint64_t>(l_pVirtMemBase)
                   + l_procOffsetAddr) ;

                uint32_t    l_sizeImageOut  =
                  ((P9_MAX_PROCS * (4 * MEGABYTE)));

                //Make sure that the HOMER is zeroed out for the MPIPL path
                memset(l_pImageOut, 0, 4 * MEGABYTE);

                //Set default values, used later by p9_hcode_build
                l_procChip->setAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>
                                                        (l_procRealMemAddr);

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Real mem  buffer for cpu 0x%08x = %p, virtAddr=%p",
                           l_procNum,
                           l_procRealMemAddr,
                           l_pImageOut);

                //Cast OUR type of target to a FAPI2 type of target.
                const fapi2::Target<TARGET_TYPE_PROC_CHIP>
                l_fapiCpuTarget( const_cast<TARGETING::Target*>(l_procChip));

                //Default constructor sets the appropriate settings
                ImageType_t img_type;

                // Check if we have a valid ring override section and
                //  include it in if so
                void* l_ringOverrides = NULL;
                l_errl = HBPM::getRingOvd(l_ringOverrides);
                if(l_errl)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"host_build_stop_image(): "
                               "Error in call to getRingOvd!");
                    break;
                }

                //Call p9_hcode_image_build.C HWP
                FAPI_INVOKE_HWP( l_errl,
                                 p9_hcode_image_build,
                                 l_fapiCpuTarget,
                                 reinterpret_cast<void*>(l_pHcodeImage),
                                 l_pImageOut, //homer image buffer
                                 l_ringOverrides,
                                 PHASE_IPL,
                                 img_type,
                                 l_temp_buffer0,
                                 HW_IMG_RING_SIZE,
                                 l_temp_buffer1,
                                 MAX_RING_BUF_SIZE,
                                 l_temp_buffer2,
                                 MAX_RING_BUF_SIZE,
                                 l_temp_buffer3,
                                 MAX_RING_BUF_SIZE);

                if ( l_errl )
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "host_build_stop_image ERROR : errorlog PLID=0x%x",
                              l_errl->plid() );

                    //  drop out of block with errorlog.
                    break;
                }

                l_errl = applyHcodeGenCpuRegs( l_procChip,
                                               l_pImageOut,
                                               l_sizeImageOut );
                if ( l_errl )
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "applyHcodeGenCpuRegs ERROR : errorlog PLID=0x%x",
                              l_errl->plid() );

                    //  drop out of block with errorlog.
                    break;
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "applyHcodeGenCpuRegs SUCCESS " );
                }

            }   while (0) ;

            // broke out due to an error, store all the details away, store
            //  the errlog in IStepError, and continue to next proc
            if (l_errl)
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_procChip).addToLog( l_errl );

                l_errl->addFFDC( ERRL_COMP_ID,
                                 reinterpret_cast<void *>(&l_imageBuild),
                                 sizeof(Util::imageBuild_t),
                                 0,                   // Version
                                 ERRL_UDT_BUILD,      // parse XIP image build
                                 false );             // merge

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
            }

        } ;  // endfor

    }  while (0);
    // @@@@@    END CUSTOM BLOCK:   @@@@@

    if (l_errl)
    {
        // Create IStep error log and cross ref error that occurred
        l_StepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    // delete working buffers
    if( l_temp_buffer0 ) { free(l_temp_buffer0); }
    if( l_temp_buffer1 ) { free(l_temp_buffer1); }
    if( l_temp_buffer2 ) { free(l_temp_buffer2); }
    if( l_temp_buffer3 ) { free(l_temp_buffer3); }

#ifdef CONFIG_SECUREBOOT
    // securely unload HCODE PNOR section, if necessary
    if ( unload_hcode_pnor_section == true )
    {
        l_errl = unloadSecureSection(PNOR::HCODE);
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"host_build_stop_image() - Error from "
                       "unloadSecureSection(PNOR::HCODE)");

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit error
            errlCommit( l_errl, ISTEP_COMP_ID );
        }
    }
#endif


    if(l_pVirtMemBase)
    {
        int rc = 0;
        rc =  mm_block_unmap(l_pVirtMemBase);
        if (rc != 0)
        {
            /*@
             * @errortype
             * @reasoncode   ISTEP::RC_MM_UNMAP_ERR
             * @moduleid     ISTEP::MOD_BUILD_HCODE_IMAGES
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @userdata1    Return Code
             * @userdata2    Unmap address
             * @devdesc      mm_block_unmap() returns error
             * @custdesc    A problem occurred during the IPL
             *              of the system.
             */
            l_errl =
              new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP::MOD_BUILD_HCODE_IMAGES,
                                      ISTEP::RC_MM_UNMAP_ERR,
                                      rc,
                                      reinterpret_cast<uint64_t>
                                      (l_pVirtMemBase));

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit error
            errlCommit( l_errl, ISTEP_COMP_ID );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_build_stop_image exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
