/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pba_init.C $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_pba_init.C
/// @brief Initialize PBA registers for modes PM_INIT, PM_RESET
///

/*

    RESET flow
        Sets up PBA Mode register (in general)
        Set the values of PBASLV 0 to allow the IPL phase accesses for
            SGPE and PPC405 boot
        Set the values of PBASLV 2 to allow the IPL phase accesses for
            PGPE boot - upon boot of the OCC, OCC FW will re-establish
            this slave for its use
    INIT flow
        Set the values of PBASLV 0 to allow Runtime phase access for
            SGPE STOP (read accesses)
        Set the values of PBASLV 1 to allow Runtime phase access for
            SGPE 24x7 (read accesses).  SGPE 24x7 thread will re-establish
            this slave for write access as necessary

*/
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: HS

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_pm_pba_init.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <pba_firmware_registers.h>

// ----------------------------------------------------------------------
// Constants & Arrays
// ----------------------------------------------------------------------
enum PBA_INIT_FIELDS
{
    //Values for PBAX Configuration register fields
    PBAX_DATA_TIMEOUT = 0x0,
    PBAX_SND_RETRY_COMMIT_OVERCOMMIT = 0x0,
    PBAX_SND_RETRY_THRESHOLD = 0x0,
    PBAX_SND_TIMEOUT = 0x0,

    //Values for PBA Mode register fields
    PBA_OCI_REGION = 0x2,
    PBA_BCE_OCI_TRANSACTION_64_BYTES = 0x1,
    PBA_OCI_MARKER_BASE = 0x40070000,

    //Values for PBA Slave Control register fields
    OCI_MASTER_ID_SLV   = 0x0,
    OCI_MASTER_ID_MASK  = 0x7,
    OCI_MASTER_ID_GPE0  = 0x0,
    OCI_MASTER_ID_GPE1  = 0x1,
    OCI_MASTER_ID_GPE2  = 0x2,
    OCI_MASTER_ID_GPE3  = 0x3,
    OCI_MASTER_ID_ICU   = 0x5,
    OCI_MASTER_ID_OCB   = 0x6,
    OCI_MASTER_ID_DCU   = 0x7,
    OCI_MASTER_ID_PGPE  = OCI_MASTER_ID_GPE2,
    OCI_MASTER_ID_SGPE  = OCI_MASTER_ID_GPE3,

    /// The number of PBA read buffers
    PBA_READ_BUFFERS = 6,

    /// The number of PBA write buffers
    PBA_WRITE_BUFFERS = 2,

    ////////////////////////////////////
    //  PBA_SLVCTLn field values
    ////////////////////////////////////

    // PBA write Ttypes

    PBA_WRITE_TTYPE_DMA_PR_WR     = 0x0, /// DMA Partial Write
    PBA_WRITE_TTYPE_LCO_M         = 0x1, /// L3 LCO, Tsize denotes chiplet
    PBA_WRITE_TTYPE_ATOMIC_RMW    = 0x2, /// Atomic operations
    PBA_WRITE_TTYPE_CACHE_INJECT  = 0x3, /// ?
    PBA_WRITE_TTYPE_CI_PR_W       = 0x4, /// Cache-inhibited partial write for Centaur putscom().

    PBA_WRITE_TTYPE_DC = PBA_WRITE_TTYPE_DMA_PR_WR, // Don't care

    PBA_WRITE_TSIZE_ARMW_ADD  = 0x03,
    PBA_WRITE_TSIZE_ARMW_AND  = 0x13,
    PBA_WRITE_TSIZE_ARMW_OR   = 0x23,
    PBA_WRITE_TSIZE_ARMW_XOR  = 0x33,

    PBA_WRITE_TSIZE_DC  = 0x0,

    // PBA write gather timeouts are defined in terms of the number of 'pulses'. A
    // pulse occurs every 64 OCI cycles. The timing of the last write of a
    // sequence is variable, so the timeout will occur somewhere between (N - 1) *
    // 64 and N * 64 OCI cycles.  If write gather timeouts are disabled, the PBA
    // holds the data until some condition occurs that causes it to disgorge the
    // data. Slaves using cache-inhibited partial write never gather write
    // data. Note from spec. : "Write gather timeouts must NOT be disabled if
    // multiple masters are enabled to write through the PBA".  The only case
    // where write gather timeouts will be disabled is for the IPL-time injection
    // of data into the L3 caches.

