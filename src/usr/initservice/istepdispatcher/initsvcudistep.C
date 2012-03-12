//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/initsvcudistep.C $
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
 *  @file initsvcudistep.C
 *
 *  @brief Implementation of InitSvcUserDetailsIstep
 */
#include <initservice/initsvcudistep.H>
#include <initservice/initsvcreasoncodes.H>

namespace   INITSERVICE
{

//------------------------------------------------------------------------------
InitSvcUserDetailsIstep::InitSvcUserDetailsIstep(
    const char * i_pIstepname,
    const uint16_t i_step,
    const uint16_t i_substep)
{
    InitSvcUserDetailsIstepData * l_pBuf =
        reinterpret_cast<InitSvcUserDetailsIstepData *>(
            reallocUsrBuf(sizeof(InitSvcUserDetailsIstepData) +
                          (strlen(i_pIstepname) + 1)));

    l_pBuf->iv_step = i_step;
    l_pBuf->iv_substep = i_substep;
    strcpy(l_pBuf->iv_pIstepname, i_pIstepname);

    // Set up ErrlUserDetails instance variables
    iv_CompId = INITSVC_COMP_ID;
    iv_Version = 1;
    iv_SubSection = INIT_SVC_UDT_ISTEP;
}

//------------------------------------------------------------------------------
InitSvcUserDetailsIstep::~InitSvcUserDetailsIstep()
{

}

}

