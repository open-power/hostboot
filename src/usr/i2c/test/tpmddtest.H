/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/test/tpmddtest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#include <i2c/tpmddreasoncodes.H>
#include <targeting/common/commontargeting.H>
#include "i2ctest.H"
#include "../tpmdd.H"
#include "../../secureboot/trusted/trustedboot.H"

extern trace_desc_t* g_trac_tpmdd;

// NOTE: TRACUCOMP defined/controlled in i2ctest.H

using namespace TARGETING;
using namespace TPMDD;


class TPMDDTest: public CxxTest::TestSuite
{
    public:

        /**
         * @brief Retrieve a node target to test with
         */
        TARGETING::Target* getTestTarget( tpm_chip_types_t i_chip )
        {
            TARGETING::TargetService& tS = TARGETING::targetService();
            TARGETING::Target* testTarget = NULL;
            tS.getMasterNodeTarget( testTarget );

            assert(testTarget != NULL);

            TRACFCOMP( g_trac_tpmdd,
                       "getTestTarget node tgt=0x%X chip=%d",
                       TARGETING::get_huid(testTarget),
                       i_chip);

            // Let's see if the requested chip is functional
            tpm_info_t tpmInfo;
            tpmInfo.chip = i_chip;
            errlHndl_t err = tpmReadAttributes (testTarget, tpmInfo);

            if (NULL != err)
            {
                testTarget = NULL;
                delete err;
            }
            else if (!tpmInfo.tpmEnabled)
            {
                TRACFCOMP(g_trac_tpmdd, "getTestTarget - "
                          "Chip %d not enabled",
                          i_chip);
                testTarget = NULL;
            }
            else
            {
                TRACFCOMP(g_trac_tpmdd, "getTestTarget - "
                          "Chip %d enabled",
                          i_chip);
            }

            return testTarget;
        }

        /**
         * @brief TPM Read VendorID Test
         */
        void testTPMReadVendorID ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint32_t data = 0x0;
            size_t dataSize = sizeof(data);

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMReadVendorID - Start" );

