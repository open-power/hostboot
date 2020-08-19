/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/iipSystem.h $       */
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

#ifndef iipSystem_h
#define iipSystem_h

// Class Specification *************************************************
//
// Class name:   System
// Parent class: None.
//
// Summary: This class provides access to the domains and chips of the
//          actual hardware system.  The System is initially set up with
//          one or more calls to the Add...() functions in which Domains
//          and Chips are added to the system. The System assumes the
//          ownership of the pointers to the chips and domains that are
//          added to the system and will delete the associated chip and
//          domain objects when the destructor of the System is called.
//
//          The Initialize() function calls the Initialize() funciton
//          for each Chip and Domain in the System.  The function is
//          also virtual so that it can be overidden in a derived class
//          for a specific system initialization behaviour.
//
//          The Analyze() function determins which Domain Analzye() function
//          to call. The prioritization for Domain Analysis
//          is based on the value of the Domain ID.  The lower Domain
//          ID has higher priority.  When Analyze() is called, the Domains
//          are queried for attention status starting with the highest
//          priority Domain and moving to the lowest.
//          The first Domain that returns true from Query() will have its
//          Analyze() function called.
//
// Cardinality: N
//
// Performance/Implementation:
//   Space Complexity: Linear based on the number of domains and chips
//                     configured in the hardware system.
//   Time Complexity:  All member functions constant unless otherwise
//                     stated.
//
// Usage Examples:
//
// extern CHIP_CLASS * chips[CHIP_COUNT];
// extern Domain * domains[DOMAIN_COUNT];
// extern ServiceDataCollector sdc;
//
// void foo(void)
//   {
//   System system;
//
//   system.Add(chips, chips + CHIP_COUNT);
//   system.Add(domains, domains + DOMAIN_COUNT);
//
//   CHIP_CLASS * system.GetChip(CHIP_ID);
//   Domain * system.GetDomain(DOMAIN_ID);
//
//   system.Initialize();
//
//   system.Analyze(sdc);
//   }
//
// End Class Specification *********************************************

#include <vector>
#include <map>

#include <iipconst.h>   //TARGETING::TargetHandle_t, DOMAIN_ID_TYPE

#include <iipsdbug.h>    // Include file for ATTENTION_TYPE

namespace PRDF
{

// Forward Declarations
class CHIP_CLASS;
class Domain;
class Resolution;
class RuleMetaData ;
class ScanFacility;
class ResolutionFactory;

struct STEP_CODE_DATA_STRUCT;
typedef std::map< TARGETING::TYPE ,RuleMetaData *> RuleMetaDataList ;

class System
  {
  private:

    typedef std::vector<CHIP_CLASS *>::iterator ChipContainerIterator;
    typedef std::vector<Domain *>::iterator DomainContainerIterator;

  public:

    System(Resolution & noSystemAttentions);
  // Function Specification ********************************************
  //
  // Purpose:      Initialization
  // Parameters:   A resolution to resolve the serviceData if no
  //               attentions are found in the configured system
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     All data members are initialized.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  //
  // End Function Specification //////////////////////////////////////

  //  System(const System & c);
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

    virtual ~System(void);
  // Function Specification ********************************************
  //
  // Purpose:      Destruction
  // Parameters:   None.
  // Returns:      No value returned
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Reentrant
  // Notes:  This destructor deletes each Chip and Domain instance in
  //         the respective containers.
  //
  // End Function Specification ****************************************

  //  System & operator=(const System & c);
  // Function Specification ********************************************
  //
  // Purpose:      Assigment
  // Parameters:   Handle to the chip
  // Returns:      Reference to this instance
  // Requirements: None.
  // Promises:     All data members are assigned to
  // Exceptions:   None.
  // Concurrency:  N/A.
  // Notes:  This assingment operator is not declared.  The compiler
  //         generated default definition is sufficient.
  //
  // End Function Specification ****************************************

    CHIP_CLASS * GetChip(TARGETING::TargetHandle_t i_pchipHandle);
  // Function Specification ********************************************
  //
  // Purpose:      Get Chip
  // Parameters:   chipId: Specifies chip to get
  // Returns:      Pointer to CHIP_CLASS
  // Requirements: None.
  // Promises:     Return a pointer to the requested chip if it exists
  // Exceptions:   None.
  // Concurrency:  Reentrant.
  // Notes:  If the specified chip is not in the System, then nullptr is
  //         returned.
  //
  // End Function Specification ****************************************

