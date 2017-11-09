/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_erepairSetFailedLanesHwp.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_io_erepairSetFailedLanesHwp.C
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

#include <fapi2.H>
#include <p9_io_erepairConsts.H>
#include <p9_io_erepairSetFailedLanesHwp.H>
#include <mvpd_access.H>

using namespace EREPAIR;
using namespace fapi2;

/******************************************************************************
 * Forward Declarations
 *****************************************************************************/

/**
 * @brief Function called by the FW Team HWP that writes the data to Field VPD.
 *        This function calls fapiSetMvpdField to write the VPD.
 *
 * @param[in] i_target      Reference to X-Bus or O-Bus or MCS target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_txFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[in] i_rxFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode writeRepairDataToVPD(
    const fapi2::Target < K >&           i_target,
    erepairVpdType                     i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes);

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers.
 *
 * @param[in] i_target      Reference to X-Bus or O-Bus or MCS target
 * @param[in] i_txFailLanes Reference to a vector that has the Tx side faillane
 *                          numbers that need to be updated to the o_buf buffer
 * @param[in] i_rxFailLanes Reference to a vector that has the Rx side faillane
 *                          numbers that need to be updated to the o_buf buffer
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[o]  o_buf         This is the buffer that has the eRepair records
 *                          that needs to be written to the VPD
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode writeRepairLanesToBuf(
    const fapi2::Target < K >&           i_target,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes,
    const uint32_t                     i_bufSz,
    const uint8_t                      i_clkGroup,
    uint8_t*                           o_buf);

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers of a specified interface.
 *
 * @param[in] i_target      Reference to X-Bus or O-Bus or MCS target
 * @param[in] i_interface   This indicates the sub-interface type the passed
 *                          faillane vector represents
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[in] i_failLanes   Reference to a vector that has the faillane numbers
 *                          that need to be updated to the o_buf buffer
 * @param[o]  o_buf         This is the buffer that has the eRepair records
 *                          that needs to be written to the VPD
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode updateRepairLanesToBuf(
    const fapi2::Target < K >&           i_target,
    const interfaceType                i_interface,
    const uint32_t                     i_bufSz,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_failLanes,
    uint8_t*                           o_buf);

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers of a specified interface.
 *
 * @param[in] i_target       Reference to X-Bus or O-Bus or MCS target
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
    uint8_t                  i_busInterface,
    uint8_t                  i_repairLane,
    uint32_t*                 o_failBit);


/******************************************************************************
 * Accessor HWP
 *****************************************************************************/

template<fapi2::TargetType K>
fapi2::ReturnCode p9_io_erepairSetFailedLanesHwp(
    const fapi2::Target < K >&           i_target,
    erepairVpdType                     i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::Target<fapi2::TARGET_TYPE_MCS>     l_mcsTgt;

    FAPI_INF(">> erepairSetFailedLanesHwp");

    FAPI_ASSERT(( (i_txFailLanes.size() != 0) || (i_rxFailLanes.size() != 0) ),
                fapi2::P9_EREPAIR_NO_RX_TX_FAILED_LANES_ERR()
                .set_TX_LANE(i_txFailLanes.size()).set_RX_LANE(i_rxFailLanes.size()),
                "ERROR: No Tx/Rx fail lanes were provided");

    FAPI_TRY( writeRepairDataToVPD(
                  i_target,
                  i_vpdType,
                  i_clkGroup,
                  i_txFailLanes,
                  i_rxFailLanes),
              "p9_io_erepairSetFailedLanesHwp() failed w/rc=0x%x",
              (uint64_t)current_err );

fapi_try_exit:
    return fapi2::current_err;
}

template ReturnCode p9_io_erepairSetFailedLanesHwp<TARGET_TYPE_XBUS>(
    const fapi2::Target <TARGET_TYPE_XBUS>&          i_target,
    erepairVpdType                    i_vpdType,
    const uint8_t                     i_clkGroup,
    const std::vector<uint8_t>&             o_txFailLanes,
    const std::vector<uint8_t>&             o_rxFailLanes);

