/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdathdif.H $                                     */
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
#ifndef HDATHDIF_H
#define HDATHDIF_H

/**
 *  @file hdathdif.H
 *
 *  @brief This file contains the class definition for the object provding the
 *         HDIF header for most hypervisor data structures.
 *
 */


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include <hdat/hdat.H>
#include <hdat/hdat_reasoncodes.H>
#include <errl/errlentry.H>
#include <util/utilmem.H>



namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatHdif class provides the base class for hypervisor data areas
 *     that have an HDIF header.  Other C++ classes that build specific
 *     hypervisor data area structures are derived from this class.
 *
 * Description: This object is not intended to be constructed directly.  Rather,
 *              it provides the base class upon which other derived classes are
 *              built.
 *
 * Thread safety:  An HdatHdif object is not thread safe.  That is, a single
 *                 object cannot be shared and used concurrently by
 *                 multiple threads at the same time.  An object can be used by
 *                 multiple threads if the threads serialize access.  And of
 *                 course, each thread can use its own object with no concerns
 *                 about what other threads are doing.
 *
 * Signal handler usage:
 *                This class is not intended to be used in a signal handler
 *                and nothing has been done to try and make it safe to use
 *                in a signal handler.
 *
 * End Class Description
 */
class HdatHdif
{
    public:

       /**
        * @brief Construct an HdatHdif base object.
        *
        *       This is the constructor for the HdatHdif object
        *
        *       If you are constructing this object on the heap by using new,
        *       you must check the pointer returned from new null value.
        *       If null, new failed to allocate storage and the constructor
        *       was not called.  If not null, then you must check o_errlHndl
        *       to see if the constructor ran successfully.If o_errlHndl
        *       indicates an error was reported by the constructor, new has
        *       already allocated heap storage and the object must be deleted in
        *       order to free the heap storage.
        *
        * @pre None
        * @param o_errlHndl  output error handle
        *
        * @param i_eyeCatcher input the eyecatcher string
        * @param i_dataPtrCnt input data array pointer count
        * @param i_instance input object instance
        * @param i_childCnt input child count
        * @param i_ver input version number
        *
        * @post An HdatHdif object has been constructed.  Heap storage has been
        * allocated.
        *
        * @return A null error log handle if successful, else the return code
        *         pointed to by errlHndl_t contains one of:
        *
        * @retval HDAT_ALLOC_ERROR
        */
        HdatHdif();

        HdatHdif(errlHndl_t &o_errlHndl,
                 const char i_eyeCatcher[],
                 uint32_t i_dataPtrCnt,
                 uint32_t i_instance = 0,
                 uint32_t i_childCnt = 0,
                 uint32_t i_ver = 1);


       /**
        * @brief HdatHdif object destructor
        *
        * @pre None
        *
        * @post Heap storage is deallocated
        *
        */
        virtual ~HdatHdif();


       /**
        * @brief Change the offset to the beginning of a set of children
        *
        * @pre i_childCnt from ctor must be greater than 0 (not checked)
        *
        * @post Total object size is updated.  Child structure pointer entry is
        * updated
        *
        * @param i_whichChildEntry -
        *        input parameter - An array index for the children being added.
        *        This is a 0 based array index so the first entry being added
        *        would specify 0 for this parameter.
        *        i_whichChildEntry < i_childCnt from ctor (not checked)
        * @param i_size            -
        *        input parameter - The size of the child structure(s)
        * @param i_numChildStr     -
        *        input parameter - The number of children being added.
        *
        */
        void addChild(uint32_t i_whichChildEntry,
                        uint32_t i_size,
                        uint32_t i_numChildStr);


       /**
        * @brief Add a grandchild structure entry to the base object.
        *
        * @pre None
        *
        * @post Total object size is updated.
        *
        * @param i_size - input parameter - The size of the grandchild structure
        *
        */
        void addGrandChild(uint32_t i_size);


       /**
        * @brief Add internal data pointer entry to the base object.
        *        When a hypervisor data structure has internal data , an array
        *        of data pointers(hdatHDIFDataHdr_t) is maintained to address
        *        the internal data areas.  This method is used to maintain the
        *        array of data pointers.
        *
        * @pre i_dataPtrCnt from ctor must be greater than 0 (not checked)
        *
        * @post Total object size is updated.  Internal data pointer entry is
        * updated
        *
        * @param i_whichDataEntry -
        *        input parameter - An array index for the data entry being added
        *        This is a 0 based array index so the first entry being added
        *        would specify 0 for this parameter.
        *        i_whichDataEntry < i_dataPtrCnt from ctor (not checked)
        * @param i_size           -
        *        input parameter - The size of the internal data
        *
        */
        void addData(uint32_t i_whichDataEntry,
                     uint32_t i_size);

