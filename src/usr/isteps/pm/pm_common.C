/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/pm_common.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

#include    <pm/pm_common.H>

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <errl/errlreasoncodes.H>
#include    <errl/errludtarget.H>

#include    <sys/misc.h>
#include    <sys/mm.h>
#include    <sys/time.h>

#include    <util/utilxipimage.H>
#include    <scom/wakeup.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>
#include    <targeting/common/mfgFlagAccessors.H>
#include    <targeting/targplatutil.H>

//  fapi support
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

//PNOR Resource Provider
#include    <pnor/pnorif.H>

#include    <initservice/isteps_trace.H>
#include    <isteps/istep_reasoncodes.H>

#include    <vfs/vfs.H>
#include    <initservice/initserviceif.H>

#include <runtime/interface.h>
#include <secureboot/service.H>
#include <secureboot/smf_utils.H>
#include <secureboot/smf.H>

#include <p10_pm_set_homer_bar.H>
#include <p10_pm_pba_bar_config.H>
#include <p10_pm_start.H>
#include <p10_pm_halt.H>
#include <p10_pm_callout.H>
#include <p10_hcode_image_build.H>
#include <p10_infrastruct_help.H>
#include <p10_hcode_image_defines.H>
#include <util/impl/shared_ptr.H>

#include <arch/ppc.H>
#include <isteps/pm/occAccess.H>

#include <isteps/pm/scopedHomerMapper.H>

#include    <p10_core_checkstop_handler.H>
#include    <p10_stop_api.H>
#include    <p10_scom_c_b.H>
#include    <p10_scom_c_d.H>
#include    <scom/scomif.H>
#include <secureboot/smf_utils.H>

#include <htmgt/htmgt.H>

#ifdef __HOSTBOOT_RUNTIME
#include <targeting/common/hbrt_target.H>
#include <runtime/interface.h>
#include <runtime/hbrt_utilities.H>

#ifdef CONFIG_NVDIMM
#include <isteps/nvdimm/nvdimm.H>  // notify NVDIMM protection change
#endif

#endif //__HOSTBOOT_RUNTIME

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


using namespace TARGETING;
using namespace hcodeImageBuild;

namespace HBPM
{
    constexpr uint16_t OCC_CHKPT_COMPLETE  = 0x0EFF;
    const uint32_t IPL_FLAG_AND_FREQ_SIZE = sizeof(uint32_t) + sizeof(uint16_t);


    std::shared_ptr<UtilLidMgr> g_pOccLidMgr (nullptr);
    std::shared_ptr<UtilLidMgr> g_pHcodeLidMgr (nullptr);
    std::shared_ptr<UtilLidMgr> g_pRingOvdLidMgr (nullptr);


    /**
     *  @brief Call p10_pm_callout and handle returned data
     *  @param[in]  i_proc_target  Processor target
     *  @param[in]  i_homer_vaddr  Pointer to local HOMER memory
     */
    void callPmCallout( TARGETING::Target* i_proc_target,
                        void* i_homer_vaddr );

    /**
     *  @brief Convert HOMER physical address space to a vitual address.
     *         The input value of the physical HOMER address, along with the
     *         converted virtual address, are saved into the attributes
     *         ATTR_HOMER_PHYS_ADDR and ATTR_HOMER_VIRT_ADDR, respectively,
     *         for future use.
     *  @param[in]  i_proc_target  Processsor target
     *  @param[in]  i_phys_addr    Physical address
     *  @return NULL on error, else virtual address
     */
    void *convertHomerPhysToVirt( TARGETING::Target* i_proc_target,
                                  uint64_t i_phys_addr)
    {
        int rc = 0;

        void *l_virt_addr = reinterpret_cast<void*>
            (i_proc_target->getAttr<ATTR_HOMER_VIRT_ADDR>());

        if((i_proc_target->getAttr<ATTR_HOMER_PHYS_ADDR>() != i_phys_addr) ||
            (nullptr == l_virt_addr))
        {
            if(nullptr != l_virt_addr)
            {
                rc = HBPM_UNMAP(l_virt_addr);

                if(rc)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              ERR_MRK"convertHomerPhysToVirt: "
                              "unmap_phys_mem failed, rc=0x%0X",
                              rc);

                    l_virt_addr = nullptr;
                }
            }

            // Remap unless we're zeroing things out
            if( i_phys_addr )
            {
                l_virt_addr = HBPM_MAP(HBPM_PHYS_ADDR,
                                       sizeof(Homerlayout_t));
            }
            else
            {
                l_virt_addr = nullptr;
            }


