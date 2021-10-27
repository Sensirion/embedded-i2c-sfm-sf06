/*
 * I2C-Generator: 0.3.0
 * Yaml Version: 1.1.0
 * Template Version: 0.7.0-80-gf4d3b1b
 */
/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>  // printf

#include "sensirion_common.h"
#include "sensirion_i2c_hal.h"
#include "sfm_sf06_i2c.h"

/**
 * select the proper i2c address for your sensor
 * see datasheet of your sensor
 *
 */

int main(void) {
    int16_t error = 0;

    sensirion_i2c_hal_init();

    init_driver(ADDR_SFM3119);

    error = sfm_sf06_stop_continuous_measurement();

    if (error) {
        printf("Error executing sfm_sf06_stop_continuous_measurement(): %i\n",
               error);
    }

    uint32_t product_identifier;
    uint8_t serial_number[8];
    uint8_t serial_number_size = 8;

    error = sfm_sf06_read_product_identifier(&product_identifier, serial_number,
                                             serial_number_size);

    if (error) {
        printf("Error executing sfm_sf06_read_product_identifier(): %i\n",
               error);
    } else {
        printf("Product identifier: %u\n", product_identifier);
        printf("Serial number: ");
        for (size_t i = 0; i < serial_number_size; i++) {
            printf("%u, ", serial_number[i]);
        }
        printf("\n");
    }

    // Start Measurement

    error = sfm_sf06_start_o2_continuous_measurement();
    if (error) {
        printf(
            "Error executing sfm_sf06_start_o2_continuous_measurement(): %i\n",
            error);

        return error;
    }
    printf("%12s\t%12s\t%12s\n", "flow", "temperature", "status");
    // measurement runs e.g. one min
    for (int i = 0; i < 60; i++) {
        // Read Measurement
        int16_t flow = 0;
        int16_t temperature = 0;
        uint16_t status = 0;
        sensirion_i2c_hal_sleep_usec(500000);
        error = sfm_sf06_read_measurement_data(&flow, &temperature, &status);
        if (error) {
            printf("Error executing sfm_sf06_read_measurement_data(): %i\n",
                   error);
            continue;
        }

        printf("%12i\t%12i\t%12i\n", flow, temperature, status);
    }

    error = sfm_sf06_stop_continuous_measurement();

    if (error) {
        printf("Error executing sfm_sf06_stop_continuous_measurement(): %i\n",
               error);
    }

    return 0;
}
