/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.C $        */
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
 *  @file sbe_centaur_init.C
 *
 *  Support file for IStep:
 *      sbe_centaur_init
 *
 *
 *
 *  HWP_IGNORE_VERSION_CHECK
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
#include <hwpisteperror.H>
#include <errl/errludtarget.H>
#include "cen_xip_customize.H"

extern fapi::ReturnCode fapiPoreVe(const fapi::Target i_target,
		   std::list<uint64_t> & io_sharedObjectArgs);


// Constants
// Memory Relocation Register for Centaur SBE image
const uint64_t CENTAUR_SBE_PNOR_MRR = 0;

namespace   SBE_CENTAUR_INIT
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   vsbe;


//
//  Wrapper function to call step 10
//
void*    call_sbe_centaur_init( void *io_pArgs )
{

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_sbe_centaur_init entry");

    // Get target list to pass in procedure
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    bool l_unloadSbePnorImg = false;
    size_t l_sbePnorSize = 0;
    const char * l_sbePnorAddr = NULL;
    errlHndl_t  l_errl = NULL;

    IStepError  l_StepError;

    // ----------------------- Setup sbe_pnor stuff --------------------

    if (l_membufTargetList.size())
    {
        // Loading image
        l_errl = VFS::module_load("centaur.sbe_pnor.bin");
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR 0x%.8X call_sbe_centaur_init - "
                 "VFS::module_load(centaur.sbe_pnor.bin) returns error",
                 l_errl->reasonCode());
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
    }

    // Loop thru all Centaurs in list
    for (TargetHandleList::const_iterator
         l_membuf_iter = l_membufTargetList.begin();
         l_membuf_iter != l_membufTargetList.end();
         ++l_membuf_iter)
    {
        // Make sure we have successfully retrieved the reference image
        if (l_errl)
        {
            l_StepError.addErrorDetails(ISTEP_SBE_CENTAUR_INIT_FAILED,
                                        ISTEP_SBE_CENTAUR_INIT,
                                        l_errl);
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }
     
        // Create a FAPI Target
        const TARGETING::Target* l_membuf_target = *l_membuf_iter;
        const fapi::Target l_fapiTarget( fapi::TARGET_TYPE_MEMBUF_CHIP,
                        (const_cast<TARGETING::Target*>(l_membuf_target)));

        const uint32_t l_customizedMaxSize = 32 * 1024;
        const uint32_t l_buf1Size = 32 * 1024;
        const uint32_t l_buf2Size = 32 * 1024;
        uint32_t l_customizedSize = l_customizedMaxSize;
        char * l_pCustomizedImage = (char *)malloc(l_customizedMaxSize);
        void * l_pBuf1 = malloc(l_buf1Size);
        void * l_pBuf2 = malloc(l_buf2Size);

        // Setup args
        std::list<uint64_t> myArgs;

        // Set FapiPoreVeOtherArg: run unlimited instructions
        FapiPoreVeOtherArg *l_otherArg =
                new FapiPoreVeOtherArg(vsbe::RUN_UNLIMITED, vsbe::PORE_SBE);
        // Entry point
        l_otherArg->iv_entryPoint = const_cast<char*>("pnor::_sbe_pnor_start");
        l_otherArg->iv_mrr = CENTAUR_SBE_PNOR_MRR;
        myArgs.push_back(reinterpret_cast<uint64_t>(l_otherArg));

        // Set FapiPoreVeMemArg for pnor option, base address = 0
        uint32_t base_addr = 0;
        char* l_dataPnor = const_cast<char*>(l_pCustomizedImage);
        FapiPoreVeMemArg* l_memArg = new FapiPoreVeMemArg(ARG_PNOR,
                                               base_addr, l_customizedSize,
                                               static_cast<void*>(l_dataPnor));
        myArgs.push_back(reinterpret_cast<uint64_t>(l_memArg));

        // Create state argument to dump out state for debugging purpose
        FapiPoreVeStateArg *l_stateArg = new FapiPoreVeStateArg(NULL);
        l_stateArg->iv_installState = false;
        l_stateArg->iv_extractState = true;
        myArgs.push_back(reinterpret_cast<uint64_t>(l_stateArg));

        //  Put out info on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Running call_sbe_centaur_init on Centaur "
            " target HUID %.8X", TARGETING::get_huid(l_membuf_target));

        if (!TARGETING::is_vpo())
        {
            uint8_t l_data[80];
            TARGETING::Target* l_pTarget = *l_membuf_iter;
            l_pTarget->tryGetAttr<
               TARGETING::ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA>(l_data);
            l_pTarget->setAttr<TARGETING::ATTR_MEMB_TP_BNDY_PLL_DATA>(l_data);
        }

        FAPI_INVOKE_HWP( l_errl, cen_xip_customize,
                         l_fapiTarget, (void *)l_sbePnorAddr,
                         l_pCustomizedImage, l_customizedSize,
                         l_pBuf1, l_buf1Size,
                         l_pBuf2, l_buf2Size );

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
               "ERROR 0x%.8X call_sbe_centaur_init - Error returned from"
               " cen_xip_customize, l_rc 0x%llX", l_errl->reasonCode());
        }
        else
        {
            // Run the engine
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_sbe_centaur_init - Start VSBE engine...");

            FAPI_INVOKE_HWP(l_errl, fapiPoreVe, l_fapiTarget, myArgs);

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR 0x%.8X call_sbe_centaur_init - Error returned from"
                   " VSBE engine on this Centaur, l_rc 0x%llX",
                   l_errl->reasonCode());
            }
        }

        // Freeing memory
        delete l_otherArg;
        delete l_memArg;
        delete l_stateArg;
        free( l_pCustomizedImage );
        free( l_pBuf1 );
        free( l_pBuf2 );

        if (l_errl )
        {
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog( l_errl );

            /*@
             * @errortype
             * @reasoncode  ISTEP_SBE_CENTAUR_INIT_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_SBE_CENTAUR_INIT
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_swl_build to build the sleep
             *              winkle image has failed
             */
            l_StepError.addErrorDetails(ISTEP_SBE_CENTAUR_INIT_FAILED,
                                        ISTEP_SBE_CENTAUR_INIT,
                                        l_errl);

            errlCommit( l_errl, HWPF_COMP_ID );

            break; // break out of memBuf loop
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "call_sbe_centaur_init - VSBE engine runs successfully "
                 "on this Centaur");
        }

    }   // end for

    // Unload image
    if (l_unloadSbePnorImg == true)
    {
        l_errl = VFS::module_unload("centaur.sbe_pnor.bin");

        if (l_errl)
        {
             FAPI_ERR("ERROR 0x%.8X call_sbe_centaur_init - "
                      "Error unloading centaur.sbe_pnor.bin",
                      l_errl->reasonCode());

            l_StepError.addErrorDetails(ISTEP_SBE_CENTAUR_INIT_FAILED,
                                        ISTEP_SBE_CENTAUR_INIT,
                                        l_errl);

            errlCommit( l_errl, HWPF_COMP_ID );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_sbe_centaur_init exit" );

    return l_StepError.getErrorHandle();
}

};   // end namespace

