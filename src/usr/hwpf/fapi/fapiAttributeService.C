/**
 *  @file fapiAttributeService.C
 *
 *  @brief Implements the AttributeService functions.
 */

#include <stdio.h>
#include <fapiAttributeService.H>
#include <fapiPlatTrace.H>

namespace fapi
{

namespace AttributeService
{

//******************************************************************************
// Get string
//******************************************************************************
template<>
ReturnCode _get<char *> (const AttributeId i_id,
                         const Target * const i_pTarget,
                         char * & o_value)
{
    FAPI_ERR("Get string attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Get uint8_t
//******************************************************************************
template<>
ReturnCode _get<uint8_t> (const AttributeId i_id,
                          const Target * const i_pTarget,
                          uint8_t & o_value)
{
    FAPI_ERR("Get uint8 attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Get uint32_t
//******************************************************************************
template<>
ReturnCode _get<uint32_t> (const AttributeId i_id,
                           const Target * const i_pTarget,
                           uint32_t & o_value)
{
    FAPI_ERR("Get uint32 attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Get uint64_t
//******************************************************************************
template<>
ReturnCode _get<uint64_t> (const AttributeId i_id,
                           const Target * const i_pTarget,
                           uint64_t & o_value)
{
    FAPI_ERR("Get uint64 attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Get uint8_t array
//******************************************************************************
template<>
ReturnCode _get<uint8_t *> (const AttributeId i_id,
                            const Target * const i_pTarget,
                            uint8_t * const o_pValues)
{
    FAPI_ERR("Get uint8 array attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Get uint32_t array
//******************************************************************************
template<>
ReturnCode _get<uint32_t *> (const AttributeId i_id,
                             const Target * const i_pTarget,
                             uint32_t * const o_pValues)
{
    FAPI_ERR("Get uint32 array attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Get uint64_t array
//******************************************************************************
template<>
ReturnCode _get<uint64_t *> (const AttributeId i_id,
                             const Target * const i_pTarget,
                             uint64_t * const o_pValues)
{
    FAPI_ERR("Get uint64 array attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Set string
//******************************************************************************
template<>
ReturnCode _set<char *> (const AttributeId i_id,
                         const Target * const i_pTarget,
                         const char * const i_pValue)
{
    FAPI_ERR("Set string attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Set uint8_t
//******************************************************************************
template<>
ReturnCode _set<uint8_t> (const AttributeId i_id,
                          const Target * const i_pTarget,
                          const uint8_t i_value)
{
    FAPI_ERR("Set uint8 attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Set uint32_t
//******************************************************************************
template<>
ReturnCode _set<uint32_t> (const AttributeId i_id,
                           const Target * const i_pTarget,
                           const uint32_t i_value)
{
    FAPI_ERR("Set uint32 attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Set uint64_t
//******************************************************************************
template<>
ReturnCode _set<uint64_t> (const AttributeId i_id,
                           const Target * const i_pTarget,
                           const uint64_t i_value)
{
    FAPI_ERR("Set uint64 attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Set uint8_t array
//******************************************************************************
template<>
ReturnCode _set<uint8_t *> (const AttributeId i_id,
                            const Target * const i_pTarget,
                            const uint8_t * const i_pValues)
{
    FAPI_ERR("Set uint8 array attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Set uint32_t array
//******************************************************************************
template<>
ReturnCode _set<uint32_t *> (const AttributeId i_id,
                             const Target * const i_pTarget,
                             const uint32_t * const i_pValues)
{
    FAPI_ERR("Set uint32 array attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

//******************************************************************************
// Set uint64_t array
//******************************************************************************
template<>
ReturnCode _set<uint64_t *> (const AttributeId i_id,
                             const Target * const i_pTarget,
                             const uint64_t * const i_pValues)
{
    FAPI_ERR("Set uint64 array attribute not implemented");
    return FAPI_RC_NOT_IMPLEMENTED;
}

} // namespace AttributeService

} // namespace fapi
