/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatnodedata.C $                                 */
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
 * @file hdatnodedata.C
 *
 * @brief This file contains the implementation of the HdatNodedata class.
 *    
 */

/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/

#include <stdlib.h>                 // malloc & free
#include <sys/mm.h>
#include <sys/mmio.h>
#include <util/align.H>
#include "hdatnodedata.H"           // HdatNodedata class definition
#include "hdathdif.H"
#include "hdatutil.H"
#include "hdatvpd.H"
#include <targeting/common/util.H>

using namespace HDAT;
namespace HDAT
{
/*-----------------------------------------------------------------------------*/
/* Global variables                                                            */
/*-----------------------------------------------------------------------------*/
extern trace_desc_t *g_trac_hdat;
uint32_t HdatNodedata::cv_actualCnt;

/** @brief See the prologue in hdatnodedata.H
 */
HdatNodedata::HdatNodedata(errlHndl_t &o_errlHndl,
                 uint64_t &io_msAddr,
                 const char *i_eyeCatcher,
                 uint32_t &o_NodeStructSize)
: HdatHdif(o_errlHndl, i_eyeCatcher, HDAT_NODE_DATA_LAST, 
cv_actualCnt++, HDAT_NO_CHILD, HDAT_NODE_DATA_VERSION)
{
    HDAT_ENTER();
    o_errlHndl = NULL;

    // Copy the mainstore address to object variable
    iv_msAddr  = io_msAddr;

    // Total size of Node Data
    iv_size  = sizeof(hdatHDIF_t) +
                     ( sizeof(hdatHDIFDataHdr_t) *
                       HDAT_NODE_DATA_LAST)+
                       HDAT_NODE_ATTR_DATA_SIZE + 0x08; // padding as per spec

    // Create a virtual address mapping
    uint64_t l_base_addr_down = ALIGN_PAGE_DOWN((uint64_t)iv_msAddr);
    iv_virt_addr =(uint8_t *) mm_block_map (
                            reinterpret_cast<void*>(l_base_addr_down),
                            (ALIGN_PAGE(iv_size) + PAGESIZE));
    iv_hdatNodeData = iv_virt_addr +
            ((uint64_t)iv_msAddr - ALIGN_PAGE_DOWN((uint64_t)iv_msAddr));

    o_NodeStructSize = iv_size;

    // Copy the end adress back to input pointer for next node use
    io_msAddr += iv_size;

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in HdatNodedata.H
 */
errlHndl_t HdatNodedata::setNodeData()
{
    HDAT_ENTER();
    errlHndl_t o_errlHndl=NULL;

    // Add the internal pointer Data
    this->addData(HDAT_NODE_ATTRIBUTE, HDAT_NODE_ATTR_DATA_SIZE);
    this->align();

    // initializing the space to zero
    memset(iv_hdatNodeData ,0x0, iv_size );

    iv_hdatNodeData = this->setHdif(iv_hdatNodeData);

    iv_hdatNodeData += HDAT_NODE_ATTR_DATA_SIZE;

    HDAT_EXIT();
    return o_errlHndl;
}

HdatNodedata::~HdatNodedata()
{
    HDAT_ENTER();

    errlHndl_t o_errlHndl=NULL;
    uint32_t rc =  mm_block_unmap(reinterpret_cast<void*>(
                    ALIGN_PAGE_DOWN((uint64_t)iv_virt_addr)));
    if( rc != 0)
    {
        /*@
        * @errortype
        * @moduleid         HDAT::MOD_HDAT_NODEDATA_DTOR
        * @reasoncode       HDAT::RC_DEV_MAP_FAIL
        * @devdesc          Unmap a mapped region failed
        * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(o_errlHndl,
                HDAT::MOD_HDAT_NODEDATA_DTOR,
                RC_DEV_MAP_FAIL,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }
    HDAT_EXIT();

}

}// HDAT namespace