    PBA_WRITE_GATHER_TIMEOUT_DISABLE   = 0x0,
    PBA_WRITE_GATHER_TIMEOUT_2_PULSES  = 0x4,
    PBA_WRITE_GATHER_TIMEOUT_4_PULSES  = 0x5,
    PBA_WRITE_GATHER_TIMEOUT_8_PULSES  = 0x6,
    PBA_WRITE_GATHER_TIMEOUT_16_PULSES = 0x7,

    /// PBA write gather timeout don't care assignment
    PBA_WRITE_GATHER_TIMEOUT_DC = PBA_WRITE_GATHER_TIMEOUT_2_PULSES,


    // PBA read Ttype
    PBA_READ_TTYPE_CL_RD_NC      = 0x0, /// Cache line read
    PBA_READ_TTYPE_CI_PR_RD      = 0x1, /// Cache-inhibited partial read for Centaur getscom().

    /// PBA read TTYPE don't care assignment
    PBA_READ_TTYPE_DC = PBA_READ_TTYPE_CL_RD_NC,


    // PBA read prefetch options
    PBA_READ_PREFETCH_AUTO_EARLY  = 0x0, /// Aggressive prefetch
    PBA_READ_PREFETCH_NONE        = 0x1, /// No prefetch
    PBA_READ_PREFETCH_AUTO_LATE   = 0x2, /// Non-aggressive prefetch

    /// PBA read prefetch don't care assignment
    PBA_READ_PREFETCH_DC = PBA_READ_PREFETCH_NONE,

};

enum PBA_WRITE_TTYPE
{
    DMA = 0,
    LCO = 1,
    ATOMIC = 2,
    INJ = 3,
    CI = 4
};


// Note:  the following registers are not reset due to SBE ownership of Slave 3
// PU_PBAMODE_SCOM  -  PBA MODE is a shared function
// PU_PBASLVCTL3_SCOM

const uint32_t PBASLAVES = 4;

// -----------------------------------------------------------------------------
// Local Function prototypes
// -----------------------------------------------------------------------------

