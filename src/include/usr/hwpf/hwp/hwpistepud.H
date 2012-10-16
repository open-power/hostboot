/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/hwpistepud.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
 *  Defines the following classes:
 *
 *  IStepUserDetailsIstep: Adds IStep FFDC to an error log as user detail data
 *  IStepUserDetailsParserIstep: Parses IStep FFDC user detail in an error log
 */

#include <errl/errluserdetails.H>

// user data type for istep error details
static const uint32_t HWP_UDT_STEP_ERROR_DETAILS =    0x01;

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

#ifndef PARSER

    /**
     * @class IStepUserDetailsIstep
     *
     * Adds IStep FFDC to an error log as user detail data
     */
    class HwpUserDetailsIstep : public ERRORLOG::ErrlUserDetails
    {
        public:
            /**
             *  @brief Constructor
             *
             *  Captures the supplied IStep FFDC data internally
             *
             *  @param i_err   error log returned by hardware procdure
             *
             */
            HwpUserDetailsIstep( errlHndl_t i_err);

            HwpUserDetailsIstep( );

            /**
             *  @brief Destructor
             */
            virtual ~HwpUserDetailsIstep();

        private:
            // Disabled
            HwpUserDetailsIstep(const HwpUserDetailsIstep &);
            HwpUserDetailsIstep & operator=(const HwpUserDetailsIstep &);
    };

#else // (if PARSER defined)

    /**
     * @class IStepUserDetailsParserIstep
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
#endif

}

#endif


