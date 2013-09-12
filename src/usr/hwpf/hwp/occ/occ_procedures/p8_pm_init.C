/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_init.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: p8_pm_init.C,v 1.20 2013/08/02 19:07:22 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
/// \file p8_pm_init.C
/// \brief Calls each PM unit initialization procedures with the control
///         parameter to process the respective phase:
///             config: use Platform Attributes to create an effective
///                     configuration using relevant Feature Attributes
///             init:   use the Feature attributes to initialize the hardware
///             reset:  call the "p8_pm_prep_reset" procedure to invoke a
///                     reset of the hardware to allow for reinitialization
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------
///
/// \version -------------------------------------------------------------------
/// \version 1.0 stillgs 2012/03/06 Initial Version
/// \version -------------------------------------------------------------------
///
///
/// \todo   Review
///
///
/// High-level procedure flow:
///
/// \verbatim
///     - call p8_pcbs_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_pmc_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_poreslw_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_poregpe_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_oha_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_pba_init.C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_occ_sram_init.C *chiptarget,mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_ocb_init .C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///     - call p8_pss_init .C *chiptarget, mode (PM_CONFIG, PM_INIT, PM_RESET)
///     - evaluate RC
///
///  \endverbatim
///
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_pm.H"
#include "p8_pm_init.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
  fapi::ReturnCode p8_pm_list(const Target& i_target, const Target& i_target2, uint32_t mode);

// ----------------------------------------------------------------------
// p8_pm_init
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pm_init(const fapi::Target &i_target1 ,const fapi::Target &i_target2 , uint32_t mode)
{

    fapi::ReturnCode l_fapi_rc;

    do
    {


        if (mode == PM_INIT)
        {
            FAPI_INF("Executing p8_pm_init in mode = PM_INIT ....\n") ;
        }
        if (mode == PM_CONFIG)
        {
            FAPI_INF("Executing p8_pm_init in mode = PM_CONFIG ....\n") ;
        }

        /// -------------------------------
        /// Configuration/Initialation
        if (mode == PM_CONFIG ||
            mode == PM_INIT ||
            mode == PM_RESET ||
            mode == PM_RESET_SOFT)
        {
            l_fapi_rc = p8_pm_list(i_target1, i_target2, mode);
            if (l_fapi_rc)
            {
                FAPI_ERR("ERROR: p8_pm_list detected failed ");
                break;
            }
        }
        /// -------------------------------
        /// Unsupported Mode
        else
        {
            FAPI_ERR("Unknown mode passed to p8_pm_init. Mode %x ....\n", mode);
            uint32_t & MODE = mode;
            FAPI_SET_HWP_ERROR(l_fapi_rc, RC_PROCPM_PMC_CODE_BAD_MODE); // proc_pmc_errors.xml
            break;
        }
    } while(0);

    return l_fapi_rc;
}


