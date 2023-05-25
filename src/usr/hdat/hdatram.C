/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatram.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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
 * @file hdatram.C
 *
 * @brief This file contains the implementation of the HdatRam class.
 *
 */

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include "hdatram.H"     // HdatRam class definition
#include "hdatutil.H"    // utility functions
#include "hdatmsvpd.H"

#include <stdio.h>


namespace HDAT
{
/*----------------------------------------------------------------------------*/
/* Global variables                                                           */
/*----------------------------------------------------------------------------*/
uint32_t HdatRam::cv_actualCnt;

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/



/** @brief See the prologue in hdatram.H
 */
HdatRam::HdatRam(errlHndl_t &o_errlHndl,
                 TARGETING::Target * i_pDimmTarget,
                 uint32_t i_resourceId,
                 uint32_t i_slcaIndex)

: HdatHdif(o_errlHndl, HDAT_RAM_STRUCT_NAME, HDAT_RAM_LAST, cv_actualCnt++,
    HDAT_NO_CHILD, HDAT_RAM_VERSION),
  iv_kwdSize(0), iv_kwd(nullptr)
{
    HDAT_ENTER();

    o_errlHndl = nullptr;

    iv_fru.hdatResourceId = i_resourceId;

    if ( i_slcaIndex != 0)
    {
        iv_fru.hdatSlcaIdx = i_slcaIndex;
    }
    else
    {
        iv_fru.hdatSlcaIdx =
            i_pDimmTarget->getAttr<TARGETING::ATTR_SLCA_INDEX>();
    }

    std::vector<uint8_t> ipzVpdData;
    size_t ipzVpdSize = 0;
    do
    {
        o_errlHndl = generateIpzFormattedVpd(iv_fru.hdatResourceId, ipzVpdData, i_pDimmTarget);
        if( o_errlHndl )
        {
            break;
        }

        if( ipzVpdData.size() )
        {
            ipzVpdSize = ipzVpdData.size();
            // Padding extra 8 bytes to keep data alignment similar to FSP
            // data
            iv_kwd = new char [ipzVpdSize + 8];
            memcpy(iv_kwd, ipzVpdData.data(), ipzVpdSize);
            iv_kwdSize = ipzVpdSize + 8;
            HDAT_INF("Ram iv_kwdSize = %d", iv_kwdSize);
        }
    }while(0);

    if (o_errlHndl)
    {
        HDAT_ERR("Ram Error in creating IPZ format keyword for DIMM with "
            "rid  = %d", iv_fru.hdatResourceId);
        /*@
         * @errortype
         * @refcode    LIC_REFCODE
         * @subsys     EPUB_FIRMWARE_SP
         * @reasoncode RC_DIMM_IPZ_CONVERT_FAIL
         * @moduleid   MOD_ADD_RAM_AREA_IPZ_VPD
         * @userdata1  resource id of dimm
         * @userdata2  unused
         * @userdata3  total ipz keyword size for dimm
         * @userdata4  slca index
         * @devdesc    Failed trying to convert the raw spd data for dimm
         *             to IPZ format
         * @custdesc   Firmware error processing Vital Product Data for dimm
         *             memory
         */
        hdatBldErrLog(o_errlHndl,
                      MOD_ADD_RAM_AREA_IPZ_VPD,            // SRC module ID
                      RC_DIMM_IPZ_CONVERT_FAIL,            // SRC ext ref code
                      iv_fru.hdatResourceId,               // SRC hex word 1
                      0,                                   // SRC hex word 2
                      ipzVpdSize,                          // SRC hex word 3
                      iv_fru.hdatSlcaIdx,                  // SRC hex word 4
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE);
    }

    // Update the base class internal data pointers
    // When the data is written to the file by commit(), it must be done in the
    // same order as these addData() calls
    this->addData(HDAT_RAM_FRU_ID, sizeof(hdatFruId_t));
    this->addData(HDAT_RAM_KWD, iv_kwdSize);
    this->addData(HDAT_RAM_ID, sizeof(hdatRamAreaId_t));
    this->addData(HDAT_RAM_SIZE, sizeof(hdatRamAreaSize_t));
    this->align();

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdatram.H
 */
HdatRam::~HdatRam()
{
    HDAT_ENTER();

    delete [] iv_kwd;

    HDAT_EXIT();
    return;
}


/** @brief See the prologue in hdatram.H
 */
uint32_t HdatRam::getRamSize()
{
    uint32_t l_size = 0;
    // Start committing the base class data
    l_size += this->getSize();

    // Write the various pieces of data from this derived class
    l_size += sizeof(hdatFruId_t);
    if (iv_kwdSize > 0)
    {
        l_size += iv_kwdSize;
    }
    l_size += sizeof(hdatRamAreaId_t);
    l_size += sizeof(hdatRamAreaSize_t);

    l_size+= this->endCommitSize();

    return l_size;
}

/** @brief See the prologue in hdatram.H
 */
void HdatRam::commit(UtilMem &i_data)
{

    // Start committing the base class data
    this->startCommit(i_data);

    i_data.write(&iv_fru, sizeof(hdatFruId_t));
    if (iv_kwdSize > 0)
    {
        i_data.write(iv_kwd,iv_kwdSize);
    }
    i_data.write(&iv_ramArea, sizeof(hdatRamAreaId_t));
    i_data.write(&iv_ramSize, sizeof(hdatRamAreaSize_t));

    this->endCommit(i_data);

}


/** @brief See the prologue in hdatram.H
 */
void HdatRam::prt()
{
    HDAT_INF("  **** HdatRam start ****");
    HDAT_INF("      cv_actualCnt = %u", cv_actualCnt);
    HDAT_INF("      iv_kwdSize = %u", iv_kwdSize);
    this->print();
    //hdatPrintFruId(&iv_fru);
    //hdatPrintKwd(iv_kwd, iv_kwdSize);

    HDAT_INF("  **hdatRamAreaId_t**");
    HDAT_INF("      hdatRamAreaId = %u", iv_ramArea.hdatRamAreaId);
    HDAT_INF("      hdatRamStatus = 0X %04X", iv_ramArea.hdatRamStatus);

    HDAT_INF("  **hdatRamAreaSize_t**");
    HDAT_INF("      hdatReserved1 = %u", iv_ramSize.hdatReserved1);
    HDAT_INF("      hdatRamTotalSize = %u", iv_ramSize.hdatRamTotalSize);

    HDAT_INF("  **** HdatRam end ****");

    return;
}
}
