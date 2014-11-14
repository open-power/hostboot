/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/runtime/rt_pnor.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include <stdlib.h>
#include <targeting/common/targetservice.H>
#include <initservice/taskargs.H>

#include <runtime/rt_targeting.H>
#include <runtime/interface.h>

#include <pnor/pnorif.H>
#include <pnor/ecc.H>
#include <pnor/pnor_reasoncodes.H>
#include "rt_pnor.H"

#include "../ffs.h"
#include "../common/ffs_hb.H"

// Trace definition
extern trace_desc_t* g_trac_pnor;

/**
 * Eyecatcher strings for PNOR TOC entries
 */
extern const char* cv_EYECATCHER[];

/**
 * @brief   set up _start() task entry procedure for PNOR daemon
 */
TASK_ENTRY_MACRO( RtPnor::init );


/**
 * @brief  Return the size and address of a given section of PNOR data
 */
errlHndl_t PNOR::getSectionInfo( PNOR::SectionId i_section,
                                 PNOR::SectionInfo_t& o_info )
{
    return Singleton<RtPnor>::instance().getSectionInfo(i_section,o_info);
}

/**
 * @brief  Write the data for a given sectino into PNOR
 */
errlHndl_t PNOR::flush( PNOR::SectionId i_section)
{
    return Singleton<RtPnor>::instance().flush(i_section);
}

/****************Public Methods***************************/
/**
 * STATIC
 * @brief Static Initializer
 */
