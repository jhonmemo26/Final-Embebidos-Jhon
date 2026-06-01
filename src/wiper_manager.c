
//Librerias
#include "wiper_manager.h"
#include "registro_manager.h"  
#include "spi_manager.h"
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"

void mcp4132_set_wiper(uint8_t wiper_value) {

    bool is_valid_value = (wiper_value <= 128);

    if (wiper_value > 128) {
        printf("Error: El valor del wiper debe estar entre 0 y 128.\n");
        return;
    }
    mcp4132_write_register(0x00, wiper_value);

}
