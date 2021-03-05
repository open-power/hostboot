/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nest/nestHwpHelperFuncs.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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

#ifndef _NEST_HWP_HELPER_FUNCS_H
#define _NEST_HWP_HELPER_FUNCS_H

/******************************************************************************/
// Includes
/******************************************************************************/
//  Integral and component ID support
#include <stdint.h>                // uint32_t
#include <hbotcompid.H>            // compId_t

//  Error handling support
#include <isteps/hwpisteperror.H>  // ISTEP_ERROR::IStepError

namespace ISTEP
{

/**
 *  @brief There seemed to be a lot of duplicated code (cut and paste) in
 *         different files.  I provide an interface to this duplicated code and
 *         consolidated it here, so if the protocol ever changes there is only
 *         one place to make changes.
 *
 *  @note  To take advantage of this consolidation, follow these guidelines
 *         1) Make sure that one of these methods will suffice for your needs
 *         2) Add an enum to HWP_CALL_TYPE that is specific to your needs (in
 *            this .H file).  This enum is the key to calling the correct HWP
 *            call you wish to perform (in this .H file).
 *         3) Add a string representation of the HWP call to
 *            hwpCallToStringMap (in .C file).
 *         4) Update method fapiHWPCallWrapper to accommodate and actually
 *            make the new HWP call (in .C file).
 *            NOTE: Don't forget to update include directives as well
 *         5) Finally call the method with the correct parameters in the file
 *            that you wish to make the HWP call
 */

/**
 *  @brief Enum specifying which HWP to call
 */
enum HWP_CALL_TYPE
{
    P10_CHIPLET_FABRIC_SCOMINIT, // Although it says chiplet, this uses proc chip
    P10_FBC_EFF_CONFIG_LINKS_ELECTRICAL, // process electrical
    P10_FBC_EFF_CONFIG_LINKS_OPTICAL, // process optical
    P10_IO_IOHS_FIRMASK_SAVE_RESTORE, // Save IOHS/PAUC FIR masks
};

/**
 *  @brief
 *      Handy utility to convert an enumeration to its equivalent string.
 *      This is a mapping of the HWP enumeration to its string representation
 *
 *  @param[in] i_hwpCall
 *      @see fapiHWPCallWrapper
 *
 *  @return
 *      Returned is the string equivalent of the enumeration supplied.  If the
 *      enumeration supplied is not valid, then an empty string is returned
 *
 *  @note
 *      Do not attempt to delete the returned string, it is immutable
 */
const char * hwpCallToString( HWP_CALL_TYPE i_hwpCall );

/**
 *  @brief
 *     This function is the function where the actual HWP calls are made.
 *     Currently this function iterates over chips and chiplets and calls
 *     the appropriate HWP call for that particular type.
 *
 *  @param[in] i_hwpCall
 *     An enumeration that specifies which HWP will be called
 *
 *  @param[out] o_stepError
 *  @param[in]  i_componentId
 *     @see hostboot/src/usr/isteps/istepHelperFuncs.H:captureError
 *
 *  @param[in]  i_targetType
 *     The targe type that determines to whether iterate over chips or chiplets
 *
 * @pre
 *     i_hwpCall is a valid HWP_CALL_TYPE. See enum HWP_CALL_TYPE above
 *     to determine which types are valid
 *
 * @post
 *     The HWP call, for the given i_hwpCall, is executed. If any error
 *     occurs, the details of the error will be contained in o_stepError.
 *
 *  @note
 *     If i_hwpCall is not a valid value the code will be halted via an assert.
 */
void fapiHWPCallWrapper(HWP_CALL_TYPE            i_hwpCall,
                        ISTEP_ERROR::IStepError &o_stepError,
                        compId_t                 i_componentId,
                        TARGETING::TYPE          i_targetType);

/**
 *  @brief
 *     This functions "handles" the call to fapiHWPCallWrapper.  If that call
 *     succeeds then true is returned else false is returned.  If
 *     fapiHWPCallWrapper fails this function will print an error message
 *     stating so.
 *
 *     This is mainly a pass-thru function call to method fapiHWPCallWrapper.
 *     It's main purpose is to return whether method fapiHWPCallWrapper
 *     succeded or failed and print an error message upon failure.
 *
 *  @param[in]  i_hwpCall
 *  @param[out] o_stepError
 *  @param[in]  i_componentId
 *  @param[in]  i_targetType
 *     @see fapiHWPCallWrapper
 *
 * @return true if call succeeds, false otherwise
 */
bool fapiHWPCallWrapperHandler(HWP_CALL_TYPE            i_hwpCall,
                               ISTEP_ERROR::IStepError &o_stepError,
                               compId_t                 i_componentId,
                               TARGETING::TYPE          i_targetType);

};  // end namespace ISTEP

#endif
