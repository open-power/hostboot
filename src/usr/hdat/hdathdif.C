/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdathdif.C $                                     */
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
/**
 * @file hdathdif.C
 *
 * @brief This file contains the implementation of the HdatHdif class.
 *
 */


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include "hdathdif.H"
#include "hdatutil.H"


namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Global variables                                                           */
/*----------------------------------------------------------------------------*/
extern trace_desc_t * g_hdatTraceDesc;


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
const uint32_t HDAT_BOUNDARY = 16; // Pad structures to a 16 byte boundary
const char HDAT_PAD[15] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
                           '\0', '\0', '\0', '\0', '\0', '\0', '\0'};


/** @brief See the prologue in hdathdif.H
 */
HdatHdif::HdatHdif()
{
}


/** @brief See the prologue in hdathdif.H
 */
HdatHdif::HdatHdif(errlHndl_t &o_errlHndl,
                  const char i_eyeCatcher[],
                  uint32_t i_dataPtrCnt,
                  uint32_t i_instance,
                  uint32_t i_childCnt,
                  uint32_t i_ver)
:iv_totalSize(0), iv_padSize(0),iv_siblingPadSize(0),iv_dataPtrSize(0),
iv_childPtrSize(0),iv_dataPtrs(NULL), iv_childPtrs(NULL)
{
    HDAT_ENTER();

    const uint32_t HDAT_MULTIPLE = 16;
    uint32_t l_mod;

    o_errlHndl = NULL;

    iv_hdr.hdatStructId       = HDAT_HDIF_STRUCT_ID;
    iv_hdr.hdatInstance       = i_instance;
    iv_hdr.hdatVersion        = i_ver;
    iv_hdr.hdatSize           = sizeof(hdatHDIF_t);
    iv_hdr.hdatHdrSize        = sizeof(hdatHDIF_t);
    iv_hdr.hdatDataPtrOffset  = 0;
    iv_hdr.hdatDataPtrCnt     = 0;
    iv_hdr.hdatChildStrOffset = 0;
    iv_hdr.hdatChildStrCnt    = 0;

    memcpy(iv_hdr.hdatStructName, i_eyeCatcher, sizeof(iv_hdr.hdatStructName));

    if (i_dataPtrCnt > 0)
    {
        iv_hdr.hdatDataPtrOffset = iv_hdr.hdatSize;
        iv_dataPtrSize = i_dataPtrCnt * sizeof(hdatHDIFDataHdr_t);
        iv_dataPtrs = reinterpret_cast<hdatHDIFDataHdr_t *>(calloc(i_dataPtrCnt,
                                            sizeof(hdatHDIFDataHdr_t)));
        iv_hdr.hdatSize += iv_dataPtrSize;
    }

    if (NULL == o_errlHndl && i_childCnt > 0)
    {
        iv_hdr.hdatChildStrOffset = iv_hdr.hdatSize;

        iv_childPtrSize = i_childCnt * sizeof(hdatHDIFChildHdr_t);
        l_mod = iv_childPtrSize % HDAT_MULTIPLE;
        if (l_mod > 0)
        {
            iv_childPtrSize += HDAT_MULTIPLE - l_mod;
        }

        iv_childPtrs = reinterpret_cast<hdatHDIFChildHdr_t *>
                          (calloc(iv_childPtrSize, 1));
        iv_hdr.hdatSize += iv_childPtrSize;
    }

    iv_totalSize = iv_hdr.hdatSize;
    HDAT_EXIT();
}//end constructor

/** @brief See the prologue in hdathdif.H
 */
HdatHdif::~HdatHdif()
{
    HDAT_ENTER();
    free(iv_dataPtrs);
    free(iv_childPtrs);
    HDAT_EXIT();
}


/** @brief See the prologue in hdathdif.H
 */
uint32_t HdatHdif::size()
{
    return iv_hdr.hdatSize;
}
uint32_t HdatHdif::getSize()
{
    uint32_t l_size = 0;

    l_size += sizeof(iv_hdr);

    if (NULL != iv_dataPtrs)
    {
        l_size += iv_dataPtrSize;
    }

    if (NULL != iv_childPtrs)
    {
        l_size += iv_childPtrSize;
    }
    return l_size;
}
/** @brief See the prologue in hdathdif.H
 */
