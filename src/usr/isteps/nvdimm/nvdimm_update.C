/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimm_update.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include "nvdimm_update.H"
#include "nvdimm.H"
#include <isteps/nvdimm/nvdimm.H>
#include <isteps/nvdimm/nvdimmreasoncodes.H>

#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <vpd/spdenums.H>

// Easy macro replace for unit testing
// #define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace NVDIMM
{
//////////////////////////////////////////////////////////////////////////////
// Helper Inline functions
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief Inline function to collect NVDIMM traces and
 *        make sure error is logged at least as PREDICTIVE
 */
inline void commitPredictiveNvdimmError(errlHndl_t & io_err)
{
    io_err->collectTrace(NVDIMM_COMP_NAME, 256);
    if ( io_err->sev() < ERRORLOG::ERRL_SEV_PREDICTIVE )
    {
        io_err->setSev( ERRORLOG::ERRL_SEV_PREDICTIVE );
    }
    ERRORLOG::errlCommit(io_err, NVDIMM_COMP_ID);
}


///////////////////////////////////////////////////////////////////////////////
// NVDIMM LID Image
///////////////////////////////////////////////////////////////////////////////
NvdimmLidImage::NvdimmLidImage(Util::LidId i_lidId, errlHndl_t& io_errHdl)
{
    iv_lidImage = nullptr;
    iv_lidImageSize = 0;
    iv_ImageLoaded = false;

    iv_lidMgr = new UtilLidMgr(i_lidId);
    io_errHdl = loadImage();
}

NvdimmLidImage::~NvdimmLidImage()
{
    errlHndl_t l_err = unloadImage();
    if (l_err)
    {
        ERRORLOG::errlCommit(l_err, NVDIMM_COMP_ID);
    }
}

uint32_t NvdimmLidImage::getType()
{
    uint32_t o_type = INVALID_TYPE;

    if (iv_lidImageSize >= sizeof(nvdimm_image_header_t))
    {
        nvdimm_image_header_t * pLid = reinterpret_cast<nvdimm_image_header_t*>
                                          (iv_lidImage);
        o_type = (uint32_t)pLid->module_mnfg_id_code << 16;
        o_type |= (uint32_t)pLid->module_product_id;
    }
    return o_type;
}

uint16_t NvdimmLidImage::getVersion()
{
    uint16_t o_version = INVALID_VERSION;

    if (iv_lidImageSize >= sizeof(nvdimm_image_header_t))
    {
        nvdimm_image_header_t * pLid = reinterpret_cast<nvdimm_image_header_t*>
                                          (iv_lidImage);
        o_version = pLid->controller_firmware_revision;
    }
    return o_version;
}

void * NvdimmLidImage::getFlashImage()
{
    void * o_image_ptr = nullptr;
    if (iv_lidImageSize > sizeof(nvdimm_image_header_t))
    {
        nvdimm_image_header_t * pLid = reinterpret_cast<nvdimm_image_header_t*>
                                          (iv_lidImage);

        // make sure we don't point outside of lid memory
        // nvdimm flash image starts after the header and digital signature
        if ((sizeof(nvdimm_image_header_t) +
             le16toh(pLid->SMART_digital_signature_size)) < iv_lidImageSize)
        {
            o_image_ptr = reinterpret_cast<uint8_t*>(iv_lidImage) +
                          sizeof(nvdimm_image_header_t) +
                          le16toh(pLid->SMART_digital_signature_size);
        }
    }
    return o_image_ptr;
}

size_t NvdimmLidImage::getFlashImageSize()
{
    uint32_t o_flash_size = 0;
    if (iv_lidImageSize > sizeof(nvdimm_image_header_t))
    {
        nvdimm_image_header_t * pLid = reinterpret_cast<nvdimm_image_header_t*>
                                          (iv_lidImage);
        o_flash_size = le32toh(pLid->firmware_image_size);
        o_flash_size -= sizeof(nvdimm_image_header_t);

        // safety check so we don't access past lid's memory size
        if ((o_flash_size + sizeof(nvdimm_image_header_t) +
             le16toh(pLid->SMART_digital_signature_size)) > iv_lidImageSize)
        {
            TRACFCOMP(g_trac_nvdimm,
                ERR_MRK"getFlashImageSize(): %ld flash size + %ld header + "
                "%ld digital signature is greater than %ld overall lid size",
                o_flash_size, sizeof(nvdimm_image_header_t),
                le16toh(pLid->SMART_digital_signature_size),
                iv_lidImageSize);
            // flash image size is outside of lid memory bounds so don't return
            // a valid flash size
            o_flash_size = 0;
        }
    }
    return o_flash_size;
}

bool NvdimmLidImage::isImageLoaded()
{
    return iv_ImageLoaded;
}
///////////////////////////////////////////////////
// Private member functions for NvdimmLidImage
///////////////////////////////////////////////////
errlHndl_t NvdimmLidImage::loadImage()
{
    errlHndl_t l_err = nullptr;
    if (!iv_ImageLoaded && (iv_lidMgr != nullptr))
    {
        // @todo RTC 205015 -- need to use secure load
        // iv_lidImage will point to memory allocated
        // and controlled by iv_lidMgr
        l_err = iv_lidMgr->getStoredLidImage(iv_lidImage, iv_lidImageSize);
        if (l_err == nullptr)
        {
            // image successfully loaded into memory
            iv_ImageLoaded = true;
        }
    }
    return l_err;
}

errlHndl_t NvdimmLidImage::unloadImage()
{
    errlHndl_t l_err = nullptr;
    if (iv_ImageLoaded && (iv_lidMgr != nullptr))
    {
        // use lidMgr to delete allocated memory for this lid
        l_err = iv_lidMgr->releaseLidImage();
        iv_lidImage = nullptr;
        iv_lidImageSize = 0;
        iv_ImageLoaded = false;
    }
    return l_err;
}

///////////////////////////////////////////////////////////////////////////////
// NVDIMM Installed Image
///////////////////////////////////////////////////////////////////////////////
NvdimmInstalledImage::NvdimmInstalledImage(TARGETING::Target * i_nvDimm) :
    iv_dimm(i_nvDimm), iv_version(INVALID_VERSION),
    iv_manufacturer_id(INVALID_ID), iv_product_id(INVALID_ID)
{
    // initialize to invalid values
}

errlHndl_t NvdimmInstalledImage::getType(uint32_t & o_type)
{
    errlHndl_t l_err = nullptr;
    do {
      size_t l_id_size = 0; // size of id
      if ( iv_manufacturer_id == INVALID_ID)
      {
          // grab values for the installed NVDIMM via SPD
          l_id_size = sizeof(iv_manufacturer_id);
          l_err = deviceRead(iv_dimm, &iv_manufacturer_id, l_id_size,
                           DEVICE_SPD_ADDRESS(SPD::RAW_MODULE_MANUFACTURER_ID));
          if (l_err)
          {
              TRACFCOMP(g_trac_nvdimm, ERR_MRK"NvdimmInstalledImage::getType()"
                  " nvdimm[%X] failed to read manufacturer ID",
                  TARGETING::get_huid(iv_dimm));
              iv_manufacturer_id = INVALID_ID;
              break;
          }
      }

      if (iv_product_id == INVALID_ID)
      {
          // grab values for the installed NVDIMM via SPD
          l_id_size = sizeof(iv_product_id);
          l_err = deviceRead(iv_dimm, &iv_product_id, l_id_size,
                            DEVICE_SPD_ADDRESS(SPD::RAW_MODULE_PRODUCT_ID));
          if (l_err)
          {
              TRACFCOMP(g_trac_nvdimm, ERR_MRK"NvdimmInstalledImage::getType()"
                  " nvdimm[%X] failed to read product ID",
                  TARGETING::get_huid(iv_dimm));
              iv_product_id = INVALID_ID;
              break;
          }
      }
    } while (0);

    // return the concatenated Type (this may include INVALID_IDs)
    o_type = ((uint32_t)iv_manufacturer_id << 16) | (uint32_t)iv_product_id;
    return l_err;
}

errlHndl_t NvdimmInstalledImage::getVersion(uint16_t & o_version)
{
    errlHndl_t l_err = nullptr;

    do {
      if ((iv_version == INVALID_VERSION))
      {
          // Return version in little-endian format
          uint8_t l_rev1 = 0xFF;
          uint8_t l_rev0 = 0xFF;

          l_err = nvdimmReadReg(iv_dimm, SLOT1_FWREV1, l_rev1 );
          if (l_err)
          {
              TRACFCOMP(g_trac_nvdimm, ERR_MRK"NvdimmInstalledImage::"
                  "getVersion() nvdimm[%X] failed to read SLOT1_FWREV1",
                  TARGETING::get_huid(iv_dimm));
              iv_version = INVALID_VERSION;
              break;
          }
          iv_version = (uint16_t)l_rev1 << 8;

          l_err = nvdimmReadReg(iv_dimm, SLOT1_FWREV0, l_rev0 );
          if (l_err)
          {
              TRACFCOMP(g_trac_nvdimm, ERR_MRK"NvdimmInstalledImage::"
                  "getVersion() nvdimm[%X] failed to read SLOT1_FWREV0",
                  TARGETING::get_huid(iv_dimm));
              iv_version = INVALID_VERSION;
              break;
          }
          iv_version |= (uint16_t)l_rev0;
      }
    } while (0);
    o_version = iv_version;
    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
// NVDIMMS Update Functions
///////////////////////////////////////////////////////////////////////////////
NvdimmsUpdate::NvdimmsUpdate(TARGETING::TargetHandleList i_nvdimmList)
{
    iv_nvdimmList = i_nvdimmList;
}

bool NvdimmsUpdate::runUpdate(void)
{
    bool o_no_error_found = true;  // true if no error was found during update

    errlHndl_t l_err = nullptr;

    uint32_t l_installed_type = INVALID_TYPE; // current LID type installed
    NvdimmLidImage * pCurLid = nullptr; // current LID being used for update

    // These are kept to minimize lid memory loading/unloading and
    // reported errors
    NvdimmLidImage * pSmallLid = nullptr;
    NvdimmLidImage * pLargeLid = nullptr;

    for (auto l_nvdimm : iv_nvdimmList)
    {
        NvdimmInstalledImage l_installed_image(l_nvdimm);
        l_err = l_installed_image.getType(l_installed_type);
        if (l_err)
        {
            // Continue updating other dimms
            TRACFCOMP(g_trac_nvdimm, ERR_MRK "NvdimmsUpdate::runUpdate() - "
                "Unable to get nvdimm[0x%.8X] installed image type. "
                "RC=0x%X, PLID=0x%.8X",
                get_huid(l_nvdimm), ERRL_GETRC_SAFE(l_err),
                ERRL_GETPLID_SAFE(l_err));
            commitPredictiveNvdimmError(l_err);
            o_no_error_found = false;
            continue;
        }

        if (l_installed_type == JEDEC_NVDIMM_16GB_TYPE)
        {
            if (pSmallLid == nullptr)
            {
                pSmallLid = new NvdimmLidImage(Util::NVDIMM_16GB_LIDID, l_err);
                if (l_err)
                {
                    // Continue to try updating other dimms
                    TRACFCOMP(g_trac_nvdimm,
                        ERR_MRK "NvdimmsUpdate::runUpdate() - Unable to load "
                        "NVDIMM_16GB_LIDID(0x%X). RC=0x%X, PLID=0x%.8X",
                        Util::NVDIMM_16GB_LIDID,
                        ERRL_GETRC_SAFE(l_err),
                        ERRL_GETPLID_SAFE(l_err));
                    commitPredictiveNvdimmError(l_err);
                    o_no_error_found = false;
                    // leaving pSmallLid object so don't continuously post the
                    // same error for each NVDIMM
                    continue;
                }
            }
            pCurLid = pSmallLid;
        }
        else if (l_installed_type == JEDEC_NVDIMM_32GB_TYPE)
        {
            if (pLargeLid == nullptr)
            {
                pLargeLid = new NvdimmLidImage(Util::NVDIMM_32GB_LIDID, l_err);
                if (l_err)
                {
                    // Continue to try updating other dimms
                    TRACFCOMP(g_trac_nvdimm,
                        ERR_MRK "NvdimmsUpdate::runUpdate() - Unable to load "
                        "NVDIMM_32GB_LIDID(0x%X). RC=0x%X, PLID=0x%.8X",
                        Util::NVDIMM_32GB_LIDID,
                        ERRL_GETRC_SAFE(l_err),
                        ERRL_GETPLID_SAFE(l_err));
                    commitPredictiveNvdimmError(l_err);
                    o_no_error_found = false;
                    // leaving pLargeLid object so don't continuously post the
                    // same error for each NVDIMM
                    continue;
                }
            }
            pCurLid = pLargeLid;
        }
        else
        {
            // unknown/unsupported Type
            TRACFCOMP(g_trac_nvdimm, "NvdimmsUpdate::runUpdate() - unknown "
                "nvdimm[%X] installed type 0x%04X, skipping update",
                TARGETING::get_huid(l_nvdimm), l_installed_type);
            /*
             *@errortype
             *@reasoncode       NVDIMM_UNSUPPORTED_NVDIMM_TYPE
             *@moduleid         NVDIMM_RUN_UPDATE
             *@userdata1[0:31]  Unsupported Type
             *@userdata1[32:63] NVDIMM Target Huid
             *@userdata2[0:31]  Supported nvdimm type
             *@userdata2[32:63] Other supported nvdimm type
             *@devdesc          Unable to update an unsupported NVDIMM type
             *@custdesc         NVDIMM not updated
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                           NVDIMM_RUN_UPDATE,
                                           NVDIMM_UNSUPPORTED_NVDIMM_TYPE,
                                           TWO_UINT32_TO_UINT64(
                                              l_installed_type,
                                              TARGETING::get_huid(l_nvdimm)),
                                           TWO_UINT32_TO_UINT64(
                                              JEDEC_NVDIMM_16GB_TYPE,
                                              JEDEC_NVDIMM_32GB_TYPE),
                                           ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            l_err->collectTrace(NVDIMM_COMP_NAME, 256 );
            l_err->addHwCallout( l_nvdimm, HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG, HWAS::GARD_NULL );
            l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW );
            ERRORLOG::errlCommit(l_err, NVDIMM_COMP_ID);
            o_no_error_found = false;
            pCurLid = nullptr;
            continue;
        }

        // Verify a valid LID was loaded and ready to read
        if ((pCurLid == nullptr) || (!pCurLid->isImageLoaded()))
        {
            // Errors already logged, just continue to the next NVDIMM
            continue;
        }

        bool updateNeeded = false;
        l_err = isUpdateNeeded(updateNeeded, pCurLid, &l_installed_image);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm, ERR_MRK "NvdimmsUpdate::runUpdate() - "
                "Unable to determine if nvdimm[%X] needs NV controller update."
                " RC=0x%X, PLID=0x%.8X",
                TARGETING::get_huid(l_nvdimm), ERRL_GETRC_SAFE(l_err),
                ERRL_GETPLID_SAFE(l_err));
            commitPredictiveNvdimmError(l_err);
            o_no_error_found = false;
        }
        else if (updateNeeded)
        {
            // perform update for this DIMM with the current LID image
            TRACFCOMP(g_trac_nvdimm, "NvdimmsUpdate::runUpdate() - "
                "now update nvdimm[0x%.8X]", TARGETING::get_huid(l_nvdimm));

            TRACFCOMP(g_trac_nvdimm,"Updating with flash size: 0x%08X",
                pCurLid->getFlashImageSize());

            // @todo RTC 202536 : Add update calls
        }
    }

    if (pLargeLid)
    {
        delete pLargeLid;
    }
    if (pSmallLid)
    {
        delete pSmallLid;
    }

    return o_no_error_found;
}

errlHndl_t NvdimmsUpdate::isUpdateNeeded(bool & o_update_needed,
                                   NvdimmLidImage * i_lid_image,
                                   NvdimmInstalledImage * i_cur_image)
{
    o_update_needed = false;  // initialize to false

    errlHndl_t l_err = nullptr;
    uint32_t lidType = INVALID_TYPE;
    uint32_t curType = INVALID_TYPE;

    do {
        const TARGETING::Target * l_dimm = i_cur_image->getNvdimmTarget();

        // check Types match (same manufacturer and product)
        lidType = i_lid_image->getType();
        l_err = i_cur_image->getType(curType);
        if (l_err)
        {
            TRACFCOMP(g_trac_nvdimm,
                "isUpdateNeeded(): failed to find type of NVDIMM[%X]",
                TARGETING::get_huid(l_dimm));
            break;
        }

        if ((lidType == curType) && (lidType != INVALID_TYPE))
        {
            // check that versions do NOT match
            uint16_t curVersion = INVALID_VERSION;
            uint16_t lidVersion = i_lid_image->getVersion();
            l_err = i_cur_image->getVersion(curVersion);
            if (l_err)
            {
                TRACFCOMP(g_trac_nvdimm,
                    "isUpdateNeeded(): failed to find version of NVDIMM[%X]",
                    TARGETING::get_huid(l_dimm));
                break;
            }


            if (curVersion != lidVersion)
            {
                // verify we are updating with a good version
                if (lidVersion != INVALID_VERSION)
                {
                    // Found mismatched version and a valid lid update version
                    // so an update can proceed
                    o_update_needed = true;

                    TRACFCOMP(g_trac_nvdimm,
                        "NVDIMM[%X] code level - current: 0x%04X, new: 0x%04X",
                        TARGETING::get_huid(l_dimm),
                        le16toh(curVersion), le16toh(lidVersion));
                }
                else
                {
                    TRACFCOMP(g_trac_nvdimm, "NVDIMM[%X] has invalid version",
                        TARGETING::get_huid(l_dimm));
                }
            }
            else
            {
                TRACUCOMP(g_trac_nvdimm,
                    "Keeping current NVDIMM[%X] level: 0x%04X",
                    TARGETING::get_huid(l_dimm), le16toh(curVersion));
            }
        }
    } while (0);

    return l_err;
}

////////////////////////////////////////////////////////////////////////////////
// External function to update the NVDIMMs
////////////////////////////////////////////////////////////////////////////////
bool nvdimm_update(TARGETING::TargetHandleList &i_nvdimmList)
{
    NvdimmsUpdate l_nvdimmsUpdate(i_nvdimmList);
    return l_nvdimmsUpdate.runUpdate();
}

}; // end namespace NVDIMM
