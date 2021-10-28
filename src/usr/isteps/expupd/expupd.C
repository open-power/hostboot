/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/expupd/expupd.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
 * @file    expupd.C
 *
 * @brief   Check and update Explorer firmware
 *          HWP: exp_fw_update
 */

#include <expupd/expupd_reasoncodes.H>
#include <pnor/pnorif.H>
#include <targeting/targplatutil.H>
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
#include <util/misc.H>
#include <hbotcompid.H>
#include "ocmbFwImage.H"
#include <exp_fw_update.H>
#include <initservice/istepdispatcherif.H>
#include <istepHelperFuncs.H>               // captureError
#include <util/threadpool.H>
#include <spdenums.H>
#include <spd.H>
#include <kernel/bltohbdatamgr.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <lib/inband/exp_fw_adapter_properties.H> // explorer properties
#include <lib/inband/exp_flash_utils.H> // exp_flash_read_test
#include <errl/errlreasoncodes.H>   // ERRL_UDT_NOFORMAT
#include <errl/errludstring.H>

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
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi2Target(i_target);
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
                      " ocmb[0x%08x]. bytesCopied[%u]. "
                      TRACE_ERR_FMT,
                      get_huid(i_target), l_bytesCopied,
                      TRACE_ERR_ARGS(l_err));

            break;
        }

        // copy scom buffer into the unformatted uint8_t array.
        // Even though the scom buffer is 8 bytes, only 4 bytes are read and
        // copied into the least significant 4 bytes.
        uint32_t regValue;
        memcpy(&regValue, l_scomPtr + sizeof(uint32_t), sizeof(uint32_t));
        regValue = le32toh( regValue );  // need to reverse byte order
        memcpy(&o_regs.unformatted[l_bytesCopied], &regValue, sizeof(regValue));
    }

    return l_err;
}

/**
 * @brief Determine if the OCMB chip is a MDS DDIMM
 *        If an error occurs while trying to determine this, the error is deleted
 *        and false will be returned.
 *
 * @param[in] i_ocmb        OCMB chip target handler from which to read the SPD from
 * @return true if OCMB chip is a MDS DDIMM; false otherwise
 */
