#ifndef __FAPItestRc_H
#define __FAPItestRc_H

/**
 *  @file fapitestRc.H
 *
 *  @brief Test case for FAPI return codes
*/

#include <cxxtest/TestSuite.H>
#include <fapi.H>

using namespace fapi;

class FapitestRc: public CxxTest::TestSuite
{
public:

    /**
     * @brief Test FAPI return codes #1
     */
    void testRc1(void)
    {
        // Create ReturnCode using default constructor
        ReturnCode l_rc;

        // Ensure that the embedded return code is success
        if (l_rc != FAPI_RC_SUCCESS)
        {
            TS_FAIL("testRc1. ReturnCode init is not FAPI_RC_SUCCESS");
        }
        else
        {
            // Ensure that OK function works
            if (l_rc.ok() == false)
            {
                TS_FAIL("testRc1. ok() returned false");
            }
            else
            {
                // Ensure that testing l_rc works
                if (l_rc)
                {
                    TS_FAIL("testRc1. testing rc returned true");
                }
            }
        }
        return;
    }


    /**
     * @brief Test FAPI return codes #2
     */
    void testRc2()
    {

        // Create ReturnCode using default constructor
        ReturnCode l_rc;

        // Set the return code to a FAPI code
        l_rc = FAPI_RC_FAPI_MASK | 0x05;

        // Ensure that the creator is FAPI
        ReturnCode::returnCodeCreator l_creator = l_rc.getCreator();

        if (l_creator != ReturnCode::CREATOR_FAPI)
        {
            TS_FAIL("testRc2. Creator is not CREATOR_FAPI");
        }
        else
        {
            // Set the return code to a PLAT code
            l_rc = FAPI_RC_PLAT_ERR_SEE_DATA;

            // Ensure that the creator is PLAT
            l_creator = l_rc.getCreator();

            if (l_creator != ReturnCode::CREATOR_PLAT)
            {
                TS_FAIL("testRc2. Creator is not CREATOR_PLAT");
            }
            else
            {
                l_rc = 5;

                // Ensure that the creator is HWP
                l_creator = l_rc.getCreator();

                if (l_creator != ReturnCode::CREATOR_HWP)
                {
                    TS_FAIL("testRc2. Creator is not CREATOR_HWP");
                }
            }
        }

        return;
    }

    /**
     * @brief Test FAPI return codes #3
     */
    void testRc3()
    {
        uint32_t l_code = 4;

        // Create ReturnCode specifying a return code
        ReturnCode l_rc(l_code);

        // Ensure that the embedded return code is as expected
        uint32_t l_codeCheck = l_rc;

        if (l_codeCheck != l_code)
        {
            TS_FAIL("testRc3. Code is not set as desired");
        }
        else
        {
            // Ensure that ok function returns false
            if (l_rc.ok())
            {
                TS_FAIL("testRc3. ok returned true");
            }
            else
            {
                // Ensure that testing l_rc works
                if (!l_rc)
                {
                    TS_FAIL("testRc3. testing rc returned false");
                }
            }
        }

        return;
    }

    /**
     * @brief Test FAPI return codes #4
     */
    void testRc4()
    {
        uint32_t l_code = 6;
        uint32_t l_code2 = 7;

        // Create similar ReturnCodes
        ReturnCode l_rc(l_code);
        ReturnCode l_rc2(l_code);

        // Ensure that the equality comparison returns true
        if (!(l_rc == l_rc2))
        {
            TS_FAIL("testRc4. Equality comparison false");
        }
        else
        {
            // Ensure that the inequality comparison returns false
            if (l_rc != l_rc2)
            {
                TS_FAIL("testRc4.Inequality comparison true");
            }
            else
            {
                // Change the code of l_rc2
                l_rc2 = l_code2;

                // Ensure that the equality comparison returns false
                if (l_rc == l_rc2)
                {
                    TS_FAIL("testRc4. Equality comparison true");
                }
                else
                {
                    // Ensure that the inequality comparison returns true
                    if (!(l_rc != l_rc2))
                    {
                        TS_FAIL("testRc4. Inequality comparison false");
                    }
                }
            }
        }

        return;
    }

