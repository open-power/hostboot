/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludprintk.C $                                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
