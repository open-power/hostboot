/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/erepairGetMnfgFailedLanesHwp.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
 *  @file erepairGetMnfgFailedLanesHwp.C
 *
 *  @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses
 *         from the Manufacturing VPD.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     12/02/2012  Created.
 */

#include <erepairGetMnfgFailedLanesHwp.H>

extern "C"
{

// TODO: RTC Task: 69592. Refactor eRepair code to remove this file and change
// the erepairGetFailedLanesHwp.C file to read Manufacturing VPD

/*****************************************************************************e
 * Forward Declarations
 *****************************************************************************/

/**
 * @brief Function called by the FW Team HWP that reads the data from Mnfg VPD.
 *        This function makes the actual calls to read the VPD.
 *        It determines the size of the buffer to be read, allocates memory
 *        of the determined size, calls fapiGetMvpdField to read the eRepair
 *        records. This buffer is further passed to another routine for
 *        parsing.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS target
 * @param[o]  o_txFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[o]  o_rxFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 */
fapi::ReturnCode retrieveMnfgRepairData(const fapi::Target   &i_tgtHandle,
                                        std::vector<uint8_t> &o_txFailLanes,
                                        std::vector<uint8_t> &o_rxFailLanes);

/**
 * @brief Function called by the FW Team HWP that parses the data read from
 *        Mnfg VPD. This function matches each eRepair record read from the VPD
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
fapi::ReturnCode determineMnfgRepairLanes(const fapi::Target   &i_tgtHandle,
                                          uint8_t              *i_buf,
                                          uint32_t             i_bufSz,
                                          std::vector<uint8_t> &o_txFailLanes,
                                          std::vector<uint8_t> &o_rxFailLanes);


/******************************************************************************
 * Accessor HWP
 *****************************************************************************/

fapi::ReturnCode erepairGetMnfgFailedLanesHwp(const fapi::Target   &i_tgtHandle,
                                              std::vector<uint8_t> &o_txFailLanes,
                                              std::vector<uint8_t> &o_rxFailLanes)
{
    fapi::ReturnCode l_rc;
    fapi::TargetType l_tgtType = fapi::TARGET_TYPE_NONE;
    std::vector<fapi::Target> l_mcsChiplets;

    FAPI_INF(">> erepairGetMnfgFailedLanesHwp: i_tgtHandle: %s",
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
            FAPI_ERR("erepairGetMnfgFailedLanesHwp: Invalid Target type %d",
                    l_tgtType);
            FAPI_SET_HWP_ERROR(l_rc, RC_ACCESSOR_HWP_INVALID_TARGET_TYPE);
            break;
        }

        // Retrieve the Manufacturing eRepair lane numbers from the VPD
        l_rc = retrieveMnfgRepairData(i_tgtHandle,
                                      o_txFailLanes,
                                      o_rxFailLanes);

        if(l_rc)
        {
            FAPI_ERR("Error (0x%x) during retrieval of Mfg records",
                    static_cast<uint32_t>(l_rc));
            break;
        }
    }while(0);

    FAPI_INF("<< erepairGetMnfgFailedLanesHwp");

    return l_rc;
}


