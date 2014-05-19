/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/winkle_ring_accessors/getL3DeltaDataAttr.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: getL3DeltaDataAttr.C,v 1.5 2014/03/20 16:24:48 whs Exp $
/**
 *  @file getL3DeltaDataAttr.C
 *
 *  @brief fetch processor ex func l3 delta data attributes based on chip type, 
 *  EC and PROC_PBIEX_ASYNC_SEL value from static arrays in 
 *  fapiL3DeltaDataAttr.H
 *
 */

#include    <stdint.h>

//  fapi support
#include    <fapi.H>
#include    <getL3DeltaDataAttr.H>
#include    <fapiL3DeltaDataAttr.H>

// Logic overview

// Define and initialize variables
// Get chip type
// Get EC level
// Get PROC_PBIEX_ASYNC_SEL attr
// Use chip & ec to select array entry and selection attr to select data array 
//   entry
// Set return delta data attr value

extern "C"
{

fapi::ReturnCode getL3DeltaDataAttr( const fapi::Target  &i_fapiTarget,
                                     uint32_t (&o_data)[DELTA_DATA_SIZE],
                                     uint32_t (&o_ringLength))
{
     FAPI_INF("getL3DeltaDataAttr: entry" );

     // Initialize return values to 0x00
     memset(o_data, 0x00, sizeof(o_data));
     o_ringLength = 0;

     // Define and initialize variables

     uint8_t                    i = 0;
     uint8_t                    l_attrDdLevel = 0;
     fapi::TargetType           l_targetType = fapi::TARGET_TYPE_NONE;
     fapi::ATTR_NAME_Type       l_chipType = 0x00;
     fapi::ATTR_PROC_PBIEX_ASYNC_SEL_Type l_selection = 0;
     fapi::ReturnCode           rc;

     // Get attributes used to determine delta data

     do
     {
         // Verify input target is a processor
         l_targetType = i_fapiTarget.getType();
         if (l_targetType != fapi::TARGET_TYPE_PROC_CHIP)
         {
             FAPI_ERR("getL3DeltaDataAttr:  Invalid target type passed on "
                      "invocation. target type=0x%08X ", 
                       static_cast<uint32_t>(l_targetType));
             // Return error on get attr
             fapi::TargetType & TARGET_TYPE = l_targetType;
             FAPI_SET_HWP_ERROR(rc, RC_GET_L3_DELTA_DATA_PARAMETER_ERR );
             break;
         }

         // Get chip type
         rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME,
                                       &i_fapiTarget,
                                       l_chipType);
         if (rc)
         {
             FAPI_ERR("getL3DeltaDataAttr: FAPI_ATTR_GET_PRIVILEGED of "
                      "ATTR_NAME failed w/rc=0x%08X", 
                       static_cast<uint32_t>(rc));
             break;
         }

         // Get EC level
         rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC,
                                       &i_fapiTarget,
                                       l_attrDdLevel);
         // Exit on error
         if (rc)
         {
             FAPI_ERR("getL3DeltaDataAttr: FAPI_ATTR_GET_PRIVILEGED of "
                      "ATTR_EC failed w/rc=0x%08X", static_cast<uint32_t>(rc));
             break;
         }

         // Get proc_pbiex_async_sel
         rc = FAPI_ATTR_GET(ATTR_PROC_PBIEX_ASYNC_SEL,
                            NULL,
                            l_selection);
         // Exit on error
         if (rc)
         {
             FAPI_ERR("getL3DeltaDataAttr: FAPI_ATTR_GET of "
                      "ATTR_PROC_PBIEX_ASYNC_SEL failed w/rc=0x%08X", 
                       static_cast<uint32_t>(rc));
             break;
         }
         // Check for valid value
         if ((l_selection != fapi::ENUM_ATTR_PROC_PBIEX_ASYNC_SEL_SEL0) &&
             (l_selection != fapi::ENUM_ATTR_PROC_PBIEX_ASYNC_SEL_SEL1) &&
             (l_selection != fapi::ENUM_ATTR_PROC_PBIEX_ASYNC_SEL_SEL2)) 
         {
             FAPI_ERR("getL3DeltaDataAttr:  FAPI_ATTR_GET() returned "
                      "unsupported value ATTR_PROC_PBIEX_ASYNC_SEL=0x%02x", 
                       l_selection);
             fapi::ATTR_PROC_PBIEX_ASYNC_SEL_Type & SELECT_VAL = l_selection;
             FAPI_SET_HWP_ERROR(rc, RC_GET_L3_DELTA_DATA_SELECT_ERR );
             break;
         }

         FAPI_INF("getL3DeltaDataAttr:  Chip type=0x%02x EC=0x%02x "
                  "ATTR_PROC_PBIEX_ASYNC_SEL = %i",
                  l_chipType, l_attrDdLevel, l_selection);

         // Murano DD1.2 and DD1.0 are equivalent in terms of engineering data
         if ((l_chipType == fapi::ENUM_ATTR_NAME_MURANO) &&
             (l_attrDdLevel == 0x12))
         {
             FAPI_INF("getL3DeltaDataAttr: Treating EC1.2 like EC1.0");
             l_attrDdLevel = 0x10;
         }

         // Use chip & ec to select array entry and selection attr to select 
         // data array entry
         for (i = 0; ((i < (sizeof(L3_DELTA_DATA_array) / 
                            sizeof(L3_DELTA_DATA_ATTR))) &&
             ((L3_DELTA_DATA_array[i].l_ATTR_CHIPTYPE != l_chipType) ||
              (L3_DELTA_DATA_array[i].l_ATTR_EC       != l_attrDdLevel) ||
              (L3_DELTA_DATA_array[i].l_ATTR_SELECT   != l_selection))); i++)
         { }
         // No match found
         if (i == (sizeof(L3_DELTA_DATA_array)/sizeof(L3_DELTA_DATA_ATTR)))
         {
             FAPI_ERR("getL3DeltaDataAttr:  No match found for chiptype=0x%x "
                      "EC=0x%x selection=%d", 
                      l_chipType, l_attrDdLevel, l_selection);
             // Return error on get attr
             fapi::ATTR_NAME_Type & CHIP_NAME = l_chipType;
             uint8_t & CHIP_EC = l_attrDdLevel;
             FAPI_SET_HWP_ERROR(rc, RC_GET_L3_DELTA_DATA_ERR );
             break;
         }

         // Set return delta data attr value
         memcpy(o_data,L3_DELTA_DATA_array[i].l_ATTR_L3_DELTA_DATA,
                sizeof(o_data));
         o_ringLength = L3_DELTA_DATA_array[i].l_ATTR_BIT_LENGTH;

     } while (0);

     FAPI_INF("getL3DeltaDataAttr: exit rc=0x%x", static_cast<uint32_t>(rc) );

     return  rc;
}

}   // extern "C"

