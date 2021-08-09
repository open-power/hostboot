/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorif.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#ifndef __PNORIF_H
#define __PNORIF_H

#include <errl/errlentry.H>
#include <errl/errlmanager.H>

class PnorIf
{
    public:
        /**
         * @brief Performs a PNOR Read Operation
         *
         * @parm o_buffer  Buffer to read data into
         * @parm io_buflen  Input: Number of bytes to read,
         *       Output: Number of bytes actually read
         * @parm i_address  Offset into flash to read
         *
         * @return Error from operation
         */
        virtual errlHndl_t readFlash(void* o_buffer,
                                     size_t& io_buflen,
                                     uint64_t i_address) = 0;

        /**
         * @brief Performs a PNOR Write Operation
         *
         * @parm i_buffer  Buffer to write data from
         * @parm io_buflen  Input: Number of bytes to write,
         *       Output: Number of bytes actually written
         * @parm i_address  Offset into flash to write
         *
         * @return Error from operation
         */
        virtual errlHndl_t writeFlash(const void* i_buffer,
                                      size_t& io_buflen,
                                      uint64_t i_address) = 0;

        /**
         * @brief Retrieve size of NOR flash
         * @return Size of PNOR in bytes
         */
        virtual uint32_t getNorSize(void) = 0;

        /**
         * @brief Retrieve bitstring of NOR workarounds
         * @return NOR workarounds (see VendorWorkarounds in norflash.H)
         */
        virtual uint32_t getNorWorkarounds(void) = 0;

        /**
         * @brief Retrieve error log from constructor and forget
         *        about it
         * @return nullptr if no error occurred in constructor,
         *         else contains error log that occurred in constructor
         */
        errlHndl_t getConstructorLog( void )
        {
            // give the stored log to the caller
            errlHndl_t errhdl = iv_constructorLog;
            iv_constructorLog = nullptr;
            return errhdl;
        };

        /**
         * @brief Destructor
         */
        virtual ~PnorIf(void)
        {
            // if we still have an unclaimed log, commit it as informational
            if( iv_constructorLog )
            {
                iv_constructorLog->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                iv_constructorLog->collectTrace(PNOR_COMP_NAME);
                errlCommit(iv_constructorLog, PNOR_COMP_ID);
            }
        }


      protected:
        /**
         * @brief Remember any log that we hit during the constructor
         *
         */
        errlHndl_t iv_constructorLog;
};

#endif
