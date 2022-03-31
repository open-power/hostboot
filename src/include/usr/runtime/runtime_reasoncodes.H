/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/runtime_reasoncodes.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#ifndef __RUNTIME_REASONCODES_H
#define __RUNTIME_REASONCODES_H

#include <hbotcompid.H>

namespace RUNTIME
{
    enum RuntimeModuleId
    {
        MOD_RUNTIME_INVALID             = 0x00, /**< Invalid module id */
        MOD_RUNTIME_POP_SYS_ATTR        = 0x01, /**< populate_attributes.C */
        MOD_RUNTIME_POP_NODE_ATTR       = 0x02, /**< populate_attributes.C */
        MOD_HDATSERVICE_CHECK_HEADER    = 0x03, /**< hdatservice.C */
        MOD_HDATSERVICE_CHECK_TUPLE     = 0x04, /**< hdatservice.C */
        MOD_HDATSERVICE_LOAD_HOST_DATA  = 0x05, /**< hdatservice.C */
        MOD_HDATSERVICE_GET_STANDALONE_SECTION  = 0x06, /**< hdatservice.C */
        MOD_HDATSERVICE_GETHOSTDATASECTION  = 0x07, /**< hdatservice.C */
        MOD_HDATSERVICE_VERIFY_HDAT_ADDRESS  = 0x08, /**< hdatservice.C */
        MOD_HDATSERVICE_FINDSPIRA       = 0x09, /** hdatservice.C */
        MOD_HDATSERVICE_UPDATE_SECTION_ACTUAL = 0x0A, /**< hdatservice.C */
        MOD_HDATSERVICE_MAPREGION       = 0x0B, /**< hdatservice.C */
        MOD_HDATSERVICE_GETINSTANCECOUNT = 0x0C, /**< hdatservice.C */
        MOD_HDATSERVICE_GETANDCHECKTUPLE = 0x0D, /**< hdatservice.C */
        MOD_PREVERLIDMGR_LOAD_FROM_PNOR = 0x0E, /** preverifiedlidmgr.C **/
        MOD_PREVERLIDMGR_LOAD_IMAGE = 0x0F, /** preverifiedlidmgr.C **/

        // customize_attrs_for_payload.C
        MOD_CUST_COMP_NON_PHYP_RT_TARGET = 0x12,
        MOD_CUST_CONF_HBRT_HYP_IDS       = 0x13,
        MOD_POPULATE_RTDATABYNODE        = 0x14,  /**< populate_hbruntime.C */
        MOD_PM_RT_LOAD_PM_COMPLEX        = 0x15,  /**< rt_pm.C */
        MOD_PM_RT_HCODE_UPDATE           = 0x16,  /**< rt_pm.C */
        MOD_MAP_PHYS_ADDR                = 0x17,  /**< populate_hbruntime.C */
        MOD_UNMAP_VIRT_ADDR              = 0x18,  /**< populate_hbruntime.C */
        MOD_POPULATE_TPMINFOBYNODE       = 0x19,  /**< populate_hbruntime.C */
        MOD_FILL_RSVMEM_HBDATA           = 0x20,  /**< populate_hbruntime.C */
        MOD_ATTR_RUNTIME_CHECK_PREP_FAIL = 0x21,  /**< populate_hbruntime.C */
        MOD_SEND_SBE_SYSCONFIG           = 0x22,  /**< populate_hbruntime.C */
        MOD_RT_FIRMWARE_NOTIFY           = 0x23,  /**< rt_fwnotify.C */
        MOD_RT_FIRMWARE_REQUEST          = 0x24,  /**< rt_fwreq_helper.C */
        MOD_RT_ATTR_SYNC_REQUEST         = 0x25,  /**< rt_fwnotify.C */
        MOD_CHECK_HB_RES_MEM_LIMIT       = 0x26,  /**< populate_hbruntime.C */
        MOD_INIT_RT_RES_MEM_TRACE_BUF    = 0x27,  /**< rt_rsvdtracebuffer.C */
        MOD_OPEN_UNTRUSTED_SP_AREAS      = 0x28,  /**< populate_hbruntime.C */
        MOD_SEND_ATTRIBUTES_TO_FSP       = 0x29,  /**< hbrt_utilities.H */
        MOD_CONFIGURE_HBRT_HYP_IDS       = 0x2C,  /**< customize_attrs_for_payload.C */
        MOD_PM_RT_START_PM_COMPLEX       = 0x2D,  /**< rt_pm.C */
        MOD_PM_RT_RESET_W_REASON         = 0x2E,  /**< rt_occ.C */
        MOD_VERIFY_AND_MOVE_PAYLOAD      = 0x2F,  /**< populate_hbruntime.C */
        MOD_LOG_GARD_EVENT               = 0x30,  /**< rt_fwnotify.C */
        MOD_CREATE_PMIC_HEALTH_CHECK_CALLBACK = 0x31,  /**< rt_fwnotify.C */
        MOD_DEALLOCATE_RESOURCE          = 0x32,  /** < rt_fwnotify.C */
        MOD_CONVERT_TO_HB_TARGET         = 0x33,  /** < rt_fwnotify.C */
        MOD_CREATE_PMC_LOAD_START_CALLBACK   = 0x34,  /**< rt_fwnotify.C */
    };

