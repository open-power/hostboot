/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/base/hb_bios_attrs.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#ifndef HB_BIOS_ATTRS_H
#define HB_BIOS_ATTRS_H

/** @file  hb_bios_attrs.H
 *  @brief This file contains the declarations of the functions that
 *         are used to get the current value of the PLDM BIOS attributes from
 *         the BMC. These interfaces should translate the PLDM attribute value
 *         into a type suitable for hostboot's use as an output parameter.
 *
 *  All interfaces should provide the following input/output parameters:
 *  param[in,out] io_string_table  A byte vector that if empty will be filled
 *                                 with the string table via a PLDM Bios Table
 *                                 request to the BMC. If it already has contents
 *                                 no request will be made and vector will not
 *                                 be modified.
 *
 *  param[in,out] io_attr_table   A byte vector that if empty will be filled
 *                                with the attribute table via a PLDM Bios Table
 *                                request to the BMC. If it already has contents
 *                                no request will be made and vector will not
 *                                be modified.
 *
 * NOTE: These parameters are required for all functions since the caller can reuse them amongst multiple function calls
 *       into this API to save on lookups which should be avoided as much as possible. By passing in the already filled
 *       vectors the underlying code skips the lookups entirely. Otherwise, the code is forced to do the lookup.
 **/

#include <openbmc/pldm/libpldm/bios_table.h>
#include <attributetraits.H>
#include <attributeenums.H>

namespace PLDM
{
    constexpr uint8_t LMB_SIZE_ENCODE_128MB = 0x3;
    constexpr uint8_t LMB_SIZE_ENCODE_256MB = 0x4;

    /** @brief Retrieve the current value of the hb_hyp_switch
    *          PLDM bios attribute and return the value converted
    *          to a ATTR_PAYLOAD_KIND enum.
    *
    * @param[in,out] io_string_table  See brief at the top of this file.
    * @param[in,out] io_attr_table    See brief at the top of this file.
    * @param[out]    o_payloadType    If no error occurred will contain the value
    *                                 found for hb_hyp_switch translated to
    *                                 terms of ATTR_PAYLOAD_KIND_type.
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getHypervisorMode(std::vector<uint8_t>& io_string_table,
                                 std::vector<uint8_t>& io_attr_table,
                                 TARGETING::ATTR_PAYLOAD_KIND_type &o_payloadType);

    /** @brief Retrieve the current value of the hb_number_huge_pages
    *          PLDM bios attribute and return the value converted
    *          to a ATTR_HUGE_PAGE_COUNT_type.
    *
    * @param[in,out] io_string_table  See brief at the top of this file.
    * @param[in,out] io_attr_table    See brief at the top of this file.
    * @param[out]    o_hugePageCount  If no error occurred will contain the value
    *                                 found for hb_number_huge_pages translated
    *                                 to terms of ATTR_HUGE_PAGE_COUNT_type.
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getHugePageCount(std::vector<uint8_t>& io_string_table,
                                std::vector<uint8_t>& io_attr_table,
                                TARGETING::ATTR_HUGE_PAGE_COUNT_type &o_hugePageCount);

   /** @brief Retrieve the current value of the hb_usb_security
    *          PLDM bios attribute and return the value converted
    *          to a ATTR_USB_SECURITY_type.
    *
    * @param[in,out] io_string_table  See brief at the top of this file.
    * @param[in,out] io_attr_table    See brief at the top of this file.
    * @param[out]    o_usb_security   If no error occurs will contain the value
    *                                 for hb_usb_security translated
    *                                 to terms of ATTR_USB_SECURITY_type.
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getUsbSecurity(std::vector<uint8_t>& io_string_table,
                              std::vector<uint8_t>& io_attr_table,
                              TARGETING::ATTR_USB_SECURITY_type &o_usb_security);

    /** @brief Retrieve the current value of the hb_huge_page_size
    *          PLDM bios attribute and return the value converted
    *          to a ATTR_HUGE_PAGE_SIZE_type.
    *
    * @param[in,out] io_string_table  See brief at the top of this file.
    * @param[in,out] io_attr_table    See brief at the top of this file.
    * @param[out]    o_hugePageSize   If no error occurred will contain the value
    *                                 found for hb_huge_page_size
    *                                 translated to terms of
    *                                 ATTR_HUGE_PAGE_SIZE_type_type.
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getHugePageSize(std::vector<uint8_t>& io_string_table,
                               std::vector<uint8_t>& io_attr_table,
                               TARGETING::ATTR_HUGE_PAGE_SIZE_type &o_hugePageSize);

    /** @brief Retrieve the current value of the hb_memory_region_size
    *          PLDM bios attribute and return the value converted
    *          to a ATTR_LMB_SIZE_type.
    *
    * @param[in,out] io_string_table  See brief at the top of this file.
    * @param[in,out] io_attr_table    See brief at the top of this file.
    * @param[out]    o_lmbSize        If no error occurred will contain the value
    *                                 found for hb_memory_region_size translated
    *                                 to terms of ATTR_LMB_SIZE_type.
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getLmbSize(std::vector<uint8_t>& io_string_table,
                          std::vector<uint8_t>& io_attr_table,
                          TARGETING::ATTR_LMB_SIZE_type &o_lmbSize);

    /** @brief Retrieve the Field Core Override (FCO) from the BMC bios
    *
    * @details This method retrieves the FCO from the BMC bios via the PLDM interface.
    *          A FCO value of 0 is interpreted as all cores will be activated.
    *          For a fused core, a non-zero value N, is interpreted as 2N cores activated.
    *          For a non-fused core, a non-zero value N, is interpreted as N cores activated.
    *
    * @param[in,out] io_string_table   See brief at the top of this file.
    * @param[in,out] io_attr_table     See brief at the top of this file.
    * @param[out] o_fieldCoreOverride  If no error occurred then will contain the value
    *                                  of the FCO from the BMC bios.
    *                                  If error then will be zeroed out.
    *
    * @return Error if failed to retrieve the FCO, otherwise nullptr on success
    */
    errlHndl_t getFieldCoreOverride( std::vector<uint8_t>& io_string_table,
                                     std::vector<uint8_t>& io_attr_table,
                                     TARGETING::ATTR_FIELD_CORE_OVERRIDE_type &o_fieldCoreOverride);


