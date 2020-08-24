/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatspsubsys.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
/* [+] International Business Machines Corp.                              */
/* [+] Super Micro Computer, Inc.                                         */
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
 * @file hdatspsubsys.C
 *
 * @brief This file contains the implementation of the HdatSpSubsys class.
 *
 */


/*---------------------------------------------------------------------------*/
/* Includes                                                                  */
/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <sys/mm.h>
#include <sys/mmio.h>
#include <pnor/pnorif.H>
#include <lpc/lpc_const.H>
#include <console/uartif.H>
#include <ipmi/ipmiif.H>
#include <util/align.H>
#include "hdatspsubsys.H"
#include "hdathdif.H"
#include "hdatutil.H"
#include "hdatvpd.H"
#include <targeting/common/util.H>

using namespace TARGETING;

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Global variables                                                           */
/*----------------------------------------------------------------------------*/
uint32_t HdatSpSubsys::cv_actualCnt;


vpdData mvpdDataTable[] =
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

extern trace_desc_t *g_trac_hdat;

/**
 * @brief This routine fill up the SP I/O path information.
 *
 * @pre The o_pathArray must be set to zero.
 *
 * @post None
 *
 * @param l_pSpTarget  - input parameter - Target handle of the SP
 * @param o_arrayHdr   - output parameter - The I/O path array header structure
 * @param o_pathArray  - output parameter - The structure to update with the SP
 *                       I/O path information
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval
 */
