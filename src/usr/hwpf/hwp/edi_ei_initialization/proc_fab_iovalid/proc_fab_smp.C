//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/edi_ei_initialization/proc_fab_iovalid/proc_fab_smp.C $
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
// $Id: proc_fab_smp.C,v 1.3 2012/04/27 18:20:00 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_fab_smp.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_fab_smp.C
// *! DESCRIPTION : Common fabric structure defintions/utility functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_fab_smp.H"

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi::ReturnCode proc_fab_smp_validate_smp(
    std::vector<proc_fab_smp_proc_chip *>& i_smp)
{
    // return code
    fapi::ReturnCode rc;

    // iterator defintions
    std::vector<proc_fab_smp_proc_chip *>::iterator smp_chip;
    std::vector<proc_fab_smp_x_bus *>::iterator x_bus;
    std::vector<proc_fab_smp_a_bus *>::iterator a_bus;

    do
    {
        // mark function entry
        FAPI_DBG("proc_fab_smp_validate_smp: Start");

        FAPI_DBG("proc_fab_smp_validate_smp: *************************************");
        for (smp_chip = i_smp.begin(); smp_chip != i_smp.end(); smp_chip++)
        {
            // ensure that proc_fab_smp_proc_chip pointer is non NULL
            if ((*smp_chip) == NULL)
            {
                FAPI_ERR("proc_fab_smp_validate_smp: Invalid NULL proc_fab_smp_proc_chip pointer");
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_PROC_CHIP_ARG);
                break;
            }

            // display target information for this chip
            FAPI_DBG("proc_fab_smp_validate_smp: Target: %s", (*smp_chip)->this_chip.toEcmdString());

            // display information about X bus connections
            for (x_bus = (*smp_chip)->x_busses.begin();
                 x_bus != (*smp_chip)->x_busses.end();
                 x_bus++)
            {
                // ensure that proc_fab_smp_x_bus pointer & enclosed destination
                // chip pointers are non NULL
                if ((*x_bus == NULL) ||
                    ((*x_bus)->dest_chip == NULL))
                {
                    FAPI_ERR("proc_fab_smp_validate_smp: Invalid/NULL proc_fab_smp_x_bus pointer");
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_X_BUS_ARG);
                    break;
                }
                // validate source/destination bus ID values
                if (((*x_bus)->src_chip_bus_id != FBC_BUS_X0) &&
                    ((*x_bus)->src_chip_bus_id != FBC_BUS_X1) &&
                    ((*x_bus)->src_chip_bus_id != FBC_BUS_X2) &&
                    ((*x_bus)->src_chip_bus_id != FBC_BUS_X3))
                {
                    FAPI_ERR("proc_fab_smp_validate_smp: Unsupported source X bus ID value 0x%x presented",
                             (*x_bus)->src_chip_bus_id);
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_X_BUS_ARG);
                    break;
                }
                if (((*x_bus)->dest_chip_bus_id != FBC_BUS_X0) &&
                    ((*x_bus)->dest_chip_bus_id != FBC_BUS_X1) &&
                    ((*x_bus)->dest_chip_bus_id != FBC_BUS_X2) &&
                    ((*x_bus)->dest_chip_bus_id != FBC_BUS_X3))
                {
                    FAPI_ERR("proc_fab_smp_validate_smp: Unsupported destination X bus ID value 0x%x presented",
                             (*x_bus)->dest_chip_bus_id);
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_X_BUS_ARG);
                    break;
                }
                FAPI_DBG("proc_fab_smp_validate_smp: X%d [ Target: %s X%d]",
                         (*x_bus)->src_chip_bus_id,
                         (*x_bus)->dest_chip->toEcmdString(),
                         (*x_bus)->dest_chip_bus_id);
            }
            if (!rc.ok())
            {
                break;
            }

            // display information about A bus connections
            for (a_bus = (*smp_chip)->a_busses.begin();
                 a_bus != (*smp_chip)->a_busses.end();
                 a_bus++)
            {
                // ensure that proc_fab_smp_a_bus pointer & enclosed destination
                // chip pointers are non NULL
                if ((*a_bus == NULL) ||
                    ((*a_bus)->dest_chip == NULL))
                {
                    FAPI_ERR("proc_fab_smp_validate_smp: Invalid/NULL proc_fab_smp_a_bus pointer");
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_A_BUS_ARG);
                    break;
                }
                // validate source/destination bus ID values
                if (((*a_bus)->src_chip_bus_id != FBC_BUS_A0) &&
                    ((*a_bus)->src_chip_bus_id != FBC_BUS_A1) &&
                    ((*a_bus)->src_chip_bus_id != FBC_BUS_A2))
                {
                    FAPI_ERR("proc_fab_smp_validate_smp: Unsupported source A bus ID value 0x%x presented",
                             (*a_bus)->src_chip_bus_id);
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_A_BUS_ARG);
                    break;
                }
                if (((*a_bus)->dest_chip_bus_id != FBC_BUS_A0) &&
                    ((*a_bus)->dest_chip_bus_id != FBC_BUS_A1) &&
                    ((*a_bus)->dest_chip_bus_id != FBC_BUS_A2))
                {
                    FAPI_ERR("proc_fab_smp_validate_smp: Unsupported destination A bus ID value 0x%x presented",
                             (*a_bus)->dest_chip_bus_id);
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_A_BUS_ARG);
                    break;
                }
                FAPI_DBG("proc_fab_smp_validate_smp: A%d [ Target: %s A%d]",
                         (*a_bus)->src_chip_bus_id,
                         (*a_bus)->dest_chip->toEcmdString(),
                         (*a_bus)->dest_chip_bus_id);
            }
            if (!rc.ok())
            {
                break;
            }

            FAPI_DBG("proc_fab_smp_validate_smp:");
        }
        FAPI_DBG("proc_fab_smp_validate_smp: *************************************");
    } while(0);

    // mark function exit
    FAPI_DBG("proc_fab_smp_validate_smp: End");
    return rc;
}


} // extern "C"
