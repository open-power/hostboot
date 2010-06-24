#ifndef __SYS_MSG_H
#define __SYS_MSG_H

#include <stdint.h>
#include <stdlib.h>

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
msg_q_t msg_q_create();
int msg_q_destroy();
int msg_q_register(msg_q_t q, char* name);
msg_q_t msg_q_resolve(char* name);

// Message interfaces.
__attribute__((always_inline)) 
    inline msg_t* msg_allocate() { return (msg_t*)malloc(sizeof(msg_t)); }
__attribute__((always_inline))
    inline void msg_free(msg_t* m) { free(m); }

int msg_send(msg_q_t q, msg_t* msg);
int msg_sendrecv(msg_q_t q, msg_t* msg);
int msg_respond(msg_q_t q, msg_t* msg);
msg_t* msg_wait(msg_q_t q);

__attribute__((always_inline))
    inline uint32_t msg_is_async(msg_t* msg) 
	{ return 0 == msg->__reserved__async; }

#ifdef __cplusplus
}
#endif

#endif
