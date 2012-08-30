/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/build_winkle_images.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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

#include    <sys/misc.h>                        //  cpu_thread_count()
#include    <vfs/vfs.H>                         // PORE image

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/initsvcreasoncodes.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    <devicefw/userif.H>
#include    <mvpd/mvpdenums.H>
#include    <mvpd/mvpdreasoncodes.H>

#include    "build_winkle_images.H"

//  Uncomment these files as they become available:
#include    "proc_slw_build/proc_slw_build.H"
#include    "proc_set_pore_bar/proc_set_pore_bar.H"

namespace   BUILD_WINKLE_IMAGES
{

using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   DeviceFW;

// @@@@@    CUSTOM BLOCK:   @@@@@

/**
 *  @def pointer to area for output PORE image
 *  @todo - make system call to allocate 512k - 1M of space to put output
 *          image for the master chip.
 *          Currently hardwired to 0x400000
 */

/**
 *  @brief Load PORE image and return a pointer to it, or NULL
 *
 *  @param[in]  -   target pointer - pointer to the processor target,
 *                  eventually we will need to know which processor to know
 *                  which image to load.
 *  @param[out] -   address of the PORE image
 *  @param[out] -   size of the PORE image
 *
 *  @return      NULL if success, errorlog if failure
 *
 *  @todo   $$ Add code to UNload this image/module when all the
 *          HWP's are finished.
 *
 */
errlHndl_t  loadPoreImage( const TARGETING::Target  *i_CpuTarget,
                           const char               *& o_rporeAddr,
                            size_t                  & o_rporeSize )
{
    errlHndl_t  l_errl      =   NULL;
    const char * fileName   =   "procpore.dat";

    /**
     *  @todo add code here later to look up the IDEC of the processor and
     *  load the appropriate PORE image.  Currently we just have the single
     *  image.
    */

    do
    {
        // Load the file
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Load PORE file %s",
                   fileName  );
        l_errl = VFS::module_load( fileName );

        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: opening binary PORE file: %s",
                       fileName );

            //  quit and return errorlog
            break;
        }

        // Get the starting address of the file/module
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Get starting address/size" );

        l_errl = VFS::module_address( fileName,
                                      o_rporeAddr,
                                      o_rporeSize );
        if ( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR: getting address of binary PORE file : %s",
                       fileName );

            // quit and return errorlog
            break;
        }

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "PORE addr = 0x%p, size=0x%x",
                   o_rporeAddr,
                   o_rporeSize  );

    } while ( 0 );

    return  l_errl;
}


