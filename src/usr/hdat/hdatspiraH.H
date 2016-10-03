/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatspiraH.H $                                   */
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
#ifndef HDATSPIRAH_H
#define HDATSPIRAH_H

/**
 *  @file hdatspiraH.H
 *
 *  @brief This file contains the definition of the Service Processor Interface
 *         Root Array Secure boot (SPIRA-H) data structure.  This data structure 
 *         is prebuilt as part of one of the LIDS loaded into memory.
 *
 *         Usage note:  The SPIRA-H structure is built as part of the host LIDs.
 *         These are big endian structures.  If this structure is used on a little
 *         endian machine, the user is responsible for performing big endian to
 *         little endian conversions.
 */

/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <stdint.h>           // integer data type definitions
#include <hdat/hdat.H>
#include "hdathdif.H"
/*-----------------------------------------------------------------------------*/
/* Constants                                                                   */
/*-----------------------------------------------------------------------------*/
const char HDAT_SPIRAH_EYE_CATCHER[] = "SPIRAH";

namespace HDAT
{

/*-----------------------------------------------------------------------------*/
/* Type definitions                                                            */
/*-----------------------------------------------------------------------------*/


/** @enum hdatSpiraHDataAreas
 *        This enumeration defines the various data areas in spiraH
 *        This list must be kept in the same order as the 5-tuple entries in
 *        the SPIRA-H.
 *
 *        If the order is changed, entries are added, or entries are deleted,
 *        update.
 */
enum hdatSpiraHDataAreas
{
    HDAT_SPIRAH_DA_FIRST       = 0,
    HDAT_SEC_HOST_DATA_AREA    = 0,
    HDAT_SEC_PROC_INIT         = 1,   // phyp-supplied processor init data
    HDAT_SEC_CPU_CTRL          = 2,   // CPU controls
    HDAT_SEC_MS_DUMP_SRC_TBL   = 3,   // mainstore dump source table (can change at run time)
    HDAT_SEC_MS_DUMP_DST_TBL   = 4,   // mainstore dump destination table (can change at run time)
    HDAT_SEC_MS_DUMP_RSLT_TBL  = 5,   // mainstore dump results table

    HDAT_SPIRAH_DA_LAST        = 6
};

/*-----------------------------------------------------------------------------*/
/* Type definitions                                                            */
/*-----------------------------------------------------------------------------*/

/** @brief The SPIRA-H is composed of an HDIF header and an array.  Each array
 *         entry is an n-tuple.  That is, it is a structure with a particular
 *         number of fields
 */
struct hdatSpiraH_t
{
    hdatHDIF_t           hdatHDIF;            // 0x0000 Common HDIF header
    hdatHDIFDataHdr_t    hdatDataHdr;         // 0x0020 Data "pointers"
    uint8_t              hdatReserved1[8];    // 0x0028 Padding/future growth
    hdatHDIFDataArray_t  hdatArrayInfo;       // 0x0030 Info on 5-tuple array
    hdat5Tuple_t         hdatDataArea[HDAT_SPIRAH_DA_LAST]; //0x0040 5-tuple array
} __attribute__ ((packed));

/*-----------------------------------------------------------------------------*/
/* C++ class definition                                                        */
/*-----------------------------------------------------------------------------*/

/** Begin Class Description                                                        
 *
 * @brief  The HdatSpiraH class is used to construct the SPIRA-H object.   
 *
 * Description: The SPIRA-H object contains mainstore addresses and other information
 *              about various hypervisor data structures.
 *              Constructing thr SPIRA-H objects maps the spiraH into a
 *              process' address space.
 *
 * Thread safety:  An HdatSpiraH object is not thread safe.  That is, a single
 *                 object cannot be shared and used concurrently by multiple
 *                 threads at the same time.  
 *
 * Signal handler usage: This class is not intended to be used in a signal handler
 *                       and nothing has been done to try and make it safe to use
 *                       in a signal handler.
 *                                             
 * End Class Description
 */
class HdatSpiraH
{
public:

