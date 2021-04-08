/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatiohub.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#ifndef HDATIOHUB_H
#define HDATIOHUB_H

/**
 *  @file hdatiohubfru.H
 *
 *  @brief This file contains the class definition for the I/O hub FRU object.
 *
 */


/*---------------------------------------------------------------------------*/
/* Includes                                                                  */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include <hdat/hdat.H>
#include "hdatutil.H"
#include <hdat/hdat_reasoncodes.H>
#include "hdathdif.H"
#include "hdatvpd.H"
#include <errl/errlentry.H>
#include <vector>
#include<map>


namespace HDAT
{

#define HDAT_PHB_LANES  96
#define NUM_BYTES_PER_LANE 2
#define NUM_LANES_PER_PHB 16
#define HDAT_PROC_EC_DD1 0x10
#define HDAT_PCIE_MAX_SPEED_GEN5 5
const uint16_t HDAT_VPD_VERSION = 0x0020;
const uint16_t HDAT_IO_VERSION = 0x8B;

const uint32_t HDAT_MAX_IO_CHIPS = 10;
const uint32_t HDAT_MAX_SLOT_PER_HUB = 32;


/*---------------------------------------------------------------------------*/
/* Type definitions                                                          */
/*---------------------------------------------------------------------------*/

/** @brief Structure definition for the hub ID data section of the CEC HUB FRU
 *       hypervisor data area.
 *       Reserved bytes are added to make the structure a multiple of 4 bytes.
 *       Adjust the reserved size as necessary if new members are added to this
 *       structure.
 */
struct hdatHubId_t
{
  uint32_t hdatCardType;     // 0x0000 FRU card type
  uint32_t hdatReserved1;    // 0x0004 Formerly Processor Module Id
  uint16_t hdatReserved2;    // 0x0008 Total number of chips on this FRU
                             // and daughter card
  uint8_t  hdatReserved3;    // 0x000A Various flags
  uint8_t  hdatReserved4;    // 0x000B padding for alignment
  uint16_t hdatReserved5;    // 0x000C Hub ID whose passthru port
                             // this FRU is connected to
  uint16_t hdatReserved6;    // 0x000E padding for alignment.
                             //Reuse if another field is added to this structure
}  __attribute__ ((packed));


/** @brief Structure definition for the hub array entry data section of the CEC
 *         HUB FRU hypervisor data area
 */
struct hdatHubEntry_t
{
  hdatMsAddr_t hdatReserved1;       // 0x0000 TCE address for I/O hub
  uint32_t     hdatReserved2;       // 0x0008 Size of I/O hub's TCE
  uint16_t     hdatIoHubId;         // 0x000C I/O hub chip instance number
  uint8_t      hdatFlags;           // 0x000E Chip status
  uint8_t      hdatReserved3;       // 0x000F Reserved
  uint8_t      hdatFab0PresDetect;  // 0x0010 I/O hub chip fabric 0
                                    // presence detect bits
  uint8_t      hdatMaxPCIeLinkSpeed;// 0x0011 Max PCIe Link Training Speed
  uint16_t     hdatModuleId;        // 0x0012 Module type Identification
  uint32_t     hdatEcLvl;           // 0x0014 EC level
  uint32_t     hdatReserved5;       // 0x0018 Affinity domain 2
  uint32_t     hdatReserved6;       // 0x001C Affinity Domain 3
  uint32_t     hdatReserved7;       // 0x0020 Reserved
  uint32_t     hdatReserved8;       // 0x0024 Reserved
  uint32_t     hdatProcChipID;      // 0x0028 Proc Chip ID associated with
                                    // this HUB
  uint32_t     hdatReserved9;       // 0x002C Reserved
  uint32_t     hdatReserved10;      // 0x0030 Reserved
  uint16_t     hdatReserved11;      // 0x0032 Reserved
  uint16_t     hdatHardwareTopology;// 0x0034 Hardware Topology
  uint32_t     hdatMRID;            // 0x0038 MRU ID of Chip
  uint32_t     hdatMemMapVersion;   // 0x003C Memory Map Version
  uint16_t     hdatLaneEqPHBGen3[HDAT_PHB_LANES]; // 0x0040 from PHB0 to PHB5
  uint16_t     hdatLaneEqPHBGen4[HDAT_PHB_LANES]; // 0x0100 Gen4 PHB for PHB 0-5
  uint16_t     hdatLaneEqPHBGen5[HDAT_PHB_LANES]; // 0x01C0 Gen5 PHB for PHB 0-5



