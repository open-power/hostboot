/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/ctype.C $                                             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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

