/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_qme_init.C $    */
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
/// @file p10_pm_qme_init.C
/// @brief Initializes all QMEs of the given proc chip.

// *HWP HWP Owner       :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   David Du   <daviddu@us.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   2
// *HWP Consumed by     :   HB

///
/// High-level procedure flow:
/// @verbatim
///   if PM_HALT
///   - Halt the QME
///   if PM_START
///   - Clear error injection bits
///   - Clear QME Flag bit to be polled on
///   - Setup QME Block Copy to point to CPMR
///     - Read QME BCEBAR0 and adjust the value to the CPMR
///   - With a length value of the Hcode and common rings provided by
///     hcode_image_build via an attribute,  kick-off the BCE and poll for
///     completion
///   - Start the QME to allow the Hcode to boot.
///   - Poll QME Flag bit for QME boot completion
///   - set CUCR[PCB_SKEW_ADJ] per quad to equalize multicast times
///
///   - QME Hcode itself (not this procedure) will use the Block Copy Engine
///     to pull the Local Pstate Parameter Block and quad specific rings
///     into QME SRAM
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------

#include <vector>
#include <algorithm>
#include <p10_hcd_common.H>
#include <p10_pm_hcd_flags.h>
#include <p10_pm_qme_init.H>
#include <p10_scom_proc_3.H>
#include <p10_scom_proc_5.H>
#include <p10_scom_c_7.H>
#include <p10_scom_eq.H>
#include <p10_scom_c.H>
#include <p10_scom_perv.H>
#include <multicast_group_defs.H>
#include <p10_hcd_memmap_base.H>
#include <p10_fbc_utils.H>
#include <p10_scom_proc_7.H>
#include <p10_scom_proc_1.H>
#include <p10_scom_proc_d.H>
#include <p10_scom_proc_b.H>
#ifndef __PPE__
    #include <p10_tod_utils.H>
#endif

// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------

enum
{
    QME_ACTIVE              =   p10hcd::QME_FLAGS_STOP_READY,
    QME_TIMEOUT_MS          =   250,
    QME_TIMEOUT_MCYCLES     =   100,
    QME_POLLTIME_MS         =   1,
    QME_POLLTIME_MCYCLES    =   1,
    TIMEOUT_COUNT           =   QME_TIMEOUT_MS / QME_POLLTIME_MS,
    SIM_TIMEOUT_COUNT       =   QME_TIMEOUT_MCYCLES / QME_POLLTIME_MCYCLES,
    QME_BASE_ADDRESS        =   0,
    QME_HALT                =   1,
    HOMER_CPMR_OFFSET       =   0x200000,
    BCE_START               =   2,  // this bit is not in generated headers
    BCE_BUSY                =   scomt::eq::QME_BCECSR_BUSY,
    BCE_ERROR               =   scomt::eq::QME_BCECSR_ERROR,
    WRITE_TO_SRAM           =   scomt::eq::QME_BCECSR_RNW,
    BCE_BAR0_SEL            =   0,
    BCE_TYPE                =   0,
    BCE_SBASE               =   0,
    BCE_BAR_APERTURE_2_MB   =   0x01,
    BCE_STALL_MAX           =   4,
    CPMR_BASE               =   (2 * 1024 * 1024),
    MBASE_SHIFT             =   5,
    QME_PIG_REQ_INT_TYPE    =   1,
    QME_PIG_REQ_INT_TYPE_LEN   = 4,
    QME_PIG_REG             =   0x200e0030,
};

// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------

fapi2::ReturnCode qme_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode qme_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode initQmeBoot( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );

fapi2::ReturnCode get_functional_chiplet_info(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target ,
    std::vector<uint64_t>& o_ppe_addr_list,
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_EQ > >& o_eq_target_list );

fapi2::ReturnCode pcb_skew_adj(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target );


// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

