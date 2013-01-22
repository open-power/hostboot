/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/initsvcudistep.H $                */
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
#ifndef INITSVC_UDSTEP_H
#define INITSVC_UDSTEP_H

/**
 *  @file initsvcudistep.H
 *
 *  Defines the InitSvcUserDetailsIstep class that adds IStep FFDC to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>

namespace   INITSERVICE
{

/**
 * @struct InitSvcUserDetailsIstepData
 *
 * Defines the user detail data
 */
struct InitSvcUserDetailsIstepData
{
    uint16_t iv_step;
    uint16_t iv_substep;
    char iv_pIstepname[0];
};

/**
 * @class InitSvcUserDetailsIstep
 *
 * Adds IStep FFDC to an error log as user detail data
 */
class InitSvcUserDetailsIstep : public ERRORLOG::ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *
     *  Captures the supplied IStep FFDC data internally
     *
     *  @param i_pIstepname Istep name
     *  @param i_step       Step number
     *  @param i_substep    Sub-step number
     */
    InitSvcUserDetailsIstep(const char * i_pIstepname,
                            const uint16_t i_step,
                            const uint16_t i_substep);

    /**
     *  @brief Destructor
     */
    virtual ~InitSvcUserDetailsIstep();

private:
    // Disabled
    InitSvcUserDetailsIstep(const InitSvcUserDetailsIstep &);
    InitSvcUserDetailsIstep & operator=(const InitSvcUserDetailsIstep &);
};

}

#endif

