/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/xspprdsdbug.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

// Module Description **************************************************
//
// Description: definition of iipsdbug.h (SYSTEM_DEBUG_CLASS) for regatta
//              PRD wrapper of sysdebug
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define xspprdsdbug_C

#ifndef __HOSTBOOT_MODULE

#include <fcntl.h>     // for O_RDONLY O_WRONLY etc..
#include <unistd.h>    // for ::read()  ::write()

#endif

#include <string.h>    // for memcpy

#include <errlentry.H>

#include <prdfMain.H>
#include <iipstep.h>
#include <iipServiceDataCollector.h>
#include <iipsdbug.h>
#include <prdfGlobal.H>
#include <prdf_service_codes.H>
#include <prdfBitString.H>
#include <prdfPlatServices.H>
#include <prdfErrlUtil.H>
#include <prdfRuleChip.H>
#include <iipSystem.h>
#include <prdfPluginDef.H>
#include <algorithm>
#include <UtilHash.H>

#undef xspprdsdbug_C

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;
//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

AttnList g_AttnDataList;
bool g_init_done = false;
uint32_t * g_src = nullptr;

//---------------------------------------------------------------------

bool findAttention( TARGETING::TargetHandle_t i_chipTgt,
                    ATTENTION_VALUE_TYPE i_eAttnType,
                    AttnList::iterator & it )
{
    bool matchFound = false;

    AttnData l_attnData( i_chipTgt, i_eAttnType );
    it = std::lower_bound( g_AttnDataList.begin(),
                           g_AttnDataList.end(),
                           l_attnData );

    if( it != g_AttnDataList.end() && *it == l_attnData )
    {
        matchFound = true;
    }

    return matchFound;
}

//---------------------------------------------------------------------

bool findTarget( TARGETING::TargetHandle_t i_chipTgt,
                 AttnList::iterator & it )
{
    bool matchFound = false;
    it = std::lower_bound(  g_AttnDataList.begin(), g_AttnDataList.end(),
                            i_chipTgt );

    if( it != g_AttnDataList.end() && i_chipTgt == (*it).targetHndl )
    {
        matchFound = true;
    }

    return matchFound;
}

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

SYSTEM_DEBUG_CLASS::SYSTEM_DEBUG_CLASS(void)
{
}

