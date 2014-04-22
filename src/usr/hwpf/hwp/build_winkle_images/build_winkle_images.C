/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/build_winkle_images.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file build_winkle_images.C
 *
 *  Support file for IStep: build_winkle_images
 *   Build Winkle Images
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <sys/misc.h>            //  cpu_thread_count(), P8_MAX_PROCS
#include    <vfs/vfs.H>             // PORE image
#include    <sys/mm.h>            // mm_block_map
#include    <sys/mmio.h>          // THIRTYTWO_GB

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/initsvcreasoncodes.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>

#include <pnor/pnorif.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    <devicefw/userif.H>
#include    <vpd/mvpdenums.H>
#include    <vpd/vpdreasoncodes.H>

#include    <hwpf/istepreasoncodes.H>

#include    "build_winkle_images.H"

#include    "p8_slw_build/p8_slw_build.H"
#include    "p8_slw_build/p8_pore_table_gen_api.H"
#include    "p8_set_pore_bar/p8_set_pore_bar.H"
#include    "p8_set_pore_bar/p8_pba_bar_config.H"
#include    "p8_pm.H"                               //  PM_INIT
#include    "p8_set_pore_bar/p8_poreslw_init.H"
#include    "p8_slw_build/sbe_xip_image.h"
#include    <runtime/runtime.H>
#include    "p8_slw_build/p8_image_help_base.H"


namespace   BUILD_WINKLE_IMAGES
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   DeviceFW;


// @@@@@    CUSTOM BLOCK:   @@@@@

/**
 *  @brief Load PORE image and return a pointer to it, or NULL
 *
 *  @param[out] -   address of the PORE image
 *  @param[out] -   size of the PORE image
 *
 *  @return      NULL if success, errorlog if failure
 *
 */
errlHndl_t  loadPoreImage(  char                    *& o_rporeAddr,
                            uint32_t                 & o_rporeSize )
{
    errlHndl_t l_errl = NULL;
    PNOR::SectionInfo_t l_info;
    int64_t rc = 0;
    o_rporeSize = 0;

    do
    {
        // Get WINK PNOR section info from PNOR RP
        l_errl = PNOR::getSectionInfo( PNOR::WINK, l_info );
        if( l_errl )
        {
            break;
        }

        rc = sbe_xip_image_size(reinterpret_cast<void*>(l_info.vaddr),
                                &o_rporeSize);
        if((rc !=0) || (o_rporeSize == 0) || o_rporeSize > l_info.size)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR: invalid WINK image rc[%d] slwSize[%d] part size[%d]",
                       rc, o_rporeSize, l_info.size);
            /*@
             * @errortype
             * @reasoncode  ISTEP_LOAD_SLW_FROM_PNOR_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_BUILD_WINKLE_IMAGES
             * @userdata1   Hi 32 bits: return code from sbe_xip_image_size
             *              Lo 32 bits: Size of memory requested
             * @userdata2   Size of WINK PNOR partition
             * @devdesc     Image from PNOR WINK partition invalid, too small,
             *              or too big
             */
            l_errl =
              new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       ISTEP::ISTEP_BUILD_WINKLE_IMAGES,
                                       ISTEP::ISTEP_LOAD_SLW_FROM_PNOR_FAILED,
                                       (rc<<32)|o_rporeSize,
                                       l_info.size );
            break;
        }

        o_rporeAddr = reinterpret_cast<char*>(l_info.vaddr);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "WINK addr = 0x%p, size=0x%x",
                   o_rporeAddr,
                   o_rporeSize  );

    } while ( 0 );

    return  l_errl;
}



/**
 * @brief   apply cpu reg information to the SLW image using
 *          p8_pore_gen_cpureg() .
 *
 * @param i_procChipTarg   -   proc target
 * @param io_image      -   pointer to the SLW image
 * @param i_sizeImage   -   size of the SLW image
 *
 * @return errorlog if error, NULL otherwise.
 *
 */
