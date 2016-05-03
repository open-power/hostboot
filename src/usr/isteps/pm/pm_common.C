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

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <sys/misc.h>

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
#include    <util/utillidmgr.H>
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

using namespace TARGETING;
using namespace p9_hcodeImageBuild;

namespace HBPM
{
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
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
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

        uint32_t nestFreq =  sysTarget->getAttr<ATTR_FREQ_PB>();

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
                   i_target->getAttr<ATTR_HUID>(),
                   i_pImageOut,
                   i_mode);

        errlHndl_t l_errl = NULL;

        // cast OUR type of target to a FAPI type of target.
        // figure out homer offsets
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapiTarg(i_target);
/* @TODO RTC: 148935 start */
        void *l_pImageIn = NULL;

        do
        {
            // @TODO RTC: 148935 Only get LID once from pnor/fsp
            size_t lidSize = 0;
            uint32_t lidId = (i_target->getAttr<ATTR_MODEL>() == MODEL_NIMBUS)
                           ? HBPM::NIMBUS_HCODE_LIDID
                           : HBPM::CUMULUS_HCODE_LIDID;
            UtilLidMgr lidMgr(lidId);

            l_errl = lidMgr.getLidSize(lidSize);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode: "
                           "Error getting lid size.  lidId=0x%.8x",
                           lidId);
                break;
            }

            // allocate memory for Hcode
            l_pImageIn = static_cast<void*>(malloc(lidSize));

            l_errl = lidMgr.getLid(l_pImageIn, lidSize);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode: "
                           "Error getting lid.  lidId=0x%.8x",
                           lidId);
                break;
            }

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "loadHcode: HCODE addr = 0x%p ",
                       l_pImageIn);

            ImageType_t l_imgType;
            void *l_buffer = (void*)malloc(HW_IMG_RING_SIZE);

            FAPI_INVOKE_HWP( l_errl,
                             p9_hcode_image_build,
                             l_fapiTarg,
                             l_pImageIn,
                             i_pImageOut,
                             (HBRT_PM_LOAD == i_mode)
                                 ? PHASE_IPL : PHASE_REBUILD,
                             l_imgType,
                             l_buffer );

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadHcode: p9_hcode_image_build failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

            // Log some info about Homer
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "pImageOut=%p",i_pImageOut);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "lidSize=%d",lidSize);

            // Log some info from the headers
            Homerlayout_t* pChipHomer = (Homerlayout_t*)i_pImageOut;

            // SGPE Region with QPMR Header
            SgpeLayout_t* pSgpeLayout =
                (SgpeLayout_t*)(&(pChipHomer->sgpeRegion));
            QpmrHeaderLayout_t* pQpmrHeaderLayout =
                (QpmrHeaderLayout_t*)(&(pSgpeLayout->qpmrHeader));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "QPMR -- Date:%d, Version:%d",
                      pQpmrHeaderLayout->buildDate,
                      pQpmrHeaderLayout->buildVersion);

            SgpeImageHeader_t* pSgpeImageHeader =
                (SgpeImageHeader_t*)(&(pSgpeLayout->imgHeader));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SGPE -- Location: %p, Date:%d, Version:%d",
                      pSgpeLayout,
                      pSgpeImageHeader->buildDate,
                      pSgpeImageHeader->buildVer);

            // CME Region
            CmeRegionLayout_t* pCmeLayout =
                (CmeRegionLayout_t*)(&(pChipHomer->cmeRegion));
            CmeImageHeader_t* pCmeImageHeader =
                (CmeImageHeader_t*)(&(pCmeLayout->imgHeader));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "CME  -- Location: %p, Date:%d, Version:%d",
                      pCmeLayout,
                      pCmeImageHeader->buildDate,
                      pCmeImageHeader->buildVer);

            // PGPE Region
            PgpeLayout_t* pPgpeLayout =
                (PgpeLayout_t*)(&(pChipHomer->pgpeRegion));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "PGPE -- Location: %p",
                      pPgpeLayout);
        } while(0);
