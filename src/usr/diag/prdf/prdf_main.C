//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/prdf/prdf_main.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END


/**
 * @file prdf_main.C
 * @brief PRD entry points
 */

#define iipMain_C

#include <prdf_proto.H>
#include <iipglobl.h>
#include <iipconst.h>
#include <targeting/common/targetservice.H>

#undef iipMain_C


namespace PRDF
{

//------------------------------------------------------------------------------
// Global Variables
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

void prdf_unInitialize(void)
{
    PRDF_ENTER( "prdf_unInitialize()" );
    // FIXME
    PRDF_EXIT( "prdf_unInitialize()" );
}

//------------------------------------------------------------------------------
errlHndl_t PrdInitialize()
{
    PRDF_ENTER( "PrdInitialize()" );

    // FIXME

    PRDF_EXIT( "PrdInitialize()" );

    return NULL;
}




// ----------------------------------------------------------------------------
errlHndl_t PrdMain(ATTENTION_VALUE_TYPE i_attentionType, const AttnList & i_attnList)
{
    PRDF_ENTER( "PrdMain() Global attnType=%04X", i_attentionType );
    using namespace TARGETING;

    // FIXME

    // FIXME: will need to figure out a better way to trace Target Handles/EntityPath here
    //        This is temporary for initial debugging purose and will be removed or change
    //        to debug traces only
    for(uint32_t i=0; i<i_attnList.size(); ++i)
    {
        TargetHandle_t l_target = i_attnList[i].targetHndl;
        EntityPath l_path = l_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump(); //this will binary trace the entity path

        PRDF_INF( "PrdMain() attnType: %X, HUID: %X", i_attnList[i].attnType, l_target->getAttr<ATTR_HUID>());

    }





    PRDF_EXIT( "PrdMain()" );

    return NULL;
}


//------------------------------------------------------------------------------
errlHndl_t PrdStartScrub(const TARGETING::TargetHandle_t i_pTarget)
{
    PRDF_ENTER( "PrdStartScrub()" );
    // FIXME
    PRDF_EXIT( "PrdStartScrub()" );

    return NULL;
}

//------------------------------------------------------------------------------
int32_t prdfRestoreDramRepairs(const TARGETING::TargetHandle_t i_pTarget)
{
    PRDF_ENTER( "prdfRestoreDramRepairs()" );
    // FIXME
    PRDF_EXIT( "prdfRestoreDramRepairs()" );

    return SUCCESS;
}

//------------------------------------------------------------------------------
void PrdIplCleanup()
{
    PRDF_ENTER( "PrdIplCleanup()" );
    // FIXME
    PRDF_EXIT( "PrdIplCleanup()" );

    return;
}



#ifndef __HOSTBOOT_MODULE

//------------------------------------------------------------------------------
errlHndl_t prdfFailoverComplete(void)
{
    PRDF_ENTER( "prdfFailoverComplete()" );

    // FIXME

    PRDF_EXIT( "prdfFailoverComplete()" );

    return NULL;
}

#endif


} // End namespace PRDF
