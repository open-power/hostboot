/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_prep_for_reset.C $  */
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
// $Id: p8_pm_prep_for_reset.C,v 1.18 2013/04/12 01:28:32 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_prep_for_reset.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Ralf Maier         Email: ralf.maier@de.ibm.com
// *!
/// \file p8_pm_prep_for_reset.C
/// \brief Initialize powermanagement
/// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------
///
///
///
/// \version --------------------------------------------------------------------------
/// \version 1.5  rmaier 09/19/12 Added review feedback
/// \version --------------------------------------------------------------------------
/// \version 1.4  rmaier 09/17/12 Fixed error when calling p8_ocb_init.C.
/// \version --------------------------------------------------------------------------
/// \version 1.1  rmaier 08/23/12 Renaming proc_ to p8_
/// \version --------------------------------------------------------------------------
/// \version 1.3 rmaier 2012/07/17 Added review feedback
/// \version --------------------------------------------------------------------------
/// \version 1.2 rmaier 2012/03/13 Added return code handling
/// \version --------------------------------------------------------------------------
/// \version 1.1 rmaier 2012/02/28 Added calls to subroutines
/// \version --------------------------------------------------------------------------
/// \version 1.0 rmaier 2012/02/01 Initial Version
/// \version ---------------------------------------------------------------------------
///
/// High-level procedure flow:
///
/// \verbatim
///
///
///     - call p8_occ_control.C *chiptarget, ENUM:OCC_STOP      ppc405_reset_ctrl = 2
///             - OCC PPC405 put into reset
///             - PMC moves to Vsafe value due to heartbeat loss
///
///     - evaluate RC
///
///     - call p8_cpu_special_wakeup.C  *chiptarget, ENUM:OCC_SPECIAL_WAKEUP
///             - For each chiplet,  put into Special Wake-up via the OCC special wake-up bit
///
///     - evaluate RC
///
///     - call p8_pmc_force_vsafe.C  *chiptarget,
///                    - Forces the Vsafe value into the voltage controller
///
///     - evaluate RC
///
///     - call p8_pcbs_init.C *chiptarget, ENUM:PCBSPM_RESET
///
///     - evaluate RC
///
///     - call p8_pmc_init.C *chiptarget, ENUM:PMC_RESET
///             - Issue reset to the PMC
///
///     - evaluate RC
///
///     - call p8_poresw_init.C *chiptarget, ENUM:PORESLW_RESET
///
///     - evaluate RC
///
///     - call p8_poregpe_init.C *chiptarget, ENUM:POREGPE_RESET
///
///     - evaluate RC
///
///     - call p8_oha_init.C *chiptarget, ENUM:OHA_RESET
///
///     - evaluate RC
///
///     - call p8_pba_init.C *chiptarget, ENUM:PBA_RESET
///
///     - evaluate RC
///
///     - call p8_occ_sram_init.C *chiptarget, ENUM:OCC_SRAM_RESET
///
///     - evaluate RC
///
///     - call p8_ocb_init .C *chiptarget, ENUM:OCC_OCB_RESET
///     - evaluate RC
///
///
///  \endverbatim
///


//------------------------------------------------------------------------------
//----------------------------------------------------------------------
//  eCMD Includes
//----------------------------------------------------------------------
#include <ecmdDataBufferBase.H>

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pm_prep_for_reset.H"
#include "p8_cpu_special_wakeup.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------
// Address definition for chiplet EX01 with base address 0x10000000
//       Example: getscom pu.ex 10000001 -c3   ---> scom address 0x13000001

