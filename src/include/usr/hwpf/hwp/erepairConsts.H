/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/erepairConsts.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: erepairConsts.H,v 1.3 2014/04/29 11:59:35 bilicon Exp $
/**
 *  @file eRepairConsts.H
 *
 *  @brief eRepair Constants
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     09/14/2012  Created.
 */

#ifndef EREPAIRCONSTS_H_
#define EREPAIRCONSTS_H_


/******************************************************************************
 * Erepair constants
 *****************************************************************************/

namespace EREPAIR
{

const uint8_t INVALID_FAIL_LANE_NUMBER = 0xFF;

// X-Bus is 78+2 lanes wide in 8 byte mode
// X-Bus is 44+2 lanes wide in 4 byte mode
// Data lanes numbering:  0 - 77 in 8 byte mode
// Spare lanes numbering: 78, 79 in 8 byte mode
// Data lanes numbering:  0 - 43 in 4 byte mode
// Spare lanes numbering: 44, 45 in 8 byte mode
const uint8_t XBUS_8_ACTIVE_LANE_START   = 0;
const uint8_t XBUS_8_ACTIVE_LANE_END     = 77;

const uint8_t XBUS_4_ACTIVE_LANE_START   = 0;
const uint8_t XBUS_4_ACTIVE_LANE_END     = 43;

const uint8_t XBUS_SPARE_DEPLOY_LANE_1   = 0;
const uint8_t XBUS_SPARE_DEPLOY_LANE_2   = 1;
const uint8_t XBUS_MAXSPARES_IN_HW       = 2;

// A-Bus is 21+1 lanes wide.
// Data lanes numbering: 0 - 20
// Spare lane numbering: 21
const uint8_t ABUS_ACTIVE_LANE_START     = 0;
const uint8_t ABUS_ACTIVE_LANE_END       = 20;

const uint8_t ABUS_SPARE_DEPLOY_LANE_1   = 0;
const uint8_t ABUS_MAXSPARES_IN_HW       = 1;

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

const uint32_t EREPAIR_P8_MODULE_VPD_FIELD_SIZE       = 0x154; // 340 bytes
const uint32_t EREPAIR_P8_MODULE_VPD_MNFG_SIZE        = 0xC4;  // 196 bytes
const uint32_t EREPAIR_MEM_FIELD_VPD_SIZE_PER_CENTAUR = 0x1C;  // 28 bytes
const uint32_t EREPAIR_MEM_MNFG_VPD_SIZE_PER_CENTAUR  = 0x14;  // 20 bytes

enum busType
{
    UNKNOWN_BUS_TYPE = 0,
    PROCESSOR_EI4            = 1,
    PROCESSOR_EDI            = 2,
    MEMORY_EDI               = 3
};

enum interfaceType
{
    UNKNOWN_INT_TYPE         = 0,
    PBUS_DRIVER              = 1,  // X-Bus, A-Bus transmit
    PBUS_RECEIVER            = 2,  // X-Bus, A-Bus receive
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
       uint8_t eye3;
   }eyeCatcher;

   uint8_t  numRecords;
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
   eRepairProcDevInfo device;     // Device info of P8
   uint8_t type      :4;          // Range:0x0-0xF. Value:PROCESSOR_EI4,
                                  //                      PROCESSOR_EDI
   uint8_t interface :4;          // Range:0x0-0xF. Value:PBUS_DRIVER,
                                  //                      PBUS_RECEIVER
   uint8_t failBit;               // Range:0x00-0xFF. Value:Failing lane number
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
   eRepairMemDevInfo device;        // Device info of P8 and Centaur
   uint8_t             type      :4;// Range:0x0-0xF. Value:MEMORY_EDI
   uint8_t             interface :4;// Range:0x0-0xF. Value:MCS_Receive,
                                    //                      MCS_Drive,
                                    //                      memBuf_Receive,
                                    //                      memBuf_Drive
   uint8_t             failBit;     // Range:0x00-0xFF.
                                    // Value:Failing lane number:0-13 OR 0-20
                                    //       depends on DownStream or UpStream
};

#endif
