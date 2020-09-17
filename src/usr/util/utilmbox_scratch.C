/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilmbox_scratch.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <targeting/common/attributes.H>

#include "utilbase.H"

using namespace ERRORLOG;

namespace Util
{

    // ----------------------------------------------
    // Globals
    // ----------------------------------------------
    mutex_t g_mutex = MUTEX_INITIALIZER;

    uint32_t readScratchReg(uint64_t i_addr, TARGETING::Target* const i_target)
    {
        size_t l_size = sizeof(uint64_t);
        uint64_t l_value = 0;

        errlHndl_t l_errl =
          deviceRead(i_target,
                     &l_value, l_size,
                     DEVICE_SCOM_ADDRESS(i_addr));

        if (l_errl)
        {
            errlCommit(l_errl, UTIL_COMP_ID);
        }

        return static_cast<uint32_t>(l_value >> 32);
    }

    void writeScratchReg(uint64_t i_addr, uint32_t i_data,
                         TARGETING::Target* const i_target)
    {
        size_t l_size = sizeof(uint64_t);
        uint64_t l_value = static_cast<uint64_t>(i_data);
        l_value <<= 32; //data is in top half of scom reg

        errlHndl_t l_errl =
          deviceWrite(i_target,
                     &i_data, l_size,
                     DEVICE_SCOM_ADDRESS(i_addr));

        if (l_errl)
        {
            errlCommit(l_errl, UTIL_COMP_ID);
        }
    }

    TARGETING::ATTR_MASTER_MBOX_SCRATCH_typeStdArr readScratchRegs(TARGETING::Target* const i_target)
    {
        using namespace INITSERVICE::SPLESS;

        TARGETING::ATTR_MASTER_MBOX_SCRATCH_typeStdArr l_scratch = { };

        const std::array<uint32_t, l_scratch.size()> l_regs
        {
            MboxScratch1_t::REG_ADDR,
            MboxScratch2_t::REG_ADDR,
            MboxScratch3_t::REG_ADDR,
            MboxScratch4_t::REG_ADDR,
            MboxScratch5_t::REG_ADDR,
            MboxScratch6_t::REG_ADDR,
            MboxScratch7_t::REG_ADDR,
            MboxScratch8_t::REG_ADDR,
            MboxScratch9_t::REG_ADDR,
            MboxScratch10_t::REG_ADDR,
            MboxScratch11_t::REG_ADDR,
            MboxScratch12_t::REG_ADDR,
            MboxScratch13_t::REG_ADDR,
            MboxScratch14_t::REG_ADDR,
            MboxScratch15_t::REG_ADDR,
            MboxScratch16_t::REG_ADDR,
        };

        for (size_t i = 0; i < l_scratch.size(); ++i)
        {
            l_scratch[i] = Util::readScratchReg(l_regs[i], i_target);
        }

        return l_scratch;
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
        writeScratchReg(INITSERVICE::SPLESS::MboxScratch1_t::REG_ADDR, l_bufAddr);
        writeScratchReg(INITSERVICE::SPLESS::MboxScratch2_t::REG_ADDR, l_bufSize);

        //wait paitently until tool has gotten the data
        //tool will zero addr when ready to continue
        while(0 != readScratchReg(INITSERVICE::SPLESS::MboxScratch1_t::REG_ADDR))
        {
            task_yield();
        }

        //Release lock
        mutex_unlock(&g_mutex);
    }

    uint32_t getBootNestFreqMhz()
    {
        uint32_t l_bootNestFreqMhz = 0;;
        INITSERVICE::SPLESS::MboxScratch4_t l_scratch4;
        l_scratch4.data32 = 0;

        TARGETING::Target * l_sys = nullptr;
        (void) TARGETING::targetService().getTopLevelTarget( l_sys );
        assert( l_sys, "getBootNestFreqMhz() system target is NULL");

        // Read what frequency SBE used for initializing the nest clock
        // from the scratch4 register
        //
        // NOTE: We are reading the core boot freq because nest freq = core freq at
        //       boot time (not true during runtime).
        const auto l_scratchRegs = l_sys->getAttrAsStdArr<TARGETING::ATTR_MASTER_MBOX_SCRATCH>();
        l_scratch4.data32 = l_scratchRegs[INITSERVICE::SPLESS::MboxScratch4_t::REG_IDX];
        l_bootNestFreqMhz = l_scratch4.nestBootFreq.coreBootFreqMhz;

        UTIL_FT("getBootNestFreqMhz::The boot frequency was %d MHz",
                l_bootNestFreqMhz);

        return l_bootNestFreqMhz;
    }


};
