/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipConfigurator.h $ */
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

#ifndef Configurator_h
#define Configurator_h

// Class Specification ************************************************/
//
//  Name:  Configurator
//  Parent class: None.
//
//  Summary: Instantiates a chip object for each hardware chip that
//           is marked as functional in the syspit. Instantiates all
//           the PRD Domains and assigns chip objects to them. Creates
//           the system and transfers chip and domain lists to it.
//
//## Class: Configurator; Abstract
//## Category: PRDCommon
//## Subsystem: PRDCommon
//## Concurrency: Sequential
//## Persistence: Transient
//## Cardinality: 1
//## Uses    iipspit {1 -> 1}
//## Creates instances of: Domain {1 -> n}
//## Creates instances of: CHIP_CLASS {1 -> n}
//
// Notes: There is only one type of configurator per PRD bind which is
//        determined at compile time by the definition of getConfiguratorPtr()
//
// Usage Example:
//        Configurator * c = getConfiguratorPtr(); // CreateConfigurator
//        System *system = c->build();
//        if(!rc)
//        {
//           Configurator::chipList cl  = c->getChipList();
//           Configurator::domainList d = c->getDomainList();
//        }
//        .
//        .
//        delete c;
//       BIG NOTE:
//      (Delete will NOT destroy the chip or domain instances created by
//       the build function - only the vectors of pointers to the instances)
//
// End Class Specification ********************************************/
//----------------------------------------------------------------------
// Reference the virtual function tables and inline function
// defintions in another translation unit.
//----------------------------------------------------------------------

// Includes
#if (!defined(_CPU_H) && !defined(CPU_H))
//#include <cpu.h>
#endif

#include <prdfMain.H>

#include <vector>

namespace PRDF
{

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/
class CHIP_CLASS;
class Domain;
class System;

class Configurator
{
public:

  typedef std::vector<CHIP_CLASS *> chipList;
  typedef std::vector<Domain *> domainList;

  static Configurator * getConfiguratorPtr();
      // Function Specification *************************************
      //
      // Purpose: returns a ptr to an instance of the Configurator
      // Notes: There is one and only one type of configurator for each
      //        hardware platform - the correct one is determined at
      //        compile time by the definition of this function.
      //        new is used to create the object and can be
      //        deleted when it is no longer needed.
      //
      // End Function Specification *********************************

    //## Destructor (generated)
  virtual ~Configurator();

  virtual System * build()=0;
  // Function Specification ********************************************
  //
  // Purpose:  Builds chipList and domainList and system
  // Parameters: None
  // Returns:    Ptr to system | NULL
  // Requirements: Global ptr to syspit object has been initialized
  // Promises:  All chip objects and domain objects for system intantiated
  // Exceptions: None
  // Concurrency: Sequential
  // Notes:
  //        Instantiate a chip object for each hardware chip that is
  //        marked as functional in the syspit.
  //        Instantiates the domains in the system and assign chips.
  //        This function should only be called once.
  //    If any fail conditions are encoutered then an SRC is written to
  //    the SOT using SRCFILL. If NULL is returned then chiplist and
  //    domainlist may not be complete.
  //
  // End Function Specification ******************************************

protected:

  chipList & getChipList() { return(sysChipLst); }
  // Function Specification ********************************************
  //
  // Purpose:  Get reference to a vector of pointers to chips
  // Parameters: None
  // Returns:    Reference to chipList
  // Requirements: Build must have been called prior to this
  // Promises:  chipList contains all chip objects for the system
  // Exceptions: None
  // Concurrency: Sequential
  //
  // End Function Specification ******************************************

  domainList & getDomainList() { return(sysDmnLst); }
  // Function Specification ********************************************
  //
  // Purpose:  Get reference to a vector of pointers to domains
  // Parameters: None
  // Returns:    Reference to domainList
  // Requirements: Build must have been called prior to this
  // Promises:  domainList contains all domain objects for the system
  //            the appropriate chips have been assigned to each domain
  // Exceptions: None
  // Concurrency: Sequential
  //
  // End Function Specification ******************************************

protected:
  Configurator(int max_chips = 50, int max_domains = 4)
  {
    sysChipLst.reserve(max_chips);
    sysDmnLst.reserve(max_domains);
  }
  // Function Specification ********************************************
  //
  // Purpose:      Constructor
  // Parameters:   Maximum number of chips and domains expected in the system
  //             Specifying maximums causes memory to be managed more efficiently
  // Returns:      Nothing
  // Requirements: None
  // Promises:     Instance of this class created
  // Exceptions:   None
  // Concurrency:  Sequential
  //
  //
  // End Function Specification ******************************************

//## Equality Operations (generated)
//    int operator==(const Configurator &right) const;
//    int operator!=(const Configurator &right) const;


  chipList sysChipLst;        // List of chips in the system
  domainList sysDmnLst;       // List of domains in the system

private:

  Configurator(const Configurator &right);
  const Configurator & operator=(const Configurator &right);

     // Function Specification ********************************************
     //
     // Purpose:      Copy constructor / Assignment operator
     // Parameters:   Reference to instance of Configurator
     // Returns:      Nothing
     // Requirements: These operations are not allowed
     // Promises:     Prevents copies / Assignments from being made
     // Exceptions:   None
     // Concurrency:  n/a
     // Notes:        No definition should exist
     //
     // End Function Specification ****************************************

};

} // End namespace PRDF

#endif
