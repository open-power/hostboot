/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/header.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#include <secureboot/header.H>
#include <sys/mm.h>
#include <sys/mmio.h>
#include <kernel/console.H>
#include <errno.h>

namespace SECUREBOOT
{
    Header& baseHeader()
    {
        return Singleton<Header>::instance();
    }

    void Header::loadSecurely()
    {
        // Fatal code bug if already loaded
        assert(iv_data == NULL);

        // Calculate original address (HRMOR-4k) of the secureboot header.
        const void* addr = NULL;
        (void)_calcSecureLoadAddr(addr);
        addr = reinterpret_cast<const void*>(
            reinterpret_cast<uint64_t>(addr)-PAGESIZE);

        // Map in the header.
        void* origHeader = mm_block_map(const_cast<void*>(addr),
                                        PAGESIZE);

        // Fatal code bug if virtual address is NULL
        assert(origHeader != NULL);

        // Copy header to a save area.
        iv_data = calloc(1,PAGESIZE);
        memcpy(iv_data, origHeader, PAGESIZE);

        // Unmap the header.
        int rc = mm_block_unmap(origHeader);

        // Fatal code bug on unmap failure
        assert(rc == 0);

        return;
    }

    void Header::setNonSecurely(
        const void* i_pHeader)
    {
        // Fatal code bug if already loaded
        assert(iv_data == NULL);
        // Fatal code bug if called with NULL pointer
        assert(i_pHeader != NULL);

        iv_data = calloc(1,PAGESIZE);
        memcpy(iv_data,i_pHeader,PAGE_SIZE);
    }

    void Header::getHeader(
        const void*& o_pHeader) const
    {
        // Fatal code bug if queried before loaded
        assert(iv_data!=NULL);
        o_pHeader = iv_data;
    }

    void Header::_calcSecureLoadAddr(
        const void*& o_pCode) const
    {
        // Determine the secure address where the HBB image was loaded by SBE.
        // Regardless of whether security is enabled or not, HBB always ends up
        // at the secure load address (which corresponds to the HRMOR).
        //
        // Zero is purposefully not mapped into the VMM tables, so we
        // can't use that for the virtual-to-real translation.  Since
        // this object is in the base (HBB) image, PA = HRMOR | EA, so we can
        // use PA - EA to find the HRMOR.
        const void* hrmor = reinterpret_cast<const void*>(
            mm_virt_to_phys(
                const_cast<SECUREBOOT::Header*>(this)) -
                    reinterpret_cast<uint64_t>(this));

        // HRMOR lookup should never fail
        assert(   reinterpret_cast<uint64_t>(hrmor)
               != static_cast<uint64_t>(-EFAULT));

        o_pCode = hrmor;
    }
}