    /** @brief Retrieve the current value of the hb_mfg_flags
    *          PLDM bios attribute from the BMC and return the value
    *          converted to a ATTR_MFG_FLAGS array attribute type.
    *
    * @param[in,out] io_string_table  See brief at the top of this file.
    * @param[in,out] io_attr_table    See brief at the top of this file.
    * @param[out]    o_mfgFlags       If no error occurred will contain the value
    *                                 found for hb_mfg_flags translated to
    *                                 terms of ATTR_MFG_FLAGS_typeStdArr.
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getMfgFlags(std::vector<uint8_t>& io_string_table,
                           std::vector<uint8_t>& io_attr_table,
                           TARGETING::ATTR_MFG_FLAGS_typeStdArr &o_mfgFlags);

    /** @brief Retrieve the current power limit PLDM bios attributes
    *          from the BMC and return to the caller.
    *
    * @param[out] o_powerLimitEnable  If no error occurs will contain the value
    *                                 we found for hb_power_limit_enable.
    * @param[out] o_powerLimitWatts   If no error occurs will contain the value
    *                                 we found for hb_power_limit_in_watts.
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getPowerLimit(bool &o_powerLimitEnable,
                             uint16_t &o_powerLimitWatts);

    /** @brief Retrieve the current value of the hb_debug_console
    *          PLDM bios attribute, convert it to a boolean value.
    *
    * @param[in,out] io_string_table  See brief at the top of this file.
    * @param[in,out] io_attr_table    See brief at the top of this file.
    * @param[out] o_debugConsoleEnabled  Will return true if "Enabled" is
    *                                    returned as the value for PLDM attr
    *
    * @return Error if any, otherwise nullptr.
    */
    errlHndl_t getDebugConsoleEnabled(std::vector<uint8_t>& io_string_table,
                                      std::vector<uint8_t>& io_attr_table,
                                      bool &o_debugConsoleEnabled);

#ifdef CONFIG_INCLUDE_XML_OPPOWERVM
    /** @brief Retrieve the current value of the pvm_fw_boot_side PLDM bios attribute and convert to hostboot
     *         ATTR_HYPERVISOR_IPL_SIDE enum.
     *
     * @param[in,out] io_string_table  See brief at the top of this file.
     * @param[in,out] io_attr_table    See brief at the top of this file.
     * @param[out]    o_bootside       If no error, then value for pvm_fw_boot_side translated to
     *                                 ATTR_HYPERVISOR_IPL_SIDE_type.
     *
     * @return        errlHndl_t       errl if an error occurs. Otherwise, nullptr.
     */
    errlHndl_t getBootside(std::vector<uint8_t>                     & io_string_table,
                           std::vector<uint8_t>                     & io_attr_table,
                           TARGETING::ATTR_HYPERVISOR_IPL_SIDE_type & o_bootside);
#endif

    /** @brief Retrieve the value of the secure version lockin enabled attribute
     *         from the BMC.
     *
     * @param[in,out] io_string_table  See brief at the top of this file.
     * @param[in,out] io_attr_table    See brief at the top of this file.
     * @param[out] o_lockinEnabled whether the secure version lockin is enabled.
     *
     * @return nullptr on success; non-nullptr on error.
     */
    errlHndl_t getSecVerLockinEnabled(std::vector<uint8_t>& io_string_table,
                                      std::vector<uint8_t>& io_attr_table,
                                      TARGETING::ATTR_SECURE_VERSION_LOCKIN_POLICY_type& o_lockinEnabled);

    /** @brief Latch all pending HB BIOS attributes into their "current" forms.
     *
     * @param[in,out] io_string_table  See brief at the top of this file.
     * @param[in,out] io_attr_table    See brief at the top of this file.
     */
    errlHndl_t latchBiosAttrs(std::vector<uint8_t>& io_string_table,
                              std::vector<uint8_t>& io_attr_table);
}

#endif
