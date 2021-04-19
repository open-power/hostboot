/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_ocb_init.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file  p10_pm_ocb_init.C
/// @brief Setup and configure OCB channels
///
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 3
// *HWP Consumed by     : SBE:HS

///   High-level procedure flow:
///
///   - if mode = PM_START
///     - placeholder - currently do nothing
///   - if mode = PM_HALT
///     - reset each register in each OCB channel to its scan0-flush state
///   - if mode = PM_SETUP_PIB or PM_SETUP_ALL
///     - process parameters passed to procedure
///     - Set up channel control/status register based on passed parameters
///       (OCBCSRn)
///     - Set Base Address Register
///       - linear streaming & non-streaming => OCBARn
///       - push queue                       => OCBSHBRn  (only if PM_SETUP_ALL)
///       - pull queue                       => OCBSLBRn  (only if PM_SETUP_ALL)
///     - Set up queue control and status register (only if PM_SETUP_ALL)
///       - push queue  => OCBSHCSn
///       - pull queue  => OCBSLCSn
///
///   Procedure Prerequisite:
///   - System clocks are running
///

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <p10_pm_ocb_init.H>
#include <p10_scom_proc.H>

using namespace scomt::proc;

//------------------------------------------------------------------------------
// CONSTANTS
//------------------------------------------------------------------------------
enum PM_OCB_CONST
{
    MAX_OCB_QUE_LEN = 31,   // Max length of PULL/PUSH queue
};

// channel register arrrays
const uint64_t OCBARn[4]       = {TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR0,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR1,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR2,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBAR3
                                 };

const uint64_t OCBCSRn_CLEAR[4] = {TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_CLEAR,
                                   TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_CLEAR,
                                   TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_CLEAR,
                                   TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_CLEAR
                                  };

const uint64_t OCBCSRn_OR[4]   = {TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR0_WO_OR,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR1_WO_OR,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR2_WO_OR,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBCSR3_WO_OR
                                 };

const uint64_t OCBESRn[4]      = {TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR0,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR1,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR2,
                                  TP_TPCHIP_OCC_OCI_OCB_PIB_OCBESR3
                                 };

const uint64_t OCBSLBRn[4]     = {TP_TPCHIP_OCC_OCI_OCB_OCBSLBR0,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSLBR1,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSLBR2,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSLBR3
                                 };

const uint64_t OCBSHBRn[4]     = {TP_TPCHIP_OCC_OCI_OCB_OCBSHBR0,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSHBR1,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSHBR2,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSHBR3
                                 };

const uint64_t OCBSLCSn[4]     = {TP_TPCHIP_OCC_OCI_OCB_OCBSLCS0,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSLCS1,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSLCS2,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSLCS3
                                 };

const uint64_t OCBSHCSn[4]     = {TP_TPCHIP_OCC_OCI_OCB_OCBSHCS0,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSHCS1,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSHCS2,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSHCS3
                                 };

const uint64_t OCBSESn[4]      = {TP_TPCHIP_OCC_OCI_OCB_OCBSES0,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSES1,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSES2,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBSES3
                                 };

const uint64_t OCBLWCRn[4]     = {TP_TPCHIP_OCC_OCI_OCB_OCBLWCR0,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBLWCR1,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBLWCR2,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBLWCR3
                                 };

const uint64_t OCBLWSBRn[4]    = {TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR0,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR1,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR2,
                                  TP_TPCHIP_OCC_OCI_OCB_OCBLWSBR3
                                 };

