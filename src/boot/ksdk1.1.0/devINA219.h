/* Driver for INA219 with Warp firmware. */

#ifndef WARP_BUILD_ENABLE_INA219
#define WARP_BUILD_ENABLE_INA219
#endif

void		initINA219(const uint8_t i2cAddress, WarpI2CDeviceState volatile *  deviceStatePointer);
WarpStatus writeCalibrationINA219(uint8_t calibration[]);
WarpStatus	readSensorRegisterINA219(uint8_t deviceRegister, int numberOfBytes);
uint16_t readRawCurrentINA219();