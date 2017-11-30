/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_cen_framelock.C $  */
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
///
/// @file p9_cen_framelock.C
/// @brief Enable transmission of the logical protocol (frame) layer over the DMI link(FAPI2)
///
/// @author Jin Song Jiang <jjsjiang@cn.ibm.com>
///

//
// *HWP HWP Owner: Jin Song Jiang <jjsjiang@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 3
// *HWP Consumed by: HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_cen_framelock.H>
#include <p9_mc_scom_addresses.H>
#include <cen_gen_scom_addresses.H>

fapi2::ReturnCode p9_cen_framelock_cloned(const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
        const p9_cen_framelock_args& i_args);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// framelock/FRTL polling constants
const uint8_t P9_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS = 5;
const uint8_t P9_CEN_FRAMELOCK_MAX_FRTL_POLLS = 5;

const uint8_t P9_CEN_FRAMELOCK_FRTL_MAX_VALUE = 0x6C;
const uint8_t P9_CEN_FRAMELOCK_FRTL_STATIC_OFFSET = 0xA;

// P9 MCI Configuration Register field/bit definitions
const uint32_t MCI_CFG_FORCE_CHANNEL_FAIL_BIT = 25;
const uint32_t MCI_CFG_START_FRAMELOCK_BIT = 0;
const uint32_t MCI_CFG_START_FRTL_BIT = 1;
const uint32_t MCI_CFG_AUTO_FRTL_DISABLE_BIT = 4;
const uint32_t MCI_CFG_MANUAL_FRTL_START_BIT = 6;
const uint32_t MCI_CFG_MANUAL_FRTL_END_BIT = 12;
const uint32_t MCI_CFG_MANUAL_FRTL_DONE_BIT = 5;
const uint32_t MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT = 2;
const uint32_t MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT   = 3;
const uint32_t MCI_CFG_MCICFGQ_SPEC_MODE = 44;
const uint32_t MCI_CFG_MCICFGQ_HOST_MODE = 45;

const uint8_t MCI_CFG_MANUAL_FRTL_FIELD_MASK = 0x7F;
const uint32_t MCI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK = 0x3;

// P9 MCI Status Register field/bit definitions
const uint32_t MCI_STAT_FRAMELOCK_PASS_BIT = 0;
const uint32_t MCI_STAT_FRAMELOCK_FAIL_BIT = 1;
const uint32_t MCI_STAT_FRTL_PASS_BIT = 2;
const uint32_t MCI_STAT_FRTL_FAIL_BIT = 3;
const uint32_t MCI_FRTL_START_BIT = 4;
const uint32_t MCI_FRTL_END_BIT = 10;
const uint32_t MCI_STAT_CHANNEL_INTERLOCK_PASS_BIT = 11;
const uint32_t MCI_STAT_CHANNEL_INTERLOCK_FAIL_BIT = 12;

// P9 MCI FIR Register field/bit definitions
const uint32_t DATAPATH_FIR_SCOM_WR_PERR_BIT                   =  0;
const uint32_t DATAPATH_FIR_MCICFGQ_PARITY_ERROR_BIT           =  1;
const uint32_t DATAPATH_FIR_DSRC_NO_FORWARD_PROGRESS_BIT       =  2;
const uint32_t DATAPATH_FIR_DSRC_PERF_DEGRAD_BIT               =  3;
const uint32_t DATAPATH_FIR_DMI_CHANNEL_FAIL_BIT               =  4;
const uint32_t DATAPATH_FIR_CHANNEL_INIT_TIMEOUT_BIT           =  5;
const uint32_t DATAPATH_FIR_CHANNEL_INTERLOCK_FAIL_BIT         =  6;
const uint32_t DATAPATH_FIR_FRTL_COUNTER_OVERFLOW_BIT          =  7;
const uint32_t DATAPATH_FIR_CRC_ERR_BIT                        =  8;
const uint32_t DATAPATH_FIR_FIR_NOACK_ERR_BIT                  =  9;
const uint32_t DATAPATH_FIR_SEQID_OUT_OF_ORDER_BIT             = 10;
const uint32_t DATAPATH_FIR_REPLAY_BUFFER_CE_BIT               = 11;
const uint32_t DATAPATH_FIR_REPLAY_BUFFER_UE_BIT               = 12;
const uint32_t DATAPATH_FIR_MULTIPLE_REPLAY_BIT                = 13;
const uint32_t DATAPATH_FIR_REPLAY_BUFFER_OVERRUN_BIT          = 14;
const uint32_t DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT         = 15;
const uint32_t DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT         = 16;
const uint32_t DATAPATH_FIR_CEN_TRACESTOP_BIT                  = 17;
const uint32_t DATAPATH_FIR_EN_FPGA_INT_BIT                    = 18;
const uint32_t DATAPATH_FIR_CENTAUR_RECOVERABLE_FAIL_BIT       = 19;
const uint32_t DATAPATH_FIR_CENTAUR_SPECIAL_ATTN_FAIL_BIT      = 20;
const uint32_t DATAPATH_FIR_CENTAUR_MAINT_COMPLETE_BIT         = 21;
const uint32_t DATAPATH_FIR_USFD_CHANFAIL_SEQ_ERROR_BIT        = 31;
const uint32_t DATAPATH_FIR_DSFF_TAG_OVERRUN_BIT               = 32;
const uint32_t DATAPATH_FIR_SFF_DS_DATA_ERROR_DETECTED_BIT     = 33;
const uint32_t DATAPATH_FIR_RDATA_PERR_BIT                     = 36;
const uint32_t DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_PERR_BIT   = 40;
const uint32_t DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_SEQERR_BIT = 41;
const uint32_t DATAPATH_FIR_DSFF_SEQ_ERROR_BIT                 = 42;
const uint32_t DATAPATH_FIR_RECOVERABLE_PERR_EICR_BIT          = 43;
const uint32_t DATAPATH_FIR_FATAL_PERR_RECR_BIT                = 44;
const uint32_t DATAPATH_FIR_WRT_RMW_BUFFER_CE_BIT              = 45;
const uint32_t DATAPATH_FIR_WRT_RMW_BUFFER_UE_BIT              = 46;
const uint32_t DATAPATH_FIR_WRT_RMW_BUFFER_SUE_BIT             = 47;
const uint32_t DATAPATH_FIR_WDF_OVERRUN_ERR_BIT0               = 48;
const uint32_t DATAPATH_FIR_WDF_OVERRUN_ERR_BIT1               = 49;
const uint32_t DATAPATH_FIR_WDF_SCOM_SEQ_ERR_BIT               = 50;
const uint32_t DATAPATH_FIR_WDF_SM_ERR_BIT                     = 51;
const uint32_t DATAPATH_FIR_WDF_REG_PERR_BIT                   = 52;
const uint32_t DATAPATH_FIR_WRT_SCOM_SEQ_ERR_BIT               = 53;
const uint32_t DATAPATH_FIR_WRT_REG_PERR_BIT                   = 54;
const uint32_t DATAPATH_FIR_USFD_ATTN_VALID_BIT                = 55;
const uint32_t DATAPATH_FIR_READ_BUF_OVERRUN_BIT               = 56;
const uint32_t DATAPATH_FIR_WDF_ASYNC_ERR_BIT                  = 57;
const uint32_t DATAPATH_FIR_READ_MCA_PERR_BIT                  = 58;
const uint32_t DATAPATH_FIR_READ_MCA_SEQ_ERR_BIT               = 59;
const uint32_t DATAPATH_FIR_DBGWAT_PERR_BIT                    = 60;
const uint32_t DATAPATH_FIR_DSFF_TIMEOUT_BIT                   = 61;
const uint32_t DATAPATH_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT  = 62;
const uint32_t DATAPATH_FIR_INTERNAL_PARITY_ERROR_COPY_BIT     = 63;

// Centaur MBI Configuration Register field/bit defintions
const uint32_t MBI_CFG_FORCE_CHANNEL_FAIL_BIT = 0;
const uint32_t MBI_CFG_FORCE_FRAMELOCK_BIT = 7;
const uint32_t MBI_CFG_FORCE_FRTL_BIT = 8;
const uint32_t MBI_CFG_AUTO_FRTL_DISABLE_BIT = 9;
const uint32_t MBI_CFG_MANUAL_FRTL_START_BIT = 10;
const uint32_t MBI_CFG_MANUAL_FRTL_END_BIT = 16;
const uint32_t MBI_CFG_MANUAL_FRTL_DONE_BIT = 17;
const uint32_t MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT = 35;
const uint32_t MBI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT = 36;

const uint8_t MBI_CFG_MANUAL_FRTL_FIELD_MASK = 0x7F;
const uint32_t MBI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK = 0x3;

// Centaur MBI Status Register field/bit definitions
const uint32_t MBI_STAT_FRAMELOCK_PASS_BIT = 0;
const uint32_t MBI_STAT_FRAMELOCK_FAIL_BIT = 1;
const uint32_t MBI_STAT_FRTL_PASS_BIT = 2;
const uint32_t MBI_STAT_FRTL_FAIL_BIT = 3;
const uint32_t MBI_STAT_CHANNEL_INTERLOCK_PASS_BIT = 13;
const uint32_t MBI_STAT_CHANNEL_INTERLOCK_FAIL_BIT = 14;

// Centaur MBI FIR Register field/bit definitions
const uint32_t MBI_FIR_DMI_CHANNEL_FAIL_BIT = 1;
const uint32_t MBI_FIR_CHANNEL_INIT_TIMEOUT_BIT = 7;
const uint32_t MBI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT = 8;
const uint32_t MBI_FIR_DATA_FLOW_PARITY_ERROR_BIT = 9;
const uint32_t MBI_FIR_GLOBAL_HOST_CHECKSTOP_BIT = 11;
const uint32_t MBI_FIR_CHANNEL_INTERLOCK_FAIL_BIT = 13;
const uint32_t MBI_FIR_LOCAL_HOST_CHECKSTOP_BIT = 14;
const uint32_t MBI_FIR_FRTL_COUNTER_OVERFLOW_BIT = 15;
const uint32_t MBI_FIR_MBICFGQ_PARITY_ERROR_BIT = 19;