void RtPnor::init(errlHndl_t &io_taskRetErrl)
{
    TRACFCOMP(g_trac_pnor, "RtPnor::init> " );
    io_taskRetErrl  = Singleton<RtPnor>::instance().readTOC();
    TRACFCOMP(g_trac_pnor, "<RtPnor::init" );
}
/**************************************************************/
errlHndl_t RtPnor::getSectionInfo(PNOR::SectionId i_section,
                              PNOR::SectionInfo_t& o_info)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::getSectionInfo");
    errlHndl_t l_err = NULL;
    do
    {
        if (i_section == PNOR::INVALID_SECTION)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor::getSectionInfo: Invalid Section"
                    " %d", (int)i_section);
            /*@
             * @errortype
             * @moduleid    PNOR::MOD_RTPNOR_GETSECTIONINFO
             * @reasoncode  PNOR::RC_RTPNOR_INVALID_SECTION
             * @userdata1   PNOR::SectionId
             * @devdesc     invalid section passed to getSectionInfo
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_RTPNOR_GETSECTIONINFO,
                                            PNOR::RC_RTPNOR_INVALID_SECTION,
                                            i_section, 0,true);
            break;
        }

        //size of the section
        uint64_t l_sizeBytes = iv_TOC[i_section].size;
        if (l_sizeBytes == 0)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::getSectionInfo: Section %d"
                    " size is 0", (int)i_section);
            /*@
             * @errortype
             * @moduleid    PNOR::MOD_RTPNOR_GETSECTIONINFO
             * @reasoncode  PNOR::RC_SECTION_SIZE_IS_ZERO
             * @userdata1   PNOR::SectionId
             * @devdesc     section size is zero
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_RTPNOR_GETSECTIONINFO,
                                            PNOR::RC_SECTION_SIZE_IS_ZERO,
                                            i_section, 0,true);
            break;
        }
        //find proc id
        uint64_t l_procId;
        TARGETING::Target* l_masterProc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );
        l_err = RT_TARG::getRtTarget (l_masterProc, l_procId);
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor::getSectionInfo: getRtTarget failed");
            break;
        }

        //ecc
        bool l_ecc = (iv_TOC[i_section].integrity&FFS_INTEG_ECC_PROTECT) ?
                      true : false;

        void* l_pWorking = NULL;
        void* l_pClean   = NULL;

        //find the section in the map first
        if(iv_pnorMap.find(i_section) != iv_pnorMap.end())
        {
            //get the addresses from the map
            PnorAddrPair_t l_addrPair = iv_pnorMap[i_section];
            l_pWorking = l_addrPair.first;
            l_pClean   = l_addrPair.second;
        }
        else
        {
            //malloc twice -- one working copy and one clean copy
            //So, we can diff and write only the dirty bytes
            l_pWorking = malloc(l_sizeBytes);
            l_pClean   = malloc(l_sizeBytes);

            //offset = 0 : read the entire section
            l_err = readFromDevice(l_procId, i_section, 0, l_sizeBytes, l_ecc,
                               l_pWorking);
            if(l_err)
            {
                TRACFCOMP(g_trac_pnor, "RtPnor::getSectionInfo:readFromDevice"
                      " failed");
                break;
            }

            //copy data to another pointer to save a clean copy of data
            memcpy(l_pClean, l_pWorking, l_sizeBytes);

            //save it in the map
            iv_pnorMap [i_section] = PnorAddrPair_t(l_pWorking, l_pClean);
        }
        //return the data in the struct
        o_info.id           = i_section;
        o_info.name         = cv_EYECATCHER[i_section];
        o_info.vaddr        = (uint64_t)l_pWorking;
        o_info.flashAddr    = iv_TOC[i_section].flashAddr;
        o_info.size         = l_sizeBytes;
        o_info.eccProtected = l_ecc;
        o_info.sha512Version=
            (iv_TOC[i_section].version & FFS_VERS_SHA512) ? true : false;
        o_info.sha512perEC  =
           (iv_TOC[i_section].version & FFS_VERS_SHA512_PER_EC) ? true : false;
    } while (0);

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::getSectionInfo");
    return l_err;
}

/**************************************************************/
errlHndl_t RtPnor::flush( PNOR::SectionId i_section)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::flush");
    errlHndl_t l_err = NULL;
    do
    {
        if (i_section == PNOR::INVALID_SECTION)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::flush: Invalid Section: %d",
                    (int)i_section);
            /*@
             * @errortype
             * @moduleid    PNOR::MOD_RTPNOR_FLUSH
             * @reasoncode  PNOR::RC_INVALID_SECTION
             * @userdata1   PNOR::SectionId
             * @devdesc     invalid section passed to flush
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_RTPNOR_FLUSH,
                                            PNOR::RC_INVALID_SECTION,
                                            i_section, 0,true);
            break;
        }
        size_t l_sizeBytes = iv_TOC[i_section].size;
        if (l_sizeBytes == 0)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::flush: Section %d"
                " size is 0", (int)i_section);

            /*@
             * @errortype
             * @moduleid    PNOR::MOD_RTPNOR_FLUSH
             * @reasoncode  PNOR::RC_SECTION_SIZE_IS_ZERO
             * @userdata1   PNOR::SectionId
             * @devdesc     section size is zero
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_RTPNOR_FLUSH,
                                            PNOR::RC_SECTION_SIZE_IS_ZERO,
                                            i_section, 0,true);
            break;
        }

        //get the saved pointers for the partitionName
        PnorAddrMap_t::iterator l_it = iv_pnorMap.find(i_section);
        if(l_it == iv_pnorMap.end())
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::flush: section %d has not been read before",
                      i_section);
            break;
        }
        PnorAddrPair_t l_addrPair = l_it->second;
        uint8_t* l_pWorking = reinterpret_cast<uint8_t*>(l_addrPair.first);
        uint8_t* l_pClean   = reinterpret_cast<uint8_t*>(l_addrPair.second);

        //ecc
        bool l_ecc = (iv_TOC[i_section].integrity&FFS_INTEG_ECC_PROTECT) ?
                            true : false;
        //find proc id
        uint64_t l_procId;
        TARGETING::Target* l_masterProc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );
        l_err = RT_TARG::getRtTarget (l_masterProc, l_procId);
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor::flush: getRtTarget failed");
            break;
        }

        //find the diff between each pointer
        //write back to pnor what doesn't match
        TRACFCOMP(g_trac_pnor, "finding diff between working and clean copy...");
        for (uint64_t i = 0; i < (l_sizeBytes/PAGESIZE); i++)
        {
            if (0 != memcmp(l_pWorking, l_pClean, PAGESIZE))
            {
                TRACFCOMP(g_trac_pnor, "RtPnor::flush: page %d is different,"
                        " writing back to pnor", i);
                l_err = writeToDevice(l_procId, i_section, i*PAGESIZE,PAGESIZE,
                               l_ecc,l_pWorking);
                if (l_err)
                {
                    TRACFCOMP(g_trac_pnor, "RtPnor::flush: writeToDevice failed");
                    break;
                }
                //update the clean copy
                memcpy(l_pClean, l_pWorking, PAGESIZE);
            }
            l_pWorking += PAGESIZE;
            l_pClean   += PAGESIZE;
        }

        if (l_err)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::flush: error writing section %d"
                    " back to pnor",(int)i_section);
            break;
        }
    } while (0);

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::flush");
    return l_err;
}
/*******Protected Methods**************/
RtPnor::RtPnor()
:iv_TOC_used(PNOR::TOC_0)
{
    errlHndl_t l_err = readTOC();
    if (l_err)
    {
        errlCommit(l_err, PNOR_COMP_ID);
    }
}

