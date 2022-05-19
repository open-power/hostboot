/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/console.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2022                        */
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
#ifndef __KERNEL_CONSOLE_H
#define __KERNEL_CONSOLE_H

#include <stdint.h>
#include <string.h>
#include <builtins.h>

#include <util/sprintf.H>

#ifdef HOSTBOOT_DEBUG
    #define printkd(format...) printk(format)
#else
    #define printkd(format...)
#endif

void printk(const char*, ...) FORMAT_PRINTF;

class Console : public Util::ConsoleBufferInterface
{
    public:
    int putc(int);
        size_t operator()(int c) { return putc(c); };

    enum { BUFFER_SIZE = 1024 * 36 };

    protected:
    Console();
    ~Console() {};

    private:
    size_t iv_pos;
    char * iv_buffer;
};

extern char kernel_printk_buffer[Console::BUFFER_SIZE];

#endif
