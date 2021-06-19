/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Ha Thach for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef DC801_H
#define DC801_H

// Keyboard config
#define KEYBOARD_ADDRESS    0x23
#define KEYBOARD_INT_PIN    18

// I2C configuration
#define I2C_INSTANCE        0

#define I2C_SCL_PIN         23
#define I2C_SDA_PIN         22

#define NRFX_TWI0_ENABLED   1
#define NRFX_TWI1_ENABLED   0

/*------------------------------------------------------------------*/
/* LED
 *------------------------------------------------------------------*/
#define LEDS_NUMBER         0
//#define LED_PRIMARY_PIN     13
//#define LED_SECONDARY_PIN   14
//#define LED_STATE_ON        0

/*------------------------------------------------------------------*/
/* BUTTON
 *------------------------------------------------------------------*/
#define BUTTONS_NUMBER      2
#define BUTTON_1            18
#define BUTTON_2            33
#define BUTTON_PULL         NRF_GPIO_PIN_PULLUP 

//--------------------------------------------------------------------+
// BLE OTA
//--------------------------------------------------------------------+
#define BLEDIS_MANUFACTURER    "DC801"
#define BLEDIS_MODEL           "BLACKMAGE"

//--------------------------------------------------------------------+
// USB
//--------------------------------------------------------------------+

// Shared VID/PID with Feather nRF52840, will be disabled for building in the future
#define USB_DESC_VID           0x239A
#define USB_DESC_UF2_PID       0x0029
#define USB_DESC_CDC_ONLY_PID  0x0029

#define UF2_PRODUCT_NAME    "DC801 BlackMage"
#define UF2_BOARD_ID        "dc801-blackmage-v1"
#define UF2_INDEX_URL       "https://github.com/DC801/BM-Badge/"

#define UF2_VOLUME_LABEL   "DC801BOOT  "

#endif // DC801_H
