/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatutil.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <i2c/eepromif.H>
#include <stdio.h>

#define UINT16_IN_LITTLE_ENDIAN(x) (((x) >> 8) | ((x) << 8))
#define HDAT_VPD_RECORD_START_TAG 0x84
#define HDAT_VPD_RECORD_END_TAG 0x78

using namespace TARGETING;
namespace HDAT
{
trace_desc_t *g_trac_hdat = NULL;
TRAC_INIT(&g_trac_hdat,HDAT_COMP_NAME,4096);


/*******************************************************************************
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
    errlHndl_t l_errl = NULL;
    TARGETING::ATTR_RAW_MTM_type l_rawMTM = {0};
    TARGETING::ATTR_SERIAL_NUMBER_type l_serialNumber = {0};
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

   l_errl = deviceRead(l_nodeTarget, NULL, l_vpdSize,
            DEVICE_PVPD_ADDRESS( PVPD::OSYS, PVPD::MM ));

    if(l_errl == NULL)
    {
        uint8_t l_vpddata[l_vpdSize];

        l_errl = deviceRead(l_nodeTarget, l_vpddata, l_vpdSize,
                DEVICE_PVPD_ADDRESS( PVPD::OSYS, PVPD::MM ));

        if(l_errl == NULL)
        {
            const uint8_t l_mtmSize= 0x08;
            //phyp would requre just 8 character of MTM
            strncpy(l_rawMTM,reinterpret_cast<const char*>(l_vpddata), 
                    l_mtmSize);
            for(uint8_t i=0; i<sizeof(l_rawMTM); i++)
            {
                if(l_rawMTM[i] == '-')
                {
                    l_rawMTM[i]='.';
                    break;
                }
            }

            if(!l_pSysTarget->trySetAttr<TARGETING::ATTR_RAW_MTM>
                                                                   (l_rawMTM))
            {
                HDAT_ERR("Error in setting MTM");
            }
        }
    }
    if(l_errl)
    {
        ERRORLOG::errlCommit(l_errl,HDAT_COMP_ID);
    }

    l_errl = deviceRead(l_nodeTarget, NULL, l_vpdSize,
            DEVICE_PVPD_ADDRESS( PVPD::OSYS, PVPD::SS ));

    if(l_errl == NULL)
    {
        uint8_t l_vpddata[l_vpdSize];

        l_errl = deviceRead(l_nodeTarget, l_vpddata, l_vpdSize,
                DEVICE_PVPD_ADDRESS( PVPD::OSYS, PVPD::SS ));

        if(l_errl == NULL)
        {
            const uint8_t l_serialSize = 0x07;
            //phyp would requre just 7 character of serial number
            strncpy(reinterpret_cast<char *>(l_serialNumber),
                    reinterpret_cast<const char*>(l_vpddata),l_serialSize);

            if(!l_pSysTarget->trySetAttr
                <TARGETING::ATTR_SERIAL_NUMBER>(l_serialNumber))
            {
                HDAT_ERR("Error in setting Serial Number");
            }
        }
    }

    if(l_errl)
    {
        ERRORLOG::errlCommit(l_errl,HDAT_COMP_ID);
    }

}

/**
 * @brief This routine gets prefix of location code
 *
 * @pre None
 *
 * @post None
 *
 * @param   o_locCode      - output parameter - Location Code Prefix
 *
 * @return None
 */
void hdatGetLocationCodePrefix(char *o_locCode)
{
    TARGETING::ATTR_RAW_MTM_type l_rawMTM = {0};
    TARGETING::ATTR_SERIAL_NUMBER_type l_serialNumber = {0};
    TARGETING::Target *l_pSysTarget = NULL;

    (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);
    if(l_pSysTarget == NULL)
    {
        HDAT_ERR("Error in getting Top Level Target");
        assert(l_pSysTarget != NULL);
    }

    strcpy(o_locCode, "U");

    //if(l_pSysTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
   // {
   //     assert(false);
   // }

    if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_RAW_MTM>(l_rawMTM))
    {
        if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_SERIAL_NUMBER>
                                                         (l_serialNumber))
        {
            strcat(o_locCode,"OPWR");
            strcat(o_locCode,".");
            strcat(o_locCode,"BAR");
            strcat(o_locCode,".");
            strcat(o_locCode,(const char*)l_serialNumber);
        }
        else
        {
            HDAT_ERR("Error accessing ATTR_SERIAL_NUMBER attribute");
        }
    }
    else
    {
        HDAT_ERR("Error accessing ATTR_RAW_MTM attribute");
    }
}

