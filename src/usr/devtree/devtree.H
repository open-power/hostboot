/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/devtree.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
#include <devtree/devtreeif.H>

#ifndef _DEVTREE_H
#define _DEVTREE_H

namespace DEVTREE
{
typedef size_t dtOffset_t;


    /**
     * The devtree class that does the actual work of
     * generating and manipulating the devtree
     *
     */
    class devTree
    {
      public:

        /**
         * Initialize the FDT at address and size
         * @param[in] i_addr     Address to place FDT at
         * @param[in] i_maxSize  Size of FDT
         * @param[in] i_virtual  Address is virtual.
         */
        void initialize(uint64_t i_addr, size_t i_maxSize, bool i_virtual);

        /**
         * Find given node (e.g. "/lpc") in the FDT
         * @param[in] nodePath  NULL terminated string of the path
         * @return dtOffset_t into FDT of node location
         */
        dtOffset_t findNode(const char* nodePath);

        /**
         * Find and return a pointer to a property within a node
         * @param[in] nodeOffset    Offset into FDT to start looking
         * @param[in] propertyName  NULL terminated string of the property
                                    to get
         * @return void* pointer to dtOffset_t into FDT of node location
         */
        void* findProperty(dtOffset_t nodeOffset, const char* propertyName);

        /**
         * Add a new node under the parent node
         * @param[in] parentNode  Offset to parent node
         * @param[in] nodeName    NULL terminated string of node to add
         * @return dtOffset_t into FDT of node location
         */
        dtOffset_t addNode(dtOffset_t parentNode, const char* nodeName);

        /**
         * Add a new node under the parent node with address
         * @param[in] parentNode  Offset to parent node
         * @param[in] nodeName    NULL terminated string of node to add
         * @param[in] unitAddress Address of the node
         * @return dtOffset_t into FDT of node location
         */
       dtOffset_t addNode(dtOffset_t parentNode, const char* nodeName,
                           uint64_t unitAddress);

       /**
        * Add a property to a node with no data
        * @param[in] parentNode    Offset to node to add property to
        * @param[in] propertyName  NULL terminated string of property name
        */
        void addProperty(dtOffset_t parentNode, const char* propertyName);

        /**
         * Add a property to a node with free form bytes
         * @param[in] parentNode    Offset to node to add property to
         * @param[in] propertyName  NULL terminated string of property name
         * @param[in] propertyData  Data to add
         * @param[in] numBytes  Number of data bytes
         */
        void addPropertyBytes(dtOffset_t parentNode, const char* propertyName,
                              const uint8_t* propertyData, uint32_t numBytes);

        /**
         * Add a property to a node with string data
         * @param[in] parentNode    Offset to node to add property to
         * @param[in] propertyName  NULL terminated string of property name
         * @param[in] propertyData  NULL terminated string data
         */
        void addPropertyString(dtOffset_t parentNode, const char* propertyName,
                               const char* propertyData);

        /**
         * Add a property to a node with array of strings
         * @param[in] parentNode    Offset to node to add property to
         * @param[in] propertyName  NULL terminated string of property name
         * @param[in] propertyData  NULL terminated array of strings, last
         *                          string must be NULL
         */
        void addPropertyStrings(dtOffset_t parentNode, const char* propertyName,
                                const char** propertyData);

        /**
         * Add a property to a node with a 32 bit "cell" (aka uint32_t data)
         * @param[in] parentNode    Offset to node to add property to
         * @param[in] propertyName  NULL terminated string of property name
         * @param[in] cell  Data to add
         */
        void addPropertyCell32(dtOffset_t parentNode, const char* propertyName,
                               const uint32_t cell);

        /**
         * Add a property to a node with a 64 bit "cell" (aka uint64_t data)
         * @param[in] parentNode    Offset to node to add property to
         * @param[in] propertyName  NULL terminated string of property name
         * @param[in] cell  Data to add
         */
        void addPropertyCell64(dtOffset_t parentNode, const char* propertyName,
                               const uint64_t cell);

        /**
         * Add a property to a node with a 32 bit array of "cells"
         * (aka uint32_t data)
         * @param[in] parentNode    Offset to node to add property to
         * @param[in] propertyName  NULL terminated string of property name
         * @param[in] cells         Array of uint32_t data
         * @param[in] numCells      Number of cells
         */
        void addPropertyCells32(dtOffset_t parentNode, const char* propertyName,
                                uint32_t cells[], uint32_t numCells);

        /**
         * Add a property to a node with a 64 bit array of "cells"
         * (aka uint64_t data)
         * @param[in] parentNode    Offset to node to add property to
         * @param[in] propertyName  NULL terminated string of property name
         * @param[in] cells         Array of uint64_t data
         * @param[in] numCells      Number of cells
         */
        void addPropertyCells64(dtOffset_t parentNode, const char* propertyName,
                                uint64_t cells[], uint32_t numCells);

