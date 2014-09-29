/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/test/htmgt_occcmd_test.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

#ifndef __HTMGT_OCCCMD_TEST_H
#define __HTMGT_OCCCMD_TEST_H

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <vfs/vfs.H>

#include <htmgt/htmgt.H>

#include <targeting/common/targetservice.H>
#include <targeting/common/attributes.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>

#include <htmgt_activate.H>
#include <htmgt_occcmd.H>


using namespace TARGETING;


class htmgtOccCmdTest: public CxxTest::TestSuite
{
    public:

        // TODO RTC 118875
        void test_occcmd_poll(void)
        {
            errlHndl_t l_err = NULL;
            bool locallyLoaded = false;
            TS_TRACE("entered test_occcmd_poll");

            if(!VFS::module_is_loaded("libhtmgt.so"))
            {
                l_err = VFS::module_load("libhtmgt.so");
                if( l_err )
                {
                    TS_FAIL("Could not load libhtmgt.so module");
                    errlCommit(l_err,HTMGT_COMP_ID);
                }
                else
                {
                    locallyLoaded = true;
                }
            }

            HTMGT::occMgr::instance().buildOccs();
            if (HTMGT::occMgr::instance().getNumOccs() > 0)
            {
                HTMGT::Occ *l_occ =
                    HTMGT::occMgr::instance().getMasterOcc();

                // create 1 byte buffer for poll command data
                const uint8_t l_cmdData[1] = { 0x10 /*version*/ };

                // Normal Poll with default response
                HTMGT::OccCmd l_cmd(l_occ, HTMGT::OCC_CMD_POLL,
                                    sizeof(l_cmdData), l_cmdData);
                l_err = l_cmd.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    TS_FAIL("occcmd_poll: Poll command failed" );
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_cmd.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size, l_cmd.getRspStatus());
                }


                // Timeout waiting for OCC to respond to Poll cmd
                HTMGT::G_debug_data = 0x01;
                HTMGT::OccCmd l_pollTimeout(l_occ, HTMGT::OCC_CMD_POLL,
                                            sizeof(l_cmdData), l_cmdData);
                l_err = l_pollTimeout.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    if (0x2635 == l_err->reasonCode())
                    {
                        TS_TRACE("occcmd_poll: Poll timeout as expected");
                    }
                    else
                    {
                        TS_FAIL("occcmd_poll: Did not fail with 0x2635");
                    }
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_pollTimeout.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size,
                             l_pollTimeout.getRspStatus());
                    TS_FAIL("occcmd_poll: Poll should have failed due to"
                            " timeout waiting for response");
                }
                HTMGT::G_debug_data = 0x00;


                // Normal Poll with default response
                HTMGT::OccCmd l_cmd2(l_occ, HTMGT::OCC_CMD_POLL,
                                     sizeof(l_cmdData), l_cmdData);
                l_err = l_cmd2.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    TS_FAIL("occcmd_poll: Poll 2 command failed" );
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_cmd2.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size, l_cmd2.getRspStatus());
                }


                // Timeout waiting for OCC to receive next command
                HTMGT::G_debug_data = 0x02;
                HTMGT::OccCmd l_pollTimeout2(l_occ, HTMGT::OCC_CMD_POLL,
                                             sizeof(l_cmdData), l_cmdData);
                l_err = l_pollTimeout2.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    if (0x2635 == l_err->reasonCode())
                    {
                        TS_TRACE("occcmd_poll: Poll timeout as expected");
                    }
                    else
                    {
                        TS_FAIL("occcmd_poll: Did not fail with 0x2635");
                    }
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_pollTimeout2.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size,
                             l_pollTimeout2.getRspStatus());
                    TS_FAIL("occcmd_poll: Poll should have failed due to"
                            " timeout waiting"
                            " to receive cmd");
                }
                HTMGT::G_debug_data = 0x00;


                // Normal Poll with default response
                HTMGT::OccCmd l_cmd3(l_occ, HTMGT::OCC_CMD_POLL,
                                     sizeof(l_cmdData), l_cmdData);
                l_err = l_cmd3.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    TS_FAIL("occcmd_poll: Poll 3 command failed" );
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_cmd3.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size, l_cmd3.getRspStatus());
                }


                // Bad checkum in OCC response
                HTMGT::G_debug_data = 0x03;
                HTMGT::OccCmd l_pollChecsum(l_occ, HTMGT::OCC_CMD_POLL,
                                            sizeof(l_cmdData), l_cmdData);
                l_err = l_pollChecsum.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    if (0x2619 == l_err->reasonCode())
                    {
                        TS_TRACE("occcmd_poll: Checksum fail as expected");
                    }
                    else
                    {
                        TS_FAIL("occcmd_poll: Did not fail with 0x2619");
                    }
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_pollChecsum.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size, l_pollChecsum.getRspStatus());
                    TS_FAIL("occcmd_poll: Poll should have failed with a"
                            " checksum failure" );
                }
                HTMGT::G_debug_data = 0x00;


                // Normal Poll with default response
                HTMGT::OccCmd l_cmd4(l_occ, HTMGT::OCC_CMD_POLL,
                                     sizeof(l_cmdData), l_cmdData);
                l_err = l_cmd4.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    TS_FAIL("occcmd_poll: Poll 4 command failed" );
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_cmd4.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size, l_cmd4.getRspStatus());
                }


                // OCC exception
                HTMGT::G_debug_data = 0xE0;
                HTMGT::OccCmd l_exception(l_occ, HTMGT::OCC_CMD_POLL,
                                          sizeof(l_cmdData), l_cmdData);
                l_err = l_exception.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    if (0x2619 == l_err->reasonCode())
                    {
                        TS_TRACE("occcmd_poll: Checksum fail as expected");
                    }
                    else
                    {
                        TS_FAIL("occcmd_poll: Did not fail with 0x2619");
                    }
                    TS_TRACE("occcmd_poll: Check for 2AE0 exception logs");
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_exception.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size, l_exception.getRspStatus());
                    TS_FAIL("occcmd_poll: Poll should have failed with an"
                            " OCC exception" );
                }
                HTMGT::G_debug_data = 0x00;


                // Normal Poll with default response
                HTMGT::OccCmd l_cmd5(l_occ, HTMGT::OCC_CMD_POLL,
                                     sizeof(l_cmdData), l_cmdData);
                l_err = l_cmd5.sendOccCmd();
                if (l_err != NULL)
                {
                    // Poll failed
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    TS_FAIL("occcmd_poll: Poll 5 command failed" );
                }
                else
                {
                    // Poll succeeded
                    uint8_t * l_poll_rsp = NULL;
                    uint32_t l_poll_rsp_size =
                        l_cmd5.getResponseData(l_poll_rsp);
                    TS_TRACE("test_occcmd_poll: length=%d, status=0x%02X",
                             l_poll_rsp_size, l_cmd5.getRspStatus());
                }

            }
            else
            {
                TS_FAIL("occcmd_poll: Could not find any OCCs" );
            }

            if (locallyLoaded)
            {
                VFS::module_unload("libhtmgt.so");
            }

            TS_TRACE("exiting test_occcmd_poll");
        }

};

#endif
