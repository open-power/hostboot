/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdrErrlPluginsSupt.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2013              */
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

#define __PRDR_PLUGIN_HOMTYPE uint32_t
#define __PRDR_PLUGIN_IDTYPE  uint32_t

#define __PRDR_PLUGIN_XY(X,Y,Z) X##Y##_##Z
#define __PRDR_PLUGIN_MAKENAME(X,Y,Z) __PRDR_PLUGIN_XY(X,Y,Z)

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
#define PRDF_ERRL_PLAT_NS namespace HOSTBOOT
#else
#define PRDF_ERRL_PLAT_NS namespace FSP
#endif

#ifndef PRDR_ERROR_SIGNATURE_TABLE_START
    #define PRDR_ERROR_SIGNATURE_TABLE_START( homtype, offset) \
        namespace PRDF \
        {\
        PRDF_ERRL_PLAT_NS \
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
                    const char *           brief; \
                }; \
                static __table_struct cv_table[]; \
        }; \
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset) \
            __PRDR_PLUGIN_MAKENAME(g_PrdrPlugin_errTable_Reg_, homtype, offset);\
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset)::\
        __PRDR_PLUGIN_MAKENAME(PrdrPlugin_ErrTable_Reg_, homtype, offset)() \
        { \
            __PRDR_PLUGIN_HOMTYPE l_homtype = homtype; \
            __table_struct * l_tablePtr = cv_table; \
            while (NULL != l_tablePtr->name) \
            { \
                GetErrorSigTable()[l_homtype][l_tablePtr->signature] = \
                        "(" + std::string(l_tablePtr->name) + ") " + \
                        std::string(l_tablePtr->brief); \
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
                { 0, NULL, NULL } \
            }; \
            } \
            } // end namespace PRDF
#endif

#ifndef PRDR_REGISTER_ID_TABLE_START
    #define PRDR_REGISTER_ID_TABLE_START( homtype, offset) \
        namespace PRDF \
        { \
        PRDF_ERRL_PLAT_NS \
        { \
        class __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, homtype, offset)\
        { \
            public: \
                __PRDR_PLUGIN_MAKENAME(PrdrPlugin_RegTable_Reg_, \
                                       homtype, offset)(); \
            private: \
                struct __table_struct \
                { \
                    uint32_t         id; \
                    const char *          name; \
                    const char *           brief; \
                    uint64_t    address; \
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
                    std::string(l_tablePtr->name);  \
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
            }; \
            } \
            } // end namespace PRDF
#endif

#include <map>
#include <string>
#include <stdint.h>

namespace PRDF
{
#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{

typedef std::map<__PRDR_PLUGIN_IDTYPE, std::string> PrdrErrSigEntries;
typedef std::map<__PRDR_PLUGIN_HOMTYPE, PrdrErrSigEntries> PrdrErrSigTable;

struct RegIdStruct
{
    std::string        name;
    uint64_t addr;
};

typedef std::map<__PRDR_PLUGIN_IDTYPE, RegIdStruct> PrdrRegIdEntries;
typedef std::map<__PRDR_PLUGIN_HOMTYPE, PrdrRegIdEntries> PrdrRegIdTable;

PrdrRegIdTable & GetRegisterIdTable();
PrdrErrSigTable & GetErrorSigTable();

} // namespace FSP/HOSTBBOT
} // end namespace PRDF

#endif
