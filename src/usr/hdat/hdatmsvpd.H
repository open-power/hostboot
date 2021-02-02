/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatmsvpd.H $                                    */
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
#ifndef HDATMSVPD_H
#define HDATMSVPD_H

/**
 *  @file hdatmsvpd.H
 *
 *  @brief This file contains the class definition for the main store
 *  VPD object.
 *
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdint.h>              // standard types
#include <hdat/hdat.H>                // HDAT header type definitions
#include "hdathdif.H"            // HdatHdif base class definition
#include "hdatmsarea.H"          // HdatMsArea class definition
#include <errl/errlentry.H>      // ErrlEntry class
#include "hdatutil.H"

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/** @brief eye catcher for the HDIF header for the mainstore VPD data area
 */
const char HDAT_MSVPD_STRUCT_NAME[] = "MS VPD";
const uint32_t HDAT_NO_MEMORY = 0;
const uint32_t HDAT_MIN_NUM_FOR_SHARING = 2;
const uint32_t HDAT_BITS_PER_BYTE = 8;
const uint32_t HDAT_MB_PER_GB = 1024;
const uint32_t MAX_CHIP_EC_CNT_PER_MSAREA = 2;
const uint32_t HDAT_START_INSTANCE = 0;
const uint32_t HDAT_RHB_MAX_RANGE_ENTRIES = 100;
const uint32_t MAX_DIMMS_PER_MCBIST = 8;

//@TODO:RTC 213230(HDAT Axone additional support)
//Need to revisit the number if needed
//This number needs to be at least as large as the maximum number of OCMBs per
//NODE
const uint32_t HDAT_MAX_MSAREA_P10 = (1     // OCMB per OMI
                                      * 2   // OMI per MCC
                                      * 2   // MCC per MI
                                      * 1   // MI per MC
                                      * 4   // MC per PROC
                                      * 8); // PROC per NODE

/** @brief Structure version number
 */
const uint16_t HDAT_MS_VPD_VERSION = 0x24;

/** @enum hdatDataPtrs
 * Constants for the internal data pointers that are added to the base class
 */
enum hdatMsVpdDataPtrs
{
  HDAT_MS_VPD_MAX_ADDR     = 0,
  HDAT_MS_VPD_MAX_SIZE     = 1,
  HDAT_MS_VPD_PAGE_MOVER   = 2,
  HDAT_MS_VPD_IMT_ADDR_RNG = 3,
  HDAT_MS_VPD_UE_ADDR_RNG  = 4,
  HDAT_MS_VPD_HB_ADDR_RNG  = 5,
  HDAT_MS_VPD_LAST         = 6
};


/** @enum hdatChildPtrs
 *        Constants for the child structure pointers that are added to the base
 *        class
 */
enum hdatMsVpdChildPtrs
{
  HDAT_MS_AREAS        = 0,
  HDAT_MS_CHILD_RESERVED1 = 1,
  HDAT_MS_CHILD_LAST      = 2
};


/*----------------------------------------------------------------------------*/
/* Typedefs                                                                   */
/*----------------------------------------------------------------------------*/

/**
* @brief structure for RAM AREA Information
*
*/
struct hdatRamArea
{
    uint32_t ivHuid;
    bool ivFunctional;
    uint32_t ivSize;
    uint32_t ivfruId;
    hdatRamArea(uint32_t i_huid,
                bool status,
                uint32_t dimmSize,uint32_t i_fruId) :
                ivHuid(i_huid),
                ivFunctional(status),
                ivSize(dimmSize),
                ivfruId(i_fruId) {
                }
};

/** @brief Main store address information
 */
struct hdatMsVpdAddr_t
{
    hdatMsAddr_t hdatMaxAddr;    // 0x0000 Maximum configured mainstore address
    hdatMsAddr_t hdatMaxCcmAddr; // 0x0008 Maximum mainstore address that could
                                 // be configured if memory is added with
                                 // concurrent maintenance
    uint32_t  hdatMstSigAffntyDom; // 0x0010 The affinity domain considered
                                 //most important when making affinity decisions
    hdatMsAddr_t hdatMirrMemStartAddr;//0x0014 Mirrorable MemoryStarting Address
    hdatMsAddr_t hdatHRMORstashLoc;   //0x001C address to HRMOR stash location in HB reserved memory
}  __attribute__ ((packed));


/** @brief Main store size information
 */
struct hdatMsVpdSize_t
{
     uint32_t hdatReserved1; // 0x0000 reserved to make hdatTotSize 8 bytes
                             // in future
     uint32_t hdatTotSize;   // 0x0004 Total configured mainstore size in
                             // mega-bytes
}  __attribute__ ((packed));


/** @brief Page mover information
 */
