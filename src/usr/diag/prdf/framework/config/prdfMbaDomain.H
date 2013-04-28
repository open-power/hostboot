/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/config/prdfMbaDomain.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

#ifndef __prdfMbaDomain_H
#define __prdfMbaDomain_H

#include <prdfMbaDomain_common.H>

namespace PRDF
{

class MbaDomain : public MbaDomainCommon
{
  public:

    MbaDomain( DOMAIN_ID i_did, uint32_t i_size = MBA_DOMAIN_SIZE ) :
        MbaDomainCommon( i_did, i_size )
    {}

    /**
     * @brief Starts memory background scrubbing for each MBA in the node.
     * @param Non-SUCCESS if an internal function failed, SUCCESS otherwise.
     */
    int32_t startScrub();

};

} // end namespace PRDF

#endif /* __prdfMbaDomain_H */

