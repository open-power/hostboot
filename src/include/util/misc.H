/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/misc.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
#ifndef __UTIL_MISC_H
#define __UTIL_MISC_H


namespace Util
{
    /**
     * @brief Determines if code is running in a simics environment
     *
     * @param[in] void
     *
     * @return bool         true if running in simics; otherwise false
     */
    bool isSimicsRunning( void );

    /**
     * @brief Determines whether the code is running under SIMICS, and if so,
     *   whether the QME model is disabled.  Under that specific condition,
     *   Hostboot must run its secondary core workarounds in istep 16.1 and 16.2
     *   in order to bring the cores up correctly, and the API returns true.
     *   Otherwise, the API returns false.
     *
     * @retval true Slave core workaround required in istep 16.1/16.2
     * @retval false Slave core workaround not required.
     */
    bool requiresSecondaryCoreWorkaround( void );

    /**
     * @brief Determines if Targeting code has been loaded
     *
     * @param[in] void
     *
     * @return bool   true if Targeting is loaded; otherwise false
     */
    bool isTargetingLoaded( void );

    /**
     * @brief Sets global that Targeting code has been loaded
     *        NOTE: this should only be called once by targeting
     *
     * @param[in] void
     *
     * @return N/A
     */
    void setIsTargetingLoaded( void );

    /**
     * @brief Determines if the Console daemon has been started
     *
     * @return bool true if Console daemon has been started; false otherwise
     */
    bool isConsoleStarted();

    /**
     * @brief Sets the global variable to indicate that the Console daemon has
     *        been started. This should only be called once when the console
     *        daemon starts.
     */
    void setIsConsoleStarted();

    /**
     * @brief Checks if multiple processors are supported in the current
     *        session..
     */
    bool isMultiprocSupported();
};

#endif

