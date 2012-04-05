/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/spd/spdif.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file spdif.H
 *
 * @brief External SPD interfaces
 *
 */
#ifndef __SPDIF_H
#define __SPDIF_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <pnor/pnorif.H>

namespace SPD
{

/**
 * @brief This structure is used to transfer common information needed
 *      for reading the address from the PNOR RP.
 */
struct pnorInformation
{
    uint64_t sectionSize;
    uint64_t maxSections;
    PNOR::SectionId pnorSection;
    PNOR::SideSelect pnorSide;
};

/**
 * @brief This Function is used to query the PNOR RP and get the address of
 *      the data section.  It is also used to then read from that address the
 *      number of bytes requested.
 *      NOTE: This function is defined here because it is used by both the SPD
 *      and MVPD code.
 *
 * @param[in] i_byteAddr - The offset into the section of the data to be read.
 *
 * @param[in] i_numBytes - The number of bytes to read.
 *
 * @param[out] o_data - The data buffer.
 *
 * @param[in] i_target - The target to read the data for.
 *
 * @param[in] i_pnorInfo - Data required to query for the PNOR data address.
 *
 * @param[in/out] io_cachedAddr - This is the address that is, or will be read
 *      from the PNOR RP and saved for future use.
 *
 * @param[in] i_mutex - Mutex from calling code to be used for setting
 *      io_isAddrCached and io_cachedAddr.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
*/
errlHndl_t readPNOR ( uint64_t i_byteAddr,
                      size_t i_numBytes,
                      void * o_data,
                      TARGETING::Target * i_target,
                      pnorInformation & i_pnorInfo,
                      uint64_t &io_cachedAddr,
                      mutex_t * i_mutex );

};  // end SPD

#endif
