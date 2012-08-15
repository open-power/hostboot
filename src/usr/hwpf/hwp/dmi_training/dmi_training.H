/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dmi_training/dmi_training.H $
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
#ifndef  __DMI_TRAINING_DMI_TRAINING_H
#define __DMI_TRAINING_DMI_TRAINING_H
/**
 *  @file dmi_training.H
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 */

/*  @tag isteplist
 *  @docversion     v1.08 (08/13/12)
 *  @istepname      dmi_training
 *  @istepnum       11
 *  @istepdesc      DMI Training
 *
 *
 *  @{
 *      @substepnum     1
 *      @substepname    dmi_scominit
 *      @substepdesc    : Scom setup on centaur
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    dmi_erepair
 *      @substepdesc    : Restore EDI Bus eRepair data
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    dmi_io_dccal
 *      @substepdesc    : Calibrate DMI interfaces
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    dmi_pre_trainadv
 *      @substepdesc    : Advanced pre DMI training
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    dmi_io_run_training
 *      @substepdesc    : Run training on MC buses
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     6
 *      @substepname    dmi_post_trainadv
 *      @substepdesc    : Advanced post DMI training
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     7
 *      @substepname    proc_cen_framelock
 *      @substepdesc    : Initialize EDI Frame
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     8
 *      @substepname    host_startPRD_dmi
 *      @substepdesc    : Load PRD for DMI domain
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     9
 *      @substepname    host_attnlisten_cen
 *      @substepdesc    : Start listening for attentions
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum    10 
 *      @substepname    cen_set_inband_addr
 *      @substepdesc    : Set the Inband base addresses
 *          @target_sched   serial
 *  @}
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>


namespace   DMI_TRAINING
{

/**
 * @brief   dmi_scominit
 *
 *  11.1 :  Scom setup on centaur
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_dmi_scominit( void * io_pArgs );


/**
 *  @brief   dmi_erepair
 *
 *  11.2   : Restore EDI Bus eRepair data
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_dmi_erepair( void * io_pArgs );


/**
 *  @brief   dmi_io_dccal
 *
 *  11.3 : Calibrate DMI interfaces
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_dmi_io_dccal( void * io_pArgs );


/**
 *  @brief   dmi_pre_trainadv
 *
 *  11.4    : Advanced pre DMI training
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_dmi_pre_trainadv( void * io_pArgs );


/**
 *  @brief   dmi_io_run_training
 *
 *  11.5    : Run training on MC buses
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_dmi_io_run_training( void * io_pArgs );


/**
 *  @brief   dmi_post_trainadv
 *
 *  11.6    : Advanced post DMI training
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_dmi_post_trainadv( void * io_pArgs );


/**
 *  @brief  proc_cen_framelock
 *
 *  11.7    : Initialize EDI Frame
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_proc_cen_framelock( void *io_pArgs );


/**
 *  @brief   host_startPRD_dmi
 *
 *  11.8 : Load PRD for DMI domain
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_host_startPRD_dmi( void * io_pArgs );


/**
 *  @brief   host_attnlisten_cen
 *
 *  11.9    : Start listening for attentions
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_host_attnlisten_cen( void * io_pArgs );


/**
 *  @brief   cen_set_inband_addr
 *
 *  11.10    : Set the Inband base addresses
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                               or NULL.
 *  return  none
 *
 */
void    call_cen_set_inband_addr( void * io_pArgs );


};   // end namespace

#endif