    Domain * GetDomain(DOMAIN_ID domainId);
  // Function Specification ********************************************
  //
  // Purpose:      Get Domain
  // Parameters:   domainId: Specifies domain to get
  // Returns:      Pointer to Domain.
  // Requirements: None.
  // Promises:     Return a pointer to the requested domain if it exists
  // Exceptions:   None.
  // Concurrency:  Reentrant.
  // Notes:  If the specified domain is not in the System, then nullptr is
  //         returned.
  //
  // End Function Specification ****************************************

    void AddChips(ChipContainerIterator begin,
      ChipContainerIterator end);
  // Function Specification ********************************************
  //
  // Purpose:      Adds a Chips to the system
  // Parameters:   begin: Iterator to first Chip to add
  //               end: Iterator to end Chip to add
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     Pointer to chip stored in system, Pointer ownership assumed
  // Exceptions:   None.
  // Concurrency:  Nonreentrant.
  //
  // End Function Specification ****************************************

    void AddDomains(DomainContainerIterator begin,
      DomainContainerIterator end);
  // Function Specification ********************************************
  //
  // Purpose:      Adds Domains to the system
  // Parameters:   Handle of chip that check stopped
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     Pointer Domain stored in system, Pointer ownership assumed
  // Exceptions:   None.
  // Concurrency:  Nonreentrant.
  //
  // End Function Specification ****************************************

    void RemoveStoppedChips(TARGETING::TargetHandle_t i_pChipHandle);    //@jl02 Unit Check Stop code added

  // Function Specification ********************************************
  //
  // Purpose:      Removes a chip from a Domain that this chip is in if we no longer
  //                 want to have the chip within prds view.
  // Parameters:   chip:  Chip ID to be changed.
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Nonreentrant.
  //
  // End Function Specification ****************************************

    void RemoveNonFunctionalChips();    //@jl04 a Add code to remove non functional
  // Function Specification ********************************************
  //
  // Purpose:      Removes chips from a Domain if we no longer
  //                 want to have the chips that are nonfunctional in HOM.
  // Parameters:   None.
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     None.
  // Exceptions:   None.
  // Concurrency:  Nonreentrant.
  //
  // End Function Specification ****************************************


    virtual void Initialize();
  // Function Specification ********************************************
  //
  // Purpose:      Initializes all chip and domains
  // Parameters:   refCode: Reference code to use if error
  //               stepCode: Step code to use if error
  // Returns:      No value returned.
  // Requirements: None.
  // Promises:     Initialize function on all chip and domains called unless
  //               an error occurrs in one of the Initialize functions.
  // Exceptions:   None.
  // Concurrency:  Reentrant.
  // Notes: The Initialize() function for each Chip and Domain is
  //        called.  If an error code is returned from a Chip or Domain
  //        Initialize call, then SrcFill is called with the specified
  //        reference code, step code, and return code.  No further calls
  //        are made when an error occurs.
  //
  // End Function Specification ****************************************

    virtual int32_t Analyze( STEP_CODE_DATA_STRUCT & io_sc );

  // Function Specification ********************************************
  //
  // Purpose:      Analyze domains for an error
  // Parameters:   io_sc: Reference to pass back error data in
  // Returns:      Error value
  // Requirements: None.
  // Promises:     ServiceData completed unless error encountered
  // Exceptions:   None.
  // Concurrency:  Reentrant.
  // Notes: Each Domain is queried using the prioritization sequence.
  //        The first Domain that returns true from Domain Query()
  //        will have its Analyze() function called.  If
  //        there are no Domains, then the error code
  //        NO_DOMAINS_IN_SYSTEM(0xDD20) is returned.  If there are no
  //        Domains at attention, then the error code
  //        NO_DOMAINS_AT_ATTENTION(0xDD21) is returned.
  //

   /**
    * @brief        Get instance of RuleMetaData associated with given target
    *               type.
    * @param[in]    i_type          target type associated with RuleMetaData.
    * @param[in]    i_fileName      name of RuleFile associated
    * @param[in]    i_scanFactory   reference to factory class which
    *                               creates register instance.
    * @param[in]    i_reslFactory   reference to factory which creates
    *                               resolution instance.
    * @param[o]     o_errl          error log handle
    */

    RuleMetaData* getChipMetaData( TARGETING::TYPE i_type,
                                const char *i_fileName,
                                ScanFacility & i_scanFactory,
                                ResolutionFactory & i_reslFactory,
                                errlHndl_t & o_errl );

  // End Function Specification ****************************************

  private:

    typedef std::vector<CHIP_CLASS *> ChipMapType;

    typedef std::vector<Domain *>     DomainContainerType;

    ChipMapType                   chips;

    DomainContainerType           prioritizedDomains;

    Resolution & noAttnResolution;
    RuleMetaDataList iv_listRuleData ;
  };

} // end namespace PRDF

#endif
