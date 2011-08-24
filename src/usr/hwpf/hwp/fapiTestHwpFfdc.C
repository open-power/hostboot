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
 *
 */

#include <fapiTestHwpFfdc.H>

extern "C"
{

//******************************************************************************
// hwpTestFfdc1 function
//******************************************************************************
fapi::ReturnCode hwpTestFfdc1(const fapi::Target & i_target,
                              fapi::TestFfdc1 & o_ffdc)
{
    FAPI_INF("Performing FFDC HWP: hwpTestFfdc1");

    // Just set data to output structure. A real FFDC HWP would do a hardware
    // access to get FFDC
    fapi::ReturnCode l_rc;

    o_ffdc.iv_data = 0x11223344;

    return l_rc;
}

} // extern "C"
