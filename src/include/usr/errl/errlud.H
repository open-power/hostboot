/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlud.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] Google Inc.                                                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef ERRLUD_H
#define ERRLUD_H
/**
 *  @file errlud.H
 *
 *  @brief Derive the ErrlUD (user defined) error log section from the
 *  more general ErrlSctn class.
*/


#include <errl/errlsctn.H>
#include <errl/errlsctnhdr.H>

namespace ERRORLOGDISPLAY
{
class ErrLogDisplay;
}

namespace ERRORLOG
{



class ErrlUD : public ErrlSctn
{


    // ErrlEntry may access private elements of this class.  Data items that
    // you would expect to be part of ErrlEntry are actually instance data
    // in this class.
    friend class ErrlEntry;
    friend class ErrlManager;
    friend class ERRORLOGDISPLAY::ErrLogDisplay;
    friend class ErrlTest;


private:


    /**
     *  @brief Constructor
     *
     *  Create a user data section with the given input data.
     *
     *  @param  i_data     Pointer to data
     *  @param  i_size     Length of data
     *  @param  i_cid      Component ID of the section
     *  @param  i_ver      Section version
     *  @param  i_sst      Section type
     *
     */
    ErrlUD(
        const void *i_data,
        uint64_t    i_size,
        compId_t    i_cid,
        uint8_t     i_ver,
        uint8_t     i_sst );



    /**
     *  @brief Destructor
     *
     *  Releases allocated resources
     *
     */
    virtual ~ErrlUD();


    /**
      * @brief   Disable copy constructor and assignment operator.
      */
    ErrlUD(const ErrlUD& i_right);
    ErrlUD& operator=(const ErrlUD& i_right);


    /**
     *  @brief Data export size. Amount of flat storage (in bytes) required to
     *  store the object.
     *
     *  @return size in bytes
     */
    uint64_t flatSize();


    /**
     *  @brief Data Export facility.
     *  Exports the object into the architecturally
     *  defined format for a user data section.
     *
     *  @param[in,out] io_pBuffer Pointer to buffer where flat data will go.
     *  @param[in]     i_cbBuffer Count of bytes in target buffer
     *
     */
    uint64_t flatten( void * io_pBuffer, const uint64_t i_cbBuffer );



    /**
     * @brief Import data
     * Imports data created with flatten.
     * @param[in] i_buf, pointer to the flattened data
     * @return number of bytes consumed
     */
    uint64_t unflatten( const void * i_buf );


    /**
     *  @brief Appends data to the section.
     *  Grows the section by the given amount
     *
     *  @param[in]  i_data  Source data
     *  @param[in]  i_size  Additional size
     *
     *  @return   Size of new data or else zero on error.
     *
     */
    uint64_t addData( const void *i_data,  uint64_t i_size );




    /**
     *  @brief Data size of the section
     *
     *  The distinction is made between data size
     *  and object flat size.  This method returns
     *  the size of the data only
     *
     *  @return Length
     *
     */
    uint64_t dataSize( void ) const;



    /**
     *  @brief Data access
     *
     *  Direct Access to the data of the object
     *  ( dangerous - use with caution )
     *
     *  @return Data pointer
     *
     */
    void * data( void ) const;




    uint8_t *   iv_pData;    // Data Pointer
    uint64_t    iv_Size;     // Data Length

};



/*****************************************************************************/
// Get data size
/*****************************************************************************/
inline uint64_t ErrlUD::dataSize( void ) const
{
    return iv_Size;
}


/*****************************************************************************/
// Data access pointer
/*****************************************************************************/
inline void * ErrlUD::data( void ) const
{
    return iv_pData;
}

} // namespace
#endif /* ERRLUD_H */
