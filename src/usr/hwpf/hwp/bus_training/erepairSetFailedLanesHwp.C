/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/erepairSetFailedLanesHwp.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
// $Id: erepairSetFailedLanesHwp.C,v 1.5 2015/02/23 16:46:15 bilicon Exp $
/**
 *  @file erepairSetFailedLanesHwp.C
 *
 *  @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     13-JAN-2013 Created.
 */

#include <erepairSetFailedLanesHwp.H>

using namespace EREPAIR;
using namespace fapi;

extern "C"
{

/******************************************************************************
 * Forward Declarations
 *****************************************************************************/

/**
 * @brief Function called by the FW Team HWP that writes the data to Field VPD.
 *        This function calls fapiSetMvpdField to write the VPD.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_txFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[in] i_rxFailLanes Reference to a vector that has eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 */
ReturnCode writeRepairDataToVPD(const Target               &i_tgtHandle,
                                erepairVpdType             i_vpdType,
                                const std::vector<uint8_t> &i_txFailLanes,
                                const std::vector<uint8_t> &i_rxFailLanes);

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS target
 * @param[in] i_txFailLanes Reference to a vector that has the Tx side faillane
 *                          numbers that need to be updated to the o_buf buffer
 * @param[in] i_rxFailLanes Reference to a vector that has the Rx side faillane
 *                          numbers that need to be updated to the o_buf buffer
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[o]  o_buf         This is the buffer that has the eRepair records
 *                          that needs to be written to the VPD
 *
 * @return ReturnCode
 */
ReturnCode writeRepairLanesToBuf(const Target               &i_tgtHandle,
                                 const std::vector<uint8_t> &i_txFailLanes,
                                 const std::vector<uint8_t> &i_rxFailLanes,
                                 const uint32_t             i_bufSz,
                                 uint8_t                    *o_buf);

/**
 * @brief Function called by the FW Team HWP that updates the passed buffer
 *        with the eRepair faillane numbers of a specified interface.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS target
 * @param[in] i_interface   This indicates the sub-interface type the passed
 *                          faillane vector represents
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[in] i_failLanes   Reference to a vector that has the faillane numbers
 *                          that need to be updated to the o_buf buffer
 * @param[o]  o_buf         This is the buffer that has the eRepair records
 *                          that needs to be written to the VPD
 *
 * @return ReturnCode
 */
ReturnCode updateRepairLanesToBuf(const Target               &i_tgtHandle,
                                  const interfaceType        i_interface,
                                  const uint32_t             i_bufSz,
                                  const std::vector<uint8_t> &i_failLanes,
                                  uint8_t                    *o_buf);

/******************************************************************************
 * Accessor HWP
 *****************************************************************************/

ReturnCode erepairSetFailedLanesHwp(const Target               &i_tgtHandle,
                                    erepairVpdType             i_vpdType,
                                    const std::vector<uint8_t> &i_txFailLanes,
                                    const std::vector<uint8_t> &i_rxFailLanes)
{
    ReturnCode l_rc;
    Target     l_mcsTgt;
    TargetType l_tgtType = TARGET_TYPE_NONE;

    FAPI_INF(">> erepairSetFailedLanesHwp: i_tgtHandle: %s",
             i_tgtHandle.toEcmdString());

    do
    {
        if((i_txFailLanes.size() == 0) && (i_rxFailLanes.size() == 0))
        {
            FAPI_INF("erepairSetFailedLanesHwp: No fail lanes were provided");
            break;
        }

        // Determine the type of target
        l_tgtType = i_tgtHandle.getType();

        // Verify if the correct target type is passed
        if((l_tgtType != TARGET_TYPE_MCS_CHIPLET)    &&
           (l_tgtType != TARGET_TYPE_MEMBUF_CHIP)    &&
           (l_tgtType != TARGET_TYPE_XBUS_ENDPOINT)  &&
           (l_tgtType != TARGET_TYPE_ABUS_ENDPOINT))
        {
            FAPI_ERR("erepairSetFailedLanesHwp: Invalid Target type %d",
                     l_tgtType);
            FAPI_SET_HWP_ERROR(l_rc, RC_ACCESSOR_HWP_INVALID_TARGET_TYPE);
            break;
        }

        l_rc = writeRepairDataToVPD(i_tgtHandle,
                                    i_vpdType,
                                    i_txFailLanes,
                                    i_rxFailLanes);

        if(l_rc)
        {
            FAPI_ERR("Error (0x%x) during write of Field records",
                     static_cast<uint32_t>(l_rc));
            break;
        }
    }while(0);

    return l_rc;
}


ReturnCode writeRepairDataToVPD(const Target               &i_tgtHandle,
                                erepairVpdType             i_vpdType,
                                const std::vector<uint8_t> &i_txFailLanes,
                                const std::vector<uint8_t> &i_rxFailLanes)
{
    ReturnCode l_rc;
    uint8_t    *l_retBuf = NULL;
    uint32_t   l_bufSize = 0;
    Target     l_procTarget;
    uint8_t    l_customDimm;
    std::vector<fapi::Target> l_mbaChiplets;
    fapi::Target              l_mbaTarget;

    FAPI_DBG(">> writeRepairDataToVPD");

    do
    {
        if(i_tgtHandle.getType() == TARGET_TYPE_MEMBUF_CHIP)
        {
            fapi::MBvpdRecord l_vpdRecord = MBVPD_RECORD_VEIR;

            if(i_vpdType == EREPAIR_VPD_MNFG)
            {
                l_vpdRecord = MBVPD_RECORD_MER0;
            }

            /*** Read the data from the FRU VPD ***/

            // Determine the size of the eRepair data in the Centaur VPD
            l_rc = fapiGetMBvpdField(l_vpdRecord,
                                     MBVPD_KEYWORD_PDI,
                                     i_tgtHandle,
                                     NULL,
                                     l_bufSize);
            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetMBvpdField",
                          static_cast<uint32_t> (l_rc));
                break;
            }

            // Get the connected MBA chiplet and determine whether we have CDIMM
            l_rc = fapiGetChildChiplets(i_tgtHandle,
                                        fapi::TARGET_TYPE_MBA_CHIPLET,
                                        l_mbaChiplets,
                                        fapi::TARGET_STATE_FUNCTIONAL);

            if(l_rc || (0 == l_mbaChiplets.size()))
            {
                FAPI_ERR("Error (0x%x) during get child MBA targets",
                         static_cast<uint32_t> (l_rc));
                break;
            }

            l_mbaTarget = l_mbaChiplets[0];
            std::vector<fapi::Target> l_target_dimm_array;

            l_rc =  fapiGetAssociatedDimms(l_mbaTarget, l_target_dimm_array);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x), from fapiGetAssociatedDimms",
                          static_cast<uint32_t>(l_rc));
                break;
            }

            if(0 != l_target_dimm_array.size())
            {
                l_rc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM,
                                     &l_target_dimm_array[0],
                                     l_customDimm);
                if(l_rc)
                {
                    FAPI_ERR("Error (0x%x), from FAPI_ATTR_GET",
                             static_cast<uint32_t>(l_rc));
                    break;
                }
            }
            else
            {
                l_customDimm = fapi::ENUM_ATTR_SPD_CUSTOM_NO;
            }

            if(l_customDimm == fapi::ENUM_ATTR_SPD_CUSTOM_YES)
            {
                if((l_bufSize == 0) ||
                       ((i_vpdType == EREPAIR_VPD_FIELD) &&
                        (l_bufSize > EREPAIR_MEM_FIELD_VPD_SIZE_PER_CENTAUR)) ||
                       ((i_vpdType == EREPAIR_VPD_MNFG) &&
                        (l_bufSize > EREPAIR_MEM_MNFG_VPD_SIZE_PER_CENTAUR)))
                {
                    FAPI_SET_HWP_ERROR(l_rc,
                                       RC_ACCESSOR_HWP_INVALID_MEM_VPD_SIZE);
                    break;
                }
            }
            else if(l_bufSize == 0)
            {
                // TODO RTC: 119531. Add upper bound checking for l_bufSize
                // This size check will depend on whether the Lane eRepair data
                // is stored on the Planar VPD or on the Riser card VPD.
                FAPI_SET_HWP_ERROR(l_rc, RC_ACCESSOR_HWP_INVALID_MEM_VPD_SIZE);
                break;
            }

            // Allocate memory for buffer
            l_retBuf = new uint8_t[l_bufSize];
            if(l_retBuf == NULL)
            {
                FAPI_ERR("Failed to allocate memory size of %d", l_bufSize);
                FAPI_SET_HWP_ERROR(l_rc, RC_ACCESSOR_HWP_MEMORY_ALLOC_FAIL);
                break;
            }

            // Retrieve the Field eRepair data from the Centaur FRU VPD
            l_rc = fapiGetMBvpdField(l_vpdRecord,
                                     MBVPD_KEYWORD_PDI,
                                     i_tgtHandle,
                                     l_retBuf,
                                     l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetMBvpdField",
                          static_cast<uint32_t> (l_rc));
                break;
            }

            /*** Update the new eRepair data to the buffer ***/
            l_rc = writeRepairLanesToBuf(i_tgtHandle,
                                         i_txFailLanes,
                                         i_rxFailLanes,
                                         l_bufSize,
                                         l_retBuf);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from writeRepairLanesToBuf",
                          static_cast<uint32_t> (l_rc));
                break;
            }

            /*** Write the updated eRepair buffer back to Centaur FRU VPD ***/
            l_rc = fapiSetMBvpdField(l_vpdRecord,
                                     MBVPD_KEYWORD_PDI,
                                     i_tgtHandle,
                                     l_retBuf,
                                     l_bufSize);
            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiSetMBvpdField",
                          static_cast<uint32_t> (l_rc));
                break;
            }
        } // end of(targetType == MEMBUF)
        else
        {
            // Determine the Processor target
            l_rc = fapiGetParentChip(i_tgtHandle, l_procTarget);
            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetParentChip",
                        static_cast<uint32_t>(l_rc));
                break;
            }

            fapi::MvpdRecord l_vpdRecord = MVPD_RECORD_VWML;

            if(i_vpdType == EREPAIR_VPD_MNFG)
            {
                l_vpdRecord = MVPD_RECORD_MER0;
            }

            /*** Read the data from the Module VPD ***/

            // Determine the size of the eRepair data in the VPD
            l_rc = fapiGetMvpdField(l_vpdRecord,
                                    MVPD_KEYWORD_PDI,
                                    l_procTarget,
                                    NULL,
                                    l_bufSize);
            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetMvpdField",
                          static_cast<uint32_t> (l_rc));
                break;
            }

            if((l_bufSize == 0) ||
               ((i_vpdType == EREPAIR_VPD_FIELD) &&
                (l_bufSize > EREPAIR_P8_MODULE_VPD_FIELD_SIZE)) ||
               ((i_vpdType == EREPAIR_VPD_MNFG) &&
                (l_bufSize > EREPAIR_P8_MODULE_VPD_MNFG_SIZE)))
            {
                FAPI_SET_HWP_ERROR(l_rc,
                                   RC_ACCESSOR_HWP_INVALID_FABRIC_VPD_SIZE);
                break;
            }

            // Allocate memory for buffer
            l_retBuf = new uint8_t[l_bufSize];
            if(l_retBuf == NULL)
            {
                FAPI_ERR("Failed to allocate memory size of %d", l_bufSize);
                FAPI_SET_HWP_ERROR(l_rc, RC_ACCESSOR_HWP_MEMORY_ALLOC_FAIL);
                break;
            }

            // Retrieve the Field eRepair data from the MVPD
            l_rc = fapiGetMvpdField(l_vpdRecord,
                                    MVPD_KEYWORD_PDI,
                                    l_procTarget,
                                    l_retBuf,
                                    l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetMvpdField",
                          static_cast<uint32_t> (l_rc));
                break;
            }

            /*** Update the new eRepair data to the buffer ***/
            l_rc = writeRepairLanesToBuf(i_tgtHandle,
                                         i_txFailLanes,
                                         i_rxFailLanes,
                                         l_bufSize,
                                         l_retBuf);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from writeRepairLanesToBuf",
                          static_cast<uint32_t> (l_rc));
                break;
            }

            /*** Write the updated eRepair buffer back to MVPD ***/
            l_rc = fapiSetMvpdField(l_vpdRecord,
                                    MVPD_KEYWORD_PDI,
                                    l_procTarget,
                                    l_retBuf,
                                    l_bufSize);
            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiSetMvpdField",
                        static_cast<uint32_t> (l_rc));
                break;
            }
        }
    }while(0);

    // Delete the buffer which has Field eRepair data
    delete[] l_retBuf;

    return (l_rc);
}

