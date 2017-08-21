/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/pm_common.C $                               */
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

#include    <stdint.h>

#include    <pm/pm_common.H>

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <errl/errlreasoncodes.H>

#include    <sys/misc.h>
#include    <sys/mm.h>
#include    <sys/time.h>

#include    <util/utilxipimage.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/targetservice.H>
#include    <targeting/common/util.H>

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

// Procedures
#include <p9_pm_pba_bar_config.H>
#include <p9_pm_init.H>
#include <p9_hcode_image_build.H>

#include <p9_hcode_image_defines.H>
#include <p9_xip_image.h>


#include <arch/ppc.H>
#include <isteps/pm/occAccess.H>

#include <isteps/pm/occCheckstop.H>

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
  #include <diag/prdf/prdfWriteHomerFirData.H>
#endif

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// Definitions for convertHomerPhysToVirt()
#ifndef __HOSTBOOT_RUNTIME
#define HBPM_UNMAP     mm_block_unmap
#define HBPM_MAP       mm_block_map
#define HBPM_PHYS_ADDR (reinterpret_cast<void*>(i_phys_addr))
#else
#define HBPM_UNMAP     g_hostInterfaces->unmap_phys_mem
#define HBPM_MAP       g_hostInterfaces->map_phys_mem
#define HBPM_PHYS_ADDR i_phys_addr
#endif


using namespace TARGETING;
using namespace p9_hcodeImageBuild;

namespace HBPM
{
    constexpr uint32_t OCC_SRAM_RSP_ADDR   = 0xFFFBF000;
    constexpr uint16_t OCC_CHKPT_COMPLETE  = 0x0EFF;
    const uint32_t IPL_FLAG_AND_FREQ_SIZE = sizeof(uint32_t) + sizeof(uint16_t);


    std::shared_ptr<UtilLidMgr> g_pOccLidMgr (nullptr);
    std::shared_ptr<UtilLidMgr> g_pHcodeLidMgr (nullptr);
    std::shared_ptr<UtilLidMgr> g_pRingOvdLidMgr (nullptr);

