/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extern/file_io.h $                               */
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
#ifndef FILEIO_H
#define FILEIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#include "base.h"

/** @brief PLDM Commands in IBM OEM type
 */
enum pldm_fileio_commands {
	PLDM_GET_FILE_TABLE = 0x1,
	PLDM_READ_FILE = 0x4,
	PLDM_WRITE_FILE = 0x5,
	PLDM_READ_FILE_INTO_MEMORY = 0x6,
	PLDM_WRITE_FILE_FROM_MEMORY = 0x7,
	PLDM_READ_FILE_BY_TYPE_INTO_MEMORY = 0x8,
	PLDM_WRITE_FILE_BY_TYPE_FROM_MEMORY = 0x9,
	PLDM_NEW_FILE_AVAILABLE = 0xA,
	PLDM_READ_FILE_BY_TYPE = 0xB,
	PLDM_WRITE_FILE_BY_TYPE = 0xC,
	PLDM_FILE_ACK = 0xD,
};

/** @brief PLDM Command specific codes
 */
enum pldm_fileio_completion_codes {
	PLDM_INVALID_FILE_HANDLE = 0x80,
	PLDM_DATA_OUT_OF_RANGE = 0x81,
	PLDM_INVALID_READ_LENGTH = 0x82,
	PLDM_INVALID_WRITE_LENGTH = 0x83,
	PLDM_FILE_TABLE_UNAVAILABLE = 0x84,
	PLDM_INVALID_FILE_TABLE_TYPE = 0x85,
	PLDM_INVALID_FILE_TYPE = 0x86,
};

/** @brief PLDM File I/O table types
 */
enum pldm_fileio_table_type {
	PLDM_FILE_ATTRIBUTE_TABLE = 0,
	PLDM_OEM_FILE_ATTRIBUTE_TABLE = 1,
};

/** @brief PLDM File I/O table types
 */
enum pldm_fileio_file_type {
	PLDM_FILE_TYPE_PEL = 0,
	PLDM_FILE_TYPE_LID_PERM = 1,
	PLDM_FILE_TYPE_LID_TEMP = 2,
};

#define PLDM_RW_FILE_MEM_REQ_BYTES 20
#define PLDM_RW_FILE_MEM_RESP_BYTES 5
#define PLDM_GET_FILE_TABLE_REQ_BYTES 6
#define PLDM_GET_FILE_TABLE_MIN_RESP_BYTES 6
#define PLDM_READ_FILE_REQ_BYTES 12
#define PLDM_READ_FILE_RESP_BYTES 5
#define PLDM_WRITE_FILE_REQ_BYTES 12
#define PLDM_WRITE_FILE_RESP_BYTES 5
#define PLDM_RW_FILE_BY_TYPE_MEM_REQ_BYTES 22
#define PLDM_RW_FILE_BY_TYPE_MEM_RESP_BYTES 5
#define PLDM_NEW_FILE_REQ_BYTES 10
#define PLDM_NEW_FILE_RESP_BYTES 1
#define PLDM_RW_FILE_BY_TYPE_REQ_BYTES 14
#define PLDM_RW_FILE_BY_TYPE_RESP_BYTES 5
#define PLDM_FILE_ACK_REQ_BYTES 7
#define PLDM_FILE_ACK_RESP_BYTES 1

/** @struct pldm_read_write_file_memory_req
 *
 *  Structure representing ReadFileIntoMemory request and WriteFileFromMemory
 *  request
 */
struct pldm_read_write_file_memory_req {
	uint32_t file_handle; //!< A Handle to the file
	uint32_t offset;      //!< Offset to the file
	uint32_t length;      //!< Number of bytes to be read/write
	uint64_t address;     //!< Memory address of the file
} __attribute__((packed));

/** @struct pldm_read_write_file_memory_resp
 *
 *  Structure representing ReadFileIntoMemory response and WriteFileFromMemory
 *  response
 */
struct pldm_read_write_file_memory_resp {
	uint8_t completion_code; //!< completion code
	uint32_t length;	 //!< Number of bytes read/written
} __attribute__((packed));

/** @brief Decode ReadFileIntoMemory and WriteFileFromMemory commands request
 *         data
 *
 *  @param[in] msg - Pointer to PLDM request message
 *  @param[in] payload_length - Length of request payload
 *  @param[out] file_handle - A handle to the file
 *  @param[out] offset - Offset to the file at which the read should begin
 *  @param[out] length - Number of bytes to be read
 *  @param[out] address - Memory address where the file content has to be
 *                        written to
 *  @return pldm_completion_codes
 */
