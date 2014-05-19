/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/header.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include "header.H"
#include <sys/mm.h>
#include <sys/mmio.h>
#include <kernel/console.H>

namespace SECUREBOOT
{
    void Header::loadBaseHeader()
    {
        // Calculate original address of the secureboot header.
        //      Zero is purposefully not mapped into the VMM tables, so we
        //      can't use that for the virtual-to-real translation.  Since
        //      this object is in the base image, EA = HRMOR | PA, so we can
        //      use PA - EA to find the HRMOR.
        uint64_t addr = mm_virt_to_phys(this) -
                            reinterpret_cast<uint64_t>(this);
        addr -= PAGESIZE;

        // Map in the header.
        void* origHeader = mm_block_map(reinterpret_cast<void*>(addr),
                                        PAGESIZE);

        // Copy header to a save area.
        //     In the future we might want to just extract pieces of the
        //     header.  The header is important when we start updating
        //     the TPM PCRs.
        iv_data = malloc(PAGESIZE);
        memcpy(iv_data, origHeader, PAGESIZE);

        // Unmap the header.
        mm_block_unmap(origHeader);

        return;
    }
}
