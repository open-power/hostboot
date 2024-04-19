/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_ffdc_parser.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2024                        */
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

#include <stdlib.h>
#include <errl/errlentry.H>
#include <errl/errlreasoncodes.H>
#include <sbeio/sbeioreasoncodes.H>
#include <errl/errlmanager.H>
#include <errl/hberrltypes.H>
#include <util/utilbyte.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <sbeio/sbe_ffdc_package_parser.H>

#include <fapi2.H>
#include <set_sbe_error.H>

#include "sbe_fifodd.H"
#include <targeting/odyutil.H>                 // isOdysseyChip

/**
 * @file sbe_ffdc_parser.C
 * @brief SBE FFDC package parser
 */


extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"ffdcParser: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"ffdcParser: " printf_string,##args)
#define SBE_TRACU(args...)
#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"ffdcParser: " printf_string,##args)
#define SBE_TRACDBIN(printf_string,args...) \
    TRACDBIN(g_trac_sbeio,"ffdcParser: " printf_string,##args)


namespace SBEIO
{

SbeFFDCParser::~SbeFFDCParser()
{
    for(const auto & ffdcPackage : iv_ffdcPackages)
    {
        free(ffdcPackage->ffdcPtr);
        ffdcPackage->ffdcPtr = nullptr;
    }
}

/*
 * @brief Parses FFDC package(s) ffdcPackageBuffer
 *
 * P10 FFDC package according to the SBE Interface Specification:
 * Word 0:
 *     byte 0,1: Magic Byte: 0xFFDC
 *     byte 2,3: Length in words (N + 4)
 * Word 1:
 *     byte 0,1: Sequence Id
 *     byte 2  : Command Class
 *     byte 3  : Command
 * Word 2:
 *     byte 0-3: Return Code
 * Word 3:
 *     byte 0-3: FFDC Word 0
 * Word N:
 *     byte 0-3: FFDC Word N
 *
 * Odyssey FFDC package according to the SBE Interface Specification:
 * Word 0:
 *     byte 0,1: Magic Byte: 0xFBAD
 *     byte 2,3: Length in words (N + 5)
 * Word 1:
 *     byte 0,1: Sequence Id
 *     byte 2  : Command Class
 *     byte 3  : Command
 * Word 2:
 *     byte 0-1: SBE Log Identifier (SLID)
 *     byte 2  : Severity (fapi2::errlSeverity_t)
 *     byte 3  : Chip Id
 * Word 3:
 *     byte 0-3: Return Code
 * Word 4:
 *     byte 0-3: FFDC Word 0
 * Word N:
 *     byte 0-3: FFDC Word N
 */
void SbeFFDCParser::parseFFDCData(void * i_ffdcPackageBuffer)
{
    uint16_t l_magicByte = 0x00;
    size_t   i           = 0; // offset into the buffer
    errlHndl_t errl      = nullptr;
    uint8_t * ffdcPackageBuffer = static_cast<uint8_t *>(i_ffdcPackageBuffer);
    bool shouldSortBySlid = false;

    SBE_TRACF(ENTER_MRK "parseFFDCData");
    // Clear the internal vector of packages. If this function gets called more than once for any reason, we don't want
    // to accidentally duplicate FFDC data or jumble unrelated data together.
    iv_ffdcPackages.clear();

    do {
        // Magic Byte is 1st 2 bytes
        l_magicByte = UtilByte::bufferTo16uint(ffdcPackageBuffer + i);

        if ((l_magicByte == SbeFifo::FIFO_FFDC_MAGIC) || (l_magicByte == SbeFifo::FIFO_ODY_FFDC_MAGIC))
        {
            // Recognized a valid magic byte. Gather up relevant data to copy into an ffdc_package managed by this
            // object.

            // As noted above, P10 and Odyssey FFDC packages have slightly different structures. Odyssey needs to
            // collect a couple extra fields from its package. Whereas P10 will simply take reasonable defaults.
            uint8_t severity = fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE;
            uint16_t slid = 0; // Invalid value
            if (l_magicByte == SbeFifo::FIFO_ODY_FFDC_MAGIC)
            {
                shouldSortBySlid = true;
                // For Odyssey, collect the SLID and severity
                // Get the SLID from the package header. Word 2.
                slid = UtilByte::bufferTo16uint(ffdcPackageBuffer
                                               + i
                                               + SLID_OFFSET);

                // Get the log severity by advancing past the SLID. They are in the same word.
                severity = *(ffdcPackageBuffer
                             + i
                             + SLID_OFFSET
                             + sizeof(uint16_t)); // Slid size
            }

            // P10 and Odyssey header sizes are different from one another. Have to account for that in the
            // pointer math below.
            const uint8_t HDR_SIZE_IN_BYTES = (l_magicByte == SbeFifo::FIFO_ODY_FFDC_MAGIC)
                                           ? HEADER_SIZE_IN_BYTES_ODYSSEY
                                           : HEADER_SIZE_IN_BYTES;
            /*
             * Length is next 2 bytes (in words, each word is 4 bytes)
             * See comment block above this function for detailed layout of the package
             */
            const uint16_t PACKAGE_LENGTH_IN_WORDS = UtilByte::bufferTo16uint(ffdcPackageBuffer
                                                   + i
                                                   + sizeof(l_magicByte));

            /*
             * Get the Return Code - final word of the header
             * Subtract size of uint32_t from header size to rewind to start of return code.
             */
            const uint32_t FFDC_RETURN_CODE = UtilByte::bufferTo32uint(ffdcPackageBuffer
                                            + i
                                            + (HDR_SIZE_IN_BYTES - sizeof(uint32_t)));

            /*
             * Get the length in bytes of the FFDC Word data contained in the FFDC Package. Later, we'll copy all the
             * FFDC words into a buffer.
             */
            const uint32_t FFDC_BUFFER_LENGTH_IN_BYTES = (sizeof(uint32_t) * PACKAGE_LENGTH_IN_WORDS)
                                                       - HDR_SIZE_IN_BYTES;

            // Check to see if what we're copying is beyond the buffer size.
            const uint32_t OFFSET_INTO_FFDC_BUFFER = i + HDR_SIZE_IN_BYTES + FFDC_BUFFER_LENGTH_IN_BYTES;

            // There are different maximum amount of pages based on the Magic Byte
            const uint32_t SBE_FFDC_MAX_PAGES = (l_magicByte == SbeFifo::FIFO_ODY_FFDC_MAGIC) ?
                                                  SBE_FFDC_MAX_PAGES_POZ : SBE_FFDC_MAX_PAGES_P10;

            if(OFFSET_INTO_FFDC_BUFFER > (PAGESIZE * SBE_FFDC_MAX_PAGES))
            {
                SBE_TRACF(ERR_MRK"parseFFDCData: FFDC Package buffer overflow detected: "
                                 "FFDC_MAGIC = 0x%X, OFFSET = 0x%X, max size = 0x%X",
                                 l_magicByte, OFFSET_INTO_FFDC_BUFFER, SBE_FFDC_MAX_PAGES);

                /*@
                 * @errortype
                 * @moduleid          SBEIO_FFDC_PARSER
                 * @reasoncode        SBEIO_FFDC_PARSER_BUFF_OVERFLOW
                 * @userdata1[00:63]  Size of FFDC package that overflows the buffer
                 * @userdata2[00:31]  Magic Byte
                 * @userdata2[32:63]  SBE FFDC MAX PAGES
                 * @devdesc           If the size of the FFDC package exceeds our
                 *                    allocated buffer size, we log it.
                 * @custdesc          Firmware error communicating with a chip
                 */

                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        SBEIO_FFDC_PARSER,
                        SBEIO_FFDC_PARSER_BUFF_OVERFLOW,
                        errl_util::SrcUserData(
                            errl_util::bits{0,63},OFFSET_INTO_FFDC_BUFFER),
                        errl_util::SrcUserData(
                            errl_util::bits{0,31},l_magicByte,
                            errl_util::bits{32,63},SBE_FFDC_MAX_PAGES));
                errl->collectTrace(SBEIO_COMP_NAME);
                errlCommit(errl, SBEIO_COMP_ID);
                break;
            }
            else
            {
                // Copy just the FFDC data from ffdcPackageBuffer to wordBuffer
                // starting at the offset to the current FFDC package + header size.
                // The rest of the package data will be stored as fields in the ffdc_package struct
                // or discarded as unused.
                void * l_wordBuffer = ffdcPackageBuffer
                                    + i
                                    + HDR_SIZE_IN_BYTES;

                addFFDCPackage(l_wordBuffer, FFDC_RETURN_CODE, FFDC_BUFFER_LENGTH_IN_BYTES, slid, severity);

            }

            // Skip length of whole package
            i += PACKAGE_LENGTH_IN_WORDS * sizeof(uint32_t);
        }
        else
        {
            // If an unrecognized FFDC magic byte is seen then quit parsing. The buffer length is unknown so there
            // is no way to know if the unrecognized byte is user error or just whatever is past the end of the buffer.
            break;
        }
    } while (1);

    // Done parsing, now sort by SLID. P10 doesn't have SLID, no need to sort in that case.
    if (shouldSortBySlid)
    {
        std::sort(iv_ffdcPackages.begin(), iv_ffdcPackages.end(),
                  [](auto & packageA, auto & packageB)
                  {
                      if (packageA->slid == packageB->slid)
                      {
                          // In the event the SLIDs are the same, then the packages need to be sorted based on RC
                          // The ordering will be for RCs where HWP < PLAT < 0  because we want to reduce
                          // the number of individual PELs generated by the SBE FFDC while prioritizing parseable FFDC
                          // over non-parseable (RC=0). See generateSbeErrors() for more detail.
                          if (packageA->rc == packageB->rc)
                          {
                              // The RCs between A and B are the same, required to return false to satisfy
                              // strict weak ordering (A < B).
                              return false;
                          }
                          if (packageA->rc != fapi2::FAPI2_RC_PLAT_ERR_SEE_DATA)
                          {
                             // A is not plat.
                             if (packageA->rc == 0)
                             {
                                 // A is RC=0. A never preceeds B.
                                 return false;
                             }
                             else
                             {
                                 // A is HWP RC, A preceeds B.
                                 return true;
                             }
                          }
                          else
                          {
                             // A is PLAT RC.
                             if (packageB->rc == 0)
                             {
                                 // A is PLAT, B is RC=0. A preceeds B.
                                 return true;
                             }
                             else
                             {
                                 // A is PLAT, B is either HWP or PLAT RC. A never preceeds B.
                                 // if B is HWP then HWP < PLAT.
                                 // if B is PLAT then A < B to enforce strict weak ordering.
                                 return false;
                             }
                          }
                      }
                      // A and Bs SLIDs do not match.
                      return packageA->slid < packageB->slid;
                  });
    }

    SBE_TRACD(EXIT_MRK "parseFFDCData");
}

errlHndl_t SbeFFDCParser::generateSbeErrors(TARGETING::TargetHandle_t i_target,
                                                         const uint8_t i_modId,
                                                         const uint16_t i_reasonCode,
                                                         const uint64_t i_userdata1,
                                                         const uint64_t i_userdata2)
{
    // The SBE could have multiple errors it wants to create for context. During the process of creating the logs
    // use a vector to store them. Later, aggregate all the logs together since one needs to be the main log and
    // we don't want to create an unnecessary log to be the main log.
    std::vector<errlHndl_t> sbeErrors;
    errlHndl_t slidErrl = nullptr;
    uint8_t UDT_FORMAT_TYPE = SBEIO_UDT_PARAMETERS; // default to the SBE PROC format, uses the o3500.py parser style
    if (TARGETING::UTIL::isOdysseyChip(i_target))
    {
        UDT_FORMAT_TYPE = SBEIO_UDT_SPPE_FORMAT; // Use the o4500.py parser style
    }

    // Track when SLID groups change.
    size_t currentSlid = 0;

    // Iterate over all the packages and handle them in batches of matching SLID. The SLID indicates which
    // errors/packages belong together.
    for (const auto & package : iv_ffdcPackages)
    {
        if (currentSlid != package->slid)
        {
            // New SLID detected.
            currentSlid = package->slid;
            if (slidErrl != nullptr)
            {
                // Add existing error to the list of return logs
                slidErrl->collectTrace(SBEIO_COMP_NAME);
                sbeErrors.push_back(slidErrl);

                slidErrl = nullptr;
            }
        }

        // There are three forms the package RC can take: Hardware Procedure RC, Platform RC, and RC=0. Each will be
        // handled differently below. The list of packages have been sorted in parseFFDCData() so that HWP RCs appear
        // first in the SLID grouping, followed by Plat RCs, and finally RC=0 packages.
        //
        // This is done to reduce the number of logs generated from the same SLID group. HWP RCs go first because
        // Hostboot has to call FAPI_SET_SBE_ERROR to create the HWP error log. After that, it's easy to append PLAT RC
        // data to that existing log. RC=0 is always last because Hostboot doesn't have a way to parse the data that
        // comes back with RC=0 so it's added as unformated data for SBE to look over.
        if ((package->rc != fapi2::FAPI2_RC_PLAT_ERR_SEE_DATA) && (package->rc != 0))
        {
            // RC is not PLAT or 0, so it must be a hardware procedure RC.

            if (slidErrl != nullptr)
            {
                SBE_TRACF(ERR_MRK"ERROR: SBE sent two HWP RCs with the same SLID, this is a code bug.");
                // There should never be two HWP RCs with the same SLID. This is an SBE code bug.
                slidErrl->addProcedureCallout(HWAS::EPUB_PRC_SBE_CODE,
                                              HWAS::SRCI_PRIORITY_HIGH);

                slidErrl->collectTrace(SBEIO_COMP_NAME);
                // Add the existing log to the list and allow the second log to be created.
                sbeErrors.push_back(slidErrl);
                slidErrl = nullptr;

            }
            using namespace fapi2;
            ReturnCode fapiRC;

            /*
             * Put FFDC data into sbeFfdc_t struct and
             * call FAPI_SET_SBE_ERROR
             */
            sbeFfdc_t * ffdcBuf = reinterpret_cast<sbeFfdc_t * >(package->ffdcPtr);

            FAPI_SET_SBE_ERROR(fapiRC,
                               package->rc,
                               ffdcBuf,
                               i_target->getAttr<TARGETING::ATTR_FAPI_POS>(),
                               convertTargetingTypeToFapi2(i_target->getAttr<TARGETING::ATTR_TYPE>()));

            slidErrl = rcToErrl(fapiRC,
                                package->severity,
                                RC_HWP_GENERATED_SBE_ERROR);

            if (slidErrl != nullptr)
            {
                slidErrl->setErrorType(package->rc);
                slidErrl->collectTrace(FAPI_TRACE_NAME);
            }
        }
        else if (package->rc == fapi2::FAPI2_RC_PLAT_ERR_SEE_DATA)
        {
            if (slidErrl == nullptr)
            {
                // Create new error for this SLID
                //     severity comes from ffdc package
                slidErrl = new ERRORLOG::ErrlEntry(package->severity,
                                                   i_modId,
                                                   i_reasonCode,
                                                   i_userdata1,
                                                   i_userdata2);

            }
            else
            {
                // An error was already created earlier.
                // If severity of this package exceeds severity of slid-pel then upgrade severity
                if (((package->severity == ERRORLOG::ERRL_SEV_UNRECOVERABLE)
                        && (slidErrl->sev() != package->severity))
                    || ((package->severity == ERRORLOG::ERRL_SEV_PREDICTIVE)
                        && (slidErrl->sev() == ERRORLOG::ERRL_SEV_RECOVERED)))
                {
                    slidErrl->setSev(package->severity);
                }
            }

            // Add (platform) data to error
            slidErrl->addFFDC(SBEIO_COMP_ID,
                              package->ffdcPtr,
                              package->size,
                              0, /* version */
                              UDT_FORMAT_TYPE,
                              false /* Do not merge*/);
        }
        else // RC==0
        {
            if (slidErrl == nullptr)
            {
                // Create new error for this SLID
                slidErrl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                                   i_modId,
                                                   i_reasonCode,
                                                   i_userdata1,
                                                   i_userdata2);

            }
            // For now, rc == 0 will have its data stuffed into a log as unformatted data. SBE team has said that RC=0
            // means no failure on the part of the SBE but they will sometimes send data back anyway.
            // At present there is no way to distingiush between PLAT error or HWP error RC=0 cases. So this
            // data may only be understood by SBE team.
            slidErrl->addFFDC(SBEIO_COMP_ID,
                              package->ffdcPtr,
                              package->size,
                              0,
                              SBEIO_UDT_NO_FORMAT,
                              false );

            slidErrl->addProcedureCallout(HWAS::EPUB_PRC_SBE_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH);

            SBE_TRACF(ERR_MRK"ERROR: SBE sent RC=0. This is a code bug on their part. ERRL %.8x",
                      ERRL_GETEID_SAFE(slidErrl));

        }

        if (slidErrl != nullptr)
        {
            // If FFDC schema is known and a processing routine is defined then perform the processing.
            // For scom PIB errors, addFruCallouts is invoked. Only processing known FFDC schemas protects us
            // from trying to process FFDC formats we do not anticipate. For example, the SBE can send user and
            // attribute FFDC information after the Scom Error FFDC. We do not want to process that type of data here.
            // Ignore the return value, in this context it doesn't do anything for the logic of this function.
            FfdcParsedPackage::doDefaultProcessing(*package,
                                                   i_target,
                                                   slidErrl);
        }
    }

    // Aggregate all the errors together. There isn't any one error log that ought to be the main one so it doesn't
    // matter which is returned as the main log.
    ERRORLOG::aggregate(slidErrl, sbeErrors);

    // Return aggregated list of all logs made to caller to deal with (add callouts or whatever)
    return slidErrl;
}

