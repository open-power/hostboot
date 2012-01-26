//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errlsctn.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef ERRLSCTN_H
#define ERRLSCTN_H
/**
 *  @file errlsctn.H
 *
 *  @brief  Base class for adding sections of data to an error log.
 *          A section may be used to store unique data for the
 *          error such as SRC or user-defined data or
 *          component traces, etc.
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <errl/hberrltypes.H>
#include <hbotcompid.H>
#include <errl/errlsctnhdr.H>



namespace ERRORLOG
{

/**
 *  @brief Base class of a section in an error log object. Derivations
 *  may include ErrlCallHome, ErrlExtUH, ErrlSrc, ErrlUD, etc.
 */
class ErrlSctn
{



protected:

    /**
     * @brief   Constructor
     *          Initializes the base object with section information
     *
     * @param[in]   i_sid        Section id
     * @param[in]   i_slen       Section length
     * @param[in]   i_ver        Section version
     * @param[in]   i_sst        Subsection type
     * @param[in]   i_compId     Component id
     *
     * @return void
     */
    ErrlSctn(  const uint16_t    i_sid,
               const uint16_t    i_slen,
               const uint8_t     i_ver,
               const uint8_t     i_sst,
               const compId_t    i_compId );


    /**
     * @brief   Default destructor
     *
     * @return void
     */
    virtual ~ErrlSctn();



    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlSctn(const ErrlSctn& i_right);
    ErrlSctn& operator=(const ErrlSctn& i_right);



    // PEL section header for flattening.
    ErrlSctnHdr   iv_header;

};



} // End namespace


#endif //ERRLSCTN_H