/**
 * @brief This routine constructs the location Code for the incoming target
 *
 * @pre None
 *
 * @post None
 *
 * @param i_pFruTarget    - input parameter - System target
 *        i_locCodePrefix - input parameter - Location Code prefix
 *        o_locCode - output parameter - Constructed location code
 *
 * @return None
 */
void hdatGetLocationCode(TARGETING::Target *i_pFruTarget,
                                             char *i_locCodePrefix,
                                             char *o_locCode)
{
    TARGETING::ATTR_PHYS_PATH_type l_physPath;
    char *l_pPhysPath;
    char l_locCode[64] = {0};

//@TODO:RTC 149347: Add methods to generate location codes

    if(i_pFruTarget->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_physPath))
    {
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

#if USE_PHYS_PATH_FOR_LOC_CODE

        strncpy(l_hdatslcaentry.location_code,
        reinterpret_cast<const char *>
                    (i_Target->getAttr<TARGETING::ATTR_PHYS_PATH>().toString()),
                                         l_hdatslcaentry.max_location_code_len);
#else

        sprintf(l_locCode, "%s-%s",i_locCodePrefix,(l_suffix+1));

        uint8_t l_index = 0;
        while(l_index < strlen(l_locCode))
        {
            if(l_locCode[l_index] != ' ')
            {
                *o_locCode++ = l_locCode[l_index];
            }
            l_index++;
        }
       // *o_locCode = 0;
#endif
    }
    else
    {
        HDAT_ERR("Error accessing ATTR_PHYS_PATH attribute");
    }
}

/******************************************************************************/
//hdatGetAsciiKwd
/******************************************************************************/

errlHndl_t hdatGetAsciiKwd( TARGETING::Target * i_target,uint32_t &o_kwdSize,
           char* &o_kwd,vpdType i_vpdtype,struct vpdData i_fetchVpd[],
           uint32_t i_num, size_t theSize[])
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
                                            i_fetchVpd,i_num,theSize);
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
           struct vpdData i_fetchVpd[], size_t i_num, size_t theSize[])
{

    errlHndl_t l_err = NULL;
    uint64_t cmds = 0x0;
    uint64_t fails = 0x0;
    VPD::vpdRecord theRecord = 0x0;
    VPD::vpdKeyword theKeyword = 0x0;


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
            cmds++;
            theRecord = i_fetchVpd[curCmd].record;
            theKeyword = i_fetchVpd[curCmd].keyword;

            if( theKeyword == PVPD::LX)
            {
                theSize[curCmd] = 0;
                continue;
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
            HDAT_DBG("fetching BP kwd size PVPD, size initialised=%x "
             " keyword =%04x",theSize[curCmd],theKeyword);
            o_kwdSize += theSize[curCmd];
        }

        HDAT_DBG("hdatGetAsciiKwdForPvpd:: allocating total key word size %d",
                  o_kwdSize);
        o_kwd = new char[o_kwdSize];

        uint32_t loc = 0;
        for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
        {
            theRecord = i_fetchVpd[curCmd].record;
            theKeyword = i_fetchVpd[curCmd].keyword;

            //this conidtion is , if in the top loop there is a fail then
            //theSize[curCmd] will be 0. 
            if( theSize[curCmd] == 0)
            {
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
            HDAT_DBG("hdatGetAsciiKwdForPvpd: read BP data %s",theData);

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
                memcpy(reinterpret_cast<void *>(o_kwd + loc),theData,
                       theSize[curCmd]);

                loc += theSize[curCmd];
                delete[] theData;
                theData = NULL;
                HDAT_DBG("hdatGetAsciiKwdForPvpd: copied to main array %d kwd",
                          curCmd);
            }
        }
    }while(0);

    HDAT_DBG("hdatGetAsciiKwdForPvpd: returning keyword size %d and data %s",
              o_kwdSize,o_kwd);
    return l_err;

}



