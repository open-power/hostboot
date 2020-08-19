/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrLoadChip.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef __PRDRLOADCHIP_H
#define __PRDRLOADCHIP_H

/**
 * @file prdrLoadChip.H
 * @brief Describes classes and enums needed to load a .prf file.
 */


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <stdint.h>

#include <errlentry.H>
#include <utilstream.H>

#include <vector>

#include <prdrCommon.H>
#include <targeting/common/target.H>

//--------------------------------------------------------------------

/**
 * @namespace Prdr
 * @brief Namespace to encapsulate Prdr specific enums, classes, and typedefs.
 */
namespace Prdr
{
    /**
     * @brief read string data out from the stream
     * @note  caller must call delete[] to release the buffer
     */
    void ReadString(UtilStream & i_stream, char *& o_string);

    /**
     * @class Register
     * @brief Holds data associated with a register.
     */
    class Register
    {
        public:
            uint16_t        cv_name;         /** hash id of Register Short Name */

            uint32_t        cv_flags;         /** Attribute flags */

            uint64_t        cv_scomAddr;         /** Scom Address */
            uint16_t        cv_scomLen;         /** Scom Length */

            Register();
            ~Register();

            struct ResetOrMaskStruct
            {
                char op;
                uint64_t addr_r;
                uint64_t addr_w;

                friend UtilStream& operator>>(UtilStream& i_left,
                                              ResetOrMaskStruct & i_right)
                {
                    return (i_left >> i_right.op
                                   >> i_right.addr_r
                                   >> i_right.addr_w);
                };
            };

            std::vector<ResetOrMaskStruct> cv_resets;
            std::vector<ResetOrMaskStruct> cv_masks;

            struct CaptureInfoStruct
            {
                uint8_t op;
                uint32_t data[2];
                char* func;

                friend UtilStream& operator>>(UtilStream& i_left,
                                              CaptureInfoStruct & i_right)
                {
                    i_left >> i_right.op;
                    int loopMax = 0;
                    switch (i_right.op)
                    {
                        case 'G':
                        case 'T':
                        case 'P':
                            loopMax = 1;
                            break;

                        case 'C':
                            loopMax = 2;
                            break;

                        case 'f':
                            loopMax = 0;
                            break;
                    }

                    for (int i = 0; i < loopMax; i++)
                        i_left >> i_right.data[i];

                    i_right.func = nullptr;

                    if ('f' == i_right.op)
                    {
                        ReadString(i_left, i_right.func);
                    }

                    return i_left;
                }
            };

            std::vector<CaptureInfoStruct> cv_captures;

    };

    /**
     * @class Expr
     * @brief Contains data for the basic rule object, the "expression".
     */
    class Expr
    {
        public:
            union value { uint32_t i; Expr * p; };

                    /** Maximum number of entries a expression can have. */
            static const uint32_t MAX_VALUES = 7;

            unsigned char cv_op;        /** Type of expr this is. */

            // Arrays for the expression entries.  cv_deletePtr remembers if
            // the p-value should be 'deleted' when we destruct this object.
            bool        cv_deletePtr[MAX_VALUES];
            value        cv_value[MAX_VALUES];

            // action function pointer
            char * cv_actFunc;
            // vector of bit string data
            std::vector<uint64_t> cv_bitStrVect;

            /**
             * @func Expr()
             * @brief Default constructor.  Clear entry arrays.
             */
            Expr();

            /**
             * @func ~Expr()
             * @brief Default destructor.  Delete all attached pointers, as
             * requested.
             */
            ~Expr();

        private:
            // Don't let us copy these things, we don't want to mess with the
            // pointer tree.
            Expr(const Expr & i_copy) {};
    };

    class Chip
    {
        public:
            uint32_t        cv_chipId;
            TARGETING::TYPE cv_targetType;
            uint32_t        cv_signatureOffset; // Offset for error register ids.
            uint32_t        cv_dumpType;        // default dump content type.
            uint16_t        cv_scomLen;         // default scom length.
            uint16_t        cv_regCount;
            Register *      cv_registers;
            uint16_t        cv_ruleCount;
            Expr *          cv_rules;
            uint16_t        cv_groupCount;
            uint16_t        cv_groupAttn[MAX_NUM_ATTN_TYPES];
            uint16_t *      cv_groupSize;
            uint8_t *       cv_groupFlags;
            Expr **         cv_groupPriorityBits;
            Expr **         cv_groupCsRootCauseBits;
            Expr **         cv_groups;
            uint16_t        cv_actionCount;
            uint16_t *      cv_actionSize;
            Expr **         cv_actions;

            Chip() : cv_regCount(0), cv_registers(nullptr),
                         cv_ruleCount(0), cv_rules(nullptr),
                         cv_groupCount(0), cv_groupSize(nullptr),
                         cv_groupFlags(nullptr), cv_groupPriorityBits(nullptr),
                         cv_groupCsRootCauseBits(nullptr), cv_groups(nullptr),
                         cv_actionCount(0), cv_actionSize(nullptr),
                         cv_actions(nullptr)
            {
            };

            ~Chip()
            {
                if (nullptr != cv_registers) delete[] cv_registers;
                if (nullptr != cv_rules) delete[] cv_rules;
                for (int i = 0; i < cv_groupCount; i++)
                {
                    if (nullptr != cv_groupPriorityBits[i])
                        delete cv_groupPriorityBits[i];

                    if ( nullptr != cv_groupCsRootCauseBits[i] )
                        delete cv_groupCsRootCauseBits[i];

                    if (nullptr != cv_groups[i])
                        delete[] cv_groups[i];
                }
                if (nullptr != cv_groups) delete[] cv_groups;
                if (nullptr != cv_groupSize) delete[] cv_groupSize;
                if (nullptr != cv_groupFlags) delete[] cv_groupFlags;
                if (nullptr != cv_groupPriorityBits) delete[] cv_groupPriorityBits;
                if ( nullptr != cv_groupCsRootCauseBits )
                    delete[] cv_groupCsRootCauseBits;
                for (int i = 0; i < cv_actionCount; i++)
                    if (nullptr != cv_actions[i]) delete[] cv_actions[i];
                if (nullptr != cv_actions) delete[] cv_actions;
                if (nullptr != cv_actionSize) delete[] cv_actionSize;
            };
    };

    errlHndl_t LoadChip(UtilStream & i_stream, Chip & o_chip);

} // end namespace Prdr

#endif
