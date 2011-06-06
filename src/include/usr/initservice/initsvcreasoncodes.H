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
    START_TRACE_ID          =   0x00,
    START_ERRL_ID,
    START_XSCOMDD_ID,
    START_PNORDD_ID,
    START_VFS_2_ID,
    START_TARGETTING_ID,
    GET_MASTER_CHIP_TARGET_ID,
    START_MAILBOXDD_ID,
    START_SP_COMM_ID,
    ENABLE_STREAMING_TRACE_ID,
    START_PROGRESS_CODES_ID,
    START_FSIDD_ID,
    SETUP_SLAVE_LINKS_ID,
    START_FSISCOM_ID,
    START_FSI_II2C_ID,
    START_HWP_ID,
    READ_MAX_CONFIG_FROM_PNOR_ID,
    APPLY_PRESENCE_DETECT_ID,
    APPLY_PARTIAL_BAD_ID,
    APPLY_GARD_ID,
    COLLECT_HW_IDEC_ID,
    VERIFY_IDEC_ID,
    DISABLE_WATCHDOG_ID,
    EXECUTE_ISTEPS_ID,

    //  reserve some tasks for my unit tests...
    INIT_SVC_TEST1_ID       =   0xf0,
    INIT_SVC_TEST2_ID,
    INIT_SVC_TEST3_ID,
    INIT_SVC_TEST4_ID,
    INIT_SVC_TEST5_ID,

};


enum    InitServiceReasonCode
{
    START_TASK_FAILED           = INITSVC_COMP_ID | 0x01,


};

};  // namespace    INITSERVICE

#endif
