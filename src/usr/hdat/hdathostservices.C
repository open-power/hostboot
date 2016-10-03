/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdathostservices.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 * @file hdathostservices.C
 *
 * @brief This file contains the implementation of the HdatHostsr class.
 *
 */


/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <stdlib.h>                 // malloc & free
#include <sys/mm.h>
#include <sys/mmio.h>
#include <util/align.H>
#include "hdathostservices.H"
#include "hdatnodedata.H"           // HdatNodedata class definition
#include "hdathdif.H"
#include "hdatutil.H"
#include "hdatvpd.H"
#include <targeting/common/util.H>

using namespace TARGETING;
namespace HDAT
{
/*-----------------------------------------------------------------------------*/
/* Global variables                                                            */
/*-----------------------------------------------------------------------------*/
extern trace_desc_t *g_trac_hdat;
uint32_t HdatHostsr::cv_actualCnt;

/** @brief See the prologue in hdathostservices.H
 */
HdatHostsr::HdatHostsr(errlHndl_t &o_errlHndl,
                       const hdatMsAddr_t &i_msAddr,
                       uint32_t &o_hostServiceTotalSize,
                       uint32_t &o_hostServiceTotalCnt)
: HdatHdif(o_errlHndl, HDAT_STRUCT_NAME, HDAT_HOSTSR_LAST, cv_actualCnt++, 
  HDAT_CHILD_LAST, HDAT_HOSTSR_VERSION),iv_actNodeCnt(0),iv_NodePtrs(NULL),
  iv_virt_addr(NULL)
{
    HDAT_ENTER();

    // Copy the passedin mainstore address in the local object variable
    memcpy(&iv_msAddr, &i_msAddr, sizeof(hdatMsAddr_t));

    // Total size for Host Service Data Structure
    // including its internal data pointer size.
    iv_size = sizeof(hdatHDIF_t) + 
              ( sizeof(hdatHDIFDataHdr_t) *
                HDAT_HOSTSR_LAST)+
              ( HDAT_CHILD_LAST * sizeof(hdatHDIFChildHdr_t))+
                HDAT_HOSTSR_SIZE + 0x10; // Padding as per spec
    // Find the virtual address to copy all the host service struct
    uint64_t l_base_addr_down = ALIGN_PAGE_DOWN( iv_msAddr );
    iv_virt_addr = (uint8_t *) mm_block_map (
                        reinterpret_cast<void*>(l_base_addr_down),
                        (ALIGN_PAGE(iv_size) + PAGESIZE));
    iv_hostServiceData = iv_virt_addr + (iv_msAddr - ALIGN_PAGE_DOWN(iv_msAddr));

    // Add up the Service Data structure size to o/p var
    o_hostServiceTotalSize += iv_size;
    o_hostServiceTotalCnt = 1; // Only one host service Data structure

    // Calling the hdatHostServiceBuild
    o_errlHndl= this->hdatHostServiceBuild(o_hostServiceTotalSize);

    HDAT_EXIT();
    return;
}



/** @brief See the prologues in hdathostservices.H
*/
errlHndl_t HdatHostsr::hdatHostServiceBuild(uint32_t &o_hostServiceTotalSize)
{
    errlHndl_t l_errlHndl = NULL;
    HDAT_ENTER();
    
    do{
    
        /*** Add the parent Data pointer first ***/
 
        this->addData(HDAT_SYSTEM_ATTRIBUTE, HDAT_HOSTSR_SIZE);
        this->align();

        /*** Create and Set the children ***/

        // Lets build the node data child structures
        // by looping into all nodes in bldNodeDataStruct

        uint32_t l_NodeDataSize = 0;
        l_errlHndl = this->bldNodeDataStruct(l_NodeDataSize);
        if(l_errlHndl == NULL)
        {
            // Done with node data.Add up the node data size to o/p var
            o_hostServiceTotalSize += l_NodeDataSize;
        }
        else
        {
            HDAT_ERR("bldNodeDataStruct returned error");
            break;
        }
        /**** Creation of children done ******/

        /*** Commit the Parent ***/

        // set the header section of host services in the constructed memory space
        iv_hostServiceData = this->setHdif(iv_hostServiceData);

        //Set the internal Data pointer Data of (parent) host services
        memset(iv_hostServiceData,0, HDAT_HOSTSR_SIZE);
        iv_hostServiceData += HDAT_HOSTSR_SIZE;
        
        /*** Parent commiting Done ***/

        /*** Commit the children ***/

        // Now lets commit the child structures.
        l_errlHndl=this->setChildPtrs(); 

        /*** Children commiting Done ***/

    }while(0);
    
    HDAT_EXIT();
    return l_errlHndl;
}

HdatHostsr::~HdatHostsr()
{   
    errlHndl_t l_errlHndl = NULL;
    HDAT_ENTER();

    /*** Unmap the virtual address of parent ***/

    uint32_t rc =  mm_block_unmap(reinterpret_cast<void*>(
                    ALIGN_PAGE_DOWN((uint64_t)iv_virt_addr)));
    if( rc != 0)
    {
        /*@
        * @errortype
        * @moduleid         HDAT::MOD_HDAT_SERVICEDATA_CTOR
        * @reasoncode       HDAT::RC_DEV_MAP_FAIL
        * @devdesc          Unmap a mapped region failed
        * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(l_errlHndl,
                HDAT::MOD_HDAT_SERVICEDATA_CTOR,
                RC_DEV_MAP_FAIL,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }
    /*** Unmap of parent addr done ***/

    /*** Unmap the virtual address of children ***/

    uint32_t l_cnt;
    HdatNodedata *l_nodeDataObj, **l_curPtr;

    l_curPtr = iv_NodePtrs;

    for (l_cnt = 0; l_cnt < iv_actNodeCnt; l_cnt++)
    {
        l_nodeDataObj = *l_curPtr;
        delete l_nodeDataObj;
        l_curPtr = reinterpret_cast<HdatNodedata **>(reinterpret_cast<char *>
                   (l_curPtr) + sizeof(HdatNodedata *));
    }

    // Free heap storage
    free(iv_NodePtrs); 

    /*** Unmap of children addrresses done ***/

    HDAT_EXIT();
}
/** @brief See the prologue in hdathostservices.H
 */

errlHndl_t HdatHostsr::bldNodeDataStruct(uint32_t &o_NodeDataSize)
{
    HDAT_ENTER();

    errlHndl_t l_errlHndl = NULL;

    // Find the number of nodes on this machine
    TARGETING::PredicateCTM l_nodeFilter(CLASS_ENC, TYPE_NODE);
    TARGETING::PredicateHwas l_pred;
    l_pred.present(true);
    TARGETING::PredicatePostfixExpr l_presentNode;
    l_presentNode.push(&l_nodeFilter).push(&l_pred).And();

    TARGETING::TargetRangeFilter l_filter(
                        TARGETING::targetService().begin(),
                        TARGETING::targetService().end(),
                        &l_presentNode);
    for( ; l_filter ; ++l_filter )
    {
        iv_actNodeCnt++;
    }

    // Looping and building the children
    HdatNodedata *l_nodeDataObj, **l_arrayEntry;
    const char HDAT_KID_STRUCT_NAME[] = "HS KID";
    uint32_t l_NodeStructSize = 0;

    if(iv_actNodeCnt > 0)
    {
        iv_NodePtrs = reinterpret_cast<HdatNodedata **>(calloc(iv_actNodeCnt, 
                                       sizeof(HdatNodedata *)));
    }
    else
    {
        HDAT_ERR("hdatHostsr : Hdat node data failed");
    }
    
    iv_msAddr += iv_size;   // Leave a space for parent before creating children

    for(uint32_t l_nodeID = 0 ; l_nodeID < iv_actNodeCnt ; l_nodeID++)
    {
        l_NodeStructSize = 0;
        l_nodeDataObj = new HdatNodedata(l_errlHndl ,iv_msAddr,
                        HDAT_KID_STRUCT_NAME,l_NodeStructSize);

        // Sum up the sizes for all the node data
        o_NodeDataSize+= l_NodeStructSize;

        l_arrayEntry = reinterpret_cast<HdatNodedata **>(
                       reinterpret_cast<char *>(iv_NodePtrs) + 
                       l_nodeID * sizeof(HdatNodedata *));

        *l_arrayEntry = l_nodeDataObj;
 
        // Tell the base class about child structures and adjust size
        if (NULL == l_errlHndl)
        {
            // 1st parm is 0 based
            this->addChild(HDAT_CHILD_NODE_ATTRIBUTE, l_NodeStructSize, 0);
        }
    }   

    HDAT_DBG("HdatHostSr::bldNodeDataStruct Done. Commit pending.");

    HDAT_EXIT();
    return l_errlHndl;
}

/** @brief See the prologue in hdathostservices.H
 */

errlHndl_t HdatHostsr::setChildPtrs()
{
    HDAT_ENTER();
    uint32_t l_cnt;
    errlHndl_t l_errlHndl = NULL;
    HdatNodedata *l_nodeDataObj, **l_curPtr;

    l_curPtr = iv_NodePtrs;

    for (l_cnt = 0; l_cnt < iv_actNodeCnt; l_cnt++)
    {   
        l_nodeDataObj = *l_curPtr;
        l_errlHndl = l_nodeDataObj->setNodeData();
        if(l_errlHndl)
        {
            HDAT_ERR(" Setting Node data failed");
            break;
        }
    }

    HDAT_EXIT();
    return l_errlHndl;

}



}// HDAT namespace
