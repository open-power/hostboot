#include "pdr.h"
#include "platform.h"
#include <assert.h>
#include <endian.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct pldm_pdr_record {
	uint32_t record_handle;
	uint32_t size;
	uint8_t *data;
	struct pldm_pdr_record *next;
	bool is_remote;
	uint16_t terminus_handle;
} pldm_pdr_record;

typedef struct pldm_pdr {
	uint32_t record_count;
	uint32_t size;
	pldm_pdr_record *first;
	pldm_pdr_record *last;
} pldm_pdr;

static inline uint32_t get_next_record_handle(const pldm_pdr *repo,
					      const pldm_pdr_record *record)
{
	assert(repo != NULL);
	assert(record != NULL);

	if (record == repo->last) {
		return 0;
	}
	return record->next->record_handle;
}

LIBPLDM_ABI_STABLE
int pldm_pdr_add_check(pldm_pdr *repo, const uint8_t *data, uint32_t size,
		       bool is_remote, uint16_t terminus_handle,
		       uint32_t *record_handle)
{
	uint32_t curr;

	if (!repo || !data || !size) {
		return -EINVAL;
	}

	if (record_handle && *record_handle) {
		curr = *record_handle;
	} else if (repo->last) {
		curr = repo->last->record_handle;
		if (curr == UINT32_MAX) {
			return -EOVERFLOW;
		}
		curr += 1;
	} else {
		curr = 1;
	}

	pldm_pdr_record *record = malloc(sizeof(pldm_pdr_record));
	if (!record) {
		return -ENOMEM;
	}

	if (data) {
		record->data = malloc(size);
		if (!record->data) {
			free(record);
			return -ENOMEM;
		}
		memcpy(record->data, data, size);
	}

	record->size = size;
	record->is_remote = is_remote;
	record->terminus_handle = terminus_handle;
	record->record_handle = curr;

	if (record_handle && !*record_handle && data) {
		/* If record handle is 0, that is an indication for this API to
		 * compute a new handle. For that reason, the computed handle
		 * needs to be populated in the PDR header. For a case where the
		 * caller supplied the record handle, it would exist in the
		 * header already.
		 */
		struct pldm_pdr_hdr *hdr = (void *)record->data;
		hdr->record_handle = htole32(record->record_handle);
	}

	record->next = NULL;

	assert(!repo->first == !repo->last);
	if (repo->first == NULL) {
		repo->first = record;
		repo->last = record;
	} else {
		repo->last->next = record;
		repo->last = record;
	}

	repo->size += record->size;
	++repo->record_count;

	if (record_handle) {
		*record_handle = record->record_handle;
	}

	return 0;
}

LIBPLDM_ABI_STABLE
pldm_pdr *pldm_pdr_init(void)
{
	pldm_pdr *repo = malloc(sizeof(pldm_pdr));
	if (!repo) {
		return NULL;
	}
	repo->record_count = 0;
	repo->size = 0;
	repo->first = NULL;
	repo->last = NULL;

	return repo;
}

LIBPLDM_ABI_STABLE
void pldm_pdr_destroy(pldm_pdr *repo)
{
	if (!repo) {
		return;
	}

	pldm_pdr_record *record = repo->first;
	while (record != NULL) {
		pldm_pdr_record *next = record->next;
		if (record->data) {
			free(record->data);
			record->data = NULL;
		}
		free(record);
		record = next;
	}
	free(repo);
}

LIBPLDM_ABI_STABLE
const pldm_pdr_record *pldm_pdr_find_record(const pldm_pdr *repo,
					    uint32_t record_handle,
					    uint8_t **data, uint32_t *size,
					    uint32_t *next_record_handle)
{
	if (!repo || !data || !size || !next_record_handle) {
		return NULL;
	}

	if (!record_handle && (repo->first != NULL)) {
		record_handle = repo->first->record_handle;
	}

	pldm_pdr_record *record = repo->first;
	while (record != NULL) {
		if (record->record_handle == record_handle) {
			*size = record->size;
			*data = record->data;
			*next_record_handle =
				get_next_record_handle(repo, record);
			return record;
		}
		record = record->next;
	}

	*size = 0;
	*next_record_handle = 0;
	return NULL;
}

LIBPLDM_ABI_STABLE
const pldm_pdr_record *
pldm_pdr_get_next_record(const pldm_pdr *repo,
			 const pldm_pdr_record *curr_record, uint8_t **data,
			 uint32_t *size, uint32_t *next_record_handle)
{
	if (!repo || !curr_record || !data || !size || !next_record_handle) {
		return NULL;
	}

	if (curr_record == repo->last) {
		*data = NULL;
		*size = 0;
		*next_record_handle = get_next_record_handle(repo, curr_record);
		return NULL;
	}

	*next_record_handle = get_next_record_handle(repo, curr_record->next);
	*data = curr_record->next->data;
	*size = curr_record->next->size;
	return curr_record->next;
}