/* end @TODO RTC: 148935 */
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
            char l_fapiTargString[50]; // @TODO RTC: 148935 Find constant for 50
            toString(l_fapiTarg, l_fapiTargString, sizeof(l_fapiTargString));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "loadOCCSetup: FapiTarget: %s",l_fapiTargString);

            //==============================
            //Setup for OCC Load
            //==============================

            // BAR0 is the Entire HOMER (start of HOMER contains OCC base Image)
            // Bar size is in MB, obtained value of 4MB from Greg Still
            TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"loadOCCSetup: OCC Address: 0x%.8X, size=0x%.8X",
                       i_occImgPaddr, VMM_HOMER_INSTANCE_SIZE_IN_MB);
                       // @TODO RTC: 148935 Find/Define size constant in HWP dir
/* @TODO RTC: 148935 start */
            FAPI_INVOKE_HWP( l_errl,
                             p9_pm_pba_bar_config,
                             l_fapiTarg,
                             0,
                             i_occImgPaddr,
                             VMM_HOMER_INSTANCE_SIZE_IN_MB, // @TODO RTC: 148935
                             // Find/Define constant in HWP directory for size
                             p9pba::LOCAL_NODAL,
                             0xFF );

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadOCCSetup: Bar0 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                l_errl->collectTrace("ISTEPS_TRACE",256);
                break;
            }
/* end @TODO RTC: 148935 */
            // BAR2 is the OCC Common Area
            // Bar size is in MB
            TARGETING::Target* sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);
            sys->setAttr<ATTR_OCC_COMMON_AREA_PHYS_ADDR>(i_commonPhysAddr);

            TRACUCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"loadOCCSetup: "
                       "OCC Common Addr: 0x%.8X,size=0x%.8X",
                       i_commonPhysAddr,VMM_OCC_COMMON_SIZE_IN_MB);
                       // @TODO RTC: 148935 Find/Define size constant in HWP dir
/* @TODO RTC: 148935 start */
            FAPI_INVOKE_HWP( l_errl,
                             p9_pm_pba_bar_config,
                             l_fapiTarg,
                             2,
                             i_commonPhysAddr,
                             VMM_OCC_COMMON_SIZE_IN_MB, // @TODO RTC: 148935
                             // Find/Define constant in HWP directory for size
                             p9pba::LOCAL_NODAL,
                             0xFF );

            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadOCCSetup: Bar2 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                l_errl->collectTrace("ISTEPS_TRACE",256);
                break;
            }
/* end @TODO RTC: 148935 */
        }while(0);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"loadOCCSetup: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    }


    /**
     * @brief Execute procedures and steps required to load
     *        OCC image in a specified processor
     */
    errlHndl_t loadOCCImageToHomer(TARGETING::Target* i_target,
                                   uint64_t i_occImgPaddr,
                                   uint64_t i_occImgVaddr) // dest
    {
        errlHndl_t l_errl = NULL;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ENTER_MRK"loadOCCImageToHomer(0x%08X, 0x%08X)",
                   i_occImgPaddr, i_occImgVaddr);
        do{
            void* occVirt = reinterpret_cast<void *>(i_occImgVaddr);

            // @TODO RTC: 148935 Only get LID once from pnor/fsp
            size_t lidSize = 0;
            UtilLidMgr lidMgr(HBPM::OCC_LIDID);

            l_errl = lidMgr.getLidSize(lidSize);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadOCCImageToHomer: "
                           "Error getting lid size.  lidId=0x%.8x",
                           OCC_LIDID);
                break;
            }

            l_errl = lidMgr.getLid(occVirt, lidSize);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"loadOCCImageToHomer: "
                           "Error getting lid.  lidId=0x%.8x",
                           OCC_LIDID);
                break;
            }
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
/* @TODO RTC: 148935 start */
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
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

        } while (0);
/* end @TODO RTC: 148935 */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"startPMComplex: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    }


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
/* @TODO RTC: 148935 start */
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
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                l_errl->collectTrace("ISTEPS_TRACE",256);

                break;
            }

        } while(0);
/* end @TODO RTC: 148935 */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   EXIT_MRK"resetPMComplex: RC=0x%X, PLID=0x%lX",
                   ERRL_GETRC_SAFE(l_errl), ERRL_GETPLID_SAFE(l_errl) );
        return l_errl;
    }

}  // end HBPM namespace

