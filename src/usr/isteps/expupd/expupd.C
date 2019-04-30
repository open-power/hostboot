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
#include <fapi2/hw_access.H>
#include <chipids.H>
#include <trace/interface.H>
#include <hbotcompid.H>
#include "ocmbFwImage.H"
#include <exp_fw_update.H>
#include <initservice/istepdispatcherif.H>

using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace expupd
{

// Initialize the trace buffer for this component
trace_desc_t* g_trac_expupd  = nullptr;
TRAC_INIT(&g_trac_expupd, EXPUPD_COMP_NAME, 2*KILOBYTE);

/**
 * @brief Structure for retrieving the explorer SHA512 hash value
 *
 */
typedef union sha512regs
{
    struct
    {
        uint32_t imageId;
        uint8_t  sha512Hash[HEADER_SHA512_SIZE];
    };
    uint8_t unformatted[sizeof(uint32_t) + HEADER_SHA512_SIZE];
}sha512regs_t;

/**
 * @brief Retrieve the SHA512 hash for the currently flashed explorer
 *        firmware image.
 *
 * @param[in] i_target Target of the OCMB chip to retrieve the SHA512 hash
 * @param[out] o_regs Structure for storing the retrieved SHA512 hash
 *
 * @return NULL on success.  Non-null on failure.
 */
errlHndl_t getFlashedHash(TargetHandle_t i_target, sha512regs_t& o_regs)
{
    fapi2::buffer<uint64_t> l_scomBuffer;
    uint8_t* l_scomPtr = reinterpret_cast<uint8_t*>(l_scomBuffer.pointer());
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi2Target(i_target);
    errlHndl_t l_err = nullptr;

    //Start addres of hash register (a.k.a. RAM1 register)
    const uint32_t HASH_REG_ADDR = 0x00002200;

    // loop until we've filled the sha512regs_t struct
    for(uint32_t l_bytesCopied = 0; l_bytesCopied < sizeof(sha512regs_t);
        l_bytesCopied += sizeof(uint32_t))
    {
        // Use getScom, this knows internally whether to use i2c or inband
        FAPI_INVOKE_HWP(l_err, getScom,
                        l_fapi2Target,
                        HASH_REG_ADDR + l_bytesCopied,
                        l_scomBuffer);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "getFlashedHash: Failed reading SHA512 hash from"
                      " ocmb[0x%08x]. bytesCopied[%u]",
                      TARGETING::get_huid(i_target), l_bytesCopied);

            break;
        }

        // copy scom buffer into the unformatted uint8_t array.
        // Even though the scom buffer is 8 bytes, only 4 bytes are read and
        // copied into the least significant 4 bytes.
        memcpy(&o_regs.unformatted[l_bytesCopied], l_scomPtr + sizeof(uint32_t),
                sizeof(uint32_t));
    }

    return l_err;
}

/**
 * @brief Check flash image SHA512 hash value of each explorer chip
 *        and update the flash if it does not match the SHA512 hash
 *        of the image in PNOR.
 *
 * @param[out] o_stepError Error handle for logging istep failures
 *
 */
