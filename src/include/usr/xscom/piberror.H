/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/xscom/piberror.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

#ifndef __PIB_ERROR_H
#define __PIB_ERROR_H

#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <xscom/piberror_common.H>
#include <stdint.h>

namespace PIB
{

/**
 * @brief Add callouts to an errorlog based on the type of PIB error passed in
 *        could be a hardware or procedure callout
 *
 * @param[in]  i_target        Operation target
 * @param[in]  i_pibErrStatus  Error Status bits retrieved
 * @param[in]  i_scomAddr      Address of SCOM operation that led to the fail,
 *    if operation was not a scom, set to UINT64_MAX
 * @param[in/out] io_errl      Originating errorlog that we will add Fru
 *                             Callouts to.
 * @return none
 */
void addFruCallouts(TARGETING::Target* i_target,
                    uint32_t i_pibErrStatus,
                    uint64_t i_scomAddr,
                    errlHndl_t& io_errl);


}

#endif
