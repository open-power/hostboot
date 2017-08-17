/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/postopchecks.H $                                 */
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
#ifndef __SCOM_POST_OP_CHECKS_H
#define __SCOM_POST_OP_CHECKS_H

#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <targeting/common/target.H>

#include <initializer_list>
#include <memory>
#include <vector>

namespace SCOM
{
/**
 *  @brief Base class for post device operation.
 *
 *  This base class and derived classes are intended to facilitate
 *  refactoring of workarounds, temporary or otherwise from the
 *  main flow of a device operation. This permits workarounds to be
 *  easily added and removed without polluting the device operation
 *  code and facilitates unit testing.
 *
 *  To Add a workaround: Derive a class from PostOpRetryCheck and
 *  place it in separate source and header files. Then add a
 *  reference to a global instance of the class to the PostOpChecks
 *  global instance constructor. The requestRetry function should
 *  be fast and re-entrant.
 *
 *  To Remove a workaround: Delete the workaround source files and
 *  remove any references to the global instances from the PostOpChecks
 *  constructor.
 *
 */
class PostOpRetryCheck
{
public:
    //Only a single instance is allowed.
    PostOpRetryCheck(const PostOpRetryCheck&)=delete;
    PostOpRetryCheck(PostOpRetryCheck&&)=delete;
    PostOpRetryCheck& operator=(const PostOpRetryCheck&)=delete;
    PostOpRetryCheck& operator=(PostOpRetryCheck&&)=delete;

    /**
     *  @brief Determine if a retry is needed given a device
     *  operation and previous results.
     *
     *  @param[in] i_errl. The error associated with the previous
     *                    scom operation.
     *  @param[in] i_retryCount. How many retries were made prior
     *                           to this call.
     *  @param[in] i_opType. The scom operation being attempted.
     *  @param[in] i_target. The target of the scom operation.
     *  @param[in] i_buffer. The buffer for the scom operation.
     *  @param[in] i_buflen. The length of the buffer for the scom
     *                       operation.
     *
     *  @param[in] i_accessType. The access type for the scom operation.
     *  @param[in] i_addr. The address for the scom operation.
     *
     *  @return True if a retry should be attempted, False otherwise.
     */
    virtual bool requestRetry(errlHndl_t i_errl,
                              uint32_t i_retryCount,
                              DeviceFW::OperationType i_opType,
                              TARGETING::Target* i_target,
                              void* i_buffer,
                              size_t i_buflen,
                              int64_t i_accessType,
                              uint64_t i_addr
                             ) const = 0;

    virtual ~PostOpRetryCheck() = default;

    //Integration Testing Support

    /**
     *  @brief Accessor for the iv_retryCount member. The method is virtual
     *  to allow the PostOpChecks container class to implement this method
     *  by adding the count of it's contained objects.
     *
     *  @return The number of retries requested by this component.
     */
    virtual uint64_t getRetryCount() const
                               {return __sync_fetch_and_add(&iv_retryCount,0);}

    /**
     * @brief Reset the iv_retryCount member to zero.
     */
    virtual void resetRetryCount() const
                                      {__sync_fetch_and_and(&iv_retryCount,0);}

protected:
    PostOpRetryCheck()=default;

    /**
     * @brief Increment the retry count for this object.
     */
    void incRetryCount() const {__sync_fetch_and_add(&iv_retryCount, 1);}

private:
    mutable uint64_t iv_retryCount{0}; /**< The number of retries requested by
                                       this instance.*/
};


/**
 *  @brief composite pattern for invoking PostOpRetryCheck
 *  methods upon a group of contained objects.
 */
class PostOpChecks: public PostOpRetryCheck
{
public:
    //Only a single instance is allowed.
    PostOpChecks(const PostOpChecks&)=delete;
    PostOpChecks(PostOpChecks&&)=delete;
    PostOpChecks& operator=(const PostOpChecks&)=delete;
    PostOpChecks& operator=(PostOpChecks&&)=delete;

    virtual ~PostOpChecks() = default;

    /**
     *  @brief Determine if a retry is needed given a device
     *  operation and previous results. This class will implement
     *  the composite pattern and invoke the same virtual function
     *  on contained interfaces until a retry request is encountered
     *  or until all children have been queried.
     *
     *  @param[in] i_errl. The error associated with the previous
     *                    scom operation.
     *  @param[in] i_retryCount. How many retries were made prior
     *                           to this call.
     *  @param[in] i_opType. The scom operation being attempted.
     *  @param[in] i_target. The target of the scom operation.
     *  @param[in] i_buffer. The buffer for the scom operation.
     *  @param[in] i_buflen. The length of the buffer for the scom
     *                       operation.
     *
     *  @param[in] i_accessType. The access type for the scom operation.
     *  @param[in] i_addr. The address for the scom operation.
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

    //Integration Test support

    /**
     *  @brief Accessor for the iv_retryCount member.
     *
     *  @return The number of retries requested by all children of
     *          this component.
    */
    uint64_t getRetryCount() const override;

    /**
    * @brief Reset the retry count member of all children to zero.
    */
    void resetRetryCount() const override;

    /**
     * @brief Access the single instance of this class.
     */
    static const PostOpChecks* theInstance();

protected:

    /**
     *  @brief CTOR.
     *
     *  @param[in] i_retrychecks. A list of PostOpRetryCheck interfaces that
     *                            will be queried for retries.
     *
     */
    PostOpChecks(
       std::initializer_list<std::shared_ptr<const PostOpRetryCheck>> i_retry);

private:
    const std::vector<std::shared_ptr<const PostOpRetryCheck>> iv_retryChecks;
};

}

#endif
