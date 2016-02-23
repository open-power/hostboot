/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/scominfo/p9_cu.H $                            */
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
/// @file p9_cu.H
/// @brief P9 chip unit definitions
///
/// HWP HWP Owner: jmcgill@us.ibm.com
/// HWP FW Owner: dcrowell@us.ibm.com
/// HWP Team: Infrastructure
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

#ifndef P9_CU_H
#define P9_CU_H

// includes
#include <stdint.h>

extern "C"
{
    /// P9 chip unit type enumeration
    typedef enum
    {
        P9C_CHIP,            ///< Cumulus chip (included for future expansion)
        P9N_CHIP,            ///< Nimbus chip (included for future expansion)
        PU_C_CHIPUNIT,       ///< Core
        PU_EQ_CHIPUNIT,      ///< Quad
        PU_EX_CHIPUNIT,      ///< EX
        PU_XBUS_CHIPUNIT,    ///< XBUS
        PU_OBUS_CHIPUNIT,    ///< OBUS
        PU_NV_CHIPUNIT,      ///< NV Link Brick
        PU_NVBUS_CHIPUNIT,   ///< DO NOT USE!  TEMPORARY FOR CI ONLY
        PU_PEC_CHIPUNIT,     ///< PCIe (PEC)
        PU_PHB_CHIPUNIT,     ///< PCIe (PHB)
        PU_MI_CHIPUNIT,      ///< MI (Cumulus only)
        PU_DMI_CHIPUNIT,     ///< DMI (Cumulus only)
        PU_MCS_CHIPUNIT,     ///< MCS (Nimbus only)
        PU_MCA_CHIPUNIT,     ///< MCA (Nimbus only)
        PU_MCBIST_CHIPUNIT,  ///< MCBIST (Nimbus only)
        PU_OCC_CHIPUNIT,     ///< OCC
        PU_PERV_CHIPUNIT,    ///< Pervasive
        PU_PPE_CHIPUNIT,     ///< PPE
        PU_SBE_CHIPUNIT,     ///< SBE
        PU_CAPP_CHIPUNIT,    ///< CAPP
        NONE                 ///< None/Invalid
    } p9ChipUnits_t;

    /// P9 chip unit pairing struct
    struct p9_chipUnitPairing_t
    {
        /// @brief Default constructor
        p9_chipUnitPairing_t()
            : chipUnitType(NONE), chipUnitNum(0) {}
        /// @brief Construct from type/instance number
        p9_chipUnitPairing_t (p9ChipUnits_t type, uint32_t num)
            : chipUnitType(type), chipUnitNum(num) {}

        p9ChipUnits_t chipUnitType;  ///< chip unit type
        uint32_t chipUnitNum;        ///< chip unit instance number
    };

} // extern "C"

#endif /* P9_CU_H */
