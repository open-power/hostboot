/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.H $
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
#ifndef __SBE_CENTAUR_INIT_SBE_CENTAUR_INIT_H
#define __SBE_CENTAUR_INIT_SBE_CENTAUR_INIT_H
/**
 *  @file sbe_centaur_init.H
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      sbe_centaur_init
 *  @istepnum       10
 *  @istepdesc      Step 10 Hostboot SBE Centaur Init
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_prd_hwreconfig
 *      @substepdesc    : Hook for PRD to handle reconfig
 *      @param  target 
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    cen_sbe_tp_chiplet_init1
 *      @substepdesc    : Execute all steps in ISTEP 10
 *      @param  target 
 *          @target_sched   serial
 *  @}

 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>


namespace   SBE_CENTAUR_INIT
{

    /**
     *  @brief   sbe_centaur_init
     *
     *           Execute alll steps in step 10
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to args,
     *                              or NULL.
     *  return  any errlors to istep
     *
     */
    void*    call_sbe_centaur_init( void * io_pArgs );

};   // end namespace

#endif
