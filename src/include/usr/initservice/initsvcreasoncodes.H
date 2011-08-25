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
    UNDEFINED_MODULE_ERRL_ID     =   0x00,
    BASE_INITSVC_ERRL_ID,
    START_TRACE_ERRL_ID,
    START_ERRL_ERRL_ID,
    START_XSCOMDD_ERRL_ID,
    START_PNORDD_ERRL_ID,
    START_EXTINITSVC_ERRL_ID,
    START_TARGETING_ERRL_ID,
    GET_MASTER_CHIP_TARGET_ERRL_ID,
    START_MAILBOXDD_ERRL_ID,
    START_SP_COMM_ERRL_ID,
    ENABLE_STREAMING_TRACE_ERRL_ID,
    START_PROGRESS_CODES_ERRL_ID,
    START_FSIDD_ERRL_ID,
    SETUP_SLAVE_LINKS_ERRL_ID,
    START_FSISCOM_ERRL_ID,
    START_FSI_II2C_ERRL_ID,
    START_HWP_ERRL_ID,
    READ_MAX_CONFIG_FROM_PNOR_ERRL_ID,
    APPLY_PRESENCE_DETECT_ERRL_ID,
    APPLY_PARTIAL_BAD_ERRL_ID,
    APPLY_GARD_ERRL_ID,
    COLLECT_HW_ERRL_IDEC_ERRL_ID,
    VERIFY_ERRL_IDEC_ERRL_ID,
    DISABLE_WATCHDOG_ERRL_ID,
    EXECUTE_ISTEPS_ERRL_ID,
    START_VFS_ERRL_ID,
    START_ECMDDATABUFFER_ERRL_ID,
    START_HWPF_ERRL_ID,
    START_FAPI_ERRL_ID,
    START_PLAT_ERRL_ID,

    ISTEP_1_ERRL_ID,
    ISTEP_2_ERRL_ID,
    ISTEP_3_ERRL_ID,
    ISTEP_4_ERRL_ID,
    ISTEP_5_ERRL_ID,

    //  reserve some tasks for my unit tests...
    START_CXXTEST_ERRL_ID       =   0xf0,
    INIT_SVC_TEST1_ERRL_ID,
    INIT_SVC_TEST2_ERRL_ID,
    INIT_SVC_TEST3_ERRL_ID,
    INIT_SVC_TEST4_ERRL_ID,
    INIT_SVC_TEST5_ERRL_ID,

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
