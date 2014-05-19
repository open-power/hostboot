/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfExtensibleChip.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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

#ifndef __PRDFEXTENSIBLECHIP_H
#define __PRDFEXTENSIBLECHIP_H

#include <iipscr.h>
#include <iipchip.h>

#include <prdfPluginDef.H>

namespace PRDF
{

class DataBundle;

class ExtensibleChip : public CHIP_CLASS
{
  public:
    ExtensibleChip( TARGETING::TargetHandle_t i_target ) :
        CHIP_CLASS(i_target)
    {}
    virtual ExtensibleChipFunction * getExtensibleFunction(
                                            const char * i_func,
                                            bool i_expectNull = false ) = 0;

    virtual SCAN_COMM_REGISTER_CLASS * getRegister(
                                            const char * i_reg,
                                            bool i_expectNull = false ) = 0;

    virtual DataBundle *& getDataBundle() = 0;
    /**
     * @brief       Add Capture data to the Capture Data object
     * @param[in]   i_cap   Capture data object (I/O)
     * @param[in]   i_group Capture group
     * @return      SUCCESS|FAIL
     */
    virtual int32_t CaptureErrorData( CaptureData & i_cap,
                               int i_group = 1 ) = 0;

    /**
     * @brief       Returns signature offset associated with registes of a
     *              RuleChip.
     * @return      Error signature offset
     */
    virtual uint32_t getSignatureOffset() = 0;

};

class DataBundle
{
  public:
    virtual ~DataBundle() {};
};

} // end namespace PRDF

#endif

