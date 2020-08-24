/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatbldda.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
 * @file hdatbldda.C
 *
 * @brief This file contains the implementation of functions which drive the 
 *        building of hypervisor data areas.
 */


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include "hdatbldda.H"              // function prototypes and structures
#include <vpd/pvpdenums.H>
#include "hdatutil.H"
#include <sys/mm.h>
#include <sys/mmio.h>
#include <assert.h>
#include <attributeenums.H>
#include <util/align.H>
#include <limits.h>

namespace HDAT
{

/**
 * @brief See the prologue in hdatbldda.H
 */
errlHndl_t hdatProcessFru(const hdatMsAddr_t &i_msAddr,
                                 const hdatSpiraDataAreas i_dataArea,
                                 const IpVpdFacade::recordInfo i_fetchVpd[],
                                 const uint8_t i_size,
                                 vpdType i_vpdtype,
                                 uint32_t &o_count,
                                 uint32_t &o_size)
{
    HDAT_ENTER();
    errlHndl_t l_errlHndl = NULL;
    HdatVpd *l_vpdObj;
    const char *l_strName;
    TARGETING::TargetHandleList l_targList;
    TARGETING::ATTR_SLCA_RID_type l_hdatRID = 0;

    // Get all the resource ids associated with this FRU type
    hdatGetTarget(i_dataArea, l_targList);

    uint8_t l_cnt = 0;
    o_count = 0;
    o_size = 0;

    if (l_targList.size() == 0)
    {
        HDAT_DBG("got target list size as NULL");
        return NULL;
    }
    

    uint64_t l_base_addr = ((uint64_t) i_msAddr.hi << 32) | i_msAddr.lo;
    uint64_t l_base_addr_down = ALIGN_PAGE_DOWN(l_base_addr);
    // As we dont know the exact size,
    //hence updating random size which is bigger
    //than actual we write to MS memory.
    void *l_virt_addr = mm_block_map ( reinterpret_cast<void*>(l_base_addr_down),
                                         (ALIGN_PAGE(2048) + PAGESIZE));

    //TODO HdatVpd and HdatHdif class should provide the total size
    o_size = 2048;
    o_count = 1;

    uint64_t l_final_addr = reinterpret_cast<uint64_t>(l_virt_addr);

    l_final_addr +=  l_base_addr - l_base_addr_down;

    l_virt_addr = reinterpret_cast<void *> (l_final_addr);

    uint8_t *l_addr = static_cast <uint8_t*>( l_virt_addr);

    if (HDAT_SYS_VPD == i_dataArea)
    {
        l_strName = HDAT_SYS_VPD_STRUCT_NAME;
        HDAT_DBG("constructing SYS VPD");
    }
    else
    {
        l_strName = HDAT_FRU_VPD_STRUCT_NAME;
    }

    // Build a VPD object for each FRU
    while (l_cnt < l_targList.size())
    {
        l_vpdObj = NULL;

        if (NULL == l_errlHndl)
        {
            uint32_t l_num = i_size/sizeof (i_fetchVpd[0]);
           l_num -= 1 ;  // The last record is TEST record.which shouldn't be used.

            // Construct the VPD object and write the flat data to a file
            l_vpdObj = new HdatVpd(l_errlHndl,
                                   l_hdatRID,
                                    l_targList[l_cnt],
                                    l_strName,
                                    l_cnt,
                                    i_vpdtype,
                                    i_fetchVpd,
                                    l_num);


            if (NULL == l_errlHndl)
            {
                l_addr = l_vpdObj->setVpd(l_addr);
            }
            else
            {
                delete l_vpdObj;
                break;
            }
            delete l_vpdObj;
        }
        l_cnt++;
    }

    uint64_t l_addrData = reinterpret_cast<uint64_t> (l_virt_addr);
    l_addrData =  ALIGN_PAGE_DOWN(l_addrData);

    l_virt_addr = reinterpret_cast<void*>(l_addrData);
    int rc =  mm_block_unmap(l_virt_addr);
    if( rc != 0)
    {
        errlHndl_t l_errl = NULL;
        /*@
         * @errortype
         * @moduleid         HDAT::MOD_PROCESS_FRU
         * @reasoncode       HDAT::RC_DEV_UNMAP_FAIL
         * @devdesc          Unmap a mapped region failed
         * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(l_errl,
                MOD_PROCESS_FRU,
                RC_DEV_UNMAP_FAIL,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }

    HDAT_EXIT();
    return l_errlHndl;
}

 
/**
 * @brief See the prologue in hdatbldda.H
 */
errlHndl_t hdatBldSpecificVpd(hdatSpiraDataAreas i_dataArea,
                              const hdatMsAddr_t &i_msAddr,
                              uint32_t &o_count,
                              uint32_t &o_size)
{
    HDAT_ENTER();

    errlHndl_t l_errlHndl = NULL;
    const IpVpdFacade::recordInfo *l_data = NULL;
    vpdType l_type = BP;
    uint8_t l_size = 0;

    // Determine which VPD structure to build.  This assumes that i_dataArea
    // is always a valid value.  This is done to avoid more code bloat with
    // a default leg to build an error log which should never occur.
    switch (i_dataArea)
    {
        case HDAT_BACKPLANE_VPD:
        case HDAT_SYS_VPD:
        l_data = pvpdRecords;
        l_size = sizeof(pvpdRecords);
        l_type = BP;
        break;

        case HDAT_CLOCK_VPD:
        l_type = CLOCK;
        break;

        case HDAT_ENCLOSURE_VPD:
        l_type = ENCLOSURE;
        break;

        case HDAT_ANCHOR_VPD:
        l_type = ANCHOR;
        break;

        case HDAT_MISC_CEC_VPD:
        l_type = BP_EXT;
        break;

        default:
        break;
    }

    // Build the VPD structure
    l_errlHndl = hdatProcessFru(i_msAddr, i_dataArea,l_data,l_size,l_type,
                o_count,o_size);

    if (NULL != l_errlHndl)
    {
       /*@
         * @errortype
         * @moduleid         HDAT::MOD_BUILD_SPECIFIED_VPD
         * @reasoncode       HDAT::RC_PROCESS_FRU_FAIL
         * @userdata1        Spira data area
         * @userdata2        Hdat fru type
         * @devdesc          process fru funciton failed
         * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(l_errlHndl,
                MOD_BUILD_SPECIFIED_VPD,
                RC_PROCESS_FRU_FAIL,
                i_dataArea,l_type,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }

    return l_errlHndl;
}

}

