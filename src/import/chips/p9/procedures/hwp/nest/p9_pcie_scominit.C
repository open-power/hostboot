/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pcie_scominit.C $              */
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
//-----------------------------------------------------------------------------------
//
/// @file p9_pcie_scominit.C
/// @brief Apply scom inits to PCIechiplets
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by:
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_pcie_scominit.H>

extern "C" {

//-----------------------------------------------------------------------------------
// HWP entry point
//-----------------------------------------------------------------------------------
    fapi2::ReturnCode p9_pcie_scominit(const
                                       fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        //return code
        fapi2::ReturnCode rc;

        //mark HWP entry
        FAPI_INF("p9_pcie_scominit: Entering...\n");

        do
        {

        }
        while(0);

        return rc;
    }

} //extern "C"
