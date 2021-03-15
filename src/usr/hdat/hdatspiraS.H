/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatspiraS.H $                                   */
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
#ifndef HDATSPIRAS_H
#define HDATSPIRAS_H

/**
 *  @file hdatspiraS.H
 *
 *  @brief This file contains the definition of the Service Processor Interface
 *       Root Array Secure boot (SPIRA-S) data structure.  This data structure
 *       is built  by FSP and placed at the beginning of the host data areas
 *       space located using the SPIRA-H. Data areas pointed to by this portion
 *       of the SPIRA will be located after it in the host data areas space.
 *
 */



/*---------------------------------------------------------------------------*/
/* Includes                                                                  */
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include <errl/errlentry.H>
#include <hdat/hdat.H>


namespace HDAT
{

/*---------------------------------------------------------------------------*/
/* Constants                                                                 */
/*---------------------------------------------------------------------------*/
const char HDAT_SPIRAS_EYE_CATCHER[] = "SPIRAS";

const uint16_t HDAT_SPIRAS_VERSION = 0x40;

const  hdatMsAddr_t SLCA_BUILD_ADDR = {0x00000000, 0x80000000};

/*---------------------------------------------------------------------------*/
/* Type definitions                                                          */
/*---------------------------------------------------------------------------*/
enum hdatSpiraSDataAreas
{
  HDAT_SPIRAS_DA_FIRST         = 0,
  HDAT_SPIRAS_SP_SUBSYS        = 0,    // service processor subsystem
  HDAT_SPIRAS_IPL_PARMS        = 1,    // IPL parameters
  HDAT_SPIRAS_ENCLOSURE_VPD    = 2,    // enclosure vital product data
  HDAT_SPIRAS_SLCA             = 3,    // slot location code array
  HDAT_SPIRAS_BACKPLANE_VPD    = 4,    // backplane vital product data
  HDAT_SPIRAS_SYS_VPD          = 5,    // system vital product data
  HDAT_SPIRAS_CLOCK_VPD        = 6,    // clock vital product data
  HDAT_SPIRAS_ANCHOR_VPD       = 7,    // anchor card vital product data
  HDAT_SPIRAS_OP_PNL_VPD       = 8,    // operator panel vital product data
  HDAT_SPIRAS_MISC_CEC_VPD     = 9,    // miscellaneous FRU vital product data
  HDAT_SPIRAS_MSVPD            = 10,   // memory description tree
  HDAT_SPIRAS_IO_HUB           = 11,   // I/O hub FRU array
  HDAT_SPIRAS_PCIA             = 12,   // PCIA (Core information area)
  HDAT_SPIRAS_PCRD             = 13,   // PCRD (Chip related data area)
  HDAT_SPIRAS_HOSTSR           = 14,   // HOSTSR (Host service data)
  HDAT_SPIRAS_HBRT             = 15,   //HBRT (runtime data)
  HDAT_SPIRAS_IPMI             = 16,   // IPMI Sensor MApping Data
  HDAT_SPIRAS_TPM_RELATED      = 17,   // Node TPM Related Data
  HDAT_SPIRAS_DA_LAST          = 18
};


/** @brief The SPIRA-S is composed of an HDIF header and an array.  Each array
 *         entry is an n-tuple.  That is, it is a structure with a particular
 *         number of fields
 */
struct hdatSpiraS_t
{
  hdatHDIF_t           hdatHDIF;            // 0x0000 Common HDIF header
  hdatHDIFDataHdr_t    hdatDataHdr;         // 0x0020 Data "pointers"
  uint8_t              hdatReserved1[8];    // 0x0028 Padding/future growth
  hdatHDIFDataArray_t  hdatArrayInfo;       // 0x0030 Info on 5-tuple array
  hdat5Tuple_t         hdatDataArea[HDAT_SPIRAS_DA_LAST]; //0x0040 5-tuple array
  // At this point, the host OS may have reserved extra space for future growth
  // but FipS does not need to be concerned with the reserved space nor DMA it
  // back from main memory.
} __attribute__ ((packed));


/*---------------------------------------------------------------------------*/
/* C++ class definition                                                      */
/*---------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatSpiraS class is used to construct the SPIRA-S object
 *
 * Description:
 *     The SPIRA-S object contains mainstore addresses and other information
 *     about various hypervisor data structures.  The SPIRA-S is initially
 *     DMA'd from mainstore to FipS control store and written to a
 *     file.  Constructing thr SPIRA-S objects maps the file into a
 *     process' address space.
 *
 * Thread safety:
 *     An HdatSpiraS object is not thread safe.  That is, a single
 *     object cannot be shared and used concurrently by multiple
 *     threads at the same time.
 *
 * Signal handler usage:
 *     This class is not intended to be used in a signal handler
 *     and nothing has been done to try and make it safe to use
 *     in a signal handler.
 *
 * End Class Description
 */
class HdatSpiraS
{
public:


