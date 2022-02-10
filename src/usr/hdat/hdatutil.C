/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatutil.C $                                     */
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

#include "hdatutil.H"
#include <eeprom/eepromif.H>
#include <stdio.h>
#include <string.h>
//*TODO RTC:216061 Re-enable when attr exists #include <p9_frequency_buckets.H>
#include <util/utilcommonattr.H>

// To fetch topology id related structures
#include <arch/memorymap.H>

#define UINT16_IN_LITTLE_ENDIAN(x) (((x) >> 8) | ((x) << 8))
#define HDAT_VPD_RECORD_START_TAG 0x84
#define HDAT_VPD_RECORD_END_TAG 0x78

using namespace TARGETING;
namespace HDAT
{
extern trace_desc_t *g_trac_hdat;

// HARD codes of sequoia and redbud GPU configurations for SMP link struct
// TODO:SW398487 : Need to replace this with PNOR : HDAT partition consumption.
// The below hardcoding is for temporary purpose but still valid values from mrw.

// SEQUOIA
const hdatSMPLinkInfo_t l_hdatSMPLinkInfoProc0_6gpucfg[] = {
 {0, 0x01,0x00,0xF1E000,11,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {2, 0x01,0x01,0x0E1870,11,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {4, 0x01,0x02,0x00078F,13,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,24,0},
 {6, 0x01,0x09,0x00078F,13,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,23,0},
 {8, 0x01,0x0A,0x0E1870,15,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,23,0},
 {10,0x01,0x0B,0xF1E000,15,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,24,0},
};
const hdatSMPLinkInfo_t l_hdatSMPLinkInfoProc1_6gpucfg[] = {
 {0, 0x01,0x00,0xF1E000,24,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {2, 0x01,0x01,0x0E1870,24,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {4, 0x01,0x02,0x00078F,26,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,23,0},
 {6, 0x01,0x09,0x00078F,26,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,24,0},
 {8, 0x01,0x0A,0x0E1870,28,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,24,0},
 {10,0x01,0x0B,0xF1E000,28,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,23,0},
};

// REDBUD
const hdatSMPLinkInfo_t l_hdatSMPLinkInfoProc0_4gpucfg[] = {
 {1, 0x01,0x00,0xF1E000,11,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {3, 0x01,0x01,0x0E1870,11,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {5, 0x01,0x02,0x00078F,11,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {7, 0x01,0x09,0x00078F,13,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,24,0},
 {9, 0x01,0x0A,0x0E1870,13,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,24,0},
 {11,0x01,0x0B,0xF1E000,13,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,24,0}
};
const hdatSMPLinkInfo_t l_hdatSMPLinkInfoProc1_4gpucfg[] = {
 {1, 0x01,0x00,0xF1E000,24,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {3, 0x01,0x01,0x0E1870,24,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {5, 0x01,0x02,0x00078F,24,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,22,0},
 {7, 0x01,0x09,0x00078F,26,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,23,0},
 {9, 0x01,0x0A,0x0E1870,26,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,23,0},
 {11,0x01,0x0B,0xF1E000,26,0xFFFF,0xFF,0x00,0xFF,0xFF,0xFF,2,23,0}
};



/*****************************************************************************n
*  hdatBldErrLog
*******************************************************************************/
void hdatBldErrLog(errlHndl_t &   io_err,
                   const uint8_t  i_modid,
                   const uint16_t i_rc,
                   const uint32_t i_data1,
                   const uint32_t i_data2,
                   const uint32_t i_data3,
                   const uint32_t i_data4,
                   const ERRORLOG::errlSeverity_t i_sev,
                   const uint16_t i_version,
                   const bool i_commit,
                   const bool i_callout )
{
    HDAT_DBG("mod:0x%02X, rc:0x%02X, data:%08X %08X %08X %08X, sev:0x%02X",
             i_modid, i_rc, i_data1, i_data2, i_data3, i_data4,
             i_sev);

    if (NULL == io_err)
    {
        io_err = new ERRORLOG::ErrlEntry(i_sev,
                                         i_modid,
                                         i_rc,
                                         TWO_UINT32_TO_UINT64(i_data1,i_data2),
                                         TWO_UINT32_TO_UINT64(i_data3,i_data4));
    }
    else
    {
        uint32_t additionalSrc[] =
        {
            uint32_t(HDAT_COMP_ID | i_rc), uint32_t(i_modid),
            uint32_t(i_sev),
            i_data1, i_data2, i_data3, i_data4
        };
        io_err->addFFDC(HDAT_COMP_ID,
                        additionalSrc,
                        sizeof(additionalSrc),
                        i_version,
                        SUBSEC_ADDITIONAL_SRC);

    }

    if ( i_callout )
    {
        io_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_HIGH);
    }
    io_err->collectTrace(HDAT_COMP_NAME);
    io_err->collectTrace("HDAT_DBG");
    io_err->collectTrace("HDAT_ERR");

    if ( i_commit )
    {
        ERRORLOG::errlCommit(io_err,HDAT_COMP_ID);
    }
}


/*******************************************************************************
*  isFunctional
*******************************************************************************/
bool isFunctional( const Target* i_Target)
{
    bool o_funcState = false;
    errlHndl_t l_errl = NULL;
    do
    {
        if(NULL == i_Target)
        {
            HDAT_ERR("Input Target Pointer is NULL");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_UTIL_IS_FUNCTIONAL
             * @reasoncode       HDAT::RC_INVALID_OBJECT
             * @devdesc          Input Target Pointer is NULL
             * @custdesc         Firmware encountered an internal error
             */
            hdatBldErrLog(l_errl,
                MOD_UTIL_IS_FUNCTIONAL,
                RC_INVALID_OBJECT,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                HDAT_VERSION1,
                true);
            break;
        }
        else
        {
            o_funcState = i_Target->getAttr<ATTR_HWAS_STATE>().functional;
        }
    }while(0);
    return o_funcState;
}

/*******************************************************************************
*  hdatGetIdEc
*******************************************************************************/
errlHndl_t hdatGetIdEc(const Target *i_pTarget,
                           uint32_t &o_ecLevel,
                           uint32_t &o_chipId)
{
    errlHndl_t l_err = NULL;

    do
    {
        const TARGETING::Target *l_pCTarget = NULL;
        if(i_pTarget->getAttr<TARGETING::ATTR_CLASS>() != TARGETING::CLASS_CHIP)
        {
            l_pCTarget = getParentChip(i_pTarget);
            o_ecLevel = l_pCTarget->getAttr<TARGETING::ATTR_HDAT_EC>();
            o_chipId = l_pCTarget->getAttr<TARGETING::ATTR_CHIP_ID>();
        }
        else
        {
            o_ecLevel = i_pTarget->getAttr<TARGETING::ATTR_HDAT_EC>();
            o_chipId =  i_pTarget->getAttr<TARGETING::ATTR_CHIP_ID>();
        }
    }
    while(0);

    return l_err;
}

/*******************************************************************************
* hdatGetHwCardId
*******************************************************************************/
errlHndl_t hdatGetHwCardId(const Target *i_pTarget, uint32_t &o_cardId)
{
    HDAT_ENTER();
    errlHndl_t l_errl = NULL;
    do
    {
        if(NULL == i_pTarget)
        {
            HDAT_ERR("Input Target pointer is NULL.");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_UTIL_CARD_ID
             * @reasoncode       HDAT::RC_INVALID_OBJECT
             * @devdesc          Input Target Pointer is NULL
             * @custdesc         Firmware encountered an internal
             *                   error while retrieving target data
             */
            hdatBldErrLog(l_errl,
                     MOD_UTIL_CARD_ID,
                     RC_INVALID_OBJECT,
                     0,0,0,0);
            break;
        }
        if((i_pTarget->getAttr<ATTR_CLASS>() != CLASS_CARD)&&
            (i_pTarget->getAttr<ATTR_CLASS>() != CLASS_LOGICAL_CARD)&&
            (i_pTarget->getAttr<ATTR_CLASS>() != CLASS_CHIP))
        {
            HDAT_ERR("Input Target is class not supported.");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_UTIL_CARD_ID
             * @reasoncode       HDAT::RC_TARGET_UNSUPPORTED
             * @devdesc          Target is not currently supported
             * @custdesc         Firmware encountered an internal error
             *                   while retrieving attribute data
             */
            hdatBldErrLog(l_errl,
                        MOD_UTIL_CARD_ID,
                        RC_TARGET_UNSUPPORTED,
                        0,0,0,0);
            break;
        }
        TARGETING::TargetHandleList targetList;
        targetList.clear();
        getParentAffinityTargets(targetList,i_pTarget,
                    TARGETING::CLASS_ENC,TARGETING::TYPE_NODE);
        if(targetList.empty())
        {
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_UTIL_CARD_ID
             * @reasoncode       HDAT::RC_EMPTY_TARGET_LIST
             * @devdesc          Target list is empty
             * @custdesc         Firmware encountered an internal
             *                   error while retrieving target data
             */
            hdatBldErrLog(l_errl,
                MOD_UTIL_CARD_ID,
                RC_EMPTY_TARGET_LIST,
                0,0,0,0);
                break;
        }
        //get the parent node id
        TARGETING::Target* l_pNodeTarget = targetList[0];
        o_cardId = l_pNodeTarget->getAttr<ATTR_ORDINAL_ID>();
    }
    while(0);

    HDAT_EXIT();
    return l_errl;
}

/**
 * @brief This routine populates the MTM and Serial number attributes
                           of system Target
 *
 * @pre None
 *
 * @post None
 *
 * @param None
 *
 * @return None
 */
void hdatPopulateMTMAndSerialNumber()
{
    HDAT_ENTER();
    errlHndl_t l_errl = NULL;
    TARGETING::ATTR_RAW_MTM_type l_rawMTM = {};
    TARGETING::ATTR_SERIAL_NUMBER_type l_serialNumber = {};
    TARGETING::Target *l_pSysTarget = NULL;

    size_t     l_vpdSize = 0;

    (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);
    if(l_pSysTarget == NULL)
    {
        HDAT_ERR("Error in getting Top Level Target");
        assert(l_pSysTarget != NULL);
    }

    TARGETING::PredicateCTM l_nodePredicate(TARGETING::CLASS_ENC,
                                             TARGETING::TYPE_NODE);
    TARGETING::PredicateHwas l_predHwas;
    l_predHwas.present(true);

    TARGETING::PredicatePostfixExpr l_presentNode;
    l_presentNode.push(&l_nodePredicate).push(&l_predHwas).And();

    //Get all Nodes
    TARGETING::TargetRangeFilter l_nodeFilter(
                                        TARGETING::targetService().begin(),
                                        TARGETING::targetService().end(),
                                        &l_presentNode);

    TARGETING::Target *l_nodeTarget = (*l_nodeFilter);
    HDAT_DBG("before deviceRead  PVPD::VSYS, PVPD::TM");

   l_errl = deviceRead(l_nodeTarget, NULL, l_vpdSize,
            DEVICE_PVPD_ADDRESS( PVPD::VSYS, PVPD::TM ));

    if(l_errl == NULL)
    {
        uint8_t l_vpddata[l_vpdSize];

        l_errl = deviceRead(l_nodeTarget, l_vpddata, l_vpdSize,
                DEVICE_PVPD_ADDRESS( PVPD::VSYS, PVPD::TM ));

        if(l_errl == NULL)
        {
            const uint8_t l_mtmSize= 0x08;
            //phyp would requre just 8 character of MTM
            strncpy(l_rawMTM,reinterpret_cast<const char*>(l_vpddata),
                    l_mtmSize);
            HDAT_DBG("from deviceRead l_rawMTM=%s, l_vpddata=%s",l_rawMTM,l_vpddata);

            if(!l_pSysTarget->trySetAttr<TARGETING::ATTR_RAW_MTM>
                                                  (l_rawMTM))
            {
                HDAT_ERR("Error in setting MTM");
            }
        }
        else
        {
            HDAT_DBG("deviceRead on PVPD::VSYS, PVPD::TM returned error");
        }
    }
    else
    {
        HDAT_DBG("deviceRead on PVPD::VSYS, PVPD::TM returned error to fetch the vpd size");
    }
    if(l_errl)
    {
        ERRORLOG::errlCommit(l_errl,HDAT_COMP_ID);
    }

    if(!l_pSysTarget->trySetAttr<TARGETING::ATTR_RAW_MTM>
                         (l_rawMTM))
    {
        HDAT_ERR("Error in setting MTM");
    }

    HDAT_DBG("before deviceRead PVPD::VSYS, PVPD::SE");
    l_errl = deviceRead(l_nodeTarget, NULL, l_vpdSize,
            DEVICE_PVPD_ADDRESS( PVPD::VSYS, PVPD::SE ));

    if(l_errl == NULL)
    {
        uint8_t l_vpddata[l_vpdSize];

        l_errl = deviceRead(l_nodeTarget, l_vpddata, l_vpdSize,
                DEVICE_PVPD_ADDRESS( PVPD::VSYS, PVPD::SE ));

        if(l_errl == NULL)
        {
            const uint8_t l_serialSize = 0x07;
            //phyp would requre just 7 character of serial number
            strncpy(reinterpret_cast<char *>(l_serialNumber),
                    reinterpret_cast<const char*>(l_vpddata),l_serialSize);
            HDAT_DBG("from deviceRead l_serialNumber=%s and l_vpddata=%s",
                                                 l_serialNumber,l_vpddata);

            if(!l_pSysTarget->trySetAttr
                <TARGETING::ATTR_SERIAL_NUMBER>(l_serialNumber))
            {
                HDAT_ERR("Error in setting Serial Number");
            }
        }
    }
    if(!l_pSysTarget->trySetAttr
           <TARGETING::ATTR_SERIAL_NUMBER>(l_serialNumber))
    {
        HDAT_ERR("Error in setting Serial Number");
    }

    if(l_errl)
    {
        ERRORLOG::errlCommit(l_errl,HDAT_COMP_ID);
    }

    HDAT_EXIT();
}


/**
 * @brief This routine constructs the location Code for the incoming target
 *
 * @pre None
 *
 * @post None
 *
 * @param i_pFruTarget    - input parameter - fru target
 *        i_frutype - input parameter - fru type
 *        o_locCode - output parameter - Constructed location code
 *
 * @return None
 */

void hdatGetLocationCode(TARGETING::Target *i_pFruTarget,
                         HDAT_FRUType_t i_frutype,
                         char *o_locCode)
{
    HDAT_ENTER();
    TARGETING::ATTR_PHYS_PATH_type l_physPath;
    TARGETING::ATTR_STATIC_ABS_LOCATION_CODE_type l_absLocationCode;
    TARGETING::ATTR_CHASSIS_LOCATION_CODE_type l_chassisLocationCode;
    TARGETING::ATTR_SYS_LOCATION_CODE_type l_sysLocationCode;
    char *l_pPhysPath;
    char l_locCode[64] = {0};


    HDAT_DBG("entered hdatGetLocationCode with fru type 0x%x",i_frutype);
    TARGETING::Target *l_pSystemTarget = NULL;
    (void) TARGETING::targetService().getTopLevelTarget(l_pSystemTarget);
    if(l_pSystemTarget == NULL)
    {
        HDAT_ERR("Error in getting Top Level Target");
        assert(l_pSystemTarget != NULL);
    }

    if(i_frutype == HDAT_SLCA_FRU_TYPE_SV ||
       i_frutype == HDAT_SLCA_FRU_TYPE_VV)
    {
        HDAT_DBG("fru type VV or SV 0x%x only SYS_LOCATION_CODE",i_frutype);
        if(l_pSystemTarget->tryGetAttr<TARGETING::ATTR_SYS_LOCATION_CODE>
                           (l_sysLocationCode)
                       &&(strlen(l_sysLocationCode) > 0))
        {
            HDAT_DBG("fetched SYS_LOCATION_CODE %s for fru type %d",
                      l_sysLocationCode, i_frutype);
            sprintf(l_locCode, "%s",l_sysLocationCode);
        }
    }
    else
    {
        if(l_pSystemTarget->tryGetAttr<TARGETING::ATTR_CHASSIS_LOCATION_CODE>
                        (l_chassisLocationCode)
                    &&  (strlen(l_chassisLocationCode) > 0))
        {
            HDAT_DBG("fetched CHASSIS_LOCATION_CODE %s for fru type %d",
                          l_chassisLocationCode, i_frutype);
        }
        if(i_frutype == HDAT_SLCA_FRU_TYPE_EV)
        {
            HDAT_DBG("fru type EV 0x%x only CHASSIS_LOCATION_CODE",i_frutype);
            sprintf(l_locCode, "%s",l_chassisLocationCode);
        }

        else
        {
            if(i_pFruTarget->tryGetAttr
                   <TARGETING::ATTR_STATIC_ABS_LOCATION_CODE>(l_absLocationCode)
                          && (strlen(l_absLocationCode) > 0))
            {
                HDAT_DBG("fetched ATTR_STATIC_ABS_LOCATION_CODE %s",
                                                             l_absLocationCode);
                HDAT_DBG("l_chassisLocationCode=%s, l_absLocationCode=%s",
                            l_chassisLocationCode,l_absLocationCode);
                sprintf(l_locCode, "%s-%s",
                       l_chassisLocationCode,l_absLocationCode);
            }
         }
     }
     HDAT_DBG("l_locCode = %s",l_locCode);

     if ( strlen(l_locCode) <= 0)
     {
         if(i_pFruTarget->tryGetAttr<TARGETING::ATTR_PHYS_PATH>
                            (l_physPath))
         {
             HDAT_DBG("fetching the ATTR_PHYS_PATH for location code");
             char *l_cutString;
             char *l_suffix;

             l_pPhysPath = i_pFruTarget->getAttr
                            <TARGETING::ATTR_PHYS_PATH>().toString();

             l_cutString = strchr(l_pPhysPath, '/');
             l_suffix = l_cutString;

             while (l_cutString != NULL)
             {
                 l_suffix = l_cutString;
                 l_cutString = strchr(l_cutString+1, '/');
             }

             sprintf(l_locCode, "ufcs-%s",(l_suffix+1));
         }
         else
         {
             HDAT_ERR("Error accessing ATTR_PHYS_PATH attribute");
             return;
         }
     }

     uint8_t l_index = 0;
     while(l_index < strlen(l_locCode))
     {
         if(l_locCode[l_index] != ' ')
         {
             *o_locCode++ = l_locCode[l_index];
         }
         l_index++;
     }
     HDAT_EXIT();
}


/******************************************************************************/
//hdatGetAsciiKwd
/******************************************************************************/

errlHndl_t hdatGetAsciiKwd( TARGETING::Target * i_target,uint32_t &o_kwdSize,
           char* &o_kwd,vpdType i_vpdtype,struct vpdData i_fetchVpd[],
           uint32_t i_num, size_t theSize[],const HdatKeywordInfo i_Keywords[])
{
    HDAT_ENTER();
    errlHndl_t l_err = NULL;

    switch (i_vpdtype)
    {
        case PROC:
             l_err = hdatGetAsciiKwdForMvpd(i_target,o_kwdSize,o_kwd,
                                            i_fetchVpd,i_num,theSize);
             HDAT_DBG("got back kwd size=%x",o_kwdSize);
             break;
        case BP:
             l_err = hdatGetAsciiKwdForPvpd(i_target,o_kwdSize,o_kwd,
                                            i_fetchVpd,i_num,theSize,
                                            i_Keywords);
             HDAT_DBG("got back kwd size=%x",o_kwdSize);
             break;
        default:
             HDAT_DBG("no appropriate vpd function to call");
             break;
    }
    HDAT_EXIT();
    return l_err;
}//end hdatGetAsciiKwd

/******************************************************************************/
//hdatGetAsciiKwd
/******************************************************************************/

errlHndl_t hdatGetFullRecords( TARGETING::Target * i_target,uint32_t &o_kwdSize,
           char* &o_kwd,vpdType i_vpdtype,const IpVpdFacade::recordInfo i_fetchVpd[],
           uint32_t i_num, size_t theSize[])
{
    HDAT_ENTER();
    errlHndl_t l_err = NULL;

    switch (i_vpdtype)
    {
        case PROC:
             l_err = hdatGetMvpdFullRecord(i_target,o_kwdSize,o_kwd,
                                            i_fetchVpd,i_num,theSize);
             HDAT_DBG("got back kwd size=%x",o_kwdSize);
             break;
        case BP:
             l_err = hdatGetPvpdFullRecord(i_target,o_kwdSize,o_kwd,
                                            i_fetchVpd,i_num,theSize);
             HDAT_DBG("got back kwd size=%x",o_kwdSize);
             break;
        default:
             HDAT_ERR("No appropriate vpd function to call.");
             break;
    }
    HDAT_EXIT();
    return l_err;
}//end hdatGetAsciiKwd

/******************************************************************************/
//hdatGetAsciiKwdForPvpd
/******************************************************************************/
errlHndl_t hdatGetAsciiKwdForPvpd(TARGETING::Target * i_target,
           uint32_t &o_kwdSize,char* &o_kwd,
           struct vpdData i_fetchVpd[], size_t i_num, size_t theSize[],
           const HdatKeywordInfo i_Keywords[])
{
    HDAT_ENTER();
    HDAT_DBG("entered hdatGetAsciiKwdForPvpd with total number of kwds=%d ",
                               i_num);

    errlHndl_t l_err = NULL;
    uint64_t fails = 0x0;
    VPD::vpdRecord theRecord = 0x0;
    VPD::vpdKeyword theKeyword = 0x0;

    size_t viniSize{};
    uint32_t lxSize{};
    uint8_t numRecords = 2; //VINI and LXR0 for BP
    size_t numViniKwds{};
    size_t numLXKwds {};
    size_t cmds{};

    o_kwd = NULL;
    o_kwdSize = 0;
    memset (theSize,0, sizeof(size_t) * i_num);

    do
    {
        assert(i_target != NULL);

        uint8_t *theData = NULL;

        const uint32_t numCmds = i_num;

        for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
        {
            theRecord = i_fetchVpd[curCmd].record;
            theKeyword = i_fetchVpd[curCmd].keyword;

            if(theRecord == PVPD::LXR0 &&
                theKeyword == PVPD::RT)
            {
                numViniKwds = cmds;
                HDAT_DBG("starting LXR0 here ");
                viniSize = o_kwdSize;
                HDAT_DBG("so vini records size=0x%x, numViniKwds=0x%x",
                                               viniSize,numViniKwds);
            }

            l_err = deviceRead( i_target,
                              NULL,
                              theSize[curCmd],
                              DEVICE_PVPD_ADDRESS( theRecord,
                                                   theKeyword ) );
            if( l_err )
            {
                fails++;
                HDAT_DBG("hdatGetAsciiKwdForPvpd::failure reading keyword size "
                         "rec: 0x%04x, kwd: 0x%04x",
                         theRecord,theKeyword );
                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_UTIL_PVPD_READ_FUNC
                 * @reasoncode       HDAT::RC_PVPD_FAIL
                 * @userdata1        pvpd record
                 * @userdata2        pvpd keyword
                 * @devdesc          PVPD read fail
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(l_err,
                    MOD_UTIL_PVPD_READ_FUNC,
                    RC_PVPD_FAIL,
                    theRecord,theKeyword,0,0,
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HDAT_VERSION1,
                    true);

                continue;
            }
            cmds++;
            HDAT_DBG("fetching BP kwd size PVPD, size initialised=%x "
             " keyword =%04x",theSize[curCmd],theKeyword);
            o_kwdSize += theSize[curCmd];
        }
        numLXKwds = cmds - numViniKwds;
        lxSize = o_kwdSize - viniSize;
        HDAT_DBG("lxSize=0x%x and numLXKwds=0x%x",lxSize,numLXKwds);

        HDAT_DBG("hdatGetAsciiKwdForPvpd:: only all key word data size 0x%x",
                  o_kwdSize);
        uint8_t l_startTag = HDAT_VPD_RECORD_START_TAG;
        uint8_t l_endTag = HDAT_VPD_RECORD_END_TAG;
        uint32_t l_RecTagSize = 2 * sizeof(l_startTag);  // Size of start and end Tags for each record
        uint32_t l_wholeTagSize = l_RecTagSize * numRecords;  // Size of start and end tags for all records

        size_t totSize = o_kwdSize + l_wholeTagSize +   //kwd data size + start + end tag
                           (sizeof(uint16_t)*numRecords) *  //size val of all recs
                           i_num *2 +//total kwd name size
                           i_num * sizeof(uint8_t); //separator between kwds
        HDAT_DBG("actual totSize=%d",totSize);
        ////////
        size_t remSize = totSize % 4  + 32;
        totSize += remSize; //Phyp needs a stanza of 0s at the end
        HDAT_DBG("after adding an extra stanza totSize=%d",totSize);
        ////////
        o_kwdSize = totSize;

        o_kwd = new char[totSize]();
        HDAT_DBG("vini kwd Size=0x%x, numViniKwds=0x%x",viniSize,numViniKwds);
        uint16_t tmpVINISize = viniSize + numViniKwds * 1 + numViniKwds * 2;
        HDAT_DBG("VINI SIZE=0x%x",tmpVINISize);
        uint16_t tmpSize = UINT16_IN_LITTLE_ENDIAN(tmpVINISize);
        memcpy(reinterpret_cast<void *>(o_kwd),&l_startTag,sizeof(l_startTag));
        memcpy(reinterpret_cast<void *>(o_kwd+1),&tmpSize,sizeof(tmpSize));

        uint32_t loc = sizeof(uint16_t) + sizeof(uint8_t);
        for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
        {
            theRecord = i_fetchVpd[curCmd].record;
            theKeyword = i_fetchVpd[curCmd].keyword;

            //this conidtion is , if in the top loop there is a fail then
            //theSize[curCmd] will be 0.
            if( theSize[curCmd] == 0)
            {
                HDAT_DBG("theSize[curCmd] is 0");
                continue;
            }
            theData = new uint8_t [theSize[curCmd]];

            HDAT_DBG("hdatGetAsciiKwdForPvpd: reading %dth keyword of size %d",
                      curCmd,theSize[curCmd]);

            l_err = deviceRead( i_target,
                              theData,
                              theSize[curCmd],
                              DEVICE_PVPD_ADDRESS( theRecord,
                                                   theKeyword ) );
            HDAT_DBG("hdatGetAsciiKwdForPvpd: read BP KWD=%s, data %s",
                                       i_Keywords[curCmd].keywordName,theData);

            if ( l_err )
            {
                fails++;
                HDAT_DBG("hdatGetAsciiKwdForPvpd: Failure on Record: "
                "0x%04x, keyword: 0x%04x, of size: 0x%04x - test %d",
                theRecord,theKeyword,theSize,curCmd);
                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_UTIL_PVPD_READ_FUNC
                 * @reasoncode       HDAT::RC_PVPD_READ_FAIL
                 * @userdata1        pvpd record
                 * @userdata2        pvpd keyword
                 * @devdesc          PVPD read fail
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(l_err,
                    MOD_UTIL_PVPD_READ_FUNC,
                    RC_PVPD_READ_FAIL,
                    theRecord,theKeyword,0,0,
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HDAT_VERSION1,
                    true);

                if ( NULL != theData )
                {
                    delete[]  theData;
                    theData = NULL;
                }
                continue;
            }
            if ( NULL != theData )
            {
                if(theRecord == PVPD::LXR0 &&
                    theKeyword == PVPD::RT)
                {
                    HDAT_DBG("end writing VINI");
                     memcpy(reinterpret_cast<void *>(o_kwd + loc),&l_endTag,
                                                              sizeof(l_endTag));
                     memcpy(reinterpret_cast<void *>(o_kwd + loc+1),&l_startTag,
                                                            sizeof(l_startTag));
                     HDAT_DBG("lxSize=0x%x, numLXKwds=0x%x",lxSize,numLXKwds);
                     uint16_t tmpLxSize = lxSize + numLXKwds * 1 +
                                                                 numLXKwds * 2;
                     HDAT_DBG("LX SIZE=0x%x",tmpLxSize);
                     tmpSize = UINT16_IN_LITTLE_ENDIAN(tmpLxSize);
                     memcpy(reinterpret_cast<void *>(o_kwd + loc+2),
                                                     &tmpSize,sizeof(tmpSize));
                     loc += sizeof(l_startTag) *2 + sizeof(tmpSize);
                }
                memcpy(reinterpret_cast<void *>(o_kwd + loc),
                                            &i_Keywords[curCmd].keywordName, 2);
                loc += 2;
                uint8_t l_var = theSize[curCmd];
                memcpy(reinterpret_cast<void *>(o_kwd + loc),&l_var,
                            sizeof(uint8_t));
                loc += sizeof(uint8_t);
                memcpy(reinterpret_cast<void *>(o_kwd + loc),theData,
                       theSize[curCmd]);

                loc += theSize[curCmd];
                delete[] theData;
                theData = NULL;
                HDAT_DBG("hdatGetAsciiKwdForPvpd: copied to main array %d kwd",
                          curCmd);
            }
        }
        memcpy(reinterpret_cast<void *>(o_kwd + loc),&l_endTag,
                                                            sizeof(l_endTag));
    }while(0);

    HDAT_DBG("hdatGetAsciiKwdForPvpd: returning keyword size %d and data %s",
              o_kwdSize,o_kwd);
    HDAT_EXIT();
    return l_err;
}



/******************************************************************************/
//hdatGetPvpdFullRecord
/******************************************************************************/
errlHndl_t hdatGetPvpdFullRecord(TARGETING::Target * i_target,
           uint32_t &o_kwdSize,char* &o_kwd,
           const IpVpdFacade::recordInfo i_fetchVpd[], size_t i_num, size_t theSize[])
{
    HDAT_ENTER();

    errlHndl_t l_err = NULL;
    uint64_t fails = 0x0;
    VPD::vpdRecord theRecord = 0x0;
    size_t totSize{};


    o_kwd = NULL;
    o_kwdSize = 0;
    memset (theSize,0, sizeof(size_t) * i_num);

    do
    {
        assert(i_target != NULL , "Input target to collect the VPD is NULL");
        uint8_t *theData = NULL;

        const uint32_t numRecs = i_num;

        for( uint32_t curRec = 0; curRec < numRecs ; curRec++ )
        {
            theRecord = i_fetchVpd[curRec].record;

            l_err = deviceRead( i_target,
                              NULL,
                              theSize[curRec],
                              DEVICE_PVPD_ADDRESS( theRecord,
                                                   IPVPD::FULL_RECORD ) );
            if( l_err )
            {
                fails++;
                HDAT_DBG("hdatGetPvpdFullRecord::failure reading record size "
                         "rec: 0x%04x", theRecord );
                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_UTIL_PVPD_FULL_READ_FUNC
                 * @reasoncode       HDAT::RC_PVPD_FAIL
                 * @userdata1        pvpd record
                 * @devdesc          PVPD read fail
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(l_err,
                    MOD_UTIL_PVPD_FULL_READ_FUNC,
                    RC_PVPD_FAIL,
                    theRecord,0,0,0,
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HDAT_VERSION1,
                    false);
                    //@TODO:RTC 213229 Remove HDAT hack
                    //There are known differences where not all records will be
                    //present. So changing now from true to false.

                continue;
            }
            HDAT_DBG("fetching record size PVPD, size initialised=%x ",theSize[curRec]);
            o_kwdSize += theSize[curRec];
        }

        HDAT_DBG("hdatGetPvpdFullRecord:: allocating total Records size %d",
                  o_kwdSize);
        uint8_t l_startTag = HDAT_VPD_RECORD_START_TAG ;
        uint8_t l_endTag = HDAT_VPD_RECORD_END_TAG ;
        uint32_t l_RecTagSize = 2 * sizeof(uint8_t);  // Size of Tags for each record
        uint32_t l_wholeTagSize = l_RecTagSize * numRecs;  // Size of tags for all records
        //o_kwd = new char[o_kwdSize + l_wholeTagSize ];
        size_t remSize = (o_kwdSize + l_wholeTagSize) % 4 + 32;
        totSize = o_kwdSize + l_wholeTagSize + remSize;
        o_kwd = new char[totSize]();
        ////

        uint32_t loc = 0;
        for( uint32_t curRec = 0; curRec < numRecs; curRec++ )
        {
            theRecord = i_fetchVpd[curRec].record;

            //this condition is , if in the top loop there is a fail then
            //theSize[curRec] will be 0.
            if( theSize[curRec] == 0)
            {
                continue;
            }
            theData = new uint8_t [theSize[curRec]];

            HDAT_DBG("hdatGetPvpdFullRecord: reading %dth record of size %d",
                      curRec,theSize[curRec]);

            l_err = deviceRead( i_target,
                              theData,
                              theSize[curRec],
                              DEVICE_PVPD_ADDRESS( theRecord,
                                                   IPVPD::FULL_RECORD) );


            if ( l_err )
            {
                fails++;
                HDAT_DBG("hdatGetPvpdFullRecord: Failure on Record: "
                "0x%04x, of size: 0x%04x - test %d",
                theRecord,theSize[curRec],curRec);
                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_UTIL_PVPD_FULL_READ_FUNC
                 * @reasoncode       HDAT::RC_PVPD_READ_FAIL
                 * @userdata1        pvpd record
                 * @devdesc          PVPD read fail
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(l_err,
                    MOD_UTIL_PVPD_FULL_READ_FUNC,
                    RC_PVPD_READ_FAIL,
                    theRecord,0,0,0,
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HDAT_VERSION1,
                    true);

                if ( NULL != theData )
                {
                    delete[]  theData;
                    theData = NULL;
                }
                continue;
            }
            if ( NULL != theData )
            {
                memcpy(reinterpret_cast<void *>(o_kwd + loc), &l_startTag, sizeof(uint8_t));
                loc += sizeof(uint8_t);
                memcpy(reinterpret_cast<void *>(o_kwd + loc),theData,
                       theSize[curRec]);
                loc += theSize[curRec];
                memcpy(reinterpret_cast<void *>(o_kwd + loc), &l_endTag, sizeof(uint8_t));
                loc += sizeof(uint8_t);

                o_kwdSize += l_RecTagSize ; // Add each rec's tag size as well to final size
                delete[] theData;
                theData = NULL;
                HDAT_DBG("hdatGetPvpdFullRecord: copied to main array %d kwd",
                          curRec);
            }
        }
    }while(0);

    o_kwdSize = totSize;
    HDAT_DBG("hdatGetPvpdFullRecord: returning keyword size %d and data %s",
              o_kwdSize,o_kwd);
    HDAT_EXIT();
    return l_err;
}

/******************************************************************************/
// hdatGetAsciiKwdForMvpd
/******************************************************************************/

errlHndl_t hdatGetAsciiKwdForMvpd(TARGETING::Target * i_target,
           uint32_t &o_kwdSize,char* &o_kwd,
           struct vpdData i_fetchVpd[], uint32_t i_num,size_t theSize[])
{
    HDAT_ENTER();
    errlHndl_t err = NULL;
    uint64_t cmds = 0x0;
    uint64_t fails = 0x0;
    uint64_t theRecord = 0x0;
    uint64_t theKeyword = 0x0;

    o_kwd = NULL;
    o_kwdSize = 0;


    do
    {
        if(i_target == NULL)
        {
            HDAT_ERR("no functional Targets found");
            break;
        }

        //size_t theSize[100] = {0};//assuming max kwd num 100
        uint8_t *theData = NULL;


        for( uint32_t curCmd = 0; curCmd < i_num; curCmd++ )
        {
            cmds++;
            theRecord = (uint64_t)i_fetchVpd[curCmd].record;
            theKeyword = (uint64_t)i_fetchVpd[curCmd].keyword;

            HDAT_DBG("fetching proc kwd size MVPD, size initialised=%x",
                      theSize[curCmd]);
            err = deviceRead( i_target,
                              NULL,
                              theSize[curCmd],
                              DEVICE_MVPD_ADDRESS( theRecord,
                                                   theKeyword ) );
            HDAT_DBG("fetched proc kwd size MVPD, size=%x",theSize[curCmd]);

            if( err )
            {
                fails++;
                HDAT_DBG("failure reading keyword size "
                         "rec: 0x%04x, kwd: 0x%04x",
                         theRecord,theKeyword );
                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_UTIL_VPD
                 * @reasoncode       HDAT::RC_DEV_READ_FAIL
                 * @devdesc          Device read failed
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(err,
                    MOD_UTIL_VPD,
                    RC_DEV_READ_FAIL,
                    theRecord,theKeyword,0,0,
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HDAT_VERSION1,
                    true);
                continue;
            }
            o_kwdSize += theSize[curCmd];
        }

        HDAT_DBG("allocating total key word size %d",
                  o_kwdSize);
        //o_kwd = static_cast<char *>(malloc( o_kwdSize));
        o_kwd = new char[o_kwdSize];

        uint32_t loc = 0;
        for( uint32_t curCmd = 0; curCmd < i_num; curCmd++ )
        {
            theRecord = (uint64_t)i_fetchVpd[curCmd].record;
            theKeyword = (uint64_t)i_fetchVpd[curCmd].keyword;

            //theData = static_cast<uint8_t*>(malloc( theSize[curCmd] ));
            theData = new uint8_t [theSize[curCmd]];

            HDAT_DBG("reading %dth keyword of size %d",
                      curCmd,theSize[curCmd]);

            err = deviceRead( i_target,
                              theData,
                              theSize[curCmd],
                              DEVICE_MVPD_ADDRESS( theRecord,
                                                   theKeyword ) );
            HDAT_DBG("read PROC data %s",theData);

            if ( err )
            {
                fails++;
                HDAT_DBG("hdatGetAsciiKwdForMvpd: Failure on Record: "
                "0x%04x, keyword: 0x%04x, of size: 0x%04x - test %d",
                theRecord,theKeyword,theSize,curCmd);

                delete err;
                err = nullptr;

                if ( NULL != theData )
                {
                   // free( theData );
                    delete[] theData;
                    theData = NULL;
                }
                continue;
            }
            if ( NULL != theData )
            {
                //copy to output array and free theData
                memcpy(reinterpret_cast<void *>(o_kwd + loc),theData,
                       theSize[curCmd]);

                loc += theSize[curCmd];
                //free( theData );
                delete[] theData;
                theData = NULL;
                HDAT_DBG("copied to main array %d kwd",
                          curCmd);
            }
        }

    }while(0);

    HDAT_DBG("returning keyword size %d and data %s",
              o_kwdSize,o_kwd);

    HDAT_EXIT();
    return err;
}//end hdatGetAsciiKwdForMvpd




/******************************************************************************/
// hdatGetMvpdFullRecord
/******************************************************************************/

errlHndl_t hdatGetMvpdFullRecord(TARGETING::Target * i_target,
           uint32_t &o_kwdSize,char* &o_kwd,
           const IpVpdFacade::recordInfo i_fetchVpd[], uint32_t i_num,size_t theSize[])
{
    HDAT_ENTER();
    errlHndl_t err = NULL;
    uint64_t fails = 0x0;
    uint64_t theRecord = 0x0;

    o_kwd = NULL;
    o_kwdSize = 0;


    do
    {
        if(i_target == NULL)
        {
            HDAT_ERR("no functional Targets found");
            break;
        }

        uint8_t *theData = NULL;


        for( uint32_t curRec = 0; curRec < i_num; curRec++ )
        {
            theRecord = (uint64_t)i_fetchVpd[curRec].record;

            HDAT_DBG("fetching proc Record size MVPD, size initialised=%x",
                      theSize[curRec]);
            err = deviceRead( i_target,
                              NULL,
                              theSize[curRec],
                              DEVICE_MVPD_ADDRESS( theRecord,
                                                   MVPD::FULL_RECORD ) );
            HDAT_DBG("fetched proc Record size MVPD, size=%x",theSize[curRec]);

            if( err )
            {
                fails++;
                HDAT_DBG("failure reading Record size "
                         "rec: 0x%04x",theRecord);
                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_UTIL_MVPD
                 * @reasoncode       HDAT::RC_DEV_READ_FAIL
                 * @devdesc          Device read failed
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(err,
                    MOD_UTIL_MVPD,
                    RC_DEV_READ_FAIL,
                    theRecord,0,0,0,
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HDAT_VERSION1,
                    true);
                continue;
            }
            o_kwdSize += theSize[curRec];
        }

        HDAT_DBG("allocating total Records size %d",
                  o_kwdSize);

        uint8_t l_startTag = 0x84;
        uint8_t l_endTag = 0x78;
        uint32_t l_RecTagSize = 2 * sizeof(uint8_t);
        uint32_t l_wholeTagSize = l_RecTagSize * i_num;
        o_kwd = new char[o_kwdSize + l_wholeTagSize ];

        uint32_t loc = 0;
        for( uint32_t curRec = 0; curRec < i_num; curRec++ )
        {
            theRecord = (uint64_t)i_fetchVpd[curRec].record;

            theData = new uint8_t [theSize[curRec]];

            HDAT_DBG("reading %dth Record of size %d",
                      curRec,theSize[curRec]);

            err = deviceRead( i_target,
                              theData,
                              theSize[curRec],
                              DEVICE_MVPD_ADDRESS( theRecord,
                                                   MVPD::FULL_RECORD ) );

            HDAT_DBG("read PROC data %s",theData);

            if ( err )
            {
                fails++;
                HDAT_DBG("hdatGetMvpdFullRecord: Failure on Record: "
                "0x%04x,  of size: 0x%04x - test %d",
                theRecord,theSize,curRec);

                delete err;
                err = nullptr;

                if ( NULL != theData )
                {
                   // free( theData );
                    delete[] theData;
                    theData = NULL;
                }
                continue;
            }
            if ( NULL != theData )
            {
                memcpy(reinterpret_cast<void *>(o_kwd + loc), &l_startTag, sizeof(uint8_t));
                loc += sizeof(uint8_t);
                memcpy(reinterpret_cast<void *>(o_kwd + loc),theData,
                       theSize[curRec]);
                loc += theSize[curRec];
                memcpy(reinterpret_cast<void *>(o_kwd + loc), &l_endTag, sizeof(uint8_t));
                loc += sizeof(uint8_t);

                o_kwdSize += l_RecTagSize ; // Add each rec's tag size as well to final size

                delete[] theData;
                theData = NULL;
                HDAT_DBG("copied to main array %d kwd",
                          curRec);
            }
        }

    }while(0);

    HDAT_DBG("returning keyword size %d and data %s",
              o_kwdSize,o_kwd);

    HDAT_EXIT();
    return err;
}//end hdatGetMvpdFullRecord

/*******************************************************************************
* hdatGetMaxCecNodes
*******************************************************************************/

uint32_t hdatGetMaxCecNodes()
{
    TARGETING::TargetHandleList l_nodeTargetList;
    do
    {
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);

        PredicateCTM predNode(CLASS_ENC, TYPE_NODE);
        PredicateHwas predFunctional;
        predFunctional.functional(true);
        PredicatePostfixExpr nodeCheckExpr;
        nodeCheckExpr.push(&predNode).push(&predFunctional).And();
        targetService().getAssociated(l_nodeTargetList, sys,
        TargetService::CHILD, TargetService::IMMEDIATE,
        &nodeCheckExpr);

    }while(0);

    return l_nodeTargetList.size();
}

/*******************************************************************************
* hdatPrintHdrs
*******************************************************************************/
void hdatPrintHdrs(const hdatHDIF_t *i_hdif,
                     const hdatHDIFDataHdr_t *i_data,
                     const hdatHDIFDataArray_t *i_dataArray,
                     const hdatHDIFChildHdr_t *i_child)
{
    hdatHDIFDataHdr_t *l_data;
    hdatHDIFChildHdr_t *l_child;
    uint32_t l_idx;
    char l_string[sizeof(i_hdif->hdatStructName)+1];

    if (NULL != i_hdif)
    {
        // Null terminate the eye catcher string.
        memcpy(l_string, &i_hdif->hdatStructName,
                sizeof(i_hdif->hdatStructName));
        l_string[sizeof(i_hdif->hdatStructName)] = 0x00;

        HDAT_INF("  **hdatHDIF_t**");
        HDAT_INF("      hdatStructId = 0X %04X ", i_hdif->hdatStructId);
        HDAT_INF("      hdatStructName = %s", l_string);
        HDAT_INF("      hdatInstance = %hu", i_hdif->hdatInstance);
        HDAT_INF("      hdatVersion = %hu", i_hdif->hdatVersion);
        HDAT_INF("      hdatSize = %u", i_hdif->hdatSize);
        HDAT_INF("      hdatHdrSize = %u", i_hdif->hdatHdrSize);
        HDAT_INF("      hdatDataPtrOffset = %u", i_hdif->hdatDataPtrOffset);
        HDAT_INF("      hdatDataPtrCnt = %hu", i_hdif->hdatDataPtrCnt);
        HDAT_INF("      hdatChildStrCnt = %hu", i_hdif->hdatChildStrCnt);
        HDAT_INF("      hdatChildStrOffset = %u", i_hdif->hdatChildStrOffset);
    }

    if (NULL != i_data && NULL != i_hdif)
    {
        l_data = const_cast<hdatHDIFDataHdr_t *>(i_data);
        HDAT_INF("  **hdatHDIFDataHdr_t**");
        for (l_idx=0; l_idx<i_hdif->hdatDataPtrCnt; l_idx++)
        {
            HDAT_INF("      hdatOffset = %u", l_data->hdatOffset);
            HDAT_INF("      hdatSize = %u", l_data->hdatSize);
            l_data++;
        }
    }

    if (NULL != i_child && NULL != i_hdif)
    {
        l_child = const_cast<hdatHDIFChildHdr_t *>(i_child);
        HDAT_INF("  **hdatHDIFChildHdr_t**");
        for (l_idx=0; l_idx<i_hdif->hdatChildStrCnt; l_idx++)
        {
            HDAT_INF("      hdatOffset = %u", l_child->hdatOffset);
            HDAT_INF("      hdatSize = %u", l_child->hdatSize);
            HDAT_INF("      hdatCnt = %u", l_child->hdatCnt);
            l_child++;
        }
        HDAT_INF("");
    }

    if (NULL != i_dataArray)
    {
        HDAT_INF("  **hdatHDIFDataArray_t**");
        HDAT_INF("      hdatOffset = %u", i_dataArray->hdatOffset);
        HDAT_INF("      hdatArrayCnt = %u", i_dataArray->hdatArrayCnt);
        HDAT_INF("      hdatAllocSize = %u", i_dataArray->hdatAllocSize);
        HDAT_INF("      hdatActSize = %u", i_dataArray->hdatActSize);
    }

    return;
}

/*******************************************************************************
* hdatPrintKwd
*******************************************************************************/
void hdatPrintKwd(const char *i_kwd,
                     int32_t i_kwdLen)
{
    const uint32_t HDAT_HEX_SIZE = 16;  //16 hex characters per line
    uint32_t l_cnt, l_lines, l_rem ;
    char * l_kwd = const_cast<char *>(i_kwd);


    l_lines = i_kwdLen / HDAT_HEX_SIZE;
    l_rem = i_kwdLen % HDAT_HEX_SIZE;

    HDAT_INF("  **ASCII keyword VPD**");
    if (NULL == i_kwd)
    {
        HDAT_INF("      No keyword VPD");
    }
    else
    {
        for (l_cnt = 0; l_cnt < l_lines; l_cnt++)
        {
            HDAT_INF( "0X %08X %08X %08X %08X",
                    (*(reinterpret_cast<uint32_t *>(l_kwd    ))) ,
                    (*(reinterpret_cast<uint32_t *>(l_kwd +  4))),
                    (*(reinterpret_cast<uint32_t *>(l_kwd + 8))) ,
                    (*(reinterpret_cast<uint32_t *>(l_kwd + 12)))  );

            i_kwd += 16;
        } // end for loop


        if ( l_rem > 0 )
        {
          // More to print, but can't go past end of storage and
          // not easy to use TRACF statements for this
          if ( l_rem < 5 )
          {
              HDAT_INF( "0X %08X ",  (*(reinterpret_cast<uint32_t *>(l_kwd))) );
          }
          else if ( l_rem < 9 )
          {
              HDAT_INF( "0X %08X %08X ",
                   (*(reinterpret_cast<uint32_t *>(l_kwd    ))) ,
                   (*(reinterpret_cast<uint32_t *>(l_kwd +  4))) );
          }
          else if ( l_rem < 13 )
          {
              HDAT_INF( "0X %08X %08X %08X ",
                      (*(reinterpret_cast<uint32_t *>(l_kwd    ))) ,
                      (*(reinterpret_cast<uint32_t *>(l_kwd +  4))),
                      (*(reinterpret_cast<uint32_t *>(l_kwd + 8))) );
          }
          else
          { // remainder is up to 15 bytes
              HDAT_INF( "0X %08X %08X %08X %08X",
                    (*(reinterpret_cast<uint32_t *>(l_kwd    ))) ,
                    (*(reinterpret_cast<uint32_t *>(l_kwd +  4))),
                    (*(reinterpret_cast<uint32_t *>(l_kwd + 8))) ,
                    (*(reinterpret_cast<uint32_t *>(l_kwd + 12)))  );
          }

        } // end if remainder non-zero

    } // else we have keyword VPD

    return;
}

/******************************************************************************/
// hdatFetchRawSpdData
/******************************************************************************/
errlHndl_t hdatFetchRawSpdData(TARGETING::Target * i_target,
           size_t &o_kwdSize,char* &o_kwd)
{

    errlHndl_t l_err = NULL;
    uint64_t keyword = SPD::ENTIRE_SPD;

    do
    {
        assert(i_target != NULL);

        l_err = deviceRead( i_target,
                            NULL,
                            o_kwdSize,
                            DEVICE_SPD_ADDRESS(keyword) );
        if (l_err)
        {
            break;
        }

        o_kwd = new char[o_kwdSize];

        l_err = deviceRead( i_target,
                            o_kwd,
                            o_kwdSize,
                            DEVICE_SPD_ADDRESS(keyword) );

    }while(0);
    if ( l_err )
    {
        HDAT_DBG("hdatFetchRawSpdData : Failure on "
                " keyword: 0x%04x, of size: 0x%04x ",
                keyword,o_kwdSize);
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_UTIL_SPD_READ_FUNC
         * @reasoncode       HDAT::RC_SPD_READ_FAIL
         * @userdata1        spd keyword
         * @userdata2        raw spd keyword size returned
         * @userdata3        none
         * @userdata4        none
         * @devdesc          Failed to fetch the raw SPD data for the dimm
         * @custdesc         Firmware error while fetching Vital Product Data
         *                   for memory
         */
        hdatBldErrLog(l_err,
                    MOD_UTIL_SPD_READ_FUNC,
                    RC_SPD_READ_FAIL,
                    keyword,
                    o_kwdSize,
                    0,
                    0,
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE);

        if ( NULL != o_kwd)
        {
            delete[]  o_kwd;
            o_kwd = NULL;
        }
    }

    HDAT_DBG("hdatFetchRawSpdData: returning keyword size %d and data %s",
              o_kwdSize,o_kwd);
    return l_err;

}

/******************************************************************************/
// hdatCreateSzKeyWord
/******************************************************************************/
uint32_t  hdatCreateSzKeyWord(const char *i_jedec_vpd_ptr)
{
    uint32_t  l_sdram_cap = 1;
    uint32_t  l_pri_bus_wid = 1;
    uint32_t  l_sdram_wid  = 1;
    uint32_t  l_logical_ranks_per_dimm = 1;
    uint32_t  l_tmp = 0;

    uint8_t   l_primaryBusWidthByteInSPD = 0;
    uint8_t   l_sdramCapacityByteInSPD = 0;
    uint8_t   l_sdramDeviceWidthByteInSPD = 0;
    uint8_t   l_packageRanksPerDimmByteInSPD = 0;
    uint8_t   l_dieCount = 1;

    do
    {
        l_sdramCapacityByteInSPD = SVPD_JEDEC_BYTE_4;
        l_primaryBusWidthByteInSPD = SVPD_JEDEC_BYTE_13;
        l_sdramDeviceWidthByteInSPD = SVPD_JEDEC_BYTE_12;
        l_packageRanksPerDimmByteInSPD = SVPD_JEDEC_BYTE_12;

        /* Calculate SDRAM capacity */
        l_tmp = i_jedec_vpd_ptr[l_sdramCapacityByteInSPD] &
                SVPD_JEDEC_SDRAM_CAP_MASK;

        /* Make sure the bits are not Reserved */
        if(l_tmp > SVPD_JEDEC_SDRAMCAP_RESRVD)
        {
            l_tmp = l_sdramCapacityByteInSPD;
            break;
        }
        l_sdram_cap = (l_sdram_cap << l_tmp) *
                SVPD_JEDEC_SDRAMCAP_MULTIPLIER;

        /* Calculate Primary bus width */
        l_tmp = i_jedec_vpd_ptr[l_primaryBusWidthByteInSPD] &
                SVPD_JEDEC_PRI_BUS_WID_MASK;
        if(l_tmp > SVPD_JEDEC_RESERVED_BITS)
        {
            l_tmp = l_primaryBusWidthByteInSPD;
            break;
        }
        l_pri_bus_wid = (l_pri_bus_wid << l_tmp) *
                SVPD_JEDEC_PRI_BUS_WID_MULTIPLIER;

        /* Calculate SDRAM width */
        l_tmp = i_jedec_vpd_ptr[l_sdramDeviceWidthByteInSPD] &
                SVPD_JEDEC_SDRAM_WID_MASK;
        if(l_tmp > SVPD_JEDEC_RESERVED_BITS)
        {
            l_tmp = l_sdramDeviceWidthByteInSPD;
            break;
        }
        l_sdram_wid = (l_sdram_wid << l_tmp) *
                SVPD_JEDEC_SDRAM_WID_MULTIPLIER;

        /*
         * Number of ranks is calculated differently for "Single load stack"
         * (3DS) package and other packages.
         *
         * Logical Ranks per DIMM =
         *      for SDP, DDP, QDP: = SPD byte 12 bits 5~3
         *      for 3DS: = SPD byte 12 bits 5~3 times SPD byte 6 bits 6~4
         *
         * */

        l_tmp = i_jedec_vpd_ptr[SVPD_JEDEC_BYTE_6]
                                & SVPD_JEDEC_SIGNAL_LOADING_MASK;

        if(l_tmp == SVPD_JEDEC_SINGLE_LOAD_STACK)
        {
            //Fetch die count
            l_tmp = i_jedec_vpd_ptr[SVPD_JEDEC_BYTE_6]
                                    & SVPD_JEDEC_DIE_COUNT_MASK;

            l_tmp >>= SVPD_JEDEC_DIE_COUNT_RIGHT_SHIFT;
            l_dieCount = l_tmp + 1;
        }

        /* Calculate Number of ranks */
        l_tmp = i_jedec_vpd_ptr[l_packageRanksPerDimmByteInSPD] &
                SVPD_JEDEC_NUM_RANKS_MASK;

        l_tmp >>= SVPD_JEDEC_RESERVED_BITS;

        if(l_tmp > SVPD_JEDEC_RESERVED_BITS)
        {
            l_tmp = l_packageRanksPerDimmByteInSPD;
            break;
        }
        l_logical_ranks_per_dimm = (l_tmp + 1) * l_dieCount;

        l_tmp = (l_sdram_cap/SVPD_JEDEC_PRI_BUS_WID_MULTIPLIER) *
                (l_pri_bus_wid/l_sdram_wid) * l_logical_ranks_per_dimm;
    }while(0);

    return l_tmp;
}

/******************************************************************************/
// hdatConvertRawSpdToIpzFormat
/******************************************************************************/
errlHndl_t hdatConvertRawSpdToIpzFormat(
    const uint32_t    i_rid,
    const size_t      i_jedec_sz,
    char              *&i_jedec_ptr,
    size_t            &o_fmtkwdSize,
    char              *&o_fmtKwd)
{
    errlHndl_t l_err = nullptr;
    char	 l_dr_str[SVPD_JEDEC_DR_KW_SIZE+1] = "       MB MEMORY";
    char     l_sz_str[SVPD_JEDEC_SZ_KW_SIZE] = {'\0'};
    bool     l_invalid_dimm = false;
    bool     l_is_spd_template_present = true;
    uint32_t l_spd_template_read_size =0;
    uint32_t l_szValue = 0;

    do
    {
        // Below code probes for the DIMM module and DIMM type from the raw SPD
        // data. As of now the only supported format is DDR4 module with DDIMM.
        // So if its a DDR5 module (VPD format is unknown now) or any other
        // unknown types, we wont proceed further and return back.
        if(i_jedec_ptr[SVPD_SPD_BYTE_THREE] == SVPD_DDIMM_MODULE_TYPE)
        {
            // It's a DDIMM
            if ((i_jedec_ptr[SVPD_SPD_BYTE_TWO] == SVPD_DDR4_DEVICE_TYPE) &&
                (0 == strncmp((char*)&i_jedec_ptr[DDIMM_SPD_BYTE_416],
                              IBM_SPECIFIC_11S_FORMAT,SPD_SIZE_3_BYTES)))
            {
                // It's a DDR4 DDIMM
                HDAT_DBG("Detected DDR4 DDIMM");
            }
            else if ((i_jedec_ptr[SVPD_SPD_BYTE_TWO] ==
                      SVPD_DDR5_DEVICE_TYPE) &&
                     (0 == strncmp((char*)&i_jedec_ptr[DDIMM_SPD_BYTE_416],
                                IBM_SPECIFIC_11S_FORMAT,SPD_SIZE_3_BYTES)))
            {
                // It's a DDR5 DDIMM
                HDAT_DBG("Detected DDR5 DDIMM, VPD format is unknown");
                l_invalid_dimm = true;
            }
            else
            {
                HDAT_DBG("Detected an unknown DDIMM");
                HDAT_ERR("Invalid Byte 2 value(0x%2X), Unable to "
                         "determine DDR type for RID 0x%X.",
                         i_jedec_ptr[SVPD_SPD_BYTE_TWO],
                         i_rid);
                l_invalid_dimm = true;
            }
            if(l_invalid_dimm == true)
            {
                /*@
                 * @errortype
                 * @refcode    LIC_REFCODE
                 * @subsys     EPUB_FIRMWARE_SP
                 * @reasoncode RC_INVALID_DIMM_MODULE
                 * @moduleid   MOD_SPD_RAW_CONVERT_TO_IPZ_MODULE
                 * @userdata1  resource id of fru
                 * @userdata2  total raw spd keyword size
                 * @userdata3  dimm type
                 * @userdata4  none
                 * @devdesc    Unable to determine the DIMM module from raw
                 *             spd data
                 * @custdesc   Firmware error detected for a non supported DIMM
                 *             module while processing Vital Product Data
                 *             for memory
                 */
                hdatBldErrLog(l_err,
                      MOD_SPD_RAW_CONVERT_TO_IPZ_MODULE,   // SRC module ID
                      RC_INVALID_DIMM_MODULE,              // SRC ext ref code
                      i_rid,                               // SRC hex word 1
                      i_jedec_sz,                          // SRC hex word 2
                      i_jedec_ptr[SVPD_SPD_BYTE_THREE],    // SRC hex word 3
                      0,                                   // SRC hex word 4
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                return l_err;
            }
        }
        else
        {
            HDAT_ERR( "Invalid Byte 3 value(0x%2X), Unable to "
                      "determine DIMM type for RID 0x%X.",
                      i_jedec_ptr[SVPD_SPD_BYTE_THREE],
                      i_rid);
            /*@
             * @errortype
             * @refcode    LIC_REFCODE
             * @subsys     EPUB_FIRMWARE_SP
             * @reasoncode RC_INVALID_DIMM_TYPE
             * @moduleid   MOD_SPD_RAW_CONVERT_TO_IPZ_TYPE
             * @userdata1  resource id of fru
             * @userdata2  total raw spd keyword size
             * @userdata3  dimm type
             * @userdata4  none
             * @devdesc    Unable to determine the DIMM type from raw spd data
             * @custdesc   Firmware error detected for a non supported DIMM
             *             type while processing Vital Product Data for memory
             */
            hdatBldErrLog(l_err,
                      MOD_SPD_RAW_CONVERT_TO_IPZ_TYPE,     // SRC module ID
                      RC_INVALID_DIMM_TYPE,                // SRC ext ref code
                      i_rid,                               // SRC hex word 1
                      i_jedec_sz,                          // SRC hex word 2
                      i_jedec_ptr[SVPD_SPD_BYTE_THREE],    // SRC hex word 3
                      0,                                   // SRC hex word 4
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            return l_err;
        }
        HDAT_DBG("i_jedec_ptr[SVPD_SPD_BYTE_TWO]=0x%x",
            i_jedec_ptr[SVPD_SPD_BYTE_TWO]);
        HDAT_DBG("i_jedec_ptr[SVPD_SPD_BYTE_THREE]=0x%x",
            i_jedec_ptr[SVPD_SPD_BYTE_THREE]);

        /* Synthesize SZ */
        l_szValue = hdatCreateSzKeyWord(i_jedec_ptr);
        sprintf(l_sz_str, "%d", l_szValue);
        HDAT_DBG("l_sz_str = %s with size = %d",l_sz_str, sizeof(l_sz_str));

        /* Synthesize DR */
        memcpy(l_dr_str,l_sz_str,SVPD_JEDEC_SZ_KW_SIZE);
        HDAT_DBG("l_dr_str = %s with size = %d",l_dr_str, sizeof(l_dr_str));

        UtilFile l_dimmIpzFile ("spd_ipz_template.dat");
        if ( !l_dimmIpzFile.exists())
        {
            HDAT_ERR("The dimm vpd ipz file template is not found");
            l_is_spd_template_present = false;
        }
        else
        {
            l_err = l_dimmIpzFile.open("r");
            do{
            if (l_err)
            {
                HDAT_DBG("File open of spd_ipz_template.dat failed");
                break;
            }

            o_fmtkwdSize = l_dimmIpzFile.size();
            HDAT_DBG("o_fmtkwdSize size = %d",o_fmtkwdSize);
            if ( o_fmtkwdSize == 0 )
            {
                HDAT_DBG("No templated spd data present");
                l_err = l_dimmIpzFile.close();
                if (l_err)
                {
                    HDAT_DBG("File close of spd_ipz_template.dat failed");
                }
                break;
            }

            o_fmtKwd = new char [o_fmtkwdSize]();
            l_spd_template_read_size =
                 l_dimmIpzFile.read((void *)&o_fmtKwd[0],o_fmtkwdSize);
            if (l_spd_template_read_size == 0)
            {
                HDAT_DBG("File read of spd_ipz_template.dat failed");
                break;
            }
            l_err = l_dimmIpzFile.close();
            if (l_err)
            {
                HDAT_DBG("File close of spd_ipz_template.dat failed");
            }
            }while(0);
        }

        if (l_err || (l_is_spd_template_present == false) )
        {
            HDAT_ERR( "Error in processing spd_ipz_template.dat file for"
                      " RID 0x%X. Size tried to read = %d",
                      i_rid, o_fmtkwdSize);
            /*@
             * @errortype
             * @refcode    LIC_REFCODE
             * @subsys     EPUB_FIRMWARE_SP
             * @reasoncode RC_SPD_IPZ_TEMPLATE_PROCESS_FAIL
             * @moduleid   MOD_SPD_TO_IPZ_CONVERT_TEMPLATE
             * @userdata1  resource id of fru
             * @userdata2  total raw spd keyword size
             * @userdata3  spd template size from file.read()
             * @userdata4  spd ipz template data from file.size()
             * @devdesc    Unable to process the spd ipz template file
             * @custdesc   Firmware error detected while converting the Vital
             *             Product Data for memory to IPZ format
             */
            hdatBldErrLog(l_err,
                      MOD_SPD_TO_IPZ_CONVERT_TEMPLATE,     // SRC module ID
                      RC_SPD_IPZ_TEMPLATE_PROCESS_FAIL,    // SRC ext ref code
                      i_rid,                               // SRC hex word 1
                      i_jedec_sz,                          // SRC hex word 2
                      l_spd_template_read_size,            // SRC hex word 3
                      o_fmtkwdSize,                        // SRC hex word 4
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            return l_err;
        }
        /****************** Synthesize VINI Block ******************/

        // Copy CC keyword
        memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_CC_KW_OFFSET]),
            &i_jedec_ptr[DDIMM_SPD_BYTE_438], SVPD_JEDEC_CC_KW_SIZE);

        // Copy FN keyword
        memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_FN_KW_OFFSET]),
            &i_jedec_ptr[DDIMM_SPD_BYTE_419], SVPD_FN_KW_SIZE);

        // Copy PN keyword (PN and FN values are same)
        memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_PN_KW_OFFSET]),
            &i_jedec_ptr[DDIMM_SPD_BYTE_419], SVPD_PN_KW_SIZE);

        // Copy SN keyword
        memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_SN_KW_OFFSET]),
            &i_jedec_ptr[DDIMM_SPD_BYTE_426], SVPD_SN_KW_SIZE);

