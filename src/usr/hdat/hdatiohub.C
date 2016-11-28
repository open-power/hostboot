/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatiohub.C $                                    */
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
#include <sys/mm.h>
#include <sys/mmio.h>
#include "hdathdif.H"
#include "hdatvpd.H"
#include "hdatiohub.H"
#include <targeting/common/util.H>
#include<sys/time.h>
#include <util/align.H>


using namespace TARGETING;

namespace HDAT
{

vpdData mvpdData[] =
{
    { PVPD::VINI, PVPD::DR },
    { PVPD::VINI, PVPD::CE },
    { PVPD::VINI, PVPD::VZ },
    { PVPD::VINI, PVPD::FN },
    { PVPD::VINI, PVPD::PN },
    { PVPD::VINI, PVPD::SN },
    { PVPD::VINI, PVPD::CC },
    { PVPD::VINI, PVPD::HE },
    { PVPD::VINI, PVPD::CT },
    { PVPD::VINI, PVPD::B3 },
    { PVPD::VINI, PVPD::B4 },
    { PVPD::VINI, PVPD::B7 },
    { PVPD::VINI, PVPD::PF },
    { PVPD::VINI, PVPD::LX },
};

const HdatKeywordInfo l_pvpdKeywords[] =
{

    { PVPD::DR,  "DR" },
    { PVPD::CE,  "CE" },
    { PVPD::VZ,  "VZ" },
    { PVPD::FN,  "FN" },
    { PVPD::PN,  "PN" },
    { PVPD::SN,  "SN" },
    { PVPD::CC,  "CC" },
    { PVPD::HE,  "HE" },
    { PVPD::CT,  "CT" },
    { PVPD::B3,  "B3" },
    { PVPD::B4,  "B4" },
    { PVPD::B7,  "B7" },
    { PVPD::PF,  "PF" },
    { PVPD::LX,  "LX" },
};

extern trace_desc_t *g_trac_hdat;

const uint32_t HDAT_MULTIPLE = 16;

//each PHB lane size
const uint32_t NUM_OF_LANES_PER_PHB = 
       sizeof(TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN3_type)/2;

static_assert( NUM_OF_LANES_PER_PHB == 
    sizeof(TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN3_type)/2,
      "no. of lanes per PHB should be 16");

/*******************************************************************************
 * IO HUB constructor
*******************************************************************************/

HdatIoHubFru::HdatIoHubFru(errlHndl_t &o_errlHndl,
                           uint32_t i_resourceId,
                           hdatCardType i_cardType,
                           uint32_t i_daughterCnt,
                           uint32_t i_index,
                           uint32_t i_slcaIdx)
:HdatHdif(o_errlHndl, "IO HUB", HDAT_PARENT_LAST,i_index,HDAT_CHILD_LAST,
          HDAT_IO_VERSION),
iv_hubStatus(0),iv_kwdSize(0),iv_maxHubs(HDAT_MAX_IO_CHIPS),
iv_maxDaughters(i_daughterCnt),iv_hubArraySize(0),iv_actDaughterCnt(0),
iv_maxDaughterSize(0),iv_kwd(NULL),iv_hubArray(NULL),iv_daughterPtrs(NULL)
{
    HDAT_ENTER();

    o_errlHndl = NULL;

    iv_hubId.hdatCardType      = i_cardType;
    iv_hubId.hdatReserved1     = 0;
    iv_hubId.hdatReserved2     = 0;
    iv_hubId.hdatReserved3     = 0;
    iv_hubId.hdatReserved4     = 0;
    iv_hubId.hdatReserved5     = 0;
    iv_hubId.hdatReserved6     = 0;

    iv_hubArrayHdr.hdatOffset     = sizeof(hdatHDIFDataArray_t);
    iv_hubArrayHdr.hdatArrayCnt   = 0;
    iv_hubArrayHdr.hdatAllocSize  = sizeof(hdatHubEntry_t);
    iv_hubArrayHdr.hdatActSize    = sizeof(hdatHubEntry_t);

    // Allocate space to build the I/O hub array
    iv_hubArraySize = iv_maxHubs * sizeof(hdatHubEntry_t);
    iv_hubArray = reinterpret_cast<hdatHubEntry_t *>(calloc(iv_maxHubs,
                                    sizeof(hdatHubEntry_t)));

    iv_fru.hdatResourceId = i_resourceId;


    if (NULL == o_errlHndl)
    {
        iv_fru.hdatSlcaIdx = i_slcaIdx;
        this->addData(HDAT_FRU_ID, sizeof(hdatFruId_t));
        this->addData(HDAT_ASCII_KWD, iv_kwdSize);
        this->addData(HDAT_HUB_ID, sizeof(hdatHubId_t));
        this->addData(HDAT_HUBS_ARRAY, iv_hubArraySize +
                      sizeof(iv_hubArrayHdr));
        this->align();
    }

    HDAT_EXIT();
}


/*******************************************************************************
 *  * IO HUB destructor
*******************************************************************************/
HdatIoHubFru::~HdatIoHubFru()
{
    uint32_t l_cnt;
    HdatVpd *l_vpdObj, **l_curPtr;
    HDAT_ENTER();

    // Destroy daughter card objects
    l_curPtr = iv_daughterPtrs;
    for (l_cnt = 0; l_cnt < iv_actDaughterCnt; l_cnt++)
    {
        l_vpdObj = *l_curPtr;
        delete l_vpdObj;
        l_curPtr = reinterpret_cast<HdatVpd **>(reinterpret_cast<char *>
                  (l_curPtr) + sizeof(HdatVpd *));
    }

    free(iv_hubArray);
    free(iv_daughterPtrs);

    HDAT_EXIT();

}



//******************************************************************************
// setIOHub
//******************************************************************************

//we enter the function each time with the starting address for the next
//object to write
uint8_t * HdatIoHubFru::setIOHub(uint8_t * io_virt_addr,
                                 uint32_t& o_size)
{
    HDAT_DBG("virtual address=0x%016llX",
              (uint64_t)io_virt_addr);

    uint8_t *l_temp = NULL, *l_ioMarker = NULL;
    HdatVpd *l_vpdObj;

    //saving the starting offset as we need to add child pointer array offset
    //to this location to start writing daughter cards which is often offset 820
    l_ioMarker = io_virt_addr;

    io_virt_addr = this->setHdif(io_virt_addr);

    HDAT_DBG("after writing HDIF header address now 0x%016llX",
             (uint64_t)io_virt_addr);


    //write FRU ID
    //cast to hdatFruId_t
    hdatFruId_t *l_hdatFruId = reinterpret_cast<hdatFruId_t *>(io_virt_addr);

    HDAT_DBG("writing FRU ID from address=0x%016llX",
             (uint64_t)l_hdatFruId);

    l_hdatFruId->hdatSlcaIdx = this->iv_fru.hdatSlcaIdx;
    l_hdatFruId->hdatResourceId = this->iv_fru.hdatResourceId;

    l_hdatFruId++; //increase by sizeof hdatFruId_t


    //write HUB FRU id
    //cast to hdatHubId_t *
    hdatHubId_t *l_hdatHubId = reinterpret_cast<hdatHubId_t *>(l_hdatFruId);

    HDAT_DBG("writing HUB FRU id from address=0x%016llX",
             (uint64_t)l_hdatHubId);

    l_hdatHubId->hdatCardType = this->iv_hubId.hdatCardType;

    l_hdatHubId++;//pass through reserved1..6 by incrementing the pointer


    //write Data array header of iohub array hdatHDIFDataArray_t  iv_hubArrayHdr
    hdatHDIFDataArray_t *l_hdatHDIFDataArray =
                          reinterpret_cast<hdatHDIFDataArray_t *>(l_hdatHubId);

    HDAT_DBG("writing io hub Data array header at address=0x%016llX",
              (uint64_t)l_hdatHDIFDataArray);

    l_hdatHDIFDataArray->hdatOffset    = this->iv_hubArrayHdr.hdatOffset;
    l_hdatHDIFDataArray->hdatArrayCnt  = this->iv_hubArrayHdr.hdatArrayCnt;
    l_hdatHDIFDataArray->hdatAllocSize = this->iv_hubArrayHdr.hdatAllocSize;
    l_hdatHDIFDataArray->hdatActSize   = this->iv_hubArrayHdr.hdatActSize;

    l_hdatHDIFDataArray++;//increase by sizeof hdatHDIFDataArray_t


    //write io hub array entries
    //number of entries are iv_hubArrayHdr.hdatArrayCnt

    hdatHubEntry_t *l_hdatHubEntry =
                        reinterpret_cast<hdatHubEntry_t *>(l_hdatHDIFDataArray);

    HDAT_DBG("writing io hub array from address=0x%016llX",
              (uint64_t)l_hdatHubEntry);

    for ( uint8_t l_cnt = 0; l_cnt < this->iv_hubArrayHdr.hdatArrayCnt; l_cnt++)
    {
        l_hdatHubEntry->hdatIoHubId =
                                  this->iv_hubArray[l_cnt].hdatIoHubId;
        l_hdatHubEntry->hdatModuleId =
                                  this->iv_hubArray[l_cnt].hdatModuleId;
        l_hdatHubEntry->hdatEcLvl =
                                  this->iv_hubArray[l_cnt].hdatEcLvl;
        l_hdatHubEntry->hdatProcChipID =
                                  this->iv_hubArray[l_cnt].hdatProcChipID;
        l_hdatHubEntry->hdatHardwareTopology =
                                  this->iv_hubArray[l_cnt].hdatHardwareTopology;
        l_hdatHubEntry->hdatMRID =
                                  this->iv_hubArray[l_cnt].hdatMRID;
        l_hdatHubEntry->hdatMemMapVersion =
                                  this->iv_hubArray[l_cnt].hdatMemMapVersion;
        l_hdatHubEntry->hdatFlags =
                                  this->iv_hubArray[l_cnt].hdatFlags;
        l_hdatHubEntry->hdatFab0PresDetect =
                                   this->iv_hubArray[l_cnt].hdatFab0PresDetect;

        for ( uint16_t l_phbcnt = 0 ; l_phbcnt < HDAT_PHB_LANES; l_phbcnt++)
        {
            l_hdatHubEntry->hdatLaneEqPHBGen3[l_phbcnt] =
                           this->iv_hubArray[l_cnt].hdatLaneEqPHBGen3[l_phbcnt];
        }
        for ( uint16_t l_phbcnt = 0 ; l_phbcnt < HDAT_PHB_LANES; l_phbcnt++)
        {
            l_hdatHubEntry->hdatLaneEqPHBGen4[l_phbcnt] =
                           this->iv_hubArray[l_cnt].hdatLaneEqPHBGen4[l_phbcnt];
        }

        l_hdatHubEntry++;//increase by size of hdatHubEntry_t

        HDAT_DBG("wrote io hub array %d",l_cnt);
    }

    l_temp = reinterpret_cast<uint8_t *>(l_hdatHubEntry);


    //doing padding for io hub

    io_virt_addr = this->setpadding(l_temp,o_size);


    //next to write daughter card values
    //this should go to offset 820 usually
    uint32_t l_chldOffset = this->getChildOffset();
    l_ioMarker += l_chldOffset;

    io_virt_addr = reinterpret_cast<uint8_t *>(l_ioMarker);

    HDAT_DBG("start writing daughter cards from address 0x%016llX",
             (uint64_t)io_virt_addr);

    if (iv_actDaughterCnt > 0)
     {
         l_vpdObj = *iv_daughterPtrs;
         uint32_t l_daughterCount = 0;
         while ( l_daughterCount < iv_actDaughterCnt)
         {
             HDAT_DBG("writing daughter from address 0x%016llX",
                       (uint64_t)io_virt_addr);
             io_virt_addr = l_vpdObj->setVpd( io_virt_addr);
             l_daughterCount++;

             if (l_daughterCount < iv_actDaughterCnt)
             {
                 l_vpdObj = *(HdatVpd **)((char *)iv_daughterPtrs +
                                           l_daughterCount * sizeof(HdatVpd *));
             }
         }
     }
     else
     {
         HDAT_DBG("no daughter information to write");
     }

    HDAT_DBG("exiting with virtual address=0x%016llX",
              (uint64_t)io_virt_addr);
    return io_virt_addr;
}


/******************************************************************************/
//  hdatGetDaughterInfoFromTarget
/******************************************************************************/

errlHndl_t HdatIoHubFru::hdatGetDaughterInfoFromTarget(
                   const TARGETING::Target * i_target,
                   TARGETING::TargetHandleList& o_targetList,
                   std::vector <uint32_t>& o_DaughterRids)
{
    //i_target is the TARGET of proc
    //add parent of this (sysnode) to list as BP
    //get all pci slot children of the proc in a list
    //for(start from the 1st slot; iterate through all the slots; )
    //add the pci slot to daughter list
    //get all the pci card children of the slot
    //for(start from the 1st card; iterate through all the cards; )
    //add the card to the daughter list

    //also add the vpdType enum here in this function and passover
    //so we get the vpd type handy while calling vpd constructor

    HDAT_ENTER();
    errlHndl_t l_errl = NULL;
    o_DaughterRids.clear();
    do
    {
        if ( NULL == i_target )
        {
            HDAT_ERR("hdatGetDaughterInfoFromTarget:"
            " input target pointer is NULL");

            /*@
             * @errortype
             * @moduleid         HDAT::MOD_IOHUB_FETCH_DAUGHTER
             * @reasoncode       HDAT::RC_INVALID_OBJECT
             * @devdesc          input Target pointer is NULL
             * @custdesc         Firmware encountered an internal error
             */
            hdatBldErrLog(l_errl,
                          MOD_IOHUB_FETCH_DAUGHTER,
                          RC_INVALID_OBJECT,
                          0,0,0,0);
            assert ( i_target != NULL);
        }
        if ((i_target->getAttr<ATTR_CLASS>() != CLASS_CARD)&&
            (i_target->getAttr<ATTR_CLASS>() != CLASS_LOGICAL_CARD)&&
            (i_target->getAttr<ATTR_CLASS>() != CLASS_CHIP))
        {
            HDAT_ERR("hdatGetDaughterInfoFromTarget: input Target class "
                     "not supported");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_IOHUB_FETCH_DAUGHTER
             * @reasoncode       HDAT::RC_TARGET_UNSUPPORTED
             * @devdesc          Target class not supported
             * @custdesc         Firmware encountered an internal error
             */
            hdatBldErrLog(l_errl,
                          MOD_IOHUB_FETCH_DAUGHTER,
                          RC_TARGET_UNSUPPORTED,
                          0,0,0,0);

            break;
        }

        o_targetList.clear();
        getParentAffinityTargets(o_targetList,i_target,
                 TARGETING::CLASS_ENC,TARGETING::TYPE_NODE);
        if(o_targetList.empty())
        {
            HDAT_ERR("hdatGetDaughterInfoFromTarget: node returned empty "
                     "Target list");
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_IOHUB_FETCH_DAUGHTER
             * @reasoncode       HDAT::RC_EMPTY_TARGET_LIST
             * @devdesc          node returned empty Target list
             * @custdesc         Firmware encountered an internal error
             */
            hdatBldErrLog(l_errl,
                          MOD_IOHUB_FETCH_DAUGHTER,
                          RC_EMPTY_TARGET_LIST,
                          0,0,0,0);
            assert ( !o_targetList.empty());

            break;
        }
        //get the parent node id, this is BP of the proc
        TARGETING::Target* l_pNodeTarget = o_targetList[0];
        o_DaughterRids.push_back(l_pNodeTarget->getAttr<ATTR_SLCA_RID>());


        //@TODO: RTC 148660 add the loop to fetch the pci slot and card
    }while(0);


    HDAT_EXIT();
    return l_errl;

}//end hdatGetDaughterInfoFromTarget

/******************************************************************************/
// bldDaughterStruct
/******************************************************************************/
errlHndl_t HdatIoHubFru::bldDaughterStruct(const TARGETING::Target * i_target,
                                           uint32_t i_index)
{
    errlHndl_t l_errlHndl = NULL;
    uint32_t   l_InstalledEtRidCnt = 0;
    uint32_t   l_loopCnt = 0;
    std::vector <uint32_t> l_etRidArray;
    TARGETING::TargetHandleList l_targetList;
    HdatVpd   *l_daughter = NULL;

    HDAT_ENTER();

    l_errlHndl = hdatGetDaughterInfoFromTarget(i_target,
                                               l_targetList,l_etRidArray);

    if (NULL == l_errlHndl)
    {
        l_InstalledEtRidCnt = l_etRidArray.size();
        HDAT_DBG("daughter count %d",l_InstalledEtRidCnt);
        iv_maxDaughters = l_InstalledEtRidCnt;

        iv_daughterPtrs = reinterpret_cast<HdatVpd **>(calloc(
                            l_InstalledEtRidCnt,sizeof(HdatVpd *)));

        if(iv_daughterPtrs)
        {
            for (uint32_t i=0; i<l_InstalledEtRidCnt; i++)
            {
                HDAT_DBG("adding daughter %d",
                         l_etRidArray[i]);
                l_errlHndl = this->addDaughterCard(l_etRidArray[i],
                                                   l_targetList[i], i_index);

                if ( NULL != l_errlHndl )
                {
                    HDAT_DBG("error adding daughter card");
                    break;
                }
            }
        }
        else
        {
            HDAT_DBG("error from calloc");

            /*@
             * @errortype
             * @moduleid         HDAT::MOD_IOHUB_BUILD_DAUGHTER
             * @reasoncode       HDAT::RC_MEM_ALLOC_FAIL
             * @devdesc          memory alloc failed in calloc
             * @custdesc         Firmware encountered an internal error
             */
            hdatBldErrLog(l_errlHndl,
                          MOD_IOHUB_BUILD_DAUGHTER,
                          RC_MEM_ALLOC_FAIL,
                          0,0,0,0);

        }
    }
    else
    {
        HDAT_DBG("no daughter cards for RID:0x%04x",
                  iv_fru.hdatResourceId);
    }

    // Tell the base class about child structures and adjust size of
    // daughter card structures so they are all the same size
    if (NULL == l_errlHndl && iv_daughterPtrs != NULL)
     {
         for(l_loopCnt = 0;l_loopCnt < iv_actDaughterCnt;l_loopCnt++)
         {
             /*l_daughter = *(HdatVpd **)((char *)iv_daughterPtrs +
                                        l_loopCnt * sizeof(HdatVpd *));*/

             l_daughter = *(reinterpret_cast<HdatVpd **>
                          (reinterpret_cast<char *>(iv_daughterPtrs) +
                          l_loopCnt * sizeof(HdatVpd *)));

             l_daughter->maxSiblingSize(iv_maxDaughterSize);

             HDAT_DBG("calling addChild");
             this->addChild(HDAT_DAUGHTER_CARD, iv_maxDaughterSize, 1);
         }
     }

     HDAT_EXIT();

     return l_errlHndl;

}//end bldDaughterStruct


/******************************************************************************/
//getTotalIoKwdSize
/******************************************************************************/

uint64_t HdatIoHubFru::getTotalIoKwdSize()
{
    HDAT_ENTER();

    return (iv_maxDaughterSize * iv_actDaughterCnt);

    HDAT_EXIT();
}

/******************************************************************************/
// addDaughterCard
/******************************************************************************/
errlHndl_t HdatIoHubFru::addDaughterCard(uint32_t i_resourceId,
                                         TARGETING::Target * i_target,
                                         uint32_t i_index)
{
    HDAT_ENTER();

    //eye catcher
    const char HDAT_KID_STRUCT_NAME[] = "IO KID";
    errlHndl_t l_errlHndl = NULL;
    HdatVpd *l_vpdObj, **l_arrayEntry;
    uint32_t l_size;
    uint32_t l_vpdType = 0x0;
    uint32_t FRU_BP = 0x8;

    l_vpdObj = NULL;
    l_vpdType = i_resourceId >> 8;
    HDAT_DBG("vpd type= %x",l_vpdType);

    // Ensure we are not trying to add more daughter cards than what we were
    // told to allow for on the constructor
    if (iv_actDaughterCnt < iv_maxDaughters)
    {
        if ( l_vpdType == FRU_BP )
        {

            uint32_t i_num = sizeof(mvpdData)/sizeof(mvpdData[0]);
            l_vpdObj = new HdatVpd(l_errlHndl, i_resourceId,i_target,
                                   HDAT_KID_STRUCT_NAME,i_index,BP,
                                   mvpdData,i_num,l_pvpdKeywords);
        }
        //@TODO: RTC 148660 pci slots and cards

        if (NULL == l_errlHndl)
        {
            l_arrayEntry = reinterpret_cast<HdatVpd **>(reinterpret_cast<char *>
                           (iv_daughterPtrs) +
                             iv_actDaughterCnt * sizeof(HdatVpd *));
            *l_arrayEntry = l_vpdObj;

            // Keep track of the largest daughter card object
            l_size = l_vpdObj->size();
            if (l_size > iv_maxDaughterSize)
            {
                iv_maxDaughterSize = l_size;
            }
            iv_actDaughterCnt++;
        }
        else
        {
            HDAT_DBG("could not create HdatVpd obj,"
            " got error");
            delete l_vpdObj;
        }
    }
    else
    {
        HDAT_DBG("exceeded limit of number of daughter card"
        " array entries");
    }

    HDAT_EXIT();

    return l_errlHndl;
}



/******************************************************************************/
// hdatLoadIoData
/******************************************************************************/

errlHndl_t hdatLoadIoData(const hdatMsAddr_t &i_msAddr,
                          uint32_t& o_size,uint32_t& o_count)
{
    HDAT_ENTER();

    errlHndl_t l_err = NULL;
    uint32_t l_size = 0;
    uint64_t l_totKwdSize = 0;
    IO_MAP l_iomap;

    o_size = 0;
    o_count = 0;


    do
    {
        //For all present  procs in the system
        TARGETING::PredicateCTM l_ctm1(TARGETING::CLASS_CHIP,
                                       TARGETING::TYPE_PROC);
        TARGETING::PredicateHwas l_predHwas;
        l_predHwas.present(true);
        TARGETING::PredicatePostfixExpr l_presentProc;
        l_presentProc.push(&l_ctm1).push(&l_predHwas).And();
        TARGETING::TargetRangeFilter l_proc(
                   TARGETING::targetService().begin(),
                   TARGETING::targetService().end(),
                   &l_presentProc);

        uint32_t l_numProcs = 0; //number of io entries
        for (;l_proc;++l_proc,l_numProcs++)  //so index will be same as l_proc
        {
            HDAT_DBG("for loop starting for index=%d",l_numProcs);

            TARGETING::Target *l_pProcTarget = *(l_proc);


            uint32_t l_rid = 0,l_slcaIdx = 0;

            l_rid = l_pProcTarget->getAttr<ATTR_SLCA_RID>();
            l_slcaIdx = l_pProcTarget->getAttr<ATTR_SLCA_INDEX>();

            HDAT_DBG("got RID value as %d",l_rid);

            uint32_t l_procOrdId =
                     l_pProcTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();
            HDAT_DBG("got ordinal id as %d",l_procOrdId);


            TARGETING::PredicateCTM l_pciPredicate(TARGETING::CLASS_UNIT,
                                                   TARGETING::TYPE_PCI);
            TARGETING::TargetHandleList l_pciList;


            //Add support for finding the card type
            //All values except HDAT_PROC_CARD is reverved
            hdatCardType l_cardType = HDAT_PROC_CARD;

            uint32_t l_procEcLevel = 0;
            uint32_t l_procChipId = 0;
            l_err = hdatGetIdEc(l_pProcTarget,
                                l_procEcLevel,
                                l_procChipId);
            if(NULL != l_err)
            {
                HDAT_ERR("Error in getting proc IdEc");
                break;
            }
            TARGETING::ATTR_MRU_ID_type l_mruId = 0;

            l_mruId = l_pProcTarget->getAttr<TARGETING::ATTR_MRU_ID>();
            HDAT_DBG("got mru id as %d",l_mruId);

            if(NULL != l_err)
            {
                HDAT_ERR("Error in getting MRU ID");
                break;
            }

            HdatIoHubFru * fruData = new HdatIoHubFru(l_err,
                                 l_rid,
                                 l_cardType,
                                 0,
                                 l_numProcs,
                                 l_slcaIdx);

            hdatHubEntry_t *l_hub;

            l_hub = reinterpret_cast<hdatHubEntry_t *>(reinterpret_cast<char *>
                    (fruData->iv_hubArray) +
                 fruData->iv_hubArrayHdr.hdatArrayCnt * sizeof(hdatHubEntry_t));

            // Save information about the I/O chip
            l_hub->hdatIoHubId = l_procOrdId;

            if(isFunctional(l_pProcTarget))
            {
                l_hub->hdatFlags = HDAT_HUB_USABLE;
            }
            else
            {
                l_hub->hdatFlags = HDAT_HUB_NOT_USABLE;
            }
            if (fruData->iv_hubStatus != 0)
            {
                // Replace status bits in hdatFlags with iv_hdatStatus
                l_hub->hdatFlags &= ~HDAT_HUB_STATUS_MASK;
                l_hub->hdatFlags |= fruData->iv_hubStatus;
            }
            HDAT_DBG("hdatFlags 1: %X",l_hub->hdatFlags);

            TARGETING::ATTR_MODEL_type  l_model =
                            (l_pProcTarget->getAttr<TARGETING::ATTR_MODEL>());

            if(l_model == TARGETING::MODEL_NIMBUS)
            {
                l_hub->hdatModuleId = HDAT_MODULE_TYPE_ID_NIMBUS_LAGRANGE;
            }
            else if(l_model == TARGETING::MODEL_CUMULUS)
            {
                l_hub->hdatModuleId = HDAT_MODULE_TYPE_ID_CUMULUS_DUOMO;
            }
            else
            {
                HDAT_ERR("Chip is not in Nimbus,Cumulus");
            }

            l_hub->hdatEcLvl = l_procEcLevel;
            l_hub->hdatProcChipID = l_procOrdId;
            l_hub->hdatHardwareTopology = l_pProcTarget->
                    getAttr<TARGETING::ATTR_PROC_HW_TOPOLOGY>();
            l_hub->hdatMRID = l_mruId;

            //memory map version
            l_hub->hdatMemMapVersion = 2;

            l_hub->hdatFab0PresDetect = l_pProcTarget->
                   getAttr<TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE>();

            TARGETING::PredicateHwas l_predHwasFunc;
            TARGETING::PredicateCTM l_phbPredicate (TARGETING::CLASS_UNIT,
                                                    TARGETING::TYPE_PHB);
            TARGETING::PredicatePostfixExpr l_funcPhb;
            l_funcPhb.push(&l_phbPredicate).push(&l_predHwasFunc).And();
            
            TARGETING::TargetHandleList l_phbList;
            
            TARGETING::targetService().getAssociated(l_phbList, l_pProcTarget,
                       TARGETING::TargetService::CHILD,
                       TARGETING::TargetService::ALL,
                       &l_funcPhb);
            // copy the lane data
            for(uint32_t l_idx = 0; l_idx<l_phbList.size(); ++l_idx)
            {
                TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN3_type
                           l_laneEq3 = {0};

                TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN4_type
                           l_laneEq4 = {0};
                           
                TARGETING::Target *l_phbTarget = l_phbList[l_idx];
                
                assert( l_phbTarget->
                   tryGetAttr<TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN3>(
                       l_laneEq3));

                memcpy((l_hub->hdatLaneEqPHBGen3 +
                          l_idx*NUM_OF_LANES_PER_PHB), l_laneEq3,
                          NUM_OF_LANES_PER_PHB*2);

                assert( l_phbTarget->
                   tryGetAttr<TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN4>(
                      l_laneEq4));

                memcpy((l_hub->hdatLaneEqPHBGen4 +
                          l_idx*NUM_OF_LANES_PER_PHB),l_laneEq4,
                          NUM_OF_LANES_PER_PHB*2);
                                      
            }


            //increment counts
            fruData->iv_hubArrayHdr.hdatArrayCnt++;

            //build the daughter structure
            l_err = fruData->bldDaughterStruct(l_pProcTarget,l_numProcs);


            if ( l_err )
            {
                HDAT_ERR("error in building daughter structure");
                break;
            }

            HDAT_DBG("fruData.bldDaughterStruct done, will insert to the map");

            //insert the fru data to the map
            l_iomap.insert(std::pair<uint32_t,HdatIoHubFru*>
                                    (l_numProcs,fruData));
            HDAT_DBG("done inserting into the map");

            l_totKwdSize = fruData->getTotalIoKwdSize();
            HDAT_DBG("got l_totKwdSize=%x",l_totKwdSize);

        }//end for loop

        o_count = l_numProcs;
        HDAT_DBG("setting count same to index=%d,o_count=%d",
                  l_numProcs,o_count);


        //calculate the virtual address to start writing at main memory
        //allocate space for iohub data

        uint64_t i_base_addr = ((uint64_t) i_msAddr.hi << 32) | i_msAddr.lo;
        uint64_t l_childPtrSize = HDAT_CHILD_LAST * sizeof(hdatHDIFChildHdr_t);
        uint32_t l_mod = l_childPtrSize % HDAT_MULTIPLE;

        if ( l_mod > 0 )
        {
            l_childPtrSize += HDAT_MULTIPLE - l_mod;
        }
        uint64_t l_totalsize = (HDAT_MAX_IO_CHIPS * sizeof(hdatHubEntry_t)) +
                               (HDAT_PARENT_LAST * sizeof(hdatHDIFDataHdr_t))+
                               l_childPtrSize;

        uint64_t i_base_addr_down = ALIGN_PAGE_DOWN(i_base_addr);

        //l_numProcs carries the number of proc
        //allocate the memory
        HDAT_DBG("allocating memory (l_totalsize * l_numProcs)+l_totKwdSize=%x",
                  ((l_totalsize * l_numProcs)+ l_totKwdSize));

        void *l_virt_addr = mm_block_map (
                            reinterpret_cast<void*>(i_base_addr_down),
                            ALIGN_PAGE((l_totalsize * l_numProcs)+ l_totKwdSize)
                                       + PAGESIZE);

        uint64_t l_vaddr = reinterpret_cast<uint64_t>(l_virt_addr);
        l_vaddr += i_base_addr-i_base_addr_down;
        l_virt_addr = reinterpret_cast<void *>(l_vaddr);

        uint8_t* l_virtAddr = reinterpret_cast<uint8_t *>(l_virt_addr);

        HDAT_DBG("l_virtAddr =0x%016llX, l_virt_addr=0x%016llX",
                  (uint64_t)l_virtAddr,(uint64_t)l_virt_addr);

        //Iterate thru each FRU data and write to mainstore

        IO_MAP::iterator l_itr;
        for(l_itr = l_iomap.begin(); l_itr != l_iomap.end(); ++l_itr)
        {
            HDAT_DBG("writing to main memory");
            uint8_t* l_startAddr = l_virtAddr;

            //write to main memory
            l_virtAddr= l_itr->second->setIOHub(l_virtAddr,l_size);

            if ( l_size > o_size )
            {
                o_size = l_size;
            }

            //add the required padding after each io object
            uint32_t l_rem = o_size % 128;
            uint32_t l_pad = l_rem ? (128 - l_rem) : 0;
            l_virtAddr = l_startAddr + l_pad + o_size;
            HDAT_DBG("wrote pad of 0x%x size after io object",l_pad);

        }//done writing to memory


        //unmap the region
        int rc = 0;
        rc =  mm_block_unmap(reinterpret_cast<void*>(ALIGN_PAGE_DOWN(
        reinterpret_cast<uint64_t>(l_virt_addr))));

        if( rc != 0)
        {
            HDAT_ERR("unmap of iohub region failed");
            errlHndl_t l_errl = NULL;
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_IOHUB_LOAD_DATA
             * @reasoncode       HDAT::RC_DEV_MAP_FAIL
             * @devdesc          Unmap a mapped region failed
             * @custdesc         Firmware encountered an internal error
             */
            hdatBldErrLog(l_errl,
                          MOD_IOHUB_LOAD_DATA,
                          RC_DEV_MAP_FAIL,
                          0,0,0,0,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                          HDAT_VERSION1,
                          true);
        }

        //erase the map
        for (l_itr = l_iomap.begin(); l_itr != l_iomap.end();)
         {
             //need to delete the object first
             delete(l_itr->second);

             l_iomap.erase(l_itr++);
         }//end erasing

    }while(0);


    HDAT_EXIT();
    return l_err;
}  //end hdatLoadIoData
}
