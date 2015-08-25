/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
 * @file trustedboot.H
 *
 * @brief Trustedboot TPM interfaces
 *
 */
#ifndef __TRUSTEDBOOT_H
#define __TRUSTEDBOOT_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <secureboot/trustedbootif.H>
#include <i2c/tpmddif.H>
#include <trace/interface.H>
#include "trustedTypes.H"

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_trustedboot;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
//#define TRACUBIN(args...)  TRACFBIN(args)
#define TRACUBIN(args...)

#define TB_SUCCESS NULL

namespace TRUSTEDBOOT
{

/// Class object to store system TPM information
class SystemTpms
{
public:
    SystemTpms();

    TpmTarget tpm[MAX_SYSTEM_TPMS];
};


/**
 * @brief Initialize the targetted TPM
 * @param[in/out] io_target Current TPM target structure
 * @param[in] i_nodeTarget Node Target
 * @param[in] i_chip Chip to initialize
*/
void tpmInitialize(TRUSTEDBOOT::TpmTarget & io_target,
                   TARGETING::Target* i_nodeTarget,
                   TPMDD::tpm_chip_types_t i_chip);


} // end TRUSTEDBOOT namespace
#endif
