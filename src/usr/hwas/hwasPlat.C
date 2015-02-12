/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlat.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
/* [+] Google Inc.                                                        */
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
 *  @file hwasPlat.C
 *
 *  @brief Platform specifics
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/hwasPlat.H>

#include <devicefw/driverif.H>
#include <initservice/taskargs.H>
#include <vpd/mvpdenums.H>
#include <stdio.h>
#include <sys/mm.h>

#include <pnor/pnorif.H>

#include <hwas/common/hwas_reasoncodes.H>
#include <targeting/common/utilFilter.H>
#include <fsi/fsiif.H>
#include <config.h>
#include <targeting/common/targetservice.H>

namespace HWAS
{

class RegisterHWASFunctions
{
    public:
    RegisterHWASFunctions()
    {
        // HWAS is awake

        // register processCallout function for ErrlEntry::commit
        HWAS_DBG("module load: calling errlog::setHwasProcessCalloutFn");
        ERRORLOG::ErrlManager::setHwasProcessCalloutFn(
                    (processCalloutFn)(&processCallout));
    }
};
// this causes the function to get run at module load.
RegisterHWASFunctions registerHWASFunctions;

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
    Target* l_pMasterProcChip = NULL;
    targetService().masterProcChipTargetHandle(l_pMasterProcChip);

    if (i_target == l_pMasterProcChip)
    {
        errl = DeviceFW::deviceRead(i_target, &id_ec,
                                    op_size,
                                    DEVICE_SCOM_ADDRESS(0x000F000Full));
    }
    else
    {
        // FSI only reads 4 bytes for id_ec
        op_size = sizeof(uint32_t);

        errl = DeviceFW::deviceRead(i_target, &id_ec, op_size,
                                    DEVICE_FSI_ADDRESS(0x01028));
    }

    //Look for a totally dead chip
    if( (errl == NULL)
        && ((id_ec & 0xFFFFFFFF00000000) == 0xFFFFFFFF00000000) )
    {
        HWAS_ERR("All FFs for chipid read on %.8X",TARGETING::get_huid(i_target));
        /*@
         * @errortype
         * @moduleid     HWAS::MOD_PLAT_READIDEC
         * @reasoncode   HWAS::RC_BAD_CHIPID
         * @userdata1    Target HUID
         * @userdata2    <unused>
         * @devdesc      platReadIDEC> Invalid chipid from hardware (all FFs)
         */
        errl = new ERRORLOG::ErrlEntry(
                                       ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       HWAS::MOD_PLAT_READIDEC,
                                       HWAS::RC_BAD_CHIPID,
                                       TARGETING::get_huid(i_target),
                                       0);

        // if things are this broken then chances are there are bigger
        //  problems, we can just make some guesses on what to call out

        // make code the highest since there are other issues
        errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                  HWAS::SRCI_PRIORITY_HIGH);

        // callout this chip as Medium and deconfigure it
        errl->addHwCallout( i_target,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DECONFIG,
                            HWAS::GARD_NULL );

