#include "common/utils.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace pldm
{
namespace utils
{
/** @brief helper function for parameter matching
 *  @param[in] lhs - left-hand side value
 *  @param[in] rhs - right-hand side value
 *  @return true if it matches
 */
inline bool operator==(const DBusMapping& lhs, const DBusMapping& rhs)
{
    return lhs.objectPath == rhs.objectPath && lhs.interface == rhs.interface &&
           lhs.propertyName == rhs.propertyName &&
           lhs.propertyType == rhs.propertyType;
}

} // namespace utils
} // namespace pldm

class GetManagedEmptyObject
{
  public:
    static pldm::utils::ObjectValueTree
        getManagedObj(const char* /*service*/, const char* /*path*/)
    {
        return pldm::utils::ObjectValueTree{};
    }
};

class GetManagedObject
{
  public:
    static pldm::utils::ObjectValueTree
        getManagedObj(const char* /*service*/, const char* /*path*/)
    {
        return pldm::utils::ObjectValueTree{
            {sdbusplus::message::object_path("/foo/bar"),
             {{"foo.bar",
               {{"Functional", true},
                {"Enabled", true},
                {"PrettyName", "System"},
                {"Present", true},
                {"SerialNumber", "abc123z"},
                {"Model", "1234 - 00Z"},
                {"SubModel", "S0"}}}}}};
    }
};

class MockdBusHandler : public pldm::utils::DBusHandler
{
  public:
    MOCK_METHOD(std::string, getService, (const char*, const char*),
                (const override));

    MOCK_METHOD(void, setDbusProperty,
                (const pldm::utils::DBusMapping&,
                 const pldm::utils::PropertyValue&),
                (const override));

    MOCK_METHOD(pldm::utils::PropertyValue, getDbusPropertyVariant,
                (const char*, const char*, const char*), (const override));

    MOCK_METHOD(pldm::utils::GetSubTreeResponse, getSubtree,
                (const std::string&, int, const std::vector<std::string>&),
                (const override));

    MOCK_METHOD(pldm::utils::GetSubTreePathsResponse, getSubTreePaths,
                (const std::string&, int, const std::vector<std::string>&),
                (const override));
};
