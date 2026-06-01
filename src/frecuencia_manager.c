//librerias
#include "frecuencia_manager.h"
#include "registro_manager.h"
#include "wiper_manager.h"
#include "spi_manager.h"
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"

void mcp4132_set_cutoff_frecuencia(uint8_t frecuencia_value) {

    float C = 10e-9; // (10nF)
    float Rab = 10000.0; // (10kohm)
    float Rw = 75.0; // (75ohm)
    float M_PI = 3.14159265358979323846; // Valor de pi

    // Calcular la resistencia total Rwb a partir de la frecuencia de corte deseada
    float Rwb = 1.0 / (2.0 * M_PI * frecuencia_value * C);

    // Calcular el valor del wiper (N) a partir de Rwb
    uint8_t N = (uint8_t)(((Rwb - Rw) * 128.0) / Rab);

    // Configurar el wiper con el valor calculado
    mcp4132_set_wiper(N);
}
