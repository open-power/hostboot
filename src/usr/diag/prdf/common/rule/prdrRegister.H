/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrRegister.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __PRDRREGISTER_H
#define __PRDRREGISTER_H

#include <stdio.h>
#include <string.h>
#include <algorithm>

#include <string>
#include <list>

#include <stdint.h>

#include <iostream>
#include <iomanip>
#include <netinet/in.h>

// define needed to enable x86 rule parser code only
#define __PRD_RULE_COMPILE
#include <prdrCommon.H>
#include <UtilHash.H>

#ifdef __HOSTBOOT_MODULE
  #include <endian.h>
  # define htonll(x) htobe64(x)
  #ifndef htobe64
    #include <byteswap.h>
    #if __BYTE_ORDER == __LITTLE_ENDIAN
        #define htobe64(x) __bswap_64(x)
    #else
        #define htobe64(x) (x)
    #endif
  #endif
#else
  #include <utilendian.H>
#endif

#define PRDR_FWRITE( memPtr, size, count, fileStream) \
    if( count != fwrite(memPtr, size, count, fileStream)) \
    { \
        std::cout<<"Failed to write data to file"; \
        exit(1); \
    }

namespace PRDR_COMPILER
{

extern Prdr::HashCollisionMap g_regsHashCollision;
extern bool g_hadError;

struct ResetOrMaskStruct
{
    uint8_t type;
    uint64_t addr_r;
    uint64_t addr_w;

    void output(FILE * l_file)
    {
        PRDR_FWRITE(&type, 1, 1, l_file);

        uint64_t l_tmp64;

        l_tmp64 = htonll(addr_r);
        PRDR_FWRITE(&l_tmp64, sizeof (l_tmp64), 1, l_file);

        l_tmp64 = htonll(addr_w);
        PRDR_FWRITE(&l_tmp64, sizeof (l_tmp64), 1, l_file);
    }
};

struct CaptureReqStruct
{
    uint8_t type;
    uint32_t data[2];
    std::string str;

    enum
    {
        PRDR_CAPTURE_GROUPID = 'G',
        PRDR_CAPTURE_CONN    = 'C',
        PRDR_CAPTURE_FUNC    = 'f',
        PRDR_CAPTURE_TYPE    = 'T', // Added this for storing a register's type in the capture struct.
        PRDR_CAPTURE_NONZERO = 'P' // Added this to specify non zero register.
    };

    void output(FILE * l_file)
    {
        PRDR_FWRITE(&type, 1, 1, l_file);
        uint32_t l_tmp32;

        int loopMax = 0;

        switch (type)
        {
            case PRDR_CAPTURE_GROUPID:
            case PRDR_CAPTURE_TYPE:
                loopMax = 1;
                break;

            case PRDR_CAPTURE_CONN:
                loopMax = 2;
                break;

            case PRDR_CAPTURE_FUNC:
            case PRDR_CAPTURE_NONZERO:
                loopMax = 0;
                break;
        }

        for (int i = 0; i < loopMax; i++)
        {
            l_tmp32 = htonl(data[i]);
            PRDR_FWRITE(&l_tmp32, 4, 1, l_file);
        }

        if (type == PRDR_CAPTURE_FUNC)
        {
            if ('"' == (str)[0])
                str = str.substr(1, str.size() - 2);
            PRDR_FWRITE(str.c_str(), str.size() + 1, 1, l_file);
        }

        if (type == PRDR_CAPTURE_NONZERO )
        {
            if ('"' == (str)[0])
            {
                // remove double quotes from the string
                str = str.substr(1, str.size() - 2);
            }
            l_tmp32 = htonl(PRDF::Util::hashString(str.c_str()));
            PRDR_FWRITE(&l_tmp32, sizeof(l_tmp32), 1, l_file);
        }
    };
};

class Register
{
  public:

    std::string * cv_sname;
    std::string * cv_name;

    uint32_t cv_flags;

    uint64_t cv_scomaddr;
    uint16_t cv_scomlen;

    std::string cv_name_default;

    std::list<ResetOrMaskStruct> cv_resets;
    std::list<ResetOrMaskStruct> cv_masks;

    std::list<CaptureReqStruct> cv_captures;

    Register() :
        cv_sname(nullptr),
        cv_name(&cv_name_default),
        cv_flags(0),
        cv_scomaddr(0),
        cv_scomlen(0),
        cv_resets(0), cv_masks(0), cv_captures(0)
    {};

    static void merge(Register * i_l, Register * i_r)
    {
        if ( nullptr != i_r->cv_sname )
        {
            i_l->cv_sname = i_r->cv_sname;
        }
        if ( &i_r->cv_name_default != i_r->cv_name )
        {
            i_l->cv_name = i_r->cv_name;
        }
        if ( 0 != i_r->cv_flags )
        {
            i_l->cv_flags |= i_r->cv_flags;
        }
        if ( 0 != i_r->cv_scomaddr )
        {
            i_l->cv_scomaddr = i_r->cv_scomaddr;
        }
        if ( 0 != i_r->cv_scomlen )
        {
            i_l->cv_scomlen = i_r->cv_scomlen;
        }
        if (0 != i_r->cv_resets.size())
        {
            std::copy( i_r->cv_resets.begin(),
                       i_r->cv_resets.end(),
                       std::back_inserter(i_l->cv_resets) );
        }
        if (0 != i_r->cv_masks.size())
        {
            std::copy( i_r->cv_masks.begin(),
                       i_r->cv_masks.end(),
                       std::back_inserter(i_l->cv_masks) );
        }
        if (0 != i_r->cv_captures.size())
        {
            std::copy( i_r->cv_captures.begin(),
                       i_r->cv_captures.end(),
                       std::back_inserter(i_l->cv_captures) );
        }
    };