struct hdatMsVpdPageMover_t
{
     uint32_t     hdatFlags;     // 0x0000 Flags
     uint32_t     hdatLockCnt;   // 0x0004 Count of hardware locks per page
     hdatMsAddr_t hdatLockAddr;  // 0x0008 Hardware lock address
     hdatMsAddr_t hdatMoverAddr; // 0x0010 Page mover address
     hdatMsAddr_t hdatBSRAddr;   // 0x0018 Barrier sync register address
     hdatMsAddr_t hdatXSCOMAddr; // 0x0020 address of XSCOM address range
}  __attribute__ ((packed));


/** @brief In Memory Trace address range array element information
 */
struct hdatMsVpdImtAddrRange_t
{
    hdatMsAddr_t hdatImtAddrRngStrAddr; // 0x0000 Range starting address
    hdatMsAddr_t hdatImtAddrRngEndAddr; // 0x0008 Range ending address+1
}  __attribute__ ((packed));


/** @brief In UE address range array element information - added for bi01
 */
struct hdatMsVpdUEAddrRange_t
{
    hdatMsAddr_t hdatUEAddr; // 0x0000 UE area starting address
}  __attribute__ ((packed));

/** @brief In Reserved Hostboot Memory iaddress range array element information
 */
struct hdatMsVpdRhbAddrRange_t
{
    uint32_t hdatRhbRngType:8;                    // 0x0000 Range type
    uint32_t hdatRhbRngId:24;                     // 0x0001 Range ID
    hdatMsAddr_t hdatRhbAddrRngStrAddr;           // 0x0004 Range starting
                                                  //        address
    hdatMsAddr_t hdatRhbAddrRngEndAddr;           // 0x000C Range ending
                                                  //        address+1
    uint32_t hdatRhbLabelSize;                    // 0x0014 Label size
    uint8_t hdatRhbLabelString[64];               // 0x0018 Label string Ptr
    hdatRhbPermType hdatRhbPermission;            // 0x0058 R/W Permissions
    uint8_t reserved[7];                          // 0x0059 Reserved
}  __attribute__ ((packed));

/** @brief Reserved HB length
 */
const uint16_t HDAT_MS_RHB_LABEL_LEN =
   sizeof(hdatMsVpdRhbAddrRange_t::hdatRhbLabelString);



struct hdatMsVpd_t
{
    hdatMsVpdAddr_t hdatMsAddr;
    hdatMsVpdSize_t hdatMsSize;
    hdatMsVpdPageMover_t hdatPageMover;
    hdatMsVpdImtAddrRange_t hdatImtAddrRange;
    hdatMsVpdUEAddrRange_t  hdatUEAddrRange;
    hdatMsVpdRhbAddrRange_t hdatRhbAddrRange;
}__attribute__ ((packed));

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/* @enum hdatMsAreaStatus
 *       Status of an MS area.
 */
enum hdatMsAreaStatus
{
    HDAT_MEM_INSTALLED      = 0x8000,      // DIMMs are installed
    HDAT_MEM_FUNCTIONAL     = 0x4000,      // DIMMs are functional
    HDAT_MEM_SHARED         = 0x2000       // Memory is shared
};

/* @enum hdatRamStatus
 *       Status of a RAM FRU.
 */
enum hdatRamStatus
{
    HDAT_RAM_NOT_INSTALLED  = 0x0000,      // RAM is NOT installed
    HDAT_RAM_INSTALLED      = 0x8000,      // RAM is installed
    HDAT_RAM_FUNCTIONAL     = 0x4000       // RAM is functional
};

/* @enum hdatMemParentType
 *
 */
enum hdatMemParentType
{
    HDAT_MEM_PARENT_RISER     = 0x8000,   // RISER card
    HDAT_MEM_PARENT_MEMCARD   = 0x4000,   // Memory card
    HDAT_MEM_PARENT_CEC_FRU   = 0x2000,   // Other CEC FRU
    HDAT_MEM_PARENT_HYB_RISER = 0x1000,   // Hybrid RISER card
};

/* @enum hdatBsrMode
 *
 */
enum hdatBsrMode
{
    HDAT_BSR_16_BYTE  = 0x00000000,   //  16 byte BSR mode
    HDAT_BSR_64_BYTE  = 0x02000000,   //  64 byte BSR mode
    HDAT_BSR_128_BYTE = 0x04000000,   // 128 byte BSR mode

    // P7 values
    HDAT_BSR_1M_BYTE  = 0x00000000,   // 1MB BSR mode
    HDAT_BSR_2M_BYTE  = 0x02000000,   // 2MB BSR mode
    HDAT_BSR_4M_BYTE  = 0x04000000,   // 4MB BSR mode
    HDAT_BSR_8M_BYTE  = 0x06000000    // 8MB BSR mode
};




