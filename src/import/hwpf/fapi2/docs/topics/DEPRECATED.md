@deprecated Functions which were either not found used in the
hostboot code or have other ways to perform the same operation
with the new buffers are candidates for deprecation. They are listed
here so if you're looking for something you might find that it's
deprecated and not been implemented. If there's something in this
list which should be implemented, let someone know and we can
implement it.<br>
- setDoubleWordLength(uint32_t i_newNumDoubleWords);<br>
- setWordLength(uint32_t i_newNumWords);<br>
- setHalfWordLength(uint32_t i_newNumHalfWords);<br>
- setByteLength(uint32_t i_newNumBytes);<br>
- setBitLength(uint32_t i_newNumBits);<br>
- setCapacity (uint32_t i_newNumWords);<br>
- shrinkBitLength(uint32_t i_newNumBits);<br>
- growBitLength(uint32_t i_newNumBits);<br>
Replaced with std::container operations
- shiftRight(uint32_t i_shiftnum, uint32_t i_offset = 0);<br>
Replaced with operator>> as offset appears unused<br>
- shiftLeft(uint32_t i_shiftnum, uint32_t i_offset = 0xFFFFFFFF);<br>
Replaced with operator<< as offset appears unused<br>
- shiftRightAndResize(uint32_t i_shiftnum, uint32_t i_offset = 0);<br>
- shiftLeftAndResize(uint32_t i_shiftnum);<br>
- rotateRight(uint32_t i_rotatenum);<br>
- rotateLeft(uint32_t i_rotatenum);<br>
- flushTo0(); and flushTo1();<br>
Replaced with flush<X>() where X can be {0,1}<br>
- applyInversionMask(const uint32_t * i_invMask, uint32_t
                     i_invByteLen);<br>
- applyInversionMask(const ecmdDataBufferBase & i_invMaskBuffer,
                     uint32_t i_invByteLen);<br>
- insert(const ecmdDataBufferBase & i_bufferIn, uint32_t i_targetStart,
         uint32_t i_len, uint32_t i_sourceStart = 0);<br>
  insert(const uint32_t * i_data, uint32_t i_targetStart, uint32_t
         i_len, uint32_t i_sourceStart = 0);<br>
It appears from the usage that the insert functions were used like a
initializer list - given a chunk of data, insert at bit 0.
Other useages have been replaced with a templated version for
variable_buffers and bit operations for integral buffers.<br>
- insertFromRight<br>
Replaced with a templated version for
variable_buffers and bit operations for integral buffers.<br>
- extract API<br>
Replaced with a templated version for
variable_buffers and bit operations for integral buffers.<br>
- setOr API/merge API<br>
- concat( ... );<br>
Replaced with operator+() and operator+=()<br>
- setOr(const uint32_t * i_data, uint32_t i_startbit,
        uint32_t i_len);<br>
  merge()
Replaced with operator|=() as it looks like startbit is always 0
and len is always the length of i_data. Merge is the same I think<br>
- setXor(const ecmdDataBufferBase & i_bufferIn, uint32_t i_startbit,
         uint32_t i_len);
Replaced with operator|=() as it looks like startbit is always 0
and len is always the length of i_data.<br>
- setAnd(const ecmdDataBufferBase & i_bufferIn, uint32_t i_startbit,
         uint32_t i_len);<br>
Replaced with operator&=() as it looks like startbit is mostly 0
and len is mostly the length of i_data. The few cases seen where
this isn't the case, a uint64_t mask would work better.<br>
- copy(ecmdDataBufferBase & o_copyBuffer) const
Replaced with operator=()
- memCopyIn, memCopyOut
- flattenSize(void) const;
- flatten(uint8_t * o_data, uint32_t i_len) const;
- unflatten(const uint8_t * i_data, uint32_t i_len);
- oddParity()
- evenParity()
- shareBuffer(ecmdDataBufferBase* i_sharingBuffer);
- compressBuffer(ecmdCompressionMode_t i_mode = ECMD_COMP_PRD);
- uncompressBuffer();
- isBufferCompressed();
- setWord(), setHalfWord(), etc.
Replaced with a templated version, set<type>();
- getDoubleWordLength(), getDoubleLength
Replaced with a templated version taking the type as an argument
- getCapacity()
- writeBit(bits_type i_bit, uint32_t i_value);
Replaced with set operations (this might be needed?)
e