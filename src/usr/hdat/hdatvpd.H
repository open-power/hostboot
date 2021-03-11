/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatvpd.H $                                      */
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
#ifndef HDATVPD_H
#define HDATVPD_H

/**
 *  @file hdatvpd.H
 *
 *  @brief This file contains the class definition for the VPD object
 *     with data obtained from the SVPD component.  Besides typical VPD objects
 *     such as the Clock Card VPD object, this alos supports VPD objects which
 *     are part of a bigger object (such as the daughter card VPD object which
 *     is part of the HdatIoHubFru object).
 *
 */


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include <hdat/hdat.H>
#include "hdathdif.H"
#include <errl/errlentry.H>
#include <vpd/vpd_if.H>
//#include "hdatutil.H"
#include "../vpd/mvpd.H"
#include "../vpd/ipvpd.H"
#include "../vpd/pvpd.H"
#include <util/utilfile.H>
using namespace MVPD;
using namespace PVPD;
using namespace IPVPD;


namespace HDAT
{

typedef struct
{
    VPD::vpdKeyword keyword;
    char keywordName[2+1];
} HdatKeywordInfo;



struct vpdData
{
    VPD::vpdRecord record;
    VPD::vpdKeyword keyword;
};

enum vpdType
{
    PROC = 0x0,
    DIMM,
    BP,
    CLOCK,
    ENCLOSURE,
    ANCHOR,
    BP_EXT,
};//add as required. this needs to be passed to hdatGetAsciiKwd
//to choose the appropriate device address


/*----------------------------------------------------------------------------*/
/* Type definitions                                                           */
/*----------------------------------------------------------------------------*/

enum hdatVpdFruStatus
{
  HDAT_VPD_FRU_FUNCTIONAL       = 0x01,
  HDAT_VPD_REDUNDANT_FRU_USED   = 0x02
};

/** @enum hdatDataPtrs
 *  Constants for the internal data pointers that are added to the base
 *  class
 */
enum hdatVpdDataPtrs
{
    HDAT_VPD_FRU_ID    = 0,
    HDAT_VPD_KWD       = 1,
    HDAT_VPD_OP_STATUS = 2,
    HDAT_VPD_RESERVED2 = 3,
    HDAT_VPD_LAST      = 4
};

typedef enum {
    GARD_Functional,
    GARD_PartialFunctional,
    GARD_NotFunctional
}GARD_FunctionalState;

typedef enum {
    GARD_Used,
    GARD_NotUsed
}GARD_UsedState;

struct hdatFruOpStatus_t
{
  uint8_t hdatFlags;
  uint8_t hdatReserved1[3];
} __attribute__ ((packed));


/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatVpd class is used to construct objects that have the general
 *         format of VPD keyword data such as the CEC backplane VPD or L3 VPD,
 *         etc
 *
 * Description: This class defines a specialized object.  It is not intended
 *              that anyone can create an object of this type.  In particular,
 *              the object is built only in the hdatstep process when the step
 *              that builds hypervisor data structures is run.
 *
 *              The real purpose of the object is to create the various VPD
 *              structures as defined by the PHYP Initialization architecture
 *              This data structure is eventually DMA'd to main memory.  The
 *              class is not defined to be a general purpose interface for
 *              building this object by anyone other than the hdatstep process.
 *
 * Thread safety:  An HdatVpd object is not thread safe.  That is, a single
 *                 object cannot be shared and used concurrently by
 *                 multiple threads at the same time.  An object can be used by
 *                 multiple threads if the threads serialize access.  And of
 *                 course, each thread can use its own object with no concerns
 *                 about what other threads are doing.
 *
 * Signal handler usage:
 *                 This class is not intended to be used in a signal handler
 *                 and nothing has been done to try and make it safe to use
 *                 in a signal handler.
 *
 * End Class Description
 */
class HdatVpd : public HdatHdif
{
public:

  /**
   * @brief Construct an HdatVpd object.
   *
   *       This is the constructor for the HdatVpd object
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
   * @param o_errlHndl output error handle
   * @param i_resourceId input resource id
   * @param i_target input Target
   * @param i_eyeCatcher input the eyecatcher string
   * @param i_index input object instance
   * @param i_vpdType input the vpd type to be added
   * @param i_fetchVpd input the record-kwd structure like mVpd or pVpd etc
   * @param i_num input the number of elements in the i_fetchVpd structure
   * @param i_Keywords string array
   *
   * @post An HdatVpd object has been constructed.  Heap storage has been
   *       allocated.
   *
   */
  HdatVpd(errlHndl_t &o_errlHndl,
          uint32_t i_resourceId,
          TARGETING::Target * i_target,
          const char *i_eyeCatcher,
          uint32_t i_index,
          vpdType i_vpdType,
          struct vpdData i_fetchVpd[],
          uint32_t i_num, const HdatKeywordInfo i_pvpdKeywords[]);
  /**
   * @brief Construct an HdatVpd object.
   *
   *       This is the constructor for the HdatVpd object
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
   * @param o_errlHndl output error handle
   * @param i_resourceId input resource id
   * @param i_target input Target
   * @param i_eyeCatcher input the eyecatcher string
   * @param i_index input object instance
   * @param i_vpdType input the vpd type to be added
   * @param i_fetchVpd input the record structure like mVpd or pVpd etc
   * @param i_num input the number of elements in the i_fetchVpd structure
   * @param i_Keywords string array
   *
   * @post An HdatVpd object has been constructed.  Heap storage has been
   *       allocated.
   *
   */


  HdatVpd(errlHndl_t &o_errlHndl,
          uint32_t i_resourceId,
          TARGETING::Target * i_target,
          const char *i_eyeCatcher,
          uint32_t i_index,
          vpdType i_vpdType,
          const IpVpdFacade::recordInfo i_fetchVpd[],
          uint32_t i_num);

  /**
   * @brief HdatVpd object destructor
   *
   *        This is the destructor for an HdatVpd object.  Any heap storage
   *        allocated for the object is dallocated.
   *
   * @pre No preconditions exist
   *
   * @post The HdatVpd object has been destroyed and can no longer be used.
   *
   */
  ~HdatVpd();

  /*
   * @brief write the vpd object to memory
   *
   *  @pre the object must be constructed and the address to write at must
   *  be provided
   *
   * @param io_virt_addr - input parameter - inputs the address
   *                       to start to write to mainstore
   * @returns               outputs thenext address

   * @post data is written to memory and the next address is returned
   *
   */
  uint8_t * setVpd(uint8_t * io_virt_addr);


private:

  /** Object Instance Data
   *
   * @li iv_kwdSize - size of the ASCII keyword
   * @li iv_kwd     - ptr to storage which holds the ASCII keyword
   * @li iv_fru     - FRU Id information
   * @li iv_status  - FRU operational status
   */
  uint32_t          iv_kwdSize;
  char             *iv_kwd;
  hdatFruId_t       iv_fru;
  hdatFruOpStatus_t iv_status;



}; // end of HdatVpd class

} //namespace HDAT
#endif // HDATVPD_H