int decode_rw_file_memory_req(const struct pldm_msg *msg, size_t payload_length,
			      uint32_t *file_handle, uint32_t *offset,
			      uint32_t *length, uint64_t *address);

/** @brief Create a PLDM response for ReadFileIntoMemory and
 *         WriteFileFromMemory
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] command - PLDM command
 *  @param[in] completion_code - PLDM completion code
 *  @param[in] length - Number of bytes read. This could be less than what the
			 requester asked for.
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'
 */
int encode_rw_file_memory_resp(uint8_t instance_id, uint8_t command,
			       uint8_t completion_code, uint32_t length,
			       struct pldm_msg *msg);

/** @brief Encode ReadFileIntoMemory and WriteFileFromMemory
 *         commands request data
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] command - PLDM command
 *  @param[in] file_handle - A handle to the file
 *  @param[in] offset -  Offset to the file at which the read should begin
 *  @param[in] length -  Number of bytes to be read/written
 *  @param[in] address - Memory address where the file content has to be
 *                       written to
 *  @param[out] msg - Message will be written to this
 *  @return pldm_completion_codes
 */
int encode_rw_file_memory_req(uint8_t instance_id, uint8_t command,
			      uint32_t file_handle, uint32_t offset,
			      uint32_t length, uint64_t address,
			      struct pldm_msg *msg);

/** @brief Decode ReadFileIntoMemory and WriteFileFromMemory
 *         commands response data
 *
 *  @param[in] msg - pointer to PLDM response message
 *  @param[in] payload_length - Length of response payload
 *  @param[out] completion_code - PLDM completion code
 *  @param[out] length - Number of bytes to be read/written
 *  @return pldm_completion_codes
 */
int decode_rw_file_memory_resp(const struct pldm_msg *msg,
			       size_t payload_length, uint8_t *completion_code,
			       uint32_t *length);

/** @struct pldm_get_file_table_req
 *
 *  Structure representing GetFileTable request
 */
struct pldm_get_file_table_req {
	uint32_t transfer_handle; //!< Data transfer handle
	uint8_t operation_flag;   //!< Transfer operation flag
	uint8_t table_type;       //!< Table type
} __attribute__((packed));

/** @struct pldm_get_file_table_resp
 *
 *  Structure representing GetFileTable response fixed data
 */
struct pldm_get_file_table_resp {
	uint8_t completion_code;       //!< Completion code
	uint32_t next_transfer_handle; //!< Next data transfer handle
	uint8_t transfer_flag;	 //!< Transfer flag
	uint8_t table_data[1];	 //!< Table Data
} __attribute__((packed));

/** @brief Encode GetFileTable command request
 *
 * @param[in] instance_id - Message's instance id
 * @param[in] transfer_handle - Handle to identify the next part of the exchange
 * @param[in] operation_flag - Flag indicating the current part of the transfer
 * @param[in] table_type - The type of table to return
 * @param[in] msg - Pointer to PLDM message
 * @param[in] payload_length - The length of the request
 * @return pldm_completion_codes
 */
int encode_get_file_table_req(uint8_t instance_id, uint32_t transfer_handle,
                              uint8_t operation_flag, uint8_t table_type,
                              struct pldm_msg* msg, size_t payload_length);

/** @brief Decode GetFileTable response
 *
 * @param[in] msg - The pointer to PLDM response message
 * @param[in] payload_length - The size of the response message
 * @param[out] completion_code - The completion code of the operation
 * @param[out] next_transfer_code - Handle to identify the next part of the
 *             exchange
 * @param[out] transfer_flag - Transfer operation flag
 * @param[out] table_size - The size of the requested table (in bytes)
 * @param[out] table_data - The pointer to the beginning of the returned table;
 *             if table_data is NULL, table_size will be set, but no data will
 *             be copied into table_data
 * @return pldm_completion_codes
 */
int decode_get_file_table_resp(const struct pldm_msg *msg,
                               size_t payload_length,
                               uint8_t* completion_code,
                               uint32_t* next_transfer_handle,
                               uint8_t* transfer_flag,
                               size_t* table_size,
                               uint8_t* table_data);