fapi::ReturnCode retrieveMnfgRepairData(const fapi::Target   &i_tgtHandle,
                                        std::vector<uint8_t> &o_txFailLanes,
                                        std::vector<uint8_t> &o_rxFailLanes)
{
    fapi::ReturnCode l_rc;
    uint8_t          *l_retBuf = NULL;
    uint32_t         l_bufSize = 0;
    fapi::Target     l_procTarget;

    FAPI_INF(">> retrieveMnfgRepairData");

    do
    {
        if(i_tgtHandle.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP)
        {
            // Determine the size of the eRepair data in the VPD
            l_rc = fapiGetMBvpdField(fapi::MBVPD_RECORD_MER0,
                                     fapi::MBVPD_KEYWORD_PDI,
                                     i_tgtHandle,
                                     NULL,
                                     l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetMBvpdField",
                        static_cast<uint32_t> (l_rc));
                break;
            }

            if((l_bufSize == 0) ||
               (l_bufSize > EREPAIR::EREPAIR_MEM_MNFG_VPD_SIZE_PER_CENTAUR))
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
            l_rc = fapiGetMBvpdField(fapi::MBVPD_RECORD_MER0,
                                     fapi::MBVPD_KEYWORD_PDI,
                                     i_tgtHandle,
                                     l_retBuf,
                                     l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetMBvpdField",
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

            // Determine the size of the eRepair data in the VPD
            l_rc = fapiGetMvpdField(fapi::MVPD_RECORD_MER0,
                                    fapi::MVPD_KEYWORD_PDI,
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
               (l_bufSize > EREPAIR::EREPAIR_P8_MODULE_VPD_MNFG_SIZE))
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
            l_rc = fapiGetMvpdField(fapi::MVPD_RECORD_MER0,
                                    fapi::MVPD_KEYWORD_PDI,
                                    l_procTarget,
                                    l_retBuf,
                                    l_bufSize);

            if(l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetMvpdField",
                        static_cast<uint32_t> (l_rc));
                break;
            }
        }

        // Parse the buffer to determine eRepair lanes and copy the
        // fail lane numbers to the return vector
        l_rc = determineMnfgRepairLanes(i_tgtHandle,
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

    FAPI_INF("<< retrieveMnfgRepairData");

    return (l_rc);
}

fapi::ReturnCode determineMnfgRepairLanes(const fapi::Target   &i_tgtHandle,
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

    FAPI_INF(">> determineMnfgRepairLanes");

    do
    {
        // Read the header and count information

        l_vpdPtr = i_buf; // point to the start of header data
        l_vpdHeadPtr = reinterpret_cast<eRepairHeader *> (l_vpdPtr);

        l_numRepairs = l_vpdHeadPtr->numRecords;

        l_bytesParsed = sizeof(eRepairHeader); // we've read the header data
        l_vpdPtr += sizeof(eRepairHeader); // point to the start of repair data

        l_tgtType = i_tgtHandle.getType();

        // Parse for Power bus data
        if((l_tgtType == fapi::TARGET_TYPE_XBUS_ENDPOINT) ||
           (l_tgtType == fapi::TARGET_TYPE_ABUS_ENDPOINT))
        {
            eRepairPowerBus l_fabricBus;

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

                // TODO: RTC task 71260
                // Investigate if there is an Endianess issue with
                // the memcpy and fix it.
                memcpy(&l_fabricBus, l_vpdPtr, l_fabricRepairDataSz);

                // Check if we have the correct Processor ID
                // Get the MRU ID of the passed processor target and
                // match with l_fabricBus.device.processor_id.
                // Note: This is currently not required.

                // Check if we have the matching the Fabric Bus types
                if((l_fabricBus.type != EREPAIR::PROCESSOR_EI4) &&
                   (l_fabricBus.type != EREPAIR::PROCESSOR_EDI))
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

                if(l_fabricBus.device.fabricBus != l_busNum)
                {
                    continue;
                }

                // Check if we have valid fail lane numbers
                if(l_fabricBus.failBit == EREPAIR::INVALID_FAIL_LANE_NUMBER)
                {
                    continue;
                }

                // Copy the fail lane numbers in the vectors
                if(l_fabricBus.interface == EREPAIR::PBUS_DRIVER)
                {
                    o_txFailLanes.push_back(l_fabricBus.failBit);
                }
                else if(l_fabricBus.interface == EREPAIR::PBUS_RECEIVER)
                {
                    o_rxFailLanes.push_back(l_fabricBus.failBit);
                }
            } // end of for loop
        } // end of if(l_tgtType is XBus or ABus)
        else if((l_tgtType == fapi::TARGET_TYPE_MCS_CHIPLET) ||
                 (l_tgtType == fapi::TARGET_TYPE_MEMBUF_CHIP))
        {
            // Parse for Memory bus data
            eRepairMemBus l_memBus;
            l_tgtHandle = i_tgtHandle;

            if(l_tgtType == fapi::TARGET_TYPE_MEMBUF_CHIP)
            {
                l_rc = fapiGetOtherSideOfMemChannel(
                                                i_tgtHandle,
                                                l_mcsTarget,
                                                fapi::TARGET_STATE_FUNCTIONAL);

                if(l_rc)
                {
                    FAPI_ERR("determineMnfgRepairLanes: Unable to get the"
                             " connected MCS target");
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

                // TODO: RTC task 71260
                // Investigate if there is an Endianess issue with
                // the memcpy and fix it.
                memcpy(&l_memBus, l_vpdPtr, l_memRepairDataSz);

                // Check if we have the correct Processor ID
                // Get the MRU ID of the passed processor target and
                // match with l_memBus.device.processor_id
                // Note: This is currently not required.

                // Check if we have the matching the Memory Bus types
                if(l_memBus.type != EREPAIR::MEMORY_EDI)
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

                if(l_memBus.device.memChannel != l_busNum)
                {
                    continue;
                }

                // Check if we have valid fail lane numbers
                if(l_memBus.failBit == EREPAIR::INVALID_FAIL_LANE_NUMBER)
                {
                    continue;
                }

                // Copy the fail lane numbers in the vectors
                if(l_tgtType == fapi::TARGET_TYPE_MCS_CHIPLET)
                {
                    if(l_memBus.interface == EREPAIR::DMI_MCS_DRIVE)
                    {
                        o_txFailLanes.push_back(l_memBus.failBit);
                    }
                    else if(l_memBus.interface == EREPAIR::DMI_MCS_RECEIVE)
                    {
                        o_rxFailLanes.push_back(l_memBus.failBit);
                    }
                }
                if(l_tgtType == fapi::TARGET_TYPE_MEMBUF_CHIP)
                {
                    if(l_memBus.interface == EREPAIR::DMI_MEMBUF_DRIVE)
                    {
                        o_txFailLanes.push_back(l_memBus.failBit);
                    }
                    else if(l_memBus.interface == EREPAIR::DMI_MEMBUF_RECEIVE)
                    {
                        o_rxFailLanes.push_back(l_memBus.failBit);
                    }
                }
            } // end of for loop
        } // end of if(l_tgtType is MCS)

    }while(0);

    FAPI_INF("<< determineMnfgRepairLanes");

    return(l_rc);
}

}// endof extern "C"
