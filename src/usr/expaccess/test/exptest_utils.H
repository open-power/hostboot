/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/test/exptest_utils.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef EXPTEST_UTILS_H_
#define EXPTEST_UTILS_H_

#ifndef __HOSTBOOT_RUNTIME
#include <vfs/vfs.H> // module_is_loaded & module_load
#endif

namespace exptest
{

// Need this module for mss::c_str call in HWP failure path traces
const char MSS_LIBRARY_NAME[17]         = "libisteps_mss.so";

/**
 * @brief Generic function to load a module
 * @param o_module_loaded - returns true if module is loaded by this function
 * @param i_modName - module name to load
 * @return error handle if module_load call fails
 */
errlHndl_t loadModule(bool & o_module_loaded, const char * i_modName);

/**
 * @brief Generic function to unload a module
 * @param i_modName - module name to load
 * @return error handle if module_unload call fails
 *
 */
errlHndl_t unloadModule(const char * i_modName);

/**
 * @brief Get the mutex pointer for syncronizing tests
 * @return pointer to mutex, nullptr if not found
 */
TARGETING::HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR getTestMutex(void);

/**
 * @brief Enable inband scoms on an OCMB target
 * @param[in] i_ocmbTarget The target OCMB chip
 */
void enableInbandScomsOcmb(const TARGETING::TargetHandle_t i_ocmbTarget);
}

#endif
