#include "../utils.hpp"
#include "common/utils.hpp"

#include <libpldm/pdr.h>

#include <filesystem>

#include <gtest/gtest.h>

namespace fs = std::filesystem;
using namespace pldm;
using namespace pldm::utils;
using namespace pldm::hostbmc::utils;

TEST(EntityAssociation, parseEntityMap)
{
    EntityMaps entityMaps = parseEntityMap("./entitymap_test.json");
    EXPECT_EQ(entityMaps.size(), 10);
}

TEST(EntityAssociation, addObjectPathEntityAssociations1)
{
    pldm_entity entities[8]{};

    entities[0].entity_type = 45;
    entities[0].entity_container_id = 0;

    entities[1].entity_type = 64;
    entities[1].entity_container_id = 1;

    entities[2].entity_type = 67;
    entities[2].entity_container_id = 2;
    entities[3].entity_type = 67;
    entities[3].entity_container_id = 2;

    entities[4].entity_type = 135;
    entities[4].entity_container_id = 3;
    entities[5].entity_type = 135;
    entities[5].entity_container_id = 3;
    entities[6].entity_type = 135;
    entities[6].entity_container_id = 3;
    entities[7].entity_type = 135;
    entities[7].entity_container_id = 3;

    auto tree = pldm_entity_association_tree_init();

    auto l1 = pldm_entity_association_tree_add_entity(
        tree, &entities[0], 1, nullptr, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true,
        true, 0xFFFF);

    auto l2 = pldm_entity_association_tree_add_entity(
        tree, &entities[1], 1, l1, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    auto l3a = pldm_entity_association_tree_add_entity(
        tree, &entities[2], 0, l2, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);
    auto l3b = pldm_entity_association_tree_add_entity(
        tree, &entities[3], 1, l2, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    auto l4a = pldm_entity_association_tree_add_entity(
        tree, &entities[4], 0, l3a, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);
    auto l4b = pldm_entity_association_tree_add_entity(
        tree, &entities[5], 1, l3a, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    auto l5a = pldm_entity_association_tree_add_entity(
        tree, &entities[6], 0, l3b, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);
    auto l5b = pldm_entity_association_tree_add_entity(
        tree, &entities[7], 1, l3b, PLDM_ENTITY_ASSOCIAION_PHYSICAL, true, true,
        0xFFFF);

    EntityAssociations entityAssociations = {
        {l1, l2}, {l2, l3a, l3b}, {l3a, l4a, l4b}, {l3b, l5a, l5b}};

    ObjectPathMaps retObjectMaps = {
        {"/xyz/openbmc_project/inventory/chassis1", l1},
        {"/xyz/openbmc_project/inventory/chassis1/motherboard1", l2},
        {"/xyz/openbmc_project/inventory/chassis1/motherboard1/dcm0", l3a},
        {"/xyz/openbmc_project/inventory/chassis1/motherboard1/dcm0/cpu0", l4a},
        {"/xyz/openbmc_project/inventory/chassis1/motherboard1/dcm0/cpu1", l4b},
        {"/xyz/openbmc_project/inventory/chassis1/motherboard1/dcm1", l3b},
        {"/xyz/openbmc_project/inventory/chassis1/motherboard1/dcm1/cpu0", l5a},
        {"/xyz/openbmc_project/inventory/chassis1/motherboard1/dcm1/cpu1",
         l5b}};

    ObjectPathMaps objPathMap;
    EntityMaps entityMaps = parseEntityMap("./entitymap_test.json");
    updateEntityAssociation(entityAssociations, tree, objPathMap, entityMaps,
                            nullptr);

    EXPECT_EQ(objPathMap.size(), retObjectMaps.size());

    int index = 0;
    for (auto& obj : objPathMap)
    {
        if (retObjectMaps.contains(obj.first))
        {
            index++;
            pldm_entity entity = pldm_entity_extract(obj.second);
            pldm_entity retEntity =
                pldm_entity_extract(retObjectMaps[obj.first]);
            EXPECT_EQ(entity.entity_type, retEntity.entity_type);
            EXPECT_EQ(entity.entity_instance_num,
                      retEntity.entity_instance_num);
            EXPECT_EQ(pldm_entity_node_get_remote_container_id(obj.second),
                      pldm_entity_node_get_remote_container_id(
                          retObjectMaps[obj.first]));
        }
    }
    EXPECT_EQ(index, retObjectMaps.size());
    pldm_entity_association_tree_destroy(tree);
}
