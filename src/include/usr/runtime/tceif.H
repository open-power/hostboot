/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/tceif.H $                             */
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
#ifndef __TCEIF_H
#define __TCEIF_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>


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
