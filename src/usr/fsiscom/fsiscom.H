/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsiscom/fsiscom.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#ifndef __FSISCOM_H
#define __FSISCOM_H

/** @file  fsiscom.H
 *  @brief Provides the interfaces to perform a FSI SCOM
 */

namespace FSISCOM
{

  enum {
    //FSI addresses are byte offsets, so need to multiply by 4
    // since each register is 4 bytes long.
    // prefix with 0x10xx for FSI2PIB engine offset
    DATA0_REG         = 0x1000,  /* SCOM Data Register 0 (0x00) */
    DATA1_REG         = 0x1004,  /* SCOM Data Register 1 (0x01) */
    COMMAND_REG       = 0x1008,  /* SCOM Command Register (0x02) */
    ENGINE_RESET_REG  = 0x1018,  /* Engine Reset Register (0x06) */
    STATUS_REG        = 0x101C,  /* STATUS Register (0x07) */
    PIB_RESET_REG     = 0x101C,  /* PIB Reset Register (0x07) */

    PARITY_CHECK      = 0x04000000, /* 5= Parity check error */
    PROTECTION_CHECK  = 0x01000000, /* 7= Blocked due to secure mode */
    PIB_ABORT_BIT     = 0x00100000, /* 12= PIB Abort */
    PIB_ERROR_BITS    = 0x00007000, /* 17:19= PCB/PIB Errors */
    ANY_ERROR_BIT     = PARITY_CHECK |
                        PROTECTION_CHECK |
                        PIB_ABORT_BIT |
                        PIB_ERROR_BITS
  };

/**
 * @brief Performs an FSI SCOM operation
 * This function performs an SCom Read/Write operation. It follows a
 * pre-defined prototype functions in order to be registered with the
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        SCom target
 * @param[in/out] io_buffer     Read: pointer to output data storage
 *                              Write: pointer to data to be written
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output: Read: size of output data
 *                                      Write: size of data written
 * @param[in]   i_accessType    Select from DeviceFW::AccessType enum
 *                              (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the SCom address value.
 *
 * @return  errlHndl_t
 */
errlHndl_t fsiScomPerformOp(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args);






}; // End namespace

#endif
