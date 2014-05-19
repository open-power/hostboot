/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfParentDomain.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2014              */
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

#ifndef prdfParentDomain_H
#define prdfParentDomain_H

#include <prdfRuleChip.H>
#include <vector>

namespace PRDF
{
/**
 Template class that Define a domain Parent that contain other domains as children.
 @par
 @note Parent class: Domain
 @par Usage Examples:
 @code
 @endcode
*/
template <typename T>
class ParentDomain
{
public:

   //The information stored for chaining Domains is two things.  a Chip of origin.
   //  Also, a pointer the the child domain.  The child domain is the next domain in
   //  a potential chain or string of domains.  The chip is the original chip that started it.

  typedef std::pair< TARGETING::TargetHandle_t, T * > ChipToDomainPointerPairType;
  typedef std::vector< ChipToDomainPointerPairType > VectorOfDomainPointerType;
  // Need to add typename here to tell the compiler that vector< ... >::iterator is a type.
  //  Otherwise because of the T template parm it doesn't know it's a type yet.
  typedef typename std::vector< ChipToDomainPointerPairType >::iterator iterator;

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
  ParentDomain();

  /**
   Add Children to this chip in this domain.
   <ul>
   <br><b>Parameter:   </b> domainId: Identifies the Domain (See iipconst.h)
   <br><b>Parameter:   </b> chip:     Parent to add children to.
   <br><b>Parameter:   </b> chipList: List of children to add to this Parent.
   <br><b>Returns:     </b> SUCCESS or FAILURE.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  int32_t AddChild(TARGETING::TargetHandle_t i_pchipHandle, T * i_childDomain);

  /**
   Returns a begin iterator to a list of children domains.
   <ul>
   <br><b>Parameter:   </b> None.
   <br><b>Returns:     </b> begin iterator.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  iterator getBeginIterator();

  /**
   Returns a end iterator to a list of children domains.
   <ul>
   <br><b>Parameter:   </b> None.
   <br><b>Returns:     </b> end iterator.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  iterator getEndIterator();

  /**
   Prints out the ids of the parent chip and children domains.
   <ul>
   <br><b>Parameter:   </b> None
   <br><b>Returns:     </b> begin iterator.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  void printChildrenIds();

protected:

private:

   VectorOfDomainPointerType iv_childrenDomains;

};

} // end namespace PRDF

#endif