/*************************/
RtPnor::~RtPnor()
{

}

/*******************Private Methods*********************/
errlHndl_t RtPnor::readFromDevice (uint64_t i_procId,
                                   PNOR::SectionId i_section,
                                   uint64_t i_offset,
                                   size_t i_size,
                                   bool i_ecc,
                                   void* o_data)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::readFromDevice: i_offset=0x%X, "
           "i_procId=%d sec=%d size=0x%X ecc=%d", i_offset, i_procId, i_section,
             i_size, i_ecc);
    errlHndl_t l_err        = NULL;
    uint8_t*   l_eccBuffer  = NULL;
    do
    {

        const char* l_partitionName  = cv_EYECATCHER[i_section];
        void*  l_dataToRead          = o_data;
        size_t l_readSize            = i_size;
        size_t l_readSizePlusECC     = (i_size * 9)/8;
        uint64_t l_offset            = i_offset;

        // if we need to handle ECC, we need to read more
        if( i_ecc )
        {
            l_eccBuffer  = new uint8_t[l_readSizePlusECC]();
            l_dataToRead = l_eccBuffer;
            l_readSize   = l_readSizePlusECC;
            l_offset     = (i_offset * 9)/8;
        }

        if (g_hostInterfaces && g_hostInterfaces->pnor_read)
        {
            // get the data from OPAL
            int l_rc = g_hostInterfaces->pnor_read(i_procId, l_partitionName,
                    l_offset, l_dataToRead, l_readSize);
            if (l_rc)
            {
                TRACFCOMP(g_trac_pnor, "RtPnor::readFromDevice: pnor_read"
                        " failed proc:%d, part:%s, offset:0x%X, size:0x%X,"
                        " dataPt:0x%X, rc:%d", i_procId, l_partitionName,
                        l_offset, l_readSize, l_dataToRead, l_rc);
                /*@
                 * @errortype
                 * @moduleid            PNOR::MOD_RTPNOR_READFROMDEVICE
                 * @reasoncode          PNOR::RC_PNOR_READ_FAILED
                 * @userdata1[00:31]    rc returned from pnor_read
                 * @userdata1[32:63]    section ID
                 * @userdata2[00:31]    offset within the section
                 * @userdata2[32:63]    size of data read in bytes
                 * @devdesc             g_hostInterfaces->pnor_read failed
                 * @custdesc            Error accessing system firmware flash
                 */
                //@todo Add PNOR callout RTC:116145
                l_err = new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 PNOR::MOD_RTPNOR_READFROMDEVICE,
                                 PNOR::RC_PNOR_READ_FAILED,
                                 TWO_UINT32_TO_UINT64(l_rc, i_section),
                                 TWO_UINT32_TO_UINT64(l_offset, l_readSize),
                                 true);
                break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::readFromDevice: This version of"
                    " OPAL does not support pnor_read");
                /*@
                 * @errortype
                 * @moduleid           PNOR::MOD_RTPNOR_READFROMDEVICE
                 * @reasoncode         PNOR::RC_PNOR_READ_NOT_SUPPORTED
                 * @devdesc            g_hostInterfaces->pnor_read not supported
                 * @custdesc           Error accessing system firmware flash
                 */
                //@todo Add PNOR callout RTC:116145
                l_err = new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 PNOR::MOD_RTPNOR_READFROMDEVICE,
                                 PNOR::RC_PNOR_READ_NOT_SUPPORTED,
                                 0,0,true);
                break;
        }
        // remove the ECC data
        if( i_ecc )
        {
            TRACFCOMP(g_trac_pnor, "RtPnor::readFromDevice: removing ECC...");
            // remove the ECC and fix the original data if it is broken
            PNOR::ECC::eccStatus ecc_stat =
                 PNOR::ECC::removeECC(reinterpret_cast<uint8_t*>(l_dataToRead),
                                      reinterpret_cast<uint8_t*>(o_data),
                                    i_size);

            // create an error if we couldn't correct things
            if( ecc_stat == PNOR::ECC::UNCORRECTABLE )
            {
                TRACFCOMP(g_trac_pnor,"RtPnor::readFromDevice>"
                    " Uncorrectable ECC error : chip=%d,offset=0x%.X",
                    i_procId, i_offset );
                /*@
                 * @errortype
                 * @moduleid    PNOR::MOD_RTPNOR_READFROMDEVICE
                 * @reasoncode  PNOR::RC_UNCORRECTABLE_ECC
                 * @devdesc     UNCORRECTABLE ECC
                 */
                //@todo Add PNOR callout RTC:116145
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_RTPNOR_READFROMDEVICE,
                                    PNOR::RC_UNCORRECTABLE_ECC,
                                    0, 0, true);
                break;
            }

            // found an error so we need to fix something
            else if( ecc_stat != PNOR::ECC::CLEAN )
            {
                TRACFCOMP(g_trac_pnor,"RtPnor::readFromDevice>"
                      "Correctable ECC error : chip=%d, offset=0x%.X",
                      i_procId, i_offset );
                if (g_hostInterfaces && g_hostInterfaces->pnor_write)
                {

                    //need to write good data back to PNOR
                    int l_rc = g_hostInterfaces->pnor_write(i_procId,
                            l_partitionName,l_offset, l_dataToRead,l_readSize);
                    if (l_rc)
                    {
                        TRACFCOMP(g_trac_pnor, "RtPnor::readFromDevice> Error"
                        " writing corrected data back to device");

                        /*@
                         * @errortype
                         * @moduleid   PNOR::MOD_RTPNOR_READFROMDEVICE
                         * @reasoncode PNOR::RC_PNOR_WRITE_FAILED
                         * @userdata1  rc returned from pnor_write
                         * @devdesc    error writing corrected data back to PNOR
                         * @custdesc   Error accessing system firmware flash
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          PNOR::MOD_RTPNOR_READFROMDEVICE,
                                          PNOR::RC_PNOR_WRITE_FAILED,
                                          l_rc, 0, true);
                        errlCommit(l_err, PNOR_COMP_ID);
                    }
                }
            }
        }
    } while(0);

    if( l_eccBuffer )
    {
        delete[] l_eccBuffer;
    }

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::readFromDevice" );
    return l_err;
}

/*********************************************************************/
errlHndl_t RtPnor::writeToDevice( uint64_t i_procId,
                                  PNOR::SectionId i_section,
                                  uint64_t i_offset,
                                  size_t i_size,
                                  bool i_ecc,
                                  void* i_src )
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::writeToDevice: i_offset=0x%X, "
           "i_procId=%d sec=%d size=0x%X ecc=%d", i_offset, i_procId, i_section,
             i_size, i_ecc);
    errlHndl_t l_err        = NULL;
    uint8_t*   l_eccBuffer  = NULL;

    do
    {
        void*  l_dataToWrite      = i_src;
        size_t l_writeSize        = i_size;
        size_t l_writeSizePlusECC = (i_size * 9)/8;
        uint64_t l_offset         = i_offset;

        // apply ECC to data if needed
        if( i_ecc )
        {
            l_eccBuffer = new uint8_t[l_writeSizePlusECC];
            PNOR::ECC::injectECC( reinterpret_cast<uint8_t*>(i_src),
                              l_writeSize,
                              reinterpret_cast<uint8_t*>(l_eccBuffer) );
            l_dataToWrite = reinterpret_cast<void*>(l_eccBuffer);
            l_writeSize = l_writeSizePlusECC;
            l_offset    = (i_offset * 9)/8;
        }

        const char* l_partitionName = cv_EYECATCHER[i_section];
        if (g_hostInterfaces && g_hostInterfaces->pnor_write)
        {
            //make call into opal to write the data
            int l_rc = g_hostInterfaces->pnor_write(i_procId,
                        l_partitionName,l_offset,l_dataToWrite,l_writeSize);
            if (l_rc)
            {
                TRACFCOMP(g_trac_pnor, "RtPnor::writeToDevice: pnor_write failed "
                    "proc:%d, part:%s, offset:0x%X, size:0x%X, dataPt:0x%X,"
                    " rc:%d", i_procId, l_partitionName, l_offset, l_writeSize,
                    l_dataToWrite, l_rc);
                /*@
                 * @errortype
                 * @moduleid            PNOR::MOD_RTPNOR_WRITETODEVICE
                 * @reasoncode          PNOR::RC_PNOR_WRITE_FAILED
                 * @userdata1[00:31]    rc returned from pnor_write
                 * @userdata1[32:63]    section ID
                 * @userdata2[00:31]    offset within the section
                 * @userdata2[32:63]    size of data written in bytes
                 * @devdesc             g_hostInterfaces->pnor_write failed
                 * @custdesc            Error accessing system firmware flash
                 */
                l_err = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             PNOR::MOD_RTPNOR_WRITETODEVICE,
                             PNOR::RC_PNOR_WRITE_FAILED,
                             TWO_UINT32_TO_UINT64(l_rc, i_section),
                             TWO_UINT32_TO_UINT64(l_offset, l_writeSize),
                             true);
                 break;
            }
        }
        else
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::writeToDevice: This version of"
                    " OPAL does not support pnor_write");
            /*@
             * @errortype
             * @moduleid           PNOR::MOD_RTPNOR_WRITETODEVICE
             * @reasoncode         PNOR::RC_PNOR_WRITE_NOT_SUPPORTED
             * @devdesc            g_hostInterfaces->pnor_write not supported
             * @custdesc           Error accessing system firmware flash
             */
            //@todo Add PNOR callout RTC:116145
            l_err = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             PNOR::MOD_RTPNOR_WRITETODEVICE,
                             PNOR::RC_PNOR_WRITE_NOT_SUPPORTED,
                             0,0,true);
            break;

        }
    } while(0);

    if( l_eccBuffer )
    {
        delete[] l_eccBuffer;
    }

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::writeToDevice" );
    return l_err;
}