CONST_UINT64_T( EX_PMGP0_0x150F0100                                             , ULL(0x150F0100) );

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------
// \temporary
fapi::ReturnCode corestat(const fapi::Target& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

/// i_primary_chip_target       Primary Chip target which will be passed
///                             to all the procedures
/// i_secondary_chip_target     Secondary Chip target will be passed for
///                             pmc_init -reset only if it is DCM otherwise
///                             this should be NULL.

fapi::ReturnCode
p8_pm_prep_for_reset(   const fapi::Target &i_primary_chip_target ,
                        const fapi::Target &i_secondary_chip_target  )
{

// Procedures executed in this file
///   FAPI_EXEC_HWP(rc, p8_occ_control, i_primary_chip_target, PM_RESET, 0);
///   FAPI_EXEC_HWP(rc, proc_cpu_special_wakeup, l_exChiplets[j], SPCWKUP_ENABLE , HOST);
///   FAPI_EXEC_HWP(rc, p8_pmc_force_vsafe, i_primary_chip_target);
///   FAPI_EXEC_HWP(rc, p8_pcbs_init, i_primary_chip_target, PM_RESET);
///   FAPI_EXEC_HWP(rc, p8_pmc_init, i_primary_chip_target, i_secondary_chip_target, PM_RESET);
///   FAPI_EXEC_HWP(rc, p8_poreslw_init, i_primary_chip_target, PM_RESET);
///   FAPI_EXEC_HWP(rc, p8_poregpe_init, i_primary_chip_target, PM_RESET, GPEALL );
///   FAPI_EXEC_HWP(rc, p8_oha_init, i_primary_chip_target, PM_RESET );
///   FAPI_EXEC_HWP(rc, p8_pba_init, i_primary_chip_target, PM_RESET );
///   FAPI_EXEC_HWP(rc, p8_occ_sram_init, i_primary_chip_target, PM_RESET );
///   FAPI_EXEC_HWP(rc, p8_ocb_init, i_primary_chip_target, PM_RESET,0 , 0, 0, 0, 0, 0 );



    fapi::ReturnCode rc;
    uint8_t                         l_functional = 0;
    uint8_t                         l_ex_number = 0;

    std::vector<fapi::Target>       l_exChiplets;
    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              mask(64);

    //    std::vector<fapi::Target>   l_chiplets;
    fapi::Target dummy;

    do
    {
    
        FAPI_INF("Executing p8_pm_prep_for_reset  ....");
        
        if ( i_secondary_chip_target.getType() == TARGET_TYPE_NONE )
        {
            if ( i_primary_chip_target.getType() == TARGET_TYPE_NONE )
            {
                FAPI_ERR("Set primay target properly for SCM " ) ;
                FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PREP_TARGET_ERR); 
                break;
            }
            FAPI_DBG("Running on SCM");
        }
        else
        {
            FAPI_DBG("Running on DCM");
        }
        
        //  ******************************************************************
        //  Mask the FIRs
        //  ******************************************************************

        FAPI_INF("Executing:p8_pm_firinit in mode PM_RESET");

        FAPI_EXEC_HWP(rc, p8_pm_firinit, i_primary_chip_target , PM_RESET );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
            break;
        }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_EXEC_HWP(rc, p8_pm_firinit, i_secondary_chip_target , PM_RESET );
            if (rc)
            {
                FAPI_ERR("ERROR: p8_pm_firinit detected failed  result");
                break;
            }
        }


        //  ******************************************************************
        //  Put OCC PPC405 into reset
        //  ******************************************************************
        //  ******************************************************************
        //  - call p8_occ_control.C *chiptarget, ENUM:OCC_STOP      ppc405_reset_ctrl = 2s
        //
        //  ******************************************************************

        FAPI_INF("Put OCC PPC405 into reset");
        FAPI_DBG("Executing: p8_occ_control.C");

        FAPI_EXEC_HWP(rc, p8_occ_control, i_primary_chip_target, PPC405_RESET_ON, 0);
        if (rc)
        {
            FAPI_ERR("p8_occ_control: Failed to prepare OCC for RESET. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_occ_control, i_secondary_chip_target, PPC405_RESET_ON, 0);
            if (rc)
            {
              FAPI_ERR("p8_occ_control: Failed to prepare OCC for RESET. With rc = 0x%x", (uint32_t)rc);
              break;
            }

    //        rc = fapiGetScom( i_secondary_chip_target, EX_PMGP0_0x150F0100  , data);
    //        if (rc)
    //        {
    //            FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //            break;
    //        }
    //        FAPI_DBG(" EX_PMGP0_0x150F0100 secondary =   %016llX",  data.getDoubleWord(0) );
        }

        //  ******************************************************************
        //  Put all EX chiplet special wakeup
        //  ******************************************************************
        //     - call proc_cpu_special_wakeup.C  *chiptarget, ENUM:OCC_SPECIAL_WAKEUP
        //             - For each chiplet,  put into Special Wake-up via the OCC special wake-up bit

        //////////////////////// PRIMARY TARGET ////////////////////////////////
        rc = fapiGetChildChiplets (  i_primary_chip_target,
                                     TARGET_TYPE_EX_CHIPLET,
                                     l_exChiplets,
                                     TARGET_STATE_PRESENT);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetChildChiplets!");
            break;
        }

        FAPI_DBG("Number of EX chiplet on primary  => %u ", l_exChiplets.size());

         // Iterate through the returned chiplets
        for (uint8_t j=0; j < l_exChiplets.size(); j++)
        {

            // Determine if it's functional
            rc = FAPI_ATTR_GET( ATTR_FUNCTIONAL,
                                &l_exChiplets[j],
                                l_functional);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error");
                break;
            }

            if ( l_functional )
            {
                // The ex is functional let's build the SCOM address
                rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
                FAPI_DBG("Running special wakeup on ex chiplet %d ", l_ex_number);

                // Set special wakeup for EX
                // Commented due to attribute errors
                //FAPI_EXEC_HWP(rc, proc_cpu_special_wakeup, l_exChiplets[j], SPCWKUP_ENABLE , HOST);
                rc = fapiSpecialWakeup(l_exChiplets[j], true);
                if (rc) 
                { 
                    FAPI_ERR("fapiSpecialWakeup: Failed to put CORE %d into special wakeup. With rc = 0x%x",  l_ex_number, (uint32_t)rc);  
                    break;    
                }

            }
        }  // chiplet loop
        
        // Exit if error
        if  (!rc.ok())
        {
            break;
        }


    //    rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
    //    if (rc)
    //    {
    //        FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //        break;
    //    }
    //
    //    FAPI_DBG(" EX_PMGP0_0x150F0100_prim =   %016llX",  data.getDoubleWord(0) );

        //////////////////////// SECONDARY TARGET ////////////////////////////////
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            rc = fapiGetChildChiplets ( i_secondary_chip_target,
                                        TARGET_TYPE_EX_CHIPLET,
                                        l_exChiplets,
                                        TARGET_STATE_PRESENT);
            if (rc)
            {
              FAPI_ERR("Error from fapiGetChildChiplets!");
              break;
            }

            FAPI_DBG("Number of EX chiplet on secondary  => %u ", l_exChiplets.size());

            // Iterate through the returned chiplets
            for (uint8_t j=0; j < l_exChiplets.size(); j++)
            {

                // Determine if it's functional
                rc = FAPI_ATTR_GET(  ATTR_FUNCTIONAL,
                         &l_exChiplets[j],
                         l_functional);
                if (rc)
                {
                    FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error");
                    break;
                }

                if ( l_functional )
                {
                    // The ex is functional
                    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
                    FAPI_DBG("Running special wakeup on EX chiplet %d ", l_ex_number);

                    // Set special wakeup for EX
                    // Commented due to attribute errors
                    //FAPI_EXEC_HWP(rc, proc_cpu_special_wakeup, l_exChiplets[j], SPCWKUP_ENABLE , HOST);
                    rc = fapiSpecialWakeup(l_exChiplets[j], true);
                    if (rc) 
                    { 
                        FAPI_ERR("fapiSpecialWakeup: Failed to put CORE %d into special wakeup. With rc = 0x%x",  l_ex_number, (uint32_t)rc);  
                        break;    
                    }
                }
            }  // chiplet loop
            
            // Exit if error
            if  (!rc.ok())
            {
                break;
            }


    //        rc = fapiGetScom( i_secondary_chip_target, EX_PMGP0_0x150F0100  , data);
    //        if (rc)
    //        {
    //            FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //            break;
    //        }
    //
    //        FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        }

        //  ******************************************************************
        //  Force Vsafe value into voltage controller
        //  ******************************************************************
        //     - call p8_pmc_force_vsafe.C  *chiptarget,
        //                    - Forces the Vsafe value into the voltage controller
        //

        FAPI_INF("Force Vsafe value into voltage controller");
        FAPI_DBG("Executing: p8_pmc_force_vsafe.C");

        //////////////////////// PRIMARY TARGET ////////////////////////////////

        FAPI_EXEC_HWP(rc, p8_pmc_force_vsafe, i_primary_chip_target);
        if (rc)
        {
            FAPI_ERR("Failed to force Vsafe value into voltage controller. With rc = 0x%x", (uint32_t)rc);
            FAPI_ERR("Contining with reset of Power Management functions");

            //break;
        }

