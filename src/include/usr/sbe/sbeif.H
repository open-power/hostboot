/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbe/sbeif.H $                                 */
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
#ifndef _SBEIF_H
#define _SBEIF_H

#include <errl/errlentry.H>
#include <pnor/pnorif.H>

namespace SBE
{
    // Each SBE Image stored in PNOR has a 64-byte version associated with it
    // (like a SHA hash of the image)
    const size_t   SBE_IMAGE_VERSION_SIZE = 64; // 64 bytes

    typedef uint8_t sbe_image_version_t[SBE_IMAGE_VERSION_SIZE];


    /**
     * @brief Gets a pointer to the proper SBE image in PNOR
     *
     * @param[in] i_target     Target used to find right SBE Image in PNOR
     *
     * @param[out] o_imgPtr    Pointer to SBE Image mapped in PNOR
     *                         Note: Pointer moved past any header(s)
     *
     * @param[out] o_imgSize   Size of the SBE Image in PNOR
     *                         Note: Size does not include any header(s)
     *
     * @param[out] o_version   Pointer to SBE Image Version Struct
     *                         If Pointer is NULL, version not returned;
     *                         Else sbe_image_version_t is filled in
     *
     * @return errlHndl_t      Error log handle on failure.
     */
    errlHndl_t findSBEInPnor(TARGETING::Target* i_target,
                             void*& o_imgPt,
                             size_t& o_imgSize,
                             sbe_image_version_t* o_version = NULL);


    /**
     * @brief Iterates through all the functional processors and updates
     *        the SBE Image in a SEEPROM, if necessary.
     *
     * @return errlHndl_t    Error log handle on failure.
     */
    errlHndl_t updateProcessorSbeSeeproms();


} //end namespace SBE

#endif /* _SBEIF_H */
