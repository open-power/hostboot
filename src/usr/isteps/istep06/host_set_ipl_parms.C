/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_set_ipl_parms.C $                 */
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

#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <util/utilsemipersist.H>
#include <hwas/common/deconfigGard.H>


namespace ISTEP_06
{

void* host_set_ipl_parms( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_stepError;
    errlHndl_t l_err;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms entry" );

    //Read out the semi persistent area.
    Util::semiPersistData_t l_semiData;
    Util::readSemiPersistData(l_semiData);

    // If magic number set, then this is warm reboot:
    //          1) increment boot count
    if(l_semiData.magic == Util::PERSIST_MAGIC)
    {
        l_semiData.reboot_cnt++;
    }
    // else magic number is not set, then this is first, cold boot:
    //          1) set magic num, boot count
    //          2) clear all gard records of type GARD_Reconfig
    else
    {
        memset(&l_semiData, 0x0, sizeof(Util::semiPersistData_t));
        l_semiData.magic = Util::PERSIST_MAGIC;

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
    }

    //Write update data back out
    Util::writeSemiPersistData(l_semiData);


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms exit" );

    return l_stepError.getErrorHandle();
}

};