bool isMdsDdimm(TargetHandle_t i_ocmb)
{
    // Assume the OCMB chip is *not* a MDS DDIMM until determined otherwise
    bool l_isMdsDdimm(false);

    errlHndl_t l_err(nullptr);

    do
    {
        // Read the memory type from the SPD of the OCMB chip
        size_t l_memTypeSize(SPD::MEM_TYPE_SZ);
        uint8_t l_memType(0);
        l_err = deviceRead(i_ocmb,
                           &l_memType,
                           l_memTypeSize,
                           DEVICE_SPD_ADDRESS(SPD::BASIC_MEMORY_TYPE));

        // If an error occurred, then commit the error and return false
        if( l_err )
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK"isMdsDdimm> Error trying to read SPD for 0x%0.8X, "
                                     "committing error and returning false", get_huid(i_ocmb));

           /*@
            * @errortype
            * @moduleid        EXPUPD::MOD_IS_MDS_DDIMM
            * @reasoncode      EXPUPD::DEVICE_READ_FAIL
            * @userdata1       HUID of OCMB target being examined
            * @userdata2       <unused>
            * @devdesc         Device read failed on OCMB target - indeterminate
            *                  if OCMB is an MDS DDIMM
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            EXPUPD::MOD_IS_MDS_DDIMM,
                                            EXPUPD::DEVICE_READ_FAIL,
                                            get_huid(i_ocmb),
                                            0,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            errlCommit(l_err, EXPUPD_COMP_ID);
            break;
        }

        // If the memory type is indeed a MDS DDIMM then return true
        if (l_memType == SPD::SPD_MDS_TYPE)
        {
           l_isMdsDdimm = true;
        }
    }
    while (0);

    TRACFCOMP(g_trac_expupd, INFO_MRK"isMdsDdimm> returning %s for 0x%0.8X",
                             (l_isMdsDdimm ? "true" : "false"), get_huid(i_ocmb) );
    return l_isMdsDdimm;
} // isMdsDdimm


/**
 * @brief Write Explorer Firmware version into SPD of the given OCMB target.
 * The SPD has byte 960 to 1023 reserved for this information.
 * Any errors found will be committed inside of the function itself.
 *
 * @param[in] i_ocmb        OCMB chip target handler. Firmware version will be written to its corresponding SPD.
 * @param[in] i_versionStr  The version string, e.g. "version=0.1", not null-terminated
 * @param[in] i_strSize     Number of bytes making up i_versionStr
 */
void writeExplorerFwVersion(TargetHandle_t i_ocmb, const uint8_t* i_versionStr, const size_t i_strSize)
{
    errlHndl_t l_err = nullptr;

    // Get SPD keyword EXPLORER_FW_VERSION info
    const SPD::KeywordData *l_fWVerKeyword = {nullptr};
    l_err = getKeywordEntry(SPD::EXPLORER_FW_VERSION, SPD::SPD_DDR4_TYPE, i_ocmb, l_fWVerKeyword);

    const size_t l_spdKeywordSize = l_fWVerKeyword->length;

    // The actual data being written to the SPD::EXPLORER_FW_VERSION keyword must be of size
    // 64-bytes for the SPD-write API to work.
    uint8_t l_paddedData [l_spdKeywordSize] = {};

    // Data copied over to l_paddedData should be at most l_spdKeywordSize
    size_t l_copySize = std::min(l_spdKeywordSize, i_strSize);
    memcpy(l_paddedData, i_versionStr, l_copySize);

    TargetHandleList l_dimmList;
    getChildAffinityTargets(l_dimmList, i_ocmb, CLASS_LOGICAL_CARD, TYPE_DIMM);

    do
    {
        // Only one DIMM target is expected. If a number other than one is found, then there's an
        // issue with the targeting layout.
        if (l_dimmList.size() != 1)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK"writeExplorerFwVersion: Unsupported number of DDIMMs "
                "(%lu) found for OCMB with HUID 0x%X.", l_dimmList.size(), get_huid(i_ocmb));
           /*@errorlog
            * @errortype       ERRL_SEV_PREDICTIVE
            * @moduleid        EXPUPD::MOD_WRITE_EXPLORER_FW_VERSION
            * @reasoncode      EXPUPD::UNSUPPORTED_NUMBER_OF_DIMMS
            * @userdata1       HUID of OCMB target whose DDIMM is being searched for
            * @userdata2       Number of DDIMMs found
            * @devdesc         Unsupported number of DDIMMs found tied to one OCMB in targeting layout.
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                            EXPUPD::MOD_WRITE_EXPLORER_FW_VERSION,
                                            EXPUPD::UNSUPPORTED_NUMBER_OF_DIMMS,
                                            get_huid(i_ocmb),
                                            l_dimmList.size(),
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        TargetHandle_t l_dimm = l_dimmList[0];

        TRACDCOMP(g_trac_expupd, "writeExplorerFwVersion: Attempting to write FW version of "
            "OCMB: 0x%X, into SPD of DDIMM: 0x%X", get_huid(i_ocmb), get_huid(l_dimm));
        TRACDBIN(g_trac_expupd, "writeExplorerFwVersion: OCMB FW Version string: ",
            l_paddedData, l_spdKeywordSize);

        l_err = deviceWrite(l_dimm, l_paddedData, (size_t&)l_spdKeywordSize, DEVICE_SPD_ADDRESS(SPD::EXPLORER_FW_VERSION));

    } while (0);

    if (l_err)
    {
        TRACFCOMP(g_trac_expupd, ERR_MRK"writeExplorerFwVersion: Failed to update version keyword "
            "for OCMB: 0x%X", get_huid(i_ocmb));
        TRACFBIN(g_trac_expupd, ERR_MRK"writeExplorerFwVersion: Failed trying to write this "
            "version string: ", i_versionStr, i_strSize);
        l_err->collectTrace(EXPUPD_COMP_NAME);
        errlCommit(l_err, EXPUPD_COMP_ID);
    }
    else
    {
        TRACDCOMP(g_trac_expupd, "writeExplorerFwVersion: successfully updated version string in "
            "SPD of OCMB 0x%08x", TARGETING::get_huid(i_ocmb));
    }

}

//
// @brief Mutex to prevent threads from adding details to the step
//        error log at the same time.
mutex_t g_stepErrorMutex = MUTEX_INITIALIZER;

/*******************************************************************************
 * @brief base work item class for isteps (used by thread pool)
 */
class IStepWorkItem
{
    public:
        virtual ~IStepWorkItem(){}
        virtual void operator()() = 0;
};

/*******************************************************************************
 * @brief OCMB specific work item class
 */
class OcmbWorkItem: public IStepWorkItem
{
    private:
        IStepError* iv_pStepError;
        const Target* iv_ocmb;
        rawImageInfo_t* iv_imageInfo;

    public:
        /**
         * @brief task function, called by threadpool to run the HWP on the
         *        target
         */
         void operator()();

        /**
         * @brief ctor
         *
         * @param[in] i_Ocmb target Ocmb to operate on
         * @param[in] i_istepError error accumulator for this istep
         */
        OcmbWorkItem(const Target& i_Ocmb,
                     IStepError& i_stepError,
                     rawImageInfo_t& i_imageInfo):
            iv_pStepError(&i_stepError),
            iv_ocmb(&i_Ocmb),
            iv_imageInfo(&i_imageInfo)        {}

        // delete default copy/move constructors and operators
        OcmbWorkItem() = delete;
        OcmbWorkItem(const OcmbWorkItem& ) = delete;
        OcmbWorkItem& operator=(const OcmbWorkItem& ) = delete;
        OcmbWorkItem(OcmbWorkItem&&) = delete;
        OcmbWorkItem& operator=(OcmbWorkItem&&) = delete;

        /**
         * @brief destructor
         */
        ~OcmbWorkItem(){};
};

//******************************************************************************
void OcmbWorkItem::operator()()
{
    errlHndl_t l_err = nullptr;

    // reset watchdog for each Ocmb as this function can be very slow
    INITSERVICE::sendProgressCode();

    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
      l_fapi2Target(const_cast<TARGETING::TargetHandle_t>(iv_ocmb));

    // Invoke procedure to get good/bad image indicators
    bool l_image_a_good = false;
    bool l_image_b_good = false;
    FAPI_INVOKE_HWP(l_err, mss::exp::ib::run_fw_adapter_properties_get,
                    l_fapi2Target, l_image_a_good, l_image_b_good);
    if (l_err)
    {
        TRACFCOMP(g_trac_expupd,
              ERR_MRK"Error from run_fw_adapter_properties_get for OCMB 0x%08x",
              TARGETING::get_huid(iv_ocmb));

        l_err->collectTrace(EXPUPD_COMP_NAME);

        // addErrorDetails may not be thread-safe.  Protect with mutex.
        mutex_lock(&g_stepErrorMutex);

        // Create IStep error log and cross reference to error
        // that occurred (will commit l_err)
        captureError(l_err, *iv_pStepError, EXPUPD_COMP_ID);

        mutex_unlock(&g_stepErrorMutex);
    }

    // Invoke update procedure
    FAPI_INVOKE_HWP(l_err, exp_fw_update, l_fapi2Target,
                    iv_imageInfo->imagePtr, iv_imageInfo->imageSize);
    if (l_err)
    {
        TRACFCOMP(g_trac_expupd,
                  ERR_MRK"Error from exp_fw_update for OCMB 0x%08x",
                  TARGETING::get_huid(iv_ocmb));

        l_err->collectTrace(EXPUPD_COMP_NAME);

        // explicitly deconfigure this part since we don't want to run on
        //  down-level code
        l_err->addHwCallout( iv_ocmb,
                             HWAS::SRCI_PRIORITY_MED,
                             HWAS::DELAYED_DECONFIG,
                             HWAS::GARD_NULL );

        // add the good/bad image indicators to FFDC
        if (l_image_a_good)
        {
            ErrlUserDetailsString("IMAGE_A_GOOD").addToLog(l_err);
        }
        else
        {
            ErrlUserDetailsString("IMAGE_A_BAD").addToLog(l_err);
        }
        if (l_image_b_good)
        {
            ErrlUserDetailsString("IMAGE_B_GOOD").addToLog(l_err);
        }
        else
        {
            ErrlUserDetailsString("IMAGE_B_BAD").addToLog(l_err);
        }

        // addErrorDetails may not be thread-safe.  Protect with mutex.
        mutex_lock(&g_stepErrorMutex);

        // Create IStep error log and cross reference to error
        // that occurred (will commit l_err)
        captureError(l_err, *iv_pStepError, EXPUPD_COMP_ID);

        mutex_unlock(&g_stepErrorMutex);
    }
    else
    {
        TRACFCOMP(g_trac_expupd,
                  "OcmbWorkItem(): successfully updated OCMB 0x%08x",
                  TARGETING::get_huid(iv_ocmb));

        // Write updated firmware version to SPD of DDIMM that belongs to OCMB chip
        if (iv_imageInfo->fwVersionStrPtr && iv_imageInfo->fwVersionStrSize != 0)
        {
            writeExplorerFwVersion((TargetHandle_t)iv_ocmb, iv_imageInfo->fwVersionStrPtr,
                iv_imageInfo->fwVersionStrSize);
        }

        // Invoke flash read test procedure
        if (TARGETING::isDimmSpiFlashScreenSet())
        {
            FAPI_INVOKE_HWP(l_err,
                            mss::exp::ib::exp_flash_read_test,
                            l_fapi2Target);
            if (l_err)
            {
                TRACFCOMP(g_trac_expupd,
                        ERR_MRK"Error from exp_flash_read_test for OCMB 0x%08x",
                        TARGETING::get_huid(iv_ocmb));

                l_err->collectTrace(EXPUPD_COMP_NAME);

                // addErrorDetails may not be thread-safe.  Protect with mutex.
                mutex_lock(&g_stepErrorMutex);

                // Create IStep error log and cross reference to error
                // that occurred (will commit l_err)
                captureError(l_err, *iv_pStepError, EXPUPD_COMP_ID);

                mutex_unlock(&g_stepErrorMutex);
            }
        }
    }
}


// Find out if any explorer chips need an update
bool explorerUpdateCheck(IStepError& o_stepError,
                        TargetHandleList& o_flashUpdateList,
                        rawImageInfo_t & o_imageInfo,
                        bool & o_imageLoaded,
                        bool & o_rebootRequired,
                        bool i_checkMfgFlag )
{
    errlHndl_t l_err = nullptr;
    o_imageLoaded = false;
    bool l_attemptUpdate = true;

    // Clear flash update list.  Will populate with OCMB chips that need updating
    o_flashUpdateList.clear();

    // Get a list of OCMB chips
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    Target* l_pTopLevel = UTIL::assertGetToplevelTarget();

    // Check if we have any overrides to force our behavior
    auto l_forced_behavior =
            l_pTopLevel->getAttr<ATTR_OCMB_FW_UPDATE_OVERRIDE>();

    TRACFCOMP(g_trac_expupd, ENTER_MRK
              "explorerUpdateCheck: %d ocmb chips found",
              l_ocmbTargetList.size());

    do
    {
        // If no OCMB chips exist, we're done.
        if(l_ocmbTargetList.size() == 0)
        {
            TRACFCOMP(g_trac_expupd, INFO_MRK "Skipping update, no OCMB found");
            l_attemptUpdate = false;
            break;
        }

        // Exit now if told to
        if( OCMB_FW_UPDATE_BEHAVIOR_PREVENT_UPDATE == l_forced_behavior )
        {
            TRACFCOMP(g_trac_expupd, INFO_MRK "Skipping update due to override "
                "(PREVENT_UPDATE)");
            l_attemptUpdate = false;
            break;
        }

        // Read explorer fw image from pnor
        PNOR::SectionInfo_t l_pnorSectionInfo;

#ifdef CONFIG_SECUREBOOT
        l_err = PNOR::loadSecureSection(PNOR::OCMBFW);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "explorerUpdateCheck: Failed to load OCMBFW section"
                      " from PNOR! "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Capture error
            captureError(l_err, o_stepError, EXPUPD_COMP_ID);
            l_attemptUpdate = false;
            break;
        }
        o_imageLoaded = true;
#endif //CONFIG_SECUREBOOT

        // get address and size of packaged image
        l_err = PNOR::getSectionInfo(PNOR::OCMBFW, l_pnorSectionInfo);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "explorerUpdateCheck: Failure in getSectionInfo(). "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Capture error
            captureError(l_err, o_stepError, EXPUPD_COMP_ID);
            l_attemptUpdate = false;
            break;
        }

        const auto l_pnorSectionSize = (l_pnorSectionInfo.hasHashTable
                                        ? l_pnorSectionInfo.size
                                        : l_pnorSectionInfo.secureProtectedPayloadSize);

        // Verify the header and retrieve address, size and
        // SHA512 hash of unpackaged image
        l_err = ocmbFwValidateImage(
                                  l_pnorSectionInfo.vaddr,
                                  l_pnorSectionSize,
                                  o_imageInfo);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "explorerUpdateCheck: Failure in ocmbFwValidateImage. "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Capture error
            captureError(l_err, o_stepError, EXPUPD_COMP_ID);
            l_attemptUpdate = false;
            break;
        }

        // A quick reference for determining if forcing updates on MDS targets only
        bool l_forceMdsUpdate = (OCMB_FW_UPDATE_BEHAVIOR_MDS_FORCE_UPDATE == l_forced_behavior);
        if (l_forceMdsUpdate)
        {
            TRACFCOMP(g_trac_expupd, "explorerUpdateCheck: Forcing updates on MDS targets only");
        }

        // For each explorer chip, compare flash hash with PNOR hash and
        // create a list of explorer chips with differing hash values.
        for(const auto & l_ocmbTarget : l_ocmbTargetList)
        {
            sha512regs_t l_regs;

            //skip all non-Explorer ocmb chips (not updateable)
            if(l_ocmbTarget->getAttr<ATTR_CHIP_ID>() !=
                                                     POWER_CHIPID::EXPLORER_16)
            {
                TRACFCOMP(g_trac_expupd,
                      "explorerUpdateCheck: skipping update of non-Explorer OCMB 0x%08x",
                      get_huid(l_ocmbTarget));
                continue;
            }

            // A quick reference for determining if OCMB target is an MDS DDIMM or not
            bool l_isMdsDimm = isMdsDdimm(l_ocmbTarget);

            // If forcing updates on MDS then *only* update MDS targets
            if (l_forceMdsUpdate)
            {
                // If target is an MDS then update it
                if (l_isMdsDimm)
                {
                    o_flashUpdateList.push_back(l_ocmbTarget);
                    o_rebootRequired = true;

                    TRACFCOMP(g_trac_expupd,
                              "explorerUpdateCheck: Forcing an update on OCMB MDS DIMM "
                              "[0x%08x]", get_huid(l_ocmbTarget));
                }
                // Skip the rest of the code that deals with non-MDS targets
                continue;
            }
            // If not forcing MDS updates then only want to update non-MDS targets
            // therefore if this an MDS target, skip
            else if (l_isMdsDimm)
            {
                continue;
            }

            //retrieve the SHA512 hash for the currently flashed image.
            l_err = getFlashedHash(l_ocmbTarget, l_regs);
            if(l_err)
            {
                TRACFCOMP(g_trac_expupd, ERR_MRK
                         "explorerUpdateCheck: Failure in getFlashedHash(huid = 0x%08x). "
                         TRACE_ERR_FMT,
                         get_huid(l_ocmbTarget),
                         TRACE_ERR_ARGS(l_err));

                l_err->collectTrace(EXPUPD_COMP_NAME);

                // Capture error
                captureError(l_err, o_stepError, EXPUPD_COMP_ID, l_ocmbTarget);

                //Don't stop on error, go to next target.
                continue;
            }

            // Trace the hash and image ID values
            TRACFCOMP(g_trac_expupd,
                      "explorerUpdateCheck: OCMB 0x%08x image ID=0x%08x",
                      get_huid(l_ocmbTarget), l_regs.imageId);
            TRACFBIN(g_trac_expupd, "SHA512 HASH FROM EXPLORER",
                     l_regs.sha512Hash, HEADER_SHA512_SIZE);

            //Compare hashes.  If different, add to list for update.
            if(memcmp(l_regs.sha512Hash, o_imageInfo.imageSHA512HashPtr,
                      HEADER_SHA512_SIZE))
            {
                TRACFCOMP(g_trac_expupd,
                        "explorerUpdateCheck: SHA512 hash mismatch on ocmb[0x%08x]",
                        get_huid(l_ocmbTarget));

                //add target to our list of targets needing an update
                o_flashUpdateList.push_back(l_ocmbTarget);
                o_rebootRequired = true;
            }
            else
            {
                TRACFCOMP(g_trac_expupd,
                          "explorerUpdateCheck: SHA512 hash for ocmb[0x%08x]"
                          " matches SHA512 hash of PNOR image.",
                          get_huid(l_ocmbTarget));

                // Add every OCMB to the update list if told to
                if( OCMB_FW_UPDATE_BEHAVIOR_FORCE_UPDATE
                    == l_forced_behavior )
                {
                    TRACFCOMP(g_trac_expupd, INFO_MRK "explorerUpdateCheck: "
                              "Forcing ocmb[0x%08X] update due to override"
                              " (FORCE_UPDATE)", get_huid(l_ocmbTarget) );
                    o_flashUpdateList.push_back(l_ocmbTarget);
                    o_rebootRequired = true;
                }
                // Or if we are using the MFG flag and the flag is set
                else if (i_checkMfgFlag && TARGETING::isDimmSpiFlashScreenSet())
                {
                    TRACFCOMP(g_trac_expupd, INFO_MRK "explorerUpdateCheck: "
                              "Forcing ocmb[0x%08X] update due to mfg flag"
                              " (MNFG_DIMM_SPI_FLASH_SCREEN)",
                              get_huid(l_ocmbTarget) );
                    o_flashUpdateList.push_back(l_ocmbTarget);
                }
            }
        } // All OCMB loop

        TRACFCOMP(g_trac_expupd,
                  "explorerUpdateCheck: %d OCMB chips require update",
                  o_flashUpdateList.size());
    } while (0);
    if( OCMB_FW_UPDATE_BEHAVIOR_CHECK_BUT_NO_UPDATE == l_forced_behavior )
    {
        TRACFCOMP(g_trac_expupd,
            INFO_MRK "explorerUpdateCheck: Skipping update due to override "
            "(CHECK_BUT_NO_UPDATE)");
        l_attemptUpdate = false;
    }

    if ( Util::isSimicsRunning() )
    {
        TRACFCOMP(g_trac_expupd,
            INFO_MRK "explorerUpdateCheck: Simics running so skipping the update");
        l_attemptUpdate = false;
    }
    return l_attemptUpdate;
}

