/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/hwpistepud.C $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file hwpudistep.C
 *
 *  @brief Implementation of HwpSvcUserDetailsIstep
 */
#include <hbotcompid.H>
#include <hwpistepud.H>
#include <hwpf/istepreasoncodes.H>

using namespace ISTEP_ERROR;

//------------------------------------------------------------------------------
HwpUserDetailsIstep::HwpUserDetailsIstep( errlHndl_t i_err )
{
    HwpUserDetailsIstepErrorData * l_pBuf =
        reinterpret_cast<HwpUserDetailsIstepErrorData *>(
                reallocUsrBuf(sizeof(HwpUserDetailsIstepErrorData)));

    l_pBuf->eid = i_err->eid();

    l_pBuf->reasoncode = i_err->reasonCode();

    // Set up ErrlUserDetails instance variables
    iv_CompId = HWPF_COMP_ID;
    iv_Version = 1;
    iv_SubSection = HWP_UDT_STEP_ERROR_DETAILS;
}

//------------------------------------------------------------------------------
HwpUserDetailsIstep::~HwpUserDetailsIstep()
{

}


