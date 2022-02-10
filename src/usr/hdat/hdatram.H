/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatram.H $                                      */
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

#ifndef HDATRAM_H
#define HDATRAM_H
 
/**
 *  @file hdatram.H
 *
 *  @brief This file contains the class definition for the RAM object which
 *         describes memory DIMMS.  This structure is part of the larger        
 *         mainstore VPD structure which describes the various chips which 
 *         make up the memory subsystem. 
 *
 */


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdint.h>              // standard types
#include <hdat/hdat.H>                // HDAT header type definitions
#include "hdathdif.H"            // HdatHdif base class definition 
#include <errl/errlentry.H>      // ErrlEntry class

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Typedefs                                                                   */
/*----------------------------------------------------------------------------*/

/** @brief Structure definition for the RAM ID and status
 */
struct hdatRamAreaId_t
{
    uint16_t hdatRamAreaId;     // 0x0000 Identifier for this RAM area
    uint16_t hdatRamStatus;     // 0x0002 Status of the RAM DIMM
    uint32_t hdatRamDimmId;     // 0x0004 Dimm ID
    uint32_t hdatRamCurFreq;    // 0x0008 Dimm current operating frequency
}  __attribute__ ((packed));


/** @brief Structure definition for the RAM size
 */
struct hdatRamAreaSize_t
{
    uint32_t hdatReserved1;     // 0x0000 Reserved to make hdatRamTotalSize 8
                                // bytes in future
    uint32_t hdatRamTotalSize;  // 0x0004 Total size of configured main store
                                // in this RAM area in megabytes
}  __attribute__ ((packed));


/*---------------------------------------------------------------------------*/
/* Constants                                                                 */
/*---------------------------------------------------------------------------*/
const char HDAT_RAM_STRUCT_NAME[] = "RAM   ";

const uint16_t HDAT_RAM_VERSION = 0x0020;


/** @brief eye catcher for the HDIF header for the RAM data area
 */

/** @enum hdatDataPtrs
 *    Constants for the internal data pointers that are added to the base class
 */
enum hdatRamDataPtrs
{
    HDAT_RAM_FRU_ID    = 0,
    HDAT_RAM_KWD       = 1,
    HDAT_RAM_ID        = 2,
    HDAT_RAM_SIZE      = 3,
    HDAT_RAM_RESERVED1 = 4,
    HDAT_RAM_RESERVED2 = 5,
    HDAT_RAM_LAST      = 6
};
/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description 
 *
 * @brief  The HdatRam class is used to construct objects for memory DIMMs.  
 *
 * Description: This class defines a specialized object.  It is not intended
 *              that anyone can create an object of this type.  In particular,
 *              the object is built only as a internal object within the 
 *              HdatMsArea object.                                            
 *
 *              The real purpose of the object is to create the various RAM
 *              structures as defined by the PHYP Initialization architecture
 *              This data structure is eventually DMA'd to main memory.  The
 *              class is not defined to be a general purpose interface for
 *              building this object by anyone other than the hdatstep process.
 *
 * Thread safety:  An HdatRam object is not thread safe.  That is, a single
 *                 object cannot be shared and used concurrently by
 *                 multiple threads at the same time.  An object can be used by 
 *                 multiple threads if the threads serialize access.  And of 
 *                 course, each thread can use its own object with no concerns
 *                 about what other threads are doing.
 *
 * Signal handler usage: This class is not intended to be used in a signal 
 *              handler and nothing has been done to try and make it safe to use
 *              in a signal handler.
 *                                             
 * End Class Description
 */
class HdatRam : public HdatHdif
{
public:


  /** 
   * @brief Construct an HdatRam object.
   *
   *       This is the constructor for the HdatRam object.  
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
   * @post An HdatRam object has been constructed.  
   * Heap storage has been allocated.
   *
   * @param[out] o_errlHndl  - If any errors occur, the HdatRam object
   *               is NOT constructed and errors are returned in this parameter
   * @param[in] i_pDimmTarget - input parameter - DIMM target
   * @param[in] i_resourceId - input parameter - The FRU's resource id
   * @param[in] i_slcaIndex - input parameter - ms area slca index,
   *            if not provided then add dimms slca index
   *                        
   * @return A null error log handle if successful, else the return code pointed
   *         to by o_errlHndl contains one of:
   *
   * @retval HDAT_OTHER_COMP_ERROR
   */
  HdatRam(errlHndl_t &o_errlHndl,
         TARGETING::Target* i_pDimmTarget,
          uint32_t i_resourceId,
          uint32_t i_slcaIndex=0);


  /**
   * @brief HdatRam object destructor
   *
   *        This is the destructor for an HdatRam object.  Any heap storage 
   *        allocated for the object is dallocated.
   *
   * @pre No preconditions exist
   *
   * @post The HdatRam object has been destroyed and can no longer be used.
   *
   */
  virtual ~HdatRam();

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
    uint32_t getRamSize();

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
   * @brief Print an HdatRam object.
   *
   *       This method is a debug mthod which prints out a RAM object.
   *     
   * @pre None
   *
   * @post None
   *
   */
  void prt();

    /** Object Instance Data
    * @li iv_ramArea   - RAM Id structure
    * @li iv_ramSize   - RAM size structure
    */
    hdatRamAreaId_t    iv_ramArea;
    hdatRamAreaSize_t  iv_ramSize;

private:


    /** Object Instance Data
     *
     * @li iv_kwdSize   - size of the VPD ASCII keyword
     * @li iv_kwd       - ptr to the VPD ASCII keyword
     * @li iv_fru       - FRU id structure
     */
    size_t            iv_kwdSize;
    char              *iv_kwd;
    hdatFruId_t        iv_fru;

    /** Class (static) Data 
     *
     * Only one copy of this data exists in a process.
     *
     * @li cv_actualCnt - a count of how many HdatRam objects are created
     */
    static uint32_t   cv_actualCnt;

}; // end of HdatRam class

}

#endif // HDATRAM_H
