/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initsvcreasoncodes.H $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file    initsvcreasoncodes.H
 *
 *  Detail all the possible reason codes for errorlog returns
 *
 */
#ifndef __INITSERVICE_RC_H
#define __INITSERVICE_RC_H

#include <hbotcompid.H>

namespace   INITSERVICE
{

/**
 * @enum    InitServiceModuleID
 *
 *  module id's used in returned errorlogs
 */
enum    InitServiceModuleID
{
    UNDEFINED_MODULE_ERRL_ID            =   0x00,

    BASE_INITSVC_MOD_ID                 =   0x01,
    EXT_INITSVC_MOD_ID                  =   0x02,
    ISTEP_INITSVC_MOD_ID                =   0x03,
    CXXTEST_MOD_ID                      =   0x04,

};


enum    InitServiceReasonCode
{
    START_TASK_FAILED           =   INITSVC_COMP_ID | 0x01,
    INVALID_TASK_TYPE           =   INITSVC_COMP_ID | 0x02,
    START_FN_FAILED             =   INITSVC_COMP_ID | 0x03,
    NULL_FN_PTR                 =   INITSVC_COMP_ID | 0x04,
    FORCE_FAIL                  =   INITSVC_COMP_ID | 0x05,
    CXXTEST_FAILED_TEST         =   INITSVC_COMP_ID | 0x06,
    SHUTDOWN_FLUSH_FAILED       =   INITSVC_COMP_ID | 0x07,
    WAIT_TASK_FAILED            =   INITSVC_COMP_ID | 0x08,
    WAIT_FN_FAILED              =   INITSVC_COMP_ID | 0x09,
    INITSVC_LOAD_MODULE_FAILED  =   INITSVC_COMP_ID | 0x0a,
    // not used
    ISTEP_SINGLESTEP_ASYNC_RCVD =   INITSVC_COMP_ID | 0x0c,
    ISTEP_BKPOINT_ASYNC_RCVD    =   INITSVC_COMP_ID | 0x0d,
    ISTEP_WAITFORSYNC_BAD_MSG   =   INITSVC_COMP_ID | 0x0e,
    ISTEP_MULTIPLE_ISTEP_REQ    =   INITSVC_COMP_ID | 0x0f,
    ISTEP_FAILED                =   INITSVC_COMP_ID | 0x10,
    LAST_ISTEP_FAILED           =   INITSVC_COMP_ID | 0x11,
    NO_MSG_PRESENT              =   INITSVC_COMP_ID | 0x12,
    ISTEP_INVALID_ISTEP         =   INITSVC_COMP_ID | 0x13,
    ISTEP_FAPI_ATTR_READ_FAILED =   INITSVC_COMP_ID | 0x14,
    ISTEP_DELAYED_DECONFIG      =   INITSVC_COMP_ID | 0x15,

};

enum InitServiceUserDetailDataSubSection
{
    INIT_SVC_UDT_ISTEP = 0x01,
};

};  // namespace    INITSERVICE

#endif
