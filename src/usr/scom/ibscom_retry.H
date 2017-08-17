/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/ibscom_retry.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __SCOM_IBSCOM_RETRY_H
#define __SCOM_IBSCOM_RETRY_H

#include "postopchecks.H"
#include <memory>

namespace SCOM
{

/**
 * @brief Class to enable checking if a retry is required
 *        based upon the error reason code. If a scom
 *        operation returns an errlHndl_t with reason
 *        code set to IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR, then
 *        one retry will be requested.
 */
class IbscomRetry: public PostOpRetryCheck
{
public:
     IbscomRetry(const IbscomRetry&)=delete;
     IbscomRetry(IbscomRetry&&)=delete;
     IbscomRetry& operator=(const IbscomRetry&)=delete;
     IbscomRetry& operator=(IbscomRetry&&)=delete;

     virtual ~IbscomRetry()=default;

    /**
     *  @brief Determine if a retry is needed given a device
     *  operation and previous results.
     *
     *  @param[in] i_errl. The error associated with the previous
     *                     scom operation. A workaround will be requested
     *                     if the error code is
     *                     IBSCOM::IBSCOM_RETRY_DUE_TO_ERROR.
     *  @param[in] i_retryCount. How many retries were made prior
     *                           to this call. This workaround will only
     *                           support 1 retry.
     *  @param[in] i_opType. The scom operation being attempted.
     *                       This workaround does not use this value.
     *  @param[in] i_target. The target of the scom operation.
     *                       This workaround does not use this value.
     *  @param[in] i_buffer. The buffer for the scom operation.
     *                       This workaround does not use this value.
     *  @param[in] i_buflen. The length of the buffer for the scom
     *                       operation. This workaround does not use
     *                       this value.
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
    IbscomRetry()=default;
};

} //End Namespace

#endif
