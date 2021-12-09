/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatspiraS.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
 * @file hdatspiraS.C
 *
 *  @brief
 *    This file contains the definition of the Service Processor Interface
 *    Root Array Secure boot (SPIRA-S) data structure.  This data structure
 *    is built  by FSP and placed at the beginning of the host data areas
 *    space located using the SPIRA-H. Data areas pointed to by this portion
 *    of the SPIRA will be located after it in the host data areas space.
 *
 */


/*---------------------------------------------------------------------------*/
/* Includes                                                                  */
/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include "hdatspiraS.H"
#include "hdatutil.H"
#include <hdat/hdat_reasoncodes.H>
#include <sys/mm.h>
#include <sys/mmio.h>
#include "hdatpcia.H"
#include "hdatpcrd.H"
#include "hdathostslcadata.H"
#include "hdatiplparms.H"
#include "hdatspsubsys.H"
#include "hdatmsvpd.H"
#include "hdathostservices.H"
#include "hdatbldda.H"
#include "hdatiohub.H"
#include "hdathbrt.H"
#include "hdattpmdata.H"
#include <util/align.H>
#include <targeting/common/commontargeting.H>



namespace HDAT
{
/*---------------------------------------------------------------------------*/
/* Global variables                                                          */
/*---------------------------------------------------------------------------*/
extern trace_desc_t *g_trac_hdat;
extern errlHndl_t hdatLoadIoData(const hdatMsAddr_t &i_msAddr,
                                 uint32_t &o_size,
                                 uint32_t &o_count);


/*****************************************************************************/
// HdatSpiraS constructor
/*****************************************************************************/


HdatSpiraS::HdatSpiraS(const hdat5Tuple_t& i_spirasHostEntry)
    : iv_spirasSize(0), iv_spiras(NULL)
{
    HDAT_ENTER();


    iv_spirasSize =
        i_spirasHostEntry.hdatAllocSize * i_spirasHostEntry.hdatAllocCnt;


    uint64_t l_base_addr =
        ((uint64_t) i_spirasHostEntry.hdatAbsAddr.hi << 32) |
          i_spirasHostEntry.hdatAbsAddr.lo;

    HDAT_DBG("l_base_addr at SPIRA-S=0x%016llX",l_base_addr);


    //calculate the hrmor and add to base address
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );

    assert(sys != NULL);

    uint64_t l_hrmor =
                   sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>()*MEGABYTE;

    HDAT_DBG("HRMOR=0x%08x",l_hrmor);

    l_base_addr = l_hrmor + l_base_addr;

    HDAT_DBG("base address after adding HRMOR=0x%08x",l_base_addr);

    uint64_t l_base_addr_down = ALIGN_PAGE_DOWN(l_base_addr);
    HDAT_DBG("l_base_addr_down=0x%016llX",l_base_addr_down);

    HDAT_DBG("reqd space=0x%x, will do a block map of size 0x%x",
             iv_spirasSize, ALIGN_PAGE(iv_spirasSize));


    void *l_virt_addr = mm_block_map( reinterpret_cast<void*>(l_base_addr_down),
                        ALIGN_PAGE(iv_spirasSize) + PAGESIZE);

    HDAT_DBG("l_virt_addr=0x%016llX after block map",l_virt_addr);

    uint64_t l_vaddr = reinterpret_cast<uint64_t>(l_virt_addr);

    HDAT_DBG("will add offset %x to starting virtual address",
             (l_base_addr-l_base_addr_down));

    l_vaddr += l_base_addr-l_base_addr_down;

    HDAT_DBG("l_vaddr after adding=0x%016llX",l_vaddr);

    l_virt_addr = reinterpret_cast<void *>(l_vaddr);
    HDAT_DBG("l_virt_addr=0x%016llX",l_virt_addr);

    iv_spiras = reinterpret_cast<hdatSpiraS_t *>(l_virt_addr);

    HDAT_DBG("constructor iv_spiras addr 0x%016llX virtual addr 0x%016llX,space"
             " allocated=0x%x",(uint64_t) this->iv_spiras,
             (uint64_t)l_virt_addr,iv_spirasSize);

