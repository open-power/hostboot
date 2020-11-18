/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_cfgdata.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

#define MAX_GPUS 3

namespace HTMGT
{
    const uint8_t  OCC_PROC_DEFAULT_WEIGHT = 10;     //default weight (1.0)
    const uint8_t  OCC_PROC_DEFAULT_DVFS_TEMP = 0x55;//default from DEF file PM
    const uint8_t  OCC_PROC_DEFAULT_ERR_TEMP  = 0x5F;
    const uint8_t  OCC_PROC_DEFAULT_TIMEOUT   = 0x05;
    const uint8_t  OCC_DIMM_DEFAULT_DVFS_TEMP = 0x45;//default from DEF file PM
    const uint8_t  OCC_DIMM_DEFAULT_ERR_TEMP  = 0x56;
    const uint8_t  OCC_DIMM_DEFAULT_TIMEOUT   = 0x1E;
    const uint8_t  OCC_NOT_DEFINED   = 0xFF;

    /** OCC configuration data message formats */
    enum occCfgDataFormat
    {
        OCC_CFGDATA_NO_REQUEST     = 0x00,  // no request for config data
        OCC_CFGDATA_OCC_ROLE       = 0x03,  // OCC Role
        OCC_CFGDATA_APSS_CONFIG    = 0x04,  // APSS Config
        OCC_CFGDATA_MEM_CONFIG     = 0x05,  // Memory Configuration
        OCC_CFGDATA_PCAP_CONFIG    = 0x07,  // PCAP Config
        OCC_CFGDATA_SYS_CONFIG     = 0x0F,  // System Configuration
        OCC_CFGDATA_MEM_THROTTLE   = 0x12,  // Memory Throttle Settings
        OCC_CFGDATA_TCT_CONFIG     = 0x13,  // Thermal Control Treshold
        OCC_CFGDATA_AVSBUS_CONFIG  = 0x14,  // AVSBus Config
        OCC_CFGDATA_GPU_CONFIG     = 0x15,  // GPU Config

        OCC_CFGDATA_FORMAT_END,             // Marker to indicate last entry
        OCC_CFGDATA_CLEAR_ALL      = 0xFF,  // Clear All Active Config Data
    };


    enum  // constants
    {
        //KVM or OPAL mode + single node
        OCC_CFGDATA_OPENPOWER_OPALVM  = 0x81,
        // Max resets due to WOF has been reached
        OCC_CFGDATA_WOF_RESET_LIMIT   = 0x04,
        //PowerVM mode + single node
        OCC_CFGDATA_OPENPOWER_POWERVM = 0x01,

        CFGDATA_CORES = 32,

        CFGDATA_FRU_TYPE_PROC       = 0x00,
        CFGDATA_FRU_TYPE_MEMBUF     = 0x01,
        CFGDATA_FRU_TYPE_DIMM       = 0x02,
        CFGDATA_FRU_TYPE_MCDIMM     = 0x03,
        CFGDATA_FRU_TYPE_GPU_CORE   = 0x04,
        CFGDATA_FRU_TYPE_GPU_MEMORY = 0x05,
        CFGDATA_FRU_TYPE_VRM_VDD    = 0x06,
        CFDATA_DVFS_NOT_DEFINED = 0xFF,
    };