///
/// @brief Clear PBA FIR & Config registers, set PBAX config register and
///        call pba_slave_setup.
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_init (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

///
/// @brief Clear PBA registers including PBAX config & error registers and
///        then call pba_slave_reset and stop BCDE &BCUE.
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_reset (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

///
/// @brief The setup is done prior to releasing the OCC from reset.
///        This setup serves both the initial boot of OCC as well as
///        for the OCC/PM reset flow performed during runtime.
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_slave_setup_runtime_phase(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

///
/// @brief The setup is done prior to booting any of the OCC complex
///         engines
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_slave_setup_boot_phase(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

///
/// @brief Walk each slave to hit the respective reset and then poll for
///        completion
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_slave_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Stop the BCDE and BCUE and then poll for their completion
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_bc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// -----------------------------------------------------------------------------
// Function definition
// -----------------------------------------------------------------------------
fapi2::ReturnCode p9_pm_pba_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("> p9_pm_pba_init");

    if (i_mode == p9pm::PM_INIT)
    {
        FAPI_TRY(pba_init(i_target), " pba_init() failed.");
    }
    else if (i_mode == p9pm::PM_RESET)
    {
        FAPI_TRY(pba_reset(i_target), " pba_reset() failed.");
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::P9_PMPROC_PBA_INIT_INCORRECT_MODE()
                    .set_PM_MODE(i_mode),
                    "Unknown mode 0x%08llx passed to p9_pm_pba_init.",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("< p9_pm_pba_init");
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  pba_init  -- mode = PM_INIT
// -----------------------------------------------------------------------------
fapi2::ReturnCode pba_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP(">> pba_init ...");

    fapi2::buffer<uint64_t> l_data64 = 0;
    uint8_t l_attr_pbax_groupid;
    uint8_t l_attr_pbax_chipid;
    uint8_t l_attr_pbax_broadcast_vector;

    // Clear PBA CONFIG. This register is cleared as there are no chicken
    // switches that need to be disabled. All other bits are set by OCC Firmware
    FAPI_TRY(fapi2::putScom(i_target, PU_PBACFG, l_data64),
             "Failed to clear PBA_CONFIG");

    // Clear the PBA FIR
    FAPI_TRY(fapi2::putScom(i_target, PU_PBAFIR, l_data64),
             "Failed to clear PBA_FIR");

    // No action required for the following registers:
    // PBARBUFVAL[n] (PBA Read Buffer Valid Status Registers) : They are ROX
    // PBAPBOCR[n] (PBA PowerBus OverCommit Rate Registers) : They are read-only
    // PBABAR[n] (PBA Base Address Range Registers) : Handled outside this FAPI
    // PBABARMSK[n] (PBA BAR Mask Register) : Handled outside this FAPI
    // (Thus, during a reset, the BARS/MASKS are retained.)

    // ----------------------------------------------------------
    // Get attributes
    // ----------------------------------------------------------
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PBAX_GROUPID,
                            i_target,
                            l_attr_pbax_groupid),
              "Error getting ATTR_PBAX_GROUPID");

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PBAX_CHIPID,
                            i_target,
                            l_attr_pbax_chipid),
              "Error getting ATTR_PBAX_CHIPID");

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PBAX_BRDCST_ID_VECTOR,
                            i_target,
                            l_attr_pbax_broadcast_vector),
              "Error getting ATTR_PBAX_BRDCST_ID_VECTOR");


    FAPI_INF("Initialize PBAX Configuration ...");
    l_data64.insertFromRight<PU_PBAXCFG_RCV_GROUPID,
                             PU_PBAXCFG_RCV_GROUPID_LEN>
                             (l_attr_pbax_groupid);

    l_data64.insertFromRight<PU_PBAXCFG_RCV_CHIPID,
                             PU_PBAXCFG_RCV_CHIPID_LEN>
                             (l_attr_pbax_chipid);

    l_data64.insertFromRight<PU_PBAXCFG_RCV_BRDCST_GROUP,
                             PU_PBAXCFG_RCV_BRDCST_GROUP_LEN>
                             (l_attr_pbax_broadcast_vector);

    FAPI_INF("PBAX Topology Configuration - GroupID: 0x%02X, ChipID: 0x%02X, BroadcastVector: 0x%02X",
             l_attr_pbax_groupid,
             l_attr_pbax_chipid,
             l_attr_pbax_broadcast_vector);


    // 20:24 - l_pbax_data_timeout
    // 27    - l_pbax_snd_retry_commit_overcommit
    // 28:35 - l_pbax_snd_retry_threshold
    // 36:40 - l_pbax_snd_timeout
    l_data64.insertFromRight<PU_PBAXCFG_RCV_DATATO_DIV,
                             PU_PBAXCFG_RCV_DATATO_DIV_LEN>
                             (PBAX_DATA_TIMEOUT);

    l_data64.insertFromRight<PU_PBAXCFG_SND_RETRY_COUNT_OVERCOM,
                             1>
                             (PBAX_SND_RETRY_COMMIT_OVERCOMMIT);

    l_data64.insertFromRight<PU_PBAXCFG_SND_RETRY_THRESH,
                             PU_PBAXCFG_SND_RETRY_THRESH_LEN>
                             (PBAX_SND_RETRY_THRESHOLD);

    l_data64.insertFromRight<PU_PBAXCFG_SND_RSVTO_DIV,
                             PU_PBAXCFG_SND_RSVTO_DIV_LEN>
                             (PBAX_SND_TIMEOUT);

    FAPI_TRY(fapi2::putScom(i_target, PU_PBAXCFG_SCOM, l_data64),
             "Failed to set PBAX Config");

    // Perform PBA Slave setup to prepare for the runtime phase.
    FAPI_TRY(pba_slave_setup_runtime_phase(i_target),
             "pba_slave_setup_runtime_phase() failed. ");

fapi_try_exit:
    FAPI_IMP("<< pba_init ...");
    return fapi2::current_err;
}


