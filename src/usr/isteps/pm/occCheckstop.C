/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/occCheckstop.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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

#include    <stdint.h>

#include    <isteps/pm/occCheckstop.H>
#include    <isteps/pm/occAccess.H>
#include    <isteps/pm/pm_common_ext.H>

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <devicefw/userif.H>
#include    <sys/misc.h>
#include    <sys/mm.h>
#include    <sys/mmio.h>
#include    <limits.h>
#include    <vmmconst.h>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>
#include    <targeting/common/util.H>

//  fapi support
#include    <isteps/hwpf_reasoncodes.H>

#include    <vfs/vfs.H>
#include    <util/utillidmgr.H>
#include    <initservice/initserviceif.H>

#include <arch/ppc.H>
#include <fapi2.H>

#include <pnorif.H>
#include <pnor_const.H>
#include <utillidmgr.H>

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
  #include <diag/prdf/prdfWriteHomerFirData.H>
#endif

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

extern trace_desc_t* g_fapiTd;
extern trace_desc_t* g_fapiImpTd;

using namespace TARGETING;

namespace HBOCC
{

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    errlHndl_t loadOCCImageDuringIpl(TARGETING::Target* i_target,
                                                            void* i_occVirtAddr)
    {
        TRACUCOMP(g_fapiTd,
                  ENTER_MRK"loadOCCImageDuringIpl(%p)",
                  i_occVirtAddr);

        errlHndl_t l_errl = NULL;
        uint8_t* l_occImage = NULL;
        void* l_modifiedSectionPtr = NULL;

        do {
            //The OCC image should always be in the virtual address space
            UtilLidMgr lidMgr(HBOCC::OCC_LIDID);
            void* l_tmpOccImage = const_cast<void*>(lidMgr.getLidVirtAddr());
            l_occImage = (uint8_t*)l_tmpOccImage;

            // Get system target in order to access ATTR_NEST_FREQ_MHZ
            TARGETING::TargetService & l_tS = TARGETING::targetService();
            TARGETING::Target * l_sysTarget = NULL;
            l_tS.getTopLevelTarget(l_sysTarget);
            assert(l_sysTarget != NULL);

            //Save Nest Frequency:
            ATTR_FREQ_PB_MHZ_type l_nestFreq =
                               l_sysTarget->getAttr<ATTR_FREQ_PB_MHZ>();
            size_t l_length = 0; // length of current section

            uint32_t* l_ptrToLength = (uint32_t*)
                                       ((char*)l_occImage + OCC_OFFSET_LENGTH);
            l_length = *l_ptrToLength; // Length of the bootloader

            // We only have PAGESIZE to work with so make sure we do not exceed
            // limit.
            assert(l_length <= PAGESIZE);
            // Write the OCC Bootloader into memory
            memcpy(i_occVirtAddr, l_occImage, l_length);

            // OCC Main Application
            char* l_occMainAppPtr = reinterpret_cast<char*>(l_occImage) +
                                    l_length;
            l_ptrToLength = (uint32_t*)(l_occMainAppPtr + OCC_OFFSET_LENGTH);
            l_length = *l_ptrToLength; // Length of the OCC Main

            // Write 405 Main application to SRAM
            l_errl = HBOCC::writeSRAM(i_target,
                                      HBOCC::OCC_405_SRAM_ADDRESS,
                                      (uint64_t*)l_occMainAppPtr,
                                      l_length);
            if(l_errl)
            {
                TRACFCOMP(g_fapiImpTd, "loadOCCImageDuringIpl:"
                                           " failed to write Main app to SRAM");
                break;
            }

            l_modifiedSectionPtr = malloc(OCC_OFFSET_FREQ + sizeof(l_nestFreq));
            // Populate this section with data from PNOR
            memcpy(l_modifiedSectionPtr, l_occMainAppPtr, OCC_OFFSET_FREQ +
                                                            sizeof(l_nestFreq));

            // Change the fequency and set the IPL flag
            uint16_t* l_ptrToIplFlag = (uint16_t*)((char*)l_modifiedSectionPtr +
                                                           OCC_OFFSET_IPL_FLAG);
            uint32_t* l_ptrToFreq = (uint32_t*)((char*)l_modifiedSectionPtr +
                                                               OCC_OFFSET_FREQ);

            *l_ptrToIplFlag |= 0x001;
            *l_ptrToFreq     = l_nestFreq;

            // Overwrite the part of Main we modified above in SRAM:
            l_errl = HBOCC::writeSRAM(i_target,
                                      HBOCC::OCC_405_SRAM_ADDRESS,
                                      (uint64_t*)l_modifiedSectionPtr,
                                      (uint32_t)OCC_OFFSET_FREQ +
                                       sizeof(l_nestFreq));
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageDuringIpl: "
                           "Failed to overwrite OCC Main app in SRAM");
                break;
            }