    enum // WOF disabled reasons
    {
        WOF_MISSING_ULTRA_TURBO     = 0x0000,
        WOF_SYSTEM_DISABLED         = 0x0001,
        WOF_RESET_COUNT_REACHED     = 0x0002,
        WOF_UNSUPPORTED_FREQ        = 0x0003,
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
        { OCC_CFGDATA_OCC_ROLE,       TARGET_ALL,  TO_20SEC,CFGSTATE_STANDBY },
        { OCC_CFGDATA_MEM_CONFIG,     TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_PCAP_CONFIG,    TARGET_MASTER, TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_MEM_THROTTLE,   TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_TCT_CONFIG,     TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
        { OCC_CFGDATA_AVSBUS_CONFIG,  TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
        // GPU config packet MUST be sent after APSS config
        { OCC_CFGDATA_GPU_CONFIG,     TARGET_ALL,    TO_20SEC, CFGSTATE_ALL },
    };
    const size_t OCC_CONFIG_TABLE_SIZE = sizeof(occCfgDataTable) /
        sizeof(occCfgDataTable_t);

    /**
     * @brief Send config format data to all OCCs
     *
     * @param[in]  config format to send.  Default is to send
     *             all config formats.
     * @return NULL on success, else error handle
     */
    errlHndl_t sendOccConfigData(const occCfgDataFormat i_requestedFormat =
                                 OCC_CFGDATA_CLEAR_ALL);

    /**
     * Fills in the Memory Config Configuration Data message buffer,
     * including the format and version numbers.
     *
     * @param[in] i_occ - the OCC to gather data for
     * @param[out] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getMemConfigMessageData(Occ *i_occ,
                                 uint8_t* o_data, uint64_t & o_size);


    /**
     * Fills in the Memory Throttle Configuration Data message buffer,
     * including the format and version numbers.
     *
     * @param[in] i_occ - the OCC to gather data for
     * @param[in] i_occ_instance - OCC instance number
     * @param[in] o_data - preallocated buffer to fill in
     * @param[out] o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getMemThrottleMessageData(const TARGETING::TargetHandle_t i_occ,
                                   const uint8_t i_occ_instance,
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
     * Return the maximum power cap for the system.
     *
     * Value is read from the MRW based on the Current Power Supply
     * Redundancy Policy sensor in the BMC
     *
     * @param[in]  i_sys - pointer to system target
     * @param[out] o_is_redundant - true if power supplies should be redundant
     * @returns  maximum power cap in watts
     */
    uint16_t getMaxPowerCap(TARGETING::Target *i_sys, bool & o_is_redundant);


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
    void getSystemConfigMessageData(const Occ &i_occ,
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
     * Fills in the AVSBus Configuration Data message buffer
     *
     * @param[in]   i_occ - the OCC target
     * @param[out]  o_data - preallocated buffer to fill in
     * @param[out]  o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getAVSBusConfigMessageData(const TARGETING::TargetHandle_t i_occ,
                                    uint8_t* o_data, uint64_t & o_size);

    /**
     * Fills in the GPU Configuration Data message buffer
     *
     * @param[in]   i_occ - the OCC target
     * @param[out]  o_data - preallocated buffer to fill in
     * @param[out]  o_size - set to the message size
     * @pre o_data is large enough.
     */
    void getGPUConfigMessageData(const TARGETING::TargetHandle_t i_occ,
                                 uint8_t * o_data,
                                 uint64_t & o_size);

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
     * Generate the APSS configuration message
     * @param[out] The APSS cfg message
     * @param[in/out] In: Byte size of the o_data area. Out: Byte size of
     *                the occ cmd message
     */
    void getApssMessageData(uint8_t* o_data,
                            uint64_t & o_size);

    /**
     * Determine if WOF is supported and return applicable frequencies
     * @param[out] nominal Nominal frequency in MHz
     * @param[out] turbo   Turbo frequency in MHz (0 = no support)
     * @param[out] ultra   Ultra Turbo frequency in MHz (0 = no support)
     * @return             TRUE if WOF is supported, else FALSE
     */
    bool check_wof_support(uint16_t & nominal,
                           uint16_t & turbo,
                           uint16_t & ultra);

    /**
     * Fill specified buffer with requested config format data
     * @param[in]  i_occ     OCC object that data is requested
     * @param[in]  i_format  config format being requested
     * @param[out] o_cfgDataLength   Length of data being returned
     * @param[in/out] o_cfgDataPtr   Buffer containing config data
     */
    void readConfigData(Occ * i_occ,
                        const uint8_t i_format,
                        uint16_t & o_cfgDataLength,
                        uint8_t *o_cfgDataPtr);
};
#endif
