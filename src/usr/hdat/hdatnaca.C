/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatnaca.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <hdat/hdatnaca.H>
#include "hdatspiraH.H"
#include <hdat/hdat.H>
#include "hdatspiraS.H"
#include "hdatutil.H"
#include <sys/mm.h>
#include <sys/mmio.h>
#include <targeting/common/util.H>
#include <initservice/initserviceif.H>

using namespace TARGETING;

#define LID_SPACE 128*MEGABYTE //Bounded lid space blocked for building hdat structs.

namespace HDAT
{
extern trace_desc_t *g_trac_hdat;

errlHndl_t hdatGetNacaFromMem(hdatNaca_t &o_naca)
{
    HDAT_ENTER();
    errlHndl_t l_errl = NULL;
    void* l_virtualAddress = NULL;
    do
    {
        // Get Target Service, and the system target.
        TargetService& l_targetService = targetService();
        TARGETING::Target* l_sysTarget = NULL;
        (void) l_targetService.getTopLevelTarget(l_sysTarget);

        assert(l_sysTarget != NULL);

        uint64_t l_hrmor = l_sysTarget->getAttr<ATTR_PAYLOAD_BASE>() * MEGABYTE;

        // Mapping the uncompressed region. HDAT areas are at the hrmor address
        // + the naca offset so we are reading the entire area of 256 MB.
        l_virtualAddress = mm_block_map(reinterpret_cast<void*>(l_hrmor),
                                        LID_SPACE );

        // Reading the data at hrmor + Naca offset
        hdatNaca_t* l_naca = reinterpret_cast<hdatNaca_t*>(
                        reinterpret_cast<uint64_t>(l_virtualAddress) +
                        HDAT_NACA_OFFSET);

        if( l_naca == NULL)
        {
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_NACA_GET_MEM
             * @reasoncode       HDAT::RC_INVALID_NACA
             * @devdesc          map a mapped region failed
             * @custdesc         Firmware encountered an internal error.
            */
            hdatBldErrLog(l_errl,
                    MOD_NACA_GET_MEM,
                    RC_INVALID_NACA,
                    0,0,0,0,
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    HDAT_VERSION1,
                    true);
            break;
        }

        memcpy(&o_naca, l_naca, sizeof(hdatNaca_t));
    }while(0);

    if ( l_virtualAddress != NULL )
    {
        int rc = 0;
        rc =  mm_block_unmap(l_virtualAddress);
        if( rc != 0)
        {

            errlHndl_t l_errl = NULL;
            /*@
             * @errortype
             * @moduleid         HDAT::MOD_NACA_GET_MEM
             * @reasoncode       HDAT::RC_DEV_MAP_FAIL
             * @devdesc          Unmap a mapped region failed
             * @custdesc         Firmware encountered an internal error.
            */
            hdatBldErrLog(l_errl,
                    MOD_NACA_GET_MEM,
                    RC_DEV_MAP_FAIL,
                    0,0,0,0,
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    HDAT_VERSION1,
                    true);
        }
    }
    return l_errl;
}

/**************************************************************/
//hdatGetCpuCtrlFromMem
/**************************************************************/

void hdatGetCpuCtrlFromMem(hdatMsAddr_t i_msAddr, uint32_t i_size)
{
    HDAT_ENTER();
    hdatMsAddr_t l_addr;
    hdatCpuCtrlArea_t l_cpuCtrl;
    hdatSvcRoutines_t l_svcRtn;

    uint64_t l_baddr = ((uint64_t) i_msAddr.hi << 32) | i_msAddr.lo;

    memcpy(&l_cpuCtrl, &l_baddr,i_size);

    TRACFBIN(g_trac_hdat,"Read Cpu Ctrl area",&l_cpuCtrl,i_size);

    l_addr.hi = l_cpuCtrl.hdatSR[HDAT_SVC_RTNS].hdatSsrPtr.hi;
    l_addr.lo = l_cpuCtrl.hdatSR[HDAT_SVC_RTNS].hdatSsrPtr.lo;

    l_baddr = ((uint64_t) l_addr.hi << 32) | l_addr.lo;

    memcpy(&l_svcRtn,&l_baddr,sizeof(hdatSvcRoutines_t));

    TRACFBIN(g_trac_hdat,"Read Svc Routine Area",&l_svcRtn,
             sizeof(hdatSvcRoutines_t));

    HDAT_EXIT();
}

/**************************************************************/
//call_hdat_steps
/**************************************************************/
void *  call_hdat_steps( void *io_pArgs )
{
    HDAT_ENTER();

    errlHndl_t l_errlHndl=NULL;
    hdatMsAddr_t i_msAddr,l_cpuAddr;
    hdat5Tuple_t l_spirasHostEntry, l_spirhCpuCtrlEntry;
    do {

        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        // Figure out what kind of payload we have
        TARGETING::PAYLOAD_KIND payload_kind
                 = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

        //true => FSP present. OR Payload Kind None
        if(INITSERVICE::spBaseServicesEnabled() ||
                    payload_kind == TARGETING::PAYLOAD_KIND_NONE  )
        {
            break;
        }

        hdatNaca_t l_naca;
        l_errlHndl = hdatGetNacaFromMem(l_naca);

        if ( l_errlHndl )
        {
            HDAT_ERR("could not get NACA from memory");
            l_errlHndl->addFFDC(HDAT_COMP_ID,AT,sizeof(AT),
                     HDAT_VERSION1,HDAT_NACA_FFDC_SUBSEC1);
            break;
        }

        i_msAddr.lo = l_naca.nacaOpalMasterThreadEntry.lo;
        i_msAddr.hi = l_naca.nacaOpalMasterThreadEntry.hi;

        HDAT_DBG("creating SPIRA-H with address hi=%x, lo=%x",
                  i_msAddr.hi,i_msAddr.lo);
        HdatSpiraH l_spirah(l_errlHndl, i_msAddr);

        l_spirah.getSpiraHEntry(HDAT_SEC_CPU_CTRL,l_spirhCpuCtrlEntry);
        l_cpuAddr.hi = l_spirhCpuCtrlEntry.hdatAbsAddr.hi;
        l_cpuAddr.lo = l_spirhCpuCtrlEntry.hdatAbsAddr.lo;

        HDAT_DBG("CPU controls structures at 0x%08x",l_cpuAddr.lo);
        hdatGetCpuCtrlFromMem(l_cpuAddr,sizeof(hdatCpuCtrlArea_t));

        //add for dump header later

        l_spirah.getSpiraHEntry(HDAT_SEC_HOST_DATA_AREA,l_spirasHostEntry);
        HDAT_DBG("got spiras addrss from SPIRAH hi=%x,lo=%x",
                 l_spirasHostEntry.hdatAbsAddr.hi,
                 l_spirasHostEntry.hdatAbsAddr.lo);
        HDAT_DBG("creating all data areas through spiras");


        HDAT_DBG("l_spirasHostEntry.hdatAbsAddr.lo=0x%x",
                  l_spirasHostEntry.hdatAbsAddr.lo);

        HdatSpiraS l_spiras (l_spirasHostEntry);

        uint32_t l_hostAreaCnt=0, l_hostAreaSize=0;

        l_errlHndl = l_spiras.loadDataArea(l_spirasHostEntry,
                              l_hostAreaCnt,l_hostAreaSize);
        HDAT_DBG("got back total size from spiras=0x%x",l_hostAreaSize);

        if ( l_errlHndl )
        {
            HDAT_ERR("could not create all data areas");
            l_errlHndl->addFFDC(HDAT_COMP_ID,AT,sizeof(AT),
                    HDAT_VERSION1,HDAT_NACA_FFDC_SUBSEC2);
            break;
        }

        l_spirah.chgSpiraHEntry(HDAT_SEC_HOST_DATA_AREA,
                                    l_hostAreaCnt,l_hostAreaSize);

        HDAT_DBG("loaded all data areas successfully");

    }while(0);

    HDAT_EXIT();
    return l_errlHndl;
}

} //namespace HDAT
