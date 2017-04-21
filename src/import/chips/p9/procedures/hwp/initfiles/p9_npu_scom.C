/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_npu_scom.C $  */
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
#include "p9_npu_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0x04 = 0x04;
constexpr uint64_t literal_0x0C = 0x0C;
constexpr uint64_t literal_0x4 = 0x4;
constexpr uint64_t literal_0x100 = 0x100;
constexpr uint64_t literal_0x200 = 0x200;
constexpr uint64_t literal_0x300 = 0x300;
constexpr uint64_t literal_0x181000 = 0x181000;
constexpr uint64_t literal_0x8 = 0x8;
constexpr uint64_t literal_0xFFF = 0xFFF;
constexpr uint64_t literal_0xE000000000000000 = 0xE000000000000000;
constexpr uint64_t literal_0x0000740000000000 = 0x0000740000000000;
constexpr uint64_t literal_0x7F60B04500AC0000 = 0x7F60B04500AC0000;
constexpr uint64_t literal_0xAAA70A55F0000000 = 0xAAA70A55F0000000;
constexpr uint64_t literal_0x5550740000000000 = 0x5550740000000000;
constexpr uint64_t literal_0x009B08180F03FFFF = 0x009B08180F03FFFF;
constexpr uint64_t literal_0xFFFFFFFFFFFFFFFF = 0xFFFFFFFFFFFFFFFF;
constexpr uint64_t literal_0x7FE0B04500AC0000 = 0x7FE0B04500AC0000;
constexpr uint64_t literal_0xFFFFF85F0FFFFFFF = 0xFFFFF85F0FFFFFFF;
constexpr uint64_t literal_0x5558F40007FFFFFF = 0x5558F40007FFFFFF;

