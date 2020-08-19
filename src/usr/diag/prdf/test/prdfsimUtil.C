/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimUtil.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

// NOTE: Items must be in the order of the entity path
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

    {"EQ{0}", {TYPE_EQ, 0}},
    {"EQ{1}", {TYPE_EQ, 1}},
    {"EQ{2}", {TYPE_EQ, 2}},
    {"EQ{3}", {TYPE_EQ, 3}},
    {"EQ{4}", {TYPE_EQ, 4}},
    {"EQ{5}", {TYPE_EQ, 5}},

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

    {"CORE{0}", {TYPE_CORE, 0}},
    {"CORE{1}", {TYPE_CORE, 1}},
    {"CORE{2}", {TYPE_CORE, 2}},
    {"CORE{3}", {TYPE_CORE, 3}},
    {"CORE{4}", {TYPE_CORE, 4}},
    {"CORE{5}", {TYPE_CORE, 5}},
    {"CORE{6}", {TYPE_CORE, 6}},
    {"CORE{7}", {TYPE_CORE, 7}},
    {"CORE{8}", {TYPE_CORE, 8}},
    {"CORE{9}", {TYPE_CORE, 9}},
    {"CORE{10}",{TYPE_CORE,10}},
    {"CORE{11}",{TYPE_CORE,11}},
    {"CORE{12}",{TYPE_CORE,12}},
    {"CORE{13}",{TYPE_CORE,13}},
    {"CORE{14}",{TYPE_CORE,14}},
    {"CORE{15}",{TYPE_CORE,15}},
    {"CORE{16}",{TYPE_CORE,16}},
    {"CORE{17}",{TYPE_CORE,17}},
    {"CORE{18}",{TYPE_CORE,18}},
    {"CORE{19}",{TYPE_CORE,19}},
    {"CORE{20}",{TYPE_CORE,20}},
    {"CORE{21}",{TYPE_CORE,21}},
    {"CORE{22}",{TYPE_CORE,22}},
    {"CORE{23}",{TYPE_CORE,23}},

    {"MCBIST{0}", {TYPE_MCBIST, 0}},
    {"MCBIST{1}", {TYPE_MCBIST, 1}},
    {"MCBIST{2}", {TYPE_MCBIST, 2}},
    {"MCBIST{3}", {TYPE_MCBIST, 3}},

    {"MCS{0}", {TYPE_MCS, 0}},
    {"MCS{1}", {TYPE_MCS, 1}},
    {"MCS{2}", {TYPE_MCS, 2}},
    {"MCS{3}", {TYPE_MCS, 3}},

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
     for (; (haystack = strchr(haystack, *needle)) != nullptr; haystack++)
         if (strncmp(haystack, needle, needlelen) == 0)
             return (char *) haystack;
     return nullptr;
 }

#endif // end ifdef __HOSTBOOT_MODULE

TARGETING::Target* string2Target(const char * i_str)
{
    TARGETING::Target* l_retTarget = nullptr;
    TARGETING::EntityPath epath(TARGETING::EntityPath::PATH_PHYSICAL);
    epath.addLast(TARGETING::TYPE_SYS,0);

    PRDF_DTRAC("prdfString2Target() i_str=%s", i_str);

    for( uint64_t x = 0; x < NUM_EPATH_ARRAY; ++x )
    {
        const char * pch = nullptr;
        pch = strstr(i_str, EPATH_ARRAY_MAP[x].str);
        if(nullptr != pch)
        {
            PRDF_DTRAC("string2Target() pathE.type=0x%08x, pathE.instance=%d",
                  EPATH_ARRAY_MAP[x].pathE.type, EPATH_ARRAY_MAP[x].pathE.instance);
            epath.addLast(EPATH_ARRAY_MAP[x].pathE.type,
                  EPATH_ARRAY_MAP[x].pathE.instance);
        }
    }

    l_retTarget = getTarget(epath);

    if ( nullptr != l_retTarget )
    {
        PRDF_TRAC("string2Target() l_retTarget=0x%08x, epath=see target traces",
                  getHuid(l_retTarget));
        epath.dump();
    }

    return l_retTarget;
}

} // End namespace PRDF
