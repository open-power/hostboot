/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfRegisterData.H $            */
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

#ifndef __PRDRERRLPLUGINSUPT_H
#define __PRDRERRLPLUGINSUPT_H

#include <map>
#include <stdint.h>

namespace PRDF
{

#define __PRDR_PLUGIN_HOMTYPE uint32_t
#define __PRDR_PLUGIN_IDTYPE  uint32_t

#define __PRDR_PLUGIN_XY(X,Y,Z) X##Y##_##Z
#define __PRDR_PLUGIN_MAKENAME(X,Y,Z) __PRDR_PLUGIN_XY(X,Y,Z)

#ifndef PRDR_REGISTER_ID_TABLE_START
    #define PRDR_REGISTER_ID_TABLE_START( homtype, offset) \
        class __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, homtype, offset)\
        { \
            public: \
                __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, \
                                       homtype, offset)(); \
            private: \
                struct __table_struct \
                { \
                    uint32_t         id; \
                    char *          name; \
                    char *           brief; \
                    uint32_t    address; \
                }; \
                static __table_struct cv_table[]; \
        }; \
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, homtype, offset) \
            __PRDR_PLUGIN_MAKENAME(g_PrdrPlugin_RegTable_Reg_, homtype, offset);\
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, homtype, offset)::\
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, homtype, offset)() \
        { \
            __PRDR_PLUGIN_HOMTYPE l_homtype = homtype; \
            __table_struct * l_tablePtr = cv_table; \
            while (nullptr != l_tablePtr->name) \
            { \
                GetRegisterIdTable()[l_homtype][l_tablePtr->id].name = \
                    l_tablePtr->name;  \
                GetRegisterIdTable()[l_homtype][l_tablePtr->id].addr = \
                    l_tablePtr->address; \
                l_tablePtr++; \
            } \
        } \
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, homtype, offset):: \
            __table_struct \
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, homtype, offset):: \
        cv_table[] = \
            {

    #define PRDR_REGISTER_ID( id , name, brief, address ) \
                { id , #name , brief, address } ,

    #define PRDR_REGISTER_ID_TABLE_END \
                { 0, nullptr, nullptr, 0 } \
            };
#endif

typedef std::map<__PRDR_PLUGIN_IDTYPE, const char *> PrdrErrSigEntries;
typedef std::map<__PRDR_PLUGIN_HOMTYPE, PrdrErrSigEntries> PrdrErrSigTable;

struct RegIdStruct
{
    const char * name;
    uint32_t addr;
};

typedef std::map<__PRDR_PLUGIN_IDTYPE, RegIdStruct> PrdrRegIdEntries;
typedef std::map<__PRDR_PLUGIN_HOMTYPE, PrdrRegIdEntries> PrdrRegIdTable;

PrdrRegIdTable & GetRegisterIdTable();

} // end namespace PRDF

#endif
