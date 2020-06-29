/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_dynamic.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>
#include <p10_dynamic.H>

///////////////////////////////////////////////////////////////////////////
////////////////////////// APIs SUPPORTED /////////////////////////////////
// 1. API to get 64-bit vector size & number of records for features/services
//    void dynamic_get_bitVectorSize_n_numRecords( void*     i_dynSection,
//                                                 uint8_t*  o_bitVectorSize,
//                                                 uint16_t* o_numRecords);
//
// 2. API to check given feature/service record exist
//    void dynamic_is_record_exist( void* i_dynSection,
//                                  char* i_name,
//                                  bool* o_result); // 0 - Yes; 1 - No
//
// 3. API to get value for given "name" for features/services
//    void dynamic_get_value( void*     i_dynSection,
//                            char*     i_name,
//                            uint16_t* o_value);
//
// 4. API to get name length for given "value" for features/services
//    void dynamic_get_name_length_perValue( void*     i_dynSection,
//                                           uint16_t  i_value,
//                                           uint8_t*  o_nameLength);
//
// 5. API to get name for given "value" for features/services
//    void dynamic_get_name( void*     i_dynSection,
//                           uint16_t  i_value,
//                           char*     o_name); // name length can be determined by API dynamic_get_name_length_perValue
//
// 6. API to get bit vector for given "service name"
//    void dynamic_get_bitVector_perName( void*     i_dynSection,
//                                        char*     i_name,
//                                        uint64_t* o_bitVector); // bit vector size can be determined by
//                                                                // API dynamic_get_bitVectorSize_n_numRecords
//
// 7. API to get bit vector for given "service value"
//    void dynamic_get_bitVector_perValue( void*     i_dynSection,
//                                         uint16_t  i_value,
//                                         uint64_t* o_bitVector); // bit vector size can be determined by
//                                                                 // API dynamic_get_bitVectorSize_n_numRecords
//
// 8. API to get desc length for given "value" for features/services
//    void dynamic_get_desc_length_perValue( void*     i_dynSection,
//                                           uint16_t  i_value,
//                                           uint8_t*  o_descLength);
//
// 9. API to get desc for given "name" for features/services
//     void dynamic_get_desc_perName( void* i_dynSection,
//                                    char* i_name,
//                                    char* o_desc); // desc length can be determined by API dynamic_get_desc_length_perValue
//
// 10. API to get desc for given "value" for features/services
//     void dynamic_get_desc_perValue( void*     i_dynSection,
//                                     uint16_t  i_value,
//                                     char*     o_desc);// desc length can be determined by API dynamic_get_desc_length_perValu
//
// 11. API to get record offset for given "name" for features/services
//     void dynamic_get_record_perName( void*     i_dynSection,
//                                      char*     i_name,
//                                      uint32_t* o_offset);
//
// 12. API to get record offset for given "value" for features/services
//     void dynamic_get_record_perValue( void*     i_dynSection,
//                                       uint16_t  i_value,
//                                       uint32_t* o_offset);
//
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


// Function to get bit vector size & num of records for
// features/services from dynamic binary section
// ----------------------------------------------------
void dynamic_get_bitVectorSize_n_numRecords( void*     i_dynSection,
        uint8_t*  o_bitVectorSize,
        uint16_t* o_numRecords)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        //Get dynamic header fields
        //=========================
        //uint64_t    magic;
        //uint8_t     version;
        //uint8_t     numOf64BitsSet;
        //uint16_t    numOfRecords;
        //uint16_t    sizeOfBinary;
        *o_bitVectorSize = ((DynamicHdr_t*)i_dynSection)->numOf64BitsSet;
        *o_numRecords    = htobe16(((DynamicHdr_t*)i_dynSection)->numOfRecords);
    }
}


