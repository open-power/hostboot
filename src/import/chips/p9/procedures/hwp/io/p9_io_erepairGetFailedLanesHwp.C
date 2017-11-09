/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_erepairGetFailedLanesHwp.C $ */
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
/// @file p9_io_erepairGetFailedLanesHwp.C
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
#include <p9_io_erepairGetFailedLanesHwp.H>
#include <mvpd_access.H>

using namespace EREPAIR;
using namespace fapi2;

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
 * @param[in] i_target      Reference to X-Bus or O-Bus or MCS target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[o]  o_txFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[o]  o_rxFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode retrieveRepairData(
    const fapi2::Target < K >&           i_target,
    erepairVpdType                     i_vpdType,
    const uint8_t                      i_clkGroup,
    std::vector<uint8_t>&              o_txFailLanes,
    std::vector<uint8_t>&              o_rxFailLanes);

/**
 * @brief Function called by the FW Team HWP that parses the data read from
 *        Field VPD. This function matches each eRepair record read from the VPD
 *        and matches it against the attributes of the passed target.
 *        If a match is found, the corresponding eRepair record is copied into
 *        the respective failLane vectors to be returned to the caller.
 *
 * @param[in] i_target      Reference to X-Bus or O-Bus or MCS target
 * @param[in] i_buf         This is the buffer that has the eRepair records
 *                          read from the VPD
 * @param[in] i_bufSz       This is the size of passed buffer in terms of bytes
 * @param[in] i_clkGroup    Specifies clock group 0:[XOA, X1A,..] 1:[X0B, X1B,..]
 * @param[o]  o_txFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[o]  o_rxFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode determineRepairLanes(
    const fapi2::Target < K >&           i_target,
    uint8_t*                           i_buf,
    uint32_t                           i_bufSz,
    const uint8_t                      i_clkGroup,
    std::vector<uint8_t>&              o_txFailLanes,
    std::vector<uint8_t>&              o_rxFailLanes);


/**
 * @brief Function to check if the system has Custom DIMM type (CDIMM).
 *        Attribute ATTR_EFF_CUSTOM_DIMM is read to determine the type.
 * @param[in] i_target      Reference to X-Bus or O-Bus or MCS target
 * @param[o]  o_customDimm  Return value - ENUM_ATTR_EFF_CUSTOM_DIMM_NO
 *                                      or ENUM_ATTR_EFF_CUSTOM_DIMM_YES
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode getDimmType(
    const fapi2::Target < K >&           i_target,
    uint8_t&                           o_customDimm);


/**
 * @brief Function called by the HWP that parses the data read from VPD.
 *        This function scans through failBit field bit pattern and checks
 *        for all bits that are set. For bits SET the corresponding bit positions
 *        marks the failed lane number and is copied into
 *        the respective failLane vectors to be returned to the caller.
 *
 * @param[in] i_target       Reference to X-Bus or O-Bus or MCS target type
 * @param[in] i_busInterface Reference to target sub interface
 * @param[in] i_failBit      This is the failBit field from the eRepair records
 *                           read from the VPD
 * @param[o]  o_FailLanes    Reference to a vector that will hold eRepair fail
 *                           lane numbers of the Rx/Tx sub-interface.
 *
 * @return ReturnCode
 */
template<fapi2::TargetType K>
fapi2::ReturnCode decodeFailedLanes(
    const fapi2::Target < K >&           i_target,
    uint8_t                            i_busInterface,
    uint32_t                           i_failBit,
    std::vector<uint8_t>&              o_FailLanes);

/******************************************************************************
 * Accessor HWP
 *****************************************************************************/

