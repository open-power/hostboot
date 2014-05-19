/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludcallout.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
     *  @param[in]  i_gardErrorType To indicate what type of failure occured
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
     *  @brief Construct a bus callout user detail
     *
     *  @param[in]  i_pTarget1Data   The hardware target1 data
     *  @param[in]  i_target1DataLength    length of i_pTarget1Data
     *  @param[in]  i_pTarget2Data   The hardware target2 data
     *  @param[in]  i_target2DataLength    length of i_pTarget2Data
     *  @param[in]  i_busType       bus type Enum
     *  @param[in]  i_priority      Priority of the callout
     *
     *  @return void
     */
    ErrlUserDetailsCallout(
                        const void *i_pTarget1Data,
                        uint32_t i_target1DataLength,
                        const void *i_pTarget2Data,
                        uint32_t i_target2DataLength,
                        const HWAS::busTypeEnum i_busType,
                        const HWAS::callOutPriority i_priority);

    /**
     *  @brief Construct a hardware callout user detail
     *
     *  @param[in]  i_pTargetData    The hardware target data
     *  @param[in]  i_targetDataLength    length of i_pTargetData
     *  @param[in]  i_priority      Priority of the callout
     *  @param [in] i_deconfigState Enum indicating whether the failing part
     *               should be deconfigured.
     *  @param [in] i_gardErrorType to indicate what type of failure occured
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


    // Disabled
    ErrlUserDetailsCallout(const ErrlUserDetailsCallout &);
    ErrlUserDetailsCallout & operator=(const ErrlUserDetailsCallout &);

};

}

#endif

