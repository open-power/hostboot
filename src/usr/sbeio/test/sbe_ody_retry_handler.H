/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_ody_retry_handler.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
#ifndef __SBE_ODY_RETRY_HANDLER_H
#define __SBE_ODY_RETRY_HANDLER_H

/**
 *  @file sbe_ody_retry_handler.H
 *
 *  @brief Test cases for Odyssey Retry Handler
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbeioreasoncodes.H>
#include <sbeio/sbe_retry_handler.H>


#define SBE_TRACD_ODY(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"odyRetryHandlerTest: " printf_string,##args)
#define SBE_TRACF_ODY(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"odyRetryHandlerTest: " printf_string,##args)

using namespace ERRORLOG;
using namespace SBE;
using namespace SBEIO;

extern trace_desc_t* g_trac_sbeio;

class odyRetryHandlerTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Call the main_sbe_handler in HBRT and IPL time for Odyssey.
     */
    void testOdysseyCombo(void)
    {
    bool l_runtime_tests = 0;
#ifdef __HOSTBOOT_RUNTIME
    l_runtime_tests = 1;
#endif
    SBE_TRACF_ODY(ENTER_MRK"testOdysseyCombo: Testing Odyssey Methods l_runtime_tests=0x%X", l_runtime_tests);
    // Only run on Odyssey OCMBs
    if (TARGETING::getOcmbChipTypesInSystem() == TARGETING::UTIL_ODYSSEY_FOUND)
    {
        SBE_TRACF_ODY(ENTER_MRK"testOdysseyCombo: Testing Odyssey Methods");

        TARGETING::TargetHandleList l_allOCMBs;
        TARGETING::getAllChips(l_allOCMBs, TARGETING::TYPE_OCMB_CHIP, true);

        for( const auto & l_ocmb: l_allOCMBs)
        {
            SBE_TRACF_ODY("testOdysseyCombo Working on HUID=0x%X", get_huid(l_ocmb));
            // @TODO PFHB-542 Figure out why the Odyssey SBE halts, STGD 580282 SBEIO_FIFO TIMEOUT
            //const auto l_SBEobj = make_sbe_retry_handler(
            //        l_ocmb,
            //        SbeRetryHandler::SBE_MODE_OF_OPERATION::INFORMATIONAL_ONLY,
            //        SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
            //        EMPTY_PLID,
            //        NOT_INITIAL_POWERON);
            //l_SBEobj->main_sbe_handler();
            // All good if we make the call and come back
            SBE_TRACF_ODY("testOdysseyCombo: Success for HUID=0x%X", get_huid(l_ocmb));
        }
        SBE_TRACF_ODY(EXIT_MRK"testOdysseyCombo: Completed");
    } // End Odyssey
    else
    {
        SBE_TRACF_ODY(ENTER_MRK"SKIPPED testOdysseyCombo: No Odyssey OCMBs");
    }

    } // End testOdysseyCombo


};

#endif