        // Copy SZ keyword
        memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_SZ_KW_OFFSET]),l_sz_str,
            SVPD_JEDEC_SZ_KW_SIZE);

        // Copy DR keyword
        memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_DR_KW_OFFSET]),l_dr_str,
            SVPD_JEDEC_DR_KW_SIZE);

        /****************** Synthesize VSPD Block ******************/

    	/* Synthesize #I KW of VSPD Block       */
        /* (Copy maximum 4096 bytes of VPD for DDIMM)   */
        memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_I_BLK_OFFSET]),
            &i_jedec_ptr[0], i_jedec_sz);

        /* Synthesize #A KW of VSPD Block */
    	/* (copy 640 - 1023 bytes of VPD for DDIMM) */
        memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_A_BLK_OFFSET]),
            &i_jedec_ptr[DDIMM_SPD_EMP_OFFSET],DDIMM_SPD_EMP_SZ);

        /* Synthesize #B KW of VSPD Block */
        /* (copy 3072 - 4095 bytes of VPD for DDIMM) */
        /* Data copy is only carried out if we get the fully supported*/
        /* size of 4096 bytes, other wise value remains zero */
        if (i_jedec_sz == DDIMM_SPD_SZ)
        {
            memcpy(reinterpret_cast<void *>(&o_fmtKwd[SVPD_B_BLK_OFFSET]),
                &i_jedec_ptr[DDIMM_SPD_EUP_OFFSET], DDIMM_SPD_EUP_SZ);
        }

	    /********************  Done with Conversion ***********************/
    }while(false);
    return l_err;
}

