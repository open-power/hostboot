/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipDomainContainer.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 1996,2020                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#ifndef iipDomainContainer_h
#define iipDomainContainer_h

#ifndef iipDomain_h
#include <iipDomain.h>
#endif

#include <vector>

namespace PRDF
{

// Forward References
struct STEP_CODE_DATA_STRUCT;

/**
 Template class that Define a domain that contain other objects - typically
 chips.
 @par
 Contained objects must have interface like CHIP_CLASS see iipchip.h
 @note Parent class: Domain
 @par Usage Examples:
 @code

  // Create a Domain derived class holding chips of a specific type
  class MyChip: public CHIP_CLASS {....};

  class MyDomain : public DomainContainer<MyChip *>
  {
    MyDomain(DOMAIN_ID domainId);

    // Need to implement pure virtual functions
    virtual SINT32 Order(void); // put chip to analyze at top of list
  };

  void foo(MyChip * chipPtr)
  {
    MyDomain myDomain(ID, 10);    // Need to hold about 10 chips

    myDomain.AddChip(chipPtr);    // Add chip to list of chips
    //   ....

    if(myDomain.LookUp(0) == chipPtr)   // lookup first chip
    {
      // LookUp successfully returned pointer to the chip
    }
  }

  void f(Domain & myDomain,
         STEP_CODE_DATA_STRUCT & sevice_data,
         ATTENTION_TYPE system_attention_type)
  {
    if(myDomain->Query())  // if has attention
    {
      myDomain->Analyze(service_data, system_attention_type);
    }
  }
  @endcode
*/
template <class T>
class DomainContainer : public Domain
{
public:

  /**
   Constructor
   <ul>
   <br><b>Parameter:   </b> domainId: Identifies the Domain (See iipconst.h)
   <br><b>Parameter:   </b> size: Estimate of max number of chips in domain
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  DomainContainer(DOMAIN_ID domainId, unsigned int size = 5);

  // Function Specification ********************************************
  //
  // Purpose:      Copy
  // Parameters:   c: Reference to instance to copy
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members will be copied (Deep copy).
  // Exceptions:   None.
  // Concurrency:  N/A.
  // Notes:  This constructor is not declared.  This compiler generated
  //         default definition is sufficient.
  //
  // End Function Specification ****************************************
  //  DomainContainer(const DomainContainer<T> & c);

  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:  This destructor is not declared.  This compiler generated
  //         default definition is sufficient.
  //
  // End Function Specification ****************************************
  // virtual ~DomainContainer(void);

  // Function Specification ********************************************
  //
  // Purpose:      Assigment
  // Parameters:   c: Reference to instance to assign from
  // Returns:      Reference to this instance
  // Requirements: None.
  // Promises:     All data members are assigned to
  // Exceptions:   None.
  // Concurrency:  N/A.
  // Notes:  This assingment operator is not declared.  The compiler
  //         generated default definition is sufficient.
  //
  // End Function Specification ****************************************
  //  DomainContainer<T> & operator=(const DomainContainer<T> & c);

  /**
   Add a chip to this domain
   <ul>
   <br><b>Parameters:  </b> Pointer to a chip instance
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> GetSize()++
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void AddChip(T * chipPtr);

  /**
   Query domain for attention
   <ul>
   <br><b>Parameters:  </b> attentionType
   <br><b>Returns:     </b> true if 1 or more chips within the domain have
   the attention type specified otherwise false
   <br><b>Requirements:</b> GetSize() > 0, Initialize()
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  virtual bool Query(ATTENTION_TYPE attentionType);


  /**
   Determin which chip to Analyze and call it's Analyze() function
   <ul>
   <br><b>Parameter:   </b> serviceData (See iipServiceDataCollector.h)
   <br><b>Parameter:   </b> attentionType [MACHINE_CHECK|RECOVERED|SPECIAL]
   <br><b>Returns:     </b> return code (0 == SUCCESS)
   <br><b>Requirements:</b> Query() == true, Initialize()
   <br><b>Promises:    </b> serviceData complete
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> This implementation calls Order() to determin
   which chip to analyze and calls that chips
   Analyze() function.
   </ul><br>
   */
  virtual int32_t Analyze(STEP_CODE_DATA_STRUCT & serviceData,ATTENTION_TYPE attentionType);

  /**
   Returns a pointer to the chip at the specified index
   <ul>
   <br><b>Parameters:  </b> chipIndex
   <br><b>Returns:     </b> pointer to a Chip of type T | nullptr
   <br><b>Requirements:</b> AddChip(), 0 <= chipIndex < GetSize()
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> nullptr is return if chipIndex is out of range
   </ul><br>
   */
  const T * LookUp(unsigned int chipIndex) const;
  T * LookUp(unsigned int chipIndex);

  /**
   Return the number of chips in the domain
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> number of chips in the domain
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  uint32_t GetSize(void) const;

protected:


  /**
   Swaps the position of two chips in the chip list
   <ul>
   <br><b>Parameters:  </b> chip indexes of chips to swap
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> indexes < GetSize(), & >= 0
   <br><b>Promises:    </b> chiplist order modified
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void Swap(unsigned int index1, unsigned int index2);

  /**
   * Moves the specified chip to the front of the list but preserves the
   * rest of the order.
   */
  void MoveToFront(unsigned int index); // pw01

// @jl02 a Start
  /**
   Removes a chip from the list inside of each Domain that contains it.
   It will leave the list at the system level for later deletion.
   <ul>
   <br><b>Parameters:  </b> chip identifier of chip to remove
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void Remove(TARGETING::TargetHandle_t i_chip);

private:

  // void * is used to reduce template code bloat
  // the chip type T is restored whenever a reference to a chip
  // is requested
  typedef std::vector<void *>         ChipContainerType;

  ChipContainerType              chips;


};

} // end namespace PRDF

#include "iipDomainContainer.inl"

//#ifdef RS6000 -- changed for V4R1 Bali - 2/27/96 JFP
#ifndef __GNUC__
#include "iipDomainContainer.C"
#endif

#endif
