/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/header.C $                            */
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
