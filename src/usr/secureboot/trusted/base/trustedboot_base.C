/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedboot_base.C $          */
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
 * @file trustedboot_base.C
 *
 * @brief Trusted boot base interfaces
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <sys/time.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <secureboot/trustedbootif.H>
#include "../trustedboot.H"
#include <secureboot/trustedboot_reasoncodes.H>

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_trustedboot = NULL;
TRAC_INIT( & g_trac_trustedboot, "TRBOOT", KILOBYTE );

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace TRUSTEDBOOT
{

/// Global object to store TPM status
SystemTpms systemTpms;

SystemTpms::SystemTpms()
{
}

TpmTarget::TpmTarget()
{
    memset(this, 0, sizeof(TpmTarget));
    mutex_init(&tpmMutex);
}

errlHndl_t pcrExtend(TPM_Pcr i_pcr,
                     uint8_t* i_digest,
                     size_t  i_digestSize,
                     const char* i_logMsg)
{
    errlHndl_t err = NULL;
#ifdef CONFIG_TPMDD
    /// @todo RTC:125288 Add call to extend the PCR

#endif
    return err;
}

} // end TRUSTEDBOOT
