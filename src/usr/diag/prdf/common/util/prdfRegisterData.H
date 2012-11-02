/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfRegisterData.H $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2012              */
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
            while (NULL != l_tablePtr->name) \
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
                { 0, NULL, NULL, 0 } \
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
