/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/ffdc/ffdc_includes.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
///
/// @file ffdc_includes.H
/// @brief Main file used to export all include files for FFDC procedures
///

#ifndef __FFDC_INCLUDES_H
#define __FFDC_INCLUDES_H

// Add any other FFDC procedures with #include

// Don't do explorer log collection on FSP side
#ifndef FIPSODE

    // needed for collectFfdc to work for adding Explorer log data
    #include <exp_collect_explorer_active_log.H>
    #include <exp_collect_explorer_saved_A_log.H>
    #include <exp_collect_explorer_saved_B_log.H>

#endif

#endif
