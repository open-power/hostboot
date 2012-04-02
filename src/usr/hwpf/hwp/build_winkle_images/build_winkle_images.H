//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/build_winkle_images/build_winkle_images.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

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
 *  THIS FILE WAS GENERATED ON 2012-04-11:1608
 *  *****************************************************************
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.01 (03/26/12)
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
 *      @substepname    proc_set_pore_bar
 *      @substepdesc    : Place winkle images in memory
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
 *  15.1 : : Build runtime winkle images
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_host_build_winkle( void    *io_pArgs );



/**
 *  @brief   proc_set_pore_bar
 *
 *  15.2 : : Place winkle images in memory
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  none
 *
 */
void    call_proc_set_pore_bar( void    *io_pArgs );


};   // end namespace

#endif

