/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimUtil.C $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

#include <prdfsimUtil.H>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __HOSTBOOT_MODULE
  #include <string_ext.h>
#endif

namespace PRDF
{

using namespace TARGETING;
using namespace PlatServices;

struct epath_array
{
  const char * str;
  EntityPath::PathElement pathE;
};

const epath_array EPATH_ARRAY_MAP[] =
{
    {"NODE{0}", {TYPE_NODE, 0}},
    {"NODE{1}", {TYPE_NODE, 1}},
    {"PROC{0}", {TYPE_PROC, 0}},
    {"PROC{1}", {TYPE_PROC, 1}},
    {"PROC{2}", {TYPE_PROC, 2}},
    {"PROC{3}", {TYPE_PROC, 3}},
    {"PROC{4}", {TYPE_PROC, 4}},
    {"PROC{5}", {TYPE_PROC, 5}},
    {"PROC{6}", {TYPE_PROC, 6}},
    {"PROC{7}", {TYPE_PROC, 7}},
    {"EX{0}", {TYPE_EX, 0}},
    {"EX{1}", {TYPE_EX, 1}},
    {"EX{2}", {TYPE_EX, 2}},
    {"EX{3}", {TYPE_EX, 3}},
    {"EX{4}", {TYPE_EX, 4}},
    {"EX{5}", {TYPE_EX, 5}},
    {"EX{6}", {TYPE_EX, 6}},
    {"EX{7}", {TYPE_EX, 7}},
    {"EX{8}", {TYPE_EX, 8}},
    {"EX{9}", {TYPE_EX, 9}},
    {"EX{10}", {TYPE_EX, 10}},
    {"EX{11}", {TYPE_EX, 11}},
    {"EX{12}", {TYPE_EX, 12}},
    {"EX{13}", {TYPE_EX, 13}},
    {"EX{14}", {TYPE_EX, 14}},
    {"EX{15}", {TYPE_EX, 15}},
    {"ABUS{0}", {TYPE_ABUS, 0}},
    {"ABUS{1}", {TYPE_ABUS, 1}},
    {"ABUS{2}", {TYPE_ABUS, 2}},
    {"XBUS{0}", {TYPE_XBUS, 0}},
    {"XBUS{1}", {TYPE_XBUS, 1}},
    {"XBUS{2}", {TYPE_XBUS, 2}},
    {"XBUS{3}", {TYPE_XBUS, 3}},
    {"MCS{0}", {TYPE_MCS, 0}},
    {"MCS{1}", {TYPE_MCS, 1}},
    {"MCS{2}", {TYPE_MCS, 2}},
    {"MCS{3}", {TYPE_MCS, 3}},
    {"MCS{4}", {TYPE_MCS, 4}},
    {"MCS{5}", {TYPE_MCS, 5}},
    {"MCS{6}", {TYPE_MCS, 6}},
    {"MCS{7}", {TYPE_MCS, 7}},
    {"MEMBUF{0}", {TYPE_MEMBUF, 0}},
    {"MEMBUF{1}", {TYPE_MEMBUF, 1}},
    {"MEMBUF{2}", {TYPE_MEMBUF, 2}},
    {"MEMBUF{3}", {TYPE_MEMBUF, 3}},
    {"MEMBUF{4}", {TYPE_MEMBUF, 4}},
    {"MEMBUF{5}", {TYPE_MEMBUF, 5}},
    {"MEMBUF{6}", {TYPE_MEMBUF, 6}},
    {"MEMBUF{7}", {TYPE_MEMBUF, 7}},
    {"MBS{0}", {TYPE_MBS, 0}},
    {"MBS{1}", {TYPE_MBS, 1}},
    {"MBA{0}", {TYPE_MBA, 0}},
    {"MBA{1}", {TYPE_MBA, 1}},
};

const uint64_t NUM_EPATH_ARRAY = sizeof(EPATH_ARRAY_MAP)/sizeof(EPATH_ARRAY_MAP[0]);

#ifdef __HOSTBOOT_MODULE

//my local version of strncmp - hostboot doesn't have this yet
 int (strncmp)(const char *s1, const char *s2, size_t n)
 {
     unsigned char uc1, uc2;
     /* Nothing to compare?  Return zero.  */
     if (n == 0)
         return 0;
     /* Loop, comparing bytes.  */
     while (n-- > 0 && *s1 == *s2) {
         /* If we've run out of bytes or hit a null, return zero
            since we already know *s1 == *s2.  */
         if (n == 0 || *s1 == '\0')
             return 0;
         s1++;
         s2++;
     }
     uc1 = (*(unsigned char *) s1);
     uc2 = (*(unsigned char *) s2);
     return ((uc1 < uc2) ? -1 : (uc1 > uc2));
 }


//my local version of strstr - hostboot doesn't have this yet
 char *(strstr)(const char *haystack, const char *needle)
 {
     size_t needlelen;
     /* Check for the null needle case.  */
     if (*needle == '\0')
         return (char *) haystack;
     needlelen = strlen(needle);
     for (; (haystack = strchr(haystack, *needle)) != NULL; haystack++)
         if (strncmp(haystack, needle, needlelen) == 0)
             return (char *) haystack;
     return NULL;
 }

#endif // end ifdef __HOSTBOOT_MODULE

TARGETING::Target* string2Target(const char * i_str)
{
    TARGETING::Target* l_retTarget = NULL;
    TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
    epath.addLast(TARGETING::TYPE_SYS,0);

    PRDF_DTRAC("prdfString2Target() i_str=%s", i_str);

    for( uint64_t x = 0; x < NUM_EPATH_ARRAY; ++x )
    {
        const char * pch = NULL;
        pch = strstr(i_str, EPATH_ARRAY_MAP[x].str);
        if(NULL != pch)
        {
            PRDF_DTRAC("string2Target() pathE.type=0x%08x, pathE.instance=%d",
                  EPATH_ARRAY_MAP[x].pathE.type, EPATH_ARRAY_MAP[x].pathE.instance);
            epath.addLast(EPATH_ARRAY_MAP[x].pathE.type,
                  EPATH_ARRAY_MAP[x].pathE.instance);
        }
    }

    l_retTarget = getTarget(epath);

    if ( NULL != l_retTarget )
    {
        PRDF_TRAC("string2Target() l_retTarget=0x%08x, epath=", getHuid(l_retTarget));
        epath.dump();
    }

    return l_retTarget;
}

} // End namespace PRDF
