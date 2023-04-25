/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ocmb_spd.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
#include <vpd/spdenums.H>
#include <devicefw/driverif.H>
#include <eeprom/eeprom_const.H>
#include <errl/errlentry.H>
#include <vpd/vpdreasoncodes.H>
#include <endian.h>
#include <errl/errlmanager.H>
#include <util/misc.H>
#include <util/utillidpnor.H>
#include <targeting/common/utilFilter.H>

#include "ocmb_spd.H"
#include "spd.H"
#include "errlud_vpd.H"
#include <vpd/vpd_if.H>
#include <vpd/pvpdenums.H>

extern trace_desc_t * g_trac_spd;

//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

const uint32_t     SPDTOC_EYECATCH = 0x53504400;  //'SPD\0'

// See ocmbIdecPhase1 for related manipulation of these bytes
// In the SPD overlay logic we will check to see if these bytes are requested
// and if so make sure we use the ORIGINAL Backplane VPD bytes which will
// actually represent the physical part DD level on the planar board
constexpr uint8_t  RAW_CARD_BYTE_OFFSET = 195; // #D raw card offset field
constexpr uint8_t  DMB_REV_OFFSET       = 200; // #D DMB REV offset, the OCMB manufacturers
                                               // version of the chip, this is later translated
                                               // to an IBM format

enum TOC_VERSION
{
    TOC_VERSION_1      = 0x01,
    TOC_VERSION_LATEST = TOC_VERSION_1,
};

struct spdEntry_t
{
    uint32_t ec;
    uint32_t offset;
    uint32_t size;
} PACKED spdEntry;

struct SectionMapTOC_t
{
    uint32_t eyeCatch;
    uint32_t TOC_version;
    uint32_t TOC_count;
    spdEntry_t PSPD_images[];
} PACKED;

// Namespace alias for targeting
namespace T = TARGETING;

namespace SPD
{

/**
 * @brief Handle SPD READ deviceOp to OCMB_CHIP targets
 *
 * @param[in]     i_opType    Operation type, see driverif.H
 * @param[in]     i_target    OCMB target
 * @param[in/out] io_buffer   Read:   Pointer to output data storage
 *                            Write:  Pointer to input data storage
 * @param[in/out] io_buflen   Input:  Read:  size of data to read (in bytes)
 *                            Output: Read:  Size of output data
 * @param[in]   i_accessType  Access type
 * @param[in]   i_args        This is an argument list for DD framework.
 *                            In this function, there is one argument,
 *                            the l_keyword, so far we only support ENTIRE_SPD
 * @return  errlHndl_t
 */
errlHndl_t ocmbSPDPerformOp(DeviceFW::OperationType i_opType,
                            T::TargetHandle_t       i_target,
                            void*                   io_buffer,
                            size_t&                 io_buflen,
                            int64_t                 i_accessType,
                            va_list                 i_args);


// Register the perform Op with the routing code for OCMBs.
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::SPD,
                      T::TYPE_OCMB_CHIP,
                      ocmbSPDPerformOp);

