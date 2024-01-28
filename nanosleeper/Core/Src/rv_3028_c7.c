/*
 * rv_3028_c7.c
 *
 *  Created on: Jan 27, 2024
 *      Author: jake
 */

#include "main.h"

#include "rv_3028_c7.h"

bool init_rv_3028_c7(I2C_HandleTypeDef i2c_handle, uint32_t current_time, bool first_setup)
{
	uint32_t timeout = 300; // in ms

	uint8_t id_value = 0;
	HAL_StatusTypeDef id_status = HAL_I2C_Mem_Read(&i2c_handle, RV3028_ADDRESS, RV3028_ID, I2C_MEMADD_SIZE_8BIT, &id_value, 1, timeout);

	if(id_status == HAL_OK)
	{
		// Check id value TODO

		// Set time
		uint8_t unix_reg[4];
		unix_reg[0] = current_time;
		unix_reg[1] = current_time >> 8;
		unix_reg[2] = current_time >> 16;
		unix_reg[3] = current_time >> 24;
		HAL_StatusTypeDef time_setup = HAL_I2C_Mem_Write(&i2c_handle, RV3028_ADDRESS, RV3028_UNIX_TIME0, I2C_MEMADD_SIZE_8BIT, unix_reg, 4, timeout);

		// Set timer to sleep
		// Note this starts here, not after we go into shutdown
		uint16_t time_to_sleep_sec = 15;
		uint8_t timer_buff[2];
		timer_buff[0] = (time_to_sleep_sec & 0xFF);
		timer_buff[1] = ((time_to_sleep_sec >> 8) & 0x0F);
		HAL_StatusTypeDef timer_set_success = HAL_I2C_Mem_Write(&i2c_handle, RV3028_ADDRESS, RV3028_TIMERVAL_0, I2C_MEMADD_SIZE_8BIT, timer_buff, 2, timeout);

		// Set control
		uint8_t control_2_value = (0x01 << 4); // Periodic countdown timer interrupt enable
		HAL_StatusTypeDef ctrl_2_success = HAL_I2C_Mem_Write(&i2c_handle, RV3028_ADDRESS, RV3028_CTRL2, I2C_MEMADD_SIZE_8BIT, &control_2_value, 1, timeout);

		uint8_t control_1_value = (0x02 << 0) | (0x01 << 2); // 1 Hz timer clock, enable periodic counter timer int, timer single mode
		HAL_StatusTypeDef ctrl_1_success = HAL_I2C_Mem_Write(&i2c_handle, RV3028_ADDRESS, RV3028_CTRL1, I2C_MEMADD_SIZE_8BIT, &control_1_value, 1, timeout);

	}

	return (id_status == HAL_OK);
}
