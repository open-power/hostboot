/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/DmiScomWorkaround.H $                            */
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
#ifndef __SCOM_DMI_SCOM_WORKAROUND_H
#define __SCOM_DMI_SCOM_WORKAROUND_H

#include "postopchecks.H"
#include <targeting/common/target.H>

#include <memory>

namespace SCOM
{

/**
 * @brief Workaround for SCOM Bug. The workaround
 *        requires a retry of read operations for certain sets
 *        of DMI SCOM registers.
 */
class DmiScomWorkaround: public PostOpRetryCheck
{

public:
    //only one instance is allowed.
    DmiScomWorkaround(const DmiScomWorkaround&)=delete;
    DmiScomWorkaround(DmiScomWorkaround&&)=delete;
    DmiScomWorkaround& operator=(const DmiScomWorkaround&)=delete;
    DmiScomWorkaround& operator=(DmiScomWorkaround&&)=delete;

    virtual ~DmiScomWorkaround() = default;

    /**
     *  @brief Determine if a retry is needed given a device
     *  operation and previous results.
     *
     *  @param[in] i_errl. The error associated with the previous
     *                     scom operation. Not Used for this workaround.
     *  @param[in] i_retryCount. How many retries were made prior
     *                           to this call. This workaround will only
     *                           support 1 retry.
     *  @param[in] i_opType. The scom operation being attempted.
     *                       This workaround is only applicable
     *                       for read operations.
     *  @param[in] i_target. The target of the scom operation.
     *                       The workaround is valid only for
     *                       PROC and DMI targets.
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
   DmiScomWorkaround()=default;

   //Unit Test Method Injection Seams.

   /**
    *   @brief Obtain the type of the passed in target.
    *
    *   @param[in] i_target. The target whose type we are trying to determine.
    *   @param[out] o_type.  The type of i_target.
    *
    *   @return True if successful, False otherwise.
    */
   virtual bool getTargetType(TARGETING::Target* i_target,
                              TARGETING::TYPE& o_type) const;

   /**
    *   @brief Obtain the processor model if the passed in target is a
    *   PROC target.
    *
    *   @param[in] i_target. The target from which we would like to determine
    *                        the processor model.
    *   @param[out] o_model. The processor model if successful.
    *
    *   @return True if successful, False otherwise.
    */
   virtual bool getTargetModel(TARGETING::Target* i_target,
                               TARGETING::MODEL& o_model) const;

   /**
    *   @brief Obtain the processor EC Level if the passed in target is a
    *   PROC target.
    *
    *   @param[in] i_target. The target from which we would like to determine
    *                        the processor model.
    *   @param[out] o_ecLevel. The processor model if successful.
    *
    *   @return True if successful, False otherwise.
    */
   virtual bool getTargetECLevel(TARGETING::Target* i_target,
                                 uint8_t& o_ecLevel) const;

   /**
    * @brief - Allows us to create tests where the model is obtained
    *          for every call. The proc model should not be cached for
    *          unit tests in order to allow mocked targets of various
    *          models. In non-test code this method always returns true.
    */
   virtual bool useCachedProcModel() const {return true;}

private:

   static uint64_t cv_model_cumulus;
};

}

#endif
