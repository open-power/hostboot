/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_field.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{
namespace spd
{

// If a constexpr static data member (since C++11) is odr-used,
// a definition at namespace scope is still required, but it cannot have an initializer.
constexpr mss::field_t<mss::endian::LITTLE> init_fields::REVISION;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::DEVICE_TYPE;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::BASE_MODULE;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::HYBRID;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::HYBRID_MEDIA;
constexpr mss::field_t<mss::endian::LITTLE> init_fields::REF_RAW_CARD;

}// spd
}// mss
