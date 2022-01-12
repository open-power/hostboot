/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utillidpnor.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#include <pnor/pnorif.H>
#include <errl/errlmanager.H>

#include <utility>
#include <map>
#include <trace/interface.H>
#include "utilbase.H"
#include <initservice/initserviceif.H>
#include <pnor/pnor_reasoncodes.H>
#include <util/util_reasoncodes.H>


namespace Util
{

const size_t lidIdStrLength = 9;

//  Map of PNOR section Ids to pairs of LidIds
//  Key - PNOR section
//  Value - LidAndContainerLid
//          The first Lid in the pair is the image content
//          The second Lid in the pair is the Container LID (Secure Header)
//
//  SPECIAL NOTE: HCODE_LID is listed first in table lookups
//  to allow prioritization of picking the non-HPT HCODE_LID partition
//  to insulate the HPT handling from affecting the LID validation steps.
static PnorLidsMap PnorToLidsMap =
{
    { PNOR::TESTRO,      LidAndContainerLid(TEST_LIDID, INVALID_LIDID)},
    { PNOR::OCC,         LidAndContainerLid(OCC_LIDID, OCC_CONTAINER_LIDID)},
#ifdef CONFIG_PLDM
    { PNOR::WOFDATA,     LidAndContainerLid(INVALID_LIDID, WOF_CONTAINER_LIDID)},
    { PNOR::HB_DATA,     LidAndContainerLid(INVALID_LIDID, TARGETING_CONTAINER_LIDID)},
#else
    { PNOR::WOFDATA,     LidAndContainerLid(WOF_LIDID, WOF_CONTAINER_LIDID)},
#endif
    { PNOR::HCODE_LID,   LidAndContainerLid(P10_HCODE_LIDID, HCODE_CONTAINER_LIDID)},
    { PNOR::HCODE,       LidAndContainerLid(P10_HCODE_LIDID, HCODE_CONTAINER_LIDID)},
    { PNOR::RINGOVD,     LidAndContainerLid(HWREFIMG_RINGOVD_LIDID,INVALID_LIDID)},
};

static mutex_t pnor_lid_map_mutex = MUTEX_INITIALIZER;

errlHndl_t updateDataLidMapping(const PNOR::SectionId i_sec,
                                const LidId i_datalid)
{
    errlHndl_t errl = nullptr;
    mutex_lock(&pnor_lid_map_mutex);
    auto l_secIter = std::find_if(PnorToLidsMap.begin(),
                                  PnorToLidsMap.end(),
                                  [i_sec](const PnorLidsPair & pair) -> bool
                                  {
                                      return pair.first == i_sec;
                                  });
    if (l_secIter != PnorToLidsMap.end())
    {
        l_secIter->second.lid = i_datalid;
    }
    else
    {
        UTIL_FT("UtilLidMgr::updateDataLidMapping unable to find mapping for section %d when trying to update the mapping value with 0x%lx",
                i_sec, i_datalid);
        /*@
          * @errortype
          * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
          * @moduleid   Util::UTIL_UPDATE_DATA_LID_MAP
          * @reasoncode Util::UTIL_NO_MAP_ENTRY
          * @userdata1  PNOR section Id we tried to lookup
          * @userdata2  Data lid value we tried to update with
          * @devdesc    Software problem, trying to update a lid the lidpnor
          *             code doesn't know about
          * @custdesc   A software error occurred during system boot
          */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              Util::UTIL_UPDATE_DATA_LID_MAP,
                              Util::UTIL_NO_MAP_ENTRY,
                              i_sec,
                              i_datalid,
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        errl->collectTrace(UTIL_COMP_NAME);
    }
    mutex_unlock(&pnor_lid_map_mutex);
    return errl;
}

errlHndl_t getPnorSecLidIds(const PNOR::SectionId i_sec,
                            LidAndContainerLid& o_lids)
{
    errlHndl_t errl = nullptr;
    mutex_lock(&pnor_lid_map_mutex);

    auto l_secIter = std::find_if(PnorToLidsMap.begin(),
                                  PnorToLidsMap.end(),
                                  [i_sec](const PnorLidsPair & pair) -> bool
                                  {
                                      return pair.first == i_sec;
                                  });
    if (l_secIter != PnorToLidsMap.end())
    {
        o_lids.lid = l_secIter->second.lid;
        o_lids.containerLid = l_secIter->second.containerLid;
    }
    else
    {
        // Make sure the LidAndContainerLid object we return has invalid ids set
        o_lids.lid = INVALID_LIDID;
        o_lids.containerLid = INVALID_LIDID;
        UTIL_FT("UtilLidMgr::getPnorSecLidIds unable to find mapping for section %d", i_sec);
        /*@
          * @errortype
          * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
          * @moduleid   Util::UTL_GET_PNOR_SEC_LID_IDS
          * @reasoncode Util::UTIL_NO_MAP_ENTRY
          * @userdata1  PNOR section Id we tried to lookup
          * @userdata2  Unused
          * @devdesc    Software problem, trying to lookup a lid the lidpnor
          *             code doesn't know about
          * @custdesc   A software error occurred during system boot
          */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              Util::UTL_GET_PNOR_SEC_LID_IDS,
                              Util::UTIL_NO_MAP_ENTRY,
                              i_sec,
                              0,
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        errl->collectTrace(UTIL_COMP_NAME);
    }
    mutex_unlock(&pnor_lid_map_mutex);
    return errl;
}

PNOR::SectionId getLidPnorSection(const LidId i_lid)
{
    PNOR::SectionId l_secId  = PNOR::INVALID_SECTION;
    mutex_lock(&pnor_lid_map_mutex);
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
    mutex_unlock(&pnor_lid_map_mutex);
    return l_secId;
}

} // end Util namespace

