/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/ctype.C $                                             */
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
#include <ctype.h>

int toupper(int ch)
{
    if(( ch >= 'a') && (ch <= 'z' ))
    {
        ch &= ~0x20;
    }
    return ch;
}

int isdigit(int c)
{
    return ((c >= '0') && (c <= '9'));
}

int islower(int c)
{
    return ((c >= 'a') && (c <= 'z'));
}

int isupper(int c)
{
    return ((c >= 'A') && (c <= 'Z'));
}

int isalpha(int c)
{
    return islower(c) || isupper(c);
}

int isalnum(int c)
{
    return isdigit(c) || isalpha(c);
}

int ispunct(int c)
{
    // Look at an ASCII table...
    return ((c >= '!') && (c <= '/')) ||
           ((c >= ':') && (c <= '@')) ||
           ((c >= '[') && (c <= '`')) ||
           ((c >= '{') && (c <= '~'));
}

int isspace(int c)
{
    // There are other space characters, like tabs, but I don't think we
    // need to support them.
    return (c == ' ');
}

int isprint(int c)
{
    return isalnum(c) || ispunct(c) || isspace(c);
}