errlHndl_t planarOcmbRetrieveSPD(T::TargetHandle_t        i_target,
                           uint64_t                 i_byteAddr,
                           size_t                   i_numBytes,
                           void*                    o_data)
{
    errlHndl_t l_errl = nullptr;
    static bool found_image = false;
    static std::vector<uint8_t> spd_cache; // local cache to store PNOR::PSPD if match found

    TRACSSCOMP(g_trac_spd, ENTER_MRK"planarOcmbRetrieveSPD "
               "i_byteAddr = 0x%X i_numBytes = %d HUID=0x%X",
               i_byteAddr, i_numBytes, get_huid(i_target));
    do {

    // parent node
    //   look for any parent regardless of state since there could be
    //   a path that runs through here before all of the presence
    //   detection is complete
    TARGETING::TargetHandleList targetListNode;
    TARGETING::getParentAffinityTargets(targetListNode,i_target,
                                        TARGETING::CLASS_ENC,
                                        TARGETING::TYPE_NODE,
                                        false /*ignore state*/);
    TARGETING::Target* l_pNodeTarget = targetListNode[0];

    // read PSPD:#D (contains the planar SPD)
    size_t l_size = 0;
    l_errl = DeviceFW::deviceOp(DeviceFW::READ,
                                l_pNodeTarget,
                                nullptr,//returns size only
                                l_size,
                                DEVICE_VPD_ADDRESS(PVPD::PSPD,
                                                   PVPD::pdD));
    if (l_errl)
    {
        TRACFCOMP(g_trac_spd, ERR_MRK"planarOcmbRetrieveSPD(): error getting size of PSPD:#D");
        break;
    }

    uint8_t l_nodeData[l_size] = {};
    l_errl = DeviceFW::deviceOp(DeviceFW::READ,
                                l_pNodeTarget,
                                l_nodeData,
                                l_size,
                                DEVICE_VPD_ADDRESS(PVPD::PSPD,
                                                   PVPD::pdD));
    if (l_errl)
    {
        TRACFCOMP(g_trac_spd, ERR_MRK"planarOcmbRetrieveSPD(): error reading PSPD:#D");
        break;
    }


    static bool unloadPSPD = false;
// Exclude FSP since there is NO PNOR access for FSP Runtime
#ifndef CONFIG_FSP_BUILD
    uint8_t *pdD_raw_card = l_nodeData+RAW_CARD_BYTE_OFFSET;
    uint8_t *pnor_raw_card = 0; // RAW_CARD_BYTE_OFFSET
    static bool first_time = true;
    SectionMapTOC_t* l_TOCPtr = nullptr;
    if (first_time) // We get first time to check if PNOR::PSPD matches, if so, we make a local cache to use
    {
        first_time = false; // We set this early, we possibly can fail to set found_image due to condition checks,
                            // but that's OK since we cannot use PNOR for some odd reason, etc.
#ifndef  __HOSTBOOT_RUNTIME
        // We first attempt to getSectionInfo, so in case that fails
        // we can log some info, but continue since the lack of the PSPD partition
        // is not a fatal condition.
        //
        // We do the getSectionInfo first as the least invasive method to check
        // for the existance of the PSPD partition.  If for example we try to
        // loadSecureSection, that may possibly cause a fatal shutdown flow to
        // be triggered in the secure paths is PSPD partition is not available.
        PNOR::SectionInfo_t l_sectionInfo_PSPD = {};
        errlHndl_t l_errl_PSPD = nullptr;
        l_errl_PSPD = PNOR::getSectionInfo(PNOR::PSPD, l_sectionInfo_PSPD);
        if (l_errl_PSPD)
        {
            l_errl_PSPD->collectTrace(VPD_COMP_NAME, 256);
            l_errl_PSPD->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errl_PSPD, VPD_COMP_ID);
            l_TOCPtr = 0; // if getSectionInfo setHeader fails clear the vaddr since it comes back valid
        }
        else
        {
#ifdef CONFIG_SECUREBOOT // NOT RUNTIME and SECUREBOOT
            l_errl_PSPD = PNOR::loadSecureSection(PNOR::PSPD);
            if (l_errl_PSPD)
            {
                // Log some info but continue since the lack of the PSPD partition is
                // not a fatal condition, so basically ignore and keep on going
                unloadPSPD = false;
                l_errl_PSPD->collectTrace(VPD_COMP_NAME, 256);
                l_errl_PSPD->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit(l_errl_PSPD, VPD_COMP_ID);
                l_TOCPtr = 0; // flag so we will be sure to skip the handling
            }
            else
            {
                TRACFCOMP(g_trac_spd, "planarOcmbRetrieveSPD loadSecureSection PNOR::PSPD");
                unloadPSPD = true;
                l_TOCPtr = reinterpret_cast<SectionMapTOC_t*>(l_sectionInfo_PSPD.vaddr);
            }
#endif // CONFIG_SECUREBOOT
        }
#else  // RUNTIME
       Util::LidAndContainerLid l_lids;
       errlHndl_t l_errl_RT_PSPD = nullptr;
       l_errl_RT_PSPD = Util::getPnorSecLidIds(PNOR::PSPD, l_lids);
       if (l_errl_RT_PSPD)
       {
           // Log some info but keep the processing flowing as an optional path
           l_errl_RT_PSPD->collectTrace(VPD_COMP_NAME, 256);
           l_errl_RT_PSPD->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
           errlCommit(l_errl_RT_PSPD, VPD_COMP_ID);
           l_TOCPtr = 0;  // flag so we will be sure to skip the handling
       }
       else
       {
           uint32_t l_lidNumber = l_lids.lid;
           size_t l_lidImageSize = 0;
           void * l_PSPD_Image =nullptr;
           UtilLidMgr l_pspdLidMgr(l_lidNumber);
           l_errl_RT_PSPD = l_pspdLidMgr.getLidSize(l_lidImageSize);
           if (l_errl_RT_PSPD)
           {
               // Log some info but keep the processing flowing as an optional path
               l_errl_RT_PSPD->collectTrace(VPD_COMP_NAME, 256);
               l_errl_RT_PSPD->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
               errlCommit(l_errl_RT_PSPD, VPD_COMP_ID);
               l_TOCPtr = 0;  // flag so we will be sure to skip the handling
           }
           else
           {
               l_errl_RT_PSPD = l_pspdLidMgr.getStoredLidImage(l_PSPD_Image, l_lidImageSize);
               if (l_errl_RT_PSPD)
               {
                   // Log some info but keep the processing flowing as an optional path
                   l_errl_RT_PSPD->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                   l_errl_RT_PSPD->collectTrace(VPD_COMP_NAME, 256);
                   errlCommit(l_errl_RT_PSPD, VPD_COMP_ID);
                   l_TOCPtr = 0;  // flag so we will be sure to skip the handling
               }
               else
               {
                   l_TOCPtr = reinterpret_cast<SectionMapTOC_t*>(l_PSPD_Image);
               }
           }
       }
#endif // __HOSTBOOT_RUNTIME

        // We could get a blank, 0xFF filled PNOR, so validate parameters
        if (l_TOCPtr)
        {
            // We will -NOT- get error from getSectionInfo if PNOR::PSPD exists but has no default images built,
            // meaning lots of 0xFF's
            if ((l_TOCPtr->TOC_count >= 1) &&
                (l_TOCPtr->TOC_version == TOC_VERSION_LATEST) &&
                (l_TOCPtr->eyeCatch == SPDTOC_EYECATCH))
            {
                for (uint32_t i=0; i<(l_TOCPtr->TOC_count); i++)
                {
                    //ranged checked that its within the range we want
                    if ((l_TOCPtr->PSPD_images[i].size >= (i_byteAddr+i_numBytes)) &&
                       (l_TOCPtr->PSPD_images[i].size >= RAW_CARD_BYTE_OFFSET)) // Future proof changes to RAW_CARD_TYPE
                    {
                        // Now that we have a candidate image, store its raw card value
                        pnor_raw_card = reinterpret_cast<uint8_t *>( reinterpret_cast<uint8_t *>(l_TOCPtr) + (l_TOCPtr->PSPD_images[i].offset + RAW_CARD_BYTE_OFFSET));
                        // ONLY if we MATCH the original Planar VPD #D SPD raw card byte do we use the new, refreshed PNOR::PSPD image
                        if (*pnor_raw_card == *pdD_raw_card)
                        {
                            found_image = true;
                            spd_cache.resize(l_TOCPtr->PSPD_images[i].size);
                            TRACFCOMP(g_trac_spd, "planarOcmbRetrieveSPD *pdD_raw_card=0x%X RAW_CARD_BYTE_OFFSET=0x%X (%d) i=0x%X spd_cache.size=0x%X (%d)",
                                                  *pdD_raw_card, RAW_CARD_BYTE_OFFSET, RAW_CARD_BYTE_OFFSET, i, spd_cache.size(), spd_cache.size());
                            memcpy(spd_cache.data(), reinterpret_cast<uint8_t *>( reinterpret_cast<uint8_t *>(l_TOCPtr) + l_TOCPtr->PSPD_images[i].offset),spd_cache.size());
                            break;
                        }
                    }
                }
            }
        } // l_TOCPtr
    } // first_time
#endif // NOT FSP

    if (found_image)
    {
        memcpy(o_data,
           (spd_cache.data() + i_byteAddr),
           i_numBytes);
        static const uint16_t blocked_bytes[] = {RAW_CARD_BYTE_OFFSET, DMB_REV_OFFSET};
        for (const auto offset : blocked_bytes)
        {
            // Range check if the Backplane VPD DD level (or any future blocked bytes)
            // are needing to be restored (restoration is based on memory hardware
            // requirements)
            if ((offset >= i_byteAddr) && (offset < i_byteAddr+i_numBytes))
            {
                memcpy( reinterpret_cast<uint8_t *>(o_data)+(offset-i_byteAddr), l_nodeData+offset, 1 );
            }
        }
    }
    else
    {
        memcpy( o_data, l_nodeData+i_byteAddr, i_numBytes );
    }

    if (unloadPSPD)
    {
        unloadPSPD = false;
#ifdef CONFIG_SECUREBOOT
#ifndef  __HOSTBOOT_RUNTIME
        errlHndl_t l_errl_unloadPSPD = nullptr;
        l_errl_unloadPSPD = PNOR::unloadSecureSection(PNOR::PSPD);
        TRACFCOMP(g_trac_spd, "planarOcmbRetrieveSPD unloadSecureSection PNOR::PSPD");
        if (l_errl_unloadPSPD)
        {
            delete l_errl_unloadPSPD;
            l_errl_unloadPSPD = nullptr;
        }
#endif  // NOT RUNTIME
#endif // NOT SECUREBOOT
    }

    } while(0);
    return l_errl;
}