            do
            {
                // Get a node Target
                TARGETING::Target* testTarget = getTestTarget(TPM_PRIMARY);
                if (NULL == testTarget)
                {
                    continue;
                }

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                                     TPM_OP_READVENDORID,
                                                     0) );

                if( NULL != err )
                {
                    fails++;
                    TS_FAIL( "testTPMReadVendorID - Error detected" );
                    errlCommit( err,
                                TPMDD_COMP_ID );
                    delete err;
                    err = NULL;
                    continue;
                }
                else if ((data & TPMDD::TPM_VENDORID_MASK)
                         != TPMDD::TPM_VENDORID)
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
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 0;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMInvalidOperation - Start" );

            do
            {

                // Get a node Target
                TARGETING::Target* testTarget = getTestTarget(TPM_PRIMARY);
                if (NULL == testTarget)
                {
                    continue;
                }

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                                     TPM_OP_LASTOP,
                                                     0) );

                if( NULL == err )
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
                    err = NULL;
                }


                num_ops++;
                err = deviceOp( DeviceFW::LAST_OP_TYPE,
                                testTarget,
                                &data,
                                dataSize,
                                DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                                    TPM_OP_READVENDORID,
                                                    0) );

                if( NULL == err )
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
                    err = NULL;
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
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = 0;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMOverflow - Start" );

            do
            {
                // Get a node Target
                TARGETING::Target* testTarget = getTestTarget(TPM_PRIMARY);
                if (NULL == testTarget)
                {
                    continue;
                }

                // Set max length
                dataSize = 0xFFFFFFFFFFFFFFFF;
                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                                     TPM_OP_READVENDORID,
                                                     0) );

                if( NULL == err ||
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
                    err = NULL;
                }



            } while( 0 );

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMOverflow - End: %d/%d fails",
                       fails, num_ops );
        }


        /**
         * @brief TPM Invalid Chip Test
         *      This test will pass in an invalid chip identifier which should
         *      result in an error being returned.
         */
        void testTPMInvalidChip ( void )
        {
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint64_t data = 0x0ull;
            size_t dataSize = sizeof(data);

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMInvalidChip - Start" );

            do
            {

                // Get a processor Target instead of a node target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                                     TPM_OP_READVENDORID,
                                                     0) );

                if( NULL == err )
                {
                    fails++;
                    TS_FAIL( "testTPMInvalidChip - ProcTarget: Error should've "
                             "resulted in using processor target!" );
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMInvalidChip - "
                              "ProcTarget: Error log returned as expected. "
                              "RC=0x%x ",
                              err->reasonCode() );
                    delete err;
                    err = NULL;
                }



                // Attempt operation against the backup TPM
                tS.getMasterNodeTarget( testTarget );
                assert(testTarget != NULL);

                // Skip this target if target is non-functional
                if(!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                                                   .functional)
                {
                    continue;
                }

                // Many systems don't have a backup TPM, if not configured
                //  test TPM presence against it
                if (getTestTarget(TPM_BACKUP) == NULL)
                {

                    num_ops++;
                    err = deviceRead(testTarget,
                                     &data,
                                     dataSize,
                                     DEVICE_TPM_ADDRESS( TPM_BACKUP,
                                                         TPM_OP_READVENDORID,
                                                         0) );

                    if( NULL == err ||
                        err->reasonCode() != TPM_DEVICE_NOT_AVAILABLE)
                    {
                        fails++;
                        TS_FAIL( "testTPMInvalidChip - TpmBackup : Error "
                                 "should've "
                                 "resulted in using backup TPM target!" );
                    }
                    else
                    {
                        TRACUCOMP(g_trac_tpmdd, "testTPMInvalidChip - "
                                  "TpmBackup : Error log returned as expected. "
                                  "RC=0x%X ",
                                  err->reasonCode() );
                        delete err;
                        err = NULL;
                    }
                }

            } while( 0 );

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMInvalidChip - End: %d/%d fails",
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

                // Get a processor Target instead of a node target
                TARGETING::TargetService& tS = TARGETING::targetService();
                TARGETING::Target* testTarget = NULL;
                tS.masterProcChipTargetHandle( testTarget );
                assert(testTarget != NULL);

                // Skip this target if target is non-functional
                if(!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                                                   .functional)
                {
                    continue;
                }

                num_ops++;

                // Test with invalid proc target
                presence = TPMDD::tpmPresence(testTarget,
                                              TPM_PRIMARY);
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


                tS.getMasterNodeTarget( testTarget );
                assert(testTarget != NULL);

                // Skip this target if target is non-functional
                if(!testTarget->getAttr<TARGETING::ATTR_HWAS_STATE>()
                   .functional)
                {
                    continue;
                }


                // Many systems don't have a backup TPM, if not configured
                //  test TPM presence against it
                if (getTestTarget(TPM_BACKUP) == NULL)
                {

                    num_ops++;
                    // Attempt operation against the backup TPM
                    presence = TPMDD::tpmPresence(testTarget,
                                                  TPM_BACKUP);
                    if( presence == true )
                    {
                        fails++;
                        TS_FAIL( "testTPMPresence - TPMBackup: Error when "
                                 "using backup TPM!, false presence" );
                    }
                    else
                    {
                        TRACUCOMP(g_trac_tpmdd, "testTPMPresence - "
                                  "TPMBackup: False returned as expected. ");
                    }
                }


                if (getTestTarget(TPM_PRIMARY) != NULL)
                {
                    // Now test with valid primary target
                    num_ops++;
                    presence = TPMDD::tpmPresence(testTarget,
                                                  TPM_PRIMARY);
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

            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint8_t data[256];
            size_t dataSize = sizeof(data);
#ifdef CONFIG_TPMDD_1_2
            uint32_t subCap = 0;
#endif
            size_t cmdSize = 0;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMTransmit - Start" );
            do
            {

                // Get a node Target
                TARGETING::Target* testTarget = getTestTarget(TPM_PRIMARY);
                if (NULL == testTarget)
                {
                    continue;
                }


                // Build our command block for a get capability
                dataSize = sizeof(data);
                memset(data, 0xFE, sizeof(data));

#ifdef CONFIG_TPMDD_1_2
                TRUSTEDBOOT::TPM_GetCapabilityIn* capCmd =
                    reinterpret_cast<TRUSTEDBOOT::TPM_GetCapabilityIn*>(data);
                subCap = TRUSTEDBOOT::TPM_CAP_PROP_MANUFACTURER;

                capCmd->base.tag = TRUSTEDBOOT::TPM_TAG_RQU_COMMAND;
                capCmd->base.paramSize =
                    sizeof (TRUSTEDBOOT::TPM_GetCapabilityIn) + sizeof (subCap);
                capCmd->base.ordinal = TRUSTEDBOOT::TPM_ORD_GetCapability;
                capCmd->capArea = TRUSTEDBOOT::TPM_CAP_PROPERTY;
                capCmd->subCapSize = sizeof (subCap);
                memcpy(capCmd->subCap, &subCap, sizeof (subCap));
                cmdSize = capCmd->base.paramSize;
#elif defined (CONFIG_TPMDD_2_0)
                TRUSTEDBOOT::TPM2_GetCapabilityIn* cmd =
                    (TRUSTEDBOOT::TPM2_GetCapabilityIn*)data;

                cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
                cmd->base.commandSize =
                    sizeof (TRUSTEDBOOT::TPM2_GetCapabilityIn);
                cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;
                cmd->capability = TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;
                cmd->property = TRUSTEDBOOT::TPM_PT_MANUFACTURER;
                cmd->propertyCount = 1;

                cmdSize = cmd->base.commandSize;

#endif

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                                     TPM_OP_TRANSMIT,
                                                     cmdSize) );

                TRUSTEDBOOT::TPM_BaseOut* resp =
                    reinterpret_cast<TRUSTEDBOOT::TPM_BaseOut*>(data);


                if( NULL != err )
                {
                    fails++;
                    TS_FAIL( "testTPMTransmit - GetCap : Error detected" );
                    errlCommit( err,
                                TPMDD_COMP_ID );
                    delete err;
                    err = NULL;
                    continue;
                }
                else if (resp->paramSize != dataSize)
                {
                    fails++;
                    TS_FAIL( "testTPMTransmit - GetCap : TPM didn't return "
                             "correct response size E:%d A:%d",
                             resp->paramSize,
                             dataSize);
                    continue;
                }
                else if (TRUSTEDBOOT::TPM_SUCCESS !=
                         resp->returnCode)
                {
                    fails++;
                    TS_FAIL( "testTPMTransmit - GetCap : "
                             "TPM return non-success : %d",
                             resp->returnCode);
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

    // Unfortunately the simics 1.2 model doesn't handle the following
    // over/under flow tests properly
#ifndef CONFIG_TPMDD_1_2
            errlHndl_t err = NULL;
            int64_t fails = 0, num_ops = 0;
            uint8_t data[256];
            size_t dataSize = sizeof(data);
#ifdef CONFIG_TPMDD_1_2
            uint32_t subCap = 0;
#endif
            size_t cmdSize = 0;

            TRACFCOMP( g_trac_tpmdd,
                       "testTPMTransmitOverUnder - Start" );

            do
            {

                // Get a node Target
                TARGETING::Target* testTarget = getTestTarget(TPM_PRIMARY);
                if (NULL == testTarget)
                {
                    continue;
                }

                // Build our command block for a startup
                memset(data, 0xFE, sizeof(data));

                // Test a TPM command underflow
#ifdef CONFIG_TPMDD_1_2
                TRUSTEDBOOT::TPM_GetCapabilityIn* capCmd =
                    reinterpret_cast<TRUSTEDBOOT::TPM_GetCapabilityIn*>(data);
                subCap = TRUSTEDBOOT::TPM_CAP_PROP_MANUFACTURER;

                capCmd->base.tag = TRUSTEDBOOT::TPM_TAG_RQU_COMMAND;
                capCmd->base.paramSize =
                    sizeof (TRUSTEDBOOT::TPM_GetCapabilityIn) + sizeof (subCap);
                capCmd->base.ordinal = TRUSTEDBOOT::TPM_ORD_GetCapability;
                capCmd->capArea = TRUSTEDBOOT::TPM_CAP_PROPERTY;
                capCmd->subCapSize = sizeof (subCap);
                memcpy(capCmd->subCap, &subCap, sizeof (subCap));
                cmdSize = capCmd->base.paramSize;
#elif defined (CONFIG_TPMDD_2_0)
                TRUSTEDBOOT::TPM2_GetCapabilityIn* cmd =
                    (TRUSTEDBOOT::TPM2_GetCapabilityIn*)data;

                cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
                cmd->base.commandSize =
                    sizeof (TRUSTEDBOOT::TPM2_GetCapabilityIn);
                cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;
                cmd->capability = TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;
                cmd->property = TRUSTEDBOOT::TPM_PT_MANUFACTURER;
                cmd->propertyCount = 1;

                cmdSize = cmd->base.commandSize;
#endif

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                          TPM_OP_TRANSMIT,
                                          cmdSize - 1) );

                if( NULL == err ||
                    err->reasonCode() != TPM_UNDERFLOW_ERROR)
                {
                    fails++;
                    TS_FAIL( "testTPMTransmitOverUnder - Error "
                             "command underflow not detected" );
                    errlCommit( err,
                                TPMDD_COMP_ID );
                    delete err;
                    err = NULL;
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMTransmitOverUnder - "
                              "CmdUnder Transmit returned as expected. len=%d",
                              dataSize);
                }


                // Build our command block for a startup
                dataSize = sizeof(data);
                memset(data, 0xFE, sizeof(data));

                // Test a TPM command overflow
