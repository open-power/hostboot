/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_attribute_service.H $              */
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
///
/// @file src/include/usr/hwpf/plat/plat_attribute_service.H
///
/// @brief Defines the specialized platform attribute access functions
///
/// Note that platform code must provide the code.
///

#ifndef PLATATTRIBUTESERVICE_H_
#define PLATATTRIBUTESERVICE_H_

#include <attribute_service.H>
#include <plat_chip_ec_feature.H>
namespace fapi2
{

namespace platAttrSvc
{

   // Currently empty because no specialized functions for Hostboot.

} // namespace platAttrSvc

} // namespace fapi2

#endif // PLATATTRIBUTESERVICE_H_
