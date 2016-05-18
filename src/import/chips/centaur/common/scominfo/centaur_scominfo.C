/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/common/scominfo/centaur_scominfo.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
///
/// @file centaur_scominfo.C
/// @brief Centaur chip unit SCOM address platform translation code
///
/// HWP HWP Owner: unknown
/// HWP FW Owner: dcrowell@us.ibm.com
/// HWP Team: Infrastructure
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

#include "centaur_scominfo.H"

#define centaur_scominfo_C

/* @brief Defines all the bus types we support */

extern "C"
{

    uint64_t centaur_scominfo_createChipUnitScomAddr(centaurChipUnits_t i_CentaurCU, uint8_t i_ChipUnitNum,
            uint64_t i_scomAddr, uint32_t i_mode)
    {
        uint64_t o_scomAddr = i_scomAddr;//default it to pass back the addr that was entered

        if ((o_scomAddr & 0xFFFFFFFFFFFFFC00ull) == 0x03010400)
        {
            if ((o_scomAddr & 0x000003FF) <= 0x0000007f)
            {
                o_scomAddr &= 0x000003FF;

                if (i_ChipUnitNum == 0)
                {
                    o_scomAddr |= 0x03010400;
                }
                else if (i_ChipUnitNum == 1)
                {
                    o_scomAddr |= 0x03010C00;
                }
            }
            else if ( ((o_scomAddr & 0x000003FF) >= 0x00000200) && ((o_scomAddr & 0x000003FF) <= 0x000002FF))
            {
                o_scomAddr &= 0x000003FF;

                if (i_ChipUnitNum == 0)
                {
                    o_scomAddr |= 0x03010400;
                }
                else if (i_ChipUnitNum == 1)
                {
                    o_scomAddr |= 0x03010C00;
                }
            }
        }
        else if ((o_scomAddr & 0xFFFFFFFFFFFFFC00ull) == 0x03011400)
        {
            o_scomAddr &= 0x000003FF;

            if (i_ChipUnitNum == 0)
            {
                o_scomAddr |= 0x03011400;
            }
            else if (i_ChipUnitNum == 1)
            {
                o_scomAddr |= 0x03011800;
            }
        }
        else if ((o_scomAddr & 0xFFF00000FFFFFFFFull) == 0x800000000301143Full)
        {
            o_scomAddr &= 0x000FFFFFF00000000ull;

            if (i_ChipUnitNum == 0)
            {
                o_scomAddr |= 0x800000000301143Full;
            }
            else if (i_ChipUnitNum == 1)
            {
                o_scomAddr |= 0x800000000301183Full;
            }
        }
        else if ((o_scomAddr & 0xFFF00000FFFFFFFFull) == 0x800000000701143Full)
        {
            o_scomAddr &= 0x000FFFFFF00000000ull;

            if (i_ChipUnitNum == 0)
            {
                o_scomAddr |= 0x800000000701143Full;
            }
            else if (i_ChipUnitNum == 1)
            {
                o_scomAddr |= 0x800000000701183Full;
            }
        }

        return o_scomAddr;
    }



    uint32_t centaur_scominfo_isChipUnitScom(uint64_t i_scomAddr, bool& o_chipUnitRelated,
            std::vector<centaur_chipUnitPairing_t>& o_chipUnitPairing, uint32_t i_mode)
    {
        uint32_t rc = 0;
        o_chipUnitRelated = false;

        centaur_chipUnitPairing_t l_singleChipUnitPairing;

        /* got this info from ekb centaur/working/ec_ind/centuar.chipunit.scominfo  */
        if ((i_scomAddr & 0xFFFFFFFFFFFFFC00ull) == 0x03010400)
        {
            if ( ((i_scomAddr & 0x000003FF) <= 0x0000007F) ||
                 (((i_scomAddr & 0x000003FF) >= 0x00000200) && ((i_scomAddr & 0x000003FF) <= 0x000002FF)) )
            {
                o_chipUnitRelated = true;
                l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
                l_singleChipUnitPairing.chipUnitNum = 0;
                o_chipUnitPairing.push_back(l_singleChipUnitPairing);
            }
        }
        else if ((i_scomAddr & 0xFFFFFFFFFFFFFC00ull) == 0x03010C00)
        {
            if ( ((i_scomAddr & 0x000003FF) <= 0x0000007F) ||
                 (((i_scomAddr & 0x000003FF) >= 0x00000200) && ((i_scomAddr & 0x000003FF) <= 0x000002FF)) )
            {
                o_chipUnitRelated = true;
                l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
                l_singleChipUnitPairing.chipUnitNum = 1;
                o_chipUnitPairing.push_back(l_singleChipUnitPairing);
            }
        }
        else if ((i_scomAddr & 0xFFFFFFFFFFFFFC00ull) == 0x03011400)
        {
            o_chipUnitRelated = true;
            l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
            l_singleChipUnitPairing.chipUnitNum = 0;
            o_chipUnitPairing.push_back(l_singleChipUnitPairing);
        }
        else if ((i_scomAddr & 0xFFFFFFFFFFFFFC00ull) == 0x03011800)
        {
            o_chipUnitRelated = true;
            l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
            l_singleChipUnitPairing.chipUnitNum = 1;
            o_chipUnitPairing.push_back(l_singleChipUnitPairing);
        }
        else if ((i_scomAddr & 0xFFFFFFFFFFFFFFC0ull) == 0x03010880)     // trace for MBA01
        {
            o_chipUnitRelated = true;
            l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
            l_singleChipUnitPairing.chipUnitNum = 0;
            o_chipUnitPairing.push_back(l_singleChipUnitPairing);
        }
        else if ((i_scomAddr & 0xFFFFFFFFFFFFFFC0ull) == 0x030110C0)     // trace for MBA23
        {
            o_chipUnitRelated = true;
            l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
            l_singleChipUnitPairing.chipUnitNum = 1;
            o_chipUnitPairing.push_back(l_singleChipUnitPairing);
        }
        else if ((i_scomAddr & 0xFFF00000FFFFFFFFull) == 0x800000000301143Full)
        {
            o_chipUnitRelated = true;
            l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
            l_singleChipUnitPairing.chipUnitNum = 0;
            o_chipUnitPairing.push_back(l_singleChipUnitPairing);
        }
        else if ((i_scomAddr & 0xFFF00000FFFFFFFFull) == 0x800000000301183Full)
        {
            o_chipUnitRelated = true;
            l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
            l_singleChipUnitPairing.chipUnitNum = 1;
            o_chipUnitPairing.push_back(l_singleChipUnitPairing);
        }
        else if ((i_scomAddr & 0xFFF00000FFFFFFFFull) == 0x800000000701143Full)
        {
            o_chipUnitRelated = true;
            l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
            l_singleChipUnitPairing.chipUnitNum = 0;
            o_chipUnitPairing.push_back(l_singleChipUnitPairing);
        }
        else if ((i_scomAddr & 0xFFF00000FFFFFFFFull) == 0x800000000701183Full)
        {
            o_chipUnitRelated = true;
            l_singleChipUnitPairing.chipUnitType = MBA_CHIPUNIT;
            l_singleChipUnitPairing.chipUnitNum = 1;
            o_chipUnitPairing.push_back(l_singleChipUnitPairing);
        }

        return rc;
    }


} // extern "C"

#undef centaur_scominfo_C

