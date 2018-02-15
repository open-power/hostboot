/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/occCheckstop.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
#include <fapi2/plat_hwp_invoker.H>

#include <pnorif.H>
#include <pnor_const.H>
#include <utillidmgr.H>

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
  #include <diag/prdf/prdfWriteHomerFirData.H>
#endif

#include <p9_pm_utils.H>
#include <p9_pm_init.H>

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)
#define OCB_OITR0 0x6C008
#define OCB_OIEPR0 0x6C00C

extern trace_desc_t* g_fapiTd;
extern trace_desc_t* g_fapiImpTd;

using namespace TARGETING;

namespace HBOCC
{

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS

    errlHndl_t makeStart405Instruction(const TARGETING::Target* i_target,
                                       uint64_t* o_instr)
    {
        errlHndl_t l_errl = NULL;
        uint64_t l_epAddr;

        l_errl = HBOCC::readSRAM(i_target,
                                 OCC_405_SRAM_ADDRESS + OCC_OFFSET_MAIN_EP,
                                 &l_epAddr,
                                 sizeof(uint64_t));

        // The branch instruction is of the form 0x4BXXXXX200000000, where X
        // is the address of the 405 main's entry point (alligned as shown).
        // Example: If 405 main's EP is FFF5B570, then the branch instruction
        // will be 0x4bf5b57200000000. The last two bits of the first byte of
        // the branch instruction must be '2' according to the OCC instruction
        // set manual.
        *o_instr = OCC_BRANCH_INSTR |
                              (((uint64_t)(BRANCH_ADDR_MASK & l_epAddr)) << 32);
        TRACFCOMP(g_fapiTd, "makeStart405Instruction instruction = %16x",
                                                                      *o_instr);
        return l_errl;
    }

    errlHndl_t startOCCFromSRAM(TARGETING::Target* i_proc)
    {
        TRACUCOMP(g_fapiTd, ENTER_MRK"startOCCFromSRAM");

        errlHndl_t l_errl = NULL;
        uint64_t l_start405MainInstr = 0;

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_target(i_proc);
        fapi2::ReturnCode l_rc;

        do {
            //  ************************************************************
            //  Issue init to OCB
            //  ************************************************************
            FAPI_DBG("Executing p9_pm_ocb_init to initialize OCB channels");
            FAPI_INVOKE_HWP(l_errl, p9_pm_ocb_init,
                          l_target,
                          p9pm::PM_INIT,// Channel setup type
                          p9ocb::OCB_CHAN1,// Channel
                          p9ocb:: OCB_TYPE_NULL,// Channel type
                          0,// Channel base address
                          0,// Push/Pull queue length
                          p9ocb::OCB_Q_OUFLOW_NULL,// Channel flow control
                          p9ocb::OCB_Q_ITPTYPE_NULL// Channel interrupt ctrl
                         );
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "ERROR: Failed to initialize channel 1");
                break;
            }

            //  ************************************************************
            //  Initializes P2S and HWC logic
            //  ************************************************************
            FAPI_DBG("Executing p9_pm_pss_init");
            FAPI_INVOKE_HWP(l_errl, p9_pm_pss_init, l_target, p9pm::PM_INIT);
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "ERROR: Failed to initialize PSS & HWC");
                break;
            }

            //  ************************************************************
            //  Set the OCC FIR actions
            //  ************************************************************
            FAPI_DBG("Executing p9_pm_occ_firinit to set FIR actions.");
            FAPI_INVOKE_HWP(l_errl, p9_pm_occ_firinit, l_target, p9pm::PM_INIT);
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "ERROR: Failed to set OCC FIR actions.");
                break;
            }

            // *************************************************************
            // Switch off OCC initiated special wakeup on EX to allowSTOP
            // functionality
            // *************************************************************
            FAPI_DBG("Clear off the wakeup");
            FAPI_INVOKE_HWP(l_errl, clear_occ_special_wakeups, l_target);
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "ERROR: Failed to clear off the wakeup");
                break;
            }

            // Hack provided by Doug Gilbert (@dgilbert). The following six
            // scoms set up the communications between GPE0 and the 405. This
            // allows to not load and start SGPE that is responsible for setting
            // up the IRQ routing.
            // TODO: RTC 178699 come up with a more permanent solution for
            // communication setup
            uint64_t l_writeData;
            uint32_t l_writeAddress;
            size_t l_writeSize = sizeof(l_writeData);

            l_writeAddress = 0x6C040;
            l_writeData = 0x218780f800000000;
            l_errl = deviceWrite(i_proc, &l_writeData, l_writeSize,
                                 DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "SCOM to address 0x%08x failed",
                                                               l_writeAddress);
                break;
            }

            l_writeAddress = 0x6C050;
            l_writeData = 0x0003d03c00000000;
            l_errl = deviceWrite(i_proc, &l_writeData, l_writeSize,
                                 DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "SCOM to address 0x%08x failed",
                                                               l_writeAddress);
                break;
            }

            l_writeAddress = 0x6C044;
            l_writeData = 0x2181801800000000;
            l_errl = deviceWrite(i_proc, &l_writeData, l_writeSize,
                                 DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "SCOM to address 0x%08x failed",
                                                               l_writeAddress);
                break;
            }

            l_writeAddress = 0x6C054;
            l_writeData = 0x0003d00c00000000;
            l_errl = deviceWrite(i_proc, &l_writeData, l_writeSize,
                                 DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "SCOM to address 0x%08x failed",
                                                               l_writeAddress);
                break;
            }

            l_writeAddress = 0x6C048;
            l_writeData = 0x010280ac00000000;
            l_errl = deviceWrite(i_proc, &l_writeData, l_writeSize,
                                 DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "SCOM to address 0x%08x failed",
                                                               l_writeAddress);
                break;
            }

            l_writeAddress = 0x6C058;
            l_writeData = 0x0001901400000000;
            l_errl = deviceWrite(i_proc, &l_writeData, l_writeSize,
                                 DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "SCOM to address 0x%08x failed",
                                                               l_writeAddress);
                break;
            }

            //  ************************************************************
            //  Start OCC PPC405
            //  ************************************************************
            l_errl = makeStart405Instruction(i_proc, &l_start405MainInstr);
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "startOCCFromSRAM: could not make instr"
                                    " to start 405 main");
                break;
            }
            FAPI_DBG("Executing p9_pm_occ_control to start OCC PPC405");
            FAPI_INVOKE_HWP(l_errl, p9_pm_occ_control, l_target,
                          p9occ_ctrl::PPC405_START,// Operation on PPC405
                          p9occ_ctrl::PPC405_BOOT_WITHOUT_BL, // PPC405 boot loc
                          l_start405MainInstr);
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "ERROR: Failed to initialize OCC PPC405");
                break;
            }

            // Set checkstop interrupt to be active-high and rising edge
            // TODO RTC:178798 Remove the following workaround
            l_writeAddress = OCB_OITR0;
            l_writeData = 0xffffffffffffffff;
            l_errl = deviceWrite(i_proc, &l_writeData, l_writeSize,
                                 DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "SCOM to address 0x%08x failed",
                                                               l_writeAddress);
                break;
            }

            l_writeAddress = OCB_OIEPR0;
            l_writeData = 0xffffffffffffffff;
            l_errl = deviceWrite(i_proc, &l_writeData, l_writeSize,
                                 DEVICE_SCOM_ADDRESS(l_writeAddress));
            if(l_errl)
            {
                TRACFCOMP(g_fapiTd, "SCOM to address 0x%08x failed",
                                                               l_writeAddress);
                break;
            }


        } while(0);

        return l_errl;
    }

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

