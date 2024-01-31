/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/src/fapi2_utils.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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
 *  @file utils.C
 *  @brief Implements fapi2 utilities
 */
#include <fapi2_attribute_service.H>
#include <attribute_ids.H>
#include <return_code.H>
#include <plat_trace.H>
#include <target.H>

namespace fapi2
{

ReturnCode queryChipEcAndName(
    const Target < fapi2::TARGET_TYPE_ALL>& i_target,
    fapi2::ATTR_NAME_Type& o_chipName, fapi2::ATTR_EC_Type& o_chipEc )
{

    ReturnCode l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_target, o_chipName);

    if ( l_rc != FAPI2_RC_SUCCESS )
    {
        FAPI_ERR("queryChipEcFeature: error getting chip name");
    }
    else
    {
        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_target, o_chipEc);

        if ( l_rc != FAPI2_RC_SUCCESS )
        {
            FAPI_ERR("queryChipEcFeature: error getting chip ec");
        }
    }

    return l_rc;
}


// convert sbe instance of target to a fapi position
uint16_t convertSbeTargInstanceToFapiPos(fapi2::TargetType i_targType,
        uint16_t i_instance,
        uint64_t i_sbeChipType,
        uint16_t i_sbeChipFapiPos)
{
    // Compute this target's FAPI_POS value.  We first take the parent's
    // FAPI_POS and multiply by the max number of targets of this type that
    // the parent's type can have. This yields the lower bound of this
    // target's FAPI_POS.  Then we add in the relative position of this
    // target with respect to the parent.  Typically this is done by passing
    // in the chip unit, in which case (such as for cores) it can be much
    // greater than the architecture limit ratio (there can be cores with
    // chip units of 0..23, but only 2 cores per ex), so to normalize we
    // have to take the value mod the architecture limit.  Note that this
    // scheme only holds up because every parent also had the same type of
    // calculation to compute its own FAPI_POS.

    uint16_t max_targets = 0;
    uint16_t fapi_pos = INVALID_FAPI_POS;

    // if the target type being converted matches the sbe chip, then
    // it will be the same chip as the sbe instance, just return that one.
    if ((i_targType & i_sbeChipType) != 0)
    {
        fapi_pos = i_sbeChipFapiPos;
    }
    else
    {
        switch( i_targType )
        {
            case  TARGET_TYPE_DIMM:
                {
                    if ((i_sbeChipType & TARGET_TYPE_PROC_CHIP) != 0)
                    {
                        max_targets = MAX_DIMM_PER_PROC;
                    }
                    else
                    {
                        max_targets = MAX_DIMM_PER_OCMB;
                    }

                    break;
                }

            case  TARGET_TYPE_EQ:
                {
                    max_targets = MAX_EQ_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_CORE:
                {
                    max_targets = MAX_CORE_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_FC:
                {
                    max_targets = MAX_FC_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_IOLINK:
                {
                    max_targets = MAX_IOLINK_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_MDS_CTLR:
                {
                    max_targets = MAX_MDS_CTLR_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_MC:
                {
                    max_targets = MAX_MC_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_MI:
                {
                    max_targets = MAX_MI_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_NMMU:
                {
                    max_targets = MAX_NMMU_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_PHB:
                {
                    max_targets = MAX_PHB_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_PERV:
                {
                    if ((i_sbeChipType & TARGET_TYPE_PROC_CHIP) != 0)
                    {
                        max_targets = MAX_PERV_PER_PROC;
                    }
                    else
                    {
                        max_targets = MAX_PERV_PER_OCMB;
                    }

                    break;
                }

            case  TARGET_TYPE_OBUS:
                {
                    max_targets = MAX_OBUS_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_PEC:
                {
                    max_targets = MAX_PEC_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_OMI:
                {
                    max_targets = MAX_OMI_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_OMIC:
                {
                    max_targets = MAX_OMIC_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_MCC:
                {
                    max_targets = MAX_MCC_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_OCMB_CHIP:
                {
                    max_targets = MAX_OCMB_CHIP_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_PAU:
                {
                    max_targets = MAX_PAU_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_IOHS:
                {
                    max_targets = MAX_IOHS_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_PAUC:
                {
                    max_targets = MAX_PAUC_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_PMIC:
                {
                    if ((i_sbeChipType & TARGET_TYPE_PROC_CHIP) != 0)
                    {
                        max_targets = MAX_PMIC_PER_PROC;
                    }
                    else
                    {
                        max_targets = MAX_PMIC_PER_OCMB;
                    }

                    break;
                }

            case  TARGET_TYPE_GENERICI2CSLAVE:
                {
                    if ((i_sbeChipType & TARGET_TYPE_PROC_CHIP) != 0)
                    {
                        max_targets = MAX_GI2C_PER_PROC;
                    }
                    else
                    {
                        max_targets = MAX_GENERIC_I2C_DEVICE_PER_OCMB;
                    }

                    break;
                }

            case TARGET_TYPE_MEM_PORT:
                {
                    if ((i_sbeChipType & TARGET_TYPE_PROC_CHIP) != 0)
                    {
                        max_targets = MAX_MEM_PORT_PER_PROC;
                    }
                    else
                    {
                        max_targets = MAX_MEM_PORT_PER_OCMB;
                    }

                    break;
                }

            case TARGET_TYPE_POWER_IC:
                {
                    if ((i_sbeChipType & TARGET_TYPE_PROC_CHIP) != 0)
                    {
                        max_targets = MAX_POWER_IC_PER_PROC;
                    }
                    else
                    {
                        max_targets = MAX_POWER_IC_PER_OCMB;
                    }

                    break;
                }

            case TARGET_TYPE_TEMP_SENSOR:
                {
                    if ((i_sbeChipType & TARGET_TYPE_PROC_CHIP) != 0)
                    {
                        max_targets = MAX_TEMP_SENSOR_PER_PROC;
                    }
                    else
                    {
                        max_targets = MAX_TEMP_SENSOR_PER_OCMB;
                    }

                    break;
                }

            case TARGET_TYPE_NONE:
            case TARGET_TYPE_SYSTEM:
            case TARGET_TYPE_PROC_CHIP:
            case TARGET_TYPE_MEMBUF_CHIP:
            case TARGET_TYPE_EX:
            case TARGET_TYPE_MBA:
            case TARGET_TYPE_MCS:
            case TARGET_TYPE_XBUS:
            case TARGET_TYPE_ABUS:
            case TARGET_TYPE_L4:
            case TARGET_TYPE_MCA:
            case TARGET_TYPE_MCBIST:
            case TARGET_TYPE_CAPP:
            case TARGET_TYPE_DMI:
            case TARGET_TYPE_OBUS_BRICK:
            case TARGET_TYPE_SBE:
            case TARGET_TYPE_PPE:
            case TARGET_TYPE_RESERVED:
            case TARGET_TYPE_MULTICAST:
            case TARGET_TYPE_ALL:
            case TARGET_TYPE_ALL_MC:
            case TARGET_TYPE_CHIPS:
            case TARGET_TYPE_CHIPLETS:
            case TARGET_TYPE_MULTICASTABLE:
            case TARGET_TYPE_MULTICAST_CHIP:
                {
                    max_targets = INVALID_TARGET_COUNT;
                    break;
                }
        }

        if( max_targets == INVALID_TARGET_COUNT )
        {
            FAPI_ERR("Unable to determine the target count "
                     "for target type = 0x%.16lX and instance 0x%d "
                     "associated with chip position %d",
                     i_targType, i_instance, i_sbeChipFapiPos);
        }
        else
        {
            fapi_pos = max_targets * i_sbeChipFapiPos + (i_instance % max_targets);

            if (((i_sbeChipType & TARGET_TYPE_OCMB_CHIP) != 0) && (i_targType == TARGET_TYPE_PERV))
            {
                // There is a special case with Odyssey SBEs where there is an agreement between Hostboot and Cronus to
                // add an arbitrary 0x8000 to FAPI_POS for PERV targs. This differentiates Odyssey SBE PERV targets from
                // P10 SBE PERV targets.
                fapi_pos |= 0x8000;
            }

        }
    }

    FAPI_INF("Returning FAPI_POS= 0x%X for target type 0x%.16lX", fapi_pos, i_targType);

    return fapi_pos;
}

};
