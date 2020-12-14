/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istepHelperFuncs.H $                           */
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

#ifndef _ISTEP_HELPER_FUNCS_H
#define _ISTEP_HELPER_FUNCS_H

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <attributetraits.H>
#include    <attributeenums.H>
#include    <initservice/isteps_trace.H>

// IStep Error support
#include  <isteps/hwpisteperror.H>

/**
 *  @brief Enum specifying what attributes should be used to set the
 *         memory _EFF_CONFIG attributes
 *
 */
enum EFF_CONFIG_ATTRIBUTES_BASE
{
    DEFAULT         = 0x00, ///< Use System Defaults
    POST_DRAM_INIT  = 0x01, ///< Use POST_DRAM_INIT attributes if non-zero
};

/**
 *  @brief Enum for per-domain control of different voltages
 */
enum MSS_PROGRAM_TYPE
{
    // domain is programmed as part of regular power on sequence
    POWERON_TYPE = 0,

    // domain needs to be programmed, no special computation needed
    STATIC_TYPE  = 1,

    // domain needs to be programmed, uses dynamic vid logic
    DYNAMIC_TYPE = 2,

    // domain needs to be programmed,
    // POWR responsible for vid values attained via sys vrm xml
    DEFAULT_TYPE = 3,
};

//
//  Helper function to set _EFF_CONFIG attributes for HWPs
//
void set_eff_config_attrs_helper( const EFF_CONFIG_ATTRIBUTES_BASE i_base,
                                  bool & o_post_dram_inits_found);


/**
 *  @brief Load HCODE image and return a pointer to it, or nullptr
 *  Note that on failure (error log returned), o_loadSuccess is accurate
 *  and o_rHcodeAddr should be ignored
 *
 *  @param[out] o_rHcodeAddr  -   address of the HCODE image
 *  @param[out] o_loadSuccess -   load image successful
 *
 *  @return      nullptr if success, errorlog if failure
 *
 */
errlHndl_t loadHcodeImage(char *& o_rHcodeAddr, bool &o_loadSuccess);




/**
 *  @brief
 *      This functions captures the user details of the given targets,
 *      if given any, and is added to the error log handle. Once the error
 *      log has the user data, for the given targets, the details of error
 *      log or added to the io_stepError.  The error log is then committed
 *      with the given component ID, leaving the error log handle NULL.
 *
 *      If no valid targets are given, everything is the same as above -
 *      io_stepError will contain the io_err info and the io_err will be
 *      committed - except the io_stepError will not contain any info
 *      collected from targets.
 *
 *  @param[in/out] io_err
 *      An error log handle, that contains the error log info. Can be NULL.  If
 *      NULL then this function becomes a no-op.  BEWARE: Upon exit of
 *      this function, the handle will be NULL.
 *
 *  @param[out] io_stepError
 *      The details from the error handle, io_err, which will be added to this.
 *
 *  @param[in] i_componentId
 *      The component ID that will be associated with the error handler, io_err,
 *      when the error is committed.
 *
 *  @param[in] i_target, i_targetList
 *      The list of target(s) that will be assimilated and have their knowledge
 *      added to the collective and when I say collective, I mean the error log
 *      handle, io_err ... resistance is futile. If not target is given, then
 *      target data will not be collected.
 */
void captureError(errlHndl_t               &io_err,
                  ISTEP_ERROR::IStepError  &io_stepError,
                  compId_t                  i_componentId,
                  const TARGETING::Target*  i_target = nullptr);

void captureError(errlHndl_t                        &io_err,
                  ISTEP_ERROR::IStepError           &io_stepError,
                  compId_t                           i_componentId,
                  const TARGETING::TargetHandleList &i_targetList);


/**
 *  @brief  Determines if the error is recoverable by I2C Explorer OCMB update
 *          If recoverable, commits error as recovered and triggers reconfig loop
 *          If not-recoverable, will act as normal captureError() call
 *
 *  @param[in/out] io_err
 *      An error log handle, that contains the error log info. Can be NULL.  If
 *      NULL then this function becomes a no-op.  BEWARE: Upon exit of
 *      this function, the handle will be NULL.
 *
 *  @param[out] io_stepError
 *      The details from the error handle, io_err, which will be added to this.
 *
 *  @param[in] i_componentId
 *      The component ID that will be associated with the error handler, io_err,
 *      when the error is committed.
 *
 *  @param[in] i_target
 *      The target that will be assimilated and have its knowledge
 *      added to the collective and when I say collective, I mean the error log
 *      handle, io_err ... resistance is futile. If not target is given, then
 *      target data will not be collected.
 */
void captureErrorOcmbUpdateCheck(errlHndl_t               &io_err,
                                 ISTEP_ERROR::IStepError  &io_stepError,
                                 compId_t                  i_componentId,
                                 const TARGETING::Target*  i_target = nullptr);

#endif
