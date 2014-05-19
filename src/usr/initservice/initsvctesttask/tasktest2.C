/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/initsvctesttask/tasktest2.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

    io_taskRetErrl=l_errl;
};

} // namespace
