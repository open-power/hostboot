/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatmsvpd.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
 * @file hdatmsvpd.C
 *
 * @brief This file contains the implementation of the HdatMsVpd class.
 *
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include "hdatmsvpd.H"              // HdatMsVpd class definition
#include "hdathdif.H"
#include <sys/mm.h>
#include <sys/mmio.h>
#include <assert.h>
#include <util/align.H>
#include <limits.h>


namespace HDAT
{
/*----------------------------------------------------------------------------*/
/* Global variables                                                           */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Macros                                                                     */
/*----------------------------------------------------------------------------*/
// macro to compute the address of a main store area
#define HDAT_MS_AREA(_i_idx_)  *((HdatMsArea **)((char *)iv_msAreaPtrs + \
_i_idx_ * sizeof(HdatMsArea *)))

/** @brief See the prologue in hdatmsvpd.H
 */
HdatMsVpd::HdatMsVpd(errlHndl_t &o_errlHndl,
                     const hdatMsAddr_t &i_msAddr
                     ):HdatHdif(o_errlHndl,
    HDAT_MSVPD_STRUCT_NAME, HDAT_MS_VPD_LAST, HDAT_START_INSTANCE,
    HDAT_MS_CHILD_LAST, HDAT_MS_VPD_VERSION),
    iv_actMsAreaCnt(0), iv_maxMsAreaCnt(0), iv_msAreaPtrs(NULL),
    iv_IMTaddrRangeArray(NULL), iv_maxIMTAddrRngCnt(0),
    iv_UEaddrRangeArray(NULL), iv_maxUEAddrRngCnt(0)
{
    memcpy(&iv_msAddr, &i_msAddr, sizeof(hdatMsAddr_t));
}



void HdatMsVpd::hdatInit(hdatMsAddr_t &i_maxMsAddr,
                         hdatMsAddr_t &i_maxMsCcmAddr,
                         uint32_t i_msSize,
                         uint32_t i_msAreaCnt,
                         uint32_t i_MostSigAffinityDomain,
                         uint32_t i_ueAreaCnt,
                         uint64_t i_MirrMemStartAddr)
{
    HDAT_ENTER();
    iv_maxUEAddrRngCnt = i_ueAreaCnt;
    iv_maxMsAreaCnt = i_msAreaCnt;
    iv_maxIMTAddrRngCnt = i_msAreaCnt;
    memcpy(&iv_maxAddr.hdatMaxAddr, &i_maxMsAddr, sizeof(hdatMsAddr_t));
    memcpy(&iv_maxAddr.hdatMaxCcmAddr, &i_maxMsCcmAddr, sizeof(hdatMsAddr_t));
    iv_maxAddr.hdatMstSigAffntyDom = i_MostSigAffinityDomain;
    memcpy(&iv_maxAddr.hdatMirrMemStartAddr, &i_MirrMemStartAddr,
            sizeof(hdatMsAddr_t));
    memset(&iv_maxAddr.hdatHRMORstashLoc,0x00,sizeof(hdatMsAddr_t));
    iv_maxSize.hdatReserved1 = 0;
    iv_maxSize.hdatTotSize = i_msSize;
    memset(&iv_mover, 0x00, sizeof(hdatMsVpdPageMover_t));
    iv_IMTaddrRngArrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    iv_IMTaddrRngArrayHdr.hdatArrayCnt  = 0;
    iv_IMTaddrRngArrayHdr.hdatAllocSize = sizeof(hdatMsVpdImtAddrRange_t);
    iv_IMTaddrRngArrayHdr.hdatActSize   = sizeof(hdatMsVpdImtAddrRange_t);
    iv_UEaddrRngArrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    iv_UEaddrRngArrayHdr.hdatArrayCnt  = 0;
    iv_UEaddrRngArrayHdr.hdatAllocSize = sizeof(hdatMsVpdUEAddrRange_t);
    iv_UEaddrRngArrayHdr.hdatActSize   = sizeof(hdatMsVpdUEAddrRange_t);
    iv_RHBaddrRngArrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    iv_RHBaddrRngArrayHdr.hdatArrayCnt  = 0;
    iv_RHBaddrRngArrayHdr.hdatAllocSize = sizeof(hdatMsVpdRhbAddrRange_t);
    iv_RHBaddrRngArrayHdr.hdatActSize   = sizeof(hdatMsVpdRhbAddrRange_t);

    iv_maxRHBAddrRngCnt = HDAT_RHB_MAX_RANGE_ENTRIES * hdatGetMaxCecNodes();

    // Allocate space for the mainstore area entries and IMT Addr Range array
    iv_msAreaPtrs = new HdatMsArea*[iv_maxMsAreaCnt];
    iv_IMTaddrRangeArray = new hdatMsVpdImtAddrRange_t[iv_maxIMTAddrRngCnt];
    iv_UEaddrRangeArray = new hdatMsVpdUEAddrRange_t[iv_maxUEAddrRngCnt];
    // Allocate space for the host boot memory reserve range
    iv_RHBaddrRangeArray = new hdatMsVpdRhbAddrRange_t[iv_maxRHBAddrRngCnt];

    // Update the base class internal data pointers.
    // When the data is written to the file by commit(), it must be done in the
    // same order as these addData() calls
    this->addData(HDAT_MS_VPD_MAX_ADDR, sizeof(hdatMsVpdAddr_t));
    this->addData(HDAT_MS_VPD_MAX_SIZE, sizeof(hdatMsVpdSize_t));
    this->addData(HDAT_MS_VPD_PAGE_MOVER, sizeof(hdatMsVpdPageMover_t));

    this->addData(HDAT_MS_VPD_IMT_ADDR_RNG, (sizeof(hdatHDIFDataArray_t) +
                  (iv_maxIMTAddrRngCnt * sizeof(hdatMsVpdImtAddrRange_t))));
    this->addData(HDAT_MS_VPD_UE_ADDR_RNG, (sizeof(hdatHDIFDataArray_t) +
                  (iv_maxUEAddrRngCnt * sizeof(hdatMsVpdUEAddrRange_t))));

    this->addData(HDAT_MS_VPD_HB_ADDR_RNG, (sizeof(hdatHDIFDataArray_t) +
				    (iv_maxRHBAddrRngCnt * sizeof(hdatMsVpdRhbAddrRange_t))));
    this->align();

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdatmsvpd.H
 */
HdatMsVpd::~HdatMsVpd()
{

    uint32_t l_cnt;
    HdatMsArea *l_obj, **l_curPtr;

    // Delete mainstore area objects (which in turn delete RAM objects)
    l_curPtr = iv_msAreaPtrs;
    for (l_cnt = 0; l_cnt < iv_actMsAreaCnt; l_cnt++)
    {
        l_obj = *l_curPtr;
        delete l_obj;
        l_curPtr = reinterpret_cast<HdatMsArea**>(reinterpret_cast<char*>
        (l_curPtr) + sizeof(HdatMsArea *));
    }

    delete[] iv_msAreaPtrs;

    // Delete IMT Address Range Array
    delete[]  iv_IMTaddrRangeArray;

    // Delete UE Address Range Array
    delete[] iv_UEaddrRangeArray;

    delete[] iv_RHBaddrRangeArray;

    uint64_t l_addr = reinterpret_cast<uint64_t> (iv_virtAddr);
    l_addr =  ALIGN_PAGE_DOWN(l_addr);

    iv_virtAddr = reinterpret_cast<void*>(l_addr);

    int rc =  mm_block_unmap(iv_virtAddr);
    if( rc != 0)
    {
        errlHndl_t l_errl = NULL;
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_MSVPD_DESTRUCTOR
         * @reasoncode       HDAT::RC_DEV_MAP_FAIL
         * @devdesc          Unmap a mapped region failed
         * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(l_errl,
                MOD_MSVPD_DESTRUCTOR,
                RC_DEV_MAP_FAIL,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }

    return;
}

/** @brief See the prologue in hdatmsvpd.H
 */
errlHndl_t HdatMsVpd::addIMTAddrRange(hdatMsAddr_t &i_start,
                                      hdatMsAddr_t &i_end)
{

    errlHndl_t l_errlHndl = NULL;
    hdatMsVpdImtAddrRange_t *l_addr;

    if (iv_IMTaddrRngArrayHdr.hdatArrayCnt < iv_maxIMTAddrRngCnt)
    {
        l_addr = reinterpret_cast<hdatMsVpdImtAddrRange_t*>(reinterpret_cast
        <char*>(iv_IMTaddrRangeArray) + (iv_IMTaddrRngArrayHdr.hdatArrayCnt *
         sizeof(hdatMsVpdImtAddrRange_t)));

        l_addr->hdatImtAddrRngStrAddr = i_start;
        l_addr->hdatImtAddrRngEndAddr = i_end;
        iv_IMTaddrRngArrayHdr.hdatArrayCnt++;
    }
    else
    {
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode RC_ERC_MAX_EXCEEDED
         * @moduleid  MOD_ADD_IMT_ADDR_RANGE
         * @userdata1 current number of array entries
         * @userdata2 maximum number of array entries
         * @userdata3 none
         * @userdata4 none
         * @devdesc   Exceeded limit of number of mainstore VPD
         *            In Memory Trace array entries
         * @custdesc  Firmware encountered an internal error.
         */
        hdatBldErrLog(l_errlHndl,
                  MOD_ADD_IMT_ADDR_RANGE,        // SRC module ID
                  RC_ERC_MAX_EXCEEDED,          // SRC extended reference code
                  iv_IMTaddrRngArrayHdr.hdatArrayCnt, // SRC hex word 1
                  iv_maxIMTAddrRngCnt);           // SRC hex word 2
    }

    return l_errlHndl;
}


/** @brief See the prologue in hdatmsvpd.H
 */
errlHndl_t HdatMsVpd::addUEAddrRange(hdatMsAddr_t &i_addr)
{

    errlHndl_t l_errlHndl = NULL;
    hdatMsVpdUEAddrRange_t *l_addr;

    if (iv_UEaddrRngArrayHdr.hdatArrayCnt < iv_maxUEAddrRngCnt)
    {
        l_addr = reinterpret_cast<hdatMsVpdUEAddrRange_t*>(reinterpret_cast
        <char*>(iv_UEaddrRangeArray) + (iv_UEaddrRngArrayHdr.hdatArrayCnt *
        sizeof(hdatMsVpdUEAddrRange_t)));

        l_addr->hdatUEAddr = i_addr;
        iv_UEaddrRngArrayHdr.hdatArrayCnt++;
    }
    else
    {
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode RC_ERC_MAX_EXCEEDED
         * @moduleid MOD_ADD_UE_ADDR_RANGE
         * @userdata1 current number of array entries
         * @userdata2 maximum number of array entries
         * @userdata3 none
         * @userdata4 none
         * @devdesc Exceeded limit of number of mainstore
         *          VPD In Memory Trace array entries
         * @custdesc Firmware encountered an internal error.
         */
        hdatBldErrLog(l_errlHndl,
                  MOD_ADD_UE_ADDR_RANGE,     // SRC module ID
                  RC_ERC_MAX_EXCEEDED,      // SRC extended reference code
                  iv_UEaddrRngArrayHdr.hdatArrayCnt,  // SRC hex word 1
                  iv_maxUEAddrRngCnt);        // SRC hex word 2
    }

    return l_errlHndl;
}


errlHndl_t HdatMsVpd::addRHBAddrRange(uint32_t i_dbob_id, hdatMsAddr_t &i_start,
                                      hdatMsAddr_t &i_end, uint32_t i_labelSize,
                                      uint8_t* &i_labelStringPtr,
                                      hdatRhbPermType i_permission)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    hdatMsVpdRhbAddrRange_t *l_addr;

    if (iv_RHBaddrRngArrayHdr.hdatArrayCnt < iv_maxRHBAddrRngCnt)
    {
        l_addr = reinterpret_cast<hdatMsVpdRhbAddrRange_t*>(reinterpret_cast
        <char*>(iv_RHBaddrRangeArray) + (iv_RHBaddrRngArrayHdr.hdatArrayCnt *
        sizeof(hdatMsVpdRhbAddrRange_t)));

        l_addr->hdatRhbRngType        = HDAT::RHB_TYPE_INVALID;
        l_addr->hdatRhbRngId          = i_dbob_id;
        l_addr->hdatRhbAddrRngStrAddr = i_start;
        l_addr->hdatRhbAddrRngEndAddr = i_end;
        //TODO : : RTC Story 159684
        //Need to verify the correct data for label size and string
        if (i_labelSize <= HDAT_MS_RHB_LABEL_LEN)
        {
            l_addr->hdatRhbLabelSize = i_labelSize;
        }
        else
        {
            l_addr->hdatRhbLabelSize = HDAT_MS_RHB_LABEL_LEN;
        }

        memset(l_addr->hdatRhbLabelString, 0x00, HDAT_MS_RHB_LABEL_LEN);

        if (i_labelStringPtr != NULL)
        {
            for(uint8_t l_idx = 0; l_idx < l_addr->hdatRhbLabelSize; l_idx++)
            {
                l_addr->hdatRhbLabelString[l_idx] = i_labelStringPtr[l_idx];
            }
        }
        else
        {
            HDAT_INF("hdatmsvpd:addRHBAddrRange "
                       "i_labelStringPtr is NULL");
        }
        l_addr->hdatRhbPermission = i_permission;

        iv_RHBaddrRngArrayHdr.hdatArrayCnt++;
    }
    else
    {
        /*@
         * @errortype
         * @refcode    LIC_REFCODE
         * @subsys     EPUB_FIRMWARE_SP
         * @reasoncode RC_ERC_MAX_EXCEEDED
         * @moduleid   MOD_ADD_RES_HB_ADDR_RANGE
         * @userdata1  current number of array entries
         * @userdata2  maximum number of array entries
         * @userdata3  none
         * @userdata4  none
         * @devdesc    Exceeded limit of number of mainstore VPD Reserved
         *             Hostboot array entries
         * @custdesc   Firmware encountered an internal error.
         */
        hdatBldErrLog(l_errlHndl,
                  MOD_ADD_RES_HB_ADDR_RANGE,     // SRC module ID
                  RC_ERC_MAX_EXCEEDED,          // SRC extended reference code
                  iv_RHBaddrRngArrayHdr.hdatArrayCnt, // SRC hex word 1
                  iv_maxRHBAddrRngCnt);           // SRC hex word 2
    }

    HDAT_EXIT();
    return l_errlHndl;

}

/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setBSR(const hdatMsAddr_t &i_bsrAddr,
                       hdatBsrMode i_bsrMode)
{
    const uint32_t HDAT_BSR_ENABLED = 0x20000000;

    iv_mover.hdatFlags |= (HDAT_BSR_ENABLED | i_bsrMode);

    memcpy(&iv_mover.hdatBSRAddr, &i_bsrAddr, sizeof(hdatMsAddr_t));

    return;
}

/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setMirrorableMemoryStartAddress(
    const uint64_t &i_MirrMemStartAddr)
{
    memcpy(&iv_maxAddr.hdatMirrMemStartAddr, &i_MirrMemStartAddr,
        sizeof(hdatMsAddr_t));
}

/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setXSCOM(const hdatMsAddr_t &i_xscomAddr)
{
    HDAT_ENTER();

    const uint32_t HDAT_XSCOM_ENABLED = 0x10000000;

    iv_mover.hdatFlags |= HDAT_XSCOM_ENABLED;

    memcpy(&iv_mover.hdatXSCOMAddr, &i_xscomAddr, sizeof(hdatMsAddr_t));

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdatmsvpd.H
 */
errlHndl_t HdatMsVpd::addMsAreaFru(uint32_t i_resourceId,
                                   uint32_t i_slcaIndex,
                                   TARGETING::Target * i_target,
                                   uint16_t i_msAreaId,
                                   uint32_t i_ramCnt,
                                   uint32_t i_chipEcCnt,
                                   uint32_t i_addrRngCnt)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    HdatMsArea *l_msArea, **l_arrayEntry;
    char *l_kwd;
    uint32_t l_kwdSize;

    l_msArea = NULL;
    l_kwd = NULL;
    l_kwdSize = 0;

    // Ensure we are not over max mainstore areas that we were told this object
    // could handle on the constructor.
    if (iv_actMsAreaCnt < iv_maxMsAreaCnt)
    {
        // Create a mainstore area object and add it to the array of objects we
        // are managing
        l_msArea = new HdatMsArea(l_errlHndl,
                              i_target,
                              i_msAreaId,
                              i_ramCnt,
                              i_chipEcCnt,
                              i_addrRngCnt,
                              i_resourceId,
                              i_slcaIndex,
                              l_kwdSize,
                              l_kwd);
        if (NULL == l_errlHndl)
        {
            l_arrayEntry = reinterpret_cast<HdatMsArea**>(reinterpret_cast
            <char*>(iv_msAreaPtrs) + iv_actMsAreaCnt * sizeof(HdatMsArea *));

            *l_arrayEntry = l_msArea;
            iv_actMsAreaCnt++;
        }
        else
        {
            delete l_msArea;
        }
    }
    else
    {
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode  RC_ERC_MAX_EXCEEDED
         * @moduleid  MOD_ADD_MS_AREA_FRU
         * @userdata1 current array entry count
         * @userdata2 maximum array entry count
         * @userdata3 ID number of mainstore area that wasn't added
         * @userdata4 none
         * @devdesc Exceeded limit of number of mainstore area array entries
         * @custdesc Firmware encountered an internal error.
         */
        hdatBldErrLog(l_errlHndl,
                  MOD_ADD_MS_AREA_FRU,   // SRC module ID
                  RC_ERC_MAX_EXCEEDED,  // SRC extended reference code
                  iv_actMsAreaCnt,        // SRC hex word 1
                  iv_maxMsAreaCnt,        // SRC hex word 2
                  i_msAreaId);            // SRC hex word 3
    }

    HDAT_EXIT();
    return l_errlHndl;
}


/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setMsAreaType(uint16_t i_msAreaId,
                              hdatMemParentType i_type)
{
    HdatMsArea *l_obj;

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_obj->setParentType(i_type);
    }

    return;
}


