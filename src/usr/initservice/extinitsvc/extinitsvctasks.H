/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/extinitsvc/extinitsvctasks.H $            */
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
#ifndef __EXT_INIT_SVC_TASKS_H
#define __EXT_INIT_SVC_TASKS_H

/**
 * @file    extinitsvctasks.H
 *
 *  TaskInfo structs for each task that will run in the extended image.
 */

#include    <initservice/initsvcreasoncodes.H>
#include    "extinitsvc.H"

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
         * @brief   FSI Device Driver
         */

        {
            "libfsi.so" ,                               // taskname
            NULL,                                       // no pointer to fn
            {
                INIT_TASK,                          // task type
                EXT_IMAGE,                          // Extended Module
            }
        },

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

        /**
         * @brief   SCAN Device Driver
         */
        {
            "libscan.so" ,                              // taskname
            NULL,                                       // no pointer to fn
            {
                INIT_TASK,                          // task type
                EXT_IMAGE,                          // Extended Module
            }
        },


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
         * @brief inband scom code library
         */
        {
            "libibscom.so" ,                      // taskname
            NULL,                                 // no pointer to fn
            {
               INIT_TASK,                         // task type
               EXT_IMAGE,                         // Extended Module
            }
        },
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
         * @brief   ecmddatabuffer task,
         */
        {
                "libecmddatabuffer.so" ,                    // taskname
                NULL,                                       // no pointer to fn
                {
                        INIT_TASK,                          // task type
                        EXT_IMAGE,                          // Extended Module
                }
        },

        /**
         * @brief   fapi task,
         */
        {
                "libfapi.so" ,                              // taskname
                NULL,                                       // no pointer to fn
                {
                        INIT_TASK,                          // task type
                        EXT_IMAGE,                          // Extended Module
                }
        },

        /**
         * @brief   hwp task,
         */
        {
                "libhwp.so" ,                               // taskname
                NULL,                                       // no pointer to fn
                {
                        INIT_TASK,                          // task type
                        EXT_IMAGE,                          // Extended Module
                }
        },

        /**
         * @brief   plat task,
         */
        {
                "libplat.so" ,                              // taskname
                NULL,                                       // no pointer to fn
                {
                        START_TASK,                         // task type
                        EXT_IMAGE,                          // Extended Module
                }
        },

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

        /**
         * @brief  bus_training library.
         */
        {
            "libbus_training.so",                  // library name
            NULL,                                  // no function to run
            {
                INIT_TASK,                         // init only
                EXT_IMAGE,                         // extended image module
            }
        },

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
