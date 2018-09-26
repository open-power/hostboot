/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/smf_utils.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __SMF_UTILS_H
#define __SMF_UTILS_H

#include <stdint.h>
#include <errl/errlentry.H>

namespace SECUREBOOT
{

namespace SMF
{

// HW limitations dictate that SMF memory needs to be a power-of-two
// multiple of 256MB starting with 256MB.
extern const uint64_t MIN_SMF_MEMORY_AMT;

/**
 * @brief Checks whether SMF mode is enabled on the system
 *
 * @return true: SMF is enabled; false: SMF is disabled.
 */
bool isSmfEnabled();

/**
 * @brief Checks whether the system has the correct risk level to
 *        support SMF: SMF is supported on Axone by default or on
 *        NIMBUS or CUMULUS with risk level >= 4.
 *
 * @return nullptr: the current system supports SMF
 *         non-nullptr: an internal error occurred or the system
 *                      does not support SMF
 */
errlHndl_t checkRiskLevelForSmf();

} // namespace SMF

} // namespace SECUREBOOT
#endif
