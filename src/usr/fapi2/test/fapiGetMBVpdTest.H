/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapiGetMBVpdTest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#ifndef __FAPI2_FAPI_GET_MB_VPD_TEST_H
#define __FAPI2_FAPI_GET_MB_VPD_TEST_H

#include <cxxtest/TestSuite.H>
#include <attribute_service.H>

#include <targeting/common/attributes.H>
#include <fapi2/target.H>
#include <target_types.H>

#include <fapi2.H>

// use TRACE_MB_VPD_ATTR_UNIT_TEST=1 make -j32
// to enable tracing of unit test
#ifdef TRACE_MB_VPD_ATTR_UNIT_TEST
#define PRINT_VPD_INFO(str) \
    FAPI_INF("%s", str)
#define __TRACE_USE_ONLY__
#define FAPI_TEST_TRACE(fmt, args...)\
    FAPI_INF("Fapi2GetMBVpdTest::" fmt, ##args)
#else
#define __TRACE_USE_ONLY__ __attribute__((unused))
#define PRINT_VPD_INFO(str)
#define FAPI_TEST_TRACE(fmt, args...)
#endif

#define TEST_GET_ATTR(ID, TARGET) \
if(rc)\
{\
    break;\
}\
do{\
    FAPI_TEST_TRACE("TEST_GET_ATTR: Start Get Test For %s", #ID);\
    ID##_Type buffer; \
    clear_buffer(buffer); \
    rc = FAPI_ATTR_GET(ID, TARGET, buffer);\
    if(rc) \
    {\
        FAPI_TEST_TRACE("TEST_GET_ATTR: Failed to read %s", #ID);\
        TS_FAIL("Fapi2GetMBVpdTest: Get Test Failed For Attribute %s", #ID); \
    }\
    else \
    {\
        dump_buffer(buffer, strbuffer, #ID); \
        PRINT_VPD_INFO(strbuffer); \
    }\
}while(0)


//----------------------------------------------------------------------
class Fapi2GetMBVpdTest:public CxxTest::TestSuite
{
public:

    //------------------------------------------------------------------
    fapi2::ReturnCode hw_proc_for_test()
    {
        fapi2::ReturnCode rc{0};

        do
        {
            // @todo RTC 178802 Enable test cases turned off during bring up
            /*
            char strbuffer[2048] = {0};

            //getMBAttr attribute function.
            TEST_GET_ATTR(ATTR_CEN_VPD_TSYS_ADR, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_TSYS_DP18, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRAM_RON, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRAM_RTT_NOM, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRAM_RTT_WR, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_ODT_RD, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_ODT_WR, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DIMM_RCD_IBT, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_RD_VREF, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRAM_WR_VREF, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRAM_WRDDR4_VREF, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_RCV_IMP_DQ_DQS, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRV_IMP_DQ_DQS, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRV_IMP_CNTL, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRV_IMP_ADDR, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRV_IMP_CLK, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRV_IMP_SPCKE, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_SLEW_RATE_DQ_DQS, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_SLEW_RATE_CNTL, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_SLEW_RATE_ADDR, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_SLEW_RATE_CLK, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_SLEW_RATE_SPCKE, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_CKE_PRI_MAP, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_CKE_PWR_MAP, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_RLO, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_WLO, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_GPO, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_PAR, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M_ACTN, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_DRAM_RTT_PARK, iv_targ_mba);
            TEST_GET_ATTR(ATTR_CEN_VPD_RD_CTR_WINDAGE_OFFSET, iv_targ_mba);

            TEST_GET_ATTR(ATTR_CEN_VPD_MR_VERSION_BYTE, iv_targ_membuf);
            TEST_GET_ATTR(ATTR_CEN_VPD_MR_DATA_CONTROL_BYTE, iv_targ_membuf);
            TEST_GET_ATTR(ATTR_CEN_VPD_MT_VERSION_BYTE, iv_targ_membuf);
            TEST_GET_ATTR(ATTR_CEN_VPD_MT_DATA_CONTROL_BYTE, iv_targ_membuf);

            //getControlCapableData attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_POWER_CONTROL_CAPABLE,
                            iv_targ_membuf);

            //getDQAttrISDIMM attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_ISDIMMTOC4DQ, iv_targ_membuf);

            //getDQSAttrISDIMM attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_ISDIMMTOC4DQS, iv_targ_membuf);

            //getMBvpdMemoryDataVersion attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_VM_KEYWORD, iv_targ_membuf);

            //getMBvpdSPDXRecordVersion attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_VD_KEYWORD, iv_targ_membuf);

            //getMBvpdVoltageSettingData attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_DW_KEYWORD, iv_targ_membuf);

            //getMBvpdDram2NModeEnabled attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED, iv_targ_mba);

            //getMBvpdSpareDramData attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_DIMM_SPARE, iv_targ_mba);

            //getMBvpdVersion attribute function
            TEST_GET_ATTR(ATTR_CEN_VPD_VERSION, iv_targ_dimm);
            */
        }
        while(0);

        return rc;
    }

    //-----------------------------------------------------------------
    void test_mb_vpd_attr()
    {
        errlHndl_t l_errl{};

        do
        {
            if(not getTargets())
            {
                FAPI_INF("test_mb_vpd_attr: Skipping test, unable to populate "
                        "targets. Assuming no memory buffers present.");
                break;
            }

            //Tests placed in hardware proccedure for synchronization
            FAPI_INVOKE_HWP(l_errl, hw_proc_for_test);
        }
        while(0);

        if(not l_errl)
        {
            FAPI_INF("test_mb_vpd_attr: Exit Test Passed!");
        }
        else
        {
            delete l_errl;
            FAPI_INF("test_mb_vpd_attr: Exit Test Failed!");
        }
    }

private:

    fapi2::Target<TARGET_TYPE_DIMM> iv_targ_dimm;
    fapi2::Target<TARGET_TYPE_MBA> iv_targ_mba;
    fapi2::Target<TARGET_TYPE_MEMBUF_CHIP> iv_targ_membuf;

    //----------------------------------------------------
    bool getTargets()
    {
        bool l_retval{false};

        do
        {
            TARGETING::TargetHandleList l_membufTargetList;
            TARGETING::getAllChips(l_membufTargetList,
                                      TARGETING::TYPE_MEMBUF);

            if(l_membufTargetList.empty())
            {
                FAPI_TEST_TRACE("getTargets: did not find any "
                                                        "membuf targets.");
                return l_retval;
            }

            for(TARGETING::Target* l_membufTarget: l_membufTargetList)
            {
                TARGETING::TargetHandleList l_mbaTargetList;
                TARGETING::getChildChiplets(l_mbaTargetList,
                                            l_membufTarget,
                                            TARGETING::TYPE_MBA
                                           );

                for(TARGETING::Target* l_mbaTarget: l_mbaTargetList)
                {
                    TARGETING::Target* l_dimmTarget{};
                    TARGETING::TargetHandleList l_dimmList;

                    TARGETING::getChildAffinityTargets(
                                                 l_dimmList,
                                                 l_mbaTarget,
                                                 TARGETING::CLASS_LOGICAL_CARD,
                                                 TARGETING::TYPE_DIMM,
                                                 false
                                                      );

                    for(TARGETING::Target* l_currentDimm: l_dimmList)
                    {
                        if(nullptr != l_currentDimm)
                        {
                            FAPI_TEST_TRACE("getTargets: Found a DIMM target "
                                            "for the parent mba target.");

                            l_dimmTarget = l_currentDimm;
                            break;
                        }
                    }

                    if(nullptr == l_dimmTarget)
                    {
                        FAPI_TEST_TRACE("getTargets: Failed to find a "
                                        "DIMM child target from an MBA target"
                                       );
                        continue;
                    }

                    iv_targ_mba =
                    fapi2::Target<fapi2::TARGET_TYPE_MBA>(l_mbaTarget);

                    iv_targ_membuf =
                    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>
                                                            (l_membufTarget);

                    iv_targ_dimm =
                    fapi2::Target<fapi2::TARGET_TYPE_DIMM>(l_dimmTarget);

                    __TRACE_USE_ONLY__ TARGETING::ATTR_HUID_type l_huid = 0;

                    l_huid = l_membufTarget->getAttr<TARGETING::ATTR_HUID>();
                    FAPI_TEST_TRACE("getTargets: membuf huid: 0x%0X", l_huid);

                    l_huid = l_mbaTarget->getAttr<TARGETING::ATTR_HUID>();
                    FAPI_TEST_TRACE("getTargets: mba huid: 0x%0X", l_huid);

                    l_huid = l_dimmTarget->getAttr<TARGETING::ATTR_HUID>();
                    FAPI_TEST_TRACE("getTargets: dimm huid: 0x%0X", l_huid);

                    l_retval = true;

                    break;
                }

                if(l_retval)
                {
                    break;
                }
            }
        }
        while(0);

        return l_retval;
    }

    //-------------------------------------------------------------------------
    template<typename T>
    bool dump_buffer_element(const T& i_arr,
                             char*& io_ptr,
                             size_t& io_remaining,
                             size_t i_element_1)
    {
        bool l_retval{false};

        do
        {
            int l_result = snprintf(io_ptr, io_remaining,
                                     "\t[%llu]=0x%llX (%llu)\n",
                                     i_element_1,
                                     i_arr[i_element_1],
                                     i_arr[i_element_1]
                                     );

            if(l_result >= 0 && static_cast<size_t>(l_result) <= io_remaining)
            {
                io_remaining -= static_cast<size_t>(l_result);
                io_ptr += static_cast<size_t>(l_result);
                l_retval = true;
            }
        }
        while(0);

        return l_retval;
    }

    //------------------------------------------------------------------------
    template<typename T>
    bool dump_buffer_element(const T& i_arr,
                             char*& io_ptr,
                             size_t& io_remaining,
                             size_t i_element_1,
                             size_t i_element_2)
    {
        bool l_retval{false};

        do
        {
            int l_result = snprintf(io_ptr, io_remaining,
                                 "\t[%llu][%llu]=0x%llX (%llu)\n",
                                 i_element_1,
                                 i_element_2,
                                 i_arr[i_element_1][i_element_2],
                                 i_arr[i_element_1][i_element_2]
                                 );

            if(l_result >= 0 && static_cast<size_t>(l_result) <= io_remaining)
            {
                io_remaining -= static_cast<size_t>(l_result);
                io_ptr += static_cast<size_t>(l_result);
                l_retval = true;
            }
        }
        while(0);

        return l_retval;
    }

    //-------------------------------------------------------------------------
    template<typename T>
    bool dump_buffer_element(const T& i_arr,
                             char*& io_ptr,
                             size_t& io_remaining,
                             size_t i_element_1,
                             size_t i_element_2,
                             size_t i_element_3)
    {
        bool l_retval{false};

        do
        {
            if(nullptr == io_ptr)
            {
                break;
            }

            int l_result = snprintf(io_ptr, io_remaining,
                                 "\t[%llu][%llu][%llu]=0x%llX (%llu)\n",
                                 i_element_1,
                                 i_element_2,
                                 i_element_3,
                                 i_arr[i_element_1][i_element_2][i_element_3],
                                 i_arr[i_element_1][i_element_2][i_element_3]);

            if(l_result >= 0 && static_cast<size_t>(l_result) <= io_remaining)
            {
                io_remaining -= static_cast<size_t>(l_result);
                io_ptr += static_cast<size_t>(l_result);
                l_retval = true;
            }
        }
        while(0);

        return l_retval;
    }

    //-------------------------------------------------------------------------
    bool dump_prefix(const char* i_prefix,
                     char*& io_ptr,
                     size_t& io_remaining)
    {
        bool l_retval{false};

        do
        {
            int l_result = snprintf(io_ptr, io_remaining, "%s\n", i_prefix);
            if(l_result >= 0 && static_cast<size_t>(l_result) <= io_remaining)
            {
                io_remaining -= static_cast<size_t>(l_result);
                io_ptr += static_cast<size_t>(l_result);
                l_retval = true;
            }
        }
        while(0);

        return l_retval;
    }

    //-------------------------------------------------------------------------
    template<typename T, size_t N>
    void dump_buffer(const T& i_arr,
                     char (&i_strbuffer)[N],
                     const char* i_prefix)
    {
        memset(i_strbuffer, 0, N);
        char* l_ptr = i_strbuffer;
        bool l_bResult{false};

        do
        {
            size_t l_remaining{(N - 1)};

            if(i_prefix)
            {
                l_bResult = dump_prefix(i_prefix ,l_ptr, l_remaining);
                if(not l_bResult)
                {
                   break;
                }
            }

            snprintf(l_ptr, l_remaining, "\tval=0x%llX\n", i_arr);
        }
        while(0);
    }

    //-------------------------------------------------------------------------
    template<typename T>
    void clear_buffer(T& i_arr)
    {
        memset(&i_arr, 0, sizeof(T));
    }

    //-------------------------------------------------------------------------
    template<typename T, size_t I, size_t N>
    void dump_buffer(const T (&i_arr)[I],
                     char (&i_strbuffer)[N],
                     const char* i_prefix)
    {
        memset(i_strbuffer, 0, N);
        char* l_ptr = i_strbuffer;
        bool l_bResult{false};

        do
        {
            size_t l_remaining{(N - 1)};

            if(i_prefix)
            {
                l_bResult = dump_prefix(i_prefix , l_ptr, l_remaining);
                if(not l_bResult)
                {
                   break;
                }
            }

            for(size_t i=0; i<I; ++i)
            {
                l_bResult = dump_buffer_element(i_arr, l_ptr, l_remaining, i);
                if(not l_bResult)
                {
                    break;
                }
            }
        }
        while(0);
    }

    //----------------------------------------------------------------------
    template<typename T, size_t I, size_t J, size_t N>
    void dump_buffer(const T (&i_arr)[I][J],
                    char (&i_strbuffer)[N],
                    const char* i_prefix)
    {
        memset(i_strbuffer, 0, N);
        char* l_ptr = i_strbuffer;

        bool l_bResult{true};

        do
        {
            size_t l_remaining{(N - 1)};

            if(i_prefix)
            {
                l_bResult = dump_prefix(i_prefix , l_ptr, l_remaining);
                if(not l_bResult)
                {
                   break;
                }
            }

            for(size_t i=0; i<I; ++i)
            {
                for(size_t j=0; j<J; ++j)
                {
                    l_bResult = dump_buffer_element(i_arr,
                                                    l_ptr,
                                                    l_remaining,
                                                    i,
                                                    j);
                    if(not l_bResult)
                    {
                       break;
                    }
                }

                if(not l_bResult)
                {
                    break;
                }
            }

        }
        while(0);
    }

    //-------------------------------------------------------------------------
    template<typename T,  size_t I, size_t J, size_t K, size_t N>
    void dump_buffer(const T (&i_arr)[I][J][K],
                     char (&i_strbuffer)[N],
                     const char* i_prefix)
    {
        memset(i_strbuffer, 0, N);
        char* l_ptr = i_strbuffer;

        bool l_bResult{true};

        do
        {
            size_t l_remaining{(N - 1)};

            if(i_prefix)
            {
                l_bResult = dump_prefix(i_prefix, l_ptr, l_remaining);
                if(not l_bResult)
                {
                   break;
                }
            }

            for(size_t i=0; i<I; ++i)
            {
                for(size_t j=0; j<J; ++j)
                {
                    for(size_t k=0; k<K; ++k)
                    {
                        l_bResult = dump_buffer_element(i_arr,
                                                        l_ptr,
                                                        l_remaining,
                                                        i,
                                                        j,
                                                        k);
                        if(not l_bResult)
                        {
                           break;
                        }
                    }

                    if(not l_bResult)
                    {
                        break;
                    }
                }

                if(not l_bResult)
                {
                    break;
                }
            }
        }
        while(0);
    }

};

#endif
