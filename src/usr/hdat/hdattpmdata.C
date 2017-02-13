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
#include <vpd/mvpdenums.H>
#include <pnor/pnorif.H>
#include <util/align.H>

#include <devicefw/userif.H>
#include <targeting/common/util.H>

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

errlHndl_t HdatTpmData::hdatLoadTpmData(uint32_t &o_size,uint32_t &o_count)
{
    errlHndl_t l_errl = nullptr;

    return l_errl;
}

}
