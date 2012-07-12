/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfaketarget.H $
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
#ifndef __TEST_ATTNFAKETARGET_H
#define __TEST_ATTNFAKETARGET_H

/**
 * @file attnfaketarget.H
 *
 * @brief HBATTN fake targeting class definitions.
 */

#include "attntest.H"
#include "../attntarget.H"

namespace ATTN
{

/**
 * @brief FakeProcTargetService
 *
 * A fake service for supporting processor only configurations.
 */
class FakeProcTargetService : public TargetServiceImpl
{
    public:

        /**
         * @brief getProc
         *
         * @param[in] i_pos
         *
         * @return
         */
        TARGETING::TargetHandle_t getProcFromPos(uint64_t i_pos);

        /**
         * @brief getProcPos
         *
         * @param[in] i_proc
         *
         * @return
         */
        uint64_t getProcFromTarget(TARGETING::TargetHandle_t i_proc);

        /**
         * @brief getAllChips Get a list of chips.
         *
         * @param[out] o_list The populated list of chips.
         * @param[in] i_type The type of chip for which a list
         *              should be obtained.
         * @param[in] i_functional functional chip filter.
         */
        virtual void getAllChips(
                TARGETING::TargetHandleList & o_list,
                TARGETING::TYPE i_type,
                bool i_functional = true);

        /**
         * @brief getMcsList Obtain the list of MCS unit targets
         *           for the given proc chip target.
         *
         * Not implemented for processor only configurations.
         *
         * @param[in] i_proc The proc chip target for which a
         *              list of MCS unit targets should be obtained.
         * @param[out] o_list The populated list of MCS unit targets.
         */
        virtual void getMcsList(
                TARGETING::TargetHandle_t i_proc,
                TARGETING::TargetHandleList & o_list)
        {

        }

        /**
         * @brief getProc Find the requested membuf chip
         *           target parent proc chip target.
         *
         * @param[in] i_membuf The membuf chip target
         *             for which the parent proc chip target
         *             should be found.
         *
         * Not implemented for processor only configurations.
         *
         * @retval[0] Did not find any associated proc chip target.
         * @retval[!0] Associated proc chip parent target.
         */
        virtual TARGETING::TargetHandle_t getProc(
                TARGETING::TargetHandle_t i_membuf)
        {
            return 0;
        }

        /**
         * @brief getMcs Find the requested membuf chip
         *           target parent MCS unit target.
         *
         * @param[in] i_membuf The membuf chip target
         *             for which the parent MCS unit target
         *             should be found.
         *
         * Not implemented for processor only configurations.
         *
         * @retval[0] Did not find any associated MCS unit target.
         * @retval[!0] Associated MCS unit parent target.
         */
        virtual TARGETING::TargetHandle_t getMcs(
                TARGETING::TargetHandle_t i_membuf)
        {
            return 0;
        }

        /**
         * @brief getMcs Find the MCS unit target given
         *           the proc chip parent target and MCS position.
         *
         * @param[in] i_proc The proc chip target for which the
         *                MCS unit target should be found.
         * @param[in] i_pos The MCS unit position for which the MCS
         *                unit target should be found.
         *
         * Not implemented for processor only configurations.
         *
         * @retval[0] Did not find any associated MCS unit target.
         * @retval[!0] Associated MCS unit target.
         */
        virtual TARGETING::TargetHandle_t getMcs(
                TARGETING::TargetHandle_t i_proc,
                uint64_t i_pos)
        {
            return 0;
        }

        /**
         * @brief getMcsPos Find the MCS unit position given
         *           the MCS unit target.
         *
         * Not implemented for processor only configurations.
         *
         * @param[in] i_mcs The MCS unit target for which the
         *                MCS unit position should be found.
         * @param[out] o_pos The MCS unit position.
         */
        virtual void getMcsPos(
                TARGETING::TargetHandle_t i_mcs,
                uint64_t & o_pos)
        {

        }

        /**
         * @brief getMembuf Find the requested MCS unit target
         *           child membuf chip target.
         *
         * @param[in] i_mcs The MCS unit target
         *             for which the child membuf chip target
         *             should be found.
         *
         * Not implemented for processor only configurations.
         *
         * @retval[0] Did not find any associated membuf chip target.
         * @retval[!0] Associated membuf chip target.
         */
        virtual TARGETING::TargetHandle_t getMembuf(
                TARGETING::TargetHandle_t i_mcs)
        {
            return 0;
        }

        /**
         * @brief getType Obtain the type of the provided target.
         *
         * Returns Hardcoded to TYPE_PROC for anything passed in.
         *
         * @param[in] i_target The target for which the type
         *                should be obtained.
         *
         * @return The type of the provided target.
         */
        virtual TARGETING::TYPE getType(TARGETING::TargetHandle_t i_target)
        {
            return TARGETING::TYPE_PROC;
        }

        /**
         * @brief dtor
         */
        virtual ~FakeProcTargetService() {}

        /**
         * @brief ctor
         *
         * @param[in] i_count The number of processor targets.
         */
        explicit FakeProcTargetService(uint64_t i_count);