/// @brief Initialize the  QME and related functions
/// @param [in] i_target Chip target
/// @param [in] i_mode   Control mode for the procedure
///                      PM_INIT, PM_RESET
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode p10_pm_qme_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP(">> p10_pm_qme_init");
    const char* PM_MODE_NAME_VAR;  //Defines storage for PM_MODE_NAME
    FAPI_IMP(" Execution mode %s", PM_MODE_NAME(i_mode));
    uint8_t                 fusedModeState = 0;

    // -------------------------------
    // Initialization:  perform order or dynamic operations to initialize
    // the STOP funciton using necessary Platform or Feature attributes.
    if ( pm::PM_START == i_mode )
    {
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE,
                               FAPI_SYSTEM,
                               fusedModeState),
                 "Error from FAPI_ATTR_GET for attribute ATTR_FUSED_CORE_MODE");

        // Boot the QME
        FAPI_TRY( qme_init( i_target ), "ERROR: Failed To Initialize  QME" );
        // Adjust for EQ placement
        FAPI_TRY( pcb_skew_adj( i_target ), "ERROR: Failed To adjust the PCB Skew" );
    }

    //-------------------------------
    // HALT: halt STOP function including the QME
    // so that it can reconfigured and reinitialized
    else if ( i_mode == pm::PM_HALT )
    {
        FAPI_TRY( qme_halt( i_target ), "ERROR: Failed To Reset QME");
    }

    // -------------------------------
    // Unsupported Mode
    else
    {
        FAPI_ERR("Unknown Mode Passed To p10_pm_qme_init. Mode %x ....", i_mode);
        FAPI_ASSERT(false,
                    fapi2::QME_BAD_MODE()
                    .set_BADMODE(i_mode),
                    "ERROR; Unknown Mode Passed To qme_init. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("<< p10_pm_qme_init");
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  QME Initialization Function
// -----------------------------------------------------------------------------

/// @brief Initializes the QME and related STOP functions on a chip
/// @param [in] i_target    Chip target
/// @retval FAPI_RC_SUCCESS else ERROR defined in xml

fapi2::ReturnCode qme_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target )
{
    // Function not supported on SBE platform
#ifndef __PPE__
    using namespace scomt::eq;
    using namespace scomt::perv;
    using namespace scomt::proc;

    // RTC 245822
    // remove this to use the auto-generated value once it bit shows up in the headers.
    const uint32_t QME_QMCR_STOP_SHIFTREG_OVERRIDE_EN = 29;

    fapi2::buffer<uint64_t>     l_qme_flag;
    fapi2::buffer<uint64_t>     l_xcr;
    fapi2::buffer<uint64_t>     l_xsr;
    fapi2::buffer<uint64_t>     l_iar;
    fapi2::buffer<uint64_t>     l_ir;
    fapi2::buffer<uint64_t>     l_dbg;
    fapi2::buffer<uint64_t>     l_qmcr;
    uint32_t                    l_timeout = TIMEOUT_COUNT;

    FAPI_IMP(">> qme_init");

    auto l_eq_mc_or  = i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_OR >(fapi2::MCGROUP_GOOD_EQ);
    auto l_eq_mc_and = i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_AND >(fapi2::MCGROUP_GOOD_EQ);
    auto l_eq_vector = i_target.getChildren<fapi2::TARGET_TYPE_EQ> (fapi2::TARGET_STATE_FUNCTIONAL);

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_IS_SIMULATION_Type is_sim;
    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, is_sim));

    if (is_sim)
    {
        l_timeout = SIM_TIMEOUT_COUNT;
    }

    // First check if QME_ACTIVE is not set in any OCCFLAG register
    FAPI_TRY( getScom( l_eq_mc_or, QME_FLAGS_RW, l_qme_flag ) );

    if( l_qme_flag.getBit<QME_ACTIVE>() == 1 )
    {
        FAPI_DBG("At least one ACTIVE bit found");

        // See which EQ(s) are active and deal with them
        for (auto& eq : l_eq_vector)
        {
            FAPI_TRY( getScom( eq, QME_FLAGS_RW, l_qme_flag ) );

            if( l_qme_flag.getBit<QME_ACTIVE>() == 1 )
            {
                fapi2::ATTR_CHIP_UNIT_POS_Type eq_pos;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                       eq,
                                       eq_pos),
                         "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");
                FAPI_INF( "WARNING: QME_ACTIVE Flag already set in QME Flag Register for QME %d. Continuing on after clear it.",
                          eq_pos);
                l_qme_flag.flush< 0 >();
                l_qme_flag.setBit< QME_ACTIVE >();
                FAPI_TRY( putScom( eq, QME_FLAGS_WO_CLEAR, l_qme_flag ),
                          "ERROR: Failed To Clear QME Active Bit In QME Flag Register" );
            }
        }
    }

    //clearing OPIT TYPE A interrupts
    {
        fapi2::buffer<uint64_t> l_pigData;
        fapi2::buffer<uint64_t> l_opitA0Data;
        fapi2::buffer<uint64_t> l_opitA1Data;
        fapi2::buffer<uint64_t> l_opitA2Data;
        fapi2::buffer<uint64_t> l_opitA3Data;
        bool l_intNotClr    =   true;
        l_pigData.flush<0>();
        l_opitA0Data.flush<0>();
        l_opitA1Data.flush<0>();
        l_opitA2Data.flush<0>();
        l_opitA3Data.flush<0>();
        l_pigData.insertFromRight( 0xA, QME_PIG_REQ_INT_TYPE, QME_PIG_REQ_INT_TYPE_LEN );

        FAPI_TRY( putScom( l_eq_mc_or, QME_PIG_REG, l_pigData ) );

        do
        {
            FAPI_TRY( getScom( i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV0, l_opitA0Data ) );
            FAPI_TRY( getScom( i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV1, l_opitA1Data ) );
            FAPI_TRY( getScom( i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV2, l_opitA2Data ) );
            FAPI_TRY( getScom( i_target, TP_TPCHIP_OCC_OCI_OCB_OPITASV3, l_opitA3Data ) );

            l_opitA0Data = ( l_opitA0Data & l_opitA1Data & l_opitA2Data & l_opitA3Data );

            if( l_opitA0Data == 0 )
            {
                l_intNotClr = false;
                break;
            }

            fapi2::delay( QME_POLLTIME_MS * 1000 * 1000, QME_POLLTIME_MCYCLES * 1000 * 1000 );
            l_timeout--;

        }
        while(( l_intNotClr ) && ( l_timeout > 0 ) );

        FAPI_ASSERT( ( false == l_intNotClr ),
                     fapi2::OPIT_INTERRUPT_NOT_CLEAR()
                     .set_CHIP(i_target)
                     .set_LOOP_COUNT(  l_timeout )
                     .set_OPIT_AND( l_opitA0Data ),
                     "Failed To Clear OPIT Interrupt");
    }

    l_timeout = TIMEOUT_COUNT;

    if (is_sim)
    {
        l_timeout = SIM_TIMEOUT_COUNT;
    }

    {
        fapi2::buffer<uint64_t>     l_rvid;
        fapi2::ATTR_RVRM_VID_Type   l_rvrm_rvid;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RVRM_VID, i_target, l_rvrm_rvid));
        l_rvid.flush<0>().insertFromRight( l_rvrm_rvid, QME_RVCR_RVID_VALUE, QME_RVCR_RVID_VALUE_LEN );
        FAPI_TRY( putScom( l_eq_mc_or, QME_RVCR, l_rvid ) );
        FAPI_INF("Setting Retention VID to %02X", l_rvrm_rvid);
    }

    {
        fapi2::buffer<uint64_t> l_tod_fsm_reg;
        fapi2::buffer<uint64_t> l_qme_flag_mask;

        l_qme_flag_mask.flush<0>().setBit<p10hcd::QME_FLAGS_TOD_SETUP_COMPLETE>();

        fapi2::ATTR_IS_MPIPL_Type l_mpipl;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL, FAPI_SYSTEM, l_mpipl))

        if (l_mpipl)
        {
            FAPI_INF("MPIPL: Clearing QME TOD Setup Complete Flag to avoid shadowing");
            FAPI_TRY( putScom( l_eq_mc_or, QME_FLAGS_WO_CLEAR, l_qme_flag_mask ) );
        }
        else
        {
            FAPI_INF("Syncing TOD Running State");
            FAPI_TRY(GET_TOD_FSM_REG(i_target, l_tod_fsm_reg));

            if (GET_TOD_FSM_REG_TOD_IS_RUNNING(l_tod_fsm_reg))
            {
                FAPI_INF("TOD is running! Setting QME TOD Setup Complete Flag");
                FAPI_TRY( putScom( l_eq_mc_or, QME_FLAGS_WO_OR, l_qme_flag_mask ) );
            }
            else
            {
                FAPI_INF("TOD is NOT running!  Clearing QME TOD Setup Complete Flag");
                FAPI_TRY( putScom( l_eq_mc_or, QME_FLAGS_WO_CLEAR, l_qme_flag_mask ) );
            }
        }
    }

    FAPI_TRY( initQmeBoot( i_target ), "p10_pm_qme_init Failed To Copy QME Hcode In To QME's SRAM" );

    FAPI_INF("Allow QMEs to have access to the shiftable core registers");
    l_qmcr.flush<0>().setBit<QME_QMCR_STOP_SHIFTREG_OVERRIDE_EN>();
    FAPI_TRY(fapi2::putScom(l_eq_mc_or, QME_QMCR_WO_CLEAR, l_qmcr),
             "Error during putscom of QME_QMCR_WO_CLEAR for shiftable regs access");

    FAPI_INF("Start the QMEs");
    l_xcr.flush< 0 >().insertFromRight( XCR_HARD_RESET, 1, 3 );
    FAPI_TRY( putScom( l_eq_mc_or, QME_SCOM_XIXCR, l_xcr ) );

    l_xcr.flush< 0 >().insertFromRight( XCR_RESUME, 1, 3 );
    FAPI_TRY( putScom( l_eq_mc_or, QME_SCOM_XIXCR, l_xcr ) );

    l_qme_flag.flush< 0 >();
    l_xsr.flush< 0 >();
    l_ir.flush< 0 >();
    l_dbg.flush< 0 >();

    FAPI_INF("Poll for all QMEs going Active");

    do
    {
        fapi2::delay( QME_POLLTIME_MS * 1000 * 1000, QME_POLLTIME_MCYCLES * 1000 * 1000 );

        FAPI_TRY( getScom( l_eq_mc_and, QME_FLAGS_RW, l_qme_flag ) );
        FAPI_TRY( getScom( l_eq_mc_or, QME_SCOM_XIDBGPRO, l_xsr ) );
        FAPI_TRY( getScom( l_eq_mc_or, QME_SCOM_XIRAMEDR, l_ir ) );
        FAPI_DBG( "Poll content: QME Flag: 0x%08llX; IR-EDR: 0x%016llX XSR-IAR: 0x%016llX DGB: 0x%016llX Timeout: %d",
                  l_qme_flag,
                  l_ir,
                  l_xsr,
                  l_dbg,
                  l_timeout );
    }
    while(!((l_qme_flag.getBit<QME_ACTIVE>() == 1) ||
            (l_xsr.getBit<XSR_HALTED_STATE>() == 1) ||
            (--l_timeout == 0)));

    FAPI_ASSERT( l_timeout != 0,
                 fapi2::QME_START_TIMEOUT()
                 .set_CHIP(i_target)
                 .set_OCC_FLAG_REG_VAL( l_qme_flag )
                 .set_XSR_REG_VAL( l_xsr )
                 .set_PPE_STATE_MODE(XCR_RESUME),
                 "QME start timed out");

    if (l_xsr.getBit<XSR_HALTED_STATE>() == 1)
    {
        for (auto& eq : l_eq_vector)
        {
            FAPI_TRY( getScom( eq, QME_SCOM_XIDBGPRO, l_xsr ) );

            if( l_xsr.getBit<XSR_HALTED_STATE>() == 1 )
            {
                fapi2::ATTR_CHIP_UNIT_POS_Type eq_pos;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                       eq,
                                       eq_pos),
                         "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");
                FAPI_ERR( "QME %d Halted", eq_pos);
            }
        }

        FAPI_ASSERT(false,
                    fapi2::QME_START_HALTED()
                    .set_CHIP(i_target)
                    .set_OCC_FLAG_REG_VAL( l_qme_flag )
                    .set_XSR_REG_VAL( l_xsr ),
                    "QME start halted");
    }

    FAPI_INF( "QME was activated successfully!!!!" );

