/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_throttle_sync.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// ----------------------------------------------------------------------------
/// @file  p9_throttle_sync.H
///
/// @brief Perform p9_throttle_sync HWP
///
/// The purpose of this procedure is to triggers sync command from MC to
/// actually load the throttle values into the Centaurs.
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_throttle_sync.H>

extern "C" {

///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------

///
/// @brief p9_throttle_sync procedure entry point
/// See doxygen in p9_throttle_sync.H
///
    fapi2::ReturnCode p9_throttle_sync(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Entering p9_throttle_sync");
        fapi2::ReturnCode l_rc;
        uint8_t l_unitPos = 0;

        // Get the functional MCAs on this proc
        auto l_mcaChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCA>();

        if (l_mcaChiplets.size() > 0)
        {
            // MCA found, proc is a Nimbus.
            // TODO: Wait for instructions on what to do with Nimbus
        }
        else
        {

            // See if this is a Cumulus
            auto l_dmiChiplets = i_target.getChildren<fapi2::TARGET_TYPE_DMI>();

            if (l_dmiChiplets.size() == 0)
            {
                // Note: You may have none of DMI nor MCA but it's a valid state;
                // therefore, don't flag an error.
                FAPI_INF("p9_throttle_sync: No functional MCs found from target.");
                return l_rc;
            }

            // DMIs found, proc is a Cumulus.
            for (auto itr = l_dmiChiplets.begin();
                 itr != l_dmiChiplets.end();
                 ++itr)
            {
                // Get the MC position
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, (*itr), l_unitPos),
                         "p9_throttle_sync: Error getting ATTR_CHIP_UNIT_POS "
                         "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

                FAPI_INF("p9_throttle_sync: working on MC %d\n", l_unitPos);

                //TODO: Need more info from Cumulus to do throttle sync
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting p9_throttle_sync");
        return fapi2::current_err;
    }

} // extern "C"
