/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/proc_fab_smp.C $                */
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
// $Id: proc_fab_smp.C,v 1.8 2013/09/23 22:01:31 jmcgill Exp $
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


//------------------------------------------------------------------------------
// function: utility function to read & return fabric node ID attribute
// parameters: i_target  => pointer to chip/chiplet target
//             o_node_id => structure encapsulating node ID value
// returns: FAPI_RC_SUCCESS if attribute read is successful & value is valid,
//          RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR if attribute value is
//              invalid,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_smp_get_node_id_attr(
    const fapi::Target* i_target,
    proc_fab_smp_node_id& o_node_id)
{
    // return code
    fapi::ReturnCode rc;
    // chiplet->chip target conversion
    bool use_parent = false;
    fapi::Target parent_target;
    // temporary attribute storage used to build procedure data structures
    uint8_t node_id_attr;

    // mark function entry
    FAPI_DBG("proc_fab_smp_get_node_id_attr: Start");

    do
    {
        if (i_target->getType() != fapi::TARGET_TYPE_PROC_CHIP)
        {
            use_parent = true;
            // retrieve parent target if input target is a chiplet
            rc = fapiGetParentChip(*i_target,
                                   parent_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_fab_smp_get_node_id_attr: Error from fapiGetParentChip");
                break;
            }
        }

        // retrieve node ID attribute
        rc = FAPI_ATTR_GET(ATTR_FABRIC_NODE_ID,
                           ((use_parent)?
                            (&parent_target):
                            (i_target)),
                           node_id_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_smp_get_node_id_attr: Error querying ATTR_FABRIC_NODE_ID");
            break;
        }

        // print attribute value
        FAPI_DBG("proc_fab_smp_get_node_id_attr: ATTR_FABRIC_NODE_ID = 0x%X",
                 node_id_attr);

        // translate to output value
        switch (node_id_attr)
        {
            case 0:
                o_node_id = FBC_NODE_ID_0;
                break;
            case 1:
                o_node_id = FBC_NODE_ID_1;
                break;
            case 2:
                o_node_id = FBC_NODE_ID_2;
                break;
            case 3:
                o_node_id = FBC_NODE_ID_3;
                break;
            case 4:
                o_node_id = FBC_NODE_ID_4;
                break;
            case 5:
                o_node_id = FBC_NODE_ID_5;
                break;
            case 6:
                o_node_id = FBC_NODE_ID_6;
                break;
            case 7:
                o_node_id = FBC_NODE_ID_7;
                break;
            default:
                FAPI_ERR("proc_fab_smp_get_node_id_attr: Invalid fabric node ID attribute value 0x%02X",
                         node_id_attr);
                const uint8_t& ATTR_DATA = node_id_attr;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR);
                break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_fab_smp_get_node_id_attr: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to read & return fabric chip ID attribute
// parameters: i_target  => pointer to chip/chiplet target
//             o_chip_id => structure encapsulating chip ID value
// returns: FAPI_RC_SUCCESS if attribute read is successful & value is valid,
//          RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR if attribute value is
//              invalid,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_smp_get_chip_id_attr(
    const fapi::Target* i_target,
    proc_fab_smp_chip_id& o_chip_id)
{
    // return code
    fapi::ReturnCode rc;
    // chiplet->chip target conversion
    bool use_parent = false;
    fapi::Target parent_target;
    // temporary attribute storage used to build procedure data structures
    uint8_t chip_id_attr;

    // mark function entry
    FAPI_DBG("proc_fab_smp_get_chip_id_attr: Start");

    do
    {
        if (i_target->getType() != fapi::TARGET_TYPE_PROC_CHIP)
        {
            use_parent = true;
            // retrieve parent target if input target is a chiplet
            rc = fapiGetParentChip(*i_target,
                                   parent_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_fab_smp_get_chip_id_attr: Error from fapiGetParentChip");
                break;
            }
        }

        // retrieve chip ID attribute
        rc = FAPI_ATTR_GET(ATTR_FABRIC_CHIP_ID,
                           ((use_parent)?
                            (&parent_target):
                            (i_target)),
                           chip_id_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_smp_get_chip_id_attr: Error querying ATTR_FABRIC_CHIP_ID");
            break;
        }

        // print attribute value
        FAPI_DBG("proc_fab_smp_get_chip_id_attr: ATTR_FABRIC_CHIP_ID = 0x%X",
                 chip_id_attr);

        // translate to output value
        switch (chip_id_attr)
        {
            case 0:
                o_chip_id = FBC_CHIP_ID_0;
                break;
            case 1:
                o_chip_id = FBC_CHIP_ID_1;
                break;
            case 2:
                o_chip_id = FBC_CHIP_ID_2;
                break;
            case 3:
                o_chip_id = FBC_CHIP_ID_3;
                break;
            case 4:
                o_chip_id = FBC_CHIP_ID_4;
                break;
            case 5:
                o_chip_id = FBC_CHIP_ID_5;
                break;
            case 6:
                o_chip_id = FBC_CHIP_ID_6;
                break;
            case 7:
                o_chip_id = FBC_CHIP_ID_7;
                break;
            default:
                FAPI_ERR("proc_fab_smp_get_chip_id_attr: Invalid fabric chip ID attribute value 0x%02X",
                         chip_id_attr);
                const uint8_t& ATTR_DATA = chip_id_attr;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR);
                break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_fab_smp_get_chip_id_attr: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to read & return PCIe/DSMP mux attribute values
// parameters: i_target          => pointer to chip target
//             o_pcie_not_f_link => vector of boolean values representing state
//                                  of PCIe/DSMP mux settings (one value per
//                                  foreign link, true=PCIe function, false=
//                                  DSMP function)
// returns: FAPI_RC_SUCCESS if attribute read is successful & value is valid,
//          RC_PROC_FAB_SMP_PCIE_NOT_F_LINK_ATTR_ERR if attribute value is
//              invalid,
//          else FAPI_ATTR_GET return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_smp_get_pcie_dsmp_mux_attrs(
    const fapi::Target* i_target,
    bool o_pcie_not_f_link[PROC_FAB_SMP_NUM_F_LINKS])
{
    // return code
    fapi::ReturnCode rc;
    // temporary attribute storage used to build procedure data structures
    uint8_t pcie_not_f_link_attr[PROC_FAB_SMP_NUM_F_LINKS];

    // mark function entry
    FAPI_DBG("proc_fab_smp_get_pcie_dsmp_mux_attrs: Start");

    do
    {
        // retrieve PCIe/DSMP mux attributes
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_NOT_F_LINK,
                           i_target,
                           pcie_not_f_link_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_smp_get_pcie_dsmp_mux_attrs: Error querying ATTR_PROC_PCIE_NOT_F_LINK");
            break;
        }

        // loop over all links
        for (uint8_t l = 0;
             l < PROC_FAB_SMP_NUM_F_LINKS;
             l++)
        {
            // print attribute value
            FAPI_DBG("proc_fab_smp_get_pcie_dsmp_mux_attrs: ATTR_PROC_PCIE_NOT_F_LINK[%d] = 0x%X",
                     l, pcie_not_f_link_attr[l]);

            // validate attribute value
            switch (pcie_not_f_link_attr[l])
            {
                case 0:
                    o_pcie_not_f_link[l] = false;
                    break;
                case 1:
                    o_pcie_not_f_link[l] = true;
                    break;
                default:
                    FAPI_ERR("proc_fab_smp_get_pcie_dsmp_mux_attrs: Invalid PCIe/DSMP mux attribute value 0x%02X",
                             pcie_not_f_link_attr[l]);
                    const uint8_t& ATTR_DATA = pcie_not_f_link_attr[l];
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_FAB_SMP_PCIE_NOT_F_LINK_ATTR_ERR);
                    break;
            }
            if (!rc.ok())
            {
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_fab_smp_get_pcie_dsmp_mux_attrs: End");
    return rc;
}



} // extern "C"
