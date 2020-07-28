/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/tpmddreasoncodes.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
/**
 * @file tpmddreasoncodes.H
 *
 * @brief Reason codes and module ids for the TPM device driver
 *
 */
#ifndef __TPMDDREASONCODES_H
#define __TPMDDREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace TPMDD
{

/**
* @enum tpmModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum tpmModuleId
{
    TPMDD_INVALID_MODULE                   = 0x00,     // Invalid Module Id
    TPMDD_PERFORM_OP                       = 0x01,
    TPMDD_READ                             = 0x02,
    TPMDD_WRITE                            = 0x03,
    TPMDD_PREPAREADDRESS                   = 0x04,
    TPMDD_READATTRIBUTES                   = 0x05,
    TPMDD_GETI2CMASTERTARGET               = 0x06, // NO LONGER USED
    TPMDD_POLLFORCOMMMANDREADY             = 0x07,
    TPMDD_POLLFORDATAAVAIL                 = 0x08,
    TPMDD_WRITEFIFO                        = 0x09,
    TPMDD_READFIFO                         = 0x0A,
    TPMDD_READSTSREGVALID                  = 0x0B,
    TPMDD_TPMPRESENCEDETECT                = 0x0C,
    TPMDD_TPMPRESENCE                      = 0x0D,
    TPMDD_GETSPICONTROLLERTARGET           = 0x0E,
};

/**
 * @enum tpmReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum tpmReasonCode
{
    TPM_INVALID_REASONCODE               = TPMDD_COMP_ID | 0x00,
    TPM_INVALID_OPERATION                = TPMDD_COMP_ID | 0x01,
    TPM_INVALID_DEVICE_TYPE              = TPMDD_COMP_ID | 0x02,
    TPM_ATTR_INFO_NOT_FOUND              = TPMDD_COMP_ID | 0x03,
    TPM_INVALID_CHIP                     = TPMDD_COMP_ID | 0x04,
    TPM_I2C_MASTER_PATH_ERROR            = TPMDD_COMP_ID | 0x05,  // NO LONGER USED
    TPM_TARGET_NULL                      = TPMDD_COMP_ID | 0x06,
    TPM_INVALID_ADDR_OFFSET_SIZE         = TPMDD_COMP_ID | 0x07,
    TPM_OVERFLOW_ERROR                   = TPMDD_COMP_ID | 0x08,
    TPM_UNDERFLOW_ERROR                  = TPMDD_COMP_ID | 0x09,
    TPM_TIMEOUT                          = TPMDD_COMP_ID | 0x0A,
    TPM_DISABLED_VIA_MRW                 = TPMDD_COMP_ID | 0x0B,
    TPM_BUS_SPEED_LOOKUP_FAIL            = TPMDD_COMP_ID | 0x0C,
    TPM_RC_TPM_NOT_DETECTED              = TPMDD_COMP_ID | 0x0D,
    TPM_RC_UNEXPECTED_VENDOR_ID          = TPMDD_COMP_ID | 0x0E,
    TPM_RC_UNEXPECTED_FAMILY_ID          = TPMDD_COMP_ID | 0x0F, // NO LONGER USED
    TPM_ATTR_MODEL_NOT_FOUND             = TPMDD_COMP_ID | 0x10,
    TPM_ATTR_INVALID_MODEL               = TPMDD_COMP_ID | 0x11,
    TPM_SPI_CONTROLLER_PATH_ERROR        = TPMDD_COMP_ID | 0x12,
    TPM_ATTR_TPM_ENABLED_NOT_FOUND       = TPMDD_COMP_ID | 0x13,
    TPM_EXTRA_DATA_AVAILABLE             = TPMDD_COMP_ID | 0x14,

};

};  // end TPMDD

#endif
