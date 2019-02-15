/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/util.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
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
/**
 *  @file targeting/common/util.C
 *
 *  @brief Provides miscellaneous utility functions to targeting, including
 *     a check for whether system is in simulation or not.
 */

//******************************************************************************
// Includes
//******************************************************************************
#include <stdint.h>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>

namespace TARGETING
{

/**
 * @brief Checks to see if we are running in a hardware simulation
 *    environment, i.e. VPO/VBU  (not Simics)
 */
bool is_vpo( void )
{
    struct IsVpoFunctor
    {
        static bool operate()
        {
            bool rc = false;

            Target* sys = NULL;
            targetService().getTopLevelTarget(sys);

            uint8_t vpo_mode = 0;
            if (unlikely(sys &&
                         sys->tryGetAttr<ATTR_IS_SIMULATION>(vpo_mode) &&
                         (1 == vpo_mode)))
            {
                rc = true;
            }
            return rc;
        }
    };

#ifdef __HOSTBOOT_MODULE
    // In Hostboot this value cannot change, so cache it as a static.
    static bool is_vpo_mode = IsVpoFunctor::operate();
    return is_vpo_mode;
#else
    // On FSP, assumption is that the user could change this, so we cannot
    // cache it as a static.  Read from the attribute directly.
    return IsVpoFunctor::operate();
#endif
};

/**
 * @brief set HWAS Changed flag to subscription mask
 *
 *   This will be used by the HCDB service - when the target has
 *   changed, this will get called to tell the appropriate services
 *   that the change has occurred.
 */
void update_hwas_changed_mask(Target * i_target)
{
    i_target->setAttr<ATTR_HWAS_STATE_CHANGED_FLAG>(
            i_target->getAttr<ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK>());
}

/**
 * @brief set HWAS Changed flag to specific bits
 *
 *   This will be used by different services when the target needs processing.
 */
void update_hwas_changed_mask(Target * i_target, const uint64_t i_bits)
{
    i_target->setAttr<ATTR_HWAS_STATE_CHANGED_FLAG>(
            i_target->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>() |
            (i_target->getAttr<ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK>() &
                i_bits));
}

/**
 * @brief clear bit in HWAS Changed Mask
 *
 *   This will be used by the appropriate services when they have handled
 *   the change flag for this target.
 */
void clear_hwas_changed_bit(Target * i_target, const HWAS_CHANGED_BIT i_bit)
{
    ATTR_HWAS_STATE_CHANGED_FLAG_type hwasChangedState =
        i_target->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>();
    hwasChangedState &= ~i_bit;
    i_target->setAttr<ATTR_HWAS_STATE_CHANGED_FLAG>(hwasChangedState);
}

/**
 * @brief   Checks if we are loading a PHYP payload
 */
bool is_phyp_load( ATTR_PAYLOAD_KIND_type* o_type )
{
    Target* sys = NULL;
    targetService().getTopLevelTarget( sys );
    assert(sys != NULL);

    // get the current payload kind
    TARGETING::PAYLOAD_KIND payload_kind = sys->getAttr<ATTR_PAYLOAD_KIND>();

    if( o_type )
    {
        *o_type = payload_kind;
    }

    //If in AVP mode default to false
    bool is_phyp = false;
    if(!is_avp_load())
    {
        is_phyp = (PAYLOAD_KIND_PHYP == payload_kind);
    }
    return is_phyp;
 }

/**
 * @brief  Utility function to determine if Sapphire is the payload
 *
 * @description  If the payload kind is Sapphire returns true.  Does
 *    not matter if it is Sapphire with FSP or standalone
 *
 * @return bool  True when loadding sapphire
 */
bool is_sapphire_load(void)
{
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);
    bool is_sapphire = false;

    //If in AVP mode default to false
    if(!is_avp_load())
    {
        is_sapphire = (PAYLOAD_KIND_SAPPHIRE ==
                       sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>());
    }
    return is_sapphire;
}

/**
 * @brief  Utility function to determine if an AVP is the payload
 *         Note the actual payload could be something else -- this
 *         is based solely on MFG flags
 *
 * @description  If MFG AVP mode flags are set then returns true
 *      Does not matter what the actual payload is
 *
 * @return bool  True when in AVP mode
 */
bool is_avp_load(void)
{
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);

    TARGETING::ATTR_MNFG_FLAGS_type mnfg_flags =
      sys->getAttr<TARGETING::ATTR_MNFG_FLAGS>();
    return ((mnfg_flags & TARGETING::MNFG_FLAG_AVP_ENABLE)
       || (mnfg_flags & TARGETING::MNFG_FLAG_HDAT_AVP_ENABLE));
}

/**
 * @brief   Checks if we are loading no Payload (PAYLOAD_KIND_NONE)
 */
bool is_no_load(void)
{
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);
    return (PAYLOAD_KIND_NONE == sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>());
}

bool orderByNodeAndPosition(  Target* i_firstProc,
                              Target* i_secondProc)
{
    uint8_t groupId0 = i_firstProc->getAttr<ATTR_FABRIC_GROUP_ID>();
    uint8_t groupId1 = i_secondProc->getAttr<ATTR_FABRIC_GROUP_ID>();
    uint8_t fabpos0 = i_firstProc->getAttr<ATTR_FABRIC_CHIP_ID>();
    uint8_t fabpos1 = i_secondProc->getAttr<ATTR_FABRIC_CHIP_ID>();

    if (groupId0 == groupId1)
    {
        return fabpos0 < fabpos1;
    }
    return groupId0 < groupId1;
}

