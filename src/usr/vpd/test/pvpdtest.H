/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/pvpdtest.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#ifndef __PVPDTEST_H
#define __PVPDTEST_H

/**
 *  @file pvpdtest.H
 *
 *  @brief Test cases for pvpd code
 */
#include <sys/time.h>

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/common/predicates/predicatectm.H>

#include <vpd/pvpdenums.H>
#include <vpd/vpdreasoncodes.H>
#include "../pvpd.H"
#include "../ipvpd.H"

extern trace_desc_t* g_trac_vpd;

using namespace TARGETING;


class pvpdTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief This function will test the numerical order of the pvpdRecords
         *      and pvpdKeywords structures.
         */
        void testpvpdCheckStructOrder ( void )
        {
            uint64_t fails = 0x0;
            VPD::vpdRecord prevRecord = PVPD::PVPD_FIRST_RECORD;
            VPD::vpdKeyword prevKeyword = PVPD::PVPD_FIRST_KEYWORD;

            TRACFCOMP( g_trac_vpd,
                       ENTER_MRK"testpvpdCheckStructOrder()" );

            // Check the pvpdRecords structure for proper order
            uint32_t entry = 0x0;
            for( entry = 0;
                 entry < (sizeof(PVPD::pvpdRecords)/
                          sizeof(PVPD::pvpdRecords[0]));
                 entry++ )
            {
                if( !(PVPD::pvpdRecords[entry].record >= prevRecord) )
                {
                    fails++;
                    TS_FAIL( "testpvpdCheckStructOrder() - Record table out of "
                             "order! Cur Record: 0x%04x, Prev Record: 0x%04x",
                             PVPD::pvpdRecords[entry].record,
                             prevRecord );
                }
                prevRecord = PVPD::pvpdRecords[entry].record;
            }

            // Check the pvpdKeywords structure for proper order
            for( entry = 0;
                 entry < (sizeof(PVPD::pvpdKeywords)/
                          sizeof(PVPD::pvpdKeywords[0]));
                 entry++ )
            {
                if( !(PVPD::pvpdKeywords[entry].keyword >= prevKeyword) )
                {
                    fails++;
                    TS_FAIL( "testpvpdCheckStructOrder() - "
       "Keyword table out of order! Cur Keyword: 0x%04x, Prev Keyword: 0x%04x",
                             PVPD::pvpdKeywords[entry].keyword,
                             prevKeyword );
                }
                prevKeyword = PVPD::pvpdKeywords[entry].keyword;
            }

            TRACFCOMP( g_trac_vpd,
                       "testpvpdCheckStructOrder - %d fails",
                       fails );
        }
};

#endif //__PVPDTEST_H