fapi_try_exit:
    FAPI_IMP("<< qme_init");
#else
    FAPI_IMP("!! qme_start not supported on SBE platform.");
#endif  // SBE Platform
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//   QME Function
// -----------------------------------------------------------------------------

/// @brief  halts the QME
/// @param  [in] i_target    Chip target
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode qme_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace eq;
    using namespace c;
    fapi2::buffer<uint64_t> l_data64;
    uint32_t                l_timeout_in_MS = 100;
    uint8_t CL2_START_POS = 5;

    FAPI_IMP(">> qme_halt...");

    // mc_or target will be used for putscom too
    auto l_eq_mc_or  =
        i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_OR >(fapi2::MCGROUP_GOOD_EQ);
    auto l_eq_mc_and =
        i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_AND >(fapi2::MCGROUP_GOOD_EQ);
    fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > core_mc_target_and =
        i_target.getMulticast< fapi2::MULTICAST_AND >(fapi2::MCGROUP_GOOD_EQ, fapi2::MCCORE_ALL);

    FAPI_INF("Send HALT command via XCR...");
    l_data64.flush<0>().insertFromRight( XCR_HALT, 1, 3 );
    FAPI_TRY( putScom( l_eq_mc_or, QME_SCOM_XIXCR, l_data64 ) );

    FAPI_INF("Poll for HALT State via XSR...");

    do
    {
        FAPI_TRY( getScom( l_eq_mc_and, QME_SCOM_XIDBGPRO, l_data64 ) );
        fapi2::delay( QME_POLLTIME_MS * 1000 * 1000, QME_POLLTIME_MCYCLES * 1000 * 1000 );
    }
    while( ( l_data64.getBit<XSR_HALTED_STATE>() == 0 ) && ( --l_timeout_in_MS != 0 ) );

    if( 0 == l_timeout_in_MS )
    {
        FAPI_ASSERT( false,
                     fapi2::QME_HALT_TIMEOUT()
                     .set_CHIP(i_target)
                     .set_PPE_STATE_MODE(XCR_HALT),
                     "STOP Reset Timeout");
    }

    FAPI_INF("Clear ASSERT_SPECIAL_WKUP_DONE and AUTO_SPECIAL_WAKEUP_DISABLE, Assert PM_EXIT if not STOP_GATED");
    l_data64.flush<0>().setBit < QME_SCSR_ASSERT_SPECIAL_WKUP_DONE > ();
    l_data64.setBit < QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE > ();
    FAPI_TRY( putScom( core_mc_target_and, QME_SCSR_WO_CLEAR, l_data64 ) );

    for ( auto l_core_target : i_target.getChildren<fapi2::TARGET_TYPE_CORE>( fapi2::TARGET_STATE_FUNCTIONAL ) )
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_core_unit_pos;
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                l_core_target,
                                l_core_unit_pos));

        l_core_unit_pos = l_core_unit_pos % 4;

        fapi2::Target<fapi2::TARGET_TYPE_EQ> l_eq_target = l_core_target.getParent<fapi2::TARGET_TYPE_EQ>();

        FAPI_TRY( fapi2::getScom( l_eq_target, CPLT_CTRL3_RW, l_data64 ) );

        if (!l_data64.getBit(l_core_unit_pos + CL2_START_POS))
        {
            continue;
        }

        FAPI_TRY( fapi2::getScom( l_core_target, scomt::c::QME_SSH_SRC, l_data64 ) );

        if( l_data64.getBit<0>() != 1)
        {
            l_data64.flush<0>().setBit< QME_SCSR_ASSERT_PM_EXIT >();
            FAPI_TRY( putScom( l_core_target, QME_SCSR_WO_OR, l_data64 ) );
        }
    }

    FAPI_INF("Clear QME_ACTIVE in OCC Flag Register...");
    l_data64.flush<0>().setBit<QME_ACTIVE>();
    FAPI_TRY( putScom( l_eq_mc_or, QME_FLAGS_RW, l_data64 ) );

