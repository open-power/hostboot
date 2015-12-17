/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bootloader.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <stdint.h>
#include <bootloader/bootloader.H>
#include <util/singleton.H>
#include <kernel/cpu.H>

#include <kernel/intmsghandler.H> // @TODO RTC:133821 might not be needed long-term

#include <usr/pnor/ecc.H>

#include <stdlib.h>

extern uint64_t kernel_other_thread_spinlock;
extern uint32_t data_sandbox[16]; // @TODO RTC:133821 temporary bringup

namespace Bootloader{
    extern "C"
    int main()
    {
        // cppBootstrap(); @TODO RTC:133821 might not be needed long-term
        // cv_blScratchSpace = ??? @TODO RTC:133821

        // @TODO RTC:134064 Get location of HB base code in PNOR from TOC

        // @TODO RTC:133821 Copy HB base code from PNOR to 0x200000

        // Remove ECC from HB base code at 0x200000 and store result at 0x300000
        PNOR::ECC::eccStatus rc = PNOR::ECC::CLEAN;
//        PNOR::ECC::removeECC(reinterpret_cast<uint8_t*>(0x200000),
//                             reinterpret_cast<uint8_t*>(0x300000),
//                             0x100000); // @TODO RTC:133821 determine size

        if (rc != PNOR::ECC::UNCORRECTABLE)
        {
//        memcpy(reinterpret_cast<void*>(0x300000),
//               reinterpret_cast<void*>(0),
//               0x100000); // @TODO RTC:133821 determine size // replace with asm cache inhibited instructions
        }

        // Ready to let the other CPUs go. @TODO RTC:133821 actually need to start relocated HB base code
        lwsync();
        kernel_other_thread_spinlock = 1;

        data_sandbox[8] = 0x12345678; // @TODO RTC:133821 temporary bringup

        MAGIC_INSTRUCTION(MAGIC_BREAK); // @TODO RTC:133821 temporary bringup

        while(1); // @TODO
        task_end_stub(); // @TODO
        return 0;
    }

    void handleMMIO(uint64_t i_srcAddr,
                    uint64_t i_destAddr,
                    uint32_t i_size,
                    MMIOLoadStoreSizes i_ld_st_size)
    {
        // @TODO RTC:133821
    }
} // end namespace Bootloader

