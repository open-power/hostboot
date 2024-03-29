/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2MulticastTest.H $                     */
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
#include <cxxtest/TestSuite.H>
#include <target.H>
#include <fapi2.H>
#include <assert.h>
#include <diag/attn/common/attntarget.H>
#include <targeting/common/targetservice.H>
#include <multicast_group_defs.H>
#include <multicast_defs.H>
#include <fapi2/plat_hw_access.H>
#include <fapi2/hw_access.H>
#include <fapi2/plat_utils.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/target.H>
#include <scom/scomreasoncodes.H>


class FapiMulticastTest : public CxxTest::TestSuite
{

public:
void testMulticastSetup()
{
    TARGETING::TargetHandle_t l_proc = nullptr;
    errlHndl_t l_errl = nullptr;

    do {

    l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
    if(l_errl)
    {
        TS_FAIL("testMulticastSetup: could not get master proc target");
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);

    auto l_eq = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_EQ,
                                        fapi2::MULTICAST_BITX>(
                                            fapi2::MCGROUP_GOOD_EQ);
    if(!l_eq.get().isMulticast())
    {
        TS_FAIL("testMulticastSetup: The EQ target was expected to be"
                " a multicast target, but it's not.");
        break;
    }

    if(l_eq.get().getMulticastGroup() != fapi2::MCGROUP_GOOD_EQ)
    {
        TS_FAIL("testMulticastSetup: Unexpected multicast group returned."
                " Expected: %d (0x%x), actual: %d (0x%x)",
                fapi2::MCGROUP_GOOD_EQ, fapi2::MCGROUP_GOOD_EQ,
                l_eq.get().getMulticastGroup(), l_eq.get().getMulticastGroup());
        break;
    }

    if(l_eq.get().getMulticastOp() != fapi2::MULTICAST_BITX)
    {
        TS_FAIL("testMulticastSetup: Unexpected multicast operation returned."
                " Expected %d (0x%x), actual %d (0x%x)",
                fapi2::MULTICAST_BITX, fapi2::MULTICAST_BITX,
                l_eq.get().getMulticastOp(), l_eq.get().getMulticastOp());
        break;
    }

    // The internal multicast target is actually the proc target, not the EQ,
    // since the multicast SCOM op will be run against the proc
    if(TARGETING::get_huid(l_eq.get()) != TARGETING::get_huid(l_proc))
    {
        TS_FAIL("testMulticastSetup: Unexpected HUID of the internal multicast "
                "target. Expected HUID: 0x%.08x; Actual HUID: 0x%.08x",
                TARGETING::get_huid(l_proc), TARGETING::get_huid(l_eq.get()));
        break;
    }

    // Now test the address assembly, since we already have a good target
    const uint32_t SCOM_TEST_ADDR = 0x20000010; // TPEQP.CPLT_CTRL0
    uint64_t l_multicastAddr = fapi2::getMulticastAddr(SCOM_TEST_ADDR,
                            l_eq.get().getMulticastGroup(),
                            l_eq.get().getMulticastOp());

    if(l_multicastAddr == SCOM_TEST_ADDR)
    {
        TS_FAIL("testMulticastSetup: The SCOM address didn't change after the "
                "invocation of getMulticastAddr");
        break;
    }

    if(fapi2::isMulticastBitSet(l_multicastAddr) != 1)
    {
        TS_FAIL("testMulticastSetup: The multicast bit is not set in the "
                "resulting multicast address");
        break;
    }

    if(fapi2::getMulticastGroup(l_multicastAddr) !=
        fapi2::getPlatMCGroup(fapi2::MCGROUP_GOOD_EQ))
    {
        TS_FAIL("testMulticastSetup: Incorrect multicast group in the resulting"
                " multicast address. Expected group %d (0x%x),"
                " actual group %d (0x%x)",
                fapi2::getPlatMCGroup(fapi2::MCGROUP_GOOD_EQ),
                fapi2::getPlatMCGroup(fapi2::MCGROUP_GOOD_EQ),
                fapi2::getMulticastGroup(l_multicastAddr),
                fapi2::getMulticastGroup(l_multicastAddr));
        break;
    }

    if(fapi2::getMulticastOp(l_multicastAddr) != fapi2::MULTICAST_BITX)
    {
        TS_FAIL("testMulticastSetup: Incorrect multicast op in the resulting"
                " multicast address. Expected op %d (0x%x), "
                " actual op %d (0x%x).",
                fapi2::MULTICAST_BITX, fapi2::MULTICAST_BITX,
                fapi2::getMulticastOp(l_multicastAddr),
                fapi2::getMulticastOp(l_multicastAddr));
        break;
    }

    // Test multihot (core select)
    l_eq = l_fapiProc.getMulticast<fapi2::MULTICAST_OR>(
                                     fapi2::MCGROUP_GOOD_EQ,
                                     fapi2::MCCORE_0);
    if(l_eq.get().getCoreSelect() != fapi2::MCCORE_0)
    {
        TS_FAIL("testMulticastSetup: Unexpected core select returned. "
                "Expected: %d (0x%x), actual: %d (0x%x)",
                fapi2::MCCORE_0, fapi2::MCCORE_0,
                l_eq.get().getCoreSelect(), l_eq.get().getCoreSelect());
        break;
    }

    l_multicastAddr = fapi2::getMulticastAddr(l_multicastAddr,
                            l_eq.get().getMulticastGroup(),
                            l_eq.get().getMulticastOp(),
                            l_eq.get().getCoreSelect());
    if(fapi2::getCoreSelect(l_multicastAddr) != fapi2::MCCORE_0)
    {
        TS_FAIL("testMulticastSetup: Incorrect core select in the resulting"
                " multicast address. Expected %d (0x%x), actual %d (0x%x)",
                fapi2::MCCORE_0, fapi2::MCCORE_0,
                fapi2::getCoreSelect(l_multicastAddr),
                fapi2::getCoreSelect(l_multicastAddr));
    }
    } while(0);
}

void testMulticastReadOr()
{
    TARGETING::TargetHandle_t l_proc = nullptr;
    errlHndl_t l_errl = nullptr;

    const uint32_t TEST_REG = 0xC000001; // CPLT_CTRL1_RW
    // Bits 1-3 are unused in this reg
    const uint64_t l_testDataArr[] = { 0x4000000000000000,
                                       0x2000000000000000,
                                       0x1000000000000000 };

    const uint64_t BIT_1_SET = 0x4000000000000000;
    const uint64_t BIT_2_SET = 0x2000000000000000;
    const uint64_t BIT_3_SET = 0x1000000000000000;

    do {

    l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
    if(l_errl)
    {
        TS_FAIL("testMulticastReadOr: could not get master proc target");
        break;
    }

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
    auto l_mc = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_MC,
                                        fapi2::MULTICAST_OR>(
                                            fapi2::MCGROUP_ALL);


    if(l_mc.get() == nullptr)
    {
        TS_FAIL("testMulticastReadOr: Internal multicast target is nullptr");
        break;
    }

    TARGETING::TargetHandleList l_mcs;
    getAllChiplets(l_mcs, TARGETING::TYPE_MC, false);

    // Need at least three targets for the test
    if(l_mcs.size() < 3)
    {
        TS_FAIL("testMulticastReadOr requires at least 3 MCs to run correctly");
        break;
    }

    uint64_t l_mcastScomAddr = fapi2::getMulticastAddr(TEST_REG,
                                    l_mc.get().getMulticastGroup(),
                                    l_mc.get().getMulticastOp());
    TS_INFO("testMulticastReadOr: multicast address = 0x%016x", l_mcastScomAddr);

    uint64_t l_testData = 0;
    uint64_t l_origData = 0;
    size_t l_size = sizeof(l_testData);
    fapi2::buffer<uint64_t>l_fapiReadData(l_testData);
    fapi2::ReturnCode l_fapiRc = fapi2::getScom(l_mc, TEST_REG,l_fapiReadData);
    if(l_fapiRc)
    {
        TS_FAIL("testMulticastReadOr: Multicast getScom returned RC: %d",static_cast<uint64_t>(l_fapiRc));
        l_errl = fapi2::rcToErrl(l_fapiRc);
        break;
    }

    l_errl = deviceRead(l_mcs[0],
                        &l_origData,
                        l_size,
                        DEVICE_SCOM_ADDRESS(TEST_REG,0));
    if(l_errl)
    {
        TS_FAIL("testMulticastReadOr: could not read from reg 0x%08x on HUID 0x%08x",
                TEST_REG, TARGETING::get_huid(l_mcs[0]));
        break;
    }

    for(uint8_t i = 0; i < 3; ++i)
    {
        l_testData = l_origData | l_testDataArr[i];
        l_errl = deviceWrite(l_mcs[i],
                             &l_testData,
                             l_size,
                             DEVICE_SCOM_ADDRESS(TEST_REG, 0));
        if(l_errl)
        {
            TS_FAIL("testMulticastReadOr: could not write to reg 0x%08x on HUID 0x%08x",
                    TEST_REG, TARGETING::get_huid(l_mcs[i]));
            break;
        }
    }
    if(l_errl)
    {
        break;
    }

    l_fapiRc = getScom(l_mc, TEST_REG, l_fapiReadData);
    if(l_fapiRc)
    {
        TS_FAIL("testMulticastReadOr: Multicast getScom returned RC: %d",static_cast<uint64_t>(l_fapiRc));
        l_errl = fapi2::rcToErrl(l_fapiRc);
        break;
    }

    if((l_fapiReadData & (BIT_1_SET | BIT_2_SET | BIT_3_SET)) !=
       (BIT_1_SET | BIT_2_SET | BIT_3_SET))
    {
        TS_FAIL("testMulticastReadOr: unexpected multicast read result. Expected: 0x%016lx; actual: 0x%016lx (full reg data: 0x%016lx)",
                BIT_1_SET | BIT_2_SET | BIT_3_SET,
                l_fapiReadData & (BIT_1_SET | BIT_2_SET | BIT_3_SET),
                l_fapiReadData);
        break;
    }

    } while(0);

    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
    }
}

