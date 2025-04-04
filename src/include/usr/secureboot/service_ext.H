/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/service_ext.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2025                        */
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
#ifndef __SERVICE_EXT_H
#define __SERVICE_EXT_H

#include <errl/errlentry.H>
#include <secureboot/service.H>

namespace SECUREBOOT
{


    // Minimum secure version for the measurement seeproms in the system
    constexpr uint32_t MINIMUM_SECURE_MEASUREMENT_VERSION = 0x00020013;
    // Measurement seeprom version resides from bytes 4-7 in register 0x10012.
    constexpr uint64_t VERSION_BYTES_MASK = 0x00000000FFFFFFFFull;

    /*
     * @brief Calls p10_update_security_ctrl HWP to lock down the secure
     *        mailboxes on all functional processors. All errors are committed
     *        internally.
     */
    void lockSecureMailboxes();

    /*
     * @brief Enforce synchronized processor security states
     */
    void validateSecuritySettings();

    /*
     * @brief Verifies that the measurement seeprom for the given target has the appropriate measurement code version
     *        and that the fuse for the measurement seeprom has been blown ensuring the code level is locked in and
     *        cannot be changed.
     *
     * @param[in]  i_proc     The processor which to verify the measurement seeprom security against.
     *
     * @return errlHndl_t   nullptr on success, otherwise an error log.
     */
    errlHndl_t verifyMeasurementSeepromSecurity(const TARGETING::TargetHandle_t& i_proc);

    /**
     *  @brief Adds the values of the Security Registers of the processors in
     *         the system to an existing error log
     *
     *  @param[in,out] io_err  Error Log that the values of the security
     *                         registers will be added to. Must not be nullptr.
     *                         NOTE:  The state of the system/processors
     *                         (ie, SCOM vs FSI) determines which registers can
     *                         be included.
     *  @param[in] i_calledByRP See the handleSecurebootFailure function's
     *                         "called by resource provider" option.
     *  @return N/A
     */
    void addSecurityRegistersToErrlog(errlHndl_t & io_err,
                                      bool i_calledByRP = false);

    /**
     * @brief Retrieve values of Security Registers of the processors in the
     *        system
     *
     * @param[out] o_regs       Vector of SecureRegisterValue structs that contain
     *                          processor security register values
     *                          NOTE:  The state of the system/processors (ie, SCOM vs
     *                          FSI) determines which registers can be included
     * @param[out] i_calledByRP See the handleSecurebootFailure function's
     *                          "called by resource provider" option.
     *
     * @return errlHndl_t  nullptr on success, else pointer to error log
     */
    errlHndl_t getAllSecurityRegisters(std::vector<SecureRegisterValues> & o_regs,
                                       const bool i_calledByRP = false);

} // namespace SECUREBOOT
#endif
