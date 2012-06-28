/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pore/poreve/model/modelerror.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __VSBE_MODELERROR_H
#define __VSBE_MODELERROR_H

// $Id: modelerror.H,v 1.10 2012/06/18 13:56:56 bcbrock Exp $

/// \file modelerror.H
/// \brief An enumeration of modeling errors

namespace vsbe {

    /// \enum ModelError
    ///
    /// A large number of error conditions can arise in the PORE VE model,
    /// ranging all the way from bugs in the model to bugs in the virtual
    /// firmware.  The PORE VE model includes an enumeration of all of these
    /// errors for error reporting and to aid in finding bugs. We chose to use
    /// this mechanism rather than defining a FAPI error for each error case
    /// since a FAPI error code may imply a complex error diagnosis and/or
    /// recovery path, while it's likely that most ModelError that halt
    /// simulation are firmware bugs that will be handled the same way.

    enum ModelError {

        /// No error.  This code is permanently assigned to 0, so code is free
        /// to either check for 0 or for ME_SUCCESS.
        ME_SUCCESS = 0,
        /// A generic failure from an operation in the environment
        ME_FAILURE = 1,
        /// An improperly configured model that is missing a bus connection
        ME_NO_BUS_MODEL = 2,
        /// A HOOK instruction hook returned an error
        ME_HOOK_INSTRUCTION_ERROR = 3,
        /// A read hook returned an error
        ME_HOOK_READ_ERROR = 4,
        /// A write hook returned an error
        ME_HOOK_WRITE_ERROR = 5,
        /// A fetch hook returned an error
        ME_HOOK_FETCH_ERROR = 6,
        /// The PORE model was constructed but never initialized
        ME_PORE_UNINITIALIZED = 7,
        /// A generic error from the underlying PoreModel
        ME_PORE_MODEL_GENERIC_ERROR = 8,
        /// A transaction size error
        ME_SIZE_ERROR = 9,
        /// An error ocurred on the registerRead[Raw]() method
        ME_REGISTER_READ_ERROR = 10,
        /// An error ocurred on the registerWrite[Raw]() method
        ME_REGISTER_WRITE_ERROR = 11,
        /// Transaction address is not in any known memory map
        ME_NOT_MAPPED_ON_BUS = 12,
        /// Transaction address is in a memory map but not in the memory image
        ME_NOT_MAPPED_IN_MEMORY = 13,
        /// Transaction mode denied by slave permissions found with transaction address
        ME_BUS_SLAVE_PERMISSION_DENIED = 14,
        /// Transaction mode denied by MemoryImage permissions
        ME_MEMORY_IMAGE_PERMISSION_DENIED = 15,
        /// There is a bug in the model
        ME_BUG = 16,
        /// The WAIT implementation failed for some reason
        ME_WAIT_FAILURE = 17,
        /// There was an error reading or writing a register in the PoreState
        ME_PORE_STATE_ERROR = 18,
        /// Attempting to read a write-only register
        ME_WRITE_ONLY_REGISTER = 19,
        /// Attempting to write a read-only register
        ME_READ_ONLY_REGISTER = 20,
        /// Request for an illegal or unmodeled register
        ME_ILLEGAL_REGISTER_OFFSET = 21,
        /// An illegal mode or setting was programmed in the I2C controller
        ME_FASTI2C_CONTROL_ERROR = 22,
        /// An illegal register sequence was attempted on the I2C controller
        ME_FASTI2C_SEQUENCE_ERROR = 23,
        /// A configuration is duplicate or ambiguous
        ME_DUPLICATE_CONFIGURATION = 24,
        /// A requested device is not mapped on the I2C controller
        ME_NOT_MAPPED_ON_FASTI2C_CONTROLLER = 25,
        /// An illegal address was presented to or computed by an I2C memory
        ME_I2CMEMORY_ILLEGAL_ADDRESS = 26,
        /// Invalid argument
        ME_INVALID_ARGUMENT = 27,
        /// LPC (PNOR) access outside of ECC bounds
        ME_LPC_ILLEGAL_ADDRESS = 28,
        /// An illegal usage of PoreModel::forceBranch()
        ME_ILLEGAL_FORCED_BRANCH = 29,
    };
};

/// HBI doesn't want strings - however for lab/test applications it's nice to
/// be able to print the error codes.  This macro can be instantiated to
/// provide this facility.

#define MODEL_ERROR_STRINGS(var) \
    const char* const var[] = { \
        "Success",                                                      \
        "A generic failure from an operation in the environment",       \
        "An improperly configured model that is missing a bus connection", \
        "A HOOK instruction hook returned an error",                    \
        "A read hook returned an error",                                \
        "A write hook returned an error",                               \
        "A fetch hook returned an error",                               \
        "The PORE model was constructed but never initialized",         \
        "A generic error from the underlying PoreModel",                \
        "A transaction size error",                                     \
        "An error ocurred on the registerRead() method",                \
        "An error ocurred on the registerWrite() method",               \
        "Transaction address is not in any known memory map",           \
        "Transaction address is in a memory map but not in the memory image", \
        "Transaction mode denied by slave permissions found with transaction address", \
        "Transaction mode denied by MemoryImage permissions",           \
        "There is a bug in the model",                                  \
        "The WAIT implementation failed for some reason",               \
        "There was an error reading or writing a register in the PoreState", \
        "Attempting to read a write-only register",                     \
        "Attempting to write a read-only register",                     \
        "Request for an illegal or unmodeled register",                 \
        "An illegal mode or setting was programmed for I2C",            \
        "An illegal register sequence was attempted on the I2C controller", \
        "A configuration is duplicate or ambiguous",                    \
        "A requested device is not mapped on the I2C controller",       \
        "An illegal address was presented to or computed by an I2C memory", \
        "Invalid argument",                                             \
        "LPC (PNOR) access outside of ECC bounds,",                     \
        "An illegal usage of PoreModel::forceBranch()",                 \
    };

#endif  // __VSBE_MODELERROR_H
       
