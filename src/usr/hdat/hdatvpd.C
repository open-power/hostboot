/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatvpd.C $                                      */
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
 * @file hdatvpd.C
 *
 * @brief This file contains the implementation of the HdatVpd class.
 *
 */


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdlib.h>
#include "hdatvpd.H"
#include "hdatutil.H"
#include <hdat/hdat_reasoncodes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/util.H>

using namespace TARGETING;

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Global variables                                                           */
/*----------------------------------------------------------------------------*/
extern trace_desc_t * g_hdatTraceDesc;


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
const uint16_t HDAT_VPD_VERSION = 0x0020;


/** @brief See the prologue in hdatvpd.H
 */
HdatVpd::HdatVpd(errlHndl_t &o_errlHndl,
                 uint32_t i_resourceId,
                 TARGETING::Target * i_target,
                 const char *i_eyeCatcher,
                 uint32_t i_index,
                 vpdType i_vpdType,
                 struct vpdData i_fetchVpd[],
                 uint32_t i_num,
                 const HdatKeywordInfo i_pvpdKeywords[])
: HdatHdif(o_errlHndl, i_eyeCatcher, HDAT_VPD_LAST,i_index,HDAT_NO_CHILD,
           HDAT_VPD_VERSION),
iv_kwdSize(0), iv_kwd(NULL)
{
    HDAT_ENTER();
    o_errlHndl = NULL;
    uint32_t l_slcaIdx = 0;
    TARGETING::Target * l_target=i_target;
    i_target->tryGetAttr<TARGETING::ATTR_SLCA_INDEX>(l_slcaIdx);

    //overriding target for BP  vpd
    if ( FRU_SV == (i_resourceId >> 8 ) )
    {
        TARGETING::TargetHandleList l_targList;
        PredicateCTM predNode(TARGETING::CLASS_ENC, TARGETING::TYPE_NODE);
        PredicateHwas predFunctional;
        predFunctional.functional(true);
        PredicatePostfixExpr nodeCheckExpr;
        nodeCheckExpr.push(&predNode).push(&predFunctional).And();

        targetService().getAssociated(l_targList, i_target,
                TargetService::CHILD, TargetService::IMMEDIATE,
                &nodeCheckExpr);
        l_target = l_targList[0];
    }

    //@TODO:RTC 149382(Method to get VPD collected status for Targets)
    GARD_FunctionalState l_functional = GARD_Functional;
    GARD_UsedState l_used = GARD_Used;

    if (GARD_Functional == l_functional ||
        GARD_PartialFunctional == l_functional)
    {
        iv_status.hdatFlags =  HDAT_VPD_FRU_FUNCTIONAL;
    }
    if (GARD_Used == l_used)
    {
        iv_status.hdatFlags |= HDAT_VPD_REDUNDANT_FRU_USED;
    }

    iv_fru.hdatResourceId = i_resourceId;
    size_t theSize[i_num];
    //get the SLCA index and the keyword for the RID
    o_errlHndl = hdatGetAsciiKwd(l_target,iv_kwdSize,iv_kwd,i_vpdType,
                                 i_fetchVpd,i_num,theSize);

    HDAT_DBG("hdatGetAsciiKwd returned kwd size =%d",iv_kwdSize);

    if(strcmp(i_eyeCatcher,"IO KID")==0)
    {
        using namespace TARGETING;
        // Get Target Service, and the system target.
        TARGETING::TargetService& l_targetService = targetService();
        TARGETING::Target* l_sysTarget = NULL;
        (void) l_targetService.getTopLevelTarget(l_sysTarget);

        assert(l_sysTarget != NULL);

        //fetching lx data
        uint64_t l_LXvalue = l_sysTarget->getAttr<ATTR_ASCII_VPD_LX_KEYWORD>();
        char *temp_kwd = new char [iv_kwdSize];
        uint32_t temp_kwdSize = iv_kwdSize;
        memcpy(temp_kwd, iv_kwd,iv_kwdSize);
        delete[] iv_kwd;
        iv_kwdSize +=sizeof(uint64_t);
        iv_kwd = new char [iv_kwdSize];
        memcpy(iv_kwd,temp_kwd,temp_kwdSize);
        memcpy((void *)(iv_kwd+temp_kwdSize),&l_LXvalue,sizeof(uint64_t));
        theSize[i_num-1] = sizeof(uint64_t);
        delete[] temp_kwd;
    }
    char *o_fmtKwd;
    uint32_t o_fmtkwdSize;
    o_errlHndl = hdatformatAsciiKwd(i_fetchVpd, i_num, theSize, iv_kwd,
                iv_kwdSize, o_fmtKwd, o_fmtkwdSize, i_pvpdKeywords);
    if( o_fmtKwd != NULL )
    {
        delete[] iv_kwd;
        iv_kwd = new char [o_fmtkwdSize];
        memcpy(iv_kwd,o_fmtKwd,o_fmtkwdSize);
        iv_kwdSize = o_fmtkwdSize;
        delete[] o_fmtKwd;
    }

    if (NULL == o_errlHndl)
    {
        iv_fru.hdatSlcaIdx = l_slcaIdx;
        this->addData(HDAT_VPD_FRU_ID, sizeof(hdatFruId_t));
        this->addData(HDAT_VPD_OP_STATUS, sizeof(hdatFruOpStatus_t));
        //Padding the size
        this->addData(HDAT_VPD_KWD, iv_kwdSize+1);
        this->align();
    }
    HDAT_EXIT();
}



