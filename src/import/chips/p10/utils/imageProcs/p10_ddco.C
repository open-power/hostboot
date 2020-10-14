/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ddco.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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

#ifdef WIN32
    #include "endian.h"
#else
    #include <endian.h>
#endif

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "p10_ddco.H"

int p9_dd_validate(struct p9_dd_cont* i_cont)
{
    if (!i_cont)
    {
        return DDCO_DDCO_DOES_NOT_EXIST;
    }

    if (be32toh(i_cont->iv_magic) != DDCO_MAGIC)
    {
        return DDCO_FAILURE_MAGIC_NOT_FOUND;
    }

    // TBD: We can do more checking here, if the container is populated

    return DDCO_SUCCESS;
}

// iterates through all dd level blocks
struct p9_dd_block* p9_dd_next(struct p9_dd_iter* io_iter)
{
    struct p9_dd_block* block;

    if (!io_iter ||
        !io_iter->iv_cont ||
        io_iter->iv_idx >= io_iter->iv_cont->iv_num)
    {
        return NULL;
    }

    block = &(io_iter->iv_cont->iv_blocks)[io_iter->iv_idx];
    io_iter->iv_idx++;

    return block;
}

uint8_t* p9_dd_addr(struct p9_dd_cont* i_cont, uint32_t i_offset)
{
    return (uint8_t*)i_cont + i_offset;
}

void p9_dd_betoh(struct p9_dd_block* i_block_be,
                 struct p9_dd_block* io_block_he)
{
    io_block_he->iv_offset = be32toh(i_block_be->iv_offset);
    io_block_he->iv_size   = be32toh(i_block_be->iv_size);
    io_block_he->iv_dd     = i_block_be->iv_dd;
}

// returns address of dd level content (without meta data)
int p9_dd_get(uint8_t* i_cont, uint8_t i_dd, uint8_t** o_buf, uint32_t* o_size)
{
    struct p9_dd_cont*  cont = (struct p9_dd_cont*)i_cont;
    struct p9_dd_iter   iter = {cont, 0};
    struct p9_dd_block* block;
    struct p9_dd_block  block_he;
    int rc;

    rc = p9_dd_validate(cont);

    if (rc != DDCO_SUCCESS)
    {
        return rc;
    }

    while ((block = p9_dd_next(&iter)))
    {
        if (block->iv_dd == i_dd)
        {
            p9_dd_betoh(block, &block_he);
            *o_buf  = p9_dd_addr(cont, block_he.iv_offset);
            *o_size = block_he.iv_size;
            return DDCO_SUCCESS;
        }
    }

    return DDCO_DDLEVEL_NOT_FOUND;
}

uint32_t p9_dd_size_meta(struct p9_dd_cont* i_cont)
{
    return (i_cont ?
            (sizeof(struct p9_dd_cont) +
             sizeof(struct p9_dd_block) * i_cont->iv_num) :
            0);
}

// assumes only API (p9_dd_add()) used to create container,
// that is, last block header points to block with biggest offset
uint32_t p9_dd_size(struct p9_dd_cont* i_cont)
{
    struct p9_dd_block* last;

    if (!i_cont)
    {
        return 0;
    }

    if (!i_cont->iv_num)
    {
        return p9_dd_size_meta(i_cont);
    }

    last = &(i_cont->iv_blocks)[i_cont->iv_num - 1];

    return be32toh(last->iv_offset) + be32toh(last->iv_size);
}

struct p9_dd_cont* p9_dd_create(void)
{
    struct p9_dd_cont* cont;

    cont = (struct p9_dd_cont*)malloc(sizeof(struct p9_dd_cont));

    if (!cont)
    {
        return cont;
    }

    cont->iv_magic = htobe32(DDCO_MAGIC);
    cont->iv_num   = 0;
    cont->iv_reserved[0] = 0;
    cont->iv_reserved[1] = 0;
    cont->iv_reserved[2] = 0;

    return cont;
}

// enlarges (reallocates) container and copies dd level block into container
int p9_dd_add(
    uint8_t** io_cont, uint32_t* o_cont_size, uint8_t i_dd,
    uint8_t* i_buf, uint32_t i_buf_size)
{
    struct p9_dd_cont*  cont = (struct p9_dd_cont*)*io_cont;

    uint8_t*            dupl_buf;
    uint32_t            dupl_size;

    uint32_t            enlarged;

    int                 rc;

    uint8_t*            others_addr_new;
    uint8_t*            others_addr_old;
    uint32_t            others_size;
    struct p9_dd_block* others_block;

    uint8_t*            this_addr;
    uint32_t            this_offs;
    struct p9_dd_block* this_block;

    struct p9_dd_iter   iter = {NULL, 0};

    // handle duplicates and initial setup of empty container
    rc = p9_dd_get(*io_cont, i_dd, &dupl_buf, &dupl_size);

    switch (rc)
    {
        case DDCO_DDLEVEL_NOT_FOUND :
            break;

        case DDCO_DDCO_DOES_NOT_EXIST :
            cont = p9_dd_create();

            if (!cont)
            {
                return DDCO_FAILURE_NOMEM;
            }

            break;

        case DDCO_SUCCESS :
            return DDCO_DUPLICATE_DDLEVEL;

        default :
            return rc;
    }

    // size of enlarged container
    enlarged = p9_dd_size(cont) + sizeof(struct p9_dd_block) + i_buf_size;

    // re-allocate to enlarge container (content is retained and consistent)
    cont = (struct p9_dd_cont*)realloc(cont, enlarged);

    if (!cont)
    {
        return DDCO_FAILURE_NOMEM;
    }

    // offsets and size of existing bufs
    others_addr_old = p9_dd_addr(cont, p9_dd_size_meta(cont));
    others_addr_new = others_addr_old + sizeof(struct p9_dd_block);
    others_size     = p9_dd_size(cont) - p9_dd_size_meta(cont);

    // meta data, offset and address of new buf
    this_block = (struct p9_dd_block*)others_addr_old;
    this_offs  = p9_dd_size(cont) + sizeof(struct p9_dd_block);
    this_addr  = p9_dd_addr(cont, this_offs);

    // fix offsets of existing bufs
    iter.iv_cont = cont;

    while ((others_block = p9_dd_next(&iter)))
    {
        others_block->iv_offset =
            htobe32(be32toh(others_block->iv_offset) +
                    sizeof(struct p9_dd_block));
    }

    // move existing bufs
    memmove(others_addr_new, others_addr_old, others_size);

    // copy new buf into container
    memcpy(this_addr, i_buf, i_buf_size);

    // fill in meta data for new buf
    memset(this_block, 0, sizeof(struct p9_dd_block));
    this_block->iv_offset = htobe32(this_offs);
    this_block->iv_size   = htobe32(i_buf_size);
    this_block->iv_dd     = i_dd;
    this_block->iv_reserved[0] = 0;
    this_block->iv_reserved[1] = 0;
    this_block->iv_reserved[2] = 0;

    // increase number off DD level blocks in container
    (cont)->iv_num++;

    *io_cont = (uint8_t*)cont;
    *o_cont_size = enlarged;

    return DDCO_SUCCESS;
}
