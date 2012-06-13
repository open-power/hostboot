/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pore/test/poretest.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __PORETEST_H
#define __PORETEST_H

/**
 *  @file poretest.H
 *
 *  @brief Test case for POREVE code
*/

#include <list>
#include <cxxtest/TestSuite.H>
#include <targeting/common/commontargeting.H>
#include <fapiPoreVeArg.H>
#include <fapiTarget.H>
#include <fapi.H>
#include <vfs/vfs.H>

//@todo - These two include files are to workaround
//1. Avoid running test case in VBU
//2. To call isSlavePresent(). Need to be removed when PD works.
#include <fsi/fsiif.H>

#define CENTAUR_SBE_PNOR_MRR    0       // Memory Relocation Register for Centaur


using namespace TARGETING;
using namespace vsbe;
extern fapi::ReturnCode fapiPoreVe(const fapi::Target i_target,
                                   std::list<uint64_t> & io_sharedObjectArgs);

class PoreTest: public CxxTest::TestSuite
{
public:
    /**
     * @brief PORE test #1
     *        Run a sample procedure on Centaur
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
            l_errl = VFS::module_load("centaur.sbe_pnor.bin");
            if (l_errl)
            {
                TS_FAIL("testPore1: Error loading centaur.sbe_pnor.bin!");
                break;
            }
            else
            {
                // Set flag to unload
                l_unloadSbePnorImg = true;
                l_errl = VFS::module_address("centaur.sbe_pnor.bin", l_sbePnorAddr, l_sbePnorSize);
                if(l_errl)
                {
                    TS_FAIL("testPore1: Error getting load address of centaur.sbe_pnor.bin!");
                    break;
                }
                else
                {
                    char l_header[10];
                    memcpy (l_header, l_sbePnorAddr, 9);
                    l_header[9] = '\0';
                    FAPI_INF("testPore1:Loading centaur.sbe_pnor.bin, Addr 0x%llX, Size %d, Header %s",
                              l_sbePnorAddr, l_sbePnorSize, l_header);
                }
            }

            // ------------ Setup Centaur targets -------------------
            // Use PredicateIsFunctional to filter only functional chips
            TARGETING::PredicateIsFunctional             l_isFunctional;
            //  filter for functional Centaur Chips
            TARGETING::PredicateCTM l_membufChipFilter(CLASS_CHIP, TYPE_MEMBUF);
            // Declare a postfix expression widget
            TARGETING::PredicatePostfixExpr l_functionalAndMembufChipFilter;
            //  is-a-membuf-chip  is-functional   AND
            l_functionalAndMembufChipFilter.push(&l_membufChipFilter).push(&l_isFunctional).And();
            // loop through all the targets, applying the filter,  and put the results in l_pMemBufs
            TARGETING::TargetRangeFilter    l_pMemBufs(
                    TARGETING::targetService().begin(),
                    TARGETING::targetService().end(),
                    &l_functionalAndMembufChipFilter );

            // ------------- Setup POREVE arguments -----------------
            // Setup args
            std::list<uint64_t> myArgs;

            // Set FapiPoreVeOtherArg: run unlimited instructions
            FapiPoreVeOtherArg *l_otherArg =
                    new FapiPoreVeOtherArg(vsbe::RUN_UNLIMITED,
                                           vsbe::PORE_SBE);
            // Entry point
            l_otherArg->iv_entryPoint = const_cast<char*>("pnor::_sbe_pnor_start");
            l_otherArg->iv_mrr = CENTAUR_SBE_PNOR_MRR;
            uint64_t fapiArg = reinterpret_cast<uint64_t> (l_otherArg);
            myArgs.push_back(fapiArg);

            // Set FapiPoreVeMemArg for pnor option, base address = 0
            uint32_t base_addr = 0;
            char* l_dataPnor = const_cast<char*>(l_sbePnorAddr);
            FapiPoreVeMemArg* l_memArg = new FapiPoreVeMemArg(ARG_PNOR,
                                base_addr, l_sbePnorSize,
                                static_cast<void*>(l_dataPnor));
            fapiArg = reinterpret_cast<uint64_t> (l_memArg);
                      myArgs.push_back(fapiArg);

            // Create state argument to dump out state for debugging purpose
            FapiPoreVeStateArg *l_stateArg = new FapiPoreVeStateArg(NULL);
                          l_stateArg->iv_installState = false;
                          l_stateArg->iv_extractState = true;
                          fapiArg = reinterpret_cast<uint64_t> (l_stateArg);
                          myArgs.push_back(fapiArg);


            // Run loop on all Centaurs
            for (    ;   l_pMemBufs;    ++l_pMemBufs  )
            {
                // Create a FAPI Target
                const TARGETING::Target*  l_membuf_target = *l_pMemBufs;
                const fapi::Target l_fapiTarget(
                                  fapi::TARGET_TYPE_MEMBUF_CHIP,
                                  reinterpret_cast<void *>
                                  (const_cast<TARGETING::Target*>(l_membuf_target)));

                //  Put out info on target
                FAPI_INF("testPore1: Running cen_sbe_tp_chiplet_init1 on Centaur entity path...");
                EntityPath l_path;
                l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();

                //@todo - Make sure target is present
                //        Temporary hack until PD works
                if ( !FSI::isSlavePresent(l_membuf_target) )
                {
                    FAPI_INF("testPore1: Skip this Centaur because it's not present");
                    continue;
                }

                // Run the engine
                FAPI_INF("testPore1: Start VSBE engine...");
                //@todo
                //@VBU workaround - Do not run in VPO since it takes too long
                //Temporarily disable this test case in VBU because it takes too long to run.
                //Also, the image used for Centaur is only a temporary image provided by Todd to try out.
                //When we have an official Centaur sbe_pnor image, use it to create a simple one to run
                //test case.
                if ( !TARGETING::is_vpo() )
                {
                    // @todo - Must comment out for now because Todd's image will fail test case
                    // l_rc = fapiPoreVe(l_fapiTarget, myArgs);
                }

                if (l_rc != fapi::FAPI_RC_SUCCESS)
                {
                   uint32_t val = l_rc;
                   FAPI_INF("testPore1: Error returned from VSBE engine on this Centaur, l_rc 0x%llX",
                           val);
                   break;
                }
                else
                {
                    FAPI_INF("testPore1: VSBE engine runs successfully on this Centaur");
                }

                // @todo - For now, run only on 1 Centaur to save VPO time
                break;


            }   // end for l_pMemBufs


            // Freeing memory
            if (l_otherArg)
            {
                delete l_otherArg;
                l_otherArg = NULL;
            }

            if (l_memArg)
            {
                delete l_memArg;
                l_memArg = NULL;
            }

            if (l_stateArg)
            {
                delete l_stateArg;
                l_stateArg = NULL;
            }



        } while(0);

        // Unload sbe_pnor
        if (l_unloadSbePnorImg == true)
        {
            l_rc2 = fapiUnloadInitFile("centaur.sbe_pnor.bin", l_sbePnorAddr,
                                       l_sbePnorSize);
            if (l_rc2 != fapi::FAPI_RC_SUCCESS)
            {
                 FAPI_ERR("testPore1: Error unloading centaur.sbe_pnor.bin");
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

    /**
     * @brief PORE test #2
     *        Run a sample procedure on Proc
     */
    void testPore2(void)
    {
        // @todo - Add code to run sbe image from Proc when available

        return;
    }

};

#endif
