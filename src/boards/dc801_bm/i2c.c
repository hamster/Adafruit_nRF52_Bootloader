//
// Created by hamster on 6/16/2021
//

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "i2c.h"
#include "board.h"
#include <nrfx_twi.h>

static const nrfx_twi_t m_twi_master = NRFX_TWI_INSTANCE(I2C_INSTANCE);

void twi_master_init(void){
    const nrfx_twi_config_t config = {
            .scl                = I2C_SCL_PIN,
            .sda                = I2C_SDA_PIN,
            .frequency          = TWI_FREQUENCY_FREQUENCY_K400,
            .interrupt_priority = 2,
            .hold_bus_uninit    = false
    };

    if (NRFX_SUCCESS == nrfx_twi_init(&m_twi_master, &config, NULL, NULL)){
        nrfx_twi_enable(&m_twi_master);
    }
}

void i2cMasterTransmit(uint16_t addr, uint8_t *pdata, size_t size){
    //badge_mutex_lock(&i2c_mutex);
    nrfx_twi_xfer_desc_t xfer = NRFX_TWI_XFER_DESC_TX(addr, pdata, size);

    nrfx_twi_xfer(&m_twi_master, &xfer, NRFX_TWI_FLAG_NO_XFER_EVT_HANDLER);
    //badge_mutex_unlock(&i2c_mutex);
}

void i2cMasterRead(uint16_t addr, uint8_t *pdata, size_t size){
    //badge_mutex_lock(&i2c_mutex);
    nrfx_twi_xfer_desc_t xfer = NRFX_TWI_XFER_DESC_RX(addr, pdata, size);

    nrfx_twi_xfer(&m_twi_master, &xfer, NRFX_TWI_FLAG_NO_XFER_EVT_HANDLER);
    //nrfx_twi_rx(&m_twi_master, addr, pdata, size);
    //badge_mutex_unlock(&i2c_mutex);
}