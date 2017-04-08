/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_dd_container.h $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#ifndef _P9_DD_CONTAINER_H_
#define _P9_DD_CONTAINER_H_

#include <stdint.h>

#define P9_DD_CONTAINER_MAGIC 0x4444434F // "DDCO"

#define P9_DD_SUCCESS                0
#define P9_DD_FAILURE_BROKEN         1
#define P9_DD_FAILURE_NOMEM          2
#define P9_DD_FAILURE_NOT_FOUND      3
#define P9_DD_FAILURE_DOES_NOT_EXIST 4
#define P9_DD_FAILURE_DUPLICATE      5

// header for each dd level block inside container
struct p9_dd_block
{
    uint32_t iv_offset;
    uint32_t iv_size;
    uint8_t  iv_dd;
    uint8_t  iv_reserved[3];
};

// container header
struct p9_dd_cont
{
    uint32_t           iv_magic;
    uint8_t            iv_num;
    uint8_t            iv_reserved[3];
    struct p9_dd_block iv_blocks[0];
};

// iterator that can be used to iterate through all dd level blocks
struct p9_dd_iter
{
    struct p9_dd_cont* iv_cont;
    uint8_t            iv_idx;
};

// initialisation of iterator
#define P9_DD_ITER_INIT(dd_cont) { .iv_cont = (dd_cont), .iv_idx  = 0 }

#ifdef __cplusplus
extern "C" {
#endif

// validates container
int p9_dd_validate(struct p9_dd_cont* i_cont);

void p9_dd_betoh(struct p9_dd_block* i_block_be,
                 struct p9_dd_block* io_block_he);

// iterates through all dd level blocks
struct p9_dd_block* p9_dd_next(struct p9_dd_iter* io_iter);

// returns address of dd level content (without meta data)
int p9_dd_get(
    uint8_t* i_cont, uint8_t i_dd, uint8_t** o_buf, uint32_t* o_size);

// enlarges (reallocates) container and copies dd level block into container
int p9_dd_add(
    uint8_t** io_cont, uint32_t* o_cont_size, uint8_t i_dd,
    uint8_t* i_buf, uint32_t i_buf_size);

#ifdef __cplusplus
}
#endif

#endif
