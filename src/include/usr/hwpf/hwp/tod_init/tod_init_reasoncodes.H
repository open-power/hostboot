/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/tod_init/tod_init_reasoncodes.H $    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef TOD_INIT_REASONCODES_H
#define TOD_INIT_REASONCODES_H

#include <hbotcompid.H>

namespace TOD
{
    enum TODModuleId
    {
        TOD_PICK_MDMT                         = 0x01,
        TOD_BUILD_TOD_DRAWERS                 = 0x02,
        TOD_QUERY_ACTIVE_CONFIG               = 0x03,
        TOD_FIND_MASTER_PROC                  = 0x04,
        TOD_SETUP_HWP                         = 0x05,
        TOD_SAVEREGS_HWP                      = 0x06,
        TOD_LOG_UNSUPPORTED_BUSTYPE           = 0x07,
        TOD_LOG_UNSUPPORTED_BUSPORT           = 0x08,
        TOD_SETUP                             = 0x09,
        TOD_READ                              = 0x0A,
        TOD_LOG_INVALID_CONFIG                = 0x0B,
        TOD_LOG_UNSUPORTED_ORDINALID          = 0x0C,
        TOD_GETSCOM                           = 0x0D,
        TOD_GETFUNCNODETARGETSONSYSTEM        = 0x0E,
        TOD_TOPOLOGY_CREATE                   = 0x0F,
        TOD_WIRE_PROCS                        = 0x10,
        TOD_WIRE_DRAWERS                      = 0x11,
        TOD_INIT_HWP                          = 0x12,
    };

    enum TODReasonCode
    {
        TOD_NO_MASTER_PROC                    = TOD_COMP_ID | 0x01,
        TOD_NO_FUNC_NODE_AVAILABLE            = TOD_COMP_ID | 0x02,
        TOD_NO_DRAWERS                        = TOD_COMP_ID | 0x03,
        TOD_HW_ERROR                          = TOD_COMP_ID | 0x04,
        TOD_UNSUPPORTED_BUSTYPE               = TOD_COMP_ID | 0x05,
        TOD_UNSUPPORTED_BUSPORT               = TOD_COMP_ID | 0x06,
        TOD_INVALID_ACTION                    = TOD_COMP_ID | 0x07,
        TOD_INVALID_CONFIG                    = TOD_COMP_ID | 0x08,
        TOD_UNSUPORTED_ORDINALID              = TOD_COMP_ID | 0x09,
        TOD_ECMD_ERROR                        = TOD_COMP_ID | 0x0A,
        TOD_NULL_INPUT_TARGET                 = TOD_COMP_ID | 0x0B,
        TOD_INVALID_TARGET                    = TOD_COMP_ID | 0x0C,
        TOD_CREATION_ERR                      = TOD_COMP_ID | 0x0D,
        TOD_CREATION_ERR_NO_DRAWER            = TOD_COMP_ID | 0x0E,
        TOD_CANNOT_WIRE_DRAWER                = TOD_COMP_ID | 0x0F,
    };

};
#endif
