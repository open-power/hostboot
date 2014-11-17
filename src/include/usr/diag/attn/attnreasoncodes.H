/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/attn/attnreasoncodes.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
 * @file attnreasoncodes.H
 *
 * @brief Reason codes and module ids for ATTN module.
 *
 */
#ifndef __ATTN_ATTNREASONCODES_H
#define __ATTN_ATTNREASONCODES_H

#include <hbotcompid.H>

namespace ATTN
{

/**
* @enum Moduleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum ModuleId
{
    ATTN_INVALID_MODULE             = 0x00,
    ATTN_TEST_FAKE_CALL_PRD         = 0x01, // this is used in test code only.
};

/**
 * @enum ReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum ReasonCode
{
    ATTN_INVALID_REASONCODE     = ATTN_COMP_ID | 0x00,   // Invalid Reasoncode
    ATTN_TEST_ATTN_FAIL         = ATTN_COMP_ID | 0x01,  // this is used in
                                                         // test code only.
};

}
#endif
