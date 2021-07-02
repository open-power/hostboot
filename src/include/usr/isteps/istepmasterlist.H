/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istepmasterlist.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __ISTEPS_ISTEPMASTERLIST_H
#define __ISTEPS_ISTEPMASTERLIST_H


/**
 * @file    istepmasterlist.H
 *
 *  ExtTaskInfo structs for each IStep that will run.
 *
 *  This is the master list of ISTeps.
 *
 *  To add a new IStep,  make a new file in the isteps directory and name
 *  it "istepNlist.H", where N is the IStep number.
 *  The file will have 2 const arrays of structs defined (see initsvcstructs.H)
 *
 *  const TaskInfo g_istepN[]   //  define the substeps/"named isteps" within
 *                              //  the IStep
 *
 *  Read through initsvcstructs.H to understand how the TaskInfo Array is
 *  put together.
 *
 *  Then build the ExtTaskInfo struct:
 *  const ExtTaskInfo   g_istepNTaskList =  {
 *      g_istepN,
 *      ( sizeof(g_istepN)/sizeof(TaskInfo) )
 *  }
 *
 *  Then add the pointer to istepNTaskList to the bottom of the g_isteps[]
 *  array below.  IStepDispatcher should pick up the new IStep automagically.
 *
 */

#include    <vector>
#include    <initservice/initsvcstructs.H>

// macro to expand library dependancies
#define DEP_LIB(x) #x

//  -----   istep include files   -----

//  isteps 1-5 run before hostboot

#include    "istep06list.H"
#include    "istep07list.H"
#include    "istep08list.H"
#include    "istep09list.H"
#include    "istep10list.H"
#include    "istep11list.H"
#include    "istep12list.H"
#include    "istep13list.H"

#include    "istep14list.H"
#include    "istep15list.H"
#include    "istep16list.H"
// istep 17, FSP only
#include    "istep18list.H"
// istep 19, FSP only
#include    "istep20list.H"
#include    "istep21list.H"


namespace   INITSERVICE
{

// initialize an array of ExtTaskInfo
const  ExtTaskInfo  g_isteps[]    =   {
        { NULL, 0, NULL },                              //  dummy IStep 0
        { NULL, 0, NULL },                              //  dummy IStep 1
        { NULL, 0, NULL },                              //  dummy IStep 2
        { NULL, 0, NULL },                              //  dummy IStep 3
        { NULL, 0, NULL },                              //  dummy IStep 4
        { NULL, 0, NULL },                              //  dummy IStep 5
        INITSERVICE::g_istep06TaskList,                 //  HWAS  IStep 6
#ifndef CONFIG_VPO_COMPILE // Only run istep 6 in VPO mode
        INITSERVICE::g_istep07TaskList,                 //        IStep 7
        INITSERVICE::g_istep08TaskList,                 //        IStep 8
        INITSERVICE::g_istep09TaskList,                 //        IStep 9
        INITSERVICE::g_istep10TaskList,                 //        IStep 10
        INITSERVICE::g_istep11TaskList,                 //        IStep 11
        INITSERVICE::g_istep12TaskList,                 //        IStep 12
        INITSERVICE::g_istep13TaskList,                 //        IStep 13
        INITSERVICE::g_istep14TaskList,                 //        Istep 14
        INITSERVICE::g_istep15TaskList,                 //        IStep 15
        INITSERVICE::g_istep16TaskList,                 //        IStep 16
        { NULL, 0, NULL},                               //  FSP   IStep 17
#ifdef CONFIG_FSP_BUILD
        { NULL, 0, NULL},                               //  FSP   IStep 18
#else
        INITSERVICE::g_istep18TaskList,                 //        IStep 18
#endif
        { NULL, 0, NULL },                              //  FSP   IStep 19
#ifdef CONFIG_FSP_BUILD
        { NULL, 0, NULL},                               //  FSP   IStep 20
#else
        INITSERVICE::g_istep20TaskList,                 //        IStep 20
#endif
        INITSERVICE::g_istep21TaskList                  //        IStep 21
        //
        // add further istep lists at the end.
#endif  //CONFIG_VPO_COMPILE
};

// See src/include/usr/initservice/initsvcstructs.H for MAX_SUBSTEPS

// publish the size of the g_isteps array
const   uint64_t    MaxISteps   =  sizeof(g_isteps)/sizeof(ExtTaskInfo) ;


};  // namespace

#endif
