/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/config/prdfExtensibleChip.H $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

class PrdfDataBundle;

class PrdfExtensibleChip : public CHIP_CLASS
{
  public:
    PrdfExtensibleChip( TARGETING::TargetHandle_t i_target ) :
        CHIP_CLASS(i_target)
    {};

    virtual PrdfExtensibleChipFunction * getExtensibleFunction(
                                            const char * i_func,
                                            bool i_expectNull = false ) = 0;

    virtual SCAN_COMM_REGISTER_CLASS * getRegister(
                                            const char * i_reg,
                                            bool i_expectNull = false ) = 0;

    virtual PrdfDataBundle *& getDataBundle() = 0;

    /**
     * Add Capture data to the Capture Data object
     * @param Capture data object (I/O)
     * @param Capture group
     */
    virtual int32_t CaptureErrorData( CaptureData &, int i_group = 1 ) = 0;

    virtual uint32_t getSignatureOffset() const = 0;
};

class PrdfDataBundle
{
  public:
    virtual ~PrdfDataBundle() {};
};

#endif

