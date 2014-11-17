/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/test/attnfakereg.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __TEST_ATTNFAKEREG_H
#define __TEST_ATTNFAKEREG_H

/**
 * @file attnfakereg.H
 *
 * @brief HBATTN fake register class definition.
 */

#include "../../common/attnscom.H"
#include <map>

namespace ATTN
{

/**
 * @brief FakeRegSvc
 *
 * Container that presents an interface to fake hardware
 * implementations.
 */
class FakeRegSvc : public ScomImpl
{
    public:

        /**
         * @brief putScom Write a register using SCOM.
         *
         * @param[in] i_target Target to write register on.
         * @param[in] i_address Register address to write to.
         * @param[in] i_data Data to write to register.
         *
         * @retval[0] No errors.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t putScom(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data);

        /**
         * @brief getScom Read a register using SCOM.
         *
         * @param[in] i_target Target to read register from.
         * @param[in] i_address Register address to read from.
         * @param[out] o_data Buffer to write register content to.
         *
         * @retval[0] No errors.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t getScom(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t & o_data);

        /**
         * @brief modifyScom RMW a register using SCOM.
         *
         * @param[in] i_target Target to update register on.
         * @param[in] i_address Register address to update.
         * @param[in] i_data Data to write to register.
         * @param[out] o_data Data read from register.
         * @param[in] i_op and/or behavior.
         *
         * @retval[0] No errors.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t modifyScom(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data,
                uint64_t & o_data,
                ScomOp i_op);


        /**
         * @brief ctor
         */
        FakeRegSvc(){};

        /**
         * @brief dtor
         */
        virtual ~FakeRegSvc(){};

    private:

        /**
         * @brief Reg Register/address association alias.
         */
        typedef std::map<uint64_t, uint64_t> RegAddrDataAssoc;

        /**
         * @brief Regs Registers/target association alias.
         */
        typedef std::map<TARGETING::TargetHandle_t, RegAddrDataAssoc> Regs;

        /**
         * @brief iv_regs Current register content.
         */
        Regs iv_regs;

};
}
#endif
