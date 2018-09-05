/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/i2c/exp_i2c_fields.C $ */
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
#include <lib/i2c/exp_i2c_fields.H>

namespace mss
{
namespace exp
{
namespace i2c
{

// If a constexpr static data member (since C++11) is odr-used,
// a definition at namespace scope is still required, but it cannot have an initializer.
constexpr mss::field_t<mss::endian::BIG> fields::BOOT_MODE;
constexpr mss::field_t<mss::endian::BIG> fields::LANE_MODE;
constexpr mss::field_t<mss::endian::BIG> fields::SERDES_FREQ;
constexpr mss::field_t<mss::endian::BIG> fields::FW_MODE;
constexpr mss::field_t<mss::endian::BIG> fields::LOOPBACK_TEST;
constexpr mss::field_t<mss::endian::BIG> fields::TRANSPORT_LAYER;
constexpr mss::field_t<mss::endian::BIG> fields::DL_LAYER_BOOT_MODE;
constexpr mss::field_t<mss::endian::BIG> fields::CMD_ID;
constexpr mss::field_t<mss::endian::BIG> fields::STATUS_CODE;
constexpr mss::field_t<mss::endian::BIG> fields::BOOT_STAGE;

}// i2c
}// exp
}// mss
