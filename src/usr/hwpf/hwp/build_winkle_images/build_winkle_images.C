/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/build_winkle_images.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#include    <sys/mmio.h>            // mmio_dev_map
#include    <sys/mm.h>              // mm_linear_map

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
#include    "p8_pm.H"                               //  PM_INIT
#include    "p8_set_pore_bar/p8_poreslw_init.H"
#include    "p8_slw_build/sbe_xip_image.h"


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
errlHndl_t  loadPoreImage(  const char              *& o_rporeAddr,
                            uint32_t                 & o_rporeSize )
{
    errlHndl_t l_errl = NULL;
    PNOR::SectionInfo_t l_info;
    int64_t rc = 0;
    o_rporeSize = 0;

    do
    {
        // Get WINK PNOR section info from PNOR RP
        l_errl = PNOR::getSectionInfo( PNOR::WINK,PNOR::CURRENT_SIDE, l_info );
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
             * @devdesc     Image from PNOR WINK partion invalid, too small,
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

        o_rporeAddr = reinterpret_cast<const char*>(l_info.vaddr);

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
 * @param i_cpuTarget   -   proc target
 * @param io_image      -   pointer to the SLW image
 * @param i_sizeImage   -   size of the SLW image
 *
 * @return errorlog if error, NULL otherwise.
 *
 */
errlHndl_t  applyPoreGenCpuRegs(   TARGETING::Target *i_cpuTarget,
                                   void      *io_image,
                                   uint32_t  i_sizeImage )
{
    errlHndl_t  l_errl      =   NULL;

    TARGETING::TargetHandleList l_coreIds;
    getChildChiplets(   l_coreIds,
                        i_cpuTarget,
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
    uint64_t    l_msrVal    =   cpu_spr_value(CPU_SPR_MSR) ;

    uint64_t    l_lpcrVal   =   cpu_spr_value( CPU_SPR_LPCR);
    //  Per Greg Still,
    //  Decrementer exceptions (bit 50) should be disabled when the system
    // comes out of winkle.
    // See LPCR def, PECE "reg" in Power ISA AS Version: Power8 June 27, 2012
    //  and 23.7.3.5 - 6 in Murano Book 4
    l_lpcrVal   &=  ~(0x0000000000002000) ;

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
        l_rc =  p8_pore_gen_cpureg( io_image,
                                    i_sizeImage,
                                    P8_MSR_MSR,
                                    l_msrVal,
                                    l_coreId,
                                    l_threadId);
        if ( l_rc )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: MSR: core=0x%x,thread=0x%x,l_rc=0x%x",
                       l_coreId, l_threadId, l_rc );
            break;
        }

        l_rc =  p8_pore_gen_cpureg( io_image,
                                    i_sizeImage,
                                    P8_SPR_HRMOR,
                                    l_hrmorVal,
                                    l_coreId,
                                    l_threadId);
        if ( l_rc ){
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: HRMOR: core=0x%x,thread=0x%x,l_rc=0x%x",
                       l_coreId, l_threadId, l_rc );
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

            l_rc =  p8_pore_gen_cpureg( io_image,
                                        i_sizeImage,
                                        P8_SPR_LPCR,
                                        l_lpcrVal,
                                        l_coreId,
                                        l_threadId);
            if ( l_rc )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR: LPCR: core=0x%x,thread=0x%x,l_rc=0x%x",
                           l_coreId, l_threadId, l_rc );
                break;
            }
        }   // end for l_threadId

        //  if error writing thread break out of l_coreId loop
        if ( l_rc )
        {
            break;
        }
    }   // end for l_coreIds

    if ( l_rc ){
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR: core=0x%x, thread=0x%x, l_rc=0x%x",
                   l_coreId, l_threadId, l_rc );
        /*@
         * @errortype
         * @reasoncode  ISTEP_BAD_RC
         * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    ISTEP_BUILD_WINKLE_IMAGES
         * @userdata1   return code from p8_pore_gen_cpureg
         *
         * @devdesc p8_pore_gen_cpureg returned an error when
         *          attempting to change a reg value in the PORE image.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                ISTEP::ISTEP_BUILD_WINKLE_IMAGES,
                                ISTEP::ISTEP_BAD_RC,
                                l_rc  );
    }

    return  l_errl;
}

//
//  Wrapper function to call host_build_winkle
//
void*    call_host_build_winkle( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    const char  *l_pPoreImage   =   NULL;
    uint32_t    l_poreSize      =   0;
    void        *l_pRealMemBase =
                        reinterpret_cast
                 <void * const>(VMM_HOMER_REGION_START_ADDR );
#if 0
    //TODO RTC 71081 - enabled when switching to dev_map
    void* l_pVirtMemBase = NULL;
#endif
    ISTEP_ERROR::IStepError     l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_build_winkle entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@

    do  {
        //  Get a chunk of real memory big enough to store all the possible
        //  SLW images.

        //Assert if anyone ever changes VMM_HOMER_REGION_SIZE to not
        //equal 32MB because mmio_dev_map won't support it
        assert(VMM_HOMER_REGION_SIZE == THIRTYTWO_MB,
               "host_build_winkle: Unsupported HOMER Region size");

#if 0
        //TODO RTC: 71081 change to non-cache inhibited
        //version of mmio_dev_map
        l_pVirtMemBase =
              mmio_dev_map(l_pRealMemBase, THIRTYTWO_MB);

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Got virtual mem  buffer for %d cpus = 0x%p",
                   P8_MAX_PROCS,
                   l_pVirtMemBase  );
#else
        const int l_getAddrRc = mm_linear_map (l_pRealMemBase,
                                               THIRTYTWO_MB);
        if(l_getAddrRc != 0)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"host_build_winkle ERROR : could not get real mem");
            assert(false);
            // drop out of do block with errorlog.
            break;
        }
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Got virtual mem  buffer for %d cpus = 0x%p",
                   P8_MAX_PROCS,
                   l_pRealMemBase  );

#endif
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
#if 0
                //TODO RTC: 71081 - change to use virtual offset
                //when switched to mmio_dev_map type interface.
                void *l_pImageOut =
                  reinterpret_cast<void * const>
                  (reinterpret_cast<uint64_t>(l_pVirtMemBase)
                   + l_procOffsetAddr) ;
#else
                 void *l_pImageOut =
                   reinterpret_cast<void * const>(l_procRealMemAddr);
#endif
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
                                 p8_slw_build,
                                 l_fapi_cpu_target,
                                 reinterpret_cast<const void*>(l_pPoreImage),
                                 l_poreSize,
                                 l_pImageOut,
                                 &l_sizeImageOut
                               );
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

                /*@
                 * @errortype
                 * @reasoncode  ISTEP_BUILD_WINKLE_IMAGES_FAILED
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_HOST_BUILD_WINKLE
                 * @userdata1       bytes 0-1: plid identifying first error
                 *                  bytes 2-3: reason code of first error
                 * @userdata2       bytes 0-1: total number of elogs included
                 *                  bytes 2-3: N/A
                 * @devdesc     Call to host_build_winkle has failed.
                 *              See user data for failing processor information
                 *
                 */
                l_StepError.addErrorDetails(
                                        ISTEP::ISTEP_BUILD_WINKLE_IMAGES_FAILED,
                                        ISTEP::ISTEP_HOST_BUILD_WINKLE,
                                        l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
            }

        } ;  // endfor

    }  while (0);
    // @@@@@    END CUSTOM BLOCK:   @@@@@

