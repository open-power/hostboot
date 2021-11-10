/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utillidpnor.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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

#include <util/utillidmgr.H>
#include <utility>
#include <map>

namespace Util
{

// 4 byte LidId string plus NULL
extern const size_t lidIdStrLength;

/** @struct LidAndContainerLid
 *  @brief  Stores the Lid ID and corresponding Container Lid ID for a lid
 *
 *  A Container Lid can be referred to as a Secure Header. The Container Lid ID
 *  is associated with the header data that sits in front of an image.
 */
struct LidAndContainerLid
{
    // Lid ID for content
    LidId lid;
    // Lid ID for Container Lid (Secure Header)
    LidId containerLid;
    LidAndContainerLid() : lid(INVALID_LIDID),containerLid(INVALID_LIDID) {}
    LidAndContainerLid(LidId i_lid, LidId i_containerLid) :
        lid(i_lid), containerLid(i_containerLid) {}
};

typedef std::pair<PNOR::SectionId, LidAndContainerLid> PnorLidsPair;
typedef std::vector<PnorLidsPair> PnorLidsMap;

/**
 * @brief Lookup the PnorToLidsMap array entry for a given SectionId
 *        and set the lid member of the LidAndContainerLid struct
 *        with a given LidId.
 *
 * @param[in] i_sec  The entry to update.
 * @param[in] i_dataLid The value we want to update the entry with.
 *
 * @return error log if an error occurs nullptr otherwise
 */
errlHndl_t updateDataLidMapping(const PNOR::SectionId i_sec,
                                const LidId i_datalid);
/**
  * @brief Returns Lid and ContainerLid (Secure Header) Ids associated with a
  *        PNOR section.
  *
  * @param[in] i_sec     Pnor section to find associated LIDs for
  * @param[in] o_lids    LidAndContainerLid - If found, valid LidIds
  *                      else, invalid LidIds
  * @return error log if an error occurs nullptr otherwise
*/
errlHndl_t getPnorSecLidIds(const PNOR::SectionId i_sec,
                            LidAndContainerLid& o_lids);

/**
  * @brief Returns PNOR section ID associated with a LidID.
  *
  * @param[in] i_lid     LidId to find associated PNOR section for
  *
  * @return  PNOR::SectionId - If found, valid PNOR section
  *                            else, INVALID_SECTION
*/
PNOR::SectionId getLidPnorSection(LidId i_lid);

}

#endif
