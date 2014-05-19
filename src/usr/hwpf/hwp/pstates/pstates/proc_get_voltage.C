/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/proc_get_voltage.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_get_voltage.C,v 1.6 2013/12/04 18:54:49 jimyac Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_get_voltage.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_get_voltage.C
// *! DESCRIPTION : Get VDD & VCS vid codes for given Frequency (FAPI)
// *!
// *! OWNER NAME  : Jim Yacynych         Email: jimyac@us.ibm.com
// *! BACKUP NAME :
// *!
// *! ADDITIONAL COMMENTS :
// *!   Procedure Prereq:
// *!       - System clocks are running
// *!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Version     Date        Owner       Description
//------------------------------------------------------------------------------
//    1.2       11/07/13                RAS review changes
//    1.1       mm/dd/yy    jimyac      Initial release
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>

#include <pstate_tables.h>
#include <lab_pstates.h>
#include <pstates.h>
#include <proc_get_voltage.H>

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
/// \param[in]      i_target           Chip Target
/// \param[in]      i_freq_mhz         frequency in Mhz
/// \param[out]     *o_vdd_vid         vdd vid value
/// \param[out]     *o_vcs_vid         vcs vid value

/// \retval FAPI_RC_SUCCESS
/// \retval ERROR defined in xml

ReturnCode proc_get_voltage(const Target&  i_target,
                            const uint32_t i_freq_mhz,
                            uint8_t& o_vdd_vid,
                            uint8_t& o_vcs_vid)
{
    fapi::ReturnCode     l_rc;
    int                  l_result = 0;
    PstateSuperStructure l_pss;
    gpst_entry_t         l_entry;
    Pstate               l_freq_pstate       = 0;
    Pstate               l_pmax              = 0;
    uint8_t              l_freq_pstate_index = 0;

    // -----------------------------
    // create pstate super structure
    // -----------------------------
    
    do
    {
        FAPI_IMP("Executing p8_build_pstate_datablock to create Pstate Superstructure");
        FAPI_EXEC_HWP(l_rc, p8_build_pstate_datablock, i_target, &l_pss);
        if (!l_rc.ok())
        {
            FAPI_ERR("Error calling p8_build_pstate_datablock");
            break;
        }

        // ----------------------
        // convert freq to pstate
        // ----------------------
        FAPI_INF("Look up Pstate for given frequency (%u Mhz) in Global Pstate Table in Pstate Superstructure", i_freq_mhz);
        l_result = freq2pState(&(l_pss.gpst), (i_freq_mhz*1000), &l_freq_pstate);

        if (l_result)
        {
            const uint32_t & FREQ_MHZ       = i_freq_mhz;
            int            & FREQ2PSTATE_RC = l_result;
            FAPI_ERR("**** ERROR : Pstate for given frequency (%u Mhz) is out of bounds of Pstate Values : max = %d min = %d", i_freq_mhz, PSTATE_MAX, PSTATE_MIN);
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_GET_VOLTAGE_FREQ2PSTATE_ERROR);
            break;
        }

        // ----------------------
        // pstate bounds checking
        // ----------------------
        l_pmax = l_pss.gpst.pmin + l_pss.gpst.entries - 1;

        FAPI_INF("l_freq_pstate = %d l_pmax = %d  pmin = %d entries = %d i_freq_mhz = %d\n", l_freq_pstate, l_pmax, l_pss.gpst.pmin, l_pss.gpst.entries, i_freq_mhz);

        if (l_freq_pstate > l_pmax)
        {
            int8_t  & FREQ_PSTATE = l_freq_pstate;
            int8_t  & PMAX        = l_pmax;
            int8_t  & PMIN        = l_pss.gpst.pmin;
            uint8_t & ENTRIES     = l_pss.gpst.entries;
            FAPI_ERR("**** ERROR : Pstate (%d) for given frequency is greater than l_pmax (%d)", l_freq_pstate, l_pmax);
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_GET_VOLTAGE_FREQ_PSTATE_GT_PMAX_ERROR);
            break;
        }

        // clip l_freq_pstate to pmin if it is lower than pmin
        if (l_freq_pstate < l_pss.gpst.pmin)
        {
            FAPI_INF("Pstate for given frequency is less than pmin, so clipping it to pmin");
            l_freq_pstate = l_pss.gpst.pmin;
        }

        // --------------------------------------------------------
        // convert pstate to pstate table index and lookup voltages
        // --------------------------------------------------------
        l_freq_pstate_index = l_freq_pstate - l_pss.gpst.pmin;
        l_entry.value       = revle64(l_pss.gpst.pstate[l_freq_pstate_index].value);
        o_vdd_vid           = l_entry.fields.evid_vdd;
        o_vcs_vid           = l_entry.fields.evid_vcs;
        
        FAPI_INF("vid codes for pstate %d : vdd = 0x%02x vcs = 0x%02x", l_freq_pstate, o_vdd_vid, o_vcs_vid);
        
    } while(0);

    return l_rc;
}

} //end extern C
