/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/runtime/util_rt.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2022                        */
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

#include <util/utilrsvdmem.H>

/**
 *  @brief Get the address of a reserved hostboot memory region by its label
 *  @param[in] i_label      HBRT_MEM_LABEL_... constant
 *  @param[in] i_instance   instance number
 *  @param[out] o_size      size of returned region in bytes
 *  @return virtual address of region or 0
 *  @platform FSP, OpenPOWER
 **/
uint64_t hb_get_rt_rsvd_mem( Util::hbrt_mem_label_t i_label,
                             uint32_t i_instance,
                             uint64_t & o_size );



