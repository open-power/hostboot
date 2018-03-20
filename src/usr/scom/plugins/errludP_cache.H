/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/plugins/errludP_cache.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

#ifndef ERRLUDP_CACHE_H
#define ERRLUDP_CACHE_H

/**
*  @file errludP_cache.H
*
*  Defines the ErrlUserDetailsParser classes that parse Centaur SCOM register
*      cache mismatch FFDC
*/

#include "errluserdetails.H"

namespace SECUREBOOT
{

namespace CENTAUR_SECURITY
{

    /**
     *  @class UdParserCentaurCacheMismatch
     *
     *  @brief Parses UdParserCentaurCacheMismatch user details sections
     */
    class UdParserCentaurCacheMismatch : public ERRORLOG::ErrlUserDetailsParser
    {

      public:

        /**
         *  @brief Constructor
         */
        UdParserCentaurCacheMismatch()
        {
        }

        /**
         *  @brief Destructor
         */
        virtual ~UdParserCentaurCacheMismatch()
        {
        }

        /**
         *  @brief Parses user detail data from an error log
         *
         *  @param[in] i_version Version of the data
         *  @param[in] i_parse   ErrlUsrParser object for outputting information
         *  @param[in] i_pBuffer Pointer to buffer containing detail data
         *  @param[in] i_buflen  Length of the buffer
         */
        virtual void parse(
                  errlver_t      i_version,
                  ErrlUsrParser& i_parser,
                  void *         i_pBuffer,
            const uint32_t       i_buflen) const
        {
            if(i_version < SCOM_UDT_VERSION_1)
            {
                i_parser.PrintHeading("SCOM cache FFDC: Unknown version");
            }
            else
            {
                i_parser.PrintHeading("SCOM cache FFDC");

                const char* fieldName[] =
                {
                    "Register address",
                    "Unmasked expected value",
                    "Unmasked actual value",
                    "Mask",
                    "Masked expected value",
                    "Masked actual value",
                };

                const uint64_t* pField =
                    reinterpret_cast<const uint64_t *>(i_pBuffer);
                for(size_t i=0;
                    i<sizeof(fieldName)/sizeof(fieldName[0]);
                    ++i)
                {
                    if(i_buflen >= (i+1)*sizeof(*pField) )
                    {
                        i_parser.PrintNumberUint64(
                            fieldName[i],"0x%016llX",
                            ERRORLOG::NTH_UINT64(pField+i));
                    }
                }
            }
         }

      private:

        // Parser isn't compiled with c++11 in all environments, and
        // therefore "delete" of unused interfaces (like below) is not
        // supported, nor are functions with move semantics

        // Disable compiler provided default functions
        UdParserCentaurCacheMismatch(
            const UdParserCentaurCacheMismatch&);

        UdParserCentaurCacheMismatch & operator=(
            const UdParserCentaurCacheMismatch&);
    };

}

}

#endif

