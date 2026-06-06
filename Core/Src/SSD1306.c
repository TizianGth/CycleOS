#include "SSD1306.h"

#define ADDRESS 0x3C << 1 // 7-bit address shifted for HAL functions

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

uint8_t buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

I2C_HandleTypeDef* SSD1306_HI2C1 = NULL;

void SSD1306_Init(I2C_HandleTypeDef* hi2c)
{
  SSD1306_HI2C1 = hi2c;
  uint8_t init[] = {
    0x00,
    0xAE,
    0x20, 0x00,
    0xB0,
    0xC8,
    0x00,
    0x10,
    0x40,
    0x81, 0xFF,
    0xA1,
    0xA6,
    0xA8, 0x3F,
    0xA4,
    0xD3, 0x00,
    0xD5, 0xF0,
    0xD9, 0x22,
    0xDA, 0x12,
    0xDB, 0x20,
    0x8D, 0x14,
    0xAF
  };

  HAL_I2C_Master_Transmit(SSD1306_HI2C1, ADDRESS, init, sizeof(init), 100);
}

void SSD1306_SetPixel(uint8_t x, uint8_t y)
{
  if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) return;

  buffer[x + y * SSD1306_WIDTH / 8] |= (1 << (y % 8));
}

bool SSD1306_Try_Update()
{
    if (SSD1306_HI2C1 &&
        HAL_I2C_IsDeviceReady(SSD1306_HI2C1, ADDRESS, 1, 100) != HAL_OK)
            return false;

    for (uint8_t page = 0; page < 8; page++)
    {
        uint8_t cmd[] = {
            0x00,
            (uint8_t)(0xB0 + page),
            0x00,
            0x10
        };

        HAL_I2C_Master_Transmit(SSD1306_HI2C1, ADDRESS, cmd, 4, 100);

        uint8_t data[129];
        data[0] = 0x40;

        for (uint8_t i = 0; i < 128; i++)
        {
            data[i + 1] = buffer[page * 128 + i];
        }

        HAL_I2C_Master_Transmit(SSD1306_HI2C1, ADDRESS, data, 129, 100);
    }
    return true;
}