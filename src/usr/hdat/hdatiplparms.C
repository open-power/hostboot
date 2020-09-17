/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatiplparms.C $                                 */
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
 * @file hdatiplparms.C
 *
 * @brief This file contains the implementation of the HdatIplParms class.
 *
 */

/*------------------------------------------------------------------------*/
/* Includes                                                               */
/*------------------------------------------------------------------------*/
#include <ctype.h>                  // endian testing
#include "hdatiplparms.H"           // HdatIplParms class definition
#include <attributeenums.H>
#include "hdatutil.H"
#include <sys/mm.h>
#include <sys/mmio.h>
#include <vpd/mvpdenums.H>
#include <pnor/pnorif.H>
#include <util/align.H>
#include <arch/pvrformat.H>

#include <devicefw/userif.H>
#include <targeting/common/util.H>

using namespace TARGETING;

namespace HDAT
{

extern trace_desc_t *g_trac_hdat;


/*------------------------------------------------------------------------*/
/* Constants                                                              */
/*------------------------------------------------------------------------*/

/**
 * @brief This routine gets number of cores in each processor
 *
 * @pre None
 *
 * @post None
 *
 * @param o_numCores - output parameter - Number of cores
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
static void hdatGetNumberOfCores(uint32_t &o_numCores)
{
    HDAT_ENTER();
    uint8_t          l_prData[9];
    size_t           l_prDataSz = 8;
    errlHndl_t       l_err = NULL;

    o_numCores = 0;


    TARGETING::PredicateCTM l_procChipPredicate(TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_PROC);

    TARGETING::PredicateHwas l_predHwas;
    l_predHwas.present(true);

    TARGETING::PredicatePostfixExpr l_presentProc;
    l_presentProc.push(&l_procChipPredicate).push(&l_predHwas).And();

    TARGETING::TargetRangeFilter l_procFilter(
                                        TARGETING::targetService().begin(),
                                        TARGETING::targetService().end(),
                                        &l_presentProc);

    TARGETING::Target *l_procTarget = (*l_procFilter);

    l_err = deviceRead(l_procTarget,l_prData,l_prDataSz,
                                    DEVICE_MVPD_ADDRESS(MVPD::VINI,MVPD::PR));

    if(l_err)
    {
        HDAT_ERR("Error during VPD PR keyword  read");
    }
    else
    {
        o_numCores = l_prData[2] >> 4;
        HDAT_DBG("Number of Cores: %d",o_numCores);
    }
    HDAT_EXIT();
}

/**
 * @brief This routine gets the information for Enlarged IO Slot Count
 *
 * @pre None
 *
 * @post None
 *
 * @param o_EnlargedSlotCount - output parameter - Enlarged IO Slot Count for
 *                                                 all nodes
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
static void hdatGetEnlargedIOCapacity(uint32_t &o_EnlargedSlotCount)
{
    HDAT_ENTER();
    TARGETING::PredicateCTM l_nodePredicate(TARGETING::CLASS_ENC,
                                             TARGETING::TYPE_NODE);
    TARGETING::PredicateHwas l_predHwas;
    l_predHwas.present(true);

    TARGETING::PredicatePostfixExpr l_presentNode;
    l_presentNode.push(&l_nodePredicate).push(&l_predHwas).And();

    TARGETING::TargetRangeFilter l_nodeFilter(
                                        TARGETING::targetService().begin(),
                                        TARGETING::targetService().end(),
                                        &l_presentNode);

    o_EnlargedSlotCount = 0;
    uint8_t l_nodeindex = 3;

    for (;l_nodeFilter;++l_nodeFilter)
    {
        TARGETING::Target *l_nodeTarget = (*l_nodeFilter);

        TARGETING::ATTR_ENLARGED_IO_SLOT_COUNT_type l_enlargedIOSlotCount;
        if(l_nodeTarget->tryGetAttr<TARGETING::ATTR_ENLARGED_IO_SLOT_COUNT>
                                                        (l_enlargedIOSlotCount))
        {
            HDAT_DBG("l_enlargedIOSlotCount=0x%x",l_enlargedIOSlotCount);
            o_EnlargedSlotCount |= (uint32_t)l_enlargedIOSlotCount <<
                                                       (8 * l_nodeindex);
        }
        else
        {
            HDAT_ERR("Error in getting ENLARGED_IO_SLOT_COUNT attribute");
        }
        l_nodeindex--;
    }
HDAT_DBG("o_EnlargedSlotCount=0x%x",o_EnlargedSlotCount);
HDAT_EXIT();
}

/**
 * @brief This routine gets the information for IPL Parameters
 *
 * @pre None
 *
 * @post None
 *
 * @param o_hdatOTA - output parameter - The structure to update with the
 *                                       other IPL attributes
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
static void hdatPopulateOtherIPLAttributes(hdatOtherIPLAttributes_t &o_hdatOTA)
{
    HDAT_ENTER();
    TARGETING::Target *l_pSysTarget = NULL;
    (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

    if(l_pSysTarget == NULL)
    {
        HDAT_ERR("Error in getting Top Level Target");
        assert(l_pSysTarget != NULL);
    }

    TARGETING::ATTR_IPL_ATTRIBUTES_type l_iplAttributes;
    l_iplAttributes = l_pSysTarget->getAttr<TARGETING::ATTR_IPL_ATTRIBUTES>();

    o_hdatOTA.hdatCreDefPartition = l_iplAttributes.createDefaultPartition;

    o_hdatOTA.hdatCTAState = l_iplAttributes.clickToAcceptState;

    o_hdatOTA.hdatDisVirtIOConn = l_iplAttributes.disableVirtIO;

    o_hdatOTA.hdatResetPCINOs = l_iplAttributes.resetPCINumbers;

    o_hdatOTA.hdatClrPhypNvram = l_iplAttributes.clearHypNVRAM;


    TARGETING::ATTR_PRESERVE_MDC_PARTITION_VPD_type l_preserveMDCPartitionVPD;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_PRESERVE_MDC_PARTITION_VPD>
                                                   (l_preserveMDCPartitionVPD))
    {
        o_hdatOTA.hdatMDCLogPartVPD = l_preserveMDCPartitionVPD;
    }
    else
    {
        HDAT_ERR("Error in getting PRESERVE_MDC_PARTITION_VPD attribute");
    }

    //No CEC CM Capability on these systems
    o_hdatOTA.hdatCECCMCapable = 0;

    //i5/OS not available on this system
    o_hdatOTA.hdati5OSEnable = 0;

    o_hdatOTA.hdatSELFlagsValid = 1;

    o_hdatOTA.hdatDelSELFromHyp = 1;

    o_hdatOTA.hdatDelSELFromHB = 1;

    o_hdatOTA.hdatDelSELFromBMC = 1;

    //Lightpath support available on these systems
    o_hdatOTA.hdatServiceIndMode = 1;

    //RPA AIX/Linux
    o_hdatOTA.hdatDefPartitionType = 1;
    HDAT_EXIT();
}

/**
 * @brief This routine gets the information for IPL Parameters
 *
 * @pre None
 *
 * @post None
 *
 * @param None
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
void  HdatIplParms::hdatGetIplParmsData()
{
    TARGETING::Target *l_pSysTarget = NULL;
    (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);
    if(l_pSysTarget == NULL)
    {
        HDAT_ERR("Error in getting Top Level Target");
        assert(l_pSysTarget != NULL);
    }

    //IPL to hypervisor running
    this->iv_hdatIPLParams->iv_iplParms.hdatIPLDestination = 0x02;

    //@TODO RTC 258465 HDAT: eBMC fetching the IPL side from
    //BIOS (Boot) parameter of PLDM
    this->iv_hdatIPLParams->iv_iplParms.hdatIPLSide =
                                     HDAT_FIRMWARE_SIDE_TEMPORARY;
    // Fast IPL Speed
    this->iv_hdatIPLParams->iv_iplParms.hdatIPLSpeed = 0xFF;


    TARGETING::ATTR_IS_MPIPL_HB_type l_mpiplHB;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_IS_MPIPL_HB>(l_mpiplHB))
    {
        if(l_mpiplHB)
        {
            this->iv_hdatIPLParams->iv_iplParms.hdatCECIPLAttributes = 0x2000;
            this->iv_hdatIPLParams->iv_iplParms.hdatIPLMajorType = 0x01;
            this->iv_hdatIPLParams->iv_iplParms.hdatIPLMinorType = 0x0D;
        }
        else
        {
            this->iv_hdatIPLParams->iv_iplParms.hdatCECIPLAttributes = 0x1000;
            this->iv_hdatIPLParams->iv_iplParms.hdatIPLMajorType = 0x00;
            this->iv_hdatIPLParams->iv_iplParms.hdatIPLMinorType = 0x0C;

            //@TODO: RTC 142465 missing attribute
            //ATTR_CEC_IPL_TYPE was supposed to provide IPL minor type data
            //Need to update it and use once we have more requirements
            HDAT_DBG("hdatGetIplParmsData: setting hdatIPLMinorType to 0x0C");
        }
    }
    else
    {
        this->iv_hdatIPLParams->iv_iplParms.hdatCECIPLAttributes = 0x1000;
        this->iv_hdatIPLParams->iv_iplParms.hdatIPLMajorType = 0x00;
        this->iv_hdatIPLParams->iv_iplParms.hdatIPLMinorType = 0x0C;
        HDAT_DBG("hdatGetIplParmsData: setting hdatIPLMinorType to 0x0C");
        HDAT_ERR("Error in getting IS_MPIPL_HB attribute");
    }

    TARGETING::ATTR_OS_IPL_MODE_type l_OSIPLMode;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_OS_IPL_MODE>(l_OSIPLMode))
    {
        this->iv_hdatIPLParams->iv_iplParms.hdatOSIPLMode = l_OSIPLMode;
    }
    else
    {
        HDAT_ERR("Error in getting OS_IPL_MODE attribute");
    }

    this->iv_hdatIPLParams->iv_iplParms.hdatKeyLockPosition =
                                                     HDAT_KEYLOCK_MANUAL;

    //@TODO: RTC 142465 missing attribute
    //@TODO RTC 245661 to get from pldm bios
    /*TARGETING::ATTR_LMB_SIZE_type l_lmbSize;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_LMB_SIZE>(l_lmbSize))
    {
        this->iv_hdatIPLParams->iv_iplParms.hdatLMBSize = 4;
    }
    else
    {
        HDAT_ERR("Error in getting LMB_SIZE attribute");
    }*/