LIBPLDM_ABI_STABLE
const pldm_pdr_record *
pldm_pdr_find_record_by_type(const pldm_pdr *repo, uint8_t pdr_type,
			     const pldm_pdr_record *curr_record, uint8_t **data,
			     uint32_t *size)
{
	if (!repo) {
		return NULL;
	}

	pldm_pdr_record *record = repo->first;
	if (curr_record != NULL) {
		record = curr_record->next;
	}
	while (record != NULL) {
		struct pldm_pdr_hdr *hdr = (struct pldm_pdr_hdr *)record->data;
		if (hdr->type == pdr_type) {
			if (data && size) {
				*size = record->size;
				*data = record->data;
			}
			return record;
		}
		record = record->next;
	}

	if (size) {
		*size = 0;
	}
	return NULL;
}

LIBPLDM_ABI_STABLE
uint32_t pldm_pdr_get_record_count(const pldm_pdr *repo)
{
	assert(repo != NULL);

	return repo->record_count;
}

LIBPLDM_ABI_STABLE
uint32_t pldm_pdr_get_repo_size(const pldm_pdr *repo)
{
	assert(repo != NULL);

	return repo->size;
}

LIBPLDM_ABI_STABLE
uint32_t pldm_pdr_get_record_handle(const pldm_pdr *repo
				    __attribute__((unused)),
				    const pldm_pdr_record *record)
{
	assert(repo != NULL);
	assert(record != NULL);

	return record->record_handle;
}

LIBPLDM_ABI_STABLE
bool pldm_pdr_record_is_remote(const pldm_pdr_record *record)
{
	assert(record != NULL);

	return record->is_remote;
}

LIBPLDM_ABI_STABLE
int pldm_pdr_add_fru_record_set_check(pldm_pdr *repo, uint16_t terminus_handle,
				      uint16_t fru_rsi, uint16_t entity_type,
				      uint16_t entity_instance_num,
				      uint16_t container_id,
				      uint32_t *bmc_record_handle)
{
	if (!repo || !bmc_record_handle) {
		return -EINVAL;
	}

	uint32_t size = sizeof(struct pldm_pdr_hdr) +
			sizeof(struct pldm_pdr_fru_record_set);
	uint8_t data[size];

	struct pldm_pdr_hdr *hdr = (struct pldm_pdr_hdr *)&data;
	hdr->version = 1;
	hdr->record_handle = *bmc_record_handle;
	hdr->type = PLDM_PDR_FRU_RECORD_SET;
	hdr->record_change_num = 0;
	hdr->length = htole16(sizeof(struct pldm_pdr_fru_record_set));
	struct pldm_pdr_fru_record_set *fru =
		(struct pldm_pdr_fru_record_set *)((uint8_t *)hdr +
						   sizeof(struct pldm_pdr_hdr));
	fru->terminus_handle = htole16(terminus_handle);
	fru->fru_rsi = htole16(fru_rsi);
	fru->entity_type = htole16(entity_type);
	fru->entity_instance_num = htole16(entity_instance_num);
	fru->container_id = htole16(container_id);

	return pldm_pdr_add_check(repo, data, size, false, terminus_handle,
				  bmc_record_handle);
}

LIBPLDM_ABI_STABLE
const pldm_pdr_record *pldm_pdr_fru_record_set_find_by_rsi(
	const pldm_pdr *repo, uint16_t fru_rsi, uint16_t *terminus_handle,
	uint16_t *entity_type, uint16_t *entity_instance_num,
	uint16_t *container_id)
{
	if (!repo || !terminus_handle || !entity_type || !entity_instance_num ||
	    !container_id) {
		return NULL;
	}

	uint8_t *data = NULL;
	uint32_t size = 0;
	const pldm_pdr_record *curr_record = pldm_pdr_find_record_by_type(
		repo, PLDM_PDR_FRU_RECORD_SET, NULL, &data, &size);
	while (curr_record != NULL) {
		struct pldm_pdr_fru_record_set *fru =
			(struct pldm_pdr_fru_record_set
				 *)(data + sizeof(struct pldm_pdr_hdr));
		if (fru->fru_rsi == htole16(fru_rsi)) {
			*terminus_handle = le16toh(fru->terminus_handle);
			*entity_type = le16toh(fru->entity_type);
			*entity_instance_num =
				le16toh(fru->entity_instance_num);
			*container_id = le16toh(fru->container_id);
			return curr_record;
		}
		data = NULL;
		curr_record = pldm_pdr_find_record_by_type(
			repo, PLDM_PDR_FRU_RECORD_SET, curr_record, &data,
			&size);
	}

	*terminus_handle = 0;
	*entity_type = 0;
	*entity_instance_num = 0;
	*container_id = 0;

	return NULL;
}