//------------------------------------------------------------------------------
//  Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Reset OCB Channels to default state (ie. scan-0 flush state)
///
/// @param [in]   i_target          Chip Target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_ocb_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Init specified channel to type specified
///
/// @param [in]   i_target         Chip Target
///
/// @param [in]   i_ocb_chan       Channel to setup from enum PM_OCB_CHAN_NUM.
///                                OCB_CHAN0 : OCB  Channel 0
///                                OCB_CHAN1 : OCB  Channel 1
///                                OCB_CHAN2 : OCB  Channel 2
///                                OCB_CHAN3 : OCB  Channel 3
///
/// @param [in]   i_ocb_type       Type of channel from PM_OCB_CHAN_TYPE.
///                                OCB_TYPE_LIN:Linear w/o address increment
///                                OCB_TYPE_LINSTR:Linear with address increment
///                                OCB_TYPE_CIRC:Circular mode
///                                OCB_TYPE_PUSHQ:Circular Push Queue
///                                OCB_TYPE_PULLQ:Circular Pull Queue
///
/// @param [in]   i_ocb_bar        32-bit channel base address(29 bits + "000")
///
/// @param [in]   i_ocb_upd_reg    Type of register to init 'PM_OCB_CHAN_REG'
///                                OCB_UPD_PIB_REG:Update PIB Register
///                                OCB_UPD_PIB_OCI_REG:Update OCI+PIB Registers
///
/// @param [in]   i_ocb_q_len      0-31 length of push or pull queue in
///                                (queue_length + 1) * 8B
///
/// @param [in]   i_ocb_ouflow_en  Channel flow control from PM_OCB_CHAN_OUFLOW
///                                OCB_Q_OUFLOW_EN:Overflow/Underflow Enable
///                                OCB_Q_OUFLOW_DIS:Overflow/Underflow Disable
///
/// @param [in]   i_ocb_itp_type   Channel interrupt control from PM_OCB_ITPTYPE
///                                OCB_Q_ITPTYPE_FULL:Interrupt on Full
///                                OCB_Q_ITPTYPE_NOTFULL:Interrupt on Not Full
///                                OCB_Q_ITPTYPE_EMPTY:Interrupt on Empty
///                                OCB_Q_ITPTYPE_NOTEMPTY:Interrupt on Not Empty
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_ocb_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const ocb::PM_OCB_CHAN_NUM    i_ocb_chan,
    const ocb::PM_OCB_CHAN_TYPE   i_ocb_type,
    const uint32_t                i_ocb_bar,
    const ocb::PM_OCB_CHAN_REG    i_ocb_upd_reg,
    const uint8_t                 i_ocb_q_len,
    const ocb::PM_OCB_CHAN_OUFLOW i_ocb_ouflow_en,
    const ocb::PM_OCB_ITPTYPE     i_ocb_itp_type);