ReturnCode writeRepairLanesToBuf(const Target               &i_tgtHandle,
                                 const std::vector<uint8_t> &i_txFailLanes,
                                 const std::vector<uint8_t> &i_rxFailLanes,
                                 const uint32_t             i_bufSz,
                                 uint8_t                    *o_buf)
{
    ReturnCode l_rc;

    FAPI_DBG(">> writeRepairLanesToBuf");

    do
    {
        if(i_txFailLanes.size())
        {
            /*** Lets update the tx side fail lane vector to the VPD ***/
            l_rc = updateRepairLanesToBuf(i_tgtHandle,
                                          DRIVE,
                                          i_bufSz,
                                          i_txFailLanes,
                                          o_buf);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x), from updateRepairLanesToBuf(DRIVE)",
                          static_cast<uint32_t>(l_rc));
                break;
            }
        }

        if(i_rxFailLanes.size())
        {
            /*** Lets update the rx side fail lane vector to the VPD ***/
            l_rc = updateRepairLanesToBuf(i_tgtHandle,
                                          RECEIVE,
                                          i_bufSz,
                                          i_rxFailLanes,
                                          o_buf);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x), from updateRepairLanesToBuf(RECEIVE)",
                          static_cast<uint32_t>(l_rc));
                break;
            }
        }
    }while(0);

    return (l_rc);
}

