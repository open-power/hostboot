/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utillidpnor.C $                                  */
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

#include <util/utillidmgr.H>
#include <util/utillidpnor.H>
#include <config.h>
#ifdef CONFIG_SECUREBOOT
#include <pnor/pnorif.H>
#include <errl/errlmanager.H>
#endif

#include <utility>
#include <map>
#include <trace/interface.H>
#include "utilbase.H"

namespace Util
{

const size_t lidIdStrLength = 9;

//  Map of PNOR section Ids to pairs of LidIds
//  Key - PNOR section
//  Value - LidAndContainerLid
//          The first Lid in the pair is the image content
//          The second Lid in the pair is the Container LID (Secure Header)
static const PnorLidsMap PnorToLidsMap =
{
    { PNOR::TESTRO,  LidAndContainerLid(TEST_LIDID, INVALID_LIDID)},
    { PNOR::OCC,     LidAndContainerLid(OCC_LIDID, OCC_CONTAINER_LIDID)},
    { PNOR::WOFDATA, LidAndContainerLid(WOF_LIDID, WOF_CONTAINER_LIDID)},
    { PNOR::HCODE,   LidAndContainerLid(NIMBUS_HCODE_LIDID, HCODE_CONTAINER_LIDID)},
    /* @TODO RTC:177927 - Figure out how to handle different Lids for the
                              same PNOR section based on chip.
    { PNOR::HCODE,   LidAndContainerLid(CUMULUS_HCODE_LIDID, HCODE_CONTAINER_LIDID)},
    */
    { PNOR::RINGOVD, LidAndContainerLid(HWREFIMG_RINGOVD_LIDID,INVALID_LIDID)},
};

LidAndContainerLid getPnorSecLidIds(const PNOR::SectionId i_sec)
{
    LidAndContainerLid l_lids;

    auto l_secIter = PnorToLidsMap.find(i_sec);
    if (l_secIter != PnorToLidsMap.end())
    {
        l_lids.lid = l_secIter->second.lid;
        l_lids.containerLid = l_secIter->second.containerLid;
    }

    return l_lids;
}

PNOR::SectionId getLidPnorSection(const LidId i_lid)
{
    PNOR::SectionId l_secId  = PNOR::INVALID_SECTION;

    // Search map by value
    // Note: Sacrificed constant look up with another map in the reverse
    //       direction to simplify maintenance with a single map
    auto l_secIter = std::find_if( PnorToLidsMap.begin(),
                                   PnorToLidsMap.end(),
                                   [i_lid](const PnorLidsPair & pair) -> bool
                                 {
                                     return pair.second.lid == i_lid;
                                 });
    // Check if we found a valid entry.
    if (l_secIter != PnorToLidsMap.end())
    {
        l_secId = l_secIter->first;
    }

    return l_secId;
}

} // end Util namespace

bool UtilLidMgr::getLidPnorSectionInfo(uint32_t i_lidId,
                                       PNOR::SectionInfo_t &o_lidPnorInfo)
{
    errlHndl_t l_err = NULL;
    bool l_lidInPnor = false;

    // Search if a lid id maps to pnor section
    auto l_secId = Util::getLidPnorSection(static_cast<Util::LidId>(i_lidId));

    // LidToPnor will return INVALID_SECITON if no mapping found
    if (l_secId == PNOR::INVALID_SECTION)
    {
        UTIL_FT("UtilLidMgr::getLidPnorSection lid 0x%X not in PNOR", i_lidId);
        o_lidPnorInfo.id = PNOR::INVALID_SECTION;
    }
    // A mapping was found
    else
    {
        l_err = PNOR::getSectionInfo(l_secId, o_lidPnorInfo);
        // Section is optional or lid is not in PNOR, so just delete error
        if (l_err)
        {
            o_lidPnorInfo.id = PNOR::INVALID_SECTION;
            delete l_err;
            l_err = NULL;
        }
        else
        {
            l_lidInPnor = true;
            UTIL_FT("UtilLidMgr::getLidPnorSection Lid 0x%X in PNOR", i_lidId);
#ifdef CONFIG_SECUREBOOT
#ifndef __HOSTBOOT_RUNTIME
            // The lid could be securely signed in PNOR
            if(o_lidPnorInfo.secure)
            {
                UTIL_FT("UtilLidMgr::getLidPnorSection verify Lid in PNOR");

                // Load the secure section
                l_err = loadSecureSection(l_secId);

                // If secure section fails to load log the error and assert
                if (l_err)
                {
                    errlCommit(l_err, UTIL_COMP_ID);
                    assert(false,"UtilLidMgr::getLidPnorSectionInfo: attempt to "
                                 "load Secure Section %d failed",
                                 l_secId);
                }

                // In Secureboot, rather than using the whole partition size,
                // only use the protected payload size that the Secure PnorRP
                // handles. This limits the memory footprint and prevents
                // downstream logic from going past the end of the image.
                // NOTE:  This assumes that any secure lid loaded from PNOR by
                // UtilLidMgr does not contain an unprotected section
                iv_lidPnorInfo.size = iv_lidPnorInfo.secureProtectedPayloadSize;
            }
#endif
#endif
        }
    }
    return l_lidInPnor;
}