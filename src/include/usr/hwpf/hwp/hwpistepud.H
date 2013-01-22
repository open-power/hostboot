/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/hwpistepud.H $                       */
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
 *  Defines the HwpUserDetailsIstep class that adds IStep FFDC to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>

namespace   ISTEP_ERROR
{

    /**
     * @struct HwpUserDetailsIstepErrorData
     *
     * Defines the user detail data
     */
    struct HwpUserDetailsIstepErrorData
    {
        uint32_t eid;
        uint32_t reasoncode;
    };

    /**
     * @class HwpUserDetailsIstep
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
}

#endif