/** @brief See the prologue in hdatvpd.H
 */
HdatVpd::HdatVpd(errlHndl_t &o_errlHndl,
                 uint32_t i_resourceId,
                 TARGETING::Target * i_target,
                 const char *i_eyeCatcher,
                 uint32_t i_index,
                 vpdType i_vpdType,
                 const IpVpdFacade::recordInfo i_fetchVpd[],
                 uint32_t i_num)
: HdatHdif(o_errlHndl, i_eyeCatcher, HDAT_VPD_LAST,i_index,HDAT_NO_CHILD,
           HDAT_VPD_VERSION),
iv_kwdSize(0), iv_kwd(NULL)
{
    HDAT_ENTER();
    o_errlHndl = NULL;
    uint32_t l_slcaIdx = 0;
    TARGETING::Target * l_target=i_target;
    i_target->tryGetAttr<TARGETING::ATTR_SLCA_INDEX>(l_slcaIdx);

    //overriding target for BP  vpd
    if ( FRU_SV == (i_resourceId >> 8 ) )
    {
        TARGETING::TargetHandleList l_targList;
        PredicateCTM predNode(TARGETING::CLASS_ENC, TARGETING::TYPE_NODE);
        PredicateHwas predFunctional;
        predFunctional.functional(true);
        PredicatePostfixExpr nodeCheckExpr;
        nodeCheckExpr.push(&predNode).push(&predFunctional).And();

        targetService().getAssociated(l_targList, i_target,
                TargetService::CHILD, TargetService::IMMEDIATE,
                &nodeCheckExpr);
        l_target = l_targList[0];
    }

    //@TODO:RTC 149382(Method to get VPD collected status for Targets)
    GARD_FunctionalState l_functional = GARD_Functional;
    GARD_UsedState l_used = GARD_Used;

    if (GARD_Functional == l_functional ||
        GARD_PartialFunctional == l_functional)
    {
        iv_status.hdatFlags =  HDAT_VPD_FRU_FUNCTIONAL;
    }
    if (GARD_Used == l_used)
    {
        iv_status.hdatFlags |= HDAT_VPD_REDUNDANT_FRU_USED;
    }

    iv_fru.hdatResourceId = i_resourceId;
    size_t theSize[i_num];
    //get the SLCA index and the keyword for the RID
    o_errlHndl = hdatGetFullRecords(l_target,iv_kwdSize,iv_kwd,i_vpdType,
                                 i_fetchVpd,i_num,theSize);

    HDAT_DBG("hdatGetAsciiKwd returned kwd size =%d",iv_kwdSize);

    if(strcmp(i_eyeCatcher,"IO KID")==0)
    {
        using namespace TARGETING;
        // Get Target Service, and the system target.
        TARGETING::TargetService& l_targetService = targetService();
        TARGETING::Target* l_sysTarget = NULL;
        (void) l_targetService.getTopLevelTarget(l_sysTarget);

        assert(l_sysTarget != NULL);

        //fetching lx data
        uint64_t l_LXvalue = l_sysTarget->getAttr<ATTR_ASCII_VPD_LX_KEYWORD>();
        char *temp_kwd = new char [iv_kwdSize];
        uint32_t temp_kwdSize = iv_kwdSize;
        memcpy(temp_kwd, iv_kwd,iv_kwdSize);
        delete[] iv_kwd;
        iv_kwdSize +=sizeof(uint64_t);
        iv_kwd = new char [iv_kwdSize];
        memcpy(iv_kwd,temp_kwd,temp_kwdSize);
        memcpy((void *)(iv_kwd+temp_kwdSize),&l_LXvalue,sizeof(uint64_t));
        theSize[i_num-1] = sizeof(uint64_t);
        delete[] temp_kwd;
    }
    if (NULL == o_errlHndl)
    {
        iv_fru.hdatSlcaIdx = l_slcaIdx;
        this->addData(HDAT_VPD_FRU_ID, sizeof(hdatFruId_t));
        this->addData(HDAT_VPD_OP_STATUS, sizeof(hdatFruOpStatus_t));
        //Padding the size
        this->addData(HDAT_VPD_KWD, iv_kwdSize+1);
        this->align();
    }
    HDAT_EXIT();
}


