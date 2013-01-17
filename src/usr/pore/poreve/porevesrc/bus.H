/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/bus.H $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __VSBE_BUS_H
#define __VSBE_BUS_H

// $Id: bus.H,v 1.16 2012/12/06 18:03:51 bcbrock Exp $

/// \file bus.H
/// \brief PoreVe bus and base device models

#include <fapi.H>
#include "transaction.H"


namespace vsbe
{

class Slave;
class Memory;

// Temporary FAPI return codes from getscom/putscom errors
#define fapi_PCB_RESOURCE_BUSY 0x02014003
#define fapi_PCB_OFFLINE_ERROR 0x02014005
#define fapi_PCB_PARTIAL_ERROR 0x02014007
#define fapi_PCB_ADDRESS_ERROR 0x02014009
#define fapi_PCB_CLOCK_ERROR   0x0201400B
#define fapi_PCB_PARITY_ERROR  0x0201400D
#define fapi_PCB_TIMEOUT_ERROR 0x0201400F

//-----------------------------------------------------------------------------
/*!
The Pore hardware engine is connected via PIB bus and OCI bus. The Bus object
functions to group all entities on the bus. For example, the PIB has the ability
to run put/getscom via the PibSlave, as well as access OTPROM memory via the 
PibMemory object and PNOR and SEEPROM via FastI2cMemory objects.
*/
/// All pore hardware bus transactions are submitted through a Bus object.
class Bus
{

public:

    Bus();
    virtual ~Bus();

    /*! Primary Slaves are searched first for a given Transaction Address */
    /// Primary Slaves are a linked list of Slave based objects
    void attachPrimarySlave(Slave* i_slave);

    /*! If a Secondary slave cannot service the Transaction then the Transaction address
    is not mapped on the bus at all. */
    /// Secondary Slaves are searched only if a Primary Slave did not support the Transaction Address
    void attachSecondarySlave(Slave* i_slave);

    /*! Detach the slave from the bus if it is mapped on either the primary or
      secondary bus; Otherwise return the generic error ME_FAILURE */
    ModelError detachSlave(Slave* i_slave);
                              
    /*!
    The PrimarySlaves attached to the bus are checked to find one that handles the  
    Transaction address. If no match, then the SecondarySlaves are checked. When a  
    Slave is found containing the address the Transaction::iv_offset is set to the  
    Transaction::iv_address - Slave::iv_base. The Slave operation method is then
    executed.

    The return code from the Slave is passed back and becomes the return code of the
    Bus operation. The Transaction ModelError is set by the Slave and is passed back
    as well.

    @returns If any error occurs then the fapi::ReturnCode is not ok, and the       
    transaction ModelError indicates the kind of problem found.

    @returns rc=1 and Transaction ModelError=ME_NOT_MAPPED_ON_BUS if neither Primary
    nor Secondary Slaves have mapped the transaction address.

    @returns rc=1 and Transaction ModelError=ME_BUS_SLAVE_PERMISSION_DENIED if the  
    transaction address is found on a Slave but the Slave permissions deny the      
    transaction mode.

    @returns rc=1 and Transaction ModelError= some other Model Error codes if the   
    Slave operation fails.

    @returns rc=0 and Transaction ModelError=ME_SUCCESS if the transaction was      
    successful.
    */
    /// The basic method called to get a bus transaction done.
    fapi::ReturnCode operation(Transaction& io_transaction);


protected:

    /// Primary list of "attached" bus elements like PibMemory, OciMemory and so forth
    Slave* iv_primarySlaves;

    /// The Secondary list is used when the Primary list fails to contain a Transaction address
    Slave* iv_secondarySlaves;

    /// Detach a slave from a slave list or else return ME_FAILURE.
    ModelError removeSlaveFromList(Slave* i_slave, Slave** i_slaves);
};

//-----------------------------------------------------------------------------
/*!
Any kind of object attached to a Bus must be based upon the Slave class.
Each of the Bus devices must specify their base address, size, and permissions
as well as target and dataBuffer to be used for bus transactions. All these attributes
are defined by the base Slave class.
*/
/// The Slave object contains the common attributes of all bus devices.
class Slave
{
public:

    Slave();
    virtual ~Slave();

    /// Slave based objects must be configured before use.
    virtual void configure(fapi::Target* i_target,
                           ecmdDataBufferBase *i_dataBuffer,
                           uint32_t i_base,
                           uint64_t i_size,
                           int i_permissions);

    /*!
    Notice that the operation is pure virtual in the Slave class. All derived bus attached
    devices must define their own operation methods since they vary from one to the other.
    */
    /// The Slave class also defines the fundamental operation that a Bus can call.
    virtual fapi::ReturnCode operation(Transaction& io_transaction) = 0; // the slave instance will implement

    /*!
    The iv_base address is specified in terms of the system, so for example it might be the first address
    in a range beginning at 0x08000000 in the system memory, or it might be the first address in a range of
    scom addresses in the system.
    */
    /// The Bus devices base address. A System memory address or scom address, not an offset.
    uint32_t iv_base;

    /// This specifies the number of bytes from the iv_base that this Bus device responds to.
    uint64_t iv_size;

    /*!
    For example: ACCESS_MODE_READ | ACCESS_MODE_WRITE | ACCESS_MODE_EXECUTE
    */
    /// Establish the read/write/execute mode allowed upon this Bus device.
    int iv_permissions;

    /// Points to the next Slave in a linked list that the Bus::operation will search
    Slave* iv_next;

    /// A pointer to the fapi Target to be used when accessing this Bus device.
    fapi::Target* iv_target;

    /// A pointer to the fapi DataBuffer to be used when accessing this Bus device.
    ecmdDataBufferBase* iv_dataBuffer;


};


//-----------------------------------------------------------------------------
/*!
The SCOM addresses of a system are defined by a call to configure to the PIB    
slave for the system. There is no mapping done since there is no memory manager 
involved. When the PIB bus manager is asked to perform an operation and if the      
Transaction iv_address falls into the address range of the SCOM's then the      
operation method for the Slave will be called, which will call the           
PibSlave::getScom/putScom implemnted with fapiGet/Putscom.
*/
/// Implements SCOM access to the system.
class PibSlave : public Slave
{
public:

    PibSlave();
    virtual ~PibSlave();

    /// Inherits Slave::operation implementation
    virtual fapi::ReturnCode operation(Transaction& io_transaction);

protected:

    /*!
    The i_offset is an actual scom address that has not been changed to implement   
    "core reduction" as an eCMD address might for certain chiplets. The address is  
    the raw native SCOM address used by the hardware.

    The calling Slave class object iv_target and iv_dataBuffer are used to perform  
    the operation.

    @returns rc= the value returned by fapi::GetScom
    */
    /// PibSlave read calls fapi::GetScom
    fapi::ReturnCode getScom(const uint32_t i_offset, uint64_t& o_data);

    /*!
    The i_offset is an actual scom address that has not been changed to implement   
    "core reduction" as an eCMD address might for certain chiplets. The address is  
    the raw native SCOM address used by the hardware.

    The calling Slave class object iv_target and iv_dataBuffer are used to perform  
    the operation.

    @returns rc= the value returned by fapi::PutScom
    */
    /// PibSlave write calls fapi::PutScom
    fapi::ReturnCode putScom(const uint32_t i_offset, const uint64_t i_data);
};

//-----------------------------------------------------------------------------
/*!
This object has (virtual) methods to handle directly access memory.
*/
/// Methods Used to access OTPROM.
class PibMemory : public PibSlave
{
public:

    PibMemory();
    virtual ~PibMemory();


    /// Slave based objects must be configured before use.
    virtual void configure(fapi::Target* i_target,
                           ecmdDataBufferBase *i_dataBuffer,
                           uint32_t i_base,
                           uint64_t i_size,
                           int i_permissions,
                           Memory* i_memory);