    // Clear HDAT area used by OPAL inorder to support memory encryption changes
    if (sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>() ==
        TARGETING::PAYLOAD_KIND_SAPPHIRE)
    {
        HDAT_DBG("i_spirasHostEntry.hdatAllocSize=%d,"
            "i_spirasHostEntry.hdatAllocSize=%d",
            i_spirasHostEntry.hdatAllocSize, i_spirasHostEntry.hdatAllocCnt);

        memset(l_virt_addr, 0x00,
            i_spirasHostEntry.hdatAllocSize * i_spirasHostEntry.hdatAllocCnt);

        HDAT_DBG("i_spirasHostEntry.hdatAllocSize=%d,"
            "i_spirasHostEntry.hdatAllocSize=%d",
            i_spirasHostEntry.hdatAllocSize, i_spirasHostEntry.hdatAllocCnt);
    }

    HDAT_DBG("creating SPIRA-S header");
    setSpiraSHdrs();

    HDAT_DBG("done setting the SPIRA-S header");


    iv_spiras->hdatHDIF.hdatSize   = sizeof(hdatSpira_t);

    HDAT_EXIT();

    return;
}

/*****************************************************************************/
// setSpiraSHdrs
/*****************************************************************************/
void HdatSpiraS::setSpiraSHdrs()
{
    HDAT_ENTER()


    iv_spiras->hdatHDIF.hdatStructId       = HDAT_HDIF_STRUCT_ID;
    iv_spiras->hdatHDIF.hdatInstance       = 0;
    iv_spiras->hdatHDIF.hdatVersion       = HDAT_SPIRAS_VERSION;
    iv_spiras->hdatArrayInfo.hdatArrayCnt  = HDAT_SPIRAS_DA_LAST;
    iv_spiras->hdatHDIF.hdatSize           = sizeof(hdatSpiraS_t);

    iv_spiras->hdatHDIF.hdatHdrSize        = sizeof(hdatHDIF_t);
    iv_spiras->hdatHDIF.hdatDataPtrOffset  = sizeof(hdatHDIF_t);
    iv_spiras->hdatHDIF.hdatDataPtrCnt     = 1;
    iv_spiras->hdatHDIF.hdatChildStrCnt    = 0;
    iv_spiras->hdatHDIF.hdatChildStrOffset = 0;

    memcpy(iv_spiras->hdatHDIF.hdatStructName, HDAT_SPIRAS_EYE_CATCHER,
           sizeof(iv_spiras->hdatHDIF.hdatStructName));

    iv_spiras->hdatDataHdr.hdatOffset      =
                           offsetof(hdatSpiraS_t, hdatArrayInfo);

    iv_spiras->hdatDataHdr.hdatSize        =
                           (sizeof(hdatHDIFDataArray_t)
                           + sizeof(iv_spiras->hdatDataArea));

    iv_spiras->hdatArrayInfo.hdatOffset    =
                           sizeof(hdatHDIFDataArray_t);

    iv_spiras->hdatArrayInfo.hdatAllocSize =
                            sizeof(hdat5Tuple_t);

    iv_spiras->hdatArrayInfo.hdatActSize   =
                           offsetof(hdat5Tuple_t, hdatReserved1);


    HDAT_EXIT();
    return;
}


/******************************************************************************/
// ~HdatSpiraS
/******************************************************************************/

HdatSpiraS::~HdatSpiraS()
{
    HDAT_ENTER();

    int rc = 0;
    rc = mm_block_unmap(iv_spiras);

    if ( rc != 0 )
    {
        HDAT_ERR("unmap of spiras failed");
        errlHndl_t l_errl = NULL;
        hdatMsAddr_t l_tmpaddr = {0};

        if ( iv_spiras )
        {
            memcpy(&l_tmpaddr,(void*)iv_spiras,sizeof(hdatMsAddr_t));
        }

        /*@
         * @errortype
         * @moduleid         HDAT::MOD_SPIRAS_DESTRUCTOR
         * @reasoncode       HDAT::RC_DEV_MAP_FAIL
         * @devdesc          Unmap a mapped region failed
         * @custdesc         Firmware encountered an internal error
         */
        hdatBldErrLog(l_errl,
                  MOD_SPIRAS_DESTRUCTOR,
                  RC_DEV_MAP_FAIL,
                  l_tmpaddr.hi,l_tmpaddr.lo,0,0,
                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                  HDAT_VERSION1,
                  true);

    }

    HDAT_EXIT();
    return;
}


