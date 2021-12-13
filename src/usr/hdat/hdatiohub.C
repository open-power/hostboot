/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatiohub.C $                                    */
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

vpdData pvpdData[] =
{
    { PVPD::VINI, PVPD::RT },
    { PVPD::VINI, PVPD::DR },
    { PVPD::VINI, PVPD::CE },
    { PVPD::VINI, PVPD::VZ },
    { PVPD::VINI, PVPD::FN },
    { PVPD::VINI, PVPD::PN },
    { PVPD::VINI, PVPD::SN },
    { PVPD::VINI, PVPD::CC },
    { PVPD::VINI, PVPD::HE },
    { PVPD::VINI, PVPD::CT },
    { PVPD::VINI, PVPD::HW },
    { PVPD::VINI, PVPD::B3 },
    { PVPD::VINI, PVPD::B4 },
    { PVPD::VINI, PVPD::B7 },
    { PVPD::LXR0, PVPD::RT },
    { PVPD::LXR0, PVPD::VZ},
    { PVPD::LXR0, PVPD::LX },
};

const HdatKeywordInfo l_pvpdKeywords[] =
{
    { PVPD::RT,  "RT" },
    { PVPD::DR,  "DR" },
    { PVPD::CE,  "CE" },
    { PVPD::VZ,  "VZ" },
    { PVPD::FN,  "FN" },
    { PVPD::PN,  "PN" },
    { PVPD::SN,  "SN" },
    { PVPD::CC,  "CC" },
    { PVPD::HE,  "HE" },
    { PVPD::CT,  "CT" },
    { PVPD::HW,  "HW" },
    { PVPD::B3,  "B3" },
    { PVPD::B4,  "B4" },
    { PVPD::B7,  "B7" },
    { PVPD::RT,  "RT" },
    { PVPD::VZ,  "VZ" },
    { PVPD::LX,  "LX" },
};

const char HDAT_EVEREST_SYSTEM_TYPE[] = "ibm,everest";

extern trace_desc_t *g_trac_hdat;

const uint32_t HDAT_MULTIPLE = 16;
//@TODO:RTC 255790 HDAT: SCM verification and support in BMC
//so that the code works for SCM and DCM seamlessly
const uint32_t PROC0_NUM_SLOT_TABLE_AREAS = 4;
const uint32_t PROC1_NUM_SLOT_TABLE_AREAS = 5;
const uint32_t PROC2_NUM_SLOT_TABLE_AREAS = 2;
const uint32_t PROC3_NUM_SLOT_TABLE_AREAS = 3;
const uint32_t PROC0_NUM_SLOT_ENTRY_INFO  = 4;
const uint32_t PROC1_NUM_SLOT_ENTRY_INFO  = 5;
const uint32_t PROC2_NUM_SLOT_ENTRY_INFO  = 2;
const uint32_t PROC3_NUM_SLOT_ENTRY_INFO  = 3;

//Everest slot numbers for each proc
const uint32_t PROC0_NUM_SLOTS = 6;
const uint32_t PROC1_NUM_SLOTS = 5;
const uint32_t PROC2_NUM_SLOTS = 3;
const uint32_t PROC3_NUM_SLOTS = 3;
const uint32_t PROC4_NUM_SLOTS = 2;
const uint32_t PROC5_NUM_SLOTS = 2;
const uint32_t PROC6_NUM_SLOTS = 2;
const uint32_t PROC7_NUM_SLOTS = 2;
const uint32_t TOTAL_NUM_SLOTS = 25;

//const uint32_t MAX_NUM_OF_PROCS           = 2;
//const uint32_t MAX_NUM_OF_SLOT_TABLE_AREAS =
  //             (PROC0_NUM_SLOT_TABLE_AREAS > PROC1_NUM_SLOT_TABLE_AREAS) ?
    //           PROC0_NUM_SLOT_TABLE_AREAS : PROC1_NUM_SLOT_TABLE_AREAS;
//const uint32_t MAX_NUM_OF_SLOT_ENTRY_INFO  =
  //            (PROC0_NUM_SLOT_ENTRY_INFO > PROC1_NUM_SLOT_ENTRY_INFO) ?
    //          PROC0_NUM_SLOT_ENTRY_INFO : PROC1_NUM_SLOT_ENTRY_INFO;

//each PHB lane size
const uint32_t NUM_OF_LANES_PER_PHB = 
       sizeof(TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN3_type)/2;

static_assert( NUM_OF_LANES_PER_PHB == 
    sizeof(TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN3_type)/2,
      "no. of lanes per PHB should be 16");

