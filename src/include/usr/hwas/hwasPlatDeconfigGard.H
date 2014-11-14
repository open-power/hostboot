/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasPlatDeconfigGard.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
/**
 *  @file hwas/hwasPlatDeconfigGard.H
 *
 *  @brief Defines platform interfaces and whatnot needed for DeconfigGard in the
 *         HWAS common and platform specific functions
 */

#ifndef HWASPLATDECONFIGGARD_H_
#define HWASPLATDECONFIGGARD_H_

#include <pnor/pnorif.H>

/**
 *  @brief Adapt common singleton declaration to specific platform
 *
 *  @param[in] __T__
 *      Type of singleton, fully namespaced
 *
 *  @param[in] __NAME__
 *      Symbol name for singleton
 */
#define HWAS_DECLARE_SINGLETON(__T__,__NAME__) \
    typedef Singleton<__T__> __NAME__;

/**
 *  @brief Adapt common singleton "getter" to the specific platform
 *
 *  @param[in] __TYPE__
 *      Typedef for singleton, as created above
 *
 *  @return Singleton reference for the given singleton
 */
#define HWAS_GET_SINGLETON(__TYPE__) \
    __TYPE__::instance()

namespace HWAS
{

struct HBDeconfigGard
{
    // GARD Record Data
    uint32_t iv_nextGardRecordId;   // Next GARD Record ID to use
    uint32_t iv_maxGardRecords;     // Maximum number of GARD Records
    void *iv_pGardRecords;          // Pointer to the GARD Records in PNOR
};

/**
 *  @brief Gets iv_gardSectionInfo and sets it if first time called.
 *         Sets o_sectionInfo based on iv_gardSectionInfo for the caller
 *
 *  @param[out] Guard PNOR section info
 *
 *  @return errlHndl_t Error log handle, depending on config options will
 *          ignore error because no Guard section exists in PNOR
 *          (e.g. CONFIG_GOLDEN_PNOR_SIDE_SUPPORT)
 *
 */
errlHndl_t getGardSectionInfo(PNOR::SectionInfo_t& o_sectionInfo);

} // namespace HWAS

#endif // HWASPLATDECONFIGGARD_H_
