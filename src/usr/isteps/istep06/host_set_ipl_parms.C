/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_set_ipl_parms.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
#include <stdlib.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/isteps_trace.H>
#include <util/utilsemipersist.H>
#include <hwas/common/deconfigGard.H>
#include <arch/pvrformat.H>
#include <sys/mmio.h>
#include <console/consoleif.H>
#include <initservice/initserviceif.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <istepHelperFuncs.H> // captureError

#ifdef CONFIG_PLDM
#include <isteps/bios_attr_accessors/bios_attr_parsers.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pnor/pnor_pldm_utils.H>
#include <pldm/pldm_errl.H>
#endif

#if defined(CONFIG_PNORDD_IS_BMCMBOX)
#include <pnor/pnorif.H>
#endif

using namespace TARGETING;

namespace ISTEP_06
{

void* host_set_ipl_parms( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_stepError;

    do{
    // switch to allocator with discontiguous physical pages to
    // alleviate fragmentation
    activate_discontiguous_malloc_heap();

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms entry" );

    // only run on non-FSP systems
    if( !INITSERVICE::spBaseServicesEnabled() )
    {
        // Read the semi persistent area
        Util::semiPersistData_t l_semiData;
        Util::readSemiPersistData(l_semiData);

        // If magic number set, then this is re-IPL,
        // so increment reboot count
        if(l_semiData.magic == Util::PERSIST_MAGIC)
        {
            l_semiData.reboot_cnt++;
        }
        // else magic number is not set, then this is a fresh IPL
        else
        {
            l_semiData.magic = Util::PERSIST_MAGIC;
            l_semiData.reboot_cnt = 0;
            //Intentionally don't change mfg_term_reboot
        }

        // Write updated data back out
        Util::writeSemiPersistData(l_semiData);

        // Informational only
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms "
            "l_semiData.magic=0x%X l_semiData.reboot_cnt=0x%X, l_semiData.mfg_term_reboot=0x%X",
            l_semiData.magic, l_semiData.reboot_cnt, l_semiData.mfg_term_reboot);

#ifdef CONFIG_FILE_XFER_VIA_PLDM

        errlHndl_t errl = PLDM_PNOR::parse_rt_lid_ids();
        if(errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "host_set_ipl_parms: An error occurred parsing out the runtime lid ids from the hb_lid_ids bios attribute.");
            captureError(errl, l_stepError, ISTEP_COMP_ID);
            break;
        }
#endif

#ifdef CONFIG_PLDM
        // Force the update of the VPD ECC data if there is a mismatch, for BMC only
        bool l_forceEccUpdateFlag = true;
        const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
        sys->setAttr<TARGETING::ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR>(l_forceEccUpdateFlag);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms: "
            "setting ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR to %d, to force the "
            "update of the VPD ECC data for MVPDs if any VPD ECC data has a mismatch. ",
            sys->getAttr<TARGETING::ATTR_FORCE_ECC_UPDATE_ON_VALIDATION_ERROR>() );
#endif
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms exit" );

    }while(0);

    return l_stepError.getErrorHandle();
}

};
