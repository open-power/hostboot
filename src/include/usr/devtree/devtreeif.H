/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devtree/devtreeif.H $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
     * @param[in] i_dtAddr - Address to load devtree.  0 will use a default
     *                       data area appropriate for non-HDAT Sapphire.
     * @param[in] i_dtSize - Allowable size for the devtree.
     * @param[in] i_smallTree - Build a small devtree appropriate for inside
     *                          the HDAT area.
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t build_flatdevtree( uint64_t i_dtAddr = 0, size_t i_dtSize = 0,
                                  bool i_smallTree = false);

    /**
     * @brief Get the address of the flattened dev tree for Sapphire
     *
     * @return uint64_t - Address if valid, else NULL
     */
    uint64_t get_flatdevtree_phys_addr( void );




}; // end namespace DEVTREE

#endif