void testMulticastWriteOp()
{
// @TODO: RTC 244854: This is broke for run time testing, enable when can.
#ifndef __HOSTBOOT_RUNTIME
    TARGETING::TargetHandle_t l_proc = nullptr;
    errlHndl_t l_errl = nullptr;

    const uint32_t TEST_SCOM_WRITE_ADDR = 0x20000010; // TPEQP.CPLT_CTRL0
    const uint64_t TEST_DATA = 0x0000000000000001; // Bit 63 set
    uint32_t l_scomAddr = TEST_SCOM_WRITE_ADDR;
    uint64_t l_dataToWrite = 0xF; // So that we know that the data changed

    do {

    l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
    if(l_errl)
    {
        TS_FAIL("testMulticastWriteOp: could not get master proc target");
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
    auto l_eq = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_EQ,
                                        fapi2::MULTICAST_OR>(
                                            fapi2::MCGROUP_ALL);


    TARGETING::TargetHandleList l_eqs;
    getChildAffinityTargets(l_eqs, l_proc,
                            TARGETING::CLASS_UNIT, TARGETING::TYPE_EQ, false);
    TARGETING::Target* l_eqTarget = l_eqs[0];

    if(l_eq.get() == nullptr)
    {
        TS_FAIL("testMulticastWriteOp: Internal multicast target is nullptr");
        break;
    }

    uint64_t l_multicastScom = fapi2::getMulticastAddr(l_scomAddr,
                            l_eq.get().getMulticastGroup(),
                            l_eq.get().getMulticastOp());

    TS_INFO("testMulticastWriteOp:: multicast address = 0x%.08x",
            l_multicastScom);

    size_t l_size = sizeof(l_dataToWrite);
    l_errl = deviceRead(l_eqTarget,
                        &l_dataToWrite,
                        l_size,
                        DEVICE_SCOM_ADDRESS(l_scomAddr, 0));
    if(l_errl)
    {
        TS_FAIL("testMulticastWriteOp: Could not read SCOM 0x%.08x",
                l_scomAddr);
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    l_dataToWrite |= TEST_DATA;

    // Write the modified data to a single SCOM reg
    l_errl = deviceWrite(l_eqTarget,
                         &l_dataToWrite,
                         l_size,
                         DEVICE_SCOM_ADDRESS(l_scomAddr, 0));
    if(l_errl)
    {
        TS_FAIL("testMulticastWriteOp: Could not write data 0x%.16lx "
                "to SCOM address 0x%.08x", l_dataToWrite, l_scomAddr);
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    uint64_t l_readBackData = 0xF;
    bool l_compareError = false;

    for(const auto l_eqTargetX : l_eqs)
    {
        // Read out and compare all other EQs
        if(l_eqTargetX != l_eqTarget)
        {
            l_errl = deviceRead(l_eqTargetX,
                                &l_readBackData,
                                l_size,
                                DEVICE_SCOM_ADDRESS(l_scomAddr, 0));
            if(l_errl)
            {
                TS_FAIL("testMulticastWriteOp: EQ[0x%.08x]: could not read "
                        "SCOM 0x%.08x", TARGETING::get_huid(l_eqTargetX),
                        l_scomAddr);
                break;
            }

            // The data should be different, since we only wrote to a single reg
            // (no multicast)
            if(l_readBackData == l_dataToWrite)
            {
                TS_FAIL("testMulticastWriteOp: EQ[0x%.08x]'s data matches "
                        "that written to EQ[0x%.08x] under non-multicast "
                        "conditions", TARGETING::get_huid(l_eqTargetX),
                        TARGETING::get_huid(l_eqTarget));
                l_compareError = true;
                // Do not break; we potentially may want to know how many EQs
                // miscompare
            }
            else
            {
                TS_INFO("testMulticastWriteOp: Regular write EQ[0x%.08x] is good",
                        TARGETING::get_huid(l_eqTargetX));
            }
        }
    }
    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }
    if(l_compareError)
    {
        break;
    }

    // Now write multicast
    fapi2::ReturnCode l_fapiRc = fapi2::putScom(l_eq,
                                                TEST_SCOM_WRITE_ADDR,
                                                l_dataToWrite);
    if(l_fapiRc)
    {
         TS_FAIL("testMulticastWriteOp: could not write multicast SCOM via"
                 " fapi2 layer to addr 0x%.08x", l_multicastScom);
         l_errl = fapi2::rcToErrl(l_fapiRc);
    }
    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    l_compareError = false;
    // All other registers should have been changed too
    for(const auto l_eqTargetX : l_eqs)
    {
        if(l_eqTargetX != l_eqTarget)
        {
            l_errl = deviceRead(l_eqTargetX,
                                &l_readBackData,
                                l_size,
                                DEVICE_SCOM_ADDRESS(l_scomAddr, 0));
            if(l_errl)
            {
                TS_FAIL("testMulticastWriteOp: EQ[0x%.08x]: could not read "
                        "SCOM 0x%.08x", TARGETING::get_huid(l_eqTargetX),
                        l_scomAddr);
                break;
            }

            if(l_readBackData != l_dataToWrite)
            {
                TS_FAIL("testMulticastWriteOp: EQ[0x%.08x]'s data does not "
                        "match that written to EQ[0x%.08x] under multicast "
                        "conditions", TARGETING::get_huid(l_eqTargetX),
                        TARGETING::get_huid(l_eqTarget));
                l_compareError = true;
                // Do not break; we potentially may want to know how many EQs
                // miscompare
            }
            else
            {
                TS_INFO("testMulticastWriteOp: Multicast write EQ[0x%.08x] is good",
                        TARGETING::get_huid(l_eqTargetX));
            }
        }
    }
    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }
    if(l_compareError)
    {
        break;
    }

    } while(0);
#endif // #ifndef __HOSTBOOT_RUNTIME
}

void testMulticastWriteOpBadParam()
{
    TARGETING::TargetHandle_t l_proc = nullptr;
    errlHndl_t l_errl = nullptr;

    const uint32_t TEST_SCOM_WRITE_ADDR = 0x20000010; // TPEQP.CPLT_CTRL0
    const uint64_t TEST_DATA = 0x0000000000000002; // Bit 62 set
    uint32_t l_scomAddr = TEST_SCOM_WRITE_ADDR;
    uint64_t l_dataToWrite = 0xF; // So that we know that the data changed

    do {

    l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
    if(l_errl)
    {
        TS_FAIL("testMulticastWriteOpBadParam: could not get master proc target");
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
    // Intentionally provide an incorrect param (MCGROUP_GOOD_IOHS). In this
    // case, the multicast should not go out to all EQs.
    auto l_eq = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_EQ,
                                        fapi2::MULTICAST_OR>(
                                            fapi2::MCGROUP_GOOD_IOHS);


    TARGETING::TargetHandleList l_eqs;
    getChildAffinityTargets(l_eqs, l_proc,
                            TARGETING::CLASS_UNIT, TARGETING::TYPE_EQ, false);
    TARGETING::Target* l_eqTarget = l_eqs[0];

    if(l_eq.get() == nullptr)
    {
        TS_FAIL("testMulticastWriteOpBadParam: Internal multicast target is "
                "nullptr");
        break;
    }

    uint64_t l_multicastScom  = fapi2::getMulticastAddr(l_scomAddr,
                                l_eq.get().getMulticastGroup(),
                                l_eq.get().getMulticastOp());
    TS_INFO("testMulticastWriteOpBadParam: multicast address = 0x%.08x",
            l_multicastScom);

    size_t l_size = sizeof(l_dataToWrite);
    l_errl = deviceRead(l_eqTarget,
                        &l_dataToWrite,
                        l_size,
                        DEVICE_SCOM_ADDRESS(l_scomAddr, 0));
    if(l_errl)
    {
        TS_FAIL("testMulticastWriteOpBadParam: Could not read SCOM "
                "0x%.08x", l_scomAddr);
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    l_dataToWrite |= TEST_DATA;

    // Multicast-write the modified data
    fapi2::ReturnCode l_fapiRc = fapi2::putScom(l_eq,
                                                TEST_SCOM_WRITE_ADDR,
                                                l_dataToWrite);
     if(l_fapiRc)
     {
         TS_FAIL("testMulticastWriteOpBadParam: could not write multicast SCOM "
                 "via fapi2 layer to addr 0x%.08x", l_multicastScom);
         l_errl = fapi2::rcToErrl(l_fapiRc);
     }
    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    bool l_compareError = false;
    uint64_t l_readBackData = 0xF;
    // No EQs should have gotten the SCOM request due to a bad param,
    // so all SCOMs should be unchanged
    for(const auto l_eqTargetX : l_eqs)
    {
        l_errl = deviceRead(l_eqTargetX,
                            &l_readBackData,
                            l_size,
                            DEVICE_SCOM_ADDRESS(l_scomAddr, 0));
        if(l_errl)
        {
            TS_FAIL("testMulticastWriteOpBadParam: EQ[0x%.08x]: could not read "
                    "SCOM 0x%.08x", TARGETING::get_huid(l_eqTargetX),
                    l_scomAddr);
            break;
        }

        // None of the EQs should contain the data we tried to multicast-write
        if(l_readBackData == l_dataToWrite)
        {
            TS_FAIL("testMulticastWriteOpBadParam: EQ[0x%.08x] erroneously "
                    "received multicast SCOM write",
                    TARGETING::get_huid(l_eqTargetX));
            l_compareError = true;
            // Do not break here - we potentially want to know how many invalid
            // multicasts went out.
        }
        else
        {
            TS_INFO("testMulticastWriteOpBadParam: EQ[0x%.08x] is good",
                    TARGETING::get_huid(l_eqTargetX));
        }
    }
    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }
    if(l_compareError)
    {
        break;
    }
    }while(0);
}

void testMulticastReadAnd()
{
    TARGETING::TargetHandle_t l_proc = nullptr;
    errlHndl_t l_errl = nullptr;

    const uint32_t TEST_SCOM_WRITE_ADDR = 0xC000001; // CPLT_CTRL1_RW
    const uint64_t TEST_DATA = 0x5000000000000000; // Bit 1, 3 set
    const uint64_t TEST_DATA_1 = 0x2000000000000000; // Bit 2 set

    uint32_t l_scomAddr = TEST_SCOM_WRITE_ADDR;
    uint64_t l_dataToWrite = 0;

    do {

    l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
    if(l_errl)
    {
        TS_FAIL("testMulticastReadAnd: could not get master proc target");
        break;
    }

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
    auto l_mc = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_MC,
                                               fapi2::MULTICAST_AND>(
                                                fapi2::MCGROUP_ALL);


    TARGETING::TargetHandleList l_mcs;
    getAllChiplets(l_mcs, TARGETING::TYPE_MC, false);

    if(l_mc.get() == nullptr)
    {
        TS_FAIL("testMulticastReadAnd: Internal multicast target is nullptr");
        break;
    }

    size_t l_size = sizeof(l_dataToWrite);
    // Write first set of test data to all MCs
    uint64_t l_testData = l_dataToWrite | TEST_DATA;

    // Multicast write the first set of test data so that all of the possible
    // MCs are updated correctly.
    fapi2::buffer<uint64_t>l_fapiBuff(l_testData);
    fapi2::ReturnCode l_fapiRc = fapi2::putScom(l_mc,
                                                TEST_SCOM_WRITE_ADDR,
                                                l_fapiBuff);
    if(l_fapiRc)
    {
        TS_FAIL("testMulticastReadAnd: could not multicast write; FAPI RC: %d",
                static_cast<uint64_t>(l_fapiRc));
        l_errl = fapi2::rcToErrl(l_fapiRc);
        break;
    }

    // Write the second set of test data to MC0
    l_testData = l_testData | TEST_DATA_1;
    l_errl = deviceWrite(l_mcs[0],
                         &l_testData,
                         l_size,
                         DEVICE_SCOM_ADDRESS(l_scomAddr, 0));
    if(l_errl)
    {
        TS_FAIL("testMulticastReadAnd: Could not write test data to MC0 (HUID: 0x%.08x)",
                TARGETING::get_huid(l_mcs[0]));
        break;
    }

    uint64_t l_multicastScom = fapi2::getMulticastAddr(l_scomAddr,
                                l_mc.get().getMulticastGroup(),
                                l_mc.get().getMulticastOp());
    TS_INFO("testMulticastReadAnd: multicast address = 0x%.08x",
            l_multicastScom);

    // Read multicast
    l_fapiRc = fapi2::getScom(l_mc,
                              TEST_SCOM_WRITE_ADDR,
                              l_fapiBuff);
    if(l_fapiRc)
    {
        TS_FAIL("testMulticastReadAnd: could not read multicast SCOM via fapi2 layer from addr 0x%.08x; FAPI RC: %d",
                l_multicastScom, static_cast<uint64_t>(l_fapiRc));
        l_errl = fapi2::rcToErrl(l_fapiRc);
        break;
    }

    TS_INFO("testMulticastReadAnd: multicast read result: 0x%016lx", l_fapiBuff);

    // At this point, MC0 contains the value 7, and all other MCs have the
    // value 5. The AND of those should produce the value of 5.
    if((l_fapiBuff & TEST_DATA) != TEST_DATA)
    {
        TS_FAIL("testMulticastReadAnd: Unexpected multicast AND read data. Expected 0x%.16lx; actual 0x%.16lx (full reg data: 0x%016lx)",
                TEST_DATA, (l_fapiBuff & TEST_DATA), l_fapiBuff);
        break;
    }

    } while(0);

    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
    }
}

void testMulticastCoreSelect()
{
    TARGETING::TargetHandle_t l_proc = nullptr;
    errlHndl_t l_errl = nullptr;

    // MCCORE_0 only
    uint32_t l_coreSelect = 0x8;
    const uint32_t TEST_SCOM_WRITE_ADDR = 0x200E88A0; // QME_QOSR
    const uint64_t TEST_DATA = 0x00000000002A0000;
    const uint64_t BIT_CLEAR_MASK = 0x00000000003F0000;

    uint64_t l_dataToWrite = 0x0;

    do {
    l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
    if(l_errl)
    {
        TS_FAIL("testMulticastCoreSelect: could not get master proc target");
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
    auto l_eq = l_fapiProc.getMulticast<fapi2::MULTICAST_AND>(
                                     fapi2::MCGROUP_ALL,
                                     static_cast<fapi2::MulticastCoreSelect>
                                            (l_coreSelect));


    uint32_t l_multicastScomAddr =fapi2::getMulticastAddr(TEST_SCOM_WRITE_ADDR,
                                                 l_eq.get().getMulticastGroup(),
                                                 l_eq.get().getMulticastOp(),
                                                 l_eq.get().getCoreSelect());
    TS_INFO("testMulticastCoreSelect: multicast address 0x%.08x",
             l_multicastScomAddr);
    size_t l_size = sizeof(l_dataToWrite);

    TARGETING::TargetHandleList l_cores;
    TARGETING::getAllChiplets(l_cores, TARGETING::TYPE_CORE, true);
    assert(l_cores.size() != 0, "testMulticastCoreSelect: "
           "could not find any cores!");
    TARGETING::Target* l_coreTarget = l_cores[0];

    l_errl = deviceRead(l_coreTarget,
                        &l_dataToWrite,
                        l_size,
                        DEVICE_SCOM_ADDRESS(TEST_SCOM_WRITE_ADDR,0));
    if(l_errl)
    {
        TS_FAIL("testMulticastCoreSelect: Could not read SCOM "
                "0x%.08x for target 0x%.08x",
                TEST_SCOM_WRITE_ADDR,
                TARGETING::get_huid(l_coreTarget));
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    l_dataToWrite &= ~(BIT_CLEAR_MASK); // reset test bits
    // Write reset test bits
    for(const auto & l_c : l_cores)
    {
        l_errl = deviceWrite(l_c,
                             &l_dataToWrite,
                             l_size,
                             DEVICE_SCOM_ADDRESS(TEST_SCOM_WRITE_ADDR, 0));
        if(l_errl)
        {
            TS_FAIL("testMulticastCoreSelect: could not reset test data on core"
                    " 0x%x", TARGETING::get_huid(l_c));
            break;
        }
    }
    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    // Set up test data
    l_dataToWrite |= TEST_DATA;
    // Write multicast
    fapi2::ReturnCode l_rc =
        fapi2::putScom(l_eq, TEST_SCOM_WRITE_ADDR, l_dataToWrite);
    if(l_rc)
    {
        TS_FAIL("testMulticastCoreSelect: could not write multicast SCOM via"
                " fapi2 layer to addr 0x%.08x", l_multicastScomAddr);
        l_errl = fapi2::rcToErrl(l_rc);
    }

    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    std::map<TARGETING::Target*, bool>l_coreTestTable = {
        {l_cores[0], true},
        {l_cores[1], false},
        {l_cores[2], false},
        {l_cores[3], false}, };

    // Read core 0 - the data should match the test data
    uint64_t l_readData = 0xFF;

    for(const auto& l_coreTest : l_coreTestTable)
    {
        l_errl = deviceRead(l_coreTest.first,
                            &l_readData,
                            l_size,
                            DEVICE_SCOM_ADDRESS(TEST_SCOM_WRITE_ADDR, 0));
        if(l_errl)
        {
            TS_FAIL("testMulticastCoreSelect: could not read from SCOM "
                    "0x%.08x for target 0x%.08x",
                    TEST_SCOM_WRITE_ADDR,
                    TARGETING::get_huid(l_coreTest.first));
            break;
        }

        if((l_readData == l_dataToWrite) != l_coreTest.second)
        {
            TS_FAIL("testMulticastCoreSelect: unexpected core select data on "
                    "core HUID 0x%.08x. Expected 0x%.16lx; actual 0x%.16x "
                    "(should %s match)",
                    TARGETING::get_huid(l_coreTest.first),
                    l_dataToWrite,
                    l_readData,
                    l_coreTest.second ? "" : "not");
            break;
        }
    }
    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    l_readData = 0xFF;

    // Now do multicast read from the affected registers
    fapi2::buffer<uint64_t>l_fapiBuff(l_readData);
    l_rc = fapi2::getScom(l_eq, TEST_SCOM_WRITE_ADDR, l_fapiBuff);
    if(l_rc)
    {
        TS_FAIL("testMulticastCoreSelect: could not read multicast SCOM via"
                " fapi2 layer from addr 0x%.08x", l_multicastScomAddr);
        l_errl = fapi2::rcToErrl(l_rc);
    }
    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
        break;
    }

    // The multicast read operation is AND, so the data that we read back
    // should match what we wrote if all is well. Multicast will read only
    // the regs on the cores we selected, all of which should have been
    // altered, so the AND of all reads should match the original data.
    if(l_fapiBuff != l_dataToWrite)
    {
        TS_FAIL("testMulticastCoreSelect: unexpected multicast read data. "
                "Expected 0x%.16lx; actual 0x%.16lx", l_dataToWrite,
                l_fapiBuff);
        break;
    }
    } while(0);
}

void testMulticastCompare()
{
// @TODO: RTC 244854: This is broke for run time testing, enable when can.
#ifndef __HOSTBOOT_RUNTIME
    TARGETING::TargetHandle_t l_proc = nullptr;
    errlHndl_t l_errl = nullptr;
    const uint32_t TEST_SCOM_WRITE_ADDR = 0xC000001; // CPLT_CTRL1_RW
    const uint64_t TEST_DATA = 0x7000000000000000; // Bits 1-3 set

    do {
    l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(l_proc);
    if(l_errl)
    {
        TS_FAIL("testMulticastCompare: could not get master proc target");
        break;
    }

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
    auto l_mc = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_MC,
                                        fapi2::MULTICAST_COMPARE >(
                                                fapi2::MCGROUP_ALL);

    TARGETING::TargetHandleList l_mcs;
    getAllChiplets(l_mcs, TARGETING::TYPE_MC, false);

    uint64_t l_dataToWrite = 0xFF;
    size_t l_size = sizeof(l_dataToWrite);

    auto l_mc0 = l_mcs[0];
    l_errl = deviceRead(l_mc0,
                        &l_dataToWrite,
                        l_size,
                        DEVICE_SCOM_ADDRESS(TEST_SCOM_WRITE_ADDR,0));
    if(l_errl)
    {
        TS_FAIL("testMulticastCompare: Could not read SCOM 0x%.08x",
                TEST_SCOM_WRITE_ADDR);
        break;
    }

    // Reset test bits
    l_dataToWrite &= ~(TEST_DATA);

    for(const auto& l_mc : l_mcs)
    {
        l_errl = deviceWrite(l_mc,
                             &l_dataToWrite,
                             l_size,
                             DEVICE_SCOM_ADDRESS(TEST_SCOM_WRITE_ADDR,0));
        if(l_errl)
        {
            TS_FAIL("testMulticastCompare: could not write to SCOM 0x%.08x "
                    "for MC HUID 0x%.08x", TEST_SCOM_WRITE_ADDR,
                    TARGETING::get_huid(l_mc));
            break;
        }
    }
    if(l_errl)
    {
        break;
    }

    l_dataToWrite |= TEST_DATA;

    // Write the test data to only the first MC to trigger the compare error
    l_errl = deviceWrite(l_mc0,
                         &l_dataToWrite,
                         l_size,
                         DEVICE_SCOM_ADDRESS(TEST_SCOM_WRITE_ADDR, 0));
    if(l_errl)
    {
        TS_FAIL("testMulticastCompare: could not write test data to SCOM "
                "0x%.08x", TEST_SCOM_WRITE_ADDR);
        break;
    }
    uint32_t l_multicastScomAddr = fapi2::getMulticastAddr(TEST_SCOM_WRITE_ADDR,
                                                 l_mc.get().getMulticastGroup(),
                                                 l_mc.get().getMulticastOp());

    uint64_t l_multicastReadData = 0xFF;
    fapi2::buffer<uint64_t>l_fapiBuff(l_multicastReadData);
    fapi2::ReturnCode l_fapiRc = fapi2::FAPI2_RC_SUCCESS;
    // Read compare - this should trigger an error.
    // Hostboot-style of SCOM here because we want to look at the HB error
    // log produced.
    l_errl = deviceRead(l_mc.get(),
                        &l_multicastReadData,
                        l_size,
                        DEVICE_SCOM_ADDRESS(l_multicastScomAddr, 0));
    if(!l_errl)
    {
        TS_FAIL("testMulticastCompare: expected a multicast compare error but "
                "didn't get one");
        break;
    }
    else
    {
        if(!l_errl->hasErrorType(SCOM::SCOM_MULTICAST_MISCOMPARE))
        {
            TS_FAIL("testMulticastCompare: incorrect RC returned for multicast"
                    " miscompare. Expected 0x%x; actual 0x%x",
                    SCOM::SCOM_MULTICAST_MISCOMPARE,
                    l_errl->reasonCode());
            break;
        }
        else
        {
            // The error is expected, so no need to keep it
            delete l_errl;
            l_errl = nullptr;
        }
    }

    // Now read FAPI-style to check HB to FAPI RC conversion
    l_fapiRc = fapi2::getScom(l_mc,
                              TEST_SCOM_WRITE_ADDR,
                              l_fapiBuff);
    if(!l_fapiRc)
    {
        TS_FAIL("testMulticastCompare: expected a FAPI multicast compare error"
                " but didn't get one");
        break;
    }
    else
    {
        if(l_fapiRc != fapi2::FAPI2_RC_PLAT_MISCOMPARE)
        {
            TS_FAIL("testMulticastCompare: incorrect RC returned for FAPI "
                    "multicsat miscompare. Expected 0x%x; actual 0x%x",
                    fapi2::FAPI2_RC_PLAT_MISCOMPARE,
                    static_cast<uint64_t>(l_fapiRc));
            l_errl = fapi2::rcToErrl(l_fapiRc);
            break;
        }
        else
        {
            l_errl = fapi2::rcToErrl(l_fapiRc);
            if(!l_errl)
            {
                TS_FAIL("testMulticastCompare: no HB errl is created for FAPI"
                        " multicast miscompare RC");
                break;
            }
            else
            {
                if(!l_errl->hasErrorType(SCOM::SCOM_MULTICAST_MISCOMPARE))
                {
                    TS_FAIL("testMulticastCompare: incorrect HB errl rc for "
                            "FAPI multicast miscompare.");
                    break;
                }
                delete l_errl;
                l_errl = nullptr;
            }
        }
    }

    // Now write multicast to all MCs
    l_fapiRc = fapi2::putScom(l_mc,
                              TEST_SCOM_WRITE_ADDR,
                              l_dataToWrite);
    if(l_fapiRc)
    {
        TS_FAIL("testMulticastCompare: could not write multicast SCOM via"
                " fapi2 layer to addr 0x%.08x", l_multicastScomAddr);
        l_errl = fapi2::rcToErrl(l_fapiRc);
    }
    if(l_errl)
    {
        break;
    }

    // Now read compare - it should work fine
    l_fapiRc = fapi2::getScom(l_mc,
                              TEST_SCOM_WRITE_ADDR,
                              l_fapiBuff);
    if(l_fapiRc)
    {
        TS_FAIL("testMulticastCompare: could not read multicast SCOM via"
                " fapi2 layer from addr 0x%.08x", l_multicastScomAddr);
        l_errl = fapi2::rcToErrl(l_fapiRc);
    }
    if(l_errl)
    {
        break;
    }

    // The read data should be the same across all reads
    if(l_fapiBuff != l_dataToWrite)
    {
        TS_FAIL("testMulticastCompare: unexpected data returned from multicast "
                "read. Expected: 0x%.16lx; actual 0x%.16lx", l_dataToWrite,
                l_multicastReadData);
        break;
    }

    } while(0);

    if(l_errl)
    {
        errlCommit(l_errl, CXXTEST_COMP_ID);
    }
#endif // #ifndef __HOSTBOOT_RUNTIME
}

}; //class FapiMulticastTest
