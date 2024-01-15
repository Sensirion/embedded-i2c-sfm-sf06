/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 0.37.0
 * Product:       sfm_sf06
 * Model-Version: 1.5.0
 */
/*
 * Copyright (c) 2024, Sensirion AG
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

#ifndef SFM_SF06_I2C_H
#define SFM_SF06_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"
#define SFM4300_I2C_ADDR_2A 0x2a
#define SFM4300_I2C_ADDR_2B 0x2b
#define SFM4300_I2C_ADDR_2C 0x2c
#define SFM4300_I2C_ADDR_2D 0x2d
#define SFM3119_I2C_ADDR_29 0x29
#define SFM3003_I2C_ADDR_28 0x28
#define SFM3003_I2C_ADDR_2D 0x2d
#define SFM3013_I2C_ADDR_2F 0x2f
#define SFM3019_I2C_ADDR_2E 0x2e

typedef enum {
    SFM_SF06_START_O2_CONTINUOUS_MEASUREMENT_CMD_ID = 0x3603,
    SFM_SF06_START_AIR_CONTINUOUS_MEASUREMENT_CMD_ID = 0x3608,
    SFM_SF06_START_N2O_CONTINUOUS_MEASUREMENT_CMD_ID = 0x3615,
    SFM_SF06_START_CO2_CONTINUOUS_MEASUREMENT_CMD_ID = 0x361e,
    SFM_SF06_START_AIR_O2_CONTINUOUS_MEASUREMENT_CMD_ID = 0x3632,
    SFM_SF06_START_N2O_O2_CONTINUOUS_MEASUREMENT_CMD_ID = 0x3639,
    SFM_SF06_START_CO2_O2_CONTINUOUS_MEASUREMENT_CMD_ID = 0x3646,
    SFM_SF06_UPDATE_CONCENTRATION_SET_CMD_ID = 0xe17d,
    SFM_SF06_UPDATE_CONCENTRATION_ACTIVATE_CMD_ID = 0xe000,
    SFM_SF06_STOP_CONTINUOUS_MEASUREMENT_CMD_ID = 0x3ff9,
    SFM_SF06_CONFIGURE_AVERAGING_CMD_ID = 0x366a,
    SFM_SF06_READ_SCALE_OFFSET_UNIT_CMD_ID = 0x3661,
    SFM_SF06_ENTER_SLEEP_CMD_ID = 0x3677,
    SFM_SF06_EXIT_SLEEP_CMD_ID = 0x0,
    SFM_SF06_READ_PRODUCT_IDENTIFIER_CMD_ID = 0xe102,
} SFM_SF06_CMD_ID;

typedef enum {
    SFM_SF06_ERROR_CODE_I2C_ERROR = 0,
    SFM_SF06_ERROR_CODE_TIMEOUT = 1,
} sfm_sf06_error_code_t;

/**
 * @brief Initialize i2c address of driver
 *
 * @param[in] i2c_address Used i2c address
 *
 */
void sfm_sf06_init(uint8_t i2c_address);

