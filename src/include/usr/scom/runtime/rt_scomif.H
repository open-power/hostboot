/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scom/runtime/rt_scomif.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#ifndef __RT_SCOMIF_H
#define __RT_SCOMIF_H

#include <devicefw/driverif.H>

namespace SCOM
{

/**
 * @brief This function sends the scom op to the Hypervisor
 *
 * @param[in]           i_opType         Scom operation type
 * @param[in]           i_target         Scom target
 * @param[in]           i_scomAddr       Scom address
 * @param[in|out]       io_buffer        Pointer to scom data
 * @return  errlHndl_t
 */
errlHndl_t sendScomToHyp(DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         uint64_t i_scomAddr,
                         void * io_buffer);

};  // end namespace SCOM

namespace SBESCOM
{

/**
 * @brief OMI channel has checkstopped.  Mark it bad and switch to FSP->SBE access.
 *
 * @param[in]     i_ocmb    OCMB SCOM target
 * @return  None
 */
void switchToSbeScomAccess(TARGETING::TargetHandle_t i_ocmb);

};  // end namespace SBESCOM

namespace FSISCOM
{

/**
 * @brief This function sends the scom op to the FSP
 *
 * @param[in]     i_opType    Scom operation type, see driverif.H
 * @param[in]     i_target    Scom target
 * @param[in]     i_scomAddr  Scom address
 * @param[in/out] io_buffer   Read: Pointer to output data storage
 *                            Write: Pointer to input data storage
 * @return  errlHndl_t
 */
errlHndl_t sendScomOpToFsp(DeviceFW::OperationType   i_opType,
                           TARGETING::TargetHandle_t i_target,
                           uint64_t                  i_scomAddr,
                           void *                    io_buffer);

/**
 * @brief Ask FSP to read list of SCOMs
 *
 * @param[in]     i_target    Scom target
 * @param[in]     i_scomAddr  Scom addresses to read
 * @param[out]    o_scomValue Scom values read (0xDEADBEEF for errors)
 * @return  errlHndl_t
 */
errlHndl_t sendMultiScomReadToFsp(TARGETING::TargetHandle_t i_target,
                                  std::vector<uint64_t> &   i_scomAddr,
                                  std::vector<uint64_t> &   o_scomValue);

};  // end namespace FSISCOM

#endif  // end __RT_SCOMIF_H
