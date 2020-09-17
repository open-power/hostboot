/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/symbols.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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





#ifndef ERRL_PLUGINS_SYMS_H
#define ERRL_PLUGINS_SYMS_H

#include <vector>
#include <stdint.h>

/**
 *  @file symbols.H
 *
 *  @brief read HB symbols file and provide a lookup mechanism.
 *
 *  NOTE: The file src/build/tools/ebmc/symbols.py should be kept in sync
 *  with the lookup mechanism in this file
 *
 */


/**
 *  @brief  hbSymbol
 *
 *  This class contains the data from a line of the HB syms file.
 */

class hbSymbol
{
    public:

    // Data from a line from hbicore.syms
    uint64_t  iv_Address;
    uint64_t  iv_Length;
    char *    iv_pszName;

    // The char in column 1 of hbicore.syms
    int       iv_Type;

    hbSymbol();

    /** @brief Set the starting address of the symbol.
     */
    void setAddress( const char * i_pszAddress );


    /** @brief Set the length of the data over which
     *  this symbol spans.
     */
    void setLength( const char * i_pszLength );


    /** @brief Set the symbol name.
     */
    void setSymbolName( char * i_pszName );


    /** @brief Set the type of symbol. This is
     *  the char found in column 1 of Hostboot
     *  symbol files.  F is function, V is variable.
     */
    void setType( int i_type );


    /** @brief Checks to see if all four set functions
     *  have been called.  If so, then this symbol is considered
     *  valid.  These symbols are built piecemeal as values are
     *  scanned from the input line of text.
     */
    bool isValid();


    ~hbSymbol();

    // A validation scheme, since instance
    // vars are set piecemeal.
    enum
    {
        ADDRESS  =  0x0001,
        LENGTH   =  0x0002,
        NAME     =  0x0004,
        TYPE     =  0x0008,
    };

    private:
    int iv_validationBits;

};






/**
 * @brief  hbSymbolTable
 *
 * Container for hbSymbols with methods to initialize and access.
 */


class hbSymbolTable
{
    public:

    /** @brief Contructor. To use: create instance, then
     *  call readSymbols() to populate the symbol table.
     *  Then call nearestSymbol().
     */
    hbSymbolTable();

    /** @brief Read the symbols file, return zero for success.
     *  On success, then you can call nearestSymbol()
     */
    int readSymbols( const char * i_filename );

    /** @brief Find and return the nearest symbol for the address given.
     *  Returns null when not found.
     */
    char * nearestSymbol( uint64_t  i_address );

    /** @brief Destructor.
     */
    ~hbSymbolTable();

    private:

    bool iv_fPopulated;
    char * iv_pFileName;
    std::vector<hbSymbol*> iv_vecSymbols;

    // Read the file and populate the symbol vector.
    int populateSymbolVector();

    // Given the address, find the vector index of the symbol.
    // Return -1 if not found.
    // Return 0 for exact match.
    // Return 1 for nearest (previous) symbol
    int locateSymbol( uint64_t i_address, int & o_index );
};



#endif       // ERRL_PLUGINS_SYMS_H

