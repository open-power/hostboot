/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatmsarea.H $                                   */
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
#ifndef HDATMSAREA_H
#define HDATMSAREA_H

/**
 *  @file hdatmsarea.H
 *
 *  @brief This file contains the class definition for the mainstore areas.
 *         This structure is part of the larger mainstore VPD structure
 *         which describes the various chips which make up the memory subsystem.
 *
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdint.h>              // standard types
#include <hdat/hdat.H>                // HDAT header type definitions
#include "hdathdif.H"            // HdatHdif base class definition
#include "hdatram.H"             // HdatRam class definition
#include <errl/errlentry.H>      // ErrlEntry class
#include "hdatutil.H"

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

const uint16_t HDAT_MS_AREA_VERSION = 0x50;
const char HDAT_MSAREA_STRUCT_NAME[] = "MSAREA";

/** @brief Since the size of each MS Area must the same as all others, the
 *         total size of the EC level array and the address range array must
 *         be the same in each MS area.  The constants below are the result of
 *         a bug found during initial PHYP bringup when several MS areas were
 *         built with different sizes.  We always reserve enough space for the
 *         maximum number of array entries since we don't know in advance how
 *         many entries will actually be added.
 */
const uint32_t HDAT_MAX_EC_ENTRIES = 5;
const uint32_t HDAT_MAX_ADDR_RNG_ENTRIES = 4;
const uint32_t HDAT_MAX_MMIO_ADDR_RNG_ENTRIES = 4;

 /** @enum hdatDataPtrs
 *  Constants for the internal data pointers that are added to the base class
 */
enum hdatMsAreaDataPtrs
{
    HDAT_MS_AREA_FRU_ID        =  0,
    HDAT_MS_AREA_KWD           =  1,
    HDAT_MS_AREA_ID            =  2,
    HDAT_MS_AREA_SIZE          =  3,
    HDAT_MS_AREA_ADDR_RNG      =  4,
    HDAT_MS_AREA_AFF           =  5,
    HDAT_MS_AREA_EC_ARRAY      =  6,
    HDAT_MS_AREA_MMIO_ADDR_RNG =  7,
    HDAT_MS_AREA_LAST          =  8
};


/*----------------------------------------------------------------------------*/
/* Typedefs                                                                   */
/*----------------------------------------------------------------------------*/

/** @brief Structure definition for the main store area id and status.
    Reserved bytes are added to make the structure a multiple of 4 bytes.
    Adjust the reserved size as necessary if new members are added to this
    structure.
 */
struct hdatMsAreaId_t
{
    uint16_t hdatMsAreaId;       // 0x0000 Identifier for this mainstore area
    uint16_t hdatMsAreaParentType; // 0x0002 Memory parent type
    uint16_t hdatMsAreaStatus;   // 0x0004 Status
    uint16_t hdatInterleavedId;  // 0x0006 Id for MS areas which are interleaved
    uint32_t hdatFsiDevicePathLen; // 0x0008 FSI Device Path – Actual Length
    uint8_t  hdatFsiDevicePath[64];// 0x000C FSI Device Path
}  __attribute__ ((packed));


/** @brief Structure definition for the size of the main store area
 */
struct hdatMsAreaSize_t
{
    uint32_t hdatReserved1;  // 0x0000 Reserved to make hdatMsAreaSize 8 bytes
                             // in future
    uint32_t hdatMsAreaSize; // 0x0004 Total size of the configured main store
                             // in mega-bytes
}  __attribute__ ((packed));

/** @brief Structure definition for Selective Memory Mirroring attributes field
 */
struct hdatSMMAttributes_t
{
    uint8_t hdatRangeIsMirrorable;  // 0x0000 Memory range is mirrorable
    uint8_t hdatMirroringAlgorithm; // 0x0001 Hardware mirroring algorithm to
                                      // use
    uint8_t hdatIsSMFmemory;        // 0x0002 SMF memory region
    uint8_t hdatReserved;           // 0x0003
}  __attribute__ ((packed));


/** @brief Structure definition for an array of main store area address ranges
 */