void performUpdate( IStepError& o_stepError,
                    TargetHandleList& i_explorerList,
                    rawImageInfo_t& i_imageInfo,
                    bool i_rebootRequired )
{
    errlHndl_t l_err = nullptr;
    Util::ThreadPool<IStepWorkItem> threadpool;
    constexpr size_t MAX_OCMB_THREADS = 8;
    Target* l_pTopLevel = UTIL::assertGetToplevelTarget();

    do
    {
        // Nothing to update, just exit
        if( i_explorerList.empty() )
        {
            TRACFCOMP(g_trac_expupd, INFO_MRK "performUpdate: Nothing to update");
            break;
        }

        // Up the number of threads we can support if we have more
        //  cache to play in
        auto l_cacheSize = g_BlToHbDataManager.getHbCacheSizeMb();
        auto l_maxThreads = MAX_OCMB_THREADS;
        if( l_cacheSize > 16 )
        {
            l_maxThreads = 128; //effectively no limit
        }

        //Don't create more threads than we have targets
        size_t l_numTargets = i_explorerList.size();
        uint32_t l_numThreads = std::min(l_maxThreads, l_numTargets);

        TRACFCOMP(g_trac_expupd,
                  INFO_MRK"Starting %llu thread(s) to handle %llu OCMB target(s) ",
                  l_numThreads, l_numTargets);

        //Set the number of threads to use in the threadpool
        Util::ThreadPoolManager::setThreadCount(l_numThreads);

        for(const auto & l_ocmb : i_explorerList)
        {
            //  Create a new workitem from this membuf and feed it to the
            //  thread pool for processing.  Thread pool handles workitem
            //  cleanup.
            threadpool.insert(new OcmbWorkItem(*l_ocmb,
                                               o_stepError,
                                               i_imageInfo));
        }

        //create and start worker threads
        threadpool.start();

        //wait for all workitems to complete, then clean up all threads.
        l_err = threadpool.shutdown();
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd,
                      ERR_MRK"performUpdate: thread pool returned an error "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));
            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Capture error
            captureError(l_err, o_stepError, EXPUPD_COMP_ID);
        }

    } while(0);

    // force reboot if any update was triggered by a FW mismatch or
    // forced by attribute
    if(i_rebootRequired)
    {
        TRACFCOMP(g_trac_expupd,
                  "performUpdate: %d OCMB chip(s) %s update.  Requesting reboot...",
                  i_explorerList.size(), o_stepError.isNull()?"completed":"attempted");
        auto l_reconfigAttr =
            l_pTopLevel->getAttr<ATTR_RECONFIGURE_LOOP>();
        l_reconfigAttr |= RECONFIGURE_LOOP_OCMB_FW_UPDATE;
        l_pTopLevel->setAttr<ATTR_RECONFIGURE_LOOP>(l_reconfigAttr);
    }
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
    bool l_rebootRequired = false;
    bool l_checkMfgFlag = true;
    TargetHandleList l_flashUpdateList;
    rawImageInfo_t l_imageInfo;


    // Check to see if any OCMBs need to update
    // Use the MFG flag in this path
    bool attemptUpdate = explorerUpdateCheck(o_stepError,
                                             l_flashUpdateList,
                                             l_imageInfo,
                                             l_imageLoaded,
                                             l_rebootRequired,
                                             l_checkMfgFlag );

    // Verify update should be attempted,
    // attr overrides and major errors can prevent update
    if (attemptUpdate)
    {
        // try to perform the update now with list
        performUpdate(o_stepError,
                      l_flashUpdateList,
                      l_imageInfo,
                      l_rebootRequired);
    }

    // unload explorer fw image
    if(l_imageLoaded)
    {
#ifdef CONFIG_SECUREBOOT
        errlHndl_t l_err = PNOR::unloadSecureSection(PNOR::OCMBFW);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "updateAll: Failed to unload OCMBFW. "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));

            l_err->collectTrace(EXPUPD_COMP_NAME);

            // Capture error
            captureError(l_err, o_stepError, EXPUPD_COMP_ID);
        }
