//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/plugins/symbols.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>

#include "symbols.H"


/**
 *  @file symbols.C
 *
 *  @brief Read HB symbols file and provide a lookup mechanism.
 *
 */




//------------------------------------------------------------------------
// trim white space from end of s

static char * trim( char *s )
{
  char *p = s;

  /* bump to last char */
  while( *p ) p++;
  p--;

  /* trim */
  while( p >= s && ( *p == ' ' || *p == '\n' || *p == '\r' || *p == '\t' )) *p-- = 0;

  /* return what was passed in */
  return s;
}



//------------------------------------------------------------------------
// hbSymbolTable methods

// Read the syms file, return zero for success.
int hbSymbolTable::readSymbols( const char * i_filename )
{
    FILE * f = NULL;

    iv_vecSymbols.clear();
    iv_fPopulated = false;

    delete[] iv_pFileName;
    iv_pFileName = NULL;

    f = fopen( i_filename,  "r" );
    if( !f )
    {
      return 2;
    }
    fclose(f);

    int cb = 1 + strlen( i_filename );
    iv_pFileName = new char[cb];
    strcpy( iv_pFileName, i_filename );

    populateSymbolVector();

    return 0;
}




// private method
// read the syms file, return 0 if OK
int hbSymbolTable::populateSymbolVector()
{
    FILE * f = NULL;
    char szWork[ 1024 ];

    if( NULL == iv_pFileName )
    {
        return 2;
    }

    f = fopen( iv_pFileName,  "r" );
    if( !f )
    {
        return 2;
    }

    memset(szWork, 0, sizeof(szWork));

    while( fgets( szWork, sizeof( szWork )-1, f ))
    {
        // function symbols only
        if( 'F' == szWork[0] )
        {
            hbSymbol* l_pSymbol = new hbSymbol();

            int k = 0;
            char * pch;
            pch = strtok( szWork, "," );
            while( pch )
            {
                switch( k )
                {
                    case 0:
                        l_pSymbol->setType( *pch );
                        break;
                    case 1:
                        l_pSymbol->setAddress( pch );
                        break;
                    case 3:
                        l_pSymbol->setLength( pch );
                        break;
                    case 4:
                        l_pSymbol->setSymbolName( pch );
                        break;
                    default:
                        // skipping field 2 for now
                        break;
                }
                k++;
                pch = strtok( NULL, "," );
            }

            if( l_pSymbol->isValid() )
            {
                iv_vecSymbols.push_back( l_pSymbol );
            }
            else
            {
                delete l_pSymbol;
            }
        }
    }

    fclose(f);

    // The Hostboot symbols file is pretty much sorted already, but
    // ensure vector is sorted for the sake of binary searching.

    int c = iv_vecSymbols.size() - 1;
    bool fSorted = (iv_vecSymbols.size() <= 1);
    while( !fSorted )
    {
        fSorted = true;
        for ( int i = 0; i < c; i++ )
        {
            if( iv_vecSymbols[i]->iv_Address > iv_vecSymbols[i+1]->iv_Address )
            {
                fSorted = false;
                // swap them
                hbSymbol * l_tempSymbol;
                l_tempSymbol       = iv_vecSymbols[i];
                iv_vecSymbols[i]   = iv_vecSymbols[i+1];
                iv_vecSymbols[i+1] = l_tempSymbol;
            }
        }
    }

    iv_fPopulated = true;
    return 0;
}



// private method
// Given the address, find the vector index of the symbol.
// Return -1 if not found.
// Return 0 for exact match.
// Return 1 for nearest (previous) symbol
int hbSymbolTable::locateSymbol( uint64_t i_address, int &o_index )
{
    int rc = -1;
    int top, bot, mid, i;
    int count = iv_vecSymbols.size();

    if( 0 == count )
    {
      return -1;
    }

    if( 1 == count )
    {
      return 1;
    }


    top = count - 1;
    bot = 0;

    while( top >= bot )
    {
        mid = (top + bot) / 2;

        uint64_t l_midAddress = iv_vecSymbols[mid]->iv_Address;

        if( i_address >  l_midAddress )
        {
            /* input address >  symtable address */
            bot = mid + 1;
        }
        else if( i_address <  l_midAddress )
        {
            /* input address <  symtable address */
            top = mid - 1;
        }
        else
        {
            /* exact match */
            o_index = mid;
            return 0;
        }
    }


    /*  The binary search above rarely returns with mid pointing to
     *  the right symbol, so back up a couple of indices and bump along
     *  until we find the right symbol.
     */

    bot = mid - 2;
    if( bot < 0 )
    {
        bot = 0;
    }

    top = mid + 1;
    if( top > count )
    {
        top = count;
    }


    for( i = bot; i < top; i++ )
    {
        if(  ( i_address >= iv_vecSymbols[i]->iv_Address ) &&
             ( i_address <  ( iv_vecSymbols[i]->iv_Address + iv_vecSymbols[i]->iv_Length )))
        {
            // this is the one
            o_index = i;

            // nearest symbol found
            rc = 1;
            break;
        }
    }
    return rc;
}





// construtor
hbSymbolTable::hbSymbolTable()
{
    iv_pFileName = NULL;
    iv_fPopulated = 0;
}


hbSymbolTable::~hbSymbolTable()
{
    int c = iv_vecSymbols.size();
    for( int i = 0; i < c; i++ )
    {
        delete iv_vecSymbols[i];
    }
    delete[] iv_pFileName;
}


// public method
char * hbSymbolTable::nearestSymbol( uint64_t  i_address )
{
    // search
    int l_index = 0;
    int rc = locateSymbol( i_address, l_index );
    if( rc < 0 )
    {
        // not found
        return NULL;
    }
    return iv_vecSymbols[l_index]->iv_pszName;
}





//------------------------------------------------------------------------
// hbSymbol methods


hbSymbol::hbSymbol()
{
    iv_validationBits = 0;
    iv_Type           = 0;
    iv_Address        = 0;
    iv_Length         = 0;
    iv_pszName        = NULL;
}

void hbSymbol::setAddress( const char * i_pszAddress )
{
    sscanf( i_pszAddress, "%llX", &iv_Address );
    iv_validationBits |= ADDRESS;
}

void hbSymbol::setLength( const char * i_pszLength )
{
    sscanf( i_pszLength,  "%llX", &iv_Length  );
    iv_validationBits |= LENGTH;
}

void hbSymbol::setType( int i_type )
{
    iv_Type = i_type;
    iv_validationBits |= TYPE;
}

void hbSymbol::setSymbolName( char * i_pszName )
{
    trim( i_pszName );

    delete[] iv_pszName;
    int cb = strlen( i_pszName ) + 1;
    iv_pszName =  new char[cb];
    strcpy( iv_pszName, i_pszName );
    if( cb > 1 )
    {
        iv_validationBits |= NAME;
    }
}

bool hbSymbol::isValid()
{
    // ensure somebody called to set address, length,
    // name of symbol, and type.  This would indicate the
    // parsing of the symbols input line went OK.
    return ((TYPE|ADDRESS|LENGTH|NAME)==(iv_validationBits));
}


hbSymbol::~hbSymbol()
{
    delete[] iv_pszName;
}