void hdatGetTarget (const hdatSpiraDataAreas i_dataArea,
                        TARGETING::TargetHandleList &o_targList)
{
    HDAT_ENTER();
    TARGETING::TYPE l_type;
    TARGETING::CLASS l_class;

    switch (i_dataArea)
    {
        case HDAT_BACKPLANE_VPD:
            l_type = TARGETING::TYPE_NODE;
            l_class = TARGETING::CLASS_ENC;
        break;

        case HDAT_CLOCK_VPD:
            l_type = TARGETING::TYPE_NA;
            l_class = TARGETING::CLASS_NA;
        break;

        case HDAT_SYS_VPD:
            l_type = TARGETING::TYPE_SYS;
            l_class = TARGETING::CLASS_SYS;
        break;

        case HDAT_ENCLOSURE_VPD:
            l_type = TARGETING::TYPE_NA;
            l_class = TARGETING::CLASS_NA;
        break;

        case HDAT_ANCHOR_VPD:
            l_type = TARGETING::TYPE_NA;
            l_class = TARGETING::CLASS_NA;
        break;

        case HDAT_MISC_CEC_VPD:
            l_type = TARGETING::TYPE_NA;
            l_class = TARGETING::CLASS_NA;
        break;
        default:
            l_type = TARGETING::TYPE_NA;
            l_class = TARGETING::CLASS_NA;
        break;
    }

    if ( (l_type != TARGETING::TYPE_NA) &&
         (l_class != TARGETING::CLASS_NA))
    {
        TARGETING::Target* l_sys = NULL;
        TARGETING::targetService().getTopLevelTarget(l_sys);
        assert(l_sys != NULL);

        if( (l_type == TARGETING::TYPE_SYS ) &&
            (l_class == TARGETING::CLASS_SYS))
        {
            o_targList.push_back(l_sys);
            HDAT_DBG("fetched SYS target");
        }
        else
        {
            PredicateCTM predNode(l_class, l_type);
            PredicateHwas predFunctional;
            predFunctional.functional(true);
            PredicatePostfixExpr nodeCheckExpr;
            nodeCheckExpr.push(&predNode).push(&predFunctional).And();

            targetService().getAssociated(o_targList, l_sys,
                TargetService::CHILD, TargetService::IMMEDIATE,
                &nodeCheckExpr);
        }

    }

    HDAT_EXIT();
}

