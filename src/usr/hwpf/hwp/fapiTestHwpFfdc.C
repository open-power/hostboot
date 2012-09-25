/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/fapiTestHwpFfdc.C $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
 *  @file fapiTestHwpFfdc.C
 *
 *  @brief Implements a simple test Hardware Procedure that collects FFDC data
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *                          mjjones     10/06/2011  Updated due to new ErrorInfo
 *                                                  design.
 *
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

#include <fapiTestHwpFfdc.H>

extern "C"
{

//******************************************************************************
// hwpTestFfdc1 function
//******************************************************************************
fapi::ReturnCode hwpTestFfdc1(const fapi::Target & i_target,
                              fapi::ReturnCode & o_rc)
{
    FAPI_INF("hwpTestFfdc1: Start HWP (FFDC HWP)");

    // Collect a uint64_t worth of FFDC
    uint64_t l_ffdc = 0x1122334455667788ULL;

    // Add FFDC specified by RC_TEST_ERROR_B
    uint64_t & UNIT_TEST_FFDC_DATA = l_ffdc;
    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_TEST_ERROR_B);

    FAPI_INF("hwpTestFfdc1: End HWP");
    return fapi::FAPI_RC_SUCCESS;
}

} // extern "C"
