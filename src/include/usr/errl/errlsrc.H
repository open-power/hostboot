/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/errl/errlsrc.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
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
#ifndef ERRLSRC_H
#define ERRLSRC_H

/**
 *  @file errlsrc.H
 *
 *  @brief Manage the data that make up the 'PS' section in an
 *  error log PEL.  PS stands for Primary System Reference Code, or SRC.
 *  Part of that data management is the flattening of data into PEL.
 *
*/

#include <errl/errlsctn.H>
#include <errl/errlsctnhdr.H>


namespace ERRORLOG
{

class ErrlSrc : public ErrlSctn
{

    // ErrlEntry may access private elements of this class.  Data items that
    // you would expect to be part of ErrlEntry are actually instance data
    // in this class.
    friend class ErrlEntry;


private:


    enum constants
    {
        SLEN            = 72,  // section length w/o sizeof(ErrlSctnHdr)
        SST             = 1,   // section type
        VER             = 1,   // section version
        SRCVER          = 2,   // SRC version (not section version)
        WORDCOUNT       = 9    // SRC word count
        // CSS_VER      = 8    // TODO unused, relates to iv_cssver[]
    };


    /**
     * @brief Constructor.  Pass in items destined for the primary SRC
     * section in the error log.
     *
     * @param[in]  i_srcType      SRC type
     * @param[in]  i_modId        Module ID
     * @param[in]  i_reasonCode   Reason code
     * @param[in]  i_user1        User data 1
     * @param[in]  i_user2        User data 2
     *
     */
    ErrlSrc( srcType_t i_srcType,
             uint8_t   i_modId,
             uint16_t  i_reasonCode,
             uint64_t  i_user1,
             uint64_t  i_user2 );


    /** @brief Destructor.  */
    ~ErrlSrc();



    /**
      * @brief   Disable copy constructor and assignment operator.
      */
    ErrlSrc(const ErrlSrc& i_right);
    ErrlSrc& operator=(const ErrlSrc& i_right);



    /**
     *  @brief Data export facility to flatten data to PEL.
     *  Exports the object into the 'PS' primary SRC PEL section.
     *
     *  @param[out] o_pBuffer  Pointer to buffer where flattened data will go.
     *  @param[in]  i_cbBuffer  Count of bytes in target buffer
     *
     */
    uint64_t flatten( void * o_pBuffer, const uint64_t i_cbBuffer );

    /**
     *  @brief Data export size.  Presently, Hostboot returns
     *  creates an 80-byte PS section: 72 bytes in the SRC
     *  and 8 bytes for the PEL section header. This is the
     *  amount of flat storage (in bytes) required to
     *  store the object.
     *
     *  @return  Size in bytes.
     *
     */
    uint64_t flatSize() const;


    // Instance data
    srcType_t       iv_srcType : 8; // SRC type, the ?? in SRC ??xxxxxx
    uint8_t         iv_modId;       // module ID
    uint16_t        iv_reasonCode;  // reason code
    epubSubSystem_t iv_ssid : 8 ;   // subsystem type, the ?? in SRC xx??xxxx
    uint64_t        iv_user1;       // user data 1
    uint64_t        iv_user2;       // user data 2


};


//**************************************************************************
// Hostboot PS SRC section generates minimal section with no additional
// words of data.
inline uint64_t ErrlSrc::flatSize() const
{
    // 72 bytes in SRC structure + 8 byte section header.
    CPPASSERT( 80 == sizeof( pelSRCSection_t ));
    return sizeof( pelSRCSection_t );
}



} // namespace

#endif //ERRLSRC_H

