/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfPluginCallResolution.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2005,2013              */
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

namespace PRDF
{

class PluginCallResolution : public Resolution
{
    private:
        ExtensibleChip * iv_chip;
        ExtensibleChipFunction * iv_function;

    public:
        PluginCallResolution(void)
          : iv_chip(NULL), iv_function(NULL) {}

        PluginCallResolution(ExtensibleChip * i_chip,
                                 ExtensibleChipFunction * i_function)
            : iv_chip(i_chip), iv_function(i_function) {};

        PluginCallResolution & operator=(const PluginCallResolution & r)
        {
          iv_chip = r.iv_chip;
          iv_function = r.iv_function;
          return *this;
        }

        bool operator==(const PluginCallResolution & r)
        {
          return (iv_chip == r.iv_chip)&&(iv_function == r.iv_function);
        }

        virtual int32_t Resolve(STEP_CODE_DATA_STRUCT & i_error)
            {
                if ((NULL == iv_chip) || (NULL == iv_function))
                    return -1;

                return (*iv_function)
                    (iv_chip,
                     PluginDef::bindParm<STEP_CODE_DATA_STRUCT&>(i_error)
                    ); //@pw01

            };

};

} // end namespace PRDF

#endif