// -----------------------------------------------------------------------------
//  pba_reset  -- mode = PM_RESET
// -----------------------------------------------------------------------------
fapi2::ReturnCode pba_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    std::vector<uint64_t> v_pba_reset_regs =
    {
        PU_BCDE_STAT_SCOM,
        PU_BCDE_PBADR_SCOM,
        PU_BCDE_OCIBAR_SCOM,
        PU_BCUE_CTL_SCOM,
        PU_BCUE_SET_SCOM,
        PU_BCUE_STAT_SCOM,
        PU_BCUE_PBADR_SCOM,
        PU_BCUE_OCIBAR_SCOM,
        PU_PBAXSHBR0_SCOM,
        PU_PBAXSHBR1_SCOM,
        PU_PBAXSHCS0_SCOM,
        PU_PBAXSHCS1_SCOM,
        PU_PBASLVCTL0_SCOM,
        PU_PBASLVCTL1_SCOM,
        PU_PBASLVCTL2_SCOM,
        PU_PBAFIR,
        PU_PBACFG,
        PU_PBAERRRPT0
    };

    FAPI_IMP(">> pba_reset ...");

    fapi2::buffer<uint64_t> l_data64;

    // Stop the  BCDE and BCUE
    FAPI_TRY(pba_bc_stop(i_target), "pba_bc_stop() detected an error");

    // Reset each slave and wait for completion.
    FAPI_TRY(pba_slave_reset(i_target), "pba_slave_reset() failed.");

    for (auto it : v_pba_reset_regs)
    {
        FAPI_DBG("Resetting PBA register 0x%08llX", it);
        FAPI_TRY(fapi2::putScom(i_target, it, 0),
                 "Failed to reset register 0x%08llX",  it);
    }

    // Perform non-zero reset operations
    // Reset PBAX errors via Configuration Register
    //     Bit 2: PBAXCFG_SND_RESET
    //     Bit 3: PBAXCFG_RCV_RESET
    l_data64.setBit<2, 2>();
    FAPI_INF("Resetting PBAX errors via PBAX config register 0x%08llX with "
             "value = 0x%16llX", PU_PBAXCFG_SCOM, uint64_t(l_data64));
    FAPI_TRY(fapi2::putScom(i_target, PU_PBAXCFG_SCOM, l_data64));

    // Perform PBA Slave setup to prepare for the boot phase.
    FAPI_TRY(pba_slave_setup_boot_phase(i_target),
             "pba_slave_setup_boot_phase() failed. ");

fapi_try_exit:
    FAPI_IMP("<< pba_reset ...");
    return fapi2::current_err;
}


// -----------------------------------------------------------------------------
//  pba_slave_reset
// -----------------------------------------------------------------------------
fapi2::ReturnCode pba_slave_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP(">> pba_slave_reset");

    fapi2::buffer<uint64_t> l_data64;
    bool                    l_poll_failure = false;
    uint32_t                l_pollCount;

    // Slave to be reset.  Note:  Slave 3 is not reset as it is owned by SBE
    std::vector<uint32_t> v_slave_resets = {0, 1, 2};


    for (auto sl : v_slave_resets)
    {
        FAPI_INF("Reseting PBA Slave %x", sl);
        l_poll_failure = true;

        for (l_pollCount = 0; l_pollCount < p9pba::MAX_PBA_RESET_POLLS;
             l_pollCount++)
        {
            // Reset the selected slave
            l_data64.insert<0, 64>(p9pba::PBA_SLVRESETs[sl] );
            FAPI_TRY(fapi2::putScom(i_target, PU_PBASLVRST_SCOM, l_data64));

            // Read the reset register to check for reset completion
            FAPI_TRY(fapi2::getScom(i_target, PU_PBASLVRST_SCOM, l_data64));
            FAPI_DBG("Slave %x reset poll l_data64 = 0x%016llX", sl, l_data64);

            // If slave reset in progress, wait and then poll
            if (l_data64 & 0x0000000000000001 << (63 - ( 4 + sl)) )
            {

                FAPI_TRY(fapi2::delay(p9pba::PBA_RESET_POLL_DELAY * 1000, 200000),
                         " fapi2::delay Failed. ");   // In microseconds
            }
            else
            {
                FAPI_INF("PBA Reset complete for Slave %d", sl);
                l_poll_failure = false;
                break;
            }
        }


        // Error exit from above loop
        if (l_poll_failure)
        {
            const uint64_t& l_BUFFCONT =  uint64_t(l_data64);
            FAPI_ASSERT(false, fapi2::P9_PMPROC_PBA_SLAVE_RESET_TIMEOUT()
                        .set_POLLCOUNT(l_pollCount)
                        .set_SLAVENUM(sl)
                        .set_PBASLVREG(l_BUFFCONT),
                        "PBA Slave Reset Timout");
        }

        // Check if the slave is still actually busy.
        // Slave %x still busy after reset,consider whether this should be polled.
        if ( l_data64 & 0x0000000000000001 << (63 - ( 8 + sl)) )
        {
            const uint64_t& l_BUFFCONT =  uint64_t(l_data64);
            FAPI_ASSERT(false, fapi2::P9_PMPROC_PBA_SLAVE_BUSY_AFTER_RESET()
                        .set_POLLCOUNT(l_pollCount)
                        .set_SLAVENUM(sl)
                        .set_PBASLVREG( l_BUFFCONT),
                        "Slave 0x%x still busy after reset", sl);
        }
    }

