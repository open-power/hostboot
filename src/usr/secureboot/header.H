/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/header.H $                                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef __SECUREBOOT_HEADER_H
#define __SECUREBOOT_HEADER_H

#include <stdint.h>

/** @file header.H
 *
 *  @brief Classes for manipulating Secureboot headers.
 */

namespace SECUREBOOT
{
    /** @class Header
     *  @brief Class for storing the original Secureboot header for later use.
     */
    class Header
    {
        public:
            Header() : iv_data(NULL) {};
            ~Header() {};

            /** @brief Extract header from original HRMOR - 1 page address. */
            void loadBaseHeader();

        private:
            /** Copy of the original secureboot header for the base image. */
            void* iv_data;
    };
};

#endif
