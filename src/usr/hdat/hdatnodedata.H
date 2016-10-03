/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatnodedata.H $                                 */
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
#ifndef HDATNODEDATA_H
#define HDATNODEDATA_H

/**
 *  @file hdatvpd.H
 *
 *  @brief This file contains the class definition for the Host service node data object constructed
 *
 */

/*-----------------------------------------------------------------------------*/
/* Includes                                                                    */
/*-----------------------------------------------------------------------------*/
#include <stdint.h>              // standard types
#include "hdathdif.H"            // HdatHdif base class definition 
#include <hdat/hdat.H>

/*-----------------------------------------------------------------------------*/
/* Constants
*/
/*-----------------------------------------------------------------------------*/
#define HDAT_NODE_ATTR_DATA_SIZE 256000

const uint16_t HDAT_NODE_DATA_VERSION = 0x0010;


/** @enum hdatDataPtrs
 *        Constants for the internal data pointers that are added to the base
 *        class
 */
enum hdatDataPtrs
{
  HDAT_NODE_ATTRIBUTE   = 0,
  HDAT_NODE_DATA_LAST   = 1
};

/*-----------------------------------------------------------------------------*/
/* Type definitions                                                            */
/*-----------------------------------------------------------------------------*/

using namespace HDAT;

/*-----------------------------------------------------------------------------*/
/* C++ class definition                                                        */
/*-----------------------------------------------------------------------------*/
namespace HDAT
{

    /** Begin Class Description                                                        
    *
    * @brief  The HdatNodedata class
    *
    * Description: This class defines a specialized object.  It is not intended
    *              that anyone can create an object of this type.  In particular,
    *              the object is built only in the hdatstep process when the step
    *              that builds hypervisor data structures is run.
    *
    * Thread safety:  An HdatNodedata object is not thread safe.  That is, a single
    *                 object cannot be shared and used concurrently by
    *                 multiple threads at the same time.  An object can be used by  
    *                 multiple threads if the threads serialize access.  And of       
    *                 course, each thread can use its own object with no concerns
    *                 about what other threads are doing.
    *
    * Signal handler usage: This class is not intended to be used in a signal handler
    *                       and nothing has been done to try and make it safe to use
    *                       in a signal handler.
    *                                             
    * End Class Description
    */
    class HdatNodedata : public HdatHdif
    {
    public:

    /** 
    * @brief Construct an HdatNodedata object.
    *
    *       This is the constructor for the HdatNodedata object.
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
    * @post An HdatNodedata object has been constructed.  Heap storage has been allocated.
    *
    * @param o_errlHndl      - output parameter - If any errors occur, the HdatNodedata object
    *                          is NOT constructed and errors are returned in this parameter
    * @param io_msAddr        - input output parameter - The main memory address 
    * @param i_eyeCatcher    - input parameter - A character string to put in the structure's
    *                          eye catcher field.
    * @param o_NodeStructSize- Whole Node Data structure size
    *                        
    * @return A null error log handle if successful, else the return code pointed 
    *         to by o_errlHndl contains one of:
    *
    * @retval HDAT_OTHER_COMP_ERROR
    */
    HdatNodedata(errlHndl_t &o_errlHndl,
                uint64_t &io_msAddr,
                const char *i_eyeCatcher,
                uint32_t &o_NodeStructSize);


    /**
    * @brief HdatNodedata object destructor
    *
    *        This is the destructor for an HdatNodedata object.  Any heap storage
    *        allocated for the object is dallocated.
    *
    * @pre No preconditions exist
    
    * @post The HdatNodedata object has been destroyed and can no longer be used.
    *
    */
    virtual ~HdatNodedata();
    errlHndl_t setNodeData();

    /** Class (static) Data 
    *
    * Only one copy of this data exists in a process. 
    *
    * @li cv_actualCnt - a count of how many HdatNodedata objects are created
    */
    static uint32_t   cv_actualCnt;

    private:

    /** Object Instance Data
    *
    * @li iv_msAddr  - main store address the structure need to be copied to
    * @li iv_hdatNodeData - Pointer to Node Data
    * @li iv_virt_addr    - Pointr to hold virtual address post mem map.
    * @li iv_nodeAttritbuteData - Pointer to internal Data pointer
    * @li iv_size    - Size of the Node data
    */
    uint64_t      iv_msAddr;
    uint8_t *     iv_hdatNodeData;
    uint8_t *     iv_virt_addr;
    uint8_t       *iv_nodeAttritbuteData;
    uint64_t      iv_size;

}; // end of HdatNodedata class


}//HDAT

#endif // HDATNODEDATA_H