struct hdatMsAreaAddrRange_t
{
    hdatMsAddr_t hdatMsAreaStrAddr;   // 0x0000 Range starting address
    hdatMsAddr_t hdatMsAreaEndAddr;   // 0x0008 Range ending address+1
    uint32_t     hatMsAreaProcChipId; // 0x0010 Processor physical chip id
                                      // associated with this address range
    hdatSMMAttributes_t hdatSMMAttributes; // 0x0014 SMM Attributes
    hdatMsAddr_t      hdatStartMirrAddr;   // 0x0018 Starting Mirrorable Address
                                          // for range
    uint32_t     hdatMsAreaMemCntId;  // 0x0020 Memory Controller ID
}  __attribute__ ((packed));


/** @brief Structure definition for the processor affinity
 */
struct hdatMsAreaAffinity_t
{
    uint32_t hdatMsAreaModuleId;   // 0x0000 Processor Module ID associated
                                   //        with this mainstore area
    uint32_t hdatMsAffinityDomain; // 0x0004 Affinity Domain
}  __attribute__ ((packed));


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/** @enum hdatMsAreaChildPtrs
 *        Constants for the child structure pointers that are added to the base
 *        class
 */
enum hdatMsAreaChildPtrs
{
    HDAT_MS_AREA_RAM_AREAS       = 0,
    HDAT_MS_AREA_CHILD_RESERVED1 = 1,
    HDAT_MS_AREA_CHILD_LAST      = 2
};


/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatMsArea class is used to construct objects which describe
 *         main store areas.
 *
 * Description: This class defines a specialized object.  It is not intended
 *              that anyone can create an object of this type.  In particular,
 *              the object is built only in the hdatstep process when the step
 *              that builds hypervisor data structures is run.
 *
 *          The real purpose of the object is to create the various main store
 *          area structures as defined by the PHYP Initialization architecture
 *          This data structure is eventually DMA'd to main memory.  The
 *          class is not defined to be a general purpose interface for
 *          building this object by anyone other than the hdatstep process.
 *
 * Thread safety:  An HdatMsArea object is not thread safe.  That is, a single
 *                 object cannot be shared and used concurrently by
 *                 multiple threads at the same time.  An object can be used by
 *                 multiple threads if the threads serialize access.  And of
 *                 course, each thread can use its own object with no concerns
 *                 about what other threads are doing.
 *
 * Signal handler usage: This class is not intended to be used in a signal
 * handler and nothing has been done to try and make it safe to use
 * in a signal handler.
 *
 * End Class Description
 */
class HdatMsArea : public HdatHdif
{
public:

  /**
   * @brief Construct an HdatMsArea object.
   *
   *       This is the constructor for the HdatMsArea object.
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
   * @post An HdatMsArea object has been constructed.
   *     Heap storage has been allocated.
   *
   * @param[out] o_errlHndl - If any errors occur, the HdatMsArea object
   *                       is NOT constructed and errors are returned in this
   *                       parameter
   * @param[in]i_msAreaId  - input parameter - A unique id for each main store
   *                       area associated with a mainstore VPD object.  The id
   *                       starts at 0 and is incremented by 1 for each new
   *                       mainstore area.
   * @param[in] i_ramCnt - The number of RAM objects that will be
   *                      added to the mainstore area.  If an exact count cannot
   *                      be computed, a maximum number can be provided.
   * @param[in] i_chipEcCnt - The number of EC entries that will be
   *                       added to the mainstore area.  If an exact count
   *                       cannot be computed, a maximum number can be provided.
   * @param[in] i_addrRngCnt  - The number of address range entries that
   *                        will be added to the mainstore area.  If an exact
   *                        count cannot be computed, a maximum number can be
   *                        provided.
   * @param[in] i_resourceId - The FRU's resource id
   * @param[in] i_slcaIdx   - SLCA index for this FRU (only meaningful
   *                        if keyword size > 0).
   * @param[in] i_kwdSize   - Size of the ASCII keyword data if available,
   *                        otherwise 0.
   * @param[in] i_kwd       - ASCII keyword data if available, otherwise
   *                        NULL.
   *
   * @return A null error log handle if successful, else the return code point
   *         to by o_errlHndl contains one of:
   *
   * @retval HDAT_ALLOC_ERROR
   */
    HdatMsArea(errlHndl_t &o_errlHndl,
             TARGETING::Target* i_target,
             uint16_t i_msAreaId,
             uint32_t i_ramCnt,
             uint32_t i_chipEcCnt,
             uint32_t i_addrRngCnt,
             uint32_t i_resourceId,
             uint32_t i_slcaIdx,
             uint32_t i_kwdSize,
             char *&i_kwd);


