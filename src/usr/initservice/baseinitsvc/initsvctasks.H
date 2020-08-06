/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/baseinitsvc/initsvctasks.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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

#ifndef __INIT_SVC_TASKS_H
#define __INIT_SVC_TASKS_H

/**
 * @file    initsvctasks.H
 *
 *  TaskInfo structs for each task that will run.
 */

#include    <initservice/initsvcreasoncodes.H>
#include    "initservice.H"

#include    <secureboot/service.H>

namespace   INITSERVICE
{


const TaskInfo    g_taskinfolist[]   =   {

        /**
         * @brief  Secureboot Base Initialization
         */
        {
                "libsecureboot_base.so",
                &SECUREBOOT::initializeBase,
                {
                        START_FN,
                        BASE_IMAGE,
                }
        },

#ifdef CONFIG_BMC_IPMI
        /**
         * @brief IPMI resource provider
         */
        {
            "libipmibase.so",                           // taskname
            NULL,                                       // no ptr to fnct
            {

                START_TASK,                             // task type
                BASE_IMAGE,                             // Base Module
            }
        },
#endif

        /**
         * @brief   PNOR    Driver  Task
         */
        {
                "libpnor.so" ,                      // taskname
                NULL,                               // no pointer to fn
                {
                        START_TASK,                 // start
                        BASE_IMAGE,                 // Base Module
                }
        },

        /**
         * @brief  Extended VFS module
         */
        {
                "libvfs.so",                        // taskname
                NULL,
                {
                        START_TASK,                 // start task
                        BASE_IMAGE,                 // Base Module
                }
        },
#if defined(CONFIG_MCTP) || defined(CONFIG_MCTP_TESTCASES)
        /**
         * @brief   libmctp
         */
        {
                "libmctp.so" ,                      // taskname
                NULL,                               // no pointer to fn
                {
                        START_TASK,
                        BASE_IMAGE,                  // Base Module
                }
        },
#endif
#if defined(CONFIG_PLDM) || defined(CONFIG_PLDM_TESTCASES)
        /**
         * @brief   libpldm_base
         */
        {
                "libpldm_base.so" ,                 // taskname
                NULL,                               // no pointer to fn
                {
                        START_TASK,
                        BASE_IMAGE,                  // Base Module
                }
        },
#endif
        //  -----   Extended Image  -----------------------------------------------------

        /**
         * @brief   extinitsvc, initializes extended module area
         */
        {
                "libextinitsvc.so" ,                // taskname
                NULL,                               // no pointer to fn
                {
                        START_TASK,
                        EXT_IMAGE,                  // EXT_IMAGE
                }
        },


        //  ---------------------------------------------------------------
        //  -----   END OF LIST!!!  ---------------------------------------
        //  ---------------------------------------------------------------

        /**
         * @brief   last task in the list
         */
        {
                "end" ,                             // dummy string
                NULL,                               // pointer to fn
                {
                        END_TASK_LIST,              // end of list
                        UNDEFINED_MT,               // dummy module type
                }
        },

};


};  // namespace
#endif  //