//------------------------------------------------------------------------------
//  Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p10_pm_ocb_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE        i_mode,
    const ocb::PM_OCB_CHAN_NUM    i_ocb_chan,
    const ocb::PM_OCB_CHAN_TYPE   i_ocb_type,
    const uint32_t                i_ocb_bar,
    const uint8_t                 i_ocb_q_len,
    const ocb::PM_OCB_CHAN_OUFLOW i_ocb_ouflow_en,
    const ocb::PM_OCB_ITPTYPE     i_ocb_itp_type)
{
    FAPI_INF("> p10_pm_ocb_init");

    // -------------------------------------------------------------------------
    // INIT mode: Placeholder; NOOP at present
    // -------------------------------------------------------------------------
    if (i_mode == pm::PM_START)
    {
        FAPI_DBG(" Channel initialization is a no-op.");
    }
    // -------------------------------------------------------------------------
    // RESET mode: Change the OCB channel registers to scan-0 flush state
    // -------------------------------------------------------------------------
    else if (i_mode == pm::PM_HALT)
    {
        FAPI_DBG("  Resetting OCB Indirect Channels");
        FAPI_TRY(pm_ocb_reset(i_target), "ERROR: OCB Reset failed.");
    }
    // -------------------------------------------------------------------------
    // SETUP mode: Perform user setup of an indirect channel
    // -------------------------------------------------------------------------
    else if (i_mode == pm::PM_SETUP_ALL || i_mode == pm::PM_SETUP_PIB)
    {
        FAPI_INF("  Setup OCB Indirect Channel %d ", i_ocb_chan);
        ocb::PM_OCB_CHAN_REG l_upd_reg = ocb::OCB_UPD_PIB_REG;

        if (i_mode == pm::PM_SETUP_ALL)
        {
            l_upd_reg = ocb::OCB_UPD_PIB_OCI_REG;
        }

        FAPI_TRY(pm_ocb_setup(i_target, i_ocb_chan, i_ocb_type, i_ocb_bar,
                              l_upd_reg, i_ocb_q_len, i_ocb_ouflow_en,
                              i_ocb_itp_type),
                 "ERROR: OCB Setup failed.");
    }
    // Invalid Mode
    else
    {
        FAPI_ASSERT(false, fapi2::PM_OCBINIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to proc_ocb_init. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_INF("< p10_pm_ocb_init");
    return fapi2::current_err;
}


fapi2::ReturnCode pm_ocb_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const ocb::PM_OCB_CHAN_NUM    i_ocb_chan,
    const ocb::PM_OCB_CHAN_TYPE   i_ocb_type,
    const uint32_t                i_ocb_bar,
    const ocb::PM_OCB_CHAN_REG    i_ocb_upd_reg,
    const uint8_t                 i_ocb_q_len,
    const ocb::PM_OCB_CHAN_OUFLOW i_ocb_ouflow_en,
    const ocb::PM_OCB_ITPTYPE     i_ocb_itp_type)
{
    FAPI_INF(">> pm_ocb_setup");

    uint32_t l_ocbase = 0x0;
    fapi2::buffer<uint64_t> l_mask_or(0);
    fapi2::buffer<uint64_t> l_mask_clear(0);
    fapi2::buffer<uint64_t> l_data64;

    // Verify input queue length is valid
    if ((i_ocb_type == ocb::OCB_TYPE_PUSHQ) ||
        (i_ocb_type == ocb::OCB_TYPE_PULLQ))
    {
        // check queue_len
        if (i_ocb_q_len > MAX_OCB_QUE_LEN)
        {
            FAPI_ASSERT(
                false,
                fapi2::PM_OCBINIT_BAD_Q_LENGTH_PARM().
                set_BADQLENGTH(i_ocb_q_len).
                set_CHANNEL(i_ocb_chan).
                set_TYPE(i_ocb_type),
                "ERROR: Bad Queue Length Passed to Procedure => %d",
                i_ocb_q_len);
        }
    }

    // -------------------------------------------------------------------------
    // Init Status and Control Register (OCBCSRn, OCBCSRn_CLEAR, OCBCSRn_OR)
    //    bit 2 => pull_read_underflow_en (0=disabled 1=enabled)
    //    bit 3 => push_write_overflow_en (0=disabled 1=enabled)
    //    bit 4 => ocb_stream_mode        (0=disabled 1=enabled)
    //    bit 5 => ocb_stream_type        (0=linear   1=circular)
    // -------------------------------------------------------------------------

    if (i_ocb_type == ocb::OCB_TYPE_LIN) // linear non-streaming
    {
        l_mask_clear.setBit<4, 2>();
    }
    else if (i_ocb_type == ocb::OCB_TYPE_LINSTR) // linear streaming
    {
        l_mask_or.setBit<4>();
        l_mask_clear.setBit<5>();
    }
    else if (i_ocb_type == ocb::OCB_TYPE_CIRC) // circular
    {
        l_mask_or.setBit<4, 2>();
    }
    else if (i_ocb_type == ocb::OCB_TYPE_PUSHQ) // push queue
    {
        l_mask_or.setBit<4, 2>();

        if (i_ocb_ouflow_en == ocb::OCB_Q_OUFLOW_EN)
        {
            l_mask_or.setBit<3>();
        }
        else if (i_ocb_ouflow_en == ocb::OCB_Q_OUFLOW_DIS)
        {
            l_mask_clear.setBit<3>();
        }
    }
    else if (i_ocb_type == ocb::OCB_TYPE_PULLQ) // pull queue
    {
        l_mask_or.setBit<4, 2>();

        if (i_ocb_ouflow_en == ocb::OCB_Q_OUFLOW_EN)
        {
            l_mask_or.setBit<2>();
        }
        else if (i_ocb_ouflow_en == ocb::OCB_Q_OUFLOW_DIS)
        {
            l_mask_clear.setBit<2>();
        }
    }

    FAPI_DBG("Writing to Channel %d Register : OCB Channel Status & Control",
             i_ocb_chan);

    // write using OR mask
    FAPI_TRY(fapi2::putScom(i_target, OCBCSRn_OR[i_ocb_chan], l_mask_or),
             "ERROR: Unexpected error encountered in write to OCB Channel "
             "Status & Control using OR mask");
    // write using AND mask
    FAPI_TRY(fapi2::putScom(i_target, OCBCSRn_CLEAR[i_ocb_chan], l_mask_clear),
             "ERROR: Unexpected error encountered in write to OCB Channel "
             "Status & Control using and mask");

    //--------------------------------------------------------------------------
    // set address base register for linear, pull queue or push queue
    //--------------------------------------------------------------------------
    //don't update bar if type null or circular
    if (!(i_ocb_type == ocb::OCB_TYPE_NULL ||
          i_ocb_type == ocb::OCB_TYPE_CIRC))
    {
        // BAR for linear (streaming / non-streaming)
        if ((i_ocb_type == ocb::OCB_TYPE_LIN) ||
            (i_ocb_type == ocb::OCB_TYPE_LINSTR))
        {
            l_ocbase = OCBARn[i_ocb_chan];
        }
        // BAR for push queue
        else if (i_ocb_type == ocb::OCB_TYPE_PUSHQ)
        {
            l_ocbase = OCBSHBRn[i_ocb_chan];
        }
        // BAR for pull queue
        else
        {
            l_ocbase = OCBSLBRn[i_ocb_chan];
        }

        l_data64.flush<0>().insertFromRight<0, 32>(i_ocb_bar);

        FAPI_DBG("Writing to Channel %d Register : OCB Channel Base Address",
                 i_ocb_chan);

        FAPI_TRY(fapi2::putScom(i_target, l_ocbase, l_data64),
                 "ERROR: Unexpected encountered in write to OCB Channel "
                 "Base Address");

    }

    // -------------------------------------------------------------------------
    // set up push queue control register
    //    bits 4:5  => push interrupt action
    //                   00=full
    //                   01=not full
    //                   10=empty
    //                   11=not empty
    //    bits 6:10 => push queue length
    //    bit  31   => push queue enable
    // -------------------------------------------------------------------------
    if ((i_ocb_type == ocb::OCB_TYPE_PUSHQ) &&
        (i_ocb_upd_reg == ocb::OCB_UPD_PIB_OCI_REG))
    {
        l_data64.flush<0>().insertFromRight<6, 5>(i_ocb_q_len);
        l_data64.insertFromRight<4, 2>(i_ocb_itp_type);
        l_data64.setBit<31>();

        FAPI_DBG("Writing to Channel %d Register : OCB Channel Push "
                 "Control/Status Address", i_ocb_chan);
        FAPI_TRY(fapi2::putScom(i_target, OCBSHCSn[i_ocb_chan], l_data64),
                 "ERROR : Unexpected error encountered in write to OCB "
                 "Channel Push Address");
    }

    // -------------------------------------------------------------------------
    // set up pull queue control register
    //    bits 4:5  => pull interrupt action
    //                   00=full
    //                   01=not full
    //                   10=empty
    //                   11=not empty
    //    bits 6:10 => pull queue length
    //    bit  31   => pull queue enable
    // -------------------------------------------------------------------------
    if ((i_ocb_type == ocb::OCB_TYPE_PULLQ) &&
        (i_ocb_upd_reg == ocb::OCB_UPD_PIB_OCI_REG))
    {
        l_data64.flush<0>().insertFromRight<6, 5>(i_ocb_q_len);
        l_data64.insertFromRight<4, 2>(i_ocb_itp_type);
        l_data64.setBit<31>();

        FAPI_DBG("Writing to Channel %d ,"
                 "Register : OCB Channel Pull Control/Status Address",
                 i_ocb_chan);
        FAPI_TRY(fapi2::putScom(i_target, OCBSLCSn[i_ocb_chan], l_data64),
                 "ERROR : Unexpected error encountered in write to OCB "
                 "Channel Pull Address");
    }

    // -------------------------------------------------------------------------
    // Print Channel Configuration Info
    // -------------------------------------------------------------------------
    FAPI_INF("OCB Channel Configuration                            ");
    FAPI_INF("  channel number             => %d ", i_ocb_chan);
    FAPI_INF("  channel type               => %d ", i_ocb_type);

    if ((i_ocb_type == ocb::OCB_TYPE_PUSHQ) ||
        (i_ocb_type == ocb::OCB_TYPE_PULLQ))
    {
        FAPI_INF("  queue length               => %d ", i_ocb_q_len);
        FAPI_INF("  interrupt type             => %d ", i_ocb_itp_type);

        if (i_ocb_type == ocb::OCB_TYPE_PUSHQ)
        {
            FAPI_INF("  push write overflow enable => %d ", i_ocb_ouflow_en);
        }
        else
        {
            FAPI_INF("  pull write underflow enable => %d ", i_ocb_ouflow_en);
        }
    }

    FAPI_INF("  channel base address       => 0x%08X ", i_ocb_bar);

fapi_try_exit:
    FAPI_INF("<< pm_ocb_setup");
    return fapi2::current_err;
}


fapi2::ReturnCode pm_ocb_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF(">> pm_ocb_reset");
    fapi2::buffer<uint64_t> l_buf64;
    fapi2::buffer<uint64_t> l_data64;

    // vector of reset channels
    // Channel 0: SBE owned; not touched here.
    // Channel 1: Host sets up once (in this HWP) in circular mode as part of OCC reset/init flow
    //     For reset, sets the channel into Linear Stream, Circular mode and disables the Pull and
    //     Push functions to render the channel "unusable".
    // Channel 2: SBE owned; not touched here.
    // Channel 3: SBE owned; not touched here.
    std::vector<uint8_t> v_reset_chan;
    v_reset_chan.push_back(1);  // Channel 1

    // -------------------------------------------------------------------------
    // Loop over PIB Registers
    // -------------------------------------------------------------------------
    for (auto& chan : v_reset_chan)
    {
        FAPI_INF(" Reset OCB channel : %d", chan);

        l_data64.flush<0>();
        // Clear out OCB Channel BAR registers
        FAPI_TRY(fapi2::putScom(i_target, OCBARn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d BAR Register", chan);

        // Clear out OCB Channel control and status registers
        l_data64.flush<1>();
        FAPI_TRY(fapi2::putScom(i_target, OCBCSRn_CLEAR[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Control & Status Register Clear", chan);

        // Put channels in Circular mode
        //  - set bits 4,5 (circular mode) using OR
        l_data64.flush<0>().setBit<4>().setBit<5>();
        FAPI_TRY(fapi2::putScom(i_target, OCBCSRn_OR[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Control & Status OR Register Set", chan);

        // Clear out OCB Channel Error Status registers
        l_data64.flush<0>();
        FAPI_TRY(fapi2::putScom(i_target, OCBESRn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Error Status Register", chan);
    }

    // -------------------------------------------------------------------------
    // Loop over OCI Registers
    // -------------------------------------------------------------------------
    for (auto& chan : v_reset_chan)
    {
        FAPI_INF(" Reset OCB channel : %d", chan);

        l_data64.flush<0>();

        // Clear out Pull Base
        FAPI_TRY(fapi2::putScom(i_target, OCBSLBRn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Pull Base Register", chan);

        // Clear out Push Base
        FAPI_TRY(fapi2::putScom(i_target, OCBSHBRn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Push Base Register", chan);

        // Clear out Pull Control & Status
        FAPI_TRY(fapi2::putScom(i_target, OCBSLCSn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Pull Control & Status Register", chan);

        // Clear out Push Control & Status
        FAPI_TRY(fapi2::putScom(i_target, OCBSHCSn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Push Control & Status Register", chan);

        // Clear out Stream Error Status
        FAPI_TRY(fapi2::putScom(i_target, OCBSESn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Stream Error Status Register", chan);

        // Clear out Linear Window Control
        FAPI_TRY(fapi2::putScom(i_target, OCBLWCRn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Linear Window Control Register", chan);

        // Clear out Linear Window Base
        //  - set bits 3:9
        l_data64.flush<0>().setBit<3, 7>();
        FAPI_TRY(fapi2::putScom(i_target, OCBLWSBRn[chan], l_data64),
                 "**** ERROR : Unexpected error encountered in write to OCB "
                 "Channel %d Linear Window Base Register", chan);
    }

    // OITR and OIEPR resetting is in p10_pm_xgpe_init as that is the
    // first HWP run in starting the complex.

    // Clear OCC Interrupt Timer Registers 0 & 1
    //  - need bits 0&1 set to clear register
    l_data64.flush<0>().setBit<0, 2>();
    FAPI_TRY(fapi2::putScom(i_target,
                            TP_TPCHIP_OCC_OCI_OCB_OTR0,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Timer0 Register (OTR0)");

    FAPI_TRY(fapi2::putScom(i_target,
                            TP_TPCHIP_OCC_OCI_OCB_OTR1,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Timer1 Register (OTR1)");

    // Clear PBA Enable Marker Acknowledgement mode to remove collisions
    // with any accesses to the OCB DCR registers (eg OSTOESR).
    // This function is only enabled by OCC firmware and is not via
    // hardware procedures.
    FAPI_TRY(fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_PBAMODE, l_data64),
             "**** ERROR : Failed to fetch PBA mode control status");
    l_data64.clearBit<TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK>();
    FAPI_TRY(fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAMODE, l_data64),
             "**** ERROR : Failed to write PBA mode control");

    l_data64.flush<0>();
    // Clear OCC special timeout error status register
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR, l_data64),
             "**** ERROR : Failed to write OSTESR");

    // Explicitly disable the OCC Heartbeat
    // Only clearing the OCB_OCI_OCCHBR_OCC_HEARTBEAT_EN and leaving the
    // Heartbeat count intact as this may prove useful for debug later.
    FAPI_TRY(fapi2::getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCHBR, l_data64),
             "**** ERROR : Failed to read OCBHBR");
    l_data64.clearBit<TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN>();
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCHBR, l_data64),
             "**** ERROR : Failed to write OCBHBR");

fapi_try_exit:
    FAPI_INF("<< pm_ocb_reset");
    return fapi2::current_err;
}
