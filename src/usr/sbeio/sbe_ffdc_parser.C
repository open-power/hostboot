/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_ffdc_parser.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
    uint8_t i;
    for(i = 0; i < iv_ffdcPackages.size(); i++)
    {
        if(iv_ffdcPackages[i]->ffdcPtr != NULL)
        {
            free((void *) iv_ffdcPackages[i]->ffdcPtr);
        }
    }
    iv_ffdcPackages.clear();
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
    uint8_t            i = 0;
    errlHndl_t errl      = NULL;

    SBE_TRACD(ENTER_MRK "parseFFDCData");
    do {
        // Magic Byte is 1st 2 bytes
        l_magicByte = UtilByte::bufferTo16uint(
                    static_cast<char *>(i_ffdcPackageBuffer) + i);

        if(l_magicByte == iv_ffdcMagicByte)
        {
            /*
             * Length is next 2 bytes (in words, each word is 4 bytes)
             * In FFDC packet, byte 2 & byte 3 holds the length in words,
             * which is 4 words less than the total package length.
             */
            uint16_t l_packageLengthInWords = UtilByte::bufferTo16uint(
                  static_cast<char *>(i_ffdcPackageBuffer) +
                  i + sizeof(l_magicByte));

            /*
             * Get the Return Code - should be 8 bytes from beginning
             */
            uint32_t l_rc = UtilByte::bufferTo32uint(
                  static_cast<char *>(i_ffdcPackageBuffer) +
                  i + iv_headerWordInBytes);

            /*
             * Get the length in bytes of the FFDC data contained in the FFDC Package
             * = the entire package length - the header (8 bytes) - the rc (4 bytes)
             */
            uint32_t l_bufLenInBytes = iv_ffdcWordLen * l_packageLengthInWords -
                 iv_headerWordInBytes - iv_ffdcWordLen;

            // Check to see if what we're copying is beyond the buffer size
            uint32_t l_bufferMarker = i + iv_headerWordInBytes + l_bufLenInBytes;
            if(l_bufferMarker > PAGESIZE * iv_ffdcPackageSize)
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
                                 TO_UINT64(l_bufferMarker),
                                 0);
                errl->collectTrace(SBEIO_COMP_NAME);
                errlCommit(errl, SBEIO_COMP_ID);

                break;
            }
            else
            {
                // Extract the words and add to errl
                void * l_wordBuffer = (void *) malloc(l_bufLenInBytes);
                if(l_wordBuffer == NULL)
                {
                    SBE_TRACF(ERR_MRK"parseFFDCData: Failure to allocate memory: wordBuffer.");
                    break;
                }

                // Copy just the FFDC data from ffdcPackageBuffer to wordBuffer
                // starting at the offset to the current FFDC package + 12 bytes
                // to skip the FFDC header (8 bytes) and rc (4 bytes)
                memcpy(l_wordBuffer,
                       static_cast<char *>(i_ffdcPackageBuffer) +
                       i + iv_headerWordInBytes + iv_ffdcWordLen,
                       l_bufLenInBytes);

                addFFDCPackage(l_wordBuffer, l_rc, l_bufLenInBytes);

                free(l_wordBuffer);
            }

            // Skip length of whole package
            i += l_packageLengthInWords * iv_ffdcWordLen;
        }
        else
        {
            SBE_TRACD(ERR_MRK"parseFFDCData: Invalid FFDC Magic Byte: 0x%04lx",
                      l_magicByte);
            break;
        }
    } while (l_magicByte != 0x00);


    SBE_TRACD(EXIT_MRK "parseFFDCData");
}

/*
 * @brief returns total FFDC packages found
 */
uint8_t SbeFFDCParser::getTotalPackages()
{
    return iv_ffdcPackages.size();
}

/*
 * @brief returns the size (bytes) of the FFDC package
 */
uint32_t SbeFFDCParser::getPackageLength(uint8_t i_index)
{
    uint32_t l_retLen = 0;
    uint8_t l_size = getTotalPackages();
    if((i_index >= 0) && (i_index <= l_size))
    {
        ffdc_package *l_ffdcPkg = iv_ffdcPackages.at(i_index);
        l_retLen = l_ffdcPkg->size;
    }
    return l_retLen;
}

/*
 * @brief returns the pointer to the FFDC package
 */
void * SbeFFDCParser::getFFDCPackage(uint8_t i_index)
{
    void *l_retPtr = NULL;
    uint8_t l_size = getTotalPackages();
    if((i_index >= 0) && (i_index <= l_size))
    {
        ffdc_package *l_ffdcPkg = iv_ffdcPackages.at(i_index);
        l_retPtr = l_ffdcPkg->ffdcPtr;
    }
    return l_retPtr;
}

/*
 * @brief returns the FFDC package
 */
bool SbeFFDCParser::getFFDCPackage(uint8_t i_index, ffdc_package& o_package)
{
    bool retval{false};
    uint8_t l_size = getTotalPackages();
    if((i_index >= 0) && (i_index < l_size))
    {
        ffdc_package *l_ffdcPkg = iv_ffdcPackages.at(i_index);
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
uint32_t SbeFFDCParser::getPackageRC(uint8_t i_index)
{
    uint32_t l_retRc = 0;
    uint8_t l_size = getTotalPackages();
    if((i_index >= 0) && (i_index <= l_size))
    {
        ffdc_package *l_ffdcPkg = iv_ffdcPackages.at(i_index);
        l_retRc = l_ffdcPkg->rc;
    }
    return l_retRc;
}

/*
 * @brief add ffdc package into the ffdc_package struct
 * and push it to the list
 */
void SbeFFDCParser::addFFDCPackage(void * i_ffdcPackage,
                                   uint32_t i_rc, uint32_t i_packageLen)
{
    ffdc_package * l_ffdcPkg = new ffdc_package();
    l_ffdcPkg->rc = i_rc;
    l_ffdcPkg->size = i_packageLen;

    l_ffdcPkg->ffdcPtr = (void *) malloc(i_packageLen);
    if(l_ffdcPkg->ffdcPtr == NULL)
    {
        SBE_TRACF(ERR_MRK"parseFFDCData: Failure to allocate memory: FFDC ptr.");
        return;
    }
    memcpy((void *) l_ffdcPkg->ffdcPtr, i_ffdcPackage, i_packageLen);
    iv_ffdcPackages.push_back(l_ffdcPkg);
}

PIB::PibError  SbeFFDCParser::getPibRc(uint8_t i_index)
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