///------------------------------------------------------------------------------
/// @brief      utility subroutine to clear the Centaur MBI Status Register
/// @param[in]  i_mem_target  => Centaur target
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_clear_cen_mbi_stat_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target )
{
    fapi2::buffer<uint64_t> zero_data = 0;

    FAPI_TRY(fapi2::putScom(i_mem_target, CEN_MBISTATQ, zero_data),
             "PutScom error (MBI_STAT_0x0201080B)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to get the Centaur MBI Status Register
/// @param[in]  i_mem_target  => Centaur target
/// @param[out] o_data        => Output data
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_get_cen_mbi_stat_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    fapi2::buffer<uint64_t>& o_data)
{
    FAPI_TRY(fapi2::getScom(i_mem_target, CEN_MBISTATQ, o_data),
             "GetScom error (MBI_STAT_0x0201080B)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to clear the Centaur MBI FIR Register
/// @param[in]  i_mem_target  => Centaur target
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_clear_cen_mbi_fir_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target)
{
    fapi2::buffer<uint64_t> zero_data = 0;

    FAPI_TRY(fapi2::putScom(i_mem_target, CEN_MBIFIRQ, zero_data),
             "PutScom error (MBI_FIR_0x02010800)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to get the Centaur MBI FIR Register
/// @param[in]  i_mem_target  => Centaur target
/// @param[out] o_data        => Output data
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_get_cen_mbi_fir_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    fapi2::buffer<uint64_t>& o_data)
{
    FAPI_TRY(fapi2::getScom(i_mem_target, CEN_MBIFIRQ, o_data),
             "GetScom error (MBI_FIR_0x02010800)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to clear the P9 MCI Status Register
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_clear_pu_mci_stat_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target)
{
    fapi2::buffer<uint64_t> zero_data = 0;

    FAPI_TRY(fapi2::putScom(i_pu_target, DMI_MCISTAT_0x0701090B, zero_data),
             "PutScom error (DMI_MCISTAT_0x0701090B)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to get the P9 MCI Status Register
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[out] o_data       => Output data
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_get_pu_mci_stat_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    fapi2::buffer<uint64_t>& o_data)
{

    FAPI_TRY(fapi2::getScom(i_pu_target, DMI_MCISTAT_0x0701090B, o_data),
             "GetScom error (DMI_MCISTAT_0x0701090B)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to clear the P9 Datapath FIR Register
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_clear_pu_datapath_fir_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target)
{
    fapi2::buffer<uint64_t> zero_data = 0;

    FAPI_TRY(fapi2::putScom(i_pu_target, DMI_DATAPATHFIR_0x07010900, zero_data),
             "PutScom error (DMI_DATAPATHFIR_0x07010900)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to get the P9 Datapath FIR Register
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[out] o_data       => output data
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_get_pu_datapath_fir_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    fapi2::buffer<uint64_t>& o_data)
{
    FAPI_TRY(fapi2::getScom(i_pu_target, DMI_DATAPATHFIR_0x07010900, o_data),
             "GetScom error (DMI_DATAPATHFIR_0x07010900)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to set the Centaur MBI Config Register
/// @param[in]  i_mem_target => Centaur target
/// @param[in]  i_data       => Input data
/// @param[in]  i_mask       => Input mask
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_set_cen_mbi_cfg_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& i_mask)
{
    FAPI_TRY(fapi2::putScomUnderMask(i_mem_target, CEN_MBICFGQ, i_data, i_mask),
             "PutScomUnderMask error (MBI_CFG_0x0201080A)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to set the P9 MCI Config Register
/// @param[in]  i_pu_target => P9 DMI chip unit target
/// @param[in]  i_data      => Input data
/// @param[in]  i_mask      => Input mask
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_set_pu_mci_cfg_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& i_mask)
{
    FAPI_TRY(fapi2::putScomUnderMask(i_pu_target, DMI_MCICFG_0x0701090A, i_data, i_mask),
             "PutScomUnderMask error (DMI_MCICFG_0x0701090A)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to set the Centaur MBI FIR Mask Register
/// @param[in]  i_mem_target => Centaur target
/// @param[in]  i_data       => Input data
/// @param[in]  i_mask       => Input mask
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_set_cen_mbi_firmask_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& i_mask)
{
    FAPI_TRY(fapi2::putScomUnderMask(i_mem_target, CEN_MBIFIRMASK, i_data, i_mask),
             "PutScomUnderMask error (MBI_FIRMASK_0x02010803)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to set the Centaur MBI FIR Action0 Register
/// @param[in]  i_mem_target => Centaur target
/// @param[in]  i_data       => Input data
/// @param[in]  i_mask       => Input mask
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_set_cen_mbi_firact0_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& i_mask)
{
    FAPI_TRY(fapi2::putScomUnderMask(i_mem_target, CEN_MBIFIRACT0, i_data, i_mask),
             "PutScomUnderMask error (MBI_FIRACT0_0x02010806)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to set the Centaur MBI FIR Action1 Register
/// @param[in]  i_mem_target => Centaur target
/// @param[in]  i_data       => Input data
/// @param[in]  i_mask       => Input mask
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_set_cen_mbi_firact1_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& i_mask)
{
    FAPI_TRY(fapi2::putScomUnderMask(i_mem_target, CEN_MBIFIRACT1, i_data, i_mask),
             "PutScomUnderMask error (MBI_FIRACT1_0x02010807)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to set the P9 DATAPATH FIR Mask Register
/// @param[in]  i_pu_target => P9 DMI chip unit target
/// @param[in]  i_data      => Input data
/// @param[in]  i_mask      => Input mask
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_set_pu_datapath_firmask_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& i_mask)
{
    FAPI_DBG("p9_cen_framelock_set_pu_datapath_firmask_reg: Data 0x%.16llX, Mask 0x%.16llX",
             i_data, i_mask);
    FAPI_TRY(fapi2::putScomUnderMask(i_pu_target, DMI_DATAPATHFIRMASK_0x07010903, i_data, i_mask),
             "PutScomUnderMask error (DMI_DATAPATHFIRMASK_0x07010903)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to set the P9 DATAPATH FIR Action0 Register
/// @param[in]  i_pu_target => P9 DMI chip unit target
/// @param[in]  i_data      => Input data
/// @param[in]  i_mask      => Input mask
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_set_pu_datapath_firact0_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& i_mask)
{
    FAPI_DBG("p9_cen_framelock_set_pu_datapath_firact0_reg: Data 0x%.16llX, Mask 0x%.16llX",
             i_data, i_mask);
    FAPI_TRY(fapi2::putScomUnderMask(i_pu_target, DMI_DATAPATHFIRACT0_0x07010906, i_data, i_mask),
             "PutScomUnderMask error (DMI_DATAPATHFIRACT0_0x07010906)");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to set the P9 DATAPATH FIR Action1 Register
/// @param[in]  i_pu_target => P9 DMI chip unit target
/// @param[in]  i_data      => Input data
/// @param[in]  i_mask      => Input mask
/// @return     FAPI_RC_SUCCESS if operation was successful, else error
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_set_pu_datapath_firact1_reg(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    fapi2::buffer<uint64_t>& i_data,
    fapi2::buffer<uint64_t>& i_mask)
{
    FAPI_DBG("p9_cen_framelock_set_pu_datapath_firact1_reg: Data 0x%.16llX, Mask 0x%.16llX",
             i_data, i_mask);
    FAPI_TRY(fapi2::putScomUnderMask(i_pu_target, DMI_DATAPATHFIRACT1_0x07010907, i_data, i_mask),
             "PutScomUnderMask error (DMI_DATAPATHFIRACT1_0x07010907)");

fapi_try_exit:
    return fapi2::current_err;
}

///------------------------------------------------------------------------------
/// Function definitions
///------------------------------------------------------------------------------


///------------------------------------------------------------------------------
/// @brief      utility subroutine to initiate P9/Centaur framelock operation and
///             poll for completion
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[in]  i_mem_target => Centaur chip target
/// @param[in]  i_args       => p9_cen_framelock HWP argumemt structure
/// @return     FAPI_RC_SUCCESS if framelock sequence completes successfully,
///                 RC_PROC_CEN_FRAMELOCK_FL_P9_FIR_ERR_MI
///                 RC_PROC_CEN_FRAMELOCK_FL_P9_FIR_ERR_MEMBUF
///                     if DATAPATH FIR is set during framelock operation,
///                 RC_PROC_CEN_FRAMELOCK_FL_P9_FAIL_ERR
///                     if MCI indicates framelock operation failure
///                 RC_PROC_CEN_FRAMELOCK_FL_TIMEOUT_ERR
///                     if MCI does not post pass/fail indication after framelock
///                     operation is started,
///                 else fapi2 getscom/putscom return code for failing SCOM operation
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_run_framelock(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    const p9_cen_framelock_args& i_args)
{
    // data buffers
    fapi2::buffer<uint64_t> data;
    fapi2::buffer<uint64_t> mask;
    fapi2::buffer<uint64_t> mci_stat;
    fapi2::buffer<uint64_t> datapath_fir;

    uint8_t polls = 0;

    FAPI_DBG("p9_cen_framelock_run_framelock: Starting framelock sequence ...");

    // Clear P9 DATAPATH FIR registers
    FAPI_TRY(p9_cen_framelock_clear_pu_datapath_fir_reg(i_pu_target),
             "p9_cen_framelock_run_framelock: Error clearing P9 DATAPATH FIR regs");

    // Clear P9 Status registers
    FAPI_TRY(p9_cen_framelock_clear_pu_mci_stat_reg(i_pu_target),
             "p9_cen_framelock_run_framelock: Error clearing P9 MCI Status regs");

    // set channel init timeout value in P9 DMI Configuration Register
    data.flush<0>();
    mask.flush<0>();
    data.insertFromRight < MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
                         (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT - MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1) >
                         ((uint32_t) (i_args.channel_init_timeout & MCI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK));

    mask.setBit < MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
                (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT - MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1) > ();

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_framelock: Error writing P9 MCI Configuration register to set init timeout");

    // start framelock
    data.flush<0>();
    data.setBit<MCI_CFG_START_FRAMELOCK_BIT>();
    mask = data;

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_framelock: Error writing P9 MCI Configuration register to initiate framelock");

    // poll until framelock operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    while (polls < P9_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS)
    {
        // Read P9 MCI Status Register
        FAPI_TRY(p9_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat),
                 "p9_cen_framelock_run_framelock: Error reading P9 MCI Status Register");

        // Read P9 DATAPATH FIR Register
        FAPI_TRY(p9_cen_framelock_get_pu_datapath_fir_reg(i_pu_target, datapath_fir),
                 "p9_cen_framelock_run_framelock: Error reading P9 DATAPATH FIR Register");

        // Fail if P9 MCI Frame Lock FAIL
        FAPI_ASSERT(!(mci_stat.getBit<MCI_STAT_FRAMELOCK_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_FL_P9_FAIL_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_framelock: Framelock fail. P9 MCI STAT"
                   );

        // Fail if DATAPATH FIR bits are set

        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_MCICFGQ_PARITY_ERROR_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_FL_P9_FIR_ERR_DMI()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_framelock: Framelock fail. P9 DATAPATH FIR errors set (DMI)"
                   );

        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_DMI_CHANNEL_FAIL_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CHANNEL_INIT_TIMEOUT_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_FL_P9_FIR_ERR_MEMBUF()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_framelock: Framelock fail. P9 DATAPATH FIR errors set (MEMBUF)"
                   );

        // Success if P9 PASS bits set
        if ((mci_stat.getBit<MCI_STAT_FRAMELOCK_PASS_BIT>()))
        {
            FAPI_INF("p9_cen_framelock_run_framelock: Framelock completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("p9_cen_framelock_run_framelock: Framelock not done, loop %d of %d...",
                     polls, P9_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS);

            // 1ms/100simcycles delay
            fapi2::delay(1000000, 100); //fapiDelay(nanoseconds, simcycles)

        }
    }

    FAPI_ASSERT(polls < P9_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS,
                fapi2::PROC_CEN_FRAMELOCK_FL_TIMEOUT_ERR()
                .set_MCI_STAT(mci_stat)
                .set_DATAPATH_FIR(datapath_fir)
                .set_MEMBUF_CHIP(i_mem_target)
                .set_DMI_CHIPLET(i_pu_target),
                "p9_cen_framelock_run_framelock:!!!! NO FRAME LOCK STATUS DETECTED !!!!"
               );

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to initiate P9/Centaur FRTL (frame round trip
///             latency) determination and check for completion
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[in]  i_mem_target => Centaur chip target
/// @return     FAPI_RC_SUCCESS if FRTL sequence completes successfully,
///             RC_PROC_CEN_FRAMELOCK_FRTL_P9_FIR_ERR_DMI
///             RC_PROC_CEN_FRAMELOCK_FRTL_P9_FIR_ERR_MEMBUF
///                  if DATAPATH FIR is set during FRTL operation,
///             RC_PROC_CEN_FRAMELOCK_FRTL_P9_FAIL_ERR
///                  if MCI indicates FRTL operation failure,
///             RC_PROC_CEN_FRAMELOCK_FRTL_TIMEOUT_ERR
///                  if MCI does not post pass/fail indication after FRTL
///                 operation is started,
///             else fapi2 getscom/putscom return code for failing SCOM operation
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_run_frtl(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target)
{
    // data buffers for putscom/getscom calls
    fapi2::buffer<uint64_t> data;
    fapi2::buffer<uint64_t> mask;
    fapi2::buffer<uint64_t> mci_stat;
    fapi2::buffer<uint64_t> datapath_fir;

    uint8_t polls = 0;

    // mark function entry
    FAPI_DBG("p9_cen_framelock_run_frtl: Starting FRTL sequence ...");

    // check EC feature to determine if special handling for FRTL overflow/timeout
    // should be engaged (HW418091)
    uint8_t l_hw418091;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW418091,
                           i_pu_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                           l_hw418091),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW418091");

    // start FRTL
    data.flush<0>();
    data.setBit<MCI_CFG_START_FRTL_BIT>();
    mask = data;

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_frtl: Error writing P9 MCI Configuration register to initiate FRTL");

    // Poll until FRTL operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    while (polls < P9_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        uint8_t l_frtl = 0;
        bool l_frtl_overflow = false;

        // Read P9 MCI Status Register
        FAPI_TRY(p9_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat),
                 "p9_cen_framelock_run_frtl: Error reading P9 MCI Status Register");
        // extract/process FRTL value
        mci_stat.extractToRight < MCI_FRTL_START_BIT,
                                MCI_FRTL_END_BIT - MCI_FRTL_START_BIT + 1 > (l_frtl);

        // Read P9 DATAPATH FIR Register
        FAPI_TRY(p9_cen_framelock_get_pu_datapath_fir_reg(i_pu_target, datapath_fir),
                 "p9_cen_framelock_run_frtl: Error reading P9 DATAPATH FIR Register");

        // Fail if P9 MCI FRTL FAIL or Channel Interlock Fail
        FAPI_ASSERT(!(mci_stat.getBit<MCI_STAT_FRTL_FAIL_BIT>()  ||
                      mci_stat.getBit<MCI_STAT_CHANNEL_INTERLOCK_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_FRTL_P9_FAIL_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_frtl: FRTL fail. P9 MCI STAT"
                   );

        // Fail if DATAPATH FIR bits are set
        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_MCICFGQ_PARITY_ERROR_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_FRTL_P9_FIR_ERR_DMI()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_frtl: FRTL fail. P9 FIR errors set (DMI)"
                   );

        if (l_hw418091)
        {
            FAPI_DBG("Examining FRTL for HW418091");
            l_frtl_overflow = (l_frtl == 0) ||
                              (l_frtl + P9_CEN_FRAMELOCK_FRTL_STATIC_OFFSET > P9_CEN_FRAMELOCK_FRTL_MAX_VALUE);
            FAPI_DBG("HW FRTL value: 0x%02X (0x%02X), HW FRTL overflow: %d, HWP overflow calculation: %d",
                     l_frtl,
                     (l_frtl) ? (l_frtl + P9_CEN_FRAMELOCK_FRTL_STATIC_OFFSET) : 0,
                     datapath_fir.getBit<DATAPATH_FIR_FRTL_COUNTER_OVERFLOW_BIT>() ? 1 : 0,
                     l_frtl_overflow);
        }
        else
        {
            l_frtl_overflow = datapath_fir.getBit<DATAPATH_FIR_FRTL_COUNTER_OVERFLOW_BIT>();
        }

        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_DMI_CHANNEL_FAIL_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CHANNEL_INIT_TIMEOUT_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>() ||
                      l_frtl_overflow),
                    fapi2::PROC_CEN_FRAMELOCK_FRTL_P9_FIR_ERR_MEMBUF()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target)
                    .set_FRTL_OVERFLOW(l_frtl_overflow)
                    .set_FRTL(l_frtl),
                    "p9_cen_framelock_run_frtl: FRTL fail. P9 FIR errors set (MEMBUF)"
                   );

        // Success if P9 FRTL and InterLock PASS bits are set
        if ((mci_stat.getBit<MCI_STAT_FRTL_PASS_BIT>()) &&
            (mci_stat.getBit<MCI_STAT_CHANNEL_INTERLOCK_PASS_BIT>()))
        {
            FAPI_INF("p9_cen_framelock_run_frtl: FRTL (auto) completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("p9_cen_framelock_run_frtl: FRTL not done, loop %d of %d...",
                     polls, P9_CEN_FRAMELOCK_MAX_FRTL_POLLS);

            // 1ms/100simcycles delay
            fapi2::delay(1000000, 100); //fapiDelay(nanoseconds, simcycles)
        }
    }

    FAPI_ASSERT(polls < P9_CEN_FRAMELOCK_MAX_FRTL_POLLS,
                fapi2::PROC_CEN_FRAMELOCK_FRTL_TIMEOUT_ERR()
                .set_MCI_STAT(mci_stat)
                .set_DATAPATH_FIR(datapath_fir)
                .set_MEMBUF_CHIP(i_mem_target)
                .set_DMI_CHIPLET(i_pu_target),
                "p9_cen_framelock_run_frtl:!!!! NO FRAME LOCK STATUS DETECTED !!!!"
               );

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to initiate P9/Centaur framelock operation and
///             poll for completion after the first operation fails.
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[in]  i_mem_target => Centaur chip target
/// @param[in]  i_args       => p9_cen_framelock HWP argumemt structure
/// @return     FAPI_RC_SUCCESS if framelock sequence completes successfully,
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_CEN_FIR_ERR
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P9_FIR_ERR_DMI
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P9_FIR_ERR_MEMBUF
///                 if MCI/MBI FIR is set during framelock operation,
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_CEN_FAIL_ERR
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P9_FAIL_ERR
///                 if MCI/MBI indicates framelock operation failure
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_TIMEOUT_ERR
///                 if MCI/MBI does not post pass/fail indication after framelock
///                 operation is started,
///             else fapi2 getscom/putscom return code for failing SCOM operation
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_run_errstate_framelock(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    const p9_cen_framelock_args& i_args)
{
    // data buffers
    fapi2::buffer<uint64_t> data;
    fapi2::buffer<uint64_t> mask;
    fapi2::buffer<uint64_t> mbi_stat;
    fapi2::buffer<uint64_t> mbi_fir;
    fapi2::buffer<uint64_t> mci_stat;
    fapi2::buffer<uint64_t> datapath_fir;

    uint8_t polls = 0;

    FAPI_DBG("p9_cen_framelock_run_errstate_framelock: Starting framelock Error State sequence ...");

    // Clear MBI Channel Fail Configuration Bit
    data.flush<0>();
    data.setBit<MBI_CFG_FORCE_CHANNEL_FAIL_BIT>();
    mask = data;
    data.clearBit<MBI_CFG_FORCE_CHANNEL_FAIL_BIT>();

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data,  mask),
             "p9_cen_framelock_run_errstate_framelock: Error writing Centaur MBI Configuration Register to clear the force channel fail bit");

    //Clear MCI Force Channel Fail Configuration Bit
    data.flush<0>();
    data.setBit<MCI_CFG_FORCE_CHANNEL_FAIL_BIT>();
    mask = data;
    data.clearBit<MCI_CFG_FORCE_CHANNEL_FAIL_BIT>();

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_errstate_framelock: Error writing P9 MCI Configuration register to clear the force channel fail bit");

    // Clear Centaur MBI FIR registers
    FAPI_TRY(p9_cen_framelock_clear_cen_mbi_fir_reg(i_mem_target),
             "p9_cen_framelock_run_errstate_framelock: Error clearing Centaur MBI FIR regs");

    // Clear Centaur MBI Status registers
    FAPI_TRY(p9_cen_framelock_clear_cen_mbi_stat_reg(i_mem_target),
             "p9_cen_framelock_run_errstate_framelock: Error clearing Centaur MBI Status regs");

    // Clear P9 DATAPATH FIR registers
    FAPI_TRY(p9_cen_framelock_clear_pu_datapath_fir_reg(i_pu_target),
             "p9_cen_framelock_run_errstate_framelock: Error clearing P9 DATAPATH FIR regs");

    // Clear P9 Status registers
    FAPI_TRY(p9_cen_framelock_clear_pu_mci_stat_reg(i_pu_target),
             "p9_cen_framelock_run_errstate_framelock: Error clearing P9 MCI Status regs");

    // set channel init timeout value in P9 MCI Configuration Register
    data.flush<0>();
    mask.flush<0>();
    data.insertFromRight < MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
                         (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT - MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1) >
                         ((uint32_t) (i_args.channel_init_timeout & MCI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK));

    mask.setBit < MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
                (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT - MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1) > ();

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_errstate_framelock: Error writing P9 MCI Configuration register to set init timeout");

    // start framelock on Centaur MBI
    data.flush<0>();
    data.setBit<MBI_CFG_FORCE_FRAMELOCK_BIT>();
    mask = data;

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask),
             "p9_cen_framelock_run_errstate_framelock: Error writing Centaur MBI Configuration Register to force framelock");

    // start framelock on P9 MCI
    data.flush<0>();
    data.setBit<MCI_CFG_START_FRAMELOCK_BIT>();
    mask = data;

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_errstate_framelock: Error writing P9 MCI Configuration register to initiate framelock");

    // poll until framelock operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    while (polls < P9_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS)
    {
        // Read CEN MBI Status Register
        FAPI_TRY(p9_cen_framelock_get_cen_mbi_stat_reg(i_mem_target, mbi_stat),
                 "p9_cen_framelock_run_errstate_framelock: Error reading Centaur MBI status Register");

        // Read CEN MBI FIR Register
        FAPI_TRY(p9_cen_framelock_get_cen_mbi_fir_reg(i_mem_target, mbi_fir),
                 "p9_cen_framelock_run_errstate_framelock: Error reading Centaur MBI FIR Register");

        // Read P9 MCI Status Register
        FAPI_TRY(p9_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat),
                 "p9_cen_framelock_run_errstate_framelock: Error reading P9 MCI Status Register");

        // Read P9 DATAPATH FIR Register
        FAPI_TRY(p9_cen_framelock_get_pu_datapath_fir_reg(i_pu_target, datapath_fir),
                 "p9_cen_framelock_run_errstate_framelock: Error reading P9 DATAPATH FIR Register");

        // Fail if Centaur MBI Frame Lock FAIL
        FAPI_ASSERT(!(mbi_stat.getBit<MBI_STAT_FRAMELOCK_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FL_CEN_FAIL_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_framelock: Framelock fail. Centaur MBI STAT"
                   );

        // Fail if Centaur MBI FIR bits are set
        FAPI_ASSERT(!(mbi_fir.getBit<MBI_FIR_DMI_CHANNEL_FAIL_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_CHANNEL_INIT_TIMEOUT_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_DATA_FLOW_PARITY_ERROR_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_MBICFGQ_PARITY_ERROR_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FL_CEN_FIR_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_framelock: Framelock fail. Centaur MBI FIR errors set"
                   );

        // Fail if P9 MCI Frame Lock FAIL
        FAPI_ASSERT(!(mci_stat.getBit<MCI_STAT_FRAMELOCK_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FL_P9_FAIL_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_framelock: Framelock fail. P9 MCI STAT"
                   );

        // Fail if P9 DATAPATH FIR bits are set
        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_MCICFGQ_PARITY_ERROR_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FL_P9_FIR_ERR_DMI()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_framelock: Framelock fail. P9 DATAPATH FIR errors set (DMI)"
                   );

        // Fail if P9 DATAPATH FIR bits are set
        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_DMI_CHANNEL_FAIL_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CHANNEL_INIT_TIMEOUT_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FL_P9_FIR_ERR_MEMBUF()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_framelock: Framelock fail. P9 DATAPATH FIR errors set (MEMBUF)"
                   );


        // Success if P9 and Centaur PASS bits set
        if (mbi_stat.getBit<MBI_STAT_FRAMELOCK_PASS_BIT>() &&
            (mci_stat.getBit<MCI_STAT_FRAMELOCK_PASS_BIT>()))
        {
            FAPI_INF("p9_cen_framelock_run_errstate_framelock: Framelock completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("p9_cen_framelock_run_errstate_framelock: Framelock not done, loop %d of %d...",
                     polls, P9_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS);

            // 1ms/100simcycles delay
            fapi2::delay(1000000, 100); //fapiDelay(nanoseconds, simcycles)
        }
    }

    FAPI_ASSERT(polls < P9_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS,
                fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FL_TIMEOUT_ERR()
                .set_MCI_STAT(mci_stat)
                .set_DATAPATH_FIR(datapath_fir)
                .set_MBI_STAT(mbi_stat)
                .set_MBI_FIR(mbi_fir)
                .set_MEMBUF_CHIP(i_mem_target)
                .set_DMI_CHIPLET(i_pu_target),
                "p9_cen_framelock_run_errstate_framelock:!!!! NO FRAME LOCK STATUS DETECTED !!!!");

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to initiate P9/Centaur FRTL (frame round trip
///             latency) determination and check for completion
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[in]  i_mem_target => Centaur chip target
/// @return     FAPI_RC_SUCCESS if FRTL sequence completes successfully,
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_CEN_FIR_ERR
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P9_FIR_ERR_DMI
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P9_FIR_ERR_MEMBUF
///                 if MCI/MBI FIR is set during FRTL operation,
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_CEN_FAIL_ERR
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P9_FAIL_ERR
///                 if MCI/MBI indicates FRTL operation failure,
///             RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_TIMEOUT_ERR
///                 if MCI/MBI does not post pass/fail indication after FRTL
///                 operation is started,
///             else fapi2 getscom/putscom return code for failing SCOM operation
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_run_errstate_frtl(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target)
{
    // data buffers for putscom/getscom calls
    fapi2::buffer<uint64_t> data(64);
    fapi2::buffer<uint64_t> mask(64);
    fapi2::buffer<uint64_t> mbi_stat(64);
    fapi2::buffer<uint64_t> mbi_fir(64);
    fapi2::buffer<uint64_t> mci_stat(64);
    fapi2::buffer<uint64_t> datapath_fir(64);

    uint8_t polls = 0;

    // mark function entry
    FAPI_DBG("p9_cen_framelock_run_errstate_frtl: Starting FRTL Error State sequence ...");

    // check EC feature to determine if special handling for FRTL overflow/timeout
    // should be engaged (HW418091)
    uint8_t l_hw418091;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW418091,
                           i_pu_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                           l_hw418091),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW418091");

    // if error state is set, force FRTL bit in Centaur MBI
    data.flush<0>();
    data.setBit<MBI_CFG_FORCE_FRTL_BIT>();
    mask = data;

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask),
             "p9_cen_framelock_run_errstate_frtl: Error writing Centaur MBI Configuration Register to force FRTL");

    // start FRTL
    data.flush<0>();
    data.setBit<MCI_CFG_START_FRTL_BIT>();
    mask = data;

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_errstate_frtl: Error writing P9 MCI Configuration register to initiate FRTL");

    // Poll until FRTL operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    while (polls < P9_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        uint8_t l_frtl = 0;
        bool l_frtl_overflow = false;

        // Read Centaur MBI Status Register
        FAPI_TRY(p9_cen_framelock_get_cen_mbi_stat_reg(i_mem_target, mbi_stat),
                 "p9_cen_framelock_run_errstate_frtl: Error reading Centaur MBI Status Register");
        // Read Centaur MBI FIR Register
        FAPI_TRY(p9_cen_framelock_get_cen_mbi_fir_reg(i_mem_target, mbi_fir),
                 "p9_cen_framelock_run_errstate_frtl: Error reading Centaur MBI FIR Register");

        // Read P9 MCI Status Register
        FAPI_TRY(p9_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat),
                 "p9_cen_framelock_run_errstate_frtl: Error reading P9 MCI Status Register");
        // extract/process FRTL value
        mci_stat.extractToRight < MCI_FRTL_START_BIT,
                                MCI_FRTL_END_BIT - MCI_FRTL_START_BIT + 1 > (l_frtl);

        // Read P9 DATAPATH FIR Register
        FAPI_TRY(p9_cen_framelock_get_pu_datapath_fir_reg(i_pu_target, datapath_fir),
                 "p9_cen_framelock_run_errstate_frtl: Error reading P9 DATAPATH FIR Register");

        // Fail if Centaur MBI FRTL FAIL or Channel Interlock Fail
        FAPI_ASSERT(!(mbi_stat.getBit<MBI_STAT_FRTL_FAIL_BIT>()  ||
                      mbi_stat.getBit<MBI_STAT_CHANNEL_INTERLOCK_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_CEN_FAIL_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_frtl: FRTL fail. Centaur MBI STAT");

        // Fail if Centaur MBI FIR bits are set
        FAPI_ASSERT(!(mbi_fir.getBit<MBI_FIR_DMI_CHANNEL_FAIL_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_CHANNEL_INIT_TIMEOUT_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_DATA_FLOW_PARITY_ERROR_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_FRTL_COUNTER_OVERFLOW_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_MBICFGQ_PARITY_ERROR_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_CEN_FIR_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_frtl: FRTL fail. Centaur MBI FIR errors set"
                   );

        // Fail if P9 MCI FRTL FAIL or Channel Interlock Fail
        FAPI_ASSERT(!(mci_stat.getBit<MCI_STAT_FRTL_FAIL_BIT>()  ||
                      mci_stat.getBit<MCI_STAT_CHANNEL_INTERLOCK_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P9_FAIL_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_frtl: FRTL fail. P9 MCI STAT");

        // Fail if DATAPATH FIR bits are set
        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_MCICFGQ_PARITY_ERROR_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P9_FIR_ERR_DMI()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_errstate_frtl: FRTL fail. P9 DATAPATH FIR errors set (DMI)"
                   );

        if (l_hw418091)
        {
            FAPI_DBG("Examining FRTL for HW418091");
            l_frtl_overflow = (l_frtl == 0) ||
                              (l_frtl + P9_CEN_FRAMELOCK_FRTL_STATIC_OFFSET > P9_CEN_FRAMELOCK_FRTL_MAX_VALUE);
            FAPI_DBG("HW FRTL value: 0x%02X (0x%02X), HW FRTL overflow: %d, HWP overflow calculation: %d",
                     l_frtl,
                     (l_frtl) ? (l_frtl + P9_CEN_FRAMELOCK_FRTL_STATIC_OFFSET) : 0,
                     datapath_fir.getBit<DATAPATH_FIR_FRTL_COUNTER_OVERFLOW_BIT>() ? 1 : 0,
                     l_frtl_overflow);
        }
        else
        {
            l_frtl_overflow = datapath_fir.getBit<DATAPATH_FIR_FRTL_COUNTER_OVERFLOW_BIT>();
        }

        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_DMI_CHANNEL_FAIL_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CHANNEL_INIT_TIMEOUT_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>() ||
                      l_frtl_overflow),
                    fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P9_FIR_ERR_MEMBUF()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target)
                    .set_FRTL_OVERFLOW(l_frtl_overflow)
                    .set_FRTL(l_frtl),
                    "p9_cen_framelock_run_errstate_frtl: FRTL fail. P9 DATAPATH FIR errors set (MEMBUF)"
                   );


        // Success if Centaur and P9 PASS bits set
        if ((mbi_stat.getBit<MBI_STAT_FRTL_PASS_BIT>()) &&
            (mbi_stat.getBit<MBI_STAT_CHANNEL_INTERLOCK_PASS_BIT>()) &&
            (mci_stat.getBit<MCI_STAT_CHANNEL_INTERLOCK_PASS_BIT>()) &&
            (mci_stat.getBit<MCI_STAT_FRTL_PASS_BIT>()))
        {
            FAPI_INF("p9_cen_framelock_run_errstate_frtl: FRTL (auto) completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("p9_cen_framelock_run_errstate_frtl: FRTL not done, loop %d of %d ...\n",
                     polls, P9_CEN_FRAMELOCK_MAX_FRTL_POLLS);

            // 1ms/100simcycles delay
            fapi2::delay(1000000, 100); //fapiDelay(nanoseconds, simcycles)

        }
    }

    FAPI_ASSERT(polls < P9_CEN_FRAMELOCK_MAX_FRTL_POLLS,
                fapi2::PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_TIMEOUT_ERR()
                .set_MCI_STAT(mci_stat)
                .set_DATAPATH_FIR(datapath_fir)
                .set_MBI_STAT(mbi_stat)
                .set_MBI_FIR(mbi_fir)
                .set_MEMBUF_CHIP(i_mem_target)
                .set_DMI_CHIPLET(i_pu_target),
                "p9_cen_framelock_run_errstate_frtl:!!!! NO FRAME LOCK STATUS DETECTED !!!!"
               );

fapi_try_exit:
    return fapi2::current_err;
}


///------------------------------------------------------------------------------
/// @brief      utility subroutine to initiate P9/Centaur FRTL (frame round trip
///             latency) determination and check for completion
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[in]  i_mem_target => Centaur chip target
/// @param[in]  i_args       => p9_cen_framelock HWP argumemt structure
/// @return     FAPI_RC_SUCCESS if FRTL sequence completes successfully,
///             RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_CEN_FIR_ERR
///             RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P9_FIR_ERR_DMI
///             RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P9_FIR_ERR_MEMBUF
///                 if MCI/MBI FIR is set during FRTL operation,
///             RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_CEN_FAIL_ERR
///             RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P9_FAIL_ERR
///                 if MCI/MBI indicates FRTL operation failure,
///             RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_TIMEOUT_ERR
///                 if MCI/MBI does not post pass/fail indication after FRTL
///                 operation is started,
///             else fapi2 getscom/putscom return code for failing SCOM operation
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_run_manual_frtl(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
    const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
    const p9_cen_framelock_args& i_args)
{
    // data buffers for putscom/getscom calls
    fapi2::buffer<uint64_t> data;
    fapi2::buffer<uint64_t> mask;
    fapi2::buffer<uint64_t> mbi_stat;
    fapi2::buffer<uint64_t> mbi_fir;
    fapi2::buffer<uint64_t> mci_stat;
    fapi2::buffer<uint64_t> datapath_fir;

    uint8_t polls = 0;

    // mark function entry
    FAPI_DBG("p9_cen_framelock_run_manual_frtl: Starting FRTL manual sequence ...");

    // check EC feature to determine if special handling for FRTL overflow/timeout
    // should be engaged (HW418091)
    uint8_t l_hw418091;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW418091,
                           i_pu_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                           l_hw418091),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW418091");

    // Manual mode

    // Disable auto FRTL mode & channel init timeout in Centaur MBI
    // Configuration Register
    //FAPI_DBG("p9_cen_framelock_run_manual_frtl: Writing Centaur MBI Configuration register to disable auto FRTL mode & channel init timeout ...");
    data.flush<0>();
    data.setBit<MBI_CFG_AUTO_FRTL_DISABLE_BIT>();
    mask = data;
    data.insertFromRight < MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
                         (MBI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT - MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1) >
                         ((uint32_t) (CHANNEL_INIT_TIMEOUT_NO_TIMEOUT & MBI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK));

    mask.setBit < MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
                (MBI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT - MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1) > ();

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask),
             "p9_cen_framelock_run_manual_frtl: Error writing Centaur MBI Configuration register to disable auto FRTL mode");

    // write specified FRTL value into Centaur MBI Configuration
    // Register
    //FAPI_DBG("p9_cen_framelock_run_manual_frtl: Writing Centaur MBI Configuration register to set manual FRTL value ...");
    data.flush<0>();
    mask.flush<0>();
    data.insertFromRight < MBI_CFG_MANUAL_FRTL_START_BIT,
                         (MBI_CFG_MANUAL_FRTL_END_BIT - MBI_CFG_MANUAL_FRTL_START_BIT + 1) >
                         ((uint32_t) (i_args.frtl_manual_mem & MBI_CFG_MANUAL_FRTL_FIELD_MASK));

    mask.setBit < MBI_CFG_MANUAL_FRTL_START_BIT,
                (MBI_CFG_MANUAL_FRTL_END_BIT - MBI_CFG_MANUAL_FRTL_START_BIT + 1) > ();

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask),
             "p9_cen_framelock_run_manual_frtl: Error writing Centaur MBI Configuration register to set manual FRTL value");

    // disable auto FRTL mode & channel init timeout in P9 MCI
    // Configuration Register
    data.flush<0>();
    data.setBit<MCI_CFG_AUTO_FRTL_DISABLE_BIT>();
    mask = data;
    data.insertFromRight < MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
                         (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT - MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1) >
                         ((uint32_t)(CHANNEL_INIT_TIMEOUT_NO_TIMEOUT & MCI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK));

    mask.setBit < MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
                (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT - MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1) > ();

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_manual_frtl: Error writing P9 MCI Configuration register to disable auto FRTL mode");

    // write specified FRTL value into P9 MCI Configuration Register
    data.flush<0>();
    mask.flush<0>();
    data.insertFromRight < MCI_CFG_MANUAL_FRTL_START_BIT,
                         (MCI_CFG_MANUAL_FRTL_END_BIT - MCI_CFG_MANUAL_FRTL_START_BIT + 1) >
                         ((uint32_t)(i_args.frtl_manual_pu & MCI_CFG_MANUAL_FRTL_FIELD_MASK));

    mask.setBit < MCI_CFG_MANUAL_FRTL_START_BIT,
                (MCI_CFG_MANUAL_FRTL_END_BIT - MCI_CFG_MANUAL_FRTL_START_BIT + 1) > ();

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_manual_frtl: Error writing P9 MCI Configuration register to set manual FRTL value");

    // write FRTL manual done bit into Centaur MBI Configuration
    // Register
    data.flush<0>();
    data.setBit<MBI_CFG_MANUAL_FRTL_DONE_BIT>();
    mask = data;

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask),
             "p9_cen_framelock_run_manual_frtl: Error writing Centaur MBI Configuration register to set manual FRTL done");

    // write FRTL manual done bit into P9 MCI Configuration Register
    data.flush<0>();
    data.setBit<MCI_CFG_MANUAL_FRTL_DONE_BIT>();
    mask = data;

    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask),
             "p9_cen_framelock_run_manual_frtl: Error writing P9 MCI Configuration register to set manual FRTL done");

    // Poll until FRTL operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    while (polls < P9_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        uint8_t l_frtl = 0;
        bool l_frtl_overflow = false;

        // Read Centaur MBI Status Register
        FAPI_TRY(p9_cen_framelock_get_cen_mbi_stat_reg(i_mem_target, mbi_stat),
                 "p9_cen_framelock_run_manual_frtl: Error reading Centaur MBI Status Register");

        // Read Centaur MBI FIR Register
        FAPI_TRY(p9_cen_framelock_get_cen_mbi_fir_reg(i_mem_target, mbi_fir),
                 "p9_cen_framelock_run_manual_frtl: Error reading Centaur MBI FIR Register");

        // Read P9 MCI Status Register
        FAPI_TRY(p9_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat),
                 "p9_cen_framelock_run_manual_frtl: Error reading P9 MCI Status Register");
        // extract/process FRTL value
        mci_stat.extractToRight < MCI_FRTL_START_BIT,
                                MCI_FRTL_END_BIT - MCI_FRTL_START_BIT + 1 > (l_frtl);

        // Read P9 DATAPATH FIR Register
        FAPI_TRY(p9_cen_framelock_get_pu_datapath_fir_reg(i_pu_target, datapath_fir),
                 "p9_cen_framelock_run_manual_frtl: Error reading P9 DATAPATH FIR Register");

        // Fail if Centaur MBI FRTL FAIL or Channel Interlock Fail
        FAPI_ASSERT(!(mbi_stat.getBit<MBI_STAT_FRTL_FAIL_BIT>()  ||
                      mbi_stat.getBit<MBI_STAT_CHANNEL_INTERLOCK_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_MANUAL_FRTL_CEN_FAIL_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_manual_frtl: FRTL fail. Centaur MBI STAT"
                   );

        // Fail if Centaur MBI FIR bits are set
        FAPI_ASSERT(!(mbi_fir.getBit<MBI_FIR_DMI_CHANNEL_FAIL_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_CHANNEL_INIT_TIMEOUT_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_DATA_FLOW_PARITY_ERROR_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_FRTL_COUNTER_OVERFLOW_BIT>() ||
                      mbi_fir.getBit<MBI_FIR_MBICFGQ_PARITY_ERROR_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_MANUAL_FRTL_CEN_FIR_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_manual_frtl: FRTL fail. Centaur MBI FIR errors set"
                   );

        // Fail if P9 MCI FRTL FAIL or Channel Interlock Fail
        FAPI_ASSERT(!(mci_stat.getBit<MCI_STAT_FRTL_FAIL_BIT>()  ||
                      mci_stat.getBit<MCI_STAT_CHANNEL_INTERLOCK_FAIL_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_MANUAL_FRTL_P9_FAIL_ERR()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_manual_frtl: FRTL fail. P9 MCI STAT"
                   );


        // Fail if DATAPATH FIR bits are set
        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_MCICFGQ_PARITY_ERROR_BIT>()),
                    fapi2::PROC_CEN_FRAMELOCK_MANUAL_FRTL_P9_FIR_ERR_DMI()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target),
                    "p9_cen_framelock_run_manual_frtl: FRTL fail. P9 DATAPATH FIR errors set (DMI)"
                   );

        if (l_hw418091)
        {
            FAPI_DBG("Examining FRTL for HW418091");
            l_frtl_overflow = (l_frtl == 0) ||
                              (l_frtl + P9_CEN_FRAMELOCK_FRTL_STATIC_OFFSET > P9_CEN_FRAMELOCK_FRTL_MAX_VALUE);
            FAPI_DBG("HW FRTL value: 0x%02X (0x%02X), HW FRTL overflow: %d, HWP overflow calculation: %d",
                     l_frtl,
                     (l_frtl) ? (l_frtl + P9_CEN_FRAMELOCK_FRTL_STATIC_OFFSET) : 0,
                     datapath_fir.getBit<DATAPATH_FIR_FRTL_COUNTER_OVERFLOW_BIT>() ? 1 : 0,
                     l_frtl_overflow);
        }
        else
        {
            l_frtl_overflow = datapath_fir.getBit<DATAPATH_FIR_FRTL_COUNTER_OVERFLOW_BIT>();
        }

        FAPI_ASSERT(!(datapath_fir.getBit<DATAPATH_FIR_DMI_CHANNEL_FAIL_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CHANNEL_INIT_TIMEOUT_BIT>() ||
                      datapath_fir.getBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>() ||
                      l_frtl_overflow),
                    fapi2::PROC_CEN_FRAMELOCK_MANUAL_FRTL_P9_FIR_ERR_MEMBUF()
                    .set_MCI_STAT(mci_stat)
                    .set_DATAPATH_FIR(datapath_fir)
                    .set_MBI_STAT(mbi_stat)
                    .set_MBI_FIR(mbi_fir)
                    .set_MEMBUF_CHIP(i_mem_target)
                    .set_DMI_CHIPLET(i_pu_target)
                    .set_FRTL_OVERFLOW(l_frtl_overflow)
                    .set_FRTL(l_frtl),
                    "p9_cen_framelock_run_manual_frtl: FRTL fail. P9 DATAPATH FIR errors set (MEMBUF)"
                   );

        // Success if Centaur and P9 PASS bits set
        if ((mbi_stat.getBit<MBI_STAT_FRTL_PASS_BIT>()) &&
            (mbi_stat.getBit<MBI_STAT_CHANNEL_INTERLOCK_PASS_BIT>()) &&
            (mci_stat.getBit<MCI_STAT_CHANNEL_INTERLOCK_PASS_BIT>()) &&
            (mci_stat.getBit<MCI_STAT_FRTL_PASS_BIT>()))
        {
            FAPI_INF("p9_cen_framelock_run_manual_frtl: FRTL (manual) completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("p9_cen_framelock_run_manual_frtl: FRTL not done, loop %d of %d...\n",
                     polls, P9_CEN_FRAMELOCK_MAX_FRTL_POLLS);

            // 1ms/100simcycles delay
            fapi2::delay(1000000, 100); //fapiDelay(nanoseconds, simcycles)

        }
    }

    FAPI_ASSERT(polls < P9_CEN_FRAMELOCK_MAX_FRTL_POLLS,
                fapi2::PROC_CEN_FRAMELOCK_MANUAL_FRTL_TIMEOUT_ERR()
                .set_MCI_STAT(mci_stat)
                .set_DATAPATH_FIR(datapath_fir)
                .set_MBI_STAT(mbi_stat)
                .set_MBI_FIR(mbi_fir)
                .set_MEMBUF_CHIP(i_mem_target)
                .set_DMI_CHIPLET(i_pu_target),
                "p9_cen_framelock_run_manual_frtl:!!!! NO FRAME LOCK STATUS DETECTED !!!!"
               );

fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// The Main Hardware Procedure
// ##################################################
// The frame lock procedure initializes the Centaur DMI memory channel.  In the
// event of errors, it will attempt to rerun the procedure.  There will be up to 3 attempts
// at initialization before giving up.  This procedure assumes the DMI/EDI channel training
// states completed successfully and that the DMI fence was lowered.
//
// When the procedure is first run, NO SCOM will be performed on Centaur.  All the scom accesses
// are limited to P9.  This allows for very fast initialization of the channels.  However,
// if the initialization does encounter a fail event, the procedure will make a second (if necessary,
// a third attempt) at intializing the channel.  The second and third attempts require scoms to both
// P9 and Centaur chips.
//
//


//------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock(const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
                                   const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
                                   const p9_cen_framelock_args& i_args)
{
    FAPI_TRY(p9_cen_framelock_cloned(i_pu_target, i_mem_target, i_args));

    // If mss_unmask_inband_errors gets it's own bad rc,
    // it will commit the passed in rc (if non-zero), and return it's own bad rc.
    // Else if mss_unmask_inband_errors runs clean,
    // it will just return the passed in rc.
    //l_rc = mss_unmask_inband_errors(i_mem_target, l_rc);

fapi_try_exit:
    return fapi2::current_err;
}

///------------------------------------------------------------------------------
/// @brief      Execute P9/Centaur framelock exit procedure by setting the MCI
//              and MBI fir action and mask registers according to PRD requirements.
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[in]  i_mem_target => Centaur chip target
/// @return     FAPI2_RC_SUCCESS if exit procedure sequence completes successfully,
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_exit_procedure(const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target)
{
    fapi2::buffer<uint64_t> mbi_data;
    fapi2::buffer<uint64_t> mbi_mask;
    fapi2::buffer<uint64_t> l_action0_data;
    fapi2::buffer<uint64_t> l_action1_data;
    fapi2::buffer<uint64_t> l_dataPathFirMask;
    fapi2::buffer<uint64_t> l_mci_data;
    fapi2::buffer<uint64_t> l_writeMask;

    // check EC feature to determine if special handling for UE/SUE errors
    // should be engaged (HW414700)
    uint8_t l_hw414700;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700,
                           i_pu_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                           l_hw414700),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW414700");

    // (Action0, Action1, Mask)
    // ------------------------
    // (0,0,0) = Checkstop Error
    // (0,1,0) = Recoverable Error
    // (1,0,0) = Attention
    // (1,1,0) = Local Checkstop Error
    // (x,x,1) = MASKED
    // Clear FIR register before exiting procedure

    // Clear P9 DATAPATH FIR registers
    FAPI_TRY(p9_cen_framelock_clear_pu_datapath_fir_reg(i_pu_target),
             "p9_cen_framelock: Error clearing P9 DATAPATH FIR regs");

    // Clear Centaur MBI FIR registers
    FAPI_TRY(p9_cen_framelock_clear_cen_mbi_fir_reg(i_mem_target),
             "p9_cen_framelock: Error clearing Centaur MBI FIR regs");

    // ----------------------------------
    // Set DATAPATH FIR ACTION0 & ACTION1
    // ----------------------------------

    // UNIT_CS if a checkstop was received from Centaur (Bit 16)
    l_action0_data.setBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>();
    l_action1_data.setBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>();

    // HOST_ATTN if special attention was received from Centaur (Bit 20)
    l_action0_data.setBit<DATAPATH_FIR_CENTAUR_SPECIAL_ATTN_FAIL_BIT>();

    // Recoverable errors
    l_action1_data.setBit<DATAPATH_FIR_SCOM_WR_PERR_BIT>()       // Bit 0
    .setBit<DATAPATH_FIR_MCICFGQ_PARITY_ERROR_BIT>()             // Bit 1
    .setBit<DATAPATH_FIR_DSRC_NO_FORWARD_PROGRESS_BIT>()         // Bit 2
    .setBit<DATAPATH_FIR_DSRC_PERF_DEGRAD_BIT>()                 // Bit 3
    .setBit<DATAPATH_FIR_CRC_ERR_BIT>()                          // Bit 8
    .setBit<DATAPATH_FIR_REPLAY_BUFFER_CE_BIT>()                 // Bit 11
    .setBit<DATAPATH_FIR_REPLAY_BUFFER_UE_BIT>()                 // Bit 12
    .setBit<DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT>()           // Bit 15
    .setBit<DATAPATH_FIR_CENTAUR_RECOVERABLE_FAIL_BIT>()         // Bit 19
    .setBit<DATAPATH_FIR_USFD_CHANFAIL_SEQ_ERROR_BIT>()          // Bit 31
    .setBit<DATAPATH_FIR_SFF_DS_DATA_ERROR_DETECTED_BIT>()       // Bit 33
    .setBit<DATAPATH_FIR_RDATA_PERR_BIT>()                       // Bit 36
    .setBit<DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_PERR_BIT>()     // Bit 40
    .setBit<DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_SEQERR_BIT>()   // Bit 41
    .setBit<DATAPATH_FIR_DSFF_SEQ_ERROR_BIT>()                   // Bit 42
    .setBit<DATAPATH_FIR_RECOVERABLE_PERR_EICR_BIT>()            // Bit 43
    .setBit<DATAPATH_FIR_FATAL_PERR_RECR_BIT>()                  // Bit 44
    .setBit<DATAPATH_FIR_WRT_RMW_BUFFER_CE_BIT>()                // Bit 45
    .setBit<DATAPATH_FIR_WRT_RMW_BUFFER_UE_BIT>()                // Bit 46
    .setBit<DATAPATH_FIR_WDF_OVERRUN_ERR_BIT0>()                 // Bit 48
    .setBit<DATAPATH_FIR_WDF_OVERRUN_ERR_BIT1>()                 // Bit 49
    .setBit<DATAPATH_FIR_WDF_SCOM_SEQ_ERR_BIT>()                 // Bit 50
    .setBit<DATAPATH_FIR_WDF_SM_ERR_BIT>()                       // Bit 51
    .setBit<DATAPATH_FIR_WDF_REG_PERR_BIT>()                     // Bit 52
    .setBit<DATAPATH_FIR_WRT_SCOM_SEQ_ERR_BIT>()                 // Bit 53
    .setBit<DATAPATH_FIR_WRT_REG_PERR_BIT>()                     // Bit 54
    .setBit<DATAPATH_FIR_READ_BUF_OVERRUN_BIT>()                 // Bit 56
    .setBit<DATAPATH_FIR_WDF_ASYNC_ERR_BIT>()                    // Bit 57
    .setBit<DATAPATH_FIR_READ_MCA_PERR_BIT>()                    // Bit 58
    .setBit<DATAPATH_FIR_READ_MCA_SEQ_ERR_BIT>()                 // Bit 59
    .setBit<DATAPATH_FIR_DBGWAT_PERR_BIT>()                      // Bit 60
    .setBit<DATAPATH_FIR_DSFF_TIMEOUT_BIT>();                    // Bit 61

    // Checkstop errors
    if (l_hw414700)
    {
        l_action0_data.clearBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>();  // Bit 16

        l_action1_data.clearBit<DATAPATH_FIR_DSRC_NO_FORWARD_PROGRESS_BIT>() // Bit 2
        .clearBit<DATAPATH_FIR_DMI_CHANNEL_FAIL_BIT>()                       // Bit 4
        .clearBit<DATAPATH_FIR_CHANNEL_INIT_TIMEOUT_BIT>()                   // Bit 5
        .clearBit<DATAPATH_FIR_CHANNEL_INTERLOCK_FAIL_BIT>()                 // Bit 6
        .clearBit<DATAPATH_FIR_CRC_ERR_BIT>()                                // Bit 8
        .clearBit<DATAPATH_FIR_REPLAY_BUFFER_UE_BIT>()                       // Bit 12
        .clearBit<DATAPATH_FIR_REPLAY_BUFFER_OVERRUN_BIT>()                  // Bit 14
        .clearBit<DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT>()                 // Bit 15
        .clearBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>()                 // Bit 16
        .clearBit<DATAPATH_FIR_DSFF_TAG_OVERRUN_BIT>()                       // Bit 32
        .clearBit<DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_PERR_BIT>()           // Bit 40
        .clearBit<DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_SEQERR_BIT>()         // Bit 41
        .clearBit<DATAPATH_FIR_DSFF_SEQ_ERROR_BIT>()                         // Bit 42
        .clearBit<DATAPATH_FIR_DSFF_TIMEOUT_BIT>();                          // Bit 61
    }

    // ----------------------------------
    // Set P9 DATAPATH FIR Mask
    // ----------------------------------

    // Any bit that is set in ACTION0 or ACTION1 reg means we want
    // recoverable/attention/unit_cs, so need to clear its mask.
    // This should clear the mask bits for these scenarios:
    // (0,1,0) = Recoverable Error
    // (1,0,0) = Attention
    // (1,1,0) = UNIT_CS
    l_dataPathFirMask = ~(l_action0_data | l_action1_data);

    // Any bit that is clear in both ACTION0 & ACTION1 reg, but
    // we want to have a checkstop, we need to explicitly clear
    // the mask bit.
    // (0,0,0) = Checkstop Error
    if (l_hw414700)
    {
        l_dataPathFirMask.clearBit<DATAPATH_FIR_DSRC_NO_FORWARD_PROGRESS_BIT>() // Bit 2
        .clearBit<DATAPATH_FIR_DMI_CHANNEL_FAIL_BIT>()                          // Bit 4
        .clearBit<DATAPATH_FIR_CHANNEL_INIT_TIMEOUT_BIT>()                      // Bit 5
        .clearBit<DATAPATH_FIR_CHANNEL_INTERLOCK_FAIL_BIT>()                    // Bit 6
        .clearBit<DATAPATH_FIR_CRC_ERR_BIT>()                                   // Bit 8
        .clearBit<DATAPATH_FIR_REPLAY_BUFFER_UE_BIT>()                          // Bit 12
        .clearBit<DATAPATH_FIR_REPLAY_BUFFER_OVERRUN_BIT>()                     // Bit 14
        .clearBit<DATAPATH_FIR_DATA_FLOW_PARITY_ERROR_BIT>()                    // Bit 15
        .clearBit<DATAPATH_FIR_CENTAUR_CHECKSTOP_FAIL_BIT>()                    // Bit 16
        .clearBit<DATAPATH_FIR_DSFF_TAG_OVERRUN_BIT>()                          // Bit 32
        .clearBit<DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_PERR_BIT>()              // Bit 40
        .clearBit<DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_SEQERR_BIT>()            // Bit 41
        .clearBit<DATAPATH_FIR_DSFF_SEQ_ERROR_BIT>()                            // Bit 42
        .clearBit<DATAPATH_FIR_DSFF_TIMEOUT_BIT>();                             // Bit 61
    }

    //TODO: To be removed, see SW413273
    l_dataPathFirMask.setBit<DATAPATH_FIR_SFF_MCA_ASYNC_CMD_ERROR_SEQERR_BIT>();

    // Write to ACTION0 reg
    l_writeMask = l_action0_data;
    FAPI_TRY(p9_cen_framelock_set_pu_datapath_firact0_reg(i_pu_target, l_action0_data, l_writeMask),
             "p9_cen_framelock: Error writing P9 DATAPATH FIR Action0 Register");

    // Write to ACTION1 reg
    l_writeMask = l_action1_data;
    FAPI_TRY(p9_cen_framelock_set_pu_datapath_firact1_reg(i_pu_target, l_action1_data, l_writeMask),
             "p9_cen_framelock: Error writing P9 DATAPATH FIR Action0 Register");

    // Write to DATAPATH FIR MASK reg
    l_writeMask = (l_action0_data | l_action1_data);
    FAPI_TRY(p9_cen_framelock_set_pu_datapath_firmask_reg(i_pu_target, l_dataPathFirMask, l_writeMask),
             "p9_cen_framelock: Error writing P9 DATAPATH FIR Mask Register");

    // ------------------------------------------------
    // Config attn to be host for CHI's FIRs
    // (In HB only, Cronus host machine doesn't have
    // code to handle attn)
    // -----------------------------------------------
