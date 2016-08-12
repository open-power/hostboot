/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/pm/pm_common.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include    <isteps/pm/pm_common_ext.H>

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <sys/misc.h>
#include    <sys/mm.h>
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

// Procedures
#include <p9_pm_pba_bar_config.H>
#include <p9_pm_init.H>
#include <p9_hcode_image_build.H>

#include <p9_hcode_image_defines.H>

#include <arch/ppc.H>

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
    constexpr uint64_t OCC_HOST_AREA_SIZE_IN_MB = OCC_HOST_AREA_SIZE / ONE_MB;
    constexpr uint64_t HOMER_INSTANCE_SIZE_IN_MB =
        sizeof(Homerlayout_t) / ONE_MB;

    std::shared_ptr<UtilLidMgr> g_pOccLidMgr (nullptr);
    std::shared_ptr<UtilLidMgr> g_pHcodeLidMgr (nullptr);

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
            (NULL == l_virt_addr))
        {
            if(NULL != l_virt_addr)
            {
                rc = HBPM_UNMAP(l_virt_addr);

                if(rc)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              ERR_MRK"convertHomerPhysToVirt: "
                              "unmap_phys_mem failed, rc=0x%0X",
                              rc);

                    l_virt_addr = NULL;
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
     * @brief Build new Pstate Parameter Block for PGPE and CME
     */
    errlHndl_t pstateParameterBuild( TARGETING::Target* i_target,
                                     void* i_homer)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"pstateParameterBuild(%p)",
                   i_homer);

        errlHndl_t l_errl = NULL;

        // cast OUR type of target to a FAPI type of target.
        // figure out homer offsets
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiTarg(i_target);

        do
        {
            // p9_pstate_parameter_build.C
/*            FAPI_INVOKE_HWP( l_errl,
                             p9_pstate_parameter_build,
                             l_fapiTarg,
                             i_homer ); @TODO RTC:153885 */

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"pstateParameterBuild: "
                           "p9_pstate_parameter_build failed!" );
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

        } while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"pstateParameterBuild: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    } // pstateParameterBuild

    /**
     * @brief Sets up OCC Host data in Homer
     */
    errlHndl_t loadHostDataToHomer( TARGETING::Target* i_proc,
                                    void* i_occHostDataVirtAddr)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadHostDataToHomer(%p)",
                   i_occHostDataVirtAddr);

        errlHndl_t l_errl = NULL;

        //Treat virtual address as starting pointer
        //for config struct
        HBPM::occHostConfigDataArea_t * config_data =
            reinterpret_cast<HBPM::occHostConfigDataArea_t *>
            (i_occHostDataVirtAddr);

        // Get top level system target
        TARGETING::TargetService & tS = TARGETING::targetService();
        TARGETING::Target * sysTarget = NULL;
        tS.getTopLevelTarget( sysTarget );
        assert( sysTarget != NULL );

        uint32_t nestFreq =  sysTarget->getAttr<ATTR_FREQ_PB_MHZ>();

        config_data->version = HBPM::OccHostDataVersion;
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

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
        // Figure out the FIR master
        TARGETING::Target* masterproc = NULL;
        tS.masterProcChipTargetHandle( masterproc );
        if( masterproc == i_proc )
        {
            config_data->firMaster = IS_FIR_MASTER;

            // TODO: RTC 124683 The ability to write the HOMER data
            //        is currently not available at runtime.
#ifndef __HOSTBOOT_RUNTIME
            l_errl = PRDF::writeHomerFirData( config_data->firdataConfig,
                                          sizeof(config_data->firdataConfig) );
#endif

        }
        else
        {
            config_data->firMaster = NOT_FIR_MASTER;
        }

