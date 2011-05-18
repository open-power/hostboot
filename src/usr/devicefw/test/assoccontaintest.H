#ifndef __TEST_ASSOCCONTAINTEST_H
#define __TEST_ASSOCCONTAINTEST_H

#include <cxxtest/TestSuite.H>
#include "../assoccontain.H"

using namespace DeviceFW;

class AssocContainTest: public CxxTest::TestSuite
{
public:
    
    /**
     * @test Ensure AssociationContainer can be constructed.
     */
    void testConstruct()
    {
        AssociationContainer* ac = new AssociationContainer();
        if (NULL == ac)
        {
            TS_FAIL("NULL pointer returned for 'new AssociationContainer'.");
        }
        delete ac;
    }

    /**
     * @test Verify allocate operation.
     */
    void testAllocate()
    {
        AssociationContainer ac;
        
        // Allocation of a single block.
        size_t root = ac.allocate(5);
        
        // Index operation on block.
        AssociationData* root_ptr = ac[root];
        if (NULL == root_ptr)
        {
            TS_FAIL("NULL pointer returned for newly allocated block.");
        }

        // Freshly allocated block is empty.
        for(int i = 0; i < 5; i++)
        {
            if (root_ptr[i].flag)
            {
                TS_FAIL("Wildcard flag set on newly allocated block.");
            }
            if (0 != root_ptr[i].offset)
            {
                TS_FAIL("Non-zero value set in newly allocated block.");
            }
        }
        
        // Second allocated block is outside original.
        size_t second_block = ac.allocate(2);
        if (((second_block + 2) > root) &&
            (second_block < (root + 5)))
        {
            TS_FAIL("Newly allocated block is inside previous block.");
        }
    }

    /**
     * @test Verify operator[].
     */
    void testIndex()
    {
        AssociationContainer ac;

        AssociationData root;
        AssociationData second;        
        
        root.offset = ac.allocate(5);
        second.offset = ac.allocate(2);
        second.flag = true;

        ac[second.offset][1].offset = 0x42;

        AssociationData* root_ptr = ac[root.offset];
        root_ptr[2] = second;
        
        // Check initial level block index.
        if ((ac[root.offset + 2]->flag != second.flag) ||
            (ac[root.offset + 2]->offset != second.offset))
        {
            TS_FAIL("Index operator points to incorrect block.");
        }

        // Check second level indirection block index.
        if (ac[ac[root.offset + 2]->offset + 1]->offset != 0x42)
        {
            TS_FAIL("Index operator points to incorrect block.");
        }
    }


};

#endif