/******************************************************************************/
//hdatGetPvpdFullRecord
/******************************************************************************/
errlHndl_t hdatGetPvpdFullRecord(TARGETING::Target * i_target,
           uint32_t &o_kwdSize,char* &o_kwd,
           const IpVpdFacade::recordInfo i_fetchVpd[], size_t i_num, size_t theSize[])
{

    errlHndl_t l_err = NULL;
    uint64_t fails = 0x0;
    VPD::vpdRecord theRecord = 0x0;


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
                    true);

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
        o_kwd = new char[o_kwdSize + l_wholeTagSize ];

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

    HDAT_DBG("hdatGetPvpdFullRecord: returning keyword size %d and data %s",
              o_kwdSize,o_kwd);
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

/******************************************************************************/
// hdatGetAsciiKwdForCvpd
/******************************************************************************/
errlHndl_t hdatGetAsciiKwdForCvpd(TARGETING::Target * i_target,
           uint32_t &o_kwdSize,char* &o_kwd,
           struct vpdData i_fetchVpd[], size_t i_num,size_t theSize[])
{

    errlHndl_t l_err = NULL;
    uint64_t cmds = 0x0;
    uint64_t fails = 0x0;
    VPD::vpdRecord theRecord = 0x0;
    VPD::vpdKeyword theKeyword = 0x0;


    o_kwd = NULL;
    o_kwdSize = 0;
    //size_t theSize[i_num];

    do
    {
        assert(i_target != NULL);

        uint8_t *theData = NULL;

        const uint32_t numCmds = i_num;

        for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
        {
            cmds++;
            theRecord = i_fetchVpd[curCmd].record;
            theKeyword = i_fetchVpd[curCmd].keyword;

            HDAT_DBG("fetching DIMM kwd size CVPD, size initialised=%x",
                      theSize[curCmd]);
            l_err = deviceRead( i_target,
                              NULL,
                              theSize[curCmd],
                              DEVICE_CVPD_ADDRESS( theRecord,
                                                   theKeyword ) );

            if( l_err )
            {
                fails++;
                HDAT_DBG("hdatGetAsciiKwdForCvpd::failure reading keyword size "
                         "rec: 0x%04x, kwd: 0x%04x",
                         theRecord,theKeyword );
                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_UTIL_CVPD_READ_FUNC
                 * @reasoncode       HDAT::RC_CVPD_FAIL
                 * @userdata1        cvpd record
                 * @userdata2        cvpd keyword
                 * @devdesc          CVPD read fail
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(l_err,
                    MOD_UTIL_CVPD_READ_FUNC,
                    RC_CVPD_FAIL,
                    theRecord,theKeyword,0,0,
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HDAT_VERSION1,
                    true);


                continue;
            }
            o_kwdSize += theSize[curCmd];
        }

        HDAT_DBG("hdatGetAsciiKwdForCvpd:: allocating total key word size %d",
                  o_kwdSize);
        o_kwd = new char[o_kwdSize];

        uint32_t loc = 0;
        for( uint32_t curCmd = 0; curCmd < numCmds; curCmd++ )
        {
            theRecord = i_fetchVpd[curCmd].record;
            theKeyword = i_fetchVpd[curCmd].keyword;

            //this conidtion is , if in the top loop there is a fail then
            //theSize[curCmd] will be 0. 
            if( theSize[curCmd] == 0)
            {
                continue;
            }
            theData = new uint8_t [theSize[curCmd]];

            HDAT_DBG("hdatGetAsciiKwdForCvpd: reading %dth keyword of size %d",
                      curCmd,theSize[curCmd]);

            l_err = deviceRead( i_target,
                              theData,
                              theSize[curCmd],
                              DEVICE_CVPD_ADDRESS( theRecord,
                                                   theKeyword ) );
            HDAT_DBG("hdatGetAsciiKwdForCvpd: read PROC data %s",theData);

            if ( l_err )
            {
                fails++;
                HDAT_DBG("hdatGetAsciiKwdForCvpd: Failure on Record: "
                "0x%04x, keyword: 0x%04x, of size: 0x%04x - test %d",
                theRecord,theKeyword,theSize,curCmd);
                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_UTIL_CVPD_READ_FUNC
                 * @reasoncode       HDAT::RC_CVPD_READ_FAIL
                 * @userdata1        cvpd record
                 * @userdata2        cvpd keyword
                 * @devdesc          CVPD read fail
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(l_err,
                    MOD_UTIL_CVPD_READ_FUNC,
                    RC_CVPD_READ_FAIL,
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
                //copy to output array and free theData
                memcpy(reinterpret_cast<void *>(o_kwd + loc),theData,
                       theSize[curCmd]);

                loc += theSize[curCmd];
                delete[] theData;
                theData = NULL;
                HDAT_DBG("hdatGetAsciiKwdForCvpd: copied to main array %d kwd",
                          curCmd);
            }
        }
    }while(0);

    HDAT_DBG("hdatGetAsciiKwdForCvpd: returning keyword size %d and data %s",
              o_kwdSize,o_kwd);
    return l_err;

}

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
// hdatGetAsciiKwdForSpd
/******************************************************************************/
errlHndl_t hdatGetAsciiKwdForSpd(TARGETING::Target * i_target,
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
        HDAT_DBG("hdatGetAsciiKwdForSpd : Failure on "
                " keyword: 0x%04x, of size: 0x%04x ",
                keyword,o_kwdSize);
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_UTIL_SPD_READ_FUNC
         * @reasoncode       HDAT::RC_SPD_READ_FAIL
         * @userdata1        spd keyword
         * @devdesc          SPD read fail
         * @custdesc         Firmware encountered an internal error
         */
        hdatBldErrLog(l_err,
                    MOD_UTIL_SPD_READ_FUNC,
                    RC_SPD_READ_FAIL,
                    keyword,0,0,0,
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    HDAT_VERSION1,
                    true);

        if ( NULL != o_kwd)
        {
            delete[]  o_kwd;
            o_kwd = NULL;
        }
    }

