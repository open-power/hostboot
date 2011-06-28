/**
 *  @file fapiAttributeService.H
 *
 *  @brief Defines the FAPI_ATTR_GET and FAPI_ATTR_SET macros that a user calls
 *         to get/set attributes and the AttributeService functions that the
 *         macros use to get/set attributes
 */

#ifndef FAPIATTRIBUTESERVICE_H_
#define FAPIATTRIBUTESERVICE_H_
#include <stdint.h>
#include <fapiAttributeIds.H>
#include <fapiReturnCode.H>
#include <fapiTarget.H>

/**
 * @brief Macros called by user to get/set attributes
 *
 * @note The user must use these macros rather than use the AttributeService
 *       _get/_set functions so that the type can be checked at compile time
 *
 * Code must have a pointer to a Target and an attribute ID (from XML file):
 *   fapi::ReturnCode l_rc;
 *   fapi::Target * l_pTarget = ????;
 *   AttributeId l_id = ????;
 *
 * To get a copy of a string attribute
 *   char * l_pString = NULL;
 *   l_rc = FAPI_ATTR_GET(l_id, l_pTarget, l_pString);
 *   delete[] l_pString; // When finished with the attribute
 *
 * To set a string attribute
 *   l_rc = FAPI_ATTR_SET(l_id, l_pTarget, "string-literal");
 *   l_rc = FAPI_ATTR_SET(l_id, l_pTarget, l_pString);
 *
 * To get a copy of an integer attribute and set the attribute
 *   uint64_t l_val = 0;
 *   l_rc = FAPI_ATTR_GET(l_id, l_pTarget, l_val);
 *   l_rc = FAPI_ATTR_SET(l_id, l_pTarget, l_val);
 *
 * To get a copy of an integer array attribute and set the attribute
 *   uint32_t l_pVal[4] = {0};
 *   l_rc = FAPI_ATTR_GET(l_id, l_pTarget, l_pVal);
 *   l_rc = FAPI_ATTR_SET(l_id, l_pTarget, l_pVal);
 */
#define FAPI_ATTR_GET(ID, PTARGET, VAL) \
    fapi::AttributeService::_get<fapi::ID##_Type>(fapi::ID, PTARGET, VAL)
#define FAPI_ATTR_SET(ID, PTARGET, VAL) \
    fapi::AttributeService::_set<fapi::ID##_Type>(fapi::ID, PTARGET, VAL)