template<fapi2::TargetType K>
fapi2::ReturnCode p9_io_erepairGetFailedLanesHwp(
    const fapi2::Target < K >&          i_target,
    erepairVpdType                    i_vpdType,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>&             o_txFailLanes,
    std::vector<uint8_t>&             o_rxFailLanes)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_INF(">> erepairGetFailedLanesHwp");

    o_txFailLanes.clear();
    o_rxFailLanes.clear();

    // Retrieve the Field eRepair lane numbers from the VPD
    FAPI_TRY( retrieveRepairData(
                  i_target,
                  i_vpdType,
                  i_clkGroup,
                  o_txFailLanes,
                  o_rxFailLanes),
              "p9_io_erepairGetFailedLanesHwp() failed w/rc=0x%x",
              (uint64_t)current_err );

fapi_try_exit:
    return fapi2::current_err;
}

template ReturnCode p9_io_erepairGetFailedLanesHwp<TARGET_TYPE_XBUS>(
    const fapi2::Target <TARGET_TYPE_XBUS>&          i_target,
    erepairVpdType                    i_vpdType,
    const uint8_t                     i_clkGroup,
    std::vector<uint8_t>&             o_txFailLanes,
    std::vector<uint8_t>&             o_rxFailLanes);

template<fapi2::TargetType K>
fapi2::ReturnCode retrieveRepairData(
    const fapi2::Target < K >&         i_target,
    erepairVpdType                   i_vpdType,
    const uint8_t                    i_clkGroup,
    std::vector<uint8_t>&            o_txFailLanes,
    std::vector<uint8_t>&            o_rxFailLanes)
{
    fapi2::ReturnCode                            l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t*                                     l_retBuf = NULL;
    uint32_t                                     l_bufSize = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>  l_procTarget;
#ifdef P9_CUMULUS
    uint8_t                                      l_customDimm;
#endif

    FAPI_DBG(">> retrieveRepairData");

    if(i_target.getType() == fapi2::TARGET_TYPE_MEMBUF_CHIP)
    {
#ifdef P9_CUMULUS
        fapi2::MBvpdRecord l_vpdRecord = fapi2::MBVPD_RECORD_VEIR;

        if(i_vpdType == EREPAIR_VPD_MNFG)
        {
            l_vpdRecord = fapi2::MBVPD_RECORD_MER0;
        }

        // Determine the size of the eRepair data in the VPD
        FAPI_TRY( getMBvpdField(
                      l_vpdRecord,
                      fapi2::MBVPD_KEYWORD_PDI,
                      i_target,
                      NULL,
                      l_bufSize),
                  "VPD size read failed w/rc=0x%x",
                  (uint64_t)current_err );

        // Check whether we have Memory on a CDIMM
        l_rc = getDimmType(i_target, l_customDimm);

        FAPI_ASSERT((uint64_t)l_rc == 0x0,
                    fapi2::P9_EREPAIR_DIMM_TYPE_CHECK_ERR()
                    .set_ERROR(l_rc),
                    "ERROR: DIMM type check");

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
                            .set_ERROR(l_rc),
                            "ERROR: Invalid MEM VPD size");
            }
        }

        // Allocate memory for buffer
        l_retBuf = new uint8_t[l_bufSize];

        FAPI_ASSERT(l_retBuf != NULL,
                    fapi2::P9_EREPAIR_ACCESSOR_HWP_MEMORY_ALLOC_FAIL_ERR()
                    .set_BUF_SIZE(l_bufSize),
                    "ERROR: Failed to allocate memory size");

        // Retrieve the Field eRepair data from the PNOR
        FAPI_TRY( getMBvpdField(
                      l_vpdRecord,
                      fapi2::MBVPD_KEYWORD_PDI,
                      i_target,
                      l_retBuf,
                      l_bufSize),
                  "VPD read failed w/rc=0x%x",
                  (uint64_t)current_err );
