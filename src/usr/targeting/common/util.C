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

}
