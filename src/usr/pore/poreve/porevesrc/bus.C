//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/porevesrc/bus.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: bus.C,v 1.22 2012/01/05 23:15:54 bcbrock Exp $

/// \file bus.C
/// \brief PoreVe bus and base device models

#include "bus.H"
#include <fapi.H>
#include <transaction.H>



using namespace vsbe;

//-----------------------------------------------------------------------------
Bus::Bus() :
    iv_primarySlaves(NULL),
    iv_secondarySlaves(NULL)
{
}

//-----------------------------------------------------------------------------
Bus::~Bus()
{
}

//-----------------------------------------------------------------------------
void 
Bus::attachPrimarySlave(Slave* i_slave)
{
    if( iv_primarySlaves == 0 )
    {
        i_slave->iv_next = 0;
    }else{
        i_slave->iv_next = iv_primarySlaves;
    }
    iv_primarySlaves = i_slave;
}

//-----------------------------------------------------------------------------
void 
Bus::attachSecondarySlave(Slave* i_slave)
{
    if( iv_secondarySlaves == 0 )
    {
        i_slave->iv_next = 0;
    }else{
        i_slave->iv_next = iv_secondarySlaves;
    }
    iv_secondarySlaves = i_slave;
}


//-----------------------------------------------------------------------------
fapi::ReturnCode 
Bus::operation(Transaction& trans)
{
    fapi::ReturnCode rc;
    Slave*           slave= 0;

    do
    {
        for( slave = iv_primarySlaves; slave; slave = slave->iv_next )
        {
            if( (trans.iv_address >= slave->iv_base) && (trans.iv_address < (slave->iv_base + slave->iv_size) ) )
            {
              break; // found a primary slave
            }
        }

        if( slave == 0 )
        { // primary slaves did not hold the transaction address. Try using the secondary slaves.
          for( slave = iv_secondarySlaves; slave; slave = slave->iv_next )
          {
              if( (trans.iv_address >= slave->iv_base) && (trans.iv_address < (slave->iv_base + slave->iv_size) ) )
              {
                break; // found a secondary slave
              }
          }
        }

        break;

    }while(0);

    do
    {
        if( slave == 0 ) // neither primary nor secondary slaves held the address
        {
          trans.busError(ME_NOT_MAPPED_ON_BUS);
          rc= 1;
          break;
        }

        if( (trans.iv_mode & slave->iv_permissions) == 0 ){
          trans.busError(ME_BUS_SLAVE_PERMISSION_DENIED);
          rc= 1;
          break;
          }

        trans.iv_offset = trans.iv_address - slave->iv_base;
        rc = slave->operation( trans );
        break;
    }while(1);

    return rc;
}

//-----------------------------------------------------------------------------
Slave::Slave()
:iv_base(0), iv_size(0), iv_permissions(0),
iv_next(NULL), iv_target(NULL), iv_dataBuffer(NULL)
{

}

//-----------------------------------------------------------------------------
Slave::~Slave()
{
}

//-----------------------------------------------------------------------------
PibSlave::PibSlave()
{
}

//-----------------------------------------------------------------------------
PibSlave::~PibSlave()
{
}

//-----------------------------------------------------------------------------
fapi::ReturnCode 
PibSlave::operation(Transaction& io_transaction)
{
    fapi::ReturnCode rc;
    PibTransaction* pt = (PibTransaction*)&io_transaction;

    if( io_transaction.iv_mode & ACCESS_MODE_READ )
    {
        rc = getScom( io_transaction.iv_address, io_transaction.iv_data );
    }
    else
    {
        rc = putScom( io_transaction.iv_address, io_transaction.iv_data );
    }

    if( rc.ok() )
    {
        pt->iv_pcbReturnCode = PCB_SUCCESS;
    }
    else
    {
        if( rc & fapi_PCB_RESOURCE_BUSY ){
            pt->iv_pcbReturnCode = PCB_RESOURCE_OCCUPIED;
        }else if( rc & fapi_PCB_OFFLINE_ERROR ){
            pt->iv_pcbReturnCode = PCB_CHIPLET_OFFLINE;
        }else if( rc & fapi_PCB_PARTIAL_ERROR ){
            pt->iv_pcbReturnCode = PCB_PARTIAL_GOOD;
        }else if( rc & fapi_PCB_ADDRESS_ERROR ){
            pt->iv_pcbReturnCode = PCB_ADDRESS_ERROR;
        }else if( rc & fapi_PCB_CLOCK_ERROR ){
            pt->iv_pcbReturnCode = PCB_CLOCK_ERROR;
        }else if( rc & fapi_PCB_PARITY_ERROR ){
            pt->iv_pcbReturnCode = PCB_PACKET_ERROR;
        }else if( rc & fapi_PCB_TIMEOUT_ERROR ){
            pt->iv_pcbReturnCode = PCB_TIMEOUT;
        }else{
            pt->iv_pcbReturnCode = PCB_TIMEOUT;
          }
        rc = 0;
    }

    io_transaction.iv_modelError = ME_SUCCESS;
    return rc;
}


