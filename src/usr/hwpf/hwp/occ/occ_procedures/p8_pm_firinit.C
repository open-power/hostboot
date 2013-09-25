/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_firinit.C $         */
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
// $Id: p8_pm_firinit.C,v 1.12 2013-09-25 21:26:09 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_firinit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Pradeep CN         Email: pradeepcn@in.ibm.com
// *!
/// \file p8_pm_init.C
/// \brief Calls each firinit procedrues to configure the FIRs to
///         predefined types
///
///
///
///
///
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------
///
/// \todo   Review
///
///
/// High-level procedure flow:
///
/// \verbatim
///     - call p8_pm_pmc_firinit.C *chiptarget
///     - evaluate RC
///
///     - call p8_pm_pba_firinit.C *chiptarget
///     - evaluate RC
///
///
///  \endverbatim
///
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------


#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pm_firinit.H"
#include "p8_pm_pmc_firinit.H"
#include "p8_pm_pba_firinit.H"
#include "p8_pm_pcbs_firinit.H"
#include "p8_pm_oha_firinit.H"
#include "p8_pm_occ_firinit.H"

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

//------------------------------------------------------------------------------
/**
 * p8_pm_firinit Call underlying FIR procedures to deal with the FIRs based on 
 *       the mode
 *
 * @param[in] i_target   Chip target which will be passed to all the procedures
 *
 * @param[in] i_mode   Control mode for the procedure
 *                     PM_INIT, PM_CONFIG, PM_RESET, PM_RESET_SOFT
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */

fapi::ReturnCode
p8_pm_firinit(const fapi::Target &i_target , uint32_t i_mode)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    uint64_t any_error = 0;

    FAPI_INF("p8_pm_firinit start for mode %x", i_mode);

    do
    {
       
        // *************************************************************
        // CHECKING FOR FIRS BEFORE RESET and INIT
        // *************************************************************

        FAPI_DBG("checking FIRs of PBA PMC OCC  ...");

        // PMC FIR
        rc = fapiGetScom(i_target, PMC_LFIR_0x01010840 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_LFIR_0x01010840) failed.");
            break;
        }

        any_error = data.getDoubleWord(0);

        if (any_error)
        {
            // Once clear FIRs are established, this will throw errors.
            FAPI_INF("WARNING: PMC_FIR has error(s) active.  0x%016llX ", data.getDoubleWord(0));
            //FAPI_ERR(" PMC_FIR has error(s) active.  0x%16llX ", data.getDoubleWord(0));
            //FAPI_SET_HWP_ERROR(rc, RC_PROCPM_FIR_ERROR);
            //break;
        }

       // PBA FIR
        rc = fapiGetScom(i_target, PBA_FIR_0x02010840 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PBA_FIR_0x02010840) failed.");
            break;
        }

        any_error = data.getDoubleWord(0);

        if (any_error)
        {
            // Once clear FIRs are established, this will throw errors.
            FAPI_INF("WARNING: PBA_FIR has error(s) active.  0x%016llX ", data.getDoubleWord(0));
            //FAPI_ERR(" PBA_FIR_0x02010840  has error(s) active.  0x%16llX ", data.getDoubleWord(0));
            //FAPI_SET_HWP_ERROR(rc, RC_PROCPM_FIR_ERROR);
            //break;
        }


        // OCC FIR
        rc = fapiGetScom(i_target, OCC_LFIR_0x01010800 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(OCC_LFIR_0x01010800) failed.");
            break;
        }

        any_error = data.getDoubleWord(0);

        if (any_error)
        {
            // Once clear FIRs are established, this will throw errors.
            FAPI_INF("WARNING: OCC_FIR has error(s) active.  0x%016llX ", data.getDoubleWord(0));
            //FAPI_ERR(" OCC_LFIR_0x01010800  has error(s) active.  0x%16llX ", data.getDoubleWord(0));
            //FAPI_SET_HWP_ERROR(rc, RC_PROCPM_FIR_ERROR);
            //break;
        }

        //  ******************************************************************
        //  PMC_FIRS
        //  ******************************************************************

        FAPI_EXEC_HWP(rc, p8_pm_pmc_firinit , i_target , i_mode );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_pmc_firinit detected failed result");
            break;
        }

        //  ******************************************************************
        //  PBA
        //  ******************************************************************
    ;
        FAPI_EXEC_HWP(rc, p8_pm_pba_firinit , i_target , i_mode );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_pba_firinit detected failed result");
            break;
        }

        //  ******************************************************************
        //  OHA
        //  ******************************************************************

        FAPI_EXEC_HWP(rc, p8_pm_oha_firinit , i_target , i_mode );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_oha_firinit detected failed result");
            break;
        }

        //  ******************************************************************
        //  PCBS
        //  ******************************************************************

        FAPI_EXEC_HWP(rc, p8_pm_pcbs_firinit , i_target , i_mode );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_pcbs_firinit detected failed result");
            break;
        }

        //  ******************************************************************
        //  OCC
        //  ******************************************************************

        FAPI_EXEC_HWP(rc,  p8_pm_occ_firinit , i_target , i_mode );
        if (rc)
        {
            FAPI_ERR("ERROR: p8_pm_occ_firinit detected failed result");
            break;
        }

    } while(0);

    FAPI_INF("p8_pm_firinit end for mode %x", i_mode);
    
    return rc;

} // Procedure

} //end extern C
