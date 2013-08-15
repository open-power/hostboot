/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCenMembuf.C $          */
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

/** @file  prdfPlatCenMembuf.C
 *  @brief Contains all Hostboot specific plugin code for the PRD Centaur.
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>

// Pegasus includes
#include <prdfCalloutUtil.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Membuf
{

// There are several plugins that will be defined but are not expected during
// Hostboot.
#define PLUGIN_UNEXPECTED_ATTN( FUNC ) \
int32_t FUNC( ExtensibleChip * i_membChip, STEP_CODE_DATA_STRUCT & i_sc ) \
{ \
    PRDF_ERR( "["#FUNC"] Unexpected attention in Hostboot: HUID=0x%08x", \
              i_membChip->GetId() ); \
    CalloutUtil::defaultError( i_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( Membuf, FUNC );

//##############################################################################
//
//                               MBSECCFIRs
//
//##############################################################################

// MBSECCFIR[20-27]

#define PLUGIN_MAINT_MPE_ERROR( MBA, RANK ) \
    PLUGIN_UNEXPECTED_ATTN( AnalyzeMaintMpe##MBA##_##RANK )

PLUGIN_MAINT_MPE_ERROR( 0, 0 )
PLUGIN_MAINT_MPE_ERROR( 0, 1 )
PLUGIN_MAINT_MPE_ERROR( 0, 2 )
PLUGIN_MAINT_MPE_ERROR( 0, 3 )
PLUGIN_MAINT_MPE_ERROR( 0, 4 )
PLUGIN_MAINT_MPE_ERROR( 0, 5 )
PLUGIN_MAINT_MPE_ERROR( 0, 6 )
PLUGIN_MAINT_MPE_ERROR( 0, 7 )

PLUGIN_MAINT_MPE_ERROR( 1, 0 )
PLUGIN_MAINT_MPE_ERROR( 1, 1 )
PLUGIN_MAINT_MPE_ERROR( 1, 2 )
PLUGIN_MAINT_MPE_ERROR( 1, 3 )
PLUGIN_MAINT_MPE_ERROR( 1, 4 )
PLUGIN_MAINT_MPE_ERROR( 1, 5 )
PLUGIN_MAINT_MPE_ERROR( 1, 6 )
PLUGIN_MAINT_MPE_ERROR( 1, 7 )

#undef PLUGIN_MAINT_MPE_ERROR

// MBSECCFIR[39,41]

#define PLUGIN_MAINT_UE_ERROR( MBA ) \
    PLUGIN_UNEXPECTED_ATTN( AnalyzeMaintUe##MBA )

PLUGIN_MAINT_UE_ERROR( 0 )
PLUGIN_MAINT_UE_ERROR( 1 )

#undef PLUGIN_MAINT_UE_ERROR

//------------------------------------------------------------------------------

#undef PLUGIN_UNEXPECTED_ATTN

} // end namespace Membuf

} // end namespace PRDF

