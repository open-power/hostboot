#ifndef __SYS_MSG_H
#define __SYS_MSG_H

#include <stdint.h>
#include <stdlib.h>
#include <builtins.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef void* msg_q_t;

struct msg_t
{
    uint32_t type;
    uint32_t __reserved__async;
    uint64_t data[2];
    void* extra_data;
};

// Message queue interfaces.


/** @fn msg_q_create
  * @brief Create a new message queue.
  *
  * @return msg_q_t handle
  */
msg_q_t msg_q_create();


/** @fn msg_q_destroy
  * @brief Deallocate a message queue previously allocated with msg_q_create()
  *
  * @param[in] q - handle to message queue to destroy
  */
void msg_q_destroy( msg_q_t q );


/** @fn msg_q_register
  * @brief Assign a name to a message queue.
  *
  * @param[in] q - handle of message queue to name
  * @param[in] name - name
  * 
  * @return  Result of msg_sendrecv where zero indicates success
  */
int msg_q_register(msg_q_t q, const char* name);


/** @fn msg_q_resolve
  * @brief Given the name of a message queue, return the handle to it.
  *
  * @param[in] name - name of message queue
  *
  * @return message queue handle or null if name not found.
  */
msg_q_t msg_q_resolve(const char* name);





// Message interfaces.
/** @fn msg_allocate
  * @brief Allocate space for message 
  * @return Pointer to message
  */
ALWAYS_INLINE 
    inline msg_t* msg_allocate() { return (msg_t*)malloc(sizeof(msg_t)); }


/** @fn msg_free
  * @brief Free a msg_t
  * @param[in] msg - message to free
  */

ALWAYS_INLINE
    inline void msg_free(msg_t* m) { free(m); }


/** @fn msg_send 
  * @brief Send a message asynchronously.
  *
  * This call adds the message queue then returns 
  * to the caller. Any process waiting for a message 
  * in the queue will awake with this message.
  *
  * @param[in] q - message queue
  * @param[in] msg - message
  * @return    Always returns zero.
  */
int msg_send(msg_q_t q, msg_t* msg);


/** @fn msg_sendrecv
  * @brief Send a message to a server and get a response synchronously.
  *
  * The calling [client] thread blocks until the recipient [server] receives 
  * and replies to the message. 
  *
  * @param[in] q - message queue
  * @param[in,out] msg - message
  * @return Zero on success, else negative.
  */
int msg_sendrecv(msg_q_t q, msg_t* msg);


/** @fn msg_respond
  * @brief Respond to a synchronous message.
  *
  * This is how server-side code responds to synchronous
  * messaging when clients call msg_sendrecv().  
  * 
  * @param[in] q - message queue
  * @param[in] msg - response message
  * @return Zero on success, else negative.
  */
int msg_respond(msg_q_t q, msg_t* msg);


/** @fn msg_wait
  * @brief  Read a message from the message queue.
  * 
  * If a message is already on the queue, this call will return immediately
  * with the message. Otherwise the calling thread will block and wait for
  * a message. 
  *
  * @param[in] q - message queue to read
  * @return the message posted to the queue
  */
msg_t* msg_wait(msg_q_t q);


/** @fn msg_is_async
  * @brief  Indicates if message is asynchronous.
  *
  * Tests the message field "__reserved__async" which appears to be set to 0 to indicate asynchronous, and 1 to indicate synchronous message.
  *
  * @return true if asynchronous message
  */
ALWAYS_INLINE
    inline uint32_t msg_is_async(msg_t* msg) 
	{ return 0 == msg->__reserved__async; }

#ifdef __cplusplus
}
#endif

#endif
