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
// $Id: getMBvpdSpareDramData.C,v 1.3 2013/09/12 14:12:39 mjjones Exp $
#include  <stdint.h>

//  fapi support
#include  <fapi.H>
#include  <dimmConsts.H>
#include  <getMBvpdSpareDramData.H>

extern "C"
{
using namespace fapi;

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
        // third (dimm) dimension contains a byte where each two bits of that
        // byte are the spare status for a particular rank.
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
                // Shift amount decrements each time as l_dimmMask is shifted
                // to the right
                uint8_t l_rankBitShift = 6;
                for (uint8_t k = 0; k < DIMM_DQ_MAX_DIMM_RANKS; k++)
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
    }while(0);

    delete l_pAmBuffer;
    l_pAmBuffer = NULL;
    return l_rc;
}

}  // extern "C"
