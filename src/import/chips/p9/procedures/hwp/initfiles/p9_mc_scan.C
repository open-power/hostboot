/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mc_scan.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include "p9_mc_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0b111111 = 0b111111;
constexpr auto literal_8 = 8;
constexpr auto literal_0b1 = 0b1;

fapi2::ReturnCode p9_mc_scan(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id);

        if (l_rc)
        {
            FAPI_ERR("ERROR getting ATTR_NAME");
            break;
        }

        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec);

        if (l_rc)
        {
            FAPI_ERR("ERROR getting ATTR_EC");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
        l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b111111, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT0.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                             l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT0.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
        l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b111111, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT1.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                             l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT1.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
        l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b111111, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT2.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                             l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT2.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
        l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b111111, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT3.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                             l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT3.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
        l_MC23_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b111111, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT0.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                             l_MC23_PORT0_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT0.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
        l_MC23_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b111111, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT1.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                             l_MC23_PORT1_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT1.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
        l_MC23_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b111111, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT2.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                             l_MC23_PORT2_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT2.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT(6);
        l_MC23_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT.insertFromRight<uint64_t>(literal_0b111111, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT3.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT",
                             l_MC23_PORT3_ATCL_CL_CLSCOM_MCPERF0_PREFETCH_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT3.ATCL.CL.CLSCOM.MCPERF0_PREFETCH_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT0.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                             l_MC01_PORT0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT0.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT1.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                             l_MC01_PORT1_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT1.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT2.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                             l_MC01_PORT2_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT2.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT3.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                             l_MC01_PORT3_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT3.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        l_MC23_PORT0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT0.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                             l_MC23_PORT0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT0.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT1_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        l_MC23_PORT1_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT1.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                             l_MC23_PORT1_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT1.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT2_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        l_MC23_PORT2_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT2.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                             l_MC23_PORT2_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT2.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT3_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        l_MC23_PORT3_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT3.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                             l_MC23_PORT3_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT3.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE(1);
        l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT0.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT0.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT0.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT0.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT0.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT0.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT0.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT0.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE(1);
        l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT1.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT1.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT1.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT1.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT1.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT1.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT1.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT1.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE(1);
        l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT2.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT2.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT2.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT2.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT2.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT2.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT2.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT2.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        fapi2::variable_buffer l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE(1);
        l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_rc = fapi2::putSpy(TGT0, "MC01.PORT3.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT3.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT3.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT3.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT3.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT3.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC01.PORT3.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC01_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC01.PORT3.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE(1);
        l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT0.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT0.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT0.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT0.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT0.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT0.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT0.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT0_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT0.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE(1);
        l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT1.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT1.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT1.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT1.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT1.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT1.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT1.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT1_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT1.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE(1);
        l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT2.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT2.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT2.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT2.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT2.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT2.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT2.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT2_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT2.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        fapi2::variable_buffer l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE(1);
        l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_rc = fapi2::putSpy(TGT0, "MC23.PORT3.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT3.READ.RDATA_ARY0.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT3.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT3.READ.RDATA_ARY1.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT3.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT3.READ.RDATA_ARY2.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

        l_rc = fapi2::putSpy(TGT0, "MC23.PORT3.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE",
                             l_MC23_PORT3_READ_RDATA_ARY0_SFT_MAC_SFT_LCBCNTL_BLK_RF_CLOCKGATE_DISABLE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putSpy (MC23.PORT3.READ.RDATA_ARY3.SFT_MAC.SFT.LCBCNTL_BLK_RF.CLOCKGATE_DISABLE)");
            break;
        }

    }
    while(0);

    return l_rc;
}
