/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapiwrap/fapiWrapif.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
#ifndef _FAPIWRAPIF_H
#define _FAPIWRAPIF_H

#include <errl/errlentry.H>  // Also gets us targeting/common/target.H


/* *** Overview ***
   There has been a trend to create more HWPs that process raw data.
   This allows Hostboot and Cronus (and other platforms to share more code.
   The trick is that we generally want to call these HWPs inside what has
   traditionally been Hostboot-only code. The fapiwrap directory will help
   encapsulate all of the calls to ekb code in one place. That way if we
   ever need to remove HWPs/EKB code it will be easier to stub out the calls.
   We have found in the past we have contaminated a lot of Hostboot-only
   code with calls to EKB code. This directory should help address that problem.
*/


namespace FAPIWRAP
{

// Global constant
    // If no device address is found for a given target then NO_DEV_ADDR will be returned
    constexpr uint8_t NO_DEV_ADDR = 0xFF;

    /**
     * @brief This function wraps around the FAPI2 HWP "exp_getidec" which
     *        takes in a OCMB target and returns the associated chipId
     *        and ec level.
     *        Chip Ids can be found in src/import/chips/common/utils/chipids.H
     * @param[in]  i_ocmbChip - Explorer OCMB target to lookup values on
     * @param[out] o_chipId   - Power Chip Id associated with this OCMB
     * @param[out] o_ec       - EC level of this chip
     * @return errlHndl_t - nullptr if no error, otherwise contains error
     */
    errlHndl_t explorer_getidec( TARGETING::Target * i_ocmbChip,
                                  uint16_t& o_chipId,
                                  uint8_t&  o_ec);

    /**
     * @brief This function wraps around the FAPI2 HWP "get_pmic_i2c_addr" which
     *        takes in a DDIMM's DDR4 SPD data and a PMIC's position relative to
     *        its parent OCMB's chip and returns the device address of that pmic
     *        This wrapper will actually lookup the SPD of a given ocmb target so
     *        the caller doesnt need to worry about it.
     * @param[in] i_ocmbChip - Parent ocmb of the PMIC we wish to find the device addres of
     * @param[in] i_pmic_id  - PMIC's position relative to parent OCMB
     * @param[out]o_pmic_devAddr - If this pmic exists on the ocmb then return the device address
     *                             found in the SPD. Otherwise return NO_DEV_ADDR
     * @return errlHndl_t - nullptr if no error, otherwise contains error
     *
     * @pre i_ocmbChip is a valid pointer to an OCMB target
     */
    errlHndl_t get_pmic_dev_addr( TARGETING::Target * i_ocmbChip,
                                  const uint8_t i_pmic_id,
                                  uint8_t& o_pmic_devAddr);

    /**
     * @brief This function wraps around the FAPI2 HWP "get_mds_i2c_addr" which
     *        takes in a DDIMM's DDR4 SPD and returns the device address for the
     *        MDS targets.
     * @param[in] i_ocmbChip - Parent ocmb of the MDS we wish to find the device addres of
     * @param[out]o_mds_devAddr - If this exists on the OCMB then return the device address
     *                            found in the SPD. Otherwise return NO_DEV_ADDR
     * @return errlHndl_t - nullptr if no error, otherwise contains error
     *
     * @pre i_ocmbChip is a valid pointer to an OCMB target
     */
    errlHndl_t get_mds_dev_addr(TARGETING::Target *i_ocmbChip,
                                          uint8_t &o_mds_devAddr);

    /**
     * @brief This function wraps around the FAPI2 HWP "get_gpio_adc_i2c_addr" which
     *        takes in the relative position of a ADC or GPIO Expansion target (relative
     *        to its parent OCMB's chip) on a 4U DDIMM and returns the i2c device address
     *        of that target.
     * @param[in]  i_rel_pos  - The ADC or GPIO Expansion's position relative to parent OCMB
     * @param[out] o_devAddr - Returns the i2c device address
     * @return errlHndl_t - nullptr if no error, otherwise contains error
     */
    errlHndl_t get_gpio_adc_dev_addr( const uint8_t i_rel_pos,
                                      uint8_t& o_devAddr);

}

#endif