#if 0
    //TODO RTC 71081 - enable when switching to dev_map
    // interface
    if(l_pVirtMemBase)
    {
        int rc = 0;
        rc =  mmio_dev_unmap(l_pVirtMemBase);
        if (rc != 0)
        {
            /*@
             * @errortype
             * @reasoncode   ISTEP::ISTEP_MMIO_UNMAP_ERR
             * @moduleid     ISTEP::ISTEP_BUILD_WINKLE_IMAGES
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @userdata1    Return Code
             * @userdata2    Unmap address
             * @devdesc      mmio_dev_unmap() returns error
             */
            l_errl =
              new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP::ISTEP_BUILD_WINKLE_IMAGES,
                                      ISTEP::ISTEP_MMIO_UNMAP_ERR,
                                      rc,
                                      reinterpret_cast<uint64_t>
                                      (l_pVirtMemBase));

            /*@
             * @errortype
             * @reasoncode  ISTEP_MMIO_UNMAP_ERR
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_HOST_BUILD_WINKLE
             * @userdata1       bytes 0-1: plid identifying first error
             *                  bytes 2-3: reason code of first error
             * @userdata2       bytes 0-1: total number of elogs included
             *                  bytes 2-3: N/A
             * @devdesc     Call to host_build_winkle has failed due to
             *              unmapping of memory.
             *
             */
            l_StepError.addErrorDetails(
                                        ISTEP::ISTEP_MMIO_UNMAP_ERR,
                                        ISTEP::ISTEP_HOST_BUILD_WINKLE,
                                        l_errl );
            errlCommit( l_errl, HWPF_COMP_ID );
        }
    }
#endif

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
        //  at winkle.  The void * i_image parameter actually points to the same
        //  place in HostBoot; in fsp or cronus these will be different.
        //
        //  @todo this may change for secure boot, need to make up an RTC
        //      to handle this, or there may one already???
        //
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


        void * const l_pImage = reinterpret_cast<void * const>(l_imageAddr);

        FAPI_INVOKE_HWP( l_errl,
                         p8_set_pore_bar,
                         l_fapi_cpu_target,
                         l_pImage,
                         l_imageAddr,
                         l_mem_size,
                         l_mem_type
                       );

        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : p8_set_pore_bar, PLID=0x%x",
                      l_errl->plid()  );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_procChip).addToLog( l_errl );

            /*@
             * @errortype
             * @reasoncode       ISTEP_BUILD_WINKLE_IMAGES_FAILED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         ISTEP_PROC_SET_PORE_BAR
             * @userdata1       bytes 0-1: plid identifying first error
             *                  bytes 2-3: reason code of first error
             * @userdata2       bytes 0-1: total number of elogs included
             *                  bytes 2-3: N/A
             * @devdesc          call to proc_set_porebar has failed, see
             *                   error log identified by the plid in user
             *                   data section.
             */
            l_stepError.addErrorDetails(ISTEP_BUILD_WINKLE_IMAGES_FAILED,
                                        ISTEP_PROC_SET_PORE_BAR,
                                        l_errl );

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

            /*@
             * @errortype
             * @reasoncode       ISTEP_P8_PORESLW_INIT_FAILED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         ISTEP_PROC_PORESLW_INIT
             * @userdata1       bytes 0-1: plid identifying first error
             *                  bytes 2-3: reason code of first error
             * @userdata2       bytes 0-1: total number of elogs included
             *                  bytes 2-3: N/A
             * @devdesc          call to proc_set_porebar has failed, see
             *                   error log identified by the plid in user
             *                   data section.
             */
            l_stepError.addErrorDetails(ISTEP_P8_PORESLW_INIT_FAILED,
                                        ISTEP_PROC_PORESLW_INIT,
                                        l_errl );

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
