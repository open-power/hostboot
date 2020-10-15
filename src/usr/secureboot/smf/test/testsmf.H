/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/smf/test/testsmf.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#ifndef __TEST_SMF_H
#define __TEST_SMF_H

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <hbotcompid.H>
#include <secureboot/smf.H>
#include <secureboot/secure_reasoncodes.H>
#include <errl/hberrltypes.H>
#include <vfs/vfs.H>

const uint64_t DISTRIBUTE_EXACT_SMF_AMT = 1 * GIGABYTE;
const uint64_t DISTRIBUTE_NON_EXACT_SMF_AMT = 800 * MEGABYTE;

class SmfMemDistributionSuite : public CxxTest::TestSuite
{
private:
    bool cv_isSmfLoaded;
    /**
     * @brief Helper function to set master proc's ATTR_PROC_SMF_BAR_SIZE
     *        to the desired size passed in as an argument.
     * @param[in] i_desiredMemSize the desired size of ATTR_PROC_SMF_BAR_SIZE
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t setSmfMemSize(const uint64_t i_desiredMemSize) const
    {
        errlHndl_t l_errl = nullptr;

        do{

        TARGETING::Target* l_masterProc = nullptr;
        l_errl = TARGETING::targetService()
                                 .queryMasterProcChipTargetHandle(l_masterProc);
        if(l_errl)
        {
            break;
        }

        l_masterProc->
                   setAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>(i_desiredMemSize);

        }while(0);
        return l_errl;
    }

    /**
     * @brief Helper function to fetch the ATTR_PROC_SMF_BAR_SIZE attr from
     *        the master proc.
     * @param[out] o_size the size of ATTR_PROC_SMF_BAR_SIZE on master proc
     * @return nullptr on success; non-nullptr on error
     */
    errlHndl_t getSmfMemSize(uint64_t& o_size) const
    {
        errlHndl_t l_errl = nullptr;

        do {

        TARGETING::Target* l_masterProc = nullptr;
        l_errl = TARGETING::targetService()
                                 .queryMasterProcChipTargetHandle(l_masterProc);
        if(l_errl)
        {
            break;
        }

        o_size = l_masterProc->
                             getAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>();

        } while(0);
        return l_errl;
    }

    // Exception: An input of 1 will result in output of 1
    uint64_t getHighestPwrTwoLessThan(const uint64_t i_val) const
    {
        uint64_t l_result = 1;

        if(i_val)
        {
            for(; (l_result << 1) < i_val; l_result <<= 1);
        }
        else
        {
            l_result = 0;
        }

        return l_result;
    }

public:
    SmfMemDistributionSuite() : cv_isSmfLoaded(false)
    {
        errlHndl_t l_errl = nullptr;
        l_errl = VFS::module_load("libsmf.so");
        if(l_errl)
        {
            TS_FAIL("SmfMemDistributionSuite(): could not load libsmf.so");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            cv_isSmfLoaded = false;
        }
        else
        {
            cv_isSmfLoaded = true;
        }
    }

