/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2HwpTest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2TestUtils.H>
#include <p9_sample_procedure.H>
#include <plat_hwp_invoker.H>



using namespace fapi2;


class Fapi2HwpTest : public CxxTest::TestSuite
{
public:
//******************************************************************************
// test_fapi2Hwp
//******************************************************************************
void test_fapi2Hwp()
{
    int numTests = 0;
    int numFails = 0;
    errlHndl_t l_errl = NULL;

    do
    {
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        TARGETING::Target * l_nimbusProc = NULL;

        //Take the first NIMBUS proc and use it
        for(uint32_t i = 0; i < l_chipList.size(); i++)
        {
            if(TARGETING::MODEL_NIMBUS ==
            l_chipList[i]->getAttr<TARGETING::ATTR_MODEL>())
            {
              l_nimbusProc = l_chipList[i];
              break;
            }
        }
        numTests++;
        if(l_nimbusProc == NULL)
        {
            // Send an errorlog because we cannot find any NIMBUS procs.
            FAPI_ERR("FAPI2_GETPARENT:: could not find Nimbus proc, skipping tests");
            numFails++;
            /*@
            * @errortype    ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid     fapi2::MOD_FAPI2_PLAT_HWP_TEST
            * @reasoncode   fapi2::RC_NO_PROCS_FOUND
            * @userdata1    Model Type we looked for
            * @userdata2    Unused
            * @devdesc      Could not find NIMBUS procs in system model
            */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            fapi2::MOD_FAPI2_PLAT_HWP_TEST,
                                            fapi2::RC_NO_PROCS_FOUND,
                                            TARGETING::MODEL_NIMBUS,
                                            NULL,
                                            true/*SW Error*/);
            errlCommit(l_errl,HWPF_COMP_ID);
            break;
        }

        TARGETING::Target* targeting_targets[NUM_TARGETS];
        generateTargets(l_nimbusProc, targeting_targets);

        for( uint64_t x = 0; x < NUM_TARGETS; x++ )
        {
            if(targeting_targets[x] == NULL)
            {
              FAPI_ERR("Unable to find target for item %d in targeting_targets", x);

              /*@
              * @errortype    ERRORLOG::ERRL_SEV_UNRECOVERABLE
              * @moduleid     fapi2::MOD_FAPI2_PLAT_HWP_TEST
              * @reasoncode   fapi2::RC_NO_PATH_TO_TARGET_FOUND
              * @userdata1    Index of target in array of objects
              * @userdata2    Unused
              * @devdesc      Could not find a path to the target of that type
              */
              l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              fapi2::MOD_FAPI2_PLAT_HWP_TEST,
                                              fapi2::RC_NO_PATH_TO_TARGET_FOUND,
                                              x,
                                              NULL,
                                              true/*SW Error*/);
              errlCommit(l_errl,HWPF_COMP_ID);
            }
        }

        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_nimbusProc);
        fapi2::Target<fapi2::TARGET_TYPE_EQ> fapi2_eqTarget(targeting_targets[MY_EQ]);
        fapi2::Target<fapi2::TARGET_TYPE_EX> fapi2_exTarget(targeting_targets[MY_EX]);
        fapi2::Target<fapi2::TARGET_TYPE_CORE> fapi2_coreTarget(
                targeting_targets[MY_CORE]);
        fapi2::Target<fapi2::TARGET_TYPE_MCS> fapi2_mcsTarget(targeting_targets[MY_MCS]);
        fapi2::Target<fapi2::TARGET_TYPE_MCA> fapi2_mcaTarget(targeting_targets[MY_MCA]);
        fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapi2_mcbistTarget(
                                                    targeting_targets[MY_MCBIST]);
        fapi2::Target<fapi2::TARGET_TYPE_PEC> fapi2_pecTarget(targeting_targets[MY_PEC]);
        fapi2::Target<fapi2::TARGET_TYPE_PHB> fapi2_phbTarget(targeting_targets[MY_PHB]);
        fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapi2_xbusTarget(
                targeting_targets[MY_XBUS]);
        fapi2::Target<fapi2::TARGET_TYPE_OBUS> fapi2_obusTarget(
                targeting_targets[MY_OBUS]);
        fapi2::Target<fapi2::TARGET_TYPE_NV> fapi2_nvTarget(
                targeting_targets[MY_NV]);
        fapi2::Target<fapi2::TARGET_TYPE_PPE> fapi2_ppeTarget(targeting_targets[MY_PPE]);
        fapi2::Target<fapi2::TARGET_TYPE_PERV> fapi2_pervTarget(
                targeting_targets[MY_PERV]);
        fapi2::Target<fapi2::TARGET_TYPE_SBE> fapi2_sbeTarget(targeting_targets[MY_SBE]);
        fapi2::Target<fapi2::TARGET_TYPE_CAPP> fapi2_cappTarget(
                                      targeting_targets[MY_CAPP]);


        int scratchWriteValue = 5;

        //Get/Set Attr for all of the targets
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_proc, fapi2_procTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_proc !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_eq, fapi2_eqTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_eq !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_ex, fapi2_exTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_ex !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_core, fapi2_coreTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_core !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_mcs, fapi2_mcsTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_mcs !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_mca, fapi2_mcaTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_mca !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_mcbist, fapi2_mcbistTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_mcbist !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_pec, fapi2_pecTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_pec !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_phb, fapi2_phbTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_phb !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_xbus, fapi2_xbusTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_xbus !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_obus, fapi2_obusTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_obus !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_nv, fapi2_nvTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_nv !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_ppe, fapi2_ppeTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_ppe !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_perv, fapi2_pervTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_perv !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_sbe, fapi2_sbeTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_sbe !!");
        }
        numTests++;
        FAPI_INVOKE_HWP(l_errl, p9_sample_procedure_capp, fapi2_cappTarget, scratchWriteValue);
        if(l_errl != NULL)
        {
          l_errl = NULL;
          numFails++;
          TS_FAIL("Error occured in p9_sample_procedure_capp !!");
        }
    }while(0);
    FAPI_INF("test_fapiHWP:: Test Complete. %d/%d fails",  numFails,numTests);
}

};
