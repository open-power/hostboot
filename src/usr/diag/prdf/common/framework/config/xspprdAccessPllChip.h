/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/xspprdAccessPllChip.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2000,2014              */
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

#ifndef xspprdAccessPllChip_h
#define xspprdAccessPllChip_h

// Class Description *************************************************
//
//  Name:  xspprdAccessPllChip
//  Base class: PllChip
//
//  Description: Provide PLL support for chips that have Access jtag interface
//  Usage:
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <iipchip.h>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
 * Provide PLL support for chips that have Access jtag interface
 *
 * @author Doug Gilbert
 */
class AccessPllChip : public CHIP_CLASS
{
  public:

    /**
     * @brief Constructor
     * @param i_target A chip target.
     */
    explicit AccessPllChip( TARGETING::TargetHandle_t i_target );

    /**
     Query hardware to see if there is a PLL error reported by this chip
     <ul>
     <br><b>Parameters:  </b> None.
     <br><b>Returns:     </b> [true | false]
     <br><b>Requirements:</b> None.
     <br><b>Promises:    </b> None.
     <br><b>Exceptions:  </b> None.
     </ul><br>
     */
    virtual bool QueryPll();

    /**
     Clear the pll check bit(s) in the hardware
     <ul>
     <br><b>Parameters:  </b> None.
     <br><b>Returns:     </b> return code
     <br><b>Requirements:</b> None.
     <br><b>Promises:    </b> None.
     <br><b>Exceptions:  </b> None.
     </ul><br>
     */
    virtual int32_t ClearPll();

    /**
     Disable the reporting of PLL errors in the hardware
     <ul>
     <br><b>Parameters:  </b> serviceData
     <br><b>Returns:     </b> return code
     <br><b>Requirements:</b> none.
     <br><b>Promises:    </b> serviceData may be modified
     <br><b>Exceptions:  </b> None.
     </ul><br>
     */
    virtual int32_t MaskPll(STEP_CODE_DATA_STRUCT & serviceData);

    /**
     Enable the reporting of PLL errors in the hardware
     <ul>
     <br><b>Parameters:  </b> None.
     <br><b>Returns:     </b> return code
     <br><b>Requirements:</b> none.
     <br><b>Promises:    </b> none.
     <br><b>Exceptions:  </b> None.
     </ul><br>
     */
    virtual int32_t UnMaskPll();

    /**
     * Add the PLL status register to the service Capturedata
     * @param Service Data collector
     * @pre   none
     * @post  service data collectors' capture data has the content of the PLL
     *        status reg
     */
    void CapturePll(STEP_CODE_DATA_STRUCT & serviceData);

  private:  // functions

    /**
     Copy constructor - Forbidden
     <ul>
     <br><b>Notes:       </b> No definitions should exist
     </ul><br>
     */
    AccessPllChip(const AccessPllChip &);
    /**
     Assignment operator - Forbidden
     <ul>
     <br><b>Notes:       </b> No definitions should exist
     </ul><br>
     */
    AccessPllChip & operator=(const AccessPllChip &);

  private:  // Data

};

inline AccessPllChip::AccessPllChip( TARGETING::TargetHandle_t i_target ) :
    CHIP_CLASS(i_target)
{}

} // end namespace PRDF

#endif /* xspprdAccessPllChip_h */
