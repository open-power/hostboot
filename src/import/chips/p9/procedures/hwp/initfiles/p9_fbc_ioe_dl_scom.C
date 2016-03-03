/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ioe_dl_scom.C $ */
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
#include "p9_fbc_ioe_dl_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>
#include <attribute_ids.H>
#include <target_types.H>
#include <fapi2_attribute_service.H>
using namespace fapi2;

#define LITERAL_PB_IOE_LL1_CONFIG_CRC_LANE_ID_ON    0x1
#define LITERAL_PB_IOE_LL1_CONFIG_LINK_PAIR_ON    0x1
#define LITERAL_PB_IOE_LL1_IOEL_FIR_MASK_REG_0xFFFFFFFFFFFFFFFF    0xFFFFFFFFFFFFFFFF
#define LITERAL_PB_IOE_LL1_THRESH_REPLAY_ENABLE_0xE00    0xE00
#define LITERAL_PB_IOE_LL1_THRESH_REPLAY_LINK0_COUNT_0x0000    0x0000
#define LITERAL_PB_IOE_LL1_THRESH_REPLAY_TAP_SEL_0x0    0x0
#define LITERAL_PB_IOE_LL1_THRESH_REPLAY_TB_SEL_0x0    0x0
#define LITERAL_PB_IOE_LL1_THRESH_SL_ECC_ENABLE_0b11    0b11
#define LITERAL_PB_IOE_LL1_THRESH_SL_ECC_LINK0_COUNT_0x0000    0x0000
#define LITERAL_PB_IOE_LL1_THRESH_SL_ECC_TAP_SEL_0x0    0x0
#define LITERAL_PB_IOE_LL1_THRESH_SL_ECC_TB_SEL_0x0    0x0

fapi2::ReturnCode p9_fbc_ioe_dl_scom(const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& TGT0)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> PB_IOE_LL1_CONFIG_LINK_PAIR_scom0;
        l_rc = fapi2::getScom( TGT0, 0x601180aull, PB_IOE_LL1_CONFIG_LINK_PAIR_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x601180a)");
            break;
        }

        PB_IOE_LL1_CONFIG_LINK_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_CONFIG_LINK_PAIR_ON, 0, 1, 63 );

        fapi2::buffer<uint64_t> PB_IOE_LL1_IOEL_FIR_MASK_REG_scom0;
        l_rc = fapi2::getScom( TGT0, 0x6011803ull, PB_IOE_LL1_IOEL_FIR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x6011803)");
            break;
        }

        PB_IOE_LL1_IOEL_FIR_MASK_REG_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_IOEL_FIR_MASK_REG_0xFFFFFFFFFFFFFFFF, 0, 64,
                0 );

        PB_IOE_LL1_CONFIG_LINK_PAIR_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_CONFIG_CRC_LANE_ID_ON, 2, 1, 63 );

        fapi2::buffer<uint64_t> PB_IOE_LL1_THRESH_REPLAY_ENABLE_scom0;
        l_rc = fapi2::getScom( TGT0, 0x6011818ull, PB_IOE_LL1_THRESH_REPLAY_ENABLE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x6011818)");
            break;
        }

        PB_IOE_LL1_THRESH_REPLAY_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_REPLAY_ENABLE_0xE00, 8, 3, 61 );

        PB_IOE_LL1_THRESH_REPLAY_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_REPLAY_LINK0_COUNT_0x0000, 32, 16,
                48 );
        PB_IOE_LL1_THRESH_REPLAY_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_REPLAY_LINK0_COUNT_0x0000, 48, 16,
                48 );

        PB_IOE_LL1_THRESH_REPLAY_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_REPLAY_TAP_SEL_0x0, 4, 4, 60 );

        PB_IOE_LL1_THRESH_REPLAY_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_REPLAY_TB_SEL_0x0, 0, 4, 60 );

        fapi2::buffer<uint64_t> PB_IOE_LL1_THRESH_SL_ECC_ENABLE_scom0;
        l_rc = fapi2::getScom( TGT0, 0x6011819ull, PB_IOE_LL1_THRESH_SL_ECC_ENABLE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: getScom (0x6011819)");
            break;
        }

        PB_IOE_LL1_THRESH_SL_ECC_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_SL_ECC_ENABLE_0b11, 8, 2, 62 );

        PB_IOE_LL1_THRESH_SL_ECC_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_SL_ECC_LINK0_COUNT_0x0000, 32, 16,
                48 );
        PB_IOE_LL1_THRESH_SL_ECC_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_SL_ECC_LINK0_COUNT_0x0000, 48, 16,
                48 );

        PB_IOE_LL1_THRESH_SL_ECC_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_SL_ECC_TAP_SEL_0x0, 4, 4, 60 );

        PB_IOE_LL1_THRESH_SL_ECC_ENABLE_scom0.insert<uint64_t> (LITERAL_PB_IOE_LL1_THRESH_SL_ECC_TB_SEL_0x0, 0, 4, 60 );


        l_rc = fapi2::putScom( TGT0, 0x6011803ull, PB_IOE_LL1_IOEL_FIR_MASK_REG_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x6011803)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x601180aull, PB_IOE_LL1_CONFIG_LINK_PAIR_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x601180a)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x6011818ull, PB_IOE_LL1_THRESH_REPLAY_ENABLE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x6011818)");
            break;
        }

        l_rc = fapi2::putScom( TGT0, 0x6011819ull, PB_IOE_LL1_THRESH_SL_ECC_ENABLE_scom0 );

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: putScom (0x6011819)");
            break;
        }

    }
    while(0);

    return l_rc;
}
