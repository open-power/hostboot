/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/util.C $                             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
/**
 *  @file targeting/common/util.C
 *
 *  @brief Provides miscellaneous utility functions to targeting, including
 *     a check for whether system is in simulation or not.
 */

//******************************************************************************
// Includes
//******************************************************************************
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>

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
 * @brief Safely fetch the HUID of a Target
 */
uint32_t get_huid( const Target* i_target )
{
    uint32_t huid = 0;
    if( i_target == NULL )
    {
        huid = 0x0;
    }
    else if( i_target == MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        huid = 0xFFFFFFFF;
    }
    else
    {
        i_target->tryGetAttr<ATTR_HUID>(huid);
    }
    return huid;
}

/**
 * @brief set HWAS Changed flag to subscription mask
 *
 *   This will be used by the HCDB service - when the target has
 *   changed, this will get called to tell the appropriate services
 *   that the change has occured.
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
            i_target->getAttr<ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK>() &
                i_bits);
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
    ATTR_PAYLOAD_KIND_type payload_kind = sys->getAttr<ATTR_PAYLOAD_KIND>();

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

    return ((mnfg_flags & TARGETING::MNFG_FLAG_BIT_MNFG_AVP_ENABLE)
       || (mnfg_flags & TARGETING::MNFG_FLAG_BIT_MNFG_HDAT_AVP_ENABLE));
}

/**
 * @brief Utility function to obtain the highest known address in the system
 */
uint64_t get_top_mem_addr(void)
{
    uint64_t top_addr = 0;

    do
    {
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        TARGETING::getAllChips(l_cpuTargetList, TYPE_PROC);

        for ( size_t proc = 0; proc < l_cpuTargetList.size(); proc++ )
        {
            TARGETING::Target * l_pProc = l_cpuTargetList[proc];

            //Not checking success here as fail results in no change to
            // top_addr
            uint64_t l_mem_bases[8] = {0,};
            uint64_t l_mem_sizes[8] = {0,};
            l_pProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_mem_bases);
            l_pProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_mem_sizes);

            for (size_t i=0; i< 8; i++)
            {
                if(l_mem_sizes[i]) //non zero means that there is memory present
                {
                    top_addr = std::max(top_addr,
                                        l_mem_bases[i] + l_mem_sizes[i]);
                }
            }
        }
    }while(0);

    return top_addr;
}


}