template<fapi2::TargetType K>
fapi2::ReturnCode writeRepairDataToVPD(
    const fapi2::Target < K >&           i_target,
    erepairVpdType                     i_vpdType,
    const uint8_t                      i_clkGroup,
    const std::vector<uint8_t>&        i_txFailLanes,
    const std::vector<uint8_t>&        i_rxFailLanes)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>                l_procTarget;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MBA_CHIPLET>> l_mbaChiplets;
    fapi2::Target<fapi2::TARGET_TYPE_MBA>                      l_mbaTarget;

    uint8_t*    l_retBuf = NULL;
    uint32_t   l_bufSize = 0;
#ifdef P9_CUMULUS
    uint8_t    l_customDimm;
#endif
    FAPI_DBG(">> writeRepairDataToVPD");

    if(i_target.getType() == TARGET_TYPE_MEMBUF_CHIP)
    {
#ifdef P9_CUMULUS
        fapi2::MBvpdRecord l_vpdRecord = MBVPD_RECORD_VEIR;

        if(i_vpdType == EREPAIR_VPD_MNFG)
        {
            l_vpdRecord = MBVPD_RECORD_MER0;
        }

        /*** Read the data from the FRU VPD ***/

        // Determine the size of the eRepair data in the Centaur VPD
        FAPI_TRY( getMBvpdField(
                      l_vpdRecord,
                      MBVPD_KEYWORD_PDI,
                      i_target,
                      NULL,
                      l_bufSize),
                  "VPD size read failed w/rc=0x%x",
                  (uint64_t)current_err );

        // Get the connected MBA chiplet and determine whether we have CDIMM
        l_rc = fapiGetChildChiplets(i_target,
                                    fapi2::TARGET_TYPE_MBA_CHIPLET,
                                    l_mbaChiplets,
                                    fapi2::TARGET_STATE_FUNCTIONAL);

        FAPI_ASSERT( ((uint64_t)l_rc == 0x0) || (0 != l_mbaChiplets.size()),
                     fapi2::P9_EREPAIR_CHILD_MBA_TARGETS_ERR()
                     .set_ERROR(l_rc),
                     "ERROR: During get child MBA targets");

        l_mbaTarget = l_mbaChiplets[0];
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_target_dimm_array;

        FAPI_TRY( fapiGetAssociatedDimms(
                      l_mbaTarget,
                      l_target_dimm_array),
                  "fapiGetAssociatedDimms() failed w/rc=0x%x",
                  (uint64_t)current_err );

        if(0 != l_target_dimm_array.size())
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SPD_CUSTOM,
                                   l_target_dimm_array[0],
                                   l_customDimm));
        }
        else
        {
            l_customDimm = fapi2::ENUM_ATTR_SPD_CUSTOM_NO;
        }

        if( (l_customDimm == fapi2::ENUM_ATTR_SPD_CUSTOM_YES) || (l_bufSize == 0) )
        {
            if((l_bufSize == 0) ||
               ((i_vpdType == EREPAIR_VPD_FIELD) &&
                (l_bufSize > EREPAIR_MEM_FIELD_VPD_SIZE_PER_CENTAUR)) ||
               ((i_vpdType == EREPAIR_VPD_MNFG) &&
                (l_bufSize > EREPAIR_MEM_MNFG_VPD_SIZE_PER_CENTAUR)))
            {
                FAPI_ASSERT(false,
                            fapi2::P9_EREPAIR_ACCESSOR_HWP_INVALID_MEM_VPD_SIZE_ERR()
                            .set_ERROR(current_err),
                            "ERROR: Invalid MEM VPD size");
            }
        }

        // Allocate memory for buffer
        l_retBuf = new uint8_t[l_bufSize];

        FAPI_ASSERT(l_retBuf != NULL,
                    fapi2::P9_EREPAIR_ACCESSOR_HWP_MEMORY_ALLOC_FAIL_ERR()
                    .set_BUF_SIZE(l_bufSize),
                    "ERROR: Failed to allocate memory size");

        // Retrieve the Field eRepair data from the Centaur FRU VPD
        FAPI_TRY( getMBvpdField(
                      l_vpdRecord,
                      MBVPD_KEYWORD_PDI,
                      i_target,
                      l_retBuf,
                      l_bufSize),
                  "Centaur FRU VPD read failed w/rc=0x%x",
                  (uint64_t)current_err );

        /*** Update the new eRepair data to the buffer ***/
        FAPI_TRY( writeRepairLanesToBuf(
                      i_target,
                      i_txFailLanes,
                      i_rxFailLanes,
                      l_bufSize,
                      i_clkGroup,
                      l_retBuf),
                  "Update erepair data to buffer failed w/rc=0x%x",
                  (uint64_t)current_err );

        /*** Write the updated eRepair buffer back to Centaur FRU VPD ***/
        FAPI_TRY( setMBvpdField(
                      l_vpdRecord,
                      MBVPD_KEYWORD_PDI,
                      i_target,
                      l_retBuf,
                      l_bufSize),
                  "Update erepair data to VPD failed w/rc=0x%x",
                  (uint64_t)current_err );
