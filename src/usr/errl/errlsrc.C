/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlsrc.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
        memset( psrc->srcString, ' ', sizeof( psrc->srcString ));

        l_rc = iv_header.flatten( o_pBuffer, i_cbBuffer );
        if( 0 == l_rc )
        {
            // Rare.
            TRACFCOMP( g_trac_errl, "ErrlSrc::flatten: header flatten error");
            break;
        }


        // Place data into the flat structure.
        psrc->ver         = ErrlSrc::SRCVER;    // 2;
#ifdef CONFIG_BUILD_FULL_PEL
        // FRU callouts included
        if (!iv_coVec.empty())
        {
            // Flags bit 7 = 1: Additional subsections present
            // beyond ASCII character string field (FRU callout subsection)
            psrc->flags |= 0x01;
        }
#endif
        psrc->wordcount   = ErrlSrc::WORDCOUNT; // 9;

        // Use reserved1 word to stash the reason code for easy extract in
        // unflatten rather than parsing srcString
        psrc->reserved1   = iv_reasonCode;

        CPPASSERT( ErrlSrc::SLEN == sizeof(pelSRCSection_t)-iv_header.flatSize());
        psrc->srcLength   = ErrlSrc::SLEN;
#ifdef CONFIG_BUILD_FULL_PEL
        // FRU callouts included
        if (!iv_coVec.empty())
        {
            // There are FRU callouts, add them to total src size
            psrc->srcLength += fruCalloutFlatSize();
        }
#endif

        // SRC format
        psrc->word2       =  0x000000E0; // SRCI_HBT_FORMAT

        // Stash the Hostboot module id into hex word 3
        psrc->moduleId    = iv_modId;

        // set deconfigure and/or gard bits
        if (iv_deconfig)
        {
            psrc->word5 |= ErrlSrc::DECONFIG_BIT; // deconfigure
        }
        if (iv_gard)
        {
            psrc->word5 |= ErrlSrc::GARD_BIT; // GARD
        }

        // set ACK bit - means unacknowledged
        psrc->word5 |= ErrlSrc::ACK_BIT; // ACK

        // Stash the Hostboot long long words into the hexwords of the SRC.
        psrc->word6       = iv_user1;    // spans 6-7
        psrc->word8       = iv_user2;    // spans 8-9

        // Build the char string for the SRC.
        uint32_t l_u32;
        l_u32 = (iv_srcType<< 24)|(iv_ssid<<16)| iv_reasonCode;

        char l_tmpString[ 20 ];
        uint64_t cb = sprintf( l_tmpString, "%08X", l_u32 );
        memcpy( psrc->srcString, l_tmpString, cb );

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

    iv_srcType      = (srcType_t)((16 * aschex2bin(p->srcString[0])) +
                        aschex2bin(p->srcString[1]));
    iv_modId        = p->moduleId;
    iv_reasonCode   = p->reserved1;
    iv_ssid         = (epubSubSystem_t)((16 * aschex2bin(p->srcString[2])) +
                       aschex2bin(p->srcString[3]));
    iv_user1        = p->word6;
    iv_user2        = p->word8;

    if(p->word5 & ErrlSrc::DECONFIG_BIT) // deconfigure
    {
        iv_deconfig = true;
    }
    if(p->word5 & ErrlSrc::GARD_BIT) // GARD
    {
        iv_gard = true;
    }

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
    const uint32_t MAX_MRU_ID_FIELDS = 15;

    // Compare new callout partNumber/locationCode to all in the vector
    for( auto it = iv_coVec.begin();
         it != iv_coVec.end();
         it++ )
    {
        if (!strcmp(io_co.partNumber, (*it).partNumber) &&
            !strcmp(io_co.locationCode, (*it).locationCode))
        {
            // Found a match, check the priority
            if (io_co.priority > (*it).priority)
            {
                // New priority is higher, keep it but save all the
                // old mru priority and id data to the new entry
                io_co.mruPriVec.insert(io_co.mruPriVec.end(),
                                      (*it).mruPriVec.begin(),
                                      (*it).mruPriVec.end());
                io_co.mruIdVec.insert(io_co.mruIdVec.end(),
                                     (*it).mruIdVec.begin(),
                                     (*it).mruIdVec.end());

                // Limited number of MRU ID fields allowed
                if (io_co.mruIdVec.size() > MAX_MRU_ID_FIELDS)
                {
                    io_co.mruIdVec.resize(MAX_MRU_ID_FIELDS);
                }

                // Erase the old callout entry
                it = iv_coVec.erase(it);
                break;
            }

            // New priority is <= old, keep the original but add the
            // new mru priority and id data to the old entry
            (*it).mruPriVec.insert((*it).mruPriVec.end(),
                                   io_co.mruPriVec.begin(),
                                   io_co.mruPriVec.end());
            (*it).mruIdVec.insert((*it).mruIdVec.end(),
                                  io_co.mruIdVec.begin(),
                                  io_co.mruIdVec.end());

            // Limited number of MRU ID fields allowed
            if ((*it).mruIdVec.size() > MAX_MRU_ID_FIELDS)
            {
                (*it).mruIdVec.resize(MAX_MRU_ID_FIELDS);
            }

            // New entry is a duplicate, don't add the new callout to the vector
            retDup = true;
            break;
        }
    }
    return retDup;
}