// Function to get record offset for name given for features/services in dynamic binary section
// --------------------------------------------------------------------------------------------
void dynamic_get_record_perName( void*     i_dynSection,
                                 char*     i_name,
                                 uint32_t* o_offset)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint16_t numOfRecords;
        uint8_t len, i, numOf64BitsSet;
        uint8_t* img_start_ptr;
        char* name;
        bool dyn_section; // 0 - Feature; 1 - Services

        //Get image start pointer
        img_start_ptr = (uint8_t*)i_dynSection;

        //Get bit vector size & number of records
        dynamic_get_bitVectorSize_n_numRecords(i_dynSection, &numOf64BitsSet, &numOfRecords);

        //Check for dyn section and update the flag
        if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) )
        {
            dyn_section = 0;
        }
        else
        {
            dyn_section = 1;
        }

        //Add header bytes
        i_dynSection = (uint8_t*)i_dynSection + 16; // <-- Adjust header bytes

        //process per record
        for ( i = 0; i < numOfRecords; i++ )
        {
            //Get name length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Pointer to name field
            name = (char*)i_dynSection;

            //Compare name
            if ( !strcmp(i_name, name) )
            {
                //Get offset of record
                *o_offset = (uint32_t)((uint8_t*)i_dynSection - img_start_ptr - 1);
                break;
            }

            //Add name length
            i_dynSection = (uint8_t*)i_dynSection + len;

            //Add value length
            i_dynSection = (uint8_t*)i_dynSection + 2;

            //Add bit vector length if any
            if ( dyn_section )
            {
                i_dynSection = (uint8_t*)i_dynSection + (numOf64BitsSet * 8);
            }

            //Add desc length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Get to next record
            i_dynSection = (uint8_t*)i_dynSection + len;
        }
    }
}


// Function to get record offset for value given for features/services in dynamic binary section
// ---------------------------------------------------------------------------------------------
void dynamic_get_record_perValue( void*     i_dynSection,
                                  uint16_t  i_value,
                                  uint32_t* o_offset)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint16_t numOfRecords, val;
        uint8_t len, i, numOf64BitsSet;
        uint8_t* img_start_ptr;
        bool dyn_section; // 0 - Feature; 1 - Services

        //Get image start pointer
        img_start_ptr = (uint8_t*)i_dynSection;

        //Get bit vector size & number of records
        dynamic_get_bitVectorSize_n_numRecords(i_dynSection, &numOf64BitsSet, &numOfRecords);

        //Check for dyn section and update the flag
        if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) )
        {
            dyn_section = 0;
        }
        else
        {
            dyn_section = 1;
        }

        //Add header bytes
        i_dynSection = (uint8_t*)i_dynSection + 16; // <-- Adjust header bytes

        //process per record
        for ( i = 0; i < numOfRecords; i++ )
        {
            //Get name length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Get value of name
            val = be16toh(*((uint16_t*)((uint8_t*)i_dynSection + len))); //<-- value

            //Compare val
            if ( i_value == val )
            {
                //Get offset of record
                *o_offset = (uint32_t)((uint8_t*)i_dynSection - img_start_ptr - 1);
                break;
            }

            //Add name length
            i_dynSection = (uint8_t*)i_dynSection + len;

            //Add value length
            i_dynSection = (uint8_t*)i_dynSection + 2;

            //Add bit vector length if any
            if ( dyn_section )
            {
                i_dynSection = (uint8_t*)i_dynSection + (numOf64BitsSet * 8);
            }

            //Add desc length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Get to next record
            i_dynSection = (uint8_t*)i_dynSection + len;
        }
    }
}


// Function to get value for given name for features/services from dynamic binary section
// --------------------------------------------------------------------------------------
void dynamic_get_value( void*     i_dynSection,
                        char*     i_name,
                        uint16_t* o_value)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint8_t len;
        uint32_t offset = 0;

        //Get matching record offset in binary image
        dynamic_get_record_perName(i_dynSection, i_name, &offset);

        if ( offset )
        {
            //Get to the record in binary image
            i_dynSection = (uint8_t*)i_dynSection + offset;

            //process record
            //Get name length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Add name length
            i_dynSection = (uint8_t*)i_dynSection + len;

            //Get value of name
            *o_value = be16toh(*((uint16_t*)i_dynSection)); //<-- value
        }
    }
}


// Function to get name length for value given for features/services from dynamic binary section
// ---------------------------------------------------------------------------------------------
void dynamic_get_name_length_perValue( void*     i_dynSection,
                                       uint16_t  i_value,
                                       uint8_t*  o_nameLength)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint32_t offset = 0;

        //Get matching record offset in binary image
        dynamic_get_record_perValue(i_dynSection, i_value, &offset);

        if ( offset )
        {
            //Get to the record in binary image
            i_dynSection = (uint8_t*)i_dynSection + offset;

            //process record
            //Update length of name (incl. null char)
            *o_nameLength = *(uint8_t*)((uint8_t*)i_dynSection);
        }
    }
}