errlHndl_t ocmbGetSPD(T::TargetHandle_t        i_target,
                            void*              io_buffer,
                            size_t&            io_buflen,
                      const VPD::vpdKeyword    i_keyword,
                      const uint8_t            i_memType,
                      EEPROM::EEPROM_SOURCE    i_location)
{
    errlHndl_t l_errl = nullptr;

    assert(i_target != nullptr, "i_target is nullptr in ocmbGetSPD");

    do {

        const SPD::KeywordData* entry = nullptr;
        l_errl = getKeywordEntry(i_keyword,
                                 i_memType,
                                 i_target,
                                 entry);
        if (l_errl != nullptr)
        {
            break;
        }

        // Check to be sure entry is not nullptr.
        if (entry == nullptr)
        {
            TRACFCOMP(g_trac_spd, ERR_MRK"SPD::KeywordData entry pointer is nullptr!");

            /*@
            * @errortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         VPD::VPD_OCMB_GET_SPD
            * @reasoncode       VPD::VPD_NULL_ENTRY
            * @userdata1[00:31] Buffer Size
            * @userdata1[32:63] Memory Type
            * @userdata2[00:31] SPD Keyword
            * @userdata2[32:63] Target HUID
            * @devdesc          SPD is not valid for this part
            * @custdesc         A problem occurred during the IPL
            *                   of the system.
            */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          VPD::VPD_OCMB_GET_SPD,
                                          VPD::VPD_NULL_ENTRY,
                                          TWO_UINT32_TO_UINT64(io_buflen,
                                            i_memType),
                                          TWO_UINT32_TO_UINT64(i_keyword,
                                              T::get_huid(i_target)),
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            l_errl->collectTrace( "SPD", 256);

            break;
        }

        // Only allow keywords supported by DDIMM
        l_errl = SPD::checkModSpecificKeyword(*entry,
                                              i_memType,
                                              i_target);

        if (l_errl != nullptr)
        {
            break;
        }

        if (entry->isSpecialCase)
        {
            l_errl = SPD::spdSpecialCases(*entry,
                                          io_buffer,
                                          i_target,
                                          i_memType);
            if (l_errl != nullptr)
            {
                break;
            }
        }

        // Support passing in nullptr buffer to return VPD field size.
        if (io_buffer == nullptr)
        {
            io_buflen = entry->length;
            break;
        }


        l_errl = SPD::spdCheckSize(io_buflen,
                                   entry->length,
                                   i_keyword);

        if (l_errl != nullptr)
        {
            break;
        }

        l_errl = ocmbFetchData(i_target,
                               entry->offset,
                               entry->length,
                               io_buffer,
                               i_location);

        if (l_errl != nullptr)
        {
            break;
        }

        // Return the size read.
        io_buflen = entry->length;

    } while(0);

    return l_errl;
}