/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setMsAreaStat(uint16_t i_msAreaId,
                              uint16_t i_status)
{

    HdatMsArea *l_obj;

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_obj->setStatus(i_status);
    }
    else
    {
        HDAT_ERR( "hdatmsvpd:setMsAreaStat - invalid i_msAreadId parameter");
    }

    return;
}


/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setMsAreaInterleavedId(uint16_t i_msAreaId,
                                       uint16_t i_id)
{
    HdatMsArea *l_obj;

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_obj->setInterleavedId(i_id);
    }
    else
    {
        HDAT_ERR( "hdatmsvpd:setMsAreaInterleavedId-invalid i_msAreadId "
            "parameter");
    }

    return;
}


/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setMsAreaSize(uint16_t i_msAreaId,
                              uint32_t i_size)
{
    HdatMsArea *l_obj;

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_obj->setSize(i_size);
    }
    else
    {
        HDAT_ERR( "hdatmsvpd:setMsAreaSize - invalid i_msAreadId parameter");
    }

    return;
}


/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setMsAreaModuleId(uint16_t i_msAreaId,
                                  uint32_t i_moduleId)
{
    HdatMsArea *l_obj;

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_obj->setModuleId(i_moduleId);
    }
    else
    {
        HDAT_ERR( "hdatmsvpd:setMsAreaModuleId - invalid i_msAreadId"
                    " parameter");
    }

    return;
}


/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::setMsAreaAffinityDomain(uint16_t i_msAreaId,
                                        uint32_t i_affinityDomain)
{
    HdatMsArea *l_obj;

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_obj->setAffinityDomain(i_affinityDomain);
    }
    else
    {
        HDAT_ERR("hdatmsvpd:setMsAreaAffinityDomain-invalid "
            "i_msAreadId parameter");
    }

    return;
}


/** @brief See the prologue in hdatmsvpd.H
 */
errlHndl_t HdatMsVpd::addMsAreaAddr(uint16_t i_msAreaId,
                                    hdatMsAddr_t &i_start,
                                    hdatMsAddr_t &i_end,
                                    uint32_t i_procChipId,
                                    bool i_rangeIsMirrorable,
                                    uint8_t i_mirroringAlgorithm,
                                    uint64_t i_startMirrAddr,
                                    uint32_t i_hdatMemCntrlID,
                                    bool i_hdatSmf)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    HdatMsArea *l_obj;
    hdatMsAddr_t l_startMirrAddr;

    memcpy(&l_startMirrAddr, &i_startMirrAddr, sizeof(hdatMsAddr_t));

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_errlHndl = l_obj->addAddrRange(i_start,
                                         i_end,
                                         i_procChipId,
                                         i_rangeIsMirrorable,
                                         i_mirroringAlgorithm,
                                         l_startMirrAddr,
                                         i_hdatMemCntrlID,
                                         i_hdatSmf);
    }
    else
    {
        HDAT_INF( "hdatmsvpd:addMsAreaAddr - invalid i_msAreadId parameter");
    }

    HDAT_EXIT();
    return l_errlHndl;
}

/** @brief See the prologue in hdatmsvpd.H
 */
errlHndl_t HdatMsVpd::addMsAreaMmioAddrRange(uint16_t i_msAreaId,
                                             hdatMsAddr_t &i_start,
                                             hdatMsAddr_t &i_end,
                                             uint32_t i_mmioMemCntlId,
                                             uint32_t i_mmioProcPhyChipId,
                                             uint64_t i_mmioHbrtChipId,
                                             uint64_t i_mmioFlags)
{
    errlHndl_t l_errlHndl = NULL;
    HdatMsArea *l_obj;

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_errlHndl = l_obj->addMmioAddrRange(i_start,
                                             i_end,
                                             i_mmioMemCntlId,
                                             i_mmioProcPhyChipId,
                                             i_mmioHbrtChipId,
                                             i_mmioFlags);
    }
    else
    {
        HDAT_INF( "HdatMsVpd::addMsAreaMmioAddrRange - invalid i_msAreadId "
            "parameter");
    }

    return l_errlHndl;
}

/** @brief See the prologue in hdatmsvpd.H
 */
errlHndl_t HdatMsVpd::addEcEntry(uint16_t i_msAreaId,
                                 uint32_t i_manfId,
                                 uint32_t i_ecLvl)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    HdatMsArea *l_obj;

    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_obj = HDAT_MS_AREA(i_msAreaId);
        l_errlHndl = l_obj->addEcEntry(i_manfId, i_ecLvl);
    }
    else
    {
        HDAT_ERR( "hdatmsvpd:addEcEntry - invalid i_msAreadId parameter");
    }

    HDAT_EXIT();
    return l_errlHndl;
}

/** @brief See the prologue in hdatmsvpd.H
 */
errlHndl_t HdatMsVpd::addRamFru(uint16_t i_msAreaId,
                                TARGETING::Target * i_target,
                                uint32_t i_resourceId,
                                uint32_t i_slcaIndex,
                                uint16_t i_ramId,
                                uint16_t i_status,
                                uint32_t i_size,
                                uint32_t i_dimmId,
                                uint32_t i_RamCurFreq)
{
    errlHndl_t l_errlHndl = NULL;

    HdatMsArea *l_msArea;;
    HdatRam *l_ram;

    // Ensure we are not over the current mainstore area count
    if (i_msAreaId < iv_actMsAreaCnt)
    {
        l_ram = NULL;
        l_msArea = HDAT_MS_AREA(i_msAreaId);

        // Create a RAM object
        l_ram = new HdatRam(l_errlHndl, i_target, i_resourceId,i_slcaIndex);
        if (NULL == l_errlHndl)
        {
            l_ram->iv_ramArea.hdatRamAreaId = i_ramId;
            l_ram->iv_ramArea.hdatRamStatus = i_status;
            l_ram->iv_ramArea.hdatRamDimmId = i_dimmId;
            l_ram->iv_ramArea.hdatRamCurFreq = i_RamCurFreq;
            l_ram->iv_ramSize.hdatRamTotalSize = i_size;

            // Add the RAM object to the mainstore area object
           if (l_msArea)
           {
                l_errlHndl = l_msArea->addRam(*l_ram);
           }
        }

        if (NULL != l_errlHndl)
        {
            delete l_ram;
        }
    }
    else
    {
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode RC_ERC_NO_PARENT
         * @moduleid MOD_ADD_RAM_FRU
         * @userdata1 main store area id
         * @userdata2 current count of main store areas
         * @userdata3 none
         * @userdata4 none
         * @devdesc Attempted to add a RAM FRU for an invalid mainstore area
         * @custdesc Firmware encountered an internal error.
        */
        HDAT_INF("Attempted to add a RAM FRU for an invalid mainstore area %d",
         i_msAreaId);

        hdatBldErrLog(l_errlHndl,
                  MOD_ADD_RAM_FRU,    // SRC module ID
                  RC_ERC_NO_PARENT,  // SRC extended reference code
                  i_msAreaId,          // SRC hex word 1
                  iv_actMsAreaCnt);    // SRC hex word 2
    }

    return l_errlHndl;
}


/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::adjustMsAreaObjects()
{
    HdatMsArea *l_msEntry;
    uint32_t l_idx, l_maxSize, l_tempSize;
    bool l_adjust;

    l_maxSize = 0;
    l_adjust = false;

    // Finalize the object size for each MS area object.  Also, determine if
    // the objects differ in size.  If they do, an extra step is needed to make
    // them all the same size.
    for (l_idx = 0; l_idx < iv_actMsAreaCnt; l_idx++)
    {
        l_msEntry = *(reinterpret_cast<HdatMsArea**>(reinterpret_cast
        <char*>(iv_msAreaPtrs) + l_idx * sizeof(HdatMsArea *)));

        l_msEntry->finalizeObjSize();  // Get the MS area sizes updated before
        // size() method is used
        l_tempSize = l_msEntry->size();
        if (l_maxSize != l_tempSize)
        {
            if (l_maxSize != 0)
            {
                l_adjust = true;
            }
            if (l_maxSize < l_tempSize)
            {
                l_maxSize = l_tempSize;
            }
        }
    }

    // Do we need to adjust some of the MS area objects to make them all the
    // same size?
    if (l_adjust)
    {
        for (l_idx = 0; l_idx < iv_actMsAreaCnt; l_idx++)
        {
            l_msEntry = *(reinterpret_cast<HdatMsArea**>(reinterpret_cast
            <char*>(iv_msAreaPtrs) + l_idx * sizeof(HdatMsArea *)));

            // If too small, adjust its size
            if (l_msEntry->size() < l_maxSize)
            {
                l_msEntry->maxSiblingSize(l_maxSize);
            }
        }
    }

    // Tell the base class about child and grandchild structures.
    for (l_idx = 0; l_idx < iv_actMsAreaCnt; l_idx++)
    {
        l_msEntry = *(reinterpret_cast<HdatMsArea**>(reinterpret_cast
            <char*>(iv_msAreaPtrs) + l_idx * sizeof(HdatMsArea *)));

        this->addChild(HDAT_MS_AREAS, l_msEntry->size(),1);//1st parm is 0 based
        this->addGrandChild(l_msEntry->ramObjSizes());
    }

    return;
}

/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::getTotalSize(uint32_t &o_size)
{

    HdatMsArea *l_msEntry;
    // Since MS area objects could be different sizes at this point (different
    // size for the VPD, for example) and since PHYP traverses the MS areas
    // as an array, we may need to adjust the MS areas so they are all the same
    // size.
    this->adjustMsAreaObjects();

    o_size = this->getSize();

    o_size += sizeof(hdatMsVpdAddr_t);

    o_size += sizeof(hdatMsVpdSize_t);

    o_size += sizeof(hdatMsVpdPageMover_t);

    o_size += sizeof(hdatHDIFDataArray_t);

    o_size += (iv_maxIMTAddrRngCnt * sizeof(hdatMsVpdImtAddrRange_t));

    o_size += sizeof(hdatHDIFDataArray_t);

    o_size += (iv_maxUEAddrRngCnt * sizeof(hdatMsVpdUEAddrRange_t));

    o_size += sizeof(hdatHDIFDataArray_t);

    o_size += (iv_maxRHBAddrRngCnt * sizeof(hdatMsVpdRhbAddrRange_t));

    o_size += this->endCommitSize();

    // Write the MS area structures and RAM structures
    if (iv_actMsAreaCnt > 0)
    {
        // All of the mainstore areas must be written first so that can be
        // processed as an array of mainstore areas.
        uint32_t l_ramSizes = 0;
        uint8_t     l_cnt = 0;
        uint8_t l_currOffset = 0;

        while (l_cnt < iv_actMsAreaCnt)
        {
            l_msEntry = *(reinterpret_cast<HdatMsArea**>(reinterpret_cast
            <char*>(iv_msAreaPtrs) + l_cnt * sizeof(HdatMsArea *)));

            // Since we don't know what order mainstore areas and RAM
            // areas were created, update the offset in the HdatMsArea
            // child structure triple so it points to the first RAM area.

            l_currOffset = (iv_actMsAreaCnt - l_cnt) * l_msEntry->size()
                    + l_ramSizes;
            l_msEntry->chgChildOffset(HDAT_MS_AREA_RAM_AREAS, l_currOffset);
            o_size += l_msEntry->getMsAreaSize();

            // Now compute the size of the RAM areas associated with this
            // mainstore area.  These will have to be added to the child offset
            // for the next mainstore area to skip over them.
            l_ramSizes += l_msEntry->ramObjSizes();

            l_cnt++;
        }

        // Now the children (RAM areas) of each mainstore area must be committed
        l_cnt = 0;

        while (l_cnt < iv_actMsAreaCnt)
        {
          l_msEntry = *(reinterpret_cast<HdatMsArea**>(reinterpret_cast
            <char*>(iv_msAreaPtrs) + l_cnt * sizeof(HdatMsArea *)));

          o_size += l_msEntry->getRamAreaSize();
          l_cnt++;
        }
      }

}


