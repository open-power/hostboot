//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/istepmasterlist.H $
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

//  -----   istep include files   -----
#include    "istep06list.H"

#include    "istep10list.H"
#include    "istep11list.H"
#include    "istep12list.H"
#include    "istep13list.H"


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
        { NULL, 0, NULL },                              //  dummy IStep 7
        { NULL, 0, NULL },                              //  dummy IStep 8
        { NULL, 0, NULL },                              //  dummy IStep 9
        INITSERVICE::g_istep10TaskList,                 //  SBE_CENTAUR_INIT
        INITSERVICE::g_istep11TaskList,                 //  DMI_TRAINING
        INITSERVICE::g_istep12TaskList,                 //  MC_INIT
        INITSERVICE::g_istep13TaskList,                 //  DRAM_TRAINING
        { NULL, 0, NULL },                              //  dummy IStep 14
        { NULL, 0, NULL },                              //  dummy IStep 15
        { NULL, 0, NULL },                              //  dummy IStep 16

        //
        // add further istep lists at the end.
};


const   uint64_t    MAX_SUBSTEPS =  25;

// publish the size of the g_isteps array
const   uint64_t    MAX_ISTEPS   =  sizeof(g_isteps)/sizeof(ExtTaskInfo) ;


};  // namespace

#endif
