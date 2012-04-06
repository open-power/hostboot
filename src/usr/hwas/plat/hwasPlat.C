//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwas/plat/hwasPlat.C $
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
/**
 *  @file hwasPlat.C
 *
 *  @brief Platform specifics
 */

#include <hwas/hwas.H>
#include <hwas/hwasCommon.H>

#include <devicefw/driverif.H>

// trace setup; used by HWAS_DBG and HWAS_ERR macros
trace_desc_t *g_trac_dbg_hwas   = NULL; // debug - fast
trace_desc_t *g_trac_imp_hwas   = NULL; // important - slow

TRAC_INIT(&g_trac_dbg_hwas, "HWAS",     2048 );
TRAC_INIT(&g_trac_imp_hwas, "HWAS_I",   2048 );

namespace HWAS
{

using   namespace   TARGETING;

//******************************************************************************
// platReadIDEC function
//******************************************************************************
errlHndl_t platReadIDEC(const TargetHandleList &i_targets)
{
    errlHndl_t errl = NULL;

    // we got a list of targets - read the ID/EC for each
    //  and update the appropriate ATTR_ fields.
    for (TargetHandleList::const_iterator pTarget_it = i_targets.begin();
            pTarget_it != i_targets.end();
            pTarget_it++)
    {
        TargetHandle_t pTarget = *pTarget_it;

        uint64_t id_ec;
        size_t op_size = sizeof(id_ec);
        errl = DeviceFW::deviceRead(pTarget, &id_ec,
                   op_size, DEVICE_SCOM_ADDRESS(0x000F000Full));

        if (errl == NULL)
        {   // no error, so we got a valid ID/EC value back
            // EC - nibbles 0,2
            //                        01234567
            uint8_t ec = (((id_ec & 0xF000000000000000ull) >> 56) |
                          ((id_ec & 0x00F0000000000000ull) >> 52));
            pTarget->setAttr<ATTR_EC>(ec);

            // ID - nibbles 1,5,3,4
            //                         01234567
            uint32_t id = (((id_ec & 0x0F00000000000000ull) >> 44) |
                           ((id_ec & 0x00000F0000000000ull) >> 32) |
                           ((id_ec & 0x000F000000000000ull) >> 44) |
                           ((id_ec & 0x0000F00000000000ull) >> 44));
            pTarget->setAttr<ATTR_CHIP_ID>(id);
            HWAS_DBG( "pTarget %x (%p) id %x ec %x",
                pTarget->getAttr<ATTR_HUID>(), pTarget, id, ec);
        }
        else
        {   // errl was set - this is an error condition.
            HWAS_ERR( "pTarget %x (%p) %x/%x - failed ID/EC read",
                pTarget->getAttr<ATTR_HUID>(), pTarget,
                pTarget->getAttr<ATTR_CLASS>(),
                pTarget->getAttr<ATTR_TYPE>());

            // break out so that we can return an error
            break;
        }
    } // for pTarget_it

    return errl;
} // platReadIDEC

//******************************************************************************
// platPresenceDetect function
//******************************************************************************
errlHndl_t platPresenceDetect(TargetHandleList &io_targets)
{
    errlHndl_t errl = NULL;

    // we got a list of targets - determine if they are present
    //  if not, delete them from the list
    for (TargetHandleList::iterator pTarget_it = io_targets.begin();
            pTarget_it != io_targets.end();
            ) // increment will be done in the loop below
    {
        TargetHandle_t pTarget = *pTarget_it;

        // call deviceRead() to see if they are present
        bool present = false;
        size_t presentSize = sizeof(present);
        errl = deviceRead(pTarget, &present, presentSize,
                                DEVICE_PRESENT_ADDRESS());

        if (errl == NULL)
        {   // no error, so we got a valid present value back
            if (present == true)
            {
                HWAS_DBG( "pTarget %x (%p) %x/%x - detected present",
                    pTarget->getAttr<ATTR_HUID>(), pTarget,
                    pTarget->getAttr<ATTR_CLASS>(),
                    pTarget->getAttr<ATTR_TYPE>());

                // advance to next entry in the list
                pTarget_it++;
            }
            else
            {   // chip no present -- remove from list
                HWAS_DBG( "pTarget %x (%p) %x/%x - no presence",
                    pTarget->getAttr<ATTR_HUID>(), pTarget,
                    pTarget->getAttr<ATTR_CLASS>(),
                    pTarget->getAttr<ATTR_TYPE>());

                // erase this target, and 'increment' to next
                pTarget_it = io_targets.erase(pTarget_it);
            }
        }
        else
        {   // errl was set - this is an error condition.
            HWAS_ERR( "pTarget %x (%p) %x/%x - failed presence detect",
                pTarget->getAttr<ATTR_HUID>(), pTarget,
                pTarget->getAttr<ATTR_CLASS>(),
                pTarget->getAttr<ATTR_TYPE>());

            // break out so that we can return an error
            break;
        }
    } // for pTarget_it

    return errl;
} // platPresenceDetect

} // namespace HWAS
