/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdSpareDramData.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
// $Id: getMBvpdSpareDramData.C,v 1.9 2016/06/03 11:41:23 thi Exp $
#include  <stdint.h>

//  fapi support
#include  <fapi.H>
#include  <dimmConsts.H>
#include  <getMBvpdSpareDramData.H>

extern "C"
{
using namespace fapi;

/**
 * @brief Function to check if the system has Custom DIMM type (CDIMM).
 * @param[in] i_tgtHandle   Reference to MBA target
 * @param[o]  o_customDimm  Return value - ENUM_ATTR_SPD_CUSTOM_NO
 *                                      or ENUM_ATTR_SPD_CUSTOM_YES
 * @return ReturnCode
 */
fapi::ReturnCode getDimmTypeFromSPD(const fapi::Target &i_tgtHandle,
                             uint8_t &o_customDimm);



fapi::ReturnCode getMBvpdSpareDramData(const fapi::Target &i_mba,
                                       uint8_t (&o_data)[DIMM_DQ_MAX_MBA_PORTS]
                                                    [DIMM_DQ_MAX_MBAPORT_DIMMS]
                                                    [DIMM_DQ_MAX_DIMM_RANKS])
{
    // AM keyword layout
    const uint8_t NUM_MBAS =  2; // Two MBAs per Centaur
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
        DimmSpareData iv_dimmSpareData[DIMM_DQ_MAX_MBAPORT_DIMMS];
    };
    struct MbaSpareData
    {
        PortSpareData iv_portSpareData[DIMM_DQ_MAX_MBA_PORTS];
    };
    struct AmKeyword
    {
        MirrorData mirrorData;
        MbaSpareData iv_mbaSpareData[NUM_MBAS];
    };

    // AM keyword size
    const uint32_t AM_KEYWORD_SIZE = sizeof(AmKeyword);
    fapi::ReturnCode l_rc;
    // Centaur memory buffer target
    fapi::Target l_mbTarget;
    // MBvpd AM keyword buffer
    AmKeyword * l_pAmBuffer = NULL;
    uint32_t  l_AmBufSize = sizeof(AmKeyword);

    do
    {
        uint8_t l_customDimm = 0;

        l_rc = getDimmTypeFromSPD(i_mba,l_customDimm);
        if(l_rc)
        {
            FAPI_ERR("getMBvpdSpareDramData: Read of Custom Dimm failed");
            break;
        }

        //if custom_dimm = 0, use isdimm
        if(fapi::ENUM_ATTR_SPD_CUSTOM_NO == l_customDimm)
        {
            //ISDIMMs do not have any spare drams,
            //return 0 for all ports and ranks.
            for (uint8_t i = 0; i < DIMM_DQ_MAX_MBA_PORTS; i++)
            {
                for (uint8_t j = 0; j < DIMM_DQ_MAX_MBAPORT_DIMMS; j++)
                {
                    for (uint8_t k = 0; k < DIMM_DQ_MAX_DIMM_RANKS; k++)
                    {
                        o_data[i][j][k] = 0;
                    }
                }
            }
        //if custom_dimm = 1, use cdimm
        }else
        {
            // find the Centaur memory buffer from the passed MBA
            l_rc = fapiGetParentChip (i_mba, l_mbTarget);
            if (l_rc)
            {
                FAPI_ERR("getMBvpdSpareDramData: Finding the parent mb failed ");
                break;
            }

            // Read AM keyword field
            l_pAmBuffer = new AmKeyword();
            l_rc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                     fapi::MBVPD_KEYWORD_AM,
                                     l_mbTarget,
                                     reinterpret_cast<uint8_t *>(l_pAmBuffer),
                                     l_AmBufSize);
            if (l_rc)
            {
                FAPI_ERR("getMBvpdSpareDramData: "
                         "Read of AM Keyword failed");
                break;
            }

            // Check for error or incorrect amount of data returned
            if (l_AmBufSize < AM_KEYWORD_SIZE)
            {
                FAPI_ERR("getMBvpdSpareDramData:"
                         " less AM keyword returned than expected %d < %d",
                           l_AmBufSize, AM_KEYWORD_SIZE);
                const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_AM;
                const uint32_t & RETURNED_SIZE = l_AmBufSize;
                const fapi::Target & CHIP_TARGET = l_mbTarget;
                FAPI_SET_HWP_ERROR(l_rc, RC_MBVPD_INSUFFICIENT_VPD_RETURNED );
                break;
            }

            // Find the position of the passed mba on the centuar
            uint8_t l_mba = 0;
            l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_mba, l_mba);

            if (l_rc)
            {
                FAPI_ERR("getMBvpdSpareDramData: Get MBA position failed ");
                break;
            }
            // Data in the AM Keyword contains information for both MBAs and
            // is stored in [mba][port][dimm] ([2][2][2]) format, where the
            // third (dimm) dimension contains a byte where each two bits of
            // that byte are the spare status for a particular rank.
            // The caller expects data returned for a particular MBA,
            // and where the ranks for each dimm are separately indexed,
            // so conversion to a [port][dimm][rank] ([2][2][4]) format
            // is necessary.
            for (uint8_t i = 0; i < DIMM_DQ_MAX_MBA_PORTS; i++)
            {
                for (uint8_t j = 0; j < DIMM_DQ_MAX_MBAPORT_DIMMS; j++)
                {
                    // Mask to pull of two bits at a time from iv_dimmSpareData
                    uint8_t l_dimmMask = 0xC0;
                    // Shift amount decrements each time as l_dimmMask
                    // is shifted to the right
                    uint8_t l_rankBitShift = 6;
                    for (uint8_t k = 0; k < DIMM_DQ_MAX_DIMM_RANKS; k++)
                    {
                        o_data[i][j][k] =((l_pAmBuffer->iv_mbaSpareData[l_mba].
                                       iv_portSpareData[i].iv_dimmSpareData[j].
                                       iv_dimmSpareData & l_dimmMask) >>
                                       l_rankBitShift);
                        l_dimmMask >>= 2;
                        l_rankBitShift -= 2;
                    }
                }
            }
        }
    }while(0);
    delete l_pAmBuffer;
    l_pAmBuffer = NULL;
    return l_rc;
}



fapi::ReturnCode getDimmTypeFromSPD(const fapi::Target &i_tgtHandle,
                             uint8_t &o_customDimm)
{
    fapi::ReturnCode          l_rc;

    do
    {
        o_customDimm = fapi::ENUM_ATTR_SPD_CUSTOM_NO;

        std::vector<fapi::Target> l_target_dimm_array;

        l_rc =  fapiGetAssociatedDimms(i_tgtHandle, l_target_dimm_array);

        if(l_rc)
        {
            FAPI_ERR("Error (0x%x), from fapiGetAssociatedDimms",
                    static_cast<uint32_t>(l_rc));
            break;
        }

        if(0 != l_target_dimm_array.size())
        {
            l_rc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM,
                    &l_target_dimm_array[0],
                    o_customDimm);
            if(l_rc)
            {
                FAPI_ERR("Error (0x%x), from FAPI_ATTR_GET",
                        static_cast<uint32_t>(l_rc));
                break;
            }
        }
        else
        {
            o_customDimm = fapi::ENUM_ATTR_SPD_CUSTOM_NO;
        }
    }while(0);

    return l_rc;
}


}  // extern "C"
