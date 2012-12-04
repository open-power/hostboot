/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hostbootIstep.C $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
/**
 *  @file hostbootIstep.C
 *
 *  @brief hostboot istep-called functions
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwas_reasoncodes.H>

#include <hwas/hostbootIstep.H>
#include <hwas/common/deconfigGard.H>

#include <fsi/fsiif.H>
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>

#include <targeting/attrsync.H>

namespace HWAS
{

// functions called from the istep dispatcher -- hostboot only

//******************************************************************************
// host_init_fsi function
//******************************************************************************
void* host_init_fsi( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi entry" );

    errlHndl_t errl = FSI::initializeHardware( );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi exit" );

    return errl;
}

//******************************************************************************
// host_set_ipl_parms function
//******************************************************************************
void* host_set_ipl_parms( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms entry" );
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms exit" );

    return errl;
}

//******************************************************************************
// host_discover_targets function
//******************************************************************************
void* host_discover_targets( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_discover_targets entry" );

    errlHndl_t errl = NULL;

    // Check whether we're in MPIPL mode
    using namespace TARGETING;
    Target* l_pTopLevel = NULL;
    uint8_t l_attrIsMpipl = 0;

    TargetService& l_targetService = targetService();
    l_targetService.getTopLevelTarget( l_pTopLevel );

    if( l_pTopLevel == NULL )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Top level handle was NULL" );

        /*@
         * @errortype
         * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid     HWAS::MOD_HOST_DISCOVER_TARGETS
         * @reasoncode   HWAS::RC_TOP_LEVEL_TARGET_NULL
         * @devdesc      Call to get top level targeting handle
         *               returned NULL
         */
        errl =  hwasError( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           HWAS::MOD_HOST_DISCOVER_TARGETS,
                           HWAS::RC_TOP_LEVEL_TARGET_NULL );
    }
    else
    {
        l_attrIsMpipl = l_pTopLevel->getAttr<ATTR_IS_MPIPL_HB> ();
        
        if (l_attrIsMpipl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "MPIPL mode" );

            // Sync attributes from Fsp
            errl = syncAllAttributesFromFsp();
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Normal IPL mode" );

            errl = discoverTargets();
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_discover_targets exit" );

    return errl;
}

//******************************************************************************
// host_gard function
//******************************************************************************
void* host_gard( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard entry" );

    errlHndl_t errl = collectGard();

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard exit" );

    return errl;
}

//******************************************************************************
// host_cancontinue_clear function
//******************************************************************************
void* host_cancontinue_clear( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_cancontinue_clear entry" );
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_cancontinue_clear exit" );

    return errl;
}

//******************************************************************************
// host_prd_hwreconfig function
//******************************************************************************
void* host_prd_hwreconfig( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_prd_hwreconfig entry" );

    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_prd_hwreconfig exit" );

    return errl;
}

//******************************************************************************
// host_stub function
//******************************************************************************
void* host_stub( void *io_pArgs )
{
    errlHndl_t errl = NULL;
    // no function required
    return errl;
}

} // namespace HWAS
