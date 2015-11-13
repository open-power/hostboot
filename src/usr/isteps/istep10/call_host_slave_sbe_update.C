/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_slave_sbe_update.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] Google Inc.                                                        */
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
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

#include    <sbe/sbeif.H>
#include    <pnor/pnorif.H>
#include    <i2c/i2cif.H>


using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;

namespace ISTEP_10
{
void* call_host_slave_sbe_update (void *io_pArgs)
{
    errlHndl_t  l_errl  =   NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_update entry" );
    do
    {

        // Slave processors should now use Host I2C Access Method
        I2C::i2cSetAccessMode( I2C::I2C_SET_ACCESS_MODE_PROC_HOST );

        // Reset I2C devices before trying to access the SBE SEEPROMs
        // Any error returned should not fail istep
        l_errl = I2C::i2cResetActiveMasters( I2C::I2C_PROC_ALL );
        if (l_errl)
        {
            // Commit error and keep going
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        // Call to check state of Processor SBE SEEPROMs and
        // make any necessary updates
        // @TODO RTC:142091 add it after SBE is ported to fapi2
        //l_errl = SBE::updateProcessorSbeSeeproms();

        if (l_errl)
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }

        // Call to Validate any Alternative Master's connection to PNOR
        // Only call this in MNFG mode
        // Any error returned should not fail istep

        // Get target service and the system target
        TargetService& tS = targetService();
        TARGETING::Target* sys = NULL;
        (void) tS.getTopLevelTarget( sys );
        assert(sys, "call_host_slave_sbe_update() system target is NULL");

        TARGETING::ATTR_MNFG_FLAGS_type mnfg_flags;
        mnfg_flags = sys->getAttr<TARGETING::ATTR_MNFG_FLAGS>();
        if ( mnfg_flags & MNFG_FLAG_THRESHOLDS )
        {
            l_errl = PNOR::validateAltMaster();
            if (l_errl)
            {
                // Commit error
                errlCommit( l_errl, HWPF_COMP_ID );
                break;
            }
        }

   } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_update exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();

}

};
