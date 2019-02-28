/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2PlatGetVpdOcmbChipTest.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

#ifndef __GET_VPD_OCMB_CHIP_TEST_H
#define __GET_VPD_OCMB_CHIP_TEST_H

/**
 * @file fapi2GetVpdOcmbChipTest.H
 * @brief platGetVpd for OCMB CHIP memory test cases
 */

#include <cxxtest/TestSuite.H>

class fapi2PlatGetVpdOcmbChipTest : public CxxTest::TestSuite
{
    public:
    /**
     * @brief OCMB_CHIP platGetVpd EFD tests
     *
     * Test the platGetVPD EFD interface. Based on a VPDInfo configuration,
     * verify the expected direct memory vpd is returned.
     * There is a dependency to update standalone simics direct memory
     * (dimmspd.dat) for the configuration to map to a keyword.
     */
    void testPlatGetVPD_EFD();

};  // end class fapi2PlatGetVpdOcmbChipTest


#endif