  /**
   * @brief HdatMsArea object destructor
   *
   *        This is the destructor for an HdatMsArea object.  Any heap storage
   *        allocated for the object is dallocated.
   *
   * @pre No preconditions exist
   *
   * @post The HdatMsArea object has been destroyed and can no longer be used.
   *
   */
    virtual ~HdatMsArea();


  /**
   * @brief Add a RAM area to this main store area
   *
   *       A RAM object is added.
   *
   * @pre The number of RAM objects added cannot exceed the RAM count specified
   *      on the HdatMsArea constructor
   *
   * @post None
   *
   * @param[in] i_ram - input parameter - A RAM object
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by o_errlHndl contains one of:
   *
   * @retval HDAT_ARRAY_ERROR
   */
    errlHndl_t addRam(HdatRam &i_ram);


  /**
   * @brief Update the mainstore area to specify the type of memory.
   *
   * @pre None
   *
   * @post None
   *
   * @param[in] i_type - input parameter - This specifies the type of memory
   *               card  for this mainstore area.
   */
    void setParentType(uint16_t i_type);


  /**
   * @brief Update the mainstore area to specify the status of the memory DIMMS
   *
   * @pre None
   *
   * @post None
   *
   * @param[in] i_status - input parameter - See the hdatMsAreaStatus enum.
   *    The value specified here can be a bitwise OR of the enum values.
   */
    void setStatus(uint16_t i_status);


  /**
   * @brief Update the mainstore area with a unique ID for interleaved areas
   *
   *        The call to setStatus must also turn on the HDAT_MEM_SHARED flag.
   *
   * @pre None
   *
   * @post None
   *
   * @param[in] i_status - A unique ID. All MS areas which are
   *                   interleaved will have the same ID.
   */
    void setInterleavedId(uint16_t i_id);


  /**
   * @brief Update the mainstore area to specify the total size of the mainstore
   *        area.
   *
   * @pre None
   *
   * @post None
   *
   * @param[in] i_size - The total size of the configured mainstore
   *             area in megabytes.  It is the (high address of the mainstore
   *             area + 1 minus the low address of the mainstore area) divided
   *             by 1 megabyte.
   */
    void setSize(uint32_t i_size);


  /**
   * @brief Update the mainstore area to specify associated processor id
   *
   * @pre None
   *
   * @post None
   *
   * @param[in] i_moduleId - The Module Id of the processor
   *                     associated with this mainstore area.
   */
    void setModuleId(uint32_t i_moduleId);

  /**
   * @brief Update the mainstore area to specify its affinity domain
   *
   * @pre None
   *
   * @post None
   *
   * @param[in] i_affinityDomain - The Affinity Domain
   *                           associated with this mainstore area.
   */
    void setAffinityDomain(uint32_t i_affinityDomain);

  /**
   * @brief Get the SLCA index, the keyword size, and the ASCII keyword
   *
   * @pre None
   *
   * @post None
   *
   * @param[out] o_resourceId - The resource ID for this FRU
   * @param[out] o_slcaIdx - The SLCA index for this FRU
   * @param[out] o_kwdSize The size of the ASCII keyword data
   * @param[out] o_kwd -  A pointer to the ASCII keyword
   *
   */
    void getKwdInfo(uint32_t &o_resourceId,
                  uint32_t &o_slcaIdx,
                  uint32_t &o_kwdSize,
                  char *&o_kwd);


