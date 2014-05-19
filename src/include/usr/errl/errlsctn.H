/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlsctn.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