  hdatHubEntry_t() : hdatProcChipID(0),  hdatHardwareTopology(0),
  hdatMRID(0xDEADBEEF), hdatMemMapVersion(0xDEADBEEF), hdatLaneEqPHBGen3(),
  hdatLaneEqPHBGen4(), hdatLaneEqPHBGen5()
  {
  }
}  __attribute__ ((packed));

struct hdatSlotMapArea_t
{
    uint16_t   hdatEntryId;
    uint16_t   hdatParentEntryId;
    uint8_t    hdatPHBId;
    uint8_t    hdatEntryType;
    uint8_t    hdatLaneSwapCnfg;
    uint8_t    hdatReserved1;
    uint16_t   hdatLaneMask;
    uint16_t   hdatLaneReversal;
    uint16_t   hdatSLCAIndx;
    uint16_t   hdatSlotIndx;
    uint32_t   hdatEntryFeatures;
    uint8_t    hdatStationId;
    uint8_t    hdatPortNum;
    uint16_t   hdatReserved2;
    uint32_t   hdatSwitchVendorId;
    uint32_t   hdatSwitchDeviceId;
    uint32_t   hdatSubSysVendorId;
    uint32_t   hdatSubSysDeviceId;
    char       hdatSlotName[16];
} __attribute__ ((packed));


struct hdatSlotEntryInfo_t
{
    uint16_t   hdatEntryId;
    uint8_t    hdatMGCLoadSource;
    uint8_t    hdatHddwOrder;
    uint16_t   hdat32MmioSizeInMB;
    uint16_t   hdat64MmioSizeInGB;
    uint16_t   hdat32DMASizeInGB;
    uint16_t   hdat64DMASizeInGB;
    uint8_t    hdatSlotPwrCtrlType;
    uint8_t    hdatPresCtrlType;
    uint8_t    hdatPERSTCtrlType;
    uint8_t    hdatPERSTCtrlGPIOPin;
    uint16_t   hdatMAxPowrSupported;
    uint32_t   hdatSlotCaps;
    uint16_t   hdatMSI;
    uint32_t   hdatI2cIdSlotPwrCtrl;
    uint32_t   hdatI2cSlotPwrPgood;
    uint32_t   hdatI2cCableCardPres;
    uint32_t   hdatI2cCableCardSlotEnable;
    uint32_t   hdatI2cMexFPGA;
    uint32_t   reserved;
} __attribute__ ((packed));

enum hdatSlotMapDataPtrs
{
    HDAT_SLOT_MAP_AREA    = 0,
    HDAT_SLOT_MAP_ENTRY   = 1,
    HDAT_SLOT_MAP_RSVD1   = 2,
    HDAT_SLOT_MAP_RSVD2   = 3,
    HDAT_SLOT_MAP_LAST    = 4
};


/** @enum hdatDataPtrs
 * Constants for the internal data pointers that are added to the base
 * class
 */
enum hdatioDataPtrs
{
    HDAT_FRU_ID           = 0,
    HDAT_ASCII_KWD        = 1,
    HDAT_HUB_ID           = 2,
    HDAT_HUBS_ARRAY       = 3,
    HDAT_PARENT_RESERVED1 = 4,
    HDAT_PARENT_RESERVED2 = 5,
    HDAT_PARENT_LAST      = 6
};

/** @enum hdatChildPtrs
 * Constants for the child structure pointers that are added to the base
 * class
 */
enum hdatioChildPtrs
{
    HDAT_DAUGHTER_CARD   = 0,
    HDAT_SLOT_MAP_INFO   = 1,
    HDAT_CHILD_RESERVED1 = 2,
    HDAT_CHILD_LAST      = 3
};


/*---------------------------------------------------------------------------*/
/* Constants                                                                 */
/*---------------------------------------------------------------------------*/

/** @enum hdatCardType
 *        Enumeration of FRU card types used in the CEC HUB FRU identification
 *        structure
 */
enum hdatCardType
{
  HDAT_IO_HUB_CARD         = 1,
  HDAT_PROC_CARD           = 2,
  HDAT_CEC_BACK_PLANE_CARD = 3,
  HDAT_BACK_PLANE_EXT_CARD = 4
};


/** @enum hdatHubStatus
 *        Status of an I/O hub chip.
 */
enum hdatHubStatus
{
  HDAT_HUB_USABLE        = 0x00,  // Usable, no failures
  HDAT_HUB_FAILURES      = 0x40,  // Usable, failures encountered
  HDAT_HUB_NOT_INSTALLED = 0x80,  // Not installed
  HDAT_HUB_NOT_USABLE    = 0xC0   // Unusable
};


// Bit definitions of the hdatFlags field of hdatHubEntry_t
// that are not included in hdatHubStatus enum.
#define HDAT_HUB_IS_MASTER      0x20  // HUB is the master I/O HUB
#define HDAT_HUB_GARDMASK_VALID 0x08    // for setting gardmask valid
#define HDAT_HUB_SWITCH_MASK_VALID 0x04 // Switch Mask field is valid
#define HDAT_HUB_FABRIC_0_VALID 0x02  // Fabric Bridge 0 Presence Detect
                                      //field is valid
#define HDAT_HUB_FABRIC_1_VALID 0x01  // Fabric Bridge 1 Presence Detect
                                      // field is valid
#define HDAT_HUB_STATUS_MASK    0xC0  // for masking status bits during logical
                                       // and/or ops


// Bit definitions of the hdatFab0PresDetect & hdatFab1PresDetect
// fields of hdatHubEntry_t
#define HDAT_HUB_FAB_BRIDGE_PHB0 0x80 // HUB Fabric Bridge PHB0
                                      //presence detect bit
#define HDAT_HUB_FAB_BRIDGE_PHB1 0x40 // HUB Fabric Bridge PHB1
                                      //presence detect bit
#define HDAT_HUB_FAB_BRIDGE_PHB2 0x20 // HUB Fabric Bridge PHB2
                                      //presence detect bit
#define HDAT_HUB_FAB_BRIDGE_PHB3 0x10 // HUB Fabric Bridge PHB3
                                      //presence detect bit

/*---------------------------------------------------------------------------*/
/* C++ class definition                                                      */
/*---------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatIoHubFru class is used to construct I/O hub FRU objects.
 *         For P8, the CEC Hub FRU refers to the DCM.
 *
 * Description: This class defines a specialized object.  It is not intended
 *              that any component can create an object of this type.
 *              In particular,the object is built only in the
 *              CEC Server process when requested
 *              by the hdat component.
 *
 *              The real purpose of the object is to create the CEC Hub FRU
 *              array structure as defined by the PHYP Initialization
 *              architecture.  This data structure is eventually DMA'd to
 *              main memory.  The class is not defined to be a general purpose
 *              interface for building this object by anyone other than the
 *              CEC Server process.
 *
 * Thread safety:  An HdatIoHubFru object is not thread safe.  That is, a single
 *                 object cannot be shared and used concurrently by multiple
 *                 threads at the same time.  In fact, an object interface is
 *                 used only as a better way to built a flat structure to DMA
 *                 to main memory.
 *
 * Signal handler usage: This class is not intended to be used in a
 *                       signal handler and nothing has been done
 *                       to try and make it safe to use
 *                       in a signal handler.
 *
 * End Class Description
 */
class HdatIoHubFru  : public HdatHdif
{
public:


