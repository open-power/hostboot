/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_hcode_image_build.C $           */
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
/// @file   p9_hcode_image_build.C
/// @brief  implements HWP interface that builds the STOP image.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          1
/// *HWP Consumed by:    Hostboot, Phyp
//
//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_hcode_image_build.H>

fapi2::ReturnCode p9_hcode_image_build( CONST_FAPI2_PROC& i_procTgt,
                                        void* const i_pImageIn,
                                        void* o_pImageOut,
                                        SysPhase_t i_phase,
                                        ImageType_t i_imgType,
                                        void*     i_pBuf )
{
    FAPI_IMP("Entering p9_hcode_image_build");

    FAPI_IMP("Exit p9_hcode_image_build" );
    return fapi2::FAPI2_RC_SUCCESS;
}
