#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "stm32f1xx_hal.h"

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

void SSD1306_Init(I2C_HandleTypeDef* hi2c);
void SSD1306_Set_Pixel(uint8_t x, uint8_t y);
bool SSD1306_Try_Update();

extern I2C_HandleTypeDef* SSD1306_HI2C1;