fapi_try_exit:
    FAPI_IMP("<< pba_slave_reset");
    return fapi2::current_err;
}


// -----------------------------------------------------------------------------
/// PgP PBA Setup
///
/// The PBA is 'set up' in three ways.
///
/// The first set up is via scan-0 settings or SBE-IPL code to enable the Host
/// Boot image to be injected into the cache of the IPL core.  This phase is not
/// implemented in this procedure set.
///
/// The second is is to enable the "boot phase" where the SGPE, PGPE and OCC
/// PPC405 and handled by pba_setup_boot_phase.
///
/// PBA slave 0 is used to boot the SGPE and the OCC PPC405.
///
/// PBA slave 1 is not used and not setup.

/// PBA slave 2 is used to boot the PGPE.  It is setup as a read/write slave
/// as the PGPE as to write to HOMER memory during this phase.
///
/// PBA Slave 3 is used by the SBE and is setup by the SBE to map the OCB to
/// mainstory.  This procedure set does not deal with this slave.
///
/// Runtime setup --- defined as that in place upon starting the PPC405.
///
/// PBA slave 0 is used by the SGPE to read HOMER memory.
///
/// PBA slave 1 is used by OCC GPEs to access Centaur memory buffers.  It is
/// setup by OCC GPE firmware.
///
/// PBA Slave 2 is used by OCC GPEs to access OCC owned memory regions for
/// GPU sensor data.
///
/// PBA Slave 3 is used by the SBE and is setup by the SBE to map the OCB to
/// mainstory.  This procedure set does not deal with this slave.
///
/// The design of PBA allows read buffers to be dedicated to a particular
/// slave, and requires that a slave have a dedicated read buffer in order to
/// do aggressive prefetching. In the end there is little reason to partition
/// the resources.  However, it also isn't clear that aggressive prefetching
/// provides any dicernable performance boost. Another wrinkle is that the BCDE
/// claims read buffer C whenever it runs, and the 405 I + D sides never run
/// after the initial OCC  startup. For these reasons all slaves are programmed
/// to share all resources.
///

