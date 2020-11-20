/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_ffdc_package_parser_test.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#ifndef __SBEIO_SBE_FFDC_PACKAGE_PARSER_TEST_H
#define __SBEIO_SBE_FFDC_PACKAGE_PARSER_TEST_H

#include <hwp_return_codes.H>

#include <sbeio/sbe_ffdc_package_parser.H>
#include <trace/interface.H>

#include <cxxtest/TestSuite.H>
#include "sbe_test_support.H"

extern trace_desc_t* g_trac_sbeio;

#define SBE_FFDC_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"sbeFFDCParserTest: " printf_string,##args)
using namespace SBEIO;

class FfdcScomPibErrorPackageTestFixure: public SBEIO::FfdcScomPibErrorPackage
{
public:

    FfdcScomPibErrorPackageTestFixure(const ffdc_package& i_ffdc,
                                      bool i_ignoreRC = false):
                                      FfdcScomPibErrorPackage(i_ffdc,
                                                              i_ignoreRC)
    {
        clearCounts();
    }

//Mock the addFruCallouts method.
void addFruCallouts (TARGETING::Target* i_target,
                     errlHndl_t i_errHndl
                     ) const override
{
    ++cv_defaultActionInvoked;

    if(not i_target)
    {
        ++cv_nullTargetCount;
    }

    if(not i_errHndl)
    {
        ++cv_nullErrlHndlCount;
    }
}

static size_t callCount() {return cv_defaultActionInvoked;}
static size_t nullTargetCount() {return cv_nullTargetCount;}
static size_t nullErrlHndlCount() {return cv_nullErrlHndlCount;}

static void clearCounts()
{
    cv_defaultActionInvoked = 0;
    cv_nullTargetCount = 0;
    cv_nullErrlHndlCount = 0;
}

private:

    static size_t cv_defaultActionInvoked;
    static size_t cv_nullTargetCount;
    static size_t cv_nullErrlHndlCount;
};

size_t FfdcScomPibErrorPackageTestFixure::cv_defaultActionInvoked = 0;
size_t FfdcScomPibErrorPackageTestFixure::cv_nullTargetCount = 0;
size_t FfdcScomPibErrorPackageTestFixure::cv_nullErrlHndlCount = 0;


std::vector<uint32_t>  bufferFFDC = {
                                    0xFFDC0009, //FFDC 1 - Magic + Len
                                    0x0000A807, //FFDC 2 - Seq, Cmd class, cmd
                                    0x00983AB6, //FFDC 3 - RC_SBE_SCOM_FAILURE
                                    0x00000008, //FFDC 4 - scom addr size
                                    0x12345678, //FFDC 5 - scom addr msb
                                    0x9ABCDEF0, //FFDC 6 - scom addr lsb
                                    0x00000001, //FFDC 7 - PIB RC size
                                    0x00000000, //FFDC 8 - PIB_PARITY_ERROR msb
                                    0x00000006  //FFDC 9 - PIB_PARITY_ERROR lsb
                                     };

std::vector<uint32_t>  bufferUnknownRCFFDC = {
                                    0xFFDC0009, //FFDC 1 - Magic + Len
                                    0x0000A807, //FFDC 2 - Seq, Cmd class, cmd
                                    0xFF983AB6, //FFDC 3 - FAPI RC
                                    0x00000008, //FFDC 4 - scom addr size
                                    0x12345678, //FFDC 5 - scom addr msb
                                    0x9ABCDEF0, //FFDC 6 - scom addr lsb
                                    0x00000001, //FFDC 7 - PIB RC size
                                    0x00000000, //FFDC 8 - PIB_PARITY_ERROR msb
                                    0x00000006  //FFDC 9 - PIB_PARITY_ERROR lsb
                                     };

std::vector<uint32_t>  bufferBadSchemaFFDC = {
                                    0xFFDC000A, //FFDC 1 - Magic + Len
                                    0x0000A807, //FFDC 2 - Seq, Cmd class, cmd
                                    0x00983AB6, //FFDC 3 - RC_SBE_SCOM_FAILURE
                                    0x00000008, //FFDC 4 - scom addr size
                                    0x12345678, //FFDC 5 - scom addr msb
                                    0x9ABCDEF0, //FFDC 6 - scom addr lsb
                                    0x00000001, //FFDC 7 - PIB RC size
                                    0x00000000, //FFDC 8 - PIB_PARITY_ERROR msb
                                    0x00000006, //FFDC 9 - PIB_PARITY_ERROR lsb
                                    0xFFEEDDCC  //FFDC 10  Extra Garbage Word
                                     };

