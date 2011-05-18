/** @file assoccontain.H
 *  @brief Provides a memory pool container for allocating blocks of
 *         associations for the device driver framework.
 *
 *  This class exists because storing the information in a normal map or
 *  vector would be exceptionally big for the expected sparseness of the
 *  device driver associations.
 */

#ifndef __DEVICEFW_ASSOCCONTAIN_H
#define __DEVICEFW_ASSOCCONTAIN_H

#include <stdint.h>
#include <builtins.h>

namespace DeviceFW
{
    /** @struct AssociationData
     *  @brief  Data about a particular association.
     *
     *  Typically this is a offset (pointer) to another association and an
     *  optional flag for the associatior to use.  This allows a user to
     *  construct a light-weight multi-dimensional sparse array.
     *
     *  The purpose of the flag field is left to the user.
     */
    struct AssociationData
    {
        bool    flag:1;
        size_t  offset:15;
        
        AssociationData() : flag(false), offset(0) { };

        AssociationData(bool i_flag, size_t i_off) 
            : flag(i_flag), offset(i_off) { };

    } PACKED;
    
    /** @class AssociationContainer
     *  @brief The memory pool container of AssociationData blocks.
     *
     *  The typical usage of this will be to create a multi-dimensional sparse
     *  associative array (map).  The first block allocated will be the first
     *  dimension of the array.  Each AssociationData entry in the block is the
     *  offset of the block containing the AssociationData for the next 
     *  dimension.  At the lowest level this offset might be used as an offset
     *  into another container, such as an std::vector.
     */
    class AssociationContainer
    {
        public:
            /**
             * @brief Constructor for AssociationContainer.
             *
             * Initializes internal members to clean values.
             */
            AssociationContainer();

            /**
             * @brief Destructor for AssociationContainer.
             *
             * Releases memory associated with container.  After this call
             * all pointers previously obtained through operator[] are invalid.
             */
            ~AssociationContainer();
                
            /**
             * @brief Look up a particular association entry by offset.
             * @return A pointer to the requested association block.
             *
             * @note Will return a NULL pointer if an invalid offset is given.
             */
            AssociationData* operator[](size_t) const;

            /**
             * @brief Allocate a new block into the pool.
             * @return A offset to the newly allocated block.
             *
             * The blocks allocated will all be erased to 0's.
             *
             * @note This function can change the pointers previously
             *       returned by the operator[].  Treat this function
             *       as though all previous pointers are invalidated.
             */
            size_t allocate(size_t);

        private:
            AssociationData*    iv_data;
            size_t              iv_size;
    };
};

#endif