#else
        config_data->firMaster = 0;
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
                          uint32_t i_mode )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadHcode(0x%08X, %p, %d)",
                   get_huid(i_target),
                   i_pImageOut,
                   i_mode);

        errlHndl_t l_errl = NULL;

        // cast OUR type of target to a FAPI type of target.
        // figure out homer offsets
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiTarg(i_target);

        void *l_buffer0 = (void*)malloc(HW_IMG_RING_SIZE);
        void *l_buffer1 = (void*)malloc(HW_IMG_RING_SIZE);

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
            void* l_pImageIn = NULL;
            size_t l_lidImageSize = 0;

            // NOTE: Ideally, there would also be a check to determine if LID
            //       manager already got the new LID, but the currently
            //       available information does not make it possible to do that.
            if(HBRT_PM_RELOAD == i_mode)
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

            ImageType_t l_imgType;

            FAPI_INVOKE_HWP( l_errl,
                             p9_hcode_image_build,
                             l_fapiTarg,
                             l_pImageIn, //reference image
                             i_pImageOut, //homer image buffer
                             NULL, //default is no ring overrides
                             (HBRT_PM_LOAD == i_mode)
                                 ? PHASE_IPL : PHASE_REBUILD,
                             l_imgType,
                             l_buffer0,
                             HW_IMG_RING_SIZE,
                             l_buffer1,
                             HW_IMG_RING_SIZE );

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode: p9_hcode_image_build failed!" );
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
                (&(pChipHomer->qpmrRegion.sgpeRegion.imgHeader));
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
                (&(pChipHomer->cpmrRegion.cmeBin.elements.imgHeader));
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "CME header  -- Hcode offset:0x%08X, Hcode length:0x%08X",
                      pCmeHeader->g_cme_hcode_offset,
                      pCmeHeader->g_cme_hcode_length);

            // PPMR Region
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PPMR region -- Location: %p",
                      &(pChipHomer->ppmrRegion));

            PgpeHeader_t* pPgpeHeader = (PgpeHeader_t*)
                (&(pChipHomer->ppmrRegion.pgpeBin.elements.imgHeader));
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PGPE header -- Date:0x%08X, Version:0x%08X, "
                      "Hcode offset:0x%08X, Hcode length:0x%08X",
                      pPgpeHeader->g_pgpe_build_date,
                      pPgpeHeader->g_pgpe_build_ver,
                      pPgpeHeader->g_pgpe_hcode_offset,
                      pPgpeHeader->g_pgpe_hcode_length);

        } while(0);

        free(l_buffer0);
        free(l_buffer1);

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
        errlHndl_t l_errl = NULL;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadOCCSetup(0x%08X, 0x%08X, 0x%08X)",
                        i_occImgPaddr, i_occImgVaddr, i_commonPhysAddr);
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
                       INFO_MRK"loadOCCSetup: OCC Address: 0x%.8X, size=0x%.8X",
                       i_occImgPaddr,
                       HOMER_INSTANCE_SIZE_IN_MB);

            // Remove bit 0, may be set for physical addresses
            uint64_t l_occ_addr = i_occImgPaddr & PHYSICAL_ADDR_MASK;
            FAPI_INVOKE_HWP( l_errl,
                             p9_pm_pba_bar_config,
                             l_fapiTarg,
                             0,
                             l_occ_addr,
                             HOMER_INSTANCE_SIZE_IN_MB,
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
            TARGETING::Target* sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);
            sys->setAttr<ATTR_OCC_COMMON_AREA_PHYS_ADDR>(i_commonPhysAddr);

            TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"loadOCCSetup: "
                       "OCC Common Addr: 0x%.8X,size=0x%.8X",
                       i_commonPhysAddr,
                       OCC_HOST_AREA_SIZE_IN_MB);

            // Remove bit 0, may be set for physical addresses
            uint64_t l_common_addr = i_commonPhysAddr & PHYSICAL_ADDR_MASK;
            FAPI_INVOKE_HWP( l_errl,
                             p9_pm_pba_bar_config,
                             l_fapiTarg,
                             2,
                             l_common_addr,
                             OCC_HOST_AREA_SIZE_IN_MB,
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
                                   uint32_t i_mode)
    {
        errlHndl_t l_errl = NULL;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadOCCImageToHomer(0x%08X, 0x%08X)",
                   i_occImgPaddr, i_occImgVaddr);
        do{
            if(g_pOccLidMgr.get() == nullptr)
            {
                g_pOccLidMgr = std::shared_ptr<UtilLidMgr>
                               (new UtilLidMgr(Util::OCC_LIDID));
            }
            void* l_pLidImage = NULL;
            size_t l_lidImageSize = 0;

            // NOTE: Ideally, there would also be a check to determine if LID
            //       manager already got the new LID, but the currently
            //       available information does not make it possible to do that.
            if(HBRT_PM_RELOAD == i_mode)
            {
                // When reloading, release LID image so any update is used
                l_errl = g_pOccLidMgr->releaseLidImage();
            }

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

            void* occVirt = reinterpret_cast<void *>(i_occImgVaddr);

            // copy LID to Homer
            memcpy(occVirt, l_pLidImage, l_lidImageSize);
        }while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"loadOCCImageToHomer: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    } // loadOCCImageToHomer


    /**
     * @brief Start PM Complex.
     */
    errlHndl_t startPMComplex (Target* i_target)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"startPMComplex");
        errlHndl_t l_errl = NULL;

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
                             p9pm::PM_INIT );

            if ( l_errl != NULL )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"startPMComplex: p9_pm_init, init failed!" );
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
        errlHndl_t l_errl = NULL;

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
                             p9pm::PM_RESET );

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"resetPMComplex:p9_pm_init, reset failed!" );
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

        } while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"resetPMComplex: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    } // resetPMComplex

}  // end HBPM namespace

