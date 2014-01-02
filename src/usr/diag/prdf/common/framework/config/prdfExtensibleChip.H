/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfExtensibleChip.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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

