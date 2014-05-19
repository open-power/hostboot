/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/build_winkle_images.H $  */
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
#ifndef  __BUILD_WINKLE_IMAGES_BUILD_WINKLE_IMAGES_H
#define  __BUILD_WINKLE_IMAGES_BUILD_WINKLE_IMAGES_H

/**
 *  @file build_winkle_images.H
 *
 *  Build Winkle Images
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-12:1228
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      build_winkle_images
 *  @istepnum       15
 *  @istepdesc      Build Winkle Images
 *
 *  @{
 *      @substepnum     1
 *      @substepname    host_build_winkle
 *      @substepdesc    : Build runtime winkle images
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    p8_set_pore_bar
 *      @substepdesc    : Tell SLW Eng where winkle image is
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    proc_poreslw_init
 *      @substepdesc    : Initialize the PORE-SLW engine
 *          @target_sched   serial
 *  @}
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   BUILD_WINKLE_IMAGES
{


/**
 *  @brief   host_build_winkle
 *
 *           Build runtime winkle images
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_host_build_winkle( void    *io_pArgs );



/**
 *  @brief   proc_set_pore_bar
 *
 *           Tell SLW Eng where winkle image is
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 *
 */
void*    call_proc_set_pore_bar( void    *io_pArgs );


/**
 *  @brief   p8_poreslw_init
 *
 *           Initialize the PORE-SLW engine
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_p8_poreslw_init( void    *io_pArgs );

};   // end namespace

#endif

