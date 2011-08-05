
#ifndef TARG_ATTRIBUTEENUMS_H
#define TARG_ATTRIBUTEENUMS_H

/**
 *  @file attributeenums.H
 *
 *  @brief Defined enums for platform attributes
 *
 *  This header file contains enumerations for supported platform attributes
 *  (as opposed to HWPF attributes).  Eventually this file will be automatically
 *  generated
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <stdint.h>
#include <stdlib.h>

//******************************************************************************
// Enumerations
//******************************************************************************

namespace TARGETING
{

/**
 *  @brief Platform attribute IDs
 *
 *  Enumeration defining every possible platform attribute that can be
 *  associated with a target
 */
enum ATTRIBUTE_ID
{
    ATTR_CLASS                  = 0x01,
    ATTR_TYPE                   = 0x02,
    ATTR_MODEL                  = 0x03,
    ATTR_PHYS_PATH              = 0x04,
    ATTR_AFFINITY_PATH          = 0x05,
    ATTR_POWER_PATH             = 0x06,
    ATTR_PRIMARY_CAPABILITIES   = 0x07,
    ATTR_XSCOM_BASE_ADDRESS     = 0x08,
    ATTR_SCOM_SWITCHES          = 0x09,
    ATTR_XSCOM_CHIP_INFO        = 0x0A,
    ATTR_INBAND_SCOM_CHIP_INFO  = 0x0B,
    ATTR_FSI_SCOM_CHIP_INFO     = 0x0C,
    ATTR_I2C_CHIP_INFO          = 0x0D,

    ATTR_DUMMY_WO               = 0xFD,
    ATTR_DUMMY_RO               = 0xFE,
    ATTR_DUMMY_RW               = 0xFF,
};

/**
 *  @brief Target Classes
 *
 *  Enumeration which identifies the general class of a target
 */
enum CLASS
{
    CLASS_NA    = 0x00,
    CLASS_CARD  = 0x01,
    CLASS_ENC   = 0x02,
    CLASS_CHIP  = 0x03,
    CLASS_UNIT  = 0x04,
    CLASS_DEV   = 0x05,
    CLASS_SYS   = 0x06,
    CLASS_MAX   = 0x07,

};

/**
 *  @brief Target Types
 *
 *  Enumeration which identifies the specific type of target
 */
enum TYPE
{
    TYPE_NA = 0x00,

    // System
    TYPE_SYS,

    // Enclosures
    TYPE_NODE,

    // Cards
    TYPE_DIMM,
    TYPE_SCM,
    TYPE_DCM,

    // Chips
    TYPE_MEMBUF,
    TYPE_PROC,

    // Voltage Suppliers
    TYPE_MEMVRM,
    TYPE_PROCVRM,

    // Processor/Centaur Units
    TYPE_EX,
    TYPE_CORE,
    TYPE_L2,
    TYPE_L3,
    TYPE_L4,
    TYPE_MCS,
    TYPE_MBS,
    TYPE_MBA,
    TYPE_MEM_PORT,
    TYPE_PERVASIVE,
    TYPE_POWERBUS,
    TYPE_XBUS,
    TYPE_ABUS,
    TYPE_PCI,

    TYPE_LAST_IN_RANGE

};

/**
 *  @brief Target Models
 *
 *  Enumeration which identifies the specific model of a target
 */
enum MODEL
{
    MODEL_NA      = 0x00,

    // Proc chips/proc units
    MODEL_SALERNO = 0x10,
    MODEL_VENICE  = 0x11,

    // Memory buffers/memory buffer units
    MODEL_CENTAUR = 0x30,

    // DIMMs
    MODEL_JEDEC   = 0x50,
    MODEL_CDIMM   = 0x51,

    // Systems
    MODEL_POWER8  = 0x70,

};

/**
 *  @brief FSI Engine Types
 *
 *  Enumeration which identifies a specific FSI engine type
 */
enum ENGINE_TYPE
{
  // TBD in future sprint
};

} // End namespace TARGETING

#endif // TARG_ATTRIBUTEENUMS_H
