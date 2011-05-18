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
    
