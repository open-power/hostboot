/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initsvcreasoncodes.H $            */
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
};

enum InitServiceUserDetailDataSubSection
{
    INIT_SVC_UDT_ISTEP = 0x01,
};

};  // namespace    INITSERVICE

#endif