namespace fapi
{

/**
 * @namespace AttributeService
 *
 * This class defines the attribute access functions. These functions must not
 * be accessed directly, they should only be called by the FAPI_ATTR_GET and
 * FAPI_ATTR_SET macros.
 *
 * Each function comes in two parts. If the caller of FAPI_ATTR_GET attempts to
 * get an incorrect type then the normal template function will be instantiated
 * and the construction of the undefined InvalidTypeRequestedForAttribute class
 * will cause a compile failure. Only if the caller attempts to get the correct
 * type will the specialized function be called which will work.
 */
namespace AttributeService
{

/**
 * @brief Forward declaration of class that will never be defined
 */
class InvalidTypeRequestedForAttribute;

/**
 * @brief Get a copy of a string attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated with
 *                       (NULL if system attribute)
 * @param[out] o_pValue  Reference to pointer that will be set to point to newly
 *                       allocated memory holding the attribute value
 *
 * @return ReturnCode. Zero on success, else error.
 *
 * @note The caller must free the data with "delete [] o_pValue"
 */
template<typename T>
ReturnCode _get(const AttributeId i_id,
                const Target * const i_pTarget,
                char * & o_pValue)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _get<char *> (const AttributeId i_id,
                         const Target * const i_pTarget,
                         char * & o_value);

/**
 * @brief Get a copy of a uint8_t attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated with
 *                       (NULL if system attribute)
 * @param[out] o_value   Reference to data that will be set to the attribute val
 *
 * @return ReturnCode. Zero on success, else error.
 */
template<typename T>
ReturnCode _get(const AttributeId i_id,
                const Target * const i_pTarget,
                uint8_t& o_value)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _get<uint8_t> (const AttributeId i_id,
                          const Target * const i_pTarget,
                          uint8_t & o_value);

/**
 * @brief Get a copy of a uint32_t attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated with
 *                       (NULL if system attribute)
 * @param[out] o_value   Reference to data that will be set to the attribute val
 *
 * @return ReturnCode. Zero on success, else error.
 */
template<typename T>
ReturnCode _get(const AttributeId i_id,
                const Target * const i_pTarget,
                uint32_t& o_value)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _get<uint32_t> (const AttributeId i_id,
                           const Target * const i_pTarget,
                           uint32_t & o_value);

/**
 * @brief Get a copy of a uint64_t attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated with
 *                       (NULL if system attribute)
 * @param[out] o_value   Reference to data that will be set to the attribute val
 *
 * @return ReturnCode. Zero on success, else error.
 */
template<typename T>
ReturnCode _get(const AttributeId i_id,
                const Target * const i_pTarget,
                uint64_t& o_value)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _get<uint64_t> (const AttributeId i_id,
                           const Target * const i_pTarget,
                           uint64_t & o_value);

/**
 * @brief Get a copy of a uint8_t array attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated with
 *                       (NULL if system attribute)
 * @param[out] o_pValues Pointer to data that will be set to the attribute value
 *
 * @return ReturnCode. Zero on success, else error.
 *
 * @note The caller's o_pValues pointer must point to memory large enough to
 *       hold the attribute.
 */
template<typename T>
ReturnCode _get(const AttributeId i_id,
                const Target * const i_pTarget,
                uint8_t * const o_pValues)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _get<uint8_t *> (const AttributeId i_id,
                            const Target * const i_pTarget,
                            uint8_t * const o_pValues);

/**
 * @brief Get a copy of a uint32_t array attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated with
 *                       (NULL if system attribute)
 * @param[out] o_pValues Pointer to data that will be set to the attribute value
 *
 * @return ReturnCode. Zero on success, else error.
 *
 * @note The caller's o_pValues pointer must point to memory large enough to
 *       hold the attribute.
 */
template<typename T>
ReturnCode _get(const AttributeId i_id,
                const Target * const i_pTarget,
                uint32_t * const o_pValues)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _get<uint32_t *> (const AttributeId i_id,
                             const Target * const i_pTarget,
                             uint32_t * const o_pValues);

/**
 * @brief Get a copy of a uint64_t array attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated with
 *                       (NULL if system attribute)
 * @param[out] o_pValues Pointer to data that will be set to the attribute value
 *
 * @return ReturnCode. Zero on success, else error.
 *
 * @note The caller's o_pValues pointer must point to memory large enough to
 *       hold the attribute.
 */
template<typename T>
ReturnCode _get(const AttributeId i_id,
                const Target * const i_pTarget,
                uint64_t * const o_pValues)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _get<uint64_t *> (const AttributeId i_id,
                             const Target * const i_pTarget,
                             uint64_t * const o_pValues);

/**
 * @brief Set a string attribute
 *
 * @param[in] i_id      Attribute ID
 * @param[in] i_pTarget Pointer to Target that the attribute is associated with
 *                      (NULL if system attribute)
 * @param[in] i_pValue  Pointer to string containing the attribute value to set
 *
 * @return ReturnCode. Zero on success, else error.
 */
template<typename T>
ReturnCode _set(const AttributeId i_id,
                const Target * const i_pTarget,
                const char * const i_pValue)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _set<char *> (const AttributeId i_id,
                         const Target * const i_pTarget,
                         const char * const i_pValue);

/**
 * @brief Set a uint8_t attribute
 *
 * @param[in] i_id      Attribute ID
 * @param[in] i_pTarget Pointer to Target that the attribute is associated with
 *                      (NULL if system attribute)
 * @param[in] i_value   Attribute value to set
 *
 * @return ReturnCode. Zero on success, else error.
 */
template<typename T>
ReturnCode _set(const AttributeId i_id,
                const Target * const i_pTarget,
                const uint8_t i_value)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _set<uint8_t> (const AttributeId i_id,
                          const Target * const i_pTarget,
                          const uint8_t i_value);

/**
 * @brief Set a uint32_t attribute
 *
 * @param[in] i_id      Attribute ID
 * @param[in] i_pTarget Pointer to Target that the attribute is associated with
 *                      (NULL if system attribute)
 * @param[in] i_value   Attribute value to set
 *
 * @return ReturnCode. Zero on success, else error.
 */
template<typename T>
ReturnCode _set(const AttributeId i_id,
                const Target * const i_pTarget,
                const uint32_t i_value)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _set<uint32_t> (const AttributeId i_id,
                           const Target * const i_pTarget,
                           const uint32_t i_value);

/**
 * @brief Set a uint64_t attribute
 *
 * @param[in] i_id      Attribute ID
 * @param[in] i_pTarget Pointer to Target that the attribute is associated with
 *                      (NULL if system attribute)
 * @param[in] i_value   Attribute value to set
 *
 * @return ReturnCode. Zero on success, else error.
 */
template<typename T>
ReturnCode _set(const AttributeId i_id,
                const Target * const i_pTarget,
                const uint64_t i_value)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _set<uint64_t> (const AttributeId i_id,
                           const Target * const i_pTarget,
                           const uint64_t i_value);

/**
 * @brief Set a uint8_t array attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated
 *                       with (NULL if system attribute)
 * @param[out] i_pValues Pointer to array containing the attribute values to
 *                       set
 *
 * @return ReturnCode. Zero on success, else error.
 *
 * @note The caller's o_pValues pointer must point to memory large enough to
 *       hold the attribute.
 */
template<typename T>
ReturnCode _set(const AttributeId i_id,
                const Target * const i_pTarget,
                const uint8_t * const i_pValues)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _set<uint8_t *> (const AttributeId i_id,
                            const Target * const i_pTarget,
                            const uint8_t * const i_pValues);

/**
 * @brief Set a uint32_t array attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated
 *                       with (NULL if system attribute)
 * @param[out] i_pValues Pointer to array containing the attribute values to
 *                       set
 *
 * @return ReturnCode. Zero on success, else error.
 *
 * @note The caller's o_pValues pointer must point to memory large enough to
 *       hold the attribute.
 */
template<typename T>
ReturnCode _set(const AttributeId i_id,
                const Target * const i_pTarget,
                const uint32_t * const i_pValues)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _set<uint32_t *> (const AttributeId i_id,
                             const Target * const i_pTarget,
                             const uint32_t * const i_pValues);

/**
 * @brief Set a uint64_t array attribute
 *
 * @param[in]  i_id      Attribute ID
 * @param[in]  i_pTarget Pointer to Target that the attribute is associated
 *                       with (NULL if system attribute)
 * @param[out] i_pValues Pointer to array containing the attribute values to
 *                       set
 *
 * @return ReturnCode. Zero on success, else error.
 *
 * @note The caller's o_pValues pointer must point to memory large enough to
 *       hold the attribute.
 */
template<typename T>
ReturnCode _set(const AttributeId i_id,
                const Target * const i_pTarget,
                const uint64_t * const i_pValues)
{
    InvalidTypeRequestedForAttribute();
    return FAPI_RC_SUCCESS;
}
template<> // Specialized template function defined in fapiAttributeService.C
ReturnCode _set<uint64_t *> (const AttributeId i_id,
                             const Target * const i_pTarget,
                             const uint64_t * const i_pValues);


} // namespace AttributeService

} // namespace fapi

#endif // FAPIATTRIBUTESERVICE_H_
