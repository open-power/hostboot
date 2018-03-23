/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ibscom/ibscom_multicast.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
#include <ibscom/ibscomif.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <scom/runtime/rt_scomif.H>

// Trace definition
extern trace_desc_t* g_trac_ibscom;

namespace IBSCOM
{

/**
 * @brief Multicast this ibscom address
 *
 * @param[in]    i_opType         read/write
 * @param[in]    i_target         target membuf
 * @param[inout] io_buffer        return data
 * @param[inout] io_buflen        return data length
 * @param[in]    i_addr           inband scom address
 * @param[out]   o_didWorkaround  return indicator
 *
 * @return     error log on fail
 */
errlHndl_t doIBScomMulticast( DeviceFW::OperationType i_opType,
                              TARGETING::Target* i_target,
                              void* io_buffer,
                              size_t& io_buflen,
                              uint64_t i_addr,
                              bool& o_didWorkaround )
{
    errlHndl_t l_err = nullptr;
    uint64_t* l_summaryReg = reinterpret_cast<uint64_t*>(io_buffer);

    // Chiplet byte info masks
    constexpr uint64_t IS_MULTICAST         = 0x40000000;
    constexpr uint64_t MULTICAST_GROUP      = 0x07000000;
    constexpr uint64_t MULTICAST_OP         = 0x38000000;
    constexpr uint64_t MULTICAST_OP_BITWISE = 0x10000000;
    constexpr uint64_t CHIPLET_BYTE         = 0xFF000000;

    // Valid groups
    constexpr uint64_t GROUP_0 = 0x00000000;
    constexpr uint64_t GROUP_3 = 0x03000000;

    uint64_t l_group = MULTICAST_GROUP & i_addr;

    // Only perform this workaround for:
    //  - reads
    //  - multicast registers
    //  - multicast read option 'bit-wise'
    //  - multicast group 0 or 3
    if( !((DeviceFW::READ == i_opType)
          && ((IS_MULTICAST & i_addr) == IS_MULTICAST)
          && ((MULTICAST_OP & i_addr) == MULTICAST_OP_BITWISE)
          && ((GROUP_0 == l_group) || (GROUP_3 == l_group)) ) )
    {
        o_didWorkaround = false;
        return nullptr;
    }

    TRACFCOMP( g_trac_ibscom, "doIBScomMulticast on %.8X for %.8X", TARGETING::get_huid(i_target), i_addr );

    // Chiplet numbers
    constexpr uint64_t CHIPLET_PRV = 1;
    constexpr uint64_t CHIPLET_NST = 2;
    constexpr uint64_t CHIPLET_MEM = 3;

    // Start chiplet depends on group, end chiplet is always MEM
    //   - Multicast group 0: PRV NST MEM, chiplets 1 2 3
    //   - Multicast group 3: NST MEM, chiplets 2 3
    uint64_t l_start_chplt = 0;
    uint64_t l_end_chplt = CHIPLET_MEM;
    if( GROUP_0 == l_group )
    {
        l_start_chplt = CHIPLET_PRV;
    }
    else // Must be group 3
    {
        l_start_chplt = CHIPLET_NST;
    }

    // Do the ibscom for each chiplet and return the combined value
    for( uint64_t l_chplt = l_start_chplt; l_chplt <= l_end_chplt; l_chplt++ )
    {
        // Remove the chiplet byte info from the address
        uint64_t l_addr = (i_addr & ~CHIPLET_BYTE);
        uint64_t l_data = 0;

        // Add the chiplet to the address
        l_addr |= (l_chplt << 24);
        io_buflen = sizeof(uint64_t);

#ifdef __HOSTBOOT_RUNTIME
        l_err = SCOM::sendScomToHyp(i_opType, i_target, l_addr, &l_data);
#else
        l_err = doIBScom(i_opType,
                         i_target,
                         &l_data,
                         io_buflen,
                         l_addr,
                         false);
#endif
        if( l_err )
        {
            break;
        }
        // If any bits are set, set this unit's bit in summary reg
        //   note: just check the first bit,
        //         this is good enough for the use-case we have now
        //         but a better implementation would be to actually
        //         check the select regs as well so we know which bit(s)
        //         are the trigger
        if( l_data & 0x8000000000000000 )
        {
            *l_summaryReg |= (0x8000000000000000 >> l_chplt);
        }

    }

    o_didWorkaround = true;

    return l_err;
}

} // end namespace IBSCOM
