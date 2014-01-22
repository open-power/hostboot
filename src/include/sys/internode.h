/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/internode.h $                                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
