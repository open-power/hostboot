/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_common.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_io_common.C
/// @brief IO Common Functions.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3 3
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// IO Common Functions
//
/// @endverbatim
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_common.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

//-----------------------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------------------
/**
 * @brief Shorten timers if we are running in simulation
 *        a right aligned value.
 * @param[in] i_tgt   FAPI2 Target
 * @param[in] i_grp   Clock group
 * @return Field Data
 */
fapi2::ReturnCode p9_io_xbus_shorten_timers(const XBUS_TGT& i_tgt, const uint8_t i_grp)
{
    FAPI_IMP("p9_io_xbus_shorten_timers: I/O EDI+ Xbus Entering");
    const uint8_t LN0  = 0;
    uint64_t      reg_data = 0;
    uint8_t       l_is_sim = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));

    if(l_is_sim)
    {
        FAPI_TRY(io::read(EDIP_RX_CTL_MODE7_EO_PG, i_tgt, i_grp, LN0, reg_data));
        io::set(EDIP_RX_ABORT_CHECK_TIMEOUT_SEL, 0x0, reg_data);
        io::set(EDIP_RX_POLLING_TIMEOUT_SEL, 0x0, reg_data);
        FAPI_TRY(io::write(EDIP_RX_CTL_MODE7_EO_PG, i_tgt, i_grp, LN0, reg_data));

        FAPI_TRY(io::rmw(EDIP_RX_SERVO_CHG_CFG, i_tgt, i_grp, LN0, 0x0));


        FAPI_TRY(io::read(EDIP_RX_CTL_MODE14_EO_PG, i_tgt, i_grp, LN0, reg_data));
        io::set(EDIP_RX_AMP_INIT_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_AMP_RECAL_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_PEAK_INIT_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_PEAK_RECAL_TIMEOUT, 0x0, reg_data);
        FAPI_TRY(io::write(EDIP_RX_CTL_MODE14_EO_PG, i_tgt, i_grp, LN0, reg_data));

        FAPI_TRY(io::read(EDIP_RX_CTL_MODE15_EO_PG, i_tgt, i_grp, LN0, reg_data));
        io::set(EDIP_RX_AMIN_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_CM_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_OFF_INIT_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_OFF_RECAL_TIMEOUT, 0x0, reg_data);
        FAPI_TRY(io::write(EDIP_RX_CTL_MODE15_EO_PG, i_tgt, i_grp, LN0, reg_data));

        FAPI_TRY(io::read(EDIP_RX_CTL_MODE16_EO_PG, i_tgt, i_grp, LN0, reg_data));
        io::set(EDIP_RX_AMP_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_BER_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_USERDEF_TIMEOUT, 0x0, reg_data);
        FAPI_TRY(io::write(EDIP_RX_CTL_MODE16_EO_PG, i_tgt, i_grp, LN0, reg_data));
    }

fapi_try_exit:
    FAPI_IMP("p9_io_xbus_shorten_timers: I/O EDI+ Xbus Exiting");
    return fapi2::current_err;
}

/**
 * @brief Shorten timers if we are running in simulation
 *        a right aligned value.
 * @param[in] i_tgt   FAPI2 Target
 * @return Field Data
 */
fapi2::ReturnCode p9_io_dmi_proc_shorten_timers(const DMI_PROC_TGT& i_tgt)
{
    FAPI_IMP("p9_io_dmi_proc_shorten_timers: I/O EDI+ DMI Proc Entering");
    const uint8_t GRP3 = 3;
    const uint8_t LN0  = 0;
    uint64_t      reg_data = 0;
    uint8_t       l_is_sim = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));

    if(l_is_sim)
    {
        FAPI_TRY(io::read(EDIP_RX_CTL_MODE7_EO_PG, i_tgt, GRP3, LN0, reg_data));
        io::set(EDIP_RX_ABORT_CHECK_TIMEOUT_SEL, 0x0, reg_data);
        io::set(EDIP_RX_POLLING_TIMEOUT_SEL, 0x0, reg_data);
        FAPI_TRY(io::write(EDIP_RX_CTL_MODE7_EO_PG, i_tgt, GRP3, LN0, reg_data));

        FAPI_TRY(io::rmw(EDIP_RX_SERVO_CHG_CFG, i_tgt, GRP3, LN0, 0x0));


        FAPI_TRY(io::read(EDIP_RX_CTL_MODE14_EO_PG, i_tgt, GRP3, LN0, reg_data));
        io::set(EDIP_RX_AMP_INIT_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_AMP_RECAL_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_PEAK_INIT_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_PEAK_RECAL_TIMEOUT, 0x0, reg_data);
        FAPI_TRY(io::write(EDIP_RX_CTL_MODE14_EO_PG, i_tgt, GRP3, LN0, reg_data));

        FAPI_TRY(io::read(EDIP_RX_CTL_MODE15_EO_PG, i_tgt, GRP3, LN0, reg_data));
        io::set(EDIP_RX_AMIN_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_CM_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_OFF_INIT_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_OFF_RECAL_TIMEOUT, 0x0, reg_data);
        FAPI_TRY(io::write(EDIP_RX_CTL_MODE15_EO_PG, i_tgt, GRP3, LN0, reg_data));

        FAPI_TRY(io::read(EDIP_RX_CTL_MODE16_EO_PG, i_tgt, GRP3, LN0, reg_data));
        io::set(EDIP_RX_AMP_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_BER_TIMEOUT, 0x0, reg_data);
        io::set(EDIP_RX_USERDEF_TIMEOUT, 0x0, reg_data);
        FAPI_TRY(io::write(EDIP_RX_CTL_MODE16_EO_PG, i_tgt, GRP3, LN0, reg_data));
    }

fapi_try_exit:
    FAPI_IMP("p9_io_dmi_proc_shorten_timers: I/O EDI+ DMI Proc Exiting");
    return fapi2::current_err;
}

/**
 * @brief Shorten timers if we are running in simulation
 *        a right aligned value.
 * @param[in] i_tgt   FAPI2 Target
 * @return Field Data
 */
fapi2::ReturnCode p9_io_dmi_cn_shorten_timers(const DMI_CN_TGT& i_tgt)
{
    FAPI_IMP("p9_io_dmi_cn_shorten_timers: I/O EDI DMI Centaur Entering");
    //const uint8_t GRP0 = 0;
    //const uint8_t LN0  = 0;
    //uint64_t      reg_data = 0;
    uint8_t       l_is_sim = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));

    if(l_is_sim)
    {
    }

fapi_try_exit:
    FAPI_IMP("p9_io_dmi_cn_shorten_timers: I/O EDI DMI Centaur Exiting");
    return fapi2::current_err;
}