        /**
         * @brief Some objects which have siblings must all be the same size
         * so thatPHYP can traverse through them as elements of an array. Since
         * the size of all the siblings is not known until the last sibling has
         * been built, this method is used to ensure all objects are padded
         * to the same size
         *
         * @pre None
         * @post Total object size is updated. Pad size computed
         * @param i_numBytes - input parameter - size, in bytes, of the
         *                     maximum sized object
         */

        void maxSiblingSize(uint32_t i_numBytes);



       /**
        * @brief After the derived object is constructed, all data pointers have
        *        been added,and the maximum number of child structures have been
        *        computed, this method must be called to "pad" the object to a
        *        nice byte boundary (currently 16 byte boundaries are used).
        *
        * @pre actual or maximum number of child structures were provided on
        *      the constructor
        *      all calls to addData() have been completed
        *
        * @post Total object size is updated. Pad size computed.
        *
        */
        void align();

        /**
         * @brief The current object size is returned. This is the size of
         * an HDIF object.  It does NOT include sizes of children or
         * grandchildren
         *
         * @pre None
         *
         * @post None
         *
         * @return Object size
         */
         uint32_t size();

         /*
          * @brief  write Hdif header to memory
          *
          * @pre the object must have been constructed
          *
          * @param io_virt_addr input virtual address to write at
          *
          * @post data is written to host memory
          *
          * @return the next address to write at
          *
          */
         uint8_t * setHdif(uint8_t * io_virt_addr);


         /*
          * @brief write the required padding
          *
          * @pre the object must have been constructed
          *
          * @param io_virt_addr input virtual address to write at
          * @param o_size  output size of the object
          * @post pad is written to host memory
          *
          * @return the next address to write at
          */

         uint8_t *setpadding(uint8_t * io_virt_addr,
                             uint32_t& o_size );


         /*
          * @brief get the child offset
          *
          * daughter data must have been constructed
          *
          * return uint32_t offset value
          */

         uint32_t getChildOffset ();
       /**
        * @brief Update the offset to the beginning of a child structure(s)
        *
        *        Complex strcutures which can have grandchilren (such as the
        *        HdatVpd object) may not be able to build the object pieces in
        *        the desired order.  Thus offsets to chilren structures can be
        *        in error.  When the objects are complete and are ready to be
        *        commited, they can be done so in the correct order but the
        *        offsets will have to be updated first.
        *
        * @pre None
        *
        * @post None
        *
        * @param[in] i_whichChildEntry - An array index for the child triple
        *           entry.This is a 0 based array index so the first entry would
        *           specify 0 for this parameter. i_whichChildEntry < i_childCnt
        *           from ctor (not checked)
        * @param[in] i_offset  - new offset value
        *
        * @return None
        *
        */
        void chgChildOffset(uint32_t i_whichChildEntry,
                               uint32_t i_offset);
       /**
        * @brief The object data is written to ms memory
        *
        *
        * @pre The derived object must be complete.
        *
        * @post The base class data is flattened and written to a ms area
        *
        * @param[in]i_data - input memory that contains data
        *
        */
        void startCommit(UtilMem &i_data);

       /**
        * @brief print out the HdatHdif object data
        *
        * @pre None
        *
        * @post output sent to stdout
        *
        */
        void print();

       /**
        * @brief Any padding that must be done to make the structure align
        * properly is performed and the msarea containing the data structure is 
        * not closed.
        *
        * @pre None
        *
        * @post
        *
        * @param[in]i_data - input memory that contains data
        *
        */
        void endCommit(UtilMem &i_data);

       /**
        * @brief Get endCommit size if there is any padding applied
        * @pre None
        *
        * @post
        *
        * @return - size
        */
        uint32_t endCommitSize();

       /**
        * @brief Get the complete size of base object that needs to be written
        * to MS memory
        * @pre None
        *
        * @post
        *
        * @return - size
        */
        uint32_t getSize();



    private:


        /** Object Instance Data
         *
         * @li iv_totalSize      - total number of bytes of structure and all
         *                         its children and grandchildren
         * @li iv_padSize        - number of bytes to pad structure to a
         *                         boundary (such as a nice 16 byte boundary)
         * @li iv_siblingPadSize - the padding to be added
         * @li iv_dataPtrSize    - size of the internal data pointers array
         *                         section
         * @li iv_childPtrSize   - size of the child pointers section
         * @li iv_hdr            - the basic HDIF header
         * @li iv_dataPtrs       - heap storage for the internal data pointers
         *                         section
         * @li iv_childPtrs      - heap storage for the internal child structure
         *                         pointers section
         */
        uint32_t             iv_totalSize;
        uint32_t             iv_padSize;
        uint32_t             iv_siblingPadSize;
        uint32_t             iv_dataPtrSize;
        uint32_t             iv_childPtrSize;
        hdatHDIF_t           iv_hdr;
        hdatHDIFDataHdr_t   *iv_dataPtrs;
        hdatHDIFChildHdr_t  *iv_childPtrs;

}; // end of HdatHdif class

}//end namespace

#endif // HDATHDIF_H
