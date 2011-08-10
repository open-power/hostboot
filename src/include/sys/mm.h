#ifndef __SYS_MM_H
#define __SYS_MM_H

#include <stdint.h>
#include <sys/msg.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @fn mm_alloc_block()
 *  @brief System call to allocate virtual memory block in the base segment
 *
 *  @param[in] mq - Message queue to be associated with the block
 *  @param[in] va - Base virtual address of the block to be allocated
 *  @param[in] size - Requested virtual memory size of the block
 *
 *  @return int - 0 for successful block allocation, non-zero otherwise
 */
int mm_alloc_block(msg_q_t mq,void* va,uint64_t size);

#ifdef __cplusplus
}
#endif

#endif
