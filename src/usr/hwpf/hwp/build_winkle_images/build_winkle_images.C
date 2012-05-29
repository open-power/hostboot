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
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <vfs/vfs.H>                         // PORE image

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/initsvcreasoncodes.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    <devicefw/userif.H>
#include    <mvpd/mvpdenums.H>
#include    <mvpd/mvpdreasoncodes.H>

#include    "build_winkle_images.H"

//  Uncomment these files as they become available:
#include    "proc_slw_build/proc_slw_build.H"
// #include    "proc_set_pore_bar/proc_set_pore_bar.H"

namespace   BUILD_WINKLE_IMAGES
{

using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   DeviceFW;

// @@@@@    CUSTOM BLOCK:   @@@@@

/**
 *  @def pointer to area for output PORE image
 *  @todo - make system call to allocate 512k - 1M of space to put output
 *          image.  Currently hardwired to 0x78000
 *
 */
void    * const g_pOutputPoreImg
                    =   reinterpret_cast<void * const >(OUTPUT_PORE_IMG_ADDR);

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
errlHndl_t  loadPoreImage( TARGETING::Target    *i_CpuTarget,
                           const char           *& o_rporeAddr,
                            size_t      & o_rporeSize )
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

//
//  Wrapper function to call 15.1 :
//      host_build_winkle
//
void    call_host_build_winkle( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;
    uint8_t                     l_cpuNum        =   0;

    const char                  *l_pPoreImage   =   NULL;
    size_t                      l_poreSize      =   0;
    void                        *l_pImageOut    =   NULL;
    uint32_t                    l_sizeImageOut  =   MAX_OUTPUT_PORE_IMG_SIZE;


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_build_winkle entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@

    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)


    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for ( l_cpuNum=0; l_cpuNum < l_cpuTargetList.size(); l_cpuNum++ )
    {
        //  make a local copy of the CPU target
        TARGETING::Target*  l_cpu_target = l_cpuTargetList[l_cpuNum];

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Run cpuNum 0x%x",
                   l_cpuNum  );

        //  dump physical path to target
        EntityPath l_path;
        l_path  =   l_cpu_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

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

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target(
                            TARGET_TYPE_PROC_CHIP,
                            reinterpret_cast<void *>
                            (const_cast<TARGETING::Target*>(l_cpu_target)) );

        //
        //  stub - get address of output buffer for PORE image for this CPU,
        //          and load it there
        //
        l_pImageOut     =   g_pOutputPoreImg;
        l_sizeImageOut  =   MAX_OUTPUT_PORE_IMG_SIZE;


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

    }   // endfor
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
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_set_pore_bar entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, proc_set_pore_bar, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_set_pore_bar exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}


};   // end namespace
