/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_fbc_no_hp_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include "p10_fbc_no_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_64 = 64;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0xB = 0xB;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x3 = 0x3;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0x4 = 0x4;
constexpr uint64_t literal_0x6 = 0x6;
constexpr uint64_t literal_0x17 = 0x17;
constexpr uint64_t literal_0x28 = 0x28;
constexpr uint64_t literal_0x1C = 0x1C;
constexpr uint64_t literal_0x32 = 0x32;
constexpr uint64_t literal_0x24 = 0x24;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_0x34 = 0x34;
constexpr uint64_t literal_0x5C = 0x5C;
constexpr uint64_t literal_0x48 = 0x48;
constexpr uint64_t literal_0x80 = 0x80;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x8 = 0x8;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_0xC = 0xC;
constexpr uint64_t literal_0x14 = 0x14;
constexpr uint64_t literal_0xA = 0xA;
constexpr uint64_t literal_0x12 = 0x12;
constexpr uint64_t literal_0x1F = 0x1F;
constexpr uint64_t literal_0xD = 0xD;
constexpr uint64_t literal_0x10 = 0x10;
constexpr uint64_t literal_0x1D = 0x1D;
constexpr uint64_t literal_0x18 = 0x18;

fapi2::ReturnCode p10_fbc_no_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE));
        fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG));
        fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_A_LINKS_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_LINKS_CNFG));
        uint64_t l_def_NUM_CHIPS_CFG = ((l_TGT0_ATTR_PROC_FABRIC_A_LINKS_CNFG + literal_1) *
                                        (l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG + literal_1));
        uint64_t l_def_NUM_X_LINKS_CFG = l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG;
        fapi2::ATTR_PROC_EPS_TABLE_TYPE_Type l_TGT1_ATTR_PROC_EPS_TABLE_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE, TGT1, l_TGT1_ATTR_PROC_EPS_TABLE_TYPE));
        uint64_t l_def_IS_FLAT_8 = ((l_TGT1_ATTR_PROC_EPS_TABLE_TYPE == fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE)
                                    && (l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x0ull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x0ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301138aull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_NODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301138aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113aaull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4 );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x6 );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x17 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x28 );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x32 );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x24 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x40 );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x34 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x5C );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x48 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x80 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113aaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113abull, l_scom_buffer ));

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x8 );
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x4 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xC );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xC );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x14 );
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x6 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x12 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x12 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x1F );
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x17 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x17 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x28 );
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xC );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x14 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x24 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x24 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x12 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x34 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x34 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x5C );
            }

            if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                 && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x18 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_2)) && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x48 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                       && (l_def_NUM_X_LINKS_CFG > literal_0)) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x48 );
            }
            else if (((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
                      && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x80 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113abull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