    //attribute LMB_SIZE not defined
    this->iv_hdatIPLParams->iv_iplParms.hdatLMBSize = 4;

    TARGETING::ATTR_MAX_HSL_OPTICONNECT_CONNECTIONS_type l_hslConnections;
    if(l_pSysTarget->tryGetAttr
                            <TARGETING::ATTR_MAX_HSL_OPTICONNECT_CONNECTIONS>
                                                           (l_hslConnections))
    {
        this->iv_hdatIPLParams->iv_iplParms.hdatMaxHSLConns = l_hslConnections;
    }
    else
    {
        HDAT_ERR("Error in getting MAX_HSL_OPTICONNECT_CONNECTIONS attribute");
    }

    hdatPopulateOtherIPLAttributes(this->iv_hdatIPLParams->iv_iplParms.hdatOIA);

    TARGETING::ATTR_HUGE_PAGE_COUNT_type l_hugePageCount;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_HUGE_PAGE_COUNT>
                                                           (l_hugePageCount))
    {
        this->iv_hdatIPLParams->iv_iplParms.hdatHugePageMemCount =
                                                             l_hugePageCount;
    }
    else
    {
        HDAT_ERR("Error in getting HUGE_PAGE_COUNT attribute");
    }

    TARGETING::ATTR_HUGE_PAGE_SIZE_type l_hugePageSize;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_HUGE_PAGE_SIZE>
                                                           (l_hugePageSize))
    {
        this->iv_hdatIPLParams->iv_iplParms.hdatHugePageMemSize =
                                                             l_hugePageSize;
    }
    else
    {
        HDAT_ERR("Error in getting HUGE_PAGE_SIZE attribute");
    }

    TARGETING::ATTR_VLAN_SWITCHES_type l_vlanSwitches;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_VLAN_SWITCHES>
                                                            (l_vlanSwitches))
    {
        this->iv_hdatIPLParams->iv_iplParms.hdatNumVlanSwitches =
                                                              l_vlanSwitches;
    }
    else
    {
        HDAT_ERR("Error in getting VLAN_SWITCHES attribute");
    }

    uint32_t hdatEnlargedIOCapacity = 0;
    hdatGetEnlargedIOCapacity(hdatEnlargedIOCapacity);
    this->iv_hdatIPLParams->iv_iplParms.hdatEnlargedIOCap =
                                                     hdatEnlargedIOCapacity;

}

