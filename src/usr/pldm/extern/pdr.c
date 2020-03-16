/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extern/pdr.c $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include "pdr.h"
#include "platform.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct pldm_pdr_record {
	uint32_t record_handle;
	uint32_t size;
	uint8_t *data;
	struct pldm_pdr_record *next;
} pldm_pdr_record;

typedef struct pldm_pdr {
	uint32_t record_count;
	uint32_t size;
	uint32_t last_used_record_handle;
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

static void add_record(pldm_pdr *repo, pldm_pdr_record *record)
{
	assert(repo != NULL);
	assert(record != NULL);

	if (repo->first == NULL) {
		assert(repo->last == NULL);
		repo->first = record;
		repo->last = record;
	} else {
		repo->last->next = record;
		repo->last = record;
	}
	repo->size += record->size;
	repo->last_used_record_handle = record->record_handle;
	++repo->record_count;
}

static inline uint32_t get_new_record_handle(const pldm_pdr *repo)
{
	assert(repo != NULL);
	assert(repo->last_used_record_handle != UINT32_MAX);

	return repo->last_used_record_handle + 1;
}

static pldm_pdr_record *make_new_record(const pldm_pdr *repo,
					const uint8_t *data, uint32_t size,
					uint32_t record_handle)
{
	assert(repo != NULL);
	assert(size != 0);

	pldm_pdr_record *record = malloc(sizeof(pldm_pdr_record));
	assert(record != NULL);
	record->record_handle =
	    record_handle == 0 ? get_new_record_handle(repo) : record_handle;
	record->size = size;
	if (data != NULL) {
		record->data = malloc(size);
		assert(record->data != NULL);
		memcpy(record->data, data, size);
		/* If record handle is 0, that is an indication for this API to
		 * compute a new handle. For that reason, the computed handle
		 * needs to be populated in the PDR header. For a case where the
		 * caller supplied the record handle, it would exist in the
		 * header already.
		 */
		if (!record_handle) {
			struct pldm_pdr_hdr *hdr =
			    (struct pldm_pdr_hdr *)(record->data);
			hdr->record_handle = record->record_handle;
		}
	}
	record->next = NULL;

	return record;
}

uint32_t pldm_pdr_add(pldm_pdr *repo, const uint8_t *data, uint32_t size,
		      uint32_t record_handle)
{
	assert(size != 0);
	assert(data != NULL);

	pldm_pdr_record *record =
	    make_new_record(repo, data, size, record_handle);
	add_record(repo, record);

	return record->record_handle;
}

pldm_pdr *pldm_pdr_init()
{
	pldm_pdr *repo = malloc(sizeof(pldm_pdr));
	assert(repo != NULL);
	repo->record_count = 0;
	repo->size = 0;
	repo->last_used_record_handle = 0;
	repo->first = NULL;
	repo->last = NULL;

	return repo;
}

void pldm_pdr_destroy(pldm_pdr *repo)
{
	assert(repo != NULL);

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

const pldm_pdr_record *pldm_pdr_find_record(const pldm_pdr *repo,
					    uint32_t record_handle,
					    uint8_t **data, uint32_t *size,
					    uint32_t *next_record_handle)
{
	assert(repo != NULL);
	assert(data != NULL);
	assert(size != NULL);
	assert(next_record_handle != NULL);

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

const pldm_pdr_record *
pldm_pdr_get_next_record(const pldm_pdr *repo,
			 const pldm_pdr_record *curr_record, uint8_t **data,
			 uint32_t *size, uint32_t *next_record_handle)
{
	assert(repo != NULL);
	assert(curr_record != NULL);
	assert(data != NULL);
	assert(size != NULL);
	assert(next_record_handle != NULL);

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

const pldm_pdr_record *
pldm_pdr_find_record_by_type(const pldm_pdr *repo, uint8_t pdr_type,
			     const pldm_pdr_record *curr_record, uint8_t **data,
			     uint32_t *size)
{
	assert(repo != NULL);
	assert(data != NULL);
	assert(size != NULL);

	pldm_pdr_record *record = repo->first;
	if (curr_record != NULL) {
		record = curr_record->next;
	}
	while (record != NULL) {
		struct pldm_pdr_hdr *hdr = (struct pldm_pdr_hdr *)record->data;
		if (hdr->type == pdr_type) {
			*size = record->size;
			*data = record->data;
			return record;
		}
		record = record->next;
	}

	*size = 0;
	return NULL;
}

uint32_t pldm_pdr_get_record_count(const pldm_pdr *repo)
{
	assert(repo != NULL);

	return repo->record_count;
}

uint32_t pldm_pdr_get_repo_size(const pldm_pdr *repo)
{
	assert(repo != NULL);

	return repo->size;
}

uint32_t pldm_pdr_get_record_handle(const pldm_pdr *repo,
				    const pldm_pdr_record *record)
{
	assert(repo != NULL);
	assert(record != NULL);

	return record->record_handle;
}

uint32_t pldm_pdr_add_fru_record_set(pldm_pdr *repo, uint16_t terminus_handle,
				     uint16_t fru_rsi, uint16_t entity_type,
				     uint16_t entity_instance_num,
				     uint16_t container_id)
{
	uint32_t size = sizeof(struct pldm_pdr_hdr) +
			sizeof(struct pldm_pdr_fru_record_set);
	uint8_t data[size];

	struct pldm_pdr_hdr *hdr = (struct pldm_pdr_hdr *)&data;
	hdr->version = 1;
	hdr->record_handle = 0;
	hdr->type = PLDM_PDR_FRU_RECORD_SET;
	hdr->record_change_num = 0;
	hdr->length = sizeof(struct pldm_pdr_fru_record_set);
	struct pldm_pdr_fru_record_set *fru =
	    (struct pldm_pdr_fru_record_set *)((uint8_t *)hdr +
					       sizeof(struct pldm_pdr_hdr));
	fru->terminus_handle = terminus_handle;
	fru->fru_rsi = fru_rsi;
	fru->entity_type = entity_type;
	fru->entity_instance_num = entity_instance_num;
	fru->container_id = container_id;

	return pldm_pdr_add(repo, data, size, 0);
}

const pldm_pdr_record *pldm_pdr_fru_record_set_find_by_rsi(
    const pldm_pdr *repo, uint16_t fru_rsi, uint16_t *terminus_handle,
    uint16_t *entity_type, uint16_t *entity_instance_num,
    uint16_t *container_id)
{
	assert(terminus_handle != NULL);
	assert(entity_type != NULL);
	assert(entity_instance_num != NULL);
	assert(container_id != NULL);

	uint8_t *data = NULL;
	uint32_t size = 0;
	const pldm_pdr_record *curr_record = pldm_pdr_find_record_by_type(
	    repo, PLDM_PDR_FRU_RECORD_SET, NULL, &data, &size);
	while (curr_record != NULL) {
		struct pldm_pdr_fru_record_set *fru =
		    (struct pldm_pdr_fru_record_set
			 *)(data + sizeof(struct pldm_pdr_hdr));
		if (fru->fru_rsi == fru_rsi) {
			*terminus_handle = fru->terminus_handle;
			*entity_type = fru->entity_type;
			*entity_instance_num = fru->entity_instance_num;
			*container_id = fru->container_id;
			return curr_record;
		}
		data = NULL;
		curr_record = pldm_pdr_find_record_by_type(
		    repo, PLDM_PDR_FRU_RECORD_SET, curr_record, &data, &size);
	}

	*terminus_handle = 0;
	*entity_type = 0;
	*entity_instance_num = 0;
	*container_id = 0;

	return NULL;
}

typedef struct pldm_entity_association_tree {
	pldm_entity_node *root;
	uint16_t last_used_container_id;
} pldm_entity_association_tree;

typedef struct pldm_entity_node {
	pldm_entity entity;
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

pldm_entity_association_tree *pldm_entity_association_tree_init()
{
	pldm_entity_association_tree *tree =
	    malloc(sizeof(pldm_entity_association_tree));
	assert(tree != NULL);
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

pldm_entity_node *
pldm_entity_association_tree_add(pldm_entity_association_tree *tree,
				 pldm_entity *entity, pldm_entity_node *parent,
				 uint8_t association_type)
{
	assert(tree != NULL);
	assert(association_type == PLDM_ENTITY_ASSOCIAION_PHYSICAL ||
	       association_type == PLDM_ENTITY_ASSOCIAION_LOGICAL);
	pldm_entity_node *node = malloc(sizeof(pldm_entity_node));
	assert(node != NULL);
	node->first_child = NULL;
	node->next_sibling = NULL;
	node->entity.entity_type = entity->entity_type;
	node->entity.entity_instance_num = 1;
	node->association_type = association_type;

	if (tree->root == NULL) {
		assert(parent == NULL);
		tree->root = node;
		/* container_id 0 here indicates this is the top-most entry */
		node->entity.entity_container_id = 0;
	} else if (parent != NULL && parent->first_child == NULL) {
		parent->first_child = node;
		node->entity.entity_container_id = next_container_id(tree);
	} else {
		pldm_entity_node *start =
		    parent == NULL ? tree->root : parent->first_child;
		pldm_entity_node *prev =
		    find_insertion_at(start, entity->entity_type);
		assert(prev != NULL);
		pldm_entity_node *next = prev->next_sibling;
		if (prev->entity.entity_type == entity->entity_type) {
			assert(prev->entity.entity_instance_num != UINT16_MAX);
			node->entity.entity_instance_num =
			    prev->entity.entity_instance_num + 1;
		}
		prev->next_sibling = node;
		node->next_sibling = next;
		node->entity.entity_container_id =
		    prev->entity.entity_container_id;
	}
	entity->entity_instance_num = node->entity.entity_instance_num;
	entity->entity_container_id = node->entity.entity_container_id;

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

void pldm_entity_association_tree_visit(pldm_entity_association_tree *tree,
					pldm_entity **entities, size_t *size)
{
	assert(tree != NULL);

	*size = 0;
	if (tree->root == NULL) {
		return;
	}

	get_num_nodes(tree->root, size);
	*entities = malloc(*size * sizeof(pldm_entity));
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

void pldm_entity_association_tree_destroy(pldm_entity_association_tree *tree)
{
	assert(tree != NULL);

	entity_association_tree_destroy(tree->root);
	free(tree);
}

inline bool pldm_entity_is_node_parent(pldm_entity_node *node)
{
	assert(node != NULL);

	return node->first_child != NULL;
}

uint8_t pldm_entity_get_num_children(pldm_entity_node *node,
				     uint8_t association_type)
{
	assert(node != NULL);
	assert(association_type == PLDM_ENTITY_ASSOCIAION_PHYSICAL ||
	       association_type == PLDM_ENTITY_ASSOCIAION_LOGICAL);

	size_t count = 0;
	pldm_entity_node *curr = node->first_child;
	while (curr != NULL) {
		if (curr->association_type == association_type) {
			++count;
		}
		curr = curr->next_sibling;
	}

	assert(count < UINT8_MAX);
	return count;
}

static void _entity_association_pdr_add_entry(pldm_entity_node *curr,
					      pldm_pdr *repo, uint16_t size,
					      uint8_t contained_count,
					      uint8_t association_type)
{
	uint8_t pdr[size];
	uint8_t *start = pdr;

	struct pldm_pdr_hdr *hdr = (struct pldm_pdr_hdr *)start;
	hdr->version = 1;
	hdr->record_handle = 0;
	hdr->type = PLDM_PDR_ENTITY_ASSOCIATION;
	hdr->record_change_num = 0;
	hdr->length = size - sizeof(struct pldm_pdr_hdr);
	start += sizeof(struct pldm_pdr_hdr);

	uint16_t *container_id = (uint16_t *)start;
	*container_id = curr->first_child->entity.entity_container_id;
	start += sizeof(uint16_t);
	*start = association_type;
	start += sizeof(uint8_t);

	pldm_entity *entity = (pldm_entity *)start;
	entity->entity_type = curr->entity.entity_type;
	entity->entity_instance_num = curr->entity.entity_instance_num;
	entity->entity_container_id = curr->entity.entity_container_id;
	start += sizeof(pldm_entity);

	*start = contained_count;
	start += sizeof(uint8_t);

	pldm_entity_node *node = curr->first_child;
	while (node != NULL) {
		if (node->association_type == association_type) {
			pldm_entity *entity = (pldm_entity *)start;
			entity->entity_type = node->entity.entity_type;
			entity->entity_instance_num =
			    node->entity.entity_instance_num;
			entity->entity_container_id =
			    node->entity.entity_container_id;
			start += sizeof(pldm_entity);
		}
		node = node->next_sibling;
	}

	pldm_pdr_add(repo, pdr, size, 0);
}

static void entity_association_pdr_add_entry(pldm_entity_node *curr,
					     pldm_pdr *repo)
{
	uint8_t num_logical_children =
	    pldm_entity_get_num_children(curr, PLDM_ENTITY_ASSOCIAION_LOGICAL);
	uint8_t num_physical_children =
	    pldm_entity_get_num_children(curr, PLDM_ENTITY_ASSOCIAION_PHYSICAL);

	if (num_logical_children) {
		uint16_t logical_pdr_size =
		    sizeof(struct pldm_pdr_hdr) + sizeof(uint16_t) +
		    sizeof(uint8_t) + sizeof(pldm_entity) + sizeof(uint8_t) +
		    (num_logical_children * sizeof(pldm_entity));
		_entity_association_pdr_add_entry(
		    curr, repo, logical_pdr_size, num_logical_children,
		    PLDM_ENTITY_ASSOCIAION_LOGICAL);
	}

	if (num_physical_children) {
		uint16_t physical_pdr_size =
		    sizeof(struct pldm_pdr_hdr) + sizeof(uint16_t) +
		    sizeof(uint8_t) + sizeof(pldm_entity) + sizeof(uint8_t) +
		    (num_physical_children * sizeof(pldm_entity));
		_entity_association_pdr_add_entry(
		    curr, repo, physical_pdr_size, num_physical_children,
		    PLDM_ENTITY_ASSOCIAION_PHYSICAL);
	}
}

static void entity_association_pdr_add(pldm_entity_node *curr, pldm_pdr *repo)
{
	if (curr == NULL) {
		return;
	}
	entity_association_pdr_add_entry(curr, repo);
	entity_association_pdr_add(curr->next_sibling, repo);
	entity_association_pdr_add(curr->first_child, repo);
}

void pldm_entity_association_pdr_add(pldm_entity_association_tree *tree,
				     pldm_pdr *repo)
{
	assert(tree != NULL);
	assert(repo != NULL);

	entity_association_pdr_add(tree->root, repo);
}
