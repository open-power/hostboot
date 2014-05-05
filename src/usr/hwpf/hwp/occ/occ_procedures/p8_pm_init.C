/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_init.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: p8_pm_init.C,v 1.26 2014/05/02 12:25:37 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *! BACKUP NAME: Greg Still        Email: stillgs@us.ibm.com
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
// *| buildfapiprcd -C p8_pm_utils.C p8_pm_init.C
//------------------------------------------------------------------------------
///
/// \version -------------------------------------------------------------------
/// \version 1.0 stillgs 2012/03/06 Initial Version
/// \version -------------------------------------------------------------------
///
/// \verbatim
///
/// High-level procedure flow:
///     - call p8_pm_prep_for_reset to prepare and perform getting the PM function
///         able to be be (re)initialized
///
///     - call pm_list() to process the individual units in turn
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
#include "p8_pm_utils.H"
#include "p8_pm_init.H"
#include "p8_pm_prep_for_reset.H"

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

fapi::ReturnCode 
pm_list(const Target& i_target, const Target& i_target2, uint32_t i_mode);

fapi::ReturnCode
clear_occ_special_wakeups (const fapi::Target &i_target);

  
// ----------------------------------------------------------------------
// p8_pm_init
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pm_init(const fapi::Target &i_target1 ,const fapi::Target &i_target2 , uint32_t mode)
{

    fapi::ReturnCode    rc;
    uint32_t            int_mode;

    do
    {

        int_mode = PM_RESET;
        FAPI_EXEC_HWP(rc, p8_pm_prep_for_reset, i_target1, i_target2, int_mode);
        if (rc)
        {
          FAPI_ERR("ERROR: p8_pm_init detected failed p8_pm_prep_for_reset result");
          break;
        }

        int_mode = PM_CONFIG;
        rc = pm_list(i_target1, i_target2, int_mode);
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_list PM_CONFIG detected failed ");
            break;
        }

        int_mode = PM_INIT;      
        rc = pm_list(i_target1, i_target2, int_mode);
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_list PM_INIT detected failed ");
            break;
        }

    } while(0);

    return rc;
}

// ----------------------------------------------------------------------
// ocb_channel_reset - Reset each of the OCB channels on the passed target
// ----------------------------------------------------------------------

fapi::ReturnCode
ocb_channel_reset(const Target& i_target, uint32_t i_mode)
{
    fapi::ReturnCode rc;
    
    do
    {
        FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, i_mode, OCB_CHAN0,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_p8_pm_init detected failed OCB result on channel 0");
            break;
        }

        FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, i_mode, OCB_CHAN1,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 1");
            break;
        }

        FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, i_mode, OCB_CHAN2,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 2");
            break;
        }

        FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, i_mode,OCB_CHAN3,OCB_TYPE_NULL, 0x10000000, 1 , OCB_Q_OUFLOW_EN , OCB_Q_ITPTYPE_NOTFULL   );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_init detected failed OCB result on channel 3");
            break;
        }
    } while(0);
    return rc;
}

// ----------------------------------------------------------------------
// ocb_channel_init - Initialize the OCB channels as TGMT expects them --- 
// ----------------------------------------------------------------------

fapi::ReturnCode
ocb_channel_init(const Target& i_target)
{
    fapi::ReturnCode rc;
    
    do
    {
        FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, PM_SETUP_PIB, OCB_CHAN0, OCB_TYPE_LINSTR, 0, 0, OCB_Q_OUFLOW_EN, OCB_Q_ITPTYPE_NULL );
        if (rc)
        {
            FAPI_ERR("ERROR: ocb_channel_init detected a failed p8_ocb_init on channel 0");
            break;
        }

        FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, PM_SETUP_PIB, OCB_CHAN1, OCB_TYPE_PUSHQ, 0, 0, OCB_Q_OUFLOW_EN, OCB_Q_ITPTYPE_NULL );
        if (rc)
        {
            FAPI_ERR("ERROR: ocb_channel_init detected a failed p8_ocb_init on channel 1");
            break;
        }

        FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, PM_SETUP_PIB, OCB_CHAN2, OCB_TYPE_LIN, 0, 0, OCB_Q_OUFLOW_NULL, OCB_Q_ITPTYPE_NULL );
        if (rc)
        {
            FAPI_ERR("ERROR: ocb_channel_init detected a failed p8_ocb_init on channel 2");
            break;
        }

        FAPI_EXEC_HWP(rc, p8_ocb_init, i_target, PM_SETUP_PIB, OCB_CHAN3, OCB_TYPE_LINSTR, 0, 0, OCB_Q_OUFLOW_EN, OCB_Q_ITPTYPE_NULL );
        if (rc)
        {
            FAPI_ERR("ERROR: ocb_channel_init detected a failed p8_ocb_init on channel 3");
            break;
        }
    } while(0);
    return rc;        
    
}