/**
 * @brief This routine gets the information for SP serial ports
 *
 * @pre None
 *
 * @post None
 *
 * @param o_portArrayHdr - output parameter - Array header
 * @param o_ports        - output parameter - The structure to update with the
 *                                            serial port information
 *
 * @return A null error log handle if successful, else the return code pointed
 *         to by errlHndl_t contains one of:
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
static errlHndl_t hdatGetPortInfo(HDAT::hdatHDIFDataArray_t &o_portArrayHdr,
                                  hdatPortCodes_t o_ports[])
{
    errlHndl_t l_errlHndl = NULL;
    uint32_t   l_loopCnt  = 0;

    o_portArrayHdr.hdatOffset    = sizeof(HDAT::hdatHDIFDataArray_t);
    o_portArrayHdr.hdatAllocSize = sizeof(hdatPortCodes_t);
    o_portArrayHdr.hdatActSize   = sizeof(hdatPortCodes_t);
    o_portArrayHdr.hdatArrayCnt  = 0;

    TARGETING::PredicateCTM l_nodePredicate(TARGETING::CLASS_ENC,
                                             TARGETING::TYPE_NODE);

    TARGETING::PredicateHwas l_predHwas;
    l_predHwas.present(true);

    TARGETING::PredicatePostfixExpr l_presentNode;
    l_presentNode.push(&l_nodePredicate).push(&l_predHwas).And();

    //Get Node targets
    TARGETING::TargetRangeFilter l_nodeFilter(
                                        TARGETING::targetService().begin(),
                                        TARGETING::targetService().end(),
                                        &l_presentNode);

    TARGETING::Target *l_nodeTarget = (*l_nodeFilter);

    TARGETING::PredicateCTM l_serialPortPredicate(TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_UART);

    TARGETING::PredicatePostfixExpr l_presentSerialPort;
    l_presentSerialPort.push(&l_serialPortPredicate).push(&l_predHwas).And();

    TARGETING::TargetHandleList l_serialPortList;

    //Get Serial Port targets associated with service processor
    TARGETING::targetService().getAssociated(l_serialPortList, l_nodeTarget,
                       TARGETING::TargetService::CHILD,
                       TARGETING::TargetService::ALL,
                       &l_presentSerialPort);

    o_portArrayHdr.hdatArrayCnt = l_serialPortList.size();

    for (uint32_t l_idx = 0; l_idx < l_serialPortList.size(); ++l_idx)
    {
        TARGETING::Target *l_serialportTarget = l_serialPortList[l_idx];
        char l_locCode[64]={0};

        hdatGetLocationCode(l_serialportTarget,
                                         HDAT_SLCA_FRU_TYPE_CS,l_locCode);
        HDAT_DBG(" Serial Port Loc Code :%s", l_locCode);

        strncpy((char *)(o_ports[l_loopCnt].hdatLocCode),
                                  l_locCode,
                                   sizeof(o_ports[l_loopCnt].hdatLocCode));

        o_ports[l_loopCnt].hdatResourceId = l_serialportTarget->getAttr
                                              <TARGETING::ATTR_SLCA_RID>();

        // None of the ports are used for callhome
        o_ports[l_loopCnt].hdatCallHome = 0;
        l_loopCnt++;
    }

    return l_errlHndl;
}

/**
 * @brief This routine fetches the information on feature flags
 *
 * @pre None
 *
 * @post None
 *
 * @param o_featureFlagArrayHdr - output parameter - Array header
 * @param o_featureFlagSettings - output parameter - The structure to update
 *                                             with Feature flag information
 * @param o_featFlagArrSize     - output parameter - Feature flag array size
 *
 * @retval None
 */
