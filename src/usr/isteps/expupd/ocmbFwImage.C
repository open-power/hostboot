/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/expupd/ocmbFwImage.C $                         */
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
#include "ocmbFwImage.H"
#include <expupd/ocmbFwImage_const.H>
#include <expupd/expupd_reasoncodes.H>
#include "expupd_trace.H"
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <algorithm>

#define EXPUPD_8BYTE_ALIGNED(_SIZE) (!(_SIZE & 0x7))

namespace expupd
{

/**
 * @brief Validates a tagged data triplet
 * @param[in] i_tripletPtr starting address of a tagged data triplet
 * @param[in] i_endDataPtr ending address of the OCMB firmware header
 * @param[out] o_imageInfo Structure will hold pointer to SHA512 hash (if found)
 * @param[out] o_numBytes total number of bytes used by this tagged data triplet
 * @return errlHndl_t indicating success or failure
 *
 */
errlHndl_t parseTaggedDataTriplet(const uint8_t* i_tripletPtr,
                                  const uint8_t* i_endDataPtr,
                                  rawImageInfo_t& o_imageInfo,
                                  uint32_t& o_numBytes)
{
    errlHndl_t l_err = nullptr;

    // Determine start of the data for the tagged data triplet
    const uint8_t* l_dataStartPtr = i_tripletPtr + sizeof(taggedTriplet_t);
    const taggedTriplet_t* l_ttPtr =
        reinterpret_cast<const taggedTriplet_t*>(i_tripletPtr);

    // Assume failure and set number of bytes consumed to 0
    o_numBytes = 0;

    do
    {
        // Check that we have enough room for the triplet
        if((l_dataStartPtr > i_endDataPtr) ||
           ((l_dataStartPtr + l_ttPtr->dataSize) > i_endDataPtr) ||
           !EXPUPD_8BYTE_ALIGNED(l_ttPtr->dataSize))
        {
            int64_t l_reqdSize = sizeof(taggedTriplet_t);
            l_reqdSize += (l_dataStartPtr > i_endDataPtr)? 0: l_ttPtr->dataSize;

            int64_t l_allocSize =
                reinterpret_cast<int64_t>(i_endDataPtr - i_tripletPtr);

            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "parseTaggedDataTriplet: Triplet does not fit or is"
                      " misaligned.  bytesReqd[%d] bytesAllocated[%d]",
                      l_reqdSize,
                      l_allocSize);

           /* @errorlog
            * @errortype       ERRL_SEV_PREDICTIVE
            * @moduleid        EXPUPD::MOD_PARSE_TAGGED_DATA_TRIPLET
            * @reasoncode      EXPUPD::INVALID_DATA_TRIPLET_SIZE
            * @userdata1       allocated size
            * @userdata2       required size
            * @devdesc         Tagged data triplet size is too big or misaligned
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         EXPUPD::MOD_PARSE_TAGGED_DATA_TRIPLET,
                                         EXPUPD::INVALID_DATA_TRIPLET_SIZE,
                                         l_allocSize,
                                         l_reqdSize,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Check for the SHA512 tag
        if(l_ttPtr->tagId == TAG_SHA512)
        {
            // Check that hash data is complete
            if(l_ttPtr->dataSize != HEADER_SHA512_SIZE)
            {
                TRACFCOMP(g_trac_expupd, ERR_MRK
                      "parseTaggedDataTriplet: Invalid hash triplet size."
                      " expected[%u] actual[%u]",
                      HEADER_SHA512_SIZE,
                      l_ttPtr->dataSize);

               /* @errorlog
                * @errortype       ERRL_SEV_PREDICTIVE
                * @moduleid        EXPUPD::MOD_PARSE_TAGGED_DATA_TRIPLET
                * @reasoncode      EXPUPD::INVALID_HASH_TRIPLET_SIZE
                * @userdata1       Expected Size
                * @userdata2       Actual Size
                * @devdesc         Incorrect hash size in OCMB image header
                * @custdesc        Error occurred during system boot.
                */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         EXPUPD::MOD_PARSE_TAGGED_DATA_TRIPLET,
                                         EXPUPD::INVALID_HASH_TRIPLET_SIZE,
                                         HEADER_SHA512_SIZE,
                                         l_ttPtr->dataSize,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

            // Save off pointer to hash for later.
            o_imageInfo.imageSHA512HashPtr = l_dataStartPtr;
        }
        else if(l_ttPtr->tagId == TAG_KEY_VALUE_PAIRS)
        {
            //trace up to MAX_BIN_TRACE bytes of the data in case it is useful
            TRACFBIN(g_trac_expupd, "OCMB FW IMAGE KEY/VALUE DATA",
                     l_dataStartPtr,
                     std::min(l_ttPtr->dataSize, MAX_BIN_TRACE));
        }
        else
        {
            //unsupported tag id.
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "parseTaggedDataTriplet: Invalid tag id[%u].",
                      l_ttPtr->tagId);

           /* @errorlog
            * @errortype       ERRL_SEV_PREDICTIVE
            * @moduleid        EXPUPD::MOD_PARSE_TAGGED_DATA_TRIPLET
            * @reasoncode      EXPUPD::INVALID_TAG_ID
            * @userdata1       tag id
            * @userdata2       <unused>
            * @devdesc         Invalid tag id found in OCMB image header
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         EXPUPD::MOD_PARSE_TAGGED_DATA_TRIPLET,
                                         EXPUPD::INVALID_TAG_ID,
                                         l_ttPtr->tagId,
                                         0,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        //Parsing was successful.  Set bytes consumed.
        o_numBytes = sizeof(taggedTriplet_t) + l_ttPtr->dataSize;
    }while(0);

    return l_err;
}

/**
 * @brief Validates OCMB firmware header of packaged image
 *
 * @param[in] i_imageStart Start address of packaged image
 * @param[in] i_imageSize Size of packaged image
 * @param[out] o_imageInfo Information pertaining to image after
 *             being stripped of OCMB firmware header
 * @return errlHndl_t indicating success or failure
 *
 */
errlHndl_t ocmbFwValidateImage(const uint64_t i_imageStart,
                               const uint64_t i_imageSize,
                               rawImageInfo_t& o_imageInfo)
{
    const uint8_t* l_imageStartPtr =
        reinterpret_cast<const uint8_t*>(i_imageStart);
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_expupd,
              ENTER_MRK "ocmbFwValidateImage(): startAddr[0x%016x] size[%u]",
                      i_imageStart, i_imageSize);

    //clear out o_imageInfo
    memset(&o_imageInfo, 0, sizeof(o_imageInfo));

    do
    {
        const uint64_t l_minHeaderSize =
                          sizeof(ocmbFwHeader_t) +
                          sizeof(taggedTriplet_t) + HEADER_SHA512_SIZE;

        const uint64_t l_maxHeaderSize =
                          std::min(static_cast<const uint64_t>(HEADER_MAX_SIZE),
                                  i_imageSize);

        // Check input parameters
        if((!l_imageStartPtr) || (i_imageSize < l_minHeaderSize))
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "ocmbFwValidateImage: Invalid image address[%p] or"
                      " size[%u]",
                      l_imageStartPtr, i_imageSize);

           /* @errorlog
            * @errortype       ERRL_SEV_PREDICTIVE
            * @moduleid        EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE
            * @reasoncode      EXPUPD::INVALID_PARMS
            * @userdata1       i_imageStart
            * @userdata2       i_imageSize
            * @devdesc         Invalid size or address for OCMB Flash Image
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE,
                                           EXPUPD::INVALID_PARMS,
                                           i_imageStart,
                                           i_imageSize,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        const ocmbFwHeader_t* l_header =
            reinterpret_cast<const ocmbFwHeader_t*>(l_imageStartPtr);

        // Check eye catcher value
        if(l_header->eyeCatcher != EYE_CATCHER_VALUE)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "ocmbFwValidateImage: Invalid eye catcher value: "
                      "expected[0x%016llx] actual[0x%016llx]",
                      EYE_CATCHER_VALUE, l_header->eyeCatcher);
           /* @errorlog
            * @errortype       ERRL_SEV_PREDICTIVE
            * @moduleid        EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE
            * @reasoncode      EXPUPD::INVALID_EYE_CATCHER
            * @userdata1       Expected Value
            * @userdata2       Actual Value
            * @devdesc         Invalid eye catcher value for OCMB Flash Image
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE,
                                           EXPUPD::INVALID_EYE_CATCHER,
                                           EYE_CATCHER_VALUE,
                                           l_header->eyeCatcher,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Check header version
        if((l_header->majorVersion != HEADER_VERSION_MAJOR) ||
           (l_header->minorVersion != HEADER_VERSION_MINOR))
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "ocmbFwValidateImage: Unsupported header version: %u.%u",
                      l_header->majorVersion, l_header->minorVersion);
           /* @errorlog
            * @errortype       ERRL_SEV_PREDICTIVE
            * @moduleid        EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE
            * @reasoncode      EXPUPD::INVALID_HEADER_VERSION
            * @userdata1       majorVersion
            * @userdata2       minorVersion
            * @devdesc         Invalid header version for OCMB Flash Image
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE,
                                           EXPUPD::INVALID_HEADER_VERSION,
                                           l_header->majorVersion,
                                           l_header->minorVersion,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        //Check that header size is within min/max range and 8byte aligned
        if((l_header->headerSize < l_minHeaderSize) ||
           (l_header->headerSize > l_maxHeaderSize) ||
           !EXPUPD_8BYTE_ALIGNED(l_header->headerSize))
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "ocmbFwValidateImage: Unsupported header size: %u bytes",
                      l_header->headerSize);
           /* @errorlog
            * @errortype       ERRL_SEV_PREDICTIVE
            * @moduleid        EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE
            * @reasoncode      EXPUPD::INVALID_HEADER_SIZE
            * @userdata1       header size
            * @userdata2       maximum allowed size
            * @devdesc         Invalid header size for OCMB Flash Image
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE,
                                           EXPUPD::INVALID_HEADER_SIZE,
                                           l_header->headerSize,
                                           l_maxHeaderSize,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Trace header information.
        TRACFCOMP(g_trac_expupd, "OCMB HEADER:  Version[%u.%u] size[%u]"
                  " triplets[%u]",
                 l_header->majorVersion,
                 l_header->minorVersion,
                 l_header->headerSize,
                 l_header->numTriplets);

        // Parse all tagged triplet data
        const uint8_t* l_curTripletPtr = l_imageStartPtr + sizeof(*l_header);
        const uint8_t* l_endDataPtr = l_imageStartPtr + l_header->headerSize;
        for(uint32_t l_curTriplet = 0;
            l_curTriplet < l_header->numTriplets;
            l_curTriplet++)
        {
            uint32_t l_numBytes = 0;

            // This will set o_imageInfo.imageSHA512Ptr if
            // SHA512 hash is found
            l_err = parseTaggedDataTriplet(l_curTripletPtr,
                                           l_endDataPtr,
                                           o_imageInfo,
                                           l_numBytes);
            if(l_err)
            {
                TRACFCOMP(g_trac_expupd, ERR_MRK
                      "ocmbFwValidateImage: Failed parsing tagged data"
                      " triplet %u of %u",
                      l_curTriplet + 1, l_header->numTriplets);
                break;
            }

            // Advance to next triplet
            l_curTripletPtr += l_numBytes;
        }
        if(l_err)
        {
            break;
        }

        // Check if we found a SHA512 hash in the header
        if(!o_imageInfo.imageSHA512HashPtr)
        {
            TRACFCOMP(g_trac_expupd, ERR_MRK
                      "ocmbFwValidateImage: No SHA512 Hash found in header!");
           /* @errorlog
            * @errortype       ERRL_SEV_PREDICTIVE
            * @moduleid        EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE
            * @reasoncode      EXPUPD::MISSING_SHA512_HASH
            * @userdata1       <unused>
            * @userdata2       <unused>
            * @devdesc         Missing SHA512 hash in OCMB Flash Image
            * @custdesc        Error occurred during system boot.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           EXPUPD::MOD_OCMB_FW_VALIDATE_IMAGE,
                                           EXPUPD::MISSING_SHA512_HASH,
                                           0, 0,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        //** Header is valid if we made it this far **

        // Trace the SHA512 hash
        TRACFBIN(g_trac_expupd, "OCMB FW IMAGE SHA512 HASH",
                 o_imageInfo.imageSHA512HashPtr, HEADER_SHA512_SIZE);

        // Set the image start address and size and we are done here.
        o_imageInfo.imagePtr = l_imageStartPtr + l_header->headerSize;
        o_imageInfo.imageSize = i_imageSize - l_header->headerSize;

    }while(0);

    TRACFCOMP(g_trac_expupd, EXIT_MRK "ocmbFwValidateImage()");
    return l_err;
}

} //namespace expupd

