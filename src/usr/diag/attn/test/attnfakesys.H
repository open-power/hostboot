/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakesys.H $
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
#ifndef __TEST_ATTNFAKESYS_H
#define __TEST_ATTNFAKESYS_H

/**
 * @file attnfakesys.H
 *
 * @brief HBATTN fake system class definition.
 */

#include "../attnfwd.H"
#include "../attnops.H"
#include "../attnprd.H"
#include "../attnresolv.H"
#include "../attnscom.H"
#include <map>

namespace ATTN
{

/**
 * @brief Event fake system event trace types.
 */
enum Event
{
    /**
     * @brief MASK_EVENT A simulated attention was masked.
     */
    MASK_EVENT,

    /**
     * @brief UNMASK_EVENT A simulated attention was unmasked.
     */
    UNMASK_EVENT,

    /**
     * @brief QUERY_EVENT A simulated attention was queried.
     */
    QUERY_EVENT,

    /**
     * @brief CALLPRD_EVENT A simulated attention was forwarded to PRD.
     */
    CALLPRD_EVENT,
};

/**
 * @brief FakeSystemProperties data associated with a simulated attention.
 */
struct FakeSystemProperties
{
    /**
     * @brief mask The mask state of the simulated attention.
     */
    bool mask;

    /**
     * @brief active The state of the simulated attention.
     */
    bool active;

    /**
     * @brief count The number of times the simulated attention has occurred.
     */
    uint64_t count;

    /**
     * @brief history Simlated aattention trace.
     */
    std::vector<uint64_t> history;

    /**
     * @brief ctor
     */
    FakeSystemProperties() : mask(false), active(false), count(0) {}
};

/**
 * @brief Comp Comparison functor for two PRDF::AttnData structs.
 */
struct Comp
{
    /**
     * @brief operator() Comparison functor for two PRDF::AttnData structs.
     *
     * @param[in] i_l One of two PRDF::AttnData structs to be compared.
     * @param[in] i_r One of two PRDF::AttnData structs to be compared.
     *
     * @return bool Comparison result.
     *
     * @retval[true] i_l < i_r;
     * @retval[false ] i_r < i_l;
     */
    bool operator()(const PRDF::AttnData & i_l,
            const PRDF::AttnData & i_r) const
    {
        return compare(i_l,  i_r) < 0;
    }
};

/**
 * @brief FakeSystem
 *
 * AttentionOps, Resolver and PRD implementations that simulate
 * normal system behavior.
 */
class FakeSystem :
    public AttentionOps,
    public Resolver,
    public PrdImpl,
    public ScomImpl
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
         * @brief mask Mask this attention.
         *
         * @param[in] i_data the attention to be masked.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t mask(const PRDF::AttnData & i_data);

        /**
         * @brief unmask Unmask this attention.
         *
         * @param[in] i_data the attention to be unmasked.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t unmask(const PRDF::AttnData & i_data);

        /**
         * @brief query Test to see if this attention is active.
         *
         * @param[in] i_data the attention to be queried.
         * @param[out] o_active true if attention is active.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t query(const PRDF::AttnData & i_data,
                bool & o_active);

        /**
         * @brief resolve Find attentions of the supplied type on the
         *        supplied target.
         *
         * @param[in] i_proc The proc on which to look for attentions.
         * @param[out] o_attentions Where to put attentions when found.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t resolve(
                TARGETING::TargetHandle_t i_proc,
                AttentionList & o_attentions);

        /**
         * @brief callPrd Simulate a call to PRD.
         *
         * @param[in] i_attentions List of attentions for PRD to analyze.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t callPrd(const AttentionList & i_attentions);

        /**
         * @brief install install this class as the prd and resolver
         *        implementation.
         */
        void install();

        /**
         * @brief raiseAttentions Attempt to raise random attentions.
         *
         * @param[in] i_q The message Q where simulated attention
         *                messages should be sent.
         * @param[i_count] The number of attentions to generate.
         *
         * @return The actual number of attentions raised.
         */
        uint64_t raiseAttentions(msg_q_t i_q, uint64_t i_count);

        /**
         * @brief validate Perform validation of the simulated system.
         *
         * @return The result of the validation.
         *
         * @retval[true] Result is valid.
         * @retval[false] Result is invalid.
         */
        virtual bool validate();

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
         * @brief generateAttentions Generate random attentions.
         *
         * @param[in] i_count The number of attentions to generate.
         * @param[in/out] io_list Where generated attentions are placed.
         *
         * @return uint64_t The actual number of attentions generated.
         */
        uint64_t generateAttentions(uint64_t i_count, PRDF::AttnList & io_list);

        /**
         * @brief iv_map Attention <-> state association.
         */
        std::map<PRDF::AttnData, FakeSystemProperties, Comp> iv_map;

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
         * @brief iv_mutex iv_map protection.
         */
        mutex_t iv_mutex;
};
}
#endif
