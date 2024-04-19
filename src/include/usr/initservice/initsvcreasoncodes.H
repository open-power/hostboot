/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initsvcreasoncodes.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2024                        */
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
    RECONFIG_LOOP_TEST_ID               =   0x05,
    ISTEP_INJECT_MOD_ID                 =   0x06,

};


enum    InitServiceReasonCode
{
    START_TASK_FAILED            =   INITSVC_COMP_ID | 0x01,
    START_FN_FAILED              =   INITSVC_COMP_ID | 0x02,
    CXXTEST_FAILED_TEST          =   INITSVC_COMP_ID | 0x03,
    SHUTDOWN_FLUSH_FAILED        =   INITSVC_COMP_ID | 0x04,
    WAIT_TASK_FAILED             =   INITSVC_COMP_ID | 0x05,
    WAIT_FN_FAILED               =   INITSVC_COMP_ID | 0x06,
    INITSVC_LOAD_MODULE_FAILED   =   INITSVC_COMP_ID | 0x07,
    NO_MSG_PRESENT               =   INITSVC_COMP_ID | 0x08,
    ISTEP_RECONFIG_LOOP_ENTERED  =   INITSVC_COMP_ID | 0x09,
    //termination_rc
    ISTEP_FAILED_DUE_TO_DECONFIG =   INITSVC_COMP_ID | 0x0a,
    //termination_rc
    SHUTDOWN_REQUESTED_BY_FSP    =   INITSVC_COMP_ID | 0x0b,
    ISTEP_INVALID_ON_MPIPL       =   INITSVC_COMP_ID | 0x0c,
    ISTEP_NON_MASTER_NODE_MSG    =   INITSVC_COMP_ID | 0x0d,
    //termination_rc
    SBE_EXTRACT_RC_REQUEST_REIPL =   INITSVC_COMP_ID | 0x0e,
    RECONFIG_LOOP_TEST_RC        =   INITSVC_COMP_ID | 0x0f,
    //termination_rc
    SHUTDOWN_NOT_RECONFIG_LOOP   =   INITSVC_COMP_ID | 0x10,
    ISTEP_SKIP_ATTEMPTED         =   INITSVC_COMP_ID | 0x11,
    ISTEP_PROCESSING_DISABLED    =   INITSVC_COMP_ID | 0x12,
    //termination_rc
    SHUTDOWN_DO_RECONFIG_LOOP    =   INITSVC_COMP_ID | 0x13,
    //termination_rc
    SHUTDOWN_MFG_TERM            =   INITSVC_COMP_ID | 0x14,
    //termination_rc
    SHUTDOWN_KEY_TRANSITION      =   INITSVC_COMP_ID | 0x15,

    ISTEP_ATTN_MONITOR_MSG_FAILED =  INITSVC_COMP_ID | 0x16,
    ISTEP_IPL_STATS               =  INITSVC_COMP_ID | 0x17,
    ISTEP_ERROR_INJECTED          =  INITSVC_COMP_ID | 0x18,
};

enum InitServiceUserDetailDataSubSection
{
    INIT_SVC_UDT_ISTEP       = 0x01,
    INIT_SVC_UDT_ISTEP_STATS = 0x02,
};


// Since the reasoncodes defined in InitServiceReasonCode above can be used in calls to
// doShutdown() without an actual error log being created, the BMC can create a TI error
// log without a custdesc (which also creates a service action for HMC).  To create the
// the proper callout for the PEL parsing put dummy errorlog doxygen comments here using
// the common moduleid BASE_INITSVC_MOD_ID which is used in InitService::_doShutdown().

/*@
 * @errortype
 * @moduleid        BASE_INITSVC_MOD_ID
 * @reasoncode      SBE_EXTRACT_RC_REQUEST_REIPL
 * @userdata1       UNDEFINED
 * @userdata2       UNDEFINED
 * @devdesc         Hostboot code called doShutdown() directly
 * @custdesc        Firmware requested a re-IPL/reboot
 */

/*@
 * @errortype
 * @moduleid        BASE_INITSVC_MOD_ID
 * @reasoncode      SHUTDOWN_DO_RECONFIG_LOOP
 * @userdata1       UNDEFINED
 * @userdata2       UNDEFINED
 * @devdesc         Hostboot code called doShutdown() directly to request a reconfig loop
 * @custdesc        Firmware requested part of the IPL to be done again
 */

/*@
 * @errortype
 * @moduleid        BASE_INITSVC_MOD_ID
 * @reasoncode      SHUTDOWN_MFG_TERM
 * @userdata1       UNDEFINED
 * @userdata2       UNDEFINED
 * @devdesc         Hostboot code called doShutdown() directly because an error was committed
 *                  in manufacturing mode
 * @custdesc        Firmware shutdown the system due to an error log being commited while the system
 *                  was running in manufacturing mode
 */

/*@
 * @errortype
 * @moduleid        BASE_INITSVC_MOD_ID
 * @reasoncode      SHUTDOWN_KEY_TRANSITION
 * @userdata1       UNDEFINED
 * @userdata2       UNDEFINED
 * @devdesc         Hostboot code called doShutdown() directly after a SBE Update where the
 *                  security keys were updated
 * @custdesc        Firmware shutdown the system after some security settings were updated
 */

};  // namespace    INITSERVICE

#endif