fapi_try_exit:
    FAPI_IMP("<< qme_halt...");
    return fapi2::current_err;
}


///
/// @brief Initialize the QME topology id table entries
/// @param[in] c                Reference to core target
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
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST > & eq,
    const std::vector<uint64_t>& topo_scoms)
{
    using namespace scomt::eq;

    FAPI_DBG(">> init_topo_id_tables");
    PREP_QME_SCOM_PBTXTR0(eq);
    FAPI_TRY(PUT_QME_SCOM_PBTXTR0(eq, topo_scoms[0]));
    PREP_QME_SCOM_PBTXTR1(eq);
    FAPI_TRY(PUT_QME_SCOM_PBTXTR1(eq, topo_scoms[1]));
    PREP_QME_SCOM_PBTXTR2(eq);
    FAPI_TRY(PUT_QME_SCOM_PBTXTR2(eq, topo_scoms[2]));
    PREP_QME_SCOM_PBTXTR3(eq);
    FAPI_TRY(PUT_QME_SCOM_PBTXTR3(eq, topo_scoms[3]));
    FAPI_DBG("<< init_topo_id_tables");
fapi_try_exit:
    return fapi2::current_err;
}

// Function not supported on SBE platform
#ifndef __PPE__

/// @brief Kicks off the boot flow of QME.
/// @param [in] i_target Chip target
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml
fapi2::ReturnCode initQmeBoot(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target )
{
    using namespace scomt;
    using namespace proc;
    using namespace eq;
    uint64_t l_cpmrBase         =   0;
    uint32_t l_qmeHcodeBlock    =   0;
    fapi2::buffer<uint64_t> l_bceBarReg;
    fapi2::buffer<uint64_t> l_bceCsrReg;
    fapi2::buffer<uint64_t> l_qmcrReg;
    fapi2::buffer<uint64_t> l_qmcData;
    uint32_t l_bceTimeOut = TIMEOUT_COUNT;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    std::vector<uint64_t> l_topo_scoms;

    FAPI_INF(">> initQmeBoot");

    // mc_or target will be used for putscom too
    auto l_eq_mc_and  =
        i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_AND >(fapi2::MCGROUP_GOOD_EQ);
    auto l_eq_mc_or  =
        i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_OR >(fapi2::MCGROUP_GOOD_EQ);
    auto l_eq_mc_cmp =
        i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_COMPARE >(fapi2::MCGROUP_GOOD_EQ);

    fapi2::ATTR_QME_BOOT_CONTROL_Type bootMode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_QME_BOOT_CONTROL,
                           i_target,
                           bootMode),
             "Error from FAPI_ATTR_GET for attribute ATTR_QME_BOOT_CONTROL");

    do
    {
        // No Block Copy means the SRAM was inserted externally
        if ( bootMode == fapi2::ENUM_ATTR_QME_BOOT_CONTROL_HCODE_ALLSCAN_NOBC ||
             bootMode == fapi2::ENUM_ATTR_QME_BOOT_CONTROL_HCODE_CMNSCAN_NOBC ||
             bootMode == fapi2::ENUM_ATTR_QME_BOOT_CONTROL_HCODE_ONLY_NOBC )
        {
            FAPI_INF("Skipping QME block copy");
            break;
        }

        // Get the register values for the SCOMs to setup the topology id table
        FAPI_TRY(topo::get_topology_table_scoms(i_target, l_topo_scoms));
        FAPI_TRY(init_topo_id_tables(l_eq_mc_or, l_topo_scoms));

        // The Base HOMER address it placed in BCEBAR0 by p10_pm_set_homer_bar
        // and includes the region size. The hardware is read as some systems
        // may move HOMER upon PM Restart actions.
        FAPI_TRY(fapi2::getScom(l_eq_mc_cmp, QME_BCEBAR0, l_bceBarReg));
        FAPI_DBG("l_bceBar0Reg BEFORE: 0x%016llX", l_bceBarReg);

        // Clear the size field to set specifically for QME
        l_bceBarReg.clearBit(61, 3);
        l_cpmrBase |=  (l_bceBarReg | CPMR_BASE | BCE_BAR_APERTURE_2_MB);
        FAPI_DBG("l_cpmrBase AFTER: 0x%016llX", l_cpmrBase);

        FAPI_TRY( putScom( l_eq_mc_or, QME_BCEBAR0, l_cpmrBase ) );
        FAPI_TRY( putScom( l_eq_mc_or, QME_BCEBAR1, l_cpmrBase ) );
        // Check for invalid hardare state
        FAPI_TRY( getScom( l_eq_mc_or, QME_BCECSR, l_bceCsrReg ) );

        if (l_bceCsrReg.getBit( BCE_ERROR ))
        {
            FAPI_ASSERT( false,
                         fapi2::QME_BCE_HW_ERR()
                         .set_CHIP(i_target),
                         "Block Copy Engine Found In Error State Before Initiating QME Hcode Transfer");
        }

        if (l_bceCsrReg.getBit( BCE_BUSY ))
        {
            FAPI_ASSERT( false,
                         fapi2::QME_BCE_BUSY_ERR()
                         .set_CHIP(i_target),
                         "Block Copy Engine Found In Busy State Before Initiating QME Hcode Transfer");
        }

        // Determine how much to block copy
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_QME_HCODE_BLOCK_COUNT,
                                FAPI_SYSTEM,
                                l_qmeHcodeBlock));
        FAPI_DBG("Block copy count = %d (0x%X)", l_qmeHcodeBlock, l_qmeHcodeBlock);

        l_bceCsrReg.flush<0>().setBit<BCE_START>().setBit<WRITE_TO_SRAM>();
        l_bceCsrReg.insertFromRight( BCE_BAR0_SEL, QME_BCECSR_BARSEL, 1 );
        l_bceCsrReg.insertFromRight( BCE_TYPE, QME_BCECSR_TYPE, QME_BCECSR_TYPE_LEN );
        l_bceCsrReg.insertFromRight( l_qmeHcodeBlock, QME_BCECSR_NUM_BLOCKS, QME_BCECSR_NUM_BLOCKS_LEN );
        l_bceCsrReg.insertFromRight( QME_IMAGE_CPMR_OFFSET >> MBASE_SHIFT, QME_BCECSR_MBASE, QME_BCECSR_MBASE_LEN );
        FAPI_DBG("l_bceCsrReg AFTER: 0x%016llX", l_bceCsrReg);

        //Kick off block copy
        l_qmcrReg.flush<0>().setBit( QME_QMCR_BCECSR_OVERRIDE_EN );
        FAPI_TRY( putScom( l_eq_mc_or, QME_QMCR_SCOM2, l_qmcrReg ) );

        FAPI_TRY( putScom( l_eq_mc_or, QME_BCECSR, l_bceCsrReg ) );
        FAPI_INF( "QME Hcode Transfer Initiated" );

        uint32_t l_qmeRunningCount = l_qmeHcodeBlock;
        uint32_t loop_count = 0;
        FAPI_DBG("l_qmeRunningCount START: %u (0x%X)", l_qmeRunningCount, l_qmeRunningCount);

        do
        {
            fapi2::delay(QME_POLLTIME_MS * 1000, QME_POLLTIME_MCYCLES * 1000 * 1000);
            FAPI_TRY( getScom( l_eq_mc_and, QME_BCECSR, l_bceCsrReg ) );
            l_bceCsrReg.extractToRight(l_qmeRunningCount, QME_BCECSR_NUM_BLOCKS, QME_BCECSR_NUM_BLOCKS_LEN );
            FAPI_DBG("l_qmeRunningCount LOOP: %u (0x%X)", l_qmeRunningCount, l_qmeRunningCount);
            ++loop_count;
        }
        while( ( l_bceCsrReg.getBit<BCE_BUSY>() == 1 ) && ( --l_bceTimeOut != 0 ) );

        FAPI_DBG("After loop l_bceCsrReg: 0x%016llX", l_bceCsrReg );

        FAPI_ASSERT( l_bceTimeOut,
                     fapi2::QME_HCODE_TRANSFER_FAILED()
                     .set_CHIP(i_target),
                     "Block Copy Engine Failed To Complete Transfer of QME Hcode and Timed Out");

        FAPI_INF( "QME Hcode Transfer Completed" );
    }
    while(0);

