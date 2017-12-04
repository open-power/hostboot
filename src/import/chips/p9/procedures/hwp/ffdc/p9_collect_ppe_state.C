/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_collect_ppe_state.C $ */
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
///
/// @file   p9_collect_ppe_state.C
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 3
/// *HWP Consumed by     : HB


#include <fapi2.H>
#include <hwp_error_info.H>
#include <p9_const_common.H>

#include <p9_collect_ppe_state.H>
#include <p9_ppe_state.H>

extern "C"
{
    uint32_t addFfdcDataSprs ( std::vector<PPERegValue_t>& i_sprList,
                               fapi2::ReturnCode& o_rc )
    {
        FAPI_INF (">>addFfdcDataSprs: input list count %d", i_sprList.size());
        uint32_t l_regCount = 0;

        // Init FFDC to a detault pattern
        uint32_t l_defaultVal = 0xDEADC0DE;
        fapi2::ffdc_t REG_DEFAULT;
        REG_DEFAULT.ptr() = static_cast<void*>(&l_defaultVal);
        REG_DEFAULT.size() = sizeof (l_defaultVal);

        fapi2::ffdc_t REG_MSR = REG_DEFAULT;
        fapi2::ffdc_t REG_CR = REG_DEFAULT;
        fapi2::ffdc_t REG_CTR = REG_DEFAULT;
        fapi2::ffdc_t REG_LR = REG_DEFAULT;
        fapi2::ffdc_t REG_ISR = REG_DEFAULT;
        fapi2::ffdc_t REG_SRR0 = REG_DEFAULT;
        fapi2::ffdc_t REG_SRR1 = REG_DEFAULT;
        fapi2::ffdc_t REG_TCR = REG_DEFAULT;
        fapi2::ffdc_t REG_TSR = REG_DEFAULT;
        fapi2::ffdc_t REG_DACR = REG_DEFAULT;
        fapi2::ffdc_t REG_DBCR = REG_DEFAULT;
        fapi2::ffdc_t REG_DEC = REG_DEFAULT;
        fapi2::ffdc_t REG_IVPR = REG_DEFAULT;
        fapi2::ffdc_t REG_PIR = REG_DEFAULT;
        fapi2::ffdc_t REG_PVR = REG_DEFAULT;
        fapi2::ffdc_t REG_XER = REG_DEFAULT;

        for (auto& it : i_sprList)
        {
            ++l_regCount;

            switch (it.number)
            {
                // Special SPRs
                case MSR:
                    REG_MSR.ptr() = static_cast<void*>(&it.value);
                    REG_MSR.size() = sizeof (it.value);
                    break;

                case CR:
                    REG_CR.ptr() = static_cast<void*>(&it.value);
                    REG_CR.size() = sizeof (it.value);
                    break;

                // Major SPRs
                case CTR:
                    REG_CTR.ptr() = static_cast<void*>(&it.value);
                    REG_CTR.size() = sizeof (it.value);
                    break;

                case LR:
                    REG_LR.ptr() = static_cast<void*>(&it.value);
                    REG_LR.size() = sizeof (it.value);
                    break;

                case ISR:
                    REG_ISR.ptr() = static_cast<void*>(&it.value);
                    REG_ISR.size() = sizeof (it.value);
                    break;

                case SRR0:
                    REG_SRR0.ptr() = static_cast<void*>(&it.value);
                    REG_SRR0.size() = sizeof (it.value);
                    break;

                case SRR1:
                    REG_SRR1.ptr() = static_cast<void*>(&it.value);
                    REG_SRR1.size() = sizeof (it.value);
                    break;

                case TCR:
                    REG_TCR.ptr() = static_cast<void*>(&it.value);
                    REG_TCR.size() = sizeof (it.value);
                    break;

                case TSR:
                    REG_TSR.ptr() = static_cast<void*>(&it.value);
                    REG_TSR.size() = sizeof (it.value);
                    break;

                // Minor SPRs
                case DACR:
                    REG_DACR.ptr() = static_cast<void*>(&it.value);
                    REG_DACR.size() = sizeof (it.value);
                    break;

                case DBCR:
                    REG_DBCR.ptr() = static_cast<void*>(&it.value);
                    REG_DBCR.size() = sizeof (it.value);
                    break;

                case DEC:
                    REG_DEC.ptr() = static_cast<void*>(&it.value);
                    REG_DEC.size() = sizeof (it.value);
                    break;

                case IVPR:
                    REG_IVPR.ptr() = static_cast<void*>(&it.value);
                    REG_IVPR.size() = sizeof (it.value);
                    break;

                case PIR:
                    REG_PIR.ptr() = static_cast<void*>(&it.value);
                    REG_PIR.size() = sizeof (it.value);
                    break;

                case PVR:
                    REG_PVR.ptr() = static_cast<void*>(&it.value);
                    REG_PVR.size() = sizeof (it.value);
                    break;

                case XER:
                    REG_XER.ptr() = static_cast<void*>(&it.value);
                    REG_XER.size() = sizeof (it.value);
                    break;

                default:
                    l_regCount--;
                    FAPI_ERR ("Unknown PPE SPR %d", it.number);
                    break;
            }
        }

        // add data to ffdc only something was collected
        if (i_sprList.size() != 0)
        {
            FAPI_ADD_INFO_TO_HWP_ERROR (o_rc, RC_PPE_STATE_DATA_SPR);
            FAPI_INF ("<< addFfdcDataSprs: %d SPRs added to FFDC", l_regCount);
            i_sprList.clear ();
        }

        return l_regCount;
    }

    uint32_t addFfdcDataXirs ( std::vector<PPERegValue_t>& i_xirList,
                               fapi2::ReturnCode& o_rc )
    {
        FAPI_INF (">> addFfdcDataXirs: input list count %d", i_xirList.size());
        uint32_t l_regCount = 0;

        // Init FFDC to a detault pattern
        uint32_t l_defaultVal = 0xDEADC0DE;
        fapi2::ffdc_t REG_DEFAULT;
        REG_DEFAULT.ptr() = static_cast<void*>(&l_defaultVal);
        REG_DEFAULT.size() = sizeof (l_defaultVal);

        fapi2::ffdc_t REG_XSR = REG_DEFAULT;
        fapi2::ffdc_t REG_IAR = REG_DEFAULT;
        fapi2::ffdc_t REG_IR = REG_DEFAULT;
        fapi2::ffdc_t REG_EDR = REG_DEFAULT;
        fapi2::ffdc_t REG_SPRG0 = REG_DEFAULT;

        for (auto& it : i_xirList)
        {
            ++l_regCount;

            switch (it.number)
            {
                case XSR:
                    REG_XSR.ptr() = static_cast<void*>(&it.value);
                    REG_XSR.size() = sizeof (it.value);
                    break;

                case IAR:
                    REG_IAR.ptr() = static_cast<void*>(&it.value);
                    REG_IAR.size() = sizeof (it.value);
                    break;

                case IR:
                    REG_IR.ptr() = static_cast<void*>(&it.value);
                    REG_IR.size() = sizeof (it.value);
                    break;

                case EDR:
                    REG_EDR.ptr() = static_cast<void*>(&it.value);
                    REG_EDR.size() = sizeof (it.value);
                    break;

                case SPRG0:
                    REG_SPRG0.ptr() = static_cast<void*>(&it.value);
                    REG_SPRG0.size() = sizeof (it.value);
                    break;

                default:
                    l_regCount--;
                    FAPI_ERR ("Unknown PPE XIR %d", it.number);
                    break;
            }
        }

        // add data to ffdc only something was collected
        if ( i_xirList.size() != 0 )
        {
            FAPI_ADD_INFO_TO_HWP_ERROR (o_rc, RC_PPE_STATE_DATA_XIR);
            FAPI_INF ("<< addFfdcDataXirs: %d XIRs added to FFDC", l_regCount);
            i_xirList.clear ();
        }

        return l_regCount;
    }


    uint32_t addFfdcDataGprs ( std::vector<PPERegValue_t>& i_gprList,
                               fapi2::ReturnCode& o_rc )
    {
        FAPI_INF (">> addFfdcDataGprs: input list count %d", i_gprList.size());
        uint32_t l_regCount = 0;

        // Init FFDC to a detault pattern
        uint32_t l_defaultVal = 0xDEADC0DE;
        fapi2::ffdc_t REG_DEFAULT;
        REG_DEFAULT.ptr() = static_cast<void*>(&l_defaultVal);
        REG_DEFAULT.size() = sizeof (l_defaultVal);

        fapi2::ffdc_t REG_R0 = REG_DEFAULT;
        fapi2::ffdc_t REG_R1 = REG_DEFAULT;
        fapi2::ffdc_t REG_R2 = REG_DEFAULT;
        fapi2::ffdc_t REG_R3 = REG_DEFAULT;
        fapi2::ffdc_t REG_R4 = REG_DEFAULT;
        fapi2::ffdc_t REG_R5 = REG_DEFAULT;
        fapi2::ffdc_t REG_R6 = REG_DEFAULT;
        fapi2::ffdc_t REG_R7 = REG_DEFAULT;
        fapi2::ffdc_t REG_R8 = REG_DEFAULT;
        fapi2::ffdc_t REG_R9 = REG_DEFAULT;
        fapi2::ffdc_t REG_R10 = REG_DEFAULT;
        fapi2::ffdc_t REG_R13 = REG_DEFAULT;
        fapi2::ffdc_t REG_R28 = REG_DEFAULT;
        fapi2::ffdc_t REG_R29 = REG_DEFAULT;
        fapi2::ffdc_t REG_R30 = REG_DEFAULT;
        fapi2::ffdc_t REG_R31 = REG_DEFAULT;

        for (auto& it : i_gprList)
        {
            ++l_regCount;

            switch (it.number)
            {
                case R0:
                    REG_R0.ptr() = static_cast<void*>(&it.value);
                    REG_R0.size() = sizeof (it.value);
                    break;

                case R1:
                    REG_R1.ptr() = static_cast<void*>(&it.value);
                    REG_R1.size() = sizeof (it.value);
                    break;

                case R2:
                    REG_R2.ptr() = static_cast<void*>(&it.value);
                    REG_R2.size() = sizeof (it.value);
                    break;

                case R3:
                    REG_R3.ptr() = static_cast<void*>(&it.value);
                    REG_R3.size() = sizeof (it.value);
                    break;

                case R4:
                    REG_R4.ptr() = static_cast<void*>(&it.value);
                    REG_R4.size() = sizeof (it.value);
                    break;

                case R5:
                    REG_R5.ptr() = static_cast<void*>(&it.value);
                    REG_R5.size() = sizeof (it.value);
                    break;

                case R6:
                    REG_R6.ptr() = static_cast<void*>(&it.value);
                    REG_R6.size() = sizeof (it.value);
                    break;

                case R7:
                    REG_R7.ptr() = static_cast<void*>(&it.value);
                    REG_R7.size() = sizeof (it.value);
                    break;

                case R8:
                    REG_R8.ptr() = static_cast<void*>(&it.value);
                    REG_R8.size() = sizeof (it.value);
                    break;

                case R9:
                    REG_R9.ptr() = static_cast<void*>(&it.value);
                    REG_R9.size() = sizeof (it.value);
                    break;

                case R10:
                    REG_R10.ptr() = static_cast<void*>(&it.value);
                    REG_R10.size() = sizeof (it.value);
                    break;

                case R13:
                    REG_R13.ptr() = static_cast<void*>(&it.value);
                    REG_R13.size() = sizeof (it.value);
                    break;

                case R28:
                    REG_R28.ptr() = static_cast<void*>(&it.value);
                    REG_R28.size() = sizeof (it.value);
                    break;

                case R29:
                    REG_R29.ptr() = static_cast<void*>(&it.value);
                    REG_R29.size() = sizeof (it.value);
                    break;

                case R30:
                    REG_R30.ptr() = static_cast<void*>(&it.value);
                    REG_R30.size() = sizeof (it.value);
                    break;

                case R31:
                    REG_R31.ptr() = static_cast<void*>(&it.value);
                    REG_R31.size() = sizeof (it.value);
                    break;

                default:
                    l_regCount--;
                    FAPI_ERR ("Unknown PPE GPR %d", it.number);
                    break;
            }
        }

        // add data to ffdc only something was collected
        if (i_gprList.size () != 0)
        {
            FAPI_ADD_INFO_TO_HWP_ERROR (o_rc, RC_PPE_STATE_DATA_GPR);
            FAPI_INF ("<< addFfdcDataGprs: %d GPRs added to FFDC", l_regCount);
            i_gprList.clear ();
        }

        return l_regCount;
    }

    fapi2::ReturnCode
    p9_collect_ppe_state ( const fapi2::ffdc_t& i_target,
                           const fapi2::ffdc_t& i_mode,
                           const fapi2::ffdc_t& i_v_ppe_addresses,
                           fapi2::ReturnCode& o_rc )
    {
        FAPI_INF (">> p9_collect_ppe_state");
        fapi2::ReturnCode l_rc;
        fapi2::ATTR_INITIATED_PM_RESET_Type l_pm_reset_active;
        fapi2::ffdc_t PPE_BASE_ADDR;

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc_chip =
            *(reinterpret_cast<const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> *>
              (i_target.ptr()));

        std::vector<uint64_t> l_ppe_addresses =
            *(reinterpret_cast<const std::vector<uint64_t>*>
              (i_v_ppe_addresses.ptr()));

        PPE_DUMP_MODE l_mode = *(reinterpret_cast<const PPE_DUMP_MODE*>(i_mode.ptr()));

        // if call to this HWP is in PM Reset flow then just collect XIRs.
        // Full PPE state will be collected as a part of PM Recovery in
        // later part of PM reset flow.
        FAPI_ATTR_GET(fapi2::ATTR_INITIATED_PM_RESET,
                      l_proc_chip,
                      l_pm_reset_active);

        if( fapi2::ENUM_ATTR_INITIATED_PM_RESET_ACTIVE == l_pm_reset_active )
        {
            l_mode = XIRS;
        }

        std::vector<PPERegValue_t> l_v_sprs;
        std::vector<PPERegValue_t> l_v_xirs;
        std::vector<PPERegValue_t> l_v_gprs;

        for (auto& it1 : l_ppe_addresses )
        {
            fapi2::ReturnCode l_rc_tmp = fapi2::current_err;
            uint64_t l_addr = it1;

            FAPI_INF ("p9_collect_ppe_state: PPE Base Addr 0x%.16llX, 0x%.8X",
                      it1, l_mode);
            FAPI_EXEC_HWP (l_rc, p9_ppe_state, l_proc_chip, it1, l_mode,
                           l_v_sprs, l_v_xirs, l_v_gprs);

            // Ignore l_rc and continue adding whatever was collected

            fapi2::current_err = l_rc_tmp;

            FAPI_INF ("Adding PPE Addr: 0x%.16llX, SPRs: %d XIRs: %d GPRs: %d",
                      it1, l_v_sprs.size(), l_v_xirs.size(), l_v_gprs.size());

            // since this accepts multiple PPE addresses, log which PPE Addr the
            // FFDC Data belongs to, to the FFDC info

            PPE_BASE_ADDR.ptr() = static_cast<void*>(&l_addr);
            PPE_BASE_ADDR.size() = sizeof (l_addr);
            FAPI_ADD_INFO_TO_HWP_ERROR (o_rc, RC_PPE_BASE_ADDR_XIXCR);

            // Add all the PPE State Registers to the FFDC
            addFfdcDataXirs (l_v_xirs, o_rc);
            addFfdcDataSprs (l_v_sprs, o_rc);
            addFfdcDataGprs (l_v_gprs, o_rc);
        }

        FAPI_INF ("<< p9_collect_ppe_state");
        return fapi2::FAPI2_RC_SUCCESS; // always return success
    }
}