/** @brief See the prologue in hdatvpd.H
 */
HdatVpd::~HdatVpd()
{
    HDAT_ENTER();
    if(iv_kwd!= NULL )
    {
        delete[] iv_kwd;
    }
    HDAT_EXIT();
}


uint8_t * HdatVpd::setVpd(uint8_t * io_virt_addr)
{
    uint32_t l_size = 0;
    HDAT_DBG("virtual address=0x%016llX",
             (uint64_t)io_virt_addr);


    io_virt_addr = this->setHdif(io_virt_addr);


    //write hdatFruId_t       iv_fru
    hdatFruId_t *l_hdatFruId = reinterpret_cast<hdatFruId_t *>(io_virt_addr);

    HDAT_DBG("writing FRU ID from address=0x%016llX",
              (uint64_t)l_hdatFruId);

    l_hdatFruId->hdatSlcaIdx = this->iv_fru.hdatSlcaIdx;
    l_hdatFruId->hdatResourceId = this->iv_fru.hdatResourceId;

    l_hdatFruId++;


    //write hdatFruOpStatus_t iv_status
    hdatFruOpStatus_t *l_hdatFruOpStatus =
                       reinterpret_cast<hdatFruOpStatus_t *>(l_hdatFruId);

    l_hdatFruOpStatus->hdatFlags = this->iv_status.hdatFlags;

    l_hdatFruOpStatus++;

    //write kwd
    io_virt_addr = reinterpret_cast<uint8_t *>(l_hdatFruOpStatus);

    if ( (NULL != this->iv_kwd) && (this->iv_kwdSize > 0))
    {
        HDAT_DBG("writing kwd from address 0x%016llX",
                 (uint64_t)io_virt_addr);
        HDAT_DBG("kwd to be added %s,"
                 "size=0x%x sizeof(this->iv_kwd)=0x%x",
                 this->iv_kwd,this->iv_kwdSize,sizeof(this->iv_kwd));

        memcpy(io_virt_addr,(this->iv_kwd),this->iv_kwdSize);

        io_virt_addr += this->iv_kwdSize;

    }

    //write pad

    io_virt_addr = this->setpadding( io_virt_addr,l_size );

    HDAT_EXIT();
    return io_virt_addr;

}//end setVpd

} //namespace HDAT
