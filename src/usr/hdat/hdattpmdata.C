/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdattpmdata.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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

HdatTpmData::HdatTpmData(errlHndl_t &o_errlHndl,
                         const HDAT::hdatMsAddr_t &i_msAddr):
    iv_msAddr(i_msAddr),
    iv_hdatTpmData(nullptr)
{
    assert(o_errlHndl == nullptr,"The error log handle passed must be nullptr");

    const uint64_t l_baseAddr = static_cast<uint64_t>(i_msAddr.hi) << 32
                                                                 | i_msAddr.lo;

    // get the top level target
    TARGETING::Target* sys = nullptr;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != nullptr,
            "HdatTpmData::HdatTpmData: Bug! Could not obtain top level target");

    // get the node bit string to see what our node layout looks like
    auto l_nodeBits = sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

    // count the bits to get the functional/present nodes
    iv_numNodes = __builtin_popcount(l_nodeBits);

    // Must be at least one. Add one in the zero case.
    iv_numNodes += !iv_numNodes;

    const auto maxLogicalSize = hdatTpmDataCalcInstanceSize() * iv_numNodes;
    const uint64_t l_size = ALIGN_PAGE(maxLogicalSize) + PAGESIZE;

    const uint64_t l_alignedAddr = ALIGN_PAGE_DOWN(l_baseAddr);

    auto l_virtAddr = reinterpret_cast<uint8_t*>(
        mm_block_map(reinterpret_cast<void*>(l_alignedAddr),l_size));
    if (l_virtAddr)
    {
        const auto l_offset = l_baseAddr - l_alignedAddr;

        iv_hdatTpmData = reinterpret_cast<hdatTpmData_t *>(l_virtAddr +
                                                                     l_offset);

        memset(iv_hdatTpmData, 0x0, maxLogicalSize);

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

    o_count = 0;

    // calculate the size of each instance
    o_size = hdatTpmDataCalcInstanceSize();

    auto l_hdatTpmData = iv_hdatTpmData;

    for (uint32_t i_instance = 0; i_instance < iv_numNodes; i_instance++)
    {
        // Note: HdatTpmData constructor already cleared the memory to the tune
        // of o_size (hdatTpmDataCalcInstanceSize()) bytes

        // We add the first two fields for a reference to aid in debugging,
        // but the rest will be populated in FSP/OpenPower common code. Any
        // work here would just be duplicated later during the runtime istep.

        // add the format magic number
        l_hdatTpmData->hdatHdr.hdatStructId = HDAT::HDAT_HDIF_STRUCT_ID;

        // add the eyecatcher
        memcpy(l_hdatTpmData->hdatHdr.hdatStructName,
           g_hdatTpmDataEyeCatch,
           strlen(g_hdatTpmDataEyeCatch));

        // Account for this one instance of Node TPM Related Data.
        ++o_count;

        // Move to the next instance
        l_hdatTpmData = reinterpret_cast<hdatTpmData_t *>(
                        reinterpret_cast<uint8_t*>(l_hdatTpmData) + o_size);
    }

    return l_errl;
}

}