#ifdef CONFIG_TPMDD_1_2
                subCap = TRUSTEDBOOT::TPM_CAP_PROP_MANUFACTURER;

                capCmd->base.tag = TRUSTEDBOOT::TPM_TAG_RQU_COMMAND;
                capCmd->base.paramSize =
                    sizeof (TRUSTEDBOOT::TPM_GetCapabilityIn) + sizeof (subCap);
                capCmd->base.ordinal = TRUSTEDBOOT::TPM_ORD_GetCapability;
                capCmd->capArea = TRUSTEDBOOT::TPM_CAP_PROPERTY;
                capCmd->subCapSize = sizeof (subCap);
                memcpy(capCmd->subCap, &subCap, sizeof (subCap));
                cmdSize = capCmd->base.paramSize;
#elif defined (CONFIG_TPMDD_2_0)

                cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
                cmd->base.commandSize =
                    sizeof (TRUSTEDBOOT::TPM2_GetCapabilityIn);
                cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;
                cmd->capability = TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;
                cmd->property = TRUSTEDBOOT::TPM_PT_MANUFACTURER;
                cmd->propertyCount = 1;

                cmdSize = cmd->base.commandSize;
#endif

                num_ops++;
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                         TPM_OP_TRANSMIT,
                                         cmdSize + 1) );

                if( NULL == err ||
                    err->reasonCode() != TPM_OVERFLOW_ERROR)
                {
                    fails++;
                    TS_FAIL( "testTPMTransmitOverUnder - Error "
                             "command overflow not detected" );
                    errlCommit( err,
                                TPMDD_COMP_ID );
                    delete err;
                    err = NULL;
                }
                else
                {
                    TRACUCOMP(g_trac_tpmdd, "testTPMTransmitOverUnder - "
                              "CmdOver Transmit returned as expected. len=%d",
                              dataSize);
                }

                // Build our command block for a startup
                dataSize = sizeof(data);
                memset(data, 0xFE, sizeof(data));

                // Test a TPM data overflow
