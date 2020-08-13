/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_init_fsi.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include <list>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <fsi/fsiif.H>
#include <i2c/i2cif.H>
#include <spi/tpmddif.H>
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <isteps/hwpisteperror.H>
#include <attributeenums.H>
#include <secureboot/trustedbootif.H>

//Targeting
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

// SBE
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>

using namespace TARGETING;
using namespace I2C;
using namespace TRUSTEDBOOT;

namespace ISTEP_06
{

void* host_init_fsi( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    ISTEP_ERROR::IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi entry" );
    do
    {
        // process SBE PSU errors that might have occurred before fapi was
        // initialized
        SBEIO::SbePsu::getTheInstance().processEarlyError();

        l_err = FSI::initializeHardware( );
        if (l_err)
        {
            // This error should get returned
            l_stepError.addErrorDetails(l_err);
            errlCommit( l_err, ISTEP_COMP_ID );
            break;
        }

        // Reset all I2C Masters
        l_err = i2cResetActiveMasters(I2C_ALL, false);
        if (l_err)
        {
            // Commit this error
            errlCommit( l_err, ISTEP_COMP_ID );
        }

    } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi exit" );
    return l_stepError.getErrorHandle();
}

}
