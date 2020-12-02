/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatpcrd.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
/* [+] Google Inc.                                                        */
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

#include <sys/mm.h>
#include <sys/mmio.h>
#include "hdatpcrd.H"
#include <targeting/common/util.H>
#include "hdatvpd.H"
#include <util/align.H>
#include <devicefw/driverif.H>
#include <vpd/mvpdenums.H>
#include <arch/memorymap.H>

using namespace VPD;
using namespace MVPD;
using namespace TARGETING;

namespace HDAT
{
extern trace_desc_t *g_trac_hdat;

/**
 * @brief Data sample to be used for MVPD testing.
 *      NOTE: By reading this entire list, it also validates that the records
 *      and keywords that we expect to be there are actually there...
 */
vpdData procVpdData[] =
{
    { MVPD::VRML, MVPD::RT },
    { MVPD::VRML, MVPD::VD },
    { MVPD::VRML, MVPD::PN },
    { MVPD::VRML, MVPD::SN },
 };

const HdatKeywordInfo l_mvpdKeywords[] =
{
    { MVPD::RT, "RT" },
    { MVPD::VD, "VD" },
    { MVPD::PN, "PN" },
    { MVPD::SN, "SN" },
};

/*******************************************************************************
 * hdatSetPcrdHdrs
 *
 * @brief Routine initializes HDIF headers for a PCRD array entry
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_pcrd
 *       The iv_spPcrd array element to operate on
 *
 * @return A null error log handle if successful, Currently can't fail.
 *
*******************************************************************************/
static errlHndl_t hdatSetPcrdHdrs(hdatSpPcrd_t *i_pcrd)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;

    i_pcrd->hdatHdr.hdatStructId       = HDAT_HDIF_STRUCT_ID;
    i_pcrd->hdatHdr.hdatInstance       = 0;
    i_pcrd->hdatHdr.hdatVersion        = HDAT_PCRD_VERSION;
    i_pcrd->hdatHdr.hdatSize           = offsetof(hdatSpPcrd_t, vpd_data);
    i_pcrd->hdatHdr.hdatHdrSize        = sizeof(hdatHDIF_t);
    i_pcrd->hdatHdr.hdatDataPtrOffset  = sizeof(hdatHDIF_t);
    i_pcrd->hdatHdr.hdatDataPtrCnt     = HDAT_PCRD_DA_CNT;
    i_pcrd->hdatHdr.hdatChildStrCnt    = 0;
    i_pcrd->hdatHdr.hdatChildStrOffset = 0;

    memcpy(i_pcrd->hdatHdr.hdatStructName, HDAT_PCRD_STRUCT_NAME,
            sizeof(i_pcrd->hdatHdr.hdatStructName));
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_CHIP_INFO].hdatOffset =
            offsetof(hdatSpPcrd_t, hdatChipData);
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_CHIP_INFO].hdatSize   =
            sizeof(hdatPcrdChipInfo_t);

    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_CHIP_TIMEOFDAY].hdatOffset =
            offsetof(hdatSpPcrd_t, hdatChipTodData);
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_CHIP_TIMEOFDAY].hdatSize =
            sizeof(hdatPcrdChipTod_t);
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_FRU_ID].hdatOffset =
            offsetof(hdatSpPcrd_t, hdatFruId);

    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_FRU_ID].hdatSize = sizeof(hdatFruId_t);
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_ASCII_KWD].hdatOffset = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_ASCII_KWD].hdatSize   = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_CHIP_VPD].hdatOffset = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_CHIP_VPD].hdatSize   = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_I2C].hdatOffset = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_I2C].hdatSize   = 0;

    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_PNOR].hdatOffset = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_PNOR].hdatSize   =
                                                 sizeof(hdatPcrdPnor_t);
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_SMP].hdatOffset = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_SMP].hdatSize   = 0;

    i_pcrd->hdatPcrdIntData[HDAT_PCRD_CHIP_EC_LVL].hdatOffset = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_CHIP_EC_LVL].hdatSize   = 0;

    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_SPI].hdatOffset = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_SPI].hdatSize   = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_EEPROM_PART].hdatOffset = 0;
    i_pcrd->hdatPcrdIntData[HDAT_PCRD_DA_EEPROM_PART].hdatSize   = 0;

  HDAT_EXIT();
  return l_errlHndl;
}

/*******************************************************************************
*  PCRD Constructor
*******************************************************************************/
HdatPcrd::HdatPcrd(errlHndl_t &o_errlHndl, const hdatMsAddr_t &i_msAddr)
    : iv_numPcrdEntries(0), iv_spPcrdEntrySize(0), iv_spPcrd(NULL)
{
    HDAT_ENTER();
    // Allocate the CHIP INFO section also
    iv_numPcrdEntries = HDAT_NUM_P7_PCRD_ENTRIES;
    iv_spPcrdEntrySize = sizeof(hdatSpPcrd_t) + HDAT_FULL_MVPD_SIZE +
           sizeof(hdatHDIFVersionedDataArray_t) + ((sizeof(hdatI2cData_t)
               * HDAT_PCRD_MAX_I2C_DEV))
               + sizeof(hdatHDIFDataArray_t)
               + (sizeof(hdatSMPLinkInfo_t) * HDAT_PCRD_MAX_SMP_LINK
               + sizeof(hdatHDIFDataArray_t) + sizeof(hdatProcEcLvlElement_t)
               + sizeof(hdatHDIFVersionedDataArray_t)
               + (sizeof(hdatSpiDevData_t) * HDAT_PCRD_MAX_SPI_DEV)
               );
     HDAT_DBG("iv_spPcrdEntrySize for one pcrd=0x%x",iv_spPcrdEntrySize);

    // Allocate space for each CHIP -- will use max amount to start
    uint64_t l_base_addr = ((uint64_t) i_msAddr.hi << 32) | i_msAddr.lo;
    void *l_virt_addr = mm_block_map (
                   reinterpret_cast<void*>(ALIGN_PAGE_DOWN(l_base_addr)),
                   (ALIGN_PAGE(iv_numPcrdEntries*iv_spPcrdEntrySize)+PAGESIZE));

    l_virt_addr = reinterpret_cast<void *>(
                        reinterpret_cast<uint64_t>(l_virt_addr) +
                        (l_base_addr - ALIGN_PAGE_DOWN(l_base_addr)));

    // initializing the space to zero
    memset(l_virt_addr ,0x0,(iv_numPcrdEntries*iv_spPcrdEntrySize));

    iv_spPcrd = reinterpret_cast<hdatSpPcrd_t *>(l_virt_addr);

    HDAT_DBG("Constructor iv_spPcrd addr 0x%016llX virtual addr 0x%016llX",
                            (uint64_t) this->iv_spPcrd, (uint64_t)l_virt_addr);
    HDAT_EXIT();
}

