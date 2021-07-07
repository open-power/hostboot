/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/src/fapi2_utils.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
        fapi2::Target<TARGET_TYPE_PROC_CHIP>& i_proc, uint16_t i_instance)
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

    ATTR_FAPI_POS_Type l_procPosition = 0;

    FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_proc, l_procPosition);

    // if the target type being converted is a proc chip, then
    // it will be the same proc as the sbe instance, just return that one
    if(i_targType == TARGET_TYPE_PROC_CHIP )
    {
        fapi_pos = l_procPosition;
    }
    else
    {
        switch( i_targType )
        {
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

            case  TARGET_TYPE_EX:
                {
                    max_targets = MAX_EX_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_MCS:
                {
                    max_targets = MAX_MCS_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_MCA:
                {
                    max_targets = MAX_MCA_PER_PROC;
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

            case  TARGET_TYPE_PHB:
                {
                    max_targets = MAX_PHB_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_MCBIST:
                {
                    max_targets = MAX_MCBIST_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_PERV:
                {
                    max_targets = MAX_PERV_PER_PROC;
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

            case  TARGET_TYPE_PMIC:
                {
                    max_targets = MAX_PMIC_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_PAUC:
                {
                    max_targets = MAX_PAUC_PER_PROC;
                    break;
                }

            case  TARGET_TYPE_GENERICI2CSLAVE:
                {
                    max_targets = MAX_GI2C_PER_PROC;
                    break;
                }

            default:
                max_targets = INVALID_TARGET_COUNT;
                break;
        }

        if( max_targets == INVALID_TARGET_COUNT )
        {
            FAPI_ERR("Unable to determine the target count "
                     "for target type = 0x%.16lX and instance 0x%d "
                     "associated with proc position %d",
                     i_targType, i_instance, l_procPosition);
        }
        else
        {
            fapi_pos = max_targets * l_procPosition +
                       (i_instance % max_targets);
        }
    }

    FAPI_INF("Returning FAPI_POS= %d for target type 0x%.16lX", fapi_pos, i_targType);

    return fapi_pos;
}

};
