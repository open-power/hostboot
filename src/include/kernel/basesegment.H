/** @file basesegment.H
 *  @brief Defines the base segment (0TB) class.
 */
#ifndef __KERNEL_BASESEGMENT_H
#define __KERNEL_BASESEGMENT_H

#include <kernel/segment.H>

class Block;

/** @class BaseSegment
 *  @brief Class to manage the base segment at 0 TB.
 *
 *  Contains a chain of blocks associated with the first segment.
 */
class BaseSegment : public Segment
{
    protected:
        /**
         * @brief Constructor.
         * Initialize attributes and set base addresss of segment to 0 TB.
         */
        BaseSegment() : Segment(0x0), iv_block(NULL) {};
        /**
         * @brief Destructor
         * Delete any blocks owned by this segment.
         */
        ~BaseSegment();

    public:
        /**
         * @brief Initialize the segment by allocating initial blocks and
         *        adding to the segment manager.
         */
        static void init();

        /**
         * @brief Implementation of the pure-virtual function from Segment.
         *
         * Calls block chain to deal with page fault.
         */
        bool handlePageFault(task_t* i_task, uint64_t i_addr);

    private:
        /**
         * @brief Internal implementation of init function.
         */
        void _init();

        /** Block-chain associated with this Segment. */
        Block* iv_block;
};

#endif