static void hdatGetFeatureFlagInfo(
                           hdatHDIFVersionedDataArray_t &o_featureFlagArrayHdr,
                           hdatIplpFeatureFlagSetting_t o_featureFlagSettings[],
                           uint32_t & o_featFlagArrSize)
{
    TARGETING::Target *l_pSysTarget = NULL;
    (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

    if(l_pSysTarget == NULL)
    {
        HDAT_ERR("hdatGetFeatureFlagInfo::Top Level Target not found");
        assert(l_pSysTarget != NULL);
    }

    // Default the dd level to 1.0
    uint8_t l_ddLevel = HDAT_PROC_P10_DD_10;
    const hdatIplpFeatureFlagSetting_t * l_featFlagArr;
    uint32_t l_featFlagArrSize = 0;
    // Default single value for P10 is set as RISK 0
    // In older releases this was fetched from attribute ATTR_RISK_LEVEL
    uint8_t l_riskLvl = 0;

    // As of now only one DD level value is supported and if needed later, below
    // code needs to be uncommented
    // PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );
    // DD level is set
    // l_ddLevel = l_pvr.getDDLevel();

    // Default to P10 DD1.0
    uint8_t l_ddLvlIdx = HDAT_P10_DD_10_IDX;

    l_featFlagArr = hdatIplpFeatureFlagSettingsArray[l_riskLvl][l_ddLvlIdx];
    l_featFlagArrSize =
      sizeof(hdatIplpFeatureFlagSettingsArray[l_riskLvl][l_ddLvlIdx]);

    HDAT_DBG("Feature flag array size:0x%x, DD Level:0x%x "
             "Risk Level:0x%x",
             l_featFlagArrSize,
             l_ddLevel, l_riskLvl);

    o_featFlagArrSize = l_featFlagArrSize;
    o_featureFlagArrayHdr.hdatOffset    = sizeof(hdatHDIFVersionedDataArray_t);
    o_featureFlagArrayHdr.hdatAllocSize = sizeof(hdatIplpFeatureFlagSetting_t);
    o_featureFlagArrayHdr.hdatActSize   = sizeof(hdatIplpFeatureFlagSetting_t);
    o_featureFlagArrayHdr.hdatArrayCnt  =
        l_featFlagArrSize/sizeof(hdatIplpFeatureFlagSetting_t);
    o_featureFlagArrayHdr.hdatVersion   = HDAT_FEATURE_FLAG_VERSION::VERSION;

    memcpy(o_featureFlagSettings , l_featFlagArr, l_featFlagArrSize);
}

/**
 * @brief This routine gets the information for System Parameters
 *
 * @pre None
 *
 * @post None
 *
 * @param None
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 **/
void HdatIplParms::hdatGetSystemParamters()
{
    HDAT_ENTER();

    TARGETING::Target *l_pSysTarget = NULL;
    (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

    if(l_pSysTarget == NULL)
    {
      HDAT_ERR("hdatGetSystemParamters::Top Level Target not found");
      assert(l_pSysTarget != NULL);
    }

    // Get system information - system model
    uint32_t l_sysModel = 0;

    TARGETING::ATTR_RAW_MTM_type l_rawMTM = {0};
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_RAW_MTM>(l_rawMTM))
    {
        HDAT_DBG("fetched RAW_MTM as %s ", l_rawMTM);
        //we only want the last three bytes of the raw MTM, preceded by a 0x20
        l_sysModel = *((reinterpret_cast<uint32_t*>(l_rawMTM))+1);
        l_sysModel &= 0x00FFFFFF;
        l_sysModel |= 0x20000000;
        this->iv_hdatIPLParams->iv_sysParms.hdatSysModel = l_sysModel;
    }
    else
    {
        HDAT_ERR("Error in getting RAW_MTM attribute");
    }

    // Get system information - processor feature code
    // Processor Feature Code = CCIN of Anchor Card
    // No Anchor Card in BMC systems
    this->iv_hdatIPLParams->iv_sysParms.hdatProcFeatCode = 0;

    // Set the PVR
    PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );
    this->iv_hdatIPLParams->iv_sysParms.hdatEffectivePvr = l_pvr.word;

    HDAT_DBG(" Effective PVR :0X%x",
            this->iv_hdatIPLParams->iv_sysParms.hdatEffectivePvr);

    // Get system type
    iv_hdatIPLParams->iv_sysParms.hdatSysType =
             (l_pSysTarget->getAttr<TARGETING::ATTR_PHYP_SYSTEM_TYPE>());
    HDAT_DBG("System Type:0X%08X", iv_hdatIPLParams->iv_sysParms.hdatSysType);

    //Setting both ABC Bus Speed and XYZ Bus Speed as 0.
    //Both values are deprecated and moved to PCRD.
    this->iv_hdatIPLParams->iv_sysParms.hdatABCBusSpeed = 0x0;
    this->iv_hdatIPLParams->iv_sysParms.hdatWXYZBusSpeed = 0x0;

    // NO ECO Support
    this->iv_hdatIPLParams->iv_sysParms.hdatSystemECOMode = 0;

    this->iv_hdatIPLParams->iv_sysParms.hdatSystemAttributes = 0;

    //Populate SMM Enabled/Disabled attribute
    TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM_type l_payLoadMirrorMem;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM>
                                                         (l_payLoadMirrorMem))
    {
        this->iv_hdatIPLParams->iv_sysParms.hdatSystemAttributes |=
             ( static_cast<uint8_t>(l_payLoadMirrorMem) ? HDAT_SMM_ENABLED : 0);
    }
    else
    {
        HDAT_ERR(" Error in getting attribute PAYLOAD_IN_MIRROR_MEM");
    }
    HDAT_DBG("after selective memory mirroring");

    //@TODO: RTC 256999 HDAT: Rainier- Revisit on MPIPL SUPPORTED flag
    //Its returning zero value
    this->iv_hdatIPLParams->iv_sysParms.hdatSystemAttributes |=
          l_pSysTarget->getAttr<ATTR_IS_MPIPL_SUPPORTED>() ? HDAT_MPIPL_SUPPORTED : 0 ;

    this->iv_hdatIPLParams->iv_sysParms.hdatSystemAttributes |= 
                                                           HDAT_MPIPL_SUPPORTED;

    this->iv_hdatIPLParams->iv_sysParms.hdatMemoryScrubbing = 0;

    // Get SPPL information
    uint32_t l_numCores;

    TARGETING::ATTR_OPEN_POWER_TURBO_MODE_SUPPORTED_type l_turboModeSupported;
    if(l_pSysTarget->tryGetAttr
                             <TARGETING::ATTR_OPEN_POWER_TURBO_MODE_SUPPORTED>
                                                        (l_turboModeSupported))
    {
        HDAT::hdatGetNumberOfCores(l_numCores);
        HDAT_DBG("got number of cores %d",l_numCores);

        if(l_turboModeSupported == true)
        {
            this->iv_hdatIPLParams->iv_sysParms.hdatCurrentSPPLValue =
                                            HDAT_TURBO_CORE_MODE_PART_SIZE_128;
        }
        else if( l_numCores == 6 )
        {
            this->iv_hdatIPLParams->iv_sysParms.hdatCurrentSPPLValue =
                                          HDAT_NONTURBO_SIX_CORE_PART_SIZE_256;
        }
        else if( l_numCores == 8 )
        {
            this->iv_hdatIPLParams->iv_sysParms.hdatCurrentSPPLValue =
                                        HDAT_NONTURBO_EIGHT_CORE_PART_SIZE_256;
        }
    }
    else
    {
        HDAT_ERR("Error in getting OPEN_POWER_TURBO_MODE_SUPPORTED attribute");
    }

    this->iv_hdatIPLParams->iv_sysParms.usePoreSleep  = 0x01;

    TARGETING::ATTR_VTPM_ENABLED_type l_vTpmEnabled;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_VTPM_ENABLED>
                                                        (l_vTpmEnabled))
    {
        this->iv_hdatIPLParams->iv_sysParms.vTpmEnabled = l_vTpmEnabled;
    }
    else
    {
        HDAT_ERR("Error in getting VTPM_ENABLED attribute");
    }
    HDAT_DBG("after VTPM_ENABLED");

    //HW Page Table Size : 0x07 : 1/128
    this->iv_hdatIPLParams->iv_sysParms.hdatHwPageTbl = 0x07;

    TARGETING::ATTR_HYP_DISPATCH_WHEEL_type l_hyperDispatchWheel;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_HYP_DISPATCH_WHEEL>
                                                      (l_hyperDispatchWheel))
    {
        if(!l_hyperDispatchWheel)
        {
            l_hyperDispatchWheel = 0x0a;
        }
        this->iv_hdatIPLParams->iv_sysParms.hdatDispWheel =
                                                        l_hyperDispatchWheel;
    }
    else
    {
        HDAT_ERR("Error in getting HYP_DISPATCH_WHEEL attribute");
    }
    HDAT_DBG("after HYP_DISPATCH_WHEEL");

    TARGETING::ATTR_FREQ_PAU_MHZ_type l_nestClockFreq;
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_FREQ_PAU_MHZ>
                                                         (l_nestClockFreq))
    {
        this->iv_hdatIPLParams->iv_sysParms.hdatNestFreq =
                                       static_cast<uint32_t>(l_nestClockFreq);
    }
    else
    {
        HDAT_ERR("Error in getting FREQ_PAU_MHZ");
    }
    HDAT_DBG("after FREQ_PAU_MHZ");

    this->iv_hdatIPLParams->iv_sysParms.hdatSplitCoreMode = 1;

    TARGETING::ATTR_SYSTEM_BRAND_NAME_type l_systemBrandName = {0};
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_SYSTEM_BRAND_NAME>
                                                         (l_systemBrandName))
    {
        strcpy(reinterpret_cast<char*>
                   (this->iv_hdatIPLParams->iv_sysParms.hdatSystemVendorName),
                                                           l_systemBrandName);
    }
    else
    {
        HDAT_ERR("Error in getting SYSTEM_BRAND_NAME");
    }
    HDAT_DBG("after SYSTEM_BRAND_NAME");

    // The next 5 fields are set to their final values in a common handler
    // in istep 21.1, to avoid trust issues when HDAT is initially populated
    // by a service processor
    this->iv_hdatIPLParams->iv_sysParms.hdatSysSecuritySetting = 0;

    this->iv_hdatIPLParams->iv_sysParms.hdatTpmConfBits = 0;

    this->iv_hdatIPLParams->iv_sysParms.hdatTpmDrawer = 0;
    this->iv_hdatIPLParams->iv_sysParms.hdatHwKeyHashSize = 0;
    memset(this->iv_hdatIPLParams->iv_sysParms.hdatHwKeyHashValue, 0x00,
        sizeof(this->iv_hdatIPLParams->iv_sysParms.hdatHwKeyHashValue));
    memset(this->iv_hdatIPLParams->iv_sysParms.hdatSystemFamily, 0x00, 64);

    TARGETING::ATTR_SYSTEM_FAMILY_type l_systemFamily = {0};
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_SYSTEM_FAMILY> (l_systemFamily))
    {
        strcpy(reinterpret_cast<char*>
               (this->iv_hdatIPLParams->iv_sysParms.hdatSystemFamily),
               l_systemFamily);
    }
    else
    {
        HDAT_ERR("Error in getting SYSTEM_FAMILY");
    }
     
    HDAT_DBG("SYSTEM_FAMILY:%s",
        this->iv_hdatIPLParams->iv_sysParms.hdatSystemFamily);

    TARGETING::ATTR_SYSTEM_TYPE_type l_systemType = {0};
    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_SYSTEM_TYPE> (l_systemType))
    {
        strcpy(reinterpret_cast<char*>
               (this->iv_hdatIPLParams->iv_sysParms.hdatSystemType),
               l_systemType);
    }
    else
    {
        HDAT_ERR("Error in getting SYSTEM_TYPE");
    }
     
    HDAT_DBG("SYSTEM_TYPE:%s",
        this->iv_hdatIPLParams->iv_sysParms.hdatSystemType);
    HDAT_EXIT();
}

