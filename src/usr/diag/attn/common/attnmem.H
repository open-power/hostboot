/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnmem.H $                          */
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
#ifndef __ATTN_ATTNMEM_H
#define __ATTN_ATTNMEM_H

/**
 * @file attnmem.H
 *
 * @brief HBATTN memory attention operations definition.
 */

#include "common/attnops.H"
#include <map>

namespace ATTN
{

/**
 * @brief MemOps ATTN memory attention operations definition.
 */
class MemOps : public AttentionOps
{
    private:
        /**
         * @brief Find memory buffer associated with MC chiplet
         *        and DMI link passed in
         *
         * @param[in] i_mc - MC Chiplet with active attention
         * @param[in] i_dmi - DMI number with active attention
         * @param[in] i_attnType - attention type to match on
         *
         * @retval membuf if we found matching attention
         * @retval NULL if no matching attention
         */
        TARGETING::TargetHandle_t attnGetMembuf(
                                   const TARGETING::TargetHandle_t &i_mc,
                                   const uint32_t i_dmi,
                                   const PRDF::ATTENTION_VALUE_TYPE i_attnType);

        /**
         * @brief Checks the CHIFIR for ANY active attention of the
         *        type passed in that isn't masked off.
         *
         * @param[in] i_dmiTarg - DMI chiplet to check CHIFIR on
         * @param[in] i_attnType - attention type to match on
         *
         * @retval true if we found active attntype in any CHIFIR bit
         * @retval false if no active attn matching a CHIFIR bit
         */
        bool attnCmpAttnType( TARGETING::TargetHandle_t  i_dmiTarg,
                              const PRDF::ATTENTION_VALUE_TYPE i_attnType );

        /**
         * @brief Checks the MEMBUF for ANY active attention of the
         *        type passed in
         *
         * @param[in] i_memBuf - memBuf chiplet to check
         * @param[in] i_attnType - attention type to check
         *
         * @retval non-zero if we found active attntype in global FIR
         * @retval zeroe if no active attn in global FIR
         */
        uint64_t chkMembufAttn( TARGETING::TargetHandle_t  i_memBuf,
                                const PRDF::ATTENTION_VALUE_TYPE i_attnType );

        /** Used to indicate that an OCMB has hit a channel fail. Because we
         *  cannot mask the OCMB chiplet level FIR, we will only handle the
         *  one channel fail before forgoing further OCMB analysis */
        std::map<TARGETING::TargetHandle_t, bool> iv_ocmbChnlFail;

    public:

        /**
         * @brief resolve Find membuf attentions behind the supplied proc.
         *
         * @param[in] i_AttnData Where to put membuf target and attn type
         * @param[in] i_mcNumber  MC unit to examine (0 or 1)
         * @param[in] i_procTarg  Processor to examine for active MC units
         *
         * @retval true  if i_AttnData was set to valid values
         * @retval false if i_AttnData is invalid (no memory attns)
         */
        bool resolve(
                PRDF::AttnData &  i_AttnData,
                const uint32_t  i_mcNumber,
                TARGETING::TargetHandle_t  i_procTarg );

        /**
         * @brief resolveOcmbs Find ocmb attentions associated with input proc.
         *
         * @param[in/out] io_attentions List of attentions
         */
        void resolveOcmbs( const TARGETING::TargetHandle_t i_proc,
                           AttentionList & io_attentions );
        /**
         * @brief Clears the iv_ocmbChnlFail map
         */
        void clearChnlFailMap() { iv_ocmbChnlFail.clear(); }

        /**
         * @brief dtor
         */
        ~MemOps();

        /**
         * @brief ctor
         */
        MemOps();
};
}
#endif