    void print()
    {
        using std::cout;
        using std::endl;
        cout << "Register " << *cv_sname << ":" << endl;
        cout << "\tLong Name: " << *cv_name << endl;
        cout << "\tScom Addr: " << cv_scomaddr << endl;
        cout << "\tScom Len:  " << cv_scomlen << endl;
        cout << "\tAccess:    ";
        uint32_t accessLevels =
                        Prdr::PRDR_REGISTER_WRITE |
                        Prdr::PRDR_REGISTER_READ |
                        Prdr::PRDR_REGISTER_ACCESS_NIL;

        switch( cv_flags & accessLevels )
        {
            case Prdr::PRDR_REGISTER_ACCESS_NIL:    cout << "No access";  break;
            case Prdr::PRDR_REGISTER_WRITE:         cout << "Write only"; break;
            case Prdr::PRDR_REGISTER_READ:          cout << "Read only";  break;
            default:                                cout << "Read/Write";
        }
    }

    int output( FILE * l_file, uint16_t i_sigOff )
    {
        // Check for hash collisions
        uint16_t hash = PRDF::Util::hashString( cv_sname->c_str() ) ^ i_sigOff;
        Prdr::HashCollisionMap::iterator i = g_regsHashCollision.find(hash);
        if ( g_regsHashCollision.end() != i )
        {
            g_hadError = true; // Compile error

            std::cerr << "Register hash collision '" << *cv_sname << "' "
                      << std::hex << "[0x"
                      << std::setfill('0') << std::setw(4)
                      << hash << "]";

            if ( 0 != cv_sname->compare(i->second) )
            {
                std::cerr << ": previous register was '" << i->second << "'";
            }

            std::cerr << std::endl;
        }
        g_regsHashCollision[hash] = (*cv_sname);

        // Setup flags
        if (0 != cv_resets.size())
            cv_flags |= Prdr::PRDR_REGISTER_RESETS;
        if (0 != cv_masks.size())
            cv_flags |= Prdr::PRDR_REGISTER_MASKS;
        if (0 != cv_captures.size())
            cv_flags |= Prdr::PRDR_REGISTER_CAPTURE;

        uint32_t readWriteAccess =
                            Prdr::PRDR_REGISTER_WRITE |
                            Prdr::PRDR_REGISTER_READ  |
                            Prdr::PRDR_REGISTER_ACCESS_NIL;

        if ( 0 == (readWriteAccess & cv_flags) )
        {
            // No access has been specified so default to Read/Write access.
            cv_flags |= readWriteAccess;
        }

        // output data
        uint32_t l_temp;
        uint16_t l_temp16;

        l_temp16 = htons(PRDF::Util::hashString( cv_sname->c_str() ));
        PRDR_FWRITE(&l_temp16, sizeof(l_temp16), 1, l_file);

        l_temp = htonl(cv_flags);
        PRDR_FWRITE(&l_temp, sizeof(l_temp), 1, l_file);

        uint64_t l_temp64 = htonll(cv_scomaddr);
        PRDR_FWRITE(&l_temp64, sizeof(l_temp64), 1, l_file);

        if (cv_flags & Prdr::PRDR_REGISTER_SCOMLEN)
        {
            l_temp16 = htons(cv_scomlen);
            PRDR_FWRITE(&l_temp16, sizeof(l_temp16), 1, l_file);
        }

        if (cv_flags & Prdr::PRDR_REGISTER_RESETS)
        {
            l_temp16 = htons(cv_resets.size());
            PRDR_FWRITE(&l_temp16, sizeof(l_temp16), 1, l_file);

            std::for_each( cv_resets.begin(), cv_resets.end(),
                           std::bind2nd(
                               std::mem_fun_ref(&ResetOrMaskStruct::output),
                               l_file) );
        }

        if (cv_flags & Prdr::PRDR_REGISTER_MASKS)
        {
            l_temp16 = htons(cv_masks.size());
            PRDR_FWRITE(&l_temp16, sizeof(l_temp16), 1, l_file);

            std::for_each( cv_masks.begin(), cv_masks.end(),
                           std::bind2nd(
                               std::mem_fun_ref(&ResetOrMaskStruct::output),
                               l_file) );
        }

        if (cv_flags & Prdr::PRDR_REGISTER_CAPTURE)
        {
            l_temp16 = htons(cv_captures.size());
            PRDR_FWRITE(&l_temp16, sizeof(l_temp16), 1, l_file);

            std::for_each( cv_captures.begin(), cv_captures.end(),
                           std::bind2nd(
                                std::mem_fun_ref(&CaptureReqStruct::output),
                                l_file) );
        }

        return 0;
    };

    void outputRegisterFile(std::ostream & o_file, uint16_t i_sigOff)
    {
        uint16_t hash = PRDF::Util::hashString( cv_sname->c_str() ) ^ i_sigOff;

        o_file << "\tPRDR_REGISTER_ID ( "
               << std::hex
               << "0x" << std::setfill('0') << std::setw(4)
               << hash << ", "
               << *cv_sname << ", " << *cv_name << ", "
               << "0x" << std::setfill('0') << std::setw(16)
               << cv_scomaddr << "ULL )"
               << std::endl;
    };
};

typedef std::list<Register *> RegisterList;

} // end namespace PRDR_COMPILER

#endif

