/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwas/hwasPlat.C $
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
/**
 *  @file hwasPlat.C
 *
 *  @brief Platform specifics
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/deconfigGard.H>

#include <devicefw/driverif.H>
#include <initservice/taskargs.H>
#include <mvpd/mvpdenums.H>
#include <stdio.h>

#include <pnor/pnorif.H>

namespace HWAS
{

using   namespace   TARGETING;

//******************************************************************************
// platReadIDEC function
//******************************************************************************
errlHndl_t platReadIDEC(const TargetHandle_t &i_target)
{
    // we got a target - read the ID/EC
    //  and update the appropriate ATTR_ field.
    uint64_t id_ec;
    size_t op_size = sizeof(id_ec);
    errlHndl_t errl = NULL;

    // At the time when we read IDEC, the tp chiplet of Centaur & slave
    // processors are not yet enabled; therefore, we can not read IDEC
    // using SCOM path.  We must use FSI path to read the IDEC values.
    // For master proc, use scom
    // For everything else, use FSI(0x1028)
    TARGETING::Target* l_pMasterProcChip = NULL;
    TARGETING::targetService(). masterProcChipTargetHandle(l_pMasterProcChip);

    if (i_target == l_pMasterProcChip)
    {
        errl = DeviceFW::deviceRead(i_target, &id_ec,
                                    op_size,
                                    DEVICE_SCOM_ADDRESS(0x000F000Full));
    }
    else
    {
        errl = DeviceFW::deviceRead(i_target, &id_ec, op_size,
                                    DEVICE_FSI_ADDRESS(0x01028));
    }

    if (errl == NULL)
    {   // no error, so we got a valid ID/EC value back
        // EC - nibbles 0,2
        //                        01234567
        uint8_t ec = (((id_ec & 0xF000000000000000ull) >> 56) |
                      ((id_ec & 0x00F0000000000000ull) >> 52));
        i_target->setAttr<ATTR_EC>(ec);

        // ID - nibbles 1,5,3,4
        //                         01234567
        uint32_t id = (((id_ec & 0x0F00000000000000ull) >> 44) |
                       ((id_ec & 0x00000F0000000000ull) >> 32) |
                       ((id_ec & 0x000F000000000000ull) >> 44) |
                       ((id_ec & 0x0000F00000000000ull) >> 44));
        i_target->setAttr<ATTR_CHIP_ID>(id);
        HWAS_DBG( "i_target %.8X - id %x ec %x",
            i_target->getAttr<ATTR_HUID>(), id, ec);
    }
    else
    {   // errl was set - this is an error condition.
        HWAS_ERR( "i_target %.8X - failed ID/EC read",
            i_target->getAttr<ATTR_HUID>());
    }

    return errl;
} // platReadIDEC

//******************************************************************************
// platReadPartialGood function
//******************************************************************************
errlHndl_t platReadPartialGood(const TargetHandle_t &i_target,
        void *o_pgData)
{
    errlHndl_t errl = NULL;
    HWAS_DBG( "i_target %.8X",
            i_target->getAttr<ATTR_HUID>());

    // call deviceRead() to find the PartialGood record
    uint8_t pgRaw[VPD_CP00_PG_HDR_LENGTH + VPD_CP00_PG_DATA_LENGTH];
    size_t pgSize = sizeof(pgRaw);

    errl = deviceRead(i_target, pgRaw, pgSize,
            DEVICE_MVPD_ADDRESS(MVPD::CP00, MVPD::PG));

    if (unlikely(errl != NULL))
    {   // errl was set - this is an error condition.
        HWAS_ERR( "i_target %.8X - failed partialGood read",
            i_target->getAttr<ATTR_HUID>());
    }
    else
    {
#if 0
// Unit test. set P8_MURANO.config to have 4 procs, and this code will
//  alter the VPD so that some of the procs and chiplets should get marked
//  as NOT functional.
        {
            // skip past the header
            uint16_t *pgData = reinterpret_cast <uint16_t *>(&pgRaw[VPD_CP00_PG_HDR_LENGTH]);
            if (i_target->getAttr<ATTR_HUID>() == 0x70000)
            {   // 1st proc - let it go thru ok.
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x70001)
            {   // 2nd proc - mark Pervasive bad - entire chip
                //  should be marked present and NOT functional
                pgData[VPD_CP00_PG_PERVASIVE_INDEX] = 0;
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x70002)
            {   // 3rd proc - part of XBUS is bad
                pgData[VPD_CP00_PG_XBUS_INDEX] = 0;
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x70003)
            {   // 4th proc -  EX13 and EX14 are bad
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0;
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0;
            }
        }
#endif

        // skip past the header
        void *pgData = static_cast<void *>(&pgRaw[VPD_CP00_PG_HDR_LENGTH]);
        HWAS_DBG_BIN("PG record", pgData, VPD_CP00_PG_DATA_LENGTH);
        // copy the data back into the caller's buffer
        memcpy(o_pgData, pgData, VPD_CP00_PG_DATA_LENGTH);
    }

    return errl;
} // platReadPartialGood

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

        if (unlikely(errl != NULL))
        {   // errl was set - this is an error condition.
            HWAS_ERR( "pTarget %.8X - failed presence detect",
                pTarget->getAttr<ATTR_HUID>());

            // commit the error but keep going
            errlCommit(errl, HWAS_COMP_ID);
            // errl is now NULL

            // target is not present - fall thru
            present = false;
        }

        if (present == true)
        {
            HWAS_DBG( "pTarget %.8X - detected present",
                pTarget->getAttr<ATTR_HUID>());

            // advance to next entry in the list
            pTarget_it++;
        }
        else
        {   // chip not present -- remove from list
            HWAS_DBG( "pTarget %.8X - no presence",
                pTarget->getAttr<ATTR_HUID>());

            // erase this target, and 'increment' to next
            pTarget_it = io_targets.erase(pTarget_it);
        }
    } // for pTarget_it

    return errl;
} // platPresenceDetect




//******************************************************************************
// platGetGardPnorAddr function
//******************************************************************************
errlHndl_t platGetGardPnorAddr(void *& o_addr,uint64_t &o_size)
{
    errlHndl_t errl = NULL;

    do
    {
#if 0
        //TODO: RTC 37739
        PNOR::SectionInfo_t l_section;
        errl = PNOR::getSectionInfo(PNOR::GUARD_DATA, PNOR::CURRENT_SIDE,
                l_section);
        if (errl)
        {
            // TODO: do the malloc and store it locally?
            break;
        }

        o_addr = reinterpret_cast<void *>(l_section.vaddr);
        o_size = l_section.size;
#else
        // just use a buffer instead of PNOR
        o_size = 20 * sizeof(DeconfigGard::GardRecord);
        o_addr = malloc(o_size);
        memset(o_addr, EMPTY_GARD_VALUE, o_size);
#endif

        HWAS_INF("GARD in PNOR: addr=%p, size=%d", o_addr, o_size);
    }
    while (0);

    return errl;
} // platGetGardPnorAddr

} // namespace HWAS
