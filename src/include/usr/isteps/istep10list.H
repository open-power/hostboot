//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/isteps/istep10list.H $
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

#ifndef __ISTEPS_ISTEP10LIST_H
#define __ISTEPS_ISTEP10LIST_H


/**
 * @file    istep10list.H
 *
 *  Step 10 Hostboot SBE Centaur Init
 *  IPL FLow Doc    v0.99 (02/10/12)
 *
 *  Please see the note in initsvcstructs.H for description of
 *      the ISTEPNAME macro.
 *
 */



#include    <initservice/initsvcstructs.H>
#include    <initservice/initsvcreasoncodes.H>

//  include prototypes file
#include    "../../../usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.H"

namespace   INITSERVICE
{

const   TaskInfo    g_istep10[]  =   {

        {
                ISTEPNAME(10,00,"cen_sbe_tp_chiplet_init1"),
                SBE_CENTAUR_INIT::call_cen_sbe_tp_chiplet_init1,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },
        {
                ISTEPNAME( 10, 01, "cen_sbe_tp_arrayinit"),
                SBE_CENTAUR_INIT::call_cen_sbe_tp_arrayinit,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },
        {
                ISTEPNAME(10,02,"cen_sbe_tp_chiplet_init2"),
                SBE_CENTAUR_INIT::call_cen_sbe_tp_chiplet_init2,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,03,"cen_sbe_tp_chiplet_init3"),
                SBE_CENTAUR_INIT::call_cen_sbe_tp_chiplet_init3,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,04,"cen_sbe_chiplet_init"),
                SBE_CENTAUR_INIT::call_cen_sbe_chiplet_init,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,05,"cen_sbe_arrayinit"),
                SBE_CENTAUR_INIT::call_cen_sbe_arrayinit,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,06,"cen_sbe_pll_initf"),
                SBE_CENTAUR_INIT::call_cen_sbe_pll_initf,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,07,"cen_sbe_dts_init"),
                SBE_CENTAUR_INIT::call_cen_sbe_dts_init,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,08,"cen_sbe_initf"),
                SBE_CENTAUR_INIT::call_cen_sbe_initf,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,09,"cen_sbe_do_manual_inits"),
                SBE_CENTAUR_INIT::call_cen_sbe_do_manual_inits,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,10,"cen_sbe_startclocks"),
                SBE_CENTAUR_INIT::call_cen_sbe_startclocks,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },        {
                ISTEPNAME(10,11,"cen_sbe_scominits"),
                SBE_CENTAUR_INIT::call_cen_sbe_scominits,
                {
                        START_FN,
                        EXT_IMAGE,
                        ISTEP_ERRL_ID,
                }
        },


        //  END OF LIST!
};

// make a struct from the above with the number of items included
const   ExtTaskInfo g_istep10TaskList    =   {
        &(g_istep10[0]),
        ( sizeof(g_istep10)/sizeof(TaskInfo) ),
        NULL
};

};  // end namespace

#endif
