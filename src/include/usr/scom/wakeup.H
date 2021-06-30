/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scom/wakeup.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
 * Contains functions and constants related to handling special wakeup.
 */

namespace WAKEUP
{

/**
 * Parameters for wakeup assert/release
 */
enum HandleOptions_t
{
    ENABLE,
    DISABLE,
    FORCE_DISABLE
};

/**
 * @brief This function handles the enable and disable of the special
 *        wakeup that allows scom operations on idle cores.
 *
 * @param[in] i_target   - EQ/EX/Core target
 * @param[in] i_enable   - set or clear or clear all of the wakeups
 *
 * @return errlHndl_t    - error handle
 */
errlHndl_t handleSpecialWakeup(TARGETING::Target* i_target,
                               HandleOptions_t i_enable);


/**
 * Parameters for wakeup logic control
 */
enum WakeupControl_t
{
    DISABLE_SPECIAL_WAKEUP, //skip calls to wakeup HWP
    ENABLE_SPECIAL_WAKEUP,  //enable calls to wakeup HWP, clear counters
};

/**
 * @brief Disable special wakeup logic
 * @param[in] i_op  - Specify enable/disable option
 */
void controlWakeupLogic( WakeupControl_t i_op );

}
