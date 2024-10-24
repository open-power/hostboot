/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/ScomParityErrorWorkaround.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
#ifndef __SCOM_PRTY_SCOM_WORKAROUND_H
#define __SCOM_PRTY_SCOM_WORKAROUND_H

#include "postopchecks.H"

namespace SCOM
{

/**
 * @brief Workaround for SCOM Bug. The workaround
 *        requires a retry of scom operations
 *        on proc targets after PIB_PARITY_ERROR
 */
class ScomParityErrorWorkaround: public PostOpRetryCheck
{
public:
    //only one instance is allowed.
    ScomParityErrorWorkaround(const ScomParityErrorWorkaround&)=delete;
    ScomParityErrorWorkaround(ScomParityErrorWorkaround&&)=delete;
    ScomParityErrorWorkaround& operator=(const ScomParityErrorWorkaround&)=delete;
    ScomParityErrorWorkaround& operator=(ScomParityErrorWorkaround&&)=delete;

    virtual ~ScomParityErrorWorkaround() = default;

    /**
     *  @brief Determine if a retry is needed given a device
     *  operation and previous results.
     *
     *  @param[in] i_errl. The error associated with the previous
     *                     scom operation.
     *  @param[in] i_retryCount. How many retries were made prior
     *                           to this call. This workaround will only
     *                           support 1 retry.
     *  @param[in] i_opType. The scom operation being attempted.
     *  @param[in] i_target. The target of the scom operation.
     *                       The workaround is valid only for
     *                       PROC targets.
     *  @param[in] i_buffer. The buffer for the scom operation.
     *                       Not used for this workaround.
     *  @param[in] i_buflen. The length of the buffer for the scom
     *                       operation. Not used for this workaround.
     *  @param[in] i_accessType. The access type for the scom operation.
     *                           Not used for this workaround.
     *  @param[in] i_addr. The address for the scom operation. The address
     *                     is used to determine if we need to retry a SCOM
     *                     read.
     *
     *  @return True if a retry should be attempted, False otherwise.
     */
    bool requestRetry(errlHndl_t i_errl,
                      uint32_t i_retryCount,
                      DeviceFW::OperationType i_opType,
                      TARGETING::Target* i_target,
                      void* i_buffer,
                      size_t i_buflen,
                      int64_t i_accessType,
                      uint64_t i_addr
                     ) const override;

    /**
        * @brief Access the single instance of this class.
        */
    static std::shared_ptr<const PostOpRetryCheck> theInstance();

protected:
    ScomParityErrorWorkaround()=default;

};

} //End Namespace

#endif
