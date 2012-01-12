//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwas/hwas.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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

//
//  #########################################
//  THIS IS A GENERATED FILE
//  #########################################
//

#ifndef  __<@istepname>_<@istepname>_H
#define __<@istepname>_<@istepname>_H
/**
 *  @file <@istepname>.H
 *
 *  <@istepname>
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>


namespace   <@istepname>
{

    /**
     *  @brief   <@substepname>
     *
     *  <@istepnum>.<@substepnum> : <@substepdesc>
     *
     *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
     *                              or NULL.
     *  return  none
     *
     */
    void    call_<@substepname>( void * io_pArgs );


};   // end namespace

#endif
