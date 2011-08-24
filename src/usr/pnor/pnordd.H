//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pnor/pnordd.H $
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
#ifndef __PNOR_PNORDD_H
#define __PNOR_PNORDD_H

/** @file pnordd.H
 *  @brief Provides the interfaces to the PNOR Device Driver
 */

namespace PNOR
{

//Not sure if this is the right place for these enums, open to suggestions.
/**
 * PNOR Modes
 */
enum lscMode
{
  MMRD = 0,  /**< Indicates PNOR is in MMRD Mode */
  PMWR,      /**< Indicates PNOR is in PMWR Mode */    

  LAST_MODE,
};


/**
 *  @brief  Type definition for PNOR address
 */
typedef uint64_t PNORAddress_t;


//@TODO: comment args
/**
 * @brief External interface for setting LSC mode
 */
errlHndl_t setLSCAccessMode(lscMode i_mode);



class PnorDD
{

  public:
    //@TODO: comment args
    /**
     * @brief Performs an PNOR Read Operation
     */
    errlHndl_t read(void* o_buffer,
                    size_t& io_buflen,
                    uint64_t i_address);

    //@TODO: comment args
    /**
     * @brief Performs an PNOR Write Operation
     */
    errlHndl_t write(void* i_buffer,
                     size_t& io_buflen,
                     uint64_t i_address);

    //@TODO: comment args
    /**
     * @brief Set LSC to desired access mode
     */
    errlHndl_t setAccessMode(lscMode i_mode);



  protected:
    /**
     * @brief Constructor
     */
    PnorDD();


    /**
     * @brief Destructor
     */
    ~PnorDD();

    //@TODO: comment args
    /**
     * Verify Request is in appropriate address range
     *
     */
    errlHndl_t verifyAddressRange(uint64_t i_address,
                                  size_t& i_length);


  private:

    /**
     * PNOR Mode Flag
     */
    lscMode iv_lscMode;

};

}; //end PNOR namespace

#endif
