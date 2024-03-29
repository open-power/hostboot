/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlsrc.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2024                        */
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
 *  @file errlsrc.C
 *
 *  @brief Manage the data items that make up the 'PS' section in an
 *  error log PEL.  PS stands for Primary System Reference Code, or SRC.
 *  ErrlSrc is a derivation of ErrlSctn.
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hbotcompid.H>
#include <errl/errlentry.H>
#include <hwas/common/hwasCallout.H>  // SRCI PRIORITY
#include <targeting/targplatutil.H>
#include <util/misc.H>


namespace ERRORLOG
{


extern trace_desc_t* g_trac_errl;



//**************************************************************************
//  constructor


ErrlSrc::ErrlSrc( srcType_t i_srcType,
                  uint8_t   i_modId,
                  uint16_t  i_reasonCode,
                  uint64_t  i_user1,
                  uint64_t  i_user2 ) :

    ErrlSctn( ERRL_SID_PRIMARY_SRC,
              ErrlSrc::SLEN,
              ErrlSrc::VER,
              ErrlSrc::SST,
              0 ),  // Component ID zero for now.
    iv_srcType( i_srcType ),
    iv_modId( i_modId ),
    iv_reasonCode( i_reasonCode ),
    iv_ssid( EPUB_FIRMWARE_SUBSYS ),
    iv_user1( i_user1 ),
    iv_user2( i_user2 ),
    iv_deconfig(false),
    iv_gard(false)
{

#ifdef CONFIG_BUILD_FULL_PEL
    iv_progress_code = 0;
#ifndef __HOSTBOOT_RUNTIME
    if(Util::isTargetingLoaded() && TARGETING::targetService().isInitialized())
    {
        TARGETING::Target * l_node = TARGETING::UTIL::getCurrentNodeTarget();
        if (l_node)
        {
            iv_progress_code = l_node->getAttr<TARGETING::ATTR_LAST_PROGRESS_CODE>();
        }
    }
#endif
#endif
}


//****************************************************************************
//

ErrlSrc::~ErrlSrc()
{

}



//**************************************************************************
// Flatten the PS primary SRC data to a minimum standard 72-byte structure.
// Page numbers refer to Platform Event Log and SRC PLDD
// https://mcdoc.boeblingen.de.ibm.com/out/out.ViewDocument.php?documentid=1675
// Version 0.8 (markup). See also src/include/usr/errl/hberrltypes.H
// for the typedef pelSRCSection_t.

uint64_t ErrlSrc::flatten( void * o_pBuffer, const uint64_t i_cbBuffer )
{
    uint64_t l_rc = 0;

    do
    {
        if( i_cbBuffer < flatSize() )
        {
            TRACFCOMP( g_trac_errl, "ErrlSrc::flatten: buffer too small");
            break;
        }

        pelSRCSection_t * psrc = static_cast<pelSRCSection_t *>(o_pBuffer);

        // memset entire buffer to zero
        // flatSize will return pelSRCSection_t size plus FRU callout size
        memset( psrc, 0, flatSize() );

        // memset spaces into the char array
        memset( psrc->src.srcString, ' ', sizeof( psrc->src.srcString ));

        l_rc = iv_header.flatten( o_pBuffer, i_cbBuffer );
        if( 0 == l_rc )
        {
            // Rare.
            TRACFCOMP( g_trac_errl, "ErrlSrc::flatten: header flatten error");
            break;
        }


        // Place data into the flat structure.
        psrc->src.ver         = ErrlSrc::SRCVER;    // 2;
#ifdef CONFIG_BUILD_FULL_PEL
        // FRU callouts included
        if (!iv_coVec.empty())
        {
            // Flags bit 7 = 1: Additional subsections present
            // beyond ASCII character string field (FRU callout subsection)
            psrc->src.flags.additionalSubsection = 1;
        }
#endif
        psrc->src.wordcount   = ErrlSrc::WORDCOUNT; // 9;

        // Use reserved1 word to stash the reason code for easy extract in
        // unflatten rather than parsing srcString
        psrc->src.reserved1   = iv_reasonCode;

        CPPASSERT( ErrlSrc::SLEN == sizeof(pelSRCSection_t)-iv_header.flatSize());
        psrc->src.srcLength   = ErrlSrc::SLEN;

#ifdef CONFIG_BUILD_FULL_PEL
        // FRU callouts included
        if (!iv_coVec.empty())
        {
            // There are FRU callouts, add them to total src size
            psrc->src.srcLength += fruCalloutFlatSize();

            // Tell the PEL section header what the new length is.
            iv_header.iv_slen = psrc->src.srcLength + iv_header.flatSize();
        }

        // 4.3.3.4 Hex Data Word 4
        // Hex value of the SRC of the last progress code
        psrc->src.word4 = iv_progress_code;
#endif

        // SRC format
        psrc->src.word2       =  0x000000E0; // SRCI_HBT_FORMAT

        // Stash the Hostboot module id into hex word 3
        psrc->src.moduleId    = iv_modId;

        // set deconfigure and/or gard bits
        if (iv_deconfig)
        {
            psrc->src.word5 |= ErrlSrc::DECONFIG_BIT; // deconfigure
        }
        if (iv_gard)
        {
            psrc->src.word5 |= ErrlSrc::GARD_BIT; // GARD
        }

        // set ACK bit - means unacknowledged
        psrc->src.word5 |= ErrlSrc::ACK_BIT; // ACK

        // Stash the Hostboot long long words into the hexwords of the SRC.
        psrc->src.word6       = iv_user1;    // spans 6-7
        psrc->src.word8       = iv_user2;    // spans 8-9

        // Build the char string for the SRC.
        uint32_t l_u32;
        l_u32 = (iv_srcType<< 24)|(iv_ssid<<16)| iv_reasonCode;

        char l_tmpString[ 20 ];
        uint64_t cb = sprintf( l_tmpString, "%08X", l_u32 );
        memcpy( psrc->src.srcString, l_tmpString, cb );

#ifdef CONFIG_BUILD_FULL_PEL
        flattenFruCallouts(psrc);
#endif

        l_rc = flatSize();
    }
    while( 0 );

    return l_rc;
}

uint64_t ErrlSrc::unflatten( const void * i_buf)
{
    const pelSRCSection_t * p =
        static_cast<const pelSRCSection_t *>(i_buf);

    iv_header.unflatten(&(p->sectionheader));

    iv_srcType      = (srcType_t)((16 * aschex2bin(p->src.srcString[0])) +
                        aschex2bin(p->src.srcString[1]));
    iv_modId        = p->src.moduleId;
    iv_reasonCode   = p->src.reserved1;
    iv_ssid         = (epubSubSystem_t)((16 * aschex2bin(p->src.srcString[2])) +
                       aschex2bin(p->src.srcString[3]));
    iv_user1        = p->src.word6;
    iv_user2        = p->src.word8;
    iv_progress_code = p->src.word4;

    if(p->src.word5 & ErrlSrc::DECONFIG_BIT) // deconfigure
    {
        iv_deconfig = true;
    }
    if(p->src.word5 & ErrlSrc::GARD_BIT) // GARD
    {
        iv_gard = true;
    }
#ifdef CONFIG_BUILD_FULL_PEL
    // check if ErrlSrc contains any FRU callouts
    // FRU callouts are added after the base SRC data when building a full PEL
    // flatSize() at this point contains everything but the FRU callouts
    uint64_t baseSrcSize = flatSize();
    if ((iv_header.iv_slen - baseSrcSize) > 0)
    {
        const char* pBuf = static_cast<const char *>(i_buf);
        unflattenFruCallouts(pBuf + baseSrcSize, (iv_header.iv_slen - baseSrcSize));
    }
#endif
    return flatSize();
}

// Quick hexdigit to binary converter.
// Hopefull someday to replaced by strtoul
uint64_t ErrlSrc::aschex2bin(char c) const
{
    if(c >= 'a' && c <= 'f')
    {
        c = c + 10 - 'a';
    }
    else if (c >= 'A' && c <= 'F')
    {
        c = c + 10 - 'A';
    }
    else if (c >= '0' && c <= '9')
    {
       c -= '0';
    }
    // else it's not a hex digit, ignore

    return c;
}

#ifdef CONFIG_BUILD_FULL_PEL
bool ErrlSrc::checkForDuplicateCallout(fruCallOutEntry_t& io_co)
{
    // By default, add new callout to the vector
    bool retDup = false;

    // Compare new callout partNumber/locationCode to all in the vector
    for( auto it = iv_coVec.begin();
         it != iv_coVec.end();
         it++ )
    {
        if (0 == strcmp(io_co.locationCode, (*it).locationCode))
        {
            if (strlen(io_co.partNumber) == 0)
            {
                // MATCH - but the New_Callout partNumber is NULL
                // so discard the New_Callout as a duplicate
                retDup = true;
                break;
            }
            if (strlen((*it).partNumber) == 0)
            {
                // MATCH - but the Existing_Callout partNumber is NULL
                // so discard the Existing_Callout as a duplicate
                iv_coVec.erase(it);
                break;
            }
            if (0 == strcmp(io_co.partNumber, (*it).partNumber))
            {
                // MATCH - check the priority
                if (io_co.priority > (*it).priority)
                {
                    // New priority is higher, keep it.
                    // Erase the old callout entry
                    it = iv_coVec.erase(it);
                    break;
                }

                // New entry is a duplicate, don't add the new callout to the vector
                retDup = true;
                break;
            }
        }
    }
    return retDup;
}

void ErrlSrc::addFruCallout(fruCallOutEntry_t& io_co)
{
    do
    {
        // Check for duplicates
        if (checkForDuplicateCallout(io_co))
        {
            // Found duplicate, do not add new callout to the vector
            break;
        }

        // Add the new callout to the vector
        iv_coVec.push_back(io_co);

        // Sort the FRU callout vector by priority
        // Define a lambda comparator function for sorting criteria
        std::sort(iv_coVec.begin(),
                  iv_coVec.end(),
                  [](const fruCallOutEntry_t& i_priA,
                     const fruCallOutEntry_t& i_priB)
                    {
                        return (i_priA.priority > i_priB.priority);
                    }
                 );
    } while(0);
}


void ErrlSrc::maxFruCallouts()
{
    const uint32_t MAX_FRU_CALLOUTS = 10;

    // Limited number of FRU callouts allowed
    if (iv_coVec.size() > MAX_FRU_CALLOUTS)
    {
        TRACFCOMP( g_trac_errl,
            "ErrlSrc: %d FRU callouts > MAX_FRU_CALLOUTS(%d), removing extra",
            iv_coVec.size(), MAX_FRU_CALLOUTS);

        uint32_t l_overMax = iv_coVec.size() - MAX_FRU_CALLOUTS;
        while (l_overMax)
        {
            fruCallOutEntry_t l_coEnt = iv_coVec.back();
            TRACFCOMP( g_trac_errl,
                "Removing FRU callout with priority %c locationCode %s "
                "partNumber %s ccin %s serialNumber %s",
                hwasPriToFruPri(l_coEnt.priority), l_coEnt.locationCode,
                l_coEnt.partNumber, l_coEnt.ccin, l_coEnt.serialNumber);
            iv_coVec.pop_back();
            l_overMax--;
        }
    }
}


char ErrlSrc::hwasPriToFruPri( uint32_t i_hwasPri )
{
    // Default to LOW, undefined = LOW
    char retchar = 'L';

    switch( static_cast<HWAS::callOutPriority>(i_hwasPri) )
    {
        case HWAS::SRCI_PRIORITY_HIGH:
            retchar = 'H';
            break;
        case HWAS::SRCI_PRIORITY_MED:
            retchar = 'M';
            break;
        case HWAS::SRCI_PRIORITY_MEDA:
            retchar = 'A';
            break;
        case HWAS::SRCI_PRIORITY_MEDB:
            retchar = 'B';
            break;
        case HWAS::SRCI_PRIORITY_MEDC:
            retchar = 'C';
            break;
        case HWAS::SRCI_PRIORITY_LOW:
        case HWAS::SRCI_PRIORITY_NONE:
            retchar = 'L';
            break;
   }
   return retchar;
}

uint32_t ErrlSrc::fruPriToHwasPri( char i_fruPri )
{
    uint32_t hwasPri = HWAS::SRCI_PRIORITY_NONE;

    switch( i_fruPri )
    {
        case 'H':
            hwasPri = HWAS::SRCI_PRIORITY_HIGH;
            break;
        case 'M':
            hwasPri = HWAS::SRCI_PRIORITY_MED;
            break;
        case 'A':
            hwasPri = HWAS::SRCI_PRIORITY_MEDA;
            break;
        case 'B':
            hwasPri = HWAS::SRCI_PRIORITY_MEDB;
            break;
        case 'C':
            hwasPri = HWAS::SRCI_PRIORITY_MEDC;
            break;
        case 'L':
            hwasPri = HWAS::SRCI_PRIORITY_LOW;
            break;
        default:
            hwasPri = HWAS::SRCI_PRIORITY_NONE;
            break;
   }
   return hwasPri;
}

void ErrlSrc::unflattenFruCallouts(const void* i_pFruCallouts, uint64_t i_flatSize)
{
    const pelSubSectionHeader_t * pHeader = reinterpret_cast<const pelSubSectionHeader_t *>(i_pFruCallouts);
    uint64_t bytesAvailable = pHeader->sslen * 4; // # words including header
    uint64_t bytesUsed = sizeof(pelSubSectionHeader_t);

    // safety check to avoid accessing memory out-of-bounds
    if (i_flatSize != bytesAvailable)
    {
        TRACFCOMP(g_trac_errl, "ErrlSrc::unflattenFruCallouts(): size mismatch (%lld vs expected %lld)",
            bytesAvailable, i_flatSize);

        // cause early exit if not enough bytes are in remaining flatSize
        if (i_flatSize < bytesAvailable)
        {
            bytesUsed = bytesAvailable;
        }
    }

    const uint8_t * pStart = reinterpret_cast<const uint8_t *>(i_pFruCallouts);

    // loop through entries
    while (bytesAvailable > bytesUsed)
    {
        fruCallOutEntry_t calloutEntry;
        const pelFRUCalloutHeader_t * pFrucoheader = reinterpret_cast<const pelFRUCalloutHeader_t *>(pStart + bytesUsed);
        calloutEntry.priority = fruPriToHwasPri(pFrucoheader->fcpri);
        calloutEntry.locCodeLen = pFrucoheader->fclclen;
        bytesUsed += sizeof(pelFRUCalloutHeader_t);
        if (calloutEntry.locCodeLen)
        {
            if (calloutEntry.locCodeLen <= PEL_LOC_CODE_SIZE)
            {
                memcpy(calloutEntry.locationCode, pStart + bytesUsed, calloutEntry.locCodeLen);
            }
            else
            {
                TRACFCOMP(g_trac_errl,
                          "ErrlSrc:unflattenFruCallouts(): location code length %d over max %d",
                          calloutEntry.locCodeLen, PEL_LOC_CODE_SIZE);
                break;
            }
        }
        bytesUsed += calloutEntry.locCodeLen;

        const pelFRUIDSubstruct_t * pFruIdSubStruct = reinterpret_cast<const pelFRUIDSubstruct_t *>(pStart + bytesUsed);
        calloutEntry.fruCompType = pFruIdSubStruct->frusshead.fssflags;
        if ( (calloutEntry.fruCompType & FAILING_COMP_TYPE_FRU_PN) ||
             (calloutEntry.fruCompType & FAILING_COMP_TYPE_FRU_PRC) )
        {
            strncpy(calloutEntry.partNumber,
                    pFruIdSubStruct->fruidpnString,
                    sizeof(calloutEntry.partNumber));
        }
        if (calloutEntry.fruCompType & FAILING_COMP_TYPE_FRU_CCIN)
        {
            strncpy(calloutEntry.ccin,
                    pFruIdSubStruct->fruidccinString,
                    sizeof(calloutEntry.ccin));
        }
        if (calloutEntry.fruCompType & FAILING_COMP_TYPE_FRU_SN)
        {
            strncpy(calloutEntry.serialNumber,
                    pFruIdSubStruct->fruidsnString,
                    sizeof(calloutEntry.serialNumber));
        }
        bytesUsed += pFruIdSubStruct->frusshead.fsslen;

        addFruCallout(calloutEntry);
    }
}

void ErrlSrc::flattenFruCallouts(pelSRCSection_t* i_psrc)
{
    // PEL spec 4.2.2.1 - Subsection ID = 0xC0, FRU callout subsection
    const uint8_t FRU_SUBSECTION_ID = 0xC0;
    // PEL spec 4.2.2.1 - Subsection flags = 0x00, No subsections after this one
    const uint8_t FRU_SUBSECTION_FLAGS = 0x00;
    // PEL spec 4.2.2.2 - Callout type in flag data is always = 2
    const uint8_t FRU_CALLOUT_TYPE_FLAG = 0x20;
    // PEL spec 4.2.2.2 - Mask for FRUID substructure included
    const uint8_t FRU_CALLOUT_FRUID_FLAG = 0x8;
    // PEL spec 4.2.2.2.2 - Substructure type = 'ID' for FRUID
    const uint16_t FRU_SUBSTRUCT_TYPE_FRUID = 0x4944;

    // Flatten FRU callouts
    uint8_t* l_tmpsrcptr = nullptr;
    if (!iv_coVec.empty())
    {
        // Limit the number of FRU callouts to the max size allowed
        maxFruCallouts();

        // Pointer to the current src next data entry location
        l_tmpsrcptr =
            reinterpret_cast<uint8_t*>(i_psrc->src.srcString + SRC_STRING_SIZE);

        // Fru Callout subsection header
        pelSubSectionHeader_t l_ssheader;
        l_ssheader.ssid = FRU_SUBSECTION_ID;
        l_ssheader.ssflags = FRU_SUBSECTION_FLAGS;
        l_ssheader.sslen = fruCalloutFlatSize() / 4;  // # of words not bytes

        // Copy the subsection header to the src next data entry location
        memcpy(l_tmpsrcptr,
               &l_ssheader,
               sizeof(pelSubSectionHeader_t));
        l_tmpsrcptr += sizeof(pelSubSectionHeader_t);
    }
    // Loop thru all the saved fru callouts
    for (const auto& entry : iv_coVec)
    {
        // Pre calculate sizes

        // FRU ID substructure length is variable depending on callout type.
        // Part Number, Serial Number, and CCIN are optional fields.
        size_t l_frusslen = fruIdSubstructSize(entry);

        // Total FRU callout length
        size_t l_frucolen = sizeof(pelFRUCalloutHeader_t)
                          + entry.locCodeLen
                          + l_frusslen;

        // Create a temp fru callout blob
        uint8_t l_tmpfruco[l_frucolen] = {};

        // Pointer to the current fru data entry location
        uint8_t* l_tmpfruptr = l_tmpfruco;

        // Fru Callout header
        // Always included the FRU ID.
        pelFRUCalloutHeader_t l_frucoheader;
        l_frucoheader.fclen = l_frucolen;
        l_frucoheader.fcflags = FRU_CALLOUT_TYPE_FLAG;
        l_frucoheader.fcflags |= FRU_CALLOUT_FRUID_FLAG;
        l_frucoheader.fcpri = hwasPriToFruPri(entry.priority);
        l_frucoheader.fclclen = entry.locCodeLen;

        // Copy the data and shift the fru data ptr
        memcpy(l_tmpfruptr,
               &l_frucoheader,
               sizeof(pelFRUCalloutHeader_t));
        l_tmpfruptr += sizeof(pelFRUCalloutHeader_t);

        // Fru Callout location code
        // Copy the data and shift the fru data ptr
        memcpy(l_tmpfruptr,
               &entry.locationCode,
               entry.locCodeLen);
        l_tmpfruptr += entry.locCodeLen;

        // FRU ID substructure
        pelFRUIDSubstruct_t l_fruss;
        l_fruss.frusshead.fsstype = FRU_SUBSTRUCT_TYPE_FRUID; // type 'ID'
        l_fruss.frusshead.fsslen = l_frusslen; // variable, several optional fields
        l_fruss.frusshead.fssflags = entry.fruCompType;

        // Flat PN/CCIN/SN are a fixed size, regardless of source string size
        // Source string is already truncated and null terminated if required
        if ((entry.fruCompType & FAILING_COMP_TYPE_FRU_PN) ||
            (entry.fruCompType & FAILING_COMP_TYPE_FRU_PRC))
        {
            strncpy(l_fruss.fruidpnString,
                    entry.partNumber,
                    sizeof(l_fruss.fruidpnString));
        }
        if (entry.fruCompType & FAILING_COMP_TYPE_FRU_CCIN)
        {
            strncpy(l_fruss.fruidccinString,
                    entry.ccin,
                    sizeof(l_fruss.fruidccinString));
        }
        if (entry.fruCompType & FAILING_COMP_TYPE_FRU_SN)
        {
            strncpy(l_fruss.fruidsnString,
                    entry.serialNumber,
                    sizeof(l_fruss.fruidsnString));
        }

        // Copy the data and shift the fru data ptr
        memcpy(l_tmpfruptr,
               &l_fruss,
               l_frusslen);
        l_tmpfruptr += l_frusslen;

        // Copy the flat fru callout into the o_buffer at the
        // src data entry location and shift the src data ptr
        memcpy(l_tmpsrcptr,
               l_tmpfruco,
               l_frucolen);
        l_tmpsrcptr += l_frucolen;
    }
}
#endif


}  // namespace



