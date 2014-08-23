/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_dimm_power_test/mss_dimm_power_test.C $ */
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
// $Id: mss_dimm_power_test.C,v 1.4 2014/09/08 21:15:02 whs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_dimm_power_test.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_dimm_power_test
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Joab Henderson    Email: joabhend@us.ibm.com
// *! BACKUP NAME : Michael Pardeik   Email: pardeik@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// DESCRIPTION:
// The purpose of this procedure is to run an insitu power test on ISDIMMs to determine max power draw
//
// TODO:
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | joabhend |04-APR-13| Shell code - Only returns success
//   1.2   | whs      |27-AUG-14| Update Shell to new interface



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <mss_dimm_power_test.H>
#include <fapi.H>

extern "C" {

   using namespace fapi;


   // Procedures in this file
fapi::ReturnCode mss_dimm_power_test(
                   std::vector<fapi::Target> & i_targets,
                   const mss_dimm_power_test_command i_command,
                   uint32_t &io_version,
                   bool     i_recalc);
//******************************************************************************
//
//******************************************************************************
fapi::ReturnCode mss_dimm_power_test(
                   std::vector<fapi::Target> & i_targets,
                   const mss_dimm_power_test_command i_command,
                   uint32_t &io_version,
                   bool     i_recalc)
{
   fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;


    FAPI_IMP ("mss_dimm_power_test command=%d",i_command);
    switch (i_command)
    {

        // return calculation dependencies hashed into an algorithm version
        case RETURN_ALGORITHM_VERSION:
            {
                struct calculation_dependencies  // example dependencies
                {
                    uint8_t   mrwDimmPowerCurvePercentUplift;
                    uint32_t  mrwMemThrottleDenominator;
                    uint32_t  mrwMaxDramDataBusUtil;
                    uint32_t  algorithmVersion;
                } cd;

                io_version = ALGORITHM_RESET; // initialize to invalid version

                l_rc = FAPI_ATTR_GET(ATTR_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT,
                                      NULL, cd.mrwDimmPowerCurvePercentUplift);
                if (l_rc) break; // exit with error

                l_rc = FAPI_ATTR_GET(ATTR_MRW_MEM_THROTTLE_DENOMINATOR,
                                      NULL, cd.mrwMemThrottleDenominator);
                if (l_rc) break; // exit with error

                l_rc = FAPI_ATTR_GET(ATTR_MRW_MAX_DRAM_DATABUS_UTIL,
                                      NULL, cd.mrwMaxDramDataBusUtil);
                if (l_rc) break; // exit with error

                cd.algorithmVersion = ALGORITHM_VERSION;

                // Hwp writer: insert hash of dependent attributes
                //       and version here ..
                // io_verion = FAPI_GEN_HASH(FAPI::HASH::CRC32,
                //                           cd,
                //                           sizeof(cd);
                io_version = ALGORITHM_VERSION; // fake return value for testing
                                               // Hwp writer: replace with
                                               // hashed value.
            }
            break;

        // calculate power curves if advised due to algorithm change or hw
        // change. Validate existing values if not advised, and recalculate
        // if necessary.
        case CALCULATE:
            {
                bool l_recalc = i_recalc;
                // validate values if not advised to recalculate
                if (!l_recalc)
                {
                    // Hwp writer: insert validation here
                    FAPI_DBG ("mss_dimm_power_test validate power curves");
                    l_recalc = true;  //if necessary to recalculate
                }
                if (l_recalc)
                {
                    //Hwp writer: insert calculation of power curve values
                    FAPI_DBG ("mss_dimm_power_test calculate power curves");
                }
            }
            break;
        default:
            {
                FAPI_ERR ("mss_dimm_power_test unexpected command %d",
                                                             i_command);
                // Hwp writer: l_rc = error
            }
   }
   return l_rc;
}

} //end extern C

