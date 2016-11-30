/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatpcrd.C $                                     */
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

#include <sys/mm.h>
#include <sys/mmio.h>
#include "hdatpcrd.H"
#include <targeting/common/util.H>
#include "hdatvpd.H"
#include <util/align.H>
#include <devicefw/driverif.H>
#include <vpd/mvpdenums.H>

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
    { MVPD::VINI, MVPD::DR },
    { MVPD::VINI, MVPD::VZ },
    { MVPD::VINI, MVPD::CC },
    { MVPD::VINI, MVPD::CE },
    { MVPD::VINI, MVPD::FN },
    { MVPD::VINI, MVPD::PN },
    { MVPD::VINI, MVPD::SN },
    { MVPD::VINI, MVPD::PR },
    { MVPD::VINI, MVPD::HE },
    { MVPD::VINI, MVPD::CT },
    { MVPD::VINI, MVPD::HW },
 };

const HdatKeywordInfo l_mvpdKeywords[] =
{
    { MVPD::DR, "DR" },
    { MVPD::VZ, "VZ" },
    { MVPD::CC, "CC" },
    { MVPD::CE, "CE" },
    { MVPD::FN, "FN" },
    { MVPD::PN, "PN" },
    { MVPD::SN, "SN" },
    { MVPD::PR, "PR" },
    { MVPD::HE, "HE" },
    { MVPD::CT, "CT" },
    { MVPD::HW, "HW" },

};

/******************************************************************************
 * hdatGetPcrdDeviceInfo
 *
 * @brief Routine returns the Host I2C device entries
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_pProcTarget
 *       The proc target handle
 * @param[out] o_i2cDevEntries
 *       The host i2c dev entries
 *
 * @return void
 *
******************************************************************************/
void hdatGetPcrdDeviceInfo(TARGETING::Target* i_pProcTarget,
    std::vector<hdatPcrdHI2cData_t>&o_i2cDevEntries)
{
    HDAT_ENTER();
    //TODO : RTC Story 165230 
    //Need to populate the data once ready
    //std::vector<hdatDeviceInfo_t> o_deviceInfo;
    //getDeviceInfo( TARGETING::Target* i_procTarget,
    //               std::vector<hdatDeviceInfo_t>& o_deviceInfo );
    hdatPcrdHI2cData_t l_hostI2cObj;
    memset(&l_hostI2cObj, 0x00, sizeof(l_hostI2cObj));

    uint32_t l_idx = 0;

    //Hard coded values
    for (l_idx = 1; l_idx < 3; l_idx++)
    {
        l_hostI2cObj.hdatPcrdI2cMasterInfo = l_idx;
        l_hostI2cObj.hdatPcrdI2cSlaveDevType = l_idx;
        l_hostI2cObj.hdatPcrdI2cPurpose = l_idx;
        o_i2cDevEntries.push_back(l_hostI2cObj);
    }
    HDAT_EXIT();
}

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

  return l_errlHndl;
}

/*******************************************************************************
*  PCRD Constructor
*******************************************************************************/
HdatPcrd::HdatPcrd(errlHndl_t &o_errlHndl, const hdatMsAddr_t &i_msAddr)
    : iv_numPcrdEntries(0), iv_spPcrdEntrySize(0), iv_spPcrd(NULL)
{
    // Allocate the CHIP INFO section also
    iv_numPcrdEntries = HDAT_NUM_P7_PCRD_ENTRIES;
    iv_spPcrdEntrySize = sizeof(hdatSpPcrd_t) + HDAT_FULL_MVPD_SIZE;

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
}

