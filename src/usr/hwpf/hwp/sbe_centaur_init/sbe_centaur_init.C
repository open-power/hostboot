/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#include <sbe/sbeif.H>
#include "cen_xip_customize.H"
#include <util/align.H>

extern fapi::ReturnCode fapiPoreVe(const fapi::Target i_target,
           std::list<uint64_t> & io_sharedObjectArgs);

const uint64_t REPAIR_LOADER_RETRY_CTR_MASK = 0x000007FC00000000ull;

// Constants
// Memory Relocation Register for Centaur SBE image
const uint64_t CENTAUR_SBE_PNOR_MRR = 0;

// Max SBE image buffer size
const uint32_t MAX_SBE_IMG_SIZE = 48 * 1024;

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

    size_t l_sbePnorSize = 0;
    void* l_sbePnorAddr = NULL;
    errlHndl_t  l_errl = NULL;

    IStepError  l_StepError;

    // Loop thru all Centaurs in list
    for (TargetHandleList::const_iterator
         l_membuf_iter = l_membufTargetList.begin();
         l_membuf_iter != l_membufTargetList.end();
         ++l_membuf_iter)
    {

        TARGETING::Target* l_membuf_target = *l_membuf_iter;
        HwasState l_hwasState = l_membuf_target->getAttr<ATTR_HWAS_STATE>();

        TARGETING::ATTR_MSS_INIT_STATE_type  l_attr_mss_init_state=
                l_membuf_target->getAttr<TARGETING::ATTR_MSS_INIT_STATE>();

        //run SBE init on functional OR previously functional centaurs
        if ( l_hwasState.functional ||
            (l_hwasState.present &&
            (l_attr_mss_init_state != ENUM_ATTR_MSS_INIT_STATE_COLD)) )
        {
            l_membuf_target->setAttr<TARGETING::ATTR_MSS_INIT_STATE>(
                                 ENUM_ATTR_MSS_INIT_STATE_COLD);
        }
        else
        {
            //go to the next membuf in the list because this present  membuf is
            //not functional or has not gone through an IPL once
            continue;
        }
        //find SBE image in PNOR
        uint8_t cur_ec = (*l_membuf_iter)->getAttr<TARGETING::ATTR_EC>();


        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK,
                   "call_sbe_centaur_init() - Find SBE image in PNOR");

        l_errl = SBE::findSBEInPnor(l_membuf_target,
                                 l_sbePnorAddr,
                                 l_sbePnorSize,
                                 NULL);
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK,
           "call_sbe_centaur_init() - Error getting image from PNOR. "
           "Target 0x%.8X, EC=0x%.2X",
           TARGETING::get_huid(l_membuf_target), cur_ec );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog( l_errl );

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
            continue;
        }

        char l_header[10];
        memcpy (l_header, l_sbePnorAddr, 9);
        l_header[9] = '\0';

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "call_sbe_centaur_init - Loading "
                     "centaur sbe from pnor, Addr 0x%llX, Size %d, Header %s",
                     l_sbePnorAddr, l_sbePnorSize, l_header);

        // Create a FAPI Target
        const fapi::Target l_fapiTarget( fapi::TARGET_TYPE_MEMBUF_CHIP,
                     (const_cast<TARGETING::Target*>(l_membuf_target)));

        // Expand buffer for new image size
        const uint32_t l_customizedMaxSize = ALIGN_POW2(MAX_SBE_IMG_SIZE);
        const uint32_t l_buf1Size = ALIGN_POW2(MAX_SBE_IMG_SIZE);
        const uint32_t l_buf2Size = ALIGN_POW2(MAX_SBE_IMG_SIZE);

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

        // XIP customize is going to look for a PLL ring with a "stub"
        // mem freq -- so set to a default, then clear it (so as not
        // to mess up MSS HWP later
        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(1600);


        FAPI_INVOKE_HWP( l_errl, cen_xip_customize,
                         l_fapiTarget, l_sbePnorAddr,
                         l_pCustomizedImage, l_customizedSize,
                         l_pBuf1, l_buf1Size,
                         l_pBuf2, l_buf2Size );

        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(0);

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
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 1024);
                l_errl->collectTrace("ISTEPS_TRACE", 512);
            }
       
            // Remove 0x0104000A reading, per Joe, the IPL procedures are no
            // longer writing information related to the repair loader into
            // this register

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

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "call_sbe_centaur_init - VSBE engine runs successfully "
                 "on this Centaur");
        }

    }   // end for

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_sbe_centaur_init exit" );

    return l_StepError.getErrorHandle();
}

};   // end namespace