fapi_try_exit:
    FAPI_INF("<< initQmeBoot");
    return fapi2::current_err;
}

#endif  // SBE Platform

/// @brief Set the PCB Skew Adjustment per EQ and per core.
/// @param [in] i_target Chip target
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml
fapi2::ReturnCode pcb_skew_adj(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target )
{
    using namespace scomt;
    using namespace proc;
    using namespace eq;
    using namespace c;

    FAPI_INF(">> pcb_skew_adj");

    fapi2::buffer<uint64_t>  adjust_value;

    auto l_eq_vector = i_target.getChildren<fapi2::TARGET_TYPE_EQ> (fapi2::TARGET_STATE_FUNCTIONAL);

    // See which EQ(s) are active and deal with them
    for (auto& eq : l_eq_vector)
    {
        fapi2::buffer<uint64_t> l_cucr;

        auto l_core_vector = eq.getChildren<fapi2::TARGET_TYPE_CORE> (fapi2::TARGET_STATE_FUNCTIONAL);

        fapi2::ATTR_CHIP_UNIT_POS_Type eq_pos;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               eq,
                               eq_pos),
                 "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");

        // EQ 0 and 1 gets 0; EQ 2 and 3 gets 1; EQ 4 and 5 gets 2; EQ 6 and 7 gets 3
        adjust_value = eq_pos >> 1;

        for (auto& core : l_core_vector)
        {
            l_cucr.flush<0>().insertFromRight<CPMS_CUCR_PCB_SKEW_ADJ, CPMS_CUCR_PCB_SKEW_ADJ_LEN> (7);
            FAPI_TRY( putScom( core, CPMS_CUCR_WO_CLEAR, l_cucr ) );

            // Only EQs 2 through 7 get a new value
            if (eq_pos > 1)
            {
                l_cucr.flush<0>().insertFromRight<CPMS_CUCR_PCB_SKEW_ADJ, CPMS_CUCR_PCB_SKEW_ADJ_LEN>(adjust_value);
                FAPI_TRY( putScom( core, CPMS_CUCR_SCOM2, l_cucr ) );
            }
        }
    }

fapi_try_exit:
    FAPI_INF("<< pcb_skew_adj");
    return fapi2::current_err;
}