// -----------------------------------------------------------------------------
//  pba_slave_setup_boot_phase
// -----------------------------------------------------------------------------
fapi2::ReturnCode
pba_slave_setup_boot_phase(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    pba_mode_t          pm;
    pba_slvctln_t       ps;

    fapi2::buffer<uint64_t>  l_data64(64);

    FAPI_IMP(">> pba_slave_setup_boot_phase");

    FAPI_INF("Initialize PBA Mode ...");
    // Set the PBA_MODECTL register. It's not yet clear how PBA BCE
    // transaction size will affect performance - for now we go with the
    // largest size.  The HTM marker space is enabled and configured. Slave
    // fairness is enabled. The setting 'dis_slvmatch_order' ensures that PBA
    // will correctly flush write data before allowing a read of the same
    // address from a different master on a different slave.  The second write
    // buffer is enabled.
    // prepare the value to be set:
    pm.value = 0;
    pm.fields.pba_region = PBA_OCI_REGION;
    pm.fields.bcde_ocitrans = PBA_BCE_OCI_TRANSACTION_64_BYTES;
    pm.fields.bcue_ocitrans = PBA_BCE_OCI_TRANSACTION_64_BYTES;
    pm.fields.en_marker_ack = 1;
    pm.fields.oci_marker_space = (PBA_OCI_MARKER_BASE >> 16) & 0x7;
    pm.fields.en_slv_fairness = 1;
    pm.fields.en_second_wrbuf = 1;

    l_data64 = pm.value;

    // write the prepared value
    FAPI_TRY(fapi2::putScom(i_target, PU_PBAMODE_SCOM, l_data64),
             "Failed to set PBA MODE register");

    FAPI_INF("Initialize PBA Slave 0 ...");
    // Slave 0 (SGPE and OCC boot).  This is a read/write slave. We only do 'static'
    // setup here.
    ps.value = 0;
    ps.fields.enable = 1;
    ps.fields.mid_match_value = OCI_MASTER_ID_SGPE |
                                OCI_MASTER_ID_DCU |
                                OCI_MASTER_ID_ICU;
    ps.fields.mid_care_mask =   OCI_MASTER_ID_SGPE |
                                OCI_MASTER_ID_DCU |
                                OCI_MASTER_ID_ICU;
    ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
    ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
    ps.fields.buf_alloc_a = 1;
    ps.fields.buf_alloc_b = 1;
    ps.fields.buf_alloc_c = 1;
    ps.fields.buf_alloc_w = 1;

    l_data64 = ps.value;

    FAPI_TRY(fapi2::putScom(i_target, PU_PBASLVCTL0_SCOM, l_data64),
             "Failed to set Slave 3 control register");

    FAPI_INF("Skipping PBA Slave 1 ...");
    // Slave 1 is not used during Boot phase

    FAPI_INF("Initialize PBA Slave 2 ...");
    // Slave 2 (PGPE Boot).  This is a read/write slave.  Write gethering is
    // allowed, but with the shortest possible timeout. This slave is
    // effectively disabled soon after IPL.

    ps.value = 0;
    ps.fields.enable = 1;
    ps.fields.mid_match_value = OCI_MASTER_ID_PGPE;
    ps.fields.mid_care_mask = OCI_MASTER_ID_PGPE;
    ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
    ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
    ps.fields.write_ttype = PBA_WRITE_TTYPE_DMA_PR_WR;
    ps.fields.wr_gather_timeout = PBA_WRITE_GATHER_TIMEOUT_2_PULSES;
    ps.fields.buf_alloc_a = 1;
    ps.fields.buf_alloc_b = 1;
    ps.fields.buf_alloc_c = 1;
    ps.fields.buf_alloc_w = 1;

    l_data64 = ps.value;

    FAPI_TRY(fapi2::putScom(i_target, PU_PBASLVCTL2_SCOM, l_data64),
             "Failed to set Slave 2 control register");

    // Slave 3 is not modified by this function
    FAPI_INF("Skipping PBA Slave 3 as this is owned by SBE ...");

fapi_try_exit:
    FAPI_IMP("<< pba_slave_setup_boot_phase");
    return fapi2::current_err;
}  // end pba_slave_setup_init



