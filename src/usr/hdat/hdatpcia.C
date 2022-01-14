/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatpcia.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
#include "hdatpcia.H"
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <util/align.H>
#include <arch/pirformat.H>

using namespace TARGETING;

namespace HDAT
{
extern trace_desc_t *g_trac_hdat;

/*******************************************************************************
* hdatSetPciaHdrs
*
* @brief Routine initializes HDIF headers for a PCIA array entry
*
* @pre None
*
* @post None
*
* @param[in] i_pcia
*       The iv_spPcia array element to operate on
*
* @return A null error log handle if successful, Currently can't fail.
*
*******************************************************************************/
static errlHndl_t hdatSetPciaHdrs(hdatSpPcia_t *i_pcia)
{
    errlHndl_t l_errlHndl = NULL;

    i_pcia->hdatHdr.hdatStructId       = HDAT_HDIF_STRUCT_ID;
    i_pcia->hdatHdr.hdatInstance       = 0;
    i_pcia->hdatHdr.hdatVersion        = HDAT_PCIA_VERSION;
    i_pcia->hdatHdr.hdatSize           = sizeof(hdatSpPcia_t);
    i_pcia->hdatHdr.hdatHdrSize        = sizeof(hdatHDIF_t);
    i_pcia->hdatHdr.hdatDataPtrOffset  = sizeof(hdatHDIF_t);
    i_pcia->hdatHdr.hdatDataPtrCnt     = HDAT_PCIA_DA_CNT;
    i_pcia->hdatHdr.hdatChildStrCnt    = 0;
    i_pcia->hdatHdr.hdatChildStrOffset = 0;

    memcpy(i_pcia->hdatHdr.hdatStructName, HDAT_PCIA_STRUCT_NAME,
            sizeof(i_pcia->hdatHdr.hdatStructName));
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_COREDATA].hdatOffset =
        offsetof(hdatSpPcia_t, hdatCoreData);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_COREDATA].hdatSize =
        sizeof(hdatPciaCoreUniqueData_t);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_CPU_TIME_BASE].hdatOffset =
        offsetof(hdatSpPcia_t, hdatTime);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_CPU_TIME_BASE].hdatSize =
        sizeof(hdatPciaCpuTimeBase_t);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_CACHE_SIZE].hdatOffset =
        offsetof(hdatSpPcia_t, hdatCache);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_CACHE_SIZE].hdatSize =
        sizeof(hdatPciaCacheSize_t);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_THREADDATA].hdatOffset =
        offsetof(hdatSpPcia_t, hdatThreadData);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_THREADDATA].hdatSize =
        sizeof(hdatPciaThreadUniqueData_t);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_CPU_ATTRIBUTES].hdatOffset =
        offsetof(hdatSpPcia_t, hdatAttr);
    i_pcia->hdatPciaIntData[HDAT_PCIA_DA_CPU_ATTRIBUTES].hdatSize =
        sizeof(hdatPciaCpuAttributes_t);

    return l_errlHndl;
}

/*******************************************************************************
*  PCIA Constructor
*******************************************************************************/
HdatPcia::HdatPcia(errlHndl_t &o_errlHndl, const hdatMsAddr_t &i_msAddr)
: iv_numPciaEntries(0), iv_spPciaEntrySize(0), iv_spPcia(NULL)
{
    // Copy the main store address for the pcia data
    memcpy(&iv_msAddr, &i_msAddr, sizeof(hdatMsAddr_t));

    // We are using the CORE DATA section
    iv_numPciaEntries = HDAT_NUM_P8_PCIA_ENTRIES;
    iv_spPciaEntrySize = sizeof(hdatSpPcia_t);

    // Allocate space for each CORE -- will use max amount to start
    uint64_t l_base_addr = ((uint64_t) i_msAddr.hi << 32) | i_msAddr.lo;

    void *l_virt_addr = mm_block_map (
            reinterpret_cast<void*>(ALIGN_PAGE_DOWN(l_base_addr)),
            (ALIGN_PAGE(iv_numPciaEntries*iv_spPciaEntrySize)+PAGESIZE));

    l_virt_addr = reinterpret_cast<void *>(
                    reinterpret_cast<uint64_t>(l_virt_addr) +
                    (l_base_addr - ALIGN_PAGE_DOWN(l_base_addr)));

    // initializing the space to zero
    memset(l_virt_addr ,0x0, (iv_numPciaEntries*iv_spPciaEntrySize));

    iv_spPcia = reinterpret_cast<hdatSpPcia_t *>(l_virt_addr);

    HDAT_DBG("Constructor iv_spPcia addr 0x%016llX virtual addr 0x%016llX",
                  (uint64_t) this->iv_spPcia, (uint64_t)l_virt_addr);
}