  /**
   * @brief Construct an HdatIoHubFru object.
   *
   *       This is the constructor for the HdatIoHubFru object when that I/O HUB
   *       is not currently plugged but has been reserved for concurrent
   *       maintenance.
   *
   *       If you are constructing this object on the heap by using new, then
   *       you must check the pointer returned from new to see if it is null.
   *       If it is null, new failed to allocate storage and the constructor
   *       was not called.  If it is not null, then you must check o_errlHndl
   *       to see if the constructor ran successfully.  If o_errlHndl indicates
   *       an error was reported by the constructor, new has already allocated
   *       heap storage and the object must be deleted in order to free the
   *       heap storage.
   *
   * @pre None
   *
   * @post An HdatIoHubFru object has been constructed.
   * Heap storage has been allocated.
   *
   * @param o_errlHndl     - output parameter - If any errors occur,
   *                         the HdatIoHubFru object is NOT constructed
   *                         and errors are returned in this parameter
   *
   * @param i_resourceId   - input parameter RID value for the FRU
   * @param i_cardType     - input parameter - FRU card type
   * @param i_daughterCnt  - input parameter - The count of the number of
   *                         daughter cards
   * @param i_index        - input parameter - instance of the object created
   * @param i_slcaIdx      - input parameter - SLCA index of the FRU
   *
   * @return A null error log handle if successful,else the return code pointed
   *         to by o_errlHndl contains one of:
   *
   * @retval HDAT_ALLOC_ERROR
   */

