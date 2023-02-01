/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio_ocmb_common.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
#ifndef __MMIO_OCMB_COMMON_H
#define __MMIO_OCMB_COMMON_H

/**
 * @file  mmio_ocmb_common.H
 * @brief Constants and interfaces that are common to multiple types of OCMB
 *        implementations, specifically Explorer and Odyssey.
 */

#include <errl/errlentry.H>
#include <targeting/common/target.H>

namespace MMIOCOMMON
{

// Odyssey MMIO addresses only have 35 bits
constexpr uint64_t MASK_35BITS = 0x7FFFFFFFFull;

// The SCOM portion of the MMIO range is at 4GB (see comments in mmio.C).
constexpr uint64_t OCMB_IB_MMIO_OFFSET = 4*GIGABYTE;

/**
 * @brief Convert a scom address to the equivalent MMIO offset
 *
 *  From the Odyssey workbook:
 *    The MMIO logic takes the incoming 35 bit OpenCAPI Physical Address
 *    and shifts this right by three bits to obtain the 32-bit PIB address.
 *
 * @param[in] i_scomAddr  SCOM Address
 * @return MMIO Offset
 */
#define MMIOCOMMON_scom_to_offset(_scomAddr) \
  ((MMIOCOMMON::OCMB_IB_MMIO_OFFSET | (_scomAddr << 3)))


/**
 * @brief Possible Open CAPI response codes for config operations
 */
enum
{
    OCAPI_RETRY_REQUEST         = 0x2,
    OCAPI_DATA_ERROR            = 0x8,
    OCAPI_UNSUPPORTED_OP_LENGTH = 0x9,
    OCAPI_BAD_ADDRESS           = 0xB,
    OCAPI_FAILED                = 0xE,
};

/**
 * @brief Possible PCB error codes for non-config operations
 */
enum
{
    PCB_OK                      = 0x0,
    PCB_INVALID_ADDRESS         = 0x4,
    PCB_PARITY_ERROR            = 0x6,
    PCB_TIMEOUT                 = 0x7,
};

/**
 * @brief List of common registers for the OCMBs
 */
enum RegNames_t
{
    MCFGERR,
    MCFGERRA,
    MMIOERR,

    RegNames_t_SIZE
};

/**
 * @brief bit-field definitions for MCFGERR register
 */
typedef union mcfgerrReg
{
    struct
    {
        uint64_t reserved           :16;
        uint64_t resp_code          :4;
        uint64_t bdi                :1;
        uint64_t error_type         :3;
        uint64_t device             :5;
        uint64_t function           :3;
        uint64_t dev_func_mismatch  :1;
        uint64_t detect_bad_op      :1;
        uint64_t tbit_is_1          :1;
        uint64_t data_is_bad        :1;
        uint64_t pl_is_invalid      :1;
        uint64_t bad_op_or_align    :1;
        uint64_t addr_no_implemented:1;
        uint64_t rdata_vld          :1;
        uint64_t tbit               :1;
        uint64_t plen               :3;
        uint64_t portnun            :2;
        uint64_t dl                 :2;
        uint64_t capptag            :16;
    };
    uint64_t word64;
}mcfgerrReg_t;


/**
 *
 * @brief Determine if the OCMB detected a failure on a specific MMIO
 *        transaction to the specified OCMB target.
 *
 * @param[in] i_expTarget Handle for the target OCMB chip.
 * @param[in] i_va Virtual address of the transaction to check
 * @param[in] i_accessLimit The byte range of the transaction
 * @param[in] i_offset The offset of the config reg, scom reg, MSCC reg or
 *            SRAM to be accessed on the explorer chip.
 * @param[in] i_opType The operation type (read or write)
 * @param[out] o_errorAddressMatches Set to true if the OCMB chip detected a
 *             failure and the failing address matches our transaction.
 * @param[out] o_errorAddressIsZero Set to true if no error has been detected
 *             by the OCMB side of the bus.
 *
 * Zero=TRUE -> Error was not detected by OCMB
 * Matches=TRUE -> Error was caused/detected by this transaction
 * Zero=FALSE,MATCHES=FALSE -> Error was detected but it doesn't seem related
 *    to this transaction
 *
 * @return nullptr on succesful read of OCMB error status, non-null otherwise.
 *
 */
errlHndl_t checkOcmbError(const TARGETING::TargetHandle_t i_ocmbTarget,
                          const uint64_t i_va,
                          const uint64_t i_accessLimit,
                          const uint64_t i_offset,
                          DeviceFW::OperationType i_opType,
                          bool& o_errorAddressMatches,
                          bool& o_errorAddressIsZero);


}; //namespace MMIOCOMMON

#endif //__MMIO_OCMB_COMMON_H
