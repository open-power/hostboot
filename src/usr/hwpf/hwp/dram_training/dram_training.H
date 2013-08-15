/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/dram_training.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef  __DRAM_TRAINING_DRAM_TRAINING_H
#define  __DRAM_TRAINING_DRAM_TRAINING_H

/**
 *  @file dram_training.H
 *
 *  Step 13 DRAM Training
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-02-27:2142
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      dram_training
 *  @istepnum       13
 *  @istepdesc      Step 13 DRAM Training
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_disable_vddr
 *      @substepdesc    : Disable VDDR on CanContinue loops
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    mem_pll_initf
 *      @substepdesc    : PLL initfile for MBAs
 *      @target_sched   serial
 *  @}

 *  @{
 *      @substepnum     3
 *      @substepname    mem_pll_setup
 *      @substepdesc    : Setup PLL for MBAs
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    mem_startclocks
 *      @substepdesc    : Start clocks on MBAs
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    host_enable_vddr
 *      @substepdesc    : Enable the VDDR3 Voltage Rail
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     6
 *      @substepname    mss_scominit
 *      @substepdesc    : Perform scom inits to MC and PHY
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     7
 *      @substepname    mss_ddr_phy_reset
 *      @substepdesc    : Soft reset of DDR PHY macros
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     8
 *      @substepname    mss_draminit
 *      @substepdesc    : Dram initialize
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     9
 *      @substepname    mss_draminit_training
 *      @substepdesc    : Dram training
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     10
 *      @substepname     mss_draminit_trainadv
 *      @substepdesc     : Advanced dram training
 *      @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     11
 *      @substepname     mss_draminit_mc
 *      @substepdesc     : Hand off control to MC
 *      @target_sched   serial
 * @}
 */
/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   DRAM_TRAINING
{

/**
 *  @brief   host_disable_vddr
 *
 *           Disable VDDR on CanContinue loops
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return any errlogs to istep 
 *
 */
void*    call_host_disable_vddr( void * io_pArgs );

/**
 *  @brief   mem_pll_initf
 *
 *           PLL init file for MBAs
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mem_pll_initf( void * io_pArgs );

/**
 *  @brief   mem_pll_setup
 *
 *           Setup PLL for MBAs
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mem_pll_setup( void * io_pArgs );



/**
 *  @brief   mem_startclocks
 *
 *           Start clocks on MBAs
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mem_startclocks( void * io_pArgs );



/**
 *  @brief   host_enable_vddr
 *
 *           Enable the VDDR3 Voltage Rail
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 

 *
 */
void*    call_host_enable_vddr( void * io_pArgs );



/**
 *  @brief   mss_scominit
 *
 *           Perform scom inits to MC and PHY
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mss_scominit( void * io_pArgs );



/**
 *  @brief   mss_ddr_phy_reset
 *
 *           Soft reset of DDR PHY macros
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mss_ddr_phy_reset( void * io_pArgs );



/**
 *  @brief   mss_draminit
 *
 *           Dram initialize
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mss_draminit( void * io_pArgs );


/**
 *  @brief   mss_draminit_training
 *
 *           Dram training
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mss_draminit_training( void * io_pArgs );



/**
 *  @brief   mss_draminit_trainadv
 *
 *           Advanced dram training
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mss_draminit_trainadv( void * io_pArgs );



/**
 *  @brief   mss_draminit_mc
 *
 *           Hand off control to MC
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep 
 *
 */
void*    call_mss_draminit_mc( void * io_pArgs );
/**
 *  @brief   mss_dimm_power_test
 *
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any errlogs to istep
 *
 */
void*    call_mss_dimm_power_test( void * io_pArgs );


};   // end namespace

#endif

