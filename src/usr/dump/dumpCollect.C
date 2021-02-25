/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/dump/dumpCollect.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

#include <sys/mmio.h>
#include "dumpCollect.H"
#include <dump/dumpreasoncodes.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/attrrp.H>
#include <runtime/runtime.H>
#include <util/align.H>
#include <util/utilrsvdmem.H>
#include <sys/mm.h>
#include <sys/misc.h>
#include <sys/internode.h>
#include <arch/memorymap.H>
#include <usr/vmmconst.h>
#include <dump/dumpif.H>
#include <util/utiltce.H>
#include <isteps/mem_utils.H>
#include <string.h>
#include <stdio.h>
#include <sys/msg.h>                     //  message Q's
#include <mbox/mbox_queues.H>            //
#include <kernel/vmmmgr.H>
#include <targeting/targplatutil.H>

// Trace definition
trace_desc_t* g_trac_dump = NULL;
TRAC_INIT(&g_trac_dump, "DUMP", 4*KILOBYTE);

#define IGNORE_HRMOR 0x8000000000000000
#define SBE_FFDC_SIZE 128
#define SIZE_TIMA_REG 8
#define SPR_ID_TYPE_NAME 0
//Minimum space required for Master Fused Core
//and its 8 threads
#define HYP_REQUIRED_MIN_REG_SIZE 0x5BC0

