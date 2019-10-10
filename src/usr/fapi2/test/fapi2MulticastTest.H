/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2MulticastTest.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/target.H>

class FapiMulticastTest : public CxxTest::TestSuite
{

public:
void testMulticastSetup()
{
    TARGETING::TargetHandle_t l_proc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle(l_proc);
    assert(l_proc, "testMulticastSetup: master proc handle is nullptr");

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);

    auto l_eq = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_EQ,
                                        fapi2::MULTICAST_BITX>(
                                            fapi2::MCGROUP_GOOD_EQ);
    do {

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

    if(fapi2::getMulticastBit(l_multicastAddr) != 1)
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
    } while(0);
}

void testMulticastWriteOp()
{
    TARGETING::TargetHandle_t l_proc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle(l_proc);
    assert(l_proc, "testMulticastWriteOp: master proc handle is nullptr");

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
    auto l_eq = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_EQ,
                                        fapi2::MULTICAST_OR>(
                                            fapi2::MCGROUP_ALL);
    const uint32_t TEST_SCOM_WRITE_ADDR = 0x20000010; // TPEQP.CPLT_CTRL0
    const uint64_t TEST_DATA = 0x0000000000000001; // Bit 63 set
    uint32_t l_scomAddr = TEST_SCOM_WRITE_ADDR;
    uint64_t l_dataToWrite = 0xF; // So that we know that the data changed

    do {

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
    errlHndl_t l_errl = deviceRead(l_eqTarget,
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
    l_errl = deviceWrite(l_eq.get(),
                         &l_dataToWrite,
                         l_size,
                         DEVICE_SCOM_ADDRESS(l_multicastScom, 0));
    if(l_errl)
    {
        TS_FAIL("testMulticastWriteOp: Could not write back data 0x%.16x "
                "to multicast SCOM 0x%.08x", l_dataToWrite, l_multicastScom);
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
}

void testMulticastWriteOpBadParam()
{
    TARGETING::TargetHandle_t l_proc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle(l_proc);
    assert(l_proc, "testMulticastWriteOpBadParam: master proc hndl is nullptr");

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
    // Intentionally provide an incorrect param (MCGROUP_GOOD_IOHS). In this
    // case, the multicast should not go out to all EQs.
    auto l_eq = l_fapiProc.getMulticast<fapi2::TARGET_TYPE_EQ,
                                        fapi2::MULTICAST_OR>(
                                            fapi2::MCGROUP_GOOD_IOHS);
    const uint32_t TEST_SCOM_WRITE_ADDR = 0x20000010; // TPEQP.CPLT_CTRL0
    const uint64_t TEST_DATA = 0x0000000000000002; // Bit 62 set
    uint32_t l_scomAddr = TEST_SCOM_WRITE_ADDR;
    uint64_t l_dataToWrite = 0xF; // So that we know that the data changed

    do {

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
    errlHndl_t l_errl = deviceRead(l_eqTarget,
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
    l_errl = deviceWrite(l_eq.get(),
                         &l_dataToWrite,
                         l_size,
                         DEVICE_SCOM_ADDRESS(l_multicastScom, 0));
    if(l_errl)
    {
        TS_FAIL("testMulticastWriteOpBadParam: Could not write data 0x%.16x "
                " to multicast SCOM 0x%.08x", l_dataToWrite, l_multicastScom);
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

}; //class FapiMulticastTest