#endif //CONFIG_SECUREBOOT
    }

    TRACFCOMP(g_trac_expupd, EXIT_MRK"updateAll()");
}

/**
 * @brief Change entire list of OCMBs to use i2cScom instead of inband
 * @param[in] List of OCMBs to switch to i2c
 */
void disableInbandScomsOCMB(const TARGETING::TargetHandleList i_ocmbTargetList)
{
    mutex_t* l_mutex = nullptr;

    for ( const auto & l_ocmb : i_ocmbTargetList )
    {
        //don't mess with attributes without the mutex (just to be safe)
        l_mutex = l_ocmb->getHbMutexAttr<ATTR_SCOM_ACCESS_MUTEX>();
        recursive_mutex_lock(l_mutex);

        ScomSwitches l_switches = l_ocmb->getAttr<ATTR_SCOM_SWITCHES>();
        if (l_switches.useI2cScom == 0)
        {
            TRACFCOMP( g_trac_expupd,
                "disabledInbandScomsOCMB: OCMB 0x%.8X updated to use i2c scom",
                TARGETING::get_huid(l_ocmb) );
            l_switches.useI2cScom = 1;
            l_switches.useInbandScom = 0;

            // Modify attribute
            l_ocmb->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
        }
        recursive_mutex_unlock(l_mutex);
    }
}

