#ifndef PDR_H
#define PDR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/** @struct pldm_pdr
 *  opaque structure that acts as a handle to a PDR repository
 */
typedef struct pldm_pdr pldm_pdr;

/** @struct pldm_pdr_record
 *  opaque structure that acts as a handle to a PDR record
 */
typedef struct pldm_pdr_record pldm_pdr_record;

/* ====================== */
/* Common PDR access APIs */
/* ====================== */

/** @brief Make a new PDR repository
 *
 *  @return opaque pointer that acts as a handle to the repository; NULL if no
 *  repository could be created
 *
 *  @note  Caller may make multiple repositories (for its own PDRs, as well as
 *  for PDRs received by other entities) and can associate the returned handle
 *  to a PLDM terminus id.
 */
pldm_pdr *pldm_pdr_init(void);

/** @brief Destroy a PDR repository (and free up associated resources)
 *
 *  @param[in/out] repo - pointer to opaque pointer acting as a PDR repo handle
 */
void pldm_pdr_destroy(pldm_pdr *repo);

/** @brief Get number of records in a PDR repository
 *
 *  @pre repo must point to a valid object
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *
 *  @return uint32_t - number of records
 */
uint32_t pldm_pdr_get_record_count(const pldm_pdr *repo);

/** @brief Get size of a PDR repository, in bytes
 *
 *  @pre repo must point to a valid object
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *
 *  @return uint32_t - size in bytes
 */
uint32_t pldm_pdr_get_repo_size(const pldm_pdr *repo);

/** @brief Add a PDR record to a PDR repository, or return an error
 *
 *  @param[in/out] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] data - pointer to a PDR record, pointing to a PDR definition as
 *  per DSP0248. This data is memcpy'd.
 *  @param[in] size - size of input PDR record in bytes
 *  @param[in] is_remote - if true, then the PDR is not from this terminus
 *  @param[in] terminus_handle - terminus handle of the input PDR record
 *  @param[in,out] record_handle - record handle of input PDR record. If this is set to 0 then a
 *  record handle is computed. The computed handle is assigned to both the PDR record and back into
 *  record_handle for the caller to consume.
 *
 *  @return 0 on success, -EINVAL if the arguments are invalid, -ENOMEM if an internal memory
 *  allocation fails, or -EOVERFLOW if a record handle could not be allocated
 */
int pldm_pdr_add_check(pldm_pdr *repo, const uint8_t *data, uint32_t size,
		       bool is_remote, uint16_t terminus_handle,
		       uint32_t *record_handle);

/** @brief Get record handle of a PDR record
 *
 *  @pre repo must point to a valid object
 *  @pre record must point to a valid object
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] record - opaque pointer acting as a PDR record handle
 *
 *  @return uint32_t - record handle assigned to PDR record; 0 if record is not
 *  found
 */
uint32_t pldm_pdr_get_record_handle(const pldm_pdr *repo,
				    const pldm_pdr_record *record);

/** @brief Find PDR record by record handle
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] record_handle - input record handle
 *  @param[in/out] data - will point to PDR record data (as per DSP0248) on
 *                        return
 *  @param[out] size - *size will be size of PDR record
 *  @param[out] next_record_handle - *next_record_handle will be the record
 *  handle of record next to the returned PDR record
 *
 *  @return opaque pointer acting as PDR record handle, will be NULL if record
 *  was not found
 */
const pldm_pdr_record *pldm_pdr_find_record(const pldm_pdr *repo,
					    uint32_t record_handle,
					    uint8_t **data, uint32_t *size,
					    uint32_t *next_record_handle);

/** @brief Get PDR record next to input PDR record
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] curr_record - opaque pointer acting as a PDR record handle
 *  @param[in/out] data - will point to PDR record data (as per DSP0248) on
 *                        return
 *  @param[out] size - *size will be size of PDR record
 *  @param[out] next_record_handle - *next_record_handle will be the record
 *  handle of record nect to the returned PDR record
 *
 *  @return opaque pointer acting as PDR record handle, will be NULL if record
 *  was not found
 */
const pldm_pdr_record *
pldm_pdr_get_next_record(const pldm_pdr *repo,
			 const pldm_pdr_record *curr_record, uint8_t **data,
			 uint32_t *size, uint32_t *next_record_handle);

/** @brief Find (first) PDR record by PDR type
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] pdr_type - PDR type number as per DSP0248
 *  @param[in] curr_record - opaque pointer acting as a PDR record handle; if
 *  not NULL, then search will begin from this record's next record
 *  @param[in/out] data - will point to PDR record data (as per DSP0248) on
 *                        return, if input is not NULL
 *  @param[out] size - *size will be size of PDR record, if input is not NULL
 *
 *  @return opaque pointer acting as PDR record handle, will be NULL if record
 *  was not found
 */
