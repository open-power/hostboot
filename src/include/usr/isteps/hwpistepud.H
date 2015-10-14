/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/hwpistepud.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