            // GPE0 application is stored right after the 405 main in memory
            char* l_gpe0AppPtr = l_occMainAppPtr + l_length;
            uint32_t* l_ptrToGpe0Length =
                          (uint32_t*)(l_occMainAppPtr + OCC_OFFSET_GPE0_LENGTH);
            l_length = *l_ptrToGpe0Length;
            l_errl = HBOCC::writeSRAM(i_target,
                                      HBOCC::OCC_GPE0_SRAM_ADDRESS,
                                      (uint64_t*)l_gpe0AppPtr,
                                      l_length);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageDuringIpl: "
                           "Failed to load GPE0 app to SRAM");
                break;
            }

            char* l_gpe1AppPtr = l_gpe0AppPtr + l_length;
            uint32_t* l_ptrToGpe1Length =
                          (uint32_t*)(l_occMainAppPtr + OCC_OFFSET_GPE1_LENGTH);
            l_length = *l_ptrToGpe1Length;
            l_errl = HBOCC::writeSRAM(i_target,
                                      HBOCC::OCC_GPE1_SRAM_ADDRESS,
                                      (uint64_t*)l_gpe1AppPtr,
                                      l_length);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageDuringIpl: "
                           "Failed to load GPE1 app to SRAM");
                break;
            }


        } while(0);
        free(l_modifiedSectionPtr);

        TRACUCOMP(g_fapiTd,
                   EXIT_MRK"loadOCCImageDuringIpl");
        return l_errl;
    }


#endif

#if defined(CONFIG_IPLTIME_CHECKSTOP_ANALYSIS) && !defined(__HOSTBOOT_RUNTIME)
    /**
     * @brief Sets up OCC Host data in SRAM
     */
    errlHndl_t loadHostDataToSRAM( TARGETING::Target* i_proc,
                                    const PRDF::HwInitialized_t i_curHw)
    {
        TRACUCOMP(g_fapiTd, ENTER_MRK"loadHostDataToSRAM i_curHw=%d",i_curHw);

        errlHndl_t  l_errl  =   NULL;

        //Treat virtual address as starting pointer
        //for config struct
        HBPM::occHostConfigDataArea_t * config_data =
                    new HBPM::occHostConfigDataArea_t();

        // Get top level system target
        TARGETING::TargetService & tS = TARGETING::targetService();
        TARGETING::Target * sysTarget = NULL;
        tS.getTopLevelTarget( sysTarget );
        assert( sysTarget != NULL );

        uint32_t nestFreq =  sysTarget->getAttr<ATTR_FREQ_PB_MHZ>();

        config_data->version = HBOCC::OccHostDataVersion;
        config_data->nestFrequency = nestFreq;

        // Figure out the interrupt type
        if( INITSERVICE::spBaseServicesEnabled() )
        {
            config_data->interruptType = USE_FSI2HOST_MAILBOX;
        }
        else
        {
            config_data->interruptType = USE_PSIHB_COMPLEX;
        }

        config_data->firMaster = IS_FIR_MASTER;
        l_errl = PRDF::writeHomerFirData( config_data->firdataConfig,
                                          sizeof(config_data->firdataConfig),
                                          i_curHw);
        if (l_errl)
        {
            TRACFCOMP( g_fapiImpTd,
                       ERR_MRK"loadHostDataToSRAM: Error in writeHomerFirData");
        }
        else
        {
            l_errl = HBOCC::writeSRAM(i_proc, OCC_SRAM_FIR_DATA,
                                      (uint64_t*)config_data->firdataConfig,
                                      sizeof(config_data->firdataConfig));
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadHostDataToSRAM: Error in writeSRAM");
            }
        }
        TRACUCOMP( g_fapiTd, EXIT_MRK"loadHostDataToSRAM");
        delete(config_data);

        return l_errl;
    } // loadHostDataToSRAM
#endif

}  //end HBOCC namespace

