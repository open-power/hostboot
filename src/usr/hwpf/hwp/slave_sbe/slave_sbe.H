/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/slave_sbe/slave_sbe.H $
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
 *  @docversion     v1.05 (06/28/12)
 *  @istepname      slave_sbe
 *  @istepnum       6
 *  @istepdesc      Slave SBE
 *
 *  @{
 *      @substepnum     8
 *      @substepname    proc_revert_sbe_mcs_setup
 *      @substepdesc    : Clean up MCS Extent regs
 *          @target_sched   serial
 *  @}
 *
 */

namespace SLAVE_SBE
{

/**
 *  @brief proc_revert_sbe_mcs_setup
 *
 *  6.8 : : Clean up MCS Extent regs
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return none
 */
void call_proc_revert_sbe_mcs_setup(void *io_pArgs);

};   // end namespace

#endif
