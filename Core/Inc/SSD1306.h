#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "stm32f1xx_hal.h"

void SSD1306_Init(I2C_HandleTypeDef* hi2c);
void SSD1306_SetPixel(uint8_t x, uint8_t y);
bool SSD1306_Try_Update();

extern I2C_HandleTypeDef* SSD1306_HI2C1;