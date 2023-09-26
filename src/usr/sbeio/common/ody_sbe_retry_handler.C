/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/common/ody_sbe_retry_handler.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <trace/interface.H>
#include <sbeio/sbe_retry_handler.H>
#include <targeting/targplatutil.H>
#include <targeting/odyutil.H>
#include <sbeio/sbeioreasoncodes.H>
#include <errl/errlreasoncodes.H>
#include "sbe_fifodd.H"

#include <ody_extract_sbe_rc.H>

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"fifodd: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

namespace SBEIO
{

GenericSbeRetryHandler::~GenericSbeRetryHandler()
{
}

/**
 * OdysseySbeRetryHandler implementation
 */

OdysseySbeRetryHandler::OdysseySbeRetryHandler(TARGETING::Target* const i_ocmb)
    : iv_ocmb(i_ocmb)
{
}

void OdysseySbeRetryHandler::main_sbe_handler(const bool i_sbeHalted)
{
    SBE_TRACF(ENTER_MRK"OdysseySberetryhandler::main_sbe_handler(0x%08x)",
              get_huid(iv_ocmb));

    errlHndl_t errl = ExtractRC();

    if (errl)
    {
        SBE_TRACF("OdysseySbeRetryHandler: ody_extract_sbe_rc returned "
                  "an error 0x%08x",
                  ERRL_GETEID_SAFE(errl));

        errlCommit(errl, SBEIO_COMP_ID);
    }
    else
    {
        SBE_TRACF("OdysseySbeRetryHandler: ody_extract_sbe_rc did not "
                  "find any error");
    }

#ifdef __HOSTBOOT_RUNTIME
    // @TODO JIRA: PFHB-289 HRESET the Odyssey here
#else
    // @TODO JIRA: PFHB-290 Dump the Odyssey SBE HERE
#endif

    SBE_TRACF(EXIT_MRK"OdysseySbeRetryHandler::main_sbe_handler(0x%08x)",
              get_huid(iv_ocmb));
}

errlHndl_t OdysseySbeRetryHandler::ExtractRC()
{
    errlHndl_t l_errl = nullptr;
    FAPI_INVOKE_HWP(l_errl, ody_extract_sbe_rc, { iv_ocmb });

    if (l_errl && l_errl->getUserData1() == fapi2::RC_SPPE_RUNNING)
    { // if the SPPE is running, the error log doesn't contain anything useful.
        delete l_errl;
        l_errl = nullptr;
    }

    return l_errl;
}

OdysseySbeRetryHandler::~OdysseySbeRetryHandler()
{
}

}