// No support for PNOR at runtime
#ifndef __HOSTBOOT_RUNTIME

errlHndl_t UtilLidMgr::getLidPnorSectionInfo(const uint32_t i_lidId,
                                             PNOR::SectionInfo_t &o_lidPnorInfo,
                                             bool &o_isLidInPnor)
{
    errlHndl_t l_err = nullptr;
    o_isLidInPnor = false;

    // Search if a lid id maps to pnor section
    auto l_secId = Util::getLidPnorSection(static_cast<Util::LidId>(i_lidId));

    do {
    // LidToPnor will return INVALID_SECITON if no mapping found
    if (l_secId == PNOR::INVALID_SECTION)
    {
        UTIL_FT("UtilLidMgr::getLidPnorSectionInfo lid 0x%X not in PNOR", i_lidId);
        o_lidPnorInfo.id = PNOR::INVALID_SECTION;
    }
    // A mapping was found
    else
    {
        // PNOR section is optional or lid is not in PNOR, so just delete error
        // During IPL
        //    PNOR section may be optional
        l_err = PNOR::getSectionInfo(l_secId, o_lidPnorInfo);
        if (l_err &&
            (l_err->reasonCode() == PNOR::RC_INVALID_SECTION)
           )
        {
            o_lidPnorInfo.id = PNOR::INVALID_SECTION;
            delete l_err;
            l_err = nullptr;
            UTIL_FT("UtilLidMgr::getLidPnorSectionInfo Lid 0x%X ignore getSectionInfo INVALID_SECTION error",
                    i_lidId);
            break;
        }
        else if (l_err)
        {
            UTIL_FT(ERR_MRK"UtilLidMgr::getLidPnorSectionInfo Lid 0x%X getSectionInfo failed rc=0x%08X",
                    l_err->reasonCode());
            break;
        }
        else
        {
            o_isLidInPnor = true;
            UTIL_FT("UtilLidMgr::getLidPnorSectionInfo Lid 0x%X in PNOR", i_lidId);
#ifdef CONFIG_SECUREBOOT
            // The lid could be securely signed in PNOR
            if(o_lidPnorInfo.secure)
            {
                UTIL_FT("UtilLidMgr::getLidPnorSectionInfo verify Lid in PNOR");

                // Load the secure section
                l_err = loadSecureSection(l_secId);
                if (l_err)
                {
                     UTIL_FT("UtilLidMgr::getLidPnorSectionInfo loadSecureSection failed for Section %d",
                             l_secId);
                     break;
                }

                // In Secureboot, rather than using the whole partition size,
                // only use the protected payload size that the Secure PnorRP
                // handles. This limits the memory footprint and prevents
                // downstream logic from going past the end of the image.
                // NOTE:  This assumes that any secure lid loaded from PNOR by
                // UtilLidMgr does not contain an unprotected section
                // In this case of hash tables, we need to load the entire
                // partition size because the user data is part of the
                // unprotected payload
                if (!iv_lidPnorInfo.hasHashTable)
                {
                    iv_lidPnorInfo.size = iv_lidPnorInfo.secureProtectedPayloadSize;
                }
            }
#endif
        }
    }
    } while(0);

    return l_err;
}

#endif //#ifndef __HOSTBOOT_RUNTIME
