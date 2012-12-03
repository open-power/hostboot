/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwas/hostbootIstep.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file hostbootIstep.C
 *
 *  @brief hostboot istep-called functions
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>

#include <hwas/hostbootIstep.H>
#include <hwas/common/deconfigGard.H>

#include <fsi/fsiif.H>
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>

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

    errlHndl_t errl = discoverTargets();

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
