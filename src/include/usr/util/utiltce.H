/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utiltce.H $                              */
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
#ifndef __TCEIF_H
#define __TCEIF_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>

#define UTILTCE_TRACE_NAME "UTILTCE"

namespace TCE
{

/*******************************************/
/* General TCE Enable/Disable Functions    */
/*******************************************/

/**
 * @brief Responsible for allocating TCEs
 *
 * @param[in] i_startingAddress - Starting physical address that the allocated
 *                                TCEs will map to.
 *                                Needs to be Page-Aligned or will fail.
 * @param[in] i_size - Size of the address space that TCEs map to.
 *                     Size must be less than (512K * PAGESIZE) or will fail.
 *                     Assert if not greater than zero.
 *
 * Note:  First time this is called will cause TCE Table to be created and
 *        the Processors to be setup to point at the TCE Table
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilAllocateTces(uint64_t i_startingAddress,
                            size_t i_size);

/**
 * @brief Responsible for deallocating TCEs
 *
 * @param[in] i_startingAddress  Starting physical address of the TCEs that
 *                               are to be deallocated from the TCE Table.
 *                               Needs to be page-aligned or will fail.
 * @param[in] i_size - Size of address space that the TCEs that are to
 *                     be deallocated map to.
 *                     Size must be less than (512K * PAGESIZE) or will fail.
 *                     Assert if not greater than zero.
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilDeallocateTces(uint64_t i_startingAddress,
                              size_t i_size);


/**
 * @brief Responsible for disabling TCEs on the system, including
 *        clearing the TCE Table and disabling Processor settings
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilDisableTces(void);


/******************************************************/
/* Specific TCE Setup/Close Functions for PAYLOAD     */
/******************************************************/

/**
 * @brief Responsible for Setting up TCEs for PAYLOAD
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilSetupPayloadTces(void);

/**
 * @brief Responsible for closing the TCEs for PAYLOAD
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilClosePayloadTces(void);

/******************************************************/
/* Miscellaneous Functions                            */
/******************************************************/

/**
 * @brief Indicates if TCEs should be used for DMA path on the system
 *
 * @return bool - TRUE if TCEs should be used; False, if not
 *
 */
bool utilUseTcesForDmas(void);

/**
 * @brief Enables the System to use TCEs without setting up a TCE Table.
 *        This prevents the FSP from using unsecure DMAs during the IPL until
 *        Hostboot sets up the TCE Table with proper TCEs.
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilEnableTcesWithoutTceTable(void);

};

#endif