#ifdef CONFIG_TPMDD_1_2
                subCap = TRUSTEDBOOT::TPM_CAP_PROP_MANUFACTURER;

                capCmd->base.tag = TRUSTEDBOOT::TPM_TAG_RQU_COMMAND;
                capCmd->base.paramSize =
                    sizeof (TRUSTEDBOOT::TPM_GetCapabilityIn) + sizeof (subCap);
                capCmd->base.ordinal = TRUSTEDBOOT::TPM_ORD_GetCapability;
                capCmd->capArea = TRUSTEDBOOT::TPM_CAP_PROPERTY;
                capCmd->subCapSize = sizeof (subCap);
                memcpy(capCmd->subCap, &subCap, sizeof (subCap));
                cmdSize = capCmd->base.paramSize;
#elif defined (CONFIG_TPMDD_2_0)

                cmd->base.tag = TRUSTEDBOOT::TPM_ST_NO_SESSIONS;
                cmd->base.commandSize =
                    sizeof (TRUSTEDBOOT::TPM2_GetCapabilityIn);
                cmd->base.commandCode = TRUSTEDBOOT::TPM_CC_GetCapability;
                cmd->capability = TRUSTEDBOOT::TPM_CAP_TPM_PROPERTIES;
                cmd->property = TRUSTEDBOOT::TPM_PT_MANUFACTURER;
                cmd->propertyCount = 1;

                cmdSize = cmd->base.commandSize;
#endif

                num_ops++;
                // Force datasize to be too small
                dataSize = sizeof(TRUSTEDBOOT::TPM_BaseOut);
                err = deviceRead(testTarget,
                                 &data,
                                 dataSize,
                                 DEVICE_TPM_ADDRESS( TPM_PRIMARY,
                                        TPM_OP_TRANSMIT,
                                        cmdSize) );

                if( NULL == err ||
                    err->reasonCode() != TPM_OVERFLOW_ERROR)
                {
                    fails++;
                    TS_FAIL( "testTPMTransmitOverUnder - Error "
                             "data overflow not detected" );
                    errlCommit( err,
                                TPMDD_COMP_ID );
                    delete err;
                    err = NULL;
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
#endif // !defined CONFIG_TPMDD_1_2
        }

};

#endif