/** @brief Decode GetFileTable command request data
 *
 *  @param[in] msg - Pointer to PLDM request message
 *  @param[in] payload_length - Length of request payload
 *  @param[out] trasnfer_handle - the handle of data
 *  @param[out] transfer_opflag - Transfer operation flag
 *  @param[out] table_type - the type of file table
 *  @return pldm_completion_codes
 */
int decode_get_file_table_req(const struct pldm_msg *msg, size_t payload_length,
			      uint32_t *transfer_handle,
			      uint8_t *transfer_opflag, uint8_t *table_type);

/** @brief Create a PLDM response for GetFileTable command
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] completion_code - PLDM completion code
 *  @param[in] next_transfer_handle - Handle to identify next portion of
 *              data transfer
 *  @param[in] transfer_flag - Represents the part of transfer
 *  @param[in] table_data - pointer to file table data
 *  @param[in] table_size - file table size
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'
 */
int encode_get_file_table_resp(uint8_t instance_id, uint8_t completion_code,
			       uint32_t next_transfer_handle,
			       uint8_t transfer_flag, const uint8_t *table_data,
			       size_t table_size, struct pldm_msg *msg);

/** @struct pldm_read_file_req
 *
 *  Structure representing ReadFile request
 */
struct pldm_read_file_req {
	uint32_t file_handle; //!< Handle to file
	uint32_t offset;      //!< Offset to file where read starts
	uint32_t length;      //!< Bytes to be read
} __attribute__((packed));

/** @struct pldm_read_file_resp
 *
 *  Structure representing ReadFile response data
 */
struct pldm_read_file_resp {
	uint8_t completion_code; //!< Completion code
	uint32_t length;	 //!< Number of bytes read
	uint8_t file_data[1];    //!< Address of this is where file data starts
} __attribute__((packed));

/** @struct pldm_write_file_req
 *
 *  Structure representing WriteFile request
 */
struct pldm_write_file_req {
	uint32_t file_handle; //!< Handle to file
	uint32_t offset;      //!< Offset to file where write starts
	uint32_t length;      //!< Bytes to be written
	uint8_t file_data[1]; //!< Address of this is where file data starts
} __attribute__((packed));

/** @struct pldm_write_file_resp
 *
 *  Structure representing WriteFile response data
 */
struct pldm_write_file_resp {
	uint8_t completion_code; //!< Completion code
	uint32_t length;	 //!< Bytes written
} __attribute__((packed));

/** @brief Decode Read File commands request
 *
 *  @param[in] msg - PLDM request message payload
 *  @param[in] payload_length - Length of request payload
 *  @param[out] file_handle - A handle to the file
 *  @param[out] offset - Offset to the file at which the read should begin
 *  @param[out] length - Number of bytes read
 *  @return pldm_completion_codes
 */
int decode_read_file_req(const struct pldm_msg *msg, size_t payload_length,
			 uint32_t *file_handle, uint32_t *offset,
			 uint32_t *length);

/** @brief Encode Read File commands request
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] file_handle - A handle to the file
 *  @param[in] offset - Offset to the file at which the read should begin
 *  @param[in] length - Number of bytes read
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'
 */
int encode_read_file_req(uint8_t instance_id, uint32_t file_handle,
			 uint32_t offset, uint32_t length,
			 struct pldm_msg *msg);

/** @brief Decode Read File commands response
 *
 *  @param[in] msg - PLDM response message payload
 *  @param[in] payload_length - Length of request payload
 *  @param[out] completion_code - PLDM completion code
 *  @param[out] length - Number of bytes read. This could be less than what the
 *                       requester asked for.
 *  @param[out] file_data_offset - Offset where file data should be read in pldm
 * msg.
 *  @return pldm_completion_codes
 */
int decode_read_file_resp(const struct pldm_msg *msg, size_t payload_length,
			  uint8_t *completion_code, uint32_t *length,
			  size_t *file_data_offset);

/** @brief Create a PLDM response for Read File
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] completion_code - PLDM completion code
 *  @param[in] length - Number of bytes read. This could be less than what the
 *                      requester asked for.
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'.
 *  Although read file command response includes file data, this function
 *  does not encode the file data to prevent additional copying of the data.
 *  The position of file data is calculated by caller from address and size
 *  of other input arguments.
 */
int encode_read_file_resp(uint8_t instance_id, uint8_t completion_code,
			  uint32_t length, struct pldm_msg *msg);

