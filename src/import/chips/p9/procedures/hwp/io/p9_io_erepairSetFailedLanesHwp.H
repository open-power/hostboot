/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_erepairSetFailedLanesHwp.H $ */
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
/// @file p9_io_erepairSetFailedLanesHwp.H
/// @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------

#ifndef P9_IO_EREPAIRSETFAILEDLANESHWP_H_
#define P9_IO_EREPAIRSETFAILEDLANESHWP_H_

#include <fapi2.H>
#include <p9_io_erepairConsts.H>
#include <mvpd_access.H>
#include <fapi2_mbvpd_access.H>

#define RECORD_LENGTH_BYTES 7

/******************************************************************************
 * Accessor HWP
 *****************************************************************************/

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers of a specified interface.
 *
 * @param[in] i_target       Reference to X-Bus or O-Bus or DMI target
 * @param[in] i_busInterface This indicates the sub-interface type the passed
 *                           faillane vector represents
 * @param[in] i_repairLane   Reference to the faillane number
 *                           that need to be updated to fail bits field
 * @param[o]  o_failBit      This is the failed lanes data that maintains the
 *                           eRepair record that needs to be updated with fail
 *                           lane number
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode gatherRepairLanes(
    const fapi2::Target < K >&           i_target,
    uint8_t                             i_busInterface,
    uint8_t                             i_repairLane,
    uint32_t*                           o_failBit)
{
    fapi2::ReturnCode l_rc;
    uint8_t           maxBusLanes       = 0;
    uint32_t          setBitPosition    = (0x00800000); // fail bits[0:23] maps to bits[8:31]

    FAPI_INF(">> setRepairLanes - IF:%d repairLane:%d ", i_busInterface, i_repairLane);

    // Check for target type and corresponding sub interface
    // to get max lanes supported per interface
    if(i_target.getType() == fapi2::TARGET_TYPE_OBUS)
    {
        maxBusLanes = EREPAIR::OBUS_MAX_LANE_WIDTH;    //OBUS
    }
    else if(i_target.getType() == fapi2::TARGET_TYPE_XBUS)
    {
        maxBusLanes = EREPAIR::XBUS_MAX_LANE_WIDTH;    //XBUS
    }
    else if((i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP) ||
            (i_target.getType() == fapi2::TARGET_TYPE_DMI))
    {
        // DMI <-- Centaur - Upstream
        if( (i_busInterface == EREPAIR::DMI_MCS_RECEIVE) ||
            (i_busInterface == EREPAIR::DMI_MEMBUF_DRIVE) )
        {
            maxBusLanes = EREPAIR::DMIBUS_UPSTREAM_MAX_LANE_WIDTH;
        }
        // DMI --> Centaur - Downstream
        else if( (i_busInterface == EREPAIR::DMI_MCS_DRIVE) ||
                 (i_busInterface == EREPAIR::DMI_MEMBUF_RECEIVE) )
        {
            maxBusLanes = EREPAIR::DMIBUS_DNSTREAM_MAX_LANE_WIDTH;
        }
    }

    // Make sure repair lane value passed is within valid range as per the target type
    FAPI_ASSERT(i_repairLane < maxBusLanes,
                fapi2::P9_EREPAIR_INVALID_LANE_VALUE_ERR()
                .set_VAL_REPAIR_LANE(i_repairLane)
                .set_VAL_MAX_LANES(maxBusLanes)
                .set_TARGET(i_target),
                "ERROR: Invalid erepair lane value");

    // Update the fail bits data with the repair lane number failed
    *o_failBit |= (setBitPosition >> i_repairLane);

    // Get the failed lanes
    FAPI_INF("Updated Fail Lanes:0x%x", *o_failBit);

    FAPI_DBG("<< setRepairLanes");

fapi_try_exit:
    return l_rc;
}

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers of a specified interface.
 *
 * @param[in] i_target      Reference to X-Bus target
 * @param[in] i_interface   This indicates the sub-interface type the passed
 *                          faillane vector represents
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_failLanes   Reference to a vector that has the faillane numbers
 *                          that need to be updated to the o_buf buffer
 * @param[o]  o_buf         This is the buffer that has the eRepair records
 *                          that needs to be written to the VPD
 * (For Proc)
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode updateRepairLanesToBufProc(
    const fapi2::Target < K >&          i_target,
    const EREPAIR::interfaceType        i_interface,
    const uint32_t             i_bufSz,
    const uint8_t              i_clkGroup,
    const std::vector<uint8_t>& i_failLanes,
    uint8_t*                    o_buf)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint32_t         l_numRepairs           = 0;
    uint32_t         l_newNumRepairs        = 0;
    uint32_t         l_repairCnt            = 0;
    uint32_t         l_bytesParsed          = 0;
    uint8_t          l_repairLane           = 0;
    uint32_t         l_repairDataSz         = 0;
    uint8_t*          l_vpdPtr              = NULL;
    uint8_t*          l_vpdDataPtr          = NULL;
    uint8_t*          l_vpdWritePtr         = NULL;
    eRepairHeader*    l_vpdHeadPtr          = NULL;
    eRepairPowerBus*  l_overWritePtr        = NULL;
    bool             l_overWrite            = false;
    uint8_t          l_chipNum              = 0;
    uint32_t         l_chipPosition         = 0;
    fapi2::Target<fapi2::TARGET_TYPE_DMI>   l_dmiTarget;
    std::vector<uint8_t>::const_iterator l_it;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_busNum;

    FAPI_INF(">> updateRepairLanesToBuf(XBUS), interface: %s clkgrp:%d ",
             i_interface == EREPAIR::DRIVE ? "Drive" : "Receive", i_clkGroup);

    for(unsigned long i = 0; (i < i_failLanes.size() && i_failLanes.size() != 0); i++)
    {
        FAPI_INF("(%lu):%llu ", i, i_failLanes[i]);
    }

    {
        l_repairDataSz = sizeof(eRepairPowerBus); // Size of memory Bus and
        // fabric Bus eRepair data
        // is same.
        // Read the header and count information
        l_vpdPtr = o_buf; // point to the start of header data
        l_vpdHeadPtr = reinterpret_cast<eRepairHeader*> (l_vpdPtr);

        l_numRepairs = l_newNumRepairs = l_vpdHeadPtr->availNumRecord;

        // We've read the header data, increment bytes parsed
        l_bytesParsed = sizeof(eRepairHeader);

        // Get a pointer to the start of repair data
        l_vpdPtr += sizeof(eRepairHeader);

        // Get the bus number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               i_target,
                               l_busNum));

        // Get the chip target
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chipTarget;
        l_chipTarget = i_target.template getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        // Get the chip number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POS,
                               l_chipTarget,
                               l_chipPosition));

        // This is needed because we can only store and compare a uint8_t
        // value. For our purpose the value in l_chipPosition (Proc Position and
        // Centaur Position) will always be within the range of uint8_t
        l_chipNum = l_chipPosition;

        // Pick each faillane for copying into buffer
        for(l_it  = i_failLanes.begin();
            l_it != i_failLanes.end();
            l_it++)
        {
            // Get vpd starting data pointer
            l_vpdDataPtr  = l_vpdPtr;
            l_repairCnt   = 0;

            l_repairLane  = *l_it;
            l_overWrite   = false;
            l_vpdWritePtr = NULL;

            FAPI_INF("repairLaneCnt-1:it:%d ", l_repairLane);

            // Parse the VPD for fabric and memory eRepair records
            for(;
                (l_repairCnt < l_numRepairs) && (l_bytesParsed <= i_bufSz);
                l_repairCnt++, (l_vpdDataPtr += l_repairDataSz))
            {
                l_overWritePtr =
                    reinterpret_cast<eRepairPowerBus*> (l_vpdDataPtr);

                FAPI_INF("repairLaneCnt-2:repariCnt:%d numRepair:%d byteparsed:%d bufSize:%d ", l_repairCnt, l_numRepairs,
                         l_bytesParsed,
                         i_bufSz);

                // Lets find the matching fabric
                if( (l_overWritePtr->device.processor_id == l_chipNum) &&
                    (l_overWritePtr->device.fabricBus    == ((i_clkGroup << 4) | l_busNum)) &&
                    (l_overWritePtr->type                == EREPAIR::PROCESSOR_EDIP) &&
                    (((l_overWritePtr->interface == EREPAIR::PBUS_DRIVER) && (i_interface == EREPAIR::DRIVE)) ||
                     ((l_overWritePtr->interface == EREPAIR::PBUS_RECEIVER) && (i_interface == EREPAIR::RECEIVE))) )
                {
                    FAPI_INF("repairLaneCnt-3:Found match: Dev id:%d type:%d IF:%d  Bus:%d ", (l_overWritePtr->device).processor_id,
                             l_overWritePtr->type, l_overWritePtr->interface, l_overWritePtr->device.fabricBus);

                    if(l_repairLane == EREPAIR::INVALID_FAIL_LANE_NUMBER)
                    {
                        FAPI_INF("FailBit:0x%x is invalidated(reset to zero)",
                                 l_overWritePtr->failBit);
                        l_overWritePtr->failBit = 0;
                        l_newNumRepairs--;
                    }
                    else  // update the failBit number
                    {
                        uint32_t temp  = (uint32_t)(l_overWritePtr->failBit);
                        uint32_t* tptr = &temp;
                        FAPI_INF("Status(after):Status(before):FailBit:0x%x temp:0x%x ", l_overWritePtr->failBit, temp);
                        FAPI_TRY( gatherRepairLanes(
                                      i_target,
                                      l_overWritePtr->interface,
                                      l_repairLane,
                                      tptr),
                                  "gatherRepairLanes() failed w/rc=0x%x",
                                  static_cast<uint64_t>(fapi2::current_err) );
                        l_overWritePtr->failBit = temp;
                        FAPI_INF("Status(after):FailBit:0x%x temp:0x%x ", l_overWritePtr->failBit, temp);
                    }

                    // Matching record found
                    l_overWrite = true;

                    // Get the record updated
                    FAPI_INF("Record updated: ");

                    for(uint8_t i = 0; i < RECORD_LENGTH_BYTES; i++)
                    {
                        FAPI_INF("%02x ", *(l_vpdDataPtr + i));
                    }

                    break;
                }

                // Increment the count of parsed bytes
                l_bytesParsed += l_repairDataSz;

            } // end of for(vpd Parsing)

            if( (l_overWrite == true) ||
                (l_repairLane == EREPAIR::INVALID_FAIL_LANE_NUMBER) )
            {
                // Go for the next repairLane
                continue;
            }

            // Check if we have parsed more bytes than the passed size
            if((l_vpdWritePtr == NULL)       &&
               (l_bytesParsed > i_bufSz)     &&
               (l_repairCnt < l_numRepairs))
            {
                FAPI_ASSERT(false,
                            fapi2::P9_EREPAIR_MVPD_FULL_ERR()
                            .set_VAL_BYTE_PARSED(l_bytesParsed)
                            .set_VAL_BUF_SIZE(i_bufSz)
                            .set_VAL_REPAIR_CNT(l_repairCnt)
                            .set_VAL_OVERWRITE_FLAG(l_overWrite)
                            .set_VAL_NUM_REPAIR(l_numRepairs),
                            "ERROR-1: from updateRepairLanesToBuf(Proc) - MVPD full");
            }

            // Add at the end
            if(l_overWrite == false)
            {
                if(l_vpdWritePtr == NULL)
                {
                    // We are writing at the end
                    l_vpdWritePtr = l_vpdDataPtr;
                }

                {
                    // Make sure we are not writing more records than the size
                    // allocated in the VPD
                    FAPI_ASSERT(l_bytesParsed <= i_bufSz,
                                fapi2::P9_EREPAIR_MVPD_FULL_ERR()
                                .set_VAL_BYTE_PARSED(l_bytesParsed)
                                .set_VAL_BUF_SIZE(i_bufSz)
                                .set_VAL_REPAIR_CNT(l_repairCnt)
                                .set_VAL_OVERWRITE_FLAG(l_overWrite)
                                .set_VAL_NUM_REPAIR(l_numRepairs),
                                "ERROR-2: from updateRepairLanesToBuf(Proc) - MVPD full");

                    eRepairPowerBus* l_fabricBus =
                        reinterpret_cast<eRepairPowerBus*>(l_vpdWritePtr);

                    l_fabricBus->device.processor_id = l_chipNum;
                    l_fabricBus->device.fabricBus    = ((i_clkGroup << 4) | l_busNum);

                    if(i_interface == EREPAIR::DRIVE)
                    {
                        l_fabricBus->interface = EREPAIR::PBUS_DRIVER;
                    }
                    else if(i_interface == EREPAIR::RECEIVE)
                    {
                        l_fabricBus->interface = EREPAIR::PBUS_RECEIVER;
                    }

                    if(i_target.getType() == fapi2::TARGET_TYPE_XBUS)
                    {
                        l_fabricBus->type = EREPAIR::PROCESSOR_EDIP;
                    }
                    else if(i_target.getType() == fapi2::TARGET_TYPE_OBUS)
                    {
                        l_fabricBus->type = EREPAIR::PROCESSOR_OPT;
                    }

                    FAPI_INF("Fabric Bus(before update):Dev:%d Bus:%d Type:%d MemIF:%d IF:%d ", l_fabricBus->device.processor_id,
                             l_fabricBus->device.fabricBus, l_fabricBus->type, l_fabricBus->interface, i_interface);

                    {
                        // For adding 'new' record, default value of failBit field should be zero
                        l_fabricBus->failBit = 0;
                        uint32_t temp = (uint32_t)(l_fabricBus->failBit);
                        uint32_t* tptr = &temp;
                        FAPI_INF("Status(before):FailBit:0x%x temp:0x%x ", l_fabricBus->failBit, temp);
                        FAPI_TRY( gatherRepairLanes(
                                      i_target,
                                      l_fabricBus->interface,
                                      l_repairLane,
                                      tptr),
                                  "gatherRepairLanes() failed w/rc=0x%x",
                                  static_cast<uint64_t>(fapi2::current_err) );
                        l_fabricBus->failBit = temp;
                        FAPI_INF("Status(after):FailBit:0x%x temp:0x%x ", l_fabricBus->failBit, temp);
                    }

                    FAPI_INF("Fabric Bus(after update):Dev:%d Bus:%d Type:%d MemIF:%d IF:%d FailBit:0x%x ",
                             l_fabricBus->device.processor_id,
                             l_fabricBus->device.fabricBus, l_fabricBus->type, l_fabricBus->interface, i_interface, l_fabricBus->failBit);

                    // Get the record added
                    FAPI_INF("Record Added: ");

                    for(uint8_t i = 0; i < RECORD_LENGTH_BYTES; i++)
                    {
                        FAPI_INF("%02x ", *(l_vpdDataPtr + i));
                    }

                    l_newNumRepairs++;

                    // Increment the count of parsed bytes
                    l_bytesParsed += l_repairDataSz;
#ifndef _BIG_ENDIAN
                    // We are on a Little Endian system.
                    // Need to swap the nibbles of structure - eRepairPowerBus

                    l_vpdWritePtr[2] = ((l_vpdWritePtr[2] >> 4) |
                                        (l_vpdWritePtr[2] << 4));
#endif
                }
            } // end of if(l_overWrite == false)
        } // end of for(failLanes)
    }

    // Update the eRepair count
    l_vpdHeadPtr->availNumRecord = l_newNumRepairs;
    FAPI_INF("Result:NumRec:%d ", l_vpdHeadPtr->availNumRecord);

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers of a specified interface.
 *
 * @param[in] i_target      Reference to MEMBUF target
 * @param[in] i_interface   This indicates the sub-interface type the passed
 *                          faillane vector represents
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_failLanes   Reference to a vector that has the faillane numbers
 *                          that need to be updated to the o_buf buffer
 * @param[o]  o_buf         This is the buffer that has the eRepair records
 *                          that needs to be written to the VPD
 * (For MemBuf)
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode updateRepairLanesToBufMemBuf(
    const fapi2::Target < K >&          i_target,
    const EREPAIR::interfaceType        i_interface,
    const uint32_t             i_bufSz,
    const uint8_t              i_clkGroup,
    const std::vector<uint8_t>& i_failLanes,
    const uint8_t              i_dimm,
    uint8_t*                    o_buf)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint32_t         l_numRepairs           = 0;
    uint32_t         l_newNumRepairs        = 0;
    uint32_t         l_repairCnt            = 0;
    uint32_t         l_bytesParsed          = 0;
    uint8_t          l_repairLane           = 0;
    uint32_t         l_repairDataSz         = 0;
    uint8_t*          l_vpdPtr              = NULL;
    uint8_t*          l_vpdDataPtr          = NULL;
    uint8_t*          l_vpdWritePtr         = NULL;
    bool             l_overWrite            = false;
    uint8_t          l_chipNum              = 0;
    uint32_t         l_chipPosition         = 0;
    fapi2::Target<fapi2::TARGET_TYPE_DMI>   l_dmiTarget;
    std::vector<uint8_t>::const_iterator l_it;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_busNum;

    FAPI_INF(">> updateRepairLanesToBuf(MemBuf), interface: %s",
             i_interface == EREPAIR::DRIVE ? "Drive" : "Receive");

    for(unsigned long i = 0; (i < i_failLanes.size() && i_failLanes.size() != 0); i++)
    {
        FAPI_INF("(%lu):%llu ", i, i_failLanes[i]);
    }

    FAPI_INF("Dimm:(%d)%s ", i_dimm,
             (i_dimm == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO ? "CEN_SPD_CUSTOM_NO" : "CEN_SPD_CUSTOM_YES"));

    // For Memory riser based centaur
    if(i_dimm == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO)
    {
        eRepairHeader*    l_vpdHeadPtr          = NULL;
        eRepairMemBus*    l_overWritePtr        = NULL;

        l_repairDataSz = sizeof(eRepairMemBus); // Size of memory Bus and
        // fabric Bus eRepair data
        // is same.
        // Read the header and count information
        l_vpdPtr = o_buf; // point to the start of header data
        l_vpdHeadPtr = reinterpret_cast<eRepairHeader*> (l_vpdPtr);

        l_numRepairs = l_newNumRepairs = l_vpdHeadPtr->availNumRecord;

        // We've read the header data, increment bytes parsed
        l_bytesParsed = sizeof(eRepairHeader);

        // Get a pointer to the start of repair data
        l_vpdPtr += sizeof(eRepairHeader);

        // Get DMI parent target
        l_dmiTarget = i_target.template getParent<fapi2::TARGET_TYPE_DMI>();

        // Get the bus number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_dmiTarget,
                               l_busNum));

        // Get the chip number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POS,
                               i_target,
                               l_chipPosition));

        // This is needed because we can only store and compare a uint8_t
        // value. For our purpose the value in l_chipPosition (Proc Position and
        // Centaur Position) will always be within the range of uint8_t
        l_chipNum = l_chipPosition;

        // Pick each faillane for copying into buffer
        for(l_it  = i_failLanes.begin();
            l_it != i_failLanes.end();
            l_it++)
        {
            // Get vpd starting data pointer
            l_vpdDataPtr  = l_vpdPtr;
            l_repairCnt   = 0;

            l_repairLane  = *l_it;
            l_overWrite   = false;
            l_vpdWritePtr = NULL;

            FAPI_INF("repairLaneCnt-1:it:%d numRepair:%d bufSize:%d ", l_repairLane, l_numRepairs, i_bufSz);

            // Parse the VPD for fabric and memory eRepair records
            for(;
                (l_repairCnt < l_numRepairs) && (l_bytesParsed <= i_bufSz);
                l_repairCnt++, (l_vpdDataPtr += l_repairDataSz))
            {
                l_overWritePtr =
                    reinterpret_cast<eRepairMemBus*> (l_vpdDataPtr);

                FAPI_INF("repairLaneCnt-2:erepairCnt:%d byteparsed:%d erprlane:%02x ChipNum:%d BusNum:%d",
                         l_repairCnt, l_bytesParsed, l_repairLane, l_chipNum, l_busNum);
                FAPI_INF("repairLaneCnt-2:Centaur Id:%d MemChannel:%d type:%d IF:%d FailBit:%d ",
                         l_overWritePtr->device.proc_centaur_id, l_overWritePtr->device.memChannel,
                         l_overWritePtr->type, l_overWritePtr->interface, l_overWritePtr->failBit);

                if( (l_overWritePtr->device.proc_centaur_id == l_chipNum) &&
                    (l_overWritePtr->device.memChannel      == l_busNum ) &&
                    (l_overWritePtr->type                   == EREPAIR::MEMORY_EDIP) &&
                    (((i_interface == EREPAIR::DRIVE) && (l_overWritePtr->interface == EREPAIR::DMI_MEMBUF_DRIVE)) ||
                     ((i_interface == EREPAIR::RECEIVE) && (l_overWritePtr->interface == EREPAIR::DMI_MEMBUF_RECEIVE))) )
                {
                    FAPI_INF("repairLaneCnt-3:Found record match");

                    if(l_repairLane == EREPAIR::INVALID_FAIL_LANE_NUMBER)
                    {
                        FAPI_INF("FailBit:0x%x is invalidated(reset to zero)", l_overWritePtr->failBit);
                        l_overWritePtr->failBit = 0;
                        l_newNumRepairs--;
                    }
                    else  // update the failBit number
                    {
                        uint32_t temp = (uint32_t)(l_overWritePtr->failBit);
                        uint32_t* tptr = &temp;
                        FAPI_INF("Status(before):FailBit:0x%x temp:0x%x ", l_overWritePtr->failBit, temp);
                        FAPI_TRY( gatherRepairLanes(
                                      i_target,
                                      l_overWritePtr->interface,
                                      l_repairLane,
                                      tptr),
                                  "gatherRepairLanes() failed w/rc=0x%x",
                                  static_cast<uint64_t>(fapi2::current_err) );
                        l_overWritePtr->failBit = temp;
                        FAPI_INF("Status(after):FailBit:0x%x temp:0x%x ", l_overWritePtr->failBit, temp);
                    }

                    // Matching record found
                    l_overWrite = true;

                    // Get the record updated
                    FAPI_INF("Record updated: ");

                    for(uint8_t i = 0; i < RECORD_LENGTH_BYTES; i++)
                    {
                        FAPI_INF("%02x ", *(l_vpdDataPtr + i));
                    }

                    break;
                } // end of record check

                // Increment the count of parsed bytes
                l_bytesParsed += l_repairDataSz;

            } // end of for(vpd Parsing)

            if( (l_overWrite == true) ||
                (l_repairLane == EREPAIR::INVALID_FAIL_LANE_NUMBER) )
            {
                // Go for the next repairLane
                continue;
            }

            // Check if we have parsed more bytes than the passed size
            if((l_vpdWritePtr == NULL)       &&
               (l_bytesParsed > i_bufSz)     &&
               (l_repairCnt < l_numRepairs))
            {
                FAPI_ASSERT(false,
                            fapi2::P9_EREPAIR_MBVPD_FULL_ERR()
                            .set_VAL_BYTE_PARSED(l_bytesParsed)
                            .set_VAL_BUF_SIZE(i_bufSz)
                            .set_VAL_REPAIR_CNT(l_repairCnt)
                            .set_VAL_OVERWRITE_FLAG(l_overWrite)
                            .set_VAL_NUM_REPAIR(l_numRepairs),
                            "ERROR-1: from updateRepairLanesToBuf(MemBuf) - MVPD full");
            }

            // Add at the end
            if(l_overWrite == false)
            {
                if(l_vpdWritePtr == NULL)
                {
                    // We are writing at the end
                    l_vpdWritePtr = l_vpdDataPtr;
                }

                {
                    // Make sure we are not writing more records than the size
                    // allocated in the VPD
                    FAPI_ASSERT(l_bytesParsed <= i_bufSz,
                                fapi2::P9_EREPAIR_MBVPD_FULL_ERR()
                                .set_VAL_BYTE_PARSED(l_bytesParsed)
                                .set_VAL_BUF_SIZE(i_bufSz)
                                .set_VAL_REPAIR_CNT(l_repairCnt)
                                .set_VAL_OVERWRITE_FLAG(l_overWrite)
                                .set_VAL_NUM_REPAIR(l_numRepairs),
                                "ERROR-2: from updateRepairLanesToBuf(MemBuf) - MBVPD full");

                    eRepairMemBus* l_memBus =
                        reinterpret_cast<eRepairMemBus*>(l_vpdWritePtr);

                    l_memBus->device.proc_centaur_id = l_chipNum;
                    l_memBus->device.memChannel      = l_busNum;
                    l_memBus->type                   = EREPAIR::MEMORY_EDIP;

                    if(i_interface == EREPAIR::DRIVE)
                    {
                        if(i_target.getType() == fapi2::TARGET_TYPE_DMI)
                        {
                            l_memBus->interface = EREPAIR::DMI_MCS_DRIVE;
                        }
                        else if(i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = EREPAIR::DMI_MEMBUF_DRIVE;
                        }
                    }
                    else if(i_interface == EREPAIR::RECEIVE)
                    {
                        if(i_target.getType() == fapi2::TARGET_TYPE_DMI)
                        {
                            l_memBus->interface = EREPAIR::DMI_MCS_RECEIVE;
                        }
                        else if(i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = EREPAIR::DMI_MEMBUF_RECEIVE;
                        }
                    }

                    FAPI_INF("Memory Bus(before update):Dev:%d Bus:%d Type:%d MemIF:%d IF:%d ", l_memBus->device.proc_centaur_id,
                             l_memBus->device.memChannel, l_memBus->type, l_memBus->interface, i_interface);

                    // For adding 'new' record, default value of failBit field should be zero
                    l_memBus->failBit = 0;
                    uint32_t temp = (uint32_t)(l_memBus->failBit);
                    uint32_t* tptr = &temp;
                    FAPI_INF("Status(before):FailBit:0x%x temp:0x%x ", l_memBus->failBit, temp);
                    FAPI_TRY( gatherRepairLanes(
                                  i_target,
                                  l_memBus->interface,
                                  l_repairLane,
                                  tptr),
                              "gatherRepairLanes() failed w/rc=0x%x",
                              static_cast<uint64_t>(fapi2::current_err) );
                    l_memBus->failBit = temp;
                    FAPI_INF("Status(after):FailBit:0x%x temp:0x%x ", l_memBus->failBit, temp);

                    FAPI_INF("Memory Bus(after update):Dev:%d Bus:%d Type:%d MemIF:%d IF:%d FailBit:0x%x ",
                             l_memBus->device.proc_centaur_id,
                             l_memBus->device.memChannel, l_memBus->type, l_memBus->interface, i_interface, l_memBus->failBit);

                    // Get the record added
                    FAPI_INF("Record added: ");

                    for(uint8_t i = 0; i < RECORD_LENGTH_BYTES; i++)
                    {
                        FAPI_INF("%02x ", *(l_vpdDataPtr + i));
                    }

                    l_newNumRepairs++;

                    // Increment the count of parsed bytes
                    l_bytesParsed += l_repairDataSz;
#ifndef _BIG_ENDIAN
                    // We are on a Little Endian system.
                    // Need to swap the nibbles of structure - eRepairMemBus

                    l_vpdWritePtr[2] = ((l_vpdWritePtr[2] >> 4) |
                                        (l_vpdWritePtr[2] << 4));
#endif
                }
            } // end of if(l_overWrite == false)
        } // end of for(failLanes)

        // Update the eRepair count
        l_vpdHeadPtr->availNumRecord = l_newNumRepairs;
        FAPI_INF("Result:NumRec:%d ", l_vpdHeadPtr->availNumRecord);
    }
    else    // For CDIMM
    {
        eRepairHeader_cdimm*    l_vpdHeadPtr          = NULL;
        eRepairMemBus_cdimm*    l_overWritePtr        = NULL;

        l_repairDataSz = sizeof(eRepairMemBus_cdimm);
        // is same.
        // Read the header and count information
        l_vpdPtr = o_buf; // point to the start of header data
        l_vpdHeadPtr = reinterpret_cast<eRepairHeader_cdimm*> (l_vpdPtr);

        l_numRepairs = l_newNumRepairs = l_vpdHeadPtr->numRecords;

        // We've read the header data, increment bytes parsed
        l_bytesParsed = sizeof(eRepairHeader_cdimm);

        // Get a pointer to the start of repair data
        l_vpdPtr += sizeof(eRepairHeader_cdimm);

        // Get DMI parent target
        l_dmiTarget = i_target.template getParent<fapi2::TARGET_TYPE_DMI>();

        // Get the bus number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_dmiTarget,
                               l_busNum));

        // Get the chip number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POS,
                               i_target,
                               l_chipPosition));

        // This is needed because we can only store and compare a uint8_t
        // value. For our purpose the value in l_chipPosition (Proc Position and
        // Centaur Position) will always be within the range of uint8_t
        l_chipNum = l_chipPosition;

        // Pick each faillane for copying into buffer
        for(l_it  = i_failLanes.begin();
            l_it != i_failLanes.end();
            l_it++)
        {
            // Get vpd starting data pointer
            l_vpdDataPtr  = l_vpdPtr;
            l_repairCnt   = 0;

            l_repairLane  = *l_it;
            l_overWrite   = false;
            l_vpdWritePtr = NULL;

            FAPI_INF("repairLaneCnt-1:it:%d numRepair:%d bufSize:%d ", l_repairLane, l_numRepairs, i_bufSz);

            // Parse the VPD for fabric and memory eRepair records
            for(;
                (l_repairCnt < l_numRepairs) && (l_bytesParsed <= i_bufSz);
                l_repairCnt++, (l_vpdDataPtr += l_repairDataSz))
            {
                l_overWritePtr =
                    reinterpret_cast<eRepairMemBus_cdimm*> (l_vpdDataPtr);

                FAPI_INF("repairLaneCnt-2:erepairCnt:%d byteparsed:%d erprlane:%02x ChipNum:%d BusNum:%d",
                         l_repairCnt, l_bytesParsed, l_repairLane, l_chipNum, l_busNum);
                FAPI_INF("repairLaneCnt-2:Centaur Id:%d MemChannel:%d type:%d IF:%d FailBit:%d ",
                         l_overWritePtr->device.proc_centaur_id, l_overWritePtr->device.memChannel,
                         l_overWritePtr->type, l_overWritePtr->interface, l_overWritePtr->failBit);

                if( (l_overWritePtr->device.proc_centaur_id == l_chipNum) &&
                    (l_overWritePtr->device.memChannel      == l_busNum ) &&
                    (l_overWritePtr->type                   == EREPAIR::MEMORY_EDIP) &&
                    ((l_overWritePtr->failBit               == l_repairLane) ||
                     (l_repairLane                          == EREPAIR::INVALID_FAIL_LANE_NUMBER)) &&
                    (((i_interface == EREPAIR::DRIVE) && (l_overWritePtr->interface == EREPAIR::DMI_MEMBUF_DRIVE)) ||
                     ((i_interface == EREPAIR::RECEIVE) && (l_overWritePtr->interface == EREPAIR::DMI_MEMBUF_RECEIVE))) )
                {
                    FAPI_INF("repairLaneCnt-3:Found record match");

                    if(l_repairLane == EREPAIR::INVALID_FAIL_LANE_NUMBER)
                    {
                        FAPI_INF("repairLaneCnt-4:Invalidated lane number:0x%2x",
                                 l_overWritePtr->failBit);
                        l_overWritePtr->failBit = l_repairLane;
                        l_newNumRepairs--;
                    }

                    // Matching record exist so no action taken; goto next record
                    // Note: To be consistent & avoid too may variables to track
                    // the name l_overWrite is retained but it doesn't mean lane
                    // got overwritten
                    l_overWrite = true;
                    break;
                }

                // Increment the count of parsed bytes
                l_bytesParsed += l_repairDataSz;

            } // end of for(vpd Parsing)

            if( (l_overWrite == true) ||
                (l_repairLane == EREPAIR::INVALID_FAIL_LANE_NUMBER) )
            {
                // Go for the next repairLane
                continue;
            }

            // Check if we have parsed more bytes than the passed size
            if((l_vpdWritePtr == NULL)       &&
               (l_bytesParsed > i_bufSz)     &&
               (l_repairCnt < l_numRepairs))
            {
                FAPI_ASSERT(false,
                            fapi2::P9_EREPAIR_MBVPD_FULL_ERR()
                            .set_VAL_BYTE_PARSED(l_bytesParsed)
                            .set_VAL_BUF_SIZE(i_bufSz)
                            .set_VAL_REPAIR_CNT(l_repairCnt)
                            .set_VAL_OVERWRITE_FLAG(l_overWrite)
                            .set_VAL_NUM_REPAIR(l_numRepairs),
                            "ERROR-1: from updateRepairLanesToBuf(MemBuf) - MVPD full");
            }

            // Add at the end
            if(l_overWrite == false)
            {
                if(l_vpdWritePtr == NULL)
                {
                    // We are writing at the end
                    l_vpdWritePtr = l_vpdDataPtr;
                }

                {
                    // Make sure we are not writing more records than the size
                    // allocated in the VPD
                    FAPI_ASSERT(l_bytesParsed <= i_bufSz,
                                fapi2::P9_EREPAIR_MBVPD_FULL_ERR()
                                .set_VAL_BYTE_PARSED(l_bytesParsed)
                                .set_VAL_BUF_SIZE(i_bufSz)
                                .set_VAL_REPAIR_CNT(l_repairCnt)
                                .set_VAL_OVERWRITE_FLAG(l_overWrite)
                                .set_VAL_NUM_REPAIR(l_numRepairs),
                                "ERROR-2: from updateRepairLanesToBuf(MemBuf) - MBVPD full");

                    eRepairMemBus_cdimm* l_memBus =
                        reinterpret_cast<eRepairMemBus_cdimm*>(l_vpdWritePtr);

                    l_memBus->device.proc_centaur_id = l_chipNum;
                    l_memBus->device.memChannel      = l_busNum;
                    l_memBus->type                   = EREPAIR::MEMORY_EDIP;

                    if(i_interface == EREPAIR::DRIVE)
                    {
                        if(i_target.getType() == fapi2::TARGET_TYPE_DMI)
                        {
                            l_memBus->interface = EREPAIR::DMI_MCS_DRIVE;
                        }
                        else if(i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = EREPAIR::DMI_MEMBUF_DRIVE;
                        }
                    }
                    else if(i_interface == EREPAIR::RECEIVE)
                    {
                        if(i_target.getType() == fapi2::TARGET_TYPE_DMI)
                        {
                            l_memBus->interface = EREPAIR::DMI_MCS_RECEIVE;
                        }
                        else if(i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = EREPAIR::DMI_MEMBUF_RECEIVE;
                        }
                    }

                    FAPI_INF("Memory Bus(before update):Dev:%d Bus:%d Type:%d MemIF:%d IF:%d ", l_memBus->device.proc_centaur_id,
                             l_memBus->device.memChannel, l_memBus->type, l_memBus->interface, i_interface);

                    l_memBus->failBit = l_repairLane;

                    FAPI_INF("Memory Bus(after update):Dev:%d Bus:%d Type:%d MemIF:%d IF:%d FailBit:0x%x ",
                             l_memBus->device.proc_centaur_id,
                             l_memBus->device.memChannel, l_memBus->type, l_memBus->interface, i_interface, l_memBus->failBit);

                    // Get the record added
                    FAPI_INF("Record added: ");

                    for(uint8_t i = 0; i < RECORD_LENGTH_BYTES; i++)
                    {
                        FAPI_INF("%02x ", *(l_vpdDataPtr + i));
                    }

                    l_newNumRepairs++;

                    // Increment the count of parsed bytes
                    l_bytesParsed += l_repairDataSz;
#ifndef _BIG_ENDIAN
                    // We are on a Little Endian system.
                    // Need to swap the nibbles of structure - eRepairMemBus

                    l_vpdWritePtr[2] = ((l_vpdWritePtr[2] >> 4) |
                                        (l_vpdWritePtr[2] << 4));
#endif
                }
            } // end of if(l_overWrite == false)
        } // end of for(failLanes)

        // Update the eRepair count
        l_vpdHeadPtr->numRecords = l_newNumRepairs;
        FAPI_INF("Result:NumRec:%d ", l_vpdHeadPtr->numRecords);
    }

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers of a specified interface.
 *
 * @param[in] i_target      Reference to DMI target
 * @param[in] i_interface   This indicates the sub-interface type the passed
 *                          faillane vector represents
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_failLanes   Reference to a vector that has the faillane numbers
 *                          that need to be updated to the o_buf buffer
 * @param[o]  o_buf         This is the buffer that has the eRepair records
 *                          that needs to be written to the VPD
 * (For DMI)
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode updateRepairLanesToBufDMI(
    const fapi2::Target < K >&          i_target,
    const EREPAIR::interfaceType        i_interface,
    const uint32_t             i_bufSz,
    const uint8_t              i_clkGroup,
    const std::vector<uint8_t>& i_failLanes,
    uint8_t*                    o_buf)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint32_t         l_numRepairs           = 0;
    uint32_t         l_newNumRepairs        = 0;
    uint32_t         l_repairCnt            = 0;
    uint32_t         l_bytesParsed          = 0;
    uint8_t          l_repairLane           = 0;
    uint32_t         l_repairDataSz         = 0;
    uint8_t*          l_vpdPtr              = NULL;
    uint8_t*          l_vpdDataPtr          = NULL;
    uint8_t*          l_vpdWritePtr         = NULL;
    eRepairHeader*    l_vpdHeadPtr          = NULL;
    eRepairMemBus*   l_overWritePtr         = NULL;
    bool             l_overWrite            = false;
    uint8_t          l_chipNum              = 0;
    uint32_t         l_chipPosition         = 0;
    fapi2::Target<fapi2::TARGET_TYPE_DMI>   l_dmiTarget;
    std::vector<uint8_t>::const_iterator l_it;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_busNum;

    FAPI_INF(">> updateRepairLanesToBuf(DMI), interface: %s",
             i_interface == EREPAIR::DRIVE ? "Drive" : "Receive");

    for(unsigned long i = 0; (i < i_failLanes.size() && i_failLanes.size() != 0); i++)
    {
        FAPI_INF("(%lu):%llu ", i, i_failLanes[i]);
    }

    {
        l_repairDataSz = sizeof(eRepairMemBus); // Size of memory Bus and
        // fabric Bus eRepair data
        // is same.
        // Read the header and count information
        l_vpdPtr = o_buf; // point to the start of header data
        l_vpdHeadPtr = reinterpret_cast<eRepairHeader*> (l_vpdPtr);

        l_numRepairs = l_newNumRepairs = l_vpdHeadPtr->availNumRecord;

        // We've read the header data, increment bytes parsed
        l_bytesParsed = sizeof(eRepairHeader);

        // Get a pointer to the start of repair data
        l_vpdPtr += sizeof(eRepairHeader);

        // Get the bus number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               i_target,
                               l_busNum));

        // Get the chip target
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chipTarget;
        l_chipTarget = i_target.template getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        // Get the chip number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POS,
                               l_chipTarget,
                               l_chipPosition));

        // This is needed because we can only store and compare a uint8_t
        // value. For our purpose the value in l_chipPosition (Proc Position and
        // Centaur Position) will always be within the range of uint8_t
        l_chipNum = l_chipPosition;

        // Pick each faillane for copying into buffer
        for(l_it  = i_failLanes.begin();
            l_it != i_failLanes.end();
            l_it++)
        {
            // Get vpd starting data pointer
            l_vpdDataPtr  = l_vpdPtr;
            l_repairCnt   = 0;

            l_repairLane  = *l_it;
            l_overWrite   = false;
            l_vpdWritePtr = NULL;

            FAPI_INF("repairLaneCnt-1:it:%d ", l_repairLane);

            // Parse the VPD for fabric and memory eRepair records
            for(;
                (l_repairCnt < l_numRepairs) && (l_bytesParsed <= i_bufSz);
                l_repairCnt++, (l_vpdDataPtr += l_repairDataSz))
            {
                l_overWritePtr =
                    reinterpret_cast<eRepairMemBus*> (l_vpdDataPtr);

                FAPI_INF("repairLaneCnt-2:repariCnt:%d numRepair:%d byteparsed:%d bufSize:%d ", l_repairCnt, l_numRepairs,
                         l_bytesParsed,
                         i_bufSz);

                // Lets find the matching record
                if( (l_overWritePtr->device.proc_centaur_id == l_chipNum) &&
                    (l_overWritePtr->device.memChannel      == l_busNum ) &&
                    (l_overWritePtr->type                   == EREPAIR::MEMORY_EDIP) &&
                    (((i_interface == EREPAIR::DRIVE) && (l_overWritePtr->interface == EREPAIR::DMI_MCS_DRIVE)) ||
                     ((i_interface == EREPAIR::RECEIVE) && (l_overWritePtr->interface == EREPAIR::DMI_MCS_RECEIVE))) )
                {
                    FAPI_INF("repairLaneCnt-3:Found match: Dev id:%d type:%d IF:%d  Bus:%d ", l_overWritePtr->device.proc_centaur_id,
                             l_overWritePtr->type, l_overWritePtr->interface, l_overWritePtr->device.memChannel);

                    if(l_repairLane == EREPAIR::INVALID_FAIL_LANE_NUMBER)
                    {
                        FAPI_INF("FailBit:0x%x is invalidated(reset to zero)",
                                 l_overWritePtr->failBit);
                        l_overWritePtr->failBit = 0;
                        l_newNumRepairs--;
                    }
                    else  // update the failBit number
                    {
                        uint32_t temp = (uint32_t)(l_overWritePtr->failBit);
                        uint32_t* tptr = &temp;
                        FAPI_INF("Status(before):FailBit:0x%x temp:0x%x ", l_overWritePtr->failBit, temp);
                        FAPI_TRY( gatherRepairLanes(
                                      i_target,
                                      l_overWritePtr->interface,
                                      l_repairLane,
                                      tptr),
                                  "gatherRepairLanes() failed w/rc=0x%x",
                                  static_cast<uint64_t>(fapi2::current_err) );
                        l_overWritePtr->failBit = temp;
                        FAPI_INF("Status(after):FailBit:0x%x temp:0x%x ", l_overWritePtr->failBit, temp);
                    }

                    // Matching record found
                    l_overWrite = true;

                    // Get the record updated
                    FAPI_INF("Record updated: ");

                    for(uint8_t i = 0; i < RECORD_LENGTH_BYTES; i++)
                    {
                        FAPI_INF("%02x ", *(l_vpdDataPtr + i));
                    }

                    break;
                } // end of record check

                // Increment the count of parsed bytes
                l_bytesParsed += l_repairDataSz;

            } // end of for(vpd Parsing)

            if( (l_overWrite == true) ||
                (l_repairLane == EREPAIR::INVALID_FAIL_LANE_NUMBER) )
            {
                // Go for the next repairLane
                continue;
            }

            // Check if we have parsed more bytes than the passed size
            if((l_vpdWritePtr == NULL)       &&
               (l_bytesParsed > i_bufSz)     &&
               (l_repairCnt < l_numRepairs))
            {
                FAPI_ASSERT(false,
                            fapi2::P9_EREPAIR_MBVPD_FULL_ERR()
                            .set_VAL_BYTE_PARSED(l_bytesParsed)
                            .set_VAL_BUF_SIZE(i_bufSz)
                            .set_VAL_REPAIR_CNT(l_repairCnt)
                            .set_VAL_OVERWRITE_FLAG(l_overWrite)
                            .set_VAL_NUM_REPAIR(l_numRepairs),
                            "ERROR-1: from updateRepairLanesToBuf(DMI) - MVPD full");
            }

            // Add at the end
            if(l_overWrite == false)
            {
                if(l_vpdWritePtr == NULL)
                {
                    // We are writing at the end
                    l_vpdWritePtr = l_vpdDataPtr;
                }

                {
                    // Make sure we are not writing more records than the size
                    // allocated in the VPD
                    FAPI_ASSERT(l_bytesParsed <= i_bufSz,
                                fapi2::P9_EREPAIR_MBVPD_FULL_ERR()
                                .set_VAL_BYTE_PARSED(l_bytesParsed)
                                .set_VAL_BUF_SIZE(i_bufSz)
                                .set_VAL_REPAIR_CNT(l_repairCnt)
                                .set_VAL_OVERWRITE_FLAG(l_overWrite)
                                .set_VAL_NUM_REPAIR(l_numRepairs),
                                "ERROR-2: from updateRepairLanesToBuf(DMI) - MBVPD full");

                    eRepairMemBus* l_memBus =
                        reinterpret_cast<eRepairMemBus*>(l_vpdWritePtr);

                    l_memBus->device.proc_centaur_id = l_chipNum;
                    l_memBus->device.memChannel      = l_busNum;
                    l_memBus->type                   = EREPAIR::MEMORY_EDIP;

                    if(i_interface == EREPAIR::DRIVE)
                    {
                        if(i_target.getType() == fapi2::TARGET_TYPE_DMI)
                        {
                            l_memBus->interface = EREPAIR::DMI_MCS_DRIVE;
                        }
                        else if(i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = EREPAIR::DMI_MEMBUF_DRIVE;
                        }
                    }
                    else if(i_interface == EREPAIR::RECEIVE)
                    {
                        if(i_target.getType() == fapi2::TARGET_TYPE_DMI)
                        {
                            l_memBus->interface = EREPAIR::DMI_MCS_RECEIVE;
                        }
                        else if(i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = EREPAIR::DMI_MEMBUF_RECEIVE;
                        }
                    }

                    FAPI_INF("DMI Bus(before update):Dev:%d Bus:%d Type:%d MemIF:%d IF:%d ", l_memBus->device.proc_centaur_id,
                             l_memBus->device.memChannel, l_memBus->type, l_memBus->interface, i_interface);

                    {
                        // For adding 'new' record, default value of failBit field should be zero
                        l_memBus->failBit = 0;
                        uint32_t temp = (uint32_t)(l_memBus->failBit);
                        uint32_t* tptr = &temp;
                        FAPI_INF("Status(before):FailBit:0x%x temp:0x%x ", l_memBus->failBit, temp);
                        FAPI_TRY( gatherRepairLanes(
                                      i_target,
                                      l_memBus->interface,
                                      l_repairLane,
                                      tptr),
                                  "gatherRepairLanes() failed w/rc=0x%x",
                                  static_cast<uint64_t>(fapi2::current_err) );
                        l_memBus->failBit = temp;
                        FAPI_INF("Status(after):FailBit:0x%x temp:0x%x ", l_memBus->failBit, temp);
                    }

                    FAPI_INF("DMI Bus(after update):Dev:%d Bus:%d Type:%d MemIF:%d IF:%d FailBit:0x%x ", l_memBus->device.proc_centaur_id,
                             l_memBus->device.memChannel, l_memBus->type, l_memBus->interface, i_interface, l_memBus->failBit);

                    // Get the record added
                    FAPI_INF("Record added: ");

                    for(uint8_t i = 0; i < RECORD_LENGTH_BYTES; i++)
                    {
                        FAPI_INF("%02x ", *(l_vpdDataPtr + i));
                    }

                    l_newNumRepairs++;

                    // Increment the count of parsed bytes
                    l_bytesParsed += l_repairDataSz;
#ifndef _BIG_ENDIAN
                    // We are on a Little Endian system.
                    // Need to swap the nibbles of structure - eRepairMemBus

                    l_vpdWritePtr[2] = ((l_vpdWritePtr[2] >> 4) |
                                        (l_vpdWritePtr[2] << 4));
#endif
                }
            } // end of if(l_overWrite == false)
        } // end of for(failLanes)
    }

    // Update the eRepair count
    l_vpdHeadPtr->availNumRecord = l_newNumRepairs;
    FAPI_INF("Result:NumRec:%d ", l_vpdHeadPtr->availNumRecord);

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Function called by the FW Team HWP that writes the data to Field VPD.
 *        This function calls fapiSetMvpdField to write the VPD.
 *
 * @param[in] i_target      Reference to X-Bus target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_txFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[in] i_rxFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Rx sub-interface.
 * (For Proc)
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode writeRepairDataToVPDProc(
    const fapi2::Target < K >&           i_target,
    EREPAIR::erepairVpdType              i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes)
{
    fapi2::ReturnCode l_rc                                       = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err                                           = fapi2::FAPI2_RC_SUCCESS;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>                  l_procTarget;

    uint8_t* l_retBuf    = NULL;
    uint32_t l_bufSize   = 0;
    uint32_t l_serialNum = 0;
    uint8_t* l_serialBuf = NULL;
    FAPI_INF(">> writeRepairDataToVPD - Proc - RxLaneSize:%llu TxLaneSize:%llu ", i_rxFailLanes.size(),
             i_txFailLanes.size());

    {
        // Determine the Processor target
        l_procTarget = i_target.template getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        fapi2::MvpdRecord l_vpdRecord = fapi2::MVPD_RECORD_VWML;

        if(i_vpdType == EREPAIR::EREPAIR_VPD_MNFG)
        {
            l_vpdRecord = fapi2::MVPD_RECORD_MER0;
        }

        /*** Read the data from the Module VPD ***/

        // Determine the serial number to uniquely identify the proc
        FAPI_TRY( getMvpdField(
                      fapi2::MVPD_RECORD_VINI,
                      fapi2::MVPD_KEYWORD_SN,
                      l_procTarget,
                      NULL,
                      l_serialNum),
                  "Serial number size read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        FAPI_INF("Serial number size:0x%08x ", l_serialNum);

        if( l_serialNum )
        {
            // Allocate memory for buffer
            l_serialBuf = new uint8_t[l_serialNum]();

            // Retrieve the serial number data from the MVPD
            FAPI_TRY( getMvpdField(
                          fapi2::MVPD_RECORD_VINI,
                          fapi2::MVPD_KEYWORD_SN,
                          l_procTarget,
                          l_serialBuf,
                          l_serialNum),
                      "Serial number read failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );

            FAPI_INF("Serial Number: ");

            for(uint32_t i = 0; i < l_serialNum; i++)
            {
                FAPI_INF("%02x ", *(l_serialBuf + i));
            }
        }

        // Determine the size of the eRepair data in the VPD
        FAPI_TRY( getMvpdField(
                      l_vpdRecord,
                      fapi2::MVPD_KEYWORD_PDI,
                      l_procTarget,
                      NULL,
                      l_bufSize),
                  "VPD size read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        FAPI_INF("VPD data:RC:0x%x KW:0x%x BS:%d ", l_vpdRecord, fapi2::MVPD_KEYWORD_PDI, l_bufSize);

        if((l_bufSize == 0) ||
           ((i_vpdType == EREPAIR::EREPAIR_VPD_FIELD) &&
            (l_bufSize > EREPAIR::EREPAIR_P9_MODULE_VPD_FIELD_SIZE)) ||
           ((i_vpdType == EREPAIR::EREPAIR_VPD_MNFG) &&
            (l_bufSize > EREPAIR::EREPAIR_P9_MODULE_VPD_MNFG_SIZE)))
        {
            FAPI_ASSERT(false,
                        fapi2::P9_EREPAIR_ACCESSOR_HWP_INVALID_FABRIC_VPD_SIZE_ERR()
                        .set_VAL_BUF_SIZE(l_bufSize)
                        .set_ERROR(fapi2::current_err),
                        "ERROR: Invalid Fabric VPD size");
        }

        // Allocate memory for buffer
        l_retBuf = new uint8_t[l_bufSize]();

        FAPI_ASSERT(l_retBuf != NULL,
                    fapi2::P9_EREPAIR_ACCESSOR_HWP_MEMORY_ALLOC_FAIL_ERR()
                    .set_BUF_SIZE(l_bufSize),
                    "ERROR: Failed to allocate fabric memory size");

        // Retrieve the Field eRepair data from the MVPD
        FAPI_TRY( getMvpdField(
                      l_vpdRecord,
                      fapi2::MVPD_KEYWORD_PDI,
                      l_procTarget,
                      l_retBuf,
                      l_bufSize),
                  "VPD read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        if(i_txFailLanes.size())
        {
            /*** Lets update the tx side fail lane vector to the VPD ***/
            FAPI_TRY( updateRepairLanesToBufProc(
                          i_target,
                          EREPAIR::DRIVE,
                          l_bufSize,
                          i_clkGroup,
                          i_txFailLanes,
                          l_retBuf),
                      "updateRepairLanesToBufProc(DRIVE) failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );
        }

        if(i_rxFailLanes.size())
        {
            /*** Lets update the rx side fail lane vector to the VPD ***/
            FAPI_TRY( updateRepairLanesToBufProc(
                          i_target,
                          EREPAIR::RECEIVE,
                          l_bufSize,
                          i_clkGroup,
                          i_rxFailLanes,
                          l_retBuf),
                      "updateRepairLanesToBufProc(RECEIVE) failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );
        }

        FAPI_INF("Set VPD data:RC:0x%x KW:0x%x BS:%d ", l_vpdRecord, fapi2::MVPD_KEYWORD_PDI, l_bufSize);
        /*** Write the updated eRepair buffer back to MVPD ***/
        FAPI_TRY( setMvpdField(
                      l_vpdRecord,
                      fapi2::MVPD_KEYWORD_PDI,
                      l_procTarget,
                      l_retBuf,
                      l_bufSize),
                  "setMvpdField()-Update erepair data to VPD failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );
    }

fapi_try_exit:
    // Delete the buffer which has Field eRepair data
    delete[] l_retBuf;
    delete[] l_serialBuf;

    return fapi2::current_err;
}

/**
 * @brief Function called by the FW Team HWP that writes the data to Field VPD.
 *        This function calls fapiSetMvpdField to write the VPD.
 *
 * @param[in] i_target      Reference to MEMBUF target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_txFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[in] i_rxFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Rx sub-interface.
 * (For MemBuf)
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode writeRepairDataToVPDMemBuf(
    const fapi2::Target < K >&           i_target,
    EREPAIR::erepairVpdType                     i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes)
{
    fapi2::ReturnCode l_rc                                       = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err                                           = fapi2::FAPI2_RC_SUCCESS;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MBA_CHIPLET>>   l_mbaChiplets;
    fapi2::Target<fapi2::TARGET_TYPE_MBA>                        l_mbaTarget;

    uint8_t* l_retBuf    = NULL;
    size_t   l_mBufSize  = 0;
    uint8_t* l_serialBuf = NULL;
    size_t   l_serialNum = 0;
    uint8_t    l_customDimm = 0xFF;    // Initialized to invalid value
    FAPI_INF(">> writeRepairDataToVPD - MemBuf - RxLaneSize:%llu TxLaneSize:%llu ", i_rxFailLanes.size(),
             i_txFailLanes.size());

    {
        fapi2::MBvpdRecord l_vpdRecord = fapi2::MBVPD_RECORD_VEIR;

        if(i_vpdType == EREPAIR::EREPAIR_VPD_MNFG)
        {
            l_vpdRecord = fapi2::MBVPD_RECORD_MER0;
        }

        /*** Read the data from the FRU VPD ***/

        // Determine the serial number to uniquely identify centaur vpd
        FAPI_TRY( getMBvpdField(
                      fapi2::MBVPD_RECORD_VINI,
                      fapi2::MBVPD_KEYWORD_SN,
                      i_target,
                      NULL,
                      l_serialNum),
                  "Serial number size read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        FAPI_INF("Serial number size:0x%08x ", l_serialNum);

        if( l_serialNum )
        {
            // Allocate memory for buffer
            l_serialBuf = new uint8_t[l_serialNum]();

            // Retrieve the serial number data from the MVPD
            FAPI_TRY( getMBvpdField(
                          fapi2::MBVPD_RECORD_VINI,
                          fapi2::MBVPD_KEYWORD_SN,
                          i_target,
                          l_serialBuf,
                          l_serialNum),
                      "Serial number read failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );

            FAPI_INF("Serial Number: ");

            for(size_t i = 0; i < l_serialNum; i++)
            {
                FAPI_INF("%02x ", *(l_serialBuf + i));
            }
        }

        // Determine the size of the eRepair data in the Centaur VPD
        FAPI_TRY( getMBvpdField(
                      l_vpdRecord,
                      fapi2::MBVPD_KEYWORD_PDI,
                      i_target,
                      NULL,
                      l_mBufSize),
                  "VPD size read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        FAPI_INF("VPD data:RC:0x%x KW:0x%x BS:%d ", l_vpdRecord, fapi2::MBVPD_KEYWORD_PDI, l_mBufSize);

        // Get the connected MBA chiplet and determine whether we have CDIMM
        l_mbaChiplets = i_target.template getChildren<fapi2::TARGET_TYPE_MBA_CHIPLET>
                        (fapi2::TARGET_STATE_FUNCTIONAL);

        FAPI_ASSERT( 0 != l_mbaChiplets.size(),
                     fapi2::P9_EREPAIR_CHILD_MBA_TARGETS_ERR()
                     .set_VAL_CHIPLET(l_mbaChiplets),
                     "ERROR: During get child MBA targets");

        l_mbaTarget = l_mbaChiplets[0];
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_target_dimm_array;

        l_target_dimm_array = l_mbaTarget.getChildren<fapi2::TARGET_TYPE_DIMM>
                              (fapi2::TARGET_STATE_FUNCTIONAL);

        if(0 != l_target_dimm_array.size())
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM,
                                   l_target_dimm_array[0],
                                   l_customDimm));
        }
        else
        {
            l_customDimm = fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO;
        }

        FAPI_INF("CustomDimm:(%d)%s \n", l_customDimm,
                 (l_customDimm == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_NO ? "CEN_SPD_CUSTOM_NO" : "CEN_SPD_CUSTOM_YES"));

        // Check for mem buf size
        FAPI_ASSERT(l_mBufSize > 0,
                    fapi2::P9_EREPAIR_ACCESSOR_HWP_INVALID_MEM_VPD_SIZE_ERR()
                    .set_VAL_BUF_SIZE(l_mBufSize)
                    .set_ERROR(fapi2::current_err),
                    "ERROR: Invalid MEM VPD size");

        // Allocate memory for buffer
        l_retBuf = new uint8_t[l_mBufSize]();

        FAPI_ASSERT(l_retBuf != NULL,
                    fapi2::P9_EREPAIR_ACCESSOR_HWP_MEMORY_ALLOC_FAIL_ERR()
                    .set_BUF_SIZE(l_mBufSize),
                    "ERROR: Failed to allocate memory size");

        // Retrieve the Field eRepair data from the Centaur FRU VPD
        FAPI_TRY( getMBvpdField(
                      l_vpdRecord,
                      fapi2::MBVPD_KEYWORD_PDI,
                      i_target,
                      l_retBuf,
                      l_mBufSize),
                  "Centaur FRU VPD read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        if(i_txFailLanes.size())
        {
            /*** Lets update the tx side fail lane vector to the VPD ***/
            FAPI_TRY( updateRepairLanesToBufMemBuf(
                          i_target,
                          EREPAIR::DRIVE,
                          l_mBufSize,
                          i_clkGroup,
                          i_txFailLanes,
                          l_customDimm,
                          l_retBuf),
                      "updateRepairLanesToBufMemBuf(DRIVE) failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );
        }

        if(i_rxFailLanes.size())
        {
            /*** Lets update the rx side fail lane vector to the VPD ***/
            FAPI_TRY( updateRepairLanesToBufMemBuf(
                          i_target,
                          EREPAIR::RECEIVE,
                          l_mBufSize,
                          i_clkGroup,
                          i_rxFailLanes,
                          l_customDimm,
                          l_retBuf),
                      "updateRepairLanesToBufMemBuf(RECEIVE) failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );
        }

        FAPI_INF("Set VPD data:RC:0x%x KW:0x%x BS:%d ", l_vpdRecord, fapi2::MBVPD_KEYWORD_PDI, l_mBufSize);
        /*** Write the updated eRepair buffer back to Centaur FRU VPD ***/
        FAPI_TRY( setMBvpdField(
                      l_vpdRecord,
                      fapi2::MBVPD_KEYWORD_PDI,
                      i_target,
                      l_retBuf,
                      l_mBufSize),
                  "Update erepair data to VPD failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );
    }

fapi_try_exit:
    // Delete the buffer which has Field eRepair data
    delete[] l_retBuf;
    delete[] l_serialBuf;

    return fapi2::current_err;
}

/**
 * @brief Function called by the FW Team HWP that writes the data to Field VPD.
 *        This function calls fapiSetMvpdField to write the VPD.
 *
 * @param[in] i_target      Reference to DMI target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_txFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[in] i_rxFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Rx sub-interface.
 * (For DMI)
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode writeRepairDataToVPDDMI(
    const fapi2::Target < K >&           i_target,
    EREPAIR::erepairVpdType                     i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes)
{
    fapi2::ReturnCode l_rc                                       = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err                                           = fapi2::FAPI2_RC_SUCCESS;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>                  l_procTarget;

    uint8_t* l_retBuf    = NULL;
    uint32_t l_bufSize   = 0;
    uint8_t* l_serialBuf = NULL;
    uint32_t l_serialNum = 0;
    FAPI_INF(">> writeRepairDataToVPD - DMI - RxLaneSize:%llu TxLaneSize:%llu ", i_rxFailLanes.size(),
             i_txFailLanes.size());

    {
        // Determine the Processor target
        l_procTarget = i_target.template getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        fapi2::MvpdRecord l_vpdRecord = fapi2::MVPD_RECORD_VWML;

        if(i_vpdType == EREPAIR::EREPAIR_VPD_MNFG)
        {
            l_vpdRecord = fapi2::MVPD_RECORD_MER0;
        }

        /*** Read the data from the Module VPD ***/

        // Determine the serial number to uniquely identify the proc
        FAPI_TRY( getMvpdField(
                      fapi2::MVPD_RECORD_VINI,
                      fapi2::MVPD_KEYWORD_SN,
                      l_procTarget,
                      NULL,
                      l_serialNum),
                  "Serial number size read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        FAPI_INF("Serial number size:0x%08x ", l_serialNum);

        if( l_serialNum )
        {
            // Allocate memory for buffer
            l_serialBuf = new uint8_t[l_serialNum]();

            // Retrieve the serial number data from the MVPD
            FAPI_TRY( getMvpdField(
                          fapi2::MVPD_RECORD_VINI,
                          fapi2::MVPD_KEYWORD_SN,
                          l_procTarget,
                          l_serialBuf,
                          l_serialNum),
                      "Serial number read failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );

            FAPI_INF("Serial Number: ");

            for(uint32_t i = 0; i < l_serialNum; i++)
            {
                FAPI_INF("%02x ", *(l_serialBuf + i));
            }
        }

        // Determine the size of the eRepair data in the VPD
        FAPI_TRY( getMvpdField(
                      l_vpdRecord,
                      fapi2::MVPD_KEYWORD_PDI,
                      l_procTarget,
                      NULL,
                      l_bufSize),
                  "VPD size read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        FAPI_INF("VPD data:RC:0x%x KW:0x%x BS:%d ", l_vpdRecord, fapi2::MVPD_KEYWORD_PDI, l_bufSize);

        if((l_bufSize == 0) ||
           ((i_vpdType == EREPAIR::EREPAIR_VPD_FIELD) &&
            (l_bufSize > EREPAIR::EREPAIR_P9_MODULE_VPD_FIELD_SIZE)) ||
           ((i_vpdType == EREPAIR::EREPAIR_VPD_MNFG) &&
            (l_bufSize > EREPAIR::EREPAIR_P9_MODULE_VPD_MNFG_SIZE)))
        {
            FAPI_ASSERT(false,
                        fapi2::P9_EREPAIR_ACCESSOR_HWP_INVALID_FABRIC_VPD_SIZE_ERR()
                        .set_VAL_BUF_SIZE(l_bufSize)
                        .set_ERROR(fapi2::current_err),
                        "ERROR: Invalid Fabric VPD (DMI) size");
        }

        // Allocate memory for buffer
        l_retBuf = new uint8_t[l_bufSize]();

        FAPI_ASSERT(l_retBuf != NULL,
                    fapi2::P9_EREPAIR_ACCESSOR_HWP_MEMORY_ALLOC_FAIL_ERR()
                    .set_BUF_SIZE(l_bufSize),
                    "ERROR: Failed to allocate memory (DMI) size");

        // Retrieve the Field eRepair data from the MVPD
        FAPI_TRY( getMvpdField(
                      l_vpdRecord,
                      fapi2::MVPD_KEYWORD_PDI,
                      l_procTarget,
                      l_retBuf,
                      l_bufSize),
                  "VPD read failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );

        if(i_txFailLanes.size())
        {
            /*** Lets update the tx side fail lane vector to the VPD ***/
            FAPI_TRY( updateRepairLanesToBufDMI(
                          i_target,
                          EREPAIR::DRIVE,
                          l_bufSize,
                          i_clkGroup,
                          i_txFailLanes,
                          l_retBuf),
                      "updateRepairLanesToBufDMI(DRIVE) failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );
        }

        if(i_rxFailLanes.size())
        {
            /*** Lets update the rx side fail lane vector to the VPD ***/
            FAPI_TRY( updateRepairLanesToBufDMI(
                          i_target,
                          EREPAIR::RECEIVE,
                          l_bufSize,
                          i_clkGroup,
                          i_rxFailLanes,
                          l_retBuf),
                      "updateRepairLanesToBufDMI(RECEIVE) failed w/rc=0x%x",
                      static_cast<uint64_t>(fapi2::current_err) );
        }

        FAPI_INF("Set VPD data:RC:0x%x KW:0x%x BS:%d ", l_vpdRecord, fapi2::MVPD_KEYWORD_PDI, l_bufSize);
        /*** Write the updated eRepair buffer back to MVPD ***/
        FAPI_TRY( setMvpdField(
                      l_vpdRecord,
                      fapi2::MVPD_KEYWORD_PDI,
                      l_procTarget,
                      l_retBuf,
                      l_bufSize),
                  "setMvpdField()-Update erepair data to VPD failed w/rc=0x%x",
                  static_cast<uint64_t>(fapi2::current_err) );
    }

fapi_try_exit:
    // Delete the buffer which has Field eRepair data
    delete[] l_retBuf;
    delete[] l_serialBuf;

    return fapi2::current_err;
}

/**
 * @brief Function called by the FW Team HWP that sets the failed lanes to VPD.
 *
 * @param[in] i_target      Reference to X-Bus DMI target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_txFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[in] i_rxFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Rx sub-interface.
 * (For Proc)
 * @return ReturnCode
 */
fapi2::ReturnCode p9_io_erepairSetFailedLanesHwp(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&           i_target,
    EREPAIR::erepairVpdType            i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(">> erepairSetFailedLanesHwp for XBUS - RxLaneSize:%llu TxLaneSize:%llu ", i_rxFailLanes.size(),
             i_txFailLanes.size());
    FAPI_INF("VPD Type:%d Clk Group:%d ", i_vpdType, i_clkGroup);

    for(unsigned long i = 0; (i < i_rxFailLanes.size() && i_rxFailLanes.size() != 0); i++)
    {
        FAPI_INF("Rx(%lu):%llu ", i, i_rxFailLanes[i]);
    }

    for(unsigned long i = 0; (i < i_txFailLanes.size() && i_txFailLanes.size() != 0); i++)
    {
        FAPI_INF("Tx(%lu):%llu ", i, i_txFailLanes[i]);
    }


    FAPI_ASSERT(( (i_txFailLanes.size() != 0) || (i_rxFailLanes.size() != 0) ),
                fapi2::P9_EREPAIR_NO_RX_TX_FAILED_LANES_ERR()
                .set_TX_LANE(i_txFailLanes.size()).set_RX_LANE(i_rxFailLanes.size()),
                "ERROR: No Tx/Rx fail lanes were provided");

    FAPI_TRY( writeRepairDataToVPDProc(
                  i_target,
                  i_vpdType,
                  i_clkGroup,
                  i_txFailLanes,
                  i_rxFailLanes),
              "writeRepairDataToVPDProc() failed w/rc=0x%x",
              static_cast<uint64_t>(fapi2::current_err) );

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Function called by the FW Team HWP that sets the failed lanes to VPD.
 *
 * @param[in] i_target      Reference to MEMBuf target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_txFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[in] i_rxFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Rx sub-interface.
 * (For MemBuf)
 * @return ReturnCode
 */
fapi2::ReturnCode p9_io_erepairSetFailedLanesHwp(
    const fapi2::Target < fapi2::TARGET_TYPE_MEMBUF_CHIP >&           i_target,
    EREPAIR::erepairVpdType            i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(">> erepairSetFailedLanesHwp for MemBuf - RxLaneSize:%llu TxLaneSize:%llu ", i_rxFailLanes.size(),
             i_txFailLanes.size());
    FAPI_INF("VPD Type:%d ", i_vpdType);

    for(unsigned long i = 0; (i < i_rxFailLanes.size() && i_rxFailLanes.size() != 0); i++)
    {
        FAPI_INF("Rx(%lu):%llu ", i, i_rxFailLanes[i]);
    }

    for(unsigned long i = 0; (i < i_txFailLanes.size() && i_txFailLanes.size() != 0); i++)
    {
        FAPI_INF("Tx(%lu):%llu ", i, i_txFailLanes[i]);
    }


    FAPI_ASSERT(( (i_txFailLanes.size() != 0) || (i_rxFailLanes.size() != 0) ),
                fapi2::P9_EREPAIR_NO_RX_TX_FAILED_LANES_ERR()
                .set_TX_LANE(i_txFailLanes.size()).set_RX_LANE(i_rxFailLanes.size()),
                "ERROR: No Tx/Rx fail lanes were provided");

    FAPI_TRY( writeRepairDataToVPDMemBuf(
                  i_target,
                  i_vpdType,
                  i_clkGroup,
                  i_txFailLanes,
                  i_rxFailLanes),
              "writeRepairDataToVPDMemBuf() failed w/rc=0x%x",
              static_cast<uint64_t>(fapi2::current_err) );

fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Function called by the FW Team HWP that sets the failed lanes to VPD.
 *
 * @param[in] i_target      Reference to DMI target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_txFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[in] i_rxFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 */
fapi2::ReturnCode p9_io_erepairSetFailedLanesHwp(
    const fapi2::Target < fapi2::TARGET_TYPE_DMI >&           i_target,
    EREPAIR::erepairVpdType            i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(">> erepairSetFailedLanesHwp for DMI - RxLaneSize:%llu TxLaneSize:%llu ", i_rxFailLanes.size(),
             i_txFailLanes.size());
    FAPI_INF("VPD Type:%d ", i_vpdType);

    for(unsigned long i = 0; (i < i_rxFailLanes.size() && i_rxFailLanes.size() != 0); i++)
    {
        FAPI_INF("Rx(%lu):%llu ", i, i_rxFailLanes[i]);
    }

    for(unsigned long i = 0; (i < i_txFailLanes.size() && i_txFailLanes.size() != 0); i++)
    {
        FAPI_INF("Tx(%lu):%llu ", i, i_txFailLanes[i]);
    }

    FAPI_ASSERT(( (i_txFailLanes.size() != 0) || (i_rxFailLanes.size() != 0) ),
                fapi2::P9_EREPAIR_NO_RX_TX_FAILED_LANES_ERR()
                .set_TX_LANE(i_txFailLanes.size()).set_RX_LANE(i_rxFailLanes.size()),
                "ERROR: No Tx/Rx fail lanes were provided");

    FAPI_TRY( writeRepairDataToVPDDMI(
                  i_target,
                  i_vpdType,
                  i_clkGroup,
                  i_txFailLanes,
                  i_rxFailLanes),
              "writeRepairDataToVPDDMI() failed w/rc=0x%x",
              static_cast<uint64_t>(fapi2::current_err) );

fapi_try_exit:
    return fapi2::current_err;
}

#endif
