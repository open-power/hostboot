/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/plugins/initsvcudistep.H $                */
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
 *  Defines the InitSvcUserDetailsParserIstep class that parses
 *  IStep FFDC user detail in an error log
 */

#include "errluserdetails.H"

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

}

#endif