    private:

        /**
         * @brief iv_procs The fake processor targets.
         */
        TARGETING::TargetHandleList iv_procs;
};

/**
 * @brief FakeProcTargetService
 *
 * A fake service for supporting processor and membuf configurations.
 * Provides a hardcoded number of fake membuf targets, and a mapping
 * between them and an externally provided array of processor targets.
 */
class FakeMemTargetService : public FakeProcTargetService
{
    public:

        /**
         * @brief getAllChips Get a list of chips.
         *
         * @param[out] o_list The populated list of chips.
         * @param[in] i_type The type of chip for which a list
         *              should be obtained.
         * @param[in] i_functional functional chip filter.
         */
        void getAllChips(
                TARGETING::TargetHandleList & o_list,
                TARGETING::TYPE i_type,
                bool i_functional = true);

        /**
         * @brief getMcsList Obtain the list of MCS unit targets
         *           for the given proc chip target.
         *
         * @param[in] i_proc The proc chip target for which a
         *              list of MCS unit targets should be obtained.
         * @param[out] o_list The populated list of MCS unit targets.
         */
        void getMcsList(
                TARGETING::TargetHandle_t i_proc,
                TARGETING::TargetHandleList & o_list);

        /**
         * @brief getProc Find the requested membuf chip
         *           target parent proc chip target.
         *
         * @param[in] i_membuf The membuf chip target
         *             for which the parent proc chip target
         *             should be found.
         *
         * @retval[0] Did not find any associated proc chip target.
         * @retval[!0] Associated proc chip parent target.
         */
        TARGETING::TargetHandle_t getProc(
                TARGETING::TargetHandle_t i_membuf);

        /**
         * @brief getMcs Find the requested membuf chip
         *           target parent MCS unit target.
         *
         * @param[in] i_membuf The membuf chip target
         *             for which the parent MCS unit target
         *             should be found.
         *
         * @retval[0] Did not find any associated MCS unit target.
         * @retval[!0] Associated MCS unit parent target.
         */
        TARGETING::TargetHandle_t getMcs(
                TARGETING::TargetHandle_t i_membuf);

        /**
         * @brief getMcs Find the MCS unit target given
         *           the proc chip parent target and MCS position.
         *
         * @param[in] i_proc The proc chip target for which the
         *                MCS unit target should be found.
         * @param[in] i_pos The MCS unit position for which the MCS
         *                unit target should be found.
         *
         * @retval[0] Did not find any associated MCS unit target.
         * @retval[!0] Associated MCS unit target.
         */
        TARGETING::TargetHandle_t getMcs(
                TARGETING::TargetHandle_t i_proc,
                uint64_t i_pos);

        /**
         * @brief getMcsPos Find the MCS unit position given
         *           the MCS unit target.
         *
         * @param[in] i_mcs The MCS unit target for which the
         *                MCS unit position should be found.
         * @param[out] o_pos The MCS unit position.
         */
        void getMcsPos(
                TARGETING::TargetHandle_t i_mcs,
                uint64_t & o_pos);

        /**
         * @brief getMembuf Find the requested MCS unit target
         *           child membuf chip target.
         *
         * @param[in] i_mcs The MCS unit target
         *             for which the child membuf chip target
         *             should be found.
         *
         * @retval[0] Did not find any associated membuf chip target.
         * @retval[!0] Associated membuf chip target.
         */
        TARGETING::TargetHandle_t getMembuf(
                TARGETING::TargetHandle_t i_mcs);

        /**
         * @brief getType Obtain the type of the provided target.
         *
         * @param[in] i_target The target for which the type
         *                should be obtained.
         *
         * @return The type of the provided target.
         */
        TARGETING::TYPE getType(
                TARGETING::TargetHandle_t i_target);

        /**
         * @brief dump print configuration to trace.
         */
        void dump();

        /**
         * @brief dtor
         */
        ~FakeMemTargetService();

        /**
         * @brief ctor
         *
         * @param[in] i_firstProc The first proc target for
         *                which to generate membuf mappings.
         * @param[in] i_lastProc Past the last proc target for which
         *                to generate membuf mappings.
         */
        explicit FakeMemTargetService(uint64_t i_count);

    private:

        TARGETING::TargetHandleList iv_mcses;
        TARGETING::TargetHandleList iv_membufs;

        /**
         * @brief iv_first The first proc target for which to
         *           generate mappings.
         */
        TARGETING::TargetHandle_t iv_first;

        /**
         * @brief iv_firstMcs The first mcs target for
         *              which to generate mappings.
         */
        TARGETING::TargetHandle_t iv_firstMcs;

        /**
         * @brief iv_firstMcs The first membuf target for
         *              which to generate mappings.
         */
        TARGETING::TargetHandle_t iv_firstMembuf;

        /**
         * @brief cv_membufsPerProc The number of membuf targets
         *            per proc target for which mappings should
         *            be generated.
         */
        static const uint64_t cv_membufsPerProc = 8;
};
}
#endif
