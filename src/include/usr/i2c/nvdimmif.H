/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/nvdimmif.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
#include "eepromif.H"

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

};  // end namespace NVDIMM

#endif  // end __NVDIMMIF_H

