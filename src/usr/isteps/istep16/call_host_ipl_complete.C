/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_ipl_complete.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

#include    <errl/errlentry.H>
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>

#include    <initservice/initserviceif.H>
#include    <initservice/istepdispatcherif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <fapi2/target.H>
#include    <fapi2/plat_hwp_invoker.H>

#include   <p9_switch_rec_attn.H>
#include   <p9_switch_cfsim.H>

#include    <targeting/attrrp.H>
#include    <sys/internode.h>
#include    <runtime/runtime.H>
#include    <util/utiltce.H>

#include    <util/utilsemipersist.H>
#include    <hwas/common/deconfigGard.H>

using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   fapi2;


namespace ISTEP_16
{
void* call_host_ipl_complete (void *io_pArgs)
{
    errlHndl_t  l_err  =   NULL;

    IStepError  l_stepError;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_ipl_complete entry" );
    do
    {
        //No more reconfig loops are supported from this point
        //forward.  Clean up the semi persistent area
        //   1) clear magic number (so next boot thinks it is cold)
        //   2) clear any reconfig specific gard records
        Util::semiPersistData_t l_semiData;  //inits to 0s
        Util::writeSemiPersistData(l_semiData);

        l_err = HWAS::clearGardByType(HWAS::GARD_Reconfig);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: clearGardByType( )",
                      l_err->reasonCode() );
            // Create IStep error log and cross ref error that occurred
            l_stepError.addErrorDetails( l_err );
            errlCommit( l_err, ISTEP_COMP_ID );
        }


        // Setup the TCEs needed for the FSP to DMA the PAYLOAD
        if (TCE::utilUseTcesForDmas())
        {
            l_err = TCE::utilSetupPayloadTces();

            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"TCE::utilSetupPayloadTces failed");
                // Don't continue with the rest of this istep
                break;
            }
        }

        // Initialize the RUNTIME DATA attributes
        // that HDAT needs to allocate memory for us.
        // -----------------------------------------
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);


        // Set number of pointer pairs for HDAT HB RESERVED MEM
        //@TODO RTC:142908 Support multiple nodes in HBRT
        const uint32_t NUM_NODES = 1;
        uint32_t  l_numRsvMemSections = NUM_NODES * HB_RSV_MEM_NUM_PTRS;
        sys->setAttr<ATTR_HDAT_RSV_MEM_NUM_SECTIONS>(l_numRsvMemSections);


        // Set number of pointer pairs for HDAT HBRT
        //@TODO RTC:142908 Support multiple nodes in HBRT
        uint32_t  l_numHbrtSections = NUM_NODES * HBRT_NUM_PTRS;
        sys->setAttr<ATTR_HDAT_HBRT_NUM_SECTIONS>(l_numHbrtSections);

        uint64_t  l_maxSecSize  = VMM_RT_VPD_SIZE;

        // Set max size of a HBRT section for HDAT
        TARGETING::ATTR_HDAT_HBRT_SECTION_SIZE_type l_secSize = {0};
        uint64_t *l_p_secSize =
            reinterpret_cast<uint64_t *>(&l_secSize);

        uint32_t l_attrArraySize =
            sizeof(ATTR_HDAT_HBRT_SECTION_SIZE_type) / sizeof(l_secSize[0]);
        assert(l_numHbrtSections <= l_attrArraySize);

        uint64_t  l_attrSize = AttrRP::maxSize();
        l_maxSecSize = (l_attrSize > l_maxSecSize) ? l_attrSize : l_maxSecSize;

        for (uint32_t  l_sect=0; (l_sect < l_numHbrtSections); l_sect++)
        {
            l_p_secSize[l_sect] = l_maxSecSize;
        }
        sys->setAttr<ATTR_HDAT_HBRT_SECTION_SIZE>(l_secSize);


