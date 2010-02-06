/*
 * Copyright (C) 2003-2010 FreeIPMI Core Team
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef _IPMI_SDR_RECORD_FORMAT_TEMPLATES_H
#define _IPMI_SDR_RECORD_FORMAT_TEMPLATES_H

#ifdef __cplusplus
extern "C" {
#endif

/* This header file is for documentation only */

#if 0

Format = { bits, "field name", field flags }

FIID_FIELD_REQUIRED - field is required for the payload
FIID_FIELD_OPTIONAL - field is optional for the payload

FIID_FIELD_LENGTH_FIXED - field length is fixed at the number of bits listed
FIID_FIELD_LENGTH_VARIABLE - field length is variable for the number of bits listed

SDR Record Header
-----------------

fiid_template_t tmpl_sdr_record_header =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 0, "", 0}
  };

SDR Full Sensor Record
----------------------

fiid_template_t tmpl_sdr_full_sensor_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Sensor owner ID */
    { 1, "sensor_owner_id.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "sensor_owner_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor owner LUN */
    { 2, "sensor_owner_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_owner_lun.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Number */
    { 8, "sensor_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /*********************
     * Record Body Bytes *
     *********************/
    /* Entity ID */
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Entity Instance */
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Initialization */
    { 1, "sensor_initialization.sensor_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.event_generation", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_thresholds", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_events", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.settable_sensor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Capabilities */
    { 2, "sensor_capabilities.event_message_control_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.threshold_access_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.hysteresis_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.auto_re_arm_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.entity_ignore_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "event_reading_type_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 16, "assertion_event_lower_threshold_reading_mask", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 16, "deassertion_event_upper_threshold_reading_mask", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 16, "discrete_reading_settable_threshold_readable_threshold_mask", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Unit 1 */
    { 1, "sensor_unit1.percentage", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "sensor_unit1.rate_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.analog_data_format", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_unit2.base_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_unit3.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Linearization */
    { 7, "linearization", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "linearization.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* M (2s complement, signed) */
    { 8, "m_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* M, tolerance */
    { 6, "tolerance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "m_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* B (2s complement, signed) */
    { 8, "b_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* B, Accuracy */
    { 6, "accuracy_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "b_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Accuracy, Accuracy exp */
    { 2, "sensor_direction", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "accuracy_exp", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "accuracy_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* R exp, B exp (2s complement, signed) */
    { 4, "b_exponent", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "r_exponent", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Analog characteristic flags */
    { 1, "analog_characteristics_flag.nominal_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "analog_characteristics_flag.normal_max", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "analog_characteristics_flag.normal_min", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 5, "analog_characteristics_flag.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "nominal_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "normal_maximum", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "normal_minimum", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_maximum_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_minimum_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_non_recoverable_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_non_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_non_recoverable_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_non_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "positive_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "negative_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 16, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "id_string_type_length_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Full Sensor Record (Non-Threshold Base Sensors)
---------------------------------------------------

fiid_template_t tmpl_sdr_full_sensor_record_non_threshold_based_sensors =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Sensor owner ID */
    { 1, "sensor_owner_id.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "sensor_owner_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor owner LUN */
    { 2, "sensor_owner_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_owner_lun.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /*********************
     * Record Body Bytes *
     *********************/
    /* Entity ID */
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Entity Instance */
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Initialization */
    { 1, "sensor_initialization.sensor_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.event_generation", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_thresholds", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_events", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Capabilities */
    { 2, "sensor_capabilities.event_message_control_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.threshold_access_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.hysteresis_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.auto_re_arm_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.entity_ignore_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "event_reading_type_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "assertion_event_mask.event_offset_0", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_5", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_6", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_7", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_8", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_9", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_10", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_11", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_12", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_13", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_14", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "deassertion_event_mask.event_offset_0", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_5", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_6", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_7", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_8", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_9", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_10", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_11", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_12", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_13", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_14", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "discrete_reading_mask.state_bit_0", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_5", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_6", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_7", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_8", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_9", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_10", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_11", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_12", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_13", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_14", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Unit 1 */
    { 1, "sensor_unit1.percentage", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "sensor_unit1.rate_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.analog_data_format", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_unit2.base_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_unit3.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Linearization */
    { 7, "linearization", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "linearization.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* M (2s complement, signed) */
    { 8, "m_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* M, tolerance */
    { 6, "tolerance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "m_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* B (2s complement, signed) */
    { 8, "b_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* B, Accuracy */
    { 6, "accuracy_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "b_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Accuracy, Accuracy exp */
    { 2, "sensor_direction", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "accuracy_exp", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "accuracy_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* R exp, B exp (2s complement, signed) */
    { 4, "b_exponent", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "r_exponent", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Analog characteristic flags */
    { 1, "analog_characteristics_flag.nominal_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "analog_characteristics_flag.normal_max", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "analog_characteristics_flag.normal_min", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 5, "analog_characteristics_flag.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "nominal_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "normal_maximum", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "normal_minimum", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_maximum_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_minimum_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_non_recoverable_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_non_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_non_recoverable_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_non_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "positive_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "negative_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 16, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "id_string_type_length_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Full Sensor Record (Threshold Base Sensors)
-----------------------------------------------

fiid_template_t tmpl_sdr_full_sensor_record_threshold_based_sensors =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Sensor owner ID */
    { 1, "sensor_owner_id.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "sensor_owner_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor owner LUN */
    { 2, "sensor_owner_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_owner_lun.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Number */
    { 8, "sensor_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /*********************
     * Record Body Bytes *
     *********************/
    /* Entity ID */
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Entity Instance */
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Initialization */
    { 1, "sensor_initialization.sensor_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.event_generation", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_thresholds", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_events", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Capabilities */
    { 2, "sensor_capabilities.event_message_control_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.threshold_access_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.hysteresis_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.auto_re_arm_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.entity_ignore_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "event_reading_type_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "threshold_assertion_event_mask.lower_non_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_non_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_non_recoverable_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_non_recoverable_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_non_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_non_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_non_recoverable_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_non_recoverable_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "lower_threshold_reading_mask.lower_non_critical_threshold_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "lower_threshold_reading_mask.lower_critical_threshold_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "lower_threshold_reading_mask.lower_non_recoverable_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "lower_threshold_reading_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "threshold_deassertion_event_mask.lower_non_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_non_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_non_recoverable_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_non_recoverable_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_non_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_non_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_non_recoverable_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_non_recoverable_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "upper_threshold_reading_mask.upper_non_critical_threshold_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "upper_threshold_reading_mask.upper_critical_threshold_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "upper_threshold_reading_mask.upper_non_recoverable_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "upper_threshold_reading_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "readable_threshold_mask.lower_non_critical_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.lower_critical_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.lower_non_recoverable_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.upper_non_critical_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.upper_critical_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.upper_non_recoverable_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.reserved1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.reserved2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.lower_non_critical_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.lower_critical_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.lower_non_recoverable_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.upper_non_critical_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.upper_critical_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.upper_non_recoverable_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.reserved1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.reserved2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Unit 1 */
    { 1, "sensor_unit1.percentage", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "sensor_unit1.rate_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.analog_data_format", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_unit2.base_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_unit3.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Linearization */
    { 7, "linearization", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "linearization.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* M (2s complement, signed) */
    { 8, "m_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* M, tolerance */
    { 6, "tolerance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "m_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* B (2s complement, signed) */
    { 8, "b_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* B, Accuracy */
    { 6, "accuracy_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "b_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Accuracy, Accuracy exp */
    { 2, "sensor_direction", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "accuracy_exp", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "accuracy_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* R exp, B exp (2s complement, signed) */
    { 4, "b_exponent", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "r_exponent", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Analog characteristic flags */
    { 1, "analog_characteristics_flag.nominal_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "analog_characteristics_flag.normal_max", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "analog_characteristics_flag.normal_min", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 5, "analog_characteristics_flag.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "nominal_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "normal_maximum", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "normal_minimum", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_maximum_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_minimum_reading", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_non_recoverable_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "upper_non_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_non_recoverable_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "lower_non_critical_threshold", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "positive_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "negative_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 16, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "id_string_type_length_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Compact Sensor Record
-------------------------

fiid_template_t tmpl_sdr_compact_sensor_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Sensor owner ID */
    { 1, "sensor_owner_id.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "sensor_owner_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor owner LUN */
    { 2, "sensor_owner_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_owner_lun.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Number */
    { 8, "sensor_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /*********************
     * Record Body Bytes *
     *********************/
    /* Entity ID */
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Entity Instance */
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Initialization */
    { 1, "sensor_initialization.sensor_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.event_generation", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_thresholds", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_events", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Capabilities */
    { 2, "sensor_capabilities.event_message_control_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.threshold_access_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.hysteresis_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.auto_re_arm_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.entity_ignore_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "event_reading_type_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 16, "assertion_event_lower_threshold_reading_mask", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 16, "deassertion_event_upper_threshold_reading_mask", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 16, "discrete_reading_settable_threshold_readable_threshold_mask", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Unit 1 */
    { 1, "sensor_unit1.percentage", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "sensor_unit1.rate_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.analog_data_format", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_unit2.base_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_unit3.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Record Sharing */
    { 4, "share_count", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "id_string_instance_modifier_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_direction", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "id_string_instance_modifier_offset", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance_sharing", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "positive_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "negative_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 24, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "id_string_type_length_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Compact Sensor Record (Non-Threshold Based Sensors)
-------------------------------------------------------

fiid_template_t tmpl_sdr_compact_sensor_record_non_threshold_based_sensors =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Sensor owner ID */
    { 1, "sensor_owner_id.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "sensor_owner_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor owner LUN */
    { 2, "sensor_owner_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_owner_lun.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Number */
    { 8, "sensor_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /*********************
     * Record Body Bytes *
     *********************/
    /* Entity ID */
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Entity Instance */
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Initialization */
    { 1, "sensor_initialization.sensor_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.event_generation", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_thresholds", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_events", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Capabilities */
    { 2, "sensor_capabilities.event_message_control_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.threshold_access_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.hysteresis_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.auto_re_arm_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.entity_ignore_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "event_reading_type_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "assertion_event_mask.event_offset_0", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_5", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_6", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_7", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_8", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_9", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_10", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_11", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_12", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_13", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.event_offset_14", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "assertion_event_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "deassertion_event_mask.event_offset_0", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_5", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_6", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_7", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_8", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_9", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_10", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_11", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_12", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_13", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.event_offset_14", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "deassertion_event_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "discrete_reading_mask.state_bit_0", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_5", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_6", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_7", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_8", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_9", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_10", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_11", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_12", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_13", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.state_bit_14", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "discrete_reading_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Unit 1 */
    { 1, "sensor_unit1.percentage", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "sensor_unit1.rate_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.analog_data_format", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_unit2.base_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_unit3.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Record Sharing */
    { 4, "share_count", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "id_string_instance_modifier_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_direction", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "id_string_instance_modifier_offset", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance_sharing", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "positive_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "negative_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 24, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "id_string_type_length_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Compact Sensor Record (Threshold Based Sensors)
---------------------------------------------------

fiid_template_t tmpl_sdr_compact_sensor_record_threshold_based_sensors =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Sensor owner ID */
    { 1, "sensor_owner_id.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "sensor_owner_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor owner LUN */
    { 2, "sensor_owner_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_owner_lun.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Number */
    { 8, "sensor_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /*********************
     * Record Body Bytes *
     *********************/
    /* Entity ID */
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Entity Instance */
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Initialization */
    { 1, "sensor_initialization.sensor_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.event_generation", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_thresholds", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_events", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.init_scanning", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_initialization.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Capabilities */
    { 2, "sensor_capabilities.event_message_control_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.threshold_access_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_capabilities.hysteresis_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.auto_re_arm_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "sensor_capabilities.entity_ignore_support", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "event_reading_type_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "threshold_assertion_event_mask.lower_non_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_non_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_non_recoverable_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.lower_non_recoverable_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_non_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_non_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_non_recoverable_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_assertion_event_mask.upper_non_recoverable_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "lower_threshold_reading_mask.lower_non_critical_threshold_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "lower_threshold_reading_mask.lower_critical_threshold_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "lower_threshold_reading_mask.lower_non_recoverable_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "lower_threshold_reading_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "threshold_deassertion_event_mask.lower_non_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_non_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_non_recoverable_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.lower_non_recoverable_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_non_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_non_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_critical_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_critical_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_non_recoverable_going_low_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "threshold_deassertion_event_mask.upper_non_recoverable_going_high_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "upper_threshold_reading_mask.upper_non_critical_threshold_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "upper_threshold_reading_mask.upper_critical_threshold_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "upper_threshold_reading_mask.upper_non_recoverable_is_comparison", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "upper_threshold_reading_mask.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 1, "readable_threshold_mask.lower_non_critical_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.lower_critical_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.lower_non_recoverable_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.upper_non_critical_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.upper_critical_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.upper_non_recoverable_threshold_is_readable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.reserved1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "readable_threshold_mask.reserved2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.lower_non_critical_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.lower_critical_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.lower_non_recoverable_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.upper_non_critical_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.upper_critical_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.upper_non_recoverable_threshold_is_settable", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.reserved1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "settable_threshold_mask.reserved2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Unit 1 */
    { 1, "sensor_unit1.percentage", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "sensor_unit1.rate_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_unit1.analog_data_format", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_unit2.base_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "sensor_unit3.modifier_unit", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /* Sensor Record Sharing */
    { 4, "share_count", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "id_string_instance_modifier_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_direction", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "id_string_instance_modifier_offset", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance_sharing", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "positive_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "negative_going_threshold_hysteresis", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 24, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "id_string_type_length_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Event Only Record
---------------------

fiid_template_t tmpl_sdr_event_only_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Sensor owner ID */
    { 1, "sensor_owner_id.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "sensor_owner_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor owner LUN */
    { 2, "sensor_owner_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "fru_inventory_device_owner_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Sensor Number */
    { 8, "sensor_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /*********************
     * Record Body Bytes *
     *********************/
    /* Entity ID */
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Entity Instance */
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "sensor_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "event_reading_type_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    /*******************************************
     * Sensor Record Sharing, Sensor Direction *
     *******************************************/
    { 4, "share_count", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "id_string_instance_modifier_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "sensor_direction", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "id_string_instance_modifier_offset", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance_sharing", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},

    { 8, "id_string_type_length_code", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Entity Association Record
-----------------------------

fiid_template_t tmpl_sdr_entity_association_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    { 8, "container_entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "container_entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Flags */
    { 5, "flags.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "flags.sensor_presence", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "flags.record_link", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "flags.contained_entities", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained Entity 1/Range 1 */
    { 8, "entity_id_contained_entity_range_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained instance entity 1/range 1 */
    { 8, "instance_id_contained_entity_range_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /*********************
     * Record Body Bytes *
     *********************/
    /* Contained Entity 2/Range 2 */
    { 8, "entity_id_contained_entity_range_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained instance entity 2/range 2 */
    { 8, "instance_id_contained_entity_range_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained Entity 3/Range 3 */
    { 8, "entity_id_contained_entity_range_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained instance entity 3/range 3 */
    { 8, "instance_id_contained_entity_range_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained Entity 4/Range 4 */
    { 8, "entity_id_contained_entity_range_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained instance entity 4/range 4 */
    { 8, "instance_id_contained_entity_range_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 0, "", 0}
  };

SDR Device Relative Entity Association Record
---------------------------------------------

fiid_template_t tmpl_sdr_device_relative_entity_association_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    { 8, "container_entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "container_entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "container_entity_device_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "container_entity_device_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "container_entity_device_channel.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "container_entity_device_channel", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Flags */
    { 5, "flags.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "flags.sensor_presence", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "flags.record_link", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "flags.contained_entities", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained Entity 1/Range 1 */
    { 1, "contained_entity_1_device_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "contained_entity_1_device_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "contained_entity_1_device_channel.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "contained_entity_1_device_channel", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_id_contained_entity_range_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_instance_contained_entity_range_1", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained Entity 2/Range 2 */
    { 1, "contained_entity_2_device_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "contained_entity_2_device_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "contained_entity_2_device_channel.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "contained_entity_2_device_channel", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_id_contained_entity_range_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_instance_contained_entity_range_2", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained Entity 3/Range 3 */
    { 1, "contained_entity_3_device_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "contained_entity_3_device_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "contained_entity_3_device_channel.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "contained_entity_3_device_channel", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_id_contained_entity_range_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_instance_contained_entity_range_3", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Contained Entity 4/Range 4 */
    { 1, "contained_entity_4_device_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "contained_entity_4_device_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "contained_entity_4_device_channel.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "contained_entity_4_device_channel", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_id_contained_entity_range_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_instance_contained_entity_range_4", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 48, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 0, "", 0}
  };

SDR Generic Device Locator Record
---------------------------------

fiid_template_t tmpl_sdr_generic_device_locator_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Direct Access Address */
    { 1, "direct_access_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "direct_access_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Device Slave Address */
    { 1, "channel_number_ms", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "device_slave_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Access LUN / Bus ID */
    { 3, "private_bus_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "lun_for_master_write_read_command", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_number_ls", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Address Span */
    { 3, "address_span", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 5, "address_span.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_type_modifier", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_id_string_type_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "device_id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR FRU Device Locator Record
-----------------------------

fiid_template_t tmpl_sdr_fru_device_locator_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Direct Access Address */
    { 1, "direct_access_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "direct_access_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* FRU Device ID/Device Slave Address */
    { 8, "logical_fru_device_device_slave_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Logical-Physical / Access LUN / Bus ID */
    { 3, "private_bus_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "lun_for_master_write_read_fru_command", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "logical_physical_access_lun_bus_id.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "logical_physical_fru_device", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Channel Number */
    { 4, "channel_number.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /*********************
     * Record Body Bytes *
     *********************/
    { 8, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_type_modifier", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "fru_entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "fru_entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* OEM */
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* ID String type/Length code */
    { 8, "device_id_string_type_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* ID String bytes */
    /* achu: spec says "device_string", but I rename for consistency to other
     * records.  I assume it's a typo in the spec.
     */
    { 128, "device_id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR FRU Device Locator Record (Non-Intelligent)
-----------------------------------------------

fiid_template_t tmpl_sdr_fru_device_locator_record_non_intelligent =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Direct Access Address */
    { 1, "direct_access_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "direct_access_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* FRU Device ID/Device Slave Address */
    { 1, "non_intelligent_fru_device.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "non_intelligent_fru_device.slave_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Logical-Physical / Access LUN / Bus ID */
    { 3, "private_bus_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "lun_for_master_write_read_fru_command", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 2, "logical_physical_access_lun_bus_id.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "logical_physical_fru_device", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Channel Number */
    { 4, "channel_number.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /*********************
     * Record Body Bytes *
     *********************/
    { 8, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_type_modifier", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "fru_entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "fru_entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_id_string_type_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* achu: spec says "device_string", but I rename for consistency to other
     * records.  I assume it's a typo in the spec.
     */
    { 128, "device_id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Management Controller Device Locator Record
-----------------------------------------------

fiid_template_t tmpl_sdr_management_controller_device_locator_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Device Slave Address */
    { 1, "device_slave_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "device_slave_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Channel number */
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /*********************
     * Record Body Bytes *
     *********************/
    /* Power State Notification/Global Initialization */
    { 2, "global_initialization.event_message_generation", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "global_initialization.log_initialization_agent_errors", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "global_initialization.controller_logs_initialization_agent_errors", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "power_state_notification.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "power_state_notification.controller", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "power_state_notification.acpi_device_power_state_notification", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "power_state_notification.acpi_system_power_state_notification", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /* Device capabilities */
    { 1, "device_capabilities.sensor_device", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "device_capabilities.sdr_repository_device", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "device_capabilities.sel_device", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "device_capabilities.fru_inventory_device", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "device_capabilities.ipmb_event_receiver", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "device_capabilities.ipmb_event_generator", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "device_capabilities.bridge", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "device_capabilities.chassis_device", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 24, "reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "entity_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "entity_instance", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "entity_instance.type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "oem", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_id_string_type_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "device_id_string", FIID_FIELD_OPTIONAL | FIID_FIELD_LENGTH_VARIABLE},
    { 0, "", 0}
  };

SDR Management Controller Confirmation Record
---------------------------------------------

fiid_template_t tmpl_sdr_management_controller_confirmation_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    /* Device Slave Address */
    { 1, "device_slave_address.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 7, "device_slave_address", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "device_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "device_revision", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_number", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /*********************
     * Record Body Bytes *
     *********************/
    { 7, "major_firmware_revision", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "major_firmware_revision.reserved", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "minor_firmware_revision", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8, "ipmi_version", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 24, "manufacturer_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 16, "product_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 128, "device_guid", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 0, "", 0}
  };

SDR BMC Message Channel Info
----------------------------

fiid_template_t tmpl_sdr_bmc_message_channel_info_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    { 4, "channel_0_protocol", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_0_message_receive_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "channel_0_transmit_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_1_protocol", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_1_message_receive_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "channel_1_transmit_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_2_protocol", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_2_message_receive_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "channel_2_transmit_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_3_protocol", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_3_message_receive_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "channel_3_transmit_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_4_protocol", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_4_message_receive_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "channel_4_transmit_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_5_protocol", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_5_message_receive_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "channel_5_transmit_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_6_protocol", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_6_message_receive_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "channel_6_transmit_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4, "channel_7_protocol", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 3, "channel_7_message_receive_lun", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 1, "channel_7_transmit_supported", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 0, "", 0}
  };

SDR OEM Record
--------------

fiid_template_t tmpl_sdr_oem_record =
  {
    /*********************
     * SDR Record Header *
     *********************/
    { 16, "record_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_major", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 4,  "sdr_version_minor", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_type", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 8,  "record_length", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    /********************
     * Record Key Bytes *
     ********************/
    { 24, "manufacturer_id", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 448, "oem_data", FIID_FIELD_REQUIRED | FIID_FIELD_LENGTH_FIXED},
    { 0, "", 0}
  };

#endif  /* 0 */

#ifdef __cplusplus
}
#endif

#endif  /* _IPMI_SDR_RECORD_FORMAT_TEMPLATES_H */