        /**
         * Return the physical "blob" address to the start of the FDT
         * @return uin64_t to the start of the FDT memory
         */
        uint64_t getBlobPhys();

        /**
         * Each devtree node has a "handle" number.  This function returns the
         * handle number for given node.
         * @param[in] nodeOffset    Offset to node
         * @return uin32_t Handle number for node
         */
        uint32_t getPhandle(dtOffset_t nodeOffset);

        /**
         * Append bytes to a property
         * @param[in] parentNode    Offset to node to add property to
         * @param[in] propertyName  NULL terminated string of property name
         * @param[in] propertyData  Data to add
         * @param[in] numBytes  Number of data bytes
         */
       void appendPropertyBytes(dtOffset_t parentNode,
                                 const char* propertyName,
                                 const uint8_t* propertyData,
                                 uint32_t numBytes);

        /**
         * Populate reserved memory regions
         * @param[in] i_addrs    Array of addresses to set in reserved memory
         * @param[in] i_sizes    Array of sizes to set in reserved memory
         * @param[in] i_num      Number of elements in the arrays
         * @return int, zero on sucesses otherwise non zero
         */
       int populateReservedMem(uint64_t i_addrs[],
                               uint64_t i_sizes[],
                               size_t i_num);

       /**
        * Return the current size of the FDT (not max)
        * @return uin32_t Size of the FDT
        */
        uint32_t getSize();


      protected:
        /*Constructor*/
        devTree();

        /*Destructor*/
        ~devTree();

        /**
         * Get the internal struct section at node offset
         * @param[in] offset    Offset to node
         * @return uin32_t* pointer to struct section
         */
       inline uint32_t* getStructSectionAtOffset(dtOffset_t offset);

        /**
         * Utility function to get the length fo the tag/name words for
         * given node
         * @param[in] nodeOffset    Offset to node
         * @return int Words consumed by tag/name in FDT
         */
       int getNodeTagAndNameWords(dtOffset_t nodeOffset);

       /**
        * Utility function to get the length fo the tag/name words for
        * given node
        * @param[in] nodeOffset    Offset to node
        * @return int Words consumed by tag/name in FDT
        */
       void insertStructSpace(uint32_t offset, int numNewWords);

       /**
        * Utility function to shift the string section
        * @param[in] shiftSize  Amount to shift
        */
       void shiftStringsSection(int shiftSize);

       /**
        * Get number of words for property
        * @param[in] propertyOffset  Offset of property
        * @return int Words consumed by Property
        */
      int getPropertyWords(int propertyOffset);

       /**
        * Utility function to add String to string table
        * @param[in] string  NULL terminated string to add
        * @return dtOffset_t Offset string was added at
        */
       dtOffset_t addString(const char *string);

       /**
        * Set the boot CPU PIR into FDT
        * @param[in] pir  PIR value for boot processor
        */
       void setBootCpu(uint32_t pir);

       /**
        * Utility function to locate string in string table
        * @param[in] string  NULL terminated string to find
        * @param[out] stringOffset Offset if found
        * @return bool  True if found
        */
       bool locateStringOffset(const char* string, uint32_t& stringOffset);


      private:

        enum Constants {
            DT_MAGIC            =0xd00dfeed,
            DT_CUR_VERSION      =0x11,
            DT_COMPAT_VERSION   =0x10,

            DT_BEGIN_NODE       =0x1,
            DT_END_NODE         =0x2,
            DT_PROP             =0x3,
            DT_NOP              =0x4,
            DT_END              =0x9,
            DT_INVALID_OFFSET   =0xFFFFFFFF,


            DT_MAX_MEM_RESERVE  =16,

        };


        typedef struct dtHeader
        {
            uint32_t magicNumber;
            uint32_t totalSize;
            uint32_t offsetStruct;
            uint32_t offsetStrings;
            uint32_t offsetReservedMemMap;
            uint32_t version;
            uint32_t lastCompatVersion;
            uint32_t bootCpuId;
            uint32_t sizeStrings;
            uint32_t sizeStruct;
        }
        dtHeader_t;

        typedef struct dtReserveEntry
        {
            uint64_t address;
            uint64_t size;
        }
        dtReserveEntry_t;



        union
        {
            dtHeader_t* mHeader;
            char* mSpace;
        };
        uint32_t mNextPhandle;
        size_t mMaxSize;
        uint64_t mPhysAddr;

        // let my testcase poke around
        friend class devTreeTest;

    };



    uint32_t* devTree::getStructSectionAtOffset(dtOffset_t offset)
    {
        return (uint32_t*) (mSpace + mHeader->offsetStruct + offset);
    }
}
#endif /* _DEVTREE_H */
