/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/nvram/import/nvram-format.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <skiboot.h>
#include <nvram.h>

struct chrp_nvram_hdr {
    uint8_t     sig;
    uint8_t     cksum;
    be16        len;
    char        name[12];
};

static struct chrp_nvram_hdr *skiboot_part_hdr;

static uint8_t chrp_nv_cksum(struct chrp_nvram_hdr *hdr)
{
    struct chrp_nvram_hdr h_copy = *hdr;
    uint8_t b_data, i_sum, c_sum;
    uint8_t *p = (uint8_t *)&h_copy;
    unsigned int nbytes = sizeof(h_copy);

    h_copy.cksum = 0;
    for (c_sum = 0; nbytes; nbytes--) {
        b_data = *(p++);
        i_sum = c_sum + b_data;
        if (i_sum < c_sum)
            i_sum++;
        c_sum = i_sum;
    }
    return c_sum;
}

#define NVRAM_SIG_FW_PRIV   0x51
#define NVRAM_SIG_SYSTEM    0x70
#define NVRAM_NAME_COMMON   "common"
#define NVRAM_NAME_FW_PRIV  "ibm,skiboot"
#define NVRAM_SIZE_FW_PRIV  0x1000

static const char *find_next_key(const char *start, const char *end)
{
    /*
     * Unused parts of the partition are set to NUL. If we hit two
     * NULs in a row then we assume that we have hit the end of the
     * partition.
     */
    if (*start == 0)
        return NULL;

    while (start < end) {
        if (*start == 0)
            return start + 1;

        start++;
    }

    return NULL;
}

/*
 * Check that the nvram partition layout is sane and that it
 * contains our required partitions. If not, we re-format the
 * lot of it
 */
int nvram_check(void *nvram_image, const uint32_t nvram_size)
{
    unsigned int offset = 0;
    bool found_common = false;

    skiboot_part_hdr = NULL;

    while (offset + sizeof(struct chrp_nvram_hdr) < nvram_size) {
#ifdef __HOSTBOOT_MODULE
        struct chrp_nvram_hdr *h = reinterpret_cast<chrp_nvram_hdr*>(
                                   reinterpret_cast<uint8_t*>(nvram_image)
                                   + offset);
#else
        struct chrp_nvram_hdr *h = nvram_image + offset;
#endif

        if (chrp_nv_cksum(h) != h->cksum) {
            prerror("NVRAM: Partition at offset 0x%x"
                " has bad checksum: 0x%02x vs 0x%02x\n",
                offset, h->cksum, chrp_nv_cksum(h));
            goto failed;
        }
        if (be16_to_cpu(h->len) < 1) {
            prerror("NVRAM: Partition at offset 0x%x"
                " has incorrect 0 length\n", offset);
            goto failed;
        }

        if (h->sig == NVRAM_SIG_SYSTEM &&
            strcmp(h->name, NVRAM_NAME_COMMON) == 0)
            found_common = true;

        if (h->sig == NVRAM_SIG_FW_PRIV &&
            strcmp(h->name, NVRAM_NAME_FW_PRIV) == 0)
            skiboot_part_hdr = h;

        offset += be16_to_cpu(h->len) << 4;
        if (offset > nvram_size) {
            prerror("NVRAM: Partition at offset 0x%x"
                " extends beyond end of nvram !\n", offset);
            goto failed;
        }
    }
    if (!found_common) {
        prlog_once(PR_ERR, "NVRAM: Common partition not found !\n");
        goto failed;
    }

    if (!skiboot_part_hdr) {
        prlog_once(PR_ERR, "NVRAM: Skiboot private partition not found !\n");
        goto failed;
    } else {
        /*
         * The OF NVRAM format requires config strings to be NUL
         * terminated and unused memory to be set to zero. Well behaved
         * software should ensure this is done for us, but we should
         * always check.
         */
        const char *last_byte = (const char *) skiboot_part_hdr +
            be16_to_cpu(skiboot_part_hdr->len) * 16 - 1;

        if (*last_byte != 0) {
            prerror("NVRAM: Skiboot private partition is not NUL terminated");
            goto failed;
        }
    }

    prlog(PR_INFO, "NVRAM: Layout appears sane\n");
    assert(skiboot_part_hdr);
    return 0;
 failed:
    return -1;
}

/*
 * nvram_query() - Searches skiboot NVRAM partition for a key=value pair.
 *
 * Returns a pointer to a NUL terminated string that contains the value
 * associated with the given key.
 */
const char *nvram_query(const char *key)
{
    const char *part_end, *start;
    int key_len = strlen(key);

    assert(key);

    if (!nvram_has_loaded()) {
        prlog(PR_DEBUG,
            "NVRAM: Query for '%s' must wait for NVRAM to load\n",
            key);
        if (!nvram_wait_for_load()) {
            prlog(PR_CRIT, "NVRAM: Failed to load\n");
            return NULL;
        }
    }

    /*
     * The running OS can modify the NVRAM as it pleases so we need to be
     * a little paranoid and check that it's ok before we try parse it.
     *
     * NB: nvram_validate() can update skiboot_part_hdr
     */
    if (!nvram_validate())
        return NULL;

    assert(skiboot_part_hdr);

    part_end = (const char *) skiboot_part_hdr
        + be16_to_cpu(skiboot_part_hdr->len) * 16 - 1;

    start = (const char *) skiboot_part_hdr
        + sizeof(*skiboot_part_hdr);

    if (!key_len) {
        prlog(PR_WARNING, "NVRAM: search key is empty!\n");
        return NULL;
    }

    if (key_len > 32)
        prlog(PR_WARNING, "NVRAM: search key '%s' is longer than 32 chars\n", key);

    while (start) {
        int remaining = part_end - start;

        prlog(PR_TRACE, "NVRAM: '%s' (%lu)\n",
            start, strlen(start));

        if (key_len + 1 > remaining)
            return NULL;

        if (!strncmp(key, start, key_len) && start[key_len] == '=') {
            const char *value = &start[key_len + 1];

            prlog(PR_DEBUG, "NVRAM: Searched for '%s' found '%s'\n",
                key, value);

            return value;
        }

        start = find_next_key(start, part_end);
    }

    prlog(PR_DEBUG, "NVRAM: '%s' not found\n", key);

    return NULL;
}
