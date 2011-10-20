//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/parser/errlparserbase.H $
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
#ifndef ERRL_ERRLPARSERBASE_H
#define ERRL_ERRLPARSERBASE_H

/**
 *  @file errlparserbase.H
 *
 *  @brief Base class for parser routines
 *
 *  pulled from fips740/ .. /src/errl/fsp/errlparser.H
 *
 * @note
 *  There are many more routines in fips code to print out specialty
 *  fields and such, these are not used presently and IMHO should be in
 *  their own file.
 *  Leave out for now.
 *
 */


/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>             // network byte-swapping routines.
// Unavoidable include for va_list
#include <cstdarg>

#include <errl/errltypes.H>

/*****************************************************************************/
//  Typedefs
/*****************************************************************************/
/**
 * @struct  BCD_time8_t
 *
 * pulled from fips740/ .. /src/rtim/fsp/rtim.H
 */
struct BCD_time8_t
{
  uint16_t year;
  uint8_t  month;
  uint8_t  day;
  uint8_t  hours;
  uint8_t  minutes;
  uint8_t  seconds;
  uint8_t  hundredths;
}  __attribute__ ((packed));



/*****************************************************************************/
// User Types
/*****************************************************************************/
class ErrlParser
{
public:


    /**
     *  @brief Build an associated parser object
     *
     *  Builds an associated parser object which is tied to the
     *  given stream.  The net effect is the addition of some
     *  simple methods to standardize log output
     *
     *  @param	i_output
     *	    Stream to be used for output, defaults to stdout
     *
     */
    ErrlParser(
            FILE *		    i_output = stdout
    );


    /**
     *  @brief Cleanup handler
     *
     *  Currently no-op
     *
     */
    virtual ~ErrlParser();


    /**
     *  @brief Set Stream pointer
     *
     *  Changes the output stream pointer which ultimately
     *  determines what OS device receives the data
     *
     *  @param	i_val
     *	    Output stream
     *
     *	@note	The stream handle is not owned by this object
     *	        and will therefore not be released automatically
     *
     */
    void setStream( FILE * i_val )
    {
        iv_Stream = i_val;
    }


    /**
     *  @brief Display a standard parser message
     *
     *  Displays the a message in the error log parser
     *  format of "Label: Desc"
     *
     *  @param	i_label
     *	    Label for the message
     *
     *  @param	i_string
     *	    Description string
     *
     */
    virtual void PrintString(
            const char * i_label,
            const char * i_string
    ) = 0;


    /**
     *  @brief Output a standard message for numeric data
     *
     *  A message consisting of the label and a hex formatted
     *  number is forwarded to the PrintString interface
     *
     *  @param	i_label
     *	    Left-hand label for the data
     *
     *  @param	i_fmt
     *	    Numeric format used to parse the data value
     *
     *  @param	i_value
     *	    Numberic value
     *
     *  @note Current implementation templates the output
     *        to PrintString after generating a string
     *        of the proper type.
     */
    virtual void PrintNumber(
            const char * i_label,
            const char * i_fmt,
            uint32_t     i_value
    );


    /**
     *  @brief Classical Hex dump of data
     *
     *  A 5 column output consisting of an offset, 4 hex words,
     *  and an ascii equivalent will be dumped in big endian
     *  mode
     *
     *  @param	i_data
     *	    Pointer to data buffer
     *
     *  @param	i_len
     *	    Length of data in bytes
     *
     */
    virtual void PrintHexDump(
            const void * i_data,
            uint32_t     i_len
    ) = 0;


protected:
    /**
     *  @brief Load a message string.
     *
     *  FSP allows this to reference a message file.  This is pulled out
     *  here, perhaps can be added later if needed.
     *
     *  @param  i_MsgId
     *      Message Identifier ( see errllang.H )
     *
     *  @return Constant pointer to the message string
     *
     *  @note The message is static and should not be modified by
     *        the caller.
     *
     */
    const char * LoadMsg( const char * i_MsgId )    const
    {
    return i_MsgId;
    }


    /**
     * @brief endian switch a uint64
     *
     * @param[in]   i_value
     *      uint64_t value to be byteswapped
     *
     *  @return byte-swapped uint64_t value
     *
     */
    uint64_t ntohll( uint64_t i )   const
    {
        uint64_t hi;
        uint64_t lo;
        uint32_t * pword = reinterpret_cast<uint32_t*>(&i);

        hi = ntohl( *pword );
        lo = ntohl( *(pword+1) );

        return (hi<<32)|lo;
    }


    // Data
    FILE *	iv_Stream;	    ///< Associated stream


};




#endif //ERRLPARSER_H
