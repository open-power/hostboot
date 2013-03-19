/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMembufDataBundle.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

#ifndef __prdfCenMembufDataBundle_H
#define __prdfCenMembufDataBundle_H

/** @file  prdfCenMembufDataBundle.H
 *  @brief Contains the common data bundle for a PRD Centaur object.
 */

#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

/**
 * @brief Data container for the Centaur Membuf chip.
 */
class CenMembufDataBundle : public DataBundle
{
  public:

    /** @brief Constructor */
    CenMembufDataBundle( ExtensibleChip * i_mbChip ) :
        iv_mbChip(i_mbChip), iv_mcsChip(NULL), iv_analyzeMba1Starvation(false)
    {}

    /** @brief Destructor */
    ~CenMembufDataBundle() {}

    /** @return The connected MCS chip. */
    ExtensibleChip * getMcsChip()
    {
        if ( NULL == iv_mcsChip )
        {
            TargetHandleList list = getConnected( iv_mbChip->GetChipHandle(),
                                                  TYPE_MCS );
            if ( 1 == list.size() )
                iv_mcsChip = (ExtensibleChip *)systemPtr->GetChip( list[0] );
            else
            {
                PRDF_ERR( "[CenMembufDataBundle::getMcsChip] "
                          "getConnected() failed" );
            }
        }

        return iv_mcsChip;
    }

  private: // functions

    CenMembufDataBundle( const CenMembufDataBundle & );
    const CenMembufDataBundle & operator=( const CenMembufDataBundle & );

  private: // instance variables

    ExtensibleChip * iv_mbChip;  ///< The Centaur chip
    ExtensibleChip * iv_mcsChip; ///< The connected MCS chip

  public: // instance variables

    // Toggles to solve MBA1 starvation issue
    bool iv_analyzeMba1Starvation;
};

/**
 * @brief  Wrapper function for the CenMembufDataBundle.
 * @param  i_membChip The centaur chip.
 * @return This centaur's data bundle.
 */
CenMembufDataBundle * getCenMembufDataBundle( ExtensibleChip * i_membChip )
{
    return static_cast<CenMembufDataBundle *>(i_membChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfCenMembufDataBundle_H

