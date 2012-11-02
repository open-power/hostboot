/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/CcAutoDeletePointer.h $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1995,2012              */
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

#ifndef CcAutoDeletePointer_h
#define CcAutoDeletePointer_h

// Class Specification *************************************************
//
// Class name:   CcAutoDeletePointer
// Parent class: None.
//
// Summary: This class is used to implement an automatic delete on a
//          pointer to memory obtained via new for a single instance.
//          Its primary purpose is for use in functions that create a
//          single instance dynamically and then perform some operations
//          that may throw an exception.
//
//          This class should be used as a local variable so that when the
//          varaible goes out of scope, the destructor is called and the
//          memory pointer is deleted.  Because the variable is local, if
//          an exception is thrown, it is guaranteed that the destructor
//          for this variable will be run and the memory pointer will be
//          deleted properly.
//
//          Access to the pointer is available through the pointer
//       dereference operators, operator->() and
//       operator*().  The normal delete syntax is used
//       (i.e. "delete ptr;").
//
// Cardinality: N
//
// Performance/Implementation:
//   Space Complexity: Constant
//   Time Complexity:  Constant
//
// Usage Examples:
//
// struct MyType
//   {
//   void bar(void);
//   };
//
// void foo(void)
//   {
//   CcAutoDeletePointer<MyType> ptr(new MyType());
//
//   // Operations that may throw an exception
//
//   ptr->bar();    // Using the pointer
//
//   (*ptr).bar();  // Dereferencing
//   }
//
//
// End Class Specification *********************************************

// Includes

namespace PRDF
{

template <class T>
class CcAutoDeletePointer
  {
  public:    // public member functions

   CcAutoDeletePointer(T * ptr);
  // Function Specification ********************************************
  //
  // Purpose:      Initialization
  // Parameters:   ptr: Pointer to auto-delete
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  N/A
  //
  // End Function Specification ****************************************

    ~CcAutoDeletePointer(void);
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  N/A
  // Notes:  The function deletes the data member pointer.
  //
  // End Function Specification ****************************************

    T * operator->(void) const;
  // Function Specification ********************************************
  //
  // Purpose:      Provide access to pointer.
  // Parameters:   None.
  // Returns:      Pointer to template type.
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  //
  // End Function Specification ****************************************

    T & operator*(void) const;
  // Function Specification ********************************************
  //
  // Purpose:      Provide access to pointer.
  // Parameters:   None.
  // Returns:      Reference to template type.
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  //
  // End Function Specification ****************************************

  private:

    CcAutoDeletePointer(const CcAutoDeletePointer<T> & e);
  // Function Specification ********************************************
  //
  // Purpose:      Copy
  // Parameters:   e: Reference to instance to copy
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  N/A.
  // Notes:  This copy constructor is declared private and not defined
  //         to prohibit copying.
  //
  // End Function Specification ****************************************

    CcAutoDeletePointer<T> & operator=(const CcAutoDeletePointer<T> & e);
  // Function Specification ********************************************
  //
  // Purpose:      Assigment
  // Parameters:   e: Reference to instance to assign from
  // Returns:      Reference to this instance
  // Requirements: None.
  // Promises:     All data members will be assigned.
  // Exceptions:   N/A.
  // Concurrency:  N/A.
  // Notes:  This assignment operator is declared private and not defined
  //         to prohibit copying.
  //
  // End Function Specification ****************************************

    T *                            pointer;

  };

// Class Specification *************************************************
//
// Class name:   CcAutoDeletePointerVector
// Parent class: None.
//
// Summary: This class is used to implement an automatic delete on a
//          pointer to memory obtained via new for multiple instances.
//          Its primary purpose is for use in functions that allocate
//          multiple instances dynamically (e.g. "T * ptr = new T[5];")
//          and then perform some operations that may throw an
//          exception.
//
//          This class should be used as a local variable so that when the
//          varaible goes out of scope, the destructor is called and the
//          memory pointer is deleted.  Because the variable is local, if
//          an exception is thrown, it is guaranteed that the destructor
//          for this variable will be run and the memory pointer will be
//          deleted properly.
//
//          Access to the pointer is available through operator().  The
//          vector delete syntax is used (e.g. "delete [] ptr;").
//
// Cardinality: N
//
// Performance/Implementation:
//   Space Complexity: Constant
//   Time Complexity:  Constant
//
// Usage Examples:
//
// void foo(void)
//   {
//   CcAutoDeletePointerVector<char> ptr(new char[4]);
//
//   // Operations that may throw an exception
//
//   strcpy(ptr(), "abc");  // Using the Pointer
//   }
//
//
// End Class Specification *********************************************

template <class T>
class CcAutoDeletePointerVector
  {
  public:    // public member functions

   CcAutoDeletePointerVector(T * ptr);
  // Function Specification ********************************************
  //
  // Purpose:      Initialization
  // Parameters:   ptr: Pointer to auto-delete
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  N/A
  //
  // End Function Specification ****************************************

    ~CcAutoDeletePointerVector(void);
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  N/A
  // Notes:  The function deletes the data member pointer.
  //
  // End Function Specification ****************************************

    T * operator()(void) const;
  // Function Specification ********************************************
  //
  // Purpose:      Provide access to pointer.
  // Parameters:   None.
  // Returns:      Pointer to template type.
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  //
  // End Function Specification ****************************************

  private:

    CcAutoDeletePointerVector(const CcAutoDeletePointerVector<T> & e);
  // Function Specification ********************************************
  //
  // Purpose:      Copy
  // Parameters:   e: Reference to instance to copy
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  N/A.
  // Notes:  This copy constructor is declared private and not defined
  //         to prohibit copying.
  //
  // End Function Specification ****************************************

    CcAutoDeletePointerVector<T> & operator=(
      const CcAutoDeletePointerVector<T> & e);
  // Function Specification ********************************************
  //
  // Purpose:      Assigment
  // Parameters:   e: Reference to instance to assign from
  // Returns:      Reference to this instance
  // Requirements: None.
  // Promises:     All data members will be assigned.
  // Exceptions:   N/A.
  // Concurrency:  N/A.
  // Notes:  This assignment operator is declared private and not defined
  //         to prohibit copying.
  //
  // End Function Specification ****************************************

    T *                            pointer;

  };

} // end namespace PRDF

#include <CcAutoDeletePointer.inl>

#endif