/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatMsVpd class is used to construct a main store VPD object.
 *
 * Description: This class defines a specialized object.  It is not intended
 *              that any component can create an object of this type.
 *              In particular,the object is built only in the CEC Server process
 *              when requested by the hdat component.  And only 1 HdatMsVpd
 *              object can be built.These restrictions are not checked or
 *              enforced by HDAT.
 *
 *              The real purpose of the object is to create the main store
 *              VPD structure as defined by the PHYP Initialization
 *              architecture.  This data structure is eventually DMA'd to
 *              main memory.  The class is not defined to be a general purpose
 *              interface for building this object by anyone other than the
 *              CEC Server process.
 *
 *              Contained within the mainstore VPD object are mainstore area
 *              objects and RAM objects.
 *
 * Thread safety:  An HdatMsVpd object is not thread safe.  That is, a single
 *                 object cannot be shared and used concurrently by multiple
 *                 threads at the same time.  In fact, an object interface is
 *                 used only as a better way to built a flat structure to DMA
 *                 to main memory.
 *
 * Signal handler usage: This class is not intended to be used in a signal
 *                  handler and nothing has been done to try and make it safe
 *                  to use in a signal handler.
 *
 * End Class Description
 */
class HdatMsVpd : public HdatHdif
{
    public:

        /**
         * @brief Construct an HdatMsVpd object.
         *
         *  This is the constructor for the HdatMsVpd object.
         *
         *  If you are constructing this object on the heap by using new, then
         *  you must check the pointer returned from new to see if it is null.
         *  If it is null, new failed to allocate storage and the constructor
         *  was not called.  If it is not null, then you must check o_errlHndl
         *  to see if the constructor ran successfully.  If o_errlHndl indicates
         *  an error was reported by the constructor, new has already allocated
         *  heap storage and the object must be deleted in order to free the
         *  heap storage.
         *
         * @pre None
         *
         * @post An HdatMsVpd object has been constructed.Heap storage has been
         * allocated.
         *
         * @param[out] o_errlHndl  - If any errors occur, the HdatMsVpd object
         *                      is NOT constructed and errors are returned in
         *                      this parameter
         * @param[in] i_msAddr    - The main memory address that the main
         *                      store VPD structure will be DMA'd to.
         *
         * @return A null error log handle if successful, else the return code
         *      pointed to by o_errlHndl.
         *
         */
        HdatMsVpd(errlHndl_t &o_errlHndl,const hdatMsAddr_t &i_msAddr);

        /**
         * @brief HdatMsVpd object destructor
         *
         * This is the destructor for an HdatMsVpd object.  Any heap storage
         * allocated for the object is dallocated.
         *
         * @pre No preconditions exist
         *
         * @post The HdatMsVpd object has been destroyed and can no longer be
         * used.
         *
         */
        virtual ~HdatMsVpd();

	    /**
         * @brief Update the mainstore VPD to specify a memory address range for
         *  the In Memory Trace tool.  More than one address range can be added.
         *
         * @post An address range entry has been added.
         *
         * @param[in] i_start     - The starting address of the range
         * @param[in] i_end       - The ending address of the range + 1
         *
         * @return A null error log handle if successful, else the return code
         * pointed to by o_errlHndl contains one of:
         *
         * @retval HDAT_ARRAY_ERROR
         */
        errlHndl_t addIMTAddrRange(hdatMsAddr_t &i_start,
                                   hdatMsAddr_t &i_end);

	    /**
         * @brief Update the mainstore VPD to specify a memory address range for
         *        UE areas.  More than one address range can be added. Added for
         *        bi01.
         *
         * @post An address range entry has been added.
         *
         * @param[in] i_addr  - The starting address of the range
         *
         * @return A null error log handle if successful, else the return code
         * pointed to by o_errlHndl contains one of:
         *
         * @retval HDAT_ARRAY_ERROR
         */
        errlHndl_t addUEAddrRange(hdatMsAddr_t &i_addr);

        /**
         * @brief Update the mainstore VPD to specify a memory address range for
         *        host boot reserver.
         *
         * @post An address range entry has been added.
         *
         * @param[in] i_dbobId         - DBOB ID
         * @param[in] i_start          - The starting address of the range
         * @param[in] i_end            - The end address of the range
         * @param[in] i_labelSize      - RHB Label Size
         * @param[in] i_labelStringPtr - RHB Label String
         * @param[in] i_permission     - R/W permissions for RHB.
         *
         * @return A null error log handle if successful, else the return code
         * pointed to by o_errlHndl contains one of:
         *
         * @retval HDAT_ARRAY_ERROR
         */

