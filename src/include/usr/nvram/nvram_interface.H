/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/nvram/nvram_interface.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __NVRAM_INTERFACE_H
#define __NVRAM_INTERFACE_H

#include <errl/errlentry.H>

namespace NVRAM_TRACE
{
    extern trace_desc_t * g_trac_nvram;
}

namespace NVRAM
{

extern const char TEST_KEY[];
extern const char SMF_MEM_AMT_KEY[];

/**
 * @brief Utility function to read the i_key from the NVRAM PNOR partition.
 *        The value of the i_key, if any, will reside in o_val after the
 *        function returns. The function attempts to readSectionInfo for
 *        the NVRAM partition and will error if it's unable to read the
 *        section info. o_val will be nullptr if the key is not found in
 *        NVRAM.
 *
 * @param[in] i_key: the key of the key/value pair representing the data
 *                   that needs to be read from NVRAM.
 * @pre              The key should be a null-terminated string and must not be
 *                   nullptr. The function will assert if i_key is nullptr.
 *
 * @param[out] o_val: The pointer to the location in NVRAM where the i_key
 *                    is located or nullptr if the key is not found.
 *
 * @return error handle: nullptr - success; non-nullptr - an error occurred
 */
errlHndl_t nvramRead(const char* i_key, const char*& o_val);

}
#endif