  /**
   * @brief Update the mainstore area to specify a memory address range.
   *        More than one address range can be added.
   *
   * @pre One cannot add any more address range entries than was specified by
   *      the i_addrRngCnt parameter on the HdatMsArea constructor.
   *
   * @post An address range entry has been added.
   *
   * @param[in] i_start      - The starting address of the range
   * @param[in] i_end        - The ending address of the range + 1
   * @param[in] i_procChipId - which is the chip id of the physical processor
   * @param[in] i_rangeIsMirrorable - Specifies whether the range is
   *                              mirrorable
   * @param[in] i_mirroringAlgorithm - Specifies hardware mirroring
   *                               algorithm to use
   * @param[in] i_startMirrAddr - Specifies the starting mirrorable
   *                          address for range
   * @param[in] i_memcntlrId - Memory Controller ID
   * @param[in] i_hdatSmf - Whether the range is in SMF memory
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by o_errlHndl contains one of:
   *
   * @retval HDAT_ARRAY_ERROR
   */
  errlHndl_t addAddrRange(hdatMsAddr_t &i_start,
                          hdatMsAddr_t &i_end,
                          uint32_t i_procChipId,
                          bool i_rangeIsMirrorable,
                          uint8_t i_mirroringAlgorithm,
                          hdatMsAddr_t &i_startMirrAddr,
                          uint32_t  i_memcntlrId,
                          bool i_hdatSmf);

  /**
   * @brief Update the mainstore area to specify a mmio memory address range.
   *        More than one address range can be added.
   *
   * @pre One cannot add any more address range entries than was specified by
   *      the i_mmioAddrRngCnt parameter on the HdatMsArea constructor.
   *
   * @post An address range entry has been added.
   *
   * @param[in] i_start      - The starting address of the range
   * @param[in] i_end        - The ending address of the range
   * @param[in] i_mmioMemCntlId - Memory Controller ID
   * @param[in] i_mmioProcPhyChipId - which is the chip id of the physical
   *                                  processor
   * @param[in] i_mmioHbrtChipId - MMIO HBRT Chip ID
   * @param[in] i_mmioFlags -  MMIO flags
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by o_errlHndl indicates that the mmio array size
   *         crossed the maximum allowed limit
   *
   * @retval RC_ERC_MAX_EXCEEDED
   */
  errlHndl_t addMmioAddrRange(hdatMsAddr_t &i_start,
                              hdatMsAddr_t &i_end,
                              uint32_t i_mmioMemCntlId,
                              uint32_t i_mmioProcPhyChipId,
                              uint64_t i_mmioHbrtChipId,
                              uint64_t i_mmioFlags);

  /**
   * @brief Add engineering change information for memory interface chips
   *
   * @pre The first EC entry added must be for the memory controller
   *
   * @post One cannot add any more engineering change entries than was specified
   *  by the i_chipEcCnt parameter on the HdatMsArea constructor.
   *
   * @param[in] i_manfId - input parameter - Chip's manufacturing id
   * @param[in] i_ecLvl  - input parameter - Chip's engineering change level
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by o_errlHndl contains one of:
   *
   * @retval HDAT_ARRAY_ERROR
   */
    errlHndl_t addEcEntry(uint32_t i_manfId,
                        uint32_t i_ecLvl);

  /**
   * @brief This routine returns the length of all RAM objects associated
   *        with this mainstore area
   *
   * @pre None
   *
   * @post None
   *
   */
    uint32_t ramObjSizes();


  /**
   * @brief This routine finalizes the object's size and updates header
   * information
   *
   *
   * @pre All data must have been added to the object and it must be ready to
   *      commit.
   *
   * @post This method must be called first before the inherited size() method
   *       can be called and return correct results.
   *
   */
  void finalizeObjSize();


  /**
   * @brief Print an HdatMsArea object.
   *
   *     This method is a debug mthod which prints out a mainstore area object.
   *
   * @pre None
   *
   * @post None
   *
   */
  void prt();

  /**
   * @brief Get MS area size
   *
   *       This method is to retreive complete MS area size
   *
   * @pre None
   *
   * @post None
   *
   * @return - returns size value
   *
   */
    uint32_t  getMsAreaSize();

