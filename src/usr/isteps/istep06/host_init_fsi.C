/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_init_fsi.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
#include <istepHelperFuncs.H>

#ifdef CONFIG_PLDM
#include <pldm/extended/pdr_manager.H>
#include <pldm/extended/hb_fru.H>
#include <pldm/extended/pldm_entity_ids.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/pldm_errl.H>
#endif

//Targeting
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

using namespace TARGETING;
using namespace I2C;
using namespace TRUSTEDBOOT;

namespace ISTEP_06
{

#ifdef CONFIG_PLDM

/* @brief Perform the first step of the PDR exchange, which will fetch the BMC's
 *        PDRs and add them to Hostboot's PDR repository.  These are necessary
 *        to request the FRU VPD for targets "owned" by the BMC.
 *
 * @return errlHndl_t Error if any, otherwise nullptr.
 */
static errlHndl_t fetch_remote_pdrs()
{
    errlHndl_t l_err = nullptr;

    /* Fetch the BMC's PDRs. */

    do
    {
        // Starting the PDR exchange, ergo, set the flag stating that HB is starting
        // a critical PLDM exchange with the BMC.
        const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
        const bool l_criticalExchangeCommencing = true;
        sys->setAttr<TARGETING::ATTR_HALT_ON_BMC_PLDM_RESET>(l_criticalExchangeCommencing);

        PLDM::thePdrManager().resetPdrs();

        /* Get the BMC's PDRs. */

        l_err = PLDM::thePdrManager().addRemotePdrs();

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to add remote PDRs to PDR manager");
            break;
        }

        sys->setAttr<TARGETING::ATTR_PLDM_BMC_PDR_COUNT>(PLDM::thePdrManager().pdrCount());

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Added %llu remote PDRs to PDR manager",
                  PLDM::thePdrManager().pdrCount());
    } while (false);

    return l_err;
}

#endif // CONFIG_PLDM

void* host_init_fsi( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    ISTEP_ERROR::IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi entry" );
    do
    {
        #ifdef CONFIG_PLDM
        // First step of the PDR exchange is to fetch remote PDRs as early
        // as possible, as some features (like graceful reboot) require
        // BMC PDRs for that to work.  Other features such as SBE dump will
        // not be possible until the the entire PDR exchange has completed,
        // since BMC requires Hostboot processor PDRs in order to create the
        // individual SBE dump effecters. Completion of the PDR exchange
        // occurs in host_discover_targets.
        l_err = fetch_remote_pdrs();
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"host_init_fsi: Failed to fetch PDRs from the BMC");
            captureError(l_err, l_stepError, ISTEP_COMP_ID);
            break;
        }

        l_err = PLDM::cacheRemoteFruVpd();
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"host_init_fsi: Failed to cache remote FRU info from the BMC");
            captureError(l_err, l_stepError, ISTEP_COMP_ID);
            break;
        }
        #endif

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