/*******************************************************************************
*  hdatLoadPcrd
*******************************************************************************/
errlHndl_t HdatPcrd::hdatLoadPcrd(uint32_t &o_size, uint32_t &o_count)
{
    HDAT_ENTER();
    errlHndl_t l_errl = NULL, l_errl1 = NULL;
    do
    {
        // PCRD index
        uint32_t index = 0;

        //Storing offset address for calculating the sizing of each PCRD
        uint8_t *l_offset = reinterpret_cast<uint8_t *> (this->iv_spPcrd);
        uint8_t *l_addr =l_offset;

        hdatPcrdPnor_t * l_pnor = NULL;

        // Get Max threads
        ATTR_THREAD_COUNT_type l_coreThreadCount = 0;
        Target* l_pTopLevel = NULL;
        (void)TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
        if(NULL == l_pTopLevel)
        {
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_PCRD_LOAD
             * @reasoncode       HDAT::RC_TOP_LVL_TGT_NOT_FOUND
             * @devdesc          Top level target not found
             * @custdesc         Firmware encountered an internal
             *                   error while retrieving target data
             */
            hdatBldErrLog(l_errl,
                    MOD_PCRD_LOAD,
                    RC_TOP_LVL_TGT_NOT_FOUND,
                    0,0,0,0);

            HDAT_ERR("Error getting top level target");
            break;
        }

        l_coreThreadCount = l_pTopLevel->getAttr<ATTR_THREAD_COUNT>();
        l_coreThreadCount = is_fused_mode() ? l_coreThreadCount*2 : l_coreThreadCount;
        HDAT_INF("l_coreThreadCount in pcrd = 0x%x",l_coreThreadCount);
        uint32_t l_procStatus;
        if ( l_coreThreadCount == HDAT_MAX_EIGHT_THREADS_SUPPORTED )
        {
            l_procStatus =
                HDAT_PROC_NOT_INSTALLED | HDAT_PRIM_THREAD | HDAT_EIGHT_THREAD;
        }
        else if ( l_coreThreadCount == HDAT_MAX_FOUR_THREADS_SUPPORTED )
        {
            l_procStatus =
                HDAT_PROC_NOT_INSTALLED | HDAT_PRIM_THREAD | HDAT_FOUR_THREAD;
        }
        else
        {
            l_procStatus =
                HDAT_PROC_NOT_INSTALLED | HDAT_PRIM_THREAD | HDAT_TWO_THREAD;
        }

        //query the master proc
        TARGETING::Target* l_pMasterProc = NULL;
        l_errl1 =targetService().queryMasterProcChipTargetHandle(l_pMasterProc);

        if ( l_errl1 )
        {
            HDAT_ERR("could not find the master processor,"
              " the PNOR data will not be added");

            /*@
             * @errortype
             * @moduleid         HDAT::MOD_PCRD_LOAD
             * @reasoncode       RC_TGT_ATTR_NOTFOUND
             * @devdesc          could not find target
             * @custdesc         Firmware encountered an internal error
             */
            hdatBldErrLog(l_errl1,
                          MOD_PCRD_LOAD,
                          RC_TGT_ATTR_NOTFOUND,
                          0,0,0,0,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL,
                          HDAT_VERSION1,
                          true);

        }

        //for each procs in the system
        TARGETING::PredicateCTM l_procFilter(CLASS_CHIP, TYPE_PROC);
        TARGETING::PredicateHwas l_pred;
        l_pred.present(true);
        TARGETING::PredicatePostfixExpr l_presentProc;
        l_presentProc.push(&l_procFilter).push(&l_pred).And();

        TARGETING::TargetRangeFilter l_filter(
                                    TARGETING::targetService().begin(),
                                    TARGETING::targetService().end(),
                                    &l_presentProc);
        for (;l_filter;++l_filter)
        {
            HDAT_DBG("Pcrd Address 0x%08X \n",
                    reinterpret_cast<uint8_t *> (this->iv_spPcrd));
            bool l_all_cores_usable = true;
            TARGETING::Target* l_pProcTarget = *l_filter;
            TARGETING::PredicateCTM l_corePredicate(TARGETING::CLASS_UNIT,
                                                    TARGETING::TYPE_CORE);

            TARGETING::PredicateHwas l_predPresent;
            l_predPresent.present(true);

            TARGETING::PredicatePostfixExpr l_PresentCore;
            l_PresentCore.push(&l_corePredicate).push(&l_predPresent).And();

            TARGETING::TargetHandleList l_coreList;

            TARGETING::targetService().getAssociated(l_coreList, l_pProcTarget,
                                                TARGETING::TargetService::CHILD,
                                                TARGETING::TargetService::ALL,
                                                &l_PresentCore);

            if(l_coreList.size() == 0 )
            {
                l_all_cores_usable = false;
            }

            for (uint32_t l_idx = 0; l_idx < l_coreList.size(); ++l_idx)
            {
                TARGETING::Target* l_pTarget = l_coreList[l_idx];
                l_procStatus = isFunctional(l_pTarget) ?
                                           HDAT_PROC_USABLE :
                                           HDAT_PROC_NOT_USABLE;

                if(l_procStatus == HDAT_PROC_NOT_USABLE)
                {
                    l_all_cores_usable = false;
                }
                l_procStatus |= l_coreThreadCount;
            }
            if(l_all_cores_usable)
            {
                l_procStatus = HDAT_PROC_USABLE;
            }
            else
            {
                l_procStatus = HDAT_PROC_FAILURES;
            }
            hdatSetPcrdHdrs(this->iv_spPcrd);

            l_errl = this->hdatSetProcessorInfo( l_pProcTarget,
                                                l_procStatus);
            if ( NULL != l_errl )
            {
                HDAT_ERR("Error [0x%08X] in call to get processor info failed",
                        l_errl->reasonCode());
                break;
            }

            this->iv_spPcrd->hdatFruId.hdatSlcaIdx =
                                    l_pProcTarget->getAttr<ATTR_SLCA_INDEX>();
            this->iv_spPcrd->hdatFruId.hdatResourceId =
                                    l_pProcTarget->getAttr<ATTR_SLCA_RID>();
            HDAT_DBG("iv_spPcrd->hdatFruId.hdatResourceId=0x%8X",
                       iv_spPcrd->hdatFruId.hdatResourceId);

            if (HDAT_PROC_NOT_INSTALLED == (HDAT_PROC_STAT_BITS &
                    this->iv_spPcrd->hdatChipData.hdatPcrdStatusFlags))
            {
                // Will leave the chip time-of-day info since that has its
                // own exist bits and we never wiped out before
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_FRU_ID].hdatOffset = 0;
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_FRU_ID].hdatSize   = 0;
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_ASCII_KWD].hdatOffset = 0;
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_ASCII_KWD].hdatSize   = 0;
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_CHIP_VPD].hdatOffset = 0;
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_CHIP_VPD].hdatSize   = 0;
            }
            else
            {
                // Need to complete the chip TOD information fetch
                //TODO : RTC 147507 - Fetch TOD information
                if(index ==0 )
                {
                    this->iv_spPcrd->hdatChipTodData.
                                    hdatPcrdTodFlags=0x06;
                }
                else
                {
                    this->iv_spPcrd->hdatChipTodData.
                                    hdatPcrdTodFlags=0x05;
                }
                this->iv_spPcrd->hdatChipTodData.hdatPcrdTodControls=
                                                                0x03F30000;
                this->iv_spPcrd->hdatChipTodData.
                    hdatPcrdTodControlRegister=0x003F0000;

                // Get ascii keyword
                char *l_keyword= NULL;
                uint32_t l_asciiKeywordSize=0;
                uint32_t l_num = sizeof(procVpdData) / sizeof(procVpdData[0]);
                size_t theSize[l_num];
                l_errl = hdatGetAsciiKwd(l_pProcTarget,l_asciiKeywordSize,l_keyword,
                        PROC,procVpdData,l_num,theSize,l_mvpdKeywords);
                if(l_errl )
                {
                    HDAT_ERR("Error [0x%08X] in the collect the VPD data",
                            l_errl->reasonCode());
                    break;
                }
                char *o_fmtKwd;
                uint32_t o_fmtkwdSize;
                l_errl = hdatformatAsciiKwd(procVpdData, l_num,
                        theSize, l_keyword, l_asciiKeywordSize, o_fmtKwd,
                                o_fmtkwdSize, l_mvpdKeywords);
                if( o_fmtKwd != NULL )
                {
                    delete[] l_keyword;
                    l_keyword = new char [o_fmtkwdSize];
                    memcpy(l_keyword,o_fmtKwd,o_fmtkwdSize);
                    l_asciiKeywordSize = o_fmtkwdSize;
                    delete[] o_fmtKwd;
                }

                uint8_t *l_keywordAddr=
                    reinterpret_cast<uint8_t *>
                        (&this->iv_spPcrd->hdatKwd);

                memcpy(l_keywordAddr ,l_keyword,l_asciiKeywordSize);

                if(l_keyword != NULL)
                {
                    delete[] l_keyword;
                }

                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_ASCII_KWD].hdatOffset =
                                offsetof(hdatSpPcrd_t, hdatKwd);
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_ASCII_KWD].hdatSize = l_asciiKeywordSize;
                this->iv_spPcrd->hdatHdr.hdatSize += l_asciiKeywordSize;

                // Populating of ASCII KWD Done. Time for Full mvpd dptr
                // Set the offset of Full MVPD int dptr based on prev dptr end point
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_CHIP_VPD].hdatOffset =
                            offsetof(hdatSpPcrd_t, hdatKwd) + l_asciiKeywordSize;
        
                // Get full Mvpd.
                char *l_FullMvpd = NULL;
                size_t l_FullMvpdSize = HDAT_FULL_MVPD_SIZE - 1;
                
                l_errl =  hdatGetFullEepromVpd(l_pProcTarget,
                                          l_FullMvpdSize,
                                          l_FullMvpd);

                if(l_errl)
                {
                    HDAT_ERR("hdatGetFullEepromVpd returns Error [0x%08X]", 
                                                    l_errl->reasonCode());
                    break;
                }
                
                //Virt address to fill full mvpd based on prev dptr end point
                uint8_t *l_FullMvpdAddr = (reinterpret_cast<uint8_t *>
                                    (&this->iv_spPcrd->hdatKwd)) + l_asciiKeywordSize;
                
                if(l_FullMvpd != NULL)
                {
                    memcpy(l_FullMvpdAddr ,(uint8_t *)l_FullMvpd,l_FullMvpdSize);
                    delete[] l_FullMvpd;
                    l_FullMvpd = NULL;
                }

                // Set the Full mvpd dptr and full pcrd struct sizes
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_CHIP_VPD].hdatSize = l_FullMvpdSize;
                this->iv_spPcrd->hdatHdr.hdatSize += l_FullMvpdSize;

                // Setting Host I2C device entry data
                uint32_t l_pcrdHI2cTotalSize = 0;

                hdatHDIFVersionedDataArray_t *l_hostI2cFullPcrdHdrPtr =
                    reinterpret_cast<hdatHDIFVersionedDataArray_t *>
                    (l_FullMvpdAddr+l_FullMvpdSize);

                // Need to get i2c Master data correctly
                std::vector<hdatI2cData_t> l_i2cDevEntries;
                //TODO : RTC Story 246361 HDAT Nimbus/Cumulus model code removal
                TARGETING::ATTR_MODEL_type  l_model = TARGETING::MODEL_POWER10;
                l_model = l_pProcTarget->getAttr<TARGETING::ATTR_MODEL>();

                hdatGetI2cDeviceInfo(l_pProcTarget, l_model, l_i2cDevEntries);

                l_pcrdHI2cTotalSize = sizeof(*l_hostI2cFullPcrdHdrPtr) +
                    (sizeof(hdatI2cData_t) * l_i2cDevEntries.size());

                HDAT_INF("pcrdHI2cNumEntries=0x%x, l_pcrdHI2cTotalSize=0x%x",
                    l_i2cDevEntries.size(), l_pcrdHI2cTotalSize);

                // All array entries start right after header which is of 5 word
                // size
                l_hostI2cFullPcrdHdrPtr->hdatOffset =
                    sizeof(*l_hostI2cFullPcrdHdrPtr);
                l_hostI2cFullPcrdHdrPtr->hdatArrayCnt =
                    l_i2cDevEntries.size();
                l_hostI2cFullPcrdHdrPtr->hdatAllocSize =
                    sizeof(hdatI2cData_t);
                l_hostI2cFullPcrdHdrPtr->hdatActSize =
                    sizeof(hdatI2cData_t);
                l_hostI2cFullPcrdHdrPtr->hdatVersion =
                    HOST_I2C_DEV_INFO_VERSION::V2;

                hdatI2cData_t *l_hostI2cFullPcrdDataPtr =
                    reinterpret_cast<hdatI2cData_t *>
                        (reinterpret_cast<uint8_t *>(l_hostI2cFullPcrdHdrPtr)
                            +sizeof(*l_hostI2cFullPcrdHdrPtr));

                if ( l_i2cDevEntries.size() != 0 )
                {
                    //copy data from vector to data ptr
                    std::copy(l_i2cDevEntries.begin(),
                        l_i2cDevEntries.end(), l_hostI2cFullPcrdDataPtr);
                }
                else
                {
                    HDAT_INF("Empty Host I2C device info vector : Size=%d",
                        l_i2cDevEntries.size());
                }
                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_I2C].
                    hdatOffset = this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_CHIP_VPD].hdatOffset +
                    this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_CHIP_VPD].
                    hdatSize;
                this->iv_spPcrd->hdatPcrdIntData
                    [HDAT_PCRD_DA_HOST_I2C].hdatSize = l_pcrdHI2cTotalSize;
                this->iv_spPcrd->hdatHdr.hdatSize +=
                    sizeof(*l_hostI2cFullPcrdHdrPtr) + (sizeof(hdatI2cData_t)
                    * HDAT_PCRD_MAX_I2C_DEV);

                uint8_t* l_temp = reinterpret_cast<uint8_t *>
                                                 (l_hostI2cFullPcrdHdrPtr);

                l_temp += sizeof(*l_hostI2cFullPcrdHdrPtr) + (sizeof(hdatI2cData_t)
                                    * HDAT_PCRD_MAX_I2C_DEV);
                l_pnor = reinterpret_cast<hdatPcrdPnor_t *>(l_temp);
            }


            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_PNOR].hdatOffset =
            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_I2C].hdatOffset
                   +
            sizeof(hdatHDIFVersionedDataArray_t) + (sizeof(hdatI2cData_t)
                * HDAT_PCRD_MAX_I2C_DEV);

            if(l_pProcTarget == l_pMasterProc)
            {
                hdatMsAddr_t l_hardCodedAddr = {0x00000000, 0x00000000};

                HDAT_DBG("adding pnor data to the master processor");
                l_pnor->hdatPcrdPnorBusType= 0x00;

                memset(l_pnor->hdatPcrdPnorReserved1,0x0,sizeof(uint8_t) *7);

                memcpy(&l_pnor->hdatPcrdPnorBaseAddr,&l_hardCodedAddr,
                                                       sizeof(hdatMsAddr_t));

                l_pnor->hdatPcrdPnorSize = 0x0;
                l_pnor->hdatPcrdPnorReserved2 = 0x0;

                memcpy(&l_pnor->hdatPcrdPnorGoldenTOC,&l_hardCodedAddr,
                                                        sizeof(hdatMsAddr_t));
                l_pnor->hdatPcrdPnorGoldenTOCsize = 0x0;
                l_pnor->hdatPcrdPnorReserved3 = 0x0;

                memcpy(&l_pnor->hdatPcrdPnorWorkingTOC,&l_hardCodedAddr,
                                                         sizeof(hdatMsAddr_t));
                l_pnor->hdatPcrdPnorWorkTOCsize = 0x0;
                l_pnor->hdatPcrdPnorReserved4 = 0x0;

                memcpy(&l_pnor->hdatPcrdPnorPsideTOC,&l_hardCodedAddr,
                                                         sizeof(hdatMsAddr_t));
                l_pnor->hdatPcrdPnorPsideTOCsize = 0x0;
                l_pnor->hdatPcrdPnorReserved5 = 0x0;

                memcpy(&l_pnor->hdatPcrdPnorTsideTOC,&l_hardCodedAddr,
                                                          sizeof(hdatMsAddr_t));
                l_pnor->hdatPcrdPnorTsideTOCsize = 0x0;
            }
            else
            {

                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_PNOR].hdatSize
                                                             = 0;
                HDAT_DBG("not a master proc, pnor data is not added");
            }
            
            // Add pnor struct size to whole pcrd size, since all pcrd
            // structs should be of same size
            this->iv_spPcrd->hdatHdr.hdatSize += sizeof(hdatPcrdPnor_t);

            // Setting SMP Link info
            uint32_t l_pcrdSMPTotalSize = 0;

            hdatHDIFDataArray_t *l_SMPInfoFullPcrdHdrPtr = NULL;
            l_SMPInfoFullPcrdHdrPtr = reinterpret_cast<hdatHDIFDataArray_t *>
                                ((uint8_t*)l_pnor + sizeof(hdatPcrdPnor_t));

            // Need to get SMP Link info  data correctly
            std::vector<hdatSMPLinkInfo_t> l_SMPInfoEntries;

            hdatGetSMPLinkInfo(l_pProcTarget, l_SMPInfoEntries);

            l_pcrdSMPTotalSize = sizeof(hdatHDIFDataArray_t) +
                    (sizeof(hdatSMPLinkInfo_t) * l_SMPInfoEntries.size());

            HDAT_INF("pcrdSMPNumEntries=0x%x, l_pcrdSMPTotalSize=0x%x",
                    l_SMPInfoEntries.size(), l_pcrdSMPTotalSize);
            l_SMPInfoFullPcrdHdrPtr->hdatOffset = 0x0010; // All array entries start right after header which is of 4 word size
            l_SMPInfoFullPcrdHdrPtr->hdatArrayCnt =
                     l_SMPInfoEntries.size();
            l_SMPInfoFullPcrdHdrPtr->hdatAllocSize =
                    sizeof(hdatSMPLinkInfo_t);
            l_SMPInfoFullPcrdHdrPtr->hdatActSize =
                    sizeof(hdatSMPLinkInfo_t);

            hdatSMPLinkInfo_t *l_SMPInfoFullPcrdDataPtr = NULL;
            l_SMPInfoFullPcrdDataPtr = reinterpret_cast<hdatSMPLinkInfo_t *>
                            ((uint8_t*)l_SMPInfoFullPcrdHdrPtr + sizeof(hdatHDIFDataArray_t));

            if ( l_SMPInfoEntries.size() != 0 )
            {
                //copy data from vector to data ptr
                std::copy(l_SMPInfoEntries.begin(),
                    l_SMPInfoEntries.end(), l_SMPInfoFullPcrdDataPtr);

                // Update obus speed and other things which can't be pulled from mrw
                // Since those are dynamically set by sbe.
                l_errl = hdatUpdateSMPLinkInfoData(l_SMPInfoFullPcrdHdrPtr ,
                                                      l_SMPInfoFullPcrdDataPtr,
                                                      l_pProcTarget);
                if(l_errl)
                {
                    HDAT_ERR(" Failed in hdatUpdateSMPLinkInfoData");
                    break;
                }
            }
            else
            {
                HDAT_INF("Empty SMP Link info vector : Size=%d",
                    l_SMPInfoEntries.size());
            }

            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_SMP].hdatOffset =
            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_PNOR].hdatOffset +
                    sizeof(hdatPcrdPnor_t);
            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_SMP].hdatSize = l_pcrdSMPTotalSize;
            this->iv_spPcrd->hdatHdr.hdatSize +=
            sizeof(hdatHDIFDataArray_t) + (sizeof(hdatSMPLinkInfo_t) * HDAT_PCRD_MAX_SMP_LINK);



            // Need to populate EC level info
            // PCRD is only one per chip . Hence the array count of EC level int pntr will be only 1.
        
            hdatHDIFDataArray_t *l_ECLvlInfoPcrdHdrPtr = NULL;
            l_ECLvlInfoPcrdHdrPtr = reinterpret_cast<hdatHDIFDataArray_t *>
                                ((uint8_t *)l_SMPInfoFullPcrdHdrPtr + sizeof(hdatHDIFDataArray_t) +
                                (sizeof(hdatSMPLinkInfo_t) * HDAT_PCRD_MAX_SMP_LINK));
            uint32_t l_pcrdECLvlTotalSize = sizeof(hdatHDIFDataArray_t) +
                                          sizeof(hdatProcEcLvlElement_t); 
            

            l_ECLvlInfoPcrdHdrPtr->hdatOffset = 0x0010; // All array entries start right after header which is of 4 word size
            l_ECLvlInfoPcrdHdrPtr->hdatArrayCnt = 1;
            l_ECLvlInfoPcrdHdrPtr->hdatAllocSize =
                    sizeof(hdatProcEcLvlElement_t);
            l_ECLvlInfoPcrdHdrPtr->hdatActSize =
                    sizeof(hdatProcEcLvlElement_t);

            uint32_t l_ecLevel = 0;
            uint32_t l_chipId = 0;

            l_errl = hdatGetIdEc( l_pProcTarget, 
                                  l_ecLevel,
                                  l_chipId);
            if(l_errl)
            {
                HDAT_ERR(" Getting the chip EC and ID value for proc chip with HUID 0X%8x failed",
                                    l_pProcTarget->getAttr<ATTR_HUID>());
                break;
            }
            hdatProcEcLvlElement_t *l_hdatProcEcLvlEle = reinterpret_cast<hdatProcEcLvlElement_t *>
                                    ((uint8_t *)l_ECLvlInfoPcrdHdrPtr + sizeof(hdatHDIFDataArray_t));
            l_hdatProcEcLvlEle->hdatEcLvl.hdatChipManfId = l_chipId;
            l_hdatProcEcLvlEle->hdatEcLvl.hdatChipEcLvl  = l_ecLevel;
            
            TARGETING::ATTR_ECID_type l_ecid = {0};
            assert(l_pProcTarget->tryGetAttr<TARGETING::ATTR_ECID>(l_ecid));

            l_hdatProcEcLvlEle->hdatEcid[0] = l_ecid[0];
            l_hdatProcEcLvlEle->hdatEcid[1] = l_ecid[1];
            

            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_CHIP_EC_LVL].hdatOffset =
            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_SMP].hdatOffset + sizeof(hdatHDIFDataArray_t) +
                                            (sizeof(hdatSMPLinkInfo_t) * HDAT_PCRD_MAX_SMP_LINK);
            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_CHIP_EC_LVL].hdatSize = l_pcrdECLvlTotalSize;
            this->iv_spPcrd->hdatHdr.hdatSize += l_pcrdECLvlTotalSize;

            // Setting Host SPI device entry data
            hdatHDIFVersionedDataArray_t *l_spiDevPcrdHdrPtr =
                reinterpret_cast<hdatHDIFVersionedDataArray_t *>
                ((uint8_t*)l_ECLvlInfoPcrdHdrPtr + l_pcrdECLvlTotalSize);

            // Get SPI device info
            std::vector<hdatSpiDevData_t> l_spiDevEntries;
            std::vector<hdatEepromPartData_t> l_eepromParts;

            hdatGetHostSpiDevInfo(l_spiDevEntries,l_eepromParts,l_pProcTarget);

            const uint32_t l_pcrdSpiDevTotalSize =
                sizeof(hdatHDIFVersionedDataArray_t) +
                (sizeof(hdatSpiDevData_t) * l_spiDevEntries.size());

            HDAT_INF("l_spiDevEntries=0x%x, l_pcrdSpiDevTotalSize=0x%x",
                l_spiDevEntries.size(), l_pcrdSpiDevTotalSize);

            l_spiDevPcrdHdrPtr->hdatOffset = HOST_SPI_EEPROM_OFFSET_TO_ARRAY;
            l_spiDevPcrdHdrPtr->hdatArrayCnt =
                     l_spiDevEntries.size();
            l_spiDevPcrdHdrPtr->hdatAllocSize =
                    sizeof(hdatSpiDevData_t);
            l_spiDevPcrdHdrPtr->hdatActSize =
                    sizeof(hdatSpiDevData_t);
            l_spiDevPcrdHdrPtr->hdatVersion = HOST_SPI_DEV_INFO_VERSION;

            hdatSpiDevData_t *l_spiDevPcrdDataPtr = NULL;
            l_spiDevPcrdDataPtr = reinterpret_cast<hdatSpiDevData_t *>
                ((uint8_t*)l_spiDevPcrdHdrPtr +
                            sizeof(hdatHDIFVersionedDataArray_t));

            if ( l_spiDevEntries.size() != 0 )
            {
                //copy data from vector to data ptr
                std::copy(l_spiDevEntries.begin(),
                    l_spiDevEntries.end(), l_spiDevPcrdDataPtr);
            }
            else
            {
                HDAT_INF("Empty SPI dev info vector : Size=%d",
                    l_spiDevEntries.size());
            }

            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_SPI].hdatOffset =
            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_CHIP_EC_LVL].hdatOffset +
                sizeof(hdatHDIFDataArray_t) + sizeof(hdatProcEcLvlElement_t);
            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_SPI].hdatSize =
                 l_pcrdSpiDevTotalSize;
            this->iv_spPcrd->hdatHdr.hdatSize += l_pcrdSpiDevTotalSize;

            // Setting EEPROM partition information
            hdatHDIFVersionedDataArray_t *l_eepromPartPcrdHdrPtr =
                reinterpret_cast<hdatHDIFVersionedDataArray_t *>
                ((uint8_t*)l_spiDevPcrdHdrPtr + l_pcrdSpiDevTotalSize);

            const uint32_t l_pcrdEepromPartTotalSize =
                sizeof(hdatHDIFVersionedDataArray_t) +
                (sizeof(hdatEepromPartData_t) * l_eepromParts.size());

            HDAT_INF("l_eepromParts=0x%x, l_pcrdEepromPartTotalSize=0x%x",
                l_eepromParts.size(), l_pcrdEepromPartTotalSize);

            l_eepromPartPcrdHdrPtr->hdatOffset = HOST_SPI_EEPROM_OFFSET_TO_ARRAY;
            l_eepromPartPcrdHdrPtr->hdatArrayCnt =
                l_eepromParts.size();
            l_eepromPartPcrdHdrPtr->hdatAllocSize =
                sizeof(hdatEepromPartData_t);
            l_eepromPartPcrdHdrPtr->hdatActSize =
                sizeof(hdatEepromPartData_t);
            l_eepromPartPcrdHdrPtr->hdatVersion = HOST_EEPROM_PART_VERSION;

            hdatEepromPartData_t *l_eepromPartPcrdDataPtr = NULL;
            l_eepromPartPcrdDataPtr = reinterpret_cast<hdatEepromPartData_t *>
                ((uint8_t*)l_eepromPartPcrdHdrPtr +
                sizeof(hdatHDIFVersionedDataArray_t));

            if ( l_eepromParts.size() != 0 )
            {
                //copy data from vector to data ptr
                std::copy(l_eepromParts.begin(),
                    l_eepromParts.end(), l_eepromPartPcrdDataPtr);
            }
            else
            {
                HDAT_INF("Empty EEPROM partition info vector : Size=%d",
                    l_eepromParts.size());
            }

            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_EEPROM_PART].hdatOffset =
                  this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_SPI].hdatOffset
                + this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_SPI].hdatSize;
            this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_EEPROM_PART].hdatSize=
                l_pcrdEepromPartTotalSize;
            this->iv_spPcrd->hdatHdr.hdatSize += l_pcrdEepromPartTotalSize;

            if( NULL != l_errl)
            {
                break;
            }
            index++;

            // The PCRD structure is a fixed size and has boundary of 128 bytes
            // so padding by 128 boundary.
            uint32_t l_rem=0, l_pad=0;
            l_rem=0; l_pad=0;
            l_rem = this->iv_spPcrd->hdatHdr.hdatSize % 128;
            l_pad = l_rem ? (128 - l_rem ) : 0;

            l_addr += this->iv_spPcrd->hdatHdr.hdatSize;

            // padding is allocated for size of PCRD entry. If it was
            // smaller than 128 bytes, then you may need to bump it up
            l_addr += l_pad;
            this->iv_spPcrd = reinterpret_cast<hdatSpPcrd_t *>(l_addr);
            HDAT_DBG("at the end of for loop iv_spPcrd=0x%08X",this->iv_spPcrd);
        }
        o_size = (reinterpret_cast<uint8_t *> (this->iv_spPcrd) - l_offset );
        o_count = index;
        //Take into account number of entries to get size of each entry
        o_size = (o_size / o_count);

    }while(0);
    HDAT_DBG("number of pcrd entries=0x%x,size=0x%x",o_count,o_size);

    HDAT_EXIT();
    return l_errl;
}

