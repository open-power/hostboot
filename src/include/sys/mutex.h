#ifndef __SYS_MUTEX_H
#define __SYS_MUTEX_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef void* mutex_t;

mutex_t mutex_create();
int mutex_destroy(mutex_t);

int mutex_lock(mutex_t);
int mutex_unlock(mutex_t);

#ifdef __cplusplus
}
#endif
#endif
