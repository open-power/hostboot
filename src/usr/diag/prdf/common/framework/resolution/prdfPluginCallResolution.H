/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfPluginCallResolution.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2012              */
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

#ifndef __PRDFPLUGINCALLRESOLUTION_H
#define __PRDFPLUGINCALLRESOLUTION_H

#include <iipResolution.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>

class PrdfPluginCallResolution : public Resolution
{
    private:
        PrdfExtensibleChip * iv_chip;
        PrdfExtensibleChipFunction * iv_function;

    public:
        PrdfPluginCallResolution(void)
          : iv_chip(NULL), iv_function(NULL) {}

        PrdfPluginCallResolution(PrdfExtensibleChip * i_chip,
                                 PrdfExtensibleChipFunction * i_function)
            : iv_chip(i_chip), iv_function(i_function) {};

        PrdfPluginCallResolution & operator=(const PrdfPluginCallResolution & r)
        {
          iv_chip = r.iv_chip;
          iv_function = r.iv_function;
          return *this;
        }

        bool operator==(const PrdfPluginCallResolution & r)
        {
          return (iv_chip == r.iv_chip)&&(iv_function == r.iv_function);
        }

        virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & i_error)
            {
                if ((NULL == iv_chip) || (NULL == iv_function))
                    return -1;

                return (*iv_function)
                    (iv_chip,
                     PrdfPluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_error)
                    ); //@pw01

            };

};

#endif

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- -------------------------------
//                              iawillia initial creation
//       F522283  f300 09/27/05 dgilbert add defaut ctor, operator==, operator=
//  pw01 F522638  f300 09/27/05 iawillia Fix possible object strip in bindParm.
// End Change Log *****************************************************

