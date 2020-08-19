/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/host_mss_attr_cleanup.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/**
 *  @file host_mss_attr_cleanup.C
 *  Place holder for cleaning up memory related attributes.
 *  Currently used for misc functions.
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <devicefw/userif.H>
#include    <vpd/spdenums.H>
#include    <util/misc.H>


namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//
//  Wrapper function to call mss_attr_update
//  mss_attr_update no longer used
//  will use this for other misc functions
//
void*    host_mss_attr_cleanup( void *io_pArgs )
{
    IStepError l_StepError;

    TRACFCOMP( g_trac_isteps_trace, "host_mss_attr_cleanup entry");

    //*****************************************************
    //  Clear out any memory repairs from the DIMMS

    // Get all the functional Dimms
    errlHndl_t l_err = nullptr;
    TargetHandleList l_funcDimmList;
    getAllLogicalCards(l_funcDimmList, TYPE_DIMM, true);

    // DIMM_BAD_DQ_DATA
    for (const auto & l_Dimm: l_funcDimmList)
    {
        // Read ATTR_CLEAR_DIMM_SPD_ENABLE attribute
        Target* l_sys = NULL;
        targetService().getTopLevelTarget(l_sys);

        ATTR_CLEAR_DIMM_SPD_ENABLE_type l_clearSPD =
            l_sys->getAttr<TARGETING::ATTR_CLEAR_DIMM_SPD_ENABLE>();

        // If SPD clear is enabled then write 0's into magic word for
        // DIMM_BAD_DQ_DATA keyword
        // Note: If there's an error from performing the clearing,
        // just log the error and continue.
        if (l_clearSPD)
        {
            size_t l_size = 0;

            // Do a read to get the DIMM_BAD_DQ_DATA keyword size
            l_err = deviceRead(l_Dimm, NULL, l_size,
                               DEVICE_SPD_ADDRESS( SPD::DIMM_BAD_DQ_DATA ));
            if (l_err)
            {
                TRACFCOMP( g_trac_isteps_trace,
                           ERR_MRK"host_mss_attr_cleanup() "
                           "Error reading DIMM_BAD_DQ_DATA keyword size");
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                // Clear the data
                TRACFCOMP( g_trac_isteps_trace,
                           "Clearing out BAD_DQ_DATA SPD on DIMM HUID 0x%X",
                           get_huid(l_Dimm));

                uint8_t * l_data = static_cast<uint8_t*>(malloc( l_size ));
                memset(l_data, 0, l_size);

                l_err = deviceWrite(l_Dimm, l_data, l_size,
                                    DEVICE_SPD_ADDRESS( SPD::DIMM_BAD_DQ_DATA));
                if (l_err)
                {
                    TRACFCOMP( g_trac_isteps_trace,
                               ERR_MRK"host_mss_attr_cleanup() "
                               "Error trying to clear SPD on DIMM HUID 0x%X",
                               get_huid(l_Dimm));
                    errlCommit( l_err, HWPF_COMP_ID );
                }

                // Free the memory
                if (NULL != l_data)
                {
                    free(l_data);
                }
            }
        }
    }

    //*****************************************************
    //  Setup any dynamic attributes

    // Replicate HB memory mirroring policy into HWP policy
    Target* l_pTopLevel = UTIL::assertGetToplevelTarget();
    auto l_mirror = l_pTopLevel->getAttr<TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM>();

    if(l_mirror)
    {
        l_pTopLevel->setAttr<TARGETING::ATTR_MRW_HW_MIRRORING_ENABLE>
          (TARGETING::MRW_HW_MIRRORING_ENABLE_REQUIRED);
    }
    else
    {
        l_pTopLevel->setAttr<TARGETING::ATTR_MRW_HW_MIRRORING_ENABLE>
          (TARGETING::MRW_HW_MIRRORING_ENABLE_OFF);
    }


    //*******************************************
    TRACFCOMP( g_trac_isteps_trace, "host_mss_attr_cleanup exit");

    return l_StepError.getErrorHandle();
}

};   // end namespace
