/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipchip.h $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1993,2013              */
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

#ifndef IIPCHIP_H
#define IIPCHIP_H

/**
 @brief
 This module contains the Processor Runtime Diagnostics Chip class declaration.
 @file iipchip.h
*/


#if !defined(PRDF_TYPES_H)
#include <prdf_types.h>
#endif

#if !defined(IIPSDBUG_H)
  #include <iipsdbug.h>     // for ATTENTION_TYPE
#endif

#if !defined(PRDF_MAIN_H)
  #include <prdfMain.H>
#endif

#include <iipconst.h>

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

namespace PRDF
{

class STEP_CODE_DATA_STRUCT;
class CaptureData;

/**
 CHIP_CLASS - model of hardware chip and functions needed by PRD

 Abstract base class

@Notes
            This Chip specifies a common interface for hardware chips.
            Associated with every hardware chip is an index to a data
            location in the SP SYS Debug global data area.  This index
            is specified during instantiation and is maintained
            internally.  The accessor function GetErrorEntryIndex()
            returns this value.  Each chip also has a logical ID for
            indentifying specific instances.  The accessor function
            GetId() that this value.
@par
            The pure virtual Analyze() function provides a standard
            interface for analyzing Chip errors.  The basic
            algorithm must be defined for each derived class.
@par
            The pure virtual MaskError() function provides a standard
            interface for masking a Chip error.  The basic
            mechanism for maksing is defined in each derived class.
@par
            Two pure virtual functions are used to provide Chip
            specific data for external Manual Ops SCR interfaces.
            Chip select parameters are passed to these functions.
            Derived classes define the function GetChipSelectValues()
            to return an array of these values as needed.  The derived
            classes must then also define the function
            GetChipSelectCount() to return the number of values in
            this array.
@par
            The virtual Initialize() function provides a standard
            interface for initializing the state of the hardware Chip.
            This may also involve changing internal data members.  A
            default implementation will be provided that does
            nothing.                                                  */

class CHIP_CLASS
{
  public:

    /**
     Destructor
     <ul>
     <br><b>Parameters:  </b> None
     <br><b>Requirements:</b> None.
     <br><b>Promises:    </b> ojbect destroyed - any resourses deallocated
     </ul><br>
     */
    virtual ~CHIP_CLASS();

    /**
     Access the target handle  for this chip
     <ul>
     <br><b>Parameters:  </b> none
     <br><b>Returns:     </b> Handle for this chip
     <br><b>Requirements:</b> None
     <br><b>Promises:    </b> None
     <br><b>Notes:       </b> Not to be used previous to Regatta
     </ul><br>
     */
    TARGETING::TargetHandle_t GetChipHandle() const
    {
        return iv_pchipHandle;
    }

    /**
     Initialize hardware associated with this chip object
     <ul>
     <br><b>Parameters:  </b> parms
     <br><b>Returns:     </b> return code (usually Mops return code)
     <br><b>Requirements:</b> System.build() complete
     <br><b>Promises:    </b> Hardware state may be modified
     <br><b>Exceptions:  </b> None.
     <br><b>Notes:       </b> Default implementation is to do nothing
     </ul><br>
     */
    virtual int32_t Initialize();

    /**
     * @brief  Analyze the error being reported by this chip
     * @param  data           Service Data Collector
     * @param  attention_type [MACHINE_CHECK | RECOVERED | SPECIAL]
     * @return return code (see iipconst.h for PRD return codes) otherwise it's
     *         a MOPs return code
     * @pre    Initiialize(). The hardware chip this object represents drove
     *         attention.
     * @post   ServiceData complete. Hardware state may be modified.
     */
    virtual int32_t Analyze( STEP_CODE_DATA_STRUCT & data,
                             ATTENTION_TYPE attention_type ) = 0;

    /**
     Mask the reporting of an error by the hardware associated with this chip
     <ul>
     <br><b>Parameters:  </b> maskId
     <br><b>Returns:     </b> return code (usually from MOPs)
     <br><b>Requirements:</b> Initialize()
     <br><b>Promises:    </b> Hardware state modified
     </ul><br>
     */
    virtual int32_t MaskError( uint32_t error_mask_id ) = 0;

    /**
     Capture the contents of certain registers withing the hardware
     <ul>
     <br><b>Parameters:  </b> cd:Capture data object (to store the capture data)
     <br><b>Returns:     </b> return code (usually from MOPs)
     <br><b>Requirements:</b> Initialize()
     <br><b>Promises:    </b> None.
     <br><b>Notes:       </b> default is to do nothing
     </ul><br>
     */
    virtual int32_t CaptureErrorData(CaptureData & cd)
    {
        return 0;
    }

    /**
     Returns the  HUID of the chip
     <ul>
     <br><b>Parameters:  </b> Nil
     <br><b>Returns:     </b> HUID of the chip
     <br><b>Requirements:</b> chip Handle
     <br><b>Promises:    </b> None.
     <br><b>Notes:       </b> default is to do nothing
     </ul><br>
     */
    HUID GetId() const;

  protected:

    /**
     Constructor
     <ul>
     <br><b>Parameters:  </b> i_pChipHandle: Handle for this chip
     <br><b>Returns:     </b> N/A
     <br><b>Requirements:</b> Id must be unique
     <br><b>Promises:    </b> object instanciated
     <br><b>Exceptions:  </b> None.
     </ul><br>
     */
    CHIP_CLASS( TARGETING::TargetHandle_t i_pChipHandle ) :
        iv_pchipHandle(i_pChipHandle)
    {}

    // Function Specification //////////////////////////////////////////
    //
    // Title:  CHIP_CLASS (Copy constructor)
    //
    // Purpose: This constructor does nothing.  The compiler generated
    //          function is sufficient.  It does not need to be called
    //          by derived class assingment operators.
    //
    // Side-effects:  This instance is initialized.
    //
    // Dependencies:  None.
    //
    // End Function Specification //////////////////////////////////////

    // Function Specification //////////////////////////////////////////
    //
    // Title:  operator= (assignment operator)
    //
    // Purpose:  This assignment operator does nothing.   This defintion
    //           is provided for an explicit call from a derived class
    //           assignment operator.  It does not need to be called by
    //           a derived class assignment operator.
    //
    // Side-effects:  None.
    //
    // Dependencies:  None.
    //
    // End Function Specification //////////////////////////////////////

    CHIP_CLASS & operator=(const CHIP_CLASS & chip)
    {
        return(*this);
    }

  private:

    TARGETING::TargetHandle_t iv_pchipHandle;

};

} // end namespace PRDF

#endif
