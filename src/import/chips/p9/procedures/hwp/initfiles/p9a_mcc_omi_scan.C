/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9a_mcc_omi_scan.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include "p9a_mcc_omi_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_28 = 28;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_0b1100111111111111111111111 = 0b1100111111111111111111111;
constexpr uint64_t literal_24 = 24;
constexpr uint64_t literal_0x3 = 0x3;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_0x26 = 0x26;
constexpr uint64_t literal_0x33 = 0x33;
constexpr uint64_t literal_0x40 = 0x40;

fapi2::ReturnCode p9a_mcc_omi_scan(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE(6);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE.insertFromRight<uint64_t>(0x3f, 0, 6);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        fapi2::variable_buffer l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        fapi2::variable_buffer l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE(6);
        l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE.insertFromRight<uint64_t>(0x3f, 0, 6);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC23.CHAN0.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC23.CHAN1.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC23.CHAN2.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC23.CHAN3.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        uint64_t l_def_ENABLE_AMO_CLEAN_LINES = literal_1;
        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN(1);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_CARE(1);

        if ((l_def_ENABLE_AMO_CLEAN_LINES == literal_1))
        {
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_ON = 0x1;
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN.insertFromRight<uint64_t>
            (l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_ON, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_CARE.insertFromRight<uint64_t>(0x1, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCAMOC_ENABLE_CLEAN",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCAMOC_ENABLE_CLEAN",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCAMOC_ENABLE_CLEAN",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCAMOC_ENABLE_CLEAN",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_ENABLE_CLEAN_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN(6);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_CARE(6);

        if ((l_def_ENABLE_AMO_CLEAN_LINES == literal_1))
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN.insertFromRight<uint64_t>(literal_12, 0, 6);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_CARE.insertFromRight<uint64_t>(0x3f, 0, 6);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF2_NUM_CLEAN",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF2_NUM_CLEAN",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF2_NUM_CLEAN",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF2_NUM_CLEAN",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_CARE));
        }

        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M(4);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M_CARE(4);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M.insertFromRight<uint64_t>(literal_0, 0, 4);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M_CARE.insertFromRight<uint64_t>(0xf, 0, 4);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF2_ALT_M",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF2_ALT_M",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF2_ALT_M",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF2_ALT_M",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_ALT_M_CARE));
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL(4);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_CARE(4);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL.insertFromRight<uint64_t>(literal_0b0100, 0, 4);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_CARE.insertFromRight<uint64_t>(0xf, 0, 4);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF2_SQ_LFSR_CNTL",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF2_SQ_LFSR_CNTL",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF2_SQ_LFSR_CNTL",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF2_SQ_LFSR_CNTL",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_CARE));
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF(5);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_CARE(5);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF.insertFromRight<uint64_t>(literal_28, 0, 5);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_CARE.insertFromRight<uint64_t>(0x1f, 0, 5);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF2_NUM_RMW_BUF",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF2_NUM_RMW_BUF",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF2_NUM_RMW_BUF",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF2_NUM_RMW_BUF",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_CARE));
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON(8);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_CARE(8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON.insertFromRight<uint64_t>(literal_0x1, 0, 8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_CARE.insertFromRight<uint64_t>(0xff, 0, 8);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCEPSQ_JITTER_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCEPSQ_JITTER_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCEPSQ_JITTER_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCEPSQ_JITTER_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_CARE));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0));
        uint64_t l_def_MC_EPSILON_CFG_T0 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 + literal_6) / literal_4);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON(8);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_CARE(8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON.insertFromRight<uint64_t>(l_def_MC_EPSILON_CFG_T0, 0, 8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_CARE.insertFromRight<uint64_t>(0xff, 0, 8);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCEPSQ_LOCAL_NODE_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCEPSQ_LOCAL_NODE_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCEPSQ_LOCAL_NODE_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCEPSQ_LOCAL_NODE_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_CARE));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1));
        uint64_t l_def_MC_EPSILON_CFG_T1 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 + literal_6) / literal_4);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON(8);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_CARE(8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON.insertFromRight<uint64_t>(l_def_MC_EPSILON_CFG_T1, 0, 8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_CARE.insertFromRight<uint64_t>(0xff, 0, 8);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCEPSQ_NEAR_NODAL_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCEPSQ_NEAR_NODAL_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCEPSQ_NEAR_NODAL_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCEPSQ_NEAR_NODAL_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_CARE));
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON(8);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_CARE(8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON.insertFromRight<uint64_t>(l_def_MC_EPSILON_CFG_T1, 0, 8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_CARE.insertFromRight<uint64_t>(0xff, 0, 8);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCEPSQ_GROUP_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCEPSQ_GROUP_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCEPSQ_GROUP_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCEPSQ_GROUP_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_CARE));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2));
        uint64_t l_def_MC_EPSILON_CFG_T2 = ((l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 + literal_6) / literal_4);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON(8);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_CARE(8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON.insertFromRight<uint64_t>(l_def_MC_EPSILON_CFG_T2, 0, 8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_CARE.insertFromRight<uint64_t>(0xff, 0, 8);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCEPSQ_REMOTE_NODAL_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCEPSQ_REMOTE_NODAL_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCEPSQ_REMOTE_NODAL_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCEPSQ_REMOTE_NODAL_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_CARE));
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON(8);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_CARE(8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON.insertFromRight<uint64_t>(l_def_MC_EPSILON_CFG_T2, 0, 8);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_CARE.insertFromRight<uint64_t>(0xff, 0, 8);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCEPSQ_VECTOR_GROUP_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCEPSQ_VECTOR_GROUP_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCEPSQ_VECTOR_GROUP_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCEPSQ_VECTOR_GROUP_EPSILON",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_CARE));
        uint64_t l_def_ENABLE_AMO_CACHING = literal_1;
        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES(25);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_CARE(25);

        if (l_def_ENABLE_AMO_CACHING)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES.insertFromRight<uint64_t>
            (literal_0b1100111111111111111111111, 0, 25);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_CARE.insertFromRight<uint64_t>(0x1ffffff, 0, 25);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCAMOC_WRTO_AMO_COLLISION_RULES",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCAMOC_WRTO_AMO_COLLISION_RULES",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCAMOC_WRTO_AMO_COLLISION_RULES",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCAMOC_WRTO_AMO_COLLISION_RULES",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_WRTO_AMO_COLLISION_RULES_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT(3);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_CARE(3);

        if (l_def_ENABLE_AMO_CACHING)
        {
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_128B_RW_64B_DATA = 0x1;
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT.insertFromRight<uint64_t>
            (l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_128B_RW_64B_DATA, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_CARE.insertFromRight<uint64_t>(0x7, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCAMOC_AMO_SIZE_SELECT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCAMOC_AMO_SIZE_SELECT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCAMOC_AMO_SIZE_SELECT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCAMOC_AMO_SIZE_SELECT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCAMOC_AMO_SIZE_SELECT_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT(6);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_CARE(6);

        if (l_def_ENABLE_AMO_CACHING)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT.insertFromRight<uint64_t>(literal_24, 0, 6);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_CARE.insertFromRight<uint64_t>(0x3f, 0, 6);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF0_AMO_LIMIT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF0_AMO_LIMIT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF0_AMO_LIMIT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF0_AMO_LIMIT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_AMO_LIMIT_CARE));
        }

        bool l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_update = false;
        fapi2::variable_buffer l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE(1);
        fapi2::variable_buffer l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_CARE(1);

        if (l_def_ENABLE_AMO_CACHING)
        {
            constexpr auto l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_ON = 0x1;
            l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE.insertFromRight<uint64_t>(l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_ON, 0, 1);
            l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_CARE.insertFromRight<uint64_t>(0x1, 0, 1);
            l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_update = true;
        }

        if ( l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MCP.CHAN0.WRITE.NEW_WRITE_64B_MODE", l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE,
                                           l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_CARE));
        }

        if ( l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MCP.CHAN1.WRITE.NEW_WRITE_64B_MODE", l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE,
                                           l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_CARE));
        }

        if ( l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MCP.CHAN2.WRITE.NEW_WRITE_64B_MODE", l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE,
                                           l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_CARE));
        }

        if ( l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MCP.CHAN3.WRITE.NEW_WRITE_64B_MODE", l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE,
                                           l_MCP_CHAN0_WRITE_NEW_WRITE_64B_MODE_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL(1);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_CARE(1);

        if (l_def_ENABLE_AMO_CACHING)
        {
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_ON = 0x1;
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL.insertFromRight<uint64_t>
            (l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_ON, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_CARE.insertFromRight<uint64_t>(0x1, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF3_AMO_LIMIT_SEL",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF3_AMO_LIMIT_SEL",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF3_AMO_LIMIT_SEL",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF3_AMO_LIMIT_SEL",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_AMO_LIMIT_SEL_CARE));
        }

        uint64_t l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC = literal_1;
        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0(3);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_CARE(3);

        if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0.insertFromRight<uint64_t>(literal_0x1, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_CARE.insertFromRight<uint64_t>(0x7, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE0",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE0",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE0",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE0",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1(3);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_CARE(3);

        if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1.insertFromRight<uint64_t>(literal_0x3, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_CARE.insertFromRight<uint64_t>(0x7, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE1",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE1",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE1",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE1",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2(3);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_CARE(3);

        if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2.insertFromRight<uint64_t>(literal_0x5, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_CARE.insertFromRight<uint64_t>(0x7, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE2",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE2",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE2",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE2",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3(3);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_CARE(3);

        if (l_def_ENABLE_PREFETCH_DROP_PROMOTE_BASIC)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3.insertFromRight<uint64_t>(literal_0x7, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_CARE.insertFromRight<uint64_t>(0x7, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE3",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE3",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE3",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF2_PF_DROP_VALUE3",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3, l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_CARE));
        }

        uint64_t l_def_ENABLE_MCBUSY = literal_1;
        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS(1);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_CARE(1);

        if (l_def_ENABLE_MCBUSY)
        {
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_ON = 0x1;
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS.insertFromRight<uint64_t>
            (l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_ON, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_CARE.insertFromRight<uint64_t>(0x1, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCBUSYQ_ENABLE_BUSY_COUNTERS",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCBUSYQ_ENABLE_BUSY_COUNTERS",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCBUSYQ_ENABLE_BUSY_COUNTERS",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCBUSYQ_ENABLE_BUSY_COUNTERS",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_ENABLE_BUSY_COUNTERS_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT(3);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_CARE(3);

        if (l_def_ENABLE_MCBUSY)
        {
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_1024_CYCLES = 0x1;
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT.insertFromRight<uint64_t>
            (l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_1024_CYCLES, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_CARE.insertFromRight<uint64_t>(0x7, 0, 3);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_WINDOW_SELECT_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0(10);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_CARE(10);

        if (l_def_ENABLE_MCBUSY)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0.insertFromRight<uint64_t>(literal_0x26, 0, 10);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_CARE.insertFromRight<uint64_t>(0x3ff, 0, 10);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD0",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD0",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD0",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD0",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD0_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1(10);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_CARE(10);

        if (l_def_ENABLE_MCBUSY)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1.insertFromRight<uint64_t>(literal_0x33, 0, 10);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_CARE.insertFromRight<uint64_t>(0x3ff, 0, 10);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD1",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD1",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD1",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD1",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD1_CARE));
        }

        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2(10);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_CARE(10);

        if (l_def_ENABLE_MCBUSY)
        {
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2.insertFromRight<uint64_t>(literal_0x40, 0, 10);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_CARE.insertFromRight<uint64_t>(0x3ff, 0, 10);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD2",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD2",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD2",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCBUSYQ_BUSY_COUNTER_THRESHOLD2",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCBUSYQ_BUSY_COUNTER_THRESHOLD2_CARE));
        }

        fapi2::ATTR_ENABLE_MEM_EARLY_DATA_SCOM_Type l_TGT1_ATTR_ENABLE_MEM_EARLY_DATA_SCOM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ENABLE_MEM_EARLY_DATA_SCOM, TGT1, l_TGT1_ATTR_ENABLE_MEM_EARLY_DATA_SCOM));
        bool l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_update = false;
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY(1);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_CARE(1);

        if ((l_TGT1_ATTR_ENABLE_MEM_EARLY_DATA_SCOM == fapi2::ENUM_ATTR_ENABLE_MEM_EARLY_DATA_SCOM_OFF))
        {
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_ON = 0x1;
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY.insertFromRight<uint64_t>
            (l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_ON, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_CARE.insertFromRight<uint64_t>(0x1, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_update = true;
        }
        else if ((l_TGT1_ATTR_ENABLE_MEM_EARLY_DATA_SCOM == fapi2::ENUM_ATTR_ENABLE_MEM_EARLY_DATA_SCOM_ON))
        {
            constexpr auto l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_OFF = 0x0;
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY.insertFromRight<uint64_t>
            (l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_OFF, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_CARE.insertFromRight<uint64_t>(0x1, 0, 1);
            l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_update = true;
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_CARE));
        }

        if ( l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY",
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY,
                                           l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF3_ENABLE_CP_M_MDI0_LOCAL_ONLY_CARE));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
