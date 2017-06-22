/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utillidpnor.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#ifndef _UTILLIDPNOR_H
#define _UTILLIDPNOR_H

/**
 * @file lidpnor.H
 *
 * @brief brief Provides the lid to pnor mapping currently used in the lidmgr
 *              In its own file to limit number of duplicate definitions for
 *              every user compared to being defined in utillidmgr
 *
 */

#include <util/utillidmgr.H>
#include <utility>

namespace Util
{

/**
 *  @brief Simple compare function for lidToPnor elements
 */
bool cmpLidToPnor (const std::pair<uint32_t, PNOR::SectionId> p1,
                   const std::pair<uint32_t, PNOR::SectionId> p2)
{
    return (p1.first < p2.first);
}

/**
 *  @brief Array containing lid to pnor mappings
 *         When adding maintain order by uint32_t (lidID)
 *         There is a test case to confirm this is sorted
 */
const std::pair<uint32_t, PNOR::SectionId>
    lidToPnor[] =
    {
        std::make_pair(Util::TEST_LIDID, PNOR::TESTRO),            // 0x00000111
        std::make_pair(Util::OCC_LIDID, PNOR::OCC),                // 0x81e00430
        std::make_pair(Util::WOF_LIDID, PNOR::WOFDATA),            // 0x81e00440
        std::make_pair(Util::NIMBUS_HCODE_LIDID, PNOR::HCODE),     // 0x81e00602
        std::make_pair(Util::CUMULUS_HCODE_LIDID, PNOR::HCODE),    // 0x81e00603
        std::make_pair(Util::HWREFIMG_RINGOVD_LIDID, PNOR::RINGOVD)// 0x81e00620
    };

// Size of lidToPnor[]
const size_t NUM_LID_TO_PNOR = ( sizeof(lidToPnor) /
                                 sizeof(std::pair<uint32_t, PNOR::SectionId>));

}

#endif
