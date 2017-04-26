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

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
  #include <diag/prdf/prdfWriteHomerFirData.H>
#endif

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

extern trace_desc_t* g_fapiTd;

using namespace TARGETING;

namespace HBOCC
{
// @todo RTC 155065 IPL Time Checkstop Analysis Enablement
#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    errlHndl_t loadOCCImageDuringIpl( TARGETING::Target* i_target,
                                        void* i_occVirtAddr)
    {
        TRACUCOMP( g_fapiTd,
                   ENTER_MRK"loadOCCImageDuringIpl(%p)",
                   i_occVirtAddr);

        errlHndl_t l_errl = NULL;
        size_t lidSize = 0;
        void* l_occImage = NULL;

        do {
            UtilLidMgr lidMgr(HBOCC::OCC_LIDID);

            // Get the size of the OCC lid
            l_errl = lidMgr.getLidSize(lidSize);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageDuringIpl: "
                           "Error getting lid size. lidId=0x%.8x",
                           OCC_LIDID);
                break;
            }

            // Check if lid is in virtual address space to save on allocating
            // a large local buffer to copy data to.
            bool l_lidInVirtMem = false;
            // Try to use virtual address space for accessing the lid
            l_occImage = const_cast<void*>(lidMgr.getLidVirtAddr());
            // Get lid from non virtual address space.
            if( l_occImage == NULL )
            {
                // allocate memory big enough for all OCC
                l_occImage = reinterpret_cast<void*>(malloc(1*MEGABYTE));

                // Ensure occ lid size is less than memory allocated for it
                assert(lidSize <= 1*MEGABYTE);

                // Get the entire OCC lid and write it into temporary memory
                l_errl = lidMgr.getLid(l_occImage, lidSize);
                if(l_errl)
                {
                    TRACFCOMP( g_fapiImpTd,
                               ERR_MRK"loadOCCImageDuringIpl: "
                               "Error getting lid. lidId=0x%.8x",
                               OCC_LIDID);
                    break;
                }
            }
            else
            {
                l_lidInVirtMem = true;
            }

            // Pointer to OCC LID
            char *l_occLid = reinterpret_cast<char*>(l_occImage);

            // Get system target in order to access ATTR_NEST_FREQ_MHZ
            TARGETING::TargetService & tS = TARGETING::targetService();
            TARGETING::Target * sysTarget = NULL;
            tS.getTopLevelTarget( sysTarget );
            assert( sysTarget != NULL );

            // Save Nest Frequency;
            ATTR_NEST_FREQ_MHZ_type l_nestFreq =
                                     sysTarget->getAttr<ATTR_FREQ_PB>();

            size_t l_length = 0; // length of this section
            size_t l_startOffset = 0; // offset to start of the section

            // offset to length of the section
            size_t l_offsetToLength = OCC_OFFSET_LENGTH;

            // Get length of OCC bootloader
            uint32_t *ptrToLength = (uint32_t *)(l_occLid + l_offsetToLength);
            l_length = *ptrToLength;

            // We only have PAGESIZE to work with so make sure we do not exceed
            // limit.
            assert(l_length <= PAGESIZE);
            // Write the OCC Bootloader into memory
            memcpy(i_occVirtAddr, l_occImage, l_length);

            // OCC Main Application
            l_startOffset = l_length; // after the Boot image
            char * l_occMainAppPtr = reinterpret_cast<char *>(l_occLid) +
                                     l_startOffset;

            // Get the length of the OCC Main application
            ptrToLength = (uint32_t *)(l_occMainAppPtr + l_offsetToLength);
            l_length = *ptrToLength;
            size_t l_occMainLength = l_length;

            // If LID is in vaddr space we do not want to modify directly.
            if (l_lidInVirtMem)
            {
                // Allocate memory for size of modified section.
                // [ipl flag and freq]
                l_length = OCC_OFFSET_FREQ + sizeof(ATTR_NEST_FREQ_MHZ_type);
                l_occImage = reinterpret_cast<void*>(malloc(l_length));
                // Fill in modify buffer from pnor vaddr.
                memcpy(l_occImage, l_occMainAppPtr, l_length);
                // Move occ main app pointer
                l_occMainAppPtr = reinterpret_cast<char*>(l_occImage);
            }

            // write the IPL flag and the nest freq into OCC main app.
            // IPL_FLAG is a two byte field.  OR a 1 into these two bytes.
            // FREQ is the 4 byte nest frequency value that goes into
            //  the same field in the HOMER.

            uint16_t *ptrToIplFlag =
                    (uint16_t *)((char *)l_occMainAppPtr + OCC_OFFSET_IPL_FLAG);

            uint32_t *ptrToFreq =
                    (uint32_t *)((char *)l_occMainAppPtr + OCC_OFFSET_FREQ);

            *ptrToIplFlag |= 0x0001;
            *ptrToFreq = l_nestFreq;

            // Store the OCC Main applicatoin into ecmdDataBuffer
            // so we may write it to SRAM
            TRACDCOMP( g_fapiImpTd, "loadOCCImageDuringIpl: "
                       "ecmdDataBufferBase size = 0x%X",
                       l_occMainLength);

            ecmdDataBufferBase l_occAppData(l_occMainLength * 8 /* bits */);
            assert(l_length < l_occMainLength,
                   "Cannot write more OCC data than the ECMD buffer "
                   "has rooom for. write size = 0x%X, ECMD buffer size = 0x%X",
                   l_length, l_occMainLength);
            uint32_t rc = l_occAppData.insert(
                                reinterpret_cast<uint32_t *>(l_occMainAppPtr),
                                0,
                                l_length * 8 /* bits */);
            if (rc)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageDuringIpl: "
                           "Error %d doing insert, write size = 0x%X, "
                           "ECMD buffer size = 0x%X",
                           rc, l_length, l_occMainLength);
                /*@
                 * @errortype
                 * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid     fapi::MOD_LOAD_OCC_IMAGE_DURING_IPL
                 * @reasoncode   fapi::RC_ECMD_INSERT_FAILED
                 * @userdata1    Return Code
                 * @userdata2    Data size to insert
                 * @devdesc      ecmd insert failed for l_occAppData
                 * @custdesc     A problem occurred during the IPL
                 *               of the system.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi::MOD_LOAD_OCC_IMAGE_DURING_IPL,
                                          fapi::RC_ECMD_INSERT_FAILED,
                                          rc,
                                          l_length,
                                          true);
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                break;
            }

            // If the lid is in vaddr space we only wrote the modify length to
            // ECMD buffer. Now need to write the rest here.
            if(l_lidInVirtMem)
            {
                size_t l_remainingSize = (l_occMainLength - l_length);
                // Move occ main pointer back to PNOR vaddr + modified length
                l_occMainAppPtr = reinterpret_cast<char *>(l_occLid) +
                                  l_startOffset + l_length;

                // Write to rest of OCC Main to buffer. This means Main app size
                // minus the modified size.
                rc = l_occAppData.insert(
                                reinterpret_cast<uint32_t *>(l_occMainAppPtr),
                                l_length * 8 /* bits */,
                                l_remainingSize * 8 /* bits */);
                if (rc)
                {
                    TRACFCOMP( g_fapiImpTd,
                               ERR_MRK"loadOCCImageDuringIpl: "
                               "Error %d doing insert of remaining data, "
                               "write size = 0x%X, ECMD buffer size = 0x%X",
                               rc,
                               l_remainingSize,
                               l_occMainLength);
                    /*@
                     * @errortype
                     * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
                     * @moduleid     fapi::MOD_LOAD_OCC_IMAGE_DURING_IPL
                     * @reasoncode   fapi::RC_ECMD_INSERT_REMAINING_FAILED
                     * @userdata1    Return Code
                     * @userdata2    Remaining data size to insert
                     * @devdesc      ecmd insert failed for l_occAppData
                     * @custdesc     A problem occurred during the IPL
                     *               of the system.
                     */
                    l_errl = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi::MOD_LOAD_OCC_IMAGE_DURING_IPL,
                                          fapi::RC_ECMD_INSERT_REMAINING_FAILED,
                                          rc,
                                          l_remainingSize,
                                          true);
                    l_errl->collectTrace(FAPI_TRACE_NAME,256);
                    l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                    break;
                }
            }

            // Write the OCC Main app into SRAM
            const uint32_t l_SramAddrApp = OCC_SRAM_ADDRESS;
            l_errl = HBOCC::writeSRAM(i_target, l_SramAddrApp, l_occAppData);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadOCCImageDuringIpl: "
                           "Error in writeSRAM of app");
                break;
            }

        }while(0);

        //free memory used for OCC lid
        free(l_occImage);

        TRACUCOMP( g_fapiTd,
                   EXIT_MRK"loadOCCImageDuringIpl");
        return l_errl;
    }
