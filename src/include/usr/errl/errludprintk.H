/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludprintk.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#ifndef ERRL_UDPRINTK_H
#define ERRL_UDPRINTK_H

/**
 *  @file errludprintk.H
 *
 *  Defines the ErrlUserDetailsPrintk class that adds a portion of the printk
 *  buffers as FFDC to an error log as user detail data.
 */

#include <stdint.h>
#include <errl/errluserdetails.H>

namespace ERRORLOG
{

    class ErrlUserDetailsPrintk : public ErrlUserDetails
    {
        public:
            enum { DEFAULT_SIZE_BYTES = 2048 };

            /** @brief Constructor
             *
             *  Captures the printk buffer.
             *
             *  @param[in] i_size - Amount (in bytes) of data to capture.
             */
            explicit ErrlUserDetailsPrintk(size_t i_size = DEFAULT_SIZE_BYTES)
            {
                _capturePrintk(i_size);
            }

            /** @brief Destructor
             */
            virtual ~ErrlUserDetailsPrintk() {};

        private:
            //Disabled.
            ErrlUserDetailsPrintk(const ErrlUserDetailsPrintk&);
            ErrlUserDetailsPrintk& operator=(const ErrlUserDetailsPrintk&);

            void _capturePrintk(size_t);
    };

}

#endif
