/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/test/sfc_ibmtest.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
/* [+] Google Inc.                                                        */
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
#ifndef __SFC_IBMTEST_H
#define __SFC_IBMTEST_H

/**
 *  @file sfc_ibmtest.H
 *
 *  @brief Test case for IBM DPSS Flash Controller
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <sys/time.h>
#include "../pnor_sfcdd.H"
using PnorDD = PnorSfcDD;
#include <list>
#include <targeting/common/attributes.H>
#include "../sfc_ibm.H"

extern trace_desc_t* g_trac_pnor;

class SfcIBMTest : public CxxTest::TestSuite
{
  public:

    /*************************************************************************/
    /* NOTE:  TEST DISABLED!!!  remove "_" before test name to re-enable     */
    /*************************************************************************/
    /**
     * @brief PNOR DD Force Fails testcase
     */
    void _test_forceFails(void)
    {
        errlHndl_t l_err = NULL;
        uint64_t fails = 0;
        uint64_t total = 0;
        SfcIBM* sfcdd = reinterpret_cast<SfcIBM*>(
                          Singleton<PnorDD>::instance().iv_sfc );
        mutex_t* l_mutex = Singleton<PnorDD>::instance().iv_mutex_ptr;
        SfcIBM::SfcCmdReg_t sfc_cmd;

        do{
            TRACFCOMP(g_trac_pnor, "SfcIBMTest::test_forceFails> starting - expect to see errors");

            /*******************************/
            /*  Send in an invalid OP Code */
            /*******************************/
            sfc_cmd.opcode = SfcIBM::SFC_OP_INVALID;
            sfc_cmd.length = 0;

            mutex_lock(l_mutex);
            l_err = sfcdd->writeReg(SfcIBM::SFC_CMD_SPACE,
                                    SfcIBM::SFC_REG_CMD,
                                    sfc_cmd.data32);
            total++;
            if (l_err)
            {
                TS_FAIL("SfcIBMTest::test_forceFails> writeReg failed! Error committed.");
                fails++;

                // Unlock mutex for Error Log to be committed
                mutex_unlock(l_mutex);
                errlCommit(l_err,PNOR_COMP_ID);

                // Lock mutex for next operation
                mutex_lock(l_mutex);
            }

            // Poll for complete status without waiting
            l_err = sfcdd->pollOpComplete();
            mutex_unlock(l_mutex);

            total++;
            if ( l_err == NULL )
            {
                TS_FAIL("SfcIBMTest::test_forceFails> Failed to create illegal opcode error!");
                fails++;
            }
            else
            {
                // error correctly created - delete it
                delete l_err;
            }

            /*******************************************************/
            /* Issue a cmd but poll for completion without waiting */
            /*******************************************************/
            //Issue Get Chip ID command
            sfc_cmd.opcode = SfcIBM::SFC_OP_CHIPID;
            sfc_cmd.length = 0;

            mutex_lock(l_mutex);
            l_err = sfcdd->writeReg(SfcIBM::SFC_CMD_SPACE,
                                    SfcIBM::SFC_REG_CMD,
                                    sfc_cmd.data32);

            total++;
            if (l_err)
            {
                TS_FAIL("SfcIBMTest::test_forceFails> Get Chip Id cmd failed! Error committed.");
                fails++;

                // Unlock mutex for Error Log to be committed
                mutex_unlock(l_mutex);
                errlCommit(l_err,PNOR_COMP_ID);

                // Lock mutex for next operation
                mutex_lock(l_mutex);
            }

            // Poll for complete status without waiting
            l_err = sfcdd->pollOpComplete();

            total++;
            if ( l_err == NULL )
            {
                TS_FAIL("SfcIBMTest::test_forceFails> pollOpCompletel(l_poll=0) Failed to create an error!");
                fails++;
            }
            else
            {
                // error correctly created - delete it
                delete l_err;
            }

            /*******************************************************/
            /* Cleanup: poll to make sure last operation completes */
            /*         before continuing                           */
            /*******************************************************/
            l_err = sfcdd->pollOpComplete();
            mutex_unlock(l_mutex);

            total++;
            if (l_err)
            {
                TS_FAIL("SfcIBMTest::test_forceFails> Cleanup polling failed! Error committed.");
                errlCommit(l_err,PNOR_COMP_ID);
                fails++;
            }


        }while(0);

        TRACFCOMP(g_trac_pnor, "SfcIBMTest::test_forceFails> %d/%d fails", fails, total );

    }
};

#endif