uint32_t SYSTEM_DEBUG_CLASS::Reinitialize(const AttnList & i_attnList)
{
    using PluginDef::bindParm;
    uint32_t l_rc = 0;

    do
    {
        if ( i_attnList.empty() )
        {
            PRDF_ERR( "SYSTEM_DEBUG_CLASS::Reinitialize() input AttnList is "
                      "empty" );
            /*@
             * @errortype
             * @subsys     EPUB_FIRMWARE_SP
             * @reasoncode PRDF_CODE_FAIL
             * @moduleid   PRDF_SDBUG_INIT
             * @userdata1  0
             * @userdata2  0
             * @userdata3  0
             * @userdata4  0
             * @devdesc    input AttnList is empty.
             * @custDesc   Chip diagnosis did not find any chip with an
             *             attention.
             * @procedure  EPUB_PRC_SP_CODE
             */
            PRDF_CREATE_ERRL( g_prd_errlHndl,
                              ERRL_SEV_UNRECOVERABLE, // error on diagnostic
                              ERRL_ETYPE_NOT_APPLICABLE,
                              SRCI_MACH_CHECK,
                              SRCI_NO_ATTR,
                              PRDF_SDBUG_INIT,                 // module id
                              FSP_DEFAULT_REFCODE,
                              PRDF_CODE_FAIL,             // Reason code
                              0,                          // user data word 1
                              0,                          // user data word 2
                              0,                          // user data word 3
                              0 );                        // user data word 4

            PRDF_ADD_PROCEDURE_CALLOUT( g_prd_errlHndl, MRU_MED, SP_CODE );
            l_rc = PRD_ATTN_DATA_ACCESS_FAILED;

            break;
        }

        Clear();
        for( AttnList::const_iterator i = i_attnList.begin();
             i != i_attnList.end(); ++i )
        {
            addChipToAttnList( (*i).targetHndl,(*i).attnType );

            // We can have UNIT CHKSTOPs present along with a normal
            // CheckStop.  We want to be sure we look at the UnitCs
            // in this case as it may be the real issue -- example is
            // OPAL forcing a checkstop since a Unit CS occurs which
            // they can't handle.
            if  ( (*i).attnType == CHECK_STOP )
            {
                bool l_ucsFound = false;
                ExtensibleChip * l_chip =
                    ( ExtensibleChip *) systemPtr->GetChip( (*i).targetHndl );
                ExtensibleChipFunction * ef
                           = l_chip->getExtensibleFunction("CheckForUnitCs");

                (*ef)( l_chip, bindParm<bool &>( l_ucsFound ) );

                if ( l_ucsFound )
                {
                    addChipToAttnList( (*i).targetHndl,UNIT_CS );
                }
            }

            // There can be a case where chip has both recoverable and Check
            // Stop. In that case chip shall report only Check Stop. In such a
            // case, we analyse the recoverable first and see if we can blame
            // check stop on recoverable. To ease its handling, let us add a
            // chip reporting recoverable attention to attention list.

            if( ((*i).attnType == CHECK_STOP ) || ((*i).attnType == UNIT_CS ) )
            {
                bool l_recovFound = false;
                ExtensibleChip * l_chip =
                    ( ExtensibleChip *) systemPtr->GetChip( (*i).targetHndl );
                ExtensibleChipFunction * ef
                           = l_chip->getExtensibleFunction("CheckForRecovered");

                (*ef)( l_chip, bindParm<bool &>( l_recovFound ) );

                if ( l_recovFound )
                {
                    addChipToAttnList( (*i).targetHndl,RECOVERABLE );
                }
            }
        }

        g_init_done = true;

    } while(0);

    return l_rc;
}

// --------------------------------------------------------------------

bool SYSTEM_DEBUG_CLASS::isActiveAttentionPending(
                                    TARGETING::TargetHandle_t i_chipTrgt,
                                    ATTENTION_TYPE i_attn ) const
{
    bool o_rc = false;
    ATTENTION_VALUE_TYPE attn ;
    //FIXME RTC 118194 shall investigate need for ATTENTION_VALUE_TYPE and
    //ATTENTION_TYPE. If possible one will be removed.
    attn = ( ATTENTION_VALUE_TYPE )i_attn;
    AttnData l_attnData( i_chipTrgt, attn );
    AttnList::iterator it;

    if( findAttention( i_chipTrgt, attn, it ) )
    {
        o_rc = (*it).isAnalysisNotDone;
    }

    return o_rc;
}

// --------------------------------------------------------------------

void SYSTEM_DEBUG_CLASS::Clear(void)
{
    g_AttnDataList.clear();
}

// --------------------------------------------------------------------

TargetHandle_t SYSTEM_DEBUG_CLASS::getTargetWithAttn
                        ( TYPE i_tgtType, ATTENTION_VALUE_TYPE i_attnType) const
{
    TargetHandle_t o_tgt = nullptr;

    for(AttnList::const_iterator i = g_AttnDataList.begin();
                                  i != g_AttnDataList.end(); ++i)
    {
        if(( getTargetType( (*i).targetHndl ) == i_tgtType)
            && ( (*i).attnType == i_attnType ) )
        {
            o_tgt = (*i).targetHndl;
            break;
        }
    }
    return o_tgt;
}

// -------------------------------------------------------------------

uint8_t SYSTEM_DEBUG_CLASS::getPrimaryAttnType( TargetHandle_t i_chipTgt ) const
{
    uint8_t type = INVALID_ATTENTION_TYPE;
    AttnList::iterator it;

    // Attention list is sorted. If a given target say X reports
    // both recoverable and platform check stop, we shall have two entries for
    // X in attention list. Also, following will be the order
    // 1. Entry with Platform CS
    // 2. Entry with Recoverable
    // It's because platform checktop attention has an enum value lower than
    // recoverable attention. When findTarget shall look for target X and an
    // attention type in the attention list, it shall see platform checkstop
    // entry before recoverable one. It's because entry with Platform CS will
    // occupy lower position in the list compared to  entry with Recoverable
    // attention.

    if( findTarget( i_chipTgt, it ) )
    {
        type = (*it).attnType;
    }

    return (uint8_t) type;
}