/**
 * @brief Start measurement and update internal state
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_start_o2_continuous_measurement();

/**
 * @brief Start measurement and update internal state
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_start_air_continuous_measurement();

/**
 * @brief Start measurement and update internal state
 *
 * Start NO2 measurement and readout the corresponding scale factor from the
 * sensor
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_start_n2o_continuous_measurement();

/**
 * @brief Start measurement and update internal state
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_start_co2_continuous_measurement();

/**
 * @brief Start measurement and update internal state
 *
 * @param[in] volume_fraction Volume fraction of O₂ in ‰.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_start_n2o_o2_continuous_measurement(uint16_t volume_fraction);

/**
 * @brief Start measurement and update internal state
 *
 * @param[in] volume_fraction Volume fraction of O₂ in ‰.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_start_co2_o2_continuous_measurement(uint16_t volume_fraction);

/**
 * @brief Start measurement and update internal state
 *
 * @param[in] volume_fraction Volume fraction of dioxigen in ‰.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_start_air_o2_continuous_measurement(uint16_t volume_fraction);

/**
 * @brief Rename overwritten function.
 *
 * @param[out] flow Calibrated flow signal.
 * @param[out] temperature Calibrated temperature.
 * @param[out] status_word Gives information about the measurement command that
 * is currently running, information on the currently selected averaging mode,
 * and the defined gas concentration of the current measurement command. A
 * detailed description of the *status_word* can be found in the data sheet.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_read_measurement_data_raw(int16_t* flow, int16_t* temperature,
                                           uint16_t* status_word);

/**
 * @brief Configure and apply new concentration value.
 *
 * @param[in] volume_fraction Fraction value
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_update_concentration(uint16_t volume_fraction);

/**
 * @brief Start continuous O₂ measurement
 *
 * The sensor starts measuring both O₂ flow and temperature and provides a
 * status word. All three measurement results can be read out through one single
 * I2C read when the continuous measurement is running. The specific command
 * code used for the start continuous measurement command selects the calibrated
 * gas or binary gas mixture (lookup table) for the flow signal.
 *
 * Supported by products:
 *   * SFM3003
 *   * SFM4300-20
 *   * SFM4300-50
 *   * SFM3119
 *   * SFM3013-300-CL
 *   * SFM3013-300-CLM
 *   * SFM3019
 *
 * @note The first measurement result will be available after 12ms. Small
 * accuracy deviations (few % of reading) can occur during the first 30ms
 * (including the 12ms)
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t ll_sfm_sf06_start_o2_continuous_measurement();

/**
 * @brief Start continuous air measurement
 *
 * The sensor starts measuring both Air flow and temperature and provides a
 * status word. All three measurement results can be read out through one single
 * I2C read when the continuous measurement is running. The specific command
 * code used for the start continuous measurement command selects the calibrated
 * gas or binary gas mixture (lookup table) for the flow signal.
 *
 * Supported by products:
 *   * SFM3003
 *   * SFM4300-20
 *   * SFM4300-50
 *   * SFM3119
 *   * SFM3013-300-CL
 *   * SFM3013-300-CLM
 *   * SFM3019
 *
 * @note The first measurement result will be available after 12ms. Small
 * accuracy deviations (few % of reading) can occur during the first 30ms
 * (including the 12ms)
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t ll_sfm_sf06_start_air_continuous_measurement();

/**
 * @brief Start continuous N₂O measurement
 *
 * The sensor starts measuring both N₂O (*HeOx for SMF3013-300-CLM*) flow and
 * temperature and provides a status word. All three measurement results can be
 * read out through one single I2C read when the continuous measurement is
 * running. The specific command code used for the start continuous measurement
 * command selects the calibrated gas or binary gas mixture (lookup table) for
 * the flow signal.
 *
 * Supported by products:
 *   * SFM4300-20
 *   * SFM3013-300-CLM (HeOx)
 *
 * @note The first measurement result will be available after 12ms. Small
 * accuracy deviations (few % of reading) can occur during the first 30ms
 * (including the 12ms)
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t ll_sfm_sf06_start_n2o_continuous_measurement();

/**
 * @brief Start continuous CO₂ measurement
 *
 * The sensor starts measuring both CO₂ flow and temperature and provides a
 * status word. All three measurement results can be read out through one single
 * I2C read when the continuous measurement is running. The specific command
 * code used for the start continuous measurement command selects the calibrated
 * gas or binary gas mixture (lookup table) for the flow signal.
 *
 * Supported by products:
 *   * SFM4300-20
 *
 * @note The first measurement result will be available after 12ms. Small
 * accuracy deviations (few % of reading) can occur during the first 30ms
 * (including the 12ms)
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t ll_sfm_sf06_start_co2_continuous_measurement();

/**
 * @brief Start continuous measurement of Air / O₂ mixture.
 *
 * The sensor starts measuring the Air/O₂ flow and temperature and provides a
 * status word. All three measurement results can be read out through one single
 * I2C read when the continuous measurement is running. The specific command
 * code used for the start continuous measurement command selects the calibrated
 * gas or binary gas mixture (lookup table) for the flow signal.
 *
 * Supported by products:
 *   * SFM3003
 *   * SFM4300-20
 *   * SFM4300-50
 *   * SFM3119
 *   * SFM3013-300-CL
 *   * SFM3013-300-CLM
 *   * SFM3019
 *
 * @param[in] volume_fraction Volume fraction of dioxigen in ‰.
 *
 * @return error_code 0 on success, an error code otherwise.
 *
 * Example:
 * --------
 *
 * @code{.c}
 *
 *     int16_t local_error = 0;
 *     local_error = sfm_sf06_start_air_o2_continuous_measurement(50);
 *     if (local_error != NO_ERROR) {
 *         return local_error;
 *     }
 *
 * @endcode
 *
 */