    /**
     *  @brief Convert HOMER physical address space to a vitual address
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

            l_virt_addr = HBPM_MAP(HBPM_PHYS_ADDR,
                                   sizeof(Homerlayout_t));

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
        l_config_data->nestFrequency = sysTarget->getAttr<ATTR_FREQ_PB_MHZ>();

        // Figure out the interrupt type
        if( INITSERVICE::spBaseServicesEnabled() )
        {
            l_config_data->interruptType = USE_FSI2HOST_MAILBOX;
        }
        else
        {
            l_config_data->interruptType = USE_PSIHB_COMPLEX;
        }

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
        // Figure out the FIR master
        TARGETING::Target* masterproc = nullptr;
        tS.masterProcChipTargetHandle( masterproc );
        if( masterproc == i_proc )
        {
            l_config_data->firMaster = IS_FIR_MASTER;

            #if !defined(__HOSTBOOT_RUNTIME) || defined(CONFIG_HBRT_PRD)
            l_errl = PRDF::writeHomerFirData( l_config_data->firdataConfig,
                                         sizeof(l_config_data->firdataConfig) );
            #endif

        }
        else
        {
            l_config_data->firMaster = NOT_FIR_MASTER;
        }

#else
        l_config_data->firMaster = 0;
#endif

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

        void *l_buffer0 = (void*)malloc(HW_IMG_RING_SIZE);
        void *l_buffer1 = (void*)malloc(MAX_RING_BUF_SIZE);
        void *l_buffer2 = (void*)malloc(MAX_RING_BUF_SIZE);
        void *l_buffer3 = (void*)malloc(MAX_RING_BUF_SIZE);

        do
        {
            bool l_isNimbus = (i_target->getAttr<ATTR_MODEL>() == MODEL_NIMBUS);
            uint32_t l_lidId = (l_isNimbus) ? Util::NIMBUS_HCODE_LIDID
                                            : Util::CUMULUS_HCODE_LIDID;
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
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode(): Error in call to getRingOvd!");
                break;
            }

            FAPI_INVOKE_HWP( l_errl,
                             p9_hcode_image_build,
                             l_fapiTarg,
                             l_pImageIn, //reference image
                             i_pImageOut, //homer image buffer
                             l_ringOverrides,
                             (PM_LOAD == i_mode)
                                 ? PHASE_IPL : PHASE_REBUILD,
                             l_imgType,
                             l_buffer0,
                             HW_IMG_RING_SIZE,
                             l_buffer1,
                             MAX_RING_BUF_SIZE,
                             l_buffer2,
                             MAX_RING_BUF_SIZE,
                             l_buffer3,
                             MAX_RING_BUF_SIZE);

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode: p9_hcode_image_build failed!" );
                l_errl->addFFDC( ISTEP_COMP_ID,
                                 reinterpret_cast<void *>(&l_imageBuild),
                                 sizeof(Util::imageBuild_t),
                                 0,                           // Version
                                 ERRORLOG::ERRL_UDT_NOFORMAT, // parser ignores
                                 false );                     // merge
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

            // Log some info about Homer
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "pImageOut=%p",i_pImageOut);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "lidSize=%d",l_lidImageSize);

            // Log some info from the headers in the Homer layout
            Homerlayout_t* pChipHomer = (Homerlayout_t*)i_pImageOut;

            // QPMR Region with SGPE Region
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "QPMR region -- Location: %p",
                      &(pChipHomer->qpmrRegion));

            QpmrHeaderLayout_t* pQpmrHeader = (QpmrHeaderLayout_t*)
                (&(pChipHomer->qpmrRegion.sgpeRegion.qpmrHeader));
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "QPMR header -- Date:0x%08X, Version:0x%08X, "
                      "Image offset:0x%08X, Image length:0x%08X, "
                      "Bootloader offset:0x%08X, Bootloader length:0x%08X",
                      pQpmrHeader->buildDate,
                      pQpmrHeader->buildVersion,
                      pQpmrHeader->sgpeImgOffset,
                      pQpmrHeader->sgpeImgLength,
                      pQpmrHeader->bootLoaderOffset,
                      pQpmrHeader->bootLoaderLength);

            sgpeHeader_t* pSgpeImageHeader = (sgpeHeader_t*)
                    & pChipHomer->qpmrRegion.sgpeRegion.sgpeSramImage[SGPE_INT_VECTOR_SIZE];
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SGPE header -- Date:0x%08X, Version:0x%08X, "
                      "Image offset:0x%08X, Image length:0x%08X",
                      pSgpeImageHeader->g_sgpe_build_date,
                      pSgpeImageHeader->g_sgpe_build_ver);

            // CPMR Region with Self Restore Region and CME Binary
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "CPMR region -- Location: %p",
                      &(pChipHomer->cpmrRegion));

            cpmrHeader_t* pCpmrHeader =
                (cpmrHeader_t*)(&(pChipHomer->
                    cpmrRegion.selfRestoreRegion.CPMR_SR.elements.CPMRHeader));
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "CMPR header -- Date:0x%08X, Version:0x%08X, "
                      "Image offset:0x%08X, Image length:0x%08X",
                      pCpmrHeader->cpmrbuildDate,
                      pCpmrHeader->cpmrVersion,
                      pCpmrHeader->cmeImgOffset,
                      pCpmrHeader->cmeImgLength);

            cmeHeader_t* pCmeHeader = (cmeHeader_t*)
                    & pChipHomer->cpmrRegion.cmeSramRegion[CME_INT_VECTOR_SIZE];
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "CME header  -- Hcode offset:0x%08X, Hcode length:0x%08X",
                      pCmeHeader->g_cme_hcode_offset,
                      pCmeHeader->g_cme_hcode_length);

            // PPMR Region
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PPMR region -- Location: %p",
                      &(pChipHomer->ppmrRegion));

            PpmrHeader_t* pPpmrHeader = (PpmrHeader_t *)pChipHomer->ppmrRegion.ppmrHeader;
            PgpeHeader_t* pPgpeHeader = (PgpeHeader_t*)
                (&(pChipHomer->ppmrRegion.pgpeSramImage[PGPE_INT_VECTOR_SIZE]));
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PGPE header -- Date:0x%08X, Version:0x%08X, "
                      "Hcode offset:0x%08X, Hcode length:0x%08X",
                      pPgpeHeader->g_pgpe_build_date,
                      pPgpeHeader->g_pgpe_build_ver,
                      pPpmrHeader->g_ppmr_hcode_offset,
                      pPpmrHeader->g_ppmr_hcode_length);

        } while(0);

        free(l_buffer0);
        free(l_buffer1);
        free(l_buffer2);
        free(l_buffer3);

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
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
            FAPI_INVOKE_HWP( l_errl,
                             p9_pm_pba_bar_config,
                             l_fapiTarg,
                             0,
                             l_occ_addr,
                             VMM_HOMER_INSTANCE_SIZE_IN_MB,
                             p9pba::LOCAL_NODAL,
                             0xFF );

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
            FAPI_INVOKE_HWP( l_errl,
                             p9_pm_pba_bar_config,
                             l_fapiTarg,
                             2,
                             l_common_addr,
                             VMM_OCC_COMMON_SIZE_IN_MB,
                             p9pba::LOCAL_NODAL,
                             0xFF );

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
                             loadPmMode i_mode,
                             bool i_useSRAM)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadPMComplex: %s",
                   (PM_LOAD == i_mode) ? "LOAD" : "RELOAD" );

        errlHndl_t l_errl = nullptr;

        do
        {
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

            void* l_homerVAddr = convertHomerPhysToVirt(i_target,
                                                        i_homerPhysAddr);
            if(nullptr == l_homerVAddr)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadPMComplex: "
                           "convertHomerPhysToVirt failed! "
                           "HOMER_Phys=0x%0lX", i_homerPhysAddr );
                break;
            }

            // Zero out the HOMER memory for LOAD only
            if(PM_LOAD == i_mode && !i_useSRAM)
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
#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
            if(i_useSRAM)
            {
                void* l_occVirt = reinterpret_cast<void *>(l_occImgVaddr);
                l_errl = HBOCC::loadOCCImageDuringIpl(i_target, l_occVirt);
                if(l_errl)
                {
                    TRACFCOMP(g_fapiImpTd,
                            ERR_MRK"loadPMComplex:"
                            " loadOCCImageDuringIpl failed!");
                    break;
                }
            }
            else
#endif
            {
#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
                //If we're in Checkstop analysis and get here, we need
                //to clear the IPL flag that got set during istep 6
                const uint32_t l_sramAddrApp = HBOCC::OCC_405_SRAM_ADDRESS;
                uint8_t l_occAppData[HBOCC::OCC_OFFSET_IPL_FLAG
                                                      + IPL_FLAG_AND_FREQ_SIZE];
                memset(l_occAppData, 0, HBOCC::OCC_OFFSET_IPL_FLAG
                                                      + IPL_FLAG_AND_FREQ_SIZE);
                l_errl = HBOCC::writeSRAM(i_target, l_sramAddrApp,
                      (uint64_t*) l_occAppData, HBOCC::OCC_OFFSET_IPL_FLAG
                                                      + IPL_FLAG_AND_FREQ_SIZE);
                if(l_errl)
                {
                    TRACFCOMP(g_fapiImpTd,
                              "loadPMComplex: Error erasing IPL flag");
                    break;
                }
#endif
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
            }
#if defined(CONFIG_IPLTIME_CHECKSTOP_ANALYSIS) && !defined(__HOSTBOOT_RUNTIME)
            if(i_useSRAM)
            {
                //==============================
                //Setup host data area in SRAM
                //==============================
                l_errl = HBOCC::loadHostDataToSRAM(i_target,
                                                        PRDF::MASTER_PROC_CORE);
                if( l_errl != NULL )
                {
                    TRACFCOMP(g_fapiImpTd,
                                       ERR_MRK"loading Host Data Area failed!");
                    break;
                }
            }
            else
#endif
            {
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
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"loadPMComplex: "
                               "loadHcode failed! "
                               "HUID=0x%08X HOMER_Virt=0x%0lX Mode=%s",
                               get_huid(i_target), l_occImgVaddr,
                               (PM_LOAD == i_mode) ? "LOAD" : "RELOAD" );
                    break;
                }
            }

            //If i_useSRAM is true, then we're in istep 6.11. This address needs
            //to be reset here, so that it's recalculated again in istep 21.1
            //where this function is called.
            if(i_useSRAM)
            {
                i_target->setAttr<ATTR_HOMER_VIRT_ADDR>(0);
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

        //Get homer image buffer
        uint64_t l_homerPhysAddr = 0x0;
        l_homerPhysAddr = i_target->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
        void* l_homerVAddr = convertHomerPhysToVirt(i_target,l_homerPhysAddr);

        // cast OUR type of target to a FAPI type of target.
        // figure out homer offsets
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiTarg(i_target);

        do {
            // Init path
            // p9_pm_init.C enum: PM_INIT
            FAPI_INVOKE_HWP( l_errl,
                             p9_pm_init,
                             l_fapiTarg,
                             p9pm::PM_INIT,
                             l_homerVAddr);

            if ( l_errl != nullptr )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"startPMComplex: "
                           "p9_pm_init(PM_INIT) failed! "
                           "HUID=0x%08X", get_huid(i_target) );
                l_errl->collectTrace("ISTEPS_TRACE",256);

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
                   ENTER_MRK"resetPMComplex");

        errlHndl_t l_errl = nullptr;

        //Get homer image buffer
        uint64_t l_homerPhysAddr = 0x0;
        l_homerPhysAddr = i_target->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
        void* l_homerVAddr = convertHomerPhysToVirt(i_target,l_homerPhysAddr);

        // cast OUR type of target to a FAPI type of target.
        // figure out homer offsets
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiTarg(i_target);

        do
        {
            // Reset path
            // p9_pm_init.C enum: PM_RESET
            FAPI_INVOKE_HWP( l_errl,
                             p9_pm_init,
                             l_fapiTarg,
                             p9pm::PM_RESET,
                             l_homerVAddr );

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"resetPMComplex: "
                           "p9_pm_init(PM_RESET) failed! "
                           "HUID=0x%08X", get_huid(i_target) );
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

        } while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"resetPMComplex: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    } // resetPMComplex


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

        for (const auto & l_procChip: l_procChips)
        {
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

        return l_errl;
    } // loadAndStartPMAll


    /**
     *  @brief Reset PM complex for all chips
     */
    errlHndl_t resetPMAll()
    {
        errlHndl_t l_errl = nullptr;

        TargetHandleList l_procChips;
        getAllChips(l_procChips, TYPE_PROC, true);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "resetPMAll: %d proc(s) found",
                   l_procChips.size());

        for (const auto & l_procChip: l_procChips)
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
                l_errl = HBOCC::readSRAM( l_procChip,OCC_SRAM_RSP_ADDR,
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

            // Block any use of overrides if we're secure
            if( PNOR::isInhibitedSection(PNOR::RINGOVD) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "getRingOvd: ignore overrides in secure mode" );
                break;
            }

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

}  // end HBPM namespace

