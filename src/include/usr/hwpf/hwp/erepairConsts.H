/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/erepairConsts.H $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */


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

enum busType
{
    EREPAIR_UNKNOWN_BUS_TYPE = 0,
    PROCESSOR_EI4            = 1,
    PROCESSOR_EDI            = 2,
    MEMORY_EDI               = 3
};

enum interfaceType
{
    EREPAIR_UNKNOWN_INT_TYPE = 0,
    PBUS_DRIVER              = 1,  // X-Bus, A-Bus transmit
    PBUS_RECEIVER            = 2,  // X-Bus, A-Bus receive
    DMI_MCS_RECEIVE          = 3,  // MCS receive
    DMI_MCS_DRIVE            = 4,  // MCS transmit
    DMI_MEMBUF_RECEIVE       = 5,  // Centaur receive
    DMI_MEMBUF_DRIVE         = 6   // Centaur transmit
};

}// end of EREPAIR namespace

/******************************************************************************
 * VPD Structures.
 *****************************************************************************/

// Device info structure of the P8 Processor
struct eRepairProcDevInfo
{
   uint8_t processor_id;// Range:0x00-0xFF. Value:Processor MRU IDs
   uint8_t fabricBus;   // Range:0x00-0xFF. Value:FabricBus(ATTR_CHIP_UNIT_POS)
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
   uint8_t proc_Centaur_id;// Range:0x00-0xFF.Value:Processor or Centaur MRU ID
   uint8_t memChannel;   // Range:0x00-0xFF.Value:MemoryBus(ATTR_CHIP_UNIT_POS)
};

// eRepair structure of failing lanes on Memory Channel
struct eRepairMemBus
{
   eRepairMemDevInfo device;        // Device info of P8 and Centaur
   uint8_t             type      :4;// Range:0x0-0xF. Value:MEMORY_EDI
   uint8_t             interface :4;// Range:0x0-0xF. Value:UpIn, UpOut,
                                    //                      DownIn, DownOut
   uint8_t             failBit;     // Range:0x00-0xFF.
                                    // Value:Failing lane number:0-13 OR 0-19
                                    //       depends on DownStream or UpStream
};

#endif