    /*!
    Pass-through mode is established with a true value. This mode means that if a 
    PibMemory address is NOT_MAPPED_IN_MEMORY then the address of a transaction is
    passed-through to the PibSlave::getScom or PibSlave::putScom method for resolution.
    */
    /// Control the pass-through mode. True means pass-through mode is enabled.
    void setPassThrough(const bool i_enable);

    /*!
    Bus::operation already made sure the Transaction address is within our chunk of 
    memory and has set the Transaction::iv_offset.

    This operation accesses direct memory, like OTPROM.

    Transactions give us addresses on 64bit , or 8 byte, boundries. The address     
    passed into Memory::read or write is calculated as the Transaction::iv_offset * 
    8. So, as example, if the Transaction::_iv_address was 0x08000000 and the       
    PibMemory Slave::iv_base were configured to 0x08000000 then the                 
    Transaction::iv_offset would be 0x00000000. That multiplied by 8 remains        
    0x00000000. If the Transaction address were 0x08000001, then the Transaction    
    offset would be 0x00000001, and that multiplied by 8 would be 0x00000008, the   
    reall offset into the eprom image we will read or write from.

    If a ACCESS_MODE_READ transaction is called for then the Memory::read method is 
    called passing the Transaction iv_offset to complete the operation. If Memory::read
    returns ME_NOT_MAPPED_IN_MEMORY and if iv_passThrough is true then              
    PibSlave::getScom is called passing the Transaction iv_address.

    If a ACCESS_MODE_READ transaction is called for then the Memory::write method is 
    called passing the Transaction iv_offset to complete the operation. If Memory::write
    returns ME_NOT_MAPPED_IN_MEMORY and if iv_passThrough is true then              
    PibSlave::putScom is called passing the Transaction iv_address.

    @returns rc=0 if transaction succeeded
    @returns rc=1 if transaction failed and passThrough mode was not active
    @returns rc!=0 if read/write failed and passThrough call to getScom/putScom also
    failed. In this case the rc value is whatever getScom or putScom returns from   
    fapi.

    */
    /// Implement a PibMemory transaction. Called by the Bus::operation()
    virtual fapi::ReturnCode operation(Transaction& io_transaction);

protected:

    /// Remember the pass-through mode setting
    bool iv_passThrough;

    /// Pointer to Memory manager storing a linked list of MemoryImage (s) "containing" mapped memory areas
    Memory* iv_memory;

};

//-----------------------------------------------------------------------------
/// Not sure what a OciSlave does yet
class OciSlave : public Slave
{
public:

    virtual ~OciSlave();

    /*!
    Bus::operation already made sure the Transaction address is within our chunk of 
    memory and has set the Transaction::iv_offset.

    If a ACCESS_MODE_READ transaction is called for then the OciSlave::read method is 
    called passing the Transaction iv_address to complete the operation.

    If a ACCESS_MODE_WRITE transaction is called for then the OciSlave::write method is 
    called passing the Transaction iv_address to complete the operation.

    @returns rc=0 if transaction succeeded
    @returns rc=1 if transaction failed

    */
    virtual fapi::ReturnCode operation(Transaction& io_transaction);

protected:

    /*!
    Called by OciSlave::operation.
    */
    virtual fapi::ReturnCode read(const uint32_t i_address, uint64_t& o_data);

    /*!
    Called by OciSlave::operation.
    */
    virtual fapi::ReturnCode write(const uint32_t i_address, const uint64_t i_data);

};

//-----------------------------------------------------------------------------
/// An OciSlave that accepts and simply swallows write transactions
class OciSlaveWritable : public OciSlave
{
public:
    virtual fapi::ReturnCode write(const uint32_t i_address, const uint64_t i_data);
};

//-----------------------------------------------------------------------------
/// Methods Used to access Mainstore/SRAM
class OciMemory : public OciSlave
{
public:
    
    OciMemory();
    virtual ~OciMemory();

