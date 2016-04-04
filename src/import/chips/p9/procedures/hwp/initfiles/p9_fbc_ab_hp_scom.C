/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ab_hp_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
#include "p9_fbc_ab_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0 = 0;

fapi2::ReturnCode p9_fbc_ab_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_Type l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP, TGT0, l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP)");
            break;
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x501180bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501180bull)");
                break;
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 61 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 62 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x501180bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501180bull)");
                break;
            }
        }

        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
            break;
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x501180full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501180full)");
                break;
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 61 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 62 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x501180full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501180full)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011c0bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c0bull)");
                break;
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 61 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 62 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c0bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c0bull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5011c0full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5011c0full)");
                break;
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 61 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 62 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5011c0full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5011c0full)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x501200bull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501200bull)");
                break;
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_scom_buffer_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 61 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 62 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_OFF, 0, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x501200bull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501200bull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x501200full, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x501200full)");
                break;
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE))
            {
                constexpr auto l_scom_buffer_ON = 0x7;
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 61 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 62 );
                l_scom_buffer.insert<uint64_t> (l_scom_buffer_ON, 0, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x501200full, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x501200full)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
