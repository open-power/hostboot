/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devtree/devtreeif.H $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#ifndef __DEVTREE_IF_H
#define __DEVTREE_IF_H

#include <errl/errlentry.H>


namespace DEVTREE
{

    /**
     * @brief Build flattened dev tree for Sapphire
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t build_flatdevtree( void );

    /**
     * @brief Get the address of the flattened dev tree for Sapphire
     *
     * @return uint64_t - Address if valid, else NULL
     */
    uint64_t get_flatdevtree_phys_addr( void );




}; // end namespace DEVTREE

#endif
