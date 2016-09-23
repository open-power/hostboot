/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilmbox_scratch.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/**
 * @file utilmem.C
 *
 * @brief   Stream manipulation
 *
 * Used for creating and manipulating streams
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <limits.h>
#include <util/util_reasoncodes.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <sys/task.h>
#include <sys/misc.h>
#include <util/utilmbox_scratch.H>

#include "utilbase.H"

using namespace ERRORLOG;

namespace Util
{

    // ----------------------------------------------
    // Globals
    // ----------------------------------------------
    mutex_t g_mutex = MUTEX_INITIALIZER;


    uint32_t readScratchReg(uint64_t i_addr)
    {
        size_t l_size = sizeof(uint64_t);
        uint64_t l_value = 0;

        errlHndl_t l_errl =
          deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                     &l_value, l_size,
                     DEVICE_SCOM_ADDRESS(i_addr));

        if (l_errl)
        {
            errlCommit(l_errl, UTIL_COMP_ID);
        }

        return static_cast<uint32_t>(l_value >> 32);
    }

    void writeScratchReg(uint64_t i_addr, uint32_t i_data)
    {
        size_t l_size = sizeof(uint64_t);
        uint64_t l_value = static_cast<uint64_t>(i_data);
        l_value <<= 32; //data is in top half of scom reg

        errlHndl_t l_errl =
          deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                     &i_data, l_size,
                     DEVICE_SCOM_ADDRESS(i_addr));

        if (l_errl)
        {
            errlCommit(l_errl, UTIL_COMP_ID);
        }
    }

    void writeDebugCommRegs(uint8_t i_usage, uint32_t i_addr, uint32_t i_size)
    {
        //convert input into uint64_t for scom write
        uint64_t l_hrmorVal  =   cpu_spr_value(CPU_SPR_HRMOR);
        uint64_t l_bufAddr = i_addr | l_hrmorVal; //OR in HRMOR for RA
        uint64_t l_bufSize = (i_size & MSG_DATA_SIZE_MASK) |
                             (i_usage << MSG_USAGE_SHIFT);

        //Lock to prevent concurrent access
        mutex_lock(&g_mutex);


        //Write out the data to be xferred to debug tool
        writeScratchReg(INITSERVICE::SPLESS::MBOX_SCRATCH_REG1, l_bufAddr);
        writeScratchReg(INITSERVICE::SPLESS::MBOX_SCRATCH_REG2, l_bufSize);

        //wait paitently until tool has gotten the data
        //tool will zero addr when ready to continue
        while(0 != readScratchReg(INITSERVICE::SPLESS::MBOX_SCRATCH_REG1))
        {
            task_yield();
        }

        //Release lock
        mutex_unlock(&g_mutex);
    }

};
