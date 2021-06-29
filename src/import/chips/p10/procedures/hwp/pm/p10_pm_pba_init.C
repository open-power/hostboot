/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_pba_init.C $    */
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
/// @file p10_pm_pba_init.C
/// @brief Initialize PBA registers for modes PM_INIT, PM_RESET
///
// *HWP HW Owner     :  Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner :  Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner     :  Prem S Jha <premjha2@in.ibm.com>
// *HWP Team         :  PM
// *HWP Level        :  3
// *HWP Consumed by  :  HS

///
/// @verbatim
///    HALT flow
///        Sets up PBA Mode register (in general)
///        Set the values of PBASLV 0 to allow the IPL phase accesses for
///            XGPE and PPC405 boot.
///        Set the values of PBASLV 2 to allow the IPL phase accesses for
///            PGPE boot - upon boot of the OCC, OCC FW will re-establish
///            this slave for its use
///    START flow
///        Set the values of PBASLV 0 to allow Runtime phase access for
///            PGPE and XGPE.
///        Set the values of PBASLV 1 to allow Runtime phase access for
///            OCC GPE use.
///@endverbatim

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p10_pm_pba_init.H>
#include <p10_fbc_utils.H>
#include <p10_scom_proc.H>

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

    PBA_OPER_HANG_DIV = 0b01000,
    PBA_EXIT_HANG_DIV = 0b01000,

    //Values for PBA Slave Control register fields
    OCI_MASTER_ID_SLV       = 0x0,
    OCI_MASTER_ID_MASK_ALL  = 0x7,
    OCI_MASTER_ID_MASK_NONE = 0x0,
    OCI_MASTER_ID_GPE0      = 0x0,
    OCI_MASTER_ID_GPE1      = 0x1,
    OCI_MASTER_ID_GPE2      = 0x2,
    OCI_MASTER_ID_GPE3      = 0x3,
    OCI_MASTER_ID_ICU       = 0x5,
    OCI_MASTER_ID_OCB       = 0x6,
    OCI_MASTER_ID_DCU       = 0x7,
    OCI_MASTER_ID_PGPE      = OCI_MASTER_ID_GPE2,
    OCI_MASTER_ID_XGPE      = OCI_MASTER_ID_GPE3,

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

enum PBA_PHASE
{
    PBA_BOOT = 0,
    PBA_RUNTIME = 1
};

const char* PBA_PHASE_NAME[] =
{
    "BOOT",
    "RUNTIME"
};

// Note:  the following registers are not reset due to SBE ownership of Slave 3
// PU_PBAMODE_SCOM  -  PBA MODE is a shared function
// PU_PBASLVCTL3_SCOM

const uint32_t PBASLAVES = 4;


///
/// @brief Initialize the PBA topology id table entries
/// @param[in] i_target         Reference to chip target
/// @param[in] topo_scoms       Vector where each element is the content to write
///                             into the topology id table SCOM register.
///                             topo_scoms[0] contains reg value for entries  0.. 7
///                             topo_scoms[1] contains reg value for entries  8..15
///                             topo_scoms[2] contains reg value for entries 16..23
///                             topo_scoms[3] contains reg value for entries 24..31
///                             assert(topo_scoms.size() == 4)
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS on success, error otherwise
///
fapi2::ReturnCode init_topo_id_tables(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const std::vector<uint64_t>& topo_scoms)
{
    using namespace scomt::proc;

    FAPI_DBG(">> init_topo_id_tables");
    PREP_TP_TPBR_PBA_PBAO_PBAPBTXT0(i_target);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBAPBTXT0(i_target, topo_scoms[0]));
    PREP_TP_TPBR_PBA_PBAO_PBAPBTXT1(i_target);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBAPBTXT1(i_target, topo_scoms[1]));
    PREP_TP_TPBR_PBA_PBAO_PBAPBTXT2(i_target);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBAPBTXT2(i_target, topo_scoms[2]));
    PREP_TP_TPBR_PBA_PBAO_PBAPBTXT3(i_target);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBAPBTXT3(i_target, topo_scoms[3]));
    FAPI_DBG("<< init_topo_id_tables");
fapi_try_exit:
    return fapi2::current_err;
}

