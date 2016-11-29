/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatmsarea.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

static vpdData cvpdData[] =
{
//    { MVPD::VINI, MVPD::RT },
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

const HdatKeywordInfo l_cvpdKeywords[] =
{
    { CVPD::DR,  "DR" },
    { CVPD::FN,  "FN" },
    { CVPD::PN,  "PN" },
    { CVPD::SN,  "SN" },
    { CVPD::CC,  "CC" },
    { CVPD::HE,  "HE" },
    { CVPD::CT,  "CT" },
    { CVPD::HW,  "HW" },
    { CVPD::PF,  "PF" },
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
    iv_msaHostI2cCnt = 0;
    iv_msaHostI2cSize = 0;
    iv_msaI2cDataPtr = NULL;

    o_errlHndl = NULL;
    iv_fru.hdatResourceId = i_resourceId;

    memset(&iv_msId, 0x00, sizeof(hdatMsAreaId_t));
    memset(&iv_msSize, 0x00, sizeof(hdatMsAreaSize_t));
    memset(&iv_aff, 0x00, sizeof(hdatMsAreaAffinity_t));

    iv_msId.hdatMsAreaId = i_msAreaId;

    iv_addrRngArrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    iv_addrRngArrayHdr.hdatArrayCnt  = 0;
    iv_addrRngArrayHdr.hdatAllocSize = sizeof(hdatMsAreaAddrRange_t);
    iv_addrRngArrayHdr.hdatActSize   = sizeof(hdatMsAreaAddrRange_t);

    iv_ecArrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    iv_ecArrayHdr.hdatArrayCnt  = 0;
    iv_ecArrayHdr.hdatAllocSize = sizeof(hdatMsAreaEcLvl_t);
    iv_ecArrayHdr.hdatActSize   = sizeof(hdatMsAreaEcLvl_t);
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
        // Get the SLCA index and ASCII keyword for this resource id
        uint32_t l_num = sizeof(cvpdData)/sizeof(cvpdData[0]);
        size_t theSize[l_num];
        hdatGetAsciiKwdForMvpd(i_target,iv_kwdSize,iv_kwd,cvpdData,
                                    l_num,theSize);
        do
        {
            char *o_fmtKwd;
            uint32_t o_fmtkwdSize;
            o_errlHndl = hdatformatAsciiKwd(cvpdData , l_num , theSize, iv_kwd,
                iv_kwdSize, o_fmtKwd, o_fmtkwdSize, l_cvpdKeywords);
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

    // Allocate space for the EC level array
    if (NULL == o_errlHndl)
    {
        iv_fru.hdatSlcaIdx = l_slcaIdx;
        iv_ecLvl = new hdatMsAreaEcLvl_t[iv_maxEcCnt];
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
                                    hdatMsAddr_t &i_startMirrAddr)
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
        l_addr->hdatStartMirrAddr = i_startMirrAddr;
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
errlHndl_t HdatMsArea::addEcEntry(uint32_t i_manfId,
                                       uint32_t i_ecLvl)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    hdatMsAreaEcLvl_t *l_ec;


    if (iv_ecArrayHdr.hdatArrayCnt < iv_maxEcCnt)
    {
        l_ec = reinterpret_cast<hdatMsAreaEcLvl_t*>(reinterpret_cast<char*>
        (iv_ecLvl) + iv_ecArrayHdr.hdatArrayCnt * sizeof(hdatMsAreaEcLvl_t));
        l_ec->hdatChipManfId = i_manfId;
        l_ec->hdatChipEcLvl  = i_ecLvl;
        iv_ecArrayHdr.hdatArrayCnt++;
    }

    HDAT_EXIT();
    return l_errlHndl;
}

/** @brief See the prologue in hdatmsarea.H
 */ 
void HdatMsArea::setMsaI2cInfo(
    std::vector<hdatMsAreaHI2cData_t> &i_I2cDevEntries )
{
    HDAT_ENTER();
    iv_msaI2cHdr.hdatOffset = 0x0010;      // this is just header of 4 words. arrays start at 0x0010
    iv_msaI2cHdr.hdatArrayCnt = i_I2cDevEntries.size();
    iv_msaI2cHdr.hdatAllocSize = sizeof(hdatMsAreaHI2cData_t);
    iv_msaI2cHdr.hdatActSize = sizeof(hdatMsAreaHI2cData_t);
    iv_msaHostI2cCnt = i_I2cDevEntries.size();
    iv_msaHostI2cSize = sizeof(hdatHDIFDataArray_t) +
        (sizeof(hdatMsAreaHI2cData_t) * iv_msaHostI2cCnt);
    HDAT_INF("iv_msaHostI2cCnt=%d, iv_msaHostI2cSize=%d",
        iv_msaHostI2cCnt, iv_msaHostI2cSize);
    if ( i_I2cDevEntries.size() != 0 )
    {
        //copy from vector to array
        std::copy(i_I2cDevEntries.begin(),i_I2cDevEntries.end(),
            iv_msaI2cDataPtr);
    }
    else
    {
        HDAT_INF("Empty Host I2C device info vector : Ms Area Id=%d, Size=%d",
            iv_msId.hdatMsAreaId, i_I2cDevEntries.size());
    } 
    HDAT_EXIT();
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
                    iv_maxEcCnt * sizeof(hdatMsAreaEcLvl_t));
    this->addData(HDAT_MS_AREA_HOST_I2C, iv_msaHostI2cSize);

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

    l_size += (iv_maxEcCnt * sizeof(hdatMsAreaEcLvl_t));

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

    i_data.write(iv_ecLvl,iv_maxEcCnt * sizeof(hdatMsAreaEcLvl_t));

    i_data.write(&iv_msaI2cHdr, sizeof(hdatHDIFDataArray_t));

    if (NULL != iv_msaI2cDataPtr)
    {
        i_data.write(iv_msaI2cDataPtr,
            (iv_msaHostI2cSize - sizeof(hdatHDIFDataArray_t)));
    }

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
    hdatMsAreaEcLvl_t *l_ec;
    hdatMsAreaAddrRange_t *l_addr;
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

    HDAT_INF("  **hdatMsAreaEcLvl_t**");
    hdatPrintHdrs(NULL, NULL, &iv_ecArrayHdr, NULL);
    l_ec = iv_ecLvl;
    for (l_cnt = 0; l_cnt < iv_ecArrayHdr.hdatArrayCnt; l_cnt++)
    {
        HDAT_INF("      hdatChipManfId = %u", l_ec->hdatChipManfId);
        HDAT_INF("      hdatChipEcLvl = %u", l_ec->hdatChipEcLvl);
        l_ec++;
    }

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
