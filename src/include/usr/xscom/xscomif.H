/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/xscom/xscomif.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#ifndef __XSCOMIF_H
#define __XSCOMIF_H

namespace XSCOM
{

/**
 * @brief Return the value of the XSCOM BAR that the driver is using
 * @return XSCOM BAR physical address
 */
uint64_t get_master_bar( void );

/**
 *  @brief Generate a fully-qualified MMIO address for a physical scom
 *        address, relative to the given processor target
 *  @param[in] i_proc - Processor
 *  @param[in] i_scomAddr - Physical scom address to convert
 *  @return uint64_t - MMIO address
 */
uint64_t generate_mmio_addr( TARGETING::Target* i_proc,
                             uint64_t i_scomAddr );

/**
 *  @brief Read of XSCOM register on remote Node
 *  @param[in] i_node - logical Node Number
 *  @param[in] i_scomAddr - Physical scom address to read
 *  @return uint64_t - Register value
 */
uint64_t readRemoteScom( uint64_t i_node,
                         uint64_t i_scomAddr );

};  // namespace XSCOM

#endif  // end __XSCOMIF_H
