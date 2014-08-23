/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_dimm_power_test/mss_dimm_power_test.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: mss_dimm_power_test.H,v 1.2 2014/08/27 20:13:20 whs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_dimm_power_test.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_throttle_to_power.H
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Joab Henderson    Email: joabhend@us.ibm.com
// *! BACKUP NAME : Michael Pardeik   Email: pardeik@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// Header file for mss_dimm_power_test.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | joabhend |04-APR-13| First Draft.
//   1.2   | whs      |27-AUG-14| Update Shell to new interface


#ifndef MSS_DIMM_POWER_TEST_H_
#define MSS_DIMM_POWER_TEST_H_

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>

//----------------------------------------------------------------------
//  Defines
//----------------------------------------------------------------------

    const uint32_t ALGORITHM_RESET = 0; // invalid algorithm version

    // change this value for each new algorithm version
    const uint32_t ALGORITHM_VERSION = 1;

//----------------------------------------------------------------------
//  ENUMs
//----------------------------------------------------------------------

    enum mss_dimm_power_test_command
    {
        RETURN_ALGORITHM_VERSION, // return hwp algorithm version
        CALCULATE,                // calculate and save power curve
    };

//----------------------------------------------------------------------
//  Data Types
//----------------------------------------------------------------------

typedef fapi::ReturnCode (*mss_dimm_power_test_FP_t)
                   (std::vector<fapi::Target> &,
                    const    mss_dimm_power_test_command i_command,
                    uint32_t &io_version,
                    bool     i_recalc);

extern "C"
{

/**
 * @brief mss_dimm_power_test procedure. Run power test on ISDIMMs to determine max power draw
 *
 * @param[in]   std::vector<fapi::Target> l_targets  Reference to vector
 *                            of Centaur Targets in a particular power domain
 *          RETURN_ALGORITHM_VERSION - empty list
 *          CALCULATE - list of mem buff targets with same vme_id
 * @param[in]      i_command  mss_dimm_power_test_command
 * @param[in,out]  io_version
 *          RETURN_ALGORITHM_VERSION -input is persistent algorithm version
 *                                    output is current hwp algorithm version
 *          CALCULATE - NA
 * @param[in]      i_recalc   advise a recalculation
 *          RETURN_ALGORITHM_VERSION - NA
 *          CALCULATE - true: versions don't match or hardware has changed
                        false: versions match and no hardware has changed
 *
 * @return ReturnCode
 */

    fapi::ReturnCode mss_dimm_power_test(
                   std::vector<fapi::Target> & i_targets,
                   const mss_dimm_power_test_command i_command,
                   uint32_t &io_version,
                   bool     i_recalc);


} // extern "C"

#endif // MSS_DIMM_POWER_TEST_H_
