/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm.H
/// @brief Common header for Power Manangement procedures
///

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS

#ifndef _P9_PM_H_
#define _P9_PM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Macro Defintions
//------------------------------------------------------------------------------

// Create a multi-bit mask of @a n bits starting at bit @a b
#ifndef BITS
    #define BITS(b, n) ((0xffffffffffffffffull << (64 - (n))) >> (b))
#endif

// Create a single bit mask at bit @a b
#ifndef BIT
    #define BIT(b) BITS((b), 1)
#endif

extern const char* p9_PM_FLOW_MODE_NAME[];

#define PM_FLOW_MODE_NAME   \
    {                           \
        "PM_RESET",             \
        "PM_INIT",              \
        "PM_SETUP",             \
        "PM_SETUP_PIB",         \
        "PM_SETUP_ALL",         \
        "PM_RESET_SOFT",        \
        "PM_INIT_SOFT",         \
        "PM_INIT_SPECIAL"       \
    }

#define PM_MODE_NAME_VAR p9_PM_FLOW_MODE_NAME[] = PM_FLOW_MODE_NAME

#define PM_MODE_NAME(_mi_mode)(         \
                                        p9_PM_FLOW_MODE_NAME[_mi_mode-1]    \
                              )




//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
namespace p9pm
{

enum PM_FLOW_MODE
{
    PM_RESET        = 0x1,
    PM_INIT         = 0x2,
    PM_SETUP        = 0x3,
    PM_SETUP_PIB    = 0x4,
    PM_SETUP_ALL    = 0x5,
    PM_RESET_SOFT   = 0x6,
    PM_INIT_SOFT    = 0x7,
    PM_INIT_SPECIAL = 0x8,
};

} // end of namespace p9pm


#endif // _P9_PM_H_
