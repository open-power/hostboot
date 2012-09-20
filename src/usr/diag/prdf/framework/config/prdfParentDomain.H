/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/config/prdfParentDomain.H $       */
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

#ifndef prdfParentDomain_H
#define prdfParentDomain_H

#include <prdfRuleChip.H>
#include <vector>

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

#endif
