/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlentry_consts.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef ERRLENTRY_CONSTS_H
#define ERRLENTRY_CONSTS_H

#include <errl/errludcallout.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>

using namespace HWAS;

namespace ERRORLOG
{

struct epubProcToSub_t
{
    epubProcedureID xProc;
    epubSubSystem_t xSubSys;

};
// Procedure to subsystem table.
const epubProcToSub_t PROCEDURE_TO_SUBSYS_TABLE[] =
{
    { EPUB_PRC_FIND_DECONFIGURED_PART , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_SP_CODE                , EPUB_FIRMWARE_SP            },
    { EPUB_PRC_PHYP_CODE              , EPUB_FIRMWARE_PHYP          },
    { EPUB_PRC_ALL_PROCS              , EPUB_PROCESSOR_SUBSYS       },
    { EPUB_PRC_ALL_MEMCRDS            , EPUB_MEMORY_SUBSYS          },
    { EPUB_PRC_INVALID_PART           , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_LVL_SUPP               , EPUB_MISC_SUBSYS            },
    { EPUB_PRC_PROCPATH               , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_NO_VPD_FOR_FRU         , EPUB_CEC_HDW_VPD_INTF       },
    { EPUB_PRC_MEMORY_PLUGGING_ERROR  , EPUB_MEMORY_SUBSYS          },
    { EPUB_PRC_FSI_PATH               , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_PROC_AB_BUS            , EPUB_PROCESSOR_BUS_CTL      },
    { EPUB_PRC_PROC_XYZ_BUS           , EPUB_PROCESSOR_BUS_CTL      },
    { EPUB_PRC_MEMBUS_ERROR           , EPUB_MEMORY_SUBSYS          },
    { EPUB_PRC_EIBUS_ERROR            , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_MEMORY_UE              , EPUB_MEMORY_SUBSYS          },
    { EPUB_PRC_POWER_ERROR            , EPUB_POWER_SUBSYS           },
    { EPUB_PRC_PERFORMANCE_DEGRADED   , EPUB_MISC_SUBSYS            },
    { EPUB_PRC_HB_CODE                , EPUB_FIRMWARE_HOSTBOOT      },
    { EPUB_PRC_TOD_CLOCK_ERR          , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_COOLING_SYSTEM_ERR     , EPUB_MISC_SUBSYS            },
    { EPUB_PRC_FW_VERIFICATION_ERR    , EPUB_FIRMWARE_SUBSYS        },
    { EPUB_PRC_GPU_ISOLATION_PROCEDURE, EPUB_CEC_HDW_SUBSYS         },
};

struct epubTargetTypeToSub_t
{
    TARGETING::TYPE     xType;
    epubSubSystem_t     xSubSys;
};
// Target type to subsystem table.
const epubTargetTypeToSub_t TARGET_TO_SUBSYS_TABLE[] =
{
    // This list must be kept sorted by TYPE
    { TARGETING::TYPE_NODE             , EPUB_CEC_HDW_SUBSYS       },
    { TARGETING::TYPE_DIMM             , EPUB_MEMORY_DIMM          },
    { TARGETING::TYPE_MEMBUF           , EPUB_MEMORY_SUBSYS        },
    { TARGETING::TYPE_PROC             , EPUB_PROCESSOR_SUBSYS     },
    { TARGETING::TYPE_EX               , EPUB_PROCESSOR_UNIT       },
    { TARGETING::TYPE_CORE             , EPUB_PROCESSOR_UNIT       },
    { TARGETING::TYPE_L4               , EPUB_MEMORY_SUBSYS        },
    { TARGETING::TYPE_MCS              , EPUB_MEMORY_CONTROLLER    },
    { TARGETING::TYPE_MBA              , EPUB_MEMORY_CONTROLLER    },
    { TARGETING::TYPE_XBUS             , EPUB_PROCESSOR_BUS_CTL    },
    { TARGETING::TYPE_ABUS             , EPUB_PROCESSOR_SUBSYS     },
    { TARGETING::TYPE_NX               , EPUB_PROCESSOR_SUBSYS     },
    { TARGETING::TYPE_CAPP             , EPUB_PROCESSOR_SUBSYS     },
    { TARGETING::TYPE_EQ               , EPUB_PROCESSOR_SUBSYS     },
    { TARGETING::TYPE_MCA              , EPUB_MEMORY_CONTROLLER    },
    { TARGETING::TYPE_MCBIST           , EPUB_MEMORY_CONTROLLER    },
    { TARGETING::TYPE_MI               , EPUB_MEMORY_CONTROLLER    },
    { TARGETING::TYPE_DMI              , EPUB_MEMORY_SUBSYS        },
    { TARGETING::TYPE_OBUS             , EPUB_PROCESSOR_BUS_CTL    },
    { TARGETING::TYPE_NV               , EPUB_PROCESSOR_SUBSYS     },
    { TARGETING::TYPE_PEC              , EPUB_IO_PHB               },
    { TARGETING::TYPE_PHB              , EPUB_IO_PHB               },
};

struct epubBusTypeToSub_t
{
    HWAS::busTypeEnum xType;
    epubSubSystem_t   xSubSys;
};
// Bus type to subsystem table
const epubBusTypeToSub_t BUS_TO_SUBSYS_TABLE[] =
{
    { HWAS::FSI_BUS_TYPE               , EPUB_CEC_HDW_CHIP_INTF    },
    { HWAS::DMI_BUS_TYPE               , EPUB_MEMORY_BUS           },
    { HWAS::A_BUS_TYPE                 , EPUB_PROCESSOR_BUS_CTL    },
    { HWAS::X_BUS_TYPE                 , EPUB_PROCESSOR_BUS_CTL    },
    { HWAS::I2C_BUS_TYPE               , EPUB_CEC_HDW_I2C_DEVS     },
    { HWAS::PSI_BUS_TYPE               , EPUB_CEC_HDW_SP_PHYP_INTF },
    { HWAS::O_BUS_TYPE                 , EPUB_PROCESSOR_BUS_CTL    },
};

struct epubClockTypeToSub_t
{
    HWAS::clockTypeEnum xType;
    epubSubSystem_t     xSubSys;
};
// Clock type to subsystem table
const epubClockTypeToSub_t CLOCK_TO_SUBSYS_TABLE[] =
{
    { HWAS::TODCLK_TYPE                , EPUB_CEC_HDW_TOD_HDW },
    { HWAS::MEMCLK_TYPE                , EPUB_CEC_HDW_CLK_CTL },
    { HWAS::OSCREFCLK_TYPE             , EPUB_CEC_HDW_CLK_CTL },
    { HWAS::OSCPCICLK_TYPE             , EPUB_CEC_HDW_CLK_CTL },
};

struct epubPartTypeToSub_t
{
    HWAS::partTypeEnum  xType;
    epubSubSystem_t     xSubSys;
};

// PART type to subsystem table
const epubPartTypeToSub_t PART_TO_SUBSYS_TABLE[] =
{
    { HWAS::FLASH_CONTROLLER_PART_TYPE  , EPUB_CEC_HDW_SUBSYS   },
    { HWAS::PNOR_PART_TYPE              , EPUB_CEC_HDW_SUBSYS   },
    { HWAS::SBE_SEEPROM_PART_TYPE       , EPUB_PROCESSOR_SUBSYS },
    { HWAS::VPD_PART_TYPE               , EPUB_CEC_HDW_SUBSYS   },
    { HWAS::LPC_SLAVE_PART_TYPE         , EPUB_CEC_HDW_SUBSYS   },
    { HWAS::GPIO_EXPANDER_PART_TYPE     , EPUB_MEMORY_SUBSYS    },
    { HWAS::SPIVID_SLAVE_PART_TYPE      , EPUB_POWER_SUBSYS   },
};

} //end namespace

#endif //#ifndef ERRLENTRY_CONSTS_H
