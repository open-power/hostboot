/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapiwrap/fapiWrap.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
#include <mds_i2c_addr_get.H>      // get_mds_i2c_addr

trace_desc_t* g_trac_fapiwrap;
TRAC_INIT(&g_trac_fapiwrap, FAPIWRAP_COMP_NAME, 6*KILOBYTE, TRACE::BUFFER_SLOW);


namespace FAPIWRAP
{
    // explorer_getidec
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

    /**
     * @brief Determines if given OCMB target is a Gemini chip or not.
     *
     * @param[in]  i_ocmbChip - The OCMB target to examine
     *
     * @pre The target supplied is indeed an OCMB target.  This method will not verify.
     *
     * @return true if OCMB target is a Gemini chip, false otherwise
     */

    bool isGeminiChip(const TARGETING::Target &i_ocmbChip)
    {
        return (i_ocmbChip.getAttr< TARGETING::ATTR_CHIP_ID>() == POWER_CHIPID::GEMINI_16);
    }

    /**
     * @brief This function retrieves the DDR4 SPD data from the given OCMB target
     *
     * @param[in]  i_ocmbChip - The OCMB target to retrieve the DDR4 SPD data from
     * @param[out] o_spdDataBuffer - Buffer to contain the SPD data if retrieved
     * @param[in]  i_spdDataBufferSize - Size of the buffer of the SPD data
     *
     * @pre The target supplied is indeed an OCMB target.  This method will not verify.
     *
     * @return errlHndl_t - nullptr if no error, otherwise contains error
     */
    errlHndl_t get_ddr4_spd_data( TARGETING::Target *i_ocmbChip,
                                            uint8_t *o_spdDataBuffer,
                                             size_t  i_spdDataBufferSize )
    {
        errlHndl_t l_errl(nullptr);

        do{
            l_errl = deviceRead( i_ocmbChip,
                                 static_cast<void*>(o_spdDataBuffer),
                                 i_spdDataBufferSize,
                                 DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD_WITHOUT_EFD) );

            if (l_errl)
            {
                TRACFCOMP( g_trac_fapiwrap, ERR_MRK"get_ddr4_spd_data() "
                            "Error reading SPD associated with OCMB 0x%.08X",
                            TARGETING::get_huid(i_ocmbChip));
                break;
            }
        } while(0);

        return l_errl;
    } // get_ddr4_spd_data

    // get_pmic_dev_addr
    errlHndl_t get_pmic_dev_addr( TARGETING::Target * i_ocmbChip,
                                  const uint8_t i_pmic_id,
                                  uint8_t& o_pmic_devAddr)
    {
        errlHndl_t l_errl(nullptr);

        // Default the out going parameter, o_pmic_devAddr, to NO_DEV_ADDR
        o_pmic_devAddr = NO_DEV_ADDR;

        do{
            if (isGeminiChip(*i_ocmbChip))
            {
                TRACFCOMP( g_trac_fapiwrap, ERR_MRK"get_pmic_dev_addr() "
                           "OCMB target 0x%.8X is a Gemini Chip. No PMICs associated "
                           "with the Gemini Chip therefore device address not "
                           "retrieved for PMIC ID %d",
                           TARGETING::get_huid(i_ocmbChip), i_pmic_id );
                break;
            }

            size_t  l_spdSize(SPD::DDIMM_DDR4_SPD_SIZE);
            uint8_t l_spdBlob[l_spdSize];
            l_errl = get_ddr4_spd_data(i_ocmbChip, l_spdBlob, l_spdSize);

            if (l_errl)
            {
                TRACFCOMP( g_trac_fapiwrap, ERR_MRK"get_pmic_dev_addr() "
                           "Call to get_ddr4_spd_data failed for OCMB target 0x%.8X, "
                           "device address not retrieved for PMIC ID %d",
                           TARGETING::get_huid(i_ocmbChip), i_pmic_id );
                break;
            }

            o_pmic_devAddr = get_pmic_i2c_addr(
                                   reinterpret_cast<char *>(l_spdBlob),
                                   i_pmic_id);
        }while(0);
        return l_errl;
    } // get_pmic_dev_addr

    // get_mds_dev_addr
    errlHndl_t get_mds_dev_addr( TARGETING::Target *i_ocmbChip,
                                 uint8_t& o_mds_devAddr)
    {
        errlHndl_t l_errl(nullptr);

        // Default the out going parameter, o_mds_devAddr, to NO_DEV_ADDR
        o_mds_devAddr = NO_DEV_ADDR;

        do
        {
            if (isGeminiChip(*i_ocmbChip))
            {
                TRACFCOMP( g_trac_fapiwrap, ERR_MRK"get_mds_dev_addr() "
                           "OCMB target 0x%.8X is a Gemini Chip. No MDSs associated "
                           "with the Gemini Chip therefore device address not "
                           "retrieved for target",
                           TARGETING::get_huid(i_ocmbChip) );
                break;
            }

            size_t  l_spdSize(SPD::DDIMM_DDR4_SPD_SIZE);
            uint8_t l_spdBlob[l_spdSize];
            l_errl = get_ddr4_spd_data(i_ocmbChip, l_spdBlob, l_spdSize);

            if (l_errl)
            {
                TRACFCOMP( g_trac_fapiwrap, ERR_MRK"get_mds_dev_addr() "
                           "Call to get_ddr4_spd_data failed for OCMB target 0x%.8X, "
                           "device address not retrieved for target.",
                           TARGETING::get_huid(i_ocmbChip) );
                break;
            }

            o_mds_devAddr = get_mds_i2c_addr(reinterpret_cast<char *>(l_spdBlob));
        } while(0);
        return l_errl;
    } // get_mds_dev_addr


    // get_gpio_adc_dev_addr
    errlHndl_t get_gpio_adc_dev_addr(TARGETING::Target *i_ocmbChip,
                                     const uint8_t i_rel_pos,
                                     uint8_t& o_devAddr)
    {
        errlHndl_t l_errl = nullptr;

        do{
            if (isGeminiChip(*i_ocmbChip))
            {
                TRACFCOMP( g_trac_fapiwrap, ERR_MRK"get_gpio_dev_addr() "
                           "OCMB target 0x%.8X is a Gemini Chip. No GPIOs associated "
                           "with the Gemini Chip therefore device address not "
                           "retrieved for target",
                           TARGETING::get_huid(i_ocmbChip) );
                break;
            }

            size_t  l_spdSize(SPD::DDIMM_DDR4_SPD_SIZE);
            uint8_t l_spdBlob[l_spdSize];
            l_errl = get_ddr4_spd_data(i_ocmbChip, l_spdBlob, l_spdSize);

            if (l_errl)
            {
                TRACFCOMP( g_trac_fapiwrap, ERR_MRK"get_mds_dev_addr() "
                           "Call to get_ddr4_spd_data failed for OCMB target 0x%.8X, "
                           "device address not retrieved for target.",
                           TARGETING::get_huid(i_ocmbChip) );
                break;
            }

            o_devAddr = get_gpio_adc_i2c_addr(l_spdBlob, i_rel_pos);

        }while(0);
        return l_errl;
    }


}
