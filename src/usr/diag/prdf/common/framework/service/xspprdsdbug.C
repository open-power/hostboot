/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/xspprdsdbug.C $    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2000,2013              */
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
#include <utilreg.H>

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

#undef xspprdsdbug_C

namespace PRDF
{

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
uint32_t * g_src = NULL;

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

SYSTEM_DEBUG_CLASS::SYSTEM_DEBUG_CLASS(void)
{
}

uint32_t SYSTEM_DEBUG_CLASS::Reinitialize(const AttnList & i_attnList)
{
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
             * @devdesc input AttnList is empty.
             * @procedure EPUB_PRC_SP_CODE
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

            PRDF_ADD_PROCEDURE_CALLOUT( g_prd_errlHndl, SRCI_PRIORITY_MED,
                                        EPUB_PRC_SP_CODE );
            l_rc = PRD_ATTN_DATA_ACCESS_FAILED;

            break;
        }

        g_AttnDataList = i_attnList;

        g_init_done = true;

    } while(0);

    return l_rc;
}

// --------------------------------------------------------------------

bool SYSTEM_DEBUG_CLASS::IsAttentionActive( TARGETING::TargetHandle_t i_pChipHandle ) const
{
    bool rc = false;

    for(AttnList::const_iterator i = g_AttnDataList.begin(); i != g_AttnDataList.end(); ++i)
    {
        if((*i).targetHndl == i_pChipHandle)
        {
            rc = true;
            break;
        }
    }
    return rc;
}

void SYSTEM_DEBUG_CLASS::Clear(void)
{
    g_AttnDataList.clear();
}

// -------------------------------------------------------------------

uint8_t SYSTEM_DEBUG_CLASS::GetAttentionType(TARGETING::TargetHandle_t i_pChipHandle) const
{
    uint8_t type = INVALID_ATTENTION_TYPE;

    for(AttnList::const_iterator i = g_AttnDataList.begin(); i != g_AttnDataList.end(); ++i)
    {
        if((*i).targetHndl == i_pChipHandle)
        {
            type = (uint8_t) (*i).attnType;
            break;
        }
    }

    return (uint8_t) type;
}


// -------------------------------------------------------------------

void SYSTEM_DEBUG_CLASS::SetPrdSrcPointer()
{
    g_src = NULL;
}

void SYSTEM_DEBUG_CLASS::SetPrdSrcPointer(uint32_t* src_ptr)
{
    g_src = src_ptr;
}

// -------------------------------------------------------------------

void SYSTEM_DEBUG_CLASS::CalloutThoseAtAttention(STEP_CODE_DATA_STRUCT & serviceData) const
{
    ServiceDataCollector * sdc = serviceData.service_data;

    CaptureData & capture = sdc->GetCaptureData();

    for(AttnList::const_iterator i = g_AttnDataList.begin(); i != g_AttnDataList.end(); ++i)
    {
        sdc->SetCallout((*i).targetHndl);
        AttnData ad(*i);
        BitString cbs(sizeof(AttnData)*8,(CPU_WORD *)&ad);

        capture.Add(PlatServices::getSystemTarget(),0,cbs);
    }

    sdc->SetCallout(NextLevelSupport_ENUM);

}

// --------------------------------------------------------------------
// SIMULATION SUPPORT for setting up sysdbug
// --------------------------------------------------------------------
const uint32_t *SYSTEM_DEBUG_CLASS::GetPrdSrcPointer(void) const
{
    return g_src;
}

void SYSTEM_DEBUG_CLASS::SetAttentionType(TARGETING::TargetHandle_t i_pTargetHandle,
                                          ATTENTION_VALUE_TYPE i_eAttnType)
{
    if(i_eAttnType  > INVALID_ATTENTION_TYPE)
    {
        if(!IsAttentionActive(i_pTargetHandle))
        {
            AttnData attnData;
            attnData.targetHndl = i_pTargetHandle;
            attnData.attnType = i_eAttnType;
            g_AttnDataList.push_back(attnData);
        }
    }
}

} // end namespace PRDF
