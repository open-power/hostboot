/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/edi_ei_initialization/edi_ei_initialization.H $
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
#ifndef  __EDI_EI_INITIALIZATION_EDI_EI_INITIALIZATION_H
#define  __EDI_EI_INITIALIZATION_EDI_EI_INITIALIZATION_H

/**
 *  @file edi_ei_initialization.H
 *
 *  EDI, EI Initialization
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1606
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      edi_ei_initialization
 *  @istepnum       08
 *  @istepdesc      EDI, EI Initialization
 *
 *  @{
 *      @substepnum     1
 *      @substepname    fabric_erepair
 *      @substepdesc    : Restore Fabric/EDI Bus eRepair data
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    fabric_io_dccal
 *      @substepdesc    : Calibrate Fabric/EDI interfaces
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    fabric_pre_trainadv
 *      @substepdesc    : Advanced pre EI/EDI training
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    fabric_io_run_training
 *      @substepdesc    : Run training on internal buses
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    fabric_post_trainadv
 *      @substepdesc    : Advanced post EI/EDI training
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     6
 *      @substepname    host_startprd_pbus
 *      @substepdesc    : Load PRD for powerbus domain
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     7
 *      @substepname    host_attnlisten_proc
 *      @substepdesc    : Start listening for attentions
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     8
 *      @substepname    proc_fab_iovalid
 *      @substepdesc    : Lower functional fences on local SMP
 *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   EDI_EI_INITIALIZATION
{



/**
 *  @brief   fabric_erepair
 *
 *           Restore Fabric/EDI Bus eRepair data
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any errlogs to istep 
 *
 */
void*    call_fabric_erepair( void    *io_pArgs );



/**
 *  @brief   fabric_io_dccal
 *
 *           Calibrate Fabric/EDI interfaces
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_fabric_io_dccal( void    *io_pArgs );



/**
 *  @brief   fabric_pre_trainadv
 *
 *  08.3 : : Advanced pre EI/EDI training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_fabric_pre_trainadv( void    *io_pArgs );



/**
 *  @brief   fabric_io_run_training
 *
 *           Run training on internal buses
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_fabric_io_run_training( void    *io_pArgs );



/**
 *  @brief   fabric_post_trainadv
 *
 *           Advanced post EI/EDI training
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_fabric_post_trainadv( void    *io_pArgs );



/**
 *  @brief   host_startprd_pbus
 *
 *           Load PRD for powerbus domain
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_host_startprd_pbus( void    *io_pArgs );



/**
 *  @brief   host_attnlisten_proc
 *
 *           Start listening for attentions
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_host_attnlisten_proc( void    *io_pArgs );



/**
 *  @brief   proc_fab_iovalid
 *
 *           Lower functional fences on local SMP
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any errlogs to istep 
 *
 */
void*    call_proc_fab_iovalid( void    *io_pArgs );


};   // end namespace

#endif

