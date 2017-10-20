/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/util_rt.C $                              */
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
#include <targeting/common/trace.H>
#include <trace/interface.H>
#include <runtime/interface.h>
#include <util/utilrsvdmem.H>
#include <util/runtime/util_rt.H>


/**
 *  @brief Get the address of a reserved hostboot memory region by its label
 *  @param[in] i_label      HBRT_MEM_LABEL_ constant
 *  @param[in] i_instance   instance number
 *  @param[out] o_size      size of returned region in bytes
 *  @return virtual address of region or 0
 *  @platform FSP, OpenPOWER
 **/
uint64_t hb_get_rt_rsvd_mem(Util::hbrt_mem_label_t i_label,
                            uint32_t i_instance,
                            uint64_t & o_size)
{
    uint64_t l_label_data_addr = 0;
    o_size = 0;

    TRACFCOMP(TARGETING::g_trac_targeting,
        ENTER_MRK"hb_get_rt_rsvd_mem(0x%llX, %d)", i_label, i_instance);

    switch(i_label)
    {
        case Util::HBRT_MEM_LABEL_VPD:
        case Util::HBRT_MEM_LABEL_ATTR:
        case Util::HBRT_MEM_LABEL_ATTROVER:
        case Util::HBRT_MEM_LABEL_PADDING:
        case Util::HBRT_MEM_LABEL_HYPCOMM:
            if( (g_hostInterfaces != NULL) &&
                (g_hostInterfaces->get_reserved_mem) )
            {
                uint64_t hb_data_addr =
                    g_hostInterfaces->get_reserved_mem(HBRT_RSVD_MEM__DATA,
                                                       i_instance);
                if (0 != hb_data_addr)
                {
                    Util::hbrtTableOfContents_t * toc_ptr =
                        reinterpret_cast<Util::hbrtTableOfContents_t *>(
                        hb_data_addr);
                    l_label_data_addr = Util::hb_find_rsvd_mem_label(i_label,
                                                                     toc_ptr,
                                                                     o_size);
                }
                else
                {
                    // unable to find HBRT_RSVD_MEM__DATA section
                    TRACFCOMP(TARGETING::g_trac_targeting, "hb_get_rt_rsvd_mem: Unable to find HBRT_RSVD_MEM__DATA section");
                }
            }
            else
            {
                // g_hostInterfaces is either NULL or
                // get_reserved_mem function isn't defined
                TRACFCOMP(TARGETING::g_trac_targeting, "hb_get_rt_rsvd_mem: g_hostInterfaces->get_reserved_mem is invalid");
            }
            break;
        default:
            // unknown label?
            TRACFCOMP(TARGETING::g_trac_targeting, "hb_get_rt_rsvd_mem: unknown label 0x%.16llX", i_label);
            break;
    }

    TRACFCOMP(TARGETING::g_trac_targeting,
            EXIT_MRK"hb_get_rt_rsvd_mem(0x%X, %d, %ld) -> 0x%.16llX",
            i_label, i_instance, o_size,l_label_data_addr);

    return l_label_data_addr;
}