//        rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
//        if (rc)
//        {
//            FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
//            break;
//        }
//        FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );


        //////////////////////// SECONDARY TARGET ////////////////////////////////
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pmc_force_vsafe, i_secondary_chip_target);
            if (rc)
            {
              FAPI_ERR("Failed to force Vsafe value into voltage controller. With rc = 0x%x", (uint32_t)rc);
              FAPI_ERR("Contining with reset of Power Management functions");

              //break;
            }

    //        rc = fapiGetScom( i_secondary_chip_target, EX_PMGP0_0x150F0100  , data);
    //        if (rc)
    //        {
    //          FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //          break;
    //        }
    //        FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );
        }

        //  ******************************************************************
        //  Prepare PCBSLV_PM for RESET
        //  ******************************************************************
        //      - call p8_pcbs_init.C *chiptarget, ENUM:PCBSPM_RESET
        //
        //      - p8_pcbs_init internally loops over all enabled chiplets

        FAPI_INF("Prepare PCBSLV_PM for RESET");
        FAPI_DBG("Executing: p8_pcbs_init.C");

        //////////////////////// PRIMARY TARGET ////////////////////////////////
        FAPI_EXEC_HWP(rc, p8_pcbs_init, i_primary_chip_target, PM_RESET);
        if (rc)
        {
            FAPI_ERR("p8_pcbs_init: Failed to prepare PCBSLV_PM for RESET. With rc = 0x%x", (uint32_t)rc);
            break;
        }

     // >>>>>  temp debug only <<<<<<
    //    rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
    //    if (rc)
    //    {
    //        FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //        break;
    //    }
    //    FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );


        //////////////////////// SECONDARY TARGET ////////////////////////////////

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_EXEC_HWP(rc, p8_pcbs_init, i_secondary_chip_target, PM_RESET);
            if (rc)
            {
              FAPI_ERR("p8_pcbs_init: Failed to prepare PCBSLV_PM for RESET. With rc = 0x%x", (uint32_t)rc);
              break;
            }

    // >>>>>  temp debug only <<<<<<
    //        rc = fapiGetScom( i_secondary_chip_target, EX_PMGP0_0x150F0100  , data);
    //        if (rc)
    //        {
    //          FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //          break;
    //        }
    //        FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        }

        //  ******************************************************************
        //  Reset PMC
        //  ******************************************************************
        //     - call p8_pmc_init.C *chiptarget, ENUM:PMC_RESET
        //

        FAPI_INF("Issue reset to PMC");
        FAPI_DBG("Executing: p8_pmc_init.C");

        FAPI_EXEC_HWP(rc, p8_pmc_init, i_primary_chip_target, i_secondary_chip_target, PM_RESET);
        if (rc)
        {
            FAPI_ERR("p8_pmc_init: Failed to issue PMC reset. With rc = 0x%x", (uint32_t)rc);
            break;
        }

    //    rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
    //    if (rc)
    //    {
    //        FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //        break;
    //    }
    //    FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        //  ******************************************************************
        //  Issue reset to PSS macro
        //  ******************************************************************
        //     - call p8_poreslw_init.C *chiptarget, ENUM:PORESLW_RESET
        //

        FAPI_INF("Issue reset to PSS macro");
        FAPI_DBG("Executing: p8_pss_init.C");

        //////////////////////// PRIMARY TARGET ////////////////////////////////
        FAPI_EXEC_HWP(rc, p8_pss_init, i_primary_chip_target, PM_RESET);
        if (rc)
        {
            FAPI_ERR("p8_pss_init: Failed to issue reset to PSS macro. With rc = 0x%x", (uint32_t)rc);
            break;
        }

    //    rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
    //    if (rc)
    //    {
    //        FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //        break;
    //    }
    //    FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );


        //////////////////////// SECONDARY TARGET ////////////////////////////////
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {

            FAPI_DBG("FAPI_EXEC_HWP(rc, p8_pss_init, i_secondary_chip_target, PM_RESET);");

            FAPI_EXEC_HWP(rc, p8_pss_init, i_secondary_chip_target, PM_RESET);
            if (rc)
            {
                FAPI_ERR("p8_pss_init: Failed to issue reset to PSS macro. With rc = 0x%x", (uint32_t)rc);
                break;
            }

    //        rc = fapiGetScom( i_secondary_chip_target, EX_PMGP0_0x150F0100  , data);
    //        if (rc)
    //        {
    //          FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //          break;
    //        }
    //        FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );
        }

        //  ******************************************************************
        //  Issue reset to PORE Sleep/Winkle engine
        //  ******************************************************************
        //     - call p8_poreslw_init.C *chiptarget, ENUM:PORESLW_RESET

        FAPI_INF("Issue reset to PORE Sleep/Winkle engine");
        FAPI_DBG("Executing: p8_poreslw_init.C");
        
        //////////////////////// PRIMARY TARGET ////////////////////////////////
        FAPI_EXEC_HWP(rc, p8_poreslw_init, i_primary_chip_target, PM_RESET);
        if (rc)
        {
            FAPI_ERR("p8_poreslw_init: Failed to issue reset to PORE Sleep/Winkle engine. With rc = 0x%x", (uint32_t)rc);
            break;
        }

    // >>>>>  temp debug only <<<<<<
    //    rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
    //    if (rc)
    //    {
    //        FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //        break;
    //    }
    //    FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        //////////////////////// SECONDARY TARGET ////////////////////////////////

        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_poreslw_init, i_secondary_chip_target, PM_RESET);
            if (rc)
            {
                FAPI_ERR("p8_poreslw_init: Failed to issue reset to PORE Sleep/Winkle engine. With rc = 0x%x", (uint32_t)rc);
                break;
            }

    // >>>>>  temp debug only <<<<<<
    //        rc = fapiGetScom( i_secondary_chip_target, EX_PMGP0_0x150F0100  , data);
    //        if (rc)
    //        {
    //            FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //            break;
    //        }
    //        FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        }

        //  ******************************************************************
        //  Issue reset to PORE General Purpose Engine
        //  ******************************************************************
        //     - call p8_poregpe_init.C *chiptarget, ENUM:POREGPE_RESET

        FAPI_INF("Issue reset to PORE General Purpose Engine");
        FAPI_DBG("Executing: p8_poregpe_init.C");

        //////////////////////// PRIMARY TARGET ////////////////////////////////
        FAPI_EXEC_HWP(rc, p8_poregpe_init, i_primary_chip_target, PM_RESET, GPEALL );
        if (rc)
        {
            FAPI_ERR("p8_poregpe_init: Failed to issue reset to PORE General Purpose Engine. With rc = 0x%x", (uint32_t)rc);
            break;
        }

    //    rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
    //    if (rc)
    //    {
    //        FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //        break;
    //    }
    //    FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        //////////////////////// SECONDARY TARGET ////////////////////////////////
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_poregpe_init, i_secondary_chip_target, PM_RESET, GPEALL );
            if (rc)
            {
                FAPI_ERR("p8_poregpe_init: Failed to issue reset to PORE General Purpose Engine. With rc = 0x%x", (uint32_t)rc);
                break;
            }

    //        rc = fapiGetScom( i_secondary_chip_target, EX_PMGP0_0x150F0100  , data);
    //        if (rc)
    //        {
    //            FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //            break;
    //        }
    //        FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );
        }

        //  ******************************************************************
        //  Issue reset to OHA
        //  ******************************************************************
    //     //     - call p8_oha_init.C *chiptarget, ENUM:OHA_RESET
    //     //
    //     FAPI_DBG("");
    //     // FAPI_DBG("*************************************");
    //     FAPI_INF("Issue reset to PORE General Purpose Engine");
    //     FAPI_DBG("Executing: p8_oha_init.C");
    //     // FAPI_DBG("*************************************");
    //     FAPI_DBG("FAPI_EXEC_HWP(rc, p8_oha_init, i_primary_chip_target, PM_RESET );");
    //     FAPI_DBG("");

    //     //
    //         FAPI_EXEC_HWP(rc, p8_oha_init, i_primary_chip_target, PM_RESET );
    //     if (rc)
    //     {
    //         FAPI_ERR("p8_oha_init: Failed to issue reset to OHA. With rc = 0x%x", (uint32_t)rc);
    //         break;
    //     }


    //     rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
    //     if (rc)
    //     {
    //         FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //         break;
    //     }
    //    FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        //  ******************************************************************
        //  Issue reset to PBA
        //  ******************************************************************
        //     - call p8_pba_init.C *chiptarget, ENUM:PBA_RESET
        //

        FAPI_INF("Issue reset to PBA");
        FAPI_DBG("Executing: p8_pba_init.C");

        //////////////////////// PRIMARY TARGET ////////////////////////////////
        FAPI_EXEC_HWP(rc, p8_pba_init, i_primary_chip_target, PM_RESET );
        if (rc)
        {
            FAPI_ERR("p8_pba_init: Failed to issue reset to PBA. With rc = 0x%x", (uint32_t)rc);
            break;
        }

    //    rc = fapiGetScom( i_primary_chip_target, EX_PMGP0_0x150F0100  , data);
    //    if (rc)
    //    {
    //        FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //        break;
    //    }
    //    FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        //////////////////////// SECONDARY TARGET ////////////////////////////////
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_pba_init, i_secondary_chip_target, PM_RESET );
            if (rc)
            {
                FAPI_ERR("p8_pba_init: Failed to issue reset to PBA. With rc = 0x%x", (uint32_t)rc);
                break;
            }

    //        rc = fapiGetScom( i_secondary_chip_target, EX_PMGP0_0x150F0100  , data);
    //        if (rc)
    //        {
    //            FAPI_ERR("fapiGetScom EX_PMGP0_0x150F0100 failed. With rc = 0x%x", (uint32_t)rc);
    //            break;
    //        }
    //        FAPI_DBG(" EX_PMGP0_0x150F0100 =   %016llX",  data.getDoubleWord(0) );

        }

        //  ******************************************************************
        //  Issue reset to OCC-SRAM
        //  ******************************************************************
        //     - call p8_occ_sram_init.C *chiptarget, ENUM:OCC_SRAM_RESET
        //

        FAPI_INF("Issue reset to OCC-SRAM");
        FAPI_DBG("Executing: p8_occ_sram_init.C");

        //////////////////////// PRIMARY TARGET ////////////////////////////////
        FAPI_EXEC_HWP(rc, p8_occ_sram_init, i_primary_chip_target, PM_RESET );
        if (rc)
        {
            FAPI_ERR("p8_occ_sram_init: Failed to issue reset to OCC-SRAM. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        //////////////////////// SECONDARY TARGET ////////////////////////////////
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_occ_sram_init, i_secondary_chip_target, PM_RESET );
            if (rc)
            {
                FAPI_ERR("p8_occ_sram_init: Failed to issue reset to OCC-SRAM. With rc = 0x%x", (uint32_t)rc);
                break;
            }
        }

        //  ******************************************************************
        //  Issue reset to OCB
        //  ******************************************************************
        //     - call p8_ocb_init.C *chiptarget, ENUM:OCC_OCB_RESET

        FAPI_INF("Issue reset to OCB");
        FAPI_DBG("Executing: p8_ocb_init.C");

        //////////////////////// PRIMARY TARGET ////////////////////////////////
        FAPI_EXEC_HWP(rc, p8_ocb_init, i_primary_chip_target, PM_RESET,0 , 0, 0, 0, 0, 0 );
        if (rc)
        {
            FAPI_ERR("p8_ocb_init: Failed to issue reset to OCB. With rc = 0x%x", (uint32_t)rc);
            break;
        }

        //////////////////////// SECONDARY TARGET ////////////////////////////////
        if ( i_secondary_chip_target.getType() != TARGET_TYPE_NONE )
        {
            FAPI_EXEC_HWP(rc, p8_ocb_init, i_secondary_chip_target, PM_RESET,0 , 0, 0, 0, 0, 0 );
            if (rc)
            {
                FAPI_ERR("p8_ocb_init: Failed to issue reset to OCB. With rc = 0x%x", (uint32_t)rc);
                break;
            }
        }

    } while(0);
    fapiDelay(300 , 3000 );

    FAPI_INF("Exiting p8_pm_prep_for_reset");
    
    return rc;
} // Procedure