/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::prt()
{
    uint32_t l_cnt;
    HdatMsArea *l_obj;

    HDAT_INF("  **** HdatMsVpd start ****");
    HDAT_INF("      iv_msAddr = 0X %08X %08X ", iv_msAddr.hi, iv_msAddr.lo);
    HDAT_INF("      iv_actMsAreaCnt = %u", iv_actMsAreaCnt);
    HDAT_INF("      iv_maxMsAreaCnt = %u", iv_maxMsAreaCnt);
    this->print();

    HDAT_INF("  **hdatMsVpdAddr_t**");
    HDAT_INF("      hdatMaxAddr = 0X %08X %08X ", iv_maxAddr.hdatMaxAddr.hi,
            iv_maxAddr.hdatMaxAddr.lo);
    HDAT_INF("    hdatMaxCcmAddr = 0X %08X %08X ", iv_maxAddr.hdatMaxCcmAddr.hi,
             iv_maxAddr.hdatMaxCcmAddr.lo);
    HDAT_INF(" hdatMstSigAffntyDom = 0X %08X ", iv_maxAddr.hdatMstSigAffntyDom);
    HDAT_INF("      HRMOR stash loc = 0X %08X %08X \n",
      iv_maxAddr.hdatHRMORstashLoc.hi, iv_maxAddr.hdatHRMORstashLoc.lo);

    HDAT_INF("  **hdatMsVpdSize_t**");
    HDAT_INF("      hdatReserved1 = %u", iv_maxSize.hdatReserved1);
    HDAT_INF("      hdatTotSize = %u", iv_maxSize.hdatTotSize);

    HDAT_INF("  **hdatMsVpdPageMover_t**");
    HDAT_INF("      hdatFlags = %u", iv_mover.hdatFlags);
    HDAT_INF("      hdatLockCnt = %u", iv_mover.hdatLockCnt);
    HDAT_INF("      hdatLockAddr = 0X %08X %08X ", iv_mover.hdatLockAddr.hi,
         iv_mover.hdatLockAddr.lo);
    HDAT_INF("      hdatMoverAddr = 0X %08X %08X ", iv_mover.hdatMoverAddr.hi,
         iv_mover.hdatMoverAddr.lo);
    HDAT_INF("      hdatBSRAddr = 0X %08X %08X ", iv_mover.hdatBSRAddr.hi,
         iv_mover.hdatBSRAddr.lo);
    HDAT_INF("      hdatXSCOMAddr = 0X %08X %08X", iv_mover.hdatXSCOMAddr.hi,
        iv_mover.hdatXSCOMAddr.lo);

    HDAT_INF("  **hdatMsVpdImtAddrRange_t**");
    hdatPrintHdrs(NULL, NULL, &iv_IMTaddrRngArrayHdr, NULL);
{
    hdatMsVpdImtAddrRange_t *l_addr = iv_IMTaddrRangeArray;
    for (l_cnt = 0; l_cnt < iv_IMTaddrRngArrayHdr.hdatArrayCnt; l_cnt++)
    {
        HDAT_INF("      hdatImtAddrRngStrAddr = 0X %08X %08X ",
           l_addr->hdatImtAddrRngStrAddr.hi,
           l_addr->hdatImtAddrRngStrAddr.lo);
        HDAT_INF("      hdatImtAddrRngEndAddr = 0X %08X %08X ",
           l_addr->hdatImtAddrRngEndAddr.hi,
           l_addr->hdatImtAddrRngEndAddr.lo);
        l_addr++;
        l_cnt++;
    }
}
    HDAT_INF("  **hdatMsVpdUEAddrRange_t**");
    hdatPrintHdrs(NULL, NULL, &iv_UEaddrRngArrayHdr, NULL);
  {
    hdatMsVpdUEAddrRange_t *l_addr = iv_UEaddrRangeArray;
    for (l_cnt = 0; l_cnt < iv_UEaddrRngArrayHdr.hdatArrayCnt; l_cnt++)
    {
        HDAT_INF("      hdatUEAddrRngStrAddr = 0X %08X %08X ",
           l_addr->hdatUEAddr.hi,
           l_addr->hdatUEAddr.lo);
        l_addr++;
        l_cnt++;
    }
  }
    HDAT_INF("  **hdatMsVpdRhbAddrRange_t**");
    hdatPrintHdrs(NULL, NULL, &iv_RHBaddrRngArrayHdr, NULL);
  {
    hdatMsVpdRhbAddrRange_t *l_addr = iv_RHBaddrRangeArray;
    for (l_cnt = 0; l_cnt < iv_RHBaddrRngArrayHdr.hdatArrayCnt; l_cnt++)
    {
        HDAT_INF("     hdatRhbAddrRngStrAddr  = 0X %08X %08X ",
           l_addr->hdatRhbAddrRngStrAddr.hi,
           l_addr->hdatRhbAddrRngStrAddr.lo);
        HDAT_INF("      hdatRhbAddrRngEndAddr = 0X %08X %08X ",
           l_addr->hdatRhbAddrRngEndAddr.hi,
           l_addr->hdatRhbAddrRngEndAddr.lo);
        l_addr++;
        l_cnt++;
    }

  }
    HDAT_INF("");;

    HDAT_INF("  **** HdatMsVpd end ****");

    HDAT_INF("  **main store areas and their associated RAM areas**");
    for (l_cnt = 0; l_cnt < iv_actMsAreaCnt; l_cnt++)
    {
        l_obj = *(HdatMsArea **)((char *)iv_msAreaPtrs + l_cnt *
                 sizeof(HdatMsArea *));
        l_obj->prt();
    }

    return;
}




