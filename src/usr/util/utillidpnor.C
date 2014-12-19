/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utillidpnor.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include <util/utillidmgr.H>
#include <utility>
#include "utillidpnor.H"

bool UtilLidMgr::getLidPnorSection(uint32_t i_lidId,
                                   PNOR::SectionInfo_t &o_lidPnorInfo)
{
    errlHndl_t l_err = NULL;
    bool l_lidInPnor = false;

    const std::pair<uint32_t, PNOR::SectionId> l_lid(i_lidId,
                                                     PNOR::INVALID_SECTION);

    const std::pair<uint32_t, PNOR::SectionId>* l_result =
                            std::lower_bound (Util::lidToPnor,
                                        Util::lidToPnor + Util::NUM_LID_TO_PNOR,
                                        l_lid,
                                        Util::cmpLidToPnor);

    if (l_result != (Util::lidToPnor + Util::NUM_LID_TO_PNOR) &&
        l_result->first == l_lid.first &&
        l_result->second != PNOR::INVALID_SECTION)
    {
        l_err = PNOR::getSectionInfo(l_result->second, o_lidPnorInfo);
        // Section is optional or lid is not in PNOR, so just delete error
        if (l_err)
        {
            o_lidPnorInfo.id = PNOR::INVALID_SECTION;
            l_lidInPnor = false;
            delete l_err;
            l_err = NULL;
        }
        else
        {
            l_lidInPnor = true;
        }
    }
    return l_lidInPnor;

}