    /// Slave based objects must be configured before use.
    virtual void configure(fapi::Target* i_target,
                           ecmdDataBufferBase *i_dataBuffer,
                           uint32_t i_base,
                           uint64_t i_size,
                           int i_permissions,
                           Memory* i_memory);

    /*!
    Bus::operation already made sure the Transaction address is within our chunk of 
    memory and has set the Transaction::iv_offset.

    This operation accesses memory like Mainstore or SRAM memory.

    Transactions to the OCI bus give us addresses on byte boundries. The offset    
    passed into Memory::read or write is therefore simply the                       
    Transaction::iv_offset without modification.

    If a ACCESS_MODE_READ transaction is called for then the Memory::read method is 
    called passing the Transaction iv_offset to complete the operation. If Memory::read
    returns ME_NOT_MAPPED_IN_MEMORY and if iv_passThrough is true then              
    OciSlave::read is called passing the Transaction iv_address.

    If a ACCESS_MODE_READ transaction is called for then the Memory::write method is 
    called passing the Transaction iv_offset to complete the operation. If Memory::write
    returns ME_NOT_MAPPED_IN_MEMORY and if iv_passThrough is true then              
    OciSlave::write is called passing the Transaction iv_address.

    @returns rc=0 if transaction succeeded
    @returns rc=1 if transaction failed and passThrough mode was not active
    @returns rc!=0 if read/write failed and passThrough call to OciSlave::read/write also
    failed. In this case the rc value is whatever OciSlave::read  or OciSlave::write  returns.
    */
    /// Implement a OciMemory transaction. Called by the Bus::operation()
    virtual fapi::ReturnCode operation(Transaction& io_transaction);

    /*!
    Pass-through mode is established with a true value. This mode means that if a 
    OciMemory address is NOT_MAPPED_IN_MEMORY then the address of a transaction is
    passed-through to the OciSlave::read or OciSlave::write method for resolution.
    */
    /// Control the pass-through mode. True means pass-through mode is enabled.
    void setPassThrough(const bool i_enable);

    /// Pointer to Memory manager storing a linked list of MemoryImage (s) "containing" mapped memory areas
    Memory *iv_memory;

protected:

    /// Remember the pass-through mode setting
    bool iv_passThrough;
};


//-----------------------------------------------------------------------------
/// Store details of a block of memory being managed by a Memory manager
class MemoryImage
{
public:
    
    /*!
    A MemoryImage is used to store information about a portion of Memory that has been mapped.
    It is created by the Memory::map method.

    @param i_base A zero based offset from the Slave iv_base address
    @param i_size Size of i_image in bytes
    @param i_permissions The read/write/execute permissions over this block of memory
    @param i_image A pointer to an allocated block of memory storing the content of the block of memory
    @param i_crcEnable true or false indicating whether crc is to be calculated over the block of memory
    */
    MemoryImage(uint32_t     i_base,
                size_t       i_size,
                int          i_permissions,
                void*        i_image,
                bool         i_crcEnable );

    virtual ~MemoryImage();

    /*!
    When this method is called the crc of the associated MemoryImage is calculated  
    and compared to iv_originalCrc which was the crc value at the time that the     
    MemoryImage was mapped into the Memory.

    @returns true if iv_originalCrc == the current crc of the MemoryImage or if crc
    checking is not enabled for the MemoryImage.
    @returns false if crc checking is enabled and the crc values do not match.
    */
    /// true if iv_originalCrc == current crc, or if iv_crcEnable == false
    virtual bool checkCrc();

    /// Dump this memory image to the FAPI_ERR stream.
    virtual void dump(void);

    /// base address associated with iv_image in the system (not real address of iv_image)
    uint32_t iv_base;

    /// byte size of the block of memory pointed to by iv_image
    size_t   iv_size;

    /// Access permissions over this block of memory (ACCESS_MODE_READ | ACCESS_MODE_WRITE | ACCESS_MODE_EXECUTE)
    int      iv_permissions;

    /// Pointer to the chunk of memory a user has allocated and stored eprom image into
    void*    iv_image;