errlHndl_t hdatformatAsciiKwd(const struct vpdData i_fetchVpd[],
        const size_t &i_num, const size_t theSize[], char* &i_kwd,
        const uint32_t &i_kwdSize, char* &o_fmtKwd, uint32_t &o_fmtkwdSize,
        const HdatKeywordInfo i_Keywords[])
{
    HDAT_ENTER();
    HDAT_DBG("entered hdatformatAsciiKwd with theSize=0x%x",theSize);

    // i_kwdSize - data size
    // (i_num* sizeof(uint8_t)) - individual datat size
    // (2 * sizeof(uint8_t)) - 0x78, 0x84
    // sizeof(uint16_t) = total data size in size
    // (i_num* 2) - keyword size
    o_fmtkwdSize = i_kwdSize + (i_num* sizeof(uint8_t)) +
                    (2 * sizeof(uint8_t)) + sizeof(uint16_t) + (i_num* 2);

    o_fmtKwd = new char[o_fmtkwdSize];
    //Tag for start of the section
    uint8_t l_initial = 0x84;
    uint16_t l_kwdSize = o_fmtkwdSize - sizeof(uint16_t) - (2*sizeof(uint8_t));

    //Need to convert the size into little endian as per format
    l_kwdSize= UINT16_IN_LITTLE_ENDIAN(l_kwdSize);
    memcpy(reinterpret_cast<void *>(o_fmtKwd ),&l_initial,sizeof(l_initial));
    memcpy(reinterpret_cast<void *>(o_fmtKwd + 1),&l_kwdSize,sizeof(l_kwdSize));

    uint32_t l_loc = sizeof(uint16_t) + sizeof(uint8_t);
    char *ptr = i_kwd;

    for( uint32_t curCmd = 0; curCmd < i_num; curCmd++ )
    {
        if( theSize[curCmd] != 0)
        {
            memcpy(reinterpret_cast<void *>(o_fmtKwd + l_loc),
                 &i_Keywords[curCmd].keywordName, 2);
            l_loc += 2;

            uint8_t l_var = theSize[curCmd];
            memcpy(reinterpret_cast<void *>(o_fmtKwd + l_loc),&l_var,
                   sizeof(uint8_t));

            l_loc += sizeof(uint8_t);

            memcpy(reinterpret_cast<void *>(o_fmtKwd + l_loc),ptr,
                   theSize[curCmd]);

            l_loc += theSize[curCmd];

            ptr += theSize[curCmd];
        }
   }
    //End start tag of the section
   uint8_t l_end= 0x78;
   memcpy(reinterpret_cast<void *>(o_fmtKwd +l_loc),&l_end,sizeof(uint8_t));
   l_loc +=sizeof(uint8_t);

   HDAT_EXIT();
   return NULL;
}


