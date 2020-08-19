/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plugins/prdrErrlDisplaySupt.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2005,2020                        */
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

#ifndef __PRDRERRLDISPLAYSUPT_H
#define __PRDRERRLDISPLAYSUPT_H

#define __PRDR_PLUGIN_HUID uint32_t
#define __PRDR_PLUGIN_IDTYPE  uint32_t

#define __PRDR_PLUGIN_XY(X,Y,Z) X##Y##_##Z
#define __PRDR_PLUGIN_MAKENAME(X,Y,Z) __PRDR_PLUGIN_XY(X,Y,Z)

#ifndef PRDR_ERROR_SIGNATURE_TABLE_START
    #define PRDR_ERROR_SIGNATURE_TABLE_START( homtype, offset) \
        namespace PRDF \
        {\
        namespace HOSTBOOT \
        { \
        class __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset)\
        { \
            public: \
                __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, \
                                       homtype, offset)(); \
            private: \
                struct __table_struct \
                { \
                    uint32_t         signature; \
                    const char *          name; \
                    const char *         brief; \
                }; \
                static __table_struct cv_table[]; \
        }; \
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset) \
           __PRDR_PLUGIN_MAKENAME(g_PrdrPlugin_errTable_Reg_, homtype, offset);\
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset)::\
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset)() \
        { \
            __PRDR_PLUGIN_HUID l_homtype = homtype; \
            __table_struct * l_tablePtr = cv_table; \
            while (nullptr != l_tablePtr->name) \
            { \
                GetErrorSigTable()[l_homtype][l_tablePtr->signature] = \
                  std::pair<const char*, const char*> \
                   (l_tablePtr->name,l_tablePtr->brief); \
                l_tablePtr++; \
            } \
        } \
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset):: \
            __table_struct \
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset):: \
        cv_table[] = \
            {

    #define PRDR_ERROR_SIGNATURE( signature , name, brief ) \
                { signature , name , brief } ,

    #define PRDR_ERROR_SIGNATURE_TABLE_END \
                { 0, nullptr, nullptr } \
            }; \
            } \
            } // end namespace PRDF
#endif

#include <map>
#include <stdint.h>

namespace PRDF
{
namespace HOSTBOOT
{

typedef std::map<__PRDR_PLUGIN_IDTYPE,
                 std::pair<const char*, const char*>> PrdrErrSigEntries;
typedef std::map<__PRDR_PLUGIN_HUID, PrdrErrSigEntries> PrdrErrSigTable;

PrdrErrSigTable & GetErrorSigTable();

} // namespace HOSTBBOT
} // end namespace PRDF

#endif
