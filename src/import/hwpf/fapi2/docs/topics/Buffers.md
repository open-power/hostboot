# Buffers

Buffers can be of two styles; buffers made from an integral type and
buffers made from a container. Integral type buffers, while limited
in size, can be tightly controlled via the compiler by using c++
templates.

C++ templates allow for very explicit control, but yield a
syntax different than the FAPI 1.x functional interface. For example,
a fapi2::buffer is defined as having a type:

    fapi2::buffer<uint64_t> new_buffer;

defines a buffer with exactly 64 bits, and can be manipulated by the
compiler as a single integral value. These implementations result
in concise instruction streams, and a platform may choose to implement
all or some or none of the integral buffer types.

Buffers which have containers as their underlying implementation
are found in the class fapi2::variable_buffer. variable_buffer is little
more than

     fapi2::buffer<fapi2::bits_container>

where bits_container is the typedef of the underlying container (a
vector of uint32_t, for example)
### Simple uint64_t buffer
    const uint32_t x = 2;
    // this data buffer will contain data in a uint64_t type
    fapi2::buffer<uint64_t> data;
    // Set using the template and a constant
    data.setBit<x>();
    // Set using the template and a value
    data.setBit<3>();
    // Set using the function interface, and a value
    data.setBit(1);
    // compiler gets smart.
    // movabs $0x7000000000000000,%rsi

### variable_buffer, same thing
    const uint32_t x = 2;
    // Note: only 15 bits long
    fapi2::variable_buffer data(15);
    data.setBit(x);
    data.setBit(3);
    data.setBit(1);

### Method chaining
Buffers support method chaining. So, rather than this
    buffer<T> mask;
    mask.setBit<B>();
    mask.invert();
    my_buffer &= mask;

You can do

    my_buffer &= buffer<T>().setBit<B>.invert();

### Buffer operations
    // An 8 bit buffer, initialized with a value
    fapi2::buffer<uint8_t> eight_bits = 0xAA;
    fapi2::buffer<uint8_t> another_eight;
    fapi2::buffer<uint16_t> sixteen_bits;
    // You can't assign an 8 bit buffer to a 16 bit buffer.
    sixteen_bits = eight_bits; ERROR
    // But you can assign buffers of the same type
    another_eight = eight_bits;
    // You can assign constants (or other known values) directly:
    sixteen_bits = 0xAABB;

### Variable buffer operations
    fapi2::variable_buffer data(16);
    // Very large buffers can be initialized rather than set bit by bit.
    const fapi2::variable_buffer bit_settings_known(
        {0xFFFF0000, 0xAABBF0F0,
         0xFFFF0000, 0xAABBF0F0,
         0xFFFF0000, 0xAABBF0F0,});
    // Assignment will expand or shrink the size automatically.
    data = bit_settings_known;
    // You can assign directly to the buffer:
    fapi2::variable_buffer other_bits;
    const fapi2::container_unit x = 0xFF00AA55;
    other_bits = {x, 0xDEADBEEF};

### Create a buffer of 32 bits and initialize it.

    fapi2::buffer<uint32_t> data(0xAA55FFAA);

### Flip bit 0

    data.flipBit<0>();

### Invert the buffer

    data.invert();

### Reset it's value

    data = 0xFFFFFFFF;

### Create a mask using an anonymous object

    my_buffer &= buffer<T>().setBit<B>.invert();

### Create an 8 bit buffer, initialize it, and flip some bits around

    fapi2::buffer<uint8_t>(0xA5).flipBit<5>().flipBit<5>() == 0xA5;