errlHndl_t  applyPoreGenCpuRegs(   TARGETING::Target *i_procChipTarg,
                                   void      *io_image,
                                   uint32_t  i_sizeImage )
{
    errlHndl_t  l_errl      =   NULL;

    TARGETING::TargetHandleList l_coreIds;
    getChildChiplets(   l_coreIds,
                        i_procChipTarg,
                        TYPE_CORE,
                        false );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "applyPoreGenCpuRegs: Process cores=0x%x, threads=0x%x",
               l_coreIds.size(),
               cpu_thread_count() );

    const size_t l_cpu_thread_count = cpu_thread_count();
    TARGETING::ATTR_CHIP_UNIT_type l_coreId    =   0;
    size_t      l_threadId  =   0;
    uint32_t    l_rc        =   0;
    uint32_t    l_failAddr  =   0;

    uint64_t    l_msrVal    =   cpu_spr_value(CPU_SPR_MSR) ;

    uint64_t    l_lpcrVal   =   cpu_spr_value( CPU_SPR_LPCR);
    //  Per Greg Still,
    //  Decrementer exceptions (bit 50) should be disabled when the system
    // comes out of winkle.
    // See LPCR def, PECE "reg" in Power ISA AS Version: Power8 June 27, 2012
    //  and 23.7.3.5 - 6 in Murano Book 4
    l_lpcrVal   &=  ~(0x0000000000002000) ;

    // Core FIR Action1 Register value from Nick
    const uint64_t action1_reg = 0xEA5C139705980000;

    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    assert( sys != NULL );
    uint64_t en_threads = sys->getAttr<ATTR_ENABLED_THREADS>();

    uint64_t    l_hrmorVal  =   cpu_spr_value(CPU_SPR_HRMOR);
    for (TargetHandleList::const_iterator
            l_coreIds_iter = l_coreIds.begin();
            l_coreIds_iter != l_coreIds.end();
            ++l_coreIds_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_core = *l_coreIds_iter;

        // write the HUID of the core we are writing to
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_core));

        l_coreId = l_core->getAttr<ATTR_CHIP_UNIT>();

        //  msr and hrmor are common across all threads, only set for thread 0
        //  on each core
        l_threadId  =   0;
        l_rc =  p8_pore_gen_cpureg_fixed( io_image,
                                          P8_SLW_MODEBUILD_IPL,
                                          P8_MSR_MSR,
                                          l_msrVal,
                                          l_coreId,
                                          l_threadId);
        if ( l_rc )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: MSR: core=0x%x,thread=0x%x,l_rc=0x%x",
                       l_coreId, l_threadId, l_rc );
            l_failAddr = P8_MSR_MSR;
            break;
        }

        l_rc =  p8_pore_gen_cpureg_fixed( io_image,
                                          P8_SLW_MODEBUILD_IPL,
                                          P8_SPR_HRMOR,
                                          l_hrmorVal,
                                          l_coreId,
                                          l_threadId);
        if ( l_rc ){
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: HRMOR: core=0x%x,thread=0x%x,l_rc=0x%x",
                       l_coreId, l_threadId, l_rc );
            l_failAddr = P8_SPR_HRMOR;
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
                       "applyPoreGenCpuRegs: core=0x%x,thread=0x%x: ",
                       l_coreId, l_threadId );
            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "applyPoreGenCpuRegs: msrc=0x%x,lpcr=0x%x,hrmor=0x%x",
                       l_msrVal, l_lpcrVal, l_hrmorVal  );

            l_rc =  p8_pore_gen_cpureg_fixed( io_image,
                                              P8_SLW_MODEBUILD_IPL,
                                              P8_SPR_LPCR,
                                              l_lpcrVal,
                                              l_coreId,
                                              l_threadId);
            if ( l_rc )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR: LPCR: core=0x%x,thread=0x%x,l_rc=0x%x",
                           l_coreId, l_threadId, l_rc );
                l_failAddr = P8_SPR_LPCR;
                break;
            }
        }   // end for l_threadId

        //  if error writing thread break out of l_coreId loop
        if ( l_rc )
        {
            break;
        }

        // Need to force core checkstops to escalate to a system checkstop
        //  by telling the SLW to update the ACTION1 register when it
        //  comes out of winkle  (see HW286670)
        l_rc = p8_pore_gen_scom_fixed( io_image,
                                       P8_SLW_MODEBUILD_IPL,
                                       EX_CORE_FIR_ACTION1_0x10013107,
                                       l_coreId,
                                       action1_reg,
                                       P8_PORE_SCOM_REPLACE,
                                       P8_SCOM_SECTION_NC );
        if( l_rc )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: ACTION1: core=0x%x,l_rc=0x%x",
                       l_coreId, l_rc );
            l_failAddr = EX_CORE_FIR_ACTION1_0x10013107;
            break;
        }

    }   // end for l_coreIds

    if ( l_rc ){
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR: p8_pore_gen api fail core=0x%x, thread=0x%x, l_rc=0x%x",
                   l_coreId, l_threadId, l_rc );
        /*@
         * @errortype
         * @reasoncode  ISTEP_BAD_RC
         * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    ISTEP_BUILD_WINKLE_IMAGES
         * @userdata1[00:31]  return code from p8_pore_gen_xxx function
         * @userdata1[32:63]  address being added to image
         * @userdata2[00:31]  Failing Core Id
         * @userdata2[32:63]  Failing Thread Id
         *
         * @devdesc p8_pore_gen_xxx returned an error when
         *          attempting to change a reg value in the PORE image.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                ISTEP::ISTEP_BUILD_WINKLE_IMAGES,
                                ISTEP::ISTEP_BAD_RC,
                                TWO_UINT32_TO_UINT64(l_rc,l_failAddr),
                                TWO_UINT32_TO_UINT64(l_coreId,l_threadId) );
        l_errl->collectTrace(FAPI_TRACE_NAME,256);
        l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
        l_errl->collectTrace("ISTEPS_TRACE",256);
    }

    return  l_errl;
}

//
// Utility function to obtain the highest known address in the system
//
uint64_t get_top_mem_addr(void)
{
    uint64_t top_addr = 0;

    do
    {
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for ( size_t proc = 0; proc < l_cpuTargetList.size(); proc++ )
        {
            TARGETING::Target * l_pProc = l_cpuTargetList[proc];

            //Not checking success here as fail results in no change to
            // top_addr
            uint64_t l_mem_bases[8] = {0,};
            uint64_t l_mem_sizes[8] = {0,};
            l_pProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_mem_bases);
            l_pProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_mem_sizes);

            for (size_t i=0; i< 8; i++)
            {
                if(l_mem_sizes[i]) //non zero means that there is memory present
                {
                    top_addr = std::max(top_addr,
                                        l_mem_bases[i] + l_mem_sizes[i]);
                }
            }
        }
    }while(0);

    return top_addr;
}

//
//  Wrapper function to call host_build_winkle
//
void*    call_host_build_winkle( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    char  *l_pPoreImage   =   NULL;
    uint32_t    l_poreSize      =   0;
    void        *l_pRealMemBase = NULL;
    void* l_pVirtMemBase        = NULL;

    ISTEP_ERROR::IStepError     l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_build_winkle entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@

    // allocate some working buffers
    void* l_rs4_tmp = malloc(FIXED_RING_BUF_SIZE);
    void* l_wf_tmp = malloc(FIXED_RING_BUF_SIZE);


    do  {
        // Get the node-offset for our instance by looking at the HRMOR
        uint64_t l_memBase = cpu_spr_value(CPU_SPR_HRMOR);
        // mask off the secureboot offset
        l_memBase = 0xFFFFF00000000000 & l_memBase;

        // Now offset up to our hardcoded region
        l_memBase += VMM_HOMER_REGION_START_ADDR;

        //  Get a chunk of real memory big enough to store all the possible
        //  SLW images.

        assert(VMM_HOMER_REGION_SIZE <= THIRTYTWO_GB,
               "host_build_winkle: Unsupported HOMER Region size");

        //If running Sapphire need to place this at the top of memory instead
        if(is_sapphire_load())
        {
            l_memBase = get_top_mem_addr();
            assert (l_memBase != 0,
                    "host_build_winkle: Top of memory was 0!");
            l_memBase -= VMM_ALL_HOMER_OCC_MEMORY_SIZE;
        }
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "HOMER base = %x", l_memBase);

        l_pRealMemBase = reinterpret_cast<void * const>(l_memBase );

        l_pVirtMemBase =
              mm_block_map(l_pRealMemBase, VMM_HOMER_REGION_SIZE);

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Got virtual mem  buffer for %d cpus = 0x%p",
                   P8_MAX_PROCS,
                   l_pVirtMemBase  );

        //  Continue, build SLW images


        //Load the reference image from PNOR
        l_errl  =   loadPoreImage(  l_pPoreImage,
                                    l_poreSize );
        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_build_winkle ERROR : errorlog PLID=0x%x",
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

        for ( TargetHandleList::const_iterator
              l_iter = l_procChips.begin();
              l_iter != l_procChips.end();
              ++l_iter )
        {
            TARGETING::Target * l_procChip  =   (*l_iter) ;

            do  {

                // write the HUID of the core we are writing to
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Build SLW image for proc "
                        "target HUID %.8X", TARGETING::get_huid(l_procChip));


                //  calculate size and location of the SLW output buffer
                uint32_t    l_procNum =
                  l_procChip->getAttr<TARGETING::ATTR_POSITION>();
                uint64_t    l_procOffsetAddr =
                  ( l_procNum *VMM_HOMER_INSTANCE_SIZE ) + HOMER_SLW_IMG_OFFSET;

                uint64_t    l_procRealMemAddr  =
                  reinterpret_cast<uint64_t>(l_pRealMemBase)
                  + l_procOffsetAddr;

                void *l_pImageOut =
                  reinterpret_cast<void * const>
                  (reinterpret_cast<uint64_t>(l_pVirtMemBase)
                   + l_procOffsetAddr) ;

                uint32_t    l_sizeImageOut  =
                  (HOMER_MAX_SLW_IMG_SIZE_IN_MB*MEGABYTE);

                //  set default values, p8_slw_build will provide actual size
                l_procChip->setAttr<TARGETING::ATTR_SLW_IMAGE_ADDR>
                                                        ( l_procRealMemAddr );
                l_procChip->setAttr<TARGETING::ATTR_SLW_IMAGE_SIZE>
                                                        ( l_sizeImageOut ) ;

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Real mem  buffer for cpu 0x%08x = %p, virtAddr=%p",
                           l_procNum,
                           l_procRealMemAddr,
                           l_pImageOut);

                // cast OUR type of target to a FAPI type of target.
                const fapi::Target l_fapi_cpu_target( TARGET_TYPE_PROC_CHIP,
                                                (const_cast<TARGETING::Target*>
                                                     (l_procChip)) );

                //  call the HWP with each fapi::Target
                FAPI_INVOKE_HWP( l_errl,
                                 p8_slw_build_fixed,
                                 l_fapi_cpu_target, //Proc chip target.
                                 reinterpret_cast<void*>(l_pPoreImage),
                                 l_pImageOut,
                                 l_sizeImageOut,
                                 P8_SLW_MODEBUILD_IPL, //i_modeBuild
                                 l_rs4_tmp,//RS4
                                 FIXED_RING_BUF_SIZE,
                                 l_wf_tmp,//WF
                                 FIXED_RING_BUF_SIZE );
                if ( l_errl )
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "host_build_winkle ERROR : errorlog PLID=0x%x",
                              l_errl->plid() );

                    //  drop out of block with errorlog.
                    break;
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "host_build_winkle SUCCESS : image size = 0x%x ",
                               l_sizeImageOut );
                }

                //  set the actual size of the image now.
                l_procChip->setAttr<TARGETING::ATTR_SLW_IMAGE_SIZE>
                ( l_sizeImageOut );

                //  apply the cpu reg information to the image.
                l_errl =   applyPoreGenCpuRegs( l_procChip,
                                                l_pImageOut,
                                                l_sizeImageOut );
                if ( l_errl )
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "applyPoreGenCpuRegs ERROR : errorlog PLID=0x%x",
                              l_errl->plid() );

                    //  drop out of block with errorlog.
                    break;
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "applyPoreGenCpuRegs SUCCESS " );
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
    if( l_rs4_tmp ) { free(l_rs4_tmp); }
    if( l_wf_tmp ) { free(l_wf_tmp); }

    if(l_pVirtMemBase)
    {
        int rc = 0;
        rc =  mm_block_unmap(l_pVirtMemBase);
        if (rc != 0)
        {
            /*@
             * @errortype
             * @reasoncode   ISTEP::ISTEP_MM_UNMAP_ERR
             * @moduleid     ISTEP::ISTEP_BUILD_WINKLE_IMAGES
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @userdata1    Return Code
             * @userdata2    Unmap address
             * @devdesc      mm_block_unmap() returns error
             */
            l_errl =
              new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP::ISTEP_BUILD_WINKLE_IMAGES,
                                      ISTEP::ISTEP_MM_UNMAP_ERR,
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
               "call_host_build_winkle exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}



