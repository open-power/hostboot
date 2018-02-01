/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utiltce.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
 *
 * @param[in] i_size - Size of the address space that TCEs map to.
 *                     Size must be less than (512K * PAGESIZE) or will fail.
 *                     Assert if not greater than zero.
 *
 * @param[out] o_startingToken - Key to the Starting Entry into the table.
 *                               This is an offset into the array based on the
 *                               TCE Index * PAGESIZE.
 *                               FSP uses the token as a DMA Address.
 *                               Each TCE entry maps to a pagesize of memory.
 *
 * @param[in] i_rwNotRO - TRUE to create TCEs in read-write mode;
 *                        FALSE for read-only mode
 *                        Default is TRUE (read-write mode)
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilAllocateTces(uint64_t  i_startingAddress,
                            size_t    i_size,
                            uint32_t& o_startingToken,
                            const bool i_rwNotRO = true);

/**
 * @brief Responsible for deallocating TCEs
 *
 * @param[in] i_startingToken  Token indicating the starting entry of the
 *                             TCE Table to remove
 *
 * @param[in] i_size - Size of memory space to remove associated TCE entries
 *                     Size must be less than (512K * PAGESIZE) or will fail.
 *                     Assert if not greater than zero.
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilDeallocateTces(uint32_t i_startingToken,
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
 * @brief Responsible for Setting up TCEs for PAYLOAD, including HDAT
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilSetupPayloadTces(void);

/**
 * @brief Responsible for closing the TCEs for PAYLOAD, including HDAT
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
 * @note  This API only works once and only when called before any other TCE
 *        Setup/Allocate functions as its logic only works the first time the
 *        UtilTceMgr Singleton class is created.
 *
 * @return errlHndl_t - Return Error Handle if failed
 *
 */
errlHndl_t utilEnableTcesWithoutTceTable(void);

};

#endif
