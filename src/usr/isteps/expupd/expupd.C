/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/expupd/expupd.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#include <expupd/expupd_reasoncodes.H>
#include <pnor/pnorif.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <isteps/hwpistepud.H>
#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <trace/interface.H>
#include <hbotcompid.H>
#include "ocmbFwImage.H"

using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace expupd
{

// Initialize the trace buffer for this component
trace_desc_t* g_trac_expupd  = nullptr;
TRAC_INIT(&g_trac_expupd, EXPUPD_COMP_NAME, 2*KILOBYTE);

/**
 * @brief Retrieve the SHA512 hash for the currently flashed explorer
 *        firmware image.
 */
errlHndl_t expupdGetFlashedHash()
{
    return nullptr;
}

/**
 * @brief Check flash image SHA512 hash value of each explorer chip
 *        and update the flash if it does not match the SHA512 hash
 *        of the image in PNOR.
 *
 */
void updateAll(IStepError& i_StepError)
{
    bool l_imageLoaded = false;
    errlHndl_t l_err = nullptr;

    // Get a list of explorer chips
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    TRACFCOMP(g_trac_expupd, ENTER_MRK
              "updateAll: %d ocmb chips found",
              l_ocmbTargetList.size());

    do
    {
        // If no explorer chips exist, we're done.
        if(l_ocmbTargetList.size() == 0)
        {
            break;
        }

        // Read explorer fw image from pnor
        PNOR::SectionInfo_t l_pnorSectionInfo;
        rawImageInfo_t l_imageInfo;

#ifdef CONFIG_SECUREBOOT
        l_err = PNOR::loadSecureSection(PNOR::OCMBFW);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "updateAll: Failed to load OCMBFW section"
                      " from PNOR!");

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Create IStep error log and cross reference to error that occurred
            i_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, EXPUPD_COMP_ID );

            break;
        }
#endif //CONFIG_SECUREBOOT

        l_imageLoaded = true;

        // get address and size of packaged image
        l_err = PNOR::getSectionInfo(PNOR::OCMBFW, l_pnorSectionInfo);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "updateAll: Failure in getSectionInfo()");

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Create IStep error log and cross reference to error that occurred
            i_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, EXPUPD_COMP_ID );
            break;
        }

        // Verify the header and retrieve address, size and
        // SHA512 hash of unpackaged image
        l_err = ocmbFwValidateImage(l_pnorSectionInfo.vaddr,
                                    l_pnorSectionInfo.size,
                                    l_imageInfo);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "updateAll: Failure in expupdValidateImage");

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Create IStep error log and cross reference to error that occurred
            i_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, EXPUPD_COMP_ID );
            break;
        }

        // For each explorer chip, compare flash hash with PNOR hash and
        // create a list of explorer chips with differing hash values

        // If list not empty update each explorer in the list
    }while(0);

    // unload explorer fw image
    if(l_imageLoaded)
    {
#ifdef CONFIG_SECUREBOOT
        l_err = PNOR::unloadSecureSection(PNOR::OCMBFW);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "updateAll: Failed to unload OCMBFW");

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Create IStep error log and cross reference to error that occurred
            i_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, EXPUPD_COMP_ID );
        }
#endif //CONFIG_SECUREBOOT
    }

    // force reboot if any updates were successful


    TRACFCOMP(g_trac_expupd, EXIT_MRK"updateAll()");
}

}//namespace expupd
