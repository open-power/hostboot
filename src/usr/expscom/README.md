## Overall Description
The expscom module contains Hostboots device drivers to communicate with scom regs
on the Explorer Open-Capi Memory Buffer (OCMB) chip. Initially when Hostboot starts
the SCOM_SWITCHES attribute on all OCMB chips will be set such that useI2cScom field
is 1 and all other fields are 0. After OMI 's are trained the SCOM_SWITCHES attribute
on the OCMB targets will change so that the useIbScom field will be set to 1 and
all other fields will be 0.

### Explorer I2C SCOM

When the useI2cScom field is set in SCOM_SWITCHES this is how the
fapi2::getScom API for OCMB targets will be processed (lets say for now this is IBM scom address):

* Generic FAPI2 getScom API that will be called in a hardware procedure (HWP)


    fapi2::getScom(myOcmbTarget, scomAddr, io_buffer);
* Platform Specifc FAPI2 getScom API which the generic wrapper immediately calls


    fapi2::platGetScom(myOcmbTarget, scomAddr, io_buffer);
* Platform Specifc FAPI2 getScom API resolves to calling into Hostboot's device framework to whatever
function is registered to read OCMB target for DeviceFW::SCOM operations


    DeviceFW::deviceRead(myOcmbTarget, io_buffer,
                         sizeof(uint64_t), DeviceFW::SCOM,
                         scomAddr, READ)
* scomPeformOp is what is defined to handle DeviceFW::SCOM operations to the OCMB chip targets


    SCOM::scomPerformOp(READ, myOCMBTarget, io_buffer,
                        sizeof(uint64_t), DeviceFW::SCOM,
                        scomAddr)
* scomPeformOp is basically a wrapper for checkIndirectAndDoScom There are no indirect scoms for
OCMB target scoms so we will end up calling doScomOp


    checkIndirectAndDoScom(READ, myOCMBTarget, io_buffer,
                           sizeof(uint64_t), DeviceFW::SCOM,
                           scomAddr)

* doScomOp looks at the SCOM_SWITCHES attribute and decides which type of scom to do for the given target.


    doScomOp(READ, myOCMBTarget, io_buffer,
             sizeof(uint64_t), DeviceFW::SCOM,
             scomAddr)

* If the useI2cScom field is set to 1 then we will call the function that is registered to i2c scoms for OCMB targets


    deviceOp(READ, myOCMBTarget, io_buffer,
             sizeof(uint64_t), DeviceFW::I2CSCOM,
             scomAddr)

* i2cScomPerformOp is the function that is registered to handle i2cScom operations,
this function will perform some simple param validation before deciding whether to
call the getScom or putScom depending if the op is READ or WRITE respectively


    i2cScomPerformOp(READ, myOCMBTarget, io_buffer,
                     sizeof(uint64_t), DeviceFW::I2CSCOM,
                     scomAddr)

* The base device drivers are defined as EKB HWPs so we must run FAPI_EXEC_HWP in order to correctly call the i2c_get_scom hwp\
**Note: that EXEC and not INVOKE is used because it is likely this path
will be called within other HWPs and nesting INVOKE calls causes deadlock
due to the way we use mutexes.**


    FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_get_scom,
                  myOCMBTarget, static_cast<uint32_t>(l_scomAddr),
                  io_buffer);

* The Explorer chip nativly uses 32-bit regs so we must perform two 32-bit operations
(LHS and RHS) in order to get the 64-bits that we expect from the IBM scom


    fw_reg_read(myOCMBTarget,
                translateIbmI2cScomAddr(i_addr, LHS),
                l_readBuffer);

    fw_reg_read(myOCMBTarget,
                translateIbmI2cScomAddr(i_addr, RHS),
                l_readBuffer);

* The RHS and LHS fw_reg_read calls are nearly identical except the address is 4 bytes more
for the RHS. In both cases the way the fw_reg_read works is to first perform an i2cWrite stating
what address and how many bytes we want to read, then perform an i2c read to get the buffer


    < build up l_cmd_vector w/ FW_REG_ADDR_LATCH op, op size, addr >
    fapi2::putI2c(myOCMBTarget, FW_I2C_SCOM_READ_SIZE,
                  l_cmd_vector, l_read_data);

     < build up l_cmd_vector w/ FW_REG_READ op >
     fapi2::getI2c(myOCMBTarget, FW_I2C_SCOM_READ_SIZE,
                   l_cmd_vector, l_read_data);

* The fapi2::getI2c/putI2c calls will drill down into the drive routing similar to how we drilled down to find the i2cScom driver


    platGetI2c( myOCMBTarget, FW_I2C_SCOM_READ_SIZE
                l_cmd_vector, l_read_data)

* The hostboot platform specific implementation of platGetI2c will lookup the device route for FAPI_I2C ops to OCMB chips


    deviceRead( myOCMBTarget, l_read_data,
                FW_I2C_SCOM_READ_SIZE, DeviceFW::FAPI_I2C,
                sizeof(l_cmd_vector), l_cmd_vector);

* The function associated with FAPI_I2C ops to OCMB chips is fapiI2cPerformOp. This
wrapper function will look up i2c information about the OCMB target and determine
the i2c address for this operation


    fapiI2cPerformOp(READ , myOCMBTarget,
                     l_read_data, FW_I2C_SCOM_READ_SIZE,
                     DeviceFW::FAPI_I2C,  sizeof(l_cmd_vector),
                     l_cmd_vector);