void updateAll(IStepError& o_stepError)
{
    bool l_imageLoaded = false;
    errlHndl_t l_err = nullptr;
    bool l_rebootRequired = false;

    // Get a list of OCMB chips
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    TRACFCOMP(g_trac_expupd, ENTER_MRK
              "updateAll: %d ocmb chips found",
              l_ocmbTargetList.size());

    do
    {
        // If no OCMB chips exist, we're done.
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
            o_stepError.addErrorDetails( l_err );

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
            o_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, EXPUPD_COMP_ID );
            break;
        }

        // Verify the header and retrieve address, size and
        // SHA512 hash of unpackaged image
        l_err = ocmbFwValidateImage(
                                  l_pnorSectionInfo.vaddr,
                                  l_pnorSectionInfo.secureProtectedPayloadSize,
                                  l_imageInfo);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "updateAll: Failure in expupdValidateImage");

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Create IStep error log and cross reference to error that occurred
            o_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, EXPUPD_COMP_ID );
            break;
        }

        // For each explorer chip, compare flash hash with PNOR hash and
        // create a list of explorer chips with differing hash values.
        TARGETING::TargetHandleList l_flashUpdateList;
        for(const auto & l_ocmbTarget : l_ocmbTargetList)
        {
            sha512regs_t l_regs;

            //skip all gemini ocmb chips (not updateable)
            if(l_ocmbTarget->getAttr<TARGETING::ATTR_CHIP_ID>() ==
                                                     POWER_CHIPID::GEMINI_16)
            {
                TRACFCOMP(g_trac_expupd,
                      "updateAll: skipping update of gemini OCMB 0x%08x",
                      TARGETING::get_huid(l_ocmbTarget));
                continue;
            }

            //retrieve the SHA512 hash for the currently flashed image.
            l_err = getFlashedHash(l_ocmbTarget, l_regs);
            if(l_err)
            {
                TRACFCOMP(g_trac_expupd, ERR_MRK
                         "updateAll: Failure in getFlashedHash(huid = 0x%08x)",
                         TARGETING::get_huid(l_ocmbTarget));

                l_err->collectTrace(EXPUPD_COMP_NAME);

                // Create IStep error log and cross reference to error
                // that occurred
                o_stepError.addErrorDetails(l_err);

                errlCommit(l_err, EXPUPD_COMP_ID);

                //Don't stop on error, go to next target.
                continue;
            }

            // Trace the hash and image ID values
            TRACFCOMP(g_trac_expupd,
                      "updateAll: OCMB 0x%08x image ID=0x%08x",
                      TARGETING::get_huid(l_ocmbTarget), l_regs.imageId);
            TRACFBIN(g_trac_expupd, "SHA512 HASH FROM EXPLORER",
                     l_regs.sha512Hash, HEADER_SHA512_SIZE);

            //Compare hashes.  If different, add to list for update.
            if(memcmp(l_regs.sha512Hash, l_imageInfo.imageSHA512HashPtr,
                      HEADER_SHA512_SIZE))
            {
                TRACFCOMP(g_trac_expupd,
                        "updateAll: SHA512 hash mismatch on ocmb[0x%08x]",
                        TARGETING::get_huid(l_ocmbTarget));

                //add target to our list of targets needing an update
                l_flashUpdateList.push_back(l_ocmbTarget);
            }
            else
            {
                TRACFCOMP(g_trac_expupd,
                          "updateAll: SHA512 hash for ocmb[0x%08x]"
                          " matches SHA512 hash of PNOR image.",
                          TARGETING::get_huid(l_ocmbTarget));
            }
        }

        TRACFCOMP(g_trac_expupd,
                  "updateAll: updating flash for %d OCMB chips",
                  l_flashUpdateList.size());

        // update each explorer in the list of chips needing updates
        for(const auto & l_ocmb : l_flashUpdateList)
        {
            TRACFCOMP(g_trac_expupd, "updateAll: updating OCMB 0x%08x",
                      TARGETING::get_huid(l_ocmb));
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi2Target(l_ocmb);

            // reset watchdog for each ocmb as this function can be very slow
            INITSERVICE::sendProgressCode();

            // Invoke procedure
            FAPI_INVOKE_HWP(l_err, exp_fw_update, l_fapi2Target,
                            l_imageInfo.imagePtr, l_imageInfo.imageSize);
            if (l_err)
            {
                TRACFCOMP(g_trac_expupd,
                          "Error from exp_fw_update for OCMB 0x%08x",
                          TARGETING::get_huid(l_ocmb));

                l_err->collectTrace(EXPUPD_COMP_NAME);

                // Create IStep error log and cross reference to error
                // that occurred
                o_stepError.addErrorDetails( l_err );

                errlCommit(l_err, EXPUPD_COMP_ID);

                // Don't stop on error, go to next target.
                continue;
            }
            else
            {
                TRACFCOMP(g_trac_expupd,
                        "updateAll: successfully updated OCMB 0x%08x",
                        TARGETING::get_huid(l_ocmb));

                // Request reboot for new firmware to be used
                l_rebootRequired = true;
            }
        }
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
            o_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, EXPUPD_COMP_ID );
        }
#endif //CONFIG_SECUREBOOT
    }

    // force reboot if any updates were successful
    if(l_rebootRequired)
    {
        TRACFCOMP(g_trac_expupd,
                  "updateAll: OCMB chip(s) was updated.  Requesting reboot...");
        Target* l_pTopLevel = nullptr;
        targetService().getTopLevelTarget( l_pTopLevel );
        assert(l_pTopLevel, "expupd::updateAll: no TopLevelTarget");
        auto l_reconfigAttr =
            l_pTopLevel->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
        l_reconfigAttr |= RECONFIGURE_LOOP_OCMB_FW_UPDATE;
        l_pTopLevel->setAttr<TARGETING::ATTR_RECONFIGURE_LOOP>(l_reconfigAttr);
    }
    else
    {
        TRACFCOMP(g_trac_expupd, "updateAll: No OCMB chips were updated");
    }


    TRACFCOMP(g_trac_expupd, EXIT_MRK"updateAll()");
}

}//namespace expupd
