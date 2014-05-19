/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludprintk.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#include <errl/errludprintk.H>
#include <errl/errlreasoncodes.H>
#include <kernel/console.H>
#include <algorithm>
#include <string.h>

namespace ERRORLOG
{

    void ErrlUserDetailsPrintk::_capturePrintk(size_t i_size)
    {
        // Determine existing size of printk buffer.
        size_t printkSize = strnlen(kernel_printk_buffer, Console::BUFFER_SIZE);
        i_size = std::min(i_size, printkSize);

        // Copy trailing i_size to UD buffer.
        uint8_t* buffer = reallocUsrBuf(i_size);
        memcpy(buffer, &kernel_printk_buffer[printkSize - i_size], i_size);

        // Set up ErrlUserDetails instance variables.
        iv_CompId = ERRL_COMP_ID;
        iv_Version = 1;
        iv_SubSection = ERRL_UDT_PRINTK;

    }

};
