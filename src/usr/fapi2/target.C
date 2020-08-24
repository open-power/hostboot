/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/target.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
///
/// @file target.C
///
/// @brief Currently just used to create helper functions for target.H
///
///

#include <target.H>

namespace fapi2
{
namespace impl
{

extern const std::array<fapi2_targeting_type, NUM_FAPI_TARGETING_TYPES>
    fapi2ToTargetingTypes =
{
    fapi2_targeting_type
    { fapi2::TARGET_TYPE_NONE      , TARGETING::TYPE_NA        },
    { fapi2::TARGET_TYPE_SYSTEM    , TARGETING::TYPE_SYS       },
    { fapi2::TARGET_TYPE_DIMM      , TARGETING::TYPE_DIMM      },
    { fapi2::TARGET_TYPE_PROC_CHIP , TARGETING::TYPE_PROC      },
    { fapi2::TARGET_TYPE_FC        , TARGETING::TYPE_FC        },
    { fapi2::TARGET_TYPE_CORE      , TARGETING::TYPE_CORE      },
    { fapi2::TARGET_TYPE_EQ        , TARGETING::TYPE_EQ        },
    { fapi2::TARGET_TYPE_MI        , TARGETING::TYPE_MI        },
    { fapi2::TARGET_TYPE_PERV      , TARGETING::TYPE_PERV      },
    { fapi2::TARGET_TYPE_PEC       , TARGETING::TYPE_PEC       },
    { fapi2::TARGET_TYPE_PHB       , TARGETING::TYPE_PHB       },
    { fapi2::TARGET_TYPE_MC        , TARGETING::TYPE_MC        },
    { fapi2::TARGET_TYPE_OMI       , TARGETING::TYPE_OMI       },
    { fapi2::TARGET_TYPE_OMIC      , TARGETING::TYPE_OMIC      },
    { fapi2::TARGET_TYPE_MCC       , TARGETING::TYPE_MCC       },
    { fapi2::TARGET_TYPE_OCMB_CHIP , TARGETING::TYPE_OCMB_CHIP },
    { fapi2::TARGET_TYPE_MEM_PORT  , TARGETING::TYPE_MEM_PORT  },
    { fapi2::TARGET_TYPE_NMMU      , TARGETING::TYPE_NMMU      },
    { fapi2::TARGET_TYPE_PAU       , TARGETING::TYPE_PAU       },
    { fapi2::TARGET_TYPE_IOHS      , TARGETING::TYPE_IOHS      },
    { fapi2::TARGET_TYPE_PAUC      , TARGETING::TYPE_PAUC      },
    { fapi2::TARGET_TYPE_PMIC      , TARGETING::TYPE_PMIC      },
    { fapi2::TARGET_TYPE_GENERICI2CSLAVE, TARGETING::TYPE_GENERIC_I2C_DEVICE },
};

} // end fapi2::impl namespace
} // end fapi2 namespace

namespace PLAT_TARGET
{

void systemTargCtorHelperFunc(fapi2::plat_target_handle_t& io_handle)
{
    TARGETING::Target* l_target = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_target);
    io_handle = l_target;
}

} // end PLAT_TARGET namespace