/*******************************************************************************
*  hdatLoadMsData
*******************************************************************************/
errlHndl_t  HdatMsVpd::hdatLoadMsData(uint32_t &o_size, uint32_t &o_count)
{
    errlHndl_t l_err = NULL;
    HDAT_ENTER();

    do
    {
        //Find the system target
        TARGETING::Target *l_pSysTarget = NULL;
        (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

        assert(l_pSysTarget != NULL);

        hdatMsAddr_t l_addr_range;
        hdatMsAddr_t l_end;
        l_addr_range.hi = 0x0;
        l_addr_range.lo = 0x0;
        l_end = l_addr_range;

        //Get the processor model
        auto l_model = TARGETING::targetService().getProcessorModel();

        uint32_t l_sizeConfigured = 0;

        uint64_t l_maxMsAddr =
            hdatGetMaxMemConfiguredAddress(l_model);

        hdatMsAddr_t l_tmpMaxMsAddr;
        l_tmpMaxMsAddr.hi = (l_maxMsAddr & 0xFFFFFFFF00000000ull) >> 32;
        l_tmpMaxMsAddr.lo =  l_maxMsAddr & 0x00000000FFFFFFFFull;

        HDAT_INF("MaxMsAddr high:0x%.8X 0x%.8X",
                 l_tmpMaxMsAddr.hi,l_tmpMaxMsAddr.lo);

        uint32_t l_mostSigAffinityDomain_x = 0;
        uint32_t l_ueCount = 1;

        uint64_t l_origMirroringBaseAddress = 0xFFFFFFFFFFFFFFFFull;
        HDAT_INF("fetching ATTR_MIRROR_BASE_ADDRESS");
        TARGETING::ATTR_MIRROR_BASE_ADDRESS_type l_mirroringBaseAddress_x =
             l_pSysTarget->getAttr<TARGETING::ATTR_MIRROR_BASE_ADDRESS>();
        HDAT_INF("fetched l_mirroringBaseAddress_x value= 0x%x",l_mirroringBaseAddress_x);

        TARGETING::ATTR_MIRROR_BASE_ADDRESS_type l_mirrorBaseAddress_x = l_mirroringBaseAddress_x;

        l_mirroringBaseAddress_x |= HDAT_REAL_ADDRESS_MASK64;
        HDAT_INF("after masking l_mirroringBaseAddress_x=0x%x",l_mirroringBaseAddress_x);
        //TODO : RTC Story 246361 HDAT Nimbus/Cumulus model code removal
        /*
        TARGETING::ATTR_MAX_MCS_PER_SYSTEM_type l_maxMsAreas =
                   l_pSysTarget->getAttr<TARGETING::ATTR_MAX_MCS_PER_SYSTEM>();

        if (l_model == TARGETING::MODEL_NIMBUS)
        {
            l_maxMsAreas *= 2;
        }
        else
        {
            l_maxMsAreas = HDAT_MAX_MSAREA_AXONE;
        }
        */
        uint32_t l_maxMsAreas = HDAT_MAX_MSAREA_P10;

        // Initialize the MS vpd class
        // TODO : RTC Story 166994 to set the maximum number of Ms Area entries
        // from new attribute
        hdatInit(l_tmpMaxMsAddr,l_tmpMaxMsAddr,l_sizeConfigured,l_maxMsAreas,
                l_mostSigAffinityDomain_x,l_ueCount,l_mirroringBaseAddress_x);

        TARGETING::ATTR_XSCOM_BASE_ADDRESS_type l_xscomAddr =
                 l_pSysTarget->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();
        assert(l_xscomAddr != 0);
        {
            hdatMsAddr_t l_hdatXscomAddr;
            l_hdatXscomAddr.hi = (l_xscomAddr & 0xFFFFFFFF00000000ull) >> 32;
            l_hdatXscomAddr.lo =  l_xscomAddr & 0x00000000FFFFFFFFull;

            l_hdatXscomAddr.hi |= HDAT_REAL_ADDRESS_MASK;

            setXSCOM(l_hdatXscomAddr);
        }

        // This contains the MS Area Index
        uint32_t l_index = 0;

        //for each proc/ memory controller in the system
        TARGETING::PredicateCTM l_procPred(TARGETING::CLASS_CHIP,
                                            TARGETING::TYPE_PROC);
        TARGETING::PredicateHwas l_predHwasPresent;
        l_predHwasPresent.present(true);
        TARGETING::PredicateHwas l_predHwasFunc;
        l_predHwasFunc.functional(true);
        TARGETING::PredicatePostfixExpr l_funcProc;
        l_funcProc.push(&l_procPred).push(&l_predHwasFunc).And();

        TARGETING::TargetRangeFilter l_procs(
                TARGETING::targetService().begin(),
                TARGETING::targetService().end(),
                &l_funcProc);

        uint32_t l_nxtSharingGroupId = 0;

        for(;l_procs;++l_procs)
        {
            bool l_smfAdded = false;

            TARGETING::Target *l_pProcTarget = *(l_procs);
            TARGETING::ATTR_ORDINAL_ID_type l_procChipId
                         = l_pProcTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();

            // TODO : RTC Story 159682
            // Further CHTM support needs to be added which contains the trace
            // array for 24 cores
            hdatMsAddr_t l_hdatNhtmStartAddr;
            hdatMsAddr_t l_hdatNhtmEndAddr;

            TARGETING::ATTR_PROC_NHTM_BAR_BASE_ADDR_type l_nhtmStartAddr =
              l_pProcTarget->getAttr<TARGETING::ATTR_PROC_NHTM_BAR_BASE_ADDR>();
            TARGETING::ATTR_PROC_NHTM_BAR_SIZE_type l_nhtmSize =
              l_pProcTarget->getAttr<TARGETING::ATTR_PROC_NHTM_BAR_SIZE>();

            if( 0 != l_nhtmSize )
            {
                l_hdatNhtmStartAddr.hi =
                              (l_nhtmStartAddr & 0xFFFFFFFF00000000ull) >> 32;
                l_hdatNhtmStartAddr.lo =
                              l_nhtmStartAddr & 0x00000000FFFFFFFFull;
                l_hdatNhtmStartAddr.hi |= HDAT_REAL_ADDRESS_MASK;

                auto l_nhtmEndAddr = l_nhtmStartAddr + l_nhtmSize;
                l_hdatNhtmEndAddr.hi =
                             (l_nhtmEndAddr & 0xFFFFFFFF00000000ull) >> 32;
                l_hdatNhtmEndAddr.lo =  l_nhtmEndAddr & 0x00000000FFFFFFFFull;
                l_hdatNhtmEndAddr.hi |= HDAT_REAL_ADDRESS_MASK;

                HDAT_INF("hdatNhtmStartAddr = 0x%08X 0x%08X ",
                        l_hdatNhtmStartAddr.hi, l_hdatNhtmStartAddr.lo);
                HDAT_INF("hdatNhtmEndAddr = 0x%08X 0x%08X ",
                        l_hdatNhtmEndAddr.hi, l_hdatNhtmEndAddr.lo);

                addIMTAddrRange(l_hdatNhtmStartAddr, l_hdatNhtmEndAddr);
            }
            else
            {
                HDAT_INF("NHTM Bar size value = 0x%016llX",
                            l_nhtmSize);
            }

            TARGETING::ATTR_PROC_MEM_BASES_type l_procMemBases = {0};
            assert(l_pProcTarget->
                    tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_procMemBases));

            TARGETING::ATTR_PROC_MIRROR_BASES_type l_MirrorAddr = {0};
            assert(l_pProcTarget->tryGetAttr<
                TARGETING::ATTR_PROC_MIRROR_BASES>(l_MirrorAddr));

            TARGETING::ATTR_PROC_MIRROR_SIZES_type l_MirrorSize = {0};
            assert(l_pProcTarget->tryGetAttr<
                TARGETING::ATTR_PROC_MIRROR_SIZES>(l_MirrorSize));

            TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM_type l_payLoadMirrorMem =
                l_pSysTarget->getAttr<TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM>();

            //TODO : RTC Story 246361 HDAT Nimbus/Cumulus model code removal
            if(l_model == TARGETING::MODEL_NIMBUS)
            {
                //Sharing count for each group
                TARGETING::ATTR_MSS_MEM_MC_IN_GROUP_type l_mcaSharingCount
                    = {0};

                //Group ID for each group, group id will be assigned only
                //if the group is shared
                TARGETING::ATTR_MSS_MEM_MC_IN_GROUP_type l_mcsSharingGrpIds
                    = {0};

                //Size configured under each group
                TARGETING::ATTR_PROC_MEM_SIZES_type l_procMemSizesBytes = {0};

                assert(l_pProcTarget->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>
                                                         (l_procMemSizesBytes));

                //For each MCA
                TARGETING::PredicateCTM l_allMca(TARGETING::CLASS_UNIT,
                                         TARGETING::TYPE_MCA);
                TARGETING::PredicateHwas l_funcMca;
                l_funcMca.functional(true);
                TARGETING::PredicatePostfixExpr l_allFuncMca;
                l_allFuncMca.push(&l_allMca).push(&l_funcMca).And();

                TARGETING::TargetHandleList l_mcaList;

                TARGETING::targetService().
                    getAssociated(l_mcaList, l_pProcTarget,
                        TARGETING::TargetService::CHILD,
                        TARGETING::TargetService::ALL, &l_allFuncMca);

                for(uint32_t l_mcaIdx = 0; l_mcaIdx<l_mcaList.size();
                    ++l_mcaIdx)
                {
                    uint32_t l_mcaInGrp = 0;
                    TARGETING::Target *l_pMcaTarget =
                             l_mcaList[l_mcaIdx];
                    if(!hdatFindGroupForMc(l_pProcTarget,
                                           l_pMcaTarget,
                                           l_mcaInGrp))
                    {
                        //Skip this MCA is not in any  group
                        continue;
                    }

                    //Increment sharing count if mem configured under group.
                    if(l_procMemSizesBytes[l_mcaInGrp] > 0)
                    {
                        l_mcaSharingCount[l_mcaInGrp]++;

                        //Assign sharing group id only if shared
                        //And only when first instance of sharing is found
                        if(l_mcaSharingCount[l_mcaInGrp] ==
                                         HDAT_MIN_NUM_FOR_SHARING)
                        {
                            l_mcsSharingGrpIds[l_mcaInGrp] =
                                    l_nxtSharingGroupId;
                            l_nxtSharingGroupId++;
                        }
                    }
                }

                TARGETING::PredicateCTM l_mcbistPredicate(TARGETING::CLASS_UNIT,
                                    TARGETING::TYPE_MCBIST);

                TARGETING::PredicatePostfixExpr l_presentMcbist;
                l_presentMcbist.push(&l_mcbistPredicate).
                         push(&l_predHwasFunc).And();

                TARGETING::TargetHandleList l_mcbistList;

                // Find Associated MCBIST list
                TARGETING::targetService().getAssociated(l_mcbistList,
                                l_pProcTarget,
                                TARGETING::TargetService::CHILD_BY_AFFINITY,
                                TARGETING::TargetService::ALL,
                                &l_presentMcbist);

                //scan all mcbist in this proc
                for(uint32_t l_mcbistIdx =0;
                             l_mcbistIdx < l_mcbistList.size();
                             ++l_mcbistIdx)
                {
                    TARGETING::Target *l_pMcbistTarget =
                        l_mcbistList[l_mcbistIdx];

                    TARGETING::PredicateCTM l_mcsPredicate(
                        TARGETING::CLASS_UNIT,
                        TARGETING::TYPE_MCS);

                    TARGETING::PredicatePostfixExpr l_funcMcs;
                    l_funcMcs.push(&l_mcsPredicate).push(&l_predHwasFunc).And();

                    TARGETING::TargetHandleList l_mcsList;

                    // Find Associated memory controllers
                    TARGETING::targetService().getAssociated(l_mcsList,
                                    l_pMcbistTarget,
                                    TARGETING::TargetService::CHILD,
                                    TARGETING::TargetService::ALL,
                                    &l_funcMcs);
                    uint32_t l_memBusFreq = getMemBusFreq(l_pMcbistTarget);

                    //scan all mcs in this proc to get sharing counit
                    for(uint32_t l_mcsIdx = 0;l_mcsIdx<l_mcsList.size();
                        ++l_mcsIdx)
                    {
                        TARGETING::Target *l_pMcsTarget = l_mcsList[l_mcsIdx];

                        //for each MCA connected to this this MCS
                        TARGETING::PredicateCTM l_mcaPredicate(
                            TARGETING::CLASS_UNIT, TARGETING::TYPE_MCA);

                        TARGETING::PredicateHwas l_predMca;
                        l_predMca.present(true);
                        TARGETING::PredicatePostfixExpr l_presentMca;
                        l_presentMca.push(&l_mcaPredicate).
                            push(&l_predMca).And();
                        TARGETING::TargetHandleList l_mcaList;

                        // Get associated MCAs
                        TARGETING::targetService().
                        getAssociated(l_mcaList, l_pMcsTarget,
                             TARGETING::TargetService::CHILD_BY_AFFINITY,
                             TARGETING::TargetService::ALL, &l_presentMca);


                        for(uint32_t l_mcaIdx = 0; l_mcaIdx<l_mcaList.size();
                            ++l_mcaIdx)
                        {
                            TARGETING::Target *l_pMcaTarget =
                                l_mcaList[l_mcaIdx];

                            //Group which this MCA is belonging
                            uint32_t l_mcaInGrp = 0;

                            if(!hdatFindGroupForMc(l_pProcTarget,
                                                   l_pMcaTarget,
                                                   l_mcaInGrp))
                            {
                                HDAT_INF("No group found for MCA");
                                //Skip this MCS is not under any group
                                continue;
                            }
                            uint32_t l_mcaFruId = 0;
                            hdatMemParentType l_parentType =
                                HDAT_MEM_PARENT_CEC_FRU;

                            std::list<hdatRamArea> l_areas;
                            l_areas.clear();
                            uint32_t  l_areaSizeInMB = 0;
                            bool      l_areaFunctional = false;
                            uint32_t  l_numDimms =0;

                            l_err = hdatScanDimms(l_pMcaTarget,
                                                  l_pMcsTarget,
                                                  l_mcaFruId,
                                                  l_areas,
                                                  l_areaSizeInMB,
                                                  l_numDimms,
                                                  l_areaFunctional,
                                                  l_parentType);

                            if(NULL != l_err)
                            {
                                HDAT_ERR("Error in calling Scan Dimms");
                                break;
                            }

                            HDAT_INF("l_areaSizeInMB:0x%.8X l_numDimms:0x%.8X "
                                "l_areas.size():0x%.8X", l_areaSizeInMB,
                                l_numDimms, l_areas.size());

                            //Skip if no memory configured under this MCS
                            if(l_areaSizeInMB == 0)
                            {
                                continue;
                            }

                            uint32_t l_maxMemBlocks = 0;
                            l_err =
                            hdatGetMaxMemoryBlocks(l_pMcsTarget,l_maxMemBlocks);
                            if(NULL != l_err)
                            {
                                HDAT_ERR("Error error in get max blocks");
                                break;
                            }

                            TARGETING::ATTR_SLCA_RID_type l_procRid =
                            l_pProcTarget->getAttr<TARGETING::ATTR_SLCA_RID>();

                            TARGETING::ATTR_SLCA_INDEX_type l_procSlcaIndex =
                                l_pProcTarget->getAttr
                                <TARGETING::ATTR_SLCA_INDEX>();

                            l_err = addMsAreaFru(l_procRid,
                                                 l_procSlcaIndex,
                                                 l_pProcTarget,
                                                 l_index,
                                                 l_numDimms,
                                                 MAX_CHIP_EC_CNT_PER_MSAREA,
                                                 l_maxMemBlocks);

                            if(NULL != l_err)
                            {
                                HDAT_ERR("Error adding MSArea %d"
                                         "Number of Dimms: %d Max Blocks: %d",
                                         l_index,
                                         l_numDimms,l_maxMemBlocks);
                                break;
                            }

                            uint32_t l_memStatus = 0;
                            //If group is shared with more than one area
                            if(l_mcaSharingCount[l_mcaInGrp] >=
                                                    HDAT_MIN_NUM_FOR_SHARING)
                            {
                                l_memStatus = HDAT_MEM_SHARED;
                                setMsAreaInterleavedId(l_index,
                                    l_mcsSharingGrpIds[l_mcaInGrp]);
                            }

                            setMsAreaType(l_index,l_parentType);
                            setMsAreaSize(l_index,l_areaSizeInMB);

                            iv_maxSize.hdatTotSize += l_areaSizeInMB;

                            l_memStatus |= l_areaFunctional ?
                             (HDAT_MEM_INSTALLED | HDAT_MEM_FUNCTIONAL) :
                              HDAT_MEM_INSTALLED;

                            setMsAreaStat(l_index, l_memStatus);

                            //Add MCS ec level
                            uint32_t l_mcsEcLevel = 0;
                            uint32_t l_mcsChipId = 0;
                            l_err = hdatGetIdEc(l_pMcsTarget,
                                                l_mcsEcLevel,
                                                l_mcsChipId);
                            if(NULL != l_err)
                            {
                                HDAT_ERR("Error in getting MCS ID "
                                 "and EC HUID:[0x%08X]",
                                 l_pMcsTarget->getAttr<TARGETING::ATTR_HUID>());
                                break;
                            }

                            l_err = addEcEntry(l_index,
                                               l_mcsChipId,
                                               l_mcsEcLevel);
                            if(NULL != l_err)
                            {
                                HDAT_ERR("Error in adding"
                                 " ID[0x%08X] and EC[0x%08X] to ms area"
                                 " HUID:[0x%08X]",l_mcsChipId,
                                 l_mcsEcLevel,
                                 l_pMcsTarget->getAttr<TARGETING::ATTR_HUID>());
                                break;
                            }

                            TARGETING::PredicateCTM l_membufPredicate(
                                TARGETING::CLASS_CHIP, TARGETING::TYPE_MEMBUF);

                            TARGETING::PredicatePostfixExpr l_presentMemBuf;
                            l_presentMemBuf.push(&l_membufPredicate).
                                          push(&l_predHwasPresent).And();

                            TARGETING::TargetHandleList l_membufList;

                            // Find Associated membuf
                            TARGETING::targetService().getAssociated(
                                l_membufList,
                                l_pMcsTarget,
                                TARGETING::TargetService::CHILD_BY_AFFINITY,
                                TARGETING::TargetService::ALL,
                                &l_presentMemBuf);

                            std::list<hdatRamArea>::iterator l_area =
                                l_areas.begin();

                            for (uint32_t l_ramId = 0;
                                 l_area != l_areas.end();
                                 ++l_ramId, ++l_area)
                            {
                                uint32_t l_status = (l_area)->ivFunctional ?
                                      (HDAT_RAM_INSTALLED | HDAT_RAM_FUNCTIONAL)
                                      : HDAT_RAM_INSTALLED;

                                TARGETING::Target *l_pDimmTarget =
                                TARGETING::Target::getTargetFromHuid(
                                    l_area->ivHuid);

                                TARGETING::ATTR_SLCA_RID_type l_dimmRid =
                                    l_pDimmTarget->getAttr
                                    <TARGETING::ATTR_SLCA_RID>();

                                TARGETING::ATTR_SLCA_INDEX_type l_dimmSlcaIndex=
                                    l_pDimmTarget->getAttr
                                    <TARGETING::ATTR_SLCA_INDEX>();

                                uint32_t l_dimmId =
                                1 << (31 - (l_pDimmTarget->getAttr
                                    <TARGETING::ATTR_FAPI_POS>() %
                                    MAX_DIMMS_PER_MCBIST));
                                l_err = addRamFru(l_index,
                                                  l_pDimmTarget,
                                                  l_dimmRid,
                                                  l_dimmSlcaIndex,
                                                  l_ramId,
                                                  l_status,
                                                  (l_area)->ivSize,
                                                  l_dimmId,
                                                  l_memBusFreq);

                                if (l_err) // Failed to add ram fru information
                                {
                                    HDAT_ERR("Error in adding RAM FRU"
                                    "Index:%d Rid:[0x%08X] status:[0x%08X]"
                                    "Size:[0x%08X] RamID:[0x%08X]",
                                    l_index,(l_area)->ivHuid,
                                    l_status,(l_area)->ivSize,l_ramId);
                                    ERRORLOG::errlCommit(l_err,HDAT_COMP_ID);

                                    delete l_err;
                                    l_err = NULL;
                                    continue;
                                }
                            }//end of RAM list

                            l_addr_range.hi = (l_procMemBases[l_mcaInGrp] &
                                           0xFFFFFFFF00000000ull) >> 32;
                            l_addr_range.lo =  l_procMemBases[l_mcaInGrp] &
                                           0x00000000FFFFFFFFull;

                            l_end = l_addr_range;

                            //Update the range
                            l_end.hi += (l_procMemSizesBytes[l_mcaInGrp] &
                                       0xFFFFFFFF00000000ull) >> 32;
                            l_end.lo += l_procMemSizesBytes[l_mcaInGrp] &
                                       0x00000000FFFFFFFFull;

                            HDAT_INF("MCS:0x%08X l_addr_range:0x%08X 0x%08X"
                             " l_end:0x%08X 0x%08X",
                             l_pMcsTarget->getAttr<TARGETING::ATTR_HUID>(),
                             l_addr_range.hi, l_addr_range.lo,
                             l_end.hi,l_end.lo);

                            uint64_t l_hdatMirrorAddr_x = 0x0ull;
                            uint64_t l_hdatMirrorAddr = 0x0ull;
                            uint32_t l_hdatMemcntrlID = 0x0 ;
                            uint8_t l_hdatMirrorAlogrithm = 0xFF;
                            bool l_rangeIsMirrorable = false;

                            //Calculate the mirror address and related data
                            uint64_t l_startAddr =
                                       (((uint64_t)(l_addr_range.hi) << 32 )
                                       | (uint64_t)(l_addr_range.lo));
                            l_hdatMirrorAddr_x =
                                (l_startAddr / 2) + l_mirrorBaseAddress_x;

                            HDAT_INF(
                            "Start add : 0x%016llX MirrorBase : 0x%016llX"
                            " MirrorAddr : 0x%016llX PayLoadMirrorMem : 0x%X",
                            l_startAddr, l_mirrorBaseAddress_x,
                            l_hdatMirrorAddr_x, l_payLoadMirrorMem);

                            if ( 0 != l_payLoadMirrorMem )
                            {
                                for ( int idx=0 ; idx <
                                (int)
                                (sizeof(TARGETING::ATTR_PROC_MIRROR_SIZES_type)
                                / sizeof(uint64_t)) ; idx++ )
                                {
                                    HDAT_INF("Mirror size : 0x%016llX"
                                       " MirrorAddr : 0x%016llX"
                                       " hdatMirrorAddr_x : 0x%016llX",
                                       l_MirrorSize[idx], l_MirrorAddr[idx],
                                       l_hdatMirrorAddr_x);

                                    if( (0 != l_MirrorSize[idx]) &&
                                    (l_MirrorAddr[idx] == l_hdatMirrorAddr_x) )
                                    {
                                        l_rangeIsMirrorable = true;
                                        l_hdatMirrorAddr = l_MirrorAddr[idx]
                                               | HDAT_REAL_ADDRESS_MASK64;
                                        break;
                                    }
                                }
                            }

                            // Set the memory controller ID
                            l_hdatMemcntrlID |=
                                1 << (31 - l_pMcbistTarget->getAttr
                                <TARGETING::ATTR_CHIP_UNIT>());
                            l_hdatMemcntrlID |=
                                1 << (31 - (l_pMcsTarget->getAttr
                                <TARGETING::ATTR_CHIP_UNIT>() + 4));
                            l_hdatMemcntrlID |=
                                1 << (31 - (l_pMcaTarget->getAttr
                                <TARGETING::ATTR_CHIP_UNIT>() + 8));

                            l_err = addMsAreaAddr(l_index,
                                                  l_addr_range,
                                                  l_end,
                                                  l_procChipId,
                                                  l_rangeIsMirrorable,
                                                  l_hdatMirrorAlogrithm,
                                                  l_hdatMirrorAddr,
                                                  l_hdatMemcntrlID);
                            if(NULL != l_err)
                            {
                                HDAT_ERR("Error in adding addMsAreaAddr"
                                   " to ms area index[%d]",
                                   l_index);
                                break;
                            }

                            // TODO : RTC Story 159682
                            // Further CHTM support needs to be added which
                            // contains the trace array for 24 cores
                            // Reinitializing the NHTM size

                            // Don't re-init NHTM size -- only one HTM region
                            // per proc
                            uint64_t l_end_hi = l_end.hi;
                            uint64_t l_end_lo = l_end.lo;
                            uint64_t l_end_addr =
                                ((l_end_hi << 32 ) | l_end_lo);


                            uint64_t l_addr_range_hi = l_addr_range.hi;
                            uint64_t l_addr_range_lo = l_addr_range.lo;
                            uint64_t l_start_addr =
                                ((l_addr_range_hi << 32 )| l_addr_range_lo);

                            uint64_t l_size_bytes = ((uint64_t)l_areaSizeInMB) *
                                 l_mcaSharingCount[l_mcaInGrp] * 1024 * 1024;

                            if((0 != l_nhtmSize) &&
                                  (l_size_bytes != (l_end_addr - l_start_addr)))
                            {
                                HDAT_INF("NHTM Bar size = 0x%016llX "
                                         " MS area size = 0x%016llX"
                                         " l_end_addr = 0x%016llX"
                                         " l_start_addr = 0x%016llX",
                                         l_nhtmSize,l_size_bytes, l_end_addr,
                                         l_start_addr);

                                l_addr_range.lo = l_hdatNhtmStartAddr.lo;
                                l_addr_range.hi = l_hdatNhtmStartAddr.hi;

                                l_end.lo = l_hdatNhtmEndAddr.lo;
                                l_end.hi = l_hdatNhtmEndAddr.hi;

                                l_err = addMsAreaAddr(l_index,
                                                      l_addr_range,
                                                      l_end,
                                                      l_procChipId,
                                                      false, 0, 0);
                                if(NULL != l_err)
                                {
                                    HDAT_ERR("Error in adding "
                                         " addMsAreaAddr to ms area index[%d]",
                                         l_index);
                                    break;
                                }
                                l_nhtmSize=0; //only add 1 entry
                            }
                            l_addr_range = l_end;

                            auto l_smfStartAddr = l_pProcTarget->
                              getAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>();
                            auto l_smfSize = l_pProcTarget->
                                getAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>();

                            if(l_smfSize && !l_smfAdded)
                            {
                                hdatMsAddr_t l_hdatSmfStartAddr{};
                                hdatMsAddr_t l_hdatSmfEndAddr{};
                                l_hdatSmfStartAddr.hi =
                                 (l_smfStartAddr & 0xFFFFFFFF00000000ull) >> 32;
                                l_hdatSmfStartAddr.lo =
                                    l_smfStartAddr & 0x00000000FFFFFFFFull;
                                l_hdatSmfStartAddr.hi |= HDAT_REAL_ADDRESS_MASK;

                                l_hdatSmfEndAddr.hi =
                                    ((l_smfStartAddr + l_smfSize) &
                                    0xFFFFFFFF00000000ull) >>32;
                                l_hdatSmfEndAddr.lo =
                                    (l_smfStartAddr + l_smfSize) &
                                    0x00000000FFFFFFFFull;
                                l_hdatSmfEndAddr.hi |= HDAT_REAL_ADDRESS_MASK;

                                l_err = addMsAreaAddr(l_index,
                                                      l_hdatSmfStartAddr,
                                                      l_hdatSmfEndAddr,
                                                      l_procChipId,
                                                      false, //rangeIsMirrorable
                                                      0, // i_mirroringAlgorithm
                                                      0, // i_startMirrAddr
                                                      l_hdatMemcntrlID,
                                                      true); // i_hdatsmf
                                l_smfAdded = true;
                            }

                            if(l_err)
                            {
                                HDAT_ERR("Could not add SMF memory range to "
                                         "HDAT at index[%d]", l_index);
                                break;
                            }
                            else
                            {
                                HDAT_INF("Added SMF memory range to HDAT at "
                                        "index[%d]; start addr: 0x%08x; end addr: 0x%08x"
                                        "; size: 0x%08x",
                                        l_smfStartAddr,
                                        l_smfStartAddr + l_smfSize,
                                        l_smfSize);
                            }

                            l_index++;
                        } //end of mca list
                        if(l_err)
                        {
                            break;
                        }
                    } //end of MCS list
                    if(l_err)
                    {
                        break;
                    }
                } //end of MCBIST list
            }
            else //if model is P10
            {
                //Sharing count for each group
                TARGETING::ATTR_MSS_MEM_MC_IN_GROUP_type l_mccSharingCount
                    = {0};

                //Group ID for each group, group id will be assigned only
                //if the group is shared
                TARGETING::ATTR_MSS_MEM_MC_IN_GROUP_type l_mccSharingGrpIds =
                    {0};

                //Size configured under each group
                TARGETING::ATTR_PROC_MEM_SIZES_type l_procMemSizesBytes = {0};

                assert(l_pProcTarget->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>
                                                         (l_procMemSizesBytes));

                //For each MCC
                TARGETING::PredicateCTM l_allMcc(TARGETING::CLASS_UNIT,
                                         TARGETING::TYPE_MCC);
                TARGETING::PredicateHwas l_funcMcc;
                l_funcMcc.functional(true);
                TARGETING::PredicatePostfixExpr l_allFuncMcc;
                l_allFuncMcc.push(&l_allMcc).push(&l_funcMcc).And();

                TARGETING::TargetHandleList l_mccList;

                TARGETING::targetService().
                    getAssociated(l_mccList, l_pProcTarget,
                        TARGETING::TargetService::CHILD,
                        TARGETING::TargetService::ALL, &l_allFuncMcc);

                for(uint32_t l_mccIdx = 0; l_mccIdx<l_mccList.size();
                    ++l_mccIdx)
                {
                    uint32_t l_mccInGrp = 0;

                    TARGETING::Target *l_pMccTarget =
                             l_mccList[l_mccIdx];
                    if(!hdatFindGroupForMcc(l_pProcTarget,
                                            l_pMccTarget,
                                            l_mccInGrp))
                    {
                        //Skip this MCC is not in any  group
                        continue;
                    }

                    HDAT_INF("hdatFindGroupForMcc returned group: %d, "
                        "procmemsizes[%d]: 0X%x",
                        l_mccInGrp,l_mccInGrp,
                        l_procMemSizesBytes[l_mccInGrp]);

                    //Increment sharing count if mem configured under group.
                    if(l_procMemSizesBytes[l_mccInGrp] > 0)
                    {
                        l_mccSharingCount[l_mccInGrp]++;

                        //Assign sharing group id only if shared
                        //And only when first instance of sharing is found
                        if(l_mccSharingCount[l_mccInGrp] ==
                            HDAT_MIN_NUM_FOR_SHARING)
                        {
                            l_mccSharingGrpIds[l_mccInGrp] =
                                l_nxtSharingGroupId;
                            l_nxtSharingGroupId++;
                        }
                    }
                }

                TARGETING::PredicateCTM l_mcPredicate(TARGETING::CLASS_UNIT,
                                    TARGETING::TYPE_MC);

                TARGETING::PredicatePostfixExpr l_presentMc;
                l_presentMc.push(&l_mcPredicate).
                         push(&l_predHwasFunc).And();

                TARGETING::TargetHandleList l_mcList;

                // Find Associated MC list
                TARGETING::targetService().getAssociated(l_mcList,
                                l_pProcTarget,
                                TARGETING::TargetService::CHILD_BY_AFFINITY,
                                TARGETING::TargetService::ALL,
                                &l_presentMc);

                //scan all mc in this proc
                for(uint32_t l_mcIdx =0;
                             l_mcIdx < l_mcList.size();
                             ++l_mcIdx)
                {
                    TARGETING::Target *l_pMcTarget = l_mcList[l_mcIdx];

                    TARGETING::PredicateCTM l_miPredicate(
                        TARGETING::CLASS_UNIT,
                        TARGETING::TYPE_MI);

                    TARGETING::PredicatePostfixExpr l_funcMi;
                    l_funcMi.push(&l_miPredicate).push(&l_predHwasFunc).And();

                    TARGETING::TargetHandleList l_miList;

                    // Find Associated mi list
                    TARGETING::targetService().getAssociated(l_miList,
                                    l_pMcTarget,
                                    TARGETING::TargetService::CHILD,
                                    TARGETING::TargetService::ALL,
                                    &l_funcMi);

                    //for each MI connected to this this MC
                    for(uint32_t l_miIdx = 0;l_miIdx<l_miList.size();
                        ++l_miIdx)
                    {
                        TARGETING::Target *l_pMiTarget = l_miList[l_miIdx];

                        //for each MCC connected to this this MI
                        TARGETING::PredicateCTM l_mccPredicate(
                            TARGETING::CLASS_UNIT, TARGETING::TYPE_MCC);

                        TARGETING::PredicateHwas l_predMcc;
                        l_predMcc.present(true);
                        TARGETING::PredicatePostfixExpr l_presentMcc;
                        l_presentMcc.push(&l_mccPredicate).
                            push(&l_predMcc).And();
                        TARGETING::TargetHandleList l_mccList;

                        // Get associated MCCs
                        TARGETING::targetService().
                        getAssociated(l_mccList, l_pMiTarget,
                             TARGETING::TargetService::CHILD_BY_AFFINITY,
                             TARGETING::TargetService::ALL, &l_presentMcc);

                        for(uint32_t l_mccIdx = 0; l_mccIdx<l_mccList.size();
                            ++l_mccIdx)
                        {
                            TARGETING::Target *l_pMccTarget =
                                l_mccList[l_mccIdx];

                            //Group which this MCC is belonging
                            uint32_t l_mccInGrp = 0;

                            if(!hdatFindGroupForMcc(l_pProcTarget,
                                                    l_pMccTarget,
                                                    l_mccInGrp))
                            {
                                HDAT_INF("No group found for MCC");
                                //Skip this MCC as it is not under any group
                                continue;
                            }

                            //for each OMI connected to this this MCC
                            TARGETING::PredicateCTM l_omiPredicate(
                                TARGETING::CLASS_UNIT, TARGETING::TYPE_OMI);

                            TARGETING::PredicateHwas l_predOmi;
                            l_predOmi.present(true);
                            TARGETING::PredicatePostfixExpr l_presentOmi;
                            l_presentOmi.push(&l_omiPredicate).
                                push(&l_predOmi).And();
                            TARGETING::TargetHandleList l_omiList;

                            // Get associated OMIs
                            TARGETING::targetService().
                            getAssociated(l_omiList, l_pMccTarget,
                                 TARGETING::TargetService::CHILD_BY_AFFINITY,
                                 TARGETING::TargetService::ALL, &l_presentOmi);

                            for(uint32_t l_omiIdx = 0;
                               l_omiIdx<l_omiList.size();
                               ++l_omiIdx)
                            {
                                TARGETING::Target *l_pOmiTarget =
                                    l_omiList[l_omiIdx];

                                //for each OCMB CHIP connected to this this OMI
                                TARGETING::PredicateCTM l_ocmbPredicate(
                                    TARGETING::CLASS_CHIP,
                                    TARGETING::TYPE_OCMB_CHIP);

                                TARGETING::PredicateHwas l_predOcmb;
                                l_predOcmb.present(true);
                                TARGETING::PredicatePostfixExpr l_presentOcmb;
                                l_presentOcmb.push(&l_ocmbPredicate).
                                    push(&l_predOcmb).And();
                                TARGETING::TargetHandleList l_ocmbList;

                                // Get associated OCMB CHIP's
                                TARGETING::targetService().
                                getAssociated(l_ocmbList, l_pOmiTarget,
                                TARGETING::TargetService::CHILD_BY_AFFINITY,
                                TARGETING::TargetService::ALL, &l_presentOcmb);

                                for(uint32_t l_ocmbIdx = 0;
                                    l_ocmbIdx<l_ocmbList.size();
                                    ++l_ocmbIdx)
                                {
                                    TARGETING::Target *l_pOcmbTarget =
                                        l_ocmbList[l_ocmbIdx];

                                    // Swift uses a DDIMM. It is a single FRU
                                    // that includes 1 OCMB chip and some dram
                                    hdatMemParentType l_parentType =
                                        HDAT_MEM_PARENT_RISER;

                                    std::list<hdatRamArea> l_areas;
                                    l_areas.clear();
                                    uint32_t  l_areaSizeInMB = 0;
                                    bool      l_areaFunctional = false;
                                    uint32_t  l_numDimms =0;

                                    l_err = hdatScanDimmsP10(l_pOcmbTarget,
                                                             l_areas,
                                                             l_areaSizeInMB,
                                                             l_numDimms,
                                                             l_areaFunctional,
                                                             l_parentType);
                                    if(NULL != l_err)
                                    {
                                        HDAT_ERR("Error in calling Scan Dimms");
                                        break;
                                    }

                                    HDAT_INF("l_areaSizeInMB:0x%.8X "
                                        "l_numDimms:0x%.8X "
                                        "l_areas.size():0x%.8X", l_areaSizeInMB,
                                        l_numDimms, l_areas.size());

                                    // Skip if no memory configured under
                                    // OCMB_CHIP
                                    if(l_areaSizeInMB == 0)
                                    {
                                        continue;
                                    }

                                    uint32_t l_maxMemBlocks = 0;
                                    l_err = hdatGetMaxMemoryBlocks
                                        (l_pOcmbTarget,l_maxMemBlocks);
                                    if(NULL != l_err)
                                    {
                                        HDAT_ERR("Error to get max blocks");
                                        break;
                                    }

                                    TARGETING::ATTR_SLCA_RID_type l_procRid =
                                        l_pProcTarget->getAttr
                                        <TARGETING::ATTR_SLCA_RID>();

                                    TARGETING::ATTR_SLCA_INDEX_type
                                        l_procSlcaIndex = l_pProcTarget->getAttr
                                        <TARGETING::ATTR_SLCA_INDEX>();

                                    l_err = addMsAreaFru(l_procRid,
                                                     l_procSlcaIndex,
                                                     l_pOcmbTarget,
                                                     l_index,
                                                     l_numDimms,
                                                     MAX_CHIP_EC_CNT_PER_MSAREA,
                                                     l_maxMemBlocks);

                                    if(NULL != l_err)
                                    {
                                        HDAT_ERR("Error adding MSArea %d"
                                            "Number of Dimms: %d "
                                            "Max Blocks: %d",
                                            l_index,
                                            l_numDimms,l_maxMemBlocks);
                                        break;
                                    }

                                    uint32_t l_memStatus = 0;

                                    //If group is shared with more than one area
                                    if(l_mccSharingCount[l_mccInGrp] >=
                                                    HDAT_MIN_NUM_FOR_SHARING)
                                    {
                                        l_memStatus = HDAT_MEM_SHARED;
                                        setMsAreaInterleavedId(l_index,
                                            l_mccSharingGrpIds[l_mccInGrp]);
                                    }
                                    //The memory channel is defined as a single
                                    // MCC, and all of the memory on that
                                    // channel is part of a single address
                                    // space.  That means that both OCMBs on
                                    // the same MCC share an address space.
                                    // While this isn't the same mechanism as
                                    // true interleaving, it looks the same to
                                    // the code consuming HDAT, so we need to
                                    // set the sharing flags appropriately.
                                    else if( l_omiList.size() > 1 )
                                    {
                                        l_memStatus = HDAT_MEM_SHARED;
                                        setMsAreaInterleavedId(l_index,
                                            l_mccSharingGrpIds[l_mccInGrp]);
                                    }

                                    setMsAreaType(l_index,l_parentType);
                                    setMsAreaSize(l_index,l_areaSizeInMB);

                                    iv_maxSize.hdatTotSize += l_areaSizeInMB;

                                    l_memStatus |= l_areaFunctional ?
                                        (HDAT_MEM_INSTALLED |
                                         HDAT_MEM_FUNCTIONAL) :
                                         HDAT_MEM_INSTALLED;

                                    setMsAreaStat(l_index, l_memStatus);

                                    //Add OMI ec level
                                    uint32_t l_omiEcLevel = 0;
                                    uint32_t l_omiChipId = 0;
                                    l_err = hdatGetIdEc(l_pOmiTarget,
                                                        l_omiEcLevel,
                                                        l_omiChipId);
                                    if(NULL != l_err)
                                    {
                                         HDAT_ERR("Error in getting OMI ID "
                                         "and EC HUID:[0x%08X]",
                                         l_pOmiTarget->getAttr
                                         <TARGETING::ATTR_HUID>());
                                         break;
                                    }

                                    l_err = addEcEntry(l_index,
                                                       l_omiChipId,
                                                       l_omiEcLevel);
                                    if(NULL != l_err)
                                    {
                                        HDAT_ERR("Error in adding"
                                            " ID[0x%08X] and "
                                            "EC[0x%08X] to ms area"
                                            " HUID:[0x%08X]",l_omiChipId,
                                            l_omiEcLevel,
                                            l_pOmiTarget->getAttr
                                            <TARGETING::ATTR_HUID>());
                                       break;
                                    }

                                    //for each mem-port connected to this this
                                    //ocmb_chip
                                    TARGETING::PredicateCTM l_allMemPort(
                                       TARGETING::CLASS_UNIT,
                                       TARGETING::TYPE_MEM_PORT);
                                    TARGETING::PredicateHwas l_funcMemPort;
                                    l_funcMemPort.functional(true);
                                    TARGETING::PredicatePostfixExpr
                                        l_allFuncMemPort;
                                    l_allFuncMemPort.push(&l_allMemPort).
                                    push(&l_funcMemPort).And();

                                    TARGETING::TargetHandleList l_memPortList;

                                    TARGETING::targetService().
                                      getAssociated(l_memPortList,
                                      l_pOcmbTarget,
                                      TARGETING::TargetService::CHILD,
                                      TARGETING::TargetService::ALL,
                                      &l_allFuncMemPort);

                                    TARGETING::Target *l_pmemPortTarget;

                                    l_pmemPortTarget = l_memPortList[0];

                                    uint32_t l_memBusFreq = 0;
                                    l_memBusFreq =
                                        getMemBusFreqP10(l_pmemPortTarget);

                                    std::list<hdatRamArea>::iterator l_area =
                                    l_areas.begin();

                                    for (uint32_t l_ramId = 0;
                                         l_area != l_areas.end();
                                         ++l_ramId, ++l_area)
                                    {
                                        uint32_t l_status =
                                            (l_area)->ivFunctional ?
                                            (HDAT_RAM_INSTALLED |
                                            HDAT_RAM_FUNCTIONAL)
                                            : HDAT_RAM_INSTALLED;

                                        TARGETING::Target *l_pDimmTarget =
                                        TARGETING::Target::getTargetFromHuid(
                                        l_area->ivHuid);

                                        TARGETING::ATTR_SLCA_RID_type l_dimmRid
                                            = 0;
                                        TARGETING::ATTR_SLCA_INDEX_type
                                            l_dimmSlcaIndex = 0;
                                        l_dimmRid
                                            = l_pDimmTarget->getAttr
                                            <TARGETING::ATTR_SLCA_RID>();

                                        l_dimmSlcaIndex =
                                            l_pDimmTarget->getAttr
                                            <TARGETING::ATTR_SLCA_INDEX>();

                                        uint32_t l_dimmId = 0;
                                        l_dimmId |=
                                            1 << (31 - l_pOmiTarget->getAttr
                                            <TARGETING::ATTR_CHIP_UNIT>());
                                        l_dimmId |=
                                           1 << (31 - (l_pmemPortTarget->getAttr
                                           <TARGETING::ATTR_CHIP_UNIT>()+16));
                                        l_dimmId |=
                                            1 << (31 - (l_pDimmTarget->getAttr
                                            <TARGETING::ATTR_REL_POS>()+20));

                                        l_err = addRamFru(l_index,
                                                          l_pDimmTarget,
                                                          l_dimmRid,
                                                          l_dimmSlcaIndex,
                                                          l_ramId,
                                                          l_status,
                                                          (l_area)->ivSize,
                                                          l_dimmId,
                                                          l_memBusFreq);

                                        if (l_err) // Failed to add ram fru
                                        {
                                            HDAT_ERR("Error in adding RAM FRU"
                                                "Index:%d Rid:[0x%08X] "
                                                "status:[0x%08X]"
                                                "Size:[0x%08X] RamID:[0x%08X]",
                                                l_index,(l_area)->ivHuid,
                                                l_status,(l_area)->ivSize,
                                                l_ramId);
                                            ERRORLOG::errlCommit(l_err,
                                                                 HDAT_COMP_ID);

                                            delete l_err;
                                            l_err = NULL;
                                            continue;
                                        }
                                    }//end of RAM list

                                    l_addr_range.hi =
                                        (l_procMemBases[l_mccInGrp] &
                                         0xFFFFFFFF00000000ull) >> 32;
                                    l_addr_range.lo =
                                        l_procMemBases[l_mccInGrp] &
                                        0x00000000FFFFFFFFull;

                                    l_end = l_addr_range;

                                    //Update the range
                                    l_end.hi +=
                                        (l_procMemSizesBytes[l_mccInGrp] &
                                        0xFFFFFFFF00000000ull) >> 32;
                                    l_end.lo +=
                                        l_procMemSizesBytes[l_mccInGrp] &
                                        0x00000000FFFFFFFFull;

                                    HDAT_INF("MI:0x%08X l_addr_range:0x%08X "
                                        "0x%08X"
                                        " l_end:0x%08X 0x%08X",
                                        l_pMiTarget->getAttr
                                        <TARGETING::ATTR_HUID>(),
                                        l_addr_range.hi, l_addr_range.lo,
                                        l_end.hi,l_end.lo);

                                    uint64_t l_hdatMirrorAddr_x = 0x0ull;
                                    uint64_t l_hdatMirrorAddr = 0x0ull;
                                    uint32_t l_hdatMemcntrlID = 0x0 ;
                                    uint8_t l_hdatMirrorAlogrithm = 0xA;
                                    bool l_rangeIsMirrorable = false;

                                    if ( 0 != l_payLoadMirrorMem )
                                    {
                                        if( 0 != l_MirrorSize[l_mccInGrp])
                                        {
                                            l_hdatMirrorAddr =
                                                l_MirrorAddr[l_mccInGrp] |
                                                HDAT_REAL_ADDRESS_MASK64;
                                            l_rangeIsMirrorable = true;
                                        }
                                        else
                                        {
                                            l_rangeIsMirrorable = false;
                                        }
                                    }

                                    HDAT_INF(
                                        "MirrorBase : 0x%016llX"
                                        " MirrorAddr : 0x%016llX"
                                        " PayLoadMirrorMem : 0x%X",
                                        l_mirrorBaseAddress_x,
                                        l_hdatMirrorAddr_x, l_payLoadMirrorMem);

                                    // Set the memory controller ID
                                    l_hdatMemcntrlID |=
                                        1 << (31 - l_pMcTarget->getAttr
                                        <TARGETING::ATTR_CHIP_UNIT>());
                                    l_hdatMemcntrlID |=
                                        1 << (31 - (l_pMiTarget->getAttr
                                        <TARGETING::ATTR_CHIP_UNIT>() + 4));
                                    l_hdatMemcntrlID |=
                                        1 << (31 - (l_pMccTarget->getAttr
                                        <TARGETING::ATTR_CHIP_UNIT>() + 8));
                                    l_hdatMemcntrlID |=
                                        1 << (31 - (l_pOmiTarget->getAttr
                                        <TARGETING::ATTR_CHIP_UNIT>() + 16));

                                    l_err = addMsAreaAddr(l_index,
                                                          l_addr_range,
                                                          l_end,
                                                          l_procChipId,
                                                          l_rangeIsMirrorable,
                                                          l_hdatMirrorAlogrithm,
                                                          l_hdatMirrorAddr,
                                                          l_hdatMemcntrlID);
                                    if(NULL != l_err)
                                    {
                                        HDAT_ERR("Error in adding addMsAreaAddr"
                                        " to ms area index[%d]",
                                        l_index);
                                        break;
                                    }
                                    else
                                    {
                                        /* Update the Mirrorable Memory Starting
                                         * Address in MSVPD here
                                         */
                                        if( (l_origMirroringBaseAddress >
                                             l_hdatMirrorAddr) &&
                                            l_rangeIsMirrorable == true)
                                        {
                                            l_origMirroringBaseAddress =
                                                l_hdatMirrorAddr;
                                            setMirrorableMemoryStartAddress(
                                                l_hdatMirrorAddr);
                                        }
                                    }

                                    // TODO : RTC Story 159682
                                    // Further CHTM support needs to be added
                                    // which contains the trace array for
                                    // 24 cores
                                    // Reinitializing the NHTM size

                                    // Don't re-init NHTM size -- only one HTM
                                    // region per proc
                                    uint64_t l_end_hi = l_end.hi;
                                    uint64_t l_end_lo = l_end.lo;
                                    uint64_t l_end_addr =
                                    ((l_end_hi << 32 ) | l_end_lo);


                                    uint64_t l_addr_range_hi = l_addr_range.hi;
                                    uint64_t l_addr_range_lo = l_addr_range.lo;
                                    uint64_t l_start_addr =
                                    ((l_addr_range_hi << 32 )| l_addr_range_lo);

                                    uint64_t l_size_bytes =
                                    ((uint64_t)l_areaSizeInMB) *
                                    l_mccSharingCount[l_mccInGrp] * 1024 * 1024;

                                    if((0 != l_nhtmSize) &&
                                       (l_size_bytes !=
                                        (l_end_addr - l_start_addr)))
                                    {
                                        HDAT_INF("NHTM Bar size = 0x%016llX "
                                                 " MS area size = 0x%016llX"
                                                 " l_end_addr = 0x%016llX"
                                                 " l_start_addr = 0x%016llX",
                                                 l_nhtmSize,l_size_bytes,
                                                 l_end_addr,
                                                 l_start_addr);

                                        l_addr_range.lo =
                                            l_hdatNhtmStartAddr.lo;
                                        l_addr_range.hi =
                                            l_hdatNhtmStartAddr.hi;

                                        l_end.lo = l_hdatNhtmEndAddr.lo;
                                        l_end.hi = l_hdatNhtmEndAddr.hi;

                                        l_err = addMsAreaAddr(l_index,
                                                              l_addr_range,
                                                              l_end,
                                                              l_procChipId,
                                                              false, 0, 0);
                                        if(NULL != l_err)
                                        {
                                            HDAT_ERR("Error in adding "
                                                " addMsAreaAddr to ms area "
                                                "index[%d]",
                                                l_index);
                                            break;
                                        }
                                        l_nhtmSize=0; //only add 1 entry
                                    }
                                    l_addr_range = l_end;

                                    // Add SMF memory addr range
                                    auto l_smfStartAddr = l_pProcTarget->
                                        getAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>();
                                    auto l_smfSize = l_pProcTarget->
                                        getAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>();

                                    if(l_smfSize && !l_smfAdded)
                                    {
                                        hdatMsAddr_t l_hdatSmfStartAddr{};
                                        hdatMsAddr_t l_hdatSmfEndAddr{};
                                        l_hdatSmfStartAddr.hi =
                                            (l_smfStartAddr & 0xFFFFFFFF00000000ull) >> 32;
                                        l_hdatSmfStartAddr.lo =
                                            l_smfStartAddr & 0x00000000FFFFFFFFull;
                                        l_hdatSmfStartAddr.hi |= HDAT_REAL_ADDRESS_MASK;

                                        l_hdatSmfEndAddr.hi =
                                            ((l_smfStartAddr + l_smfSize) &
                                            0xFFFFFFFF00000000ull) >>32;
                                        l_hdatSmfEndAddr.lo =
                                            (l_smfStartAddr + l_smfSize) &
                                            0x00000000FFFFFFFFull;
                                        l_hdatSmfEndAddr.hi |= HDAT_REAL_ADDRESS_MASK;

                                        l_err = addMsAreaAddr(l_index,
                                                              l_hdatSmfStartAddr,
                                                              l_hdatSmfEndAddr,
                                                              l_procChipId,
                                                              false, //rangeIsMirrorable
                                                              0, // i_mirroringAlgorithm
                                                              0, // i_startMirrAddr
                                                              l_hdatMemcntrlID,
                                                              true); // i_hdatsmf
                                        l_smfAdded = true;
                                    }

                                    if(l_err)
                                    {
                                        HDAT_ERR("Could not add SMF memory range to "
                                             "HDAT at index[%d]", l_index);
                                        break;
                                    }
                                    else
                                    {
                                        HDAT_INF("Added SMF memory range to HDAT at "
                                            "index[%d]; start addr: 0x%08x; end addr: 0x%08x"
                                            "; size: 0x%08x",
                                            l_smfStartAddr,
                                            l_smfStartAddr + l_smfSize,
                                            l_smfSize);
                                    }

                                    // Add MMIO address range entries
                                    std::vector<hdatMsAreaMmioAddrRange_t>
                                        l_mmioDevEntries;

                                    if (l_pOcmbTarget != NULL)
                                    {
                                        hdatGetMemTargetMmioInfo(l_pOcmbTarget,
                                            l_mmioDevEntries);
                                    }

                                    if(l_mmioDevEntries.empty())
                                    {
                                        HDAT_INF("No MMIO entries found with "
                                        "HUID of 0x%08X",
                                        TARGETING::get_huid(l_pOcmbTarget));
                                    }
                                    else
                                    {
                                        for (auto& mmioDev : l_mmioDevEntries)
                                        {
                                            l_err = addMsAreaMmioAddrRange(
                                                l_index,
                                                mmioDev.hdatMmioAddrRngStrAddr,
                                                mmioDev.hdatMmioAddrRngEndAddr,
                                                l_hdatMemcntrlID,
                                                l_procChipId,
                                                mmioDev.hdatMmioHbrtChipId,
                                                mmioDev.hdatMmioFlags);
                                        }
                                    }

                                    l_index++;
                                } // end of OCMB_CHIP list
                                if(l_err)
                                {
                                    break;
                                }
                            } //end of OMI list
                            if(l_err)
                            {
                                break;
                            }
                        } //end of MCC list
                        if(l_err)
                        {
                            break;
                        }
                    } //end of MI list
                    if(l_err)
                    {
                        break;
                    }
                } //end of MC list
            }
            if(l_err)
            {
                // Error message recorded above
                break;
            }
        } //end of proc list

        TARGETING::PredicateCTM l_nodePred(TARGETING::CLASS_ENC,
                                           TARGETING::TYPE_NODE);
        TARGETING::PredicateHwas l_predFunctional;
        l_predFunctional.functional(true);
        TARGETING::PredicatePostfixExpr l_functionalnode;
        l_functionalnode.push(&l_nodePred).push(&l_predFunctional).And();

        TARGETING::TargetRangeFilter l_nodes(TARGETING::targetService().begin(),
                                             TARGETING::targetService().end(),
                                             &l_functionalnode);

        TARGETING::ATTR_HB_RSV_MEM_SIZE_MB_type l_rhbSize =
            l_pSysTarget->getAttr<TARGETING::ATTR_HB_RSV_MEM_SIZE_MB>();
        if( 0 != l_rhbSize )
        {
            for(;l_nodes;++l_nodes)
            {
                TARGETING::ATTR_HB_HRMOR_NODAL_BASE_type l_rhbStartAddr =
                   l_pSysTarget->getAttr<TARGETING::ATTR_HB_HRMOR_NODAL_BASE>();

                TARGETING::Target *l_pNodeTarget = *(l_nodes);
                uint32_t l_dbobId =
                          l_pNodeTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();

                hdatMsAddr_t l_hdatRhbStartAddr;
                hdatMsAddr_t l_hdatRhbEndAddr;

                l_rhbStartAddr = l_rhbStartAddr * l_dbobId;
                TARGETING::ATTR_PAYLOAD_BASE_type l_payLoadBase =
                    l_pSysTarget->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
                // Since PAYLOAD_BASE is in MB's, converting it to bytes
                l_rhbStartAddr |= ((uint64_t)(l_payLoadBase)) << 20;
                l_rhbStartAddr &= 0xFFFFFFFF00000000;
                if( l_payLoadBase > 0x100 )
                {
                    l_rhbStartAddr = 0x40000000000; //4TB hardcode for now
                }
                l_hdatRhbStartAddr.hi =
                                (l_rhbStartAddr & 0xFFFFFFFF00000000ull) >> 32;
                l_hdatRhbStartAddr.lo =  l_rhbStartAddr & 0x00000000FFFFFFFFull;
                l_hdatRhbStartAddr.hi |= HDAT_REAL_ADDRESS_MASK;

                // need to store a 64 bit range
                uint64_t l_hbSize=0;
                // in bytes
                uint64_t l_size_bytes = (l_rhbSize * 1024 * 1024) -1;
                l_hbSize = l_rhbStartAddr + l_size_bytes;
                l_hdatRhbEndAddr.hi = (l_hbSize & 0xFFFFFFFF00000000ull) >> 32;
                l_hdatRhbEndAddr.lo =  l_hbSize & 0x00000000FFFFFFFFull;
                l_hdatRhbEndAddr.hi |= HDAT_REAL_ADDRESS_MASK;

                //TODO : : RTC Story 159684
                //Need to populate correct label size and label string
                uint32_t l_rhbLabelSize = 0;
                uint8_t* l_rhbLabelStringPtr = NULL;

                addRHBAddrRange(l_dbobId, l_hdatRhbStartAddr,
                                l_hdatRhbEndAddr, l_rhbLabelSize,
                                l_rhbLabelStringPtr);

                TARGETING::ATTR_HB_RSV_MEM_SIZE_MB_type l_rhbEntries =
                    l_pSysTarget->getAttr
                        <TARGETING::ATTR_HDAT_RSV_MEM_NUM_SECTIONS>();

                l_dbobId = 0x0;
                l_hdatRhbStartAddr.lo = 0x0;
                l_hdatRhbStartAddr.hi = 0x0;
                l_hdatRhbEndAddr.lo = 0x0;
                l_hdatRhbEndAddr.hi = 0x0;
                for(uint32_t l_entry=0; l_entry<l_rhbEntries; l_entry++)
                {
                    addRHBAddrRange(l_dbobId, l_hdatRhbStartAddr,
                                    l_hdatRhbEndAddr, l_rhbLabelSize,
                                    l_rhbLabelStringPtr);
                }
            }
        }
        else
        {
            HDAT_INF("Reserve HB mem size 0x%08X",l_rhbSize);
        }

        if(l_err)
        {
            // Error message recorded above
            break;
        }

        o_size = 0;
        o_count = 1; // Only 1 of these structures is ever built

        getTotalSize (o_size);


        uint64_t l_base_addr = ((uint64_t) iv_msAddr.hi << 32) | iv_msAddr.lo;
        uint64_t l_base_addr_down = ALIGN_PAGE_DOWN(l_base_addr);
        iv_virtAddr = mm_block_map ( reinterpret_cast<void*>(l_base_addr_down),
                                         (ALIGN_PAGE(o_size) + PAGESIZE));

        uint64_t l_final_addr = reinterpret_cast<uint64_t>(iv_virtAddr);

        l_final_addr +=  l_base_addr - l_base_addr_down;


        iv_virtAddr = reinterpret_cast<void *> (l_final_addr);


        commit(iv_virtAddr,o_size);

        prt();
    }
    while(0);

    HDAT_EXIT();

    return l_err;
}

