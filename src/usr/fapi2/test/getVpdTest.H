/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/getVpdTest.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __GETVPDTEST_H
#define __GETVPDTEST_H

//RTC:257497-Update with new vpd targets and types

/**
 * @file getVpdTest.H
 * @brief getVpd for MCS memory test cases
 */

#include <stdint.h>

/**
 * @brief MCS getVpd MR tests
 *
 * Test the getVPD MR interface. Based on a VPDInfo configuration,
 * verify the expected direct memory vpd is returned.
 * There is a dependency to update standalone simics direct memory (dvpd.dat)
 * for the configuration to map to a keyword, but there is no data dependency.
 * expected data.
 */
void testGetVPD_MR(void);

/**
 * @brief MCS getVpd MT tests
 *
 * Test the getVPD MT interface. Based on a VPDInfo configuration,
 * verify the expected direct memory vpd is returned.
 * There is a dependency to update standalone simics direct memory (dvpd.dat)
 * for the configuration to map to a keyword, but there is no data dependency.
 */
void testGetVPD_MT(void);

/**
 * @brief p9_get_mem_vpd_keyword MR decode tests
 *
 * Test the p9_get_mem_vpd_keyword decode MR interface. Based on a VPDInfo
 * configuration, verify the expected keyword is returned.
 */
void testDecode_MR(void);

/**
 * @brief p9_get_mem_vpd_keyword MT decode tests
 *
 * Test the p9_get_mem_vpd_keyword decode MT interface. Based on a VPDInfo
 * configuration, verify the expected keyword is returned.
 */
void testDecode_MT(void);
/**
 * @brief MCS getVpd override test
 *
 * Verify that overriding the direct memory vpd works.
 */
void testGetVPD_Override(void);

/**
 * @brief MCS getVpd DQ tests
 *
 * Test the getVPD DQ interface. Based on a VPDInfo configuration,
 * verify the expected direct memory vpd is returned.
 * There is a dependency to update standalone simics direct memory (dvpd.dat)
 * for the configuration to map to a keyword, but there is no data dependency.
 * expected data.
 */
void testGetVPD_DQ(void);

/**
 * @brief MCS getVpd CK tests
 *
 * Test the getVPD CK interface. Based on a VPDInfo configuration,
 * verify the expected direct memory vpd is returned.
 * There is a dependency to update standalone simics direct memory (dvpd.dat)
 * for the configuration to map to a keyword, but there is no data dependency.
 * expected data.
 */
void testGetVPD_CK(void);

#endif
