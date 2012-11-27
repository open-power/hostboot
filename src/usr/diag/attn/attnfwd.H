/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnfwd.H $                                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef __ATTN_ATTNFWD_H
#define __ATTN_ATTNFWD_H

/**
 * @file attnfwd.H
 *
 * @brief HBATTN forward declarations.
 */

#include <attn/attn.H>
#include <intr/interrupt.H>
#include <errl/errlentry.H>
#include <diag/prdf/common/prdfMain.H>
#include <targeting/common/target.H>
#include <vector>
#include <builtins.h>
#include "attnbits.H"

class AttnTraceTest;
class AttnSvcTest;
class AttnListTest;
class AttnOpsTest;
class AttScomTest;
class AttnProcTest;
class AttnMemTest;

namespace ATTN
{

class Attention;
class AttentionList;
class AttentionOps;
class PrdWrapper;
class PrdImpl;
class TargetService;
class TargetServiceImpl;
class ScomWrapper;
class ScomImpl;
class ProcOps;
class MemOps;

enum
{
    /**
     * @brief HOST Represents host attentions,
     *         distinct from the local error attentions.
     */
    HOST = PRDF::END_ATTENTION_TYPE,
};

/**
 * @brief MessageType Attention service message types.
 */
enum MessageType
{
    /**
     * @brief ATTENTION Attention message.
     */
    ATTENTION = 0x1,

    /**
     * @brief SHUTDOWN Shutdown message.
     */
    SHUTDOWN,
};

/**
 * @brief ScomOp ModifyScom operation types.
 */
enum ScomOp
{
    /**
     * @brief SCOM_OR ModifyScom or operation.
     */
    SCOM_OR,

    /**
     * @brief SCOM_AND ModifyScom and operation.
     */
    SCOM_AND,
};

/**
 * @brief getScom Read a register using SCOM.
 *
 * @param[in] i_target Target to read register from.
 * @param[in] i_address Register address to read from.
 * @param[in] i_data Buffer to write register content to.
 *
 * @retval[0] No errors.
 * @retval[!0] Unexpected error occurred.
 */
errlHndl_t getScom(
        TARGETING::TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t & o_data);

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
 * @brief modifyScom Read/Modify/Write a register using SCOM.
 *
 * @param[in] i_target Target to write register on.
 * @param[in] i_address Register address to write to.
 * @param[in] i_data Data to write to register.
 * @param[in] i_op And/Or specification.
 *
 * @retval[0] No errors.
 * @retval[!0] Unexpected error occurred.
 */
errlHndl_t modifyScom(
        TARGETING::TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data,
        ScomOp i_op);

/**
 * @brief getScomWrapper ScomWrapper singleton access.
 *
 * @return ScomWrapper Singleton instance.
 */
ScomWrapper & getScomWrapper();

/**
 * @brief getPrdWrapper PrdWrapper singleton access.
 *
 * @return PrdWrapper Singleton instance.
 */
PrdWrapper & getPrdWrapper();

/**
 * @brief getTargetService TargetService singleton access.
 *
 * @return TargetService Singleton instance.
 */
TargetService & getTargetService();

/**
 * @brief getProcOps ProcOps singleton access.
 *
 * @return ProcOps Singleton instance.
 */
ProcOps & getProcOps();

/**
 * @brief getMemOps MemOps singleton access.
 *
 * @return MemOps Singleton instance.
 */
MemOps & getMemOps();

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