#endif
    } // end of(targetType == MEMBUF)
    else
    {
        // Determine the Processor target
        l_procTarget = i_target.template getParent<TARGET_TYPE_PROC_CHIP>();

        fapi2::MvpdRecord l_vpdRecord = MVPD_RECORD_VWML;

        if(i_vpdType == EREPAIR_VPD_MNFG)
        {
            l_vpdRecord = MVPD_RECORD_MER0;
        }

        /*** Read the data from the Module VPD ***/

        // Determine the size of the eRepair data in the VPD
        FAPI_TRY( getMvpdField(
                      l_vpdRecord,
                      MVPD_KEYWORD_PDI,
                      l_procTarget,
                      NULL,
                      l_bufSize),
                  "VPD size read failed w/rc=0x%x",
                  (uint64_t)current_err );

        if((l_bufSize == 0) ||
           ((i_vpdType == EREPAIR_VPD_FIELD) &&
            (l_bufSize > EREPAIR_P9_MODULE_VPD_FIELD_SIZE)) ||
           ((i_vpdType == EREPAIR_VPD_MNFG) &&
            (l_bufSize > EREPAIR_P9_MODULE_VPD_MNFG_SIZE)))
        {
            FAPI_ASSERT(false,
                        fapi2::P9_EREPAIR_ACCESSOR_HWP_INVALID_FABRIC_VPD_SIZE_ERR()
                        .set_ERROR(current_err),
                        "ERROR: Invalid Fabric VPD size");
        }

        // Allocate memory for buffer
        l_retBuf = new uint8_t[l_bufSize];

        FAPI_ASSERT(l_retBuf != NULL,
                    fapi2::P9_EREPAIR_ACCESSOR_HWP_MEMORY_ALLOC_FAIL_ERR()
                    .set_BUF_SIZE(l_bufSize),
                    "ERROR: Failed to allocate memory size");

        // Retrieve the Field eRepair data from the MVPD
        FAPI_TRY( getMvpdField(
                      l_vpdRecord,
                      MVPD_KEYWORD_PDI,
                      l_procTarget,
                      l_retBuf,
                      l_bufSize),
                  "VPD read failed w/rc=0x%x",
                  (uint64_t)current_err );

        /*** Update the new eRepair data to the buffer ***/
        FAPI_TRY( writeRepairLanesToBuf(
                      i_target,
                      i_txFailLanes,
                      i_rxFailLanes,
                      l_bufSize,
                      i_clkGroup,
                      l_retBuf),
                  "writeRepairLanesToBuf() failed w/rc=0x%x",
                  (uint64_t)current_err );

        /*** Write the updated eRepair buffer back to MVPD ***/
        FAPI_TRY( setMvpdField(
                      l_vpdRecord,
                      MVPD_KEYWORD_PDI,
                      l_procTarget,
                      l_retBuf,
                      l_bufSize),
                  "setMvpdField()-Update erepair data to VPD failed w/rc=0x%x",
                  (uint64_t)current_err );
    }

    // Delete the buffer which has Field eRepair data
    delete[] l_retBuf;

fapi_try_exit:
    return fapi2::current_err;
}