const pldm_pdr_record *
pldm_pdr_find_record_by_type(const pldm_pdr *repo, uint8_t pdr_type,
			     const pldm_pdr_record *curr_record, uint8_t **data,
			     uint32_t *size);

/** @brief Determine if a record is a remote record
 *
 *  @pre record must point to a valid object
 *
 *  @return true if the record is a remote record, false otherwise.
 */
bool pldm_pdr_record_is_remote(const pldm_pdr_record *record);

/** @brief Remove all PDR records that belong to a remote terminus
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *
 *  If repo is NULL then there are no PDRs that can be removed.
 */
void pldm_pdr_remove_remote_pdrs(pldm_pdr *repo);

/** @brief Remove all remote PDR's that beling to a specific terminus
 *         handle
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] terminus_handle - Terminus Handle of the remove PLDM terminus
 *
 *  If repo is NULL there are no PDRs that can be removed.
 */
void pldm_pdr_remove_pdrs_by_terminus_handle(pldm_pdr *repo,
					     uint16_t terminus_handle);

/** @brief Update the validity of TL PDR - the validity is decided based on
 * whether the valid bit is set or not as per the spec DSP0248
 *
 * @param[in] repo - opaque pointer acting as a PDR repo handle
 * @param[in] terminus_handle - PLDM terminus handle
 * @param[in] tid - Terminus ID
 * @param[in] tl_eid - MCTP endpoint EID
 * @param[in] valid - validity bit of TLPDR
 */
/* NOLINTNEXTLINE(readability-identifier-naming) */
void pldm_pdr_update_TL_pdr(const pldm_pdr *repo, uint16_t terminus_handle,
			    uint8_t tid, uint8_t tl_eid, bool valid);

/** @brief Find the last record within the particular range
 * of record handles
 *
 *  @param[in] repo - pointer acting as a PDR repo handle
 *  @param[in] first - first record handle value of the records in the range
 *  @param[in] last - last record handle value of the records in the range
 *
 *  @return pointer to the PDR record,will be NULL if record was not
 *  found
 */
pldm_pdr_record *pldm_pdr_find_last_in_range(const pldm_pdr *repo,
					     uint32_t first, uint32_t last);

/** @brief find the container ID of the contained entity which is not in the
 *  particular range of record handles given
 *
 * @param[in] repo - opaque pointer acting as a PDR repo handle
 * @param[in] entity_type - entity type
 * @param[in] entity_instance - instance of the entity
 * @param[in] child_index - index of the child entity whose container id needs to be found
 * @param[in] range_exclude_start_handle - first record handle in the range of the remote endpoint
 * 	      which is ignored
 * @param[in] range_exclude_end_handle - last record handle in the range of the remote endpoint
 * 	      which is ignored
 * @param[out] container_id - container id of the contained entity
 *
 * @return container id of the PDR record found on success,-EINVAL when repo is NULL
 * or -ENOKEY if the container id is not found.
 */
int pldm_pdr_find_child_container_id_index_range_exclude(
	const pldm_pdr *repo, uint16_t entity_type, uint16_t entity_instance,
	uint8_t child_index, uint32_t range_exclude_start_handle,
	uint32_t range_exclude_end_handle, uint16_t *container_id);

/* ======================= */
/* FRU Record Set PDR APIs */
/* ======================= */

/** @brief Add a FRU record set PDR record to a PDR repository, or return an error
 *
 *  @param[in/out] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] terminus_handle - PLDM terminus handle of terminus owning the PDR
 *  record
 *  @param[in] fru_rsi - FRU record set identifier
 *  @param[in] entity_type - entity type of FRU
 *  @param[in] entity_instance_num - entity instance number of FRU
 *  @param[in] container_id - container id of FRU
 *  @param[in,out] bmc_record_handle - A pointer to the handle used to construct the next record. If
 *  		   the value is zero on input then a new handle is automatically allocated.
 *  		   Otherwise, the provided handle is used. If a new handle is automatically
 *  		   allocated then the object pointed to by bmc_record_handle will contain its value
 *  		   as output.
 *  @return 0 on success, -EINVAL if the arguments are invalid, or -ENOMEM if an internal allocation
 *  	    fails.
 */
int pldm_pdr_add_fru_record_set_check(pldm_pdr *repo, uint16_t terminus_handle,
				      uint16_t fru_rsi, uint16_t entity_type,
				      uint16_t entity_instance_num,
				      uint16_t container_id,
				      uint32_t *bmc_record_handle);

