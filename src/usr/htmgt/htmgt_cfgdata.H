/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_cfgdata.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#ifndef HTMGT_CFGDATA_H
#define HTMGT_CFGDATA_H

#include <targeting/common/target.H>
#include "htmgt_occ.H"


namespace HTMGT
{

    /** OCC configuration data message formats */
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
        OCC_CFGDATA_TCT_CONFIG     = 0x13,  // Thermal Control Treshold

        OCC_CFGDATA_FORMAT_END,             // Marker to indicate last entry
        OCC_CFGDATA_CLEAR_ALL      = 0xFF,  // Clear All Active Config Data
    };


    enum  // constants
    {
        //KVM mode + single node
        OCC_CFGDATA_OPENPOWER_SYSTEMTYPE = 0x81,

        CFGDATA_CORES = 12,

        CFGDATA_FRU_TYPE_PROC   = 0x00,
        CFGDATA_FRU_TYPE_MEMBUF = 0x01,
        CFGDATA_FRU_TYPE_DIMM   = 0x02,

        CFDATA_DVFS_NOT_DEFINED = 0xFF,
    };


    enum cfgTargets
    {
        TARGET_ALL    = 0x00,
        TARGET_MASTER = 0x01,
    };

    enum cfgSupStates
    {
        CFGSTATE_ALL     = 0x00,
        CFGSTATE_STANDBY = 0x01,
        CFGSTATE_SBYOBS  = 0x02
    };

    const uint32_t TO_20SEC = 20;

    struct occCfgDataTable_t
    {
        occCfgDataFormat    format;
        cfgTargets          targets;
        uint16_t            timeout; // in seconds
        cfgSupStates        supportedStates;

        bool operator==(const occCfgDataFormat& i_format) const
        {
            return (i_format == format);
        }
    };

    const occCfgDataTable_t occCfgDataTable[] =
    {
        { OCC_CFGDATA_SYS_CONFIG,     TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_APSS_CONFIG,    TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_OCC_ROLE,       TARGET_ALL,  TO_20SEC, CFGSTATE_STANDBY },
        { OCC_CFGDATA_PSTATE_SSTRUCT, TARGET_ALL,  TO_20SEC, CFGSTATE_SBYOBS },
        { OCC_CFGDATA_FREQ_POINT,     TARGET_MASTER, TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_MEM_CONFIG,     TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_PCAP_CONFIG,    TARGET_MASTER, TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_MEM_THROTTLE,   TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_TCT_CONFIG,     TARGET_ALL,    TO_20SEC, CFGSTATE_ALL }
    };
    const size_t OCC_CONFIG_TABLE_SIZE = sizeof(occCfgDataTable) /
        sizeof(occCfgDataTable_t);

    /**
     * @brief Send config format data to all OCCs
     *
     * @param[in]  config format to send.  Default is to send
     *             all config formats.
     */
    void sendOccConfigData(const occCfgDataFormat i_requestedFormat =
                           OCC_CFGDATA_CLEAR_ALL);

    /**
     * Fills in the Memory Config Configuration Data message buffer,
     * including the format and version numbers.
     *
     * @param[in] i_occ - the OCC to gather data for
     * @param[in] i_monitoringEnabled - set it to true if mem monitoring on
     * @param[out] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getMemConfigMessageData(const TARGETING::TargetHandle_t i_occ,
                                 bool i_monitoringEnabled,
                                 uint8_t* o_data, uint64_t & o_size);


    /**
     * Fills in the Memory Throttle Configuration Data message buffer,
     * including the format and version numbers.
     *
     * @param[in] i_occ - the OCC to gather data for
     * @param[in] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getMemThrottleMessageData(const TARGETING::TargetHandle_t i_occ,
                                   uint8_t* o_data, uint64_t & o_size);


    /**
     * Fills in the OCC Role Configuration Data message buffer.
     *
     * @param[in] i_master - if this is for the OCC master
     * @param[in] i_firMaster - if this is for the OCC FIR master
     * @param[out] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getOCCRoleMessageData(bool i_master, bool i_firMaster,
                               uint8_t* o_data, uint64_t & o_size);


    /**
     * Fills in the Power Cap Configuration Data message buffer.
     *
     * @param[out] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getPowerCapMessageData(uint8_t* o_data, uint64_t & o_size);


    /**
     * Fills in the System Config Configuration Data message buffer.
     *
     * @param[in]  i_occ  - the OCC target
     * @param[out] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getSystemConfigMessageData(const TARGETING::TargetHandle_t i_occ,
                                    uint8_t* o_data, uint64_t & o_size);


    /**
     * Fills in the Thermal Control Thresholds Configuration
     * Data message buffer.
     *
     * @param[out] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getThermalControlMessageData(uint8_t* o_data, uint64_t & o_size);


    /**
     * Fill in the Frequency Point Configuration Data
     * message buffer.
     *
     * @param[out] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getFrequencyPointMessageData(uint8_t* o_data,
                                      uint64_t & o_size);

    /**
     * Read pstate data from attribute and build occcmd message
     * @param[in] The OCC TARGETING::Target
     * @param[out] The occ cmd message
     * @param[in/out] In: Byte size of the o_data area. Out: Byte size of
     *                the occ cmd message.
     */
    void getPstateTableMessageData(const TARGETING::TargetHandle_t i_occTarget,
                                   uint8_t* o_data,
                                   uint64_t & io_size);

    /**
     * Generate the APSS configuration message
     * @param[out] The APSS cfg message
     * @param[in/out] In: Byte size of the o_data area. Out: Byte size of
     *                the occ cmd message
     */
    void getApssMessageData(uint8_t* o_data,
                            uint64_t & o_size);

};
#endif