// ------------------------------------------------------------------
// ocmbFetchData
// ------------------------------------------------------------------
errlHndl_t ocmbFetchData(T::TargetHandle_t    i_target,
                        uint64_t              i_byteAddr,
                        size_t                i_numBytes,
                        void*                 o_data,
                        EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err = nullptr;

    TRACSSCOMP(g_trac_spd, ENTER_MRK"ocmbFetchData() target=%.8X,"
               "i_byteAddr = 0x%X i_numBytes = %d i_eepromSource = 0x%X",
               T::get_huid(i_target),
               i_byteAddr, i_numBytes, i_eepromSource);

    do
    {
        // Pull from the EEPROM if it exists
        T::ATTR_EEPROM_VPD_PRIMARY_INFO_type l_eepromVpd;
        if( i_target->tryGetAttr<T::ATTR_EEPROM_VPD_PRIMARY_INFO>(l_eepromVpd) )
        {
            // Get the data
            err = DeviceFW::deviceOp(DeviceFW::READ,
                                     i_target,
                                     o_data,
                                     i_numBytes,
                                     DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                                           i_byteAddr,
                                                           i_eepromSource));
            if( err )
            {
                TRACFCOMP(g_trac_spd, ERR_MRK"ocmbFetchData(): error reading EEPROM");
                break;
            }
        }
        // Otherwise pull the data from the node VPD
        else
        {
            err = planarOcmbRetrieveSPD(i_target, i_byteAddr, i_numBytes, o_data);
            if ( err )
            {
                TRACFCOMP(g_trac_spd, ERR_MRK"ocmbFetchData(): failing out of planarOcmbRetrieveSPD");
                break;
            }
        }
    } while(0);

    TRACSSCOMP(g_trac_spd,
               EXIT_MRK"ocmbFetchData(): returning %s errors",
               ((err != nullptr) ? "with" : "with no") );

    return err;
}

// ------------------------------------------------------------------
// isValidOcmbDimmType
// ------------------------------------------------------------------
bool isValidOcmbDimmType(const uint8_t i_dimmType)
{
    return ((SPD::DDR4_TYPE == i_dimmType)
            ||(SPD::DDR5_TYPE == i_dimmType));
}

// See above for details
errlHndl_t ocmbSPDPerformOp(DeviceFW::OperationType i_opType,
                            T::TargetHandle_t i_target,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args)
{
    errlHndl_t errl = nullptr;
    const uint64_t keyword = va_arg(i_args, uint64_t);

    TRACSSCOMP(g_trac_spd, ENTER_MRK" ocmbSPDPerformOP() target: %.8X,, io_buflen: %d, keyword: 0x%04X",
               T::get_huid(i_target), io_buflen, keyword );

    do
    {
        // Read the Basic Memory Type
        spdMemType_t memType(SPD::MEM_TYPE_INVALID);
        errl = OCMB_SPD::getMemType(memType, i_target, EEPROM::AUTOSELECT);

        if( errl )
        {
            break;
        }

        TRACSSCOMP(g_trac_spd, INFO_MRK"Mem Type: 0x%04X", memType);

        // Check the Basic Memory Type
        if (isValidOcmbDimmType(memType))
        {
            // If the user wanted the Basic memory type, return this now.
            if(BASIC_MEMORY_TYPE == keyword)
            {
                io_buflen = SPD::MEM_TYPE_SZ;
                if (io_buffer != nullptr)
                {
                    memcpy(io_buffer, &memType, io_buflen);
                }
                break;
            }

            // Read the keyword value
            errl = ocmbGetSPD(i_target,
                              io_buffer,
                              io_buflen,
                              keyword,
                              memType,
                              EEPROM::AUTOSELECT);

            if( errl )
            {
                break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_spd, ERR_MRK"Invalid Basic Memory Type (0x%04X), target huid = 0x%08X",
                      memType, T::get_huid(i_target));

            /*@
            * @errlortype
            * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid         VPD::VPD_OCMB_SPD_PERFORM_OP
            * @reasoncode       VPD::VPD_INVALID_BASIC_MEMORY_TYPE
            * @userdata1[00:31] Basic Memory Type (Byte 2)
            * @userdata1[32:63] Target HUID
            * @userdata2        Keyword Requested
            * @devdesc          Invalid Basic Memory Type
            */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           VPD::VPD_OCMB_SPD_PERFORM_OP,
                                           VPD::VPD_INVALID_BASIC_MEMORY_TYPE,
                                           TWO_UINT32_TO_UINT64(memType,
                                               T::get_huid(i_target)),
                                           keyword);

            // User could have installed a bad/unsupported dimm
            errl->addHwCallout(i_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DECONFIG,
                               HWAS::GARD_NULL);

            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_LOW);

            errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                      HWAS::SRCI_PRIORITY_LOW);

            errl->collectTrace("SPD", 256);

            break;
        }
    } while(0);

    // If there is an error, add parameter info to log
    if ( errl != nullptr )
    {
        VPD::UdVpdParms(i_target,
                        io_buflen,
                        0,
                        keyword,
                        EEPROM::AUTOSELECT,
                        true) // read
            .addToLog(errl);
    }

    TRACSSCOMP(g_trac_spd, EXIT_MRK" ocmbSPDPerformOP(): returning %s errors",
               (errl ? "with" : "with no") );

    return errl;

}