/***********************************************************************/
// getStructAddr
/***********************************************************************/

const hdatSpiraS_t *HdatSpiraS::getStructAddr()
{
  return iv_spiras;
}


/***********************************************************************/
// loadDataArea
/***********************************************************************/

errlHndl_t HdatSpiraS::loadDataArea( const hdat5Tuple_t& i_spirasHostEntry,
                                     uint32_t& o_actCount, uint32_t& o_actSize)
{
    HDAT_ENTER();
    errlHndl_t l_err = NULL;
    hdatMsAddr_t l_msAddr,l_addrToPass,i_slcaMsAddr = SLCA_BUILD_ADDR;
    hdat5Tuple_t l_spirasEntry;
    uint32_t l_hostUsed = 0;
    uint32_t l_size,l_count,l_hdatslcaSize,l_hdatSlcaCnt;
    uint64_t l_binAddr;
    o_actCount = 1;
    o_actSize = 0;

    do {

    //calculate HRMOR
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );

    assert(sys != NULL);

    uint64_t l_hrmor =
             sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>()*MEGABYTE;

    HDAT_DBG("HRMOR=0x%08x",l_hrmor);


    HDAT_DBG("building SLCA");
    l_binAddr = ((uint64_t)i_slcaMsAddr.hi << 32)
                      |
                i_slcaMsAddr.lo;

    l_binAddr += l_hrmor;
    memcpy(&i_slcaMsAddr, &l_binAddr, sizeof(l_binAddr));

    HDAT_DBG("building SLCA at i_slcaMsAddr.hi=%x,i_slcaMsAddr.lo=%x",
             i_slcaMsAddr.hi,i_slcaMsAddr.lo);

    l_err = hdatBuildSLCA(i_slcaMsAddr,l_hdatSlcaCnt,l_hdatslcaSize);

    if ( l_err )
    {
        HDAT_ERR("failed to build SLCA");
        break;
    }

    HDAT_DBG("built SLCA, size=0x%x",l_hdatslcaSize);

    l_hostUsed =  i_spirasHostEntry.hdatActualSize + (sizeof(hdatSpiraS_t));

    HDAT_DBG("size of hdatSpiraS_t:  0x%08X, hdatActualSize: 0x%08X",
              (sizeof(hdatSpiraS_t)),i_spirasHostEntry.hdatActualSize);


    for ( hdatSpiraSDataAreas l_entryToPrint=HDAT_SPIRAS_DA_FIRST;
         (l_entryToPrint < HDAT_SPIRAS_DA_LAST);
          l_entryToPrint=(hdatSpiraSDataAreas)((uint32_t)l_entryToPrint +1) )
    {
        HDAT_DBG("for loop index=%d",l_entryToPrint);
        l_count = 0;
        l_size = 0;

        l_binAddr = 0x0;
        l_binAddr = ((uint64_t)i_spirasHostEntry.hdatAbsAddr.hi << 32)
                          |
                     i_spirasHostEntry.hdatAbsAddr.lo;


        l_binAddr += (uint64_t)l_hostUsed;

        memcpy(&l_msAddr, &l_binAddr, sizeof(l_binAddr));

        HDAT_DBG("next spiras tuple will be l_msAddr.hi=0x%8x,"
                 "l_msAddr.lo=0x%8x",l_msAddr.hi,l_msAddr.lo);


        l_binAddr += l_hrmor;

        memcpy(&l_addrToPass, &l_binAddr, sizeof(l_binAddr));

        HDAT_DBG("address to pass to next data area after adding hrmor"
                 " l_addrToPass.hi"
                "=0x%8x,l_addrToPass.lo=0x%8x",l_addrToPass.hi,l_addrToPass.lo);

        switch ( l_entryToPrint )
        {
            case HDAT_SPIRAS_SP_SUBSYS:
            {
                HDAT_DBG("calling SP SUBSYS from spiras");
                l_err = HdatLoadSpSubSys(l_addrToPass,
                             l_size,l_count);
                HDAT_DBG("returned from SP SUBSYS, count=%d"
                          "size=0x%x",l_count,l_size);
            }
                 break;
            case HDAT_SPIRAS_IPL_PARMS:
            {
                HDAT_DBG("calling IPL PARMS from spiras");
                HdatIplParms l_iplParms(l_err,l_addrToPass);

                if ( NULL == l_err)
                {
                    l_err = l_iplParms.hdatLoadIplParams(l_size,l_count);

                    if ( NULL == l_err )
                    {
                        HDAT_DBG("returned from IPL PARMS, size=0x%x,count=%d",
                                l_size,l_count);
                    }
                    else
                    {
                        HDAT_DBG("could not load IPL PARMS");
                    }
                }
                else
                {
                    HDAT_DBG("could not create IPL PARMS object");
                }
            }
                 break;
            case HDAT_SPIRAS_ENCLOSURE_VPD:
            {
                HDAT_DBG("calling ENCLOSURE VPD from spiras");
                l_err = hdatBldSpecificVpd(HDAT_ENCLOSURE_VPD,l_addrToPass,
                                           l_count,l_size);
                if ( l_err )
                {
                    HDAT_ERR("could not build ENCLOSURE VPD");
                }
                else
                {
                    HDAT_DBG("returned from ENCLOSURE VPD count=%d, size=0x%x",
                           l_count,l_size);
                }
            }
                 break;
            case HDAT_SPIRAS_SLCA:
            {
                HDAT_DBG("calling SLCA from spiras ");
                l_count = l_hdatSlcaCnt;
                l_size = l_hdatslcaSize;
                hdatMoveSLCA(i_slcaMsAddr,
                l_addrToPass,l_hdatslcaSize);
                HDAT_DBG("moved SLCA count=%d, size=0x%x",l_count,l_size);
            }
                 break;
            case HDAT_SPIRAS_BACKPLANE_VPD:
            {
                HDAT_DBG("calling BACKPLANE VPD from spiras");
                l_err = hdatBldSpecificVpd( HDAT_BACKPLANE_VPD, l_addrToPass,
                                           l_count,l_size);
                if ( l_err )
                {
                    HDAT_ERR("could not build BACKPLANE VPD");
                }
                else
                {
                    HDAT_DBG("returned from BACKPLANE  VPD count=%d, size=0x%x",
                          l_count,l_size);
                }
            }
                 break;
            case HDAT_SPIRAS_SYS_VPD:
            {
                HDAT_DBG("calling SYS VPD from spiras");
                l_err = hdatBldSpecificVpd( HDAT_SYS_VPD,l_addrToPass,l_count,
                                           l_size);
                if ( l_err )
                {
                    HDAT_ERR("could not build  SYS VPD");
                }
                else
                {
                    HDAT_DBG("returned from SYS VPD count=%d, size=0x%x",
                          l_count,l_size);
                }
            }
                 break;
            case HDAT_SPIRAS_CLOCK_VPD:
            {
                HDAT_DBG("calling CLOCK VPD from spiras");
                l_err = hdatBldSpecificVpd( HDAT_CLOCK_VPD,l_addrToPass,l_count,
                                            l_size);
                if ( l_err )
                {
                    HDAT_ERR("could not build CLOCK VPD");
                }
                else
                {
                    HDAT_DBG("returned from CLOCK VPD count=%d, size=0x%x",
                          l_count,l_size);
                }
            }
                 break;
            case HDAT_SPIRAS_ANCHOR_VPD:
            {
                HDAT_DBG("calling ANCHOR VPD from spiras");
                l_err = hdatBldSpecificVpd(HDAT_ANCHOR_VPD,l_addrToPass,l_count,
                                    l_size);
                if ( l_err )
                {
                    HDAT_ERR("could not build ANCHOR VPD");
                }
                else
                {
                    HDAT_DBG("returned from ANCHOR VPD count=%d, size=0x%x",
                         l_count,l_size);
                }
            }
                 break;
            case HDAT_SPIRAS_OP_PNL_VPD:
            {
                HDAT_DBG("calling OP PANL VPD from spiras");
                l_err = hdatBldSpecificVpd(HDAT_OP_PNL_VPD,l_addrToPass,l_count,
                                    l_size);
                if( l_err )
                {
                    HDAT_ERR("could not build OP PANL VPD");
                }
                else
                {
                    HDAT_DBG("returned from OP PANL VPD count=%d, size=0x%x",
                          l_count,l_size);
                }
            }
                 break;
            case HDAT_SPIRAS_MISC_CEC_VPD:
            {
                HDAT_DBG("calling MISC CEC VPD from spiras");
                l_err = hdatBldSpecificVpd( HDAT_MISC_CEC_VPD,l_addrToPass,
                                            l_count,l_size);
                if ( l_err )
                {
                    HDAT_ERR("could not build MISC CEC VPD");
                }
                else
                {
                    HDAT_DBG("returned from MISC CEC VPD count=%d, size=0x%x",
                          l_count,l_size);
                }
            }
                 break;
            case HDAT_SPIRAS_MSVPD:
            {
                HDAT_DBG("calling MS VPD from spiras");
                HdatMsVpd l_msvpd(l_err,l_addrToPass);
                if ( l_err == NULL )
                {
                    l_err = l_msvpd.hdatLoadMsData(l_size,l_count);
                    HDAT_DBG("MS VPD count=%d, size=0x%x",l_count,l_size);
                }
                else
                {
                    HDAT_DBG("could not create MS VPD object");
                }
            }
                 break;
            case HDAT_SPIRAS_IO_HUB:
            {
                HDAT_DBG("calling IO HUB from spiras");
                l_err = hdatLoadIoData(l_addrToPass,l_size,l_count);
                HDAT_DBG("returned from IO HUB size=0x%x,count=%d from iohub",
                l_size,l_count);
            }
                 break;
            case HDAT_SPIRAS_PCIA:
            {
                HDAT_DBG("calling PCIA from spiras");
                HdatPcia pcia(l_err,l_addrToPass);
                if ( NULL == l_err )
                {
                    l_err = pcia.hdatLoadPcia(l_size,l_count);
                    HDAT_DBG("returned from PCIA count=%d,size=0x%x",
                             l_count,l_size);
                }
                else
                {
                    HDAT_DBG("could not create PCIA object");
                }
            }
                 break;
            case HDAT_SPIRAS_PCRD:
            {
                HDAT_DBG("calling PCRD from spiras");
                HdatPcrd l_pcrd(l_err,l_addrToPass);

                if ( NULL == l_err )
                {
                    l_err = l_pcrd.hdatLoadPcrd(l_size,l_count);
                    HDAT_DBG("PCRD count=%d,size=%x",l_count,l_size);
                }
                else
                {
                    HDAT_ERR("could not create PCRD object");
                }
            }
                 break;
            case HDAT_SPIRAS_HOSTSR:
            {
                HDAT_DBG("HOSTSR from spiras");
                HdatHostsr l_hdatHostSr(l_err,l_addrToPass,l_size,l_count);
                HDAT_DBG("HOSTSR count=%d,size=%x",l_count,l_size);
            }
                 break;

            case HDAT_SPIRAS_HBRT:
            {
                HDAT_DBG("HBRT from spiras");
                l_err = loadHbrt(l_addrToPass,l_size,l_count);

                if ( l_err )
                {
                    HDAT_ERR("loading HBRT failed");
                }
                else
                {
                    HDAT_DBG("HBRT count=%d,size=0x%x",l_count,l_size);
                }
            }
            break;
            case HDAT_SPIRAS_IPMI:
            {
                HDAT_DBG("not creating IPMI data")
            }
            break;
            case HDAT_SPIRAS_TPM_RELATED:
            {
                HDAT_DBG("calling TPM DATA from spiras");
                HdatTpmData l_tpmData(l_err, l_addrToPass);

                if ( nullptr == l_err)
                {
                    l_err = l_tpmData.hdatLoadTpmData(l_size, l_count);

                    if ( nullptr == l_err )
                    {
                        HDAT_DBG("returned from TPM DATA, size=0x%x,count=%d",
                                l_size, l_count);
                    }
                    else
                    {
                        HDAT_ERR("could not load TPM DATA");
                    }
                }
                else
                {
                    HDAT_ERR("could not create TPM DATA object");
                }
            }
            break;
            default:
            {
                HDAT_ERR("not a valid data area");
            }
            break;

        }
        if (l_err)
        {
            HDAT_ERR("error in creating data area %d",l_entryToPrint);
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_SPIRAS_CREATE_DATA_AREA
             * @reasoncode       HDAT::RC_DATA_AREA_FAIL
             * @devdesc          could not create the data area from spiras
             * @custdesc         Firmware encountered an internal error
             */
            hdatBldErrLog (l_err,
                      MOD_SPIRAS_CREATE_DATA_AREA,
                      RC_DATA_AREA_FAIL,
                      l_entryToPrint,0,0,0);

            break;
        }
        if ( l_count && l_size )
        {
            memset(&l_spirasEntry, 0, sizeof(hdat5Tuple_t));
            l_spirasEntry.hdatAbsAddr.hi = l_msAddr.hi;
            l_spirasEntry.hdatAbsAddr.lo = l_msAddr.lo;

            l_spirasEntry.hdatAllocCnt   = l_count;
            l_spirasEntry.hdatActualCnt  = l_count;

            uint32_t l_rem = l_size % HDAT_HDIF_ALIGN;
            uint32_t l_pad = l_rem ? (HDAT_HDIF_ALIGN - l_rem) : 0;

            l_spirasEntry.hdatAllocSize  = l_size + l_pad;
            l_spirasEntry.hdatActualSize = l_size;

            l_hostUsed += l_count * l_spirasEntry.hdatAllocSize;

            //copy the tuple to spira-s memory

            memcpy(&iv_spiras->hdatDataArea[l_entryToPrint],&l_spirasEntry,
                   sizeof(hdat5Tuple_t));

            HDAT_DBG("iv_spiras->hdatDataArea[%d].hdatActualCnt=%d,"
                     "hdatActualSize=%x",l_entryToPrint,
                     iv_spiras->hdatDataArea[l_entryToPrint].hdatActualCnt,
                     iv_spiras->hdatDataArea[l_entryToPrint].hdatActualSize);

        }
    }//end for

    }while(0);

    o_actSize = l_hostUsed;

    HDAT_EXIT();
    return l_err;

}//end loadDataArea