/** @brief See the prologue in hdatmsvpd.H
 */
void HdatMsVpd::commit(void * i_addr,
                             uint32_t i_size)
{

    uint32_t l_cnt,l_currOffset, l_ramSizes;
    HdatMsArea *l_msEntry;
    UtilMem l_data(i_addr, i_size);

    // Start committing the base class data
    this->startCommit(l_data);

    l_data.write(&iv_maxAddr, sizeof(hdatMsVpdAddr_t));

    l_data.write(&iv_maxSize, sizeof(hdatMsVpdSize_t));

    // Page mover is called 'Misc Addr Structure' on OPAL but still exists
    l_data.write(&iv_mover, sizeof(hdatMsVpdPageMover_t));

    l_data.write(&iv_IMTaddrRngArrayHdr,sizeof(hdatHDIFDataArray_t));

    l_data.write(iv_IMTaddrRangeArray,
        iv_maxIMTAddrRngCnt * sizeof(hdatMsVpdImtAddrRange_t));

    l_data.write(&iv_UEaddrRngArrayHdr, sizeof(hdatHDIFDataArray_t));

    l_data.write(iv_UEaddrRangeArray,
            iv_maxUEAddrRngCnt * sizeof(hdatMsVpdUEAddrRange_t));

    l_data.write(&iv_RHBaddrRngArrayHdr,sizeof(hdatHDIFDataArray_t));

    l_data.write (iv_RHBaddrRangeArray,iv_maxRHBAddrRngCnt
            * sizeof(hdatMsVpdRhbAddrRange_t));

    this->endCommit(l_data);


    // Write the MS area structures and RAM structures
    if (iv_actMsAreaCnt > 0)
    {
        // All of the mainstore areas must be written first so that can be
        // processed as an array of mainstore areas.
        l_ramSizes = 0;
        l_cnt = 0;

        while (l_cnt < iv_actMsAreaCnt)
        {
            l_msEntry = *(reinterpret_cast<HdatMsArea **>(
                        reinterpret_cast<char *>(iv_msAreaPtrs) + l_cnt
                        * sizeof(HdatMsArea *)));

            // Since we don't know what order mainstore areas and RAM
            // areas were created, update the offset in the HdatMsArea
            // child structure triple so it points to the first RAM area.

            l_currOffset = (iv_actMsAreaCnt - l_cnt) * l_msEntry->size()
                            + l_ramSizes;
            l_msEntry->chgChildOffset(HDAT_MS_AREA_RAM_AREAS, l_currOffset);
            l_msEntry->commit(l_data);

            // Now compute the size of the RAM areas associated with this
            // mainstore  area.  These will have to be added to the child
            // offset for the next mainstore area to skip over them.
            l_ramSizes += l_msEntry->ramObjSizes();

            l_cnt++;
        }

        // Now the children (RAM areas) of each mainstore area must be committed
        l_cnt = 0;

        while (l_cnt < iv_actMsAreaCnt)
        {
          l_msEntry = *(reinterpret_cast<HdatMsArea **>(reinterpret_cast<char *>
                      (iv_msAreaPtrs) + l_cnt
                      * sizeof(HdatMsArea *)));
          l_msEntry->commitRamAreas(l_data);
          l_cnt++;
        }
    }
}