// -------------------------------------------------------------------

void SYSTEM_DEBUG_CLASS::SetPrdSrcPointer()
{
    g_src = nullptr;
}

void SYSTEM_DEBUG_CLASS::SetPrdSrcPointer(uint32_t* src_ptr)
{
    g_src = src_ptr;
}

// -------------------------------------------------------------------

void SYSTEM_DEBUG_CLASS::CalloutThoseAtAttention(
                                    STEP_CODE_DATA_STRUCT & serviceData ) const
{
    ServiceDataCollector * sdc = serviceData.service_data;

    CaptureData & capture = sdc->GetCaptureData();

    // This routine gets invoked for DD02 and DD23 errors.
    // So both will now callout 2nd level high and additional
    // hardware as low.
    for( AttnList::const_iterator i = g_AttnDataList.begin();
         i != g_AttnDataList.end(); ++i )
    {
        sdc->SetCallout((*i).targetHndl, MRU_LOW, NO_GARD);
        AttnData ad(*i);
        BitString cbs(sizeof(AttnData)*8,(CPU_WORD *)&ad);

        capture.Add( PlatServices::getSystemTarget(),
                     Util::hashString("ATTN_DATA"), cbs );
    }

    sdc->SetCallout(LEVEL2_SUPPORT, MRU_HIGH, NO_GARD);
}

// -------------------------------------------------------------------

void SYSTEM_DEBUG_CLASS::clearAttnPendingStatus(
                                    TARGETING::TargetHandle_t i_chipTgt,
                                    ATTENTION_TYPE i_attnType )
{
    ATTENTION_VALUE_TYPE attn ;
    attn = ( ATTENTION_VALUE_TYPE )i_attnType;
    AttnData l_attn( i_chipTgt, attn );
    AttnList::iterator it;

    if( findAttention( i_chipTgt, attn, it ) )
    {
        (*it).isAnalysisNotDone = false;
    }
}

// -------------------------------------------------------------------

void SYSTEM_DEBUG_CLASS::initAttnPendingtatus( )
{
    for( AttnList::iterator i = g_AttnDataList.begin();
         i != g_AttnDataList.end(); ++i )
    {
        (*i).isAnalysisNotDone  = true;
    }
}

// -------------------------------------------------------------------

void SYSTEM_DEBUG_CLASS::addChipToAttnList(
                            TARGETING::TargetHandle_t i_chipTgt,
                            ATTENTION_VALUE_TYPE i_attnType )
{
    AttnData l_attnData( i_chipTgt, i_attnType );
    g_AttnDataList.insert( std::lower_bound( g_AttnDataList.begin(),
                           g_AttnDataList.end(), l_attnData ), l_attnData );
}


// --------------------------------------------------------------------
// SIMULATION SUPPORT for setting up sysdbug
// --------------------------------------------------------------------
const uint32_t *SYSTEM_DEBUG_CLASS::GetPrdSrcPointer(void) const
{
    return g_src;
}

void SYSTEM_DEBUG_CLASS::setPrimaryAttnType(TARGETING::TargetHandle_t
                                            i_pTargetHandle,
                                            ATTENTION_VALUE_TYPE i_eAttnType)
{
    if(i_eAttnType  > INVALID_ATTENTION_TYPE)
    {
        if( !isActiveAttentionPending( i_pTargetHandle, i_eAttnType ) )
        {
            AttnData attnData( i_pTargetHandle, i_eAttnType );
            g_AttnDataList.insert( std::lower_bound( g_AttnDataList.begin(),
                                                     g_AttnDataList.end(),
                                                     attnData ), attnData );
        }
    }
}

} // end namespace PRDF
