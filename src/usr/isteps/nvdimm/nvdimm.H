/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimm.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2019                        */
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

#ifndef NVDIMM_H__
#define NVDIMM_H__

#include <usr/errl/errlentry.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <i2c/eepromif.H>
#include <map>

using namespace EEPROM;

// Trace definition
extern trace_desc_t* g_trac_nvdimm;

namespace NVDIMM
{

//Defining necessary offsets for page0
//Refer to BAEBI spec for details
//https://www.jedec.org/standards-documents/docs/jesd245a
enum i2cReg : uint8_t
{
    ARM_CMD                 = 0x45,
    ARM_STATUS              = 0x6A,
    NVDIMM_FUNC_CMD         = 0x43,
    NVDIMM_CMD_STATUS0      = 0x61,
    CSAVE_INFO              = 0x80,
    CSAVE_STATUS            = 0x64,
    RESTORE_STATUS          = 0x66,
    SET_ES_POLICY_CMD       = 0x49,
    SET_ES_POLICY_STATUS    = 0x70,
    NVDIMM_MGT_CMD0         = 0x40,
    ERASE_STATUS            = 0x68,
    MODULE_HEALTH           = 0xA0,
    MODULE_HEALTH_STATUS0   = 0xA1,
    MODULE_HEALTH_STATUS1   = 0xA2,
    OPEN_PAGE               = 0x00,
    NVDIMM_READY            = 0x60,
};

// Up to 10 pages per BAEBI Spec,
// but use page 0 mostly
enum page : uint8_t
{
    ZERO  = 0x00,
    ONE   = 0x01,
    TWO   = 0x02,
    THREE = 0x03,
    FOUR  = 0x04,
};

// Enums for inputs/expected output to/from the i2c registers
enum i2c_in_values : uint8_t
{
    ARM_RESETN_AND_ATOMIC_SAVE_AND_ERASE        = 0x84,
    ARM_RESETN                                  = 0x04,
    ES_DEV_MANAGE                               = 0x01, //0x01 for device manage
    ERASE_IMAGE                                 = 0x08,
    RESTORE_IMAGE                               = 0x04,
    RESET_CTRLR                                 = 0x01,
    VALID_IMAGE                                 = 0x01,
};

enum i2c_out_values : uint8_t
{
    SAVE_IN_PROGRESS            = 0x05,
    RSTR_IN_PROGRESS            = 0x09,
    ERASE_IN_PROGRESS           = 0x11,
    ARM_IN_PROGRESS             = 0x41,
    CHARGE_IN_PROGRESS          = 0x41,
    SAVE_SUCCESS                = 0x01,
    RSTR_SUCCESS                = 0X01,
    ARM_SUCCESS                 = 0X09,
    ERASE_SUCCESS               = 0X01,
    ES_SUCCESS                  = 0x05,
    CHARGE_SUCCESS              = 0x00,
    NV_READY                    = 0xA5,
};

// Timeout-related enum
enum timeout : uint32_t
{
    OPS_POLL_TIME_MS = 5000,
    PAGE_SWITCH_POLL_TIME_NS    = 100,
};

// Assign an id to each of the 6 major ops
enum ops_id : uint8_t
{
    SAVE = 0,
    RESTORE,
    ERASE,
    ARM,
    PAGE_SWITCH,
    CHARGE,
};

/**
 * @brief Wrapper to call deviceOp to read the NV controller via I2C
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_addr - address/offset for the register to be read
 *
 * @param[out] o_data - returned data from read
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmReadReg(TARGETING::Target* i_nvdimm, uint8_t i_addr, uint8_t & o_data );

/**
 * @brief Wrapper to call deviceOp to write the NV controller via I2C
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_addr - address/offset for the register to be written
 *
 * @param[in] i_data - data to register
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmWriteReg(TARGETING::Target* i_nvdimm, uint8_t i_addr, uint8_t  i_data );

/**
 * @brief This function polls the status register for the given ops_id
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[in] i_ops_id - id assigned to each operation in nvdimm.H
 *
 * @param[out] o_poll - total polled time in ms
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmPollStatus(TARGETING::Target *i_nvdimm, ops_id i_ops_id, uint32_t &o_poll);
} //End NVDIMM namespace


#endif  // NVDIMM_H__