    /// Remember if told to compute crc or not via i_crcEnable
    bool     iv_crcEnable;

    /// Link to next MemoryImage in the Memory managers circular linked list
    MemoryImage* iv_next;

protected:

    /// Method to calculate crc over iv_image
    virtual uint64_t computeCrc();

    /// If iv_crcEnable is true this is the calculated crc over iv_image at the time it was mapped into Memory
    uint64_t iv_originalCrc;
};

//-----------------------------------------------------------------------------
/// Contains one or many MemoryImages for a certain type of memory
class Memory
{
public:
    
    Memory();
    virtual ~Memory();

    /*!
    The map method is used to register a pointer to a contiguous block of memory    
    that contains some part of an eeprom image, as well as to declare the offset    
    from the system base address, the size, and access permissions of that block of 
    memory.

    The iv_images pointer of the Memory manager points to one or many MemoryImages. 
    Each time this map method is called a new MemoryImage object is created to      
    remember all the details about the i_image being passed in. The new MemoryImage
    is placed into a circular linked list owned by the Memory manager.

    The Memory manager is always associated with a particuliar kind of memory, like 
    PibMemory or OciMemory, so the i_image is some portion of PibMemory or          
    OciMemory. As an example, suppose OTPROM is 0x01000000 bytes in the system,     
    starting at address 0x80000000. Also suppose you have parts of the OTPROM from  
    0x80000000 to 0x80000100 and from 0x80010000 to 0x80010500 in two image files   
    that you have read into program memory and you want to map into the OTPROM      
    Memory manager. When calling the configure method on the PibMemory you declare  
    OTPROM memory starts at 0x80000000 and has 0x01000000 bytes. Then you call map  
    on the PibMemory manager twice, first declaring an offset 0x00000000 for        
    0x00000100 bytes, then again with offset 0x00010000 for 0x00000500 bytes.

    @param i_base A zero based offset from the Slave iv_base address
    @param i_size Size of i_image in bytes
    @param i_permissions The read/write/execute permissions over this block of memory
    @param i_image A pointer to an allocated block of memory storing the content of the block of memory
    @param i_crcEnable true or false indicating whether crc is to be calculated over the block of memory
    @returns ME_SUCCESS if all's well (currently that's all it can return)
    */
    /// Register a "chunk" of memory to the Memory manager
    virtual ModelError map(uint32_t i_base,
                           size_t i_size,
                           int i_permissions,
                           void* i_image,
                           bool i_crcEnable);

    /*!
    This method runs through every MemoryImage checking its crc. 

    @returns true if all MemoryImage have the same crc as when they were originally mapped into Memory
    @returns false if any MemoryImage has a crc that is different
    */
    /// Check if crc of all MemoryImages is still the same as when it was originally mapped into Memory
    virtual bool checkCrc();

    /*!
    This method is used to read Direct Memory out of an eprom image. An offset from 
    the base of the eprom memory image is passed in for the access, along with the  
    number of bytes to read.

    The memory storage may be split into more than one MemoryImage's that have been
    mapped. This method runs through the circuliarly linked list of MemoryImage objects
    looking for one that contains the block of memory being accessed.

    Upon successfully finding a containing MemoryImage the Memory::iv_images is set 
    to point to the MemoryImage just found. This should speed up operation assuming 
    a large number of transactions might occur on contiguous blocks of memory.

    The data are copied out of the MemoryImage::iv_image into the o_data buffer for 
    return. The Endianess of the host platform being used is considered as this     
    operation occurs. (It is assumed the MemoryImage::iv_image is stored in         
    BigEndian order.)

    @returns If there is no MemoryImage that contains the block of memory requested 
    then ME_NOT_MAPPED_IN_MEMORY is returned.

    @returns If the memory block is found within a MemoryImage but the              
    MemoryImage::iv_permissions do not permit ACCESS_MODE_READ then                 
    ME_MEMORY_IMAGE_PERMISSION_DENIED is returned.

    @returns ME_SUCCESS if all bytes of the memory requested are contained in the   
    MemoryImage and the permissions of the MemoryImage allow ACCESS_MODE_READ.

    */
    /// Used to find a MemoryImage from which to read data
    virtual ModelError read(uint32_t i_offset, 
                            uint64_t& o_data,
                            size_t i_size
                            );

