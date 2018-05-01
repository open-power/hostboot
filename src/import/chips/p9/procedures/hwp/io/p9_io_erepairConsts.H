/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_erepairConsts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
///
/// @file p9_io_erepairConsts.H
/// @brief eRepair Constants
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------

#ifndef P9_IO_EREPAIRCONSTS_H_
#define P9_IO_EREPAIRCONSTS_H_

/******************************************************************************
 * Erepair constants
 *****************************************************************************/

namespace EREPAIR
{
const uint8_t INVALID_FAIL_LANE_NUMBER = 0;

// X-Bus is 16+1 lanes wide in 2 byte mode
// Data lanes numbering:  0 - 15 in 2 byte mode
// Spare lanes numbering: 16     in 2 byte mode
const uint8_t XBUS_2_ACTIVE_LANE_START   = 0;
const uint8_t XBUS_2_ACTIVE_LANE_END     = 15;

const uint8_t XBUS_SPARE_DEPLOY_LANE_1   = 0;
const uint8_t XBUS_MAXSPARES_IN_HW       = 1;
const uint8_t XBUS_MAX_LANE_WIDTH        = 16;

// O-Bus is 12+2 lanes wide.
// Data lanes numbering: 0 - 11
// Spare lane numbering: 12,13
const uint8_t OBUS_ACTIVE_LANE_START     = 0;
const uint8_t OBUS_ACTIVE_LANE_END       = 11;

const uint8_t OBUS_SPARE_DEPLOY_LANE_1   = 0;
const uint8_t OBUS_SPARE_DEPLOY_LANE_2   = 1;
const uint8_t OBUS_MAXSPARES_IN_HW       = 2;
const uint8_t OBUS_MAX_LANE_WIDTH        = 12;

// UpStream DMI-Bus is 21+2 lanes wide.
// Data lanes numbering:  0 - 20
// Spare lanes numbering: 21, 22
const uint8_t DMIBUS_UPSTREAM_ACTIVE_LANE_START   = 0;
const uint8_t DMIBUS_UPSTREAM_ACTIVE_LANE_END     = 20;

// DownStream DMI-Bus is 14+2 lanes wide.
// Data lanes numbering:  0 - 13
// Spare lanes numbering: 14, 15
const uint8_t DMIBUS_DOWNSTREAM_ACTIVE_LANE_START = 0;
const uint8_t DMIBUS_DOWNSTREAM_ACTIVE_LANE_END   = 13;

const uint8_t DMIBUS_SPARE_DEPLOY_LANE_1          = 0;
const uint8_t DMIBUS_SPARE_DEPLOY_LANE_2          = 1;
const uint8_t DMIBUS_MAXSPARES_IN_HW              = 2;
const uint8_t DMIBUS_UPSTREAM_MAX_LANE_WIDTH      = 21;
const uint8_t DMIBUS_DNSTREAM_MAX_LANE_WIDTH      = 14;

const uint32_t EREPAIR_P9_MODULE_VPD_FIELD_SIZE       = 0x10E; // 270 bytes
const uint32_t EREPAIR_P9_MODULE_VPD_MNFG_SIZE        = 0x10E; // 270 bytes
const uint32_t EREPAIR_MEM_FIELD_VPD_SIZE_PER_CENTAUR = 0x36;  // 54 bytes
const uint32_t EREPAIR_MEM_MNFG_VPD_SIZE_PER_CENTAUR  = 0x36;  // 54 bytes

//TODO:
enum busType
{
    UNKNOWN_BUS_TYPE = 0,
    PROCESSOR_OPT            = 1,
    PROCESSOR_EDIP           = 2,
    MEMORY_EDIP              = 3
};

enum interfaceType
{
    UNKNOWN_INT_TYPE         = 0,
    PBUS_DRIVER              = 1,  // X-Bus, O-Bus transmit
    PBUS_RECEIVER            = 2,  // X-Bus, O-Bus receive
    DMI_MCS_RECEIVE          = 3,  // MCS receive
    DMI_MCS_DRIVE            = 4,  // MCS transmit
    DMI_MEMBUF_RECEIVE       = 5,  // Centaur receive
    DMI_MEMBUF_DRIVE         = 6,  // Centaur transmit
    DRIVE                    = 7,  // Tx
    RECEIVE                  = 8   // Rx
};

// VPD Type to read-write
enum erepairVpdType
{
    EREPAIR_VPD_UNKNOWN = 0,
    EREPAIR_VPD_MNFG    = 1,
    EREPAIR_VPD_FIELD   = 2,
};

}// end of EREPAIR namespace