        errlHndl_t addRHBAddrRange( uint32_t i_dbob_id, hdatMsAddr_t &i_start,
                                    hdatMsAddr_t &i_end, uint32_t i_labelSize,
                                    uint8_t* &i_labelStringPtr,
                                    hdatRhbPermType i_permission =
                                        HDAT::RHB_READ_WRITE);

        /**
         * @brief Update the mainstore VPD with Barrier Synchronization Register
         * information
         *
         * Note: If the Barrier Synchronization Register is NOT enabled, this
         *        method does not have to be called.
         *
         * @pre None
         *
         * @post None
         *
         * @param[in] i_bsrAddr - Address of memory mapped BSR
         * @param[in] i_bsrMode - Mode the BSR is initialized to
         */
        void setBSR(const hdatMsAddr_t &i_bsrAddr,
                     hdatBsrMode i_bsrMode = HDAT_BSR_128_BYTE);


        /**
         * @brief Update the mainstore VPD with address of XSCOM
         *
         *        Note: If the XSCOM address is NOT supported, this
         *        method does not have to be called.
         *
         * @pre None
         *
         * @post None
         *
         * @param[in] i_xscomAddr - Address of XSCOM address range
         */
        void setXSCOM(const hdatMsAddr_t &i_xscomAddr);


        /**
         * @brief Add a main store area FRU.
         *
         *  Each main store area FRU which contains memory must be added to the
         *  HdatMsVpd object.  This method adds information about the FRU.
         *
         * @pre One cannot add any more mainstore area FRUs than was specified
         * by the i_msAreaCnt parameter on the HdatMsVpd constructor.
         *
         * @post A main store area FRU has been added to the object.
         * Heap storage has been allocated.
         *
         * @param[in] i_resourceId - The FRU's resource id
         * @param[in] i_msAreaId   - A unique id for each main store area
         * associated with a mainstore VPD object.  The id starts at
         *                       0 and is incremented by 1 for each new
         *                       mainstore area.
         * @param[in] i_ramCnt     - The number of RAM objects that will be
         *                       added to the mainstore area.  If an exact count
         *                       cannot be computed, a maximum number can be
         *                       provided.
         * @param[in] i_chipEcCnt  - The number of EC entries that will be
         * added to the mainstore area. If an exact count cannot be
         *                       computed, a maximum number can be provided.
         * @param[in] i_addrRngCnt - The number of address range entries that
         *                       will be added to the mainstore area.  If an
         *                       exact count cannot be computed, a maximum
         *                       number can be provided.
         *
         * @return A null error log handle if successful, else the return code
         *      pointed to by errlHndl_t contains one of:
         *
         * @retval HDAT_ALLOC_ERROR
         * @retval HDAT_ARRAY_ERROR
         */
        errlHndl_t addMsAreaFru(uint32_t i_resourceId,
                                uint32_t i_slcaIndex,
                                TARGETING::Target * i_target,
                                uint16_t i_msAreaId,
                                uint32_t i_ramCnt,
                                uint32_t i_chipEcCnt,
                                uint32_t i_addrRngCnt);


        /**
         * @brief Update the mainstore area to specify the type of memory.
         *
         * @pre The i_msAreaId parameter must be for a valid mainstore area that
         *  was added with the addMsAreaFru() method.  HDAT does not check or
         *  enforce that this is a valid main store area ID.
         *
         * @post None
         *
         * @param[in] i_msAreaId - A unique id for each main store area
         *                     associated with a mainstore VPD object.  The id
         *                     identifies the mainstore area that is to be
         *                     updated.
         * @param[in] i_type     - This specifies the type of memory card
         *                     for this mainstore area.
         */
        void setMsAreaType(uint16_t i_msAreaId,
                           hdatMemParentType i_type);


        /**
         * @brief Update the mainstore area to specify the status of the memory
         * DIMMS
         *
         * @pre The i_msAreaId parameter must be for a valid mainstore area that
         * was added with the addMsAreaFru() method.HDAT does not check or
         * enforce that this is a valid main store area ID.
         *
         * @post None
         *
         * @param[in] i_msAreaId - A unique id for each main store area
         *                  associated with a mainstore VPD object.  The id
         *                  identifies the mainstore area that is to be updated.
         * @param[in] i_status   - See the hdatMsAreaStatus enum.  The value
         *                     specified here can be a bitwise OR of the enum
         *                     values.
         */
        void setMsAreaStat(uint16_t i_msAreaId,
                           uint16_t i_status);


        /**
         * @brief Update the mainstore area with an id for interleaved memory
         *
         * @pre The i_msAreaId parameter must be for a valid mainstore area that
         *  was added with the addMsAreaFru() method.HDAT does not check or
         *  enforce that this is a valid main store area ID.
         *
         * @post None
         *
         * @param[in] i_msAreaId - A unique id for each main store area
         *                   associated with a mainstore VPD object.  The id
         *                   identifies the mainstore area that is to be updated
         * @param[in] i_id  - An identifier from 0 to N which is the same
         *                  for each MS area which is interleaved.  In
         *                  addition, the HDAT_MEM_SHARED status attribute
         *                  must have been used for this
         *                  MS area when setMsAreaStat() was called.
         */
        void setMsAreaInterleavedId(uint16_t i_msAreaId,
                                    uint16_t i_id);


