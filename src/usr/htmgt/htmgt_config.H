/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/tmgtutility.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef HTMGT_CONFIG_H
#define HTMGT_CONFIG_H

#include <stdint.h>

namespace HTMGT
{

    extern const uint8_t NUM_CFG_FORMATS;

    enum occCfgDataFormat
    {
        OCC_CFGDATA_NO_REQUEST     = 0x00,  // no request for config data
        OCC_CFGDATA_PSTATE_SSTRUCT = 0x01,  // Psate Super Structure
        OCC_CFGDATA_FREQ_POINT     = 0x02,  // Frequency Operating Points
        OCC_CFGDATA_OCC_ROLE       = 0x03,  // OCC Role
        OCC_CFGDATA_APSS_CONFIG    = 0x04,  // APSS Config
        OCC_CFGDATA_MEM_CONFIG     = 0x05,  // Memory Configuration
        OCC_CFGDATA_FIR_SCOMS      = 0x06,  // FIR Scoms Table
        OCC_CFGDATA_PCAP_CONFIG    = 0x07,  // PCAP Config
        OCC_CFGDATA_SYS_CONFIG     = 0x0F,  // System Configuration
        OCC_CFGDATA_MEM_THROTTLE   = 0x12,  // Memory Throttle Settings
        OCC_CFGDATA_TCT_CONFIG     = 0x13,  // Thermal Contorl Treshold

        OCC_CFGDATA_FORMAT_END,             // Marker to indicate last entry
        OCC_CFGDATA_CLEAR_ALL      = 0xFF,  // Clear All Active Config Data
    };


    enum occDataState
    {
        OCC_DATA_NOT_AVAILABLE               = 0x00,
        OCC_DATA_AVAILABLE                   = 0x01,
        OCC_DATA_NEEDS_TO_BE_SENT            = 0x02,
    };



    // Send all config data to the OCCs
    void sendOccConfigData();



} // end namespace

#endif