LIBPLDM_ABI_STABLE
/* NOLINTNEXTLINE(readability-identifier-naming) */
void pldm_pdr_update_TL_pdr(const pldm_pdr *repo, uint16_t terminus_handle,
			    uint8_t tid, uint8_t tl_eid, bool valid_bit)
{
	uint8_t *out_data = NULL;
	uint32_t size = 0;
	const pldm_pdr_record *record;
	record = pldm_pdr_find_record_by_type(repo, PLDM_TERMINUS_LOCATOR_PDR,
					      NULL, &out_data, &size);

	do {
		if (record != NULL) {
			struct pldm_terminus_locator_pdr *pdr =
				(struct pldm_terminus_locator_pdr *)out_data;
			struct pldm_terminus_locator_type_mctp_eid *value =
				(struct pldm_terminus_locator_type_mctp_eid *)
					pdr->terminus_locator_value;
			if (pdr->terminus_handle == terminus_handle &&
			    pdr->tid == tid && value->eid == tl_eid) {
				pdr->validity = valid_bit;
				break;
			}
		}
		record = pldm_pdr_find_record_by_type(repo,
						      PLDM_TERMINUS_LOCATOR_PDR,
						      record, &out_data, &size);
	} while (record);
}

static bool pldm_record_handle_in_range(uint32_t record_handle,
					uint32_t first_record_handle,
					uint32_t last_record_handle)
{
	return record_handle >= first_record_handle &&
	       record_handle <= last_record_handle;
}

LIBPLDM_ABI_TESTING
int pldm_pdr_find_child_container_id_index_range_exclude(
	const pldm_pdr *repo, uint16_t entity_type, uint16_t entity_instance,
	uint8_t child_index, uint32_t range_exclude_start_handle,
	uint32_t range_exclude_end_handle, uint16_t *container_id)
{
	pldm_pdr_record *record;
	if (!repo) {
		return -EINVAL;
	}

	for (record = repo->first; record; record = record->next) {
		bool is_container_entity_instance_number;
		struct pldm_pdr_entity_association *pdr;
		bool is_container_entity_type;
		struct pldm_entity *child;
		struct pldm_pdr_hdr *hdr;
		bool in_range;

		// pldm_pdr_add() takes only uint8_t* data as an argument.
		// The expectation here is the pldm_pdr_hdr is the first field of the record data
		hdr = (struct pldm_pdr_hdr *)record->data;
		if (hdr->type != PLDM_PDR_ENTITY_ASSOCIATION) {
			continue;
		}
		in_range = pldm_record_handle_in_range(
			record->record_handle, range_exclude_start_handle,
			range_exclude_end_handle);
		if (in_range) {
			continue;
		}

		// this cast is valid with respect to alignment because
		// struct pldm_pdr_hdr is declared with __attribute__((packed))
		pdr = (void *)(record->data + sizeof(struct pldm_pdr_hdr));
		if (child_index >= pdr->num_children) {
			continue;
		}

		child = (&pdr->children[child_index]);
		is_container_entity_type = pdr->container.entity_type ==
					   entity_type;
		is_container_entity_instance_number =
			pdr->container.entity_instance_num == entity_instance;
		if (is_container_entity_type &&
		    is_container_entity_instance_number) {
			*container_id = le16toh(child->entity_container_id);
			return 0;
		}
	}
	return -ENOKEY;
}

typedef struct pldm_entity_association_tree {
	pldm_entity_node *root;
	uint16_t last_used_container_id;
} pldm_entity_association_tree;

typedef struct pldm_entity_node {
	pldm_entity entity;
	pldm_entity parent;
	uint16_t remote_container_id;
	pldm_entity_node *first_child;
	pldm_entity_node *next_sibling;
	uint8_t association_type;
} pldm_entity_node;

static inline uint16_t next_container_id(pldm_entity_association_tree *tree)
{
	assert(tree != NULL);
	assert(tree->last_used_container_id != UINT16_MAX);

	return ++tree->last_used_container_id;
}

LIBPLDM_ABI_STABLE
pldm_entity pldm_entity_extract(pldm_entity_node *node)
{
	assert(node != NULL);

	return node->entity;
}

LIBPLDM_ABI_TESTING
uint16_t
pldm_entity_node_get_remote_container_id(const pldm_entity_node *entity)
{
	assert(entity != NULL);

	return entity->remote_container_id;
}

LIBPLDM_ABI_STABLE
pldm_entity_association_tree *pldm_entity_association_tree_init(void)
{
	pldm_entity_association_tree *tree =
		malloc(sizeof(pldm_entity_association_tree));
	if (!tree) {
		return NULL;
	}
	tree->root = NULL;
	tree->last_used_container_id = 0;

	return tree;
}

static pldm_entity_node *find_insertion_at(pldm_entity_node *start,
					   uint16_t entity_type)
{
	assert(start != NULL);

	/* Insert after the the last node that matches the input entity type, or
	 * at the end if no such match occurrs
	 */
	while (start->next_sibling != NULL) {
		uint16_t this_type = start->entity.entity_type;
		pldm_entity_node *next = start->next_sibling;
		if (this_type == entity_type &&
		    (this_type != next->entity.entity_type)) {
			break;
		}
		start = start->next_sibling;
	}

	return start;
}