  HdatIoHubFru(errlHndl_t &o_errlHndl,
               uint32_t i_resourceId,
               hdatCardType i_cardType,
               uint32_t i_daughterCnt,
               uint32_t i_index,
               uint32_t i_slcaIdx);


  /**
   * @brief HdatIoHubFru object destructor
   *
   *        This is the destructor for an HdatIoHubFru object. Any heap storage
   *        allocated for the object is dallocated.
   *
   * @pre No preconditions exist
   *
   * @post The HdatIoHubFru object has been destroyed and can no longer be used.
   *
   */
  ~HdatIoHubFru();



  /**
   * @brief write the data to main memory
   *
   * @param io_virt_addr  - input parameter inputs the address to be
   *                        written at. outputs the next iohub address
   *
   * @param o_size - output parameter - size of iohub data
   *
   * @return A null error log handle if successful,else the return code pointed
   * to by errlHndl_t contains one of the error
   */
  uint8_t * setIOHub(uint8_t * io_virt_addr,
                     uint32_t& o_size);

  /**
   * @brief Add a daughter card description.
   *
   *    Each I/O daughter card which provides part of the I/O path must be added
   *    to the HdatIoHubFru object.  This method adds information about the card
   *
   * @pre None
   *
   * @post A card's VPD definiton has been added to the object.  Heap storage
   *       has been allocated.
   *
   * @param i_resourceId - input parameter -
   *                       VPD resource id for the daughter card FRU
   * @param i_target     - input parameter - TARGET value of the FRU
   * @param i_index      - input parameter - instance number to be added
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by errlHndl_t contains one of:
   *
   * @retval HDAT_ALLOC_ERROR
   * @retval HDAT_ARRAY_ERROR
   */
  errlHndl_t addDaughterCard( uint32_t i_resourceId,
                      TARGETING::Target * i_target, uint32_t i_index);


  /**
   * @brief Build the hypervisor data area structres for I/O hub daughter cards.
   *
   *       Each I/O daughter card which provides part of the I/O path must have
   *       a data structure built for it.
   *
   *       IMPLEMENTATION NOTE.  This is not a generalized method.  For the
   *       Squadrons program, no I/O hubs required daughter card structures
   *       so there was no good way to test the implementation.  When P5IOC2
   *       with Host Ethernet Adapter support came along in eClipz, there was
   *       a need for daughter card structures.  But no other I/O hub type
   *       had this requirement.  So again, no easy way to test a generalized
   *       implementation.  So to simplify the code, this routine is specific
   *       to P5IOC2.  If some other I/O card comes along with a need for
   *       daughter card structures, this rotuine will likely require changes.
   *
   * @pre None
   *
   * @param i_hubArrayNum - input parameter - number of hub array in the hub fru
   *
   * @post A card's VPD definiton has been added to the object.  Heap storage
   *       has been allocated.
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by errlHndl_t contains one of:
   *
   * @retval HDAT_ALLOC_ERROR
   */
  errlHndl_t bldDaughterStruct(uint32_t i_hubArrayNum );

  /**
   * @brief Build the hypervisor data area structres for Slot Map structure.
   *
   *       Each PCIe slot connected to I/O hub will have a datastructure built
   *
   * @pre None
   *
   * @param i_iohubNum - input parameter - tells which iohub object this
   *                                       slotmap is getting built for
   * @param i_dcm   - input parameter - DCM architecture or not
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by errlHndl_t contains one of:
   *
   */

  errlHndl_t bldSlotMapInfoStruct(int i_iohubNum,
                                  bool i_dcm = false);


