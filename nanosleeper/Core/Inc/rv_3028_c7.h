/*
 * rv_3028_c7.h
 *
 *  Created on: Jan 27, 2024
 *      Author: jake
 */

#ifndef INC_RV_3028_C7_H_
#define INC_RV_3028_C7_H_

#include <stdint.h>
#include <stdbool.h>

#define RV3028_ADDRESS					(0xA4)


#define RV3028_SECONDS      			0x00
#define RV3028_MINUTES      			0x01
#define RV3028_HOURS        			0x02

#define RV3028_WEEKDAY					0x03
#define RV3028_DATE         			0x04
#define RV3028_MONTHS        			0x05
#define RV3028_YEARS        			0x06

#define RV3028_MINUTES_ALM     			0x07
#define RV3028_HOURS_ALM       			0x08
#define RV3028_DATE_ALM        			0x09

#define RV3028_TIMERVAL_0				0x0A
#define RV3028_TIMERVAL_1				0x0B
#define RV3028_TIMERSTAT_0				0x0C
#define RV3028_TIMERSTAT_1				0x0D

#define RV3028_STATUS					0x0E
#define RV3028_CTRL1					0x0F
#define RV3028_CTRL2					0x10
#define RV3028_GPBITS					0x11
#define RV3028_INT_MASK					0x12

#define RV3028_EVENTCTRL				0x13
#define RV3028_COUNT_TS					0x14
#define RV3028_SECONDS_TS				0x15
#define RV3028_MINUTES_TS				0x16
#define RV3028_HOURS_TS					0x17
#define RV3028_DATE_TS					0x18
#define RV3028_MONTH_TS					0x19
#define RV3028_YEAR_TS					0x1A

#define RV3028_UNIX_TIME0				0x1B
#define RV3028_UNIX_TIME1				0x1C
#define RV3028_UNIX_TIME2				0x1D
#define RV3028_UNIX_TIME3				0x1E

#define RV3028_USER_RAM1				0x1F
#define RV3028_USER_RAM2				0x20

#define RV3028_PASSWORD0				0x21
#define RV3028_PASSWORD1				0x22
#define RV3028_PASSWORD2				0x23
#define RV3028_PASSWORD3				0x24

#define RV3028_EEPROM_ADDR				0x25
#define RV3028_EEPROM_DATA				0x26
#define RV3028_EEPROM_CMD				0x27

#define RV3028_ID						0x28

#define EEPROM_Clkout_Register			0x35
#define RV3028_EEOffset_8_1				0x36	//bits 8 to 1 of EEOffset. Bit 0 is bit 7 of register 0x37
#define EEPROM_Backup_Register			0x37

bool init_rv_3028_c7(I2C_HandleTypeDef i2c_handle, uint32_t current_time, bool first_setup);

#endif /* INC_RV_3028_C7_H_ */
