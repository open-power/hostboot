/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_ffdc_parser.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
#include <util/utilbyte.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <fapi2.H>

#include "sbe_fifodd.H"

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
 * FFDC package according to the SBE Interface Specification:
 * Dword 0:
 *     byte 0,1: Magic Byte: 0xFFDC
 *     byte 2,3: Length in words (N + 4)
 *     byte 4,5: Sequence Id
 *     byte 6  : Command Class
 *     byte 7  : Command
 * Dword 1:
 *     byte 0-3: Return Code
 *     byte 4-7: Word 0
 * Dword M:
 *     byte 0-3: Word N - 1
 *     byte 4-7: Word N
 */
void SbeFFDCParser::parseFFDCData(void * i_ffdcPackageBuffer)
{
    uint16_t l_magicByte = 0x00;
    size_t   i           = 0;
    errlHndl_t errl      = nullptr;

    SBE_TRACF(ENTER_MRK "parseFFDCData");
    do {
        // Magic Byte is 1st 2 bytes
        l_magicByte = UtilByte::bufferTo16uint(static_cast<char *>(i_ffdcPackageBuffer) + i);

        if ((l_magicByte == SbeFifo::FIFO_FFDC_MAGIC) || (l_magicByte == SbeFifo::FIFO_ODY_FFDC_MAGIC))
        {
            // P10 and Odyssey header sizes are different from one another. Have to account for that in the
            // pointer math below.
            const uint8_t HDR_SIZE_IN_BYTES = (l_magicByte == SbeFifo::FIFO_ODY_FFDC_MAGIC)
                                           ? HEADER_SIZE_IN_BYTES_ODYSSEY
                                           : HEADER_SIZE_IN_BYTES;
            /*
             * Length is next 2 bytes (in words, each word is 4 bytes)
             * In FFDC packet, byte 2 & byte 3 holds the length in words,
             * which is 4 words less than the total package length.
             */
            const uint16_t PACKAGE_LENGTH_IN_WORDS = UtilByte::bufferTo16uint(static_cast<char *>(i_ffdcPackageBuffer) +
                                                   i + sizeof(l_magicByte));

            /*
             * Get the Return Code - final word of the header
             */
            const uint32_t FFDC_RETURN_CODE = UtilByte::bufferTo32uint(static_cast<char *>(i_ffdcPackageBuffer)
                                            + i
                                            + (HDR_SIZE_IN_BYTES - sizeof(uint32_t)));

            /*
             * Get the length in bytes of the FFDC data contained in the FFDC Package.
             */
            const uint32_t FFDC_BUFFER_LENGTH_IN_BYTES = (sizeof(uint32_t) * PACKAGE_LENGTH_IN_WORDS) - HDR_SIZE_IN_BYTES;

            // Check to see if what we're copying is beyond the buffer size
            const uint32_t OFFSET_INTO_FFDC_BUFFER = i + HDR_SIZE_IN_BYTES + FFDC_BUFFER_LENGTH_IN_BYTES;
            if( OFFSET_INTO_FFDC_BUFFER > (PAGESIZE * SBE_FFDC_MAX_PAGES))
            {
                SBE_TRACF(ERR_MRK"parseFFDCData: FFDC Package buffer overflow detected.");

                /*@
                 * @errortype
                 * @moduleid     SBEIO_FFDC_PARSER
                 * @reasoncode   SBEIO_FFDC_PARSER_BUFF_OVERFLOW
                 * @userdata1    size of FFDC package that overflows the buffer
                 * @devdesc      If the size of the FFDC package exceeds our
                 *               allocated buffer size, we log it.
                 */

                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        SBEIO_FFDC_PARSER,
                        SBEIO_FFDC_PARSER_BUFF_OVERFLOW,
                        TO_UINT64(OFFSET_INTO_FFDC_BUFFER),
                        0);
                errl->collectTrace(SBEIO_COMP_NAME);
                errlCommit(errl, SBEIO_COMP_ID);

                break;
            }
            else
            {
                // Copy just the FFDC data from ffdcPackageBuffer to wordBuffer
                // starting at the offset to the current FFDC package + header size.
                void * l_wordBuffer = reinterpret_cast<uint8_t *>(i_ffdcPackageBuffer)
                                    + i
                                    + HDR_SIZE_IN_BYTES;

                // @TODO JIRA PFHB-260
                addFFDCPackage(l_wordBuffer, FFDC_RETURN_CODE, FFDC_BUFFER_LENGTH_IN_BYTES, 0, 0);

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

    SBE_TRACD(EXIT_MRK "parseFFDCData");
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
    uint16_t l_slid = 0; // 0 is invalid
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
            l_pibRc = PIB::PIB_RESOURCE_OCCUPIED;
            break;

        case fapi2::RC_SBE_PIB_OFFLINE_ERROR:
            l_pibRc = PIB::PIB_CHIPLET_OFFLINE;
            break;

        case fapi2::RC_SBE_PIB_PARTIAL_ERROR:
            l_pibRc = PIB::PIB_PARTIAL_GOOD;
            break;

        case fapi2::RC_SBE_PIB_ADDRESS_ERROR:
            l_pibRc = PIB::PIB_INVALID_ADDRESS;
            break;

        case fapi2::RC_SBE_PIB_CLOCK_ERROR:
            l_pibRc = PIB::PIB_CLOCK_ERROR;
            break;

        case fapi2::RC_SBE_PIB_PARITY_ERROR:
            l_pibRc = PIB::PIB_PARITY_ERROR;
            break;

        case fapi2::RC_SBE_PIB_TIMEOUT_ERROR:
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
