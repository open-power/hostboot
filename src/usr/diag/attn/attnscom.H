/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnscom.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __ATTN_ATTNSCOM_H
#define __ATTN_ATTNSCOM_H

/**
 * @file attnscom.H
 *
 * @brief HBATTN SCOM abstraction layer definitions.
 */

#include "attnfwd.H"

namespace ATTN
{

/**
 * @brief ScomImpl SCOM interface requirement.
 *
 * This default implementation routes SCOM calls to real hardware.
 */
class ScomImpl
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
        virtual errlHndl_t putScom(
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
        virtual errlHndl_t getScom(
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
        virtual errlHndl_t modifyScom(
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data,
                uint64_t & o_data,
                ScomOp i_op);

        /**
         * @brief installScomImpl
         *
         * Set this as the active scom implementation.
         */
        void installScomImpl();

        /**
         * @brief dtor
         */
        virtual ~ScomImpl() {}

        /**
         * @brief ctor
         */
        ScomImpl() {}

    private:

        /**
         * @brief copy Disabled.
         */
        ScomImpl(const ScomImpl &);

        /**
         * @brief assignment Disabled.
         */
        ScomImpl & operator=(const ScomImpl &);
};

/**
 * @brief ScomWrapper Holds the installed SCOM implementation.
 */
class ScomWrapper
{
    public:

        /**
         * @brief setImpl Change the SCOM implementation to be used.
         *
         * @param[in] i_impl The new implemenation to use.
         */
        void setImpl(ScomImpl & i_impl)
        {
            iv_impl = &i_impl;
        }

        /**
         * @brief putScom Write a register using SCOM.
         *
         * Routes to the current SCOM implementation.
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
         * Routes to the current SCOM implementation.
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
        ScomWrapper();

    private:

        /**
         * @brief iv_impl The SCOM implementation to
         *            which calls should be forwarded.
         */
        ScomImpl * iv_impl;

        /**
         * @brief copy Disabled.
         */
        ScomWrapper(const ScomWrapper &);

        /**
         * @brief assignment Disabled.
         */
        ScomWrapper & operator=(const ScomWrapper &);
};
}
#endif
