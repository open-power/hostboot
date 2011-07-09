/** @file segment.H
 *  @brief Contains the definition of the virtual Segment class.
 */
#ifndef __KERNEL_SEGMENT_H
#define __KERNEL_SEGMENT_H

#include <kernel/task.H>

/** @class Segment
 *  @brief Virtual segment class to handle virtual memory management within
 *         a 1TB segment.
 */
class Segment
{
    public:
        /**
         * @brief Constructor.
         * @param[in] i_baseAddr - Base [virtual] address of this segment.
         */
        explicit Segment(uint64_t i_baseAddr) : iv_baseAddress(i_baseAddr) {};
        /**
         * @brief Destructor.
         * No additional action necessary.
         */
        virtual ~Segment() {};

        /**
         * @brief Responsible for handling page faults within the segment.
         *
         * @param[in] i_task - Task causing the page fault.
         * @param[in] i_addr - Effective address accessed to cause fault.
         *
         * @return true - Page fault was successfully handled.
         *
         * If the page fault is not successfully handled the expectation is
         * that the VMM will perform appropriate action, such as killing the
         * task.
         */
        virtual bool handlePageFault(task_t* i_task, uint64_t i_addr) = 0;

        /**
         * @brief Get the base address of this segment.
         * @return Base address (as uint64_t).
         */
        uint64_t getBaseAddress() const { return iv_baseAddress; };

    protected:
            /** The base address of the segment. */
        const uint64_t iv_baseAddress;
};

#endif
