/**
 * Custom board handler routines
 * 
 * hamster, 6/18/2021
 *
 */

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "nrfx.h"

#include "keyboard.h"
#include "led.h"
#include "i2c.h"


static int LEDCounter = 0;
static int curLED = LED_XOR;
static bool inDFU = false;

void custom_inDFU(bool DFU){
    inDFU = DFU;
}

void custom_board_init(void){
    twi_master_init();
    keyboard_init();
    ledInit();
    ledsOff();
}

void custom_board_teardown(void){
    ledsOff();
    twi_master_uninit();
}


void custom_systick(void){

    if(inDFU){
        if(LEDCounter++ > 100){
                LEDCounter = 0;
                ledOff(curLED);
                curLED++;
                if(curLED == LED_COUNT){
                        curLED = LED_XOR;
                }
                ledOn(curLED);
        }
    }

}

bool custom_dfu_start(void){

    uint32_t keyboardMask = 0;

    // Wait a tick for the keyboard controller to wake up
    // DFU button pressed
    for(int i = 0; i < 20; i++){
      NRFX_DELAY_MS(5);
    }

    // Check if the bootloader entry button is down
    keyboardMask = get_keyboard_mask();

    if(((keyboardMask >> KEYBOARD_KEY_BIT1) & 0x01) == 1){
        inDFU = true;
        ledOn(curLED);
        return true;
    }

    return false;
}
