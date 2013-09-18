/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlsctnhdr.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
#ifndef ERRLSCTNHDR_H
#define ERRLSCTNHDR_H
/**
 *  @file errlsctnhdr.H
 *
 *  @brief  This file contain the class that abstracts the header of
 *  an error log section.  Every section in PEL binary data starts with
 *  eight bytes of data. This class manages those 8 bytes for all manner
 *  of PEL sections, including PH (private header), UH (user header),
 *  UD (user defined), etc.
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <errl/hberrltypes.H>
#include <hbotcompid.H>
#include <string.h>

namespace ERRORLOG
{

/**
 *  @brief class ErrlSctnHdr abstracts a header of each PEL section in an
 *  error log object. Objects of classes ErrlSctn, ErrlUH, ErrlPrvt
 *  have one of these.
 */
class ErrlSctnHdr
{


    // All these classes have a ErrlSctnHdr
    friend class ErrlSctn;
    friend class ErrlPrvt;
    friend class ErrlUH;
    friend class ErrlUD;
    friend class ErrlSrc;
    friend class ErrlEntry;



private:

    /**
     * @brief Section header constructor
     *
     * Comp ID, section type and version uniquely identify exactly what
     * kind of a section it is. These fields can be used by a post-dump
     * parser to call the user-supplied parser code to interpret and
     * the data nicely.
     *
     * @param[in]   i_sid           Section ID destined for iv_sid
     * @param[in]   i_slen          Section length
     * @param[in]   i_ver           Section version
     * @param[in]   i_sst           Subsection type
     * @param[in]   i_compId        Component Id of the caller
     *
     * @return void
     */
    ErrlSctnHdr( const uint16_t     i_sid,
                 const uint16_t     i_slen,
                 const uint8_t      i_ver,
                 const uint8_t      i_sst,
                 const compId_t     i_compId );




    /**
     * @brief   Default destructor
     *
     * @return void
     */
    ~ErrlSctnHdr();



    /**
     * @brief   Disabled copy constructor and assignment operator
     */
    ErrlSctnHdr(const ErrlSctnHdr& i_right);
    ErrlSctnHdr& operator=(const ErrlSctnHdr& i_right);




    /**
     * @brief Compute the flattened size of this.
     *
     * @return Size in bytes of the flattened data, which is 8
     * for an ErrlSctnHdr.
     */
    uint64_t flatSize() const;



    /**
     * @brief Flatten to buffer provided.
     *
     * @param[in,out]  o_buffer    Points to data block to be filled
     * @param[in]      i_cbBuffer  Count of bytes in buffer supplied
     *
     * @return  Count of bytes copied to caller's
     *          buffer or else zero if it does not fit.
     */
    uint64_t flatten( void * o_pbuffer, const uint64_t i_cbBuffer );

    /**
     * @brief Import flattened data 
     * @param[in] i_buf, pointer to flattened data
     * @return number of bytes consumed in the flattened data
     */
    uint64_t unflatten( const void * i_buf );


    // Instance data.
    uint16_t  iv_sid;         // section id  'PH' 'UH' etc (errlSectionId_t)
    uint16_t  iv_slen;        // section length
    uint8_t   iv_ver;         // section version
    uint8_t   iv_sst;         // subsection type
    compId_t  iv_compId;      // hostboot component id


};



//***************************************************************************

inline uint64_t ErrlSctnHdr::flatSize() const
{
    // 2 for section id (errlSectionId)
    // 2 for section len
    // 1 for ver
    // 1 for subsection type
    // 2 for component id
    CPPASSERT( 8 == sizeof( pelSectionHeader_t ));
    return sizeof( pelSectionHeader_t );
}

} // End namespace

#endif //ERRLSCTNHDR_H

