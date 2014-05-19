/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/predicates/predicateisfunctional.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef  __TARGETING_COMMON_PREDICATEISFUNCTIONAL_H
#define  __TARGETING_COMMON_PREDICATEISFUNCTIONAL_H
/**
 *  @file targeting/common/predicates/predicateisfunctional.H
 *
 *  PredicateIsFunctional class, used to filter targets for HWP wrapper.
 *  From the example tutorial page at
 *  https://w3-connections.ibm.com/wikis/home?lang=en_US#/wiki/Host%20Boot/page/Target%20And%20Attribute%20Usage%20Guide
 *  :
 *  Create Custom Predicate
 *  Take the following predicate "template" and customize to your needs.
 *  Make sure to:
 *      1) Rename the class in the appropriate places
 *      2) Implement the operator() function which should return "true" if
 *          the given Target matches the predicate criteria, false otherwise
 *      3) Add any input arguments to the constructor, and any necessary
 *          private variables to store state
 *      4) Implement the destructor, if needed
 *      5) Update documentation
 *
 *      See example in src/include/usr/targeting/predicate/predicatectm.H
 *      (and usr/targeting/predicate/predicatectm.C)
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

//  targeting support.
#include <targeting/common/attributes.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicatectm.H>


namespace   TARGETING
{

class PredicateIsFunctional : public PredicateBase
{

public:

    /**
     *  @brief Create a predicate to select targets that
     *   are marked functional.
     *   Default (no parms) is to check for functional: assumption is that
     *   functional implies poweredOn, etc.
     *   More function will probably be added later.
     *
     */
    PredicateIsFunctional( );


    /**
     *  @brief Destroy the predicate
     */
    virtual ~PredicateIsFunctional();

    /**
     *  @brief returns true if target is marked functional
     *
     *  @param[in] i_pTarget
     *      Handle to the target to perform the predicate check on
     *
     *  @return bool indicating whether target it functional or not
     */
    bool operator()(const TARGETING::Target* i_pTarget) const ;

private:

    TARG_DISABLE_COPY_AND_ASSIGNMENT_OPERATORS(PredicateIsFunctional);
};

};   // end namespace

#endif // __TARGETING_COMMON_PREDICATEISFUNCTIONAL_H
