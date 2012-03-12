//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/initservice/initsvcudistep.H $
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
#ifndef INITSVC_UDSTEP_H
#define INITSVC_UDSTEP_H

/**
 *  @file initsvcudistep.H
 *
 *  Defines the following classes:
 *
 *  InitSvcUserDetailsIstep: Adds IStep FFDC to an error log as user detail data
 *  InitSvcUserDetailsParserIstep: Parses IStep FFDC user detail in an error log
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

#ifndef PARSER

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

#else // (if PARSER defined)

/**
 * @class InitSvcUserDetailsParserIstep
 *
 * Parses Istep user detail in an error log
*/
class InitSvcUserDetailsParserIstep : public ERRORLOG::ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    InitSvcUserDetailsParserIstep() {}

    /**
     *  @brief Destructor
     */
    virtual ~InitSvcUserDetailsParserIstep() {}

    /**
     *  @brief Parses Istep user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        InitSvcUserDetailsIstepData * l_pData =
            static_cast<InitSvcUserDetailsIstepData *>(i_pBuffer);

        i_parser.PrintString("IStep name", l_pData->iv_pIstepname);
        i_parser.PrintNumber("Step", "%d", ntohs(l_pData->iv_step));
        i_parser.PrintNumber("Sub-step", "%d", ntohs(l_pData->iv_substep));
    }

private:
    // Disabled
    InitSvcUserDetailsParserIstep(const InitSvcUserDetailsParserIstep &);
    InitSvcUserDetailsParserIstep & operator=(
        const InitSvcUserDetailsParserIstep &);
};

#endif

}

#endif

