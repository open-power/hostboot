/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/istep09HelperFuncs.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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

#ifndef _ISTEP09_HELPER_FUNCS_H
#define _ISTEP09_HELPER_FUNCS_H

/******************************************************************************/
// Includes
/******************************************************************************/
//  Integral and component ID support
#include <stdint.h>                // uint32_t
#include <hbotcompid.H>            // HWPF_COMP_ID

//  Error handling support
#include <isteps/hwpisteperror.H>  // ISTEP_ERROR::IStepError

//  TARGETING support
#include <attributeenums.H>        // TARGETING::TYPE

//  Pbus link service support
#include <pbusLinkSvc.H>           // TargetPairs_t

// forward declare TARGETING::Target
namespace TARGETING
{
    class Target;
}

namespace ISTEP_09
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
 *            call you wish to perform.
 *            NOTE: Please update the LAST_VALUE with the newly added enum
 *         3) Add a string representation of the HWP call to
 *            hwpCallToStringMap (in .C file).
 *         4) Update one of the methods below to accommodate the new HWP call
 *            (in .C file).
 *            NOTE: Don't forget to update include directives as well
 *         5) Finally call the method with the correct parameters in the file
 *            that wishes to make the HWP call
 */

/**
 *  @brief Enum specifying which HWP to call
 */
enum HWP_CALL_TYPE
{
    // These enums pertain to the trainbus call
    P9_IO_XBUS_PRE_TRAINADV,       // XBUS pre training
    P9_IO_XBUS_POST_TRAINADV,      // XBUS post training
    P9_IO_OBUS_DCCAL,              // OBUS dccal
    P9_IO_OBUS_PRE_TRAINADV,       // OBUS pre training
    P9_IO_OBUS_LINKTRAIN,          // OBUS link training
    P9_IO_OBUS_POST_TRAINADV,      // OBUS post training
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
 *     These two functions train the appropriate XBUS/OBUS based on the
 *     enumeration passed in.
 *
 *  @param[in] i_hwpCall
 *     An enumeration that specifies which HWP will be called
 *
 *  @param[out] o_stepError
 *  @param[in] i_componentId
 *     @see hostboot/src/usr/isteps/istepHelperFuncs.H:captureError
 *
 *  @param[in] i_firstTarget
 *  @param[in] i_secondTarget
 *     TAREGTING::Target(s) that are converted to fapi2:Target(s) which are
 *     passed to HWP call that is specified by the i_hwpCall
 *
 *  @return
 *     The number of errors encountered while executing the HWP call
 *
 * @pre
 *     i_hwpCall is a valid HWP_CALL_TYPE enum for an XBUS call.
 *     i_firstTarget and i_secondTarget are valid targets (not NULL).
 *
 * @post
 *     The HWP call, for the given i_hwpCall, is executed for the given
 *     targets (i_firstTarget and i_secondTarget).  If any error occurs,
 *     the details of the error will be contained in o_stepError.
 *
 *  @note
 *     If i_hwpCall is not a valid value and/or i_firstTarget/i_secondTarget
 *     are NULL then the code will be halted via an assert.
 *
 */

// Use this call if the fapi2 target type is TARGET_TYPE_XBUS
uint32_t trainXbus(HWP_CALL_TYPE            i_hwpCall,
                   ISTEP_ERROR::IStepError &o_stepError,
                   compId_t                 i_componentId,
                   const TARGETING::Target* i_firstTarget,
                   const TARGETING::Target* i_secondTarget);

// Use this call if the fapi2 target type is TARGET_TYPE_OBUS
uint32_t trainObus(HWP_CALL_TYPE            i_hwpCall,
                   ISTEP_ERROR::IStepError &o_stepError,
                   compId_t                 i_componentId,
                   const TARGETING::Target* i_firstTarget,
                   const TARGETING::Target* i_secondTarget);

/**
 *  @brief
 *     This functions "handles" the call to trainXbus/trainObus.  If the call
 *     succeeds then true is returned else false is returned.  If
 *     the call fails this function will print an error message
 *     stating so.
 *
 *     This is mainly a pass-thru function call to method fapiHWPCallWrapper.
 *     It's main purpose is to return whether method fapiHWPCallWrapper
 *     succeded or failed and print an error message upon failure.
 *
 *  @param[in] i_busType      Type of the bus to process, currently XBUS or OBUS
 *  @param[in] i_hwpCall      @see trainXbus/trainObus
 *  @param[out] o_stepError   @see trainXbus/trainObus
 *  @param[in] i_componentId  @see trainXbus/trainObus
 *  @param[in] i_targetPairs  bus pair connections (XBUS or OBUS)
 *
 *  @return true if call succeeds, false otherwise
 *
 */
bool trainBusHandler(TARGETING::TYPE          i_busType,
                     HWP_CALL_TYPE            i_hwpCall,
                     ISTEP_ERROR::IStepError &o_stepError,
                     compId_t                 i_componentId,
                     const EDI_EI_INITIALIZATION::TargetPairs_t &i_targetPairs);

};  // end namespace ISTEP_09

#endif