    /*!
    This method is used to fetch instructions from Direct Memory out of an eprom    
    image. An offset from the base of the eprom memory image is passed in for the   
    access, along with the number of bytes to read.

    The memory storage may be split into more than one MemoryImage's that have been
    mapped. This method runs through the circuliarly linked list of MemoryImage objects
    looking for one that contains the block of memory being accessed.

    Upon successfully finding a containing MemoryImage the Memory::iv_images is set 
    to point to the MemoryImage just found. This should speed up operation assuming 
    a large number of transactions might occur on contiguous blocks of memory.

    The data are copied out of the MemoryImage::iv_image into the o_data buffer for 
    return. The Endianess of the host platform being used is considered as this     
    operation occurs. (It is assumed the MemoryImage::iv_image is stored in         
    BigEndian order.)

    @returns If there is no MemoryImage that contains the block of memory requested 
    then ME_NOT_MAPPED_IN_MEMORY is returned.

    @returns If the memory block is found within a MemoryImage but the              
    MemoryImage::iv_permissions do not permit ACCESS_MODE_EXECUTE then              
    ME_MEMORY_IMAGE_PERMISSION_DENIED is returned.

    @returns ME_SUCCESS if all bytes of the memory requested are contained in the   
    MemoryImage and the permissions of the MemoryImage allow ACCESS_MODE_EXECUTE.

    */
    /// Used to find a MemoryImage from which to fetch instructions
    virtual ModelError fetch(uint32_t i_offset, 
                            uint64_t& o_data,
                            size_t i_size
                            );

    /*!
    This method is used to write Direct Memory out of an eprom image. An offset from 
    the base of the eprom memory image is passed in for the access, along with the  
    number of bytes to write.

    The memory storage may be split into more than one MemoryImage's that have been
    mapped. This method runs through the circuliarly linked list of MemoryImage objects
    looking for one that contains the block of memory being accessed.

    Upon successfully finding a containing MemoryImage the Memory::iv_images is set 
    to point to the MemoryImage just found. This should speed up operation assuming 
    a large number of transactions might occur on contiguous blocks of memory.

    The data are copied out of the i_data buffer into the MemoryImage::iv_image. The
    Endianess of the host platform being used is considered as this operation       
    occurs. (It is assumed the MemoryImage::iv_image is stored in BigEndian order.)

    @returns If there is no MemoryImage that contains the block of memory requested 
    then ME_NOT_MAPPED_IN_MEMORY is returned.

    @returns If the memory block is found within a MemoryImage but the              
    MemoryImage::iv_permissions do not permit ACCESS_MODE_WRITE then                 
    ME_MEMORY_IMAGE_PERMISSION_DENIED is returned.

    @returns ME_SUCCESS if all bytes of the memory requested are contained in the   
    MemoryImage and the permissions of the MemoryImage allow ACCESS_MODE_WRITE.

    */
    /// Used to find a MemoryImage to change
    virtual ModelError write(uint32_t i_offset, 
                             uint64_t i_data,
                             size_t i_size);

    /// Dump the list of memory images to the FAPI_ERR stream.
    virtual void dump(void);

    /// Pointer to first MemoryImage in a circularly linked list
    MemoryImage* iv_images;
    
#if POREVE_STATISTICS

    /// Reset Memory usage statistics
    ///
    /// This API clears the instance variables iv_reads, iv_writes and
    /// iv_fetches. 
    void
    resetStatistics();

    /// Number of read() calls for this memory
    uint64_t iv_reads;

    /// Number of write() calls for this memory
    uint64_t iv_writes;

    /// Number of fetch() calls for this memory
    uint64_t iv_fetches;

#endif // POREVE_STATISTICS

};









} // end of namespace vsbe
#endif
