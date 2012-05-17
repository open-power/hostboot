//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/attn/attnfwd.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __ATTN_ATTNFWD_H
#define __ATTN_ATTNFWD_H

/**
 * @file attnfwd.H
 *
 * @brief HBATTN forward declarations.
 */

#include <intr/interrupt.H>
#include <errl/errlentry.H>
#include <diag/prdf/prdf_proto.H>
#include <targeting/common/target.H>
#include <vector>
#include <builtins.h>

class AttnTraceTest;
class AttnSvcTest;
class AttnListTest;
class AttnOpsTest;

namespace ATTN
{

class Attention;
class AttentionList;
class AttentionOps;
class PrdWrapper;
class PrdImpl;
class ResolverWrapper;
class Resolver;

/**
 * @brief MessageType Attention service message types.
 */
enum MessageType
{
    /**
     * @brief ATTENTION Attention message.
     */
    ATTENTION = INTR::ATTENTION,

    /**
     * @brief SHUTDOWN Shutdown message.
     */
    SHUTDOWN,
};

/**
 * @brief getPrdWrapper PrdWrapper singleton access.
 *
 * @return PrdWrapper Singleton instance.
 */
PrdWrapper & getPrdWrapper();

/**
 * @brief getResolverWrapper ResolverWrapper singleton access.
 *
 * @return ResolverWrapper Singleton instance.
 */
ResolverWrapper & getResolverWrapper();

/**
 * @brief compare compare two PRDF::AttnData structures.
 *
 * @param[in] i_l one of two AttnData structures.
 * @param[in] i_r one of two AttnData structures.
 *
 * @raturn int64_t The result of the comparison.
 *
 * @retval[-1] i_l < i_r
 * @retval[1] i_r < i_l
 * @retval[0] equivalent
 */
int64_t compare(const PRDF::AttnData & i_l, const PRDF::AttnData & i_r);

}
#endif
