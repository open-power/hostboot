/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */
/* Force elision of assert() */
#ifndef NDEBUG
#define NDEBUG
#endif

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "compiler.h"

/* NOLINTNEXTLINE(bugprone-suspicious-include) */
#include "dsp/bios_table.c"

/* Satisfy the symbol needs of bios_table.c */
uint32_t crc32(const void* data LIBPLDM_CC_UNUSED,
               size_t size LIBPLDM_CC_UNUSED)
{
    return 0;
}

/* This is the non-death version of TEST(Iterator, DeathTest) */
int main(void)
{
    struct pldm_bios_attr_table_entry entries[2] = {0};
    struct pldm_bios_table_iter* iter;
    int result;

    static_assert(2 * sizeof(entries[0]) == sizeof(entries), "");

    entries[0].attr_type = PLDM_BIOS_PASSWORD;
    entries[1].attr_type = PLDM_BIOS_STRING_READ_ONLY;

    iter = pldm_bios_table_iter_create(entries, sizeof(entries),
                                       PLDM_BIOS_ATTR_TABLE);

    /*
     * We expect the test configuration to claim the iterator has reached the
     * end because the there's no entry length descriptor for the
     * PLDM_BIOS_PASSWORD entry type. By the attr_able_entry_length()
     * implementation this would normally trigger an assert() to uphold that the
     * necessary pointers are not NULL. However, we've defined NDEBUG above and
     * so the assert() is elided. That should force us down the path of the
     * early-exit, which should in-turn yield a `true` result from
     * pldm_bios_table_iter_is_end() to prevent further attempts to access
     * invalid objects.
     */
    result = pldm_bios_table_iter_is_end(iter) ? EXIT_SUCCESS : EXIT_FAILURE;

    pldm_bios_table_iter_free(iter);

    exit(result);

    return 0;
}
