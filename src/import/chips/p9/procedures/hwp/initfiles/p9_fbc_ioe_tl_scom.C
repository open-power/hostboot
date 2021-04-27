/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioe_tl_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include "p9_fbc_ioe_tl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0x20 = 0x20;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_82 = 82;
constexpr uint64_t literal_0x15 = 0x15;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_100 = 100;
constexpr uint64_t literal_1075 = 1075;
constexpr uint64_t literal_0x1A = 0x1A;
constexpr uint64_t literal_0x19 = 0x19;
constexpr uint64_t literal_0x10 = 0x10;
constexpr uint64_t literal_0x1F = 0x1F;
constexpr uint64_t literal_0x3F = 0x3F;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_0x3C = 0x3C;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0b0001 = 0b0001;

fapi2::ReturnCode p9_fbc_ioe_tl_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        uint64_t l_def_X0_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        fapi2::ATTR_CHIP_EC_FEATURE_DD1_FBC_SETTINGS_Type l_TGT0_ATTR_CHIP_EC_FEATURE_DD1_FBC_SETTINGS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DD1_FBC_SETTINGS, TGT0,
                               l_TGT0_ATTR_CHIP_EC_FEATURE_DD1_FBC_SETTINGS));
        uint64_t l_def_DD2X_PARTS = (l_TGT0_ATTR_CHIP_EC_FEATURE_DD1_FBC_SETTINGS != literal_1);
        fapi2::ATTR_FREQ_X_MHZ_Type l_TGT1_ATTR_FREQ_X_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_X_MHZ, TGT1, l_TGT1_ATTR_FREQ_X_MHZ));
        uint64_t l_def_DD2_LO_LIMIT_D = (l_TGT1_ATTR_FREQ_X_MHZ * literal_10);
        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_DD2_LO_LIMIT_N = (l_TGT1_ATTR_FREQ_PB_MHZ * literal_82);
        uint64_t l_def_DD1_LO_LIMIT_D = (l_TGT1_ATTR_FREQ_X_MHZ * literal_100);
        uint64_t l_def_DD1_LO_LIMIT_H = (l_def_DD1_LO_LIMIT_D / literal_2);
        uint64_t l_def_DD1_LO_LIMIT_N = (l_TGT1_ATTR_FREQ_PB_MHZ * literal_1075);
        uint64_t l_def_DD1_LO_LIMIT_R = (l_def_DD1_LO_LIMIT_N % l_def_DD1_LO_LIMIT_D);
        uint64_t l_def_DD1_PARTS = (l_TGT0_ATTR_CHIP_EC_FEATURE_DD1_FBC_SETTINGS == literal_1);
        uint64_t l_def_DD1_LO_LIMIT_P = (l_def_DD1_LO_LIMIT_D % literal_2);
        uint64_t l_def_X1_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_X2_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE_Type l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE));
        uint64_t l_def_OPTICS_IS_A_BUS = (l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE ==
                                          fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS);
        fapi2::ATTR_CHIP_EC_FEATURE_HW384245_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW384245;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW384245, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW384245));
        uint64_t l_def_X0_IS_PAIRED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] ==
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE);
        uint64_t l_def_X1_IS_PAIRED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] ==
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE);
        uint64_t l_def_X2_IS_PAIRED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] ==
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501340aull, l_scom_buffer ));

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0x1 );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0x20 );
            }

            if (( ! l_def_X0_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP0_FMR_DISABLE_ON = 0x1;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP0_FMR_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP0_FMR_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP0_FMR_DISABLE_OFF );
            }

            if (( ! l_def_X0_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP0_PRS_DISABLE_ON = 0x1;
                l_scom_buffer.insert<25, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP0_PRS_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP0_PRS_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<25, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP0_PRS_DISABLE_OFF );
            }

            constexpr auto l_PB_IOE_SCOM_FP0_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP0_DISABLE_GATHERING_ON );

            if ((l_def_X0_ENABLED && l_def_DD2X_PARTS))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x15 - (l_def_DD2_LO_LIMIT_N / l_def_DD2_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R < l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && l_def_DD1_LO_LIMIT_P))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && ( ! l_def_DD1_LO_LIMIT_P)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R > l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x20 );
            }

            if (( ! l_def_X0_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP1_FMR_DISABLE_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP1_FMR_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP1_FMR_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP1_FMR_DISABLE_OFF );
            }

            if (( ! l_def_X0_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP1_PRS_DISABLE_ON = 0x1;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP1_PRS_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP1_PRS_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP1_PRS_DISABLE_OFF );
            }

            constexpr auto l_PB_IOE_SCOM_FP1_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP1_DISABLE_GATHERING_ON );

            if ((l_def_X0_ENABLED && l_def_DD2X_PARTS))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x15 - (l_def_DD2_LO_LIMIT_N / l_def_DD2_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R < l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && l_def_DD1_LO_LIMIT_P))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && ( ! l_def_DD1_LO_LIMIT_P)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R > l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501340aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501340bull, l_scom_buffer ));

            if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0x1 );
            }

            if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0x20 );
            }

            if (( ! l_def_X1_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP2_FMR_DISABLE_ON = 0x1;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP2_FMR_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP2_FMR_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP2_FMR_DISABLE_OFF );
            }

            if (( ! l_def_X1_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP2_PRS_DISABLE_ON = 0x1;
                l_scom_buffer.insert<25, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP2_PRS_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP2_PRS_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<25, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP2_PRS_DISABLE_OFF );
            }

            constexpr auto l_PB_IOE_SCOM_FP2_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP2_DISABLE_GATHERING_ON );

            if ((l_def_X1_ENABLED && l_def_DD2X_PARTS))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x15 - (l_def_DD2_LO_LIMIT_N / l_def_DD2_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R < l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && l_def_DD1_LO_LIMIT_P))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && ( ! l_def_DD1_LO_LIMIT_P)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R > l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }

            if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x20 );
            }

            if (( ! l_def_X1_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP3_FMR_DISABLE_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP3_FMR_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP3_FMR_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP3_FMR_DISABLE_OFF );
            }

            if (( ! l_def_X1_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP3_PRS_DISABLE_ON = 0x1;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP3_PRS_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP3_PRS_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP3_PRS_DISABLE_OFF );
            }

            constexpr auto l_PB_IOE_SCOM_FP3_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP3_DISABLE_GATHERING_ON );

            if ((l_def_X1_ENABLED && l_def_DD2X_PARTS))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x15 - (l_def_DD2_LO_LIMIT_N / l_def_DD2_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R < l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && l_def_DD1_LO_LIMIT_P))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && ( ! l_def_DD1_LO_LIMIT_P)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R > l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501340bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501340cull, l_scom_buffer ));

            if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0x1 );
            }

            if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0x20 );
            }

            if (( ! l_def_X2_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP4_FMR_DISABLE_ON = 0x1;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP4_FMR_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP4_FMR_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP4_FMR_DISABLE_OFF );
            }

            if (( ! l_def_X2_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP4_PRS_DISABLE_ON = 0x1;
                l_scom_buffer.insert<25, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP4_PRS_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP4_PRS_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<25, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP4_PRS_DISABLE_OFF );
            }

            constexpr auto l_PB_IOE_SCOM_FP4_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP4_DISABLE_GATHERING_ON );

            if ((l_def_X2_ENABLED && l_def_DD2X_PARTS))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x15 - (l_def_DD2_LO_LIMIT_N / l_def_DD2_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R < l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && l_def_DD1_LO_LIMIT_P))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && ( ! l_def_DD1_LO_LIMIT_P)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R > l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<4, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }

            if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<44, 8, 56, uint64_t>(literal_0x20 );
            }

            if (( ! l_def_X2_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP5_FMR_DISABLE_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP5_FMR_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP5_FMR_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP5_FMR_DISABLE_OFF );
            }

            if (( ! l_def_X2_ENABLED))
            {
                constexpr auto l_PB_IOE_SCOM_FP5_PRS_DISABLE_ON = 0x1;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP5_PRS_DISABLE_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_FP5_PRS_DISABLE_OFF = 0x0;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP5_PRS_DISABLE_OFF );
            }

            constexpr auto l_PB_IOE_SCOM_FP5_DISABLE_GATHERING_ON = 0x1;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_PB_IOE_SCOM_FP5_DISABLE_GATHERING_ON );

            if ((l_def_X2_ENABLED && l_def_DD2X_PARTS))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x15 - (l_def_DD2_LO_LIMIT_N / l_def_DD2_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R < l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && l_def_DD1_LO_LIMIT_P))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x1A - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if ((((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R == l_def_DD1_LO_LIMIT_H))
                      && ( ! l_def_DD1_LO_LIMIT_P)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }
            else if (((l_def_X0_ENABLED && l_def_DD1_PARTS) && (l_def_DD1_LO_LIMIT_R > l_def_DD1_LO_LIMIT_H)))
            {
                l_scom_buffer.insert<36, 8, 56, uint64_t>((literal_0x19 - (l_def_DD1_LO_LIMIT_N / l_def_DD1_LO_LIMIT_D)) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501340cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013410ull, l_scom_buffer ));

            if ((l_def_X0_ENABLED && l_def_OPTICS_IS_A_BUS))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x10 );
            }
            else if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x1F );
            }

            if ((l_def_X0_ENABLED && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW384245 != literal_0)))
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x3F );
            }
            else if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x40 );
            }

            if ((l_def_X0_ENABLED && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW384245 != literal_0)))
            {
                l_scom_buffer.insert<33, 7, 57, uint64_t>(literal_0x3F );
            }
            else if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<33, 7, 57, uint64_t>(literal_0x40 );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<41, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x3C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013410ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013411ull, l_scom_buffer ));

            if ((l_def_X1_ENABLED && l_def_OPTICS_IS_A_BUS))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x10 );
            }
            else if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x1F );
            }

            if ((l_def_X1_ENABLED && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW384245 != literal_0)))
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x3F );
            }
            else if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x40 );
            }

            if ((l_def_X1_ENABLED && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW384245 != literal_0)))
            {
                l_scom_buffer.insert<33, 7, 57, uint64_t>(literal_0x3F );
            }
            else if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<33, 7, 57, uint64_t>(literal_0x40 );
            }

            if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<41, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X1_ENABLED)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x3C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013411ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013412ull, l_scom_buffer ));

            if ((l_def_X2_ENABLED && l_def_OPTICS_IS_A_BUS))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x10 );
            }
            else if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0x1F );
            }

            if ((l_def_X2_ENABLED && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW384245 != literal_0)))
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x3F );
            }
            else if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<1, 7, 57, uint64_t>(literal_0x40 );
            }

            if ((l_def_X2_ENABLED && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW384245 != literal_0)))
            {
                l_scom_buffer.insert<33, 7, 57, uint64_t>(literal_0x3F );
            }
            else if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<33, 7, 57, uint64_t>(literal_0x40 );
            }

            if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<9, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<41, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<17, 7, 57, uint64_t>(literal_0x3C );
            }

            if (l_def_X2_ENABLED)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x3C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013412ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013423ull, l_scom_buffer ));

            if (l_def_X0_IS_PAIRED)
            {
                constexpr auto l_PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_IOE_SCOM_PB_CFG_IOE01_IS_LOGICAL_PAIR_OFF );
            }

            if (l_def_X1_IS_PAIRED)
            {
                constexpr auto l_PB_IOE_SCOM_PB_CFG_IOE23_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOE_SCOM_PB_CFG_IOE23_IS_LOGICAL_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_PB_CFG_IOE23_IS_LOGICAL_PAIR_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_IOE_SCOM_PB_CFG_IOE23_IS_LOGICAL_PAIR_OFF );
            }

            if (l_def_X2_IS_PAIRED)
            {
                constexpr auto l_PB_IOE_SCOM_PB_CFG_IOE45_IS_LOGICAL_PAIR_ON = 0x1;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_IOE_SCOM_PB_CFG_IOE45_IS_LOGICAL_PAIR_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_IOE_SCOM_PB_CFG_IOE45_IS_LOGICAL_PAIR_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_IOE_SCOM_PB_CFG_IOE45_IS_LOGICAL_PAIR_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013423ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5013424ull, l_scom_buffer ));

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (l_def_X0_ENABLED)
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b0001 );
            }

            if ((( ! l_def_X0_ENABLED) && l_def_X1_ENABLED))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0b0100 );
            }

            if ((( ! l_def_X0_ENABLED) && l_def_X1_ENABLED))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0b0100 );
            }

            if ((( ! l_def_X0_ENABLED) && l_def_X1_ENABLED))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0001 );
            }

            if ((( ! l_def_X0_ENABLED) && l_def_X1_ENABLED))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (((( ! l_def_X0_ENABLED) && ( ! l_def_X1_ENABLED)) && l_def_X2_ENABLED))
            {
                l_scom_buffer.insert<32, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (((( ! l_def_X0_ENABLED) && ( ! l_def_X1_ENABLED)) && l_def_X2_ENABLED))
            {
                l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (((( ! l_def_X0_ENABLED) && ( ! l_def_X1_ENABLED)) && l_def_X2_ENABLED))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>(literal_0b0001 );
            }

            if (((( ! l_def_X0_ENABLED) && ( ! l_def_X1_ENABLED)) && l_def_X2_ENABLED))
            {
                l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0b0001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5013424ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
