/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devicefw/assoccontain.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include "assoccontain.H"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

namespace DeviceFW
{

    AssociationContainer::AssociationContainer()
        : iv_data(NULL), iv_size(0)
    {
    }

    AssociationContainer::~AssociationContainer()
    {
        if (NULL != iv_data)
        {
            free(iv_data);
        }
    }

    AssociationData* AssociationContainer::operator[](size_t i_pos) const
    {
        if (i_pos >= iv_size)
        {
            return NULL;
        }

        return &iv_data[i_pos];
    }

    size_t AssociationContainer::allocate(size_t i_size)
    {
        size_t cur_pos = iv_size;

        // Resize buffer to have space for request.
        iv_size += i_size;
        iv_data =
            static_cast<AssociationData*>(
                realloc(iv_data,
                        sizeof(AssociationData) * (iv_size)
                )
            );

        // Clear out newly allocated space.
        memset(this->operator[](cur_pos), '\0', 
               sizeof(AssociationData) * i_size);

        return cur_pos;
    }
};
    
