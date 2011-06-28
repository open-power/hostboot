/**
 *  @file fapiSystemConfig.H
 *
 *  @brief Defines the System Config query functions that platform code must
 *         implement. It is an eCMD requirement that these be "C" functions.
 */

#ifndef FAPISYSTEMCONFIG_H_
#define FAPISYSTEMCONFIG_H_

#include <stdint.h>
#include <vector>
#include <fapiReturnCode.H>
#include <fapiTarget.H>

extern "C"
{

/**
 * @brief Gets the functional chiplets that are children of the supplied target
 *
 * @param[in]  i_target     Parent target
 * @param[in]  i_targetType Type of chiplet required
 * @param[out] o_chiplets   Reference to vector that is filled in with the
 *                          result chiplets
 *
 * @return ReturnCode. Zero on success, else error
 */
fapi::ReturnCode GetFunctionalChiplets(const fapi::Target& i_target,
                                       const fapi::TargetType i_chipletType,
                                       std::vector<fapi::Target> & o_chiplets);

/**
 * @brief Gets the existing chiplets that are children of the supplied target
 *
 * @param[in]  i_target     Parent target
 * @param[in]  i_targetType Type of chiplet required
 * @param[out] o_chiplets   Reference to vector that is filled in with the
 *                          result chiplets
 *
 * @return ReturnCode. Zero on success, else error
 */
fapi::ReturnCode GetExistingChiplets(const fapi::Target& i_target,
                                     const fapi::TargetType i_chipletType,
                                     std::vector<fapi::Target> & o_chiplets);

/**
 * @brief Gets the functional DIMMs that are children of the supplied target
 *
 * @param[in]  i_target Parent target
 * @param[out] o_dimms  Reference to vector that is filled in with the result
 *                      DIMMs
 *
 * @return ReturnCode. Zero on success, else error
 */
fapi::ReturnCode GetFunctionalDimms(const fapi::Target& i_target,
                                    std::vector<fapi::Target> & o_dimms);

/**
 * @brief Gets the existing DIMMs that are children of the supplied target
 *
 * @param[in]  i_target Parent target
 * @param[out] o_dimms  Reference to vector that is filled in with the result
 *                      DIMMs
 *
 * @return ReturnCode. Zero on success, else error
 */
fapi::ReturnCode GetExistingDimms(const fapi::Target& i_target,
                                  std::vector<fapi::Target> & o_dimms);

} // extern "C"

#endif // FAPISYSTEMCONFIG_H_