/******************************************************************************
 * VPD Structures.
 *****************************************************************************/

// eRepair Header
struct eRepairHeader
{
    struct
    {
        uint8_t eye1;
        uint8_t eye2;
    } eyeCatcher;

    uint8_t version;
    uint8_t sizeOfRecord;
    uint8_t maxNumRecord;
    uint8_t availNumRecord;
};

// Device info structure of the P8 Processor
struct eRepairProcDevInfo
{
    uint8_t processor_id;// Range:0x00-0xFF. Value:Processor MRU IDs
    uint8_t fabricBus;   // Range:0x00-0xFF. Value: FabricBus(ATTR_CHIP_UNIT_POS)
};

// eRepair structure for failing lanes on Power Bus
struct eRepairPowerBus
{
    eRepairProcDevInfo device;     // Device info of P9
    uint8_t type      : 4;         // Range:0x0-0xF. Value:PROCESSOR_EDIP
    uint8_t interface : 4;         // Range:0x0-0xF. Value:[PBUS_DRIVER|PBUS_RECEIVER]
    uint32_t failBit : 24;         // Bit stream value: Bit 0:Lane 0; Bit 1:Lane 1 ...
};


// Device info structure of the endpoints of the Memory Channel
struct eRepairMemDevInfo
{
    uint8_t proc_centaur_id;// Range:0x00-0xFF.Value:Processor or Centaur MRU ID
    uint8_t memChannel;   // Range:0x00-0xFF.Value: MemoryBus(ATTR_CHIP_UNIT_POS)
};

// eRepair structure of failing lanes on Memory Channel
struct eRepairMemBus
{
    eRepairMemDevInfo device;          // Device info of P9 and Centaur
    uint8_t             type      : 4; // Range:0x0-0xF. Value:MEMORY_EDIP
    uint8_t             interface : 4; // Range:0x0-0xF. Value:[MCS_Receive|MCS_Drive|memBuf_Receive|memBuf_Drive]
    uint32_t            failBit  : 24; // Bit stream value: Bit 0:Lane 0; Bit 1:Lane 1 ...
};

/**
 * @brief This function combines the eRepair lane numbers read from
 *        Manufacturing VPD and Field VPD
 *
 * @param [in]  i_mnfgFaillanes  The eRepair lane numbers read from the
 *                               Manufacturing VPD
 * @param [in]  i_fieldFaillanes The eRepair lane numbers read from the
 *                               Field VPD
 * @param [out] o_allFaillanes   The eRepair lane numbers which is the union
 *                               of the Field and Manufacturing eRepair lanes
 *                               passed as first iand second params
 *
 * @return void
 */
void combineFieldandMnfgLanes(std::vector<uint8_t>& i_mnfgFaillanes,
                              std::vector<uint8_t>& i_fieldFaillanes,
                              std::vector<uint8_t>& o_allFailLanes);


/**
 * @brief This function checks to see if the passed vectors have matching
 *        fail lane numbers. If no matching lane number is found, such lane
 *        value will be invalidated in the vector
 *
 * @param [in]  io_endp1_txFaillanes        Reference to vector which has fail
 *                                          lane numbers of Tx side
 * @param [in]  io_endp2_rxFaillanes        Reference to vector which has fail
 *                                          lane numbers of Rx side
 * @param [out] o_invalidFails_inTx_Ofendp1 If TRUE, indicates that Tx has fail
 *                                          lane numbers for which there is no
 *                                          matching entry on Rx side
 * @param [out] o_invalidFails_inRx_Ofendp2 If TRUE, indicates that Tx has fail
 *                                          lane numbers for which there is no
 *                                          matching entry on Tx side
 *
 * @return void
 */
void invalidateNonMatchingFailLanes(std::vector<uint8_t>& io_endp1_txFaillanes,
                                    std::vector<uint8_t>& io_endp2_rxFaillanes,
                                    bool& o_invalidFails_inTx_Ofendp1,
                                    bool& o_invalidFails_inRx_Ofendp2);

#endif