/*
 * @brief returns total FFDC packages found
 */
size_t SbeFFDCParser::getTotalPackages()
{
    return iv_ffdcPackages.size();
}

/*
 * @brief returns the size (bytes) of the FFDC package
 */
uint32_t SbeFFDCParser::getPackageLength(const size_t i_index)
{
    uint32_t l_retLen = 0;
    if(isIndexValid(i_index))
    {
        l_retLen = iv_ffdcPackages.at(i_index)->size;
    }
    return l_retLen;
}

/*
 * @brief returns the pointer to the FFDC package
 */
void * SbeFFDCParser::getFFDCPackage(const size_t i_index)
{
    void *l_retPtr = nullptr;
    if(isIndexValid(i_index))
    {
        l_retPtr =  iv_ffdcPackages.at(i_index)->ffdcPtr;
    }
    return l_retPtr;
}

/*
 * @brief returns the FFDC package
 */
bool SbeFFDCParser::getFFDCPackage(const size_t i_index, ffdc_package& o_package)
{
    bool retval{false};
    if(isIndexValid(i_index))
    {
        ffdc_package * l_ffdcPkg = iv_ffdcPackages.at(i_index).get();
        if(l_ffdcPkg)
        {
            o_package = *l_ffdcPkg;
            retval = true;
        }
    }
    return retval;
}

