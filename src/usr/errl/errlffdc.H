#ifndef ERRLFFDC_H
#define ERRLFFDC_H
/**
 *  @file errlffdc.H
 *
 *  @brief FFDC data section within ErrlEntry object
 *
 *  This header file contains the definition of FFDC data class that
 *  is attached within the ErrlEntry object.
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include "errlsctn.H"


namespace ERRORLOG
{

/**
 *  @brief  Abstract an FFDC data section in an error log
 *  This class contains FFDC data that users add to an error log.
 */
class ErrlFFDC: public ErrlSctn
{

public:

    /**
     * @brief Constructor
     * Create a user data FFDC section with the given
     * input data.
     *
     * @param[in]   i_compId        Creator (component id)
     * @param[in]   i_ffdcPtr       Data pointer
     * @param[in]   i_ffdcLen       Data length (bytes)
     * @param[in]   i_ffdcVer       Data identifier
     * @param[in]   i_ffdcSubSect   Sub section identifier
     *
     * @return void
     */
    ErrlFFDC(const compId_t i_compId,
             const void* i_ffdcPtr,
             const uint32_t i_ffdcLen,
             const uint8_t i_ffdcVer,
             const uint8_t i_ffdcSubSect);


    /**
     *  @brief Cleanup ( destructor )
     *
     *  Releases allocated resources
     *
     */
    ~ErrlFFDC();

    /**
     *  @brief Appends data to the section
     *  Grows the section by the given amount
     *
     *  @param[in]  i_data      Pointer to data source
     *  @param[in]  i_size      Data size (bytes)
     *
     *  @return None
     */
    void addData(const void *i_data,
                 const uint32_t i_size);

private:
    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlFFDC(const ErrlFFDC& i_right);
    ErrlFFDC& operator=(const ErrlFFDC& i_right);

    uint8_t*    iv_data;    // Data Pointer
    uint32_t    iv_size;    // Data Length
};


} // End namespace

#endif //ERRLFFDC_H