LIBPLDM_ABI_STABLE
pldm_entity_node *pldm_entity_association_tree_add(
	pldm_entity_association_tree *tree, pldm_entity *entity,
	uint16_t entity_instance_number, pldm_entity_node *parent,
	uint8_t association_type)
{
	return pldm_entity_association_tree_add_entity(tree, entity,
						       entity_instance_number,
						       parent, association_type,
						       false, true, 0xFFFF);
}

LIBPLDM_ABI_TESTING
pldm_entity_node *pldm_entity_association_tree_add_entity(
	pldm_entity_association_tree *tree, pldm_entity *entity,
	uint16_t entity_instance_number, pldm_entity_node *parent,
	uint8_t association_type, bool is_remote, bool is_update_container_id,
	uint16_t container_id)
{
	if ((!tree) || (!entity)) {
		return NULL;
	}

	if (entity_instance_number != 0xFFFF && parent != NULL) {
		pldm_entity node;
		node.entity_type = entity->entity_type;
		node.entity_instance_num = entity_instance_number;
		if (pldm_is_current_parent_child(parent, &node)) {
			return NULL;
		}
	}
	if (association_type != PLDM_ENTITY_ASSOCIAION_PHYSICAL &&
	    association_type != PLDM_ENTITY_ASSOCIAION_LOGICAL) {
		return NULL;
	}
	pldm_entity_node *node = malloc(sizeof(pldm_entity_node));
	if (!node) {
		return NULL;
	}
	node->first_child = NULL;
	node->next_sibling = NULL;
	node->parent.entity_type = 0;
	node->parent.entity_instance_num = 0;
	node->parent.entity_container_id = 0;
	node->entity.entity_type = entity->entity_type;
	node->entity.entity_instance_num =
		entity_instance_number != 0xFFFF ? entity_instance_number : 1;
	node->association_type = association_type;
	node->remote_container_id = 0;
	if (tree->root == NULL) {
		if (parent != NULL) {
			free(node);
			return NULL;
		}
		tree->root = node;
		/* container_id 0 here indicates this is the top-most entry */
		node->entity.entity_container_id = 0;
		node->remote_container_id = node->entity.entity_container_id;
	} else if (parent != NULL && parent->first_child == NULL) {
		parent->first_child = node;
		node->parent = parent->entity;

		if (is_remote) {
			node->remote_container_id = entity->entity_container_id;
		}
		if (is_update_container_id) {
			if (container_id != 0xFFFF) {
				node->entity.entity_container_id = container_id;
			} else {
				node->entity.entity_container_id =
					next_container_id(tree);
			}
		} else {
			node->entity.entity_container_id =
				entity->entity_container_id;
		}

		if (!is_remote) {
			node->remote_container_id =
				node->entity.entity_container_id;
		}
	} else {
		pldm_entity_node *start = parent == NULL ? tree->root :
							   parent->first_child;
		pldm_entity_node *prev =
			find_insertion_at(start, entity->entity_type);
		if (!prev) {
			free(node);
			return NULL;
		}
		pldm_entity_node *next = prev->next_sibling;
		if (prev->entity.entity_type == entity->entity_type) {
			if (prev->entity.entity_instance_num == UINT16_MAX) {
				free(node);
				return NULL;
			}
			node->entity.entity_instance_num =
				entity_instance_number != 0xFFFF ?
					entity_instance_number :
					prev->entity.entity_instance_num + 1;
		}
		prev->next_sibling = node;
		node->parent = prev->parent;
		node->next_sibling = next;
		node->entity.entity_container_id =
			prev->entity.entity_container_id;
		node->remote_container_id = entity->entity_container_id;
	}
	entity->entity_instance_num = node->entity.entity_instance_num;
	if (is_update_container_id) {
		entity->entity_container_id = node->entity.entity_container_id;
	}
	return node;
}

static void get_num_nodes(pldm_entity_node *node, size_t *num)
{
	if (node == NULL) {
		return;
	}

	++(*num);
	get_num_nodes(node->next_sibling, num);
	get_num_nodes(node->first_child, num);
}

static void entity_association_tree_visit(pldm_entity_node *node,
					  pldm_entity *entities, size_t *index)
{
	if (node == NULL) {
		return;
	}

	pldm_entity *entity = &entities[*index];
	++(*index);
	entity->entity_type = node->entity.entity_type;
	entity->entity_instance_num = node->entity.entity_instance_num;
	entity->entity_container_id = node->entity.entity_container_id;

	entity_association_tree_visit(node->next_sibling, entities, index);
	entity_association_tree_visit(node->first_child, entities, index);
}

