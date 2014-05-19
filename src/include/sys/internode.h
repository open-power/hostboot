/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/internode.h $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#ifndef __INTERNODE_H
#define __INTERNODE_H
// Memory area preserved on MPIPL

#include <vmmconst.h>

enum internode_info_vals_t
{
    MAX_NODES_PER_SYS = 8,
};

enum intr_mpipl_sync_t
{
    INTR_MPIPL_SYNC_CLEAR = 0,
    INTR_MPIPL_UPSTREAM_DISABLED = 1,
    INTR_MPIPL_DRAINED = 2,
};


/**
 * Node information needed across MPIPLs
 */
struct internode_info_t
{
    uint64_t eye_catcher;
    uint64_t version;
    bool  exist[ MAX_NODES_PER_SYS ];       //!< true if HB node exists
    volatile intr_mpipl_sync_t  mpipl_intr_sync;     //!< at sync point
};

#define NODE_INFO_EYE_CATCHER 0x4e4f444544415441ul // "NODEDATA"
#define NODE_INFO_VERSION 1

#define INTERNODE_INFO_SIZE (sizeof(internode_info_t))

#endif
