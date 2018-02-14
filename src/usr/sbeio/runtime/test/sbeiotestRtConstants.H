/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/test/sbeiotestRtConstants.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#ifndef __SBEIO_SBEIO_TEST_RT_CONSTANTS_H
#define __SBEIO_SBEIO_TEST_RT_CONSTANTS_H

// Constants for SBE Message bits in SCOM_ADDR_5003B
const uint32_t SBE_MSG_IN_PROGRESS = 0x40000000;
const uint32_t SBE_MSG_COMPLETE = 0x80000000;
const uint32_t SBE_MSG_MASK = SBE_MSG_COMPLETE | SBE_MSG_IN_PROGRESS;

#endif
