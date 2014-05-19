/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devtree/devtreeif.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
