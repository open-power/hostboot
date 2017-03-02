/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/daemon.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#include <stdio.h>
#include <sys/msg.h>
#include <sys/task.h>
#include <sys/time.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include "uart.H"
#include "daemon.H"

extern char hbi_ImageId[];

namespace CONSOLE
{
    extern msg_q_t g_msgq;

    /* Display characters one at a time from string. */
    void _display(const char* str)
    {

        while(*str)
        {
            // UART uses DOS-style new lines. "\r\n"
            if (*str == '\n')
            {
                Uart::g_device->putc('\r');
            }

            Uart::g_device->putc(*str);

            str++;
        }
    }

    void* consoleDaemon(void* unused)
    {
        // Detach and register daemon with shutdown path.
        task_detach();
        INITSERVICE::registerShutdownEvent(g_msgq, SYNC,
                                           INITSERVICE::CONSOLE_PRIORITY);

        // Create a default output UART device if there isn't already one.
        //    - Some devices are registered via the CONSOLE_UART_DEFINE_DEVICE
        //      macro and therefore don't need this.
        if (NULL == Uart::g_device)
        {
            Uart::g_device = new Uart();
            Uart::g_device->initialize();
        }

        // Display a banner denoting the hostboot version
        char banner[256];
        snprintf(banner, sizeof(banner),
                 "\n\n--== Welcome to Hostboot %s ==--\n\n",
                 hbi_ImageId);
        _display(banner);

        while(1)
        {
            msg_t* msg = msg_wait(g_msgq);

            switch (msg->type)
            {
                case DISPLAY:
                {
                    if (NULL != msg->extra_data)
                    {
                        char timestamp[11];
                        sprintf(timestamp, "%3d.%05d|",
                                msg->data[0],
                                    // 5 Digits worth of ns.
                                (msg->data[1]*100000)/NS_PER_SEC);
                        _display(timestamp);

                        _display(
                            static_cast<const char*>(msg->extra_data));
                        free(msg->extra_data);
                    }
                    msg_free(msg);
                    break;
                }

                case SYNC:
                {
                    msg_respond(g_msgq, msg);
                    break;
                }
            }

        }

        return NULL;
    }

    void consoleEntryPoint(errlHndl_t& o_errl)
    {
        task_create(&consoleDaemon, NULL);
    }
}

TASK_ENTRY_MACRO(CONSOLE::consoleEntryPoint);
