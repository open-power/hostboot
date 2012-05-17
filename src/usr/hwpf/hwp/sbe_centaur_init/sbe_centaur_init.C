//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

/**
 *  @file sbe_centaur_init.C
 *
 *  Support file for IStep:
 *      sbe_centaur_init
 *
 *
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <initservice/isteps_trace.H>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <fapi.H>
#include <fapiPoreVeArg.H>
#include <fapiTarget.H>
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#include <vfs/vfs.H>
#include <list>
#include "sbe_centaur_init.H"

//@todo - The following workarounds need to be readdressed
//1. Avoid running test case in VBU below
//2. To call isSlavePresent(). Need to remove following header when PD works.
#include <fsi/fsiif.H>

// Extern function declaration
extern fapi::ReturnCode fapiPoreVe(const fapi::Target i_target,
                                   std::list<uint64_t> & io_sharedObjectArgs);
// Constants
#define CENTAUR_SBE_PNOR_MRR    0   // Memory Relocation Register for Centaur SBE image

// Name spaces
using namespace TARGETING;
using namespace vsbe;

namespace   SBE_CENTAUR_INIT
{

using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call 10.1 : cen_sbe_tp_chiplet_init1
//
void    call_cen_sbe_tp_chiplet_init1( void *io_pArgs )
{


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init1 entry" );

    // Get target list to pass in procedure
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    bool l_unloadSbePnorImg = false;
    size_t l_sbePnorSize = 0;
    const char * l_sbePnorAddr = NULL;
    errlHndl_t  l_errl = NULL;

    do
    {
        // ----------------------- Setup sbe_pnor stuff --------------------

        // Loading sbe_pnor img
        l_errl = VFS::module_load("sbe_pnor.bin");
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X call_cen_sbe_tp_chiplet_init1 - VFS::module_load(sbe_pnor.bin) returns error",
                    l_errl->reasonCode());
            break;
        }
        else
        {
             // Set flag to unload
             l_unloadSbePnorImg = true;
             l_errl = VFS::module_address("sbe_pnor.bin", l_sbePnorAddr, l_sbePnorSize);
             if(l_errl)
             {
                 TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X call_cen_sbe_tp_chiplet_init1 - VFS::module_address(sbe_pnor.bin) return error",
                         l_errl->reasonCode());
                 break;
             }
             else
             {
                 char l_header[10];
                 memcpy (l_header, l_sbePnorAddr, 9);
                 l_header[9] = '\0';
                 TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init1 -Loading sbe_pnor.bin, Addr 0x%llX, Size %d, Header %s",
                           l_sbePnorAddr, l_sbePnorSize, l_header);
             }
        }

        // Setup args
        std::list<uint64_t> myArgs;

        // Set FapiPoreVeOtherArg: run unlimited instructions
        FapiPoreVeOtherArg *l_otherArg =
                new FapiPoreVeOtherArg(vsbe::RUN_UNLIMITED,
                                       vsbe::PORE_SBE);
        // Entry point
        l_otherArg->iv_entryPoint = const_cast<char*>("pnor::_sbe_pnor_start");
        l_otherArg->iv_mrr = CENTAUR_SBE_PNOR_MRR;
        uint64_t fapiArg = reinterpret_cast<uint64_t> (l_otherArg);
        myArgs.push_back(fapiArg);

        // Set FapiPoreVeMemArg for pnor option, base address = 0
        uint32_t base_addr = 0;
        char* l_dataPnor = const_cast<char*>(l_sbePnorAddr);
        FapiPoreVeMemArg* l_memArg = new FapiPoreVeMemArg(ARG_PNOR,
                            base_addr, l_sbePnorSize,
                            static_cast<void*>(l_dataPnor));
        fapiArg = reinterpret_cast<uint64_t> (l_memArg);
                  myArgs.push_back(fapiArg);

        // Create state argument to dump out state for debugging purpose
        FapiPoreVeStateArg *l_stateArg = new FapiPoreVeStateArg(NULL);
                      l_stateArg->iv_installState = false;
                      l_stateArg->iv_extractState = true;
                      fapiArg = reinterpret_cast<uint64_t> (l_stateArg);
                      myArgs.push_back(fapiArg);

        // Loop thru all Centaurs in list
        for ( size_t i = 0; i < l_membufTargetList.size(); i++ )
        {
            // Create a FAPI Target
            const TARGETING::Target*  l_membuf_target = l_membufTargetList[i];
            const fapi::Target l_fapiTarget(
                              fapi::TARGET_TYPE_MEMBUF_CHIP,
                              reinterpret_cast<void *>
                              (const_cast<TARGETING::Target*>(l_membuf_target)));

            //  Put out info on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                             "Running cen_sbe_tp_chiplet_init1 on Centaur entity path...");

            EntityPath l_path;
            l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            //@todo - This is a temporary hack to skip if Target is not present.
            // This should be removed when PD works.
            if ( !FSI::isSlavePresent(l_membuf_target) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init1 - Skip this Centaur because it's not present");
                continue;
            }

            // Run the engine
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init1 - Start VSBE engine...");

            //@todo
            //@VBU workaround - Do not run in VPO since it takes too long
            //Temporarily disable this test case in VBU because it takes too long to run.
            //Also, the image used for Centaur is only a temporary image provided by Todd to try out.
            if ( !TARGETING::is_vpo() )
            {
                // Can't run now because the HALT returned will cause a failure in simics
                //FAPI_INVOKE_HWP(l_errl, fapiPoreVe, l_fapiTarget, myArgs);
            }

            if (l_errl )
            {
               TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X call_cen_sbe_tp_chiplet_init1 - Error returned from VSBE engine on this Centaur, l_rc 0x%llX",
                       l_errl->reasonCode());
               break; // break out of memBuf loop
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init1 - VSBE engine runs successfully on this Centaur");
            }

        }   // end for

        // Freeing memory
        if (l_otherArg)
        {
            delete l_otherArg;
            l_otherArg = NULL;
        }

        if (l_memArg)
        {
            delete l_memArg;
            l_memArg = NULL;
        }

        if (l_stateArg)
        {
            delete l_stateArg;
            l_stateArg = NULL;
        }

        if (l_errl)
        {
            break; // break out of do-while loop
        }


    } while(0);

    // Unload sbe_pnor
    if (l_unloadSbePnorImg == true)
    {
        errlHndl_t  l_tempErrl = NULL;
        FAPI_INVOKE_HWP(l_tempErrl, fapiUnloadInitFile, "sbe_pnor.bin",
                                    l_sbePnorAddr,
                                    l_sbePnorSize);
        if (l_tempErrl)
        {
             FAPI_ERR("ERROR 0x%.8X call_cen_sbe_tp_chiplet_init1 - Error unloading sbe_pnor.bin",
                     l_tempErrl->reasonCode());
             if (l_errl == NULL)
             {
                 l_errl = l_tempErrl;
             }
        }
    }

    //  process return code.
    if ( l_errl )
    {
         TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR 0x%.8X:  cen_sbe_tp_chiplet_init1 HWP(?,?,? ) ",
                 l_errl->reasonCode());
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_tp_chiplet_init1 HWP(? ? ? )" );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "cen_sbe_tp_chiplet_init1 exit" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.2 : cen_sbe_npll_initf
//
void    call_cen_sbe_npll_initf( void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_cen_sbe_pll_initf entry"  );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_pll_initf HWP(? ? ? )" );

#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_pll_initf( ? , ?, ? );
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_pll_initf exit" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.3 : cen_sbe_tp_chiplet_init2
//
void    call_cen_sbe_tp_chiplet_init2( void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
    "call_cen_sbe_tp_chiplet_init2" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_tp_chiplet_init2 HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_tp_chiplet_init2( ? , ?, ? );
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_cen_sbe_tp_chiplet_init2" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.4 : cen_sbe_tp_arrayinit
//
void    call_cen_sbe_tp_arrayinit( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_tp_arrayinit entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_tp_arrayinit HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_tp_arrayinit( ? , ?, ? );
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_tp_arrayinit exit" );

    task_end2( l_errl );
}



//
//  Wrapper function to call 10.5 : cen_sbe_tp_chiplet_init3
//
void    call_cen_sbe_tp_chiplet_init3( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_tp_chiplet_init3 entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_tp_chiplet_init3 HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_tp_chiplet_init3( ? , ?, ? );
#endif


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_tp_chiplet_init3 exit" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.6 : cen_sbe_chiplet_init
//
void    call_cen_sbe_chiplet_init( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                    "call_cen_sbe_chiplet_init entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_chiplet_init HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_chiplet_init( ? , ?, ? );
#endif


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_chiplet_init exit" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.7 : cen_sbe_arrayinit
//
void    call_cen_sbe_arrayinit( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                    "call_cen_sbe_arrayinit entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_arrayinit HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_arrayinit( ? , ?, ? );
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_arrayinit exit" );

    task_end2( l_errl );
}

//
//  Wrapper function to call 10.8 : cen_sbe_dts_init
//
void    call_cen_sbe_dts_init( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_dts_init entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_dts_init HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_dts_init( ? , ?, ? );
#endif


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                    "call_cen_sbe_dts_init exit" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.9 : cen_sbe_initf
//
void    call_cen_sbe_initf( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                    "call_cen_sbe_initf entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_initf HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_initf( ? , ?, ? );
#endif


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_initf exit" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.10 : cen_sbe_do_manual_inits
//
void    call_cen_sbe_do_manual_inits( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_do_manual_inits entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_do_manual_inits HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_do_manual_inits( ? , ?, ? );
#endif


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_do_manual_inits exit" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.11 : cen_sbe_nest_startclocks
//
void    call_cen_sbe_nest_startclocks( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_startclocks entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_startclocks HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_startclocks( ? , ?, ? );
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_startclocks exit" );

    task_end2( l_errl );
}


//
//  Wrapper function to call 10.12 : cen_sbe_scominits
//
void    call_cen_sbe_scominits( void *io_pArgs )
{

    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                "call_cen_sbe_scominits entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_scominits HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_scominits( ? , ?, ? );
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,                            
               "call_cen_sbe_scominits exit"  );

    task_end2( l_errl );
}

};   // end namespace