/** @brief Find a FRU record set PDR by FRU record set identifier
 *
 *  @param[in] repo - opaque pointer acting as a PDR repo handle
 *  @param[in] fru_rsi - FRU record set identifier
 *  @param[in] terminus_handle - *terminus_handle will be FRU terminus handle of
 *  found PDR, or 0 if not found
 *  @param[in] entity_type - *entity_type will be FRU entity type of found PDR,
 *  or 0 if not found
 *  @param[in] entity_instance_num - *entity_instance_num will be FRU entity
 *  instance number of found PDR, or 0 if not found
 *  @param[in] container_id - *cintainer_id will be FRU container id of found
 *  PDR, or 0 if not found
 *
 *  @return An opaque pointer to the PDR record on success, or NULL on failure
 */
const pldm_pdr_record *pldm_pdr_fru_record_set_find_by_rsi(
	const pldm_pdr *repo, uint16_t fru_rsi, uint16_t *terminus_handle,
	uint16_t *entity_type, uint16_t *entity_instance_num,
	uint16_t *container_id);

/* =========================== */
/* Entity Association PDR APIs */
/* =========================== */

typedef struct pldm_entity {
	uint16_t entity_type;
	uint16_t entity_instance_num;
	uint16_t entity_container_id;
} __attribute__((packed)) pldm_entity;

enum entity_association_containment_type {
	PLDM_ENTITY_ASSOCIAION_PHYSICAL = 0x0,
	PLDM_ENTITY_ASSOCIAION_LOGICAL = 0x1,
};

/** @struct pldm_entity_association_tree
 *  opaque structure that represents the entity association hierarchy
 */
typedef struct pldm_entity_association_tree pldm_entity_association_tree;

/** @struct pldm_entity_node
 *  opaque structure that represents a node in the entity association hierarchy
 */
typedef struct pldm_entity_node pldm_entity_node;

/** @brief Make a new entity association tree
 *
 *  @return opaque pointer that acts as a handle to the tree; NULL if no
 *  tree could be created
 */
pldm_entity_association_tree *pldm_entity_association_tree_init(void);

/** @brief Add a local entity into the entity association tree
 *
 *  @param[in/out] tree - opaque pointer acting as a handle to the tree
 *  @param[in/out] entity - pointer to the entity to be added. Input has the
 *                          entity type. On output, instance number and the
 *                          container id are populated.
 *  @param[in] entity_instance_number - entity instance number, we can use the
 *                                      entity instance number of the entity by
 *                                      default if its value is equal 0xFFFF.
 *  @param[in] parent - pointer to the node that should be the parent of input
 *                      entity. If this is NULL, then the entity is the root
 *  @param[in] association_type - relation with the parent : logical or physical
 *
 *  @return pldm_entity_node* - opaque pointer to added entity
 */
pldm_entity_node *pldm_entity_association_tree_add(
	pldm_entity_association_tree *tree, pldm_entity *entity,
	uint16_t entity_instance_number, pldm_entity_node *parent,
	uint8_t association_type);

/** @brief Add an entity into the entity association tree based on remote field
 *  set or unset.
 *
 *  @param[in/out] tree - opaque pointer acting as a handle to the tree
 *  @param[in/out] entity - pointer to the entity to be added. Input has the
 *                          entity type. On output, instance number and the
 *                          container id are populated.
 *  @param[in] entity_instance_number - entity instance number, we can use the
 *                                      entity instance number of the entity by
 *                                      default if its value is equal 0xFFFF.
 *  @param[in] parent - pointer to the node that should be the parent of input
 *                      entity. If this is NULL, then the entity is the root
 *  @param[in] association_type - relation with the parent : logical or physical
 *  @param[in] is_remote - used to denote whether we are adding a BMC entity to
 *                         the tree or a host entity
 *  @param[in] is_update_contanier_id - Used to determine whether need to update
 *                                      contanier id.
 *                                      true: should be changed
 *                                      false: should not be changed
 *  @param[in] container_id - container id of the entity added.
 *
 *  @return pldm_entity_node* - opaque pointer to added entity
 */
pldm_entity_node *pldm_entity_association_tree_add_entity(
	pldm_entity_association_tree *tree, pldm_entity *entity,
	uint16_t entity_instance_number, pldm_entity_node *parent,
	uint8_t association_type, bool is_remote, bool is_update_container_id,
	uint16_t container_id);