// -----------------------------------------------------------------------------
//  pba_slave_setup_runtime_phase
// -----------------------------------------------------------------------------
fapi2::ReturnCode
pba_slave_setup_runtime_phase(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    pba_mode_t          pm;
    pba_slvctln_t       ps;

    fapi2::buffer<uint64_t>  l_data64(64);

    FAPI_IMP(">> pba_slave_setup_runtime_phase");

    // Set the PBA_MODECTL register. It's not yet clear how PBA BCE
    // transaction size will affect performance - for now we go with the
    // largest size.  The HTM marker space is enabled and configured. Slave
    // fairness is enabled. The setting 'dis_slvmatch_order' ensures that PBA
    // will correctly flush write data before allowing a read of the same
    // address from a different master on a different slave.  The second write
    // buffer is enabled.

    pm.value = 0;
    pm.fields.pba_region = PBA_OCI_REGION;
    pm.fields.bcde_ocitrans = PBA_BCE_OCI_TRANSACTION_64_BYTES;
    pm.fields.bcue_ocitrans = PBA_BCE_OCI_TRANSACTION_64_BYTES;
    pm.fields.en_marker_ack = 1;
    pm.fields.oci_marker_space = (PBA_OCI_MARKER_BASE >> 16) & 0x7;
    pm.fields.en_slv_fairness = 1;
    pm.fields.en_second_wrbuf = 1;

    l_data64 = pm.value;

    // write the prepared value
    FAPI_TRY(fapi2::putScom(i_target, PU_PBAMODE_SCOM, l_data64),
             "Failed to set PBA MODE register");

    FAPI_INF("Initialize PBA Slave 0 for SGPE STOP use...");
    // Slave 0 (SGPE STOP).  This is a read/write slave in the event that
    // the STOP functions needs to write to memory..
    ps.value = 0;
    ps.fields.enable = 1;
    ps.fields.mid_match_value = OCI_MASTER_ID_SGPE;
    ps.fields.mid_care_mask = OCI_MASTER_ID_SGPE;
    ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
    ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
    ps.fields.write_ttype = PBA_WRITE_TTYPE_DMA_PR_WR;
    ps.fields.wr_gather_timeout = PBA_WRITE_GATHER_TIMEOUT_2_PULSES;
    ps.fields.buf_alloc_a = 1;
    ps.fields.buf_alloc_b = 1;
    ps.fields.buf_alloc_c = 1;
    ps.fields.buf_alloc_w = 1;

    l_data64 = ps.value;

    FAPI_TRY(fapi2::putScom(i_target, PU_PBASLVCTL0_SCOM, l_data64),
             "Failed to set Slave 3 control register");

    FAPI_INF("Initialize PBA Slave 1 for SGPE 24x7 use...");
    // Slave 1 (SGPE 24x7).  This is a read/write slave.  Write gethering is
    // allowed, but with the shortest possible timeout.

    ps.value = 0;
    ps.fields.enable = 1;
    ps.fields.mid_match_value = OCI_MASTER_ID_SGPE;
    ps.fields.mid_care_mask = OCI_MASTER_ID_SGPE;
    ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
    ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
    ps.fields.write_ttype = PBA_WRITE_TTYPE_DMA_PR_WR;
    ps.fields.wr_gather_timeout = PBA_WRITE_GATHER_TIMEOUT_2_PULSES;
    ps.fields.buf_alloc_a = 1;
    ps.fields.buf_alloc_b = 1;
    ps.fields.buf_alloc_c = 1;
    ps.fields.buf_alloc_w = 1;

    l_data64 = ps.value;

    FAPI_TRY(fapi2::putScom(i_target, PU_PBASLVCTL2_SCOM, l_data64),
             "Failed to set Slave 2 control register");


    FAPI_INF("Disabling PBA Slave 2 ...  To be enabled/setup by OCC Firmware");
    // Slave 2 - used by OCC.   Tear this down to ensure that it is properly
    // setup by OCC.

    ps.value = 0;
    ps.fields.enable = 0;
    ps.fields.mid_match_value = OCI_MASTER_ID_GPE0;
    ps.fields.mid_care_mask = OCI_MASTER_ID_ICU & OCI_MASTER_ID_DCU;
    ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
    ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
    ps.fields.write_ttype = PBA_WRITE_TTYPE_DMA_PR_WR;
    ps.fields.wr_gather_timeout = PBA_WRITE_GATHER_TIMEOUT_2_PULSES;
    ps.fields.buf_alloc_a = 0;
    ps.fields.buf_alloc_b = 0;
    ps.fields.buf_alloc_c = 0;
    ps.fields.buf_alloc_w = 0;

    l_data64 = ps.value;

    FAPI_TRY(fapi2::putScom(i_target, PU_PBASLVCTL2_SCOM, l_data64),
             "Failed to set Slave 2 control register");

    // Slave 3 is not modified by this function
    FAPI_INF("Skipping PBA Slave 3 as this is owned by SBE ...");

fapi_try_exit:
    FAPI_IMP("<< pba_slave_setup_runtime_phase");
    return fapi2::current_err;
}  // end pba_slave_setup_runtime_phase

