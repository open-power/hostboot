/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnfakesys.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __TEST_ATTNFAKESYS_H
#define __TEST_ATTNFAKESYS_H

/**
 * @file attnfakesys.H
 *
 * @brief HBATTN fake system class definition.
 */

#include "../attnscom.H"
#include "attntest.H"
#include "attncomp.H"
#include "attninject.H"
#include <map>

namespace ATTN
{

/**
 * @brief FakeSystem
 *
 * Container that presents an interface to fake hardware
 * implementations.
 */
class FakeSystem : public ScomImpl, public InjectSink
{
    public:

        /**
         * @brief putReg
         *
         * Simulate register modification originating in hardware.
         *
         * @param[in] i_target Target to write register on.
         * @param[in] i_address Register address to write to.
         * @param[in] i_data Data to write to register.
         *
         * @retval[0] No errors.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t putReg(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data);

        /**
         * @brief modifyReg
         *
         * Simulate register modification originating in hardware.
         *
         * @param[in] i_target Target to update register on.
         * @param[in] i_address Register address to update.
         * @param[in] i_data Data to write to register.
         * @param[in] i_op and/or behavior.
         *
         * @retval[0] No errors.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t modifyReg(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data,
                ScomOp i_op);

        /**
         * @brief getReg Register read originating in hardware.
         *
         * @param[in] i_target Target to read register from.
         * @param[in] i_address Register address to read from.
         *
         * @return Register data.
         */
        uint64_t getReg(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address);

        /**
         * @brief putAttentions
         *
         * Instruct the system to inject the specified attention.
         *
         * @param[in] i_list The attentions to inject.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t putAttentions(
                const PRDF::AttnList & i_list);

        /**
         * @brief clearAttention
         *
         * Instruct the system clear the specified attention.
         *
         * @param[in] i_attn The attention to clear.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t clearAttention(
                const PRDF::AttnData & i_attn);

        /**
         * @brief clearAllAttentions
         *
         * Instruct the system clear all instances of the specified attention.
         *
         * @param[in] i_attn The attention to clear.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t clearAllAttentions(
                const PRDF::AttnData & i_attn);

        /**
         * @brief count
         *
         * For the provided attention type, obtain the number
         * of times it is being reported by the system.
         *
         * @param[in] i_attn The attention type for which the count should be
         *                obtained.
         */
        uint64_t count(
                const PRDF::AttnData & i_attn);

        /**
         * @brief wait
         *
         * Block the calling thread until no attentions are
         * being reported on the system.
         *
         * @param[in] i_maxTimeNs Max amount of time to wait
         *                once system has reached stable state
         *                (number of attentions isn't changing)
         *
         * @retval[true] No attentions being reported.
         * @retval[false].Attentions still being reported
         *                  after waiting i_maxTimeNs.
         */
        bool wait(uint64_t i_maxTimeNs);

        /**
         * @brief wait
         *
         * Block the calling thread until no attentions are
         * being reported on the system.
         */
        void wait();

        /**
         * @brief addReg
         *
         * Register a register implementaion with the system.
         *
         * @param[in] i_address The address for which the implementation
         *              wishes to monitor.
         * @param[in] i_reg The register implementation to add to the system.
         */
        void addReg(
                uint64_t i_address,
                FakeReg & i_reg);

        /**
         * @brief addSource
         *
         * Register an attention source implementation with the system.
         *
         * @param[in] i_targetType The target type for which the implementation
         *              wishes to monitor.
         * @param[in] i_type The attention type for which the implementation
         *              wishes to monitor.
         * @param[in] i_source The source to add to the system.
         */
        void addSource(
                TARGETING::TYPE i_targetType,
                PRDF::ATTENTION_VALUE_TYPE i_type,
                FakeSource & i_source);

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
         * @brief dump Dump active attentions to trace.
         */
        void dump();

        /*
         * @brief count Obtain the number of attentions present
         *          on the system.
         *
         * @return The number of attentions present on the system.
         */
        uint64_t count();

        /**
         * @brief ctor
         */
        FakeSystem();

        /**
         * @brief dtor
         */
        virtual ~FakeSystem();

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

        /**
         * @brief makeAttnCallbacks
         *
         * Notify registered sources of attention state changes.
         *
         * @param[in] i_list List of attentions changing state.
         * @param[in] i_set Attentions turning on / off.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t makeAttnCallbacks(
                const PRDF::AttnList & i_list,
                bool i_set);

        /**
         * @brief makeRegCallbacks
         *
         * Notify registered registers of content changes.
         *
         * @param[in] i_target Target being updated.
         * @param[in] i_address Address of register being updated.
         * @param[in] i_new Post update register content.
         * @param[in] i_new Pre update register content.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t makeRegCallbacks(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_new,
                uint64_t i_old);

        /**
         * @brief clearAttentionUnsafe
         *
         * Thread unsafe wrapper for clearAttention.
         *
         * @param[in] i_attn The attention to clear.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        void clearAttentionUnsafe(
                const PRDF::AttnData & i_attn);

        /**
         * @brief putRegUnsafe
         *
         * Thread unsafe wrapper for putReg.
         *
         * @param[in] i_target Target to write register on.
         * @param[in] i_address Register address to write to.
         * @param[in] i_data Data to write to register.
         */
        void putRegUnsafe(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data);

        /**
         * @brief iv_attentions Current active attentions.
         */
        AttnDataMap<uint64_t> iv_attentions;

        /**
         * @brief iv_regImpl registered register implementations.
         */
        std::vector<std::pair<uint64_t, FakeReg *> > iv_regImpl;

        /**
         * @brief Key Registered source key alias.
         */
        typedef std::pair<TARGETING::TYPE, PRDF::ATTENTION_VALUE_TYPE> Key;

        /**
         * @brief Entry Registered source key/value alias.
         */
        typedef std::pair<Key, FakeSource *> Entry;

        /**
         * @brief iv_source Registered sources.
         */
        std::vector<Entry> iv_sources;

        /**
         * @brief iv_mutex Shared data access serialization.
         */
        mutex_t iv_mutex;

        /**
         * @brief iv_cond Zero attentions condition.
         */
        sync_cond_t iv_cond;
};
}
#endif