static errlHndl_t hdatGetPathInfo(
                                  uint32_t &io_numOfIoPaths,
                                  hdatHDIFDataArray_t &o_arrayHdr,
                                  hdatSpIoPath_t o_pathArray[])
{

    HDAT_ENTER();

    errlHndl_t  l_errlHndl = NULL;

    // Set the number of Io Paths.
    // For now, we have only 1, may change in future
    io_numOfIoPaths = HDAT_NUM_IO_PATHS_FOR_BMC;

    // Set fields in the array header
    o_arrayHdr.hdatOffset    = sizeof(hdatHDIFDataArray_t);
    o_arrayHdr.hdatAllocSize = sizeof(hdatSpIoPath_t);
    o_arrayHdr.hdatActSize   = sizeof(hdatSpIoPath_t);
    o_arrayHdr.hdatArrayCnt  = 0;

    for( ; o_arrayHdr.hdatArrayCnt < io_numOfIoPaths ; )
    {
        o_pathArray[o_arrayHdr.hdatArrayCnt].
                                hdatPathType = HDAT_LPC_PATH_TYPE;
        o_pathArray[o_arrayHdr.hdatArrayCnt].
                                hdatLinkStatus = HDAT_CURRENT_LINK;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatML2ChipVer  = 0x10;

        // Get the master proc handle.

        TARGETING::Target* l_pMasterProcChipTargetHandle = NULL;
        (void)TARGETING::targetService().masterProcChipTargetHandle(
                                    l_pMasterProcChipTargetHandle);

        if (l_pMasterProcChipTargetHandle == NULL)
        {
            /*@
            * @errortype
            * @moduleid         HDAT::MOD_GET_PATH_INFO
            * @reasoncode       HDAT::RC_MASTER_PROC_TARGET_NULL
            * @devdesc          Master proc target returned is Null
            * @custdesc         Firmware encountered an internal
            *                   error while retrieving target handle
            */
            hdatBldErrLog(l_errlHndl,
                          MOD_GET_PATH_INFO,
                          RC_MASTER_PROC_TARGET_NULL,
                          0,0,0,0);

            HDAT_ERR("Master proc target handle is Null");
        }
        else
        {

            o_pathArray[o_arrayHdr.hdatArrayCnt].hdatProcChipId =
                l_pMasterProcChipTargetHandle->getAttr<ATTR_ORDINAL_ID>();

        }

        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatLPCHCBarIOAdrSpc =
                                                            LPC::LPCHC_IO_SPACE;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatLPCHCBarMemAdrSpc =
                                                            LPC::LPCHC_MEM_SPACE;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatLPCHCBarFwAdrSpc =
                                                         LPC::LPCHC_FW_SPACE;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatLPCHCBarIntRegSpc =
                                                         LPC::LPCHC_INT_REG_SPACE;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatLPCMCTPMemWinBar =
                                                      LPC::LPCHC_MCTP_PLDM_BASE;
#ifdef CONFIG_CONSOLE
        CONSOLE::UartInfo_t l_vuart1Info =
            CONSOLE::getUartInfo(CONSOLE::VUART1);

        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatBarOfVUART1Dev =
                                                    l_vuart1Info.lpcBaseAddr;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatSizeofVUART1AdrSpc =
                                                    l_vuart1Info.lpcSize;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatVUART1FreqHz =
                                                    l_vuart1Info.clockFreqHz;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatCurVUART1DevBaudRate =
                                                    l_vuart1Info.freqHz;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatVUART1InterruptDetails.
                                hdatUARTIntrNum = l_vuart1Info.interruptNum;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatVUART1InterruptDetails.
                                hdatTriggerType = l_vuart1Info.interruptTrigger;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatVUART1InterruptDetails.
                               hdatIsURARTValid = HDAT_UART_IS_VALID;
#endif

        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatKCSDataRegAddr =
                                                         LPC::KCS_DATA_REG;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatKCSStatusRegAddr =
                                                         LPC::KCS_STATUS_REG;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatKCSInterruptNum =
                                                         LPC::KCS_SERIAL_IRQ;

#ifdef CONFIG_CONSOLE
        CONSOLE::UartInfo_t l_vuart2Info =
            CONSOLE::getUartInfo(CONSOLE::VUART2);

        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatBarOfVUART2Dev =
                                                    l_vuart2Info.lpcBaseAddr;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatSizeofVUART2AdrSpc =
                                                    l_vuart2Info.lpcSize;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatVUART2FreqHz =
                                                    l_vuart2Info.clockFreqHz;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatCurVUART2DevBaudRate =
                                                    l_vuart2Info.freqHz;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatVUART2InterruptDetails.
                                hdatUARTIntrNum = l_vuart2Info.interruptNum;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatVUART2InterruptDetails.
                                hdatTriggerType = l_vuart2Info.interruptTrigger;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatVUART2InterruptDetails.
                               hdatIsURARTValid = HDAT_UART_IS_VALID;
#endif

// Enablng IPMI BT support in SP Subsystem
#ifdef CONFIG_BMC_IPMI
        IPMI::BmcInfo_t l_bmcInfo = IPMI::getBmcInfo();

        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatBarOfBTDev =
                                              l_bmcInfo.bulkTransferLpcBaseAddr;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatSizeofBTAdrSpc =
                                              l_bmcInfo.bulkTransferSize;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatBTInterruptDetails.
                                hdatSMSAttnIntrNum = l_bmcInfo.smsAttnInterrupt;
        o_pathArray[o_arrayHdr.hdatArrayCnt].hdatBTInterruptDetails.
                        hdatBMCtoHostRespIntrNum = l_bmcInfo.bmcToHostInterrupt;
#endif

        // LPC link doesn't have any FRU's in the path
        // except the end points Service Processor and master proc
        // The Fru's slca index should be populated for this entry by
        // starting from SP

        /* TARGETING::Target* l_lpcPathTargetsArray[] =
                           { i_pSpTarget , l_pMasterProcChipTargetHandle };
        uint32_t l_fruIdx = 0;
        for ( ; l_fruIdx < LPC_PATH_FRU_CNT_FOR_BMC ; l_fruIdx++)
        {
            o_pathArray[o_arrayHdr.hdatArrayCnt].hdatSlcaIdx[l_fruIdx] =
                l_lpcPathTargetsArray[l_fruIdx]->getAttr<ATTR_SLCA_INDEX>();
        }*/
        o_arrayHdr.hdatArrayCnt++;
    }

    HDAT_EXIT();
    return l_errlHndl;
}

/**
 * @brief This routine Loads SP Sub sys information.
 *
 * @param io_msAddr- input parameter - Mainstore address for SP subsys to write
 * @param o_spSubSysTotalSize - output parameter  Total size of sp sub sys
 * @param o_spSubsysCnt   - output parameter - Count of SP Sub sys structures
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval
 */