errlHndl_t hdatGetFullEepromVpd(TARGETING::Target * i_target,
                                size_t &io_dataSize,
                                char* &o_data)
{
    errlHndl_t err = NULL;

    HDAT_ENTER();
    if(i_target != NULL)
    {
        o_data = new char[io_dataSize];

        //Collecting Full module VPD data
        err = deviceOp( DeviceFW::READ,
                        i_target,
                        o_data,
                        io_dataSize,
                        DEVICE_EEPROM_ADDRESS(EEPROM::VPD_AUTO,
                                              0,
                                              EEPROM::AUTOSELECT));
        if(err)
        {
            HDAT_ERR("Reading Full vpd from Eeprom failed");
            /*@
            * @errortype
            * @moduleid         HDAT::MOD_UTIL_FULL_MVPD_READ_FUNC
            * @reasoncode       HDAT::RC_DEV_READ_VPD_FAIL
            * @devdesc          Device read failed
            * @custdesc         Firmware encountered an internal error
            */
            hdatBldErrLog(err,
                          MOD_UTIL_FULL_MVPD_READ_FUNC,
                          RC_DEV_READ_VPD_FAIL,
                          0,0,0,0,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL,
                          HDAT_VERSION1,
                          true);
            if(o_data != NULL)  // No point in keeping this data with err
            {
                delete[] o_data;
                o_data = NULL;
            }
        }
    }
    else
    {
        HDAT_ERR("Input Target is Null");
    }
    HDAT_EXIT();
    return(err);
}