int16_t
ll_sfm_sf06_start_air_o2_continuous_measurement(uint16_t volume_fraction);

/**
 * @brief Start continuous measurement of N₂O / O₂ mixture.
 *
 * The sensor starts measuring the  N₂O / O₂ (*HeOx for SMF3013-300-CLM*) flow
 * and temperature and provides a status word. All three measurement results can
 * be read out through one single I2C read when the continuous measurement is
 * running. The specific command code used for the start continuous measurement
 * command selects the calibrated gas or binary gas mixture (lookup table) for
 * the flow signal.
 *
 * Supported by products:
 *   * SFM4300-20
 *   * SFM3013-300-CLM (HeOx)
 *
 * @param[in] volume_fraction Volume fraction of O₂ in ‰.
 *
 * @return error_code 0 on success, an error code otherwise.
 *
 * Example:
 * --------
 *
 * @code{.c}
 *
 *     int16_t local_error = 0;
 *     local_error = sfm_sf06_start_n2o_o2_continuous_measurement(50);
 *     if (local_error != NO_ERROR) {
 *         return local_error;
 *     }
 *
 * @endcode
 *
 */
int16_t
ll_sfm_sf06_start_n2o_o2_continuous_measurement(uint16_t volume_fraction);

/**
 * @brief Start continuous measurement of CO₂ / O₂ mixture.
 *
 * The sensor starts measuring the  CO₂ / O₂ flow and temperature and provides a
 * status word. All three measurement results can be read out through one single
 * I2C read when the continuous measurement is running. The specific command
 * code used for the start continuous measurement command selects the calibrated
 * gas or binary gas mixture (lookup table) for the flow signal.
 *
 * Supported by products:
 *   * SFM4300-20
 *
 * @param[in] volume_fraction Volume fraction of O₂ in ‰.
 *
 * @return error_code 0 on success, an error code otherwise.
 *
 * Example:
 * --------
 *
 * @code{.c}
 *
 *     int16_t local_error = 0;
 *     local_error = sfm_sf06_start_co2_o2_continuous_measurement(50);
 *     if (local_error != NO_ERROR) {
 *         return local_error;
 *     }
 *
 * @endcode
 *
 */
int16_t
ll_sfm_sf06_start_co2_o2_continuous_measurement(uint16_t volume_fraction);

/**
 * @brief Read out the data from the sensor.
 *
 * After the command *start_xx_continuous_measurement* has been sent, the chip
 * continuously measures and updates the measurement results. New results (flow,
 * temperature, and status word) can be read continuously with this command.
 *
 * @param[out] flow Calibrated flow signal.
 * @param[out] temperature Calibrated temperature.
 * @param[out] status_word Gives information about the measurement command that
 * is currently running, information on the currently selected averaging mode,
 * and the defined gas concentration of the current measurement command. A
 * detailed description of the *status_word* can be found in the data sheet.
 *
 * @note The first measurement result will be available after 12ms. Small
 * accuracy deviations (few % of reading) can occur during the first 30ms
 * (including the 12ms)
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_read_measurement_data(int16_t* flow, int16_t* temperature,
                                       uint16_t* status_word);

/**
 * @brief Activate a previously set concentration value.
 *
 * Together with the instruction *update_concentration_activate* this
 * instruction allows to update the concentration of a binary gas mixture
 * dynamically, i.e. without exiting the running measurement mode. This first
 * instruction transmits the new concentration value to the flow sensor. This
 * instruction refers to *Transmit concentration*. For more details see
 * data-sheet section *Update Concentration*
 *
 * @param[in] volume_fraction Fraction value
 *
 * @note
 * * The concentration value must not be updated more than once per millisecond
 * * If a concentration value greater than 1000 is passed to the sensor, the
 *   measurement mode will stop.
 *
 * @return error_code 0 on success, an error code otherwise.
 *
 * Example:
 * --------
 *
 * @code{.c}
 *
 *     int16_t local_error = 0;
 *     local_error = sfm_sf06_update_concentration_set(50);
 *     if (local_error != NO_ERROR) {
 *         return local_error;
 *     }
 *
 * @endcode
 *
 */
int16_t sfm_sf06_update_concentration_set(uint16_t volume_fraction);