LIBPLDM_ABI_STABLE
void pldm_entity_association_tree_visit(pldm_entity_association_tree *tree,
					pldm_entity **entities, size_t *size)
{
	if (!tree || !entities || !size) {
		return;
	}

	*size = 0;
	if (tree->root == NULL) {
		return;
	}

	get_num_nodes(tree->root, size);
	*entities = malloc(*size * sizeof(pldm_entity));
	if (!entities) {
		return;
	}
	size_t index = 0;
	entity_association_tree_visit(tree->root, *entities, &index);
}

static void entity_association_tree_destroy(pldm_entity_node *node)
{
	if (node == NULL) {
		return;
	}

	entity_association_tree_destroy(node->next_sibling);
	entity_association_tree_destroy(node->first_child);
	free(node);
}

LIBPLDM_ABI_STABLE
void pldm_entity_association_tree_destroy(pldm_entity_association_tree *tree)
{
	if (!tree) {
		return;
	}

	entity_association_tree_destroy(tree->root);
	free(tree);
}

LIBPLDM_ABI_STABLE
bool pldm_entity_is_node_parent(pldm_entity_node *node)
{
	assert(node != NULL);

	return node->first_child != NULL;
}

LIBPLDM_ABI_STABLE
pldm_entity pldm_entity_get_parent(pldm_entity_node *node)
{
	assert(node != NULL);

	return node->parent;
}

LIBPLDM_ABI_STABLE
bool pldm_entity_is_exist_parent(pldm_entity_node *node)
{
	assert(node != NULL);

	if (node->parent.entity_type == 0 &&
	    node->parent.entity_instance_num == 0 &&
	    node->parent.entity_container_id == 0) {
		return false;
	}

	return true;
}

LIBPLDM_ABI_STABLE
uint8_t pldm_entity_get_num_children(pldm_entity_node *node,
				     uint8_t association_type)
{
	if (!node) {
		return 0;
	}

	if (!(association_type == PLDM_ENTITY_ASSOCIAION_PHYSICAL ||
	      association_type == PLDM_ENTITY_ASSOCIAION_LOGICAL)) {
		return 0;
	}

	size_t count = 0;
	pldm_entity_node *curr = node->first_child;
	while (curr != NULL) {
		if (curr->association_type == association_type) {
			++count;
		}
		curr = curr->next_sibling;
	}

	assert(count < UINT8_MAX);
	return count < UINT8_MAX ? count : 0;
}

LIBPLDM_ABI_STABLE
bool pldm_is_current_parent_child(pldm_entity_node *parent, pldm_entity *node)
{
	if (!parent || !node) {
		return false;
	}

	pldm_entity_node *curr = parent->first_child;
	while (curr != NULL) {
		if (node->entity_type == curr->entity.entity_type &&
		    node->entity_instance_num ==
			    curr->entity.entity_instance_num) {
			return true;
		}
		curr = curr->next_sibling;
	}

	return false;
}

static int entity_association_pdr_add_children(
	pldm_entity_node *curr, pldm_pdr *repo, uint16_t size,
	uint8_t contained_count, uint8_t association_type, bool is_remote,
	uint16_t terminus_handle, uint32_t record_handle)
{
	uint8_t pdr[size];
	uint8_t *start = pdr;

	struct pldm_pdr_hdr *hdr = (struct pldm_pdr_hdr *)start;
	hdr->version = 1;
	hdr->record_handle = 0;
	hdr->type = PLDM_PDR_ENTITY_ASSOCIATION;
	hdr->record_change_num = 0;
	hdr->length = htole16(size - sizeof(struct pldm_pdr_hdr));
	start += sizeof(struct pldm_pdr_hdr);

	uint16_t *container_id = (uint16_t *)start;
	*container_id = htole16(curr->first_child->entity.entity_container_id);
	start += sizeof(uint16_t);
	*start = association_type;
	start += sizeof(uint8_t);

	pldm_entity *entity = (pldm_entity *)start;
	entity->entity_type = htole16(curr->entity.entity_type);
	entity->entity_instance_num = htole16(curr->entity.entity_instance_num);
	entity->entity_container_id = htole16(curr->entity.entity_container_id);
	start += sizeof(pldm_entity);

	*start = contained_count;
	start += sizeof(uint8_t);

	pldm_entity_node *node = curr->first_child;
	while (node != NULL) {
		if (node->association_type == association_type) {
			pldm_entity *entity = (pldm_entity *)start;
			entity->entity_type = htole16(node->entity.entity_type);
			entity->entity_instance_num =
				htole16(node->entity.entity_instance_num);
			entity->entity_container_id =
				htole16(node->entity.entity_container_id);
			start += sizeof(pldm_entity);
		}
		node = node->next_sibling;
	}

	return pldm_pdr_add_check(repo, pdr, size, is_remote, terminus_handle,
				  &record_handle);
}