/** @brief Decode Write File commands request
 *
 *  @param[in] msg - PLDM request message payload
 *  @param[in] payload_length - Length of request payload
 *  @param[out] file_handle - A handle to the file
 *  @param[out] offset - Offset to the file at which the write should begin
 *  @param[out] length - Number of bytes to write
 *  @param[out] file_data_offset - Offset where file data write begins in pldm
 * msg.
 *  @return pldm_completion_codes
 */
int decode_write_file_req(const struct pldm_msg *msg, size_t payload_length,
			  uint32_t *file_handle, uint32_t *offset,
			  uint32_t *length, size_t *file_data_offset);

/** @brief Create a PLDM request for Write File
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] file_handle - A handle to the file
 *  @param[in] offset - Offset to the file at which the read should begin
 *  @param[in] length - Number of bytes written. This could be less than what
 *                      the requester asked for.
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'.
 *  Although write file command request includes file data, this function
 *  does not encode the file data to prevent additional copying of the data.
 *  The position of file data is calculated by caller from address and size
 *  of other input arguments.
 */
int encode_write_file_req(uint8_t instance_id, uint32_t file_handle,
			  uint32_t offset, uint32_t length,
			  struct pldm_msg *msg);

/** @brief Decode Write File commands response
 *
 *  @param[in] msg - PLDM request message payload
 *  @param[in] payload_length - Length of request payload
 *  @param[out] completion_code - PLDM completion code
 *  @param[out] length - Number of bytes written
 *  @return pldm_completion_codes
 */
int decode_write_file_resp(const struct pldm_msg *msg, size_t payload_length,
			   uint8_t *completion_code, uint32_t *length);

/** @brief Create a PLDM response for Write File
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] completion_code - PLDM completion code
 *  @param[in] length - Number of bytes written. This could be less than what
 *                      the requester asked for.
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'
 */
int encode_write_file_resp(uint8_t instance_id, uint8_t completion_code,
			   uint32_t length, struct pldm_msg *msg);

/** @struct pldm_read_write_file_by_type_memory_req
 *
 *  Structure representing ReadFileByTypeIntoMemory and
 * WriteFileByTypeFromMemory request
 */
struct pldm_read_write_file_by_type_memory_req {
	uint16_t file_type;   //!< Type of file
	uint32_t file_handle; //!< Handle to file
	uint32_t offset;      //!< Offset to file where read starts
	uint32_t length;      //!< Bytes to be read
	uint64_t address;     //!< Memory address of the file
} __attribute__((packed));

/** @struct pldm_read_write_file_by_type_memory_resp
 *
 *  Structure representing ReadFileByTypeIntoMemory and
 * WriteFileByTypeFromMemory response
 */
struct pldm_read_write_file_by_type_memory_resp {
	uint8_t completion_code; //!< Completion code
	uint32_t length;	 //!< Number of bytes read
} __attribute__((packed));

/** @brief Decode ReadFileByTypeIntoMemory and WriteFileByTypeFromMemory
 * commands request data
 *
 *  @param[in] msg - Pointer to PLDM request message
 *  @param[in] payload_length - Length of request payload
 *  @param[in] file_type - Type of the file
 *  @param[out] file_handle - A handle to the file
 *  @param[out] offset - Offset to the file at which the read should begin
 *  @param[out] length - Number of bytes to be read
 *  @param[out] address - Memory address of the file content
 *  @return pldm_completion_codes
 */
int decode_rw_file_by_type_memory_req(const struct pldm_msg *msg,
				      size_t payload_length,
				      uint16_t *file_type,
				      uint32_t *file_handle, uint32_t *offset,
				      uint32_t *length, uint64_t *address);

/** @brief Create a PLDM response for ReadFileByTypeIntoMemory and
 * WriteFileByTypeFromMemory
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] command - PLDM command
 *  @param[in] completion_code - PLDM completion code
 *  @param[in] length - Number of bytes read. This could be less than what the
 *                      requester asked for.
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'
 */
int encode_rw_file_by_type_memory_resp(uint8_t instance_id, uint8_t command,
				       uint8_t completion_code, uint32_t length,
				       struct pldm_msg *msg);

/** @brief Encode ReadFileByTypeIntoMemory and WriteFileByTypeFromMemory
 *         commands request data
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] command - PLDM command
 *  @param[in] file_type - Type of the file
 *  @param[in] file_handle - A handle to the file
 *  @param[in] offset -  Offset to the file at which the read should begin
 *  @param[in] length -  Number of bytes to be read/written
 *  @param[in] address - Memory address where the file content has to be
 *                       written to
 *  @param[out] msg - Message will be written to this
 *  @return pldm_completion_codes
 */