// ----------------------------------------------------------------------
// pm_list - process the underlying routines in the prescribed order
// ----------------------------------------------------------------------

fapi::ReturnCode
pm_list(const Target& i_target, const Target& i_target2, uint32_t i_mode)
{

    fapi::ReturnCode    rc;
    ecmdDataBufferBase  data(64);
    uint32_t            effective_mode = 0;
    const char *        PM_MODE_NAME_VAR; // Defines storage for PM_MODE_NAME

    std::vector<fapi::Target>      l_exChiplets;

    FAPI_INF("p8_pm_list start in mode %s", PM_MODE_NAME(i_mode));


    do
    {
        if (i_mode == PM_RESET_SOFT || i_mode == PM_RESET)
        {
            effective_mode = PM_RESET;
            FAPI_DBG("A Reset mode is detected.  Setting effective reset for non-PMC procedures to PM_RESET (mode %x)",
                            effective_mode);
        }
        else
        {
             effective_mode = i_mode;
        }


        //  ******************************************************************
        //  PCBS_PM
        //  ******************************************************************

        FAPI_INF("Executing: p8_pcbs_init.C in mode %s", PM_MODE_NAME(effective_mode));

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

        FAPI_INF("Executing: p8_pmc_init in mode %s", PM_MODE_NAME(i_mode));

        FAPI_EXEC_HWP(rc, p8_pmc_init, i_target, i_target2, i_mode);
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
        // if (!(mode == PM_INIT_SOFT || mode == PM_RESET_SOFT ))
//         {
//             FAPI_INF("Executing: p8_poreslw_init in mode %x", mode);
//             if ( i_target.getType() != TARGET_TYPE_NONE )
//             {
//                 FAPI_EXEC_HWP(rc, p8_poreslw_init, i_target, mode);
//                 if (rc)
//                 {
//                     FAPI_ERR("ERROR: p8_pm_init detected failed PORE SLW result");
//                     break;
//                 }
//             }
// 
//             if ( i_target2.getType() != TARGET_TYPE_NONE )
//             {
//                 FAPI_EXEC_HWP(rc, p8_poreslw_init, i_target2, mode);
//                 if (rc)
//                 {
//                     FAPI_ERR("ERROR: p8_pm_init detected failed PORE SLW result");
//                     break;
//                 }
//             }
//         }
//         else
//         {
//             FAPI_INF("Skipping p8_poreslw_init for mode %x - either soft init or soft reset", mode);
//         }
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

        // FAPI_INF("Executing: p8_oha_init in mode %s", PM_MODE_NAME(effective_mode));
        //          
        // if ( i_target.getType() != TARGET_TYPE_NONE )
        // {
        //     FAPI_EXEC_HWP(rc, p8_oha_init, i_target, effective_mode);
        //     if (rc)
        //     {
        //         FAPI_ERR("ERROR: p8_pm_init detected failed OHA result");
        //         break;
        //     }
        // }
        //
        // if ( i_target2.getType() != TARGET_TYPE_NONE )
        // {
        //     FAPI_EXEC_HWP(rc, p8_oha_init, i_target2, effective_mode);
        //     if (rc)
        //     {
        //         FAPI_ERR("ERROR: p8_pm_init detected failed OHA result");
        //         break;
        //     }
        // }

        //  ******************************************************************
        //  OCC-SRAM
        //  ******************************************************************


        FAPI_INF("Executing: p8_occ_sram_init in mode %s", PM_MODE_NAME(effective_mode));

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

        FAPI_INF("Executing: p8_ocb_init in mode %s", PM_MODE_NAME(effective_mode));
        if ( i_target.getType() != TARGET_TYPE_NONE )
        {
            if (effective_mode == PM_RESET)
            {
                rc = ocb_channel_reset(i_target, effective_mode);
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_init detected ocb_channel_reset error");
                    break;
                }
            }
            else if (effective_mode == PM_INIT)
            {
                rc = ocb_channel_init(i_target);
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_init detected ocb_channel_init error");
                    break;
                }                       
            }
        }

        if ( i_target2.getType() != TARGET_TYPE_NONE )
        {
            if (effective_mode == PM_RESET)
            {
                rc = ocb_channel_reset(i_target2, effective_mode);
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_init detected ocb_channel_reset error");
                    break;
                }
            }
            else if (effective_mode == PM_INIT)
            {
                rc = ocb_channel_init(i_target2);
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_init detected ocb_channel_init error");
                    break;
                }                       
            }
        }


        //  ******************************************************************
        //  PSS
        //  ******************************************************************

        FAPI_INF("Executing:p8_pss_init in effective_mode %s", PM_MODE_NAME(effective_mode));

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

        FAPI_INF("Executing: p8_pba_init  in effective_mode %s", PM_MODE_NAME(effective_mode));
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


            FAPI_INF("Executing:p8_pm_firinit in effective_mode %s", PM_MODE_NAME(i_mode));

            if ( i_target.getType() != TARGET_TYPE_NONE )
            {

                FAPI_EXEC_HWP(rc, p8_pm_firinit, i_target , i_mode );
                if (rc)
                {
                    FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
                    break;
                }
            }

            if ( i_target2.getType() != TARGET_TYPE_NONE )
            {

                FAPI_EXEC_HWP(rc, p8_pm_firinit, i_target2 , i_mode );
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
                rc = clear_occ_special_wakeups (i_target);
                if (!rc.ok())
                {
                    break;
                }
            } 

            if ( i_target2.getType() != TARGET_TYPE_NONE )
            {
                rc = clear_occ_special_wakeups (i_target2);
                if (!rc.ok())
                {
                    break;
                }                  
            } 
                        
        } // PM_INIT special stuff
        
        //  Check for xstops and recoverables
        rc = p8_pm_glob_fir_trace (i_target, "end of p8_pm_init_list");
        if (!rc.ok()) 
        {
            break;
        }  

    } while(0);

    FAPI_INF("p8_pm_list end in mode %s", PM_MODE_NAME(i_mode));
    return rc;

}