static int entity_association_pdr_add_entry(pldm_entity_node *curr,
					    pldm_pdr *repo, bool is_remote,
					    uint16_t terminus_handle,
					    uint32_t record_handle)
{
	uint8_t num_logical_children = pldm_entity_get_num_children(
		curr, PLDM_ENTITY_ASSOCIAION_LOGICAL);
	uint8_t num_physical_children = pldm_entity_get_num_children(
		curr, PLDM_ENTITY_ASSOCIAION_PHYSICAL);
	int rc;

	if (num_logical_children) {
		uint16_t logical_pdr_size =
			sizeof(struct pldm_pdr_hdr) + sizeof(uint16_t) +
			sizeof(uint8_t) + sizeof(pldm_entity) +
			sizeof(uint8_t) +
			(num_logical_children * sizeof(pldm_entity));
		rc = entity_association_pdr_add_children(
			curr, repo, logical_pdr_size, num_logical_children,
			PLDM_ENTITY_ASSOCIAION_LOGICAL, is_remote,
			terminus_handle, record_handle);
		if (rc < 0) {
			return rc;
		}
	}

	if (num_physical_children) {
		uint16_t physical_pdr_size =
			sizeof(struct pldm_pdr_hdr) + sizeof(uint16_t) +
			sizeof(uint8_t) + sizeof(pldm_entity) +
			sizeof(uint8_t) +
			(num_physical_children * sizeof(pldm_entity));
		rc = entity_association_pdr_add_children(
			curr, repo, physical_pdr_size, num_physical_children,
			PLDM_ENTITY_ASSOCIAION_PHYSICAL, is_remote,
			terminus_handle, record_handle);
		if (rc < 0) {
			return rc;
		}
	}

	return 0;
}

static bool is_present(pldm_entity entity, pldm_entity **entities,
		       size_t num_entities)
{
	if (entities == NULL || num_entities == 0) {
		return true;
	}
	size_t i = 0;
	while (i < num_entities) {
		if ((*entities + i)->entity_type == entity.entity_type) {
			return true;
		}
		i++;
	}
	return false;
}

static int entity_association_pdr_add(pldm_entity_node *curr, pldm_pdr *repo,
				      pldm_entity **entities,
				      size_t num_entities, bool is_remote,
				      uint16_t terminus_handle,
				      uint32_t record_handle)
{
	int rc;

	if (curr == NULL) {
		return 0;
	}

	if (is_present(curr->entity, entities, num_entities)) {
		rc = entity_association_pdr_add_entry(
			curr, repo, is_remote, terminus_handle, record_handle);
		if (rc) {
			return rc;
		}
	}

	rc = entity_association_pdr_add(curr->next_sibling, repo, entities,
					num_entities, is_remote,
					terminus_handle, record_handle);
	if (rc) {
		return rc;
	}

	return entity_association_pdr_add(curr->first_child, repo, entities,
					  num_entities, is_remote,
					  terminus_handle, record_handle);
}

LIBPLDM_ABI_DEPRECATED
void pldm_entity_association_pdr_add(pldm_entity_association_tree *tree,
				     pldm_pdr *repo, bool is_remote,
				     uint16_t terminus_handle)
{
	int rc = pldm_entity_association_pdr_add_check(tree, repo, is_remote,
						       terminus_handle);
	(void)rc;
	assert(!rc);
}

LIBPLDM_ABI_STABLE
int pldm_entity_association_pdr_add_check(pldm_entity_association_tree *tree,
					  pldm_pdr *repo, bool is_remote,
					  uint16_t terminus_handle)
{
	if (!tree || !repo) {
		return 0;
	}

	return entity_association_pdr_add(tree->root, repo, NULL, 0, is_remote,
					  terminus_handle, 0);
}

LIBPLDM_ABI_STABLE
int pldm_entity_association_pdr_add_from_node_check(
	pldm_entity_node *node, pldm_pdr *repo, pldm_entity **entities,
	size_t num_entities, bool is_remote, uint16_t terminus_handle)
{
	return pldm_entity_association_pdr_add_from_node_with_record_handle(
		node, repo, entities, num_entities, is_remote, terminus_handle,
		0);
}

LIBPLDM_ABI_TESTING
int pldm_entity_association_pdr_add_from_node_with_record_handle(
	pldm_entity_node *node, pldm_pdr *repo, pldm_entity **entities,
	size_t num_entities, bool is_remote, uint16_t terminus_handle,
	uint32_t record_handle)
{
	if (!node || !repo || !entities) {
		return -EINVAL;
	}

	entity_association_pdr_add(node, repo, entities, num_entities,
				   is_remote, terminus_handle, record_handle);

	return 0;
}

