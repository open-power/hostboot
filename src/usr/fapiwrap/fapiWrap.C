/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapiwrap/fapiWrap.C $                                 */
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

// Platform includes
#include <fapiwrap/fapiWrapif.H>    // interface definitions
#include <fapi2/plat_hwp_invoker.H> // FAPI_INVOKE_HWP
#include <trace/interface.H>        // tracing includes
#include <vpd/spdenums.H>           // DDIMM_DDR4_SPD_SIZE
#include <devicefw/driverif.H>      // deviceRead

// Imported Includes
#include <exp_getidec.H>           // exp_getidec
#include <pmic_i2c_addr_get.H>     // get_pmic_i2c_addr
#include <chipids.H>               // for GEMINI ID
#include <gpio_adc_i2c_addr_get.H> // for get_gpio_adc_i2c_addr

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

    errlHndl_t get_pmic_dev_addr( TARGETING::Target * i_ocmbChip,
                                  const uint8_t i_pmic_id,
                                  uint8_t& o_pmic_devAddr)
    {
        errlHndl_t l_errl = nullptr;

        do{

            auto l_chipId = i_ocmbChip->getAttr< TARGETING::ATTR_CHIP_ID>();

            if( l_chipId == POWER_CHIPID::GEMINI_16)
            {
                // If this is a Gemini OCMB then there are no PMIC targets
                // so just set the out parm to NO_PMIC_DEV_ADDR and break
                o_pmic_devAddr = NO_PMIC_DEV_ADDR;
                break;
            }

            uint8_t l_spdBlob[SPD::DDIMM_DDR4_SPD_SIZE];
            size_t l_spdSize = SPD::DDIMM_DDR4_SPD_SIZE;

            l_errl = deviceRead(i_ocmbChip,
                        l_spdBlob,
                        l_spdSize,
                        DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD_WITHOUT_EFD));

            if(l_errl)
            {
                TRACFCOMP( g_trac_fapiwrap, ERR_MRK"get_pmic_dev_addr() "
                            "Error reading SPD associated with OCMB 0x%.08X",
                            TARGETING::get_huid(i_ocmbChip));
                break;
            }

            o_pmic_devAddr = get_pmic_i2c_addr(
                                   reinterpret_cast<char *>(l_spdBlob),
                                   i_pmic_id);

        }while(0);
        return l_errl;
    }

    errlHndl_t get_gpio_adc_dev_addr( const uint8_t i_rel_pos,
                                      uint8_t& o_devAddr)
    {
        errlHndl_t l_errl = nullptr;

        do{

            o_devAddr = get_gpio_adc_i2c_addr(i_rel_pos);

        }while(0);
        return l_errl;
    }


}