// Function to get name for given value for features/services from dynamic binary section
// --------------------------------------------------------------------------------------
void dynamic_get_name( void*     i_dynSection,
                       uint16_t  i_value,
                       char*     o_name)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint32_t offset = 0;

        //Get matching record offset in binary image
        dynamic_get_record_perValue(i_dynSection, i_value, &offset);

        //Get to the record in binary image
        i_dynSection = (uint8_t*)i_dynSection + offset;

        if ( offset )
        {
            //process record
            //Pointer to name field
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Get name
            strcpy(o_name, (char*)i_dynSection);
        }
    }
}


// Function to get bit vector for given service name from dynamic services binary section
// --------------------------------------------------------------------------------------
void dynamic_get_bitVector_perName( void*     i_dynSection,
                                    char*     i_name,
                                    uint64_t* o_bitVector)
{
    //Dynamic binary image - Services
    //===============================
    if ( be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE )
    {
        uint16_t numOfRecords;
        uint8_t len, i, numOf64BitsSet;
        uint32_t offset = 0;

        //Get bit vector size & number of records
        dynamic_get_bitVectorSize_n_numRecords(i_dynSection, &numOf64BitsSet, &numOfRecords);

        //Get matching record offset in binary image
        dynamic_get_record_perName(i_dynSection, i_name, &offset);

        if ( offset )
        {
            //Get to the record in binary image
            i_dynSection = (uint8_t*)i_dynSection + offset;

            //process record
            //Get name length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Add name length
            i_dynSection = (uint8_t*)i_dynSection + len;

            //Add value length
            i_dynSection = (uint8_t*)i_dynSection + 2;

            //Get bit vector
            for ( i = 0; i < numOf64BitsSet; i++ )
            {
                *o_bitVector = be64toh(*((uint64_t*)i_dynSection + i));
                o_bitVector++;
            }
        }
    }
}


// Function to get bit vector for given service value from dynamic services binary section
// ---------------------------------------------------------------------------------------
void dynamic_get_bitVector_perValue( void*     i_dynSection,
                                     uint16_t  i_value,
                                     uint64_t* o_bitVector)
{
    //Dynamic binary image - Services
    //===============================
    if ( be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE )
    {
        uint16_t numOfRecords;
        uint8_t len, i, numOf64BitsSet;
        uint32_t offset = 0;

        //Get bit vector size & number of records
        dynamic_get_bitVectorSize_n_numRecords(i_dynSection, &numOf64BitsSet, &numOfRecords);

        //Get matching record offset in binary image
        dynamic_get_record_perValue(i_dynSection, i_value, &offset);

        if ( offset )
        {
            //Get to the record in binary image
            i_dynSection = (uint8_t*)i_dynSection + offset;

            //process record
            //Get name length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Add name length
            i_dynSection = (uint8_t*)i_dynSection + len;

            //Add value length
            i_dynSection = (uint8_t*)i_dynSection + 2;

            //Get bit vector
            for ( i = 0; i < numOf64BitsSet; i++ )
            {
                *o_bitVector = be64toh(*((uint64_t*)i_dynSection + i));
                o_bitVector++;
            }
        }
    }
}


// Function to check given feature/service record exist in dynamic binary section
// ------------------------------------------------------------------------------
void dynamic_is_record_exist( void* i_dynSection,
                              char* i_name,
                              bool* o_result)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint32_t offset = 0;

        //Get matching record offset in binary image
        dynamic_get_record_perName(i_dynSection, i_name, &offset);

        //Check for record existense
        if ( offset )
        {
            *o_result = 0; // record found
        }
        else
        {
            *o_result = 1; // record not found
        }
    }
}


