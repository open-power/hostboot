/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/extinitsvc/extinitsvctasks.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
/* [+] Google Inc.                                                        */
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
#ifndef __EXT_INIT_SVC_TASKS_H
#define __EXT_INIT_SVC_TASKS_H

/**
 * @file    extinitsvctasks.H
 *
 *  TaskInfo structs for each task that will run in the extended image.
 */

#include    <initservice/initsvcreasoncodes.H>
#include    "extinitsvc.H"
#include    <config.h>

namespace   INITSERVICE
{


const TaskInfo g_exttaskinfolist[]   =   {

        //  -----   Extended Image  ------------------------------------------

        /**
         * @brief  util library.
         */
        {
            "libutil.so",                          // library name
            NULL,                                  // no function to run
            {
                INIT_TASK,                         // init only
                EXT_IMAGE,                         // extended image module
            }
        },

        /**
         * @brief console library
         */
#ifdef CONFIG_CONSOLE
        {
            "libconsole.so",                       // library name
            NULL,                                  // no function to run
            {
                START_TASK,                        // task type
                EXT_IMAGE,                         // extended image module
            }
        },
#endif

#ifdef CONFIG_SECUREBOOT
        /**
         *  @brief Secureboot extended
         */
        {
            "libsecureboot_ext.so",                // taskname
            NULL,                                  // no pointer to fn
            {
                INIT_TASK,                         // task type
                EXT_IMAGE,                         // Extended Module
            }
        },
#endif
        /**
         * @brief   targeting task,
         */
        {
            "libtargeting.so" ,                         // taskname
            NULL,                                       // no pointer to fn
            {
                START_TASK,                         // task type
                EXT_IMAGE,                          // Extended Module
            }
        },
#if defined(CONFIG_PLDM) || defined(CONFIG_PLDM_TESTCASES)
        /**
         * @brief   PLDM Extended
         */
        {
            "libpldm_extended.so",                      // taskname
            NULL,                                       // no ptr to fnct
            {

                START_TASK,                              // task type
                EXT_IMAGE,                              // Extended Module
            }
        },
#endif
        /**
         * @brief   HWAS,
         * need the hwas module for errl dependency gard / deconfig
         */
        {
            "libhwas.so" ,                                  // taskname
            NULL,                                           // no pointer to fn
            {
                INIT_TASK,                                  // task type
                EXT_IMAGE,                                  // Extended Module
            }
        },

        /**
         * @brief   FSI Device Driver
         */

        {
            "libfsi.so" ,                               // taskname
            NULL,                                       // no pointer to fn
            {
                INIT_TASK,                          // init only
                EXT_IMAGE,                          // Extended Module
            }
        },

        /**
         * @brief External interrupt resource provider
         */
        {
            "libintr.so",                               // taskname
            NULL,                                       // no ptr to fnct
            {
                START_TASK,                             // task type
                EXT_IMAGE,                              // Extended Module
            }
        },

        /**
         * @brief SBE IO Device Driver
         */
        {
            "libsbeio.so",                               // taskname
            NULL,                                       // no ptr to fnct
            {

                INIT_TASK,                          // init only
                EXT_IMAGE,                          // Extended Module
            }
        },

        /**
         * @brief Mailbox service provider
         */
        {
            "libmbox.so",                               // taskname
            NULL,                                       // no ptr to fnct
            {

                START_TASK,                             // task type
                EXT_IMAGE,                              // Extended Module
            }
        },

#ifdef CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY
        /**
         * @brief Human readable error log display
         * Note: Because of dependencies, this must come after libmbox.so
         *       or hostboot will hang with an Inst Storage exception
         *       (the ErrlManager constructor tries to talk to MBOX.)
         */
        {
            "liberrldisplay.so",                        // taskname
            NULL,                                       // no ptr to fnct
            {
                START_TASK,                             // task type
                EXT_IMAGE,                              // Extended Module
            }
        },
#endif

        /**
         * @brief Trace daemon
         */
        {
            "libtracedaemon.so",                        // taskname
            NULL,                                       // no ptr to fnct
            {

                START_TASK,                             // task type
                EXT_IMAGE,                              // Extended Module
            }
        },

        /**
         * @brief IPMI
         */
#ifdef CONFIG_BMC_IPMI
        {
            "libipmiext.so",                            // taskname
            NULL,                                       // no ptr to fnct
            {

                START_TASK,                             // task type
                EXT_IMAGE,                              // Extended Module
            }
        },
#endif

#ifndef CONFIG_VPO_COMPILE
        /**
         * @brief   FSI SCOM Device Driver
         */
        {
            "libfsiscom.so" ,                           // taskname
            NULL,                                       // no pointer to fn
            {
                INIT_TASK,                          // task type
                EXT_IMAGE,                          // Extended Module
            }
        },
#endif


#ifdef CONFIG_DEVTREE
        /**
         * @brief   Device tree sync
         */
        {
            "libdevtree.so" ,                           // taskname
            NULL,                                       // no pointer to fn
            {
                INIT_TASK,                          // task type
                EXT_IMAGE,                          // Extended Module
            }
        },
#endif


        /**
         * @brief   I2C Device Driver
         */
        {
            "libi2c.so" ,                       // taskname
            NULL,                               // no pointer to fn
            {
                INIT_TASK,                      // task type
                EXT_IMAGE,                      // Extended Module
            }
        },

        /**
         * @brief   Eeprom Task
         */
        {
            "libeeprom.so" ,                     // taskname
            NULL,                               // no pointer to fn
            {
                START_TASK,                      // task type
                EXT_IMAGE,                      // Extended Module
            }
        },

        /**
         * @brief   fapi2 task, handles attribute override and fapi2 plat intf.
         */
        {
            "libfapi2.so" ,                                 // taskname
            NULL,                                           // no pointer to fn
            {
                    START_TASK,                             // task type
                    EXT_IMAGE,                              // Extended Module
            }
        },

        /**
         * @brief   Serial Peripheral Interface (SPI) Device Driver library
         */
        {
            "libspi.so" ,                       // taskname
            NULL,                               // no pointer to fn
            {
                START_TASK,                     // task type
                EXT_IMAGE,                      // Extended Module
            }
        },

        /**
         * @brief spd task
         */
        {
            "libvpd.so",                                    // taskname
            NULL,                                           // no pointer to fn
            {
                INIT_TASK,                                  // task type
                EXT_IMAGE,                                  // Extended module
            }
        },
        /**
         * @brief   fapiwrap task, handles fapi wrapper for platform libraries
         */
        {
            "libfapiwrap.so" ,                              // taskname
            NULL,                                           // no pointer to fn
            {
                    INIT_TASK,                              // task type
                    EXT_IMAGE,                              // Extended Module
            }
        },

        // @todo RTC:145354 Restore testprdf and testattn in p9 branch
        /**
         * @brief   Start slave threads
         */
        {
            "libthread_activate.so" ,               // taskname
            NULL,                                   // no pointer to fn
            {
                START_TASK,                         // task type
                EXT_IMAGE,                          // Extended Module
            }
        },
        {
            "libthread_activate.so" ,               // taskname
            NULL,                                   // no pointer to fn
            {
                UNINIT_TASK,                        // task type
                EXT_IMAGE,                          // Extended Module
            }
        },

        // @todo RTC:137627 - remove for p9 bringup
// No mdia in VPO
#ifndef CONFIG_VPO_COMPILE
        /**
         * @brief MDIA code library
         */
        {
            "libmdia.so" ,                        // taskname
            NULL,                                 // no pointer to fn
            {
               INIT_TASK,                         // task type
               EXT_IMAGE,                         // Extended Module
            }
        },

        /**
         * @brief PRDF code library
         */
        {
            "libprdf.so" ,                        // taskname
            NULL,                                 // no pointer to fn
            {
               INIT_TASK,                         // task type
               EXT_IMAGE,                         // Extended Module
            }
        },
#endif

        /**
         * @brief ATTN code library
         */
        {
            "libattn.so" ,                        // taskname
            NULL,                                 // no pointer to fn
            {
               INIT_TASK,                         // task type
               EXT_IMAGE,                         // Extended Module
            }
        },

#ifdef CONFIG_GPIODD
        /**
         * @brief GPIO code library
         */
        {
            "libgpio.so" ,                        // taskname
            NULL,                                 // no pointer to fn
            {
                INIT_TASK,                        // task type
                EXT_IMAGE,                        // Extended Module
            }
        },
#endif

#ifdef CONFIG_TPMDD
        /**
         * @brief   Trusted boot library
         */
        {
            "libsecureboot_trusted.so" ,        // taskname
            NULL,                               // no pointer to fn
            {
                INIT_TASK,                      // task type
                EXT_IMAGE,                      // Extended Module
            }
        },
#endif
#ifndef CONFIG_VPO_COMPILE
        /**
         * @brief   Node Communications Device Driver library
         */
        {
            "libnode_comm.so" ,                 // taskname
            NULL,                               // no pointer to fn
            {
                INIT_TASK,                      // task type
                EXT_IMAGE,                      // Extended Module
            }
        },
#endif

        /**
         * @brief  Explorer Scom library
         */
        {
            "libexpaccess.so" ,                 // taskname
            NULL,                               // no pointer to fn
            {
                INIT_TASK,                      // task type
                EXT_IMAGE,                      // Extended Module
            }
        },

        /**
         * @brief MDS (Micro-architectural Data Sampling) Controller library
         */
        {
            "libmdsaccess.so" ,                 // taskname
            NULL,                               // no pointer to fn
            {
                INIT_TASK,                      // task type
                EXT_IMAGE,                      // Extended Module
            }
        },

        /**
         * @brief   Common istep functions
         *
         *
         */
        {
            "libisteps.so" ,                                // taskname
            NULL,                                           // no pointer to fn
            {
                INIT_TASK,                                  // task type
                EXT_IMAGE,                                  // Extended Module
            }
        },

        /**
         * @brief   MMIO module
         */
        {
            "libmmio.so" ,                                  // taskname
            NULL,                                           // no pointer to fn
            {
                INIT_TASK,                                  // task type
                EXT_IMAGE,                                  // Extended Module
            }
        },
#ifdef CONFIG_NVDIMM
        /**
         * @brief   NVDIMM module
         */
        {
            "libnvdimm.so" ,                                // taskname
            NULL,                                           // no pointer to fn
            {
                INIT_TASK,                                  // task type
                EXT_IMAGE,                                  // Extended Module
            }
        },
#endif

        /**
         * @brief SMF module
         */
        {
            "libsmf.so",                                    // taskname
            NULL,                                           // no pointer to fn
            {
                INIT_TASK,                                  // task type
                EXT_IMAGE,                                  // Extended Module
            }
        },

        //  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // NOTE: libistepdisp.so needs to always be last in this list!!
        //  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        /**
         * @brief   IStep Dispatcher task, runs ISteps
         *
         *
         */
        {
            "libistepdisp.so" ,                             // taskname
            NULL,                                           // no pointer to fn
            {
                START_TASK,                                 // task type
                EXT_IMAGE,                                  // Extended Module
            }
        },
        // NOTE: libistepdisp.so needs to always be last in this list!!

        //  ---------------------------------------------------------------
        //  -----   END OF LIST!!!  ---------------------------------------
        //  ---------------------------------------------------------------

        /**
         * @brief   last task in the list
         */
        {
                "end" ,                                     // dummy string
                NULL,                                       // pointer to fn
                {
                        END_TASK_LIST,                      // end of list
                        UNDEFINED_MT,                       // dummy module type
                }
        },

};

//  -------------------------------------------------------------------------
//  -----   UNIT    TESTS   -------------------------------------------------
//  -------------------------------------------------------------------------
const   TaskInfo    cxxTestTask    =   {
                "libcxxtest.so" ,                           // taskname
                NULL,                                       // no pointer to fn
                {
                        START_TASK,                         // task type
                        EXT_IMAGE,                          // Extended Module
                }
        };


};  // namespace

#endif  // __EXT_INIT_SVC_TASKS_H