/**
 * clear_occ_special_wakeups - clears OCC special wake-up on all configured EXs
 *
 * @param[in] i_target   Chip target w
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
clear_occ_special_wakeups (const fapi::Target &i_target)
{
    fapi::ReturnCode                rc;
    uint32_t                        e_rc = 0; 
    uint64_t                        SP_WKUP_REG_ADDRS;
    ecmdDataBufferBase              data(64);   
    std::vector<fapi::Target>       l_exChiplets;
    uint8_t                         l_ex_number = 0;    
    
    do
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
            rc = FAPI_ATTR_GET( ATTR_CHIP_UNIT_POS, 
                                &l_exChiplets[j], 
                                l_ex_number);
            if (rc)
            {
                FAPI_ERR("Error from ATTR_GET for chip position!");
                break;
            }
            FAPI_DBG("Clearing OCC special wakeup on ex chiplet %d ", 
                                l_ex_number);
                        
            e_rc |= data.flushTo0();
            E_RC_CHECK(e_rc, rc);
            
            SP_WKUP_REG_ADDRS = PM_SPECIAL_WKUP_OCC_0x100F010C + 
                                (l_ex_number  * 0x01000000) ;
            
            PUTSCOM(rc, i_target, SP_WKUP_REG_ADDRS, data);
            
        }  // chiplet loop
        if (!rc.ok())
        {
            break;
        }
    } while(0);
    return rc;
}


} //end extern C

