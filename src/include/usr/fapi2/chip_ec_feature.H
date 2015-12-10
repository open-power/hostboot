/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/chip_ec_feature.H $                     */
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
#ifndef CHIPECFEATURE_H_
#define CHIPECFEATURE_H_

#include <plat_chip_ec_feature.H>
#include <fapi2_chip_ec_feature.H>

#include <stdint.h>
#include <target.H>
#include <return_code.H>

namespace fapi2
{

///
/// @brief Platform implementation of querying chip ec feature
///
/// This should only be called by FAPI during the processing of a FAPI_ATTR_GET
/// for a Chip EC Feature attribute
///
/// @param[in]  i_id         Attribute ID of the Chip EC Feature
/// @param[in]  i_pTarget    Pointer to chip target
/// @param[out] o_hasFeature Set to 1 if chip has feature else 0
/// @return ReturnCode. Zero on success, else platform specified error
///
template< TargetType K >
ReturnCode queryChipEcFeature(AttributeId i_id,
                              const Target<K>& i_pTarget,
                              uint8_t & o_hasFeature)
{
    ReturnCode l_rc;
    //@todo-RTC:128106
    return l_rc;
}

} // end namespace

#endif // CHIPECFEATURE_H_
