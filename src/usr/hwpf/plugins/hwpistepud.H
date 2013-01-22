/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plugins/hwpistepud.H $                           */
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
 *  Defines the HwpUserDetailsParserIstep class that parses
 *  IStep FFDC user detail in an error log
 */

#include "errluserdetails.H"

namespace   ISTEP_ERROR
{
    /**
     * @struct IStepUserDetailsIstepData
     *
     * Defines the user detail data
     */
    struct HwpUserDetailsIstepErrorData
    {
        uint32_t eid;
        uint32_t reasoncode;
    };

    /**
     * @class HwpUserDetailsParserIstep
     *
     * Parses Istep user detail in an error log
     */
    class HwpUserDetailsParserIstep : public ERRORLOG::ErrlUserDetailsParser
    {
        public:
            /**
             *  @brief Constructor
             */
            HwpUserDetailsParserIstep() {}

            /**
             *  @brief Destructor
             */
            virtual ~HwpUserDetailsParserIstep() {}

            /**
             *  @brief Parses Istep user detail data from an error log
             *
             *  @param  i_version Version of the data
             *  @param  i_parse   ErrlUsrParser object for outputting
             *                    information
             *  @param  i_pBuffer Pointer to buffer containing detail data
             *  @param  i_buflen  Length of the buffer
             */
            virtual void parse(errlver_t i_version,
                    ErrlUsrParser & i_parser,
                    void * i_pBuffer,
                    const uint32_t i_buflen) const
            {
                HwpUserDetailsIstepErrorData * l_pData =
                    static_cast<HwpUserDetailsIstepErrorData *>(i_pBuffer);

                i_parser.PrintNumber("See error log ID:","0x%X",
                                     ntohl(l_pData->eid));

                i_parser.PrintNumber("Reasoncode:","0x%X",
                                      ntohl(l_pData->reasoncode) );
            }

        private:
            // Disabled
            HwpUserDetailsParserIstep(const HwpUserDetailsParserIstep &);
            HwpUserDetailsParserIstep & operator=(
                    const HwpUserDetailsParserIstep &);
    };
}

#endif

