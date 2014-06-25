/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_firinit.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

// $Id: p8_pm_firinit.C,v 1.17 2014/07/09 14:49:32 daviddu Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_firinit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
    fapi::ReturnCode    rc;
    ecmdDataBufferBase  data(64);
    uint64_t            any_error = 0;
    const char *        PM_MODE_NAME_VAR; // Defines storage for PM_MODE_NAME
    uint8_t             attr_pm_firinit_done_once_flag;

    FAPI_INF("p8_pm_firinit start for mode %s", PM_MODE_NAME(i_mode));

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
        //  OHA - Removed as the values are part of the winkle image
        //  ******************************************************************

        //  FAPI_EXEC_HWP(rc, p8_pm_oha_firinit , i_target , i_mode );
        //  if (rc)
        //  {
        //      FAPI_ERR("ERROR: p8_pm_oha_firinit detected failed result");
        //      break;
        //  }

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

        // -----------
        // SW260003
        // -----------

        rc = FAPI_ATTR_GET(ATTR_PM_FIRINIT_DONE_ONCE_FLAG, &i_target, attr_pm_firinit_done_once_flag);
        if (!rc.ok()) {
                        FAPI_ERR("fapiGetAttribute of ATTR_PM_FIRINIT_DONE_ONCE_FLAG failed.");
            break;
        }

        if (i_mode == PM_INIT) {    
            if (attr_pm_firinit_done_once_flag != 1) {
                attr_pm_firinit_done_once_flag = 1;
                rc = FAPI_ATTR_SET(ATTR_PM_FIRINIT_DONE_ONCE_FLAG, &i_target, attr_pm_firinit_done_once_flag);
                if (!rc.ok()) {
                  FAPI_ERR("fapiSetAttribute of ATTR_PM_FIRINIT_DONE_ONCE_FLAG failed");
                  break;
                }
            }
        }
        else if (i_mode == PM_RESET) {    
            if (attr_pm_firinit_done_once_flag == 1) {
                attr_pm_firinit_done_once_flag = 2;
                rc = FAPI_ATTR_SET(ATTR_PM_FIRINIT_DONE_ONCE_FLAG, &i_target, attr_pm_firinit_done_once_flag);
                if (!rc.ok()) {
                  FAPI_ERR("fapiSetAttribute of ATTR_PM_FIRINIT_DONE_ONCE_FLAG failed");
                  break;
                }
            }
        }

    } while(0);

    FAPI_INF("p8_pm_firinit end for mode %s", PM_MODE_NAME(i_mode));
    
    return rc;

} // Procedure

} //end extern C
