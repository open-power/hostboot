/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep15/host_build_stop_image.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

//Error handling and tracing
#include    <errl/errlentry.H>
#include    <errl/errluserdetails.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
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
        // Get WINK PNOR section info from PNOR RP
        l_errl = PNOR::getSectionInfo( PNOR::WINK, l_info );
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
    uint64_t    l_msrVal    =   cpu_spr_value(CPU_SPR_MSR) ;
    uint64_t    l_lpcrVal   =   cpu_spr_value( CPU_SPR_LPCR);

    // See LPCR def, PECE "reg" in Power ISA AS Version: Power8 June 27, 2012
    //  and 23.7.3.5 - 6 in Murano Book 4
    l_lpcrVal   &=  ~(0x0000000000002000) ;

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

        //Call p9_stop_save_cpureg from p9_stop_api to store the MSR SPR value
        l_rc = p9_stop_save_cpureg( io_image,
                                    P9_STOP_SPR_MSR,
                                    l_msrVal,
                                    l_pirVal);
        if ( l_rc )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: MSR: core=0x%x,thread=0x%x,l_rc=0x%x",
                       l_coreId, l_threadId, l_rc );
            l_failAddr = P9_STOP_SPR_MSR;
            break;
        }


        //Call p9_stop_save_cpureg from p9_stop_api to store the HRMOR SPR value
        l_rc = p9_stop_save_cpureg( io_image,
                                    P9_STOP_SPR_HRMOR,
                                    l_hrmorVal,
                                    l_pirVal);

        if ( l_rc ){
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: HRMOR: core=0x%x,thread=0x%x,l_rc=0x%x",
                       l_coreId, l_threadId, l_rc );
            l_failAddr = P9_STOP_SPR_HRMOR;
            break;
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
            l_pirVal |= l_threadId;

            //Call p9_stop_save_cpureg from p9_stop_api
            //to store the LPCR SPR value
            l_rc = p9_stop_save_cpureg( io_image,
                                        P9_STOP_SPR_LPCR,
                                        l_lpcrVal,
                                        l_pirVal);
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

    char*       l_pHcodeImage     = NULL;
    void*       l_pRealMemBase   = NULL;
    void*       l_pVirtMemBase   = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_build_stop_image entry" );

    // allocate a temporary buffer
    void* l_temp_buffer = malloc(FIXED_RING_BUF_SIZE);


    do  {
        // Get the node-offset for our instance by looking at the HRMOR
        uint64_t l_memBase = cpu_spr_value(CPU_SPR_HRMOR);
        // mask off the secureboot offset
        l_memBase = 0xFFFFF00000000000 & l_memBase;

        // Now offset up to our hardcoded region
        l_memBase += VMM_HOMER_REGION_START_ADDR;

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
                   "HOMER base = %x", l_memBase);

        l_pRealMemBase = reinterpret_cast<void * const>(l_memBase );

        //Convert the real memory pointer to a pointer in virtual memory
        l_pVirtMemBase =
              mm_block_map(l_pRealMemBase, VMM_HOMER_REGION_SIZE);

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Got virtual mem  buffer for %d cpus = 0x%p",
                   P9_MAX_PROCS,
                   l_pVirtMemBase  );

        //  Continue, build hcode images

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


        //  Loop through all functional Procs and generate images for them.
        TARGETING::TargetHandleList l_procChips;
        getAllChips( l_procChips,
                     TARGETING::TYPE_PROC   );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Found %d procs in system",
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

                //  set default values, p9_hcode_build will provide actual size
                l_procChip->setAttr<TARGETING::ATTR_HCODE_IMAGE_ADDR>
                                                        ( l_procRealMemAddr );
                l_procChip->setAttr<TARGETING::ATTR_HCODE_IMAGE_SIZE>
                                                        ( l_sizeImageOut ) ;

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Real mem  buffer for cpu 0x%08x = %p, virtAddr=%p",
                           l_procNum,
                           l_procRealMemAddr,
                           l_pImageOut);

                // cast OUR type of target to a FAPI2 type of target.
                const fapi2::Target<TARGET_TYPE_PROC_CHIP>
                l_fapiCpuTarget( const_cast<TARGETING::Target*>(l_procChip));

                ImageType_t img_type;

                //Call p9_hcode_image_build.C HWP
                FAPI_INVOKE_HWP( l_errl,
                                 p9_hcode_image_build,
                                 l_fapiCpuTarget, //Proc chip target.
                                 reinterpret_cast<void*>(l_pHcodeImage),
                                 l_pImageOut,
                                 PHASE_IPL, //sys_Phase
                                 img_type,
                                 l_temp_buffer)
                if ( l_errl )
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "host_build_stop_image ERROR : errorlog PLID=0x%x",
                              l_errl->plid() );

                    //  drop out of block with errorlog.
                    break;
                }


                //  set the actual size of the image now.
                l_procChip->setAttr<TARGETING::ATTR_HCODE_IMAGE_SIZE>
                ( l_sizeImageOut );

                l_errl =   applyHcodeGenCpuRegs( l_procChip,
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
    if( l_temp_buffer ) { free(l_temp_buffer); }

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
