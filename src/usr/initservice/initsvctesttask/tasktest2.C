//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/initsvcunittesttask2/tasktest2.C $
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

/**
 *  @file tasktest2.H
 *
  */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <sys/task.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include    <initservice/initsvcreasoncodes.H>

#include "tasktest2.H"

namespace   INITSERVICE
{

TASK_ENTRY_MACRO( InitSvcTaskTest2::getTheInstance().init );

/******************************************************************************/
// Globals/Constants
/******************************************************************************/

/******************************************************************************/
// InitService::getTheInstance return the only instance
/******************************************************************************/
InitSvcTaskTest2& InitSvcTaskTest2::getTheInstance()
{
    return Singleton<InitSvcTaskTest2>::instance();
}


void    InitSvcTaskTest2::init( errlHndl_t  &io_taskRetErrl )
{
    errlHndl_t  l_errl  =   NULL;


    task_end2( l_errl );
};

} // namespace