  /**
   * @brief Get Ram area size
   *
   *       This method invokes ram getSize routine for all the child pointers
   *       and gets the size.
   *
   * @pre None
   *
   * @post None
   *
   * @return - returns size value
   *
   */
    uint32_t getRamAreaSize();
  /**
   * @brief Writes the MS area data in main store memory
   *
   * @pre None
   *
   * @post None
   *
   * @param[inout] i_data - memory used to write the data
   *
   *
   */
    void commit(UtilMem &i_data);
  /**
   * @brief Iterates all the child pointers to invoke function that writes ram
   * area data
   *
   * @pre None
   *
   * @post None
   *
   * @param[inout] i_data - memory used to write the data
   *
   *
   */
    void commitRamAreas(UtilMem &i_data);
private:


    /** Object Instance Data
     *
     * @li iv_kwdSize         - size of the ASCII keyword
     * @li iv_maxAddrRngCnt   - maximum number of address range entries that
     *                          can be added
     * @li iv_maxMmioAddrRngCnt - maximum number of mmio address range entries
     *                          that can be added
     * @li iv_maxEcCnt        - maximum number of EC entries that can be added
     * @li iv_msaHostI2cCnt   - actual number of host I2C entries that can be
     *                          added
     * @li iv_msaHostI2cSize  - total size of host i2c data
     * @li iv_maxRamCnt       - maximum number of RAM objects that can be added
     * @li iv_actRamCnt       - actual number of RAM objects that were added
     * @li iv_maxRamObjSize   - maximum size of any RAM object associated with
     *                          this mainstore area
     * @li iv_kwd             - ptr to storage which holds the ASCII keyword
     * @li iv_ramPadReq       - padding will be required for one or more RAM
     *                          objects to make them all the same size
     * @li iv_fru             - FRU Id information
     * @li iv_msId            - mainstore area id information
     * @li iv_msSize          - mainstore size information
     * @li iv_AddrRngArrayHdr - data array header
     * @li iv_addrRange       - mainstore addresses
     * @li iv_mmioAddrRngArrayHdr - MMIO address range array header
     * @li iv_mmioAddrRngArray    - MMIO address range array
     * @li iv_aff             - CPU affinity information
     * @li iv_ecArrayHdr      - data array header
     * @li iv_ecLvl           - EC level array
     * @li iv_msaI2cHdr       - Host I2C info header
     * @li iv_msaI2cEntryPtr - Host I2C info entries
     * @li iv_ramPtrs         - ptr to storage which contains one of more ptrs
     *                          to RAM objects
     */
    uint32_t                     iv_kwdSize;
    uint32_t                     iv_maxAddrRngCnt;
    uint32_t                     iv_maxMmioAddrRngCnt;
    uint32_t                     iv_maxEcCnt;
    uint32_t                     iv_maxRamCnt;
    uint32_t                     iv_actRamCnt;
    uint32_t                     iv_maxRamObjSize;
    char                        *iv_kwd;
    bool                         iv_ramPadReq;
    hdatFruId_t                  iv_fru;
    hdatMsAreaId_t               iv_msId;
    hdatMsAreaSize_t             iv_msSize;
    hdatHDIFDataArray_t          iv_addrRngArrayHdr;
    hdatMsAreaAddrRange_t        *iv_addrRange;
    hdatHDIFDataArray_t          iv_mmioAddrRngArrayHdr;
    hdatMsAreaMmioAddrRange_t    *iv_mmioAddrRngArray;
    hdatMsAreaAffinity_t         iv_aff;
    hdatHDIFDataArray_t          iv_ecArrayHdr;
    hdatEcLvl_t           *iv_ecLvl;
    HdatRam                    **iv_ramPtrs;


    /** Class (static) Data
     *
     * Only one copy of this data exists in a process.
     *
     * @li cv_actualCnt - a count of how many HdatMsArea objects are created
     */
    static uint32_t   cv_actualCnt;

}; // end of HdatMsArea class

}
#endif // HDATMSAREA_H
