/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/bios_attr_accessors/bios_attr_parsers.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/** @file  bios_attr_parsers.H
 *  @brief This file contains the declarations of the functions that
 *         lookup a PLDM BIOS attribute using one of the APIs defined
 *         in hb_bios_attrs.H. These functions will use the value returned
 *         to set the appropriate attribute(s) on the appropriate target(s).
 *
 *  @note  All APIs definied in this header should have the same parameters.
 *         These functions are intended to be all called in host_set_ipl_parms.C
 */

// System Includes
#include <stdint.h>
#include <vector>

// Forward Declarations
namespace ISTEP_ERROR
{
class IStepError;
}

namespace ISTEP
{

/**
 * @brief Retrieve PROC_FAVOR_AGGRESSIVE_PREFETCH from the BMC BIOS and set the system
 *        attribute ATTR_PROC_FAVOR_AGGRESSIVE_PREFETCH to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H.
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H.
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_proc_favor_aggressive_prefetch(std::vector<uint8_t>& io_string_table,
                                    std::vector<uint8_t>& io_attr_table,
                                    ISTEP_ERROR::IStepError & io_stepError);
/**
 * @brief Retrieve the Lateral Cast Out (LCO) mode from the BMC BIOS and set the system
 *        attribute ATTR_PROC_LCO_MODE_DISABLE to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H.
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H.
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_lateral_cast_out_mode(std::vector<uint8_t>& io_string_table,
                                    std::vector<uint8_t>& io_attr_table,
                                    ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Retrieve the TPM Required Policy from the BMC BIOS and set the system
 *        attribute ATTR_TPM_REQUIRED to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H.
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H.
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_tpm_required(std::vector<uint8_t>& io_string_table,
                           std::vector<uint8_t>& io_attr_table,
                           ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Retrieve the Field Core Override (FCO) from the BMC BIOS and set the system's
 *        nodes attribute ATTR_FIELD_CORE_OVERRIDE to the retrieved value,
 *        if no error occurred. If an error occurs retrieving the BMC BIOS, then the
 *        attribute, for the individual NODE targets, is left as is.
 *
 * @note Changing the attribute ATTR_FIELD_CORE_OVERRIDE to all existing nodes and not
 *       just functional nodes because discover targets has not been run yet.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H.
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H.
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_field_core_override(std::vector<uint8_t>& io_string_table,
                                  std::vector<uint8_t>& io_attr_table,
                                  ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Retrieve the Mirror Memory State from the BMC BIOS and set the system
 *        attribute ATTR_PAYLOAD_IN_MIRROR_MEM to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table  See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table    See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError     If an error occurs which require a TI it can be attached
 *                                 to this IstepError log.
 * @return void
 */
void parse_hb_memory_mirror_mode(std::vector<uint8_t>& io_string_table,
                                 std::vector<uint8_t>& io_attr_table,
                                 ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Retrieve the Key Clear Request from the BMC BIOS and set the all the nodes'
 *        attribute ATTR_KEY_CLEAR_REQUEST to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS attribute, then the hostboot attribute
 *        is set to KEY_CLEAR_REQUEST_NONE.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_key_clear_request(std::vector<uint8_t>& io_string_table,
                                std::vector<uint8_t>& io_attr_table,
                                ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Lookup hb_number_huge_pages and set the system attribute ATTR_HUGE_PAGE_COUNT
 *        accordingly. If there is an error looking up the BIOS attribute, default
 *        ATTR_HUGE_PAGE_COUNT to 0.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_number_huge_pages(std::vector<uint8_t>& io_string_table,
                                std::vector<uint8_t>& io_attr_table,
                                ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Lookup hb_huge_page_size and set the system attribute ATTR_HUGE_PAGE_SIZE
 *        accordingly. If there is an error looking up the BIOS attribute, default
 *        ATTR_HUGE_PAGE_SIZE to 16 GB.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_huge_page_size(std::vector<uint8_t>& io_string_table,
                             std::vector<uint8_t>& io_attr_table,
                             ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Lookup hb_memory_region_size and set the system attribute ATTR_LMB_SIZE
 *        accordingly. If there is an error looking up the BIOS attribute, default
 *        ATTR_LMB_SIZE to 256 MB.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_memory_region_size(std::vector<uint8_t>& io_string_table,
                                 std::vector<uint8_t>& io_attr_table,
                                 ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Lookup hb_mfg_flags and set the system attribute ATTR_MFG_FLAGS
 *        accordingly. If there is an error looking up the BIOS attribute, default
 *        ATTR_MFG_FLAGS to 0.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_mfg_flags(std::vector<uint8_t>& io_string_table,
                        std::vector<uint8_t>& io_attr_table,
                        ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Lookup hb_hyp_switch and set the system attribute ATTR_PAYLOAD_KIND
 *        accordingly. If there is an error looking up the BIOS attribute, create
 *        an error log and attach it to io_stepError to trigger a TI at the end of
 *        this istep.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_hyp_switch(std::vector<uint8_t>& io_string_table,
                         std::vector<uint8_t>& io_attr_table,
                         ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Lookup pvm_fw_boot_side and set the system attribute ATTR_HYPERVISOR_IPL_SIDE
 *        accordingly. If there is an error looking up the BIOS attribute, create
 *        an error log and attach it to io_stepError to trigger a TI at the end of
 *        this istep.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_pvm_fw_boot_side(std::vector<uint8_t>& io_string_table,
                            std::vector<uint8_t>& io_attr_table,
                            ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Retrieve the USB Enablement from the BMC BIOS and set the system
 *        attribute ATTR_USB_SECURITY to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_host_usb_enablement(std::vector<uint8_t>& io_string_table,
                                  std::vector<uint8_t>& io_attr_table,
                                  ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Retrieve the Enlarged Capacity from the BMC BIOS and set the system
 *        attribute ATTR_ENLARGED_IO_SLOT_COUNT to the retrieved value, if no error occurred.
 *        If an error occurs retrieving the BMC BIOS, then the attribute is left as is.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which require a TI it can be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_ioadapter_enlarged_capacity(std::vector<uint8_t>& io_string_table,
                                          std::vector<uint8_t>& io_attr_table,
                                          ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Retrieve the Inhibit BMC Reset BIOS attribute and set the system
 *        attribute ATTR_HYP_INHIBIT_RUNTIME_BMC_RESET to the retrieved value if no
 *        error occurred.  If an error occurs retrieving the BMC BIOS, then the
 *        attribute is set to not inhibit resets.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which requires a TI, it will be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_inhibit_bmc_reset(std::vector<uint8_t>& io_string_table,
                                std::vector<uint8_t>& io_attr_table,
                                ISTEP_ERROR::IStepError & io_stepError);

/**
 * @brief Retrieve the HB_CAP_FREQ_MHZ BIOS attribute and set the system
 *        attribute ATTR_CAP_FREQ_MHZ to the retrieved value if no
 *        error occurred.  If an error occurs retrieving the BMC BIOS, then the
 *        attribute is set to 0.
 *
 * @param[in,out] io_string_table   See brief in file hb_bios_attrs.H
 * @param[in,out] io_attr_table     See brief in file hb_bios_attrs.H
 * @param[in,out] io_stepError      If an error occurs which requires a TI, it will be attached
 *                                  to this IstepError log.
 * @return void
 */
void parse_hb_cap_freq_mhz(std::vector<uint8_t>& io_string_table,
                           std::vector<uint8_t>& io_attr_table,
                           ISTEP_ERROR::IStepError & io_stepError);
}
