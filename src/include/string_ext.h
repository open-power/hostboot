/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/string_ext.h $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __STRING_EXT_H
#define __STRING_EXT_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Converts lowercase string to uppercase
 *
 * Any characters that cannot be converted are left unchanged
 *
 * @param[in] s Pointer to c-string that is converted to uppercase
 * @return char *. Pointer to beginning of string (same as 's' parameter)
 */
char* strupr(char* s);

#ifdef __cplusplus
};
#endif

#endif
