/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_post_winkle/proc_post_winkle.C $ */
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
// $Id: proc_post_winkle.C,v 1.2 2013/07/18 00:45:00 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_post_winkle.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Michael Olsen Email: cmolsen@us.ibm.com
/// \file proc_post_winkle.C
/// \brief  Re-enables the standard product idle mode configuration after
///         an IPL Winkle action
///
/// \verbatim
///
///     For the passed EX target,
///         - Remove disable of DISABLE_FORCE_DEEP_TO_FAST_WINKLE that was
///             set on the master core.  Removing on the non_master cores
///             is not harmful
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "proc_post_winkle.H"

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


/**
 * proc_post_winkle
 *
 * @param[in] i_target EX target
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR only those from called functions or MACROs
 */
fapi::ReturnCode
proc_post_winkle(const Target& i_ex_target)
{
    fapi::ReturnCode    l_rc;
    uint32_t            rc = 0;

    ecmdDataBufferBase  data(64);
    uint64_t            address = 0;
    uint64_t            ex_offset = 0;    

    uint8_t             l_ex_number = 0;
    fapi::Target        l_parentTarget;

    do
    {

        FAPI_INF("Beginnning proc_post_winkle...");

        // Get the parent chip to target the PCBS registers
        l_rc = fapiGetParentChip(i_ex_target, l_parentTarget);
        if (l_rc)
        {
            FAPI_ERR("fapiGetParentChip access");
            break;
        }

        // Get the core number
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_ex_target, l_ex_number);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)l_rc);
            break;
        }

        FAPI_INF("Processing core %d on %s", l_ex_number, l_parentTarget.toEcmdString());
        
        ex_offset = l_ex_number * 0x01000000;
        
        // Debug
        address = EX_PMGP1_0x100F0103 + ex_offset;
        l_rc = fapiGetScom(l_parentTarget, address, data);
        if(!l_rc.ok())
        {
            FAPI_ERR("Scom error reading PMGP1\n");
            break;
        }
        FAPI_DBG("\tBefore PMGP1: 0x%016llX", data.getDoubleWord(0));

        // Enable movement to Fast Winkle if errors are present.  This is
        // turned off in the during the IPL process
        rc |= data.flushTo1();
        rc |= data.clearBit(20);
        if(rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc);
            l_rc.setEcmdError(rc);
            break;
        }

        address = EX_PMGP1_AND_0x100F0104 + ex_offset;
        l_rc = fapiPutScom(l_parentTarget, address, data);
        if(!l_rc.ok())
        {
            FAPI_ERR("Scom error updating PMGP1\n");
            break;
        }
        FAPI_INF("Enabled the conversion of Deep Winkle operations to Fast Winkle if errors are present upon Winkle entry");
        
        // Debug
        address = EX_PMGP1_0x100F0103 + ex_offset;
        l_rc = fapiGetScom(l_parentTarget, address, data);
        if(!l_rc.ok())
        {
            FAPI_ERR("Scom error reading PMGP1\n");
            break;
        }
        FAPI_DBG("\tAfter  PMGP1: 0x%016llX", data.getDoubleWord(0));

    } while(0);

    FAPI_INF("Exiting proc_post_winkle...");
    return l_rc;
}


} //end extern C