/*******************************************************************************
*  hdatLoadPcia
*******************************************************************************/
errlHndl_t HdatPcia::hdatLoadPcia(uint32_t &o_size, uint32_t &o_count)
{
    HDAT_ENTER();
    errlHndl_t l_errl = NULL;

    do
    {
        // PCIA index
        uint32_t index = 0;

        //Storing offset address for calculating the sizing of each PCIA
        uint64_t l_offset = (uint64_t)&this->iv_spPcia[index];

        // Get Max threads
        ATTR_THREAD_COUNT_type l_coreThreadCount = 0;
        Target* l_pTopLevel = NULL;
        (void)TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
        if(NULL == l_pTopLevel)
        {
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_PCIA_LOAD
             * @reasoncode       HDAT::RC_TOP_LVL_TGT_NOT_FOUND
             * @devdesc          Top level target not found
             * @custdesc         Firmware encountered an internal
             *                   error while retrieving target data
             */
            hdatBldErrLog(l_errl,
                    MOD_PCIA_LOAD,
                    RC_TOP_LVL_TGT_NOT_FOUND,
                    0,0,0,0);

            HDAT_ERR("Error getting top level target");
            break;
        }

        // Get the fused core support info
        bool l_fused_core_support = is_fused_mode();
        HDAT_DBG("is_fused_mode=%d",l_fused_core_support);

        l_coreThreadCount = l_pTopLevel->getAttr<ATTR_THREAD_COUNT>();
        uint64_t en_thread_mask =
          l_pTopLevel->getAttr<TARGETING::ATTR_ENABLED_THREADS>();
          HDAT_INF("fetched en_thread_mask=0x%16x",en_thread_mask);
        //Check the enabled threads to see if user overrode to SMT1 or SMT2
        //Note this only handles specific SMT1/2 -- no other permutations
        size_t l_enabledThreads = l_coreThreadCount;
        if (en_thread_mask == 0x8000000000000000)
        {
            l_enabledThreads = 1;
        }
        else if (en_thread_mask == 0xC000000000000000)
        {
             l_enabledThreads = 2;
        }
        uint32_t l_procStatus;
        HDAT_DBG("Core Thread Count[%d], Enabled[%d]",
                 l_coreThreadCount, l_enabledThreads);

        if ( l_enabledThreads == HDAT_MAX_EIGHT_THREADS_SUPPORTED )
        {
            l_procStatus =
                HDAT_PROC_NOT_INSTALLED | HDAT_PRIM_THREAD | HDAT_EIGHT_THREAD;
        }
        else if ( l_enabledThreads == HDAT_MAX_FOUR_THREADS_SUPPORTED )
        {
            l_procStatus =
                HDAT_PROC_NOT_INSTALLED | HDAT_PRIM_THREAD | HDAT_FOUR_THREAD;
        }
        else if ( l_enabledThreads == HDAT_MAX_TWO_THREADS_SUPPORTED )
        {
            l_procStatus =
                HDAT_PROC_NOT_INSTALLED | HDAT_PRIM_THREAD | HDAT_TWO_THREAD;
        }
        else // Single threaded
        {
            l_procStatus =
                HDAT_PROC_NOT_INSTALLED | HDAT_PRIM_THREAD;
        }
        l_coreThreadCount = is_fused_mode() ? l_coreThreadCount*2 : l_coreThreadCount;
        HDAT_DBG("THREAD_COUNT is 0x%x",l_coreThreadCount);

        TARGETING::ATTR_LOCATION_CODE_type l_cur_location_code { };
        TARGETING::ATTR_LOCATION_CODE_type l_last_location_code { };
        uint8_t l_dcmNum = 0;

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
        if (l_fused_core_support == false)
        {
            for (;l_filter;++l_filter)
            {
                TARGETING::Target* l_pProcTarget = *l_filter;
                uint32_t Procstatus = 0;

                const uint8_t l_procTopologyId =
                    l_pProcTarget->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();

                // Fabric Node Id needs to get set according to the DCM number
                // that contains the processor chip
                hdatGetLocationCode(l_pProcTarget, HDAT_SLCA_FRU_TYPE_PROC,
                    l_cur_location_code);

                // Value of index is based on the proc numbers, so here
                // depending on the index, the first value is set and
                // consecutive dcm values are determined from location code
                // match result
                if ( (index !=0) &&
                      strcmp(l_cur_location_code, l_last_location_code)
                   )
                {
                    l_dcmNum++;
                }

                strcpy(l_last_location_code, l_cur_location_code);

                TARGETING::TargetHandleList l_coreList;
                TARGETING::getNonEcoCores(l_coreList,
                                          l_pProcTarget,
                                          false);

                for (uint32_t l_idx = 0; l_idx < l_coreList.size(); ++l_idx)
                {
                    HDAT_DBG("Core list size %d PCIA offset 0x%016llX",
                        l_coreList.size(),(uint64_t) &this->iv_spPcia[index]);
                    TARGETING::Target* l_pTarget = l_coreList[l_idx];
                    uint32_t l_coreNum =
                            l_pTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                    for ( uint32_t l_threadIndex=0;
                        l_threadIndex < l_enabledThreads; ++l_threadIndex)
                    {
                        l_errl = hdatSetCoreInfo(index,
                                            l_pTarget,l_pProcTarget, l_dcmNum);
                        if(l_errl)
                        {
                            HDAT_ERR("Error [0x%08X] in call to set core info",
                                                          l_errl->reasonCode());
                            break;
                        }
                        this->iv_spPcia[index].hdatThreadData.
                        pciaThreadData[l_threadIndex].pciaPhysThreadId =
                                                                l_threadIndex;

                        HDAT_DBG("HdatPcia thread idx %d, thread id %d ",
                        l_threadIndex, this->iv_spPcia[index].hdatThreadData.
                        pciaThreadData[l_threadIndex].pciaPhysThreadId);

                        /* Proc ID Reg for split core is SSSTTTTRPPPPPYY
                           Where           SSS   is spare id
                                                 and its zero, space left for
                                                 hardware changes
                                           TTTT  is topology id
                                           R     is reserved
                                           PPPPP is the core number
                                           YY    is thread id
                         */
                        // PIR generation for split core mode
                        const PIR_t pir(l_procTopologyId, l_coreNum,
                                l_threadIndex);
                        const uint32_t l_threadProcIdReg = pir.word;

                        HDAT_DBG("l_threadProcIdReg split core: 0x%.8X",
                            l_threadProcIdReg);

                        hdatSetPciaHdrs(&this->iv_spPcia[index]);
                        this->iv_spPcia[index].hdatCoreData.pciaProcStatus
                            = l_procStatus;
                        this->iv_spPcia[index].hdatThreadData.
                        pciaThreadData[l_threadIndex].pciaProcIdReg =
                        l_threadProcIdReg;

                        //This field is deprecated starting with P9
                        this->iv_spPcia[index].hdatThreadData.
                        pciaThreadData[l_threadIndex].pciaInterruptLine = 0;

                        Procstatus = isFunctional(l_pTarget) ?
                                           HDAT_PROC_USABLE :
                                           HDAT_PROC_NOT_USABLE;
                        l_procStatus &= ~HDAT_PROC_STAT_MASK;
                        l_procStatus |= Procstatus;

                        this->iv_spPcia[index].hdatCoreData.pciaProcStatus =
                        (static_cast<hdatProcStatus> (l_procStatus)
                        ) & HDAT_EXIST_FLAGS_MASK_FOR_PCIA;

                        // This field is deprecated starting with P9
                        this->iv_spPcia[index].hdatThreadData.
                        pciaThreadData[l_threadIndex].pciaIbaseAddr.hi  = 0;

                        // This field is deprecated starting with P9
                        this->iv_spPcia[index].hdatThreadData.
                        pciaThreadData[l_threadIndex].pciaIbaseAddr.lo  = 0;

                        if(HDAT_PROC_NOT_INSTALLED == (HDAT_PROC_STAT_BITS &
                            this->iv_spPcia[index].hdatCoreData.pciaProcStatus))
                        {
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CPU_TIME_BASE].hdatOffset = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CPU_TIME_BASE].hdatSize = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CACHE_SIZE].hdatOffset = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CACHE_SIZE].hdatSize = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CPU_ATTRIBUTES].hdatOffset = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CPU_ATTRIBUTES].hdatSize = 0;
                        }
                        // Need to setup header information for Thread Array Data
                        this->iv_spPcia[index].hdatThreadData.pciaThreadOffsetToData
                        = offsetof(hdatPciaThreadUniqueData_t, pciaThreadData);
                        this->iv_spPcia[index].hdatThreadData.pciaThreadNumEntries
                        = l_enabledThreads;
                        this->iv_spPcia[index].hdatThreadData.
                        pciaThreadSizeAllocated = sizeof(hdatPciaThreadArray_t);
                        this->iv_spPcia[index].hdatThreadData.pciaThreadSizeActual =
                        sizeof(hdatPciaThreadArray_t);

                    }
                    if(NULL != l_errl)
                    {
                        //Break if there is an error
                        HDAT_ERR("Error [0x%08X] in call to get chip parent failed",
                                                l_errl->reasonCode());
                        break;
                    }
                    index++;
                    if ((HDAT_RESERVE_FOR_CCM == (HDAT_RESERVE_FOR_CCM &
                    this->iv_spPcia[index].hdatCoreData.pciaProcStatus))||
                    (HDAT_PROC_NOT_INSTALLED != (HDAT_PROC_STAT_BITS &
                    this->iv_spPcia[index].hdatCoreData.pciaProcStatus)))
                    {
                        // The PCIA is a fixed size, but wanted it padded to a 128
                        // byte boundary
                        uint32_t l_rem=0, l_pad=0;
                        l_rem=0; l_pad=0;
                        // Pad to 128 bytes
                        l_rem = this->iv_spPcia[index-1].hdatHdr.hdatSize % 128;
                        l_pad = l_rem ? (128 - l_rem ) : 0;
                        uint8_t *l_addr=
                        reinterpret_cast<uint8_t *> (this->iv_spPcia);
                        // padding is allocated for size of PCIA entry. If it was
                        // smaller than 128 bytes, then you may need to bump it up
                        l_addr += l_pad;
                        this->iv_spPcia  =
                            reinterpret_cast<hdatSpPcia_t *>(l_addr);
                    }
                }
                if(NULL != l_errl)
                {
                    //Break if there is an error
                    break;
                }
            }
        }
        else
        {
            index = 0;
            for (;l_filter;++l_filter)
            {
                TARGETING::Target* l_pProcTarget = *l_filter;
                uint32_t l_procStatus = HDAT_PROC_USABLE;

                const uint8_t l_procTopologyId =
                    l_pProcTarget->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();

                // Fabric Node Id needs to get set according to the DCM number that
                // contains the processor chip
                hdatGetLocationCode(l_pProcTarget, HDAT_SLCA_FRU_TYPE_PROC,
                    l_cur_location_code);

                // Value of index is based on the proc numbers, so here
                // depending on the index, the first value is set and
                // consecutive dcm values are determined from location code
                // match result
                if ( (index !=0) &&
                      strcmp(l_cur_location_code, l_last_location_code)
                   )
                {
                    l_dcmNum++;
                }

                strcpy(l_last_location_code, l_cur_location_code);

                //Get the the EQ(Quad id) targets
                TARGETING::TargetHandleList l_eqList;
                TARGETING::PredicateCTM
                    l_eqFilter(TARGETING::CLASS_UNIT, TARGETING::TYPE_EQ);

                //Check the presence of EQs
                TARGETING::PredicateHwas l_predEqPresent;
                l_predEqPresent.present(true);

                TARGETING::PredicatePostfixExpr l_presentEq;
                l_presentEq.push(&l_eqFilter).push(&l_predEqPresent).And();

                TARGETING::targetService().getAssociated(
                    l_eqList,
                    l_pProcTarget,
                    TARGETING::TargetService::CHILD,
                    TARGETING::TargetService::ALL,
                    &l_presentEq);

                for(uint32_t l_eqIdx = 0; l_eqIdx < l_eqList.size();
                    ++l_eqIdx)
                {
                    TARGETING::Target* l_pTarget = l_eqList[l_eqIdx];

                    //Get the the FC targets
                    TARGETING::TargetHandleList l_fcList;
                    // Get the present (functional is not necessary) FC targets that don't have ECO CORE children.
                    TARGETING::getNonEcoFcs(l_fcList,
                                            l_pTarget,
                                            false);

                    HDAT_DBG("thread count :0x%.8X", l_coreThreadCount);
                    TARGETING::ATTR_CHIP_UNIT_type l_fcId = 0;
                    for(uint32_t l_fcIdx = 0; l_fcIdx < l_fcList.size();
                        ++l_fcIdx)
                    {
                        HDAT_DBG("PCIA offset 0x%016llX",
                            (uint64_t) &this->iv_spPcia[index]);

                        TARGETING::Target* l_pFcTarget = l_fcList[l_fcIdx];
                        l_fcId =
                            l_pFcTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                        //Resetting the proc status
                        l_procStatus = HDAT_PROC_USABLE;

                        l_errl = hdatSetCoreInfo(index, l_pFcTarget,
                                                 l_pProcTarget, l_dcmNum);
                        if(l_errl)
                        {
                            HDAT_ERR("Error [0x%08X] in call to set core info",
                                                          l_errl->reasonCode());
                            break;
                        }

                        for ( uint32_t l_threadIndex=0;
                            l_threadIndex < l_coreThreadCount; ++l_threadIndex)
                        {
                            this->iv_spPcia[index].hdatThreadData.
                            pciaThreadData[l_threadIndex].pciaPhysThreadId =
                                                                l_threadIndex;

                            HDAT_DBG("HdatPcia thread idx %d, thread id %d ",
                                l_threadIndex,
                                this->iv_spPcia[index].hdatThreadData.
                                pciaThreadData[l_threadIndex].pciaPhysThreadId);

                            /* Proc ID Reg for fused core is SSSTTTTRPPPPYYY
                               Where           SSS    is Spare Id
                                                      and its zero, space left
                                                      for hardware changes
                                               TTTT   is Topology id
                                               R      is reserved
                                               PPPP   is the core
                                                      chiplet pair number
                                               YYY    is thread id
                             */
                            uint32_t l_threadProcIdReg = 0;

                            // PIR generation for fused core mode
                            PIR_t pir(0);
                            pir.topologyIdFused = l_procTopologyId;
                            pir.coreIdFused = l_fcId;
                            pir.threadIdFused = l_threadIndex;
                            l_threadProcIdReg = pir.word;

                            HDAT_DBG("l_threadProcIdReg fused core: 0x%.8X",
                                l_threadProcIdReg);

                            this->iv_spPcia[index].hdatThreadData.
                                pciaThreadData[l_threadIndex].pciaProcIdReg =
                                l_threadProcIdReg;
                        }

                        if (l_pFcTarget->getAttr<TARGETING::ATTR_HWAS_STATE>
                            ().functional == false)
                        {
                            l_procStatus = HDAT_PROC_NOT_USABLE;
                        }

                        hdatSetPciaHdrs(&this->iv_spPcia[index]);
                            this->iv_spPcia[index].hdatCoreData.pciaProcStatus
                            = l_procStatus;

                        l_procStatus |= HDAT_EIGHT_THREAD;

                        uint32_t l_stat = this->iv_spPcia[index].hdatCoreData.
                            pciaProcStatus & HDAT_PROC_STAT_MASK;
                        this->iv_spPcia[index].hdatCoreData.pciaProcStatus =
                           (static_cast<hdatProcStatus> (l_procStatus)
                           | l_stat ) & HDAT_EXIST_FLAGS_MASK_FOR_PCIA;

                        if(HDAT_PROC_NOT_INSTALLED == (HDAT_PROC_STAT_BITS &
                        this->iv_spPcia[index].hdatCoreData.pciaProcStatus))
                        {
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CPU_TIME_BASE].hdatOffset = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CPU_TIME_BASE].hdatSize = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CACHE_SIZE].hdatOffset = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CACHE_SIZE].hdatSize = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CPU_ATTRIBUTES].hdatOffset = 0;
                            this->iv_spPcia[index].hdatPciaIntData
                                [HDAT_PCIA_DA_CPU_ATTRIBUTES].hdatSize = 0;
                        }
                        // Need to setup header information for
                        // Thread Array Data
                        this->iv_spPcia[index].hdatThreadData.pciaThreadOffsetToData
                        = offsetof(hdatPciaThreadUniqueData_t, pciaThreadData);
                        this->iv_spPcia[index].hdatThreadData.pciaThreadNumEntries
                            = l_coreThreadCount;
                        this->iv_spPcia[index].hdatThreadData.
                        pciaThreadSizeAllocated = sizeof(hdatPciaThreadArray_t);
                        this->iv_spPcia[index].hdatThreadData.pciaThreadSizeActual =
                            sizeof(hdatPciaThreadArray_t);
                        if(NULL != l_errl)
                        {
                            //Break if there is an error
                            HDAT_ERR("Error [0x%08X] in call to get chip parent failed",
                                     l_errl->reasonCode());
                            break;
                        }
                        index++;
                        if ((HDAT_RESERVE_FOR_CCM == (HDAT_RESERVE_FOR_CCM &
                            this->iv_spPcia[index].hdatCoreData.pciaProcStatus))||
                            (HDAT_PROC_NOT_INSTALLED != (HDAT_PROC_STAT_BITS &
                            this->iv_spPcia[index].hdatCoreData.pciaProcStatus)))
                        {
                            // The PCIA is a fixed size, but wanted it padded to a 128
                            // byte boundary
                            uint32_t l_rem=0, l_pad=0;
                            l_rem=0; l_pad=0;
                            // Pad to 128 bytes
                            l_rem = this->iv_spPcia[index-1].hdatHdr.hdatSize % 128;
                            l_pad = l_rem ? (128 - l_rem ) : 0;
                            uint8_t *l_addr=
                            reinterpret_cast<uint8_t *> (this->iv_spPcia);
                            // padding is allocated for size of PCIA entry. If it was
                            // smaller than 128 bytes, then you may need to bump it up
                            l_addr += l_pad;
                            this->iv_spPcia  =
                            reinterpret_cast<hdatSpPcia_t *>(l_addr);
                        }
                    } //End of EX list
                } //End of EQ list
                if(NULL != l_errl)
                {
                    //Break if there is an error
                    break;
                }
            } //End of Proc list
        }
        //End offset - starting offset divided by index
        //for calculating each PCIA size.
        o_size = ((uint64_t)&this->iv_spPcia[index] - l_offset)/index;
        o_count = index;
    }while(0);

    HDAT_EXIT();
    return l_errl;
}