    /**
     * @brief Test FAPI return codes #5
     */
    void testRc5()
    {
        uint32_t l_code = 6;
        uint32_t l_code2 = 7;

        // Create a ReturnCode
        ReturnCode l_rc(l_code);

        // Ensure that the equality comparison returns true when comparing to the
        // same return code value
        if (!(l_rc == l_code))
        {
            TS_FAIL("testRc5. 1. Equality comparison false");
        }
        else
        {
            // Ensure that the inequality comparison returns false when comparing to
            // the same return code value
            if (l_rc != l_code)
            {
                TS_FAIL("testRc5. 2. Inequality comparison true");
            }
            else
            {
                // Ensure that the equality comparison returns false when comparing
                // to a different return code value
                if (l_rc == l_code2)
                {
                    TS_FAIL("testRc5. 3. Equality comparison true");
                }
                else
                {
                    // Ensure that the inequality comparison returns true when
                    // comparing to a different return code value
                    if (!(l_rc != l_code2))
                    {
                        TS_FAIL("testRc5. 4. Inequality comparison false");
                    }
                }
            }
        }

        return;
    }

    /**
     * @brief Test FAPI return codes #6
     */
    void testRc6()
    {
        uint32_t l_code = 6;

        // Create a ReturnCode
        ReturnCode l_rc(l_code);

        // Ensure that the getData function returns NULL
        void * l_pData = reinterpret_cast<void *> (0x12345678);

        l_pData = l_rc.getData();
        if (l_pData != NULL)
        {
            TS_FAIL("testRc6. getData did not return NULL");
        }
        else
        {
            // Ensure that the releaseData function returns NULL
            l_pData = reinterpret_cast<void *> (0x12345678);

            l_pData = l_rc.releaseData();

            if (l_pData != NULL)
            {
                TS_FAIL("testRc6. releaseData did not return NULL");
            }
        }

        return;
    }

    /**
     * @brief Test FAPI return codes #7
     */
    void testRc7()
    {
        uint32_t l_code = 10;

        // Create a ReturnCode
        ReturnCode l_rc(l_code);

        // Assign ReturnCodeData. Note that this should really be an errlHndl_t,
        // because the FSP deleteData function will attempt to delete an error
        // log, but this is just for test, the data will be released before the
        // ReturnCode is destructed.
        uint32_t l_myData = 6;
        void * l_pMyData = reinterpret_cast<void *> (&l_myData);
        (void) l_rc.setData(l_pMyData);

        // Ensure that getData retrieves the ReturnCodeData
        void * l_pMyDataCheck = l_rc.getData();

        if (l_pMyDataCheck != l_pMyData)
        {
            TS_FAIL("testRc7. getData returned unexpected data ptr");
        }
        else
        {
            // Ensure that getData retrieves the ReturnCodeData again
            l_pMyDataCheck = NULL;
            l_pMyDataCheck = l_rc.getData();

            if (l_pMyDataCheck != l_pMyData)
            {
                TS_FAIL("testRc7. getData returned unexpected data ptr");
            }
        }

        // Release the data to avoid ReturnCode from deleting in on destruction
        l_pMyDataCheck = l_rc.releaseData();

        return;
    }