/**
 * @brief This routine gets the IPL Time Delta Structure
 *
 * @pre None
 *
 * @post None
 *
 * @param o_iplTime - output parameter - IPLTime Data
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
void hdatGetIPLTimeData(hdatIplTimeData_t & o_iplTime)
{
    //RTC and Delta values marked as invalid
    o_iplTime.hdatRTCValidFlags = 0;

    //Cumulative RTC Delta value is reset
    o_iplTime.hdatCumulativeRTCDelta = 0;
}


/**
 * @brief This routine gets the Manufacturing Flags
 *
 * @pre None
 *
 * @post None
 *
 * @param o_hdatManfFlags - output parameter - Manufacturing Flags
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
void hdatGetMnfgFlags(hdatManf_t &o_hdatManfFlags)
{
    TARGETING::ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags;
    // Set HDAT Policy Flags to the manufacturing flags
    TARGETING::getAllMfgFlags(l_allMfgFlags);
    memcpy(o_hdatManfFlags.hdatPolicyFlags, l_allMfgFlags.data(),
           TARGETING::MFG_FLAG_SIZE_OF_ALL_CELLS_IN_BYTES);

    // Explicitly set the mask to the individual cells to delineate each cell
    // from each other and to explicitly mark each as cell 0, cell 1, etc.
    // Identifying each cell is done to keep inline with previous
    // code that did the same.
    o_hdatManfFlags.hdatPolicyFlags[TARGETING::MFG_FLAG_CELL_0_INDEX] |=
                                            TARGETING::MFG_FLAG_CELL_0_MASK;
    o_hdatManfFlags.hdatPolicyFlags[TARGETING::MFG_FLAG_CELL_1_INDEX] |=
                                            TARGETING::MFG_FLAG_CELL_1_MASK;
    o_hdatManfFlags.hdatPolicyFlags[TARGETING::MFG_FLAG_CELL_2_INDEX] |=
                                            TARGETING::MFG_FLAG_CELL_2_MASK;
    o_hdatManfFlags.hdatPolicyFlags[TARGETING::MFG_FLAG_CELL_3_INDEX] |=
                                            TARGETING::MFG_FLAG_CELL_3_MASK;
}

/**
 * @brief This routine populates dump data table
 *
 * @pre None
 *
 * @post None
 *
 * @param o_hdatDump
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
void hdatGetPlatformDumpData(hdatDump_t &o_hdatDump)
{
    o_hdatDump.hdatReserved2 = 0;
    o_hdatDump.hdatHypDumpPolicy = 0;
    memset(o_hdatDump.hdatReserved3, 0 , sizeof(o_hdatDump.hdatReserved3));
    o_hdatDump.hdatMaxHdwSize = 0;
    o_hdatDump.hdatActHdwSize = 0;
    o_hdatDump.hdatMaxSpSize = 0;

    o_hdatDump.hdatFlags = 0x0;

    //For the current OpenPOWER P9 systems (where hostboot
    // builds the HDAT) anytime we do an MPIPL there
    //will a memory dump.  Use the HDAT flags to indicate this
    //Note that in the future there will be MPIPLs that
    //are not dumps -- but will deal with that when the function
    //has been added
    // flags - set hdatRptPending, hdatMemDumpExists, hdatMemDumpReq:
    TargetService& l_targetService = targetService();
    Target* l_sys = nullptr;
    l_targetService.getTopLevelTarget(l_sys);
    if(l_sys->getAttr<ATTR_IS_MPIPL_HB>())
    {
        o_hdatDump.hdatRptPending = 0x1;
        o_hdatDump.hdatMemDumpExists = 0x1;
        o_hdatDump.hdatMemDumpReq = 0x1;
    }

    o_hdatDump.hdatDumpId = 0;
    o_hdatDump.hdatActPlatformDumpSize = 0; // PHYP/OPAL can query from MDRT
    o_hdatDump.hdatPlid = 0;

}

/**
 * @brief This routine sets the Header information for IPL
 *        Parameters structure
 *
 * @pre None
 *
 * @post None
 *
 * @param o_iplparams - Output Parameter - IPL Parameter headers
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
static void hdatSetIPLParamsHdrs(hdatIPLParameters_t *o_iplparams)
{

    o_iplparams->hdatHdr.hdatStructId       = HDAT_HDIF_STRUCT_ID;
    o_iplparams->hdatHdr.hdatInstance       = 0;
    o_iplparams->hdatHdr.hdatVersion        = HDAT_IPL_PARAMS_VERSION;
    o_iplparams->hdatHdr.hdatSize           = sizeof(hdatIPLParameters_t);
    o_iplparams->hdatHdr.hdatHdrSize        = sizeof(hdatHDIF_t);
    o_iplparams->hdatHdr.hdatDataPtrOffset  = sizeof(hdatHDIF_t);
    o_iplparams->hdatHdr.hdatDataPtrCnt     = HDAT_IPL_PARAMS_DA_CNT;
    o_iplparams->hdatHdr.hdatChildStrCnt    = 0;
    o_iplparams->hdatHdr.hdatChildStrOffset = 0;

    // Set the feature flag array size
    uint32_t l_featureFlagArrSize = 0;
    l_featureFlagArrSize = sizeof(hdatIplpFeatureFlagSettingsArray[0][0]);

    memcpy(o_iplparams->hdatHdr.hdatStructName, HDAT_IPLP_STRUCT_NAME,
            sizeof(o_iplparams->hdatHdr.hdatStructName));

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_SYS_PARAMS].hdatOffset =
        offsetof(hdatIPLParameters_t,iv_sysParms);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_SYS_PARAMS].hdatSize =
        sizeof(hdatSysParms_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_IPL_PARAMS].hdatOffset =
        offsetof(hdatIPLParameters_t,iv_iplParms);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_IPL_PARAMS].hdatSize =
        sizeof(hdatIPLParams_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_TIME_DATA].hdatOffset =
        offsetof(hdatIPLParameters_t,iv_iplTime);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_TIME_DATA].hdatSize =
        sizeof(hdatIplTimeData_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_SPPL_PARAMS].hdatOffset =
        offsetof(hdatIPLParameters_t,iv_pvt);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_SPPL_PARAMS].hdatSize =
        sizeof(hdatIplSpPvt_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_PDUMP_DATA].hdatOffset =
        offsetof(hdatIPLParameters_t, iv_dump);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_PDUMP_DATA].hdatSize =
        sizeof(hdatDump_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_HMC_CONNS].hdatOffset =
        offsetof(hdatIPLParameters_t, iv_hmc);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_HMC_CONNS].hdatSize =
        sizeof(hdatHmc_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_CUOD_DATA].hdatOffset =
        offsetof(hdatIPLParameters_t, iv_cuod);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_CUOD_DATA].hdatSize =
        sizeof(hdatCuod_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_MFG_DATA].hdatOffset =
        offsetof(hdatIPLParameters_t, iv_manf);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_MFG_DATA].hdatSize =
        sizeof(hdatManf_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_SERIAL_PORTS].hdatOffset =
        offsetof(hdatIPLParameters_t, iv_portArrayHdr);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_SERIAL_PORTS].hdatSize =
        sizeof(hdatHDIFDataArray_t) + sizeof(hdatPortCodes_t);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_FEATURE_FLAGS].hdatOffset =
        offsetof(hdatIPLParameters_t, iv_featureFlagArrayHdr);

    o_iplparams->hdatIPLParamsIntData[HDAT_IPL_PARAMS_FEATURE_FLAGS].hdatSize =
        sizeof(hdatHDIFVersionedDataArray_t) + l_featureFlagArrSize;


}

/**
 * @brief Constructor for IPL Parameters  construction class
 *
 * @pre None
 *
 * @post None
 *
 * @param o_errlHndl - output parameter - Error Handlea
 *        i_msAddr - Mainstore address where IPL Params
 *                   structure is loaded
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
HdatIplParms::HdatIplParms(errlHndl_t &o_errlHndl,
                           const HDAT::hdatMsAddr_t &i_msAddr)
{
    o_errlHndl = NULL;

    // Copy the main store address for the pcia data
    memcpy(&iv_msAddr, &i_msAddr, sizeof(hdatMsAddr_t));

    uint64_t l_base_addr = ((uint64_t) i_msAddr.hi << 32) | i_msAddr.lo;

    void *l_virt_addr = mm_block_map (
                         reinterpret_cast<void*>(ALIGN_PAGE_DOWN(l_base_addr)),
                         (ALIGN_PAGE(sizeof(hdatIPLParameters_t))+ PAGESIZE));

    l_virt_addr = reinterpret_cast<void *>(
                    reinterpret_cast<uint64_t>(l_virt_addr) +
                    (l_base_addr - ALIGN_PAGE_DOWN(l_base_addr)));

    // initializing the space to zero
    memset(l_virt_addr ,0x0, sizeof(hdatIPLParameters_t));

    iv_hdatIPLParams = reinterpret_cast<hdatIPLParameters_t *>(l_virt_addr);

    HDAT_DBG("Ctr iv_hdatIPLParams addr 0x%016llX virtual addr 0x%016llX",
                  (uint64_t) this->iv_hdatIPLParams, (uint64_t)l_virt_addr);

}

/**
 * @brief Load IPL Paramsters to Mainstore
 *
 * @pre None
 *
 * @post None
 *
 * @param o_size - output parameter - Size of IPL Parameters structure
 *        o_count - output parameter - Number of IPL Parameters structures
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
errlHndl_t HdatIplParms::hdatLoadIplParams(uint32_t &o_size, uint32_t &o_count)
{
    errlHndl_t l_errl = NULL;

    //Set IPLParams Headers
    hdatSetIPLParamsHdrs(this->iv_hdatIPLParams);

    //Get the FSP private IPL type
    TARGETING::Target *l_pSysTarget = NULL;
    (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

    if(l_pSysTarget == NULL)
    {
        HDAT_ERR("Error in getting Top Level target");
        assert(l_pSysTarget != NULL);
    }

    //Initializing SP IPL Type to Power On Reset
    this->iv_hdatIPLParams->iv_pvt.hdatIplType = 0x00000801;

    // Get the IPL parameters data
    hdatGetIplParmsData();

    // Get the IPL time data
    hdatGetIPLTimeData(this->iv_hdatIPLParams->iv_iplTime);

    // Get the System Parameters
    hdatGetSystemParamters();

    // Get HMC information
    memset(&this->iv_hdatIPLParams->iv_hmc, 0x00,
                                   sizeof(this->iv_hdatIPLParams->iv_hmc));

    // Get dump information
    hdatGetPlatformDumpData(this->iv_hdatIPLParams->iv_dump);

    // Get CUOD information
    this->iv_hdatIPLParams->iv_cuod.hdatCuodFlags = HDAT_POWER_OFF;

    // Get manufacturing mode information
    memset(&this->iv_hdatIPLParams->iv_manf, 0x00, sizeof(hdatManf_t));
    hdatGetMnfgFlags(this->iv_hdatIPLParams->iv_manf);

    // Get serial port information
    memset(&this->iv_hdatIPLParams->iv_portArrayHdr, 0x00,
                                         sizeof(HDAT::hdatHDIFDataArray_t));
    memset(this->iv_hdatIPLParams->iv_ports, 0x00, sizeof(hdatPortCodes_t) * 2);
    hdatGetPortInfo(this->iv_hdatIPLParams->iv_portArrayHdr,
                                         this->iv_hdatIPLParams->iv_ports);
    // Get the feature flag information
    memset(&this->iv_hdatIPLParams->iv_featureFlagArrayHdr, 0x00,
                                sizeof(HDAT::hdatHDIFVersionedDataArray_t));
    memset(&this->iv_hdatIPLParams->iv_featureFlagSettings, 0x00,
                  sizeof(hdatIplpFeatureFlagSetting_t) * MAX_FEATURE_FLAGS);
    this->iv_hdatIPLParams->iv_featureFlagArrSize = 0x00;
    hdatGetFeatureFlagInfo(this->iv_hdatIPLParams->iv_featureFlagArrayHdr,
                           this->iv_hdatIPLParams->iv_featureFlagSettings,
                           this->iv_hdatIPLParams->iv_featureFlagArrSize);

    HDAT_DBG("HDAT:: IPL Parameters Loaded :: Size : 0x%X",
                                      sizeof(hdatIPLParameters_t));

    o_count = 1;
    o_size  = sizeof(hdatIPLParameters_t);

    return l_errl;
}

/**
 * @brief Destructor for IPL Parameters construction class
 *
 * @pre None
 *
 * @post None
 *
 * @param None
 *
 * @return None
 *
 * @retval HDAT_OTHER_COMP_ERROR
 */
HdatIplParms::~HdatIplParms()
{
    int rc = 0;
    rc =  mm_block_unmap(iv_hdatIPLParams);
    if( rc != 0)
    {
        errlHndl_t l_errl = NULL;
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_IPLPARMS_DESTRUCTOR
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

    return;
}
};