namespace DUMP
{
////////////
// Define an SPR number to name str map.  Note that this inverse of how
// the HWP uses it... so use the same mechanism/data - just inverse
std::map<uint32_t, const char*> SPRNUM_MAP;
typedef std::map<uint32_t, const char*>::iterator SPRNUM_MAP_IT;

#define LIST_SPR_NAME_REG(_op_)\
    _op_(XER      ,1   )\
    _op_(DSCR_RU  ,3   )\
    _op_(LR       ,8   )\
    _op_(CTR      ,9   )\
    _op_(UAMR     ,13  )\
    _op_(DSCR     ,17  )\
    _op_(DSISR    ,18  )\
    _op_(DAR      ,19  )\
    _op_(DEC      ,22  )\
    _op_(SDR1     ,25  )\
    _op_(SRR0     ,26  )\
    _op_(SRR1     ,27  )\
    _op_(CFAR     ,28  )\
    _op_(AMR      ,29  )\
    _op_(PIDR     ,48  )\
    _op_(IAMR     ,61  )\
    _op_(TFHAR    ,128 )\
    _op_(TFIAR    ,129 )\
    _op_(TEXASR   ,130 )\
    _op_(TEXASRU  ,131 )\
    _op_(CTRL_RU  ,136 )\
    _op_(TIDR     ,144 )\
    _op_(CTRL     ,152 )\
    _op_(FSCR     ,153 )\
    _op_(UAMOR    ,157 )\
    _op_(GSR      ,158 )\
    _op_(PSPB     ,159 )\
    _op_(DPDES    ,176 )\
    _op_(DAWR0    ,180 )\
    _op_(DAWR1    ,181 )\
    _op_(RPR      ,186 )\
    _op_(CIABR    ,187 )\
    _op_(DAWRX0   ,188 )\
    _op_(DAWRX1   ,189 )\
    _op_(HFSCR    ,190 )\
    _op_(VRSAVE   ,256 )\
    _op_(SPRG3_RU ,259 )\
    _op_(TB       ,268 )\
    _op_(TBU_RU   ,269 )\
    _op_(SPRG0    ,272 )\
    _op_(SPRG1    ,273 )\
    _op_(SPRG2    ,274 )\
    _op_(SPRG3    ,275 )\
    _op_(SPRC     ,276 )\
    _op_(SPRD     ,277 )\
    _op_(CIR      ,283 )\
    _op_(TBL      ,284 )\
    _op_(TBU      ,285 )\
    _op_(TBU40    ,286 )\
    _op_(PVR      ,287 )\
    _op_(HSPRG0   ,304 )\
    _op_(HSPRG1   ,305 )\
    _op_(HDSISR   ,306 )\
    _op_(HDAR     ,307 )\
    _op_(SPURR    ,308 )\
    _op_(PURR     ,309 )\
    _op_(HDEC     ,310 )\
    _op_(HRMOR    ,313 )\
    _op_(HSRR0    ,314 )\
    _op_(HSRR1    ,315 )\
    _op_(TFMR     ,317 )\
    _op_(LPCR     ,318 )\
    _op_(LPIDR    ,319 )\
    _op_(HMER     ,336 )\
    _op_(HMEER    ,337 )\
    _op_(PCR      ,338 )\
    _op_(HEIR     ,339 )\
    _op_(AMOR     ,349 )\
    _op_(TIR      ,446 )\
    _op_(HDEXCR_RU,455 )\
    _op_(PTCR     ,464 )\
    _op_(HDEXCR   ,471 )\
    _op_(USPRG0   ,496 )\
    _op_(USPRG1   ,497 )\
    _op_(UDAR     ,499 )\
    _op_(SEIDR    ,504 )\
    _op_(URMOR    ,505 )\
    _op_(USRR0    ,506 )\
    _op_(USRR1    ,507 )\
    _op_(UEIR     ,509 )\
    _op_(ACMCR    ,510 )\
    _op_(SMFCTRL  ,511 )\
    _op_(SIERA_RU ,736 )\
    _op_(SIERB_RU ,737 )\
    _op_(MMCR3_RU ,738 )\
    _op_(SIERA    ,752 )\
    _op_(SIERB    ,753 )\
    _op_(MMCR3    ,754 )\
    _op_(SIER_RU  ,768 )\
    _op_(MMCR2_RU ,769 )\
    _op_(MMCRA_RU ,770 )\
    _op_(PMC1_RU  ,771 )\
    _op_(PMC2_RU  ,772 )\
    _op_(PMC3_RU  ,773 )\
    _op_(PMC4_RU  ,774 )\
    _op_(PMC5_RU  ,775 )\
    _op_(PMC6_RU  ,776 )\
    _op_(MMCR0_RU ,779 )\
    _op_(SIAR_RU  ,780 )\
    _op_(SDAR_RU  ,781 )\
    _op_(MMCR1_RU ,782 )\
    _op_(SIER     ,784 )\
    _op_(MMCR2    ,785 )\
    _op_(MMCRA    ,786 )\
    _op_(PMC1     ,787 )\
    _op_(PMC2     ,788 )\
    _op_(PMC3     ,789 )\
    _op_(PMC4     ,790 )\
    _op_(PMC5     ,791 )\
    _op_(PMC6     ,792 )\
    _op_(MMCR0    ,795 )\
    _op_(SIAR     ,796 )\
    _op_(SDAR     ,797 )\
    _op_(MMCR1    ,798 )\
    _op_(IMC      ,799 )\
    _op_(BESCRS   ,800 )\
    _op_(BESCRSU  ,801 )\
    _op_(BESCRR   ,802 )\
    _op_(BESCRRU  ,803 )\
    _op_(EBBHR    ,804 )\
    _op_(EBBRR    ,805 )\
    _op_(BESCR    ,806 )\
    _op_(DEXCR_RU ,812 )\
    _op_(LMRR     ,813 )\
    _op_(LMSER    ,814 )\
    _op_(TAR      ,815 )\
    _op_(ASDR     ,816 )\
    _op_(PSSCR_SU ,823 )\
    _op_(DEXCR    ,828 )\
    _op_(IC       ,848 )\
    _op_(VTB      ,849 )\
    _op_(LDBAR    ,850 )\
    _op_(MMCRC    ,851 )\
    _op_(PMSR     ,853 )\
    _op_(PMMAR    ,854 )\
    _op_(PSSCR    ,855 )\
    _op_(L2QOSR   ,861 )\
    _op_(WORC     ,863 )\
    _op_(TRIG0    ,880 )\
    _op_(TRIG1    ,881 )\
    _op_(TRIG2    ,882 )\
    _op_(PMCR     ,884 )\
    _op_(RWMR     ,885 )\
    _op_(WORT     ,895 )\
    _op_(PPR      ,896 )\
    _op_(PPR32    ,898 )\
    _op_(TSCR     ,921 )\
    _op_(TTR      ,922 )\
    _op_(TRACE    ,1006)\
    _op_(HID      ,1008)\
    _op_(PIR      ,1023)\
    _op_(NIA      ,2000)\
    _op_(MSRD     ,2001)\
    _op_(CR       ,2002)\
    _op_(FPSCR    ,2003)\
    _op_(VSCR     ,2004)\
    _op_(MSR      ,2005)\
    _op_(MSR_L1   ,2006)\
    _op_(MSRD_L1  ,2007)



#define DO_SPRNUM_MAP(in_name, in_number)\
    SPRNUM_MAP[in_number] = #in_name;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

errlHndl_t doDumpCollect(void)
{
    TRACFCOMP(g_trac_dump, "doDumpCollect - start ");
    errlHndl_t l_err = NULL;

    // Table Sizes
    uint64_t srcTableSize = 0;
    uint64_t destTableSize = 0;
    uint64_t resultsTableSize = 0;

    // Dump table struct pointers
    dumpEntry *srcTableEntry = NULL;
    dumpEntry *destTableEntry = NULL;
    resultsEntry *resultsTableEntry = NULL;

    do
    {
        // Get the Data pointers to the locations we need from HDAT
        //     MS_DUMP_SRC_TBL, < MDST: Memory Dump Source Table
        //     MS_DUMP_DST_TBL, < MDDT: Memory Dump Destination Table
        //     MS_DUMP_RESULTS_TBL,  <MDRT:Memory Dump Results Table
        l_err = getHostDataPtrs(srcTableEntry, srcTableSize,
                                destTableEntry, destTableSize,
                                resultsTableEntry, resultsTableSize);

        if (l_err)
        {
            TRACFCOMP(g_trac_dump, "doDumpCollect: Got an error back from getHostDataPtrs");
            break;
        }

        l_err = copySrcToDest(srcTableEntry,srcTableSize,
                              destTableEntry,destTableSize,
                              resultsTableEntry,resultsTableSize);

        if (l_err)
        {
            TRACFCOMP(g_trac_dump, "doDumpCollect: Got an error back from copySrcToDest");
            break;
        }

    }while (0);

    return (l_err);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Replace reg num with name
void replaceRegNumWithName( hostArchRegDataEntry *hostRegData )
{
    char str[sizeof(reg_t)];

    if(hostRegData->reg.type == DUMP_ARCH_REG_TYPE_GPR)
    {
        snprintf(str,sizeof(reg_t), "GPR%d\0", hostRegData->reg.num);
        strncpy(hostRegData->reg.name, str, sizeof(reg_t));
    }
    else if (hostRegData->reg.type == DUMP_ARCH_REG_TYPE_SPR)
    {
        if(SPRNUM_MAP.find(hostRegData->reg.num) != SPRNUM_MAP.end())
        {
            strncpy(hostRegData->reg.name, SPRNUM_MAP[hostRegData->reg.num], sizeof(reg_t));
        }
        //else unknown... leave as number for debug
    }
    else if (hostRegData->reg.type == DUMP_ARCH_REG_TYPE_TIMA)
    {
        snprintf(str,sizeof(reg_t), "TIMA%d\0", hostRegData->reg.num);
        strncpy(hostRegData->reg.name, str, sizeof(reg_t));
    }
    //else unknown type... leave as number for debug

}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Returns the physical address corresponding to a PHYP MDST/MDRT entry
void* getPhysAddr( uint64_t i_phypAddr )
{
    uint64_t phys_addr = 0;

    // Physical Address
    if( VmmManager::FORCE_PHYS_ADDR & i_phypAddr )
    {
        // lop off the top bit so our vmm code works
        phys_addr = (i_phypAddr & ~VmmManager::FORCE_PHYS_ADDR);
    }
    // Relative to PHYP HRMOR
    else
    {
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        // add the hrmor/payload_base to the value in the table
        TARGETING::ATTR_PAYLOAD_BASE_type payload_base
          = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        phys_addr = payload_base*MEGABYTE + i_phypAddr;
    }

    return reinterpret_cast<void*>(ALIGN_PAGE_DOWN(phys_addr));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t copyArchitectedRegs(void)
{
    errlHndl_t l_err = nullptr;
    int rc;
    // Processor dump area address and size from HDAT
    uint64_t procTableAddr = 0;
    uint64_t procTableSize = 0;
    // Pointer to architected register reserved memory
    void *pSrcAddrBase = nullptr;
    void *vMapSrcAddrBase = nullptr;
    // Pointers to Hypervisor allocated memory for register data content
    void *pDstAddrBase = nullptr;
    void *vMapDstAddrBase = nullptr;
    // Architected Reg Dump table struct pointers
    procDumpAreaEntry *procTableEntry = nullptr;

    //Setup SPR num to string mapping
    LIST_SPR_NAME_REG(DO_SPRNUM_MAP)

    do
    {
        uint8_t nodeId =  TARGETING::UTIL::getCurrentNodePhysId();
        TRACFCOMP(g_trac_dump, "copyArchitectedRegs - start, NodeId=0x%x ",nodeId);
        // Get the PROC_DUMP_AREA_TBL address from SPIRAH
        l_err = RUNTIME::get_host_data_section(RUNTIME::PROC_DUMP_AREA_TBL,
                                               0,
                                               procTableAddr,
                                               procTableSize);
        if (l_err)
        {
            // Got an errorlog back from get_host_data_sections
            TRACFCOMP(g_trac_dump, "copyArchitectedRegs get_host_data_sections "
                                   "for PDAT failed");
            break;
        }
        // If the address or size is zero - error out
        if ((procTableAddr == 0) || (procTableSize == 0))
        {
            // Invalid address or size
            TRACFCOMP(g_trac_dump, "copyArchitectedRegs address or size invalid"
                                   " for PDAT: addr =0x%X, size =0x%X,",
                                   procTableAddr, procTableSize);
            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_ARCH_REGS
             * @reasoncode   DUMP::DUMP_PDAT_INVALID_ADDR
             * @userdata1    Table address returned
             * @userdata2    Table size returned
             * @devdesc      Invalid address and size returned from HDAT
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_ARCH_REGS,
                                            DUMP_PDAT_INVALID_ADDR,
                                            procTableAddr,
                                            procTableSize,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Map processor dump area destination address to VA addresses
        procTableEntry = reinterpret_cast<procDumpAreaEntry *>(procTableAddr);

        //In case of HYP Pre-Init failure case , HYP does not allocate minimum memory on all nodes so node specific 
        //allocated size will be zero.In that case skip copying of data to HDAT and return to the caller.
        if( !procTableEntry->HypInitSuccess && (procTableEntry->iv_nodeSrcArcRegDataTOC[nodeId].dataSize == 0) )
        {
            TRACFCOMP(g_trac_dump, "Hypervisor Pre-Init failure scenario!! No memory "
                      "allocated for dump collection for Node:%d",nodeId);
            /*@
             * @errortype
             * @moduleid         DUMP::DUMP_ARCH_REGS
             * @reasoncode       DUMP::DUMP_PDAT_INSUF_SPACE_FOR_NODE
             * @userdata1        NODE ORDINAL ID
             * @devdesc          HYP Pre-Init scenario. No memory allocated for theode
             * @custdesc         Failure to collect some error data
             *                   following system error
             *
             */
            l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    DUMP_ARCH_REGS,
                    DUMP_PDAT_INSUF_SPACE_FOR_NODE,
                    nodeId);
            errlCommit(l_err, DUMP_COMP_ID);
            break;
        }
        pDstAddrBase = getPhysAddr(procTableEntry->iv_nodeSrcArcRegDataTOC
                       [nodeId].dataOffset);
        vMapDstAddrBase = mm_block_map(pDstAddrBase,
                          (ALIGN_PAGE(procTableEntry->iv_nodeSrcArcRegDataTOC
                          [nodeId].dataSize) + PAGESIZE));

        //Need to adjust actual virtual address due to mm_block_map only
        //mapping on page boundary to account for non page aligned addresses
        //from PHYP/OPAL
        uint64_t tmpAddr = reinterpret_cast<uint64_t>(vMapDstAddrBase);
        vMapDstAddrBase = reinterpret_cast<void*>(tmpAddr +
                          (procTableEntry->iv_nodeSrcArcRegDataTOC
                          [nodeId].dataOffset & (PAGESIZE-1)));

        // Map architected register reserved memory to VA addresses
        TARGETING::Target * l_sys = NULL;
        TARGETING::targetService().getTopLevelTarget( l_sys );
        assert(l_sys != NULL);
        //The ATTR_SBE_ARCH_DUMP_ADDR will be updated with Node specific value
        //in the forward IPL path. (populate_HbRsvMem)
        //eg:Node 0: 0xe6800000
        //   Node 1: 0x4000e6800000 etc
        auto srcAddr =
                  l_sys->getAttr<TARGETING::ATTR_SBE_ARCH_DUMP_ADDR>();
        pSrcAddrBase = reinterpret_cast<void * const>(srcAddr);
        vMapSrcAddrBase = mm_block_map(pSrcAddrBase,
                                       VMM_ARCH_REG_DATA_SIZE_ALL_PROC);

        TRACFCOMP(g_trac_dump, "Node level Source address (ATTR_SBE_ARCH_DUMP_ADDR)=[0x%16llx] "
                 "vMapSrcAddrBase=[%p], HYP assigned dest addr [0x%.16llx] pDstAddrBase=[%p] "
                 "vMapDstAddrBase=[%p]", srcAddr, vMapSrcAddrBase,procTableEntry->iv_nodeSrcArcRegDataTOC
                 [nodeId].dataOffset, pDstAddrBase, vMapDstAddrBase);

        // Get list of functional processor chips, in MPIPL path we
        // don't expect any deconfiguration
        TARGETING::TargetHandleList procChips;
        TARGETING::getAllChips( procChips, TARGETING::TYPE_PROC, true);


        uint64_t dstTempAddr = reinterpret_cast<uint64_t>(vMapDstAddrBase);
        procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataSize = 0;
        uint64_t allProcDataSize = 0; 
        for (uint32_t procNum = 0; procNum < procChips.size(); procNum++)
        {
            // Base addresses w.r.t PROC positions. This is static here
            // and used for reference below to calculate all other addresses
            uint64_t procSrcAddr = (reinterpret_cast<uint64_t>(vMapSrcAddrBase)+
                                    procNum * VMM_ARCH_REG_DATA_PER_PROC_SIZE);
            //Valid data will be post metadata structure
            procSrcAddr = procSrcAddr + sizeof(sbeArchHWDumpMetaData_t);
            TRACDCOMP(g_trac_dump, "Proc[%d] Data Source Address[%p]", procNum, procSrcAddr);
            TRACDCOMP(g_trac_dump, "VMM_ARCH_REG_DATA_PER_PROC_SIZE=0x%.8x",VMM_ARCH_REG_DATA_PER_PROC_SIZE);
            sbeArchRegDumpProcHdr_t *sbeProcHdr =
                       reinterpret_cast<sbeArchRegDumpProcHdr_t *>(procSrcAddr);
            uint16_t threadCount = sbeProcHdr->thread_cnt;
            uint16_t regCount = sbeProcHdr->reg_cnt;

            //FSP has a non-HW dump collection MPIPL flow. In that flow SBE is
            //not called to collect the  spr/gpr.There is no way for hostboot to
            //know , its non-hw dump mode of MPIPL. Hence check the thread count
            //and skip copying of the data.
            if(threadCount == 0)
             {
                 TRACFCOMP(g_trac_dump, "copyArchitectedRegs(): Data not not "
                 "collected by SBE coreCount=%d threadCount=%d and regCount=%d",
                  sbeProcHdr->core_cnt,threadCount,regCount);
                 continue;
             }

            //Validate the structure versions used by SBE and HB for sharing the
            //data
            if( sbeProcHdr->version != REG_DUMP_SBE_HB_STRUCT_VER )
            {
                /*@
                 * @errortype
                 * @moduleid     DUMP::DUMP_ARCH_REGS
                 * @reasoncode   DUMP::DUMP_PDAT_VERSION_MISMATCH
                 * @userdata1    Structure version obtained from SBE
                 * @userdata2    Structure version supported by HB
                 * @devdesc      Mismatch between the version of structure
                 *               supported by both SBE and HB.
                 *
                 */
                l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        DUMP_ARCH_REGS,
                        DUMP_PDAT_VERSION_MISMATCH,
                        sbeProcHdr->version,
                        REG_DUMP_SBE_HB_STRUCT_VER,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                errlCommit(l_err, DUMP_COMP_ID);
                break;
            }

            //Update the data source address to point to the thread specific
            //header data obtained by SBE
            procSrcAddr = reinterpret_cast<uint64_t>(procSrcAddr +
                                               sizeof(sbeArchRegDumpProcHdr_t));

            procTableEntry->threadRegSize = sizeof(hostArchRegDataHdr)+
                                      (regCount * sizeof(hostArchRegDataEntry));
            procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataSize =
                      procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataSize +
                      (procTableEntry->threadRegSize * threadCount);


            bool collectMinimumDataMode = false;
            //Check if PHYP initialization was successfull.
            //In case of Hypervisor pre-init failure, Hypervisor allocates memory to save off
            //first fused core data
            if(!procTableEntry->HypInitSuccess)
            {
                //HYP Pre-Init Failure cause.
                collectMinimumDataMode = true;
                //Data will be collected only for Master fused core of master proc
                //Update the procDumpAreaEntry entries accordingly
                threadCount = 8;//Fused core.
                procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataSize =
                                                  (procTableEntry->threadRegSize * threadCount);
            }

            if(procTableEntry->iv_nodeSrcArcRegDataTOC[nodeId].dataSize <
                                  procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataSize)
            {
                TRACFCOMP(g_trac_dump, "Insufficient space detected, HYP Reserved Size=0x%.8x, "
                "actual  size=0x%.8x and Hypervisor Pre-Init failure(%d)",
                procTableEntry->iv_nodeSrcArcRegDataTOC[nodeId].dataSize,
                procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataSize,collectMinimumDataMode);
                /*@
                 * @errortype
                 * @moduleid         DUMP::DUMP_ARCH_REGS
                 * @reasoncode       DUMP::DUMP_PDAT_INSUFFICIENT_SPACE
                 * @userdata1[00:31] Hypervisor reserved memory size
                 * @userdata1[32:63] Memory needed to copy architected
                 *                   register data
                 * @userdata2        Minimum memory required for copy architected
                 *                   register data(PRE_INIT failure case)
                 * @devdesc          Insufficient space to copy architected
                 *                   registers
                 * @custdesc         Failure to collect some error data
                 *                   following system error
                 *
                 */
                l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        DUMP_ARCH_REGS,
                        DUMP_PDAT_INSUFFICIENT_SPACE,
                        TWO_UINT32_TO_UINT64(procTableEntry->iv_nodeSrcArcRegDataTOC[nodeId].dataSize,
                                       procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataSize),
                        HYP_REQUIRED_MIN_REG_SIZE,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                errlCommit(l_err, DUMP_COMP_ID);
                break;
            }

            TRACFCOMP(g_trac_dump, "HYP Reserved Size=0x%.8x, actual size=0x%.8x and "
            "Hypervisor Pre-Init failure(%d)", procTableEntry->iv_nodeSrcArcRegDataTOC[nodeId].dataSize,
            procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataSize,collectMinimumDataMode);
            // Total Number of Threads possible in one Proc
            for(uint32_t idx = 0; idx < threadCount; idx++)
            {
                sbeArchRegDumpThreadHdr_t *sbeTdHdr =
                     reinterpret_cast<sbeArchRegDumpThreadHdr_t *>(procSrcAddr);

                hostArchRegDataHdr *hostHdr =
                     reinterpret_cast<hostArchRegDataHdr *>(dstTempAddr);

                TRACDCOMP(g_trac_dump, "  Thread[%d] src[%p] dest[%p]",
                          idx, procSrcAddr, dstTempAddr);

                // Fill thread header info
                regCount = sbeProcHdr->reg_cnt;
                memset(hostHdr, 0x0, sizeof(hostHdr));
                hostHdr->pir = sbeTdHdr->pir;
                hostHdr->coreState = sbeTdHdr->coreState;
                hostHdr->iv_regArrayHdr.hdatOffset =
                                              sizeof(hostArchRegDataHdr);
                hostHdr->iv_regArrayHdr.hdatArrayCnt = regCount;
                hostHdr->iv_regArrayHdr.hdatAllocSize =
                                              sizeof(hostArchRegDataEntry);
                hostHdr->iv_regArrayHdr.hdatActSize =
                                              sizeof(hostArchRegDataEntry);

                dstTempAddr = reinterpret_cast<uint64_t>(dstTempAddr +
                                                    sizeof(hostArchRegDataHdr));
                //Update SBE data source address to point to the register data
                //related to the current thread.
                procSrcAddr = reinterpret_cast<uint64_t>(procSrcAddr +
                                             sizeof(sbeArchRegDumpThreadHdr_t));

                // Fill register data
                for(uint8_t cnt = 0; cnt < regCount; cnt++)
                {
                    sbeArchRegDumpEntries_t *sbeRegData =
                       reinterpret_cast<sbeArchRegDumpEntries_t *>(procSrcAddr);
                    hostArchRegDataEntry *hostRegData =
                         reinterpret_cast<hostArchRegDataEntry *>(dstTempAddr);

                    hostRegData->reg.type = sbeRegData->regType;
                    hostRegData->reg.num  = sbeRegData->regNum;
                    hostRegData->regVal  = sbeRegData->regVal;

                    dstTempAddr = reinterpret_cast<uint64_t>(dstTempAddr +
                                                  sizeof(hostArchRegDataEntry));

                    //Update the SBE data source address to point to the
                    //next register data related to the same thread.
                    procSrcAddr = reinterpret_cast<uint64_t>(procSrcAddr +
                                               sizeof(sbeArchRegDumpEntries_t));

                    //Handle the Failure FFDC for current register being read
                    if(sbeRegData->isFfdcPresent)
                    {
                        TRACFCOMP(g_trac_dump, "SBE indicated failure to collect register."
                        " TYPE:%d,REG:0%.8x,FAPIRC=0x%.16llx for PIR=0x%.8x",(uint8_t)sbeRegData->regType,
                        (uint32_t)sbeRegData->regNum,sbeRegData->regVal,(uint32_t)hostHdr->pir);

                        //Fetch the FFDC buffer and attach it to the errorlog
                        /*@
                         * @errortype
                         * @moduleid          DUMP::DUMP_ARCH_REGS
                         * @reasoncode        DUMP::DUMP_INVALID_ARCH_REG_DATA
                         * @userdata1[00:31]  PIR value
                         * @userdata1[32:63]  Register Address/Offset
                         * @userdata2         Failure FAPI RC
                         * @devdesc           SBE failed to collect architected
                         *                    register (ref userdata 1)
                         * @custdesc          Failure to collect some error data
                         *                    following system error
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                DUMP_ARCH_REGS,
                                DUMP_INVALID_ARCH_REG_DATA,
                                TWO_UINT32_TO_UINT64(hostHdr->pir,sbeRegData->regNum),
                                sbeRegData->regVal);
                        //Fetch the length of the FFDC
                        uint32_t* ffdcLen =  reinterpret_cast<uint32_t*>(procSrcAddr);
                        //Move the source ptr to start of FFDC data.
                        procSrcAddr = procSrcAddr+sizeof(uint32_t);
                        //Fetch the FFDC buffer and attach it to the errorlog
                        l_err->addFFDC(DUMP_COMP_ID,reinterpret_cast<uint8_t*>(procSrcAddr),*ffdcLen,
                                       0,0,false);
                        //Commit the errorlog an continue
                        errlCommit(l_err, DUMP_COMP_ID);
                        //Move the source address to skip the FFDC bytes
                        procSrcAddr =(procSrcAddr + *ffdcLen);

                        //If Reg Type is TIMA and Last register is not set,
                        //then there is valid data after TIMA failure FFDC.
                        //Adjust the destination address accordingly to copy
                        //the SPR data.
                        if ( (sbeRegData->regType == DUMP_ARCH_REG_TYPE_TIMA)
                                && (!sbeRegData->isLastReg) )
                        {
                            uint32_t remainingTIMACount = SIZE_TIMA_REG - (cnt+1);
                            dstTempAddr = reinterpret_cast<uint64_t>(
                                          dstTempAddr + (remainingTIMACount *
                                                   sizeof(hostArchRegDataEntry)));
                        }
                    }
                    //If Last register is set irrespective of type of register
                    if( sbeRegData->isLastReg )
                    {
                        //Bump up the destination address to leave holes
                        //at the memory reserved for remaining registers
                        uint16_t remaingRegCount = regCount - (cnt+1);
                        //TRACFCOMP("remaingRegCount=0x%.8x",(uint32_t)remaingRegCount);
                        if(remaingRegCount)
                        {
                            dstTempAddr = reinterpret_cast<uint64_t>(
                                     dstTempAddr + (remaingRegCount *
                                          sizeof(hostArchRegDataEntry)));
                        }
                        break;
                    }

                } //End of Register Loop
            }//Thread Loop

            //Populate the processor specific TOC in the HDAT PDA structure.
            uint32_t procId = procChips[procNum]->getAttr<TARGETING::ATTR_ORDINAL_ID>();
            //Update PROC specific data offset
            procTableEntry->iv_procArcRegDataToc[procId].dataOffset = 
               static_cast<uint64_t>(procTableEntry->iv_nodeSrcArcRegDataTOC[nodeId].dataOffset + 
                                     allProcDataSize);
            //Update the size information.
            procTableEntry->iv_procArcRegDataToc[procId].dataSize = (procTableEntry->threadRegSize * threadCount);
            //Update the allProcDataSize to calculate the next PROC specific data offset.
            allProcDataSize = allProcDataSize + procTableEntry->iv_procArcRegDataToc[procId].dataSize;


            TRACDCOMP(g_trac_dump,"procTableEntry->iv_procArcRegDataToc[%d].dataOffset=0x%.8x",
                                   procId,procTableEntry->iv_procArcRegDataToc[procId].dataOffset);
            TRACDCOMP(g_trac_dump,"procTableEntry->iv_procArcRegDataToc[%d].dataSize=0x%.8x",
                                   procId,procTableEntry->iv_procArcRegDataToc[procId].dataSize);

            if(collectMinimumDataMode)
            {
                TRACFCOMP(g_trac_dump, "Hypervisor Pre-Init failure case. Copy data only related to "
                "master procesor,master fused core!");
                break;
            }
        }
        // Update Process Dump Area tuple
        procTableEntry->threadRegVersion = REG_DUMP_HDAT_STRUCT_VER;
        procTableEntry->iv_nodeCapturedArcRegDataTOC[nodeId].dataOffset =
                                  procTableEntry->iv_nodeSrcArcRegDataTOC[nodeId].dataOffset;

        // Update the PDA Table Entries to Attribute to be fetched in istep 21
        l_sys->setAttr<TARGETING::ATTR_PDA_THREAD_REG_STATE_ENTRY_FORMAT>(
                                              procTableEntry->threadRegVersion);
        l_sys->setAttr<TARGETING::ATTR_PDA_THREAD_REG_ENTRY_SIZE>(
                                                 procTableEntry->threadRegSize);

        //Update the HW Dump Area table
        TRACFCOMP(g_trac_dump, "Updating the HW Dump Area Table");
        //Fetch the reference to the HW Dump area table to update the proc specific offset
        uint64_t l_hostDataAddr = 0;
        uint64_t l_hostDataSize = 0;
        l_err = RUNTIME::get_host_data_section(RUNTIME::HW_DUMP_AREA_TBL,0,l_hostDataAddr,
                l_hostDataSize);
        if(l_err)
        {
            TRACFCOMP(g_trac_dump,"Failed to obatain the HW_DUMP_AREA_TBL section");
            break;
        }
        DUMP::HwDumpAreaTable  *hwDumpTable = nullptr;
        hwDumpTable = reinterpret_cast<DUMP::HwDumpAreaTable *>(l_hostDataAddr);

        for (uint32_t procNum = 0; procNum < procChips.size(); procNum++)
        {

            //Fetch PROC specific Meta Data
            uint64_t procSrcAddr = (reinterpret_cast<uint64_t>(vMapSrcAddrBase)+
                                  procNum * VMM_ARCH_REG_DATA_PER_PROC_SIZE);
            DUMP::sbeArchHWDumpMetaData_t *metadata =
                   reinterpret_cast<DUMP::sbeArchHWDumpMetaData_t *>(procSrcAddr);

            TRACDCOMP(g_trac_dump, "METADATA OF PROC WITH SRC address:0x%.16llx",
                      metadata->archDataMemoryAddr);
            uint32_t procId = procChips[procNum]->getAttr<TARGETING::ATTR_ORDINAL_ID>();

            hwDumpTable->procHwRegDataToc[procId].dataOffset= metadata->hwDataMemoryAddr;
            hwDumpTable->procHwRegDataToc[procId].dataSize=metadata->hwDataMemCapturedSize;
            hwDumpTable->procHwRegDataToc[procId].nodeId = nodeId;
            TRACFCOMP(g_trac_dump, "PROC[%d] HWDataOffset=0x%.16llx Size=0x%.8x",
                      procId,hwDumpTable->procHwRegDataToc[procId].dataOffset,hwDumpTable->procHwRegDataToc[procId].dataSize);

        }

    } while (0);

    // Unmap destination memory
    if (vMapDstAddrBase)
    {
        rc = mm_block_unmap(vMapDstAddrBase);
        if (rc != 0)
        {
            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_ARCH_REGS
             * @reasoncode   DUMP::DUMP_PDAT_CANNOT_UNMAP_DST_ADDR
             * @userdata1    VA of Destination Array Address for PDAT
             * @userdata2    rc value from unmap
             * @devdesc      Cannot unmap the PDAT Destinatin Array Addr
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  DUMP_ARCH_REGS,
                                  DUMP_PDAT_CANNOT_UNMAP_DST_ADDR,
                                  (uint64_t)vMapDstAddrBase,
                                  rc,
                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            // Commit the error and continue.
            // Leave the devices unmapped?
            errlCommit(l_err, DUMP_COMP_ID);
            l_err = NULL;
        }
    }

    // Unmap source memory
    if(vMapSrcAddrBase)
    {
        rc = mm_block_unmap(vMapSrcAddrBase);
        if (rc != 0)
        {
            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_ARCH_REGS
             * @reasoncode   DUMP::DUMP_PDAT_CANNOT_UNMAP_SRC_ADDR
             * @userdata1    VA address of Source Array Address for PDAT
             * @userdata2    rc value from unmap
             * @devdesc      Cannot unmap the PDAT Source Array Address
             */
            l_err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  DUMP_ARCH_REGS,
                                  DUMP_PDAT_CANNOT_UNMAP_SRC_ADDR,
                                  (uint64_t)vMapSrcAddrBase,
                                  rc,
                                  ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            // Commit the error and continue.
            // Leave the devices unmapped?
            errlCommit(l_err, DUMP_COMP_ID);
            l_err = NULL;
        }
    }
    TRACFCOMP(g_trac_dump, "copyArchitectedRegs - end ");
    return (l_err);
}

/**
 *  @brief check dump destination address for valid ranges
 *
 *  @param[in] i_curDestTableAddr    destination table address to validate
 *  @param[in] i_phys_attr_data_addr physical attribute data address
 *  @param[in] i_attr_data_size      attribute data size
 *
 *  @return errlHndl_t error log handler
 */
errlHndl_t checkValidDumpDestinationAddresses(const uint64_t i_curDestTableAddr,
                                              const uint64_t i_phys_attr_data_addr,
                                              const uint64_t i_attr_data_size)
{
    errlHndl_t l_err = nullptr;

    // Verify that the destination table does not contain
    // both the reserved memory region and our memory footprint
    for (uint64_t i = 0; i < MAX_NODES_PER_SYS; i++)
    {
        uint64_t lowerBound = cpu_spr_value(CPU_SPR_HRMOR) +
            i * MEMMAP::NODE_OFFSET;
        lowerBound |= IGNORE_HRMOR;
        uint64_t upperBound = lowerBound + VMM_MEMORY_SIZE - 1;

        // Skip attribute checks if getReservedMemoryRegion returned error
        if ((i_curDestTableAddr >= lowerBound &&
             i_curDestTableAddr <= upperBound) ||
             (i_phys_attr_data_addr != 0 &&
             i_attr_data_size != 0 &&
             i_curDestTableAddr >= i_phys_attr_data_addr &&
             i_curDestTableAddr <= i_phys_attr_data_addr + i_attr_data_size - 1))
        {
            // Cannot write to Hostboot memory region
            TRACFCOMP(g_trac_dump, ERR_MRK"HBDumpCopySrcToDest: "
                "Dump table is incorrectly writing its contents "
                "within memory regions owned by Hostboot");
           /*@
            * @errortype
            * @moduleid    DUMP::DUMP_COLLECT
            * @reasoncode  DUMP::DUMP_MDDT_INVALID_REGION
            * @userdata1   Address of destination table write
            * @devdesc     MDDT table entry is inside hostboot region
            * @custdesc    Error occurred during system boot
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_COLLECT,
                                            DUMP_MDDT_INVALID_REGION,
                                            i_curDestTableAddr);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_MED);
            break;
        }
    }

    return l_err;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

errlHndl_t copySrcToDest(dumpEntry *srcTableEntry,
                         uint64_t srcTableSize,
                         dumpEntry *destTableEntry,
                         uint64_t destTableSize,
                         resultsEntry *resultsTableEntry,
                         uint64_t resultsTableSize)
{
    TRACFCOMP(g_trac_dump, "copySrcToDest - start ");

    errlHndl_t l_err = nullptr;
    int rc = 0;
    bool invalidSrcSize = false;
    bool invalidDestSize = false;
    uint32_t l_resultCount = 0x0;

    // local src table info
    uint64_t *vaSrcTableAddr = 0;
    uint64_t *vaMapSrcTableAddr = 0;
    uint64_t curSrcTableAddr = 0;

    // destination table info
    uint64_t *vaDestTableAddr = 0;
    uint64_t *vaMapDestTableAddr = 0;
    uint64_t curDestTableAddr = 0;

    // Data sizes
    uint64_t sizeToCopy = 0;
    uint64_t bytesLeftInSrc = 0;
    uint64_t bytesLeftInDest = 0;

    do
    {

        // Need to loop through all the source entries.. Copying into a
        // destination entry.  Note the src could be larger than the
        // destination size and could require multiple copies.. In addition
        // the size of the destination could be larger than 1 source entry.
        // These entries need to be packed into the destination.. so 1
        // destination entry could have multiple source entries in it.
        // After each copy need to write an entry into the results table
        // source/destination/size.

        // Figure out the num of entries in the src table
        uint64_t maxSrcEntries = srcTableSize/(sizeof (dumpEntry));

        // Figure out the num of entries in the dest table
        uint64_t maxDestEntries = destTableSize/(sizeof (dumpEntry));

        // Figure out the max result entires
        uint64_t maxResultEntries = resultsTableSize/(sizeof
                                                      (resultsEntry));

        // Index into each Dump table
        uint64_t curSourceIndex = 0;
        uint64_t curDestIndex = 0;
        uint64_t curResultIndex = 0;

        // Map in the first source and destination entries from their
        // corresponding tables.
        // NOTE: When mapping a device the address we are mapping needs to
        // be page aligned.  In addition the VA returned is page
        // aligned so we need to add the offset of the page aligned address
        // to the VA returned

        // Get the first Source address and size
        curSrcTableAddr = srcTableEntry[curSourceIndex].dataAddr;
        bytesLeftInSrc = srcTableEntry[curSourceIndex].dataSize;

        // Get the first destination address and size.
        curDestTableAddr = destTableEntry[curDestIndex].dataAddr;
        bytesLeftInDest = destTableEntry[curDestIndex].dataSize;

        // Determine the src and destination offset.
        uint64_t destOffset = curDestTableAddr
          - ALIGN_PAGE_DOWN(curDestTableAddr);
        uint64_t srcOffset = curSrcTableAddr
          - ALIGN_PAGE_DOWN(curSrcTableAddr);

        // If the data size is greater then 32GB after page alignment
        // create an error.  Current limitation on DevMap is 32GB in size.
        // Not sure yet if we will ever see a table entry > 3GB.
        if (bytesLeftInSrc + srcOffset > THIRTYTWO_GB)
        {
            invalidSrcSize = true;
            break;
        }
        else if ((bytesLeftInDest + destOffset > THIRTYTWO_GB))
        {
            invalidDestSize = true;
            break;
        }

        vaMapSrcTableAddr = (static_cast<uint64_t*>(mm_block_map(
                              getPhysAddr(curSrcTableAddr),
                              THIRTYTWO_GB)));

        vaSrcTableAddr = vaMapSrcTableAddr;

        vaMapDestTableAddr = (static_cast<uint64_t*>(mm_block_map(
                               getPhysAddr(curDestTableAddr),
                               THIRTYTWO_GB)));

        vaDestTableAddr = vaMapDestTableAddr;

        // add the offset to the src and destination VAs,
        vaSrcTableAddr += (srcOffset/(sizeof (uint64_t)));

        vaDestTableAddr += (destOffset/(sizeof (uint64_t)));

        // Current Source physical and Va address
        TRACFCOMP(g_trac_dump, "copySrcToDest SrcTableIndex = %d, srcTableAddr = %.16X, VA = %.16X",  curSourceIndex, curSrcTableAddr, vaSrcTableAddr);

        // Current Destination physical and Va address
        TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest DestTableIndex = %d, DestTableAddr = %.16X, VA = %.16X", curDestIndex, curDestTableAddr, vaDestTableAddr);

        resultsTableEntry->dataSize = 0x0;

        uint64_t l_phys_attr_data_addr = 0;
        uint64_t l_attr_data_size = 0;
        // Get reserved memory for later use
        l_err = TARGETING::AttrRP::getReservedMemoryRegion(l_phys_attr_data_addr,
                                                           l_attr_data_size);

        if (l_err)
        {
            // Reset these back so checkValidDumpDestinationAddresses can use them
            l_phys_attr_data_addr = 0;
            l_attr_data_size = 0;
            errlCommit(l_err, TARG_COMP_ID);
        }

        l_err = checkValidDumpDestinationAddresses(curDestTableAddr,
                                                   l_phys_attr_data_addr,
                                                   l_attr_data_size);

        if (l_err)
        {
            TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: checkValidDumpDestinationAddresses"
                " returned error, curDestTableAddr = 0x%.16llX, physAttrData = 0x%.16llX,"
                " attrDataSize = %lld", curDestTableAddr, l_phys_attr_data_addr, l_attr_data_size);

            errlCommit(l_err, TARG_COMP_ID);

            // If destination is bad, set the remaining bytes to be 0
            bytesLeftInDest = 0;
        }

        while(1)
        {
            // If we have copied all the bytes in the src entry
            if (bytesLeftInSrc == 0)
            {
                // unmap the previous src entry
                rc =  mm_block_unmap(
                            reinterpret_cast<void*>(vaMapSrcTableAddr));

                if (rc != 0)
                {
                    /*@
                     * @errortype
                     * @moduleid     DUMP::DUMP_COLLECT
                     * @reasoncode   DUMP::DUMP_CANNOT_UNMAP_SRC
                     * @userdata1    VA address of the MDST to unmap
                     * @userdata2    rc value from unmap
                     * @devdesc      Cannot unmap the source table section
                     * @custdesc     Error occurred during system boot
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          DUMP_COLLECT,
                                          DUMP_CANNOT_UNMAP_SRC,
                                          (uint64_t)vaMapSrcTableAddr,
                                          rc);

                    // commit the error and continue.
                    // Leave the devices unmapped for now.
                    errlCommit(l_err,DUMP_COMP_ID);
                }

                // increment to the next src entry
                curSourceIndex++;

                // if we have reach all entries
                if (curSourceIndex >= maxSrcEntries)
                {
                    TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest - through all src entries");
                    break;
                }

                curSrcTableAddr = srcTableEntry[curSourceIndex].dataAddr;
                bytesLeftInSrc = srcTableEntry[curSourceIndex].dataSize;

                // src address 0 is valid source address on OPAL sytems
                if (!TARGETING::is_sapphire_load())
                {
                    // If the current Src table Address is 0 we are done
                    if (curSrcTableAddr == 0)
                    {
                        break;
                    }
                }

                srcOffset =  curSrcTableAddr -
                  ALIGN_PAGE_DOWN(curSrcTableAddr);

                // If the data size is less then 32GB after page alignment
                if (bytesLeftInSrc + srcOffset > THIRTYTWO_GB)
                {
                    invalidSrcSize = true;
                    break;
                }

                // map the MDST entry to a device such that we can read and
                //  write from that memory address
                vaMapSrcTableAddr = (static_cast<uint64_t*>(mm_block_map(
                                      getPhysAddr(curSrcTableAddr),
                                      THIRTYTWO_GB)));

                vaSrcTableAddr = vaMapSrcTableAddr;

                vaSrcTableAddr += (srcOffset/(sizeof (uint64_t)));

                // Current Source physical and Va address
                TRACFCOMP(g_trac_dump, "copySrcToDest SrcTableIndex = %d, srcTableAddr = %.16X, VA = %.16X",  curSourceIndex, curSrcTableAddr, vaSrcTableAddr);

            }

            // If there is no more space in the destination area
            if (bytesLeftInDest == 0)
            {
                if (vaMapDestTableAddr != nullptr)
                {
                    // unmap the previous dest entry
                    rc =  mm_block_unmap(
                        reinterpret_cast<void*>(vaMapDestTableAddr));
                    vaMapDestTableAddr = nullptr;

                    if (rc != 0)
                    {
                        /*@
                         * @errortype
                         * @moduleid     DUMP::DUMP_COLLECT
                         * @reasoncode   DUMP::DUMP_CANNOT_UNMAP_DEST
                         * @userdata1    VA address of the MDDT to unmap
                         * @userdata2    rc value from unmap
                         * @devdesc      Cannot unmap the source table section
                         * @custdesc     Error occurred during system boot
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              DUMP_COLLECT,
                                              DUMP_CANNOT_UNMAP_DEST,
                                              (uint64_t)vaMapDestTableAddr,
                                              rc);

                        // commit the error and continue.
                        errlCommit(l_err,DUMP_COMP_ID);
                    }
                }

                // increment to the next dest entry
                curDestIndex++;

                // if made it through all dest entries.
                if (curDestIndex >= maxDestEntries)
                {
                    // need to check here to see if we still have SRC
                    // entries not copied.
                    if (bytesLeftInSrc != 0)
                    {
                        // Write an error because we have more src entries
                        // then destination space available.
                        TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: not enough Destination table entries");

                        /*@
                         * @errortype
                         * @moduleid     DUMP::DUMP_COLLECT
                         * @reasoncode   DUMP::DUMP_MDDT_INSUFFICIENT_ENTRIES
                         * @userdata1    Source Entires bytes left to copy
                         * @userdata2    Index into the MDST table
                         * @devdesc      MDDT table is not big enough to
                         *               hold all src entries
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              DUMP_COLLECT,
                                              DUMP_MDDT_INSUFFICIENT_ENTRIES,
                                              bytesLeftInSrc,
                                              curSourceIndex);

                        errlCommit(l_err, TARG_COMP_ID);

                        // TODO:  RTC: 64399
                        //  Need to add the src entries and sizes? that did
                        //  not get copied to the destination. This error
                        //  condition is such that the table entries are
                        // exceeded.
                    }

                    break;
                }

                curDestTableAddr = destTableEntry[curDestIndex].dataAddr;
                bytesLeftInDest = destTableEntry[curDestIndex].dataSize;

                destOffset = curDestTableAddr
                    - ALIGN_PAGE_DOWN(curDestTableAddr);

                //check to see if there are contiguous destination addresses
                while ((destTableEntry[curDestIndex].dataAddr +
                        destTableEntry[curDestIndex].dataSize) ==
                       destTableEntry[curDestIndex+1].dataAddr)
                {
                    uint64_t destSize = bytesLeftInDest + destOffset;

                    // dataSize in dumpEntry structure is defined as a uint32_t.
                    // Also, DevMap currently limits the size to 32GB.
                    destSize += destTableEntry[curDestIndex].dataSize;
                    if (destSize >= THIRTYTWO_GB)
                    {
                        break;
                    }

                    curDestIndex++;
                    bytesLeftInDest += destTableEntry[curDestIndex].dataSize;
                }

                // If the current dest addr or the size to copy are zero.
                if ((curDestTableAddr == 0) || (bytesLeftInDest == 0))
                {

                    // If there are still SRC entries to copy with no
                    // destination send an error back.
                    if (bytesLeftInSrc != 0)
                    {
                        // Write an error because we have more src entries
                        // than destination space available.
                        TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: not enough"
                                  "Destination table space");

                        /*@
                         * @errortype
                         * @moduleid     DUMP::DUMP_COLLECT
                         * @reasoncode   DUMP::DUMP_MDDT_INSUFFICIENT_SPACE
                         * @userdata1    Source Entires bytes left to copy
                         * @userdata2    Index into the MDST table
                         * @devdesc      MDDT table is not big enough to
                         *               hold all src entries
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              DUMP_COLLECT,
                                              DUMP_MDDT_INSUFFICIENT_SPACE,
                                              bytesLeftInSrc,
                                              curSourceIndex);

                        // do not commit this errorlog error as this is a
                        // real problem.

                        // TODO:  RTC: 64399
                        //  Need to add the src entries and sizes? that did
                        //  not get copied to the destination.  This
                        //  condition is such that we have a destination
                        //  entry that either has a zero address or zero
                        //  size.. Perhaps put the bad destination entry
                        //  there as well
                    }

                    break;
                }

                // If the data size is less then 32GB after page alignment
                if (bytesLeftInDest + destOffset > THIRTYTWO_GB)
                {
                    invalidDestSize = true;
                    break;
                }

                l_err = checkValidDumpDestinationAddresses(curDestTableAddr,
                                                           l_phys_attr_data_addr,
                                                           l_attr_data_size);

                if (l_err)
                {
                    TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: checkValidDumpDestinationAddresses"
                        " returned error, curDestTableAddr = 0x%.16llX, physAttrData = 0x%.16llX,"
                        " attrDataSize = %lld", curDestTableAddr, l_phys_attr_data_addr, l_attr_data_size);

                    errlCommit(l_err, TARG_COMP_ID);

                    // If destination is bad, set the remaining bytes to 0
                    bytesLeftInDest = 0;
                    continue;
                }

                // map the MDDT to a VA addresss
                vaMapDestTableAddr = (static_cast<uint64_t*>(mm_block_map(
                                       getPhysAddr(curDestTableAddr),
                                       THIRTYTWO_GB)));

                vaDestTableAddr = vaMapDestTableAddr;

                vaDestTableAddr += (destOffset/(sizeof(uint64_t)));

                // Current Destination physical and Va address
                TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest DestTableIndex = %d, DestTableAddr = %.16X, VA = %.16X", curDestIndex, curDestTableAddr, vaDestTableAddr);

            }


            // Determine how much to copy..
            sizeToCopy = std::min(bytesLeftInSrc, bytesLeftInDest);

            // Do the copy of the data from the source to the destination
            mm_tolerate_ue(1);
            memcpy( vaDestTableAddr,vaSrcTableAddr, sizeToCopy);
            mm_tolerate_ue(0);

            if (curResultIndex < maxResultEntries)
            {
                // Update the results table
                resultsTableEntry->srcAddr =
                  VmmManager::FORCE_PHYS_ADDR|curSrcTableAddr;
                resultsTableEntry->destAddr =
                  VmmManager::FORCE_PHYS_ADDR|curDestTableAddr;

                resultsTableEntry->dataSize = sizeToCopy;
                // Size field in source/destination table is of 4 bytes.
                // So result table size field will never cross 4 bytes.
                // Hence use top 2 bytes to copy data_type from source
                // table to result table (see HDAT spec for details).
                if (TARGETING::is_sapphire_load())
                {
                    uint64_t data_type = srcTableEntry[curSourceIndex].data_type;
                    resultsTableEntry->dataSize |= (data_type << 48);
                }
                resultsTableEntry++;
                l_resultCount++;
                curResultIndex++;
            }
            else
            {
                TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: not enough result table space");

                /*@
                 * @errortype
                 * @moduleid     DUMP::DUMP_COLLECT
                 * @reasoncode   DUMP::DUMP_MDRT_INSUFFICIENT_SPACE
                 * @userdata1    Index into the MDRT
                 * @userdata2    max entries allowed given space allocated
                 * @devdesc      MDRT table is not big enough to hold all
                 *               entries
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                DUMP_COLLECT,
                                                DUMP_MDRT_INSUFFICIENT_SPACE,
                                                curResultIndex,
                                                maxResultEntries);

                // commit the error and continue.
                errlCommit(l_err,DUMP_COMP_ID);

                l_err = NULL;
            }

            // decrement the amount copied from the source and destination
            bytesLeftInSrc -= sizeToCopy;
            bytesLeftInDest -= sizeToCopy;

            uint64_t addrOffset = sizeToCopy/(sizeof (uint64_t));

            // increment the current src and dest addresses in both the
            // physical and virtual addresses.
            curSrcTableAddr += sizeToCopy;
            curDestTableAddr += sizeToCopy;
            vaSrcTableAddr += addrOffset;
            vaDestTableAddr += addrOffset;
        } // end of while loop

        if (invalidSrcSize)
        {
            // Write an error because we have more src entries
            // then destination space available.
            TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: Source TableSize > 32GB");

            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_COLLECT
             * @reasoncode   DUMP::DUMP_MDST_INVALID_TABLE_SIZE
             * @userdata1    Size of Source Table Entry
             * @userdata2    Size of Page Aligned Source Table Entry
             * @devdesc      MDST table entry with page aligned is
             *               greater than 32GB
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_COLLECT,
                                            DUMP_MDST_INVALID_TABLE_SIZE,
                                            bytesLeftInSrc,
                                            bytesLeftInSrc + srcOffset);
            break;

        }
        if (invalidDestSize)
        {
            // Write an error because we have more src entries
            // then destination space available.
            TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest: Destination TableSize > 32GB");

            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_COLLECT
             * @reasoncode   DUMP::DUMP_MDDT_INVALID_TABLE_SIZE
             * @userdata1    Size of Destination Table Entry
             * @userdata2    Size of Page Aligned Destination Table Entry
             * @devdesc      MDDT table entry with page aligned is
             *               greater than 32GB
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_COLLECT,
                                            DUMP_MDDT_INVALID_TABLE_SIZE,
                                            bytesLeftInDest,
                                            bytesLeftInDest + destOffset);

            break;
        }

        // Update the MDRT Count to Attribute to be fetched in istep 21
        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        TARGETING::Target* l_sys = NULL;
        l_targetService.getTopLevelTarget(l_sys);
        l_sys->setAttr<TARGETING::ATTR_MPIPL_HB_MDRT_COUNT>(l_resultCount);

        //Update actual count in RUNTIME
        RUNTIME::saveActualCount(RUNTIME::MS_DUMP_RESULTS_TBL,
                                 l_resultCount);

        //Write actual count into memory as well
        // We know this will get whacked when FSP reloads the PHYP
        // lid, but we want it to be valid before that to allow
        // FSP code to consume the data from mainstore
        RUNTIME::writeActualCount(RUNTIME::MS_DUMP_RESULTS_TBL);
    }while(0);// end of do-while loop

    // Got an errorlog back from get_host_data_sections
    TRACFCOMP(g_trac_dump, "HBDumpCopySrcToDest - COMPLETE ");

    return l_err;
}



    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////

    errlHndl_t getHostDataPtrs(dumpEntry *&srcTableEntry,
                               uint64_t &srcTableSize,
                               dumpEntry *&destTableEntry,
                               uint64_t &destTableSize,
                               resultsEntry *&resultsTableEntry,
                               uint64_t &resultsTableSize)

    {

        errlHndl_t l_err = NULL;
        int rc = 0;
        bool l_error = false;
        uint64_t l_section = 0;
        uint64_t l_addr = 0;
        uint64_t srcTableAddr = 0;
        uint64_t destTableAddr = 0;
        uint64_t resultsTableAddr = 0;


        do
        {

            // Get the Src Table address  (MDST)
            l_err = RUNTIME::get_host_data_section(RUNTIME::MS_DUMP_SRC_TBL,
                                                   0,
                                                   srcTableAddr,
                                                   srcTableSize);


            if (l_err)
            {
                // Got an errorlog back from get_host_data_sections
                TRACFCOMP(g_trac_dump, "HBDumpGetHostData get_host_data_sections for MDST failed rc=0x%X", rc);

                break;
            }

            // If the address or size is zero - error out
            if ((srcTableSize == 0) || (srcTableAddr == 0))
            {
                // Invalid size or address
                TRACFCOMP(g_trac_dump, "HBDumpGetHostData address or size invalie for MDST: addr =0x%X, size =0x%X," , srcTableAddr, srcTableSize);

                l_section = RUNTIME::MS_DUMP_SRC_TBL;
                l_addr = srcTableAddr;
                l_error = true;
                // got back a bad address
                break;
            }

            srcTableEntry = reinterpret_cast<dumpEntry *>(srcTableAddr);

            // Get the Destination Table Address (MDDT)
            l_err = RUNTIME::get_host_data_section(RUNTIME::MS_DUMP_DST_TBL,
                                                   0,
                                                   destTableAddr,
                                                   destTableSize);


            if (l_err)
            {
                // Got an errorlog back from get_host_data_sections
                TRACFCOMP(g_trac_dump, "HBDumpGetHostData get_host_data_sections for MDDT failed rc=0x%X", rc);

                break;
            }

            // If the address or size is zero - error out
            if ((destTableSize == 0) || (destTableAddr == 0))
            {
                // Invalid size or address
                TRACFCOMP(g_trac_dump,
                          "HBDumpGetHostData address or size invalie for MDDT: addr =0x%X, size =0x%X," ,
                          destTableAddr, destTableSize);

                l_section = RUNTIME::MS_DUMP_DST_TBL;
                l_addr = destTableAddr;
                l_error = true;

                // got back a bad address
                break;
            }

            destTableEntry = reinterpret_cast<dumpEntry *>(destTableAddr);

            // Get the Results Table Address
            l_err = RUNTIME::get_host_data_section(RUNTIME::MS_DUMP_RESULTS_TBL,
                                                   0,
                                                   resultsTableAddr,
                                                   resultsTableSize);


            if (l_err)
            {
                // Got an errorlog back from get_host_data_sections
                TRACFCOMP(g_trac_dump, "HBDumpGetHostData get_host_data_sections for MDDT failed rc=0x%X", rc);

                break;
            }

            // If the address or size is zero - error out
            if ((resultsTableSize == 0) || (resultsTableAddr == 0))
            {
                // Invalid size or address
                TRACFCOMP(g_trac_dump,
                          "HBDumpGetHostData address or size invalid for MDRT: addr =0x%X, size =0x%X," ,
                          resultsTableAddr, resultsTableSize);

                l_section = RUNTIME::MS_DUMP_RESULTS_TBL;
                l_addr = resultsTableAddr;
                l_error = true;
                // got back a bad address
                break;
            }

            // Each results table entry has the Source,Destination and Size for
            // each copy that is done from source to destination
            resultsTableEntry =
              reinterpret_cast<resultsEntry *>(resultsTableAddr);

            TRACFCOMP(g_trac_dump,
                      "gethostDataPtrs SrcTableAddr = %.16x, DestTableAddr = %.16X, resultTableAddr = %.16X",
                      srcTableAddr, destTableAddr, resultsTableAddr);

        }while(0);

        if (l_error)
        {

            /*@
             * @errortype
             * @moduleid     DUMP::DUMP_COLLECT
             * @reasoncode   DUMP::DUMP_NO_HDAT_ADDR
             * @userdata1    Address returned
             * @userdata2    Table type Requested
             * @devdesc      Invalid address and size returned from HDAT
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            DUMP_COLLECT,
                                            DUMP_NO_HDAT_ADDR,
                                            l_addr,
                                            l_section);

        }

        return (l_err);
    }


    // ------------------------------------------------------------------
    // sendMboxMsg
    // ------------------------------------------------------------------
    errlHndl_t sendMboxMsg(DUMP_MSG_TYPE i_type)

    {
        errlHndl_t l_err = NULL;
        msg_t* msg = NULL;
        TRACFCOMP( g_trac_dump,
                   ENTER_MRK"sendMboxMsg()" );

        do
        {

            //Create a mailbox message to send to FSP
            msg = msg_allocate();
            msg->type = i_type;

            // If this is not a dump start message, need to collect the
            // Results table and size as well as the results table itself.
            if (i_type != DUMP_MSG_START_MSG_TYPE)
            {
                uint64_t resultsTableAddr = 0;
                uint64_t resultsTableSize = 0;

                // Get the Results Table Address
                l_err =
                  RUNTIME::get_host_data_section(RUNTIME::MS_DUMP_RESULTS_TBL,
                                                 0,
                                                 resultsTableAddr,
                                                 resultsTableSize);


                if (l_err)
                {
                    // Got an errorlog back from get_host_data_sections
                    TRACFCOMP(g_trac_dump, "HBDumpGetHostData get_host_data_sections for MDDT failed rc=0x%X", l_err->reasonCode());
                }
                // If the address or size is zero - error out
                else if ((resultsTableSize == 0) || (resultsTableAddr == 0))
                {
                    // Invalid size or address
                    TRACFCOMP(g_trac_dump,
                              "HBDumpGetHostData address or size invalid for MDRT: addr =0x%X, size =0x%X," ,
                              resultsTableAddr, resultsTableSize);


                    // Create an errorlog and change the type to error and add
                    // the plid to the data section.

                    /*@
                     * @errortype
                     * @moduleid     DUMP::DUMP_SEND_MBOX_MSG
                     * @reasoncode   DUMP::DUMP_NO_HDAT_ADDR
                     * @userdata1    Address returned
                     * @userdata2    Table type Requested
                     * @devdesc      Invalid address and size returned from HDAT
                     */
                    l_err =
                      new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              DUMP_SEND_MBOX_MSG,
                                              DUMP_NO_HDAT_ADDR,
                                              resultsTableAddr,
                                              i_type);

                }

                // if no error then collect as expected.
                if (!l_err)
                {
                    // Physical Address of the results table
                    uint64_t l_mdrt_phys =
                      mm_virt_to_phys(
                          reinterpret_cast<void*>(resultsTableAddr));

                    // If TCEs are enabled setup TCEs in TCE Table to allow
                    // the FSP to read this memory
                    if (TCE::utilUseTcesForDmas())
                    {
                        // Align Physical addr down for TCE requirement
                        uint64_t mdrt_phys_aligned =
                                   ALIGN_PAGE_DOWN(l_mdrt_phys);

                        uint64_t offset = l_mdrt_phys - mdrt_phys_aligned;

                        TRACFCOMP( g_trac_dump,"Setup TCEs for FSP to use for "
                                   "l_mdrt_phys=0x%.16llX (virt=0x%.16llX, "
                                   "aligned_phys=0x%.16llX, offset=0x%X)",
                                   l_mdrt_phys, resultsTableAddr,
                                   mdrt_phys_aligned, offset);

                        uint32_t token = 0;
                        l_err = TCE::utilAllocateTces(mdrt_phys_aligned,
                                                      resultsTableSize+offset,
                                                      token,
                                                      false); //Read-Only

                        if (l_err)
                        {
                            // Got an errorlog back from utilAllocateTces
                            TRACFCOMP(g_trac_dump, "HBDumpGetHostData utilAllocateTces failed rc=0x%X", l_err->reasonCode());
                        }
                        else
                        {
                            // Put the token with the offset into the msg
                            msg->data[0] = token + offset;
                        }
                    }
                    else
                    {
                        msg->data[0] = l_mdrt_phys;
                    }

                    // Number of bytes in the results table
                    msg->data[1] = resultsTableSize;

                    // No extra data to worry about
                    msg->extra_data = NULL;

                }

                if (l_err)
                {
                    TRACFCOMP( g_trac_dump,
                               INFO_MRK"Got an error trying to send msg. %.8X,",
                               i_type);

                    // change the msg type to be error type
                    i_type = DUMP_MSG_ERROR_MSG_TYPE;

                    l_err->collectTrace("DUMP",1024);

                    // Put a default value into the data[0] indicating plid to in data[1]
                    msg->data[0] = 0xFFFF;

                    msg->data[1] = l_err->plid(); // plid

                    // just commit the log from failure on Read.. and
                    // send an error msg to FSP.
                    errlCommit( l_err, DUMP_COMP_ID );
                    l_err = NULL;

                }
            }


            TRACFCOMP( g_trac_dump,
                       INFO_MRK"Send msg to FSP about DUMP %.8X,",
                       i_type);

            // Send the message
            l_err = MBOX::send( MBOX::FSP_DUMP_MSGQ_ID, msg );

            // got an error.. Free the msg space allocated above.
            if( l_err )
            {
                TRACFCOMP(g_trac_dump,
                          ERR_MRK "Failed sending DUMP to FSP for %.8X",i_type);

                l_err->collectTrace("DUMP",1024);

                free( msg->extra_data );
                msg->extra_data = NULL;
                msg_free( msg );
            }
        } while( 0 );


        TRACFCOMP( g_trac_dump,
                   EXIT_MRK"sendMboxMsg()" );

        return l_err;
    }


}; // end of namespace