// -----------------------------------------------------------------------------
//  pba_bc_stop
// -----------------------------------------------------------------------------
fapi2::ReturnCode pba_bc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP(">>> pba_bc_stop...");

    fapi2::buffer<uint64_t> l_data64;
    bool                l_bcde_stop_complete = false;
    bool                l_bcue_stop_complete = false;
    uint32_t            l_pollCount;

    l_data64.setBit<0>();
    // Stopping Block Copy Download Engine
    FAPI_TRY(fapi2::putScom(i_target, PU_BCDE_CTL_SCOM, l_data64),
             "Failed to set the BCDE control register");

    // Stopping Block Copy Upload Engine
    FAPI_TRY(fapi2::putScom(i_target, PU_BCUE_CTL_SCOM, l_data64),
             "Failed to set the BCUE control register");

    // Polling on, to verify that BCDE & BCUE are indeed stopped.
    for (l_pollCount = 0;
         l_pollCount < p9pba::MAX_PBA_BC_STOP_POLLS;
         l_pollCount++)
    {
        // Read the BCDE Status register to check for a stopped condition
        FAPI_TRY(fapi2::getScom(i_target, PU_BCDE_STAT_SCOM, l_data64));
        FAPI_DBG("BCDE Status = 0x%016llX", uint64_t(l_data64));

        if (! l_data64.getBit<p9pba::PBA_BC_STAT_RUNNING>() )
        {
            FAPI_INF("BCDE Running Bit clear to indicate the stop condition");
            l_bcde_stop_complete = true;
        }

        // Read the BCUE Status register to check for stop condition
        FAPI_TRY(fapi2::getScom(i_target, PU_BCUE_STAT_SCOM, l_data64));
        FAPI_DBG("BCUE Status = 0x%016llX",  uint64_t(l_data64));

        if(! l_data64.getBit<p9pba::PBA_BC_STAT_RUNNING>())
        {
            FAPI_INF("BCUE Running Bit is clear, indicates the stop condition");
            l_bcue_stop_complete = true;
        }

        // If both engines are stopped , exit polling loop
        if (l_bcde_stop_complete && l_bcue_stop_complete)
        {
            break;
        }
        else
        {
            FAPI_TRY(fapi2::delay(p9pba::MAX_PBA_BC_STOP_POLLS * 1000, 2000000),
                     " fapi2::delay Failed ");   // In microseconds
        }
    }

    // Assert, if BCDE did not stop
    if (!l_bcde_stop_complete)
    {
        FAPI_ASSERT(false, fapi2::P9_PROCPM_PBA_BCDE_STOP_TIMEOUT()
                    .set_POLLCOUNT( p9pba::MAX_PBA_BC_STOP_POLLS)
                    .set_POLLVALUE(p9pba::MAX_PBA_BC_STOP_POLLS),
                    "PBA BCDE Stop Timeout");
    }

    // Assert, if BCUE did not stop
    if (!l_bcue_stop_complete)
    {
        FAPI_ASSERT(false, fapi2::P9_PROCPM_PBA_BCUE_STOP_TIMEOUT()
                    .set_POLLCOUNT( p9pba::MAX_PBA_BC_STOP_POLLS)
                    .set_POLLVALUE( p9pba::MAX_PBA_BC_STOP_POLLS),
                    "PBA BCUE Stop Timeout");
    }

    FAPI_INF("Clear the BCDE and BCUE stop bits.");
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, PU_BCDE_CTL_SCOM, l_data64));
    FAPI_TRY(fapi2::putScom(i_target, PU_BCUE_CTL_SCOM, l_data64));

fapi_try_exit:
    FAPI_IMP("<<< pba_bc_stop...");
    return fapi2::current_err;
}