            // Update the attributes for the current values
            i_proc_target->setAttr<ATTR_HOMER_PHYS_ADDR>(i_phys_addr);
            i_proc_target->setAttr<ATTR_HOMER_VIRT_ADDR>(
                reinterpret_cast<uint64_t>(l_virt_addr));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "convertHomerPhysToVirt: "
                      "phys_addr=0x%0lX, virt_addr=0x%0lX",
                      i_phys_addr,
                      reinterpret_cast<uint64_t>(l_virt_addr));
        }

        return l_virt_addr;
    } // convertHomerPhysToVirt

    /**
     * @brief Sets up OCC Host data in Homer
     */
    errlHndl_t loadHostDataToHomer( TARGETING::Target* i_proc,
                                    void* i_occHostDataVirtAddr)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadHostDataToHomer(OccHostDataV:%p)",
                   i_occHostDataVirtAddr );

        errlHndl_t l_errl = nullptr;

        //Treat virtual address as starting pointer
        //for config struct
        occHostConfigDataArea_t * l_config_data =
            reinterpret_cast<occHostConfigDataArea_t *>
            (i_occHostDataVirtAddr);

        // Get top level system target
        TARGETING::TargetService & tS = TARGETING::targetService();
        TARGETING::Target * sysTarget = nullptr;
        tS.getTopLevelTarget( sysTarget );
        assert( sysTarget != nullptr );

        l_config_data->version = OccHostDataVersion;
        l_config_data->occFrequency = sysTarget->getAttr<ATTR_FREQ_PAU_MHZ>();

        // Figure out the interrupt type
        if( INITSERVICE::spBaseServicesEnabled() )
        {
            l_config_data->interruptType = USE_FSI2HOST_MAILBOX;
        }
        else
        {
            l_config_data->interruptType = USE_PSIHB_COMPLEX;
        }

        if (SECUREBOOT::SMF::isSmfEnabled())
        {
            l_config_data->smfMode = SMF_MODE_ENABLED;
        }
        else
        {
            l_config_data->smfMode = SMF_MODE_DISABLED;
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"loadHostDataToHomer: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );

        return l_errl;
    } // loadHostDataToHomer

    /**
     * @brief Sets up Hcode in Homer
     */
    errlHndl_t loadHcode( TARGETING::Target* i_target,
                          void* i_pImageOut,
                          loadPmMode i_mode )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadHcode(HUID:0x%08X, Image:%p, Mode:%s)",
                   get_huid(i_target), i_pImageOut,
                   (PM_LOAD == i_mode) ? "LOAD" : "RELOAD" );

        errlHndl_t l_errl = nullptr;

        // cast OUR type of target to a FAPI type of target.
        // figure out homer offsets
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiTarg(i_target);

        void *l_buffer1 = (void*)malloc(HW_IMG_RING_SIZE);
        void *l_buffer2 = (void*)malloc(XIPC_RING_BUF1_SIZE);
        void *l_buffer3 = (void*)malloc(XIPC_RING_BUF2_SIZE);
        void *l_buffer4 = (void*)malloc(XIPC_RING_BUF3_SIZE);

        do
        {
            uint32_t l_lidId = Util::P10_HCODE_LIDID;
            if(g_pHcodeLidMgr.get() == nullptr)
            {
                g_pHcodeLidMgr = std::shared_ptr<UtilLidMgr>
                                 (new UtilLidMgr(l_lidId));
            }
            void* l_pImageIn = nullptr;
            size_t l_lidImageSize = 0;

            // NOTE: Ideally, there would also be a check to determine if LID
            //       manager already got the new LID, but the currently
            //       available information does not make it possible to do that.
            if(PM_RELOAD == i_mode)
            {
                // When reloading, release LID image so any update is used
                l_errl = g_pHcodeLidMgr->releaseLidImage();
            }

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode: "
                           "release stored LID image failed!");
                l_errl->collectTrace("ISTEPS_TRACE",256);
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                break;
            }

            l_errl = g_pHcodeLidMgr->getStoredLidImage(l_pImageIn,
                                                       l_lidImageSize);
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode: get stored LID image failed!");
                l_errl->collectTrace("ISTEPS_TRACE",256);
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                break;
            }

            // The ref image may still include the 4K header which the HWP is
            // not expecting, so move the image pointer past the header
            if( *(reinterpret_cast<uint64_t*>(l_pImageIn)) == VER_EYECATCH)
            {
                 l_pImageIn = reinterpret_cast<void*>
                    (reinterpret_cast<uint8_t*>(l_pImageIn) + PAGESIZE);
            }
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "loadHcode: HCODE addr = 0x%p, lidId = 0x%.8x",
                       l_pImageIn,
                       l_lidId);

            // Pull build information from XIP header and trace it
            Util::imageBuild_t l_imageBuild;
            Util::pullTraceBuildInfo(l_pImageIn,
                                     l_imageBuild,
                                     ISTEPS_TRACE::g_trac_isteps_trace);

            ImageType_t l_imgType;

            // Check if we have a valid ring override section and
            //  include it in if so
            void* l_ringOverrides = nullptr;
            l_errl = HBPM::getRingOvd(l_ringOverrides);
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode(): Error in call to getRingOvd!");
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit(l_errl, ISTEP_COMP_ID);
            }

            FAPI_INVOKE_HWP( l_errl,
                             p10_hcode_image_build,
                             l_fapiTarg,
                             l_pImageIn, //reference image
                             i_pImageOut, //homer image buffer
                             l_ringOverrides,
                             (PM_LOAD == i_mode)
                                 ? PHASE_IPL : PHASE_REBUILD,
                             l_imgType,
                             l_buffer1,
                             HW_IMG_RING_SIZE,
                             l_buffer2,
                             XIPC_RING_BUF1_SIZE,
                             l_buffer3,
                             XIPC_RING_BUF2_SIZE,
                             l_buffer4,
                             XIPC_RING_BUF3_SIZE);

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode: p10_hcode_image_build failed!" );
                l_errl->addFFDC( ERRL_COMP_ID,
                                 reinterpret_cast<void *>(&l_imageBuild),
                                 sizeof(Util::imageBuild_t),
                                 0,                           // Version
                                 ERRORLOG::ERRL_UDT_BUILD,    // parse build
                                 false );                     // merge
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

            // If SMF is enabled, need to copy the information contained within
            // l_buffer2 into the unsecure HOMER memory area
            if(SECUREBOOT::SMF::isSmfEnabled())
            {
                auto l_unsecureHomerSize = i_target->
                          getAttr<TARGETING::ATTR_UNSECURE_HOMER_SIZE>();
                auto l_unsecureHomerAddr = i_target->
                          getAttr<TARGETING::ATTR_UNSECURE_HOMER_ADDRESS>();
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "loadHcode: Unsecure HOMER addr: 0x%.16llx; unsecure HOMER size: 0x%x",
                          l_unsecureHomerAddr, l_unsecureHomerSize);

                assert(l_unsecureHomerSize <= MAX_RING_BUF_SIZE,
                       "loadHcode: unsecure HOMER is bigger than the output buffer");
                assert(l_unsecureHomerSize <= MAX_UNSECURE_HOMER_SIZE,
                       "loadHcode: the size of unsecure HOMER is more than 0x%x", MAX_UNSECURE_HOMER_SIZE);
                assert(l_unsecureHomerAddr,
                       "loadHcode: the unsecure HOMER addr is 0");

                void* l_unsecureHomerVAddr = HBPM_MAP(
                                   UNSEC_HOMER_PHYS_ADDR,
                                   l_unsecureHomerSize);
                assert(l_unsecureHomerVAddr,
                       "loadHcode: could not map unsecure HOMER phys addr");
                memcpy(l_unsecureHomerVAddr, l_buffer2, l_unsecureHomerSize);

                int l_rc = HBPM_UNMAP(l_unsecureHomerVAddr);
                if(l_rc)
                {
                    /*@
                    * @errortype
                    * @reasoncode ISTEP::RC_MM_UNMAP_FAILED
                    * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
                    * @moduleid   ISTEP::MOD_LOAD_HCODE
                    * @userdata1  Unsecure HOMER addr
                    * @userdata2  RC from HBPM_UNMAP
                    * @devdesc    Could not unmap unsecure HOMER's virtual
                    *             address
                    * @custdesc   A problem occurred during the IPL of the
                    *             system
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           ISTEP::MOD_LOAD_HCODE,
                                           ISTEP::RC_MM_UNMAP_FAILED,
                                           reinterpret_cast<uint64_t>(
                                                      l_unsecureHomerVAddr),
                                           l_rc,
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    l_errl->collectTrace(ISTEP_COMP_NAME);
                    break;
                }

            }


            // Log some info about Homer
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "pImageOut=%p",i_pImageOut);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "lidSize=%d",l_lidImageSize);

            // Log some info from the headers in the Homer layout
            Homerlayout_t* pChipHomer = (Homerlayout_t*)i_pImageOut;

            // CPMR Region with Self Restore Region and CME Binary
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "CPMR region -- Location: %p",
                      &(pChipHomer->iv_cpmrRegion));

            CpmrHeader_t* pCpmrHeader =
                (CpmrHeader_t*)(&(pChipHomer->
                iv_cpmrRegion.iv_selfRestoreRegion.iv_CPMR_SR.elements.iv_CPMRHeader));
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "CMPR header -- Date:0x%08X, Version:0x%08X, "
                      "Image offset:0x%08X, Image length:0x%08X",
                      pCpmrHeader->iv_buildDate,
                      pCpmrHeader->iv_version,
                      pCpmrHeader->iv_qmeImgOffset,
                      pCpmrHeader->iv_qmeImgLength);

            // PPMR Region
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PPMR region -- Location: %p",
                      &(pChipHomer->iv_ppmrRegion));

            PpmrHeader_t* pPpmrHeader = (PpmrHeader_t *)pChipHomer->iv_ppmrRegion.iv_ppmrHeader;
            PgpeHeader_t* pPgpeHeader = (PgpeHeader_t*)
               (&(pChipHomer->iv_ppmrRegion.iv_pgpeSramRegion[OCC_SRAM_PGPE_REGION_SIZE]));
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PGPE header -- Date:0x%08X, Version:0x%08X, "
                      "Hcode offset:0x%08X, Hcode length:0x%08X",
                      pPgpeHeader->g_pgpe_buildDate,
                      pPgpeHeader->g_pgpe_buildVer,
                      pPpmrHeader->iv_hcodeOffset,
                      pPpmrHeader->iv_hcodeLength);

        } while(0);

        free(l_buffer1);
        free(l_buffer2);
        free(l_buffer3);
        free(l_buffer4);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"loadHcode: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );

        return l_errl;
    } // loadHcode

    /**
     * @brief Execute procedures and steps required to setup for loading
     *        the OCC image in a specified processor
     */
    errlHndl_t loadOCCSetup(TARGETING::Target* i_target,
                            uint64_t i_occImgPaddr,
                            uint64_t i_occImgVaddr, // dest
                            uint64_t i_commonPhysAddr)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ENTER_MRK"loadOCCSetup"
                  "(OccP:0x%0lX, OccV:0x%0lX, CommonP:0x%0lX)",
                  i_occImgPaddr, i_occImgVaddr, i_commonPhysAddr );

        errlHndl_t l_errl = nullptr;

        do{
            // cast OUR type of target to a FAPI type of target.
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapiTarg(i_target);
            char l_fapiTargString[ATTR_FAPI_NAME_max_chars];
            toString(l_fapiTarg, l_fapiTargString, sizeof(l_fapiTargString));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "loadOCCSetup: FapiTarget: %s",l_fapiTargString);

            //==============================
            //Setup for OCC Load
            //==============================

            // BAR0 is the Entire HOMER (start of HOMER contains OCC base Image)
            // Bar size is in MB
            TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"loadOCCSetup: OCC Address: 0x%0lX, size=0x%.8X",
                       i_occImgPaddr,
                       VMM_HOMER_INSTANCE_SIZE_IN_MB);

            // Remove bit 0, may be set for physical addresses
            uint64_t l_occ_addr = i_occImgPaddr & PHYSICAL_ADDR_MASK;
            FAPI_INVOKE_HWP(l_errl,
                            p10_pm_set_homer_bar,
                            l_fapiTarg,
                            l_occ_addr,
                            VMM_HOMER_INSTANCE_SIZE_IN_MB);

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"loadOCCSetup: Bar0 config failed!" );
                l_errl->collectTrace("ISTEPS_TRACE",256);
                break;
            }

            // BAR2 is the OCC Common Area
            // Bar size is in MB
            TARGETING::Target* sys = nullptr;
            TARGETING::targetService().getTopLevelTarget(sys);
            sys->setAttr<ATTR_OCC_COMMON_AREA_PHYS_ADDR>(i_commonPhysAddr);

            TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"loadOCCSetup: "
                       "OCC Common Addr: 0x%0lX,size=0x%.8X",
                       i_commonPhysAddr,
                       VMM_OCC_COMMON_SIZE_IN_MB);

            // Remove bit 0, may be set for physical addresses
            uint64_t l_common_addr = i_commonPhysAddr & PHYSICAL_ADDR_MASK;
            FAPI_INVOKE_HWP(l_errl,
                            p10_pm_pba_bar_config,
                            l_fapiTarg,
                            2, // Index
                            l_common_addr,
                            VMM_OCC_COMMON_SIZE_IN_MB,
                            p10pba::LOCAL_NODAL,
                            0);

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"loadOCCSetup: Bar2 config failed!" );
                l_errl->collectTrace("ISTEPS_TRACE",256);
                break;
            }

        }while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"loadOCCSetup: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    } // loadOCCSetup


    /**
     * @brief Execute procedures and steps required to load
     *        OCC image in a specified processor
     */
    errlHndl_t loadOCCImageToHomer(TARGETING::Target* i_target,
                                   uint64_t i_occImgPaddr,
                                   uint64_t i_occImgVaddr, // dest
                                   loadPmMode i_mode)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadOCCImageToHomer(OccP:0x%0lX, OccV:0x%0lX)",
                   i_occImgPaddr, i_occImgVaddr);

        errlHndl_t l_errl = nullptr;

        do{
            if(g_pOccLidMgr.get() == nullptr)
            {
                g_pOccLidMgr = std::shared_ptr<UtilLidMgr>
                               (new UtilLidMgr(Util::OCC_LIDID));
            }
            void* l_pLidImage = nullptr;
            size_t l_lidImageSize = 0;

            // NOTE: Ideally, there would also be a check to determine if LID
            //       manager already got the new LID, but the currently
            //       available information does not make it possible to do that.
            if(PM_RELOAD == i_mode)
            {
                // When reloading, release LID image so any update is used
                l_errl = g_pOccLidMgr->releaseLidImage();

                if (l_errl)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            ERR_MRK"loadOCCImageToHomer: "
                            "release stored LID image failed!");
                    l_errl->collectTrace("ISTEPS_TRACE",256);
                    l_errl->collectTrace(FAPI_TRACE_NAME,256);
                    l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                    break;
                }
            }

            l_errl = g_pOccLidMgr->getStoredLidImage(l_pLidImage,
                                                     l_lidImageSize);
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadOCCImageToHomer: "
                           "get stored LID image failed!");
                l_errl->collectTrace("ISTEPS_TRACE",256);
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                break;
            }

            void* l_occVirt = reinterpret_cast<void *>(i_occImgVaddr);

            // copy LID to Homer
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Copying %p to %p for %d bytes",
                       l_occVirt, l_pLidImage, l_lidImageSize );
            memcpy(l_occVirt, l_pLidImage, l_lidImageSize);
        }while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"loadOCCImageToHomer: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    } // loadOCCImageToHomer


    /**
     *  @brief Load OCC/HCODE images into mainstore
     */
    errlHndl_t loadPMComplex(TARGETING::Target * i_target,
                             uint64_t i_homerPhysAddr,
                             uint64_t i_commonPhysAddr,
                             loadPmMode i_mode)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadPMComplex: %s",
                   (PM_LOAD == i_mode) ? "LOAD" : "RELOAD" );

        errlHndl_t l_errl = nullptr;
        void* l_homerVAddr = nullptr;
        ScopedHomerMapper l_homerMapper(i_target);

        do
        {
            // Clear this attribute so hostboot logs an error if a specific
            // situation happens
            i_target->setAttr<ATTR_LOGGED_FAIL_GETTING_OVERRIDE_WOF_TABLE>(0);

            // Update the physical addresses prior to mapping to make sure
            // they are current.
            i_target->setAttr<ATTR_HOMER_PHYS_ADDR>(i_homerPhysAddr);
            UTIL::assertGetToplevelTarget()->
                setAttr<ATTR_OCC_COMMON_AREA_PHYS_ADDR>(i_commonPhysAddr);

            // Reset the PM complex for LOAD only
            if(PM_LOAD == i_mode)
            {
                l_errl = resetPMComplex(i_target);
                if( l_errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"loadPMComplex: "
                               "reset PM complex failed!" );
                    break;
                }
            }

            // Map the HOMER into virual space.
            l_errl = l_homerMapper.map();
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadPMComplex: could not map HOMER to virt space!");
                break;
            }

            l_homerVAddr = reinterpret_cast<void*>(
                                l_homerMapper.getHomerVirtAddr());
            if(nullptr == l_homerVAddr)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadPMComplex: HOMER mapped to nullptr! HOMER_Phys=0x%0lX", i_homerPhysAddr );
                break;
            }

            // Zero out the HOMER memory for LOAD only
            if(PM_LOAD == i_mode)
            {
                memset(l_homerVAddr, 0, VMM_HOMER_INSTANCE_SIZE);
            }

            uint64_t l_occImgPaddr = i_homerPhysAddr
                                            + HOMER_OFFSET_TO_OCC_IMG;
            uint64_t l_occImgVaddr = reinterpret_cast <uint64_t>(l_homerVAddr)
                                            + HOMER_OFFSET_TO_OCC_IMG;
            l_errl = loadOCCSetup(i_target,
                                  l_occImgPaddr,
                                  l_occImgVaddr,
                                  i_commonPhysAddr);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadPMComplex: "
                           "loadOCCSetup failed! "
                           "HUID=0x%08X OCC_Phys=0x%0lX "
                           "OCC_Virt=0x%0lX Common_Phys=0x%0lX",
                           get_huid(i_target), l_occImgPaddr,
                           l_occImgVaddr, i_commonPhysAddr );
                break;
            }

            l_errl = loadOCCImageToHomer(i_target,
                                         l_occImgPaddr,
                                         l_occImgVaddr,
                                         i_mode);
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"loadPMComplex: "
                          "loading OCC failed! "
                          "HUID=0x%08X OCC_Phys=0x%0lX "
                          "OCC_Virt=0x%0lX Mode=%s",
                          get_huid(i_target), l_occImgPaddr, l_occImgVaddr,
                          (PM_LOAD == i_mode) ? "LOAD" : "RELOAD" );
                break;
            }

            void* l_occDataVaddr = reinterpret_cast <void *>(l_occImgVaddr +
                                             HOMER_OFFSET_TO_OCC_HOST_DATA);

            l_errl = loadHostDataToHomer(i_target,
                                         l_occDataVaddr);
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"loadPMComplex: "
                          "loading Host Data Area failed! "
                          "HUID=0x%08X OCC_Host_Data_Virt=0x%0lX",
                          get_huid(i_target), l_occDataVaddr );
                break;
            }

            l_errl = loadHcode(i_target,
                               l_homerVAddr,
                               i_mode);
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"loadPMComplex: "
                          "loadHcode failed! "
                          "HUID=0x%08X HOMER_Virt=0x%0lX Mode=%s",
                          get_huid(i_target), l_occImgVaddr,
                          (PM_LOAD == i_mode) ? "LOAD" : "RELOAD" );
                break;
            }

        } while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"loadPMComplex: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );

        return l_errl;
    }


    /**
     * @brief Start PM Complex.
     */
    errlHndl_t startPMComplex(Target* i_target)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"startPMComplex");

        errlHndl_t l_errl = nullptr;

        TARGETING::Target * l_sys = UTIL::assertGetToplevelTarget();

        ScopedHomerMapper l_homerMapper(i_target);

        void* l_homerVAddr = nullptr;

        // cast OUR type of target to a FAPI type of target.
        // figure out homer offsets
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiTarg(i_target);

        do {
            l_errl = l_homerMapper.map();
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"startPMComplex: could not map HOMER to virt space!");
                break;
            }

            l_homerVAddr = reinterpret_cast<void*>(
                                l_homerMapper.getHomerVirtAddr());
            if(l_homerVAddr == nullptr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     ERR_MRK"startPMComplex: returned HOMER VAddr is nullptr!");
                /*@
                 * @errortype
                 * @reasoncode ISTEP::RC_INVALID_HOMER_VADDR
                 * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid   ISTEP::MOD_START_PM_COMPLEX
                 * @userdata1  HUID
                 * @userdata2  HOMER Phys Addr
                 * @devdesc    Could not map HOMER Physical address to virt
                 * @custdesc   A host failure occurred
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ISTEP::MOD_START_PM_COMPLEX,
                                    ISTEP::RC_INVALID_HOMER_VADDR,
                                    get_huid(i_target),
                                    l_homerMapper.getHomerPhysAddr(),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
            // Init path
            // p10_pm_init.C enum: PM_INIT
            if (TARGETING::is_phyp_load())
            {
                l_sys->setAttr <TARGETING::ATTR_PM_MALF_ALERT_ENABLE> (0x1);
            }
            FAPI_INVOKE_HWP(l_errl,
                            p10_pm_start,
                            l_fapiTarg,
                            l_homerVAddr);

            if ( l_errl != nullptr )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"startPMComplex: "
                           "p10_pm_start failed! "
                           "HUID=0x%08X", get_huid(i_target) );
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

            // The PM Complex is now live, ensure that there are no
            //  lingering special wakeups enabled
            l_errl = WAKEUP::handleSpecialWakeup( i_target,
                                                  WAKEUP::FORCE_DISABLE );
            if( l_errl )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Error disabling wakeup on %.8X",
                           TARGETING::get_huid(i_target) );
                //Just commit the log as informational and keep going
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                l_errl->collectTrace(ISTEP_COMP_NAME,1024);
                errlCommit( l_errl, RUNTIME_COMP_ID );
                l_errl = nullptr;
                break;
            }

        } while (0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"startPMComplex: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    } // startPMComplex


    /**
     * @brief Reset PM Complex.
     */
    errlHndl_t resetPMComplex(TARGETING::Target * i_target)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK" resetPMComplex");

        errlHndl_t l_errl = nullptr;
        ScopedHomerMapper l_homerMapper(i_target);

        // cast OUR type of target to a FAPI type of target.
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiTarg(i_target);

        do
        {
            l_errl = l_homerMapper.map();
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"resetPMComplex: could not map HOMER virt!, ignoring error log and trying to make progress");
                // Make the trace but ignore the error
                delete l_errl;
                l_errl = nullptr;
            }