template<fapi2::TargetType K>
fapi2::ReturnCode writeRepairLanesToBuf(
    const fapi2::Target < K >&           i_target,
    const std::vector<uint8_t>& i_txFailLanes,
    const std::vector<uint8_t>& i_rxFailLanes,
    const uint32_t              i_bufSz,
    const uint8_t               i_clkGroup,
    uint8_t*                    o_buf)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_DBG(">> writeRepairLanesToBuf");

    if(i_txFailLanes.size())
    {
        /*** Lets update the tx side fail lane vector to the VPD ***/
        FAPI_TRY( updateRepairLanesToBuf(
                      i_target,
                      DRIVE,
                      i_bufSz,
                      i_clkGroup,
                      i_txFailLanes,
                      o_buf),
                  "updateRepairLanesToBuf(DRIVE) failed w/rc=0x%x",
                  (uint64_t)current_err );
    }

    if(i_rxFailLanes.size())
    {
        /*** Lets update the rx side fail lane vector to the VPD ***/
        FAPI_TRY( updateRepairLanesToBuf(
                      i_target,
                      RECEIVE,
                      i_bufSz,
                      i_clkGroup,
                      i_rxFailLanes,
                      o_buf),
                  "updateRepairLanesToBuf(RECEIVE) failed w/rc=0x%x",
                  (uint64_t)current_err );
    }

fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K>
fapi2::ReturnCode updateRepairLanesToBuf(
    const fapi2::Target < K >&           i_target,
    const interfaceType        i_interface,
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
    bool             l_bClkGroupFound       = false;
#ifdef P9_CUMULUS
    fapi2::Target<fapi2::TARGET_TYPE_MCS>   l_mcsTarget;
#endif
    std::vector<uint8_t>::const_iterator l_it;
    ATTR_CHIP_UNIT_POS_Type l_busNum;

    FAPI_DBG(">> updateRepairLanesToBuf, interface: %s",
             i_interface == DRIVE ? "Drive" : "Receive");

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

        if(i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP)
        {
#ifdef P9_CUMULUS
            FAPI_TRY( fapiGetOtherSideOfMemChannel(
                          i_target,
                          l_mcsTarget,
                          fapi2::TARGET_STATE_FUNCTIONAL),
                      "fapiGetOtherSideOfMemChannel() failed w/rc=0x%x",
                      (uint64_t)current_err );

            // Get the bus number
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   l_mcsTarget,
                                   l_busNum));
