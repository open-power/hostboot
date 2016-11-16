/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_mbs_scan.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include "centaur_mbs_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x2000 = 0x2000;
constexpr uint64_t literal_0b10110111000 = 0b10110111000;
constexpr uint64_t literal_0b00000000000000 = 0b00000000000000;
constexpr uint64_t literal_0b001001 = 0b001001;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_0b00100 = 0b00100;
constexpr uint64_t literal_0b011 = 0b011;

fapi2::ReturnCode centaur_mbs_scan(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::variable_buffer l_MBU_MBS_CFG_MBS_FLARB_PROGRESS_WINDOW_EN(1);
        constexpr auto l_MBU_MBS_CFG_MBS_FLARB_PROGRESS_WINDOW_EN_ON = 0x1;
        l_MBU_MBS_CFG_MBS_FLARB_PROGRESS_WINDOW_EN.insertFromRight<uint64_t>(l_MBU_MBS_CFG_MBS_FLARB_PROGRESS_WINDOW_EN_ON, 0,
                1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.CFG_MBS_FLARB_PROGRESS_WINDOW_EN", l_MBU_MBS_CFG_MBS_FLARB_PROGRESS_WINDOW_EN));
        fapi2::variable_buffer l_MBU_MBS_CFG_BLOCK_CACHE_CE_FIR_DIS(1);
        constexpr auto l_MBU_MBS_CFG_BLOCK_CACHE_CE_FIR_DIS_ON = 0x1;
        l_MBU_MBS_CFG_BLOCK_CACHE_CE_FIR_DIS.insertFromRight<uint64_t>(l_MBU_MBS_CFG_BLOCK_CACHE_CE_FIR_DIS_ON, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.CFG_BLOCK_CACHE_CE_FIR_DIS", l_MBU_MBS_CFG_BLOCK_CACHE_CE_FIR_DIS));
        fapi2::variable_buffer l_MBU_MBX_HW269130_MBX_RDTAG_PARITY_CHECK(4);
        constexpr auto l_MBU_MBX_HW269130_MBX_RDTAG_PARITY_CHECK_MASKED = 0xf;
        l_MBU_MBX_HW269130_MBX_RDTAG_PARITY_CHECK.insertFromRight<uint64_t>(l_MBU_MBX_HW269130_MBX_RDTAG_PARITY_CHECK_MASKED, 0,
                4);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBX.HW269130_MBX_RDTAG_PARITY_CHECK", l_MBU_MBX_HW269130_MBX_RDTAG_PARITY_CHECK));
        fapi2::variable_buffer l_MBU_MBS_CFG_DIR_ECC_USE_ADDPAR_DISABLE(7);
        constexpr auto l_MBU_MBS_CFG_DIR_ECC_USE_ADDPAR_DISABLE_OFF = 0x0;
        l_MBU_MBS_CFG_DIR_ECC_USE_ADDPAR_DISABLE.insertFromRight<uint64_t>(l_MBU_MBS_CFG_DIR_ECC_USE_ADDPAR_DISABLE_OFF, 0, 7);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.CFG_DIR_ECC_USE_ADDPAR_DISABLE", l_MBU_MBS_CFG_DIR_ECC_USE_ADDPAR_DISABLE));
        fapi2::variable_buffer l_MBU_MBI_MBI_WAT0A_WAT_ENABLE(1);
        constexpr auto l_MBU_MBI_MBI_WAT0A_WAT_ENABLE_ON = 0x1;
        l_MBU_MBI_MBI_WAT0A_WAT_ENABLE.insertFromRight<uint64_t>(l_MBU_MBI_MBI_WAT0A_WAT_ENABLE_ON, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBI.MBI.WAT0A.WAT_ENABLE", l_MBU_MBI_MBI_WAT0A_WAT_ENABLE));
        fapi2::variable_buffer l_MBU_MBI_MBI_WAT0B_WAT_ENABLE(1);
        constexpr auto l_MBU_MBI_MBI_WAT0B_WAT_ENABLE_ON = 0x1;
        l_MBU_MBI_MBI_WAT0B_WAT_ENABLE.insertFromRight<uint64_t>(l_MBU_MBI_MBI_WAT0B_WAT_ENABLE_ON, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBI.MBI.WAT0B.WAT_ENABLE", l_MBU_MBI_MBI_WAT0B_WAT_ENABLE));
        fapi2::variable_buffer l_MBU_MBI_CFG_DBG_MUX(7);
        l_MBU_MBI_CFG_DBG_MUX.insertFromRight<uint64_t>(literal_0x2000, 0, 7);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBI.CFG_DBG_MUX", l_MBU_MBI_CFG_DBG_MUX));
        fapi2::variable_buffer l_MBU_MBS_IBB_IBRD_CFG_LATE_OCC_UPDATE_DONE(1);
        constexpr auto l_MBU_MBS_IBB_IBRD_CFG_LATE_OCC_UPDATE_DONE_ON = 0x1;
        l_MBU_MBS_IBB_IBRD_CFG_LATE_OCC_UPDATE_DONE.insertFromRight<uint64_t>(l_MBU_MBS_IBB_IBRD_CFG_LATE_OCC_UPDATE_DONE_ON, 0,
                1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.IBB.IBRD.CFG_LATE_OCC_UPDATE_DONE", l_MBU_MBS_IBB_IBRD_CFG_LATE_OCC_UPDATE_DONE));
        fapi2::variable_buffer l_MBU_MBS_CFG_HANG_COUNT(11);
        l_MBU_MBS_CFG_HANG_COUNT.insertFromRight<uint64_t>(literal_0b10110111000, 0, 11);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.CFG_HANG_COUNT", l_MBU_MBS_CFG_HANG_COUNT));
        fapi2::variable_buffer l_MBU_MBS_MBS_CLN_DV_CGC_CNT_LWMARK(14);
        l_MBU_MBS_MBS_CLN_DV_CGC_CNT_LWMARK.insertFromRight<uint64_t>(literal_0b00000000000000, 0, 14);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.MBS_CLN_DV_CGC_CNT_LWMARK", l_MBU_MBS_MBS_CLN_DV_CGC_CNT_LWMARK));
        fapi2::variable_buffer l_MBU_MBS_MBS_CLN_RNK_GRP_WRQ_CNT_LWMARK(6);
        l_MBU_MBS_MBS_CLN_RNK_GRP_WRQ_CNT_LWMARK.insertFromRight<uint64_t>(literal_0b001001, 0, 6);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.MBS_CLN_RNK_GRP_WRQ_CNT_LWMARK", l_MBU_MBS_MBS_CLN_RNK_GRP_WRQ_CNT_LWMARK));
        fapi2::variable_buffer l_MBU_MBS_MBS_CLN_PAGE_MODE_HARVEST_DIS(1);
        constexpr auto l_MBU_MBS_MBS_CLN_PAGE_MODE_HARVEST_DIS_OFF = 0x0;
        l_MBU_MBS_MBS_CLN_PAGE_MODE_HARVEST_DIS.insertFromRight<uint64_t>(l_MBU_MBS_MBS_CLN_PAGE_MODE_HARVEST_DIS_OFF, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.MBS_CLN_PAGE_MODE_HARVEST_DIS", l_MBU_MBS_MBS_CLN_PAGE_MODE_HARVEST_DIS));
        fapi2::variable_buffer l_MBU_MBS_MBS_CLN_PAGE_MODE_HARV_MAX_FAILS_CNT(3);
        l_MBU_MBS_MBS_CLN_PAGE_MODE_HARV_MAX_FAILS_CNT.insertFromRight<uint64_t>(literal_0b001, 0, 3);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.MBS_CLN_PAGE_MODE_HARV_MAX_FAILS_CNT",
                               l_MBU_MBS_MBS_CLN_PAGE_MODE_HARV_MAX_FAILS_CNT));
        fapi2::variable_buffer l_MBU_MBS_MBS_CLN_PG_HARV_CONFLICT_WAIT_CNT(6);
        l_MBU_MBS_MBS_CLN_PG_HARV_CONFLICT_WAIT_CNT.insertFromRight<uint64_t>(literal_0b000000, 0, 6);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.MBS_CLN_PG_HARV_CONFLICT_WAIT_CNT", l_MBU_MBS_MBS_CLN_PG_HARV_CONFLICT_WAIT_CNT));
        fapi2::variable_buffer l_MBU_MBS_CFG_WHAP_CLEAN_THRESHOLD(5);
        l_MBU_MBS_CFG_WHAP_CLEAN_THRESHOLD.insertFromRight<uint64_t>(literal_0b00100, 0, 5);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.CFG_WHAP_CLEAN_THRESHOLD", l_MBU_MBS_CFG_WHAP_CLEAN_THRESHOLD));
        fapi2::variable_buffer l_MBU_MBS_CFG_WHAP_WR_START_RECNT(3);
        l_MBU_MBS_CFG_WHAP_WR_START_RECNT.insertFromRight<uint64_t>(literal_0b011, 0, 3);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBS.CFG_WHAP_WR_START_RECNT", l_MBU_MBS_CFG_WHAP_WR_START_RECNT));

    };
fapi_try_exit:
    return fapi2::current_err;
}
