/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetParentTest.C $                     */
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

using namespace fapi2;

namespace fapi2
{

/**
 *  @brief Helper to get the parent pervasive of the given target
 *
 *  @tparam K Input target's FAPI2 type
 *  @tparam V Platform target handle type
 *
 *  @param[in] i_pTarget Targeting target
 *
 *  @return Platform target handle giving the pervasive of the input target
 *  @retval NULL No parent found
 *  @retval !NULL Parent found, equal to the retval
 */
template< TargetType K, typename V = plat_target_handle_t >
inline V getPervasiveParent(V i_pTarget)
{
    Target<K,V> fapi2_target(i_pTarget);
    return static_cast<V>(
        fapi2_target.template getParent<TARGET_TYPE_PERV>());
}

//******************************************************************************
// fapi2GetParentTest
//******************************************************************************
errlHndl_t fapi2GetParentTest()
{
    int numTests = 0;
    int numFails = 0;
    errlHndl_t l_err = NULL;
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

        if(l_nimbusProc == NULL)
        {
            // Send an errorlog because we cannot find any NIMBUS procs.
            FAPI_ERR("FAPI2_GETPARENT:: could not find Nimbus proc, skipping tests");
            numFails++;
            /*@
            * @errortype    ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid     fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode   fapi2::RC_NO_PROCS_FOUND
            * @userdata1    Model Type we looked for
            * @userdata2    Unused
            * @devdesc      Could not find NIMBUS procs in system model
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_NO_PROCS_FOUND,
                                          TARGETING::MODEL_NIMBUS,
                                          NULL,
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
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
                * @moduleid     fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
                * @reasoncode   fapi2::RC_NO_PATH_TO_TARGET_FOUND
                * @userdata1    Index of target in array of objects
                * @userdata2    Unused
                * @devdesc      Could not find a path to the target of that type
                */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_NO_PATH_TO_TARGET_FOUND,
                                          x,
                                          NULL,
                                          true/*SW Error*/);
                errlCommit(l_err,HWPF_COMP_ID);
            }
        }


        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(
                l_nimbusProc);
        Target<fapi2::TARGET_TYPE_EQ> fapi2_eqTarget(
                targeting_targets[MY_EQ]);
        Target<fapi2::TARGET_TYPE_EX> fapi2_exTarget(
                targeting_targets[MY_EX]);
        Target<fapi2::TARGET_TYPE_CORE> fapi2_coreTarget(
                targeting_targets[MY_CORE]);
        Target<fapi2::TARGET_TYPE_MCS> fapi2_mcsTarget(
                targeting_targets[MY_MCS]);
        Target<fapi2::TARGET_TYPE_MCA> fapi2_mcaTarget(
                targeting_targets[MY_MCA]);
        Target<fapi2::TARGET_TYPE_MCBIST> fapi2_mcbistTarget(
                targeting_targets[MY_MCBIST]);
        Target<fapi2::TARGET_TYPE_PEC> fapi2_pecTarget(
                targeting_targets[MY_PEC]);
        Target<fapi2::TARGET_TYPE_PHB> fapi2_phbTarget(
                targeting_targets[MY_PHB]);
        Target<fapi2::TARGET_TYPE_XBUS> fapi2_xbusTarget(
                targeting_targets[MY_XBUS]);
        Target<fapi2::TARGET_TYPE_OBUS> fapi2_obusTarget(
                targeting_targets[MY_OBUS]);
        Target<fapi2::TARGET_TYPE_NV> fapi2_nvTarget(
                targeting_targets[MY_NV]);
        Target<fapi2::TARGET_TYPE_PPE> fapi2_ppeTarget(
                targeting_targets[MY_PPE]);
        Target<fapi2::TARGET_TYPE_PERV> fapi2_pervTarget(
                targeting_targets[MY_PERV]);
        Target<fapi2::TARGET_TYPE_SBE> fapi2_sbeTarget(
                targeting_targets[MY_SBE]);
        Target<fapi2::TARGET_TYPE_CAPP> fapi2_cappTarget(
                targeting_targets[MY_CAPP]);

        TARGETING::Target * l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_coreTarget.getParent<TARGET_TYPE_EX>());

        //Check CORE's parents
        numTests++;
        if(TARGETING::get_huid(targeting_targets[MY_EX]) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_CORE]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);

            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_CORE_NO_EX_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of core
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent EX of this
            *                     CORE target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_CORE_NO_EX_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          targeting_targets[MY_EX])),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_EX)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL("fapi2TargetTest::Unable to find CORE's EX parent!");
            numFails++;
        }


        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_coreTarget.getParent<TARGET_TYPE_EQ>());

        numTests++;
        if(TARGETING::get_huid(targeting_targets[MY_EQ]) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_CORE]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_CORE_NO_EQ_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of core
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent EQ of this
            *                     CORE target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_CORE_NO_EQ_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          targeting_targets[MY_EQ])),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_EQ)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find CORE's EQ parent!");
            numFails++;
        }


        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_coreTarget.getParent<TARGET_TYPE_PROC_CHIP>());

        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_CORE]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_CORE_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of core
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     CORE target
            */
            l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                fapi2::RC_CORE_NO_PROC_FOUND,
                                TWO_UINT32_TO_UINT64(
                                TO_UINT32(
                                TARGETING::get_huid(
                                l_nimbusProc)),
                                TO_UINT32(
                                TARGETING::get_huid(
                                l_tempTargetingParent))),
                                TWO_UINT32_TO_UINT64(
                                TO_UINT32(l_instance),
                                TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find CORE's PROC parent!");
            numFails++;
        }


        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_exTarget.getParent<TARGET_TYPE_EQ>());

        //Check EX's parents
        numTests++;
        if(TARGETING::get_huid(targeting_targets[MY_EQ]) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {

          uint8_t l_instance = 0;
          targeting_targets[MY_EX]->
          tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
          /*@
          * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
          * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
          * @reasoncode         fapi2::RC_EX_NO_EQ_FOUND
          * @userdata1[0:31]    Expected Parent HUID
          * @userdata1[32:63]   Actual Parent HUID
          * @userdata2[0:31]    Instance of EX
          * @userdata2[32:63]   fapi2 Type of expected parent
          * @devdesc            Could not find the parent EQ of this EX target
          */
          l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                        fapi2::RC_EX_NO_EQ_FOUND,
                                        TWO_UINT32_TO_UINT64(
                                        TO_UINT32(
                                        TARGETING::get_huid(
                                        targeting_targets[MY_EQ])),
                                        TO_UINT32(
                                        TARGETING::get_huid(
                                        l_tempTargetingParent))),
                                        TWO_UINT32_TO_UINT64(
                                        TO_UINT32(l_instance),
                                        TO_UINT32(TARGET_TYPE_EQ)),
                                        true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find EX's EQ parent!");
            numFails++;
        }


        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_exTarget.getParent<TARGET_TYPE_PROC_CHIP>());

        //Check EX's parents
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_EX]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_EX_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of EX
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc           Could not find the parent PROC of this
            *                    EX target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_EX_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find EXs's PROC parent!");
            numFails++;
        }

        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_eqTarget.getParent<TARGET_TYPE_PROC_CHIP>());

        //Check EQ's parents
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_EQ]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_EQ_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of EQ
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     EQ target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_EQ_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find EQs's PROC parent!");
            numFails++;
        }

        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_mcaTarget.getParent<TARGET_TYPE_MCS>());

        //Check MCA's parents
        numTests++;
        if(TARGETING::get_huid(targeting_targets[MY_MCS]) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_MCA]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_MCA_NO_MCS_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of MCA
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent MSC of this
            *                     MCA target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_MCA_NO_MCS_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          targeting_targets[MY_MCS])),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_MCS)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find MCA's MCS parent!");
            numFails++;
        }

        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_mcaTarget.getParent<TARGET_TYPE_PROC_CHIP>());

        numTests++;

        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_MCA]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_MCA_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of MCA
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     MCA target
            */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                  fapi2::RC_MCA_NO_PROC_FOUND,
                                  TWO_UINT32_TO_UINT64(
                                  TO_UINT32(
                                  TARGETING::get_huid(
                                  l_nimbusProc)),
                                  TO_UINT32(
                                  TARGETING::get_huid(
                                  l_tempTargetingParent))),
                                  TWO_UINT32_TO_UINT64(
                                  TO_UINT32(l_instance),
                                  TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                  true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find MCA's PROC parent!");
            numFails++;
        }

        //Check MCS's parents

        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_mcsTarget.getParent<TARGET_TYPE_PROC_CHIP>());

        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_MCS]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_MCS_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of MCS
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     MCS target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_MCS_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find MCS's PROC parent!");
            numFails++;
        }

        //Check MCBIST's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_mcbistTarget.getParent<TARGET_TYPE_PROC_CHIP>());

        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_MCBIST]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_MCBIST_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of MCS
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     MCBIST target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_MCBIST_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find MCBIST's PROC parent!");
            numFails++;
        }

        //Check PHB's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_phbTarget.getParent<TARGET_TYPE_PROC_CHIP>());

        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_PHB]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_PHB_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of PHB
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     PHB target
            */
            l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                fapi2::RC_PHB_NO_PROC_FOUND,
                                TWO_UINT32_TO_UINT64(
                                TO_UINT32(
                                TARGETING::get_huid(
                                l_nimbusProc)),
                                TO_UINT32(
                                TARGETING::get_huid(
                                l_tempTargetingParent))),
                                TWO_UINT32_TO_UINT64(
                                TO_UINT32(l_instance),
                                TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find PHB's PROC parent!");
            numFails++;
        }

        //Check PEC's parents

        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_pecTarget.getParent<TARGET_TYPE_PROC_CHIP>());
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_PEC]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_PEC_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of PEC
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     PEC target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_PEC_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find PEC's PROC parent!");
            numFails++;
        }

        //Check XBUS's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_xbusTarget.getParent<TARGET_TYPE_PROC_CHIP>());
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_XBUS]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_XBUS_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of XBUS
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     XBUS target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_XBUS_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find XBUS's PROC parent!");
            numFails++;
        }

        //Check OBUS's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_obusTarget.getParent<TARGET_TYPE_PROC_CHIP>());
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_OBUS]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_OBUS_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of OBUS
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     OBUS target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_OBUS_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
           errlCommit(l_err,HWPF_COMP_ID);
           TS_FAIL( "fapi2TargetTest::Unable to find OBUS's PROC parent!");
           numFails++;
        }

        //Check NV's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_nvTarget.getParent<TARGET_TYPE_PROC_CHIP>());
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_NV]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_NV_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of NV
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     NV target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_NV_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find NV's PROC parent!");
            numFails++;
        }

        //Check PPE's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_ppeTarget.getParent<TARGET_TYPE_PROC_CHIP>());
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_PPE]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_PPE_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of PPE
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     PPE target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_PPE_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::Unable to find PPE's PROC parent!");
            numFails++;
        }

        //Check PERV's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_pervTarget.getParent<TARGET_TYPE_PROC_CHIP>());
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_PERV]->
              tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_PERV_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of PERV
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     PERV target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_PERV_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
           errlCommit(l_err,HWPF_COMP_ID);
           TS_FAIL( "fapi2TargetTest::Unable to find PERV's PROC parent!");
           numFails++;
        }

        //Check CAPP's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_cappTarget.getParent<TARGET_TYPE_PROC_CHIP>());
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_CAPP]->
              tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_CAPP_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of CAPP
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     CAPP target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_CAPP_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
           errlCommit(l_err,HWPF_COMP_ID);
           TS_FAIL( "fapi2TargetTest::Unable to find CAPP's PROC parent!");
           numFails++;
        }

        //Check SBE's parents
        l_tempTargetingParent =
            static_cast<TARGETING::Target*>(
                fapi2_sbeTarget.getParent<TARGET_TYPE_PROC_CHIP>());
        numTests++;
        if(TARGETING::get_huid(l_nimbusProc) !=
           TARGETING::get_huid(l_tempTargetingParent))
        {
            uint8_t l_instance = 0;
            targeting_targets[MY_SBE]->
            tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_instance);
            /*@
            * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
            * @reasoncode         fapi2::RC_SBE_NO_PROC_FOUND
            * @userdata1[0:31]    Expected Parent HUID
            * @userdata1[32:63]   Actual Parent HUID
            * @userdata2[0:31]    Instance of SBE
            * @userdata2[32:63]   fapi2 Type of expected parent
            * @devdesc            Could not find the parent PROC of this
            *                     SBE target
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                                          fapi2::RC_SBE_NO_PROC_FOUND,
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_nimbusProc)),
                                          TO_UINT32(
                                          TARGETING::get_huid(
                                          l_tempTargetingParent))),
                                          TWO_UINT32_TO_UINT64(
                                          TO_UINT32(l_instance),
                                          TO_UINT32(TARGET_TYPE_PROC_CHIP)),
                                          true/*SW Error*/);
            errlCommit(l_err,HWPF_COMP_ID);
            TS_FAIL( "fapi2TargetTest::UnAble to find SBE's PROC parent!");
            numFails++;
        }

        // Check units which have a pervasive parent

        static struct pervasiveParentTestRec {

            // Source unit from which to find parent pervasive
            TARGETING::Target* pTarget;

            // Lambda function taking a unit target and returning its
            // parent pervasive target (if any)
            TARGETING::Target* (*getParent)(TARGETING::Target* i_pTarget);

        } pervasiveParentTests [] = {

            {targeting_targets[MY_EQ],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_EQ>(i_pTarget); }},
            {targeting_targets[MY_CORE],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_CORE>(i_pTarget); }},
            {targeting_targets[MY_MCS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MCS>(i_pTarget); }},
            {targeting_targets[MY_MCA],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MCA>(i_pTarget); }},
            {targeting_targets[MY_MCBIST],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_MCBIST>(i_pTarget);}},
            {targeting_targets[MY_PEC],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_PEC>(i_pTarget); }},
            {targeting_targets[MY_PHB],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_PHB>(i_pTarget); }},
            {targeting_targets[MY_XBUS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_XBUS>(i_pTarget); }},
            {targeting_targets[MY_OBUS],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_OBUS>(i_pTarget); }},
            {targeting_targets[MY_NV],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_NV>(i_pTarget); }},
            {targeting_targets[MY_CAPP],
             [](TARGETING::Target* i_pTarget)
                 {return getPervasiveParent<TARGET_TYPE_CAPP>(i_pTarget); }},
        };

        // Test each type of target that can have exactly one pervasive parent
        for(const pervasiveParentTestRec& pervasiveParentTest
                : pervasiveParentTests)
        {
            numTests++;
            l_tempTargetingParent = pervasiveParentTest.getParent(
                pervasiveParentTest.pTarget);

            // Result must be a non-NULL target of pervasive type, and its
            // parent must be the same proc as the other tests above
            TARGETING::Target* pPervasiveParent = NULL;
            if(    l_tempTargetingParent
               && (   l_tempTargetingParent->getAttr<TARGETING::ATTR_TYPE>()
                   == TARGETING::TYPE_PERV))
            {
                Target<TARGET_TYPE_PERV> fapi2_pervTarg(l_tempTargetingParent);
                pPervasiveParent = static_cast<TARGETING::Target*>(
                    fapi2_pervTarg.getParent<TARGET_TYPE_PROC_CHIP>());
            }

            // If the parent of the target under test was NULL, or it was
            // not a pervasive, or if the parent of the pervasive was NULL
            // or was not the processor, fail the test
            if(TARGETING::get_huid(l_nimbusProc) !=
               TARGETING::get_huid(pPervasiveParent))
            {
                TARGETING::ATTR_CHIP_UNIT_type instance = 0;
                TARGETING::ATTR_TYPE_type type = TARGETING::TYPE_NA;
                pervasiveParentTest.pTarget->
                    tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(instance);
                pervasiveParentTest.pTarget->
                    tryGetAttr<TARGETING::ATTR_TYPE>(type);

                /*@
                * @errortype         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                * @moduleid          fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST
                * @reasoncode        fapi2::RC_UNIT_NO_PERV_FOUND
                * @userdata1[0:31]   Actual PROC HUID
                * @userdata1[32:63]  Actual PERV HUID
                * @userdata2[0:31]   Source unit's "chip unit"
                * @userdata2[32:63]  Source unit's "targeting type"
                * @devdesc           Could not find the parent PERV of this
                *                    unit target or the pervasive did not
                *                    map to expected PROC
                */
                l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi2::MOD_FAPI2_PLAT_GET_PARENT_TEST,
                    fapi2::RC_UNIT_NO_PERV_FOUND,
                    TWO_UINT32_TO_UINT64(
                        TO_UINT32(
                            TARGETING::get_huid(pPervasiveParent)),
                        TO_UINT32(
                            TARGETING::get_huid(l_tempTargetingParent))),
                    TWO_UINT32_TO_UINT64(
                        TO_UINT32(instance),
                        TO_UINT32(type)),
                    true/*SW Error*/);

                errlCommit(l_err,HWPF_COMP_ID);
                TS_FAIL("fapi2TargetTest::Unable to find unit's pervasive!");
                numFails++;
            }
        }

    }while(0);
    FAPI_INF("fapi2TargetTest:: Test Complete. %d/%d fails", numTests, numFails);
    return l_err;
}




}
