
//Librerias
#include "registro_manager.h"
#include "spi_manager.h"
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"

void mcp4132_write_register(uint8_t reg, uint8_t value) {
    
    uint8_t tx_data[2];
    tx_data[0] = (reg << 1) | 0x00; // El bit de escritura es 0
    tx_data[1] = value;

    // Configurar la transacción SPI
    spi_transaction_t trans_desc;
    memset(&trans_desc, 0, sizeof(trans_desc));
    trans_desc.length = 16; // 2 bytes
    trans_desc.tx_buffer = tx_data;
    trans_desc.rx_buffer = NULL;

    // Transmitir la transacción
    spi_transaction_t trans = {
        .flags = 0,
        .length = 16, // bits para transmitir
        .rxlength = 16, // bits para recibir
        .tx_buffer = &tx_data,
        .rx_buffer = rx_data
    };

}

void mcp4132_read_register(uint8_t reg, uint8_t* data) {
    uint8_t tx_data[2];
    tx_data[0] = (reg << 1) | 0x01; // El bit de lectura es 1
    tx_data[1] = 0x00; // Valor dummy para recibir datos

    // Configurar la transacción SPI
    spi_transaction_t trans = {
        .flags = 0,
        .length = 16, // 2 bytes
        .rxlength = 16, // 2 bytes
        .tx_buffer = tx_data,
        .rx_buffer = data
    };
}