//@TODO RTC:150266 HWPs for Centuar+Cumulus
// Need cen_switch_rec_attn for mem_chips
#if 0
        if ( INITSERVICE::spBaseServicesEnabled())
        {
            // For FSP based systems, do not route centaur
            // attentions through host after this step.
            // Loop through all the centaurs in the system
            // and run cen_switch_rec_attn
            TARGETING::TargetHandleList l_memTargetList;
            getAllChips(l_memTargetList, TYPE_MEMBUF );

            for ( TargetHandleList::iterator l_iter = l_memTargetList.begin();
                  l_iter != l_memTargetList.end();
                  ++l_iter )
            {
                TARGETING::Target * l_memChip  =   (*l_iter) ;

                //  dump physical path to target
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         "Running cen_switch_rec_attn HWP on target HUID %.8X",
                         TARGETING::get_huid(l_memChip) );


                const fapi2::Target<TARGET_TYPE_MEMBUF_CHIP> l_fap2_centTarget(
                            const_cast<TARGETING::Target*> (l_memChip));
                FAPI_INVOKE_HWP( l_err,
                                 cen_switch_rec_attn,
                                 l_fap2_centTarget );


                if (l_err)
                {
                    // log error for this centaur and continue

                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR 0x%.8X: cen_switch_rec_attn HWP( )",
                              l_err->reasonCode() );

                    // Add all the details for this centaur
                    ErrlUserDetailsTarget myDetails(l_memChip);

                    // capture the target data in the elog
                    myDetails.addToLog(l_err);

                    // Create IStep error log and cross ref error that occurred
                    l_stepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, HWPF_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "SUCCESS: cen_switch_rec_attn HWP( )" );
                }
            }   // endfor

        } // end if ( INITSERVICE::spBaseServicesEnabled())

#endif

        TARGETING::TargetHandleList l_procChips;
        //Use targeting code to get a list of all processors
        getAllChips( l_procChips, TARGETING::TYPE_PROC   );

        //Loop through all of the procs and call the HWP on each one
        for (const auto & l_procChip: l_procChips)
        {
            const fapi2::Target<TARGET_TYPE_PROC_CHIP>
                l_fapiProcTarget(l_procChip);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "Running p9_switch_rec_attn HWP on target HUID %.8X",
            TARGETING::get_huid(l_procChip) );

            //  call p9_switch_rec_attn
            FAPI_INVOKE_HWP(l_err, p9_switch_rec_attn, l_fapiProcTarget);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: p9_switch_rec_attn HWP returned error",
                          l_err->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_procChip).addToLog( l_err );

                //Create IStep error log and cross reference error that occurred
                l_stepError.addErrorDetails( l_err );

                //break to end because if p9_switch_rec_attn fails
                //recoverable/special attentions control didnt make it back
                // to the fsp, this is a fatal error
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS: p9_switch_rec_attn HWP( ) on target HUID %.8X",
                    TARGETING::get_huid(l_procChip) );
            }

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running proc_switch_cfsim HWP on target HUID %.8X",
                    TARGETING::get_huid(l_procChip) );

            FAPI_INVOKE_HWP(l_err, p9_switch_cfsim, l_fapiProcTarget);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: proc_switch_cfsim HWP returned error",
                          l_err->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_procChip).addToLog( l_err );

                //Create IStep error log and cross reference error that occurred
                l_stepError.addErrorDetails( l_err );


                //break to end because if proc_switch_cfsim fails
                //then FSP does not have FSI control again and system is toast
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS: proc_switch_cfsim HWP( ) on target HUID %.8X",
                    TARGETING::get_huid(l_procChip) );
            }
        }

        //if an error occurred during for loop, break to error handling
        if( l_err )
        {
            break;
        }

        // Sync attributes to Fsp
        l_err = syncAllAttributesToFsp();

        if( l_err )
        {
            break;
        }

        // Send Sync Point to Fsp
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Send SYNC_POINT_REACHED msg to Fsp" );
        l_err = INITSERVICE::sendSyncPoint();

    } while( 0 );

    if( l_err )
    {
        // collect and log any remaining errors

        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_ipl_complete exit ");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


};
