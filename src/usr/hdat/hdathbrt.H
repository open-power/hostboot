/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdathbrt.H $                                     */
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
#ifndef HDATHBRT_H
#define HDATHBRT_H

/**
 *  @file hdathbrt.H
 *
 *  @brief This file contains the class definition for the Host boot runtime
 *         data object.
 *
 */

/*----------------------------------------------------------------------------*/
/*  Includes                                                                  */
/*----------------------------------------------------------------------------*/

#include <stdint.h>
#include <errl/errlentry.H>
#include <hdat/hdat.H>
#include <hdat/hdat_reasoncodes.H>
#include "hdatutil.H"
#include "hdathdif.H"

namespace HDAT
{
/*----------------------------------------------------------------------------*/
/*  Constants                                                                 */
/*----------------------------------------------------------------------------*/

/** @brief eye catcher for the HDIF header for the Host boot runtime data
 */
const char HDAT_HBRT_STRUCT_NAME[] = "HBRT  ";

/** @enum hdatHbrtDataPtrs
 *      Constants for the internal data pointers that are added to the base
 *      class
 */
enum hdatHBrtDataPtrs
{
      HDAT_HBRT_ATTRIBUTE   = 0
};

/** @enum hdatHbrtChildPtrs
 *      Constants for the child structure pointers that are added to the base
 *      class
 */
enum hdatHbrtChildPtrs
{
    HDAT_HBRT_CHILD_COUNT = 0
};

/** @brief Host boot runtime version number
 *
 */
const uint16_t HDAT_HBRT_VERSION = 0x0010;

/** @brief Host boot runtime string lablel size
 *
 */
#define HDAT_HBRT_STRING_LABEL_SIZE        24

/** @brief HBRT structure instance
 * */
#define HBRT_INSTANCE                      0


/*----------------------------------------------------------------------------*/
/*  Type definitions                                                          */
/*----------------------------------------------------------------------------*/


/** @brief Host boot runtime data section. Host boot data updated will be
 *      populated in this structure format.
 *
 */
struct hdatHbrtData_t
{
    uint8_t           hdatHbrtStringLabel[HDAT_HBRT_STRING_LABEL_SIZE];
                                                 //0x0000 : String Label
    uint32_t          hdatHbrtInstanceNum;       //0x0018 : Instance Number
    hdatHDIFDataHdr_t hdatHbrtBlobData;          //0x001C : Pointer to Data Blob
    uint32_t          hdatHbrtReserved1;         //0x0024 : Reserved1
    uint32_t          hdatHbrtReserved2;         //0x0028 : Reserved2
    uint32_t          hdatHbrtReserved3;         //0x002C : Reserved3
}  __attribute__ ((packed));


/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatHbrt class is used to construct Host boot runtime data
 *     objects.
 *
 * Description: This class defines a specialized object.  It is not intended
 *     that any component can create an object of this type.  In
 *     particular, the object is built only in the CEC Server process
 *     when requested by the hdat component.
 *
 *     The real purpose of the object is to create the Host boot
 *     runtime data as defined by the PHYP Initialization
 *     architecture and is written to
 *     main memory.  The class is not defined to be a general purpose
 *     interface for building this object by anyone other than the
 *     CEC Server process.
 *
 * Thread safety:  An HdatHbrt object is not thread safe.  That is, a single
 *     object cannot be shared and used concurrently by multiple
 *     threads at the same time.
 *
 * Signal handler usage: This class is not intended to be used in a signal
 *     handler and nothing has been done to try and make it
 *     safe to use in a signal handler.
 *
 * End Class Description
 */
class HdatHbrt : public HdatHdif
{
    public:


        /**
         *  @brief Construct an HdatHbrt object.
         *
         *      This is the constructor for the HdatHbrt object when that Host
         *      boot runtime data is not currently plugged but has been reserved
         *      for concurrent maintenance.
         *
         *      If you are constructing this object on the heap by using new,
         *      then you must check the pointer returned from new to see if it
         *      is null. If it is null, new failed to allocate storage and the
         *      constructor was not called.  If it is not null, then you must
         *      check o_errlHndl to see if the constructor ran successfully. If
         *      o_errlHndl indicates an error was reported by the constructor,
         *      new has already allocated heap storage and the object must be
         *      deleted in order to free the heap storage.
         *
         *  @pre None
         *
         *  @post An HdatHbrt object has been constructed.  Heap storage has
         *      been allocated.
         *
         *  @param[out]  o_errlHndl
         *      If any errors occur, the HdatHbrt object is NOT constructed and
         *      errors are returned in this parameter
         *  @param[in] i_msAddr
         *      The main memory address that the Host boot runtime data that
         *      will be written to
         *  @param[in] i_numHbrtSections
         *      Number of host boot runtime sections
         *  @param[in] i_sizeHbrtSections
         *      HBRT section blob size array
         *
         *  @return A null error log handle if successful, else the return code
         *      pointed to by o_errlHndl contains one of retval
         *
         *  @retval HDAT_ALLOC_ERROR
         */
        HdatHbrt(errlHndl_t &o_errlHndl, const hdatMsAddr_t &i_msAddr,
                const uint32_t i_numHbrtSections,uint64_t i_sizeHbrtSections[]);


        /**
         *  @brief HdatHbrt object destructor
         *
         *      This is the destructor for an HdatHbrt object.  Any heap storage
         *      allocated for the object is dallocated.
         *
         *  @pre No preconditions exist
         *
         *  @post The HdatHbrt object has been destroyed and can no longer be
         *       used.
         *
         */
        virtual ~HdatHbrt();


        /**
         *  @brief write an HdatHbrt object.
         *
         *      This method must be called when the HdatHbrt object has been
         *      completed. That is, the object was constructed and all data has
         *      been added to object.
         *
         *
         *  @pre All informaton that is needed in the object must have been put
         *      there by the constructor or other methods.
         *
         *  @post The object data is written to main memory
         *
         *  @param[in] i_sizeHbrtSections
         *      Size of each of the host boot runtime sections
         *  @param[in] i_size
         *      The size of this and all previous objects.Needed to calculate
         *      the memory size which will be allocated.
         *  @param[out] o_count
         *      The count of all objects which have been committed. This value
         *      from the last object which is committed must be returned to the
         *      hdat component
         *
         *  @return A null error log handle if successful, else the return code
         *      pointed to by errlHndl_t contains one of the retval
         *
         */
        errlHndl_t setHbrt(uint64_t i_sizeHbrtSections[],uint32_t i_size);

    private:

        /** Object Instance Data
         *
         * @li iv_msAddr - main memory address the final data structure
         *     is written to
         * @li iv_numHbrtSections  - number of hbrt data sections
         */
        hdatMsAddr_t         iv_msAddr;
        uint32_t             iv_numHbrtSections;


}; // end of HdatHbrt class


/*
 *  @brief main function to load an hbrt object into main memory. This
 *  function is called from Spiras while loading all the data areas.
 *
 *  @pre All the previous data areas have been loaded to main memory
 *
 *  @post HBRT is written to main memory
 *
 *  @param[in] i_msAddr
 *             The main memory address where HBRT is written to
 *
 *  @param[out] o_size
 *             Total size written
 *
 *  @param[out] o_count
 *             Number of HBRT data structures
 */

errlHndl_t loadHbrt(const hdatMsAddr_t &i_msAddr,
            uint32_t &o_size , uint32_t &o_count);


}//end namespace

#endif // HDATHBRT_H