// ----------------------------------------------------------------------
// p8_pm_list - process the underlying routines in the prescribed order
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pm_list(const Target& i_target, const Target& i_target2, uint32_t mode)
{

    fapi::ReturnCode    rc;
    uint64_t            SP_WKUP_REG_ADDRS;
    uint8_t             l_ex_number = 0;
    ecmdDataBufferBase  data(64);
    uint32_t            effective_mode = 0;

    std::vector<fapi::Target>      l_exChiplets;

    FAPI_INF("Executing p8_pm_list in mode %x start", mode);

    do
    {
        if (mode == PM_RESET_SOFT || mode == PM_RESET)
        {
            effective_mode = PM_RESET;
            FAPI_DBG("A Reset mode is detected.  Setting effective reset for non-PMC procedures to PM_RESET (mode %x)",
                            effective_mode);
        }
        else
        {
             effective_mode = mode;
        }


        //  ******************************************************************
        //  PCBS_PM
        //  ******************************************************************

        FAPI_INF("Executing: p8_pcbs_init.C in mode %x", mode);

        if ( i_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pcbs_init, i_target, effective_mode);
            if (rc)
            {
              FAPI_ERR("ERROR: p8_pm_init detected failed PCBS_PM result");
              break;
            }
        }


        if ( i_target2.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pcbs_init, i_target2, effective_mode);
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed PCBS_PM result");
                break;
            }
        }
        //  ******************************************************************
        //  PMC
        //  ******************************************************************

        FAPI_INF("Executing: p8_pmc_init in mode %x", mode);

        FAPI_EXEC_HWP(rc, p8_pmc_init, i_target, i_target2, mode);
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_init detected failed PMC result");
            break;
        }

        //  ******************************************************************
        //  PORE Sleep/Winkle engine
        //  ******************************************************************

        // Run SLW for hard reset and hard init and any config. So as to not
        // touch the hardware, skip for soft reset and soft init.
        if (!(mode == PM_INIT_SOFT || mode == PM_RESET_SOFT ))
        {
            FAPI_INF("Executing: p8_poreslw_init in mode %x", mode);
            if ( i_target.getType() != TARGET_TYPE_NONE )
            {
                FAPI_EXEC_HWP(rc, p8_poreslw_init, i_target, mode);
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_init detected failed PORE SLW result");
                    break;
                }
            }

            if ( i_target2.getType() != TARGET_TYPE_NONE )
            {
                FAPI_EXEC_HWP(rc, p8_poreslw_init, i_target2, mode);
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_init detected failed PORE SLW result");
                    break;
                }
            }
        }
        else
        {
            FAPI_INF("Skipping p8_poreslw_init for mode %x - either soft init or soft reset", mode);
        }
        //  ******************************************************************
        //  PORE General Purpose Engines
        //  ******************************************************************

        FAPI_INF("Executing: p8_poregpe_init in mode %x", effective_mode);

        if ( i_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_poregpe_init, i_target, effective_mode , GPEALL);
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed PORE GPE result");
                break;
            }
        }

        if ( i_target2.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_poregpe_init, i_target2, effective_mode , GPEALL);
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed PORE GPE result");
                break;
            }
        }
        //  ******************************************************************
        //  OHA
        //  ******************************************************************

        FAPI_INF("Executing: p8_oha_init in mode %x", effective_mode);

        if ( i_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_oha_init, i_target, effective_mode);
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OHA result");
                break;
            }
        }

        if ( i_target2.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_oha_init, i_target2, effective_mode);
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OHA result");
                break;
            }
        }

        //  ******************************************************************
        //  OCC-SRAM
        //  ******************************************************************


        FAPI_INF("Executing: p8_occ_sram_init in mode %x", effective_mode);

        if ( i_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_occ_sram_init, i_target, effective_mode );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCC-SRAM result");
                break;
            }
        }

        if ( i_target2.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_occ_sram_init, i_target2, effective_mode );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCC-SRAM result");
             break;
            }
        }

        //  ******************************************************************
        //  OCB
        //  ******************************************************************

        FAPI_INF("Executing: p8_ocb_init in mode %x", effective_mode);
        if ( i_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, effective_mode,OCB_CHAN0,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 0");
                break;
            }

            FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, effective_mode,OCB_CHAN1,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 1");
                break;
            }

            FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, effective_mode,OCB_CHAN2,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 2");
                break;
            }

            FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, effective_mode,OCB_CHAN3,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 0");
                break;
            }

        }

        if ( i_target2.getType() != TARGET_TYPE_NONE )
        {


            FAPI_EXEC_HWP(rc, p8_ocb_init, i_target2, effective_mode,OCB_CHAN0,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 0");
                break;
            }

            FAPI_EXEC_HWP(rc, p8_ocb_init, i_target2, effective_mode,OCB_CHAN1,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 1");
                break;
            }

            FAPI_EXEC_HWP(rc, p8_ocb_init, i_target2, effective_mode,OCB_CHAN2,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 2");
                break;
            }

            FAPI_EXEC_HWP(rc, p8_ocb_init, i_target2, effective_mode,OCB_CHAN3,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 0");
                break;
            }
        }


        //  ******************************************************************
        //  PSS
        //  ******************************************************************

        FAPI_INF("Executing:p8_pss_init in effective_mode %x", effective_mode);

        if ( i_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_EXEC_HWP(rc, p8_pss_init, i_target, effective_mode );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed PSS result");
                break;
            }
        }

        if ( i_target2.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pss_init, i_target2, effective_mode );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed PSS result");
                break;
            }
        }

        //  ******************************************************************
        //  PBA
        //  ******************************************************************

        FAPI_INF("Executing: p8_pba_init  in effective_mode %x", effective_mode);
        if ( i_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pba_init, i_target, effective_mode );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed PBA result");
                break;
            }
        }

        if ( i_target2.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pba_init, i_target2, effective_mode );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_init detected failed PBA result");
                break;
            }
        }

        if (effective_mode == PM_INIT)
        {
            //  ******************************************************************
            //  FIRINIT
            //  ******************************************************************


            FAPI_INF("Executing:p8_pm_firinit in effective_mode %x", mode);

            if ( i_target.getType() != TARGET_TYPE_NONE )
            {

                FAPI_EXEC_HWP(rc, p8_pm_firinit, i_target , mode );
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
                    break;
                }
            }

            if ( i_target2.getType() != TARGET_TYPE_NONE )
            {

                FAPI_EXEC_HWP(rc, p8_pm_firinit, i_target2 , mode );
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
                    break;
                }
            }

            //  ******************************************************************
            //  CPU_SPECIAL_WAKEUP switch off
            //  ******************************************************************

            if ( i_target.getType() != TARGET_TYPE_NONE )
            {
                rc = fapiGetChildChiplets (  i_target,
                                TARGET_TYPE_EX_CHIPLET,
                                l_exChiplets,
                                TARGET_STATE_FUNCTIONAL);
                if (rc)
                {
                    FAPI_ERR("Error from fapiGetChildChiplets!");
                    break;
                }

                FAPI_DBG("\tChiplet vector size  => %u ", l_exChiplets.size());

                // Iterate through the returned chiplets
                for (uint8_t j=0; j < l_exChiplets.size(); j++)
                {

                    // Build the SCOM address
                    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
                    FAPI_DBG("Running special wakeup on ex chiplet %d ", l_ex_number);

                    // Set special wakeup for EX
                    // Commented due to attribute errors
                    SP_WKUP_REG_ADDRS = PM_SPECIAL_WKUP_OCC_0x100F010C + (l_ex_number  * 0x01000000) ;
                    rc=fapiGetScom(i_target, SP_WKUP_REG_ADDRS , data);
                    if(rc)
                    {
                        break;
                    }
                    FAPI_DBG("  Before clear of SPWKUP_REG PM_SPECIAL_WKUP_OCC_(0x%08llx) => =>0x%16llx",  SP_WKUP_REG_ADDRS, data.getDoubleWord(0));

                    if (data.isBitSet(0))
                    {
                        rc = fapiSpecialWakeup(l_exChiplets[j], false);
                        if (rc)
                        {
                            FAPI_ERR("p8_cpu_special_wakeup: Failed to put CORE into special wakeup. With rc = 0x%x", (uint32_t)rc);
                            break;
                        }
                    }
                }  // chiplet loop
                if (!rc.ok())
                {
                    break;
                }
            }  // Master target

            ///////////////////////////////////////////// SLAVE TARGET /////////////////////////////////////////////////


            if ( i_target2.getType() != TARGET_TYPE_NONE )
            {
                rc = fapiGetChildChiplets (  i_target2,
                                  TARGET_TYPE_EX_CHIPLET,
                                  l_exChiplets,
                                  TARGET_STATE_FUNCTIONAL);
                if (rc)
                {
                  FAPI_ERR("Error from fapiGetChildChiplets!");
                  break;
                }

                FAPI_DBG("\tChiplet vector size  => %u ", l_exChiplets.size());

                // Iterate through the returned chiplets
                for (uint8_t j=0; j < l_exChiplets.size(); j++)
                {

                    // Build the SCOM address
                    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
                    if (rc)
                    {
                        FAPI_ERR("Error from ATTR_GET for chip position!");
                        break;
                    }
                    FAPI_DBG("Running special wakeup on ex chiplet %d ", l_ex_number);

                    // Set special wakeup for EX
                    // Commented due to attribute errors
                    SP_WKUP_REG_ADDRS = PM_SPECIAL_WKUP_OCC_0x100F010C + (l_ex_number  * 0x01000000) ;
                    rc=fapiGetScom(i_target2, SP_WKUP_REG_ADDRS , data);
                    if(rc)
                    {
                        FAPI_ERR("Error from GetScom of OCC SPWKUP");
                        break;
                    }
                    FAPI_DBG("  Before clear of SPWKUP_REG PM_SPECIAL_WKUP_OCC_(0x%08llx) => =>0x%16llx",  SP_WKUP_REG_ADDRS, data.getDoubleWord(0));

                    if (data.isBitSet(0))
                    {
                        rc = fapiSpecialWakeup(l_exChiplets[j], false);
                        if (rc)
                        {
                            FAPI_ERR("p8_cpu_special_wakeup: Failed to put CORE into special wakeup. With rc = 0x%x", (uint32_t)rc);
                            break;
                        }
                    }
                }  // chiplet loop
                if (!rc.ok())
                {
                    break;
                }
            } // Slave target
        } // PM_INIT special stuff
    } while(0);

    FAPI_INF("Executing p8_pm_list in mode %x end", mode);

    return rc;

}

} //end extern C