/// -----------------------------------------------------------------------------
/// pba_slave_reset
/// -----------------------------------------------------------------------------
///
/// @brief Walk each slave to hit the respective reset and then poll for
///        completion
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_slave_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;

    FAPI_IMP(">> pba_slave_reset");

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_slvrst;
    bool                    l_poll_failure = false;
    uint32_t                l_pollCount;

    // Slave to be reset.  Note:  Slave 3 is not reset as it is owned by SBE
    std::vector<uint32_t> v_slave_resets;
    v_slave_resets.push_back(0);
    v_slave_resets.push_back(1);
    v_slave_resets.push_back(2);

    for (auto sl : v_slave_resets)
    {
        FAPI_INF("Reseting PBA Slave %x", sl);
        l_poll_failure = true;

        for (l_pollCount = 0; l_pollCount < p10pba::MAX_PBA_RESET_POLLS;
             l_pollCount++)
        {
            // Reset the selected slave
            PREP_TP_TPBR_PBA_PBAO_PBASLVRST(i_target);
            l_data64.insert<0, 64>(p10pba::PBA_SLVRESETs[sl] );
            FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBASLVRST(i_target, l_data64));

            // Read the reset register to check for reset completion
            FAPI_TRY(GET_TP_TPBR_PBA_PBAO_PBASLVRST(i_target, l_slvrst));
            GET_TP_TPBR_PBA_PBAO_PBASLVRST_IN_PROG(l_slvrst, l_data64);
            FAPI_DBG("Slave %x reset poll = 0x%01llX", sl, l_data64);

            // If slave reset in progress, wait and then poll
            if (l_data64 & (0x1 << (3 - sl)) )
            {
                FAPI_TRY(fapi2::delay(p10pba::PBA_RESET_POLL_DELAY * 1000, 200000),
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
            FAPI_ASSERT(false, fapi2::PM_PBA_SLAVE_RESET_TIMEOUT()
                        .set_POLLCOUNT(l_pollCount)
                        .set_SLAVENUM(sl)
                        .set_PBASLVREG(l_BUFFCONT)
                        .set_CHIP(i_target),
                        "PBA Slave Reset Timout");
        }

        // Check if the slave is still actually busy.
        GET_TP_TPBR_PBA_PBAO_PBASLVRST_BUSY_STATUS(l_slvrst, l_data64);

        if (l_data64 & (0x1 << (3 - sl)) )
        {
            const uint64_t& l_BUFFCONT =  uint64_t(l_data64);
            FAPI_ASSERT(false, fapi2::PM_PBA_SLAVE_BUSY_AFTER_RESET()
                        .set_POLLCOUNT(l_pollCount)
                        .set_SLAVENUM(sl)
                        .set_PBASLVREG( l_BUFFCONT)
                        .set_CHIP(i_target),
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
/// The second is is to enable the "boot phase" where the XGPE, PGPE and OCC
/// PPC405 and handled by pba_setup_boot_phase.
///
/// PBA slave 0 is used to boot the XGPE.
///
/// PBA slave 1 is used to boot the OCC PPC405.
///
/// PBA slave 2 is used to boot the PGPE.  It is setup as a read/write slave
/// as the PGPE as to write to HOMER memory during this phase.
///
/// PBA Slave 3 is used by the SBE and is setup by the SBE to map the OCB to
/// mainstore.  This procedure set does not deal with this slave.
///
/// Runtime setup --- defined as that in place upon starting the PPC405.
///
/// PBA slave 0 is used by the XGPE to read and write HOMER memory.
///
/// PBA slave 1 is used by OCC GPE1 to access memory buffers and for
/// writing 24x7 performance information. It is setup for basic read/write
/// for the PPC405 and then modified by by OCC GPE firmware.
///
/// PBA slave 2 is used to by the PGPE to write trace and characterization
/// data to memory.
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

/// -----------------------------------------------------------------------------
/// pba_slave_setup
/// -----------------------------------------------------------------------------
///
/// @brief The setup is done prior to booting any of the OCC complex
///         engines
///
/// @param[in] i_target Chip target
/// @param[in] i_phase  PBA_BOOT or PBA_RUNTIME
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///

fapi2::ReturnCode
pba_slave_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const PBA_PHASE i_phase)
{
    // Function not supported on SBE platform
#ifndef __PPE__
    using namespace scomt::proc;

    fapi2::buffer<uint64_t>  l_data(64);

    FAPI_IMP(">> pba_slave_setup in %s mode", PBA_PHASE_NAME[i_phase]);

    FAPI_INF("Initialize PBA Mode ...");
    // Set the PBA_MODECTL register. It's not yet clear how PBA BCE
    // transaction size will affect performance - for now we go with the
    // largest size.  The HTM marker space is enabled and configured. Slave
    // fairness is enabled. The setting 'dis_slvmatch_order' ensures that PBA
    // will correctly flush write data before allowing a read of the same
    // address from a different master on a different slave.  The second write
    // buffer is enabled.
    l_data.flush<0>();
    PREP_TP_TPBR_PBA_PBAO_PBAMODE(i_target);
    SET_TP_TPBR_PBA_PBAO_PBAMODE_PBA_REGION(        PBA_OCI_REGION,                     l_data);
    SET_TP_TPBR_PBA_PBAO_PBAMODE_BCDE_OCITRANS(     PBA_BCE_OCI_TRANSACTION_64_BYTES,   l_data);
    SET_TP_TPBR_PBA_PBAO_PBAMODE_BCUE_OCITRANS(     PBA_BCE_OCI_TRANSACTION_64_BYTES,   l_data);
    SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_MARKER_ACK(                                         l_data);
    SET_TP_TPBR_PBA_PBAO_PBAMODE_OCI_MARKER_SPACE(  ((PBA_OCI_MARKER_BASE >> 16) & 0x7), l_data);
    SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SLV_FAIRNESS(                                       l_data);
    SET_TP_TPBR_PBA_PBAO_PBAMODE_EN_SECOND_WRBUF(                                       l_data);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBAMODE(i_target, l_data));

    FAPI_INF("Initialize PBA Slave 0 ...");
    // Boot: Slave 0 (XGPE and OCC boot).  This is a read/write slave. We only do 'static'
    // setup here.
    //
    // Runtime: Slave 0 (XGPE).  This is a read/write slave in the event that
    // the XGPE functions needs to write to memory.

    l_data.flush<0>();
    PREP_TP_TPBR_PBA_PBAO_PBASLVCTL0(i_target);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE(                                                 l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE(  OCI_MASTER_ID_XGPE,                   l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK(    OCI_MASTER_ID_MASK_ALL,               l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE(       PBA_READ_TTYPE_CL_RD_NC,              l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL(PBA_READ_PREFETCH_NONE,               l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A(                                            l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B(                                            l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C(                                            l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W(                                            l_data);
    fapi2::ATTR_HOMER_LOCATION_Type l_homerloc;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HOMER_LOCATION,
                           i_target,
                           l_homerloc));


    if (i_phase == PBA_RUNTIME)
    {
        if (l_homerloc == fapi2::ENUM_ATTR_HOMER_LOCATION_CACHE)
        {
            FAPI_DBG("PBA Slave 0 setup for booting from CACHE");
            SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE(PBA_WRITE_TTYPE_LCO_M, l_data);
        }
        else
        {
            FAPI_DBG("PBA Slave 0 setup for booting from MEMORY");
            SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE(      PBA_WRITE_TTYPE_DMA_PR_WR,        l_data);
        }

        SET_TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT(PBA_WRITE_GATHER_TIMEOUT_2_PULSES, l_data);
    }

    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBASLVCTL0(i_target, l_data));

    FAPI_INF("Initialize PBA Slave 1 ...");
    // Boot: 405 ICU/DCU.  This is a read/write slave.  Write gethering is
    // allowed, but with the shortest possible timeout.
    //
    // Run-Time: GPE 1 (but setup by OCC FW).  This is a read/write slave.
    // Write gathering is allowed, but with the shortest possible timeout.

    l_data.flush<0>();
    PREP_TP_TPBR_PBA_PBAO_PBASLVCTL1(i_target);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_ENABLE(                                                  l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_MATCH_VALUE( (OCI_MASTER_ID_ICU & OCI_MASTER_ID_DCU), l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_MID_CARE_MASK(   (OCI_MASTER_ID_ICU & OCI_MASTER_ID_DCU), l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_READ_TTYPE(       PBA_READ_TTYPE_CL_RD_NC,               l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_READ_PREFETCH_CTL(PBA_READ_PREFETCH_NONE,                l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_WRITE_TTYPE(      PBA_WRITE_TTYPE_DMA_PR_WR,             l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_WR_GATHER_TIMEOUT(PBA_WRITE_GATHER_TIMEOUT_2_PULSES,     l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_A(                                             l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_B(                                             l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_C(                                             l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL1_BUF_ALLOC_W(                                             l_data);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBASLVCTL1(i_target, l_data));

    FAPI_INF("Initialize PBA Slave 2 ...");
    // Boot: PGPE Boot.  This is a read/write slave.  Write gethering is
    // allowed, but with the shortest possible timeout.
    //
    // Run-Time: PGPE to memory.  This is a read/write slave.  Write gethering is
    // allowed, but with the shortest possible timeout.

    l_data.flush<0>();
    PREP_TP_TPBR_PBA_PBAO_PBASLVCTL2(i_target);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_ENABLE(                                                 l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_MATCH_VALUE(  OCI_MASTER_ID_PGPE,                   l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_MID_CARE_MASK(    OCI_MASTER_ID_MASK_ALL,               l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_TTYPE(       PBA_READ_TTYPE_CL_RD_NC,              l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_READ_PREFETCH_CTL(PBA_READ_PREFETCH_NONE,               l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_A(                                            l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_B(                                            l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_C(                                            l_data);
    SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_BUF_ALLOC_W(                                            l_data);

    if (i_phase == PBA_RUNTIME)
    {
        if (l_homerloc == fapi2::ENUM_ATTR_HOMER_LOCATION_CACHE)
        {
            FAPI_DBG("PBA Slave 2 setup for booting from CACHE");
            SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE(PBA_WRITE_TTYPE_LCO_M, l_data);
        }
        else
        {
            FAPI_DBG("PBA Slave 2 setup for booting from MEMORY");
            SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WRITE_TTYPE(PBA_WRITE_TTYPE_DMA_PR_WR, l_data);
        }

        SET_TP_TPBR_PBA_PBAO_PBASLVCTL2_WR_GATHER_TIMEOUT(PBA_WRITE_GATHER_TIMEOUT_2_PULSES, l_data);
    }

    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBASLVCTL2(i_target, l_data));

    // Slave 3 is not modified by this function
    FAPI_INF("Skipping PBA Slave 3 as this is owned by SBE ...");

fapi_try_exit:
    FAPI_IMP("<< pba_slave_setup");
#else
    FAPI_IMP("!! pba_slave_setup not supported on SBE platform.");
#endif
    return fapi2::current_err;
}  // end pba_slave_setup

/// -----------------------------------------------------------------------------
///  pba_bc_stop
/// -----------------------------------------------------------------------------
///
/// @brief Stop the BCDE and BCUE and then poll for their completion
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_bc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP(">>> pba_bc_stop...");

    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_data64;
    bool                l_bcde_stop_complete = false;
    bool                l_bcue_stop_complete = false;
    uint32_t            l_pollCount;

    l_data64.setBit<0>();
    // Stopping Block Copy Download Engine
    FAPI_TRY(fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL, l_data64),
             "Failed to set the BCDE control register");

    // Stopping Block Copy Upload Engine
    FAPI_TRY(fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCUE_CTL, l_data64),
             "Failed to set the BCUE control register");

    // Polling on, to verify that BCDE & BCUE are indeed stopped.
    for (l_pollCount = 0;
         l_pollCount < p10pba::MAX_PBA_BC_STOP_POLLS;
         l_pollCount++)
    {
        // Read the BCDE Status register to check for a stopped condition
        FAPI_TRY(fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_STAT, l_data64));
        FAPI_DBG("BCDE Status = 0x%016llX", uint64_t(l_data64));

        if (! l_data64.getBit<p10pba::PBA_BC_STAT_RUNNING>() )
        {
            FAPI_INF("BCDE Running Bit clear to indicate the stop condition");
            l_bcde_stop_complete = true;
        }

        // Read the BCUE Status register to check for stop condition
        FAPI_TRY(fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCUE_STAT, l_data64));
        FAPI_DBG("BCUE Status = 0x%016llX",  uint64_t(l_data64));

        if(! l_data64.getBit<p10pba::PBA_BC_STAT_RUNNING>())
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
            FAPI_TRY(fapi2::delay(p10pba::MAX_PBA_BC_STOP_POLLS * 1000, 2000000),
                     " fapi2::delay Failed ");   // In microseconds
        }
    }

    // Assert, if BCDE did not stop
    if (!l_bcde_stop_complete)
    {
        FAPI_TRY(fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCDE_STAT, l_data64));
        FAPI_ASSERT(false, fapi2::PM_PBA_BCDE_STOP_TIMEOUT()
                    .set_POLLCOUNT( p10pba::MAX_PBA_BC_STOP_POLLS)
                    .set_POLLVALUE(p10pba::MAX_PBA_BC_STOP_POLLS)
                    .set_CHIP(i_target)
                    .set_TP_TPBR_PBA_PBAO_BCDE_STAT(l_data64),
                    "PBA BCDE Stop Timeout");
    }

    // Assert, if BCUE did not stop
    if (!l_bcue_stop_complete)
    {
        FAPI_TRY(fapi2::getScom(i_target, TP_TPBR_PBA_PBAO_BCUE_STAT, l_data64));
        FAPI_ASSERT(false, fapi2::PM_PBA_BCUE_STOP_TIMEOUT()
                    .set_POLLCOUNT( p10pba::MAX_PBA_BC_STOP_POLLS)
                    .set_POLLVALUE( p10pba::MAX_PBA_BC_STOP_POLLS)
                    .set_CHIP(i_target)
                    .set_TP_TPBR_PBA_PBAO_BCUE_STAT(l_data64),
                    "PBA BCUE Stop Timeout");
    }

    FAPI_INF("Clear the BCDE and BCUE stop bits.");
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCDE_CTL, l_data64));
    FAPI_TRY(fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_BCUE_CTL, l_data64));

fapi_try_exit:

    FAPI_IMP("<<< pba_bc_stop...");
    return fapi2::current_err;
}

/// ----------------------------------------------------------------------------
/// pba_start  -- mode = PM_START
/// -----------------------------------------------------------------------------
///
/// @brief Clear PBA FIR & Config registers, set PBAX config register and
///        call pba_slave_setup.
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // Function not supported on SBE platform
#ifndef __PPE__
    FAPI_IMP(">> pba_start ...");

    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_data64 = 0;
    uint8_t l_attr_pbax_groupid;
    uint8_t l_attr_pbax_chipid;
    uint8_t l_attr_pbax_broadcast_vector;
    std::vector<uint64_t> l_topo_scoms;

    // Resetting PBACFGs (O and F) back values from HW spec
    PREP_TP_TPBR_PBA_PBAO_PBAOCFG(i_target);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBAOCFG(i_target, l_data64));

    l_data64.flush<0>();
    PREP_TP_TPBR_PBA_PBAF_PBAFCFG(i_target);
    SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_SLVFW_MAX_PRIORITY(                     l_data64);
    SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_BCE_MAX_PRIORITY(                       l_data64);
    SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_OPER_HANG_DIV(       PBA_OPER_HANG_DIV, l_data64);
    SET_TP_TPBR_PBA_PBAF_PBAFCFG_PBREQ_EXIT_HANG_DIV(       PBA_EXIT_HANG_DIV, l_data64);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAF_PBAFCFG(i_target, l_data64));

    // Clear the PBAF and PBA0 FIRs
    l_data64.flush<0>();
    PREP_TP_TPBR_PBA_PBAF_PBAFIR_RW(i_target);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAF_PBAFIR_RW(i_target, l_data64));
    PREP_TP_TPBR_PBA_PBAO_PBAFIR_RW(i_target);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBAFIR_RW(i_target, l_data64));

    // No action required for the following registers:
    // PBARBUFVAL[n] (PBA Read Buffer Valid Status Registers) : They are ROX
    // PBAPBOCR[n] (PBA PowerBus OverCommit Rate Registers) : They are read-only
    // PBABAR[n] (PBA Base Address Range Registers) : Handled outside this HWP
    // PBABARMSK[n] (PBA BAR Mask Register) : Handled outside this HWP
    // (Thus, during a reset, the BARS/MASKS are retained.)

    // ----------------------------------------------------------
    // Get attributes
    // ----------------------------------------------------------
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PBAX_GROUPID,
                            i_target,
                            l_attr_pbax_groupid));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PBAX_CHIPID,
                            i_target,
                            l_attr_pbax_chipid));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PBAX_BRDCST_ID_VECTOR,
                            i_target,
                            l_attr_pbax_broadcast_vector));
    FAPI_INF("PBAX Topology Configuration - GroupID: 0x%02X, ChipID: 0x%02X, BroadcastVector: 0x%02X",
             l_attr_pbax_groupid,
             l_attr_pbax_chipid,
             l_attr_pbax_broadcast_vector);

    FAPI_INF("Initialize PBAX Configuration ...");
    PREP_TP_TPBR_PBA_PBAO_PBAXCFG(i_target);
    l_data64.flush<0>();
    SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_GROUPID(            l_attr_pbax_groupid,               l_data64);
    SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_CHIPID(             l_attr_pbax_chipid,                l_data64);
    SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_BRDCST_GROUP(       l_attr_pbax_broadcast_vector,      l_data64);
    SET_TP_TPBR_PBA_PBAO_PBAXCFG_RCV_DATATO_DIV(         PBAX_DATA_TIMEOUT,                 l_data64);
    SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_COUNT_OVERCOM(PBAX_SND_RETRY_COMMIT_OVERCOMMIT,  l_data64);
    SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RETRY_THRESH(       PBAX_SND_RETRY_THRESHOLD,          l_data64);
    SET_TP_TPBR_PBA_PBAO_PBAXCFG_SND_RSVTO_DIV(          PBAX_SND_TIMEOUT,                  l_data64);
    FAPI_TRY(PUT_TP_TPBR_PBA_PBAO_PBAXCFG(i_target, l_data64));

    // Get the register values for the SCOMs to setup the topology id table
    FAPI_TRY(topo::get_topology_table_scoms(i_target, l_topo_scoms));

    // Setup the topology id tables for PBA
    FAPI_TRY(init_topo_id_tables(i_target, l_topo_scoms));

    // Perform PBA Slave setup to prepare for the runtime phase.
    FAPI_TRY(pba_slave_setup(i_target, PBA_RUNTIME));

fapi_try_exit:
    FAPI_IMP("<< pba_start ...");
#else
    FAPI_IMP("!! pba_start not supported on SBE platform.");
#endif
    return fapi2::current_err;
}


/// -----------------------------------------------------------------------------
/// pba_halt  -- mode = PM_HALT
/// -----------------------------------------------------------------------------
///
/// @brief Clear PBA registers including PBAX config & error registers and
///        then call pba_slave_reset and stop BCDE &BCUE.
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pba_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    using namespace scomt::proc;

    std::vector<uint64_t> v_pba_reset_regs;
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_BCDE_PBADR);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_BCDE_OCIBAR);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_BCUE_CTL);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_BCUE_SET);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_BCUE_PBADR);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_BCUE_OCIBAR);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_PBAXSHBR0);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_PBAXSHBR1);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_PBAXSHCS0);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_PBAXSHCS1);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_PBASLVCTL0);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_PBASLVCTL1);
    v_pba_reset_regs.push_back(TP_TPBR_PBA_PBAO_PBASLVCTL2);

    FAPI_IMP(">> pba_halt ...");

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
    // None presently defined

    // Reset PBAX errors via Configuration Register
    //     Bit 2: PBAXCFG_SND_RESET
    //     Bit 3: PBAXCFG_RCV_RESET
    l_data64.flush<0>().setBit<2, 2>();
    FAPI_INF("Resetting PBAX errors via PBAX config register 0x%08llX with "
             "value = 0x%16llX", TP_TPBR_PBA_PBAO_PBAXCFG, uint64_t(l_data64));
    FAPI_TRY(fapi2::putScom(i_target, TP_TPBR_PBA_PBAO_PBAXCFG, l_data64));

    // Perform PBA Slave setup to prepare for the boot phase.
    FAPI_TRY(pba_slave_setup(i_target, PBA_BOOT));

fapi_try_exit:
    FAPI_IMP("<< pba_halt ...");
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
// Function definition
// -----------------------------------------------------------------------------
fapi2::ReturnCode p10_pm_pba_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("> p10_pm_pba_init");

    if (i_mode == pm::PM_START)
    {
        FAPI_TRY(pba_start(i_target), " pba_start() failed.");
    }
    else if (i_mode == pm::PM_HALT)
    {
        FAPI_TRY(pba_halt(i_target), " pba_start() failed.");
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::PM_PBA_INIT_INCORRECT_MODE()
                    .set_PM_MODE(i_mode),
                    "Unknown mode 0x%08llx passed to p10_pm_pba_init.",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("< p10_pm_pba_init");
    return fapi2::current_err;
}