/** @brief Visit and note each entity in the entity association tree
 *
 *  @pre `*entities == NULL` and `*size == 0` must hold at the time of invocation.
 *
 *  Callers must inspect the values of `*entities` and `*size` post-invocation to determine if the
 *  invocation was a success or failure.
 *
 *  @param[in] tree - opaque pointer acting as a handle to the tree
 *  @param[out] entities - pointer to list of pldm_entity's. To be free()'d by
 *                         the caller
 *  @param[out] size - number of pldm_entity's
 */
void pldm_entity_association_tree_visit(pldm_entity_association_tree *tree,
					pldm_entity **entities, size_t *size);

/** @brief Extract pldm entity by the pldm_entity_node
 *
 *  @pre node must point to a valid object
 *
 *  @param[in] node     - opaque pointer to added entity
 *
 *  @return pldm_entity - pldm entity
 */
pldm_entity pldm_entity_extract(pldm_entity_node *node);

/** @brief Extract remote container id from the pldm_entity_node
 *
 *  @pre entity must point to a valid object
 *
 *  @param[in] entity - pointer to existing entity
 *
 *  @return The remote container id
 */
uint16_t
pldm_entity_node_get_remote_container_id(const pldm_entity_node *entity);

/** @brief Destroy entity association tree
 *
 *  @param[in] tree - opaque pointer acting as a handle to the tree
 */
void pldm_entity_association_tree_destroy(pldm_entity_association_tree *tree);

/** @brief Check if input enity node is a parent
 *
 *  @pre node must point to a valid object
 *
 *  @param[in] node - opaque pointer acting as a handle to an entity node
 *
 *  @return bool true if node is a parent, false otherwise
 */
bool pldm_entity_is_node_parent(pldm_entity_node *node);

/** @brief Get parent of entity
 *
 *  @pre node must point to a valid object
 *
 *  @param[in] node - opaque pointer acting as a handle to an entity node
 *
 *  @return pldm_entity - pldm entity
 */
pldm_entity pldm_entity_get_parent(pldm_entity_node *node);

/** @brief Check the current pldm entity is exist parent
 *
 *  @pre node must point to a valid object
 *
 *  @param[in] node - opaque pointer acting as a handle to an entity node
 *
 *  @return bool true if exist parent, false otherwise
 */
bool pldm_entity_is_exist_parent(pldm_entity_node *node);

/** @brief Convert entity association tree to PDR
 *
 *  No conversion takes place if one or both of tree or repo are NULL.
 *
 *  @param[in] tree - opaque pointer to entity association tree
 *  @param[in] repo - PDR repo where entity association records should be added
 *  @param[in] is_remote - if true, then the PDR is not from this terminus
 *  @param[in] terminus_handle - terminus handle of the terminus
 */
void pldm_entity_association_pdr_add(pldm_entity_association_tree *tree,
				     pldm_pdr *repo, bool is_remote,
				     uint16_t terminus_handle);

/** @brief Convert entity association tree to PDR, or return an error
 *
 *  No conversion takes place if one or both of tree or repo are NULL.
 *
 *  If an error is returned then the state and consistency of the PDR repository is undefined.
 *
 *  @param[in] tree - opaque pointer to entity association tree
 *  @param[in] repo - PDR repo where entity association records should be added
 *  @param[in] is_remote - if true, then the PDR is not from this terminus
 *  @param[in] terminus_handle - terminus handle of the terminus
 *
 *  @return 0 on success, -EINVAL if the arguments are invalid, -ENOMEM if an internal memory
 *  allocation fails, or -EOVERFLOW if a record handle could not be allocated
 */
int pldm_entity_association_pdr_add_check(pldm_entity_association_tree *tree,
					  pldm_pdr *repo, bool is_remote,
					  uint16_t terminus_handle);

/** @brief Add entity association pdr from node, or return an error
 *
 *  @param[in] node - opaque pointer acting as a handle to an entity node
 *  @param[in] repo - PDR repo where entity association records should be added
 *  @param[in] is_remote  - if true, then the PDR is not from this terminus
 *  @param[in] terminus_handle - terminus handle of the terminus
 *
 *  @return 0 on success, -EINVAL if the provided arguments are invalid.
 */
int pldm_entity_association_pdr_add_from_node_check(
	pldm_entity_node *node, pldm_pdr *repo, pldm_entity **entities,
	size_t num_entities, bool is_remote, uint16_t terminus_handle);

/** @brief Add entity association pdr record based on record handle
 *  earlier the records where added in a sequential way alone, with
 *  this change the entity association PDR records gets the new record
 *  handle based on the input value given.
 *
 *  @param[in] node - opaque pointer acting as a handle to an entity node
 *  @param[in] repo - PDR repo where entity association records should be added
 *  @param[in] is_remote  - if true, then the PDR is not from this terminus
 *  @param[in] terminus_handle - terminus handle of the terminus
 *  @param[in] record_handle - record handle of the PDR
 *
 *  @return 0 on succes, -EINVAL if the provided arguments are invalid.
 */
