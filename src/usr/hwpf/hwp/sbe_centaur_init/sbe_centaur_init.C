/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.C $
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

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <fapi.H>
#include <fapiPoreVeArg.H>
#include <fapiTarget.H>
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#include <vfs/vfs.H>
#include "sbe_centaur_init.H"

// Extern function declaration
extern fapi::ReturnCode fapiPoreVe(const fapi::Target i_target,
                   std::vector<vsbe::FapiPoreVeArg *> & io_sharedObjectArgs);
// Constants
// Memory Relocation Register for Centaur SBE image
const uint64_t CENTAUR_SBE_PNOR_MRR = 0;

namespace   SBE_CENTAUR_INIT
{

using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   vsbe;

//
//  Wrapper function to call step 10 : sbe_centaur_init
//
void    call_sbe_centaur_init( void *io_pArgs )
{

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_sbe_centaur_init entry");

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

        // Loading image
        l_errl = VFS::module_load("centaur.sbe_pnor.bin");
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR 0x%.8X call_sbe_centaur_init - "
                 "VFS::module_load(centaur.sbe_pnor.bin) returns error",
                 l_errl->reasonCode());
            break;
        }
        else
        {
             // Set flag to unload
             l_unloadSbePnorImg = true;
             l_errl = VFS::module_address("centaur.sbe_pnor.bin",
                                          l_sbePnorAddr, l_sbePnorSize);
             if(l_errl)
             {
                 TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X call_sbe_centaur_init - "
                      "VFS::module_address(centaur.sbe_pnor.bin) return error",
                      l_errl->reasonCode());
                 break;
             }
             else
             {
                 char l_header[10];
                 memcpy (l_header, l_sbePnorAddr, 9);
                 l_header[9] = '\0';
                 TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_sbe_centaur_init - Loading "
                      "centaur.sbe_pnor.bin, Addr 0x%llX, Size %d, Header %s",
                      l_sbePnorAddr, l_sbePnorSize, l_header);
             }
        }

        // Setup args
        std::vector<FapiPoreVeArg *> myArgs;

        // Set FapiPoreVeOtherArg: run unlimited instructions
        FapiPoreVeOtherArg *l_otherArg =
                new FapiPoreVeOtherArg(vsbe::RUN_UNLIMITED, vsbe::PORE_SBE);
        // Entry point
        l_otherArg->iv_entryPoint = const_cast<char*>("pnor::_sbe_pnor_start");
        l_otherArg->iv_mrr = CENTAUR_SBE_PNOR_MRR;
        myArgs.push_back(l_otherArg);

        // Set FapiPoreVeMemArg for pnor option, base address = 0
        uint32_t base_addr = 0;
        char* l_dataPnor = const_cast<char*>(l_sbePnorAddr);
        FapiPoreVeMemArg* l_memArg = new FapiPoreVeMemArg(ARG_PNOR,
                                               base_addr, l_sbePnorSize,
                                               static_cast<void*>(l_dataPnor));
        myArgs.push_back(l_memArg);

        // Create state argument to dump out state for debugging purpose
        FapiPoreVeStateArg *l_stateArg = new FapiPoreVeStateArg(NULL);
        l_stateArg->iv_installState = false;
        l_stateArg->iv_extractState = true;
        myArgs.push_back(l_stateArg);

        // Loop thru all Centaurs in list
        for ( size_t i = 0; i < l_membufTargetList.size(); i++ )
        {
            // Create a FAPI Target
            const TARGETING::Target*  l_membuf_target = l_membufTargetList[i];
            const fapi::Target l_fapiTarget( fapi::TARGET_TYPE_MEMBUF_CHIP,
                            reinterpret_cast<void *>
                            (const_cast<TARGETING::Target*>(l_membuf_target)));

            //  Put out info on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running call_sbe_centaur_init on Centaur entity path...");

            EntityPath l_path;
            l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            // Run the engine
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_sbe_centaur_init - Start VSBE engine...");

            FAPI_INVOKE_HWP(l_errl, fapiPoreVe, l_fapiTarget, myArgs);

            if (l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X call_sbe_centaur_init - Error returned from"
                     " VSBE engine on this Centaur, l_rc 0x%llX",
                     l_errl->reasonCode());
               break; // break out of memBuf loop
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "call_sbe_centaur_init - VSBE engine runs successfully "
                     "on this Centaur");
            }

        }   // end for

        // Freeing memory
        delete l_otherArg;
        delete l_memArg;
        delete l_stateArg;

    } while(0);

    // Unload image
    if (l_unloadSbePnorImg == true)
    {
        errlHndl_t l_tempErrl = VFS::module_unload("centaur.sbe_pnor.bin");

        if (l_tempErrl)
        {
             FAPI_ERR("ERROR 0x%.8X call_sbe_centaur_init - "
                      "Error unloading centaur.sbe_pnor.bin",
                      l_tempErrl->reasonCode());
             if (l_errl == NULL)
             {
                 l_errl = l_tempErrl;
             }
             else
             {
                 errlCommit( l_tempErrl, HWPF_COMP_ID );
             }
        }
    }

    //  process return code.
    if ( l_errl )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR 0x%.8X:  sbe_centaur_init HWP",
                   l_errl->reasonCode());
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS :  sbe_centaur_init HWP" );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_sbe_centaur_init exit" );

    task_end2( l_errl );
}

};   // end namespace

