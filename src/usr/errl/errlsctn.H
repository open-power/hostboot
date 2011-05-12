#ifndef ERRLSCTN_H
#define ERRLSCTN_H
/**
 *  @file errlsctn.H
 *
 *  @brief  Base class that abstracts a section in an error log.
 *          A section may be used to store unique data for the
 *          error such as FFDC, Software error information, etc...
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <errl/errltypes.H>
#include "errlsctnhdr.H"

namespace ERRORLOG
{

/**
 *  @brief Base class that abstracts a section in an error log object.
 */
class ErrlSctn
{

public:

    /**
     * @brief   Constructor
     *          Initializes the base object with section information
     *
     * @param[in]   i_compId     Component Id of the caller
     * @param[in]   i_sctnVer    A user supplied identifier which
     *                           classifies the data in the section
     * @param[in]   i_subSect    A user supplied sub section identifier
     *                           which classifies the data.  This in
     *                           conjunction with the version can be used
     *                           to decode the data.
     * @return void
     *
     */
    ErrlSctn(const compId_t i_compId,
             const uint8_t i_sctnVer,
             const uint8_t i_subSect);

    /**
     * @brief   Default destructor
     *
     * @return void
     */
    virtual ~ErrlSctn();

    //@todo - Need to add serialization interfaces for ErrlSctn object.
    //        Serialization method (boost serialization?) for HostBoot
    //        is currently not yet determined.
    //        Note: stream is currently not supported

    /**
     *  @brief Get section's version
     *
     *  @return Section version (uint8_t)
     *
     */
    uint8_t sctnVer() const;

    /**
     *  @brief Get section's subsection type
     *
     *  @return Subsection type (uint8_t)
     *
     */
    uint8_t subSect() const;

    /**
     *  @brief Get section's component Id
     *
     *  @return Component Id of the section creator
     *
     */
    compId_t compId() const;

private:

    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlSctn(const ErrlSctn& i_right);
    ErrlSctn& operator=(const ErrlSctn& i_right);

    // Section header
    ErrlSctnHdr iv_header;

};

//-----------------------------------------------------------------------
// In-line functions
//-----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint8_t ErrlSctn::sctnVer() const
{
    return iv_header.iv_sctnVer;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint8_t ErrlSctn::subSect() const
{
    return iv_header.iv_subSect;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline compId_t ErrlSctn::compId() const
{
    return iv_header.iv_compId;
}


} // End namespace

#endif //ERRLSCTN_H

