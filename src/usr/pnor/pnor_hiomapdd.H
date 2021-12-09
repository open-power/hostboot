/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_hiomapdd.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
#ifndef __PNOR_HIOMAPDD_H
#define __PNOR_HIOMAPDD_H

/*
 * The PnorHiomapDD class implements fallback semantics for the HIOMAP
 * transport implementations (currently, AST mailbox). The constructor
 * probes each transport. If a transport's
 * probe is successful the instance of the transport's class is stored in
 * the iv_pnor member of PnorHiomapDD.
 *
 * With this in place, we register the readFlash() and writeFlash() methods
 * of PnorHiomapDD as the handlers for the PNOR device driver route. Each
 * method then delegates to the respective method on the instance of the class
 * of transport that was successfully probed.
 */

#include <errl/errlentry.H>
#include <targeting/common/target.H>

#include "pnorif.H"

class PnorHiomapDD : public PnorIf
{
    public:
        PnorHiomapDD(TARGETING::Target* i_target = NULL);
        ~PnorHiomapDD();

        PNOR::hiomapMode getAccessMode(void);

        virtual errlHndl_t readFlash(void* o_buffer,
                                     size_t& io_buflen,
                                     uint64_t i_address);

        virtual errlHndl_t writeFlash(const void* i_buffer,
                                      size_t& io_buflen,
                                      uint64_t i_address);

        virtual uint32_t getNorSize(void);

        virtual uint32_t getNorWorkarounds(void);

    private:
        PnorIf* iv_pnor;
        PNOR::hiomapMode iv_mode;
};

#endif
