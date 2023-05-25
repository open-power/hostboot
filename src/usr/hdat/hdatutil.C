/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatutil.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
#include "hdatbldda.H"
#include <eeprom/eepromif.H>
#include <stdio.h>
#include <string.h>
#include <util/utilcommonattr.H>
#include <util/random.H>

#include <targeting/targplatutil.H>

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

    if (nullptr == io_err)
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
    errlHndl_t l_errl = nullptr;
    do
    {
        if(nullptr == i_Target)
        {
            HDAT_ERR("Input Target Pointer is nullptr");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_UTIL_IS_FUNCTIONAL
             * @reasoncode       HDAT::RC_INVALID_OBJECT
             * @devdesc          Input Target Pointer is nullptr
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
    errlHndl_t l_err = nullptr;

    do
    {
        const TARGETING::Target *l_pCTarget = nullptr;
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
    errlHndl_t l_errl = nullptr;
    do
    {
        if(nullptr == i_pTarget)
        {
            HDAT_ERR("Input Target pointer is nullptr.");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_UTIL_CARD_ID
             * @reasoncode       HDAT::RC_INVALID_OBJECT
             * @devdesc          Input Target Pointer is nullptr
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
    errlHndl_t l_errl = nullptr;
    TARGETING::ATTR_RAW_MTM_type l_rawMTM = {};
    TARGETING::ATTR_SERIAL_NUMBER_type l_serialNumber = {};
    TARGETING::Target *l_pSysTarget = TARGETING::UTIL::assertGetToplevelTarget();

    size_t l_vpdSize = 0;

    TARGETING::Target * l_nodeTarget = TARGETING::UTIL::getCurrentNodeTarget();

    HDAT_DBG("before deviceRead  PVPD::VSYS, PVPD::TM");
    l_errl = deviceRead(l_nodeTarget,
                        nullptr,
                        l_vpdSize,
                        DEVICE_PVPD_ADDRESS( PVPD::VSYS, PVPD::TM ));

    if(l_errl == nullptr)
    {
        uint8_t l_vpddata[l_vpdSize+1] = {0};
        l_errl = deviceRead(l_nodeTarget,
                            l_vpddata,
                            l_vpdSize,
                            DEVICE_PVPD_ADDRESS( PVPD::VSYS, PVPD::TM ));

        if(l_errl == nullptr)
        {
            const uint8_t l_mtmSize= 0x08;
            //phyp would require just 8 characters of MTM
            strncpy(l_rawMTM, reinterpret_cast<const char*>(l_vpddata), l_mtmSize);
            HDAT_DBG("from deviceRead l_rawMTM=%s, l_vpddata=%s", l_rawMTM, l_vpddata);

            if(!l_pSysTarget->trySetAttr<TARGETING::ATTR_RAW_MTM>(l_rawMTM))
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

    if(!l_pSysTarget->trySetAttr<TARGETING::ATTR_RAW_MTM>(l_rawMTM))
    {
        HDAT_ERR("Error in setting MTM");
    }

    HDAT_DBG("before deviceRead PVPD::VSYS, PVPD::SE");
    l_errl = deviceRead(l_nodeTarget,
                        nullptr,
                        l_vpdSize,
                        DEVICE_PVPD_ADDRESS( PVPD::VSYS, PVPD::SE ));

    if(l_errl == nullptr)
    {
        uint8_t l_vpddata[l_vpdSize+1] = {0};

        l_errl = deviceRead(l_nodeTarget,
                            l_vpddata,
                            l_vpdSize,
                            DEVICE_PVPD_ADDRESS( PVPD::VSYS, PVPD::SE ));

        if(l_errl == nullptr)
        {
            const uint8_t l_serialSize = 0x07;
            //phyp would require just 7 character of serial number
            strncpy(reinterpret_cast<char *>(l_serialNumber), reinterpret_cast<const char*>(l_vpddata), l_serialSize);
            HDAT_DBG("from deviceRead l_serialNumber=%s and l_vpddata=%s",
                    l_serialNumber,l_vpddata);

            if(!l_pSysTarget->trySetAttr<TARGETING::ATTR_SERIAL_NUMBER>(l_serialNumber))
            {
                HDAT_ERR("Error in setting Serial Number");
            }
        }
    }
    if(!l_pSysTarget->trySetAttr<TARGETING::ATTR_SERIAL_NUMBER>(l_serialNumber))
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
    TARGETING::Target *l_pSystemTarget = TARGETING::UTIL::assertGetToplevelTarget();

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

             while (l_cutString != nullptr)
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
    errlHndl_t l_err = nullptr;

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
    errlHndl_t l_err = nullptr;

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

    errlHndl_t l_err = nullptr;
    uint64_t fails = 0x0;
    VPD::vpdRecord theRecord = 0x0;
    VPD::vpdKeyword theKeyword = 0x0;

    size_t viniSize{};
    uint32_t lxSize{};
    uint8_t numRecords = 2; //VINI and LXR0 for BP
    size_t numViniKwds{};
    size_t numLXKwds {};
    size_t cmds{};

    o_kwd = nullptr;
    o_kwdSize = 0;
    memset (theSize,0, sizeof(size_t) * i_num);

    do
    {
        assert(i_target != nullptr);

        uint8_t *theData = nullptr;

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
                              nullptr,
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

        o_kwd = new char[totSize+1]();
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
            // allocate extra byte for null-termation
            theData = new uint8_t [theSize[curCmd]+1]();

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

                if ( nullptr != theData )
                {
                    delete[]  theData;
                    theData = nullptr;
                }
                continue;
            }
            if ( nullptr != theData )
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
                theData = nullptr;
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

    errlHndl_t l_err = nullptr;
    uint64_t fails = 0x0;
    VPD::vpdRecord theRecord = 0x0;
    size_t totSize{};


    o_kwd = nullptr;
    o_kwdSize = 0;
    memset (theSize,0, sizeof(size_t) * i_num);

    do
    {
        assert(i_target != nullptr , "Input target to collect the VPD is nullptr");
        uint8_t *theData = nullptr;

        const uint32_t numRecs = i_num;

        for( uint32_t curRec = 0; curRec < numRecs ; curRec++ )
        {
            theRecord = i_fetchVpd[curRec].record;

            HDAT_DBG("hdatGetPvpdFullRecord : curRecord %d (%s), size = 0x%X (%d)",
                      theRecord, i_fetchVpd[curRec].recordName, theSize[curRec], theSize[curRec]);

            // It is not necessary to include the very large PSPD section of the Platform VPD
            // as it is not used by PHYP.  It is only used during the memory initialization
            // during the IPL.
            if (!(strcmp(i_fetchVpd[curRec].recordName, "PSPD")))
            {
                HDAT_DBG("hdatGetPvpdFullRecord : Skipping %s because of its size 0x%X (%d)",
                          i_fetchVpd[curRec].recordName, theSize[curRec], theSize[curRec]);
                continue;
            }

            l_err = deviceRead( i_target,
                              nullptr,
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
        o_kwd = new char[totSize+1]();
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

                if ( nullptr != theData )
                {
                    delete[]  theData;
                    theData = nullptr;
                }
                continue;
            }
            if ( nullptr != theData )
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
                theData = nullptr;
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
    errlHndl_t err = nullptr;
    uint64_t cmds = 0x0;
    uint64_t fails = 0x0;
    uint64_t theRecord = 0x0;
    uint64_t theKeyword = 0x0;

    o_kwd = nullptr;
    o_kwdSize = 0;


    do
    {
        if(i_target == nullptr)
        {
            HDAT_ERR("no functional Targets found");
            break;
        }

        //size_t theSize[100] = {0};//assuming max kwd num 100
        uint8_t *theData = nullptr;


        for( uint32_t curCmd = 0; curCmd < i_num; curCmd++ )
        {
            cmds++;
            theRecord = (uint64_t)i_fetchVpd[curCmd].record;
            theKeyword = (uint64_t)i_fetchVpd[curCmd].keyword;

            HDAT_DBG("fetching proc kwd size MVPD, size initialised=%x",
                      theSize[curCmd]);
            err = deviceRead( i_target,
                              nullptr,
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
        o_kwd = new char[o_kwdSize+1]();

        uint32_t loc = 0;
        for( uint32_t curCmd = 0; curCmd < i_num; curCmd++ )
        {
            theRecord = (uint64_t)i_fetchVpd[curCmd].record;
            theKeyword = (uint64_t)i_fetchVpd[curCmd].keyword;

            //theData = static_cast<uint8_t*>(malloc( theSize[curCmd]+1));
            // allow extra byte for null-termination
            theData = new uint8_t [theSize[curCmd]+1]();

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

                if ( nullptr != theData )
                {
                   // free( theData );
                    delete[] theData;
                    theData = nullptr;
                }
                continue;
            }
            if ( nullptr != theData )
            {
                //copy to output array and free theData
                memcpy(reinterpret_cast<void *>(o_kwd + loc),theData,
                       theSize[curCmd]);

                loc += theSize[curCmd];
                //free( theData );
                delete[] theData;
                theData = nullptr;
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
    errlHndl_t err = nullptr;
    uint64_t fails = 0x0;
    uint64_t theRecord = 0x0;

    o_kwd = nullptr;
    o_kwdSize = 0;


    do
    {
        if(i_target == nullptr)
        {
            HDAT_ERR("no functional Targets found");
            break;
        }

        uint8_t *theData = nullptr;


        for( uint32_t curRec = 0; curRec < i_num; curRec++ )
        {
            theRecord = (uint64_t)i_fetchVpd[curRec].record;

            HDAT_DBG("fetching proc Record size MVPD, size initialised=%x",
                      theSize[curRec]);
            err = deviceRead( i_target,
                              nullptr,
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

            // allocate extra byte for null-termination
            theData = new uint8_t [theSize[curRec]+1]();

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

                if ( nullptr != theData )
                {
                   // free( theData );
                    delete[] theData;
                    theData = nullptr;
                }
                continue;
            }
            if ( nullptr != theData )
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
                theData = nullptr;
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
        TARGETING::Target* sys = TARGETING::UTIL::assertGetToplevelTarget();

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

    if (nullptr != i_hdif)
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

    if (nullptr != i_data && nullptr != i_hdif)
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

    if (nullptr != i_child && nullptr != i_hdif)
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

    if (nullptr != i_dataArray)
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
    if (nullptr == i_kwd)
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

            l_kwd += 16;
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

    errlHndl_t l_err = nullptr;
    uint64_t keyword = SPD::ENTIRE_SPD;

    do
    {
        assert(i_target != nullptr);
        l_err = deviceRead( i_target,
                            nullptr,
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

        if ( nullptr != o_kwd)
        {
            delete[]  o_kwd;
            o_kwd = nullptr;
        }
    }

    HDAT_DBG("hdatFetchRawSpdData: returning keyword size %d and data %s",
              o_kwdSize,o_kwd);
    return l_err;

}


// Forward declarations for the various IPZ VPD generation functions. Their documentation comes after
// generateIpzFormattedKeyword.
uint32_t  hdatCreateSzKeyword(const char *i_jedec_vpd_ptr);
void copyPoundKeywordIntoIpzVpdData(std::vector<uint8_t> & io_ipzVpdData,
        const VPD::VPD_ASCII_KEYWORD_NAME & i_keywordName,
        const vpdPdKwSize_t & i_keywordSize,
        const uint8_t       * i_keywordData);
void copyKeywordIntoIpzVpdData(std::vector<uint8_t> & io_ipzVpdData,
        const VPD::VPD_ASCII_KEYWORD_NAME & i_keywordName,
        const vpdKwSize_t & i_keywordSize,
        const uint8_t * i_keywordData);
void generateIpzKeywordFromDefault(std::vector<uint8_t> & io_ipzVpdData,
        const VPD::VPD_ASCII_KEYWORD_NAME i_keywordName);
void generateIpzKeywordDataFromAttr(std::vector<uint8_t> & io_ipzVpdData,
        const Target * i_target,
        const VPD::VPD_ASCII_KEYWORD_NAME & i_keywordName);
void generateIpzRecordHeader(std::vector<uint8_t> & io_ipzRecord, const VPD::VPD_ASCII_RECORD_NAME & i_asciiRecordName);
void generateIpzRecordFooter(std::vector<uint8_t> & io_ipzRecordData);
void generateIpzDrKeyword(std::vector<uint8_t> & io_ipzVpdData, const char * i_rawSpdData, const size_t i_rawSpdSize);
void generatePoundIKeyword(std::vector<uint8_t> & io_ipzVpdData, const char * i_rawSpdData, const size_t i_rawSpdSize);
void generatePoundAKeyword(std::vector<uint8_t> & io_ipzVpdData, Target * i_target);

/*
 * @brief This function serves as a centralized dispatcher for the various functions which generate IPZ formatted
 *        keywords. Note, that RT and PF keywords are the only keywords that have a strict ordering requirement. The RT
 *        keyword must always be first as it is part of the header of the IPZ VPD record and used to identify which
 *        record all subsequent keywords belong to. The PF keyword marks the end of a record and created as part of the
 *        footer. All other records do not have ordering requirements per the spec. However, some keywords are generated
 *        with an ordering requirement because their data is largely shared. This isn't required by the spec, it was
 *        just an arbitrary decision made by the consumers of the data and their generation was coupled together
 *        for optimization reasons.
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append this keyword to.
 * @param[in]     i_target         The dimm/ocmb target to pull the #A keyword data from.
 * @param[in]     i_recordName     The ASCII record name.
 * @param[in]     i_keywordName    The ASCII keyword name.
 * @param[in]     i_rawSpdData     A pointer to the "raw" SPD data read from the i_target retrieved using
 *                                 SPD::ENTIRE_SPD.
 * @param[in]     i_rawSpdSize     The size of the "raw" SPD data.
 */
void generateIpzFormattedKeyword(std::vector<uint8_t> & io_ipzVpdData,
                                 Target * i_target,
                                 const VPD::VPD_ASCII_RECORD_NAME & i_recordName,
                                 const VPD::VPD_ASCII_KEYWORD_NAME & i_keyword,
                                 const char * i_rawSpdData,
                                 const size_t i_rawSpdSize)
{
        switch(i_keyword)
        {
            case (VPD::RT):
            {
                generateIpzRecordHeader(io_ipzVpdData, i_recordName);
                break;
            }
            case (VPD::SZ):
            {
                // DR keyword will fill this
                break;
            }
            case (VPD::DR):
            {
                generateIpzDrKeyword(io_ipzVpdData, i_rawSpdData, i_rawSpdSize);
                break;
            }
            case (VPD::CC):
            case (VPD::SN):
            case (VPD::PN):
            case (VPD::FN):
            {
                generateIpzKeywordDataFromAttr(io_ipzVpdData, i_target, i_keyword);
                break;
            }
            case (VPD::CE):
            case (VPD::VZ):
            case (VPD::HE):
            case (VPD::CT):
            case (VPD::HW):
            case (VPD::B3):
            case (VPD::B4):
            case (VPD::B7):
            case (VPD::PR):
            {
                generateIpzKeywordFromDefault(io_ipzVpdData, i_keyword);
                break;
            }
            case (VPD::PF):
            {
                generateIpzRecordFooter(io_ipzVpdData);
                break;
            }
            case (VPD::POUND_A):
            {
                generatePoundAKeyword(io_ipzVpdData, i_target);
                break;
            }
            case (VPD::POUND_B):
            {
                // Do nothing.
                break;
            }
            case (VPD::POUND_I):
            {
                generatePoundIKeyword(io_ipzVpdData, i_rawSpdData, i_rawSpdSize);
                break;
            }
            case (VPD::VPD_ASCII_KEYWORD_INVALID):
            {
                assert(false);
            }
        }
}

/* @brief This function will generate the record header for a given record name using the standard ipz record header
 *        format. The record length field will be set to zero since it's not known how long the record will be at the
 *        time this record is created. It is the caller's responsibility to set that field once the record has been
 *        completed.
 *
 *        Generally, the flow for creating an IPZ record is to include the standard IPZ record header described in this
 *        function below, add keywords, and complete the record with the footer. The footer is described in the function
 *        generateIpzRecordHeader.
 *
 * @param[in/out] io_ipzRecord      The vector to hold the record header in. Will be cleared before the record is added.
 * @param[in]     i_asciiRecordName The ASCII record name.
 */
void generateIpzRecordHeader(std::vector<uint8_t> & io_ipzRecord, const VPD::VPD_ASCII_RECORD_NAME & i_asciiRecordName)
{
    // Start with an empty record
    io_ipzRecord.clear();

    // Fill in the record header
    standard_ipz_record_hdr header;
    header.large_resource = VPD_RECORD_START_MAGIC_NUM;
    header.record_length = 0; // This is populated later when completing the record footer.
    header.rt_kw_name = VPD::RT;
    header.rt_kw_len = VPD_RT_KEYWORD_SIZE;
    header.rt_kw_val = i_asciiRecordName;

    // Copy the data into the record
    io_ipzRecord.insert(io_ipzRecord.end(), reinterpret_cast<uint8_t*>(&header),
                        reinterpret_cast<uint8_t*>(&header) + sizeof(standard_ipz_record_hdr));
}

/* @brief This function will generate the record footer for a given record name. The footer is just the PF keyword and
 *        the record end magic number. It will also calculate the size of the given record and update the record header
 *        with that data in little endian, as required by the spec.
 *
 * @param[in/out] io_ipzRecordData      The vector to append the record footer too. Assumes this data comprises only a
 *                                      single IPZ record.
 */
void generateIpzRecordFooter(std::vector<uint8_t> & io_ipzRecordData)
{
    // The length of a VPD record must be divisble by 4
    const size_t WORD_BOUNDARY = 4;
    // The data in each record must be a minimum of 44 bytes long
    const size_t MIN_RECORD_LENGTH = 44;

    // Size of the PF keyword name and size byte
    const size_t PF_SIZE_EXCLUDING_DATA = KEYWORD_BYTE_SIZE + KEYWORD_SIZE_BYTE_SIZE;
    const size_t SMALL_RESOURCE_SIZE = sizeof(VPD_RECORD_END_MAGIC_NUM);
    const size_t VPD_SIZE_INCLUDING_PF_AND_SMALL_RESOURCE_SIZE = io_ipzRecordData.size()
                                                               + PF_SIZE_EXCLUDING_DATA
                                                               + SMALL_RESOURCE_SIZE;

    // Determine the number of 0x00 bytes the pad fill keyword should have as data. Typically will be between 0-3 bytes.
    uint8_t padFillSize = 0;
    if (io_ipzRecordData.size() < MIN_RECORD_LENGTH)
    {
        padFillSize = MIN_RECORD_LENGTH
                    - io_ipzRecordData.size()
                    - PF_SIZE_EXCLUDING_DATA
                    - SMALL_RESOURCE_SIZE;
    }
    else if ((VPD_SIZE_INCLUDING_PF_AND_SMALL_RESOURCE_SIZE % WORD_BOUNDARY) != 0)
    {
        // When calculating how many extra bytes to fill, take (VPD data size % WORD_BOUNDARY) and subtract it
        // from the WORD_BOUNDARY. This gives how many bytes off the data is from being word aligned and thus how
        // many to add to achieve word alignment.
        padFillSize = WORD_BOUNDARY - (VPD_SIZE_INCLUDING_PF_AND_SMALL_RESOURCE_SIZE % WORD_BOUNDARY);
    }
    else
    {
        // Size of the VPD data including PF keyword w/ size==0 and small resource indicator fits on word boundary.
        // There is no need to add any extra padding beyond just including the PF keyword and size==0.
    }

    // Add the PF and PF size to the data buffer
    const uint16_t PF_KEYWORD = VPD::PF;
    io_ipzRecordData.insert(io_ipzRecordData.end(),
                         reinterpret_cast<const uint8_t *>(&PF_KEYWORD),
                         reinterpret_cast<const uint8_t *>(&PF_KEYWORD) + KEYWORD_BYTE_SIZE);
    io_ipzRecordData.insert(io_ipzRecordData.end(),
                         padFillSize);
    if (padFillSize != 0)
    {
        io_ipzRecordData.insert(io_ipzRecordData.end(),
                             padFillSize,
                             0x00);
    }
    // Add small resource indicator to mark the end of this record
    io_ipzRecordData.insert(io_ipzRecordData.end(),
                         VPD_RECORD_END_MAGIC_NUM);

    // Calculate the size of this record.
    // The record size only includes the bytes between the large and small resource indicators, excluding the bytes for
    // record length as well.
    const uint16_t RECORD_LENGTH = io_ipzRecordData.size()
                                 - SMALL_RESOURCE_SIZE
                                 - sizeof(VPD_RECORD_START_MAGIC_NUM)
                                 - sizeof(uint16_t); // Do not include the size of the RECORD_LENGTH itself.
    standard_ipz_record_hdr * recordHdr = reinterpret_cast<standard_ipz_record_hdr *>(io_ipzRecordData.data());
    recordHdr->record_length = htole16(RECORD_LENGTH);
}

/**
 * @brief This helper function adds the fully formed pound keyword to a given vector of VPD data. The pound keywords all
 *        start with the # symbol to indicate that their size field is two bytes wide instead of one.
 *
 *        Example(hex) : 23 49 00 10 12 34 56 ......
 *                       #  I  ^SIZE ^DATA
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append this keyword to.
 * @param[in]     i_keywordName    The ASCII keyword name.
 * @param[in]     i_keywordSize    The size of the keyword. This is copied into the VPD in little endian form.
 * @param[in]     i_keywordData    The keyword data of length i_keywordSize.
 *
 */
void copyPoundKeywordIntoIpzVpdData(std::vector<uint8_t> & io_ipzVpdData,
                                    const VPD::VPD_ASCII_KEYWORD_NAME & i_keywordName,
                                    const vpdPdKwSize_t & i_keywordSize,
                                    const uint8_t       * i_keywordData)
{
    // Copy the keyword name
    io_ipzVpdData.insert(io_ipzVpdData.end(),
                         reinterpret_cast<const uint8_t *>(&i_keywordName),
                         reinterpret_cast<const uint8_t *>(&i_keywordName) + sizeof(VPD::VPD_ASCII_KEYWORD_NAME));

    // Swap the bytes to be in little endian as required by the spec.
    const vpdPdKwSize_t littleEndianKeywordSize = htole16(i_keywordSize);
    // Copy the keyword size
    io_ipzVpdData.insert(io_ipzVpdData.end(),
                         reinterpret_cast<const uint8_t *>(&littleEndianKeywordSize),
                         reinterpret_cast<const uint8_t *>(&littleEndianKeywordSize) + sizeof(vpdPdKwSize_t));

    // Copy the keyword data
    io_ipzVpdData.insert(io_ipzVpdData.end(),
                         i_keywordData,
                         i_keywordData + i_keywordSize);
}

/**
 * @brief This helper function adds the fully formed keyword to a given vector of VPD data. These keywords do not
 *        start with a pound symbol which means that their size field is only one byte wide.
 *
 *        Example(hex) : 53 5a 07    12 34 56 ......
 *                       S  Z  ^SIZE ^DATA
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append this keyword to.
 * @param[in]     i_keywordName    The ASCII keyword name.
 * @param[in]     i_keywordSize    The size of the keyword.
 * @param[in]     i_keywordData    The keyword data of length i_keywordSize.
 *
 */
void copyKeywordIntoIpzVpdData(std::vector<uint8_t> & io_ipzVpdData,
                               const VPD::VPD_ASCII_KEYWORD_NAME & i_keywordName,
                               const vpdKwSize_t & i_keywordSize,
                               const uint8_t * i_keywordData)
{
    // Copy the keyword name
    io_ipzVpdData.insert(io_ipzVpdData.end(),
                         reinterpret_cast<const uint8_t *>(&i_keywordName),
                         reinterpret_cast<const uint8_t *>(&i_keywordName) + sizeof(VPD::VPD_ASCII_KEYWORD_NAME));

    // Copy the keyword size
    io_ipzVpdData.insert(io_ipzVpdData.end(),
                         reinterpret_cast<const uint8_t *>(&i_keywordSize),
                         reinterpret_cast<const uint8_t *>(&i_keywordSize) + sizeof(vpdKwSize_t));

    // Copy the keyword data
    io_ipzVpdData.insert(io_ipzVpdData.end(),
                         i_keywordData,
                         i_keywordData + i_keywordSize);
}

/* @brief This function will add the default value for a required VINI keyword to the vector of ipz formatted VPD Data
 *        given.
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append this keyword to.
 * @param[in]     i_keywordName    The ASCII keyword name.
 *
 */
void generateIpzKeywordFromDefault(std::vector<uint8_t> & io_ipzVpdData, const VPD::VPD_ASCII_KEYWORD_NAME i_keywordName)
{
    // These are the set of required keywords for the VINI record and their default values. This excludes the RT and PF
    // keywords which are also required because they deviate from the specified form below enough to warrant their own
    // generation methods. The RT and PF keywords are also common across many records and so they can be generalized for
    // use with any record.
    //
    // Notably, optional keywords like SZ, are not included here because they are optional.
    static const std::vector<keyword_t> DEFAULT_VINI_KEYWORDS
    {
        { VPD::DR, VPD_DR_KEYWORD_SIZE, std::vector<uint8_t>(VPD_DR_KEYWORD_SIZE, 0x2E) },
        { VPD::CE, VPD_CE_KEYWORD_SIZE, std::vector<uint8_t>(VPD_CE_KEYWORD_SIZE, 0x31) },
        { VPD::VZ, VPD_VZ_KEYWORD_SIZE, std::initializer_list<uint8_t>{0x30, 0x31} },
        { VPD::FN, VPD_FN_KEYWORD_SIZE, std::vector<uint8_t>(VPD_FN_KEYWORD_SIZE, 0x30) },
        { VPD::PN, VPD_PN_KEYWORD_SIZE, std::vector<uint8_t>(VPD_PN_KEYWORD_SIZE, 0x30) },
        { VPD::SN, VPD_SN_KEYWORD_SIZE, std::vector<uint8_t>(VPD_SN_KEYWORD_SIZE, 0x30) },
        { VPD::CC, VPD_CC_KEYWORD_SIZE, std::initializer_list<uint8_t>{0x50, 0x78, 0x78, 0x78} },
        { VPD::HE, VPD_HE_KEYWORD_SIZE, std::initializer_list<uint8_t>{0x30, 0x30, 0x30, 0x31} },
        { VPD::CT, VPD_CT_KEYWORD_SIZE, std::vector<uint8_t>(VPD_CT_KEYWORD_SIZE, 0x00) },
        { VPD::HW, VPD_HW_KEYWORD_SIZE, std::initializer_list<uint8_t>{ 0x00, 0x01 } },
        { VPD::B3, VPD_B3_KEYWORD_SIZE, std::vector<uint8_t>(VPD_B3_KEYWORD_SIZE, 0x00) },
        { VPD::B4, VPD_B4_KEYWORD_SIZE, std::vector<uint8_t>(VPD_B4_KEYWORD_SIZE, 0x00) },
        { VPD::B7, VPD_B7_KEYWORD_SIZE, std::vector<uint8_t>(VPD_B7_KEYWORD_SIZE, 0x00) },
        { VPD::PR, VPD_PR_KEYWORD_SIZE, std::initializer_list<uint8_t>{ 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } },
    };

    const auto defaultKeyword = std::find_if(DEFAULT_VINI_KEYWORDS.begin(), DEFAULT_VINI_KEYWORDS.end(),
             [&i_keywordName](const keyword_t i_keyword)
             {
                return i_keyword.name == i_keywordName;
             });
    if (defaultKeyword != nullptr)
    {
        copyKeywordIntoIpzVpdData(io_ipzVpdData,
                                  defaultKeyword->name,
                                  defaultKeyword->size,
                                  defaultKeyword->kwData.data());
    }
    else
    {
        HDAT_INF("generateIpzKeywordFromDefault(): Could not find default keyword data for keyword 0x%X",
                 i_keywordName);
    }
}

/* @brief This function will attempt to find an associated targeting attribute for the given keyword and collect the
 *        data from the given target. It will then populate the given vector with the IPZ formatted keyword. If the
 *        attribute cannot be found or used then this function will attempt to populate the default value for the
 *        keyword.
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append this keyword to.
 * @param[in]     i_target         The target which holds the associated attribute.
 * @param[in]     i_keywordName    The ASCII keyword name.
 *
 */
void generateIpzKeywordDataFromAttr(std::vector<uint8_t> & io_ipzVpdData,
                                    const Target * i_target,
                                    const VPD::VPD_ASCII_KEYWORD_NAME & i_keywordName)
{
    // The following array associates a VPD keyword with an attribute that holds its data.
    using AttrLookupRow = std::tuple<VPD::VPD_ASCII_KEYWORD_NAME, vpdKwSize_t, ATTRIBUTE_ID, size_t>;
    static const std::array<AttrLookupRow, 4> KEYWORD_SIZES =
    {
        std::make_tuple(VPD::CC, VPD_CC_KEYWORD_SIZE,
                        ATTR_FRU_CCIN, sizeof(AttributeTraits<ATTR_FRU_CCIN>::Type)),
        std::make_tuple(VPD::PN, VPD_PN_KEYWORD_SIZE,
                        ATTR_PART_NUMBER, sizeof(AttributeTraits<ATTR_PART_NUMBER>::Type)),
        std::make_tuple(VPD::FN, VPD_FN_KEYWORD_SIZE,
                        ATTR_PART_NUMBER, sizeof(AttributeTraits<ATTR_PART_NUMBER>::Type)),
        std::make_tuple(VPD::SN, VPD_SN_KEYWORD_SIZE,
                        ATTR_SERIAL_NUMBER, sizeof(AttributeTraits<ATTR_SERIAL_NUMBER>::Type)),
    };
    // Presently, FN uses the same value as PN so PN needs to be able to fit into FN.
    static_assert(VPD_FN_KEYWORD_SIZE >= VPD_PN_KEYWORD_SIZE);

    const AttrLookupRow * keywordAttrRow = std::find_if(KEYWORD_SIZES.begin(), KEYWORD_SIZES.end(),
                                 [&i_keywordName](const auto i_lookup)
                                 {
                                     return std::get<0>(i_lookup) == i_keywordName;
                                 });
    if (keywordAttrRow == KEYWORD_SIZES.end())
    {
        HDAT_INF("generateIpzKeywordDataFromAttr(): Could not find attribute associated with keyword 0x%X. "
                 "Using default instead.", i_keywordName);
        generateIpzKeywordFromDefault(io_ipzVpdData, i_keywordName);
        goto ERROR_EXIT;
    }

    {
        const AttrLookupRow kwAttr = *keywordAttrRow;
        const auto ATTR_ID = std::get<2>(kwAttr);
        const auto ATTR_SIZE = std::get<3>(kwAttr);
        uint8_t l_attr[ATTR_SIZE];
        if (!i_target->unsafeTryGetAttr(ATTR_ID, ATTR_SIZE, &l_attr))
        {
            HDAT_INF("generateIpzKeywordDataFromAttr(): Could not get attribute 0x%X associated with keyword 0x%X. "
                     "Using default instead.", ATTR_ID, i_keywordName);
            generateIpzKeywordFromDefault(io_ipzVpdData, i_keywordName);
            goto ERROR_EXIT;
        }
        const vpdKwSize_t MAX_COPY_SIZE = std::get<1>(kwAttr);
        copyKeywordIntoIpzVpdData(io_ipzVpdData,
                                  i_keywordName,
                                  std::min(sizeof(l_attr), static_cast<size_t>(MAX_COPY_SIZE)),
                                  l_attr);
    }
ERROR_EXIT:
    return;
}

/**
 * @brief  Create the SZ keyword for the specific DIMM/OCMB
 *
 * @param[in] i_jedec_vpd_ptr: Raw SPD keyword data
 *
 * @return the SZ keyword value (Memory size in MB)
 *
 */
uint32_t  hdatCreateSzKeyword(const char *i_jedec_vpd_ptr)
{
    uint32_t  l_sdram_cap = 1;
    uint32_t  l_pri_bus_wid = 1;
    uint32_t  l_sdram_wid  = 1;
    uint32_t  l_logical_ranks_per_dimm = 1;
    uint32_t  l_tmp = 0;
    uint8_t   l_dieCount = 1;

    constexpr uint8_t PRIMARY_BUS_WIDTH_BYTE_IN_SPD = SVPD_JEDEC_BYTE_13;
    constexpr uint8_t SDRAM_CAPACITY_BYTE_IN_SPD = SVPD_JEDEC_BYTE_4;
    constexpr uint8_t SDRAM_DEVICE_WIDTH_BYTE_IN_SPD = SVPD_JEDEC_BYTE_12;
    constexpr uint8_t PACKAGE_RANKS_PER_DIMM_BYTE_IN_SPD = SVPD_JEDEC_BYTE_12;

    do
    {
        /* Calculate SDRAM capacity */
        l_tmp = i_jedec_vpd_ptr[SDRAM_CAPACITY_BYTE_IN_SPD] & SVPD_JEDEC_SDRAM_CAP_MASK;

        /* Make sure the bits are not Reserved */
        if(l_tmp > SVPD_JEDEC_SDRAMCAP_RESRVD)
        {
            l_tmp = SDRAM_CAPACITY_BYTE_IN_SPD;
            break;
        }
        l_sdram_cap = (l_sdram_cap << l_tmp) * SVPD_JEDEC_SDRAMCAP_MULTIPLIER;

        /* Calculate Primary bus width */
        l_tmp = i_jedec_vpd_ptr[PRIMARY_BUS_WIDTH_BYTE_IN_SPD] & SVPD_JEDEC_PRI_BUS_WID_MASK;
        if(l_tmp > SVPD_JEDEC_RESERVED_BITS)
        {
            l_tmp = PRIMARY_BUS_WIDTH_BYTE_IN_SPD;
            break;
        }

        l_pri_bus_wid = (l_pri_bus_wid << l_tmp) * SVPD_JEDEC_PRI_BUS_WID_MULTIPLIER;

        /* Calculate SDRAM width */
        l_tmp = i_jedec_vpd_ptr[SDRAM_DEVICE_WIDTH_BYTE_IN_SPD] & SVPD_JEDEC_SDRAM_WID_MASK;
        if(l_tmp > SVPD_JEDEC_RESERVED_BITS)
        {
            l_tmp = SDRAM_DEVICE_WIDTH_BYTE_IN_SPD;
            break;
        }
        l_sdram_wid = (l_sdram_wid << l_tmp) * SVPD_JEDEC_SDRAM_WID_MULTIPLIER;

        /*
         * Number of ranks is calculated differently for "Single load stack"
         * (3DS) package and other packages.
         *
         * Logical Ranks per DIMM =
         *      for SDP, DDP, QDP: = SPD byte 12 bits 5~3
         *      for 3DS: = SPD byte 12 bits 5~3 times SPD byte 6 bits 6~4
         *
         * */

        l_tmp = i_jedec_vpd_ptr[SVPD_JEDEC_BYTE_6] & SVPD_JEDEC_SIGNAL_LOADING_MASK;

        if(l_tmp == SVPD_JEDEC_SINGLE_LOAD_STACK)
        {
            //Fetch die count
            l_tmp = i_jedec_vpd_ptr[SVPD_JEDEC_BYTE_6] & SVPD_JEDEC_DIE_COUNT_MASK;

            l_tmp >>= SVPD_JEDEC_DIE_COUNT_RIGHT_SHIFT;
            l_dieCount = l_tmp + 1;
        }

        /* Calculate Number of ranks */
        l_tmp = i_jedec_vpd_ptr[PACKAGE_RANKS_PER_DIMM_BYTE_IN_SPD] & SVPD_JEDEC_NUM_RANKS_MASK;

        l_tmp >>= SVPD_JEDEC_RESERVED_BITS;

        if(l_tmp > SVPD_JEDEC_RESERVED_BITS)
        {
            l_tmp = PACKAGE_RANKS_PER_DIMM_BYTE_IN_SPD;
            break;
        }
        l_logical_ranks_per_dimm = (l_tmp + 1) * l_dieCount;

        l_tmp = (l_sdram_cap/SVPD_JEDEC_PRI_BUS_WID_MULTIPLIER)
              * (l_pri_bus_wid/l_sdram_wid)
              * l_logical_ranks_per_dimm;
    }while(0);

    return l_tmp;
}

/* @brief Generates the IPZ formatted DR and SZ keywords. The DR keyword relies on info contained in the SZ keyword so
 *        that keyword is generated first. Then both keywords are appended to the given vector of IPZ VPD data.
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append these keywords to.
 * @param[in]     i_rawSpdData     A pointer to the "raw" SPD data read from the dimm/ocmb target retrieved using
 *                                 SPD::ENTIRE_SPD.
 * @param[in]     i_rawSpdSize     The size of the "raw" SPD data.
 *
 */
void generateIpzDrKeyword(std::vector<uint8_t> & io_ipzVpdData, const char * i_rawSpdData, const size_t i_rawSpdSize)
{
        char     l_dr_str[VPD_DR_KEYWORD_SIZE+1] = "       MB MEMORY";
        char     l_sz_str[VPD_SZ_KEYWORD_SIZE+1] = {'\0'};
        uint32_t l_szValue = 0;

        // Generate SZ keyword
        l_szValue = hdatCreateSzKeyword(i_rawSpdData);
        snprintf(l_sz_str, VPD_SZ_KEYWORD_SIZE+1, "%d", l_szValue);
        HDAT_DBG("l_sz_str = %s with size = %d", l_sz_str, sizeof(l_sz_str));

        // Generate DR keyword. It's just the size with "MB MEMORY" appended to it.
        size_t szStrLength = strlen(l_sz_str);
        memcpy(l_dr_str, l_sz_str, std::min(szStrLength, static_cast<size_t>(VPD_SZ_KEYWORD_SIZE)));
        HDAT_DBG("l_dr_str = %s with size = %d", l_dr_str, sizeof(l_dr_str));

        // Copy DR Keyword into buffer
        copyKeywordIntoIpzVpdData(io_ipzVpdData,
                                  VPD::DR,
                                  VPD_DR_KEYWORD_SIZE,
                                  reinterpret_cast<uint8_t *>(l_dr_str));

        // Copy SZ Keyword into buffer
        copyKeywordIntoIpzVpdData(io_ipzVpdData,
                                  VPD::SZ,
                                  VPD_SZ_KEYWORD_SIZE,
                                  reinterpret_cast<uint8_t *>(l_sz_str));
}

/* @brief Generates the #I keyword and appends it to the IPZ VPD data.
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append this keyword to.
 * @param[in]     i_rawSpdData     A pointer to the "raw" SPD data read from the dimm/ocmb target retrieved using
 *                                 SPD::ENTIRE_SPD.
 * @param[in]     i_rawSpdSize     The size of the "raw" SPD data.
 *
 */
void generatePoundIKeyword(std::vector<uint8_t> & io_ipzVpdData,
                           const char * i_rawSpdData,
                           const size_t i_rawSpdSize)
{
    copyPoundKeywordIntoIpzVpdData(io_ipzVpdData,
                                   VPD::POUND_I,
                                   i_rawSpdSize,
                                   reinterpret_cast<const uint8_t *>(i_rawSpdData));
}

/* @brief Generates the #A keyword and appends it to the IPZ VPD data.
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append this keyword to.
 * @param[in]     i_target         The dimm/ocmb target to pull the #A keyword data from.
 *
 */
void generatePoundAKeyword(std::vector<uint8_t> & io_ipzVpdData,
                           Target * i_target)
{

    size_t keywordSize = 0;
    errlHndl_t err = nullptr;

    // Fetch the size
    err = deviceRead( i_target,
            nullptr,
            keywordSize,
            DEVICE_SPD_ADDRESS( SPD::DIMM_BAD_DQ_DATA ) );
    if (err != nullptr)
    {
        HDAT_INF("Could not read #A keyword size from target with HUID=0x%0.8X", get_huid(i_target));
        delete err;
        err = nullptr;
        goto ERROR_EXIT;
    }

    {
    uint8_t keywordData[keywordSize] = {0};

    // Fetch the data
    err = deviceRead( i_target,
            keywordData,
            keywordSize,
            DEVICE_SPD_ADDRESS( SPD::DIMM_BAD_DQ_DATA ) );
    if (err != nullptr)
    {
        HDAT_INF("Could not read #A keyword data from target with HUID=0x%0.8X", get_huid(i_target));
        delete err;
        err = nullptr;
        goto ERROR_EXIT;
    }

    copyPoundKeywordIntoIpzVpdData(io_ipzVpdData,
                                   VPD::POUND_A,
                                   keywordSize,
                                   keywordData);
    }
ERROR_EXIT:
    return;
}

/*
 * @brief Generates the IPZ formatted VPD for the given dimm/ocmb by various means. This function will only generate the
 *        VINI and VSPD sections which is all HDAT needs for its purposes.
 *
 * @param[in/out] io_ipzVpdData    The vector of VPD data to append this keyword to.
 * @param[in]     i_target         The dimm/ocmb target to pull data from.
 */
errlHndl_t generateIpzFormattedVpd(const uint32_t    i_rid,
                                   std::vector<uint8_t> & io_ipzVpdData,
                                   TARGETING::Target * i_target)
{
    // Data is pulled from the "raw" SPD from the target
    size_t rawSpdSize = 0;
    char * rawSpd = nullptr; // @TODO JIRA PFHB-387 Does this need to be deleted? Better name too
    bool invalidDimm = false;
    errlHndl_t errl = hdatFetchRawSpdData(i_target, rawSpdSize, rawSpd);
    if ((errl != nullptr) || (rawSpd == nullptr))
    {
        HDAT_INF("Error getting raw SPD data for target HUID=0x%X with rid = %d", get_huid(i_target), i_rid);
        goto ERROR_EXIT;
    }

    { // goto label scope

    TARGETING::ATTR_MEM_MRW_IS_PLANAR_type isDimms = false;
    if (!i_target->tryGetAttr<ATTR_MEM_MRW_IS_PLANAR>(isDimms))
    {
        isDimms = false;
    }
    HDAT_INF("hdatConvertRawSpdToIpzFormat HUID=0x%X isDimms=0x%X", TARGETING::get_huid(i_target), isDimms);
    // Check for the DIMM module and DIMM type from the raw SPD data. Unsupported types will generate an error.
    if((rawSpd[SVPD_SPD_BYTE_THREE] == SVPD_DDIMM_MODULE_TYPE) ||
       (rawSpd[SVPD_SPD_BYTE_THREE] == SVPD_PLANAR_MODULE_TYPE))
    {
        if (rawSpd[SVPD_SPD_BYTE_TWO] == SVPD_DDR4_DEVICE_TYPE)
        {
            HDAT_DBG("Detected DDR4");
        }
        else if (rawSpd[SVPD_SPD_BYTE_TWO] == SVPD_DDR5_DEVICE_TYPE)
        {
            HDAT_DBG("Detected DDR5 DDIMM");
        }
        else
        {
            HDAT_DBG("Detected an unknown DDR type");
            HDAT_ERR("Invalid Byte 2 value(0x%2X), Unable to determine DDR type for target HUID=0x%X RID 0x%X.",
                     rawSpd[SVPD_SPD_BYTE_TWO],
                     get_huid(i_target),
                     i_rid);
            invalidDimm = true;
        }
        if(invalidDimm == true)
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
            hdatBldErrLog(errl,
                  MOD_SPD_RAW_CONVERT_TO_IPZ_MODULE,   // SRC module ID
                  RC_INVALID_DIMM_MODULE,              // SRC ext ref code
                  i_rid,                               // SRC hex word 1
                  rawSpdSize,                          // SRC hex word 2
                  rawSpd[SVPD_SPD_BYTE_THREE],    // SRC hex word 3
                  0,                                   // SRC hex word 4
                  ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            goto ERROR_EXIT;
        }
    }
    else if(rawSpd[SVPD_SPD_BYTE_THREE] == SVPD_ISDIMM_MODULE_TYPE)
    {
        HDAT_DBG("hdatConvertRawSpdToIpzFormat rawSpd[SVPD_SPD_BYTE_THREE]=0x%X HUID=0x%X isDimms=0x%X",
                  rawSpd[SVPD_SPD_BYTE_THREE], TARGETING::get_huid(i_target), isDimms);
    }
    else
    {
        HDAT_ERR( "Invalid Byte 3 value(0x%2X), Unable to determine DIMM type for target HUID=%X RID 0x%X.",
                  rawSpd[SVPD_SPD_BYTE_THREE],
                  get_huid(i_target),
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
        hdatBldErrLog(errl,
                  MOD_SPD_RAW_CONVERT_TO_IPZ_TYPE,     // SRC module ID
                  RC_INVALID_DIMM_TYPE,                // SRC ext ref code
                  i_rid,                               // SRC hex word 1
                  rawSpdSize,                          // SRC hex word 2
                  rawSpd[SVPD_SPD_BYTE_THREE],    // SRC hex word 3
                  0,                                   // SRC hex word 4
                  ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        goto ERROR_EXIT;
    }

    HDAT_DBG("rawSpd[SVPD_SPD_BYTE_TWO]=0x%x", rawSpd[SVPD_SPD_BYTE_TWO]);
    HDAT_DBG("rawSpd[SVPD_SPD_BYTE_THREE]=0x%x", rawSpd[SVPD_SPD_BYTE_THREE]);

    // The set of keywords for this record
    constexpr std::array<VPD::VPD_ASCII_KEYWORD_NAME, 17> FILLED_VINI_KEYWORDS
    {
        VPD::RT,
        VPD::SZ, // No-op, DR will fill this since it depends on it. Listed for completeness
        VPD::DR,
        VPD::CC,
        VPD::SN,
        VPD::PN,
        VPD::FN, // Same as PN
        VPD::CE,
        VPD::VZ,
        VPD::HE,
        VPD::CT,
        VPD::HW,
        VPD::B3,
        VPD::B4,
        VPD::B7,
        VPD::PR,
        VPD::PF,
    };
    // Must have RT and PF keywords in the front and back of the array respectively. Otherwise the record will
    // not be generated properly.
    static_assert((FILLED_VINI_KEYWORDS.front() == VPD::RT) && (FILLED_VINI_KEYWORDS.back() == VPD::PF),
                 "RT or PF out of order for FILLED_VINI_KEYWORDS");

    // Start with an empty vector
    io_ipzVpdData.clear();
    for (const auto keyword : FILLED_VINI_KEYWORDS)
    {
        generateIpzFormattedKeyword(io_ipzVpdData, i_target, VPD::VINI, keyword, rawSpd, rawSpdSize);
    }

    constexpr std::array<VPD::VPD_ASCII_KEYWORD_NAME, 4> FILLED_VSPD_KEYWORDS
    {
        VPD::RT,
        VPD::POUND_I,
        VPD::POUND_A,
        VPD::PF
    };
    // Must have RT and PF keywords in the front and back of the array respectively. Otherwise the record will
    // not be generated properly.
    static_assert((FILLED_VSPD_KEYWORDS.front() == VPD::RT) && (FILLED_VSPD_KEYWORDS.back() == VPD::PF),
                 "RT or PF out of order for FILLED_VSPD_KEYWORDS");

    std::vector<uint8_t> VSPD_record;
    for (const auto keyword: FILLED_VSPD_KEYWORDS)
    {
        generateIpzFormattedKeyword(VSPD_record, i_target, VPD::VSPD, keyword, rawSpd, rawSpdSize);
    }

    // Add the VSPD to the full VPD data
    io_ipzVpdData.insert(io_ipzVpdData.end(),
                         VSPD_record.begin(),
                         VSPD_record.end());
    }
ERROR_EXIT:
    if (rawSpd != nullptr)
    {
        delete [] rawSpd;
        rawSpd = nullptr;
    }
    return errl;
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
        TARGETING::Target* l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(l_sys);
        assert(l_sys != nullptr);

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

    // Pad Filler (PF) Total Size (6) = Keyword length (2) + Size (1) + Data (3)
    uint8_t l_padFillerTotalSize = 6;

    // i_kwdSize - data size
    // (i_num* sizeof(uint8_t)) - individual datat size
    // (2 * sizeof(uint8_t)) - 0x78, 0x84
    // sizeof(uint16_t) = total data size in size
    // (i_num* 2) - keyword size
    // l_padFillerTotalSize - Pad Filler(PF) total size
    o_fmtkwdSize = i_kwdSize + (i_num* sizeof(uint8_t)) +
                    (2 * sizeof(uint8_t)) + sizeof(uint16_t) + (i_num* 2) +
                     l_padFillerTotalSize;

    o_fmtKwd = new char[o_fmtkwdSize]();
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

   // Add the PF keyword which is common with all VPD records
   memcpy(reinterpret_cast<void *>(o_fmtKwd + l_loc), "PF",2);
   l_loc += 2;

   // PF length is set as 3 and values will be all zeroes
   uint8_t l_pfLength = 3;
   memcpy(reinterpret_cast<void *>(o_fmtKwd + l_loc),&l_pfLength,
          sizeof(uint8_t));
   l_loc += sizeof(uint8_t);

   // Skipping zero values
   l_loc += l_pfLength;

   // End tag of the section
   uint8_t l_recordEnd= 0x78;
   memcpy(reinterpret_cast<void *>(o_fmtKwd +l_loc),
       &l_recordEnd,sizeof(uint8_t));
   l_loc +=sizeof(uint8_t);

   // VPD end indication
   uint8_t l_vpdEnd= 0x00;
   memcpy(reinterpret_cast<void *>(o_fmtKwd +l_loc),&l_vpdEnd,sizeof(uint8_t));
   l_loc +=sizeof(uint8_t);

   HDAT_EXIT();
   return nullptr;
}


errlHndl_t hdatGetFullEepromVpd(TARGETING::Target * i_target,
                                size_t &io_dataSize,
                                char* &o_data)
{
    errlHndl_t err = nullptr;

    HDAT_ENTER();
    if(i_target != nullptr)
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
            if(o_data != nullptr)  // No point in keeping this data with err
            {
                delete[] o_data;
                o_data = nullptr;
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
    std::list<hdatI2cData_t>& o_i2cDevEntries)
{
    HDAT_ENTER();

    // This vector is expensive to construct, so initialize it once and then
    // cache it for future uses.
    static const std::list<DeviceInfo_t> deviceInfo =
        ([] {
            std::list<DeviceInfo_t> devinfo;
            getDeviceInfo(nullptr, devinfo);

            // Order by node ordinal ID, processor position, I2C master target
            // pointer
            devinfo.sort(byNodeProcAffinity);

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
            .node=static_cast<uint8_t>(deviceInfo.front().assocNode),
            .proc=static_cast<uint8_t>(deviceInfo.front().assocProc),
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
 /*   errlHndl_t l_err = nullptr;
    uint8_t *l_NVKwd = nullptr;
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

    l_err = deviceRead(l_target,nullptr,l_nvKwdSize,
                            DEVICE_PVPD_ADDRESS(l_Record,l_KeyWord));
    if(l_err == nullptr)
    {
        if(l_nvKwdSize == sizeof(hdatNVKwdStruct_t))
        {
            uint8_t l_kwd[l_nvKwdSize] = {0};
            l_err = deviceRead(l_target,l_kwd,l_nvKwdSize,
                            DEVICE_PVPD_ADDRESS(l_Record,l_KeyWord));

            if(l_err == nullptr)
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

    const hdatSMPLinkInfo_t *l_smpLinkInfoPtr = nullptr;
    uint32_t           l_smpLinkInfoSize = 0;

    if(l_NVKwd != nullptr)
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
    if(l_NVKwd != nullptr)
    {
        delete l_NVKwd;
        l_NVKwd = nullptr;
    }
    if(l_err != nullptr)
    {
        delete l_err;
        l_err = nullptr;
    }

*/
    HDAT_EXIT();
}

errlHndl_t hdatUpdateSMPLinkInfoData(hdatHDIFDataArray_t * i_SMPInfoFullPcrdHdrPtr ,
                                        hdatSMPLinkInfo_t * io_SMPInfoFullPcrdDataPtr,
                                        TARGETING::Target* i_pProcTarget)
{
    errlHndl_t l_errl = nullptr;
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
            if(l_errl != nullptr)
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
            uint32_t *l_freqList = nullptr;
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

            if(l_freqList == nullptr)
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
            if(l_errl != nullptr){break;};
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
            "hbrt Id=0x%02X, "
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
    char *l_hwSubsystemOrScope = nullptr;

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
            char *l_vendor = nullptr;
            l_vendor = const_cast<char *>(spiDev.description.vendor);
            char *l_deviceType= nullptr;
            l_deviceType = const_cast<char *>(spiDev.description.deviceType);
            char *l_dataTypeOrPurpose = nullptr;
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
