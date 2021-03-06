//
// Created by hamster on 6/16/2021
//

#ifndef I2C_H
#define I2C_H

#ifdef __cplusplus
extern "C" {
#endif

void twi_master_init(void);
void twi_master_uninit(void);
void i2cMasterTransmit(uint16_t addr, uint8_t *pdata, size_t size);
void i2cMasterRead(uint16_t addr, uint8_t *pdata, size_t size);

#ifdef __cplusplus
}
#endif

#endif //I2C_H