static void find_entity_ref_in_tree(pldm_entity_node *tree_node,
				    pldm_entity entity, pldm_entity_node **node)
{
	bool is_entity_container_id;
	bool is_entity_instance_num;
	bool is_type;

	if (tree_node == NULL) {
		return;
	}

	is_type = tree_node->entity.entity_type == entity.entity_type;
	is_entity_instance_num = tree_node->entity.entity_instance_num ==
				 entity.entity_instance_num;
	is_entity_container_id = tree_node->entity.entity_container_id ==
				 entity.entity_container_id;

	if (is_type && is_entity_instance_num && is_entity_container_id) {
		*node = tree_node;
		return;
	}

	find_entity_ref_in_tree(tree_node->first_child, entity, node);
	find_entity_ref_in_tree(tree_node->next_sibling, entity, node);
}

LIBPLDM_ABI_STABLE
void pldm_find_entity_ref_in_tree(pldm_entity_association_tree *tree,
				  pldm_entity entity, pldm_entity_node **node)
{
	if (!tree || !node) {
		return;
	}

	find_entity_ref_in_tree(tree->root, entity, node);
}

LIBPLDM_ABI_STABLE
void pldm_pdr_remove_pdrs_by_terminus_handle(pldm_pdr *repo,
					     uint16_t terminus_handle)
{
	if (!repo) {
		return;
	}

	bool removed = false;

	pldm_pdr_record *record = repo->first;
	pldm_pdr_record *prev = NULL;
	while (record != NULL) {
		pldm_pdr_record *next = record->next;
		if (record->terminus_handle == terminus_handle) {
			if (repo->first == record) {
				repo->first = next;
			} else {
				prev->next = next;
			}
			if (repo->last == record) {
				repo->last = prev;
			}
			if (record->data) {
				free(record->data);
			}
			--repo->record_count;
			repo->size -= record->size;
			free(record);
			removed = true;
		} else {
			prev = record;
		}
		record = next;
	}

	if (removed == true) {
		record = repo->first;
		uint32_t record_handle = 0;
		while (record != NULL) {
			record->record_handle = ++record_handle;
			if (record->data != NULL) {
				struct pldm_pdr_hdr *hdr =
					(struct pldm_pdr_hdr *)(record->data);
				hdr->record_handle =
					htole32(record->record_handle);
			}
			record = record->next;
		}
	}
}

LIBPLDM_ABI_STABLE
void pldm_pdr_remove_remote_pdrs(pldm_pdr *repo)
{
	if (!repo) {
		return;
	}

	bool removed = false;

	pldm_pdr_record *record = repo->first;
	pldm_pdr_record *prev = NULL;
	while (record != NULL) {
		pldm_pdr_record *next = record->next;
		if (record->is_remote == true) {
			if (repo->first == record) {
				repo->first = next;
			} else {
				prev->next = next;
			}
			if (repo->last == record) {
				repo->last = prev;
			}
			if (record->data) {
				free(record->data);
			}
			--repo->record_count;
			repo->size -= record->size;
			free(record);
			removed = true;
		} else {
			prev = record;
		}
		record = next;
	}

	if (removed == true) {
		record = repo->first;
		uint32_t record_handle = 0;
		while (record != NULL) {
			record->record_handle = ++record_handle;
			if (record->data != NULL) {
				struct pldm_pdr_hdr *hdr =
					(struct pldm_pdr_hdr *)(record->data);
				hdr->record_handle =
					htole32(record->record_handle);
			}
			record = record->next;
		}
	}
}

LIBPLDM_ABI_TESTING
pldm_pdr_record *pldm_pdr_find_last_in_range(const pldm_pdr *repo,
					     uint32_t first, uint32_t last)
{
	pldm_pdr_record *record = NULL;
	pldm_pdr_record *curr;

	if (!repo) {
		return NULL;
	}
	for (curr = repo->first; curr; curr = curr->next) {
		if (first > curr->record_handle || last < curr->record_handle) {
			continue;
		}
		if (!record || curr->record_handle > record->record_handle) {
			record = curr;
		}
	}

	return record;
}

static void entity_association_tree_find_if_remote(pldm_entity_node *node,
						   pldm_entity *entity,
						   pldm_entity_node **out,
						   bool is_remote)
{
	if (node == NULL) {
		return;
	}
	bool is_entity_type;
	bool is_entity_instance_num;

	is_entity_type = node->entity.entity_type == entity->entity_type;
	is_entity_instance_num = node->entity.entity_instance_num ==
				 entity->entity_instance_num;

	if (!is_remote ||
	    node->remote_container_id == entity->entity_container_id) {
		if (is_entity_type && is_entity_instance_num) {
			entity->entity_container_id =
				node->entity.entity_container_id;
			*out = node;
			return;
		}
	}
	entity_association_tree_find_if_remote(node->next_sibling, entity, out,
					       is_remote);
	entity_association_tree_find_if_remote(node->first_child, entity, out,
					       is_remote);
}

LIBPLDM_ABI_STABLE
pldm_entity_node *pldm_entity_association_tree_find_with_locality(
	pldm_entity_association_tree *tree, pldm_entity *entity, bool is_remote)
{
	if (!tree || !entity) {
		return NULL;
	}
	pldm_entity_node *node = NULL;
	entity_association_tree_find_if_remote(tree->root, entity, &node,
					       is_remote);
	return node;
}