errlHndl_t HdatLoadSpSubSys(hdatMsAddr_t &io_msAddr,
                            uint32_t &o_spSubSysTotalSize,
                            uint32_t &o_spSubsysCnt)
{
    errlHndl_t l_errlHndl = NULL;
    hdatMsAddr_t l_msAddr = io_msAddr;

    HDAT_ENTER();


    HdatSpSubsys l_hdatSpSubsys(l_errlHndl, l_msAddr);

    // Iterate through the SP targets and fill the SP sub sys
    // structure for each SP
   /* do{
        TARGETING::PredicateCTM l_spFilter(CLASS_CHIP, TYPE_SP, MODEL_BMC);
        TARGETING::PredicateHwas l_pred;
        l_pred.present(true);
        TARGETING::PredicatePostfixExpr l_presentSp;
        l_presentSp.push(&l_spFilter).push(&l_pred).And();

        TARGETING::TargetRangeFilter l_filter(
                            TARGETING::targetService().begin(),
                            TARGETING::targetService().end(),
                            &l_presentSp);
        for( ; l_filter ; ++l_filter )
        {
            TARGETING::Target* l_pSpTarget = *l_filter;

            HdatSpSubsys l_hdatSpSubsys(l_errlHndl, l_msAddr); */

            if( l_errlHndl )
            {
                // Break the loop and return the error
                HDAT_ERR("Got an error while filling sp sub sys"
                         " for sp: 0x%x", o_spSubsysCnt);
                // break;
            }
            else
            {
                // Update the count and msaddr before continuing
                // the loop for next SP.
                memcpy(&io_msAddr , &l_msAddr , sizeof(hdatMsAddr_t));
                o_spSubsysCnt++;
                o_spSubSysTotalSize += l_hdatSpSubsys.getSpSubSysStructSize();;
            }

        //}
    //}while(0);

    HDAT_EXIT();
    return l_errlHndl;
}


/** @brief See the prologue in hdatspsubsys.H
 */
HdatSpSubsys::HdatSpSubsys(errlHndl_t &o_errlHndl,
                           hdatMsAddr_t &io_msAddr
                            ):
                           HdatHdif(o_errlHndl, HDAT_STRUCT_NAME,
                           HDAT_SPSUBSYS_LAST, cv_actualCnt++, HDAT_NO_CHILD,
                           HDAT_SP_SUBSYS_VERSION), iv_kwdSize(0),
                           iv_kwd(NULL),iv_ioPathArray(NULL),
                           iv_spSubsys(NULL),iv_size(0),
                           iv_numOfIoPaths(0)
{

    HDAT_ENTER();

    // Copy the input phy address to this object member variable
    iv_msAddr  = ((uint64_t) io_msAddr.hi << 32) | io_msAddr.lo;

    do{
        // Fill the internal data pointers
        o_errlHndl = this->hdatFillDataPtrs();
        if(o_errlHndl)
        {
            HDAT_ERR("Error while filling internal data ptrs for SP subsys");
            break;
        }

        // Size of the SP sub sys structure
        iv_size  = sizeof(hdatHDIF_t) +
                         ( sizeof(hdatHDIFDataHdr_t) *
                           HDAT_SPSUBSYS_NUM_DATA_PTRS)+
                         sizeof(hdatFruId_t) +
                         iv_kwdSize +
                         sizeof(hdatSpImpl_t) +
                         sizeof(hdatSpMem_t) +
                         sizeof(hdatHDIFDataArray_t) +
                         (sizeof(hdatSpIoPath_t) * iv_numOfIoPaths);

        uint64_t l_base_addr_down = ALIGN_PAGE_DOWN(iv_msAddr);
        uint8_t *l_virt_addr =
                        (uint8_t *) mm_block_map (
                        reinterpret_cast<void*>(l_base_addr_down),
                        (ALIGN_PAGE(iv_size) + PAGESIZE));
        iv_spSubsys = l_virt_addr + (iv_msAddr - ALIGN_PAGE_DOWN(iv_msAddr));

        // initializing the space to zero
        memset(iv_spSubsys ,0x0, iv_size );

        iv_spSubsys = this->setHdif(iv_spSubsys);

        memcpy(iv_spSubsys, &iv_fru, sizeof(hdatFruId_t));
        iv_spSubsys += sizeof(hdatFruId_t);

        memcpy(iv_spSubsys, iv_kwd, iv_kwdSize);
        iv_spSubsys += iv_kwdSize;

        memcpy(iv_spSubsys, &iv_impl, sizeof(hdatSpImpl_t));
        iv_spSubsys += sizeof(hdatSpImpl_t);

        memcpy(iv_spSubsys, &iv_mem, sizeof(hdatSpMem_t));
        iv_spSubsys += sizeof(hdatSpMem_t);

        memcpy(iv_spSubsys , &iv_ioPathArrayHdr, sizeof(hdatHDIFDataArray_t));
        iv_spSubsys += sizeof(hdatHDIFDataArray_t);

        memcpy(iv_spSubsys, iv_ioPathArray,
            sizeof(hdatSpIoPath_t) * iv_numOfIoPaths);
        iv_spSubsys += sizeof(hdatSpIoPath_t) * iv_numOfIoPaths;

        // update the base address for next SP sub sys
        uint64_t l_msAddrEnd = iv_msAddr + iv_size;

        memcpy(&io_msAddr, &l_msAddrEnd, sizeof(hdatMsAddr_t));

    } while(0);

    HDAT_EXIT();
    return;
}