        /**
         * @brief Update the mainstore area to specify the total size of the
         *      mainstore area.
         *
         * @pre The i_msAreaId parameter must be for a valid mainstore area that
         *  was added with the addMsAreaFru() method.  HDAT does not check or
         *  enforce that this is a valid main store area ID.
         *
         * @post None
         *
         * @param[in] i_msAreaId - A unique id for each main store area
         *                     associated with a mainstore VPD object. The id
         *                     identifies the mainstore area that is to be
         *                     updated.
         * @param[in] i_size  - The total size of the configured mainstore
         *                     area in megabytes.  It is the (high address of
         *                     the mainstore area + 1 minus the low address of
         *                     the mainstore area) divided by 1 megabyte.
         */
        void setMsAreaSize(uint16_t i_msAreaId,
                           uint32_t i_size);


        /**
         * @brief Update the mainstore area to specify associated processor id
         *
         * @pre The i_msAreaId parameter must be for a valid mainstore area that
         *   was added with the addMsAreaFru() method.  HDAT does not check or
         *   enforce that this is a valid main store area ID.
         *
         * @post None
         *
         * @param[in] i_msAreaId  - A unique id for each main store area
         *                         associated with a mainstore VPD object.
         *                         The id identifies the mainstore area that is
         *                         to be updated.
         * @param[in] i_moduleId   - The Module Id of the processor
         *                         associated with this mainstore area.
         */
        void setMsAreaModuleId(uint16_t i_msAreaId,
                               uint32_t i_moduleId);


        /**
         * @brief Update the mainstore area to specify the affinity domain
         *
         * @pre The i_msAreaId parameter must be for a valid mainstore area that
         *  was added with the addMsAreaFru() method.  HDAT does not check or
         *  enforce that this is a valid main store area ID.
         *
         * @post None
         *
         * @param[in] i_msAreaId  - A unique id for each main store area
         *                         associated with a mainstore VPD object.
         *                         The id identifies the mainstore area that is
         *                         to be updated.
         * @param[in] i_affinityDomain - The affinity domain
         *                           associated with this mainstore area.
         */
        void setMsAreaAffinityDomain(uint16_t i_msAreaId,
                                     uint32_t i_affinityDomain);


        /**
         * @brief Update the mainstore area to specify the memory address range
         *        More than one address range can be added.
         *
         * @pre The i_msAreaId parameter must be for a valid mainstore area that
         *  was added with the addMsAreaFru() method.  HDAT does not check or
         *  enforce that this is a valid main store area ID.
         *
         * @post None
         *
         * @param[in] i_msAreaId  - A unique id for each main store area
         *                       associated with a mainstore VPD object.  The id
         *                       identifies the mainstore area that is to be
         *                       updated.
         * @param[in] i_start   - The starting address of the range
         * @param[in] i_end     - The ending address of the range + 1
         * @param[in] i_procChipId - which is the chip id of the physical
         *                          processor
         * @param[in] i_rangeIsMirrorable - Specifies whether the range is
         *                              mirrorable
         * @param[in] i_mirroringAlgorithm - Specifies hardware mirroring
         *                               algorithm to use
         * @param[in] i_startMirrAddr - Specifies the starting mirrorable
         *                          address for range
         * @param[in] i_hdatMemCntlID - Memory Controller ID
         * @param[in] i_hdatSmf - Whether the range is in SMF memory
         *
         * @return A null error log handle if successful, else the return code
         * pointed to by errlHndl_t contains one of:
         *
         * @retval HDAT_ARRAY_ERROR
         */
        errlHndl_t addMsAreaAddr(uint16_t i_msAreaId,
                                 hdatMsAddr_t &i_start,
                                 hdatMsAddr_t &i_end,
                                 uint32_t i_procChipId,
                                 bool i_rangeIsMirrorable = false,
                                 uint8_t i_mirroringAlgorithm = 0,
                                 uint64_t i_startMirrAddr = 0,
                                 uint32_t i_hdatMemCntlID = 0,
                                 bool i_hdatSmf = false);

