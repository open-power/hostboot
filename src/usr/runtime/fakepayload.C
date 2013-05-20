/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/fakepayload.C $                               */
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
#include "fakepayload.H"
#include <string.h>
#include <sys/mm.h>
#include <util/align.H>
#include <targeting/common/commontargeting.H>


namespace RUNTIME
{

void FakePayload::payload()
{
    MAGIC_INSTRUCTION(MAGIC_FAKEPAYLOAD_ENTER); // instr 1

    nap();                                      // instr 2
    // Should never wake from nap, but just in case...
    loop:
        goto loop;                              // instr 3
}

const size_t FakePayload::size = 3 * sizeof(uint32_t); // 3 instructions.
const size_t FakePayload::safeClearArea = 1 * MEGABYTE;

void FakePayload::load()
{
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);

    // Find payload base address and offset.
    uint64_t base = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>() * MEGABYTE;
    uint64_t entry = sys->getAttr<TARGETING::ATTR_PAYLOAD_ENTRY>();

    // Skip loading the payload if the address is 0.
    if (0 == base)
    {
        return;
    }

    // Verify payload size.
    assert(ALIGN_PAGE(entry + size) < safeClearArea);

    // Map in the payload area.
    void* memArea = mm_block_map(reinterpret_cast<void*>(base), safeClearArea);

    // Clear out anything the FSP might have left around (for security).
    memset(memArea, '\0', safeClearArea);

    // Copy over the fake payload code.
    uint8_t* dest = reinterpret_cast<uint8_t*>(memArea) + entry;
    union fn_ptr
    {
        void (*opd)();
        uint64_t** data;
    };
    fn_ptr payload_code = { payload };
    memcpy(dest, *payload_code.data, size);

    // Invalidate the icache since this is instructions.
    mm_icache_invalidate(memArea, ALIGN_8(safeClearArea) / sizeof(uint64_t));

    // Unmap the payload area.
    assert(0 == mm_block_unmap(memArea));

}

}