#if defined(__HOSTBOOT_RUNTIME) && !defined(CONFIG_FSP_BUILD)
            // Inform PHYP that we are about to reset the PM complex on
            //  this chip (BMC systems only)

            // Create the firmware_request request struct
            hostInterfaces::hbrt_fw_msg l_req_msg;
            memset(&l_req_msg, 0, sizeof(l_req_msg));  // clear it all
            l_req_msg.io_type = hostInterfaces::HBRT_FW_MSG_TYPE_PM_RESET_ALERT;

            // Get the Proc Chip Id
            TARGETING::rtChipId_t l_chipId = 0;
            l_errl = TARGETING::getRtTarget(i_target, l_chipId);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"resetPMComplex(): getRtTarget ERROR for %.8X",
                           TARGETING::get_huid(i_target) );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Sending HBRT_FW_MSG_TYPE_PM_RESET_ALERT(%d) message to phyp",
                           l_chipId );

                l_req_msg.pmreset_alert.procId = l_chipId;

                // actual msg size (one type of hbrt_fw_msg)
                uint64_t l_req_msg_size = hostInterfaces::HBRT_FW_MSG_BASE_SIZE +
                  sizeof(l_req_msg.pmreset_alert);

                // Create the firmware_request response struct to receive data
                hostInterfaces::hbrt_fw_msg l_resp_fw_msg;
                uint64_t l_resp_fw_msg_size = sizeof(l_resp_fw_msg);
                memset(&l_resp_fw_msg, 0, l_resp_fw_msg_size);

                // Make the firmware_request call
                l_errl = firmware_request_helper(l_req_msg_size,
                                                 &l_req_msg,
                                                 &l_resp_fw_msg_size,
                                                 &l_resp_fw_msg);
                if (l_errl)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"resetPMComplex(): Error sending firmware_request" );

                    //@fixme in followup commit
                    // To avoid a coreq with the phyp build we will ignore
                    // this error for now
                    l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    l_errl->collectTrace("ISTEPS_TRACE",256);
                    errlCommit(l_errl, ISTEP_COMP_ID);
                }
            }
            // commit the log and move on with the reset, it might be okay...
            if (l_errl)
            {
                l_errl->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                l_errl->collectTrace("ISTEPS_TRACE",256);
                errlCommit(l_errl, ISTEP_COMP_ID);
            }
