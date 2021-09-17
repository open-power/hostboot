/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/progressSrc.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
 *  @file progressSrc.C
 *
 *  @brief Implementation of progressSrc class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include "progressSrc.H"
#include <errl/errlentry.H>
#include <errl/hberrltypes.H>
#include <targeting/targplatutil.H>
#include <util/misc.H>
#include <pldm/requests/pldm_fileio_requests.H>

using namespace ERRORLOG;

namespace INITSERVICE
{
extern trace_desc_t *g_trac_initsvc;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ProgressCodeSrc::ProgressCodeSrc( uint8_t i_major_istep,
                                  uint8_t i_minor_istep,
                                  uint8_t i_rolling_count )
{
    // build ProgressCode based on input
    iv_progressCode.progress_code = 0;

    // set hostboot settings
    // 'CC' = Hostboot IPL Progress code SRC
    iv_progressCode.srcitype = SRC_IPL_STATUS;

    // grab nodeId
    iv_progressCode.nodeID = TARGETING::UTIL::getCurrentNodePhysId();

    iv_progressCode.iplCompID = 9; // HWSV_PROG_CODE_IPL_COMP_ID

    iv_progressCode.rollingCounter = i_rolling_count;
    iv_progressCode.majorNo = i_major_istep;
    iv_progressCode.minorNo = i_minor_istep;
    TRACDCOMP(g_trac_initsvc,
        "ProgressCodeSrc constructor done -> %08X progress code",
        iv_progressCode.progress_code);
}

uint64_t ProgressCodeSrc::flatten(void * o_pBuffer, const uint64_t i_cbBuffer)
{
    assert(i_cbBuffer >= sizeof(SrcSection),
      "ProgressCodeSrc can not be flattened in %lld bytes (need %lld)",
      i_cbBuffer, flatSize());

    SrcSection * pSrc = reinterpret_cast<SrcSection *>(o_pBuffer);

    memset(pSrc, 0, sizeof(SrcSection));

    pSrc->ver = 2;
    pSrc->flags.srcIsPostedToOpPanel = 1;
    pSrc->wordcount = 9;
    pSrc->srcLength = sizeof(SrcSection);
    pSrc->word2 = 0xE0;  // SRC_format for 0xCC progress code
    pSrc->word4 = iv_progressCode.progress_code;

    // memset spaces into the char array
    memset( pSrc->srcString, ' ', sizeof( pSrc->srcString ) );
    int nullIdx = sprintf(pSrc->srcString, "%08X", iv_progressCode.progress_code);
    pSrc->srcString[nullIdx] = ' ';

    return sizeof(SrcSection);
}

uint64_t ProgressCodeSrc::flatSize() const
{
    return sizeof(SrcSection);
}

#ifdef CONFIG_PLDM
errlHndl_t ProgressCodeSrc::sendProgressCodeToBmc()
{
    uint32_t l_bufsize = sizeof(SrcSection);
    uint8_t l_buffer[l_bufsize];
    flatten(l_buffer, l_bufsize);

    TRACFCOMP(g_trac_initsvc, "sendProgressCodeToBmc(): sending %08X progress code",
        iv_progressCode.progress_code);

    // update last code sent
    if(Util::isTargetingLoaded() && TARGETING::targetService().isInitialized())
    {
        TARGETING::Target * l_node = TARGETING::UTIL::getCurrentNodeTarget();
        if (l_node != nullptr)
        {
            l_node->setAttr<TARGETING::ATTR_LAST_PROGRESS_CODE>(iv_progressCode.progress_code);
        }
    }
    else
    {
        TRACFCOMP(g_trac_initsvc,
            "sendProgressCodeToBmc(): targeting unavailable to update ATTR_LAST_PROGRESS_CODE (%08X)",
            iv_progressCode.progress_code);
    }
    return PLDM::sendProgressSrc(l_buffer, l_bufsize);
}
#endif

};