/****************************************************************/
//getSpirasObject
/****************************************************************/

void HdatSpiraS::getSpirasObject(uint8_t* &io_spiras,uint32_t& o_size,
                       const hdatMsAddr_t& i_msAddr)
{
    HDAT_ENTER();

    io_spiras = NULL;

    //user is responsible to free up the memory
    io_spiras = new uint8_t[iv_spirasSize];

    o_size = iv_spirasSize;

    memcpy(io_spiras, iv_spiras, iv_spirasSize);

    HDAT_EXIT();
}



/****************************************************************/
// getSpiraSEntry
/****************************************************************/

void HdatSpiraS::getSpiraSEntry(hdatSpiraSDataAreas i_dataArea,
                                hdat5Tuple_t &o_entry)
{
    HDAT_ENTER();

    o_entry.hdatAbsAddr.hi = iv_spiras->hdatDataArea[i_dataArea].hdatAbsAddr.hi;
    o_entry.hdatAbsAddr.lo = iv_spiras->hdatDataArea[i_dataArea].hdatAbsAddr.lo;
    o_entry.hdatAllocCnt = iv_spiras->hdatDataArea[i_dataArea].hdatAllocCnt;
    o_entry.hdatActualCnt = iv_spiras->hdatDataArea[i_dataArea].hdatActualCnt;
    o_entry.hdatAllocSize = iv_spiras->hdatDataArea[i_dataArea].hdatAllocSize;
    o_entry.hdatActualSize = iv_spiras->hdatDataArea[i_dataArea].hdatActualSize;
    o_entry.hdatTceOffset = iv_spiras->hdatDataArea[i_dataArea].hdatTceOffset;

    HDAT_DBG("returning tuple o_entry.hdatAbsAddr.hi : 0x%08X,"
             " o_entry.hdatAbsAddr.lo : 0x%08X",
              o_entry.hdatAbsAddr.hi,o_entry.hdatAbsAddr.lo);

    HDAT_DBG("o_entry.hdatAllocCnt : 0x%08X, o_entry.hdatActualCnt: 0x%08X ",
              o_entry.hdatAllocCnt,o_entry.hdatActualCnt);

    HDAT_DBG("o_entry.hdatAllocSize : 0x%08X, o_entry.hdatActualSize: 0x%08X",
              o_entry.hdatAllocSize,o_entry.hdatActualSize);

    HDAT_EXIT();
}

}//end namespace
