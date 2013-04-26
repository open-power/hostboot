/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pm.H $ */
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
// $Id: p8_pm.H,v 1.4 2013/04/12 01:22:23 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_pm.H
// *! DESCRIPTION : Common header for Power Manangement procedures
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Jim Yacynych  Email: jimyac@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _P8_PM_H_
#define _P8_PM_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>

#include "p8_scom_addresses.H"


extern "C" {

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


#ifndef _P8_PM_FLOW_MODE
#define _P8_PM_FLOW_MODE
enum p8_PM_FLOW_MODE {
        PM_CONFIG       = 0x1,
        PM_RESET        = 0x2,
        PM_INIT         = 0x3,
        PM_SETUP        = 0x4,
        PM_SETUP_PIB    = 0x5,
        PM_SETUP_ALL    = 0x6,
        PM_RESET_NOPMC  = 0x7
        };
#endif  // _P8_PM_FLOW_MODE


// Macros to enhance readability yet provide for error handling
// Assume the error path is to break out of the current loop.  If nested loops
// are employed, the error_flag can be used to break out of the necessary
// levels.
#define PUTSCOM(_mi_target, _mi_address, _mi_buffer){		            \
    l_rc = fapiPutScom(_mi_target, _mi_address, _mi_buffer);            \
    if(!l_rc.ok())                                                      \
    {                                                                   \
        FAPI_ERR("PutScom error to address 0x%08llx", _mi_address);     \
        error_flag=true;                                                \
        break;                                                          \
    }                                                                   \
}

#define GETSCOM(_mi_target, _mi_address, _mi_buffer){		            \
    l_rc = fapiGetScom(_mi_target, _mi_address, _mi_buffer);            \
    if(!l_rc.ok())                                                      \
    {                                                                   \
        FAPI_ERR("GetScom error to address 0x%08llx", _mi_address);     \
        error_flag=true;                                                \
        break;                                                          \
    }                                                                   \
}

#define E_RC_CHECK(_mi_e_rc, _mi_l_rc){                                 \
    if (e_rc)                                                           \
    {                                                                   \
        FAPI_ERR("Error (0x%x) accessing ecmdDataBufferBase", _mi_e_rc);\
        _mi_l_rc.setEcmdError(_mi_e_rc);                                \
        break;                                                          \
    }                                                                   \
}

#define GETATTR_DEFAULT(_mi_attr, _mi_attr_name, _mi_target, _mi_value, _mi_default){\
        rc = FAPI_ATTR_GET(_mi_attr, _mi_target, _mi_value); \
        if (rc) \
        { \
            FAPI_ERR("fapiGetAttribute of %s with rc = 0x%x", _mi_attr_name, (uint32_t)rc); \
            break; \
        } \
        FAPI_INF (" value read from attribute %s = 0x%x",  _mi_attr_name,  _mi_value ); \
        if (!_mi_value) \
        { \
            FAPI_DBG(" setting value of read attribute %s to default = 0x%x",  _mi_attr_name,  _mi_default ); \
             _mi_value = _mi_default;\
        } \
}

#define GETATTR(_mi_attr, _mi_attr_name, _mi_target, _mi_value){\
        rc = FAPI_ATTR_GET(_mi_attr, _mi_target, _mi_value); \
        if (rc) \
        { \
             FAPI_ERR("fapiGetAttribute of %s with rc = 0x%x",  _mi_attr_name, (uint32_t)rc); \
            break; \
        } \
        FAPI_INF (" value read from attribute %s = 0x%x", _mi_attr_name, _mi_value ); \
}

#define SETATTR(_mi_attr, _mi_attr_name, _mi_target, _mi_value){\
        rc = FAPI_ATTR_SET(_mi_attr, _mi_target, _mi_value); \
        if (rc) \
        { \
            FAPI_ERR("fapiSetAttribute of %s with rc = 0x%x",  _mi_attr_name, (uint32_t)rc); \
            break; \
        } \
        FAPI_INF (" value written to attribute %s = 0x%x",  _mi_attr_name,  _mi_value ); \
}

} // extern "C"

#endif // _P8_PM_H_
