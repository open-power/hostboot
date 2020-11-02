/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatcommonutil.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#include <ctype.h>
#include "hdattpmdata.H"
#include <util/align.H>
#include <algorithm>

#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <securerom/ROM.H>

namespace HDAT
{
trace_desc_t *g_trac_hdat = nullptr;
TRAC_INIT(&g_trac_hdat,HDAT_COMP_NAME,4096);

/** @brief Structure id for an HDIF structure*/
const uint16_t HDAT_HDIF_STRUCT_ID = 0xD1F0;

/** @brief Align value for HDAT instances */
const uint8_t HDAT_HDIF_ALIGN = 128;

const char g_hdatTpmDataEyeCatch[] = "TPMREL";

uint16_t hdatCalcMaxTpmsPerNode()
{
    size_t l_maxTpms = 0;

    // calculate max # of TPMs per node

    // look for class ENC type NODE and class chip TPM to find TPMs
    TARGETING::TargetHandleList l_nodeEncList;

    getEncResources(l_nodeEncList, TARGETING::TYPE_NODE,
        TARGETING::UTIL_FILTER_ALL);

    // loop thru the nodes and check number of TPMs
    std::for_each(l_nodeEncList.begin(), l_nodeEncList.end(),
    [&l_maxTpms](const TARGETING::Target* const i_pNode)
    {
        // for this Node, get a list of tpms
        TARGETING::TargetHandleList l_tpmChipList;

        getChildAffinityTargets ( l_tpmChipList, i_pNode,
                        TARGETING::CLASS_CHIP, TARGETING::TYPE_TPM, false );

        l_maxTpms = std::max(l_maxTpms, l_tpmChipList.size());
    } );
    return l_maxTpms;
}

uint32_t hdatTpmDataCalcInstanceSize()
{
    uint32_t l_size = 0;

    // account for the size of the TPM data header
    l_size += sizeof(hdatTpmData_t);

    // account for the size of the TPM Info array header
    l_size += sizeof(hdatHDIFDataArray_t);

    // account for each element of the TPM Info array
    l_size += ((sizeof(hdatSbTpmInstInfo_t) +
                TPM_SRTM_EVENT_LOG_MAX +
                TPM_DRTM_EVENT_LOG_MAX)
                * hdatCalcMaxTpmsPerNode());

    // account for User physical interaction mechanism info struct
    // and Host I2C device information pointers
    l_size += sizeof(hdatPhysInterMechInfo_t);

    // account for the size of the Hash and Verfication Function array header
    l_size += sizeof(hdatHDIFDataArray_t);

    // account for each element of the Hash and Verfication Function array
    l_size += sizeof(hdatHashVerifyFunc_t) * SecRomFuncTypes.size();

    // Align size value to match actual allocated size, because we also want to
    // zero the padded part, and thus simplify multinode support going forward.
    l_size = ALIGN_X(l_size, HDAT_HDIF_ALIGN);

    return l_size;
}

}
