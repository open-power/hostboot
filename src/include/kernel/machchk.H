/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/machchk.H $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef __KERNEL_MACHCHK_H
#define __KERNEL_MACHCHK_H

#include <stdint.h>
#include <kernel/task.H>

namespace Kernel
{
    namespace MachineCheck
    {
        /** Handles memory UE machine checks.
         *
         *  @param[in] t - Task which took the machine check.
         *  @return bool - True if MC successfully handled, false otherwise.
         */
        bool handleLoadUE(task_t* t);

        /** Handle SLB parity and multi-hit error machine checks.
         *
         *  @param[in] t - Task which took the machine check.
         *  @return bool - True if MC successfully handled, false otherwise.
         */
        bool handleSLB(task_t* t);
    }
}

#endif
