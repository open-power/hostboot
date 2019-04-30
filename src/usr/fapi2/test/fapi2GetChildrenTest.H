/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2GetChildrenTest.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include <cxxtest/TestSuite.H>
#include <functional>
#include <plat_utils.H>
#include <error_scope.H>
#include <config.h>

namespace fapi2
{

class Fapi2GetChildrenTest : public CxxTest::TestSuite
{
public:


        struct pervasiveChildTestRec {

            // Expected number of children
            uint32_t expectedSize;

            // Lambda function specifying which pervasive chip units map to
            // children of the type implied by the body of the lambda function
            // below
            bool (*unitMapsToRightTargetType)(TARGETING::ATTR_CHIP_UNIT_type);

            // Lambda function taking a pervasive target and returning the
            // number of children it has for a given FAPI type
            size_t (*actualSize)(Target<fapi2::TARGET_TYPE_PERV>&);

        };

//******************************************************************************
// test_fapi2GetChildren
//******************************************************************************
void test_fapi2GetChildren()
{
    uint32_t l_targetHuid = 0xFFFFFFFF;
    uint32_t l_actualSize = 0;
    uint32_t l_expectedSize = 0;
    errlHndl_t l_err = nullptr;
    int numTests = 0;
    int numFails = 0;

    do
    {
        GENERATE_TEST_TARGETS(test_fapi2GetChildren)

        // Creates some vectors for later use
        std::vector<Target<fapi2::TARGET_TYPE_CORE> > l_childCores;
        std::vector<Target<fapi2::TARGET_TYPE_MCA> > l_childMCAs;
        std::vector<Target<fapi2::TARGET_TYPE_EQ> > l_childEQs;
        std::vector<Target<fapi2::TARGET_TYPE_EX> > l_childEXs;
        std::vector<Target<fapi2::TARGET_TYPE_XBUS> > l_childXBUSs;
        std::vector<Target<fapi2::TARGET_TYPE_DMI> > l_childDMIs;
        std::vector<Target<fapi2::TARGET_TYPE_OMI> > l_childOMIs;
        std::vector<Target<fapi2::TARGET_TYPE_OCMB_CHIP> > l_childOCMBs;
        std::vector<Target<fapi2::TARGET_TYPE_MEM_PORT> > l_childMEMPORTs;


        if (isHwValid(l_proc, MY_MCA)
              && isHwValid(l_proc, MY_MCBIST)
              && isHwValid(l_proc, MY_MCS))
        {
            l_childMCAs = fapi2_mcbistTarget.getChildren<fapi2::TARGET_TYPE_MCA>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_MCBIST]);
            l_actualSize = l_childMCAs.size();

            //Set expected size to be the number of MCAs per MCBIST
            l_expectedSize = MCA_PER_MCS * MCS_PER_PROC / MCBIST_PER_PROC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: MCAs per MCBIST mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_MC)
              && isHwValid(l_proc, MY_MI)
              && isHwValid(l_proc, MY_DMI))
        {
            l_childDMIs = fapi2_mcTarget.getChildren<fapi2::TARGET_TYPE_DMI>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_MC]);
            l_actualSize = l_childDMIs.size();

            //Set expected size to be the number of DMIs per MC
            l_expectedSize = DMI_PER_MI * MI_PER_PROC / MC_PER_PROC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: DMIs per MC mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_MC)
            && isHwValid(l_proc, MY_MI)
            && isHwValid(l_proc, MY_MCC)
            && isHwValid(l_proc, MY_OMI))
        {
            l_childOMIs = fapi2_mcTarget.getChildren<fapi2::TARGET_TYPE_OMI>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_MC]);
            l_actualSize = l_childOMIs.size();

            //Set expected size to be the number of OMIs per MC
            l_expectedSize = OMI_PER_MCC * MCC_PER_MI * MI_PER_MC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: OMIs per MC mismatch");
                numFails++;
                break;
            }
        }

        l_childCores = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per proc
        l_expectedSize = EQ_PER_PROC * EX_PER_EQ * CORE_PER_EX;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: present cores per proc mismatch");
            numFails++;
            break;
        }

        l_childCores = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_FUNCTIONAL);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per proc
        //Nimbus model has 4 functional cores
        l_expectedSize = SIMULATED_GOOD_CORES;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: functional cores per proc mismatch");
            numFails++;
            break;
        }

        if (isHwValid(l_proc, MY_MCA)
              && isHwValid(l_proc, MY_MCBIST)
              && isHwValid(l_proc, MY_MCS))
        {
            l_childMCAs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_MCA>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(l_proc) ;
            l_actualSize = l_childMCAs.size();

            //Set expected size to be the number of MCAs per proc
            l_expectedSize = MCA_PER_MCS * MCS_PER_PROC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: MCAs per proc mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_MC)
              && isHwValid(l_proc, MY_MI)
              && isHwValid(l_proc, MY_DMI))
        {
            l_childDMIs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_DMI>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(l_proc);
            l_actualSize = l_childDMIs.size();

            //Set expected size to be the number of DMIs per proc
            l_expectedSize = DMI_PER_MI * MI_PER_PROC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: DMIs per proc mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_MC)
            && isHwValid(l_proc, MY_MI)
            && isHwValid(l_proc, MY_MCC)
            && isHwValid(l_proc, MY_OMI))
        {
            l_childOMIs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_OMI>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(l_proc);
            l_actualSize = l_childOMIs.size();

            //Set expected size to be the number of OMIs per proc
            l_expectedSize = OMI_PER_MCC * MCC_PER_MI * MI_PER_MC * MC_PER_PROC;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: OMIs per proc mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_OMIC2)
            && isHwValid(l_proc, MY_OMI))
        {
            l_childOMIs = fapi2_omic2Target.getChildren<fapi2::TARGET_TYPE_OMI>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_OMIC2]);
            l_actualSize = l_childOMIs.size();

            // OMIC2 only has 2 OMIs (others have 3)
            l_expectedSize = 2;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: # OMIs foound for OMIC0 proc is %d and not %d",
                         l_actualSize, l_expectedSize);
                numFails++;
                break;
            }

            bool l_foundme = false;
            for( auto omi : l_childOMIs )
            {
                if( reinterpret_cast<TARGETING::Target*>(omi.get())
                    == targeting_targets[MY_OMI] )
                {
                    l_foundme = true;
                    break;
                }
            }
            if( !l_foundme )
            {
                TS_FAIL("OMI %.8X not found in child list for OMIC %.8X",
                        TARGETING::get_huid(targeting_targets[MY_OMI]),
                        TARGETING::get_huid(targeting_targets[MY_OMIC2]));
            }
        }

        if (isHwValid(l_proc, MY_OMI)
            && isHwValid(l_proc, MY_OCMB))
        {
            l_childOCMBs = fapi2_omiTarget.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_OMI]);
            l_actualSize = l_childOCMBs.size();

            //Set expected size to be the number of OMIs per proc
            l_expectedSize = OCMB_PER_OMI;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: OCMBs per proc mismatch");
                numFails++;
                break;
            }
        }

        if (isHwValid(l_proc, MY_OCMB)
            && isHwValid(l_proc, MY_MEM_PORT))
        {
            l_childMEMPORTs = fapi2_ocmbTarget.getChildren<fapi2::TARGET_TYPE_MEM_PORT>(TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(targeting_targets[MY_OCMB]);
            l_actualSize = l_childOCMBs.size();

            //Set expected size to be the number of OMIs per proc
            l_expectedSize = MEM_PORT_PER_OCMB;
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: MEM_PORTs per proc mismatch");
                numFails++;
                break;
            }
        }


        l_childCores = fapi2_exTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(targeting_targets[MY_EX]) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per ex
        l_expectedSize = CORE_PER_EX;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: cores per EX mismatch");
            numFails++;
            break;
        }


        l_childCores = fapi2_eqTarget.getChildren<fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(targeting_targets[MY_EQ]) ;
        l_actualSize = l_childCores.size();

        //Set expected size to be the number of cores per eq
        l_expectedSize = CORE_PER_EX * EX_PER_EQ;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: cores per EQ mismatch");
            numFails++;
            break;
        }


        //Explicitly make sure getChildren for EX targets works
        l_childEXs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_EX>(TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childEXs.size();

        //Set expected size to be the number of Exs per proc
        l_expectedSize = EQ_PER_PROC * EX_PER_EQ;
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            TS_FAIL("test_fapi2GetChildren:: EXs per proc mismatch");
            numFails++;
            break;
        }


        // Test pervasive children

        // Valid children for PERV:
        // PERV -> EQ   // PERV -> CORE // PERV -> XBUS   // PERV -> OBUS
        // PERV -> CAPP // PERV -> NV   // PERV -> MCBIST // PERV -> MCS
        // PERV -> MCA  // PERV -> PEC  // PERV -> PHB    // PERV -> MI
        // PERV -> DMI

        static pervasiveChildTestRec nimbusPervasiveChildTests [] = {

            // EQ pervasive has 1 EQ child
            {PERV_EQ_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= EQ_LOW) && (i_unit <= EQ_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_EQ>(
                   TARGET_STATE_PRESENT).size(); } },

            // CORE pervasive has 32 CORE child
            {PERV_CORE_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                 { return ((i_unit >= CORE_LOW) && (i_unit <= CORE_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CORE>(
                   TARGET_STATE_PRESENT).size(); } },

            // XBUS pervasive has 1 XBUS children
            {PERV_XBUS_NIMBUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == XBUS_RANGE); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_XBUS>(
                   TARGET_STATE_PRESENT).size(); } },

            // OBUS pervasive has 3 OBUS child
            {PERV_OBUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= OBUS_LOW) && (i_unit <= OBUS_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_OBUS>(
                   TARGET_STATE_PRESENT).size(); } },

            // CAPP pervasive has 1 CAPP child
            {PERV_CAPP_NIMBUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                { return ((i_unit == CAPP0_RANGE) || (i_unit == CAPP1_RANGE));},
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CAPP>(
                   TARGET_STATE_PRESENT).size(); } },

            // OBUS pervasive has 3 OBUS BRICK children
            {PERV_OBUS_BRICK_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= OBUS_LOW) && (i_unit <= OBUS_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_OBUS_BRICK>(
                   TARGET_STATE_PRESENT).size(); } },

            // MCBIST/MCS/MCA pervasive has 1 MCBIST child
            {PERV_MCBIST_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (   (i_unit >= MC_LOW)
                            && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_MCBIST>(
                   TARGET_STATE_PRESENT).size(); } },

            // MCBIST/MCS/MCA pervasive has 2 MCS children
            {PERV_MCS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_MCS>(
                    TARGET_STATE_PRESENT).size(); } },

            // MCBIST/MCS/MCA pervasive has 4 MCA children
            {PERV_MCA_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_MCA>(
                    TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive has 1 PEC child
            {PERV_PEC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
              { return ((i_unit >= PEC_LOW) && (i_unit <= PEC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PEC>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 1 PHB child
            {PERV_PEC0_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_LOW); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 2 PHB children
            {PERV_PEC1_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_MID); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 3 PHB children
            {PERV_PEC2_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_HIGH); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // No MI or DMI units for Nimbus
        };

        static pervasiveChildTestRec cumulusPervasiveChildTests [] = {

            // EQ pervasive has 1 EQ child
            {PERV_EQ_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= EQ_LOW) && (i_unit <= EQ_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_EQ>(
                   TARGET_STATE_PRESENT).size(); } },

            // CORE pervasive has 32 CORE child
            {PERV_CORE_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                 { return ((i_unit >= CORE_LOW) && (i_unit <= CORE_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CORE>(
                   TARGET_STATE_PRESENT).size(); } },

            // XBUS pervasive has 1 XBUS children
            {PERV_XBUS_CUMULUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == XBUS_RANGE); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_XBUS>(
                   TARGET_STATE_PRESENT).size(); } },

            // OBUS pervasive has 3 OBUS child
            {PERV_OBUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= OBUS_LOW) && (i_unit <= OBUS_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_OBUS>(
                   TARGET_STATE_PRESENT).size(); } },

            // CAPP pervasive has 1 CAPP child
            {PERV_CAPP_CUMULUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                { return ((i_unit == CAPP0_RANGE) || (i_unit == CAPP1_RANGE));},
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CAPP>(
                   TARGET_STATE_PRESENT).size(); } },

            // OBUS pervasive has 3 OBUS BRICK children
            {PERV_OBUS_BRICK_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= OBUS_LOW) && (i_unit <= OBUS_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_OBUS_BRICK>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive has 1 PEC child
            {PERV_PEC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
              { return ((i_unit >= PEC_LOW) && (i_unit <= PEC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PEC>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 1 PHB child
            {PERV_PEC0_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_LOW); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 2 PHB children
            {PERV_PEC1_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_MID); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 3 PHB children
            {PERV_PEC2_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_HIGH); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // MC / MI / DMI pervasive has 1 MC Children
            {PERV_MC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (   (i_unit >= MC_LOW)
                            && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_MC>(
                   TARGET_STATE_PRESENT).size(); } },

            // MC / MI / DMI pervasive has 2 MI Children
            {PERV_MI_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_MI>(
                    TARGET_STATE_PRESENT).size(); } },

            // MC / MI / DMI pervasive has 4 DMI children
            {PERV_DMI_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_DMI>(
                    TARGET_STATE_PRESENT).size(); } },
        };

        static pervasiveChildTestRec axonePervasiveChildTests [] = {

            // EQ pervasive has 1 EQ child
            {PERV_EQ_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= EQ_LOW) && (i_unit <= EQ_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_EQ>(
                   TARGET_STATE_PRESENT).size(); } },

            // CORE pervasive has 32 children
            {PERV_CORE_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                 { return ((i_unit >= CORE_LOW) && (i_unit <= CORE_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CORE>(
                   TARGET_STATE_PRESENT).size(); } },

            // XBUS pervasive has 1 XBUS children
            {PERV_XBUS_CUMULUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == XBUS_RANGE); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_XBUS>(
                   TARGET_STATE_PRESENT).size(); } },

            // OBUS pervasive has 3 OBUS child
            {PERV_OBUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= OBUS_LOW) && (i_unit <= OBUS_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_OBUS>(
                   TARGET_STATE_PRESENT).size(); } },

            // CAPP pervasive has 1 CAPP child
            {PERV_CAPP_CUMULUS_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                { return ((i_unit == CAPP0_RANGE) || (i_unit == CAPP1_RANGE));},
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_CAPP>(
                   TARGET_STATE_PRESENT).size(); } },

            // OBUS pervasive has 3 OBUS BRICK children
            {PERV_OBUS_BRICK_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= OBUS_LOW) && (i_unit <= OBUS_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_OBUS_BRICK>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive has 3 PEC child
            {PERV_PEC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
              { return ((i_unit >= PEC_LOW) && (i_unit <= PEC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PEC>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 1 PHB child
            {PERV_PEC0_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_LOW); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 2 PHB children
            {PERV_PEC1_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_MID); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // PEC/PHB pervasive with 3 PHB children
            {PERV_PEC2_PHB_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (i_unit == PEC_HIGH); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                 { return i_perv.getChildren<fapi2::TARGET_TYPE_PHB>(
                   TARGET_STATE_PRESENT).size(); } },

            // MC / MI / DMI pervasive has 1 MC Children
            {PERV_MC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return (   (i_unit >= MC_LOW)
                            && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_MC>(
                   TARGET_STATE_PRESENT).size(); } },

            // MC / MI / DMI pervasive has 2 MI Children
            {PERV_MI_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                  { return i_perv.getChildren<fapi2::TARGET_TYPE_MI>(
                    TARGET_STATE_PRESENT).size(); } },

            // MC / MI / MCC / OMI pervasive has 4 MCC children
            {PERV_OCC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_MCC>(
                    TARGET_STATE_PRESENT).size(); } },

            // MC / MI / MCC / OMI pervasive has 8 OMI children
            {PERV_OMI_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_OMI>(
                    TARGET_STATE_PRESENT).size(); } },

            {PERV_OMIC_CHILDREN,
             [](TARGETING::ATTR_CHIP_UNIT_type i_unit)
                  { return ((i_unit >= MC_LOW) && (i_unit <= MC_HIGH)); },
             [](Target<fapi2::TARGET_TYPE_PERV>& i_perv)
                   { return i_perv.getChildren<fapi2::TARGET_TYPE_OMIC>(
                    TARGET_STATE_PRESENT).size(); } },
        };

        pervasiveChildTestRec* ptr;
        int numPervTests = 0;
        TARGETING::ATTR_MODEL_type l_model = l_proc->getAttr<TARGETING::ATTR_MODEL>();
        if (l_model == TARGETING::MODEL_NIMBUS)
        {
            numPervTests = sizeof(nimbusPervasiveChildTests) / sizeof(pervasiveChildTestRec);
            ptr = nimbusPervasiveChildTests;
        }
        else if(l_model == TARGETING::MODEL_CUMULUS)
        {
            numPervTests = sizeof(cumulusPervasiveChildTests) / sizeof(pervasiveChildTestRec);
            ptr = cumulusPervasiveChildTests;
        }
        else if(l_model == TARGETING::MODEL_AXONE)
        {
            numPervTests = sizeof(axonePervasiveChildTests) / sizeof(pervasiveChildTestRec);
            ptr = axonePervasiveChildTests;
        }

        // Build list of all pervasive targets in the blueprint
        TARGETING::TargetHandleList pervasiveTargets;
        TARGETING::getAllChiplets(
            pervasiveTargets,
            TARGETING::TYPE_PERV,
            false);

        // Test each type of target that can be a child of a pervasive
        for (int i = 0; i < numPervTests; ++i)
        {
            const pervasiveChildTestRec& pervasiveChildTest = ptr[i];
            l_expectedSize = pervasiveChildTest.expectedSize;
            l_actualSize = 0;
            l_targetHuid = 0;

            numTests++;
            TARGETING::TargetHandle_t candidateTarget = nullptr;
            for(TARGETING::TargetHandleList::const_iterator pIt
                    = pervasiveTargets.begin();
                pIt != pervasiveTargets.end();
                ++pIt)
            {
                auto unit = (*pIt)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                if ( pervasiveChildTest.unitMapsToRightTargetType(unit) )
                {
                    candidateTarget = (*pIt);
                    break;
                }
            }

            if(candidateTarget == nullptr)
            {
                TS_FAIL("test_fapi2GetChildren:: candidateTarget not found");
                numFails++;
                break;
            }

            l_targetHuid = TARGETING::get_huid(candidateTarget);

            Target<fapi2::TARGET_TYPE_PERV> fapi2_pervTarget(
                candidateTarget);

            l_actualSize = pervasiveChildTest.actualSize(fapi2_pervTarget);

            if(l_actualSize != l_expectedSize)
            {
                TS_FAIL("test_fapi2GetChildren:: children of pervasive mismatch");
                numFails++;
                break;
            }

        }

        // Uncomment to test compile fails
        // std::vector<Target<fapi2::TARGET_TYPE_PROC_CHIP> > l_childProcs;
        // l_childProcs = fapi2_procTarget.getChildren<
        //     fapi2::TARGET_TYPE_PROC_CHIP>(TARGET_STATE_PRESENT);
        // l_childCores = fapi2_mcsTarget.getChildren<
        //     fapi2::TARGET_TYPE_CORE>(TARGET_STATE_PRESENT);

    }while(0);

    if(l_actualSize != l_expectedSize)
    {
        /*@
        * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_TEST
        * @reasoncode         fapi2::RC_INVALID_CHILD_COUNT
        * @userdata1[0:31]    Expected Child Count
        * @userdata1[32:63]   Actual Child Count
        * @userdata2          Parent HUID
        * @devdesc            Invalid amount of child cores found
        *                     on a proc
        */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_TEST,
                                        fapi2::RC_INVALID_CHILD_COUNT,
                                        TWO_UINT32_TO_UINT64(
                                        TO_UINT32(
                                        l_expectedSize),
                                        TO_UINT32(
                                        l_actualSize)),
                                        l_targetHuid,
                                        true/*SW Error*/);
        errlCommit(l_err,HWPF_COMP_ID);
        TS_FAIL("test_fapi2GetChildren Fail, for HUID: %d , expected %d children , found %d ", l_targetHuid,l_expectedSize,l_actualSize );
    }
    FAPI_INF("fapi2GetChildrenTest:: Test Complete. %d/%d fails",  numFails , numTests);
}

//******************************************************************************
// test_fapi2GetChildrenFilter
//******************************************************************************
void test_fapi2GetChildrenFilter()
{
    int numTests = 0;
    int numFails = 0;
    uint32_t l_targetHuid = 0xFFFFFFFF;
    uint32_t l_actualSize = 0;
    uint32_t l_expectedSize = 0;
    errlHndl_t l_err = nullptr;
    TARGETING::Target * l_proc = nullptr;
    TARGETING::TargetHandleList l_chipList;
    do
    {
        FAPI_DBG("start of test_fapi2GetChildrenFilter()");

        numTests++;
        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        if(l_chipList.size())
        {
            l_proc = l_chipList[0];
        }
        else
        {
            TS_FAIL("test_fapi2GetChildren Fail: could not find any proc, skipping tests");
            numFails++;
            break;
        }
        TARGETING::Target* targeting_targets[NUM_TARGETS];
        generateTargets(l_proc, targeting_targets);

        numTests++;
        for( uint64_t x = 0; x < NUM_TARGETS; x++ )
        {
            //Skip tests where the HW unit to test isn't valid for the proc type
            if (!isHwValid(l_proc, x))
            {
                continue;
            }
            else if(targeting_targets[x] == nullptr)
            {
              numFails++;
              TS_FAIL("test_fapi2GetChildrenFilter Fail: Unable to find target for item %d in targeting_targets", x);
              break;
            }
        }

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(
                l_proc);

        std::vector<Target<fapi2::TARGET_TYPE_PERV> > l_childPERVs;

        // Start of the Tests

        // PERV - TARGET_FILTER_ALL_CORES
        l_expectedSize = 24;
        l_childPERVs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>(
                                                             TARGET_FILTER_ALL_CORES,
                                                             TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childPERVs.size();
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            numFails++;
            break;
        }

        // PERV - TARGET_FILTER_CORE1
        l_expectedSize = 1;
        l_childPERVs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>(
                                                             TARGET_FILTER_CORE1,
                                                             TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childPERVs.size();
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            numFails++;
            break;
        }

        if (isHwValid(l_proc, MY_MC))
        {
            // PERV - TARGET_FILTER_ALL_MC
            l_expectedSize = 2;
            l_childPERVs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>(
                                                             TARGET_FILTER_ALL_MC,
                                                             TARGET_STATE_PRESENT);
            l_targetHuid = TARGETING::get_huid(l_proc) ;
            l_actualSize = l_childPERVs.size();
            numTests++;
            if(l_actualSize != l_expectedSize)
            {
                numFails++;
                break;
            }
        }

        // PERV - SYNC_MODE_ALL_IO_EXCEPT_NEST
        // NOTE:  2 of 4 OBUS are Cumulus only, so expect 8 instead of 10 returned
        l_expectedSize = 8;
        l_childPERVs = fapi2_procTarget.getChildren<fapi2::TARGET_TYPE_PERV>(
                                                             TARGET_FILTER_SYNC_MODE_ALL_IO_EXCEPT_NEST,
                                                             TARGET_STATE_PRESENT);
        l_targetHuid = TARGETING::get_huid(l_proc) ;
        l_actualSize = l_childPERVs.size();
        numTests++;
        if(l_actualSize != l_expectedSize)
        {
            numFails++;
            break;
        }

    }while(0);

    if(l_actualSize != l_expectedSize)
    {
        /*@
        * @errortype          ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid           fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_FILTER_TEST
        * @reasoncode         fapi2::RC_INVALID_CHILD_COUNT
        * @userdata1[0:31]    Expected Child Count
        * @userdata1[32:63]   Actual Child Count
        * @userdata2          Parent HUID
        * @devdesc            Invalid amount of child cores found
        *                     on a proc
        */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        fapi2::MOD_FAPI2_PLAT_GET_CHILDREN_FILTER_TEST,
                                        fapi2::RC_INVALID_CHILD_COUNT,
                                        TWO_UINT32_TO_UINT64(
                                        TO_UINT32(
                                        l_expectedSize),
                                        TO_UINT32(
                                        l_actualSize)),
                                        l_targetHuid,
                                        true/*SW Error*/);
        errlCommit(l_err,HWPF_COMP_ID);
        TS_FAIL("test_fapi2GetChildrenFilter Fail, for HUID: 0x%X , expected %d children , found %d ", l_targetHuid,l_expectedSize,l_actualSize );
    }

    FAPI_INF("test_fapi2GetChildrenFilter: Test Complete. %d/%d fails",  numFails , numTests);
}

//******************************************************************************
// test_fapi2GetChildrenFilter
// Currently only test DIMM aspects of interface
//******************************************************************************
void test_fapi2getChildTargetsForCDG()
{
    int numTests = 0;
    int numFails = 0;
    TARGETING::Target * l_proc = nullptr;
    size_t l_expectedDimms = 0;
    TARGETING::TargetHandleList l_chipList;
// These port and socket arguments are not valid for Axone targets
#ifndef CONFIG_AXONE
    size_t l_expectedDimmsUnderPort0 = 0;
    size_t l_expectedDimmsUnderPort1 = 0;
#endif
    do
    {
        FAPI_DBG("start of test_fapi2getChildTargetsForCDG()");

        numTests++;
        // Get a list of all of the proc chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_PROC, false);

        if(l_chipList.size())
        {
            l_proc = l_chipList[0];
        }
        else
        {
            TS_FAIL("test_fapi2getChildTargetsForCDG Fail: could not find any proc, skipping tests");
            numFails++;
            break;
        }

        if (l_proc->getAttr<TARGETING::ATTR_MODEL>() == TARGETING::MODEL_NIMBUS)
        {
            l_expectedDimms = 16;
// These port and socket arguments are not valid for Axone targets
#ifndef CONFIG_AXONE
            l_expectedDimmsUnderPort0 = l_expectedDimms;
            l_expectedDimmsUnderPort1 = 0;
#endif
        }
        else if (l_proc->getAttr<TARGETING::ATTR_MODEL>() == TARGETING::MODEL_CUMULUS)
        {
            l_expectedDimms = 8;
// These port and socket arguments are not valid for Axone targets
#ifndef CONFIG_AXONE
            l_expectedDimmsUnderPort0 = l_expectedDimms/2;
            l_expectedDimmsUnderPort1 = l_expectedDimms/2;
#endif
        }
        else if (l_proc->getAttr<TARGETING::ATTR_MODEL>() == TARGETING::MODEL_AXONE)
        {
            l_expectedDimms = 9;
        }
        else //both are nullptr
        {
            // Should never get here since error should have been returned
            // above
            TS_FAIL("fapi2getChildTargetsForCDG: Never Should Happen");
            numFails++;
            break;
        }

        Target<fapi2::TARGET_TYPE_PROC_CHIP> fapi2_procTarget(l_proc);
        // Now get all dimms under this processor
        TARGETING::TargetHandleList l_dimmList;
        fapi2::getChildTargetsForCDG(fapi2_procTarget,
                fapi2::TARGET_TYPE_DIMM,
                0xff,  // All ports
                0xff,  // All sockets
                l_dimmList);

        FAPI_INF("test_fapi2getChildTargetsForCDG: Dimms under proc 0x%.08X is %d",
                TARGETING::get_huid(l_proc),l_dimmList.size());
        numTests++;
        if(l_dimmList.size() != l_expectedDimms)
        {
            TS_FAIL("test_fapi2getChildTargetsForCDG: Dimm count %d not equal expected %d",
                    l_dimmList.size(),l_expectedDimms);
            numFails++;
        }

// These port and socket arguments are not valid for Axone targets
// so skip testing them
#ifndef CONFIG_AXONE
        // All dimms under port 0
        fapi2::getChildTargetsForCDG(fapi2_procTarget,
                fapi2::TARGET_TYPE_DIMM,
                0x0,   // Port 0
                0xff,  // All sockets
                l_dimmList);
        FAPI_INF("test_fapi2getChildTargetsForCDG: Dimms under proc 0x%.08X port 0 is %d",
                TARGETING::get_huid(l_proc),l_dimmList.size());
        numTests++;

        if(l_dimmList.size() != l_expectedDimmsUnderPort0)
        {
            TS_FAIL("test_fapi2getChildTargetsForCDG: Dimm count %d under port 0 not equal expected %d",
                    l_dimmList.size(),l_expectedDimmsUnderPort0);
            numFails++;
        }

        // All dimms under port 1
        fapi2::getChildTargetsForCDG(fapi2_procTarget,
                fapi2::TARGET_TYPE_DIMM,
                0x1,   // Port 1
                0xff,  // All sockets
                l_dimmList);
        FAPI_INF("test_fapi2getChildTargetsForCDG: Dimms under proc 0x%.08X port 1 is %d",
                TARGETING::get_huid(l_proc),l_dimmList.size());
        numTests++;

        if(l_dimmList.size() != l_expectedDimmsUnderPort1)
        {
            TS_FAIL("test_fapi2getChildTargetsForCDG: Dimm count %d under port 1 not equal expected %d",
                    l_dimmList.size(),l_expectedDimmsUnderPort1);
            numFails++;
        }

        // All dimms under socket 0
        fapi2::getChildTargetsForCDG(fapi2_procTarget,
                fapi2::TARGET_TYPE_DIMM,
                0xff,  // All ports
                0x0,   // Socket 0
                l_dimmList);
        FAPI_INF("test_fapi2getChildTargetsForCDG: Dimms under proc 0x%.08X socket 0 is %d",
                TARGETING::get_huid(l_proc),l_dimmList.size());
        numTests++;
        if(l_dimmList.size() != l_expectedDimms)
        {
            TS_FAIL("test_fapi2getChildTargetsForCDG: Dimm count %d under socket 0x0, all ports, not equal expected %d",
                    l_dimmList.size(),l_expectedDimms);
            numFails++;
        }

        // All dimms under socket 1
        fapi2::getChildTargetsForCDG(fapi2_procTarget,
                fapi2::TARGET_TYPE_DIMM,
                0xff,  // All ports
                0x1,   // Socket 1
                l_dimmList);
        FAPI_INF("test_fapi2getChildTargetsForCDG: Dimms under proc 0x%.08X socket 1 is %d",
                TARGETING::get_huid(l_proc),l_dimmList.size());
        numTests++;
        if(l_dimmList.size() != 0)
        {
            TS_FAIL("test_fapi2getChildTargetsForCDG: Dimm count %d under socket 1 not equal expected %d",
                    l_dimmList.size(),0);
            numFails++;
        }
#endif

    }while(0);

    FAPI_INF("test_fapi2getChildTargetsForCDG: Test Complete. %d/%d fails",  numFails , numTests);
}

};

} // namespace fapi2