int encode_rw_file_by_type_memory_req(uint8_t instance_id, uint8_t command,
				      uint16_t file_type, uint32_t file_handle,
				      uint32_t offset, uint32_t length,
				      uint64_t address, struct pldm_msg *msg);

/** @brief Decode ReadFileTypeIntoMemory and WriteFileTypeFromMemory
 *         commands response data
 *
 *  @param[in] msg - pointer to PLDM response message
 *  @param[in] payload_length - Length of response payload
 *  @param[out] completion_code - PLDM completion code
 *  @param[out] length - Number of bytes to be read/written
 *  @return pldm_completion_codes
 */
int decode_rw_file_by_type_memory_resp(const struct pldm_msg *msg,
				       size_t payload_length,
				       uint8_t *completion_code,
				       uint32_t *length);

/** @struct pldm_new_file_req
 *
 *  Structure representing NewFile request
 */
struct pldm_new_file_req {
	uint16_t file_type;   //!< Type of file
	uint32_t file_handle; //!< Handle to file
	uint32_t length;      //!< Number of bytes in new file
} __attribute__((packed));

/** @struct pldm_new_file_resp
 *
 *  Structure representing NewFile response data
 */
struct pldm_new_file_resp {
	uint8_t completion_code; //!< Completion code
} __attribute__((packed));

/** @brief Decode NewFileAvailable command request data
 *
 *  @param[in] msg - Pointer to PLDM request message
 *  @param[in] payload_length - Length of request payload
 *  @param[in] file_type - Type of the file
 *  @param[out] file_handle - A handle to the file
 *  @param[out] length - Number of bytes in new file
 *  @return pldm_completion_codes
 */
int decode_new_file_req(const struct pldm_msg *msg, size_t payload_length,
			uint16_t *file_type, uint32_t *file_handle,
			uint32_t *length);

/** @brief Create a PLDM response for NewFileAvailable
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] completion_code - PLDM completion code
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'
 */
int encode_new_file_resp(uint8_t instance_id, uint8_t completion_code,
			 struct pldm_msg *msg);

/** @brief Encode NewFileAvailable command request data
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] file_type - Type of the file
 *  @param[in] file_handle - A handle to the file
 *  @param[in] length -  Number of bytes in new file
 *  @param[out] msg - Message will be written to this
 *  @return pldm_completion_codes
 */
int encode_new_file_req(uint8_t instance_id, uint16_t file_type,
			uint32_t file_handle, uint32_t length,
			struct pldm_msg *msg);

/** @brief Decode NewFileAvailable command response data
 *
 *  @param[in] msg - pointer to PLDM response message
 *  @param[in] payload_length - Length of response payload
 *  @param[out] completion_code - PLDM completion code
 *  @return pldm_completion_codes
 */
int decode_new_file_resp(const struct pldm_msg *msg, size_t payload_length,
			 uint8_t *completion_code);

/** @struct pldm_read_write_file_by_type_req
 *
 *  Structure representing ReadFileByType and
 *  WriteFileByType request
 */
struct pldm_read_write_file_by_type_req {
	uint16_t file_type;   //!< Type of file
	uint32_t file_handle; //!< Handle to file
	uint32_t offset;      //!< Offset to file where read/write starts
	uint32_t length;      //!< Bytes to be read
} __attribute__((packed));

/** @struct pldm_read_write_file_by_type_resp
 *
 *  Structure representing ReadFileByType and
 *  WriteFileByType response
 */
struct pldm_read_write_file_by_type_resp {
    uint8_t completion_code; //!< Completion code
    uint32_t length;         //!< Number of bytes read
    uint8_t  file_data[1];   //!< Beginning of the file data
} __attribute__((packed));

/** @brief Decode ReadFileByType and WriteFileByType
 *  commands request data
 *
 *  @param[in] msg - Pointer to PLDM request message
 *  @param[in] payload_length - Length of request payload
 *  @param[out] file_type - Type of the file
 *  @param[out] file_handle - A handle to the file
 *  @param[out] offset - Offset to the file at which the read/write should begin
 *  @param[out] length - Number of bytes to be read/written
 *  @return pldm_completion_codes
 */
int decode_rw_file_by_type_req(const struct pldm_msg *msg,
			       size_t payload_length, uint16_t *file_type,
			       uint32_t *file_handle, uint32_t *offset,
			       uint32_t *length);

