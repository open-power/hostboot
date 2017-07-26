/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_load_io_ppe.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

#include    <errl/errlentry.H>
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <fapi2/target.H>
#include    <fapi2/plat_hwp_invoker.H>

#include    <p9_io_obus_image_build.H>
#include    <p9_io_xbus_image_build.H>

using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   fapi2;


namespace ISTEP_16
{

/**
 *  @brief Load HCODE image and return a pointer to it, or NULL
 *  @param[out] -   address of the HCODE image
 *  @return      NULL if success, errorlog if failure
 */
errlHndl_t loadHcodeImage(char *& o_rHcodeAddr)
{
    errlHndl_t l_err = NULL;
    PNOR::SectionInfo_t l_info;

    do
    {

#ifdef CONFIG_SECUREBOOT
        l_err = loadSecureSection(PNOR::HCODE);
        if (l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"loadHcodeImage() - Error from "
                       "loadSecureSection(PNOR::HCODE)");

            //No need to commit error here, it gets handled later
            //just break out to escape this function
            break;
        }
#endif

        // Get HCODE/WINK PNOR section info from PNOR RP
        l_err = PNOR::getSectionInfo( PNOR::HCODE, l_info );
        if( l_err )
        {
            //No need to commit error here, it gets handled later
            //just break out to escape this function
            break;
        }

        o_rHcodeAddr = reinterpret_cast<char*>(l_info.vaddr);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "HCODE addr = 0x%p ",
                   o_rHcodeAddr);

    } while ( 0 );

    return  l_err;
}

void* call_host_load_io_ppe (void *io_pArgs)
{
    errlHndl_t  l_err  =   NULL;
    IStepError  l_stepError;

    char* l_pHcodeImage = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_load_io_ppe entry" );

    do
    {

        l_err = loadHcodeImage(l_pHcodeImage);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_load_io_ppe ERROR : "
                  "Unable to load HCODE image errorlog PLID=0x%x",
                  l_err->plid());

            l_stepError.addErrorDetails(l_err);
            errlCommit( l_err, ISTEP_COMP_ID );
            break;
        }

        // Get all OBUS targets
        TARGETING::TargetHandleList l_obusTargetList;
        getAllChiplets(l_obusTargetList, TYPE_OBUS);
        // Get all PROC targets for XBUS
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);

        // Loop through OBUS
        for (const auto & l_obusTarget: l_obusTargetList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_OBUS>
                l_obusFapi2Target(
                (const_cast<TARGETING::Target*>(l_obusTarget)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Running p9_io_obus_image_build HWP on "
                     "OBUS target %.8X",
                       TARGETING::get_huid(l_obusTarget));

            FAPI_INVOKE_HWP( l_err,
                      p9_io_obus_image_build,
                      l_obusFapi2Target,
                      reinterpret_cast<void*>(l_pHcodeImage));

            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         "ERROR 0x%.8X: returned from p9_io_obus_image_build on "
                         "OBUS target %.8X, PLID=0x%x",
                        l_err->reasonCode(),
                        TARGETING::get_huid(l_obusTarget),
                        l_err->plid());

                l_stepError.addErrorDetails(l_err);
                errlCommit(l_err, HWPF_COMP_ID);
            }
        } // end of looping through obus

        // Loop through PROC (for XBUS)
        for (const auto & l_procTarget: l_procTargetList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_procFapi2Target(
                (const_cast<TARGETING::Target*>(l_procTarget)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Running p9_io_xbus_image_build HWP on "
                     "XBUS target %.8X",
                       TARGETING::get_huid(l_procTarget));

            FAPI_INVOKE_HWP( l_err,
                      p9_io_xbus_image_build,
                      l_procFapi2Target,
                      reinterpret_cast<void*>(l_pHcodeImage));

            if(l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         "ERROR 0x%.8X: returned from p9_io_xbus_image_build on "
                         "XBUS target %.8X, PLID=0x%x",
                        l_err->reasonCode(),
                        TARGETING::get_huid(l_procTarget),
                        l_err->plid());

                l_stepError.addErrorDetails(l_err);
                errlCommit(l_err, HWPF_COMP_ID);
            }
        } // end of looping through xbus
    } while( 0 );

#ifdef CONFIG_SECUREBOOT
    l_err = unloadSecureSection(PNOR::HCODE);
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   ERR_MRK"host_load_io_ppe() - Error from "
                   "unloadSecureSection(PNOR::HCODE)");

        l_stepError.addErrorDetails( l_err );
        errlCommit( l_err, ISTEP_COMP_ID );
    }
#endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_load_io_ppe exit ");

    return l_stepError.getErrorHandle();
}


};