/**
 * @brief Generates a 16 bit CRC in CCITT XModem mode
 * @param[in] i_ptr - pointer to the data to compute CRC of
 * @param[in] i_count - number of bytes in i_data for the CRC calculation
 * @return Computed CRC value
 *
 * Reference code taken from JEDEC Standard No. 21-C
 *  Page 4.1.2.12.3 ?? 44
 */
uint16_t jedec_Crc16( const uint8_t *i_ptr, size_t i_count )
{
    TRACDCOMP( g_trac_spd, "jedec_Crc16(%p,%d)", i_ptr, i_count );
    uint16_t crc = 0;
    for( size_t c=0; c<i_count; c++ )
    {
        crc = crc ^ (static_cast<uint16_t>(*(i_ptr++)) << 8);
        for (size_t i = 0; i < 8; ++i)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ 0x1021;
            }
            else
            {
                crc = crc << 1;
            }
        }
    }
    return crc;
}


/**
 * @brief Evaluate and/or correct all CRC entries for this DDIMM
 */
errlHndl_t checkCRC( T::TargetHandle_t i_target,
                     enum CRCMODE_t i_mode,
                     EEPROM::EEPROM_ROLE i_role,
                     EEPROM::EEPROM_SOURCE i_location,
                     std::vector<crc_section_t>& o_crc_sections,
                     bool* const o_missing_vpd )
{
    errlHndl_t l_errl = nullptr;

    // Skip the CRC check if the data isn't coming from a regular EEPROM
    T::ATTR_EEPROM_VPD_PRIMARY_INFO_type l_eepromVpd;
    if( !i_target->tryGetAttr<T::ATTR_EEPROM_VPD_PRIMARY_INFO>(l_eepromVpd) )
    {
        TRACFCOMP( g_trac_spd, "Skipping CRC check on %.08X", T::get_huid(i_target) );
        return nullptr;
    }
    TRACDCOMP( g_trac_spd, "Start checkCRC on %08X", T::get_huid(i_target) );

    o_crc_sections.clear();

    // SPD data that has CRC (per DDIMM spec)
    crc_section_t l_sections[] = {
        {    0,  128 }, //0:125+126:127
        {  192,  256 }, //192:445+446:447
        { 1024,  128 }, //1024:1149+1150:1151
        { 1152,  128 }, //1152:1277+1278:1279
        { 1280,  128 }, //1280:1405+1406:1407
        { 3456,  128 }  //3456:3581+3582:3583
    };

    // Remember if we found a miscompare and if we repaired it
    bool l_foundMiscompare = false;
    bool l_repairedMiscompare = false;

    // Compute/correct CRC for every defined section
    for( auto l_section : l_sections )
    {
        uint8_t l_spddata[l_section.numbytes] = {};

        l_errl = DeviceFW::deviceOp(DeviceFW::READ,
                                    i_target,
                                    l_spddata,
                                    l_section.numbytes,
                                    DEVICE_EEPROM_ADDRESS(i_role,
                                                          l_section.start,
                                                          i_location) );
        if( l_errl )
        {
            TRACFCOMP( g_trac_spd,
                      "Error fetching SPD for CRC verification" );

            o_missing_vpd && (*o_missing_vpd = true);

            break;
        }

        // Pull the CRC from the last 2 bytes, it is stored little-endian
        TRACDCOMP( g_trac_spd, "crcSPD=%04X",
                   ((reinterpret_cast<uint16_t*>(l_spddata))
                   [(l_section.numbytes-2)/2]) );
        l_section.crcSPD = htole16((reinterpret_cast<uint16_t*>(l_spddata))
                                   [(l_section.numbytes-2)/2]);
        TRACDCOMP( g_trac_spd, "crcSPD=%04X (swap)", l_section.crcSPD );
        TRACDBIN( g_trac_spd, "SPD Data", l_spddata, l_section.numbytes );

        // Compute the CRC from the current data
        l_section.crcActual = jedec_Crc16( l_spddata, l_section.numbytes-2 );
        TRACDCOMP( g_trac_spd, "crcActual=%04X", l_section.crcActual );

        // Take some actions if there is a miscompare
        if( l_section.crcSPD != l_section.crcActual )
        {
            TRACFCOMP( g_trac_spd,
                   "%s CRC Miscompare found on 0x%08X for range %d, SPD=0x%04X, Computed=0x%04X (loc=%d)",
                   i_location == EEPROM::CACHE ? "CACHE" : "HW",
                   T::get_huid(i_target), l_section.start,
                   l_section.crcSPD, l_section.crcActual,
                   i_location );
            TRACFBIN( g_trac_spd, "SPD Data", l_spddata, l_section.numbytes );

// DDR5 SPD currently has a CRC issue that causes miscompares, which fails the boot
#ifndef CONFIG_ODYSSEY_BRINGUP
            l_foundMiscompare = true;
#endif

            // Write the new CRC out to the SPD if asked
            if( (FIX == i_mode) || (CHECK_AND_FIX == i_mode) )
            {
                TRACFCOMP( g_trac_spd, "Fixing CRC on %08X", T::get_huid(i_target) );
                l_repairedMiscompare = true;

                // byteswap the data before writing it back
                uint16_t l_swapped = htole16(l_section.crcActual);

                // Write out the updated value.
                size_t l_crcBytes = 2;
                l_errl = DeviceFW::deviceOp( DeviceFW::WRITE,
                                             i_target,
                                             &l_swapped,
                                             l_crcBytes,
                                             DEVICE_EEPROM_ADDRESS(
                                                  i_role,
                                                  l_section.start+l_section.numbytes-2,
                                                  i_location) );
                if( l_errl )
                {
                    // commit the attempt to fix and keep going
                    //  so that we find all errors
                    ERRORLOG::errlCommit(l_errl, VPD_COMP_ID );

                    // change the mode to CHECK to force a visible
                    //  error below since we couldn't actually fix
                    //  the problem
                    i_mode = CHECK;
                }
            }
        }

        // copy section into output crc sections list
        o_crc_sections.push_back(l_section);
    } // end l_sections for loop

    // Create some errors as requested if we find an error
    if( l_foundMiscompare )
    {
        TRACFCOMP( g_trac_spd, "Found at least 1 miscompare, create an error" );
        uint16_t l_failedRanges[6] = {};
        size_t l_next = 0;
        for( auto l_section : l_sections )
        {
            if( l_section.crcSPD != l_section.crcActual )
            {
                l_failedRanges[l_next++] = l_section.start;
            }
        }

        /*@
         * @errortype
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         VPD::VPD_OCMB_CHECK_CRC
         * @reasoncode       VPD::VPD_DDIMM_SPD_CRC_MISCOMPARE
         * @userdata1[00:31] Associated Target
         * @userdata1[32:47] First failing range
         * @userdata1[48:63] Second failing range
         * @userdata2[00:47] 3rd,4th,5th failing range
         * @userdata2[48:55] EEPROM_ROLE that failed: 0=VPD_PRIMARY, 1=VPD_BACKUP, 6=VPD_AUTO
         * @userdata2[56:63] EEPROM_SOURCE that failed: 1=CACHE, 2=HW
         * @devdesc          CRC Miscompare in the SPD
         * @custdesc         There is a problem with the vital product
         *                   data of a DIMM.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         VPD::VPD_OCMB_CHECK_CRC,
                                         VPD::VPD_DDIMM_SPD_CRC_MISCOMPARE,
                                TWO_UINT32_TO_UINT64(T::get_huid(i_target),
                                    l_failedRanges[0]
                                    | (l_failedRanges[1] >> 16)),
                                FOUR_UINT16_TO_UINT64(l_failedRanges[2],
                                    l_failedRanges[3],
                                    l_failedRanges[4],
                                    TWO_UINT8_TO_UINT16(i_role, i_location)) );

        // Default to deconfiguring the part immediately.
        // This should allow us to mark the target as present, but non-functional
        HWAS::DeconfigEnum l_deconfig = HWAS::DECONFIG;
        if( CHECK_AND_FIX == i_mode )
        {
            // Since we fixed the problem, do not deconfigure the part
            l_deconfig = HWAS::NO_DECONFIG;
        }

        l_errl->addHwCallout(i_target,
                             HWAS::SRCI_PRIORITY_HIGH,
                             l_deconfig,
                             HWAS::GARD_NULL);

        l_errl->collectTrace( "SPD", 1*KILOBYTE );

        // If we're explicitly trying to fix things, only make an info log
        if( FIX == i_mode )
        {
            l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            ERRORLOG::errlCommit(l_errl, VPD_COMP_ID );
        }
        // Commit the log inline and don't return the error if asked
        else if( CHECK_AND_FIX == i_mode )
        {
            ERRORLOG::errlCommit(l_errl, VPD_COMP_ID );
        }
        // else error is returned
    }

    // If we repaired something check to see if the repair worked
    if( l_repairedMiscompare )
    {
        TRACFCOMP( g_trac_spd, "Rechecking repaired SPD" );
        // Force a check of the raw hardware
        std::vector<crc_section_t> vSections;
        errlHndl_t l_checkErrl = checkCRC( i_target,
                                           CHECK,
                                           i_role,
                                           EEPROM::HARDWARE,
                                           vSections );
        if( l_checkErrl )
        {
            TRACFCOMP( g_trac_spd, "Recheck of repaired SPD still shows CRC errors" );
            if( !l_errl )
            {
                l_errl = l_checkErrl;
            }
            else
            {
                l_checkErrl->plid(l_errl->plid());
                ERRORLOG::errlCommit(l_checkErrl, VPD_COMP_ID );
            }
        }
        else
        {
            TRACFCOMP( g_trac_spd, "All errors repaired" );
        }
    }


    TRACDCOMP( g_trac_spd, "Finish checkCRC on %08X", T::get_huid(i_target) );
    return l_errl;
}

/**
 * @brief Forcibly write our cached SPD data out to the hardware
 */
errlHndl_t fixEEPROM( TARGETING::TargetHandle_t i_target )
{
    errlHndl_t l_errl = nullptr;
    size_t l_spdSize = 4*KILOBYTE;
    uint8_t l_spdData[l_spdSize] = {0};

    do {
        // Before doing anything, run a check against the EEPROM just
        //  to see if the data was bad
        std::vector<crc_section_t> l_sections;
        l_errl = SPD::checkCRC( i_target, SPD::CHECK, EEPROM::VPD_AUTO, EEPROM::HARDWARE, l_sections);
        if( l_errl )
        {
            TRACFCOMP( g_trac_spd, "fixEEPROM> Errors found in precheck" );
            //commit as informational
            l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            ERRORLOG::errlCommit(l_errl, VPD_COMP_ID );
        }

        // Read the data from the cache
        l_errl = DeviceFW::deviceOp(DeviceFW::READ,
                                    i_target,
                                    l_spdData,
                                    l_spdSize,
                                    DEVICE_EEPROM_ADDRESS(EEPROM::VPD_PRIMARY,
                                                          0,
                                                          EEPROM::CACHE) );
        if( l_errl )
        {
            TRACFCOMP( g_trac_spd, "Error reading SPD from cache on %08X", T::get_huid(i_target) );
            break;
        }

        // Before pushing our cache out to hardware, make sure it isn't also corrupted
        l_errl = SPD::checkCRC( i_target, SPD::CHECK, EEPROM::VPD_PRIMARY, EEPROM::CACHE, l_sections );
        if( l_errl )
        {
            TRACFCOMP( g_trac_spd, "fixEEPROM> Errors found in cache!" );
            l_errl->collectTrace( "SPD", 1*KILOBYTE );

            // Simics currently has bad CRC for the serial number portion
            if(Util::isSimicsRunning())
            {
                TRACFCOMP( g_trac_spd, "fixEEPROM> Ignoring error in Simics" );
                delete l_errl;
                l_errl = nullptr;
            }
            else
            {
                break;
            }
        }

        TRACFCOMP( g_trac_spd,
                   "fixEEPROM> Pushing cached SPD out to EEPROM on %08X",
                   T::get_huid(i_target) );
        l_errl = DeviceFW::deviceOp( DeviceFW::WRITE,
                                     i_target,
                                     l_spdData,
                                     l_spdSize,
                                     DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                     0,
                                     EEPROM::HARDWARE) );
        if( l_errl )
        {
            TRACFCOMP( g_trac_spd, "Error writing SPD on %08X", T::get_huid(i_target) );
            break;
        }

    } while(0);

    return l_errl;
}


/**
 * Needed to prevent infinite recursion since ddimmParkEeprom calls
 * into the EEPROM layer which then calls into ddimmParkEeprom
 */
thread_local bool tl_parkRecursion = false;

/**
 * @brief As a workaround to avoid some SPD corruption that can occur
 *  in power off scenarios, we want to park the eeprom onto a
 *  "safe" unused portion after any access.  We will do this
 *  by doing a 1-byte read to address 2048.
 */
errlHndl_t ddimmParkEeprom(TARGETING::TargetHandle_t i_target)
{
    errlHndl_t l_errhdl = nullptr;

    // Only need to worry if we actually touch hardware
#ifdef CONFIG_SUPPORT_EEPROM_HWACCESS

    TARGETING::EEPROM_CONTENT_TYPE eepromType = T::EEPROM_CONTENT_TYPE_RAW;
    T::ATTR_EEPROM_VPD_PRIMARY_INFO_type l_eepromVpd;
    if( i_target->tryGetAttr<T::ATTR_EEPROM_VPD_PRIMARY_INFO>(l_eepromVpd) )
    {
        eepromType = static_cast<TARGETING::EEPROM_CONTENT_TYPE>
          (l_eepromVpd.eepromContentType);
    }

    // Make sure this is a DDIMM (in case we support ISDIMMs at some point)
    if( (TARGETING::EEPROM_CONTENT_TYPE_DDIMM == eepromType)
        && !tl_parkRecursion ) //avoid infinite recursion
    {
        tl_parkRecursion = true;
        constexpr size_t DDIMM_SPD_SAFE_OFFSET = 2048;
        uint8_t l_byte = 0;
        size_t l_numBytes = 1;
        l_errhdl = DeviceFW::deviceOp(DeviceFW::READ,
                                i_target,
                                &l_byte,
                                l_numBytes,
                                DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                                      DDIMM_SPD_SAFE_OFFSET,
                                                      EEPROM::HARDWARE));
        if( l_errhdl )
        {
            TRACFCOMP(g_trac_spd,
                      ERR_MRK"ddimmParkEeprom> Failed on %08X",
                      TARGETING::get_huid(i_target));
            l_errhdl->collectTrace( "SPD", 1*KILOBYTE );
        }
        tl_parkRecursion = false;
    }

#endif //#ifdef CONFIG_SUPPORT_EEPROM_CACHING

    return l_errhdl;
}

