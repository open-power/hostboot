/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/nvdimmif.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2019                        */
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
#ifndef __NVDIMMIF_H
#define __NVDIMMIF_H

#include <list>
#include <i2c/eepromif.H>

namespace NVDIMM
{

/**
 * @brief Return a set of information related to every unique
 *        NVDIMM in the system
 *
 * @param[out] o_info - list of NVDIMM Information
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
void getNVDIMMs( std::list<EEPROM::EepromInfo_t>& o_info );

/**
 * @brief Check if given address is owned by nvdimms and return
          a new address that isn't if it was
 * @param[in] i_topAddr = High mainstore address (see get_top_homer_mem_addr)
 * @return uint64_t - Highest address without a nvdimm
 */
uint64_t get_top_addr_with_no_nvdimms( uint64_t i_topAddr );

// Make a very simple inline if we don't support NVDIMMs in this compile
#ifndef CONFIG_NVDIMM
inline uint64_t get_top_addr_with_no_nvdimms( uint64_t i_topAddr )
{
    return i_topAddr;
};
#endif

};  // end namespace NVDIMM

#endif  // end __NVDIMMIF_H