    /**
     * @brief Test FAPI return codes #8
     */
    void testRc8()
    {
        uint32_t l_code = 10;

        // Create a ReturnCode
        ReturnCode l_rc(l_code);

        // Assign ReturnCodeData. Note that this should really be an errlHndl_t,
        // because the FSP deleteData function will attempt to delete an error
        // log, but this is just for test, the data will be released before the
        // ReturnCode is destructed.
        uint32_t l_myData = 6;
        void * l_pMyData = reinterpret_cast<void *> (&l_myData);
        (void) l_rc.setData(l_pMyData);

        // Ensure that releaseData retrieves the ReturnCodeData
        void * l_pMyDataCheck = l_rc.releaseData();

        if (l_pMyDataCheck != l_pMyData)
        {
            TS_FAIL("testRc8. getData returned unexpected data ptr");
        }
        else
        {
            // Ensure that releaseData now returns NULL
            l_pMyDataCheck = NULL;
            l_pMyDataCheck = l_rc.releaseData();

            if (l_pMyDataCheck != NULL)
            {
                TS_FAIL("testRc8. getData returned non NULL ptr");
            }
        }

        return;
    }

    /**
     * @brief Test FAPI return codes #9
     */
    void testRc9()
    {
        uint32_t l_code = 10;

        // Create a ReturnCode
        ReturnCode l_rc(l_code);

        // Assign ReturnCodeData. Note that this should really be an errlHndl_t,
        // because the FSP deleteData function will attempt to delete an error
        // log, but this is just for test, the data will be released before the
        // ReturnCode is destructed.
        uint32_t l_myData = 6;
        void * l_pMyData = reinterpret_cast<void *> (&l_myData);
        (void) l_rc.setData(l_pMyData);

        // Create a ReturnCode using the copy constructor
        ReturnCode l_rc2(l_rc);

        // Ensure that the two ReturnCodes are the same
        if (l_rc != l_rc2)
        {
            TS_FAIL("testRc9. ReturnCodes differ");
        }
        else
        {
            // Ensure that getData retrieves the ReturnCodeData from l_rc
            void * l_pMyDataCheck = l_rc.getData();

            if (l_pMyDataCheck != l_pMyData)
            {
                TS_FAIL("testRc9. getData returned unexpected data ptr (1)");
            }
            else
            {
                // Ensure that getData retrieves the ReturnCodeData from l_rc2
                l_pMyDataCheck = NULL;
                l_pMyDataCheck = l_rc2.getData();

                if (l_pMyDataCheck != l_pMyData)
                {
                    TS_FAIL("testRc9.  getData returned unexpected data ptr (2)");
                }
            }
        }

        // Release the data to avoid ReturnCode from deleting in on destruction.
        // This will release the data from both copies of the ReturnCode.
        (void) l_rc.releaseData();

        return;
    }

    /**
     * @brief Test FAPI return codes #10
     */
    void testRc10()
    {
        uint32_t l_code = 10;

        // Create a ReturnCode
        ReturnCode l_rc(l_code);

        // Assign ReturnCodeData. Note that this should really be an errlHndl_t,
        // because the FSP deleteData function will attempt to delete an error
        // log, but this is just for test, the data will be released before the
        // ReturnCode is destructed.
        uint32_t l_myData = 6;
        void * l_pMyData = reinterpret_cast<void *> (&l_myData);
        (void) l_rc.setData(l_pMyData);

        // Create a ReturnCode using the assignment operator
        ReturnCode l_rc2;
        l_rc2 = l_rc;

        // Ensure that the two ReturnCodes are the same
        if (l_rc != l_rc2)
        {
            TS_FAIL("testRc10. ReturnCodes differ");
        }
        else
        {
            // Ensure that releaseData retrieves the ReturnCodeData from l_rc
            void * l_pMyDataCheck = l_rc.releaseData();

            if (l_pMyDataCheck != l_pMyData)
            {
                TS_FAIL("testRc10. releaseData returned unexpected data ptr");
            }
            else
            {
                // Ensure that releaseData retrieves NULL from l_rc2
                l_pMyDataCheck = NULL;
                l_pMyDataCheck = l_rc2.releaseData();

                if (l_pMyDataCheck != NULL)
                {
                    TS_FAIL("testRc10. releaseData returned non NULL ptr");
                }
            }
        }

        return;
    }



};

#endif
