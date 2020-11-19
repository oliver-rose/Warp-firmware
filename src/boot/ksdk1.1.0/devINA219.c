/* Driver for INA219 with Warp firmware. */

#include <stdlib.h>

#include "fsl_device_registers.h"
#include "fsl_i2c_master_driver.h"
#include "fsl_spi_master_driver.h"

#include "warp.h"


extern volatile WarpI2CDeviceState deviceINA219State;
extern volatile uint32_t		gWarpI2cBaudRateKbps;
extern volatile uint32_t		gWarpI2cTimeoutMilliseconds;


void
initINA219(const uint8_t i2cAddress, WarpI2CDeviceState volatile *  deviceStatePointer)
{
	deviceStatePointer->i2cAddress	= i2cAddress;
	return;
}


WarpStatus
writeCalibrationINA219(uint8_t calibration[])
{
	uint8_t commandByte[1];
	i2c_status_t status;

	i2c_device_t slave =
	{
		.address = deviceINA219State.i2cAddress,
		.baudRate_kbps = gWarpI2cBaudRateKbps
	};

	commandByte[0] = 0x05;	// Calibration register
	status = I2C_DRV_MasterSendDataBlocking(
		0,
		&slave,
		commandByte,
		1,
		calibration,
		2,
		gWarpI2cTimeoutMilliseconds);
	if (status != kStatus_I2C_Success)
	{
		return kWarpStatusDeviceCommunicationFailed;
	}

	return kWarpStatusOK;
}


WarpStatus
readSensorRegisterINA219(uint8_t deviceRegister, int numberOfBytes)
{
	uint8_t cmdBuf[1] = {0xFF};
	i2c_status_t status;

	USED(numberOfBytes);
	switch (deviceRegister)
	{
		case 0x00: case 0x01: case 0x02: case 0x03:
		case 0x04: case 0x05:
		{
			break;
		}
		default:
		{
			return kWarpStatusBadDeviceCommand;
		}
	}

	i2c_device_t slave = {
		.address = deviceINA219State.i2cAddress,
		.baudRate_kbps = gWarpI2cBaudRateKbps
	};

	cmdBuf[0] = deviceRegister;

	status = I2C_DRV_MasterReceiveDataBlocking(
		0,
		&slave,
		cmdBuf,
		1,
		(uint8_t *)deviceINA219State.i2cBuffer,
		numberOfBytes,
		gWarpI2cTimeoutMilliseconds
	);

	if (status != kStatus_I2C_Success)
	{
		return kWarpStatusDeviceCommunicationFailed;
	}

	return kWarpStatusOK;
}


/* Read a current value from the INA219 (including conversion) */
uint16_t
readCurrentINA219()
{
	readSensorRegisterINA219(0x04, 2);
	return (
		(((uint32_t) deviceINA219State.i2cBuffer[0]) << 8)
		 + deviceINA219State.i2cBuffer[1]
		) / 100;
}