uint64_t addr = 0x1234567890ABCDEF;
TARGETING::Target* g_testTarget = reinterpret_cast<TARGETING::Target*>(addr);
errlHndl_t g_errl = reinterpret_cast<errlHndl_t>(addr);

ffdc_package g_testPackage = {nullptr, 0, 0};

//============================================================
class SbeFFDCPackageParserTest : public CxxTest::TestSuite
{
public:

    void testGoodFFDC()
    {
        SBE_FFDC_TRACD("ENTER sbeFFDCParserTest testGoodFFDC");

        bool result{true};

        do
        {
            g_testPackage.ffdcPtr = &bufferFFDC[3];
            g_testPackage.size = (bufferFFDC.size() - 3) * sizeof(uint32_t);
            g_testPackage.rc = bufferFFDC[2];

            bool matchesSchema =
            FfdcScomPibErrorPackage::doesPackageMatchSchema(g_testPackage);

            if(not matchesSchema)
            {
                char strFfdc[64];
                xxdPrint(g_testPackage.ffdcPtr, g_testPackage.size, strFfdc);

                SBE_FFDC_TRACD("sbeFFDCParserTest testGoodFFDC: "
                               "doesPackageMatchSchema unexpectedly "
                               "returned false. Input FFDC:%s",
                                strFfdc
                              );

                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "doesPackageMatchSchema unexpectedly result = false."
                       );

                result = false;
                break;
            }

            FfdcScomPibErrorPackageTestFixure l_ffdcPackage{g_testPackage};

            if(not l_ffdcPackage.isValid())
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "ffdc package was not successfully parsed."
                       );