   /* @brief Construct an HdatSpiraH object.
   *
   *        This function maps the Service Processor Interface Root Array (SPIRA-H) 
   *        structure from hypervisor lid space to a process' address space.
   *
   * @pre The SPIRA-H containing Lid must have loaded on memory
   *
   * @post The SPIRA-H is mapped to a process' memory
   *
   * @param o_errlHndl - output parameter - error log handle
   *
   * @return A null error log handle if successful, else the return code pointed 
   *         to by errlHndl_t contains one of:
   */
   HdatSpiraH(errlHndl_t &o_errlHndl, hdatMsAddr_t &i_msAddr);

  /**
   * @brief HdatSpiraH object destructor
   *
   *        This is the destructor for an HdatSpiraH object.  Any heap storage 
   *        allocated for the object is dallocated.
   *
   * @pre No preconditions exist
   *
   * @post The HdatSpiraH object has been destroyed and can no longer be used.
   *
   */
  virtual ~HdatSpiraH(); 

  /**
   * @brief This function computes the address of a 5-tuple entry within the
   *        SPIRA-H structure and returns it.
   *
   *        Usage note:  The SPIRA-H structure is built as part of the host LIDs.
   *        These are big endian structures.
   *
   * @pre None
   *
   * @post A copy of the desired 5-tuple returned, with any endian conversion done.
   *
   * @param i_dataArea - input parameter - an enumeration for the 5-tuple entry
   *                     being requested.
   * @param o_entry    - output parameter - a copy of the 5-tuple entry being
   *                     requested, with any endian conversion already performed.
   *
   * @return NONE
   */
    void getSpiraHEntry(hdatSpiraHDataAreas i_dataArea,
                     hdat5Tuple_t &o_entry);

  /**
   * @brief This function updates a SPIRA-H entry.  Any required endian conversion
   *        is performed on the 5-tuple entry before the update.
   *
   * @pre None
   *
   * @post The SPIRA-H has been updated
   *
   * @param i_dataArea - input parameter - An enumeration for the 5-tuple entry
   *                     being updated.
   * @param i_entry    - input parameter - the 5-tuple entry being updated.
   */
    void chgSpiraHEntry(hdatSpiraHDataAreas i_dataArea,
                     const hdat5Tuple_t &i_entry);

    /**
     * @brief This function updates a data area entry for spiraH in main memory
     *
     * @pre spiraH is present at main memory
     *
     * @param i_dataArea - input parameter -An enumeration for the 5-tuple entry
     *                     being updated
     *
     * @param i_actCount,i_actSize - actual count and size of the data area
     */

    void chgSpiraHEntry(hdatSpiraHDataAreas i_dataArea,
                            uint32_t i_actCount,uint32_t i_actSize);
private:

  /**
   * @brief This function copies the Service Processor Interface Root Array (SPIRA-H)
   *        structure from phyp lid space.
   *
   * @pre The primary LID which contains the NACA and the primary/secondary LID
   *      which contains the SPIRA-H must have been Loaded to memory.
   *
   * @post The SPIRA-H is copied from main memory into iv_spirah
   *
   */

    errlHndl_t getSpiraH();

  /** 
   * @brief This routine initializes the SPIRA-H HDIF header and clears the N-Tuple array
   *       
   * @pre None
   *
   * @post None
   *
   * @param None
   *
   * @return None
   *
   * @retval no errors currently defined
   */
    void setSpiraHHdrs();


  /** Object Instance Data
   *
   * @li iv_spirah - pointer to the SPIRA-H structure
   * @li iv_msAddr - Mainstore address of spiraH
   * @li iv_virt_addr - virtual address mapped to phyisical ms addr of spirah
   */
    hdatSpiraH_t *iv_spirah;
    uint64_t iv_msAddr;
    uint8_t *iv_virt_addr;

}; // end of HdatSpiraH class

} //HDAT
#endif // HDATSPIRAH_H