/*******************************************************************************
*  hdatLoadPcrd
*******************************************************************************/
errlHndl_t HdatPcrd::hdatLoadPcrd(uint32_t &o_size, uint32_t &o_count)
{
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

        // @TODO: RTC 142465. Add check to know whether in fused mode or not
        l_coreThreadCount = l_pTopLevel->getAttr<ATTR_THREAD_COUNT>();
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
                        PROC,procVpdData,l_num,theSize);
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

                hdatHDIFDataArray_t *l_hostI2cFullPcrdHdrPtr = NULL;
                l_hostI2cFullPcrdHdrPtr =
                    reinterpret_cast<hdatHDIFDataArray_t *>
                    (l_FullMvpdAddr+l_FullMvpdSize);

                // TODO RTC Story 165230
                // Need to get i2c Master data correctly
                std::vector<hdatPcrdHI2cData_t> l_i2cDevEntries;

                hdatGetPcrdDeviceInfo(l_pProcTarget, l_i2cDevEntries);

                l_pcrdHI2cTotalSize = sizeof(hdatHDIFDataArray_t) +
                    (sizeof(hdatPcrdHI2cData_t) * l_i2cDevEntries.size());

                HDAT_INF("pcrdHI2cNumEntries=0x%x, l_pcrdHI2cTotalSize=0x%x",
                    l_i2cDevEntries.size(), l_pcrdHI2cTotalSize);

                l_hostI2cFullPcrdHdrPtr->hdatOffset = 0x0010; // All array entries start right after header which is of 4 word size
                l_hostI2cFullPcrdHdrPtr->hdatArrayCnt =
                    l_i2cDevEntries.size();
                l_hostI2cFullPcrdHdrPtr->hdatAllocSize =
                    sizeof(hdatPcrdHI2cData_t);
                l_hostI2cFullPcrdHdrPtr->hdatActSize =
                    sizeof(hdatPcrdHI2cData_t);

                hdatPcrdHI2cData_t *l_hostI2cFullPcrdDataPtr = NULL;
                l_hostI2cFullPcrdDataPtr =
                    reinterpret_cast<hdatPcrdHI2cData_t *>
                    (l_hostI2cFullPcrdHdrPtr+sizeof(hdatHDIFDataArray_t));

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
                this->iv_spPcrd->hdatHdr.hdatSize += l_pcrdHI2cTotalSize;

              
                uint8_t* l_temp = reinterpret_cast<uint8_t *>
                                                 (l_hostI2cFullPcrdHdrPtr);

                l_temp += l_pcrdHI2cTotalSize;
                l_pnor = reinterpret_cast<hdatPcrdPnor_t *>(l_temp);
            }

            if ( l_pProcTarget == l_pMasterProc )
            {
                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_PNOR].hdatOffset =
                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_I2C].hdatOffset
                   + 
                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_I2C].hdatSize;

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
                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_PNOR].hdatOffset = 
                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_I2C].hdatOffset
                   +
                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_HOST_I2C].hdatSize;

                this->iv_spPcrd->hdatPcrdIntData[HDAT_PCRD_DA_PNOR].hdatSize
                                                             = 0;
                HDAT_DBG("not a master proc, pnor data is not added");
            }

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
        }
        o_size = (reinterpret_cast<uint8_t *> (this->iv_spPcrd)
                        - l_offset ) / index ;
        o_count = index;
    }while(0);

    return l_errl;
}

/*******************************************************************************
* hdatSetProcessorInfo
*******************************************************************************/
errlHndl_t HdatPcrd::hdatSetProcessorInfo(
                const TARGETING::Target* i_pProcTarget, uint32_t i_procstatus)
{
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

        iv_spPcrd->hdatChipData.hdatPcrdStatusFlags =
            isFunctional(i_pProcTarget)? i_procstatus : HDAT_PROC_NOT_USABLE;

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

        uint32_t l_procFabricId =
                    i_pProcTarget->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();

        // Set fabric nodeid (NNN) and chip (CC) into xscom id:  NN_N0CC
        uint32_t l_XscomChipId =
                    i_pProcTarget->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
        l_XscomChipId |= l_procFabricId << 3;


        iv_spPcrd->hdatChipData.hdatPcrdXscomChipId = l_XscomChipId;


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
        iv_spPcrd->hdatChipData.hdatPcrdFabricId = l_procFabricId;
        iv_spPcrd->hdatChipData.hdatPcrdCcmNodeID =
                    l_pNodeTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();

        //set CAPP functional state
        iv_spPcrd->hdatChipData.hdatPcrdCappFunctional = 0;
        TARGETING::PredicateCTM l_predCapp(TARGETING::CLASS_UNIT,
                                           TARGETING::TYPE_CAPP);
        TARGETING::TargetHandleList l_predCapplist;
        TARGETING::targetService().getAssociated(l_predCapplist, i_pProcTarget,
                                  TARGETING::TargetService::CHILD,
                                  TARGETING::TargetService::ALL, &l_predCapp);

        if (l_predCapplist.size() > 0)
        {
            TARGETING::Target *l_predCappTarget = l_predCapplist[0];
            iv_spPcrd->hdatChipData.hdatPcrdCappFunctional =
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

        iv_spPcrd->hdatChipData.hdatPcrdStopLevelSupport =
            l_pSysTarget->getAttr<TARGETING::ATTR_SUPPORTED_STOP_STATES>();

    }
    while(0);
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