    enum RuntimeReasonCode
    {
        RC_DO_NOT_USE_THIS             = RUNTIME_COMP_ID | 0x00,
        RC_ATTR_GET_FAIL               = RUNTIME_COMP_ID | 0x01,
        RC_BAD_HDAT_HEADER             = RUNTIME_COMP_ID | 0x02,
        RC_BAD_HDAT_TUPLE              = RUNTIME_COMP_ID | 0x03,
        RC_INVALID_STANDALONE          = RUNTIME_COMP_ID | 0x04,
        RC_CANNOT_MAP_MEMORY           = RUNTIME_COMP_ID | 0x05,
        //RC_XXX                       = RUNTIME_COMP_ID | 0x06,
        RC_CANNOT_MAP_MEMORY2          = RUNTIME_COMP_ID | 0x07,
        RC_INVALID_PAYLOAD_KIND        = RUNTIME_COMP_ID | 0x08,
        RC_NO_HSVC_NODE_DATA_FOUND     = RUNTIME_COMP_ID | 0x09,
        RC_BAD_NACA                    = RUNTIME_COMP_ID | 0x0A,
        RC_INVALID_ADDRESS             = RUNTIME_COMP_ID | 0x0B,
        RC_INVALID_SECTION             = RUNTIME_COMP_ID | 0x0C,
        RC_CANNOT_MAP_MEMORY3          = RUNTIME_COMP_ID | 0x0D,
        RC_TCE_INVALID_SIZE            = RUNTIME_COMP_ID | 0x0E,
        RC_TCE_ADDR_NOT_ALIGNED        = RUNTIME_COMP_ID | 0x0F,
        RC_TCE_INIT_NOT_RUN            = RUNTIME_COMP_ID | 0x10,
        RC_TCE_DEV_MAP_FAIL            = RUNTIME_COMP_ID | 0x11,
        RC_TCE_DEV_UNMAP_FAIL          = RUNTIME_COMP_ID | 0x12,
        RC_TCE_NO_ACTIVE_PSI           = RUNTIME_COMP_ID | 0x13,
        RC_TCE_NOT_ENOUGH_FREE_ENTRIES = RUNTIME_COMP_ID | 0x14,
        RC_TCE_ENTRY_NOT_CONTIGUOUS    = RUNTIME_COMP_ID | 0x15,
        RC_NO_SPIRA                    = RUNTIME_COMP_ID | 0x16,
        RC_CANNOT_MAP_HDAT             = RUNTIME_COMP_ID | 0x17,
        RC_NOT_ENOUGH_SPACE            = RUNTIME_COMP_ID | 0x18,
        RT_UNIT_TARGET_NOT_FOUND       = RUNTIME_COMP_ID | 0x19,
        RT_TARGET_TYPE_NOT_SUPPORTED   = RUNTIME_COMP_ID | 0x1A,
        RT_NO_PROC_TARGET              = RUNTIME_COMP_ID | 0x1B,
        RC_UNMAP_FAIL                  = RUNTIME_COMP_ID | 0x1C,
        RC_PM_RT_UNKNOWN_MODE          = RUNTIME_COMP_ID | 0x1D,
        RC_PM_RT_INTERFACE_ERR         = RUNTIME_COMP_ID | 0x1E,
        RC_PM_RT_HCODE_UPDATE_ERR      = RUNTIME_COMP_ID | 0x1F,
        RC_INVALID_RHB_INSTANCE        = RUNTIME_COMP_ID | 0x20,
        RC_DUPLICATE_I2C_LINK_IDS      = RUNTIME_COMP_ID | 0x21,
        RC_I2C_DEVICE_NOT_IN_MRW       = RUNTIME_COMP_ID | 0x22,
        RC_INSTANCES_UNSUPPORTED       = RUNTIME_COMP_ID | 0x23,
        RC_I2C_DEVICE_DUPLICATE_IN_MRW = RUNTIME_COMP_ID | 0x24,
        RC_EXTRA_I2C_DEVICE_IN_MRW     = RUNTIME_COMP_ID | 0x25,
        RC_GETTUPLE_UNSUPPORTED        = RUNTIME_COMP_ID | 0x26,
        RC_EXCEEDED_MEMORY             = RUNTIME_COMP_ID | 0x27,
        RC_UNABLE_TO_PIN_ATTR_MEM      = RUNTIME_COMP_ID | 0x28,
        RC_UNABLE_TO_UNPIN_ATTR_MEM    = RUNTIME_COMP_ID | 0x29,
        RC_TPM_HDAT_OUT_OF_SPACE       = RUNTIME_COMP_ID | 0x2A,
        RC_TPM_HDAT_ID_MISMATCH        = RUNTIME_COMP_ID | 0x2B,
        RC_TPM_HDAT_EYE_CATCH_MISMATCH = RUNTIME_COMP_ID | 0x2C,
        RC_TPM_MISSING_PROC            = RUNTIME_COMP_ID | 0x2D,
        RC_TPM_HDAT_BAD_VERSION        = RUNTIME_COMP_ID | 0x2E,
        RC_TPM_HDAT_BAD_NUM_I2C        = RUNTIME_COMP_ID | 0x2F,
        RC_INVALID_LID                 = RUNTIME_COMP_ID | 0x30,
        RC_PREVER_INVALID_SIZE         = RUNTIME_COMP_ID | 0x31,
        RC_FW_NOTIFY_RT_INVALID_MSG    = RUNTIME_COMP_ID | 0x32,
        RC_FW_NOTIFY_RT_INVALID_MSG_TYPE = RUNTIME_COMP_ID | 0x33,
        RC_FW_REQUEST_RT_NULL_PTR      = RUNTIME_COMP_ID | 0x34,
        RC_SBE_RT_INVALID_HUID         = RUNTIME_COMP_ID | 0x35,
        RC_SBE_RT_RECOVERY_ERR         = RUNTIME_COMP_ID | 0x36,
        RC_FW_REQUEST_HWSV_ERR         = RUNTIME_COMP_ID | 0x37,
        RC_FW_REQUEST_RESET_RELOAD_ERR = RUNTIME_COMP_ID | 0x38,
        RC_FW_REQUEST_ERR              = RUNTIME_COMP_ID | 0x39,
        RC_TPM_HDAT_VIRT_TO_PHYS_ERR   = RUNTIME_COMP_ID | 0x3A,
        RC_TPM_HDAT_MAP_BLOCK_ERR      = RUNTIME_COMP_ID | 0x3B,
        RC_ATTR_UPDATE_FAILED          = RUNTIME_COMP_ID | 0x3C,
        RC_HB_RES_MEM_EXCEEDED         = RUNTIME_COMP_ID | 0x3D,
        RC_SEND_SBE_TIMER_EXPIRED      = RUNTIME_COMP_ID | 0x3E,
        RC_HOST_TIMER_THREAD_FAIL      = RUNTIME_COMP_ID | 0x3F,
        RC_RT_RES_TRACE_BUF_DUMPED     = RUNTIME_COMP_ID | 0x40,
        RC_RT_RES_TRACE_BUF_INVALID    = RUNTIME_COMP_ID | 0x41,
        RC_SP_ATTN_AREA_OVERFLOW       = RUNTIME_COMP_ID | 0x42,
        RC_SP_ATTN_AREA1_SIZE_OVERFLOW = RUNTIME_COMP_ID | 0x43,
        RC_UNKNOWN_LABEL               = RUNTIME_COMP_ID | 0x44,
        RC_NULL_FIRMWARE_MSG_PTR       = RUNTIME_COMP_ID | 0x45,
        RC_SERIALIZE_ATTRIBUTE_FAILED  = RUNTIME_COMP_ID | 0x46,
        RC_NO_SPACE_FOR_ATTRIBUTE_SERIALIZATION = RUNTIME_COMP_ID | 0x47,
        RC_CANNOT_MAKE_ATTRIBUTE       = RUNTIME_COMP_ID | 0x48,
        RT_NO_OMI_TARGET_FOUND         = RUNTIME_COMP_ID | 0x49,
        RC_LOG_GARD_EVENT_UNKNOWN_ERROR_TYPE   = RUNTIME_COMP_ID | 0x4A,
        RC_LOG_GARD_EVENT              = RUNTIME_COMP_ID | 0x4B,
        RC_BAD_HOMER_PHYS_ADDR         = RUNTIME_COMP_ID | 0x4C,
        RC_COULD_NOT_MAP_RESET_REASON  = RUNTIME_COMP_ID | 0x4D,
        RC_MCTP_AVAILABLE_ERR          = RUNTIME_COMP_ID | 0x4E,
        RC_INVALID_SPI_DEVICE          = RUNTIME_COMP_ID | 0x4F,
        RC_TPM_HDAT_BAD_NUM_SPI        = RUNTIME_COMP_ID | 0x50,
        RC_DUPLICATE_SPI_DEV_IDS       = RUNTIME_COMP_ID | 0x51,
        RC_SPI_DEVICE_NOT_IN_MRW       = RUNTIME_COMP_ID | 0x52,
        RC_SPI_DEVICE_DUPLICATE_IN_MRW = RUNTIME_COMP_ID | 0x53,
        RC_EXTRA_SPI_DEVICE_IN_MRW     = RUNTIME_COMP_ID | 0x54,
        RC_INVALID_NX_QUANTITY         = RUNTIME_COMP_ID | 0x55,
        RC_HOST_CALLBACK_INTERFACE_ERR = RUNTIME_COMP_ID | 0x56,
        RC_HOST_CALLBACK_ERR           = RUNTIME_COMP_ID | 0x57,
        RC_UNSUPPORTED_TARGET          = RUNTIME_COMP_ID | 0x58,
        RC_UNSUPPORTED_RESOURCE_TYPE   = RUNTIME_COMP_ID | 0x59,
    };

    enum UserDetailsTypes
    {
        RUNTIME_UDT_NO_FORMAT       = 0x0,
        RUNTIME_UDT_NACA            = 0x1,
        RUNTIME_UDT_SPIRA           = 0x2,
        RUNTIME_UDT_TUPLE           = 0x3,
    };
};

#endif