/*******************************************************************************
*  hdatGetMaxMemConfiguredAddress
*******************************************************************************/
uint64_t HdatMsVpd::hdatGetMaxMemConfiguredAddress(
    TARGETING::ATTR_MODEL_type i_model)
{
    //For each processor in the system
    TARGETING::PredicateCTM l_procChipPred(TARGETING::CLASS_CHIP,
                                           TARGETING::TYPE_PROC);

    TARGETING::PredicateHwas l_predFunctional;
    l_predFunctional.functional(true);
    TARGETING::PredicatePostfixExpr l_functionalProc;
    l_functionalProc.push(&l_procChipPred).push(&l_predFunctional).And();

    TARGETING::TargetRangeFilter l_procs(
                TARGETING::targetService().begin(),
                TARGETING::targetService().end(),
                &l_functionalProc);

    uint64_t l_maxBase = 0x0ull;
    uint64_t l_maxMsAddress = 0x0ull;
    bool l_processedAnyGroup = false;
    uint64_t l_hdatMaxImtAddr = 0x0ull;

    for(;l_procs;++l_procs)
    {
        TARGETING::Target *l_pProcTarget = (*l_procs);

        TARGETING::ATTR_PROC_MEM_BASES_type l_procMemBases = {0};
        TARGETING::ATTR_PROC_MEM_SIZES_type l_procMemSizesBytes = {0};

        assert(l_pProcTarget->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>
                                                         (l_procMemSizesBytes));

        assert(l_pProcTarget->
               tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_procMemBases));
        //TODO : RTC Story 246361 HDAT Nimbus/Cumulus model code removal
        if (i_model == TARGETING::MODEL_NIMBUS)
        {
            //For each MCA
            TARGETING::PredicateCTM l_allMca(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_MCA);
            TARGETING::PredicateHwas l_funcMca;
            l_funcMca.functional(true);
            TARGETING::PredicatePostfixExpr l_allFuncMca;
            l_allFuncMca.push(&l_allMca).push(&l_funcMca).And();

            TARGETING::TargetHandleList l_mcaList;

            TARGETING::targetService().
                  getAssociated(l_mcaList, l_pProcTarget,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL, &l_allFuncMca);

            for(uint32_t i=0; i < l_mcaList.size(); i++)
            {

                TARGETING::Target *l_pMcaTarget = l_mcaList[i];

                uint32_t l_mcaInGroup =  0;
                if(!hdatFindGroupForMc(l_pProcTarget,
                                       l_pMcaTarget,
                                       l_mcaInGroup))
                {
                    HDAT_INF("Input target is not in group,"
                             " MCA HUID:[0x%08X]",
                             l_pMcaTarget->getAttr<TARGETING::ATTR_HUID>());
                    //Skip this MC not part of any group
                    continue;
                }

                if(!l_processedAnyGroup ||
                   (l_procMemBases[l_mcaInGroup] > l_maxBase))
                {
                    l_maxBase = l_procMemBases[l_mcaInGroup];
                    l_processedAnyGroup = true;
                    l_maxMsAddress =
                        l_maxBase + l_procMemSizesBytes[l_mcaInGroup];
                    HDAT_INF("Max MS Addr l_maxMsAddress: = 0x%016llX,"
                      "l_maxBase= 0x%016llX,"
                      "l_procMemSizesBytes[l_mcaInGroup]= 0x%016llX",
                      l_maxMsAddress, l_maxBase,
                      l_procMemSizesBytes[l_mcaInGroup]);
                }
            }
        }
        else
        {
            //For each MCC
            TARGETING::PredicateCTM l_allMcc(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_MCC);
            TARGETING::PredicateHwas l_funcMcc;
            l_funcMcc.functional(true);
            TARGETING::PredicatePostfixExpr l_allFuncMcc;
            l_allFuncMcc.push(&l_allMcc).push(&l_funcMcc).And();

            TARGETING::TargetHandleList l_mccList;

            TARGETING::targetService().
                  getAssociated(l_mccList, l_pProcTarget,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL, &l_allFuncMcc);

            for(uint32_t i=0; i < l_mccList.size(); i++)
            {
                TARGETING::Target *l_pMccTarget = l_mccList[i];

                uint32_t l_mccInGroup =  0;
                if(!hdatFindGroupForMcc(l_pProcTarget,
                                        l_pMccTarget,
                                        l_mccInGroup))
                {
                    HDAT_INF("Input target is not in group,"
                             " MCC HUID:[0x%08X]",
                             l_pMccTarget->getAttr<TARGETING::ATTR_HUID>());
                    //Skip this MCC as its not part of any group
                    continue;
                }

                if(!l_processedAnyGroup ||
                   (l_procMemBases[l_mccInGroup] > l_maxBase))
                {
                    l_maxBase = l_procMemBases[l_mccInGroup];
                    l_processedAnyGroup = true;
                    l_maxMsAddress =
                        l_maxBase + l_procMemSizesBytes[l_mccInGroup];
                    HDAT_INF("Max MS Addr l_maxMsAddress: = 0x%016llX,"
                      "l_maxBase= 0x%016llX,"
                      "l_procMemSizesBytes[l_omiInGroup]= 0x%016llX",
                      l_maxMsAddress, l_maxBase,
                      l_procMemSizesBytes[l_mccInGroup]);
                }
            }
        }

        // TODO : RTC Story 159682
        // Further CHTM support needs to be added which contains the trace array
        // for 24 cores
        hdatMsAddr_t l_hdatNhtmStartAddr;
        hdatMsAddr_t l_hdatNhtmEndAddr;

        TARGETING::ATTR_PROC_NHTM_BAR_BASE_ADDR_type l_nhtmStartAddr =
              l_pProcTarget->getAttr<TARGETING::ATTR_PROC_NHTM_BAR_BASE_ADDR>();
        TARGETING::ATTR_PROC_NHTM_BAR_SIZE_type l_nhtmSize =
              l_pProcTarget->getAttr<TARGETING::ATTR_PROC_NHTM_BAR_SIZE>();

        if( 0 != l_nhtmSize )
        {
            l_hdatNhtmStartAddr.hi =
                              (l_nhtmStartAddr & 0xFFFFFFFF00000000ull) >> 32;
            l_hdatNhtmStartAddr.lo =  l_nhtmStartAddr & 0x00000000FFFFFFFFull;
            l_hdatNhtmStartAddr.hi |= HDAT_REAL_ADDRESS_MASK;

            l_nhtmSize = l_nhtmStartAddr + l_nhtmSize;
            l_hdatNhtmEndAddr.hi =
                              (l_nhtmSize & 0xFFFFFFFF00000000ull) >> 32;
            l_hdatNhtmEndAddr.lo =  l_nhtmSize & 0x00000000FFFFFFFFull;
            l_hdatNhtmEndAddr.hi |= HDAT_REAL_ADDRESS_MASK;

            if( l_hdatMaxImtAddr <
                 (((uint64_t)l_hdatNhtmEndAddr.hi << 32) |l_hdatNhtmEndAddr.lo))
            {
                l_hdatMaxImtAddr =
                 (((uint64_t)l_hdatNhtmEndAddr.hi << 32) |l_hdatNhtmEndAddr.lo);
                HDAT_INF("NHTM Max Addr: = 0x%016llX", l_hdatMaxImtAddr);
            }
        }
        else
        {
            HDAT_INF("NHTM Bar size value = 0x%016llX ", l_nhtmSize);
        }
    }
    // Set MSB to 1 for PHYP
    l_maxMsAddress |= HDAT_REAL_ADDRESS_MASK64;

    if(l_hdatMaxImtAddr > l_maxMsAddress)
    {
        l_maxMsAddress = l_hdatMaxImtAddr;
        HDAT_INF("IMT Max MS Addr: = 0x%016llX",l_maxMsAddress);
    }
    // We now have to subtract 1 since the address range starts at 0
    if(l_maxMsAddress != 0)
    {
        l_maxMsAddress -= 1;
    }

    return l_maxMsAddress;
}

