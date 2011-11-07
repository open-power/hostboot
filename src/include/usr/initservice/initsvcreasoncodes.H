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

    //  base image modules
    BASE_INITSVC_ERRL_ID                =   0x01,
    START_TRACE_ERRL_ID                 =   0x02,
    START_ERRL_ERRL_ID                  =   0x03,
    START_PNORDD_ERRL_ID                =   0x04,
    START_VFS_ERRL_ID                   =   0x05,
    START_EXTINITSVC_ERRL_ID            =   0x06,

    // extended image modules
    START_ECMDDATABUFFER_ERRL_ID        =   0x10,
    START_HWPF_ERRL_ID                  =   0x11,
    START_FAPI_ERRL_ID                  =   0x12,
    START_HWP_ERRL_ID                   =   0x13,
    START_PLAT_ERRL_ID                  =   0x14,
    EXECUTE_ISTEPS_ERRL_ID              =   0x15,
    START_FSIDD_ERRL_ID                 =   0x16,
    START_FSISCOM_ERRL_ID               =   0x17,
    START_TARGETING_ERRL_ID             =   0x18,


    //  Internal InitService codes
    INITSVC_START_TASK_MOD_ID           =   0x20,
    INITSVC_START_FN_MOD_ID             =   0x21,
    INITSVC_TASK_RETURNED_ERROR_ID      =   0x22,
    EXTINITSVC_TASK_RETURNED_ERROR_ID   =   0x23,
    CXXTEST_TASK_RETURNED_ERROR_ID      =   0x24,
    ISTEP_RETURNED_ERROR_ID             =   0x25,

    //
    //  HWAS:  ISTEP 4
    //  HWAS named isteps (substeps)
    //  @todo sync these names up with Dean's document later
    //
    HWAS_1_ERRL_ID                      =   0x30,
    HWAS_2_ERRL_ID                      =   0x31,
    HWAS_3_ERRL_ID                      =   0x32,
    HWAS_4_ERRL_ID                      =   0x33,
    HWAS_5_ERRL_ID                      =   0x34,
    HWAS_6_ERRL_ID                      =   0x35,
    HWAS_7_ERRL_ID                      =   0x36,
    HWAS_8_ERRL_ID                      =   0x37,
    HWAS_9_ERRL_ID                      =   0x38,

    //  reserve some tasks for my unit tests...
    START_CXXTEST_ERRL_ID       =   0xf0,
    INIT_SVC_TEST1_ERRL_ID      =   0xf1,
    INIT_SVC_TEST2_ERRL_ID      =   0xf2,
    INIT_SVC_TEST3_ERRL_ID      =   0xf3,
    INIT_SVC_TEST4_ERRL_ID      =   0xf4,
    INIT_SVC_TEST5_ERRL_ID      =   0xf5,

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



};

};  // namespace    INITSERVICE

#endif