static void entity_association_tree_find(pldm_entity_node *node,
					 pldm_entity *entity,
					 pldm_entity_node **out)
{
	if (node == NULL) {
		return;
	}

	if (node->entity.entity_type == entity->entity_type &&
	    node->entity.entity_instance_num == entity->entity_instance_num) {
		entity->entity_container_id = node->entity.entity_container_id;
		*out = node;
		return;
	}
	entity_association_tree_find(node->next_sibling, entity, out);
	entity_association_tree_find(node->first_child, entity, out);
}

LIBPLDM_ABI_STABLE
pldm_entity_node *
pldm_entity_association_tree_find(pldm_entity_association_tree *tree,
				  pldm_entity *entity)
{
	if (!tree || !entity) {
		return NULL;
	}

	pldm_entity_node *node = NULL;
	entity_association_tree_find(tree->root, entity, &node);
	return node;
}

static void entity_association_tree_copy(pldm_entity_node *org_node,
					 pldm_entity_node **new_node)
{
	if (org_node == NULL) {
		return;
	}
	*new_node = malloc(sizeof(pldm_entity_node));
	(*new_node)->parent = org_node->parent;
	(*new_node)->entity = org_node->entity;
	(*new_node)->association_type = org_node->association_type;
	(*new_node)->remote_container_id = org_node->remote_container_id;
	(*new_node)->first_child = NULL;
	(*new_node)->next_sibling = NULL;
	entity_association_tree_copy(org_node->first_child,
				     &((*new_node)->first_child));
	entity_association_tree_copy(org_node->next_sibling,
				     &((*new_node)->next_sibling));
}

LIBPLDM_ABI_STABLE
void pldm_entity_association_tree_copy_root(
	pldm_entity_association_tree *org_tree,
	pldm_entity_association_tree *new_tree)
{
	new_tree->last_used_container_id = org_tree->last_used_container_id;
	entity_association_tree_copy(org_tree->root, &(new_tree->root));
}

LIBPLDM_ABI_STABLE
void pldm_entity_association_tree_destroy_root(
	pldm_entity_association_tree *tree)
{
	if (!tree) {
		return;
	}

	entity_association_tree_destroy(tree->root);
	tree->last_used_container_id = 0;
	tree->root = NULL;
}

LIBPLDM_ABI_STABLE
bool pldm_is_empty_entity_assoc_tree(pldm_entity_association_tree *tree)
{
	return ((tree->root == NULL) ? true : false);
}

LIBPLDM_ABI_STABLE
void pldm_entity_association_pdr_extract(const uint8_t *pdr, uint16_t pdr_len,
					 size_t *num_entities,
					 pldm_entity **entities)
{
	if (!pdr || !num_entities || !entities) {
		return;
	}
#define PDR_MIN_SIZE                                                           \
	(sizeof(struct pldm_pdr_hdr) +                                         \
	 sizeof(struct pldm_pdr_entity_association))
	if (pdr_len < PDR_MIN_SIZE) {
		return;
	}
#undef PDR_MIN_SIZE

	struct pldm_pdr_hdr *hdr = (struct pldm_pdr_hdr *)pdr;
	if (hdr->type != PLDM_PDR_ENTITY_ASSOCIATION) {
		return;
	}

	const uint8_t *start = (uint8_t *)pdr;
	const uint8_t *end __attribute__((unused)) =
		start + sizeof(struct pldm_pdr_hdr) + le16toh(hdr->length);
	start += sizeof(struct pldm_pdr_hdr);
	struct pldm_pdr_entity_association *entity_association_pdr =
		(struct pldm_pdr_entity_association *)start;
	size_t l_num_entities = entity_association_pdr->num_children + 1;
	if (l_num_entities < 2) {
		return;
	}
	if (start + sizeof(struct pldm_pdr_entity_association) +
		    sizeof(pldm_entity) * (l_num_entities - 2) !=
	    end) {
		return;
	}
	pldm_entity *l_entities = malloc(sizeof(pldm_entity) * l_num_entities);
	if (!l_entities) {
		return;
	}
	l_entities[0].entity_type =
		le16toh(entity_association_pdr->container.entity_type);
	l_entities[0].entity_instance_num =
		le16toh(entity_association_pdr->container.entity_instance_num);
	l_entities[0].entity_container_id =
		le16toh(entity_association_pdr->container.entity_container_id);
	pldm_entity *curr_entity = entity_association_pdr->children;
	for (size_t i = 1; i < l_num_entities; i++, curr_entity++) {
		l_entities[i].entity_type = le16toh(curr_entity->entity_type);
		l_entities[i].entity_instance_num =
			le16toh(curr_entity->entity_instance_num);
		l_entities[i].entity_container_id =
			le16toh(curr_entity->entity_container_id);
	}

	*num_entities = l_num_entities;
	*entities = l_entities;
}