                result = false;
                break;
            }

            if(not l_ffdcPackage)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "operator bool failed. ffdc package was not "
                        "successfully parsed."
                       );

                result = false;
                break;
            }

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
                                                    l_ffdcPackage.parsedType())
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "Did not receive ParsedType SBE_SCOM_PIB_ERROR "
                        "from ParsedType() call."
                       );

                result = false;
                break;
            }

            uint64_t scomAddr = l_ffdcPackage.getScomAddress();
            uint64_t expectedScomAddr = *(reinterpret_cast<const uint64_t*>
                                                             (&bufferFFDC[4]));
            if(expectedScomAddr != scomAddr)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "Did not receive scom addr 0x%08X as expected. "
                        "scom addr: 0x%08X",
                         expectedScomAddr,
                         scomAddr
                       );

                result = false;
                break;
            }

            uint64_t pibRc = l_ffdcPackage.getPibRc();
            uint64_t expectedPibRc = *(reinterpret_cast<const uint64_t*>
                                                             (&bufferFFDC[7]));
            if(expectedPibRc != pibRc)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "Did not receive pib rc 0x%08X as expected. "
                        "pib rc: 0x%08X",
                         expectedPibRc,
                         pibRc
                       );

                result = false;
                break;
            }

            l_ffdcPackage(g_testTarget, g_errl);

            if(FfdcScomPibErrorPackageTestFixure::callCount() == 0)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "call operator did not invoke addFruCallouts"
                       );

                result = false;
                break;
            }

            if(FfdcScomPibErrorPackageTestFixure::nullTargetCount() != 0)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "call operator invoked addFruCallouts with a "
                        "null target argument."
                       );

                result = false;
                break;
            }

            if(FfdcScomPibErrorPackageTestFixure::nullErrlHndlCount() != 0)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDC: "
                        "call operator invoked addFruCallouts with a "
                        "null errlHndl_t argument."
                       );

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_FFDC_TRACD("sbeFFDCParserTest testGoodFFDC test passed!");
        }
        else
        {
            SBE_FFDC_TRACD("sbeFFDCParserTest testGoodFFDC test failed!");
        }
    }

    //------------------------------------------------------------------
    void testGoodFFDCBaseClass()
    {
        SBE_FFDC_TRACD("ENTER sbeFFDCParserTest TestGoodFFDCBaseClass");

        bool result{true};

        do
        {
            bufferFFDC[2] = static_cast<uint32_t>(fapi2::RC_SBE_SCOM_FAILURE);
            bufferFFDC[3] = 4; // test with size of scom addr = 4
            g_testPackage.ffdcPtr = &bufferFFDC[3];
            g_testPackage.size = (bufferFFDC.size() - 3) * sizeof(uint32_t);
            g_testPackage.rc = bufferFFDC[2];

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
              FfdcParsedPackage::rcToParsedType(fapi2::RC_SBE_SCOM_FAILURE))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "RC_SBE_SCOM_FAILURE did not map to SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
                FfdcParsedPackage::rcToParsedType(
                                            fapi2::RC_SBE_PIB_XSCOM_ERROR))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "RC_SBE_PIB_XSCOM_ERROR did not map to "
                        "SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
                FfdcParsedPackage::rcToParsedType(
                                            fapi2::RC_SBE_PIB_OFFLINE_ERROR))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "RC_SBE_PIB_OFFLINE_ERROR did not map to "
                        "SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
                FfdcParsedPackage::rcToParsedType(
                                            fapi2::RC_SBE_PIB_PARTIAL_ERROR))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "RC_SBE_PIB_PARTIAL_ERROR did not map to "
                        "SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
                FfdcParsedPackage::rcToParsedType(
                                            fapi2::RC_SBE_PIB_ADDRESS_ERROR))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "RC_SBE_PIB_ADDRESS_ERROR did not map to "
                        "SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
                FfdcParsedPackage::rcToParsedType(
                                            fapi2::RC_SBE_PIB_CLOCK_ERROR))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "RC_SBE_PIB_CLOCK_ERROR did not map to "
                        "SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
                FfdcParsedPackage::rcToParsedType(
                                            fapi2::RC_SBE_PIB_PARITY_ERROR))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "RC_SBE_PIB_PARITY_ERROR did not map to "
                        "SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }

            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR !=
                FfdcParsedPackage::rcToParsedType(
                                            fapi2::RC_SBE_PIB_TIMEOUT_ERROR))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "RC_SBE_PIB_TIMEOUT_ERROR did not map to "
                        "SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }


            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR ==
                FfdcParsedPackage::rcToParsedType(0xFFEEDDCC))
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "0xFFEEDDCC mapped to SBE_SCOM_PIB_ERROR"
                       );

                result = false;
                break;
            }

            std::shared_ptr<const FfdcParsedPackage> l_package =
                FfdcParsedPackage::getParsedPackage(g_testPackage);

            if(not l_package)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "getParsedPackage result = returned a null pointer."
                       );

                result = false;
                break;
            }

            if(not l_package->isValid())
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "getParsedPackage did not parse the ffdc package."
                       );

                result = false;
                break;
            }


            if(FfdcParsedPackage::ParsedType::SBE_SCOM_PIB_ERROR
                                                   !=  l_package->parsedType())
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "getParsedPackage did not parse the ffdc package "
                        "to the correct type."
                       );

                result = false;
                break;
            }

            FfdcScomPibErrorPackageTestFixure l_ffdcPackage{g_testPackage};

            if(not l_ffdcPackage.isValid())
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "ffdc package was not successfully parsed."
                       );

                result = false;
                break;
            }

            FfdcScomPibErrorPackageTestFixure::clearCounts();
            l_ffdcPackage(g_testTarget, g_errl);

            if(FfdcScomPibErrorPackageTestFixure::callCount() == 0)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "call operator did not invoke addFruCallouts"
                       );

                result = false;
                break;
            }

            if(FfdcScomPibErrorPackageTestFixure::nullTargetCount() != 0)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "call operator invoked addFruCallouts with a "
                        "null target argument."
                       );

                result = false;
                break;
            }

            if(FfdcScomPibErrorPackageTestFixure::nullErrlHndlCount() != 0)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "call operator invoked addFruCallouts with a "
                        "null errlHndl_t argument."
                       );

                result = false;
                break;
            }

            g_testPackage.ffdcPtr = &bufferBadSchemaFFDC[2];
            g_testPackage.size = (bufferBadSchemaFFDC.size() - 2) *
                                                              sizeof(uint32_t);
            g_testPackage.rc = 0xFF983AB6; //arbitrary value

            FfdcScomPibErrorPackageTestFixure
                                        l_ffdcPackage_badschema{g_testPackage};

            FfdcScomPibErrorPackageTestFixure::clearCounts();
            l_ffdcPackage_badschema(g_testTarget, g_errl);

            if(FfdcScomPibErrorPackageTestFixure::callCount() != 0)
            {
                TS_FAIL("sbeFFDCParserTest testGoodFFDCBaseClass: "
                        "call operator invoked addFruCallouts on bad FFDC"
                       );

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_FFDC_TRACD("sbeFFDCParserTest testGoodFFDCBaseClass "
                                                              "test passed!");
        }
        else
        {
             SBE_FFDC_TRACD("sbeFFDCParserTest testGoodFFDCBaseClass "
                                                              "test failed!");
        }
    }


     //------------------------------------------------------------------
     void testbadFFDCSchema()
     {
        SBE_FFDC_TRACD("ENTER sbeFFDCParserTest testbadFFDCSchema");

        bufferBadSchemaFFDC[2] = static_cast<uint32_t>
                                            (fapi2::RC_SBE_SCOM_FAILURE);

        g_testPackage.ffdcPtr = &bufferBadSchemaFFDC[3];
        g_testPackage.size = (bufferBadSchemaFFDC.size() - 3) *
                                                            sizeof(uint32_t);
        g_testPackage.rc = bufferBadSchemaFFDC[2];

        FfdcScomPibErrorPackageTestFixure l_ffdcPackage{g_testPackage};

        bool result{true};

        do
        {
            if(l_ffdcPackage.isValid())
            {
                TS_FAIL("sbeFFDCParserTest testbadFFDCSchema: "
                        "ffdc package was unexpectedly successfully parsed."
                       );

                result = false;
                break;
            }

            if(l_ffdcPackage)
            {
                TS_FAIL("sbeFFDCParserTest testbadFFDCSchema: "
                        "operator bool returned true. The ffdc package was "
                        "unexpectedly successfully parsed."
                       );

                result = false;
                break;
            }
        }
        while(0);

        if(result)
        {
            SBE_FFDC_TRACD("sbeFFDCParserTest testbadFFDCSchema test passed!");
        }
        else
        {
            SBE_FFDC_TRACD("sbeFFDCParserTest testbadFFDCSchema test failed!");
        }
     }

     //---------------------------------------------------------------------
     void testWithFFDCParser()
     {
         SBE_FFDC_TRACD("ENTER sbeFFDCParserTest testWithFFDCParser");

         bool result{true};

         SbeFFDCParser ffdcParser;
         ffdcParser.parseFFDCData(&bufferFFDC[0]);

         do
         {
             if(1 != ffdcParser.getTotalPackages())
             {
                 TS_FAIL("sbeFFDCParserTest testWithFFDCParser: "
                         "ffdcParser.getTotalPackages() returned %d, "
                         "expected 1.",
                          ffdcParser.getTotalPackages()
                        );

                 result = false;
                 break;
             }

             ffdc_package package;
             package.ffdcPtr = ffdcParser.getFFDCPackage(0);
             package.rc = ffdcParser.getPackageRC(0);
             package.size = ffdcParser.getPackageLength(0);

             FfdcScomPibErrorPackageTestFixure l_ffdcPackage{package};

             if(not l_ffdcPackage.isValid())
             {
                char strFfdc[64];
                xxdPrint(package.ffdcPtr, package.size, strFfdc);
                SBE_FFDC_TRACD("testWithFFDCParser "
                               "Ffdc package was not successfully parsed. "
                               "FFDC Data:\n%s",
                                strFfdc
                              );

                TS_FAIL("sbeFFDCParserTest testWithFFDCParser: "
                        "Ffdc package was not successfully parsed."
                       );

                result = false;
                break;
             }

             ffdc_package package2 = {nullptr, 0, 0};
             bool rc = ffdcParser.getFFDCPackage(0, package2);

             if(not rc)
             {
                TS_FAIL("sbeFFDCParserTest testWithFFDCParser: "
                        "ffdcParser.getFFDCPackage(0, package2) failed."
                       );

                result = false;
                break;
             }

             FfdcScomPibErrorPackageTestFixure l_ffdcPackage2{package2};

             if(not l_ffdcPackage2.isValid())
             {
                char strFfdc[64];
                xxdPrint(package.ffdcPtr, package.size, strFfdc);
                SBE_FFDC_TRACD("testWithFFDCParser "
                               "Ffdc package 2 was not successfully parsed. "
                               "FFDC Data:\n%s",
                                strFfdc
                              );

                TS_FAIL("sbeFFDCParserTest testWithFFDCParser: "
                        "Ffdc package 2 was not successfully parsed."
                       );

                result = false;
                break;
             }
         }
         while(0);

         if(result)
         {
            SBE_FFDC_TRACD("sbeFFDCParserTest testWithFFDCParser "
                                                               "test passed!");
         }
         else
         {
            SBE_FFDC_TRACD("sbeFFDCParserTest testWithFFDCParser "
                                                               "test failed!");
         }
     }
};

#endif
