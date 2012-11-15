/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/iipErrorRegisterFilter.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2001,2012              */
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

#ifndef iipErrorRegisterFilter_h
#define iipErrorRegisterFilter_h

/**
 @file iipErrorRegisterFileter.h
 @brief ErrorRegisterFilter class declaration
*/

// Class Description *************************************************
//
//  Name:  ErrorRegisterFilter
//  Base class: ErrorRegister
//
//  Description: Error register with a filter
//  Usage: (see iipErrorRegisterMask.h)
//
//
// End Class Description *********************************************

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#if !defined(iipErrorRegister_h)
#include <iipErrorRegister.h>
#endif
#include <prdfFilters.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

/**
 Error register class with filtering capabilities
 @author Doug Gilbert
 */
class ErrorRegisterFilter : public ErrorRegister
{
public:

  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> Scan comm register to get bitString from hardware
   <br><b>Parameter:   </b> Resolution map to map bit pattern to a resolution
   <br><b>Parameter:   </b> scan comm register id for error signature
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None
   <br><b>Notes:       </b>
   </ul><br>
   */
  ErrorRegisterFilter(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, uint16_t scrId = 0x0fff);

  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> Scan comm register to get bitString from hardware
   <br><b>Parameter:   </b> Resolution map to map bit pattern to a resolution
   <br><b>Parameter:   </b> Filter to apply to bit string before mapping it
   <br><b>Parameter:   </b> scan comm register id
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None
   <br><b>Notes:       </b>
   </ul><br>
   */
  ErrorRegisterFilter(SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm, prdfFilter * f, uint16_t scrId = 0x0fff);

  /*
   Destructor
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> No value returned
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Compiler default is OK
   </ul><br>
   */
   //~ErrorRegisterFilter();

  /**
   * @brief Get the stored filter associated with this resolution map.
   * @returns Currently assigned filter.
   */
  prdfFilter * getFilter() const { return filter; };

  /**
   * @brief Store a new filter with this resolution map.
   * @param i - Filter to store.
   */
  void setFilter(prdfFilter * i_filter) { filter = i_filter; };

protected:  // functions

  /**
   Filter the bit string (if a filter is provided) & convert it to a BitList
   <ul>
   <br><b>Parameters:  </b> Bit String
   <br><b>Returns:     </b> Bit List
   <br><b>Requirements:</b> Read()
   <br><b>Promises:    </b> Bit list representation of the (filtered) bit string
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> filter is called only if provided
                            - DEFINTION in iipErrorRegisterMask.C
   </ul><br>
   */
  virtual prdfBitKey Filter(const BIT_STRING_CLASS & bs);

  /**
   * Certain filters need to be reversed in order for Reset() to work right
   * @return bit_list modified ? [true|false]
   * @see prdfFilters.H
   */
  virtual bool FilterUndo(prdfBitKey & i_bit_list)
  {
    bool modified = false;
    if(filter) modified = filter->Undo(i_bit_list);
    return modified;
  }

private: // functions

  /** Copy forbidden - no definition exists */
  ErrorRegisterFilter(const ErrorRegisterFilter & er);
  /** Assignment forbidden - no definition exists */
  ErrorRegisterFilter & operator=(const ErrorRegisterFilter & er);

protected: // data

  prdfFilter * filter;

private:  // Data

};

inline
ErrorRegisterFilter::ErrorRegisterFilter(SCAN_COMM_REGISTER_CLASS & r,
                                         ResolutionMap & rm,
                                         uint16_t scrId)
: ErrorRegister(r,rm,scrId), filter(NULL)
{}

inline
ErrorRegisterFilter::ErrorRegisterFilter(SCAN_COMM_REGISTER_CLASS & r,
                                         ResolutionMap & rm,
                                         prdfFilter * f,
                                         uint16_t scrId)
: ErrorRegister(r,rm,scrId), filter(f)
{}


#endif /* iipErrorRegisterFilter_h */

// Change Log *************************************************************************************
//
//  Flag Reason   Vers    Date     Coder    Description
//  ---- -------- ----    -------- -------- -------------------------------------------------------
//       P4907878 v5r2    04/27/01 dgilbert Initial Creation
//       423599   fsp     10/28/03 dgilbert make scrId a uint16_t
//       558003   fips310 06/21/06 dgilbert add get/setFilter() and FilterUndo
//
// End Change Log *********************************************************************************
