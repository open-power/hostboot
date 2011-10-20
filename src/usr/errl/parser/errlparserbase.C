//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/parser/errlparserbase.C $
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
 *  @file errlparsebase.C
 *
 *  @brief <Brief Description of this file>
 *
 *  <Detailed description of what this file does, functions it includes,
 *  etc,>
*/


/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/parser/errlparserbase.H>


///< Maximum displayable characters
static const int    LINE_WIDTH = 78;



/*****************************************************************************/
// Constructor
/*****************************************************************************/
ErrlParser::ErrlParser(
    FILE *		i_output
)
{

}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
ErrlParser::~ErrlParser()
{

}


/*****************************************************************************/
// Numeric Print
/*****************************************************************************/
void ErrlParser::PrintNumber(
    const char * i_label,
    const char * i_fmt,
    uint32_t	 i_value
)
{
    char l_tmp[LINE_WIDTH];

    snprintf(l_tmp,LINE_WIDTH,i_fmt,i_value);
    l_tmp[LINE_WIDTH-1] = 0;

    PrintString( i_label, l_tmp );
}


