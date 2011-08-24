//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/fapiFfdcHwpData.H $
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
 *  @file fapiFfdcHwpData.H
 *
 *  @brief Defines all FFDC data that can be returned by FFDC HWPs
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *
 */

#ifndef FAPIFFDCHWPDATA_H_
#define FAPIFFDCHWPDATA_H_

namespace fapi
{

/**
 * @brief An FFDC structure contining a single uint64_t of data
 */
struct TestFfdc1
{
    uint64_t iv_data;
};

}

#endif // FAPIFFDCHWPDATA_H_