void ErrlSrc::addFruCallout(fruCallOutEntry_t& io_co)
{
    const uint32_t MAX_FRU_CALLOUTS = 10;

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

        // Limited number of FRU callouts allowed
        if (iv_coVec.size() > MAX_FRU_CALLOUTS)
        {
            iv_coVec.resize(MAX_FRU_CALLOUTS);
        }

    } while(0);
}

char ErrlSrc::hwasPriToFruPri( uint32_t i_hwasPri )
{
    // Default to LOW, undefined = LOW
    char retchar = 'L';

    switch( i_hwasPri )
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
        default:
            break;
   }
   return retchar;
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
    // PEL spec 4.2.2.2 - Mask for MRUID substructure included
    const uint8_t FRU_CALLOUT_MRUID_FLAG = 0x4;
    // PEL spec 4.2.2.2.2 - Substructure type = 'ID' for FRUID
    const uint16_t FRU_SUBSTRUCT_TYPE_FRUID = 0x4944;
    // PEL spec 4.2.2.2.2 - Substructure type = 'MR' for MRUID
    const uint16_t FRU_SUBSTRUCT_TYPE_MRUID = 0x4D52;
    // PEL spec 4.2.2.2.3 - FRUID substructure flags mask
    //    PN = bit4, CCIN = bit5, SN = bit7
    const uint8_t FRU_SUBSTRUCT_FLAGS = 0x0D;

    // Flatten FRU callouts
    uint8_t* l_tmpsrcptr = nullptr;
    if (!iv_coVec.empty())
    {
        // Pointer to the current src next data entry location
        l_tmpsrcptr =
            reinterpret_cast<uint8_t*>(i_psrc->srcString + SRC_STRING_SIZE);

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
        // MRU ID substructure length
        size_t l_mrusslen = sizeof(pelMRUIDSubstruct_t)
                          + (sizeof(mruidfield)
                          * entry.mruIdVec.size());
        // FRU ID substructure length
        size_t l_frusslen = sizeof(pelFRUIDSubstruct_t);
        // Total FRU callout length
        size_t l_frucolen = sizeof(pelFRUCalloutHeader_t)
                          + entry.locCodeLen
                          + l_frusslen
                          + l_mrusslen;

        // Creaate a temp fru callout blob
        uint8_t l_tmpfruco[l_frucolen] = {};

        // Pointer to the current fru data entry location
        uint8_t* l_tmpfruptr = l_tmpfruco;

        // Fru Callout header
        // Always included the FRU ID and MRU ID  sections
        pelFRUCalloutHeader_t l_frucoheader;
        l_frucoheader.fclen = l_frucolen;
        l_frucoheader.fcflags = FRU_CALLOUT_TYPE_FLAG;
        l_frucoheader.fcflags |= FRU_CALLOUT_FRUID_FLAG;
        l_frucoheader.fcflags |= FRU_CALLOUT_MRUID_FLAG;
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
        l_fruss.frusshead.fsslen = l_frusslen; // 28
        l_fruss.frusshead.fssflags = entry.fruCompType << 4; // bits 0-3
        l_fruss.frusshead.fssflags |= FRU_SUBSTRUCT_FLAGS; // bits 4-7
        // Flat PN/CCIN/SN are a fixed size, regardless of source string size
        // Source string is already truncated and null terminated if required
        strncpy(l_fruss.fruidpnString,
                entry.partNumber,
                sizeof(l_fruss.fruidpnString));
        strncpy(l_fruss.fruidccinString,
                entry.ccin,
                sizeof(l_fruss.fruidccinString));
        strncpy(l_fruss.fruidsnString,
                entry.serialNumber,
                sizeof(l_fruss.fruidsnString));

        // Copy the data and shift the fru data ptr
        memcpy(l_tmpfruptr,
               &l_fruss,
               sizeof(pelFRUIDSubstruct_t));
        l_tmpfruptr += sizeof(pelFRUIDSubstruct_t);

        // MRU ID substructure header
        pelMRUIDSubstruct_t l_mruss;
        l_mruss.frusshead.fsstype = FRU_SUBSTRUCT_TYPE_MRUID; // 'MR'
        l_mruss.frusshead.fsslen = l_mrusslen;
        // Flag bits 0-3 reserved, bits 4-7 number of mru id entries
        l_mruss.frusshead.fssflags = entry.mruIdVec.size();
        l_mruss.mrussreserved = 0x0;

        // Copy the data and shift the fru data ptr
        memcpy(l_tmpfruptr,
               &l_mruss,
               sizeof(pelMRUIDSubstruct_t));
        l_tmpfruptr += sizeof(pelMRUIDSubstruct_t);

        // Loop thru all the mru id field entries
        for (uint32_t mruidx = 0;
             mruidx < entry.mruIdVec.size();
             mruidx++)
        {
            pelMRUIDField_t l_mrufield;
            l_mrufield.mrufieldreserved = 0x0;
            l_mrufield.mrureppri =
                hwasPriToFruPri(entry.mruPriVec[mruidx]);
            l_mrufield.mruid = entry.mruIdVec[mruidx];

            // Copy the data and shift the fru data ptr
            memcpy(l_tmpfruptr,
                   &l_mrufield,
                   sizeof(pelMRUIDField_t));
            l_tmpfruptr += sizeof(pelMRUIDField_t);
        }

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