/*******************************************************************************
* hdatSetProcessorInfo
*******************************************************************************/
errlHndl_t HdatPcrd::hdatSetProcessorInfo(
                const TARGETING::Target* i_pProcTarget, uint32_t i_procstatus)
{
    HDAT_ENTER();
    errlHndl_t l_errl = NULL;

    do
    {
        if(NULL == i_pProcTarget)
        {
            HDAT_ERR("Input Target Pointer is NULL");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_PCRD_SET_PROC_INF
             * @reasoncode       HDAT::RC_INVALID_OBJECT
             * @userdata1        Index of proc target
             * @userdata2        Target HUID
             * @devdesc          Input Target Pointer is NULL
             * @custdesc         Firmware encountered an internal
             *                   error while retrieving target data
             */
            hdatBldErrLog(l_errl,
                    MOD_PCRD_SET_PROC_INF,
                    RC_INVALID_OBJECT,
                    0,0,0,0);
            break;
        }
        iv_spPcrd->hdatChipData.hdatPcrdProcChipId =
            i_pProcTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();
        HDAT_DBG("hdatPcrdProcChipId=0x%8X",
                 iv_spPcrd->hdatChipData.hdatPcrdProcChipId);    

        iv_spPcrd->hdatChipData.hdatPcrdStatusFlags =
            isFunctional(i_pProcTarget)? i_procstatus : HDAT_PROC_NOT_USABLE;

        if(i_pProcTarget->getAttr<ATTR_PROC_MASTER_TYPE>() == 
                        TARGETING::PROC_MASTER_TYPE_ACTING_MASTER)
        {
            iv_spPcrd->hdatChipData.hdatPcrdStatusFlags |= HDAT_PROC_IPL_MASTER;
        }

        //Set NxFunctional State
        iv_spPcrd->hdatChipData.hdatPcrdNxFunctional = 0;
        TARGETING::PredicateCTM l_predNx(TARGETING::CLASS_UNIT,
                                            TARGETING::TYPE_NX);
        TARGETING::TargetHandleList l_predNxlist;
        TARGETING::targetService().getAssociated(l_predNxlist, i_pProcTarget,
                                             TARGETING::TargetService::CHILD,
                                   TARGETING::TargetService::ALL, &l_predNx);
        if(l_predNxlist.size() > 0)
        {
            TARGETING::Target *l_predNxTarget = l_predNxlist[0];
            iv_spPcrd->hdatChipData.hdatPcrdNxFunctional =
                                isFunctional(l_predNxTarget);
        }

        //set PORE functional state
        iv_spPcrd->hdatChipData.hdatPcrdPoreFunctional = 0;
        TARGETING::PredicateCTM l_predPore(TARGETING::CLASS_UNIT,
                                           TARGETING::TYPE_PORE);
        TARGETING::TargetHandleList l_predPorelist;
        TARGETING::targetService().getAssociated(l_predPorelist, i_pProcTarget,
                                  TARGETING::TargetService::CHILD,
                                  TARGETING::TargetService::ALL, &l_predPore);

        if (l_predPorelist.size() > 0)
        {
            TARGETING::Target *l_predPoreTarget = l_predPorelist[0];
            iv_spPcrd->hdatChipData.hdatPcrdPoreFunctional =
                            isFunctional(l_predPoreTarget);

        }

        const uint8_t l_procRealFabricTopoId =
            i_pProcTarget->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();

        uint8_t l_procRealFabricGrpId = 0;
        uint8_t l_RealFabricChipId = 0;
        extractGroupAndChip(l_procRealFabricTopoId,
            l_procRealFabricGrpId, l_RealFabricChipId);

        iv_spPcrd->hdatChipData.hdatPcrdRealFabricGrpId =
                        (l_RealFabricChipId | (l_procRealFabricGrpId << 3));

        const uint8_t l_procEffFabricTopoId =
            i_pProcTarget->getAttr<TARGETING::ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>();

        uint8_t l_procEffFabricGrpId = 0;
        uint8_t l_EffFabricChipId = 0;
        extractGroupAndChip(l_procEffFabricTopoId,
            l_procEffFabricGrpId, l_EffFabricChipId);

        iv_spPcrd->hdatChipData.hdatPcrdEffFabricGrpId =
                        (l_EffFabricChipId | (l_procEffFabricGrpId << 3));


        TARGETING::TargetHandleList targetListNode;
        targetListNode.clear();
        getParentAffinityTargets(targetListNode,i_pProcTarget,
                            TARGETING::CLASS_ENC,TARGETING::TYPE_NODE);
        if(targetListNode.empty())
        {
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_PCRD_SET_PROC_INF:
             * @reasoncode       HDAT::RC_EMPTY_TARGET_LIST
             * @devdesc          Input Target Pointer is NULL
             * @custdesc         Firmware encountered an internal
             *                   error while retrieving target data
             */
            hdatBldErrLog(l_errl,
                MOD_PCRD_SET_PROC_INF,
                RC_EMPTY_TARGET_LIST,
                0,0,0,0);
                break;
        }
        //get the parent node id
        TARGETING::Target* l_pNodeTarget = targetListNode[0];

        iv_spPcrd->hdatChipData.hdatPcrdDbobId =
                    l_pNodeTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();

        iv_spPcrd->hdatChipData.hdatPcrdOccFuncState = 0;
        TARGETING::PredicateCTM l_occPredicate(TARGETING::CLASS_UNIT,
                                                  TARGETING::TYPE_OCC);
        TARGETING::TargetHandleList l_occList;
        TARGETING::targetService().getAssociated(l_occList, i_pProcTarget,
                      TARGETING::TargetService::CHILD,
                      TARGETING::TargetService::ALL, &l_occPredicate);
        if(l_occList.size() > 0)
        {
            TARGETING::Target *l_pOccTarget = l_occList[0];
            iv_spPcrd->hdatChipData.hdatPcrdOccFuncState =
                                    isFunctional(l_pOccTarget);
        }

        iv_spPcrd->hdatChipData.hdatPcrdProcessorFruId =
                            i_pProcTarget->getAttr<TARGETING::ATTR_FRU_ID>();
        HDAT_DBG("pcrd: ProcessorFruId=0x%8X",
                             iv_spPcrd->hdatChipData.hdatPcrdProcessorFruId);

        uint32_t l_eclevel = 0;
        uint32_t l_chipId = 0;

        //Set the Chip EC level
        l_errl = HDAT::hdatGetIdEc(i_pProcTarget, l_eclevel, l_chipId);
        if(NULL != l_errl)
        {
            HDAT_ERR("Error [0x%08X] in call to get IdEc Failed",
                                                        l_errl->reasonCode());
            break;
        }
        iv_spPcrd->hdatChipData.hdatPcrdChipECLevel = l_eclevel;
        iv_spPcrd->hdatChipData.hdatPcrdHwModuleId =
                            i_pProcTarget->getAttr<TARGETING::ATTR_FRU_ID>();
        // Set Hardware Card ID
        uint32_t l_HWCardId  =  0;
        l_errl = hdatGetHwCardId(i_pProcTarget,l_HWCardId);
        if(NULL != l_errl)
        {
            HDAT_ERR("Error [0x%08X] in call to get card id failed",
                                                    l_errl->reasonCode());
            break;
        }
        HDAT_DBG("hw card ID:0x%llx", l_HWCardId);

        iv_spPcrd->hdatChipData.hdatPcrdHwCardID = l_HWCardId;
        iv_spPcrd->hdatChipData.hdatPcrdFabricId = l_procRealFabricGrpId;
        iv_spPcrd->hdatChipData.hdatPcrdCcmNodeID =
                    l_pNodeTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();

        //set CAPP functional state
        iv_spPcrd->hdatChipData.hdatPcrdCappFunc_unit0 = 0;
        iv_spPcrd->hdatChipData.hdatPcrdCappFunc_unit1 = 0;
        TARGETING::PredicateCTM l_predCapp(TARGETING::CLASS_UNIT,
                                           TARGETING::TYPE_CAPP);
        TARGETING::TargetHandleList l_predCapplist;
        TARGETING::targetService().getAssociated(l_predCapplist, i_pProcTarget,
                                  TARGETING::TargetService::CHILD,
                                  TARGETING::TargetService::ALL, &l_predCapp);

        if (l_predCapplist.size() > 0 )
        {
            TARGETING::Target *l_predCappTarget = l_predCapplist[0];
            iv_spPcrd->hdatChipData.hdatPcrdCappFunc_unit0 =
                           isFunctional(l_predCappTarget)?1:0;
        }
        if (l_predCapplist.size() > 1 )
        {
            TARGETING::Target *l_predCappTarget = l_predCapplist[1];
            iv_spPcrd->hdatChipData.hdatPcrdCappFunc_unit1 =
                           isFunctional(l_predCappTarget)?1:0;
        }

                                                                               
        //set supported stop level
        TARGETING::Target *l_pSysTarget = NULL;
        (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);
        if(l_pSysTarget == NULL)
        {
            HDAT_ERR("Error in getting Top Level Target");
            assert(l_pSysTarget != NULL);
        }

#ifdef CONFIG_LOAD_PHYP_FROM_BOOTKERNEL
        //Disable all STOP states (for debug ease) when loading
        //PHYP from BOOTKERNEL partition.
        iv_spPcrd->hdatChipData.hdatPcrdStopLevelSupport = 0x00000000;
#else
        // Get the 4 byte system level supported stop state value defined by the
        // system owner for this specific box
        TARGETING::ATTR_SUPPORTED_STOP_STATES_type l_stopStates =
            l_pSysTarget->getAttr<TARGETING::ATTR_SUPPORTED_STOP_STATES>();

        // Making it ready to combine with a 2 byte value (No data loss here as
        // the last 2 bytes of the above attribute is not used)
        uint16_t l_systemStopStates = (l_stopStates & 0xFFFF0000) >> 16;

        // Get the 2 byte stop level value which is currently supported by the
        // the QME hardware/software stack
        TARGETING::ATTR_STOP_LEVELS_SUPPORTED_type l_qmeHwSwStopStates =
            l_pSysTarget->getAttr<TARGETING::ATTR_STOP_LEVELS_SUPPORTED >();

        // Final value is still a 4 byte value which reflects the intersection
        // of these two fields
        iv_spPcrd->hdatChipData.hdatPcrdStopLevelSupport =
            (l_systemStopStates & l_qmeHwSwStopStates) << 16;

        HDAT_DBG("Final Stop Level=0x%X",
            iv_spPcrd->hdatChipData.hdatPcrdStopLevelSupport);
#endif
        iv_spPcrd->hdatChipData.hdatPcrdCheckstopAddr = HDAT_SW_CHKSTP_FIR_SCOM;
        iv_spPcrd->hdatChipData.hdatPcrdSpareBitNum   = HDAT_SW_CHKSTP_FIR_SCOM_BIT_POS;

        TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE_type l_topIdTable = {0};

        //Get topology id table details
        assert(l_pSysTarget->tryGetAttr<
            TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE>(l_topIdTable));

        uint8_t l_topologyMode =
          l_pSysTarget->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_MODE>();

        uint8_t l_topIndex5bit = 0;
        iv_spPcrd->hdatChipData.hdatPcrdTopologyIdIndex = 0;

        //Fetch the 5 bit primary topology id index value
        l_topIndex5bit = hdatGetPrimaryTopIdIndex(l_procEffFabricTopoId,
            l_topologyMode);

        HDAT_DBG("EffTopId4Bit=%d, RealTopId4Bit=%d, TopMode=%d,"
            "TopIdx5bit=%d",  l_procEffFabricTopoId, l_procRealFabricTopoId,
            l_topologyMode, l_topIndex5bit);

        memset(iv_spPcrd->hdatChipData.hdatPcrdTopologyIdTab, 0xff,
            sizeof(TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE_type));

        uint8_t l_curentry = 0;
        for (uint8_t l_idx = 0;
             l_idx < sizeof(TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE_type);
             l_idx++)
        {
            if (l_topIdTable[l_idx] == l_procRealFabricTopoId)
            {
                iv_spPcrd->hdatChipData.hdatPcrdTopologyIdTab[l_curentry] =
                    l_idx;
                // ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE indicates which physical
                // processor owns each memory range. The index into the array is
                // the 5-bit address range indicator, and the value is the
                // physical topology id of the owning processor.
                if ( l_idx == l_topIndex5bit )
                {
                    iv_spPcrd->hdatChipData.hdatPcrdTopologyIdIndex =
                        l_curentry;
                }
                l_curentry++;
            }
        }

        HDAT_DBG("PrimTopIdx=%d",
            iv_spPcrd->hdatChipData.hdatPcrdTopologyIdIndex);

        bool l_smpxSet = false;
        bool l_smpaSet = false;
        TARGETING::PredicateHwas l_predHwasFunc;
        TARGETING::PredicateCTM l_iohsPredicate (TARGETING::CLASS_UNIT,
                                                 TARGETING::TYPE_IOHS);
        l_predHwasFunc.functional(true);
        TARGETING::PredicatePostfixExpr l_funcIohs;
        l_funcIohs.push(&l_iohsPredicate).push(&l_predHwasFunc).And();

        TARGETING::TargetHandleList l_iohsList;

        TARGETING::targetService().getAssociated(l_iohsList, i_pProcTarget,
                   TARGETING::TargetService::CHILD,
                   TARGETING::TargetService::ALL,
                   &l_funcIohs);

        for(uint8_t l_iohsIdx = 0; l_iohsIdx<l_iohsList.size(); ++l_iohsIdx)
        {
            TARGETING::Target *l_pIohsTarget = l_iohsList[l_iohsIdx];

            if( (l_pIohsTarget->getAttr<ATTR_IOHS_CONFIG_MODE>() ==
                 TARGETING::IOHS_CONFIG_MODE_SMPX) && (l_smpxSet == false) )
            {
                iv_spPcrd->hdatChipData.hdatPcrdXYZBusSpeed =
                    l_pIohsTarget->getAttr<ATTR_FREQ_IOHS_MHZ>();
                l_smpxSet = true;
            }
            else if( (l_pIohsTarget->getAttr<ATTR_IOHS_CONFIG_MODE>() ==
                TARGETING::IOHS_CONFIG_MODE_SMPA) && (l_smpaSet == false) )
            {
                iv_spPcrd->hdatChipData.hdatPcrdABCBusSpeed =
                    l_pIohsTarget->getAttr<ATTR_FREQ_IOHS_MHZ>();
                l_smpaSet = true;
            }

            if (l_smpxSet == true && l_smpaSet == true)
            {
                break;
            }
        }

        HDAT_DBG("l_abcFreq=%d, l_wxyzFreq=%d",
            iv_spPcrd->hdatChipData.hdatPcrdABCBusSpeed,
            iv_spPcrd->hdatChipData.hdatPcrdXYZBusSpeed);

        iv_spPcrd->hdatChipData.hdatPcrdFabTopologyId = l_procRealFabricTopoId;
    }
    while(0);
    HDAT_EXIT();
    return l_errl;
}

/*******************************************************************************
*  PCRD Destructor
*******************************************************************************/
HdatPcrd :: ~HdatPcrd()
{
    int rc = 0;
    rc =  mm_block_unmap(reinterpret_cast<void*>(ALIGN_PAGE_DOWN(
                    reinterpret_cast<uint64_t>(iv_spPcrd))));
    if( rc != 0)
    {
        errlHndl_t l_errl = NULL;
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_PCRD_DESTRUCTOR
         * @reasoncode       HDAT::RC_DEV_MAP_FAIL
         * @devdesc          Unmap a mapped region failed
         * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(l_errl,
                MOD_PCRD_DESTRUCTOR,
                RC_DEV_MAP_FAIL,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }
}


errlHndl_t HdatPcrd::fetch_pnor_data( hdatPcrdPnor_t& o_pnorData)
{
    errlHndl_t l_err = NULL;

    return l_err;

    //will be implemented once api is available
}
} // namespace HDATPcrd
