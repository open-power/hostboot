//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/fapiTestHwpFfdc.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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

    fapi::ReturnCodeFfdc::addEIFfdc(o_rc, l_ffdc);

    FAPI_INF("hwpTestFfdc1: End HWP");
    return fapi::FAPI_RC_SUCCESS;
}

} // extern "C"