#endif

// @todo RTC 155065 IPL Time Checkstop Analysis Enablement
#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
#ifndef __HOSTBOOT_RUNTIME
    /**
     * @brief Sets up OCC Host data in SRAM
     */
    errlHndl_t loadHostDataToSRAM( TARGETING::Target* i_proc,
                                    const PRDF::HwInitialized_t i_curHw)
    {
        TRACUCOMP( g_fapiTd,
                   ENTER_MRK"loadHostDataToSRAM i_curHw=%d",i_curHw);

        errlHndl_t  l_errl  =   NULL;

        //Treat virtual address as starting pointer
        //for config struct
        HBOCC::occHostConfigDataArea_t * config_data =
                    new HBOCC::occHostConfigDataArea_t();

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
            const uint32_t l_SramAddrFir = OCC_SRAM_FIR_DATA;
            ecmdDataBufferBase l_occFirData(OCC_SRAM_FIR_LENGTH * 8 /* bits */);
            /// copy config_data in here
            uint32_t rc = l_occFirData.insert(
                    (uint32_t *)config_data->firdataConfig,
                     0,
                     sizeof(config_data->firdataConfig) * 8 /* bits */);
            if (rc)
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"loadHostDataToSRAM: Error %d doing insert",
                           rc);
                /*@
                 * @errortype
                 * @moduleid     fapi::MOD_OCC_LOAD_HOST_DATA_TO_SRAM
                 * @reasoncode   fapi::RC_ECMD_INSERT_FAILED
                 * @userdata1    Return Code
                 * @userdata2    0
                 * @devdesc      ecmd insert failed for l_occFirData
                 * @custdesc     A problem occurred during the IPL
                 *               of the system.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          fapi::MOD_OCC_LOAD_HOST_DATA_TO_SRAM,
                                          fapi::RC_ECMD_INSERT_FAILED,
                                          rc, 0);
            }
            else
            {
                l_errl = HBOCC::writeSRAM(i_proc, l_SramAddrFir, l_occFirData);
                if(l_errl)
                {
                    TRACFCOMP( g_fapiImpTd,
                               ERR_MRK"loadHostDataToSRAM: Error in writeSRAM");
                }
            }
        }

        TRACUCOMP( g_fapiTd,
                   EXIT_MRK"loadHostDataToSRAM");

        return l_errl;
    } // loadHostDataToSRAM
#endif
#endif

}  //end HBOCC namespace