  /**
   * @brief Construct an HdatSpiraS object.
   *
   *      This function reads in the Service Processor Interface Root Array
   *      (SPIRA-S) structure from main memory,
   *
   *      THIS CONSTRUCTOR CAN BE USED ONLY BY THE HDAT COMPONENT.
   *
   * @pre The primary LID which contains the NACA and the primary/secondary LID
   *      which contains the SPIRA-S must have been read to main memory.
   *
   * @post The SPIRA-S is read from main memory and is initiailized to default
   *       values
   *
   *
   * @param  i_spirasHostEntry - input parameter - the spiras starting address
   *                             entry fetched from spira-h
   *
   * @return A null error log handle if successful, else the return code
   *         pointed to by errlHndl_t contains one of:
   *
   * @retval HDAT_ALLOC_ERROR
   * @retval HDAT_FILE_ERROR
   */
  HdatSpiraS(const hdat5Tuple_t& i_spirasHostEntry);


  /**
   * @brief HdatSpiraS object destructor
   *
   *        This is the destructor for an HdatSpiraS object.  Any heap storage
   *        allocated for the object is dallocated.
   *
   * @pre No preconditions exist
   *
   * @post The HdatSpiraS object has been destroyed and can no longer be used.
   *
   */
  ~HdatSpiraS();




  /**
   * @brief This function returns the address to the raw SPIRA-S structure.  It
   *        is intended to be used only to put the structure into an error log.
   *
   *      THIS FUNCTION SHOULD BE USED ONLY BY THE HDAT COMPONENT.
   *
   * @pre None
   *
   * @post None
   *
   * @return An address to the spiraH
   */
  const hdatSpiraS_t *getStructAddr();


  /**
   * @brief This routine initializes the SPIRA-S HDIF header and
   * clears the N-Tuple array
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
  void setSpiraSHdrs();


  /**
   * @brief This function constructs the (SPIRA-S)
   *        structure in main memory
   *
   * @pre The primary LID which contains the NACA and the primary/secondary LID
   *      which contains the SPIRA-S must have been read to main memory.
   *
   *      THIS FUNCTION CAN BE USED ONLY BY THE HDAT COMPONENT.
   *
   * @post The SPIRA-S is written to main memory, and initialized to default
   *       values if required
   *
   * @param  i_spirasHostEntry  the spiras starting address entry fetched
   *       from spira-h
   *
   * @return A null error log handle if successful, else the return code pointed
   *         to by errlHndl_t contains one of:
   *
   * @retval HDAT_ALLOC_ERROR
   * @retval HDAT_FILE_ERROR
   */
  errlHndl_t loadDataArea( const hdat5Tuple_t& i_spirasHostEntry,
                           uint32_t& o_actCount, uint32_t& o_actSize);


  /**
   * @brief this function returns a copy of the spiras object into
   * a buffer provided by the user
   *
   * @pre None
   *
   * @post the buffer area is allocated and spiras is copied to that area.
   *       the user is responsible to free up the memory area used
   *
   * @param io_spiras - input-output parameter- area where spiras is copied
   *
   * @param i_msAddr - starting address of spiras retrieved from spirah
   *
   * @return None
   */

  void getSpirasObject(uint8_t * &io_spiras,uint32_t& o_size,
              const hdatMsAddr_t& i_msAddr);



  /**
   * @brief This function computes the address of a 5-tuple entry within the
   * SPIRA-S structure and returns it
   *
   * Usage note:  The SPIRA-S structure is already built as part of the Host
   * LIDS
   * @pre None
   * @post A copy of the desired 5-tuple returned
   *
   * @param i_dataArea - input parameter - an enumeration for the 5-tuple entry
   *                     being requested
   * @param o_entry    - output parameter - a copy of the 5-tuple entry being
   *                     requested
   *
   * @return NONE
   */

  void getSpiraSEntry(hdatSpiraSDataAreas i_dataArea,
              hdat5Tuple_t &o_entry);


private:


  /** Object Instance Data
   *
   * @li iv_spirasSize - size if the SPIRA-S structure
   * @li iv_spiras  - pointer to the SPIRA-S structure
   */
  uint32_t     iv_spirasSize;
  hdatSpiraS_t *iv_spiras;

}; // end of HdatSpiraS class

} //end namespace
#endif // HDATSPIRAS_H