* Eventually when the i2c info is known we call i2cRead/i2cWrite which will lookup
the device op route for I2C address on the OCMB's master I2c device (which will be a processor).


    i2cRead( myOCMBTargeti2cMaster, l_read_data,
             FW_I2C_SCOM_READ_SIZE, &l_myOCMBTargeti2cInfo,
             l_cmd_vector,  sizeof(l_cmd_vector));

* At this point we will drill down into the platform I2C device driver code


    deviceOp( DeviceFW::READ, myOCMBTargeti2cMaster,
              l_read_data, FW_I2C_SCOM_READ_SIZE,
              DEVICE_I2C_ADDRESS_OFFSET(l_myOCMBTargeti2cInfo->port,
                                        l_myOCMBTargeti2cInfo->engine,
                                        l_myOCMBTargeti2cInfo->devAddr,
                                        sizeof(l_cmd_vector),
                                        l_cmd_vector) );

### Explorer MMIO SCOM

When the useIbScom field is set in SCOM_SWITCHES this is how the fapi2::putScom API for OCMB
targets will be processed (lets say for now this is IBM scom address):

* Generic FAPI2 getScom API


    fapi2::getScom(myOcmbTarget, scomAddr, io_buffer);

* Platform Specifc FAPI2 getScom API


    fapi2::platGetScom(myOcmbTarget, scomAddr, io_buffer);

* Platform Specifc FAPI2 getScom API resolves to calling into our device framework to whatever
function is registered to read OCMB target for DeviceFW::SCOM operations


    DeviceFW::deviceRead(myOcmbTarget, io_buffer,
                         sizeof(uint64_t), DeviceFW::SCOM,
                         scomAddr, READ)

* scomPeformOp is what is defined to handle DeviceFW::SCOM operations to the OCMB chip targets


    SCOM::scomPerformOp(READ, myOCMBTarget, io_buffer,
                        sizeof(uint64_t), DeviceFW::SCOM,
                        scomAddr)

* scomPeformOp is basically a wrapper for checkIndirectAndDoScom. There are no indirect scoms
for OCMB target scoms so we will end up calling doScomOp


    checkIndirectAndDoScom(READ, myOCMBTarget, io_buffer,
                           sizeof(uint64_t), DeviceFW::SCOM,
                           scomAddr)

* doScomOp looks at the SCOM_SWITCHES attribute and decides which type of scom to do for the given target.


    doScomOp(READ, myOCMBTarget, io_buffer,
             sizeof(uint64_t), DeviceFW::SCOM,
             scomAddr)

* If the useIbScom field is set to 1 then we will call the function that is registered to inband scoms for OCMB targets


    deviceOp(READ, myOCMBTarget, io_buffer,
             sizeof(uint64_t), DeviceFW::IBSCOM,
             scomAddr)

* mmioScomPerformOp is the function that is registered to IBSCOM operations to OCMB chips


    mmioScomPerformOp(READ, myOCMBTarget, io_buffer,
                      sizeof(uint64_t), DeviceFW::IBSCOM,
                      scomAddr)

* mmioScomPerformOp will call the hwp mss::exp::ib::getScom which is a in-band scom driver for the OCMB explorer chip


    FAPI_EXEC_HWP(l_rc , mss::exp::ib::getScom, myOCMBTarget, scomAddr, io_buffer);

* mss::exp::ib::getScom will translate the scomAddress into a mmio address and perform a getMMIO64 operation


    getMMIO64(myOCMBTarget, (scomAddr << 3), io_buffer);

* getMMIO64 will add the IB_MMIO offset and perform a 64 bit mmio read using the fapi2::getMMIO interface


    fapi2::getMMIO(myOCMBTarget, EXPLR_IB_MMIO_OFFSET | scomAddr, 8, io_buffer)

* fapi2::getMMIO is defined by the platform


    ReturnCode platGetMMIO( myOCMBTarget,
                            EXPLR_IB_MMIO_OFFSET | (scomAddr << 3),
                            8,  // bytes
                            io_buffer )

* platGetMMIO will use the device framework to look up the correct routine for MMIO addresses on OCMB targets


    DeviceFW::deviceRead(myOCMBTarget,
                         io_buffer,
                         8,  // bytes
                         DEVICE_MMIO_ADDRESS(EXPLR_IB_MMIO_OFFSET | (scomAddr << 3), 8));


* the device framework will route the deviceRead call to mmioPerformOp


    mmioPerformOp(READ,
                  myOCMBTarget,
                  io_buffer,
                  8, // bytes
                  DeviceFW::MMIO,
                  address, readLimit);

* mmioPerformOp resolves to doing a memcpy on the address requested


    if (i_opType == DeviceFW::READ)
    {
        memcpy(io_ptr + i, mm_ptr + i, l_accessLimit);
    }
    else if (i_opType == DeviceFW::WRITE)
    {
        memcpy(mm_ptr + i, io_ptr + i, l_accessLimit);

        // XXX Need to check a processor SCOM here to determine if the
        // write succeeded or failed.
    }