        // Grab all the FFDC we can think of
        FSI::getFsiFFDC( FSI::FFDC_OPB_FAIL_SLAVE,
                         errl,
                         i_target );
        FSI::getFsiFFDC( FSI::FFDC_READWRITE_FAIL,
                         errl,
                         i_target );
        FSI::getFsiFFDC( FSI::FFDC_PIB_FAIL,
                         errl,
                         i_target );

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
// platSystemIsAtRuntime function
// Description: This function will return false always because when Hostboot
// is running then System cannot be at runtime
//******************************************************************************
bool platSystemIsAtRuntime()
{
    HWAS_INF("HostBoot is running so system is not at runtime.");
    return false;
}

//******************************************************************************
// platIsMinHwCheckingAllowed function
// Description: This function will return false always because when Hostboot
// is running then System cannot be at runtime
//******************************************************************************
errlHndl_t platIsMinHwCheckingAllowed(bool &o_minHwCheckingAllowed)
{
    errlHndl_t errl = NULL;

    // for hostboot, minimum hardware checkign is always allowed
    o_minHwCheckingAllowed = true;

    return errl;
}

//******************************************************************************
// platReadPartialGood function
//******************************************************************************
errlHndl_t platReadPartialGood(const TargetHandle_t &i_target,
        void *o_pgData)
{
    HWAS_DBG( "i_target %.8X",
            i_target->getAttr<ATTR_HUID>());

    // call deviceRead() to find the PartialGood record
    uint8_t pgRaw[VPD_CP00_PG_HDR_LENGTH + VPD_CP00_PG_DATA_LENGTH];
    size_t pgSize = sizeof(pgRaw);

    errlHndl_t errl = deviceRead(i_target, pgRaw, pgSize,
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
            if (i_target->getAttr<ATTR_HUID>() == 0x50000)
            {   // 1st proc
                pgData[VPD_CP00_PG_EX0_INDEX+4] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+5] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+6] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+12] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0x9300; // off
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50001)
            {   // 2nd proc
                pgData[VPD_CP00_PG_EX0_INDEX+4] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+5] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+6] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+12] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0xF300;
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50002)
            {   // 3rd proc
                //// mark Pervasive bad - entire chip
                ////  should be marked present and NOT functional
                ////pgData[VPD_CP00_PG_PERVASIVE_INDEX] = 0;

                pgData[VPD_CP00_PG_EX0_INDEX+4] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+5] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+6] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+12] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0xF300;
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50003)
            {   // 4th proc -  EX13 and EX14 are good
                pgData[VPD_CP00_PG_EX0_INDEX+4] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+5] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+6] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+12] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0x9300; // off
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
// platReadPR function
//******************************************************************************
errlHndl_t platReadPR(const TargetHandle_t &i_target,
        void *o_prData)
{
    HWAS_DBG( "i_target %.8X",
            i_target->getAttr<ATTR_HUID>());

    // call deviceRead() to find the PR record
    uint8_t prData[VPD_VINI_PR_DATA_LENGTH];
    size_t prSize = sizeof(prData);

    errlHndl_t errl = deviceRead(i_target, prData, prSize,
            DEVICE_MVPD_ADDRESS(MVPD::VINI, MVPD::PR));

    if (unlikely(errl != NULL))
    {   // errl was set - this is an error condition.
        HWAS_ERR( "i_target %.8X - failed PR read",
            i_target->getAttr<ATTR_HUID>());
    }
    else
    {
#if 0
// Unit test. set P8_MURANO.config to have 4 procs, and this code will
//  alter the VPD so that some of the procs and chiplets should get marked
//  as NOT functional.
        {
            if (i_target->getAttr<ATTR_HUID>() == 0x50000)
            {   // 1st proc - let it go thru ok.
                prData[2] = 3 << VPD_VINI_PR_B2_SHIFT; // 3*2 = 6 cores
                prData[7] = 1; // 2 procs
                //prData[2] = 1 << VPD_VINI_PR_B2_SHIFT; // 1*4 = 4 cores
                //prData[7] = 3; // 4 cores
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50001)
            {   // 2nd proc -
                prData[2] = 3 << VPD_VINI_PR_B2_SHIFT; // 3*2 = 6 cores
                prData[7] = 1; // 2 procs
                //prData[2] = 1 << VPD_VINI_PR_B2_SHIFT; // 1*4 = 4 cores
                //prData[7] = 3; // 4 cores
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50002)
            {   // 3rd proc -
                prData[2] = 3 << VPD_VINI_PR_B2_SHIFT; // 3*1 = 3 cores
                prData[7] = 0; // 1 procs
                //prData[2] = 1 << VPD_VINI_PR_B2_SHIFT; // 1*4 = 4 cores
                //prData[7] = 3; // 4 cores
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50003)
            {   // 4th proc -
                prData[2] = 4 << VPD_VINI_PR_B2_SHIFT; // 4*1 = 4 cores
                prData[7] = 0; // 1 procs
                //prData[2] = 1 << VPD_VINI_PR_B2_SHIFT; // 1*4 = 4 cores
                //prData[7] = 3; // 4 cores
            }
        }
#endif

        HWAS_DBG_BIN("PR record", prData, VPD_VINI_PR_DATA_LENGTH);
        // copy the data back into the caller's buffer
        memcpy(o_prData, prData, VPD_VINI_PR_DATA_LENGTH);
    }

    return errl;
} // platReadPR

