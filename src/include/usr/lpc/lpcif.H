/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/lpc/lpcif.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
/* [+] Google Inc.                                                        */
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
#ifndef __LPCIF_H
#define __LPCIF_H

#include <errl/errlentry.H>

namespace LPC
{

/**
 * @enum LPC::TransType
 * @brief LPC Transaction Types
 *
 * @note Any changes to this enum should be reflected in lpcxscom.C's
 *     cv_lpcTypeDecoder table which maps each of these enumerators into a
 *     corresponding string.
 *
 */
enum TransType {
    TRANS_IO,  // LPC IO Space
    TRANS_MEM, // LPC Memory Space
    TRANS_FW,  // LPC Firmware Space
    TRANS_REG, // LPCHC Register space
    TRANS_ABS, // Address parm is absolute
    TRANS_ERR, // LPC Register Error Space
    TRANS_LAST // Invalid, used for looping and tests
};

/**
 * @brief Create/delete software objects to support non-master access
 *
 * Only a single altmaster object can be active at any given time.  The
 * previous object must be destroyed before creating another one.
 *
 * @param i_create  true: create objects, false: destroy previous objects
 * @param i_proc  Processor target to use for LPC access
 *
 * @return Error if invalid parms or ordering occurs
 */
errlHndl_t create_altmaster_objects( bool i_create,
                                     TARGETING::Target* i_proc );

/**
 * @brief Return the value of the LPC BAR that the driver is using
 * @return LPC BAR physical address
 */
uint64_t get_lpc_bar( void );

/**
 * @brief Return the value of the LPC BAR that the driver is using
 * @return LPC BAR virtual address
 */
uint64_t get_lpc_virtual_bar( void );


};  // namespace LPC

#endif  // end __LPCIF_H