#ifdef __HOSTBOOT_MODULE
    l_mci_data.flush<0>().setBit<MCI_CFG_MCICFGQ_SPEC_MODE>()
    .setBit<MCI_CFG_MCICFGQ_HOST_MODE>();
    l_writeMask = l_mci_data;
    l_mci_data.clearBit<MCI_CFG_MCICFGQ_SPEC_MODE>();
    FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, l_mci_data, l_writeMask),
             "p9_cen_framelock: Error writing P9 MCI Configuration register to set CHI's FIRs mode.");
#endif

    // Set Centaur DATAPATH FIR Mask
    mbi_data.flush<0>();
    mbi_data.setBit<0>();     //Replay Timeout
    mbi_data.setBit<5>();     //Replay Buffer CE
    mbi_data.setBit<6>();     //Replay Buffer UE
    mbi_data.setBit<8>();     //MBI Internal Control Parity Error
    mbi_data.setBit<9>();     //MBI Data Flow Parity Error
    mbi_data.setBit<10>();    //CRC Performance Degradation
    mbi_data.setBit<16>();    //SCOM Register parity
    mbi_data.setBit<19>();    //MBICFGQ Parity Error
    mbi_data.setBit<20>();    //Replay Buffer Overrun Error
    mbi_data.setBit<25>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE: Internal SCOM Error Clone
    mbi_data.setBit<26>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE_COPY: Internal SCOM Error Clone copy
    mbi_mask = mbi_data;

    mbi_data.clearBit<0>();     //Replay Timeout
    mbi_data.clearBit<5>();     //Replay Buffer CE
    mbi_data.clearBit<6>();     //Replay Buffer UE
    mbi_data.clearBit<8>();     //MBI Internal Control Parity Error
    mbi_data.clearBit<9>();     //MBI Data Flow Parity Error
    mbi_data.clearBit<10>();    //CRC Performance Degradation
    mbi_data.clearBit<16>();    //SCOM Register parity
    mbi_data.clearBit<19>();    //MBICFGQ Parity Error
    mbi_data.clearBit<20>();    //Replay Buffer Overrun Error
    mbi_data.clearBit<25>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE: Internal SCOM Error Clone
    mbi_data.clearBit<26>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE_COPY: Internal SCOM Error Clone copy

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_firmask_reg(i_mem_target, mbi_data, mbi_mask),
             "p9_cen_framelock: Error writing Centaur MBI Fir Mask Register");

    // Bit set For Centaur
    // No Bits are set in CEN MBI FIR ACT0

    // Set CEN MBI FIR ACT1
    mbi_data.flush<0>();
    mbi_data.clearBit<4>();   //Seqid OOO
    mbi_data.setBit<5>();     //Replay Buffer CE
    mbi_data.setBit<10>();    //CRC Performance Degradation
    mbi_data.setBit<16>();    //Scom Register parity error
    mbi_data.setBit<25>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE: Internal SCOM Error Clone
    mbi_data.setBit<26>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE_COPY: Internal SCOM Error Clone copy
    mbi_mask = mbi_data;

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_firact1_reg(i_mem_target, mbi_data, mbi_mask),
             "p9_cen_framelock: Error writing Centaur MBI Fir Action1 Register");

    // Set Centaur MBI FIR Mask
    mbi_data.flush<0>();
    mbi_data.setBit<0>();     //Replay Timeout
    mbi_data.setBit<5>();     //Replay Buffer CE
    mbi_data.setBit<6>();     //Replay Buffer UE
    mbi_data.setBit<8>();     //MBI Internal Control Parity Error
    mbi_data.setBit<9>();     //MBI Data Flow Parity Error
    mbi_data.setBit<10>();    //CRC Performance Degradation
    mbi_data.setBit<16>();    //SCOM Register parity
    mbi_data.setBit<19>();    //MBICFGQ Parity Error
    mbi_data.setBit<20>();    //Replay Buffer Overrun Error
    mbi_data.setBit<25>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE: Internal SCOM Error Clone
    mbi_data.setBit<26>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE_COPY: Internal SCOM Error Clone copy
    mbi_mask = mbi_data;
    mbi_data.clearBit<0>();     //Replay Timeout
    mbi_data.clearBit<5>();     //Replay Buffer CE
    mbi_data.clearBit<6>();     //Replay Buffer UE
    mbi_data.clearBit<8>();     //MBI Internal Control Parity Error
    mbi_data.clearBit<9>();     //MBI Data Flow Parity Error
    mbi_data.clearBit<10>();    //CRC Performance Degradation
    mbi_data.clearBit<16>();    //SCOM Register parity
    mbi_data.clearBit<19>();    //MBICFGQ Parity Error
    mbi_data.clearBit<20>();    //Replay Buffer Overrun Error
    mbi_data.clearBit<25>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE: Internal SCOM Error Clone
    mbi_data.clearBit<26>();    //MBIFIRQ_INTERNAL_SCOM_ERROR_CLONE_COPY: Internal SCOM Error Clone copy

    FAPI_TRY(p9_cen_framelock_set_cen_mbi_firmask_reg(i_mem_target, mbi_data, mbi_mask),
             "p9_cen_framelock: Error writing Centaur MBI Fir Mask Register");

