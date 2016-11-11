/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/service.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#include <secureboot/service.H>
#include <stdint.h>
#include <sys/mm.h>
#include <util/singleton.H>
#include <secureboot/secure_reasoncodes.H>
#include <config.h>
#include <devicefw/userif.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <initservice/initserviceif.H>
#include <secureboot/settings.H>
#include <secureboot/header.H>
#include "purge.H"
#include <kernel/misc.H>
#include <kernel/console.H>
#include <console/consoleif.H>

#include "../common/securetrace.H"

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


using namespace ERRORLOG;
using namespace TARGETING;

namespace SECUREBOOT
{

// TODO securebootp9 - Do a diff of this file with the p8 version make sure
// all the missing parts are brought in.

void* initializeBase(void* unused)
{
    errlHndl_t l_errl = NULL;

    do
    {

        // Load original secureboot header.
        if (enabled())
        {
            Singleton<Header>::instance().loadBaseHeader();
        }

        // Extend memory footprint into lower portion of cache.
        assert(0 == mm_extend(MM_EXTEND_PARTIAL_CACHE));

        // Don't extend more than 1/2 cache in VPO as fake PNOR is there
        // Don't enable SecureROM in VPO
#ifndef CONFIG_P9_VPO_COMPILE
        // Run dcbz on the entire 10MB cache
        assert(0 == mm_extend(MM_EXTEND_FULL_CACHE));

        // Initialize the Secure ROM
        l_errl = initializeSecureROM();
        if (l_errl)
        {
            break;
        }
#endif
    } while(0);

    return l_errl;
}

bool enabled()
{
    return Singleton<Settings>::instance().getEnabled();
}

errlHndl_t getSecuritySwitch(uint64_t& o_regValue, TARGETING::Target* i_targ)
{
    return Singleton<Settings>::instance().getSecuritySwitch(o_regValue,i_targ);
}

errlHndl_t getJumperState(SecureJumperState& o_state, TARGETING::Target* i_targ)
{
    return Singleton<Settings>::instance().getJumperState(o_state, i_targ);
}

void handleSecurebootFailure(errlHndl_t &io_err, bool i_waitForShutdown)
{
    TRACFCOMP( g_trac_secure, ENTER_MRK"handleSecurebootFailure()");

    assert(io_err != NULL, "Secureboot Failure has a NULL error log")

    // Grab errlog reason code before committing.
    uint16_t l_rc = io_err->reasonCode();

#ifdef CONFIG_CONSOLE
    CONSOLE::displayf(SECURE_COMP_NAME, "Secureboot Failure plid = 0x%08X, rc = 0x%04X\n",
                      io_err->plid(), l_rc);
#endif
    printk("Secureboot Failure plid = 0x%08X, rc = 0x%04X\n",
           io_err->plid(),l_rc);

    // Add Verification callout
    io_err->addProcedureCallout(HWAS::EPUB_PRC_FW_VERIFICATION_ERR,
                               HWAS::SRCI_PRIORITY_HIGH);
    errlCommit(io_err, SECURE_COMP_ID);

    // Shutdown with Secureboot error status
    INITSERVICE::doShutdown(l_rc, !i_waitForShutdown);
}

} //namespace SECUREBOOT