#endif

            //Get homer image buffer
            void* l_homerVAddr = reinterpret_cast<void*>(
                                    l_homerMapper.getHomerVirtAddr());

            // If this target was already reset previously by the runtime
            //  deconfig logic, then skip it.
            // ATTR_HB_INITIATED_PM_RESET set to COMPLETE signifies that this
            //  chip has already been reset
            auto l_chipResetState =
                     i_target->getAttr<TARGETING::ATTR_HB_INITIATED_PM_RESET>();
            if (HB_INITIATED_PM_RESET_COMPLETE == l_chipResetState)
            {
                // set ATTR_HB_INITIATED_PM_RESET to INACTIVE (reset the reset)
                i_target->setAttr<ATTR_HB_INITIATED_PM_RESET>
                                (HB_INITIATED_PM_RESET_INACTIVE);

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    INFO_MRK"resetPMComplex: reset skipped target huid=0x%X",
                    get_huid(i_target) );

                break;
            }

#if defined(__HOSTBOOT_RUNTIME) && defined(CONFIG_NVDIMM)
            // Notify PHYP that NVDIMMs are not protected from power off event
            l_errl = NVDIMM::notifyNvdimmProtectionChange(i_target, NVDIMM::NOT_PROTECTED);
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"resetPMComplex: unable to notify PHYP that NVDIMM"
                  " is not protected for HUID=0x%.8X", get_huid(i_target) );

                l_errl->collectTrace("ISTEPS_TRACE",256);
                errlCommit(l_errl, ISTEP_COMP_ID);
            }
