/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdSpareDramData.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file getMBvpdSpareDramData.H
/// @brief queries the MBvpd to determine spare DRAM availability
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include  <stdint.h>

//  fapi2 support
#include  <fapi2.H>
#include  <getMBvpdSpareDramData.H>
#include  <dimmConsts.H>
#include <fapi2_mbvpd_access.H>

extern "C"
{

///
/// @brief Function to check if the system has Custom DIMM type (CDIMM).
/// @param[in] i_tgtHandle   Reference to MBA target
/// @param[out]  o_customDimm  Return value - fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO
///                                      or fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_YES
/// @return ReturnCode
///
    fapi2::ReturnCode getDimmTypeFromSPD(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_tgtHandle,
                                         uint8_t& o_customDimm);


///
/// @brief FW Team HWP that handles the ATTR_VPD_DIMM_SPARE attribute
/// by querying MBvpd to determine spare DRAM availability for C-DIMMs.
///
/// @note This HWP should be called through the VPD_DIMM_SPARE attribute.
/// @param[in]  i_mba       Reference to MBA Target.
/// @param[out] o_data      Reference to spare DRAM data.
/// @return ReturnCode
///
    fapi2::ReturnCode getMBvpdSpareDramData(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
                                            uint8_t (&o_data)[MAX_PORTS_PER_MBA]
                                            [MAX_DIMM_PER_PORT]
                                            [MAX_RANKS_PER_DIMM])
    {
        // AM keyword layout
        const uint8_t NUM_MIRR_BYTES = 4; // Size of address mirror data

        // Struct for AM Keyword buffer
        // Contains a 1D array for the address mirror data and
        // a 2D array for the spare DRAM data.
        struct MirrorData
        {
            uint8_t iv_mirrorData[NUM_MIRR_BYTES];
        };
        struct DimmSpareData
        {
            // This contains information for all ranks and is returned in o_data
            uint8_t iv_dimmSpareData;
        };
        struct PortSpareData
        {
            DimmSpareData iv_dimmSpareData[MAX_DIMM_PER_PORT];
        };
        struct MbaSpareData
        {
            PortSpareData iv_portSpareData[MAX_PORTS_PER_MBA];
        };
        struct AmKeyword
        {
            MirrorData mirrorData;
            MbaSpareData iv_mbaSpareData[MAX_MBA_PER_CEN];
        };

        // AM keyword size
        const uint32_t AM_KEYWORD_SIZE = sizeof(AmKeyword);
        // Centaur memory buffer target
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_mbTarget;
        // MBvpd AM keyword buffer
        AmKeyword* l_pAmBuffer = NULL;
        size_t l_AmBufSize = sizeof(AmKeyword);

        uint8_t l_customDimm = 0;

        FAPI_TRY(getDimmTypeFromSPD(i_mba, l_customDimm), "getMBvpdSpareDramData: Read of Custom Dimm failed");

        //if custom_dimm = 0, use isdimm
        if(fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO == l_customDimm)
        {
            //ISDIMMs do not have any spare drams,
            //return 0 for all ports and ranks.
            for (uint8_t i = 0; i < MAX_PORTS_PER_MBA; i++)
            {
                for (uint8_t j = 0; j < MAX_DIMM_PER_PORT; j++)
                {
                    for (uint8_t k = 0; k < MAX_RANKS_PER_DIMM; k++)
                    {
                        o_data[i][j][k] = 0;
                    }
                }
            }

            //if custom_dimm = 1, use cdimm
        }
        else
        {
            // find the Centaur memory buffer from the passed MBA
            l_mbTarget = i_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

            // Read AM keyword field
            l_pAmBuffer = new AmKeyword();
            FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                                   fapi2::MBVPD_KEYWORD_AM,
                                   l_mbTarget,
                                   reinterpret_cast<uint8_t*>(l_pAmBuffer),
                                   l_AmBufSize), "getMBvpdSpareDramData: "
                     "Read of AM Keyword failed");

            // Check for error or incorrect amount of data returned
            FAPI_ASSERT(l_AmBufSize >= AM_KEYWORD_SIZE,
                        fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                        set_KEYWORD(fapi2::MBVPD_KEYWORD_AM).
                        set_RETURNED_SIZE(l_AmBufSize).
                        set_CHIP_TARGET(l_mbTarget),
                        "getMBvpdSpareDramData:"
                        " less AM keyword returned than expected %d < %d",
                        l_AmBufSize, AM_KEYWORD_SIZE);

            // Find the position of the passed mba on the centuar
            uint8_t l_mba = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_mba,  l_mba), "getMBvpdSpareDramData: Get MBA position failed ");

            // Data in the AM Keyword contains information for both MBAs and
            // is stored in [mba][port][dimm] ([2][2][2]) format, where the
            // third (dimm) dimension contains a byte where each two bits of
            // that byte are the spare status for a particular rank.
            // The caller expects data returned for a particular MBA,
            // and where the ranks for each dimm are separately indexed,
            // so conversion to a [port][dimm][rank] ([2][2][4]) format
            // is necessary.
            for (uint8_t i = 0; i < MAX_PORTS_PER_MBA; i++)
            {
                for (uint8_t j = 0; j < MAX_DIMM_PER_PORT; j++)
                {
                    // Mask to pull of two bits at a time from iv_dimmSpareData
                    uint8_t l_dimmMask = 0xC0;
                    // Shift amount decrements each time as l_dimmMask
                    // is shifted to the right
                    uint8_t l_rankBitShift = 6;

                    for (uint8_t k = 0; k < MAX_RANKS_PER_DIMM; k++)
                    {
                        o_data[i][j][k] = ((l_pAmBuffer->iv_mbaSpareData[l_mba].
                                            iv_portSpareData[i].iv_dimmSpareData[j].
                                            iv_dimmSpareData & l_dimmMask) >>
                                           l_rankBitShift);
                        l_dimmMask >>= 2;
                        l_rankBitShift -= 2;
                    }
                }
            }
        }

        delete l_pAmBuffer;
        l_pAmBuffer = NULL;
    fapi_try_exit:
        return fapi2::current_err;
    }


///
/// @brief Function to check if the system has Custom DIMM type (CDIMM).
/// @param[in] i_tgtHandle   Reference to MBA target
/// @param[out]  o_customDimm  Return value - fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO
///                                      or fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_YES
/// @return ReturnCode
///
    fapi2::ReturnCode getDimmTypeFromSPD(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_tgtHandle,
                                         uint8_t& o_customDimm)
    {
        o_customDimm = fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO;
        auto l_target_dimm_array = i_tgtHandle.getChildren<fapi2::TARGET_TYPE_DIMM>();

        if(0 != l_target_dimm_array.size())
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM,
                                   l_target_dimm_array[0],
                                   o_customDimm), "Error from FAPI_ATTR_GET");
        }
        else
        {
            o_customDimm = fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }


}  // extern "C"
