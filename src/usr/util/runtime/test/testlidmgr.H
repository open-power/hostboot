/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/test/testlidmgr.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <util/utillidmgr.H>

class LidMgrTest : public CxxTest::TestSuite
{
    public:
        void testMissingLid()
        {
            UtilLidMgr lidmgr(-1);

            size_t l_size = 0;
            errlHndl_t l_errl = lidmgr.getLidSize(l_size);

            if (NULL == l_errl)
            {
                TS_FAIL("Found missing lid -1.");
            }
            else
            {
                delete l_errl;
            }
        }
};
