/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/tools/dce/dce-extra-files/trace_defs.h++ $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

#include <console/consoleif.H>

#define CONSOLE_TRACE(args...) CONSOLE::displayf(CONSOLE::DEFAULT, NULL, args)

#undef TRACFCOMP
#define TRACFCOMP(X, args...) CONSOLE_TRACE(args)

#undef TS_INFO
#define TS_INFO(args...) CONSOLE_TRACE(args)

#undef TS_FAIL
#define TS_FAIL(args...) CONSOLE_TRACE(args)

#undef FAPI_INF
#define FAPI_INF(args...) CONSOLE_TRACE(args)

#undef FAPI_ERR
#define FAPI_ERR(args...) CONSOLE_TRACE("ERROR!! " args)

#undef FAPI_DBG
#define FAPI_DBG(args...) CONSOLE_TRACE(args)

#endif
