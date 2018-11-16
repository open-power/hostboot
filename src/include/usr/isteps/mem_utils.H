/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/mem_utils.H $                          */
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
#ifndef __MEM_UTILS_H
#define __MEM_UTILS_H

#include <errl/errlentry.H>

namespace ISTEP
{

/**
 * @brief Utility function to obtain the highest known address in the system
 *
 * @return The highest address in the system in bytes
 */
uint64_t get_top_mem_addr();

/**
 * @brief Utility function to obtain the highest known address in a given proc
 *
 * @param[in] i_proc: Proc that we want to calculate the top address for;
 *                    must not be nullptr or the func will assert
 *                    must be of TYPE_PROC or the func will assert
 *
 * @return The highest address in the given proc (in bytes)
 */
uint64_t get_top_mem_addr(const TARGETING::Target* i_proc);

/**
 * @brief Utility function to obtain the lowest known address in the system
 *
 * @return the lowest known address in the system
 */
uint64_t get_bottom_mem_addr();

/**
 * @brief Utility function to obtain the lowest known address in a given proc
 *
 * @param[in] i_proc: Proc that we want to calculate the bottom address for;
 *                    must not be nullptr or the func will assert
 *                    must be of TYPE_PROC or the func will assert
 *
 * @return the lowest known address on the specified proc
 */
uint64_t get_bottom_mem_addr(const TARGETING::Target* i_proc);

/**
 * @brief Utility function to obtain the highest known SMF base address on
 *        the system.
 *
 * @return: the address (in bytes) of the top SMF memory
 *
 */
uint64_t get_top_smf_mem_addr();

/**
 * @brief Utility function to obtain the SMF base address on the given proc
 *
 * @param[in] i_proc: Proc to fetch the SMF BAR from;
 *                    must not be nullptr or the func will assert
 *                    must be of TYPE_PROC or the func will assert
 *
 *
 * @return The SMF BAR of the given proc (in bytes)
 */
uint64_t get_top_smf_mem_addr(const TARGETING::Target* i_proc);

/**
 * @brief Utility function to fetch the top of the HOMER memory
 *
 * @return the address of the HOMER mem
 *
 * @note When SMF is enabled, the highest available SMF BAR will be returned;
 *       when SMF is disabled, the function behaves exactly like
 *       get_top_mem_addr
 */
uint64_t get_top_homer_mem_addr();

} //namespace ISTEP

#endif
