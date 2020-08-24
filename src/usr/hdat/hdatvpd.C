/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatvpd.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
    if ( strcmp(i_eyeCatcher,HDAT_SYS_VPD_STRUCT_NAME) == 0 )
    {
        HDAT_DBG("fetching node target for SYSVPD");
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
    char *o_fmtKwd = nullptr;
    uint32_t o_fmtkwdSize = 0;
    o_errlHndl = hdatGetAsciiKwd(l_target,iv_kwdSize,iv_kwd,i_vpdType,
                                 i_fetchVpd,i_num,theSize,i_pvpdKeywords);
    //no need to call hdatformatAsciiKwd as the kwd is formatted 
    //in the abovefunction itself  

    HDAT_DBG("hdatGetAsciiKwd returned kwd size =%d",iv_kwdSize);

    /*else //bp vpd
    {
        UtilFile l_bpFile ("pvpd_bp.dat");
        if ( !l_bpFile.exists())
        {
            HDAT_ERR("the backplane vpd file was not found");
        }
        else
        {
            o_errlHndl = l_bpFile.open("r");
            do{
            if (o_errlHndl)
            {
                break;
            }
            o_fmtkwdSize = l_bpFile.size();
            if ( o_fmtkwdSize == 0 )
            {
                HDAT_DBG("no vpd data");
                o_errlHndl = l_bpFile.close();
                if (o_errlHndl)
                {
                    delete o_errlHndl;
                }
                break;
            }
            o_fmtKwd = new char [o_fmtkwdSize];
            l_bpFile.read((void *)&o_fmtKwd[0],o_fmtkwdSize);
            HDAT_DBG("constructed bp vpd data");
            o_errlHndl = l_bpFile.close();
            if (o_errlHndl)
            {
                delete o_errlHndl;
            }
            }while(0);
        }
    }*/
    if( o_fmtKwd != NULL )
    {
        delete[] iv_kwd;
        iv_kwd = new char [o_fmtkwdSize];
        memcpy(iv_kwd,o_fmtKwd,o_fmtkwdSize);
        iv_kwdSize = o_fmtkwdSize;
        delete[] o_fmtKwd;
        o_fmtKwd = nullptr;
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
    if ( strcmp(i_eyeCatcher,HDAT_SYS_VPD_STRUCT_NAME) == 0 )
    {
        HDAT_DBG("fetching node target for SYSVPD");
        TARGETING::TargetHandleList l_targList;
        PredicateCTM predNode(TARGETING::CLASS_ENC, TARGETING::TYPE_NODE);
        PredicateHwas predFunctional;
        //@TODO:RTC 213229(Remove HDAT hack or Axone)
        //crashes below at l_target because the node got deconfigured
        //changed from functional to present
        predFunctional.present(true);
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
    HDAT_DBG("before hdatGetFullRecords");
    o_errlHndl = hdatGetFullRecords(l_target,iv_kwdSize,iv_kwd,i_vpdType,
                                 i_fetchVpd,i_num,theSize);

    HDAT_DBG("hdatGetFullRecords returned kwd size =%d",iv_kwdSize);
    /*else
    {
        UtilFile l_bpFile ("pvpd_bp.dat");
        if ( !l_bpFile.exists())
        {
            HDAT_ERR("the backplane vpd file was not found for full bp vpd");
        }
        else
        {
            o_errlHndl = l_bpFile.open("r");
            do{
                if (o_errlHndl)
                {
                    break;
                }
            iv_kwdSize = l_bpFile.size();
            if (iv_kwdSize == 0)
            {
                HDAT_DBG("no vpd data");
                o_errlHndl = l_bpFile.close();
                if (o_errlHndl)
                {
                    delete o_errlHndl;
                }
                break;
            }
            iv_kwd = new char [iv_kwdSize];
            l_bpFile.read((void *)&iv_kwd[0], iv_kwdSize);
            o_errlHndl = l_bpFile.close();
            if (o_errlHndl)
            {
                delete o_errlHndl;
            }
            HDAT_DBG("constructed full bp vpd data");
            }while(0);
        }
    }*/

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
