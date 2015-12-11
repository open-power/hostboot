/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp_fbc_cd.C $          */
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
/// @file p9_build_smp_fbc_cd.C
/// @brief  Fabric configuration (hotplug, CD) functions
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp_fbc_cd.H>
#include <p9_build_smp_adu.H>

extern "C" {


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// structure encapsulating serial configuration load programming
    struct p9_build_smp_sconfig_def
    {
        uint8_t select;                               // ID/select for chain
        uint8_t length;                               // number of bits to load
        bool use_slow_clock;                          // use 16:1 slow clock? (EX)
        bool use_shadow[P9_BUILD_SMP_NUM_SHADOWS];  // define which shadows to set
    };


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// NOTE: see comments above function prototype in header
    fapi2::ReturnCode p9_build_smp_set_fbc_cd(p9_build_smp_system& i_smp)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;

        // Chip/Node map iterators
        std::map<p9_fab_smp_node_id, p9_build_smp_node>::iterator n_iter;
        std::map<p9_fab_smp_chip_id, p9_build_smp_chip>::iterator p_iter;

        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             ++n_iter)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 ++p_iter)
            {

                // TODO: RTC 147511 - Call initfile
                // Call initfile when available to program center/east/west chains
                FAPI_DBG("Invoking initfile %s",
                         "TODO RTC 147511 - Replace with initfile name here");
#if 0
                // Run initfile to program chains
                FAPI_TRY(p9_build_smp_set_sconfig(p_iter->second),
                         "p9_build_smp_set_sconfig() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
#endif

                // Issue single switch CD to force all updates to occur
                FAPI_TRY(p9_build_smp_switch_cd(p_iter->second, i_smp),
                         "p9_build_smp_switch_cd returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

    fapi_try_exit:
        FAPI_INF("End");
        return fapi2::current_err;
    }

} // extern "C"
