/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_omi_scom.C $ */
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
#include "p10_omi_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b000 = 0b000;

fapi2::ReturnCode p10_omi_scom(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& TGT0,
                               const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80042c4010012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80042c4010012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80042c4110012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80042c4110012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80042c4210012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80042c4210012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80042c4310012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80042c4310012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80042c4410012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80042c4410012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80042c4510012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80042c4510012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80042c4610012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80042c4610012c3full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80042c4710012c3full, l_scom_buffer ));

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_IS_SIM)
            {
                l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80042c4710012c3full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
