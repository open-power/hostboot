/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pm.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: p8_pm.H,v 1.9 2013/10/30 17:13:12 stillgs Exp $
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
enum p8_PM_FLOW_MODE 
{
    PM_CONFIG       = 0x1,
    PM_RESET        = 0x2,
    PM_INIT         = 0x3,
    PM_SETUP        = 0x4,
    PM_SETUP_PIB    = 0x5,
    PM_SETUP_ALL    = 0x6,
    PM_RESET_SOFT   = 0x7,
    PM_CONFIG_SOFT  = PM_CONFIG,
    PM_INIT_SOFT    = 0x8,
    PM_INIT_SPECIAL = 0x9,
    PM_INIT_PMC     = 0xA
};
        
// This storage is contained in p8_pm_utils.C which must be included
// in the compilation of all procs that use the PM_MODE_NAME macro     
extern const char * p8_PM_FLOW_MODE_NAME[]; 

#define PM_FLOW_MODE_NAME   \
{                           \
    "PM_CONFIG",            \
    "PM_RESET",             \
    "PM_INIT",              \
    "PM_SETUP",             \
    "PM_SETUP_PIB",         \
    "PM_SETUP_ALL",         \
    "PM_RESET_SOFT",        \
    "PM_INIT_SOFT",         \
    "PM_INIT_SPECIAL",      \
    "PM_INIT_PMC",          \
    "PM_CONFIG_SOFT"        \
}

// Necessary definition to allocated enum string array storage.
// Typical declaration:  
// const char *        PM_MODE_NAME_VAR; // Defines storage for PM_MODE_NAME
#define PM_MODE_NAME_VAR p8_PM_FLOW_MODE_NAME[] = PM_FLOW_MODE_NAME

#define PM_MODE_NAME(_mi_mode)(         \
    p8_PM_FLOW_MODE_NAME[_mi_mode-1]    \
)
       
#endif  // _P8_PM_FLOW_MODE


// Macros to enhance readability yet provide for error handling
// Assume the error path is to break out of the current loop.  If nested loops
// are employed, the error_flag can be used to break out of the necessary
// levels.
#define PUTSCOM(_mi_rc, _mi_target, _mi_address, _mi_buffer){		    \
    _mi_rc = fapiPutScom(_mi_target, _mi_address, _mi_buffer);          \
    if(!_mi_rc.ok())                                                    \
    {                                                                   \
        FAPI_ERR("PutScom error to address 0x%08llx", _mi_address);     \
        break;                                                          \
    }                                                                   \
}

#define GETSCOM(_mi_rc, _mi_target, _mi_address, _mi_buffer){		    \
    _mi_rc = fapiGetScom(_mi_target, _mi_address, _mi_buffer);          \
    if(!_mi_rc.ok())                                                    \
    {                                                                   \
        FAPI_ERR("GetScom error to address 0x%08llx", _mi_address);     \
        break;                                                          \
    }                                                                   \
}

#define E_RC_CHECK(_mi_e_rc, _mi_l_rc){                                 \
    if (_mi_e_rc)                                                       \
    {                                                                   \
        FAPI_ERR("Error (0x%x) accessing ecmdDataBufferBase", _mi_e_rc);\
        _mi_l_rc.setEcmdError(_mi_e_rc);                                \
        break;                                                          \
    }                                                                   \
}

#define GETATTR_DEFAULT(_mi_rc, _mi_attr, _mi_attr_name, _mi_target, _mi_value, _mi_default){\
        _mi_rc = FAPI_ATTR_GET(_mi_attr, _mi_target, _mi_value); \
        if (_mi_rc) \
        { \
            FAPI_ERR("fapiGetAttribute of %s with rc = 0x%x", _mi_attr_name, (uint32_t)_mi_rc); \
            break; \
        } \
        FAPI_INF (" value read from attribute %s = 0x%x",  _mi_attr_name,  _mi_value ); \
        if (!_mi_value) \
        { \
            FAPI_DBG(" setting value of read attribute %s to default = 0x%x",  _mi_attr_name,  _mi_default ); \
             _mi_value = _mi_default;\
        } \
}

#define GETATTR(_mi_rc, _mi_attr, _mi_attr_name, _mi_target, _mi_value){\
        _mi_rc = FAPI_ATTR_GET(_mi_attr, _mi_target, _mi_value); \
        if (_mi_rc) \
        { \
             FAPI_ERR("fapiGetAttribute of %s with rc = 0x%x",  _mi_attr_name, (uint32_t)rc); \
            break; \
        } \
        FAPI_INF (" value read from attribute %s = 0x%x", _mi_attr_name, _mi_value ); \
}

#define SETATTR(_mi_rc, _mi_attr, _mi_attr_name, _mi_target, _mi_value){\
        _mi_rc = FAPI_ATTR_SET(_mi_attr, _mi_target, _mi_value); \
        if (_mi_rc) \
        { \
            FAPI_ERR("fapiSetAttribute of %s with rc = 0x%x",  _mi_attr_name, (uint32_t)_mi_rc); \
            break; \
        } \
        FAPI_INF (" value written to attribute %s = 0x%x",  _mi_attr_name,  _mi_value ); \
}

} // extern "C"

#endif // _P8_PM_H_
