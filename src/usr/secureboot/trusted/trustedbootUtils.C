/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedbootUtils.C $               */
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
/**
 * @file trustedbootUtils.C
 *
 * @brief Trusted boot utility functions
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
#include <targeting/common/targetservice.H>
#include <devicefw/driverif.H>
#include <spi/tpmddif.H>
#include <secureboot/trustedbootif.H>
#include <spi/tpmddreasoncodes.H>
#include <secureboot/trustedboot_reasoncodes.H>
#include "trustedbootUtils.H"
#include "trustedbootCmds.H"
#include "trustedboot.H"
#include "trustedTypes.H"


namespace TRUSTEDBOOT
{

errlHndl_t tpmTransmit(TpmTarget * io_target,
                       uint8_t* io_buffer,
                       size_t i_cmdSize,
                       size_t i_bufsize,
                       tpm_locality_t i_locality)
{
    errlHndl_t err = NULL;

    do
    {
        TRACDCOMP( g_trac_trustedboot,
               ">>TPM OP TRANSMIT : BufLen %d : %016llx, cmdSize = %d",
               static_cast<int>(i_bufsize),
               *(reinterpret_cast<uint64_t*>(io_buffer)),
               static_cast<int>(i_cmdSize) );

        // Send to the TPM
        err = deviceRead(io_target,
                         io_buffer,
                         i_bufsize,
                         DEVICE_TPM_ADDRESS(TPMDD::TPM_OP_TRANSMIT,
                                            i_cmdSize,
                                            i_locality));
        TRACDCOMP( g_trac_trustedboot,
              "<<TPM OP TRANSMIT : BufLen %d : %016llx, cmdSize = %d DONE, rc=0x%X",
               static_cast<int>(i_bufsize),
               *(reinterpret_cast<uint64_t*>(io_buffer)),
               static_cast<int>(i_cmdSize),
               ERRL_GETRC_SAFE(err) );
        if (NULL != err)
        {
            break;
        }

    } while ( 0 );

    return err;
}

errlHndl_t tpmCreateErrorLog(
    const uint8_t  i_modId,
    const uint16_t i_reasonCode,
    const uint64_t i_user1,
    const uint64_t i_user2,
    const bool     i_addSwCallout)
{
    errlHndl_t pError =
        new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            i_modId,
            i_reasonCode,
            i_user1,
            i_user2,
            i_addSwCallout);

    pError->collectTrace(SECURE_COMP_NAME);
    pError->collectTrace(TRBOOT_COMP_NAME);

    return pError;
}

} // end TRUSTEDBOOT
