/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errluh.H $                               */
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

    // failing sub system ID
    epubSubSystem_t    iv_ssid;

    // these are defaulted at object creation
    // no setters/getters are provided currently
    errlDomain_t       iv_domain;
    errlVector_t       iv_vector;
    uint16_t           iv_actions;
    errlScope_t        iv_scope;

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
