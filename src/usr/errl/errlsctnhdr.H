#ifndef ERRLSCTNHDR_H
#define ERRLSCTNHDR_H
/**
 *  @file errlsctnhdr.H
 *
 *  @brief  This file contain the class that abstracts the header of
 *  an error log section.
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <errl/errltypes.H>
#include <hbotcompid.H>
#include <string.h>

namespace ERRORLOG
{

/**
 *  @brief This class abstracts a header of a section in an error log object
 */
class ErrlSctnHdr
{
    // ErrlSctn accesses ErrlSctnHdr directly.
    friend class ErrlSctn;

    /**
     * @brief Section header constructor
     *
     * @param[in]   i_compId        Component Id of the caller
     * @param[in]   i_sctnVer       A user supplied identifier which
     *                              classifies the data in the section
     * @param[in]   i_subSect       A user supplied sub section identifier
     *                              which classifies the data.  This in
     *                              conjunction with the version can be used
     *                              to decode the data.
     * @return void
     */
    ErrlSctnHdr(const compId_t i_compId,
                const uint8_t i_sctnVer,
                const uint8_t i_subSect);

    /**
     * @brief   Default destructor
     *
     * @return void
     */
    ~ErrlSctnHdr();

    //@todo - Need to add serialization interfaces for ErrlSctnHdr object.
    //        Serialization method (boost serialization?) for HostBoot
    //        is currently not yet determined.
    //        Note: stream is currently not supported



private:

    /**
     * @brief   Disabled copy constructor and assignment operator
     */
    ErrlSctnHdr(const ErrlSctnHdr& i_right);
    ErrlSctnHdr& operator=(const ErrlSctnHdr& i_right);

    // Data
    // Can/will be accessed by friend class ErrlSctn
    compId_t iv_compId;
    uint8_t iv_sctnVer;
    uint8_t iv_subSect;

};

} // End namespace

#endif //ERRLSCTNHDR_H

