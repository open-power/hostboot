/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/test/vpdEccApiTest.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#ifndef __VPD_ECC_TEST_H
#define __VPD_ECC_TEST_H

/**
 *  @file vpdEccApiTest.H
 *
 *  @brief Test cases for the VPD ECC data API
 */

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include "mvpdtest.H"          // getFunctionalProcTarget
#include <usr/vpd/mvpdenums.H> // MVPD::VWML, MVPD::pdI
#include <usr/vpd/vpd_if.H>    // VPD::validateAllRecordEccData, VPD::updateRecordEccData
#include "../mvpd.H"           // For MvpdFacade singleton
#include <devicefw/userif.H>   // DEVICE_MVPD_ADDRESS, deviceRead, deviceWrite

extern trace_desc_t* g_trac_vpd;

// Global variable to determine if the ECC APIs are present and available.
// Defined and set in file vpd_ecc_api.C.
extern const bool g_vpd_ecc_api_present;


class vpdEccApiTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief Run the tests to exercise the VPD ECC API
         */
        void testVpdEccApi()
        {
#ifndef __HOSTBOOT_RUNTIME
            do
            {
                if (false == g_vpd_ecc_api_present)
                {
                    TRACFCOMP( g_trac_vpd, INFO_MRK"testVpdEccApi(): VPD update/validate "
                               "ECC data APIs are not present, therefore skipping tests" );
                    break;
                }

                // Initialize class member variables
                if (false == mySetUp())
                {
                    TRACFCOMP( g_trac_vpd, INFO_MRK"testVpdEccApi(): Failed to properly "
                               "initialize test, therefore skipping tests. " );
                    break;
                }

                // Modify a keyword via the MVPD API and test
                if (modifyKeywordViaMvpdApi())
                {
                    validateAllRecordEccDataTest();
                    updateRecordEccDataTest();
                    validateAllRecordEccDataTest();
                }

                // Modify a keyword via different API and test
                if (modifyKeywordViaNonMvpdApi())
                {
                    validateAllRecordEccDataTest(true);
                    updateRecordEccDataTest();
                    validateAllRecordEccDataTest();
                }

                // Clean up after ourselves
                tearDown();
            } while (0);

            TRACFCOMP( g_trac_vpd, EXIT_MRK"testVpdEccApi()" );

#endif // #ifndef __HOSTBOOT_RUNTIME
        }

    private:  // private methods

        /**
         * @brief Test the VPD::validateAllRecordEccData API
         * @param l_expectedFail - if true, then test is expected to fail
         *                         if false, then test is expected to pass
         */
        void validateAllRecordEccDataTest ( bool l_expectedFail = false )
        {
            errlHndl_t l_err = VPD::validateAllRecordEccData( m_procTarget );

            // If expecting an error
            if (true == l_expectedFail)
            {
                // If did not get an error then test failed
                if (!l_err)
                {
                    TS_FAIL("testVpdEccApi::validateAllRecordEccDataTest succeeded but "
                            "should have failed. The record MVPD::VWML(0x%.4X) and keyword "
                            "MVPD::pdI(0x%.4X) has been modified and therefore the ECC "
                            "data should not match record", m_record, m_keyword);
                }
                // If did not get the expected error, then test failed
                else if (l_err->moduleId() != VPD::VPD_IPVPD_ECC_DATA_CHECK)
                {
                    TS_FAIL("testVpdEccApi::validateAllRecordEccDataTest returned "
                            "unexpected module ID 0x%.4X with reason code 0x%.4X",
                            l_err->moduleId(), l_err->reasonCode());
                    errlCommit( l_err, VPD_COMP_ID );
                }
                else
                {
                    // An error was returned, as expected
                    delete l_err;
                    l_err = nullptr;
                }
            }
            // Not expecting an error
            else
            {
                if (l_err)
                {
                    TS_FAIL("testVpdEccApi::validateAllRecordEccDataTest returned "
                            "an unexpected error: module ID 0x%.4X and reason code 0x%.4X",
                            l_err->moduleId(), l_err->reasonCode());
                    errlCommit( l_err, VPD_COMP_ID );
                }
            }

        } // validateAllRecordEccDataTest

        /**
         * @brief Test the VPD::updateRecordEccData API
         */
        void updateRecordEccDataTest ( void )
        {
            errlHndl_t l_err = VPD::updateRecordEccData( m_procTarget,
                                    m_record, m_keyword, m_location, m_eepromSource );

            if (l_err)
            {
                errlCommit( l_err, VPD_COMP_ID );

                TS_FAIL("testVpdEccApi::updateRecordEccData returned an error");
            }
        } // updateRecordEccDataTest

        /**
         * @brief Initialize class member variables
         *
         * @return bool True if no error, false if an error occurred
         */
        bool mySetUp()
        {
            // Get a functional PROC target to work with
            m_procTarget = getFunctionalProcTarget();

            // Initialize the input arguments
            m_record = MVPD::VWML;
            m_keyword = MVPD::pdI;
            m_location = VPD::SEEPROM;
            m_eepromSource = EEPROM::AUTOSELECT;

            // Initialize the random keyword data
            m_randomKeywordData = 0;

            // Initialize the back up buffer
            m_buffer = nullptr;
            m_bufferSize = 0;

            return saveKeywordData();
        } // setUp

        /**
         * @brief Clean up any allocated memory
         */
        void tearDown()
        {
            restoreKeyword();
            if (m_buffer)
            {
                free (m_buffer);
                m_buffer = nullptr;
            }
        } // tearDown

        /**
         * @brief Save a copy of the keyword before manipulating it for test purposes.
         *        Will use this saved copy to restore keyword data once testing is complete.
         *
         * @return bool True if no error, false if an error occurred
         */
        bool saveKeywordData()
        {
            errlHndl_t l_err(nullptr);

            // True signifies successfully retrieving the keyword data. Assume success.
            bool l_retValue = true;
            do
            {
                // Figure out how big the keyword is
                l_err = deviceRead( m_procTarget,
                                    m_buffer,
                                    m_bufferSize,
                                    DEVICE_MVPD_ADDRESS(m_record, m_keyword) );
                if (l_err)
                {
                    break;
                }

                // Get the keyword data
                m_buffer = static_cast<uint8_t *>(malloc(m_bufferSize));
                l_err = deviceRead( m_procTarget,
                                    m_buffer,
                                    m_bufferSize,
                                    DEVICE_MVPD_ADDRESS(m_record, m_keyword) );

                if (l_err)
                {
                    break;
                }
            }
            while (0);

            if (l_err)
            {
                errlCommit( l_err, VPD_COMP_ID );

                l_retValue = false;
                TS_FAIL("vpdEccApiTest::saveKeywordData returning false %d", l_retValue);
            }

            return l_retValue;
        } // saveKeywordData

        /**
         * @brief Restore the keyword to it's original state
         */
        void restoreKeyword ( )
        {
            if (m_buffer)
            {
                errlHndl_t l_err = deviceWrite(
                                     m_procTarget,
                                     m_buffer,
                                     m_bufferSize,
                                     DEVICE_MVPD_ADDRESS(m_record, m_keyword) );

                if (l_err)
                {
                    errlCommit( l_err, VPD_COMP_ID );

                    TS_FAIL("vpdEccApiTest::restoreKeyword returned an error");
                }

                free (m_buffer);
                m_buffer = nullptr;
            } // if (m_buffer)
         } // restoreKeyword

        /**
         * @brief Modify a keyword with garbage and then test the data.
         *        Tests should still pass, because ECC data should change to be
         *        in sync with record change.
         *
         * @return bool True if no error, false if an error occurred
         */
        bool modifyKeywordViaMvpdApi()
        {
            errlHndl_t l_err(nullptr);

            // True signifies a successful keyword change. Assume success.
            bool retValue = true;
            do
            {
                // Create a buffer to write to keyword
                size_t  l_bufferSize(m_bufferSize);
                uint8_t l_buffer[l_bufferSize];

                // Fill the buffer with random data
                for ( size_t ii = 0; ii < l_bufferSize; ii++ )
                {
                    l_buffer[ii] = ++m_randomKeywordData;
                }

                // Write the random data to the keyword
                l_err = deviceWrite( m_procTarget,
                                     l_buffer,
                                     l_bufferSize,
                                     DEVICE_MVPD_ADDRESS(m_record, m_keyword) );
                if (l_err)
                {
                    break;
                }
            }
            while (0);

            if (l_err)
            {
                errlCommit( l_err, VPD_COMP_ID );

                retValue = false;
                TS_FAIL("vpdEccApiTest::modifyKeywordViaMvpdApi returned an error");
            }

            return retValue;
        } // modifyKeywordViaMvpdApi

        /**
         * @brief Modify a keyword with garbage and then test the data.
         *        Tests should fail because ECC data will not be updated.
         *
         * @return bool True if no error, false if an error occurred
         */
        bool modifyKeywordViaNonMvpdApi()
        {
            errlHndl_t l_err(nullptr);

            // True signifies a successful keyword change. Assume success.
            bool retValue = true;
            do
            {
                // Create a buffer to write to keyword
                size_t  l_bufferSize(m_bufferSize);
                uint8_t l_buffer[l_bufferSize];

                // Fill the buffer with random data
                for ( size_t ii = 0; ii < l_bufferSize; ii++ )
                {
                    l_buffer[ii] = ++m_randomKeywordData;;
                }

                IpVpdFacade::input_args_t l_args;
                l_args.record = m_record;
                l_args.keyword = m_keyword;
                l_args.location = m_location;
                l_args.eepromSource = m_eepromSource;

                // Write the random data to the keyword
                l_err = MvpdFacade::getInstance().write(
                                  m_procTarget, l_buffer, m_bufferSize, l_args);

                if (l_err)
                {
                    break;
                }
            }
            while (0);

            if (l_err)
            {
                errlCommit( l_err, VPD_COMP_ID );

                retValue = false;
                TS_FAIL("vpdEccApiTest::modifyKeywordViaNonMvpdApi returned an error");
            }

            return retValue;
        } // modifyKeywordViaNonMvpdApi

    private: // private members

        TARGETING::Target * m_procTarget;

        VPD::vpdRecord        m_record;
        VPD::vpdKeyword       m_keyword;
        VPD::vpdCmdTarget     m_location;
        EEPROM::EEPROM_SOURCE m_eepromSource;

        int8_t m_randomKeywordData;

        uint8_t* m_buffer;
        size_t   m_bufferSize;
}; // class vpdEccApiTest

#endif  // __VPD_ECC_TEST_H

