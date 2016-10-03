/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatspiraH.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 *  @file hdatspiraH.H
 *
 *  @brief This file contains the definition of the Service Processor Interface
 *         Root Array Secure boot (SPIRA-H) data structure.  This data structure 
 *         is prebuilt as part of one of the LIDS loaded into memory.
 *
 *         Usage note:  The SPIRA-H structure is built as part of the host LIDs.
 *         These are big endian structures.  If this structure is used on a little
 *         endian machine, the user is responsible for performing big endian to
 *         little endian conversions.
 */

/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <sys/mm.h>
#include <sys/mmio.h>
#include "hdatspiraH.H"
#include "hdatutil.H"
#include "hdatvpd.H"
#include <util/align.H>
#include <targeting/common/util.H>
/*-----------------------------------------------------------------------------*/
/* Global variables                                                            */
/*-----------------------------------------------------------------------------*/
extern trace_desc_t *g_trac_hdat;
/*-----------------------------------------------------------------------------*/
/* Constants                                                                   */
/*-----------------------------------------------------------------------------*/
const uint16_t HDAT_SPIRAH_VERSION = 0x50;

using namespace TARGETING;

namespace HDAT
{

/**
 * @brief Construct an HdatSpiraH object.
 *
 *        This function maps the Service Processor Interface Root Array (SPIRA-H)
 *        structure from the mainstore address where the containing lid loaded. 
 *
 * @pre The SPIRA-H containing Lid must have loaded in mainstore.
 *
 * @post The SPIRA-H data mapped to a HB process' memory
 *
 * @param o_errlHndl - output parameter - error log handle
 *
 * @return A null error log handle if successful, else the return code pointed 
 *         to by errlHndl_t 
 *
 */
HdatSpiraH::HdatSpiraH(errlHndl_t &o_errlHndl, hdatMsAddr_t &i_msAddr)
{

    HDAT_ENTER();

    HDAT_DBG("HdatSpiraH i_msAddr addr hi 0x%08X lo 0x%08X",
                  i_msAddr.hi, i_msAddr.lo);
    memcpy(&iv_msAddr , &i_msAddr , sizeof(hdatMsAddr_t));

    // Get Target Service, and the system target.
    TargetService& l_targetService = targetService();
    TARGETING::Target* l_sysTarget = NULL;
    (void) l_targetService.getTopLevelTarget(l_sysTarget);

    // asserting
    assert(l_sysTarget != NULL);

    uint64_t l_hrmor = l_sysTarget->getAttr<ATTR_PAYLOAD_BASE>();
    l_hrmor = l_sysTarget->getAttr<ATTR_PAYLOAD_BASE>() * MEGABYTE;
    iv_msAddr +=l_hrmor;

    // Allocate space for spiraH in process memory

    iv_spirah = reinterpret_cast<hdatSpiraH_t *>(calloc(sizeof(hdatSpiraH_t),
                                                 1));

    if(NULL == o_errlHndl) 
    { // Set SPIRA-H to defaults 
        setSpiraHHdrs();
    }

    // Now get the spiraH from mainstore address.
    o_errlHndl = getSpiraH();

    HDAT_EXIT();
    return;
}

/**
 * @brief This function gets the spirah from the stored mainstore adress.
 *         The mainstore address is where spirah is loaded as part of lid. 
 *
 * @pre The primary LID which contains the NACA and the primary/secondary LID
 *      which contains the SPIRA-H must have been loaded
 *
 * @post The SPIRA-H is copied into process space.
 *
 */
errlHndl_t HdatSpiraH::getSpiraH()
{
    errlHndl_t l_errlHndl = NULL;
    HDAT_ENTER();

    if(iv_msAddr != 0)
    {
        uint64_t l_base_addr_down = ALIGN_PAGE_DOWN((uint64_t)iv_msAddr);
        iv_virt_addr  = (uint8_t *)mm_block_map(
                    reinterpret_cast<void*>(l_base_addr_down),
                    (ALIGN_PAGE(sizeof(hdatSpiraH_t)) + PAGESIZE));
        iv_virt_addr = iv_virt_addr +
            ((uint64_t)iv_msAddr - ALIGN_PAGE_DOWN((uint64_t)iv_msAddr));

        memcpy((void *)iv_spirah,(void *)iv_virt_addr,sizeof(hdatSpiraH_t));
    }
    else
    {
        /*@
        * @errortype
        * @moduleid         HDAT::MOD_HDAT_GET_SPIRAH
        * @reasoncode       HDAT::RC_NULL_PTR_PASSED
        * @devdesc          Null passed for spirah ms addr
        * @custdesc         Firmware encountered an internal error.
        */

        hdatBldErrLog(l_errlHndl,
                MOD_HDAT_GET_SPIRAH,
                RC_NULL_PTR_PASSED,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }
    HDAT_EXIT();
    return l_errlHndl;
}


/**
 * @brief HdatSpiraH object destructor
 *
 *        This is the destructor for an HdatSpiraH object.  Any heap storage 
 *        allocated for the object is dallocated.
 *
 * @pre No preconditions exist
 *
 * @post The HdatSpiraH object has been destroyed and can no longer be used.
 *
 */
HdatSpiraH::~HdatSpiraH()
{
    errlHndl_t l_errlHndl = NULL;
    uint32_t rc=0;
    HDAT_ENTER();

    free(iv_spirah);
    if(iv_virt_addr != NULL)
    {
        rc =  mm_block_unmap(reinterpret_cast<void*>(
                        ALIGN_PAGE_DOWN((uint64_t)iv_virt_addr)));
        if( rc != 0)
        {
            /*@
            * @errortype
            * @moduleid         HDAT::MOD_HDAT_SPIRAH_DTOR
            * @reasoncode       HDAT::RC_DEV_MAP_FAIL
            * @userdata1        Spirah address hi
            * @userdata2        Spirah address lo
            * @devdesc          Unmap a mapped region failed
            * @custdesc         Firmware encountered an internal error.
            */
            hdatBldErrLog(l_errlHndl,
                    HDAT::MOD_HDAT_SPIRAH_DTOR,
                    RC_DEV_MAP_FAIL,
                    static_cast<uint32_t>(iv_msAddr>> 32),
                    static_cast<uint32_t>(iv_msAddr),
                    0,0,
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    HDAT_VERSION1,
                    true);
        }
    }

    HDAT_EXIT();
}


/**
 * @brief This function computes the address of a 5-tuple entry within the
 *        SPIRA-H structure and returns it.
 *
 *        Usage note:  The SPIRA-H structure is built as part of the host LIDs.
 *        These are big endian structures.  This function performs any
 *        big endian to little endian conversions needed.
 *
 * @pre None
 *
 * @post A copy of the desired 5-tuple returned, with any endian conversion done.
 *
 * @param i_dataArea - input parameter - an enumeration for the 5-tuple entry
 *                     being requested.
 * @param o_entry    - output parameter - a copy of the 5-tuple entry being
 *                     requested, with any endian conversion already performed.
 *
 * @return NONE
 */
void HdatSpiraH::getSpiraHEntry(hdatSpiraHDataAreas i_dataArea,
                              hdat5Tuple_t &o_entry)
{
    HDAT_ENTER();
    hdatHDIF_t *l_hdif;
    hdatHDIFDataHdr_t *l_dataHdr;
    hdat5Tuple_t *l_entry;
    hdatHDIFDataArray_t *l_arrayHdr;

    // Compute the address of the entry in the SPIRA-H the caller wants.  This
    // entry is a 5-tuple for a particular data structure.
    l_hdif = reinterpret_cast<hdatHDIF_t *>(iv_spirah);

    l_dataHdr = reinterpret_cast<hdatHDIFDataHdr_t *>(reinterpret_cast<char *>
                (l_hdif) + l_hdif->hdatDataPtrOffset);

    l_arrayHdr = reinterpret_cast<hdatHDIFDataArray_t *>(
                  reinterpret_cast<char *>(l_hdif) + l_dataHdr->hdatOffset);

    l_entry = reinterpret_cast<hdat5Tuple_t *>(reinterpret_cast<char *>
                             (l_arrayHdr) + l_arrayHdr->hdatOffset +
                             (l_arrayHdr->hdatAllocSize) * i_dataArea);

    o_entry.hdatAbsAddr.hi = l_entry->hdatAbsAddr.hi;
    o_entry.hdatAbsAddr.lo = l_entry->hdatAbsAddr.lo;
    o_entry.hdatAllocCnt   = l_entry->hdatAllocCnt;
    o_entry.hdatActualCnt  = l_entry->hdatActualCnt;
    o_entry.hdatAllocSize  = l_entry->hdatAllocSize;
    o_entry.hdatActualSize = l_entry->hdatActualSize;
    o_entry.hdatTceOffset  = l_entry->hdatTceOffset;
    HDAT_EXIT();
    return;
}

/**
 * @brief This function updates a SPIRA-H entry.  Any required endian conversion
 *        is performed on the 5-tuple entry before the update.
 *
 * @pre None
 *
 * @post The SPIRA-H has been updated
 *
 * @param i_dataArea - input parameter - An enumeration for the 5-tuple entry
 *                     being updated.
 * @param i_entry    - input parameter - the 5-tuple entry being updated.
 */
void HdatSpiraH::chgSpiraHEntry(hdatSpiraHDataAreas i_dataArea,
                              const hdat5Tuple_t &i_entry)
{
    HDAT_ENTER();
    hdatHDIF_t *l_hdif;
    hdatHDIFDataHdr_t *l_dataHdr;
    hdatHDIFDataArray_t *l_arrayHdr;
    hdat5Tuple_t *l_entry;

    // Compute the address of the entry in the SPIRA-H the caller wants.  This
    // entry is a 5-tuple for a particular data structure.
    l_hdif = reinterpret_cast<hdatHDIF_t *>(iv_spirah);

    l_dataHdr = reinterpret_cast<hdatHDIFDataHdr_t *>(reinterpret_cast<char *>
                (l_hdif) + l_hdif->hdatDataPtrOffset);

    l_arrayHdr = reinterpret_cast<hdatHDIFDataArray_t *>(
                 reinterpret_cast<char *>(l_hdif) + l_dataHdr->hdatOffset);

    l_entry = reinterpret_cast<hdat5Tuple_t *>(reinterpret_cast<char *>
                             (l_arrayHdr) + l_arrayHdr->hdatOffset +
                             l_arrayHdr->hdatAllocSize * i_dataArea);

    // Update the data in the SPIRA-H entry.
    l_entry->hdatAbsAddr.hi = i_entry.hdatAbsAddr.hi;
    l_entry->hdatAbsAddr.lo = i_entry.hdatAbsAddr.lo;
    l_entry->hdatAllocCnt   = i_entry.hdatAllocCnt;
    l_entry->hdatActualCnt  = i_entry.hdatActualCnt;
    l_entry->hdatAllocSize  = i_entry.hdatAllocSize;
    l_entry->hdatActualSize = i_entry.hdatActualSize;
    l_entry->hdatTceOffset  = i_entry.hdatTceOffset;

    HDAT_EXIT();
    return;
}

/** 
 * @brief This routine initializes the SPIRA-H HDIF header and clears the N-Tuple array
 *       
 * @pre None
 *
 * @post None
 *
 * @param None
 *
 * @return None
 *
 * @retval no errors currently defined
 */
void HdatSpiraH::setSpiraHHdrs()
{
    HDAT_ENTER();
    iv_spirah->hdatHDIF.hdatStructId       = HDAT_HDIF_STRUCT_ID;
    iv_spirah->hdatHDIF.hdatInstance       = 0;
    iv_spirah->hdatHDIF.hdatVersion       = HDAT_SPIRAH_VERSION;
    iv_spirah->hdatArrayInfo.hdatArrayCnt = HDAT_SPIRAH_DA_LAST;
    iv_spirah->hdatHDIF.hdatSize           = sizeof(hdatSpiraH_t);

    iv_spirah->hdatHDIF.hdatHdrSize        = sizeof(hdatHDIF_t);
    iv_spirah->hdatHDIF.hdatDataPtrOffset  = sizeof(hdatHDIF_t);
    iv_spirah->hdatHDIF.hdatDataPtrCnt     = 1;
    iv_spirah->hdatHDIF.hdatChildStrCnt    = 0;
    iv_spirah->hdatHDIF.hdatChildStrOffset = 0;

    memcpy(iv_spirah->hdatHDIF.hdatStructName, HDAT_SPIRAH_EYE_CATCHER, sizeof(iv_spirah->hdatHDIF.hdatStructName));

    iv_spirah->hdatDataHdr.hdatOffset = offsetof(hdatSpiraH_t, hdatArrayInfo);
    iv_spirah->hdatDataHdr.hdatSize = sizeof(hdatHDIFDataArray_t) + sizeof(iv_spirah->hdatDataArea);
    iv_spirah->hdatArrayInfo.hdatOffset = sizeof(hdatHDIFDataArray_t);
    iv_spirah->hdatArrayInfo.hdatAllocSize = sizeof(hdat5Tuple_t);
    iv_spirah->hdatArrayInfo.hdatActSize = offsetof(hdat5Tuple_t, hdatReserved1);

    memset(iv_spirah->hdatDataArea, 0, sizeof((iv_spirah->hdatDataArea)));
    HDAT_EXIT();
    return;
}


void HdatSpiraH::chgSpiraHEntry(hdatSpiraHDataAreas i_dataArea,
                                    uint32_t i_actCount,uint32_t i_actSize)
{
    HDAT_ENTER();
    hdatSpiraH_t * l_temp;

    l_temp = reinterpret_cast<hdatSpiraH_t *>(iv_virt_addr);
    HDAT_DBG("updating the spiraH hostdata area with count=0x%x and size=0x%x",
              i_actCount,i_actSize);
    l_temp->hdatDataArea[i_dataArea].hdatActualCnt = i_actCount;
    l_temp->hdatDataArea[i_dataArea].hdatActualSize = i_actSize;

    HDAT_DBG("actual count=0x%x, actual size=0x%x",
             l_temp->hdatDataArea[i_dataArea].hdatActualCnt,
             l_temp->hdatDataArea[i_dataArea].hdatActualSize);

    HDAT_EXIT();
}

} //HDAT 
