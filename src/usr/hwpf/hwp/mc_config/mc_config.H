/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/mc_config/mc_config.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
 *  @docversion     v1.08 (08/13/12)
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
 *  12.1 : : Collect Master dimm SPD
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_host_collect_dimm_spd( void * io_pArgs );



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
errlHndl_t call_mss_volt( void * io_pArgs );



/**
 *  @brief   mss_freq
 *
 *  12.2 : : Calc dimm frequency
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
 *  12.3 : : Determine effective config
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 *
 */
void*    call_mss_eff_config( void * io_pArgs );


};   // end namespace

#endif

