/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/tceif.H $                             */
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
#ifndef __TCEIF_H
#define __TCEIF_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>

#define TCE_TRACE_NAME "TCE"

namespace TCE
{
    /**
     * @brief Responsible for initalizing the TCE entries
     *
     * @return errl - Return Error Handle if failed.
     *
     */
    errlHndl_t createTceTable();

    /**
     * @brief Responsible for setting up the Processors to point to the TCE
     *            table
     *
     * @return errl - Return Error Handle if failed.
     *
     */
    errlHndl_t initTceInHdw();

    /**
     * @brief Responsible for allocating TCE Entries
     *
     * @param[in] i_startingAddress - Starting address to TCE
     * @param[in] i_size - Size of the address space
     * @param[out] startingToken - Starting Entry into the table.
     *          (this is an offset into the array based on the
     *           TCE index * PAGESIZE.  Each TCE entry maps to a
     *           pagesize of memory)
     *
     * Note:  Must run createTceTable and InitTceInHdw or allocate will not work
     *
     * @return errl - Return Error Handle if failed.
     *
     */
    errlHndl_t allocateTces(uint64_t startingAddress, uint64_t size, uint64_t&
                            startingToken);

    /**
     * @brief Responsible for deallocating TCE Entries
     *
     * @param[in] i_startingToken - Token indicating the starting entry to
     *                              remove
     * @param[in] i_size - Size of memory space to remove TCE entries
     *                     associated
     *
     * @return errl - Return Error Handle if fatal failure occurred.
     *
     */
    errlHndl_t deallocateTces(uint64_t startingToken, uint64_t size);
};

#endif
