/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/tools/dce/dce-extra-files/trace_defs.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
#ifndef TRACE_DEFS_H
#define TRACE_DEFS_H

/* @file trace_defs.H
 *
 *  The purpose of this file is to override the TRACFCOMP macro and redirect it to the console output for DCE. That way
 *  users of DCE can get traces for their DCE scripts. Typically, only TRACFCOMP should need to be redirected but there
 *  may be cases where trace macros need to be overridden, such as TRACDCOMP. They can be added here as well as needed.
 */

#include <console/consoleif.H>

#define CONSOLE_TRACE(args...) CONSOLE::displayf(CONSOLE::DEFAULT, NULL, args)

#undef TRACFCOMP
#define TRACFCOMP(X, args...) CONSOLE_TRACE(args)

#endif
