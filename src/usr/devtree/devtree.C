/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/devtree.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "devtree.H"
#include <sys/mm.h>
#include <limits.h>

extern trace_desc_t *g_trac_devtree;

#define DEBUGOUT(msg...)
#define DEBUGOUTB(data,len,msg...)
//#define DEBUGOUT(msg...)  TRACFCOMP(g_trac_devtree,msg)
//#define DEBUGOUTB(data,len,msg...)  DEBUGOUT(msg);TRACFBIN(g_trac_devtree,"",data,len);

namespace DEVTREE
{

uint64_t devTree::getBlobPhys()
{
    return mPhysAddr;
}

uint32_t devTree::getSize()
{
    return mHeader->totalSize;
}

void devTree::initialize(uint64_t i_addr, size_t i_maxSize, bool i_virtual)
{
    /* Initialize the device tree header. */
    mMaxSize = i_maxSize;
    if (i_virtual)
    {
        mPhysAddr = 0;
        mSpace = reinterpret_cast<char*>(i_addr);
    }
    else
    {
        mPhysAddr = i_addr;
        mSpace= static_cast<char*>
                    (mm_block_map(reinterpret_cast<void*>(mPhysAddr),
                    mMaxSize));
    }
    memset(mSpace, 0, mMaxSize);
    mNextPhandle = 0x10000000;

    TRACFCOMP( g_trac_devtree, "FDT located @ v:%p p:0x%x", mSpace, mPhysAddr);

    mHeader->magicNumber = DT_MAGIC;
    mHeader->totalSize = (sizeof(*mHeader) +
                          (sizeof(dtReserveEntry_t) * DT_MAX_MEM_RESERVE));
    mHeader->offsetStruct = mHeader->totalSize;
    mHeader->offsetStrings = mHeader->totalSize;
    mHeader->offsetReservedMemMap = sizeof(*mHeader);
    mHeader->version = DT_CUR_VERSION;
    mHeader->lastCompatVersion = DT_COMPAT_VERSION;
    mHeader->bootCpuId = 0;
    mHeader->sizeStrings = 0;
    mHeader->sizeStruct = 0;

    /* Create the initial root node. */
    uint32_t* curWord = getStructSectionAtOffset(0);
    *curWord++ = DT_BEGIN_NODE;
    *curWord++ = 0;
    *curWord++ = DT_END_NODE;
    *curWord = DT_END;

    /* Adjust offsets and sizes to account for the root node we just added*/
    uint32_t structSizeAdded = sizeof(uint32_t) * 4;
    mHeader->offsetStrings += structSizeAdded;
    mHeader->sizeStruct += structSizeAdded;
    mHeader->totalSize += structSizeAdded;

    /* Add the standard root node properties. */
    dtOffset_t rootNode = findNode("/");
    addPropertyCell32(rootNode, "#address-cells", 2);
    addPropertyCell32(rootNode, "#size-cells", 2);

    //"Get" the phandle -- this will add one to root node as
    //it doesn't already have one
    getPhandle(rootNode);
}

void devTree::setBootCpu(uint32_t pir)
{
    mHeader->bootCpuId = pir;
}

dtOffset_t devTree::findNode(const char* nodePath)
{
    /* Get structure section and start out with the name of first node*/
    uint32_t* curWord = getStructSectionAtOffset(0);
    dtOffset_t curOffset = 0;

    if(strlen(nodePath) == 1)
    {
        if(nodePath[0] == '/')
        {
            return 0;
        }
        else
        {
            return DT_INVALID_OFFSET;
        }
    }

    nodePath++;
    int nodeNestLevel = 0;
    curWord += 2;
    curOffset += 8;
    do
    {
        nodeNestLevel = 0;
        /* Figure out how long the name of the current portion
         of the path we're looking for is. */
        int currentPathLength = 0;
        while(nodePath[currentPathLength] &&
              (nodePath[currentPathLength] != '/'))
        {
            currentPathLength++;
        }
        int done = 0;
        do
        {
            switch(*curWord)
            {
            case DT_BEGIN_NODE:
                {
                    if(nodeNestLevel == 0)
                    {
                        if(memcmp(curWord+1, nodePath, currentPathLength) == 0)
                        {
                            if(nodePath[currentPathLength] == NULL)
                            {
                                return curOffset;
                            }
                            else
                            {
                                done = 1;
                            }
                        }
                    }

                    nodeNestLevel++;

                    /* Figure out how far to advance to get past this node entry
                       Start by skipping over the node name. */
                    int nodeSkipWords = getNodeTagAndNameWords(curOffset);
                    curWord += nodeSkipWords;
                    curOffset += nodeSkipWords * 4;
                }
                break;

            case DT_END_NODE:
                {
                    if(nodeNestLevel == 0)
                    {
                        return DT_INVALID_OFFSET;
                    }
                    else
                    {
                        nodeNestLevel--;
                        /* Skip over the node end tag. */
                        curWord++;
                        curOffset += 4;
                    }
                }
                break;

            case DT_PROP:
                {
                    /* Skip over the property. */
                    curWord++;
                    int propSkiWords = ((*curWord + 3) / 4) + 2;
                    curWord += propSkiWords;
                    curOffset += (propSkiWords + 1) * 4;
                }
                break;

            case DT_NOP:
                {
                    curWord++;
                    curOffset += 4;
                }
                break;

            case DT_END:
                return DT_INVALID_OFFSET;
                break;

            default:
                return DT_INVALID_OFFSET;
                break;
            }
        }
        while(!done);
        nodePath += currentPathLength + 1;
    }
    while(*nodePath != NULL);

    /* We should never get here. */
    return DT_INVALID_OFFSET;
}

dtOffset_t devTree::addNode(dtOffset_t parentNodeOffset, const char* nodeName)
{
    DEBUGOUT("DT> addNode:%s",nodeName);
    uint32_t* curWord = getStructSectionAtOffset(parentNodeOffset);
    int skipWords = getNodeTagAndNameWords(parentNodeOffset);

    curWord += skipWords;
    dtOffset_t newNodeOffset = parentNodeOffset + (skipWords * 4);

    /* There is a FDT rule that nodes must be after properties
       so skip over any properties. */
    while(*curWord == DT_PROP)
    {
        int propertyWords = getPropertyWords(newNodeOffset);
        curWord += propertyWords;
        newNodeOffset += propertyWords * 4;
    }

    size_t newNodeNameLength = strlen(nodeName);
    int newNodeNameWords = (newNodeNameLength + 4) / 4;
    insertStructSpace(newNodeOffset, newNodeNameWords + 2);

    *curWord++ = DT_BEGIN_NODE;
    for(int i = 0; i < newNodeNameWords; ++i)
    {
        *curWord = 0;
        memcpy(curWord, nodeName + (i * 4),
               newNodeNameLength < 4 ? newNodeNameLength : 4);
        if(newNodeNameLength < 4)
        {
            newNodeNameLength = 0;
        }
        else
        {
            newNodeNameLength -= 4;
        }
        curWord++;
    }

    *curWord = DT_END_NODE;

    /* Always tack on a pHandle to each new node*/
    uint32_t newPhandle = mNextPhandle++;
    addPropertyCell32(newNodeOffset, "phandle", newPhandle);

    return newNodeOffset;
}

dtOffset_t devTree::addNode(dtOffset_t parentNodeOffset,
                            const char* nodeName, uint64_t unitAddress)
{
    char nodeNameWithUnitAddress[1024];
    sprintf(nodeNameWithUnitAddress, "%s@%lx", nodeName, unitAddress);
    return addNode(parentNodeOffset, nodeNameWithUnitAddress);
}

void devTree::addProperty(dtOffset_t parentNodeOffset, const char* propertyName)
{
    uint32_t* curWord = getStructSectionAtOffset(parentNodeOffset);
    int skipWords = getNodeTagAndNameWords(parentNodeOffset);

    curWord += skipWords;
    dtOffset_t newPropertyOffset = parentNodeOffset + (skipWords * 4);
    insertStructSpace(newPropertyOffset, 3);

    *curWord++ = DT_PROP;
    *curWord++ = 0;
    *curWord++ = addString(propertyName);
    DEBUGOUT("DT> addProperty:%s",propertyName);
}

void devTree::addPropertyString(dtOffset_t parentNodeOffset,
                                const char* propertyName,
                                const char* propertyData)
{
    DEBUGOUT("DT> addPropertyString:%s=%s",propertyName,propertyData);
    uint32_t* curWord = getStructSectionAtOffset(parentNodeOffset);
    int skipWords = getNodeTagAndNameWords(parentNodeOffset);

    curWord += skipWords;
    dtOffset_t newPropertyOffset = parentNodeOffset + (skipWords * 4);
    size_t newPropertyDataLength = strlen(propertyData);
    int newPropertyDataWords = (newPropertyDataLength + 4) / 4;
    insertStructSpace(newPropertyOffset, newPropertyDataWords + 3);

    *curWord++ = DT_PROP;
    *curWord++ = newPropertyDataLength + 1;
    *curWord++ = addString(propertyName);

    for(int i = 0; i < newPropertyDataWords; ++i)
    {
        *curWord = 0;
        memcpy(curWord, propertyData + (i * 4),
               newPropertyDataLength < 4 ? newPropertyDataLength : 4);
        if(newPropertyDataLength < 4)
        {
            newPropertyDataLength = 0;
        }
        else
        {
            newPropertyDataLength -= 4;
        }
        curWord++;
    }
}

void devTree::addPropertyBytes(dtOffset_t parentNodeOffset,
                               const char* propertyName,
                               const uint8_t* propertyData,
                               uint32_t numBytes)
{
    DEBUGOUTB(propertyData,numBytes,"DT> addPropertyBytes:%s=",propertyName);
    uint32_t* curWord = getStructSectionAtOffset(parentNodeOffset);
    int skipWords = getNodeTagAndNameWords(parentNodeOffset);

    curWord += skipWords;
    dtOffset_t newPropertyOffset = parentNodeOffset + (skipWords * 4);
    size_t newPropertyDataLength = numBytes;
    int newPropertyDataWords = (newPropertyDataLength + 3) / 4;
    insertStructSpace(newPropertyOffset, newPropertyDataWords + 3);

    *curWord++ = DT_PROP;
    *curWord++ = newPropertyDataLength;
    *curWord++ = addString(propertyName);

    for(int i = 0; i < newPropertyDataWords; ++i)
    {
        *curWord = 0;
        memcpy(curWord, propertyData + (i * 4),
               newPropertyDataLength < 4 ? newPropertyDataLength : 4);
        if(newPropertyDataLength < 4)
        {
            newPropertyDataLength = 0;
        }
        else
        {
            newPropertyDataLength -= 4;
        }
        curWord++;
    }
}

void devTree::addPropertyStrings(dtOffset_t parentNodeOffset,
                                 const char* propertyName,
                                 const char** propertyData)
{
    uint32_t* curWord = getStructSectionAtOffset(parentNodeOffset);
    int skipWords = getNodeTagAndNameWords(parentNodeOffset);

    size_t totalDataSize = 0;
    int numStrings = 0;
    /* Figure out the total size of the data in the property. */
    for(int stringIndex = 0;
        propertyData[stringIndex] && *propertyData[stringIndex]; stringIndex++)
    {
        totalDataSize += strlen(propertyData[stringIndex]) + 1;
        numStrings++;
    }

    curWord += skipWords;
    dtOffset_t newPropertyOffset = parentNodeOffset + (skipWords * 4);
    size_t newPropertyDataLength = totalDataSize;
    int newPropertyDataWords = (newPropertyDataLength + 3) / 4;
    insertStructSpace(newPropertyOffset, newPropertyDataWords + 3);

    *curWord++ = DT_PROP;
    *curWord++ = newPropertyDataLength ;
    *curWord++ = addString(propertyName);
    DEBUGOUT("DT> addPropertyStrings:%s",propertyName);

    for(int i = 0; i < newPropertyDataWords; ++i)
    {
        *(curWord + i) = 0;
    }

    char* target = (char*)curWord;
    for(int stringIndex = 0; stringIndex < numStrings; stringIndex++)
    {
        DEBUGOUT("DT>    %s",propertyData[stringIndex]);
        size_t curStringLen = strlen(propertyData[stringIndex]);
        memcpy(target, propertyData[stringIndex], curStringLen);
        target += curStringLen + 1;
    }
}

void devTree::addPropertyCell32(dtOffset_t parentNodeOffset,
                                const char* propertyName,
                                const uint32_t cell)
{
    uint32_t cells[1] = { cell };
    addPropertyCells32(parentNodeOffset, propertyName, cells, 1);
}

void devTree::addPropertyCell64(dtOffset_t parentNodeOffset,
                                const char* propertyName,
                                const uint64_t cell)
{
    uint64_t cells[1] = { cell };
    addPropertyCells64(parentNodeOffset, propertyName, cells, 1);
}

void devTree::addPropertyCells32(dtOffset_t parentNodeOffset,
                                 const char* propertyName,
                                 uint32_t cells[], uint32_t numCells)
{
    uint32_t* curWord = getStructSectionAtOffset(parentNodeOffset);
    int skipWords = getNodeTagAndNameWords(parentNodeOffset);

    curWord += skipWords;
    dtOffset_t newPropertyOffset = parentNodeOffset + (skipWords * 4);
    int newPropertyDataLength = numCells * 4;
    int newPropertyDataWords = numCells;
    insertStructSpace(newPropertyOffset, newPropertyDataWords + 3);

    *curWord++ = DT_PROP;
    *curWord++ = newPropertyDataLength;
    *curWord++ = addString(propertyName);
    DEBUGOUT("DT> addPropertyCells32:%s",propertyName);

    for(uint32_t i = 0; i < numCells; ++i)
    {
        DEBUGOUT("DT>    %.8X",cells[i]);
        *curWord++ = cells[i];
    }
}

void devTree::addPropertyCells64(dtOffset_t parentNodeOffset,
                                 const char* propertyName,
                                 uint64_t cells[], uint32_t numCells)
{
    uint32_t* curWord = getStructSectionAtOffset(parentNodeOffset);
    int skipWords = getNodeTagAndNameWords(parentNodeOffset);

    curWord += skipWords;
    dtOffset_t newPropertyOffset = parentNodeOffset + (skipWords * 4);
    int newPropertyDataLength = numCells * 8;
    int newPropertyDataWords = numCells * 2;
    insertStructSpace(newPropertyOffset, newPropertyDataWords + 3);

    *curWord++ = DT_PROP;
    *curWord++ = newPropertyDataLength;
    *curWord++ = addString(propertyName);
    DEBUGOUT("DT> addPropertyCells32:%s",propertyName);

    for(uint32_t i = 0; i < numCells; ++i)
    {
        DEBUGOUT("DT>    %.16X",cells[i]);
        *curWord++ = cells[i] >> 32;
        *curWord++ = cells[i];
    }
}

int devTree::getNodeTagAndNameWords(dtOffset_t nodeOffset)
{
    size_t nodeNameAndTagWords = 1;
    uint32_t* curWord = getStructSectionAtOffset(nodeOffset);
    nodeNameAndTagWords += (strlen((char*)(curWord + 1)) + 4) / 4;
    return nodeNameAndTagWords;
}

void devTree::insertStructSpace(uint32_t offset, int numNewWords)
{
    uint32_t* firstWord = getStructSectionAtOffset(0);
    int numCurrentWords = mHeader->sizeStruct / 4;
    /* Mode the string section out of the way first. */
    shiftStringsSection(numNewWords * 4);
    /* Now insert space into the struct section. */
    assert((mHeader->totalSize + (numNewWords * 4)) < mMaxSize);
    mHeader->sizeStruct += numNewWords * 4;
    mHeader->totalSize += numNewWords * 4;

    uint32_t* srcWord = firstWord + numCurrentWords - 1;
    uint32_t* tgtWord = firstWord + numCurrentWords + numNewWords - 1;
    int numCopyWords = numCurrentWords - (offset / 4);
    while(numCopyWords--)
    {
        *tgtWord = *srcWord;
        tgtWord--;
        srcWord--;
    };
}

void devTree::shiftStringsSection(int shiftSize)
{
    /* We always move it forward so copy it from the end to the beginning. */
    uint32_t stringSectionSize = mHeader->sizeStrings;
    char* src = mSpace + mHeader->offsetStrings;
    char* tgt = src + shiftSize;

    memmove(tgt, src, stringSectionSize);

    mHeader->offsetStrings += shiftSize;

    /* Clear out the area we just shifted out of so that it's easier to
       debug the blob. */
    memset(src, 0, shiftSize);
}

int devTree::getPropertyWords(int propertyOffset)
{
    int propertyWords = 3;
    uint32_t* curWord = getStructSectionAtOffset(propertyOffset);
    curWord++; /* Skip over the DT_PROP tag */
    propertyWords += (*curWord + 3) / 4;
    return propertyWords;
}

dtOffset_t devTree::addString(const char *string)
{
    dtOffset_t stringOffset = 0;
    size_t stringSize = strlen(string) + 1;
    char* stringSection = mSpace + mHeader->offsetStrings;
    uint32_t stringSectionSize = mHeader->sizeStrings;

    /* Search for the string as long as we know it could still be there. */
    while(stringSize <= (stringSectionSize - stringOffset))
    {
        if(memcmp(stringSection, string, stringSize) == 0)
        {
            return stringOffset;
        }
        else
        {
            size_t curStringLength = strlen(stringSection) + 1;
            stringOffset += curStringLength;
            stringSection += curStringLength;
        }
    }

    /* We didn't find a string to reuse so tack this one on the end. */
    stringOffset = mHeader->sizeStrings;
    memcpy(mSpace + mHeader->offsetStrings + stringOffset, string, stringSize);
    assert((mHeader->totalSize + stringSize) < mMaxSize);
    mHeader->sizeStrings += stringSize;
    mHeader->totalSize += stringSize;
    return stringOffset;
}

bool devTree::locateStringOffset(const char* string, uint32_t& stringOffset)
{
    bool foundStringOffset = false;
    stringOffset = 0;
    size_t stringSize = strlen(string) + 1;
    char* stringSection = mSpace + mHeader->offsetStrings;
    uint32_t stringSectionSize = mHeader->sizeStrings;

    /* Search for the string as long as we know it could still be there. */
    while(stringSize <= (stringSectionSize - stringOffset))
    {
        if(memcmp(stringSection, string, stringSize) == 0)
        {
            foundStringOffset = true;
            break;
        }
        else
        {
            size_t curStringLength = strlen(stringSection) + 1;
            stringOffset += curStringLength;
            stringSection += curStringLength;
        }
    }

    return foundStringOffset;
}

void* devTree::findProperty(dtOffset_t nodeOffset, const char* propertyName)
{
    uint32_t nameOffset = 0;
    void *propertyData = NULL;

    if(locateStringOffset(propertyName, nameOffset))
    {
        uint32_t* curWord = getStructSectionAtOffset(nodeOffset);
        int skipWords = getNodeTagAndNameWords(nodeOffset);

        curWord += skipWords;
        dtOffset_t curOffset = nodeOffset + (skipWords * 4);

        while(*curWord == DT_PROP)
        {
            /* Check if this is the property we are searching for. */
            if(*(curWord + 2) == nameOffset)
            {
                /* It is, we found it. */
                return (void*)(curWord + 3);
            }
            else
            {
                int propertyWords = getPropertyWords(curOffset);
                curWord += propertyWords;
                curOffset += propertyWords * 4;
            }
        }
    }

    return propertyData;
}

uint32_t devTree::getPhandle(dtOffset_t nodeOffset)
{
    uint32_t* phandlePtr = (uint32_t*) findProperty(nodeOffset, "phandle");
    if(phandlePtr)
    {
        return *phandlePtr;
    }

    /* We didn't find a phandle, so we need to add one. */
    uint32_t newPhandle = mNextPhandle++;
    addPropertyCell32(nodeOffset, "phandle", newPhandle);
    return newPhandle;
}

void devTree::appendPropertyBytes(dtOffset_t parentNode,
                                  const char* propertyName,
                                  const uint8_t* propertyData,
                                  uint32_t numBytes)
{
    uint32_t nameOffset = 0;

    if(locateStringOffset(propertyName, nameOffset))
    {
        uint32_t* curWord = getStructSectionAtOffset(parentNode);
        int skipWords = getNodeTagAndNameWords(parentNode);

        curWord += skipWords;
        dtOffset_t curOffset = parentNode + (skipWords * 4);

        while(*curWord == DT_PROP)
        {
            /* Check if this is the property we are searching for. */
            if(*(curWord + 2) == nameOffset)
            {
                /* It is, we found it. */
                uint32_t curPropertyDataLength = *(curWord + 1);
                *(curWord + 1) = curPropertyDataLength + numBytes;
                uint8_t* newDataLocation = ((uint8_t*)(curWord + 3))
                                           + curPropertyDataLength;
                uint32_t curPropertyDataWords = (curPropertyDataLength + 3) / 4;
                uint32_t newPropertyDataWords = (curPropertyDataLength
                                                 + numBytes + 3) / 4;
                uint32_t propertyDataWordsToAdd = newPropertyDataWords
                                                  - curPropertyDataWords;
                if(propertyDataWordsToAdd)
                {
                    uint32_t insertOffset =curOffset +
                                           ((3 + curPropertyDataWords) * 4);
                    insertStructSpace(insertOffset, propertyDataWordsToAdd);
                }
                memcpy(newDataLocation, propertyData, numBytes);
                break;
            }
            else
            {
                int propertyWords = getPropertyWords(curOffset);
                curWord += propertyWords;
                curOffset += propertyWords * 4;
            }
        }
    }
}

int devTree::populateReservedMem(uint64_t i_addrs[],
                               uint64_t i_sizes[],
                               size_t i_num)
{
    int rc = 1;

    //if requested num is less than max, update
    if(i_num < DT_MAX_MEM_RESERVE)
    {
        dtReserveEntry* reserveMemMap = reinterpret_cast<dtReserveEntry*>
          (mSpace + mHeader->offsetReservedMemMap);

        for(size_t i=0; i<i_num; i++)
        {
            reserveMemMap->address = i_addrs[i];
            reserveMemMap->size = i_sizes[i];

            reserveMemMap++;
        }

        rc = 0;
    }

    return rc;
}


/********************
Internal Methods
********************/

/**
 * @brief  Constructor
*/
devTree::devTree()
:mSpace(NULL), mMaxSize(0)
{
    //Nothing right now...
}

/**
 * @brief  Destructor
 */
devTree::~devTree()
{
    if (mPhysAddr)
    {
        mm_block_unmap(mSpace);
    }
}

}