/**
 * @brief Aktivate the new concentration setting
 *
 * By executing this instruction the previously with *update_concentration_set*
 * set value becomes active. The instruction resets the I2C address pointer to
 * the regular result output buffer such that the measurement data as described
 * by the transfer read_measurement_data are optained upon a subsequent read.
 * This instruction refers to *Reset-i2c address pointer*. For more details see
 * data-sheet section *Update Concentration*
 *
 * @note
 * * The concentration value must not be updated more than once per millisecond
 * * If a concentration value greater than 1000 is passed to the sensor, the
 *   measurement mode will stop.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_update_concentration_activate();

/**
 * @brief This transfer stops the continuous measurement and puts the sensor in
 * idle mode.
 *
 * This command stops the continuous measurement and puts the sensor in idle
 * mode. After it receives the stop command, the sensor needs up to 0.5ms to
 * power down the heater, enter idle mode and be receptive for a new command.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_stop_continuous_measurement();

/**
 * @brief Configures the sensor's averaging mode.
 *
 * This command configures the sensor’s averaging mode:
 *   * N=0 (default): average-until-read mode (c.f. Sec. 3)
 *   * 1≤N≤128: fixed-N averaging mode. N is the number of internal measurements
 *     that are averaged for one returned measurement value (i.e. the average
 *     over N flow samples, where N = CmdArgument, c.f. Sec. 3).
 * The configured averaging mode will be used for flow measurements until a
 * reset or re-execution of this command is performed. After a reset, averaging
 * is set to average-until-read mode (i.e. N is set to 0). The highest averaging
 * number allowed is 128. If a higher number is used in the command argument, it
 * will be overruled by the maximal value of 128 samples to average. If no
 * averaging is desired, set N to 1.
 *
 * @param[in] average_window Average window configuration value.
 *
 * @return error_code 0 on success, an error code otherwise.
 *
 * Example:
 * --------
 *
 * @code{.c}
 *
 *     int16_t local_error = 0;
 *     local_error = sfm_sf06_configure_averaging(50);
 *     if (local_error != NO_ERROR) {
 *         return local_error;
 *     }
 *
 * @endcode
 *
 */
int16_t sfm_sf06_configure_averaging(uint16_t average_window);

/**
 * @brief This command provides the actually used scale factor and offset of the
 * sensor.
 *
 * This command provides the scale factor and offset to convert flow readings
 * into physical units. The scale factor and offset are specific to the
 * calibrated gas / gas mixture and its corresponding lookup table used for the
 * flow measurement. Therefore, the gas / gas mixture needs to be specified in
 * the command argument by the command code of the corresponding start
 * continuous measurement. For detailed information see data-sheet.
 *
 * @param[in] command_code Code of measurement from which we want to have that
 * information.
 * @param[out] flow_scale_factor Scale factor used by the sensor.
 * @param[out] flow_offset Offset used by the sensor.
 * @param[out] flow_unit Applicable flow unit.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_read_scale_offset_unit(uint16_t command_code,
                                        int16_t* flow_scale_factor,
                                        int16_t* flow_offset,
                                        uint16_t* flow_unit);

/**
 * @brief Enters sleep mode
 *
 * In sleep mode the sensor uses a minimum amount of power. The mode can only be
 * entered from idle mode, i.e. when the sensor is not performing measurements.
 * This mode is particularly useful for battery operated devices. To minimize
 * the current in this mode, the complexity of the sleep mode circuit has been
 * reduced as much as possible, which is mainly reflected by the way the sensor
 * exits the sleep mode. In sleep mode the sensor cannot be soft reset.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_enter_sleep();

/**
 * @brief Exits from sleep mode
 *
 * The sensor exits the sleep mode and enters the idle mode when it receives the
 * valid I2C address and a write bit (‘0’). Note that the I2C address is not
 * acknowledged. It is necessary to poll the sensor to see whether the sensor
 * has received the address and has woken up. This should take typically 16ms.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_exit_sleep();

/**
 * @brief This command reads product identifier and the serial number.
 *
 * This command allows to read product identifier and the serial number. The
 * command can only be executed from the idle mode, i.e. when the sensor is not
 * performing measurements
 *
 * @param[out] product_identifier 32-bit unique product and revision number
 * @param[out] serial_number 64 bit unique serial number of the device
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfm_sf06_read_product_identifier(uint32_t* product_identifier,
                                         uint8_t* serial_number,
                                         uint16_t serial_number_size);

#ifdef __cplusplus
}
#endif
#endif  // SFM_SF06_I2C_H
