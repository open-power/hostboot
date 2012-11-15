/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/xspprdAccessPllChip.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2000,2012              */
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

#endif /* xspprdAccessPllChip_h */
