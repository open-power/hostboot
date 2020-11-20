/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/daemon.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
#include <util/misc.H>

extern char hbi_ImageId[];

namespace CONSOLE
{
    extern msg_q_t g_msgq;

    std::array<Uart*, NUM_VUARTS> devices{};

    /* Display characters one at a time from string. */
    void _display(const char* str, const uartId_t id)
    {

        while(*str)
        {
            // UART uses DOS-style new lines. "\r\n"
            if (*str == '\n')
            {
                devices[id]->putc('\r');
            }

            devices[id]->putc(*str);

            str++;
        }
    }

    void* consoleDaemon(void* unused)
    {
        // Detach and register daemon with shutdown path.
        task_detach();
        INITSERVICE::registerShutdownEvent(CONSOLE_COMP_ID, g_msgq, SYNC,
                                           INITSERVICE::CONSOLE_PRIORITY);

        for(uint8_t device_id = VUART1; device_id < NUM_VUARTS; device_id++)
        {
            devices[device_id] = new Uart();
            devices[device_id]->initialize(static_cast<uartId_t>(device_id));
        }

        Util::setIsConsoleStarted();

        // Display a banner denoting the hostboot version
        char banner[256];
        snprintf(banner, sizeof(banner),
                 "\n\n--== Welcome to Hostboot %s Boot Status (VUART1) ==--\n\n",
                 hbi_ImageId);
        _display(banner, VUART1);
        snprintf(banner, sizeof(banner),
                 "\n\n--== Welcome to Hostboot %s Debug Trace (VUART2) ==--\n\n",
                 hbi_ImageId);
        _display(banner, VUART2);

        while(1)
        {
            msg_t* msg = msg_wait(g_msgq);
            uartId_t id = DEBUG;
            switch (msg->type)
            {
                case DISPLAY_DEFAULT:
                    id = DEFAULT;
                case DISPLAY_DEBUG:
                {
                    if (NULL != msg->extra_data)
                    {
                        char timestamp[11];
                        sprintf(timestamp, "%3d.%05d|",
                                msg->data[0],
                                    // 5 Digits worth of ns.
                                (msg->data[1]*100000)/NS_PER_SEC);

                        _display(timestamp,
                                 id);

                        _display(static_cast<const char*>(msg->extra_data),
                                 id);
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