//******************************************************************************
// byNodeProcAffinty (std::sort comparison function)
//******************************************************************************

bool byNodeProcAffinity(
    const DeviceInfo_t& i_lhs,
    const DeviceInfo_t& i_rhs)
{
    bool lhsLogicallyBeforeRhs = (i_lhs.assocNode < i_rhs.assocNode);
    if(i_lhs.assocNode == i_rhs.assocNode)
    {
        lhsLogicallyBeforeRhs = (i_lhs.assocProc < i_rhs.assocProc);
        if(i_lhs.assocProc == i_rhs.assocProc)
        {
            lhsLogicallyBeforeRhs = (i_lhs.masterChip < i_rhs.masterChip);
        }
    }
    return lhsLogicallyBeforeRhs;
}

/*******************************************************************************
 * hdatGetI2cDeviceInfo
 *
 * @brief Routine returns the Host I2C device entries
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_pTarget
 *       The i2c master target handle, or nullptr for all i2c masters
 * @param[in] i_model Target model
 * @param[out] o_i2cDevEntries
 *       The host i2c dev entries
 *
 * @return void
 *
*******************************************************************************/
void hdatGetI2cDeviceInfo(
    TARGETING::Target*          i_pTarget,
    TARGETING::ATTR_MODEL_type  i_model,
    std::vector<hdatI2cData_t>& o_i2cDevEntries)
{
    HDAT_ENTER();

    // This vector is expensive to construct, so initialize it once and then
    // cache it for future uses.
    static const std::vector<DeviceInfo_t> deviceInfo =
        ([] {
            std::vector<DeviceInfo_t> devinfo;
            getDeviceInfo(nullptr, devinfo);

            // Order by node ordinal ID, processor position, I2C master target
            // pointer
            std::sort(devinfo.begin(), devinfo.end(),
                      byNodeProcAffinity);

            return devinfo;
        })();

    if(deviceInfo.empty())
    {
        HDAT_INF("No I2C connections found for I2C master with HUID of 0x%08X",
                 TARGETING::get_huid(i_pTarget));
    }
    else // At least one device, and index [0] is valid
    {
        union LinkId
        {
            struct
            {
                uint8_t  node;     ///< Ordinal ID of node
                uint8_t  proc;     ///< Processor position
                uint16_t instance; ///< Link instance (unique across a given
                                   ///<     processor and its downstream
                                   ///<     membufs)
            };
            uint32_t val;          ///< Allow access to the raw value
        } linkId = { {
            .node=static_cast<uint8_t>(deviceInfo[0].assocNode),
            .proc=static_cast<uint8_t>(deviceInfo[0].assocProc),
            .instance=0 }
        };

        for (const auto& i2cDevice : deviceInfo)
        {

            if(   (i2cDevice.assocNode != linkId.node)
               || (i2cDevice.assocProc != linkId.proc))
            {
                linkId.node=i2cDevice.assocNode;
                linkId.proc=i2cDevice.assocProc;
                linkId.instance=0;
            }

            hdatI2cData_t l_hostI2cObj;
            memset(&l_hostI2cObj, 0x00, sizeof(hdatI2cData_t));

            l_hostI2cObj.hdatI2cEngine       = i2cDevice.engine;
            l_hostI2cObj.hdatI2cMasterPort   = i2cDevice.masterPort;
            l_hostI2cObj.hdatI2cBusSpeed     = i2cDevice.busFreqKhz;
            l_hostI2cObj.hdatI2cSlaveDevType = i2cDevice.deviceType;
            l_hostI2cObj.hdatI2cSlaveDevAddr = i2cDevice.addr;
            l_hostI2cObj.hdatI2cSlavePort    = i2cDevice.slavePort;
            l_hostI2cObj.hdatI2cSlaveDevPurp = i2cDevice.devicePurpose;
            l_hostI2cObj.hdatI2cLinkId       = linkId.val;
            strncpy(l_hostI2cObj.hdatI2cLabel,
                    i2cDevice.deviceLabel,
                    sizeof(l_hostI2cObj.hdatI2cLabel)-1);
            // SLCA Index will be filled in by HDAT code

            // Don't include the device if the slave address is
            // invalid
            if(l_hostI2cObj.hdatI2cSlaveDevAddr == UINT8_MAX)
            {
                continue;
            }

            assert(linkId.instance <= UINT16_MAX,"Illegal link ID instance "
                "detected");
            ++linkId.instance;

            if( (i_pTarget == nullptr) ||
                (i_pTarget == i2cDevice.masterChip)
              )
            {
                o_i2cDevEntries.push_back(l_hostI2cObj);
            }
        }
    }

    for(auto const& i2cDevice : o_i2cDevEntries)
    {

        HDAT_DBG("Unique I2C device attached to HUID=0x%08X: "
                 "engine=0x%02X, "
                 "port=0x%02X, "
                 "speed=0x%04X, "
                 "slave type=0x%02X, "
                 "slave address=0x%02X, ",
                 TARGETING::get_huid(i_pTarget),
                 i2cDevice.hdatI2cEngine,
                 i2cDevice.hdatI2cMasterPort,
                 i2cDevice.hdatI2cBusSpeed,
                 i2cDevice.hdatI2cSlaveDevType,
                 i2cDevice.hdatI2cSlaveDevAddr);

        HDAT_DBG("slave port=0x%02X, "
                 "slave purpose=0x%08X, "
                 "link ID=0x%08X, "
                 "SLCA index=0x%04X, "
                 "slave label=\"%s\"",
                 i2cDevice.hdatI2cSlavePort,
                 i2cDevice.hdatI2cSlaveDevPurp,
                 i2cDevice.hdatI2cLinkId,
                 i2cDevice.hdatI2cSlcaIndex,
                 i2cDevice.hdatI2cLabel);
    }

    HDAT_EXIT();
}


/*******************************************************************************
 * hdatGetSMPLinkInfo
 *
 * @brief Routine returns the Host SMP Link info entries
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_pTarget
 *       The SMP link master target handle
 * @param[out] o_SMPLinkEntries
 *       The host SMP Link info entries
 *
 * @return void
 *
*******************************************************************************/


