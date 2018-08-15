/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_collect_lpc_regs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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

#include <stdint.h>
#include <hwp_error_info.H>
#include <fapi2.H>
#include "p9_collect_lpc_regs.H"
#include "p9_perv_scom_addresses.H"
#include "p9_perv_scom_addresses_fld.H"
#include "p9_misc_scom_addresses.H"
#include "p9_misc_scom_addresses_fld.H"

#include <p9_lpc_utils.H>

static void lpc_dump(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint32_t i_first_addr, uint32_t i_last_addr,
    fapi2::variable_buffer& o_data, fapi2::ffdc_t& o_ffdc)
{
    const uint32_t l_nregs = (i_last_addr - i_first_addr + 4) / 4;
    fapi2::buffer<uint32_t> l_data32;
    o_data.resize(l_nregs * 32);
    o_ffdc.ptr() = o_data.pointer();
    o_ffdc.size() = o_data.getLength<uint8_t>();

    for (uint32_t i = 0; i < l_nregs; i++)
    {
        fapi2::ReturnCode l_rc = lpc_read(i_target_chip, i_first_addr + (i * 4), l_data32, false);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            l_data32 = 0xDEADC0DE;
        }

        o_data.set(l_data32(), i);
    }
}

extern "C" fapi2::ReturnCode p9_collect_lpc_regs(fapi2::ffdc_t& i_target_chip, fapi2::ReturnCode& o_rc)
{
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target_chip =
        *(reinterpret_cast<const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> *>
          (i_target_chip.ptr()));

    fapi2::variable_buffer l_opb_mst_regs, l_opb_arb_regs, l_lpc_hc_regs;
    fapi2::ffdc_t OPB_MST_REGS, OPB_ARB_REGS, LPC_HC_REGS;

    lpc_dump(l_target_chip, 0xC0010000, 0xC001005C, l_opb_mst_regs, OPB_MST_REGS);
    lpc_dump(l_target_chip, 0xC0011000, 0xC0011004, l_opb_arb_regs, OPB_ARB_REGS);
    lpc_dump(l_target_chip, 0xC0012000, 0xC00120FC, l_lpc_hc_regs, LPC_HC_REGS);

    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_LPC_REGISTERS);
    return fapi2::ReturnCode();
}
