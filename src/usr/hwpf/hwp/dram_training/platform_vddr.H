/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/platform_vddr.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// platform specific VDDR support.

#ifndef PLATFORM_VDDR_H__
#define PLATFORM_VDDR_H__

#include <usr/errl/errlentry.H>

/**
 * @brief Enable vspd on DIMMS
 * @return NULL | error handle on error
 */
errlHndl_t platform_enable_vspd();

/**
 * @brief Enable vddr on DIMMS
 * @return NULL | error handle on error
 */
errlHndl_t platform_enable_vddr();

/**
 * @brief Disable vddr on DIMMS
 * @return NULL | error handle on error
 */
errlHndl_t platform_disable_vddr();

#endif  // PLATFORM_VDDR_H__