void hdatGetSMPLinkInfo(TARGETING::Target* i_pTarget,
    std::vector<hdatSMPLinkInfo_t>&o_SMPLinkEntries)
{
    HDAT_ENTER();

    //@TODO RTC 246357 missing attribute
    //@TODO RTC 246438 VNDR NV is not defined: in the bp vpd yet
 /*   errlHndl_t l_err = NULL;
    uint8_t *l_NVKwd = NULL;
    PVPD::pvpdRecord l_Record = PVPD::VNDR;
    PVPD::pvpdKeyword l_KeyWord = PVPD::NV;
    size_t l_nvKwdSize = 0;

    TARGETING::TargetHandleList l_targList;
    PredicateCTM predNode(TARGETING::CLASS_ENC, TARGETING::TYPE_NODE);
    PredicateHwas predFunctional;
    predFunctional.functional(true);
    PredicatePostfixExpr nodeCheckExpr;
    nodeCheckExpr.push(&predNode).push(&predFunctional).And();

    targetService().getAssociated(l_targList, i_pTarget,
                TargetService::PARENT, TargetService::IMMEDIATE,
                &nodeCheckExpr);
    TARGETING::Target* l_target = l_targList[0];

    l_err = deviceRead(l_target,NULL,l_nvKwdSize,
                            DEVICE_PVPD_ADDRESS(l_Record,l_KeyWord));
    if(l_err == NULL)
    {
        if(l_nvKwdSize == sizeof(hdatNVKwdStruct_t))
        {
            uint8_t l_kwd[l_nvKwdSize] = {0};
            l_err = deviceRead(l_target,l_kwd,l_nvKwdSize,
                            DEVICE_PVPD_ADDRESS(l_Record,l_KeyWord));

            if(l_err == NULL)
            {
                l_NVKwd = new uint8_t[sizeof(hdatNVKwdStruct_t)];
                memcpy(l_NVKwd, l_kwd, sizeof(hdatNVKwdStruct_t));
            }
            else
            {
                HDAT_ERR(" Device Read for NV keyword errored out ");
                ERRORLOG::errlCommit(l_err,HDAT_COMP_ID);
            }
        }
        else
        {
            HDAT_ERR("Returned length for NV keyword is 0x%x which is not 0x%x",
                            l_nvKwdSize,sizeof(hdatNVKwdStruct_t));
        }
    }
    else
    {
        HDAT_ERR("deviceRead failed for NV keyword VNDR record");
    }

    const hdatSMPLinkInfo_t *l_smpLinkInfoPtr = NULL;
    uint32_t           l_smpLinkInfoSize = 0;

    if(l_NVKwd != NULL)
    {
        if((reinterpret_cast<hdatNVKwdStruct_t *>(l_NVKwd)->magic == HDAT_NV_KWD_MAGIC_WRD)
                        &&(reinterpret_cast<hdatNVKwdStruct_t *>(l_NVKwd)->version == 0x01))
        {
            if(reinterpret_cast<hdatNVKwdStruct_t *>(l_NVKwd)->config == HDAT_REDBUD_NV_CNFG)
            {
                if(i_pTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>() == 0)
                {
                    l_smpLinkInfoPtr = l_hdatSMPLinkInfoProc0_4gpucfg;
                    l_smpLinkInfoSize = sizeof(l_hdatSMPLinkInfoProc0_4gpucfg)/sizeof(hdatSMPLinkInfo_t);
                }
                else
                {
                    l_smpLinkInfoPtr = l_hdatSMPLinkInfoProc1_4gpucfg;
                    l_smpLinkInfoSize = sizeof(l_hdatSMPLinkInfoProc1_4gpucfg)/sizeof(hdatSMPLinkInfo_t);
                }
            }
            else if(reinterpret_cast<hdatNVKwdStruct_t *>(l_NVKwd)->config == HDAT_SEQUOIA_NV_CNFG)
            {
                if(i_pTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>() == 0)
                {
                    l_smpLinkInfoPtr = l_hdatSMPLinkInfoProc0_6gpucfg;
                    l_smpLinkInfoSize = sizeof(l_hdatSMPLinkInfoProc0_6gpucfg)/sizeof(hdatSMPLinkInfo_t);
                }
                else
                {
                    l_smpLinkInfoPtr = l_hdatSMPLinkInfoProc1_6gpucfg;
                    l_smpLinkInfoSize = sizeof(l_hdatSMPLinkInfoProc1_6gpucfg)/sizeof(hdatSMPLinkInfo_t);
                }
            }
        }
        else
        {
            HDAT_ERR(" Unknown config : NV KWD Magic = 0X%8X, Version = 0x%x");
        }
    }

    for( uint32_t l_count = 0; l_count < l_smpLinkInfoSize ; l_count++)
    {
        hdatSMPLinkInfo_t l_hdatSMPLinkInfo;
        memcpy(&l_hdatSMPLinkInfo, &l_smpLinkInfoPtr[l_count], sizeof(hdatSMPLinkInfo_t));
        o_SMPLinkEntries.push_back(l_hdatSMPLinkInfo);
    }
    if(l_NVKwd != NULL)
    {
        delete l_NVKwd;
        l_NVKwd = NULL;
    }
    if(l_err != NULL)
    {
        delete l_err;
        l_err = NULL;
    }

*/
    HDAT_EXIT();
}

errlHndl_t hdatUpdateSMPLinkInfoData(hdatHDIFDataArray_t * i_SMPInfoFullPcrdHdrPtr ,
                                        hdatSMPLinkInfo_t * io_SMPInfoFullPcrdDataPtr,
                                        TARGETING::Target* i_pProcTarget)
{
    errlHndl_t l_errl = NULL;
    HDAT_ENTER();
    std::vector<hdatSMPLinkInfo_t> l_SMPLinkInfoCntr(io_SMPInfoFullPcrdDataPtr,
                           io_SMPInfoFullPcrdDataPtr + i_SMPInfoFullPcrdHdrPtr->hdatArrayCnt);
    do{
        for(auto & l_SMPInfoEle : l_SMPLinkInfoCntr)
        {
            uint8_t l_obusChipletPos =
                    (uint8_t) l_SMPInfoEle.hdatSMPLinkBrickID / NUM_BRICKS_PER_OBUS;
            uint8_t l_obusPllFreqBucket = 0;
            switch( l_obusChipletPos){
                case 0:
                case 1:
                case 2:
                case 3:
                {
                    l_errl = Util::getObusPllBucket(i_pProcTarget,
                                                    l_obusPllFreqBucket,
                                                    l_obusChipletPos);
                     break;
                }
                default :{
                    HDAT_ERR(" Invalid obus Brick ID ");

                    /*@
                    * @errortype
                    * @moduleid         HDAT::MOD_UTIL_SMP_LINK_INFO
                    * @reasoncode       HDAT::RC_INVALID_OBUS_BRICKID
                    * @devdesc          Invalid OBUS brick ID
                    * @custdesc         Firmware encountered an internal
                    *                   error while getting  obus brick ID
                    */
                    hdatBldErrLog(l_errl,
                             MOD_UTIL_SMP_LINK_INFO,
                            RC_INVALID_OBUS_BRICKID,
                            0,0,0,0);
                    break;
                }
            }
            if(l_errl != NULL)
            {
                HDAT_ERR(" Error in getting the PLL Freq bucket");
                break;
            }


//TODO RTC:216061 Re-enable when attr exists            if(l_obusPllFreqBucket > OBUS_PLL_FREQ_BUCKETS)
            if(l_obusPllFreqBucket > 24)
            {
                    HDAT_ERR(" Invalid obus Freq bucket ");

                    /*@
                    * @errortype
                    * @moduleid         HDAT::MOD_UTIL_SMP_LINK_INFO
                    * @reasoncode       HDAT::RC_INVALID_OBUS_FREQ_BUCKET
                    * @devdesc          Invalid OBUS Freq Bucket
                    * @custdesc         Firmware encountered an internal
                    *                   error while getting  obus frequency bucket
                    */
                    hdatBldErrLog(l_errl,
                             MOD_UTIL_SMP_LINK_INFO,
                            RC_INVALID_OBUS_FREQ_BUCKET,
                            0,0,0,0);
                    break;
            }

/*TODO RTC:216061 Re-enable when attr exists
            uint32_t *l_freqList = NULL;
            TARGETING::ATTR_MODEL_type l_chipModel = i_pProcTarget->getAttr<TARGETING::ATTR_MODEL>();
            uint32_t l_chipECLevel = i_pProcTarget->getAttr<TARGETING::ATTR_HDAT_EC>();
            if(l_chipModel == TARGETING::MODEL_NIMBUS)
            {
                switch (l_chipECLevel){
                    case 0x10:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9N_10); break; }
                    case 0x20:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9N_20); break; }
                    case 0x21:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9N_21); break; }
                    case 0x22:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9N_22); break; }
                    case 0x23:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9N_23); break; }
                }
            }
            else if(l_chipModel == TARGETING::MODEL_CUMULUS)
            {
                switch (l_chipECLevel){
                    case 0x10:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9C_10); break; }
                    case 0x11:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9C_11); break; }
                    case 0x12:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9C_12); break; }
                    case 0x13:{l_freqList = const_cast<uint32_t *>(OBUS_PLL_FREQ_LIST_P9C_13); break; }
                }
            }

            if(l_freqList == NULL)
            {
                HDAT_ERR("Invalid proc model and ec 0x%x, 0x%x", l_chipModel , l_chipECLevel);
                    * @errortype
                    * @moduleid         HDAT::MOD_UTIL_SMP_LINK_INFO
                    * @reasoncode       HDAT::RC_UNDEFINED_PROC_MODEL_EC
                    * @devdesc          Undefined Proc model and ec
                    * @custdesc         Firmware encountered an internal
                    *                   error while finding proc model and ec
                             MOD_UTIL_SMP_LINK_INFO,
                            RC_UNDEFINED_PROC_MODEL_EC,
                            0,0,0,0);
                    break;
            }

            //PLL bucket is 1 based (1,2,3), subtract 1 for 0 based array
            uint32_t l_pllfreq = *(l_freqList+l_obusPllFreqBucket -1);

            switch( l_pllfreq ){
                case 1250:{l_SMPInfoEle.hdatSMPLinkSpeed = HDAT_OBUS_FREQ_20GBPS; break; };
                case 1563:{l_SMPInfoEle.hdatSMPLinkSpeed = HDAT_OBUS_FREQ_25GBPS; break; };
                case 1611:{l_SMPInfoEle.hdatSMPLinkSpeed = HDAT_OBUS_FREQ_25_78125GBPS; break; };
                default:{
                        HDAT_ERR("Invalid obus pll freq value for obus chiplet %d,"
                                "of proc with HUID 0x%8X: 0x%d", l_obusChipletPos,
                                i_pProcTarget->getAttr<ATTR_HUID>(), l_pllfreq);
                        * @errortype
                        * @moduleid         HDAT::MOD_UTIL_SMP_LINK_INFO
                        * @reasoncode       HDAT::RC_INVALID_OBUS_PLL_FREQ
                        * @devdesc          Invalid OBUS PLL frequency value
                        * @custdesc         Firmware encountered an internal
                        *                   error while retrieving obus pll frequency values
                                MOD_UTIL_SMP_LINK_INFO,
                                RC_INVALID_OBUS_PLL_FREQ,
                                0,0,0,0);
                        break;
                  }
            }
            **/
            l_SMPInfoEle.hdatSMPLinkSpeed = HDAT_OBUS_FREQ_25GBPS;
            if(l_errl != NULL){break;};
        }
    }while(0);
    //Replace the updated data in the passed in pointer.
    std::copy(l_SMPLinkInfoCntr.begin(), l_SMPLinkInfoCntr.end(),io_SMPInfoFullPcrdDataPtr);
    HDAT_EXIT();
    return l_errl;

}

uint32_t getMemBusFreq(const TARGETING::Target* i_pTarget)
{

    HDAT_ENTER();
    /*TODO RTC:216061 Re-enable when attr exists
    TARGETING::ATTR_MSS_FREQ_type l_MemBusFreqInMHz = 0;

    TARGETING::ATTR_CLASS_type l_class = GETCLASS(i_pTarget);
    TARGETING::ATTR_TYPE_type l_type = GETTYPE(i_pTarget);
    if((l_class == TARGETING::CLASS_CHIP) && (l_type == TARGETING::TYPE_PROC))
    {
        TARGETING::PredicateCTM l_mcbistPredicate(TARGETING::CLASS_UNIT,
                                                TARGETING::TYPE_MCBIST);
        TARGETING::PredicateHwas l_predHwasFunc;
        TARGETING::PredicatePostfixExpr l_presentMcbist;
        l_presentMcbist.push(&l_mcbistPredicate).
                            push(&l_predHwasFunc).And();
        TARGETING::TargetHandleList l_mcbistList;

        // Find Associated MCBIST list
        TARGETING::targetService().getAssociated(l_mcbistList,
                                            i_pTarget,
                                            TARGETING::TargetService::CHILD_BY_AFFINITY,
                                            TARGETING::TargetService::ALL,
                                            &l_presentMcbist);
        if(l_mcbistList.size() == 0)
        {
            HDAT_ERR("Didn't find any mcbist for a proc with huid [0x%08X]",
                        i_pTarget->getAttr<TARGETING::ATTR_HUID>());
        }
        else
        {
            TARGETING::Target *l_pMcbistTarget = l_mcbistList[0];
            if( l_pMcbistTarget->tryGetAttr<TARGETING::ATTR_MSS_FREQ>
             (l_MemBusFreqInMHz) == false )
            {
                HDAT_ERR(" MSS_FREQ not present for MCBIST with huid [0x%08X]",
                        l_pMcbistTarget->getAttr<TARGETING::ATTR_HUID>());
            }
        }
     }
    else if((l_class == TARGETING::CLASS_UNIT) && (l_type == TARGETING::TYPE_MCBIST))
    {
        if(i_pTarget->tryGetAttr<TARGETING::ATTR_MSS_FREQ>
             (l_MemBusFreqInMHz) == false )
            {
                HDAT_ERR(" MSS_FREQ not present for MCBIST with huid [0x%08X]",
                        i_pTarget->getAttr<TARGETING::ATTR_HUID>());
            }
    }
    else
    {

        HDAT_ERR(" Input target with HUID [0x%08X] is not of proc/mcbist target type",
                        i_pTarget->getAttr<TARGETING::ATTR_HUID>());
    }

    HDAT_EXIT();
    return l_MemBusFreqInMHz;
    **/
    HDAT_EXIT();
    return 24;
}