#endif

            // Reset path
            FAPI_INVOKE_HWP(l_errl,
                            p10_pm_halt,
                            l_fapiTarg,
                            pm::PM_NO_DUMP,
                            l_homerVAddr);

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"resetPMComplex: "
                          "p10_pm_halt failed! "
                          "HUID=0x%08X", get_huid(i_target) );
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "resetPMComplex: p10_pm_halt succeeded "
                       "HUID=0x%08X", get_huid(i_target) );

            // Explicitly call pm_callout before exiting to ensure we
            // gather all of the data before reloading the PM complex.
            callPmCallout( i_target, l_homerVAddr );

        } while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"resetPMComplex: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );

        return l_errl;
    } // resetPMComplex

    /**
     *  @brief Call p10_pm_callout and handle returned data
     */
    void callPmCallout( TARGETING::Target* i_proc_target,
                        void* i_homer_vaddr )
    {
        errlHndl_t l_errl = nullptr;
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
          l_fapiTarg(i_proc_target);
        fapi2::buffer<uint32_t> l_deadCores;
        std::vector<StopErrLogSectn> l_ffdcList;
        RasAction l_rasAction = NO_CALLOUT;

        FAPI_INVOKE_HWP(l_errl,
                        p10_pm_callout,
                        i_homer_vaddr,
                        l_fapiTarg,
                        l_deadCores,
                        l_ffdcList,
                        l_rasAction);
        if(!l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      INFO_MRK"callPmCallout: p10_pm_callout returned no RC action=%d, deadcores=%.8X",
                      l_rasAction,
                      static_cast<uint32_t>(l_deadCores));
            return;
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  INFO_MRK"callPmCallout: p10_pm_callout returned action=%d, deadcores=%.8X",
                  l_rasAction,
                  static_cast<uint32_t>(l_deadCores));
        if( NO_CALLOUT == l_rasAction )
        {
            l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }
        else //commit the log as visible error since it includes callouts
        {
            // add all cores in deadcore list as LOW callouts
            //  to the returned error log
            if( (l_rasAction == CORE_CALLOUT)
                && l_deadCores.getBit(0,32) ) //any bits set
            {
                TargetHandleList l_childCores;;
                getChildChiplets( l_childCores,
                                  i_proc_target,
                                  TARGETING::TYPE_CORE );
                for( auto core : l_childCores )
                {
                    auto l_corenum =
                      core->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                    if( l_deadCores.getBit(l_corenum) )
                    {
                        l_errl->addHwCallout( core,
                                              HWAS::SRCI_PRIORITY_HIGH,
                                              HWAS::NO_DECONFIG,
                                              HWAS::GARD_NULL );
                    }
                }
            }
        }

        // Add FFDC sections
        for( auto & ffdcSctn : l_ffdcList )
        {
            l_errl->addFFDC( HWPF_COMP_ID, ffdcSctn.iv_pBufPtr,
                             ffdcSctn.iv_bufSize, ffdcSctn.iv_subsec,
                             ERRORLOG::ERRL_UDT_NOFORMAT ); // parser ignores data
        }
        l_errl->collectTrace("ISTEPS_TRACE",256);
        errlCommit(l_errl, ISTEP_COMP_ID);
    }


    /**
     *  @brief Load and start PM complex for all chips
     */
    errlHndl_t loadAndStartPMAll(loadPmMode i_mode,
                                 TARGETING::Target* & o_failTarget)
    {
        errlHndl_t l_errl = nullptr;

        TARGETING::Target * l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( l_sys );
        assert(l_sys != nullptr);

        TargetHandleList l_procChips;
        getAllChips(l_procChips, TYPE_PROC, true);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "loadAndStartPMAll: %s %d proc(s) found",
                   (PM_LOAD == i_mode) ? "LOAD" : "RELOAD",
                   l_procChips.size() );

        uint64_t l_homerPhysAddr = 0x0;
        uint64_t l_commonPhysAddr = 0x0;

        do
        {
            // Switching core checkstops from unit to system
            TARGETING::TargetHandleList l_coreTargetList;
            getNonEcoCores(l_coreTargetList);

            if(is_sapphire_load())
            {
                for( auto l_core_target : l_coreTargetList )
                {
                    l_errl = core_checkstop_helper_hwp(l_core_target, true);

                    if( l_errl )
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "loadPM complex, switching core checkstops "
                               "from unit to system ERROR: reason=0x%x",
                               l_errl->reasonCode() );

                        // Capture the target data in the elog
                        ERRORLOG::ErrlUserDetailsTarget(l_core_target).
                                addToLog(l_errl);
                        break;

                    }
                }
            }
            if(l_errl)
            {
                break;
            }

            for (auto & l_procChip: l_procChips)
            {
                ScopedHomerMapper l_homerMapper(l_procChip);
                l_homerMapper.map();
                // This attr was set during istep15 HCODE build
                l_homerPhysAddr = l_procChip->
                        getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
                l_commonPhysAddr = l_sys->
                        getAttr<TARGETING::ATTR_OCC_COMMON_AREA_PHYS_ADDR>();

                l_errl = loadPMComplex(l_procChip,
                                       l_homerPhysAddr,
                                       l_commonPhysAddr,
                                       i_mode);
                if( l_errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"loadAndStartPMAll: "
                               "load PM complex failed!" );
                    o_failTarget = l_procChip;
                    break;
                }

                l_errl = startPMComplex(l_procChip);
                if( l_errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"loadAndStartPMAll: "
                               "start PM complex failed!" );
                    o_failTarget = l_procChip;
                    break;
                }
            }

            if( l_errl )
            {
                break;
            }

            if(is_sapphire_load())
            {
                l_errl = core_checkstop_helper_homer();

                if( l_errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "loadPM complex switching homer xstops from unit "
                           "to system error. ERROR: reaso=0x%x",
                           l_errl->reasonCode() );
                }
            }

        }while(0);

        return l_errl;

    } // loadAndStartPMAll


    /**
     *  @brief Reset PM complex for all chips
     */
    errlHndl_t resetPMAll( resetOptions_t i_opt,
                           uint8_t i_skip_fir_attr_reset)
    {
        errlHndl_t l_errl = nullptr;

        TargetHandleList l_procChips;
        getAllChips(l_procChips, TYPE_PROC, true);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "resetPMAll(%d): %d proc(s) found",
                   i_opt,
                   l_procChips.size());

        for (const auto & l_procChip: l_procChips)
        {
            if( RESET_HW & i_opt )
            {
                l_errl = resetPMComplex(l_procChip);
                if( l_errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"resetPMAll: "
                               "reset PM complex failed!" );
                    break;
                }
            }

            if( CLEAR_ATTRIBUTES & i_opt )
            {
                // Zero out the HOMER vars
                (void) convertHomerPhysToVirt( l_procChip, 0 );

                if (!i_skip_fir_attr_reset)
                {
                    // Zero out the FIR save/restore
                    l_procChip->setAttr<ATTR_PM_FIRINIT_DONE_ONCE_FLAG>(0);
                }
            }
        }

        if( !l_errl )
        {
            if( CLEAR_ATTRIBUTES & i_opt )
            {
                TARGETING::Target* sys = nullptr;
                TARGETING::targetService().getTopLevelTarget(sys);
                sys->setAttr<ATTR_OCC_COMMON_AREA_PHYS_ADDR>(0);
            }
        }

        return l_errl;
    } // resetPMAll


    /**
     *  @brief Verify all OCCs at checkpoint
     */
    errlHndl_t verifyOccChkptAll()
    {
        errlHndl_t l_errl = nullptr;

        TargetHandleList l_procChips;
        getAllChips(l_procChips, TYPE_PROC, true);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "verifyOccChkptAll: %d proc(s) found",
                   l_procChips.size());

        // Wait up to 15 seconds for all OCCs to be ready (150 * 100ms = 15s)
        const size_t NS_BETWEEN_READ = 100 * NS_PER_MSEC;
        const size_t READ_RETRY_LIMIT = 150;
        const uint16_t l_readLength = 8;
        for (const auto & l_procChip: l_procChips)
        {
            uint64_t l_checkpoint = 0x0;
            uint8_t retryCount = 0;
            bool chkptReached = false;

            while (retryCount++ < READ_RETRY_LIMIT)
            {
                // Read SRAM response buffer to check for OCC checkpoint
                l_errl = HBOCC::readSRAM( l_procChip,HTMGT::OCC_RSP_SRAM_ADDR,
                                          &(l_checkpoint),
                                          l_readLength );

                if( l_errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "verifyOccChkptAll: SRAM read failed "
                        "HUID 0x%X", get_huid(l_procChip));
                    break;
                }
                if( OCC_CHKPT_COMPLETE == (l_checkpoint & 0xFFFF) )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "verifyOccChkptAll: OCC checkpoint detected "
                        "HUID 0x%X", get_huid(l_procChip));
                    chkptReached = true;
                    break;
                }

                // Sleep before we check again
                nanosleep(0, NS_BETWEEN_READ);
            }

            if( l_errl )
            {
                break;
            }

            if( !chkptReached )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "verifyOccChkptAll: Timeout waiting for OCC checkpoint "
                    "HUID 0x%X Checkpoint 0x%0lX",
                     get_huid(l_procChip), l_checkpoint);

                /*@
                * @errortype
                * @reasoncode  ISTEP::RC_PM_OCC_CHKPT_TIMEOUT
                * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                * @moduleid    ISTEP::MOD_PM_VERIFY_OCC_CHKPT
                * @userdata1   HUID
                * @userdata2   Checkpoint value
                * @devdesc     Timeout waiting for OCC checkpoint
                * @custdesc    A problem occurred during the IPL
                *              of the system.
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        ISTEP::MOD_PM_VERIFY_OCC_CHKPT,
                                        ISTEP::RC_PM_OCC_CHKPT_TIMEOUT,
                                        get_huid(l_procChip),
                                        l_checkpoint,
                                        true);

                TARGETING::TargetHandleList l_Occs;
                getChildChiplets(l_Occs, l_procChip, TARGETING::TYPE_OCC);

                if( l_Occs[0] != nullptr )
                {
                    l_errl->addHwCallout( l_Occs[0],
                                          HWAS::SRCI_PRIORITY_HIGH,
                                          HWAS::NO_DECONFIG,
                                          HWAS::GARD_NULL );
                }

                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }
        }

        return l_errl;
    } // verifyOccChkptAll


    /**
     *  @brief Fetch the ring overrides (if they exist)
     */
    errlHndl_t getRingOvd(void*& io_overrideImg)
    {
        errlHndl_t l_err = nullptr;

        do {
            io_overrideImg = nullptr;

#ifndef __HOSTBOOT_RUNTIME
            // Block any use of overrides if we're secure
            if( PNOR::isInhibitedSection(PNOR::RINGOVD) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "getRingOvd: ignore overrides in secure mode" );
                break;
            }
#endif

            uint32_t l_lidId = Util::HWREFIMG_RINGOVD_LIDID;
            if(g_pRingOvdLidMgr.get() == nullptr)
            {
                g_pRingOvdLidMgr = std::shared_ptr<UtilLidMgr>
                                                    (new UtilLidMgr(l_lidId));
            }
            void* l_pImageIn = nullptr;
            size_t l_lidImageSize = 0;

            l_err = g_pRingOvdLidMgr->getStoredLidImage(l_pImageIn,
                                                        l_lidImageSize);
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"getRingOvd: get stored LID image failed!");
                l_err->collectTrace("ISTEPS_TRACE",256);
                l_err->collectTrace(FAPI_TRACE_NAME,256);
                l_err->collectTrace(FAPI_IMP_TRACE_NAME,256);
                break;
            }

            if((l_lidImageSize == 0) || (l_pImageIn == nullptr))
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           INFO_MRK"getRingOvd(): RINGOVD section is empty");
                break;
            }

            TRACDBIN( ISTEPS_TRACE::g_trac_isteps_trace,
                      "getRingOvd():100 bytes of RINGOVD section",
                      l_pImageIn, 100);

            // If first 8 bytes are just FF's then we know there's no override
            if((*(static_cast<uint64_t *>(l_pImageIn))) == 0xFFFFFFFFFFFFFFFF )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    INFO_MRK"getRingOvd():No overrides in RINGOVD section "
                            "found");
                break;
            }

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"getRingOvd():Found valid ring overrides");
            io_overrideImg = l_pImageIn;

        }while(0);

        return l_err;
    } // end getRingOvd

