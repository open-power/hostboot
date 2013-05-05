/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8McsDataBundle.H $ */
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

#ifndef __prdfP8McsDataBundle_H
#define __prdfP8McsDataBundle_H

/** @file  prdfP8McsDataBundle.H
 *  @brief Contains the data bundle for a P8 MCS object.
 */

#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>

namespace PRDF
{

/**
 * @brief The P8 Centaur MBA data bundle.
 */
class P8McsDataBundle : public DataBundle
{
  public: // functions

    /**
     * @brief Constructor.
     * @param i_mcsChip The MCS chip.
     */
    explicit P8McsDataBundle( ExtensibleChip * i_mcsChip ) :
        iv_mcsChip(i_mcsChip), iv_membChip(NULL)
    {}

    /**
     * @brief Destructor.
     */
    ~P8McsDataBundle() {}

    /** @return The connected MEMBUF chip. */
    ExtensibleChip * getMembChip()
    {
        using namespace TARGETING;
        using namespace PlatServices;

        if ( NULL == iv_membChip )
        {
            TargetHandle_t mcs = iv_mcsChip->GetChipHandle();

            TargetHandle_t memb = getConnectedChild( mcs, TYPE_MEMBUF, 0 );
            if ( NULL != memb )
                iv_membChip = (ExtensibleChip *)systemPtr->GetChip( memb );
        }

        return iv_membChip;
    }

  private: // functions

    P8McsDataBundle( const P8McsDataBundle & );
    const P8McsDataBundle & operator=( const P8McsDataBundle & );

  private: // instance variables

    ExtensibleChip * iv_mcsChip;  ///< This MCS chip
    ExtensibleChip * iv_membChip; ///< The connected MEMBUF chip
};

//------------------------------------------------------------------------------

/**
 * @brief  Wrapper function for the P8McsDataBundle.
 * @param  i_mcsChip The MCS chip.
 * @return This MBA's data bundle.
 */
inline P8McsDataBundle * getMcsDataBundle( ExtensibleChip * i_mcsChip )
{
    return static_cast<P8McsDataBundle *>(i_mcsChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfP8McsDataBundle_H

