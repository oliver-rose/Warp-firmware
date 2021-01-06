/*
	Authored 2016-2018. Phillip Stanley-Marbell, Youchao Wang.

	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	*	Redistributions of source code must retain the above
		copyright notice, this list of conditions and the following
		disclaimer.

	*	Redistributions in binary form must reproduce the above
		copyright notice, this list of conditions and the following
		disclaimer in the documentation and/or other materials
		provided with the distribution.

	*	Neither the name of the author nor the names of its
		contributors may be used to endorse or promote products
		derived from this software without specific prior written
		permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
	FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
	COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
	LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
	ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef WARP_BUILD_ENABLE_DEVMMA8451Q
#define WARP_BUILD_ENABLE_DEVMMA8451Q

void		initMMA8451Q(const uint8_t i2cAddress, WarpI2CDeviceState volatile *  deviceStatePointer);
WarpStatus	readSensorRegisterMMA8451Q(uint8_t deviceRegister, int numberOfBytes);
WarpStatus	writeSensorRegisterMMA8451Q(uint8_t deviceRegister,
					uint8_t payloadBtye,
					uint16_t menuI2cPullupValue);
WarpStatus	configureSensorMMA8451Q(uint8_t payloadF_SETUP, uint8_t payloadCTRL_REG1, uint16_t menuI2cPullupValue);
WarpStatus	configureSensorMMA8451Qmotion(uint16_t menuI2cPullupValue);
WarpStatus	readSensorSignalMMA8451Q(WarpTypeMask signal,
					WarpSignalPrecision precision,
					WarpSignalAccuracy accuracy,
					WarpSignalReliability reliability,
					WarpSignalNoise noise);
void		printSensorDataMMA8451Q(bool hexModeFlag, bool motionDetection);

typedef enum
{
	/* Status */
	kWarpSensorRegisterMMA8451Q_STATUS				= 0x00,

	/* Output registers */
	kWarpSensorRegisterMMA8451Q_OUT_X_MSB			= 0x01,
	kWarpSensorRegisterMMA8451Q_OUT_X_LSB			= 0x02,
	kWarpSensorRegisterMMA8451Q_OUT_Y_MSB			= 0x03,
	kWarpSensorRegisterMMA8451Q_OUT_Y_LSB			= 0x04,
	kWarpSensorRegisterMMA8451Q_OUT_Z_MSB			= 0x05,
	kWarpSensorRegisterMMA8451Q_OUT_Z_LSB			= 0x06,

	/* FIFO */
	kWarpSensorRegisterMMA8451Q_F_SETUP				= 0x09,
	kWarpSensorRegisterMMA8451Q_TRIG_CFG			= 0x0A,

	/* System mode */
	kWarpSensorRegisterMMA8451Q_SYSMOD 				= 0x0B,
	/* Interrupt status */
	kWarpSensorRegisterMMA8451Q_INT_SOURCE 			= 0x0C,

	/* Device ID (0x1A) */
	kWarpSensorRegisterMMA8451Q_WHO_AM_I 			= 0x0D,

	/* Configuration registers */
	kWarpSensorRegisterMMA8451Q_XYZ_DATA_CFG 		= 0x0E,
	kWarpSensorRegisterMMA8451Q_HP_FILTER_CUTOFF 	= 0x0F,

	/* Portrait/landscape */
	kWarpSensorRegisterMMA8451Q_PL_STATUS 			= 0x10,
	kWarpSensorRegisterMMA8451Q_PL_CFG 				= 0x11,
	kWarpSensorRegisterMMA8451Q_PL_COUNT 			= 0x12,
	kWarpSensorRegisterMMA8451Q_PL_BF_ZCOMP 		= 0x13,
	kWarpSensorRegisterMMA8451Q_P_L_THS_REG 		= 0x14,

	/* Freefall/motion detection */
	kWarpSensorRegisterMMA8451Q_FF_MT_CFG			= 0x15,
	kWarpSensorRegisterMMA8451Q_FF_MT_SRC			= 0x16,
	kWarpSensorRegisterMMA8451Q_FF_MT_THS			= 0x17,
	kWarpSensorRegisterMMA8451Q_FF_MT_COUNT			= 0x18,

	/* Transient event */
	kWarpSensorRegisterMMA8451Q_TRANSIENT_CFG		= 0x1D,
	kWarpSensorRegisterMMA8451Q_TRANSIENT_SCR		= 0x1E,
	kWarpSensorRegisterMMA8451Q_TRANSIENT_THS		= 0x1F,
	kWarpSensorRegisterMMA8451Q_TRANSIENT_COUNT		= 0x20,

	/* Pulse */
	kWarpSensorRegisterMMA8451Q_PULSE_CFG			= 0x21,
	kWarpSensorRegisterMMA8451Q_PULSE_SRC			= 0x22,
	kWarpSensorRegisterMMA8451Q_PULSE_THSX			= 0x23,
	kWarpSensorRegisterMMA8451Q_PULSE_THSY			= 0x24,
	kWarpSensorRegisterMMA8451Q_PULSE_THSZ			= 0x25,
	kWarpSensorRegisterMMA8451Q_PULSE_TMLT			= 0x26,
	kWarpSensorRegisterMMA8451Q_PULSE_LTCY			= 0x27,
	kWarpSensorRegisterMMA8451Q_PULSE_WIND			= 0x28,

	/* Auto sleep */
	kWarpSensorRegisterMMA8451Q_ASLP_COUNT			= 0x29,

	/* Control registers */
	kWarpSensorRegisterMMA8451Q_CTRL_REG1			= 0x2A,
	kWarpSensorRegisterMMA8451Q_CTRL_REG2			= 0x2B,
	kWarpSensorRegisterMMA8451Q_CTRL_REG3			= 0x2C,
	kWarpSensorRegisterMMA8451Q_CTRL_REG4			= 0x2D,
	kWarpSensorRegisterMMA8451Q_CTRL_REG5			= 0x2E,

	/* Offsets */
	kWarpSensorRegisterMMA8451Q_OFF_X				= 0x2F,
	kWarpSensorRegisterMMA8451Q_OFF_Y				= 0x30,
	kWarpSensorRegisterMMA8451Q_OFF_Z				= 0x31,
} WarpSensorRegisterMMA8451Q;

#endif