  errlHndl_t hdatGetSlotMapTableAreas(const char* i_systemType,
      int i_iohubNum, bool i_dcm = false);
  errlHndl_t hdatGetSlotMapEntryInfos(const char* i_systemType,
      int i_iohubNum, bool i_dcm = false);

  /*
   * @brief fetches all the daughter card information for a proc when the
   * TARGET is passed
   *
   * @pre None
   *
   * @param i_target     - input parameter - TARGET value of the FRU
   * @param o_targetList - output parameter - daughter TARGET list
   * @param o_DaughterRids - output parameter - daughter card RID list
   *
   * @post o_DaughterRids is populated with the daughter RID data
   *
   * @return A null error log handle if successful, else the error
   * handle
   */

  errlHndl_t hdatGetDaughterInfoFromTarget(const TARGETING::Target * i_target,
             TARGETING::TargetHandleList& o_targetList,
             std::vector <uint32_t>& o_DaughterRids);



 /* @brief function to get the total keyword size for
  * all the iohub objects
  * @pre None
  * @return the size
  */

  uint64_t getTotalIoKwdSize();


  /* @brief construct the iohub data. This function will be called from
   * the interface. The constructor of iohub will be called inside this
   * function
   *
   * @pre None
   *
   * @param i_msAddr - input parameter - MS address where the io hub data need
   *                                     to be written at
   *
   * @param o_size - output parameter - size of the iohub data
   * @param o_count - output parameter - number of iohub
   *
   * @post The iohub data along with daughter card information is constructed
   * and written to memory
   *
   * @return A null error log handle if successful, else the error
   * handle
   *
   */
  friend errlHndl_t hdatLoadIoData(const hdatMsAddr_t &i_msAddr,
                            uint32_t &o_size,
                            uint32_t &o_count);



  private:
  /** Object Instance Data
   *
   * @li iv_msAddr          - main memory address the final data structure is
   *                          DMA'd to
   * @li iv_hubStatus       - operational status of the IO Hub
   * @li iv_kwdSize         - size of the VPD ASCII keyword
   * @li iv_maxHubs         - maximum number of hub chips that can be added
   *                          with addIoChip()
   * @li iv_maxDaughters    - maximum number of daughter cards that can be
   *                          added with
   *                          addDaughterCard()
   * @li iv_hubArraySize    - total size of the I/O hub array.
   * @li iv_actDaughterCnt  - number of daughter cards added to this object
   * @li iv_maxDaughterSize - maximum size of a daughter card
   * @li iv_kwd             - ptr to the VPD ASCII keyword
   * @li iv_fru             - I/O hub FRU structure
   * @li iv_hubId           - hub FRU ID structure
   * @li iv_hubArrayHdr     - data header for the I/O hub array
   * @li iv_hubArray        - ptr to storage which holds the I/O hub array
   *                          entries
   * @li iv_daughterPtrs    - ptr to one or more ptrs which in turn point to
   *                          HdatVpd objects
   */
  hdatMsAddr_t         iv_msAddr;
  uint8_t              iv_hubStatus;
  uint32_t             iv_kwdSize;
  uint32_t             iv_maxHubs;
  uint32_t             iv_maxDaughters;
  uint32_t             iv_hubArraySize;
  uint32_t             iv_actDaughterCnt;
  uint32_t             iv_maxDaughterSize;
  char                *iv_kwd;
  hdatFruId_t          iv_fru;
  hdatHubId_t          iv_hubId;
  hdatHDIFDataArray_t  iv_hubArrayHdr;
  hdatHubEntry_t      *iv_hubArray;
  HdatVpd            **iv_daughterPtrs;
  std::vector<HdatHdif>     iv_slotMapInfoObjs;
  uint32_t             iv_slotMapInfoSize;
  hdatHDIFDataArray_t  iv_hdatSlotMapAreaArrayHdr;
  hdatHDIFDataArray_t  iv_hdatSlotMapEntryArrayHdr;
  hdatSlotMapArea_t    *iv_hdatSlotMapAreaPtr;
  hdatSlotEntryInfo_t  *iv_hdatSlotMapEntryInfoPtr;

}; // end of HdatIoHubFru class

}  //namespace HDAT

#endif // HDATIOHUB_H