#endif
        }
        else
        {
            // Get the bus number
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   i_target,
                                   l_busNum));
        }

        // Get the chip target
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chipTarget;
        l_chipTarget = i_target.template getParent<TARGET_TYPE_PROC_CHIP>();

        // Get the chip number
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POS,
                               l_chipTarget,
                               l_chipPosition));


        // This is needed because we can only store and compare a uint8_t
        // value. For our purpose the value in l_chipPosition (Proc Position and
        // Centaur Position) will always be within the range of uint8_t
        l_chipNum = l_chipPosition;

        /*** Lets update the fail lane vector to the Buffer ***/
        // Create a structure of eRepair data that we will be matching
        // in the buffer.
        struct erepairDataMatch
        {
            interfaceType        intType;
            fapi2::TargetType    tgtType;
            union repairData
            {
                eRepairPowerBus fabBus;
                eRepairMemBus   memBus;
            } bus;
        };

        // Create an array of the above match structure to have all the
        // combinations of Fabric and Memory repair data
        erepairDataMatch l_repairMatch[14] =
        {
            {
                // index 0 - X0A (clock group 0)
                DRIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDIP, // type
                        PBUS_DRIVER,   // interface
                    },
                },
            },
            {
                // index 1 - X0A (clock group 0)
                RECEIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDIP, // type
                        PBUS_RECEIVER, // interface
                    },
                },
            },
            {
                // index 2 - X0A (clock group 1)
                DRIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDIP, // type
                        PBUS_DRIVER,   // interface
                    },
                },
            },
            {
                // index 3 - X0A (clock group 1)
                RECEIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDIP, // type
                        PBUS_RECEIVER, // interface
                    },
                },
            },
            {
                // index 4 - X1A (clock group 0)
                DRIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDIP, // type
                        PBUS_DRIVER,   // interface
                    },
                },
            },
            {
                // index 5 - X1A (clock group 0)
                RECEIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDIP, // type
                        PBUS_RECEIVER, // interface
                    },
                },
            },
            {
                // index 6 - X1A (clock group 1)
                DRIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDIP, // type
                        PBUS_DRIVER,   // interface
                    },
                },
            },
            {
                // index 7 - X1A (clock group 1)
                RECEIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDIP, // type
                        PBUS_RECEIVER, // interface
                    },
                },
            },
            {
                // index 8
                DRIVE,
                TARGET_TYPE_OBUS,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_OPT, // type
                        PBUS_DRIVER,   // interface
                    },
                },
            },
            {
                // index 9
                RECEIVE,
                TARGET_TYPE_OBUS,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_OPT, // type
                        PBUS_RECEIVER, // interface
                    },
                },
            },
            {
                // index 10
                DRIVE,
                TARGET_TYPE_MCS_CHIPLET,
                {
                    // repairData
                    {
                        // fabBus
                        {
                            // device
                            l_chipNum,// proc_centaur_id
                            l_busNum, // memChannel
                        },
                        MEMORY_EDIP,  // type
                        DMI_MCS_DRIVE,// interface
                    },
                },
            },
            {
                // index 11
                DRIVE,
                TARGET_TYPE_MEMBUF_CHIP,
                {
                    // repairData
                    {
                        // memBus
                        {
                            // device
                            l_chipNum,// proc_centaur_id
                            l_busNum, // memChannel
                        },
                        MEMORY_EDIP,     // type
                        DMI_MEMBUF_DRIVE,// interface
                    },
                },
            },
            {
                // index 12
                RECEIVE,
                TARGET_TYPE_MCS_CHIPLET,
                {
                    // repairData
                    {
                        // memBus
                        {
                            // device
                            l_chipNum,// proc_centaur_id
                            l_busNum, // memChannel
                        },
                        MEMORY_EDIP,     // type
                        DMI_MCS_RECEIVE, // interface
                    },
                },
            },
            {
                // index 13
                RECEIVE,
                TARGET_TYPE_MEMBUF_CHIP,
                {
                    // repairData
                    {
                        // memBus
                        {
                            // device
                            l_chipNum,// proc_centaur_id
                            l_busNum, // memChannel
                        },
                        MEMORY_EDIP,        // type
                        DMI_MEMBUF_RECEIVE, // interface
                    },
                },
            }
        };

        l_vpdDataPtr  = l_vpdPtr;
        l_repairCnt   = 0;

        // Pick each faillane for copying into buffer
        for(l_it  = i_failLanes.begin();
            l_it != i_failLanes.end();
            l_it++, (l_vpdDataPtr += l_repairDataSz))
        {
            l_repairLane  = *l_it;
            l_overWrite   = false;
            l_vpdWritePtr = NULL;

            // Parse the VPD for fabric and memory eRepair records
            for(;
                (l_repairCnt < l_numRepairs) && (l_bytesParsed <= i_bufSz);
                l_repairCnt++, (l_vpdDataPtr += l_repairDataSz))
            {
                l_overWritePtr =
                    reinterpret_cast<eRepairPowerBus*> (l_vpdDataPtr);

                // Lets find the matching fabric
                for(uint8_t l_loop = 0; l_loop < 14; l_loop++)
                {
                    if((i_target.getType() == TARGET_TYPE_XBUS) ||
                       (i_target.getType() == TARGET_TYPE_OBUS))
                    {
                        if((i_interface == l_repairMatch[l_loop].intType)    &&
                           (i_target.getType()   == l_repairMatch[l_loop].tgtType)    &&
                           ((l_overWritePtr->device).processor_id ==
                            l_repairMatch[l_loop].bus.fabBus.device.processor_id) &&
                           (l_overWritePtr->type ==
                            l_repairMatch[l_loop].bus.fabBus.type)       &&
                           (l_overWritePtr->interface ==
                            l_repairMatch[l_loop].bus.fabBus.interface)  &&
                           (l_overWritePtr->device.fabricBus ==
                            l_repairMatch[l_loop].bus.fabBus.device.fabricBus))
                        {
                            if(i_clkGroup > 0 && !l_bClkGroupFound)
                            {
                                l_bClkGroupFound = true;
                                continue;
                            }

                            // update the failBit number
                            {
                                uint32_t temp  = (uint32_t)(l_overWritePtr->failBit);
                                uint32_t* tptr = &temp;
                                FAPI_TRY( gatherRepairLanes(
                                              i_target,
                                              l_overWritePtr->interface,
                                              l_repairLane,
                                              tptr),
                                          "gatherRepairLanes() failed w/rc=0x%x",
                                          (uint64_t)current_err );
                                l_overWritePtr->failBit = temp;
                            }

                            // Increment the count of parsed bytes
                            l_bytesParsed += l_repairDataSz;

                            l_repairCnt++;
                            l_overWrite = true;

                            break;
                        }
                    }
                    else if((i_target.getType() == TARGET_TYPE_MCS_CHIPLET) ||
                            (i_target.getType() == TARGET_TYPE_MEMBUF_CHIP) )
                    {
                        if((i_interface == l_repairMatch[l_loop].intType)    &&
                           (i_target.getType()   == l_repairMatch[l_loop].tgtType)    &&
                           ((l_overWritePtr->device).processor_id ==
                            l_repairMatch[l_loop].bus.memBus.device.proc_centaur_id) &&
                           (l_overWritePtr->type ==
                            l_repairMatch[l_loop].bus.memBus.type)       &&
                           (l_overWritePtr->interface ==
                            l_repairMatch[l_loop].bus.memBus.interface)  &&
                           (l_overWritePtr->device.fabricBus ==
                            l_repairMatch[l_loop].bus.memBus.device.memChannel))
                        {
                            // update the failBit number
                            {
                                uint32_t temp = (uint32_t)(l_overWritePtr->failBit);
                                uint32_t* tptr = &temp;
                                FAPI_TRY( gatherRepairLanes(
                                              i_target,
                                              l_overWritePtr->interface,
                                              l_repairLane,
                                              tptr),
                                          "gatherRepairLanes() failed w/rc=0x%x",
                                          (uint64_t)current_err );
                                l_overWritePtr->failBit = temp;
                            }

                            // Increment the count of parsed bytes
                            l_bytesParsed += l_repairDataSz;

                            l_repairCnt++;
                            l_overWrite = true;

                            break;
                        }
                    }
                } // end of for(l_loop < 14)

                if(l_overWrite == true)
                {
                    // Go for the next repairLane
                    break;
                }
            } // end of for(vpd Parsing)

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
                            .set_VAL_NUM_REPAIR(l_numRepairs),
                            "ERROR: from updateRepairLanesToBuf - MVPD full");
            }

            // Add at the end
            if(l_overWrite == false)
            {
                if(l_vpdWritePtr == NULL)
                {
                    // We are writing at the end
                    l_vpdWritePtr = l_vpdDataPtr;
                }

                if((i_target.getType() == TARGET_TYPE_XBUS) ||
                   (i_target.getType() == TARGET_TYPE_OBUS))
                {
                    // Make sure we are not writing more records than the size
                    // allocated in the VPD
                    FAPI_ASSERT(l_bytesParsed <= i_bufSz,
                                fapi2::P9_EREPAIR_MVPD_FULL_ERR()
                                .set_VAL_BYTE_PARSED(l_bytesParsed)
                                .set_VAL_BUF_SIZE(i_bufSz)
                                .set_VAL_REPAIR_CNT(l_repairCnt)
                                .set_VAL_NUM_REPAIR(l_numRepairs),
                                "ERROR: from updateRepairLanesToBuf - MVPD full");

                    eRepairPowerBus* l_fabricBus =
                        reinterpret_cast<eRepairPowerBus*>(l_vpdWritePtr);

                    l_fabricBus->device.processor_id = l_chipNum;
                    l_fabricBus->device.fabricBus    = l_busNum;

                    if(i_interface == DRIVE)
                    {
                        l_fabricBus->interface = PBUS_DRIVER;
                    }
                    else if(i_interface == RECEIVE)
                    {
                        l_fabricBus->interface = PBUS_RECEIVER;
                    }

                    if(i_target.getType() == TARGET_TYPE_XBUS)
                    {
                        l_fabricBus->type = PROCESSOR_EDIP;
                    }
                    else if(i_target.getType() == TARGET_TYPE_OBUS)
                    {
                        l_fabricBus->type = PROCESSOR_OPT;
                    }

                    {
                        uint32_t temp = (uint32_t)(l_fabricBus->failBit);
                        uint32_t* tptr = &temp;
                        FAPI_TRY( gatherRepairLanes(
                                      i_target,
                                      l_fabricBus->interface,
                                      l_repairLane,
                                      tptr),
                                  "gatherRepairLanes() failed w/rc=0x%x",
                                  (uint64_t)current_err );
                        l_fabricBus->failBit = temp;
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
                else if((i_target.getType() == TARGET_TYPE_MCS_CHIPLET) ||
                        (i_target.getType() == TARGET_TYPE_MEMBUF_CHIP) )
                {
                    // Make sure we are not writing more records than the size
                    // allocated in the VPD
                    FAPI_ASSERT(l_bytesParsed == i_bufSz,
                                fapi2::P9_EREPAIR_MBVPD_FULL_ERR()
                                .set_ERROR(l_bytesParsed),
                                "ERROR: from updateRepairLanesToBuf - MBVPD full");

                    eRepairMemBus* l_memBus =
                        reinterpret_cast<eRepairMemBus*>(l_vpdWritePtr);

                    l_memBus->device.proc_centaur_id = l_chipNum;
                    l_memBus->device.memChannel      = l_busNum;
                    l_memBus->type                   = MEMORY_EDIP;

                    if(i_interface == DRIVE)
                    {
                        if(i_target.getType() == TARGET_TYPE_MCS_CHIPLET)
                        {
                            l_memBus->interface = DMI_MCS_DRIVE;
                        }
                        else if(i_target.getType() == TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = DMI_MEMBUF_DRIVE;
                        }
                    }
                    else if(i_interface == RECEIVE)
                    {
                        if(i_target.getType() == TARGET_TYPE_MCS_CHIPLET)
                        {
                            l_memBus->interface = DMI_MCS_RECEIVE;
                        }
                        else if(i_target.getType() == TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = DMI_MEMBUF_RECEIVE;
                        }
                    }

                    {
                        uint32_t temp = (uint32_t)(l_memBus->failBit);
                        uint32_t* tptr = &temp;
                        FAPI_TRY( gatherRepairLanes(
                                      i_target,
                                      l_memBus->interface,
                                      l_repairLane,
                                      tptr),
                                  "gatherRepairLanes() failed w/rc=0x%x",
                                  (uint64_t)current_err );
                        l_memBus->failBit = temp;
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

fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K>
fapi2::ReturnCode gatherRepairLanes(
    const fapi2::Target < K >&           i_target,
    uint8_t                             i_busInterface,
    uint8_t                             i_repairLane,
    uint32_t*                           o_failBit)
{
    fapi2::ReturnCode l_rc;
    uint8_t           maxBusLanes       = 0;
    uint32_t          setBitPosition    = (0x80000000);

    FAPI_DBG(">> setRepairLanes");

    // Check for target type and corresponding sub interface
    // to get max lanes supported per interface
    if(i_target.getType() == fapi2::TARGET_TYPE_OBUS)
    {
        maxBusLanes = OBUS_MAX_LANE_WIDTH;    //OBUS
    }
    else if(i_target.getType() == fapi2::TARGET_TYPE_XBUS)
    {
        maxBusLanes = XBUS_MAX_LANE_WIDTH;    //XBUS
    }
    else if((i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP) ||
            (i_target.getType() == fapi2::TARGET_TYPE_MCS_CHIPLET)) //DMI
    {
        if( (i_busInterface == DMI_MCS_RECEIVE) ||
            (i_busInterface == DMI_MEMBUF_DRIVE) )
        {
            maxBusLanes = DMIBUS_DNSTREAM_MAX_LANE_WIDTH;
        }
        else if( (i_busInterface == DMI_MCS_DRIVE) ||
                 (i_busInterface == DMI_MEMBUF_RECEIVE) )
        {
            maxBusLanes = DMIBUS_UPSTREAM_MAX_LANE_WIDTH;
        }
    }

    // Make sure repair lane value passed is within valid range as per the target type
    FAPI_ASSERT(i_repairLane < maxBusLanes,
                fapi2::P9_EREPAIR_INVALID_LANE_VALUE_ERR()
                .set_ERROR(i_repairLane)
                .set_TARGET(i_target),
                "ERROR: Invalid erepair lane value");

    // Update the fail bits data with the repair lane number failed
    *o_failBit |= (setBitPosition >> i_repairLane);

    // Get the failed lanes
    FAPI_INF("Updated Fail Lanes:%x", *o_failBit);

    FAPI_DBG("<< setRepairLanes");

fapi_try_exit:
    return l_rc;
}