/*
 * @brief returns the RC word
 */
uint32_t SbeFFDCParser::getPackageRC(const size_t i_index)
{
    uint32_t l_retRc = 0;
    if(isIndexValid(i_index))
    {
        l_retRc = iv_ffdcPackages.at(i_index)->rc;
    }
    return l_retRc;
}

uint16_t SbeFFDCParser::getPackageSlid(const size_t i_index)
{
    uint16_t l_slid = 0;
    if (isIndexValid(i_index))
    {
        l_slid = iv_ffdcPackages.at(i_index)->slid;
    }
    return l_slid;
}

ERRORLOG::errlSeverity_t SbeFFDCParser::getPackageSeverity(const size_t i_index)
{
    // Fetch the value from the package
    ERRORLOG::errlSeverity_t l_sev = ERRORLOG::ERRL_SEV_UNRECOVERABLE;
    if (isIndexValid(i_index))
    {
        l_sev = iv_ffdcPackages.at(i_index)->severity;
    }

    return l_sev;
}

ERRORLOG::errlSeverity_t SbeFFDCParser::setSeverity(const uint8_t i_sev)
{
    // Default to unrecoverable.
    // For P10, this is the only severity used.
    ERRORLOG::errlSeverity_t errlSev = ERRORLOG::ERRL_SEV_UNRECOVERABLE;

    // These are the only supported types in fapi2::errlSeverity_t that map to ERRORLOG::errlSeverity_t
    // Since we're casting to ERRORLOG::errlSeverity_t because we need to use this field to create the log
    // severity let's make sure these stay in sync.
    static_assert(static_cast<size_t>(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                  == static_cast<size_t>(ERRORLOG::ERRL_SEV_RECOVERED));
    static_assert(static_cast<size_t>(fapi2::FAPI2_ERRL_SEV_PREDICTIVE)
                  == static_cast<size_t>(ERRORLOG::ERRL_SEV_PREDICTIVE));
    static_assert(static_cast<size_t>(fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE)
                  == static_cast<size_t>(ERRORLOG::ERRL_SEV_UNRECOVERABLE));

    // Cast value to fapi2::errlSeverity_t and check it matches one of those values. There are fewer of those than what
    // hostboot has. So if fapi2 has a need in the future to add another severity that hostboot has this code should be
    // updated to reflect those changes.
    fapi2::errlSeverity_t fapiSev = static_cast<fapi2::errlSeverity_t>(i_sev);

    bool valid = false;
    switch(fapiSev)
    {
        case fapi2::FAPI2_ERRL_SEV_RECOVERED:
        case fapi2::FAPI2_ERRL_SEV_PREDICTIVE:
        case fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE:
        {
            // These are supported
            valid = true;
            break;
        }
        case fapi2::FAPI2_ERRL_SEV_UNDEFINED:
        {
            // This maps to ERRORLOG::errlSeverity_t::ERRL_SEV_INFORMATIONAL in hostboot. This is not valid.
            break;
        }
    }

    // Only update from ERRL_SEV_UNRECOVERABLE if we detected a valid mapping between fapi2 and hostboot.
    // If hostboot got garbage in this field probably best to err on the side of visibility.
    if (valid)
    {
        // Cast to ERRORLOG::errlSeverity_t enum.
        errlSev = static_cast<ERRORLOG::errlSeverity_t>(i_sev);
    }

    return errlSev;
}

/*
 * @brief add ffdc package into the ffdc_package struct
 * and push it to the list
 */
void SbeFFDCParser::addFFDCPackage(void * i_ffdcPackage,
                                   const uint32_t i_rc, const uint32_t i_packageLen,
                                   const uint16_t i_slid, const uint8_t i_sev)
{
    std::unique_ptr<ffdc_package> l_ffdcPkg = std::make_unique<ffdc_package>();
    l_ffdcPkg->rc = i_rc;
    l_ffdcPkg->size = i_packageLen;
    l_ffdcPkg->slid = i_slid;
    l_ffdcPkg->severity = setSeverity(i_sev);

    l_ffdcPkg->ffdcPtr = malloc(i_packageLen);
    memcpy(l_ffdcPkg->ffdcPtr, i_ffdcPackage, i_packageLen);
    iv_ffdcPackages.push_back(std::move(l_ffdcPkg));
}

PIB::PibError  SbeFFDCParser::getPibRc(const size_t i_index)
{
    PIB::PibError l_pibRc   = PIB::PIB_NO_ERROR;

    //get the rc for this ffdc package
    auto l_fapiRc           = getPackageRC(i_index);

    //check if it is a fapi2::PIBRC
    //if yes, convert to PIBERROR value
    switch(l_fapiRc)
    {
        case fapi2::RC_SBE_PIB_XSCOM_ERROR:
        case fapi2::RC_POZ_PIB_XSCOM_ERROR:
            l_pibRc = PIB::PIB_RESOURCE_OCCUPIED;
            break;

        case fapi2::RC_SBE_PIB_OFFLINE_ERROR:
        case fapi2::RC_POZ_PIB_OFFLINE_ERROR:
            l_pibRc = PIB::PIB_CHIPLET_OFFLINE;
            break;

        case fapi2::RC_SBE_PIB_PARTIAL_ERROR:
        case fapi2::RC_POZ_PIB_PARTIAL_ERROR:
            l_pibRc = PIB::PIB_PARTIAL_GOOD;
            break;

        case fapi2::RC_SBE_PIB_ADDRESS_ERROR:
        case fapi2::RC_POZ_PIB_ADDRESS_ERROR:
            l_pibRc = PIB::PIB_INVALID_ADDRESS;
            break;

        case fapi2::RC_SBE_PIB_CLOCK_ERROR:
        case fapi2::RC_POZ_PIB_CLOCK_ERROR:
            l_pibRc = PIB::PIB_CLOCK_ERROR;
            break;

        case fapi2::RC_SBE_PIB_PARITY_ERROR:
        case fapi2::RC_POZ_PIB_PARITY_ERROR:
            l_pibRc = PIB::PIB_PARITY_ERROR;
            break;

        case fapi2::RC_SBE_PIB_TIMEOUT_ERROR:
        case fapi2::RC_POZ_PIB_TIMEOUT_ERROR:
            l_pibRc = PIB::PIB_TIMEOUT;
            break;

        case fapi2::FAPI2_RC_SUCCESS:
            l_pibRc = PIB::PIB_NO_ERROR;
            break;
    }
    SBE_TRACF("getPibRc for index=%d, fapiRc=0x%x pibRc:%0x", i_index, l_fapiRc, l_pibRc);

    return l_pibRc;
}
}