#endif
    }
    else
    {
        // Determine the Processor target
        l_procTarget = i_target.template getParent<TARGET_TYPE_PROC_CHIP>();

        fapi2::MvpdRecord l_vpdRecord = fapi2::MVPD_RECORD_VWML;

        if(i_vpdType == EREPAIR_VPD_MNFG)
        {
            l_vpdRecord = fapi2::MVPD_RECORD_MER0;
        }

        // Determine the size of the eRepair data in the VPD
        FAPI_TRY( getMvpdField(
                      l_vpdRecord,
                      fapi2::MVPD_KEYWORD_PDI,
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

        // Retrieve the Field eRepair data from the PNOR
        FAPI_TRY( getMvpdField(
                      l_vpdRecord,
                      fapi2::MVPD_KEYWORD_PDI,
                      l_procTarget,
                      l_retBuf,
                      l_bufSize),
                  "VPD read failed w/rc=0x%x",
                  (uint64_t)current_err );
    }

    // Parse the buffer to determine eRepair lanes and copy the
    // fail lane numbers to the return vector
    FAPI_TRY( determineRepairLanes(
                  i_target,
                  l_retBuf,
                  l_bufSize,
                  i_clkGroup,
                  o_txFailLanes,
                  o_rxFailLanes),
              "Call to determineRepairLanes failed w/rc=0x%x",
              (uint64_t)current_err );

    // Delete the buffer which has Field eRepair data
    delete[] l_retBuf;

    FAPI_DBG("<< retrieveRepairData");

fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K>
fapi2::ReturnCode determineRepairLanes(
    const fapi2::Target < K >&           i_target,
    uint8_t*                           i_buf,
    uint32_t                           i_bufSz,
    const uint8_t                      i_clkGroup,
    std::vector<uint8_t>&              o_txFailLanes,
    std::vector<uint8_t>&              o_rxFailLanes)
{
    uint32_t         l_numRepairs         = 0;
    uint8_t*          l_vpdPtr            = NULL;
    eRepairHeader*    l_vpdHeadPtr        = NULL;
    uint32_t         l_loop               = 0;
    uint32_t         l_bytesParsed        = 0;
    const uint32_t   l_fabricRepairDataSz = sizeof(eRepairPowerBus);
#ifdef P9_CUMULUS
    const uint32_t   l_memRepairDataSz    = sizeof(eRepairMemBus);
    uint8_t                                  l_customDimm;
#endif
    fapi2::TargetType l_tgtType              = fapi2::TARGET_TYPE_NONE;
    fapi2::Target<fapi2::TARGET_TYPE_MCS>     l_mcsTarget;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chipTarget;
    fapi2::ReturnCode                        l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ATTR_CHIP_UNIT_POS_Type           l_busNum;
    bool                                     l_bClkGroupFound = false;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_DBG(">> determineRepairLanes");

    l_tgtType = i_target.getType();

    // Get the parent chip target
    l_chipTarget = i_target.template getParent<TARGET_TYPE_PROC_CHIP>();

    // Get the chip position
    uint32_t l_chipPosition;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POS,
                           l_chipTarget,
                           l_chipPosition));

    // Read the header and count information
    l_vpdPtr = i_buf; // point to the start of header data
    l_vpdHeadPtr = reinterpret_cast<eRepairHeader*> (l_vpdPtr);

    l_numRepairs = l_vpdHeadPtr->availNumRecord;

    l_bytesParsed = sizeof(eRepairHeader); // we've read the header data
    l_vpdPtr += sizeof(eRepairHeader); // point to the start of repair data

    // Parse for Power bus data
    if((l_tgtType == fapi2::TARGET_TYPE_XBUS) ||
       (l_tgtType == fapi2::TARGET_TYPE_OBUS))
    {
        eRepairPowerBus* l_fabricBus;

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

            l_fabricBus = reinterpret_cast<eRepairPowerBus*>(l_vpdPtr);

#ifndef _BIG_ENDIAN
            // We are on a Little Endian system.
            // Need to swap the nibbles of the structure - eRepairPowerBus

            uint8_t l_temp = l_vpdPtr[2];
            l_fabricBus->type = (l_temp >> 4);
            l_fabricBus->interface = (l_temp & 0x0F);
#endif

            // We do not need the check of processor ID because
            // a MVPD read is specific to a Processor

            // Check if we have the matching the Fabric Bus types
            if((l_tgtType == fapi2::TARGET_TYPE_OBUS) &&
               (l_fabricBus->type != PROCESSOR_OPT))
            {
                continue;
            }

            if((l_tgtType == fapi2::TARGET_TYPE_XBUS) &&
               (l_fabricBus->type != PROCESSOR_EDIP))
            {
                continue;
            }

            // Check if we have the matching fabric bus interface
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   i_target,
                                   l_busNum));

            if(l_fabricBus->device.fabricBus != l_busNum)
            {
                continue;
            }

            if(i_clkGroup > 0 && !l_bClkGroupFound)
            {
                l_vpdPtr += l_fabricRepairDataSz;
                l_bClkGroupFound = true;
                continue;
            }

            // Copy the fail lane numbers in the vectors
            if(l_fabricBus->interface == PBUS_DRIVER)
            {
                decodeFailedLanes(i_target, l_fabricBus->interface,
                                  l_fabricBus->failBit, o_txFailLanes);
            }
            else if(l_fabricBus->interface == PBUS_RECEIVER)
            {
                decodeFailedLanes(i_target, l_fabricBus->interface,
                                  l_fabricBus->failBit, o_rxFailLanes);
            }
        } // end of for loop
    } // end of if(l_tgtType is XBus or OBus)
    else if((l_tgtType == fapi2::TARGET_TYPE_MCS_CHIPLET) ||
            (l_tgtType == fapi2::TARGET_TYPE_MEMBUF_CHIP))
    {
#ifdef P9_CUMULUS
        // Parse for Memory bus data
        eRepairMemBus* l_memBus;

        if(l_tgtType == fapi2::TARGET_TYPE_MEMBUF_CHIP)
        {
            l_rc = fapiGetOtherSideOfMemChannel(
                       i_target,
                       l_mcsTarget,
                       fapi2::TARGET_STATE_FUNCTIONAL);

            FAPI_ASSERT((uint64_t)l_rc == 0x0,
                        fapi2::P9_EREPAIR_UNABLE_CONNECT_MCS_TARGET_ERR()
                        .set_ERROR(l_rc),
                        "ERROR: determineRepairLanes: Unable to get the connected to MCS target");

            // Check whether we have Memory on a CDIMM
            l_rc = getDimmType(i_target, l_customDimm);

            FAPI_ASSERT((uint64_t)l_rc == 0x0,
                        fapi2::P9_EREPAIR_DIMM_TYPE_CHECK_ERR()
                        .set_ERROR(l_rc),
                        "ERROR: DIMM type check");
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

            l_memBus = reinterpret_cast<eRepairMemBus*>(l_vpdPtr);

#ifndef _BIG_ENDIAN
            // We are on a Little Endian system.
            // Need to swap the nibbles of the structure - eRepairMemBus

            uint8_t l_temp = l_vpdPtr[2];
            l_memBus->type = (l_temp >> 4);
            l_memBus->interface = (l_temp & 0x0F);
#endif

            // Check if we have the correct Centaur ID
            // NOTE: We do not prefer to make the check of Centaur ID if the
            // system is known to have CDIMMs. This check is applicable
            // only for systems with ISDIMM because in the ISDIMM systems
            // the Lane eRepair data for multiple Centaurs is maintained in
            // a common VPD.

            if((l_tgtType == fapi2::TARGET_TYPE_MEMBUF_CHIP)     &&
               (l_customDimm != fapi2::ENUM_ATTR_SPD_CUSTOM_YES) &&
               (l_chipPosition != l_memBus->device.proc_centaur_id))
            {
                continue;
            }

            // Check if we have the matching the Memory Bus types
            if(l_memBus->type != MEMORY_EDIP)
            {
                continue;
            }

            // Check if we have the matching memory bus interface
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   l_mcsTarget,
                                   l_busNum));

            if(l_memBus->device.memChannel != l_busNum)
            {
                continue;
            }

            // Copy the fail lane numbers in the vectors
            if(l_tgtType == fapi2::TARGET_TYPE_MCS_CHIPLET)
            {
                if(l_memBus->interface == DMI_MCS_DRIVE)
                {
                    decodeFailedLanes(i_target, l_memBus->interface,
                                      l_memBus->failBit, o_txFailLanes);
                }
                else if(l_memBus->interface == DMI_MCS_RECEIVE)
                {
                    decodeFailedLanes(i_target, l_memBus->interface,
                                      l_memBus->failBit, o_rxFailLanes);
                }
            }
            else if(l_tgtType == fapi2::TARGET_TYPE_MEMBUF_CHIP)
            {
                if(l_memBus->interface == DMI_MEMBUF_DRIVE)
                {
                    decodeFailedLanes(i_target, l_memBus->interface,
                                      l_memBus->failBit, o_txFailLanes);
                }
                else if(l_memBus->interface == DMI_MEMBUF_RECEIVE)
                {
                    decodeFailedLanes(i_target, l_memBus->interface,
                                      l_memBus->failBit, o_rxFailLanes);
                }
            }
        } // end of for loop

