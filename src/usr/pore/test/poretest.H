//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/test/poretest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __PORETEST_H
#define __PORETEST_H

/**
 *  @file poretest.H
 *
 *  @brief Test case for POREVE code
*/

#include <list>
#include <cxxtest/TestSuite.H>
#include <targeting/targetservice.H>
#include <fapiPoreVeArg.H>
#include <fapiTarget.H>
#include <fapi.H>
#include    <vfs/vfs.H>

using namespace TARGETING;
using namespace vsbe;
extern fapi::ReturnCode fapiPoreVe(const fapi::Target i_target,
                                   std::list<uint64_t> & io_sharedObjectArgs);

class PoreTest: public CxxTest::TestSuite
{
public:
    /**
     * @brief PORE test #1
     *        Run a sample procedure
     */
    void testPore1(void)
    {
        fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
        fapi::ReturnCode l_rc2 = fapi::FAPI_RC_SUCCESS;
        bool l_unloadSbePnorImg = false;
        size_t l_sbePnorSize = 0;
        const char * l_sbePnorAddr = NULL;

        errlHndl_t  l_errl = NULL;

        do
        {
            // Loading sbe_pnor img
            l_errl = VFS::module_load("sbe_pnor.bin");
            if (l_errl)
            {
                TS_FAIL("testPore1: Error loading sbe_pnor.bin!");
                break;
            }
            else
            {
                // Set flag to unload
                l_unloadSbePnorImg = true;
                l_errl = VFS::module_address("sbe_pnor.bin", l_sbePnorAddr, l_sbePnorSize);
                if(l_errl)
                {
                    TS_FAIL("testPore1: Error getting load address of sbe_pnor.bin!");
                    break;
                }
                else
                {
                    char l_header[10];
                    memcpy (l_header, l_sbePnorAddr, 9);
                    l_header[9] = '\0';
                    FAPI_INF("Loading sbe_pnor.bin, Addr 0x%llX, Size %d, Header %s",
                              l_sbePnorAddr, l_sbePnorSize, l_header);
                }
            }

            // Setting up fapi target
            TARGETING::TargetService& l_targetService =
                    TARGETING::targetService();
            TARGETING::Target* l_testTarget = NULL;
            l_targetService.masterProcChipTargetHandle(l_testTarget);
            assert(l_testTarget != NULL);

            // Setup args
            std::list<uint64_t> myArgs;

            // Run unlimited instruction on SBE engine
            FapiPoreVeOtherArg *l_otherArg =
                    new FapiPoreVeOtherArg(vsbe::RUN_UNLIMITED,
                                           vsbe::PORE_SBE);
            //Set entry point
            //l_otherArg->iv_entryPoint = const_cast<char*>("pnor::_sbe_pnor_start");
            //l_otherArg->iv_entryPoint = const_cast<char*>("pnor::proc_sbe_fabricinit");
            l_otherArg->iv_entryPoint = const_cast<char*>("pnor::proc_sbe_pb_startclocks");

            l_otherArg->iv_mrr = 0x280000000;

            uint64_t fapiArg = reinterpret_cast<uint64_t> (l_otherArg);
            myArgs.push_back(fapiArg);

            // Set FapiPoreVeMemArg for pnor option, base address = 0
            uint32_t base_addr = 0;
            char* l_dataPnor = const_cast<char*>(l_sbePnorAddr);
            //@todo - Need to somehow avoid manually entering file size here.
            FapiPoreVeMemArg* l_memArg = new FapiPoreVeMemArg(ARG_PNOR,
                        base_addr, 31360, static_cast<void*>(l_dataPnor));
            fapiArg = reinterpret_cast<uint64_t> (l_memArg);
            myArgs.push_back(fapiArg);

            // Create state argument to dump out state for debugging purpose
            FapiPoreVeStateArg *l_stateArg = new FapiPoreVeStateArg(NULL);
            l_stateArg->iv_installState = false;
            l_stateArg->iv_extractState = true;
            fapiArg = reinterpret_cast<uint64_t> (l_stateArg);
            myArgs.push_back(fapiArg);

            // Create a FAPI Target
            fapi::Target l_fapiTarget(fapi::TARGET_TYPE_PROC_CHIP,
                    reinterpret_cast<void *> (l_testTarget));

            //@todo - Comment out the actual run for now because
            //        the "halt" instruction causes poreve to scom SBEVITAL cfam reg,
            //        which causes an error in SIMICs.
            //        VBU model also has a hack that models this register
            //l_rc = fapiPoreVe(l_fapiTarget, myArgs);
            if (l_rc != fapi::FAPI_RC_SUCCESS)
            {
                uint32_t val = l_rc;
                FAPI_ERR("testPore1: Error from fapiPoreVe 0x%llX", val);
            }
            else
            {
                FAPI_INF("testPore1: fapiPoreVe runs successfully!");
            }

        } while(0);

        // Unload sbe_pnor
        if (l_unloadSbePnorImg == true)
        {
            l_rc2 = fapiUnloadInitFile("sbe_pnor.bin", l_sbePnorAddr,
                                       l_sbePnorSize);
            if (l_rc2 != fapi::FAPI_RC_SUCCESS)
            {
                 FAPI_ERR("testPore1: Error unloading sbe_pnor.bin");
                 if (l_rc == fapi::FAPI_RC_SUCCESS)
                 {
                     l_rc = l_rc2;
                 }
            }
        }

        // Test fail/pass
        if (l_rc != fapi::FAPI_RC_SUCCESS)
        {
            TS_FAIL("testPore1 fails! Check FAPI trace");
        }
        else
        {
            TS_TRACE("testPore1 ran successfully!");
        }

        return;
    }
};

#endif