// Function to get desc length for given value for features/services from dynamic binary section
// ---------------------------------------------------------------------------------------------
void dynamic_get_desc_length_perValue( void*     i_dynSection,
                                       uint16_t  i_value,
                                       uint8_t*  o_descLength)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint16_t numOfRecords;
        uint8_t len, numOf64BitsSet;
        uint32_t offset = 0;
        bool dyn_section; // 0 - Feature; 1 - Services

        //Get bit vector size & number of records
        dynamic_get_bitVectorSize_n_numRecords(i_dynSection, &numOf64BitsSet, &numOfRecords);

        //Check for dyn section and update the flag
        if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) )
        {
            dyn_section = 0;
        }
        else
        {
            dyn_section = 1;
        }

        //Get matching record offset in binary image
        dynamic_get_record_perValue(i_dynSection, i_value, &offset);

        if ( offset )
        {
            //Get to the record in binary image
            i_dynSection = (uint8_t*)i_dynSection + offset;

            //process record
            //Get name length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Add name length
            i_dynSection = (uint8_t*)i_dynSection + len;

            //Add value length
            i_dynSection = (uint8_t*)i_dynSection + 2;

            //Add service bit vector length if any
            if ( dyn_section )
            {
                i_dynSection = (uint8_t*)i_dynSection + (numOf64BitsSet * 8);
            }

            //Get desc length (incl. null char)
            *o_descLength = *(uint8_t*)((uint8_t*)i_dynSection);
        }
    }
}


// Function to get desc for given name for features/services from dynamic binary section
// -------------------------------------------------------------------------------------
void dynamic_get_desc_perName( void* i_dynSection,
                               char* i_name,
                               char* o_desc)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint16_t numOfRecords;
        uint8_t len, numOf64BitsSet;
        uint32_t offset = 0;
        bool dyn_section; // 0 - Feature; 1 - Services

        //Get bit vector size & number of records
        dynamic_get_bitVectorSize_n_numRecords(i_dynSection, &numOf64BitsSet, &numOfRecords);

        //Check for dyn section and update the flag
        if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) )
        {
            dyn_section = 0;
        }
        else
        {
            dyn_section = 1;
        }

        //Get matching record offset in binary image
        dynamic_get_record_perName(i_dynSection, i_name, &offset);

        if ( offset )
        {
            //Get to the record in binary image
            i_dynSection = (uint8_t*)i_dynSection + offset;

            //process record
            //Get name length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Add name length
            i_dynSection = (uint8_t*)i_dynSection + len;

            //Add value length
            i_dynSection = (uint8_t*)i_dynSection + 2;

            //Add service bit vector length if any
            if ( dyn_section )
            {
                i_dynSection = (uint8_t*)i_dynSection + (numOf64BitsSet * 8);
            }

            //Get to desc pointer
            i_dynSection = (uint8_t*)i_dynSection + 1;
            strcpy(o_desc, (char*)i_dynSection);
        }
    }
}


// Function to get desc for given value for features/services from dynamic binary section
// --------------------------------------------------------------------------------------
void dynamic_get_desc_perValue( void*     i_dynSection,
                                uint16_t  i_value,
                                char*     o_desc)
{
    //Dynamic binary image - Features/Services
    //========================================
    if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) ||
         (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_SERVICE) )
    {
        uint16_t numOfRecords;
        uint8_t len, numOf64BitsSet;
        uint32_t offset = 0;
        bool dyn_section; // 0 - Feature; 1 - Services

        //Get bit vector size & number of records
        dynamic_get_bitVectorSize_n_numRecords(i_dynSection, &numOf64BitsSet, &numOfRecords);

        //Check for dyn section and update the flag
        if ( (be64toh(((DynamicHdr_t*)i_dynSection)->magic) == DYN_MAGIC_FEATURE) )
        {
            dyn_section = 0;
        }
        else
        {
            dyn_section = 1;
        }

        //Get matching record offset in binary image
        dynamic_get_record_perValue(i_dynSection, i_value, &offset);

        if ( offset )
        {
            //Get to the record in binary image
            i_dynSection = (uint8_t*)i_dynSection + offset;

            //process record
            //Get name length
            len = *(uint8_t*)((uint8_t*)i_dynSection);
            i_dynSection = (uint8_t*)i_dynSection + 1;

            //Add name length
            i_dynSection = (uint8_t*)i_dynSection + len;

            //Add value length
            i_dynSection = (uint8_t*)i_dynSection + 2;

            //Add service bit vector length if any
            if ( dyn_section )
            {
                i_dynSection = (uint8_t*)i_dynSection + (numOf64BitsSet * 8);
            }

            //Get to desc pointer
            i_dynSection = (uint8_t*)i_dynSection + 1;
            strcpy(o_desc, (char*)i_dynSection);
        }
    }
}
