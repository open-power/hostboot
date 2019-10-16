/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapiwrap/fapiWrap.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#include <fapiwrap/fapiWrapif.H> // interface definitions
#include <fapi2/plat_hwp_invoker.H> // FAPI_INVOKE_HWP
#include <trace/interface.H> // tracing includes

#include <exp_getidec.H>       // exp_getidec
#include <pmic_i2c_addr_get.H> // get_pmic_i2c_addr

trace_desc_t* g_trac_fapiwrap;
TRAC_INIT(&g_trac_fapiwrap, FAPIWRAP_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);


namespace FAPIWRAP
{
    errlHndl_t explorer_getidec( TARGETING::Target * i_ocmbChip,
                                 uint16_t& o_chipId,
                                 uint8_t&  o_ec)
    {
        errlHndl_t l_errl = nullptr;

        //assert type of i_ocmbChip == TARGETING::TYPE_OCMB_CHIP
        assert(i_ocmbChip->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_OCMB_CHIP,
               "exp_getidec_wrap: error expected type OCMB_CHIP");

        fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(i_ocmbChip);

        FAPI_INVOKE_HWP(l_errl,
                        exp_getidec,
                        l_fapi_ocmb_target,
                        o_chipId,
                        o_ec);

        return l_errl;
    }

    uint8_t get_pmic_dev_addr( const char* i_spd,
                               const uint8_t i_pmic_id)
    {
        return get_pmic_i2c_addr(i_spd, i_pmic_id);
    }
}