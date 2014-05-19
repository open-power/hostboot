/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
