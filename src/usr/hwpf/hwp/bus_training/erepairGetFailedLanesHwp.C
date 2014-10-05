/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/erepairGetFailedLanesHwp.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: erepairGetFailedLanesHwp.C,v 1.4 2014/08/05 15:04:38 kahnevan Exp $
/**
 *  @file erepairGetFailedLanesHwp.C
 *
 *  @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     09/14/2012  Created.
 */

#include <erepairGetFailedLanesHwp.H>

extern "C"
{

/******************************************************************************
 * Forward Declarations
 *****************************************************************************/

/**
 * @brief Function called by the FW Team HWP that reads the data from Field VPD.
 *        This function makes the actual calls to read the VPD
 *        It determines the size of the buffer to be read, allocates memory
 *        of the determined size, calls fapiGetMvpdField to read the eRepair
 *        records. This buffer is further passed to another routine for
 *        parsing.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[o]  o_txFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[o]  o_rxFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 */
fapi::ReturnCode retrieveRepairData(const fapi::Target      &i_tgtHandle,
                                    EREPAIR::erepairVpdType i_vpdType,
                                    std::vector<uint8_t>    &o_txFailLanes,
                                    std::vector<uint8_t>    &o_rxFailLanes);

/**
 * @brief Function called by the FW Team HWP that parses the data read from
 *        Field VPD. This function matches each eRepair record read from the VPD
 *        and matches it against the attributes of the passed target.
 *        If a match is found, the corresponding eRepair record is copied into
 *        the respective failLane vectors to be returned to the caller.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS target
 * @param[in] i_buf         This is the buffer that has the eRepair records
 *                          read from the VPD
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[o]  o_txFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[o]  o_rxFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 */
fapi::ReturnCode determineRepairLanes(const fapi::Target   &i_tgtHandle,
                                      uint8_t              *i_buf,
                                      uint32_t             i_bufSz,
                                      std::vector<uint8_t> &o_txFailLanes,
                                      std::vector<uint8_t> &o_rxFailLanes);


/******************************************************************************
 * Accessor HWP
 *****************************************************************************/

fapi::ReturnCode erepairGetFailedLanesHwp(
                                         const fapi::Target      &i_tgtHandle,
                                         EREPAIR::erepairVpdType i_vpdType,
                                         std::vector<uint8_t>    &o_txFailLanes,
                                         std::vector<uint8_t>    &o_rxFailLanes)
{
    fapi::ReturnCode l_rc;
    fapi::Target     l_processorTgt;
    fapi::TargetType l_tgtType = fapi::TARGET_TYPE_NONE;
    std::vector<fapi::Target> l_mcsChiplets;

    FAPI_INF(">> erepairGetFailedLanesHwp: i_tgtHandle: %s",
             i_tgtHandle.toEcmdString());

    do
    {
        o_txFailLanes.clear();
        o_rxFailLanes.clear();

        // Determine the type of target
        l_tgtType = i_tgtHandle.getType();

        // Verify if the correct target type is passed
        if((l_tgtType != fapi::TARGET_TYPE_MCS_CHIPLET)    &&
           (l_tgtType != fapi::TARGET_TYPE_MEMBUF_CHIP)    &&
           (l_tgtType != fapi::TARGET_TYPE_XBUS_ENDPOINT)  &&
           (l_tgtType != fapi::TARGET_TYPE_ABUS_ENDPOINT))
        {
            FAPI_ERR("erepairGetFailedLanesHwp: Invalid Target type %d",
                    l_tgtType);
            FAPI_SET_HWP_ERROR(l_rc, RC_ACCESSOR_HWP_INVALID_TARGET_TYPE);
            break;
        }

        // Retrieve the Field eRepair lane numbers from the VPD
        l_rc = retrieveRepairData(i_tgtHandle,
                                  i_vpdType,
                                  o_txFailLanes,
                                  o_rxFailLanes);

        if(l_rc)
        {
            FAPI_ERR("Error (0x%x) during retrieval of Field records",
                    static_cast<uint32_t>(l_rc));
            break;
        }
    }while(0);

    return l_rc;
}

fapi::ReturnCode retrieveRepairData(const fapi::Target      &i_tgtHandle,
                                    EREPAIR::erepairVpdType i_vpdType,
                                    std::vector<uint8_t>    &o_txFailLanes,
                                    std::vector<uint8_t>    &o_rxFailLanes)
{
    fapi::ReturnCode l_rc;
    uint8_t          *l_retBuf = NULL;
    uint32_t         l_bufSize = 0;
    fapi::Target     l_procTarget;

    FAPI_DBG(">> retrieveRepairData");

    do
    {
        if(i_tgtHandle.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP)
        {
            fapi::MBvpdRecord l_vpdRecord = fapi::MBVPD_RECORD_VEIR;

            if(i_vpdType == EREPAIR::EREPAIR_VPD_MNFG)
            {
                l_vpdRecord = fapi::MBVPD_RECORD_MER0;
            }

            // Determine the size of the eRepair data in the VPD
            l_rc = fapiGetMBvpdField(l_vpdRecord,
                                     fapi::MBVPD_KEYWORD_PDI,
                                     i_tgtHandle,
                                     NULL,
                                     l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) during VPD size read",
                        static_cast<uint32_t> (l_rc));
                break;
            }

            if((l_bufSize == 0) ||
               ((i_vpdType == EREPAIR::EREPAIR_VPD_FIELD) &&
                (l_bufSize > EREPAIR::EREPAIR_MEM_FIELD_VPD_SIZE_PER_CENTAUR))||
               ((i_vpdType == EREPAIR::EREPAIR_VPD_MNFG) &&
                (l_bufSize > EREPAIR::EREPAIR_MEM_MNFG_VPD_SIZE_PER_CENTAUR)))
            {
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

            // Retrieve the Field eRepair data from the PNOR
            l_rc = fapiGetMBvpdField(l_vpdRecord,
                                     fapi::MBVPD_KEYWORD_PDI,
                                     i_tgtHandle,
                                     l_retBuf,
                                     l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) during VPD read",
                        static_cast<uint32_t> (l_rc));
                break;
            }
        }
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

            fapi::MvpdRecord l_vpdRecord = fapi::MVPD_RECORD_VWML;

            if(i_vpdType == EREPAIR::EREPAIR_VPD_MNFG)
            {
                l_vpdRecord = fapi::MVPD_RECORD_MER0;
            }

            // Determine the size of the eRepair data in the VPD
            l_rc = fapiGetMvpdField(l_vpdRecord,
                                    fapi::MVPD_KEYWORD_PDI,
                                    l_procTarget,
                                    NULL,
                                    l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) during VPD size read",
                        static_cast<uint32_t> (l_rc));
                break;
            }

            if((l_bufSize == 0) ||
               ((i_vpdType == EREPAIR::EREPAIR_VPD_FIELD) &&
                (l_bufSize > EREPAIR::EREPAIR_P8_MODULE_VPD_FIELD_SIZE)) ||
               ((i_vpdType == EREPAIR::EREPAIR_VPD_MNFG) &&
                (l_bufSize > EREPAIR::EREPAIR_P8_MODULE_VPD_MNFG_SIZE)))
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

            // Retrieve the Field eRepair data from the PNOR
            l_rc = fapiGetMvpdField(l_vpdRecord,
                                    fapi::MVPD_KEYWORD_PDI,
                                    l_procTarget,
                                    l_retBuf,
                                    l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) during VPD read",
                        static_cast<uint32_t> (l_rc));
                break;
            }
        }

        // Parse the buffer to determine eRepair lanes and copy the
        // fail lane numbers to the return vector
        l_rc = determineRepairLanes(i_tgtHandle,
                                    l_retBuf,
                                    l_bufSize,
                                    o_txFailLanes,
                                    o_rxFailLanes);
        if(l_rc)
        {
            FAPI_ERR("determineRepairLanes failed");
            break;
        }
    }while(0);

    // Delete the buffer which has Field eRepair data
    delete[] l_retBuf;

    FAPI_DBG("<< retrieveRepairData");

    return (l_rc);
}