    HDAT_DBG("hdatGetAsciiKwdForSpd: returning keyword size %d and data %s",
              o_kwdSize,o_kwd);
    return l_err;

}

void hdatGetTarget (const hdatSpiraDataAreas i_dataArea,
                        TARGETING::TargetHandleList &o_targList)
{
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

}

errlHndl_t hdatformatAsciiKwd(const struct vpdData i_fetchVpd[],
        const size_t &i_num, const size_t theSize[], char* &i_kwd,
        const uint32_t &i_kwdSize, char* &o_fmtKwd, uint32_t &o_fmtkwdSize,
        const HdatKeywordInfo i_Keywords[])
{
    HDAT_ENTER();

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
                        DEVICE_EEPROM_ADDRESS(EEPROM::VPD_PRIMARY, 0));
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
 *       The i2c master target handle
 * @param[out] o_i2cDevEntries
 *       The host i2c dev entries
 *
 * @return void
 *
*******************************************************************************/
void hdatGetI2cDeviceInfo(TARGETING::Target* i_pTarget,
    std::vector<hdatI2cData_t>&o_i2cDevEntries)
{
    HDAT_ENTER();
    std::vector<DeviceInfo_t> o_deviceInfo;
    getDeviceInfo( i_pTarget, o_deviceInfo);
    uint32_t l_I2cLinkId = 0;

    if(!o_deviceInfo.size())
    {
        HDAT_INF(" No i2c connections found for i2c master : 0x08X",
                i_pTarget->getAttr<ATTR_HUID>());
    }
    else
    {
        for ( auto &l_i2cDevEle : o_deviceInfo )
        {
            hdatI2cData_t l_hostI2cObj;
            memset(&l_hostI2cObj, 0x00, sizeof(hdatI2cData_t));

            l_hostI2cObj.hdatI2cEngine       = l_i2cDevEle.engine;
            l_hostI2cObj.hdatI2cMasterPort   = l_i2cDevEle.masterPort;
            l_hostI2cObj.hdatI2cBusSpeed     = l_i2cDevEle.busFreqKhz;
            l_hostI2cObj.hdatI2cSlaveDevType = l_i2cDevEle.deviceType;
            l_hostI2cObj.hdatI2cSlaveDevAddr = l_i2cDevEle.addr;
            l_hostI2cObj.hdatI2cSlavePort    = l_i2cDevEle.slavePort;
            l_hostI2cObj.hdatI2cSlaveDevPurp = l_i2cDevEle.devicePurpose;
            l_hostI2cObj.hdatI2cLinkId       = l_I2cLinkId++;

            o_i2cDevEntries.push_back(l_hostI2cObj);
        }
    }

    HDAT_EXIT();
}



} //namespace HDAT