        /**
         * @brief Update the mainstore area to specify a mmio memory address
         *        range. More than one address range can be added.
         *
         * @pre One cannot add any more address range entries than the
         *      maximum supported limit.
         *
         * @post An address range entry has been added.
         *
         * @param[in] i_start      - The starting address of the range
         * @param[in] i_end        - The ending address of the range
         * @param[in] i_rangeSize  - MMIO address range size
         * @param[in] i_mmioMemCntlId - Memory Controller ID
         * @param[in] i_mmioProcPhyChipId - which is the chip id of the physical
         *                                  processor
         * @param[in] i_mmioHbrtChipId - MMIO HBRT Chip ID
         * @param[in] i_mmioFlags -  MMIO flags
         *
         * @return A null error log handle if successful, else the return code
         *         pointed to by o_errlHndl indicates that the mmio array size
         *         crossed the maximum allowed limit
         *
         * @retval RC_ERC_MAX_EXCEEDED
         */

         errlHndl_t addMsAreaMmioAddrRange(uint16_t i_msAreaId,
                                           hdatMsAddr_t &i_start,
                                           hdatMsAddr_t &i_end,
                                           uint32_t i_mmioMemCntlId,
                                           uint32_t i_mmioProcPhyChipId,
                                           uint64_t i_mmioHbrtChipId,
                                           uint64_t i_mmioFlags);

        /**
         * @brief Add engineering change information for memory interface chips
         *
         * @pre The first EC entry added must be for the memory controller.
         * HDAT has no way of validating or enforcing this so it is up to the
         * user of the method to do this correctly.
         *
         *      The i_msAreaId parameter must be for a valid mainstore area that
         *      was added with the addMsAreaFru() method.HDAT does not check or
         *      enforce that this is a valid main store area ID.
         *
         * @post One cannot add any more engineering change entries than was
         * specified by the i_chipEcCnt parameter on the addMsAreaFru method.
         *
         * @param[in] i_msAreaId -A unique id for each main store area
         *                     associated with a mainstore VPD object.  The id
         *                     identifies the mainstore area that is to be
         *                     updated.
         * @param[in] i_manfId  - Chip's manufacturing id
         * @param[in] i_ecLvl   - Chip's engineering change level
         *
         * @return A null error log handle if successful, else the return code
         * pointed to by errlHndl_t contains one of:
         *
         * @retval HDAT_ARRAY_ERROR
         */
        errlHndl_t addEcEntry(uint16_t i_msAreaId,
                              uint32_t i_manfId,
                              uint32_t i_ecLvl);

        /**
         * @brief Update the mainstore area to specify the host I2C device info
         *
         * @pre The i_msAreaId parameter must be for a valid mainstore area that
         *      was added with the addMsAreaFru() method.  HDAT does not check
         *      or enforce that this is a valid main store area ID.
         *
         * @post None
         *
         * @param[in] i_msAreaId - A unique id for each main
         *                         store area associated with a mainstore VPD
         *                         object.  The id identifies the mainstore area
         *                         that is to be updated.
         * @param[in] i_I2cDevEntries - host I2c device info
         */
        void setMsaI2cInfo(uint16_t i_msAreaId,
            std::vector<hdatI2cData_t>& i_I2cDevEntries);

        /**
         * @brief Add a RAM area FRU.
         *
         *   After a mainstore area has been added to the mainstore VBPD object,
         *   one or more RAM FRUs must be added to the mainstore area.
         *
         * @pre A mainstore area must have been previously created so this RAM
         *  area can be added to it.
         *
         *      The i_msAreaId parameter must be for a valid mainstore area that
         *      was added with the addMsAreaFru() method.  HDAT does not check
         *      or enforce that this is a valid main store area ID.
         *
         * @post A RAM card's VPD definiton has been added to the object.  Heap
         * storage has been allocated.
         *
         * @param[in] i_msAreaId - The id of the mainstore area this
         *                       RAM is associated with
         * @param[in] i_resourceId - VPD resource ID for the RAM FRU.
         * @param[in] i_slcaIndex - SLCA index of ms area
         * @param[in] i_ramId     - RAM area identifier; a number from 0 to N
         * @param[in] i_status    - staus of the DIMMS and is the bitwise OR of
         *                       values from hdatRamStatus defined above
         * @param[in] i_size     -the total size of configured mainstore in this
         *                       RAM area
         * @param[in] i_dimmId   - Dimm ID with bit positions signifying the target
         *                         positions in the affinity path
         * @param[in] i_dimmCurFreq - Current operating dimm frequency
         *
         * @return A null error log handle if successful, else the return code
         *  pointed to by errlHndl_t contains one of:
         *
         * @retval HDAT_ALLOC_ERROR
         * @retval HDAT_ARRAY_ERROR
         */
        errlHndl_t addRamFru(uint16_t i_msAreaId,
                            TARGETING::Target * i_target,
                             uint32_t i_resourceId,
                             uint32_t i_slcaIndex,
                             uint16_t i_ramId,
                             uint16_t i_status,
                             uint32_t i_size,
                             uint32_t i_dimmId,
                             uint32_t i_dimmCurFreq);
        /**
         * @brief Initialization of HdatMsVpd object.
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
         * @post An HdatMsVpd object has been initialized.  Heap storage has
         * been allocated.
         *
         * @param[in] i_maxMsAddr  - maximum configured main store address
         * @param[in] i_maxMsCcmAddr - maximum main store address that could be
         *                         configured if memory was added with
         *                         concurrent maintenance.If concurrent
         *                         maintenance cannot be performed on this
         *                         machine,this parameter has the same value as
         *                         i_maxMsAddr.
         * @param[in] i_msSize   - total size of configured main store in
         *                         mega-bytes. (number of mega-bytes from lowest
         *                         main store address to highest main store
         *                         address minus the number of mega-bytes of a
         *                         ddress holes)
         * @param[in] i_msAreaCnt  The count of the number of main store areas
         *                         that will be defined by using the
         *                         addMsAreaFru() method below.If the actual
         *                         count cannot be derived when this object is
         *                         constructed, a maximum count can be supplied.
         * @param[in] i_MostSigAffinityDomain -most significant affinity domain.
         *                         The affinity domain considered most important
         *                         when making affinity decisions.  The value is
         *                         model dependent.
         * @param[in] i_ueAreaCnt - Maximum number of UE Address ranges
         * @param[in] i_MirrMemStartAddr - The address of the start of
         *                         mirrorable memory
         *
         */
        void hdatInit(hdatMsAddr_t &i_maxMsAddr,
                         hdatMsAddr_t &i_maxMsCcmAddr,
                         uint32_t i_msSize,
                         uint32_t i_msAreaCnt,
                         uint32_t i_MostSigAffinityDomain,
                         uint32_t i_ueAreaCnt,
                         uint64_t i_MirrMemStartAddr);

