/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludcallout.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#ifndef ERRL_UDCALLOU_H
#define ERRL_UDCALLOU_H

/**
 *  @file errludcallout.H
 *
 *  Defines the ErrlUserDetailsCallout class that adds a hardware callout to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>
#include <hwas/common/hwasCallout.H>

// Forward reference
namespace TARGETING
{
    class Target;
}

namespace ERRORLOG
{

// Forward class declaration
class ErrlEntry;

/**
 * @class ErrlUserDetailsCallout
 *
 * Adds Callout FFDC to an error log as user detail data
 */
class ErrlUserDetailsCallout : public ErrlUserDetails
{

    friend class ErrlEntry;

private:

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsCallout() { };

    /**
     *  @brief Construct a clock callout user detail
     *
     *  @param[in]  i_pTargetData   The hardware target data
     *  @param[in]  i_targetDataLength    length of i_pTargetData
     *  @param[in]  i_clockType     clock type Enum
     *  @param[in]  i_priority      Priority of the callout
     *  @param[in]  i_deconfigState Enum indicating whether the failing part
     *                              should be deconfigured.
     *  @param[in]  i_gardErrorType To indicate what type of failure occurred
     *
     *  @return void
     */
    ErrlUserDetailsCallout(
                       const void *i_pTargetData,
                       uint32_t i_targetDataLength,
                       const HWAS::clockTypeEnum i_clockType,
                       const HWAS::callOutPriority i_priority,
                       const HWAS::DeconfigEnum i_deconfigState,
                       const HWAS::GARD_ErrorType i_gardErrorType);
    /**
     *  @brief Construct a part callout user detail
     *
     *  @param[in]  i_pTargetData   The hardware target data
     *  @param[in]  i_targetDataLength    length of i_pTargetData
     *  @param[in]  i_partType     part type Enum
     *  @param[in]  i_priority      Priority of the callout
     *  @param[in]  i_deconfigState Enum indicating whether the failing part
     *                              should be deconfigured.
     *  @param[in]  i_gardErrorType To indicate what type of failure occurred
     *
     *  @return void
     */
    ErrlUserDetailsCallout(
                       const void *i_pTargetData,
                       uint32_t i_targetDataLength,
                       const HWAS::partTypeEnum i_partType,
                       const HWAS::callOutPriority i_priority,
                       const HWAS::DeconfigEnum i_deconfigState,
                       const HWAS::GARD_ErrorType i_gardErrorType);

    /**
     * @brief Construct a vrm callout user details section
     *
     * @param[in]   i_pTargetData       The processor that failed to communicate with the VRM
     * @param[in]   i_targetDataLength  Length, in bytes, of i_pTargetData
     * @param[in]   i_vrmType           Voltage type enum
     * @param[in]   i_priority          Priority of the callout
     *
     * @return void
     */
    ErrlUserDetailsCallout(
                        const void *i_pTargetData,
                        uint32_t i_targetDataLength,
                        const HWAS::voltageTypeEnum i_vrmType,
                        const HWAS::callOutPriority i_priority);

    /**
     *  @brief Construct a bus callout user detail
     *
     *  @param[in]  i_pTarget1Data   The hardware target1 data
     *  @param[in]  i_target1DataLength    length of i_pTarget1Data
     *  @param[in]  i_pTarget2Data   The hardware target2 data
     *  @param[in]  i_target2DataLength    length of i_pTarget2Data
     *  @param[in]  i_busType       bus type Enum
     *  @param[in]  i_priority      Priority of the callout
     *  @param[in]  i_flag          Extra flag for callout structure
     *
     *  @return void
     */
    ErrlUserDetailsCallout(
                        const void *i_pTarget1Data,
                        uint32_t i_target1DataLength,
                        const void *i_pTarget2Data,
                        uint32_t i_target2DataLength,
                        const HWAS::busTypeEnum i_busType,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::CalloutFlag_t i_flag );

    /**
     *  @brief Construct a hardware callout user detail
     *
     *  @param[in]  i_pTargetData    The hardware target data
     *  @param[in]  i_targetDataLength    length of i_pTargetData
     *  @param[in]  i_priority      Priority of the callout
     *  @param [in] i_deconfigState Enum indicating whether the failing part
     *               should be deconfigured.
     *  @param [in] i_gardErrorType to indicate what type of failure occurred
     *
     *  @return void
     */
    ErrlUserDetailsCallout(
                        const void *i_pTargetData,
                        uint32_t i_targetDataLength,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::DeconfigEnum i_deconfigState,
                        const HWAS::GARD_ErrorType i_gardErrorType);

    /**
     *  @brief Add a procedure ( software ) callout
     *  Adds the given service procedure to the list
     *  of callouts for the log
     *
     *  @param[in]  i_procedure     Procedure identifier.
     *  @param[in]  i_priority      Priority of the callout
     *
     *  @return void
     */
    ErrlUserDetailsCallout(const HWAS::epubProcedureID i_procedure,
                        const HWAS::callOutPriority i_priority);


    /**
     *  @brief Add a sensor callout
     *  Adds the given sensor to the list of callouts for the log
     *
     *  @param[in]  i_sensorID      Sensor ID
     *  @param[in]  i_sensorType    Type of sensor being added
     *  @param[in]  i_priority      Priority of the callout
     *
     *  @return void
     */
    ErrlUserDetailsCallout(const uint32_t i_sensorID,
                        const HWAS::sensorTypeEnum i_sensorType,
                        const HWAS::callOutPriority i_priority );


    /**
     *  @brief Construct an i2c device callout user detail
     *
     *  @param[in]  i_pTargData     The hardware target data or in other words
     *                              the bytes in memory that comprise the
     *                              entity path of the target
     *  @param[in]  i_targDataLen   length of i_pTargData in bytes
     *  @param[in]  i_engine        The i2c device engine
     *  @param[in]  i_port          The i2c device port
     *  @param[in]  i_address       The i2c device address
     *  @param[in]  i_priority      Priority of the callout
     *
     *  @return void
     */
    ErrlUserDetailsCallout(
                        const void *i_pTargData,
                        const uint32_t i_targDataLen,
                        const uint8_t i_engine,
                        const uint8_t i_port,
                        const uint8_t i_address,
                        const HWAS::callOutPriority i_priority);


    // Disabled
    ErrlUserDetailsCallout(const ErrlUserDetailsCallout &);
    ErrlUserDetailsCallout & operator=(const ErrlUserDetailsCallout &);

    // The hash of the binary User Detail section (used to find duplicates)
    uint32_t iv_UDCalloutHash;

    /**
     * @brief Returns the computed hash of the User Data Callout section
     *
     * @return The hash of the User Data Callout section
     */
    uint32_t getUDCalloutHash() const;
};

}

#endif