ReturnCode updateRepairLanesToBuf(const Target               &i_tgtHandle,
                                  const interfaceType        i_interface,
                                  const uint32_t             i_bufSz,
                                  const std::vector<uint8_t> &i_failLanes,
                                  uint8_t                    *o_buf)
{
    ReturnCode       l_rc;
    uint32_t         l_numRepairs           = 0;
    uint32_t         l_newNumRepairs        = 0;
    uint32_t         l_repairCnt            = 0;
    uint32_t         l_bytesParsed          = 0;
    uint8_t          l_repairLane           = 0;
    uint32_t         l_repairDataSz         = 0;
    uint8_t          *l_vpdPtr              = NULL;
    uint8_t          *l_vpdDataPtr          = NULL;
    uint8_t          *l_vpdWritePtr         = NULL;
    eRepairHeader    *l_vpdHeadPtr          = NULL;
    eRepairPowerBus  *l_overWritePtr        = NULL;
    bool             l_overWrite            = false;
    TargetType       l_tgtType              = TARGET_TYPE_NONE;
    Target           l_mcsTarget;
    Target           l_tgtHandle;
    std::vector<uint8_t>::const_iterator l_it;
    ATTR_CHIP_UNIT_POS_Type l_busNum;

    FAPI_DBG(">> updateRepairLanesToBuf, interface: %s",
              i_interface == DRIVE ? "Drive" : "Recevie");

    do
    {
        l_repairDataSz = sizeof(eRepairPowerBus); // Size of memory Bus and
                                                  // fabric Bus eRepair data
                                                  // is same.
        // Read the header and count information
        l_vpdPtr = o_buf; // point to the start of header data
        l_vpdHeadPtr = reinterpret_cast<eRepairHeader *> (l_vpdPtr);

        l_numRepairs = l_newNumRepairs = l_vpdHeadPtr->numRecords;

        // We've read the header data, increment bytes parsed
        l_bytesParsed = sizeof(eRepairHeader);

        // Get a pointer to the start of repair data
        l_vpdPtr += sizeof(eRepairHeader);

        l_tgtType = i_tgtHandle.getType();

        l_tgtHandle = i_tgtHandle;
        if(l_tgtType == TARGET_TYPE_MEMBUF_CHIP)
        {
            l_rc = fapiGetOtherSideOfMemChannel(i_tgtHandle,
                                                l_mcsTarget,
                                                TARGET_STATE_FUNCTIONAL);

            if(l_rc)
            {
                FAPI_ERR("updateRepairLanesToBuf: unable to get the connected"
                         " MCS target");
                break;
            }

            l_tgtHandle = l_mcsTarget;
        }

        // Get the bus number
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_tgtHandle, l_busNum);
        if(l_rc)
        {
            FAPI_ERR("Error (0x%x), from FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS)",
                     static_cast<uint32_t>(l_rc));
            break;
        }

        // Get the chip target
        Target l_chipTarget = i_tgtHandle;
        if((l_tgtType == TARGET_TYPE_XBUS_ENDPOINT) ||
           (l_tgtType == TARGET_TYPE_ABUS_ENDPOINT) ||
           (l_tgtType == TARGET_TYPE_MCS_CHIPLET))
        {
            l_rc = fapiGetParentChip(i_tgtHandle, l_chipTarget);
            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetParentChip",
                        static_cast<uint32_t>(l_rc));
                break;
            }
        }

        // Get the chip number
        uint32_t l_chipPosition;
        l_rc = FAPI_ATTR_GET(ATTR_POS, &l_chipTarget, l_chipPosition);
        if(l_rc)
        {
            FAPI_ERR("Error (0x%x), from FAPI_ATTR_GET(ATTR_POS)",
                     static_cast<uint32_t>(l_rc));
            break;
        }

        // This is needed because we can only store and compare a uint8_t
        // value. For our purpose the value in l_chipPosition (Proc Position and
        // Centaur Position) will always be within the range of uint8_t
        uint8_t l_chipNum = l_chipPosition;

        /*** Lets update the fail lane vector to the Buffer ***/

        // Create a structure of eRepair data that we will be matching
        // in the buffer.
        struct erepairDataMatch
        {
            interfaceType   intType;
            TargetType      tgtType;
            union repairData
            {
                eRepairPowerBus fabBus;
                eRepairMemBus   memBus;
            }bus;
        };

        // Create an array of the above match structure to have all the
        // combinations of Fabric and Memory repair data
        erepairDataMatch l_repairMatch[8] =
        {
            { // index 0
                DRIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                { // repairData
                    { // fabBus
                        { // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EI4, // type
                        PBUS_DRIVER,   // interface
                    },
                },
            },
            { // index 1
                DRIVE,
                TARGET_TYPE_ABUS_ENDPOINT,
                { // repairData
                    { // fabBus
                        { // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDI, // type
                        PBUS_DRIVER,   // interface
                    },
                },
            },
            { // index 2
                RECEIVE,
                TARGET_TYPE_XBUS_ENDPOINT,
                { // repairData
                    { // fabBus
                        { // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EI4, // type
                        PBUS_RECEIVER, // interface
                    },
                },
            },
            { // index 3
                RECEIVE,
                TARGET_TYPE_ABUS_ENDPOINT,
                { // repairData
                    { // fabBus
                        { // device
                            l_chipNum,// processor_id
                            l_busNum, // fabricBus
                        },
                        PROCESSOR_EDI, // type
                        PBUS_RECEIVER, // interface
                    },
                },
            },
            { // index 4
                DRIVE,
                TARGET_TYPE_MCS_CHIPLET,
                { // repairData
                    { // fabBus
                        { // device
                            l_chipNum,// proc_centaur_id
                            l_busNum, // memChannel
                        },
                        MEMORY_EDI,   // type
                        DMI_MCS_DRIVE,// interface
                    },
                },
            },
            { // index 5
                DRIVE,
                TARGET_TYPE_MEMBUF_CHIP,
                { // repairData
                    { // memBus
                        { // device
                            l_chipNum,// proc_centaur_id
                            l_busNum, // memChannel
                        },
                        MEMORY_EDI,      // type
                        DMI_MEMBUF_DRIVE,// interface
                    },
                },
            },
            { // index 6
                RECEIVE,
                TARGET_TYPE_MCS_CHIPLET,
                { // repairData
                    { // memBus
                        { // device
                            l_chipNum,// proc_centaur_id
                            l_busNum, // memChannel
                        },
                        MEMORY_EDI,      // type
                        DMI_MCS_RECEIVE, // interface
                    },
                },
            },
            { // index 7
                RECEIVE,
                TARGET_TYPE_MEMBUF_CHIP,
                { // repairData
                    { // memBus
                        { // device
                            l_chipNum,// proc_centaur_id
                            l_busNum, // memChannel
                        },
                        MEMORY_EDI,         // type
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
                            reinterpret_cast<eRepairPowerBus *> (l_vpdDataPtr);

                // Lets find the matching fabric
                for(uint8_t l_loop = 0; l_loop < 8; l_loop++)
                {
                    if((l_tgtType == TARGET_TYPE_XBUS_ENDPOINT) ||
                       (l_tgtType == TARGET_TYPE_ABUS_ENDPOINT))
                    {
                        if((i_interface == l_repairMatch[l_loop].intType)    &&
                           (l_tgtType   == l_repairMatch[l_loop].tgtType)    &&
                           ((l_overWritePtr->device).processor_id ==
                        l_repairMatch[l_loop].bus.fabBus.device.processor_id)&&
                           (l_overWritePtr->type ==
                                l_repairMatch[l_loop].bus.fabBus.type)       &&
                           (l_overWritePtr->interface ==
                                l_repairMatch[l_loop].bus.fabBus.interface)  &&
                           (l_overWritePtr->device.fabricBus ==
                            l_repairMatch[l_loop].bus.fabBus.device.fabricBus))
                        {
                            // update the failBit number
                            l_overWritePtr->failBit = l_repairLane;

                            // Increment the count of parsed bytes
                            l_bytesParsed += l_repairDataSz;

                            l_repairCnt++;
                            l_overWrite = true;

                            break;
                        }
                    }
                    else if((l_tgtType == TARGET_TYPE_MCS_CHIPLET) ||
                            (l_tgtType == TARGET_TYPE_MEMBUF_CHIP) )
                    {
                        if((i_interface == l_repairMatch[l_loop].intType)    &&
                           (l_tgtType   == l_repairMatch[l_loop].tgtType)    &&
                           ((l_overWritePtr->device).processor_id ==
                     l_repairMatch[l_loop].bus.memBus.device.proc_centaur_id)&&
                           (l_overWritePtr->type ==
                                l_repairMatch[l_loop].bus.memBus.type)       &&
                           (l_overWritePtr->interface ==
                                l_repairMatch[l_loop].bus.memBus.interface)  &&
                           (l_overWritePtr->device.fabricBus ==
                            l_repairMatch[l_loop].bus.memBus.device.memChannel))
                        {
                            // update the failBit number
                            l_overWritePtr->failBit = l_repairLane;

                            // Increment the count of parsed bytes
                            l_bytesParsed += l_repairDataSz;

                            l_repairCnt++;
                            l_overWrite = true;

                            break;
                        }
                    }

                    // Check if we have a eRepair record that is invalidated
                    // If yes, save the pointer so that we can overwrite it
                    // if no matching record is found
                    if(l_overWritePtr->failBit == INVALID_FAIL_LANE_NUMBER)
                    {
                        l_vpdWritePtr = l_vpdDataPtr;
                    }
                } // end of for(l_loop < 8)

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
                if((l_tgtType == TARGET_TYPE_XBUS_ENDPOINT) ||
                   (l_tgtType == TARGET_TYPE_ABUS_ENDPOINT))
                {
                    FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_MVPD_FULL);
                }
                else if((l_tgtType == TARGET_TYPE_MCS_CHIPLET) ||
                        (l_tgtType == TARGET_TYPE_MEMBUF_CHIP) )
                {
                    FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_MBVPD_FULL);
                }
                break;
            }

            // Add at the end
            if(l_overWrite == false)
            {
                if(l_vpdWritePtr == NULL)
                {
                    // We are writing at the end
                    l_vpdWritePtr = l_vpdDataPtr;
                }

                if((l_tgtType == TARGET_TYPE_XBUS_ENDPOINT) ||
                   (l_tgtType == TARGET_TYPE_ABUS_ENDPOINT))
                {
                    // Make sure we are not writing more records than the size
                    // allocated in the VPD
                    if(l_bytesParsed == i_bufSz)
                    {
                        FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_MVPD_FULL);
                        break;
                    }

                    eRepairPowerBus *l_fabricBus =
                             reinterpret_cast<eRepairPowerBus *>(l_vpdWritePtr);

                    l_fabricBus->device.processor_id = l_chipNum;
                    l_fabricBus->device.fabricBus    = l_busNum;
                    l_fabricBus->failBit             = l_repairLane;

                    if(i_interface == DRIVE)
                    {
                        l_fabricBus->interface = PBUS_DRIVER;
                    }
                    else if(i_interface == RECEIVE)
                    {
                        l_fabricBus->interface = PBUS_RECEIVER;
                    }

                    if(l_tgtType == TARGET_TYPE_XBUS_ENDPOINT)
                    {
                        l_fabricBus->type = PROCESSOR_EI4;
                    }
                    else if(l_tgtType == TARGET_TYPE_ABUS_ENDPOINT)
                    {
                        l_fabricBus->type = PROCESSOR_EDI;
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
                else if((l_tgtType == TARGET_TYPE_MCS_CHIPLET) ||
                        (l_tgtType == TARGET_TYPE_MEMBUF_CHIP) )
                {
                    // Make sure we are not writing more records than the size
                    // allocated in the VPD
                    if(l_bytesParsed == i_bufSz)
                    {
                        FAPI_SET_HWP_ERROR(l_rc, RC_EREPAIR_MBVPD_FULL);
                        break;
                    }

                    eRepairMemBus *l_memBus =
                               reinterpret_cast<eRepairMemBus *>(l_vpdWritePtr);

                    l_memBus->device.proc_centaur_id = l_chipNum;
                    l_memBus->device.memChannel      = l_busNum;
                    l_memBus->type                   = MEMORY_EDI;
                    l_memBus->failBit                = l_repairLane;

                    if(i_interface == DRIVE)
                    {
                        if(l_tgtType == TARGET_TYPE_MCS_CHIPLET)
                        {
                            l_memBus->interface = DMI_MCS_DRIVE;
                        }
                        else if(l_tgtType == TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = DMI_MEMBUF_DRIVE;
                        }
                    }
                    else if(i_interface == RECEIVE)
                    {
                        if(l_tgtType == TARGET_TYPE_MCS_CHIPLET)
                        {
                            l_memBus->interface = DMI_MCS_RECEIVE;
                        }
                        else if(l_tgtType == TARGET_TYPE_MEMBUF_CHIP)
                        {
                            l_memBus->interface = DMI_MEMBUF_RECEIVE;
                        }
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

    }while(0);

    return(l_rc);
}

}// endof extern "C"
