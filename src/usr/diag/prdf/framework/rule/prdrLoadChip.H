/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/rule/prdrLoadChip.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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
    void prdrReadString(UtilStream & i_stream, char *& o_string);

    /**
     * @class PrdrRegister
     * @brief Holds data associated with a register.
     */
    class PrdrRegister
    {
        public:
            uint16_t        cv_name;         /** hash id of Register Short Name */

            uint32_t        cv_flags;         /** Attribute flags */

            uint64_t        cv_scomAddr;         /** Scom Address */
            uint16_t        cv_scomLen;         /** Scom Length */

            PrdrRegister();
            ~PrdrRegister();

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
                char * func;

                friend UtilStream& operator>>(UtilStream& i_left,
                                              CaptureInfoStruct & i_right)
                {
                    i_left >> i_right.op;
                    int loopMax = 0;
                    switch (i_right.op)
                    {
                        case 'G':
                        case 'T':
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

                    i_right.func = NULL;
                    if ('f' == i_right.op)
                    {
                        prdrReadString(i_left, i_right.func);
                    }

                    return i_left;
                }
            };

            std::vector<CaptureInfoStruct> cv_captures;

    };

    /**
     * @class PrdrExpr
     * @brief Contains data for the basic rule object, the "expression".
     */
    class PrdrExpr
    {
        public:
            union value { uint32_t i; PrdrExpr * p; };

                    /** Maximum number of entries a expression can have. */
            static const uint32_t MAX_VALUES = 6;

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
             * @func PrdrExpr()
             * @brief Default constructor.  Clear entry arrays.
             */
            PrdrExpr();

            /**
             * @func ~PrdrExpr()
             * @brief Default destructor.  Delete all attached pointers, as
             * requested.
             */
            ~PrdrExpr();

        private:
            // Don't let us copy these things, we don't want to mess with the
            // pointer tree.
            PrdrExpr(const PrdrExpr & i_copy) {};
    };

    class PrdrChip
    {
        public:
            uint32_t        cv_chipId;
            TARGETING::TYPE cv_targetType;
            uint32_t        cv_signatureOffset; // Offset for error register ids.
            uint32_t        cv_dumpType;        // default dump content type.
            uint16_t        cv_scomLen;         // default scom length.
            uint16_t        cv_regCount;
            PrdrRegister *  cv_registers;
            uint16_t        cv_ruleCount;
            PrdrExpr *      cv_rules;
            uint16_t        cv_groupCount;
            uint16_t        cv_groupAttn[NUM_GROUP_ATTN];
            uint16_t *      cv_groupSize;
            uint8_t *       cv_groupFlags;
            PrdrExpr **     cv_groupPriorityBits;
            PrdrExpr **     cv_groups;
            uint16_t        cv_actionCount;
            uint16_t *      cv_actionSize;
            PrdrExpr **     cv_actions;

            PrdrChip() : cv_regCount(0), cv_registers(NULL),
                         cv_ruleCount(0), cv_rules(NULL),
                         cv_groupCount(0), cv_groupSize(NULL),
                         cv_groupFlags(NULL), cv_groupPriorityBits(NULL),
                         cv_groups(NULL),
                         cv_actionCount(0), cv_actionSize(NULL),
                         cv_actions(NULL)
            {
            };

            ~PrdrChip()
            {
                if (NULL != cv_registers) delete[] cv_registers;
                if (NULL != cv_rules) delete[] cv_rules;
                for (int i = 0; i < cv_groupCount; i++)
                {
                    if (NULL != cv_groupPriorityBits[i])
                        delete cv_groupPriorityBits[i];
                    if (NULL != cv_groups[i])
                        delete[] cv_groups[i];
                }
                if (NULL != cv_groups) delete[] cv_groups;
                if (NULL != cv_groupSize) delete[] cv_groupSize;
                if (NULL != cv_groupFlags) delete[] cv_groupFlags;
                if (NULL != cv_groupPriorityBits) delete[] cv_groupPriorityBits;
                for (int i = 0; i < cv_actionCount; i++)
                    if (NULL != cv_actions[i]) delete[] cv_actions[i];
                if (NULL != cv_actions) delete[] cv_actions;
                if (NULL != cv_actionSize) delete[] cv_actionSize;
            };
    };

    errlHndl_t prdrLoadChip(UtilStream & i_stream, PrdrChip & o_chip);

};
#endif
