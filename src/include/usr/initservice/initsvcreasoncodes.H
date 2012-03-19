//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/initservice/initsvcreasoncodes.H $
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
    INITSVC_START_TASK_MOD_ID           =   0x01,
    INITSVC_START_FN_MOD_ID             =   0x02,
    INITSVC_TASK_RETURNED_ERROR_ID      =   0x03,
    EXTINITSVC_TASK_RETURNED_ERROR_ID   =   0x04,
    CXXTEST_TASK_RETURNED_ERROR_ID      =   0x05,
    ISTEP_RETURNED_ERROR_ID             =   0x06,
    INITSVC_DO_SHUTDOWN_MOD_ID          =   0x07,
};


enum    InitServiceReasonCode
{
    START_TASK_FAILED           =   INITSVC_COMP_ID | 0x01,
    INVALID_TASK_TYPE           =   INITSVC_COMP_ID | 0x02,
    START_FN_FAILED             =   INITSVC_COMP_ID | 0x03,
    NULL_FN_PTR                 =   INITSVC_COMP_ID | 0x04,
    ISTEP_FAILED_NO_ERRLOG      =   INITSVC_COMP_ID | 0x05,
    INITSVC_FAILED_NO_ERRLOG    =   INITSVC_COMP_ID | 0x06,
    EXTINITSVC_FAILED_NO_ERRLOG =   INITSVC_COMP_ID | 0x07,
    CXXTEST_FAILED_NO_ERRLOG    =   INITSVC_COMP_ID | 0x08,
    SHUTDOWN_FLUSH_FAILED       =   INITSVC_COMP_ID | 0x09,
};

enum InitServiceUserDetailDataSubSection
{
    INIT_SVC_UDT_ISTEP = 0x01,
};

};  // namespace    INITSERVICE

#endif