//******************************************************************************
// platGetFCO function
//******************************************************************************
errlHndl_t platGetFCO(const TargetHandle_t &i_node,
            uint32_t &o_fco)
{
    errlHndl_t errl = NULL;

    o_fco = i_node->getAttr<ATTR_FIELD_CORE_OVERRIDE>();

    HWAS_DBG("FCO returned: %d", o_fco);

    return errl;
} // platGetFCO

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

        // if CLASS_ENC
        // by definition, hostboot only has 1 node/enclosure, and we're
        //  here, so it is functional
        if (pTarget->getAttr<ATTR_CLASS>() == CLASS_ENC)
        {
            HWAS_DBG("pTarget %.8X - detected present",
                pTarget->getAttr<ATTR_HUID>());

            // on to the next target
            pTarget_it++;
            continue;
        }

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
// hwasPLDDetection function
//******************************************************************************
bool hwasPLDDetection()
{
    bool rc = false;

    // TODO: RTC: 76459
    HWAS_DBG("hwasPLDDetection");

    Target *l_pTopLevel = NULL;
    targetService().getTopLevelTarget( l_pTopLevel );

    // check if SP doesn't support this,
    if (l_pTopLevel->getAttr<ATTR_SP_FUNCTIONS>().powerLineDisturbance)
    {
        // SP supports this - return false as this will get handled later.
        rc = false;
    }
    else
    {
        // TBD - detect power fault
        rc = false;
    }

    return rc;
} // hwasPLDDetection

//******************************************************************************
// markTargetChanged function
//******************************************************************************
#ifdef CONFIG_HOST_HCDB_SUPPORT
void markTargetChanged(TARGETING::TargetHandle_t i_target)
{
    TargetHandleList l_pChildList;

    HWAS_INF("Marking target and all children as changed for parent HUID %.8X",
                TARGETING::get_huid(i_target) );

    //Call update mask on the target
    update_hwas_changed_mask(i_target);

    //Get all children under this target, and set them into the list
    targetService().getAssociated(l_pChildList, i_target,
           TargetService::CHILD, TargetService::ALL);

    //Iterate through the child list that was populated, and update mask
    for (TargetHandleList::iterator l_pChild_it = l_pChildList.begin();
            l_pChild_it != l_pChildList.end(); ++l_pChild_it)
    {
        TargetHandle_t l_pChild = *l_pChild_it;
        update_hwas_changed_mask(l_pChild);
    }

} // markTargetChanged
#endif

//******************************************************************************
//  platCheckMinimumHardware()
//******************************************************************************
void platCheckMinimumHardware(uint32_t & io_plid,
                            const TARGETING::ConstTargetHandle_t i_node,
                            bool *o_bootable)
{
    //errlHndl_t l_errl = NULL;

    //  nothing to do yet...

    //  if you add something here, don't forget to
    //      add a procedure callout
    //l_errl->addProcedureCallout( EPUB_PRC_FIND_DECONFIGURED_PART,
    //                             SRCI_PRIORITY_HIGH);

    //      and update the common plid
    //if (io_plid != 0)
    //{
    //    l_errl->plid(io_plid) ;
    //}
    //else
    //{
    //    io_plid = l_errl->plid();
    //}
}


} // namespace HWAS