//******************************************************************************
//* hdatFindGroupForMc
//******************************************************************************
bool HdatMsVpd::hdatFindGroupForMc(const TARGETING::Target *i_pProcTarget,
                            const TARGETING::Target *i_pMcaTarget,
                            uint32_t& o_groupOfMc)
{
    bool l_foundGroup = false;
    TARGETING::ATTR_MSS_MEM_MC_IN_GROUP_type l_mcaGroups = {0};
    assert(i_pProcTarget != NULL || i_pMcaTarget != NULL);

    assert(!(i_pProcTarget->getAttr<TARGETING::ATTR_TYPE>()
                                                != TARGETING::TYPE_PROC)||
           !(i_pProcTarget->getAttr<TARGETING::ATTR_CLASS>()
                                                != TARGETING::CLASS_CHIP));

    assert(i_pProcTarget->
             tryGetAttr<TARGETING::ATTR_MSS_MEM_MC_IN_GROUP>(l_mcaGroups));

    assert(!(i_pMcaTarget->getAttr<TARGETING::ATTR_TYPE>()
                                               != TARGETING::TYPE_MCA)||
           !(i_pMcaTarget->getAttr<TARGETING::ATTR_CLASS>()
                                               != TARGETING::CLASS_UNIT));
    TARGETING::ATTR_CHIP_UNIT_type l_chipUnit =
                          i_pMcaTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
    uint32_t l_sizeOfArray  = sizeof(l_mcaGroups)/sizeof(l_mcaGroups[0]);

    assert(!(sizeof( l_mcaGroups[0] ) != sizeof(uint8_t)));

    assert(!( l_chipUnit >= ( sizeof( l_mcaGroups[0] ) * HDAT_BITS_PER_BYTE )));

    const uint8_t MC_IN_GROUP_MCA_0  = 0x80;
    for(uint32_t l_idx =0; l_idx < l_sizeOfArray;++l_idx)
    {
        //Attribute ATTR_MSS_MEM_MC_IN_GROUP  is an array of bitmask
        //bit 0 of bitmask corresponds to mca 0, bit 7 to mca7
        if((l_mcaGroups[l_idx] & (MC_IN_GROUP_MCA_0 >> l_chipUnit)) ==
               (MC_IN_GROUP_MCA_0 >> l_chipUnit))
        {
            HDAT_INF("hdatFindGroupForMc::: Found group : %d",l_idx);
            o_groupOfMc = l_idx;
            l_foundGroup = true;
            break;
        }
    }

    return l_foundGroup;
}

