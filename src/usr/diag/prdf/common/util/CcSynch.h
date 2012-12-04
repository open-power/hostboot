/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/CcSynch.h $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1995,2013              */
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

#ifndef CcSynch_h
#define CcSynch_h

// Class Specification *************************************************
//
// Class name:   CcSynch
// Parent class: None.
//
// Summary: This class is used as a synchronization mechanism.  A
//          static step counter is maintained and incremented via the
//          static member function Advance().  An internal step counter
//          is also maintained.  The member function IsCurrent()
//          compares the two values to indicate if this instance is
//          "in synch".  Calling the IsCurrent() functiona also updates
//          the internal counter to the static counter.
//
//          The primary use is to ensure that an operation is performed
//          only once over a given time interval.  The time interval
//          is controlled by successive calls to Advance().  If an
//          instance is not current, then the operation is performed
//          and the instance will then be current.
//
//          The parameterized type STEP_TYPE is used for the type of
//          the counters.  This type should be selected according to
//          the necessary granularity.  For example, an 8 bit integer
//          value allows for 256 unique counter values.
//
//          The parameterized type ID is used to diferentiate an
//          instantiation of this tmeplate from other instantiations.
//          This class relies on a unique static data member which is
//          generated for each unique instantiation.
//
// Cardinality: N
//
// Performance/Implementation:
//   Space Complexity: Constant
//   Time Complexity:  Constant
//
// Usage Examples:
//
// struct mytype {};
//
// void foo(CcSynch<int, mytpe> & synch)
//   {
//   synch.Advance();
//
//   if(synch.IsCurrent())
//     {
//     // Operation is performed
//     }
//
//   if(synch.IsCurrent())
//     {
//     // Operation is not performed
//     }
//   }
//
//
// End Class Specification *********************************************

// Includes

namespace PRDF
{

template <class STEP_TYPE, class ID>
class CcSynch
  {
  public:    // public member functions

     typedef STEP_TYPE StepType;

     enum
       {
       STATIC_INITIAL_VALUE = 1,
       INSTANCE_INITIAL_VALUE = 0
       };

     static void Advance(void);
  // Function Specification ********************************************
  //
  // Purpose:      Advances the static data member step.
  // Parameters:   None.
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     Static data member step will be incremented.
  // Exceptions:   None.
  // Concurrency:  Reentrant.
  //
  // End Function Specification ****************************************

   CcSynch(void);
  // Function Specification ********************************************
  //
  // Purpose:      Initialization
  // Parameters:   No parameters
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  N/A
  //
  // End Function Specification ****************************************

  //  CcSynch(const CcSynch & e);
  // Function Specification ********************************************
  //
  // Purpose:      Copy
  // Parameters:   e: Reference to instance to copy
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  N/A.
  // Notes:  The compiler generated copy constructor is sufficient.
  //
  // End Function Specification ****************************************

  //  ~CcSynch(void);
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  N/A
  // Notes:  The compiler generated default destructor is sufficient.
  //
  // End Function Specification ****************************************

  //  CcSynch & operator=(const CcSynch & e);
  // Function Specification ********************************************
  //
  // Purpose:      Assigment
  // Parameters:   e: Reference to instance to assign from
  // Returns:      Reference to this instance
  // Requirements: None.
  // Promises:     All data members will be assigned.
  // Exceptions:   N/A.
  // Concurrency:  N/A.
  // Notes:  The compiler generated default assignment operator is
  //         sufficient.
  //
  // End Function Specification ****************************************

    bool IsCurrent(void);
  // Function Specification ********************************************
  //
  // Purpose:      Determines if myStep is current with step.
  // Parameters:   None.
  // Returns:      TRUE if myStep is current with step. Otherewise,
  //               FALSE.
  // Requirements: None.
  // Promises:     myStep will be current with step.
  // Exceptions:   None..
  // Concurrency:  Reenetrant.
  //
  // End Function Specification ****************************************

  private:

    static StepType                step;

    StepType                       myStep;
  };

} // end namespace PRDF

#include "CcSynch.inl"

#endif