errlHndl_t HdatSpSubsys::hdatFillDataPtrs()
{
    errlHndl_t l_errlHndl = NULL;

    HDAT_ENTER();

    do{
        // Initialize  all the values to zero
        memset(&iv_impl , 0x0 , sizeof(hdatSpImpl_t));
        memset(&iv_fru, 0x0 , sizeof(hdatFruId_t));
        memset(&iv_mem, 0x0 , sizeof(hdatSpMem_t));

        // Fill the SP impl data
        iv_impl.hdatHdwVer = 0x0003;
        iv_impl.hdatSftVer = 0x0002;
        iv_impl.hdatChipVer = 0x10;
        iv_impl.hdatStatus = HDAT_SP_INSTALLED;
            iv_impl.hdatStatus |= HDAT_SP_PRIMARY;
            iv_impl.hdatStatus |=  HDAT_SP_FUNCTIONAL;

        TARGETING::PredicateCTM l_bmcFilter(CLASS_SP, TYPE_BMC, MODEL_AST2500);
        TARGETING::PredicateHwas l_pred;
        l_pred.present(true);
        TARGETING::PredicatePostfixExpr l_presentSp;
        l_presentSp.push(&l_bmcFilter).push(&l_pred).And();

        TARGETING::TargetRangeFilter l_filter(
                            TARGETING::targetService().begin(),
                            TARGETING::targetService().end(),
                            &l_presentSp);

        // As of now we are not supporting any other bmc stacks.
        // But there is a scope for improvement here by using
        // data driven approach. TODO : RTC@166476
        if(l_filter)
        {
           TARGETING::ATTR_BMC_MANUFACTURER_type l_bmcManufacturer;
           l_filter->
              tryGetAttr<TARGETING::ATTR_BMC_MANUFACTURER>(l_bmcManufacturer);

           TARGETING::ATTR_BMC_HW_CHIP_TYPE_type l_bmcHwChip;
           l_filter->tryGetAttr<TARGETING::ATTR_BMC_HW_CHIP_TYPE>(l_bmcHwChip);

           TARGETING::ATTR_BMC_SW_TYPE_type l_bmcSw;
           l_filter->tryGetAttr<TARGETING::ATTR_BMC_SW_TYPE>(l_bmcSw);

           strcpy( iv_impl.hdatBmcFamily , l_bmcManufacturer);
           strcat( iv_impl.hdatBmcFamily , ",");
           strcat( iv_impl.hdatBmcFamily , l_bmcHwChip);
           strcat( iv_impl.hdatBmcFamily , ",");
           strcat( iv_impl.hdatBmcFamily , l_bmcSw);
        }
        else
        {
           strcpy( iv_impl.hdatBmcFamily , "ibm,ast2600,openbmc");
        }

        // Fill the FRU data
        iv_fru.hdatSlcaIdx = 0;
        iv_fru.hdatResourceId = 0;

        // Fill the SP memory info
        PNOR::SectionInfo_t l_info;
        l_errlHndl = PNOR::getSectionInfo(PNOR::NVRAM, l_info);
        if(l_errlHndl)
        {
            HDAT_ERR("PNOR::getSectionInfo returns error. Fill the size as 0");
            iv_mem.hdatHostRamSize = 0;
        }
        else
        {
            iv_mem.hdatHostRamSize = l_info.size;
        }

        //TODO: RTC Story 246515 Miscellaneous Rainier Changes
        iv_mem.hdatHostRamSize = 0x0110b000;
        HDAT_DBG(" hdatHostRamSize:0X%08X", iv_mem.hdatHostRamSize);

        // Fill the SP I/O path information

        iv_ioPathArray = reinterpret_cast<hdatSpIoPath_t *>(calloc(
                         HDAT_MAX_NUM_IO_PATHS,sizeof(hdatSpIoPath_t)));
        // No need to check iv_ioPathArray because calloc won't return if out of memory.

        l_errlHndl = hdatGetPathInfo(
                                     iv_numOfIoPaths,
                                     iv_ioPathArrayHdr,
                                     iv_ioPathArray);
        HDAT_DBG(" Num of Io Paths returned : %d", iv_numOfIoPaths);
        if(l_errlHndl)
        {
            HDAT_ERR("hdatGetPathInfo returns Error");
            break;
        }

        // Fill the kwd

        // As of now there is no VPD present on BMC.
        // Hence we are filling PROC data to get things moving.
        // TODO : RTC : 151618 Will relook at this once we get mail from Tom.


        TARGETING::Target* l_pMasterProcChipTargetHandle = NULL;
        (void)TARGETING::targetService().masterProcChipTargetHandle(
                                l_pMasterProcChipTargetHandle);

        if (l_pMasterProcChipTargetHandle == NULL)
        {
            /*@
            * @errortype
            * @moduleid         HDAT::MOD_HDAT_SP_SUBSYS_CTOR
            * @reasoncode       HDAT::RC_MASTER_PROC_TARGET_NULL
            * @devdesc          Master proc target returned is Null
            * @custdesc         Firmware encountered an internal
            *                   error while retrieving target data
            */
            hdatBldErrLog(l_errlHndl,
                          MOD_GET_PATH_INFO,
                          RC_MASTER_PROC_TARGET_NULL,
                          0,0,0,0);

            HDAT_ERR("Master proc target handle is Null");
            break;
        }
        else
        {
            uint32_t l_num = sizeof(mvpdDataTable) / sizeof(vpdData);
            size_t theSize[l_num];
            HDAT_DBG(" spsubsys number of vpd : %X", l_num);
            l_errlHndl =  hdatGetAsciiKwd(l_pMasterProcChipTargetHandle,
                                          iv_kwdSize,
                                          iv_kwd,
                                          HDAT::PROC,
                                          mvpdDataTable,
                                          l_num,theSize,
                                          l_mvpdKeywords);
            HDAT_DBG(" initial size vpd  : %X", iv_kwdSize);
            if(l_errlHndl)
            {
                HDAT_ERR("hdatGetAsciiKwd returns Error");
                break;
            }
            char *o_fmtKwd;
            uint32_t o_fmtkwdSize;
            l_errlHndl = hdatformatAsciiKwd(mvpdDataTable, l_num, theSize,
                            iv_kwd, iv_kwdSize, o_fmtKwd,
                            o_fmtkwdSize, l_mvpdKeywords);
            if( o_fmtKwd != NULL )
            {
                delete[] iv_kwd;
                iv_kwd = new char [o_fmtkwdSize + 8];
                memcpy(iv_kwd,o_fmtKwd,o_fmtkwdSize);
                iv_kwdSize = o_fmtkwdSize + 8;
                delete[] o_fmtKwd;
            }
        }

        // Done with getting all the data. Now its time to Add.
        if( l_errlHndl == NULL )
        {
            this->addData(HDAT_SPSUBSYS_FRU_ID, sizeof(hdatFruId_t));
            this->addData(HDAT_SPSUBSYS_KWD, iv_kwdSize);
            this->addData(HDAT_SPSUBSYS_IMPL, sizeof(hdatSpImpl_t));
            this->addData(HDAT_SPSUBSYS_DEPRECATED, 0);  // Still need to account for the deprecated pointer pair

            this->addData(HDAT_SPSUBSYS_MEMORY, sizeof(hdatSpMem_t));
            this->addData(HDAT_SPSUBSYS_IO_PATH, sizeof(hdatHDIFDataArray_t) +
                    sizeof(hdatSpIoPath_t) * iv_ioPathArrayHdr.hdatArrayCnt);

            this->align();
        }

    }while(0);
    HDAT_EXIT();
    return l_errlHndl;
}

/** @brief get the sp sub sys structure total size
*/
uint32_t HdatSpSubsys::getSpSubSysStructSize()
{
    return iv_size;
}


/** @brief See the prologue in hdathdatspsubsys.H
 */
HdatSpSubsys::~HdatSpSubsys()
{
    errlHndl_t o_errlHndl=NULL;

    HDAT_ENTER();

    // Free the memory allocated for filling this entry.
    int rc=0;
    free(iv_ioPathArray);
    delete[] iv_kwd;
    rc =  mm_block_unmap(reinterpret_cast<void*>(
                        ALIGN_PAGE_DOWN((uint64_t)iv_spSubsys)));
    if( rc != 0)
    {
        /*@
        * @errortype
        * @moduleid         HDAT::MOD_HDAT_SP_SUBSYS_DTOR
        * @reasoncode       HDAT::RC_DEV_MAP_FAIL
        * @devdesc          Unmap a mapped region failed
        * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(o_errlHndl,
                HDAT::MOD_HDAT_SP_SUBSYS_DTOR,
                RC_DEV_MAP_FAIL,
                rc,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }

    HDAT_EXIT();
    return;
}


} // end namespace