// HARD codes of slot map area and entry structs
// TODO:SW398487 : Need to replace this with PNOR : HDAT partition consumption.
// The below hardcoding is for temporary purpose but still valid values from mrw
// hdatSlotMapAreas got changed to reflect P10 Rainier model values
hdatSlotMapArea_t hdatSlotMapAreas[PROC0_NUM_SLOT_TABLE_AREAS + PROC1_NUM_SLOT_TABLE_AREAS + PROC2_NUM_SLOT_TABLE_AREAS + PROC3_NUM_SLOT_TABLE_AREAS]=
{
{ 1,0,0,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"C11" },
{ 2,0,1,0,0,0,0x00FF,0,0,0,1,0,0,0,0,0,0,0,"002" },
{ 3,0,2,0,0,0,0x000F,0,0,0,1,0,0,0,0,0,0,0,"001" },
{ 4,0,3,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C10" },
{ 5,0,0,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"C9" },
{ 6,0,1,0,0,0,0x00FF,0,0,0,1,0,0,0,0,0,0,0,"C8" },
{ 7,0,3,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"C7" },
{ 8,0,4,0,0,0,0x00F0,0,0,0,1,0,0,0,0,0,0,0,"004" },
{ 9,0,5,0,0,0,0x000F,0,0,0,1,0,0,0,0,0,0,0,"003" },
{ 10,0,0,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C4" },
{ 11,0,3,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C3" },
{ 12,0,0,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"C2" },
{ 13,0,1,0,0,0,0x00FF,0,0,0,1,0,0,0,0,0,0,0,"C1" },
{ 14,0,3,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C0" }
};


hdatSlotEntryInfo_t hdatSlotMapEntries[PROC0_NUM_SLOT_ENTRY_INFO + PROC1_NUM_SLOT_ENTRY_INFO + PROC2_NUM_SLOT_ENTRY_INFO + PROC3_NUM_SLOT_ENTRY_INFO] = {
{ 1,0,5,2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0,0 },
{ 2,0,0,128, 0,  2,0,0,0,0,0,25,0, 32,  0,0,0,0,0,0 },
{ 3,0,0,64,  0,  2,0,0,0,0,0,25,0, 32,  0,0,0,0,0,0 },
{ 4,0,1,2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0,0 },
{ 5,0,9,2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0,0 },
{ 6,0,7,2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0,0 },
{ 7,0,6,2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0,0 },
{ 8,0,0,128, 0,  2,0,0,0,0,0,25,0, 32,  0,0,0,0,0,0 },
{ 9,0,0,128, 0,  2,0,0,0,0,0,25,0, 32,  0,0,0,0,0,0 },
{ 10,0,4,2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0 },
{ 11,0,3,2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0 },
{ 12,0,10,2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0 },
{ 13,0,8, 2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0 },
{ 14,0,2, 2040,256,2,0,0,0,0,0,25,46,4072,0,0,0,0,0 }
};

//Everest related slot map area entries
//@TODO:RTC 270825 HDAT : Slot map hard code removal
//Need to replace the hard codings with a different mechanism
hdatSlotMapArea_t hdatSlotMapAreasEverest[TOTAL_NUM_SLOTS]=
{
{ 1, 0,0,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"C1" },
{ 2, 0,1,0,0,0,0x00F0,0,0,0,1,0,0,0,0,0,0,0,"Enet 0" },
{ 3, 0,2,0,0,0,0x000F,0,0,0,1,0,0,0,0,0,0,0,"Enet 1" },
{ 4, 0,3,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"NVMe C9" },
{ 5, 0,4,0,0,0,0x00F0,0,0,0,1,0,0,0,0,0,0,0,"NVMe C4" },
{ 6, 0,5,0,0,0,0x000F,0,0,0,1,0,0,0,0,0,0,0,"USB Cntr" },

{ 7, 0,0,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"NVMe C8" },
{ 8, 0,1,0,0,0,0x00F0,0,0,0,1,0,0,0,0,0,0,0,"eBMC" },
{ 9, 0,2,0,0,0,0x000F,0,0,0,1,0,0,0,0,0,0,0,"NVMe C3" },
{ 10,0,3,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"NVMe C7" },
{ 11,0,4,0,0,0,0x00F0,0,0,0,1,0,0,0,0,0,0,0,"NVMe C2" },

{ 12,0,0,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C11" },
{ 13,0,3,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"C10" },
{ 14,0,4,0,0,0,0x00FF,0,0,0,1,0,0,0,0,0,0,0,"C9" },

{ 15,0,0,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C8" },
{ 16,0,3,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"C7" },
{ 17,0,4,0,0,0,0x00FF,0,0,0,1,0,0,0,0,0,0,0,"C6" },

{ 18,0,0,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C5" },
{ 19,0,3,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C4" },

{ 20,0,0,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C3" },
{ 21,0,3,0,0,0,0xFFFF,0,0,0,1,0,0,0,0,0,0,0,"C2" },

{ 22,0,0,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"NVMe C6" },
{ 23,0,3,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"NVMe C1" },

{ 24,0,0,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"NVMe C5" },
{ 25,0,3,0,0,0,0xFF00,0,0,0,1,0,0,0,0,0,0,0,"NVMe C0" },
};


//Everest related slot map info entries
hdatSlotEntryInfo_t hdatSlotMapEntriesEverest[TOTAL_NUM_SLOTS]=
{
{ 1, 0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 2, 0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },
{ 3, 0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },
{ 4, 0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 5, 0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },
{ 6, 0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },

{ 7, 0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 8, 0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },
{ 9, 0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },
{ 10,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 11,0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },

{ 12,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 13,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 14,0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },

{ 15,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 16,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 17,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },

{ 18,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 19,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },

{ 20,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 21,0,0,2040,256,2,0,0,0,0,0,75,46,2024,0,0,0,0,0,0 },

{ 22,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 23,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },

{ 24,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
{ 25,0,0,2040,256,2,0,0,0,0,0,75,46,4072,0,0,0,0,0,0 },
};

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
iv_maxDaughterSize(0),iv_kwd(NULL),iv_hubArray(NULL),iv_daughterPtrs(NULL),
iv_hdatSlotMapAreaPtr(NULL),iv_hdatSlotMapEntryInfoPtr(NULL)
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
    iv_hdatSlotMapAreaArrayHdr = {0};
    iv_hdatSlotMapEntryArrayHdr= {0};

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
    HDAT_ENTER();
    HDAT_DBG("entered setIOHub with virtual address=0x%016llX",
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
    HDAT_DBG("number of hub array entries: 0x%x",
                                             this->iv_hubArrayHdr.hdatArrayCnt);

    for ( uint8_t l_cnt = 0; l_cnt < this->iv_hubArrayHdr.hdatArrayCnt; l_cnt++)
    {
        l_hdatHubEntry->hdatIoHubId =
                                  this->iv_hubArray[l_cnt].hdatIoHubId;
        l_hdatHubEntry->hdatMaxPCIeLinkSpeed = 
                                  this->iv_hubArray[l_cnt].hdatMaxPCIeLinkSpeed;
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
        for ( uint16_t l_phbcnt = 0 ; l_phbcnt < HDAT_PHB_LANES; l_phbcnt++)
        {
            l_hdatHubEntry->hdatLaneEqPHBGen5[l_phbcnt] =
                           this->iv_hubArray[l_cnt].hdatLaneEqPHBGen5[l_phbcnt];
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
    HDAT_DBG("l_chldOffset=0x%x",l_chldOffset);
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
             HDAT_ADD_PAD(io_virt_addr);
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
         HDAT_ADD_PAD(io_virt_addr);
     }
    HDAT_DBG("completed writing daughter card at address 0x%016llX",
               (uint64_t)io_virt_addr);

     if( iv_slotMapInfoObjs.size() > 0 )
     {
         HDAT_DBG("writing iv_slotMapInfoObjs number=%d",
                                         iv_slotMapInfoObjs.size());
        for( auto &l_slotMapInfoEle : iv_slotMapInfoObjs)
        {
            io_virt_addr = l_slotMapInfoEle.setHdif(io_virt_addr);
            memcpy(io_virt_addr, &iv_hdatSlotMapAreaArrayHdr,
                      sizeof(hdatHDIFDataArray_t));
            io_virt_addr += sizeof(hdatHDIFDataArray_t);
            memcpy(io_virt_addr, iv_hdatSlotMapAreaPtr,
                   sizeof(hdatSlotMapArea_t) *
                   (iv_hdatSlotMapAreaArrayHdr.hdatArrayCnt));
            io_virt_addr += sizeof(hdatSlotMapArea_t) *
                     (iv_hdatSlotMapAreaArrayHdr.hdatArrayCnt);
            memcpy(io_virt_addr, &iv_hdatSlotMapEntryArrayHdr,
                   sizeof(hdatHDIFDataArray_t));
            io_virt_addr += sizeof(hdatHDIFDataArray_t);
            memcpy(io_virt_addr, iv_hdatSlotMapEntryInfoPtr,
                   sizeof(hdatSlotEntryInfo_t) *
                        (iv_hdatSlotMapEntryArrayHdr.hdatArrayCnt));
            io_virt_addr += sizeof(hdatSlotEntryInfo_t) *
                          (iv_hdatSlotMapEntryArrayHdr.hdatArrayCnt);
        
            HDAT_ADD_PAD(io_virt_addr);
        }
    }

    HDAT_DBG("exiting with virtual address=0x%016llX",
              (uint64_t)io_virt_addr);
    HDAT_EXIT();
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
    uint32_t  dummy_slca_rid = 0;
    TARGETING::TargetHandleList l_list;
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
        HDAT_DBG("entered with i_target=%x",i_target);
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

        getParentAffinityTargets(l_list,i_target,
                 TARGETING::CLASS_ENC,TARGETING::TYPE_NODE);
        HDAT_DBG("l_list.size()=%d",l_list.size());
        if(l_list.empty())
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
        //not available in hostboot
        //TARGETING::Target* l_pNodeTarget = o_targetList[0];
        //@TODO RTC 246357 missing attribute
        //SLCA_RID not present for BP, will it be supported at all?
        //o_DaughterRids.push_back(l_pNodeTarget->getAttr<ATTR_SLCA_RID>());
        o_DaughterRids.push_back(dummy_slca_rid);
        o_targetList.insert(o_targetList.end(),l_list.begin(),l_list.end());
        dummy_slca_rid++;
        HDAT_DBG("o_targetList.size()=%d",o_targetList.size()); 

        //@TODO: RTC 148660 add the loop to fetch the pci slot and card
    }while(0);


    HDAT_EXIT();
    return l_errl;

}//end hdatGetDaughterInfoFromTarget


/******************************************************************************/
// bldDaughterStruct
/******************************************************************************/
errlHndl_t HdatIoHubFru::bldDaughterStruct(uint32_t i_hubArrayNum)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    uint32_t   l_InstalledEtRidCnt = 0;
    uint32_t   l_loopCnt = 0;
    std::vector <uint32_t> l_etRidArray;
    TARGETING::TargetHandleList l_targetList;
    HdatVpd   *l_daughter = NULL;

    HDAT_DBG("entered bldDaughterStruct with num of hub array=%d",i_hubArrayNum);

    for(uint32_t i=0; i<i_hubArrayNum; i++)
    {
        uint32_t procOrdId= this->iv_hubArray[i].hdatIoHubId;
        HDAT_DBG("fetched procOrdId=0x%x",procOrdId);
        TARGETING::Target * i_target = nullptr;
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
        for (;l_proc;++l_proc)
        {
            i_target = *(l_proc);
            uint32_t l_procOrdId = i_target->getAttr<TARGETING::ATTR_ORDINAL_ID>();
            if(l_procOrdId == procOrdId)
            {
                HDAT_DBG("found proc target=%x for procOrdId=0x%x",
                                              TARGETING::get_huid(i_target),l_procOrdId);
                break;
            }
            else
            {
                i_target = nullptr;
            }
        }
        HDAT_DBG("before calling hdatGetDaughterInfoFromTarget l_targetList.size=%d",l_targetList.size());

        l_errlHndl = hdatGetDaughterInfoFromTarget(i_target,
                                               l_targetList,l_etRidArray);
        HDAT_DBG("after hdatGetDaughterInfoFromTarget l_targetList.size=%d",l_targetList.size());
        if(l_errlHndl)
        {
            return l_errlHndl;
        }
    }

    if (NULL == l_errlHndl)
    {
        l_InstalledEtRidCnt = l_etRidArray.size();
        HDAT_DBG("daughter count l_InstalledEtRidCnt %d",l_InstalledEtRidCnt);
        iv_maxDaughters = l_InstalledEtRidCnt;

        iv_daughterPtrs = reinterpret_cast<HdatVpd **>(calloc(
                            l_InstalledEtRidCnt,sizeof(HdatVpd *)));

        if(iv_daughterPtrs)
        {
            for (uint32_t i=0; i<l_InstalledEtRidCnt; i++)
            {
                HDAT_DBG("adding daughter %d for rid=%d and target=0x%x",
                         i,l_etRidArray[i],l_targetList[i]);
                l_errlHndl = this->addDaughterCard(l_etRidArray[i],
                                                   l_targetList[i], i);

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
             HDAT_DBG("iv_actDaughterCnt=%d and l_loopCnt=%d",
                                    iv_actDaughterCnt,l_loopCnt);

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

    l_vpdObj = NULL;
    l_vpdType = i_resourceId >> 8;
    HDAT_DBG("vpd type= %x, RID=%d,i_index=%d",l_vpdType,i_resourceId,i_index);

    // Ensure we are not trying to add more daughter cards than what we were
    // told to allow for on the constructor
    if (iv_actDaughterCnt < iv_maxDaughters)
    {
        //Get the processor model
        auto l_model = TARGETING::targetService().getProcessorModel();

        if (l_model == TARGETING::MODEL_POWER10)
        {
            //l_vpdType can not be compared since there is no valid rid
            //for BP in p10
            HDAT_DBG("constructing BP vpd for daughter card for p10");
            uint32_t i_num = sizeof(pvpdData)/sizeof(pvpdData[0]);
            l_vpdObj = new HdatVpd(l_errlHndl, i_resourceId,i_target,
                                      HDAT_KID_STRUCT_NAME,i_index,BP,
                                     pvpdData,i_num,l_pvpdKeywords);
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



//@TODO:RTC Story 255790 : HDAT: SCM verification and support in BMC
//make change to correctly know about SCM or DCM architecture
//decide about i_dcm variable
errlHndl_t HdatIoHubFru::bldSlotMapInfoStruct(/*uint32_t i_numProc,*/int i_iohubNum,
                                              bool i_dcm)
{

    errlHndl_t l_errlHndl = NULL;

    HDAT_ENTER();

    TARGETING::Target *l_pSysTarget = NULL;
    (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

    if(l_pSysTarget == NULL)
    {
      HDAT_ERR("bldSlotMapInfoStruct:Top Level Target not found");
      assert(l_pSysTarget != NULL);
    }

    TARGETING::ATTR_SYSTEM_TYPE_type l_systemType = {0};
    l_pSysTarget->tryGetAttr<TARGETING::ATTR_SYSTEM_TYPE> (l_systemType);

    do{
        const char HDAT_IOSLOT_STRUCT_NAME[] = "IOSLOT";   
        const uint16_t HDAT_SLOTMAP_INFO_VER = 0x0020;

        iv_hdatSlotMapAreaPtr = reinterpret_cast<hdatSlotMapArea_t *>(calloc(
                            HDAT_MAX_SLOT_PER_HUB, sizeof(hdatSlotMapArea_t)));

        iv_hdatSlotMapEntryInfoPtr =
                        reinterpret_cast<hdatSlotEntryInfo_t *>(calloc(
                            HDAT_MAX_SLOT_PER_HUB, sizeof(hdatSlotEntryInfo_t)));

    
        HdatHdif *l_SlotMap = new HdatHdif(l_errlHndl,HDAT_IOSLOT_STRUCT_NAME,
                                           HDAT_SLOT_MAP_LAST, 0, 0, 
                                           HDAT_SLOTMAP_INFO_VER);
        if(l_errlHndl == NULL)
        {
            l_errlHndl = hdatGetSlotMapTableAreas(/*i_numProc,*/l_systemType, i_iohubNum,i_dcm);
            if(l_errlHndl != NULL)
            {
                HDAT_ERR(" Slot Map Table Areas population failed");
                break;
            }

            l_errlHndl = hdatGetSlotMapEntryInfos(/*i_numProc,*/l_systemType, i_iohubNum,i_dcm);
            if(l_errlHndl != NULL)
            {
                HDAT_ERR(" Slot Map Entry Infos population failed");
                break;
            }

            l_SlotMap->addData(HDAT_SLOT_MAP_AREA, sizeof(hdatHDIFDataArray_t)+
                 sizeof(hdatSlotMapArea_t) * iv_hdatSlotMapAreaArrayHdr.hdatArrayCnt);
            l_SlotMap->addData(HDAT_SLOT_MAP_ENTRY,sizeof(hdatHDIFDataArray_t)+
                 sizeof(hdatSlotEntryInfo_t) * iv_hdatSlotMapEntryArrayHdr.hdatArrayCnt);
            l_SlotMap->align();
        }
        iv_slotMapInfoSize = l_SlotMap->size();
        l_SlotMap->print();
                        
        this->addChild(HDAT_SLOT_MAP_INFO, iv_slotMapInfoSize ,1);
        iv_slotMapInfoObjs.push_back(*l_SlotMap);
    }while(0);
    return(l_errlHndl);
}



errlHndl_t HdatIoHubFru::hdatGetSlotMapTableAreas(/*uint32_t i_numProc,*/
    const char* i_systemType, int i_iohubNum,bool i_dcm)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    if (!i_dcm)
    {
        uint32_t arrayCount = 0;
        auto startIndex = 0;
        if(strcmp(i_systemType, HDAT_EVEREST_SYSTEM_TYPE)) //Rainier
        {
            if(i_iohubNum == 1)
            {
                arrayCount = PROC0_NUM_SLOT_TABLE_AREAS +
                             PROC1_NUM_SLOT_TABLE_AREAS;
            }
            else if(i_iohubNum == 2)
            {
                arrayCount = PROC0_NUM_SLOT_TABLE_AREAS +
                             PROC1_NUM_SLOT_TABLE_AREAS +
                             PROC2_NUM_SLOT_TABLE_AREAS +
                             PROC3_NUM_SLOT_TABLE_AREAS;
            }
        }
        else //Everest
        {
            if(i_iohubNum == 1)
            {
                arrayCount = PROC0_NUM_SLOTS +
                             PROC1_NUM_SLOTS;
            }
            else if(i_iohubNum == 2)
            {
                arrayCount = PROC0_NUM_SLOTS +
                             PROC1_NUM_SLOTS +
                             PROC2_NUM_SLOTS +
                             PROC3_NUM_SLOTS;
            }
            else if(i_iohubNum == 3)
            {
                arrayCount = PROC0_NUM_SLOTS +
                             PROC1_NUM_SLOTS +
                             PROC2_NUM_SLOTS +
                             PROC3_NUM_SLOTS +
                             PROC4_NUM_SLOTS +
                             PROC5_NUM_SLOTS;
            }
            else if(i_iohubNum == 4)
            {
                arrayCount = PROC0_NUM_SLOTS +
                             PROC1_NUM_SLOTS +
                             PROC2_NUM_SLOTS +
                             PROC3_NUM_SLOTS +
                             PROC4_NUM_SLOTS +
                             PROC5_NUM_SLOTS +
                             PROC6_NUM_SLOTS +
                             PROC7_NUM_SLOTS;
            }
        }

        iv_hdatSlotMapAreaArrayHdr = { sizeof(hdatHDIFDataArray_t),
                          arrayCount,
                          sizeof(hdatSlotMapArea_t),
                          sizeof(hdatSlotMapArea_t) };
        if(strcmp(i_systemType, HDAT_EVEREST_SYSTEM_TYPE)) //Rainier
        {
            memcpy(iv_hdatSlotMapAreaPtr, (hdatSlotMapAreas+startIndex) ,
            sizeof(hdatSlotMapArea_t)*iv_hdatSlotMapAreaArrayHdr.hdatArrayCnt);
        }
        else //Everest
        {
            memcpy(iv_hdatSlotMapAreaPtr, (hdatSlotMapAreasEverest+startIndex),
            sizeof(hdatSlotMapArea_t)*iv_hdatSlotMapAreaArrayHdr.hdatArrayCnt);
        }
    }
    else
    {
        uint32_t arrayCount = 0;
        auto startIndex = 0;
        if(strcmp(i_systemType, HDAT_EVEREST_SYSTEM_TYPE)) //Rainier
        {
            switch(i_iohubNum)
            {
                case 1: arrayCount = PROC0_NUM_SLOT_TABLE_AREAS +
                                     PROC1_NUM_SLOT_TABLE_AREAS;
                        break;
                case 2: arrayCount = PROC2_NUM_SLOT_TABLE_AREAS +
                                     PROC3_NUM_SLOT_TABLE_AREAS;

                        startIndex = PROC0_NUM_SLOT_TABLE_AREAS +
                                     PROC1_NUM_SLOT_TABLE_AREAS;
                        break;
            }
        }
        else //Everest
        {
            switch(i_iohubNum)
            {
                case 1: arrayCount = PROC0_NUM_SLOTS +
                                     PROC1_NUM_SLOTS;
                        break;
                case 2: arrayCount = PROC2_NUM_SLOTS +
                                     PROC3_NUM_SLOTS;

                        startIndex = PROC0_NUM_SLOTS +
                                     PROC1_NUM_SLOTS;
                        break;
                case 3: arrayCount = PROC4_NUM_SLOTS +
                                     PROC5_NUM_SLOTS;

                        startIndex = PROC0_NUM_SLOTS +
                                     PROC1_NUM_SLOTS +
                                     PROC2_NUM_SLOTS +
                                     PROC3_NUM_SLOTS;
                        break;
                case 4: arrayCount = PROC6_NUM_SLOTS +
                                     PROC7_NUM_SLOTS;

                        startIndex = PROC0_NUM_SLOTS +
                                     PROC1_NUM_SLOTS +
                                     PROC2_NUM_SLOTS +
                                     PROC3_NUM_SLOTS +
                                     PROC4_NUM_SLOTS +
                                     PROC5_NUM_SLOTS;
                        break;
            }
        }

        iv_hdatSlotMapAreaArrayHdr = { sizeof(hdatHDIFDataArray_t), 
           arrayCount,
           sizeof(hdatSlotMapArea_t), sizeof(hdatSlotMapArea_t) };

        if(strcmp(i_systemType, HDAT_EVEREST_SYSTEM_TYPE)) //Rainier
        {
            memcpy(iv_hdatSlotMapAreaPtr, (hdatSlotMapAreas + startIndex),
            sizeof(hdatSlotMapArea_t)*iv_hdatSlotMapAreaArrayHdr.hdatArrayCnt);
        }
        else // Everest
        {
            memcpy(iv_hdatSlotMapAreaPtr,
                (hdatSlotMapAreasEverest + startIndex),
            sizeof(hdatSlotMapArea_t)*iv_hdatSlotMapAreaArrayHdr.hdatArrayCnt);
        }
        auto toPrintSlotMap= 
                 reinterpret_cast<hdatSlotMapArea_t *>(iv_hdatSlotMapAreaPtr);
        for(size_t i=0; i<iv_hdatSlotMapAreaArrayHdr.hdatArrayCnt;i++)
        {
            HDAT_DBG("printing slot map object %i",i);
            HDAT_DBG("hdatEntryId=0x%x",toPrintSlotMap->hdatEntryId);
            HDAT_DBG("hdatLaneMask=0x%x",toPrintSlotMap->hdatLaneMask);
            HDAT_DBG("hdatSlotName=%s",toPrintSlotMap->hdatSlotName);
            toPrintSlotMap++;
        }
    }
    HDAT_EXIT();
    return l_errlHndl;
}

errlHndl_t HdatIoHubFru::hdatGetSlotMapEntryInfos(/*uint32_t i_numProc,*/
    const char* i_systemType, int i_iohubNum, bool i_dcm)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    if (!i_dcm)
    {
        uint32_t arrayCount = 0;
        auto startIndex = 0;
        if(strcmp(i_systemType, HDAT_EVEREST_SYSTEM_TYPE)) //Rainier
        {
            if(i_iohubNum == 1)
            {
                arrayCount = PROC0_NUM_SLOT_ENTRY_INFO +
                             PROC1_NUM_SLOT_ENTRY_INFO;
            }
            else if(i_iohubNum == 2)
            {
                arrayCount = PROC0_NUM_SLOT_ENTRY_INFO +
                             PROC1_NUM_SLOT_ENTRY_INFO +
                             PROC2_NUM_SLOT_ENTRY_INFO +
                             PROC3_NUM_SLOT_ENTRY_INFO;
            }
        }
        else //Evesret
        {
            if(i_iohubNum == 1)
            {
                arrayCount = PROC0_NUM_SLOTS +
                             PROC1_NUM_SLOTS;
            }
            else if(i_iohubNum == 2)
            {
                arrayCount = PROC0_NUM_SLOTS +
                             PROC1_NUM_SLOTS +
                             PROC2_NUM_SLOTS +
                             PROC3_NUM_SLOTS;
            }
            else if(i_iohubNum == 3)
            {
                arrayCount = PROC0_NUM_SLOTS +
                             PROC1_NUM_SLOTS +
                             PROC2_NUM_SLOTS +
                             PROC3_NUM_SLOTS +
                             PROC4_NUM_SLOTS +
                             PROC5_NUM_SLOTS;
            }
            else if(i_iohubNum == 4)
            {
                arrayCount = PROC0_NUM_SLOTS +
                             PROC1_NUM_SLOTS +
                             PROC2_NUM_SLOTS +
                             PROC3_NUM_SLOTS +
                             PROC4_NUM_SLOTS +
                             PROC5_NUM_SLOTS +
                             PROC6_NUM_SLOTS +
                             PROC7_NUM_SLOTS;
            }
        }

        iv_hdatSlotMapEntryArrayHdr = { sizeof(hdatHDIFDataArray_t),
                            arrayCount,
                            sizeof(hdatSlotEntryInfo_t),
                            sizeof(hdatSlotEntryInfo_t) };
        if(strcmp(i_systemType, HDAT_EVEREST_SYSTEM_TYPE)) //Rainier
        {
            memcpy(iv_hdatSlotMapEntryInfoPtr, (hdatSlotMapEntries+startIndex),
                   sizeof(hdatSlotEntryInfo_t) *
                   iv_hdatSlotMapEntryArrayHdr.hdatArrayCnt);
        }
        else //Everest
        {
            memcpy(iv_hdatSlotMapEntryInfoPtr,
                   (hdatSlotMapEntriesEverest+startIndex),
                   sizeof(hdatSlotEntryInfo_t) *
                   iv_hdatSlotMapEntryArrayHdr.hdatArrayCnt);
        }
    }
    else
    {
        uint32_t arrayCount = 0;
        auto startIndex = 0;
        if(strcmp(i_systemType, HDAT_EVEREST_SYSTEM_TYPE)) //Rainier
        {
            switch(i_iohubNum)
            {
                case 1: arrayCount = PROC0_NUM_SLOT_ENTRY_INFO +
                                     PROC1_NUM_SLOT_ENTRY_INFO;
                        break;
                case 2: arrayCount = PROC2_NUM_SLOT_ENTRY_INFO +
                                     PROC3_NUM_SLOT_ENTRY_INFO;

                        startIndex = PROC0_NUM_SLOT_ENTRY_INFO +
                                     PROC1_NUM_SLOT_ENTRY_INFO;
                        break;
            }
        }
        else //Everest
        {
            switch(i_iohubNum)
            {
                case 1: arrayCount = PROC0_NUM_SLOTS +
                                     PROC1_NUM_SLOTS;
                        break;
                case 2: arrayCount = PROC2_NUM_SLOTS +
                                     PROC3_NUM_SLOTS;

                        startIndex = PROC0_NUM_SLOTS +
                                     PROC1_NUM_SLOTS;
                        break;
                case 3: arrayCount = PROC4_NUM_SLOTS +
                                     PROC5_NUM_SLOTS;

                        startIndex = PROC0_NUM_SLOTS +
                                     PROC1_NUM_SLOTS +
                                     PROC2_NUM_SLOTS +
                                     PROC3_NUM_SLOTS;
                        break;
                case 4: arrayCount = PROC6_NUM_SLOTS +
                                     PROC7_NUM_SLOTS;

                        startIndex = PROC0_NUM_SLOTS +
                                     PROC1_NUM_SLOTS +
                                     PROC2_NUM_SLOTS +
                                     PROC3_NUM_SLOTS +
                                     PROC4_NUM_SLOTS +
                                     PROC5_NUM_SLOTS;
                        break;
            }
        }
        iv_hdatSlotMapEntryArrayHdr = { sizeof(hdatHDIFDataArray_t), 
                          arrayCount,
                          sizeof(hdatSlotEntryInfo_t), 
                          sizeof(hdatSlotEntryInfo_t) };
        if(strcmp(i_systemType, HDAT_EVEREST_SYSTEM_TYPE)) //Rainier
        {
            memcpy(iv_hdatSlotMapEntryInfoPtr,
                   (hdatSlotMapEntries + startIndex),
                   sizeof(hdatSlotEntryInfo_t) *
                   iv_hdatSlotMapEntryArrayHdr.hdatArrayCnt);
        }
        else //Everest
        {
            memcpy(iv_hdatSlotMapEntryInfoPtr,
                   (hdatSlotMapEntriesEverest + startIndex),
                   sizeof(hdatSlotEntryInfo_t) *
                   iv_hdatSlotMapEntryArrayHdr.hdatArrayCnt);
        }
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
    uint64_t l_totKwdSize = 0 , l_totalSlotMapSize = 0;

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
        std::vector<HdatIoHubFru *>hdatIoHubFrus;
        TARGETING::ATTR_LOCATION_CODE_type l_cur_location_code { };
        TARGETING::ATTR_LOCATION_CODE_type l_last_location_code { };
        uint8_t l_dcmNum = 0;

        for (;l_proc;++l_proc,l_numProcs++)  //so index will be same as l_proc
        {
            HDAT_DBG("for loop starting for index=%d",l_numProcs);

            TARGETING::Target *l_pProcTarget = *(l_proc);


            uint32_t l_rid = 0,l_slcaIdx = 0;

            l_rid = l_pProcTarget->getAttr<ATTR_SLCA_RID>();
            l_slcaIdx = l_pProcTarget->getAttr<ATTR_SLCA_INDEX>();

            // Get the current proc location code
            hdatGetLocationCode(l_pProcTarget, HDAT_SLCA_FRU_TYPE_PROC,
                l_cur_location_code);

            uint32_t l_procOrdId =
                     l_pProcTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();
            HDAT_DBG("l_procOrdId=0x%x for target=0x%x",l_procOrdId,l_pProcTarget);

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

            //here check for SCM or DCM
            //create a new HdatIoHubFru object each time for SCM which means
            //a new HdatIoHubFru (eye catcher IO HUB) for each
            //processor
            //for DCM we should create a new hdatHubEntry_t in the
            //iv_hubArray or create a new HdatIoHubFru object
            //for proc0 and proc1 in DCM0 we will have 2hub array entry in
            //io1
            //check if there is any attribute for finding SCM vs DCM
            //in fsp this is checked by comparing the fru id. if same
            //then add a new hubentry in hub array otherwise create a 
            //new HdatIoHubFru object

            // Procs under DCM shares the same location code. This logic
            // is used to determine the DCM number.
            if ( strcmp(l_cur_location_code, l_last_location_code) )
            {
                // Increment of dcm number needed to be skipped
                // for the first DCM set
                if (l_numProcs !=0)
                {
                    l_dcmNum++;
                }

                HDAT_DBG("creating new fruData");
                HdatIoHubFru * fruData = new HdatIoHubFru(l_err,
                                 l_rid,
                                 l_cardType,
                                 0,
                                 l_dcmNum,
                                 l_slcaIdx);
                hdatIoHubFrus.push_back(std::move(fruData));
            }
            else
            {
                HDAT_DBG("adding to existing fruData");
                //once the vector is created then l_hub will be added to the 
                //end of the last fruData object in the vector
            }

            // Preserving the current location code for the next proc
            // comparision
            strcpy(l_last_location_code, l_cur_location_code);
            HDAT_DBG("l_dcmNum: %d", l_dcmNum);

            size_t lastElem = hdatIoHubFrus.size() - 1;
            HDAT_DBG("setting l_hub->hdatIoHubId");
            hdatHubEntry_t *l_hub = reinterpret_cast<hdatHubEntry_t *>
                (reinterpret_cast<char *>(hdatIoHubFrus[lastElem]->iv_hubArray) 
                + hdatIoHubFrus[lastElem]->iv_hubArrayHdr.hdatArrayCnt * 
                sizeof(hdatHubEntry_t));

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
            if(hdatIoHubFrus[lastElem]->iv_hubStatus != 0)    
            {
                // Replace status bits in hdatFlags with iv_hdatStatus
                l_hub->hdatFlags &= ~HDAT_HUB_STATUS_MASK;
                //l_hub->hdatFlags |= fruData->iv_hubStatus;
                l_hub->hdatFlags |= hdatIoHubFrus[lastElem]->iv_hubStatus;
            }
            HDAT_DBG("hdatFlags 1: %X",l_hub->hdatFlags);

            TARGETING::Target *l_pSysTarget = NULL;
            (void) TARGETING::targetService().getTopLevelTarget(l_pSysTarget);

            if(l_pSysTarget == NULL)
            {
                HDAT_ERR("Error in getting Top Level Target");
                assert(l_pSysTarget != NULL);
            }

            TARGETING::ATTR_PROC_MODULE_TYPE_type  l_modType =
                TARGETING::PROC_MODULE_TYPE_GODEL;
            if(!(l_pSysTarget->tryGetAttr<TARGETING::ATTR_PROC_MODULE_TYPE>
                (l_modType)))
            {
                HDAT_ERR("Failed to read ATTR_PROC_MODULE_TYPE for SYS");
            }
            l_hub->hdatModuleId = l_modType;
            HDAT_DBG("Module type: %X",l_modType);

            // Setting the Maximum PCIe Link Training Speed
            l_hub->hdatMaxPCIeLinkSpeed = HDAT_PCIE_MAX_SPEED_GEN5;

            l_hub->hdatEcLvl = l_procEcLevel;
            l_hub->hdatProcChipID = l_procOrdId;
            l_hub->hdatHardwareTopology = l_pProcTarget->
                    getAttr<TARGETING::ATTR_PROC_HW_TOPOLOGY>();
            l_hub->hdatMRID = l_mruId;

            //memory map version
            l_hub->hdatMemMapVersion = 3;

            TARGETING::PredicateHwas l_predHwasFunc;
            TARGETING::PredicateCTM l_pecPredicate (TARGETING::CLASS_UNIT,
                                                    TARGETING::TYPE_PEC);
            TARGETING::PredicatePostfixExpr l_funcPec;
            l_funcPec.push(&l_pecPredicate).push(&l_predHwasFunc).And();

            TARGETING::TargetHandleList l_pecList;

            TARGETING::targetService().getAssociated(l_pecList, l_pProcTarget,
                       TARGETING::TargetService::CHILD,
                       TARGETING::TargetService::ALL,
                       &l_funcPec);

            // Sample values for DCM-0 (Proc-0 and Proc-1)
            // Hub0 : PHB 0,1,2 & 3 : 0xF0
            // Hub1 : PHB 0,1,3,4 & 5 : 0xDC
            uint8_t  l_fab0PresDetect = 0;
            for(uint8_t l_idx = 0; l_idx<l_pecList.size(); ++l_idx)
            {
                TARGETING::Target *l_pecTarget = l_pecList[l_idx];

                TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type l_phbActive =
                    {0};

                //Get PHB Active flag from PEC
                assert( l_pecTarget->
                   tryGetAttr<TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE>(
                      l_phbActive));

                uint8_t l_pecChipUnit = 0;
                assert( l_pecTarget->
                   tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_pecChipUnit));

                //Array count of ATTR_PROC_PCIE_PHB_ACTIVE_BASE is 3
                for(uint8_t l_phbActIdx = 0; l_phbActIdx <
                    sizeof(TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE_type);
                    ++l_phbActIdx)
                {
                    uint8_t l_bitPos = 0;
                    if ((l_phbActive[l_phbActIdx] == 1) && (l_pecChipUnit == 0))
                    {
                        //Filling bit positions 7,6,5
                        l_bitPos = 7 - l_phbActIdx;
                    }
                    else if ((l_phbActive[l_phbActIdx] == 1) &&
                             (l_pecChipUnit == 1))
                    {
                        //Filling bit positions 4,3,2
                        l_bitPos = 4 - l_phbActIdx;
                    }

                    //Only update the value if the active bit has been set
                    if (l_phbActive[l_phbActIdx] == 1)
                    {
                        l_fab0PresDetect = (1 << l_bitPos) | l_fab0PresDetect;
                    }
                }
            }
            l_hub->hdatFab0PresDetect = l_fab0PresDetect;
            HDAT_DBG("hdatFab0PresDetect : 0x%X", l_hub->hdatFab0PresDetect);

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
                TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN5_type
                           l_laneEq5 = {0};

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

                assert( l_phbTarget->
                   tryGetAttr<TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_GEN5>(
                      l_laneEq5));
                memcpy((l_hub->hdatLaneEqPHBGen5 +
                          l_idx*NUM_OF_LANES_PER_PHB),l_laneEq5,
                          NUM_OF_LANES_PER_PHB*2);
            }


            //increment counts
            hdatIoHubFrus[lastElem]->iv_hubArrayHdr.hdatArrayCnt++;
            HDAT_DBG("fruData->iv_hubArrayHdr.hdatArrayCnt=0x%x",
                       hdatIoHubFrus[lastElem]->iv_hubArrayHdr.hdatArrayCnt);
        }//end of the for loop here

        HDAT_DBG("number of fruData objects created=%d",hdatIoHubFrus.size());

        int l_slotMapIndex = 0;
        for(auto fruData : hdatIoHubFrus)
        {
            //build the daughter structure
            HDAT_DBG("calling bldDaughterStruct");
            l_err = 
               fruData->bldDaughterStruct(fruData->iv_hubArrayHdr.hdatArrayCnt);
            if ( l_err )
            {
                HDAT_ERR("error in building daughter structure");
                break;
            }

            //@TODO:RTC Story 255790 : HDAT: SCM verification and support in BMC
            //how to know SCM vs DCM
            //build the slot map info structure
            //Creating slot map info once using the fruData count
            l_err = 
                fruData->bldSlotMapInfoStruct(++l_slotMapIndex,
                    true);//taking DCM by default 
            if ( l_err )
            {
                HDAT_ERR("error in building Slot map info structure");
                break;
            }
            l_totalSlotMapSize += fruData->iv_slotMapInfoObjs.size() *
                             fruData->iv_slotMapInfoSize;
            HDAT_DBG("slotmap size=0x%x",l_totalSlotMapSize);

            l_totKwdSize += fruData->getTotalIoKwdSize();
            HDAT_DBG("got l_totKwdSize=%x",l_totKwdSize);
        }//end for loop

        o_count = hdatIoHubFrus.size();
        HDAT_DBG("setting count o_count=%d",o_count);

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
                               l_childPtrSize + l_totalSlotMapSize;

        uint64_t i_base_addr_down = ALIGN_PAGE_DOWN(i_base_addr);

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
        for(auto fruData : hdatIoHubFrus)
        {
            HDAT_DBG("writing to main memory");
            uint8_t* l_startAddr = l_virtAddr;

            //write to main memory
            l_virtAddr= fruData->setIOHub(l_virtAddr,l_size);

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

        //free up the memory
         for(size_t i=0; i < hdatIoHubFrus.size(); i++)
         {
             delete hdatIoHubFrus[i];
         }
         hdatIoHubFrus.clear();
         

    }while(0);

    HDAT_EXIT();
    return l_err;
}  //end hdatLoadIoData
}