//-----------------------------------------------------------------------------
void 
Slave::configure(
    fapi::Target*       i_target,
    ecmdDataBufferBase* i_dataBuffer,
    uint32_t            i_base,
    uint64_t            i_size,
    int                 i_permissions
    )
{
    iv_target      = i_target;
    iv_dataBuffer  = i_dataBuffer;
    iv_base        = i_base;
    iv_size        = i_size;
    iv_permissions = i_permissions;
    iv_next        = NULL;
}



//-----------------------------------------------------------------------------
fapi::ReturnCode 
PibSlave::getScom(const uint32_t i_offset, uint64_t& o_data)
{
    fapi::ReturnCode rc;
    rc = fapiGetScom( *iv_target, i_offset, *iv_dataBuffer );
    o_data = iv_dataBuffer->getDoubleWord( 0 );

    return rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode 
PibSlave::putScom(const uint32_t i_offset, const uint64_t i_data)
{
    fapi::ReturnCode rc;
    iv_dataBuffer->setDoubleWordLength( 1 );
    iv_dataBuffer->setDoubleWord( 0, i_data );
    rc = fapiPutScom( *iv_target, i_offset, *iv_dataBuffer );

    return rc;
}


//-----------------------------------------------------------------------------
PibMemory::PibMemory() :
iv_passThrough(false),iv_memory(NULL)
{
}

//-----------------------------------------------------------------------------
PibMemory::~PibMemory()
{
}

//-----------------------------------------------------------------------------
void 
PibMemory::setPassThrough(const bool i_enable)
{
    iv_passThrough = i_enable;
}

//-----------------------------------------------------------------------------
void 
PibMemory::configure(
    fapi::Target*       i_target,
    ecmdDataBufferBase* i_dataBuffer,
    uint32_t            i_base,
    uint64_t            i_size,
    int                 i_permissions,
    Memory*             i_memory
    )
{
    iv_target      = i_target;
    iv_dataBuffer  = i_dataBuffer;
    iv_base        = i_base;
    iv_size        = i_size;
    iv_permissions = i_permissions;
    iv_memory      = i_memory;
    iv_next        = NULL;
}


//-----------------------------------------------------------------------------
// 
fapi::ReturnCode 
PibMemory::operation(Transaction& io_transaction)
{
    fapi::ReturnCode rc;
    ModelError       me;

    if( io_transaction.iv_mode & ACCESS_MODE_READ )
    {
        me = iv_memory->read( (uint32_t)(io_transaction.iv_offset * TRANSACTION_SIZE_IN_BYTES), io_transaction.iv_data, TRANSACTION_SIZE_IN_BYTES );
        if( me == ME_NOT_MAPPED_IN_MEMORY && iv_passThrough )
        {
            rc = getScom( io_transaction.iv_address, io_transaction.iv_data );
            if( rc.ok() )
            {
                me = ME_SUCCESS;
            }
            else
            {
                me = ME_FAILURE;
            }
        }
    }
    else if( io_transaction.iv_mode & ACCESS_MODE_WRITE )
    {
        me = iv_memory->write( (uint32_t)(io_transaction.iv_offset * TRANSACTION_SIZE_IN_BYTES), io_transaction.iv_data, TRANSACTION_SIZE_IN_BYTES );
        if( me == ME_NOT_MAPPED_IN_MEMORY && iv_passThrough )
        {
            rc = putScom( io_transaction.iv_address, io_transaction.iv_data );
            if( rc.ok() )
            {
                me = ME_SUCCESS;
            }
            else
            {
                me = ME_FAILURE;
            }
        }
    }
    else
    {
        me = iv_memory->fetch( (uint32_t)(io_transaction.iv_offset * TRANSACTION_SIZE_IN_BYTES), io_transaction.iv_data, TRANSACTION_SIZE_IN_BYTES );
        if( me == ME_NOT_MAPPED_IN_MEMORY && iv_passThrough )
        {
            rc = getScom( io_transaction.iv_address, io_transaction.iv_data );
            if( rc.ok() )
            {
                me = ME_SUCCESS;
            }
            else
            {
                me = ME_FAILURE;
            }
        }
    }

    io_transaction.busError( me );

    if( me == ME_SUCCESS )
    {
        rc = (uint32_t)0; // if read/write or getScom/putScom succeeded then set rc = 0
    }

    // if read/write failed then rc == 1 by default
    // if read/write returned ME_NOT_MAPPED_IN_MEMORY && pass through true then rc == value returned from putScom or getScom

    return rc;
}


//-----------------------------------------------------------------------------
Memory::Memory() :
    iv_images(0)
{
#if POREVE_STATISTICS
    resetStatistics();
#endif
}

//-----------------------------------------------------------------------------
Memory::~Memory()
{
}

//-----------------------------------------------------------------------------
bool 
Memory::checkCrc()
{
    MemoryImage* mi = iv_images;
    bool         rc = true;

    do{

      if( mi->checkCrc() == false )
      {
        rc = false;
        break;
      }
      mi = mi->iv_next;

    }while( mi != iv_images );

    return rc;
}


//-----------------------------------------------------------------------------
ModelError 
Memory::read(
    uint32_t  i_offset,
    uint64_t& o_data,
    size_t    i_size
    )
{
    char*        from_ptr;
    char*        to_ptr;
    size_t       cnt;
    MemoryImage* mi;
    ModelError   me;
    int          mi_found;

    o_data = 0; // Assure all bytes are cleared

    me = ME_SUCCESS;
    do{
			if( iv_images == 0 )
			{
					me = ME_NOT_MAPPED_IN_MEMORY;
					break;
			}
      mi       = iv_images;
      mi_found = 0;
      do{

        if( (i_offset >= mi->iv_base) && ((i_offset + i_size) <= (mi->iv_base + mi->iv_size) ) )
        {
            mi_found= 1;
            iv_images = mi; // have the Memory always point to the last MemoryImage that was used
            break;          // we found a chunk of memory containing the transaction address
        }
        mi = mi->iv_next;

      }while( mi != iv_images );

      if( ! mi_found )
      { // There was no MemoryImage that contained the transaction address
        me = ME_NOT_MAPPED_IN_MEMORY;
        break;
      }

      if( (mi->iv_permissions & ACCESS_MODE_READ ) == 0 )
      { // The permissions over the memory block do not allow the mode being used by the transaction
        me = ME_MEMORY_IMAGE_PERMISSION_DENIED;
        break;
      }

      // Init the character pointer into the eprom image we are using.
      from_ptr = (char*)mi->iv_image + (i_offset - mi->iv_base);

      // Init the character pointer into the o_data buffer.
      // Take care of Endianess by moving to one or the other end of the buffer as appropriate.
#ifdef _BIG_ENDIAN
        to_ptr   = (char*)&o_data + (TRANSACTION_SIZE_IN_BYTES - i_size);
#else
        to_ptr   = ((char*)&o_data + i_size -1);
#endif

      for( cnt = 0; cnt < i_size; cnt++ )
      {
        *to_ptr = *from_ptr++;

        // Move the to pointer either forward or backward as appropriate for Endianess
#ifdef _BIG_ENDIAN
        to_ptr++;
#else
        to_ptr--;
#endif
      }

      me = ME_SUCCESS;
      break;
    }while(1);

#if POREVE_STATISTICS
        iv_reads++;
#endif

    return me;
}

//-----------------------------------------------------------------------------
ModelError 
Memory::fetch(
    uint32_t  i_offset,
    uint64_t& o_data,
    size_t    i_size
    )
{
    char*        from_ptr;
    char*        to_ptr;
    size_t       cnt;
    MemoryImage* mi;
    ModelError   me;
    int          mi_found;

    o_data = 0; // Assure all bytes are cleared

    me = ME_SUCCESS;
    do{
			if( iv_images == 0 )
			{
					me = ME_NOT_MAPPED_IN_MEMORY;
					break;
			}
      mi       = iv_images;
      mi_found = 0;
      do{

        if( (i_offset >= mi->iv_base) && ((i_offset + i_size) <= (mi->iv_base + mi->iv_size) ) )
        {
            mi_found= 1;
            iv_images = mi; // have the Memory always point to the last MemoryImage that was used
            break;          // we found a chunk of memory containing the transaction address
        }
        mi = mi->iv_next;

      }while( mi != iv_images );

      if( ! mi_found )
      { // There was no MemoryImage that contained the transaction address
        me = ME_NOT_MAPPED_IN_MEMORY;
        break;
      }

      if( (mi->iv_permissions & ACCESS_MODE_EXECUTE ) == 0 )
      { // The permissions over the memory block do not allow the mode being used by the transaction
        me = ME_MEMORY_IMAGE_PERMISSION_DENIED;
        break;
      }

      // Init the character pointer into the eprom image we are using.
      from_ptr = (char*)mi->iv_image + i_offset;

      // Init the character pointer into the o_data buffer.
      // Take care of Endianess by moving to one or the other end of the buffer as appropriate.
#ifdef _BIG_ENDIAN
        to_ptr   = (char*)&o_data + (TRANSACTION_SIZE_IN_BYTES - i_size);
#else
        to_ptr   = ((char*)&o_data + i_size -1);
#endif

      for( cnt = 0; cnt < i_size; cnt++ )
      {
        *to_ptr = *from_ptr++;

        // Move the to pointer either forward or backward as appropriate for Endianess
#ifdef _BIG_ENDIAN
        to_ptr++;
#else
        to_ptr--;
#endif
      }

      me = ME_SUCCESS;
      break;
    }while(1);

#if POREVE_STATISTICS
        iv_fetches++;
#endif

    return me;
}



//-----------------------------------------------------------------------------
ModelError
Memory::write(
    uint32_t  i_offset, // the address in the eprom image 
    uint64_t  i_data,   // data to write into the eprom image
    size_t    i_size    // number of bytes to write (pretty much going to be TRANSACTION_SIZE_IN_BYTES)
    )
{
    char*        to_ptr;
    char*        from_ptr;
    size_t       cnt;
    MemoryImage* mi;
    ModelError   me;
    int          mi_found;

    me = ME_SUCCESS;
    do{
        if( iv_images == 0 )
        {
            me = ME_NOT_MAPPED_IN_MEMORY;
            break;
        }
      mi       = iv_images;
      mi_found = 0;
      do{

        if( (i_offset >= mi->iv_base) && ((i_offset + i_size) <= (mi->iv_base + mi->iv_size) ) )
        {
            mi_found= 1;
            iv_images = mi; // have the Memory always point to the last MemoryImage that was used
            break;          // we found a chunk of memory containing the transaction address
        }
        mi = mi->iv_next;

      }while( mi != iv_images );

      if( ! mi_found )
      { // There was no MemoryImage that contained the transaction address
        me = ME_NOT_MAPPED_IN_MEMORY;
        break;
      }

      if( (mi->iv_permissions & ACCESS_MODE_WRITE ) == 0 )
      { // The permissions over the memory block do not allow the mode being used by the transaction
        me = ME_MEMORY_IMAGE_PERMISSION_DENIED;
        break;
      }

      // Init the character pointer into the eprom image we are using.
      to_ptr = (char*)mi->iv_image + i_offset;

      // Init the character pointer into the o_data buffer.
      // Take care of Endianess by moving to one or the other end of the buffer as appropriate.
#ifdef _BIG_ENDIAN
        from_ptr   = (char*)&i_data + (TRANSACTION_SIZE_IN_BYTES - i_size);
#else
        from_ptr   = ((char*)&i_data + i_size -1);
#endif

      for( cnt = 0; cnt < i_size; cnt++ )
      {
        *to_ptr++ = *from_ptr;

        // Move the to pointer either forward or backward as appropriate for Endianess
#ifdef _BIG_ENDIAN
        from_ptr++;
#else
        from_ptr--;
#endif
      }

      me = ME_SUCCESS;
      break;

    }while(1);

#if POREVE_STATISTICS
        iv_writes++;
#endif

    return me;
}


//-----------------------------------------------------------------------------
ModelError
Memory::map(
    uint32_t i_base,            // For direct memory this is the 0 based offset from the Slave iv_base
    size_t   i_size,            // Size of this chunk of memory
    int      i_permissions,
    void*    i_image,
    bool     i_crcEnable
    )
{
    ModelError   me = ME_SUCCESS;
    MemoryImage* n;
    MemoryImage* mi = new MemoryImage( i_base, i_size, i_permissions, i_image, i_crcEnable );

    if( iv_images == 0 )
    {
      iv_images = mi;
      mi->iv_next = mi;
    }else{
      n = iv_images->iv_next;
      while( n->iv_next != iv_images )
      {
        n = n->iv_next;
      }
      n->iv_next = mi;
      mi->iv_next = iv_images;
    }

    return me;
}


//-----------------------------------------------------------------------------
#if POREVE_STATISTICS
void
Memory::resetStatistics()
{
    iv_reads = 0;
    iv_writes = 0;
    iv_fetches = 0;
}
#endif  // POREVE_STATISTICS


//-----------------------------------------------------------------------------
MemoryImage::MemoryImage(
    uint32_t     i_base,
    size_t       i_size,
    int          i_permissions,
    void*        i_image,
    bool         i_crcEnable
    )
{

    iv_base        = i_base;
    iv_size        = i_size;
    iv_permissions = i_permissions;
    iv_image       = i_image;
    iv_crcEnable   = i_crcEnable;
    iv_originalCrc = 0;
    iv_next = NULL;

    if( i_crcEnable )
    {
        iv_originalCrc = computeCrc();
    }

}

//-----------------------------------------------------------------------------
MemoryImage::~MemoryImage()
{
}

//-----------------------------------------------------------------------------
uint64_t 
MemoryImage::computeCrc()
{
    return 0;
}

//-----------------------------------------------------------------------------
bool
MemoryImage::checkCrc()
{
    bool result = true;

    if( iv_crcEnable == true )
    {
        uint64_t current_crc = computeCrc();
        if( current_crc != iv_originalCrc )
        {
            result = false;
        }
    }

    return result;
}

//-----------------------------------------------------------------------------
OciMemory::OciMemory() :
iv_memory(NULL), iv_passThrough(false)
{
}

//-----------------------------------------------------------------------------
OciMemory::~OciMemory()
{
}

//-----------------------------------------------------------------------------
void
OciMemory::setPassThrough(const bool i_enable)
{
    iv_passThrough = i_enable;
}

//-----------------------------------------------------------------------------
void
OciMemory::configure(
    fapi::Target*       i_target,
    ecmdDataBufferBase* i_dataBuffer,
    uint32_t            i_base,
    uint64_t            i_size,
    int                 i_permissions,
    Memory*             i_memory
    )
{
    iv_target      = i_target;
    iv_dataBuffer  = i_dataBuffer;
    iv_base        = i_base;
    iv_size        = i_size;
    iv_permissions = i_permissions;
    iv_memory      = i_memory;
}



//-----------------------------------------------------------------------------
// 
fapi::ReturnCode
OciMemory::operation(Transaction& io_transaction)
{
    fapi::ReturnCode rc;

    ModelError       me;

    if( io_transaction.iv_mode & ACCESS_MODE_READ )
    {
        me = iv_memory->read( (uint32_t)io_transaction.iv_offset, io_transaction.iv_data, TRANSACTION_SIZE_IN_BYTES );
        if( me == ME_NOT_MAPPED_IN_MEMORY && iv_passThrough )
        {
            rc = read( io_transaction.iv_address, io_transaction.iv_data );
            if( rc.ok() )
            {
                me = ME_SUCCESS;
            }
            else
            {
                me = ME_FAILURE;
            }
        }
    }
    else
    {
        me = iv_memory->write( (uint32_t)io_transaction.iv_offset, io_transaction.iv_data, TRANSACTION_SIZE_IN_BYTES );
        if( me == ME_NOT_MAPPED_IN_MEMORY && iv_passThrough )
        {
            rc = write( io_transaction.iv_address, io_transaction.iv_data );
            if( rc.ok() )
            {
                me = ME_SUCCESS;
            }
            else
            {
                me = ME_FAILURE;
            }
        }
    }

    io_transaction.busError( me );

    if( me == ME_SUCCESS )
    {
      rc = (uint32_t)0;
    }

    // if read/write failed then rc == 1 by default
    // if read/write returned ME_NOT_MAPPED_IN_MEMORY && pass through true then
    // rc == value returned from putScom or getScom

    return rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode
OciSlave::operation(Transaction& io_transaction)
{
    fapi::ReturnCode rc;
    ModelError       me;

    if( io_transaction.iv_mode & ACCESS_MODE_READ )
    {
        rc = read( io_transaction.iv_address, io_transaction.iv_data );
    }
    else
    {
        rc = write( io_transaction.iv_address, io_transaction.iv_data );
    }

    if( rc.ok() )
    {
        me = ME_SUCCESS;
    }
    else
    {
        me = ME_FAILURE;
    }

    io_transaction.busError( me );

    return rc;
}

//-----------------------------------------------------------------------------
OciSlave::~OciSlave()
{
}

//-----------------------------------------------------------------------------
fapi::ReturnCode
OciSlave::read(const uint32_t i_address, uint64_t& o_data)
{
    fapi::ReturnCode rc;
    return rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode
OciSlave::write(const uint32_t i_address, const uint64_t i_data)
{
    fapi::ReturnCode rc;
    return rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode
OciSlaveWritable::write(const uint32_t i_address, const uint64_t i_data)
{

    // For this model, print out a message to confirm a write has been written is all it needs.
    FAPI_INF("OciSlaveWritable::write(0x%08x, 0x%016llx)",
             i_address, i_data);
    fapi::ReturnCode rc;
    return rc;
}

