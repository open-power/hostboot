/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdattpmdata.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include <attributeenums.H>
#include "hdatutil.H"
#include <sys/mm.h>
#include <sys/mmio.h>
#include <sys/internode.h>
#include <vpd/mvpdenums.H>
#include <pnor/pnorif.H>
#include <util/align.H>
#include <algorithm>

#include <devicefw/userif.H>
#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/entitypath.H>

namespace HDAT
{

extern trace_desc_t *g_trac_hdat;

const uint8_t g_hdatTpmDataEyeCatch[] = {'T', 'P', 'M', 'R', 'E', 'L'};

HdatTpmData::HdatTpmData(errlHndl_t &o_errlHndl,
                         const HDAT::hdatMsAddr_t &i_msAddr):
    iv_msAddr(i_msAddr),
    iv_hdatTpmData(nullptr)
{
    assert(o_errlHndl == nullptr,"The error log handle passed must be nullptr");

    const uint64_t l_baseAddr = static_cast<uint64_t>(i_msAddr.hi) << 32
                                                                 | i_msAddr.lo;

    const uint64_t l_size = ALIGN_PAGE(sizeof(hdatTpmData_t)) + PAGESIZE;

    const uint64_t l_alignedAddr = ALIGN_PAGE_DOWN(l_baseAddr);

    auto l_virtAddr = reinterpret_cast<uint8_t*>(
        mm_block_map(reinterpret_cast<void*>(l_alignedAddr),l_size));
    if (l_virtAddr)
    {
        const auto l_offset = l_baseAddr - l_alignedAddr;

        iv_hdatTpmData = reinterpret_cast<hdatTpmData_t *>(l_virtAddr +
                                                                     l_offset);

        // TODO RTC 167290 - This memset needs to be revisited for multinode
        // support. We may need to do this memset once per node or use some
        // other approach to initialization.
        memset(iv_hdatTpmData, 0x0, sizeof(hdatTpmData_t));

        HDAT_DBG("Ctr iv_hdatTpmData addr 0x%.16llX virtual addr 0x%.16llX",
                                    reinterpret_cast<uint64_t>(iv_hdatTpmData),
                                    reinterpret_cast<uint64_t>(l_virtAddr));
    }
    else
    {
        /*@
         * @errortype
         * @moduleid          HDAT::MOD_TPMDATA_CONSTRUCTOR
         * @reasoncode        HDAT::RC_DEV_MAP_FAIL
         * @userdata1[00:31]  Address attempted to map upper
         * @userdata1[32:63]  Address attempted to map lower
         * @userdata2[00:31]  Size of mapped region upper
         * @userdata2[32:63]  Size of mapped region lower
         * @devdesc           Creation of mapped region failed
         * @custdesc          Firmware encountered an internal error
         */
        hdatBldErrLog(o_errlHndl,
            MOD_TPMDATA_CONSTRUCTOR,
            RC_DEV_MAP_FAIL,
            static_cast<uint32_t>(UINT64_HIGH(l_alignedAddr)),
            static_cast<uint32_t>(UINT64_LOW(l_alignedAddr)),
            static_cast<uint32_t>(UINT64_HIGH(l_size)),
            static_cast<uint32_t>(UINT64_LOW(l_size)),
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            HDAT_VERSION1,
            false);
    }
}

HdatTpmData::~HdatTpmData()
{
    const uint64_t l_unmapAddr = ALIGN_PAGE_DOWN(
                                   reinterpret_cast<uint64_t>(iv_hdatTpmData));

    // if the constructor successfully mapped the region then
    // it must be unmapped
    if (iv_hdatTpmData)
    {
        auto rc = mm_block_unmap(reinterpret_cast<void*>(l_unmapAddr));
        if (rc)
        {
            errlHndl_t l_errl = nullptr;
            /*@
             * @errortype
             * @severity          ERRL_SEV_UNRECOVERABLE
             * @moduleid          HDAT::MOD_TPMDATA_DESTRUCTOR
             * @reasoncode        HDAT::RC_DEV_MAP_FAIL
             * @userdata1[00:31]  Address attempted to unmap upper
             * @userdata1[32:63]  Address attempted to unmap lower
             * @devdesc           Unmap of a mapped region failed
             * @custdesc          Firmware encountered an internal error
             */
            hdatBldErrLog(l_errl,
                MOD_TPMDATA_DESTRUCTOR,
                RC_DEV_MAP_FAIL,
                static_cast<uint32_t>(UINT64_HIGH(l_unmapAddr)),
                static_cast<uint32_t>(UINT64_LOW(l_unmapAddr)),
                0, 0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
        }
        iv_hdatTpmData = nullptr;
    }
}

errlHndl_t HdatTpmData::hdatLoadTpmData(uint32_t &o_size, uint32_t &o_count)
{
    errlHndl_t l_errl = nullptr;

    o_size = 0;
    o_count = 0;

    // TODO RTC 167290 - In order to support multiple nodes, this calculation
    // needs to be #nodes * [ the entire 18.x set of structures ] and the
    // initialization needs to be done on each instance. The reported size
    // (in variable o_size) needs to be the size of a single instance and the
    // reported count (via o_count) needs to be the number of nodes. For now,
    // we assume one node.

    // account for the size of the TPM data header
    o_size += sizeof(hdatTpmData_t);

    // account for the size of the TPM Info array header
    o_size += sizeof(hdatSbTpmInfo_t);

    // account for each element of the TPM Info array
    o_size += ((sizeof(hdatSbTpmInstInfo_t) +
                TPM_SRTM_EVENT_LOG_MAX +
                TPM_DRTM_EVENT_LOG_MAX)
                * hdatCalcMaxTpmsPerNode());

    // account for User physical interaction mechanism info struct
    // and Host I2C device information pointers
    o_size += (sizeof(hdatPhysInterMechInfo_t) + sizeof(hdatI2cDevInfoPtrs_t) *
        NUM_I2C_PHYS_PRESENCE_DEVICES);

    // Align size value to match actual allocated size, because we also want to
    // zero the padded part, and thus simplify multinode support going forward.
    o_size = ALIGN_X(o_size, HDAT_HDIF_ALIGN);

    // zero all of it
    memset(iv_hdatTpmData,0,o_size);

    // We add the first two fields for a reference to aid in debugging,
    // but the rest will be populated in FSP/OpenPower common code. Any
    // work here would just be duplicated later during the runtime istep.

    // add the format magic number
    iv_hdatTpmData->hdatHdr.hdatStructId = HDAT::HDAT_HDIF_STRUCT_ID;

    // add the eyecatcher
    memcpy(iv_hdatTpmData->hdatHdr.hdatStructName,
           g_hdatTpmDataEyeCatch,
           sizeof(g_hdatTpmDataEyeCatch));

    // account for this one instance of Node TPM Related Data
    ++o_count;

    return l_errl;
}

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

}
