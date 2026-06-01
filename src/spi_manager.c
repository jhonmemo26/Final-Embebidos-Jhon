#include "spi_manager.h"
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"

//definir pines
#define PIN_NUM_MISO 19
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK 18
#define PIN_NUM_CS 5

static spi_device_handle_t spi_dev;

void spi_bus_init() {
    spi_bus_config_t buscfg = {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 0 
    };


    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 1000000,           
        .mode = 0,                    
        .spics_io_num = PIN_NUM_CS,
        .queue_size = 7            // SPI mode 0
};

    spi_bus_initialize (SPI2_HOST, &buscfg, SPI_DMA_DISABLED);
    spi_bus_device (SPI2_HOST, &devcfg, &spi_dev);

};
