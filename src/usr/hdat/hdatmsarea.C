/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatmsarea.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
 * @file hdatmsarea.C
 *
 *  @brief This file contains the implementation of the HdatMsArea class.
 *
 */


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdlib.h>         // malloc & free
#include <hdat/hdat.H>           // debug compile control variables
#include "hdatmsarea.H"     // HdatMsArea class definition
#include "hdatutil.H"       // utility functions
#include "hdatmsvpd.H"

#include <stdio.h>

namespace HDAT
{
/*----------------------------------------------------------------------------*/
/* Global variables                                                           */
/*----------------------------------------------------------------------------*/
uint32_t HdatMsArea::cv_actualCnt;

static vpdData mvpdData[] =
{
    { MVPD::VINI, MVPD::DR },
    { MVPD::VINI, MVPD::FN },
    { MVPD::VINI, MVPD::PN },
    { MVPD::VINI, MVPD::SN },
    { MVPD::VINI, MVPD::CC },
//    { MVPD::VINI, MVPD::PR },
    //{ MVPD::VINI, MVPD::SZ },
    { MVPD::VINI, MVPD::HE },
    { MVPD::VINI, MVPD::CT },
    { MVPD::VINI, MVPD::HW },
 //   { MVPD::VINI, MVPD::B3 },
 //   { MVPD::VINI, MVPD::B4 },
 //   { MVPD::VINI, MVPD::B7 },
};

const HdatKeywordInfo l_mvpdKeywords[] = 
{
    { MVPD::DR,  "DR" },  
    { MVPD::FN,  "FN" },  
    { MVPD::PN,  "PN" },  
    { MVPD::SN,  "SN" },  
    { MVPD::CC,  "CC" },  
    { MVPD::HE,  "HE" },  
    { MVPD::CT,  "CT" },  
    { MVPD::HW,  "HW" },  
};


/** @brief See the prologue in hdatmsarea.H
 */
HdatMsArea::HdatMsArea(errlHndl_t &o_errlHndl,
                       TARGETING::Target * i_target,
                            uint16_t i_msAreaId,
                            uint32_t i_ramCnt,
                            uint32_t i_chipEcCnt,
                            uint32_t i_addrRngCnt,
                            uint32_t i_resourceId,
                            uint32_t i_slcaIdx,
                            uint32_t i_kwdSize,
                            char *&i_kwd)

: HdatHdif(o_errlHndl,HDAT_MSAREA_STRUCT_NAME,HDAT_MS_AREA_LAST,cv_actualCnt++,
    HDAT_MS_AREA_CHILD_LAST,HDAT_MS_AREA_VERSION), 
  iv_kwdSize(i_kwdSize),
  iv_maxAddrRngCnt(HDAT_MAX_ADDR_RNG_ENTRIES), iv_maxEcCnt(HDAT_MAX_EC_ENTRIES),
  iv_maxRamCnt(i_ramCnt), iv_actRamCnt(0), iv_maxRamObjSize(0), iv_kwd(NULL),
  iv_ramPadReq(false),iv_addrRange(NULL), iv_ecLvl(NULL), iv_ramPtrs(NULL)
{
    HDAT_ENTER( );

    uint32_t l_slcaIdx = 0;
    iv_mmioAddrRngArray = NULL;

    o_errlHndl = NULL;
    iv_fru.hdatResourceId = i_resourceId;

    memset(&iv_msId, 0x00, sizeof(hdatMsAreaId_t));
    memset(&iv_msSize, 0x00, sizeof(hdatMsAreaSize_t));
    memset(&iv_aff, 0x00, sizeof(hdatMsAreaAffinity_t));

    iv_msId.hdatMsAreaId = i_msAreaId;
    iv_maxMmioAddrRngCnt =  HDAT_MAX_MMIO_ADDR_RNG_ENTRIES;

    //TODO : RTC Story 161864
    //For Nimbus based systems, FSI device path length is always zero so hard
    //coding the values
    //But for Cumulus/Centaur based systems, we need to get the actual data
    iv_msId.hdatFsiDevicePathLen = 0;
    memset(iv_msId.hdatFsiDevicePath, 0x00, 64);
  
    iv_addrRngArrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    iv_addrRngArrayHdr.hdatArrayCnt  = 0;
    iv_addrRngArrayHdr.hdatAllocSize = sizeof(hdatMsAreaAddrRange_t);
    iv_addrRngArrayHdr.hdatActSize   = sizeof(hdatMsAreaAddrRange_t);

    iv_mmioAddrRngArrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    iv_mmioAddrRngArrayHdr.hdatArrayCnt  = 0;
    iv_mmioAddrRngArrayHdr.hdatAllocSize = sizeof(hdatMsAreaMmioAddrRange_t);
    iv_mmioAddrRngArrayHdr.hdatActSize   = sizeof(hdatMsAreaMmioAddrRange_t);

    iv_ecArrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    iv_ecArrayHdr.hdatArrayCnt  = 0;
    iv_ecArrayHdr.hdatAllocSize = sizeof(hdatEcLvl_t);
    iv_ecArrayHdr.hdatActSize   = sizeof(hdatEcLvl_t);
    l_slcaIdx = i_slcaIdx;


    // If the ASCII keyword data and related info has been passed to us as a
    // parm, use it and avoid calling into svpd.  This is an IPL performance
    // improvement since all mainstore areas for an MCM will have the same
    // resource id and thus the same keyword VPD.
    if (i_kwdSize > 0)
    {
        l_slcaIdx = i_slcaIdx;
        iv_kwd = new char[i_kwdSize];
        memcpy(iv_kwd, i_kwd, i_kwdSize);
    }
    else
    {
        do
        {
            // Get the SLCA index and ASCII keyword for this resource id
            uint32_t l_num = sizeof(mvpdData)/sizeof(mvpdData[0]);
            size_t theSize[l_num];
            o_errlHndl = hdatGetAsciiKwdForMvpd(i_target,iv_kwdSize,
                                                iv_kwd,mvpdData,
                                                l_num,theSize);
            if( o_errlHndl ) { break; }

            char *o_fmtKwd;
            uint32_t o_fmtkwdSize;
            o_errlHndl = hdatformatAsciiKwd(mvpdData , l_num , theSize, iv_kwd,
                iv_kwdSize, o_fmtKwd, o_fmtkwdSize, l_mvpdKeywords);
            if( o_errlHndl ) { break; }

            if( o_fmtKwd != NULL )
            {
                delete[] iv_kwd;
                //padding extra 8 bytes to keep data sync as FSP
                iv_kwd = new char [o_fmtkwdSize + 8];
                memcpy(iv_kwd,o_fmtKwd,o_fmtkwdSize);
                iv_kwdSize = o_fmtkwdSize + 8;
                delete[] o_fmtKwd;
            }
        }while(0);
    }

    // Allocate space for the address range array
    if (NULL == o_errlHndl)
    {
        iv_addrRange = new hdatMsAreaAddrRange_t[iv_maxAddrRngCnt];
        memset(iv_addrRange,0,
                (sizeof(hdatMsAreaAddrRange_t) * iv_maxAddrRngCnt));
    }

    // Allocate space for the MMIO address range array
    if (NULL == o_errlHndl)
    {
        iv_mmioAddrRngArray =
            new hdatMsAreaMmioAddrRange_t[iv_maxMmioAddrRngCnt];
        memset(iv_mmioAddrRngArray,0,
                (sizeof(hdatMsAreaMmioAddrRange_t) * iv_maxMmioAddrRngCnt));
    }

    // Allocate space for the EC level array
    if (NULL == o_errlHndl)
    {
        iv_fru.hdatSlcaIdx = l_slcaIdx;
        iv_ecLvl = new hdatEcLvl_t[iv_maxEcCnt];
    }
    // Allocate space for the RAM entries
    if (NULL == o_errlHndl)
    {
        iv_ramPtrs = new HdatRam*[i_ramCnt];
    }

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
HdatMsArea::~HdatMsArea()
{
    HDAT_ENTER( );

    uint32_t l_cnt;
    HdatRam *l_ramObj, **l_curPtr;

    // Delete RAM Objects
    l_curPtr = iv_ramPtrs;
    for (l_cnt = 0; l_cnt < iv_actRamCnt; l_cnt++)
    {
        l_ramObj = *l_curPtr;
        delete l_ramObj;
        l_curPtr = reinterpret_cast<HdatRam **>(reinterpret_cast<char*>(l_curPtr)
                    + sizeof(HdatRam *));
    }
    
    delete[] iv_kwd;
    delete[] iv_addrRange;
    delete[] iv_ecLvl;
    delete [] iv_ramPtrs;

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::setParentType(uint16_t i_type)
{
    iv_msId.hdatMsAreaParentType = i_type;
    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::setStatus(uint16_t i_status)
{
    iv_msId.hdatMsAreaStatus = i_status;

    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::setInterleavedId(uint16_t i_id)
{
    iv_msId.hdatInterleavedId = i_id;

    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::setSize(uint32_t i_size)
{
    iv_msSize.hdatReserved1 = 0;
    iv_msSize.hdatMsAreaSize = i_size;

    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::setModuleId(uint32_t i_moduleId)
{
    iv_aff.hdatMsAreaModuleId = i_moduleId;

    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::setAffinityDomain(uint32_t i_affinityDomain)
{
    iv_aff.hdatMsAffinityDomain = i_affinityDomain;

    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::getKwdInfo(uint32_t &o_resourceId,
                                 uint32_t &o_slcaIdx,
                                 uint32_t &o_kwdSize,
                                 char *&o_kwd)
{
    o_resourceId = iv_fru.hdatResourceId;
    o_slcaIdx    = iv_fru.hdatSlcaIdx;
    o_kwdSize    = iv_kwdSize;
    o_kwd        = iv_kwd;

    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
errlHndl_t HdatMsArea::addAddrRange(hdatMsAddr_t &i_start,
                                    hdatMsAddr_t &i_end,
                                    uint32_t i_procChipId,
                                    bool i_rangeIsMirrorable,
                                    uint8_t i_mirroringAlgorithm,
                                    hdatMsAddr_t &i_startMirrAddr,
                                    uint32_t  i_memcntlrId,
                                    bool i_hdatSmf)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    hdatMsAreaAddrRange_t *l_addr;

    if (iv_addrRngArrayHdr.hdatArrayCnt < iv_maxAddrRngCnt)
    {
        l_addr = reinterpret_cast<hdatMsAreaAddrRange_t*>(
        reinterpret_cast<char*>(iv_addrRange) + iv_addrRngArrayHdr.hdatArrayCnt*
        sizeof(hdatMsAreaAddrRange_t));

        l_addr->hdatMsAreaStrAddr = i_start;
        l_addr->hdatMsAreaEndAddr = i_end;
        l_addr->hatMsAreaProcChipId = i_procChipId;
        l_addr->hdatSMMAttributes.hdatRangeIsMirrorable =
                i_rangeIsMirrorable ? 1 : 0;
        l_addr->hdatSMMAttributes.hdatMirroringAlgorithm = i_mirroringAlgorithm;
        l_addr->hdatSMMAttributes.hdatIsSMFmemory = i_hdatSmf;
        l_addr->hdatStartMirrAddr = i_startMirrAddr;
        l_addr->hdatMsAreaMemCntId = i_memcntlrId;
        iv_addrRngArrayHdr.hdatArrayCnt++;
    }
    else
    {
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode RC_ERC_MAX_EXCEEDED
         * @moduleid MOD_ADD_ADDR_RANGE
         * @userdata1 current number of array entries
         * @userdata2 maximum number of array entries
         * @userdata3 ID number of mainstore area
         * @userdata4 none
         * @devdesc Failed trying to add another entry to a mainstore area
         *          address range array
         */
        hdatBldErrLog(l_errlHndl,
                      MOD_ADD_ADDR_RANGE,         // SRC module ID
                      RC_ERC_MAX_EXCEEDED,        // SRC extended reference code
                      iv_addrRngArrayHdr.hdatArrayCnt, // SRC hex word 1
                      iv_maxAddrRngCnt,           // SRC hex word 2
                      iv_msId.hdatMsAreaId);      // SRC hex word 3
    }
    HDAT_EXIT();
    return l_errlHndl;
}

/** @brief See the prologue in hdatmsarea.H
 */
errlHndl_t HdatMsArea::addMmioAddrRange(hdatMsAddr_t &i_start,
                                        hdatMsAddr_t &i_end,
                                        uint32_t i_mmioMemCntlId,
                                        uint32_t i_mmioProcPhyChipId,
                                        uint64_t i_mmioHbrtChipId,
                                        uint64_t i_mmioFlags)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    hdatMsAreaMmioAddrRange_t *l_addr;

    if (iv_mmioAddrRngArrayHdr.hdatArrayCnt < iv_maxMmioAddrRngCnt)
    {
        l_addr = reinterpret_cast<hdatMsAreaMmioAddrRange_t*>(
            reinterpret_cast<char*>(iv_mmioAddrRngArray) +
            iv_mmioAddrRngArrayHdr.hdatArrayCnt *
            sizeof(hdatMsAreaMmioAddrRange_t));

        l_addr->hdatMmioAddrRngStrAddr = i_start;
        l_addr->hdatMmioAddrRngEndAddr = i_end;
        l_addr->hdatMmioMemCtlId = i_mmioMemCntlId;
        l_addr->hdatMmioProcPhyChipId = i_mmioProcPhyChipId;
        l_addr->hdatMmioHbrtChipId = i_mmioHbrtChipId;
        l_addr->hdatMmioFlags = i_mmioFlags;
        iv_mmioAddrRngArrayHdr.hdatArrayCnt++;
    }
    else
    {
        /*@
         * @errortype
         * @refcode    LIC_REFCODE
         * @subsys     EPUB_FIRMWARE_SP
         * @reasoncode RC_ERC_MAX_EXCEEDED
         * @moduleid   MOD_ADD_MMIO_ADDR_RANGE
         * @userdata1  current no of mmio array entries
         * @userdata2  maximum no of mmio array entries
         * @userdata3  ID number of mainstore area
         * @userdata4  none
         * @devdesc    Failed trying to add another entry to a mainstore area
         *             MMIO address range array
         */
        hdatBldErrLog(l_errlHndl,
                      MOD_ADD_MMIO_ADDR_RANGE,             // SRC module ID
                      RC_ERC_MAX_EXCEEDED,                 // SRC ext ref code
                      iv_mmioAddrRngArrayHdr.hdatArrayCnt, // SRC hex word 1
                      iv_maxMmioAddrRngCnt,                // SRC hex word 2
                      iv_msId.hdatMsAreaId);               // SRC hex word 3
    }
    HDAT_EXIT();
    return l_errlHndl;
}

/** @brief See the prologue in hdatmsarea.H
 */
errlHndl_t HdatMsArea::addEcEntry(uint32_t i_manfId,
                                       uint32_t i_ecLvl)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    hdatEcLvl_t *l_ec;


    if (iv_ecArrayHdr.hdatArrayCnt < iv_maxEcCnt)
    {
        l_ec = reinterpret_cast<hdatEcLvl_t*>(reinterpret_cast<char*>
        (iv_ecLvl) + iv_ecArrayHdr.hdatArrayCnt * sizeof(hdatEcLvl_t));
        l_ec->hdatChipManfId = i_manfId;
        l_ec->hdatChipEcLvl  = i_ecLvl;
        iv_ecArrayHdr.hdatArrayCnt++;
    }

    HDAT_EXIT();
    return l_errlHndl;
}

/** @brief See the prologue in hdatmsarea.H
 */
errlHndl_t HdatMsArea::addRam(HdatRam &i_ram)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    HdatRam **l_arrayEntry;
    uint32_t l_ramSize;

    if (iv_actRamCnt < iv_maxRamCnt)
    {
        l_arrayEntry =  reinterpret_cast<HdatRam**>(reinterpret_cast<char*>
        (iv_ramPtrs) + iv_actRamCnt * sizeof(HdatRam *));

        *l_arrayEntry = &i_ram;

        //Determine if the size of this RAM is larger than any other RAM objects
        // associated with this mainstore area
        l_ramSize = i_ram.size();
        if (l_ramSize != iv_maxRamObjSize)
        {
            // If not the first RAM object, then we have to pad some shorter
            // RAM object(s)
            if (iv_maxRamObjSize != 0)
            {
                iv_ramPadReq = true;
            }
            if (l_ramSize > iv_maxRamObjSize)
            {
                iv_maxRamObjSize = l_ramSize;
            }
        }

        iv_actRamCnt++;
    }
    else
    {
        /*@
         * @errortype
         * @refcode LIC_REFCODE
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode RC_ERC_MAX_EXCEEDED
         * @moduleid MOD_ADD_RAM
         * @userdata1 current number of array entries
         * @userdata2 maximum number of array entries
         * @userdata3 ID number of mainstore area
         * @userdata4 none
         * @devdesc Failed trying to add another entry to a mainstore area
         *          RAM array
         */

        HDAT_INF("Failed trying to add another entry to a mainstore area RAM "
                  "array %d",iv_actRamCnt);

        hdatBldErrLog(l_errlHndl,
                  MOD_ADD_RAM,           // SRC module ID
                  RC_ERC_MAX_EXCEEDED,  // SRC extended reference code
                  iv_actRamCnt,           // SRC hex word 1
                  iv_maxRamCnt,           // SRC hex word 2
                  iv_msId.hdatMsAreaId);  // SRC hex word 3 
    }
    HDAT_EXIT();
    return l_errlHndl;
}


/** @brief See the prologue in hdatmsarea.H
 */
uint32_t HdatMsArea::ramObjSizes()
{
    HDAT_ENTER();
    uint32_t l_size, l_cnt;
    HdatRam *l_ramObj;

    l_size = 0;

    // Process the RAM objects
    for (l_cnt = 0; l_cnt < iv_actRamCnt; l_cnt++)
    {
        l_ramObj = *(reinterpret_cast<HdatRam **>(reinterpret_cast<char*>
            (iv_ramPtrs) + l_cnt * sizeof(HdatRam *)));
        l_size += l_ramObj->size();
    }

    HDAT_EXIT();
    return l_size;
}


/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::finalizeObjSize()
{
    HDAT_ENTER();
    uint32_t l_idx;
    HdatRam **l_ramEntry;

    // Update the base class internal data pointers
    // When the data is written to the file by commit(), it must be done in the
    // same order as these addData() calls
    this->addData(HDAT_MS_AREA_FRU_ID, sizeof(hdatFruId_t));
    this->addData(HDAT_MS_AREA_KWD, iv_kwdSize);
    this->addData(HDAT_MS_AREA_ID, sizeof(hdatMsAreaId_t));
    this->addData(HDAT_MS_AREA_SIZE, sizeof(hdatMsAreaSize_t));
    this->addData(HDAT_MS_AREA_ADDR_RNG, sizeof(hdatHDIFDataArray_t) +
                  iv_maxAddrRngCnt * sizeof(hdatMsAreaAddrRange_t));

    this->addData(HDAT_MS_AREA_AFF, sizeof(hdatMsAreaAffinity_t));
    this->addData(HDAT_MS_AREA_EC_ARRAY, sizeof(hdatHDIFDataArray_t) +
                    iv_maxEcCnt * sizeof(hdatEcLvl_t));
    this->addData(HDAT_MS_AREA_MMIO_ADDR_RNG, sizeof(hdatHDIFDataArray_t) +
                  iv_maxMmioAddrRngCnt * sizeof(hdatMsAreaMmioAddrRange_t));

    this->align();

    // If we have RAM objects of different sizes, the smaller ones have to be
    // padded to the size of the largest one so that PHYP can traverse through
    // the RAM objects as elements of an array.
    if (iv_ramPadReq)
    {
        for (l_idx = 0; l_idx < iv_actRamCnt; l_idx++)
        {
            l_ramEntry = (reinterpret_cast<HdatRam **>(reinterpret_cast<char*>
            (iv_ramPtrs) + l_idx * sizeof(HdatRam *)));

            if (iv_maxRamObjSize > (*l_ramEntry)->size())
	        {
                (*l_ramEntry)->maxSiblingSize(iv_maxRamObjSize);
	        }
	    }
    }

    // Update the base class for children that have been added
    for (l_idx = 0; l_idx < iv_actRamCnt; l_idx++)
    {
        l_ramEntry = (reinterpret_cast<HdatRam **>(reinterpret_cast<char*>
            (iv_ramPtrs) + l_idx * sizeof(HdatRam *)));
        this->addChild(HDAT_MS_AREA_RAM_AREAS, (*l_ramEntry)->size(), 1);
                                                    // 1st parm is 0 based
    }

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdatmsarea.H
 */
uint32_t  HdatMsArea::getMsAreaSize()
{
    uint32_t l_size = 0;

    // Start committing the base class data
    l_size += this->getSize();

    // Write the various pieces of data from this derived class
    l_size += sizeof(hdatFruId_t);

    if ( iv_kwdSize > 0)
    {
        l_size += iv_kwdSize;
    }

    l_size += sizeof(hdatMsAreaId_t);

    l_size += sizeof(hdatMsAreaSize_t);

    l_size += sizeof(hdatHDIFDataArray_t);

    l_size += (iv_maxAddrRngCnt * sizeof(hdatMsAreaAddrRange_t));

    l_size += sizeof(hdatMsAreaAffinity_t);

    l_size += sizeof(hdatHDIFDataArray_t);

    l_size += (iv_maxEcCnt * sizeof(hdatEcLvl_t));

    l_size += sizeof(hdatHDIFDataArray_t);

    l_size += (iv_maxMmioAddrRngCnt * sizeof(hdatMsAreaMmioAddrRange_t));

    l_size += this->endCommitSize();
    return l_size;
}


/** @brief See the prologue in hdatmsarea.H
 */
uint32_t HdatMsArea::getRamAreaSize()
{
    uint32_t l_size = 0, l_cnt = 0;
    HdatRam *l_ramObj;

    // Write the RAM structures
    if (iv_actRamCnt > 0)
    {
        l_cnt = 0;
        while (l_cnt < iv_actRamCnt)
        {
            l_ramObj = *(reinterpret_cast<HdatRam **>(reinterpret_cast<char*>
            (iv_ramPtrs) + l_cnt * sizeof(HdatRam *)));

            l_size += l_ramObj->getRamSize();
            l_cnt++;

        }
    }

    return l_size;
}
/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::commit(UtilMem &i_data)
{

    // Start committing the base class data
    this->startCommit(i_data);


    i_data.write(&iv_fru,sizeof(hdatFruId_t));

    if (iv_kwdSize > 0)
    {
        i_data.write(iv_kwd,iv_kwdSize);
    }


    i_data.write(&iv_msId,sizeof(hdatMsAreaId_t));


    i_data.write(&iv_msSize, sizeof(hdatMsAreaSize_t));

    i_data.write(&iv_addrRngArrayHdr,sizeof(hdatHDIFDataArray_t));

    i_data.write(iv_addrRange,iv_maxAddrRngCnt * sizeof(hdatMsAreaAddrRange_t));

    i_data.write(&iv_aff, sizeof(hdatMsAreaAffinity_t));

    i_data.write(&iv_ecArrayHdr, sizeof(hdatHDIFDataArray_t));

    i_data.write(iv_ecLvl,iv_maxEcCnt * sizeof(hdatEcLvl_t));

    i_data.write(&iv_mmioAddrRngArrayHdr,sizeof(hdatHDIFDataArray_t));

    i_data.write(iv_mmioAddrRngArray,
        iv_maxMmioAddrRngCnt * sizeof(hdatMsAreaMmioAddrRange_t));

    this->endCommit(i_data);
}
/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::commitRamAreas(UtilMem &i_data)
{

    uint32_t l_cnt;
    HdatRam *l_ramObj;

    // Write the RAM structures
    if (iv_actRamCnt > 0)
    {      
        l_cnt = 0; 
        while (l_cnt < iv_actRamCnt)
        {
            l_ramObj = *(reinterpret_cast<HdatRam **>(reinterpret_cast<char*>
            (iv_ramPtrs) + l_cnt * sizeof(HdatRam *)));

            l_ramObj->commit(i_data);
            l_cnt++;

        }
    }
}



/** @brief See the prologue in hdatmsarea.H
 */
void HdatMsArea::prt()
{
    uint32_t l_cnt;
    hdatEcLvl_t *l_ec;
    hdatMsAreaAddrRange_t *l_addr;
    hdatMsAreaMmioAddrRange_t *l_mmioAddr;
    HdatRam *l_ramObj;

    HDAT_INF("  **** HdatMsArea start ****");
    HDAT_INF("      cv_actualCnt = %u", cv_actualCnt);
    HDAT_INF("      iv_kwdSize = %u", iv_kwdSize);
    HDAT_INF("      iv_maxAddrRngCnt = %u", iv_maxAddrRngCnt);
    HDAT_INF("      iv_maxEcCnt = %u", iv_maxEcCnt);
    HDAT_INF("      iv_maxRamCnt = %u", iv_maxRamCnt);
    HDAT_INF("      iv_actRamCnt = %u", iv_actRamCnt);
    this->print();
    //hdatPrintFruId(&iv_fru);
    hdatPrintKwd(iv_kwd, iv_kwdSize);

    HDAT_INF("  **hdatMsAreaId_t**");
    HDAT_INF("      hdatMsAreaId = %u", iv_msId.hdatMsAreaId);
    HDAT_INF("      hdatMsAreaParentType = %u", iv_msId.hdatMsAreaParentType);
    HDAT_INF("      hdatMsAreaStatus %u", iv_msId.hdatMsAreaStatus);

    HDAT_INF("  **hdatMsAreaSize_t**");
    HDAT_INF("      hdatMsAreaSize = %u", iv_msSize.hdatMsAreaSize);

    HDAT_INF("  **hdatMsAreaAddrRange_t**");
    hdatPrintHdrs(NULL, NULL, &iv_addrRngArrayHdr, NULL);
    l_addr = iv_addrRange;
    for (l_cnt = 0; l_cnt < iv_ecArrayHdr.hdatArrayCnt; l_cnt++)
    {
        HDAT_INF("      hdatMsAreaStrAddr = 0X %08X %08X ",
               l_addr->hdatMsAreaStrAddr.hi,
               l_addr->hdatMsAreaStrAddr.lo);
        HDAT_INF("      hdatMsAreaEndAddr = 0X %08X %08X ",
               l_addr->hdatMsAreaEndAddr.hi,
               l_addr->hdatMsAreaEndAddr.lo);
        HDAT_INF("      hatMsAreaProcChipId = %u", l_addr->hatMsAreaProcChipId);
        HDAT_INF("      hdatSMMAttributes.hdatRangeIsMirrorable = %u",
                    l_addr->hdatSMMAttributes.hdatRangeIsMirrorable);
        HDAT_INF("      hdatSMMAttributes.hdatMirroringAlgorithm = %u",
                    l_addr->hdatSMMAttributes.hdatMirroringAlgorithm);
        HDAT_INF("      hdatStartMirrAddr = 0X %08X %08X ",
                    l_addr->hdatStartMirrAddr.hi, l_addr->hdatStartMirrAddr.lo);
        l_addr++;
        l_cnt++;
    }
    HDAT_INF("");


    HDAT_INF("  **hdatMsAreaAffinity_t**");
    HDAT_INF("      hdatMsAreaModuleId = %u", iv_aff.hdatMsAreaModuleId);
    HDAT_INF("      hdatMsAffinityDomain = %u", iv_aff.hdatMsAffinityDomain);

    HDAT_INF("  **hdatEcLvl_t**");
    hdatPrintHdrs(NULL, NULL, &iv_ecArrayHdr, NULL);
    l_ec = iv_ecLvl;
    for (l_cnt = 0; l_cnt < iv_ecArrayHdr.hdatArrayCnt; l_cnt++)
    {
        HDAT_INF("      hdatChipManfId = %u", l_ec->hdatChipManfId);
        HDAT_INF("      hdatChipEcLvl = %u", l_ec->hdatChipEcLvl);
        l_ec++;
    }
    HDAT_INF("");

    HDAT_INF("  **hdatMsAreaMmioAddrRange_t**");
    hdatPrintHdrs(NULL, NULL, &iv_mmioAddrRngArrayHdr, NULL);
    l_mmioAddr = iv_mmioAddrRngArray;
    for (uint8_t l_mmioCnt = 0; l_mmioCnt < iv_mmioAddrRngArrayHdr.hdatArrayCnt;
         l_mmioCnt++)
    {
        HDAT_INF("      hdatMmioAddrRngStrAddr = 0X %08X %08X ",
                 l_mmioAddr->hdatMmioAddrRngStrAddr.hi,
                 l_mmioAddr->hdatMmioAddrRngStrAddr.lo);
        HDAT_INF("      hdatMmioAddrRngEndAddr = 0X %08X %08X ",
                 l_mmioAddr->hdatMmioAddrRngEndAddr.hi,
                 l_mmioAddr->hdatMmioAddrRngEndAddr.lo);
        HDAT_INF("      hdatMmioMemCtlId = %u", l_mmioAddr->hdatMmioMemCtlId);
        HDAT_INF("      hdatMmioProcPhyChipId = %u",
                 l_mmioAddr->hdatMmioProcPhyChipId);
        HDAT_INF("      hdatMmioHbrtChipId = %u",
                 l_mmioAddr->hdatMmioHbrtChipId);
        HDAT_INF("      hdatMmioFlags = %u", l_mmioAddr->hdatMmioFlags);
        l_mmioAddr++;
        l_mmioCnt++;
    }
    HDAT_INF("");

    HDAT_INF("  **** HdatMsArea end ****");

    // Write the RAM structures
    if (iv_actRamCnt > 0)
    {
        HDAT_INF("  **associated RAM objects**");
        for(l_cnt = 0; l_cnt < iv_actRamCnt; l_cnt++)
        {
            l_ramObj = *(HdatRam **)((char *)iv_ramPtrs + l_cnt
            * sizeof(HdatRam *));
            l_ramObj->prt();
        }
    }

    return;
}
}
