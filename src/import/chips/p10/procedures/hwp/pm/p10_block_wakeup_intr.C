/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_block_wakeup_intr.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file  p10_block_wakeup_intr.H
/// @brief Enable/Disable block stop entry/exit protocol
///         associated with an core chiplet
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *HWP Team     : PM
// *HWP Level    : 2
// *HWP Consumed by: FSP:HS
///
/// @endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p10_block_wakeup_intr.H>
#include <p10_hcd_common.H>
#include <p10_pm_hcd_flags.h>
#include <p10_scom_proc.H>
#include <p10_scom_eq.H>

using namespace scomt;
using namespace proc;
using namespace eq;
using namespace p10hcd;
using namespace p10pmblockwkup;

// 1000000 nanosecond = 1 millisecond
// total timeout = 10 milliseconds
static const uint64_t POLLTIME_NS          = 1000000;
static const uint64_t POLLTIME_MCYCLES     = 4000;
static const uint32_t TRIES_BEFORE_TIMEOUT = 500;

const char* g_block_op_string[] =
{
    "ENABLE_BLOCK_EXIT",
    "DISABLE_BLOCK_EXIT",
    "ENABLE_BLOCK_ENTRY",
    "DISABLE_BLOCK_ENTRY",
    "NONE"
};

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------
fapi2::ReturnCode
p10_block_wakeup_intr(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    const OP_TYPE i_operation)
{
    FAPI_INF("> p10_block_wakeup_intr...");

    fapi2::buffer<uint64_t> l_data64 = 0;
    uint64_t l_occflg3_data = 0;
    uint32_t l_relative_core_pos = 0;
    uint64_t l_scrb_data = 0;
    uint8_t  l_block_operation = false;

    // Get the core number
    uint8_t l_attr_chip_unit_core_pos = 0;
    uint8_t l_attr_chip_unit_eq_pos = 0;


    fapi2::Target<fapi2::TARGET_TYPE_EQ> l_eq =
        i_core_target.getParent<fapi2::TARGET_TYPE_EQ>();

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc =
        i_core_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                           i_core_target,
                           l_attr_chip_unit_core_pos),
             "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");

    l_attr_chip_unit_eq_pos = l_attr_chip_unit_core_pos >> 2;

    l_relative_core_pos = l_attr_chip_unit_core_pos % 4;

    switch (i_operation)
    {
        case ENABLE_BLOCK_EXIT:

            //Ignore STOP Exits  bits :0-3
            l_scrb_data = BIT64(l_relative_core_pos);
            //OCCFLG3 set bit 11,12,13
            l_occflg3_data = BIT64(XGPE_IGNORE_STOP_CONTROL) | BIT64(XGPE_IGNORE_STOP_ACTION) |
                             BIT64(XGPE_IGNORE_STOP_EXITS);
            break;

        case DISABLE_BLOCK_EXIT:
            //Ignore STOP Exits  bits :0-3
            l_scrb_data = BIT64(l_relative_core_pos);

            //OCCFLG3 set bit 11,13
            //bit 11 is left cleared for the disable operation".
            l_occflg3_data = BIT64(XGPE_IGNORE_STOP_CONTROL) | BIT64(XGPE_IGNORE_STOP_EXITS);
            break;

        case ENABLE_BLOCK_ENTRY:
            //Ignore STOP Entries  bits :4-7
            l_scrb_data = BIT64(l_relative_core_pos) >> 4;

            //OCCFLG3 set bit 11,12,13
            l_occflg3_data = BIT64(XGPE_IGNORE_STOP_CONTROL) | BIT64(XGPE_IGNORE_STOP_ACTION) |
                             BIT64(XGPE_IGNORE_STOP_ENTRIES);
            break;

        case DISABLE_BLOCK_ENTRY:
            //Ignore STOP Entries  bits :4-7
            l_scrb_data = BIT64(l_relative_core_pos) >> 4;

            //OCCFLG3 set bit 11,14
            //bit 12 is left cleared for the disable operation".
            l_occflg3_data = BIT64(XGPE_IGNORE_STOP_CONTROL) | BIT64(XGPE_IGNORE_STOP_ENTRIES);
            break;

        default:
            FAPI_ASSERT_NOEXIT(false,
                               //SBE Platform does not take an arguement for FFDC constructor.
                               //There was a ppe compilation failure due to this.
#ifdef __PPE__
                               fapi2::PM_BLOCK_WAKEUP_INTR_OP()
#else
                               fapi2::PM_BLOCK_WAKEUP_INTR_OP(fapi2::FAPI2_ERRL_SEV_RECOVERED)
#endif
                               .set_OPERATION(i_operation)
                               .set_CORE_TARGET(i_core_target)
                               .set_CORE_POSITION(l_attr_chip_unit_core_pos),
                               "Invalid parameter passed to block wakeup procedure");
            break;
    }

    //set QME SCRB[Ignore STOP Exits]
    PREP_QME_SCRB_WO_OR(l_eq);
    PUT_QME_SCRB_WO_OR(l_eq, l_scrb_data);

    PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_OR(l_proc);
    PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_OR(l_proc, l_occflg3_data);

    //OISR0 - set GPE3_FUNC_TRIGGER (that signals xgpe)
    PREP_TP_TPCHIP_OCC_OCI_OCB_OISR0_WO_OR(l_proc);
    l_data64.flush<0>().setBit<11>();
    PUT_TP_TPCHIP_OCC_OCI_OCB_OISR0_WO_OR(l_proc, l_data64);

    for (uint32_t i = 0; i < TRIES_BEFORE_TIMEOUT; i++)
    {
        //Poll for OCCFLG3[XGPE Ignore STOP Control]
        GET_TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_RW(l_proc, l_data64);

        if (!l_data64.getBit<XGPE_IGNORE_STOP_CONTROL>())
        {
            l_block_operation = true;
            break;
        }

        fapi2::delay(POLLTIME_NS, POLLTIME_MCYCLES * 1000 * 1000);
    }

    if (!l_block_operation)
    {
        FAPI_ERR("%s operation failed for core %d of quad %d",
                 g_block_op_string[i_operation], l_attr_chip_unit_core_pos,
                 l_attr_chip_unit_eq_pos);
        FAPI_ASSERT(false,
                    fapi2::PM_BLOCK_WAKEUP_INTR_FAILED()
                    .set_CHIP_TARGET(l_proc)
                    .set_OCCFLG3_DATA(l_data64)
                    .set_OP_TYPE(i_operation)
                    .set_CORE_TARGET(i_core_target)
                    .set_CORE_POSITION(l_attr_chip_unit_core_pos)
                    .set_EQ_TARGET(l_eq)
                    .set_EQ_POSITION(l_attr_chip_unit_eq_pos),
                    "Block wakeup procedure failed");
    }


    //OCCFLG3 clear bit 11,12,13
    l_occflg3_data = BIT64(XGPE_IGNORE_STOP_ENTRIES) | BIT64(XGPE_IGNORE_STOP_ACTION) |
                     BIT64(XGPE_IGNORE_STOP_EXITS);
    PREP_TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_CLEAR(l_proc);
    PUT_TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_CLEAR(l_proc, l_occflg3_data);

    //clear QME SCRB[Ignore STOP Exits]
    PREP_QME_SCRB_WO_CLEAR(l_eq);
    PUT_QME_SCRB_WO_CLEAR(l_eq, l_scrb_data);



fapi_try_exit:
    FAPI_INF("< p10_block_wakeup_intr...");
    return fapi2::current_err;
}