fapi_try_exit:
    return fapi2::current_err;
}

///------------------------------------------------------------------------------
/// @brief      Execute P9/Centaur framelock and FRTL operations
/// @param[in]  i_pu_target  => P9 DMI chip unit target
/// @param[in]  i_mem_target => Centaur chip target
/// @param[in]  i_args       => p9_cen_framelock HWP argumemt structure
/// @return     FAPI2_RC_SUCCESS if framelock/FRTL sequence completes successfully,
///             or error from p9_cen_framelock_errors.xml
///             else FAPI getscom/putscom return code for failing operation
///------------------------------------------------------------------------------
fapi2::ReturnCode p9_cen_framelock_cloned(const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_pu_target,
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mem_target,
        const p9_cen_framelock_args& i_args)
{

// data buffers for putscom/getscom calls
    fapi2::buffer<uint64_t> mci_data;
    fapi2::buffer<uint64_t> mbi_data;
    fapi2::buffer<uint64_t> mci_mask;
    fapi2::buffer<uint64_t> mbi_mask;

    fapi2::ReturnCode l_rc;

    // mark HWP entry
    FAPI_DBG("p9_cen_framelock: Entering ...");

    // validate arguments
    FAPI_ASSERT(i_args.frtl_manual_mem < MBI_CFG_MANUAL_FRTL_FIELD_MASK,
                fapi2::PROC_CEN_FRAMELOCK_INVALID_ARGS().set_ARGS(i_args),
                "p9_cen_framelock: Out of range value %d presented for manual FRTL mem argument value!",
                i_args.frtl_manual_mem
               );

    FAPI_ASSERT(i_args.frtl_manual_pu < MCI_CFG_MANUAL_FRTL_FIELD_MASK,
                fapi2::PROC_CEN_FRAMELOCK_INVALID_ARGS().set_ARGS(i_args),
                "p9_cen_framelock: Out of range value %d presented for manual FRTL pu argument value!",
                i_args.frtl_manual_pu
               );


    // Execute Framelock
    l_rc = p9_cen_framelock_run_framelock(i_pu_target, i_mem_target, i_args);
    FAPI_DBG("exit p9_cen_framelock");

    if (!l_rc)
    {
        // Execute FRTL
        if (i_args.frtl_auto_not_manual)
        {
            l_rc = p9_cen_framelock_run_frtl(i_pu_target, i_mem_target);
        }
        else
        {
            l_rc = p9_cen_framelock_run_manual_frtl(i_pu_target, i_mem_target,
                                                    i_args);
        }
    }

    if (l_rc)
    {
        // The regular framelock/frtl failed, retry up to twice using the
        // errorstate functions
        fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);// record last error
        FAPI_DBG("p9_cen_framelock fail");
        const uint8_t NUM_FRAMELOCK_ERR_RETRIES = 2;

        for (uint8_t i = 0; i < NUM_FRAMELOCK_ERR_RETRIES; i++)
        {
            // Force MBI in Channel Fail State
            mbi_data.flush<0>();
            mbi_data.setBit<MBI_CFG_FORCE_CHANNEL_FAIL_BIT>();
            mbi_mask = mbi_data;

            FAPI_TRY(p9_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, mbi_data,  mbi_mask),
                     "p9_cen_framelock: Error writing Centaur MBI Configuration Register to force framelock");

            //Force MCI in Channel Fail State
            mci_data.flush<0>();
            mci_data.setBit<MCI_CFG_FORCE_CHANNEL_FAIL_BIT>();
            mci_mask = mci_data;

            FAPI_TRY(p9_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, mci_data, mci_mask),
                     "p9_cen_framelock: Error writing P9 MCI Configuration register to force MCI in channel fail state");

            // 1ms/100simcycles delay
            fapi2::delay(1000000, 100); //fapiDelay(nanoseconds, simcycles)

            // Execute errorstate Framelock
            l_rc = p9_cen_framelock_run_errstate_framelock(i_pu_target,
                    i_mem_target,
                    i_args);

            // Log error from framelock reset as informational
            if (l_rc)
            {
                fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
            }

            // In error state attempt FRTL although FL might have failed

            if (i_args.frtl_auto_not_manual)
            {
                l_rc = p9_cen_framelock_run_errstate_frtl(i_pu_target,
                        i_mem_target);
            }
            else
            {
                l_rc = p9_cen_framelock_run_manual_frtl(i_pu_target,
                                                        i_mem_target,
                                                        i_args);
            }

            if (!l_rc)
            {
                // Success, break out of retry loop
                break;
            }
        }
    }

    if (!l_rc)
    {
        // EXIT Procedure
        // by setting the MCI and MBI fir action and mask registers according to PRD requirements.
        FAPI_TRY(p9_cen_framelock_exit_procedure(i_pu_target, i_mem_target));
    }

    // mark HWP exit
    FAPI_DBG("p9_cen_framelock: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