    ~SmfMemDistributionSuite()
    {
        if(cv_isSmfLoaded)
        {
            errlHndl_t l_errl = nullptr;
            l_errl = VFS::module_unload("libsmf.so");
            if(l_errl)
            {
                TS_FAIL("~SmfMemDistributionSuite(): could not unload libsmf.so");
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }
    }

    void testDistributeZeroMem() const
    {
        TS_INFO(ENTER_MRK"testDistributeZeroMem");
        errlHndl_t l_errl = nullptr;
        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        // Set up SMF on the system target for this test.
        // We expect SMF to be turned off when the function runs.
        TARGETING::Target* l_sys = nullptr;

        TARGETING::targetService().getTopLevelTarget(l_sys);
        assert(l_sys != nullptr, "The top level target is nullptr!");
        l_sys->setAttr<TARGETING::ATTR_SMF_CONFIG>(true);

        // Set SMF mem size to be something other than 0
        l_errl = setSmfMemSize(0x1);
        if(l_errl)
        {
            TS_FAIL("testDistributeZeroMem: could not setSmfMemSize");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        l_errl = SECUREBOOT::SMF::distributeSmfMem(0);
        if(l_errl)
        {
            TS_FAIL("testDistributeZeroMem: distributeSmfMem returned an errl. Errl plid = 0x%x", l_errl->plid());
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

        if(l_sys->getAttr<TARGETING::ATTR_SMF_CONFIG>())
        {
            // SMF should have been turned OFF with 0 mem request
            TS_FAIL("testDistributeZeroMem: SMF should have been disabled on 0 SMF mem request");
        }

        uint64_t l_resultingSmfSize = 0;
        l_errl = getSmfMemSize(l_resultingSmfSize);
        if(l_errl)
        {
            TS_FAIL("testDistributeZeroMem: could not getSmfMemSize");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        if(l_resultingSmfSize != 0)
        {
            TS_FAIL("testDistributeZeroMem: Request to distribute zero SMF memory resulted in non-zero SMF_BAR_SIZE under master proc");
        }
        } while(0);

        TS_INFO(EXIT_MRK"testDistributeZeroMem");
    }

    void testDistributeSmallMemAmt() const
    {
        TS_INFO(INFO_MRK"testDistributeSmallMemAmt");
        errlHndl_t l_errl = nullptr;

        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        l_errl = SECUREBOOT::SMF::distributeSmfMem(0x1);
        if(!l_errl)
        {
            TS_FAIL("testDistributeSmallMemAmt: distributeSmfMem should have returned an error log.");
        }
        else
        {
            if(l_errl->reasonCode() != SECUREBOOT::RC_ALLOCATED_NE_REQUESTED)
            {
                TS_FAIL("testDistributeSmallMemAmt: Incorrect RC returned. Expected 0x%x, actual 0x%x", SECUREBOOT::RC_ALLOCATED_NE_REQUESTED, l_errl->reasonCode());

               if(l_errl->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL)
                {
                    TS_FAIL("testDistributeSmallMemAmt: Incorrect error log severity. Expected 0x%x, actual 0x%x", ERRORLOG::ERRL_SEV_INFORMATIONAL, l_errl->sev());
                }
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
            delete l_errl;
            l_errl = nullptr;
        }

        uint64_t l_smfBarSize = 0;
        l_errl = getSmfMemSize(l_smfBarSize);
        if(l_errl)
        {
            TS_FAIL("testDistributeSmallMemAmt: could not getSmfMemSize");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        if(l_smfBarSize != SECUREBOOT::SMF::MIN_SMF_MEMORY_AMT)
        {
            TS_FAIL("testDistributeSmallMemAmt: Unexpected amount of memory allocated. Expected: 0x%x, actual: 0x%x", SECUREBOOT::SMF::MIN_SMF_MEMORY_AMT, l_smfBarSize);
        }
        } while(0);

        TS_INFO(EXIT_MRK"testDistributeSmallMemAmt");
    }

    void testDistributeLargeMemAmt() const
    {
        TS_INFO(ENTER_MRK"testDistributeLargeMemAmt");
        errlHndl_t l_errl = nullptr;

        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        // Try to distribute very large amt of mem
        l_errl = SECUREBOOT::SMF::distributeSmfMem(1000000*GIGABYTE);
        if(!l_errl)
        {
            TS_FAIL("testDistributeLargeMemAmt: distributeSmfMem should have returned an error log.");
        }
        else
        {
            if(l_errl->reasonCode() != SECUREBOOT::RC_ALLOCATED_NE_REQUESTED)
            {
                TS_FAIL("testDistributeLargeMemAmt: Incorrect RC returned. Expected 0x%x, actual 0x%x", SECUREBOOT::RC_ALLOCATED_NE_REQUESTED, l_errl->reasonCode());

                if(l_errl->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL)
                {
                    TS_FAIL("testDistributeLargeMemAmt: Incorrect error log severity. Expected 0x%x, actual 0x%x", ERRORLOG::ERRL_SEV_INFORMATIONAL, l_errl->sev());
                }

                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
            delete l_errl;
            l_errl = nullptr;
        }

        uint64_t l_smfBarSize = 0;
        l_errl = getSmfMemSize(l_smfBarSize);
        if(l_errl)
        {
            TS_FAIL("testDistributeLargeMemAmt: could not getSmfMemSize");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        TARGETING::Target* l_masterProc = nullptr;
        l_errl = TARGETING::targetService()
                                 .queryMasterProcChipTargetHandle(l_masterProc);
        if(l_errl)
        {
            TS_FAIL("testDistributeLargeMemAmt: could not get master proc!");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        uint64_t l_expectedMemAmt = getHighestPwrTwoLessThan(
                            SECUREBOOT::SMF::getTotalProcMemSize(l_masterProc) -
                            SECUREBOOT::SMF::MIN_MEM_RESERVED_FOR_HB);

        if(l_smfBarSize != l_expectedMemAmt)
        {
            TS_FAIL("testDistributeLargeMemAmt: Unexpected amount of memory allocated. Expected: 0x%x, actual: 0x%x", l_expectedMemAmt, l_smfBarSize);
        }
        } while(0);

        TS_INFO(EXIT_MRK"testDistributeLargeMemAmt");
    }

    void testDistributeExactAmt() const
    {
        TS_INFO(ENTER_MRK"testDistributeExactAmt");
        errlHndl_t l_errl = nullptr;

        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        // This amount should be distributed exactly
        l_errl = SECUREBOOT::SMF::distributeSmfMem(DISTRIBUTE_EXACT_SMF_AMT);
        if(l_errl)
        {
            TS_FAIL("testDistributeExactAmt: Unexpected error log returned from distributeSmfMem. Plid = 0x%x", l_errl->plid());
            errlCommit(l_errl, CXXTEST_COMP_ID);
        }

        uint64_t l_smfBarSize = 0;
        l_errl = getSmfMemSize(l_smfBarSize);
        if(l_errl)
        {
            TS_FAIL("testDistributeExactAmt: could not getSmfMemSize");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        if(l_smfBarSize != (DISTRIBUTE_EXACT_SMF_AMT))
        {
            TS_FAIL("testDistributeExactAmt: Unexpected amount of memory allocated. Expected: 0x%x, actual 0x%x", DISTRIBUTE_EXACT_SMF_AMT, l_smfBarSize);
        }
        } while(0);

        TS_INFO(EXIT_MRK"testDistributeExactAmt");
    }

    void testDistributeNotExactAmt()
    {
        TS_INFO(ENTER_MRK"testDistributeNotExactAmt");
        errlHndl_t l_errl = nullptr;

        do {
        if(!cv_isSmfLoaded)
        {
            break;
        }

        // Distribute the amount that cannot be fit exactly.
        // 800MB will be adjusted up to 1GB because of the power-of-two
        // hardware constraints.
        l_errl =
                SECUREBOOT::SMF::distributeSmfMem(DISTRIBUTE_NON_EXACT_SMF_AMT);
        if(!l_errl)
        {
            TS_FAIL("testDistributeNotExactAmt: distributeSmfMem should have returned an error log.");
        }
        else
        {
            if(l_errl->reasonCode() != SECUREBOOT::RC_ALLOCATED_NE_REQUESTED)
            {
                TS_FAIL("testDistributeNotExactAmt: Incorrect RC returned. Expected 0x%x, actual 0x%x", SECUREBOOT::RC_ALLOCATED_NE_REQUESTED, l_errl->reasonCode());

                if(l_errl->sev() != ERRORLOG::ERRL_SEV_INFORMATIONAL)
                {
                    TS_FAIL("testDistributeNotExactAmt: Incorrect error log severity. Expected 0x%x, actual 0x%x", ERRORLOG::ERRL_SEV_INFORMATIONAL, l_errl->sev());
                }
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
            delete l_errl;
            l_errl = nullptr;
        }

        uint64_t l_smfBarSize = 0;
        l_errl = getSmfMemSize(l_smfBarSize);
        if(l_errl)
        {
            TS_FAIL("testDistributeNotExactAmt: could not getSmfMemSize");
            errlCommit(l_errl, CXXTEST_COMP_ID);
            break;
        }

        if(l_smfBarSize != (DISTRIBUTE_EXACT_SMF_AMT))
        {
            TS_FAIL("testDistributeNotExactAmt: Unexpected amount of memory allocated. Expected: 0x%x, actual 0x%x", DISTRIBUTE_EXACT_SMF_AMT, l_smfBarSize);
        }
        } while(0);

        TS_INFO(EXIT_MRK"testDistributeNotExactAmt");
    }
};

#endif