//
//  Wrapper function to call p8_set_pore_bar
//
void*    call_proc_set_pore_bar( void    *io_pArgs )
{
    errlHndl_t  l_errl      =   NULL;

    ISTEP_ERROR::IStepError     l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_set_pore_bar entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@

    TARGETING::TargetHandleList l_procChips;
    getAllChips( l_procChips,
                 TARGETING::TYPE_PROC   );

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Found %d procs in system",
               l_procChips.size()   );

    for ( TargetHandleList::const_iterator
          l_iter = l_procChips.begin();
          l_iter != l_procChips.end();
          ++l_iter )
    {
        const TARGETING::Target * l_procChip  =   (*l_iter) ;

        // write the HUID of the core we are writing to
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Set pore bar for "
                "target HUID %.8X", TARGETING::get_huid(l_procChip));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target( TARGET_TYPE_PROC_CHIP,
                            (const_cast<TARGETING::Target*>(l_procChip)) );

        //  fetch image location and size, written by host_build_winkle above

        //  Note that the "i_mem_bar" input to p8_set_pore_bar is the physical
        //  address of the PORE image, this is the image that will get executed
        //  at winkle.
        uint64_t l_imageAddr =
        l_procChip->getAttr<TARGETING::ATTR_SLW_IMAGE_ADDR>();


        //  Size (in MB) of the region where image is located.
        //  This is rounded up to the nearest power of 2 by the HWP.
        //  Easiest way to insure this works right is to set it to a power
        //  of 2;  see vmmconst.H
        uint64_t l_mem_size =  HOMER_MAX_SLW_IMG_SIZE_IN_MB ;

        //  defined in p8_set_pore_bar.H
        uint32_t        l_mem_type  =   SLW_L3 ;


        //  call the HWP with each fapi::Target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "p8_set_pore_bar, mem=0x%lx, sz=0x%lx, msk=0x%lx, type=0x%x",
                   l_imageAddr,
                   (l_procChip->getAttr<ATTR_SLW_IMAGE_SIZE>()),
                   l_mem_size,
                   l_mem_type );


        // Map image.
        void * const l_pImage = reinterpret_cast<void* const>(
                        mm_block_map(reinterpret_cast<void*>(l_imageAddr),
                                     HOMER_MAX_SLW_IMG_SIZE_IN_MB*MEGABYTE));

        FAPI_INVOKE_HWP( l_errl,
                         p8_set_pore_bar,
                         l_fapi_cpu_target,
                         l_pImage,
                         l_imageAddr,
                         l_mem_size,
                         l_mem_type
                       );

        // Unmap
        int rc = mm_block_unmap(l_pImage);
        if ((rc != 0) && (NULL == l_errl)) // The bad rc is lower priority
                                           // than any other error, so just
                                           // ignore it if something else
                                           // happened.
        {
            /*@
             * @errortype
             * @reasoncode   ISTEP::ISTEP_MM_UNMAP_ERR
             * @moduleid     ISTEP::ISTEP_PROC_SET_PORE_BAR
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @userdata1    Return Code
             * @userdata2    Unmap address
             * @devdesc      mm_block_unmap() returns error
             */
            l_errl =
              new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP::ISTEP_PROC_SET_PORE_BAR,
                                      ISTEP::ISTEP_MM_UNMAP_ERR,
                                      rc,
                                      reinterpret_cast<uint64_t>
                                      (l_pImage));
        }

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : p8_set_pore_bar, PLID=0x%x",
                      l_errl->plid()  );
        }
        else
        {
            //No error on previous call, make sure to
            //init PBA BAR 0 to 0s.  This is required on MPIPLs
            //so sapphire can determine when OCC is active.  FSPless
            //it will be active before hostboot hands over control
            //FSP mode it will be loaded in sapphire

            FAPI_INVOKE_HWP( l_errl,
                             p8_pba_bar_config,
                             l_fapi_cpu_target,
                             0,                 //PBA BAR 0
                             0,                 //Addr 0
                             0,                 //Size 0
                             0);                //Cmd 0

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : p8_pba_bar_config, PLID=0x%x",
                          l_errl->plid()  );
            }
        }


        if ( l_errl )
        {
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_procChip).addToLog( l_errl );

            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : p8_set_pore_bar" );
        }

    }   // end for

    // @@@@@    END CUSTOM BLOCK:   @@@@@


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_set_pore_bar exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call p8_poreslw_init
//
void*    call_p8_poreslw_init( void    *io_pArgs )
{
    errlHndl_t  l_errl      =   NULL;

    ISTEP_ERROR::IStepError     l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_p8_poreslw_init entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@


    TARGETING::TargetHandleList l_procChips;
    getAllChips( l_procChips,
                 TARGETING::TYPE_PROC   );

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Found %d procs in system",
               l_procChips.size()   );

    for ( TargetHandleList::const_iterator
          l_iter = l_procChips.begin();
          l_iter != l_procChips.end();
          ++l_iter )
    {
        const TARGETING::Target * l_procChip  =   (*l_iter) ;

        // write the HUID of the core we are writing to
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_procChip));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target( TARGET_TYPE_PROC_CHIP,
                           (const_cast<TARGETING::Target*>(l_procChip)) );

        //
        //  Configure the SLW PORE and related functions to enable idle
        //  operations
        //
        FAPI_INVOKE_HWP( l_errl,
                         p8_poreslw_init,
                         l_fapi_cpu_target,
                         PM_INIT  );
        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : p8_poreslw_init, PLID=0x%x",
                      l_errl->plid()  );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_procChip).addToLog( l_errl );

            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : p8_poreslw_init " );
        }

    }   // end for

    // @@@@@    END CUSTOM BLOCK:   @@@@@


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_p8_poreslw_init exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


};   // end namespace