#endif
    } // end of if(l_tgtType is MCS)

    FAPI_INF("<< No.of Fail Lanes: tx: %zd, rx: %zd",
             o_txFailLanes.size(), o_rxFailLanes.size());

fapi_try_exit:
    return fapi2::current_err;
}

template<fapi2::TargetType K>
fapi2::ReturnCode getDimmType(
    const fapi2::Target < K >&           i_target,
    uint8_t&                                                 o_customDimm)
{
    fapi2::ReturnCode                                          l_rc = fapi2::FAPI2_RC_SUCCESS;
#ifdef P9_CUMULUS
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MBA_CHIPLET>> l_mbaChiplets;
    fapi2::Target<fapi2::TARGET_TYPE_MBA>                      l_mbaTarget;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_target_dimm_array;

    o_customDimm = fapi2::ENUM_ATTR_SPD_CUSTOM_NO;

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
    l_rc =  fapiGetAssociatedDimms(l_mbaTarget, l_target_dimm_array);

    FAPI_ASSERT( (uint64_t)l_rc == 0x0,
                 fapi2::P9_EREPAIR_GET_ASSOCIATE_DIMMS_ERR()
                 .set_ERROR(l_rc),
                 "ERROR: from fapiGetAssociatedDimms");

    if(0 != l_target_dimm_array.size())
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SPD_CUSTOM,
                               l_target_dimm_array[0],
                               o_customDimm));
    }
    else
    {
        o_customDimm = fapi2::ENUM_ATTR_SPD_CUSTOM_NO;
    }

fapi_try_exit:
#endif
    return l_rc;
}

template<fapi2::TargetType K>
fapi2::ReturnCode decodeFailedLanes(
    const fapi2::Target < K >&           i_target,
    uint8_t                                                  i_busInterface,
    uint32_t                                                 i_failBit,
    std::vector<uint8_t>&                                    o_FailLanes)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t           loop;
    uint8_t           maxBusLanes       = 0;
    uint32_t          checkBitPosition  = (0x80000000);

    FAPI_DBG(">> decodeFailedLanes");

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
            (i_target.getType() == fapi2::TARGET_TYPE_MCS_CHIPLET) ||
            (i_target.getType() == fapi2::TARGET_TYPE_MCS)) //DMI
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

    //Check for all the failed bit SET in the bit stream and update the vector
    //And print the failed lanes
    FAPI_INF("No. of Failed Lanes:");

    for( loop = 0;
         loop < maxBusLanes;
         loop++ )
    {
        if( i_failBit & ( checkBitPosition >> loop ) )
        {
            o_FailLanes.push_back(loop);
            FAPI_INF("%d", loop);
        }
    }

    FAPI_DBG("<< decodeFailedLanes");
    return l_rc;
}

