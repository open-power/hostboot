/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mvpd_accessors/getMBvpdSpareDramData.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: getMBvpdSpareDramData.C,v 1.1 2013/08/13 20:35:13 mjjones Exp $
#include  <stdint.h>

//  fapi support
#include  <fapi.H>
#include  <dimmConsts.H>
#include  <getMBvpdSpareDramData.H>

extern "C"
{
using namespace fapi;

fapi::ReturnCode getMBvpdSpareDramData(const fapi::Target &i_mba,
                                       const fapi::Target &i_dimm,
                                       uint8_t &o_data)

{
    // AM keyword layout
    const uint8_t NUM_MBAS =  2; // Two MBAs per Centaur
    const uint8_t NUM_PORTS =  2; // Two ports per MBA
    const uint8_t NUM_DIMMS = 2; // Two DIMMS per port
    const uint8_t NUM_MIRR_BYTES = 4; // Size of address mirror data

    // Struct for AM Keyword buffer
    // Contains a simple array for the address mirror data and
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
        DimmSpareData iv_dimmSpareData[NUM_DIMMS];
    };
    struct MbaSpareData
    {
        PortSpareData iv_portSpareData[NUM_PORTS];
    };
    struct AmKeyword
    {
        MirrorData mirrorData;
        MbaSpareData iv_mbaSpareData[NUM_MBAS];
    };

    // Old VPD without the Spare Data
    const uint8_t VPD_WITHOUT_SPARE_DATA_SIZE = sizeof(MirrorData);

    // Current VPD AM keyword size
    const uint32_t AM_KEYWORD_SIZE = sizeof(AmKeyword);
    fapi::ReturnCode l_rc;
    // Centaur target
    fapi::Target l_mbTarget;
    // MBvpd AM keyword buffer
    AmKeyword * l_pAmBuffer = NULL;
    uint32_t  l_AmBufSize = sizeof(AmKeyword);

    do
    {
        // Check to see if IS-DIMM
        uint8_t l_dimmType = 0;
        l_rc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM, &i_dimm, l_dimmType);
        if (l_rc)
        {
            FAPI_ERR("getMBvpdSpareDramData: "
                     "Error getting ATTR_SPD_CUSTOM");
            break;
        }
        if (fapi::ENUM_ATTR_SPD_CUSTOM_NO == l_dimmType)
        {
            //IS-DIMM, return NO_SPARE
            o_data = fapi::ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE;
            break;
        }

        // find the Centaur memory buffer from the passed MBA
        l_rc = fapiGetParentChip (i_mba,l_mbTarget);
        if (l_rc)
        {
            FAPI_ERR("getMBvpdSpareDramData: Finding the parent mb failed ");
            break;
        }

        // Read AM keyword field
        l_pAmBuffer = new AmKeyword;
        l_rc = fapiGetMBvpdField(fapi::MBVPD_RECORD_VSPD,
                                 fapi::MBVPD_KEYWORD_AM,
                                 l_mbTarget,
                                 reinterpret_cast<uint8_t *>(l_pAmBuffer),
                                 l_AmBufSize);

        if (l_rc)
        {
            FAPI_ERR("getMBvpdSpareDramData: Read of AM keyword failed");
            break;
        }

        // Check correct amount of data returned
        if (l_AmBufSize < AM_KEYWORD_SIZE)
        {

            // If Old VPD
            if (VPD_WITHOUT_SPARE_DATA_SIZE == l_AmBufSize)
            {
                // Because prior VPD AM keyword does not contain
                // spare DRAM data, the ATTR_SPD_DRAM_WIDTH
                // attribute is used to determine spare DRAM availability.
                // If x4 configuration, assume LOW_NIBBLE.
                // Otherwise, FULL_BYTE.
                uint8_t l_dramWidth = 0;
                l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_WIDTH, &i_dimm, l_dramWidth);
                if (l_rc)
                {
                    FAPI_ERR("getMBvpdSpareDramData: "
                             "Error getting DRAM spare data");
                    break;
                }
                // If x4 configuration, low nibble.
                if (fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W4 == l_dramWidth)
                {
                    o_data = fapi::ENUM_ATTR_VPD_DIMM_SPARE_LOW_NIBBLE;
                    break;
                }
                // Else, full spare.
                else
                {
                    o_data = fapi::ENUM_ATTR_VPD_DIMM_SPARE_FULL_BYTE;
                    break;
                }
            }

            else
            {
                FAPI_ERR("getMBvpdSpareDramData: "
                         "Insufficient amount of data returned:"
                         " %u < %u", l_AmBufSize, AM_KEYWORD_SIZE);
                const uint32_t & KEYWORD = fapi::MBVPD_KEYWORD_AM;
                const uint32_t & RETURNED_SIZE = l_AmBufSize;
                FAPI_SET_HWP_ERROR(l_rc,
                                   RC_MBVPD_INSUFFICIENT_VPD_RETURNED);
                break;
            }
        }


        // Return the spare DRAM availability for particular dimm
        // Find the position of the passed mba on the centuar
        uint8_t l_mba = 0;
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_mba, l_mba);
        if (l_rc)
        {
            FAPI_ERR("getMBvpdSpareDramData: Get MBA position failed ");
            break;
        }
        // Find the mba port this dimm is connected to
        uint8_t l_mbaPort = 0;
        l_rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &i_dimm, l_mbaPort);
        if (l_rc)
        {
            FAPI_ERR("getMBvpdSpareDramData: "
                     "Error getting MBA port number");
            break;
        }
        // Find the dimm number associated with this dimm
        uint8_t l_dimm = 0;
        l_rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &i_dimm, l_dimm);
        if (l_rc)
        {
            FAPI_ERR("getMBvpdSpareDramData: "
                     "Error getting dimm number");
            break;
        }

        o_data = l_pAmBuffer->iv_mbaSpareData[l_mba].\
                 iv_portSpareData[l_mbaPort].\
                 iv_dimmSpareData[l_dimm].iv_dimmSpareData;

    }while(0);

    delete l_pAmBuffer;
    l_pAmBuffer = NULL;
    return l_rc;
}

}  // extern "C"
