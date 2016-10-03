/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdathostservices.H $                             */
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
#ifndef HDATHOSTSR_H
#define HDATHOSTSR_H

/**
 *  @file hdathostservices.H
 *
 *  @brief This file contains the class definition for the Host service data object.
 *
 */

/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <stdint.h>              // standard types
#include <hdat/hdat.H>                // HDAT header type definitions
#include "hdathdif.H"            // HdatHdif base class definition
#include "hdatnodedata.H"        //Host service node data

/*-----------------------------------------------------------------------------*/
/* Constants                                                                   */
/*-----------------------------------------------------------------------------*/

/** @brief eye catcher for the HDIF header for the Host service data
 */
const char HDAT_STRUCT_NAME[] = "HOSTSR";


/** @enum hdatDataPtrs
 *        Constants for the internal data pointers that are added to the base
 *        class
 */
enum hdatHSDataPtrs
{
  HDAT_SYSTEM_ATTRIBUTE  = 0,
  HDAT_HOSTSR_LAST       = 1
};

/** @enum hdatChildPtrs
 *        Constants for the child structure pointers that are added to the base
 *        class
 */
enum hdatChildPtrs
{
  HDAT_CHILD_NODE_ATTRIBUTE   = 0,
  HDAT_CHILD_RESERVED1  = 1,
  HDAT_CHILD_LAST       = 2
};

const uint16_t HDAT_HOSTSR_VERSION = 0x0010;

const uint32_t HDAT_HOSTSR_SIZE = 4096;


/*-----------------------------------------------------------------------------*/
/* Type definitions                                                            */
/*-----------------------------------------------------------------------------*/


namespace HDAT
{
/*-----------------------------------------------------------------------------*/
/* C++ class definition                                                        */
/*-----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatHostsr class is used to construct Host service data objects.
 *
 * Description: This class defines a specialized object.
 *              The real purpose of the object is to create the HostService data
 *              as defined by the PHYP Initialization
 *              architecture. 
 *
 * End Class Description
 */
class HdatHostsr : public HdatHdif
{
public:

    /**
    * @brief Construct an HdatHostsr object.
    *
    *       This is the constructor for the HdatHostsr object when that Host service data
    *       is not currently plugged but has been reserved for concurrent
    *       maintenance.
    *
    *       If you are constructing this object on the heap by using new, then
    *       you must check the pointer returned from new to see if it is null.
    *       If it is null, new failed to allocate storage and the constructor
    *       was not called.  If it is not null, then you must check o_errlHndl
    *       to see if the constructor ran successfully.  If o_errlHndl indicates
    *        an error was reported by the constructor, new has already allocated
    *       heap storage and the object must be deleted in order to free the
    *       heap storage.
    *
    * @pre None
    *
    * @post An HdatHostsr object has been constructed.  Heap storage has been allocated.
    *
    * @param o_errlHndl     - output parameter - If any errors occur, the HdatHostsr object
    *                         is NOT constructed and errors are returned in this parameter
    * @param i_msAddr      - input parameter - The main memory address that the Host service data
    *                        that will be DMA'd to.
    *
    * @return A null error log handle if successful, else the return code pointed
    *         to by o_errlHndl contains one of:
    *
    * @retval HDAT_ALLOC_ERROR
    */
    HdatHostsr(errlHndl_t &o_errlHndl,
               const hdatMsAddr_t &i_msAddr,
               uint32_t &o_hostServiceDataSize,
               uint32_t &o_hostServiceDataCnt);


    /**
    * @brief HdatHostsr object destructor
    *
    *        This is the destructor for an HdatHostsr object.  Any heap storage
    *        allocated for the object is dallocated.
    *
    * @pre No preconditions exist
    *
    * @post The HdatHostsr object has been destroyed and can no longer be used.
    *
    */
    virtual ~HdatHostsr();
    /**
    * @brief Build Host Service Data
    *
    * @pre Virtual mapping is done in constructor
    *
    * @post Host service(parent) and Node data(children) setting done
    *
    * @return A null error log handle if successful, else the return code pointed
    *         to by errlHndl_t
    */

    errlHndl_t hdatHostServiceBuild(uint32_t &o_hostServiceTotalSize);

    /** 
    * @brief Build the hypervisor data area structres for Node Data.
    *
    * @pre None
    *
    * @post A node data has been added to the object.  Heap storage
    *       has been allocated.
    *
    * @return A null error log handle if successful, else the return code pointed 
    *         to by errlHndl_t contains one of:
    *
    * @retval HDAT_ALLOC_ERROR
    */
    errlHndl_t bldNodeDataStruct(uint32_t &o_NodeDataSize);

    /**
    * @brief Add  Host Service Node data description.
    *
    * @pre None
    *
    * @post Node data has been added to the object.  Heap storage
    *       has been allocated.
    *
    * @param i_resourceId - input parameter - Node number
    *
    * @return A null error log handle if successful, else the return code pointed
    *         to by errlHndl_t contains one of:
    *
    * @retval HDAT_ALLOC_ERROR
    * @retval HDAT_ARRAY_ERROR
    */
    errlHndl_t addNodeData(uint32_t node);

    /**
    * @brief Set node data child pointers.
    *
    * @pre Node data pointer should have built i.e., node data
    *       object should be instantiated
    *
    * @post Node data committed
    */

    errlHndl_t setChildPtrs();

    /** Class (static) Data
    *
    * Only one copy of this data exists in a process.
    * 
    * @li cv_actualCnt - a count of how many HdatServiceData objects are created
    */
    static uint32_t   cv_actualCnt;

private:

    /** Object Instance Data
    *
    * @li iv_msAddr          - main memory address
    * @li iv_hostServiceData - Pointer to host service data
    * @li iv_size            - Size of the service Data structure
    * @li iv_maxNodes        - maximum number of Nodes
    * @li iv_actNodeCnt      - Actual Node Count
    * @li iv_NodePtrs        - Pointer to array of Node data pointers
    * @li iv_virt_addr       - Pointer to virtual mapped address
    */
    uint64_t             iv_msAddr;
    uint8_t*             iv_hostServiceData;
    uint64_t             iv_size;
    uint32_t             iv_maxNodes;
    uint32_t             iv_actNodeCnt;
    HdatNodedata         **iv_NodePtrs;
    uint8_t*             iv_virt_addr;

}; // end of HdatHostSr class


}

#endif // HDATHOSTSR_H

