//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/util.C $
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
//******************************************************************************
// Includes
//******************************************************************************
#include <targeting/attributes.H> 
#include <targeting/entitypath.H>
#include <targeting/targetservice.H>


/**
 * Miscellaneous Utility Functions
 */

namespace TARGETING
{

/**
 * @brief Checks to see if we are running in a hardware simulation
 *    environment, i.e. VPO/VBU  (not Simics)
 */
bool is_vpo( void )
{
    Target * sys = NULL;
    targetService().getTopLevelTarget( sys );
    uint8_t vpo_mode = 0;
    if( unlikely( //compiler hint to optimize the false path
        sys
        && sys->tryGetAttr<ATTR_IS_SIMULATION>(vpo_mode)
        && (vpo_mode == 1)
        ) )
    {
       return true;
    }
    return false;
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


}