/*****************************************************************/
errlHndl_t RtPnor::readTOC ()
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"RtPnor::readTOC" );
    errlHndl_t l_err = NULL;
    uint8_t* toc0Buffer = new uint8_t[PAGESIZE];
    uint8_t* toc1Buffer = new uint8_t[PAGESIZE];
    do {
        //find proc id
        uint64_t l_procId;
        TARGETING::Target* l_masterProc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );
        l_err = RT_TARG::getRtTarget (l_masterProc, l_procId);
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor::readTOC: getRtTarget failed");
            break;
        }

        // @TODO RTC:120733
        // RT code needs a way to get the active side tocs vs just defaulting
        // to SIDE_A
        l_err = readFromDevice (l_procId, PNOR::TOC, PNOR::SIDE_A_TOC_0_OFFSET,
                PAGESIZE,false,toc0Buffer);
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor,"RtPnor::readTOC:readFromDevice failed"
                      " for TOC0");
            break;
        }
        l_err = readFromDevice (l_procId, PNOR::TOC, PNOR::SIDE_A_TOC_1_OFFSET,
                PAGESIZE, false,toc1Buffer);
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor::readTOC:readFromDevice failed"
                      " for TOC1");
            break;
        }

        l_err = PNOR::parseTOC(toc0Buffer, toc1Buffer, iv_TOC_used, iv_TOC, 0);
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor, "RtPnor::readTOC: parseTOC failed");
            break;
        }
    } while (0);

    if(toc0Buffer != NULL)
    {
        delete[] toc0Buffer;
    }

    if(toc1Buffer != NULL)
    {
        delete[] toc1Buffer;
    }

    TRACFCOMP(g_trac_pnor, EXIT_MRK"RtPnor::readTOC" );
    return l_err;
}

/***********************************************************/
RtPnor& RtPnor::getInstance()
{
    return Singleton<RtPnor>::instance();
}
