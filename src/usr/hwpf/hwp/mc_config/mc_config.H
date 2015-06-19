/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mc_config.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#ifndef  __MC_CONFIG_MC_CONFIG_H
#define  __MC_CONFIG_MC_CONFIG_H

/**
 *  @file mc_config.H
 *
 *  Step 12 MC Config
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-03-01:1032
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      mc_config
 *  @istepnum       12
 *  @istepdesc      Step 12 MC Config
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_collect_dimm_spd
 *      @substepdesc    : Collect Master dimm SPD
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    mss_volt
 *      @substepdesc    : Calc dimm voltage
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    mss_freq
 *      @substepdesc    : Calc dimm frequency
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    mss_eff_config
 *      @substepdesc    : Determine effective config
 *      @target_sched   serial
 *  @}
 */
/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <errl/errlentry.H>
namespace   MC_CONFIG
{



/**
 *  @brief   host_collect_dimm_spd
 *
 *           Collect Master dimm SPD
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_host_collect_dimm_spd( void * io_pArgs );

/**
 *  @brief For a given memory voltage domain, program the domain's offset
 *      voltage if this behavior is enabled, otherwise program 0
 *
 *  @tparam OFFSET_DISABLEMENT_ATTR
 *      ID of the attribute to read to determine if a given memory voltage
 *      domain offset voltage should be applied or not.  Should be one of
 *      the TARGETING::ATTR_*_ID attribute IDs, where * = VMEM, VPP, VCS,
 *      VDD, or AVDD.
 *
 *  @tparam OFFSET_VOLTAGE_ATTR
 *      ID of the attribute to receive the given voltage domain's offset voltage
 *      value.  Should be one of the TARGETING::ATTR_MEM_*_OFFSET_MILLIVOLTS
 *      attribute IDs, where * = VMEM, VPP, VCS, VDD, or AVDD.  Only set to
 *      non-zero when memory voltage domain's offset voltage is enabled.
 *
 *  @tparam VOLTAGE_DOMAIN_ID_ATTR
 *      ID of the attribute which should be read to obtain the given memory
 *      voltage domain's ID.  IDs are only unique within the same memory voltage
 *      domain type. Must be one of the ATTR_*_ID attributes, where * = VPP,
 *      AVDD, VMEM, VDD, VCS.
 *
 *  @note: This function does not ensure that all permutations of the above
 *    template parameters are valid.
 *
 *  @return Error log handle indicating the status of the request.
 *
 *  @retval NULL Offset voltage successfully programmed or set to 0
 *  @retval Failed setting correct offset voltage
 */
template< const TARGETING::ATTRIBUTE_ID OFFSET_DISABLEMENT_ATTR,
          const TARGETING::ATTRIBUTE_ID OFFSET_VOLTAGE_ATTR,
          const TARGETING::ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR >
errlHndl_t setMemoryVoltageDomainOffsetVoltage();

/**
 *  @brief   mss_volt
 *
 *            Calc dimm voltage
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*   call_mss_volt( void * io_pArgs );



/**
 *  @brief   mss_freq
 *
 *           Calc dimm frequency
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_freq( void * io_pArgs );



/**
 *  @brief   mss_eff_config
 *
 *           Determine effective config
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_eff_config( void * io_pArgs );

/**
 *  @brief   mss_attr_update
 *
 *  Stub HWP to allow FW to override attributes programmatically
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_attr_update( void *io_pArgs );


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
 * @brief  Helper function to set memory _EFF_CONFIG attributes for HWPs
 *
 *  param[in]  i_base - Determines base of EFF_CONFIG attributes values
 *
 *  param[out] o_post_dram_inits_found - if i_base==POST_DRAM_INIT and
 *                                          POST_DRAM_INIT attributes were
 *                                          found return TRUE;
 *                                       else, return FALSE
 */
void set_eff_config_attrs_helper( const EFF_CONFIG_ATTRIBUTES_BASE i_base,
                                  bool & o_post_dram_inits_found);


};   // end namespace

#endif

