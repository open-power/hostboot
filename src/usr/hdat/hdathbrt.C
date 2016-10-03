/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdathbrt.C $                                     */
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
#include <hdat/hdat.H>
#include "hdathbrt.H"
#include <targeting/common/util.H>
#include <sys/mm.h>
#include <sys/mmio.h>
#include <util/align.H>

using namespace TARGETING;


namespace HDAT
{


    errlHndl_t loadHbrt(const hdatMsAddr_t &i_msAddr,
                uint32_t &o_size , uint32_t &o_count)
    {
        HDAT_ENTER();
        errlHndl_t l_err = NULL;
        HdatHbrt *l_hbrt = NULL;


        //fetch the target attributes
        do {
            TARGETING::Target *l_pSysTarget = NULL;
            (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

            if ( NULL == l_pSysTarget )
            {
                HDAT_ERR("Error in getting Top Level Target");
                assert (l_pSysTarget != NULL);
            }
            TARGETING::ATTR_HDAT_HBRT_NUM_SECTIONS_type
                       l_numHbRuntimeDataSections =
                l_pSysTarget->getAttr<TARGETING::ATTR_HDAT_HBRT_NUM_SECTIONS>();

            TARGETING::ATTR_HDAT_HBRT_SECTION_SIZE_type
                   l_sizeHbRuntimeDataSections= {};

            if(l_pSysTarget->tryGetAttr<TARGETING::ATTR_HDAT_HBRT_SECTION_SIZE>(
                l_sizeHbRuntimeDataSections) == false )
            {
                HDAT_ERR ("tryGetAttr of ATTR_HDAT_HBRT_SECTION_SIZE returned"
                           "false");

                /*@
                 * @errortype
                 * @moduleid         HDAT::MOD_HBRT_LOAD_DATA
                 * @reasoncode       HDAT::RC_TGT_ATTR_NOTFOUND
                 * @devdesc          The target attribute not found
                 * @custdesc         Firmware encountered an internal error
                 */
                hdatBldErrLog(l_err,
                              MOD_HBRT_LOAD_DATA,
                              RC_TGT_ATTR_NOTFOUND,
                              0,0,0,0);
                break;
            }


            l_hbrt = new HdatHbrt(l_err,i_msAddr,
                         (uint32_t)l_numHbRuntimeDataSections,
                          l_sizeHbRuntimeDataSections);


            o_size = l_hbrt->size();
            o_count = HBRT_INSTANCE + 1;


            l_err = l_hbrt->setHbrt(l_sizeHbRuntimeDataSections,o_size);

            HDAT_DBG("done building hbrt data, size = 0x%x, count= 0x%x",
                      o_size,o_count);


        }while(0);


        if ( l_hbrt )
        {
            delete l_hbrt;
        }

        HDAT_EXIT();
        return l_err;
    }//end loadHbrt


HdatHbrt::HdatHbrt(errlHndl_t &o_errlHndl,const hdatMsAddr_t &i_msAddr,
                 const uint32_t i_numHbrtSections,uint64_t i_sizeHbrtSections[])
:HdatHdif(o_errlHndl,HDAT_HBRT_STRUCT_NAME, i_numHbrtSections,
          HBRT_INSTANCE, HDAT_HBRT_CHILD_COUNT, HDAT_HBRT_VERSION)
{
    HDAT_ENTER();

    memcpy(&iv_msAddr, &i_msAddr, sizeof(hdatMsAddr_t));
    iv_numHbrtSections = i_numHbrtSections;

    for ( uint32_t l_loopCnt = 0; l_loopCnt < iv_numHbrtSections; l_loopCnt++ )
    {
        this->addData(l_loopCnt,
               (sizeof(hdatHbrtData_t) + i_sizeHbrtSections[l_loopCnt]));
    }
    this->align();

    HDAT_EXIT();
}//end constructor


HdatHbrt::~HdatHbrt()
{
    //free heap storage if any
}


errlHndl_t HdatHbrt::setHbrt( uint64_t i_sizeHbrtSections[],uint32_t i_size)
{
    errlHndl_t l_err = NULL;
    hdatHbrtData_t *l_hdatHbrtData_t = NULL;
    HDAT_ENTER();


    //first do block map
    //total size reqd is size of hdif + (size of hbrt * number of hbrt sections)
    uint64_t i_base_addr = ((uint64_t) iv_msAddr.hi << 32) | iv_msAddr.lo;
    uint64_t i_base_addr_down = ALIGN_PAGE_DOWN(i_base_addr);



    void *l_virt_addr = mm_block_map (
                        reinterpret_cast<void*>(i_base_addr_down),
                        ALIGN_PAGE(i_size) + PAGESIZE);


    uint64_t l_vaddr = reinterpret_cast<uint64_t>(l_virt_addr);
    l_vaddr += i_base_addr-i_base_addr_down;

    l_virt_addr = reinterpret_cast<void *>(l_vaddr);

    memset(l_virt_addr ,0x0, i_size);
    uint8_t* io_virt_addr = reinterpret_cast<uint8_t *>(l_virt_addr);

    uint8_t* l_startAddr = io_virt_addr;
    HDAT_DBG("io_virt_addr=0x%016llX, l_virt_addr=0x%016llX",
              (uint64_t)io_virt_addr,(uint64_t)l_virt_addr);

    io_virt_addr = this->setHdif(io_virt_addr);

    HDAT_DBG("after writing HDIF header address now 0x%016llX",
              (uint64_t)io_virt_addr);

    //now write the hbrt struct iv_numHbrtSections times

    uint32_t l_commonOffset = sizeof(hdatHDIF_t) +
                              (iv_numHbrtSections * sizeof(hdatHDIFDataHdr_t))+
                              sizeof(hdatHbrtData_t);

    HDAT_DBG("common offset added to each is 0x%x",l_commonOffset);

    for (uint32_t i =0; i< iv_numHbrtSections; i++)
    {
        l_hdatHbrtData_t = reinterpret_cast<hdatHbrtData_t *>
                                           (io_virt_addr);
        l_hdatHbrtData_t->hdatHbrtBlobData.hdatSize =
                          i_sizeHbrtSections[i];

        l_hdatHbrtData_t->hdatHbrtBlobData.hdatOffset = l_commonOffset;

        HDAT_DBG("hdatSize=0x%x, offset=0x%x",i_sizeHbrtSections[i],
                   l_hdatHbrtData_t->hdatHbrtBlobData.hdatOffset);

        l_commonOffset += i_sizeHbrtSections[i] + sizeof(hdatHbrtData_t);

        HDAT_DBG("next offset is 0x%x+0x%x=0x%x more",i_sizeHbrtSections[i],
         sizeof(hdatHbrtData_t),(i_sizeHbrtSections[i]+sizeof(hdatHbrtData_t)));


        io_virt_addr = reinterpret_cast<uint8_t *>(l_hdatHbrtData_t);

        io_virt_addr += sizeof(hdatHbrtData_t) + i_sizeHbrtSections[i];

    }//end for


    //add the pad after writing all the hbrt objects
    uint32_t l_rem = i_size % 128;
    uint32_t l_pad = l_rem ? (128 - l_rem) : 0;

    for (uint32_t i=0; i < l_pad; i++)
    {
        io_virt_addr[i] = '\0';
    }
    HDAT_DBG("wrote pad of 0x%x size after hbrt object",l_pad);

    //unmap the region
    int rc = 0;

    rc =  mm_block_unmap(reinterpret_cast<void*>(ALIGN_PAGE_DOWN(
    reinterpret_cast<uint64_t>(l_startAddr))));

    if ( rc != 0 )
    {
        HDAT_ERR("unmap of hbrt region failed");
        hdatMsAddr_t l_tmpaddr = {0};

        if ( l_startAddr )
        {
            memcpy(&l_tmpaddr,(void*)l_startAddr,sizeof(hdatMsAddr_t));
        }
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_HBRT_LOAD_DATA
         * @reasoncode       HDAT::RC_DEV_MAP_FAIL
         * @devdesc          Unmap a mapped region failed
         * @custdesc         Firmware encountered an internal error
         */
        hdatBldErrLog(l_err,
                      MOD_HBRT_LOAD_DATA,
                      RC_DEV_MAP_FAIL,
                      l_tmpaddr.hi,l_tmpaddr.lo,0,0,
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                      HDAT_VERSION1,
                      true);

    }


    HDAT_EXIT();
    return l_err;
}//end setHbrt

}//end namespace
