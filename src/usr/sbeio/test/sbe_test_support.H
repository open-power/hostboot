/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_test_support.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __SBE_TEST_SUPPORT_H
#define __SBE_TEST_SUPPORT_H

#include <stdint.h>
#include <stdio.h>

//---------------------------------------------------------------------
template <size_t N>
void xxdPrint(const void* pvbuffer,
              size_t bufferSize,
              char (&strBuffer)[N])
{
    if(nullptr == pvbuffer || 0 == bufferSize)
    {
        return;
    }

    const char* pbuffer = reinterpret_cast<const char*>(pvbuffer);

    char* pstr = strBuffer;

    int remaining = static_cast<int>(sizeof(strBuffer));
    memset(strBuffer, 0, sizeof(strBuffer));

    for(size_t i=0; i < bufferSize; ++i)
    {
        int rc{};
        const uint8_t byteVal =
            *(reinterpret_cast<const uint8_t*>(pbuffer++));
        if(i == 0)
        {
            rc = snprintf(pstr, remaining, "\t\t\t\t%02X", byteVal);
        }
        else if(i%16 == 0)
        {
            rc = snprintf(pstr, remaining, "\n\t\t\t\t%02X", byteVal);
        }
        else
        {
            if(i%2 == 1)
            {
                rc = snprintf(pstr, remaining, "%02X ", byteVal);
            }
            else
            {
                rc = snprintf(pstr, remaining, "%02X", byteVal);
            }
        }

        if(rc > 0 && rc < remaining)
        {
            remaining -= rc;
            pstr += rc;

            if(remaining <= 0)
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

#endif
