/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/sprintf.H $                                  */
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
#ifndef __UTIL_SPRINTF_H
#define __UTIL_SPRINTF_H

#include <stdarg.h>
#include <stdint.h>

namespace Util
{
    class ConsoleBufferInterface
    {
        public:
            virtual ~ConsoleBufferInterface() {};
            virtual size_t operator() (int) = 0;
    };

    size_t vasprintf(ConsoleBufferInterface& output_func,
                     const char* fmt_str, va_list& args);

};

#endif
