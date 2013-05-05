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

#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/**
 * @brief Data container for the Centaur Membuf chip.
 */
class CenMembufDataBundle : public DataBundle
{
  public:

    /** @brief Constructor */
    CenMembufDataBundle( ExtensibleChip * i_membChip ) :
        iv_membChip(i_membChip), iv_mcsChip(NULL),
        iv_analyzeMba1Starvation(false)
    {
        for ( uint32_t i = 0; i < MAX_MBA_PER_MEMBUF; i++ )
            iv_mbaChips[i] = NULL;
    }

    /** @brief Destructor */
    ~CenMembufDataBundle() {}

    /** @return The connected MCS chip. */
    ExtensibleChip * getMcsChip()
    {
        using namespace TARGETING;
        using namespace PlatServices;

        if ( NULL == iv_mcsChip )
        {
            TargetHandle_t memb = iv_membChip->GetChipHandle();

            TargetHandle_t mcs = getConnectedParent( memb, TYPE_MCS );
            if ( NULL != mcs )
                iv_mcsChip = (ExtensibleChip *)systemPtr->GetChip( mcs );
        }

        return iv_mcsChip;
    }

    /** @return The connected MBA0 chip. */
    ExtensibleChip * getMbaChip( uint32_t i_pos )
    {
        using namespace TARGETING;
        using namespace PlatServices;

        ExtensibleChip * mbaChip = NULL;

        if ( MAX_MBA_PER_MEMBUF > i_pos )
        {
            if ( NULL == iv_mbaChips[i_pos] )
            {
                TargetHandle_t memb = iv_membChip->GetChipHandle();

                TargetHandle_t mba = getConnectedChild( memb, TYPE_MBA, i_pos );
                if ( NULL != mba )
                {
                    iv_mbaChips[i_pos]
                                = (ExtensibleChip *)systemPtr->GetChip(mba);
                }
            }

            mbaChip = iv_mbaChips[i_pos];
        }
        else
        {
            PRDF_ERR( "[CenMembufDataBundle::getMbaChip] Invalid parameter: "
                      "i_pos=%d", i_pos );
        }

        return mbaChip;
    }

  private: // functions

    CenMembufDataBundle( const CenMembufDataBundle & );
    const CenMembufDataBundle & operator=( const CenMembufDataBundle & );

  private: // instance variables

    ExtensibleChip * iv_membChip; ///< This MEMBUF chip
    ExtensibleChip * iv_mcsChip;  ///< The connected MCS chip
    ExtensibleChip * iv_mbaChips[MAX_MBA_PER_MEMBUF]; ///< Connected MBA chips

  public: // instance variables

    // Toggles to solve MBA1 starvation issue
    bool iv_analyzeMba1Starvation;
};

/**
 * @brief  Wrapper function for the CenMembufDataBundle.
 * @param  i_membChip The centaur chip.
 * @return This centaur's data bundle.
 */
inline CenMembufDataBundle * getMembufDataBundle( ExtensibleChip * i_membChip )
{
    return static_cast<CenMembufDataBundle *>(i_membChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfCenMembufDataBundle_H

