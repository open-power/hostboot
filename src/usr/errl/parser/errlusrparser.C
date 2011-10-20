//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/parser/errlusrparser.C $
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
/**
 *  @file errlusrparser.C
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <cstring>
#include <ctype.h>
#include <cstdarg>

#include <errl/parser/errlusrparser.H>

/*****************************************************************************/
//  Constant string defines
/*****************************************************************************/
const   char *  ERRL_MSG_UNKNOWN        =   "Unknown";
const   char *  ERRL_MSG_BOOL_TRUE      =   "True";
const   char *  ERRL_MSG_BOOL_FALSE     =   "False";
const   char *  ERRL_MSG_STR_ENABLED    =   "Enabled";
const   char *  ERRL_MSG_STR_DISABLED   =   "Disabled";


/*****************************************************************************/
// Send the label & return # of chars printed
/*****************************************************************************/
static int PrintLabel(
                     FILE *   i_stream,
                     const char * i_label
                     )
{
    if ( ! i_label )
    {
        i_label = "";
    }

    return fprintf(i_stream,"| %-25.25s: ",i_label);
}


/*****************************************************************************/
// Regular string ( may be multiline )
/*****************************************************************************/
void ErrlUsrParser::PrintString(
                               const char * i_label,
                               const char * i_string
                               )
{
    // Must make sure the string fits on the available width
    int l_strlen = 0;
    int l_printed = 0;


    // Ensure String is valid
    if ( i_string )
    {
        l_strlen = strlen( i_string );
    }

    // Fake a blank string
    if ( ! l_strlen )
    {
        l_strlen = 1;
        i_string = " ";
    }

    // Print it out
    while ( l_strlen > l_printed )
    {
        // Leader ( label or blanks )
        PrintLabel( iv_Stream, i_label );

        // label is only printed once
        i_label = "";

        l_printed += fprintf(
                            iv_Stream,
                            "%-50.50s",
                            i_string+l_printed
                            );

        fprintf(iv_Stream,"|\n");
    }
}
/*****************************************************************************/
// Numeric Print
/*****************************************************************************/
void ErrlUsrParser::PrintNumber(
                               const char * i_label,
                               const char * i_fmt,
                               uint32_t     i_value
                               ){
    ErrlParser::PrintNumber( i_label, i_fmt, i_value );
}


/*****************************************************************************/
// Hex Dump
/*****************************************************************************/
void ErrlUsrParser::PrintHexDump(
                                const void * i_data,
                                uint32_t     i_len
                                )
{
    uint32_t i = 0 ;
    uint32_t l_counter = 0;
    uint32_t l_written;
    uint8_t *l_data = (uint8_t*)i_data;

    while ( l_counter < i_len)
    {
        fprintf(iv_Stream,"|   %08X     ",l_counter);

        // Display 16 bytes in Hex with 2 spaces in between
        l_written = 0;
        for ( i = 0; i < 16 && l_counter < i_len; i++ )
        {
            l_written += fprintf(iv_Stream,"%02X",l_data[l_counter++]);

            if ( ! ( l_counter % 4 ) )
            {
                l_written += fprintf(iv_Stream,"  ");
            }
        }

        // Pad with spaces
        fprintf(iv_Stream,"%-*c",43-l_written,' ');

        // Display ASCII -- fk1
        l_written = 0;
        uint8_t l_char;
        for ( ; i > 0 ; i-- )
        {
            l_char = l_data[ l_counter-i ];

            if ( isprint( l_char ) &&
                 ( l_char != '&' ) &&
                 ( l_char != '<' ) &&
                 ( l_char != '>' )
               )
            {
                l_written += fprintf( iv_Stream,"%c",l_char );
            }
            else
            {
                l_written += fprintf( iv_Stream,"." );
            }
        }

        // Pad with spaces -- fk1
        fprintf( iv_Stream,"%-*c|\n",19-l_written,' ' );



    }
}