fapi2::ReturnCode p9_npu_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE));
        uint64_t l_def_NVLINK_ACTIVE = ((((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                                           fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV)
                                          || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                                         || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
                                        || (l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T0_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T1_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_READ_CYCLES_T2_Type l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, TGT1, l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1_Type l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, TGT1, l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1));
        fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2_Type l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, TGT1, l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2));
        fapi2::ATTR_PROC_FABRIC_GROUP_ID_Type l_TGT0_ATTR_PROC_FABRIC_GROUP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_ID, TGT0, l_TGT0_ATTR_PROC_FABRIC_GROUP_ID));
        fapi2::ATTR_PROC_FABRIC_CHIP_ID_Type l_TGT0_ATTR_PROC_FABRIC_CHIP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CHIP_ID, TGT0, l_TGT0_ATTR_PROC_FABRIC_CHIP_ID));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011000ull, l_scom_buffer ));

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011000ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011002ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011002ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011008ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011008ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501101bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501101bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011020ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011020ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011022ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011022ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011028ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011028ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011030ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011030ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011032ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011032ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011038ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011038ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501103bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501103bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011040ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011040ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011042ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011042ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011048ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011048ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501105bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501105bull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011060ull, l_scom_buffer ));

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011060ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011062ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011062ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011068ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011068ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501107bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501107bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011080ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011080ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011090ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011090ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011092ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011092ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011098ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011098ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50110c0ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50110c0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50110d0ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50110d0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011100ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011100ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011102ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011102ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011108ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011108ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501111bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501111bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011120ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011120ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011122ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011122ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011128ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011128ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501113bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501113bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011140ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011140ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011142ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011142ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011148ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011148ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501115bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501115bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011160ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011160ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011162ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011162ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011168ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011168ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501117bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501117bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011180ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011180ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011190ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011190ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011200ull, l_scom_buffer ));

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011200ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011202ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011202ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011206ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<10, 21, 43, uint64_t>(literal_0x181000 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<3, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_GROUP_ID );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<7, 3, 61, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_CHIP_ID );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011206ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011208ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011208ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501121bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501121bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011220ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011220ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011222ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011222ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011226ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<10, 21, 43, uint64_t>(literal_0x181000 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<3, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_GROUP_ID );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<7, 3, 61, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_CHIP_ID );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011226ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011228ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011228ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011230ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011230ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011232ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011232ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011238ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011238ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501123bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501123bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011240ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011240ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011242ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011242ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011246ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<10, 21, 43, uint64_t>(literal_0x181000 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<3, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_GROUP_ID );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<7, 3, 61, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_CHIP_ID );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011246ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011248ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011248ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501125bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501125bull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011260ull, l_scom_buffer ));

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011260ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011262ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
            }

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011262ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011266ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<10, 21, 43, uint64_t>(literal_0x181000 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<3, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_GROUP_ID );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<7, 3, 61, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_CHIP_ID );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011266ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011268ull, l_scom_buffer ));

            if ((l_def_NVLINK_ACTIVE == literal_1))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011268ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501127bull, l_scom_buffer ));

                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x501127bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011280ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011280ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011290ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011290ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011292ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011292ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011298ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011298ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50112c0ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50112c0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50112d0ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50112d0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011345ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x8 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011345ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011382ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0xFFF );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x8 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011382ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011383ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 3, 0, uint64_t>(literal_0xE000000000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011383ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011389ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000740000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011389ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501138aull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7F60B04500AC0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501138aull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501138bull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAA70A55F0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501138bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501138dull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5550740000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501138dull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011400ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011400ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011402ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011402ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011403ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x009B08180F03FFFF );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011403ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011406ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7FE0B04500AC0000 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<10, 21, 43, uint64_t>(literal_0x181000 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<3, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_GROUP_ID );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<7, 3, 61, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_CHIP_ID );
                }
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011406ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011407ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFF85F0FFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011407ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011408ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011408ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011430ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011430ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011432ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011432ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011436ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<10, 21, 43, uint64_t>(literal_0x181000 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<3, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_GROUP_ID );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<7, 3, 61, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_CHIP_ID );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011436ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011438ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011438ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011443ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5558F40007FFFFFF );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011443ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011446ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAA70A55F0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011446ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011447ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011447ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011460ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011460ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011462ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011462ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011466ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<10, 21, 43, uint64_t>(literal_0x181000 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<3, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_GROUP_ID );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<7, 3, 61, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_CHIP_ID );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011466ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011468ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011468ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011490ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0x1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011490ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011492ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T0 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<52, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_READ_CYCLES_T2 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 12, 52, uint64_t>(l_TGT1_ATTR_PROC_EPS_WRITE_CYCLES_T2 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011492ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011496ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0x1 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<10, 21, 43, uint64_t>(literal_0x181000 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<3, 4, 60, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_GROUP_ID );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<7, 3, 61, uint64_t>(l_TGT0_ATTR_PROC_FABRIC_CHIP_ID );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011496ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011498ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011498ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50114c0ull, l_scom_buffer ));

                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<22, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<28, 6, 58, uint64_t>(literal_0x04 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<34, 6, 58, uint64_t>(literal_0x0C );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<40, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<44, 4, 60, uint64_t>(literal_0x4 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50114c0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x50114d0ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<1, 3, 61, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<4, 10, 54, uint64_t>(literal_0x100 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x200 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x300 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x50114d0ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011645ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x8 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011645ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011682ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0xFFF );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0x4 );
                }

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_0x8 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011682ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011683ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 7, 0, uint64_t>(literal_0xE000000000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011683ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5011689ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x0000740000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5011689ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501168aull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7F60B04500AC0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501168aull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501168bull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAA70A55F0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501168bull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x501168dull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5550740000000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x501168dull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c03ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x009B08180F03FFFF );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c03ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c06ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7FE0B04500AC0000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c06ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c07ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFF85F0FFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c07ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c43ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5558F40007FFFFFF );
                }
                else if ((l_def_NVLINK_ACTIVE == literal_0))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c43ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c46ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAA70A55F0000000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c46ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5013c47ull, l_scom_buffer ));

                if ((l_def_NVLINK_ACTIVE == literal_1))
                {
                    l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xFFFFFFFFFFFFFFFF );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x5013c47ull, l_scom_buffer));
            }
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