//
//  Helper function to enable or disable core checkstops with the HWP
//
errlHndl_t core_checkstop_helper_hwp( const TARGETING::Target* i_core_target,
                            bool i_override_restore)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,ENTER_MRK
               "core_checkstop_helper_hwp(core huid: 0x%08X, override_restore: %d)",
               TARGETING::get_huid(i_core_target), i_override_restore );

    errlHndl_t l_errl = NULL;
    TARGETING::Target* l_sys = NULL;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL );

    do
    {
        assert( i_core_target != NULL );

        const fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapi2_coreTarget(
                const_cast<TARGETING::Target*> ( i_core_target ));

        FAPI_INVOKE_HWP( l_errl, p10_core_checkstop_handler,
                         l_fapi2_coreTarget, i_override_restore);

        if( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "p10_core_checkstop_handler ERROR: returning "
                       "errorlog, reason=0x%x", l_errl->reasonCode() );

            // Capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(i_core_target).
                   addToLog( l_errl );
            break;
        }

    }while(0);

    if( l_errl )
    {
        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,EXIT_MRK
               "core_checkstop_helper_hwp");

    return l_errl;
}

//
//  Helper function to disable core checkstops with the HOMER
//
errlHndl_t core_checkstop_helper_homer()
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,ENTER_MRK
               "core_checkstop_helper_homer");

    errlHndl_t l_errl = NULL;

    do{

        TARGETING::TargetHandleList l_coreIds;
        getNonEcoCores(l_coreIds);

        for(TARGETING::Target* l_core : l_coreIds)
        {
            uint64_t l_action0 = l_core->getAttr<
                        TARGETING::ATTR_ORIG_FIR_SETTINGS_ACTION0>();
            uint64_t l_action1 = l_core->getAttr<
                        TARGETING::ATTR_ORIG_FIR_SETTINGS_ACTION1>();

            uint64_t l_local_xstop = l_action0 & l_action1;
            l_action0 &= ~l_local_xstop;
            l_action1 &= ~l_local_xstop;

            const TARGETING::Target* l_procChip =
                        TARGETING::getParentChip(l_core);

            const uint64_t l_homerAddr = l_procChip->getAttr<
                        TARGETING::ATTR_HOMER_PHYS_ADDR>();

            void* l_homerVAddr = HBPM::convertHomerPhysToVirt(
                                (TARGETING::Target*) l_procChip,
                                l_homerAddr);

            // Translate the scom address
            uint64_t l_scomAddr = scomt::c::EC_PC_FIR_CORE_ACTION0;
            bool l_needsWakeup = false; // Ignored - SW already enabled

            l_errl = SCOM::scomTranslate( l_core, l_scomAddr,
                                          l_needsWakeup );
            if( l_errl )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                           "core_checkstop_helper: scomTranslate ERROR");
                break;
            }

            stopImageSection::StopReturnCode_t l_srErrl =
                                stopImageSection::proc_stop_save_scom(
                                l_homerVAddr, l_scomAddr, l_action0,
                                stopImageSection::PROC_STOP_SCOM_REPLACE,
                                stopImageSection::PROC_STOP_SECTION_CORE );

            if( l_srErrl != stopImageSection::StopReturnCode_t::
                                STOP_SAVE_SUCCESS )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "core_checkstop_helper: Returning errorlog, "
                           "reason=0x%x",l_srErrl );

                break;
            }

            // Translate the scom address
            l_scomAddr = scomt::c::EC_PC_FIR_CORE_ACTION1;

            l_errl = SCOM::scomTranslate(l_core, l_scomAddr,
                                l_needsWakeup);

            if( l_errl )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                           "core_checkstop_helper: scomTranslate ERROR");
                break;
            }

            l_srErrl = stopImageSection::proc_stop_save_scom(
                                l_homerVAddr, l_scomAddr, l_action1,
                                stopImageSection::PROC_STOP_SCOM_REPLACE,
                                stopImageSection::PROC_STOP_SECTION_CORE );

            if( l_srErrl != stopImageSection::StopReturnCode_t::
                                STOP_SAVE_SUCCESS )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "core_checkstop_helper: Returning errorlog, "
                           "reason=0x%x",l_srErrl );

                break;
            }

        }
    } while(0);

    if( l_errl )
    {
        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,EXIT_MRK
               "core_checkstop_helper_homer");

    return l_errl;

}


}  // end HBPM namespace

