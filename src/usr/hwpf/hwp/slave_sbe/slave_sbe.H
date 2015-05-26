/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/slave_sbe.H $                      */
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

#ifndef  __SLAVE_SBE_SLAVE_SBE_H
#define  __SLAVE_SBE_SLAVE_SBE_H

/**
 *  @file slave_sbe.H
 *
 *  Slave SBE Isteps that invoke HWPs.
 *
 *  Note that a number of IStep 6 substeps are done by Hostboot specific
 *  functions, this file is for the substeps that invoke HWPs
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      slave_sbe
 *  @istepnum       6
 *  @istepdesc      Slave SBE
 *
 *  @{
 *      @substepnum     9
 *      @substepname    host_slave_sbe_config
 *      @substepdesc    : 
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     10
 *      @substepname    host_sbe_start
 *      @substepdesc    : execute proc_start_sbe.C procedure
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     11
 *      @substepname    proc_check_slave_slave_sbe_seeprom_complete
 *      @substepdesc    : Check slave SBE complete
 *          @target_sched   serial

 *
 */

namespace SLAVE_SBE
{

/**
 *  @brief host_slave_sbe_config
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_host_slave_sbe_config(void *io_pArgs);

/**
 *  @brief call_host_setup_sbe
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_host_setup_sbe(void *io_pArgs);

/**
 *  @brief call_host_cbs_start
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_host_cbs_start(void *io_pArgs);


/**
 *  @brief set_proc_voltage_vid - sets ATTR_PROC_BOOT_VOLTAGE_VID
 *
 *  return error logs
 */
errlHndl_t set_proc_boot_voltage_vid();


/**
 *  @brief host_sbe_start
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep 
 */
void* call_host_sbe_start(void *io_pArgs);

/**
 *  @brief proc_check_slave_sbe_seeprom_complete
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep 
 */
void* call_proc_check_slave_sbe_seeprom_complete(void *io_pArgs);

/**
 *  @brief proc_xmit_sbe
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep 
 */
void* call_proc_xmit_sbe(void *io_pArgs);
/**
 *  @brief  proc_cen_ref_clk_enable
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep 
 */
void* call_proc_cen_ref_clk_enable(void *io_pArgs);


};   // end namespace

#endif
