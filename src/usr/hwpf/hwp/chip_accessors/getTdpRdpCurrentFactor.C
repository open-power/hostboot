/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/chip_accessors/getTdpRdpCurrentFactor.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: getTdpRdpCurrentFactor.C,v 1.6 2015/09/15 20:31:49 whs Exp $
/**
 *  @file getTdpRdpCurrentFactor.C
 *
 *  @brief Accessor for providing the ATTR_TDP_RDP_CURRENT_FACTOR attribute
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <fapiUtil.H>
#include    <getTdpRdpCurrentFactor.H>

extern "C"
{
using   namespace   fapi;

fapi::ReturnCode getTdpRdpCurrentFactor(
                              const fapi::Target   &i_procTarget,
                              uint32_t  & o_val)
{

    const uint32_t DEFAULT_TDP_RDP_CURRENT_FACTOR = 9180;  // 91.90% = 0x9180
    // IQ keyword layout
    const uint8_t NUM_ENTRIES =  4;    // The IQ keyword has 4 sub entries
    const uint8_t TDP_RDP_ENTRY =0;    // Array index for LRP9 Entry 1

    struct iq_entry
    {
       uint8_t iv_MSB;   // data in big endian format
       uint8_t iv_LSB;
    };
    struct iq_keyword
    {
        uint8_t iv_version;
        iq_entry entry[NUM_ENTRIES];
    };

    fapi::ReturnCode l_fapirc;
    uint32_t l_tdpRdp = 0;

    FAPI_DBG("getTdpRdpCurrentFactor: entry");

    do
    {
        // On WOF enabled systems, mvpd record LRP9 keyword IQ has the
        // TDP RDP current factor. LRP9 is not present for Murano processors
        // and is present, but not defined as TDP RPD current factor on other
        // Venice processors.
        // Only look for TDP RPD current factor in vpd for WOF enabled systems.

        // See if WOF enabled
        uint8_t l_WofEnabled = ENUM_ATTR_WOF_ENABLED_DISABLED;
        l_fapirc = FAPI_ATTR_GET(ATTR_WOF_ENABLED,NULL,l_WofEnabled);
        if ( l_fapirc  )
        {
            FAPI_IMP("getTdpRdpCurrentFactor: get ATTR_WOF_ENABLED failed, "
                     "rc=0x%08x",
                     static_cast<uint32_t>(l_fapirc));
            break;  // return with error. Unexpected.
        }
        else if (ENUM_ATTR_WOF_ENABLED_DISABLED == l_WofEnabled)
        {
            break;  // not a WOF enabled system. Return with 0 value. No error.
        }

        // Read TDP RDP current factor from LRP9 IQ keyword.
        // Expected to be present on WOF enabled system.
        iq_keyword l_iqKeyword = {0,{{0}}};
        uint32_t l_bufsize = sizeof(l_iqKeyword);

        l_fapirc = fapiGetMvpdField(MVPD_RECORD_LRP9,
                                    MVPD_KEYWORD_IQ,
                                    i_procTarget,
                                    (uint8_t*)(&l_iqKeyword),
                                    l_bufsize );
        if ( l_fapirc  )
        {
            FAPI_IMP("getTdpRdpCurrentFactor: get LRP9 IQ failed, "
                     "rc=0x%08x",
                     static_cast<uint32_t>(l_fapirc));
            break;  // return with  error
        }
        if (l_bufsize < sizeof(l_iqKeyword)) //ensure expected data retured
        {
            FAPI_ERR("getTdpRdpCurrentFacto:"
                     " less IQ keyword returned than expected %d < %d, "
                     " use default",
                       l_bufsize, sizeof(l_iqKeyword));
            const uint32_t & KEYWORD = fapi::MVPD_KEYWORD_IQ;
            const uint32_t & RETURNED_SIZE = l_bufsize;
            const uint32_t & EXPECTED_SIZE = sizeof(l_iqKeyword);
            const fapi::Target & CHIP_TARGET = i_procTarget;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_INSUFFICIENT_VPD_RETURNED );
            break;  // return with error. Unexpected.
        }
        // get TDP RDP current factor endian safe
        l_tdpRdp  = l_iqKeyword.entry[TDP_RDP_ENTRY].iv_LSB;
        l_tdpRdp |= (l_iqKeyword.entry[TDP_RDP_ENTRY].iv_MSB<<8);
        FAPI_DBG("getTdpRdpCurrentFactor: LRP9 IQ value=%d",l_tdpRdp);

        // use default if value not filled in by mfg
        if (!l_tdpRdp)
        {
            l_tdpRdp = DEFAULT_TDP_RDP_CURRENT_FACTOR;
            FAPI_IMP("getTdpRdpCurrentFactor: use default value=%d",l_tdpRdp);
        }
    } while (0);

    // return value
    o_val = l_tdpRdp;

    return  l_fapirc;
}

}   // extern "C"
