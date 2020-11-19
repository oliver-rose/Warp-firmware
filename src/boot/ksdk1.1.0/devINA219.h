/* Driver for INA219 with Warp firmware. */

#ifndef WARP_BUILD_ENABLE_INA219
#define WARP_BUILD_ENABLE_INA219
#endif


WarpStatus	readSensorRegisterINA219(uint8_t deviceRegister, int numberOfBytes);