fapi::ReturnCode determineRepairLanes(const fapi::Target   &i_tgtHandle,
                                      uint8_t              *i_buf,
                                      uint32_t             i_bufSz,
                                      std::vector<uint8_t> &o_txFailLanes,
                                      std::vector<uint8_t> &o_rxFailLanes)
{
    uint32_t         l_numRepairs         = 0;
    uint8_t          *l_vpdPtr            = NULL;
    eRepairHeader    *l_vpdHeadPtr        = NULL;
    uint32_t         l_loop               = 0;
    uint32_t         l_bytesParsed        = 0;
    const uint32_t   l_memRepairDataSz    = sizeof(eRepairMemBus);
    const uint32_t   l_fabricRepairDataSz = sizeof(eRepairPowerBus);
    fapi::TargetType l_tgtType            = fapi::TARGET_TYPE_NONE;
    fapi::Target     l_mcsTarget;
    fapi::Target     l_tgtHandle;
    fapi::ReturnCode l_rc;
    fapi::ATTR_CHIP_UNIT_POS_Type l_busNum;

    FAPI_DBG(">> determineRepairLanes");

    do
    {
        l_tgtType = i_tgtHandle.getType();

        // Get the parent chip target
        fapi::Target l_chipTarget = i_tgtHandle;
        if((l_tgtType == fapi::TARGET_TYPE_XBUS_ENDPOINT) ||
           (l_tgtType == fapi::TARGET_TYPE_ABUS_ENDPOINT) ||
           (l_tgtType == fapi::TARGET_TYPE_MCS_CHIPLET))
        {
            l_rc = fapiGetParentChip(i_tgtHandle, l_chipTarget);
            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetParentChip",
                         static_cast<uint32_t>(l_rc));
                break;
            }
        }

        // Get the chip position
        uint32_t l_chipPosition;
        l_rc = FAPI_ATTR_GET(ATTR_POS, &l_chipTarget, l_chipPosition);
        if(l_rc)
        {
            FAPI_ERR("Error (0x%x), from FAPI_ATTR_GET",
                    static_cast<uint32_t>(l_rc));
            break;
        }

        // Read the header and count information
        l_vpdPtr = i_buf; // point to the start of header data
        l_vpdHeadPtr = reinterpret_cast<eRepairHeader *> (l_vpdPtr);

        l_numRepairs = l_vpdHeadPtr->numRecords;

        l_bytesParsed = sizeof(eRepairHeader); // we've read the header data
        l_vpdPtr += sizeof(eRepairHeader); // point to the start of repair data

        // Parse for Power bus data
        if((l_tgtType == fapi::TARGET_TYPE_XBUS_ENDPOINT) ||
           (l_tgtType == fapi::TARGET_TYPE_ABUS_ENDPOINT))
        {
            eRepairPowerBus *l_fabricBus;

            // Read Power bus eRepair data and get the failed lane numbers
            for(l_loop = 0;
                l_loop < l_numRepairs;
                l_loop++, (l_vpdPtr += l_fabricRepairDataSz))
            {
                // Make sure we are not parsing more data than the passed size
                l_bytesParsed += l_fabricRepairDataSz;
                if(l_bytesParsed > i_bufSz)
                {
                    break;
                }

                l_fabricBus = reinterpret_cast<eRepairPowerBus *>(l_vpdPtr);

#ifndef _BIG_ENDIAN
                // We are on a Little Endian system.
                // Need to swap the nibbles of the structure - eRepairPowerBus

                uint8_t l_temp = l_vpdPtr[2];
                l_fabricBus->type = (l_temp >> 4);
                l_fabricBus->interface = (l_temp & 0x0F);
#endif

                // Check if we have the correct Processor ID
                if(l_chipPosition != l_fabricBus->device.processor_id)
                {
                    continue;
                }

                // Check if we have the matching the Fabric Bus types
                if((l_tgtType == fapi::TARGET_TYPE_ABUS_ENDPOINT) &&
                   (l_fabricBus->type != EREPAIR::PROCESSOR_EDI))
                {
                    continue;
                }

                if((l_tgtType == fapi::TARGET_TYPE_XBUS_ENDPOINT) &&
                   (l_fabricBus->type != EREPAIR::PROCESSOR_EI4))
                {
                    continue;
                }

                // Check if we have the matching fabric bus interface
                l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,&i_tgtHandle,l_busNum);
                if(l_rc)
                {
                    FAPI_ERR("Error (0x%x), from FAPI_ATTR_GET",
                            static_cast<uint32_t>(l_rc));
                    break;
                }

                if(l_fabricBus->device.fabricBus != l_busNum)
                {
                    continue;
                }

                // Check if we have valid fail lane numbers
                if(l_fabricBus->failBit == EREPAIR::INVALID_FAIL_LANE_NUMBER)
                {
                    continue;
                }

                // Copy the fail lane numbers in the vectors
                if(l_fabricBus->interface == EREPAIR::PBUS_DRIVER)
                {
                    o_txFailLanes.push_back(l_fabricBus->failBit);
                }
                else if(l_fabricBus->interface == EREPAIR::PBUS_RECEIVER)
                {
                    o_rxFailLanes.push_back(l_fabricBus->failBit);
                }
            } // end of for loop
        } // end of if(l_tgtType is XBus or ABus)
        else if((l_tgtType == fapi::TARGET_TYPE_MCS_CHIPLET) ||
                (l_tgtType == fapi::TARGET_TYPE_MEMBUF_CHIP))
        {
            // Parse for Memory bus data
            eRepairMemBus *l_memBus;
            l_tgtHandle = i_tgtHandle;

            if(l_tgtType == fapi::TARGET_TYPE_MEMBUF_CHIP)
            {
                l_rc = fapiGetOtherSideOfMemChannel(
                                                i_tgtHandle,
                                                l_mcsTarget,
                                                fapi::TARGET_STATE_FUNCTIONAL);

                if(l_rc)
                {
                    FAPI_ERR("determineRepairLanes: Unable to get the connected"
                             " MCS target");
                    break;
                }

                l_tgtHandle = l_mcsTarget;
            }

            // Read Power bus eRepair data and get the failed lane numbers
            for(l_loop = 0;
                l_loop < l_numRepairs;
                l_loop++, (l_vpdPtr += l_memRepairDataSz))
            {
                // Make sure we are not parsing more data than the passed size
                l_bytesParsed += l_memRepairDataSz;
                if(l_bytesParsed > i_bufSz)
                {
                    break;
                }

                l_memBus = reinterpret_cast<eRepairMemBus *>(l_vpdPtr);

#ifndef _BIG_ENDIAN
                // We are on a Little Endian system.
                // Need to swap the nibbles of the structure - eRepairMemBus

                uint8_t l_temp = l_vpdPtr[2];
                l_memBus->type = (l_temp >> 4);
                l_memBus->interface = (l_temp & 0x0F);
#endif

                // Check if we have the correct Processor/Centaur ID
                if(l_chipPosition != l_memBus->device.proc_centaur_id)
                {
                    continue;
                }

                // Check if we have the matching the Memory Bus types
                if(l_memBus->type != EREPAIR::MEMORY_EDI)
                {
                    continue;
                }

                // Check if we have the matching memory bus interface
                l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,&l_tgtHandle,l_busNum);
                if(l_rc)
                {
                    FAPI_ERR("Error (0x%x), from ATTR_CHIP_UNIT_POS",
                            static_cast<uint32_t>(l_rc));
                    break;
                }

                if(l_memBus->device.memChannel != l_busNum)
                {
                    continue;
                }

                // Check if we have valid fail lane numbers
                if(l_memBus->failBit == EREPAIR::INVALID_FAIL_LANE_NUMBER)
                {
                    continue;
                }

                // Copy the fail lane numbers in the vectors
                if(l_tgtType == fapi::TARGET_TYPE_MCS_CHIPLET)
                {
                   if(l_memBus->interface == EREPAIR::DMI_MCS_DRIVE)
                   {
                       o_txFailLanes.push_back(l_memBus->failBit);
                   }
                   else if(l_memBus->interface == EREPAIR::DMI_MCS_RECEIVE)
                   {
                       o_rxFailLanes.push_back(l_memBus->failBit);
                   }
                }
                else if(l_tgtType == fapi::TARGET_TYPE_MEMBUF_CHIP)
                {
                   if(l_memBus->interface == EREPAIR::DMI_MEMBUF_DRIVE)
                   {
                       o_txFailLanes.push_back(l_memBus->failBit);
                   }
                   else if(l_memBus->interface == EREPAIR::DMI_MEMBUF_RECEIVE)
                   {
                       o_rxFailLanes.push_back(l_memBus->failBit);
                   }
                }
            } // end of for loop
        } // end of if(l_tgtType is MCS)

    }while(0);

    FAPI_INF("<< No.of Fail Lanes: tx: %d, rx: %d",
              o_txFailLanes.size(), o_rxFailLanes.size());

    return(l_rc);
}

}// endof extern "C"