int pldm_entity_association_pdr_add_from_node_with_record_handle(
	pldm_entity_node *node, pldm_pdr *repo, pldm_entity **entities,
	size_t num_entities, bool is_remote, uint16_t terminus_handle,
	uint32_t record_handle);

/** @brief Find entity reference in tree
 *
 *  @param[in] tree - opaque pointer to entity association tree
 *  @param[in] entity - PLDM entity
 *  @param[in] node - node to the entity
 */
void pldm_find_entity_ref_in_tree(pldm_entity_association_tree *tree,
				  pldm_entity entity, pldm_entity_node **node);

/** @brief Get number of children of entity
 *
 *  @param[in] node - opaque pointer acting as a handle to an entity node
 *  @param[in] association_type - relation type filter : logical or physical
 *
 *  @return uint8_t number of children. The returned value is zero if node is NULL or
 *  	    association_type is not one of PLDM_ENTITY_ASSOCIAION_PHYSICAL or
 *  	    PLDM_ENTITY_ASSOCIAION_LOGICAL.
 */
uint8_t pldm_entity_get_num_children(pldm_entity_node *node,
				     uint8_t association_type);

/** @brief Verify that the current node is a child of the current parent
 *
 *  @pre parent must point to a valid object
 *  @pre node must point to a valid object
 *
 *  @param[in] parent    - opaque pointer acting as a handle to an entity parent
 *  @param[in] node      - pointer to the node of the pldm entity
 *
 *  @return True if the node is a child of parent, false otherwise, including if one or both of
 *  parent or node are NULL.
 */
bool pldm_is_current_parent_child(pldm_entity_node *parent, pldm_entity *node);

/** @brief Find an entity in the entity association tree
 *
 *  @param[in] tree - pointer to entity association tree
 *  @param[in/out] entity - entity type and instance id set on input, container
 *                 id set on output
 *  @return pldm_entity_node* pointer to entity if found, NULL otherwise
 *
 *  There are no entity nodes to search if tree is NULL, nor are there entity nodes to find if the
 *  search criteria are unspecified when entity is NULL.
 */
pldm_entity_node *
pldm_entity_association_tree_find(pldm_entity_association_tree *tree,
				  pldm_entity *entity);

/** @brief Find an entity in the entity association tree with locality specified,
 *         ie - remote entity or local entity
 *
 *  @param[in] tree - pointer to entity association tree
 *  @param[in/out] entity - entity type and instance id set on input, container
 *                          id set on output
 *  @param[in] is_remote - variable to denote whether we are finding a remote
 *                         entity or a local entity
 *
 *  @return pldm_entity_node* pointer to entity if found, NULL otherwise
 */
pldm_entity_node *pldm_entity_association_tree_find_with_locality(
	pldm_entity_association_tree *tree, pldm_entity *entity,
	bool is_remote);

/** @brief Create a copy of an existing entity association tree
 *
 *  @param[in] org_tree - pointer to source tree
 *  @param[in/out] new_tree - pointer to destination tree
 */
void pldm_entity_association_tree_copy_root(
	pldm_entity_association_tree *org_tree,
	pldm_entity_association_tree *new_tree);

/** @brief Destroy all the nodes of the entity association tree
 *
 *  @param[in] tree - pointer to entity association tree
 *
 *  There is no tree to destroy if tree is NULL.
 */
void pldm_entity_association_tree_destroy_root(
	pldm_entity_association_tree *tree);

/** @brief Check whether the entity association tree is empty
 *
 *  @pre tree must point to a valid object
 *
 *  @param[in] tree - pointer to entity association tree
 *  @return bool, true if tree is empty
 */
bool pldm_is_empty_entity_assoc_tree(pldm_entity_association_tree *tree);

/** @brief Extract entities from entity association PDR
 *
 *  @pre `*entities == NULL` and `*num_entities == 0` must hold at the time of invocation.
 *
 *  @param[in] pdr - entity association PDR
 *  @param[in] pdr_len - size of entity association PDR in bytes
 *  @param[out] num_entities - number of entities found, including the container
 *  @param[out] entities - extracted entities, container is *entities[0]. Caller
 *              must free *entities
 */
void pldm_entity_association_pdr_extract(const uint8_t *pdr, uint16_t pdr_len,
					 size_t *num_entities,
					 pldm_entity **entities);

#ifdef __cplusplus
}
#endif

#endif /* PDR_H */
