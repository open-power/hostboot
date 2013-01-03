/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devtree/devtree_reasoncodes.H $               */
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
#ifndef __DEVTREE_REASONCODES_H
#define __DEVTREE_REASONCODES_H

#include <hbotcompid.H>

namespace DEVTREE
{
    enum DevtreeModuleId
    {
        MOD_DEVTREE_INVALID           = 0x00, /**< Zero is invalid module id */
        MOD_DEVTREE_BLD_MEM           = 0x01,
    };

    enum DevtreeReasonCode
    {
        RC_ATTR_MEMSIZE_GET_FAIL            = DEVTREE_COMP_ID | 0x01,
        RC_ATTR_MEMBASE_GET_FAIL            = DEVTREE_COMP_ID | 0x02,
    };
};

#endif
