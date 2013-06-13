/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdrCommon.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2013              */
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

#ifndef __PRDRCOMMON_H
#define __PRDRCOMMON_H

/**
 * @file prdrCommon.H
 * @brief Common enums, typedefs, etc. between compiler and loader for rule
 * table code.
 */

#include <map>
#include <stdint.h>

#ifdef __PRD_RULE_COMPILE
  #include <string>
#endif

/**
 * @namespace Prdr
 * @brief Namespace to encapsulate Prdr specific enums, classes, and typedefs.
 */
namespace Prdr
{

    enum NumberOfAttentions
    {
        NUM_GROUP_ATTN = 4,
    };

    /**
     * @enum RegisterFlags
     * @brief Flags for which register attributes are contained in a register
     * definition.
     *
     * When loading the .prf file, each register entry will contain a set of
     * these flags that describe what attributes are non-default (and therefore
     * contained in the file).
     */
    enum RegisterFlags
    {
        PRDR_REGISTER_SCOMLEN       = 0x01, ///< Non-default scomlen
        PRDR_REGISTER_RESETS        = 0x02, ///< Resets defined
        PRDR_REGISTER_MASKS         = 0x04, ///< Masks defined
        PRDR_REGISTER_CAPTURE       = 0x08, ///< Capture requirements
        PRDR_REGISTER_ACCESS_NIL    = 0x10, ///< FFDC only register
        PRDR_REGISTER_READ          = 0x20, ///< Read only register
        PRDR_REGISTER_WRITE         = 0x40, ///< Write only register
    };

    /**
     * @enum GroupFlags
     * @brief Flags for which group attributes are contained in a group
     * definition.
     *
     * When loading the .prf file, each group entry will contain a set of
     * these flags that describe what attributes are non-default (and therefore
     * contained in the file).
     */
    enum GroupFlags
    {
            /** Single Bit Filter */
        PRDR_GROUP_FILTER_SINGLE_BIT = 0x1,
            /** Priority Bit Filter */
        PRDR_GROUP_FILTER_PRIORITY = 0x2,
    };

    /**
     * @enum TimeBaseFlags
     * @brief Enums for time base
     *
     * When reading rule file, these flags can be used to write in prf files
     * for time base values.
     */
    enum TimeBaseFlags
    {
        PRDR_TIME_BASE_SEC  = 1,
        PRDR_TIME_BASE_MIN  = PRDR_TIME_BASE_SEC  * 60,
        PRDR_TIME_BASE_HOUR = PRDR_TIME_BASE_MIN  * 60,
        PRDR_TIME_BASE_DAY  = PRDR_TIME_BASE_HOUR * 24,
    };

    /**
     * @enum ExprOps
     * @brief Single char op's defined for .prf files.
     *
     * Needed for properly reading/writing .prf files.
     */
    enum ExprOps
    {
        REF_RULE  = 'r',
        REF_REG   = 'e',
        REF_GRP   = 'g',
        REF_ACT   = 'a',
        INTEGER   = 'I',
        INT_SHORT = 'i',
        BIT_STR   = 'B',
        NOT       = '~',
        AND       = '&',
        OR        = '|',
        XOR       = '^',
        LSHIFT    = 174, // ASCII left-shift
        RSHIFT    = 175, // ASCII right-shift
        RULE      = 'R',
        GROUP     = 'G',
        ACTION    = 'A',

        ATTNLINK  = 'L',

        ACT_THRES = 't',
        ACT_ANALY = 'y',
        ACT_TRY   = '{',
        ACT_DUMP  = 'd',
        ACT_GARD  = '-',
        ACT_CALL  = 'c',
        ACT_FUNC  = 'f',
        ACT_FLAG  = 'F',
        ACT_CAPT  = 'C',
    };

    class SignatureOp
    {
      public:
        enum { DEFAULT_SIGNATURE = 0x0 };

        static uint16_t combineSig( uint16_t a, uint16_t b )
        {
            // The two signature will be XOR'd together and there is a
            // possibility that the signature could be the same, which would
            // result in 0. So, rotate the first signature to essentially
            // scramble it. This should be able to create a unique signature.
            a = ((a & 0xff80) >> 7) | ((a & 0x007f) << 9); // rotate left 9 bits
            return ( (a ^ b) & 0xffff );
        };
    };

    #ifdef __PRD_RULE_COMPILE
    typedef std::map<uint16_t, std::string> HashCollisionMap;
    #endif

} // end namespace Prdr

#endif

