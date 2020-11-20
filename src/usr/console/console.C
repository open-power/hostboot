/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/console/console.C $                                   */
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
#include <console/consoleif.H>
#include <util/sprintf.H>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>
#include "daemon.H"

namespace CONSOLE
{
    msg_q_t g_msgq = msg_q_create();

    void display(const uartId_t id, const char* str)
    {
        timespec_t time;
        clock_gettime(CLOCK_MONOTONIC, &time);

        msg_t* msg = msg_allocate();
        msg->type = id;
        msg->data[0] = time.tv_sec;
        msg->data[1] = time.tv_nsec;
        msg->extra_data = strdup(str);
        msg_send(g_msgq, msg);
    }

    void displayf(const uartId_t id, const char* header, const char* format, ...)
    {
        va_list args;
        va_start(args, format);

        vdisplayf(id, header, format, args);

        va_end(args);
    }

    void vdisplayf(const uartId_t id, const char* header, const char* format, va_list args)
    {
        using Util::vasprintf;

        class OutputBuffer : public Util::ConsoleBufferInterface
        {
            public:
                OutputBuffer() { str.reserve(64); }

                int putc(int c)
                {
                    str.push_back(c);
                    return c;
                }

                size_t operator()(int c) { return putc(c); }

                std::vector<char> str;
        };

        OutputBuffer b;

        if (header)
        {
            while(*header)
            {
                b.putc(*header);
                header++;
            }
            b.putc('|');
        }

        vasprintf(b, format, args);
        b.putc('\n');
        b.putc('\0');

        if (b.str.size())
        {
            display(id, &b.str[0]);
        }
    }

    void flush()
    {
        msg_t* msg = msg_allocate();
        msg->type = SYNC;
        msg_sendrecv(g_msgq, msg);

        // Always free since send/recv implies ownership
        msg_free(msg);
        msg=nullptr;
    }

}