// Check if any OCMB needs an i2c update and perform it if necessary
void ocmbFwI2cUpdateStatusCheck( IStepError & io_StepError)
{
    TargetHandleList l_ocmbUpdateList;
    rawImageInfo_t l_imageInfo;
    bool l_imageLoaded = false;
    bool l_rebootRequired = false;
    bool l_checkMfgFlag = false;

    // Get a handle to the current node target
    TargetHandle_t l_nodeTarget = UTIL::getCurrentNodeTarget();

    ATTR_OCMB_FW_UPDATE_STATUS_type l_updStatus =
        l_nodeTarget->getAttr<ATTR_OCMB_FW_UPDATE_STATUS>();

    // Avoid falling back to i2c mode in manufacturing mode
    bool mfgMode = TARGETING::areMfgThresholdsActive();

    TRACFCOMP(g_trac_expupd, "ocmbFwI2cUpdateStatusCheck: "
              "Enter OCMB_FW_UPDATE_STATUS: updateRequired = %d, "
              "updateI2c = %d, i2cUpdateAttepted = %d, hardFailure = %d, "
              "mdfgMode = %d",
              l_updStatus.updateRequired, l_updStatus.updateI2c,
              l_updStatus.i2cUpdateAttempted, l_updStatus.hardFailure,
              mfgMode);

    // Get list of OCMBs that need updating + update image
    // Do not use the MFG flag in this path
    bool doUpdate = explorerUpdateCheck(io_StepError,
                                        l_ocmbUpdateList,
                                        l_imageInfo,
                                        l_imageLoaded,
                                        l_rebootRequired,
                                        l_checkMfgFlag );

    // check that at least one ocmb needs an update
    if (l_ocmbUpdateList.size() && !mfgMode)
    {
        l_updStatus.updateRequired = 1;
        if (l_updStatus.hardFailure)
        {
            //clear out rest of status to attempt a fresh update
            l_updStatus.updateI2c = 0;
            l_updStatus.i2cUpdateAttempted = 0;
            l_updStatus.hardFailure = 0;
        }
        else if (l_updStatus.updateI2c && !l_updStatus.i2cUpdateAttempted)
        {
            // only perform update if the check says to do it
            if (doUpdate)
            {
                // make sure i2c scom path is taken
                disableInbandScomsOCMB(l_ocmbUpdateList);

                // do the i2c update of the Explorer(s)
                performUpdate(io_StepError,
                              l_ocmbUpdateList,
                              l_imageInfo,
                              l_rebootRequired);
            }
            l_updStatus.i2cUpdateAttempted = 1;
        }
    }
    else
    {
        // clear out status, nothing to update
        l_updStatus.updateRequired = 0;
        l_updStatus.updateI2c = 0;
        l_updStatus.i2cUpdateAttempted = 0;
        l_updStatus.hardFailure = 0;
    }

    l_nodeTarget->setAttr<ATTR_OCMB_FW_UPDATE_STATUS>(l_updStatus);
    TRACFCOMP(g_trac_expupd, "ocmbFwI2cUpdateStatusCheck: "
              "Exit OCMB_FW_UPDATE_STATUS: updateRequired = %d, "
              "updateI2c = %d, i2cUpdateAttepted = %d, hardFailure = %d",
              l_updStatus.updateRequired, l_updStatus.updateI2c,
              l_updStatus.i2cUpdateAttempted, l_updStatus.hardFailure);


    // cleanup pnor memory
    if (l_imageLoaded)
    {
#ifdef CONFIG_SECUREBOOT
        errlHndl_t l_err = PNOR::unloadSecureSection(PNOR::OCMBFW);
        if(l_err)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "ocmbFwI2cUpdateStatusCheck: Failed to unload OCMBFW. "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));

            l_err->collectTrace(ISTEP_COMP_NAME);

            // Capture error
            captureError(l_err, io_StepError, ISTEP_COMP_ID);
        }
#endif //CONFIG_SECUREBOOT
    }
}


}//namespace expupd
