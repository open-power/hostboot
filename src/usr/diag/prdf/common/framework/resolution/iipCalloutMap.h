/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipCalloutMap.h $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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

#ifndef iipCalloutMap_h
#define iipCalloutMap_h

// Class Description *************************************************
//
//  Name:  iipCalloutMap
//  Base class:
//
//  Description: Map ChipiD's to Mru callouts
//  Usage:
//
//  CalloutMap calloutMap();
//
//  foo(CalloutMap & calloutMap, CHIP_CLASS * chip)
//  {
//    uint32_t chip_id = chip->GetId();
//    MruCallout m1 = calloutMap.GetCallout(chip_id,HIGH);
//  }
//
// End Class Description *********************************************
//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#if !defined(PRDF_TYPES_H)
  #include <prdf_types.h>
#endif

#include <prdfCallouts.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

namespace PRDF
{

/**
 Convert a chipid to a mru callout
 @author Douglas R. Gilbert
 @version V4R5
*/
class CalloutMap
{
public:

  enum probability { HIGH_PROBABILITY, LOW_PROBABILITY };

  /**
   CTOR
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> None
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  CalloutMap();

  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:        Compiler default is sufficient
  //
  // End Function Specification ****************************************
  // ~iipCalloutMap();


  /**
   Return a MruCallout for a chipId (Apache/Northstar)
   <ul>
   <br><b>Parameters:  </b> chipId, probability
   <br><b>Returns:     </b> MruCallout
   <br><b>Requirements:</b> Valid chipId
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Implemented for Apache and Northstar only
   </ul><br>
   */
  //MruCallout GetCallout(uint32_t chipId, probability prb = HIGH_PROBABILITY) const;

  /**
   Get a MruValues for a chipId (Condor/CSP)
   <ul>
   <br><b>Parameters:  </b> ChipId
   <br><b>Returns:     </b> MruValues (see xspiiCallout.h)
   <br><b>Requirements:</b> Valid chipId
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Implemented for Condor and CSP only
   </ul><br>
   */
  PRDF::MruValues GetMruCallout(uint32_t chipId) const;

  /**
   Get a MruValues for a chipId (Regatta/CSP)
   <ul>
   <br><b>Parameters:  </b> ChipEnum
   <br><b>Returns:     </b> MruValues (see xspiiCallout.h)
   <br><b>Requirements:</b> Valid chipEnum
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Implemented for Regatta and CSP only
   </ul><br>
   */
  PRDF::MruValues GetMruCallout(ChipEnum chipEnum) const;

private:  // functions
private:  // Data

};

} // end namespace PRDF

#endif /* iipCalloutMap_h */

// Change Log *********************************************************
//
//  Flag Reason   Vers Date     Coder Description
//  ---- -------- ---- -------- ----- -------------------------------
//       d24758.1 v4r1 05/20/96 DRG   Initial Creation
//       D49127.7 V4R1 09/27/96 DRG   Made data static
//       D49274.1 V4R5 06/08/98 DRG   MOdify to support v4r5
//       D49420.x v5r2 07/17/00 mak   modify to support v5r2
//
// End Change Log *****************************************************
