/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_erepair.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
 *  @file call_fabric_erepair.C
 *
 *  Support file for IStep: edi_ei_initialization
 *   EDI, EI Initialization
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <hwas/common/hwasCommon.H>

#include    <sbe/sbeif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>


namespace   ISTEP_09
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;


//
//  Wrapper function to call fabric_erepair
//
void*    call_fabric_erepair( void    *io_pArgs )
{
    errlHndl_t l_errl = NULL;
    //@TODO RTC:134079
    /*ISTEP_ERROR::IStepError l_StepError;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_fabric_erepair entry" );

    do {

    // Check if the system can support multiple nest frequencies
    // and if so, see if an SBE Update is required
    TARGETING::Target* l_sys = NULL;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL, "call_fabric_erepair: sys target is NULL" );
    MRW_NEST_CAPABLE_FREQUENCIES_SYS l_mrw_nest_capable;
    l_mrw_nest_capable =
               l_sys->getAttr<ATTR_MRW_NEST_CAPABLE_FREQUENCIES_SYS>();
    if ( l_mrw_nest_capable ==
               MRW_NEST_CAPABLE_FREQUENCIES_SYS_2000_MHZ_OR_2400_MHZ )
    {
        // Call to check Processor SBE SEEPROM Images against NEST_FREQ_MHZ
        // attributes and make any necessary updates
        l_errl = SBE::updateProcessorSbeSeeproms(
                            SBE::SBE_UPDATE_ONLY_CHECK_NEST_FREQ);

        if (l_errl)
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }

    }

    std::vector<uint8_t> l_endp1_txFaillanes;
    std::vector<uint8_t> l_endp1_rxFaillanes;
    std::vector<uint8_t> l_endp2_txFaillanes;
    std::vector<uint8_t> l_endp2_rxFaillanes;

    TargetPairs_t l_PbusConnections;
    const uint32_t MaxBusSet = 2;
    TYPE busSet[MaxBusSet] = { TYPE_ABUS, TYPE_XBUS };
    uint32_t l_count = 0;
    fapi::TargetType l_tgtType = fapi::TARGET_TYPE_NONE;

    for (uint32_t i = 0; l_StepError.isNull() && (i < MaxBusSet); i++)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                            l_PbusConnections, busSet[i] );
        if ( l_errl )
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        for (TargetPairs_t::const_iterator l_itr = l_PbusConnections.begin();
             (l_StepError.isNull()) && (l_itr != l_PbusConnections.end());
             ++l_itr)
        {
            const fapi::Target l_fapi_endp1_target(
                   (i ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->first)));
            const fapi::Target l_fapi_endp2_target(
                   (i ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->second)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "===== " );

            // Get the repair lanes from the VPD
            fapi::ReturnCode l_rc;
            l_endp1_txFaillanes.clear();
            l_endp1_rxFaillanes.clear();
            l_endp2_txFaillanes.clear();
            l_endp2_rxFaillanes.clear();
            l_rc = erepairGetRestoreLanes(l_fapi_endp1_target,
                                          l_endp1_txFaillanes,
                                          l_endp1_rxFaillanes,
                                          l_fapi_endp2_target,
                                          l_endp2_txFaillanes,
                                          l_endp2_rxFaillanes);

            if(l_rc)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Unable to"
                          " retrieve fabric eRepair data from the VPD");

                // convert the FAPI return code to an err handle
                l_errl = fapiRcToErrl(l_rc);

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl);

                // Commit Error
                errlCommit(l_errl, HWPF_COMP_ID);
                break;
            }

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                   "===== Call io_restore_erepair HWP"
                   "%cbus connection ", (i ? 'X' : 'A') );

            if(l_endp1_txFaillanes.size() || l_endp1_rxFaillanes.size())
            {
                // call the io_restore_erepair HWP to restore eRepair
                // lanes of endp1
                //@TODO RTC:133830
                //FAPI_INVOKE_HWP(l_errl,
                //                p9_io_restore_erepair,
                //                l_fapi_endp1_target,
                //                l_endp1_txFaillanes,
                //                l_endp1_rxFaillanes);
            }

            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X :  io_restore_erepair HWP"
                        "%cbus connection ",
                        l_errl->reasonCode(), (i ? 'X' : 'A') );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl);

                // Commit Error
                errlCommit(l_errl, HWPF_COMP_ID);
                break;
            }

            l_tgtType = l_fapi_endp1_target.getType();
            for(l_count = 0; l_count < l_endp1_txFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Tx lane %d, of %s, of endpoint %s",
                          l_endp1_txFaillanes[l_count],
                          l_tgtType == TARGET_TYPE_XBUS_ENDPOINT ? "X-Bus" :
                          "A-Bus", l_fapi_endp1_target.toEcmdString());
            }

            for(l_count = 0; l_count < l_endp1_rxFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Rx lane %d, of %s, of endpoint %s",
                          l_endp1_rxFaillanes[l_count],
                          l_tgtType == TARGET_TYPE_XBUS_ENDPOINT ? "X-Bus" :
                          "A-Bus", l_fapi_endp1_target.toEcmdString());
            }

            if(l_endp2_txFaillanes.size() || l_endp2_rxFaillanes.size())
            {
                // call the io_restore_erepair HWP to restore eRepair
                // lanes of endp2
                //@TODO RTC:133830
                FAPI_INVOKE_HWP(l_errl,
                                io_restore_erepair,
                                l_fapi_endp2_target,
                                l_endp2_txFaillanes,
                                l_endp2_rxFaillanes);
            }

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "ERROR 0x%.8X :  io_restore_erepair HWP"
                            "%cbus connection ",
                            l_errl->reasonCode(), (i ? 'X' : 'A') );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl);

                // Commit Error
                errlCommit(l_errl, HWPF_COMP_ID);
                break;
            }

            l_tgtType = l_fapi_endp2_target.getType();
            for(l_count = 0; l_count < l_endp2_txFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Tx lane %d, of %s, of endpoint %s",
                          l_endp2_txFaillanes[l_count],
                          l_tgtType == TARGET_TYPE_XBUS_ENDPOINT ? "X-Bus" :
                          "A-Bus", l_fapi_endp2_target.toEcmdString());
            }

            for(l_count = 0; l_count < l_endp2_rxFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Rx lane %d, of %s, of endpoint %s",
                          l_endp2_rxFaillanes[l_count],
                          l_tgtType == TARGET_TYPE_XBUS_ENDPOINT ? "X-Bus" :
                          "A-Bus", l_fapi_endp2_target.toEcmdString());
            }
        } // end for l_PbusConnections
    } // end for MaxBusSet

    } while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_fabric_erepair exit" );

    return l_StepError.getErrorHandle();
    */
        return l_errl;
}
};