void HdatHdif::chgChildOffset(uint32_t i_whichChildEntry,
                                   uint32_t i_offset)
{
    hdatHDIFChildHdr_t *l_hdr;

    // If there are child structures, change the offset of the selected triple 
    // entry
    if (iv_hdr.hdatChildStrCnt > 0)
    {
        l_hdr = reinterpret_cast<hdatHDIFChildHdr_t *>(reinterpret_cast<char *>
                                   (iv_childPtrs) + sizeof(hdatHDIFChildHdr_t) *
                                   i_whichChildEntry);
        l_hdr->hdatOffset = i_offset;
    }

    return;
}



/** @brief See the prologue in hdathdif.H
 */
void HdatHdif::addChild(uint32_t i_whichChildEntry,
                           uint32_t i_size,
                           uint32_t i_numChildStr)
{
    HDAT_ENTER();

    hdatHDIFChildHdr_t *l_childHdr;

    iv_hdr.hdatChildStrCnt = i_whichChildEntry + 1; //(0 based index plus 1)

    // Address the child entry
    l_childHdr = reinterpret_cast<hdatHDIFChildHdr_t *>(reinterpret_cast<char *>
                  (iv_childPtrs) +
                  sizeof(hdatHDIFChildHdr_t) * i_whichChildEntry);

    // Update child entry information

    // If not yet done, set offset to first child structure.  Child structures
    // are contiguous after the first and are all the same size.
    if (0 == l_childHdr->hdatOffset)
    {
        l_childHdr->hdatOffset = iv_totalSize;
        l_childHdr->hdatSize   = i_size;
    }
    l_childHdr->hdatCnt++;

    // Increment total object size by child's size
    iv_totalSize += i_size;

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdathdif.H
 */
void HdatHdif::addGrandChild(uint32_t i_size)
{

    // Increment total object size by the grandchild's size
    iv_totalSize += i_size;

    return;
}


/** @brief See the prologue in hdathdif.H
 */
void HdatHdif::addData(uint32_t i_whichDataEntry,
                       uint32_t i_size)
{
    HDAT_ENTER();

    hdatHDIFDataHdr_t *l_dataHdr;

    l_dataHdr = reinterpret_cast<hdatHDIFDataHdr_t *>(reinterpret_cast<char *>
               (iv_dataPtrs) +
               sizeof(hdatHDIFDataHdr_t) * i_whichDataEntry);

    // Update data entry information if there is any data
    if (i_size > 0)
    {
        l_dataHdr->hdatOffset = iv_hdr.hdatSize;
        l_dataHdr->hdatSize   = i_size;
    }
    // Increment total object size by data's size and increment
    // count of data entries
    iv_hdr.hdatSize += i_size;
    iv_totalSize += i_size;
    iv_hdr.hdatDataPtrCnt++;

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdathdif.H
 */
void HdatHdif::maxSiblingSize(uint32_t i_numBytes)
{

    if (i_numBytes > iv_hdr.hdatSize)
    {
        iv_siblingPadSize = i_numBytes - iv_hdr.hdatSize;
        iv_hdr.hdatSize += iv_siblingPadSize;
        iv_totalSize += iv_siblingPadSize;
    }

}




/** @brief See the prologue in hdathdif.H
 */
void HdatHdif::align()
{
     uint32_t l_rem;

    // If the structure length is not a multiple of the boundary
    // requirement, compute the number of pad bytes needed
    l_rem = iv_hdr.hdatSize % HDAT_BOUNDARY;

    if (l_rem > 0)
    {
        iv_padSize = HDAT_BOUNDARY - l_rem;
        iv_hdr.hdatSize += iv_padSize;
        iv_totalSize += iv_padSize;
    }

    return;
}

uint8_t * HdatHdif::setHdif(uint8_t * io_virt_addr)
{
    HDAT_DBG("virtual address=0x%016llX",
            (uint64_t)io_virt_addr);

    uint8_t *l_temp = NULL;

    // If no children were ever added, ensure offset to child pointers is 0
    if (0 == this->iv_hdr.hdatChildStrCnt)
    {
        HDAT_DBG(" no child information were addded");
        this->iv_hdr.hdatChildStrOffset = 0;
    }

    //first write the hdatHDIF_t iv_hdr
    hdatHDIF_t * l_hdatHDIF= reinterpret_cast<hdatHDIF_t *>(io_virt_addr);


    l_hdatHDIF->hdatStructId = this->iv_hdr.hdatStructId;
    l_hdatHDIF->hdatInstance = this->iv_hdr.hdatInstance;
    l_hdatHDIF->hdatVersion = this->iv_hdr.hdatVersion;
    l_hdatHDIF->hdatSize = this->iv_hdr.hdatSize;
    l_hdatHDIF->hdatHdrSize = this->iv_hdr.hdatHdrSize;
    l_hdatHDIF->hdatDataPtrOffset = this->iv_hdr.hdatDataPtrOffset;
    l_hdatHDIF->hdatDataPtrCnt = this->iv_hdr.hdatDataPtrCnt;
    l_hdatHDIF->hdatChildStrCnt = this->iv_hdr.hdatChildStrCnt;
    l_hdatHDIF->hdatChildStrOffset = this->iv_hdr.hdatChildStrOffset;

    memcpy(l_hdatHDIF->hdatStructName,iv_hdr.hdatStructName,
           sizeof(iv_hdr.hdatStructName));

    //cast back to uint8_t and increment the pointer by size of
    //hdatHDIF_t to point the next

    l_temp = reinterpret_cast<uint8_t *>(l_hdatHDIF);
    l_temp += this->iv_hdr.hdatDataPtrOffset;

    HDAT_DBG("sizeof HDIF header=%x",sizeof(hdatHDIF_t));

    //write data pointer array hdatHDIFDataHdr_t   *iv_dataPtrs
    hdatHDIFDataHdr_t *l_hdatHDIFDataHdr =
                       reinterpret_cast<hdatHDIFDataHdr_t *>(l_temp);

    HDAT_DBG("writing Data pointers array from address=0x%016llX",
             (uint64_t)l_hdatHDIFDataHdr);

    //total number of data pointer header is HDAT_PARENT_LAST,
    //actual filled up number is
    //this->iv_hdr.hdatDataPtrCnt, but we should loop through the total number
    //to fillup the memory and increment the pointer

    uint8_t l_totdataHdrCnt = this->iv_dataPtrSize / sizeof(hdatHDIFDataHdr_t);

    for (uint8_t l_cnt=0; l_cnt < l_totdataHdrCnt; l_cnt++)
    {
        l_hdatHDIFDataHdr->hdatOffset = this->iv_dataPtrs[l_cnt].hdatOffset;
        l_hdatHDIFDataHdr->hdatSize = this->iv_dataPtrs[l_cnt].hdatSize;

        HDAT_DBG("wrote data array %d, at address 0x%016llX",
                 l_cnt,(uint64_t)l_hdatHDIFDataHdr);
        l_hdatHDIFDataHdr++;
    }


    //write Child pointers array
    hdatHDIFChildHdr_t *l_hdatHDIFChildHdr =
                      reinterpret_cast<hdatHDIFChildHdr_t *>(l_hdatHDIFDataHdr);

      //saving the start value
    uint8_t *l_tempChildHdr = reinterpret_cast<uint8_t *>(l_hdatHDIFChildHdr);

    HDAT_DBG("writing Child pointers array from address=0x%016llX",
             (uint64_t)l_hdatHDIFChildHdr);
    //total count is HDAT_CHILD_LAST but actual data is hdatChildStrCnt
    //but we need to copy the full to increase the memory pointer
    uint8_t l_totChldHdrCnt =
            this->iv_childPtrSize / sizeof(hdatHDIFChildHdr_t);


    for(uint8_t l_cnt = 0; l_cnt < l_totChldHdrCnt; l_cnt++)
    {
        l_hdatHDIFChildHdr->hdatOffset = this->iv_childPtrs[l_cnt].hdatOffset;
        l_hdatHDIFChildHdr->hdatSize = this->iv_childPtrs[l_cnt].hdatSize;
        l_hdatHDIFChildHdr->hdatCnt = this->iv_childPtrs[l_cnt].hdatCnt;

        HDAT_DBG("wrote child array %d, at address 0x%016llX",
                  l_cnt,(uint64_t)l_hdatHDIFChildHdr);
        l_hdatHDIFChildHdr++;
    }


    l_tempChildHdr += iv_childPtrSize;

    io_virt_addr = reinterpret_cast<uint8_t *>(l_tempChildHdr);

    return io_virt_addr;

}//end setHdif


uint8_t * HdatHdif::setpadding(uint8_t * io_virt_addr,
                               uint32_t &o_size)
{

    HDAT_DBG("address=0x%016llX",
             (uint64_t)io_virt_addr);
    uint32_t i = 0;

    if (this->iv_padSize > 0)
    {
        HDAT_DBG("adding iv_padSize=0x%x",iv_padSize);
        for ( i = 0; i < iv_padSize; i++)
        {
            io_virt_addr[i] = '\0';
        }
    }


    if (iv_siblingPadSize > 0)
    {
        HDAT_DBG("adding iv_siblingPadSize=0x%x",
                  iv_siblingPadSize);
        for ( i = 0; i < iv_siblingPadSize; i++)
        {
            io_virt_addr[i] = '\0';
        }
    }

    io_virt_addr += iv_padSize + iv_siblingPadSize;
    o_size = iv_totalSize;

    HDAT_DBG("exit address=0x%016llX",
             (uint64_t)io_virt_addr);

    return io_virt_addr;
}




uint32_t HdatHdif::getChildOffset()
{
    if ( this->iv_childPtrs )
    {
        return this->iv_childPtrs[0].hdatOffset;
    }
    else
    {
        return 0;
    }

}//end getChildOffset
/** @brief See the prologue in hdathdif.H
 */
void HdatHdif::startCommit(UtilMem &i_data)
{

    // If no children were ever added, ensure offset to child pointers
    // is 0.
    if (0 == iv_hdr.hdatChildStrCnt)
	{
        iv_hdr.hdatChildStrOffset = 0;
	}
    i_data.write(&iv_hdr,sizeof(iv_hdr));

    if ( NULL != iv_dataPtrs)
    {
        i_data.write(iv_dataPtrs ,iv_dataPtrSize);
    }

    // Write the child pointers section.  
    if (NULL != iv_childPtrs)
    {
        i_data.write(iv_childPtrs,iv_childPtrSize);
    }
}
void HdatHdif::print()
{
    HDAT_INF("****** HdatHdif base object ******");

    HDAT_INF("      iv_totalSize = %u", iv_totalSize);
    HDAT_INF("      iv_padSize = %u", iv_padSize);
    HDAT_INF("      iv_dataPtrSize = %u", iv_dataPtrSize);
    HDAT_INF("      iv_childPtrSize = %u", iv_childPtrSize);

    hdatPrintHdrs(&iv_hdr,
                  (const hdatHDIFDataHdr_t *)iv_dataPtrs,
                  NULL,
                  (const hdatHDIFChildHdr_t *)iv_childPtrs);
  

    return;
}

/** @brief See the prologue in hdathdif.H
 */
uint32_t HdatHdif::endCommitSize()
{
    uint32_t l_size = 0;

  // Write pad bytes if needed
    if (iv_padSize > 0)
    {
      l_size += iv_padSize;
    }

    if (iv_siblingPadSize > 0)
    {
      if (iv_siblingPadSize <= sizeof(HDAT_PAD))
      {
        l_size += iv_siblingPadSize;
      }
      else
      {
        l_size += iv_siblingPadSize;
      }
    }
    return l_size;

}
void HdatHdif::endCommit(UtilMem &i_data)
{

  char *l_buffer = NULL;

  // Write pad bytes if needed
    if (iv_padSize > 0)
    {
      i_data.write(HDAT_PAD,iv_padSize);
    }

    if (iv_siblingPadSize > 0)
    {
      if (iv_siblingPadSize <= sizeof(HDAT_PAD))
      {
        i_data.write(HDAT_PAD,iv_siblingPadSize);
      }
      else
      {
        l_buffer = new char[iv_siblingPadSize]();
        i_data.write(l_buffer,iv_siblingPadSize);
        delete[] l_buffer;
      }
    }

}


} //namespace HDAT
