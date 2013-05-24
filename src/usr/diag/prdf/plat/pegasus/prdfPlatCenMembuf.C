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

// MBSECCFIR[0-7,16,17,19,20-27,39,41]

#define PLUGIN_MEMORY_ECC_ERROR( TYPE, ECC, POS ) \
    PLUGIN_UNEXPECTED_ATTN( Analyze##TYPE##ECC##POS )

PLUGIN_MEMORY_ECC_ERROR( Fetch, Mpe, 0 )
PLUGIN_MEMORY_ECC_ERROR( Fetch, Mpe, 1 )
PLUGIN_MEMORY_ECC_ERROR( Fetch, Nce, 0 )
PLUGIN_MEMORY_ECC_ERROR( Fetch, Nce, 1 )
PLUGIN_MEMORY_ECC_ERROR( Fetch, Rce, 0 )
PLUGIN_MEMORY_ECC_ERROR( Fetch, Rce, 1 )
PLUGIN_MEMORY_ECC_ERROR( Fetch, Ue,  0 )
PLUGIN_MEMORY_ECC_ERROR( Fetch, Ue,  1 )

PLUGIN_MEMORY_ECC_ERROR( Maint, Mpe, 0 )
PLUGIN_MEMORY_ECC_ERROR( Maint, Mpe, 1 )
PLUGIN_MEMORY_ECC_ERROR( Maint, Ue,  0 )
PLUGIN_MEMORY_ECC_ERROR( Maint, Ue,  1 )

#undef PLUGIN_MEMORY_ECC_ERROR

//------------------------------------------------------------------------------

#undef PLUGIN_UNEXPECTED_ATTN

} // end namespace Membuf

} // end namespace PRDF

