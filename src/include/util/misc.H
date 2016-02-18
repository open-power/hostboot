/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/misc.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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

#ifdef HOSTBOOT_MEMORY_LEAKS
    /**
     * @brief Enables collection of memory leak info in a simics environment
     *
     * @param[in] void
     *
     * @return void
     */
    void simicsMemLeakEnable( void );

    /**
     * @brief Disables collection of memory leak info in a simics environment
     *
     * @param[in] void
     *
     * @return void
     */
    void simicsMemLeakDisable( void );
#endif
};

#endif

