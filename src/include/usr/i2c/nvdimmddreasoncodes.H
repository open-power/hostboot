/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/nvdimmddreasoncodes.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2018                        */
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
 * @file nvdimmddreasoncodes.H
 *
 * @brief Reason codes and module ids for the NVDIMM device driver
 *
 */
#ifndef __NVDIMMDDREASONCODES_H
#define __NVDIMMDDREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace NVDIMM
{

/**
* @enum nvdimmModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum nvdimmModuleId
{
    NVDIMM_INVALID_MODULE                   = 0x00,     // Invalid Module Id
    NVDIMM_PERFORM_OP                       = 0x01,
    NVDIMM_READ                             = 0x02,
    NVDIMM_WRITE                            = 0x03,
    NVDIMM_PREPAREADDRESS                   = 0x04,
    NVDIMM_READATTRIBUTES                   = 0x05,
    NVDIMM_GETI2CMASTERTARGET               = 0x06,
    NVDIMM_CROSSESNVDIMMPAGEBOUNDARY        = 0x07,
};

/**
 * @enum nvdimmReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum nvdimmReasonCode
{
    NVDIMM_INVALID_REASONCODE               = NVDIMM_COMP_ID | 0x00,   // Invalid Reasoncode
    NVDIMM_INVALID_OPERATION                = NVDIMM_COMP_ID | 0x01,
    NVDIMM_INVALID_DEVICE_TYPE              = NVDIMM_COMP_ID | 0x02,
    NVDIMM_ATTR_INFO_NOT_FOUND              = NVDIMM_COMP_ID | 0x03,
    NVDIMM_INVALID_CHIP                     = NVDIMM_COMP_ID | 0x04,
    NVDIMM_I2C_MASTER_PATH_ERROR            = NVDIMM_COMP_ID | 0x05,
    NVDIMM_TARGET_NULL                      = NVDIMM_COMP_ID | 0x06,
    NVDIMM_INVALID_ADDR_OFFSET_SIZE         = NVDIMM_COMP_ID | 0x07,
    NVDIMM_OVERFLOW_ERROR                   = NVDIMM_COMP_ID | 0x08,
    NVDIMM_I2C_WRITE_PAGE_SIZE_ZERO         = NVDIMM_COMP_ID | 0x09,
    NVDIMM_INVALID_OFFSET                   = NVDIMM_COMP_ID | 0x0A,
};

enum UserDetailsTypes
{
        NVDIMM_UDT_NO_FORMAT       = 0x0,
        NVDIMM_UDT_PARAMETERS      = 0x1,
};

};  // end NVDIMM

#endif
