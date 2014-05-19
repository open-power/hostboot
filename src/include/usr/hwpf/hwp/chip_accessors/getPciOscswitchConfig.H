/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/chip_accessors/getPciOscswitchConfig.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: getPciOscswitchConfig.H,v 1.2 2014/01/15 20:03:21 whs Exp $
/**
 *  @file getPciOscswitchConfig.H
 *
 *  @brief Accessor for providing the ATTR_PCI_OSCSWITCH_CONFIG attribute
 */

#ifndef _HWP_GETPCIOSCSWITCHCONFIG_
#define _HWP_GETPCIOSCSWITCHCONFIG_

#include <fapi.H>

// configuration values
enum PciOscswitchConfigValues
{
    MURANO_DD1X = 0x03,
    MURANO_DD2X = 0x0C,
    VENICE_P0P2 = 0x09, // position 0 and 2
    VENICE_P1P3 = 0x06, // position 1 and 3
};

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getPciOscswitchConfig_FP_t)
    (const fapi::Target &, uint8_t &);

extern "C"
{
/**
 * @brief Get the ATTR_PCI_OSCSWITCH_CONFIG FAPI attribute
 *
 * @param[in]  i_procTarget - Reference to processor chip target
 * @param[out] o_val        - Filled in with pci oscswitch config
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getPciOscswitchConfig(
    const fapi::Target & i_procTarget,
    uint8_t & o_val);
}

#endif