/*******************************************************************************
*  hdatSetCoreInfo
*******************************************************************************/
errlHndl_t HdatPcia::hdatSetCoreInfo(const uint32_t i_index,
                                     const Target* i_pCoreTarget,
                                     const Target* i_pProcTarget,
                                     const uint8_t i_dcmNum)
{
    errlHndl_t l_errl = NULL;
    do
    {
        if(NULL == i_pCoreTarget)
        {
            HDAT_ERR("Input Target Pointer is NULL");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_PCIA_SET_CORE_INF
             * @reasoncode       HDAT::RC_INVALID_OBJECT
             * @userdata1        Index of proc target
             * @devdesc          Input Target Pointer is NULL
             * @custdesc         Firmware encountered an internal
             *                   error while retrieving target data
             */
            hdatBldErrLog(l_errl,
                    MOD_PCIA_SET_CORE_INF,
                    RC_INVALID_OBJECT,
                    i_index,0,0,0);
            break;
        }

        if((i_pCoreTarget->getAttr<ATTR_TYPE>() != TYPE_CORE) &&
            (i_pCoreTarget->getAttr<ATTR_TYPE>() != TYPE_FC))
        {
            HDAT_ERR("Input Target type is not valid");
            HDAT_ERR("Input Target type is not valid %x",
                   i_pCoreTarget->getAttr<ATTR_TYPE>());
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_PCIA_SET_CORE_INF
             * @reasoncode       HDAT::RC_INVALID_TGT_ATTR
             * @userdata1        Index of proc target
             * @userdata2        Target HUID
             * @devdesc          Invalid input target attribute
             * @custdesc         Firmware encountered an internal error
             *                   while retrieving attribute data
             */
            hdatBldErrLog(l_errl,
                    MOD_PCIA_SET_CORE_INF,
                    RC_INVALID_TGT_ATTR,
                    i_index,get_huid(i_pCoreTarget),0,0);
            break;
        }
        TARGETING::Target *l_pSysTarget = NULL;
        (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

        // asserting
        assert(l_pSysTarget != NULL);

        uint32_t l_procOrdId = i_pProcTarget->getAttr<ATTR_ORDINAL_ID>();

        uint32_t l_coreOrdId = i_pCoreTarget->getAttr<ATTR_ORDINAL_ID>();

        HDAT_DBG("proc ord ID:0x%08X, core ord ID:0x%08X",
                                                 l_procOrdId,l_coreOrdId);

        uint32_t l_HWCardId  =  0;
        l_errl = HDAT::hdatGetHwCardId(i_pProcTarget,l_HWCardId);
        if(NULL != l_errl)
        {
            HDAT_ERR("Error [0x%08X] in call to get card id failed",
                                                    l_errl->reasonCode());

            l_errl->addFFDC(HDAT_COMP_ID,AT,sizeof(AT),
                    HDAT_VERSION1,HDAT_PCIA_FFDC_SUBSEC);
            break;
        }
        HDAT_DBG("hw card ID:0x%08X", l_HWCardId);

        iv_spPcia[i_index].hdatCoreData.pciaHWCardID = l_HWCardId;

        TARGETING::TargetHandleList targetListNode;
        targetListNode.clear();
        getParentAffinityTargets(targetListNode,i_pCoreTarget,
                    TARGETING::CLASS_ENC,TARGETING::TYPE_NODE);
        if(targetListNode.empty())
        {
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_PCIA_SET_CORE_INF
             * @reasoncode       HDAT::RC_EMPTY_TARGET_LIST
             * @devdesc          Target List is Empty
             * @custdesc         Firmware encountered an internal
             *                   error while retrieving target data
             */
            hdatBldErrLog(l_errl,
                MOD_PCIA_SET_CORE_INF,
                RC_EMPTY_TARGET_LIST,
                0,0,0,0);
                break;
        }
        //get the parent node id
        Target* l_pNodeTarget = targetListNode[0];

        uint32_t l_nodeOrdId = l_pNodeTarget->getAttr<ATTR_ORDINAL_ID>();

        //Set the Internal Drawer Node ID as DCM number
        iv_spPcia[i_index].hdatCoreData.pciaDrawerNodeID = i_dcmNum;

        //get the parent node id and set that
        this->iv_spPcia[i_index].hdatCoreData.pciaDBOBID = l_nodeOrdId;

        //set the LCO target to 0
        this->iv_spPcia[i_index].hdatCoreData.pciaLCOTarget = 0;
        this->iv_spPcia[i_index].hdatCoreData.pciaCCMNodeID = l_nodeOrdId;
        //get the parent node id and set that

        //Ordinal Id of the fru containing this proc
        uint32_t l_fruOrdId = i_pProcTarget->getAttr<TARGETING::ATTR_FRU_ID>();
        this->iv_spPcia[i_index].hdatCoreData.pciaFruId = l_fruOrdId;

        //Module id is same as FRU Ordinal ID
        this->iv_spPcia[i_index].hdatCoreData.pciaModuleId = l_fruOrdId;

        //Ordinal ID of the core
        this->iv_spPcia[i_index].hdatCoreData.pciaHdwProcId = l_coreOrdId;

        uint32_t l_eclevel = 0;
        uint32_t l_chipId = 0;

        //Set the Chip EC level
        l_errl = HDAT::hdatGetIdEc(i_pProcTarget, l_eclevel, l_chipId);
        if(NULL != l_errl)
        {
            HDAT_ERR("Error [0x%08X] in call to get IdEc Failed",
                                                        l_errl->reasonCode());
            l_errl->addFFDC(HDAT_COMP_ID,AT,sizeof(AT),
                    HDAT_VERSION1,HDAT_PCIA_FFDC_SUBSEC);
            break;
        }
        iv_spPcia[i_index].hdatCoreData.pciaChipEcLvl = l_eclevel;

        //Ordinal id of the proc(chip)
        this->iv_spPcia[i_index].hdatCoreData.pciaChipId = l_procOrdId;

        //Set Clock Freq - Cycle Time in MHz
        iv_spPcia[i_index].hdatTime.pciaClockSpeed =
                     l_pSysTarget->getAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>();

        //CPU Time Base Structure
        uint32_t l_CycleTime = pow(2,34) /
            iv_spPcia[i_index].hdatTime.pciaClockSpeed;

        //Set Cycle Time
        iv_spPcia[i_index].hdatTime.pciaCycleTime = l_CycleTime;
        //Set Time Base - units of microseconds * 2^32
        iv_spPcia[i_index].hdatTime.pciaTimeBase =
                         i_pProcTarget->getAttr<TARGETING::ATTR_TIME_BASE>();
        // set the memory bus frequency
        iv_spPcia[i_index].hdatTime.pciaMemBusFreq = getMemBusFreq(i_pProcTarget);

        HDAT_INF("before setting cache info");
        //Set ICache Info
        //Cache Size Structure
        this->iv_spPcia[i_index].hdatCache.pciaICacheSize =
                 i_pProcTarget->getAttr<TARGETING::ATTR_ICACHE_SIZE>();
        HDAT_DBG("hdatCache.pciaICacheSize=0x%x",
                    this->iv_spPcia[i_index].hdatCache.pciaICacheSize);
        this->iv_spPcia[i_index].hdatCache.pciaICacheLineSize =
                 i_pProcTarget->getAttr<TARGETING::ATTR_ICACHE_LINE_SIZE>();
        HDAT_DBG("hdatCache.pciaICacheLineSize=0x%x",
                     this->iv_spPcia[i_index].hdatCache.pciaICacheLineSize);
        this->iv_spPcia[i_index].hdatCache.pciaICacheBlkSize =
                 i_pProcTarget->getAttr<TARGETING::ATTR_ICACHE_BLOCK_SIZE>();
        HDAT_DBG("hdatCache.pciaICacheBlkSize=0x%x",
                 this->iv_spPcia[i_index].hdatCache.pciaICacheBlkSize);

        this->iv_spPcia[i_index].hdatCache.pciaICacheAssocSets =
                 i_pProcTarget->getAttr<TARGETING::ATTR_ICACHE_ASSOC_SETS>();
        HDAT_DBG("hdatCache.pciaICacheAssocSets=0x%x",
                this->iv_spPcia[i_index].hdatCache.pciaICacheAssocSets);

        //Set DCache Info
        this->iv_spPcia[i_index].hdatCache.pciaDCacheBlkSize =
                 i_pProcTarget->getAttr<TARGETING::ATTR_DCACHE_LINE_SIZE>();
        HDAT_DBG("hdatCache.pciaDCacheBlkSize=0x%x",
                     this->iv_spPcia[i_index].hdatCache.pciaDCacheBlkSize);
        this->iv_spPcia[i_index].hdatCache.pciaDCacheAssocSets =
                 i_pProcTarget->getAttr<TARGETING::ATTR_DCACHE_ASSOC_SETS>();
        HDAT_DBG("hdatCache.pciaDCacheAssocSets=0x%x",
                      this->iv_spPcia[i_index].hdatCache.pciaDCacheAssocSets);


        //Set L1 Cache Info
        this->iv_spPcia[i_index].hdatCache.pciaL1DCacheSize =
                 i_pProcTarget->getAttr<TARGETING::ATTR_DATA_CACHE_SIZE>();
        HDAT_DBG("hdatCache.pciaL1DCacheSize=0x%x",
                      this->iv_spPcia[i_index].hdatCache.pciaL1DCacheSize);
        this->iv_spPcia[i_index].hdatCache.pciaL1DCacheLineSize =
                 i_pProcTarget->getAttr<TARGETING::ATTR_DATA_CACHE_LINE_SIZE>();
        HDAT_DBG("hdatCache.pciaL1DCacheLineSize=0x%x",
                      this->iv_spPcia[i_index].hdatCache.pciaL1DCacheLineSize);

        //Set L2 Cache Info
        this->iv_spPcia[i_index].hdatCache.pciaL2DCacheSize =
                  i_pProcTarget->getAttr<TARGETING::ATTR_L2_CACHE_SIZE>();
        HDAT_DBG("hdatCache.pciaL2DCacheSize=0x%x",
                     this->iv_spPcia[i_index].hdatCache.pciaL2DCacheSize);
        this->iv_spPcia[i_index].hdatCache.pciaL2DCacheLineSize =
                  i_pProcTarget->getAttr<TARGETING::ATTR_L2_CACHE_LINE_SIZE>();
        HDAT_DBG("hdatCache.pciaL2DCacheLineSize=0x%x",
               this->iv_spPcia[i_index].hdatCache.pciaL2DCacheLineSize);

        this->iv_spPcia[i_index].hdatCache.pciaL2AssocSets =
                  i_pProcTarget->getAttr<TARGETING::ATTR_L2_CACHE_ASSOC_SETS>();
        HDAT_DBG("hdatCache.pciaL2AssocSets=0x%x",
                 this->iv_spPcia[i_index].hdatCache.pciaL2AssocSets);

        //Set L3 Cache Info
        this->iv_spPcia[i_index].hdatCache.pciaL3DCacheSize =
            i_pProcTarget->getAttr<TARGETING::ATTR_L3_CACHE_SIZE>();
        HDAT_DBG("hdatCache.pciaL3DCacheSize=0x%x",
               this->iv_spPcia[i_index].hdatCache.pciaL3DCacheSize);
        this->iv_spPcia[i_index].hdatCache.pciaL3DCacheLineSize =
            i_pProcTarget->getAttr<TARGETING::ATTR_L3_CACHE_LINE_SIZE>();
        HDAT_DBG("hdatCache.pciaL3DCacheLineSize=0x%x",
               this->iv_spPcia[i_index].hdatCache.pciaL3DCacheLineSize);

        //ECO not supported initialize to 0
        this->iv_spPcia[i_index].hdatCache.pciaL3Pt5DCacheSize = 0;
        this->iv_spPcia[i_index].hdatCache.pciaL3Pt5DCacheLineSize = 0;

        //Set TLB info
        this->iv_spPcia[i_index].hdatCache.pciaITlbEntries =
                 i_pProcTarget->getAttr<TARGETING::ATTR_TLB_INSTR_ENTRIES>();
        HDAT_DBG("hdatCache.pciaITlbEntries=0x%x",
                       this->iv_spPcia[i_index].hdatCache.pciaITlbEntries);
        this->iv_spPcia[i_index].hdatCache.pciaITlbAssocSets =
                 i_pProcTarget->getAttr<TARGETING::ATTR_TLB_INSTR_ASSOC_SETS>();
        HDAT_DBG("hdatCache.pciaITlbAssocSets=0x%x",
                      this->iv_spPcia[i_index].hdatCache.pciaITlbAssocSets);

        this->iv_spPcia[i_index].hdatCache.pciaDTlbEntries =
                 i_pProcTarget->getAttr<TARGETING::ATTR_TLB_DATA_ENTRIES>();
        HDAT_DBG("hdatCache.pciaDTlbEntries=0x%x",
                        this->iv_spPcia[i_index].hdatCache.pciaDTlbEntries);
        this->iv_spPcia[i_index].hdatCache.pciaDTlbAssocSets =
                 i_pProcTarget->getAttr<TARGETING::ATTR_TLB_DATA_ASSOC_SETS>();
        HDAT_DBG("hdatCache.pciaDTlbAssocSets=0x%x",
                       this->iv_spPcia[i_index].hdatCache.pciaDTlbAssocSets);

        this->iv_spPcia[i_index].hdatCache.pciaReserveSize =
                 i_pProcTarget->getAttr<TARGETING::ATTR_TLB_RESERVE_SIZE>();
        HDAT_DBG("hdatCache.pciaReserveSize=0x%x",
                        this->iv_spPcia[i_index].hdatCache.pciaReserveSize);

        //Set CPU Attributes
        iv_spPcia[i_index].hdatAttr.pciaAttributes =
                        i_pProcTarget->getAttr<TARGETING::ATTR_CPU_ATTR>();
        HDAT_DBG("hdatAttr.pciaAttributes=0x%x",
                          iv_spPcia[i_index].hdatAttr.pciaAttributes );

    }
    while(0);

    return l_errl;
}

/*******************************************************************************
*  PCIA Destructor
*******************************************************************************/
HdatPcia :: ~HdatPcia()
{
    int rc = 0;
    rc =  mm_block_unmap(reinterpret_cast<void*>(ALIGN_PAGE_DOWN(
                    reinterpret_cast<uint64_t>(iv_spPcia))));
    if( rc != 0)
    {
        errlHndl_t l_errl = NULL;
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_PCIA_DESTRUCTOR
         * @reasoncode       HDAT::RC_DEV_MAP_FAIL
         * @devdesc          Unmap a mapped region failed
         * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(l_errl,
                MOD_PCIA_DESTRUCTOR,
                RC_DEV_MAP_FAIL,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }

}

} //namespace HDAT
