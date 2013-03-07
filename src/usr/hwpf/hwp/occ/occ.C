/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include    <stdint.h>

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <devicefw/userif.H>
#include    <sys/misc.h>
#include    <sys/mm.h>
#include    <vmmconst.h>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/plat/fapiPlatTrace.H>
#include    <hwpf/hwpf_reasoncodes.H>

// Procedures
#include <p8_pba_init.H>
#include <p8_occ_control.H>
#include <p8_pba_bar_config.H>
#include <p8_pm_init.H>
#include <p8_pm_firinit.H>

extern trace_desc_t* g_fapiTd;

namespace OCC
{

    errlHndl_t loadOCCImageToHomer(uint64_t i_homer_addr )
    {
        errlHndl_t  l_errl  =   NULL;

        do {
            //RTC: 51076 - Implement DMA message passing to
            //  get OCC image from FSP.

        }while(0);

        return l_errl;
    }

    errlHndl_t loadnStartOcc(uint64_t i_homer_addr,
                             uint64_t i_common_addr,
                             TARGETING::Target* i_target)
    {
        errlHndl_t  l_errl  =   NULL;

        TRACDCOMP( g_fapiTd,
                   "loadnStartOcc entry" );


        do {

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapiTarg(fapi::TARGET_TYPE_PROC_CHIP,
                                          (const_cast<TARGETING::Target*>(i_target)));


            //==============================
            //Setup for OCC Load
            //==============================

            //TODO: put this const in the common location with HOMER struct
            //RTC: 50987
            // BAR0 is the Entire HOMER (start of HOMER contains OCC base Image)
            // Bar size is in MB, obtained value of 4MB from Greg Still
            const uint32_t bar0_size_MB = 4;
            FAPI_INVOKE_HWP( l_errl,
                             p8_pba_bar_config,
                             l_fapiTarg,
                             0, i_homer_addr, bar0_size_MB,
                             PBA_CMD_SCOPE_NODAL );

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"Bar0 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            //TODO: put this const in the common location with HOMER struct
            //RTC: 50987
            // BAR3 is the OCC Common Area
            // Bar size is in MB, obtained value of 8MB from Tim Hallett
            const uint32_t bar3_size_MB = 8;
            FAPI_INVOKE_HWP( l_errl,
                             p8_pba_bar_config,
                             l_fapiTarg,
                             3, i_common_addr, bar3_size_MB,
                             PBA_CMD_SCOPE_NODAL );

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"Bar3 config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            //TODO: This flow needs to be updated along with procedure refresh
            //RTC: 68461
            // Config path
            // p8_pm_init.C enum: PM_CONFIG
            FAPI_INVOKE_HWP( l_errl,
                             p8_pm_init,
                             l_fapiTarg,
                             PM_CONFIG );

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"p8_pm_init, config failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            // Init path
            // p8_pm_init.C enum: PM_INIT
            FAPI_INVOKE_HWP( l_errl,
                             p8_pm_init,
                             l_fapiTarg,
                             PM_INIT );

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"p8_pm_init, init failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }
            TRACFCOMP( g_fapiImpTd,
                       INFO_MRK"OCC Finished: p8_pm_init.C enum: PM_INIT" );

            // Firinit       
            // p8_pm_firinit.C
            FAPI_INVOKE_HWP( l_errl,
                             p8_pm_firinit,
                             l_fapiTarg );
            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"p8_pm_firinit, failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            //==============================
            //Load the OCC HOMER image
            //==============================
            l_errl = loadOCCImageToHomer( i_homer_addr );
            if( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd, ERR_MRK"loading images failed!" );
                break;
            }

            //TODO RTC:50987 - Fill in OCC data areas in HOMER.  See Story
            //  49595 for details.

            //==============================
            //Start the OCC image
            //==============================
            FAPI_INVOKE_HWP( l_errl,
                             p8_occ_control,
                             l_fapiTarg,
                             PPC405_RESET_OFF,
                             PPC405_BOOT_MEM );

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                           ERR_MRK"occ_control failed!" );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

        } while(0);

        TRACDCOMP( g_fapiTd,
                   "loadnStartOcc Exit" );

        return l_errl;
    }

}  //end OCC namespace