uint32_t getMemBusFreqP10(const TARGETING::Target* i_pTarget)
{
    HDAT_ENTER();
    TARGETING::ATTR_MEM_EFF_FREQ_type l_MemBusFreqInMHz = {0};
    if( i_pTarget->tryGetAttr<TARGETING::ATTR_MEM_EFF_FREQ>
          (l_MemBusFreqInMHz) == false )
    {
        HDAT_ERR("MSS_EFF_FREQ not present for MEM PORT with "
                 "huid [0x%08X]",
                 i_pTarget->getAttr<TARGETING::ATTR_HUID>());
    }
    HDAT_EXIT();
    return l_MemBusFreqInMHz;
}

/*******************************************************************************
 * hdatGetMemTargetMmioInfo
 *
 * @brief Routine returns the MMIO entries
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_pTarget
 *       The MMIO target handle
 * @param[out] o_mmioEntries
 *       The MMIO entries
 *
 * @return void
 *
*******************************************************************************/
void hdatGetMemTargetMmioInfo(TARGETING::Target* i_pTarget,
     std::vector<hdatMsAreaMmioAddrRange_t>&o_mmioEntries)
{
    HDAT_ENTER();

    std::vector<ocmbMmioAddressRange_t> mmioInfo;
    getMemTargetMmioInfo(i_pTarget, mmioInfo);

    if(mmioInfo.empty())
    {
        HDAT_INF("No MMIO entries found with HUID of 0x%08X",
                 TARGETING::get_huid(i_pTarget));
    }
    else // At least one entrey found
    {
        for (const auto& mmioDev : mmioInfo)
        {
            hdatMsAreaMmioAddrRange_t l_mmioObj;
            memset(&l_mmioObj, 0x00, sizeof(hdatMsAreaMmioAddrRange_t));

            l_mmioObj.hdatMmioAddrRngStrAddr.hi =
                (mmioDev.mmioBaseAddr & 0xFFFFFFFF00000000ull) >> 32;
            l_mmioObj.hdatMmioAddrRngStrAddr.lo =
                mmioDev.mmioBaseAddr & 0x00000000FFFFFFFFull;
            l_mmioObj.hdatMmioAddrRngStrAddr.hi |= HDAT_REAL_ADDRESS_MASK;

            l_mmioObj.hdatMmioAddrRngEndAddr.hi =
                (mmioDev.mmioEndAddr & 0xFFFFFFFF00000000ull) >> 32;
            l_mmioObj.hdatMmioAddrRngEndAddr.lo =
                mmioDev.mmioEndAddr & 0x00000000FFFFFFFFull;
            l_mmioObj.hdatMmioAddrRngEndAddr.hi |= HDAT_REAL_ADDRESS_MASK;

            l_mmioObj.hdatMmioHbrtChipId = mmioDev.hbrtId;

            if (mmioDev.accessSize == 8)
            {
                l_mmioObj.hdatMmioFlags = HDAT_8BYTE_ACCESS_SUPPORT;
            }
            else if (mmioDev.accessSize == 4)
            {
                l_mmioObj.hdatMmioFlags = HDAT_4BYTE_ACCESS_SUPPORT;
            }
            o_mmioEntries.push_back(l_mmioObj);
        }
    }

    for (const auto& mmioDev : mmioInfo)
    {
        HDAT_DBG("MMIO device attached to HUID=0x%08X: "
            "hbrt Id=0x%02X, ",
            "mmio flags=0x%02X, ",
            TARGETING::get_huid(i_pTarget),
            mmioDev.hbrtId,
            mmioDev.accessSize);
    }

    HDAT_EXIT();
}

/******************************************************************************/
// hdatGetHostSpiDevInfo
/******************************************************************************/
void hdatGetHostSpiDevInfo(std::vector<hdatSpiDevData_t>&o_spiDevEntries,
     std::vector<hdatEepromPartData_t>&o_eepromPartEntries,
     TARGETING::Target* i_pProcTarget)
{
    HDAT_ENTER();

    std::vector<spiSlaveDevice> spiInfo;
    getSpiDeviceInfo(spiInfo, i_pProcTarget);
    char *l_hwSubsystemOrScope = NULL;

    if(spiInfo.empty())
    {
        HDAT_INF("No SPI entries found");
    }
    else // At least one entry found
    {
        for (const auto& spiDev : spiInfo)
        {
            hdatSpiDevData_t l_spiObj;
            memset(&l_spiObj, 0x00, sizeof(hdatSpiDevData_t));

            l_spiObj.hdatSpiDevId = spiDev.deviceId.word;
            l_spiObj.hdatSpiMasterEngine = spiDev.masterEngine;
            l_spiObj.hdatSpiMasterPort = spiDev.masterPort;
            l_spiObj.hdatSpiBusSpeed = spiDev.busSpeedKhz;
            l_spiObj.hdatSpiSlaveDevType =
                static_cast<uint8_t>(spiDev.deviceType);
            l_spiObj.hdatSpiDevPurp =
                static_cast<uint8_t>(spiDev.devicePurpose);
            l_spiObj.hdatSpiSlcaIndex = spiDev.residentFruSlcaIndex;
            char *l_vendor = NULL;
            l_vendor = const_cast<char *>(spiDev.description.vendor);
            char *l_deviceType= NULL;
            l_deviceType = const_cast<char *>(spiDev.description.deviceType);
            char *l_dataTypeOrPurpose = NULL;
            l_dataTypeOrPurpose =
                const_cast<char *>(spiDev.description.dataTypeOrPurpose);
            l_hwSubsystemOrScope =
                const_cast<char *>(spiDev.description.hwSubsystemOrScope);
            sprintf(l_spiObj.hdatSpiDevStr,
                "%s,%s,%s,%s",
                l_vendor, l_deviceType, l_dataTypeOrPurpose,
                l_hwSubsystemOrScope);

            o_spiDevEntries.push_back(l_spiObj);

            if(spiDev.partitions.empty())
            {
                HDAT_INF("No EEPROM entries found");
            }
            else // At least one entry found
            {
                for (const auto& eepromDev : spiDev.partitions)
                {
                    hdatEepromPartData_t l_eepromObj;
                    memset(&l_eepromObj, 0x00, sizeof(hdatEepromPartData_t));

                    l_eepromObj.hdatSpiDevId = spiDev.deviceId.word;
                    l_eepromObj.hdatEepmPartDevPurp =
                        static_cast<uint32_t>(eepromDev.partitionPurpose);
                    l_eepromObj.hdatEepmStartOffset = eepromDev.offsetBytes;
                    l_eepromObj.hdatEepmSize = eepromDev.sizeBytes;

                    l_eepromObj.hdatWriteLockInfo.hdatScomAddr.hi =
                        ( eepromDev.writeAccessControl.scomAddress &
                          0xFFFFFFFF00000000ull
                        ) >> 32;
                    l_eepromObj.hdatWriteLockInfo.hdatScomAddr.lo =
                        eepromDev.writeAccessControl.scomAddress &
                        0x00000000FFFFFFFFull;
                    l_eepromObj.hdatWriteLockInfo.hdatScomAddr.hi |=
                        HDAT_REAL_ADDRESS_MASK;
                    l_eepromObj.hdatWriteLockInfo.hdatBitPol =
                        static_cast<uint8_t>
                        (eepromDev.writeAccessControl.bitPolarity);
                    l_eepromObj.hdatWriteLockInfo.hdatIsSticky =
                        eepromDev.writeAccessControl.sticky;
                    l_eepromObj.hdatWriteLockInfo.hdatBitControl =
                        eepromDev.writeAccessControl.secureBitPosition;

                    l_eepromObj.hdatReadLockInfo.hdatScomAddr.hi =
                        ( eepromDev.readAccessControl.scomAddress &
                          0xFFFFFFFF00000000ull
                        ) >> 32;
                    l_eepromObj.hdatReadLockInfo.hdatScomAddr.lo =
                        eepromDev.readAccessControl.scomAddress &
                        0x00000000FFFFFFFFull;
                    l_eepromObj.hdatReadLockInfo.hdatScomAddr.hi |=
                        HDAT_REAL_ADDRESS_MASK;
                    l_eepromObj.hdatReadLockInfo.hdatBitPol =
                        static_cast<uint8_t>
                        (eepromDev.readAccessControl.bitPolarity);
                    l_eepromObj.hdatReadLockInfo.hdatIsSticky =
                        eepromDev.readAccessControl.sticky;
                    l_eepromObj.hdatReadLockInfo.hdatBitControl =
                        eepromDev.readAccessControl.secureBitPosition;

                    o_eepromPartEntries.push_back(l_eepromObj);
                }
            }

            for (const auto& eepromDev : o_eepromPartEntries)
            {
                HDAT_INF("EEPROM partition info: ");
                HDAT_INF("hdatSpiDevId=0x%08X ",eepromDev.hdatSpiDevId);
                HDAT_INF("hdatEepmPartDevPurp=0x%08X ",
                    eepromDev.hdatEepmPartDevPurp);
                HDAT_INF("hdatEepmStartOffset=0x%08X ",
                    eepromDev.hdatEepmStartOffset);
                HDAT_INF("hdatEepmSize=0x%08X ",eepromDev.hdatEepmSize);
                HDAT_INF("hdatWriteLockInfo.hdatBitPol=0x%02X ",
                    eepromDev.hdatWriteLockInfo.hdatBitPol);
                HDAT_INF("hdatWriteLockInfo.hdatIsSticky=0x%02X ",
                    eepromDev.hdatWriteLockInfo.hdatIsSticky);
                HDAT_INF("hdatWriteLockInfo.hdatBitControl=0x%02X ",
                    eepromDev.hdatWriteLockInfo.hdatBitControl);
                HDAT_INF("hdatReadLockInfo.hdatBitPol=0x%02X ",
                    eepromDev.hdatReadLockInfo.hdatBitPol);
                HDAT_INF("hdatReadLockInfo.hdatIsSticky=0x%02X ",
                    eepromDev.hdatReadLockInfo.hdatIsSticky);
                HDAT_INF("hdatReadLockInfo.hdatBitControl=0x%02X ",
                    eepromDev.hdatReadLockInfo.hdatBitControl);
            }
        }
    }

    for (const auto& spiDev : o_spiDevEntries)
    {
        HDAT_INF("SPI device info: ");
        HDAT_INF("hdatSpiDevId=0x%08X ", spiDev.hdatSpiDevId);
        HDAT_INF("hdatSpiMasterEngine=0x%02X ",spiDev.hdatSpiMasterEngine);
        HDAT_INF("hdatSpiMasterPort=0x%02X ",spiDev.hdatSpiMasterPort);
        HDAT_INF("hdatSpiBusSpeed=0x%08X ",spiDev.hdatSpiBusSpeed);
        HDAT_INF("hdatSpiSlaveDevType=0x%02X ",spiDev.hdatSpiSlaveDevType);
        HDAT_INF("hdatSpiDevPurp=0x%08X ",spiDev.hdatSpiDevPurp);
        HDAT_INF("hdatSpiSlcaIndex=0x%04X ",spiDev.hdatSpiSlcaIndex);
        HDAT_INF("hdatSpiDevStr=%s ",spiDev.hdatSpiDevStr);
    }

    HDAT_EXIT();
}

/******************************************************************************/
// hdatGetPrimaryTopIdIndex
/******************************************************************************/
uint8_t hdatGetPrimaryTopIdIndex( const uint32_t i_procEffFabricTopoId,
                                  const uint32_t i_topMod )
{
    HDAT_ENTER();

    // The 5-bit topology index value is derived from the topology ID with below
    // logic
    // MODE0: GGGC -> GGG0C
    // MODE1: GGCC -> 0GGCC
    MEMMAP::topologyIdBits_t l_idBits;
    l_idBits.topoId = i_procEffFabricTopoId;
    MEMMAP::topologyIndexBits_t l_indexBits;
    l_indexBits.topoIndex = 0;

    if(i_topMod == TARGETING::PROC_FABRIC_TOPOLOGY_MODE_MODE0)
    {
        l_indexBits.mode0.group = l_idBits.mode0.group;
        l_indexBits.mode0.chip  = l_idBits.mode0.chip;
    }
    else
    {
        l_indexBits.mode1.group = l_idBits.mode1.group;
        l_indexBits.mode1.chip  = l_idBits.mode1.chip;
    }

    HDAT_EXIT();
    return l_indexBits.topoIndex;
};

} //namespace HDAT