//******************************************************************************
//* hdatFindGroupForMcc
//******************************************************************************
bool HdatMsVpd::hdatFindGroupForMcc(const TARGETING::Target *i_pProcTarget,
                            const TARGETING::Target *i_pMccTarget,
                            uint32_t& o_groupOfMcc)
{
    bool l_foundGroup = false;
    TARGETING::ATTR_MSS_MEM_MC_IN_GROUP_type l_mccGroups = {0};
    assert(i_pProcTarget != NULL || i_pMccTarget != NULL);

    assert(!(i_pProcTarget->getAttr<TARGETING::ATTR_TYPE>()
                                                != TARGETING::TYPE_PROC)||
           !(i_pProcTarget->getAttr<TARGETING::ATTR_CLASS>()
                                                != TARGETING::CLASS_CHIP));

    assert(i_pProcTarget->
             tryGetAttr<TARGETING::ATTR_MSS_MEM_MC_IN_GROUP>(l_mccGroups));

    assert(!(i_pMccTarget->getAttr<TARGETING::ATTR_TYPE>()
                                               != TARGETING::TYPE_MCC)||
           !(i_pMccTarget->getAttr<TARGETING::ATTR_CLASS>()
                                               != TARGETING::CLASS_UNIT));
    TARGETING::ATTR_CHIP_UNIT_type l_chipUnit =
                          i_pMccTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
    uint32_t l_sizeOfArray  = sizeof(l_mccGroups)/sizeof(l_mccGroups[0]);

    assert(!(sizeof( l_mccGroups[0] ) != sizeof(uint8_t)));

    assert(!( l_chipUnit >= ( sizeof( l_mccGroups[0] ) * HDAT_BITS_PER_BYTE )));

    const uint8_t MC_IN_GROUP_MCC_0  = 0x80;
    for(uint32_t l_idx =0; l_idx < l_sizeOfArray;++l_idx)
    {
        //Attribute ATTR_MSS_MEM_MC_IN_GROUP  is an array of bitmask
        //bit 0 of bitmask corresponds to mcc 0, bit 7 to mcc 7
        if((l_mccGroups[l_idx] & (MC_IN_GROUP_MCC_0 >> l_chipUnit)) ==
               (MC_IN_GROUP_MCC_0 >> l_chipUnit))
        {
            HDAT_INF("hdatFindGroupForMcc::: Found group : %d",l_idx);
            o_groupOfMcc = l_idx;
            l_foundGroup = true;
            break;
        }
    }

    return l_foundGroup;
}

/*******************************************************************************
*  hdatScanDimms
*******************************************************************************/
errlHndl_t HdatMsVpd::hdatScanDimms(const TARGETING::Target *i_pTarget,
                         const TARGETING::Target *i_pMcsTarget,
                         uint32_t i_mcaFruid,
                         std::list<hdatRamArea>& o_areas,
                         uint32_t& o_areaSize,
                         uint32_t& o_dimmNum,
                         bool& o_areaFunctional,
                         hdatMemParentType& o_parentType)
{
    errlHndl_t l_err = NULL;

    do
    {
        if(i_pTarget->getAttr<TARGETING::ATTR_TYPE>() != TARGETING::TYPE_MCA)
        {
            HDAT_ERR("Input Target is type not MCA");
            break;
        }

        if(i_pMcsTarget->getAttr<TARGETING::ATTR_TYPE>() != TARGETING::TYPE_MCS)
        {
            HDAT_ERR("Input Target is type not MCA");
            break;
        }

        /*TODO RTC:216061 Re-enable when attr exists
        TARGETING::ATTR_EFF_DIMM_SIZE_type l_dimSizes = {{0}};
        //Get configured memory size
        if(!i_pMcsTarget->
                   tryGetAttr<TARGETING::ATTR_EFF_DIMM_SIZE>(l_dimSizes))
        {
            HDAT_ERR("DIMM size should be available with MCS");
        }
        **/

        uint8_t l_mcaPort = 0;
        if(!i_pTarget->
                   tryGetAttr<TARGETING::ATTR_REL_POS>(l_mcaPort))
        {
           HDAT_ERR("REL_POS not there in MCA port");
        }
        else
        {
            l_mcaPort= l_mcaPort%2;
        }
        //[TODO RTC: 47148]

        //for each DIMM connected to this this MCA
        TARGETING::PredicateCTM l_dimmPredicate(TARGETING::
                                                CLASS_LOGICAL_CARD,
                                                TARGETING::TYPE_DIMM);
        TARGETING::PredicateHwas l_predDimm;
        l_predDimm.present(true);
        TARGETING::PredicatePostfixExpr l_presentDimm;
        l_presentDimm.push(&l_dimmPredicate).push(&l_predDimm).And();

        TARGETING::TargetHandleList l_dimmList;

        // Get associated dimms
        TARGETING::targetService().
        getAssociated(l_dimmList, i_pTarget,
                      TARGETING::TargetService::CHILD_BY_AFFINITY,
                      TARGETING::TargetService::ALL, &l_presentDimm);

        for(uint32_t j=0; j < l_dimmList.size(); ++j)
        {
            //fetch each dimm
            TARGETING::Target *l_pDimmTarget = l_dimmList[j];

            uint32_t l_dimmfru = 0;
            l_dimmfru = l_pDimmTarget->getAttr<TARGETING::ATTR_FRU_ID>();

            //TODO RTC:216061 Re-enable when attr exists
            //uint8_t l_mcaDimm = 0;
            TARGETING::ATTR_REL_POS_type l_dimmRelPos = 0;

            if(l_pDimmTarget->
               tryGetAttr<TARGETING::ATTR_REL_POS>(l_dimmRelPos))
            {
                //TODO RTC:216061 Re-enable when attr exists
                //uint8_t l_mcaDimm = l_dimmRelPos%2; //2 DIMMs per MCA
                l_dimmRelPos = 0;
                if(!i_pTarget->
                    tryGetAttr<TARGETING::ATTR_REL_POS>(l_dimmRelPos))
                {
                    HDAT_ERR("Attribute REL_POS in MCA is not "
                             "present");
                }
            }
            else
            {
                HDAT_ERR("Attribute REL_POS in DIMM "
                         "is not present");
            }

            //Convert GB to MB
            // TODO RTC:216061 Re-enable when attr exists
            //uint32_t l_dimmSizeInMB =
            //         l_dimSizes[l_mcaPort][l_mcaDimm] * HDAT_MB_PER_GB;
            uint32_t l_dimmSizeInMB = 24 * HDAT_MB_PER_GB;
            uint32_t l_huid = TARGETING::get_huid(l_pDimmTarget);

            bool foundArea = false;
            for (std::list<hdatRamArea>::iterator l_area = o_areas.begin();
                                                  l_area != o_areas.end();
                                                  ++l_area)
            {
                //we do not need to compare each dimm fru id with mca fru id
                //to create ram area, by the below logic
                //dimms with same fruid will fall into same ram area
                //even if they have fru id same with mca
                if (l_area->ivfruId == l_dimmfru)//this means soldered dimms
                {
                    foundArea = true;
                    l_area->ivFunctional = (l_area)->ivFunctional ||
                                            isFunctional(l_pDimmTarget);
                    (l_area)->ivFunctional = true;
                    (l_area)->ivSize += l_dimmSizeInMB;
                    break;
                }
            }

            //Search in the list of RAM Areas if not
            //present create a new ram area
            if (!foundArea)
            {
                o_dimmNum++;
                o_areas.push_back(hdatRamArea(l_huid,
                                        isFunctional(l_pDimmTarget),
                                         l_dimmSizeInMB,l_dimmfru));
            }
            o_areaSize += l_dimmSizeInMB;
            o_areaFunctional = o_areaFunctional ||
                               isFunctional(l_pDimmTarget);
        }

        o_parentType = HDAT_MEM_PARENT_CEC_FRU;

        if(l_err != NULL)
        {
            //break if error
            break;
        }
    }
    while(0);
    return l_err;
}

/*******************************************************************************
*  hdatScanDimmsAxone
*******************************************************************************/
errlHndl_t HdatMsVpd::hdatScanDimmsP10(const TARGETING::Target *i_pOcmbTarget,
                         std::list<hdatRamArea>& o_areas,
                         uint32_t& o_areaSize,
                         uint32_t& o_dimmNum,
                         bool& o_areaFunctional,
                         hdatMemParentType& o_parentType)
{
    HDAT_ENTER();
    errlHndl_t l_err = NULL;

    do
    {
        if(i_pOcmbTarget->getAttr<TARGETING::ATTR_TYPE>() !=
           TARGETING::TYPE_OCMB_CHIP)
        {
            HDAT_ERR("Input Target is type not OCMB_CHIP");
            break;
        }

        //for each mem-port connected to this this ocmb_chip
        TARGETING::PredicateCTM l_allMemPort(TARGETING::CLASS_UNIT,
                                         TARGETING::TYPE_MEM_PORT);
        TARGETING::PredicateHwas l_funcMemPort;
        l_funcMemPort.functional(true);
        TARGETING::PredicatePostfixExpr l_allFuncMemPort;
        l_allFuncMemPort.push(&l_allMemPort).push(&l_funcMemPort).And();

        TARGETING::TargetHandleList l_memPortList;

        TARGETING::targetService().
              getAssociated(l_memPortList, i_pOcmbTarget,
                      TARGETING::TargetService::CHILD,
                      TARGETING::TargetService::ALL, &l_allFuncMemPort);

        for(uint32_t i=0; i < l_memPortList.size(); i++)
        {
            TARGETING::Target *l_pmemPortTarget = l_memPortList[i];

            TARGETING::ATTR_MEM_EFF_DIMM_SIZE_type l_dimSizes = {0};
            //Get configured memory size
            if(!l_pmemPortTarget->
                   tryGetAttr<TARGETING::ATTR_MEM_EFF_DIMM_SIZE>(l_dimSizes))
            {
                HDAT_ERR("DIMM size should be available with MEM_PORT");
            }

            //for each DIMM connected to this this MCA
            TARGETING::PredicateCTM l_dimmPredicate(TARGETING::
                                                    CLASS_LOGICAL_CARD,
                                                    TARGETING::TYPE_DIMM);
            TARGETING::PredicateHwas l_predDimm;
            l_predDimm.present(true);
            TARGETING::PredicatePostfixExpr l_presentDimm;
            l_presentDimm.push(&l_dimmPredicate).push(&l_predDimm).And();

            TARGETING::TargetHandleList l_dimmList;

            // Get associated dimms
            TARGETING::targetService().
            getAssociated(l_dimmList, l_pmemPortTarget,
                          TARGETING::TargetService::CHILD_BY_AFFINITY,
                          TARGETING::TargetService::ALL, &l_presentDimm);

            for(uint32_t j=0; j < l_dimmList.size(); ++j)
            {
                //fetch each dimm
                TARGETING::Target *l_pDimmTarget = l_dimmList[j];

                uint32_t l_dimmfru = 0;
                l_dimmfru = l_pDimmTarget->getAttr<TARGETING::ATTR_FRU_ID>();

                TARGETING::ATTR_MEM_PORT_type l_dimmMemPort = 0;

                if(!l_pDimmTarget->
                    tryGetAttr<TARGETING::ATTR_MEM_PORT>(l_dimmMemPort))
                {
                    HDAT_ERR("DIMM size should be available with MEM_PORT");
                }

                //Convert GB to MB
                uint32_t l_dimmSizeInMB = l_dimSizes[l_dimmMemPort] *
                    HDAT_MB_PER_GB;
                uint32_t l_huid = TARGETING::get_huid(l_pDimmTarget);

                bool foundArea = false;
                for (std::list<hdatRamArea>::iterator l_area = o_areas.begin();
                                                      l_area != o_areas.end();
                                                      ++l_area)
                {
                    //we do not need to compare each dimm fru id with mca fru id
                    //to create ram area, by the below logic
                    //dimms with same fruid will fall into same ram area
                    //even if they have fru id same with mca
                    if (l_area->ivfruId == l_dimmfru)//this means soldered dimms
                    {
                        foundArea = true;
                        l_area->ivFunctional = (l_area)->ivFunctional ||
                                                isFunctional(l_pDimmTarget);
                        (l_area)->ivFunctional = true;
                        (l_area)->ivSize += l_dimmSizeInMB;
                        break;
                    }
                }

                //Search in the list of RAM Areas if not
                //present create a new ram area
                if (!foundArea)
                {
                    o_dimmNum++;
                    o_areas.push_back(hdatRamArea(l_huid,
                                      isFunctional(l_pDimmTarget),
                                      l_dimmSizeInMB,l_dimmfru));
                }
                o_areaSize += l_dimmSizeInMB;
                o_areaFunctional = o_areaFunctional ||
                                   isFunctional(l_pDimmTarget);
            }  //end of dimm list

            o_parentType = HDAT_MEM_PARENT_CEC_FRU;

            if(l_err != NULL)
            {
                //break if error
                break;
            }
        } // end of mem_port list
        if(l_err != NULL)
        {
            //break if error
            break;
        }
    }
    while(0);
    HDAT_EXIT();
    return l_err;
}

/*******************************************************************************
*  hdatGetMaxMemoryBlocks
*******************************************************************************/
errlHndl_t HdatMsVpd::hdatGetMaxMemoryBlocks(const TARGETING::Target *i_pTarget,
                                   uint32_t &o_maxMemoryBlocks)
{
    errlHndl_t l_err = NULL;
    do
    {
        //One Memctrl connected to only one membuf in P8
        o_maxMemoryBlocks = 1;
    }
    while(0);
    return l_err;
}
} //namespace HDAT