/**
 * @brief   apply cpu reg information to the SLW image using
 *          p8_pore_gen_cpureg() .
 *
 * @param io_image      -   pointer to the SLW image
 * @param i_sizeImage   -   size of the SLW image
 *
 * @return errorlog if error, NULL otherwise.
 *
 *  @todo   $$ pore_gen_cpu_reg not supported this sprint (???), leave main code
 *          commented out for now.
 *  @todo   $$ l_regname is defined as "unswizzled spr value" ????
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
                        true );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "applyPoreGenCpuRegs: Process cores=0x%x, threads=0x%x",
               l_coreIds.size(),
               cpu_thread_count() );

#if 1
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
           "applyPoreGenCpuRegs: DISABLED until pore_gen_cpureg integration" );

    //  $$ this will be turned on when we integrate pore_gen_cpureg
    //  $$   @todo RTC 41425
#else
    size_t      l_threadid  =   0;
    size_t      l_coreid    =   0;
    uint32_t    l_rc        =   0;
    uint64_t    l_msrcVal   =   cpu_spr_value(CPU_SPR_MSRC) ;
    uint64_t    l_lpcrVal   =   cpu_spr_value(CPU_SPR_LPCR) ;
    uint64_t    l_hrmorVal  =   cpu_spr_value(CPU_SPR_HRMOR);
    for ( l_coreid=0; l_coreid < l_coreIds.size(); l_coreid++ )
    {
        for ( l_threadid=0; l_threadid < cpu_thread_count(); l_threadid++ )
        {

            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "core=0x%x,thread=0x%x: ",
                       l_coreid,
                       l_threadid );
            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "msrc=0x%x,lpcr=0x%x,hrmor=0x%x",
                       l_msrcVal,
                       l_lpcrVal,
                       l_hrmorVal  );
            do  {
                l_rc =  p8_pore_gen_cpureg( io_image,
                                            i_sizeImage,
                                            l_regName,
                                            l_msrcVal,
                                            l_coreid,
                                            l_threadid);
                if ( l_rc )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "p8_pore_gen_cpu_reg ERROR: MSRC: core=0x%x,thread=0x%x,l_rc=0x%x",
                               l_coreId,
                               l_threadId,
                               l_rc );
                    break;
                }

                l_rc =  p8_pore_gen_cpureg( io_image,
                                            i_sizeImage,
                                            l_regName,
                                            l_lpcrVal,
                                            l_coreid,
                                            l_threadid);
                if ( l_rc )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "p8_pore_gen_cpu_reg ERROR: LPCR: core=0x%x,thread=0x%x,l_rc=0x%x",
                               l_coreId,
                               l_threadId,
                               l_rc );
                    break;
                }

                l_rc =  p8_pore_gen_cpureg( io_image,
                                            i_sizeImage,
                                            l_regName,
                                            l_hrmorVal,
                                            l_coreid,
                                            l_threadid);
                if ( l_rc ){
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "p8_pore_gen_cpu_reg ERROR: HRMOR: core=0x%x,thread=0x%x,l_rc=0x%x",
                               l_coreId,
                               l_threadId,
                               l_rc );
                    break;
                }


            } while (0);

            if ( l_rc ){
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "p8_pore_gen_cpu_reg ERROR: core=0x%x, thread=0x%x, l_rc=0x%x",
                           l_coreId,
                           l_threadId,
                           l_rc );
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
                l_errl =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        ISTEP_BUILD_WINKLE_IMAGES,
                                        ISTEP_BAD_RC,
                                        l_rc  );
            }
        }   // end for l_threadId
    }   // end for l_coreId
#endif

    return  l_errl;
}

//
//  Wrapper function to call 15.1 :
//      host_build_winkle
//
void    call_host_build_winkle( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    const char                  *l_pPoreImage   =   NULL;
    size_t                      l_poreSize      =   0;
    void                        *l_pImageOut    =   NULL;
    uint32_t                    l_sizeImageOut  =   MAX_OUTPUT_PORE_IMG_SIZE;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_build_winkle entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@

    // find the master core, i.e. the one we are running on
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Find master chip: " );

    const TARGETING::Target*  l_masterCore  = getMasterCore( );
    assert( l_masterCore != NULL );

    TARGETING::Target* l_cpu_target = const_cast<TARGETING::Target *>
                                            ( getParentChip( l_masterCore ) );

    //  dump physical path to target
    EntityPath l_path;
    l_path  =   l_cpu_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    do {

        l_errl  =   loadPoreImage(  l_cpu_target,
                                    l_pPoreImage,
                                    l_poreSize );
        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_build_winkle ERROR : Returning errorlog, PLID=0x%x",
                      l_errl->plid() );
            // drop out of loop and return errlog to fail.
            break;
        }
        //
        //  @todo stub - eventually this will make a system call to get storage
        //  ( and size ) for the output buffer for PORE image for this CPU.
        //  Save the results in attributes so that other isteps/substeps can
        //  use it.
        //
        //  @NOTE NOTE NOTE
        //  This address must be on a 1-meg boundary.
        //
        l_pImageOut =   reinterpret_cast<void * const >(OUTPUT_PORE_IMG_ADDR);
        l_cpu_target->setAttr<TARGETING::ATTR_SLW_IMAGE_ADDR>
                                                    ( OUTPUT_PORE_IMG_ADDR );

        l_sizeImageOut  =   MAX_OUTPUT_PORE_IMG_SIZE;
        l_cpu_target->setAttr<TARGETING::ATTR_SLW_IMAGE_SIZE>
                                                ( MAX_OUTPUT_PORE_IMG_SIZE );

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target(
                                TARGET_TYPE_PROC_CHIP,
                                reinterpret_cast<void *>
                                              (const_cast<TARGETING::Target*>
                                                            (l_cpu_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         proc_slw_build,
                         l_fapi_cpu_target,
                         reinterpret_cast<const void*>(l_pPoreImage),
                         static_cast<uint32_t>(l_poreSize),
                         l_pImageOut,
                         &l_sizeImageOut
                       );
        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_build_winkle ERROR : Returning errorlog, PLID=0x%x",
                      l_errl->plid() );
            //  drop out if we hit an error and quit.
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "host_build_winkle SUCCESS : out image size = 0x%x ",
                       l_sizeImageOut );
        }

        //  set the actual size of the image now.
        l_cpu_target->setAttr<TARGETING::ATTR_SLW_IMAGE_SIZE>
                                                        ( l_sizeImageOut );

        //  apply the cpu reg information to the image.
        l_errl =   applyPoreGenCpuRegs( l_cpu_target,
                                        l_pImageOut,
                                        l_sizeImageOut );
        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "applyPoreGenCpuRegs ERROR : Returning errorlog, PLID=0x%x",
                      l_errl->plid() );
            //  drop out if we hit an error and quit.
            break;
        }

    }   while (0);  // end do block

    // @@@@@    END CUSTOM BLOCK:   @@@@@


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_build_winkle exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 15.2 :
//      proc_set_pore_bar
//
void    call_proc_set_pore_bar( void    *io_pArgs )
{
    errlHndl_t  l_errl      =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_set_pore_bar entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@

    const TARGETING::Target*  l_masterCore  = TARGETING::getMasterCore( );
    assert( l_masterCore != NULL );

    TARGETING::Target* l_cpu_target = const_cast<TARGETING::Target *>
                                      ( getParentChip( l_masterCore ) );

    //  dump physical path to target
    EntityPath l_path;
    l_path  =   l_cpu_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    do  {

        //  fetch image location and size, written by host_build_winkle above

        //  Note that the "i_mem_bar" input to proc_set_pore_bar is the physical
        //  address of the PORE image, this is the image that will get executed
        //  at winkle.  The void * i_image parameter actually points to the same
        //  place in HostBoot; in fsp or cronus these will be different.
        //
        //  @todo this may change for secure boot, need to make up an RTC
        //      to handle this, or there may one already???
        //
        uint64_t l_imageAddr =
        l_cpu_target->getAttr<TARGETING::ATTR_SLW_IMAGE_ADDR>();


        // Size in Meg of the image, this is rounded up to the nearest power
        //  of 2.  So far our images are less than 1 meg so this is 1
        uint64_t l_mem_size =  1;

        //  defined in proc_set_pore_bar.H
        uint32_t        l_mem_type  =   SLW_L3 ;

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target(
                                            TARGET_TYPE_PROC_CHIP,
                                            reinterpret_cast<void *>
                                            (const_cast<TARGETING::Target*>
                                             (l_cpu_target)) );

        //  call the HWP with each fapi::Target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call proc_set_pore_bar, membar=0x%lx, size=0x%lx, mask=0x%lx, type=0x%x",
                   l_imageAddr,
                   (l_cpu_target->getAttr<ATTR_SLW_IMAGE_SIZE>()),
                   l_mem_size,
                   l_mem_type );


        void * const l_pImage = reinterpret_cast<void * const>(l_imageAddr);

        FAPI_INVOKE_HWP( l_errl,
                         proc_set_pore_bar,
                         l_fapi_cpu_target,
                         l_pImage,
                         l_imageAddr,
                         l_mem_size,
                         l_mem_type
                       );

        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_set_pore_bar, PLID=0x%x",
                      l_errl->plid()  );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : proc_set_pore_bar" );
        }

    }   while ( 0 ); // end do block

    // @@@@@    END CUSTOM BLOCK:   @@@@@


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_set_pore_bar exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}


};   // end namespace