        /**
         * @brief Gather MS data for HDAT
         *  @par Description:
         *   This function collects various MS attributes and fills MS Data area
         *
         * @param[in] o_size - total size written
         * @param[in] o_count - total count of ms vpd instance
         *
         * @return A null error log handle if successful, else the return code
         * pointed to by o_errlHndl contains one of:
         *
         * @retval HDAT_ARRAY_ERROR
         */
        errlHndl_t  hdatLoadMsData(uint32_t &o_size, uint32_t &o_count);

        /**
         * @brief Gets maximum configured memory address
         *
         * @param[in] i_model Target model
         *
         * @return value of  ms address
         */
        uint64_t hdatGetMaxMemConfiguredAddress(
            TARGETING::ATTR_MODEL_type i_model);

        /**
         * @brief Fetches the group of MC
         *
         * @param[in] i_pTarget Proc target
         * @param[in] i_pMcsTarget MCS target
         * @param[out] o_groupOfMc MC group value
         *
         * @return Success or failure
         */
        bool hdatFindGroupForMc(const TARGETING::Target *i_pProcTarget,
                            const TARGETING::Target *i_pMcsTarget,
                            uint32_t& o_groupOfMc);

        /**
         * @brief Fetches the group of MCC
         *
         * @param[in] i_pTarget Proc target
         * @param[in] i_pMccTarget MCC target
         * @param[out] o_groupOfMcc MCC group value
         *
         * @return Success or failure
         */
        bool hdatFindGroupForMcc(const TARGETING::Target *i_pProcTarget,
                            const TARGETING::Target *i_pMccTarget,
                            uint32_t& o_groupOfMcc);

        /**
         * @brief Get the DIMMS list present on the system
         *
         * @param[in] i_pTarget Mca target
         * @param[in] i_pMcsTarget Mcs target
         * @param[in] i_membufFruid - membuf fruid decides the parent type
         * @param[out] o_areas list of ram area structure based on the DIMM
         * present.
         * @param[out] o_areaSize - Total DIMM size
         * @param[out] o_dimmNum - Total DIMM number
         * @param[out] o_areaFunctional - DIMM functional status
         * @param[out] o_parentType - memory parent type based on whether
         *              the dimms are pluggable or soldered
         *
         * @return A null error log handle if successful, else the return the
         * error handle
         */
        errlHndl_t hdatScanDimms(const TARGETING::Target *i_pTarget,
                         const TARGETING::Target *i_pMcsTarget,
                         uint32_t i_membufFruid,
                         std::list<hdatRamArea>& o_areas,
                         uint32_t& o_areaSize,
                         uint32_t& o_dimmNum,
                         bool& o_areaFunctional,
                         hdatMemParentType& i_parentType);

