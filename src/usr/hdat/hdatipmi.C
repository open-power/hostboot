/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatipmi.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <sys/mm.h>
#include <sys/mmio.h>
#include <hdat/hdat.H>
#include <string.h>
#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <util/align.H>
#include "hdatipmi.H"
#include "hdatutil.H"
#include <ipmi/ipmisensor.H>

using namespace TARGETING;
using namespace SENSOR;

namespace HDAT
{
extern trace_desc_t *g_trac_hdat;

uint32_t HdatIpmi::cv_actualCnt = 0;





/*******************************************************************************
*  IPMI Constructor
*  IPMI sensor data structure is pretty simple with only 2 internal data pointers.
*  But each of those data pointers are arrays by itself.( FRU sensor and LED sensor)
*  In the constructor we initialize all the member variables including the 
*  sensor vectors as those are needed to calculate the whole struct size
*******************************************************************************/
HdatIpmi::HdatIpmi(errlHndl_t &o_errlHndl, const hdatMsAddr_t &i_msAddr):
                           HdatHdif(o_errlHndl, HDAT_IPMI_STRUCT_NAME,
                           HDAT_IPMI_DA_LAST, cv_actualCnt++, HDAT_NO_CHILD,
                           HDAT_IPMI_DATA_VERSION),iv_ipmiDataSize(0),
                           iv_ipmiData(NULL)
{
    HDAT_ENTER();
    errlHndl_t l_errl = NULL;
    do{

        // Populating the FRU sensor and LED sensor vectors.
        // Filter out all targets and loop them through to fill the FRU and LED sensor arrays.
        
        TARGETING::TargetService & l_targetService = TARGETING::targetService();
        TARGETING::PredicateHwas l_predHwas;
        l_predHwas.present(true);

        TARGETING::PredicateCTM l_procFilter(TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_PROC);

        TARGETING::PredicateCTM l_sysFilter(TARGETING::CLASS_SYS,
                                             TARGETING::TYPE_SYS);

        TARGETING::PredicateCTM l_nodeFilter(TARGETING::CLASS_ENC,
                                             TARGETING::TYPE_NODE);
        
        TARGETING::PredicateCTM l_dimmFilter(TARGETING::CLASS_LOGICAL_CARD,
                                             TARGETING::TYPE_DIMM);

        TARGETING::PredicatePostfixExpr l_presentTargExpr;
        l_presentTargExpr.push(&l_procFilter).push(&l_sysFilter).Or().
                     push(&l_nodeFilter).Or().push(&l_dimmFilter).Or().
                     push(&l_predHwas).And();

        TARGETING::TargetRangeFilter l_targFilter(
        l_targetService.begin(),
        l_targetService.end(),
        &l_presentTargExpr);

        for(; l_targFilter; ++l_targFilter)
        {
#if 0
            // Create a new array entry and push it to FRU/LED sensor vector
            hdatIPMIFRUSensorMapEntry_t l_fruEntry;
            uint8_t l_sensorType = 0;
            uint8_t l_eventReadingType = 0;
            l_fruEntry.SLCAIndex = (*l_targFilter)->getAttr<ATTR_SLCA_INDEX>();
            l_fruEntry.IPMISensorID = getFaultSensorNumber(*l_targFilter);
            l_errl = SensorBase::getSensorType(l_fruEntry.IPMISensorID,
                                   l_sensorType, l_eventReadingType);
            if(l_errl == NULL)
            {
                l_fruEntry.IPMISensorType = l_sensorType;
            }
            else
            { 
                HDAT_ERR(" Error in getsensor type");
                break;
            }
            iv_ipmiFruEntry.push_back(l_fruEntry);
#endif
        }
        iv_ipmiDataSize = sizeof(hdatHDIF_t)+
                          HDAT_IPMI_PADDING +
                          ( sizeof(hdatHDIFDataHdr_t) * HDAT_IPMI_NUM_DATA_PTRS)+
                          ( sizeof(hdatIPMIFRUSensorMapEntry_t) * iv_ipmiFruEntry.size())+
                          ( sizeof(hdatIPMILEDSensorMapEntry_t) * iv_ipmiLedEntry.size())+
                          ( 2 * sizeof(uint32_t));
        
        // Copy the input phy address to this object member variable
        iv_msAddr  = ((uint64_t) i_msAddr.hi << 32) | i_msAddr.lo;

        // Allocate space and get virt addr with mem map
        void *l_virt_addr = mm_block_map (
                       reinterpret_cast<void*>(ALIGN_PAGE_DOWN(iv_msAddr)),
                       (ALIGN_PAGE(iv_ipmiDataSize)+ PAGESIZE));
        iv_ipmiData = static_cast<uint8_t*>(l_virt_addr) + 
                       (iv_msAddr - ALIGN_PAGE_DOWN(iv_msAddr));

        // initializing the space to zero
        memset(iv_ipmiData , 0x0, iv_ipmiDataSize);

    }while(0);
    o_errlHndl = l_errl;

    HDAT_EXIT();
}

/*******************************************************************************
* setIpmiData : Sets all the ipmi data in mainstore pointed by passed in virtaddr
*******************************************************************************/

void HdatIpmi::setIpmiData()
{
    HDAT_ENTER();

     // Update size and ofset of internal data pointers in HDif int dptr section.
    this->addData(HDAT_IPMI_FRU_SENSOR_MAPPING,
        (sizeof(hdatIPMIFRUSensorMapEntry_t) * iv_ipmiFruEntry.size()) + sizeof(uint32_t));
    this->addData(HDAT_IPMI_LED_SENSOR_ID_MAPPING,
        (sizeof(hdatIPMILEDSensorMapEntry_t) * iv_ipmiLedEntry.size()) + sizeof(uint32_t));

    // Set  the HDIF header data 
    iv_ipmiData = this->setHdif(iv_ipmiData);

    // Add the padding before adding int data pointers. ( Refer Spec)
    this->align();

    // Each internal data pointer has number of array elements followed by 
    // array data.Hence fill the array size first.
    
    uint32_t l_ipmiFruArraySize = iv_ipmiFruEntry.size();
    memcpy( iv_ipmiData, &l_ipmiFruArraySize, sizeof(uint32_t));
    iv_ipmiData+=sizeof(uint32_t);
    
    //  Lets fillup array data. 
    if(iv_ipmiFruEntry.size() > 0)
    {   
        memcpy(iv_ipmiData, &iv_ipmiFruEntry[0],
                sizeof(hdatIPMIFRUSensorMapEntry_t) * iv_ipmiFruEntry.size());
        iv_ipmiData += sizeof(hdatIPMIFRUSensorMapEntry_t) * iv_ipmiFruEntry.size(); 
    }
    

    uint32_t l_ipmiLedArraySize = iv_ipmiLedEntry.size();
    memcpy( iv_ipmiData, &l_ipmiLedArraySize, sizeof(uint32_t));
    iv_ipmiData+=sizeof(uint32_t);
    if(iv_ipmiLedEntry.size() > 0)
    {
        memcpy(iv_ipmiData, &iv_ipmiLedEntry[0],
                sizeof(hdatIPMILEDSensorMapEntry_t) * iv_ipmiLedEntry.size());
        iv_ipmiData += sizeof(hdatIPMILEDSensorMapEntry_t) * iv_ipmiLedEntry.size(); 
    }

    HDAT_EXIT();
}


/***********************************************************
*  getIpmiEntrySize() : returns size of whole ipmi structure
************************************************************/
uint32_t HdatIpmi::getIpmiEntrySize()
{
    return iv_ipmiDataSize;
}


/*******************************************************************************
* hdatLoadIpmi  : API called by SPiraS for ipmi data loading.
 *******************************************************************************/


errlHndl_t hdatLoadIpmi(const hdatMsAddr_t &i_msAddr,uint32_t &o_size, uint32_t &o_count)
{
    HDAT_ENTER();
    errlHndl_t l_errl;
    do{
        HdatIpmi l_hdatIpmi(l_errl,i_msAddr);
        if(l_errl != NULL)
        {
            HDAT_ERR(" error in constructor");
            break;
        }
        l_hdatIpmi.setIpmiData();
        o_size = l_hdatIpmi.getIpmiEntrySize();
        o_count= HdatIpmi::cv_actualCnt;
    }while(0);
    HDAT_EXIT();
    return(l_errl);
}



/** @brief See the prologue in hdathdatspsubsys.H
 */
HdatIpmi::~HdatIpmi()
{
    errlHndl_t o_errlHndl=NULL;

    HDAT_ENTER();

    // Free the memory allocated for filling this entry.
    int rc=0;
    rc =  mm_block_unmap(reinterpret_cast<void*>(
                        ALIGN_PAGE_DOWN((uint64_t)iv_ipmiData)));
    if( rc != 0)
    {
        /*@
        * @errortype
        * @moduleid         HDAT::MOD_HDAT_IPMI_DTOR
        * @reasoncode       HDAT::RC_DEV_MAP_FAIL
        * @devdesc          Unmap a mapped region failed
        * @custdesc         Firmware encountered an internal error.
        */
        hdatBldErrLog(o_errlHndl,
                HDAT::MOD_HDAT_IPMI_DTOR,
                RC_DEV_MAP_FAIL,
                0,0,0,0,
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                HDAT_VERSION1,
                true);
    }

    HDAT_EXIT();
    return;
}


} // end namespace
                                  