// Also want to register against the Generic VPD driver, but we need a
//  wrapper to handle the extra "record" argument
errlHndl_t ocmbSPDPerformOp_generic ( DeviceFW::OperationType i_opType,
                                      TARGETING::Target * i_target,
                                      void * io_buffer,
                                      size_t & io_buflen,
                                      int64_t i_accessType,
                                      va_list i_args )
{
    //first arg is a record that we ignore
    uint64_t l_record = va_arg( i_args, uint64_t );
    assert( l_record == SPD::NO_RECORD );

    //i_args is modified by va_arg so just pass it directly in
    return ocmbSPDPerformOp(i_opType,
                            i_target,
                            io_buffer,
                            io_buflen,
                            i_accessType,
                            i_args);
}
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::VPD,
                      T::TYPE_OCMB_CHIP,
                      ocmbSPDPerformOp_generic );


errlHndl_t getMemInfo(T::TargetHandle_t     i_target,
                      spdMemType_t & o_memType,
                      spdModType_t & o_memModType,
                      dimmModHeight_t & o_memHeight,
                      EEPROM::EEPROM_SOURCE i_eepromSource)
{
    errlHndl_t err{nullptr};

    // initialize to invalid data
    o_memType = SPD::MEM_TYPE_INVALID;
    o_memModType = SPD::MOD_TYPE_INVALID;
    o_memHeight = SPD::DDIMM_MOD_HEIGHT_INVALID;

    do {
        err = OCMB_SPD::getMemType(o_memType, i_target, i_eepromSource);
        if (err)
        {
            break;
        }

        if (SPD::isValidOcmbDimmType(o_memType))
        {
            static_assert( sizeof(o_memModType) == SPD::MOD_TYPE_SZ );
            err = ocmbFetchData(i_target,
                                SPD::MOD_TYPE_ADDR,
                                SPD::MOD_TYPE_SZ,
                                &o_memModType,
                                i_eepromSource);
            if (err)
            {
                TRACFCOMP(g_trac_spd,
                      ERR_MRK"getMemInfo> Unable to read modType for OCMB 0x%08X",
                      TARGETING::get_huid(i_target));
                break;
            }

            if (o_memModType == SPD::MOD_TYPE_DDIMM)
            {
                // Module height byte varies by dimm type so need to use the
                // more complex call that supports all varieties.
                static_assert( sizeof(o_memHeight) == SPD::DDIMM_MOD_HEIGHT_SZ );
                size_t l_len = SPD::DDIMM_MOD_HEIGHT_SZ;
                err = ocmbGetSPD(i_target,
                                 &o_memHeight,
                                 l_len,
                                 DDIMM_MODULE_HEIGHT,
                                 o_memType,
                                 i_eepromSource);
                if (err)
                {
                    TRACFCOMP(g_trac_spd,
                      ERR_MRK"getMemInfo> Unable to read DDIMM height for OCMB 0x%08X",
                      TARGETING::get_huid(i_target));
                    break;
                }
            }
        }
        else
        {
            TRACFCOMP(g_trac_spd,
                      ERR_MRK"getMemInfo> Unsupported OCMB dimm type 0x%02X for OCMB 0x%08X",
                      o_memType, TARGETING::get_huid(i_target));
            break;
        }

    } while(0);

    return err;
}

} // End of SPD namespace


namespace OCMB_SPD
{

// ------------------------------------------------------------------
// getMemType
// ------------------------------------------------------------------
errlHndl_t getMemType(SPD::spdMemType_t&    o_memType,
                      T::TargetHandle_t     i_target,
                      EEPROM::EEPROM_SOURCE i_location)
{
    errlHndl_t err = nullptr;

    static_assert( sizeof(o_memType) == SPD::MEM_TYPE_SZ );
    err = ocmbFetchData(i_target,
                        SPD::MEM_TYPE_ADDR,
                        SPD::MEM_TYPE_SZ,
                        &o_memType,
                        i_location);

    TRACSSCOMP(g_trac_spd,
               EXIT_MRK"SPD::getMemType() - MemType: 0x%02x, Error: %s",
               o_memType,
               ((err != nullptr) ? "Yes" : "No"));

    return err;
}




}
