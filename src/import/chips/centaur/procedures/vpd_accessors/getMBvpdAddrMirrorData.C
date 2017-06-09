/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdAddrMirrorData.C $ */
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
///  @file getMBvpdAddrMirror.C
///  @brief Prototype for getMBvpdAddrMirror()-get Address Mirroring Data from MBvpd
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>
#include    <getMBvpdAddrMirrorData.H>
#include <fapi2_mbvpd_access.H>
#include  <generic/memory/lib/utils/c_str.H>

extern "C"
{
///
/// @brief get Address Mirroring Data from cvpd record VSPD keyword AM
/// @param[in]  i_mbaTarget  -   mba target
/// @param[out] o_val        -   2 x 2 array of bytes ([num ports] [num dimms])
///                              Address Mirroring 4 bits per dimm returned
///                              in the lower nibble of the byte for the mba
///
/// @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,relevant error code for failure.
///
    fapi2::ReturnCode getMBvpdAddrMirrorData(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>&   i_mbaTarget,
        uint8_t (& o_val)[2][2])
    {
        //AM keyword layout
        //The following constants are for readibility. They need to stay in sync
        //  with the vpd layout.
        const uint8_t NUM_MBAS =  2;   //There are 2 MBAs per Centaur memory buffer
        const uint8_t NUM_PORTS = 2;   //Each MBA has 2 ports
        struct port_attributes
        {
            uint8_t iv_dimm ; // bits 0:3 DIMM 0 bits 4:7 DIMM 1
        };
        struct mba_attributes
        {
            port_attributes mba_port[NUM_PORTS];
        };
        struct am_keyword
        {
            mba_attributes mb_mba[NUM_MBAS];
            uint8_t        spare[8]; //VPD data CCIN_31E1_v.5.3.ods
        };
        const uint32_t AM_KEYWORD_SIZE = sizeof(am_keyword);  // keyword size

        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_mbTarget;
        uint8_t l_mbaPos = NUM_MBAS; //initialize to out of range value (+1)
        am_keyword* l_pMaBuffer = NULL;  // MBvpd MT keyword buffer
        size_t l_MaBufsize = sizeof(am_keyword);

        FAPI_DBG("getMBvpdAddrMirrorData: entry ");

        // Determine which VPD format we are using
        uint8_t l_customDimm = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_mbaTarget, l_customDimm),
                 "getMBvpdAddrMirrorData: Read of Custom Dimm failed");

        //if not a custom_dimm then assume ISDIMM
        if(fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_NO == l_customDimm)
        {
            // Planar CVPD (==ISDIMM) has no AM keyword, by default there is
            // no mirrored data
            for (uint8_t l_port = 0; l_port < NUM_PORTS; l_port++)
            {
                o_val[l_port][0] = 0;
                o_val[l_port][1] = 0;
            }

            return fapi2::current_err;
        }

        // find the position of the passed mba on the centuar
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_mbaTarget, l_mbaPos),
                 " getMBvpdAddrMirrorData: Get MBA position failed ");

        FAPI_DBG("getMBvpdAddrMirrorData: mba %s position=%d",
                 mss::c_str(i_mbaTarget),
                 l_mbaPos);

        // find the Centaur memmory buffer from the passed MBA
        l_mbTarget = i_mbaTarget.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        FAPI_DBG("getMBvpdAddrMirrorData: parent mb path=%s ",
                 mss::c_str(l_mbTarget)  );

        // Read the AM keyword field
        l_pMaBuffer = new am_keyword;

        FAPI_TRY(getMBvpdField(fapi2::MBVPD_RECORD_VSPD,
                               fapi2::MBVPD_KEYWORD_AM,
                               l_mbTarget,
                               reinterpret_cast<uint8_t*>(l_pMaBuffer),
                               l_MaBufsize),
                 "getMBvpdAddrMirrorData: Read of AM keyword failed");

        // Check that sufficient AM was returned.
        FAPI_ASSERT(l_MaBufsize >= AM_KEYWORD_SIZE,
                    fapi2::CEN_MBVPD_INSUFFICIENT_VPD_RETURNED().
                    set_KEYWORD(fapi2::MBVPD_KEYWORD_AM).
                    set_RETURNED_SIZE(l_MaBufsize).
                    set_CHIP_TARGET(l_mbTarget),
                    "getMBvpdAddrMirrorData:"
                    " less AM keyword returned than expected %d < %d",
                    l_MaBufsize, AM_KEYWORD_SIZE);

        // Return the 4 bits of address mirroring data for each
        // of the 4 DIMMs for the requested mba from the AM keyword buffer
        for (uint8_t l_port = 0; l_port < NUM_PORTS; l_port++)
        {
            uint8_t l_dimm = l_pMaBuffer->
                             mb_mba[l_mbaPos].mba_port[l_port].iv_dimm;
            o_val[l_port][0] = ((l_dimm & 0xF0) >> 4);
            o_val[l_port][1] = l_dimm & 0x0F;
        }

        if( l_pMaBuffer )
        {
            delete l_pMaBuffer;
            l_pMaBuffer = NULL;
        }

        FAPI_DBG("getMBvpdAddrMirrorData: exit");

    fapi_try_exit:
        return fapi2::current_err;
    }

}   // extern "C"
