/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/memory_encryption.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
/* [+] International Business Machines Corp.                              */
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

/* @file memory_encryption.H
 *
 * Interface for Hostboot support for memory encryption.
 */

#ifndef MEMORY_ENCRYPTION_H
#define MEMORY_ENCRYPTION_H

/* @brief Set up the keys for memory encryption.
 *
 * @return errlHndl_t  Error on failure, nullptr otherwise.
 */
errlHndl_t setup_memory_crypto_keys();

/* @brief Lock the memory encryption settings.
 *
 * This function locks the crypto settings so that cryptographic keys cannot be
 * read or written by the host from SCOM registers or the keystore SEEPROM, and
 * encryption/decryption settings cannot be disabled or modified. The lock
 * persists until the units are power-cycled.
 *
 * This function should be called after encryption has been set up and enabled.
 *
 * @return errlHndl_t  Error on failure, nullptr otherwise.
 */
errlHndl_t lock_memory_crypto_settings();

#endif
