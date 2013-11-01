/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/proc_fab_smp.H $                */
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
// $Id: proc_fab_smp.H,v 1.8 2013/09/23 22:01:31 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_fab_smp.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_fab_smp.H
// *! DESCRIPTION : Common fabric structure defintions/utility functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_FAB_SMP_H_
#define _PROC_FAB_SMP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// define set of supported fabric node ID values
enum proc_fab_smp_node_id
{
    FBC_NODE_ID_0 = 0,
    FBC_NODE_ID_1 = 1,
    FBC_NODE_ID_2 = 2,
    FBC_NODE_ID_3 = 3,
    FBC_NODE_ID_4 = 4,
    FBC_NODE_ID_5 = 5,
    FBC_NODE_ID_6 = 6,
    FBC_NODE_ID_7 = 7
};

// define set of supported fabric chip ID values
enum proc_fab_smp_chip_id
{
    FBC_CHIP_ID_0 = 0,
    FBC_CHIP_ID_1 = 1,
    FBC_CHIP_ID_2 = 2,
    FBC_CHIP_ID_3 = 3,
    FBC_CHIP_ID_4 = 4,
    FBC_CHIP_ID_5 = 5,
    FBC_CHIP_ID_6 = 6,
    FBC_CHIP_ID_7 = 7
};

// define set of supported epsilon table types
enum proc_fab_smp_eps_table_type
{
    PROC_FAB_SMP_EPSILON_TABLE_TYPE_LE = 1,
    PROC_FAB_SMP_EPSILON_TABLE_TYPE_HE = 2,
    PROC_FAB_SMP_EPSILON_TABLE_TYPE_1S = 3
};

// define set of supported broadcast/pump modes
enum proc_fab_smp_pump_mode
{
    PROC_FAB_SMP_PUMP_MODE1 = 1,
    PROC_FAB_SMP_PUMP_MODE2 = 2
};


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// largest representable fabric real address given HW implementation
const uint64_t PROC_FAB_SMP_MAX_ADDRESS = ((1ULL << 50)-1ULL);

// number of links supported per chip
const uint8_t PROC_FAB_SMP_NUM_A_LINKS = 3;
const uint8_t PROC_FAB_SMP_NUM_X_LINKS = 4;
const uint8_t PROC_FAB_SMP_NUM_F_LINKS = 2;

// range of fabric node/chip ID fields
const uint8_t PROC_FAB_SMP_NUM_CHIP_IDS = 8;
const uint8_t PROC_FAB_SMP_NUM_NODE_IDS = 8;

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
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
    proc_fab_smp_node_id& o_node_id);

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
    proc_fab_smp_chip_id& o_chip_id);

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
    bool o_pcie_not_f_link[PROC_FAB_SMP_NUM_F_LINKS]);


} // extern "C"

#endif // _PROC_FAB_SMP_H_
