/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/rt_targeting.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#ifndef __RT_TARGETING_H
#define __RT_TARGETING_H

#include <errl/errlentry.H>

namespace TARGETING
{
    class Target;
}

namespace RT_TARG
{
    typedef uint64_t rtChipId_t;

    enum
    {
        CHIPID_NODE_SHIFT = 3,  //!< CHIPID NODE is 'NNNCCC'b
        MEMBUF_ID_SHIFT = 4,    //!< CHIPID for MEMBUF is 'NNNCCCMMMM'b
        UNIT_ID_SHIFT   = 4,    //!< CHIPID for CORE is 'NNNCCCPPPP'b
        UNIT_ID_MASK    = 0x000003ff, //!< Valid id bits w/o ID_FLAG
        PROC_ID_TYPE    = 0x00000000, //!< PROC chip id type
        MEMBUF_ID_TYPE  = 0x80000000, //!< MEMBUF chip id type
        CORE_ID_TYPE    = 0x40000000, //!< CORE/EX chip id type
        CHIPID_ID_MASK  = 0xFF000000, //!< TYPE field
    };


    /**
     * @brief Convert a TARGETING::Target to an unit ID that can be used
     * in calls to Sapphire
     * @param[in] The HB TARGETING::Target
     * @param[out] Sapphire target id
     * @return an error handle on error
     */
    errlHndl_t getRtTarget(const TARGETING::Target* i_target,
                           rtChipId_t &o_targetId);

    /**
     * @brier Convert a runtime chip_id (target) into a TARGETING::Target
     * @param[in] The rt chipId
     * @param[out] The TARGETING::Target pointer
     * @return error log handle on error else NULL
     */
    errlHndl_t getHbTarget(rtChipId_t i_rt_chip_id,
                           TARGETING::Target *& o_target);
};

#endif
