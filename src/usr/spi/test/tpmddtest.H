/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/test/tpmddtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#ifndef __TPMDDTEST_H
#define __TPMDDTEST_H

/**
 *  @file tpmddtest.H
 *
 *  @brief Test cases for the tpm dd code
 */

#include <sys/time.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <spi/tpmddreasoncodes.H>
#include <targeting/common/commontargeting.H>
#include <secureboot/trustedbootif.H>
#include "../tpmdd.H"
#include "../../secureboot/trusted/trustedTypes.H"

extern trace_desc_t* g_trac_tpmdd;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace TARGETING;
using namespace TPMDD;


class TPMDDTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief Retrieve a TPM target to test with
         */
        TARGETING::Target* getTestTarget()
        {
            TARGETING::Target* testTarget = nullptr;
            TARGETING::TargetHandleList tpmList;
            TARGETING::getAllChips(tpmList,
                                   TARGETING::TYPE_TPM,
                                   true); // only functional
            if (tpmList.size() > 0)
            {
                testTarget = tpmList[0];

                TRACFCOMP( g_trac_tpmdd,
                           "getTestTarget tpm tgt=0x%08X",
                           TARGETING::get_huid(testTarget));

                // Let's see if the requested chip is functional
                tpm_info_t tpmInfo;
                memset(&tpmInfo, 0, sizeof(tpm_info_t));
                errlHndl_t err = tpmReadAttributes (testTarget, tpmInfo,
                                                    TPM_LOCALITY_0);

                if (nullptr != err)
                {
                    testTarget = nullptr;
                    delete err;
                    err = nullptr;
                }
                else if (!tpmInfo.tpmEnabled)
                {
                    TRACFCOMP(g_trac_tpmdd, "getTestTarget - "
                              "Chip not enabled");
                    testTarget = nullptr;
                }
                else
                {
                    TRACFCOMP(g_trac_tpmdd, "getTestTarget - "
                              "Chip enabled");
                }
            }

            return testTarget;
        }

        /**
         * @brief TPM Read VendorID Test
         */
        void testTPMReadVendorID ( void )
        {
            errlHndl_t err = nullptr;
            int64_t fails = 0, num_ops = 0;
            uint32_t data = 0x0;
            size_t dataSize = sizeof(data);

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMReadVendorID - Start" );

            do
            {
                // Get a TPM Target
                TARGETING::Target* testTarget = getTestTarget();
                if (nullptr == testTarget)
                {
                    continue;
                }

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_OP_READVENDORID,
                                                     0,
                                                     TPM_LOCALITY_0) );

                if( nullptr != err )
                {
                    fails++;
                    TS_FAIL( "testTPMReadVendorID - Error detected" );
                    errlCommit( err,
                                TPMDD_COMP_ID );
                    delete err;
                    err = nullptr;
                    continue;
                }
                else if ((data & TPMDD::TPM_VENDORID_MASK)
                         // Only 75x supported in simics for now:
                           != TPMDD::TPM_VENDORID_75x)
                {
                    fails++;
                    TS_FAIL( "testTPMReadVendorID - Failed to read "
                             "correct vendor id ID=0x%X", data);
                    continue;

                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMReadVendorID - "
                              "VendorID returned as expected. ID=0x%X",
                              data);
                    continue;
                }
            } while( 0 );
            TRACFCOMP( g_trac_tpmdd,
                       "testTPMReadVendorID - End: %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief TPM Invalid Operation Test
         *      This test will pass in an invalid Operation type.  It
         *      is expected that an error log is to be returned.
         */
        void testTPMInvalidOperation ( void )
        {
            errlHndl_t err = nullptr;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 0;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMInvalidOperation - Start" );

            do
            {

                // Get a TPM Target
                TARGETING::Target* testTarget = getTestTarget();
                if (nullptr == testTarget)
                {
                    continue;
                }

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_OP_LASTOP,
                                                     0,
                                                     TPM_LOCALITY_0) );

                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "testTPMInvalidOperation - Error should've "
                             " resulted in Operation type of TPM_OP_LASTOP!" );
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMInvalidOperation - "
                              "TPM_OP_LASTOP : Error log returned as expected. "
                              "RC=0x%X",
                              err->reasonCode() );
                    delete err;
                    err = nullptr;
                }


                num_ops++;
                err = deviceOp( DeviceFW::LAST_OP_TYPE,
                                testTarget,
                                &data,
                                dataSize,
                                DEVICE_TPM_ADDRESS( TPM_OP_READVENDORID,
                                                    0,
                                                    TPM_LOCALITY_0) );

                if( nullptr == err )
                {
                    fails++;
                    TS_FAIL( "testTPMInvalidOperation - Error should've "
                             " resulted in Operation type of LAST_OP_TYPE!" );
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMInvalidOperation - "
                              "DevFW::LastOp : Error log returned as expected. "
                              "RC=0x%X",
                              err->reasonCode() );
                    delete err;
                    err = nullptr;
                }


            } while( 0 );
            TRACFCOMP( g_trac_tpmdd,
                       "testTPMInvalidOperation - End: %d/%d fails",
                       fails, num_ops );
        }

        /**
         * @brief TPM Overflow Test
         *      This test will pass in a read length too long for the
         *      device.  It is expected that an error log is to be
         *      returned.
         */
        void testTPMOverflow ( void )
        {
            errlHndl_t err = nullptr;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 0;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMOverflow - Start" );

            do
            {
                // Get a TPM Target
                TARGETING::Target* testTarget = getTestTarget();
                if (nullptr == testTarget)
                {
                    continue;
                }

                // Set max length
                dataSize = 0xFFFFFFFFFFFFFFFF;
                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_OP_READVENDORID,
                                                     0,
                                                     TPM_LOCALITY_0) );

                if( nullptr == err ||
                    err->reasonCode() != TPM_OVERFLOW_ERROR)
                {
                    fails++;
                    TS_FAIL( "testTPMOverflow - ReadVendorId: Error should've "
                             "resulted from overflow length: "
                             "length = 0x%x",
                             dataSize);
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMOverflow - "
                              "ReadVendorId: Error log returned as expected. "
                              "RC=0x%X",
                              err->reasonCode() );
                    delete err;
                    err = nullptr;
                }



            } while( 0 );

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMOverflow - End: %d/%d fails",
                       fails, num_ops );
        }


        /**
         * @brief TPM Presence Test
         */
        void testTPMPresence ( void )
        {
            int64_t fails = 0, num_ops = 0;
            bool presence = false;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMPresence - Start" );

            do
            {

                // Get a processor Target instead of a tpm target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = nullptr;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != nullptr);

                // Skip this target if target is non-functional
                if(!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                                                   .functional)
                {
                    continue;
                }

                num_ops++;

                // Test with invalid proc target
                presence = TPMDD::tpmPresence(testTarget);
                if( presence == true )
                {
                    fails++;
                    TS_FAIL( "testTPMPresence - ProcTarget: Error when "
                             "using processor target, false presence!" );
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMPresence - "
                              "ProcTarget: False returned as expected. ");
                }


                testTarget = getTestTarget();

                if (nullptr != testTarget)
                {
                    // Now test with valid primary target
                    num_ops++;
                    presence = TPMDD::tpmPresence(testTarget);
                    if( presence == false )
                    {
                        fails++;
                        TS_FAIL( "testTPMPresence - TPMPrimary: true should've "
                                 "resulted in using backup TPM!" );
                    }
                    else
                    {
                        TRACUCOMP(g_trac_tpmdd, "testTPMPresence - "
                                  "TPMPrimary: true returned as expected. ");
                    }
                }

            } while( 0 );

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMPresence - End: %d/%d fails",
                       fails, num_ops );
        }


        /**
         * @brief TPM Transmit Test
         */
        void testTPMTransmit ( void )
        {

            errlHndl_t err = nullptr;
            int64_t fails = 0, num_ops = 0;
            uint8_t data[256];
            size_t dataSize = sizeof(data);
            size_t cmdSize = 0;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMTransmit - Start" );
            do
            {

                // Get a TPM Target
                TARGETING::Target* testTarget = getTestTarget();
                if (nullptr == testTarget)
                {
                    continue;
                }


                // Build our command block for a get capability
                dataSize = sizeof(data);
                memset(data, 0xFE, sizeof(data));

                TRUSTEDBOOT::TPM2_GetCapabilityIn* cmd =
                    reinterpret_cast<TRUSTEDBOOT::TPM2_GetCapabilityIn*>
                    (data);

                cmd->base.commandSize =
                    sizeof (TRUSTEDBOOT::TPM2_GetCapabilityIn);
                cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
                cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;
                cmd->capability = TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;
                cmd->property = TRUSTEDBOOT::TPM_PT_MANUFACTURER;
                cmd->propertyCount = 1;
                cmdSize = cmd->base.commandSize;

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_OP_TRANSMIT,
                                                     cmdSize,
                                                     TPM_LOCALITY_0) );

                TRUSTEDBOOT::TPM2_BaseOut* resp =
                    reinterpret_cast<TRUSTEDBOOT::TPM2_BaseOut*>(data);


                if( nullptr != err )
                {
                    fails++;
                    TS_FAIL( "testTPMTransmit - GetCap : Error detected" );
                    errlCommit( err, TPMDD_COMP_ID );
                    delete err;
                    err = nullptr;
                    continue;
                }
                else if (TRUSTEDBOOT::TPM_SUCCESS !=
                         resp->responseCode)
                {
                    fails++;
                    TS_FAIL( "testTPMTransmit - GetCap : "
                             "TPM return non-success : %d",
                             resp->responseCode);
                    continue;
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMTransmit - GetCap : "
                              "Transmit returned as expected. len=%d",
                              dataSize);
                }

            } while( 0 );
            TRACFCOMP( g_trac_tpmdd,
                       "testTPMTransmit - End: %d/%d fails",
                       fails, num_ops );
        }


        /**
         * @brief TPM Transmit Over/Under flow Test
         */
        void testTPMTransmitOverUnder ( void )
        {

            errlHndl_t err = nullptr;
            int64_t fails = 0, num_ops = 0;
            uint8_t data[256];
            size_t dataSize = sizeof(data);
            size_t cmdSize = 0;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMTransmitOverUnder - Start" );

            do
            {

                // Get a TPM Target
                TARGETING::Target* testTarget = getTestTarget();
                if (nullptr == testTarget)
                {
                    continue;
                }

                dataSize = sizeof(data);
                memset(data, 0xFE, sizeof(data));

                // Test a TPM data overflow
                TRUSTEDBOOT::TPM2_GetCapabilityIn* cmd =
                    reinterpret_cast<TRUSTEDBOOT::TPM2_GetCapabilityIn*>(data);

                cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
                cmd->base.commandSize =
                    sizeof (TRUSTEDBOOT::TPM2_GetCapabilityIn);
                cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;
                cmd->capability = TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;
                cmd->property = TRUSTEDBOOT::TPM_PT_MANUFACTURER;
                cmd->propertyCount = 1;

                cmdSize = cmd->base.commandSize;

                num_ops++;
                // Force datasize to be too small
                dataSize = sizeof(TRUSTEDBOOT::TPM2_BaseOut);

                err = deviceRead(testTarget,
                                 data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS(TPM_OP_TRANSMIT,
                                                    cmdSize,
                                                    TPM_LOCALITY_0) );

                if( (nullptr == err) ||
                    (err->reasonCode() != TPM_OVERFLOW_ERROR) )
                {
                    fails++;
                    TS_FAIL( "testTPMTransmitOverUnder - Error "
                             "data overflow NOT detected - "
                             "(dataSize %d vs cmdSize %d), "
                             " rc=0x%X, plid=0x%X",
                             sizeof(TRUSTEDBOOT::TPM2_BaseOut), cmdSize,
                             ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err) );
                    if (err)
                    {
                        errlCommit( err,
                                    TPMDD_COMP_ID );
                        delete err;
                        err = nullptr;
                    }
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMTransmitOverUnder - "
                              "DataOver Transmit returned as expected. len=%d",
                              dataSize);
                }

            } while( 0 );
            TRACFCOMP( g_trac_tpmdd,
                       "testTPMTransmitOverUnder - End: %d/%d fails",
                       fails, num_ops );
        }

};

#endif
