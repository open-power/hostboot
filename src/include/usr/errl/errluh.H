/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errluh.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
#ifndef ERRLUH_H
#define ERRLUH_H

/**
 *  @file errluh.H
 *
 *  @brief A class for the user header 'UH' section of an error log.
 *  This classes manages those ErrlEntry data items that are destined
 *  to be saved in the user header PEL section.
*/

#include <errl/errlentry.H>
#include <errl/errlsctnhdr.H>


namespace ERRORLOG
{


class ErrlUH
{

    // ErrlEntry may access private elements of this class.  Data items that
    // you would expect to be part of ErrlEntry are actually instance data
    // in this class.
    friend class ErrlEntry;



private:

    enum constants
    {
        // for generating UH section of PEL
	SLEN    = 16,  // 16 does not include the 8 bytes of ErrlSctnHdr
	VER     = 1,   // section version
	SST     = 0    // section type
    };

    /** @brief User header constructor.  */
    ErrlUH( errlSeverity_t i_sev );

    /** @brief User header destructor.  */
    ~ErrlUH();


    /**
      * @brief   Disable copy constructor and assignment operator.
      */
    ErrlUH(const ErrlUH& i_right);
    ErrlUH& operator=(const ErrlUH& i_right);


    /**
     *  @brief Data export size. Amount of flat storage (in bytes) required to
     *  store the object.
     *
     *  @return size in bytes
     */
    uint64_t flatSize() const;


    /**
     *  @brief Data Export facility. Flatten the object into PEL for the
     *  'UH' user header section.
     *
     *  @param[in,out] io_pBuffer Pointer to buffer where flat data will go.
     *  @param[in]     i_cbBuffer Count of bytes in target buffer
     *
     */
    uint64_t flatten(  void * io_pBuffer, const uint64_t i_cbBuffer );

    /**
     * @brief Import data
     * @param[in] i_buf, the pointer to the flattened data
     * @return number of bytes consumed
     */
    uint64_t unflatten( const void * i_buf );

    /**
     *  @brief return the failing subsystem id value
     *
     *  @return  Failing subsystem ID
     *
     */
    epubSubSystem_t getSubSys()const { return iv_ssid; };

    /**
     *  @brief set the failing subsystem id value in the SRC object
     *
     *
     */
    void setSubSys( epubSubSystem_t i_ssid ){ iv_ssid = i_ssid; };


    /**  @brief Set the component ID into the user header.
     *   Only should be called from ErrlEntry instance.
     *   The component ID in the user header identifies
     *   the component that committed the error log.
     *
     *   @param[in]  i_compId   component ID
     */
    void setComponentId( compId_t i_compId );

    // Instance variables
    // SctnHdr for 'UH' section
    ErrlSctnHdr        iv_header;


    errlSeverity_t     iv_severity;
    errlEventType_t    iv_etype;
    uint16_t           iv_actions;

    // failing sub system ID
    epubSubSystem_t    iv_ssid;

    // these are defaulted at object creation
    // no setters/getters are provided currently
    errlDomain_t       iv_domain;
    errlVector_t       iv_vector;
    errlScope_t        iv_scope;

    /**  @brief Set the event type to TRACING or severity to INFORMATIONAL.
     *          Taken from errluh.H in FSP code
     *
     *   @param[in]  i_etype  event type
     */
    void setInformationalEvent( errlEventType_t i_etype );

};


/*****************************************************************************/
// Destructor

inline ErrlUH::~ErrlUH()
{
}


/*****************************************************************************/
// Export data size

inline uint64_t ErrlUH::flatSize() const
{
    return ( iv_header.flatSize() + SLEN );
}




/*****************************************************************************/
// For user headers, the comp ID represents the committing component.

inline void ErrlUH::setComponentId( compId_t i_compId )
{
  iv_header.iv_compId = i_compId;
}




} // namespace


#endif //ERRLUH_H