        /**
         * @brief Get the DIMMS list present on the P10 system
         *
         * @param[in] i_pTarget OCMB Chip target
         * @param[out] o_areas list of ram area structure based on the DIMM
         * present.
         * @param[out] o_areaSize - Total DIMM size
         * @param[out] o_dimmNum - Total DIMM number
         * @param[out] o_areaFunctional - DIMM functional status
         * @param[out] o_parentType - memory parent type based on whether
         *              the dimms are pluggable or soldered
         *
         * @return A null error log handle if successful, else the return the
         * error handle
         */
        errlHndl_t hdatScanDimmsP10(const TARGETING::Target *i_pOcmbTarget,
                         std::list<hdatRamArea>& o_areas,
                         uint32_t& o_areaSize,
                         uint32_t& o_dimmNum,
                         bool& o_areaFunctional,
                         hdatMemParentType& i_parentType);

        /**
         * @brief Get max memory blocks connected to membuf
         *
         * @param[in] i_pTarget Mcs target
         * @param[out] o_maxMemoryBlocks - max memory block value
         *
         * @return A null error log handle if successful, else the return the
         * error handle
         */
        errlHndl_t  hdatGetMaxMemoryBlocks(const TARGETING::Target *i_pTarget,
                                   uint32_t &o_maxMemoryBlocks);

        /**
         * @brief Write the data to Mainstore area space
         *
         * @param[in] i_addr - MS address
         * @param[in] i_size - total size to be written
         *
         */
        void commit(void * i_addr,uint32_t i_size);

        /**
         * @brief Get total size of MS data to be written
         *
         * @param[out] o_size - total size value
         *
         */
         void getTotalSize(uint32_t &o_size);

        /**
         * @brief Print an HdatMsVpd object.
         *
         * This method is a debug mthod which prints out a mainstore VPD object.
         *
         * @pre None
         *
         * @post None
         *
         */
        void prt();

    protected:

        /**
         * @brief After all MS area objects have been created, this routine must
         *   be called to see if they are all the same size.If they are not, the
         *        smaller one(s) will be adjusted with padding so they are all
         *        the same size.
         *
         *        This is required because PHYP traverses through the MS areas
         *        as entries in an array.
         *
         * @pre All MS area objects must have been created
         *
         * @post Some objects' size may be adjusted
         *
         */
        void adjustMsAreaObjects();


    private:


        /** Object Instance Data
         *
         * @li iv_msAddr       - main memory address the final data structure is
         *                       DMA'd to
         * @li iv_actMsAreaCnt - actual count of main store areas that are added
         * @li iv_maxMsAreaCnt - maximum count of main store areas that can be
         *                       added
         * @li iv_maxAddr      - maximum main store addresses
         * @li iv_maxSize      - maximum main store size
         * @li iv_mover        - page mover information
         * @li iv_msAreaPtrs   - ptr to one or more ptrs which in turn point to
         *                       HdatMsArea objects
         * @li iv_IMTaddrRngArrayHdr - In memory trace address range header
         * @li iv_IMTaddrRangeArray - In memory trace address range array
         * @li iv_UEaddrRngArrayHdr - UE address range header
         * @li iv_UEaddrRangeArray -  UE address range array
         * @li iv_maxUEAddrRngCnt - Max UE address range count
         * @li iv_RHBaddrRngArrayHdr - Reserved host boot address range header
         * @li iv_RHBaddrRangeArray - Reserved host boot address range array
         * @li iv_maxRHBAddrRngCnt - Max RHB address range count
         * @li iv_virtAddr          - virtual address
         */
        hdatMsAddr_t             iv_msAddr;
        uint32_t                 iv_actMsAreaCnt;
        uint32_t                 iv_maxMsAreaCnt;
        hdatMsVpdAddr_t          iv_maxAddr;
        hdatMsVpdSize_t          iv_maxSize;
        hdatMsVpdPageMover_t     iv_mover;
        HdatMsArea             **iv_msAreaPtrs;
        hdatHDIFDataArray_t      iv_IMTaddrRngArrayHdr;
        hdatMsVpdImtAddrRange_t *iv_IMTaddrRangeArray;
        uint32_t                 iv_maxIMTAddrRngCnt;
        hdatHDIFDataArray_t      iv_UEaddrRngArrayHdr;
        hdatMsVpdUEAddrRange_t  *iv_UEaddrRangeArray;
        uint32_t                 iv_maxUEAddrRngCnt;
        hdatHDIFDataArray_t      iv_RHBaddrRngArrayHdr;
        hdatMsVpdRhbAddrRange_t *iv_RHBaddrRangeArray;
        uint32_t                 iv_maxRHBAddrRngCnt;
        void                    *iv_virtAddr;


        /** Class (static) Data
         *
         * Only one copy of this data exists in a process.
         *
         * @li cv_actualCnt - a count of how many HdatMsVpd objects are created
         */
        static uint32_t cv_actualCnt;

}; // end of HdatMsVpd class

}

#endif // HDATMSVPD_H
