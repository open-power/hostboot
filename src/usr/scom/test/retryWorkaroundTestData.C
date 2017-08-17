/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/test/retryWorkaroundTestData.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include "retryWorkaroundTestData.H"

// A set of addresses that never require a SCOM DMI retry
std::vector<uint64_t> g_always_no_retry_addrs = {
                                                 0x1319821,
                                                 0x1319822,
                                                 0x1319921,
                                                 0x1319922,
                                                 0x1319a21,
                                                 0x1319a22,
                                                 0x1319b21,
                                                 0x1319b22,

                                                 0xF319821,
                                                 0xF319822,
                                                 0xF319921,
                                                 0xF319922,
                                                 0xF319a21,
                                                 0xF319a22,
                                                 0xF319b21,
                                                 0xF319b22,

                                                 0x40108a3,
                                                 0x40108a4,
                                                 0x40108a5,
                                                 0x40108a6,
                                                 0x40108a7,
                                                 0x40108a8,
                                                 0x40108a9,
                                                 0x40108aa,

                                                 0x3010820,
                                                 0x3010821,
                                                 0x3010822,
                                                 0x301082b,
                                                 0x301082c,
                                                 0x301082d,
                                                 0x301082e,
                                                 0x301082f,

                                                 0x3010830,
                                                 0x3010831,
                                                 0x3010832,
                                                 0x301083b,
                                                 0x301083c,
                                                 0x301083d,
                                                 0x301083e,
                                                 0x301083f,

                                                 0x30108a0,
                                                 0x30108a1,
                                                 0x30108a2,
                                                 0x30108ab,
                                                 0x30108ac,
                                                 0x30108ad,
                                                 0x30108ae,
                                                 0x30108af,

                                                 0x30108b0,
                                                 0x30108b1,
                                                 0x30108b2,
                                                 0x30108bb,
                                                 0x30108bc,
                                                 0x30108bd,
                                                 0x30108be,
                                                 0x30108bf,

                                                 0x3010803,
                                                 0x3010813,
                                                 0x3010843,
                                                 0x3010853,
                                                 0x3010863,
                                                 0x3010873,
                                                 0x3010883,
                                                 0x3010893,
                                                 0x30108c3,
                                                 0x30108d3,
                                                 0x30108e3,
                                                 0x30108f3,
                                             };

//All of the following addresses require retries
std::vector<uint64_t> g_always_retry_addrs =
                                         {
                                             //dmi-4
                                             0x3010823,
                                             0x3010824,
                                             0x3010825,
                                             0x3010826,
                                             0x3010827,
                                             0x3010828,
                                             0x3010829,
                                             0x301082a,

                                             //dmi-5
                                             0x3010833,
                                             0x3010834,
                                             0x3010835,
                                             0x3010836,
                                             0x3010837,
                                             0x3010838,
                                             0x3010839,
                                             0x301083a,

                                             //dmi-6
                                             0x30108a3,
                                             0x30108a4,
                                             0x30108a5,
                                             0x30108a6,
                                             0x30108a7,
                                             0x30108a8,
                                             0x30108a9,
                                             0x30108aa,

                                             //dmi-7
                                             0x30108b3,
                                             0x30108b4,
                                             0x30108b5,
                                             0x30108b6,
                                             0x30108b7,
                                             0x30108b8,
                                             0x30108b9,
                                             0x30108ba,

                                             //dmi-0
                                             0x5010823,
                                             0x5010824,
                                             0x5010825,
                                             0x5010826,
                                             0x5010827,
                                             0x5010828,
                                             0x5010829,
                                             0x501082a,

                                             //dmi-1
                                             0x5010833,
                                             0x5010834,
                                             0x5010835,
                                             0x5010836,
                                             0x5010837,
                                             0x5010838,
                                             0x5010839,
                                             0x501083a,

                                             //dmi-2
                                             0x50108a3,
                                             0x50108a4,
                                             0x50108a5,
                                             0x50108a6,
                                             0x50108a7,
                                             0x50108a8,
                                             0x50108a9,
                                             0x50108aa,

                                             //dmi-3
                                             0x50108b3,
                                             0x50108b4,
                                             0x50108b5,
                                             0x50108b6,
                                             0x50108b7,
                                             0x50108b8,
                                             0x50108b9,
                                             0x50108ba
                                       };