/** @brief Create a PLDM response for ReadFileByType and
 *  WriteFileByType
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] command - PLDM command
 *  @param[in] completion_code - PLDM completion code
 *  @param[in] length - Number of bytes read/written. This could be less than
 *                      what the requester asked for.
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'
 *  @note File content has to be copied directly by the caller.
 */
int encode_rw_file_by_type_resp(uint8_t instance_id, uint8_t command,
				uint8_t completion_code, uint32_t length,
				struct pldm_msg *msg);

/** @brief Encode ReadFileByType and WriteFileByType
 *         commands request data
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] command - PLDM command
 *  @param[in] file_type - Type of the file
 *  @param[in] file_handle - A handle to the file
 *  @param[in] offset -  Offset to the file at which the read should begin
 *  @param[in] length -  Number of bytes to be read/written
 *  @param[out] msg - Message will be written to this
 *  @param[in] payload_length - The length of the request in bytes
 *  @return pldm_completion_codes
 *  @note File content has to be read directly by the caller.
 */
int encode_rw_file_by_type_req(uint8_t instance_id, uint8_t command,
                               uint16_t file_type, uint32_t file_handle,
                               uint32_t offset, uint32_t length,
                               struct pldm_msg *msg, size_t payload_length);

/** @brief Decode ReadFileByType and WriteFileByType
 *         commands response data
 *
 *  @param[in] msg - pointer to PLDM response message
 *  @param[in] payload_length - Length of response payload
 *  @param[out] completion_code - PLDM completion code
 *  @param[out] length - Number of bytes to be read/written
 *  @param[out] file_data - The binary contents of the requested file. If
 *              file_data is NULL, length will still be set, but no data
 *              will be written to file_data.
 *  @return pldm_completion_codes
 */
int decode_rw_file_by_type_resp(const struct pldm_msg *msg,
                                size_t payload_length, uint8_t *completion_code,
                                uint32_t *length, uint8_t *file_data);

/** @struct pldm_file_ack_req
 *
 *  Structure representing FileAck request
 */
struct pldm_file_ack_req {
	uint16_t file_type;   //!< Type of file
	uint32_t file_handle; //!< Handle to file
	uint8_t file_status;  //!< Status of file processing
} __attribute__((packed));

/** @struct pldm_file_ack_resp
 *
 *  Structure representing NewFile response data
 */
struct pldm_file_ack_resp {
	uint8_t completion_code; //!< Completion code
} __attribute__((packed));

/** @brief Decode FileAck command request data
 *
 *  @param[in] msg - Pointer to PLDM request message
 *  @param[in] payload_length - Length of request payload
 *  @param[out] file_type - Type of the file
 *  @param[out] file_handle - A handle to the file
 *  @param[out] file_status - Status of file processing
 *  @return pldm_completion_codes
 */
int decode_file_ack_req(const struct pldm_msg *msg, size_t payload_length,
			uint16_t *file_type, uint32_t *file_handle,
			uint8_t *file_status);

/** @brief Create a PLDM response for FileAck
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] completion_code - PLDM completion code
 *  @param[in,out] msg - Message will be written to this
 *  @return pldm_completion_codes
 *  @note  Caller is responsible for memory alloc and dealloc of param 'msg'
 */
int encode_file_ack_resp(uint8_t instance_id, uint8_t completion_code,
			 struct pldm_msg *msg);

/** @brief Encode FileAck command request data
 *
 *  @param[in] instance_id - Message's instance id
 *  @param[in] file_type - Type of the file
 *  @param[in] file_handle - A handle to the file
 *  @param[in] file_status - Status of file processing
 *  @param[out] msg - Message will be written to this
 *  @return pldm_completion_codes
 */
int encode_file_ack_req(uint8_t instance_id, uint16_t file_type,
			uint32_t file_handle, uint8_t file_status,
			struct pldm_msg *msg);

/** @brief Decode FileAck command response data
 *
 *  @param[in] msg - pointer to PLDM response message
 *  @param[in] payload_length - Length of response payload
 *  @param[out] completion_code - PLDM completion code
 *  @return pldm_completion_codes
 */
int decode_file_ack_resp(const struct pldm_msg *msg, size_t payload_length,
			 uint8_t *completion_code);

#ifdef __cplusplus
}
#endif

#endif /* FILEIO_H */
