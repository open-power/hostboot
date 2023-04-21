#ifndef INSTANCE_ID_H
#define INSTANCE_ID_H

#ifdef __cplusplus
extern "C" {
#endif

#include "libpldm/base.h"
#include <stdint.h>

typedef uint8_t pldm_instance_id_t;
struct pldm_instance_db;

#ifdef __STDC_HOSTED__
/**
 * @brief Instantiates an instance ID database object for a given database path
 *
 * @param[out] ctx - *ctx must be NULL, and will point to a PLDM instance ID
 * 		     database object on success.
 * @param[in] dbpath - the path to the instance ID database file to use
 *
 * @return int - Returns 0 on success. Returns -EINVAL if ctx is NULL or *ctx
 * 		 is not NULL. Returns -ENOMEM if memory couldn't be allocated.
 *		 Returns the errno if the database couldn't be opened.
 * */
int pldm_instance_db_init(struct pldm_instance_db **ctx, const char *dbpath);

/**
 * @brief Instantiates an instance ID database object for the default database
 * 	  path
 *
 * @param[out] ctx - *ctx will point to a PLDM instance ID database object on
 * 	       success.
 *
 * @return int - Returns 0 on success. Returns -EINVAL if ctx is NULL or *ctx
 * 		 is not NULL. Returns -ENOMEM if memory couldn't be allocated.
 * 		 Returns the errno if the database couldn't be opened.
 * */
int pldm_instance_db_init_default(struct pldm_instance_db **ctx);

/**
 * @brief Destroys an instance ID database object
 *
 * @param[in] ctx - PLDM instance ID database object
 *
 * @return int - Returns 0 on success or if *ctx is NULL. No specific errors are
 *		 specified.
 * */
int pldm_instance_db_destroy(struct pldm_instance_db *ctx);

/**
 * @brief Allocates an instance ID for a destination TID from the instance ID
 * 	  database
 *
 * @param[in] ctx - PLDM instance ID database object
 * @param[in] tid - PLDM TID
 * @param[in] iid - caller owned pointer to a PLDM instance ID object. On
 * 	      success, this points to an instance ID to use for a PLDM request
 * 	      message.
 *
 * @return int - Returns 0 on success if we were able to allocate an instance
 * 		 ID. Returns -EINVAL if the iid pointer is NULL. Returns -EAGAIN
 *		 if a successive call may succeed. Returns -EPROTO if the
 *		 operation has entered an undefined state.
 */
int pldm_instance_id_alloc(struct pldm_instance_db *ctx, pldm_tid_t tid,
			   pldm_instance_id_t *iid);

/**
 * @brief Frees an instance ID previously allocated by pldm_instance_id_alloc
 *
 * @param[in] ctx - PLDM instance ID database object
 * @param[in] tid - PLDM TID
 * @param[in] iid - If this instance ID was not previously allocated by
 * 	      pldm_instance_id_alloc then EINVAL is returned.
 *
 * @return int - Returns 0 on success. Returns -EINVAL if the iid supplied was
 * 		 not previously allocated by pldm_instance_id_alloc or it has
 * 		 previously been freed. Returns -EAGAIN if a successive call may
 * 		 succeed. Returns -EPROTO if the operation has entered an
 *		 undefined state.
 */
int pldm_instance_id_free(struct pldm_instance_db *ctx, pldm_tid_t tid,
			  pldm_instance_id_t iid);

#endif /* __STDC_HOSTED__*/

#ifdef __cplusplus
}
#endif

#endif /* INSTANCE_ID_H */
