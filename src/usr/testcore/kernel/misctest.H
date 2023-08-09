/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/kernel/misctest.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
#ifndef __TESTCORE_KERNEL_MISC_H
#define __TESTCORE_KERNEL_MISC_H

#include <sys/misc.h>
#include <kernel/cpumgr.H>
#include <targeting/common/targetservice.H>
#include <secureboot/smf_utils.H>
#include <util/misc.H>

/** @file misctest.H
 *
 *  Testcases for the system calls in sys/misc.h
 */

class MiscTest : public CxxTest::TestSuite
{
    public:

        /** Tests for cpu_spr_value() */
        void testCpuSprValue()
        {
            const auto smfEnabled = SECUREBOOT::SMF::isSmfEnabled();
            uint64_t smfMsrBit = smfEnabled ? MSR_SMF_MASK : 0;

            const uint64_t msrActual = cpu_spr_value(CPU_SPR_MSR);
            if ((WAKEUP_MSR_VALUE | smfMsrBit) != msrActual)
            {
                TS_FAIL("With SMF %s, expected MSR value of 0x%016llX but got "
                    "0x%016llX",
                    smfEnabled ? "enabled" : "disabled",
                    WAKEUP_MSR_VALUE | smfMsrBit,
                    msrActual);
            }

            if (WAKEUP_LPCR_VALUE != cpu_spr_value(CPU_SPR_LPCR))
            {
                TS_FAIL("LPCR value is not as expected.");
            }
        }

        /** Tests for mm_virt_to_phys() */
        void testVirtToPhys()
        {
            uint64_t phys = 0;
            uint64_t hrmor = cpu_spr_value(CPU_SPR_HRMOR);

            // Verify a regular heap address
            uint8_t* heap = (uint8_t*)contiguous_malloc(1);
            *heap = 0xAB; //to make sure it gets paged in
            phys = mm_virt_to_phys( heap );
            if( phys != (reinterpret_cast<uint64_t>(heap)|hrmor) )
            {
                TS_FAIL("Unexpected Physical Address for Heap.");
                TS_TRACE( "heap> virt=%p, phys=%lX", (void*)heap, phys );
            }
            free(heap);

            // Verify a regular stack address
            phys = mm_virt_to_phys( (void*)&phys );
            if( phys < hrmor )
            {
                TS_FAIL("Unexpected Physical Address for Stack.");
                TS_TRACE( "stack> virt=%p, phys=%lX", &phys, phys );
            }

            // Verify a MMIO (XSCOM)
            TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
            epath.addLast(TARGETING::TYPE_SYS,0);
            epath.addLast(TARGETING::TYPE_NODE,0);
            epath.addLast(TARGETING::TYPE_PROC,1);
            TARGETING::Target* l_targ =
              TARGETING::targetService().toTarget(epath);
            if(l_targ != NULL)
            {
                uint64_t xscom_virt =
                  l_targ->getAttr<TARGETING::ATTR_XSCOM_VIRTUAL_ADDR>();
                uint64_t xscom_phys =
                  l_targ->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();
                phys = mm_virt_to_phys( (void*)xscom_virt );
                if( (phys != xscom_phys)
                    && (xscom_virt != 0) ) //never got set
                {
                    TS_FAIL("Unexpected Physical Address for MMIO.");
                    TS_INFO( "mmio1> virt=%lX, phys=%lX, expected=%lX\n",
                             xscom_virt, phys, xscom_phys );
                }
            }
        }
};

#endif