uint8_t  is_fused_mode( )
{
    uint8_t  l_fused;
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);

    /*
        Fused Mode

        ATTR_FUSED_CORE_MODE / ATTR_FUSED_CORE_OPTION / ATTR_PAYLOAD_KIND

        smt4_default / default_cores / phyp --> fused
        smt4_default / default_cores / opal --> notfused
        smt4_default / normal_cores  / *    --> notfused
        smt4_default / fused_cores   / *    --> fused

        smt4_only / default_cores / *   --> notfused
        smt4_only / normal_cores  / *   --> notfused
        smt4_only / fused_cores   / *   --> fused

        smt8_only / default_cores / *   --> fused
        smt8_only / normal_cores  / *   --> notfused
        smt8_only / fused_cores   / *   --> fused
    */

    uint8_t l_mode = sys->getAttr<ATTR_FUSED_CORE_MODE_HB>();;
    uint8_t l_option = sys->getAttr<ATTR_FUSED_CORE_OPTION>();;
    PAYLOAD_KIND l_payload = sys->getAttr<ATTR_PAYLOAD_KIND>();

    if (FUSED_CORE_OPTION_USING_DEFAULT_CORES == l_option)
    {
        if (FUSED_CORE_MODE_HB_SMT4_DEFAULT == l_mode)
        {
            if (PAYLOAD_KIND_PHYP == l_payload)
            {
                l_fused = true;
            }
            else
            {
                l_fused = false;
            }
        }
        else if (FUSED_CORE_MODE_HB_SMT4_ONLY == l_mode)
        {
            l_fused = false;
        }
        else // SMT8_ONLY
        {
            l_fused = true;
        }
    }
    else if (FUSED_CORE_OPTION_USING_NORMAL_CORES == l_option)
    {
        l_fused = false;
    }
    else // USING_FUSED_CORES
    {
        l_fused = true;
    }

    return(l_fused);

} // end is_fused_mode


bool isNVDIMM( const TARGETING::Target * i_target )
{
    // Not the most elegant way of doing it but the hybrid attributes
    // are at the MCS level. Need to find my way up to MCS and check
    // if the dimm is hybrid
    TARGETING::TargetHandleList l_mcaList;
    getParentAffinityTargets(l_mcaList, i_target, TARGETING::CLASS_UNIT, TARGETING::TYPE_MCA);

    if (l_mcaList.size())
    {
        TARGETING::TargetHandleList l_mcsList;
        getParentAffinityTargets(l_mcsList, l_mcaList[0], TARGETING::CLASS_UNIT, TARGETING::TYPE_MCS);

        if(l_mcsList.size())
        {
            // 2-D array. [MCA][DIMM]
            TARGETING::ATTR_EFF_HYBRID_type l_hybrid;
            TARGETING::ATTR_EFF_HYBRID_MEMORY_TYPE_type l_hybrid_type;

            if( l_mcsList[0]->tryGetAttr<TARGETING::ATTR_EFF_HYBRID>(l_hybrid) &&
                l_mcsList[0]->tryGetAttr<TARGETING::ATTR_EFF_HYBRID_MEMORY_TYPE>(l_hybrid_type) )
            {
                //Using relative position to lookup the hybrid attribute for the current dimm
                TARGETING::ATTR_REL_POS_type l_dimm_rel_pos = i_target->getAttr<ATTR_REL_POS>();
                TARGETING::ATTR_REL_POS_type l_mca_rel_pos = l_mcaList[0]->getAttr<ATTR_REL_POS>();

                // Verify code is not accessing outside of the array boundaries
                // Check if l_dimm_rel_pos is outside of l_hybrid column boundary
                assert(l_dimm_rel_pos < sizeof(l_hybrid[0]));

                // Check if l_mca_rel_pos is outside of l_hybrid row boundary
                assert(l_mca_rel_pos < (sizeof(l_hybrid)/sizeof(l_hybrid[0])));

                return (l_hybrid[l_mca_rel_pos][l_dimm_rel_pos] == TARGETING::EFF_HYBRID_IS_HYBRID &&
                        l_hybrid_type[l_mca_rel_pos][l_dimm_rel_pos] == TARGETING::EFF_HYBRID_MEMORY_TYPE_NVDIMM);
            }
        }
    }

    return false;
}


TARGETING::TargetHandleList getProcNVDIMMs( TARGETING::Target * i_proc )
{
    TargetHandleList o_nvdimmList;

    TARGETING::ATTR_MODEL_type l_chipModel =
        i_proc->getAttr<TARGETING::ATTR_MODEL>();

    // NVDIMM only present on NIMBUS systems
    if (l_chipModel == TARGETING::MODEL_NIMBUS)
    {
        TargetHandleList l_dimmTargetList;
        getChildAffinityTargets(l_dimmTargetList, i_proc, CLASS_NA, TYPE_DIMM);

        for (TargetHandleList::iterator it = l_dimmTargetList.begin();
                 it != l_dimmTargetList.end(); ++it)
        {
            TARGETING::Target* l_dimm = *it;
            if (TARGETING::isNVDIMM(l_dimm))
            {
                // Found a valid NVDIMM
                o_nvdimmList.push_back(l_dimm);
            }
        }
    }

    return o_nvdimmList;
}

} // end namespace TARGETING