//------------------------------------------------------------------------------
// Core Status
//------------------------------------------------------------------------------
fapi::ReturnCode
corestat(const fapi::Target& i_target) 
{
    fapi::ReturnCode rc;   
 
    ecmdDataBufferBase              data(64);
    
    std::vector<fapi::Target>       l_exChiplets;
    uint8_t                         l_functional = 0;
    uint8_t                         l_ex_number = 0;
    

    FAPI_INF("Core Status ...");
       
    rc = fapiGetChildChiplets ( i_target, 
                                TARGET_TYPE_EX_CHIPLET, 
                                l_exChiplets, 
                                TARGET_STATE_FUNCTIONAL);
	if (rc)
	{
	    FAPI_ERR("Error from fapiGetChildChiplets!");
	    return rc;
	}
    FAPI_DBG("Number of chiplets  => %u", l_exChiplets.size());
    
    // Iterate through the returned chiplets
    //for (itr = l_exChiplets.begin(); itr != l_exChiplets.end(); itr++) 
    for (uint8_t c=0; c < l_exChiplets.size(); c++)
    {
        // Determine if it's functional
        //rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, itr, l_functional);
        rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[c], l_functional);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error");
            break;
        }
        
        // With TARGET_STATE_FUNCTIONAL above, this check may be redundant
        if ( l_functional )
        {
            // Get the core number
            //rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, itr, c); 
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[c], l_ex_number);                  
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
                break;
            }

            FAPI_DBG("Processing core : %d ", l_ex_number);
    
            // Read register content
            
            rc = fapiGetScom( l_exChiplets[c], EX_PERV_SCRATCH0_10013283 , data );
            if (rc) 
            {
                FAPI_ERR("fapiGetScom(EX_OHA_MODE_REG) failed. With rc = 0x%x", (uint32_t)rc);  
                return rc;    
            }

            FAPI_DBG ("EX_PERV_SCRATCH0_10013283  :  %016llX", data.getDoubleWord(0));
            
        }
    }     
    
    return rc;
  
}  //corestat



} //end extern C

